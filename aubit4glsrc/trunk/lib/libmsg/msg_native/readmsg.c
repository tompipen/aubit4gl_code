/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
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
# $Id: readmsg.c,v 1.8 2003-01-21 08:25:55 afalout Exp $
#*/

/**
 * @file
 * Functions for reading help message file in native format
 *
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_lib_msg_native_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/* from extfile.c : */
char 	helpbuff[10000];
char 	disp[24][81];
int 	max_width;
FILE *	helpfile = 0;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 * @todo Describe function
 */
int
read_help_f (int no,int *maxwidth)
{
short pos;
int cnt;
short num;
char tmpbuf[80];


  max_width = 0;
  cnt = 0;
  rewind (helpfile);
  helpbuff[0]=0;
  *maxwidth=0;

  /*
    FIXME:

	4gl programs are expected to specify full help file name, including the
    extendion. This allmost allways means that programs will specify .iem
    exstension, but Aubit help compiler will create help files with extension
    acl_getenv ("A4GL_HLP_EXT") - which has to be different then Informix one -
    to faciliate creation of multi-compiler make files, and also to distinguish
    between files that are obviously not compatible.

    Therefore, we should not just blindly take "helpfile" variable, but instead
    first strip it's extension, and add Aubit one.

    We also need to try using $DBPATH, as Informix does, to search for this
    file, if it's not in current directory.

  */


  debug("Reading : %d (%p)",no,helpfile);
  while (1)
    {
      fread (&pos, 2, 1, helpfile);
      debug("pos=%d",pos);

      if (pos == -1 || pos > no) {
         debug("Out of range 1");
         exitwith ("Help message not found");
        break;
      }

      if (feof (helpfile)) {
         debug("End of file");
         exitwith ("Help message not found");
        return 0;
        break;
      }

      fread (&num, 2, 1, helpfile);

      debug("num=%d",num);

      if (pos == no)
        {
			debug("Got it...");
          fseek (helpfile, (long) num + 3, SEEK_SET);
          while (1 == 1)
            {
              if (feof (helpfile))
                break;
              fgets (tmpbuf, 80, helpfile);
				debug("Buff=%s",tmpbuf);
              strcat(helpbuff,tmpbuf);
              stripnl (tmpbuf);
              strcpy (disp[cnt++], tmpbuf);
              if (strlen (tmpbuf) > max_width)
                max_width = strlen (tmpbuf);
              if (cnt > 20)
                break;
              num = fgetc (helpfile);
              if (num == 127)
                break;
              else
                ungetc (num, helpfile);
            }
        }

      *maxwidth=max_width;
      if (pos == no) {
           debug("Got it...");
           return cnt;
      }
    }
  exitwith ("Could not read help message");
  return 0;

}

/* ============================== EOF =============================== */

