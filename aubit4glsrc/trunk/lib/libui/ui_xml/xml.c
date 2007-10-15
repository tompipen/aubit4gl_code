#include "a4gl_libaubit4gl.h"
#include "comms.h"
#include "uilib.h"

#include <stdarg.h>
int mn_id = 0;
struct s_windows
{
  int w, h, border;
  char name[100];
  int visible;
  //struct s_form_dets *form;
  //struct s_form_attr winattr;
};
#define MAXWIN 1000
struct s_windows *win_stack[MAXWIN];
int win_stack_cnt = 0;
int XML_A4GL_assertion (int n, char *s);


#define niy() A4GL_niy((char *)__PRETTY_FUNCTION__)

int
A4GL_win_stack_cnt (void)
{
  return win_stack_cnt;
}

int
A4GL_niy (char *func)
{
  char buff[245];
  sprintf (buff, "Not implemented: %s", func);
  XML_A4GL_assertion (1, buff);
  return 0;
}


static void
A4GL_XML_opening_form_xml (char *formname, char *formfile, char *fbuff)
{
  int a;
  suspend_flush(1);
  send_to_ui ("<XMLFORM NAME=\"%s\" FILE=\"%s\">", formname, formfile);
  for (a = 0; a < strlen (fbuff); a += 256)
    {
      char b[300];
      strncpy (b, &fbuff[a], 256);
      b[256] = 0;
      send_to_ui ("%s", uilib_xml_escape (b));
    }
  send_to_ui ("</XMLFORM>");
  suspend_flush(-1);
flush_ui();
}

static int
A4GL_XML_opening_form (char *formfile, char *formname)
{
  FILE *f;
  char *fbuff;
  char buff[2000];
  char buff_formname[2000];
  strcpy (buff, formfile);
  A4GL_trim (buff);
  strcpy (buff_formname, formname);
  A4GL_trim (buff_formname);
  strcat (buff, ".xml");
  f = A4GL_open_file_dbpath (buff);

  if (f)
    {
      long l;
      fseek (f, 0, SEEK_END);
      l = ftell (f);
      rewind (f);
      fbuff = malloc (l + 1);
      fread (fbuff, l, 1, f);
      fbuff[l] = 0;
      fclose (f);
      A4GL_XML_opening_form_xml (buff_formname, formfile, fbuff);
      free (fbuff);
      return 1;
    }
  else
    {
      return 0;
    }
}



void *
A4GL_win_stack (struct s_windows *w, char *name, int op)
{
  int a;
  int b;

  if (op == '^')
    {
      A4GL_win_stack (w, name, '+');
      A4GL_win_stack (w, name, '-');
      return 0;
    }

  if (w == 0)
    {
      for (a = 0; a < MAXWIN; a++)
	{
	  if (win_stack[a] == 0)
	    continue;

	  if (win_stack[a]->name)
	    {

	      if (A4GL_aubit_strcasecmp (name, win_stack[a]->name) == 0)
		{
		  w = win_stack[a];
		  break;
		}
	    }
	}
    }

  if (w == 0)
    {
      printf ("**** WINDOW NOT FOUND *****");
      return 0;
    }


  A4GL_debug ("win_stack : %p %c", w, op);

  if (op == '+')
    {
      win_stack[win_stack_cnt++] = w;
    }

  if (op == '-')
    {
      for (a = 0; a < win_stack_cnt; a++)
	{
	  if (win_stack[a] == w)
	    {
	      win_stack[a] = 0;
	      for (b = a + 1; b < win_stack_cnt; b++)
		{
		  win_stack[b - 1] = win_stack[b];
		}
	      win_stack_cnt--;
	      A4GL_debug ("win_stack_cnt=%d", win_stack_cnt);
	      break;
	    }
	}


    }

  return w;

}


void
add_window (char *s, int w, int h, int border)
{
  struct s_windows *win;
  win = malloc (sizeof (struct s_windows));
  strcpy (win->name, s);
  win->w = w;
  win->h = h;
  win->border = border;
  win->visible = 1;
  A4GL_win_stack (win, s, '+');
}



int
UILIB_A4GL_cr_window_form (char *name, int iswindow, int form_line,
			   int error_line, int prompt_line, int menu_line,
			   int border, int comment_line, int message_line,
			   int attrib,char *text, char *style)
{
//int rval;
  char *fname;
  int x;
  int y;
  struct s_form_dets *form;
  fname = A4GL_char_pop ();
  x = A4GL_pop_int ();
  y = A4GL_pop_int ();
if (style==0) style="";
if (text==0) text="";

  A4GL_trim (fname);
// Can we find a pregenerated XML form ? 
  if (!A4GL_XML_opening_form (fname, name))
    {
      // Nope - lets send a non-xml form instead..
      // this will callback to our UILIB_A4GL_read_metrics function..
      send_to_ui
	("<OPENWINDOWWITHFORM WINDOW=\"%s\" X=\"%d\" Y=\"%d\" ATTRIBUTE=\"%d\" ", name, x, y, attrib);
	send_to_ui(" TEXT=\"%s\" STYLE=\"%s\" ERROR_LINE=\"%d\" PROMPT_LINE=\"%d\" MENU_LINE=\"%d\" BORDER=\"%d\" COMMENT_LINE=\"%d\" MESSAGE_LINE=\"%d\"", text, style, error_line, prompt_line,  menu_line, border,  comment_line,  message_line);
	send_to_ui(">");
      send_to_ui ("<FORM>");
      form = A4GL_read_form (fname, name);
      send_to_ui ("</FORM>");
      send_to_ui ("</OPENWINDOWWITHFORM>");
    }
  else
    {
      send_to_ui
	("<OPENWINDOWWITHFORM WINDOW=\"%s\" X=\"%d\" Y=\"%d\" ATTRIBUTE=\"%d\" SOURCE=\"%s\"",
	 name, x, y, attrib, fname);
	send_to_ui(" TEXT=\"%s\" STYLE=\"%s\" ERROR_LINE=\"%d\" PROMPT_LINE=\"%d\" MENU_LINE=\"%d\" BORDER=\"%d\" COMMENT_LINE=\"%d\" MESSAGE_LINE=\"%d\"", text, style, error_line, prompt_line,  menu_line, border,  comment_line,  message_line);


	send_to_ui("/>");
    }



  return 0;
}

