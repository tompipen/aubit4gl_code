{

This is example for new SHARED handling - removed the old method


(which looked bad) and introduced the "::" syntax as per perl (as someone
here suggested a while ago)

See library in lib/extra_libs/file for file handling as an example.

}



main
define afile integer
define fsize integer
define buff CHAR(80)

WHENEVER SQLERROR CONTINUE
WHENEVER ERROR CONTINUE
WHENEVER ANY ERROR CONTINUE

	CALL A4GL_file::fopen("textfile","r") returning afile

	IF afile=0 THEN
		ERROR "Unable to open a file called 'textfile'"
			WAIT FOR KEY
		EXIT PROGRAM
	END IF

	DISPLAY "afile=",afile
	
	LET status=0
	CALL A4GL_file::fsize(afile) returning fsize

	IF status!=0 THEN
		DISPLAY "ERROR : ",A4GL_file::ferror(afile);
	END IF

	DISPLAY "Size=",fsize
	WHILE TRUE
		CALL A4GL_file::fgets(afile) returning buff
		IF A4GL_file::feof(afile) THEN
			EXIT WHILE
		END IF
		DISPLAY "Read '",buff clipped,"' from file"
	END WHILE

end main
	
