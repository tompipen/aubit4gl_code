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
# $Id: attributes.c,v 1.12 2003-07-12 08:02:56 mikeaubury Exp $
#*/

/**
 * @file
 * This should be a complete list of all possible attributes anything
 * can have - some are not applicable to certain areas.
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


/*
CONSTRUCT 
DISPLAY
DISPLAY ARRAY
DISPLAY FORM
INPUT
INPUT ARRAY
MESSAGE
PROMPT
*/
struct s_std_attr
{
  int colour;

  int reverse;
  int underline;
  int bold;
  int dim;
  int blink;
  int invisible;

  int normal;
  int help_no;
};

/*
OPEN WINDOW 
*/

struct s_win_attr
{
  int color;

  int normal;
  int bold;
  int dim;
  int reverse;
  int border;

  int comment_line;
  int form_line;
  int menu_line;
  int message_line;
  int prompt_line;
};


/* 
OPTIONS INPUT ATTRIBUTE 
OPTIONS DISPLAY ATTRIBUTE 
*/
struct s_options_inpdisp_attr
{
  int color;
  int reverse;
  int underline;
  int blink;
  int bold;
  int dim;
  int invisible;
  int normal;
  int form;
  int window;
};

/* 
OPTIONS
*/
struct s_options_attr
{
  int comment_line;
  int error_line;
  int form_line;
  int menu_line;
  int message_line;
  int prompt_line;
  int accept_key;
  int delete_key;
  int insert_key;
  int next_key;
  int previous_key;
  int help_key;
  char *helpfile;
  struct s_options_inpdisp_attr *display_attribute;
  struct s_options_inpdisp_attr *input_attribute;
  int input_wrap;
  int field_order;
  int sql_interrupt;
};


struct s_field_attr
{
  int screen_records_subscript;
  struct colours *field_cols;
  int field_cols_len;
};



enum e_attribute_type
{
  ATTR_STD,
  ATTR_WIN,
  ATTR_OPTIONS_INPDISP,
  ATTR_OPTIONS,
  ATTR_FIELD,
  ATTR_STRING
};

struct s_all_attributes
{
  int attribute_type;
  union
  {
    struct s_std_attr;
    struct s_win_attr;
    struct s_options_inpdisp_attr;
    struct s_options_attr;
    struct s_field_attr;
    char *string_summary;
  }
  u_all;
};


struct s_std_attr *A4GL_determine_attribute_as_std_attr(int cmd_type, struct s_std_attr *attrib_curr, struct s_std_attr *attrib_field);
//void A4GL_get_strings_from_attr (int attr, char *col_str, char *attr_str);
struct s_std_attr *A4GL_determine_attribute_internal( struct s_std_attr *attrib_curr, struct s_std_attr *attrib_field, struct s_std_attr *syscol, struct s_std_attr *options, struct s_std_attr *disp_form, struct s_std_attr *open_window) ;
void A4GL_attr_int_to_std(int attr,struct s_std_attr *p) ;
int A4GL_determine_attribute_as_int(int cmd_type, struct s_std_attr *attrib_curr, struct s_std_attr *attrib_field) ;

int A4GL_get_curr_form_attr(void) ;
int A4GL_get_curr_window_attr(void) ;


int A4GL_get_curr_form_attr(void) { 
void *ptr;
int attr;
char buff[20];
ptr=A4GL_get_curr_form(0);
sprintf(buff,"%p",ptr);
if (A4GL_has_pointer(buff,ATTRIBUTE)) {
	attr=A4GL_find_pointer(buff,ATTRIBUTE);
	
} else {
	attr=0;
}

return attr;
}