int
UILIB_A4GL_disp_fields_ap (int n, int attr, va_list * ap)
{
  int rval;
  char *field_list = "field_list";
  char **args;
  char *argp;
  int a;

  args = malloc (sizeof (char *) * n);

  for (a = 0; a < n; a++)
    {
      args[a] = A4GL_char_pop ();
    }
  send_to_ui ("<DISPLAYTO ATTRIBUTE=\"%d\">", attr);
  send_to_ui ("<FIELDLIST>");

  while ((argp = va_arg (*ap, char *)))
    {
      int i;
      i = va_arg (*ap, int);
      A4GL_trim (argp);
      if (i == 1)
	{
	  send_to_ui ("<FIELD NAME=\"%s\"/>", argp);
	}
      else
	{
	  send_to_ui ("<FIELD NAME=\"%s[%d]\"/>", argp, i);
	}
    }
  send_to_ui ("</FIELDLIST>");

  send_to_ui ("<VALUES>", attr, field_list);

  for (a = n - 1; a >= 0; a--)
    {
      send_to_ui ("<TEXT>%s</TEXT>", uilib_xml_escape (args[a]));
      free (args[a]);
    }
  free (args);
  send_to_ui ("</VALUES></DISPLAYTO>");
  return rval;
}

int
UILIB_A4GL_disp_form_fields_ap (int n, int attr, char *formname, va_list * ap)
{
  int rval;
  niy ();
  return rval;
}

int
UILIB_A4GL_open_form (char *name)
{
  char *s;
  char buff[300];
  struct s_form_dets *form;

  s = A4GL_char_pop ();
  strncpy (buff, s, 256);
  buff[255] = 0;
  A4GL_trim (buff);
  A4GLSQL_set_status (0, 0);


// Can we find a pregenerated XML form ? 
  if (!A4GL_XML_opening_form (buff, name))
    {
      // Nope - lets send a non-xml form instead..
      // this will callback to our UILIB_A4GL_read_metrics function..
      send_to_ui ("<OPENFORM FORM=\"%s\">", name, buff);
      send_to_ui ("<FORM>");
      form = A4GL_read_form (buff, name);
      send_to_ui ("</FORM>");
      send_to_ui ("</OPENFORM>");
    }
  else
    {
      send_to_ui ("<OPENFORM FORM=\"%s\" SOURCE=\"%s\"/>", name, buff);
    }

  free (s);
  return 0;			// Success...
}

void
UILIB_A4GL_close_form (char *name)
{
  send_to_ui ("<CLOSEFORM FORM=\"%s\"/>", name);
}

int
UILIB_A4GL_disp_form (char *name, int attr)
{
  int rval = 0;
  send_to_ui ("<DISPLAYFORM FORM=\"%s\" ATTRIBUTE=\"%d\"/>", name, attr);
  return rval;
}

int
UILIB_A4GL_current_window (char *win_name)
{
  send_to_ui ("<CURRENTWINDOW WINDOW=\"%s\"/>", win_name);
  A4GL_win_stack (0, win_name, '^');
  return 1;
}

int
UILIB_aclfgl_fgl_drawbox (int n)
{
  int rval = 1;
  int x1, x2, x3, x4, x5;
  if (n == 4)
    {
      x1 = A4GL_pop_int ();
      x2 = A4GL_pop_int ();
      x3 = A4GL_pop_int ();
      x4 = A4GL_pop_int ();
      send_to_ui
	("<DRAWBOX arg1=\"%d\" arg2=\"%d\" arg3=\"%d\" arg4=\"%d\" />", x1,
	 x2, x3, x4);
    }
  if (n == 5)
    {
      x1 = A4GL_pop_int ();
      x2 = A4GL_pop_int ();
      x3 = A4GL_pop_int ();
      x4 = A4GL_pop_int ();
      x5 = A4GL_pop_int ();
      send_to_ui
	("<DRAWBOX arg1=\"%d\" arg2=\"%d\" arg3=\"%d\" arg4=\"%d\" arg5=\"%d\"/>",
	 x1, x2, x3, x4, x5);
    }

  return rval;
}


void *
UILIB_A4GL_new_menu_create_with_attr (char *title, int x, int y, int mn_type,
				      int help_no, char *comment, char *style,
				      char *image)
{
  static char mn[20] = "xml";
  static long ln = 0;

  ln++;
  A4GL_push_char (mn);
  A4GL_push_int (ln);
  A4GL_push_char (title);
  uilib_menu_start (3);
  mn_id = 0;

  return (void *) ln;
}

void
UILIB_A4GL_add_menu_option (void *menu, char *txt, char *keys_orig,
			    char *desc, int helpno, int attr)
{
  static long ln = 0;
  long context;
  char keys[2000];
  int len;
  strcpy (keys, keys_orig);
  ln = (long) menu;
  A4GL_push_char ("xml");
  A4GL_push_int (ln);
  uilib_get_context (2);
  context = A4GL_pop_long ();
  A4GL_push_int (context);
  mn_id++;

  A4GL_push_int (mn_id);
  A4GL_push_char (txt);

  if (strstr (keys, "||"))
    {
      int cnt;
      char a[100];
      char buff[3000] = "";
      int start = 0;

      int b = 0;
      len = strlen (keys);
      for (cnt = 0; cnt <= len; cnt++)
	{
	  if ((keys[cnt] == '|' && keys[cnt + 1] == '|') || keys[cnt] == 0)
	    {
	      keys[cnt] = 0;
	      if (keys[cnt] == '|')
		{
		  keys[cnt + 1] = ' ';
		}
	      b = A4GL_key_val (&keys[start]);
	      sprintf (a, "%d", b);
	      if (start)
		strcat (buff, ",");
	      strcat (buff, a);
	      start = cnt + 2;
	    }
	}
      A4GL_push_char (buff);


    }
  else
    {
      int a;
      char buff[200];
      A4GL_lrtrim (keys);
      a = A4GL_key_val (keys);
      if (a == -1)
	{
	  A4GL_push_char ("");
	}
      else
	{
	  sprintf (buff, "%d", a);
	  A4GL_push_char (buff);
	}
    }


  A4GL_push_char (desc);
  A4GL_push_int (helpno);

  uilib_menu_add (6);
}


