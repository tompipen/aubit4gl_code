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
# $Id: resource.c,v 1.129 2006-12-01 22:52:59 mikeaubury Exp $
#
*/

/**
 * @file
 * Defined default settings for configuration variables, and functionality needed
 * to read configuration setting from configuration file(s) like "aubitrc"
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
#include <stdlib.h>


//#define DEBUG_VARIABLE_USAGE

#if (defined (__MINGW32__))
#ifndef _AUBITETC_
#define _AUBITETC_ AUBITETC
#endif
#endif

#ifdef DEBUG_VARIABLE_USAGE
FILE *fd1=0;
#endif
char *debug=0;
char *debug_level=0;

static char * A4GL_strip_quotes_resource (char *s);
static char * acl_getenv_internal (char *s,int rcfiles);
char *an_empty_string="";

#define USE_OPTIMISATION 1

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
  {"A4GL_SQLDIALECT", "INFORMIX"},
  {"RM_COMMENTS_FIRST","Y"},
  {"A4GL_SYSCOL_ATT","syscolatt"},
  {"A4GL_SYSCOL_VAL","syscolval"},
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
  {"ODDOPTIONS", "N"},
  {"EXDTYPE", ""},

#ifdef CONFAUBITDIR
  {"AUBITDIR", CONFAUBITDIR},
#endif
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
  {"AUBITETC", _AUBITETC_},	/* points to default location of Aubit config files as determined by Autoconf in variable @AUBITRC@ */
  {"A4GL_MV_CMD", "ren"},
  {"A4GL_CP_CMD", "copy"},
#else
//TODO: should we use _AUBITETC_ here too? Not all users installing Aubit will have sufficient 
//privileges to install aubitrc under /etc
#ifdef AUBITETC
  {"AUBITETC", AUBITETC},	/* points to default location of Aubit config files */
#else
  {"AUBITETC", "/etc/opt/aubit4gl"},	/* points to default location of Aubit config files */
#endif
  {"A4GL_MV_CMD", "mv"},
  {"A4GL_CP_CMD", "cp"},
#endif
  {"A4GL_RESERVEWORDS", "NO"},
  {"DBDATE", "MDY4/"},
  {"DBANSIWARN", "N"},  // obsolete? we are using A4GL_ANSI_ERROR and A4GL_ANSI_WARN
  {"DBBLOBBUF", "64"},
  {"DBCENTURY", "C"},
  {"DBDELIMITER", "|"},
  {"FORCE_ROLLBACK_AT_EXIT","Y"},
  {"TRANMODE","1"},
#ifdef __WIN32__
  {"DBEDIT", "notepad.exe"},
#else
  {"DBEDIT", "vi"},
#endif
  {"DBFLTMASK", "2"},
  {"DBLANG", "<ACLDIR>"},
  {"DBMONEY", "#."},
  {"DBPATH", "."},
  {"PLATFORM", "DEFAULT"},
  {"A4GL_NO_CONV_ERR","Y"},
  {"DBPRINT", "lp"},
  {"ACLCCOMP", "cc"},
  {"ACL_MOUSE", "N"},
  {"TARGET", CONFIGURED_TARGET},
  {"TARGET_OS", CONFIGURED_TARGET_OS},
  {"AUBIT_Y2K", "70"},
  {"A4GL_MAP4GL", "N"},
  {"SCROLLBACKTO1","Y"}, // Allow Display Array to move back to srec[1] when scr_line>1
  {"LOGNAME", "UNKNOWN"},
  {"A4GL_NOCLOBBER", "Y"},
  {"A4GL_NOSQLCLOBBER", "N"},
  {"EXTENDED_FETCH", "Y"},	/* This won't always work ! */
  {"BEEPONERROR","Y"},
  {"HELPTEXT", "Help"},
  {"USE_INDICATOR", "Y"},
  {"ERROR_MSG", "Press Any Key"},
  {"PAUSE_MSG", "Press Any Key"},
  {"FIELD_ERROR_MSG", " Error in field "},
  {"FIELD_INCL_MSG", " This value is not among the valid possibilities "},
  {"FIELD_REQD_MSG", " This field required an entered value "},
  {"FIELD_CONSTR_EXPR", " Error in expression "},
  {"FIELD_PICTURE_MSG", " You cannot use this editing feature because a picture exists "},
  {"ARR_DIR_MSG",	" There are no more rows in the direction you are going "},
  {"INPARRAY_FULL_MSG"," Cannot insert another row - the input array is full "},
  {"NOSELECTVARWARNING","N"},
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


  {"RESTARTLOG","N"},
  {"DBL2DEC_USING","Y"},
  {"COLOR_TUI_BKG_DEF","-1"},
  {"COLOR_TUI_BKG","0"},
  {"COLOR_TUI_FG_DEF","-1"},
  {"COLOR_TUI_FG","7"},
  {"NO_INVIS_ATTR","Y"}, // Don't Apply invisible attribute - rely on invisible option in fields
			 // Setting to N will mess up TERM=SCOANSI and doesn't seem to 
			// matter otherwise...
  /* all platforms Compilation options */
