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
# $Id: color.c,v 1.1 2002-06-26 06:11:44 afalout Exp $
#*/

/**
 * @file
 *
 * Color and styles to be used by 4gl.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#ifdef OLD_INCL

	#include <gtk/gtk.h>

	#include "a4gl_aubitcolours.h"
	#include "a4gl_debug.h"


#else

    #include "a4gl_lib_ui_gtk_int.h"

#endif

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

/*
#define COLOR_BLACK     0
#define COLOR_RED       1
#define COLOR_GREEN     2
#define COLOR_YELLOW    3
#define COLOR_BLUE      4
#define COLOR_MAGENTA   5
#define COLOR_CYAN      6
#define COLOR_WHITE     7
*/

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/**
 * Flag that indicates if the colors have allready been alocated
 */
static int allocated_colors=0;

GdkColormap * colormap;

/**
 * Array of styles
 */
GdkColor gdkColors[8]={
	{0,	0,0,0},
	{0,	0xffff,0,0},
	{0,	0,0xffff,0},
	{0,	0xffff,0xffff,0},
	{0,	0,0,0xffff},
	{0,	0xffff,0,0xffff},
	{0,	0,0xffff,0xffff},
	{0,	0xffff,0xffff,0xffff}
};


GtkStyle *colorStyles[8];
GtkStyle *rcolorStyles[8];

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

void
MyStyleSetItemColor(
    GdkColor   color,     /* The allocated color to be added to the style */
    char       item,      /* the item to which the color is to be applied */
                          /* 'f' = foreground; 'b' = background;*/
                          /* 'l' = light;      'd' = dark;*/
                          /* 'm' = mid;        't' = text;*/
                          /* 's' = base.*/
    GtkStyle * style      /* The old style - changes made to a copy */
 );



#ifdef OLD_INCL
	void alloc_colors(void);
	void gui_set_field_fore(GtkWidget *w,int attr);
	void gui_set_field_back(GtkWidget *w,int attr);
#endif


/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 * Allocate the colors and assigns it to the styles used.
 */
void
alloc_colors(void)
{
  int a;
  GtkStyle *default_style;

	colormap = gdk_colormap_get_system();
	default_style=gtk_widget_get_default_style();

	/* Allocate the colors first... */
	for (a=0;a<8;a++)
	{
		gdk_colormap_alloc_color(colormap,&gdkColors[a],FALSE,TRUE);
		colorStyles[a]=gtk_style_copy(default_style);
		rcolorStyles[a]=gtk_style_copy(default_style);
		MyStyleSetItemColor(gdkColors[a],'f',colorStyles[a]);
		MyStyleSetItemColor(gdkColors[a],'b',rcolorStyles[a]);
	}
  
  	allocated_colors=1;
}



/**
 * This function Shamelessly nicked from a post by Tony Denault <denault@hawaii.edu>
 *
 */
void 
MyStyleSetItemColor(
    GdkColor   color,     /* The allocated color to be added to the style */
    char       item,      /* the item to which the color is to be applied */
                          /* 'f' = foreground; 'b' = background;*/
                          /* 'l' = light;      'd' = dark;*/
                          /* 'm' = mid;        't' = text;*/
                          /* 's' = base.*/
    GtkStyle * style      /* The old style - changes made to a copy */
)
{
    int i;
    switch ( item )
    {
       case 'f':
       case 'F':
          for ( i = 0; i < 5; i++ )
             style->fg[i] = color;
          break;
       case 'b':
       case 'B':
          for ( i = 0; i < 5; i++ )
             style->bg[i] = color;
          break;
       case 'l':
       case 'L':
          for ( i = 0; i < 5; i++ )
             style->light[i] = color;
         break;
      case 'd':
      case 'D':
         for ( i = 0; i < 5; i++ )
            style->dark[i] = color;
         break;
       case 'm':
       case 'M':
          for ( i = 0; i < 5; i++ )
             style->mid[i] = color;
          break;
       case 't':
       case 'T':
          for ( i = 0; i < 5; i++ )
          for ( i = 0; i < 5; i++ )
             style->text[i] = color;
          break;
       case 's':
       case 'S':
          for ( i = 0; i < 5; i++ )
             style->base[i] = color;
          break;
    }
}

/**
 * Sets the color for foreground field
 *
 * @param w The widget used.
 * @param attr The index of the style wanted.
 */
void
gui_set_field_fore(GtkWidget *w,int attr)
{
	debug("Setting style to %x",attr);
	if (allocated_colors==0) alloc_colors();

	if (attr&AUBIT_ATTR_REVERSE) {
		debug("REVERSE VIDEO!!!");
		gtk_widget_set_style(w, rcolorStyles[attr&7]);
	}
	else gtk_widget_set_style(w, colorStyles[attr&7]);
	/* gtk_widget_modify_style(w,rc_style[attr]); */
}

/**
 * Sets the field background.
 *
 * @param w The widget to be modified.
 * @param attr The index of the style wanted.
 */
void
gui_set_field_back(GtkWidget *w,int attr)
{
	if (allocated_colors==0) alloc_colors();
	gtk_widget_set_style(w, colorStyles[attr&7]);
}

/* =========================== EOF ================================ */

