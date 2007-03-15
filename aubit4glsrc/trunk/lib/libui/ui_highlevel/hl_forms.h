/* forms.h */
#ifndef HL_FORMS_H
#define HL_FORMS_H
#include "a4gl_libaubit4gl.h"

struct s_windows
{
  int x, y, w, h;
  void *win;
  char name[100];
  struct s_form_dets *form;
  struct s_form_attr winattr;
};




#endif