#ifndef  SIMPLIFIED
  {"A4GL_LINK_LIBS", LINKAUBITLIBFULL},
  {"DEFAULT_PLUGINDIR", PLUGINDIR},
#else
  {"FGLPCSETTINGSDIR",DATADIR},
  {"DEFAULT_PLUGINDIR", AUBITPLUGINDIR},
#endif
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

#if (defined (__CYGWIN__) || defined (__MINGW32__)) // I'd like them anyway
  {"A4GL_EXE_EXT", 		".exe"},
  {"A4GL_DLL_EXT", 		".dll"},
#else
  {"A4GL_EXE_EXT", 		""},
  {"A4GL_DLL_EXT", 		".so"},
#endif


  /* can't use del on Windows, does not accept forward slash in the path */
  {"A4GL_RM_CMD", "rm -f"},
  {"A4GL_DEBUG_LEVEL", "10"},

  /* L10N stuff */
  {"A4GL_DIALOG_OK", "OK"},
  {"A4GL_DIALOG_CANCEL", "Cancel"},
  {"A4GL_DIALOG_ABORT", "Abort"},
  {"A4GL_DIALOG_RETRY", "Retry"},
  {"A4GL_DIALOG_IGNORE", "Ignore"},
  {"A4GL_DIALOG_YES", "Yes"},
  {"A4GL_DIALOG_NO", "No"},
  {"A4GL_DIALOG_ERROR", "Error"},

  /* GUI HL_GTK Stuff */
  {"A4GL_USE_PANGO_ML", "N"}, /* set to Y to use PangoML in Labels */


  /* misc */
  {"GDB_ATTACH", "N"}, /* set to Y to attach debugger after crash */
  {"GDB_EXE", "gdb"},  /* set it to the name of your prefered debugger */
  {"SWAP_SQLCA62", "N"}, /* to get OID after INSERT on unpatched PostgreSQL */
#ifdef POSTGRESDIR
  {"POSTGRESDIR",POSTGRESDIR},
#endif

#ifdef POSTGRESDIR
	#ifdef PG_ESQLC
  		{"PG_ESQLC",PG_ESQLC},
	#else
  		{"PG_ESQLC","ecpg"},
	#endif
	
	#if HAVE_PGSQL_INFORMIX_ESQL_DECIMAL_H
  		{"PG_COPTS","-DUSING_PG_COPTS=1 -DHAVE_PGSQL_INFORMIX_ESQL_DECIMAL_H=1"},
	#else
		#if HAVE_POSTGRESQL_INFORMIX_ESQL_DECIMAL_H
  		{"PG_COPTS","-DUSING_PG_COPTS=1 -DHAVE_POSTGRESQL_INFORMIX_ESQL_DECIMAL_H=1"},
		#else
			#if HAVE_PG_INFORMIX_ESQL_DECIMAL_H
  				{"PG_COPTS","-DUSING_PG_COPTS=1 -DHAVE_PG_INFORMIX_ESQL_DECIMAL_H=1"},
			#else
				#if HAVE_DECIMAL_H
  				{"PG_COPTS","-DUSING_PG_COPTS=1 -DHAVE_DECIMAL_H=1"},
				#endif
			#endif
		#endif
	#endif
