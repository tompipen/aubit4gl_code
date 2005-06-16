#include <stdlib.h>
#include <string.h>
#include "a4gl_libaubit4gl.h"
#include "hl_proto.h"
#include "a4gl_API_lowlevel.h"
#include "a4gl_API_ui_lib.h"
#include "aubit_noform.h"
#ifdef XCURSES
#include <xpanel.h>
#else
#include <panel.h>
#endif

void A4GL_LL_screen_refresh (void);

// we need to fix some bits on here - 
// we need to set curr_width, curr_height,curr_border
// for now - we'll just use these defaults and hope for the 
// best....
//
#define NEED_CURRWHB 24,80,0,1

/* A lot of this is copied from ncurses libform and hacked...

 That software contains :
 ****************************************************************************
 * Copyright (c) 1998,2000 Free Software Foundation, Inc.                   *
 *                                                                          *
 * Permission is hereby granted, free of charge, to any person obtaining a  *
 * copy of this software and associated documentation files (the            *
 * "Software"), to deal in the Software without restriction, including      *
 * without limitation the rights to use, copy, modify, merge, publish,      *
 * distribute, distribute with modifications, sublicense, and/or sell       *
 * copies of the Software, and to permit persons to whom the Software is    *
 * furnished to do so, subject to the following conditions:                 *
 *                                                                          *
 * The above copyright notice and this permission notice shall be included  *
 * in all copies or substantial portions of the Software.                   *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *
 * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *
 *                                                                          *
 * Except as contained in this notice, the name(s) of the above copyright   *
 * holders shall not be used in advertising or otherwise to promote the     *
 * sale, use or other dealings in this Software without prior written       *
 * authorization.                                                            
 ****************************************************************************
 *   Author:  Juergen Pfeifer, 1995,1997                                    *
 *   Contact: http://www.familiepfeifer.de/Contact.aspx?Lang=en             *
 ****************************************************************************
*/

/*

       int A4GL_form_set_current_field(FORM *form, FIELD *field);
       FIELD *A4GL_form_current_field(const FORM *);
       int A4GL_form_set_form_page(FORM *form, int n);
       int A4GL_form_form_page(const FORM *form);
       int A4GL_form_dynamic_field_info(const FIELD *field, int *rows, int *cols, *max);
       int A4GL_form_set_field_fore(FIELD *field, chtype attr);
       chtype A4GL_form_field_fore(const FIELD *field);
       int A4GL_form_set_field_back(FIELD *field, chtype attr);
       chtype A4GL_form_field_back(const FIELD *field);
       int  A4GL_form_set_field_buffer(FIELD  *field,  int  buf, const char *value);
       char *A4GL_form_field_buffer(const FIELD *field, int buffer);
       int A4GL_form_set_field_status(FIELD *field, bool status);
       bool A4GL_form_field_status(const FIELD *field);
       int A4GL_form_set_max_field(FIELD *field, int max);
       int A4GL_form_set_field_opts(FIELD *field, OPTIONS opts);
       int A4GL_form_field_opts_on(FIELD *field, OPTIONS opts);
       int A4GL_form_field_opts_off(FIELD *field, OPTIONS opts);
       OPTIONS A4GL_form_field_opts(const FIELD *field);
       int A4GL_form_set_field_userptr(FIELD *field, void*userptr);
       void *A4GL_form_field_userptr(const FIELD *field);
       int A4GL_form_form_driver(FORM *form, int c);
       int A4GL_form_set_form_userptr(FORM *form, void *userptr);
       void* A4GL_form_form_userptr(const FORM *form);
       FORM *A4GL_form_new_form(FIELD **fields);
       int A4GL_form_free_form(FORM *form);
       int A4GL_form_pos_form_cursor(FORM *form);
       int A4GL_form_post_form(FORM *form);
       int A4GL_form_unpost_form(FORM *form);
       int A4GL_form_set_form_win(FORM *form, WINDOW *win);
       WINDOW *A4GL_form_form_win(const FORM *form);
       int A4GL_form_set_form_sub(FORM *form, WINDOW *sub);
       WINDOW *A4GL_form_form_sub(const FORM *form);
       int A4GL_form_scale_form(const FORM *form, int *rows, int *columns);
       int A4GL_form_set_new_page(FIELD *field, bool new_page_flag);
       bool A4GL_form_new_page(const FIELD *field);
       FIELD *A4GL_form_new_field(int height, int width, int toprow, int leftcol, int offscreen, int nbuffers);

*/


