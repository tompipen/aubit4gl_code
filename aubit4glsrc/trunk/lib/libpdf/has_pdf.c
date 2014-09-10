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
# $Id: has_pdf.c,v 1.78 2014-09-10 17:09:57 pauldgardiner Exp $
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

#define USE_PDFLIB_H

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

void            A4GLREPORT_initlib (void);

static char    *A4GL_report_char_pop (void);

void            A4GL_pdf_add_spaces (void);


static void     A4GL_pdf_get_font_info (struct pdf_rep_structure *rep);
static int      A4GL_pdf_is_core_font (char const *font);
double          A4GL_pdf_metric (int a, char c, struct pdf_rep_structure *rep);
void            A4GL_pdf_move (struct pdf_rep_structure *rep);
int             A4GL_pdf_new_page (struct pdf_rep_structure *rep);

static void     A4GL_pdf_reset_color (struct pdf_rep_structure *rep);
static void     A4GL_pdf_resume_page (struct pdf_rep_structure *rep, int page);
static void     A4GL_pdf_set_color (struct pdf_rep_structure *rep, const char *fstype, const char *colorspace, double c1, double c2, double c3, double c4);
static void     A4GL_pdf_set_compression (struct pdf_rep_structure *rep, int level);
static int      A4GL_pdf_set_font_name (struct pdf_rep_structure *rep, char *font_name, int font_embedded);
static void     A4GL_pdf_show_text_internal (struct pdf_rep_structure *rep, char *text);
static void     A4GL_pdf_suspend_page (struct pdf_rep_structure *rep);
static double   A4GL_pdf_text_width (struct pdf_rep_structure *rep, char *text);

void            generate_barcode (PDF * p, double xpos, double ypos, double x, double y, char *str, float p_page_height, int incl_text);
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

#ifdef DEBUG // {{{
    A4GL_debug ("Calling PDF_boot");
#endif // }}}

    //QUERY MJA - is this required now?
    PDF_boot ();

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

        if (rep->pdf_ptr)
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


    PDF_set_text_pos ((PDF *) rep->pdf_ptr, rep->col_no, rep->page_length - rep->line_no);
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

    /* PDF_begin_page ((PDF *) rep->pdf_ptr, width, height); */

    if (rep->page_no)
    {
        if (A4GL_isyes (acl_getenv ("A4GL_PDF_SUSPEND_PAGES")))
            A4GL_pdf_suspend_page (rep);
        else
            PDF_end_page ((PDF *) rep->pdf_ptr);
    }

#ifdef DEBUG // {{{
    A4GL_debug ("Begin page width = %lf length=%lf\n", rep->page_width, rep->page_length);
