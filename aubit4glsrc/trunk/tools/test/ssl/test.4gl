MAIN

DEFINE keyfile CHAR(40)
DEFINE certfile CHAR(40)
DEFINE data varchar(50)

DEFINE lv_seal CHAR(2048)
DEFINE lv_seal_size INT
DEFINE la_seal VARCHAR(2048)

DEFINE lv_err int

LET certfile =  "cert.pem"
LET keyfile  = "key.pem"
LET data     = "I owe you..."

CALL A4GL_ssl::get_privatekey(keyfile)
CALL A4GL_ssl::sign(data,length(data),"md5") RETURNING lv_seal, lv_seal_size
LET la_seal = lv_seal[1,lv_seal_size]
DISPLAY "seal=", la_seal
CALL A4GL_ssl::free_key()

CALL A4GL_ssl::get_publickey(certfile)
LET lv_err =  A4GL_ssl::verify(lv_seal, lv_seal_size, data,length(data),"md5")
CALL A4GL_ssl::free_key()

IF lv_err != 1 THEN
	CALL A4GL_ssl::print_errors()
ELSE
    DISPLAY "Signature Verified Ok."
END IF
END MAIN
