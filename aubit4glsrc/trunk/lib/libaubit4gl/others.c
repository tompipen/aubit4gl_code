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
# $Id: others.c,v 1.17 2002-10-13 01:40:34 afalout Exp $
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

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/* here only to satisfy libMENU_( from compilers/4glc/4glc.c)
also referenced from 4glc.c and other places.
Move it to a4gl_libaubit4gl.h
*/
char *		outputfilename;
int 		ccnt = 0; /* was in lexer.c */



struct 		struct_form the_form;
struct 		struct_scr_field *fld;
int 		as_c=1;
int 		m_lastkey = 0;


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


#ifdef OLD_INCL
	char * 		char_val 			(char *s);
#endif

char *		replace_sql_var 	(char *s);
int 		fgl_keyval			(int _np);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Get the laskey typed by the user.
 *
 * Return the values by the stack.
 *
 * @param _np Number of parameters passed by stack. Should be zero. If not
 * give an error.
 */
int
aclfgl_fgl_lastkey(int _np)
{
  long _r;
  if (_np!=0) { fgl_error(-3000,"",0,0);}

  _r=get_lastkey();
  push_long(_r);
  return 1;
}

/**
 * Gets the keyval.
 *
 * @param _np the number of parameters passed by stack.
 * @return Allways 1
 */