#define Get_Form_Window(form) ((form)->sub?(form)->sub:((form)->win?(form)->win:stdscr))
#define ALL_FORM_OPTS  (                \
                        O_NL_OVERLOAD  |\
                        O_BS_OVERLOAD   )

#define ALL_FIELD_OPTS (           \
                        O_VISIBLE |\
                        O_ACTIVE  |\
                        O_PUBLIC  |\
                        O_EDIT    |\
                        O_WRAP    |\
                        O_BLANK   |\
                        O_AUTOSKIP|\
                        O_NULLOK  |\
                        O_PASSOK  |\
                        O_STATIC   )


static void
redraw_field (FIELD * f)
{
  int x, y;
  int attr;
  char **ptr;
  static char *buff = 0;
  static int buff_len = 0;
  int row;
  char *xbuff;
  WINDOW *wot;

  A4GL_debug ("Redraw field : %p", f);


  if (f == 0)
    {
      char *ptr = 0;
      *ptr = 0;
      A4GL_debug ("Can't draw nothing...");
      return;
    }


  if (f->form == 0)
    {
      A4GL_debug ("Its not been posted yet..");
      return;
    }

  ptr = (char **) f->buf;
  if ((f->cols * f->rows) > buff_len)
    {
      buff_len = (f->cols * f->rows);
      buff = realloc (buff, buff_len + 1);
    }

  y = f->frow;
  x = f->fcol;

  wot = Get_Form_Window (f->form);
  /*
     warning: assignment from incompatible pointer type
     PANEL *wot;
     #define Get_Form_Window(form) ((form)->sub?(form)->sub:((form)->win?(form)->win:stdscr))

     Mike:
     but as its just a pointer - it does no harm (panels can be used for 
     windows in curses anyway)
     Changed to a WINDOW *...

     Looks like not commited yet - check again later, if still get warning, change
     to WINDOW *...

   */

  memset (buff, 0, buff_len);

  if ((!(f->opts & O_VISIBLE)) || (!(f->opts & O_PUBLIC))
      || (f->fore & A_INVIS))
    {
      A4GL_debug ("ITS INVISIBLE!");
      memset (buff, ' ', (f->cols * f->rows));
      buff[f->cols * f->rows] = 0;
    }
  else
    {

      memcpy (buff, ptr[0], (f->cols * f->rows));
    }

  buff[(f->cols * f->rows)] = 0;

  attr = (f->back | f->fore) & 0xffffff00;
  if (f->rows > 1)
    {
      xbuff = malloc (f->cols + 1);
      for (row = 0; row < f->rows; row++)
	{
	  strncpy (xbuff, &buff[row * f->cols], f->cols);
	  xbuff[f->cols] = 0;
	  A4GL_debug ("Printing : '%s' @ %d,%d (multi line)\n", xbuff, x, y);
	  A4GL_wprintw_window (wot, attr, x, y + row, NEED_CURRWHB, "%s", xbuff);	// @ fixme - needs curr_width, curr_height and curr_border?
	  A4GL_debug ("Print0\n");
	}
      free (xbuff);
    }
  else
    {
      //A4GL_debug ("Printing : %s @ %d,%d %x %x w=%p wot=%p\n", buff, x, y,f->opts,f->fore,w,w);
      A4GL_debug ("Print1 %p '%s'\n", wot, buff);
      A4GL_wprintw_window (wot, attr, x + 1, y + 1, NEED_CURRWHB, "%s", buff);
    }
  //wrefresh(w);
  //A4GL_LL_screen_update();

}

static void
redraw_current_field (FORM * f)
{
  redraw_field (f->current);
}


static void
redraw_form (FORM * f)
{
  int a;
  for (a = 0; a < f->maxfield; a++)
    {
      redraw_field (f->field[a]);
    }
}





FIELD *
A4GL_form_current_field (const FORM * f)
{
  return f->current;
}


chtype
A4GL_form_field_back (const FIELD * field)
{
  return field->back;
}

char *
A4GL_form_field_buffer (const FIELD * field, int buffer)
{
  char **ptr;
  ptr = (char **) field->buf;
  return ptr[buffer];
}

chtype
A4GL_form_field_fore (const FIELD * field)
{
  return field->fore;
}

OPTIONS
A4GL_form_field_opts (const FIELD * field)
{
  return field->opts;
}

