/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: disp_arr.c,v 1.9 2003-07-18 16:17:32 mikeaubury Exp $
#*/

/**
 * @file
 * Implementation of Display Array
 *
 * @todo Doxygen A4GL_comments to add
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#include "a4gl_lib_ui_gtk_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern int m_lastkey;
int cmode = 0;
struct s_disp_arr *curr_arr;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

struct struct_screen_record *A4GL_get_srec_gtk (char *);
void A4GL_disp_arr_fields (int n, int fonly, int attr, ...);
void A4GL_idisp_arr_fields (int n, int fonly, int attr, ...);
void A4GL_set_arr_fields (int n, int attr, ...);
void A4GL_idraw_arr_all (struct s_inp_arr *disp);
void A4GL_idraw_arr (struct s_inp_arr *disp, int type, int no);
void A4GL_iclear_srec_line (struct struct_screen_record *srec, int line);

void A4GL_set_array_mode (int type);
//int A4GL_disp_arr (struct s_disp_arr *disp, void *ptr, char *srecname, int attrib, va_list * ap);

//int A4GL_disp_arr_ap (struct s_disp_arr *disp, void *ptr, char *srecname, int attrib, va_list * ap);
/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Clear a screen record.
 *
 * @param srec The screen record information structure.
 */
static void
clear_srec (struct struct_screen_record *srec)
{
  int a;
  int b;
/*  char empty[2] = ""; */
  char srec1[256];
  A4GL_debug ("Clearing %s", srec->name);
  strcpy (srec1, srec->name);
  strcat (srec1, ".*");
  A4GL_debug ("Got fields as %s", srec1);
  for (b = 0; b < srec->dim; b++)
    {
      for (a = 0; a < srec->attribs.attribs_len + 1; a++)

	{

	  A4GL_push_char (" ");

	}
      A4GL_debug ("disp_fields(%d,%d,%s,%d,%d)", srec->attribs.attribs_len + 1, 0,
	     srec1, b, 0, 0);
      A4GL_disp_arr_fields (srec->attribs.attribs_len + 1, 0, 0, srec1, b + 1, 0,
		       0);
    }
}

/**
 *
 * @param disp A pointer to the display array inforation strutcure
 * @param type
 * @param no
 */
static void
draw_arr (struct s_disp_arr *disp, int type, int no)
{
  char srec2[256];
  int topline;
  int scr_line;
  int first_only = 0;
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("in draw_arr %p %d %d", disp, type, no);
  }
#endif
  if (type < 0)
    {
      type = 0 - type;
      first_only = 1;
    }
  topline = disp->arr_line - disp->scr_line + 1;
  scr_line = no - topline + 1;
  strcpy (srec2, disp->srec->name);
  strcat (srec2, ".*");
  if (type == 2)
    {
      A4GL_debug ("calling set_arr_Fields");
      A4GL_set_arr_fields (disp->nbind, 0, srec2, scr_line, 0, 0);
#ifdef DEBUG
      /* {DEBUG} */
      {
 A4GL_debug ("Done");
      }
#endif
      return;
    }

  if (first_only)
    A4GL_push_bind (disp->binding, 1, no, disp->arr_elemsize);
  else
    A4GL_push_bind (disp->binding, disp->nbind, no, disp->arr_elemsize);

  A4GL_debug ("Print array no %d to scr %d", no, disp->scr_line);
  A4GL_debug ("calling disp_arR_fields");

  if (disp->highlight)
    {
      A4GL_debug ("With highlight");
      A4GL_disp_arr_fields (disp->nbind, first_only, type * 0x400, srec2, scr_line,
		       0, 0);
    }
  else
    {
      A4GL_debug ("Without highlight");
      A4GL_disp_arr_fields (disp->nbind, first_only, 0, srec2, scr_line, 0, 0);
    }
}

/**
 * Draw / show a screen array.
 *
 * @param disp
 */
