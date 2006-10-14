/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
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
# $Id: data_if.c,v 1.35 2006-10-14 16:18:31 mikeaubury Exp $
#
*/

/**
 * @file
 *
 * Used by C compiled 4gl code
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */


/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


static void *get_set_s_screenio (void *ptr, int mode, char *name, long var);
static void *get_set_s_inp_arr (void *ptr, int mode, char *name, long var);
static void *get_set_s_prompt (void *ptr, int mode, char *name, long var);
//static void *get_set_rep_structure (void *ptr, int mode, char *name, long var);
static void *get_set_s_disp_arr (void *ptr, int mode, char *name, long var);



/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Handler for s_screenio
 *
 * @todo Describe function
 */
static void *
get_set_s_screenio (void *ptr, int mode, char *name, long var)
{
  struct s_s_screenio_1
  {
    int mode;
     struct s_form_dets *currform;
    void *currentfield;
    int curr_attrib;
    void *currentmetrics;
    int novars;
    void *vars;
    void *constr;
    int nfields;
    void *field_list;
    int field_changed;
    int help_no;
    void *fcntrl;
    int fcntrl_cnt;
    int attrib;
	int processed_onkey;
  };

  struct s_s_screenio_1 *val;

  A4GL_debug ("screenio - %p mode=%d name=%s var=%x", ptr, mode, A4GL_null_as_null(name), var);
  if (mode == GETSETNEW)
    {
      return (void *) acl_malloc2 (sizeof (struct s_s_screenio_1));
    }

  if (mode == GETSETRM)
    {
      free (ptr);
      return 0;
    }

  val = (struct s_s_screenio_1 *) ptr;

  if (strcmp (name, "mode") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->mode;
      if (mode == GETSETGETPTR)
	return (void *) &(val->mode);
      if (mode == GETSETSET)
	{
	  val->mode = (int) var;
	  return (void *) 1;
	}
    }
  if (strcmp (name, "processed_onkey") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->processed_onkey;
      if (mode == GETSETGETPTR)
	return (void *) &(val->processed_onkey);
      if (mode == GETSETSET)
	{
	  val->processed_onkey = (int) var;
	  return (void *) 1;
	}
    }


  if (strcmp (name, "currform") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->currform;
      if (mode == GETSETGETPTR)
	return (void *) &(val->currform);
      if (mode == GETSETSET)
	{
	  val->currform = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "cform") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->currform->form;
      if (mode == GETSETGETPTR)
	return (void *) &(val->currform->form);
      if (mode == GETSETSET)
	{
	  val->currform->form = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "currentfield") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->currentfield;
      if (mode == GETSETGETPTR)
	return (void *) &(val->currentfield);
      if (mode == GETSETSET)
	{
	  val->currentfield = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "currentmetrics") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->currentmetrics;
      if (mode == GETSETGETPTR)
	return (void *) &(val->currentmetrics);
      if (mode == GETSETSET)
	{
	  val->currentmetrics = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "novars") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->novars;
      if (mode == GETSETGETPTR)
	return (void *) &(val->novars);
      if (mode == GETSETSET)
	{
	  val->novars = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "vars") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->vars;
      if (mode == GETSETGETPTR)
	return (void *) &(val->vars);
      if (mode == GETSETSET)
	{
	  val->vars = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "attrib") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->attrib;
      if (mode == GETSETGETPTR)
	return (void *) &(val->attrib);
      if (mode == GETSETSET)
	{
	  val->attrib = (int ) var;
	  return (void *) 1;
	}
    }


  if (strcmp (name, "constr") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->constr;
      if (mode == GETSETGETPTR)
	return (void *) &(val->constr);
      if (mode == GETSETSET)
	{
	  val->constr = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "nfields") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->nfields;
      if (mode == GETSETGETPTR)
	return (void *) &(val->nfields);
      if (mode == GETSETSET)
	{
	  val->nfields = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "field_list") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->field_list;
      if (mode == GETSETGETPTR)
	return (void *) &(val->field_list);
      if (mode == GETSETSET)
	{
	  val->field_list = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "field_changed") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->field_changed;
      if (mode == GETSETGETPTR)
	return (void *) &(val->field_changed);
      if (mode == GETSETSET)
	{
	  val->field_changed = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "help_no") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->help_no;
      if (mode == GETSETGETPTR)
	return (void *) &(val->help_no);
      if (mode == GETSETSET)
	{
	  val->help_no = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "processed_onkey") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->processed_onkey;
      if (mode == GETSETGETPTR)
	return (void *) &(val->processed_onkey);
      if (mode == GETSETSET)
	{
	  val->processed_onkey = (int) var;
	  return (void *) 1;
	}
    }



  A4GL_debug ("No found name %s\n", A4GL_null_as_null(name));

  return (void *) 0;		/* unknown value */
}

