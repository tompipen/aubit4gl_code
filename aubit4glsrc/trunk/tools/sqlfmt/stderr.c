/*
@(#)File:            $RCSfile: stderr.c,v $
@(#)Version:         $Revision: 1.3 $
@(#)Last changed:    $Date: 2003-05-15 07:10:51 $
@(#)Purpose:         Error reporting routines -- using stdio
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1988-91,1996-98
@(#)Product:         SQLFMT Version 14 (1998-11-04)
*/  
  
/*TABSTOP=4*/ 
   /*LINTLIBRARY*/ 
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include "stderr.h"
static char arg0[15] = "**undefined**";
static FILE *errout = stderr;

#ifndef lint
static const char rcs[] =
  "@(#)$Id: stderr.c,v 1.3 2003-05-15 07:10:51 mikeaubury Exp $";

#endif	/* lint */
  
/* Change the definition of 'stderr', reporting on the old one too */ 
/* NB: using err_stderr((FILE *)0) simply reports the current 'stderr' */ 
  FILE * err_stderr (FILE * newerr) 
{
  FILE * old = errout;
  if (newerr != (FILE *) 0)
    errout = newerr;
  return (old);
}
const char *
A4GL_getarg0 (void) 
{
  return (arg0);
}
void
remark2 (const char *s1, const char *s2) 
{
  err_report (ERR_REM, ERR_STAT, "%s %s\n", (s1), (s2));
}
void
remark (const char *s1) 
{
  err_report (ERR_REM, ERR_STAT, "%s\n", (s1));
}
void
error2 (const char *s1, const char *s2) 
{
  err_report (ERR_ERR, ERR_STAT, "%s %s\n", (s1), (s2));
}
void
error (const char *s1) 
{
  err_report (ERR_ERR, ERR_STAT, "%s\n", (s1));
}
void
stop (const char *s1) 
{
  err_report (ERR_ABT, ERR_STAT, "%s\n", (s1));
}
void
usage (const char *s1) 
{
  err_report (ERR_USE, ERR_STAT, (s1));
}
const char *
err_rcs_string (const char *s2, char *buffer, size_t buflen) 
{
  const char *src = s2;
  char *dst = buffer;
  char *end = buffer + buflen - 1;
  
    /*
       ** Bother RCS!  We've probably been given something like:
       ** "$Revision: 1.3 $ ($Date: 2003-05-15 07:10:51 $)"
       ** We only want to emit the revision number and the date/time.
       ** Skip the components between '$' and ': ', copy up to ' $',
       ** repeating as necessary.  And we have to test for overflow!
     */ 
    while (*src != '\0' && dst < end)
    
    {
      while (*src != '\0' && *src != '$')
	
	{
	  *dst++ = *src++;
	  if (dst >= end)
	    break;
	}
      if (*src == '$')
	src++;
      while (*src != '\0' && *src != ':' && *src != '$')
	src++;
      if (*src == '\0')
	break;
      if (*src == '$')
	
	{
	  
	    /* Unexpanded keyword '$Keyword$' notation */ 
	    src++;
	  continue;
	}
      if (*src == ':')
	src++;
      if (*src == ' ')
	src++;
      while (*src != '\0' && *src != '$')
	
	{
	  *dst++ = *src++;
	  if (dst >= end)
	    break;
	}
      if (*src == '$')
	
	{
	  if (*(dst - 1) == ' ')
	    dst--;
	  src++;
	}
    }
  *dst = '\0';
  return (buffer);
}


/* Report version information, removing embedded RCS keyword strings (but not values) */ 
  void
version (const char *s1, const char *s2) 
{
  char buffer[64];
  if (strchr (s2, '$'))
    s2 = err_rcs_string (s2, buffer, sizeof (buffer));
  err_logmsg (stdout, ERR_ERR, EXIT_SUCCESS, "%s Version %s\n", s1, s2);
}


/* Store basename of command, excluding trailing slashes */ 
/* Doesn't handle two pathological cases -- "/" and "" */ 
  void
A4GL_setarg0 (const char *argv0) 
{
  const char *cp;
  size_t nbytes = sizeof (arg0) - 1;
  if ((cp = strrchr (argv0, '/')) != (char *) 0 && *(cp + 1) == '\0')
    
    {
      
	/* Skip backwards over trailing slashes */ 
      const char *ep = cp;
      while (ep > argv0 && *ep == '/')
	ep--;
      
	/* Skip backwards over non-slashes */ 
	cp = ep;
      while (cp > argv0 && *cp != '/')
	cp--;
      cp++;
      nbytes = ep - cp + 1;
      if (nbytes > sizeof (arg0) - 1)
	nbytes = sizeof (arg0) - 1;
    }
  
  else if (cp != (char *) 0)
    
    {
      
	/* Regular pathname containing slashes */ 
	cp++;
    }
  
  else
    
    {
      
	/* Basename of file only */ 
	cp = argv0;
    }
  strncpy (arg0, cp, nbytes);
  arg0[nbytes] = '\0';
}