int
A4GL_form_field_opts_off (FIELD * field, OPTIONS opts)
{
  field->opts = field->opts & ~opts;
  if (field->form)
    redraw_field (field);
  return E_OK;
}

int
A4GL_form_field_opts_on (FIELD * field, OPTIONS opts)
{
  field->opts |= opts;
  return E_OK;
}

bool
A4GL_form_field_status (const FIELD * field)
{
  return field->status;
}


void *
A4GL_form_field_userptr (const FIELD * field)
{
  return field->usrptr;
}



int
A4GL_form_form_page (const FORM * form)
{
  return form->curpage;
}


void *
A4GL_form_form_userptr (const FORM * form)
{
  return form->usrptr;
}


int
A4GL_form_set_current_field (FORM * form, FIELD * field)
{
  if (form->current != field)
    {
      form->current = field;
      form->curcol = 0;
    }
  return E_OK;
}


int
A4GL_form_set_field_back (FIELD * field, chtype attr)
{
  field->back = attr;
  if (field->form)
    redraw_field (field);
  return E_OK;
}



int
A4GL_form_set_field_buffer (FIELD * field, int buf, const char *value)
{
  char **ptr;
  char *cptr;
  int l;
  ptr = (char **) field->buf;
  A4GL_debug
    ("set_field_buffer   ptr=%p buf=%d ptr[buf]=%p &ptr[buf]=%p = %s\n", ptr,
     buf, ptr[buf], &ptr[buf], value);
  cptr = ptr[buf];


  /* For a static field - we need to make sure we pad it to the size of the field */

  memset (cptr, ' ', field->cols * field->rows);
  l = field->cols * field->rows;
  if (strlen (value) < l)
    l = strlen (value);
  strncpy (cptr, value, l);
  cptr[field->cols * field->rows] = 0;


  A4GL_debug ("FIELD BUFFER SET TO '%s' from '%s' for field width %d", cptr,
	      value, field->cols * field->rows);




  if (field->form)
    redraw_field (field);
  return E_OK;
}



int
A4GL_form_set_field_fore (FIELD * field, chtype attr)
{
  field->fore = attr;
  if (field->form)
    redraw_field (field);
  return E_OK;
}


int
A4GL_form_set_field_opts (FIELD * field, OPTIONS opts)
{
  field->opts = opts;
  return E_OK;
}

int
A4GL_form_set_field_status (FIELD * field, bool status)
{
  field->status = status;
  return E_OK;
}

int
A4GL_form_set_field_userptr (FIELD * field, void *userptr)
{
  field->usrptr = userptr;
  return E_OK;
}


int
A4GL_form_set_form_sub (FORM * form, WINDOW * sub)
{
  A4GL_debug ("form_set_Form_sub=%p", sub);
  form->sub = sub;
  return E_OK;
}

WINDOW *
A4GL_form_form_sub (const FORM * form)
{
  return form->sub;
}


int
A4GL_form_set_form_userptr (FORM * form, void *userptr)
{
  form->usrptr = userptr;
  return E_OK;
}

int
A4GL_form_set_form_win (FORM * form, WINDOW * win)
{
  A4GL_debug ("form_set_Form_win=%p", win);
  form->win = win;
  return E_OK;
}


int
A4GL_form_set_max_field (FIELD * field, int max)
{
  field->maxgrow = max;
  return E_OK;
}


int
A4GL_form_set_new_page (FIELD * field, bool new_page_flag)
{
  field->page = -1;
  return E_OK;
}


int
A4GL_form_set_form_page (FORM * form, int n)
{
  form->curpage = n;
  //form->curcol=0;
  redraw_form (form);
  return E_OK;
}


FIELD *
A4GL_form_new_field (int height, int width, int toprow, int leftcol,
		     int offscreen, int nbuffers)
{
  FIELD *f;
  int a;
  char **ptr;

  f = malloc (sizeof (FIELD));
  f->status = 0;
  f->rows = height;
  f->cols = width;
  f->frow = toprow;
  f->fcol = leftcol;
  f->drows = height;
  f->dcols = width;
  f->maxgrow = 0;
  f->just = 0;
  f->page = 0;
  f->index = -1;
  f->pad = ' ';
  f->fore = A_NORMAL;
  f->back = A_NORMAL;
  f->opts = ALL_FIELD_OPTS;
  f->snext = 0;
  f->sprev = 0;
  f->link = 0;
  f->form = 0;
  f->type = 0;
  f->arg = 0;
  f->usrptr = 0;
  f->nrow = offscreen;
  f->nbuf = nbuffers;
  f->buf = malloc (sizeof (char *) * (nbuffers + 1));
  ptr = (char **) f->buf;

  for (a = 0; a < nbuffers + 1; a++)
    {
      //char *cptr;
      ptr[a] = malloc (width * height + 1);
      A4GL_form_set_field_buffer (f, a, "");
    }

  return f;
}




