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
# $Id: others.c,v 1.61 2006-01-29 16:39:10 mikeaubury Exp $
#
*/

/**
 * @file
 * Other 4gl internal functions implementation, plus some functions we did
 * not know where to put...
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"
#include <stdio.h>
#include <ctype.h>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/* here only to satisfy libMENU_( from compilers/4glc/4glc.c)
also referenced from 4glc.c and other places.
Move it to a4gl_libaubit4gl.h
*/


 char *outputfilename;
int ccnt = 0;			/* was in lexer.c */



struct struct_form the_form;
 struct struct_scr_field *fld;
int as_c = 1;
int m_lastkey = 0;


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/



////char *A4GL_replace_sql_var (char *s);
//int A4GL_fgl_keyval (int _np);
//int aclfgl_aclfgl_random(int n) ;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/



int get_ccnt() {
	return ccnt;
}

void set_ccnt(int a) {
	ccnt=a;
}

/**
 * Get the laskey typed by the user.
 *
 * Return the values by the stack.
 *
 * @param _np Number of parameters passed by stack. Should be zero. If not
 * give an error.
 */
int
aclfgl_fgl_lastkey (int _np)
{
  long _r;
  if (_np != 0)
    {
      A4GL_fgl_error (-3000, "", 0, 0);
    }

  _r = A4GL_get_lastkey ();
  A4GL_debug ("TST1 Lastkey=%d", _r);

  A4GL_push_long (_r);
  return 1;
}


#ifdef MOVED

int aclfgl_aclfgl_set_color (int _nargs){ 
   long c ; 
   long r ; 
   long g ; 
   long b ; 
   struct BINDING fbind[4]={ /* 4 */
   {0,2,0,0,0,0} ,
   {0,2,0,0,0,0} ,
   {0,2,0,0,0,0} ,
   {0,2,0,0,0,0}
   }; 
   fbind[0].ptr=&c;
   fbind[1].ptr=&r;
   fbind[2].ptr=&g;
   fbind[3].ptr=&b;
   A4GL_pop_params(fbind,4);

   A4GL_init_color(c,r,g,b);

   return 0;
}

#endif

#ifdef MOVED

int aclfgl_aclfgl_get_user(int n) {
	A4GL_push_user ();
	return 1;
}


/**
 * Gets the integer keyval from a string representing it.
 *
 * The string with the name is passed by the stack.
 *
 * The keyval is  returned by the stack.
 *
 * @param _np The number of para,eters passed by stack.
 * @return Allways 1
 */
int
A4GL_fgl_keyval (int _np)
{
  long _r;
  char *v0;
  char buff[20];

  if (_np != 1)
    {
      A4GLSQL_set_status (-3000, 0);
      A4GL_debug ("Bad number of arguments to A4GL_fgl_keyval got %d - expected 1",
	     _np);

      for (_r = 0; _r < _np; _r++)
	{
	  A4GL_pop_char (buff, 10);
	}
    }

  v0 = A4GL_char_pop ();
  A4GL_debug ("TST1 - v0=%s", v0);

  _r = A4GL_key_val (v0);
  A4GL_debug ("TST1 - r=%d\n", _r);
  A4GL_push_long (_r);
  acl_free (v0);
  return 1;
}
#endif


/**
 * Upshift a string
 *
 * @param s The string to be converted.
 */
void
A4GL_convupper (char *s)
{
  int a;
  for (a = 0; s[a]; a++)
    {
      s[a] = toupper (s[a]);
    }
}

/**
 * Downshift a string
 *
 * @param s The string to be converted.
 */
void
A4GL_convlower (char *s)
{
  int a;
  for (a = 0; s[a]; a++)
    {
      s[a] = tolower (s[a]);
    }

}


#ifdef MOVED
/**
 * Get the integer key value from a string.
 *
 * @param v The string key representation.
 * @return The integer key representation.
 */