/**
 * Handler for s_inp_arr
 *
 * @todo Describe function
 */
static void *
get_set_s_inp_arr (void *ptr, int mode, char *name, long var)
{
  struct s_s_inp_arr_1
  {
    int mode;
    int nbind;
    void *currform;
    void *currentfield;
    void *currentmetrics;
    int novars;
    void *constr;
    int nfields;
    void *field_list;
    int no_fields;
    int no_lines;
    int no_arr;
    int inp_flags;
    int arr_size;
    int last_arr;
    int last_arr_line;
    int last_scr_line;
    void *srec;
    int arr_elemsize;
    int scr_line;
    int arr_line;
    int highlight;
    void *binding;
    int cntrl;
    int help_no;
    int curr_attrib;
    void *screen_io;
    void *fcntrl;
    int fcntrl_cnt;
    int allow_insert;
    int allow_delete;
    char *curr_display;
    int curr_display_i;
    int maxcount;
    int count;
    int display_attrib;
    int scr_dim;
	int curr_line_is_new;
	int processed_onkey;
  };

  struct s_s_inp_arr_1 *val;
A4GL_debug("getcount=%d XYX",A4GL_get_count());

  A4GL_debug ("mode = %d ptr=%x  name=%s size=%d", mode, ptr, A4GL_null_as_null(name),
	 sizeof (struct s_s_inp_arr_1));
  if (mode == GETSETNEW)
    {
      return (void *) acl_malloc2 (sizeof (struct s_s_inp_arr_1));
    }

  if (mode == GETSETRM)
    {
      free (ptr);
      return 0;
    }

  val = (struct s_s_inp_arr_1 *) ptr;

  if (strcmp (name, "processed_onkey") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->processed_onkey;
      if (mode == GETSETGETPTR)
	return (void *) &(val->processed_onkey);
      if (mode == GETSETSET)
	{
	  val->processed_onkey = (int) var;
	  return (void *) 1;
	}
    }


  if (strcmp (name, "mode") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->mode;
      if (mode == GETSETGETPTR)
	return (void *) &(val->mode);
      if (mode == GETSETSET)
	{
	  val->mode = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "currform") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->currform;
      if (mode == GETSETGETPTR)
	return (void *) &(val->currform);
      if (mode == GETSETSET)
	{
	  val->currform = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "currentfield") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->currentfield;
      if (mode == GETSETGETPTR)
	return (void *) &(val->currentfield);
      if (mode == GETSETSET)
	{
	  val->currentfield = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "currentmetrics") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->currentmetrics;
      if (mode == GETSETGETPTR)
	return (void *) &(val->currentmetrics);
      if (mode == GETSETSET)
	{
	  val->currentmetrics = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "novars") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->novars;
      if (mode == GETSETGETPTR)
	return (void *) &(val->novars);
      if (mode == GETSETSET)
	{
	  val->novars = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "constr") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->constr;
      if (mode == GETSETGETPTR)
	return (void *) &(val->constr);
      if (mode == GETSETSET)
	{
	  val->constr = (void *) var;
	  return (void *) 1;
	}
    }


  if (strcmp (name, "inp_flags") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->inp_flags;
      if (mode == GETSETGETPTR)
	return (void *) &(val->inp_flags);
      if (mode == GETSETSET)
	{
	  val->inp_flags = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "arr_size") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->arr_size;
      if (mode == GETSETGETPTR)
	return (void *) &(val->arr_size);
      if (mode == GETSETSET)
	{
	  val->arr_size = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "count") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->count;
      if (mode == GETSETGETPTR)
	return (void *) &(val->count);
      if (mode == GETSETSET)
	{
	A4GL_debug("Setting count %d XYX\n",var);
	  val->count = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "allow_insert") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->allow_insert;
      if (mode == GETSETGETPTR)
	return (void *) &(val->allow_insert);
      if (mode == GETSETSET)
	{
	  val->allow_insert = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "allow_delete") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->allow_delete;
      if (mode == GETSETGETPTR)
	return (void *) &(val->allow_delete);
      if (mode == GETSETSET)
	{
	  val->allow_delete = (int) var;
	  return (void *) 1;
	}
    }


  if (strcmp (name, "maxcount") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->maxcount;
      if (mode == GETSETGETPTR)
	return (void *) &(val->maxcount);
      if (mode == GETSETSET)
	{
	  val->maxcount = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "scr_dim") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->scr_dim;
      if (mode == GETSETGETPTR)
	return (void *) &(val->scr_dim);
      if (mode == GETSETSET)
	{
	  val->scr_dim = (int) var;
	  return (void *) 1;
	}
    }


  if (strcmp (name, "display_attrib") == 0)
    {
      if (mode == GETSETGET)
        return (void *)(long) val->display_attrib;
      if (mode == GETSETGETPTR)
        return (void *) &(val->display_attrib);
      if (mode == GETSETSET)
        {
          val->display_attrib = (int) var;
          return (void *) 1;
        }
    }
  if (strcmp (name, "nfields") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->nfields;
      if (mode == GETSETGETPTR)
	return (void *) &(val->nfields);
      if (mode == GETSETSET)
	{
	  val->nfields = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "field_list") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->field_list;
      if (mode == GETSETGETPTR)
	return (void *) &(val->field_list);
      if (mode == GETSETSET)
	{
	  val->field_list = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "no_fields") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->no_fields;
      if (mode == GETSETGETPTR)
	return (void *) &(val->no_fields);
      if (mode == GETSETSET)
	{
	  val->no_fields = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "curr_display_i") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->curr_display_i;
      if (mode == GETSETGETPTR)
	return (void *) &(val->curr_display_i);
      if (mode == GETSETSET)
	{
	  val->curr_display_i = (int) var;
	  return (void *) 1;
	}
    }


  if (strcmp (name, "curr_display") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->curr_display;
      if (mode == GETSETGETPTR)
	return (void *) &(val->curr_display);
      if (mode == GETSETSET)
	{
	  val->curr_display = (char *) var;
	  return (void *) 1;
	}
    }



  if (strcmp (name, "no_lines") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->no_lines;
      if (mode == GETSETGETPTR)
	return (void *) &(val->no_lines);
      if (mode == GETSETSET)
	{
	  val->no_lines = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "no_arr") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->no_arr;
      if (mode == GETSETGETPTR)
	return (void *) &(val->no_arr);
      if (mode == GETSETSET)
	{
	  val->no_arr = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "last_arr_line") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->last_arr_line;
      if (mode == GETSETGETPTR)
	return (void *) &(val->last_arr_line);
      if (mode == GETSETSET)
	{
	  val->last_arr_line = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "srec") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->srec;
      if (mode == GETSETGETPTR)
	return (void *) &(val->srec);
      if (mode == GETSETSET)
	{
	  val->srec = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "arr_elemsize") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->arr_elemsize;
      if (mode == GETSETGETPTR)
	return (void *) &(val->arr_elemsize);
      if (mode == GETSETSET)
	{
	  val->arr_elemsize = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "scr_line") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->scr_line;
      if (mode == GETSETGETPTR)
	return (void *) &(val->scr_line);
      if (mode == GETSETSET)
	{
	  val->scr_line = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "arr_line") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->arr_line;
      if (mode == GETSETGETPTR)
	return (void *) &(val->arr_line);
      if (mode == GETSETSET)
	{
	  val->arr_line = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "highlight") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->highlight;
      if (mode == GETSETGETPTR)
	return (void *) &(val->highlight);
      if (mode == GETSETSET)
	{
	  val->highlight = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "binding") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->binding;
      if (mode == GETSETGETPTR)
	return (void *) &(val->binding);
      if (mode == GETSETSET)
	{
	  val->binding = (void *) var;
	  return (void *) 1;
	}
    }


  if (strcmp (name, "nbind") == 0)
    {
      A4GL_debug ("Setting nbind=%d", (int) var);
      if (mode == GETSETGET)
	return (void *)(long) val->nbind;
      if (mode == GETSETGETPTR)
	return (void *) &(val->nbind);
      if (mode == GETSETSET)
	{
	  val->nbind = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "cntrl") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->cntrl;
      if (mode == GETSETGETPTR)
	return (void *) &(val->cntrl);
      if (mode == GETSETSET)
	{
	  val->cntrl = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "help_no") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->help_no;
      if (mode == GETSETGETPTR)
	return (void *) &(val->help_no);
      if (mode == GETSETSET)
	{
	  val->help_no = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "curr_attrib") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->curr_attrib;
      if (mode == GETSETGETPTR)
	return (void *) &(val->curr_attrib);
      if (mode == GETSETSET)
	{
	  val->curr_attrib = (int) var;
	  return (void *) 1;
	}
    }

  A4GL_assertion (1, "CRITICAL ERROR - unknown name in GETSET/s_inp_arr");
  A4GL_debug ("CRITICAL - UNKNOWN VALUE FOR  s_inp_arr - %s\n", A4GL_null_as_null(name));

  return (void *) 0;		/* unknown value */
}


