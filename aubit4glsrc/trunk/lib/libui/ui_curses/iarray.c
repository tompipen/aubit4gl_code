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
# $Id: iarray.c,v 1.3 2002-09-26 01:32:15 afalout Exp $
#*/

/**
 * @file
 * Input array implementation
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


#include "a4gl_lib_ui_tui_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern int m_lastkey;
extern WINDOW *currwin;
struct s_inp_arr *curr_arr_inp;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 *
 * @param
 */
static void
iclear_srec_line (struct struct_screen_record *srec,int line)
{
int a;
char srec1[256];

  strcpy (srec1, srec->name);
  strcat (srec1, ".*");

  for (a = 0; a < srec->attribs.attribs_len + 1; a++)
	{
	  push_char (" ");
	}
      idisp_arr_fields (srec->attribs.attribs_len + 1, 0, 0, srec1, line + 1, 0, 0);
}

/**
 *
 *
 * @param
 */
static void
idraw_arr (struct s_inp_arr *disp, int type, int no)
{
  char srec2[256];
  int topline;
  int scr_line;
  int fonly = 0;
#ifdef DEBUG
  {    debug ("in draw_arr %p %d %d", disp, type, no);  }
#endif
  if (type < 0)
    {
      type = 0 - type;
      fonly = 1;
    }

  debug("*** no=%d disp->no_arr=%d\n", no,disp->no_arr);

  topline = disp->arr_line - disp->scr_line + 1;
  scr_line = no - topline + 1;

  if (scr_line>disp->srec->dim) {
	debug("scr line out of range %d %d\n",scr_line,disp->srec->dim);
	 return;
  }

  if (no>disp->no_arr) {
	  debug("arr no out of range %d %d\n",scr_line,disp->srec->dim);
          iclear_srec_line (disp->srec,scr_line-1);
	  return;
  }
 
  strcpy (srec2, disp->srec->name);
  strcat (srec2, ".*");

  if (type == 2)
    {
      debug ("calling set_arr_Fields");
      set_arr_fields (disp->nbind, 1, srec2, scr_line, 0, 0);
#ifdef DEBUG
      {	debug ("Done");      }
#endif
      return;
    }


  if (fonly)
    push_bind (disp->binding, 1, no, disp->arr_elemsize);
  else
    push_bind (disp->binding, disp->nbind, no, disp->arr_elemsize);

  debug ("Print array no %d to scr %d", no, scr_line);
  debug ("calling disp_arR_fields");
  if (disp->highlight)
    {
      debug ("With highlight");
      idisp_arr_fields (disp->nbind, fonly, type * A_REVERSE, srec2, scr_line, 0, 0);
    }
  else
    {
      debug ("Without highlight");
      idisp_arr_fields (disp->nbind, fonly, 0, srec2, scr_line, 0, 0);
    }
}

/**
 *
 *
 * @param
 */
static void
iclear_srec (struct struct_screen_record *srec)
{
int b;

  for (b = 0; b < srec->dim; b++)
    {
	iclear_srec_line(srec,b);
    }
}

/**
 *
 *
 * @param
 */
static void
idraw_arr_all (struct s_inp_arr *disp)
{
  int a;
  int topline;
  topline = disp->arr_line - disp->scr_line + 1;
#ifdef DEBUG
  {    debug ("Draw_arr_all");  }
#endif
  for (a = 0; a < disp->srec->dim; a++)
    {
      /* if (a + topline < disp->no_arr)
	{
    */
	  idraw_arr (disp, a + topline == disp->arr_line, a + topline);
#ifdef DEBUG
	  {	    debug ("after draw_arr (6)");	  }
#endif
	/* } */
    }
  idraw_arr (disp, 1, disp->arr_line);
#ifdef DEBUG
  {    debug ("after draw_arr (7)");  }
#endif
  mja_refresh ();
}

/**
 *
 *
 * @param
 */
static void
iredisplay_arr (struct s_inp_arr *arr, int redisp)
{

  debug("scr_line=%d arr_line=%d\n",arr->scr_line,arr->arr_line);
  if (redisp == 1)
    {
      debug ("Redisplay one");
      idraw_arr (arr, 0, arr->last_arr);
#ifdef DEBUG
      {	debug ("after draw_arr (4)");      }
#endif
      debug ("Display one");
      idraw_arr (arr, 1, arr->arr_line);
#ifdef DEBUG
      {	debug ("after draw_arr (5)");      }
#endif
    }
  if (redisp == 2)
    {
      debug ("Redisplay all");
      idraw_arr_all (arr);
    }
  mja_wrefresh (currwin);
}

