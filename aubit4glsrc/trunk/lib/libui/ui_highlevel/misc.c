
#include "a4gl_libaubit4gl.h"
#include "hl_proto.h"
#include "a4gl_lib_ui_int.h"
#include "a4gl_API_lowlevel.h"
#include "a4gl_API_ui_lib.h"
#include "misc.h"
#include "lowlevel.h"
#ifndef lint
static char const module_id[] =
  "$Id: misc.c,v 1.41 2006-04-05 06:54:38 mikeaubury Exp $";
#endif

//void *UILIB_A4GL_get_curr_form (int n);

int initialized_screen_mode = 0;
#include "formdriver.h"

//void chk_for_picture (void *f, char *buff);

//int A4GL_field_opts_off (void *v, int n);
//int A4GL_field_opts_on (void *v, int n);

int A4GL_LL_fieldnametoid (char *f, char *s, int n);
void *A4GL_get_currwin (void);
int A4GL_UI_int_get_inc_quotes (int a);

void A4GL_clear_menu (ACL_Menu * menu);
int aclfgl_a4gl_show_help (int n);
extern void *inp_current_field;

int
UILIB_aclfgl_a4gl_get_page (int n)
{
  struct s_form_dets *f;
  f = UILIB_A4GL_get_curr_form (1);
  A4GL_push_int (1);		//A4GL_LL_form_page (f->form));
  return 1;
}

int
UILIB_aclfgl_a4gl_set_page (int n)
{
  int b;
  struct s_form_dets *f;
  b = A4GL_pop_int ();
  f = UILIB_A4GL_get_curr_form (1);
  A4GL_LL_set_form_page (f->form, b);
  A4GL_LL_screen_update ();
  return 0;
}


int
UILIB_aclfgl_aclfgl_dump_screen (int n)
{
  char *ptr = "tmpfile";
  int mode = 1;
  if (n == 1)
    {
      ptr = A4GL_char_pop ();
    }
  if (n == 2)
    {
      mode = A4GL_pop_int ();
      ptr = A4GL_char_pop ();
    }
  return A4GL_LL_dump_screen (n, ptr, mode);
}


void
UILIB_A4GL_gui_run_til_no_more ()
{
  A4GL_LL_gui_run_til_no_more ();
}



void
UILIB_A4GL_clr_form (int to_default)
{
  struct s_form_dets *formdets;
  int a;
  int metric_no;
  struct struct_metrics *k;
  void *f;
  int fno;
  int rn;

  A4GLSQL_set_status (0, 0);

  formdets = UILIB_A4GL_get_curr_form (1);

  if (formdets == 0)
    return;


  /* Go through each field */
  for (a = 0; a < formdets->fileform->attributes.attributes_len; a++)
    {
      fno = formdets->fileform->attributes.attributes_val[a].field_no;

      /* And through each metric for this field */
      for (rn = 0;
	   rn < formdets->fileform->fields.fields_val[fno].metric.metric_len;
	   rn++)
	{
	  metric_no =
	    formdets->fileform->fields.fields_val[fno].metric.metric_val[rn];
	  k = &formdets->fileform->metrics.metrics_val[metric_no];
	  f = (void *) k->field;

	  A4GL_debug ("Calling set_field_attr_with_attr for clearing..");

	  A4GL_set_field_attr_with_attr ((void *) formdets->fileform->
					 metrics.metrics_val[metric_no].field,
					 0, FGL_CMD_CLEAR);

	  A4GL_debug ("clr : field = %p", f);
	  if (!to_default)
	    {
	      A4GL_debug ("Blanking field %p MJAMJAMJA", f);
	      A4GL_mja_set_field_buffer (f, 0, "");
	    }
	  else
	    {
	      struct struct_scr_field *prop;
	      prop =
		(struct struct_scr_field *) A4GL_ll_get_field_userptr (f);
	      A4GL_mja_set_field_buffer (f, 0,
					 (char *)
					 A4GL_replace_sql_var ((char *)
							       A4GL_strip_quotes
							       (A4GL_get_str_attribute
								(prop,
								 FA_S_DEFAULT))));
	    }
	}

    }

  A4GL_LL_screen_update ();
}



