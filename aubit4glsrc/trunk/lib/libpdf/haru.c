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
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: haru.c,v 1.12 2014-09-10 19:57:57 mikeaubury Exp $
#*/

/**
 * @file
 * PDF Report Implementation functions.
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 * @todo something similar to fit_textline but universal across libraries
 * @todo password. not supported on pdfliblite
 * @todo haru: textleading ?
 * @todo haru: utf8 support
 * @todo transition mode?
 */

/*
=====================================================================
                            Includes
=====================================================================
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include "hpdf.h"

#include "a4gl_lib_exreport_pdf_int.h"

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

#define SECTION_NORMAL  0
#define SECTION_HEADER  1
#define SECTION_TRAILER 2

#define A4GL_M_PI    3.14159265358979323846
// degrees to radians = PI / 180
#define A4GL_DEG2RAD 0.0174532925199433

// in percent
#define A4GL_DEFAULT_UNDERLINEPOSITION -10.0
#define A4GL_DEFAULT_UNDERLINEWIDTH      5.0
#define A4GL_DEFAULT_STROKEWIDTH         3.0

struct Haru_doc
{
    HPDF_Doc        doc;
    HPDF_Page       current_page;
};

typedef struct Haru_doc Haru_doc;

#ifdef HPDF_DLL
void __stdcall
#else
void
#endif // }}}
error_handler (HPDF_STATUS error_no, HPDF_STATUS detail_no, void *user_data);

#ifdef HPDF_DLL
void __stdcall
#else
void
#endif // }}}
error_handler (HPDF_STATUS error_no, HPDF_STATUS detail_no, void *user_data)
{
    char            buff[2000];

    printf ("ERROR: error_no=%04X, detail_no=%u\n", (HPDF_UINT) error_no, (HPDF_UINT) detail_no);
    sprintf (buff, "ERROR: error_no=%04X, detail_no=%u\n", (HPDF_UINT) error_no, (HPDF_UINT) detail_no);
    A4GL_set_errm (buff);
    A4GL_exitwith ("PDF Error");
}

#define DOC(x) ((Haru_doc *)(x->pdf_ptr))
#define DOC_CURRENT_PAGE(x) DOC(x)->current_page

HPDF_Doc        newdoc (struct pdf_rep_structure *rep);

char           *A4GL_get_pdf_haru_encoding (void);

static void     select_gmode (Haru_doc * doc, HPDF_UINT16 unew);
static void     begin_text_mode (struct pdf_rep_structure *rep);

// for generate_barcode
void            PDF_fill_stroke (void *pv);
void            PDF_rect (void *pv, double x, double y, double width, double height);
void            PDF_set_text_pos (void *pv, double x, double y);
void            PDF_setlinewidth (void *pv, double width);
void            PDF_show (void *pv, char *text);


void            A4GLREPORT_initlib (void);

static char    *A4GL_report_char_pop (void);

void            A4GL_pdf_add_spaces (void);
static int      A4GL_pdf_arc (struct pdf_rep_structure *rep, double x, double y, double r, double alpha, double beta, int direction);
static int      A4GL_pdf_arc_segment (struct pdf_rep_structure *rep, double x, double y, double r, double alpha, double beta);
static void     A4GL_pdf_get_font_info (struct pdf_rep_structure *rep);
static int      A4GL_pdf_is_core_font (char const *font);
double          A4GL_pdf_metric (int a, char c, struct pdf_rep_structure *rep);
void            A4GL_pdf_move (struct pdf_rep_structure *rep);
int             A4GL_pdf_new_page (struct pdf_rep_structure *rep);
static void     A4GL_pdf_position_aligned_text (struct pdf_rep_structure *rep, double x, double y, char *text, char *align);
static void     A4GL_pdf_reset_color (struct pdf_rep_structure *rep);
static void     A4GL_pdf_resume_page (struct pdf_rep_structure *rep, int page);
static void     A4GL_pdf_set_color (struct pdf_rep_structure *rep, const char *fstype, const char *colorspace, double c1, double c2, double c3, double c4);
static void     A4GL_pdf_set_compression (struct pdf_rep_structure *rep, int level);
static int      A4GL_pdf_set_font_name (struct pdf_rep_structure *rep, char *font_name, int font_embedded);
static void     A4GL_pdf_show_text_internal (struct pdf_rep_structure *rep, char *text);
static void     A4GL_pdf_suspend_page (struct pdf_rep_structure *rep);
static double   A4GL_pdf_text_width (struct pdf_rep_structure *rep, char *text);

void            generate_barcode (Haru_doc * p, double xpos, double ypos, double x, double y, char *str, float p_page_height, int incl_text);
void            set_barcode_type (char *s);

// used to print out pdf debugging info
int             A4GL_PDF_DEBUG = 0;

struct pdf_font_info_s
{
    char   *name;
    // position of underline in percent of font size from baseline. up(+) or down(-)
    double  underlineposition;
    // width of underline in percent of font size.
    // 5% is pdflib default apparently.
    double  underlinewidth;
};

static const struct pdf_font_info_s pdf_font_info[] =
{
    //font                             underline
    //name                   core     pos  width
    {"Courier",                -19.8,   5.2},
    {"Courier-Oblique",        -19.8,   5.2},
    {"Courier-Bold",           -19.8,   5.2},
    {"Courier-BoldOblique",    -19.8,   5.2},
    {"Helvetica",              -10.6,   7.3},
    {"Helvetica-Oblique",      -10.6,   7.3},
    {"Helvetica-Bold",         -10.6,  10.5},
    {"Helvetica-BoldOblique",  -10.6,  10.5},
    {"Times-Roman",            -10.9,   4.9},
    {"Times-Italic",           -10.9,   4.9},
    {"Times-Bold",             -10.9,   9.5},
    {"Times-BoldItalic",       -10.9,   9.5},
    {"Symbol",                 -10.0,   5.0},
    {"ZapfDingbats",           -10.0,   5.0},

    {NULL,                       0.0,   0.0}
};


// A4GLPDFREP_EXREPORT_initlib {{{
/**
 *
 * @todo Describe function
 */
int
A4GLPDFREP_EXREPORT_initlib (void)
{

    A4GL_PDF_DEBUG = A4GL_isyes (acl_getenv ("A4GL_PDF_DEBUG"));

#ifdef DEBUG // {{{
    A4GL_debug ("In A4GLPDFREP_EXREPORT_initlib");
#endif // }}}

    return 1;
}
// }}}

// A4GL_report_char_pop {{{
static char    *
A4GL_report_char_pop (void)
{
    int             tos_size;
    int             tos_dtype;
    void           *tos_ptr;
    char           *ptr;
    char           *(*function) (void *, int, int, struct struct_scr_field *, int);

    A4GL_get_top_of_stack (1, &tos_dtype, &tos_size, (void **) &tos_ptr);

    function = (char *(*)(void *, int, int, struct_scr_field *, int)) A4GL_get_datatype_function_i (tos_dtype & DTYPE_MASK, "DISPLAY");

    A4GL_assertion (function == 0, "No report display function for this datatype");

    ptr = function (tos_ptr, tos_size, -1, (struct struct_scr_field *) 0, DISPLAY_TYPE_PRINT);

    if (ptr != 0)
    {
        ptr = strdup (ptr);
        A4GL_drop_param ();
    }
    else
    {
        ptr = A4GL_char_pop ();
    }

    return ptr;
}
// }}}

// A4GL_pdf_add_spaces {{{
/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_add_spaces (void)
{
    int             a;
    char            str[1000];

    a = A4GL_pop_int ();

    if (a >= 1000)
        a = 999;

    memset (str, ' ', a);
    str[a] = 0;

    A4GL_push_char (str);
}
// }}}
// A4GL_pdf_get_font_info {{{
static void
A4GL_pdf_get_font_info (struct pdf_rep_structure *rep)
{
    int found = 0;
    int i;

    //search for font in table to get info
    for (i = 0; pdf_font_info[i].name != NULL; i++)
    {
        const char *search_name = rep->font_name;
        const char *table_name = pdf_font_info[i].name;

        for (; *search_name; ++search_name, ++table_name)
        {
            if (*search_name != *table_name)
            break;
        }

        if (*search_name == *table_name)
        {
            rep->value.underlineposition = pdf_font_info[i].underlineposition;
            rep->value.underlinewidth = pdf_font_info[i].underlinewidth;
            found = 1;
            break;
        }
    }

    if (!found)
    {
        // use defaults if not found
        rep->value.underlineposition = A4GL_DEFAULT_UNDERLINEPOSITION;
        rep->value.underlinewidth = A4GL_DEFAULT_UNDERLINEWIDTH;
    }

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
        printf ("A4GL_pdf_get_font_info font_name=%s position=%f width=%f found=%d\n", rep->font_name, rep->value.underlineposition, rep->value.underlinewidth, found);
    A4GL_debug ("A4GL_pdf_get_font_info font_name=%s position=%f width=%f found=%d\n", rep->font_name, rep->value.underlineposition, rep->value.underlinewidth, found);
#endif // }}}

    return;

}
// }}}
// A4GL_pdf_arc {{{
/**
 * Draws an arc
 *
 * @param rep         Pointer to pdf_rep_structure
 * @param x,y         The coordinates of the center of the circular arc segment.
 * @param r           The radius of the circular arc segment. r must be positive.
 * @param alpha, beta The start and end angles of the circular arc segment in degrees. Angles are measured counterclockwise from the positive x axis.
 * @param direction   1=clockwise, -1=counterclockwise.
 *
 * @returns 0
 */
static int
A4GL_pdf_arc (struct pdf_rep_structure *rep, double x, double y, double r, double alpha, double beta, int direction)
{
    double          rad_alpha;
    double          start_pos_x;
    double          start_pos_y;

    HPDF_UINT16     state;

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("args A4GL_pdf_arc x=%f y=%f r=%f alpha=%f beta=%f direction=%d\n", x, y, r, alpha, beta, direction);
    A4GL_debug ("args A4GL_pdf_arc x=%f y=%f r=%f alpha=%f beta=%f direction=%d\n", x, y, r, alpha, beta, direction);
#endif // }}}

    // find start position
    rad_alpha = alpha * A4GL_DEG2RAD;

    start_pos_x = x + (r * cos (rad_alpha));
    start_pos_y = y + (r * sin (rad_alpha));

    select_gmode (DOC (rep), HPDF_GMODE_PATH_OBJECT);

    // decide whether to move to or draw a line to the start position depending on current graphics state
    state = HPDF_Page_GetGMode (DOC_CURRENT_PAGE (rep));

    if (state != HPDF_GMODE_PATH_OBJECT &&
        state != HPDF_GMODE_CLIPPING_PATH)
    {
        // no path so start a new one
        HPDF_Page_MoveTo (DOC_CURRENT_PAGE (rep), start_pos_x, start_pos_y);
    }
    else
    {
        // path started so join to start position if not there already
        HPDF_Point point;
        double     current_x;
        double     current_y;

        point = HPDF_Page_GetCurrentPos (DOC_CURRENT_PAGE (rep));

        current_x = point.x;
        current_y = point.y;

        if (start_pos_x != current_x ||
            start_pos_y != current_y)
            HPDF_Page_LineTo (DOC_CURRENT_PAGE (rep), start_pos_x, start_pos_y);
    }

    if (direction == 1)
    {
        // clockwise
        while (alpha < beta)
            alpha += 360;
    }
    else
    {
        // counterclockwise
        while (beta < alpha)
            beta += 360;
    }

    if (alpha == beta)
        return 0;

    if (direction == 1)
    {
        // clockwise
        while (alpha - beta > 90)
        {
            A4GL_pdf_arc_segment (rep, x, y, r, alpha, alpha - 90);
            alpha -= 90;
        }
    }
    else
    {
        // counterclockwise
        while (beta - alpha > 90)
        {
            A4GL_pdf_arc_segment (rep, x, y, r, alpha, alpha + 90);
            alpha += 90;
        }
    }

    if (alpha != beta)
        A4GL_pdf_arc_segment (rep, x, y, r, alpha, beta);

    return 0;
}
// }}}
// A4GL_pdf_arc_segment {{{
/**
 * Draws an arc segment up to 90 degrees
 *
 * @param rep         Pointer to pdf_rep_structure
 * @param x,y         The coordinates of the center of the circular arc segment.
 * @param r           The radius of the circular arc segment. r must be positive.
 * param alpha, beta The start and end angles of the cirlular arc segment in degrees. Angles are measured counterclockwise from the positive x axis.
 *
 * @returns 0
 */
static int
A4GL_pdf_arc_segment (struct pdf_rep_structure *rep, double x, double y, double r, double alpha, double beta)
{
    double          cos_alpha;
    double          cos_beta;
    double          sin_alpha;
    double          sin_beta;
    double          bezier_cp;

    alpha = alpha * A4GL_DEG2RAD;
    beta  = beta  * A4GL_DEG2RAD;

    cos_alpha = cos (alpha);
    cos_beta  = cos (beta);
    sin_alpha = sin (alpha);
    sin_beta  = sin (beta);

    bezier_cp = (4.0 / 3 * ((1 - cos ((beta - alpha) / 2)) / sin ((beta - alpha) / 2)));

    HPDF_Page_CurveTo (DOC_CURRENT_PAGE (rep),
        x + (r * (cos_alpha - bezier_cp * sin_alpha)), y + (r * (sin_alpha + bezier_cp * cos_alpha)),
        x + (r * (cos_beta  + bezier_cp * sin_beta)) , y + (r * (sin_beta  - bezier_cp * cos_beta)),
        x + (r *  cos_beta)                          , y + (r *  sin_beta)
        );

    return 0;
}
// }}}
// A4GL_pdf_is_core_font {{{
/**
 * Checks whether a font is core or not.
 *
 * @param font  Name of font to check.
 * @returns 1 if font is a core font, otherwise 0.
 */
