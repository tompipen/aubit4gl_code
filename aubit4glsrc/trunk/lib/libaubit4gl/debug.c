#include <stdarg.h>

int debug_full (char *fmt,...);

#include "../libincl/dbform.h"
#include "../libincl/stack.h"
#include "../libincl/debug.h"
#include "../libincl/pointers.h"
#ifdef __CYGWIN__
#include "../libincl/sqlca.h"
#endif

FILE *debugfile = 0;
int nodebug = 0;
char g_fname[256];
int g_lineno;

open_debugfile ()
{
  debugfile = mja_fopen ("debug.out", "w");
  if (debugfile==0) {
                printf("Unable to open debug.out - check directory permissions...\n");
        exit(2);
  }
}

debug_full (char *fmt,...)
{
  va_list args;
  static char buff[4096];
  if (nodebug == 2)
    return;

  if (nodebug == 0)
    {
      if (strlen(acl_getenv ("DEBUG")))
        nodebug = 1;
      else
        {
          nodebug = 2;
          return;
        }
    }

  if (debugfile == 0)
    {
      open_debugfile ();
    }
  if (strcmp ("ALL", acl_getenv ("DEBUG")) == 0 || strcmp (g_fname, acl_getenv ("DEBUG")) == 0)
    {
      va_start (args, fmt);
      vsprintf (buff, fmt, args);
      if (buff[strlen (buff) - 1] != ':')
        fprintf (debugfile, "%-20s %-6d status=%6d sqlca.sqlcode=%6d\n ", g_fname, g_lineno, status, sqlca.sqlcode);
      fprintf (debugfile, "%s\n", buff);

        //fixme: AUBITGUI can also be gui, not only gtk
        if (strcmp(acl_getenv("AUBITGUI"),"GTK")==0) {
                fprintf(stderr,"%s\n",buff);
        }
      if (buff[strlen (buff) - 1] != ':')
        fprintf (debugfile, "\n");
      fflush (debugfile);
    }
}


int
set_line (char *fname, long lineno)
{
  if (nodebug == 1)
    {
      strcpy (g_fname, fname);

      g_lineno = lineno;
    }
  return 0;
}
