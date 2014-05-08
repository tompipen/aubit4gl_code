#include "a4gl_libaubit4gl_int.h"

/*
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
*/
#include <dirent.h>

#define HELPMAXLEN 78
static struct dirent *de = 0;
static DIR *d;



static char *
check_for_msgno (char *file, int msgno)
{
  char *lv_char;
  long lv_msgline;
  A4GL_push_char (file);
  A4GL_push_long (msgno);
  aclfgl_aclfgl_openiem (2);
  lv_char = A4GL_char_pop ();
  lv_msgline = A4GL_pop_long ();
  if (lv_msgline)
    {
#ifdef DEBUG
      A4GL_debug ("FOUND IN %s", file);
#endif
      A4GL_trim_nl (lv_char);
      return lv_char;
    }
  return 0;
}

static char *
internal_get_errmsg_from_helpfile (char *path, int n)
{
//static char buff[256];
  static char buff2[256];

  if (d)
    {
      closedir (d);
      d = 0;
    }
  d = (DIR *) opendir (path);

  if (d != 0)
    {
      while (1)
	{
	  de = readdir (d);
	  if (!de)
	    break;

	  if (strstr (de->d_name, "helpsql_"))
	    {			// These will get picked up separately...
	      continue;
	    }
	  if (!strstr (de->d_name, ".iem") && !strstr (de->d_name, ".hlp") && !strstr (de->d_name, acl_getenv ("A4GL_HLP_EXT")))
	    {
	      continue;
	    }
	  strcpy (buff2, path);
	  strcat (buff2, "/");
	  strcat (buff2, de->d_name);
	  if (strlen (de->d_name))
	    {
	      char *lv_char;

	      lv_char = check_for_msgno (buff2, n);
	      if (lv_char)
		{
#ifdef DEBUG
		  A4GL_debug ("FOUND IN %s file %s", buff2);
#endif
		  closedir (d);
		  d = 0;
		  return lv_char;
		}
	    }
	  else
	    {
	      closedir (d);
	      d = 0;
	      return 0;
	    }
	}
    }
  return 0;
}

char *
A4GL_get_errmsg_from_helpfiles (int n)
{
  char buff[2000];
  char buff2[2000];
  char *ptr;


// First lets try in $AUBITDIR/etc/help_$DIALECT.*
  strcpy (buff, (char *) acl_getenv ("AUBITDIR"));
#ifdef SIMPLIFIED
  strcat (buff, "/share");
#else
  strcat (buff, "/etc");
#endif
  strcat (buff, "/helpsql_");
  strcat (buff, A4GLSQL_dbms_dialect ());

  SPRINTF2 (buff2, "%s%s", buff, acl_getenv ("A4GL_HLP_EXT"));
#ifdef DEBUG
  A4GL_debug ("Looking in file '%s'\n", buff2);
#endif
  if (A4GL_file_exists (buff2))
    {
      ptr = check_for_msgno (buff2, n);
      if (ptr)
	return ptr;
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("Skipping - no file");
#endif
    }
  SPRINTF1 (buff2, "%s.iem", buff);
#ifdef DEBUG
  A4GL_debug ("Looking in file '%s'\n", buff2);
#endif
  if (A4GL_file_exists (buff2))
    {
      ptr = check_for_msgno (buff2, n);
      if (ptr)
	return ptr;
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("Skipping - no file");
#endif
    }
  SPRINTF1 (buff2, "%s.hlp", buff);
#ifdef DEBUG
  A4GL_debug ("Looking in file '%s'\n", buff2);
#endif
  if (A4GL_file_exists (buff2))
    {
      ptr = check_for_msgno (buff2, n);
      if (ptr)
	return ptr;
    }
  else
    {
#ifdef DEBUG
      A4GL_debug ("Skipping - no file");
#endif
    }



// Nothing specific - lets try generic...
  strcpy (buff, (char *) acl_getenv ("AUBITDIR"));
#ifdef SIMPLIFIED
  strcat (buff, "/share");
#else
  strcat (buff, "/etc");
#endif


#ifdef DEBUG
  A4GL_debug ("Looking in directory %s\n", buff);
#endif
  ptr = internal_get_errmsg_from_helpfile (buff, n);
  if (ptr)
    return ptr;


  if (!A4GL_isno (acl_getenv ("CHECKINFORMIXMSGS")))
    {
      // Nothing found - lets take a peak in $INFORMIXDIR if its set...
      if (acl_getenv_not_set_as_0 ("INFORMIXDIR") != 0)
	{
	  SPRINTF1 (buff, "%s/msg/en_us/0333", acl_getenv ("INFORMIXDIR"));
#ifdef DEBUG
	  A4GL_debug ("Looking in directory %s\n", buff);
#endif
	  ptr = internal_get_errmsg_from_helpfile (buff, n);
	  if (ptr)
	    {
	      char *p;
	      p = strchr (ptr, '\n');
	      if (p)
		*p = 0;
	      p = strchr (ptr, '\r');
	      if (p)
		*p = 0;
	      return ptr;
	    }
	}
    }

  return 0;
}
