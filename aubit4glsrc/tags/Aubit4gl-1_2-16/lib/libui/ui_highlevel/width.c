#include <stdlib.h>
#include "a4gl_libaubit4gl.h"
#include "hl_proto.h"
#include "a4gl_lib_ui_int.h"
#include "a4gl_API_ui_lib.h"
#include "a4gl_API_lowlevel.h"
#include "formdriver.h"
#include <wchar.h>

#ifdef WIDEC
#include <wchar.h>
static wchar_t *wc_strdup (char *buff);
static int wc_char_len (wchar_t * s);
static wchar_t *wc_col_width (wchar_t * s);
static wchar_t *wc_byte_width (wchar_t * s);
static char *wc_to_str (char *s, wchar_t * src, int char_size);
void A4GL_LL_wadd_wchar_xy_col (void *win, int x, int y, int oattr, wchar_t ch, int curr_width, int curr_height);
#endif
//void A4GL_LL_wadd_char_xy_col_w (void *win, int x, int y, int ch, int curr_width, int curr_height, int iscurrborder, int currwinno);

void A4GL_wprintw_internal (void *win, int attr, int x, int y, char *buff,
			    int pfunc, int curr_width, int curr_height,
			    int iscurrborder, int currwinno);

void
A4GL_wprintw_internal (void *win, int attr, int x, int y, char *buff,
		       int pfunc, int curr_width, int curr_height,
		       int iscurrborder, int currwinno)
{
  int a;
  unsigned char c;

#ifdef WIDEC
  {
    int len;
    wchar_t *wp;
    int w;
    wp = wc_strdup (buff);
    len = wc_char_len (wp);

    A4GL_debug ("len=%d\n", len);
    if (len == 0)
      return;
    if (len == -1)
      {
	A4GL_debug ("Invalid long string!");
	// We'll try anyway...
	for (a = 0; a < strlen (buff); a++)
	  {
	    A4GL_debug ("Printing wide character %d - w=%d (%s)\n", a, w,
			buff);
	    if (pfunc == 0)
	      A4GL_LL_wadd_wchar_xy_col (win, x, y, attr, buff[a],
					 curr_width, curr_height);
	    else
	      A4GL_LL_wadd_wchar_xy_col_w (win, x, y, attr, buff[a],
					   curr_width, curr_height);
	  }

	return;

      }
    for (a = 0; a < len; a++)
      {
	char buff[256];
	w = wcwidth (wp[a], 4);
	if (w < 0)
	  break;
	memset (buff, 0, 255);
	wc_single_to_str (buff, wp[a]);
	A4GL_debug ("Printing wide character %d - w=%d (%s)\n", a, w, buff);
	if (pfunc == 0)
	  A4GL_LL_wadd_wchar_xy_col (win, x, y, attr, wp[a]);
	else
	  A4GL_LL_wadd_wchar_xy_col_w (win, x, y, attr, wp[a]);

	x += w;
      }
    free (wp);
    A4GL_LL_screen_update ();
  }

#else
  for (a = 0; a < strlen (buff); a++)
    {

      if (pfunc == 0)
	{
	  c = buff[a];
	  //A4GL_debug ("Add1 : %x ", c);
	  A4GL_LL_wadd_char_xy_col (win, x, y, c | (attr & 0xffffff00),
				    curr_width, curr_height, iscurrborder,
				    currwinno);
	}
      else
	{
	  //A4GL_debug ("Add2");
	  c = buff[a];
	  A4GL_LL_wadd_char_xy_col_w (win, x, y, c | (attr & 0xffffff00),
				      curr_width, curr_height, iscurrborder,
				      currwinno);
	}
      x++;
    }
#endif

}




void
A4GL_wprintw (void *win, int attr, int x, int y, int cw, int ch, int cb,
	      int currwinno, char *fmt, ...)
{
  va_list args;
  unsigned char buff[2048];
  //A4GL_chkwin ();
  va_start (args, fmt);
  memset (buff, 0, sizeof (buff));
  VSNPRINTF ((char *)buff, sizeof (buff) - 1, fmt, args);

  buff[2047] = 0;
  A4GL_debug ("wprintw : x=%d", x);
  A4GL_debug ("wprintw : y=%d", y);
  A4GL_debug ("wprintw : buff=%s", buff);
  A4GL_debug ("wprintw : attr=%x", attr);
  A4GL_set_status (0, 0);
  A4GL_wprintw_internal (win, attr, x, y, (char *)buff, 0, cw, ch, cb, currwinno);
}




/* This is a bodge - fix it later... */
void
A4GL_wprintw_window (void *win, int attr, int x, int y, int cw, int ch,
		     int cb, int currwinno, char *fmt, ...)
{
  va_list args;
  unsigned char buff[2048];
  //A4GL_chkwin ();
  A4GL_debug ("A4GL_wprintw_window");
  va_start (args, fmt);
  vsprintf ((char *)buff, fmt, args);
  A4GL_debug ("wprintw : %d %d   '%s' attr=%x", x, y, buff, attr);
  A4GL_set_status (0, 0);
  A4GL_wprintw_internal (win, attr, x, y, (char *)buff, 1, cw, ch, cb, currwinno);
}




#ifdef WIDEC

/* Is a string convertible to a wide string ? */
int
A4GL_WC_valid_string (char *buff)
{
  wchar_t *wp;
  wp = wc_strdup (buff);
  if (wp == 0)
    return 0;
  free (wp);
  return 1;
}



/* Convert a string to a wide string - with its space allocated */
static wchar_t *
wc_strdup (char *buff)
{
  int len;
  int n;
  wchar_t *wp;
  len = mbstowcs (NULL, buff, 0);
  if (len <= 0)
    {
      return 0;
    }
  n = (len + 10) * sizeof (wchar_t);
  wp = (wchar_t *) acl_malloc2 (n);
  len = mbstowcs (wp, buff, n);
  wp[len] = 0;
  if (len)
    return wp;
  free (wp);
  return 0;
}


/* Get the number of individual characters (glyphs) in a wide string */
static int
wc_char_len (wchar_t * s)
{
  int a;
  if (s == 0)
    return -1;
  for (a = 0; s[a]; a++);
  return a;
}

/* Get the number of columns it would take to display a wide string */
static wchar_t *
wc_col_width (wchar_t * s)
{
  return wcswidth (s, 9999);
}



/* Get the number of bytes it would take to store a wide string as a normal string */
static wchar_t *
wc_byte_width (wchar_t * s)
{
  static char buff[2000];
  char *ptr;
  ptr = wc_to_str (buff, s, 2000);
  if (ptr)
    return strlen (ptr);
  return -1;
}



/* Convert a wide string to a normal string */
static char *
wc_to_str (char *s, wchar_t * src, int char_size)
{
  int l;
  l = wcstombs (s, src, char_size);
  if (l)
    return s;

  return 0;
}

/* Convert a wide string to a normal string */
static char *
wc_single_to_str (char *s, wchar_t src)
{
  int l;
  wchar_t buff[2];
  buff[0] = src;
  buff[1] = 0;
  l = wcstombs (s, buff, 16);
  if (l)
    return s;
  return 0;
}


#endif
