{
###########################################################################
# This program is free software; you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the
# Free Software Foundation; either version 2 of the License, or (at your
# option) any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
# General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
#
###########################################################################

	 $Id: libfile.4gl,v 1.12 2004-11-01 05:11:19 afalout Exp $
}

{**
 * @file
 *
 * Collections of functions for file system files handling from 4GL
 * Finctions defined in this library:
 * popen fopen ftell ferror fseek fseek_from_end fsize fgets feof fclose rewind
 * 
 *
 * This library uses new SHARED handling - the old method (which looked bad) 
 * was removed and the "::" syntax (as per perl) is introduced
 *
 * See the 'file.4gl' example in tools/test for examples of usage
 *
 * @todo    : Add Doc4GL comments to functions and variables in this file
 *
 * @version : original
 *
 * @process : UNKNOWN
 *
 *}


code
#include <stdio.h>
endcode

	WHENEVER ERROR CONTINUE
	WHENEVER ANY ERROR CONTINUE
	WHENEVER SQLERROR CONTINUE

{**
 * 
 *
 *
 *}
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

{**
 * 
 *
 *
 *}
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

{**
 * 
 *
 *
 *}
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

{**
 * 
 *
 *
 *}
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

{**
 * 
 *
 *
 *}
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

{**
 * 
 *
 *
 *}
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

{**
 * 
 *
 *
 *}
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

{**
 * 
 *
 *
 *}
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

{**
 * 
 *
 *
 *}
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

{**
 * 
 *
 *
 *}
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

{**
 * 
 *
 *
 *}
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