void
UILIB_A4GL_clr_fields_ap (int to_defaults, va_list * ap)
{
  int a;
  void **field_list;
  struct struct_scr_field *f;
  int c;
  A4GL_debug ("clr_Fields_ap");

  c =
    UILIB_A4GL_gen_field_chars_ap (&field_list, UILIB_A4GL_get_curr_form (1),
				   ap);

  for (a = 0; a <= c; a++)
    {
      A4GL_mja_set_field_buffer (field_list[a], 0, "");
      f =
	(struct struct_scr_field
	 *) (A4GL_ll_get_field_userptr (field_list[a]));
      if (f)
	A4GL_default_attributes (field_list[a], f->datatype,
				 A4GL_has_str_attribute (f, FA_S_PICTURE));
    }

  //if (field_list) free(field_list);
  //else {
  //A4GL_exitwith("no fields found to clear...");
  //}

}



int
UILIB_A4GL_fgl_fieldtouched_input_ap (void *sv, va_list * ap)
{
  int a;
  int c;
  int b;
  void **field_list;
  int found;
  struct s_screenio *s;
  struct struct_scr_field *fprop;
  s = sv;
  A4GL_debug ("fgl_fieldtouched - input ");
  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap);
  if (c >= 0)
    {
      for (a = 0; a < c; a++)
	{
	  found = 0;
	  //A4GL_debug ("fieldtouched void : %p a=%d c=%d - status=%d\n", field_list[a], a, c, field_status (field_list[a]));

	  // Have a look to see if we are currently inputing this one...
	  for (b = 0; b <= s->nfields; b++)
	    {
	      void *ptr1;
	      void *ptr2;


	      ptr1 = field_list[a];


	      ptr2 = field_list[b];

	      A4GL_debug ("Ptr1=%p", ptr1);
	      A4GL_debug ("Ptr2=%p", ptr2);

	      if (ptr1 == ptr2)
		found = 1;


	    }
	  if (!found)
	    {
	      // We don't appear to be...
	      A4GL_exitwith ("Field is not currently being input");
	      return 0;
	    }
	}
      A4GL_debug ("fieldtouched_input - checking field_status");

      for (a = 0; a <= c; a++)
	{

	  A4GL_LL_int_form_driver (s->currform->form, AUBIT_REQ_VALIDATION);
	  fprop =
	    (struct struct_scr_field
	     *) (A4GL_ll_get_field_userptr (field_list[a]));

	  if (fprop->flags & 2)
	    {
	      A4GL_debug ("fieldtouched Field status is set for %p",
			  field_list[a]);
	      free (field_list);
	      return 1;
	    }
	}
      A4GL_debug ("fieldtouched Field status not set for any..");
      free (field_list);
      return 0;

    }
  else
    {
      A4GL_exitwith ("field_touched called with no fields...");
      return 0;
    }
}



int
UILIB_A4GL_fgl_fieldtouched_input_array_ap (void *sv, va_list * ap)
{
  int a;
  int c;
  int b;
  void **field_list;
  //int found;
  struct s_inp_arr *s;
  struct struct_scr_field *fprop;
  s = sv;
  A4GL_debug ("fgl_fieldtouched - input array");


//debug_print_flags(sv,"ft");


  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap);
  if (c >= 0)
    {
      /*
         for (a = 0; a <= c; a++)
         {
         found = 0;
         A4GL_debug ("fieldtouched void : %p a=%d c=%d - status=%d\n",
         field_list[a], a, c, field_status (field_list[a]));

         // Have a look to see if we are currently inputing this one...
         for (b = 0; b <= s->nfields; b++)
         {
         if (field_list[a] == field_list[b])
         found = 1;
         }
         if (!found)
         {
         // We don't appear to be...
         A4GL_exitwith ("Field is not currently being input");
         return 0;
         }
         }
       */


      A4GL_debug ("fieldtouched_input - checking field_status");

      for (a = 0; a <= c; a++)
	{
	  void *f;
	  f = field_list[a];
	  for (b = 0; b < s->nbind; b++)
	    {
	      if (f == s->field_list[0][b])
		{
		  // Found @ position b....
		  fprop =
		    (struct struct_scr_field
		     *) (A4GL_ll_get_field_userptr (s->
						    field_list[s->scr_line -
							       1][b]));
		  if (fprop->flags & 2)
		    {
		      A4GL_debug
			("fieldtouched Field status is set for %p - %d line %d - b=%d",
			 field_list[a], fprop->flags, s->scr_line - 1, b);
		      free (field_list);
		      return 1;
		    }
		}
	    }
	}
      A4GL_debug ("fieldtouched Field status not set for any..");
      free (field_list);
      return 0;

    }
  else
    {
      A4GL_exitwith ("field_touched called with no fields...");
      return 0;
    }
}