static void
draw_arr_all (struct s_disp_arr *disp)
{
  int a;
  int topline;
  topline = disp->arr_line - disp->scr_line + 1;
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("***** Draw_arr_all topline=%d", topline);
  }
#endif
  for (a = 0; a < disp->srec->dim; a++)
    {
      if (a + topline < disp->no_arr)

	{

	  /* draw_arr (disp, a + topline == disp->arr_line, a + topline); */
	  draw_arr (disp, 0, a + topline);

#ifdef DEBUG
	  /* {DEBUG} */
	  {
	    A4GL_debug ("after draw_arr (6)");
	  }
#endif
	}
    }

  draw_arr (disp, 1, disp->arr_line);
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("after draw_arr (7)");
  }
#endif
}

/**
 * 
 * @param arr
 * @param redisp
 */
static void
redisplay_arr (struct s_disp_arr *arr, int redisp)
{
  if (redisp == 1)
    {
      A4GL_debug ("Redisplay one");
      draw_arr (arr, 0, arr->last_arr);
#ifdef DEBUG
      /* {DEBUG} */
      {
 A4GL_debug ("after draw_arr (4)");
      }
#endif
      A4GL_debug ("Display one");
      draw_arr (arr, 1, arr->arr_line);
#ifdef DEBUG
      /* {DEBUG} */
      {
 A4GL_debug ("after draw_arr (5)");
      }
#endif
    }
  if (redisp == 2)
    {
      A4GL_debug ("Redisplay all");
      draw_arr_all (arr);
    }
}

/**
 * Assigns the ype of the instruction that are using the array.
 * 
 * @param type The type of array usage :
 *   - I : Input.
 *   - D : Display.
 */
void
A4GL_set_array_mode (int type)
{
  cmode = type;
}


/**
 * The display array loop.
 *
 * Stay in loop until the user type a command that finishes the instruction
 * (Accept, etc).
 *
 * @param arr A pointer to the display array information structure.
 */
static int
disp_loop (struct s_disp_arr *arr)
{
  struct s_form_dets *form;
  int a;
  int k;
  int action;
  int redisp;
  curr_arr = arr;
  form = arr->currform;
  m_lastkey = 0;
  A4GL_set_array_mode ('D');

  a = 0;

#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Currform=%p (s_form_dets)", form);
  }
