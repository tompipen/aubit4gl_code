/**
 * @file
 * Other 4gl internal functions implementation.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

#include "../libincl/dbform.h"
#include "../libincl/debug.h"
#include "../libincl/keys.h"

int m_lastkey = 0;
char *strip_quotes (char *s);

/**
 * Get the laskey typed by the user.
 *
 * Return the values by the stack.
 *
 * @param _np Number of parameters passed by stack. Should be zero. If not
 * give an error.
 */
int aclfgl_fgl_lastkey(int _np) 
{
  long _r;
  if (_np!=0) { fgl_error(-3000,"");}
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
int aclfgl_fgl_keyval(int _np) 
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
int fgl_keyval(int _np) 
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
int aclfgl_upshift(int _np) {
char *v1;
if (_np!=1) { fgl_error(-3000,"");}
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
int aclfgl_downshift(int _np) {
char *v1;
if (_np!=1) { fgl_error(-3000,"");}
//char_pop(v1);
v1=char_pop();
//convupper(v1);
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
convupper(char *s) {
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
convlower(char *s) {
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
int net_keyval(char *v) 
{
char v0[80];
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

get_lastkey ()
{
  return m_lastkey;
}


void
set_last_key (int a)
{
  m_lastkey = a;
}


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


