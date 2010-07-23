code
#include <stdio.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include <openssl/rsa.h>
#include <openssl/evp.h>
#include <openssl/objects.h>
#include <openssl/x509.h>
#include <openssl/err.h>
#include <openssl/pem.h>
#include <openssl/ssl.h>
endcode

WHENEVER ERROR CONTINUE
WHENEVER ANY ERROR CONTINUE
WHENEVER SQLERROR CONTINUE

DEFINE mv_initialized integer

code
EVP_PKEY *     pkey;
endcode

####################################
FUNCTION get_privatekey(p_filename)
####################################
DEFINE p_filename char(256)
call initialize()
return get_privatekey_with_passphrase(p_filename,NULL)
END FUNCTION

####################################
FUNCTION get_privatekey_with_passphrase(p_filename,p_passphrase)
####################################
DEFINE  p_filename char(256),
	p_passphrase char(255)
DEFINE lv_use_passphrase INTEGER
DEFINE lv_ret INT
code
FILE *          fp;
endcode

call initialize()
LET lv_ret = 1
if p_passphrase is null then
	let lv_use_passphrase=false
else 
	let lv_use_passphrase=true
end if

code
	A4GL_trim(p_filename);
	A4GL_trim(p_passphrase);
    fp = fopen (p_filename, "r");
    if (fp == NULL) {
        lv_ret=0;
    } else {
        pkey = PEM_read_PrivateKey(fp, NULL, NULL, NULL);
        fclose (fp);
        if (pkey == NULL) {
            lv_ret=0;
        }
	}
endcode
RETURN lv_ret
END FUNCTION

####################################
FUNCTION sign(p_string, p_size, p_algo)
####################################
DEFINE p_string char(30000)
DEFINE p_size int
DEFINE p_algo char(10)

DEFINE sig_buf char(4096)
DEFINE sig_len int
DEFINE lv_err int;

LET lv_err = 1;
CALL initialize()
code
{
EVP_MD_CTX     md_ctx;
const EVP_MD *md;
	A4GL_trim(p_algo);
    md = EVP_get_digestbyname(p_algo);
    if (!md) {
        lv_err = 0;
    } else {
        EVP_SignInit   (&md_ctx, md);
        lv_err = EVP_SignUpdate (&md_ctx, p_string, p_size);
        if (lv_err == 1) {
           sig_len = sizeof(sig_buf);
           lv_err = EVP_SignFinal (&md_ctx, sig_buf, &sig_len, pkey);
        }
    }
}
endcode
RETURN lv_err, sig_buf, sig_len
END FUNCTION

####################################
FUNCTION sign64(p_string, p_size, p_algo)
####################################
DEFINE p_string char(30000)
DEFINE p_size int
DEFINE p_algo char(10)

DEFINE lv_err int;
DEFINE lv_base char(2048);

LET lv_err = 1;
CALL initialize()
code
{
EVP_MD_CTX     md_ctx;
const EVP_MD *md;
unsigned char sig_buf[4096];
unsigned int sig_len;

BIO *bmem, *b64;
BUF_MEM *bptr;

	A4GL_trim(p_algo);
    md = EVP_get_digestbyname(p_algo);
    if (!md) {
        lv_err = 0;
    } else {
        EVP_SignInit   (&md_ctx, md);
        lv_err = EVP_SignUpdate (&md_ctx, p_string, p_size);
        if (lv_err == 1) {
           sig_len = sizeof(sig_buf);
           lv_err = EVP_SignFinal (&md_ctx, sig_buf, &sig_len, pkey);
           if (lv_err == 1) {
               b64 = BIO_new(BIO_f_base64());
               BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
               bmem = BIO_new(BIO_s_mem());
               b64 = BIO_push(b64, bmem);
             
               BIO_write(b64, sig_buf, sig_len);
               BIO_flush(b64);
               BIO_get_mem_ptr(b64, &bptr);
             
               char *buff = (char *)malloc(bptr->length);
               memcpy(buff, bptr->data, bptr->length-1);
               buff[bptr->length-1] = 0;
           
               BIO_free_all(b64);
           
               strncpy(lv_base, buff, 2047);
            }
        }
    }
}
endcode
RETURN lv_err, lv_base
END FUNCTION