int
aclfgl_fgl_keyval(int _np)
{
  return fgl_keyval(_np);
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
fgl_keyval(int _np)
{
  long _r;
  char *v0;
  char buff[20];

	if (_np!=1) {
		A4GLSQL_set_status(-3000,0);
		debug("Bad number of arguments to fgl_keyval got %d - expected 1",_np);

		for (_r=0;_r<_np;_r++) {
			pop_char(buff,10);
		}
	}

	v0=char_pop();

	push_int(key_val(v0));
	acl_free(v0);
	return 1;
}

/**
 * Upshift a string.
 *
 * The origin string is getted from the stack.
 *
 * The string upshifted is returned by the stack.
 *
 * @param The number of parameters
 * @return Allways 1
 */
int
aclfgl_upshift(int _np)
{
char *v1;
	if (_np!=1) { fgl_error(-3000,"",0,0);}
	v1=char_pop();
	convupper(v1);
	push_char(v1);
	acl_free(v1);
	return 1;
}

/**
 * Downshift a string.
 *
 * The origin string is getted from the stack.
 *
 * The string downshifted is returned by the stack.
 *
 * @param The number of parameters
 * @return Allways 1
 */
int
aclfgl_downshift(int _np)
{
char *v1;
	if (_np!=1) { fgl_error(-3000,"",0,0);}
	/* char_pop(v1); */
	v1=char_pop();
	/* convupper(v1); */
	convlower(v1);
	push_char(v1);
	acl_free(v1);
	return 1;
}

/**
 * Upshift a string
 *
 * @param s The string to be converted.
 */
void
convupper(char *s)
{
int a;
	for (a=0;s[a];a++) {
	    s[a]=toupper(s[a]);
	}
}

/**
 * Downshift a string
 *
 * @param s The string to be converted.
 */
void
convlower(char *s)
{
int a;
	for (a=0;s[a];a++) {
	    s[a]=tolower(s[a]);
	}

}

/**
 * Get the integer key value from a string.
 *
 * @param v The string key representation.
 * @return The integer key representation.
 */
int 
net_keyval(char *v)
{
char v0[800];
long _r;
	
	debug("In net_keyval");
	strcpy(v0,v);
	trim(v);
	stripnl(v);
	debug("Decoding ...%s...",v0);
	if (strlen(v0)==1) {return v0[0];}
	if (strcmp(v0,"INTERRUPT")==0) {return (-1);}
	if (strcmp(v0,"ACCEPT")==0) {return(-2);}
	if (strcmp(v0,"LEFT")==0) return A4GLKEY_LEFT;
	if (strcmp(v0,"RIGHT")==0) return A4GLKEY_RIGHT;
	if (strcmp(v0,"UP")==0) return A4GLKEY_UP;
	if (strcmp(v0,"DOWN")==0) return A4GLKEY_DOWN;
	if (strcmp(v0,"PGUP")==0) return A4GLKEY_PGUP;
	if (strcmp(v0,"PGDN")==0) return A4GLKEY_PGDN;
	if (strcmp(v0,"INS")==0) return A4GLKEY_INS;
	if (strcmp(v0,"DEL")==0) return A4GLKEY_DEL;
	if (strcmp(v0,"BACKSPACE")==0) return 8;
	if (strcmp(v0,"RETURN")==0) return CR;
	if (strcmp(v0,"TAB")==0) return 9;
	if (strcmp(v0,"HOME")==0) return A4GLKEY_HOME;
	if (strcmp(v0,"END")==0) return A4GLKEY_END;
	if (strcmp(v0,"ESCAPE")==0) return 27;

	if (v0[0]=='F') {
        	_r=atoi(&v0[1]);
        	return(A4GLKEY_F(_r));
        	}
	
	if (v0[0]=='^') {return(v0[1]-'A'+1);}
	debug("Not found in here");
return 0;
}

/**
 *
 * @todo Describe function
 */
int
get_lastkey (void)
{
  return m_lastkey;
}


/**
 *
 * @todo Describe function
 */
void
set_last_key (int a)
{
  m_lastkey = a;
}


/**
 *
 * @todo Describe function
 */
char *
strip_quotes (char *s)
{
  static char buff[1024];
  if (s[0] == '"' || s[0] == '\'')
    {
      strcpy (buff, &s[1]);
      buff[strlen (buff) - 1] = 0;
    }
  else
    {
      strcpy (buff, s);
    }
  debug ("Returning %s", buff);
  return buff;
}


/**
 *
 * @todo Describe function
 */
char *
replace_sql_var (char *s)
{
  static char buff[1024];
  char *ptr;
  if (s[0] != '\n')
    {
      return s;
    }
  strcpy (buff, &s[1]);

  if (strcmp (buff, "today") == 0)
    {
      push_today ();
      ptr = char_pop ();
      strcpy (buff, ptr);
      acl_free (ptr);
    }
  if (strcmp (buff, "user") == 0)
    {
      push_user ();
      ptr = char_pop ();
      strcpy (buff, ptr);
      acl_free (ptr);
    }
  debug ("replace_sql_var :Returning %s", buff);
  return buff;

}




/**
 *
 * @todo Describe function
 */
int
attr_name_match (struct struct_scr_field * field, char *s)
{
  char colname[40];
  char tabname[40];
  int aa;
  int ab;
  /*
  debug ("Field : %p\n", field);
  debug ("attr_name_match : %s", s);
  */

  bname (s, tabname, colname);

  /*
  debug ("Splits to %s & %s", tabname, colname);
  debug ("field is [%s %s]", field->tabname, field->colname);
  */

  aa = strcmp (field->tabname, tabname);
  ab = strcmp (field->colname, colname);
  /* debug ("Matches = %d %d ", aa, ab); */
  if ((ab == 0) || (colname[0] == '*'))
    {
      debug ("Match on *");
      return 1;
    }
  if (ab == 0 && tabname[0] == 0)
    {
      debug ("Matched");
      return 1;
    }
  /*
  debug ("Not matched (%s!=%s or %s!=%s)", field->tabname, tabname,
	field->colname, colname);
    */
  return 0;
}



/**
 *
 * @todo Describe function
 */
char *
get_str_attribute (struct struct_scr_field *f, int str)
{
  int a;

  if (!has_str_attribute (f, str))
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
find_srec (struct_form * fd, char *name)
{
  int a;

	debug("No of records : %d",fd->records.records_len);

  for (a = 0; a < fd->records.records_len; a++)
    {
      if (strcasecmp (name, fd->records.records_val[a].name) == 0)
	return a;
    }
  return -1;
}



/**
 *
 * @todo Describe function
 */
int
has_str_attribute (struct struct_scr_field * f, int str)
{
  int a;
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
char_val (char *s)
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


/** Moved from readforms.c
 *
 *
 */
struct struct_screen_record *
get_srec (char *name)
{
  int a;
  struct s_form_dets *form;
  debug ("Get_srec");
  form = get_curr_form ();
  debug ("found form");

  debug ("Got form %p", form);

  if (form == 0)
    {
      debug ("No form...");
      return (struct struct_screen_record *) 0;
    }

  debug ("fileform=%p name=%p(%s)", form->fileform, name, name);

  a = find_srec (form->fileform, name);
  debug ("Got %d", a);
  if (a == -1)
    return (struct struct_screen_record *) 0;
  else
    return (struct struct_screen_record *) &form->fileform->
      records.records_val[a];
}

/* ============================== EOF ========================== */


