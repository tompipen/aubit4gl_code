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
# $Id: ui.c,v 1.60 2006-10-12 06:13:14 mikeaubury Exp $
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
 * @todo Doxygen comments to add to functions
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
char last_fcompile_err[1024];

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *A4GL_pull_off_data_for_display(int n,int display_type);
void A4GL_processed_onkey_v2(char *iot,char *base) ;
void A4GL_ensure_column(void ) ;
void A4GL_add_key_mapping(int src,int dest) ;
//int A4GL_has_event(int a,struct aclfgl_event_list *evt) ;
//int A4GL_has_event_for_keypress(int a,struct aclfgl_event_list *evt) ;
//int A4GL_has_event_for_field(int cat,char *a,struct aclfgl_event_list *evt) ;
//int A4GL_has_event_for_action(char *a,struct aclfgl_event_list *evt) ;
int aclfgl_aclfgl_add_keymap(int n) ;
char  *A4GL_find_gui_id_name_from_id(int id) ;
int A4GL_find_gui_id_from_name(char *s) ;
int A4GL_add_gui_id_name(char *s) ;
char *A4GL_linemode_goto_column(int a) ;
void A4GL_set_line_mode_column(int n,int ab_rel) ;
int aclfgl_aclfgl_get_curr_width(int n);
int aclfgl_aclfgl_get_curr_height(int n);



#define LINE_MODE               0
#define SCREEN_MODE     1
#define UI_MODE_TEXT    0
#define UI_MODE_GTK     1
extern int ui_mode;
int currscrmode = SCREEN_MODE;


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
  int line_length;

  x = 0;
  y = 0;

  x = A4GL_pop_int ();
  y = A4GL_pop_int ();

  A4GLSQL_set_status(0,0);
  A4GL_debug_print_stack();
  A4GL_get_top_of_stack (1, &tos_dtype, &tos_size, (void **) &tos_ptr);
  A4GL_debug ("TOP1 = %d %x %p\n", tos_dtype & 0xff, tos_size, tos_ptr);
  //A4GL_assertion(tos_ptr==0,"Invalid pointer passed to display_at");
  if ((tos_dtype &0xff)== 0 && tos_size == 0)
    {
	char *ctos_ptr;
	A4GL_debug("Maybe null....");
	ctos_ptr=(char *)tos_ptr;
        //A4GL_debug("50 Clear end of line required... %d %d",ctos_ptr[0],ctos_ptr[1]);
    	clr_end_of_line = 1;
    }

	  if (x == -1 && y == -1) {
		display_type=DISPLAY_TYPE_DISPLAY;
		A4GL_set_line_mode_column(1,0);
	  } else {
		display_type=DISPLAY_TYPE_DISPLAY_AT;
	  }

  s=A4GL_pull_off_data_for_display(n,display_type);



  if (x == -1 && y == -1)
    {
      // Do nothing 
    }
  else
    {

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
	  A4GL_debug ("'%s' seems to long to display... - I'm gonna trim it..", s);
	  s[line_length] = 0;

	}

    }


  A4GL_debug("Finding display_internal clr_end_of_line=%d",clr_end_of_line);

  if (strlen(s)) {
	A4GL_debug("display_internal - attr =%x",a);
  	A4GL_display_internal (x, y, s, a, clr_end_of_line);
  } else {
	if (clr_end_of_line && A4GL_was_last_empty() && n==1 && (tos_dtype &0xff)== 0 && tos_size == 0) {
  		if (x>=0&&y>=0) A4GL_display_internal (x, y, " " , a, clr_end_of_line); // Screen mode
  		else A4GL_display_internal (x, y, "" , a, 0); // Line mode

	} else {
  		A4GL_display_internal (x, y, "" , a, 0); 

	}
  }

  free (s);
  A4GL_debug ("Done Display@");
  A4GL_clr_last_was_empty();

  if (!aclfgli_get_err_flg()) { A4GLSQL_set_status(0,0); }
  //return 1;
}



/**
 *
 * @todo Describe function
 */