int A4GL_get_curr_window_attr(void) { 
A4GL_debug("XXX - get_curr_window_attr");
if ( A4GL_has_pointer ((char *)A4GL_get_currwin_name (), ATTRIBUTE))  {
	int a;
	a=A4GL_find_pointer ((char *)A4GL_get_currwin_name (), ATTRIBUTE);
	A4GL_debug("Current window has an attribute %d",a);
	return a;
}
A4GL_debug("Current window has no attribute");
return 0;

}

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
* Get a string representation of an attribute
*
* @param attr  Attribute to decode
* @param col_str Pointer to character string to store the colour
* @param col_str Pointer to character string to store the attributes
*/
void
A4GL_get_strings_from_attr (int attr, char *col_str, char *attr_str)
{
  int col_int;

A4GL_debug("Attr=%x\n",attr);
  strcpy (col_str, "WHITE");
  strcpy (attr_str, "");

  col_int = (attr & 0xf00);
  A4GL_debug ("col_int=%x\n", col_int);
  /* Work out the colours first */
  switch (col_int)
    {
    case AUBIT_COLOR_BLACK:
      strcpy (col_str, "BLACK");
      break;
    case AUBIT_COLOR_RED:
      strcpy (col_str, "RED");
      break;
    case AUBIT_COLOR_GREEN:
      strcpy (col_str, "GREEN");
      break;
    case AUBIT_COLOR_YELLOW:
      strcpy (col_str, "YELLOW");
      break;
    case AUBIT_COLOR_BLUE:
      strcpy (col_str, "BLUE");
      break;
    case AUBIT_COLOR_MAGENTA:
      strcpy (col_str, "MAGENTA");
      break;
    case AUBIT_COLOR_CYAN:
      strcpy (col_str, "CYAN");
      break;
    case AUBIT_COLOR_WHITE:
      strcpy (col_str, "WHITE");
      break;
    }

  /* Now for the attributes */
  if (attr & AUBIT_ATTR_NORMAL)
    strcat (attr_str, "NORMAL ");
  if (attr & AUBIT_ATTR_REVERSE)
    strcat (attr_str, "REVERSE ");
  if (attr & AUBIT_ATTR_UNDERLINE)
    strcat (attr_str, "UNDERLINE ");
  if (attr & AUBIT_ATTR_BOLD)
    strcat (attr_str, "BOLD ");
  if (attr & AUBIT_ATTR_BLINK) 
    strcat (attr_str, "BLINK ");
  if (attr & AUBIT_ATTR_DIM)
    strcat (attr_str, "DIM ");
  A4GL_debug ("get_strings returning %s %s", col_str, attr_str);
}

/**
 *  Decode a string attribute into an Aubit internal attribute
 *
 *  @param s The string to decode - should contain a single colour or attribute
 *
 */
int
A4GL_get_attr_from_string (char *s)
{
  if (strcasecmp (s, "BLACK") == 0)
    return AUBIT_COLOR_BLACK;
  if (strcasecmp (s, "RED") == 0)
    return AUBIT_COLOR_RED;
  if (strcasecmp (s, "GREEN") == 0)
    return AUBIT_COLOR_GREEN;
  if (strcasecmp (s, "YELLOW") == 0)
    return AUBIT_COLOR_YELLOW;
  if (strcasecmp (s, "BLUE") == 0)
    return AUBIT_COLOR_BLUE;
  if (strcasecmp (s, "MAGENTA") == 0)
    return AUBIT_COLOR_MAGENTA;
  if (strcasecmp (s, "CYAN") == 0)
    return AUBIT_COLOR_CYAN;
  if (strcasecmp (s, "WHITE") == 0)
    return AUBIT_COLOR_WHITE;

  if (strcasecmp (s, "NORMAL") == 0)
    return AUBIT_ATTR_NORMAL;
  if (strcasecmp (s, "REVERSE") == 0)
    return AUBIT_ATTR_REVERSE;
  if (strcasecmp (s, "UNDERLINE") == 0)
    return AUBIT_ATTR_UNDERLINE;
  if (strcasecmp (s, "BOLD") == 0)
    return AUBIT_ATTR_BOLD;
  if (strcasecmp (s, "BLINK") == 0)
    return AUBIT_ATTR_BLINK;
  if (strcasecmp (s, "DIM") == 0)
    return AUBIT_ATTR_DIM;
  printf ("Unknown attribute : %s\n", s);
  return -1;
}


/* 

go through the hierarchy to determine what attribute we should be using...

*/

