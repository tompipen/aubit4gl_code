/**
 * @file
 * Error handling (there are several files)
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

#include "../generated/tmperrs.h"
//#include "../libincl/debug.h"
#include "../libincl/debug.h"
#include <stdarg.h>
#define IGNOREEXITWITH
char errorbuff[256]="";
char lasterrorstr[1024]="";
extern int status;

int cache_status=0;
int cache_statusno=0;

IGNOREEXITWITH exitwith(char *s) {
int a;
#ifdef DEBUG
/* {DEBUG} */ {debug("Error... %s",s);
}
#endif
for (a=0;errors[a].errno;a++) {
       if (strcmp(s,errors[a].errmsg)==0) {
#ifdef DEBUG
/* {DEBUG} */ {              debug("Found error = %d",errors[a].errno);
}
#endif
debug("Setting status");
   	A4GLSQL_set_status(-1*(errors[a].errno+30000),0);
debug("Setting cache_status");
	     cache_status=(errors[a].errno+30000);
debug("Setting statusno");
	     cache_statusno=a;
		return;
       }
}

exitwith("Unknown error");
}


IGNOREEXITWITH exitwith_sql(char *s) {
int a;
#ifdef DEBUG
/* {DEBUG} */ {debug("Error... %s",s); }
#endif
for (a=0;errors[a].errno;a++) {
       if (strcmp(s,errors[a].errmsg)==0) {
#ifdef DEBUG
/* {DEBUG} */ {              debug("Found error = %d",errors[a].errno);
}
#endif
             A4GLSQL_set_status(-1*(errors[a].errno+30000),1);
	     cache_status=(errors[a].errno+30000);
	     cache_statusno=a;
       }
}
}

set_error (char *fmt,...)
{
  va_list args;
  va_start (args, fmt);
  vsprintf (errorbuff, fmt, args);
#ifdef DEBUG
/* {DEBUG} */ {  debug("%s",errorbuff);
}
#endif
}

char *get_errm(int z)
{
int a;
debug("In get errm");
if (z==cache_status) {
debug("Cached...");
	return errors[cache_statusno].errmsg;
}

       debug("Looking up error... %d",a);
for (a=0;errors[a].errno;a++) {
       if (errors[a].errno+30000==z) {
	return errors[a].errmsg;
       }
}
debug("Not found...");
debug("Returning %p",lasterrorstr);
debug("Returning %s",lasterrorstr);
return lasterrorstr;
}