#endif // }}}

    PDF_begin_page ((PDF *) rep->pdf_ptr, rep->page_width, rep->page_length);

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
        PDF_setlinewidth ((PDF *) rep->pdf_ptr, eachline / 20);

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

                    PDF_moveto ((PDF *) rep->pdf_ptr, (0), ypos + spacing);
                    PDF_lineto ((PDF *) rep->pdf_ptr, (rep->page_width), ypos + spacing);
                }

                ypos = ypos - (eachline * 2);

                if (ypos + eachline < rep->bottom_margin)
                    break;
            }

            PDF_stroke ((PDF *) rep->pdf_ptr);
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

                PDF_rect ((PDF *) rep->pdf_ptr, (0), ypos - offset, rep->page_width, eachline * 0.9);
                PDF_fill_stroke ((PDF *) rep->pdf_ptr);

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
// A4GL_pdf_reset_color {{{
static void
A4GL_pdf_reset_color (struct pdf_rep_structure *rep)
{

    PDF_setcolor ((PDF *) rep->pdf_ptr, "stroke", "rgb", rep->stroke_color_r, rep->stroke_color_g, rep->stroke_color_b, 0);
    PDF_setcolor ((PDF *) rep->pdf_ptr, "fill", "rgb", rep->fill_color_r, rep->fill_color_g, rep->fill_color_b, 0);
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
    char opt_page_no[20];

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("resume page=%d\n", page);
    A4GL_debug ("resume page=%d\n", page);
#endif // }}}

    sprintf (opt_page_no, "pagenumber=%d", page);
    PDF_resume_page ((PDF *) rep->pdf_ptr, opt_page_no);

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

    if (strcmp (fstype, "fill") == 0)
    {
        rep->fill_color_r = c1;
        rep->fill_color_g = c2;
        rep->fill_color_b = c3;
        PDF_setcolor ((PDF *) rep->pdf_ptr, fstype, colorspace, c1, c2, c3, c4);
        return;
    }

    if (strcmp (fstype, "stroke") == 0)
    {
        rep->stroke_color_r = c1;
        rep->stroke_color_g = c2;
        rep->stroke_color_b = c3;
        PDF_setcolor ((PDF *) rep->pdf_ptr, fstype, colorspace, c1, c2, c3, c4);
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
        PDF_setcolor ((PDF *) rep->pdf_ptr, fstype, colorspace, c1, c2, c3, c4);
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

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("A4GL_pdf_set_compression level=%d\n", level);
    A4GL_debug ("A4GL_pdf_set_compression level=%d\n", level);
#endif // }}}

    PDF_set_value ((PDF *) rep->pdf_ptr, "compress", level);
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
    int       a;


#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("args A4GL_pdf_set_font_name font_name=%s font_embedded=%d\n", font_name, font_embedded);
    A4GL_debug ("args A4GL_pdf_set_font_name font_name=%s font_embedded=%d\n", font_name, font_embedded);
#endif // }}}

    a = PDF_load_font ((PDF *) rep->pdf_ptr, font_name, 0, A4GL_get_pdf_encoding (), (font_embedded > 0) ? "embedding" : "");

    if (a < 0)
    {
        A4GL_exitwith ("Unable to locate font");
        return 0;
    }
    else
    {
#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("A4GL_pdf_set_font_name font=%s ok\n", font_name);
    A4GL_debug ("A4GL_pdf_set_font_name font=%s ok\n", font_name);
#endif // }}}
    }

    // make font current if embedded value is not 2
    if (font_embedded != 2)
    {
        strcpy (rep->font_name, font_name);

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("A4GL_pdf_set_font_name font=%s\n", rep->font_name);
        A4GL_debug ("A4GL_pdf_set_font_name font=%s\n", rep->font_name);
#endif // }}}

        rep->font = a;

        PDF_setfont ((PDF *) rep->pdf_ptr, rep->font, rep->font_size);

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

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("A4GL_pdf_show_text_internal text=%s\n", text);
    A4GL_debug ("A4GL_pdf_show_text_internal text=%s\n", text);
#endif // }}}

    PDF_show ((PDF *) rep->pdf_ptr, text);
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

#ifdef DEBUG // {{{
    if (A4GL_PDF_DEBUG)
        printf ("suspend page=%d\n", rep->current_page_no);
    A4GL_debug ("suspend page=%d\n", rep->current_page_no);
#endif // }}}

    PDF_suspend_page ((PDF *) rep->pdf_ptr, "");

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

    return PDF_stringwidth ((PDF *) rep->pdf_ptr, "W", rep->font, rep->font_size);
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
    int             n;
    double          sx;
    double          sy;
    int             x, y;
    double          ox;
    double          oy;
    struct pdf_rep_structure *rep;
    struct fgl_int_loc *blob;

    rep = (struct pdf_rep_structure *) vrep;

    blob = (struct fgl_int_loc *) vblob;

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

    n = PDF_open_image_file ((PDF *) rep->pdf_ptr, type, blob->filename, "", 0);

#ifdef DEBUG // {{{
    A4GL_debug ("Image handle=%d\n", n);
#endif // }}}

    if (n < 0)

        /* exitwith ("Unable to open file %s %s", type, blob->filename); */
        /* An empty blob or invalid type (bmp) is also error,
           so just ignore and continue */
        /* A4GL_exitwith ("Unable to open file."); */
        return;

    y = PDF_get_value ((PDF *) rep->pdf_ptr, "imageheight", n);
    x = PDF_get_value ((PDF *) rep->pdf_ptr, "imagewidth", n);

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

    PDF_place_image ((PDF *) rep->pdf_ptr, n, rep->col_no, rep->page_length - rep->line_no - y, sx);

#ifdef DEBUG // {{{
    A4GL_debug ("Closing");
#endif // }}}

    PDF_close_image ((PDF *) rep->pdf_ptr, n);

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
    int             n;
    double          sx;
    double          sy;
    int             x, y;
    double          ox;
    double          oy;
    char           *filename;
    struct pdf_rep_structure *rep;

    rep = (struct pdf_rep_structure *) vrep;

    filename = A4GL_char_pop ();
    A4GL_trim (filename);

    sx = A4GL_pop_double ();
    sy = A4GL_pop_double ();

    n = PDF_open_image_file ((PDF *) rep->pdf_ptr, type, filename, "", 0);

    if (n < 0)

        /* exitwith ("Unable to open file %s %s", type, blob->filename); */
        /* An empty blob or invalid type (bmp) is also error,
           so just ignore and continue */
        /* A4GL_exitwith ("Unable to open file."); */
        return;

    y = PDF_get_value ((PDF *) rep->pdf_ptr, "imageheight", n);
    x = PDF_get_value ((PDF *) rep->pdf_ptr, "imagewidth", n);

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



    PDF_place_image ((PDF *) rep->pdf_ptr, n, rep->col_no, rep->page_length - rep->line_no - y, sx);

#ifdef DEBUG // {{{
    A4GL_debug ("Closing");
#endif // }}}

    PDF_close_image ((PDF *) rep->pdf_ptr, n);

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


#ifdef DEBUG // {{{
        A4GL_debug ("A");
#endif // }}}

        if (A4GL_isyes (acl_getenv ("A4GL_PDF_SUSPEND_PAGES")))
        {

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("ending %d suspended pages\n", rep->page_no);
        A4GL_debug ("ending %d suspended pages\n", rep->page_no);
#endif // }}}

            // suspend the current page
            A4GL_pdf_suspend_page (rep);

            // end all suspended pages
            for (i=1; i <= rep->page_no; i++)
            {
                A4GL_pdf_resume_page (rep, i);
                PDF_end_page ((PDF *) rep->pdf_ptr);
            }
        }
        else
        {
            // just end current page
            PDF_end_page ((PDF *) rep->pdf_ptr);
        }

        PDF_close ((PDF *) rep->pdf_ptr);
        PDF_delete ((PDF *) rep->pdf_ptr);

        //QUERY - newer method
        //PDF_end_document ((PDF *) rep->pdf_ptr, "");
    }

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
                    rep->pdf_ptr = (void *) PDF_new ();
                    PDF_set_parameter ((PDF *) rep->pdf_ptr, "compatibility", "1.4");

#ifdef DEBUG // {{{
                    A4GL_debug ("Opening file: %s\n", rep->output_loc_str);
#endif // }}}

                    if (PDF_open_file ((PDF *) rep->pdf_ptr, rep->output_loc_str) == -1)
                    {
                        A4GL_exitwith ("Error opening output\n");
                        return;
                    }

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
    PDF_set_info ((PDF *) p, "Creator", creator);
    PDF_set_info ((PDF *) p, "Author", "Auto");
    PDF_set_info ((PDF *) p, "Title", "Auto");
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

        if (strcmp (fname, "add_bookmark") == 0 ||
            strcmp (fname, "add_bookmark_no_ret") == 0)
            a = A4GL_pop_int ();

        buf = A4GL_char_pop ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("args func=%s buf=%s a=%d\n", fname, buf, a);
        A4GL_debug ("args func=%s buf=%s a=%d\n", fname, buf, a);
#endif // }}}

        if (strcmp (fname, "bookmark") == 0)
            PDF_create_bookmark ((PDF *) rep->pdf_ptr, buf, 0, "");
        else
            a = PDF_add_bookmark ((PDF *) rep->pdf_ptr, buf, a, 0);

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("func=%s a=%d\n", fname, a);
        A4GL_debug ("func=%s a=%d\n", fname, a);
#endif // }}}

        acl_free (buf);

        if (strcmp (fname, "add_bookmark_no_ret") == 0 ||
            strcmp (fname, "bookmark") == 0)
        {
            return 0;
        }
        else
        {
            A4GL_push_int (a);
            return 1;
        }
    }
// }}}
// add_table_cell {{{
    if (strcmp (fname, "add_table_cell") == 0)
    {
        int             table;
        int             column;
        int             row;
        char           *text;
        char           *optlist = "";

        if (nargs >= 5)
            optlist = A4GL_char_pop ();

        text = A4GL_char_pop ();
        row = A4GL_pop_long ();
        column = A4GL_pop_long ();
        table = A4GL_pop_long ();

        table = PDF_add_table_cell ((PDF *) rep->pdf_ptr, table, column, row, text, strlen (text), optlist);

        A4GL_push_int (table);

        acl_free (text);

        if (nargs >= 5)
            acl_free (optlist);

        return 1;
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

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
                printf ("arc x=%f y=%f r=%f alpha=%f beta=%f\n", x, y, r, alpha, beta);
            A4GL_debug ("arc x=%f y=%f r=%f alpha=%f beta=%f\n", x, y, r, alpha, beta);
#endif // }}}

            PDF_arc ((PDF *) rep->pdf_ptr, x, y, r, alpha, beta);

        }
        else
        {
            // arcn - clockwise

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
                printf ("arcn x=%f y=%f r=%f alpha=%f beta=%f\n", x, y, r, alpha, beta);
            A4GL_debug ("arcn x=%f y=%f r=%f alpha=%f beta=%f\n", x, y, r, alpha, beta);
#endif // }}}

            PDF_arcn ((PDF *) rep->pdf_ptr, x, y, r, alpha, beta);
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

        generate_barcode ((PDF *) rep->pdf_ptr, x, y, w, h, str, rep->page_length, show_text);

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

        PDF_circle ((PDF *) rep->pdf_ptr, x, y, r);
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

        PDF_clip ((PDF *) rep->pdf_ptr);
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

        PDF_closepath ((PDF *) rep->pdf_ptr);
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

        PDF_concat ((PDF *) rep->pdf_ptr, a, b, c, d, e, f);

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







        // move to 12 o'clock
        PDF_moveto ((PDF *) rep->pdf_ptr, x, y + yr);

        // first quarter 12 - 3 o'clock
        PDF_curveto ((PDF *) rep->pdf_ptr,
            x + (xr * bezier_cp_quarter), y + yr,
            x + xr                      , y + (yr * bezier_cp_quarter),
            x + xr                      , y
            );
        // second quarter 3 - 6 o'clock
        PDF_curveto ((PDF *) rep->pdf_ptr,
            x + xr                      , y - (yr * bezier_cp_quarter),
            x + (xr * bezier_cp_quarter), y - yr,
            x                           , y - yr
            );
        // third quarter 6 - 9 o'clock
        PDF_curveto ((PDF *) rep->pdf_ptr,
            x - (xr * bezier_cp_quarter), y - yr,
            x - xr                      , y - (yr * bezier_cp_quarter),
            x - xr                      , y
            );
        // forth quarter 9 - 12 o'clock
        PDF_curveto ((PDF *) rep->pdf_ptr,
            x - xr                      , y + (yr * bezier_cp_quarter),
            x - (xr * bezier_cp_quarter), y + yr,
            x                           , y + yr
            );

        // move back to centre
        PDF_moveto ((PDF *) rep->pdf_ptr, x, y);

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

        PDF_fill ((PDF *) rep->pdf_ptr);

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

        PDF_fill_stroke ((PDF *) rep->pdf_ptr);

        return 0;
    }
// }}}
// fit_table {{{
    if (strcmp (fname, "fit_table") == 0)
    {
        int             table;
        double          llx;
        double          lly;
        double          urx;
        double          ury;
        char           *optlist = "";
        const char     *rval;

        if (nargs >= 5)
            optlist = A4GL_char_pop ();

        ury = A4GL_pop_double ();
        urx = A4GL_pop_double ();
        lly = A4GL_pop_double ();
        llx = A4GL_pop_double ();
        table = A4GL_pop_long ();

        rval = PDF_fit_table ((PDF *) rep->pdf_ptr, table, llx, lly, urx, ury, optlist);

        A4GL_push_char ((char *) rval);

        if (nargs >= 5)
            acl_free (optlist);

        return 1;
    }
// }}}
// fit_textline {{{
    if (strcmp (fname, "fit_textline") == 0)
    {
        char           *text;
        double          llx;
        double          lly;
        char           *optlist = "";

        if (nargs >= 4)
            optlist = A4GL_char_pop ();

        lly = A4GL_pop_double ();
        llx = A4GL_pop_double ();

        text = A4GL_char_pop ();

        PDF_fit_textline ((PDF *) rep->pdf_ptr, text, strlen (text), llx, lly, optlist);

        if (nargs >= 4)
            acl_free (optlist);

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

        PDF_lineto ((PDF *) rep->pdf_ptr, f1, f2);

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

        PDF_moveto ((PDF *) rep->pdf_ptr, f1, f2);

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


        PDF_rect ((PDF *) rep->pdf_ptr, fx, fy, fw, fh);

        if (rect_is_stroked)
            PDF_stroke ((PDF *) rep->pdf_ptr);

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

        if (strcmp (corners, "0000") == 0 || r == 0)
        {
            // square corners only
            PDF_rect ((PDF *) rep->pdf_ptr, x, y, w, h);
        }
        else
        {
            // 1 or more rounded corners required

            // start at bottom left
            if (corners[3] == '1')
            {
                PDF_arc ((PDF *) rep->pdf_ptr, x + r, y + r, r, 180, 270);
            }
            else
            {
                PDF_moveto ((PDF *) rep->pdf_ptr, x, y);
            }

            // bottom right
            if (corners[2] == '1')
            {
                PDF_lineto ((PDF *) rep->pdf_ptr, x + w - r, y);
                PDF_arc ((PDF *) rep->pdf_ptr, x + w - r, y + r, r, 270, 360);
            }
            else
            {
                PDF_lineto ((PDF *) rep->pdf_ptr, x + w, y);
            }

            // top right
            if (corners[1] == '1')
            {
                PDF_lineto ((PDF *) rep->pdf_ptr, x + w, y + h - r);
                PDF_arc ((PDF *) rep->pdf_ptr, x + w - r, y + h - r, r, 0, 90);
            }
            else
            {
                PDF_lineto ((PDF *) rep->pdf_ptr, x + w, y + h);
            }

            // top left
            if (corners[0] == '1')
            {
                PDF_lineto ((PDF *) rep->pdf_ptr, x + r, y + h);
                PDF_arc ((PDF *) rep->pdf_ptr, x + r, y + h - r, r, 90, 180);
            }
            else
            {
                PDF_lineto ((PDF *) rep->pdf_ptr, x, y + h);
            }

            // close the rectangle
            PDF_closepath ((PDF *) rep->pdf_ptr);
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

        PDF_restore ((PDF *) rep->pdf_ptr);

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



#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("rotate a=%f b=%f c=%f d=%f e=%f f=%f\n", a, b, c, d, e, f);
        A4GL_debug ("rotate a=%f b=%f c=%f d=%f e=%f f=%f\n", a, b, c, d, e, f);
#endif // }}}

        PDF_concat ((PDF *) rep->pdf_ptr, a, b, c, d, e, f);

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



        PDF_save ((PDF *) rep->pdf_ptr);

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



#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("scale a=%f b=%f c=%f d=%f e=%f f=%f\n", a, b, c, d, e, f);
        A4GL_debug ("scale a=%f b=%f c=%f d=%f e=%f f=%f",   a, b, c, d, e, f);
#endif // }}}

        PDF_concat ((PDF *) rep->pdf_ptr, a, b, c, d, e, f);

        return 0;
    }
// }}}
// set_font_size {{{

    if (strcmp (fname, "set_font_size") == 0)
    {
        double font_size;

        font_size = A4GL_pop_double ();

        rep->font_size = font_size;

        PDF_setfont ((PDF *) rep->pdf_ptr, rep->font, rep->font_size);

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
 * any name other           User-defined field. PDFlib supports an arbitrary number of fields. A custom field
 * than CreationDate,       name should only be supplied once. With multiple occurrences of the same field
 * Producer, ModDate,       name the last one will be used. See also moddate option of PDF_begin/end_document ( ).
 * GTS_PDFXVersion,         Custom document info fields must not contain any space character if XMP meta-
 * GTS_PDFXConformance,     data is created (via the autoxmp or metadata options).
 * ISO_PDFEVersion
 *
 */

    if (strcmp (fname, "set_info") == 0)
    {
        char           *key;
        char           *value;

        int             valid_key = 1;

        value = A4GL_char_pop ();
        key = A4GL_char_pop ();

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("set_info key=%s value=%s\n", key, value);
        A4GL_debug ("set_info key=%s value=%s\n", key, value);
#endif // }}}

        // pdflib allows any keys apart from the following
        if (strcmp (key, "CreationDate") == 0 ||
            strcmp (key, "creationdate") == 0 ||
            strcmp (key, "Producer") == 0 ||
            strcmp (key, "producer") == 0 ||
            strcmp (key, "ModDate") == 0 ||
            strcmp (key, "moddate") == 0 ||
            strcmp (key, "GTS_PDFXVersion") == 0 ||
            strcmp (key, "gts_pdfxversion") == 0 ||
            strcmp (key, "GTS_PDFXConformance") == 0 ||
            strcmp (key, "gts_pdfxconformance") == 0 ||
            strcmp (key, "ISO_PDFEVersion") == 0 ||
            strcmp (key, "iso_pdfeversion") == 0)
            valid_key = 0;

        if (valid_key)
        {
            PDF_set_info ((PDF *) rep->pdf_ptr, key, value);
        }

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

        PDF_set_parameter ((PDF *) rep->pdf_ptr, parameter, value);

        acl_free (parameter);
        acl_free (value);

        return 0;
    }
// }}}
// set_text_format {{{
// pdflib parameter:
// (Only for non Unicode-compatible language bindings) The format in which the text output functions will
// expect the client-supplied strings. Possible values are bytes, utf8, ebcdicutf8 (only on iSeries and
// zSeries), utf16, utf16le, utf16be, and auto. Default: auto. Scope: any
    if (strcmp (fname, "set_text_format") == 0)
    {
        char           *s;

        s = A4GL_char_pop ();

        PDF_set_parameter ((PDF *) rep->pdf_ptr, "textformat", s);

        acl_free (s);

        return 0;
    }
// }}}
// set_value {{{
    if (strcmp (fname, "set_value") == 0)
    {
        char           *key;
        double          value;
        int             set_key = 1;

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
            set_key = 0;
        }

        if (strcmp (key, "horizscaling") == 0)
        {
            rep->value.horizscaling = value; 
        }

        if (strcmp (key, "strokewidth") == 0)
        {
            rep->value.strokewidth = value; 
            // just used internally
            set_key = 0;
        }

        if (strcmp (key, "textrendering") == 0)
        {
            rep->value.textrendering = value; 
        }

        if (strcmp (key, "textrise") == 0)
        {
            rep->value.textrise = value; 
        }

        if (strcmp (key, "underlineposition") == 0)
            rep->value.underlineposition = value; 

        if (strcmp (key, "underlinewidth") == 0)
            rep->value.underlinewidth = value; 

        if (set_key)
            PDF_set_value ((PDF *) rep->pdf_ptr, key, value);

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

        char            optlist[100];

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

        sprintf (optlist, "dasharray={%f %f} dashphase=%f", black, white, phase);

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("setdash black=%f white=%f phase=%f\n", black, white, phase);
        A4GL_debug ("setdash black=%f white=%f phase=%f\n", black, white, phase);
#endif // }}}

        //PDF_setdash ((PDF *) rep->pdf_ptr, black, white);
        PDF_setdashpattern ((PDF *) rep->pdf_ptr, optlist);

        return 0;
    }
// }}}
// setdashpattern set_dash_pattern {{{
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

        char            optlist[200];
        char            opt[50];

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
        sprintf (optlist, "dasharray={%f %f", black1, white1);
        while (1 == 1)
        {
            if (black2 > 0) { sprintf (opt, " %f", black2); strcat (optlist, opt); } else { break; }
            if (white2 > 0) { sprintf (opt, " %f", white2); strcat (optlist, opt); } else { break; }
            if (black3 > 0) { sprintf (opt, " %f", black3); strcat (optlist, opt); } else { break; }
            if (white3 > 0) { sprintf (opt, " %f", white3); strcat (optlist, opt); } else { break; }
            if (black4 > 0) { sprintf (opt, " %f", black4); strcat (optlist, opt); } else { break; }
            if (white4 > 0) { sprintf (opt, " %f", white4); strcat (optlist, opt); } else { break; }
            break;
        }

        sprintf (opt, "} dashphase=%f", phase);
        strcat (optlist, opt);

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("setdashpattern optlist=%s\n", optlist);
        A4GL_debug ("setdashpattern optlist=%s\n", optlist);
#endif // }}}

        PDF_setdashpattern ((PDF *) rep->pdf_ptr, optlist);

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

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("setlinecap=%d\n", a);
        A4GL_debug ("setlinecap=%d\n", a);
#endif // }}}

        PDF_setlinecap ((PDF *) rep->pdf_ptr, a);

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

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("setlinejoin=%d\n", a);
        A4GL_debug ("setlinejoin=%d\n", a);
#endif // }}}

        PDF_setlinejoin ((PDF *) rep->pdf_ptr, a);

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

        PDF_setlinewidth ((PDF *) rep->pdf_ptr, d);

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
        int             c = 0;

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

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("%s x=%f y=%f w=%f h=%f text=%s mode=%s feature=%s\n", fname, fx, fy, fw, fh, text, mode, feature);
        A4GL_debug ("%s x=%f y=%f w=%f h=%f text=%s mode=%s feature=%s\n", fname, fx, fy, fw, fh, text, mode, feature);
#endif // }}}

        c = PDF_show_boxed ((PDF *) rep->pdf_ptr, text, fx, fy, fw, fh, mode, feature);

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

        PDF_set_text_pos ((PDF *) rep->pdf_ptr, fx, fy);
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



#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("skew a=%f b=%f c=%f d=%f e=%f f=%f\n", a, b, c, d, e, f);
        A4GL_debug ("skew a=%f b=%f c=%f d=%f e=%f f=%f\n", a, b, c, d, e, f);
#endif // }}}

      PDF_concat ((PDF *) rep->pdf_ptr, a, b, c, d, e, f);

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

        PDF_stroke ((PDF *) rep->pdf_ptr);

        return 0;
    }
// }}}
// texturl text_url{{{
    if (strcmp (fname, "texturl") == 0 ||
        strcmp (fname, "text_url") == 0)
    {
        char           *url;
        char           *text;

        //QUERY MJA - bit large?
        char            optlist[20000];

        double          lly1;
        double          lly2;
        double          llx1;
        double          llx2;
        int             d;

        url = A4GL_char_pop ();
        text = A4GL_char_pop ();

        //lly=A4GL_pop_double ();
        //llx=A4GL_pop_double ();
        A4GL_trim (url);
        sprintf (optlist, "url {%s}", url);

#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("texturl url=%s text=%s\n", url, text);
        A4GL_debug ("texturl url=%s text=%s\n", url, text);
#endif // }}}

        d = PDF_create_action ((PDF *) rep->pdf_ptr, "URI", optlist);
        lly1 = rep->page_length - rep->line_no;
        lly2 = lly1 + A4GLPDFREP_A4GL_pdf_size (1, 'l', rep);
        llx1 = rep->col_no;
        llx2 = llx1 + A4GL_pdf_text_width (rep, text);

        //A4GL_pdf_set_color (rep, "both", "rgb", 0, 0, 1, 0);

        PDF_fit_textline ((PDF *) rep->pdf_ptr, text, strlen (text), llx1, lly1, "");
        sprintf (optlist, "action={activate %d } linewidth=0", d);
        PDF_create_annotation ((PDF *) rep->pdf_ptr, llx1, lly1, llx2, lly2, "Link", optlist);

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



#ifdef DEBUG // {{{
        if (A4GL_PDF_DEBUG)
            printf ("translate a=%f b=%f c=%f d=%f e=%f f=%f\n", a, b, c, d, e, f);
        A4GL_debug ("translate a=%f b=%f c=%f d=%f e=%f f=%f\n", a, b, c, d, e, f);
#endif // }}}

        PDF_concat ((PDF *) rep->pdf_ptr, a, b, c, d, e, f);

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

/* vim: set expandtab softtabstop=4 tabstop=4 shiftwidth=4 foldmethod=marker: */
/* ================================ EOF ============================== */
