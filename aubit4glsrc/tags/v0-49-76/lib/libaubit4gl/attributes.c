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
# $Id: attributes.c,v 1.30 2005-03-17 20:48:34 mikeaubury Exp $
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
//char * A4GL_get_currwin_name (void);

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

/*
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
*/

int A4GL_get_attr_from_string (char *s);
int A4GL_evaluate_field_colour(char *field_contents, struct struct_scr_field *fprop);

struct s_std_attr *A4GL_determine_attribute_as_std_attr (int cmd_type,
							 struct s_std_attr
							 *attrib_curr,
							 struct s_std_attr
							 *attrib_field);

struct s_std_attr *A4GL_determine_attribute_internal (struct s_std_attr
						      *attrib_curr,
						      struct s_std_attr
						      *attrib_field,
						      struct s_std_attr
						      *syscol,
						      struct s_std_attr
						      *options,
						      struct s_std_attr
						      *disp_form,
						      struct s_std_attr
						      *open_window);
void A4GL_attr_int_to_std (int attr, struct s_std_attr *p);
int A4GL_determine_attribute_as_int (int cmd_type,
				     struct s_std_attr *attrib_curr,
				     struct s_std_attr *attrib_field);

int A4GL_get_curr_form_attr (void);



int
A4GL_get_curr_form_attr (void)
{
  void *ptr;
  int attr;
  char buff[20];
  ptr = A4GL_get_curr_form (0);
  sprintf (buff, "%p", ptr);
  if (A4GL_has_pointer (buff, ATTRIBUTE))
    {
      attr = (int) A4GL_find_pointer (buff, ATTRIBUTE);

    }
  else
    {
      attr = 0;
    }

  return attr;
}


int
A4GL_get_curr_window_attr (void)
{
  A4GL_debug ("30 XXX - get_curr_window_attr");
  if (A4GL_has_pointer ((char *) A4GL_get_currwin_name (), ATTRIBUTE))
    {
      int a;
      a =
	(int) A4GL_find_pointer ((char *) A4GL_get_currwin_name (),
				 ATTRIBUTE);
      A4GL_debug ("30 Current window has an attribute %d", a);
      return a;
    }
  A4GL_debug ("30 Current window has no attribute");
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

  A4GL_debug ("30 Attr=%x\n", attr);
  strcpy (col_str, "WHITE");
  strcpy (attr_str, "");

  col_int = (attr & 0xf00);
  A4GL_debug ("30 col_int=%x\n", col_int);
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
  if (attr & AUBIT_ATTR_INVISIBLE)
    strcat (attr_str, "INVISIBLE ");
  if (attr & AUBIT_ATTR_ALTCHARSET)
    strcat (attr_str, "ALT ");
  A4GL_debug ("30 get_strings returning %s %s (DIM=%d)", A4GL_null_as_null(col_str), A4GL_null_as_null(attr_str),AUBIT_ATTR_DIM);
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

  if (strcasecmp (s, "INVISIBLE") == 0)
    return AUBIT_ATTR_INVISIBLE;
  if (strcasecmp (s, "LEFT") == 0)
    return AUBIT_ATTR_LEFT;
  printf ("Unknown attribute : %s\n", s);
  return -1;
}


/* 

go through the hierarchy to determine what attribute we should be using...

*/

struct s_std_attr *
A4GL_determine_attribute_as_std_attr (int cmd_type,
				      struct s_std_attr *attrib_curr,
				      struct s_std_attr *attrib_field)
{
  struct s_std_attr std_options;
  struct s_std_attr std_disp_form;
  struct s_std_attr std_open_window;
  struct s_std_attr *ptr_std_options = 0;
  struct s_std_attr *ptr_std_disp_form = 0;
  struct s_std_attr *ptr_std_open_window = 0;

  int int_options = 0;
  int int_disp_form = 0;
  int int_open_window = 0;