void
UILIB_A4GL_finish_create_menu (void *menu)
{
  A4GL_push_char ("xml");
  A4GL_push_int ((long) menu);
  uilib_get_context (2);
  uilib_menu_initialised (1);
}

void
UILIB_A4GL_disp_h_menu (void *menu)
{
//niy();
}

int
UILIB_A4GL_menu_loop_v2 (void *menu, void *evt)
{
  int a;
  while (1)
    {
      A4GL_push_char ("xml");
      A4GL_push_int ((long) menu);
      uilib_get_context (2);
      uilib_menu_loop (1);
      a = A4GL_pop_int ();
      if (a == -1)
	continue;
      if (a == 0)
	continue;
      return a - 1;
      break;
    }
  return a;
}

void
UILIB_A4GL_next_option (void *menu, char *nextopt)
{
  long context;
  A4GL_push_char ("xml");
  A4GL_push_int ((long) menu);
  uilib_get_context (2);
  context = A4GL_pop_long ();
  A4GL_push_char (nextopt);
  A4GL_push_int (context);
  uilib_next_option (2);
  return;
}

int
UILIB_A4GL_free_menu (void *menu)
{
  int a;
  A4GL_push_char ("xml");
  A4GL_push_int ((long) menu);
  uilib_get_context (2);
  uilib_free_menu (1);
  a = A4GL_pop_int ();
  return a;

}

int
UILIB_A4GL_req_field_input (void *sv, char type, va_list * ap)
{
  int rval = 1;
  int context;
  struct s_field_name_list list;
  struct s_screenio *s;
  s = sv;
  A4GL_push_char ("XML");
  A4GL_push_int (((long) s) & 0xffffffff);
  uilib_get_context (2);
  context = A4GL_pop_int ();
  if (type == '+')
    {
      send_to_ui ("<NEXTFIELD CONTEXT=\"%d\" FIELD=\"NEXT\"/>", context);
      return 1;
    }
  if (type == '-')
    {
      send_to_ui ("<NEXTFIELD CONTEXT=\"%d\" FIELD=\"PREVIOUS\"/>", context);
      return 1;
    }
  if (type == '0')
    {
      send_to_ui ("<NEXTFIELD CONTEXT=\"%d\" FIELD=\"CURRENT\"/>", context);
      return 1;
    }


  A4GL_make_field_slist_from_ap (&list, ap);

  send_to_ui ("<NEXTFIELD CONTEXT=\"%d\" FIELD=\"%s[%d]\"/>", context,
	      list.field_name_list[0].fname, list.field_name_list[0].fpos);

  return rval;
}

int
UILIB_A4GL_req_field_input_array (void *sv, char type, va_list * ap)
{
  int rval = 1;
  struct s_inp_arr *arr;
  int context;
  struct s_field_name_list list;
  arr = sv;
  A4GL_push_char ("XML");
  A4GL_push_int (((long) arr) & 0xffffffff);
  uilib_get_context (2);
  context = A4GL_pop_int ();

  if (type == '+')
    {
      send_to_ui ("<NEXTFIELD CONTEXT=\"%d\" FIELD=\"NEXT\"/>", context);
      return 1;
    }
  if (type == '-')
    {
      send_to_ui ("<NEXTFIELD CONTEXT=\"%d\" FIELD=\"PREVIOUS\"/>", context);
      return 1;
    }
  if (type == '0')
    {
      send_to_ui ("<NEXTFIELD CONTEXT=\"%d\" FIELD=\"CURRENT\"/>", context);
      return 1;
    }


  A4GL_make_field_slist_from_ap (&list, ap);

  send_to_ui ("<NEXTFIELD CONTEXT=\"%d\" FIELD=\"%s[%d]\"/>", context,
	      list.field_name_list[0].fname, list.field_name_list[0].fpos);


  return rval;
}

int
UILIB_A4GL_menu_hide_ap (void *menu, va_list * ap)
{
  char *argp;
  int rval = 0;
  long context;
  A4GL_push_char ("xml");
  A4GL_push_int ((long) menu);
  uilib_get_context (2);
  context = A4GL_pop_long ();
  while ((argp = va_arg (*ap, char *)))
    {
      A4GL_trim (argp);
      send_to_ui ("<HIDEOPTION CONTEXT=\"%d\" OPTION=\"%s\"/>", context,
		  argp);
    }
  return rval;
}

int
UILIB_A4GL_menu_show_ap (void *menu, va_list * ap)
{
  char *argp;
  long context;
  A4GL_push_char ("xml");
  A4GL_push_int ((long) menu);
  uilib_get_context (2);
  context = A4GL_pop_long ();
  while ((argp = va_arg (*ap, char *)))
    {
      A4GL_trim (argp);
      send_to_ui ("<SHOWOPTION CONTEXT=\"%d\" OPTION=\"%s\"/>", context,
		  argp);
    }
  return 0;
}

void
UILIB_aclfgli_pr_message_internal (int attr, int wait, char *s)
{
  A4GL_push_char (s);
  A4GL_push_int (attr);
  uilib_message (2);
}

void
UILIB_A4GL_display_error (int attr, int wait)
{
  uilib_error (1);
}

void *
UILIB_A4GL_get_curr_form (int warn_if_no_form)
{
//fprintf(stderr,"Got a call to UILIB_A4GL_get_curr_form\n");
  return (void *) 1;
}

void
UILIB_A4GL_set_option_value_for_current_window (char type, long keyval)
{
  send_to_ui ("<OPTIONS TYPE=\"%c\" VALUE=\"%d\"/>", type, keyval);
}

long
UILIB_A4GL_get_option_value_for_current_window (char type)
{
  int rval;
  niy ();
  return rval;
}

int
UILIB_A4GL_widget_name_match (void *w, char *name)
{
  int rval;
  niy ();
  return rval;
}

int
UILIB_A4GL_gen_field_chars_ap (void *field_list, void *formdets, va_list * ap)
{
  char buff[20000];
  char smbuff[200];
  char *argp;
  char **f;
  strcpy (buff, "<FIELDLIST>");

  while ((argp = va_arg (*ap, char *)))
    {
      int i;
      i = va_arg (*ap, int);
      A4GL_trim (argp);
      if (i == 1)
	{
	  sprintf (smbuff, "<FIELD NAME=\"%s\"/>", argp);
	}
      else
	{
	  sprintf (smbuff, "<FIELD NAME=\"%s[%d]\"/>", argp, i);
	}
      strcat (buff, smbuff);
    }
  strcat (buff, "</FIELDLIST>");
  f = field_list;
  *f = buff;
  return 1;
}