static int
A4GL_pdf_is_core_font (char const *font)
{
    if (strcmp (font, "Courier") == 0 ||
        strcmp (font, "Courier-Oblique") == 0 ||
        strcmp (font, "Courier-Bold") == 0 ||
        strcmp (font, "Courier-BoldOblique") == 0 ||
        strcmp (font, "Helvetica") == 0 ||
        strcmp (font, "Helvetica-Oblique") == 0 ||
        strcmp (font, "Helvetica-Bold") == 0 ||
        strcmp (font, "Helvetica-BoldOblique") == 0 ||
        strcmp (font, "Times-Roman") == 0 ||
        strcmp (font, "Times-Italic") == 0 ||
        strcmp (font, "Times-Bold") == 0 ||
        strcmp (font, "Times-BoldItalic") == 0 ||
        strcmp (font, "Symbol") == 0 ||
        strcmp (font, "ZapfDingbats") == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
// }}}
// A4GL_pdf_metric {{{
/**
 *
 * @todo Describe function
 */
double
A4GL_pdf_metric (int a, char c, struct pdf_rep_structure *rep)
{

#ifdef DEBUG // {{{
    A4GL_debug ("pdf_metric a=%d c=%c p=%p", a, c, rep);
#endif // }}}

    if (c == 'c')
    {

#ifdef DEBUG // {{{
        A4GL_debug ("metric C %d %c", a, c);
#endif // }}}

        if (DOC (rep) && DOC_CURRENT_PAGE (rep))
        {
            return (double) ((double) a * A4GL_pdf_text_width (rep, "W"));
        }
        else
        {
            return (double) ((double) a * 8 * (rep->value.horizscaling / 100));
        }
    }
    else
    {

#ifdef DEBUG // {{{
        A4GL_debug ("metric L %d %c", a, c);
#endif // }}}

        return (double) (a * rep->font_size);     /* 18 */
    }
}
// }}}
// A4GL_pdf_move {{{
/**
 *
 * @todo Describe function
 */
void
A4GL_pdf_move (struct pdf_rep_structure *rep)
{

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("Move to x=%f y=%f\n", rep->col_no, rep->page_length - rep->line_no);
    A4GL_debug ("Move to x=%f y=%f\n", rep->col_no, rep->page_length - rep->line_no);
#endif // }}}

    // we need to begin text mode to reset x and y to 0, 0
    begin_text_mode (rep);

    HPDF_Page_MoveTextPos (DOC_CURRENT_PAGE (rep), rep->col_no, rep->page_length - rep->line_no);
}
// }}}
// A4GL_pdf_new_page {{{
/**
 *
 * @todo Describe function
 */
int
A4GL_pdf_new_page (struct pdf_rep_structure *rep)
{

#ifdef DEBUG // {{{
    A4GL_debug ("NEW PAGE : %d\n", rep->page_no);
#endif // }}}

    if (rep->page_no)
    {
        // clear any pending stokes or text placements...
        select_gmode (DOC (rep), HPDF_GMODE_PAGE_DESCRIPTION);

        if (A4GL_isyes (acl_getenv ("A4GL_PDF_SUSPEND_PAGES")))
            A4GL_pdf_suspend_page (rep);
    }

#ifdef DEBUG // {{{
    A4GL_debug ("Begin page width = %lf length=%lf\n", rep->page_width, rep->page_length);
#endif // }}}

    DOC (rep)->current_page = HPDF_AddPage (DOC (rep)->doc);

    HPDF_Page_SetWidth (DOC (rep)->current_page, rep->page_width);
    HPDF_Page_SetHeight (DOC (rep)->current_page, rep->page_length);

    // ensure a font is always set
    A4GL_pdf_set_font_name (rep, rep->font_name, 0);

    // reset parameter and value defaults
    rep->parameter.underline = 0;
    rep->parameter.overline  = 0;
    rep->parameter.strikeout = 0;

    rep->value.horizscaling  = 100;
    rep->value.strokewidth   = 0;
    rep->value.textrendering = 0;
    rep->value.textrise      = 0;

#ifdef DEBUG // {{{
    A4GL_debug ("Done\n");
#endif // }}}

    // do we need bluebars ? 
    if (rep->bluebar_style != E_BLUEBAR_NONE)
    {
        //double printable;
        double          eachline;
        double          ypos;

        //printable = rep->page_height - (rep->top_margin);
        //eachline = printable / h;
        eachline = A4GLPDFREP_A4GL_pdf_size (1, 'l', rep);

        A4GL_pdf_set_color (rep, "both", "rgb", rep->bluebar_r, rep->bluebar_g, rep->bluebar_b, 0);

        select_gmode (DOC (rep), HPDF_GMODE_PAGE_DESCRIPTION);

        HPDF_Page_SetLineWidth (DOC (rep)->current_page, eachline / 20);

        if (rep->bluebar_style == E_BLUEBAR_5LINE)
        {
            int             a;

            ypos = rep->page_length - rep->top_margin;

            for (a = 0;; a += 2)
            {
                //char *ptr;
                int             bb;

                //double ypos_spacing;
                float           spacing;

                spacing = 0;
                spacing -= 2.0 * (float) eachline / 10;

                for (bb = 0; bb < 5; bb++)
                {
                    spacing -= 2.0 * (float) eachline / 10;

                    HPDF_Page_MoveTo (DOC (rep)->current_page, (0), ypos + spacing);
                    HPDF_Page_LineTo (DOC (rep)->current_page, (rep->page_width), ypos + spacing);
                }

                ypos = ypos - (eachline * 2);

                if (ypos + eachline < rep->bottom_margin)
                    break;
            }

            HPDF_Page_Stroke (DOC (rep)->current_page);
        }

        if (rep->bluebar_style == E_BLUEBAR_RECTANGLE)
        {
            int             a;

            ypos = rep->page_length - (rep->top_margin + eachline);

            for (a = 0;; a += 2)
            {
                //char *ptr;
                //int bb;
                float           offset;

                //ypos=a * eachline;
                //spacing -= (float) eachline / 10;
                offset = 2.0 * (float) eachline / 10;

                if (ypos + eachline > (rep->page_length))
                    break;

                HPDF_Page_Rectangle (DOC (rep)->current_page, (0), ypos - offset, rep->page_width, eachline * 0.9);
                HPDF_Page_FillStroke (DOC (rep)->current_page);

                ypos = ypos - (eachline * 2);

                if (ypos + eachline < rep->bottom_margin)
                    break;
            }
        }

        A4GL_pdf_reset_color (rep);
    }

#ifdef DEBUG // {{{
    A4GL_debug ("ok!\n");
#endif // }}}

    return 1;
}
// }}}
// A4GL_pdf_position_aligned_text {{{
/**
 * Sets text position according to alignment required
 *
 * @param rep   Pointer to pdf_rep_structure
 * @param x     x coordinate
 * @param y     y coordinate
 * @param text  Text to base alignment on
 * @param align Alignment required. left, right, or center
 */
static void
A4GL_pdf_position_aligned_text (struct pdf_rep_structure *rep, double x, double y, char *text, char *align)
{
    double          text_width = 0;

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("A4GL_pdf_position_aligned_text x=%f y=%f text=%s align=%s\n", x, y, text, align);
    A4GL_debug ("A4GL_pdf_position_aligned_text x=%f y=%f text=%s align=%s\n", x, y, text, align);
#endif // }}}

    // if right or center is required then get width of text
    if (strcmp (align, "right") == 0 ||
        strcmp (align, "center") == 0)
        text_width = A4GL_pdf_text_width (rep, text);

    // adjust alignment position if required
    if (strcmp (align, "right") == 0)
    {
        x -= text_width;
    }
    if (strcmp (align, "center") == 0)
    {
        x -= text_width / 2;
    }

    // we need to begin text mode to reset x and y to 0, 0
    begin_text_mode (rep);

    HPDF_Page_MoveTextPos (DOC_CURRENT_PAGE (rep), x, y);

    return;
}
// }}}
// A4GL_pdf_reset_color {{{
static void
A4GL_pdf_reset_color (struct pdf_rep_structure *rep)
{

    HPDF_Page_SetRGBStroke (DOC_CURRENT_PAGE (rep), rep->stroke_color_r, rep->stroke_color_g, rep->stroke_color_b);
    HPDF_Page_SetRGBFill (DOC_CURRENT_PAGE (rep), rep->fill_color_r, rep->fill_color_g, rep->fill_color_b);
}
// }}}
// A4GL_pdf_resume_page {{{
/**
 * Resume page
 *
 * @param rep  Pointer to pdf_rep_structure
 * @param page Page number to resume
 */
static void
A4GL_pdf_resume_page (struct pdf_rep_structure *rep, int page)
{

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("resume page=%d\n", page);
    A4GL_debug ("resume page=%d\n", page);
#endif // }}}

    DOC_CURRENT_PAGE (rep) = rep->pages_suspended_array[page - 1]->page_handle;

    rep->parameter.underline     = rep->pages_suspended_array[page - 1]->parameter.underline;
    rep->parameter.overline      = rep->pages_suspended_array[page - 1]->parameter.overline;
    rep->parameter.strikeout     = rep->pages_suspended_array[page - 1]->parameter.strikeout;

    rep->value.horizscaling      = rep->pages_suspended_array[page - 1]->value.horizscaling;
    rep->value.strokewidth       = rep->pages_suspended_array[page - 1]->value.strokewidth;
    rep->value.textrendering     = rep->pages_suspended_array[page - 1]->value.textrendering;
    rep->value.textrise          = rep->pages_suspended_array[page - 1]->value.textrise;
    rep->value.underlineposition = rep->pages_suspended_array[page - 1]->value.underlineposition;
    rep->value.underlinewidth    = rep->pages_suspended_array[page - 1]->value.underlinewidth;

    rep->current_page_no = page;

    return;
}
// }}}
// A4GL_pdf_set_color {{{
static void
A4GL_pdf_set_color (struct pdf_rep_structure *rep, const char *fstype, const char *colorspace, double c1, double c2, double c3, double c4)
{

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("setcolor fstype=%s colorspace=%s c1=%f c2=%f c3=%f c4=%f\n", fstype, colorspace, c1, c2, c3, c4);
    A4GL_debug ("setcolor fstype=%s colorspace=%s c1=%f c2=%f c3=%f c4=%f\n", fstype, colorspace, c1, c2, c3, c4);
#endif // }}}

    if (strcmp (colorspace, "rgb") != 0)
        A4GL_assertion (1, "A4GL_pdf_set_color must be rgb");

    select_gmode (DOC (rep), HPDF_GMODE_PAGE_DESCRIPTION);

    if (strcmp (fstype, "fill") == 0)
    {
        rep->fill_color_r = c1;
        rep->fill_color_g = c2;
        rep->fill_color_b = c3;
        HPDF_Page_SetRGBFill (DOC_CURRENT_PAGE (rep), c1, c2, c3);
        return;
    }

    if (strcmp (fstype, "stroke") == 0)
    {
        rep->stroke_color_r = c1;
        rep->stroke_color_g = c2;
        rep->stroke_color_b = c3;
        HPDF_Page_SetRGBStroke (DOC_CURRENT_PAGE (rep), c1, c2, c3);
        return;
    }
    if (strcmp (fstype, "both") == 0)
    {
        rep->fill_color_r = c1;
        rep->fill_color_g = c2;
        rep->fill_color_b = c3;
        rep->stroke_color_r = c1;
        rep->stroke_color_g = c2;
        rep->stroke_color_b = c3;
        HPDF_Page_SetRGBStroke (DOC_CURRENT_PAGE (rep), c1, c2, c3);
        HPDF_Page_SetRGBFill (DOC_CURRENT_PAGE (rep), c1, c2, c3);
        return;
    }

    A4GL_assertion (1, "unexpected fstype");
}
// }}}
// A4GL_pdf_set_compression {{{
/**
 * Sets compression level of PDF file
 *
 * @param rep   Pointer to pdf_rep_structure
 * @param level Level of compression (0-9)
 *
 * @remarks
 * haru  : 0=none, 1=text, 2=image, 3=text+image, 4=meta, 5=text+meta, 6-9=all. 6=default
 * pdflib: 0=none, 9=full. 6=default
 *
 */
void
A4GL_pdf_set_compression (struct pdf_rep_structure *rep, int level)
{

    HPDF_UINT  mode;

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("A4GL_pdf_set_compression level=%d\n", level);
    A4GL_debug ("A4GL_pdf_set_compression level=%d\n", level);
#endif // }}}

    switch (level)
    {
        case 0: mode = HPDF_COMP_NONE;                      break;
        case 1: mode = HPDF_COMP_TEXT;                      break;
        case 2: mode = HPDF_COMP_IMAGE;                     break;
        case 3: mode = HPDF_COMP_TEXT | HPDF_COMP_IMAGE;    break;
        case 4: mode = HPDF_COMP_METADATA;                  break;
        case 5: mode = HPDF_COMP_TEXT | HPDF_COMP_METADATA; break;
        case 6: mode = HPDF_COMP_ALL;                       break;
        case 7: mode = HPDF_COMP_ALL;                       break;
        case 8: mode = HPDF_COMP_ALL;                       break;
        case 9: mode = HPDF_COMP_ALL;                       break;
    }

    HPDF_SetCompressionMode (DOC (rep)->doc, mode);
}
// }}}
// A4GL_pdf_set_font_name {{{
/**
 * Sets font and embeds if required
 *
 * @param rep           Pointer to pdf_rep_structure
 * @param font_name     Font path/name without file extension
 * @param font_embedded 0=not embedded and set as current. 1=embedded and set as current. 2=embedded, but not set as current(to behave as pdf_function "embedfont").
 * @remarks
 * The font name will have the following extensions appended to it to search for the font file: @n
 * @n
 * .tte .ttf .otf .afm .pfm .ttc @n
 * .TTE .TTF .OTF .AFM .PFM .TTC @n
 * @n
 * If the font is a TTC type, the index for the font is specified after a : character. @n
 * @n
 * e.g. myttcfont:2 would set the font to myttcfont.ttc with an index of 2.
 */
static int
A4GL_pdf_set_font_name (struct pdf_rep_structure *rep, char *font_name, int font_embedded)
{
    HPDF_Font a;

    char         font_name_to_use[256];
    int          ttc_index;
    const char  *loaded_font_name;
    HPDF_BOOL    embedded = HPDF_FALSE;

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("args A4GL_pdf_set_font_name font_name=%s font_embedded=%d\n", font_name, font_embedded);
    A4GL_debug ("args A4GL_pdf_set_font_name font_name=%s font_embedded=%d\n", font_name, font_embedded);
#endif // }}}

    if (A4GL_pdf_is_core_font (font_name))
    {
        // font is core so nothing else to be done
        strcpy (font_name_to_use, font_name);
    }
    else
    {
        // font needs to be loaded
        int found_loaded = 0;
        int c;

        // see if font has already been loaded {{{
        if (rep->fonts_loaded_count > 0)
        {
            for (c = 0; c < rep->fonts_loaded_count; c++)
            {

#ifdef DEBUG // {{{
                if (A4GL_PDF_DEBUG)
                    printf ("search fonts_loaded_array pos=%d looking for=%s font_file=%s\n", c, font_name, rep->fonts_loaded_array[c]->font_file);
                A4GL_debug ("search fonts_loaded_array pos=%d looking for=%s font_file=%s\n", c, font_name, rep->fonts_loaded_array[c]->font_file);
#endif // }}}

                if (strcmp (font_name, rep->fonts_loaded_array[c]->font_file) == 0)
                {
                    found_loaded = 1;
                    break;
                }
            }
        }
        // }}}

        if (found_loaded)
        {

#ifdef DEBUG // {{{
            if (A4GL_PDF_DEBUG)
                printf ("Font requested has already been loaded\n");
            A4GL_debug ("Font requested has already been loaded\n");
#endif // }}}

            // font has already been loaded so just need its name
            strcpy (font_name_to_use, rep->fonts_loaded_array[c]->font_name);
        }
        else
        {
            // load the font {{{
        
            char         font_file[256];
            char         font_file_ab[256];
            int          found = 0;
            int          i = 0;
            int          ttc_index_found = 0;
            char        *ttc_separator_pos;

            typedef enum
            {
                type_tte  = 1,
                type_ttf  = 2,
                type_otf  = 3,
                type_afm  = 4,
                type_pfm  = 5,
                type_ttc  = 6,
                type_pfa  = 7,
                type_pfb  = 8
            }
            pdf_font_type;

            struct pdf_font_search_types_s
            {
                char   *extension;
                int     type;
            };

            static const struct pdf_font_search_types_s pdf_font_search_types[] =
            {
                //font
                //ext    type
                {".tte", type_tte},
                {".ttf", type_ttf},
                {".otf", type_otf},
                {".afm", type_afm},
                {".pfm", type_pfm},
                {".ttc", type_ttc},
                {".TTE", type_tte},
                {".TTF", type_ttf},
                {".OTF", type_otf},
                {".AFM", type_afm},
                {".PFM", type_pfm},
                {".TTC", type_ttc},
                {NULL, 0}
            };

            struct pdf_font_search_types_ab_s
            {
                char   *extension;
            };

            static const struct pdf_font_search_types_ab_s pdf_font_search_types_ab[] =
            {
                {".pfa",},
                {".pfb",},
                {".PFA",},
                {".PFB",},
                {NULL}
            };

            // see if font_name has ttc index separator
            ttc_separator_pos = strrchr (font_name, ':');
            
            if (ttc_separator_pos != NULL)
            {
                // move to start of index value position
                ttc_separator_pos++;

                // check if index value is present and read if so
                if (!*ttc_separator_pos)
                {
                    ttc_index = 0;
                }
                else
                {
                    // read the index value
                    ttc_index = atoi (ttc_separator_pos);

                    if (ttc_index == -1)
                    {
                        A4GL_assertion (1, "TTC font index invalid.");
                    }
                }

#ifdef DEBUG // {{{
                if (A4GL_PDF_DEBUG)
                    printf ("A4GL_pdf_set_font_name ttc_index=%d\n", ttc_index);
                A4GL_debug ("A4GL_pdf_set_font_name ttc_index=%d\n", ttc_index);
#endif // }}}

                // move back to separator position
                ttc_separator_pos--;

                // null terminate font_name string at ":" position ready for adding file extensions
                *ttc_separator_pos = 0;

                // flag to just look for .ttc or .TTC files as an index was present
                ttc_index_found = 1;
            }

            // search by cycling through possible file extensions
            for (i = 0; pdf_font_search_types[i].extension != NULL; i++)
            {
                // only search for ttc types if ttc index was found in font_name
                if (ttc_index_found)
                    if (pdf_font_search_types[i].type != type_ttc)
                        continue;

                // construct file to test for
                strcpy (font_file, font_name);
                strcat (font_file, pdf_font_search_types[i].extension);

                if (A4GL_file_exists (font_file))
                {
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                // see if font has already been loaded, but just use the font_name as is, in case it's a font name(handle) {{{
                // QUERY - should maybe just error with font not found as pdflib will only be compatible with this if FontOutline is set.
                found_loaded = 0;

                if (rep->fonts_loaded_count > 0 )
                {
                    for (c = 0; c < rep->fonts_loaded_count; c++)
                    {

#ifdef DEBUG // {{{
                        if (A4GL_PDF_DEBUG)
                            printf ("search fonts_loaded_array pos=%d looking for=%s font_name=%s\n", c, font_name, rep->fonts_loaded_array[c]->font_name);
                        A4GL_debug ("search fonts_loaded_array pos=%d looking for=%s font_name=%s\n", c, font_name, rep->fonts_loaded_array[c]->font_name);
#endif // }}}

                        if (strcmp (font_name, rep->fonts_loaded_array[c]->font_name) == 0)
                        {
                            found_loaded = 1;
                            break;
                        }
                    }
                }
                // }}}
                if (found_loaded)
                {
                    // font has already been loaded so just need its name
                    strcpy (font_name_to_use, font_name);
                }
                else
                {
                    A4GL_assertion (1, "Font file not found.");
                }
            }
            else
            {
                // try to load the font from file(s)

                if (font_embedded)
                    embedded = HPDF_TRUE;

                // tte
                if (pdf_font_search_types[i].type == type_tte)
                    A4GL_assertion (1, "TTE font type not supported.");

                // ttf
                if (pdf_font_search_types[i].type == type_ttf)
                    loaded_font_name = HPDF_LoadTTFontFromFile (DOC (rep)->doc, font_file, embedded);

                // otf
                if (pdf_font_search_types[i].type == type_otf)
                    A4GL_assertion (1, "OTF font type not supported.");

                // afm
                if (pdf_font_search_types[i].type == type_afm)
                {
                    if (!embedded)
                        // if not embedded then just need the afm file
                        loaded_font_name = HPDF_LoadType1FontFromFile (DOC (rep)->doc, font_file, NULL);
                    else
                    {
                        // if embedded then need to search for either a pfa or pfb file too
                        int found_ab = 0;
                        int j;

                        for (j = 0; pdf_font_search_types_ab[j].extension != NULL; j++)
                        {
                            strcpy (font_file_ab, font_name);
                            strcat (font_file_ab, pdf_font_search_types_ab[j].extension);

                            if (A4GL_file_exists (font_file_ab))
                            {
                                found_ab = 1;
                                break;
                            }
                        }

                        if (!found_ab)
                        {
                            A4GL_assertion (1, "PFA or PFB font not found for embedding.");
                        }

                        loaded_font_name = HPDF_LoadType1FontFromFile (DOC (rep)->doc, font_file, font_file_ab);
                    }
                }

                // pfm
                if (pdf_font_search_types[i].type == type_pfm)
                    A4GL_assertion (1, "PFM font type not supported.");

                // ttc
                if (pdf_font_search_types[i].type == type_ttc)
                    loaded_font_name = HPDF_LoadTTFontFromFile2 (DOC (rep)->doc, font_file, ttc_index, embedded);

                if (loaded_font_name == NULL)
                    A4GL_assertion (1, "Failed to load font.");

#ifdef DEBUG // {{{
                if (A4GL_PDF_DEBUG)
                    printf ("A4GL_pdf_set_font_name loaded_font_name=%s embedded=%d\n", loaded_font_name, font_embedded);
                A4GL_debug ("A4GL_pdf_set_font_name loaded_font_name=%s embedded=%d\n", loaded_font_name, font_embedded);
#endif // }}}

                strcpy (font_name_to_use, loaded_font_name);

                // add font to fonts loaded array
                rep->fonts_loaded_array = (struct fonts_loaded_s **) acl_realloc (rep->fonts_loaded_array, sizeof (struct fonts_loaded_s *) * (rep->fonts_loaded_count + 1));
                rep->fonts_loaded_array[rep->fonts_loaded_count] = (struct fonts_loaded_s *) acl_malloc2 (sizeof (struct fonts_loaded_s));
                rep->fonts_loaded_array[rep->fonts_loaded_count]->font_name = strdup (loaded_font_name);
                rep->fonts_loaded_array[rep->fonts_loaded_count]->font_file = strdup (font_name);

#ifdef DEBUG // {{{
                if (A4GL_PDF_DEBUG)
                    printf ("added to fonts_loaded_array index=%d name=%s file=%s\n", rep->fonts_loaded_count, rep->fonts_loaded_array[rep->fonts_loaded_count]->font_name, rep->fonts_loaded_array[rep->fonts_loaded_count]->font_file);
                A4GL_debug ("added to fonts_loaded_array index=%d name=%s file=%s\n", rep->fonts_loaded_count, rep->fonts_loaded_array[rep->fonts_loaded_count]->font_name, rep->fonts_loaded_array[rep->fonts_loaded_count]->font_file);
#endif // }}}

                rep->fonts_loaded_count++;
            }
            // }}}
        }
    }

    // make font current if embedded value is not 2
    if (font_embedded != 2)
    {
        strcpy (rep->font_name, font_name_to_use);

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("A4GL_pdf_set_font_name font=%s\n", rep->font_name);
        A4GL_debug ("A4GL_pdf_set_font_name font=%s\n", rep->font_name);
#endif // }}}

        a = HPDF_GetFont (DOC (rep)->doc, rep->font_name, A4GL_get_pdf_haru_encoding ());

        if (a == NULL)
        {
            A4GL_exitwith ("Unable to locate font");
            return 0;
        }
        else
        {
#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("A4GL_pdf_set_font_name font=%s ok\n", rep->font_name);
        A4GL_debug ("A4GL_pdf_set_font_name font=%s ok\n", rep->font_name);
#endif // }}}
        }

        rep->fontptr = a;

        HPDF_Page_SetFontAndSize (DOC_CURRENT_PAGE (rep), rep->fontptr, rep->font_size);

        A4GL_pdf_get_font_info (rep);
    }

    return 0;
}
// }}}
// A4GL_pdf_show_text_internal {{{
/**
 * Internal show text function that adds underline, overline, strikeout and strokewidth features.
 *
 * @param Pointer to pdf_rep_structure
 * @param Text to show
 */
static void
A4GL_pdf_show_text_internal (struct pdf_rep_structure *rep, char *text)
{
    double          text_width = 0;
    double          stroke_width_orig = 0;
    double          stroke_mode = 0;
    double          y_adjust = 0;
    double          x, y;

    HPDF_Point      point;

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("A4GL_pdf_show_text_internal text=%s\n", text);
    A4GL_debug ("A4GL_pdf_show_text_internal text=%s\n", text);
#endif // }}}

    point = HPDF_Page_GetCurrentTextPos (DOC_CURRENT_PAGE (rep));
    // printf ("getcurrenttextpos x=%f y=%f\n", point.x, point.y);

    x = point.x;
    y = point.y;

    // prepare for line drawing if underline, overline or strikeout is required
    if (rep->parameter.underline ||
        rep->parameter.overline ||
        rep->parameter.strikeout)
    {
        text_width = A4GL_pdf_text_width (rep, text);

        select_gmode (DOC (rep), HPDF_GMODE_PAGE_DESCRIPTION);
        HPDF_Page_GSave (DOC_CURRENT_PAGE (rep));

        HPDF_Page_SetLineCap (DOC_CURRENT_PAGE (rep), HPDF_BUTT_END);
        HPDF_Page_SetDash (DOC_CURRENT_PAGE (rep), NULL, 0, 0);
    }

    // underline {{{
    if (rep->parameter.underline)
    {
        double          line_width = 0;

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("underline=%d underlineposition=%f underlinewidth=%f\n", rep->parameter.underline, rep->value.underlineposition, rep->value.underlinewidth);
        A4GL_debug ("underline=%d underlineposition=%f underlinewidth=%f\n", rep->parameter.underline, rep->value.underlineposition, rep->value.underlinewidth);
#endif // }}}

        // line width at underlinewidth% of font size * horizscaling%
        line_width = ((rep->value.underlinewidth / 100) * rep->font_size) * (rep->value.horizscaling / 100);

        HPDF_Page_SetLineWidth (DOC_CURRENT_PAGE (rep), line_width);

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("underlinewidth calced=%f\n", line_width);
        A4GL_debug ("underlinewidth calced=%f\n", line_width);
#endif // }}}

        // line position at underlineposition% of font size + textrise
        y_adjust = ((rep->value.underlineposition / 100) * rep->font_size) + rep->value.textrise;

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("underlineposition y_adjust=%f\n", y_adjust);
        A4GL_debug ("underlineposition y_adjust=%f\n", y_adjust);
#endif // }}}

        HPDF_Page_MoveTo (DOC_CURRENT_PAGE (rep), x             , y + y_adjust);
        HPDF_Page_LineTo (DOC_CURRENT_PAGE (rep), x + text_width, y + y_adjust);
        HPDF_Page_Stroke (DOC_CURRENT_PAGE (rep));
    }
    // }}}
    // overline {{{
    if (rep->parameter.overline)
    {
        double          line_width = 0;
        double          ascent = 0;

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("overline=%d underlineposition=%f underlinewidth=%f\n", rep->parameter.overline, rep->value.underlineposition, rep->value.underlinewidth);
        A4GL_debug ("overline=%d underlineposition=%f underlinewidth=%f\n", rep->parameter.overline, rep->value.underlineposition, rep->value.underlinewidth);
#endif // }}}

        ascent = HPDF_Font_GetAscent (rep->fontptr);

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("overline=%d underlineposition=%f underlinewidth=%f ascent=%f\n", rep->parameter.overline, rep->value.underlineposition, rep->value.underlinewidth, ascent);
        A4GL_debug ("overline=%d underlineposition=%f underlinewidth=%f ascent=%f\n", rep->parameter.overline, rep->value.underlineposition, rep->value.underlinewidth, ascent);
#endif // }}}

        // line width at underlinewidth% of font size and horizscaling
        line_width = ((rep->value.underlinewidth / 100) * rep->font_size) * (rep->value.horizscaling / 100);

        HPDF_Page_SetLineWidth (DOC_CURRENT_PAGE (rep), line_width);

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("overlinewidth calced=%f\n", line_width);
#endif // }}}

        // line position at ascent - underlineposition% of font size + textrise
        y_adjust = (((ascent / 1000) - (rep->value.underlineposition / 100)) * rep->font_size) + rep->value.textrise;

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("overlineposition y_adjust=%f\n", y_adjust);
        A4GL_debug ("overlineposition y_adjust=%f\n", y_adjust);
#endif // }}}

        HPDF_Page_MoveTo (DOC_CURRENT_PAGE (rep), x             , y + y_adjust);
        HPDF_Page_LineTo (DOC_CURRENT_PAGE (rep), x + text_width, y + y_adjust);
        HPDF_Page_Stroke (DOC_CURRENT_PAGE (rep));
    }
    // }}}
    // strikeout {{{
    if (rep->parameter.strikeout)
    {
        double          line_width = 0;
        double          ascent = 0;

        ascent = HPDF_Font_GetAscent (rep->fontptr);

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("strikeout=%d underlineposition=%f underlinewidth=%f ascent=%f\n", rep->parameter.strikeout, rep->value.underlineposition, rep->value.underlinewidth, ascent);
        A4GL_debug ("strikeout=%d underlineposition=%f underlinewidth=%f ascent=%f\n", rep->parameter.strikeout, rep->value.underlineposition, rep->value.underlinewidth, ascent);
#endif // }}}


        // line width at underlinewidth% of font size and horizscaling
        line_width = ((rep->value.underlinewidth / 100) * rep->font_size) * (rep->value.horizscaling / 100);

        HPDF_Page_SetLineWidth (DOC_CURRENT_PAGE (rep), line_width);

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("strikeoutwidth calced=%f\n", line_width);
        A4GL_debug ("strikeoutwidth calced=%f\n", line_width);
#endif // }}}

        // line position at ascent / 2 - underlineposition% of font size + textrise
        y_adjust = ((((ascent / 1000) / 2) + ((rep->value.underlineposition / 100))) * rep->font_size) + rep->value.textrise;

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("overlineposition y_adjust=%f\n", y_adjust);
        A4GL_debug ("overlineposition y_adjust=%f\n", y_adjust);
#endif // }}}

        HPDF_Page_MoveTo (DOC_CURRENT_PAGE (rep), x             , y + y_adjust);
        HPDF_Page_LineTo (DOC_CURRENT_PAGE (rep), x + text_width, y + y_adjust);
        HPDF_Page_Stroke (DOC_CURRENT_PAGE (rep));
    }
    // }}}

    // end line drawing if underline, overline or strikeout was required
    if (rep->parameter.underline ||
        rep->parameter.overline ||
        rep->parameter.strikeout)
        HPDF_Page_GRestore (DOC_CURRENT_PAGE (rep));

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("A4GL_pdf_show_text_internal x=%f y=%f text=%s\n", x, y, text);
    A4GL_debug ("A4GL_pdf_show_text_internal x=%f y=%f text=%s\n", x, y, text);
#endif // }}}

    // see if stroke will be applied to text
    if (rep->value.textrendering == 1 ||
        rep->value.textrendering == 2 ||
        rep->value.textrendering == 5 ||
        rep->value.textrendering == 6)
    {
        double          stroke_width;

        stroke_mode = 1;

        // save current stroke width
        stroke_width_orig = HPDF_Page_GetLineWidth (DOC_CURRENT_PAGE (rep));

        if (rep->value.strokewidth)
            // use strokewidth if provided
            stroke_width = rep->value.strokewidth;
        else
            // if strokewidth is 0 then default to 3% of font size and horizscaling% to match pdflib
            stroke_width = (rep->font_size * (rep->value.horizscaling / 100)) * (A4GL_DEFAULT_STROKEWIDTH / 100);

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("strokewidth=%f stroke_width=%f\n", rep->value.strokewidth, stroke_width);
    A4GL_debug ("strokewidth=%f stroke_width=%f\n", rep->value.strokewidth, stroke_width);
#endif // }}}

        HPDF_Page_SetLineWidth (DOC_CURRENT_PAGE (rep), stroke_width);
    }

    // we need to begin text mode to reset x and y to 0, 0
    begin_text_mode (rep);

    HPDF_Page_TextOut (DOC_CURRENT_PAGE (rep), x, y, text);
    HPDF_Page_EndText (DOC_CURRENT_PAGE (rep));

    if (stroke_mode)
        // restore original stroke width
        HPDF_Page_SetLineWidth (DOC_CURRENT_PAGE (rep), stroke_width_orig);

    return;
}
// }}}
// A4GL_pdf_suspend_page {{{
/**
 * Suspend current page
 *
 * @param rep  Pointer to pdf_rep_structure
 */
static void
A4GL_pdf_suspend_page (struct pdf_rep_structure *rep)
{

    if (rep->pages_suspended_count < rep->page_no)
    {

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("suspend page=%d\n", rep->current_page_no);
        A4GL_debug ("suspend page=%d\n", rep->current_page_no);
#endif // }}}

        // add current page to pages suspended array
        rep->pages_suspended_array = (struct pages_suspended_s **) acl_realloc (rep->pages_suspended_array, sizeof (struct pages_suspended_s *) * (rep->pages_suspended_count + 1));
        rep->pages_suspended_array[rep->pages_suspended_count] = (struct pages_suspended_s *) acl_malloc2 (sizeof (struct pages_suspended_s));

        rep->pages_suspended_array[rep->pages_suspended_count]->page_handle = DOC_CURRENT_PAGE (rep);

        rep->pages_suspended_array[rep->pages_suspended_count]->parameter.underline     = rep->parameter.underline;
        rep->pages_suspended_array[rep->pages_suspended_count]->parameter.overline      = rep->parameter.overline;
        rep->pages_suspended_array[rep->pages_suspended_count]->parameter.strikeout     = rep->parameter.strikeout;

        rep->pages_suspended_array[rep->pages_suspended_count]->value.horizscaling      = rep->value.horizscaling;
        rep->pages_suspended_array[rep->pages_suspended_count]->value.strokewidth       = rep->value.strokewidth;
        rep->pages_suspended_array[rep->pages_suspended_count]->value.textrendering     = rep->value.textrendering;
        rep->pages_suspended_array[rep->pages_suspended_count]->value.textrise          = rep->value.textrise;
        rep->pages_suspended_array[rep->pages_suspended_count]->value.underlineposition = rep->value.underlineposition;
        rep->pages_suspended_array[rep->pages_suspended_count]->value.underlinewidth    = rep->value.underlinewidth;

        rep->pages_suspended_count++;
    }

    rep->current_page_no = 0;

    return;
}
// }}}
// A4GL_pdf_text_width {{{
/**
 * Returns width of text string
 *
 * @param rep  Pointer to pdf_rep_structure
 * @param text Text to find width of
 *
 * @remarks
 * horizscaling calculation:
 * - pdflib includes it in PDF_stringwidth
 * - haru   does NOT include it in HPDF_Page_TextWidth
 */
static double
A4GL_pdf_text_width (struct pdf_rep_structure *rep, char *text)
{

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("A4GL_pdf_text_width text=%s\n", text);
    A4GL_debug ("A4GL_pdf_text_width text=%s\n", text);
#endif // }}}

    return HPDF_Page_TextWidth (DOC_CURRENT_PAGE (rep), text) * (rep->value.horizscaling / 100);
}
// }}}

// A4GLPDFREP_A4GL_pdf_aclfgli_skip_lines {{{
/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_aclfgli_skip_lines (void *vrep)
{
    long            a;
    struct pdf_rep_structure *rep;

    rep = (struct pdf_rep_structure *) vrep;

#ifdef DEBUG // {{{
    A4GL_debug ("skip lines");
#endif // }}}

    a = A4GL_pop_long ();

    rep->line_no += A4GL_pdf_metric (a, 'l', rep);
}
// }}}
// A4GLPDFREP_A4GL_pdf_blob_print {{{
/**
 *
 * @todo Describe function
 */

void
A4GLPDFREP_A4GL_pdf_blob_print (void *vrep, void *vblob, char *type, int cr)
{
    //int             n;
    double          sx;
    double          sy;
    int             x, y;
    double          ox;
    double          oy;
    struct pdf_rep_structure *rep;
    struct fgl_int_loc *blob;
    HPDF_Image      i;

    rep = (struct pdf_rep_structure *) vrep;

    blob = vblob;

    sx = A4GL_pop_double ();
    sy = A4GL_pop_double ();

#ifdef DEBUG // {{{
    A4GL_debug ("Scaling by %f %f", sx, sy);
#endif // }}}

    if (blob->where != 'F' && blob->where != 'M')
    {
        A4GL_exitwith ("Blob not located");
        return;
    }

    if (blob->where != 'F')
    {
        A4GL_exitwith ("Not implemented yet...\n");
        return;
    }

#ifdef DEBUG // {{{
    A4GL_debug ("Opening blob\n");
#endif // }}}

    i = NULL;

    if (A4GL_has_pointer (blob->filename, HARU_IMAGE))
        i = A4GL_find_pointer (blob->filename, HARU_IMAGE);

    if (i == NULL)
    {
        if (A4GL_aubit_strcasecmp (type, "PNG") == 0)
            i = HPDF_LoadPngImageFromFile (DOC (rep)->doc, blob->filename);

        if (A4GL_aubit_strcasecmp (type, "JPG") == 0 || A4GL_aubit_strcasecmp (type, "JPEG") == 0)
            i = HPDF_LoadJpegImageFromFile (DOC (rep)->doc, blob->filename);
    }

    if (i)
        A4GL_add_pointer (blob->filename, HARU_IMAGE, i);

#ifdef DEBUG // {{{
    A4GL_debug ("Image handle=%p\n", i);
#endif // }}}

    if (i == NULL)

        /* exitwith ("Unable to open file %s %s", type, blob->filename); */
        /* An empty blob or invalid type (bmp) is also error,
           so just ignore and continue */
        /* A4GL_exitwith ("Unable to open file."); */
        return;

    x = HPDF_Image_GetWidth (i);
    y = HPDF_Image_GetHeight (i);

    ox = (double) x;
    oy = (double) y;
    sy = sx;
    y = (int) ((double) y * sy);
    x = (int) ((double) x * sx);

// If it's just way to large to fit on the page - scale it back...
// this doesn't care if we're too far down the page etc - thats a different problem :-)
    while (y > (int) rep->page_length)
    {

#ifdef DEBUG // {{{
        A4GL_debug ("Too high %d %lf", y, rep->page_length);
#endif // }}}

        sx *= 0.99;
        sy *= 0.99;
        y = (int) (oy * sy);
        x = (int) (ox * sx);
    }

    while (x > (int) rep->page_width)
    {

#ifdef DEBUG // {{{
        A4GL_debug ("Too wide %d %lf", x, rep->page_width);
#endif // }}}
        sx *= 0.99;
        sy *= 0.99;
        y = (int) (oy * sy);
        x = (int) (ox * sx);
    }

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("Placing height of image =%d col=%f line=%f length=%f scale=%lf\n", y, rep->col_no, rep->line_no, rep->page_length, sx);
    A4GL_debug ("Placing height of image =%d col=%f line=%f length=%f scale=%lf\n", y, rep->col_no, rep->line_no, rep->page_length, sx);
#endif // }}}

    if (rep->col_no == 0)
        rep->col_no += rep->left_margin;

#ifdef DEBUG // {{{
    A4GL_debug ("x=%lf y=%lf", rep->col_no, rep->page_length - rep->line_no - y);
#endif // }}}

    select_gmode (DOC (rep), HPDF_GMODE_PAGE_DESCRIPTION);

    HPDF_Page_DrawImage (DOC_CURRENT_PAGE (rep), i, rep->col_no, rep->page_length - rep->line_no - y, HPDF_Image_GetWidth (i) * sx, HPDF_Image_GetHeight (i) * sy);

#ifdef DEBUG // {{{
    A4GL_debug ("Closing");
#endif // }}}

#ifdef DEBUG // {{{
    A4GL_debug ("lineno (%lf) +=  %lf", rep->line_no, (double) y);
    A4GL_debug ("colno (%lf) +=  %lf", rep->col_no, (double) x);
#endif // }}}

    rep->line_no = rep->line_no + (double) y;
    rep->col_no = rep->col_no + (double) x;

    A4GL_push_empty_char ();

    A4GL_pdf_rep_print (rep, 1, cr, 0, -1);

    return;
}
// }}}
// A4GLPDFREP_A4GL_pdf_image_print {{{
void
A4GLPDFREP_A4GL_pdf_image_print (void *vrep, char *type, int cr)
{
    //int n;
    double          sx;
    double          sy;
    int             x, y;
    double          ox;
    double          oy;
    char           *filename;
    struct pdf_rep_structure *rep;
    HPDF_Image      i;

    rep = (struct pdf_rep_structure *) vrep;

    filename = A4GL_char_pop ();
    A4GL_trim (filename);

    sx = A4GL_pop_double ();
    sy = A4GL_pop_double ();

#ifdef DEBUG // {{{
    A4GL_debug ("Scaling by %f %f", sx, sy);
#endif // }}}

#ifdef DEBUG // {{{
    A4GL_debug ("Opening blob\n");
#endif // }}}

    i = NULL;

    if (A4GL_has_pointer (filename, HARU_IMAGE))
        i = A4GL_find_pointer (filename, HARU_IMAGE);

    if (i == NULL)
    {
        if (A4GL_aubit_strcasecmp (type, "PNG") == 0)
            i = HPDF_LoadPngImageFromFile (DOC (rep)->doc, filename);

        if (A4GL_aubit_strcasecmp (type, "JPG") == 0 || A4GL_aubit_strcasecmp (type, "JPEG") == 0)
            i = HPDF_LoadJpegImageFromFile (DOC (rep)->doc, filename);
    }
    if (i)
        A4GL_add_pointer (filename, HARU_IMAGE, i);

#ifdef DEBUG // {{{
    A4GL_debug ("Image handle=%p\n", i);
#endif // }}}

    if (i == NULL)
        /* exitwith ("Unable to open file %s %s", type, blob->filename); */
        /* An empty blob or invalid type (bmp) is also error,
           so just ignore and continue */
        /* A4GL_exitwith ("Unable to open file."); */
        return;

    x = HPDF_Image_GetWidth (i);
    y = HPDF_Image_GetHeight (i);

    ox = (double) x;
    oy = (double) y;
    sy = sx;
    y = (int) ((double) y * sy);
    x = (int) ((double) x * sx);

// If its just way to large to fit on the page - scale it back...
// this doesn't care if we're too far down the page etc - thats a different problem :-)
    while (y > (int) rep->page_length)
    {

#ifdef DEBUG // {{{
        A4GL_debug ("Too high %d %lf", y, rep->page_length);
#endif // }}}

        sx *= 0.99;
        sy *= 0.99;
        y = (int) (oy * sy);
        x = (int) (ox * sx);
    }

    while (x > (int) rep->page_width)
    {

#ifdef DEBUG // {{{
        A4GL_debug ("Too wide %d %lf", x, rep->page_width);
#endif // }}}
        sx *= 0.99;
        sy *= 0.99;
        y = (int) (oy * sy);
        x = (int) (ox * sx);
    }

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("Placing height of image =%d col=%f line=%f length=%f scale=%lf\n", y, rep->col_no, rep->line_no, rep->page_length, sx);
    A4GL_debug ("Placing height of image =%d col=%f line=%f length=%f scale=%lf\n", y, rep->col_no, rep->line_no, rep->page_length, sx);
#endif // }}}

    if (rep->col_no == 0)
        rep->col_no += rep->left_margin;

#ifdef DEBUG // {{{
    A4GL_debug ("x=%lf y=%lf", rep->col_no, rep->page_length - rep->line_no - y);
#endif // }}}

    select_gmode (DOC (rep), HPDF_GMODE_PAGE_DESCRIPTION);

    HPDF_Page_DrawImage (DOC_CURRENT_PAGE (rep), i, rep->col_no, rep->page_length - rep->line_no - y, HPDF_Image_GetWidth (i) * sx, HPDF_Image_GetHeight (i) * sy);

#ifdef DEBUG // {{{
    A4GL_debug ("Closing");
#endif // }}}



#ifdef DEBUG // {{{
    A4GL_debug ("lineno (%lf) +=  %lf", rep->line_no, (double) y);
    A4GL_debug ("colno (%lf) +=  %lf", rep->col_no, (double) x);
#endif // }}}

    rep->line_no = rep->line_no + (double) y;
    rep->col_no = rep->col_no + (double) x;

    A4GL_push_empty_char ();

    A4GL_pdf_rep_print (rep, 1, cr, 0, -1);

    return;
}
// }}}
// A4GLPDFREP_A4GL_pdf_need_lines {{{
/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_need_lines (void *vrep)
{
    int             a;
    struct pdf_rep_structure *rep;

    rep = (struct pdf_rep_structure *) vrep;

#ifdef DEBUG // {{{
    A4GL_debug ("need lines");
#endif // }}}

    a = A4GL_pdf_metric (A4GL_pop_int (), 'l', rep);

    if (rep->line_no > (rep->page_length - rep->bottom_margin - a))
    {

#ifdef DEBUG // {{{
        A4GL_debug ("need forcing new page");
#endif // }}}

        A4GL_pdf_skip_top_of_page (rep, 2);
    }
}
// }}}
// A4GLPDFREP_A4GL_pdf_rep_close {{{
/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_rep_close (void *vrep)
{
    struct pdf_rep_structure *rep;
    int             i = 0;

    rep = (struct pdf_rep_structure *) vrep;

#ifdef DEBUG // {{{
    A4GL_debug ("Closing report %f\n", rep->line_no);
#endif // }}}

    if (rep->line_no != 0.0)
    {
        select_gmode (DOC (rep), HPDF_GMODE_PAGE_DESCRIPTION);

#ifdef DEBUG // {{{
        A4GL_debug ("A");
#endif // }}}

    }

    if (HPDF_SaveToFile (DOC (rep)->doc, rep->output_loc_str) != HPDF_OK)
    {
        A4GL_exitwith ("Error opening output\n");
        return;
    }

    // free any bookmark handles
    acl_free (rep->bookmarks);

    // free rep->fonts_loaded_array
    for (i = 0; i < rep->fonts_loaded_count; i++)
    {
        acl_free (rep->fonts_loaded_array[i]->font_name);
        acl_free (rep->fonts_loaded_array[i]->font_file);
        acl_free (rep->fonts_loaded_array[i]);
    }
    acl_free (rep->fonts_loaded_array);

    //free rep->pages_suspended_array
    for (i = 0; i < rep->pages_suspended_count; i++)
    {
        acl_free (rep->pages_suspended_array[i]);
    }
    acl_free (rep->pages_suspended_array);

    HPDF_Free (DOC (rep)->doc);

    acl_free (rep->pdf_ptr);

    rep->pdf_ptr = 0;

#ifdef DEBUG // {{{
    A4GL_debug ("All done...");
#endif // }}}

}
// }}}
// A4GLPDFREP_A4GL_pdf_rep_print {{{
/**
 *
 * a = number to pop
 * s = semi colon at the end
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_rep_print (void *vrep, int a, int s, int right_margin, int why)
{
    int    b;
    int    entry = 0;
    char   *str;
    struct pdf_rep_structure *rep;

    rep = (struct pdf_rep_structure *) vrep;

#ifdef DEBUG // {{{
    A4GL_debug ("In rep_print");
#endif // }}}

    if (right_margin != 0)
    {

#ifdef DEBUG // {{{
        A4GL_debug ("***** WARNING ***** wordwrap margin not implemented..");
#endif // }}}

    }

    if (rep->line_no == 0 && rep->page_no == 0)
    {
        if (rep->output_mode == 'C')
        {
            tmpnam (rep->output_loc_str);
            rep->output = fopen (rep->output_loc_str, "w");

            if (rep->output == 0)
            {
                A4GL_exitwith ("Could not open report output");
                return;
            }

        }
        else
        {
            if (rep->output_mode == 'F')
            {
                if (strcmp (rep->output_loc_str, "stdout") == 0)
                {
                    A4GL_push_empty_char ();
                    A4GL_push_int (-1);
                    A4GL_push_int (-1);
                    A4GL_display_at (1, 0);
                    rep->output = stdout;
                }
                else
                {
                    rep->pdf_ptr = acl_malloc2 (sizeof (Haru_doc));

                    DOC (rep)->doc = newdoc (rep);

#ifdef DEBUG // {{{
                    A4GL_debug ("Set info");
#endif // }}}

                    A4GLPDFREP_A4GL_pdf_set_info (rep->pdf_ptr, "A4GL");

                    A4GL_pdf_set_compression (rep, atoi (acl_getenv ("A4GL_PDF_COMPRESSION")));
                }
            }
            else
            {
                rep->output = popen (rep->output_loc_str, "w");

                if (rep->output == 0)
                {
                    A4GL_exitwith ("Could not open report output");
                    return;
                }
            }
        }
    }

    // We're just setting up...
    if (a < 0)
        return;

    if (a || s == 0 || rep->finishing || entry == -5)
    {
        if (rep->print_section == SECTION_NORMAL)
        {

//printf ("%lf %lf\n", rep->line_no,  rep->page_length -  A4GL_pdf_metric (rep->lines_in_trailer , 'l', rep)   - rep->bottom_margin);
            if (rep->line_no >= rep->page_length - A4GL_pdf_metric (rep->lines_in_trailer, 'l', rep) - rep->bottom_margin)
            {

//printf ("Here...\n");
                rep->print_section = SECTION_TRAILER;
                rep->report (0, REPORT_PAGETRAILER);    /* report.c:180: too many arguments to function */
                rep->print_section = SECTION_NORMAL;
            }

            if (rep->line_no > rep->page_length - rep->bottom_margin)
            {

#ifdef DEBUG // {{{
                A4GL_debug ("setting line_no=0");
#endif // }}}

                rep->line_no = 0;

                if (rep->lines_in_trailer)
                {

#ifdef DEBUG // {{{
                    A4GL_debug ("Calling rep_print");
#endif // }}}

                    A4GL_pdf_rep_print (rep, 0, 1, 0, -10);
                }
            }
        }
    }

    if (rep->line_no == 0 && !rep->finishing)
    {

#ifdef DEBUG // {{{
        A4GL_debug ("New page...");
#endif // }}}

        A4GL_pdf_new_page (rep);

#ifdef DEBUG // {{{
        A4GL_debug ("set line 1");
#endif // }}}

        rep->line_no = A4GL_pdf_metric (1, 'l', rep);

#ifdef DEBUG // {{{
        A4GL_debug ("Adding to page no...");
#endif // }}}

        rep->page_no++;
        rep->current_page_no = rep->page_no;

#ifdef DEBUG // {{{
        A4GL_debug ("Need page header");
#endif // }}}

        rep->print_section = SECTION_HEADER;
        A4GLPDFREP_A4GL_pdf_skip_by (rep, 0.0 - rep->top_margin);
        rep->report (0, REPORT_PAGEHEADER);
        rep->print_section = SECTION_NORMAL;

        if (a == 0)
            return;
    }