/**
 *
 *
 * @param
 */
/*
static char *
proc_zero(char *s)
{
  static char *buff="Not Set";
  if (s==0)
    return buff;
  else
    return s;
}
*/

/**
 * It have a direct return
 * @todo Confirm if its like this and if remove the rest of the code
 */
static void debug_print_field(FIELD *f)
{
  return;
#ifdef OLDFORMDEFINITION
	attr=(struct s_field_attr *) field_userptr(f);
	debug_print_field_opts(f);
	/* debug("attr=%p",f,attr); */
		debug("Value='%s':",field_buffer(f,0));
	if (attr) {
		debug("      Datatype   : %d:",attr->dtype);
		debug("      Field No   : %d:",attr->field_no);
		debug("      Tabname    : %s:",proc_zero(attr->tabname));
		debug("      Colname    : %s:",proc_zero(attr->colname));
		debug("      Metrics    : %d:",attr->metrics_cnt);
		/*
		debug("      sub1       : %s:",proc_zero(attr->sub1));
		debug("      sub2       : %s:",proc_zero(attr->sub2));
        */
		debug("      autonext   : %d:",attr->autonext);
		debug("      invisible  : %d:",attr->invisible);
		debug("      noentry    : %d:",attr->noentry);
		debug("      required   : %d:",attr->required);
		debug("      reverse    : %d:",attr->reverse);
		debug("      shift      : %d:",attr->shift);
		debug("      verify     : %d:",attr->verify);
		debug("      wordwrap   : %d:",attr->wordwrap);
		debug("      colour     : %d:",attr->colour);
		debug("      include    : %s:",proc_zero(attr->include));
		debug("      comments   : %s:",proc_zero(attr->comments));
		debug("      default_val: %s:",proc_zero(attr->default_val));
		debug("      format     : %s:",proc_zero(attr->format));
		debug("      picture    : %s:",proc_zero(attr->picture));
		debug("      program    : %s:",proc_zero(attr->program));
		debug("      dynamic    : %d\n\n:",attr->dynamic);
	}
#endif
}

/**
 *
 *
 * @param
 */
static void
debug_print_field_list(FIELD **fld_list)
{
  int a;
  debug("Field List (%p)",fld_list);
  for (a=0;fld_list[a];a++) {
    debug_print_field(fld_list[a]);
  }
}

/**
 *
 *
 * @param
 */
static int 
pop_iarr_var(struct s_form_dets *form,int x,int y,int elem,
		    struct BINDING *b) 
{
  debug("In pop_iarr_var %d %d",x,y);
  y--;

  if (copy_field_data(form)) 
  {
    push_char(field_buffer(form->currentfield,0));
    debug("Pushed field buffer");
    pop_var2((char *)b[x].ptr+(y*elem), b[x].dtype, b[x].size);
    debug("Popped field buffer into variable");
    return 1;
  }
  return 0;
}

/**
 *
 *
 * @param
 */