int
UILIB_A4GL_gen_field_list_from_slist (void *field_listv, void *formdetsv,
				      void *listv)
{
  int rval;
  niy ();
  return rval;
}

/*
static char *
decode_keys (int a)
{
  int c;
  char *strings[] = {
    "CONTROL-A",
    "CONTROL-B",
    "CONTROL-C",
    "CONTROL-D",
    "CONTROL-E",
    "CONTROL-F",
    "CONTROL-G",
    "CONTROL-H",
    "CONTROL-I",
    "CONTROL-J",
    "CONTROL-K",
    "CONTROL-L",
    "CONTROL-M",
    "CONTROL-N",
    "CONTROL-O",
    "CONTROL-P",
    "CONTROL-Q",
    "CONTROL-R",
    "CONTROL-S",
    "CONTROL-T",
    "CONTROL-U",
    "CONTROL-V",
    "CONTROL-W",
    "CONTROL-X",
    "CONTROL-Y",
    "CONTROL-Z",
    "INTERRUPT",
    "ACCEPT",
    "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10",
    "F11", "F12", "F13", "F14", "F15", "F16", "F17", "F18", "F19", "F20",
    "F21", "F22", "F23", "F24", "F25", "F26", "F27", "F28", "F29", "F30",
    "F31", "F31", "F32", "F33", "F34", "F35", "F36",
    "ESCAPE",
    0
  };
  for (c = 0; strings[c]; c++)
    {
      if (a == A4GL_key_val (strings[c]))
        return strings[c];
    }
  printf("Keycode=%d\n",a);
  A4GL_assertion (1, "Unknown keycode");
  return "UNKNOWN";
}
*/

/*
static int *
get_key_codes (char *keys)
{
  char s[1024];
  char *k;
  char *k1;
  static int *x = 0;
  int xcnt = 0;


  if (x)
    {
      free (x);
      x = 0;
    }

  strcpy (s, keys);
  A4GL_trim (s);
  strcat (s, "||");
  A4GL_debug ("Chk keys %s\n", s);

  if (strcmp (keys, "->ANY") == 0)
    {
      x = acl_malloc2 (sizeof (int) * 2);
      x[0] = 0xffff;
      x[1] = 0;
      return x;
    }

  k = s;

  while (1)
    {
      k1 = k;
      k = strstr (k1, "||");
      if (k == 0)
        break;
      *k = 0;
      k += 2;
      xcnt++;
      x = realloc (x, sizeof (int) * xcnt);
      x[xcnt - 1] = A4GL_key_val (k1);
    }


  xcnt++;
  x = realloc (x, sizeof (int) * xcnt);
  x[xcnt - 1] = 0;
  return x;
}
*/


static char *
decode_event_id (int i)
{
  if (i == A4GL_EVENT_KEY_PRESS)
    {
      return "ONKEY";
    }

  if (i == A4GL_EVENT_BEFORE_FIELD)
    {
      return "BEFORE FIELD";
    }

  if (i == A4GL_EVENT_AFTER_FIELD)
    {
      return "AFTER FIELD";
    }

  if (i == A4GL_EVENT_BEF_ROW)
    {
      return "BEFORE ROW";
    }

  if (i == A4GL_EVENT_AFT_ROW)
    {
      return "AFTER ROW";
    }

  if (i == A4GL_EVENT_AFTER_INP)
    {
      return "AFTER INPUT";
    }

  if (i == A4GL_EVENT_BEFORE_INP)
    {
      return "BEFORE INPUT";
    }

  if (i == A4GL_EVENT_BEFORE_INSERT)
    {
      return "BEFORE INSERT";
    }
  if (i == A4GL_EVENT_AFTER_INSERT)
    {
      return "AFTER INSERT";
    }
  if (i == A4GL_EVENT_ON_ACTION)
    {
      return "ON ACTION";
    }


  A4GL_assertion (1, "UNKNOWN event ID");
  return "";

}


char **
get_field_codes (char *fields)
{
  char s[10240];
  char *k;
  char *k1;
  static char **x = 0;
  char *p;
  int xcnt = 0;

  if (x)
    {
      free (x);
      x = 0;
    }

  strcpy (s, fields);
  A4GL_trim (s);
  strcat (s, "||");
  k = s;

  while (1)
    {
      k1 = k;
      k = strstr (k1, "||");
      if (k == 0)
	break;
      *k = 0;
      k += 2;
      xcnt++;
      x = realloc (x, sizeof (int) * xcnt);
      p = strchr (k1, ',');
      if (p)
	*p = 0;
      x[xcnt - 1] = strdup (k1);
    }


  xcnt++;
  x = realloc (x, sizeof (char *) * xcnt);
  x[xcnt - 1] = 0;
  return x;
}


static void
dump_events (struct aclfgl_event_list *e)
{
  int a;
  int b;
  //int *keys;
  uilib_start_events (0);
  for (a = 0; e[a].event_type; a++)
    {
      char **fields;
      if (e[a].event_type == A4GL_EVENT_AFTER_INP_CLEAN)
	{
	  continue;
	}
      if (e[a].event_type == A4GL_EVENT_KEY_PRESS)
	{
	  //keys = get_key_codes (e[a].field);
	  A4GL_push_int (a + 1);
	  A4GL_push_char ("ONKEY");
	  A4GL_push_int (e[a].keycode);
	  uilib_event (3);
	  continue;
	}
      fields = get_field_codes (e[a].field);
      for (b = 0; fields[b]; b++)
	{
	  if (strlen (fields[b]) != 0)
	    {
	      A4GL_push_int (a + 1);
	      A4GL_push_char (decode_event_id (e[a].event_type));
	      A4GL_push_char (fields[b]);
	      uilib_event (3);
	      //printf ("CALL UILIB_EVENT(%d,\"%s\",%s)", a + 1,  decode_event_id (e[a].event_type), fields[b]);
	    }
	  else
	    {
	      if (e[a].event_type == A4GL_EVENT_BEFORE_INP
		  || e[a].event_type == A4GL_EVENT_AFTER_INP_CLEAN)
		{
		  //printc ("CALL UILIB_EVENT(%d,\"%s\",\"\")", a + 1, decode_event_id (event_id));
		  A4GL_push_int (a + 1);
		  A4GL_push_char (decode_event_id (e[a].event_type));
		  A4GL_push_char ("");
		  uilib_event (3);
		}
	      else
		{
		  A4GL_push_int (a + 1);
		  A4GL_push_char (decode_event_id (e[a].event_type));
		  A4GL_push_char ("");
		  uilib_event (3);
		  //printf ("CALL UILIB_EVENT(%d,\"%s\",\"\")", a + 1, decode_event_id (e[a].event_type));
		}
	    }
	}

    }

  uilib_end_events (0);
}

