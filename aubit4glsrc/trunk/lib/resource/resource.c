/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0   root makefile              |
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
# $Id: resource.c,v 1.3 2002-05-11 08:31:21 mikeaubury Exp $
#
*/

/**
 * @file
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

#define RES_MAX 2000
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
This is only source code file in which we should allowe getenv() function
call. Everywhere else, we should use acl_getenv. To allow use of getenv,
we will define this two variables:
*/
#define GETENV_OK
#define WGETENV_OK
#include "a4gl_debug.h"


struct str_resource
  {
    char name[20];
    char value[127];
  };

struct str_resource *user_resource = 0;

int loaded_resources=0;
struct str_resource *build_resource=0;
int build_resource_cnt=0;
static int has_resource(char *s) ;
static void add_resources_in(FILE *resourcefile) ;
static int next_resource();

struct str_resource builtin_resource[] =
{
/* defaults for environment */
  {"AUBITGUI",    "text"},
  {"ACL_MOUSE",   "N"},
  {"A4GL_SQLTYPE", "nosql"},
  {"NOCURSES", "N"},            //FIXME: NOCURSES is now AUBITGUI=CONSOLE
  {"GUIPORT", ""},
  {"A4GL_LEXTYPE","C"},
  {"DBDATE", "MDY4/"},
  {"DBANSIWARN", "N"},
  {"DBBLOBBUF", "64"},
  {"DBCENTURY", "C"},
  {"DBDELIMITER", "|"},
  {"DBEDIT", "vi"},
  {"DBFLTMASK", "2"},
  {"DBLANG", "<ACLDIR>"},
  {"DBMONEY", "#."},
  {"DBPATH", "."},
  {"DBPRINT", "lp"},
  {"ACLCCOMP", "cc"},
  {"AUBIT_Y2K", "70"},
  {"MAP4GL", "N"},
  {"LOGNAME", "UNKNOWN"},
  {"NOCLOBBER","N"},
#ifdef WIN32
  {"EXTENDED_FETCH", "Y"},
#else
  {"EXTENDED_FETCH", "Y"}, // This won't always work !
#endif
  {"ACLDIR", "/usr/acl"},
  {"ACLTEMP", "tempdsn"},
  {"HELPTEXT", "Help"},
  {"ERROR_MSG", "Press Any Key"},
  {"PAUSE_MSG", "Press Any Key"},
  {"FIELD_ERROR_MSG","Error in field"},
 
  {"MENUCSELECT", "0"},
  {"MENUCTITLE", "0"},
  {"MENUCNORMAL", "0"},
  {"MENUCHIGHLIGHT", "<>"},
 