#else
  	{"PG_ESQLC","ecpg"},
#endif

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
  int f;

#ifdef DEBUG
//  debug("Finding resource %s\n",s);
#endif
  /* look in user resources first */
  ptr = chk_str_resource (s, user_resource);
 

  if (ptr == 0)
    {
  	f=0;
      /* Check built-in resources next */
      ptr = chk_str_resource (s, builtin_resource);
    } else {
	f=1;
	}

  if (ptr)
    {
#ifdef DEBUG_VARIABLE_USAGE
	if (fd1) fprintf(fd1,"Found resource %s in %s - %s\n",s,f?"user":"builtin",ptr);
#endif



      return ptr;
    }
  else
    {
      return 0;
    }
}


char * acl_getenv (char *s) {
	char *ptr;
	ptr=acl_getenv_internal(s,1);
	return ptr;
}


char * acl_getenv_not_set_as_0 (char *s) {
	char *ptr;
	ptr=acl_getenv_internal(s,1);
	if (ptr==an_empty_string) {
		return 0;
	} else {
		return ptr;
	}
}

char * acl_getenv_only (char *s) {
	return acl_getenv_internal(s,0);
}

/**
 * Get the contents of an resources or environment variable.
 * WARNING - DO NOT USE CALLS TO A4GL_debug() in this function (OR ANY FUNCTIION 
 * CALLED BY THIS FUNCTION - it will cause an endless loop
 * @param s The environment variable name.
 * @param rcfiles Check rc files too
 */
