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
#include "hl_proto.h"
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
  A4GL_LL_set_field_buffer (field, nbuff, buff);
}




void
A4GL_start_form (void *frm)
{

  A4GL_LL_int_form_driver (frm, AUBIT_REQ_FIRST_PAGE);
  A4GL_LL_int_form_driver (frm, AUBIT_REQ_FIRST_FIELD);
  A4GL_LL_set_carat (frm);

  //s->form_details.insmode = 0;
  //if (s->form_details.insmode)
  //A4GL_LL_int_form_driver (frm, AUBIT_REQ_INS_MODE);
  //else


    A4GL_LL_int_form_driver (frm, AUBIT_REQ_OVL_MODE);

}




void
A4GL_default_attributes (void *f, int dtype,int has_picture)
{
  int done = 0;

  A4GL_debug ("In def attrib f=%p", f);



      if (has_picture)
        {
          A4GL_debug ("ZZZZ - SET OPTS");
          A4GL_LL_set_field_opts (f,
                                  AUBIT_O_VISIBLE | AUBIT_O_ACTIVE |
                                  AUBIT_O_PUBLIC | AUBIT_O_EDIT );
          done = 1;
        }





  if (done == 0)
    {

      A4GL_debug ("MMMM DTYPE & 255 = %d", dtype);

      if ((dtype & 255) == 0)
        {
          A4GL_debug ("ZZZZ - SET OPTS");
          A4GL_LL_set_field_opts (f,
                                  AUBIT_O_VISIBLE | AUBIT_O_ACTIVE | AUBIT_O_PUBLIC | AUBIT_O_EDIT);


	
          //A4GL_field_opts_off (f, AUBIT_O_BLANK); @todo     is it ok to remove this ?

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
  A4GL_LL_set_max_field(f,A4GL_LL_get_field_width(f));

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

