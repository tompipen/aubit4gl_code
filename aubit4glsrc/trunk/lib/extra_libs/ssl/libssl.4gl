code
#include <stdio.h>
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
EVP_MD_CTX     md_ctx;
EVP_PKEY *      pkey;
X509 *    x509;

endcode
####################################
FUNCTION get_privatekey(p_filename)
####################################
DEFINE p_filename char(256)

call initialize()
call get_privatekey_with_passphrase(p_filename,NULL)

END FUNCTION



####################################
FUNCTION get_privatekey_with_passphrase(p_filename,p_passphrase)
####################################
DEFINE  p_filename char(256),
	p_passphrase char(255)
DEFINE lv_use_passphrase INTEGER
code
 FILE *          fp;
endcode

call initialize()
if p_passphrase is null then
	let lv_use_passphrase=false
else 
	let lv_use_passphrase=true
end if

code
	A4GL_trim(p_filename);
	A4GL_trim(p_passphrase);
    fp = fopen (p_filename, "r");
    if (fp == NULL) exit (1);
    pkey = PEM_read_PrivateKey(fp, NULL, NULL, NULL);
    fclose (fp);

    if (pkey == NULL) {
       ERR_print_errors_fp (stderr);
       exit (1);
     }

endcode
END FUNCTION

####################################
FUNCTION sign(p_string, p_size, p_algo)
####################################
DEFINE p_string char(30000)
define p_size int
define p_algo char(10)
define lv_algo int
define sig_buf char(4096)
define sig_len int
call initialize()
CASE p_algo
    WHEN "md"        LET lv_algo = 1
    WHEN "md2"       LET lv_algo = 2
    WHEN "md5"       LET lv_algo = 3
    WHEN "sha"       LET lv_algo = 4
    WHEN "sha1"      LET lv_algo = 5
    WHEN "dss"       LET lv_algo = 6
    WHEN "dss1"      LET lv_algo = 7
    WHEN "ripemd160" LET lv_algo = 9
    OTHERWISE        LET lv_algo = 5   # PHP default
END CASE
code
{
int err;
    switch (lv_algo) {
       case 1: EVP_SignInit   (&md_ctx, EVP_md_null()); break;
       case 2: EVP_SignInit   (&md_ctx, EVP_md2()); break;
       case 3: EVP_SignInit   (&md_ctx, EVP_md5()); break;
       case 4: EVP_SignInit   (&md_ctx, EVP_sha()); break;
       case 5: EVP_SignInit   (&md_ctx, EVP_sha1()); break;
       case 6: EVP_SignInit   (&md_ctx, EVP_dss()); break;
       case 7: EVP_SignInit   (&md_ctx, EVP_dss1()); break;
       case 9: EVP_SignInit   (&md_ctx, EVP_ripemd160()); break;
    }
    EVP_SignUpdate (&md_ctx, p_string, p_size);
    sig_len = sizeof(sig_buf);
    err = EVP_SignFinal (&md_ctx, sig_buf, &sig_len, pkey);

    if (err != 1) {
       ERR_print_errors_fp(stderr);
       exit (1);
    }

}
endcode

return sig_buf, sig_len

END FUNCTION

####################################
FUNCTION get_publickey(p_filename)
####################################
define p_filename char(256)
call initialize()
code
    FILE *          fp;
    /* Read public key */

	A4GL_trim(p_filename);
    fp = fopen (p_filename, "r");
    if (fp == NULL) exit (1);
    x509 = PEM_read_X509(fp, NULL, NULL, NULL);
    fclose (fp);

    if (x509 == NULL) {
        ERR_print_errors_fp (stderr);
        exit (1);
    }

    /* Get public key - eay */
    pkey=X509_get_pubkey(x509);
    if (pkey == NULL) {
      ERR_print_errors_fp (stderr);
      exit (1);
    }

end code
END FUNCTION

####################################
FUNCTION verify(p_sig_data, p_sig_len, p_data, p_size, p_algo)
####################################
define p_sig_data char(4096)
define p_sig_len int
define p_data char(4096)
define p_size int
define p_algo char(10)
define lv_algo int
define err int
CALL initialize()
CASE p_algo
    WHEN "md"        LET lv_algo = 1
    WHEN "md2"       LET lv_algo = 2
    WHEN "md5"       LET lv_algo = 3
    WHEN "sha"       LET lv_algo = 4
    WHEN "sha1"      LET lv_algo = 5
    WHEN "dss"       LET lv_algo = 6
    WHEN "dss1"      LET lv_algo = 7
    WHEN "ripemd160" LET lv_algo = 9
    OTHERWISE        LET lv_algo = 5   # PHP default
END CASE
code
    switch (lv_algo) {
       case 1: EVP_VerifyInit   (&md_ctx, EVP_md_null()); break;
       case 2: EVP_VerifyInit   (&md_ctx, EVP_md2()); break;
       case 3: EVP_VerifyInit   (&md_ctx, EVP_md5()); break;
       case 4: EVP_VerifyInit   (&md_ctx, EVP_sha()); break;
       case 5: EVP_VerifyInit   (&md_ctx, EVP_sha1()); break;
       case 6: EVP_VerifyInit   (&md_ctx, EVP_dss()); break;
       case 7: EVP_VerifyInit   (&md_ctx, EVP_dss1()); break;
       case 9: EVP_VerifyInit   (&md_ctx, EVP_ripemd160()); break;
    }
  EVP_VerifyUpdate (&md_ctx, p_data, p_size);
  err = EVP_VerifyFinal (&md_ctx, p_sig_data, p_sig_len, pkey);
end code
return err
end FUNCTION

####################################
FUNCTION print_errors()
####################################
CALL initialize()
code
  ERR_print_errors_fp(stderr);
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
FUNCTION initialize()
####################################
if not mv_initialized then
    let mv_initialized = true
code
    /* Just load the crypto library error strings,
     * SSL_load_error_strings() loads the crypto AND the SSL ones */
    /* SSL_load_error_strings();*/
    ERR_load_crypto_strings();
end code
end if
end FUNCTION
