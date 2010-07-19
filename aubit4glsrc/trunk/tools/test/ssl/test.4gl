MAIN

DEFINE keyfile CHAR(40)
DEFINE certfile CHAR(40)
DEFINE data varchar(50)

DEFINE lv_seal CHAR(2048)
DEFINE lv_seal_size INT

DEFINE lv_err int

LET certfile =  "cert.pem"
LET keyfile  = "key.pem"
LET data     = "I owe you..."

CALL A4GL_ssl::get_privatekey(keyfile) RETURNING lv_err
IF lv_err != 1 THEN
    DISPLAY "error private key"
	CALL A4GL_ssl::print_errors()
    EXIT PROGRAM -1
END IF
CALL A4GL_ssl::sign(data,length(data),"md5") RETURNING lv_err, lv_seal, lv_seal_size
IF lv_err != 1 THEN
    DISPLAY "error sign"
	CALL A4GL_ssl::print_errors()
    EXIT PROGRAM -2
END IF
CALL A4GL_ssl::free_key()
IF lv_err != 1 THEN
    DISPLAY "error free"
	CALL A4GL_ssl::print_errors()
    EXIT PROGRAM -3
END IF

CALL A4GL_ssl::get_publickey(certfile) RETURNING lv_err
IF lv_err != 1 THEN
    DISPLAY "error get public key"
	CALL A4GL_ssl::print_errors()
    EXIT PROGRAM -4
END IF
LET lv_err =  A4GL_ssl::verify(lv_seal, lv_seal_size, data,length(data),"md5")
CALL A4GL_ssl::free_key()

IF lv_err != 1 THEN
    DISPLAY "Error in verify"
	CALL A4GL_ssl::print_errors()
    EXIT PROGRAM -5
ELSE
    DISPLAY "Signature Verified Ok."
END IF
END MAIN