#endif
  if (form != A4GL_get_curr_form (1))
    {
      A4GL_exitwith ("Input form is not the current form!");
      exit (0);
    }

  if (arr->cntrl != 0)
    {
      a = arr->cntrl;
      arr->cntrl = 0;
    }
  else
    {
      draw_arr (arr, 2, arr->arr_line);
      draw_arr (arr, -1, arr->arr_line);


      while (1)
	{

	  action = A4GL_user_has_done_something ();

	  /* printf("Action=%d\n",action); */
	  if (action)
	    {
	      printf ("ACTION\n");
	      fflush (stdout);
	      break;
	    }

	  a4gl_usleep (100);
	  if (gtk_events_pending ())
	    gtk_main_iteration ();
	}


      if (action == 1)
	{			/*  key pressed... */
	  k = A4GL_which_key ();
	  //printf ("KEY PRESSED 0x%x\n", k);

	  A4GL_clear_something ();

	  k = A4GL_gui_proc_key_display_array (k);
	  //printf ("k=%x Down=%x Up=%x\n", k, GDK_Down, GDK_Up);

	  if (k == 0)
	    {
	      A4GL_debug ("** Returning k=0");
	      return 0;
	    }

	  if (a < 0)
	    {
	      A4GL_debug ("** Returning %d\n", a);
	      return a;
	    }

	  printf ("A=%d\n", a);
	  arr->cntrl = k;
	  return -90;
	}
      else
	{
	  void *p;
	  printf ("Not a key..");
	  p = (void *) A4GL_get_which_field ();
	  if (gtk_object_get_data (p, "ARRAY") == arr)
	    {
	      GtkAdjustment *a;
	      /*  Its our scroll bar... */

	      a = gtk_range_get_adjustment (p);

	      arr->last_arr = arr->arr_line;
	      arr->arr_line = (int) a->value;
	      A4GL_debug ("***  Set to %d value=%f max=%f\n", arr->arr_line,
		     a->value, a->upper);

	      if (arr->last_arr - arr->arr_line == 1)
		arr->scr_line--;
	      if (arr->last_arr - arr->arr_line == -1)
		arr->scr_line++;



	      if (arr->scr_line <= 0)
		arr->scr_line = 1;
	      if (arr->scr_line > arr->srec->dim)
		arr->scr_line = arr->srec->dim;
	      if (arr->scr_line > arr->arr_line)
		arr->scr_line = 1;

	      while (arr->arr_line - arr->scr_line + arr->srec->dim >
		     arr->no_arr && arr->scr_line < arr->srec->dim)
		arr->scr_line++;
	      while (arr->arr_line - arr->scr_line + arr->srec->dim <= 0
		     && arr->scr_line > 1)
		arr->scr_line--;

	      redisplay_arr (arr, 2);
	      A4GL_debug
		("**** arr_line = %d scr_line=%d dim=%d no_arr=%d arr->last_arr=%d",
		 arr->arr_line, arr->scr_line, arr->srec->dim, arr->no_arr,
		 arr->last_arr);
	      A4GL_set_arr_curr (arr->arr_line);
	      A4GL_set_scr_line (arr->scr_line);
	    }
	  A4GL_clear_something ();
	  /* arr->cntrl=-10; */

	  return -11;
	}



      m_lastkey = a;
    }

  redisp = 0;

  switch (a)
    {
    case GDK_Down:
      A4GL_debug ("Key down");
      if (arr->arr_line < arr->no_arr)
	{
	  A4GL_debug ("****** Scroll Down");
	  arr->cntrl = 0 - GDK_Down;

	  return -11;

	}
      break;

    case 0 - GDK_Down:
      A4GL_debug ("Keydown +");
      arr->last_arr = arr->arr_line;
      arr->arr_line++;
      A4GL_debug ("Is really down %d", arr->arr_line);
      redisp = 1;
      arr->scr_line++;
      if (arr->scr_line > arr->srec->dim)
	{
	  arr->scr_line = arr->srec->dim;
	  redisplay_arr (arr, 2);
	}
      else
	{
	  redisplay_arr (arr, 1);
	}
      A4GL_set_arr_curr (arr->arr_line);
      A4GL_set_scr_line (arr->scr_line);

      return -10;
      break;

    case GDK_Up:
      A4GL_debug ("****** Scroll Up");
      if (arr->arr_line > 1)

	{

	  arr->cntrl = 0 - GDK_Up;

	  return -11;

	}
      break;

    case 0 - GDK_Up:
      arr->last_arr = arr->arr_line;
      arr->arr_line--;
      A4GL_debug ("Is really up");
      arr->scr_line--;
      if (arr->scr_line == 0)

	{

	  arr->scr_line = 1;

	  redisplay_arr (arr, 2);

	}
      else
	{
	  redisplay_arr (arr, 1);
	}
      A4GL_set_arr_curr (arr->arr_line);
      A4GL_set_scr_line (arr->scr_line);
      return -10;
      break;

    case 27:
      return 0;			/* escape */

    case 26:			/* control-z */
      return 0;
    }
  return -90;
}

/**
 * Execute a display array.
 *
 * This is part of run-time of TUI interface.
 *
 * @param dis A pointer to the display array information structure.
 * @param ptr
 * @param srecname Screen record name of the form
 * @param attrib The attributes
 */
