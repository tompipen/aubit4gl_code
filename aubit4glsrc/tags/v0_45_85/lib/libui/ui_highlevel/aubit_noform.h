#include <curses.h>
/* A lot of this is copied from ncurses libform and hacked...

 That software contains :
 ****************************************************************************
 * Copyright (c) 1998,2000 Free Software Foundation, Inc.                   *
 *                                                                          *
 * Permission is hereby granted, free of charge, to any person obtaining a  *
 * copy of this software and associated documentation files (the            *
 * "Software"), to deal in the Software without restriction, including      *
 * without limitation the rights to use, copy, modify, merge, publish,      *
 * distribute, distribute with modifications, sublicense, and/or sell       *
 * copies of the Software, and to permit persons to whom the Software is    *
 * furnished to do so, subject to the following conditions:                 *
 *                                                                          *
 * The above copyright notice and this permission notice shall be included  *
 * in all copies or substantial portions of the Software.                   *
 *                                                                          *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *
 * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *
 * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *
 *                                                                          *
 * Except as contained in this notice, the name(s) of the above copyright   *
 * holders shall not be used in advertising or otherwise to promote the     *
 * sale, use or other dealings in this Software without prior written       *
 * authorization.
 ****************************************************************************
 *   Author:  Juergen Pfeifer, 1995,1997                                    *
 *   Contact: http://www.familiepfeifer.de/Contact.aspx?Lang=en             *
 ****************************************************************************
*/

typedef int Form_Options;
typedef int Field_Options;
typedef int OPTIONS;

typedef struct {
  short pmin;     /* index of first field on page            */
  short pmax;     /* index of last field on page             */
  short smin;     /* index of top leftmost field on page     */
  short smax;     /* index of bottom rightmost field on page */
} _PAGE;

typedef struct fieldnode {
  unsigned short        status;   /* flags                      */
  short                 rows;     /* size in rows               */
  short                 cols;     /* size in cols               */
  short                 frow;     /* first row                  */
  short                 fcol;     /* first col                  */
  int                   drows;    /* dynamic rows               */
  int                   dcols;    /* dynamic cols               */
  int                   maxgrow;  /* maximum field growth       */
  int                   nrow;     /* offscreen rows             */
  short                 nbuf;     /* additional buffers         */
  short                 just;     /* justification              */
  short                 page;     /* page on form               */
  short                 index;    /* into form -> field         */
  int                   pad;      /* pad character              */
  chtype                fore;     /* foreground attribute       */
  chtype                back;     /* background attribute       */
  Field_Options         opts;     /* options                    */
  struct fieldnode *    snext;    /* sorted order pointer       */
  struct fieldnode *    sprev;    /* sorted order pointer       */
  struct fieldnode *    link;     /* linked field chain         */
  struct formnode *     form;     /* containing form            */
  struct typenode *     type;     /* field type                 */
  void *                arg;      /* argument for type          */
  char *                buf;      /* field buffers              */
  void *                usrptr;   /* user pointer               */
} FIELD;


typedef struct formnode {
  unsigned short        status;   /* flags                      */
  short                 rows;     /* size in rows               */
  short                 cols;     /* size in cols               */
  int                   currow;   /* current row in field window*/
  int                   curcol;   /* current col in field window*/
  int                   toprow;   /* in scrollable field window */
  int                   begincol; /* in horiz. scrollable field */
  short                 maxfield; /* number of fields           */
  short                 maxpage;  /* number of pages            */
  short                 curpage;  /* index into page            */
  Form_Options          opts;     /* options                    */
  WINDOW *              win;      /* window                     */
  WINDOW *              sub;      /* subwindow                  */
  WINDOW *              w;        /* window for current field   */
  FIELD **              field;    /* field [maxfield]           */
  FIELD *               current;  /* current field              */
  _PAGE *               page;     /* page [maxpage]             */
  void *                usrptr;   /* user pointer               */

  void                  (*forminit)(struct formnode *);
  void                  (*formterm)(struct formnode *);
  void                  (*fieldinit)(struct formnode *);
  void                  (*fieldterm)(struct formnode *);

} FORM;


#define O_VISIBLE               (0x0001)
#define O_ACTIVE                (0x0002)
#define O_PUBLIC                (0x0004)
#define O_EDIT                  (0x0008)
#define O_WRAP                  (0x0010)
#define O_BLANK                 (0x0020)
#define O_AUTOSKIP              (0x0040)
#define O_NULLOK                (0x0080)
#define O_PASSOK                (0x0100)
#define O_STATIC                (0x0200)


#define O_NL_OVERLOAD           (0x0001)
#define O_BS_OVERLOAD           (0x0002)



#define REQ_NEXT_PAGE    (KEY_MAX + 1)  /* move to next page            */
#define REQ_PREV_PAGE    (KEY_MAX + 2)  /* move to previous page        */
#define REQ_FIRST_PAGE   (KEY_MAX + 3)  /* move to first page           */
#define REQ_LAST_PAGE    (KEY_MAX + 4)  /* move to last page            */

