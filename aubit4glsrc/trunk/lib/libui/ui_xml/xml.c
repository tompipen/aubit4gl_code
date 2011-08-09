#include <stdarg.h>
#include "a4gl_libaubit4gl.h"
#include "comms.h"
#include "uilib.h"
#include "pipe.h"
#include "uilib/xml/attr.h"
#include "a4gl_API_ui_lib.h"
extern struct s_attr *last_attr;
static char *get_field_with_subscript_as_string(char *field, int i);
FILE *def_stderr = NULL;
char stderr_fname[2000]="";
char *set_current_display_delims = 0;

int generate_xml_forms=1; // Automatically generate XML form files where no XML file exists

void dump_form_labels(void) ;

#include "lib/libpacker/formxml/formxml.h"
static int last_w=1;
static int last_h=1;

#ifdef MOVED
char screen[200][200];



struct s_field
{
  int y;
  int x;
  int w;
  char *label;
  int field_start;

};

struct s_field *screen_convert_fields = 0;
int nfields = 0;
#endif


//void make_screen (struct_form * f);
char reading_form_id[200];
char reading_form_name[200];
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
int startingPrompt = 0;

static int get_inc_quotes (int a);

#define niy() A4GL_niy((char *)__PRETTY_FUNCTION__)
char *generate_construct_result (struct s_screenio *s);


static char *
ignull (char *s)
{
  if (s)
    return s;
  return "";

}

int UILIB_aclfgl_aclfgl_add_acs_mapping(int n) {
return 0;
}


static int set_reading_form(char *form_id, char *form_name) {
	//printf("%s %s\n",form_id, form_name);
	strcpy(reading_form_id, form_id);
	strcpy(reading_form_name, form_name);
	return 1;
}


static int
A4GL_niy (char *func)
{
  char buff[245];
  SPRINTF (buff, "Not implemented: %s", func);
  XML_A4GL_assertion (1, buff);
  return 0;
}


int exiting_context[100];
int exiting_context_state[100];
int exiting_context_cnt = 0;

char *getlastkey(void);

static void set_xml_lastkey(void) {
	char *ptr=getlastkey();
	if (ptr) {
		A4GL_set_last_key(A4GL_key_val(ptr));
	}
}

static void
clr_exiting_context (int n)
{
  int a;
  for (a = 0; a < exiting_context_cnt; a++)
    {
      if (exiting_context[a] == n)
	{
	  exiting_context[a] = -1;
	}
    }
}


static void
set_exiting_context (int n, int state)
{
  int a;
// Is it already set ? 
  for (a = 0; a < exiting_context_cnt; a++)
    {
      if (exiting_context[a] == n)
	{
	  exiting_context_state[a] = state;
	  return;
	}
    }


// Is there a gap to set it in ? 
  for (a = 0; a < exiting_context_cnt; a++)
    {
      if (exiting_context[a] == -1)
	{
	  exiting_context_state[a] = state;
	  exiting_context[a] = n;
	  return;
	}
    }

// Add it at the end...
  exiting_context_cnt++;
  exiting_context[exiting_context_cnt - 1] = n;
  exiting_context_state[exiting_context_cnt - 1] = state;
}


static int
isset_exiting_context (int n, int *state)
{
  int a;
  for (a = 0; a < exiting_context_cnt; a++)
    {
      if (exiting_context[a] == n)
	{
	  if (state)
	    *state = exiting_context_state[a];
	  return 1;
	}
    }
  return 0;
}


static void
A4GL_XML_opening_form_xml (char *formname, char *formfile, char *fbuff)
{
  //int a;
  char *buff;
char buff2[2000];
int len;
int l;
char *ptr;

  int cnt;
  send_to_ui ("<XMLFORM NAME=\"%s\" FILE=\"%s\">", formname, formfile);

  cnt=0;
  len=strlen(fbuff);
  A4GL_base64_encode(fbuff,len,&buff);
  l=strlen(buff);
  ptr=buff;
  
  while (cnt<l) {
	strncpy(buff2,ptr,256);
	buff2[256]=0;
  	send_to_ui_no_nl ("%s", buff2);
	cnt+=256;
	ptr+=256;
  }
free(buff);
/*
  for (a = 0; a < strlen (fbuff); a += 256)
    {
      char b[300];
      strncpy (b, &fbuff[a], 256);
      b[256] = 0;
      send_to_ui ("%s", uilib_xml_escape (b));
    }
*/
  send_to_ui ("</XMLFORM>");
}

static int
A4GL_XML_opening_form (char *formfile, char *formname,int append_xml)
{
  FILE *f;
  char *fbuff;
  char buff[2000];
  char buff_formname[2000];
  strcpy (buff, formfile);
  A4GL_trim (buff);
  strcpy (buff_formname, formname);
  A4GL_trim (buff_formname);

  last_h=1; last_w=1;
  if (append_xml) {
  	strcat (buff, ".xml");
  }
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
      //printf ("Unable to open file '%s'\n", buff);
      return 0;
    }
}



static void *
A4GL_win_stack (struct s_windows *w, char *name, int op)
{
  int a;
  int b;
//printf("Win_stack called with %p %s %c\n",w,name,op);
  if (op == '^')
    {
	A4GL_debug("win stack ^");
      A4GL_win_stack (w, name, '+');
      A4GL_win_stack (w, name, '-');
      return 0;
    }

  if (w == NULL)
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

  if (w == NULL)
    {
      FPRINTF (def_stderr, "**** WINDOW NOT FOUND %s op=%c *****",name,op);
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
  A4GL_debug ("Done win_stack : %p %c", w, op);

  return w;

}


static void
add_window (char *s, int w, int h, int border)
{
  struct s_windows *win;
  win = malloc (sizeof (struct s_windows));
  strcpy (win->name, s);
  win->w = w;
  win->h = h;
  win->border = border;
  win->visible = 1;
  A4GL_debug("Add window : %s",s);
  A4GL_win_stack (win, s, '+');
}



int
UILIB_A4GL_cr_window_form (char *name, int iswindow, int form_line,
			   int error_line, int prompt_line, int menu_line,
			   int border, int comment_line, int message_line, int attrib, char *style, char *text)
{
//int rval;
  char *fname;
  int x;
  int y;
  struct s_form_dets *form;


  fname = A4GL_char_pop ();
  x = A4GL_pop_int ();
  y = A4GL_pop_int ();
  if (style == 0)
    style = "";
  if (text == 0)
    text = "";




  suspend_flush (1);
  A4GL_trim (fname);
  send_to_ui ("<OPENWINDOWWITHFORM WINDOW=\"%s\" X=\"%d\" Y=\"%d\" ATTRIBUTE=\"%d\" SOURCE=\"%s\"", name, x, y, attrib, fname);
      send_to_ui
	(" TEXT=\"%s\" STYLE=\"%s\" ERROR_LINE=\"%d\" PROMPT_LINE=\"%d\" MENU_LINE=\"%d\" BORDER=\"%d\" COMMENT_LINE=\"%d\" MESSAGE_LINE=\"%d\" FORM_LINE=\"%d\">",
	 ignull (text), ignull (style), error_line, prompt_line, menu_line, border, comment_line, message_line,form_line);


// Can we find a pregenerated XML form ? 
  if (!A4GL_XML_opening_form (fname, name,1))
    {
	set_reading_form(fname,name);
      form = A4GL_read_form (fname, name);
    }
  send_to_ui ("</OPENWINDOWWITHFORM>");
  suspend_flush (-1);

  if (last_w==1 && last_h==1) {
		last_w=80;
		last_h=24;
  }

  add_window (name, last_w, last_h, border);
  free(fname);

  return 0;
}

int
UILIB_A4GL_disp_fields_ap (int n, int attr, va_list * ap)
{
  int rval=0;
  char *field_list = "field_list";
  char **args;
  char *argp;
  int *arg_types;
  int a;

  args = malloc (sizeof (char *) * n);
  arg_types = malloc (sizeof (int) * n);

  for (a = 0; a < n; a++)
    {
		//char *s;
		int d1;
  		int s1;
  		void *ptr1;

	  	A4GL_get_top_of_stack (1, &d1, &s1, (void **) &ptr1);
		arg_types[a]=d1;
		if ((d1&DTYPE_MASK)==DTYPE_BYTE || (d1&DTYPE_MASK)==DTYPE_TEXT) {
			args[a] =malloc(sizeof(fglbyte));
			memcpy(args[a],ptr1,sizeof(fglbyte));
			A4GL_drop_param();
				
		} else {
      			args[a] = A4GL_char_pop ();
			switch (d1&DTYPE_MASK) {
				case DTYPE_INT:
				case DTYPE_SMINT:
				case DTYPE_FLOAT:
				case DTYPE_SMFLOAT:
				case DTYPE_MONEY:
				case DTYPE_SERIAL:
					A4GL_lrtrim(args[a]);
					break;

				case DTYPE_DECIMAL:
					A4GL_lrtrim(args[a]);
					if (args[a][0]=='.') {
						char buff[2000];
						sprintf(buff,"0%s",args[a]);
						free(args[a]);
						args[a]=strdup(buff);
					}

			}
		}
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
	  send_to_ui ("<FIELD NAME=\"%s\"/>", get_field_with_subscript_as_string(argp, i));
	}
    }
  send_to_ui ("</FIELDLIST>");

  send_to_ui ("<VS>", attr, field_list);
  for (a = n - 1; a >= 0; a--)
    {
		if (arg_types[a]==DTYPE_BYTE || arg_types[a]==DTYPE_TEXT) {
			fglbyte *b;
			fglbyte **bp;
			char *ptr;
			b=(fglbyte *)args[a];
			bp=(fglbyte **)args[a];
			ptr=A4GL_byte_as_base64(b);
			if (ptr) {
				int l;
				int cnt=0;
				char buff2[300];
      				send_to_ui_no_nl ("<TEXT TYPE=\"BLOB\">");
				l=strlen(ptr);
  				while (cnt<l) {
					strncpy(buff2,ptr,256);
					buff2[256]=0;
  					send_to_ui_no_nl ("%s", buff2);
					cnt+=256;
					ptr+=256;
  				}
				send_to_ui("</TEXT>", ptr);
			} else {
      				send_to_ui ("<TEXT TYPE=\"BLOB\"/>"); // Empty blob - maybe it couldn't be loaded etc..
			}
		} else {
      			send_to_ui ("<TEXT>%s</TEXT>", uilib_xml_escape (args[a]));
		}
      free (args[a]);
    }
  free (args);
  free (arg_types);

  send_to_ui ("</VS></DISPLAYTO>");
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
  A4GL_set_status (0, 0);


  suspend_flush (1);


  send_to_ui ("<OPENFORM FORMNAME=\"%s\" SOURCE=\"%s\">", name, buff);
// Can we find a pregenerated XML form ? 
//
  if (!A4GL_XML_opening_form (buff, name,1))
    {
      // Nope - lets send a non-xml form instead..
      // this will callback to our UILIB_A4GL_read_metrics function..
	set_reading_form(buff,name);
      form = A4GL_read_form (buff, name);
    }
    send_to_ui ("</OPENFORM>");
  suspend_flush (-1);

  free (s);
  return 0;			// Success...
}

void
UILIB_A4GL_close_form (char *name)
{
  send_to_ui ("<CLOSEFORM FORMNAME=\"%s\"/>", name);
}