#ifdef DEBUG // {{{
    A4GL_debug ("Popping %d parameters", a);
#endif // }}}

    if (a > 0)
    {
        if (rep->col_no == 0)
            rep->col_no += rep->left_margin;

        for (b = 0; b < a; b++)
        {

#ifdef DEBUG // {{{
            A4GL_debug ("A\n");
#endif // }}}

            str = A4GL_report_char_pop ();

            A4GL_pdf_move (rep);

#ifdef DEBUG // {{{
            if (A4GL_PDF_DEBUG)
                printf ("Putting %s\n", str);
#endif // }}}

            A4GL_pdf_show_text_internal (rep, str);

#ifdef DEBUG // {{{
            A4GL_debug ("Adding %f to col_no\n", A4GL_pdf_metric (strlen (str), 'c', rep));
#endif // }}}

            rep->col_no += A4GL_pdf_metric (strlen (str), 'c', rep);
            acl_free (str);
        }

        A4GL_pdf_move (rep);
    }

#ifdef DEBUG // {{{
    A4GL_debug ("Newline : %d", s);
#endif // }}}

    if (s == 0)
    {

#ifdef DEBUG // {{{
        A4GL_debug ("B\n");
#endif // }}}

        A4GL_pdf_move (rep);

        rep->col_no = 0;

#ifdef DEBUG // {{{
        A4GL_debug ("CR lineno was %lf\n", rep->line_no);
#endif // }}}

        rep->line_no += A4GL_pdf_metric (1, 'l', rep);

#ifdef DEBUG // {{{
        A4GL_debug ("CR lineno now %lf\n", rep->line_no);
#endif // }}}

        if (rep->line_no > rep->page_length - rep->bottom_margin)
        {

#ifdef DEBUG // {{{
            A4GL_debug ("setting line_no=0 lineno=%lf page_length=%lf bottom_margin=%lf", rep->line_no, rep->page_length, rep->bottom_margin);
#endif // }}}

            rep->line_no = 0;
            A4GL_pdf_rep_print (rep, 0, 0, 0, -1);
        }
    }
    fflush (rep->output);