int
A4GL_disp_arr_ap (void *dispv, void *ptr, char *srecname, int attrib, va_list * ap)
{
  int a;
  int nofields;
  GtkWidget **field_list;
struct s_disp_arr  *disp;
  disp=dispv;
  curr_arr = disp;
  A4GL_debug ("In A4GL_disp_arr : %s %p %p %d", srecname, ptr, disp, attrib);
  if (disp->srec == 0)
    {
      A4GL_debug ("disparr1");
      disp->srec = A4GL_get_srec_gtk (srecname);


      if (disp->srec == 0)
	{
	  A4GL_exitwith ("Screen record not found");
	  return 0;
	}

      disp->currform = A4GL_get_curr_form (1);


      A4GL_debug ("Trying to find scroll widget currform = %p", disp->currform);

      nofields =
 A4GL_gen_field_list_gtk (&field_list, (GtkWindow *) disp->currform, 1, ap);
      nofields++;
      A4GL_debug ("nofields=%d\n", nofields);

      if (nofields == 1)
	{
	  void *p;
	  A4GL_debug ("Setting range... %p dim=%d count=%d ", field_list[0],
		 disp->srec->dim, A4GL_get_count ());


	  /* This all changes for GTK 2.0
	     Don't know why its not updated straight away mind you... */
	  p = gtk_adjustment_new ((gfloat) 1,
				  (gfloat) 1,
				  (gfloat) A4GL_get_count (),
				  (gfloat) 1,
				  (gfloat) disp->srec->dim - 1, (gfloat) 0);
	  gtk_adjustment_set_value ((GtkAdjustment *) GTK_ENTRY (p), 1);
	  gtk_range_set_update_policy ((GtkRange *) field_list[0],
				       GTK_UPDATE_CONTINUOUS);

	  /*   GtkWidget **field_list;
	     void           gtk_range_set_update_policy      (GtkRange      *range,
	     GtkUpdateType  policy);
	   */

	  A4GL_gui_set_active (field_list[0], 1);
	  gtk_range_set_adjustment (GTK_RANGE (field_list[0]),
				    GTK_ADJUSTMENT (p));
	  A4GL_gui_run_til_no_more ();
	  gtk_adjustment_value_changed (p);
	  gtk_adjustment_changed (p);
	  A4GL_gui_run_til_no_more ();
	  gtk_object_set_data ((GtkObject *) field_list[0], "ARRAY", disp);

/*
void     gtk_object_set_data         (GtkObject      *object,
                                      const gchar    *key,
                                      gpointer        data);
*/
	}


#ifdef DEBUG
      /* {DEBUG} */
      {
 A4GL_debug ("disp->currform=%p", disp->currform);
      }
#endif
      disp->last_arr = -1;
      disp->scr_line = 1;
      disp->arr_line = 1;
      disp->cntrl = 1;
      disp->highlight = 1;

      A4GL_debug ("disparr2");
      if (disp->srec == 0)
	{
	  A4GL_exitwith ("Screen record does not exist");

	  return 0;

	}
      A4GL_debug ("disparr3");

      if (disp->srec->attribs.attribs_len != disp->nbind)
	{
	  A4GL_debug ("Too many or too few variables for fields %d %d %d",
		 disp->srec->dim, disp->nbind,
		 disp->srec->attribs.attribs_len);

	  return 0;

	}

      A4GL_debug ("Clearing Record");
      clear_srec (disp->srec);
      A4GL_debug ("Cleared record");
      for (a = 0; a < disp->srec->dim; a++)

	{

	  if (a < disp->no_arr)

	    {

#ifdef DEBUG
	      /* {DEBUG} */
	      {
	 A4GL_debug ("call draw_arr (1)");
	      }
#endif
	      draw_arr (disp, a + 1 == disp->arr_line, a + 1);
#ifdef DEBUG
	      /* {DEBUG} */
	      {
	 A4GL_debug ("after draw_arr (1)");
	      }
#endif
	    }

	}
#ifdef DEBUG
      /* {DEBUG} */
      {
 A4GL_debug ("call draw_arr (2)");
      }
#endif
      draw_arr (disp, 1, disp->arr_line);
#ifdef DEBUG
      /* {DEBUG} */
      {
 A4GL_debug ("after draw_arr (2)");
      }
#endif
      A4GL_gui_scroll (disp->no_arr);
      A4GL_set_arr_curr (disp->arr_line);
      A4GL_set_scr_line (disp->scr_line);

      return -10;
    }
  A4GL_debug ("disparr4");
  return disp_loop (disp);
}