int
UILIB_A4GL_form_loop_v2 (void *s, int init, void *evt)
{
  struct s_screenio *sreal;
  sreal = s;

  if (sreal->fcntrl_cnt)
    {

    }


  if (init)
    {
      //A4GL_push_char("XML");
      //A4GL_push_int(((long)s) &0xffffffff);

      uilib_set_field_list_directly ((char *) sreal->field_list);


      if (sreal->mode == MODE_CONSTRUCT)
	{
	  int a;
	  int cno;
	  cno = 3;		// number of things pushed..
	  A4GL_push_char ("XML");
	  A4GL_push_int (((long) s) & 0xffffffff);
	  for (a = 0; a < sreal->novars; a++)
	    {
	      char buff[2000];
	      sprintf (buff, "%s.%s", sreal->constr[a].tabname,
		       sreal->constr[a].colname);
	      //printf("PUSHING : %s\n",buff);
	      A4GL_push_char (buff);
	      cno++;
	    }

	  A4GL_push_int (sreal->attrib);
	  uilib_construct_start (cno);
	  dump_events (evt);
	  uilib_construct_initialised (0);
	}
      else
	{
	  A4GL_push_char ("XML");
	  A4GL_push_int (((long) s) & 0xffffffff);
	  A4GL_push_int (sreal->mode & 0x1);
	  A4GL_push_int (sreal->attrib);
	  uilib_input_start (4);
	  dump_events (evt);
	  uilib_input_initialised (0);
	}

    }

  while (1)
    {
      int a;

      A4GL_push_char ("XML");
      A4GL_push_int (((long) s) & 0xffffffff);
      uilib_get_context (2);

      uilib_construct_loop (1);
      a = A4GL_pop_int ();
      printf ("Got a as %d\n", a);
      if (a == 0)
	continue;
      if (a == -1)
	continue;
      if (a == -100)
	{			// Accept...
	  if (A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt))
	    {
	      return A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt);
	    }
	}
      if (a == -101)
	{			// Interrupt
	  if (A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt))
	    {
	      return A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt);
	    }
	}
      return a;
    }

}

int
UILIB_A4GL_push_constr (void *s)
{
  int context;
  A4GL_push_char ("XML");
  A4GL_push_int (((long) s) & 0xffffffff);
  uilib_get_context (2);
  context = A4GL_pop_int ();

  uilib_construct_query (1);
  return 1;
}

int
UILIB_aclfgl_aclfgl_add_to_toolbar (int n)
{
  char *tag;
  int keyval, alwaysShow;
  char *toolTip;
  char *img;
  char *buttonText;

  if (n != 6)
    {
      A4GL_pop_args (n);
      return 0;
    }
  alwaysShow = A4GL_pop_int ();
  keyval = A4GL_pop_int ();
  toolTip = A4GL_char_pop ();
  img = A4GL_char_pop ();
  buttonText = A4GL_char_pop ();
  tag = A4GL_char_pop ();
  send_to_ui
    ("<ADDTOTOOLBAR TAG='%s' BUTTON='%s' IMAGE='%s' TOOLTOP='%s' KEYVAL='%d' ALWAYSSHOW='%d'/>",
     uilib_xml_escape (tag), uilib_xml_escape (buttonText),
     uilib_xml_escape (img), uilib_xml_escape (toolTip), keyval, alwaysShow);



  return 0;
}


void
UILIB_A4GL_display_internal (int x, int y, char *s, int a, int clr_line)
{
  if (x == -1 && y == -1)
    {
      send_to_ui ("<DISPLAY>%s</DISPLAY>", uilib_xml_escape (s));
    }
  else
    {
      send_to_ui
	("<DISPLAYAT X=\"%d\" Y=\"%d\" ATTRIBUTE=\"%d\">%s</DISPLAYAT>", x, y,
	 a, uilib_xml_escape (s));
    }
}

void
UILIB_A4GL_sleep_i ()
{
  int a;
  a = A4GL_pop_int ();
  printf ("Sleeping %d\n", a);
  sleep (a);
}


int
UILIB_A4GLUI_ui_init (int argc, char **argv)
{
  int a;
  if (!connect_ui ())
    {
      return 0;
    }

  for (a = 0; a < MAXWIN; a++)
    {
      win_stack[a] = 0;
    }

  add_window ("screen", 80, 24, 0);

  send_to_ui ("<PROGRAMSTARTUP PROGRAMNAME=\"%s\" ID=\"%d\"/>", argv[0],
	      get_ui_id ('r'));
  flush_ui ();
  return 1;
}

void
UILIB_A4GLUI_set_intr ()
{
  send_to_ui ("<SETINTR/>");
}

static void
A4GL_XML_opening_file_xml (char *filename, char *fbuff)
{
  int a;
  suspend_flush(1);
  send_to_ui ("<FILE NAME=\"%s\">", filename);
  for (a = 0; a < strlen (fbuff); a += 256)
    {
      char b[300];
      strncpy (b, &fbuff[a], 256);
      b[256] = 0;
      send_to_ui ("%s", uilib_xml_escape (b));
    }
  send_to_ui ("</FILE>");
  suspend_flush(-1);
	flush_ui();
}

static int
SendFile (char *filename)
{
  FILE *f;
  char *fbuff;
  char buff[2000];
  strcpy (buff, filename);
  A4GL_trim (buff);
  f = A4GL_open_file_dbpath (buff);

  if (f)
    {
      long l;
      fseek (f, 0, SEEK_END);
      l = ftell (f);
      rewind (f);
      fbuff = malloc (l + 1);
      fread (fbuff, l, 1, f);
      fbuff[l] = 0;
      fclose (f);
      A4GL_XML_opening_file_xml (filename, fbuff);
      free (fbuff);
      return 1;
    }
  else
    {
      return 0;
    }
}



