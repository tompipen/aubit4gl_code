
#include "a4gl_libaubit4gl_int.h"

int dying=0;

// --- from fglwrap.c
void
A4GL_fgl_die_with_msg (int n, char *s)
{
  if (dying)
    {
      // We're already trying to die...
      return;
    }
  dying++;

  if (dying > 1)
    {
      exit (n);
    }
  if (A4GL_isscrmode ())
    {
#ifdef DEBUG
      A4GL_debug ("In screen mode - ending curses...");
#endif
      A4GL_gotolinemode ();
    }
  A4GL_close_database ();
  A4GL_close_errorlog_file ();
  A4GL_debug ("End of program - exit(%d).", n);
  PRINTF ("%s\n", s);
  exit (n);
}



void
A4GL_fgl_die (int n)
{
  if (dying)
    return;
  dying++;
  if (dying > 1)
    {
      // Die quickly...
      exit (n);
    }



  A4GL_stop_ui();


  if (A4GL_isscrmode ())
    {
#ifdef DEBUG
      A4GL_debug ("In screen mode - ending curses...");
#endif
      A4GL_stop_ui();
      //A4GL_gotolinemode ();
    }
  A4GL_close_database ();
  A4GL_close_errorlog_file ();
  A4GL_debug ("End of program - exit(%d).", n);
  exit (n);
}