static int 
idisp_loop (struct s_inp_arr *arr)
{
  struct s_form_dets *form;
  int a;
  int redisp;
  FORM *mform;
  curr_arr_inp = arr;
  form = arr->currform;
  set_array_mode ('I');
  
  m_lastkey = 0;
#ifdef DEBUG
  {    debug ("Currform=%p (s_form_dets)", form);  }
#endif
  if (form != get_curr_form ())
    {
      exitwith ("Input form is not the current form!");
      exit (0);
    }
  mform = form->form;
#ifdef DEBUG
  {    debug ("FORM=%p", mform);  }
#endif
  if (arr->cntrl != 0)
    {
      a = arr->cntrl;
      arr->cntrl = 0;
    }
  else
    {
      idraw_arr (arr, 2, arr->arr_line);
#ifdef DEBUG
      {	debug ("after draw_arr (3) mform=%p", mform);      }
      {	debug ("Searching for form");      }
      {	find_ptr_debug (form);      }
      {	debug ("Searching for mform");      }
      {	find_ptr_debug (mform);     }
      {	debug ("form_win(mform)=%p", form_win (mform));      }
#endif
debug("Printing field list");
      debug_print_field_list(form_fields(mform));
debug("Setting current field");
	form->currentfield=arr->field_list[arr->scr_line-1][arr->curr_attrib];
debug("Setting current field..");
      set_current_field(mform,arr->field_list[arr->scr_line-1][arr->curr_attrib]);
debug("Positioning character");

      pos_form_cursor(mform);
debug("Before do update");
      doupdate();
debug("Getting char");
      a = getch_win ();
      m_lastkey = a;
    }
  redisp = 0;
  
  if (a>0&&a<255) {
	int_form_driver(mform,a);
	int_form_driver(mform,REQ_VALIDATION);
  }
	
  if (a==KEY_LEFT&&mform->curcol==0&&mform->currow==0) {
	a=KEY_BACKSPACE;
  }
  
  if (a==key_val ("ACCEPT")) {a=27;}

  if (a==key_val ("NEXT")) { a=KEY_NPAGE; }
  if (a==key_val ("PREV")) { a=KEY_PPAGE; }

  switch (a)
    {
    case KEY_NPAGE:
      debug ("Page down");
      if (pop_iarr_var(arr->currform,arr->curr_attrib,arr->arr_line,arr->arr_elemsize,arr->binding)) {
      if (arr->arr_line < arr->no_arr)
	{
	  arr->cntrl = 0 - KEY_NPAGE;
	  return -11;
	}
	}
      break;

    case KEY_PPAGE:
      debug ("Page up");
      if (pop_iarr_var(arr->currform,arr->curr_attrib,arr->arr_line,arr->arr_elemsize,arr->binding)) {
      if (arr->arr_line> 0)
	{
	  arr->cntrl = 0 - KEY_PPAGE;
	  return -11;
	}
	}
      break;


    case KEY_DOWN:
      debug ("Key down");
      if (pop_iarr_var(arr->currform,arr->curr_attrib,arr->arr_line,arr->arr_elemsize,arr->binding)) {

      if (arr->arr_line < arr->no_arr)
	{
	  arr->cntrl = 0 - KEY_DOWN;
	  return -11;
	}

      if ((arr->arr_line == arr->no_arr) && (arr->arr_line<arr->arr_size))
	{
 		if (arr->inp_flags & (0x01!=0x01))
		{
	  		set_arr_count(arr->no_arr+1);
	  		arr->no_arr++;
	  		arr->cntrl = 0 - KEY_DOWN;
	  		return -11;
		}
	}

	}
      break;

    case 0 - KEY_NPAGE:
      debug ("pagedown +");
      arr->last_arr=arr->arr_line;
      arr->arr_line+=arr->srec->dim;

      if (arr->arr_line>=arr->no_arr) arr->arr_line=arr->no_arr;

      debug ("Is really down %d", arr->arr_line);
      redisp = 1;
      iredisplay_arr (arr, 2);
      set_arr_curr (arr->arr_line);
      set_scr_line (arr->scr_line);
      return -10;
      break;

    case 0 - KEY_PPAGE:
      debug ("pageup +");
      arr->last_arr = arr->arr_line;
      arr->arr_line-=arr->srec->dim;
      if (arr->arr_line<=0) {
		arr->arr_line=1;
      }

      if (arr->arr_line-arr->scr_line<=0) {
		arr->scr_line=1;
      }

      debug ("Is really down %d", arr->arr_line);
      redisp = 1;
      iredisplay_arr (arr, 2);
      set_arr_curr (arr->arr_line);
      set_scr_line (arr->scr_line);
      return -10;
      break;



    case 0 - KEY_DOWN:
      debug ("Keydown +");
      arr->last_arr = arr->arr_line;
      arr->arr_line++;
      debug ("Is really down %d", arr->arr_line);
      redisp = 1;
      arr->scr_line++;
      if (arr->scr_line > arr->srec->dim)
	{
	  arr->scr_line = arr->srec->dim;
	  iredisplay_arr (arr, 2);
	}
      else
	{
	  iredisplay_arr (arr, 1);
	}
      set_arr_curr (arr->arr_line);
      set_scr_line (arr->scr_line);
      return -10;
      break;

    case KEY_RIGHT:
	debug("Key_right");
	int_form_driver(mform,REQ_NEXT_CHAR);
	break;

    case KEY_LEFT:
	debug("Key_left");
	int_form_driver(mform,REQ_PREV_CHAR);
	break;


    case 10:
    case 13:
    case '\t':
      if (pop_iarr_var(arr->currform,arr->curr_attrib,arr->arr_line,arr->arr_elemsize,arr->binding)) {
	if (arr->curr_attrib<arr->srec->attribs.attribs_len) {
		arr->curr_attrib++;
	  arr->cntrl = 1001;
	  return -1000;
	}
	}
	break;

    case KEY_BACKSPACE:
      if (pop_iarr_var(arr->currform,arr->curr_attrib,arr->arr_line,arr->arr_elemsize,arr->binding)) {
	if (arr->curr_attrib>0) {
		arr->curr_attrib--;
	  arr->cntrl = 1002;
	return -1001;
	}
	}
	break;



    case KEY_UP:
      if (pop_iarr_var(arr->currform,arr->curr_attrib,arr->arr_line,arr->arr_elemsize,arr->binding)) {
      if (arr->arr_line > 1)

	{

	  arr->cntrl = 0 - KEY_UP;

	  return -11;

	}
	}
      break;

    case 0 - KEY_UP:
      arr->last_arr = arr->arr_line;
      arr->arr_line--;
      debug ("Is really up");
      arr->scr_line--;
      if (arr->scr_line == 0)

	{

	  arr->scr_line = 1;

	  iredisplay_arr (arr, 2);

	}
      else
	{

	  iredisplay_arr (arr, 1);

	}
      set_arr_curr (arr->arr_line);
      set_scr_line (arr->scr_line);
      return -10;
      break;

    case  27:
      if (pop_iarr_var(arr->currform,arr->curr_attrib,arr->arr_line,arr->arr_elemsize,arr->binding)) {
      return 0;			/* escape */
	}

    case 26:			/* control-z */
      if (pop_iarr_var(arr->currform,arr->curr_attrib,arr->arr_line,arr->arr_elemsize,arr->binding)) {
      return 0;
	}
    }
  return -90;
}