  {"MENUMSELECT", "0"},
  {"MENUMTITLE", "0"},
  {"MENUMNORMAL", "0"},
  {"MENUMHIGHLIGHT", "<>"},
 
/* abbr week days */
  {"_DAY0", "Sun"},
  {"_DAY1", "Mon"},
  {"_DAY2", "Tue"},
  {"_DAY3", "Wed"},
  {"_DAY4", "Thu"},
  {"_DAY5", "Fri"},
  {"_DAY6", "Sat"},
 
/* full week days */
  {"_FDAY0", "Sunday"},
  {"_FDAY1", "Monday"},
  {"_FDAY2", "Tuesday"},
  {"_FDAY3", "Wednesday"},
  {"_FDAY4", "Thursday"},
  {"_FDAY5", "Friday"},
  {"_FDAY6", "Saturday"},
 
/* abbr months */
  {"_MON1", "Jan"},
  {"_MON2", "Feb"},
  {"_MON3", "Mar"},
  {"_MON4", "Apr"},
  {"_MON5", "May"},
  {"_MON6", "Jun"},
  {"_MON7", "Jul"},
  {"_MON8", "Aug"},
  {"_MON9", "Sep"},
  {"_MON10", "Oct"},
  {"_MON11", "Nov"},
  {"_MON12", "Dec"},
 
/* Full months */
  {"_FMON1", "January"},
  {"_FMON2", "February"},
  {"_FMON3", "March"},
  {"_FMON4", "April"},
  {"_FMON5", "May"},
  {"_FMON6", "June"},
  {"_FMON7", "July"},
  {"_FMON8", "August"},
  {"_FMON9", "September"},
  {"_FMON10", "October"},
  {"_FMON11", "November"},
  {"_FMON12", "December"},
 
/* addition for days */
  {"_DAYTH1", "st"},
  {"_DAYTH2", "nd"},
  {"_DAYTH3", "rd"},
  {"_DAYTH4", "th"},
  {"_DAYTH5", "th"},
  {"_DAYTH6", "th"},
  {"_DAYTH7", "th"},
  {"_DAYTH8", "th"},
  {"_DAYTH9", "th"},
  {"_DAYTH10", "th"},
  {"_DAYTH11", "th"},
  {"_DAYTH12", "th"},
  {"_DAYTH13", "th"},
  {"_DAYTH14", "th"},
  {"_DAYTH15", "th"},
  {"_DAYTH16", "th"},
  {"_DAYTH17", "th"},
  {"_DAYTH18", "th"},
  {"_DAYTH19", "th"},
  {"_DAYTH20", "th"},
  {"_DAYTH21", "st"},
  {"_DAYTH22", "nd"},
  {"_DAYTH23", "rd"},
  {"_DAYTH24", "th"},
  {"_DAYTH25", "th"},
  {"_DAYTH26", "th"},
  {"_DAYTH27", "th"},
  {"_DAYTH28", "th"},
  {"_DAYTH29", "th"},
  {"_DAYTH30", "th"},
  {"_DAYTH31", "st"},
/* default lines... */
  {"_FORMLINE", "3"},
  {"_MENULINE", "1"},
  {"_PROMPTLINE", "1"},
  {"_ERRORLINE", "-1"},
  {"_MESSAGELINE", "-2"},
  {"_COMMENTLINE", "-2"},
 
/* WINDOWS Compilation options */
  {"W32LIBSDIR", "-L/acl/lib"},
  {"W32LIBS", "-lpdcurs -lgdi32 -luser32 -lwsock32"},
  {"W32FGLLIBSDIR", "-L/acl/lib"},
  {"W32FGLLIBS_SHARED", "-laclshared -lm"},
  {"W32ODBC", "-lodbc32 -lodbccp32"},
  {"W32FGLLIBS", "-laclall -lm"},
  {"W32INCLDIR", "-I/acl/incl"},
  {"W32GCC", "gcc -s -O"},
 
/* End of definitions */
  {"", 0}
};  


char *
chk_str_resource (char *s, struct str_resource *res)
{
  register int a;
 
  if (res == 0)
    {
      return 0;
    }
 
  for (a = 0; strlen (res[a].name) != 0; a++)
    {
      if (strcmp (res[a].name, s) == 0)
        {

          return res[a].value;
        }
    }
  return 0;
}

int
add_userptr (void *ptr)
{
  user_resource = ptr;
  return 0;
}




/**
 * Gets an environment variable.
 *
 * No more needed because cygwin implements getenv.
 *
 * @param s The environment variable name
 */
/*
static char *wgetenv (char *s)
{

  return getenv (s);

}
*/



char *find_str_resource_int (char *search, int a)
{
  char *ptr;
  char s[256];
  sprintf (s, "%s%d", search, a);
  /* look in user resources first */
  ptr = chk_str_resource (s, user_resource);
  if (ptr)
    return ptr;
  /* Check built-in resources next */
  ptr = chk_str_resource (s, builtin_resource);
  if (ptr)
    return ptr;
  return 0;
}
 
char *find_str_resource (char *s)
{
  char *ptr;
  /* look in user resources first */
  ptr = chk_str_resource (s, user_resource);

  if (ptr)
    return ptr;
  /* Check built-in resources next */

  ptr = chk_str_resource (s, builtin_resource);
  if (ptr)
    return ptr;
  return 0;
}

/**
 * Get the contents of an evironment variable.
 *
 * @param s The environment variable name.
 */
