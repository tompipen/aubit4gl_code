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
# $Id: extfile.c,v 1.29 2006-11-28 18:55:41 mikeaubury Exp $
#
*/

/**
 * @file
 *
 * @todo Add Doxygen comments to file
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

static FILE *helpfile = 0;
static FILE *langfile = 0;
static char *language_file_contents = 0;
static char disp[24][81];
static int max_width;
static char *curr_help_filename = 0;
static char last_outfile[256] = "";

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void A4GL_set_help_file (char *fname);
void A4GL_set_lang_file (char *fname_orig);

int aclfgl_a4gl_show_help (int a);
int aclfgli_show_help (int n);
char * A4GL_get_helpfilename (void);
//int aclfgl_aclfgl_libhelp_showhelp(int helpno);
//void A4GL_set_last_outfile (char *s);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Invoked when HELP FILE "filename.iem" is encountered in 4GL code.
 * Checks id file exists, and sets current help file for later use by
 * explicit (call SHOWHELP(123)) or implicit (MENU ... COMMAND ... HELP 123)
 * invocation
 *
 * @param fname file name containing compiled help messages
 */
void
A4GL_set_help_file (char *fname)
{
  char a[128] = "";
  char b[128] = "";
  char c[128] = "";

  if (helpfile != 0)
    fclose (helpfile);

  if (curr_help_filename)
    free (curr_help_filename);
  curr_help_filename = acl_strdup (fname);

  helpfile =  A4GL_open_file_dbpath (fname);

  if (helpfile == 0)
    {
      /* Many 4GL programs out there use fixed extension .iem to specify help file,
         but because we need to distinguish between help files created by different
         compilers, im nost cases Aubit compiled help files will have extension .hlp
         Therefore, if checking for hard-coded file name fails, we need to try to
         substitire extension, and check again:
       */

      strcpy (c, fname);
      A4GL_bname (c, a, b);

      //if (strcmp (b, "iem") == 0)

      strcat (a, acl_getenv ("A4GL_HLP_EXT"));

      helpfile = A4GL_open_file_dbpath (a);


      if (helpfile == 0)
	{
	  A4GL_exitwith ("Unable to open help file");
	}
    }

#ifdef DEBUG
  A4GL_debug ("Helpfile=%p", helpfile);
#endif
}


/**
 * Callable from 4GL
 *
 * @todo Describe function
 */
void
A4GL_set_lang_file (char *fname_orig)
{
  long l;
  long a;
  char *fname;

  fname = acl_strdup (fname_orig);
  A4GL_trim (fname);
  A4GL_debug ("Language file='%s'", fname);

  if (language_file_contents != 0)
    free (language_file_contents);
  langfile = A4GL_open_file_dbpath (fname);

  if (langfile == 0)
    {
      language_file_contents = 0;
      A4GL_exitwith ("Unable to open language file");
      free (fname);
      return;
    }

  fseek (langfile, 0, SEEK_END);
  l = ftell (langfile);
  rewind (langfile);
  language_file_contents = acl_malloc2 (l + 1);
  fread (language_file_contents, l, 1, langfile);

  language_file_contents[l] = 0x0;

  fclose (langfile);
  A4GL_debug ("langfile=%p", langfile);

  for (a = 0; a < l; a++)
    {
      if (language_file_contents[a] == '\n')
	{
	  language_file_contents[a] = 0;
	}
    }

  free (fname);
}

/**
 *
 * @todo Describe function
 */
int
aclfgl_a4gl_show_help (int a)
{
  A4GL_assertion(a!=1,"show help takes 1 parameter");

  //a = A4GL_pop_int ();
  aclfgli_show_help (a);
  return 0;
}


/**
 *
 * @todo Describe function
 */
char *
A4GL_get_translated_id (char *no_c)
{
  short mno;
  int cnt;
  //short num;
  //short *ptr;
  int no;
//  unsigned char *cptr;
  char *cptr;
  long len;
  long offset;
  max_width = 0;
  cnt = 0;
  no = atoi (no_c);
  A4GL_debug("no=%d (from %s)",no,no_c);
  cptr = language_file_contents;
  if (cptr == 0)
    {
      A4GL_exitwith ("No language file");
      return "<unknown>";
    }
  cptr+=4;

  //ptr = (short *) (language_file_contents);

  while (1)
    {
      mno =  cptr[0] * 256 + cptr[1];
      A4GL_debug ("pos=%d (%x)", mno,mno);


      if (mno == -1 || mno > no)
	{
	  A4GL_debug ("Out of range 1");
	  A4GL_exitwith ("message not found");
	  return 0;
	  break;
	}

	len = cptr[2] * 256 + cptr[3];

	offset = cptr[4] * 16777216 // 256 ^ 3
	        + cptr[5] * 65536   // 256 ^ 2
		        + cptr[6] * 256
			 +cptr[7];


      if (mno == no)
	{
	  cptr = language_file_contents + offset ;
	  A4GL_debug ("returning %p", cptr);
	  return cptr;

	}
      cptr += 8;
    }
  A4GL_exitwith ("Could not read lang text");
  return "<unknown>";

}


/**
 *
 * @todo Describe function
 */
int
A4GL_has_helpfile (void)
{
  if (helpfile)
    return 1;
  else
    return 0;
}

/*
 * This is the main show_help function...
 * 
*/
int
aclfgli_show_help (int n)
{
  long a;
  a = A4GL_pop_long ();
  if (A4GL_has_helpfile ())
    {
      A4GL_push_char ((char *) A4GL_get_helpfilename ());
      A4GL_push_long (a);
      aclfgl_aclfgl_libhelp_showhelp (2);
    }
	return 1;

}


char *
A4GL_get_helpfilename (void)
{
  if (helpfile)
    return curr_help_filename;
  else
    return 0;
}

/**
 *
 * @todo Describe function
 */
char *
A4GL_get_help_disp (int n)
{
  return disp[n];
}


/**
 *
 * @todo Describe function
 */
void
A4GL_set_last_outfile (char *s)
{
  A4GL_debug ("last_outfile=%s", s);
  strcpy (last_outfile, s);
}

/**
 *
 * @todo Describe function
 */
char *
A4GL_get_last_outfile (void)
{
  A4GL_debug ("Returning last_outfile=%s", last_outfile);
  return last_outfile;
}

/* ================================ EOF =============================== */