  switch (cmd_type)
    {
    case FGL_CMD_DISPLAY_CMD:	// DISPLAY / DISPLAY @
    case FGL_CMD_DISPLAY_FIELD_CMD:	// DISPLAY TO, DISPLAY BY NAME
    case FGL_CMD_DISPLAY_FORM:
      A4GL_debug ("30 Command is DISPLAY");
      int_options = A4GL_get_option_value ('d');
      int_disp_form = A4GL_get_curr_form_attr ();
      int_open_window = A4GL_get_curr_window_attr ();
      A4GL_debug ("30 int_options=%x int_disp_form=%x int_open_window=%x",
		  int_options, int_disp_form, int_open_window);
      break;

    case FGL_CMD_INPUT:
    case FGL_CMD_CONSTRUCT:
      A4GL_debug ("30 Command is INPUT");
      int_options = A4GL_get_option_value ('i');
      int_disp_form = A4GL_get_curr_form_attr ();
      int_open_window = A4GL_get_curr_window_attr ();
      break;
    }

if (int_options==0xffff || int_options==-1) int_options=0;
if (int_disp_form==0xffff || int_disp_form==-1) int_disp_form=0;
if (int_open_window==0xffff || int_open_window==-1) int_open_window=0;
A4GL_debug("INT OPTS : %x %x %x",int_options,int_disp_form,int_open_window);

  if (int_options)
    {
      ptr_std_options = &std_options;
		A4GL_debug("a");
      A4GL_attr_int_to_std (int_options, ptr_std_options);
    }
  if (int_disp_form)
    {
      ptr_std_disp_form = &std_disp_form;
		A4GL_debug("a");
      A4GL_attr_int_to_std (int_disp_form, ptr_std_disp_form);
    }
  if (int_open_window)
    {
      ptr_std_open_window = &std_open_window;
		A4GL_debug("a");
      A4GL_attr_int_to_std (int_open_window, ptr_std_open_window);
    }

A4GL_debug("XXX %x",attrib_curr);
  return A4GL_determine_attribute_internal (attrib_curr, attrib_field, 0,	// We don't do syscol yet...
					    ptr_std_options,
					    ptr_std_disp_form,
					    ptr_std_open_window);


}





struct s_std_attr *
A4GL_determine_attribute_internal (struct s_std_attr *attrib_curr,
				   struct s_std_attr *attrib_field,
				   struct s_std_attr *syscol,
				   struct s_std_attr *options,
				   struct s_std_attr *disp_form,
				   struct s_std_attr *open_window)
{

  static struct s_std_attr rval;
  struct s_std_attr *r = 0;

  A4GL_debug
    ("30 A4GL_determine_attribute_internal : c=%p f=%p s=%p o=%p d=%p w=%p",
     attrib_curr, attrib_field, syscol, options, disp_form, open_window);

/*

1. The ATTRIBUTE clause of the current statement. 

2. The attributes from the field descriptions in the ATTRIBUTES section of the current form file. (See  Field Attribute Syntax  on page 6-34.) 

3. The default attributes specified in the syscolatt table of any fields linked to database columns. To modify the syscolatt table, use the upscol utility. For information on using this utility, see Appendix B,  IBM Informix 4GL Utility Programs.  

4. The ATTRIBUTE clause of the most recent OPTIONS statement. 

5. The ATTRIBUTE clause of the current form in the most recent DISPLAY FORM statement. 

6. The ATTRIBUTE clause of the current 4GL window in the most recent OPEN WINDOW statement. 

7. The default reserved line positions and the default foreground color on your terminal.

*/

  if (attrib_curr)
    {
      A4GL_debug
	("30 determine_attribute_internal - Attribute : attrib_curr= %x %d %d %d %d %d %d %d",
	 attrib_curr->colour, attrib_curr->normal, attrib_curr->reverse,
	 attrib_curr->underline, attrib_curr->bold, attrib_curr->blink,
	 attrib_curr->dim, attrib_curr->invisible);
    }

  if (attrib_field)
    {
      A4GL_debug
	("30 determine_attribute_internal - Attribute : attrib_field= %x %d %d %d %d %d %d %d",
	 attrib_field->colour, attrib_field->normal, attrib_field->reverse,
	 attrib_field->underline, attrib_field->bold, attrib_field->blink,
	 attrib_field->dim, attrib_field->invisible);
    }

