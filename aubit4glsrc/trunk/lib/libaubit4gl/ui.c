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
# $Id: ui.c,v 1.5 2003-07-29 10:47:04 mikeaubury Exp $
#
*/


/**
 * @file
 * GUI interface implementations
 *
 * The user interface functions pass allways from here.
 *
 * There is work to be done in this module in order to change it to work
 * like SQL library with several interfaces:
 *   - Curses
 *   - GTK
 *   - Thin client using TCP
 *
 * @todo Does this file belong in lib/ directory, or?
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen A4GL_comments to add to functions
 */

 /*
    =====================================================================
    Includes
    =====================================================================
  */

#include "a4gl_libaubit4gl_int.h"
#include "a4gl_API_ui.h"

/*
=====================================================================
                    Constants definitions
=====================================================================
*/


/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *A4GL_pull_off_data_for_display(int n,int display_type);


#define LINE_MODE               0
#define SCREEN_MODE     1
#define UI_MODE_TEXT    0
#define UI_MODE_GTK     1
extern int ui_mode;
int currscrmode = SCREEN_MODE;
void *libptr;


void
A4GL_set_scrmode (char a)
{
  if (a == 'L')
    currscrmode = LINE_MODE;
  else
    currscrmode = SCREEN_MODE;
}


/**
 *
 * @todo Describe function
 */
int
A4GL_isscrmode (void)
{
  return (currscrmode == SCREEN_MODE);
}

/**
 *
 * @todo Describe function
 */
int
A4GL_islinemode (void)
{
  return (currscrmode == LINE_MODE);
}

/**
 *
 * @todo Describe function
 */
void A4GL_disp_fields (int n, int attr, ...)
{
  va_list ap;
  va_start (ap, attr);
  A4GL_disp_fields_ap(n, attr, &ap);
  va_end(ap);
}

/**
 *
 * @todo Describe function
 */
int A4GL_disp_form_fields (int n, int attr, char *formname, ...)
{
  va_list ap; 
  int a;
  va_start (ap, formname);
  a=A4GL_disp_form_fields_ap(n, attr, formname, &ap);
  va_end(ap);
  return a;
}



/**
 *
 * @todo Describe function
 */
int A4GL_req_field (void *s, char itype, char type, ...)
{
va_list ap;
int a=0;
int found=0;
  va_start(ap,type);

  if (itype=='I'||itype=='C') 
    {
	a=A4GL_req_field_input(s,type,&ap);
	found=1;
    }

  if (itype=='A')
    {
	a=A4GL_req_field_input_array(s,type,&ap);
	found=1;
    }


  if (found == 0)
    {
      A4GL_debug ("Unable to determine current action... - itype='%c'",itype);
      A4GL_exitwith ("Unable to determine current action...");
    }

  va_end(ap);
  return a;

}


/**
 * Not used but should be.
 */
int A4GL_menu_hide (ACL_Menu * menu, ...)
{
  va_list ap;
  int a;
  va_start (ap, menu);
  a=A4GL_menu_hide_ap(menu, &ap);
  va_end(ap);
  return a;
}

/**
 * Show an item of the menu.
 *
 * Called by the generated C code at run-time.
 *
 * @param The menu name to be showed.
 * @param ... The options to be showed.
 */
int A4GL_menu_show (ACL_Menu * menu, ...)
{
  va_list ap;
  int a;
  va_start (ap, menu);
  a=A4GL_menu_show_ap (menu, &ap);
  va_end(ap);
  return a;
}

/**
 *
 * @todo Describe function
 */
void aclfgli_pr_message (int attr, int wait,int n)
{
  char *s;
A4GL_debug("In aclfgli_pr_message : %d",n);
  s=A4GL_pull_off_data_for_display(n,DISPLAY_TYPE_DISPLAY_AT);
  A4GL_debug(" called pull_off_data_for_display  s=%s",s);
  aclfgli_pr_message_internal(attr, wait,s);
  free(s);
}

/**
 * Implementation of part of the INPUT 4gl statement.
 *
 * Generate a list of fields acording the parameters.
 *
 * @param field_list A pointer to the place where to put the field list.
 * @param formdets Pointer to the structure filled with the form details.
 * @param ...
 * @return
 */
int A4GL_gen_field_chars (void ***field_list, void *formdets, ...)
{
  va_list ap;
  int a;
  va_start (ap, formdets);

  a=A4GL_gen_field_chars_ap(field_list, formdets, &ap);
  va_end(ap);
return a;
}