//int A4GL_disp_arr_v2 (void *disp, void *ptr, char *srecname, int attrib, int scroll,void *evt)
//{
  //va_list ap;
  //int a;

  //va_start (ap, evt);
  //a=A4GL_disp_arr_v2 (disp, ptr, srecname, attrib, scroll,evt);
  //va_end(ap);
  //return a;
//}


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

  A4GL_debug("itype=%c",itype);
  if (itype=='I' || itype=='C') {
  	a=A4GL_fgl_getfldbuf_ap (inp,&ap); 
  } else {
  	a=A4GL_fgl_getfldbuf_ia_ap (inp,&ap); 
  }

  va_end(ap);

  return a;

}



int A4GL_pushint_fgl_infield (void *inp,char itype,...)
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
  A4GL_push_int(a);
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



int A4GL_open_gui_form (long *form_variable,char *name_orig, int absolute, int nat, char *like, int disable, void *handler_e, void (*handler_c (int a, int b)))
{
#ifndef CSCC
  return A4GL_open_gui_form_internal (form_variable,name_orig, absolute, nat, like, disable, handler_e, handler_c);
#endif
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
  s = acl_malloc2 (2);
  s[0] = 0;

  for (z = n -1; z >=0 ; z--)
    {
A4GL_debug("z=%d n=%d\n",z,n);
      A4GL_get_top_of_stack (z+1, &tos_dtype, &tos_size, (void **) &tos_ptr);

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

          //if (ptr != 0) { A4GL_drop_param (); }


		if (ptr) ptr=acl_strdup(ptr);

        } 

	if (ptr==0)  {
		A4GL_push_param(tos_ptr,(tos_dtype & DTYPE_MASK) + ENCODE_SIZE (tos_size));
		ptr=A4GL_char_pop();
	}


	if (ptr[0]==0x01) {
		if (display_type==DISPLAY_TYPE_DISPLAY) {
			int a;
			char buff[255];
			strcpy(buff,&ptr[1]);
			a=atoi(buff);
			free(ptr);
			ptr=acl_strdup(A4GL_linemode_goto_column(a));
		} else {
			ptr=acl_strdup("");
		}

	}

	A4GL_debug("ptr='%s'\n",ptr);


      buff = realloc (buff, strlen (s) + strlen (ptr) + 1);
      ls= strlen (s) + strlen (ptr) + 1;
      if (display_type==DISPLAY_TYPE_DISPLAY) {
		A4GL_set_line_mode_column(strlen(ptr),1);
	}
      s = realloc (s, ls);
      SPRINTF2 (buff, "%s%s",  s,ptr);
      free(ptr);
      strcpy (s, buff);
      A4GL_debug ("s='%s' %p %d %d\n", s, s,strlen(s),ls);
    }
    free(buff);
    A4GL_debug("pull_off_data_for_display returns %s",s);
    for (z=0;z<n;z++) {
		A4GL_drop_param();
	}
    return s;
}


/* This is a bad kludge - moved to the scren IO portions
   so it doesn't overlap
*/

/*
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
*/




void A4GL_processed_onkey_v2(char *iot,char *base) {
int *ptr;
	A4GL_debug("In A4GL_processed_onkey_v2");
	ptr=GETPTR(iot,base,"processed_onkey");
	if (ptr==0) {
		A4GL_debug("Darn - no processed_onkey %s (%p)",iot,base);
	} else {
		A4GL_debug("Processed key... %d in %s @ %p",*ptr,iot,base);
		*ptr=0;
	}
}



int A4GL_field_name_str_match(char *f1,char *f2) {
int a;
char *f1p;
char *f2p;
f1p=a_strchr(f1,'.');
if(f1p) f1p++;
else f1p=f1;

f2p=a_strchr(f2,'.');
if(f2p) f2p++;
else f2p=f2;

a=strcmp(f1p,f2p);
if (a==0) a=1;
else a=0;

A4GL_debug("field_name_str_match : %s %s -> %d",f1p,f2p,a);
return a;
}