int
UILIB_A4GL_disp_form (char *name, int attr)
{
  int rval = 0;
  send_to_ui ("<DISPLAYFORM FORMNAME=\"%s\" ATTRIBUTE=\"%d\"/>", name, attr);
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
  int rval = 0;
  int x1, x2, x3, x4, x5;
  if (n == 4)
    {
      x1 = A4GL_pop_int ();
      x2 = A4GL_pop_int ();
      x3 = A4GL_pop_int ();
      x4 = A4GL_pop_int ();
      send_to_ui ("<DRAWBOX arg1=\"%d\" arg2=\"%d\" arg3=\"%d\" arg4=\"%d\" />", x1, x2, x3, x4);
    }
  if (n == 5)
    {
      x1 = A4GL_pop_int ();
      x2 = A4GL_pop_int ();
      x3 = A4GL_pop_int ();
      x4 = A4GL_pop_int ();
      x5 = A4GL_pop_int ();
      send_to_ui ("<DRAWBOX arg1=\"%d\" arg2=\"%d\" arg3=\"%d\" arg4=\"%d\" arg5=\"%d\"/>", x1, x2, x3, x4, x5);
    }

  return rval;
}


void *
UILIB_A4GL_new_menu_create_with_attr (char *title, int x, int y, int mn_type, int help_no, char *comment, char *style, char *image,char *normal, char *highlight)
{
  static char mn[20] = "XML";
  static long ln = 0;

  ln++;
  A4GL_push_char (mn);
  A4GL_push_int (ln);
  A4GL_push_char (title);
  A4GL_push_char (comment);
  A4GL_push_char (style);
  A4GL_push_char (image);
  uilib_menu_start (6);
  mn_id = 0;

  return (void *) ln;
}

void
UILIB_A4GL_add_menu_option (void *menu, char *txt, char *keys_orig, char *desc, int helpno, int attr)
{
  static long ln = 0;
  long context;
  char keys[2000];
  int len;
  strcpy (keys, keys_orig);
  ln = (long) menu;
  A4GL_push_char ("XML");
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
	      SPRINTF (a, "%d", b);
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
	  A4GL_push_empty_char ();
	}
      else
	{
	  SPRINTF (buff, "%d", a);
	  A4GL_push_char (buff);
	}
    }


  A4GL_push_char (desc);
  A4GL_push_int (helpno);

  uilib_menu_add (6);
}




void UILIB_A4GL_ensure_menu_option (int optno, void* menuv, char *txt, char *keys, char *desc, int helpno, int attr) {
  //ACL_Menu_Opts *opt1;
  //ACL_Menu_Opts *opt2;
  //ACL_Menu *menu;
  //char opt_title[200];

// Does nothing yet...
}



void
UILIB_A4GL_finish_create_menu (void *menu)
{
  A4GL_push_char ("XML");
  A4GL_push_int ((long) menu);
  uilib_get_context (2);
  uilib_menu_initialised (1);
}


int
UILIB_A4GL_menu_loop_v2 (void *menu, void *evt)
{
  int a;
  while (1)
    {
      A4GL_push_char ("XML");
      A4GL_push_int ((long) menu);
      uilib_get_context (2);
      uilib_menu_loop (1);
		set_xml_lastkey();
      a = A4GL_pop_int ();

      if (a == -1)
	continue;

      if (a == -2)
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
  A4GL_push_char ("XML");
  A4GL_push_int ((long) menu);
  uilib_get_context (2);
  context = A4GL_pop_long ();
  A4GL_push_int (context);
  A4GL_push_char (nextopt);
  uilib_next_option (2);
  return;
}

int
UILIB_A4GL_free_menu (void *menu)
{
  int a;
  A4GL_push_char ("XML");
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

  clr_exiting_context (context);

  clrPendingTriggers(context);

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


  A4GL_make_field_slist_from_ap (&list, ap,0);
  if (list.field_name_list[0].fpos != 0 && list.field_name_list[0].fpos != 1)
    {
      send_to_ui ("<NEXTFIELD CONTEXT=\"%d\" FIELD=\"%s\"/>", context, get_field_with_subscript_as_string(list.field_name_list[0].fname, list.field_name_list[0].fpos));
    }
  else
    {
      send_to_ui ("<NEXTFIELD CONTEXT=\"%d\" FIELD=\"%s\"/>", context, list.field_name_list[0].fname);
    }

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
clr_exiting_context(context);
  clrPendingTriggers(context);
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


  A4GL_make_field_slist_from_ap (&list, ap, 0);

  send_to_ui ("<NEXTFIELD CONTEXT=\"%d\" FIELD=\"%s\"/>", context, get_field_with_subscript_as_string(list.field_name_list[0].fname, list.field_name_list[0].fpos));


  return rval;
}

int
UILIB_A4GL_menu_hide_ap (void *menu, va_list * ap)
{
  char *argp;
  int rval = 0;
  long context;
  A4GL_push_char ("XML");
  A4GL_push_int ((long) menu);
  uilib_get_context (2);
  context = A4GL_pop_long ();
  while ((argp = va_arg (*ap, char *)))
    {
      A4GL_trim (argp);
      send_to_ui ("<HIDEOPTION CONTEXT=\"%d\" OPTION=\"%s\"/>", context, argp);
    }
  return rval;
}

int
UILIB_A4GL_menu_show_ap (void *menu, va_list * ap)
{
  char *argp;
  long context;
  A4GL_push_char ("XML");
  A4GL_push_int ((long) menu);
  uilib_get_context (2);
  context = A4GL_pop_long ();
  while ((argp = va_arg (*ap, char *)))
    {
      A4GL_trim (argp);
      send_to_ui ("<SHOWOPTION CONTEXT=\"%d\" OPTION=\"%s\"/>", context, argp);
    }
  return 0;
}

void
UILIB_aclfgli_pr_message_internal (int attr, int wait, char *s)
{
  A4GL_push_char (s);
  A4GL_push_int (attr);
  A4GL_push_int (wait);
  uilib_message (3);
}

void
UILIB_A4GL_display_error (int attr, int wait)
{
  uilib_error (1);
}

void *
UILIB_A4GL_get_curr_form (int warn_if_no_form)
{
  return (void *) 1;
}

void
UILIB_A4GL_set_option_value_for_current_window (char type, long keyval)
{
  send_to_ui ("<OPTIONS TYPE=\"%c\" VALUE=\"%d\"/>", type, keyval);
}


int
UILIB_A4GL_gen_field_chars_ap (void *field_list, void *formdets, va_list * ap,int replace_0)
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
      if (i == 1 )
	{
	  SPRINTF (smbuff, "<FIELD NAME=\"%s\"/>", argp);
	}
      else
	{
	if (i==0) i=replace_0;
	  SPRINTF (smbuff, "<FIELD NAME=\"%s\"/>", get_field_with_subscript_as_string(argp, i));
	}
      strcat (buff, smbuff);
    }
  strcat (buff, "</FIELDLIST>");
  f = field_list;
  *f = strdup (buff);
  return 1;
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
  if (i == A4GL_EVENT_AFTER_DELETE)
    {
      return "AFTER DELETE";
    }
  if (i == A4GL_EVENT_ON_ACTION)
    {
      return "ON ACTION";
    }
  if (i== A4GL_EVENT_AFT_INSERT_DELETE) {
      return "AFTER INSERT_DELETE";
  }
  if (i== A4GL_EVENT_BEF_INSERT_DELETE) {
      return "BEFORE INSERT_DELETE";
  }

 if (i==A4GL_EVENT_BEFORE_DELETE) {
	return "BEFORE DELETE";
 }


  A4GL_assertion (1, "UNKNOWN event ID");
  return "";

}