/* Format a time string for now (using ISO8601 format) */ 
/* Allow for future settable time format with tm_format */ 
static char *
err_time (void) 
{
  static char buffer[32];
  static const char tm_format[] = "%Y-%m-%d %H:%M:%S";
  time_t now;
  struct tm *tp;
  now = time ((time_t *) 0);
  tp = localtime (&now);
  strftime (buffer, sizeof (buffer), tm_format, tp);
  return (buffer);
}


/* Most fundamental (and flexible) error message printing routine */ 
/* Not singularly convenient for ordinary mortals -- see err_logmsg() */ 
  void
err_fprint (FILE * fp, int flags, int estat, const char *string,
	    va_list args) 
{
  int errnum = errno;		/* Capture errno before it is damaged! */
  if (flags & ERR_FLUSH)
    (void) fflush (stdout);
  if (flags & ERR_USAGE)
    (void) fprintf (fp, "Usage: %s %s\n", arg0, string);
  
  else if (flags & ERR_COMM)
    
    {
      if ((flags & ERR_NOARG0) == 0)
	(void) fprintf (fp, "%s: ", arg0);
      if (flags & ERR_STAMP)
	(void) fprintf (fp, "%s - ", err_time ());
      if (flags & ERR_PID)
	(void) fprintf (fp, "pid=%d: ", (int) getpid ());
      (void) vfprintf (fp, string, args);
      if (flags & ERR_ERRNO)
	(void) fprintf (fp, "error (%d) %s\n", errnum, strerror (errnum));
    }
  (void) fflush (fp);
  if (flags & ERR_ABORT)
    abort ();
  if (flags & ERR_EXIT)
    exit (estat);
}


/* Most convenient external interface to err_fprint() */ 
  void
err_logmsg (FILE * fp, int flags, int estat, const char *string, ...) 
{
  va_list args;
  va_start (args, string);
  err_fprint (fp, flags, estat, string, args);
  va_end (args);
}


/* Cover function for err_fprint() using default output file (normally stderr) */ 
  void
A4GL_err_print (int flags, int estat, const char *string, va_list args) 
{
  err_fprint (errout, flags, estat, string, args);
}
void
err_remark (const char *format, ...) 
{
  va_list args;
  va_start (args, format);
  err_print (ERR_REM, ERR_STAT, format, args);
  va_end (args);
}
void
err_error (const char *format, ...) 
{
  va_list args;
  va_start (args, format);
  err_print (ERR_ERR, ERR_STAT, format, args);
  va_end (args);
}
void
err_report (int flags, int estat, const char *string, ...) 
{
  va_list args;
  va_start (args, string);
  err_print (flags, estat, string, args);
  va_end (args);
}


#ifdef TEST
static const char *list[] = 
  { "/usr/fred/bloggs", "/usr/fred/bloggs/", "/usr/fred/bloggs////",
"bloggs", "/.", ".", "/", "//", "///", "////", "", (char *) 0 
};
int
main (int argc, char **argv) 
{
  const char **name;
  char *data;
  setarg0 (argv[0]);
  err_logmsg (stdout, ERR_LOG, EXIT_SUCCESS, "testing ERR_LOG\n");
  err_logmsg (stdout, ERR_STAMP | ERR_REM | ERR_FLUSH, EXIT_SUCCESS,
	       "testing ERR_STAMP\n");
  err_logmsg (stdout, ERR_PID | ERR_REM | ERR_FLUSH, EXIT_SUCCESS,
	       "testing ERR_PID\n");
  errno = EXDEV;
  err_logmsg (stdout, ERR_ERRNO | ERR_REM | ERR_FLUSH, EXIT_SUCCESS,
	       "testing ERR_ERRNO\n");
  remark ("testing values for argv[0]");
  for (name = list; *name != (char *) 0; name++)
    
    {
      data = malloc (strlen (*name) + 1);
      strcpy (data, *name);
      printf ("name = <<%s>>; ", *name);
      setarg0 (*name);
      printf (" (<<%s>>) arg0 = <<%s>>\n", *name, A4GL_getarg0 ());
      free (data);
    }
  setarg0 (argv[0]);
  remark ("reporting arguments to program");
  while (*++argv != (char *) 0)
    remark2 ("next argument", *argv);
  remark ("reporting on version!");
  version ("STDERR", "$Revision: 1.3 $ ($Date: 2003-05-15 07:10:51 $)");
  return (0);
}


#endif	/* TEST */
