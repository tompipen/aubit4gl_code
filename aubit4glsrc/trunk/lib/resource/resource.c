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
# $Id: resource.c,v 1.59 2004-01-16 16:35:43 mikeaubury Exp $
#
*/

/**
 * @file
 * Defined default settings for configuration variables, and functionality needed
 * to read configuration setting from configuration file(s) like "aubitrc"
 *
 * @todo Add Doxygen A4GL_comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

	/*
	   This is only source code file in which we should allowe getenv() function
	   call. Everywhere else, we should use acl_getenv. To allow use of getenv,
	   we will define this two variables:
	 */
#define GETENV_OK
#define WGETENV_OK
#define _NO_FORM_X_H_
#include "a4gl_libaubit4gl_int.h"
#include <ctype.h>


/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define RES_MAX 2000

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

#ifdef __MINGW32__
HKEY newkey = 0;		//not sure if this is correct!!!
#endif

struct str_resource *user_resource = 0;
int loaded_resources = 0;
struct str_resource *build_resource = 0;
int build_resource_cnt = 0;

struct str_resource builtin_resource[] = {

  /* Loadable modules/library configuration */
#if (defined (__MINGW32__) || defined (__CYGWIN__))
  {"A4GL_SQLTYPE", "odbc32"},
#else
  {"A4GL_SQLTYPE", "nosql"},
#endif
  {"RM_COMMENTS_FIRST","Y"},
  {"A4GL_UPSCOL_ATT","syscolatt"},
  {"A4GL_UPSCOL_VAL","syscolval"},
  {"A4GL_UI", "TUI"}, 			//should this be CONSOLE ?
  {"A4GL_FORMTYPE", "GENERIC"},
  {"A4GL_PACKER", "XML"},       //should this be PACKED?
  {"A4GL_PDFTYPE", "NOPDF"},	/* libEXREPORT_xxxx */
  {"A4GL_LEXTYPE", "C"},
  {"A4GL_LEXDIALECT", "INFORMIX"}, // If they set LEXTYPE TO EC - this is the default
  {"A4GL_RPCTYPE", "NORPC"},
  {"A4GL_MENUTYPE", "NOMENU"},
  {"A4GL_MSGTYPE", "NATIVE"},
  {"A4GL_HELPTYPE", "std"},
  {"EXDTYPE", ""},
//  {"AUBITDIR",                        "@aubitdir@  we should try setting AUBITDIR relative to 
//location of invoked executable, if not already set

  /*
     INCLINES Adds originating line number of each created target language statemtn
     coresponding to 4gl source code, to created target language source code,
     which is usefull for debugging. Like:
     #line 2 "../tools/test/test_build.4gl"
     It can increase compile time significantly, so the default should be "no"
   */
  {"INCLINES", "no"},		///"yes" or "no"
#if (defined (__MINGW32__))
//FIXME: do not hard-code D:/cygwin
  {"AUBITETC", "D:/cygwin/etc/opt/aubit4gl"},	/* points to default location of Aubit config files */
  {"A4GL_MV_CMD", "move"},
#else
  {"AUBITETC", "/etc/opt/aubit4gl"},	/* points to default location of Aubit config files */
  {"A4GL_MV_CMD", "mv"},
#endif
  {"A4GL_RESERVEWORDS", "NO"},
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
  {"ACL_MOUSE", "N"},
  {"AUBIT_Y2K", "70"},

  {"MAP4GL", "N"},
  {"SCROLLBACKTO1","Y"}, // Allow Display Array to move back to srec[1] when scr_line>1
  {"LOGNAME", "UNKNOWN"},
  {"NOCLOBBER", "N"},
#ifdef WIN32
  {"EXTENDED_FETCH", "Y"},
#else
  {"EXTENDED_FETCH", "Y"},	/* This won't always work ! */
#endif
  {"BEEPONERROR","Y"},
  {"HELPTEXT", "Help"},
  {"ERROR_MSG", "Press Any Key"},
  {"PAUSE_MSG", "Press Any Key"},
  {"FIELD_ERROR_MSG", " Error in field "},
  {"FIELD_INCL_MSG", " This value is not among the valid possibilties "},
  {"FIELD_REQD_MSG", " This field required an entered value "},
  {"FIELD_CONSTR_EXPR", " Error in expression "},
  {"FIELD_PICTURE_MSG", " You cannot use this editing feature because a picture exists "},
  {"ARR_DIR_MSG",	" There are no more rows in the direction you are going "},
  {"INPARRAY_FULL_MSG"," Cannot insert another row - the input array is full "},

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

