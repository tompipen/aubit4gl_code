/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: writemsg.c,v 1.4 2005-03-09 15:14:49 mikeaubury Exp $
#*/

/**
 * @file
 * mkmess - message help file compiler, Informix 4gl style formated.
 *
 * Compile a message file (.msg), and generates a help compiled file
 * for use in Aubit 4gl programs
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

//#include "a4gl_mkmess_int.h"
#include "a4gl_lib_msg_native_int.h"


/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * process help messages source file and output compiled help file in
 * simple native format:
 *
 * 1. Index section: array of records terminated by (-1, offset)
 *    helpno (2 bytes, native order),
 *    offset -3 (2 bytes, native order)
 * 2. Help strings ( each terminated with char 0x7F )
 *
 * @param offset
 * @param msg input file handle - source code with help messages (.msg)
 * @param tmp temporary file handle
 * @param hlp output file handle
 */
int
A4GL_writemsg (int offset, FILE * msg, FILE * tmp, FILE * hlp)
{
  int flg = 0;
  char tmpbuf[80];
  int offset2;
  int num;

  offset2 = offset;
  rewind (msg);
  tmpbuf[0] = 0;

  while (1)
    {
      if (feof (msg))
	{
	  if (flg == 1)
	    {
	      if (tmpbuf[strlen (tmpbuf)] != '\n' && tmpbuf[0] != '#')
		{
		  fprintf (tmp, "\n");
		}
	      offset++;
	    }
	  break;
	}
      tmpbuf[0] = 0;
      fgets (tmpbuf, 80, msg);
      if (feof (msg))
	break;
      if (tmpbuf[0] == '.')
	{
	  if (flg == 1)
	    {
	      fprintf (tmp, "%c", 127);
	    }
	  offset++;
	  num = atoi (&tmpbuf[1]);
	  fwrite (&num, 2, 1, hlp);
	  fwrite (&offset, 2, 1, hlp);
	  flg = 1;
	  continue;
	}
      if (flg == 1)
	{
	  fprintf (tmp, "%s", tmpbuf);
	  offset = offset + strlen (tmpbuf);
	}
    }

  num = -1;
  fwrite (&num, 2, 1, hlp);
  fwrite (&offset, 2, 1, hlp);
  fclose (tmp);


  return (0);

}


/* ============================= EOF ================================== */