static char **
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

      if (e[a].event_type == A4GL_EVENT_AFTER_INP_CLEAN || e[a].event_type == A4GL_EVENT_BEFORE_INP)
	{
	  continue;
	}
      if (e[a].event_type == A4GL_EVENT_KEY_PRESS)
	{
	  //keys = get_key_codes (e[a].field);
	  A4GL_push_int (e[a].block);
	  A4GL_push_char ("ONKEY");
	  A4GL_push_int (e[a].keycode);
	  uilib_event (3);
	  continue;
	}



      if (e[a].field == 0)
	{
	  A4GL_push_int (e[a].block);
	  A4GL_push_char (decode_event_id (e[a].event_type));
	  A4GL_push_empty_char ();
	  uilib_event (3);
	  continue;
	}

      fields = get_field_codes (e[a].field);

      for (b = 0; fields[b]; b++)
	{
	  if (strlen (fields[b]) != 0)
	    {
	      A4GL_push_int (e[a].block);
	      A4GL_push_char (decode_event_id (e[a].event_type));
	      A4GL_push_char (fields[b]);
	      uilib_event (3);
	      //printf ("CALL UILIB_EVENT(%d,\"%s\",%s)", a + 1,  decode_event_id (e[a].event_type), fields[b]);
	    }
	  else
	    {
	      if (e[a].event_type == A4GL_EVENT_BEFORE_INP || e[a].event_type == A4GL_EVENT_AFTER_INP_CLEAN)
		{
		  //printc ("CALL UILIB_EVENT(%d,\"%s\",\"\")", a + 1, decode_event_id (event_id));
		  A4GL_push_int (e[a].block);
		  A4GL_push_char (decode_event_id (e[a].event_type));
		  A4GL_push_empty_char ();
		  uilib_event (3);
		}
	      else
		{
		  A4GL_push_int (e[a].block);
		  A4GL_push_char (decode_event_id (e[a].event_type));
		  A4GL_push_empty_char ();
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
  int Context;
  sreal = s;

  A4GL_debug ("FORM LOOP\n");

//printf("s=%p\n",s);
  if (init)
    {
      int context;
      A4GL_push_char ("XML");
      A4GL_push_int (((long) s) & 0xffffffff);
      uilib_get_context_dont_care_if_doesnt_exist (2);
      context = A4GL_pop_int ();	// Context..
      if (context>=0)
	{
	  clr_exiting_context (context);
	}
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
	  cno = 4;		// number of things pushed..
	  A4GL_push_char ("XML");
	  A4GL_push_int (((long) s) & 0xffffffff);
	  for (a = 0; a < sreal->novars; a++)
	    {
	      char buff[2000];
	      SPRINTF (buff, "%s.%s", sreal->constr[a].tabname, sreal->constr[a].colname);
	      //printf("PUSHING : %s\n",buff);
	      A4GL_push_char (buff);
	      cno++;
	    }

	  A4GL_push_int (sreal->attrib);
	  A4GL_push_int (A4GL_get_dbscr_inputmode());
	  uilib_construct_start (cno);
	  dump_events (evt);
	  uilib_construct_initialised (0);
	  A4GL_push_char ("XML");
	  A4GL_push_int (((long) s) & 0xffffffff);
	  uilib_get_context (2);
	  Context = A4GL_pop_int ();	// Context..
	  if (Context)
	    {
	      clr_exiting_context (Context);
	    }
	}
      else
	{
	  int with_defaults;
	  A4GL_push_char ("XML");
	  A4GL_push_int (((long) s) & 0xffffffff);
	  with_defaults = sreal->mode & 0x1;
	  if (with_defaults)
	    {
	      // Need to set all the values to null..
	      //
	      A4GL_push_int (0);
	    }
	  else
	    {
	      A4GL_push_int (1);
	    }
	  A4GL_push_int (sreal->attrib);
	  A4GL_push_int (sreal->novars);
	  A4GL_push_int (A4GL_get_dbscr_inputmode());
	  uilib_input_start (6);
	  dump_events (evt);
	  uilib_input_initialised (0);
	  A4GL_push_char ("XML");
	  A4GL_push_int (((long) s) & 0xffffffff);
	  uilib_get_context (2);
	  Context = A4GL_pop_int ();	// Context..
	  if (Context)
	    {
	      clr_exiting_context (Context);
	    }
	}

    }


  A4GL_push_char ("XML");
  A4GL_push_int (((long) s) & 0xffffffff);
  uilib_get_context (2);
  Context = A4GL_pop_int ();	// Context..
  while (1)
    {
      int a = 0;

      if (isset_exiting_context (Context, 0))
	{
	  clr_exiting_context (Context);
	  // We had an AFTER INPUT - now we need to exit the input cleanly...
	  if (A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt))
	    {
	      return A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt);
	    }
	}

      if (sreal->mode == MODE_CONSTRUCT)
	{
	  A4GL_push_int (Context);
	  uilib_construct_loop (1);
		set_xml_lastkey();
	}
      else
	{
	  int b;
	  A4GL_push_int (Context);

	  // ONly send if WITHOUT DEFAULTS or if its 'with defaults' then only if its not the first time around
	  if (init && (sreal->mode & 1))
	    {
	      uilib_input_loop (1);
		set_xml_lastkey();
	    }
	  else
	    {
	      for (b = 0; b < sreal->novars; b++)
		{
		char *fixnumeric;
		  A4GL_push_param (sreal->vars[b].ptr, sreal->vars[b].dtype + ENCODE_SIZE (sreal->vars[b].size));
		  switch (sreal->vars[b].dtype&DTYPE_MASK) {
                                case DTYPE_INT:
                                case DTYPE_SMINT:
                                case DTYPE_FLOAT:
                                case DTYPE_SMFLOAT:
                                case DTYPE_MONEY:
                                case DTYPE_SERIAL:
					fixnumeric=A4GL_char_pop();
                                        A4GL_lrtrim(fixnumeric);
					A4GL_push_char(fixnumeric);
					free(fixnumeric);
                                        break;

                                case DTYPE_DECIMAL:
					fixnumeric=A4GL_char_pop();
                                        A4GL_lrtrim(fixnumeric);
                                        if (fixnumeric[0]=='.') {
                                                char buff[2000];
                                                sprintf(buff,"0%s",fixnumeric);
						A4GL_push_char(buff);
                                        } else {
						A4GL_push_char(fixnumeric);
					}
					free(fixnumeric);

		  }
		}

	      uilib_input_loop (sreal->novars + 1);
		set_xml_lastkey();
	    }
	}
      a = A4GL_pop_int ();

	
      if (a == 0)
	{
	  if (A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt))
	    {
	      return A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt);
	    }
	}

      if (a == 0)
	continue;
      if (a == -1)
	continue;


      if (sreal->mode != MODE_CONSTRUCT && last_attr->sync.nvalues)
	{
	  int b;

	  // @FIXME Do we want to do this if its an ON KEY  ?
	  //
	  A4GL_push_int (Context);
	  uilib_input_get_values (1);
	//printf("Popping values\n");
	  for (b= sreal->novars - 1; b >= 0; b--)
	    {
	      A4GL_pop_var2 (sreal->vars[b].ptr, sreal->vars[b].dtype, sreal->vars[b].size);
	    }
	}

      if (sreal->mode == MODE_CONSTRUCT ) {
      if (last_attr->sync.nvalues)
	{
	  set_construct_clause (Context, generate_construct_result (sreal));
	}
      else
	{
	  set_construct_clause (Context, strdup (sreal->vars[0].ptr));
	}
	}


      if (a == -100)
	{			// Accept...
		/*
	  if (sreal->mode == MODE_CONSTRUCT)
	    {
	      if (last_attr->sync.nvalues)
		{
		  set_construct_clause (Context, generate_construct_result (sreal));
		}
	      else
		{
		  set_construct_clause (Context, strdup (sreal->vars[0].ptr));
		}
	    }
		*/

	  if (A4GL_has_event (A4GL_EVENT_AFTER_INP, evt))
	    {
	      set_exiting_context (Context, -100);
	      return A4GL_has_event (A4GL_EVENT_AFTER_INP, evt);
	    }

	  if (A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt))
	    {
	      return A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt);
	    }
	}

      if (a == -101)
	{			// Interrupt
	  int_flag = 1;
		/*
	  if (sreal->mode == MODE_CONSTRUCT)
	    {
	      set_construct_clause (Context, strdup (sreal->vars[0].ptr));
	    }
		*/

	  if (A4GL_has_event (A4GL_EVENT_AFTER_INP, evt))
	    {
	      set_exiting_context (Context, -101);
	      return A4GL_has_event (A4GL_EVENT_AFTER_INP, evt);
	    }

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
  A4GL_push_int (context);
  uilib_construct_query (1);
  return 1;
}

int
UILIB_aclfgl_aclfgl_add_to_toolbar (int n)
{
  char *tag;
  char * keyval;
  int  alwaysShow;
  char *toolTip;
  char *img;
  char *buttonText;

  if (n != 6)
    {
      A4GL_pop_args (n);
      return 0;
    }
  alwaysShow = A4GL_pop_int ();
  keyval = A4GL_char_pop ();
  toolTip = A4GL_char_pop ();
  img = A4GL_char_pop ();
  buttonText = A4GL_char_pop ();
  tag = A4GL_char_pop ();
  send_to_ui
    ("<ADDTOTOOLBAR TAG='%s' BUTTON='%s' IMAGE='%s' TOOLTIP='%s' KEYVAL='%s' ALWAYSSHOW='%d'/>",
     uilib_xml_escape (tag), uilib_xml_escape (buttonText), uilib_xml_escape (img), uilib_xml_escape (toolTip), keyval, alwaysShow);



  return 0;
}


void
UILIB_A4GL_display_internal (int x, int y, char *s, int a, int clr_line)
{
  if (x == -1 && y == -1)
    {
	if (A4GL_isyes(acl_getenv("DISPLAYLOCAL"))) {
		printf("%s\n",s);
	} else {
      		send_to_ui ("<DISPLAY>%s</DISPLAY>", uilib_xml_escape (s));
	}
    }
  else
    {
      send_to_ui ("<DISPLAYAT X=\"%d\" Y=\"%d\" ATTRIBUTE=\"%d\">%s</DISPLAYAT>", x, y, a, uilib_xml_escape (s));
    }
}

void
UILIB_A4GL_sleep_i ()
{
  int a;

  flush_ui ();
  a = A4GL_pop_int ();
  sleep (a);
}


int
UILIB_A4GLUI_ui_init (int argc, char **argv)
{
  int a;
  char *nm[] = {
    "DBPATH",
    "DBDATE",
    "DBMONEY",
    "DB_LOCALE",
    "LANG",
    0
  };
  if (!connect_ui ())
    {
      fprintf (stderr, "Unable to connect to the client\n");
      return 0;
    }

  for (a = 0; a < MAXWIN; a++)
    {
      win_stack[a] = 0;
    }
A4GL_debug("ui_init");
  add_window ("screen", 80, 24, 0);
A4GL_debug("added window 'screen'");
  if (generate_xml_forms==-1) {
	if (A4GL_isyes(acl_getenv("ALWAYSUSEXMLFORMS"))) {
		generate_xml_forms=1;
	} else {
		generate_xml_forms=0;
	}
  }
A4GL_debug("...");
  send_to_ui ("<PROGRAMSTARTUP PROGRAMNAME=\"%s\" ID=\"%d\">", argv[0], get_ui_id ('r'));
  for (a = 0; nm[a]; a++)
    {
      send_to_ui ("<ENV NAME=\"%s\" VALUE=\"%s\"/>", nm[a], uilib_xml_escape (acl_getenv (nm[a])));
    }
A4GL_debug("...");

  send_to_ui ("</PROGRAMSTARTUP>");
A4GL_debug("...");
  tmpnam (stderr_fname);
A4GL_debug("...");
  def_stderr = fopen (stderr_fname, "w");
A4GL_debug("...");
  if (def_stderr)
    {
      A4GL_set_stderr (def_stderr);
    }
A4GL_debug("...");
  flush_ui ();
  A4GL_debug("Done ui_init...");
  return 1;
}

void
UILIB_A4GLUI_set_intr ()
{
  send_to_ui ("<SETINTR/>");
}


/*
static char
hex_digit (int n)
{
  if (n >= 0 && n <= 9)
    return n + '0';
  if (n == 10)
    return 'a';
  if (n == 11)
    return 'b';
  if (n == 12)
    return 'c';
  if (n == 13)
    return 'd';
  if (n == 14)
    return 'e';
  if (n == 15)
    return 'f';
printf("n=%d\n",n);
  return 'x';
}
*/


static void
A4GL_send_xml_for_binary_file (char *filename, char *fbuff,char *remotename,int len)
{
  //int a;
  char *buff=0;
char buff2[2000];
  char *ptr;
  int l;
int cnt;
  //char *send;
  suspend_flush (1);
  if (remotename==0) {
  	send_to_ui_no_nl ("<FILE NAME=\"%s\">", filename);
  } else {
  	send_to_ui_no_nl ("<FILE NAME=\"%s\" CLIENTNAME=\"%s\">", uilib_xml_escape(filename),uilib_xml_escape(remotename)) ;
  }
  cnt=0;
  A4GL_base64_encode(fbuff,len,&buff);
  l=strlen(buff);
  ptr=buff;
  
  while (cnt<l) {
	strncpy(buff2,ptr,256);
	buff2[256]=0;
  	send_to_ui_no_nl ("%s", buff2);
	cnt+=256;
	ptr+=256;
  }

  send_to_ui ("</FILE>");
  suspend_flush (-1);
  flush_ui ();
}


static void
A4GL_send_xml_for_print_file (char *filename,int pageLength, char *fbuff, int len,char *mode)
{
  //int a;
  char *buff=0;
char buff2[2000];
  char *ptr;
  int l;
int cnt;
  //char *send;
  suspend_flush (1);

  send_to_ui_no_nl ("<PRINTFILE NAME=\"%s\" PAGELENGTH=\"%d\" MODE=\"%s\" >", filename, pageLength,mode);

  cnt=0;
  A4GL_base64_encode(fbuff,len,&buff);
  l=strlen(buff);
  ptr=buff;
  
  while (cnt<l) {
	strncpy(buff2,ptr,256);
	buff2[256]=0;
  	send_to_ui_no_nl ("%s", buff2);
	cnt+=256;
	ptr+=256;
  }

  send_to_ui ("</PRINTFILE>");
  suspend_flush (-1);
  flush_ui ();
}

static int
SendFile (char *filename, char *remotename)
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
      fbuff = malloc (l);
      fread (fbuff, l, 1, f);
      //fbuff[l] = 0;
      fclose (f);

      A4GL_send_xml_for_binary_file (filename, fbuff, remotename,l);


      free (fbuff);
      return 1;
    }
  else
    {
      return 0;
    }
}