/**
 * Set the screen line.
 *
 * @param np Number of parameters.
 * @return 
 *   - 1 : Everithing OK.
 *   - 0 : There was an error.
 */
/*
static int
set_scrline_da (int np)
{
  int a;
  if (np != 1)
    {
      A4GL_exitwith ("set_scrline requires 1 parameter");
      return 0;
    }
  a = A4GL_pop_int ();
  curr_arr->scr_line = a;
  A4GL_set_scr_line (a);
  draw_arr_all (curr_arr);
	#ifdef DEBUG
		{A4GL_debug ("Set scrline...%d", a);}
	#endif
  return 1;
}
*/

/**
 *
 * @param np Number of parameters.
 */
/*
static int
set_arrline_da (int np)
{
  int a;
  if (np != 1)
    {
      A4GL_exitwith ("set_arrline requires 1 parameter");
      return 0;
    }
  a = A4GL_pop_int ();
  curr_arr->arr_line = a;
  A4GL_set_arr_curr (a);
  draw_arr_all (curr_arr);
	#ifdef DEBUG
		{A4GL_debug ("Set arrline... %d", a);}
	#endif
  return 1;
}
*/

/**
 * Not used
 *
 * @todo : Remove if not used.
 * @deprecated Removal candidate.
 * @param np Number of parameters.
 */
/*
static int
aclfgl_set_arrline (int np)
{
  if (cmode == 'D')
    {
      return set_arrline_da (np);
    }

  if (cmode == 'I')
    {
      return set_arrline_ia (np);
    }
  return 0;
}
*/

/**
 * Not used
 * @todo : Remove if not used.
 * @deprecated Removal candidate.
 */
/*
static int
aclfgl_set_scrline (int np)
{
  if (cmode == 'D')
    {
      return set_scrline_da (np);
    }

  if (cmode == 'I')
    {
      return set_scrline_ia (np);
    }
  A4GL_exitwith ("set_scrline() may only be called when in a display/input array");
  return 0;
}
*/


/**
 *
 *
 * @param
 */
void
A4GL_disp_arr_fields (int n, int fonly, int attr, ...)
{
  int a;
  va_list ap;
  int flg;
  struct s_form_dets *formdets;
  void **field_list;
  int nofields;

  A4GL_debug ("In disp_fields");
  formdets = A4GL_get_curr_form (1);
  flg = 0;

  va_start (ap, attr);
  A4GL_debug (" field_list = %p", &field_list);
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Genfldlist 5");
  }
#endif
  A4GL_debug ("disp_arr_fields");
  nofields =
    A4GL_gen_field_list_gtk ((GtkWidget ***) & field_list, (GtkWindow *) formdets,
			n, &ap);

  /* int A4GL_gen_field_list_gtk (GtkWidget *** field_list, GtkWindow * cwin, int a, va_list * ap); */

  if (fonly && nofields >= 0)
    nofields = 0;
  A4GL_debug ("Number of fields=%d", nofields);
  if (nofields >= 0)
    {
      for (a = 0; a <= nofields; a++)
	{
	  A4GL_debug ("field_list[%d]=%p - attr=%x", a, field_list[a], attr);
	  A4GL_gui_set_field_pop_attr (field_list[a], attr);
	  A4GL_debug ("set_init_pop complete");
	}
    }
}



/**
 * function does nothing - see return at top - remove it
 *
 * @param
 */