#ifdef DEBUG // {{{
    A4GL_debug ("Done\n");
#endif // }}}

    return;
}
// }}}
// A4GLPDFREP_A4GL_pdf_set_column {{{
/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_set_column (void *vrep)
{
    double          a;
    double          needn;
    double          req;
    struct pdf_rep_structure *rep;
    int             force_move;

    rep = (struct pdf_rep_structure *) vrep;

#ifdef DEBUG // {{{
    A4GL_debug ("Set column");
#endif // }}}

    A4GL_push_empty_char ();
    A4GL_pdf_rep_print (rep, 1, 1, 0, -2);

    req = (double) A4GL_pop_double ();

    force_move = 0;

    // PDG changed from < to <= as print column 0 inches, "blah" would indent by a charater width
    if (req <= 0)
        force_move = 1;

    a = A4GLPDFREP_A4GL_pdf_size (req, 'c', rep);

    if (rep->col_no == 0.0)
    {

#ifdef DEBUG // {{{
        A4GL_debug ("setcol");
#endif // }}}

        rep->col_no = A4GL_pdf_metric (1, 'c', rep);
    }

    needn = a - rep->col_no + rep->left_margin; /* -pdf_metric (1,'c', rep); */

    /* if (rep->col_no==pdf_metric (1,'c', rep)) needn+=pdf_metric (1,'c', rep); */

#ifdef DEBUG // {{{
    A4GL_debug ("needn=%ld", needn);
#endif // }}}

    if (needn > 0)
    {

        /* fputmanyc (rep->output,' ',(int)needn); */
        rep->col_no += needn;

#ifdef DEBUG // {{{
        A4GL_debug ("Colno increased by %d", needn);
#endif // }}}

    }
    else
    {
        if (force_move)
            rep->col_no = a + rep->left_margin;

#ifdef DEBUG // {{{
        A4GL_debug ("Already past that point");
#endif // }}}

    }

    A4GL_push_empty_char ();
    A4GL_pdf_move (rep);
}
// }}}
// A4GLPDFREP_A4GL_pdf_set_info {{{
/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_set_info (void *p, char *creator)
{
    Haru_doc       *pp;
    pp = (Haru_doc *) p;

    HPDF_SetInfoAttr (pp->doc, HPDF_INFO_CREATOR, creator);
    HPDF_SetInfoAttr (pp->doc, HPDF_INFO_AUTHOR, "Auto");
    HPDF_SetInfoAttr (pp->doc, HPDF_INFO_TITLE, "Auto");
}
// }}}
// A4GLPDFREP_A4GL_pdf_size {{{
/**
 *
 * @todo Describe function
 */
