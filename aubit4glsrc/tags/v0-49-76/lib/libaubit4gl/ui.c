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
# $Id: ui.c,v 1.33 2005-03-17 20:48:34 mikeaubury Exp $
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
void A4GL_processed_onkey_v2(char *iot,char *base) ;
void A4GL_ensure_column(void ) ;
void A4GL_add_key_mapping(int src,int dest) ;
int A4GL_has_event(int a,struct aclfgl_event_list *evt) ;
int A4GL_has_event_for_keypress(int a,struct aclfgl_event_list *evt) ;
int A4GL_has_event_for_field(int cat,char *a,struct aclfgl_event_list *evt) ;
int aclfgl_aclfgl_add_keymap(int n) ;
char  *A4GL_find_gui_id_name_from_id(int id) ;
int A4GL_find_gui_id_from_name(char *s) ;
int A4GL_add_gui_id_name(char *s) ;
char *A4GL_linemode_goto_column(int a) ;
void A4GL_set_line_mode_column(int n,int ab_rel) ;



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
  int a;

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
  s = malloc (2);
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


		if (ptr) ptr=strdup(ptr);

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
			ptr=strdup(A4GL_linemode_goto_column(a));
		} else {
			ptr=strdup("");
		}

	}

	A4GL_debug("ptr='%s'\n",ptr);


      buff = realloc (buff, strlen (s) + strlen (ptr) + 1);
      ls= strlen (s) + strlen (ptr) + 1;
      if (display_type==DISPLAY_TYPE_DISPLAY) {
		A4GL_set_line_mode_column(strlen(ptr),1);
	}
      s = realloc (s, ls);
      sprintf (buff, "%s%s",  s,ptr);
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
		gui_id_names[gui_id_names_cnt-1]=strdup(s);
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
sprintf(buff,"%c%d",0x01,a);
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
        int f;
        char *s;
        list->nfields=0;
        while (1) {
                s = va_arg (*ap, char *);
                if (s==0)  break;
                f = (int) va_arg (*ap, int *);
                if (f > 0) f--;
                list->nfields++;
                list->field_name_list=realloc(list->field_name_list, sizeof(list->field_name_list[0])*list->nfields);
                list->field_name_list[list->nfields-1].fname=s;
                list->field_name_list[list->nfields-1].fpos=f;
        }
}

/* ============================= EOF ================================ */