int
A4GL_form_scale_form (const FORM * form, int *rows, int *columns)
{
  int a;
  int maxx = 0;
  int maxy = 0;

  if (form == 0)
    return 0;

  for (a = 0; a < form->maxfield; a++)
    {
      if (form->field[a]->fcol + form->field[a]->cols > maxx)
	{
	  maxx = form->field[a]->fcol + form->field[a]->cols;
	}
      if (form->field[a]->frow + form->field[a]->rows > maxy)
	{
	  maxy = form->field[a]->frow + form->field[a]->rows;
	}

    }
  *rows = maxy;
  *columns = maxx;
  return E_OK;
}



int
A4GL_form_unpost_form (FORM * form)
{
  A4GL_debug ("unpost form");
  werase (form->sub);
  form->status &= ~1;
  return E_OK;
}



int
A4GL_form_post_form (FORM * form)
{
  WINDOW *formwin;
  //int err;
  //int page;
  A4GL_debug ("post_form");
  if ((form->status & 1) == 1)
    return E_POSTED;
  formwin = Get_Form_Window (form);

  if ((form->cols > getmaxx (formwin)) || (form->rows > getmaxy (formwin)))
    return (E_NO_ROOM);

  form->curcol = 0;
  form->current = 0;

  redraw_form (form);

  A4GL_LL_screen_update ();


  form->status |= 1;

  if (form->current)
    redraw_current_field (form);
  redraw_form (form);

  if (A4GL_isyes (acl_getenv ("OLDREFRESH")))
    {
      wrefresh (formwin);	/* @ */
    }
  else
    {
      A4GL_LL_screen_update ();
    }
  return E_OK;
}


static FORM default_form = {
  0,				/* status     */
  0,				/* rows       */
  0,				/* cols       */
  0,				/* currow     */
  0,				/* curcol     */
  0,				/* toprow     */
  0,				/* begincol   */
  -1,				/* maxfield   */
  -1,				/* maxpage    */
  -1,				/* curpage    */
  ALL_FORM_OPTS,		/* opts       */
  (WINDOW *) 0,			/* win        */
  (WINDOW *) 0,			/* sub        */
  (WINDOW *) 0,			/* w          */
  (FIELD **) 0,			/* field      */
  (FIELD *) 0,			/* current    */
  (_PAGE *) 0,			/* page       */
  (char *) 0,			/* usrptr     */
  NULL,				/* forminit   */
  NULL,				/* formterm   */
  NULL,				/* fieldinit  */
  NULL				/* fieldterm  */
};


FORM *
A4GL_form_new_form (FIELD ** fields)
{
  FORM *form;
  int a;

  form = (FORM *) malloc (sizeof (FORM));
  memcpy (form, &default_form, sizeof (FORM));

  for (a = 0; fields[a]; a++)
    {
      A4GL_debug ("a=%d field[a]=%p\n", a, fields[a]);
    }
  form->maxfield = a;

  form->field = malloc (sizeof (FIELD *) * form->maxfield);
  for (a = 0; fields[a]; a++)
    {
      form->field[a] = fields[a];
      fields[a]->index = a;
      fields[a]->form = form;
    }
  return form;
}



int
A4GL_form_free_form (FORM * form)
{
  int a;
  int c;
  char **ptr;
  for (a = 0; a < form->maxfield; a++)
    {
      ptr = (char **) form->field[a]->buf;
      for (c = 0; c < form->field[a]->nbuf; c++)
	{
	  if (ptr[c])
	    free (ptr[c]);
	}
      free (form->field[a]->buf);
      free (form->field[a]);
    }
  free (form);
  return E_OK;
}



