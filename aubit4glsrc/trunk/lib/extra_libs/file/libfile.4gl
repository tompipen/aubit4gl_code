{

This is new SHARED handling - removed the old method
(which looked bad) and introduced the "::" syntax as per perl (as someone
here suggested a while ago)

This library in lib/extra_libs/file for file handling as an example.

Try the 'file.4gl' example in tools/test...

}

code
#include <stdio.h>
endcode

	WHENEVER ERROR CONTINUE
	WHENEVER ANY ERROR CONTINUE
	WHENEVER SQLERROR CONTINUE


####################################
FUNCTION popen(p_command,mode)
####################################
DEFINE p_command char(256)
DEFINE mode char(3)
DEFINE r INTEGER

code
	A4GL_trim(p_command);
	A4GL_trim(mode);
	r=(long)popen(p_command,mode);
endcode

	IF r=0 THEN
		LET status=-101
	END IF
	RETURN r
END FUNCTION


####################################
FUNCTION fopen(filename,mode)
####################################
DEFINE filename char(256)
DEFINE mode char(3)
DEFINE r INTEGER

code
	A4GL_trim(filename);
	A4GL_trim(mode);
	r=(long)fopen(filename,mode);
endcode

	IF r=0 THEN
		LET status=-101
	END IF
	RETURN r
END FUNCTION


####################################
FUNCTION ftell(handle)
####################################
DEFINE handle INTEGER
DEFINE r INTEGER

	IF handle=0 THEN
		LET status=-101
		RETURN 0
	END IF

code
	r=ftell((FILE *)handle);
endcode

	RETURN r

END FUNCTION

####################################
FUNCTION ferror(handle)
####################################
DEFINE handle INTEGER
DEFINE r INTEGER

	IF handle=0 THEN
		LET status=-101
		RETURN 0
	END IF

code
	r=ferror((FILE *)handle);
endcode

	RETURN r

END FUNCTION

####################################
FUNCTION fseek(handle,n)
####################################
DEFINE handle INTEGER
DEFINE n INTEGER
DEFINE r INTEGER

	IF handle=0 THEN
		LET status=-101
		RETURN 0
	END IF

code
	r=fseek((FILE *)handle,n,SEEK_SET);
endcode

	if r!=0 THEN
		LET status=-101
	END IF

END FUNCTION

####################################
FUNCTION fseek_from_end(handle,n)
####################################
DEFINE handle INTEGER
DEFINE n INTEGER
DEFINE r INTEGER

	IF handle=0 THEN
		LET status=-101
		RETURN 0
	END IF

code
	r=fseek((FILE *)handle,n,SEEK_END);
endcode

	if r!=0 THEN
		LET status=-101
	END IF

END FUNCTION

####################################
FUNCTION fsize(handle)
####################################
DEFINE handle INTEGER
DEFINE n INTEGER
DEFINE c INTEGER

	IF handle=0 THEN
		LET status=-101
		RETURN 0
	END IF

code
	c=ftell((FILE *)handle);          /* Save current position */
	fseek((FILE *)handle,0,SEEK_END); /* move to end */
	n=ftell((FILE *)handle);          /* Where are we now ? */
	fseek((FILE *)handle,c,SEEK_SET); /* move back to where we started */
endcode

	RETURN n

END FUNCTION

####################################
FUNCTION fgets(handle)
####################################
DEFINE handle INTEGER
DEFINE buff CHAR(256)
DEFINE r INTEGER

	IF handle=0 THEN
		LET status=-101
		RETURN ""
	END IF
	LET buff=""

code
	fgets(buff,255,(FILE *)handle);
	A4GL_trim_nl(buff);
	A4GL_push_char(buff);
	return 1;
endcode

END FUNCTION

####################################
FUNCTION feof(handle)
####################################
DEFINE handle INTEGER
DEFINE r INTEGER

	IF handle=0 THEN
		LET status=-101
		RETURN ""
	END IF


code
{
FILE *hf;
hf=(FILE *)handle;
r=feof(hf);
}
endcode
	
	RETURN r

END FUNCTION

####################################
FUNCTION fclose(handle)
####################################
DEFINE handle INTEGER
DEFINE r INTEGER

	IF handle=0 THEN
		LET status=-101
		RETURN ""
	END IF

code
	r=fclose((FILE *)handle);
endcode
	
	RETURN r

END FUNCTION

####################################
FUNCTION rewind(handle)
####################################
DEFINE handle INTEGER
DEFINE r INTEGER
	
	IF handle=0 THEN
		LET status=-101
		RETURN 0
	END IF

code
	rewind((FILE *)handle);
endcode

END FUNCTION


############################### EOF ##################################
