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
# $Id: extfile.c,v 1.12 2003-04-09 06:54:23 mikeaubury Exp $
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

FILE *helpfile = 0;
FILE *langfile = 0;
char *language_file_contents=0;
char disp[24][81];
int max_width;
char *curr_help_filename=0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void 			set_help_file 			(char *fname);
void 			set_lang_file 			(char *fname_orig);


/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Callable from 4GL
 *
 * @todo Describe function
 */
void
set_help_file (char *fname)
{
  if (helpfile != 0) fclose (helpfile);

  if (curr_help_filename) free(curr_help_filename);
  curr_help_filename=strdup(fname);

  helpfile = (FILE *)open_file_dbpath(fname);
  if (helpfile==0) {
        exitwith("Unable to open help file");
  }
debug("Helpfile=%p",helpfile);
}


/**
 * Callable from 4GL
 *
 * @todo Describe function
 */
void
set_lang_file (char *fname_orig)
{
long l;
long a;
char *fname;

	fname=strdup(fname_orig);
	trim(fname);
	debug("Language file='%s'",fname);

	if (language_file_contents!=0) free(language_file_contents);
	langfile = (FILE *)open_file_dbpath(fname);

	if (langfile==0) {
	        language_file_contents=0;
	        exitwith("Unable to open language file");
	        free(fname);
	        return;
	}

	fseek(langfile,0,SEEK_END);
	l=ftell(langfile);
	rewind(langfile);
	language_file_contents=malloc(l+1);
	fread(language_file_contents,l,1,langfile);

	language_file_contents[l]=0x0;

	fclose(langfile);
	debug("langfile=%p",langfile);

	for (a=0;a<l;a++) {
	        if ( language_file_contents[a]=='\n') {
	                language_file_contents[a]=0;
	        }
	}

	free(fname);
}

/**
 *
 * @todo Describe function
 */
int
aclfgl_a4gl_show_help(int a)
{
    	a=pop_int();
    	aclfgli_show_help(a);
	return 0;
}


/**
 *
 * @todo Describe function
 */
char *
get_translated_id (char * no_c)
{
short pos;
int cnt;
short num;
short *ptr;
int no;
char *cptr;
max_width = 0;
cnt = 0;
no=atoi(no_c);

  cptr=language_file_contents;
  if (cptr==0) {
        exitwith("No language file");
        return "<unknown>";
  }


  ptr=(short *)language_file_contents;

  while (1)
    {
      pos=*(short *)cptr;
      debug("pos=%d",pos);

      cptr+=2;

      if (pos == -1 || pos > no) {
         debug("Out of range 1");
         exitwith("message not found");
        return 0;
        break;
      }

      num=*(short *)cptr;
      cptr+=2;
      debug("num=%d",num);

      if (pos == no)
        {
          cptr=language_file_contents+num+3;
        debug("returning %p",cptr);
          return cptr;

        }
    }
  exitwith("Could not read lang text");
  return "<unknown>";

}


/**
 *
 * @todo Describe function
 */
int
has_helpfile(void) 
{
	if (helpfile) return 1;
	else return 0;
}

/*
 * This is the main show_help function...
 * 
*/
int aclfgli_show_help(int n) {
	long a;
		a=pop_long();
		if (has_helpfile()) {
			push_char((char *)get_helpfilename());
			push_long(a);
			aclfgli_libhelp_showhelp(2);
		}
}


char *get_helpfilename(void) 
{
	if (helpfile) return curr_help_filename;
	else return 0;
}

/**
 *
 * @todo Describe function
 */
char *
get_help_disp(int n) 
{
	return disp[n];
}

char last_outfile[256]="";
void set_last_outfile(char *s) {
	debug("last_outfile=%s",s);
	strcpy(last_outfile,s);
}

char *get_last_outfile(void) {
	debug("Returning last_outfile=%s",last_outfile);
	return last_outfile;
}

/* ================================ EOF =============================== */
