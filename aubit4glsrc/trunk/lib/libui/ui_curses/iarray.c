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
# $Id: iarray.c,v 1.9 2003-03-29 16:48:31 mikeaubury Exp $
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


//#include "a4gl_lib_ui_tui_int.h"
#include "a4gl_lib_ui_int.h"
int disp_fields (int n, int attr, ...);


/*
=====================================================================
                    Variables definitions
=====================================================================
*/

extern int m_lastkey;
struct s_inp_arr *curr_arr_inp;
int iarr_loop (struct s_inp_arr *arr,int init);

int gen_field_chars(void * field_list, struct s_form_dets *formdets,...);


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



void iarr_arr_fields (int n, int attr, char *fldname,int fldline) {
	debug("Iarr_arr_fields n=%d attr=%d fldname=%s fldline=%d",
		n,attr,fldname,fldline);
  	disp_fields(n,attr,fldname,fldline,0);
}


static void
iclear_srec_line (struct struct_screen_record *srec, int line)
{
  int a;
  char srec1[256];

  strcpy (srec1, srec->name);
  strcat (srec1, ".*");

  for (a = 0; a < srec->attribs.attribs_len + 1; a++)
    {
      push_char (" ");
    }


  iarr_arr_fields (srec->attribs.attribs_len + 1,  0, srec1, line + 1);
}


static void
iclear_srec (struct struct_screen_record *srec)
{
  int b;

  for (b = 0; b < srec->dim; b++)
    {
      iclear_srec_line (srec, b);
    }
}



static void
idraw_arr (struct s_inp_arr *disp, int no)
{
  char srec2[256];
  int topline;
  int scr_line;

  topline = disp->arr_line - disp->scr_line + 1;
  scr_line = no - topline + 1;

  if (scr_line > disp->srec->dim)
    {
      return;
    }

  if (no > disp->no_arr)
    {
      iclear_srec_line (disp->srec, scr_line - 1);
      return;
    }

  strcpy (srec2, disp->srec->name);
  strcat (srec2, ".*");

  push_bind_reverse (disp->binding, disp->nbind, no, disp->arr_elemsize);

  iarr_arr_fields (disp->nbind,  0, srec2, scr_line);
}






int iarr_loop (struct s_inp_arr *arr,int init) {
int a=0;
static int i_want_to_move_line=0;
static int movement;
char buff[256];
static int cnt=0;
cnt++;

  if (arr->cntrl != 0)
    {
      a = arr->cntrl;
      arr->cntrl = 0;
    } else {
	// Form loop....
	debug("MJA - Calling form_loop - init=%d",init);
	a=form_loop(arr->screen_io,init);
	i_want_to_move_line=0;
	if (m_lastkey==A4GLKEY_UP) {
		i_want_to_move_line=-1;
	}

	if ( m_lastkey==A4GLKEY_DOWN) {
		i_want_to_move_line=1;
	}

    }




    if (i_want_to_move_line!=0) {
	    debug("Here...");
	    sprintf(buff,"Move %d",cnt);
	    movement=i_want_to_move_line;
	    i_want_to_move_line=0;
	    error_box(buff);
	    arr->cntrl=0-a;
	    return -11;
    }

    if (movement!=0) {
	    error_box("Moving");
	    movement=0;
    }

    debug("iarr_loop returning %d",a);
    return a;
}