void A4GL_chk_for_screen_print(int a) {
static int have_key=0; // 0- don't know 1= do nothing 2=print screen to file 3=print screen to pipe
static int key=0;
char *ptr;
//char buff[256];
if (have_key==1) return;

if (have_key==0) {
	have_key=1;
	ptr=acl_getenv("A4GL_PRINTSCRKEY");
	if (ptr==0) return;
	if (strlen(ptr)==0) return;

	key=A4GL_key_val(ptr);
	if (key==0) return;
	have_key=2;
	ptr=acl_getenv("A4GL_PRINTSCRFILE");
	if (ptr) {
		if (strlen(ptr)==0) ptr=0;
	}
	if (ptr==0) {
		have_key=1;
		A4GL_exitwith("You have specified PRINTSCRKEY but not PRINTSCRFILE");
		return ;
	}
}
// If we've got to here then we've got a PRINTSCRKEY defined...

if (a!=key) return; // Its not our key...

aclfgl_aclfgl_dump_screen(0);

}

/*
void *A4GL_make_pixmap(char *filename) {
	return A4GL_make_pixmap_gw(filename);
}
*/




// Key mappings..
// Any key can be mapped directly to another
// The simplest way of doing this is to have a simple lookup
// int src_keycode -> int dest_keycode

struct s_key_mapping {
	int src_keycode;
	int dest_keycode;
};

struct s_key_mapping *key_mappings=0;
int nkeymappings=0;



/* Add a new mapping to our keylist */
void A4GL_add_key_mapping(int src,int dest) {
nkeymappings++;
key_mappings=realloc(key_mappings,sizeof(struct s_key_mapping)*nkeymappings);
key_mappings[nkeymappings-1].src_keycode=src;
key_mappings[nkeymappings-1].dest_keycode=dest;
}

/* Transform a keycode based on our mappings */
int A4GL_key_map(int keycode) {
int a;
A4GL_debug("Got key %d",keycode);
if (key_mappings==0) return keycode;

for (a=0;a<nkeymappings;a++) {
	if (key_mappings[a].src_keycode==keycode) {
			A4GL_debug("Found mapping - %d -> %d",keycode,key_mappings[a].dest_keycode);
			return key_mappings[a].dest_keycode;
	}
}
A4GL_debug("No key match - %d",keycode);
return keycode;
}


int aclfgl_aclfgl_add_keymap(int n) {
int dest;
int src;
dest=A4GL_pop_long();
src=A4GL_pop_long();
A4GL_add_key_mapping(src,dest);
return 0;
}




int A4GL_has_event(int a,struct aclfgl_event_list *evt) {
int n;
for (n=0;evt[n].event_type;n++) {
        if (evt[n].event_type==a) return evt[n].block;
}
return 0;
}


int A4GL_has_event_for_keypress(int a,struct aclfgl_event_list *evt) {
int n;
for (n=0;evt[n].event_type;n++) {
        if (evt[n].event_type==-90 && evt[n].keycode==a) return evt[n].block;
}
return 0;
}

int A4GL_has_event_for_field(int cat,char *a,struct aclfgl_event_list *evt) {
int n;
A4GL_debug("Looking for a %d event on field %s HEF",cat,a);
for (n=0;evt[n].event_type;n++) {
        if (evt[n].event_type==cat && A4GL_field_name_str_match(evt[n].field,a) ) {
		A4GL_debug("FOUND ONE HEF");
		return evt[n].block;
	}
}
return 0;
}

int A4GL_has_event_for_action(char *a,struct aclfgl_event_list *evt) {
int n;
int cde;
for (n=0;evt[n].event_type;n++) {
	cde=A4GL_EVENT_ON_ACTION;
        if (evt[n].event_type==cde) {
	       	if (A4GL_aubit_strcasecmp(evt[n].field,a) ==0) {
			A4GL_debug("FOUND ONE HEF");
			return evt[n].block;
		}
	}
}
return 0;
}


