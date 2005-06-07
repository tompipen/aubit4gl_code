// This module contains functions which can be called from the
// front end and independantly from the backend
// There should be nothing that is called directly from libaubit4gl!
// (so no UILIB_... functions)
//
//

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

#include "a4gl_libaubit4gl.h"
#include "a4gl_API_lowlevel.h"

#define COLOR_BLACK     0
#define COLOR_RED       1
#define COLOR_GREEN     2
#define COLOR_YELLOW    3
#define COLOR_BLUE      4
#define COLOR_MAGENTA   5
#define COLOR_CYAN      6
#define COLOR_WHITE     7


int
A4GL_decode_colour_attr_aubit (int a)
{
  char colour[20];
  char attr[256];
  A4GL_debug ("MJA Decoding %d", a);
  A4GL_get_strings_from_attr (a, colour, attr);

  A4GL_debug ("MJA Got colour as : %s - %s", colour, attr);
  A4GL_trim (colour);

  if (strlen (colour) == 0)
    return A4GL_LL_colour_code (COLOR_WHITE);
  if (strcmp (colour, "BLACK") == 0)
    return A4GL_LL_colour_code (COLOR_BLACK);
  if (strcmp (colour, "RED") == 0)
    return A4GL_LL_colour_code (COLOR_RED);
  if (strcmp (colour, "GREEN") == 0)
    return A4GL_LL_colour_code (COLOR_GREEN);
  if (strcmp (colour, "YELLOW") == 0)
    return A4GL_LL_colour_code (COLOR_YELLOW);
  if (strcmp (colour, "BLUE") == 0)
    return A4GL_LL_colour_code (COLOR_BLUE);
  if (strcmp (colour, "MAGENTA") == 0)
    return A4GL_LL_colour_code (COLOR_MAGENTA);
  if (strcmp (colour, "CYAN") == 0)
    return A4GL_LL_colour_code (COLOR_CYAN);
  if (strcmp (colour, "WHITE") == 0)
    return A4GL_LL_colour_code (COLOR_WHITE);



  return 0;
}



int
A4GL_field_opts_on (void *v, int n)
{

  if (A4GL_LL_field_opts (v) & n)
    return 1;
  A4GL_LL_set_field_opts (v, A4GL_LL_field_opts (v) + n);
  return 1;
}

int
A4GL_field_opts_off (void *v, int n)
{
  if (!(A4GL_LL_field_opts (v) & n))
    return 1;
  A4GL_LL_set_field_opts (v, A4GL_LL_field_opts (v) - n);
  return 1;
}


/**
 *  *
 *   * @todo Describe function
 *    */
void *
A4GL_create_blank_window (char *name, int x, int y, int w, int h, int border)
{
  void *p;
  //A4GL_chkwin ();
  A4GL_debug ("Creating blank window..");
  p =
    (void *) A4GL_create_window (name, x, y, w, h, 1, 0xff, 0xff, 0xff, 0xff,
				 border, 0xff, 0xff, 0xffff);
  A4GL_debug ("window=%p", p);


  return p;
}



void
A4GL_mja_set_field_buffer (void *field, int nbuff, char *buff)
{
  char buff2[8024];
  int a;
  int b;
  int width;
  b = A4GL_get_field_width (field);
  strcpy (buff2, buff);
  a = strlen (buff2);
  b = A4GL_get_field_width (field);
  A4GL_debug ("field_buffer %p %d %s", field, nbuff, buff);
  width = A4GL_get_field_width (field);
  if (width > 2048)
    {
      char *ptr = 0;
      A4GL_debug ("Field too big...");
      *ptr = 0;

    }
  if (a < A4GL_get_field_width (field))
    {
      A4GL_debug ("Adding padding");
      A4GL_pad_string (buff2, A4GL_get_field_width (field));
    }
  else
    {
      A4GL_debug ("No padding required '%s'", buff);
    }


  A4GL_LL_set_field_buffer (field, nbuff, buff2);
}



void
A4GL_mja_set_field_buffer_contrl (void *field, int nbuff, int ch)
{
  char buff[20];
  A4GL_debug ("Ch=%d", ch);
  if (ch == 0)
    {
      return;
    }
  buff[0] = ch & 0xff;
  buff[1] = 0;
  A4GL_debug ("Adding char %d %c", ch, ch);
  A4GL_mja_set_field_buffer (field, nbuff, buff);
}



int
A4GL_getch_win (int allow_acc_intr)
{
    int a;
    A4GL_debug ("getch_win called...");
    if (allow_acc_intr) { A4GL_LL_set_acc_intr_keys(1); }
    a = A4GL_LL_getch_swin (A4GL_window_on_top ());
    A4GL_clr_error_nobox ("A4GL_getch_win");
    if (allow_acc_intr) { A4GL_LL_set_acc_intr_keys(0); }
    return a;
}


int
A4GL_get_field_width (void *field)
{
	  return A4GL_LL_get_field_width (field);
}