double
A4GLPDFREP_A4GL_pdf_size (double f, char c, void *vrep)
{
    int             size;
    struct pdf_rep_structure *rep;

    rep = (struct pdf_rep_structure *) vrep;

#ifdef DEBUG // {{{
    A4GL_debug ("pdf_size (%lf %c %p)", f, c, rep);
#endif // }}}

    if (f < 0)
    {

#ifdef DEBUG // {{{
        A4GL_debug ("Returning 0-%lf", f);
#endif // }}}
        // This is already in PDF units
        return 0 - f;
    }

    size = f;
    // This is in lines or chars
    return A4GL_pdf_metric (size, c, rep);
}
// }}}
// A4GLPDFREP_A4GL_pdf_skip_by {{{
/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_skip_by (void *vrep, double a)
{
    struct pdf_rep_structure *rep;

    rep = (struct pdf_rep_structure *) vrep;

#ifdef DEBUG // {{{
    A4GL_debug ("pdf_skip_by");
#endif // }}}

    a = A4GLPDFREP_A4GL_pdf_size (a, 'l', rep);
    rep->line_no += a;

#ifdef DEBUG // {{{
    A4GL_debug ("Done skip by line_no=%f", rep->line_no);
#endif // }}}

}
// }}}
// A4GLPDFREP_A4GL_pdf_skip_to {{{
/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_skip_to (void *vrep, double a)
{
    struct pdf_rep_structure *rep;

    rep = (struct pdf_rep_structure *) vrep;

#ifdef DEBUG // {{{
    A4GL_debug ("pdf_skip_to");
#endif // }}}

    a = A4GLPDFREP_A4GL_pdf_size (a, 'l', rep);

#ifdef DEBUG // {{{
    A4GL_debug ("setting line_no=%lf", a);
#endif // }}}

    rep->line_no = a;
    rep->col_no = 0;
}
// }}}
// A4GLPDFREP_A4GL_pdf_skip_top_of_page {{{
/**
 *
 * @todo Describe function
 */
void
A4GLPDFREP_A4GL_pdf_skip_top_of_page (void *vrep, int n)
{
    int             z;
    int             a;
    double          ad;
    struct pdf_rep_structure *rep;

    rep = (struct pdf_rep_structure *) vrep;

#ifdef DEBUG // {{{
    A4GL_debug ("pdf_skip_top_of_page");
#endif // }}}

//  a = rep->page_length - rep->line_no - rep->bottom_margin - rep->lines_in_trailer;
    a = rep->page_length - rep->line_no - rep->bottom_margin - A4GL_pdf_metric (rep->lines_in_trailer, 'l', rep);

//  ad = rep->page_length - rep->line_no - rep->bottom_margin - rep->lines_in_trailer;
    ad = rep->page_length - rep->bottom_margin - A4GL_pdf_metric (rep->lines_in_trailer, 'l', rep);

    if (n != 1 || rep->page_no)
    {
        if (rep->header)
            return;

        if (rep->line_no == 0)
            return;
    }

    //A4GLPDFREP_A4GL_pdf_skip_to (vrep,  ad+0);
    rep->line_no = ad;

    A4GL_pdf_rep_print (rep, 0, 0, 0, -5);

    if (a && 0)
    {
        //double b;

        for (z = 0; z < a; z++)
        {
            //b = rep->page_length - rep->line_no - rep->bottom_margin - rep->lines_in_trailer;

            A4GL_pdf_rep_print (rep, 0, 0, 0, -4);
        }

        A4GL_pdf_rep_print (rep, 0, 0, 0, -5);
    }
}
// }}}