/* These functions are used internally for ID_TO_INT and INT_TO_ID functions */

char **gui_id_names=0;
int gui_id_names_cnt=0;

char  *A4GL_find_gui_id_name_from_id(int id) {
	if (id<0||id>=gui_id_names_cnt) return 0;
	return gui_id_names[id];
}

int A4GL_find_gui_id_from_name(char *s) {
int a;
	if (gui_id_names_cnt==0) return -1;

	for (a=0;a<gui_id_names_cnt;a++) {
		if (strcmp(gui_id_names[a],s)==0) return a;
	}
	return -1;
}



int A4GL_add_gui_id_name(char *s) {
	int id;
	id=A4GL_find_gui_id_from_name(s);
	if (id==-1) {
		gui_id_names_cnt++;
		gui_id_names=realloc(gui_id_names,sizeof(char *)*gui_id_names_cnt);
		gui_id_names[gui_id_names_cnt-1]=acl_strdup(s);
		return gui_id_names_cnt-1;
	}
	return id;
}


int line_mode_column=0;


/* 
Maintain a line mode column number
ab_rel : 0= absolute (line_mode_column = n)
	 1= relatative (line_mode_column+=n)
*/

void A4GL_set_line_mode_column(int n,int ab_rel) {
if (ab_rel==0) {
	line_mode_column=n;
} else {
	line_mode_column+=n;
}

}

void A4GL_ensure_column(void ) {
char buff[2048];
int a;
a=A4GL_pop_int();
SPRINTF2(buff,"%c%d",0x01,a);
A4GL_push_char(buff);
}

char *A4GL_linemode_goto_column(int a) {
int b;
static char buff[2048];
b=0;
	while (a>line_mode_column) {
			b++;a--;
	}
	memset(buff,' ',b);
	buff[b]=0;
	return buff;
}

void A4GL_make_field_slist_from_ap( struct s_field_name_list *list, va_list *ap) {
        int f; // F is field number - should be int ? 
        //long f;
        char *s;
        list->nfields=0;
        while (1) {
                s = va_arg (*ap, char *);
                if (s==0)  break;
                //f = (int) va_arg (*ap, int *);
                f = (int) va_arg (*ap, int);
                if (f > 0) f--;
                list->nfields++;
                list->field_name_list=realloc(list->field_name_list, sizeof(list->field_name_list[0])*list->nfields);
                list->field_name_list[list->nfields-1].fname=s;
                list->field_name_list[list->nfields-1].fpos=f;
        }
}

int aclfgl_aclfgl_get_curr_width(int n) {
	  A4GL_push_long(A4GL_get_curr_width () );
	return 1;
}

int aclfgl_aclfgl_get_curr_height(int n) {
	  A4GL_push_long(A4GL_get_curr_height () );
	return 1;
}


// When using input/display array - the screen record is *always* specified as srecname.*
// So we need to be able to swap and change between having the .* and not
// These two functions make sure the .* exists (or not)
// 
// Get a sreen record - but remove the .*
char *A4GL_var_for_inp_array(char *s) {
	static char buff[255];
	char *ptr;

	if (strchr(s,'*')) {
		strcpy(buff,s);
		A4GL_trim(s);
		ptr=strchr(buff,'*');
		ptr--;
		*ptr=0;
		return buff;
	}
	strcpy(buff,s);
	A4GL_trim(buff);
	return buff;
}


// Get a sreen record - but add the .*
char *A4GL_add_dot_star(char *s) {
	static char buff[256];
	static char buff2[256];
	if (strstr(s,".*")) {
			strcpy(buff,s);
			A4GL_trim(buff);
			return buff;
	}
	strcpy(buff2,s);
	SPRINTF1(buff,"%s.*",buff2);
	return buff;
}



