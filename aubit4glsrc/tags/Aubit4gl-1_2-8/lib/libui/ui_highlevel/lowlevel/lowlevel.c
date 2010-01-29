#include "a4gl_libaubit4gl.h"
#include "lowlevel.h"
#ifndef lint
static char const module_id[] =
  "$Id: lowlevel.c,v 1.7 2007-05-18 18:20:53 mikeaubury Exp $";
#endif



int chars_normal[6];

void
A4GL_LL_switch_to_line_mode (void)
{
  printf ("switch_to_line_mode\n");
  A4GL_set_scrmode ('L');
}


void
A4GL_LL_display_menu (ACL_Menu * m)
{
  printf ("display_menu\n");
}


void *
A4GL_LL_create_window (int h, int w, int y, int x, int border)
{
  printf ("create window %d %d %d %d %d\n", h, w, y, x, border);
}

void
A4GL_LL_remove_window (void *x)
{
  printf ("Remove window\n");
}

void
A4GL_LL_initialize_display ()
{
}

void
A4GL_LL_wadd_char_xy_col (void *win, int x, int y, int ch)
{
  printf ("wadd_char_xy_col %c %2d %2d %x\n", ch & 0xff, x, y, ch >> 8);
}

void
A4GL_LL_screen_mode ()
{
}

void
A4GL_LL_screen_update (void)
{
// Update the physical screen
  printf ("screen update\n");
}

void
A4GL_LL_screen_refresh (void)
{
// Blank the screen and redraw from scratch
  printf ("screen refresh\n");
}

int
A4GL_LL_colour_code (int c)
{
  printf ("color_code\n");
}



void
A4GL_LL_error_box (char *str, int attr)
{
  printf ("error_box\n");
}

void *
A4GL_LL_display_form (void *f, int attr)
{
  printf ("display_form\n");
}

void
A4GL_LL_h_disp_opt (ACL_Menu * menu, ACL_Menu_Opts * opt1, int offset, int y,
		    int type)
{
  printf ("h_disp_opt\n");
}

void
A4GL_LL_clr_menu_disp (ACL_Menu * menu)
{
  printf ("clr_menu_Disp\n");
}

void
A4GL_LL_out_linemode (char *s)
{
  printf ("out_linemode : %s\n", s);
}


void
A4GL_LL_sleep (int n)
{
  printf ("sleep %d\n", n);
}


void
A4GL_LL_make_window_top (void *w)
{
  printf ("make_window_top\n");
}

int
A4GL_LL_screen_width (void)
{
  return 80;
}

int
A4GL_LL_screen_height (void)
{
  return 24;
}

void
A4GL_LL_set_bkg (void *win, int attr)
{
  printf ("set_bkg\n");
}


int
A4GL_LL_decode_aubit_attr (int a, char s)
{
  printf ("decode_aubit_Attr\n");
}

int
A4GL_LL_menu_loop (void *menuv)
{
  printf ("A4GL_menu_loop\n");
  return 3;
}

int
A4GL_LL_start_prompt (void *vprompt, int ap, int c, int h, int af)
{
  printf ("start prompt\n");
}

int
A4GL_LL_prompt_loop (void *vprompt, int timeout)
{
  printf ("prompt loop\n");
}




void *
A4GL_LL_make_field (int frow, int fcol, int rows, int cols)
{

}


void *
A4GL_LL_make_label (int frow, int fcol, char *label)
{

}

int
A4GL_LL_set_new_page (void *field, int n)
{

}


void
A4GL_LL_set_field_userptr (void *field, void *ptr)
{
}

void *
A4GL_LL_get_field_userptr (void *field)
{
}

void
A4GL_LL_set_field_attr (void *field)
{
}



void *
A4GL_LL_new_form (void **fields)
{
}

void
A4GL_LL_set_form_userptr (void *form, void *data)
{
}

void *
A4GL_LL_get_form_userptr (void *form)
{
}



char *
A4GL_LL_field_buffer (void *field, int n)
{
}


void
A4GL_LL_set_field_buffer (void *field, int n, char *str, char *orig)
{
}



int
A4GL_LL_field_opts (void *field)
{

}


int
A4GL_LL_set_field_opts (void *field, int oopt)
{

}


void
A4GL_LL_set_field_fore (void *field, int attr)
{
}


void
A4GL_LL_set_field_back (void *field, int attr)
{
}


void
A4GL_LL_set_current_field (void *form, void *field)
{
}


void
A4GL_LL_set_carat (void *form)
{
}


int
A4GL_LL_getch_swin (char*why)
{
}

int
A4GL_LL_get_carat (void *form)
{
}

int
A4GL_LL_int_form_driver (void *mform, int mode)
{
}

void *
A4GL_LL_current_field (void *form)
{
}

void
A4GL_LL_set_form_page (void *form, int page)
{
}

void
A4GL_LL_form_page (void *form)
{
}
void *
A4GL_LL_create_errorwindow (int h, int w, int y, int x, int attr, char *str)
{
}

void
A4GL_LL_delete_errorwindow (void *curr_error_window)
{

}

int
A4GL_LL_field_status (void *field)
{
}


int
A4GL_LL_dump_screen (int n)
{
  return 0;
}

int
A4GL_LL_set_field_status (void *f, int stat)
{
}


void
A4GL_LL_move_window (void *w, int y, int x)
{
}


void
A4GL_LL_hide_window (void *w)
{
}
void
A4GL_LL_show_window (void *w)
{
}

void
A4GL_LL_gui_run_til_no_more ()
{
}