void
UILIB_A4GL_direct_to_ui (char *what, char *string)
{
  if (strcmp (what, "SEND") == 0)
    {
      send_to_ui ("<UIDIRECT>%s</UIDIRECT>", uilib_xml_escape (string));
      return;
    }
  if (strcmp (what, "FILE") == 0)
    {
      SendFile (string);
      return;
    }

  if (strcmp (what, "dialog_setkeylabel") == 0)
    {
      //int a;
      //int params;
      char *p1;
      char *p2;
      p2 = A4GL_char_pop ();
      p1 = A4GL_char_pop ();
      send_to_ui ("<SETKEYLABEL DIALOG=\"1\" LABEL=\"%s\"  TEXT=\"%s\"/>", p1,
		  p2);
      free (p1);
      free (p2);
      return;
    }
  if (strcmp (what, "setkeylabel") == 0)
    {
      //int a;
      //int params;
      char *p1;
      char *p2;
      p2 = A4GL_char_pop ();
      p1 = A4GL_char_pop ();
      send_to_ui ("<SETKEYLABEL DIALOG=\"0\" LABEL=\"%s\"  TEXT=\"%s\"/>", p1,
		  p2);
      free (p1);
      free (p2);
      return;
    }

  printf ("unhandled direct to ui call\n");

}

void
UILIB_A4GL_ui_exit ()
{
  send_to_ui ("<PROGRAMSTOP EXITCODE=\"%d\" ID=\"%d\"/>", 0, get_ui_id ('r'));
  flush_ui ();
}

int
UILIB_A4GL_movewin (char *winname, int absol)
{
  int rval = 0;
  int x;
  int y;
  x = A4GL_pop_int ();
  y = A4GL_pop_int ();

  send_to_ui
    ("<MOVEWINDOW WINDOW=\"%s\"/ x=\"%d\" y=\"%d\" ABSOLUTE=\"%d\" >",
     winname, x, y, absol);

  return rval;
}

void
UILIB_A4GL_hide_window (char *winname)
{
  send_to_ui ("<HIDEWINDOW WINDOW=\"%s\"/>", winname);
  //A4GL_win_stack(0,win_name,'!');
}

void
UILIB_A4GL_show_window (char *winname)
{
  send_to_ui ("<SHOWWINDOW WINDOW=\"%s\"/>", winname);
  A4GL_win_stack (0, winname, '^');
}

int
UILIB_A4GL_fgl_infield_ap (void *inp, va_list * ap)
{
  int rval;

  return rval;
}

int
UILIB_A4GL_fgl_infield_ia_ap (void *inp, va_list * ap)
{
  int rval;
  niy ();
  return rval;
}

void
UILIB_A4GL_clr_window (char *winname)
{
  send_to_ui ("<CLEARWINDOW WINDOW=\"%s\"/>", winname);
}

void
UILIB_A4GL_remove_window (char *win_name)
{
  A4GL_del_pointer (win_name, WINCODE);
  send_to_ui ("<CLOSEWINDOW WINDOW=\"%s\"/>", win_name);
}

int
UILIB_A4GL_disp_arr_v2 (void *disp, void *ptr, char *srecname, int attrib,
			int scrollf, int scrollw, void *evt)
{
  int rval;
  niy ();
  return rval;
}

int
UILIB_A4GL_inp_arr_v2 (void *disp, int defs, char *srecname, int attrib,
		       int init, void *evt)
{
  int rval;
  niy ();
  return rval;
}

int
UILIB_A4GL_prompt_loop_v2 (void *prompt, int timeout, void *evt_list)
{
  int rval;
  niy ();
  return rval;
}

int
UILIB_A4GL_start_prompt (void *prompt, int ap, int c, int h, int af)
{
  int rval;
  niy ();
  return rval;
}

int
UILIB_A4GL_endis_fields_ap (int en_dis, va_list * ap)
{
  int rval;
  niy ();
  return rval;
}

void
UILIB_A4GL_clr_form (int to_defaults)
{
  send_to_ui ("<CLEARFORM TODEFAULTS=\"%d\"/>", to_defaults);
}

void
UILIB_A4GL_clr_form_fields (int to_defaults, char *defs)
{
  niy ();
}

void
UILIB_A4GL_clr_fields_ap (int to_defaults, va_list * ap)
{
  niy ();
}

int
UILIB_A4GL_fgl_getfldbuf_ap (void *inp, va_list * ap)
{
  int rval;
  niy ();
  return rval;
}

int
UILIB_A4GL_fgl_getfldbuf_ia_ap (void *inp, va_list * ap)
{
  int rval;
  niy ();
  return rval;
}

void
UILIB_A4GL_zrefresh ()
{
  flush_ui ();
}

void
UILIB_A4GL_gotolinemode ()
{
// Does nothing...
}

char *
UILIB_A4GL_get_currwin_name ()
{
  return win_stack[win_stack_cnt - 1]->name;

}

void
UILIB_A4GL_gui_run_til_no_more ()
{
  niy ();
}

int
UILIB_A4GL_read_fields (void *formdets)
{
  return 1;
}


int
UILIB_aclfgl_a4gl_set_page (int n)
{
  int rval;
  niy ();
  return rval;
}

int
UILIB_aclfgl_a4gl_get_page (int n)
{
  int rval;
  niy ();
  return rval;
}

int
UILIB_aclfgl_a4gl_run_gui (int nargs)
{
  int rval;
  niy ();
  return rval;
}

void
UILIB_A4GL_set_infield_from_stack ()
{
  niy ();
}

int
UILIB_A4GL_fgl_fieldnametoid (char *f, char *s, int n)
{
  int rval;
  niy ();
  return rval;
}

int
UILIB_aclfgl_set_window_title (int nargs)
{
  int rval;
  niy ();
  return rval;
}

void
UILIB_A4GL_finish_screenio (void *sio, char *siotype)
{
  A4GL_push_char ("XML");
  A4GL_push_int (((long) sio) & 0xffffffff);
  uilib_get_context (2);
  uilib_free_input (1);
}