  A4GL_debug
    ("30 Determining attribute : curr=%p field=%p syscol=%p options=%p disp_Form=%p open_window=%p",
     attrib_curr, attrib_field, syscol, options, disp_form, open_window);
  if (attrib_curr && r == 0)
    {
      A4GL_debug ("30 Attribute 1");
      memcpy (&rval, attrib_curr, sizeof (struct s_std_attr));
      r = &rval;
    }
  if (attrib_field && r == 0)
    {
      A4GL_debug ("30 Attribute 2");
      memcpy (&rval, attrib_field, sizeof (struct s_std_attr));
      r = &rval;
    }
  if (syscol && r == 0)
    {
      A4GL_debug ("30 Attribute 3");
      memcpy (&rval, syscol, sizeof (struct s_std_attr));
      r = &rval;
    }
  if (options && r == 0)
    {
      A4GL_debug ("30 Attribute 4");
      memcpy (&rval, options, sizeof (struct s_std_attr));
      r = &rval;
    }
  if (disp_form && r == 0)
    {
      A4GL_debug ("30 Attribute 5");
      memcpy (&rval, disp_form, sizeof (struct s_std_attr));
      r = &rval;
    }
  if (open_window && r == 0)
    {
      A4GL_debug ("30 Attribute 6");
      memcpy (&rval, open_window, sizeof (struct s_std_attr));
      r = &rval;
    }

  if (r)
    {
      A4GL_debug ("30 determine_attribute_internal - Attribute : %x %d %d %d %d %d %d %d",
	 r->colour, r->normal, r->reverse, r->underline, r->bold, r->blink,
	 r->dim, r->invisible);

	return r;
    }
  else
    {
      A4GL_debug ("30 determine_attribute_internal - Attribute : No attribute");
	return r;
    }

  return r;

}


void
A4GL_attr_int_to_std (int attr, struct s_std_attr *p)
{
  int col_int;
  col_int = (attr & 0xf00);

  p->colour = col_int;
  p->reverse = 0;
  p->underline = 0;
  p->bold = 0;
  p->blink = 0;
  p->dim = 0;
  p->invisible = 0;
  p->normal = 0;

  if (attr & AUBIT_ATTR_NORMAL)
    p->normal = 1;
  if (attr & AUBIT_ATTR_REVERSE)
    p->reverse = 1;
  if (attr & AUBIT_ATTR_UNDERLINE)
    p->underline = 1;
  if (attr & AUBIT_ATTR_BOLD)
    p->bold = 1;
  if (attr & AUBIT_ATTR_BLINK)
    p->blink = 1;
  if (attr & AUBIT_ATTR_DIM)
    p->dim = 1;
  if (attr & AUBIT_ATTR_INVISIBLE)
    p->invisible = 1;

  A4GL_debug ("30 Attribute : %x %d %d %d %d %d %d", p->colour, p->normal,
	      p->reverse, p->underline, p->bold, p->blink, p->dim);
}





int
A4GL_determine_attribute_as_int (int cmd_type, struct s_std_attr *attrib_curr,
				 struct s_std_attr *attrib_field)
{
  struct s_std_attr *r;
  int attr;
  r =
    A4GL_determine_attribute_as_std_attr (cmd_type, attrib_curr,
					  attrib_field);
  attr = 0;
  attr = attr + r->colour;
  if (r->normal)
    attr += AUBIT_ATTR_NORMAL;
  if (r->reverse)
    attr += AUBIT_ATTR_REVERSE;
  if (r->underline)
    attr += AUBIT_ATTR_UNDERLINE;
  if (r->bold)
    attr += AUBIT_ATTR_BOLD;
  if (r->blink)
    attr += AUBIT_ATTR_BLINK;
  if (r->dim)
    attr += AUBIT_ATTR_DIM;
  if (r->invisible)
    attr += AUBIT_ATTR_INVISIBLE;

  return attr;
}