/**
 *
 *
 * @param
 */
static int 
gen_field_list_vals(void *a,void *b,int nv,...)
{
  va_list va;
  va_start(va,nv);
  return gen_field_list(a,b,nv,&va);
}

/**
 *
 *
 * @param
 */
static FIELD ***
gen_srec_field_list(char *s,struct s_form_dets *form,int a,int d)
{
  FIELD ***fld_list;
  int fc;
  int lc;
  char buff[64];
  debug("Generating field list for screen array");

  fld_list=(FIELD ***) calloc(d,sizeof(FIELD **));

  for (lc=0;lc<d;lc++) 
  {
    debug("Generating field list for line %d",lc);
    strcpy(buff,s);
    strcat(buff,".*");
    debug("calling gen_field_list_vals with %p %p %d %s %d %d",
      &fld_list[lc],form,a,buff,lc,0
    );
    fc=gen_field_list_vals(&fld_list[lc],form,a,buff,lc+1,0,0);
    debug(">>>> fc=%d fld_list[lc]=%p",fc,fld_list[lc]);
  }

  debug("Field lists (gen_srec_field_list)");
  
  for (lc=0;lc<d;lc++) 
  {
    debug("Srec line : %d %p",lc,fld_list[lc]);
    for (fc=0;fc<a;fc++) 
    {
      debug("Line %d Col %d Field %p:",lc,fc,fld_list[lc][fc]);
    }
  }
  debug("End of list");
  return fld_list;
}

/**
 * Implementation of input array.
 *
 * Called by generated code for corresponding of input array 
 * its part of run-time library.
 * 
 * @param disp
 * @param ptr
 * @param srecname Screen Record name
 * @param attrib Attributes used during input array
 * @return
 */