int
A4GL_net_keyval (char *v)
{
  char v0[800];
  long _r;

  A4GL_debug ("In net_keyval");
  strcpy (v0, v);
  A4GL_trim (v);
  A4GL_stripnl (v);
  A4GL_debug ("Decoding ...%s...", v0);
  if (strlen (v0) == 1)
    {
      return v0[0];
    }
  if (strcmp (v0, "INTERRUPT") == 0)
    {
      return (-1);
    }
  if (strcmp (v0, "ACCEPT") == 0)
    {
      return (-2);
    }
  if (strcmp (v0, "LEFT") == 0)
    return A4GLKEY_LEFT;
  if (strcmp (v0, "RIGHT") == 0)
    return A4GLKEY_RIGHT;
  if (strcmp (v0, "UP") == 0)
    return A4GLKEY_UP;
  if (strcmp (v0, "DOWN") == 0)
    return A4GLKEY_DOWN;
  if (strcmp (v0, "PGUP") == 0)
    return A4GLKEY_PGUP;
  if (strcmp (v0, "PGDN") == 0)
    return A4GLKEY_PGDN;
  if (strcmp (v0, "INS") == 0)
    return A4GLKEY_INS;
  if (strcmp (v0, "DEL") == 0)
    return A4GLKEY_DEL;
  if (strcmp (v0, "BACKSPACE") == 0)
    return 8;
  if (strcmp (v0, "RETURN") == 0)
    return CR;
  if (strcmp (v0, "TAB") == 0)
    return 9;
  if (strcmp (v0, "HOME") == 0)
    return A4GLKEY_HOME;
  if (strcmp (v0, "END") == 0)
    return A4GLKEY_END;
  if (strcmp (v0, "ESCAPE") == 0)
    return 27;

  if (v0[0] == 'F')
    {
      _r = atoi (&v0[1]);
      return (A4GLKEY_F (_r));
    }

  if (v0[0] == '^')
    {
      return (v0[1] - 'A' + 1);
    }
  A4GL_debug ("Not found in here");
  return 0;
}

#endif

/**
 *
 * @todo Describe function
 */
int
A4GL_get_lastkey (void)
{
  return m_lastkey;
}


/**
 *
 * @todo Describe function
 */
void
A4GL_set_last_key (int a)
{
  m_lastkey = a;
}


/**
 * WARNING: must NOT use calls to A4GL_debug in this function - it would cause
 * endless loop
 * @todo Describe function
 */
char * A4GL_strip_quotes (char *s)
{
  static char *buff_sq=0;

  buff_sq=realloc(buff_sq,strlen(s)+10);

  if ((s[0] == '"' || s[0] == '\'') && s[strlen (s) - 1] == s[0])
    {
      strcpy (buff_sq, &s[1]);
      buff_sq[strlen (buff_sq) - 1] = 0;
    }
  else
    {
      strcpy (buff_sq, s);
    }
  return buff_sq;
}


/**
 *
 * @todo Describe function
 */
char *
A4GL_replace_sql_var (char *s)
{
  static char buff[1024];
  char *ptr;

  A4GL_debug("In replace_sql_var :%s\n",s);

  //if (s[0] != '\n')
    //{
      //return s;
    //}
  strcpy (buff, s);

  A4GL_debug("Buff=%s\n",buff);

  if (A4GL_aubit_strcasecmp (buff, "today") == 0)
    {
      A4GL_push_today ();
      ptr = A4GL_char_pop ();
      strcpy (buff, ptr);
      acl_free (ptr);
      A4GL_debug("Its today!");
  A4GL_debug ("replace_sql_var :Returning %s", buff);
	return buff;
    }

  if (A4GL_aubit_strcasecmp (buff, "user") == 0)
    {
      A4GL_push_user ();
      ptr = A4GL_char_pop ();
      strcpy (buff, ptr);
      acl_free (ptr);
  A4GL_debug ("replace_sql_var :Returning %s", buff);
	return buff;
    }
  return s;
  A4GL_debug ("replace_sql_var :Returning %s", buff);

}



#ifdef MOVED
/**
 *
 * @todo Describe function
 */