  /* default lines */
  {"_FORMLINE", "3"},
  {"_MENULINE", "1"},
  {"_PROMPTLINE", "1"},
  {"_ERRORLINE", "-1"},
  {"_MESSAGELINE", "-2"},
  {"_COMMENTLINE", "-2"},
  {"FIRSTCOL_ONERR","Y"},

#ifndef WIN32
  {"COLOR_TUI_BLACK","0"},
  {"COLOR_TUI_RED","1"},
  {"COLOR_TUI_GREEN","2"},
  {"COLOR_TUI_YELLOW","3"},
  {"COLOR_TUI_BLUE","4"},
  {"COLOR_TUI_MAGENTA","5"},
  {"COLOR_TUI_CYAN","6"},
  {"COLOR_TUI_WHITE","7"},

#else
  {"COLOR_TUI_BLACK","0"},
  {"COLOR_TUI_BLUE","1"},
  {"COLOR_TUI_GREEN","2"},
  {"COLOR_TUI_CYAN","3"},
  {"COLOR_TUI_RED","4"},
  {"COLOR_TUI_MAGENTA","5"},
  {"COLOR_TUI_YELLOW","6"},
  {"COLOR_TUI_WHITE","7"},
#endif


  {"COLOR_TUI_BKG_DEF","-1"},
  {"COLOR_TUI_BKG","0"},
  {"COLOR_TUI_FG_DEF","-1"},
  {"COLOR_TUI_FG","7"},
  {"NO_INVIS_ATTR","Y"}, // Don't Apply invisible attribute - rely on invisible option in fields
			 // Setting to N will mess up TERM=SCOANSI and doesn't seem to 
			// matter otherwise...
  /* all platforms Compilation options */
  {"A4GL_LINK_LIBS", "-laubit4gl"},
  {"A4GL_C_COMP", "gcc"},
  {"A4GL_RDYNAMIC", "-rdynamic"},

  /* 
     extensions used when invoking C compiler from 4glc
     This is what Amake rules expect - so don't go changing this from here
     or you will break amake - use a4glrc file, or environment instad.
     If you use environment, you can at the same time override extension
     specified in a4gl.mk, or you can even use aubit-config program to read
     then from aubitrc directly inside a4gl.mk
   */
										// counterpart source file extensions:
  {"A4GL_MNU_BASE_EXT", ".mnu"},				// .menu
  {"A4GL_HLP_EXT", ".hlp"},				// .msg

/* form files (source:.per) */
  {"A4GL_FRM_BASE_EXT", ".afr"},
  
/* packer extension (added to form/menu files) */
  {"A4GL_XML_EXT", ".xml"},
  {"A4GL_PACKED_EXT", ".dat"},

/* compiled objects (source:.c/.ec/.4gl) */
  {"A4GL_OBJ_EXT", ".ao"},			// static object
  {"A4GL_LIB_EXT", ".aox"},			// static library
  {"A4GL_SOB_EXT", ".aso"},      	// shared object (pbject compiled with -PIC to be linked in shared library)
//FIXME: do we need distintion between shared object and shared library?
  {"A4GL_SOL_EXT", ".asx"},      	// shared library
  {"A4GL_EXE_EXT", ".4ae"},			// executable

/* This is not needed, since GCC will add .exe/.dll extension automatically on Windows
#if (defined (__CYGWIN__) || defined (__MINGW32__))
  {"A4GL_EXE_EXT", 		".exe"},
  {"A4GL_DLL_EXT", 		".dll"},
#else
*/



  /* can't use del on Windows, does not accept forward slash in the path */
  {"A4GL_RM_CMD", "rm -f"},
  {"A4GL_DEBUG_LEVEL", "10"},
  {"GTK_INC_PATH", ""},		//this ently is to prevent core dumps on Windows when thsi value is not set

  /* End of definitions */
  {"", "0"}
};


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static int has_resource (char *s);
static void add_resources_in (FILE * resourcefile);
static int next_resource (void);
int A4GL_chk_dbdate (char *p);

extern void A4GL_trim_nl (char *p);	/* in aubit-config.c when used to make aubit-config executable. */