char *acl_getenv (char *s)
{
  static char undef[] = "Undefined";
  char prefixed_string[256];
  char *ptr;


  sprintf(prefixed_string,"A4GL_%s",s);
  ptr = getenv (prefixed_string);

  if (ptr==0) 
  	ptr = (char *)getenv (s);

  if (ptr == 0 ) {
    	ptr = find_str_resource (s);
  }

  if (strcmp (s, "DBDATE") == 0)
  {
    chk_dbdate (ptr);
  }

  if (ptr==0) return "";

  return ptr;
}

/**
 * Checks format of DBDATE resource.
 *
 * @param p The DBDATE variable string.
 */
chk_dbdate (char *p)
{
  int d, m, y, del, ysize;
  int cnt;
  d = -1;
  m = -1;
  y = -1;

  if (p == 0)
    {
      exitwith ("Invalid DBDATE format(1)");
      return 0;
    }

  for (cnt = 0; cnt <= 2; cnt++)
    {
      if (toupper (p[cnt]) == 'Y')
        y = cnt;
      if (toupper (p[cnt]) == 'M')
        m = cnt;
      if (toupper (p[cnt]) == 'D')
        d = cnt;
    }

  if (y == -1 || d == -1 || m == -1)
    {
      exitwith ("Invalid DBDATE format(2)");
      return 0;
    }


  if (strlen (p) > 3)
    {
      if (p[3] != '2' && p[3] != '4')
        {
          exitwith ("Invalid DBDATE format(3)");
          return 0;
        }
    }
}

int
replace_str_resource (char *s, char *neww)
{
  void *ptr;
// use with care !
  ptr = chk_str_resource (s, builtin_resource);
  if (ptr)
    strcpy (ptr, neww);
  return 0;
}




/* the following are all win32 specific.... */
#ifdef WIN32
#ifndef __CYGWIN__


/************************************************************************/
/* set a value in the registry
	   Eg.
	   set_regkey("User","maubu");
	   set_regkey("Password","password");
	   set_regkey("Host","sisco");                                      */
/************************************************************************/

int
set_regkey (char *key, char *data)
{
  LONG a;
  if (newkey == 0)
    createkey ();
  a = RegSetValueEx (newkey, key, 0, REG_SZ, data, strlen (data));
  return (a == 0);
}


/***********************************************************************/
/* get a value from the registry                                       */
/***********************************************************************/
int
get_regkey (char *key, char *data, int n)
{
  LONG a;
  DWORD l;
  l = REG_SZ;
  if (newkey == 0)
    createkey ();
  a = RegQueryValueEx (newkey, key, 0, &l, data, &n);
  return (a == 0);
}

/***********************************************************************/
/* helper program to generate the registry key                         */
/***********************************************************************/
void
createkey ()
{
  LONG a;
  DWORD disp;
  a = RegCreateKeyEx (
		       HKEY_LOCAL_MACHINE, "Software\\Aubit Computing Ltd.\\A4GL", 0, "AclClass", REG_OPTION_NON_VOLATILE, KEY_ALL_ACCESS, NULL, &newkey, &disp);
}


/***********************************************************************/
/* get any key value from registry                                     */
/***********************************************************************/
void
get_anykey (HKEY whence, char *key, char *key2, char *data, int n)
{
  LONG a;
  DWORD l;
  HKEY nkey;
  a = RegOpenKeyEx (whence, key, 0, KEY_ALL_ACCESS, &nkey);
  if (a != ERROR_SUCCESS)
    {
      MessageBox (NULL, "Couldnt open registry entry!", key, 0);
      data[0] = 0;
      return;
    }
  l = REG_SZ;
  a = RegQueryValueEx (nkey, key2, 0, &l, data, &n);
}



/************************************************************************/
/* get the NT logon username                                            */
/************************************************************************/
char *
get_login ()
{
  static char buff[255] = "";
  get_anykey (HKEY_LOCAL_MACHINE, "Network\\Logon", "username", buff, 255);
  return buff;
}
#endif //__CYGWIN__
#endif // WIN32



/**
 * Finds config fire(s) with user resources (configuration settings)
 * and invokes parser/loader
 */
struct str_resource *build_user_resources() {
	char buff[512];
	int a;
	FILE *resourcefile=0;

	debug("Loading resources");

	if (loaded_resources) return build_resource;
	if (build_resource) free(build_resource);

// from /etc/opt/aubit4gl/aubitrc