int
A4GL_form_pos_form_cursor (FORM * form)
{
//char buff[245];
  A4GL_debug ("A4GL_form_pos_form_cursor");
  if (form->current)
    {
      WINDOW *w;
      int incr;
      if (UILIB_A4GL_iscurrborder ())
	incr = 1;
      else
	incr = 0;
      //w=form->sub;
      w = Get_Form_Window (form);
      //(void *) panel_window(A4GL_window_on_top_ign_menu ());
      if (w)
	{
	  wmove (w, form->current->frow + incr,
		 form->current->fcol + form->curcol + incr);
	  wcursyncup (w);
	  wrefresh (w);
	}
    }
  else
    {
      A4GL_debug ("pos_form_cursor called when form current = 0....");
    }
  return E_OK;
}


int
A4GL_form_field_info (const FIELD * f, int *rows, int *cols, int *frow,
		      int *fcol, int *nrow, int *nbuf)
{
  *rows = f->rows;
  *cols = f->cols;
  *frow = f->frow;
  *fcol = f->fcol;
  *nrow = f->nrow;
  *nbuf = f->nbuf;
  return 1;
}



int
A4GL_form_dynamic_field_info (const FIELD * field, int *rows, int *cols,
			      int *max)
{
  *rows = field->drows;
  *cols = field->dcols;
  *max = field->maxgrow;
  return E_OK;
}