static char *chk_str_resource (char *s, struct str_resource *res);
static int add_userptr (void *ptr);
static char *find_str_resource (char *s);
int A4GL_replace_str_resource (char *s, char *neww);
void A4GL_dump_all_resource_vars (int export);

char * A4GL_getenv_registry (char *s,char *prefixed_string);


#if (defined(WIN32) && ! defined(__CYGWIN__))

long get_regkey (char *key, char *data, int n);
int set_regkey (char *key, char *data);
void createkey (void);
void get_anykey (HKEY whence, char *key, char *key2, char *data, int n);
char *get_login (void);

#endif

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 *
 *
 *
 *
 * @param
 */
static char *
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

/**
 *
 *
 *
 *
 * @param
 */
static int
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



/**
 *
 *
 *
 *
 * @param
 */
char *
A4GL_find_str_resource_int (char *search, int a)
{
  char *ptr;
  char s[1024];
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

/**
 *
 *
 *
 *
 * @param
 */
static char *
find_str_resource (char *s)
{
  char *ptr;

#ifdef DEBUG
//  debug("Finding resource %s\n",s);
#endif

  /* look in user resources first */
  ptr = chk_str_resource (s, user_resource);

  if (ptr == 0)
    {
      /* Check built-in resources next */
      ptr = chk_str_resource (s, builtin_resource);
    }

  if (ptr)
    {
#ifdef DEBUG
//      debug("Resurce %s has value of: %s\n",s,ptr);
#endif
      return ptr;
    }
  else
    {
      return 0;
    }
}

/**
 * Get the contents of an resources or environment variable.
 * WARNING - DO NOT USE CALLS TO A4GL_debug() in this function - it will cause endless loop
 * @param s The environment variable name.
 */
char *
acl_getenv (char *s)
{
char prefixed_string[1024];
//WHY was this static?
//static char *ptr;
char *ptr_env=0, *ptr_env_A4GL=0,*ptr_resources=0, *ptr_resources_A4GL=0, *ptr_registry=0, *ptr=0;
int cumulate = 0;
char cumulate_char=0;
char cumulated_string[2048];

//WARNING - strings returned by getenv() are linited to 125 charcters!
//strings defined in aubitrc don't have this limitation.

	cumulated_string[0] = 0;

	if ((strcmp (s, "DBPATH") == 0) || (strcmp (s, "A4GL_DBPATH") == 0) ) {
        /* some variables, like DBPATH need to be cumulated from all available
		sources, otherwise value of higher priority source will overwrite the
        value of lower priority one
        */
        cumulate = 1;
		#if ( (defined (WIN32) || defined (__MINGW32__)) && ! defined (__CYGWIN__))
			cumulate_char=';';
        #else
			cumulate_char=':';
        #endif
    }

    sprintf (prefixed_string, "A4GL_%s", s);

	ptr_env_A4GL = getenv (prefixed_string); /* in environmet, with a prefix */
	ptr_env = (char *) getenv (s); /* in environment, but without the prefix */
	ptr_registry=A4GL_getenv_registry (s,(char *) prefixed_string); /*Windows registry */
	ptr_resources_A4GL = find_str_resource (prefixed_string); 		/* Try in resources */
	ptr_resources = find_str_resource (s); 		/* Try in resources */

    if (cumulate) {
		if (ptr_env_A4GL != 0) {
			sprintf(cumulated_string,"%s",ptr_env_A4GL);
		}
	    if (ptr_env != 0) {
			sprintf(cumulated_string,"%s%c%s",cumulated_string,cumulate_char,ptr_env);
		}
	    if (ptr_registry != 0) {
			sprintf(cumulated_string,"%s%c%s",cumulated_string,cumulate_char,ptr_registry);
		}
	    if (ptr_resources_A4GL != 0) {
			sprintf(cumulated_string,"%s%c%s",cumulated_string,cumulate_char,ptr_resources_A4GL);
		}
		if (ptr_resources != 0) {
			sprintf(cumulated_string,"%s%c%s",cumulated_string,cumulate_char,ptr_resources);
		}
		if (strlen (cumulated_string) != 0 ){
			ptr=(char *)cumulated_string;
        }
    } else {
		if (ptr_env_A4GL != 0) { ptr=ptr_env_A4GL; }
	    else if (ptr_env != 0) { ptr=ptr_env; }
	    else if (ptr_registry != 0) { ptr=ptr_registry; }
	    else if (ptr_resources_A4GL != 0) { ptr=ptr_resources_A4GL; }
		else if (ptr_resources != 0) { ptr=ptr_resources; }
	}

	if (ptr == 0) {
		return "";
	} else {

    	/* FIXME: make sure that things like AUBITDIR are in appropriate format:
         on Windows, watch out for Cywin relative paths.
         /cygdrive/c/something is OK, but /usr/bin is not (missing drive
		 letter and CygWin path)!
		*/
		if (strcmp (s, "DBDATE") == 0) {
			A4GL_chk_dbdate (ptr);
		}

		return ptr;
    }
}

char *
A4GL_getenv_registry (char *s,char *prefixed_string)
{
char *ptr=0;
	#if ( (defined (WIN32) || defined (__MINGW32__)) && ! defined (__CYGWIN__))
      /* try in Windows registry 
        Works only with native Windows port, since I don't think CygWin
        provides RegQueryValueEx function... (?)

	  */
      /* why was this static? */
      //static char buff[1024];
      char buff[1024];
		if (get_regkey (s, buff, 1023)) {
			//ptr = (char *)buff;
			ptr = buff;
        } else {
			if (get_regkey (prefixed_string, buff, 1023)) {
				//ptr = (char *)buff;
				ptr = buff;
			}
        }
	#endif

	return ptr;
}

/**
 * Checks format of DBDATE resource.
 *
 * @param p The DBDATE variable string.
 */
int
A4GL_chk_dbdate (char *p)
{
  int d, m, y;
  int cnt;
  d = -1;
  m = -1;
  y = -1;

  if (p == 0)
    {
      A4GL_exitwith ("Invalid DBDATE format(1)");
      return 0;
    }

  for (cnt = 0; cnt <= 3; cnt++)
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
      A4GL_exitwith ("Invalid DBDATE format(2)");
      return 0;
    }

  /* not correct :  eg. "Y4MD-" is valid */
  //  if (strlen (p) > 3)
  //    {
  //      if (p[3] != '2' && p[3] != '4')
  //        {
  //          A4GL_exitwith ("Invalid DBDATE format(3)");
  //          return 0;
  //        }
  //    }

  return 0;
}