void A4GL_clr_evt_timeouts(struct aclfgl_event_list *evt) {
	int a;
	long now;
	now=time(0);
  	for (a=0;evt[a].event_type;a++) {
			if (evt[a].event_type==A4GL_EVENT_ON_IDLE) {
				*(long *)evt[a].field=now;
			}
			if (evt[a].event_type==A4GL_EVENT_ON_INTERVAL) {
				*(long *)evt[a].field=now;
			}
			if (evt[a].event_type==A4GL_EVENT_ON_TIME) {
				// Not implemented...
				A4GL_assertion(1,"ON TIMESTAMP not implemented");
			}
	}
}


int A4GL_has_evt_timeout(struct aclfgl_event_list *evt) {
  	int a;
	long now;
	long then;
	long timeout_val;
	now=time(0);
  	for (a=0;evt[a].event_type;a++) {
			if (evt[a].event_type==A4GL_EVENT_ON_IDLE) {
				timeout_val=evt[a].keycode;
				then=*(long *)evt[a].field;
				if ((now-then)>=timeout_val) { 
					*(long *)evt[a].field=now;
					return evt[a].block; 
				}
			}
			if (evt[a].event_type==A4GL_EVENT_ON_INTERVAL) {
				timeout_val=evt[a].keycode;
				then=*(long *)evt[a].field;
				if ((now-then)>=timeout_val) { 
					*(long *)evt[a].field=now;
					return evt[a].block; 
				}
			}
			if (evt[a].event_type==A4GL_EVENT_ON_TIME) {
				// Not implemented...
				A4GL_assertion(1,"ON TIMESTAMP not implemented");
			}
	}
	return 0;
}

void A4GL_evt_not_idle(struct aclfgl_event_list *evt) {
  	int a;
	long now;
	now=time(0);
  	for (a=0;evt[a].event_type;a++) {
			if (evt[a].event_type==A4GL_EVENT_ON_IDLE) {
				*(long *)evt[a].field=now;
			}
	}
}


void A4GL_add_recall_value(char *field_name,char *value) {
	struct s_recall_list *s;
	struct s_recall_entry *e;
	
	if (A4GL_has_pointer(field_name,RECALL_LOG_ENTRIES)) {
		s=A4GL_find_pointer(field_name,RECALL_LOG_ENTRIES);
	} else {
		s=malloc(sizeof(struct s_recall_list));
		s->first=0;
		s->last=0;
		A4GL_add_pointer(field_name,RECALL_LOG_ENTRIES,s);
	}

	if (s->first) {
		e=s->first;
		if (strcmp(e->recall_value,value)==0) { // Its already at the front of the list..
			return;
		}
	}

	e=malloc(sizeof(struct s_recall_entry));
	e->prev=0;
	e->next=0;

	e->recall_value=acl_strdup(value);

	if (s->first==0) { // First one...
			s->first=e; s->last=e;
	} else {
		struct s_recall_entry *old_first;
		old_first=s->first;
		s->first=e;
		e->next=old_first;
		old_first->prev=e;
	}

	e=s->first; // We'll skip the first entry - because we've only just put it there!
	e=e->next;

	while (e) {
		struct s_recall_entry *n;
		n=e->next;
		if (strcmp(value,e->recall_value)==0) { // It was already in our list
				struct s_recall_entry *e2;
				free(e->recall_value);
				e2=e->prev;
				if (e2) { e2->next=e->next; }
				e2=e->next;
				if (e2) { e2->prev=e->prev; }
				if (e==s->last) { s->last=e->prev; }
				free(e);
		}
		e=n;
	}
}


void A4GL_debug_dump_recall(char *field_name) {
	struct s_recall_list *s;
	struct s_recall_entry *e;

	PRINTF("DUMP RECALL FOR FIELD : %s\n",field_name);
	if (A4GL_has_pointer(field_name,RECALL_LOG_ENTRIES)) {
		s=A4GL_find_pointer(field_name,RECALL_LOG_ENTRIES);
	} else {
		PRINTF("No recall values\n");
		return;
	}
	e=s->first;
	while (e) {
		if (e->recall_value) {
			PRINTF("%s\n",e->recall_value);
		}
		e=e->next;
	}
	PRINTF("---------------\n");
}