int
A4GL_attr_name_match (struct struct_scr_field *field, char *s_x)
{
  char colname[40];
  char tabname[40];
  int aa;
  int ab;
   char s[256];

     A4GL_debug ("Field : %p \n", field);
     
strcpy(s,s_x);
  A4GL_trim(s);
     A4GL_debug ("attr_name_match : %s", s);
  A4GL_bname (s, tabname, colname);


     A4GL_debug ("Splits to %s & %s", tabname, colname);
     A4GL_debug ("field is [%s %s]", field->tabname, field->colname);


  aa = strcmp (field->tabname, tabname);
  ab = strcmp (field->colname, colname);
  /* A4GL_debug ("Matches = %d %d ", aa, ab); */
  if ((ab == 0) || (colname[0] == '*'))
    {
      A4GL_debug ("Match on * (%s,%s,%s) (%s,%s)",s,tabname,colname,field->tabname,field->colname);
      return 1;
    }
  if (ab == 0 && tabname[0] == 0)
    {
      A4GL_debug ("Matched %s.%s = %s.%s ",tabname,colname,field->tabname,field->colname);
      return 1;
    }
  
     A4GL_debug ("Not matched (%s!=%s or %s!=%s)", field->tabname, tabname,
    field->colname, colname);
 
  return 0;
}
#endif


/**
 *
 * @todo Describe function
 */
char *
A4GL_get_str_attribute (struct struct_scr_field *f, int str)
{
  int a;

  if (!A4GL_has_str_attribute (f, str))
    {
      return 0;
    }

  for (a = 0; a < f->str_attribs.str_attribs_len; a++)
    {
      if (f->str_attribs.str_attribs_val[a].type == str)
	return f->str_attribs.str_attribs_val[a].value;
    }
  return 0;
}



/**
 *
 * @todo Describe function
 */
int
A4GL_find_srec (struct_form * fd, char *name)
{
  int a;

  A4GL_debug ("No of records : %d", fd->records.records_len);

  for (a = 0; a < fd->records.records_len; a++)
    {
	A4GL_debug("MJA MJA %s - %s\n",fd->records.records_val[a].name,name);
	if (A4GL_aubit_strcasecmp (name, fd->records.records_val[a].name) == 0) {
		A4GL_debug("Found it...");
	return a;
	}
    }
  return -1;
}



/**
 *
 * @todo Describe function
 */
int
A4GL_has_str_attribute (struct struct_scr_field *f, int str)
{
  int a;
  if (f == 0)
    {
      A4GL_assertion (1, "has_str_attribute passed null pointer..");
    }
  for (a = 0; a < f->str_attribs.str_attribs_len; a++)
    {
      if (f->str_attribs.str_attribs_val[a].type == str)
	return 1;
    }
  return 0;
}


/**
 *
 * @todo Describe function
 */
char *
A4GL_char_val (char *s)
{
  static char str[800];
  int a;
  strcpy (str, &s[1]);
  str[strlen (str) - 1] = 0;
  for (a = 0; a < strlen (str); a++)
    {
      if (str[a] == '\t')
	str[a] = ' ';
    }
  return str;
}

#ifdef MOVED
int aclfgl_aclfgl_random(int n) {
int a;
static int seeded=0;
	if (!seeded) {
		seeded=1;
		srand(time(0));
	}
	a=A4GL_pop_int();
	a=rand()%a;
	A4GL_push_int(a);
	return 1;
}
#endif

/** Moved from readforms.c
 *
 *
 */
struct struct_screen_record *
A4GL_get_srec (char *name)
{
  int a;
  struct s_form_dets *form;
  A4GL_debug ("Get_srec");
  form = A4GL_get_curr_form (1);
  A4GL_debug ("found form");

  A4GL_debug ("Got form %p", form);

  if (form == 0)
    {
      A4GL_debug ("No form...");
      return (struct struct_screen_record *) 0;
    }

  A4GL_debug ("fileform=%p name=%p(%s)", form->fileform, name, name);
  A4GL_debug("Database =%s",form->fileform->dbname);
  a = A4GL_find_srec (form->fileform, name);
  A4GL_debug ("Got %d", a);
  if (a == -1)
    return (struct struct_screen_record *) 0;
  else
    return (struct struct_screen_record *) &form->fileform->
      records.records_val[a];
}