/* This is our main calling point ! */
int
A4GL_determine_attribute (int cmd_type, int attrib_curr_int, void *vfprop,
			  char *val_for_field)
{
  struct s_std_attr *r;
  struct s_std_attr attrib_curr;
  struct s_std_attr attrib_field;
  struct s_std_attr *ptr_attrib_curr = 0;
  struct s_std_attr *ptr_attrib_field = 0;
  struct struct_scr_field *fprop;
  int attr;


  
  if (cmd_type == FGL_CMD_CLEAR)
    {				// Dont bother with clear...
      A4GL_debug ("30 CMD_CLEAR Attributes are always 0...");
      return 0;
    }

  fprop = vfprop;
/* Decode our current attribute */
  A4GL_debug("attrib_curr_int=0x%x (%d)",attrib_curr_int,attrib_curr_int);

  if (attrib_curr_int!=-1 && attrib_curr_int!=0)
    {
		A4GL_debug("a - %x %d",attrib_curr_int,attrib_curr_int);
      		A4GL_attr_int_to_std (attrib_curr_int, &attrib_curr);
      		ptr_attrib_curr = &attrib_curr;
      A4GL_debug
	("30 determined Attribute setting attrib_curr =  %x %d %d %d %d %d %d %d",
	 ptr_attrib_curr->colour, ptr_attrib_curr->normal,
	 ptr_attrib_curr->reverse, ptr_attrib_curr->underline,
	 ptr_attrib_curr->bold, ptr_attrib_curr->blink, ptr_attrib_curr->dim,
	 ptr_attrib_curr->invisible);
    }

  if (fprop)
    {
      int a;


      attrib_field.colour = 0;
      attrib_field.reverse = 0;
      attrib_field.underline = 0;
      attrib_field.bold = 0;
      attrib_field.blink = 0;
      attrib_field.invisible = 0;
      attrib_field.dim = 0;
      attrib_field.normal = 0;

      a = A4GL_evaluate_field_colour (val_for_field, fprop);
A4GL_debug("eval = %d",a);

      if (a == -1)
	{
	  attr = 0;
	}
      else
	{
		A4GL_debug("a =%d",a);
	  A4GL_attr_int_to_std (a << 8, &attrib_field);
	  attr = attrib_field.colour;
        }


	  A4GL_debug ("30 attrib_field.colour=%d\n", attrib_field.colour);

	  if (A4GL_has_bool_attribute (fprop, FA_B_REVERSE))
	    {
	      attrib_field.reverse = 1;
	    }
	  if (A4GL_has_bool_attribute (fprop, FA_B_INVISIBLE))
	    {
	      attrib_field.invisible = 1;
	    }


	A4GL_debug("attr before = %x",attr);

	  if (attrib_field.normal)
	    attr += AUBIT_ATTR_NORMAL;
	  if (attrib_field.reverse)
	    attr += AUBIT_ATTR_REVERSE;
	  if (attrib_field.underline)
	    attr += AUBIT_ATTR_UNDERLINE;
	  if (attrib_field.bold)
	    attr += AUBIT_ATTR_BOLD;
	  if (attrib_field.blink)
	    attr += AUBIT_ATTR_BLINK;
	  if (attrib_field.dim)
	    attr += AUBIT_ATTR_DIM;
	  if (attrib_field.invisible)
	    attr += AUBIT_ATTR_INVISIBLE;
A4GL_debug("attr after = %x",attr);


	  A4GL_debug ("Form attribute = %x\n", attr);
	

      if (attr == 0)
	{
	  ptr_attrib_field = 0;
	}
      else
	{
	  ptr_attrib_field = &attrib_field;
	  A4GL_debug
	    (" determined Attribute setting attrib_field =  %x %d %d %d %d %d %d",
	     ptr_attrib_field->colour, ptr_attrib_field->normal,
	     ptr_attrib_field->reverse, ptr_attrib_field->underline,
	     ptr_attrib_field->bold, ptr_attrib_field->blink,
	     ptr_attrib_field->dim);
	}

    }

  A4GL_debug ("30 ptr_attrib_field=%p\n", ptr_attrib_field);

  A4GL_debug("ptr_attrib_curr=%p ptr_attrib_field=%p", ptr_attrib_curr, ptr_attrib_field);

  r =
    A4GL_determine_attribute_as_std_attr (cmd_type, ptr_attrib_curr,
					  ptr_attrib_field);

  if (r == 0)
    {
      A4GL_debug ("30 no Attribute specified anywhere...");
      return 0;
    }


  if ((r->colour==0xf00) && r->dim &&r->bold && r->blink) {
		A4GL_assertion(1,"Too many options set - probably corrupt attribute");
  }
  A4GL_debug (" MJAMJAMJA determined Attribute : %x %d %d %d %d %d %d",
	      r->colour, r->normal, r->reverse, r->underline, r->bold,
	      r->blink, r->dim);
  attr = 0;
  A4GL_debug ("30 Have Attribute..");
  attr = attr + r->colour;
  if (r->normal)
    attr += AUBIT_ATTR_NORMAL;
  if (r->reverse)
    attr += AUBIT_ATTR_REVERSE;
  if (r->underline)
    attr += AUBIT_ATTR_UNDERLINE;
  if (r->bold)
    attr += AUBIT_ATTR_BOLD;
  if (r->blink)
    attr += AUBIT_ATTR_BLINK;
  if (r->dim)
    attr += AUBIT_ATTR_DIM;
  if (r->invisible)
    attr += AUBIT_ATTR_INVISIBLE;
  A4GL_debug (" Returning Attribute : %d (%x)\n", attr,attr);

  return attr;
}

/* =============================== EOF ================================== */