int
UILIB_A4GL_fgl_getfldbuf_ap (void *inp, va_list * ap)
{

  void **field_list;
  struct s_screenio *s;
  int c;
  int a;
  int nr;


  s = inp;

  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap);
  nr = 0;
  for (a = 0; a <= c; a++)
    {
      char *buff;
      buff = strdup (A4GL_LL_field_buffer (field_list[a], 0));
      chk_for_picture (field_list[a], buff);
      A4GL_push_char (buff);
      free (buff);
      nr++;
    }
  return nr;
}


int
UILIB_A4GL_fgl_getfldbuf_ia_ap (void *inp, va_list * ap)
{

  void **field_list;
  struct s_inp_arr *s;
  int c;
  int a;
  int nr;
  int b;

  s = inp;

  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap);
  nr = 0;
  for (a = 0; a <= c; a++)
    {
      void *f;
      f = field_list[a];	// f will always be in the first rows of screen fields..
      for (b = 0; b < s->nbind; b++)
	{
	  if (f == s->field_list[0][b])
	    {
	      char *buff;
	      // Found @ position b...
	      A4GL_push_char (A4GL_LL_field_buffer
			      (s->field_list[s->scr_line - 1][b], 0));
	      buff =
		strdup (A4GL_LL_field_buffer
			(s->field_list[s->scr_line - 1][b], 0));
	      chk_for_picture (field_list[a], buff);
	      A4GL_push_char (buff);
	      free (buff);
	      nr++;
	    }
	}
    }
  return nr;
}



int
UILIB_A4GL_fgl_infield_ap (void *inp, va_list * ap)
{
  //struct s_form_dets *f;
  void **field_list;
  struct s_screenio *s;
  int c;
  int a;
  int rval = 0;
  char *colname;
  int field_no;

  if (A4GL_get_curr_form (0) == 0)
    {
      return 0;
    }




  while (1)
    {
      colname = va_arg (*ap, char *);	/* This is suspect.... */
      if (colname == 0)
	break;
      field_no = va_arg (*ap, int);


      if (A4GL_field_name_match ((void *) A4GL_get_curr_infield (), colname))
	{
	  A4GL_debug ("infield - matches");
	  return 1;
	}
    }
  A4GL_debug ("Infield - doesn't match");
  return 0;




  s = inp;

  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap);
  for (a = 0; a <= c; a++)
    {
      //extern void *inp_current_field;
      if (field_list[a] == (void *) inp_current_field)
	{

	  rval = 1;
	  break;
	}
    }

  return rval;
}


int
UILIB_A4GL_fgl_infield_ia_ap (void *inp, va_list * ap)
{
  //struct s_form_dets *f;
  void **field_list;
  struct s_inp_arr *s;
  int c;
  int a;
  int rval = 0;
  char *colname;
  int field_no;
  s = inp;
  if (A4GL_get_curr_form (0) == 0)
    {
      return 0;
    }

  while (1)
    {
      colname = va_arg (*ap, char *);	/* This is suspect.... */
      if (colname == 0)
	break;
      field_no = va_arg (*ap, int);

      if (A4GL_field_name_match ((void *) A4GL_get_curr_infield (), colname))
	{
	  A4GL_debug ("Infield_ia - matches...");
	  return 1;
	}
    }
  A4GL_debug ("Infield_ia - doesn't match");
  return 0;



  c = UILIB_A4GL_gen_field_chars_ap (&field_list, s->currform, ap);
  for (a = 0; a <= c; a++)
    {
      if (field_list[a] == (void *) inp_current_field)
	{

	  rval = 1;
	  break;
	}
    }

  return rval;
}


