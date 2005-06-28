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