char *A4GL_recall_field(char *t,char *c,int x,int y,int show) {
        struct s_recall_list *s;
        struct s_recall_entry *e;
	int maxlen=0;
	int nvals=0;
	char **values=0;
	int cnt;
	int rows;
	int sline;
	int cols;
	char *buff;
	int crow;
	int ok=1;
	static char *last_val=0;
	char field_name[256];
	SPRINTF1(field_name,"%s",c);
	if (last_val) {free(last_val); last_val=0;}

        if (A4GL_has_pointer(field_name,RECALL_LOG_ENTRIES)) {
                s=A4GL_find_pointer(field_name,RECALL_LOG_ENTRIES);
        } else {
                return 0;
        }

	nvals=0;
        e=s->first;
        while (e) {
                if (e->recall_value) {
			if (strlen(e->recall_value)) {
				nvals++;
				if (strlen(e->recall_value)>maxlen) {
					if (show==0) { 
						SPRINTF2(field_name,"%s.%s",t,c);
						// Return our value..
						A4GL_push_char(e->recall_value);
						A4GL_disp_fields(1,0xffffffff,field_name,1,0);
						return e->recall_value; 
					}
					maxlen=strlen(e->recall_value);
				}
			}
                }
                e=e->next;
        }
	if (show==0) {
		
		SPRINTF2(field_name,"%s.%s",t,c);
		// Return our value..
		A4GL_push_char(" " );
		A4GL_disp_fields(1,0xffffffff,field_name,1,0);
		return " ";
	}
	if (nvals>100) nvals=100; // Gotta call it sometime...

	values=malloc(sizeof(char *)*nvals);

	cnt=0;
        e=s->first;

	buff=malloc(maxlen+1);
	buff[maxlen]=0;
        while (e) {
                if (e->recall_value) {
			if (strlen(e->recall_value)) {
			memset(buff,' ',maxlen);
			strncpy(buff,e->recall_value,strlen(e->recall_value));
			values[cnt]=acl_strdup(buff);
			cnt++;
			}
                }
                e=e->next;
        }


	if (maxlen>50)  {cols=50;} else {cols=maxlen;}
	if (nvals>10)   {rows=10;} else {rows=nvals;}
	
	// Need to double check these are valid....
        A4GL_push_long(x+1);
        A4GL_push_long(y+1);

        A4GL_push_long(rows);
        A4GL_push_long(cols);
	A4GL_cr_window("a4gl_recall", 1,255,255,255,255,1,255,255,(0x0));


	sline=0;
	crow=0;

	// mantain a scrolling list of values...
	while (1) {
		long key;
		int top;
		int a;

		// Display our current list..
		for (a=0;a<rows;a++) {
			top=crow-sline;
   			A4GL_push_char(values[top+a]);
   			A4GL_push_long(a+1);
   			A4GL_push_long(1);
			if (crow==top+a) {
   				A4GL_display_at(1,0x1000);
			} else {
   				A4GL_display_at(1,0xffffffff);
			}
		}

		// wait for a key press..
      		aclfgl_fgl_getkey(0);
		A4GL_pop_var2(&key,2,0x0);

		// act on that keypress..
		if (key==A4GLKEY_F(12)) 	{ok=0;break;}
		if (key==A4GLKEY_ENTER) 	{ok=1;break;}
		if (key==A4GLKEY_UP&& crow>0)   {crow=crow-1; sline--; }
		if (key==A4GLKEY_DOWN && crow<(nvals-1)) {crow=crow+1; sline++; }
		if (sline>=rows) sline=rows-1;
		if (sline<0) sline=0;
	}

	A4GL_remove_window("a4gl_recall");

	// Lets make a copy - so we can free all the values...
	if (ok) { last_val=acl_strdup(values[crow]); }

	// Free them
	for (cnt=0;cnt<nvals;cnt++) {
		free(values[cnt]);
	}
	free(values);

	// Was it ok ?
	if (ok==0) { return 0; }

	SPRINTF2(field_name,"%s.%s",t,c);
	// Return our value..
	A4GL_push_char(last_val);
	A4GL_disp_fields(1,0xffffffff,field_name,1,0);

	return last_val;
}

