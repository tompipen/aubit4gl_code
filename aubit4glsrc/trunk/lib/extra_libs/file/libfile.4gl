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

	IMPORT FUNCTION ferror(1)


####################################
FUNCTION popen(p_command,mode)
####################################
DEFINE p_command char(256)
DEFINE mode char(3)
DEFINE r INTEGER

code
	trim(p_command);
	trim(mode);
	r=popen(p_command,mode);
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
	trim(filename);
	trim(mode);
	r=fopen(filename,mode);
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
	r=ftell(handle);
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
	r=fseek(handle,n,SEEK_SET);
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
	r=fseek(handle,n,SEEK_END);
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
	c=ftell(handle);          /* Save current position */
	fseek(handle,0,SEEK_END); /* move to end */
	n=ftell(handle);          /* Where are we now ? */
	fseek(handle,c,SEEK_SET); /* move back to where we started */
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
	fgets(buff,255,handle);
	trim_nl(buff);
	push_char(buff);
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
	r=feof(handle);
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
	r=fclose(handle);
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
	rewind(handle);
endcode

END FUNCTION


############################### EOF ##################################