int
UILIB_A4GL_gen_field_chars_ap (void *field_listv, void *formdetsv,
			       va_list * ap)
{
  int a;
  void ***field_list;
  struct s_form_dets *formdets;

  field_list = field_listv;
  formdets = formdetsv;
#ifdef DEBUG
  {
    A4GL_debug ("Starting A4GL_gen_field_chars %p %p", field_list, formdets);
  }
  {
    A4GL_debug ("Genfldlist 3");
  }
#endif
  A4GL_debug ("gen_field_chars");
  a = A4GL_gen_field_list (field_list, formdets, 9999, ap);
#ifdef DEBUG
  {
    A4GL_debug ("--------------------------------------END gen_field_chars");
  }
#endif
  A4GL_debug ("Gen_field_list returned %d", a);
  return a;
}





int
UILIB_A4GL_push_constr (void *vs)
{
  struct struct_scr_field *fprop;
  void *f;
  int a;
  char *ptr;
  int flg = 0;
  struct s_screenio *s;
  s = vs;

  if (s->processed_onkey == A4GLKEY_INTERRUPT)
    {
      A4GL_push_char (s->vars[0].ptr);
      return 0;
    }



  if (s->nfields < 0)
    {
      A4GL_debug ("NO CONSTRUCT - No fields\n");
      A4GL_push_char ("");
      return 0;
    }
  if (s->currform == 0)
    {
      A4GL_debug ("NO CONSTRUCT - No form\n");
      A4GL_push_char ("");
      return 0;
    }
  A4GL_LL_int_form_driver (s->currform->form, AUBIT_REQ_FIRST_PAGE);

  A4GL_debug ("Push_constr");
  A4GL_debug ("nfields=%d", s->nfields);
  A4GL_debug ("s-field_list[0]=%p", s->field_list[0]);

  for (a = 0; a <= s->nfields; a++)
    {
      A4GL_debug ("Looping a=%d\n", a);
      f = s->field_list[a];
      A4GL_debug ("f=%p", f);
      fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (f));
      A4GL_debug ("fprop=%p", fprop);
      if (fprop != 0)
	{
	  A4GL_debug ("getting ptr", fprop);
	  A4GL_debug ("fprop->colname=%s fprop->datatype=%x", fprop->colname,
		      (fprop->datatype) & 0xffff);


	  //A4GL_debug ("Calling constr with : '%s' '%s'", s->constr[a].tabname, s->constr[a].colname);

	  ptr =
	    (char *) A4GL_construct (s->constr[a].tabname,
				     s->constr[a].colname,
				     A4GL_LL_field_buffer (f, 0),
				     A4GL_UI_int_get_inc_quotes (fprop->
								 datatype));


	  A4GL_assertion (ptr == 0,
			  "Pointer returned from A4GL_construct is null");

	  if (strlen (ptr) > 0)
	    {
	      A4GL_debug ("ptr=%s\n", ptr);
	      if (flg == 0)
		{
		  A4GL_push_char (ptr);
		  flg = 1;
		}
	      else
		{
		  A4GL_push_char (" and ");
		  A4GL_push_char (ptr);
		  A4GL_pushop (OP_CONCAT);
		  A4GL_pushop (OP_CONCAT);
		}
	    }
	}
    }
  if (flg == 0)
    A4GL_push_char (" 1=1");
  return 1;
}