/**
 *
 *
 *
 *
 * @param
 */
int
A4GL_replace_str_resource (char *s, char *neww)
{
  void *ptr;
  /* use with care ! */
  ptr = chk_str_resource (s, builtin_resource);
  if (ptr)
    strcpy (ptr, neww);
  return 0;
}




/* the following are all win32 specific.... */
#if (defined(WIN32) && ! defined(__CYGWIN__))

/**
 *  set a value in the registry
 *	   Eg.
 *	   set_regkey("User","maubu");
 *	   set_regkey("Password","password");
 *	   set_regkey("Host","sisco");
 *
 *
 *
 *
 * @param
 */
int
set_regkey (char *key, char *data)
{
  LONG a;
  if (newkey == 0)
    createkey ();
  a = RegSetValueEx (newkey, key, 0, REG_SZ, data, strlen (data));
  return (a == 0);
}


/**
 * get a value from the registry
 * key : name of the value to query
 * data: Pointer to a buffer that receives the value's data
 * n: Pointer to a variable that specifies the size of the buffer pointed to by the Data parameter, in bytes
 *
 * @param
 */
long
get_regkey (char *key, char *data, int n)
{
  LONG a;
  DWORD l;
  /*

     WARNING!!!!

     DO __NOT__ call debug() from this function - it will cause loop when looking for
     value of DEBUG variable - and eventually core A4GL_dump !!!!

     #ifdef DEBUG
     debug("serching Windows registry for %s",key);
     #endif
   */

  l = REG_SZ;			//type of registry data - string
  if (newkey == 0)
    {
      createkey ();
    }

  // The RegQueryValueEx function retrieves the type and data for a specified value name
  // associated with an open registry key.
  a = RegQueryValueEx (newkey, key, 0, &l, data, &n);
  return (a == 0);
}

/**
 * helper program to generate the registry key
 *
 *
 *
 * @param
 */
