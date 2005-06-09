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
#include "formdriver.h"

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
A4GL_get_field_width (void *field)
{
	  return A4GL_LL_get_field_width (field);
}


void
A4GL_start_form (struct s_form_dets *s)
{
  A4GL_debug ("Start form - %p %p", s, s->form);

  A4GL_LL_int_form_driver (s->form, AUBIT_REQ_FIRST_PAGE);
  A4GL_LL_int_form_driver (s->form, AUBIT_REQ_FIRST_FIELD);
  A4GL_LL_set_carat (s->form);

  s->form_details.insmode = 0;

  if (s->form_details.insmode)
    A4GL_LL_int_form_driver (s->form, AUBIT_REQ_INS_MODE);
  else
    A4GL_LL_int_form_driver (s->form, AUBIT_REQ_OVL_MODE);

  /*A4GL_form_field_chk (s, 1); */
}



#ifdef MOVED
int
A4GL_proc_key_prompt (int a, void *mform, struct s_prompt *prompt)
{
  void *f;

  f = A4GL_LL_current_field (mform);


  A4GL_debug ("In proc_key_prompt.... for %d", a);
  switch (a)
    {
    case 18: A4GL_LL_screen_redraw (); break;

    case -1: abort_pressed = 1; return 0;

    case 27: return 0;

    case 26: return 0;

    case 127:
    case 8:
    case A4GLKEY_DC:
    case A4GLKEY_DL:
    case A4GLKEY_BACKSPACE:
      if (A4GL_LL_get_carat (mform))
        {
          A4GL_LL_int_form_driver (mform, AUBIT_REQ_DEL_PREV);
        }
      return 0;

    case 24:
      A4GL_LL_int_form_driver (mform, AUBIT_REQ_DEL_CHAR);
      return 0;

    case '\t':
    case A4GLKEY_DOWN:
      if (prompt->charmode == 0)
        return 10;
      else
        return 0;


    //case A4GLKEY_ENTER:
    case 13:
    case 10: return 10;
    case A4GLKEY_LEFT: A4GL_LL_int_form_driver (mform, AUBIT_REQ_PREV_CHAR); return 0;

    case A4GLKEY_RIGHT: A4GL_LL_int_form_driver (mform, AUBIT_REQ_NEXT_CHAR); return 0;
    case 4: A4GL_LL_int_form_driver (mform, AUBIT_REQ_CLR_FIELD); return 0;

    case 1:                     // Control - A
      prompt->insmode = prompt->insmode ? 0 : 1;
      if (prompt->insmode) A4GL_LL_int_form_driver (mform, AUBIT_REQ_INS_MODE);
      else A4GL_LL_int_form_driver (mform, AUBIT_REQ_OVL_MODE);
      return 0;
    }
  if (A4GL_is_special_key(a, A4GLKEY_HELP)) { aclfgl_a4gl_show_help (prompt->h); a = 0; }
  return a;
}

#endif

void
A4GL_default_attributes (void *f, int dtype)
{
  struct struct_scr_field *fprop;

  int done = 0;

  fprop = (struct struct_scr_field *) (A4GL_LL_get_field_userptr (f));
  A4GL_debug ("In def attrib f=%p", f);





  if (fprop)
    {
      if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
        {
          A4GL_debug ("ZZZZ - SET OPTS");
          A4GL_LL_set_field_opts (f,
                                  AUBIT_O_VISIBLE | AUBIT_O_ACTIVE |
                                  AUBIT_O_PUBLIC | AUBIT_O_EDIT );
          done = 1;
        }
    }



  if (done == 0)
    {

      A4GL_debug ("MMMM DTYPE & 255 = %d", dtype);

      if ((dtype & 255) == 0)
        {
          A4GL_debug ("ZZZZ - SET OPTS");
          A4GL_LL_set_field_opts (f,
                                  AUBIT_O_VISIBLE | AUBIT_O_ACTIVE | AUBIT_O_PUBLIC | AUBIT_O_EDIT);
          A4GL_field_opts_off (f, AUBIT_O_BLANK);
        }
      else
        {
          A4GL_debug ("ZZZZ - SET OPTS");
          A4GL_debug ("BLANK BLANK");
          A4GL_LL_set_field_opts (f,
                                  AUBIT_O_VISIBLE | AUBIT_O_ACTIVE |
                                  AUBIT_O_PUBLIC | AUBIT_O_EDIT | AUBIT_O_BLANK);
        }

    }

  A4GL_debug ("STATIC");
  A4GL_LL_set_field_fore (f, A4GL_LL_colour_code (7));
  A4GL_LL_set_field_back (f, A4GL_LL_colour_code (7));
  A4GL_LL_set_max_field(f,A4GL_get_field_width(f));

}



int
A4GL_get_metric_for (struct s_form_dets *form, void *f)
{
  int a;

  A4GL_debug ("In curr metric");
  for (a = 0; a < form->fileform->metrics.metrics_len; a++)
    {
      if (f == (void *) form->fileform->metrics.metrics_val[a].field)
        {
          A4GL_debug ("Returning %d\n", a);
          return a;
        }
    }
  A4GL_debug ("NO current metric !");
  return -1;
}