int
UILIB_A4GL_set_fields (void *vsio)
{
  int wid;
  int a;
  int nv;
  int flg;
  char buff[8048];
  struct s_form_dets *formdets;
  struct struct_scr_field *field;
  struct struct_scr_field *prop;
  void **field_list;
  void *firstfield = 0;
  int nofields;
  struct s_screenio *sio;
  int attr;

  sio = vsio;

  wid = 0;
  if (sio->mode == MODE_INPUT_WITHOUT_DEFAULTS
      || sio->mode == MODE_INPUT_ARRAY)
    wid = 1;
  A4GL_debug ("in set fields");
  formdets = sio->currform;
  if (formdets == 0)
    {
      A4GL_exitwith ("No form");
      return 0;
    }
  A4GL_debug ("set fdets");

  flg = 0;

  A4GL_debug ("Turning off all");

  for (a = 0; formdets->form_fields[a] != 0; a++)
    {
      field =
	(struct struct_scr_field
	 *) (A4GL_ll_get_field_userptr (formdets->form_fields[a]));
      if (field == 0)
	continue;

      if (A4GL_turn_field_off (formdets->form_fields[a]))
	{
	  firstfield = formdets->form_fields[a];
	}

    }

  nofields = sio->nfields;
  field_list = (void **) sio->field_list;

  A4GL_debug ("Field list=%p number of fields = %d", field_list, nofields);
  nv = sio->novars;
  if (sio->mode == MODE_CONSTRUCT)
    {
      int a;
      int need_fix = 0;
      // sio->constr contains a s_constr_list structure
      // this may need explanding if the column contains a '*'
      for (a = 0; a < nv; a++)
	{
	  if (strcmp (sio->constr[a].colname, "*") == 0)
	    {			// It'll need expanding...
	      need_fix = 1;
	    }
	}
      if (need_fix)
	{
	  A4GL_exitwith
	    ("Construct needs fixing to handle 'byname on tab.*'");
	  sio->nfields = 0;
	  return 0;
	}
    }

  if (nofields != nv - 1)
    {
      A4GL_debug
	("Number of fields (%d) is not the same as the number of vars (%d)",
	 nofields + 1, nv);
      A4GL_exitwith
	("Number of fields is not the same as the number of variables");
      sio->nfields = 0;
      return 0;
    }





  for (a = 0; a < nv; a++)
    {

      if (field_list[a] == firstfield)
	{
	  firstfield = 0;
	}
      A4GL_debug ("loop through fields a=%d %p", a, field_list[a]);
      A4GL_turn_field_on2 (field_list[a], sio->mode != MODE_CONSTRUCT);

      if (wid)
	{
	  A4GL_debug ("99 wid set_init_value as in variable");
	  A4GL_set_init_value (field_list[a], sio->vars[a].ptr,
			       sio->vars[a].dtype +
			       ENCODE_SIZE (sio->vars[a].size));


	}
      else
	{
	  prop =
	    (struct struct_scr_field *)
	    A4GL_ll_get_field_userptr (field_list[a]);
	  if (A4GL_has_str_attribute (prop, FA_S_DEFAULT)
	      && sio->mode != MODE_CONSTRUCT)
	    {
	      A4GL_debug ("99  set_init_value from form");
	      A4GL_debug ("default from form to '%s'",
			  A4GL_get_str_attribute (prop, FA_S_DEFAULT));

	      A4GL_set_init_value (field_list[a],
				   A4GL_replace_sql_var (A4GL_strip_quotes
							 (A4GL_get_str_attribute
							  (prop,
							   FA_S_DEFAULT))),
				   0);

	    }
	  else
	    {
	      A4GL_debug ("99  set_init_value as nothing...");
	      A4GL_set_init_value (field_list[a], 0, 0);
	    }
	}

      if (sio->mode != MODE_CONSTRUCT)
	{
	  prop =
	    (struct struct_scr_field *)
	    A4GL_ll_get_field_userptr (field_list[a]);
	  strcpy (buff, A4GL_LL_field_buffer (field_list[a], 0));
	  A4GL_trim (buff);

	  if (strlen (buff))
	    {
	      A4GL_push_char ((char *)
			      A4GL_fld_data_ignore_format (prop, buff));
	    }
	  else
	    A4GL_push_null (sio->vars[a].dtype, sio->vars[a].size);	// @todo - check if its set to not null and return CHARs instead..

	  A4GL_pop_var2 (sio->vars[a].ptr, sio->vars[a].dtype,
			 sio->vars[a].size);
	}

      if (flg == 0)
	{
	  A4GL_LL_set_current_field (formdets->form, field_list[a]);
	  /*formdets->form_fields[z]); */
	  flg = 1;
	}


      prop =
	(struct struct_scr_field *) A4GL_ll_get_field_userptr (field_list[a]);

      attr = A4GL_determine_attribute (FGL_CMD_INPUT, sio->attrib, prop, 0);

      if (attr != 0)
	A4GL_set_field_attr_with_attr (field_list[a], attr, FGL_CMD_INPUT);

      A4GL_LL_set_field_status (field_list[a], 0);
      prop->flags = 0;
    }

  if (firstfield)
    A4GL_turn_field_off (firstfield);

  if (flg == 0)
    {
      A4GL_LL_error_box ("No active field\n", 0);
    }
  A4GL_LL_screen_update ();
  return 1;
}