void
createkey (void)
{
  LONG a;
  DWORD disp;
  //printf("In createkey\n");
  a = RegCreateKeyEx (HKEY_LOCAL_MACHINE,
		      /* user will need Administrator privilege to write in HKLM, maybe we should
		         use HKCU instead ? */
		      "Software\\Aubit project\\Aubit 4GL compiler",
		      0,
		      "AclClass",
		      REG_OPTION_NON_VOLATILE,
		      KEY_ALL_ACCESS, NULL, &newkey, &disp);
}


/**
 * get any key value from registry
 * See http://msdn.microsoft.com/library/default.asp?url=/library/en-us/sysinfo/base/regqueryvalueex.asp
 *
 *
 * @param
 */
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



/**
 * get the NT logon username
 *
 *
 *
 * @param
 */
char *
get_login (void)
{
  static char buff[1024] = "";
  get_anykey (HKEY_LOCAL_MACHINE, "Network\\Logon", "username", buff, 255);
  return buff;
}

#endif /* WIN32 */


/**
 * Finds config fire(s) with user resources (configuration settings)
 * and invokes parser/loader
 */
struct str_resource *
A4GL_build_user_resources (void)
{
  char buff[1024];
  int a;
  FILE *resourcefile = 0;

#ifdef DEBUG
  A4GL_debug ("Loading resources");
#endif

  if (loaded_resources)
    return build_resource;
  if (build_resource)
    free (build_resource);

  /* ----------------- from /etc/opt/aubit4gl/aubitrc 
     On Windows, this will work only if there is CygWin installed
   */

  sprintf (buff, "%s/%s", acl_getenv ("AUBITETC"), "aubitrc");
  resourcefile = fopen (buff, "r");
  if (resourcefile != 0)
    {
#ifdef DEBUG
      A4GL_debug ("1:From %s", buff);
#endif
      add_resources_in (resourcefile);
      fclose (resourcefile);
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("1:cannot read %s", buff);
#endif
    };

  /* -----------------  from $AUBITDIR/etc/aubitrc */

  /*
     AUBITDIR on Windows, when using CygWin tools to compile MingWin native
     compiler will be UNIX style, and point to CygWin installation (and will not
     start with drive leter, etc.)

     Since environment variables override configuration file settings when 
     calling aclfgl_getenv(), this will give us AUBITDIR that is unreachable
     from native Windows executables, that know nothing about CygWin path mapping

     As one of the consequences, the following statement will fail to find
     aubitrc configuration file in AUBITDIR specified in this manner, because it
     will try to open file

     /something/aubitrc

     but file is actually

     X:/cygwin/something/aubitrc

   */

  sprintf (buff, "%s/etc/%s", acl_getenv ("AUBITDIR"), "aubitrc");
  resourcefile = fopen (buff, "r");
  if (resourcefile != 0)
    {
#ifdef DEBUG
      A4GL_debug ("2:From %s", buff);
#endif
      add_resources_in (resourcefile);
      fclose (resourcefile);
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("2:cannot read %s", buff);
#endif
    };


  /* -----------------  from ~/.aubit4gl/aubitrc */

  sprintf (buff, "%s/.aubit4gl/%s", acl_getenv ("HOME"), "aubitrc");
  resourcefile = fopen (buff, "r");
  if (resourcefile != 0)
    {
#ifdef DEBUG
      A4GL_debug ("From %s", buff);
#endif
      add_resources_in (resourcefile);
      fclose (resourcefile);
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("cannot read %s", buff);
#endif
    };

  /* -----------------  from ~/aubitrc */

  //Whooops: ~ works on shell command line, not from here!
  //debug("From ~/aubitrc");
  //sprintf(buff,"~/%s","aubitrc");
  sprintf (buff, "%s/%s", acl_getenv ("HOME"), "aubitrc");
  resourcefile = fopen (buff, "r");
  if (resourcefile != 0)
    {
#ifdef DEBUG
      A4GL_debug ("From %s", buff);
#endif
      add_resources_in (resourcefile);
      fclose (resourcefile);
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("cannot read %s", buff);
#endif
    };

  /* ----------------- from ./.aubtirc */

  sprintf (buff, "./%s", ".aubitrc");
  resourcefile = fopen (buff, "r");
  if (resourcefile != 0)
    {
#ifdef DEBUG
      A4GL_debug ("From %s", buff);
#endif
      add_resources_in (resourcefile);
      fclose (resourcefile);
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("cannot read %s", buff);
#endif
    };

  /* ----------------- from $A4GL_INIFILE */

  sprintf (buff, "%s", acl_getenv ("A4GL_INIFILE"));
  if (strlen (buff))
    {
      resourcefile = fopen (buff, "r");
      if (resourcefile != 0)
	{
#ifdef DEBUG
	  A4GL_debug ("From %s", buff);
#endif
	  add_resources_in (resourcefile);
	  fclose (resourcefile);
	}
      else
	{
#ifdef DEBUG
	  A4GL_debug ("cannot read %s", buff);
#endif
	};
    }

  if (build_resource_cnt)
    {
#ifdef DEBUG
      A4GL_debug ("User resources");
#endif
      for (a = 0; a < build_resource_cnt; a++)
	{
#ifdef DEBUG
	  A4GL_debug ("%d. %s = %s", a, build_resource[a].name,
		 build_resource[a].value);
#endif
	}

    }

  add_userptr (build_resource);
#ifdef DEBUG
  A4GL_debug ("Finished reading configuration");
#endif
  return build_resource;
}