#define REQ_NEXT_FIELD   (KEY_MAX + 5)  /* move to next field           */
#define REQ_PREV_FIELD   (KEY_MAX + 6)  /* move to previous field       */
#define REQ_FIRST_FIELD  (KEY_MAX + 7)  /* move to first field          */
#define REQ_LAST_FIELD   (KEY_MAX + 8)  /* move to last field           */
#define REQ_SNEXT_FIELD  (KEY_MAX + 9)  /* move to sorted next field    */
#define REQ_SPREV_FIELD  (KEY_MAX + 10) /* move to sorted prev field    */
#define REQ_SFIRST_FIELD (KEY_MAX + 11) /* move to sorted first field   */
#define REQ_SLAST_FIELD  (KEY_MAX + 12) /* move to sorted last field    */
#define REQ_LEFT_FIELD   (KEY_MAX + 13) /* move to left to field        */
#define REQ_RIGHT_FIELD  (KEY_MAX + 14) /* move to right to field       */
#define REQ_UP_FIELD     (KEY_MAX + 15) /* move to up to field          */
#define REQ_DOWN_FIELD   (KEY_MAX + 16) /* move to down to field        */

#define REQ_NEXT_CHAR    (KEY_MAX + 17) /* move to next char in field   */
#define REQ_PREV_CHAR    (KEY_MAX + 18) /* move to prev char in field   */
#define REQ_NEXT_LINE    (KEY_MAX + 19) /* move to next line in field   */
#define REQ_PREV_LINE    (KEY_MAX + 20) /* move to prev line in field   */
#define REQ_NEXT_WORD    (KEY_MAX + 21) /* move to next word in field   */
#define REQ_PREV_WORD    (KEY_MAX + 22) /* move to prev word in field   */
#define REQ_BEG_FIELD    (KEY_MAX + 23) /* move to first char in field  */
#define REQ_END_FIELD    (KEY_MAX + 24) /* move after last char in fld  */
#define REQ_BEG_LINE     (KEY_MAX + 25) /* move to beginning of line    */
#define REQ_END_LINE     (KEY_MAX + 26) /* move after last char in line */
#define REQ_LEFT_CHAR    (KEY_MAX + 27) /* move left in field           */
#define REQ_RIGHT_CHAR   (KEY_MAX + 28) /* move right in field          */
#define REQ_UP_CHAR      (KEY_MAX + 29) /* move up in field             */
#define REQ_DOWN_CHAR    (KEY_MAX + 30) /* move down in field           */

#define REQ_NEXT_CHAR    (KEY_MAX + 17) /* move to next char in field   */
#define REQ_PREV_CHAR    (KEY_MAX + 18) /* move to prev char in field   */
#define REQ_NEXT_LINE    (KEY_MAX + 19) /* move to next line in field   */
#define REQ_PREV_LINE    (KEY_MAX + 20) /* move to prev line in field   */
#define REQ_NEXT_WORD    (KEY_MAX + 21) /* move to next word in field   */
#define REQ_PREV_WORD    (KEY_MAX + 22) /* move to prev word in field   */
#define REQ_BEG_FIELD    (KEY_MAX + 23) /* move to first char in field  */
#define REQ_END_FIELD    (KEY_MAX + 24) /* move after last char in fld  */
#define REQ_BEG_LINE     (KEY_MAX + 25) /* move to beginning of line    */
#define REQ_END_LINE     (KEY_MAX + 26) /* move after last char in line */
#define REQ_LEFT_CHAR    (KEY_MAX + 27) /* move left in field           */
#define REQ_RIGHT_CHAR   (KEY_MAX + 28) /* move right in field          */
#define REQ_UP_CHAR      (KEY_MAX + 29) /* move up in field             */
#define REQ_DOWN_CHAR    (KEY_MAX + 30) /* move down in field           */