// A4GLPDFREP_A4GL_pdf_pdffunc_internal - START {{{
int
A4GLPDFREP_A4GL_pdf_pdffunc_internal (void *vrep, char *fname, int nargs)
{
    struct pdf_rep_structure *rep;

    rep = (struct pdf_rep_structure *) vrep;

// }}}
//
// add_bookmark add_bookmark_no_ret bookmark {{{
/**
 * @verbatim add_bookmark (parent, text)

add_bookmark_no_ret
bookmark
@endverbatim
 *
 * Add a nested bookmark under parent, or a new top-level bookmark.
 *
 * @param parent      If parent contains a valid bookmark handle returned by a previous call to add_bookmark (), a new bookmark will be generated which is a subordinate of the given parent. In this way, arbitrarily nested bookmarks can be generated. If parent = 0 a new top-level bookmark will be generated. Not used with bookmark.
 * @param text        Contains the text of the bookmark. A practical limit of 32 characters for text is advised.
 *
 * @remarks
 * HARU: @n
 */
    if (strcmp (fname, "add_bookmark") == 0 ||
        strcmp (fname, "add_bookmark_no_ret") == 0 ||
        strcmp (fname, "bookmark") == 0)
    {
        char           *buf;
        int             a = 0;

        // A4GL_find_pointer method {{{
//      char            keyname[20];
        // }}}

        HPDF_Outline     parent;
        HPDF_Outline     outline;
        HPDF_Destination destination;

        if (strcmp (fname, "add_bookmark") == 0 ||
            strcmp (fname, "add_bookmark_no_ret") == 0)
            a = A4GL_pop_int ();

        buf = A4GL_char_pop ();

        // check if a parent handle index has been given
        if (a > 0)
        {
            parent = rep->bookmarks[a - 1];

            // A4GL_find_pointer method * NOT USED * {{{
//          sprintf (keyname, "%d", a);
//          remember to add 'b' as HARU_BOOKMARKS to libaubit file
//          parent = A4GL_find_pointer (keyname, 'b');
            // }}}

        }
        else
        {
            parent = NULL;
        }

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("args func=%s parent index=%d\n", fname, a);
        A4GL_debug ("args func=%s parent index=%d\n", fname, a);
#endif // }}}

        // check open mode hasn't already been selected
        if (!rep->openmode_used)
            HPDF_SetPageMode (DOC (rep)->doc, HPDF_PAGE_MODE_USE_OUTLINE);

        outline = HPDF_CreateOutline (DOC (rep)->doc, parent, buf, NULL);
        //QUERY - pdflib does not open by default. maybe add optional OPENED keyword to BOOKMARK
        HPDF_Outline_SetOpened (outline, HPDF_FALSE);

        destination = HPDF_Page_CreateDestination (DOC_CURRENT_PAGE (rep));
        //QUERY - is this needed as SetFit seems to be the default anyway?
//      HPDF_Destination_SetFit (destination);
        HPDF_Outline_SetDestination (outline, destination);

        rep->bookmarks_count++;

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("func=%s rep->bookmarks_count=%d\n", fname, rep->bookmarks_count);
        A4GL_debug ("func=%s rep->bookmarks_count=%d\n", fname, rep->bookmarks_count);
#endif // }}}

        // A4GL_find_pointer method * NOT USED * {{{
//      sprintf (keyname, "%d", rep->bookmarks_count);
//      A4GL_add_pointer (keyname, 'b', outline);
        // }}}

        rep->bookmarks = acl_realloc (rep->bookmarks, sizeof (rep->bookmarks[0]) * rep->bookmarks_count);
        rep->bookmarks[rep->bookmarks_count - 1] = outline;

        acl_free (buf);

        if (strcmp (fname, "add_bookmark_no_ret") == 0 ||
            strcmp (fname, "bookmark") == 0)
        {
            return 0;
        }
        else
        {
            A4GL_push_int (rep->bookmarks_count);
            return 1;
        }
    }
// }}}
// X add_table_cell {{{
    if (strcmp (fname, "add_table_cell") == 0)
    {

        A4GL_assertion (1, "add_table_cell not implemented for HARU");

        return 0;
    }
// }}}
// arc arcn {{{
/**
 * @verbatim arc (x, y, r, alpha, beta)

arc_top
arcn
arcn_top
@endverbatim
 *
 * Draw a counter clockwise(arc) or clockwise(arcn) circular arc segment.
 *
 * @param x,y         The coordinates of the center of the circular arc segment.
 * @param r           The radius of the circular arc segment. r must be positive.
 * @param alpha, beta The start and end angles of the circular arc segment in degrees. Angles are measured counterclockwise from the positive x axis.
 *
 * @remarks
 * HARU: @n
 * A4GL_HARU_CONVERT_TO_PDFLIB is defaulted to Y to be compatible with pdflib angle behaviour.
 * If this is set to N then the arc or arc_top function can be used and the HARU library will behave as normal by using positive y as 0 and measured clockwise.
 *
 */

    if (strcmp (fname, "arc") == 0 ||
        strcmp (fname, "arc_top") == 0 ||
        strcmp (fname, "arcn") == 0 ||
        strcmp (fname, "arcn_top") == 0)
    {
        double          x;
        double          y;
        double          r;
        double          alpha;
        double          beta;

        beta  = A4GL_pop_double ();
        alpha = A4GL_pop_double ();

        r = A4GL_pop_double ();
        y = A4GL_pop_double ();
        x = A4GL_pop_double ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("args func=%s x=%f y=%f r=%f alpha=%f beta=%f\n", fname, x, y, r, alpha, beta);
        A4GL_debug ("args func=%s x=%f y=%f r=%f alpha=%f beta=%f\n", fname, x, y, r, alpha, beta);
#endif // }}}

        if (strcmp (fname, "arc_top") == 0 ||
            strcmp (fname, "arcn_top") == 0)
            y = rep->page_length - y;

        // r must be positive
        if (r < 0) r = 0 - r;

        if (strcmp (fname, "arc") == 0 ||
            strcmp (fname, "arc_top") == 0)
        {
            // arc - counterclockwise
            A4GL_pdf_arc (rep, x, y, r, alpha, beta, -1);
        }
        else
        {
            // arcn - clockwise
            A4GL_pdf_arc (rep, x, y, r, alpha, beta,  1);
        }

        return 0;
    }
// }}}
// barcode barcode_no_text{{{
    if (strcmp (fname, "barcode") == 0 ||
        strcmp (fname, "barcode_no_text") == 0)
    {
        double          x, y, w, h;
        char           *str;
        int             show_text = 0;

        str = A4GL_char_pop ();
        h = A4GL_pop_double ();
        w = A4GL_pop_double ();

        // These should probably always be <0 - but we'll correct it anyway...
        if (w < 0) w = 0 - w;
        if (h < 0) h = 0 - h;

        y = A4GL_pop_double ();
        x = A4GL_pop_double ();
        y = y + h;

        if (strcmp (fname, "barcode") == 0)
            show_text = 1;

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("%s x=%f y=%f w=%f h=%f str=%s page_length=%f show_text=%d\n", fname, x, y, w, h, str, rep->page_length, show_text);
        A4GL_debug ("%s x=%f y=%f w=%f h=%f str=%s page_length=%f show_text=%d\n", fname, x, y, w, h, str, rep->page_length, show_text);
#endif // }}}

        generate_barcode (rep->pdf_ptr, x, y, w, h, str, rep->page_length, show_text);

        acl_free (str);

        return 0;
    }
// }}}
// barcode_type {{{
    if (strcmp (fname, "barcode_type") == 0)
    {
        char           *str;

        str = A4GL_char_pop ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("%s type=%s\n", fname, str);
        A4GL_debug ("%s type=%s\n", fname, str);
#endif // }}}

        set_barcode_type (str);

        acl_free (str);

        return 0;
    }
// }}}
// char_width {{{
    if (strcmp (fname, "char_width") == 0)
    {
        int             a;
        double          f1;

        f1 = A4GL_pop_double ();

        a = A4GLPDFREP_A4GL_pdf_size (f1, 'c', rep);

        A4GL_push_double (a);

        return 1;
    }
// }}}
// circle {{{
/**
 * @verbatim circle (x, y, r)

circle_top
@endverbatim
 *
 * Draw a circle.
 *
 * @param x, y The coordinates of the center of the circle.
 * @param r    The radius of the circle.
 *
 */

    if (strcmp (fname, "circle") == 0 || strcmp (fname, "circle_top") == 0)
    {
        double          x;
        double          y;
        double          r;

        r = A4GL_pop_double ();
        y = A4GL_pop_double ();
        x = A4GL_pop_double ();

        if (strcmp (fname, "circle_top") == 0)
            y = rep->page_length - y;

        // r must be positive
        if (r < 0) r = 0 - r;

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("%s x=%f y=%f r=%f\n", fname, x, y, r);
        A4GL_debug ("%s x=%f y=%f r=%f\n", fname, x, y, r);
#endif // }}}

        select_gmode (DOC (rep), HPDF_GMODE_PATH_OBJECT);

        HPDF_Page_Circle (DOC_CURRENT_PAGE (rep), x, y, r);

        return 0;
    }
// }}}
// clip {{{
/**
 * clip ()
 *
 * Use the current path as clipping path
 *
 */

    if (strcmp (fname, "clip") == 0)
    {

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("clip\n");
        A4GL_debug ("clip\n");
#endif // }}}

        select_gmode (DOC (rep), HPDF_GMODE_PATH_OBJECT);

        HPDF_Page_Clip (DOC_CURRENT_PAGE (rep));

        return 0;
    }
// }}}
// closepath close_path {{{
/**
 * closepath ()
 *
 * Close the current path.
 *
 */

    if (strcmp (fname, "closepath") == 0 ||
        strcmp (fname, "close_path") == 0)
    {

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("closepath\n");
        A4GL_debug ("closepath\n");
#endif // }}}

        select_gmode (DOC (rep), HPDF_GMODE_PATH_OBJECT);

        HPDF_Page_ClosePath (DOC_CURRENT_PAGE (rep));

        return 0;
    }
// }}}
// concat {{{
/**
 * concat (a, b, c, e, f)
 *
 * Apply a transformation matrix to the current coordinate system.
 *
 * a, b, c,     Elements of a transformation matrix.
 * d, e, f      The six values make up a matrix in the same way as in
 *              PostScript and PDF (see references). In order to avoid
 *              degenerate transformations, a*d must not be equal to b*c.
 *
 *   Notes from Adobe spec:
 *
 * - Translations are specified as [ 1 0 0 1 tx ty ],
 *   where tx and ty are the distances to translate the
 *   origin of the coordinate system in the horizontal
 *   and vertical dimensions, respectively.
 *
 * - Scaling is obtained by [ sx 0 0 sy 0 0 ].
 *   This scales the coordinates so that 1 unit in the
 *   horizontal and vertical dimensions of the new 
 *   coordinate system is the same size as sx and sy units,
 *   respectively, in the previous coordinate system.
 *
 * - Rotations are produced by [ cos A sin A -sin A cos A 0 0 ],
 *   which has the effect of rotating the coordinate system
 *   axes by an angle A counterclockwise.
 *
 * - Skew is specified by [ 1 tan A tan B 1 0 0 ],
 *   which skews the x axis by an angle A and the y axis by an angle B.
 *
 */

    if (strcmp (fname, "concat") == 0)
    {
        double          a;
        double          b;
        double          c;
        double          d;
        double          e;
        double          f;

        f = A4GL_pop_double ();
        e = A4GL_pop_double ();
        d = A4GL_pop_double ();
        c = A4GL_pop_double ();
        b = A4GL_pop_double ();
        a = A4GL_pop_double ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("concat a=%f b=%f c=%f d=%f e=%f f=%f\n", a, b, c, d, e, f);
        A4GL_debug ("concat a=%f b=%f c=%f d=%f e=%f f=%f",   a, b, c, d, e, f);
#endif // }}}

        select_gmode (DOC (rep), HPDF_GMODE_PAGE_DESCRIPTION);

        HPDF_Page_Concat (DOC_CURRENT_PAGE (rep), a, b, c, d, e, f);

        return 0;
    }
// }}}
// currpos curr_pos {{{
    if (strcmp (fname, "currpos") == 0 ||
        strcmp (fname, "curr_pos") == 0)
    {
        int             n;

        n = A4GL_pop_int ();

        if (n == 1)
        {
            A4GL_push_double (rep->col_no);
            return 1;
        }
        if (n == 2)
        {
            A4GL_push_double (rep->page_length - rep->line_no);
            return 1;
        }
        if (n == 3)
        {
            A4GL_push_double (rep->page_length - rep->line_no);
            A4GL_push_double (rep->col_no);
            return 2;
        }

        return 0;
    }
// }}}
// ellipse {{{
/**
 * ellipse (x, y, xr, yr)
 *
 * Draw an ellipse.
 *
 * x, y         The coordinates of the center of the ellipse.
 * xr           The x radius of the ellipse.
 * xy           The y radius of the ellipse.
 *
 */
    if (strcmp (fname, "ellipse") == 0 ||
        strcmp (fname, "ellipse_top") == 0)
    {
        double          x;
        double          y;
        double          xr;
        double          yr;

        // approximation of control point positions on a
        // bezier to simulate a quarter of a circle.
        // 4/3 * (1 - cos 45°) / sin 45° = 4/3 * (sqrt (2) - 1)
        // 4/3 * (sqrt (2) - 1) = 0.5522847498307933984022516322796
        float           bezier_cp_quarter = 0.552f;

        yr = A4GL_pop_double ();
        xr = A4GL_pop_double ();
        y = A4GL_pop_double ();
        x = A4GL_pop_double ();

        if (strcmp (fname, "ellipse_top") == 0)
            y = rep->page_length - y;

        // xr and xy must be positive
        if (xr < 0) xr = 0 - xr;
        if (yr < 0) yr = 0 - xr;

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("%s x=%f y=%f xr=%f yr=%f\n", fname, x, y, xr, yr);
        A4GL_debug ("%s x=%f y=%f xr=%f yr=%f\n", fname, x, y, xr, yr);
#endif // }}}

        select_gmode (DOC (rep), HPDF_GMODE_PATH_OBJECT);

        // haru has an ellipse function but we do it manually
        // to match pdflib which does not. (well, up to 7.0.5p3 anyway)
        // HPDF_Page_Ellipse (DOC_CURRENT_PAGE (rep), x, y, xr, yr);

        // move to 12 o'clock
        HPDF_Page_MoveTo (DOC_CURRENT_PAGE (rep), x, y + yr);

        // first quarter 12 - 3 o'clock
        HPDF_Page_CurveTo (DOC_CURRENT_PAGE (rep),
            x + (xr * bezier_cp_quarter), y + yr,
            x + xr                      , y + (yr * bezier_cp_quarter),
            x + xr                      , y
            );
        // second quarter 3 - 6 o'clock
        HPDF_Page_CurveTo (DOC_CURRENT_PAGE (rep),
            x + xr                      , y - (yr * bezier_cp_quarter),
            x + (xr * bezier_cp_quarter), y - yr,
            x                           , y - yr
            );
        // third quarter 6 - 9 o'clock
        HPDF_Page_CurveTo (DOC_CURRENT_PAGE (rep),
            x - (xr * bezier_cp_quarter), y - yr,
            x - xr                      , y - (yr * bezier_cp_quarter),
            x - xr                      , y
            );
        // forth quarter 9 - 12 o'clock
        HPDF_Page_CurveTo (DOC_CURRENT_PAGE (rep),
            x - xr                      , y + (yr * bezier_cp_quarter),
            x - (xr * bezier_cp_quarter), y + yr,
            x                           , y + yr
            );

        // move back to centre
        HPDF_Page_MoveTo (DOC_CURRENT_PAGE (rep), x, y);

        return 0;
    }
// }}}
// embedfont embed_font{{{
    if (strcmp (fname, "embedfont") == 0 ||
        strcmp (fname, "embed_font") == 0)
    {
        char     *font_name;

        font_name = A4GL_char_pop ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("%s font_name=%s\n", fname, font_name);
        A4GL_debug ("%s font_name=%s\n", fname, font_name);
#endif // }}}

        // setting font_embedded arg to 2 indicates just to load and embed the font, not set it as the current one
        A4GL_pdf_set_font_name (rep, font_name, 2);

        acl_free (font_name);

        return 0;
    }
// }}} 
// fill {{{
    if (strcmp (fname, "fill") == 0)
    {

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("fill\n");
        A4GL_debug ("fill");
#endif // }}}

        HPDF_Page_Fill (DOC_CURRENT_PAGE (rep));

        return 0;
    }
// }}}
// fill_stroke {{{
    if (strcmp (fname, "fill_stroke") == 0)
    {

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("fill_stroke\n");
        A4GL_debug ("fill_stroke");
#endif // }}}

        HPDF_Page_FillStroke (DOC_CURRENT_PAGE (rep));

        return 0;
    }
// }}}
// X fit_table {{{
    if (strcmp (fname, "fit_table") == 0)
    {
        A4GL_assertion (1, "Fit Table not implemented for HARU");

        return 0;
    }
// }}}
// X fit_textline {{{
    if (strcmp (fname, "fit_textline") == 0)
    {
        A4GL_assertion (1, "fit_textline not available in HARU");

        return 0;
    }
// }}}
// line_height {{{
    if (strcmp (fname, "line_height") == 0)
    {
        int             a;
        double          f1;

        f1 = A4GL_pop_double ();

        a = A4GLPDFREP_A4GL_pdf_size (f1, 'l', rep);

        A4GL_push_double (a);

        return 1;
    }
// }}}
// lineto line_to {{{
    if (strcmp (fname, "lineto") == 0 ||
        strcmp (fname, "line_to") == 0 ||
        strcmp (fname, "lineto_top") == 0 ||
        strcmp (fname, "line_to_top") == 0)
    {

        float           f1;
        float           f2;

        f2 = A4GL_pop_double ();
        f1 = A4GL_pop_double ();

        if (strcmp (fname, "lineto_top") == 0 ||
            strcmp (fname, "line_to_top") == 0)
            f2 = rep->page_length - f2;

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("%s x=%f y=%f\n", fname, f1, f2);
        A4GL_debug ("%s x=%f y=%f\n", fname, f1, f2);
#endif // }}}

        HPDF_Page_LineTo (DOC_CURRENT_PAGE (rep), f1, f2);

        return 0;
    }
// }}}
// moveto move_to {{{
    if (strcmp (fname, "moveto") == 0 ||
        strcmp (fname, "move_to") == 0 ||
        strcmp (fname, "moveto_top") == 0 ||
        strcmp (fname, "move_to_top") == 0)
    {
        float           f1;
        float           f2;

        f2 = A4GL_pop_double ();
        f1 = A4GL_pop_double ();

        if (strcmp (fname, "moveto_top") == 0 ||
            strcmp (fname, "move_to_top") == 0)
            f2 = rep->page_length - f2;

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("%s x=%f y=%f\n", fname, f1, f2);
        A4GL_debug ("%s x=%f y=%f\n", fname, f1, f2);
#endif // }}}

        select_gmode (DOC (rep), HPDF_GMODE_PATH_OBJECT);

        HPDF_Page_MoveTo (DOC_CURRENT_PAGE (rep), f1, f2);

        return 0;
    }
// }}}
// page_col_inches {{{
    if (strcmp (fname, "page_col_inches") == 0)
    {
        double          f1;

        f1 = A4GL_pop_double ();
        f1 *= 72.0;

        A4GL_push_double (rep->left_margin + f1);

        return 1;
    }
// }}}
// page_line {{{
// page_line (lineno), convert lineno to pdf metric, need -1 to align properly
    if (strcmp (fname, "page_line") == 0)
    {
        double          f1;

        f1 = A4GL_pop_double ();

        A4GL_push_double (rep->page_length - f1 - 1);

        return 1;
    }
// }}}
// page_line_inches {{{
    if (strcmp (fname, "page_line_inches") == 0)
    {
        double          f1;

        f1 = A4GL_pop_double ();
        f1 *= 72.0;

        A4GL_push_double (rep->page_length - f1);

        return 1;
    }
// }}}
// rect {{{
// rect (x, y, w, h);
    if (strcmp (fname, "rect") == 0 ||
        strcmp (fname, "rect_top") == 0)
    {
        float           fx, fy, fw, fh;

        int             rect_is_stroked = A4GL_isyes (acl_getenv ("A4GL_PDF_RECT_IS_STROKED"));

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("A4GL_PDF_RECT_IS_STROKED=%d\n", rect_is_stroked);
        A4GL_debug ("A4GL_PDF_RECT_IS_STROKED=%d\n", rect_is_stroked);
#endif // }}}

        fh = A4GL_pop_double ();
        fw = A4GL_pop_double ();
        fy = A4GL_pop_double ();
        fx = A4GL_pop_double ();

        if (strcmp (fname, "rect_top") == 0)
            fy = rep->page_length - fy;

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("args func=%s x=%f y=%f w=%f h=%f\n", fname, fx, fy, fw, fh);
        A4GL_debug ("args func=%s x=%f y=%f w=%f h=%f\n", fname, fx, fy, fw, fh);
#endif // }}}

        select_gmode (DOC (rep), HPDF_GMODE_PATH_OBJECT);

        HPDF_Page_Rectangle (DOC_CURRENT_PAGE (rep), fx, fy, fw, fh);

        if (rect_is_stroked)
            HPDF_Page_Stroke (DOC_CURRENT_PAGE(rep));

        return 0;
    }
// }}}
// rect_rounded {{{
/** 
 * rect_rounded (x, y, w, h, r, corners)
 *
 * Draws a rectangle with selectable rounded corners.
 *
 * x, y         The coordinates of the center of the circle.
 * w, h         The width and height of the rectangle.
 * r            The radius of the corners.
 * corners      Four character string representing which corners are to be rounded.
 *              0 = square, 1 = rounded. Order is Top Left, Top Right, Bottom Right, Bottom Left
 *
 */

    if (strcmp (fname, "rect_rounded") == 0 ||
        strcmp (fname, "rect_rounded_top") == 0)
    {
        double          x, y, w, h, r;
        char           *corners;

        if (nargs == 6)
            corners = A4GL_char_pop ();
        else
            corners = "1111";

        r = A4GL_pop_double ();
        h = A4GL_pop_double ();
        w = A4GL_pop_double ();
        y = A4GL_pop_double ();
        x = A4GL_pop_double ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("args func=%s x=%f y=%f w=%f h=%f r=%f corners=%s\n", fname, x, y, w, h, r, corners);
        A4GL_debug ("args func=%s x=%f y=%f w=%f h=%f r=%f corners=%s\n", fname, x, y, w, h, r, corners);
#endif // }}}

        if (strcmp (fname, "rect_rounded_top") == 0)
            y = rep->page_length - y;

        // r must be positive
        if (r < 0) r = 0 - r;

        select_gmode (DOC (rep), HPDF_GMODE_PATH_OBJECT);

        if (strcmp (corners, "0000") == 0 || r == 0)
        {
            // square corners only
            HPDF_Page_Rectangle (DOC_CURRENT_PAGE (rep), x, y, w, h);
        }
        else
        {
            // 1 or more rounded corners required

            // start at bottom left
            if (corners[3] == '1')
            {
                A4GL_pdf_arc (rep, x + r, y + r, r, 180, 270, -1);
            }
            else
            {
                HPDF_Page_MoveTo (DOC_CURRENT_PAGE (rep), x, y);
            }

            // bottom right
            if (corners[2] == '1')
            {
                HPDF_Page_LineTo (DOC_CURRENT_PAGE (rep), x + w - r, y);
                A4GL_pdf_arc (rep, x + w - r, y + r, r, 270, 360, -1);
            }
            else
            {
                HPDF_Page_LineTo (DOC_CURRENT_PAGE (rep), x + w, y);
            }

            // top right
            if (corners[1] == '1')
            {
                HPDF_Page_LineTo (DOC_CURRENT_PAGE (rep), x + w, y + h - r);
                A4GL_pdf_arc (rep, x + w - r, y + h - r, r, 0, 90, -1);
            }
            else
            {
                HPDF_Page_LineTo (DOC_CURRENT_PAGE (rep), x + w, y + h);
            }

            // top left
            if (corners[0] == '1')
            {
                HPDF_Page_LineTo (DOC_CURRENT_PAGE (rep), x + r, y + h);
                A4GL_pdf_arc (rep, x + r, y + h - r, r, 90, 180, -1);
            }
            else
            {
                HPDF_Page_LineTo (DOC_CURRENT_PAGE (rep), x, y + h);
            }

            // close the rectangle
            HPDF_Page_ClosePath (DOC_CURRENT_PAGE (rep));
        }

        if (nargs == 6)
            acl_free (corners);

        return 0;
    }
// }}}
// restore {{{
/**
 * restore ()
 *
 * Restore the current graphics state
 *
 */

    if (strcmp (fname, "restore") == 0)
    {

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("restore\n");
        A4GL_debug ("restore\n");
#endif // }}}

        select_gmode (DOC (rep), HPDF_GMODE_PAGE_DESCRIPTION);

        HPDF_Page_GRestore (DOC_CURRENT_PAGE (rep));

        return 0;
    }
// }}}
// resume_page {{{
/**
 * resume_page ()
 *
 * Resume a previously suspended page
 *
 */

    if (strcmp (fname, "resume_page") == 0)
    {
        int  page = 0;

        page = A4GL_pop_int ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("args %s page=%d\n", fname, page);
        A4GL_debug ("args %s page=%d\n", fname, page);
#endif // }}}

        if (page > 0 && page <= rep->page_no)
        {
            // suspend current page
            A4GL_pdf_suspend_page (rep);
            // resume required page
            A4GL_pdf_resume_page (rep, page);
        }

        return 0;
    }
// }}}
// rotate {{{
/**
 * rotate (alpha, x, y)
 *
 * Rotate
 *
 * alpha        Angle in degrees for rotation (counter-clockwise)
 * x, y         The coordinates of the centre of rotation
 *
 */

    if (strcmp (fname, "rotate") == 0)
    {
        double          alpha;
        double          x;
        double          y;

        double          rad_alpha,
                        cos_alpha,
                        sin_alpha;

        double          a, b, c, d, e, f;

        y = A4GL_pop_double ();
        x = A4GL_pop_double ();
        alpha = A4GL_pop_double ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("rotate alpha=%f x=%f y=%f\n", alpha, x, y);
        A4GL_debug ("rotate alpha=%f x=%f y=%f\n", alpha, x, y);
#endif // }}}

        rad_alpha = alpha * A4GL_DEG2RAD;

        cos_alpha = cos (rad_alpha);
        sin_alpha = sin (rad_alpha);

        a = cos_alpha;
        b = sin_alpha;
        c = -sin_alpha;
        d = cos_alpha;
        e = x + (sin_alpha * y) - (cos_alpha * x);
        f = y - (cos_alpha * y) - (sin_alpha * x);

        select_gmode (DOC (rep), HPDF_GMODE_PAGE_DESCRIPTION);

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("rotate a=%f b=%f c=%f d=%f e=%f f=%f\n", a, b, c, d, e, f);
        A4GL_debug ("rotate a=%f b=%f c=%f d=%f e=%f f=%f\n", a, b, c, d, e, f);
#endif // }}}

        HPDF_Page_Concat (DOC_CURRENT_PAGE (rep), a, b, c, d, e, f);

        return 0;
    }
// }}}
// save {{{
/**
 * save ()
 *
 * Save the current graphics state
 *
 */

    if (strcmp (fname, "save") == 0 )
    {

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("save\n");
        A4GL_debug ("save\n");
#endif // }}}

        select_gmode (DOC (rep), HPDF_GMODE_PAGE_DESCRIPTION);

        HPDF_Page_GSave (DOC_CURRENT_PAGE (rep));

        return 0;
    }
// }}}
// scale {{{
/**
 * scale (sx, sy)
 *
 * Scale the coordinate system.
 *
 * sx, sy       Scaling factors in x and y direction.
 *
 * This function scales the coordinate system by sx and sy. It may also be
 * used for achieving a reflection (mirroring) by using a negative scaling
 * factor. One unit in the x direction in the new coordinate system equals
 * sx units in the x direction in the old coordinate system; analogous for
 * y coordinates.
 *
 */

    if (strcmp (fname, "scale") == 0)
    {
        double          sx;
        double          sy;

        double          a, b, c, d, e, f;

        sy = A4GL_pop_double ();
        sx = A4GL_pop_double ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("scale sx=%f sy=%f\n", sx, sy);
        A4GL_debug ("scale sx=%f sy=%f\n", sx, sy);
#endif // }}}

        a = sx;
        b = 0;
        c = 0;
        d = sy;
        e = 0;
        f = 0;

        select_gmode (DOC (rep), HPDF_GMODE_PAGE_DESCRIPTION);

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("scale a=%f b=%f c=%f d=%f e=%f f=%f\n", a, b, c, d, e, f);
        A4GL_debug ("scale a=%f b=%f c=%f d=%f e=%f f=%f",   a, b, c, d, e, f);
#endif // }}}

        HPDF_Page_Concat (DOC_CURRENT_PAGE (rep), a, b, c, d, e, f);

        return 0;
    }
// }}}
// set_font_size {{{

    if (strcmp (fname, "set_font_size") == 0)
    {
        double font_size;

        font_size = A4GL_pop_double ();

        rep->font_size = font_size;

        HPDF_Page_SetFontAndSize (DOC_CURRENT_PAGE (rep), rep->fontptr, rep->font_size);

        return 0;
    }
// }}}
// set_font_name {{{
    if (strcmp (fname, "set_font_name") == 0)
    {
        char     *font_name;
        int       font_embedded = 0;

        if (nargs == 2)
            font_embedded = A4GL_pop_int ();

        font_name = A4GL_char_pop ();

        A4GL_pdf_set_font_name (rep, font_name, font_embedded);

        acl_free (font_name);

        return 0;
    }
// }}}
// set_info {{{
/**
 * set_info (key, value)
 *
 * Fill document information field key with value.
 *
 * key          (Name string) The name of the document info field, which may be any of the standard
 *              names, or an arbitrary custom name (see Table 12.1). There is no limit for the number
 *              of custom fields. Regarding the use and semantics of custom document information
 *              fields, PDFlib users are encouraged to take a look at the Dublin Core Metadata element
 *              set.1
 *
 * value        (Hypertext string) The string to which the key parameter will be set. Acrobat imposes
 *              a maximum length of value of 255 bytes. Note that due to a bug in Adobe Reader 6
 *              for Windows the & character does not display properly in some info strings.
 *
 * key                      explanation
 * Subject                  Subject of the document
 * Title                    Title of the document
 * Creator                  Software used to create the document (as opposed to the Producer of the PDF output,
 *                          which is always PDFlib). Acrobat will display this entry as Application.
 * Author                   Author of the document
 * Keywords                 Keywords describing the contents of the document
 * Trapped                  Indicates whether trapping has been applied to the document. Allowed values are
 *                          True, False, and Unknown. In PDF/X mode Unknown is not allowed.
 * Producer                 Producer of the document
 *
 */

    if (strcmp (fname, "set_info") == 0)
    {
        char           *key;
        char           *value;



        value = A4GL_char_pop ();
        key = A4GL_char_pop ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("set_info key=%s value=%s\n", key, value);
        A4GL_debug ("set_info key=%s value=%s\n", key, value);
#endif // }}}

        // haru only allows the following keys
        if (strcmp (key, "subject") == 0 ||
            strcmp (key, "Subject") == 0)
            HPDF_SetInfoAttr (DOC (rep)->doc, HPDF_INFO_SUBJECT, value);

        if (strcmp (key, "title") == 0 ||
            strcmp (key, "Title") == 0)
            HPDF_SetInfoAttr (DOC (rep)->doc, HPDF_INFO_TITLE, value);

        if (strcmp (key, "creator") == 0 ||
            strcmp (key, "Creator") == 0)
            HPDF_SetInfoAttr (DOC (rep)->doc, HPDF_INFO_CREATOR, value);

        if (strcmp (key, "author") == 0 ||
            strcmp (key, "Author") == 0)
            HPDF_SetInfoAttr (DOC (rep)->doc, HPDF_INFO_AUTHOR, value);

        if (strcmp (key, "keywords") == 0 ||
            strcmp (key, "Keywords") == 0)
            HPDF_SetInfoAttr (DOC (rep)->doc, HPDF_INFO_KEYWORDS, value);

#ifdef HPDF_INFO_TRAPPED
        if (strcmp (key, "trapped") == 0 ||
            strcmp (key, "Trapped") == 0)
            HPDF_SetInfoAttr (DOC (rep)->doc, HPDF_INFO_TRAPPED, value);
#endif

        if (strcmp (key, "producer") == 0 ||
            strcmp (key, "Producer") == 0)
            HPDF_SetInfoAttr (DOC (rep)->doc, HPDF_INFO_PRODUCER, value);

        acl_free (key);
        acl_free (value);

        return 0;
    }
// }}}
// set_parameter {{{
    if (strcmp (fname, "set_parameter") == 0)
    {
        char           *parameter;
        char           *value;

        value = A4GL_char_pop ();
        parameter = A4GL_char_pop ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("%s parameter=%s value=%s\n", fname, parameter, value);
        A4GL_debug ("%s parameter=%s value=%s\n", fname, parameter, value);
#endif // }}}

        if (strcmp (parameter, "openmode") == 0)
        {
            HPDF_PageMode mode = HPDF_PAGE_MODE_EOF;

            if (strcmp (value, "none") == 0)
               mode = HPDF_PAGE_MODE_USE_NONE; 

            if (strcmp (value, "bookmarks") == 0)
               mode = HPDF_PAGE_MODE_USE_OUTLINE; 

            if (strcmp (value, "thumbnails") == 0)
               mode = HPDF_PAGE_MODE_USE_THUMBS; 

            if (strcmp (value, "fullscreen") == 0)
               mode = HPDF_PAGE_MODE_FULL_SCREEN; 

            if (mode != HPDF_PAGE_MODE_EOF)
            {
                rep->openmode_used = 1;

                HPDF_SetPageMode (DOC (rep)->doc, mode);
            }
        }

        if (strcmp (parameter, "underline") == 0)
        {
            if (strcmp (value, "true") == 0)
               rep->parameter.underline = 1; 

            if (strcmp (value, "false") == 0)
               rep->parameter.underline = 0; 
        }

        if (strcmp (parameter, "overline") == 0)
        {
            if (strcmp (value, "true") == 0)
               rep->parameter.overline = 1; 

            if (strcmp (value, "false") == 0)
               rep->parameter.overline = 0; 
        }

        if (strcmp (parameter, "strikeout") == 0)
        {
            if (strcmp (value, "true") == 0)
               rep->parameter.strikeout = 1; 

            if (strcmp (value, "false") == 0)
               rep->parameter.strikeout = 0; 
        }



        acl_free (parameter);
        acl_free (value);

        return 0;
    }
// }}}
// X set_text_format {{{
// pdflib parameter:
// (Only for non Unicode-compatible language bindings) The format in which the text output functions will
// expect the client-supplied strings. Possible values are bytes, utf8, ebcdicutf8 (only on iSeries and
// zSeries), utf16, utf16le, utf16be, and auto. Default: auto. Scope: any
    if (strcmp (fname, "set_text_format") == 0)
    {
        //FIXME - allow this? as 4gl has keywords SET TEXT FORMAT
        //A4GL_assertion (1, "set_text_format not available in HARU");

        return 0;
    }
// }}}
// set_value {{{
    if (strcmp (fname, "set_value") == 0)
    {
        char           *key;
        double          value;

        value = A4GL_pop_double ();

        key = A4GL_char_pop ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("%s key=%s value=%f\n", fname, key, value);
        A4GL_debug ("%s key=%s value=%f\n", fname, key, value);
#endif // }}}

        if (strcmp (key, "compress") == 0)
        {
            A4GL_pdf_set_compression (rep, value);
        }

        if (strcmp (key, "horizscaling") == 0)
        {
            rep->value.horizscaling = value; 
            HPDF_Page_SetHorizontalScalling (DOC_CURRENT_PAGE (rep), value);
        }

        if (strcmp (key, "strokewidth") == 0)
        {
            rep->value.strokewidth = value; 
        }

        if (strcmp (key, "textrendering") == 0)
        {
            rep->value.textrendering = value; 

            HPDF_TextRenderingMode mode = HPDF_RENDERING_MODE_EOF;

            switch ((int) value)
            {
                case 0: mode = HPDF_FILL;                 break;
                case 1: mode = HPDF_STROKE;               break;
                case 2: mode = HPDF_FILL_THEN_STROKE;     break;
                case 3: mode = HPDF_INVISIBLE;            break;
                case 4: mode = HPDF_FILL_CLIPPING;        break;
                case 5: mode = HPDF_STROKE_CLIPPING;      break;
                case 6: mode = HPDF_FILL_STROKE_CLIPPING; break;
                case 7: mode = HPDF_CLIPPING;             break;
            }

            if (mode != HPDF_RENDERING_MODE_EOF)
                HPDF_Page_SetTextRenderingMode (DOC_CURRENT_PAGE (rep), mode);
        }

        if (strcmp (key, "textrise") == 0)
        {
            rep->value.textrise = value; 
            HPDF_Page_SetTextRise (DOC_CURRENT_PAGE (rep), value);
        }

        if (strcmp (key, "underlineposition") == 0)
            rep->value.underlineposition = value; 

        if (strcmp (key, "underlinewidth") == 0)
            rep->value.underlinewidth = value; 



        acl_free (key);

        return 0;
    }
// }}}
// setcolor set_color {{{
    if (strcmp (fname, "setcolor") == 0 ||
        strcmp (fname, "set_color") == 0)
    {
        float           f1;
        float           f2;
        float           f3;

        f3 = A4GL_pop_double ();
        f2 = A4GL_pop_double ();
        f1 = A4GL_pop_double ();

        A4GL_pdf_set_color (rep, "both", "rgb", f1, f2, f3, 0);

        return 0;
    }
// }}}
// setdash set_dash {{{
/**
 * setdash (b, w, p)
 *
 * Set the current dash pattern.
 * 
 * b, w         The number of alternating black and white units. b and w must be non-negative numbers.
 * p            Optional phase value.
 *
 */

    if (strcmp (fname, "setdash") == 0 ||
        strcmp (fname, "set_dash") == 0)
    {
        double          black;
        double          white;
        double          phase = 0;

        HPDF_UINT16     dash_mode[2];

        if (nargs == 3)
            phase = A4GL_pop_double ();

        white = A4GL_pop_double ();
        black = A4GL_pop_double ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("args func=%s b=%f w=%f p=%f\n", fname, black, white, phase);
        A4GL_debug ("args func=%s b=%f w=%f p=%f\n", fname, black, white, phase);
#endif // }}}

        // must be positive
        if (black < 0) black = 0 - black;
        if (white < 0) white = 0 - white;

        // black = 0 and white = 0 in pdflib resets to solid stroke
        if (black == 0 && white == 0)
        {
            black = 1;
            white = 1;
        }

        dash_mode[0] = black;
        dash_mode[1] = white;

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("setdash black=%f white=%f phase=%f\n", black, white, phase);
        A4GL_debug ("setdash black=%f white=%f phase=%f\n", black, white, phase);
#endif // }}}

        HPDF_Page_SetDash (DOC_CURRENT_PAGE (rep), dash_mode, 2, phase);

        return 0;
    }
// }}}
// setdashpattern {{{
/**
 * setdashpattern (b1, w1, b2, w2, b3, w3, b4, w4, p)
 *
 * Set the current dash pattern.
 * 
 * b1-4, w1-4   The number of alternating black and white units. b1-4 and w1-4 must be non-negative numbers. Must be at least 2 values. 0 = not used.
 * p            Optional phase value.
 *
 */

    if (strcmp (fname, "setdashpattern") == 0 ||
        strcmp (fname, "set_dash_pattern") == 0)
    {
        double          black1, black2, black3, black4;
        double          white1, white2, white3, white4;
        double          phase = 0;

        HPDF_UINT16     dash_mode[8];
        int             item_count;

        if (nargs == 9)
            phase = A4GL_pop_double ();

        white4 = A4GL_pop_double ();
        black4 = A4GL_pop_double ();
        white3 = A4GL_pop_double ();
        black3 = A4GL_pop_double ();
        white2 = A4GL_pop_double ();
        black2 = A4GL_pop_double ();
        white1 = A4GL_pop_double ();
        black1 = A4GL_pop_double ();

        // must be positive
        if (black1 < 0) black1 = 0 - black1;
        if (white1 < 0) white1 = 0 - white1;
        if (black2 < 0) black2 = 0 - black2;
        if (white2 < 0) white2 = 0 - white2;
        if (black3 < 0) black3 = 0 - black3;
        if (white3 < 0) white3 = 0 - white3;
        if (black4 < 0) black4 = 0 - black4;
        if (white4 < 0) white4 = 0 - white4;

        // must have at least 2 values
        item_count = 0;
        dash_mode[0] = black1;
        item_count++;
        dash_mode[1] = white1;
        item_count++;

        while (1 == 1)
        {
            if (black2 > 0) { dash_mode[2] = black2; item_count++; } else { break; }
            if (white2 > 0) { dash_mode[3] = white2; item_count++; } else { break; }
            if (black3 > 0) { dash_mode[4] = black3; item_count++; } else { break; }
            if (white3 > 0) { dash_mode[5] = white3; item_count++; } else { break; }
            if (black4 > 0) { dash_mode[6] = black4; item_count++; } else { break; }
            if (white4 > 0) { dash_mode[7] = white4; item_count++; } else { break; }
            break;
        }

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("setdashpattern black1=%f white1=%f black2=%f white2=%f black3=%f white3=%f black4=%f white4=%f phase=%f\n", black1, white1, black2, white2, black3, white3, black4, white4, phase);
        A4GL_debug ("setdashpattern black1=%f white1=%f black2=%f white2=%f black3=%f white3=%f black4=%f white4=%f phase=%f", black1, white1, black2, white2, black3, white3, black4, white4, phase);
#endif // }}}

        HPDF_Page_SetDash (DOC_CURRENT_PAGE (rep), dash_mode, item_count, phase);

        return 0;
    }
// }}}
// setfillcolor set_fill_color {{{
    if (strcmp (fname, "setfillcolor") == 0 ||
        strcmp (fname, "set_fill_color") == 0)
    {
        float           f1;
        float           f2;
        float           f3;

        f3 = A4GL_pop_double ();
        f2 = A4GL_pop_double ();
        f1 = A4GL_pop_double ();

        A4GL_pdf_set_color (rep, "fill", "rgb", f1, f2, f3, 0);

        return 0;
    }
// }}}
// setlinecap set_line_cap {{{
/**
 * setlinecap (linecap)
 *
 * Set the linecap parameter.
 *
 * linecap      Controls the shape at the end of a path with respect to stroking.
 *
 * 0 = Butt end caps
 * 1 = Round end caps
 * 2 = Projecting square end caps
 *
 */

    if (strcmp (fname, "setlinecap") == 0 ||
        strcmp (fname, "set_line_cap") == 0)
    {
        int             a;

        a = A4GL_pop_int ();

        // a must be 0, 1 or 2, if not set it to default
        if (a != 0 && a != 1 && a != 2)
            a = 0;

        // SCUARE is not a spelling mistake!
        switch (a)
        {
            case 0:
                a = HPDF_BUTT_END;
                break;
            case 1:
                a = HPDF_ROUND_END;
                break;
            case 2:
                a = HPDF_PROJECTING_SCUARE_END;
                break;
        }

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("setlinecap=%d\n", a);
        A4GL_debug ("setlinecap=%d\n", a);
#endif // }}}

        HPDF_Page_SetLineCap (DOC_CURRENT_PAGE (rep), a);

        return 0;
    }
// }}}
// setlinejoin set_line_join {{{
/**
 * setlinejoin (linejoin)
 *
 * Set the linejoin style.
 *
 * linejoin     Specifies the shape at the corners of paths that are stroked.
 *
 * 0 = Mitre joins
 * 1 = Round joins
 * 2 = Bevel joins
 *
 */

    if (strcmp (fname, "setlinejoin") == 0 ||
        strcmp (fname, "set_line_join") == 0)
    {
        int             a;

        a = A4GL_pop_int ();

        // a must be 0, 1 or 2, if not set it to default
        if (a != 0 && a != 1 && a != 2)
            a = 0;

        switch (a)
        {
            case 0:
                a = HPDF_MITER_JOIN;
                break;
            case 1:
                a = HPDF_ROUND_JOIN;
                break;
            case 2:
                a = HPDF_BEVEL_JOIN;
                break;
        }

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("setlinejoin=%d\n", a);
        A4GL_debug ("setlinejoin=%d\n", a);
#endif // }}}

        HPDF_Page_SetLineJoin (DOC_CURRENT_PAGE (rep), a);

        return 0;
    }
// }}}
// setlinewidth set_line_width {{{
/**
 * setlinewidth (width)
 *
 * Set the current line width.
 * 
 * width        The line width in units of the current user coordinate system.
 *
 */

    if (strcmp (fname, "setlinewidth") == 0 ||
        strcmp (fname, "set_line_width") == 0)
    {
        double d;

        d  = A4GL_pop_double ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("setlinewidth=%f\n", d);
        A4GL_debug ("setlinewidth=%f\n", d);
#endif // }}}

        HPDF_Page_SetLineWidth (DOC_CURRENT_PAGE (rep), d);

        return 0;
    }
// }}}
// setstrokecolor set_stroke_color {{{
    if (strcmp (fname, "setstrokecolor") == 0 ||
        strcmp (fname, "set_stroke_color") == 0)
    {
        float           f1;
        float           f2;
        float           f3;

        f3 = A4GL_pop_double ();
        f2 = A4GL_pop_double ();
        f1 = A4GL_pop_double ();

        A4GL_pdf_set_color (rep, "stroke", "rgb", f1, f2, f3, 0);

        return 0;
    }
// }}}
// show_boxed {{{
// show_boxed (text, x, y, w, h, mode, feature) returning rc;
// mode=(left, right, center, justify, fulljustify);
// if w=h=0, x, y is anchor point for left, right, center single line formatting
// feature=blind used for testing if text fit. rc is no of chars not fit.

    if (strcmp (fname, "show_boxed") == 0 ||
        strcmp (fname, "show_boxed_top") == 0)
    {
        float           fx, fy, fw, fh;
        char           *text, *mode, *feature;
        HPDF_UINT       c = 0;
        HPDF_TextAlignment align;

        if (nargs == 7)
        {
            feature = A4GL_char_pop ();
            if (strcmp (feature, "blind") != 0)
            {
                acl_free (feature);
                feature = "";
            }
        }
        else
            feature = "";

        mode = A4GL_char_pop ();

        fh = A4GL_pop_double ();
        fw = A4GL_pop_double ();
        fy = A4GL_pop_double ();
        fx = A4GL_pop_double ();

        text = A4GL_char_pop ();

        if (strcmp (fname, "show_boxed_top") == 0)
            fy = rep->page_length - fy;

        if (strcmp (mode, "left") != 0 &&
            strcmp (mode, "right") != 0 &&
            strcmp (mode, "center") != 0 &&
            strcmp (mode, "justify") != 0 &&
            strcmp (mode, "fulljustify") != 0)
            mode = "justify";

        if (strcmp (mode, "left") == 0)
            align = HPDF_TALIGN_LEFT;
        if (strcmp (mode, "right") == 0)
            align = HPDF_TALIGN_RIGHT;
        if (strcmp (mode, "center") == 0)
            align = HPDF_TALIGN_CENTER;
        // fulljustify not available in haru
        if (strcmp (mode, "justify") == 0 ||
            strcmp (mode, "fulljustify") == 0)
            align = HPDF_TALIGN_JUSTIFY;

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("%s x=%f y=%f w=%f h=%f text=%s mode=%s feature=%s\n", fname, fx, fy, fw, fh, text, mode, feature);
        A4GL_debug ("%s x=%f y=%f w=%f h=%f text=%s mode=%s feature=%s\n", fname, fx, fy, fw, fh, text, mode, feature);
#endif // }}}

        if (fw == 0 && fh == 0)
        {
            // if w=h=0, x, y is anchor point for left, right, center single line formatting
            A4GL_pdf_position_aligned_text (rep, fx, fy, text, mode);
            A4GL_pdf_show_text_internal (rep, text);
        }
        else
        {
            begin_text_mode (rep);

            // multi line box
            HPDF_Page_TextRect (DOC_CURRENT_PAGE (rep), fx, fy + fh, fx + fw, fy, text, align, &c);

            // needed this otherwise coordinate system seemed to be screwed up
            select_gmode (DOC (rep), HPDF_GMODE_PAGE_DESCRIPTION);

            // QUERY - utf8. check for wide chars?
            // number of chars not fitted
            c = strlen (text) - c;

            //printf ("show_boxed c=%d\n", c);
        }

        A4GL_push_double ((double) c);

        acl_free (text);
        acl_free (mode);

        if (strcmp (feature, "blind") == 0)
            acl_free (feature);

        return 1;
    }
// }}}
// show_text_pos {{{
    if (strcmp (fname, "show_text_pos") == 0 ||
        strcmp (fname, "show_text_pos_top") == 0)
    {
        float           fx, fy;
        char           *text;

        text = A4GL_char_pop ();
        fy = A4GL_pop_double ();
        fx = A4GL_pop_double ();

        if (strcmp (fname, "set_text_pos_top") == 0)
            fy = rep->page_length - fy;

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("%s x=%f y=%f text=%s\n", fname, fx, fy, text);
        A4GL_debug ("%s x=%f y=%f text=%s\n", fname, fx, fy, text);
#endif // }}}

        // we need to begin text mode to reset x and y to 0, 0
        begin_text_mode (rep);

        HPDF_Page_MoveTextPos (DOC_CURRENT_PAGE (rep), fx, fy);
        A4GL_pdf_show_text_internal (rep, text);

        acl_free (text);

        return 0;
    }
// }}}
// skew {{{
/**
 * skew (alpha, beta, x, y)
 *
 * Skew the coordinate system.
 *
 * alpha, beta  Skewing angles in x and y direction in degrees. 
 * x, y         The coordinates of the centre of skewing
 *
 * Skewing (or shearing) distorts the coordinate system by the given angles
 * in x and y direction. alpha is measured counterclockwise from the positive
 * x axis of the current coordinate system, beta is measured clockwise from
 * the positive y axis. Both angles must be in the range -360. < alpha,
 * beta < 360, and must be different from -270, -90, 90, and 270.
 *
 */

    if (strcmp (fname, "skew") == 0)
    {
        double          alpha;
        double          beta;
        double          x;
        double          y;

        double          a, b, c, d, e, f;

        y = A4GL_pop_double ();
        x = A4GL_pop_double ();
        beta = A4GL_pop_double ();
        alpha = A4GL_pop_double ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("skew alpha=%f beta=%f x=%f y=%f\n", alpha, beta, x, y);
        A4GL_debug ("skew alpha=%f beta=%f x=%f y=%f\n", alpha, beta, x, y);
#endif // }}}

        a = 1;
        b = tan (alpha * A4GL_DEG2RAD);
        c = tan (beta  * A4GL_DEG2RAD);
        d = 1;
        e = -c * y;
        f = -b * x;

        select_gmode (DOC (rep), HPDF_GMODE_PAGE_DESCRIPTION);

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("skew a=%f b=%f c=%f d=%f e=%f f=%f\n", a, b, c, d, e, f);
        A4GL_debug ("skew a=%f b=%f c=%f d=%f e=%f f=%f\n", a, b, c, d, e, f);
#endif // }}}

        HPDF_Page_Concat (DOC_CURRENT_PAGE (rep), a, b, c, d, e, f);

        return 0;
    }
// }}}
// skip_to {{{
// skip_to (lineno), need +1 to get to current line_no ???
    if (strcmp (fname, "skip_to") == 0)
    {
        double          f1;

        f1 = A4GL_pop_double ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("skip_to %f\n", f1);
        A4GL_debug ("skip_to %f\n", f1);
#endif // }}}

        rep->line_no = f1 + 1;

        return 0;
    }
// }}}
// stroke {{{
    if (strcmp (fname, "stroke") == 0)
    {

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("stroke\n");
        A4GL_debug ("stroke\n");
#endif // }}}

        HPDF_Page_Stroke (DOC_CURRENT_PAGE (rep));

        return 0;
    }
// }}}
// texturl text_url{{{
    if (strcmp (fname, "texturl") == 0 ||
        strcmp (fname, "text_url") == 0)
    {
        char           *url;
        char           *text;

        HPDF_Rect       rect;
        HPDF_Annotation annot;

        double          lly1;
        double          lly2;
        double          llx1;
        double          llx2;

        url = A4GL_char_pop ();
        text = A4GL_char_pop ();

        A4GL_trim (url);

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("texturl url=%s text=%s\n", url, text);
        A4GL_debug ("texturl url=%s text=%s\n", url, text);
#endif // }}}

        lly1 = rep->page_length - rep->line_no;
        lly2 = lly1 + A4GLPDFREP_A4GL_pdf_size (1, 'l', rep);
        llx1 = rep->col_no;
        llx2 = llx1 + A4GL_pdf_text_width (rep, text);

        //A4GL_pdf_set_color (rep, "both", "rgb", 0, 0, 1, 0);

        A4GL_pdf_position_aligned_text (rep, llx1, lly1, text, "left");
        A4GL_pdf_show_text_internal (rep, text);

        rect.left   = llx1;
        rect.bottom = lly1;
        rect.right  = llx2;
        rect.top    = lly2;

        annot = HPDF_Page_CreateURILinkAnnot (DOC_CURRENT_PAGE (rep), rect, url);
        HPDF_LinkAnnot_SetBorderStyle (annot, 0, 0, 0);

        //A4GL_pdf_reset_color (rep);

        acl_free (url);
        acl_free (text);

        return 0;
    }
// }}}
// textwidth text_width {{{
    if (strcmp (fname, "textwidth") == 0 ||
        strcmp (fname, "text_width") == 0)
    {
        char           *s;
        double          d;

        s = A4GL_char_pop ();

        d = A4GL_pdf_text_width (rep, s);

        A4GL_push_double (d);

        acl_free (s);

        return 1;
    }
// }}}
// translate {{{
/**
 * translate (tx, ty)
 *
 * Translate the origin of the coordinate system.
 *
 * tx, ty       The new origin of the coordinate system is the point (tx, ty),
 *              measured in the old coordinate system.
 *
 */

    if (strcmp (fname, "translate") == 0)
    {
        double          tx;
        double          ty;

        double          a, b, c, d, e, f;

        ty = A4GL_pop_double ();
        tx = A4GL_pop_double ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("translate tx=%f ty=%f\n", tx, ty);
        A4GL_debug ("translate tx=%f ty=%f\n", tx, ty);
#endif // }}}

        a = 1;
        b = 0;
        c = 0;
        d = 1;
        e = tx;
        f = ty;

        select_gmode (DOC (rep), HPDF_GMODE_PAGE_DESCRIPTION);

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("translate a=%f b=%f c=%f d=%f e=%f f=%f\n", a, b, c, d, e, f);
        A4GL_debug ("translate a=%f b=%f c=%f d=%f e=%f f=%f\n", a, b, c, d, e, f);
#endif // }}}

        HPDF_Page_Concat (DOC_CURRENT_PAGE (rep), a, b, c, d, e, f);

        return 0;
    }
// }}}

// A4GLPDFREP_A4GL_pdf_pdffunc_internal - END {{{
    char unknown[256];
    sprintf (unknown, "Unknown PDF function (%s)", fname);
    A4GL_assertion (1, unknown);

    return 0;
}
// }}}