/**
 * parse config (rc) file and load values into user resources
 *
 *
 *
 * @param
 */
static void
add_resources_in (FILE * resourcefile)
{
  char buff[1024];
  char *ptr;
  int a;
  rewind (resourcefile);
  while (1)
    {
      fgets (buff, 511, resourcefile);
      if (feof (resourcefile))
	break;
      ptr = strchr (buff, '#');
      if (ptr)
	{
	  *ptr = 0;
	}
      A4GL_trim_nl (buff);
      ptr = strchr (buff, '=');
      if (ptr)
	{
	  *ptr = 0;
	  ptr++;
	  A4GL_trim_nl (buff);
	  A4GL_trim_nl (ptr);
	  a = has_resource (buff);
	  if (a != -1)
	    {			/* overwrite an existing entry */
	      strcpy (build_resource[a].value, ptr);
	    }
	  else
	    {
	      a = next_resource ();
	      strcpy (build_resource[a].name, buff);
	      strcpy (build_resource[a].value, ptr);
	    }
	}
    }
}


/**
 *
 *
 *
 *
 * @param
 */
static int
next_resource (void)
{
  build_resource_cnt++;
  build_resource =
    realloc (build_resource,
	     (build_resource_cnt + 1) * sizeof (struct str_resource));
  build_resource[build_resource_cnt].name[0] = 0;
  build_resource[build_resource_cnt].value[0] = 0;

  return build_resource_cnt - 1;
}

/**
 *
 *
 *
 *
 * @param
 */
static int
has_resource (char *s)
{
  int a;
  if (build_resource_cnt)
    {
      for (a = 0; a < build_resource_cnt; a++)
	{
	  if (strcmp (build_resource[a].name, s) == 0)
	    {
	      return a;
	    }
	}
    }
  return -1;
}


/**
 *
 *
 *
 *
 * @param
 */
void
A4GL_dump_all_resource_vars (int export)
{
  struct str_resource *res;
  int a;

  res = builtin_resource;
  if (!export)
    printf ("Built-in resources:\n");
  for (a = 0; strlen (res[a].name) != 0; a++)
    {
      if (!export)
	printf ("  %s=%s\n", res[a].name, res[a].value);
      else
	{
	  if (getenv (res[a].name))
	    printf ("export %s='%s'\n", res[a].name,
		    acl_getenv (res[a].name));
	}
    }

  res = user_resource;

  if (res)
    {
      if (!export)
	printf ("User resources :\n");
      for (a = 0; strlen (res[a].name) != 0; a++)
	{
	  if (!export)
	    printf ("  %s=%s\n", res[a].name, res[a].value);
	  else
	    {
	      if (getenv (res[a].name))
		{
		  printf ("export %s='%s'\n", res[a].name,
			  acl_getenv (res[a].name));
		}
	    }
	}
    }

}





/**
 *
 *
 *
 *
 * @param
 */
int
A4GL_env_option_set (char *s)
{
  char *a;
  a = acl_getenv (s);
  if (a == 0)
    a = "";
  if (strcmp (s, "") == 0)
    return 0;
  if (a[0] == 'Y' || a[0] == 'y')
    return 1;
  return 0;
}



/* ----------------------------- EOF --------------------------------- */
