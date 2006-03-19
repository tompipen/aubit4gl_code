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
# $Id: errfile.c,v 1.24 2006-03-19 14:08:17 mikeaubury Exp $
#
*/

/**
 * @file
 * File error writing
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

//change this tp HAVE_SHARE_H
//#ifdef __NATIVE_WINDOWS__
#if HAVE_SHARE_H
#include <share.h>
#endif

#include "a4gl_libaubit4gl_int.h"


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

static char buff[2048];
static FILE *fout = 0;
static long le;
static int errline;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void A4GL_find_nl (FILE * f, long fp, long *s, long *e);
void A4GL_prerrmark (FILE * f, int a);
//void A4GL_write_errfile_many_errors(char *errfile,FILE *fin,struct s_module_error *e,int cnt);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Write to error file.
 *
 * The error file is a copy of the source file with an error on it.
 * Used by the compiler.
 *
 * @param f A pointer to the source file name.
 * @param fname The error file name.
 * @param as Position in the file
 * @param lineno Line number on the source file.
 */
FILE *
A4GL_write_errfile (FILE * f, char *fname, long as, int lineno)
{
  int a;
  long s2, e;
  long s;
  int b;
  //int errorno;

  fout = A4GL_mja_fopen (fname, "w");
  if (fout == 0)
    {
      PRINTF ("Unable to open %s\n", fname);
      A4GL_fgl_die (2);
    }
  //errorno = ferror (f);



  /* find the nearest NL */
  A4GL_find_nl (f, as, &s2, &e);
  if ((as - s2) <= 0)
    {
      as -= 2;
      A4GL_find_nl (f, as, &s2, &e);
    }
#ifdef DEBUG
  A4GL_debug ("s2=%d e=%d", s2, e);
#endif
  s = e + 1;
  errline = lineno;
  rewind (f);
  a = 2048;
  while (s > 0)
    {
      if (a > s) {
	a = s;
      }
      //printf("s=%d a=%d\n",s,a);

      b=fread (buff, 1,(size_t)a,  f);
      fwrite (buff, (size_t)b, 1, fout);
      s -= a;
    }
  le = as - s2;
  A4GL_prerrmark (fout, (int) (as - s2));
  return fout;
}

/**
 * Copy the rest of the bytes in the input file to the output file.
 *
 * @param f A pointer to the input source file.
 */
void
A4GL_write_cont (FILE * f)
{
  int a, s = 1;
  a = 2048;
  FPRINTF (fout, "\n");
  while (s > 0)
    {
      /* if (feof(f)) break; */
      s = fread (buff, (size_t)1, a, f);
      fwrite (buff, (size_t)s, 1, fout);
    }
  fclose (fout);
}


/**
 * Find the new lines nearest to a position in a file.
 *
 * @param f The pointer to the opened file.
 * @param fp The file position where to find the new line.
 * @param s A pointer to the place where to return the position of the new line
 *   before.
 * @param e A pointer to the place where to return the position of the new line
 *   after.
 */
void
A4GL_find_nl (FILE * f, long fp, long *s, long *e)
{
  char buff[10];

  while (fp > 0)
    {
      fseek (f, fp, SEEK_SET);
      fread (buff, (size_t)1, 1, f);
      if (buff[0] == '\n')
	break;
      fp--;
    }
  *s = fp + 1;
  buff[0] = 0;
  for (fp = *s + 1; buff[0] != '\n'; fp++)
    {
      fseek (f, fp, SEEK_SET);
      fread (buff, (size_t)1, 1, f);
      if (feof (f))
	break;
    }
  *e = fp - 1;
}

/**
 *
 * @todo Describe function
 */
void
A4GL_prerrmark (FILE * f, int a)
{
  int b;
  FPRINTF (f, "|");
  for (b = 1; b < a - 1; b++)
    {
      FPRINTF (f, "_");
    }
  FPRINTF (f, "^\n");
  FPRINTF (f, "| Error at line %d, character %d\n", errline, (int) le);

}

/*
main() {
FILE *f;
f=mja_fopen("test","r");
write_errfile(f,"test.out",10);
write_cont(f);
}
*/


/**
 * Open a file
 *
 * @param name The file name.
 * @param mode The mode for passing directy to mode.
 * @return The pointer to the opened file.
 */
FILE *
A4GL_mja_fopen (char *name, char *mode)
{
  return fopen (name, mode);
}



void A4GL_write_errfile_many_errors(char *errfile,FILE *fin,struct s_module_error *e,int cnt) {
FILE *fout;
int a;
char lnbuff[20000];
int ln;
int maxed=0;
  fout = A4GL_mja_fopen (errfile, "w");
  if (fout == 0)
    {
      PRINTF ("Unable to open %s\n", errfile);
      A4GL_fgl_die (2);
    }
    rewind(fin);
    ln=0;
    if (cnt>21)  {cnt=21; maxed=1;}

    while (fgets(lnbuff,sizeof(lnbuff),fin)) {
	ln++;
	FPRINTF(fout,"%s",lnbuff);
	for (a=0;a<cnt;a++) {
		if (e[a].lineno==ln) {
			FPRINTF(fout,"|\n");
			FPRINTF(fout,"|%s\n",e[a].err_str);
			if (a==20 && maxed) {
				FPRINTF(fout,"| ****  Too many errors - further errors ignored ****\n");
			}
		}
	}
    }
    fclose(fout);
}

/* ================================== EOF ============================= */