#ifdef YYPRINT
  /* Give the individual parser a way to print the precise meaning
     of a token, for further debugging info.  */

//YYPRINT (stderr, yychar, yylval)
int
aubit_yyprint (int xstderr, int xyychar, int xyylval)
{

  //do your output here
  return 0;
}
#endif




/**
 *
 * cygwin headers has no prototype for usleep(), but have the function
 *   on POSIX/ANSI sustems thsi is usually in unistd.h:
 *	extern int usleep (__useconds_t __useconds) __THROW;
 *
 *   Mingwin header stdlib.h has _sleep() but suggest to use Windows API
 *   finstion Sleep() instead (see winbase.h) .
 *
 *	The usleep() function will cause the calling thread to be suspended
 *	from execution until either the number of real-time microseconds
 *	specified by the argument useconds has elapsed or a signal is
 *	delivered to the calling thread and its action is to invoke a
 *	signal-catching function or to terminate the process.
 *	The suspension time may be longer than requested due to the
 *	scheduling of other activity by the system.
 *
 */
void
a4gl_usleep (int a)
{

#if defined( __MINGW32__ ) || defined(MSVC)
#include <winbase.h>
  DWORD b;
  b = a / 1000;
  Sleep (b);			/* SECONDS - __NOT__ micro!!! */
#else
  usleep (a);			/* microseconds !!!!! */
#endif
}

/*
Windows has this functions in winsock.dll
prototypes are in MinGW/include/winsock2.h
		# undef ntohs
*/
/*
unsigned short
A4GL_ntohs(unsigned short netshort)
{
char *ptr;
unsigned short  *iptr;
char buff[2];

	#if HAVE_NTOHS == 0
		// Byte swap..

		#if HAVE_LEAST_BYTE_FIRST == 1
			//least byte first
			ptr=&netshort;
			buff[0]=ptr[1];
			buff[1]=ptr[0];
			iptr=(int *)&buff;
			return *iptr;
		#else
			//#define ntohs(x) (x)
		#endif

    #else
		return ntohs(netshort);
    #endif



}
*/






#ifdef MOVED


/* 
// Added with permission :
//___| read_pipe.c |______________________________________________________
*/
/*
    Run a Unix command and return the first line of output to 4GL
    Usage: CALL read_pipe(command) RETURNING string
    Doug Lawry, 19/12/91

	Modified for Aubit MJA - June 2004
*/

#define MAX_STRING 512

int aclfgl_aclfgl_read_pipe(int nargs)
{
    FILE *pp;                                /* pipe pointer          */
    char *cmd_orig;                    /* command to be run     */
    char *cmd;                    /* command to be run     */
    char data[MAX_STRING];                   /* return from command   */
    int  bytes = 0;                          /* number of bytes read  */

    cmd_orig=A4GL_char_pop();               /* get the command       */
    A4GL_trim(cmd_orig);                   /* strip trailing spaces */
    cmd=acl_malloc2(strlen(cmd_orig)+20);
    strcpy(cmd,cmd_orig);
    free(cmd_orig);
    strcat(cmd, " 2>/dev/null");             /* ignore error output   */

    A4GL_set_a4gl_status(0);

    if ((pp = popen(cmd, "r")) == NULL) {
        A4GL_set_a4gl_status(100);                   /* set error status      */
	} else {
        for (bytes = 0; bytes < MAX_STRING - 1; bytes++)
            if ((data[bytes] = getc(pp)) == EOF || data[bytes] == '\n')
                break;
#ifdef MSVC
        _pclose(pp);                          /* close the pipe        */
#else
		pclose(pp);                          /* close the pipe        */
#endif
    }

    data[bytes] = 0;                      /* terminate string      */

    free(cmd);
    A4GL_push_char(data);                          /* return command output */
    return(1);                               /* returning 1 parameter */
}

/* End of inclusion */
#endif


#if defined (__MINGW32__)

int isblank(int n) {
	if (n==' ') return 1;
	if (n=='\t') return 1;
	return 0;
}


#endif

/* ============================== EOF ========================== */