struct s_std_attr *A4GL_determine_attribute_as_std_attr(int cmd_type, struct s_std_attr *attrib_curr, struct s_std_attr *attrib_field) {
struct s_std_attr  std_options;
struct s_std_attr  std_disp_form;
struct s_std_attr  std_open_window;
struct s_std_attr  *ptr_std_options=0;
struct s_std_attr  *ptr_std_disp_form=0;
struct s_std_attr  *ptr_std_open_window=0;

int int_options=0;
int int_disp_form=0;
int int_open_window=0;

switch(cmd_type) {
        case FGL_CMD_DISPLAY_CMD:  // DISPLAY / DISPLAY @
        case FGL_CMD_DISPLAY_FIELD_CMD:  // DISPLAY TO, DISPLAY BY NAME
        case FGL_CMD_DISPLAY_FORM:
		A4GL_debug("Command is DISPLAY");
  		int_options	=A4GL_get_option_value('d');
  		int_disp_form	=A4GL_get_curr_form_attr();
  		int_open_window	=A4GL_get_curr_window_attr();
		A4GL_debug("int_options=%x int_disp_form=%x int_open_window=%x",int_options,int_disp_form,int_open_window);
		break;

        case FGL_CMD_INPUT:
        case FGL_CMD_CONSTRUCT:
		A4GL_debug("Command is INPUT");
  		int_options	=A4GL_get_option_value('i');
  		int_disp_form	=A4GL_get_curr_form_attr();
  		int_open_window	=A4GL_get_curr_window_attr();
		break;
}


if (int_options)   { ptr_std_options=&std_options; 		A4GL_attr_int_to_std(int_options,ptr_std_options); }
if (int_disp_form) { ptr_std_disp_form=&std_disp_form; 		A4GL_attr_int_to_std(int_disp_form,ptr_std_disp_form); }
if (int_open_window) { ptr_std_open_window=&std_open_window; 	A4GL_attr_int_to_std(int_open_window,ptr_std_open_window); }

return A4GL_determine_attribute_internal(
		attrib_curr,
		attrib_field,
		0, // We don't do syscol yet...
		ptr_std_options,
		ptr_std_disp_form,
		ptr_std_open_window);
		

}





struct s_std_attr *A4GL_determine_attribute_internal( struct s_std_attr *attrib_curr, struct s_std_attr *attrib_field, struct s_std_attr *syscol, struct s_std_attr *options, struct s_std_attr *disp_form, struct s_std_attr *open_window) {

static struct s_std_attr rval;
struct s_std_attr *r=0;

A4GL_debug("A4GL_determine_attribute_internal : c=%p f=%p s=%p o=%p d=%p w=%p",
attrib_curr,attrib_field,syscol,options,disp_form,open_window);

/*

1. The ATTRIBUTE clause of the current statement. 

2. The attributes from the field descriptions in the ATTRIBUTES section of the current form file. (See  Field Attribute Syntax  on page 6-34.) 

3. The default attributes specified in the syscolatt table of any fields linked to database columns. To modify the syscolatt table, use the upscol utility. For information on using this utility, see Appendix B,  IBM Informix 4GL Utility Programs.  

4. The ATTRIBUTE clause of the most recent OPTIONS statement. 

5. The ATTRIBUTE clause of the current form in the most recent DISPLAY FORM statement. 

6. The ATTRIBUTE clause of the current 4GL window in the most recent OPEN WINDOW statement. 

7. The default reserved line positions and the default foreground color on your terminal.

*/

if (attrib_curr) {
	A4GL_debug("determine_attribute_internal - Attribute : attrib_curr= %x %d %d %d %d %d %d", attrib_curr->colour, attrib_curr->normal, attrib_curr->reverse, attrib_curr->underline, attrib_curr->bold, attrib_curr->blink, attrib_curr->dim);
}

if (attrib_field) {
	A4GL_debug("determine_attribute_internal - Attribute : attrib_field= %x %d %d %d %d %d %d", attrib_field->colour, attrib_field->normal, attrib_field->reverse, attrib_field->underline, attrib_field->bold, attrib_field->blink, attrib_field->dim);
}

A4GL_debug("Determining attribute : curr=%p field=%p syscol=%p options=%p disp_Form=%p open_window=%p",attrib_curr,attrib_field,syscol,options,disp_form,open_window);
if (attrib_curr&&r==0)  { A4GL_debug("Attribute 1");memcpy(&rval,attrib_curr,	sizeof(struct s_std_attr)); r=&rval; }
if (attrib_field&&r==0) { A4GL_debug("Attribute 2");memcpy(&rval,attrib_field,	sizeof(struct s_std_attr)); r=&rval; }
if (syscol&&r==0)       { A4GL_debug("Attribute 3");memcpy(&rval,syscol,	sizeof(struct s_std_attr)); r=&rval; }
if (options&&r==0)      { A4GL_debug("Attribute 4");memcpy(&rval,options,	sizeof(struct s_std_attr)); r=&rval; }
if (disp_form&&r==0)    { A4GL_debug("Attribute 5");memcpy(&rval,disp_form,	sizeof(struct s_std_attr)); r=&rval; }
if (open_window&&r==0)  { A4GL_debug("Attribute 6");memcpy(&rval,open_window,	sizeof(struct s_std_attr)); r=&rval; }

if (r) {
	A4GL_debug("determine_attribute_internal - Attribute : %x %d %d %d %d %d %d", r->colour, r->normal, r->reverse, r->underline, r->bold, r->blink, r->dim);
} else {
	A4GL_debug("determine_attribute_internal - Attribute : No attribute");
}

return r;

}