// A4GL_get_pdf_haru_encoding {{{
char *
A4GL_get_pdf_haru_encoding (void)
{
    char           *s;

    s = A4GL_get_pdf_encoding ();

    if (strcmp (s, "winansi") == 0)
        return "WinAnsiEncoding";

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("get pdf encoding: s=%s\n", s);
    A4GL_debug ("get pdf encoding: s=%s\n", s);
#endif // }}}

    return s;
}
// }}}

// begin_text_mode {{{
static void
begin_text_mode (struct pdf_rep_structure *rep)
{
    // clear any existing page states
    select_gmode (DOC (rep), HPDF_GMODE_PAGE_DESCRIPTION);

    HPDF_Page_BeginText (DOC_CURRENT_PAGE (rep));
}
// }}}
// select_gmode {{{
static void
select_gmode (Haru_doc * doc, HPDF_UINT16 unew)
{

    HPDF_UINT16     u;

    u = HPDF_Page_GetGMode (doc->current_page);

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("select_gmode: required=%d current=%d\n", unew, u);
    A4GL_debug ("select_gmode: required=%d current=%d\n", unew, u);
#endif // }}}

    if (u == unew)
        return;

    switch (u)
    {
        case HPDF_GMODE_PAGE_DESCRIPTION:
#ifdef DEBUG // {{{
//          if (A4GL_PDF_DEBUG)
//              printf ("select_gmode: page description\n");
            A4GL_debug ("select_gmode: page description\n");
#endif // }}}
            break;

        case HPDF_GMODE_TEXT_OBJECT:
#ifdef DEBUG // {{{
//          if (A4GL_PDF_DEBUG)
//              printf ("select_gmode: text object\n");
            A4GL_debug ("select_gmode: text object\n");
#endif // }}}
            HPDF_Page_EndText (doc->current_page);
            break;

        case HPDF_GMODE_PATH_OBJECT:
#ifdef DEBUG // {{{
//          if (A4GL_PDF_DEBUG)
//              printf ("select_gmode: path object\n");
            A4GL_debug ("select_gmode: path object\n");
#endif // }}}
            HPDF_Page_EndPath (doc->current_page);
            //HPDF_Page_Stroke (doc->current_page);
            break;

        case HPDF_GMODE_CLIPPING_PATH:
#ifdef DEBUG // {{{
//          if (A4GL_PDF_DEBUG)
//              printf ("select_gmode: clipping path\n");
            A4GL_debug ("select_gmode: clipping path\n");
#endif // }}}
            HPDF_Page_EndPath (doc->current_page);
            //HPDF_Page_Stroke (doc->current_page);
            break;
    }
}
// }}}
// newdoc {{{
HPDF_Doc
newdoc (struct pdf_rep_structure *rep)
{
    HPDF_Doc        doc;

    doc = HPDF_New (error_handler, NULL);

    return doc;
}
// }}}