static int
PrintFile (char *filename,int LinesPerPage,char *mode)
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
      fbuff = malloc (l);
      fread (fbuff, l, 1, f);
      //fbuff[l] = 0;
      fclose (f);

      A4GL_send_xml_for_print_file (filename,LinesPerPage,fbuff, l,mode);

      free (fbuff);
      return 1;
    }
  else
    {
      return 0;
    }
}


static int
GetFile (char *id, char *filename)
{
  if (uilib_save_file (id, filename))
    {
      A4GL_push_int (1);
      return 1;
    }
  else
    {
      A4GL_push_int (0);
      return 1;
    }
}

/*
int UILIB_aclfgl_aclfgl_client_ui_call(int n) {
char buff[2000];
char smbuff[2000];
char *params[2000];
int a;
	sprintf(buff,"<CALL NPARAMS=\"%d\">",n);
	for (a=0;a<n;a++) {
		params[n-a-1]=A4GL_char_pop();
		A4GL_trim(params[n-a-1]);
	}
	for (a=0;a<n;a++) {
		sprintf(smbuff,"<PARAM NO=\"%d\">%s</PARAM>",a+1,uilib_xml_escape(params[a]));
		strcat(buff,smbuff);
		free(params[a]);
	}
	strcat(buff,"</CALL>");
	send_to_ui(buff);
  	flush_ui ();
	return uilib_get_call_result();
}
*/


void
UILIB_A4GL_direct_to_ui (char *what, char *string)
{
  if (strcmp (what, "SEND") == 0)
    {
      send_to_ui ("<UIDIRECT>%s</UIDIRECT>", uilib_xml_escape (string));
      return;
    }


  if (strcmp (what, "FLUSH") == 0)
    {
	flush_ui();
      	return;
    }

  if (strcmp (what, "SET") == 0)
    {
	char *val;
	char *name;
	char buff1[2000];
	char buff2[2000];
	val=A4GL_char_pop();
	name=A4GL_char_pop();
	strcpy(buff1, uilib_xml_escape (name));
	strcpy(buff2, uilib_xml_escape (val));
	free(name);
	free(val);
	
      send_to_ui ("<UIOPTION NAME=\"%s\" VALUE=\"%s\"/>", buff1,buff2);
      return;
	}

  if (strcmp (what, "NAMEDFILE") == 0)
    {
     char *p1;
     char *p2;
     	p2=A4GL_char_pop();
	p1=A4GL_char_pop();
      if (SendFile (p1,p2)) {
		A4GL_push_int(1);
	} else {
		A4GL_push_int(0);
	}
      return;
    }

  if (strcmp (what, "FILE") == 0)
    {
      if (SendFile (string,0)) {
		A4GL_push_int(1);
	} else {
		A4GL_push_int(0);
	}
      return;
    }




  if (strcmp (what, "GETFILE") == 0)
    {
      char *p1;
      char *p2;
      p2 = A4GL_char_pop ();
      p1 = A4GL_char_pop ();
      GetFile (p1, p2);
      free (p1);
      free (p2);

      return;
    }

  if (strcmp(what,"EXECUTE")==0) {
      send_to_ui ("<EXECUTE>%s</EXECUTE>",uilib_xml_escape( string));
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
      send_to_ui ("<SETKEYLABEL DIALOG=\"1\" LABEL=\"%s\"  TEXT=\"%s\"/>", p1, ignull (p2));
      free (p1);
      free (p2);
      return;
    }

  if (strcmp (what, "fgl_dialog_seticon") == 0)
    {
      //int a;
      //int params;
      char *p1;
      char *p2;
      char *p3;
      p3 = A4GL_char_pop ();
      p2 = A4GL_char_pop ();
      p1 = A4GL_char_pop ();
      send_to_ui ("<FGL_DIALOG_SETICON ICON=\"%s\" TEXT=\"%s\"  COMMAND_OR_KEY=\"%s\"/>", uilib_xml_escape(p1), uilib_xml_escape (p2),uilib_xml_escape(p3));
      free (p1);
      free (p2);
      free (p3);
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
      send_to_ui ("<SETKEYLABEL DIALOG=\"0\" LABEL=\"%s\"  TEXT=\"%s\"/>", p1, ignull (p2));
      free (p1);
      free (p2);
      return;
    }

  if (strcmp (what, "dialog_setcursor") == 0)
    {
      //int a;
      //int params;
      int cpos;
	cpos=A4GL_pop_long();
      send_to_ui ("<SETCURSOR POSITION=\"%d\"/>",cpos);
      return;
    }

  FPRINTF (def_stderr, "unhandled direct to ui call\n");

}

void
UILIB_A4GL_ui_exit (int exitstatus)
{
  static int exiting = 0;
  if (exiting)
    return;
  exiting++;


#define MAX_LINE_LEN 256
  if (def_stderr)
    {
      fclose (def_stderr);
      def_stderr = fopen (stderr_fname, "r");
      pipe_clear();
      send_to_ui ("<PROGRAMSTOP EXITCODE=\"%d\" ID=\"%d\">", exitstatus, get_ui_id ('r'));
      if (def_stderr)
	{
	  char buf[MAX_LINE_LEN + 1];
	  while (fgets (buf, MAX_LINE_LEN + 1, def_stderr))
	    {
	      if (feof (def_stderr))
		break;
	      A4GL_trim (buf);
	      send_to_ui ("<line>%s</line>", buf);
	    }
	}
      send_to_ui ("</PROGRAMSTOP>");
	fclose(def_stderr);
      unlink (stderr_fname);
    }
  else
    {
      pipe_clear();
      send_to_ui ("<PROGRAMSTOP EXITCODE=\"%d\" ID=\"%d\"/>", exitstatus, get_ui_id ('r'));
      unlink (stderr_fname);
    }

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

  send_to_ui ("<MOVEWINDOW WINDOW=\"%s\"/ x=\"%d\" y=\"%d\" ABSOLUTE=\"%d\" >", winname, x, y, absol);

  return rval;
}

void
UILIB_A4GL_hide_window (char *winname)
{
  send_to_ui ("<HIDEWINDOW WINDOW=\"%s\"/>", winname);
   A4GL_win_stack (NULL, winname, 'v');
  //A4GL_win_stack(0,win_name,'!');
}

void
UILIB_A4GL_show_window (char *winname)
{
  send_to_ui ("<SHOWWINDOW WINDOW=\"%s\"/>", winname);
  A4GL_win_stack (NULL, winname, '^');
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
	A4GL_win_stack (NULL, win_name, '-');
}

int
UILIB_A4GL_disp_arr_v2 (void *disp, void *ptr, char *srecname, int attrib, char * scrollf, int scrollw, void *evt)
{
  char buff[2000];
  int a, b;
  //int n;
  struct s_disp_arr *d;
  int context;
  int rval=0;
  d = (struct s_disp_arr *) disp;

  if (d->srec == 0)
    {
      d->srec = (void *) srecname;
      d->last_arr = -1;
      d->scr_line = 1;
      d->arr_line = 1;
      d->cntrl = 1;
      d->highlight = 0;
      d->attribute = attrib;

      SPRINTF (buff, "<FIELDLIST><FIELD NAME=\"%s.*\"/></FIELDLIST>", srecname);
      uilib_set_field_list_directly (buff);

      A4GL_push_char ("XML");
      A4GL_push_int (((long) disp) & 0xffffffff);
      A4GL_push_int (attrib);

      A4GL_push_int (d->no_arr);
      uilib_set_count (1);

      A4GL_push_int (d->nbind);
      uilib_display_array_start (3);
      uilib_array_lines_start (0);

      for (a = 0; a < d->no_arr; a++)
	{
	  A4GL_push_int (a);
	  for (b = 0; b < d->nbind; b++)
	    {
	      char *cptr;
		char *aptr;
	      cptr = (char *) d->binding[b].ptr + d->arr_elemsize * (a);
	      A4GL_push_param (cptr, d->binding[b].dtype + ENCODE_SIZE (d->binding[b].size));
	      switch (d->binding[b].dtype&DTYPE_MASK) {
				case DTYPE_INT:
				case DTYPE_SMINT:
				case DTYPE_FLOAT:
				case DTYPE_SMFLOAT:
				case DTYPE_MONEY:
				case DTYPE_SERIAL:
					aptr=A4GL_char_pop();
					A4GL_lrtrim(aptr);
					A4GL_push_char(aptr);
					free(aptr);
					break;

				case DTYPE_DECIMAL:
					aptr=A4GL_char_pop();
					A4GL_lrtrim(aptr);
					if (aptr[0]=='.') {
						char buff[2000];
						sprintf(buff,"0%s",aptr);
						free(aptr);
						aptr=strdup(buff);
					}
					A4GL_push_char(aptr);
					free(aptr);
					break;		
			
			}


	    }
	  uilib_display_array_line (d->nbind + 1);
	}
      uilib_array_lines_end (0);
      dump_events (evt);
/*
                CALL UILIB_START_EVENTS()
                CALL UILIB_EVENT(1,"ONKEY","F1")
                CALL UILIB_END_EVENTS()
*/


      uilib_display_array_initialised (0);
    }

  A4GL_push_char ("XML");
  A4GL_push_int (((long) disp) & 0xffffffff);
  uilib_get_context (2);
  context = A4GL_pop_int ();
  A4GL_push_int (context);


  uilib_display_array_loop (1);
		set_xml_lastkey();
  rval = A4GL_pop_int ();

  if (rval == 0)
    {
      if (A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt))
	{
	  return A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt);
	}
    }

  if (last_attr)
    {
      if (last_attr->arrline) {
	A4GL_set_arr_curr (last_attr->arrline);
	d->arr_line=last_attr->arrline;
	}
      if (last_attr->arrcount)
	A4GL_set_arr_count (last_attr->arrcount);
      if (last_attr->scrline) {
	A4GL_set_scr_line (last_attr->scrline);
	d->scr_line=last_attr->scrline;
	}

    }

  if (rval == -100)
    {
      // ACCEPT...
      if (A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt))
	{
          A4GL_push_long (context);
          //uilib_free_display (1);
	  return A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt);
	}
    }

  if (rval == -101)
    {
      // INTERRUPT
      int_flag = 1;
      if (A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt))
	{
      	A4GL_push_long (context);
          //uilib_free_display (1);
	  return A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt);
	}
    }

  return rval;
}


int
UILIB_aclfgl_set_window_title (int nargs)
{
  char *s;
  s = A4GL_char_pop ();
  send_to_ui ("<SETWINDOWTITLE TEXT=\"%s\"/>", uilib_xml_escape (ignull (s)));
  free (s);
  return 0;
}


int
UILIB_aclfgl_aclfgl_set_application_xml (int nargs)
{
  char *s;
  s = A4GL_char_pop ();
  send_to_ui ("<SETAPPLICATIONLAUNCHERXML FILE=\"%s\"/>", uilib_xml_escape (ignull (s)));
  free (s);
  return 0;
}


void
UILIB_A4GL_finish_screenio (void *sio, char *siotype)
{
  A4GL_push_char ("XML");
  A4GL_push_int (((long) sio) & 0xffffffff);
  uilib_get_context (2);
  if (strcmp (siotype, "s_inp_arr") == 0)
    {
      uilib_free_input_array (1);
	return ;
    }

  if (strcmp (siotype, "s_screenio") == 0)
    {
      uilib_free_input (1);
	return ;
    }
  if (strcmp (siotype, "s_disp_arr") == 0)
    {
      uilib_free_display (1);
	return ;
    }
A4GL_assertion(1,"Unhandled free_screenio");
}