void A4GL_attr_int_to_std(int attr,struct s_std_attr *p) {
  int col_int;
  col_int = (attr & 0xf00);

  p->colour=col_int;
  p->reverse=0;
  p->underline=0;
  p->bold=0;
  p->blink=0;
  p->dim=0;
  p->invisible=0;
  p->normal=0;

  if (attr & AUBIT_ATTR_NORMAL) 	p->normal=1;
  if (attr & AUBIT_ATTR_REVERSE) 	p->reverse=1;
  if (attr & AUBIT_ATTR_UNDERLINE) 	p->underline=1;
  if (attr & AUBIT_ATTR_BOLD) 		p->bold=1;
  if (attr & AUBIT_ATTR_BLINK) 		p->blink=1;
  if (attr & AUBIT_ATTR_DIM) 		p->dim=1;

	A4GL_debug("Attribute : %x %d %d %d %d %d %d", p->colour, p->normal, p->reverse, p->underline, p->bold, p->blink, p->dim);
}





int A4GL_determine_attribute_as_int(int cmd_type, struct s_std_attr *attrib_curr, struct s_std_attr *attrib_field) {
struct s_std_attr *r;
int attr;
r=A4GL_determine_attribute_as_std_attr(cmd_type, attrib_curr, attrib_field);
attr=0;
attr=attr+r->colour;
if (r->normal) attr+=AUBIT_ATTR_NORMAL;
if (r->reverse) attr+=AUBIT_ATTR_REVERSE;
if (r->underline) attr+=AUBIT_ATTR_UNDERLINE;
if (r->bold) attr+=AUBIT_ATTR_BOLD;
if (r->blink) attr+=AUBIT_ATTR_BLINK;
if (r->dim) attr+=AUBIT_ATTR_DIM;

return attr;
}





