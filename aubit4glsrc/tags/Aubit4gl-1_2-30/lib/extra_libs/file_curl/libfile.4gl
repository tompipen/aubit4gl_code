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

	 $Id: libfile.4gl,v 1.1 2010-05-19 17:46:05 mikeaubury Exp $
}

{**
 * @file
 *
 * Collections of functions for file system files handling from 4GL
 * Finctions defined in this library:
 * popen pclose fclose
 * url_fopen ftell ferror fseek fseek_from_end fsize fgets fputs feof url_rewind
 * opendir readdir closedir
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
#include <dirent.h>
#include <unistd.h>
#include <curl/curl.h>
#include "a4gl_curl.h"

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
FUNCTION fopen(filename,mode)
####################################
DEFINE filename char(256)
DEFINE mode char(3)
DEFINE r INTEGER

code
	A4GL_trim(filename);
	A4GL_trim(mode);
	r=(long)url_fopen(filename,mode);
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
	url_fgets(buff,255,(URL_FILE *)handle);
	A4GL_trim_nl(buff);
	A4GL_push_char(buff);
	A4GLSTK_popFunction();
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
URL_FILE *hf;
hf=(URL_FILE *)handle;
r=url_feof(hf);
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
	r=url_fclose((URL_FILE *)handle);
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
	url_rewind((URL_FILE *)handle);
endcode

END FUNCTION




############################### EOF ##################################