void
UILIB_A4GL_clr_form (int to_defaults)
{
  send_to_ui ("<CLEARFORM TODEFAULTS=\"%d\"/>", to_defaults);
}

int
UILIB_A4GL_read_fields (void *formdets)
{
  return 1;
}

int
UILIB_aclfgl_aclfgl_dump_screen (int n)
{
  int rval=0;
  send_to_ui ("<DUMPSCREEN/>");
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
	A4GL_assertion(win_stack_cnt<=0, "Nothing on windows stack");
  return win_stack[win_stack_cnt - 1]->name;

}

int
UILIB_A4GL_get_curr_width ()
{
	A4GL_assertion(win_stack_cnt<=0, "Nothing on windows stack");
  return win_stack[win_stack_cnt - 1]->w;
}

int
UILIB_A4GL_get_curr_height ()
{
	A4GL_assertion(win_stack_cnt<=0, "Nothing on windows stack");
  return win_stack[win_stack_cnt - 1]->h;
}

int
UILIB_A4GL_iscurrborder ()
{
	A4GL_assertion(win_stack_cnt<=0, "Nothing on windows stack");
  return win_stack[win_stack_cnt - 1]->border;
}




int
UILIB_A4GL_inp_arr_v2 (void *vinp, int defs, char *srecname, int attrib, int init, void *evt)
{
  int rval=0;
  struct s_inp_arr *inp;
  int context = -1;
  int acnt;
  int ninp;
  inp = vinp;
  int count=-1;

  if (init)
    {
      char buff[2000];
      //int a;
      count = A4GL_get_count ();
      A4GL_push_int (count);
      uilib_set_count (1);
      suspend_flush (1);
      SPRINTF (buff, "<FIELDLIST><FIELD NAME=\"%s.*\"/></FIELDLIST>", srecname);
      uilib_set_field_list_directly (buff);

      A4GL_push_char ("XML");
      A4GL_push_int (((long) inp) & 0xffffffff);
      A4GL_push_int (defs);
      A4GL_push_int (attrib);
      A4GL_push_int (inp->arr_size);
      A4GL_push_int (inp->nbind);
	A4GL_push_int(inp->allow_insert);
	A4GL_push_int(inp->allow_delete);
	A4GL_push_int(inp->inp_flags);
	  A4GL_push_int (A4GL_get_dbscr_inputmode());
      uilib_input_array_start (10);

      A4GL_push_char ("XML");
      A4GL_push_int ((long) vinp & (0xffffffff));
      uilib_get_context (2);
      context = A4GL_pop_long ();
      clr_exiting_context (context);

      ninp = count;
      dump_events (evt);
      uilib_input_array_initialised (0);
      suspend_flush (-1);

      if (defs == 0)
	{
	  if (ninp)
	    {
	      A4GL_debug ("CLEARING down array - we want defaults\n");
	      for (acnt = 0; acnt < ninp; acnt++)
		{
		  int b;
		  for (b = 0; b < inp->nbind; b++)
		    {
		      char *cptr;
		      cptr = (char *) inp->binding[b].ptr + inp->arr_elemsize * (acnt);
		      A4GL_setnull (inp->binding[b].dtype, cptr, inp->binding[b].size);
		    }
		}
	    }
	}
    }

  if (context == -1)
    {
      A4GL_push_char ("XML");
      A4GL_push_int ((long) vinp & 0xffffffff);
      uilib_get_context (2);
      context = A4GL_pop_long ();
    } 

if (count==-1) {
        A4GL_push_int (context);
	uilib_get_input_array_count(1);
	count=A4GL_pop_int();
	}

  for (acnt = 0; acnt < count; acnt++)
    {
      int b;
      A4GL_push_int (context);
      A4GL_push_int (acnt + 1);
      for (b = 0; b < inp->nbind; b++)
	{
	  char *cptr;
	char *aptr;
	  cptr = (char *) inp->binding[b].ptr + inp->arr_elemsize * (acnt);
	//printf("DTYPE=%d\n",inp->binding[b].dtype );
	//if ((inp->binding[b].dtype  & DTYPE_MASK)==DTYPE_CHAR) {
			//printf("Pushing  : %s\n", cptr);
	//}
	  A4GL_push_param (cptr, inp->binding[b].dtype + ENCODE_SIZE (inp->binding[b].size));
	      switch (inp->binding[b].dtype&DTYPE_MASK) {
				case DTYPE_INT:
				case DTYPE_SMINT:
				case DTYPE_FLOAT:
				case DTYPE_SMFLOAT:
				case DTYPE_MONEY:
				case DTYPE_SERIAL:
					aptr=A4GL_char_pop();
					A4GL_lrtrim(aptr);
					A4GL_push_char(aptr);
					free(aptr);
					break;

				case DTYPE_DECIMAL:
					aptr=A4GL_char_pop();
					A4GL_lrtrim(aptr);
					if (aptr[0]=='.') {
						char buff[2000];
						sprintf(buff,"0%s",aptr);
						free(aptr);
						aptr=strdup(buff);
					}
					A4GL_push_char(aptr);
					free(aptr);
					break;		
			
	    }
	}
      uilib_input_array_sync (inp->nbind + 2);
    }


      if (isset_exiting_context (context, 0))
	{
	  clr_exiting_context (context);
	  // We had an AFTER INPUT - now we need to exit the input cleanly...
	  if (A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt))
	    {
	      return A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt);
	    }
	}


  A4GL_push_int (context);
  uilib_input_array_loop (1);
		set_xml_lastkey();

  rval = A4GL_pop_int ();

  if (rval == 0)
    {
      if (A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt))
	{
	  return A4GL_has_event (A4GL_EVENT_BEFORE_INP, evt);
	}
    }

  if (rval > 0 || rval == -100)
    {
      // If we've got to here we need to copy down our values...
      while (1)
	{
	  int gc_arr_cnt;
	  int b;
	  A4GL_push_int (context);
	  uilib_has_array_values (1);
	  gc_arr_cnt = A4GL_pop_long ();
	  if (gc_arr_cnt <= 0)
	    break;
	  A4GL_push_long (context);
	  A4GL_push_long (gc_arr_cnt);
	  uilib_input_get_array_values (2);
	  for (b = inp->nbind - 1; b >= 0; b--)
	    {
	      char *cptr;
	      cptr = (char *) inp->binding[b].ptr + inp->arr_elemsize * (gc_arr_cnt - 1);
	      A4GL_pop_var2 (cptr, inp->binding[b].dtype, inp->binding[b].size);
	    }
	}
    }

  if (last_attr)
    {
      if (last_attr->arrline) {
	//printf("Setting arrline ... %d\n", last_attr->arrline);
	A4GL_set_arr_curr (last_attr->arrline);
	inp->arr_line=last_attr->arrline;
      }
      if (last_attr->arrcount) {
	A4GL_set_arr_count (last_attr->arrcount);
 	inp->no_arr=last_attr->arrcount;
	}
      if (last_attr->scrline) {
	A4GL_set_scr_line (last_attr->scrline);
	inp->scr_line=last_attr->scrline;
	}


    }

  if (rval == -100)
    {
      A4GL_debug ("ACCEPT....\n");
      // ACCEPT...
      if (A4GL_has_event (A4GL_EVENT_AFTER_INP, evt))
	{
	  set_exiting_context (context, -100);
	  return A4GL_has_event (A4GL_EVENT_AFTER_INP, evt);
	}
      if (A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt))
	{
	  int a;
	  a = A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt);
	  A4GL_debug ("Returning %d\n", a);
	  return a;
	}
      A4GL_assertion (1, "Should have an A4GL_EVENT_AFTER_INP_CLEAN");
    }
  if (rval == -101)
    {
      // INTERRUPT
      int_flag = 1;
      set_exiting_context (context, -101);

      if (A4GL_has_event (A4GL_EVENT_AFTER_INP, evt))
	{
	  set_exiting_context (context, -101);
	  return A4GL_has_event (A4GL_EVENT_AFTER_INP, evt);
	}
      //A4GL_push_int (context); uilib_free_input_array(1);
      if (A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt))
	{
	  return A4GL_has_event (A4GL_EVENT_AFTER_INP_CLEAN, evt);
	}
      A4GL_assertion (1, "Should have an A4GL_EVENT_AFTER_INP_CLEAN");
    }

  return rval;
}

int
UILIB_A4GL_prompt_loop_v2 (void *vprompt, int timeout, void *evt_list)
{
  long context;
  struct s_prompt *prompt;
  long ln;
  int rval=0;
  prompt = vprompt;


  ln = (long) prompt;

  if (startingPrompt)
    {
      startingPrompt = 0;
      dump_events (evt_list);
      uilib_prompt_initialised (0);
    }

  A4GL_push_char ("XML");
  A4GL_push_int (ln);
  uilib_get_context (2);
  context = A4GL_pop_long ();
	A4GL_debug("loop : Prompt context: %d\n",context);

  while (1)
    {
      A4GL_push_long (context);
      uilib_prompt_loop (1);
		set_xml_lastkey();
      rval = A4GL_pop_long ();
      if (rval > 0)
	{
	  prompt->mode = 2;
	  A4GL_push_long (context);
	  uilib_free_prompt (1);
	  return rval;
	}
      if (rval == -100)
	{
	  char *rvalstr;
	  if (last_attr->sync.nvalues)
	    {
	      //int b;
	      A4GL_push_int (context);
	      uilib_get_prompt_result (1);
	      rvalstr = A4GL_char_pop ();
	    }
	  else
	    {
	      rvalstr = strdup ("");
	    }

	  A4GL_push_char (rvalstr);
	  free (rvalstr);
	  prompt->mode = 2;
	  break;
	}

      if (rval == -101)
	{
	  prompt->mode = 2;
	  int_flag = 1;
	  break;
	}
    }

//fprintf(stderr, "prompt loop mode :%d\n", prompt->mode);
  if (prompt->mode == 2)
    {
      A4GL_push_long (context);
      uilib_free_prompt (1);
    }


  //printf("prompt->mode=%d\n",prompt->mode);
  return 1;
}

int
UILIB_A4GL_start_prompt (void *vprompt, int ap, int c, int h, int af,char *text,char *style,int dtype_hint)
{
  int rval=0;
  char *promptstr;
  static long ln = 0;
  //long context;
  struct s_prompt *prompt;
  prompt = vprompt;
  ln = (long) prompt;
  promptstr = A4GL_char_pop ();
  prompt->mode = -1;



  A4GL_push_char ("XML");
  //A4GL_push_int (ln);
  //uilib_get_context (2);
  //context = A4GL_pop_long ();
//printf("Prompt context: %d\n",context);
  A4GL_push_char ("XML");
  A4GL_push_int (ln);
  A4GL_push_char (promptstr);
  A4GL_push_long (ap);		// attribute for prompt
  A4GL_push_long (af);		// attribute for prompt
  A4GL_push_long (c);
  A4GL_push_long (h);
  A4GL_push_char(text);
  A4GL_push_char(style);
  A4GL_push_long(dtype_hint);
  startingPrompt++;
  uilib_prompt_start (10);

  rval = 1;
  return rval;
}


void
UILIB_A4GL_reset_state_for (void *sio, char *siotype)
{
}




int
UILIB_A4GL_screen_mode (int sm)
{
  return 1;
}