void A4GL_display_at (int n, int a)
{

  //int b;
  //int z;
  int x, y;
  char *s = 0;
  //char *ptr;
  //char *buff = 0;
  int tos_size;
  int tos_dtype;
  void *tos_ptr;
  int clr_end_of_line = 0;
  int display_type;

  x = 0;
  y = 0;

  x = A4GL_pop_int ();
  y = A4GL_pop_int ();

  A4GL_debug_print_stack();
  A4GL_get_top_of_stack (1, &tos_dtype, &tos_size, (void **) &tos_ptr);
  A4GL_debug ("TOP1 = %d %x %p\n", tos_dtype % 256, tos_size, tos_ptr);

  if (tos_dtype % 256 == 0 && tos_size == 0)
    {
      clr_end_of_line = 1;
    }

	  if (x == -1 && y == -1) {
		display_type=DISPLAY_TYPE_DISPLAY;
	  } else {
		display_type=DISPLAY_TYPE_DISPLAY_AT;
	  }

  s=A4GL_pull_off_data_for_display(n,display_type);


#ifdef REMOVED
  for (z = 0; z <= n - 1; z++)
    {
      A4GL_get_top_of_stack (1, &tos_dtype, &tos_size, (void **) &tos_ptr);
      ptr = 0;
      if (A4GL_has_datatype_function_i (tos_dtype & DTYPE_MASK, "DISPLAY"))
	{
	  char *(*function) (void *, int, int, struct struct_scr_field *,
			     int);
	  function =
	    A4GL_get_datatype_function_i (tos_dtype & DTYPE_MASK, "DISPLAY");

	  if (x == -1 && y == -1)
	    {
	      ptr =
		function (tos_ptr, tos_size, -1,
			  (struct struct_scr_field *) 0,
			  DISPLAY_TYPE_DISPLAY);
	    }
	  else
	    {
	      ptr =
		function (tos_ptr, tos_size, -1,
			  (struct struct_scr_field *) 0,
			  DISPLAY_TYPE_DISPLAY_AT);
	    }

	  if (ptr != 0)
	    {
	      A4GL_drop_param ();
	    }
	}

      if (ptr == 0)
	{
	  ptr = A4GL_char_pop ();
	}

      A4GL_debug ("DISPLAY_AT : '%s'\n", ptr);
      buff = realloc (buff, strlen (s) + strlen (ptr) + 1);
      s = realloc (s, strlen (s) + strlen (ptr) + 1);
      sprintf (buff, "%s%s", ptr, s);
      strcpy (s, buff);
      A4GL_debug ("s='%s' %p\n", s, s);
    }

#endif
A4GL_debug("Here1\n");

  if (x == -1 && y == -1)
    {
      // Do nothing 
    }
  else
    {
      int line_length;

      if (A4GL_iscurrborder ())
	{
	  line_length = A4GL_get_curr_width () - x;
	}
      else
	{
	  line_length = A4GL_get_curr_width () - x + 1;
	}

      line_length++;
      if (strlen (s) > line_length)
	{
	  A4GL_debug ("'%s' seems to long to display... - I'm gonna A4GL_trim it..", s);
	  s[line_length] = 0;

	}

    }


A4GL_debug("Finding display_internal");

  A4GL_display_internal (x, y, s, a, clr_end_of_line);

  free (s);
  A4GL_debug ("Done Display@");
  //return 1;
}



/**
 *
 * @todo Describe function
 */
int A4GL_disp_arr (void *disp, void *ptr, char *srecname, int attrib, ...)
{
  va_list ap;
  int a;

  va_start (ap, attrib);
  a=A4GL_disp_arr_ap (disp, ptr, srecname, attrib, &ap);
  va_end(ap);
  return a;
}


/**
 *
 * @todo Describe function
 */
int A4GL_endis_fields (int en_dis, ...)
{
va_list ap;
int a;
  va_start (ap, en_dis);
  a=A4GL_endis_fields_ap (en_dis, &ap);
  va_end(ap);
  return a;
}

//void A4GL_clr_form_fields (int to_defaults, char *defs)
//{

  //A4GL_debug ("FIXME: not implemented: clr_form_fields");

//}

void A4GL_clr_fields (int to_defaults, ...)
{
  va_list ap;

  va_start (ap, to_defaults);
  A4GL_clr_fields_ap (to_defaults,&ap);
  va_end(ap);
  return ;
}

/**
 * WARNING: exists only in UI Curses!!!!
 * @todo Describe function
 */