/*
 *
 * @todo Describe function
 */
int
A4GL_attr_name_match (struct struct_scr_field *field, char *s_x)
{
  char colname[40];
  char tabname[40];
  int aa;
  int ab;
   char s[256];

     A4GL_debug ("Field : %p \n", field);

strcpy(s,s_x);
  A4GL_trim(s);
     A4GL_debug ("attr_name_match : %s", s);
  A4GL_bname (s, tabname, colname);


     A4GL_debug ("Splits to %s & %s", tabname, colname);
     A4GL_debug ("field is [%s %s]", field->tabname, field->colname);


  aa = strcmp (field->tabname, tabname);
  ab = strcmp (field->colname, colname);
  /* A4GL_debug ("Matches = %d %d ", aa, ab); */
  if ((ab == 0) || (colname[0] == '*'))
    {
      A4GL_debug ("Match on * (%s,%s,%s) (%s,%s)",s,tabname,colname,field->tabname,field->colname);
      return 1;
    }
  if (ab == 0 && tabname[0] == 0)
    {
      A4GL_debug ("Matched %s.%s = %s.%s ",tabname,colname,field->tabname,field->colname);
      return 1;
    }

     A4GL_debug ("Not matched (%s!=%s or %s!=%s)", field->tabname, tabname,
    field->colname, colname);

  return 0;
}
// We're quitting - so close down any UI specific stuff
// before we go...
void A4GL_stop_ui(void) {
	static int  stopping=0;
	if (!stopping) {
    		A4GL_ui_exit();
	}

	stopping++;


    /*
  if (A4GL_isscrmode ())
    {
#ifdef DEBUG
      A4GL_debug ("In screen mode - ending curses...");
#endif
      A4GL_gotolinemode ();
    }
    */
}





/**
 * Gets the integer keyval from a string representing it.
 *
 * The string with the name is passed by the stack.
 *
 * The keyval is  returned by the stack.
 *
 * @param _np The number of para,eters passed by stack.
 * @return Allways 1
 */
int
A4GL_fgl_keyval (int _np)
{
  long _r;
  char *v0;
  char buff[20];

  if (_np != 1)
    {
      A4GLSQL_set_status (-3000, 0);
      A4GL_debug ("Bad number of arguments to A4GL_fgl_keyval got %d - expected 1",
             _np);

      for (_r = 0; _r < _np; _r++)
        {
          A4GL_pop_char (buff, 10);
        }
    }

  v0 = A4GL_char_pop ();
  A4GL_debug ("TST1 - v0=%s", v0);

  _r = A4GL_key_val (v0);
  A4GL_debug ("TST1 - r=%d\n", _r);
  A4GL_push_long (_r);
  acl_free (v0);
  return 1;
}