void
UILIB_aclfgli_pr_message_internal (int attr, int wait, char *s)
{
  char p[2048];
  //long w;
  int ml;
  int width;
  //char *s;
  //char *ptr_pop;
  void *cw;
  char buff[512];
  //static void *mw;
  A4GL_chkwin ();
  A4GL_debug ("In message...");
  cw = (void *) A4GL_get_currwin ();
  ml = A4GL_getmessage_line ();

  if (ml < 0)
    {
      A4GL_exitwith ("Internal error - negative messageline");
      return;
    }
  A4GL_debug ("MJA - Got message line as %d - %s\n", ml, s);




  if (A4GL_LL_can_show_message(ml,s,wait)) {
	  return;
  }
	



  width = UILIB_A4GL_get_curr_width ();
  //A4GL_push_char(s);

  strcpy (p, s);
  //A4GL_pop_char (p, width);

  if (strlen (p) == 0)
    {
      memset (p, ' ', sizeof (p));
      p[A4GL_get_curr_width ()] = 0;

    }
  A4GL_debug ("Message : '%s'", p);
  A4GL_push_char (p);

  A4GL_debug (" Wait =%d\n", wait);

  if (wait == 0)
    {
      // Blank out the line...
      memset (buff, ' ', sizeof (buff));
      buff[A4GL_get_curr_width ()] = 0;
      A4GL_push_char (buff);
      A4GL_push_int (ml);
      A4GL_push_int (1);
      A4GL_display_at (1, 0);

      A4GL_push_int (ml);
      A4GL_push_int (1);
      A4GL_display_at (1, attr);
    }
  else
    {
      /* Need to pad this out later... */
      A4GL_push_int (ml);
      A4GL_push_int (1);
      A4GL_display_at (1, attr);
    }
  return;			/* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< */

}


void
chk_for_picture (void *f, char *buff)
{
  struct struct_scr_field *fprop;
  char *picture;

  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (f));

  if (A4GL_has_str_attribute (fprop, FA_S_PICTURE))
    {
      int a;
      int blank = 1;
      picture = A4GL_get_str_attribute (fprop, FA_S_PICTURE);
      A4GL_debug ("HAS PICTURE MJA123");
      for (a = 0; a < strlen (buff); a++)
	{
	  if (picture[a] == 'X' && buff[a] != ' ')
	    {
	      blank = 0;
	      break;
	    }
	  if (picture[a] == 'A' && buff[a] != ' ')
	    {
	      blank = 0;
	      break;
	    }
	  if (picture[a] == '#' && buff[a] != ' ')
	    {
	      blank = 0;
	      break;
	    }
	}
      if (blank)
	strcpy (buff, "");
    }
  A4GL_trim (buff);
}




void
A4GL_clear_menu (ACL_Menu * menu)
{
/*
  void *w;
  w = A4GL_find_pointer (menu->window_name, WINCODE);
  A4GL_del_pointer (menu->window_name, WINCODE);
  A4GL_LL_remove_window (w);
*/

}


int
A4GL_turn_field_off (void *f)
{
  struct struct_scr_field *fprop;
  int a;
  fprop = (struct struct_scr_field *) (A4GL_ll_get_field_userptr (f));
  a = A4GL_field_opts_off (f, AUBIT_O_ACTIVE);
  a += A4GL_field_opts_off (f, AUBIT_O_EDIT);
  if (a == 0)
    return 0;
  return 1;

}


void
A4GL_initialize_screen_mode (void)
{
  A4GL_debug ("initialize_screen_mode");
  A4GL_set_scrmode ('S');
  A4GL_LL_initialize_display ();
  A4GL_debug ("Call set scrmode");
  A4GL_debug ("Call init_windows");
  A4GL_init_windows ();
}

void
A4GL_switch_to_scr_mode (void)
{
  A4GL_debug ("switch_to_scr_mode");
  if (initialized_screen_mode == 0)
    {
      initialized_screen_mode = 1;
      A4GL_debug ("Initialize screen mode");
      A4GL_initialize_screen_mode ();
    }
  A4GL_debug ("LL_screen_mode");
  A4GL_LL_screen_mode ();
  A4GL_debug ("All done..");
}


void
UILIB_A4GL_zrefresh ()
{
  A4GL_LL_screen_update ();
}






int
UILIB_A4GL_endis_fields_ap (int en_dis, va_list * ap)
{
  return A4GL_LL_endis_fields_ap (en_dis, ap);

}