/**
 * Handler for s_prompt
 *
 * @todo Describe function
 */
static void *
get_set_s_prompt (void *ptr, int mode, char *name, long var)
{
  struct s_s_prompt_1
  {
    void *win;
    int mode;
    int charmode;
    char *promptstr;
    int lastkey;
    void *f;
    void *field;
    int h;
	int insmode;
	int processed_onkey;

  };

  struct s_s_prompt_1 *val;


  if (mode == GETSETNEW)
    {
      return (void *) acl_malloc2 (sizeof (struct s_s_prompt_1));
    }

  if (mode == GETSETRM)
    {
      free (ptr);
      return 0;
    }

  val = (struct s_s_prompt_1 *) ptr;

  if (strcmp (name, "win") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->win;
      if (mode == GETSETGETPTR)
	return (void *) &(val->win);
      if (mode == GETSETSET)
	{
	  val->win = (void *) var;
	  return (void *) 1;
	}
    }
  if (strcmp (name, "processed_onkey") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->processed_onkey;
      if (mode == GETSETGETPTR)
	return (void *) &(val->processed_onkey);
      if (mode == GETSETSET)
	{
	  val->processed_onkey = (int) var;
	  return (void *) 1;
	}
    }


  if (strcmp (name, "mode") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->mode;
      if (mode == GETSETGETPTR)
	return (void *) &(val->mode);
      if (mode == GETSETSET)
	{
	  val->mode = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "charmode") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->charmode;
      if (mode == GETSETGETPTR)
	return (void *) &(val->charmode);
      if (mode == GETSETSET)
	{
	  val->charmode = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "promptstr") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->promptstr;
      if (mode == GETSETGETPTR)
	return (void *) &(val->promptstr);
      if (mode == GETSETSET)
	{
	  val->promptstr = (char *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "lastkey") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->lastkey;
      if (mode == GETSETGETPTR)
	return (void *) &(val->lastkey);
      if (mode == GETSETSET)
	{
	  val->lastkey = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "f") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->f;
      if (mode == GETSETGETPTR)
	return (void *) &(val->f);
      if (mode == GETSETSET)
	{
	  val->f = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "field") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->field;
      if (mode == GETSETGETPTR)
	return (void *) &(val->field);
      if (mode == GETSETSET)
	{
	  val->field = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "h") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->h;
      if (mode == GETSETGETPTR)
	return (void *) &(val->h);
      if (mode == GETSETSET)
	{
	  val->h = (int) var;
	  return (void *) 1;
	}
    }

  return (void *) 0;		/* unknown value */
}


#ifdef NDEF
/**
 * Handler for rep_structure.
 *
 * The rep structure is a report identification structure.
 *
 *
 * @param ptr
 * @param mode
 * @param name
 * @param var
 */
static void *
get_set_rep_structure (void *ptr, int mode, char *name, long var)
{
  struct s_rep_structure_1
  {
    int top_margin;
    int bottom_margin;
    int left_margin;
    int right_margin;
    int page_length;
    int has_first_page;
    char *next_page;
    char *rep_table;
    void *group_data;
    char output_mode;
    char output_loc[256];
    void *output;
    int page_no;
    int printed_page_no;
    int line_no;
    int col_no;
    void *report;
  };

  struct s_rep_structure_1 *val;

  if (mode == GETSETNEW)
    {
      return (void *) acl_malloc2 (sizeof (struct s_rep_structure_1));
    }

  if (mode == GETSETRM)
    {
      free (ptr);
      return 0;
    }

  val = (struct s_rep_structure_1 *) ptr;

  if (strcmp (name, "top_margin") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->top_margin;
      if (mode == GETSETGETPTR)
	return (void *) &(val->top_margin);
      if (mode == GETSETSET)
	{
	  val->top_margin = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "bottom_margin") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->bottom_margin;
      if (mode == GETSETGETPTR)
	return (void *) &(val->bottom_margin);
      if (mode == GETSETSET)
	{
	  val->bottom_margin = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "left_margin") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->left_margin;
      if (mode == GETSETGETPTR)
	return (void *) &(val->left_margin);
      if (mode == GETSETSET)
	{
	  val->left_margin = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "right_margin") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->right_margin;
      if (mode == GETSETGETPTR)
	return (void *) &(val->right_margin);
      if (mode == GETSETSET)
	{
	  val->right_margin = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "page_length") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->page_length;
      if (mode == GETSETGETPTR)
	return (void *) &(val->page_length);
      if (mode == GETSETSET)
	{
	  val->page_length = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "has_first_page") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->has_first_page;
      if (mode == GETSETGETPTR)
	return (void *) &(val->has_first_page);
      if (mode == GETSETSET)
	{
	  val->has_first_page = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "next_page") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->next_page;
      if (mode == GETSETGETPTR)
	return (void *) &(val->next_page);
      if (mode == GETSETSET)
	{
	  val->next_page = (char *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "rep_table") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->rep_table;
      if (mode == GETSETGETPTR)
	return (void *) &(val->rep_table);
      if (mode == GETSETSET)
	{
	  val->rep_table = (char *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "group_data") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->group_data;
      if (mode == GETSETGETPTR)
	return (void *) &(val->group_data);
      if (mode == GETSETSET)
	{
	  val->group_data = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "output_mode") == 0)
    {
      if (mode == GETSETGET)
	return (void *) &val->output_mode;
      if (mode == GETSETGETPTR)
	return (void *) &(val->output_mode);
      if (mode == GETSETSET)
	{
	  val->output_mode = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "output_loc") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->output_loc;
      if (mode == GETSETGETPTR)
	return (void *) &(val->output_loc);
      if (mode == GETSETSET)
	{
	  strcpy (val->output_loc, (char *) var);
	  return (void *) 1;
	}
    }

  if (strcmp (name, "output") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->output;
      if (mode == GETSETGETPTR)
	return (void *) &(val->output);
      if (mode == GETSETSET)
	{
	  val->output = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "page_no") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->page_no;
      if (mode == GETSETGETPTR)
	return (void *) &(val->page_no);
      if (mode == GETSETSET)
	{
	  val->page_no = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "printed_page_no") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->printed_page_no;
      if (mode == GETSETGETPTR)
	return (void *) &(val->printed_page_no);
      if (mode == GETSETSET)
	{
	  val->printed_page_no = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "line_no") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->line_no;
      if (mode == GETSETGETPTR)
	return (void *) &(val->line_no);
      if (mode == GETSETSET)
	{
	  val->line_no = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "col_no") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->col_no;
      if (mode == GETSETGETPTR)
	return (void *) &(val->col_no);
      if (mode == GETSETSET)
	{
	  val->col_no = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "report") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->report;
      if (mode == GETSETGETPTR)
	return (void *) &(val->report);
      if (mode == GETSETSET)
	{
	  val->report = (void *) var;
	  return (void *) 1;
	}
    }

  return (void *) 0;		/* unknown value */
}
#endif


/**
 * Handler for s_disp_arr
 *
 * @todo Describe function
 */
static void *
get_set_s_disp_arr (void *ptr, int mode, char *name, long var)
{
  struct s_s_disp_arr_1
  {
    int no_fields;
    int no_lines;
    int no_arr;
    int last_arr;
    void *srec;
    int arr_elemsize;
    int scr_line;
    int arr_line;
    int highlight;
    void *currform;
    void *binding;
    int nbind;
    int cntrl;
    int attribute;
    int processed_onkey;
    char *curr_display;
  };

  struct s_s_disp_arr_1 *val;

  if (mode == GETSETNEW)
    {
      return (void *) acl_malloc2 (sizeof (struct s_s_disp_arr_1));
    }

  if (mode == GETSETRM)
    {
      free (ptr);
      return 0;
    }

  val = (struct s_s_disp_arr_1 *) ptr;

  if (strcmp (name, "processed_onkey") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->processed_onkey;
      if (mode == GETSETGETPTR)
	return (void *) &(val->processed_onkey);
      if (mode == GETSETSET)
	{
	  val->processed_onkey = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "no_fields") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->no_fields;
      if (mode == GETSETGETPTR)
	return (void *) &(val->no_fields);
      if (mode == GETSETSET)
	{
	  val->no_fields = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "no_lines") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->no_lines;
      if (mode == GETSETGETPTR)
	return (void *) &(val->no_lines);
      if (mode == GETSETSET)
	{
	  val->no_lines = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "no_arr") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->no_arr;
      if (mode == GETSETGETPTR)
	return (void *) &(val->no_arr);
      if (mode == GETSETSET)
	{
	  val->no_arr = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "last_arr") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->last_arr;
      if (mode == GETSETGETPTR)
	return (void *) &(val->last_arr);
      if (mode == GETSETSET)
	{
	  val->last_arr = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "srec") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->srec;
      if (mode == GETSETGETPTR)
	return (void *) &(val->srec);
      if (mode == GETSETSET)
	{
	  val->srec = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "arr_elemsize") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->arr_elemsize;
      if (mode == GETSETGETPTR)
	return (void *) &(val->arr_elemsize);
      if (mode == GETSETSET)
	{
	  val->arr_elemsize = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "scr_line") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->scr_line;
      if (mode == GETSETGETPTR)
	return (void *) &(val->scr_line);
      if (mode == GETSETSET)
	{
	  val->scr_line = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "arr_line") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->arr_line;
      if (mode == GETSETGETPTR)
	return (void *) &(val->arr_line);
      if (mode == GETSETSET)
	{
	  val->arr_line = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "highlight") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->highlight;
      if (mode == GETSETGETPTR)
	return (void *) &(val->highlight);
      if (mode == GETSETSET)
	{
	  val->highlight = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "currform") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->currform;
      if (mode == GETSETGETPTR)
	return (void *) &(val->currform);
      if (mode == GETSETSET)
	{
	  val->currform = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "binding") == 0)
    {
      if (mode == GETSETGET)
	return (void *) val->binding;
      if (mode == GETSETGETPTR)
	return (void *) &(val->binding);
      if (mode == GETSETSET)
	{
	  val->binding = (void *) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "nbind") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->nbind;
      if (mode == GETSETGETPTR)
	return (void *) &(val->nbind);
      if (mode == GETSETSET)
	{
	  val->nbind = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp (name, "cntrl") == 0)
    {
      if (mode == GETSETGET)
	return (void *)(long) val->cntrl;
      if (mode == GETSETGETPTR)
	return (void *) &(val->cntrl);
      if (mode == GETSETSET)
	{
	  val->cntrl = (int) var;
	  return (void *) 1;
	}
    }

  if (strcmp(name,"curr_display")==0) {
      if (mode == GETSETGET)
	return (void *) val->curr_display;
      if (mode == GETSETGETPTR)
	return (void *) &(val->curr_display);
      if (mode == GETSETSET)
	{
	  val->curr_display = (void *) var;
	  return (void *) 1;
	}
	  
  }

  A4GL_assertion (1, "CRITICAL ERROR - unknown name in GETSET/s_disp_arr");
  return (void *) 0;		/* unknown value */
}


int A4GL_get_set_as_int(char *str, void *ptr, int mode, char *name, long var) {
int a;
a=(int)((long)A4GL_get_set(str,ptr,mode,name,var)&0xffffffff);
return a;
}

/**
 * Main entry point.
 *
 * @param str Name of structure
 * @param ptr Pointer to structure
 * @param mode NEW/RM/GET/SET
 * @param name Name of element
 * @param var Value to assign
 */
void *
A4GL_get_set (char *str, void *ptr, int mode, char *name, long var)
{
  int a;

  A4GL_debug ("Get_set %s\n", A4GL_null_as_null(str));
  if ((a = atoi (str)) != 0)
    {
      if (a == 0)
	{			/* s_screenio */
	  return get_set_s_screenio (ptr, mode, name, var);
	}
      if (a == 1)
	{			/* s_inp_arr */
	  return get_set_s_inp_arr (ptr, mode, name, var);
	}
      if (a == 2)
	{			/* s_prompt */
	  return get_set_s_prompt (ptr, mode, name, var);
	}

      if (a == 3)
	{			/* rep_structure */
		A4GL_assertion(1,"NOT USED...");
	  //return get_set_rep_structure (ptr, mode, name, var);
	}
      if (a == 4)
	{			/* s_disp_arr */
	  return get_set_s_disp_arr (ptr, mode, name, var);
	}
    }

  if (strcmp (str, "s_screenio") == 0)
    {
      return get_set_s_screenio (ptr, mode, name, var);
    }
  if (strcmp (str, "s_inp_arr") == 0)
    {
      return get_set_s_inp_arr (ptr, mode, name, var);
    }
  if (strcmp (str, "s_prompt") == 0)
    {
      return get_set_s_prompt (ptr, mode, name, var);
    }
  if (strcmp (str, "rep_structure") == 0)
    {
A4GL_assertion(1,"NOT USED");
      //return get_set_rep_structure (ptr, mode, name, var);
    }
  if (strcmp (str, "s_disp_arr") == 0)
    {
      return get_set_s_disp_arr (ptr, mode, name, var);
    }
  A4GL_debug ("No found %s\n", A4GL_null_as_null(str));
  return (void *) 0;
}



/* ================================ EOF ============================== */