void *
UILIB_A4GL_make_pixmap_gw (char *filename)
{
  void *rval;
  niy ();
  return rval;
}

int
UILIB_aclfgl_aclfgl_dump_screen (int n)
{
  int rval;
  send_to_ui ("<DUMPSCREEN>");
  return rval;
}

int
UILIB_A4GL_get_curr_width ()
{
  return win_stack[win_stack_cnt - 1]->w;
}

int
UILIB_A4GL_get_curr_height ()
{
  return win_stack[win_stack_cnt - 1]->h;
}

int
UILIB_A4GL_iscurrborder ()
{
  return win_stack[win_stack_cnt - 1]->border;
}

void
UILIB_A4GL_init_color (int n, int r, int g, int b)
{
  niy ();
}

int
UILIB_A4GL_fgl_fieldtouched_input_ap (void *input, va_list * ap)
{
  int rval;
  niy ();
  return rval;
}

int
UILIB_A4GL_fgl_fieldtouched_input_array_ap (void *input, va_list * ap)
{
  int rval;
  niy ();
  return rval;
}

void
UILIB_A4GL_acli_scroll_ap (int n, va_list * ap)
{
  niy ();
}

int
UILIB_A4GL_get_key (int timeout)
{
  int rval;
  niy ();
  return rval;
}

void *
UILIB_A4GL_create_menu (void *m, char *id, int mode, void *handler)
{
  void *rval;
  niy ();
  return rval;
}

void
UILIB_A4GL_reset_state_for (void *sio, char *siotype)
{
}

int
UILIB_aclfgl_fgl_set_arrline (int nparam)
{
  int rval;
  niy ();
  return rval;
}

int
UILIB_aclfgl_fgl_set_scrline (int nparam)
{
  int rval;
  niy ();
  return rval;
}

void
UILIB_A4GL_reset_delims (void *vformdets, void *field, char *delims)
{
  niy ();
}


int
UILIB_A4GL_screen_mode (int sm)
{
//int rval;
  return 1;
//return rval;
}



char *
UILIB_A4GL_ui_fgl_winquestion (char *title, char *text, char *def, char *pos,
			       char *icon, int danger, int winbutton)
{
//char* rval;
  int a;
  send_to_ui
    ("<WINQUESTION TITLE=\"%s\" TEXT=\"%s\" DEFAULT=\"%s\" POS=\"%s\" ICON=\"%s\" DANGER=\"%s\" BUTTON=\"%s\" />",
     title, uilib_xml_escape (text), def, pos, icon, danger, winbutton);
  send_to_ui ("<WAITFOREVENT/>");
  flush_ui ();
  a = get_event_from_ui ();
  if (a == -100)
    {
      return "cancel";
    }
  if (a == -101)
    {
      return "yes";
    }
  if (a == -102)
    {
      return "no";
    }
  return "InvalidReturnedValue";
}


int
XML_A4GL_assertion (int n, char *s)
{
  if (!n)
    return 0;
  fprintf (stderr, "************ ASSERTION FAILED %s\n", s);
  fflush (stdout);
  exit (4);
}

void *
UILIB_A4GL_cr_window (char *s, int iswindow, int form_line, int error_line,
		      int prompt_line, int menu_line, int border,
		      int comment_line, int message_line, int attrib,char *text, char *style)
{
//void* rval;
  int x, y, w, h;
  w = A4GL_pop_int ();
  h = A4GL_pop_int ();
  x = A4GL_pop_int ();
  y = A4GL_pop_int ();
if (style==0) style="";

  if (A4GL_has_pointer (s, WINCODE))
    {
#ifdef DEBUG
      {
	A4GL_debug ("Window already exists");
      }
#endif
      A4GL_set_errm (s);
      A4GL_exitwith ("Window already exists (%s)");
      return 0;
    }

  A4GL_add_pointer (s, WINCODE, (void *) 1);	// Just some value - maybe later we'll do something useful with it...
  send_to_ui
    ("<CREATEWINDOW NAME=\"%s\" X=\"%d\" Y=\"%d\" W=\"%d\" H=\"%d\" FORMLINE=\"%d\" ERRORLINE=\"%d\" PROMPTLINE=\"%d\" MENULINE=\"%d\" COMMENTLINE=\"%d\" MESSAGELINE=\"%d\" BORDER=\"%d\" ATTRIBUTE=\"%d\" STYLE=\"%s\" TEXT=\"%s\" />",
     s, x, y, w, h, form_line, error_line, prompt_line, menu_line,
     comment_line, message_line, border, attrib,style,text);


  return (void *) 1;
}



int
UILIB_A4GL_set_fields (void *sio)
{
  return 1;
}

void
UILIB_A4GL_add_menu_timeout (void *menu, char timeout_type, int timeoutlen,
			     int cmd_no_on_timeout, long *timeoutvar)
{
  static long ln = 0;
  long context;
  ln = (long) menu;
  A4GL_push_char ("xml");
  A4GL_push_int (ln);
  uilib_get_context (2);
  context = A4GL_pop_long ();
  mn_id++;
  send_to_ui
    ("<MENUTIMEOUT CONTEXT=\"%d\" ID=\"%d\" CMD_NO=\"%d\" TYPE=\"%c\" TIMEOUT=\"%d\" />",
     context, mn_id, cmd_no_on_timeout, timeoutlen);
}

void
UILIB_A4GL_add_menu_action (void *menu, char *action, int cmd_no_on_timeout)
{
  static long ln = 0;
  long context;
  ln = (long) menu;
  A4GL_push_char ("xml");
  A4GL_push_int (ln);
  uilib_get_context (2);
  context = A4GL_pop_long ();
  mn_id++;
  send_to_ui
    ("<MENUACTION CONTEXT=\"%d\" ID=\"%d\" ACTION=\"%s\" CMD_NO_TIMEOUT=\"%d\" />",
     context, mn_id, action, cmd_no_on_timeout);
}


static void
A4GL_make_label (int frow, int fcol, char *label)
{
  send_to_ui ("<LABEL ROW=\"%d\" COLUMN=\"%d\">%s</LABEL>", frow, fcol,
	      uilib_xml_escape (label));
}