int
UILIB_A4GL_open_gui_form_internal (long *form_variable, char *name_orig,
				   int absolute, int nat, char *like,
				   int disable, void *handler_e,
				   void *handler_c)
{
  int n;
  A4GL_chkwin ();
  n =
    A4GL_LL_open_gui_form (name_orig, absolute, nat, like, disable, handler_e,
			   handler_c);
  *form_variable = n;
  A4GL_LL_screen_update ();
  return n;

}



void
UILIB_A4GL_clr_form_fields (int to_defaults, char *defs)
{
  A4GL_chkwin ();
  A4GL_LL_clr_form_fields (to_defaults, defs);
}


void
UILIB_A4GL_init_color (int n, int r, int g, int b)
{
	// Does nothing in this version...
	A4GL_LL_init_color(n,r,g,b);
}


int
UILIB_A4GL_disp_form_fields_ap (int n, int attr, char *formname, va_list * ap)
{
  A4GL_chkwin ();
  return A4GL_LL_disp_form_fields_ap (n, attr, formname, ap);

}


int
UILIB_aclfgl_set_window_title (int nargs)
{
  char *s;
  int rval;
  A4GL_chkwin ();
  s=A4GL_char_pop();
  rval=A4GL_LL_set_window_title (A4GL_get_currwin (), s);
  return rval;
}




int
UILIB_A4GL_widget_name_match (void *w, char *name)
{
  A4GL_chkwin ();
  return A4GL_LL_widget_name_match (w, name);
}


int
UILIB_aclfgl_a4gl_run_gui (int nargs)
{
  while (1)
    A4GL_LL_screen_update ();
  return 1;
}


int
UILIB_A4GL_fgl_fieldnametoid (char *f, char *s, int n)
{
  return A4GL_LL_fieldnametoid (f, s, n);
}





void
UILIB_A4GL_finish_screenio (void *sio, char *siotype)
{
  if (strcmp (siotype, "s_inp_arr") == 0)
    {
      A4GL_comments (0);
    }

  if (strcmp (siotype, "s_screenio") == 0)
    {
      A4GL_comments (0);
    }
  A4GL_LL_finished_with_events(sio);
}

void *
UILIB_A4GL_create_menu (void *m, char *id, int mode, void *handler)
{
  return A4GL_LL_create_menu (m, id, mode, handler);

}


void
UILIB_A4GL_reset_delims (void *vformdets, void *field, char *delims)
{
  struct s_form_dets *formdets;
  int a;
  char sbuff0[2];
  char sbuff1[2];
  formdets = vformdets;
  sbuff0[0] = delims[0];
  sbuff0[1] = 0;
  sbuff1[0] = delims[1];
  sbuff1[1] = 0;

  for (a = 0; a < formdets->fileform->metrics.metrics_len; a++)
    {
      if (field
	  && (void *) formdets->fileform->metrics.metrics_val[a].field !=
	  field)
	continue;

      A4GL_mja_set_field_buffer ((void *) formdets->fileform->metrics.
				 metrics_val[a].dlm1, 0, sbuff0);
      A4GL_mja_set_field_buffer ((void *) formdets->fileform->metrics.
				 metrics_val[a].dlm2, 0, sbuff1);
    }
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



int
A4GL_getch_win (int allow_acc_intr)
{
  int a;
  A4GL_debug ("getch_win called...");
  if (allow_acc_intr)
    {
      A4GL_LL_set_acc_intr_keys (1);
    }
  a = A4GL_getch_internal (A4GL_get_currwin ());
  if (a) A4GL_clr_error_nobox ("A4GL_getch_win");
  if (allow_acc_intr)
    {
      A4GL_LL_set_acc_intr_keys (0);
    }
  return a;
}




int
A4GL_get_field_width (void *f)
{
  //int x, y, a;
  int w;
  struct s_form_dets *formdets;
  struct s_scr_field *fprop;

  if (f==0) return 0;

  fprop 	= (struct s_scr_field *) (A4GL_ll_get_field_userptr (f));
  formdets 	= (struct s_form_dets *) A4GL_get_curr_form (0);

  if (formdets == 0 || fprop == 0)
    {
	    	A4GL_pause_execution();
      return A4GL_LL_get_field_width_dynamic (f);
    }

  w =
    formdets->fileform->metrics.
    metrics_val[A4GL_get_metric_for (formdets, f)].w;

  return w;
}