void
A4GL_set_arr_fields (int n, int attr, ...)
{
  int a;
  va_list ap;
  int flg;
  struct s_form_dets *fff;
  struct s_form_dets *formdets;
  void **field_list;
  int nofields;

  return;

  A4GL_debug ("In disp_fields");
  formdets = A4GL_get_curr_form (1);
  flg = 0;

  va_start (ap, attr);
  A4GL_debug (" field_list = %p", &field_list);
#ifdef DEBUG
  {
    A4GL_debug ("Genfldlist 6");
  }
#endif
  A4GL_debug ("set_arr_fields");

  nofields =
    A4GL_gen_field_list_gtk ((GtkWidget ***) & field_list, (GtkWindow *) formdets,
			n, &ap);
  A4GL_debug ("Number of fields=%d", nofields);

  for (a = nofields; a >= 0; a--)
    {
      A4GL_debug ("field_list[%d]=%p", field_list[a]);
      fff = A4GL_get_curr_form (1);

      /* set_current_field (fff->form, field_list[a]); */
      A4GL_debug ("set_init_pop complete");
    }
  /* set_current_field (fff->form, field_list[nofields]); */
}



    /*
       struct s_disp_arr {
       int no_fields;
       int no_lines;
       int no_arr;
       int last_arr;
       struct struct_screen_record *srec;
       int arr_elemsize;
       int scr_line;
       int arr_line;
       int highlight;
       struct s_form_dets *currform;
       struct BINDING *binding;
       int nbind;
       int cntrl;
       };

     */


    /*
       struct s_inp_arr {
       int mode;
       struct s_form_dets *currform;
       void *currentfield;
       struct s_metrics *currentmetrics;
       int novars;
       struct s_constr_list *constr;
       int nfields;
       void ***field_list;
       int no_fields;
       int no_lines;
       int no_arr;
       int inp_flags;
       int arr_size;
       int last_arr;
       struct struct_screen_record *srec;
       int arr_elemsize;
       int scr_line;
       int arr_line;
       int highlight;
       struct BINDING *binding;
       int nbind;
       int cntrl;
       int help_no;
       int curr_attrib;
       };


     */

/**
 * Not used
 *
 * @param
 */
/*
int
set_scrline_ia (int np)
{
  int a;
  if (np != 1)
    {
      A4GL_exitwith ("set_scrline requires 1 parameter");
      return 0;
    }
  a = A4GL_pop_int ();
  curr_arr->scr_line = a;
  A4GL_set_scr_line (a);
  A4GL_idraw_arr_all (curr_arr); // warning: passing arg 1 of `idraw_arr_all' from incompatible pointer type

	//void A4GL_idraw_arr_all (struct s_inp_arr *disp)
    //struct s_disp_arr *curr_arr;



#ifdef DEBUG
	{ A4GL_debug ("Set scrline...%d", a); }
#endif
  return 1;
}
*/


/**
 * I think its not used because the function that calls it its not used
 */
/*
int
set_arrline_ia (int np)
{
  int a;
  if (np != 1)
    {
      A4GL_exitwith ("set_arrline requires 1 parameter");
      return 0;
    }
  a = A4GL_pop_int ();
  curr_arr->arr_line = a;
  A4GL_set_arr_curr (a);
  A4GL_idraw_arr_all (curr_arr);
#ifdef DEBUG
	{ A4GL_debug ("Set arrline... %d", a); }
#endif
  return 1;
}
*/

/**
 *
 *
 * @param
 */
void
A4GL_idraw_arr_all (struct s_inp_arr *disp)
{
  int a;
  int topline;
  topline = disp->arr_line - disp->scr_line + 1;
#ifdef DEBUG
  {
    A4GL_debug ("Draw_arr_all");
  }
#endif
  for (a = 0; a < disp->srec->dim; a++)
    {
      /* if (a + topline < disp->no_arr)
         {  */
      A4GL_idraw_arr (disp, a + topline == disp->arr_line, a + topline);
#ifdef DEBUG
      {
 A4GL_debug ("after draw_arr (6)");
      }
#endif
      /* } */
    }
  A4GL_idraw_arr (disp, 1, disp->arr_line);
#ifdef DEBUG
  {
    A4GL_debug ("after draw_arr (7)");
  }
#endif
}


