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
# $Id: compile_c_gtk.c,v 1.2 2002-05-20 11:41:13 afalout Exp $
#
*/


/**
 * @file
 * Generate .C & .H modules, that interface with GTK+ GUI libraries functions
 *
 * Most of the functions implemented here are called by the parser.
 *
 * The goal is to generate a C program that implement the functionality of
 * the 4gl being compiled.
 */

 /*
=====================================================================
		                    Includes
=====================================================================
*/

#include <string.h>
#include <stdio.h>

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

char lname[256];

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


extern void printc(char* fmt,... ); //in API_lex.c
extern void printh (char *fmt, ...); //in API_lex.x

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 * @todo Describe function
 */
void
print_formhandler (char *name)
{
strcpy(lname,name);
  printh
    ("int hnd_e_%s(GtkWidget *widget,GdkEvent *event,gpointer data);\n",
     name);
  printh
    ("int hnd_c_%s(GtkWidget *widget,gpointer data);\n",
     name);
  printh ("int hnd_%s (GtkWidget *widget, int isevent,GdkEvent *event,gpointer data);\n", name);
  printc
    ("int hnd_e_%s(GtkWidget *widget,GdkEvent *event,gpointer data) {\n",
     name);
  printc ("  hnd_%s(widget,1,event,data);\n", name);
  printc ("return 0;}\n");
  printc ("int hnd_c_%s(GtkWidget *widget,gpointer data) {\n", name);
  printc ("  return hnd_%s(widget,0,0,data);\n", name);
  printc ("}\n");
  printc ("int hnd_%s (GtkWidget *widget, int isevent,GdkEvent *event,gpointer data) {\n", name);

}

/**
 *
 * @todo Describe function
 */
void
print_getwin(void) 
{
	printc("static char this_win[64]=\"\";char cwin[64]; strcpy(cwin,get_currwin_name());\n",lname);
	printc("if (strlen(this_win)==0) strcpy(this_win,get_currwin_name());\n");
	printc("if (strcmp(this_win,cwin)!=0) current_window(this_win);");
}


/**
 *
 * @todo Describe function
 */
void
print_end_formhandler (void)
{
  printc ("}\n");
}


/**
 *
 * @todo Describe function
 */
void
print_event (int type)
{

  if (type == 'B')
    printc ("if (BEFORE_EVENT) {\n");
  if (type == 'b')
    printc ("if (BEFORE_OPEN_FORM) {\n");

  if (type == 'A')
    printc ("if (AFTER_EVENT) {\n");
  if (type == 'a')
    printc ("if (BEFORE_CLOSE_FORM) {\n");
}

/**
 *
 * @todo Describe function
 */
void
print_event_2 (void)
{
  printc ("}\n");
}

/**
 *
 * @todo Describe function
 */
void
print_gtk_field (int type, char *s)
{
  if (type == 'B')
    printc ("if (BEFORE_ANY) {\n");
  if (type == 'A')
    printc ("if (AFTER_ANY) {\n");

  if (type == 'b')
    printc ("if (BEFORE_FIELD(\"%s\")) {\n", s);
  if (type == 'a')
    printc ("if (AFTER_FIELD(\"%s\")) {\n", s);
  if (type == 'o')
    printc ("if (ON_FIELD(\"%s\")) {\n", s);
}


/**
 *
 * @todo Describe function
 */
void
print_gtk_field_2 (void)
{
  printc ("}\n");
}

/*************************************************************************/


/**
 *
 * @todo Describe function
 */
void
print_gtk_menuhandler_1 (char *name)
{
  printc ("void aclfglmn_%s(char *p) {\n", name);
}

/**
 *
 * @todo Describe function
 */
void
print_gtk_menuhandler_bsm (void)
{
  printc ("if (strcmp(p,\"__BSM__\")==0) {\n");
}


/**
 *
 * @todo Describe function
 */
void
print_gtk_menuhandler_bsm_end (void)
{
  printc ("}/* before show menu*/\n");
}

/**
 *
 * @todo Describe function
 */
void
print_gtk_menuhandler_on (char *s)
{
  char buff[256];
  print_gtk_menuhandler_bsm ();
  sprintf (buff, "\"%s\"", s);
  printc
    ("  if (!mn_itemexists(%s)) { exitwith(\"Menu item does not exist\");\n}",
     buff);
  printc ("}\nif (strcmp(p,%s)==0) {", buff);
}


/**
 *
 * @todo Describe function
 */
void
print_gtk_menuhandler_on_end (void)
{
  printc ("}\n");
}

/**
 *
 * @todo Describe function
 */
void
print_gtk_menuhandler_end(void) 
{
	printc("}\n");
}


// ================================= EOF ==============================