char *
UILIB_A4GL_ui_fgl_winquestion (char *title, char *text, char *def, char *pos, char *icon, int danger, int winbutton)
{
  //char* rval;
  int a;
  send_to_ui
    ("<WINQUESTION TITLE=\"%s\" TEXT=\"%s\" DEFAULT=\"%s\" POS=\"%s\" ICON=\"%s\" DANGER=\"%d\" BUTTON=\"%d\" />",
     ignull (title), uilib_xml_escape (ignull (text)), def, pos, icon, danger, winbutton);

  send_to_ui ("<WAITFOREVENT/>");
  flush_ui ();
  a = get_event_from_ui (NULL);
  if (a == -118)
    {
      return "cancel";
    }
  if (a == -101)
    {
      return "yes";
    }
  if (a == -120)
    {
      return "ignore";
    }
  if (a == -119)
    {
      return "ok";
    }
  if (a == -121)
    {
      return "retry";
    }
  if (a == -102)
    {
      return "no";
    }


  return last_attr->lastkey;

	printf("Bad winquestion result: %d\n",a);
  return "InvalidReturnedValue";
}


int
XML_A4GL_assertion (int n, char *s)
{
  if (!n)
    return 0;
  FPRINTF (def_stderr, "************ ASSERTION FAILED %s\n", s);
  fflush (stdout);
  exit (4);
}

void *
UILIB_A4GL_cr_window (char *s, int iswindow, int form_line, int error_line,
		      int prompt_line, int menu_line, int border,
		      int comment_line, int message_line, int attrib, char *style, char *text)
{
  //void* rval;
  int x, y, w, h;
  w = A4GL_pop_int ();
  h = A4GL_pop_int ();
  x = A4GL_pop_int ();
  y = A4GL_pop_int ();
  if (style == 0)
    style = "";

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
    ("<CREATEWINDOW NAME=\"%s\" X=\"%d\" Y=\"%d\" W=\"%d\" H=\"%d\" FORM_LINE=\"%d\" ERROR_LINE=\"%d\" PROMPT_LINE=\"%d\" MENU_LINE=\"%d\" COMMENT_LINE=\"%d\" MESSAGE_LINE=\"%d\" BORDER=\"%d\" ATTRIBUTE=\"%d\" STYLE=\"%s\" TEXT=\"%s\" />",
     s, x, y, w, h, form_line, error_line, prompt_line, menu_line,
     comment_line, message_line, border, attrib, ignull (style), ignull (text));


  add_window (s,w, h, border);

  return (void *) 1;
}



int
UILIB_A4GL_set_fields (void *sio)
{
  return 1;
}

void
UILIB_A4GL_add_menu_timeout (void *menu, char timeout_type, int timeoutlen, int cmd_no_on_timeout, long *timeoutvar)
{
  static long ln = 0;
  long context;
  ln = (long) menu;
  A4GL_push_char ("XML");
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
  A4GL_push_char ("XML");
  A4GL_push_int (ln);
  uilib_get_context (2);
  context = A4GL_pop_long ();
  mn_id++;
  send_to_ui
    ("<MENUACTION CONTEXT=\"%d\" ID=\"%d\" ACTION=\"%s\" CMD_NO_TIMEOUT=\"%d\" />", context, mn_id, action, cmd_no_on_timeout);
}


#ifdef OBSOLETE
static void
A4GL_make_label (int frow, int fcol, char *label)
{
  send_to_ui ("<FORMLABEL ROW=\"%d\" COLUMN=\"%d\">%s</FORMLABEL>", frow, fcol, uilib_xml_escape (label));
}
#endif


static void
A4GL_make_field (int frow, int fcol, int rows, int cols, char *widget,
		 char *config, char *inc, void *id, char *tab_and_col, char *action, int attr_no)
{
  	send_to_ui ("<FORMFIELD ROW=\"%d\" COLUMN=\"%d\" ROWS=\"%d\" COLS=\"%d\" WIDGET=\"%s\"",frow, fcol, rows, cols, uilib_xml_escape (widget));
 	send_to_ui(" CONFIG=\"%s\"",uilib_xml_escape (config));
	send_to_ui(" INC=\"%s\" ID=\"%d\"",uilib_xml_escape (inc), (long) id);
	send_to_ui(" TABCOL=\"%s\"",uilib_xml_escape (tab_and_col));
	send_to_ui(" ACTION=\"%s\" ATTRIBUTE_NO=\"%d\"/>", uilib_xml_escape (action), attr_no);
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
	  A4GL_debug ("Found field %d @ %d - %s\n", field_no, a, f->attributes.attributes_val[a].colname);
	  return a;
	}
    }
  A4GL_debug ("Not found\n");
  return -1;

}



static int
A4GL_find_attrib_from_metric (struct_form * f, int metric_no)
{
  return A4GL_find_attrib_from_field (f, A4GL_find_fields_no_metric (f, metric_no));
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
  int generated_xml_form=0;



  formdets = formdetsv;
  if (generate_xml_forms) {
		FILE *f;
		char buff[200];
		tmpnam(buff);
		//strcpy(buff,"tmp.xml");
		f=fopen(buff,"w");
		if (f) {
			write_xml_form(f,reading_form_id,formdets->fileform) ;
	  		if (A4GL_XML_opening_form (buff, reading_form_id,0)) {
				generated_xml_form=1;
			}

		}
		unlink(buff);
  } 

  if (generated_xml_form) {
	return 1;
  }
	
  delims[0][0] = formdets->fileform->delim[0];
  delims[1][0] = formdets->fileform->delim[1];
  delims[2][0] = formdets->fileform->delim[2];
  delims[0][1] = 0;
  delims[1][1] = 0;
  delims[2][1] = 0;
  n = formdets->fileform->metrics.metrics_len;
  A4GL_debug ("metrics len=%d", n);

      send_to_ui ("<FORM>");
  send_to_ui ("<SCREENS MAXCOL=\"%d\" MAXLINE=\"%d\">", formdets->fileform->maxcol, formdets->fileform->maxline);

  send_to_ui ("<SCREENLAYOUT>", formdets->fileform->maxcol, formdets->fileform->maxline);


  merge_labels(formdets->fileform,1); // using 1 because we want to dump Screen 1

  dump_form_labels();

  for (metric_no = 0; metric_no < n; metric_no++)
    {


      formdets->fileform->metrics.metrics_val[metric_no].pos_code = 0;
      A4GL_debug ("checking label %s\n", formdets->fileform->metrics.metrics_val[metric_no].label);

      if (strlen (formdets->fileform->metrics.metrics_val[metric_no].label) != 0)
	{
		continue;
	  	//A4GL_make_label (formdets->fileform->metrics.metrics_val[metric_no].  y, formdets->fileform->metrics.metrics_val[metric_no].  x, formdets->fileform->metrics.metrics_val[metric_no].label);
	}
      else
	{
	  int attr_no;
	  attr_no = A4GL_find_attrib_from_metric (formdets->fileform, metric_no);
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
			   config, include, fprop, make_tab_and_col (fprop->tabname, fprop->colname), action, attr_no);

	}
    }

  send_to_ui ("</SCREENLAYOUT>");
  send_to_ui ("</SCREENS>");

  send_to_ui ("<SCREENRECORDS>");
  // We also need to send the screen records as these might be used....
  for (n = 0; n < formdets->fileform->records.records_len; n++)
    {
      int attr;
      send_to_ui ("<SCREENRECORD NAME=\"%s\" SIZE=\"%d\">", formdets->fileform->records.records_val[n].name,
		  formdets->fileform->records.records_val[n].dim);
      for (attr = 0; attr < formdets->fileform->records.records_val[n].attribs.attribs_len; attr++)
	{
	  int attr_no;
	  attr_no = formdets->fileform->records.records_val[n].attribs.attribs_val[attr];
	  fprop = &formdets->fileform->attributes.attributes_val[attr_no];
	  send_to_ui ("<ATTRIBUTE ATTRIBUTE_NO=\"%d\" NAME=\"%s\"/>",
		      formdets->fileform->records.records_val[n].attribs.attribs_val[attr], fprop->colname);
	}
      send_to_ui ("</SCREENRECORD>");
    }
  send_to_ui ("</SCREENRECORDS>");
  send_to_ui ("<ATTRIBUTES>");
  for (n = 0; n < formdets->fileform->attributes.attributes_len; n++)
    {
      int b;
      struct struct_scr_field *f;
      f = &formdets->fileform->attributes.attributes_val[n];
      send_to_ui ("<ATTRIB ATTRIBUTE_NO=\"%d\" DATATYPE=\"%d\" DATATYPE_SIZE=\"%d\" DYNAMIC=\"%d\" REVERSE=\"%d\" >",
		  n, f->datatype, f->dtype_size, f->dynamic, f->do_reverse);
      for (b = 0; b < f->str_attribs.str_attribs_len; b++)
	{
	  switch (f->str_attribs.str_attribs_val[b].type)
	    {
	    case FA_S_INCLUDE:
	    case FA_S_WIDGET:
	    case FA_S_CONFIG:
	    case FA_S_ACTION:
	      break;

	    case FA_S_PICTURE:
	      send_to_ui ("<ATTRIB_PICTURE>%s</ATTRIB_PICTURE>", uilib_xml_escape (f->str_attribs.str_attribs_val[b].value));
	      break;
	    case FA_S_FORMAT:
	      send_to_ui ("<ATTRIB_FORMAT>%s</ATTRIB_FORMAT>", uilib_xml_escape (f->str_attribs.str_attribs_val[b].value));
	      break;
	    case FA_S_DEFAULT:
	      send_to_ui ("<ATTRIB_DEFAULT>%s</ATTRIB_DEFAULT>", uilib_xml_escape (f->str_attribs.str_attribs_val[b].value));
	      break;
	    case FA_S_PROGRAM:
	      send_to_ui ("<ATTRIB_PROGRAM>%s</ATTRIB_PROGRAM>", uilib_xml_escape (f->str_attribs.str_attribs_val[b].value));
	      break;
	    case FA_S_COMMENTS:
	      send_to_ui ("<ATTRIB_COMMENTS>%s</ATTRIB_COMMENTS>", uilib_xml_escape (f->str_attribs.str_attribs_val[b].value));
	      break;
	    case FA_S_CLASS:
	      send_to_ui ("<ATTRIB_CLASS>%s</ATTRIB_CLASS>", uilib_xml_escape (f->str_attribs.str_attribs_val[b].value));
	      break;
	default: 
		break;

	    }
	}

      for (b = 0; b < f->bool_attribs.bool_attribs_len; b++)
	{
	  switch (f->bool_attribs.bool_attribs_val[b])
	    {
	    case FA_B_AUTONEXT:
	      send_to_ui ("<ATTRIB_AUTONEXT/>");
	      break;
	    case FA_B_REVERSE:
	      send_to_ui ("<ATTRIB_REVERSE/>");
	      break;
	    case FA_B_INVISIBLE:
	      send_to_ui ("<ATTRIB_INVISIBLE/>");
	      break;
	    case FA_B_NOENTRY:
	      send_to_ui ("<ATTRIB_NOENTRY/>");
	      break;
	    case FA_B_VERIFY:
	      send_to_ui ("<ATTRIB_VERIFY/>");
	      break;
	    case FA_B_WORDWRAP:
	      send_to_ui ("<ATTRIB_WORDWRAP/>");
	      break;
	    case FA_B_COMPRESS:
	      send_to_ui ("<ATTRIB_COMPRESS/>");
	      break;
	    case FA_B_UPSHIFT:
	      send_to_ui ("<ATTRIB_UPSHIFT/>");
	      break;
	    case FA_B_DOWNSHIFT:
	      send_to_ui ("<ATTRIB_DOWNSHIFT/>");
	      break;
	    case FA_B_REQUIRED:
	      send_to_ui ("<ATTRIB_REQUIRED/>");
	      break;
	    case FA_B_NOUPDATE:
	      send_to_ui ("<ATTRIB_NOUPDATE/>");
	      break;
	    case FA_B_QUERYCLEAR:
	      send_to_ui ("<ATTRIB_QUERYCLEAR/>");
	      break;
	    case FA_B_ZEROFILL:
	      send_to_ui ("<ATTRIB_ZEROFILL/>");
	      break;
	    case FA_B_RIGHT:
	      send_to_ui ("<ATTRIB_RIGHT/>");
	      break;

	case FA_B_HIDDEN:
		send_to_ui ("<ATTRIB_HIDDEN/>");
		break;

	case FA_B_SCROLL:
		send_to_ui ("<ATTRIB_SCROLL/>");
		break;

	case FA_B_WANTTABS:
		send_to_ui ("<ATTRIB_WANTTABS/>");
		break;

	case FA_B_WANTNORETURNS:
		send_to_ui ("<ATTRIB_WANTNORETURNS/>");
		break;

	case FA_B_FONTPITCHFIXED:
		send_to_ui ("<ATTRIB_FONTPITCHFIXED/>");
		break;

	case FA_B_FONTPITCHVARIABLE:
		send_to_ui ("<ATTRIB_FONTPITCHVARIABLE/>");
		break;

	case FA_B_AUTOSCALE:
		send_to_ui ("<ATTRIB_AUTOSCALE/>");
		break;

	case FA_B_STRETCH_BOTH:
		send_to_ui ("<ATTRIB_FA_B_STRETCH_BOTH/>");
		break;

	case FA_B_STRETCH_Y:
		send_to_ui ("<ATTRIB_STRETCH_Y/>");
		break;

	case FA_B_SCROLLBARS_BOTH:
		send_to_ui ("<ATTRIB_SCROLLBARS_BOTH/>");
		break;

	case FA_B_SCROLLBARS_VERTICAL:
		send_to_ui ("<ATTRIB_SCROLLBARS_VERTICAL/>");
		break;

	case FA_B_SCROLLBARS_HORIZONAL:
		send_to_ui ("<ATTRIB_SCROLLBARS_HORIZONAL/>");
		break;

	default:
		break;

	    }
	}
      send_to_ui ("</ATTRIB>");
    }
  send_to_ui ("</ATTRIBUTES>");
      send_to_ui ("</FORM>");


  return 1;
}