int
A4GL_form_form_driver (FORM * form, long c)
{
  char *cfield_buffer;
  FIELD *current;
  int field_length;
  int a;
  A4GL_debug ("TTT - form_driver %d %x", c, c);
  if (c >= 0x100 && c < 0x6000)
    {
      A4GL_debug ("FX1 INVALID CALL TO FORM DRIVER : %x", c);
      A4GL_pause_execution ();
    }
  if (c == REQ_FIRST_FIELD)
    {
      A4GL_debug ("REQ FIRST FIELD detected");
    }

  current = form->current;


  if (current == 0 && c != REQ_FIRST_FIELD)
    {
      A4GL_form_form_driver (form, REQ_FIRST_FIELD);
      if (current == 0)
	{
	  return -1;
	}
    }

  if (c != REQ_FIRST_FIELD)
    {
      cfield_buffer = A4GL_form_field_buffer (current, 0);
      field_length = strlen (cfield_buffer);
    }
  else
    {
      A4GL_debug ("Looking for first - maxfield=%d\n", form->maxfield);
      for (a = 0; a < form->maxfield; a++)
	{
	  int fopts;
	  fopts = form->field[a]->opts;

	  A4GL_debug ("fopts=%x %x %x %x \n", fopts, (fopts & O_VISIBLE),
		      (fopts & O_EDIT), (fopts & O_ACTIVE));

	  if ((fopts & O_VISIBLE) && (fopts & O_EDIT) && (fopts & O_ACTIVE))
	    {
	      form->current = form->field[a];
	      form->curcol = 0;
	      break;
	    }
	}
      return E_OK;
    }



  if (c >= ' ' && c <= 0xff)
    {

      A4GL_debug ("----> FIELD WAS '%s' %d ", cfield_buffer,
		  current->maxgrow);

      // Add it as a character..

      if (current->maxgrow != 0)
	{
	  A4GL_debug ("T1");
	  if (form->curcol < field_length)
	    {
	      A4GL_debug ("T2");
	      if ((form->current->opts & (O_BLANK)) && form->curcol == 0)
		{
		  A4GL_debug ("T2.1");
		  memset (cfield_buffer, ' ', field_length);
		}

	      if ((form->status & 2) == 0)
		{		// Overwrite mode...
		  A4GL_debug ("T2.2");
		  A4GL_debug ("OVERWRITE CHARACTER : %c @ %d", c,
			      form->curcol);
		  cfield_buffer[form->curcol] = c;
		  A4GL_debug ("%s", cfield_buffer);
		}
	      else
		{
		  char *rest_of_line;
		  A4GL_debug ("T2.3");
		  A4GL_debug ("INSERT CHARACTER : %c", c);
		  rest_of_line = strdup (&cfield_buffer[form->curcol]);
		  cfield_buffer[form->curcol] = c;
		  if (strlen (rest_of_line))
		    {
		      strncpy (&cfield_buffer[form->curcol + 1], rest_of_line,
			       strlen (rest_of_line) - 1);
		    }
		}

	      /* Now advance one character */
	      if (form->curcol < (field_length - 1))
		{
		  A4GL_debug ("T2.4");
		  form->curcol++;
		}
	    }

	}
      else
	{
	  A4GL_debug ("T3");
	  if (form->curcol <= field_length - 1)
	    {
	      A4GL_debug ("T4");
	      if ((form->current->opts & (O_BLANK)) && form->curcol == 0)
		{
		  memset (cfield_buffer, ' ', field_length);
		}

	      if ((form->status & 2) == 0)
		{		// Overwrite mode...
		  A4GL_debug ("OVERWRITE CHARACTER : %c", c);
		  cfield_buffer[form->curcol] = c;
		}
	      else
		{
		  char *rest_of_line;
		  A4GL_debug ("INSERT CHARACTER : %c", c);
		  rest_of_line = strdup (&cfield_buffer[form->curcol]);
		  cfield_buffer[form->curcol] = c;
		  if (strlen (rest_of_line))
		    {
		      strncpy (&cfield_buffer[form->curcol + 1], rest_of_line,
			       strlen (rest_of_line) - 1);
		    }
		}

	      /* Now advance one character */
	      if (form->curcol < (field_length - 1))
		{
		  form->curcol++;
		}
	    }
	}



      A4GL_debug ("T5");
      A4GL_debug ("----> FIELD NOW '%s'", cfield_buffer);
      redraw_current_field (form);
      A4GL_debug ("T6");
      return E_OK;
    }


  switch (c)
    {
    case REQ_BEG_FIELD:
      form->curcol = 0;
      break;

    case REQ_END_FIELD:
      {
	char *x;
	x = strdup (cfield_buffer);
	A4GL_trim (x);
	form->curcol = strlen (x);
	free (x);
      }
      break;


    case REQ_CLR_EOF:
      memset (&cfield_buffer[form->curcol], ' ', field_length - form->curcol);
      break;


    case REQ_CLR_FIELD:
      memset (cfield_buffer, ' ', field_length);
      form->curcol = 0;

      break;


    case REQ_DEL_CHAR:
      {
	char *ptr1;		// The whole thing
	char *ptr2;		// The bit after the delete
	ptr1 = strdup (cfield_buffer);
	memset (&ptr1[form->curcol], ' ', field_length - form->curcol);
	ptr2 = strdup (&cfield_buffer[form->curcol + 1]);
	memcpy (&ptr1[form->curcol], ptr2, strlen (ptr2));
	strcpy (cfield_buffer, ptr1);
	free (ptr1);
	free (ptr2);
      }

      break;


    case REQ_DEL_PREV:
      if (form->curcol)
	{
	  char *ptr1;		// The whole thing
	  char *ptr2;		// The bit after the delete
	  form->curcol--;
	  ptr1 = strdup (cfield_buffer);
	  memset (ptr1, ' ', field_length);
	  ptr2 = strdup (&cfield_buffer[form->curcol + 1]);
	  memcpy (&ptr1[form->curcol], ptr2, strlen (ptr2));
	  strcpy (cfield_buffer, ptr1);
	  free (ptr1);
	  free (ptr2);
	}
      break;

    case REQ_FIRST_FIELD:
      A4GL_debug ("REQ_FIRST_FIELD");
      for (a = 0; a < form->maxfield; a++)
	{
	  int fopts;
	  fopts = form->field[a]->opts;
	  A4GL_debug ("fopts=%x %x %x %x %x\n", fopts, (fopts & O_VISIBLE),
		      (fopts & O_EDIT), (fopts & O_ACTIVE));
	  if ((fopts & O_VISIBLE) && (fopts & O_EDIT) && (fopts & O_ACTIVE))
	    {
	      form->current = form->field[a];
	      form->curcol = 0;
	      break;
	    }
	}
      break;


    case REQ_FIRST_PAGE:
      A4GL_debug ("REQ_FIRST_PAGE");
      if (form->curpage != 0)
	{
	  form->curpage = 0;
	  redraw_form (form);
	}
      form->curcol = 0;
      break;


    case REQ_INS_MODE:
      A4GL_debug ("INSERT MODE");
      if ((form->status & 2) == 0)
	form->status += 2;
      break;


    case REQ_NEXT_CHAR:
      if (form->curcol < field_length - 1)
	form->curcol++;
      break;


    case REQ_OVL_MODE:
      A4GL_debug ("OVERWRITE MODE");
      if (form->status & 2)
	form->status -= 2;
      break;


    case REQ_PREV_CHAR:
      form->curcol--;
      if (form->curcol < 0)
	form->curcol = 0;
      break;


    case REQ_VALIDATION:
      break;
    }


  redraw_current_field (form);
  return E_OK;
}