/* This is our main calling point ! */
int A4GL_determine_attribute(int cmd_type, int attrib_curr_int, void *vfprop) {
struct s_std_attr *r;
struct s_std_attr attrib_curr;
struct s_std_attr attrib_field;
struct s_std_attr *ptr_attrib_curr=0;
struct s_std_attr *ptr_attrib_field=0;
struct struct_scr_field *fprop;
int attr;

if (cmd_type==FGL_CMD_CLEAR) { // Dont bother with clear...
	A4GL_debug("CMD_CLEAR Attributes are always 0...");
	return 0;
}

fprop=vfprop;
/* Decode our current attribute */

if (attrib_curr_int) {
	A4GL_attr_int_to_std(attrib_curr_int,&attrib_curr);
	ptr_attrib_curr=&attrib_curr;
A4GL_debug("determined Attribute setting attrib_curr =  %x %d %d %d %d %d %d", ptr_attrib_curr->colour, ptr_attrib_curr->normal, ptr_attrib_curr->reverse, ptr_attrib_curr->underline, ptr_attrib_curr->bold, ptr_attrib_curr->blink, ptr_attrib_curr->dim);
}

if (fprop) {

	A4GL_debug("fprop->colour=%d",fprop->colour);

  	attrib_field.colour=0;
  	attrib_field.reverse=0;
  	attrib_field.underline=0;
  	attrib_field.bold=0;
  	attrib_field.blink=0;
  	attrib_field.dim=0;
  	attrib_field.normal=0;

	A4GL_attr_int_to_std(fprop->colour<<8,&attrib_field);
	A4GL_debug("attrib_field.colour=%d\n",attrib_field.colour);

	if (A4GL_has_bool_attribute(fprop,FA_B_REVERSE)) { attrib_field.reverse=1; }
	if (A4GL_has_bool_attribute(fprop,FA_B_INVISIBLE)) { attrib_field.invisible=1; }

	//if (A4GL_has_bool_attribute(fprop,FA_B_UNDERLINE)) { attrib_field.underline=1; }
	//if (A4GL_has_bool_attribute(fprop,FA_B_BOLD)) { attrib_field.bold=1; }
	//if (A4GL_has_bool_attribute(fprop,FA_B_BLINK)) { attrib_field.blink=1; }
	//if (A4GL_has_bool_attribute(fprop,FA_B_DIM)) { attrib_field.dim=1; }
	//if (A4GL_has_bool_attribute(fprop,FA_B_NORMAL)) { attrib_field.normal=1; }


	attr=0;
	attr=attr+attrib_field.colour;
	if (attrib_field.normal) attr+=AUBIT_ATTR_NORMAL;
	if (attrib_field.reverse) attr+=AUBIT_ATTR_REVERSE;
	if (attrib_field.underline) attr+=AUBIT_ATTR_UNDERLINE;
	if (attrib_field.bold) attr+=AUBIT_ATTR_BOLD;
	if (attrib_field.blink) attr+=AUBIT_ATTR_BLINK;
	if (attrib_field.dim) attr+=AUBIT_ATTR_DIM;


	A4GL_debug("Form attribute = %x\n",attr);

	if (attr==0||attr==FA_C_WHITE<<8) {
		ptr_attrib_field=0;
	} else {
		ptr_attrib_field=&attrib_field;
A4GL_debug("determined Attribute setting attrib_field =  %x %d %d %d %d %d %d", ptr_attrib_field->colour, ptr_attrib_field->normal, ptr_attrib_field->reverse, ptr_attrib_field->underline, ptr_attrib_field->bold, ptr_attrib_field->blink, ptr_attrib_field->dim);
	}

}

A4GL_debug("ptr_attrib_field=%p\n",ptr_attrib_field);

r=A4GL_determine_attribute_as_std_attr(cmd_type, ptr_attrib_curr, ptr_attrib_field);

if (r==0) {
	A4GL_debug("no Attribute specified anywhere...");
		return 0;
}


A4GL_debug("MJAMJAMJA determined Attribute : %x %d %d %d %d %d %d", r->colour, r->normal, r->reverse, r->underline, r->bold, r->blink, r->dim);
attr=0;
A4GL_debug("Have Attribute..");
attr=attr+r->colour;
if (r->normal) attr+=AUBIT_ATTR_NORMAL;
if (r->reverse) attr+=AUBIT_ATTR_REVERSE;
if (r->underline) attr+=AUBIT_ATTR_UNDERLINE;
if (r->bold) attr+=AUBIT_ATTR_BOLD;
if (r->blink) attr+=AUBIT_ATTR_BLINK;
if (r->dim) attr+=AUBIT_ATTR_DIM;
A4GL_debug("Returning Attribute : %d\n",attr);

return attr;
}

/* =============================== EOF ================================== */