####################################
FUNCTION get_publickey(p_filename)
####################################
define p_filename char(256)
define lv_ret INT
LET lv_ret = 1
call initialize()
code
    FILE *          fp;
    X509 *         x509;

	A4GL_trim(p_filename);
    fp = fopen (p_filename, "r");
    if (fp == NULL) {
        lv_ret=0;
    } else {
        x509 = PEM_read_X509(fp, NULL, NULL, NULL);
        fclose (fp);
        if (x509 == NULL) {
            lv_ret=0;
        } else {
            pkey=X509_get_pubkey(x509);
        }
    }
end code
RETURN lv_ret
END FUNCTION

####################################
FUNCTION verify(p_sig_data, p_sig_len, p_data, p_size, p_algo)
####################################
define p_sig_data char(4096)
define p_sig_len int
define p_data char(4096)
define p_size int
define p_algo char(10)
define lv_err int
code
EVP_MD_CTX     md_ctx;
const EVP_MD *md;
end code
CALL initialize()
code
	A4GL_trim(p_algo);
    md = EVP_get_digestbyname(p_algo);
    if (!md) {
        lv_err = 0;
    } else {
        EVP_VerifyInit   (&md_ctx, EVP_get_digestbyname(p_algo));
        lv_err = EVP_VerifyUpdate (&md_ctx, p_data, p_size);
        if (lv_err == 1) {
            lv_err = EVP_VerifyFinal (&md_ctx, p_sig_data, p_sig_len, pkey);
        }
    }
end code
return lv_err
end FUNCTION

####################################
FUNCTION print_errors()
####################################
CALL initialize()
code
  ERR_print_errors_fp(stderr);
  perror("libssl.4gl");
end code
end FUNCTION

####################################
FUNCTION free_key()
####################################
CALL initialize()
code
  EVP_PKEY_free (pkey);
end code
end FUNCTION

####################################
FUNCTION base64_encode(p_data, p_size)
####################################
DEFINE p_data char(4096)
DEFINE p_size int
DEFINE lv_buff char(4096)
DEFINE lv_size int
CALL initialize()
code
  BIO *bmem, *b64;
  BUF_MEM *bptr;

  b64 = BIO_new(BIO_f_base64());
  BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
  bmem = BIO_new(BIO_s_mem());
  b64 = BIO_push(b64, bmem);

  BIO_write(b64, p_data, p_size);
  BIO_flush(b64);
  BIO_get_mem_ptr(b64, &bptr);

  char *buff = (char *)malloc(bptr->length);
  memcpy(buff, bptr->data, bptr->length);
  buff[bptr->length] = 0;
  lv_size=bptr->length;

  BIO_free_all(b64);

  strncpy(lv_buff, buff, 4095);
end code
RETURN lv_buff, lv_size
end FUNCTION

####################################
FUNCTION base64_decode(p_data, p_data_size)
####################################
DEFINE p_data CHAR(4096)
DEFINE p_data_size INT
DEFINE lv_buff CHAR(4096)
DEFINE lv_size INT
CALL initialize()
LET lv_size = 4095;
code
  BIO *b64, *bmem;

  memset(lv_buff, 0, lv_size);

  b64 = BIO_new(BIO_f_base64());
  // BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
  bmem = BIO_new_mem_buf(p_data, p_data_size);
  b64 = BIO_push(b64, bmem);

  lv_size = BIO_read(bmem, lv_buff, lv_size);

  BIO_free_all(bmem);

end code
RETURN lv_buff, lv_size
end FUNCTION

####################################
FUNCTION initialize()
####################################
if not mv_initialized then
    let mv_initialized = true
code
    /* Just load the crypto library error strings,
     * SSL_load_error_strings() loads the crypto AND the SSL ones */
    /* SSL_load_error_strings();*/
    ERR_load_crypto_strings();
    /* Load the list o cyphers to enable load by name */
    OpenSSL_add_all_digests();
end code
end if
end FUNCTION
