#include "a4gl_libaubit4gl_int.h"


/**
 * Get the integer key value from a string.
 *
 * @param v The string key representation.
 * @return The integer key representation.
 */
int
A4GL_net_keyval (char *v)
{
  char v0[800];
  long _r;

  A4GL_debug ("In net_keyval");
  strcpy (v0, v);
  A4GL_trim (v);
  A4GL_stripnl (v);
  A4GL_debug ("Decoding ...%s...", v0);
  if (strlen (v0) == 1)
    {
      return v0[0];
    }
  if (strcmp (v0, "INTERRUPT") == 0)
    {
      return (-1);
    }
  if (strcmp (v0, "ACCEPT") == 0)
    {
      return (-2);
    }
  if (strcmp (v0, "LEFT") == 0)
    return A4GLKEY_LEFT;
  if (strcmp (v0, "RIGHT") == 0)
    return A4GLKEY_RIGHT;
  if (strcmp (v0, "UP") == 0)
    return A4GLKEY_UP;
  if (strcmp (v0, "DOWN") == 0)
    return A4GLKEY_DOWN;
  if (strcmp (v0, "PGUP") == 0)
    return A4GLKEY_PGUP;
  if (strcmp (v0, "PGDN") == 0)
    return A4GLKEY_PGDN;
  if (strcmp (v0, "INS") == 0)
    return A4GLKEY_INS;
  if (strcmp (v0, "DEL") == 0)
    return A4GLKEY_DEL;
  if (strcmp (v0, "BACKSPACE") == 0)
    return 8;
  if (strcmp (v0, "RETURN") == 0)
    return CR;
  if (strcmp (v0, "TAB") == 0)
    return 9;
  if (strcmp (v0, "HOME") == 0)
    return A4GLKEY_HOME;
  if (strcmp (v0, "END") == 0)
    return A4GLKEY_END;
  if (strcmp (v0, "ESCAPE") == 0)
    return 27;

  if (v0[0] == 'F')
    {
      _r = atoi (&v0[1]);
      return (A4GLKEY_F (_r));
    }

  if (v0[0] == '^')
    {
      return (v0[1] - 'A' + 1);
    }
  A4GL_debug ("Not found in here");
  return 0;
}