int
inp_arr (struct s_inp_arr *disp, void *ptr, char *srecname, int attrib)
{
FIELD ***fld_list;
int a;

  curr_arr_inp = disp;
  debug ("In disp_arr : %s %p %p %d", srecname, ptr, disp, attrib);
  if (disp->srec == 0)
    {
      debug ("disparr1");
      disp->srec = get_srec (srecname);
       debug(">>>>disp->srec=%p",disp->srec);

      if (disp->srec == 0)
	return 0;
      disp->currform = get_curr_form ();
	#ifdef DEBUG
      {	debug ("disp->currform=%p", disp->currform);      }
	#endif
      disp->last_arr = -1;
      disp->scr_line = 1;
      disp->arr_line = 1;
      disp->cntrl = 1;
      disp->highlight = 0;
	  debug("********** no_arr=%d\n",disp->no_arr);
      set_arr_curr (disp->arr_line);
      set_scr_line (disp->scr_line);
      set_arr_count(disp->no_arr);
      /* debug ("Srec dimension name=%s dim=%d no_Attr=%d", disp->srec->name, disp->srec->dim, disp->srec->attribs.attribs_len); */
      debug ("disparr2");
      if (disp->srec == 0)

	{

	  debug ("Screen record does not exist");

	  return 0;

	}
      debug ("disparr3");

      if (disp->srec->attribs.attribs_len  != disp->nbind)

	{

	  debug ("Too many or too few variables for fields %d %d",
		 disp->srec->dim, disp->nbind
	    );

	  return 0;

	}

      debug ("Clearing Record");
      iclear_srec (disp->srec);
      debug ("Cleared record");

      fld_list=gen_srec_field_list(disp->srec->name,disp->currform,disp->srec->attribs.attribs_len+1,disp->srec->dim);
      debug("All done...");
      disp->field_list=(void ***)fld_list;

      /*
        FIELD ***fld_list;
		struct s_inp_arr *disp

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

	#ifdef DEBUG
		/*
      for (x=0;x<disp->srec->attribs.attribs_len;x++) {

      for (y=0;y<disp->srec->dim;y++) {
           debug("Setting pos %d %d",x,y);
	   sprintf(buff,"%d,%d",x,y);
           debug("Setting to %s",buff);
           mja_set_field_buffer(fld_list[y][x],0,buff);
           }
      }
	   update_panels();
           doupdate();
		*/
      debug("Array dimensions : %d %d",disp->srec->dim,disp->srec->attribs.attribs_len);
      for (a=0;a<disp->srec->attribs.attribs_len;a++) {
            debug("          Attrib %d = %d:",a,disp->srec->attribs.attribs_val[a]);
      }

	#endif

      for (a = 0; a < disp->srec->dim; a++)

	{

	  if (a < disp->no_arr)

	    {

		#ifdef DEBUG
	      {	debug ("call draw_arr (1)");	      }
		#endif
	      idraw_arr (disp, a + 1 == disp->arr_line, a + 1);

		#ifdef DEBUG
	      {	debug ("after draw_arr (1)");	      }
		#endif
	    }

	}
		#ifdef DEBUG
    	  {	debug ("call draw_arr (2) %p %d",disp,disp->arr_line);      }
		#endif

      idraw_arr (disp, 1, disp->arr_line);

		#ifdef DEBUG
	      {	debug ("after draw_arr (2)");      }
		#endif

      gui_scroll (disp->no_arr);
      set_arr_curr (disp->arr_line);
      set_scr_line (disp->scr_line);
      set_arr_count(disp->no_arr);
      mja_wrefresh (currwin);
      disp->curr_attrib=0;

      return -10;
    }
  debug ("disparr4");
  return idisp_loop (disp);
}


/**
 * I think its not used because the function that calls it its not used
 */
/*
int
set_scrline_ia (int np)
{
  int a;
  if (np != 1)
    {
      exitwith ("set_scrline requires 1 parameter");
      return 0;
    }
  a = pop_int ();
  curr_arr_inp->scr_line = a;
  set_scr_line (a);
  idraw_arr_all (curr_arr_inp);
#ifdef DEBUG
  {    debug ("Set scrline...%d", a);  }
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
      exitwith ("set_arrline requires 1 parameter");
      return 0;
    }
  a = pop_int ();
  curr_arr_inp->arr_line = a;
  set_arr_curr (a);
  idraw_arr_all (curr_arr_inp);
#ifdef DEBUG
  {    debug ("Set arrline... %d", a);  }
#endif
    return 1;
}
*/

/**
 * Not used
 *
 * @todo Confirm if its not used and deleted if so
 */
/*
static void
debug_print_all_fields(FORM *f)
{
  FIELD **fld_list;
  fld_list=form_fields(f);
  debug_print_field_list(fld_list);
}
*/

/* ================================= EOF ============================== */