char *
generate_construct_result (struct s_screenio *s)
{
  int a;
  char *ptr;
  int flg = 0;
  char *buff = 0;

  for (a = 0; a < last_attr->sync.nvalues; a++)
    {


      // @@ FIXME - use the proper details from the construct structure in uilib/uilib.c
      ptr = A4GL_construct (s->constr[a].tabname, s->constr[a].colname,
			    last_attr->sync.vals[a].value, get_inc_quotes (last_attr->sync.vals[a].fieldtype),
			    last_attr->sync.vals[a].fieldtype & DTYPE_MASK, last_attr->sync.vals[a].fieldtype >> 16, s->callback_function);
      if (ptr == 0)
	{			/* Some error... */
	  if (buff)
	    free (buff);
	  return 0;
	}

      if (strlen (ptr))
	{
	  flg++;
	  if (buff)
	    {
	      buff = realloc (buff, strlen (buff) + strlen (ptr) + 10);
	      strcat (buff, " and ");
	      strcat (buff, ptr);
	    }
	  else
	    {
	      buff = strdup (ptr);
	    }
	}
    }

  if (!buff)
    buff = strdup (" 1=1");
  return buff;
}


static int
get_inc_quotes (int a)
{
  if ((a & DTYPE_MASK) == DTYPE_CHAR || (a & DTYPE_MASK) == DTYPE_VCHAR)
    return 1;
  if ((a & DTYPE_MASK) == DTYPE_DATE)
    return 2;
  if ((a & DTYPE_MASK) == DTYPE_DTIME)
    return 3;
  if ((a & DTYPE_MASK) == DTYPE_INTERVAL)
    return 4;
  return 0;
}



int
UILIB_UI_initlib ()
{
  return 1;
}


int
UILIB_A4GL_fgl_infield_ap (void *inp, va_list * ap)
{
  int rval = 0;
  int context;
  char *argp;
  int infield;
  A4GL_push_char ("XML");
A4GL_debug("inp=%p\n",inp);
  A4GL_push_int (((long) inp) & 0xffffffff);
  uilib_get_context (2);
  context = A4GL_pop_int ();
A4GL_debug("Got context as : %d\n",context);

  while ((argp = va_arg (*ap, char *)))
    {
      int i;
      i = va_arg (*ap, int);
      A4GL_trim (argp);
      A4GL_push_int (context);
      A4GL_push_char (argp);
      uilib_infield (2);
      infield = A4GL_pop_long ();
      if (infield)
	{
	  rval = 1;
	  break;
	}
    }

  return rval;
}



int
UILIB_A4GL_fgl_infield_ia_ap (void *inp, va_list * ap)
{
  int rval = 0;
  int context;
  char *argp;
  int infield;

  if (inp==NULL) {
	/* It might be an input or an input array - we dont know.. - we have no context - match against the last recorded infield*/
  	context = -1;
  } else {
  	A4GL_push_char ("XML");
  	A4GL_push_int (((long) inp) & 0xffffffff);
  	uilib_get_context (2);
  	context = A4GL_pop_int ();
  }

  while ((argp = va_arg (*ap, char *)))
    {
      int i;
      i = va_arg (*ap, int);
      A4GL_trim (argp);
      A4GL_push_int (context);
      A4GL_push_char (argp);
      uilib_infield (2);
      infield = A4GL_pop_long ();
      if (infield)
	{
	  rval = 1;
	  break;
	}
    }

  return rval;
}

void
UILIB_A4GL_clr_fields_ap (int to_defaults, va_list * ap)
{
  char *field_list;
  UILIB_A4GL_gen_field_chars_ap (&field_list, UILIB_A4GL_get_curr_form (1), ap,0);
  send_to_ui ("<CLEAR todefault=\"%d\">%s</CLEAR>", to_defaults, field_list);
}

int
UILIB_A4GL_fgl_getfldbuf_ap (void *inp, ts_field_name *orig_list,va_list * ap)
{
  int context;
  char *argp;
  int n;
  A4GL_push_char ("XML");
  A4GL_push_int (((long) inp) & 0xffffffff);
  uilib_get_context (2);
  context = A4GL_pop_int ();

  A4GL_push_int (context);
  n = 1;
  while ((argp = va_arg (*ap, char *)))
    {
      int i;
      i = va_arg (*ap, int);
      A4GL_trim (argp);
      A4GL_push_char (argp);
      n++;
    }
  n = uilib_getfldbuf (n);
  return n;
}

int
UILIB_A4GL_fgl_getfldbuf_ia_ap (void *inp, ts_field_name *orig_list,va_list * ap)
{
  int context;
  char *argp;
  int n;
  A4GL_push_char ("XML");
  A4GL_push_int (((long) inp) & 0xffffffff);
  uilib_get_context (2);
  context = A4GL_pop_int ();

  A4GL_push_int (context);
  n = 1;
  while ((argp = va_arg (*ap, char *)))
    {
      int i;
      i = va_arg (*ap, int);
      A4GL_trim (argp);
      A4GL_push_char (argp);
      n++;
    }
  n = uilib_getfldbuf (n);
  return n;
}


void
UILIB_A4GL_disp_h_menu (void *menu)
{

// Doesn't need to do anything...

}

// NIY ----------------------------------------------------------------------------------


int
UILIB_A4GL_gen_field_list_from_slist (void *field_listv, void *formdetsv, void *listv)
{
  int rval=0;
  niy ();
  return rval;
}

long
UILIB_A4GL_get_option_value_for_current_window (char type)
{
  int rval=0;
  niy ();
  return rval;
}

int
UILIB_A4GL_widget_name_match (void *w, char *name)
{
  int rval=0;
  niy ();
  return rval;
}

int
UILIB_A4GL_disp_form_fields_ap (int n, int attr, char *formname, va_list * ap)
{
  int rval=0;
  niy ();
  return rval;
}


int
UILIB_A4GL_endis_fields_ap (int en_dis, va_list * ap)
{
  int rval=0;
  niy ();
  return rval;
}

void
UILIB_A4GL_clr_form_fields (int to_defaults, char *defs)
{
  niy ();
}



void
UILIB_A4GL_gui_run_til_no_more ()
{
  niy ();
}


int
UILIB_aclfgl_a4gl_set_page (int n)
{
  int b;
  b = A4GL_pop_int ();
  send_to_ui ("<SETPAGE=\%d\"/>", b);
  return 0;
}

int
UILIB_aclfgl_a4gl_get_page (int n)
{
  int rval=0;
  niy ();
  return rval;
}

int
UILIB_aclfgl_a4gl_run_gui (int nargs)
{
  int rval=0;
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
  int rval=0;
  niy ();
  return rval;
}


void *
UILIB_A4GL_make_pixmap_gw (char *filename)
{
  void *rval=NULL;
  niy ();
  return rval;
}



void
UILIB_A4GL_init_color (int n, int r, int g, int b)
{
  niy ();
}



int
UILIB_A4GL_fgl_fieldtouched_input_ap (void *input, va_list * ap)
{
  int context;
  char *argp;
  int n;
  A4GL_push_char ("XML");
  A4GL_push_int (((long) input) & 0xffffffff);
  uilib_get_context (2);
  context = A4GL_pop_int ();
  A4GL_push_int (context);
  n = 1;

  while ((argp = va_arg (*ap, char *)))
    {
      int i;
      i = va_arg (*ap, int);
      A4GL_trim (argp);
      A4GL_push_char (argp);
      n++;
    }
  n = uilib_touched (n);
  return n;


}

int
UILIB_A4GL_fgl_fieldtouched_input_array_ap (void *input, va_list * ap)
{
  int context;
  char *argp;
  int n;
  A4GL_push_char ("XML");
  A4GL_push_int (((long) input) & 0xffffffff);
  uilib_get_context (2);
  context = A4GL_pop_int ();
  A4GL_push_int (context);
  n = 1;

  while ((argp = va_arg (*ap, char *)))
    {
      int i;
      i = va_arg (*ap, int);
      A4GL_trim (argp);
      A4GL_push_char (argp);
      n++;
    }
  n = uilib_touched (n);
  return n;
}

void
UILIB_A4GL_acli_scroll_ap (int n, va_list * ap)
{
  char *arr;

  arr = va_arg (*ap, char *);
  send_to_ui ("<SCROLL BY=\"%d\" ARRAY=\"%s\"/>", n, arr);
}