/**
 *
 *
 * @param
 */
void
A4GL_idraw_arr (struct s_inp_arr *disp, int type, int no)
{
  char srec2[256];
  int topline;
  int scr_line;
  int fonly = 0;
#ifdef DEBUG
  {
    A4GL_debug ("in draw_arr %p %d %d", disp, type, no);
  }
#endif
  if (type < 0)
    {
      type = 0 - type;
      fonly = 1;
    }

  A4GL_debug ("*** no=%d disp->no_arr=%d\n", no, disp->no_arr);

  topline = disp->arr_line - disp->scr_line + 1;
  scr_line = no - topline + 1;

  if (scr_line > disp->srec->dim)
    {
      A4GL_debug ("scr line out of range %d %d\n", scr_line, disp->srec->dim);
      return;
    }

  if (no > disp->no_arr)
    {
      A4GL_debug ("arr no out of range %d %d\n", scr_line, disp->srec->dim);
      A4GL_iclear_srec_line (disp->srec, scr_line - 1);
      return;
    }

  strcpy (srec2, disp->srec->name);
  strcat (srec2, ".*");

  if (type == 2)
    {
      A4GL_debug ("calling set_arr_Fields");
      A4GL_set_arr_fields (disp->nbind, 1, srec2, scr_line, 0, 0);
#ifdef DEBUG
      {
 A4GL_debug ("Done");
      }
#endif
      return;
    }


  if (fonly)
    A4GL_push_bind (disp->binding, 1, no, disp->arr_elemsize);
  else
    A4GL_push_bind (disp->binding, disp->nbind, no, disp->arr_elemsize);

  A4GL_debug ("Print array no %d to scr %d", no, scr_line);
  A4GL_debug ("calling disp_arR_fields");
  if (disp->highlight)
    {
      A4GL_debug ("With highlight");
      A4GL_idisp_arr_fields (disp->nbind, fonly, type * 0x400, srec2, scr_line, 0,
			0);
    }
  else
    {
      A4GL_debug ("Without highlight");
      A4GL_idisp_arr_fields (disp->nbind, fonly, 0, srec2, scr_line, 0, 0);
    }
}



/**
 *
 *
 * @param
 */
void
A4GL_iclear_srec_line (struct struct_screen_record *srec, int line)
{
  int a;
  char srec1[256];
  strcpy (srec1, srec->name);
  strcat (srec1, ".*");

  for (a = 0; a < srec->attribs.attribs_len + 1; a++)
    {
      A4GL_push_char (" ");
    }
  A4GL_idisp_arr_fields (srec->attribs.attribs_len + 1, 0, 0, srec1, line + 1, 0,
		    0);
}

/**
 *
 *
 * @param
 */
void
A4GL_idisp_arr_fields (int n, int fonly, int attr, ...)
{
  int a;
  va_list ap;
  int flg;
  struct s_form_dets *formdets;
  GtkWidget **field_list;
  int nofields;

  A4GL_debug ("In A4GL_disp_fields - attr=%d");
  formdets = A4GL_get_curr_form (1);
  flg = 0;

  va_start (ap, attr);
  A4GL_debug (" field_list = %p", &field_list);
#ifdef DEBUG
  {
    A4GL_debug ("Genfldlist 5");
  }
#endif
  A4GL_debug ("idisp_arr_fields");
  nofields = A4GL_gen_field_list_gtk (&field_list, (GtkWindow *) formdets, n, &ap);
  if (fonly && nofields >= 0)
    nofields = 0;
  A4GL_debug ("Number of fields=%d", nofields);
  if (nofields >= 0)
    {
      for (a = 0; a <= nofields; a++)
	{
	  A4GL_debug ("field_list[%d]=%p", a, field_list[a]);
	  A4GL_gui_set_field_pop_attr (field_list[a], attr);
	  A4GL_debug ("set_init_pop complete");
	}
    }
}

/* ================================= EOF =========================== */