#define REQ_NEW_LINE     (KEY_MAX + 31) /* insert/overlay new line      */
#define REQ_INS_CHAR     (KEY_MAX + 32) /* insert blank char at cursor  */
#define REQ_INS_LINE     (KEY_MAX + 33) /* insert blank line at cursor  */
#define REQ_DEL_CHAR     (KEY_MAX + 34) /* delete char at cursor        */
#define REQ_DEL_PREV     (KEY_MAX + 35) /* delete char before cursor    */
#define REQ_DEL_LINE     (KEY_MAX + 36) /* delete line at cursor        */
#define REQ_DEL_WORD     (KEY_MAX + 37) /* delete line at cursor        */
#define REQ_CLR_EOL      (KEY_MAX + 38) /* clear to end of line         */
#define REQ_CLR_EOF      (KEY_MAX + 39) /* clear to end of field        */
#define REQ_CLR_FIELD    (KEY_MAX + 40) /* clear entire field           */
#define REQ_OVL_MODE     (KEY_MAX + 41) /* begin overlay mode           */
#define REQ_INS_MODE     (KEY_MAX + 42) /* begin insert mode            */
#define REQ_SCR_FLINE    (KEY_MAX + 43) /* scroll field forward a line  */
#define REQ_SCR_BLINE    (KEY_MAX + 44) /* scroll field backward a line */
#define REQ_SCR_FPAGE    (KEY_MAX + 45) /* scroll field forward a page  */
#define REQ_SCR_BPAGE    (KEY_MAX + 46) /* scroll field backward a page */
#define REQ_SCR_FHPAGE   (KEY_MAX + 47) /* scroll field forward  half page */
#define REQ_SCR_BHPAGE   (KEY_MAX + 48) /* scroll field backward half page */
#define REQ_SCR_FCHAR    (KEY_MAX + 49) /* horizontal scroll char          */
#define REQ_SCR_BCHAR    (KEY_MAX + 50) /* horizontal scroll char          */
#define REQ_SCR_HFLINE   (KEY_MAX + 51) /* horizontal scroll line          */
#define REQ_SCR_HBLINE   (KEY_MAX + 52) /* horizontal scroll line          */
#define REQ_SCR_HFHALF   (KEY_MAX + 53) /* horizontal scroll half line     */
#define REQ_SCR_HBHALF   (KEY_MAX + 54) /* horizontal scroll half line     */

#define REQ_VALIDATION   (KEY_MAX + 55) /* validate field               */
#define REQ_NEXT_CHOICE  (KEY_MAX + 56) /* display next field choice    */
#define REQ_PREV_CHOICE  (KEY_MAX + 57) /* display prev field choice    */

#define MIN_FORM_COMMAND (KEY_MAX + 1)  /* used by form_driver          */
#define MAX_FORM_COMMAND (KEY_MAX + 57) /* used by form_driver          */

#ifndef E_POSTED
#define E_OK                    (0)
#define E_SYSTEM_ERROR          (-1)
#define E_BAD_ARGUMENT          (-2)
#define E_POSTED                (-3)
#define E_CONNECTED             (-4)
#define E_BAD_STATE             (-5)
#define E_NO_ROOM               (-6)
#define E_NOT_POSTED            (-7)
#define E_UNKNOWN_COMMAND       (-8)
#define E_NO_MATCH              (-9)
#define E_NOT_SELECTABLE        (-10)
#define E_NOT_CONNECTED         (-11)
#define E_REQUEST_DENIED        (-12)
#define E_INVALID_FIELD         (-13)
#define E_CURRENT               (-14)
#endif


       int A4GL_form_set_current_field(FORM *form, FIELD *field);
       FIELD *A4GL_form_current_field(const FORM *);
       int A4GL_form_set_form_page(FORM *form, int n);
       int A4GL_form_form_page(const FORM *form);
       int A4GL_form_dynamic_field_info(const FIELD *field, int *rows, int *cols,int *max);
       int A4GL_form_set_field_fore(FIELD *field, chtype attr);
       chtype A4GL_form_field_fore(const FIELD *field);
       int A4GL_form_set_field_back(FIELD *field, chtype attr);
       chtype A4GL_form_field_back(const FIELD *field);
       int  A4GL_form_set_field_buffer(FIELD  *field,  int  buf, const char *value);
       char *A4GL_form_field_buffer(const FIELD *field, int buffer);
       int A4GL_form_set_field_status(FIELD *field, bool status);
       bool A4GL_form_field_status(const FIELD *field);
       int A4GL_form_set_max_field(FIELD *field, int max);
       int A4GL_form_set_field_opts(FIELD *field, OPTIONS opts);
       int A4GL_form_field_opts_on(FIELD *field, OPTIONS opts);
       int A4GL_form_field_opts_off(FIELD *field, OPTIONS opts);
       OPTIONS A4GL_form_field_opts(const FIELD *field);
       int A4GL_form_set_field_userptr(FIELD *field, void*userptr);
       void *A4GL_form_field_userptr(const FIELD *field);
       int A4GL_form_form_driver(FORM *form, int c);
       int A4GL_form_set_form_userptr(FORM *form, void *userptr);
       void* A4GL_form_form_userptr(const FORM *form);
       FORM *A4GL_form_new_form(FIELD **fields);
       int A4GL_form_free_form(FORM *form);
       int A4GL_form_pos_form_cursor(FORM *form);
       int A4GL_form_post_form(FORM *form);
       int A4GL_form_unpost_form(FORM *form);
       int A4GL_form_set_form_win(FORM *form, WINDOW *win);
       WINDOW *A4GL_form_form_win(const FORM *form);
       int A4GL_form_set_form_sub(FORM *form, WINDOW *sub);
       WINDOW *A4GL_form_form_sub(const FORM *form);
       int A4GL_form_scale_form(const FORM *form, int *rows, int *columns);
       int A4GL_form_set_new_page(FIELD *field, bool new_page_flag);
       bool A4GL_form_new_page(const FIELD *field);
       FIELD *A4GL_form_new_field(int height, int width, int toprow, int leftcol, int offscreen, int nbuffers);