static void make_binding(struct BINDING *dest,struct BINDING *src,
		int bindsize,int no,int elemsize) {
int a;

for (a=0;a<bindsize;a++) {
      	dest[a].ptr			=(src[a].ptr + elemsize * (no - 1));
	dest[a].dtype			=src[a].dtype;
	dest[a].size			=src[a].size;
	dest[a].start_char_subscript	=src[a].start_char_subscript;
	dest[a].end_char_subscript	=src[a].end_char_subscript;
	debug("MJAMJA binding : %d %x",a,dest[a].dtype);
}

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
inp_arr (struct s_inp_arr *sio_arr, void *ptr, char *srecname, 
		int attrib,int init) {
  int a;
  char srec[256];
  static int starting=0;
int _sf;

  debug("MJAMJA sio_arr->nbind=%d size=%d init=%d",sio_arr->nbind,sizeof(struct s_inp_arr),init);

  strcpy(srec,srecname);
  strcat(srec,".*");

  debug("inp_arr - %s %s",srec,srecname);
  curr_arr_inp = sio_arr;


  if (init)
    {
      sio_arr->srec = get_srec (srecname);
      sio_arr->screen_io=malloc(sizeof(struct s_screenio));

      if (sio_arr->srec == 0)
        {
          exitwith ("Screen record not found");
          return 0;
        }
      sio_arr->currform = get_curr_form ();
      sio_arr->screen_io->currform=sio_arr->currform;


      debug("MJAMJA currform set to %p sio_arr->screen_io->currform=%p",sio_arr->currform,sio_arr->screen_io->currform);
	
	sio_arr->cntrl=0;
      sio_arr->last_arr_line = -1;
      sio_arr->last_scr_line = -1;

      sio_arr->scr_line = 1;
      sio_arr->arr_line = 1;
      //sio_arr->cntrl = 1;
      sio_arr->highlight = 0;

      set_arr_curr (sio_arr->arr_line);
      set_scr_line (sio_arr->scr_line);
      set_arr_count (sio_arr->no_arr);


	sio_arr->screen_io->novars=sio_arr->nbind;
	debug("sio_arr->nbind=%d",sio_arr->nbind);
	sio_arr->screen_io->help_no=sio_arr->help_no;
	sio_arr->screen_io->currentfield=0;
	sio_arr->screen_io->currentmetrics=0;
	sio_arr->screen_io->mode=MODE_INPUT_ARRAY;
	sio_arr->screen_io->nfields=sio_arr->nfields;

      if (sio_arr->srec == 0) {
          debug ("Screen record does not exist");
          return 0;
        }

      if (sio_arr->srec->attribs.attribs_len != sio_arr->nbind) {
          debug ("Too many or too few variables for fields %d %d",
                 sio_arr->srec->dim, sio_arr->nbind);

          return 0;

        }

      iclear_srec (sio_arr->srec);

	debug("sio_arr->nbind=%d",sio_arr->nbind);

      for (a = 0; a < sio_arr->srec->dim; a++) {
          if (a < sio_arr->no_arr)
            {
              idraw_arr (sio_arr,  a + 1);
            }

        }
	debug("sio_arr->nbind=%d",sio_arr->nbind);
      idraw_arr (sio_arr, sio_arr->arr_line);

      gui_scroll (sio_arr->no_arr);
      set_arr_curr (sio_arr->arr_line);
      set_scr_line (sio_arr->scr_line);
      set_arr_count (sio_arr->no_arr);
      debug("sio_arr->nbind=%d",sio_arr->nbind);
      sio_arr->curr_attrib = 0;
	starting=1;
	return -10;
  }



  if (sio_arr->last_arr_line!=sio_arr->arr_line) {

	debug("sio_arr->nbind=%d",sio_arr->nbind);
	if (sio_arr->field_list) {
		free(sio_arr->field_list);
	}

	debug("sio_arr->nbind=%d",sio_arr->nbind);

	sio_arr->screen_io->vars=malloc(sizeof(struct BINDING)*(sio_arr->nbind));
	make_binding(sio_arr->screen_io->vars,sio_arr->binding,sio_arr->nbind,
			sio_arr->arr_line,sio_arr->arr_elemsize);

	debug("sio_arr->nbind=%d",sio_arr->nbind);
	gen_field_chars(sio_arr->field_list,sio_arr->currform,srec,sio_arr->scr_line,0);

	sio_arr->screen_io->field_list=(void *)sio_arr->field_list;
      debug("MJAMJA currform set to %p sio_arr->screen_io->currform=%p",sio_arr->currform,sio_arr->screen_io->currform);
	_sf=set_fields(sio_arr->screen_io);
	debug("MJAMJA _sf=%d",_sf);
	sio_arr->last_arr_line=sio_arr->arr_line;
  }

  debug("MJAMJA Calling iarr_loop with init=%d",init);
  if (starting==1) {
	init=1;
	starting=0;
	debug("MJAMJA got a starting..");
  }
  return iarr_loop (sio_arr,init);
}