// Mapped functions used in generate_barcode
// PDF_fill_stroke {{{
void
PDF_fill_stroke (void *pv)
{
    struct Haru_doc *p;

    p = (Haru_doc *) pv;

    if (HPDF_Page_GetGMode (p->current_page) == HPDF_GMODE_TEXT_OBJECT)
        select_gmode (p, HPDF_GMODE_PATH_OBJECT);

    HPDF_Page_FillStroke (p->current_page);
}
// }}}
// PDF_rect {{{
void
PDF_rect (void *pv, double x, double y, double width, double height)
{
    struct Haru_doc *p;

    p = (Haru_doc *) pv;

    if (HPDF_Page_GetGMode (p->current_page) == HPDF_GMODE_TEXT_OBJECT)
        select_gmode (p, HPDF_GMODE_PATH_OBJECT);

    HPDF_Page_Rectangle (p->current_page, x, y, width, height);
}
// }}}
// PDF_set_text_pos {{{
void
PDF_set_text_pos (void *pv, double x, double y)
{
    struct Haru_doc *p;

    p = (Haru_doc *) pv;

    if (HPDF_Page_GetGMode (p->current_page) != HPDF_GMODE_TEXT_OBJECT)
    {
        select_gmode (p, HPDF_GMODE_TEXT_OBJECT);
        HPDF_Page_BeginText (p->current_page);
    }

    HPDF_Page_MoveTextPos (p->current_page, x, y);
}
// }}}
// PDF_setlinewidth {{{
void
PDF_setlinewidth (void *pv, double width)
{
    struct Haru_doc *p;

    p = (Haru_doc *) pv;

    if (HPDF_Page_GetGMode (p->current_page) == HPDF_GMODE_TEXT_OBJECT)
        select_gmode (p, HPDF_GMODE_PAGE_DESCRIPTION);

    HPDF_Page_SetLineWidth (p->current_page, width);
}
// }}}
// PDF_show {{{
void
PDF_show (void *pv, char *text)
{
    struct Haru_doc *p;

    p = (Haru_doc *) pv;

    if (HPDF_Page_GetGMode (p->current_page) != HPDF_GMODE_TEXT_OBJECT)
    {
        select_gmode (p, HPDF_GMODE_TEXT_OBJECT);
        HPDF_Page_BeginText (p->current_page);
    }

    HPDF_Page_ShowText (p->current_page, text);
    HPDF_Page_EndText (p->current_page);
}
// }}}

/* vim: set expandtab softtabstop=4 tabstop=4 shiftwidth=4 foldmethod=marker: */
/* ================================ EOF ============================== */