static void
A4GL_make_field (int frow, int fcol, int rows, int cols, char *widget,
		 char *config, char *inc, void *id, char *tab_and_col,
		 char *action)
{
  send_to_ui
    ("<FIELD ROW=\"%d\" COLUMN=\"%d\" ROWS=\"%d\" COLS=\"%d\" WIDGET=\"%s\" CONFIG=\"%s\" INC=\"%s\" ID=\"%d\" TABCOL=\"%s\" ACTION=\"%s\"/>",
     frow, fcol, rows, cols, uilib_xml_escape (widget),
     uilib_xml_escape (config), uilib_xml_escape (inc), (long) id,
     uilib_xml_escape (tab_and_col), uilib_xml_escape (action));
}



static char *
A4GL_decode_str_fprop (struct_scr_field * fprop, int type)
{
  int b;
  if (fprop == 0)
    return 0;
  if (fprop->str_attribs.str_attribs_val == 0)
    return 0;
  for (b = 0; b < fprop->str_attribs.str_attribs_len; b++)
    {
      if (fprop->str_attribs.str_attribs_val[b].type == type)
	{
	  return fprop->str_attribs.str_attribs_val[b].value;
	}
    }
  return "";
}

/**
 *  * Find fields
 *   *
 *    * @param f A pointer to a form describing strucutre.
 *     * @param metric_no The metric sequence number.
 *      * @return The metric number.
 *       */
static int
A4GL_find_fields_no_metric (struct_form * f, int metric_no)
{
  int a, b;
  A4GL_debug ("BB - Looking for metric : %d\n", metric_no);
  for (a = 0; a < f->fields.fields_len; a++)
    {
      for (b = 0; b < f->fields.fields_val[a].metric.metric_len; b++)
	{
	  if (f->fields.fields_val[a].metric.metric_val[b] == metric_no)
	    {
	      A4GL_debug ("Found metric : %d\n", f);
	      return a;
	    }
	}
    }
  A4GL_debug ("Metric not found %d", metric_no);
  return -1;
}


static int
A4GL_find_attrib_from_field (struct_form * f, int field_no)
{
  int a;
  A4GL_debug ("AA\n");
  A4GL_debug ("field_no=%d\n", field_no);
  if (field_no == -1)
    return -1;
  for (a = 0; a < f->attributes.attributes_len; a++)
    {
      if (f->attributes.attributes_val[a].field_no == field_no)
	{
	  A4GL_debug ("Found field %d @ %d - %s\n", field_no, a,
		      f->attributes.attributes_val[a].colname);
	  return a;
	}
    }
  A4GL_debug ("Not found\n");
  return -1;

}



static int
A4GL_find_attrib_from_metric (struct_form * f, int metric_no)
{
  return A4GL_find_attrib_from_field (f,
				      A4GL_find_fields_no_metric (f,
								  metric_no));
}

static char *
make_tab_and_col (char *t, char *c)
{
  static char buff[256];
  SPRINTF2 (buff, "%s.%s", t, c);
  return buff;
}


/**
 *
 * @todo Describe function
 *  @todo Validate the calls to A4GL_make_label that alocates space to a FIELD
 *  struct and assigns the pointer to integers.
 */
int
UILIB_A4GL_read_metrics (void *formdetsv)
{
  struct s_form_dets *formdets;
  int metric_no, n;
  char delims[3][2];
  char *widget;
  char *config;
  char *include;
  struct struct_scr_field *fprop = 0;
  char *action;

  formdets = formdetsv;
  delims[0][0] = formdets->fileform->delim[0];
  delims[1][0] = formdets->fileform->delim[1];
  delims[2][0] = formdets->fileform->delim[2];
  delims[0][1] = 0;
  delims[1][1] = 0;
  delims[2][1] = 0;
  n = formdets->fileform->metrics.metrics_len;
  A4GL_debug ("metrics len=%d", n);


  for (metric_no = 0; metric_no < n; metric_no++)
    {


      formdets->fileform->metrics.metrics_val[metric_no].pos_code = 0;
      A4GL_debug ("checking label %s\n",
		  formdets->fileform->metrics.metrics_val[metric_no].label);


      if (strlen (formdets->fileform->metrics.metrics_val[metric_no].label) !=
	  0)
	{
	  A4GL_make_label (formdets->fileform->metrics.metrics_val[metric_no].
			   y,
			   formdets->fileform->metrics.metrics_val[metric_no].
			   x,
			   formdets->fileform->metrics.metrics_val[metric_no].
			   label);
	}
      else
	{
	  int attr_no;
	  attr_no =
	    A4GL_find_attrib_from_metric (formdets->fileform, metric_no);
	  if (attr_no == -1)
	    continue;
	  widget = 0;
	  config = 0;
	  include = 0;
	  action = 0;
	  if (attr_no >= 0)
	    {
	      fprop = &formdets->fileform->attributes.attributes_val[attr_no];
	      A4GL_debug ("attr_no=%d fprop=%p", attr_no, fprop);

	      widget = A4GL_decode_str_fprop (fprop, FA_S_WIDGET);
	      config = A4GL_decode_str_fprop (fprop, FA_S_CONFIG);
	      include = 0;
	      if (A4GL_has_str_attribute (fprop, FA_S_INCLUDE))
		{
		  include = A4GL_get_str_attribute (fprop, FA_S_INCLUDE);
		}
	      else
		{
		  include = 0;
		}
	      action = 0;
	      if (A4GL_has_str_attribute (fprop, FA_S_ACTION))
		{
		  action = A4GL_get_str_attribute (fprop, FA_S_ACTION);
		}
	      else
		{
		  action = 0;
		}
	    }
	  else
	    {
	      widget = 0;
	      config = 0;
	      include = 0;
	      action = 0;
	    }

	  if (widget == 0)
	    widget = "";
	  if (config == 0)
	    config = "";
	  if (include == 0)
	    include = "";
	  if (action == 0)
	    action = "";



	  A4GL_make_field (formdets->fileform->metrics.
			   metrics_val[metric_no].y,
			   formdets->fileform->metrics.
			   metrics_val[metric_no].x,
			   formdets->fileform->metrics.
			   metrics_val[metric_no].h,
			   formdets->fileform->metrics.
			   metrics_val[metric_no].w, widget,
			   config, include, fprop,
			   make_tab_and_col (fprop->tabname,
					     fprop->colname), action);

	}

    }

  return 1;
}