int A4GL_fgl_getfldbuf (void *inp,char itype,...)
{
int a=-1;
  va_list ap;

  va_start (ap, itype);

  if (itype=='I' || itype=='C') {
  	a=A4GL_fgl_getfldbuf_ap (inp,&ap); 
  } else {
  	a=A4GL_fgl_getfldbuf_ia_ap (inp,&ap); 
  }

  va_end(ap);

  return a;

}

int A4GL_fgl_infield (void *inp,char itype,...)
{
int a=-1;
  va_list ap;

  va_start (ap, itype);

  if (itype=='I' || itype=='C') {
  	a=A4GL_fgl_infield_ap (inp,&ap); 
  } else {
  	a=A4GL_fgl_infield_ia_ap (inp,&ap); 
  }

  va_end(ap);

  return a;

}



int A4GL_open_gui_form (char *name_orig, int absolute, int nat, char *like, int disable, void *handler_e, void (*handler_c (int a, int b)))
{
  return A4GL_open_gui_form_internal (name_orig, absolute, nat, like, disable, handler_e);
}


/**
 * The FIELD_TOUCHED( ) operator tests whether the user has entered or
 * edited a value in a specified field or list of fields of the current 4GL
 * form. (This operator can only appear within CONSTRUCT, INPUT, and INPUT
 * ARRAY statements.)
 *
 * Usage:
 * input by name pr_globals.vouch_date, ...
 * ...
 * if not field_touched(year_num) then
 *
 *
 *
 * Built-in functions that access field buffers and keystroke buffers:
 *
 * Built-In Funtion             Description
 * FIELD_TOUCHED(field) Returns TRUE when the user has made a change to
 *   screen field.
 * GET_FLDBUF(field-list) Returns the character values of the contents of
 *   one or more fields.
 * FGL_LASTKEY( ) Returns an INTEGER value corresponding to the most recent
 *   keystroke.
 * INFIELD(field) Returns TRUE if field is the name of the current screen field.
 * FGL_GETKEY
 * FGL_KEYVAL( )
 *
 *
 * See Informix 7.3 manual
 *
 * @param fieldname
 * @param fieldno
 */
int A4GL_fgl_fieldtouched (void *input,char itype, ...)
{
  int a=-1;
  va_list ap;
  
  va_start (ap, itype);
  if (itype == 'I' || itype=='C') 
    {
	a=A4GL_fgl_fieldtouched_input_ap(input,&ap);
    }

  if (itype=='A') 
    {
     a=A4GL_fgl_fieldtouched_input_array_ap(input,&ap);
    }

  return a;
}


char *A4GL_pull_off_data_for_display(int n,int display_type) {
int z;
char *s=0;
int tos_dtype,tos_size;
void *tos_ptr;
char *ptr;
char *buff=0;
int ls;
  s = malloc (2);
  s[0] = 0;

  for (z = 0; z <= n - 1; z++)
    {
      A4GL_get_top_of_stack (1, &tos_dtype, &tos_size, (void **) &tos_ptr);

      //A4GL_assertion(tos_ptr==0,"Top of the stack has 0 for the pointer..");

      ptr = 0;
      if (A4GL_has_datatype_function_i (tos_dtype & DTYPE_MASK, "DISPLAY"))
        {
          char *(*function) (void *, int, int, struct struct_scr_field *,
                             int);
          function =
            A4GL_get_datatype_function_i (tos_dtype & DTYPE_MASK, "DISPLAY");

              ptr =
                function (tos_ptr, tos_size, -1,
                          (struct struct_scr_field *) 0,display_type);

          if (ptr != 0)
            {
              A4GL_drop_param ();
            }
        }

      if (ptr == 0)
        {
          ptr = A4GL_char_pop ();
        }

      buff = realloc (buff, strlen (s) + strlen (ptr) + 1);
	ls= strlen (s) + strlen (ptr) + 1;
      s = realloc (s, ls);
      sprintf (buff, "%s%s", ptr, s);
      strcpy (s, buff);
      A4GL_debug ("s='%s' %p %d %d\n", s, s,strlen(s),ls);
    }
    free(buff);
	A4GL_debug("pull_off_data_for_display returns %s",s);
    return s;
}

int processed_onkey;

void A4GL_processed_onkey() {
	processed_onkey=1;
}

void A4GL_reset_processed_onkey() {
	processed_onkey=0;
}

int A4GL_has_processed_onkey() {
	return processed_onkey;
}

/* ============================= EOF ================================ */
