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

	 $Id: libfile.4gl,v 1.15 2005-03-10 10:04:36 mikeaubury Exp $
}

{**
 * @file
 *
 * Collections of functions for file system files handling from 4GL
 * Finctions defined in this library:
 * popen pclose fclose
 * fopen ftell ferror fseek fseek_from_end fsize fgets fputs feof rewind
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
	A4GLSTK_popFunction();
	return 1;
endcode

END FUNCTION


####################################
FUNCTION fputs(buff, handle)
####################################
DEFINE handle INTEGER
DEFINE buff CHAR(256)
DEFINE r INTEGER
define count integer

	IF handle=0 THEN
		LET status=-101
	END IF

	let r = 1

code
	A4GL_trim(buff);
	for (count=0; count<256; count++)
	{
		if(buff[count]!='\0')
		{
			putc(buff[count],(FILE *)handle);
			if (ferror((FILE *)handle) != 0)
			{
				r = 0;
			}
		}
		else
		{
			break;
		}
	}
	putc('\n', (FILE *)handle);
	if (ferror((FILE *)handle) != 0)
	{
		r = 0;
	}
endcode

if r = 0 then
	let status = -101
end if
return r

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
FUNCTION pclose(handle)
####################################
DEFINE handle INTEGER
DEFINE r INTEGER

	IF handle=0 THEN
		LET status=-101
		RETURN ""
	END IF

code
	r=pclose((FILE *)handle);
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

{**
 * 
 *
 *
 *}
####################################
FUNCTION opendir(dirname)
####################################
DEFINE dirname char(256)
DEFINE r INTEGER

code
	A4GL_trim(dirname);
	r=(long)opendir(dirname);
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
FUNCTION readdir(handle)
####################################
DEFINE handle integer
DEFINE direntry char(256)
DEFINE r INTEGER

code
{
	struct dirent *dp;
	dp = readdir((DIR *)handle);
	if (dp != NULL)
	{
		strcpy(direntry, dp->d_name);
		r = 1;
	}
}
endcode

	IF r=0 THEN
		LET status=-101
	END IF
	RETURN direntry, r
END FUNCTION

{**
 * 
 *
 *
 *}
####################################
FUNCTION closedir(handle)
####################################
DEFINE handle INTEGER
DEFINE r INTEGER

	IF handle=0 THEN
		LET status=-101
		RETURN ""
	END IF

code
	r=closedir((DIR *)handle);
endcode
	
	RETURN 1

END FUNCTION


{**
 * 
 *
 *
 *}
####################################
FUNCTION fsize_fname(fname)
####################################
DEFINE fname char(512)
DEFINE n INTEGER
DEFINE c INTEGER

code
{
	FILE *handle;
	A4GL_trim(fname);
	handle=fopen(fname,"r");
	if (handle==0) n=0; 
	else {
		fseek((FILE *)handle,0,SEEK_END); /* move to end */
		n=ftell((FILE *)handle);          /* Where are we now ? */
	}
}
endcode

	RETURN n

END FUNCTION


############################### EOF ##################################