static char * acl_getenv_internal (char *s,int rcfiles)
{
static char prefixed_string[1024];
static char *value_not_set="VALUE_NOT_SET";
char *ptr_env=0, *ptr_env_A4GL=0,*ptr_resources=0, *ptr_resources_A4GL=0, *ptr_registry=0, *ptr=0;
int cumulate = 0;
char cumulate_char=0;
static char cumulated_string[2048]="";
static char cumulated_string_tmp[2048]="";


	if (strcmp(s,"A4GL_VERSION_STRING")==0) {
		SPRINTF2(prefixed_string,"%s_%d",A4GL_internal_version(),A4GL_internal_build());
		return prefixed_string;
	}

#ifdef DEBUG_VARIABLE_USAGE
	if (fd1==0) {
		fd1=fopen("/tmp/acl_getenv","w");
	}
#endif


// We can only use optimization in one case 
// so we're choosing to do it when we can look in
// rc files too...
//
if (rcfiles) { 
#ifdef USE_OPTIMISATION
ptr=(char *)A4GL_find_pointer (s,STR_RESOURCE_VAL);

if (ptr)  {
	if (ptr==value_not_set)  { /* BEFORE you complain - this is RIGHT!
				 I don't want a string comparison - I want to see If this is set
				 to the pointer which is exactly value_not_set.
				 This is done if I couldn't previously find a value for a variables setting
				*/
#ifdef DEBUG_VARIABLE_USAGE
		if (fd1) fprintf(fd1,"%s - CACHED (Not set)\n",s);
#endif
		if (strcmp(s,"AUBITDIR")!=0) return "";
	} else {

#ifdef DEBUG_VARIABLE_USAGE
	if (fd1) fprintf(fd1,"%s - CACHED (%s)\n",s,ptr);
#endif
	return ptr;
	}
}

#endif
}

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

	if (strncmp(s,"A4GL_",5)!=0) { // No point looking for an A4GL_A4GL_...
        	snprintf (prefixed_string, sizeof(prefixed_string), "A4GL_%s", s);
		prefixed_string[1000]=0;
		ptr_env_A4GL = getenv (prefixed_string); /* in environmet, with A4GL_ prefix */
	} else {
		ptr_env_A4GL = 0;
		strcpy(prefixed_string,"");
	}

	ptr_env = getenv (s); /* in environment, but without the prefix */
#ifdef DEBUG_VARIABLE_USAGE
	if (fd1) fprintf(fd1,"%s - Env lookup = %s %s\n",s,
	ptr_env_A4GL?ptr_env_A4GL:"No",
	ptr_env?ptr_env:"No"
);
#endif
        ptr_registry=A4GL_getenv_registry (s,(char *) prefixed_string); /*Windows registry */


    ptr_resources_A4GL=0;
    ptr_resources=0;
    if (rcfiles) {
	if (strlen(prefixed_string)) {
	ptr_resources_A4GL = find_str_resource (prefixed_string); 	/* Try in resources */
	}
	ptr_resources = find_str_resource (s); 		/* Try in resources */
    }

    if (cumulate) {
		if (ptr_env_A4GL != 0) {
			sprintf(cumulated_string_tmp,"%s",ptr_env_A4GL);
			strcpy(cumulated_string,cumulated_string_tmp);
		}
	    	if (ptr_env != 0) {
			sprintf(cumulated_string_tmp,"%s%c%s",cumulated_string,cumulate_char,ptr_env);
			strcpy(cumulated_string,cumulated_string_tmp);
		}
	    	if (ptr_registry != 0) {
			sprintf(cumulated_string_tmp,"%s%c%s",cumulated_string,cumulate_char,ptr_registry);
			strcpy(cumulated_string,cumulated_string_tmp);
		}
	    	if (ptr_resources_A4GL != 0) {
			sprintf(cumulated_string_tmp,"%s%c%s",cumulated_string,cumulate_char,ptr_resources_A4GL);
			strcpy(cumulated_string,cumulated_string_tmp);
		}
		if (ptr_resources != 0) {
			sprintf(cumulated_string_tmp,"%s%c%s",cumulated_string,cumulate_char,ptr_resources);
			strcpy(cumulated_string,cumulated_string_tmp);
		}
		if (strlen (cumulated_string) != 0 ){
			ptr=(char *)cumulated_string;
        	}
		if (strlen(cumulated_string)>=sizeof(cumulated_string)) {
			PRINTF("Ran out of space - sorry - not enough space to generate a full '%s'\n",s);
			exit(1);
		}
    } else {


#ifdef DEBUG_VARIABLE_USAGE
	    	if (fd1) {
		fprintf(fd1,"%s - %p %p %p %p %p\n",s,ptr_env_A4GL,ptr_env,ptr_registry,ptr_resources_A4GL,ptr_resources);
		}
#endif



		ptr=0;

		if (ptr_env_A4GL != 0 && ptr==0) 	{ptr=ptr_env_A4GL; 
#ifdef DEBUG_VARIABLE_USAGE
		if (fd1) fprintf(fd1,"%s - Set from A4GL_ prefixed variablen",s);
#endif
		}
		if (ptr_env != 0 && ptr==0) 		{ptr=ptr_env; 
#ifdef DEBUG_VARIABLE_USAGE
		if (fd1) fprintf(fd1,"%s - Set from env variable\n",s);
#endif
		}
	    	if (ptr_registry != 0 && ptr==0)  	{ptr=ptr_registry; 
#ifdef DEBUG_VARIABLE_USAGE
		if (fd1) fprintf(fd1,"%s - Set from registry\n",s);
#endif
		}
	    	if (ptr_resources_A4GL != 0 && ptr==0)  {ptr=ptr_resources_A4GL; 
#ifdef DEBUG_VARIABLE_USAGE
		if (fd1) fprintf(fd1,"%s - Set from resource 1\n",s);
#endif
		}
		if (ptr_resources != 0 && ptr==0)  	{ptr=ptr_resources; 
#ifdef DEBUG_VARIABLE_USAGE
		if (fd1) fprintf(fd1,"%s - Set from resource 2\n",s);
#endif
		}
	}

	if (ptr == 0) {
#ifdef DEBUG_VARIABLE_USAGE
		if (fd1) fprintf(fd1,"%s - Not set anywhere\n",s);
#endif


#ifdef USE_OPTIMISATION
		A4GL_add_pointer(s,STR_RESOURCE_VAL,value_not_set);
#endif
		return an_empty_string;
	} else {

    	/* 
		FIXME: make sure that things like AUBITDIR are in appropriate format:
         	on Windows, watch out for Cywin relative paths.
         	/cygdrive/c/something is OK, but /usr/bin is not (missing drive
	        letter and CygWin path)!
	*/
		if (strcmp (s, "DBDATE") == 0) {
			A4GL_chk_dbdate (ptr);
		}

#ifdef DEBUG_VARIABLE_USAGE
		if (fd1) fprintf(fd1,"%s - %s\n",s,ptr);
#endif
		//remove quotes - for instance for the cases where quotes are used in 
		//aubitrc file because values contain spaces
		ptr=A4GL_strip_quotes_resource (ptr);
#ifdef USE_OPTIMISATION
		ptr=strdup(ptr);
		A4GL_add_pointer(s,STR_RESOURCE_VAL,ptr);
#endif

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
      /* why was this static? - because we return a pointer to it... */
      static char buff[1024];
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
 * Finds config file(s) with user resources (configuration settings)
 * and invokes parser/loader
 */
struct str_resource *
A4GL_build_user_resources (void)
{
char buff[1024];
FILE *resourcefile = 0;


	#ifdef DEBUG
		A4GL_debug ("Loading resources");
	#endif

	if (loaded_resources)
		return build_resource;
	if (build_resource)
		free (build_resource);

	
  /* 
  	----------------- from GLOBAL fixed location (/etc/opt/aubit4gl/aubitrc)
	On Windows, this will work only if there is CygWin installed
  */

	sprintf(buff, "/etc/opt/aubit4gl/%s", "aubitrc");
	resourcefile = fopen (buff, "r");
	if (resourcefile != 0) {
		#ifdef DEBUG
			A4GL_debug ("0:From %s", buff);
		#endif
		add_resources_in (resourcefile);
		fclose (resourcefile);
    } else {
		#ifdef DEBUG
			A4GL_debug ("0:cannot read %s", buff);
		#endif
    }

	
  /* 
  	----------------- from under AUBITETC (tipically /etc/opt/aubit4gl/aubitrc
	unless Autoconf determined that user does not have sufficient privileges
	to install it there) (SYSTEM GLOBAL)
	On Windows, this will work only with CygWin build - NOT with native compiled Aubit
	(Native Windows executables know nothing about CygWin path mangling, and what
	CYgWin1.dll presents to CygWin compiled programs as /etc is really a
	C:\cygwin\etc
  */

	sprintf(buff, "%s/%s", acl_getenv ("AUBITETC"), "aubitrc");
	resourcefile = fopen (buff, "r");
	if (resourcefile != 0) {
		#ifdef DEBUG
			A4GL_debug ("1:From %s", buff);
		#endif
		add_resources_in (resourcefile);
		fclose (resourcefile);
    } else {
		#ifdef DEBUG
			A4GL_debug ("1:cannot read %s", buff);
		#endif
    }

  /* 
  	-----------------  from $AUBITDIR/etc/aubitrc (AUBIT INSTALATION DIRECTORY) 
  */

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
  	if (resourcefile != 0) {
		#ifdef DEBUG
      		A4GL_debug ("2:From %s", buff);
		#endif
		add_resources_in (resourcefile);
		fclose (resourcefile);
    } else {
		#ifdef DEBUG
			A4GL_debug ("2:cannot read %s", buff);
		#endif
    }

  /* -----------------  from ~/.aubitrc (USER'S HOME DIRECTORY) */

  //Whooops: ~ works on shell command line, not from here!
  sprintf (buff, "%s/%s", acl_getenv ("HOME"), "/.aubit4gl/aubitrc");
  resourcefile = fopen (buff, "r");
  	if (resourcefile != 0) {
		#ifdef DEBUG
			A4GL_debug ("3:From %s", buff);
		#endif
		add_resources_in (resourcefile);
		fclose (resourcefile);
    } else {
		#ifdef DEBUG
			A4GL_debug ("3:cannot read %s", buff);
		#endif
    }

  /* ----------------- from ./.aubtirc (CURENT DIRECTORY) */

  sprintf (buff, "./%s", ".aubitrc");
  resourcefile = fopen (buff, "r");
  	if (resourcefile != 0) {
		#ifdef DEBUG
     	 A4GL_debug ("4:From %s", buff);
		#endif
      add_resources_in (resourcefile);
      fclose (resourcefile);
    } else {
		#ifdef DEBUG
			A4GL_debug ("4:cannot read %s", buff);
		#endif
    }

  /* ----------------- from $A4GL_INIFILE environment variable, if set */

  sprintf (buff, "%s", acl_getenv ("A4GL_INIFILE"));
  if (strlen (buff)) {
      resourcefile = fopen (buff, "r");
      if (resourcefile != 0) {
		  #ifdef DEBUG
			A4GL_debug ("5:From A4GL_INIFILE:%s", buff);
		  #endif
		  add_resources_in (resourcefile);
		  fclose (resourcefile);
	  } else {
		  #ifdef DEBUG
			A4GL_debug ("5:Cannot read A4GL_INIFILE:%s", buff);
		  #endif
	  }
  } else {
	  #ifdef DEBUG
		A4GL_debug ("A4GL_INIFILE not set");
	  #endif
  }

#ifdef DEBUG
	//dump user resources to debug log
	if (build_resource_cnt) {
		int a;
		A4GL_debug ("User resources");
      for (a = 0; a < build_resource_cnt; a++) {
		//It can be security risk to dump some settings to log files
		if (strcmp (build_resource[a].name, "SQLPWD") == 0){
			A4GL_debug ("%d. %s = <SET>", a, build_resource[a].name);
		} else {
			A4GL_debug ("%d. %s = %s", a, build_resource[a].name,
				build_resource[a].value);
		}
	  }
    }
#endif

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
		char *ptr2;
		ptr2=ptr;
		if (strcmp(buff,"PG_ESQLC")==0) { 
			// By mistake - this may be in the .aubit4gl/aubitrc file
			// with an empty value
			// This will stop ecpg working...
			// - so lets filter that condition out...
			if (strlen(ptr)==0|| strcmp(ptr,"\"\"")==0) ptr2=0;
		} 

		if (ptr2) {
	      		strcpy (build_resource[a].value, ptr);
		}
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
    PRINTF ("Built-in resources:\n");
  for (a = 0; strlen (res[a].name) != 0; a++)
    {
      if (!export)
	PRINTF ("  %s=%s\n", res[a].name, res[a].value);
      else
	{
	  if (getenv (res[a].name))
	    PRINTF ("export %s='%s'\n", res[a].name,
		    acl_getenv (res[a].name));
	}
    }

  res = user_resource;

  if (res)
    {
      if (!export)
	PRINTF ("User resources :\n");
      for (a = 0; strlen (res[a].name) != 0; a++)
	{
	  if (!export)
	    PRINTF ("  %s=%s\n", res[a].name, res[a].value);
	  else
	    {
	      if (getenv (res[a].name))
		{
		  PRINTF ("export %s='%s'\n", res[a].name,
			  acl_getenv (res[a].name));
		}
	    }
	}
    }

}


void A4GL_log_changed_envvar(char *name,char *value) {
#ifdef DEBUG_VARIABLE_USAGE
		if (fd1) fprintf(fd1,"A4GL_setenv - changes %s to %s\n",name,value);
#endif
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


// Get the value thats used to represent an empty string...
char *A4GL_not_set_empty_string(void) {
	return an_empty_string;
}
static char * A4GL_strip_quotes_resource (char *s)
{
  static char *buff=0;
  static int bl=0;

  if (strlen(s)>bl || buff==0) {
		bl=strlen(s);
		buff=realloc(buff,bl+1);
  }

  if ((s[0] == '"' || s[0] == '\'') && s[strlen (s) - 1] == s[0])
    {
      strcpy (buff, &s[1]);
      buff[strlen (buff) - 1] = 0;
    }
  else
    {
      strcpy (buff, s);
    }
  return buff;
}




/* ----------------------------- EOF --------------------------------- */