#define INC_EACH "\n"
#define INC_RANGE '\t'
int
A4GL_include_range_check (char *ss, char *ptr, int dtype)
{
  static char buff[2048];       /* what we're checking */
  static char buff2[2048];      /* what we're checking against */
  static char buff3[2048];      /* used if its a range */
  char *ptr1=0;
  char *ptr2=0;
  char *ptr3=0;
  char *s;
  int had_length;

  memset(buff,0,sizeof(buff));
  memset(buff2,0,sizeof(buff2));
  memset(buff3,0,sizeof(buff3));
  s = acl_malloc2 (strlen(ss)+10);
  memset(s,0,strlen(ss)+10);
  had_length=strlen(ss);
  strcpy(s,ss);
  A4GL_trim (s);
  A4GL_debug ("include_range_check(%s,%s,%d)", s, ptr, dtype);

        if (A4GL_aubit_strcasecmp(ptr,"NULL")==0) {
                // Check for a null...
                A4GL_debug("NULL ALLOWED");
                if (strlen(s)==0) {
                        return 1;
                }
        }


  if (had_length && strlen(s)==0) {
	strcpy(s," ");
  }


  ptr3 = strchr (ptr, INC_RANGE);

  if (ptr3)
    {
      ptr3[0] = 0;
      ptr3++;
      A4GL_debug ("a range has been specified '%s' to '%s'", ptr, ptr3);
    }

  if (dtype != DTYPE_CHAR)
    {
        int dim=0;

      if (dtype==DTYPE_DECIMAL||dtype==DTYPE_MONEY) {
                dim=0x2010;
        }
      A4GL_debug ("Not a string expression");
        A4GL_debug("Pushing '%s'",s);
      A4GL_push_char (s);
      A4GL_pop_param (&buff[0], dtype, dim);
      ptr1 = buff;

        if (dtype==1) { A4GL_debug("Popped ptr1 : %d",*(int *)ptr1); }
        A4GL_debug("Pushing '%s'",ptr);
      A4GL_push_char (ptr);
      A4GL_pop_param (&buff2[0], dtype, dim);
      ptr2 = buff2;
        if (dtype==1) { A4GL_debug("Popped ptr2 : %d",*(int *)ptr2); }

      /* do we have a range of values to check ? */
      if (ptr3)
        {
        A4GL_debug("Pushing '%s'",ptr3);
          A4GL_push_char (ptr3);
          A4GL_pop_param (&buff3[0], dtype, dim);
          ptr3 = buff3;
          if (dtype==1) { A4GL_debug("Popped ptr3 : %d",*(int *)ptr3); }
        }

    }
  else
    {
      A4GL_debug ("String expression");
      ptr1 = s;
      ptr2 = ptr;
    }

  if (ptr3 == 0)
    {
        int chk_again;
      /* Not a range */
        if (A4GL_aubit_strcasecmp(ptr2,"NULL")==0) {
                // Check for a null...
                A4GL_trim(ptr1);
                if (strlen(ptr1)==0) {
                        return 1;
                }
        }

        if (dtype==1) {
                A4GL_debug("%x %x",*(int *)ptr1,*(int *)ptr2);
        }

      A4GL_push_param (ptr1, dtype);
      A4GL_push_param (ptr2, dtype);
      A4GL_debug_print_stack ();
      A4GL_pushop (OP_EQUAL);
      A4GL_debug ("Checking for equal");
      free (s);


      chk_again= A4GL_pop_bool ();
      if ((dtype==DTYPE_SMINT||dtype==DTYPE_INT||dtype==DTYPE_DECIMAL ||dtype==DTYPE_FLOAT||dtype==DTYPE_SMFLOAT) && chk_again && !strncmp(ptr, "NULL", 4)) {

        A4GL_debug ("zero not equal to NULL during form range checks");
        chk_again = 0;
      }
      return chk_again;



    }
  else
    {
      if(dtype==1||dtype==2) {
      A4GL_debug ("if ints : %d comp %d", *(int *) ptr1, *(int *) ptr2);
        }
      A4GL_push_param (ptr1, dtype);
      A4GL_push_param (ptr2, dtype);
      A4GL_debug_print_stack ();
      A4GL_pushop (OP_GREATER_THAN_EQ);
      A4GL_debug ("Checking for <=");
      if (A4GL_pop_bool () == 0)
        {
          free (s);
          return FALSE;
        }

      //A4GL_debug ("if ints : %d comp %d", *(int *) ptr1, *(int *) ptr3);
      A4GL_push_param (ptr1, dtype);
      A4GL_push_param (ptr3, dtype);
      A4GL_debug_print_stack ();
      A4GL_pushop (OP_LESS_THAN_EQ);
      A4GL_debug ("Checking for >=");
      free (s);
      if (A4GL_pop_bool () == 0)
        return FALSE;
      return TRUE;
    }

}


void A4GL_set_fcompile_err(char *s) {
strcpy(last_fcompile_err,s);
}

char *A4GL_get_fcompile_err(void) {
return last_fcompile_err;
}

/* ============================= EOF ================================ */