int
UILIB_A4GL_get_key (int timeout)
{
  //char buff[2000];
  int a;
  char *s;
  send_to_ui ("<GETKEY/><WAITFOREVENT/>");
  flush_ui ();
  a = get_event_from_ui (NULL);
  uilib_last_received_key ();
  s = A4GL_char_pop ();
  if (s)
    {

      if (strlen (s) == 0)
	{
	  a = 0;
	}
      else
	{
	  a = atoi (s);
	  free (s);
	}
    }
  else
    {
      a = 0;
    }
  return a;
}

void *
UILIB_A4GL_create_menu (void *m, char *id, int mode, void *handler)
{
  void *rval=NULL;
  niy ();
  return rval;
}


int
UILIB_aclfgl_fgl_set_arrline (int nparam)
{
  int b;
  b = A4GL_pop_int ();
  send_to_ui ("<SETARRLINE LINE=\"%d\"/>", b);
  return 0;
}

int
UILIB_aclfgl_fgl_set_scrline (int nparam)
{
  int b;
  b = A4GL_pop_int ();
  send_to_ui ("<SETSCRLINE LINE=\"%d\"/>", b);
  return 0;
}

void
UILIB_A4GL_reset_delims (void *vformdets, void *field, char *delims)
{
  niy ();
}





void cleanup(void) {
      	pipe_clear();
      	send_to_ui ("<PROGRAMSTOP ID=\"%d\"/>",  get_ui_id ('r'));
	 flush_ui ();

      	unlink (stderr_fname);
	if (def_stderr) fclose(def_stderr);
	if (strlen(stderr_fname)) {
      		unlink (stderr_fname);
	}
}

#ifdef MOVED
void
merge_labels (struct s_form_dets *formdets)
{
	make_screen(formdets->fileform);
}


void
new_field (int y, int x, int w, char because_of, int fstart)
{
  char buff[200];
  strcpy (buff, &screen[y][x]);
  buff[w] = 0;

  nfields++;
  screen_convert_fields = realloc (screen_convert_fields, sizeof (struct s_field) * nfields);
  screen_convert_fields[nfields - 1].x = x;
  screen_convert_fields[nfields - 1].y = y;
  screen_convert_fields[nfields - 1].w = w;
  screen_convert_fields[nfields - 1].label = strdup (buff);
  screen_convert_fields[nfields - 1].field_start = fstart;
}
#endif




void dump_form_labels(void) {
int a;
int nfields;
nfields=get_num_labels();
for (a=0;a<nfields;a++) {
	int x;
	int y;
	char *label;
	get_label(a,&label,&x,&y);
  send_to_ui ("<FORMLABEL ROW=\"%d\" COLUMN=\"%d\">%s</FORMLABEL>", 
			y,
			x, uilib_xml_escape (label));
}

}

#ifdef MOVED
int
has_label (int x, int y, int w, int set, int fy)
{
  int a;
  int ok;
  int start_in;
  int end_in;
// Find any labels matching on this line over this field
  for (a = 0; a < nfields; a++)
    {
      if (screen_convert_fields[a].label == 0)
	continue;

      if (screen_convert_fields[a].y != y)
	continue;

      //
      //         LABEL
      //
      //          [ ]                   /1
      //          [                 ]   /2
      //     [     ]                    /3
      //    [             ]             /4
      //
      //
      ok = 0;
      start_in = 0;
      if (x >= screen_convert_fields[a].x && x <= screen_convert_fields[a].x + strlen (screen_convert_fields[a].label))
	start_in = 1;


      end_in = 0;
      if (x + w >= screen_convert_fields[a].x
	  && x + w <= screen_convert_fields[a].x + strlen (screen_convert_fields[a].label))
	end_in = 1;


      if (end_in || start_in)
	ok = 1;
      if (x <= screen_convert_fields[a].x && x + w >= screen_convert_fields[a].x + strlen (screen_convert_fields[a].label))
	ok = 2;

      if (set && ok && 0 )
	{
	  screen_convert_fields[a].field_start = x;
	  screen_convert_fields[a].y = fy;

	  return ok;
	}
      if (ok)
	return ok;
    }

  return 0;
}


void make_screen (struct_form * f)
{
  int x, y;
  int spc;
  int a;
  int fno;
  int b;

  if (f->maxcol > 200 || f->maxline > 200)
    {
      printf ("Too wide or too long\n");
      exit (1);
    }
  for (y = 0; y < f->maxline; y++)
    {
      memset (screen[y], ' ', f->maxcol);
      screen[y][f->maxcol + 1] = 0;
    }

  for (a = 0; a < f->metrics.metrics_len; a++)
    {
      int w;
      x = f->metrics.metrics_val[a].x;
      y = f->metrics.metrics_val[a].y;
      w = f->metrics.metrics_val[a].w;

      if (f->metrics.metrics_val[a].scr != 1)
	{
	  printf ("Not on a single screen\n");
	  exit (1);
	}


      if (f->metrics.metrics_val[a].label[0] == '\n')
	continue;		// Ignore graphics characters-  line drawing
      if (strncmp(f->metrics.metrics_val[a].label ,"nl;",3)==0) {
		continue;
	}


      if (strlen (f->metrics.metrics_val[a].label))
	{
	  strncpy (&screen[y][x], f->metrics.metrics_val[a].label,
		   strlen (f->metrics.metrics_val[a].label));
	}
      else
	{
	  screen[y][x] = 1;
	  screen[y][x + w + 1] = 2;
	}
    }


// We've now got our screen reassembled - now look for any fields which are single spaced delimited...
//
//

  for (y = 0; y < f->maxline; y++)
    {

      // Convert all ':' to spaces - they'd look rubbish anyway....
      for (x = 0; x < f->maxcol; x++)
	{
	  if (screen[y][x] == ':')
	    screen[y][x] = ' ';
	}

      for (x = 0; x < f->maxcol; x++)
	{
	  int because_of=0;
	  int w;
	  int w2;
	  int fstart = -1;
	  if (screen[y][x] != ' ' && screen[y][x] != 1 && screen[y][x] != 2)
	    {
	      for (w = x + 1; w <= f->maxcol; w++)
		{
		  if (screen[y][w - 1] == ' ' && screen[y][w] == 0)
		    {
		      because_of = ' ';
		      break;
		    }		// more than 1 space
		  if (screen[y][w - 1] == ' ' && screen[y][w] == ' ')
		    {
		      because_of = ' ';
		      break;
		    }		// more than 1 space
		  if (screen[y][w] == 1 || screen[y][w] == 2)
		    {
		      because_of = '[';
		      fstart = w;
		      break;
		    }		// a field
		}

	      if (because_of == ' ')
		{
		  for (w2 = w; w2 < f->maxcol; w2++)
		    {
		      if (screen[y][w2] == ' ')
			continue;
		      if (screen[y][w2] == 1)
			{
			  fstart = w2;
			  break;
			}
		      break;
		    }
		}
	      new_field (y, x, w - x - 1, because_of, fstart);
	      memset (&screen[y][x], ' ', w - x - 1);
	    }
	}
    }


  for (a = 0; a < f->attributes.attributes_len; a++)
    {
      int mno;
      int ok;
      int w;

      fno = f->attributes.attributes_val[a].field_no;
      if (f->fields.fields_val[fno].metric.metric_len <= 1)
	continue;
      mno = f->fields.fields_val[fno].metric.metric_val[0];

      // We've got an array of these - normally they'd all start at the same 'x' - so lets check
      x = f->metrics.metrics_val[mno].x;
      y = f->metrics.metrics_val[mno].y;
      ok = 1;

      for (b = 1; b < f->fields.fields_val[fno].metric.metric_len; b++)
	{
	  mno = f->fields.fields_val[fno].metric.metric_val[b];
	  if (x != f->metrics.metrics_val[mno].x)
	    {
	      ok = 0;
	      break;
	    }
	  if (y + b != f->metrics.metrics_val[mno].y)
	    {
	      ok = 0;
	      break;
	    }			// Must be contiguous down the page too
	}
      if (ok == 0)
	continue;

      // if we've got to here all ourt fields line up
      //
      mno = f->fields.fields_val[fno].metric.metric_val[0];
      w = f->metrics.metrics_val[mno].w;
      x = f->metrics.metrics_val[mno].x;
      y = f->metrics.metrics_val[mno].y;

      if (has_label (x, y - 1, w, 0, y))
	{
	  //printf("Found 1\n");
	  has_label (x, y - 1, w, 1, y);
	}
      else
	{
	  if (has_label (x, y - 2, w, 0, y))
	    {
	      //printf("Found 2\n");
	      has_label (x, y - 2, w, 1, y);
	    }
	}


    }


}

#endif

static char *get_field_with_subscript_as_string(char *field, int i) {
static char buff[200];
char fld2[200];
char *ptr;
if (i!=0 && i!=1) {
	strcpy(fld2,field);
	// Does the field contain a '.'
	ptr=strchr(fld2,'.');
	if (ptr) {
		*ptr=0;
		ptr++;
		sprintf(buff,"%s[%d].%s",fld2,i,ptr);
	} else {
		sprintf(buff,"%s[%d]",field,i);
	}
	return buff;
}
sprintf(buff,"%s",field);
return buff;
}



/*
 This function sets a value which is used for the
 beginning and end of field delimiters (normally [ and ] )
 so that they can be easily changed from the 4gl code

 This is normally done to emulate the isql perform action
 where only the fields for the current form have their '[' and ']'
 displayed.

 In order to use this value - you have to DISPLAY something to the field

        Example usage :


        call aclfgl_set_display_field_delimiters("  ")
        display "hh" to tabname
        call aclfgl_set_display_field_delimiters("[]")
        display "hh" to tabname
*/
int UILIB_aclfgl_aclfgl_set_display_field_delimiters(int n) {
	char *s;
	s=A4GL_char_pop();
	send_to_ui("<FIELDDELIMITERS DELIMS=\"%s\"/>",uilib_xml_escape(s));
	return 0;
}


void UILIB_A4GL_ui_frontcall(char *module, char*name, void *vibind, int ni, void *vobind, int no) {
struct BINDING *ibind;
struct BINDING *obind;
char buff[100000];
char smbuff[20000];
obind=vobind;
ibind=vibind;
sprintf(buff,"<FRONTCALL MODULE=\"%s\" NAME=\"%s\" EXPECT=\"%d\">",uilib_xml_escape(module),uilib_xml_escape(name),no);
if (ni) {
	int a;
	strcat(buff,"<VS>");
	for (a=0;a<ni;a++) {
		char *ptr;
		 A4GL_push_param (ibind[a].ptr, ibind[a].dtype + ENCODE_SIZE (ibind[a].size));
		ptr=A4GL_char_pop();
		A4GL_trim(ptr);
		sprintf(smbuff,"<V>%s</V>",uilib_xml_escape(ptr));
		strcat(buff,smbuff);
		free(ptr);
	}
	strcat(buff,"</VS>");
}
strcat(buff,"</FRONTCALL>");
if (uilib_do_frontcall(buff,no)) {
	int a;
	for (a=no-1;a>=0;a--){ 
	      A4GL_pop_var2 (obind[a].ptr,obind[a].dtype, obind[a].size);
	}
}
}

void UILIB_A4GL_ui_cancel( int n) {
if (n==0)  {
	send_to_ui("<CANCEL_INSERT/>");
}	else {
	send_to_ui("<CANCEL_DELETE/>");
}
}



int UILIB_A4GL_ui_send_report_to_ui(char *filename, int linesPerPage,char *mode) {
      return PrintFile (filename, linesPerPage,mode);
}