	debug("From /etc/opt/aubit4gl/aubitrc");

	sprintf(buff,"/etc/opt/aubit4gl/%s","aubitrc");
	resourcefile=fopen(buff,"r");

	if (resourcefile!=0) { add_resources_in(resourcefile); fclose(resourcefile); }

// from $AUBITDIR/etc/aubitrc

	debug("Finding aubitdir from environment");

	sprintf(buff,"%s/etc/%s",acl_getenv("AUBITDIR"),"aubitrc");

	debug("From %s",buff);

	resourcefile=fopen(buff,"r");

	if (resourcefile!=0) { add_resources_in(resourcefile); fclose(resourcefile); }

// from ~/.aubit4gl/aubitrc

	debug("From ~/.aubit4gl/aubitrc");

	sprintf(buff,"~/.aubit4gl/%s","aubitrc");
	resourcefile=fopen(buff,"r");

	if (resourcefile!=0) { add_resources_in(resourcefile); fclose(resourcefile); }


// from ./.aubtirc

	sprintf(buff,"./%s",".aubitrc");

	debug("From %s",buff);

	resourcefile=fopen(buff,"r");
	if (resourcefile!=0) { add_resources_in(resourcefile); fclose(resourcefile); }

// from $A4GL_INIFILE

	debug("Finding INIfile from env");

	sprintf(buff,"%s",acl_getenv("A4GL_INIFILE"));
	if (strlen(buff)) {

		debug("From $A4GL_INIFILE %s",buff);

		resourcefile=fopen(buff,"r");
		if (resourcefile!=0) { add_resources_in(resourcefile); fclose(resourcefile); }
	}

	if (build_resource_cnt) {
		debug("User resources\n --------------");
	for (a=0;a<build_resource_cnt;a++) {
		debug("%d. %s = %s",a, build_resource[a].name, build_resource[a].value);
	}

}

add_userptr (build_resource);
	return build_resource;
}

// parse config (rc) file and load values into user resources
static void add_resources_in(FILE *resourcefile) {
char buff[512];
char *ptr;
int a;
	rewind(resourcefile);
	while (1) {
		fgets(buff,511,resourcefile);
		if (feof(resourcefile)) break;
		ptr=strchr(buff,'#');
		if (ptr) {
			*ptr=0;
		}
		trim_nl(buff);
		ptr=strchr(buff,'=');
		if (ptr) {
			*ptr=0;
			ptr++;
			trim_nl(buff);
			trim_nl(ptr);
			a=has_resource(buff);
			if (a!=-1) { /* overwrite an existing entry */
				strcpy(build_resource[a].value,ptr);
			} else {
				a=next_resource();
				strcpy(build_resource[a].name,buff);
				strcpy(build_resource[a].value,ptr);
			}
		}
	} 
}

 
static int next_resource() {
	build_resource_cnt++;
	build_resource=realloc(build_resource,(build_resource_cnt+1)*sizeof(struct str_resource) );
	build_resource[build_resource_cnt].name[0]=0;
	build_resource[build_resource_cnt].value[0]=0;

	return build_resource_cnt-1;
}

static int has_resource(char *s) {
int a;
	if (build_resource_cnt) {
		for (a=0;a<build_resource_cnt;a++) {
			if (strcmp(build_resource[a].name,s)==0) {
				return a;
			}
		}
	}
	return -1;
}


dump_all_resource_vars() {
struct str_resource *res;
int a;

res=builtin_resource;
printf("Built-in resources:\n");
  for (a = 0; strlen (res[a].name) != 0; a++) {
	printf("  %s=%s\n",res[a].name,res[a].value);
}

res=user_resource;
if (res) {
printf("User resources :\n");
  for (a = 0; strlen (res[a].name) != 0; a++) {
	printf("  %s=%s\n",res[a].name,res[a].value);
}
}

}



env_option_set(char *s) {
char *a;
	a=acl_getenv(s);
	if (a==0) a="";
	if (strcmp(s,"")==0) return 0;
	if (a[0]=='Y'||a[0]=='y') return 1;
	return 0;
}



//----------------------------- EOF ---------------------------------

