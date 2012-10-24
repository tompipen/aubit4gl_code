#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "xml/attr.h"
#include "../debug.h"
#include "../pipe.h"
#include "uilib.h"
#include "comms.h"
#include "fglsys.h"

#ifndef WIN32
#include <iconv.h>
#endif

char * A4GL_lrtrim (char *str);
char *A4GL_pull_off_data_for_display (int n, int display_type);



#define DTYPE_CHAR      0
#define DTYPE_SMINT     1
#define DTYPE_INT       2
#define DTYPE_FLOAT     3
#define DTYPE_SMFLOAT   4
#define DTYPE_DECIMAL   5
#define DTYPE_SERIAL    6
#define DTYPE_DATE      7
#define DTYPE_MONEY     8
#define DTYPE_NULL      9
#define DTYPE_DTIME     10
#define DTYPE_BYTE      11
#define DTYPE_TEXT      12
#define DTYPE_VCHAR     13
#define DTYPE_INTERVAL  14
#define DTYPE_NCHAR  15
#define DTYPE_NVCHAR  16
#define DTYPE_INT8         17
#define DTYPE_SERIAL8      18
#define DTYPE_OBJECT    99
#define DTYPE_BINDING    95
#define DTYPE_MASK          255


void A4GL_trim(char *s) ;
void A4GL_push_null (int dtype,int size);
size_t A4GL_base64_decode(const char *src, unsigned char **outptr);
void A4GL_get_top_of_stack (int a, int *d, int *s, void **ptr);


static void local_trim (char *p);
void brpoint (void);		// DUMMY FUNCTION USED FOR DEBUGGING...

static int field_match (char *a, char *b);
static char *last_field_list = 0;
static int m_arr_curr = 0;
static int m_scr_line = 0;
static int m_arr_count = 0;
char *mLastKey = 0;
static char lastInfield[255]="";

#include "contexts.h"

extern struct s_attr *last_attr;

int ncontexts = 0;
struct ui_context *contexts = 0;
static char **get_args (int nargs);
static void send_input_array_change (int ci);

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
  return 'x';
}
*/


static char *
xml_escape_int (char *s)
{
  static char *buff = 0;
  static int last_len = 0;
  int c;
  int a;
  int l;
  int b;
  int allocated;
int sl;

A4GL_assertion(s==NULL,"Null pointer passed to xml_escape_int");

sl=strlen(s);

  c = 0;
  //if (s==0) return "";
  for (a=0;a<sl;a++) {
  		if (s[a]=='&' || s[a]=='<' || s[a]=='>' || s[a]=='"' || s[a]=='\'' || s[a]=='\n'  || s[a]=='\r' || s[a] < 31 || s[a] > 126) {
				c++;
			 break;
		}

  	}



  if (c == 0)
    {
      return s;
    }

  l = strlen (s);
  allocated = (l * 6) + 1;

  if (l > last_len)
    {
      buff = realloc (buff, allocated);
      last_len = l;
    }

  b = 0;
  for (a = 0; a < l; a++)
    {
      if (s[a] == '>')
	{
	  buff[b++] = '&';
	  buff[b++] = 'g';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '<')
	{
	  buff[b++] = '&';
	  buff[b++] = 'l';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '&')
	{
	  buff[b++] = '&';
	  buff[b++] = 'a';
	  buff[b++] = 'm';
	  buff[b++] = 'p';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '"')
	{
	  buff[b++] = '&';
	  buff[b++] = 'q';
	  buff[b++] = 'u';
	  buff[b++] = 'o';
	  buff[b++] = 't';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] == '\'')
	{
	  buff[b++] = '&';
	  buff[b++] = 'a';
	  buff[b++] = 'p';
	  buff[b++] = 'o';
	  buff[b++] = 's';
	  buff[b++] = ';';
	  continue;
	}
      if (s[a] < 31 || s[a] > 126)
	{
	  int z1;
	  char buff2[20];
	  z1 = ((unsigned char) s[a]);
	  sprintf (buff2, "&#x%02X;", z1);
	  for (z1 = 0; z1 < strlen (buff2); z1++)
	    {
	      buff[b++] = buff2[z1];
	    }
	  continue;
	}
      buff[b++] = s[a];
    }
if (b>=allocated) {

fprintf(stderr,"b=%d allocated=%d l=%d\n", b,allocated,l);
}
  if (b >= allocated ) {
	fprintf(stderr, "XML escape buffer too small") ;
	exit(2);
  }
  buff[b] = 0;
  return buff;
}


#ifdef WIN32 
char *char_encode(char *s) {
	return s;
}
#else

int set_iconv=0;

iconv_t convin=(iconv_t)-1;
iconv_t convout=(iconv_t)-1;


static void set_encode(void) {
	if (set_iconv) {
		return;
	}
	set_iconv=1;
	char *client=getenv("A4GL_CLIENTENCODING");
	char *server=getenv("A4GL_SERVERENCODING");
	if (client && strlen(client) && server && strlen(server)) {
			convout=iconv_open(client,server);
			convin=iconv_open(server,client);
	}
}

static char *char_encode_internal(char *s,char direction) {
	if (!set_iconv) {
		set_encode();
	}
	if (( convout!=(iconv_t)-1 && direction=='o') || (convin!=(iconv_t)-1 && direction=='i') ) {
		size_t l;
		size_t rval=-1;
		size_t obuffsz;
		static char *obuff[10]={0,0,0,0,0,0,0,0,0,0};
		static int obuffcnt=-1;
		char *optr;
		obuffcnt++;
		if (obuff[obuffcnt]) free(obuff[obuffcnt]);
		l=strlen(s);
		obuffsz=l*4+1;

		obuff[obuffcnt]=malloc(obuffsz);
		memset(obuff[obuffcnt],0,obuffsz);
		optr=obuff[obuffcnt];
		if (direction=='o') {
			rval=iconv(convout,&s,&l,&optr,&obuffsz);
			//printf("DIRO - rval=%d l=%d obuffsz=%d:%s\n",rval,l,obuffsz, obuff[obuffcnt]);
		} 
		if (direction=='i') {
			rval=iconv(convin,&s,&l,&optr,&obuffsz);
			//printf("DIRI - rval=%d\n",rval);
		}
		if (rval<0) {
			return s;
		}

		return obuff[obuffcnt];
	}
	return s;
}

char *char_encode(char *s) {
	return char_encode_internal(s,'o');
}

char *char_decode(char *s) {
	return char_encode_internal(s,'i');
}

#endif


static char *
xml_escape (char *s) {
char *rval;
static int n=0;
static char *buff[5]={NULL,NULL,NULL,NULL,NULL};

if (buff[n]) {
	free(buff[n]); 
	buff[n]=0;
}

buff[n]=strdup(xml_escape_int(s));


rval=buff[n];
n++;
if (n>=5)  n=0;
return rval;

}

char *
uilib_xml_escape (char *s)
{
  return xml_escape (s);
}

/*
static char *xml_unescape(char *s) {
static char *buff=0;
static int last_len=0;
int b;
int a;
int l;
l=strlen(s);
if (strchr(s,'&')==0) return s;

if (l>last_len) {
	buff=realloc(buff,l+1);
	last_len=l;
}
b=0;
for (a=0;a<l;a++) {
	if (s[a]!='&') {
		buff[b++]=s[a];
		continue;
	}
	if (s[a+1]=='g' && s[a+2]=='t' && s[a+3]==';') {
		buff[b++]='>';
		a+=3;
	}
	if (s[a+1]=='l' && s[a+2]=='t' && s[a+3]==';') {
		buff[b++]='<';
		a+=3;
	}
	if (s[a+1]=='a' && s[a+2]=='m' && s[a+3]=='p' && s[a+4]==';') {
		buff[b++]='&';
		a+=3;
	}
	fprintf(stderr, "Unexpected escaped XML string: %s\n", s);
	exit(4);
}
buff[b]=0;
return buff;
}
*/


/*
 *******************************************************************************
 */
static int
new_context (enum uitype ui, char *module, int lineno)
{
  int c = -1;
  int a;
  UIdebug (5, "New context request for uitype=%d module=%s line=%d ncontexts=%d", ui, module, lineno, ncontexts);
  for (a = 0; a < ncontexts; a++)
    {
      if (contexts[a].state != UI_FREE)
	{
	  UIdebug (9, "Current Context %d: %d %s %d\n", a, ui, module, lineno);
	  if (contexts[a].type == ui && strcmp (contexts[a].modulename, module) == 0 && contexts[a].lineno == lineno)
	    {
	      contexts[a].state = UI_NOT_INITIALIZED;
	      UIdebug (1, "CONTEXT ALREADY IN USE - HAS IT NOT BEEN FREED BEFORE ? ******");
	      return a;
	    }
	}
    }

  // Anything free we can use ? 
  for (a = 0; a < ncontexts; a++)
    {
      if (contexts[a].state == UI_FREE)
	{
	  c = a;
	  UIdebug (5, "Free slot found at @%d", c);
	  break;
	}
    }
  if (c == -1)
    {
      ncontexts++;
      contexts = realloc (contexts, sizeof (struct ui_context) * ncontexts);
      c = ncontexts - 1;
    }

  contexts[c].type = ui;
  contexts[c].state = UI_NOT_INITIALIZED;
  contexts[c].modulename = module;
  contexts[c].lineno = lineno;

  contexts[c].nPendingTriggereds=0;

  UIdebug (5, "New context generated as %d for %s %d", c, module, lineno);
  return c;
}



char *A4GL_char_pop(void);

/*
 *******************************************************************************
 */
static char *
charpop (void)
{
  char s[1024];

  return A4GL_char_pop();

  popstring (s, 1023);
  local_trim (s);
  return strdup (s);
}

static void
PUSHquote (char *s)
{
  //printf("Pushing %s\n",s);
  pushquote (s, strlen (s));
}


/*
 *******************************************************************************
 */
static int
POPint (void)
{
  int a;
  popint (&a);
  return a;

}

/*
 *******************************************************************************
 */
int
uilib_start (int nargs)
{
  char *s;
  if (!connect_ui ())
    {
      pushint (0);
      return 1;
    }
  s = charpop ();
  send_to_ui ("<PROGRAMSTARTUP PROGRAMNAME=\"%s\" ID=\"%d\"/>", s, get_ui_id ('r'));
  flush_ui ();
  free (s);
  pushint (1);
  return 1;
}

/*
 *******************************************************************************
 */

int
uilib_program_exit (int nargs)
{
  int n;
  n = POPint ();
  send_to_ui ("<PROGRAMSTOP EXITCODE=\"%d\" ID=\"%d\"/>", n, get_ui_id ('r'));
  flush_ui ();
  return 0;

}

/*
 *******************************************************************************
 */
int
uilib_clear_screen (int nargs)
{
  send_to_ui ("<CLEARSCREEN/>");
  return 0;
}

/*
 *******************************************************************************
 */
int
uilib_clear_window (int nargs)
{
  char *s;
  s = charpop ();
  send_to_ui ("<CLEARWINDOW WINDOW=\"%s\"/>", s);
  free (s);
  return 0;
}

int
uilib_set_field_list_directly (char *s)
{
  if (last_field_list)
    {
      free (last_field_list);
    }
  last_field_list = strdup (s);
  return 0;
}

/*
 *******************************************************************************
 */
int
uilib_set_field_list (int nargs)
{
  char *buffer;
  int l = 0;
  char **args;
  int a;
  if (last_field_list)
    {
      free (last_field_list);
    }
  args = malloc (sizeof (char *) * nargs);
  for (a = 0; a < nargs; a++)
    {
      args[a] = charpop ();
      l += strlen (args[a]) + 40;
    }
  l += 40;			// Allow some for header/footer


  if (last_field_list)
    free (last_field_list);
  buffer = malloc (l);
  last_field_list = buffer;
  sprintf (buffer, "<FIELDLIST>\n");
  for (a = nargs - 1; a >= 0; a--)
    {
      char smbuff[256];
      sprintf (smbuff, " <FIELD NAME=\"%s\"/>\n", args[a]);
      free (args[a]);
      strcat (buffer, smbuff);
    }
  strcat (buffer, "</FIELDLIST>\n");
  free (args);
  return 0;
}


/*
 *******************************************************************************
 */

int
uilib_display_values (int nargs)
{
  char **args;
  long *args_dtypes;
  long *args_sizes;
  char *attr;
  int a;
  attr = charpop ();		// Attribute
  nargs--;
  args = malloc (sizeof (char *) * nargs);
  args_dtypes = malloc (sizeof (long) * nargs);
  args_sizes = malloc (sizeof (long) * nargs);
  for (a = 0; a < nargs; a++)
    {
	int d1;
	int s1;
	void *p1;

	args_dtypes[a]=-1;
	args_sizes[a]=0;
//Aubit4GL specific code...
	A4GL_get_top_of_stack (1, &d1, &s1, (void *) &p1);
	args_dtypes[a]=d1;
	args_sizes[a]=s1;
//End of Aubit4GL specific code

      	args[a] = get_data_from_stack(NULL,NULL);

    }

  send_to_ui ("<DISPLAYTO ATTRIBUTE=\"%s\">%s<VALUES>", attr, last_field_list);
  for (a = nargs - 1; a >= 0; a--)
    {
	if (args_dtypes[a]!=-1) {
      		send_to_ui ("<TEXT DTYPE=\"%d\">%s</TEXT>", args_dtypes[a], xml_escape (char_encode(args[a])));
	} else {
      		send_to_ui ("<TEXT>%s</TEXT>", xml_escape (char_encode(args[a])));
	}
      free (args[a]);
    }

  send_to_ui ("</VALUES></DISPLAYTO>");

  free (args);
  free (args_dtypes);
  free (args_sizes);
  free (attr);
  return 0;
}


/*
 *******************************************************************************
 */
int
uilib_clear_fields (int nargs)
{
  send_to_ui ("<CLEAR>%s</CLEAR>", last_field_list);
  return 0;
}

/*
 *******************************************************************************
 */
int
uilib_clear_form (int nargs)
{
  int n;
  n = POPint ();
  if (n)
    {
      send_to_ui ("<CLEARFORM TODEFAULTS=\"1\"/>");
    }
  else
    {
      send_to_ui ("<CLEARFORM TODEFAULTS=\"0\"/>");
    }
  return 0;
}


/*
 *******************************************************************************
 */
int
uilib_close_form (int nargs)
{
  char *s;
  s = charpop ();
  send_to_ui ("<CLOSEFORM FORM=\"%s\"/>", s);
  free (s);
  return 0;
}

/*
 *******************************************************************************
 */
int
uilib_close_window (int nargs)
{
  char *s;
  s = charpop ();
  send_to_ui ("<CLOSEWINDOW WINDOW=\"%s\"/>", s);
  free (s);
  return 0;
}

/*
 *******************************************************************************
 */
int
uilib_error (int nargs)
{
  char *s;
  char *a = "";
  //a = charpop ();
  s = charpop ();
  send_to_ui ("<ERROR ATTRIBUTE=\"%s\">%s</ERROR>", a, xml_escape (char_encode(s)));
  free (s);
  return 0;
}

/*
 *******************************************************************************
 */
int
uilib_message (int nargs)
{
  char *s;
  char *a;
  int wait;
  wait=POPint();
  a = charpop ();
  s = charpop ();
  send_to_ui ("<MESSAGE ATTRIBUTE=\"%s\" WAIT=\"%d\">%s</MESSAGE>", a, wait, xml_escape (char_encode(s)));
  free (s);
  free (a);
  return 0;
}


/*
 *******************************************************************************
 */
int
uilib_displayat (int nargs)
{
  int x;
  int y;
  char *s;
  char *a;
  x = POPint ();
  y = POPint ();
  a = charpop ();
  s = charpop ();
  send_to_ui ("<DISPLAYAT X=\"%d\" Y=\"%d\" ATTRIBUTE=\"%d\">%s</DISPLAYAT>", x, y, a, xml_escape (char_encode(s)));
  free (s);
  free (a);
  return 0;
}


/*
 *******************************************************************************
 * Line mode
 *
 */
int
uilib_display (int nargs)
{
  char *s;
  s = charpop ();
  send_to_ui ("<DISPLAY>%s</DISPLAY>", xml_escape (char_encode(s)));
  free (s);
  return 0;
}

/*
 *******************************************************************************
 */

int
uilib_options (int nargs)
{
  char *s;
  char *v;
  v = charpop ();
  s = charpop ();
  send_to_ui ("<OPTIONS TYPE=\"%s\" VALUE=\"%s\"/>", s, v);
  free (s);
  free (v);
  return 0;
}

/*
 *******************************************************************************
 */
int
uilib_open_form (int nargs)
{
  char *src;
  char *fname;
  fname = charpop ();
  src = charpop ();
  send_to_ui ("<OPENFORM FORM=\"%s\" SOURCE=\"%s\"/>", src, fname);
  free (src);
  free (fname);
  return 0;
}

/*
 *******************************************************************************
 */
int
uilib_display_form (int nargs)
{
  char *fname;
  char *attrib;
  attrib = charpop ();
  fname = charpop ();
  send_to_ui ("<DISPLAYFORM FORM=\"%s\" ATTRIBUTE=\"%s\"/>", fname, attrib);
  free (fname);
  free (attrib);
  return 0;
}

/*
 *******************************************************************************
 */
int
uilib_current_window (int nargs)
{
  char *wname;
  wname = charpop ();
  send_to_ui ("<CURRENTWINDOW WINDOW=\"%s\"/>", wname);
  free (wname);
  return 0;
}

/*
 *******************************************************************************
 */

int
uilib_sleep (int nargs)
{
  int n;
  n = POPint ();
  send_to_ui ("<SLEEP PAUSE=\"%d\"/>", n);
  flush_ui ();
#ifdef __WIN32__
  Sleep (n);
#else
  sleep (n);
#endif
  return 0;
}



/*
 *******************************************************************************
 */

int
uilib_open_window_with_form (int n)
{
  int x;
  int y;
  char *a;			// Attribute
  char *w;			// window name
  char *f;			// formname
  a = charpop ();
  f = charpop ();
  x = POPint ();
  y = POPint ();
  w = charpop ();

  send_to_ui ("<OPENWINDOWWITHFORM WINDOW=\"%s\" X=\"%d\" Y=\"%d\" ATTRIBUTE=\"%s\" SOURCE=\"%s\"/>", w, x, y, a, f);
  free (f);
  free (a);
  free (w);
  return 0;
}

/*
 *******************************************************************************
 */

int
uilib_open_window (int n)
{
  int x;
  int y;
  char *a;			// Attribute
  char *w;			// window name
  int c;
  int r;
  a = charpop ();

  c = POPint ();
  r = POPint ();

  x = POPint ();
  y = POPint ();
  w = charpop ();
  send_to_ui ("<OPENWINDOW WINDOW=\"%s\" X=\"%d\" Y=\"%d\" ROWS=\"%d\" COLUMNS=\"%d\" ATTRIBUTE=\"%s\"/>", w, x, y, r, c, a);
  free (a);
  return 0;
}


/*
 *******************************************************************************
 */


/* PROMPT HANDLING */

int
uilib_prompt_start (int n)
{
  int cprompt;
  char *promptstr;
  char *prompt_attr;
  char *field_attr;
  char *text;
  char *style;
  int ln;
  char *mod;
  int helpno;
  int charmode;
int dtype;

  dtype=POPint();

  style = charpop ();
  text = charpop ();
  helpno = POPint ();
  charmode = POPint ();
  field_attr = charpop ();
  prompt_attr = charpop ();
  promptstr = charpop ();
  ln = POPint ();
  mod = charpop ();


  cprompt = new_context (UIPROMPT, mod, ln);

  contexts[cprompt].ui.prompt.promptresult = 0;
  suspend_flush (1);
  send_to_ui
    ("<PROMPT CONTEXT=\"%d\" PROMPTATTRIBUTE=\"%s\" FIELDATTRIBUTE=\"%s\" TEXT=\"%s\" CHARMODE=\"%d\" HELPNO=\"%d\" ATTRIB_STYLE=\"%s\" ATTRIB_TEXT=\"%s\" DTYPE_HINT=\"%d\">",
     cprompt, prompt_attr, field_attr, xml_escape(char_encode(promptstr)), charmode, helpno, xml_escape(char_encode(style)), xml_escape(char_encode(text)), dtype);
  free (field_attr);
  free (prompt_attr);
  free (promptstr);
  //pushint (cprompt);
  return 0;
}

int
uilib_prompt_initialised (int n)
{
  suspend_flush (-1);
  send_to_ui ("</PROMPT>");
  return 0;
}

int
uilib_prompt_loop (int n)
{
  int i;
  int context;
  context = POPint ();
  i = 1;


  if (contexts[context].state == UI_NOT_INITIALIZED)
    {
      UIdebug (5, "not initialized\n");
      contexts[context].state = UI_WANT_BEFORE_INPUT;
      // Return -1 to intialize all the control blocks..
      pushint (-1);
      return 1;
    }

  if (contexts[context].state == UI_WANT_BEFORE_INPUT)
    {
      UIdebug (5, "before menu\n");
      // return whatever the before menu was...
      contexts[context].state = UI_INITIALIZED;
      pushint (0);
      return 1;
    }

  send_to_ui ("<WAITFOREVENT CONTEXT=\"%d\" CACHED=\"%d\"/>", context,havePendingTriggers(&contexts[context]));
  flush_ui ();

  while (1)
    {
      contexts[context].ui.prompt.promptresult = 0;
      i = get_event_from_ui (&contexts[context]);
      mLastKey = last_attr->lastkey;
      if (i != -1)
	break;
      send_to_ui ("<WAITFOREVENT CONTEXT=\"%d\" ERR=\"BAD RESPONSE\"/>", context);
      flush_ui ();
    }

  if (last_attr->sync.nvalues)
    {
      // Got a prompt result...
      contexts[context].ui.prompt.promptresult = char_decode(last_attr->sync.vals[0].value);
    }
  pushint (i);
  return 1;
}



int uilib_get_call_result(void) {
int i;
int a;
        i = get_event_from_ui (NULL);
        if (i != -110) { // Not a RETURN... :-(
                return 0;
        }

	for (a=0;a<last_attr->sync.nvalues;a++) {
		PUSHquote(char_decode(last_attr->sync.vals[a].value));
	}
	return last_attr->sync.nvalues;
}

int
uilib_get_prompt_result (int nargs)
{
  int context;
  context = POPint ();
  if (contexts[context].ui.prompt.promptresult)
    {
	if (strlen(contexts[context].ui.prompt.promptresult)) {
      		PUSHquote (contexts[context].ui.prompt.promptresult);
	} else {
		char buff[10];
		memset(buff,0,10);
  		pushquote (buff, 1);
	}
    }
  else
    {
      PUSHquote ("");
    }

  return 1;
}

int
uilib_free_prompt (int nargs)
{
  int context;
  context = POPint ();
  if (contexts[context].ui.prompt.promptresult)
    {
      free (contexts[context].ui.prompt.promptresult);
    }
  contexts[context].state = UI_FREE;
  send_to_ui ("<FREE TYPE=\"PROMPT\" CONTEXT=\"%d\"/>", context);
  return 0;
}


int
uilib_free_display (int nargs)
{
  int context;
  context = POPint ();
  contexts[context].state = UI_FREE;
  send_to_ui ("<FREE TYPE=\"DISPLAY\" CONTEXT=\"%d\"/>", context);
  return 0;
}


/*
 *******************************************************************************
 */


/*
 *******************************************************************************
 */

static char *
no_space (char *s)
{
  int a;
  static char buff[200];
  strcpy (buff, s);
  for (a = 0; a < strlen (buff); a++)
    {
      if (buff[a] == ' ')
	buff[a] = '_';
    }
  return buff;
}

int
uilib_event (int nargs)
{
  char *field_or_key;
  char *evt_type;
  int event_id;
  field_or_key = charpop ();
  evt_type = charpop ();
  event_id = POPint ();

  if (strlen (field_or_key))
    {
      if (strcmp (evt_type, "ONKEY") == 0)
	{
	  send_to_ui (" <%s_EVENT KEY=\"%s\" ID=\"%d\"/>", no_space (evt_type), field_or_key, event_id);
	}
      else
	{
	  if (strcmp (evt_type, "ON ACTION") == 0)
	    {
	      send_to_ui (" <%s_EVENT ACTION=\"%s\" ID=\"%d\"/>", no_space (evt_type), field_or_key, event_id);

	    }
	  else
	    {
	      send_to_ui (" <%s_EVENT FIELD=\"%s\" ID=\"%d\"/>", no_space (evt_type), field_or_key, event_id);
	    }

	}
    }
  else
    {
      send_to_ui (" <%s_EVENT ID=\"%d\"/>", no_space (evt_type), event_id);
    }
  return 0;
}

int
uilib_start_events (int nargs)
{
  send_to_ui ("<EVENTS>");
  return 0;
}



int
uilib_end_events (int nargs)
{
  send_to_ui ("</EVENTS>");
  return 0;
}


/* MENU HANDLING */


int
uilib_hide_option (int nargs)
{
  char *opt;
  int context;
  opt = charpop ();
  context = POPint ();
  send_to_ui ("<HIDEOPTION CONTEXT=\"%d\" OPTION=\"%s\"/>", context, opt);
  free (opt);
  return 0;
}

int
uilib_show_option (int n)
{
  char *opt;
  int context;
  opt = charpop ();
  context = POPint ();
  send_to_ui ("<SHOWOPTION CONTEXT=\"%d\" OPTION=\"%s\"/>", context, opt);
  free (opt);
  return 0;
}

int
uilib_next_option (int n)
{
  char *opt;
  int context;
  opt = charpop ();
  context = POPint ();
  send_to_ui ("<NEXTOPTION CONTEXT=\"%d\" OPTION=\"%s\"/>", context, opt);
  free (opt);
  return 0;
}

int
uilib_menu_add (int nargs)
{
  int context;
  int helpno;
  char *desc;
  char *mn;
  char *keys;
  int id;
  helpno = POPint ();
  desc = charpop ();
  keys = charpop ();
  mn = charpop ();
  id = POPint ();

  A4GL_trim(mn);
  A4GL_trim(desc);

  context = POPint ();
  send_to_ui
    ("<MENUCOMMAND CONTEXT=\"%d\" KEYS=\"%s\" ID=\"%d\" TEXT=\"%s\" DESCRIPTION=\"%s\" HELPNO=\"%d\"/>",
     context, xml_escape(char_encode(keys)), id, xml_escape(char_encode(mn)), xml_escape(char_encode(desc)), helpno);
  return 0;
}


int
uilib_menu_set (int nargs)
{
  int context;
  char *desc;
  char *mn;
  int id;

  desc = charpop ();
  mn = charpop ();
  id = POPint ();
  context = POPint ();

  send_to_ui ("<MENUSET CONTEXT=\"%d\" ID=\"%d\" TEXT=\"%s\" DESCRIPTION=\"%s\"/>", context, id, xml_escape(char_encode(mn)), xml_escape(char_encode(desc)));
  return 0;
}


int
uilib_free_menu (int nargs)
{
  int context;
  context = POPint ();
  UIdebug (6, "free menu : context = %d", context);
  send_to_ui ("<FREE TYPE=\"MENU\" CONTEXT=\"%d\"/>", context);
  contexts[context].state = UI_FREE;
  free (contexts[context].ui.menu.menutitle);
  return 0;

}

int
uilib_menu_loop (int nargs)
{
  int context;
  int i;
  context = POPint ();
  UIdebug (5, "Menu loop - Context=%d state=%d\n", context, contexts[context].state);
  if (contexts[context].state == UI_NOT_INITIALIZED)
    {
      UIdebug (5, "not initialized\n");
      contexts[context].state = UI_WANT_BEFORE_MENU;
      // Return -1 to intialize all the control blocks..
      pushint (-1);
      return 1;
    }

  if (contexts[context].state == UI_WANT_BEFORE_MENU)
    {
      UIdebug (5, "before menu\n");
      // return whatever the before menu was...
      contexts[context].state = UI_AFTER_BEFORE_MENU;
      pushint (0);
      return 1;
    }

  if (contexts[context].state == UI_AFTER_BEFORE_MENU)
    {
      UIdebug (5, "before menu\n");
      // return whatever the before menu was...
      contexts[context].state = UI_INITIALIZED;
      pushint (-2);
      return 1;
    }


  // if we've got to here - we're in our menu loop proper...
  send_to_ui ("<WAITFOREVENT CONTEXT=\"%d\" CACHED=\"%d\"/>", context, havePendingTriggers(&contexts[context]));
  flush_ui ();
  while (1)
    {
      i = get_event_from_ui (&contexts[context]);
      mLastKey = last_attr->lastkey;
      if (i != -1)
	break;
      send_to_ui ("<WAITFOREVENT CONTEXT=\"%d\" ERR=\"BAD RESPONSE\"/>", context);
      flush_ui ();
    }
  pushint (i);
  return 1;

}







int
uilib_menu_start (int nargs)
{
  char *mt;
  int cmenu;
  int ln;
  char *mod;
  char *comment;
  char *image;
  char *style;


  image = charpop ();
  style = charpop ();
  comment = charpop ();

  mt = charpop ();
  ln = POPint ();
  mod = charpop ();


  cmenu = new_context (UIMENU, mod, ln);
  contexts[cmenu].ui.menu.menutitle = mt;
  contexts[cmenu].state = UI_NOT_INITIALIZED;

  UIdebug (5, "Menu start context=%d for %s %d\n", cmenu, mod, ln);
  pushint (cmenu);
  suspend_flush (1);
  send_to_ui ("<MENU CONTEXT=\"%d\" TITLE=\"%s\" COMMENT=\"%s\" STYLE=\"%s\" IMAGE=\"%s\">\n<MENUCOMMANDS>", cmenu, mt, xml_escape(char_encode(comment)),
	      xml_escape(char_encode(style)), xml_escape(char_encode(image)));

  return 0;
}

int
uilib_menu_initialised (int nargs)
{
  int context;
  context = POPint ();
  suspend_flush (-1);
  send_to_ui ("</MENUCOMMANDS>\n</MENU>");
  return 0;
}

/* INPUT HANDLING */
int
uilib_free_input (int nargs)
{
  int context;
  context = POPint ();

  if (contexts[context].type == UICONSTRUCT)
    {
      // confused - should be free_construct...
      pushint (context);
      return uilib_free_construct (1);
    }

  contexts[context].state = UI_FREE;

  if (contexts[context].ui.input.changed) {
    free (contexts[context].ui.input.changed);
	contexts[context].ui.input.changed=0;
  }


  if (contexts[context].ui.input.variable_data) {
    free (contexts[context].ui.input.variable_data);
	contexts[context].ui.input.variable_data=0;
  }

  if (contexts[context].ui.input.touched) {
    free (contexts[context].ui.input.touched);
	contexts[context].ui.input.touched=0;
  }



  send_to_ui ("<FREE TYPE=\"INPUT\" CONTEXT=\"%d\"/>", context);
  return 0;
}


static void set_infield(char *inField) {
	strcpy(lastInfield,inField);
}

int
uilib_input_get_values (int nargs)
{
  int context;
  int a;
  context = POPint ();
  //for (a=contexts[context].ui.input.nfields-1;a>=0;a--) {


  for (a = 0; a < contexts[context].ui.input.nfields; a++)
    {
	char *field_data;
	field_data=contexts[context].ui.input.variable_data[a];
	if (field_data==0) field_data="";

      UIdebug (5, "Pushing input data : %d %s\n", a, field_data);
	
      if (strlen (field_data) == 0)
	{
		//printf("Pushing NULL\n");
	  A4GL_push_null (0, 0);
	}
      else
	{
		//printf("Pushing %s\n", contexts[context].ui.input.variable_data[a]);
	  PUSHquote (contexts[context].ui.input.variable_data[a]);
	}
    }
  return contexts[context].ui.input.nfields;


}

int
uilib_input_loop (int nargs)
{
  int context;
  int i;
  int changed = 0;
  int a;
  char **args;
  int init=0;

  args = get_args (nargs - 1);
  UIdebug (5, "Got args\n");
  context = POPint ();
  nargs--;
  UIdebug (5, "Got context\n");




  UIdebug (5, "Context=%d\n", context);

  if (contexts[context].state == UI_NOT_INITIALIZED)
    {
      UIdebug (5, "not initialized\n");
      contexts[context].state = UI_WANT_BEFORE_INPUT;
      //contexts[context].ui.input.num_field_data = 0;
      //contexts[context].ui.input.field_data = 0;
      //contexts[context].ui.input.variable_data=0;
      // Return -1 to intialize all the control blocks..
      pushint (-1);
      return 1;
    }

  if (contexts[context].state == UI_WANT_BEFORE_INPUT)
    {
      UIdebug (5, "before menu\n");
      // return whatever the before menu was...
      contexts[context].state = UI_INITIALIZED;
      contexts[context].ui.input.infield = 0;
	set_infield("");
      pushint (0);
      return 1;
    }


  if (nargs)
    {
      if (contexts[context].ui.input.variable_data)
	{
	  if (contexts[context].ui.input.changed == 0)
	    {
	      int n;
	      if (contexts[context].ui.input.nfields < nargs)
		n = nargs;
	      else
		n = contexts[context].ui.input.nfields;
	      contexts[context].ui.input.changed = malloc (sizeof (int) * n);
	      for (a = 0; a < n; a++)
		{
		  contexts[context].ui.input.changed[a] = 0;
		}
	    }


	  UIdebug (5, "Got variable_data\n");
	  for (a = 0; a < nargs; a++)
	    {
	      if (contexts[context].ui.input.variable_data[a] == 0)
		{
			if (args[a]) {
		  			contexts[context].ui.input.changed[a] = 1;	// Mark as changed
	//printf("Setting to : %s from args\n",   args[a]);
					contexts[context].ui.input.variable_data[a] = args[a]; 
		      			changed++;
			} else {
		  			contexts[context].ui.input.changed[a] = 0;	// Mark as changed
			}
		}
	      else
		{
		  if (strcmp (contexts[context].ui.input.variable_data[a], args[a]) != 0)
		    {		// Its changed
		      UIdebug (5, "WAS %s NOW %s\n", contexts[context].ui.input.variable_data[a], args[a]);
		      free (contexts[context].ui.input.variable_data[a]);	// Remove old value
		      contexts[context].ui.input.variable_data[a] = args[a];	// Copy in new value
	//printf("Setting to : %s from args (2)\n",   args[a]);
		      contexts[context].ui.input.changed[a] = 1;	// Mark as changed
		      changed++;
		    }
		  else
		    {
		      free (args[a]);
		    }
		}
	    }
	}
      else
	{
	  UIdebug (5, "No variable_data : %d\n", nargs);
	  contexts[context].ui.input.nfields = nargs;
	  contexts[context].ui.input.changed = malloc (sizeof (int) * contexts[context].ui.input.nfields);
	  UIdebug (5, "alloced changed\n");
	  contexts[context].ui.input.variable_data = malloc (sizeof (char *) * contexts[context].ui.input.nfields);
	  contexts[context].ui.input.num_field_data = contexts[context].ui.input.nfields;
	  contexts[context].ui.input.field_data = malloc (sizeof (char *) * contexts[context].ui.input.nfields);
	  for (a = 0; a < contexts[context].ui.input.num_field_data; a++)
	    {
	      contexts[context].ui.input.field_data[a] = 0;
	    }
	  UIdebug (5, "alloced variable_data\n");

	  for (a = 0; a < nargs; a++)
	    {
	      UIdebug (5, "using variable_data : %d\n", nargs);
	      contexts[context].ui.input.changed[a] = 1;
	//printf("Setting to : %s from args (3)\n",   args[a]);
	      contexts[context].ui.input.variable_data[a] = args[a];	// Copy in new value
	      changed++;
	    }
	}
    }

 init=1;
      for (a = 0; a < contexts[context].ui.input.nfields; a++) {
		if (contexts[context].ui.input.variable_data[a]!=0) {
			UIdebug(6,"Variable_data @ %d means its not init\n",a);
			init=0;
			break;
		}
	}
UIdebug(5, "init=%d changed=%d\n", init, changed);
  if (changed || init==0 )			// Although only a single field has changed - we'll send the whole lot
    // we can always change this later...
    {
      send_to_ui ("<WAITFOREVENT CONTEXT=\"%d\" CHANGED=\"%d\" CACHED=\"%d\">", context,changed, havePendingTriggers(&contexts[context]));
	
      // Changed data...
      send_to_ui (" <VS>");
      for (a = 0; a < contexts[context].ui.input.nfields; a++)
	{
	  send_to_ui ("  <V CHANGED=\"%d\">%s</V>",
		      contexts[context].ui.input.changed[a], xml_escape (char_encode(contexts[context].ui.input.variable_data[a])));
	}
      send_to_ui (" </VS>");
      if (contexts[context].ui.input.setfield)
	{
	  send_to_ui ("<SETFIELD FIELD=\"%s\"/>", contexts[context].ui.input.setfield);
	  free (contexts[context].ui.input.setfield);
	  contexts[context].ui.input.setfield = 0;
	}

      send_to_ui ("</WAITFOREVENT>");
      flush_ui ();
    }
  else
    {
      send_to_ui ("<WAITFOREVENT CONTEXT=\"%d\" CACHED=\"%d\"/>", context,havePendingTriggers(&contexts[context]));
      flush_ui ();
    }

  while (1)
    {
      i = get_event_from_ui (&contexts[context]);
      mLastKey = last_attr->lastkey;
      if (i != -1)
	break;
      send_to_ui ("<WAITFOREVENT CONTEXT=\"%d\" ERR=\"BAD RESPONSE\"/>", context);
      flush_ui ();
    }

  if (last_attr->sync.nvalues)	// Did we get some field values back ? 
    {
      for (a = 0; a < last_attr->sync.nvalues; a++)
	{
	  if (contexts[context].ui.input.num_field_data < last_attr->sync.nvalues)
	    {
	      fprintf (stderr,"contexts[context].ui.input.num_field_data=%d ", contexts[context].ui.input.num_field_data);
	      fprintf (stderr,"last_attr->sync.nvalues=%d\n", last_attr->sync.nvalues);
		
	     fprintf (stderr, "too many values sent back");
	exit(2);
	    }
	  if (contexts[context].ui.input.variable_data[a])
	    {
	      free (contexts[context].ui.input.variable_data[a]);
	      contexts[context].ui.input.variable_data[a] = 0;
	    }
	  if (contexts[context].ui.input.field_data[a])
	    {
	      free (contexts[context].ui.input.field_data[a]);
	      contexts[context].ui.input.field_data[a] = 0;
	    }

	//printf("Setting to : %s\n",  last_attr->sync.vals[a].value);
	  contexts[context].ui.input.variable_data[a] = char_decode(last_attr->sync.vals[a].value);
	  contexts[context].ui.input.touched[a] = last_attr->sync.vals[a].touched;


	  if (contexts[context].ui.input.field_data)
	    {
	      if (last_attr->sync.vals[a].fieldname)
		{
		  contexts[context].ui.input.field_data[a] = last_attr->sync.vals[a].fieldname;
		}
	    }
	}
    }
  if (last_attr->infield)
    {
      if (contexts[context].ui.input.infield)
	free (contexts[context].ui.input.infield);
      contexts[context].ui.input.infield = strdup (last_attr->infield);
	set_infield(contexts[context].ui.input.infield);
    }
  pushint (i);
  return 1;
}



static void
free_args (char **args)
{
  int a;
  for (a = 0; args[a]; a++)
    {
      free (args[a]);
    }
  free (args);
}



static char **
get_args (int nargs)
{
  char **args;
  int a;

  UIdebug (5, "In get_args\n");
  args = malloc (sizeof (char *) * (nargs + 1));
  UIdebug (5, "Alloc args : %d\n", nargs);
  args[nargs] = 0;
  for (a = nargs; a > 0; a--)
    {

      UIdebug (5, "set args[%d]\n", a - 1);
      args[a - 1] = get_data_from_stack(NULL,NULL);
      UIdebug (5, "set args[%d]=%s\n", a - 1, args[a - 1]);
    }
  UIdebug (5, "Returning\n");
  return args;
}

int
uilib_input_start (int nargs)
{
  int cinput = -1;
  int todefs = 0;
  char *attr;
  int ln;
  char *mod;
  int nfields=0;
  int a;
  int wrap;

  wrap=POPint();
  nfields = POPint ();
  attr = charpop ();
  todefs = POPint ();
  ln = POPint ();
  mod = charpop ();

 //nfields++;

  cinput = new_context (UIINPUT, mod, ln);

  contexts[cinput].ui.input.field_data = 0;
  contexts[cinput].ui.input.num_field_data = 0;
  contexts[cinput].ui.input.changed = 0;
  contexts[cinput].ui.input.setfield = 0;

  contexts[cinput].ui.input.num_field_data = nfields;
  contexts[cinput].ui.input.changed = malloc (sizeof (int) * nfields);
  contexts[cinput].ui.input.field_data = malloc (sizeof (char *) * nfields);
  contexts[cinput].ui.input.variable_data = malloc (sizeof (char *) * nfields);
  contexts[cinput].ui.input.touched= malloc (sizeof (int) * nfields);

//printf("Allocating .ui.input.variable_data for %d fields\n", nfields);

  contexts[cinput].ui.input.nfields = nfields;

  for (a = 0; a < nfields;  a++)
    {
      contexts[cinput].ui.input.changed[a] = 0;
      contexts[cinput].ui.input.field_data[a] = 0;
      contexts[cinput].ui.input.variable_data[a] = 0;
      contexts[cinput].ui.input.touched[a] = 0;
    }
  suspend_flush (1);
  send_to_ui ("<INPUT CONTEXT=\"%d\" ATTRIBUTE=\"%s\" WITHOUT_DEFAULTS=\"%d\" WRAP=\"%d\">\n%s", cinput, attr, todefs, wrap, last_field_list);

	free(attr);
//free(mod);

  //pushint (cinput);
  return 0;
}

int
uilib_input_initialised (int nargs)
{

  send_to_ui ("</INPUT>");
  suspend_flush (-1);
  return 0;
}

/*
int uilib_input_start_value_and_datatype(int nargs) {
	int context;
	context=POPint();
	send_to_ui("<INPUTVARIABLES CONTEXT=\"%d\">",context);
	contexts[context].ui.input.nfields=0;
	contexts[context].ui.input.variable_data=0;
	contexts[context].ui.input.changed=0;
	return 0;
}

int uilib_input_end_value_and_datatype(int nargs) {
	int context;
	int a;
	context=POPint();

	contexts[context].ui.input.changed=malloc(sizeof(int *) * contexts[context].ui.input.nfields) ;

	for (a=0;a<contexts[context].ui.input.nfields;a++) {
		contexts[context].ui.input.changed=0;
	}

	send_to_ui("</INPUTVARIABLES>");
	return 0;
}



int uilib_input_set_value_and_datatype(int nargs) {
	int scale;
	int dtype;
	char *initval;
	int context;
	scale=POPint();
	dtype=POPint();
	initval=charpop();
	context=POPint();
	
 	send_to_ui("<INPUTVARIABLE DATATYPE=\"%d\" SCALE=\"%d\">%s</INPUTVARIABLE>",dtype,scale,xml_escape(initval));
	contexts[context].ui.input.nfields++;
	contexts[context].ui.input.variable_data=realloc(contexts[context].ui.input.variable_data,sizeof(char *) * contexts[context].ui.input.nfields) ;
	contexts[context].ui.input.variable_data[contexts[context].ui.input.nfields-1]=initval;
	return 0;
}
*/



int
uilib_next_field (int nargs)
{
  char *opt;
  int context;
  opt = charpop ();
  context = POPint ();

  if (contexts[context].type == UIINPUT)
    {
      if (contexts[context].ui.input.setfield)
	free (contexts[context].ui.input.setfield);
      contexts[context].ui.input.setfield = opt;
      return 0;
    }

  send_to_ui ("<NEXTFIELD CONTEXT=\"%d\" FIELD=\"%s\"/>", context, xml_escape(char_encode(opt)));

  free (opt);
  return 0;
}




/* CONSTRUCT HANDLING */


int
uilib_construct_start (int nargs)
{
  int a;
  int cconstruct = -1;
  char *attr;
  char **args;
  int nfields;
  int ln;
  char *mod;
  int wrap;


  wrap=POPint(); nargs--;

  attr = charpop ();
  nargs--;
  args = malloc (sizeof (char *) * nargs);
  args[0] = 0;
  args[1] = 0;
  for (a = nargs; a > 2; a--)
    {
      args[a - 1] = charpop ();
    }
  ln = POPint ();
  mod = charpop ();
  cconstruct = new_context (UICONSTRUCT, mod, ln);
  contexts[cconstruct].ui.construct.constr_clause = 0;
  contexts[cconstruct].ui.construct.setfield = 0;
  contexts[cconstruct].ui.construct.infield = 0;
  contexts[cconstruct].ui.construct.num_field_data = 0;
  contexts[cconstruct].ui.construct.field_data = 0;
  contexts[cconstruct].ui.construct.field_content_data = 0;
  UIdebug (5, "Construct - state=%d", contexts[cconstruct].state);
  suspend_flush (1);
  UIdebug (5, "Construct start - state=%d", contexts[cconstruct].state);
  send_to_ui ("<CONSTRUCT CONTEXT=\"%d\" ATTRIBUTE=\"%s\" WRAP=\"%d\">%s", cconstruct, attr, wrap,last_field_list);
  send_to_ui ("<COLUMNS>");
  for (a = 2; a < nargs; a++)
    {
      send_to_ui ("<COLUMN NAME=\"%s\"/>", args[a]);
    }
  send_to_ui ("</COLUMNS>");
  nfields = nargs - 1;

  contexts[cconstruct].ui.construct.num_field_data = nfields;
  contexts[cconstruct].ui.construct.field_data = malloc (sizeof (char *) * nfields);
  contexts[cconstruct].ui.construct.touched = malloc (sizeof (int) * nfields);
  contexts[cconstruct].ui.construct.field_content_data = malloc (sizeof (char *) * nfields);

  for (a = 0; a < contexts[cconstruct].ui.construct.num_field_data; a++)
    {
      contexts[cconstruct].ui.construct.field_data[a] = 0;
      contexts[cconstruct].ui.construct.touched[a] = 0;
      contexts[cconstruct].ui.construct.field_content_data[a] = 0;
    }

  //pushint (cconstruct);
  return 0;
}

int
uilib_construct_loop (int nargs)
{
  int context;
  int i;
  context = POPint ();
  UIdebug (5, "construct Context=%d state=%d\n", context, contexts[context].state);

  if (contexts[context].state == UI_NOT_INITIALIZED)
    {
      UIdebug (5, "construct not initialized\n");
      contexts[context].state = UI_WANT_BEFORE_INPUT;
      // Return -1 to intialize all the control blocks..
      pushint (-1);
      return 1;
    }

  if (contexts[context].state == UI_WANT_BEFORE_INPUT)
    {
      UIdebug (5, "construct before menu\n");
      // return whatever the before menu was...
      contexts[context].state = UI_INITIALIZED;
      pushint (0);
      return 1;
    }

  UIdebug (5, "construct wait for event\n");
  send_to_ui ("<WAITFOREVENT CONTEXT=\"%d\" CACHED=\"%d\"/>", context,havePendingTriggers(&contexts[context]));
  flush_ui ();
  while (1)
    {
      i = get_event_from_ui (&contexts[context]);
      mLastKey = last_attr->lastkey;
      if (i != -1)
	break;
      send_to_ui ("<WAITFOREVENT CONTEXT=\"%d\" ERR=\"BAD RESPONSE\"/>", context);
      flush_ui ();
    }

  if (last_attr->sync.nvalues)
    {
      int a;
      /* Got a construct result... */
      contexts[context].ui.construct.constr_clause = char_decode(last_attr->sync.vals[0].value);
	if (last_attr->sync.nvalues> contexts[context].ui.construct.num_field_data) {
		fprintf(stderr,"Critical internal error : Too many values returned\n");
		exit(5);
	} else {
      for (a = 0; a < last_attr->sync.nvalues; a++)
	{
	  if (contexts[context].ui.construct.field_content_data[a])
	    {
	      free (contexts[context].ui.construct.field_content_data[a]);
	      contexts[context].ui.construct.field_content_data[a] = 0;
	    }
	  if (contexts[context].ui.construct.field_data[a])
	    {
	      free (contexts[context].ui.construct.field_data[a]);
	      contexts[context].ui.construct.field_data[a] = 0;
	    }
	  contexts[context].ui.construct.field_content_data[a] = char_decode(last_attr->sync.vals[a].value);
	  contexts[context].ui.construct.touched[a]=last_attr->sync.vals[a].touched;
	  contexts[context].ui.construct.field_data[a] = last_attr->sync.vals[a].fieldname;
	}
	}
    }

  if (last_attr->infield)
    {
      if (contexts[context].ui.construct.infield)
	{
	  free (contexts[context].ui.construct.infield);
	}
      contexts[context].ui.construct.infield = strdup (last_attr->infield);
	set_infield(contexts[context].ui.construct.infield);
    }
  pushint (i);
  return 1;
}

int
uilib_construct_query (int nargs)
{
  int context;
  context = POPint ();

  if (contexts[context].ui.construct.constr_clause)
    {
      PUSHquote (contexts[context].ui.construct.constr_clause);
      return 1;
    }
  PUSHquote (" 1=1");
  return 1;
}

int
uilib_free_construct (int nargs)
{
  int context;
  context = POPint ();
  contexts[context].state = UI_FREE;


/*
  if (contexts[context].ui.construct.constr_clause)
    free (contexts[context].ui.construct.constr_clause);
*/

  if (contexts[context].ui.construct.field_content_data)
    {
      int a;
      for (a = 0; a < contexts[context].ui.construct.num_field_data; a++)
	{
	  free (contexts[context].ui.construct.field_content_data);
	  contexts[context].ui.construct.field_content_data = 0;
	}
      free (contexts[context].ui.construct.field_content_data);
      contexts[context].ui.construct.field_content_data = 0;
    }


  send_to_ui ("<FREE TYPE=\"CONSTRUCT\" CONTEXT=\"%d\"/>", context);
  return 0;
}

int
uilib_construct_initialised (int nargs)
{
  UIdebug (5, "uilib_construct_initialised called");
  suspend_flush (-1);

  send_to_ui ("</CONSTRUCT>");
  return 0;
}


static int get_context_for_modline(char *mod,int line,int fail_if_not_there) {
  int a;
	if (line==0) {
			A4GL_pause_execution();
		}
  UIdebug (5, "get context request for module=%s line=%d ncontexts=%d",  mod, line, ncontexts);
  for (a = 0; a < ncontexts; a++)
    {
      if (contexts[a].lineno == line && contexts[a].state != UI_FREE)
	{
	  if (strcmp (contexts[a].modulename, mod) == 0)
	    {
	      UIdebug (9, "FOUND CONTEXT : %s %d=%d\n", mod, line, a);
	      pushint (a);
	      return 1;
	    }
	}
    }

if (fail_if_not_there) {
	// critical...
  	UIdebug (0, "CRITICAL ERROR - COULD NOT FIND CONTEXT\n\n");
	fprintf(stderr,"CRITICAL ERROR - COULD NOT FIND CONTEXT\n");
  	//A4GL_pause_execution();
	exit(99);
}

  pushint (-1);
  return 1;
}



int uilib_get_context_dont_care_if_doesnt_exist(int n) {
  char *mod;
  int line;
int context;
  line = POPint ();
  mod = charpop ();
  context= get_context_for_modline(mod,line,0);
  free(mod);
  return context;
}

int
uilib_get_context (int nargs)
{
  int context;
  char *mod;
  int line;
  //int a;
  line = POPint ();
  mod = charpop ();
  context=get_context_for_modline(mod,line,1);
  free(mod);
  return context;
}

int
uilib_clear (int nargs)
{
  send_to_ui ("<CLEAR>%s</CLEAR>", last_field_list);
  return 0;
}


int
uilib_clear_to_defaults (int nargs)
{
  send_to_ui ("<CLEARTODEFAULTS>%s</CLEARTODEFAULTS>", last_field_list);
  return 0;
}

int
uilib_set_count (int nargs)
{
  int a;
  a = POPint ();
  m_arr_count = a;
  return 0;
}

int
uilib_arr_count (int nargs)
{
  pushint (m_arr_count);
  return 1;
}


int
uilib_scr_line (int nargs)
{
  pushint (m_scr_line);
  return 1;
}

int
uilib_arr_curr (int nargs)
{
printf("uilib_arr_curr   m_arr_curr=%d\n",m_arr_curr);
  pushint (m_arr_curr);
  return 1;
}


int
uilib_display_array_start (int nargs)
{
  int ci = -1;
  char *attr;
  int ln;
  char *mod;
  int nbind;
	char *style;

  nbind=POPint();
  style = charpop ();
  attr = charpop ();
  ln = POPint ();
  mod = charpop ();
  ci = new_context (UIDISPLAYARRAY, mod, ln);
  contexts[ci].ui.displayarray.scr_line = 0;
  contexts[ci].ui.displayarray.arr_line = 0;
  contexts[ci].ui.displayarray.count = m_arr_count;

  m_arr_count = m_arr_count;
  m_arr_curr = 1;
  m_scr_line = 1;

  suspend_flush (1);
  send_to_ui ("<DISPLAYARRAY CONTEXT=\"%d\" ATTRIBUTE=\"%s\" ARRCOUNT=\"%d\" ARRVARIABLES=\"%d\">\n%s", ci, attr, m_arr_count, nbind,last_field_list);
  //pushint (cinput);
  return 0;
}


int
uilib_array_lines_start (int nargs)
{
  send_to_ui ("<ROWS>");
  return 0;
}

int
uilib_array_lines_end (int nargs)
{
  send_to_ui ("</ROWS>");
  return 0;
}

int
uilib_display_array_initialised (int nargs)
{
  send_to_ui ("</DISPLAYARRAY>");
  suspend_flush (-1);
  return 0;
}

int
uilib_display_array_loop (int n)
{
  int i;
  int context;
  context = POPint ();
  i = 1;


  if (contexts[context].state == UI_NOT_INITIALIZED)
    {
      UIdebug (5, "not initialized\n");
      contexts[context].state = UI_WANT_BEFORE_INPUT;
      // Return -1 to intialize all the control blocks..
      pushint (-1);
      return 1;
    }

  if (contexts[context].state == UI_WANT_BEFORE_INPUT)
    {
      UIdebug (5, "before menu\n");
      // return whatever the before menu was...
      contexts[context].state = UI_INITIALIZED;
      pushint (0);
      return 1;
    }

  send_to_ui ("<WAITFOREVENT CONTEXT=\"%d\" CACHED=\"%d\"/>", context, havePendingTriggers(&contexts[context]));
  flush_ui ();

  while (1)
    {
      i = get_event_from_ui (&contexts[context]);
      mLastKey = last_attr->lastkey;
      if (i != -1)
	break;
      send_to_ui ("<WAITFOREVENT CONTEXT=\"%d\" ERR=\"BAD RESPONSE\"/>", context);
      flush_ui ();
    }
  if (last_attr->scrline)
    {
      contexts[context].ui.displayarray.scr_line = last_attr->scrline;
    }
  if (last_attr->arrline)
    {
      contexts[context].ui.displayarray.arr_line = last_attr->arrline;
    }
  if (last_attr->arrcount)
    {
      contexts[context].ui.displayarray.count = last_attr->arrcount;
    }

  m_arr_count = last_attr->arrcount;
  m_arr_curr = last_attr->arrline;
  m_scr_line = last_attr->scrline;

  UIdebug (7, "DISPLAY ARRAY GETS sl=%d al=%d #=%d\n", contexts[context].ui.displayarray.scr_line,
	   contexts[context].ui.displayarray.arr_line, contexts[context].ui.displayarray.count);
  pushint (i);
  return 1;
}



int
uilib_display_array_line (int nargs)
{
  char **args;
  int row;
  int a;
  args = get_args (nargs - 1);
  row = POPint ();
  send_to_ui (" <ROW SUBSCRIPT=\"%d\">", row+1);
  send_to_ui ("  <VS>");
  for (a = 0; a < nargs - 1; a++)
    {
      send_to_ui ("   <V>%s</V>", xml_escape (char_encode(args[a]))); // MJA1
    }
  send_to_ui ("  </VS>");
  send_to_ui (" </ROW>");
  free_args (args);
  return 0;
}




int
uilib_input_array_start (int nargs)
{
  int ci = -1;
  int a;
  int b;
  char *attr;
  int ln;
  char *mod;
  int todefs;
  int arrsize;
  int nvals;
int allow_insert;
int allow_delete;
int inp_flags;
int wrap;
wrap=POPint();
inp_flags=POPint();
allow_delete=POPint();
allow_insert=POPint();



  nvals = POPint ();		// Number of variables in the array (per line)
  arrsize = POPint ();		// number of elements in the array
  attr = charpop ();		// attribute
  todefs = POPint ();		// todefaults ?
  ln = POPint ();		// context match on line
  mod = charpop ();		// context match on module
  ci = new_context (UIINPUTARRAY, mod, ln);
  memset(&contexts[ci].ui.inputarray,0,sizeof(contexts[ci].ui.inputarray));

  contexts[ci].ui.inputarray.scr_line = 0;
  contexts[ci].ui.inputarray.arr_line = 0;
  contexts[ci].ui.inputarray.count = m_arr_count;

  //contexts[ci].ui.inputarray.num_field_data = nvals
  //contexts[ci].ui.inputarray.field_data=



  m_arr_count = m_arr_count;
  m_arr_curr = 1;
  m_scr_line = 1;

  contexts[ci].ui.inputarray.maxarrsize = arrsize;
  contexts[ci].ui.inputarray.nvals = nvals;


  contexts[ci].ui.inputarray.changed_rows = malloc (arrsize * sizeof (int));
  contexts[ci].ui.inputarray.variable_data = malloc (arrsize * sizeof (char **));
  contexts[ci].ui.inputarray.touched = malloc (arrsize * sizeof (int *));

  for (a = 0; a < arrsize; a++)
    {
      char **p;
      contexts[ci].ui.inputarray.variable_data[a] = malloc (nvals * sizeof (char *));
      contexts[ci].ui.inputarray.touched[a] = malloc (nvals * sizeof (int));
      contexts[ci].ui.inputarray.changed_rows[a] = 0;
      p = contexts[ci].ui.inputarray.variable_data[a];
      for (b = 0; b < nvals; b++)
	{
	  p[b] = 0;
	}
    }

  suspend_flush (1);
  send_to_ui ("<INPUTARRAY CONTEXT=\"%d\" ATTRIBUTE=\"%s\" ARRCOUNT=\"%d\" MAXARRSIZE=\"%d\" WITHOUT_DEFAULTS=\"%d\" ARRVARIABLES=\"%d\" ALLOWINSERT=\"%d\" ALLOWDELETE=\"%d\" NONEWLINES=\"%d\" WRAP=\"%d\">\n%s", ci,
	      attr, m_arr_count, arrsize, todefs, nvals,
		allow_insert,allow_delete,inp_flags, wrap,
last_field_list);
  return 0;
}

int
uilib_input_array_initialised (int nargs)
{
  send_to_ui ("</INPUTARRAY>");
  suspend_flush (-1);
  return 0;
}

int
uilib_input_array_sync (int nargs)
{
  char **args;
  int row;
  int a;
  int ci;
  char **p;
  int changed = 0;
  args = get_args (nargs - 2);
  row = POPint () - 1;
  ci = POPint ();
  UIdebug (5, "Input arry sync : row = %d ci=%d", row, ci);
  p = contexts[ci].ui.inputarray.variable_data[row];

  for (a = 0; a < nargs - 2; a++)
    {
      if (p[a] == 0)
	{

	  UIdebug (5, "New Value @%d %s", a, args[a]);
	  p[a] = args[a];
	  contexts[ci].ui.inputarray.changed_rows[row] = 1;
	  changed++;
	}
      else
	{
	  UIdebug (5, "Compare Value @%d %s %s", a, p[a], args[a]);
	  if (strcmp (p[a], args[a]) != 0)
	    {

	      free (p[a]);
	      p[a] = args[a];
	      contexts[ci].ui.inputarray.changed_rows[row] = 1;
	      changed++;
	    }
	}
    }

  if (changed)
    {
      UIdebug (5, "some values changes - will need to resync row = %d ci=%d", row, ci);
    }

  return 0;
}

static void
send_input_array_change (int ci)
{
  int a;
  int b;
  int need_to_send = 0;

  //if (contexts[ci].ui.inputarray.field_data==NULL) {
	//need_to_send=1;
  //} 


  for (a = 0; a < contexts[ci].ui.inputarray.maxarrsize; a++)
    {
      if (contexts[ci].ui.inputarray.changed_rows[a])
	need_to_send++;
    }

  if (!need_to_send)
    return;


  send_to_ui ("<ROWS>");
  for (a = 0; a < contexts[ci].ui.inputarray.maxarrsize; a++)
    {
      if (!contexts[ci].ui.inputarray.changed_rows[a])
	continue;
      send_to_ui ("<ROW SUBSCRIPT=\"%d\">", a + 1);
      send_to_ui ("<VS>");
      for (b = 0; b < contexts[ci].ui.inputarray.nvals; b++)
	{
	  send_to_ui (" <V>%s</V>", xml_escape (char_encode(contexts[ci].ui.inputarray.variable_data[a][b])));
	}
      send_to_ui ("</VS>");
      send_to_ui (" </ROW>");
      contexts[ci].ui.inputarray.changed_rows[a] = 0;
    }
  send_to_ui ("</ROWS>");
}


int
uilib_input_array_loop (int n)
{
  int i;
  int context;
  context = POPint ();
  i = 1;


  UIdebug (9, "contexts[#].ui.inputarray.changed_rows[0]=%d\n", contexts[context].ui.inputarray.changed_rows[0]);
  if (contexts[context].state == UI_NOT_INITIALIZED)
    {
      UIdebug (5, "not initialized\n");
      contexts[context].state = UI_WANT_BEFORE_INPUT;
      // Return -1 to intialize all the control blocks..
      pushint (-1);
      return 1;
    }

  if (contexts[context].state == UI_WANT_BEFORE_INPUT)
    {
      UIdebug (5, "before menu\n");
      // return whatever the before menu was...
      contexts[context].state = UI_INITIALIZED;
      contexts[context].ui.inputarray.infield = 0;
	set_infield("");
      pushint (0);
      return 1;
    }

  send_to_ui ("<WAITFOREVENT CONTEXT=\"%d\" CACHED=\"%d\">", context,havePendingTriggers(&contexts[context]));
  send_input_array_change (context);
  send_to_ui ("</WAITFOREVENT>");
  flush_ui ();
  while (1)
    {
      i = get_event_from_ui (&contexts[context]);
      mLastKey = last_attr->lastkey;
      if (i != -1)
	break;
      send_to_ui ("<WAITFOREVENT CONTEXT=\"%d\" ERR=\"BAD RESPONSE\"/>", context);
      flush_ui ();
    }

  if (last_attr->scrline)
    {
	//printf("SCRLINE : %d\n",  contexts[context].ui.inputarray.scr_line );
      contexts[context].ui.inputarray.scr_line = last_attr->scrline;
    }
  if (last_attr->arrline)
    {
	//printf("ARRLINE : %d\n",  contexts[context].ui.inputarray.arr_line );
      contexts[context].ui.inputarray.arr_line = last_attr->arrline;
    }
  if (last_attr->arrcount)
    {
      contexts[context].ui.inputarray.count = last_attr->arrcount;
    }

  if (last_attr->infield)
    {
      if (contexts[context].ui.inputarray.infield)
        free (contexts[context].ui.inputarray.infield);
      contexts[context].ui.inputarray.infield = strdup (last_attr->infield);
	set_infield(contexts[context].ui.inputarray.infield);
    }

  if (contexts[context].ui.inputarray.field_data && last_attr->rows.nrows) { // Do we have some replacement rows ? 
		int a;
		// yes - clean out the old stuff...
		for (a=0;a<contexts[context].ui.inputarray.num_field_data;a++) {
			if (contexts[context].ui.inputarray.field_data[a]!=0) {
				free(contexts[context].ui.inputarray.field_data[a]) ;
			}
		
		}
		contexts[context].ui.inputarray.field_data=0;
  }


  m_arr_count = last_attr->arrcount;
  m_arr_curr = last_attr->arrline;
  m_scr_line = last_attr->scrline;

// Ok - we've got a reply - maybe its got some row attached ? 
  if (last_attr->rows.nrows)
    {
      int a;
      int b;
      int arrline;
	
  	contexts[context].ui.inputarray.num_field_data=contexts[context].ui.inputarray.nvals;
  	contexts[context].ui.inputarray.field_data=malloc (sizeof (char *) * contexts[context].ui.inputarray.num_field_data);

	for (a=0;a<contexts[context].ui.inputarray.num_field_data;a++) {
		contexts[context].ui.inputarray.field_data[a]=0;
	}

      for (a = 0; a < last_attr->rows.nrows; a++)
	{
	  arrline = last_attr->rows.row[a].rownum - 1;
	  contexts[context].ui.inputarray.changed_rows[arrline] = 1;

	  UIdebug (5, " changed row @ arrline=%d", arrline);

	  if (last_attr->rows.row[a].sync.nvalues != contexts[context].ui.inputarray.nvals)
	    {			// Doesn't look like it matches!
	      UIdebug (0, "CRITICAL - Number of values is not the same as the number in the array (%d!=%d)",
	last_attr->rows.row[a].sync.nvalues , contexts[context].ui.inputarray.nvals
);
	      continue;
	    }
	  for (b = 0; b < contexts[context].ui.inputarray.nvals; b++)
	    {
	      char **p;
		if (a==0) {
			contexts[context].ui.inputarray.field_data[b]=strdup(last_attr->rows.row[a].sync.vals[b].fieldname);
		}

	         p = contexts[context].ui.inputarray.variable_data[arrline];
		contexts[context].ui.inputarray.touched[arrline][b]=last_attr->rows.row[a].sync.vals[b].touched;
	      if (p[b])
		{
		  free (p[b]);
		}
	      p[b] = strdup (char_decode(last_attr->rows.row[a].sync.vals[b].value));
	    }
	}
    }

  UIdebug (7, "INPUT ARRAY GETS sl=%d al=%d #=%d\n", contexts[context].ui.inputarray.scr_line, contexts[context].ui.inputarray.arr_line, contexts[context].ui.inputarray.count);
  pushint (i);
  return 1;
}


int uilib_get_input_array_count(int n) {
	int context;
  	context = POPint ();
	pushint(contexts[context].ui.inputarray.count);
	return  1;
}

int
uilib_has_array_values (int n)
{
  int context;
  int a;
  context = POPint ();
  UIdebug (5, " Checking for changed rows");
  for (a = 0; a < contexts[context].ui.inputarray.maxarrsize; a++)
    {
      if (contexts[context].ui.inputarray.changed_rows[a])
	{
	  UIdebug (5, "Found a changed row : %d", a + 1);

		//printf("Found a changed row %d\n",a+1);

	  pushint (a + 1);
	  return 1;
	}
    }
  UIdebug (5, "No changed rows");
  pushint (0);
  return 1;
}


int
uilib_input_get_array_values (int n)
{
  int context;
  int b;

  char **p;
  int arrline;
  arrline = POPint () - 1;
  context = POPint ();
  UIdebug (5, "Get a line : arrline=%d context=%d", arrline, context);
  p = contexts[context].ui.inputarray.variable_data[arrline];
  for (b = 0; b < contexts[context].ui.inputarray.nvals; b++)
    {
      UIdebug (6, "Pushing : '%s'", p[b]);

      if (strlen (p[b]) == 0)
        {
		//printf("%d : NULL\n",b);
          A4GL_push_null (0, 0);
        }
      else
        {
		//printf("%d : %s\n",b,p[b]);
      	PUSHquote (p[b]);
        }
    }
  contexts[context].ui.inputarray.changed_rows[arrline] = 0;
  return contexts[context].ui.inputarray.nvals;
}

void
brpoint ()
{
  printf ("Break here");
}

int
uilib_save_file (char *id, char *s)
{
  FILE *f;
  int i;

  send_to_ui ("<REQUESTFILE FILEID='%s'/>", uilib_xml_escape (char_encode(id)));
  flush_ui ();
  i = get_event_from_ui (NULL);

  if (i != -103)
    {
      return 0;
    }

  if (strcmp (last_attr->fileid, id) != 0)
    {
      // Invalid id
      return 0;
    }

  f = fopen (s, "w");
  if (f)
    {
	unsigned char *buff;
	int len;
	int printed=0;

	if (last_attr->sync.vals!=0) {
		if (last_attr->sync.vals[0].value!=0) {
			char *r;
			if (strlen(last_attr->sync.vals[0].value)>200) {
				r=strdup(last_attr->sync.vals[0].value);
				strcpy(&r[80],"...");
				UIdebug(4,"Saving file %s - len=%d should be %d\n",r, len, last_attr->filelen);
				free(r);
			} else {
				UIdebug(4,"Saving file %s - len=%d should be %d\n",last_attr->sync.vals[0].value, len, last_attr->filelen);
			}
			printed++;
		}
	} 
	if (!printed) {
		fprintf(stderr,"couldnt save file - no synvalue");
		exit(2);
	}
	len=A4GL_base64_decode(last_attr->sync.vals[0].value, &buff);
      //printf("FILELEN : %d\n", last_attr->filelen);
      fwrite (buff, len, 1, f);
	free(buff);
      fclose (f);
    }

  return 1;
}


char *getlastkey(void) {
	if (last_attr) {
	return last_attr->lastkey;
	}
	return NULL;
}

int
uilib_last_received_key (void )
{
  PUSHquote (last_attr->lastkey);
  return 1;
}


int
uilib_lastkey (int nargs)
{
  if (mLastKey)
    {
      PUSHquote (mLastKey);
    }
  else
    {
      PUSHquote ("");
    }
  return 1;
}



int
uilib_free_input_array (int nargs)
{
  int context;
  context = POPint ();
  contexts[context].state = UI_FREE;
  send_to_ui ("<FREE TYPE=\"INPUTARRAY\" CONTEXT=\"%d\"/>", context);
  return 0;
}

int
uilib_getfldbuf (int nargs)
{
  int context;
  //char *fld;
  int nfields;
  char **fields;
  int a;
  int b;

  nfields = nargs - 1;
  fields = malloc (sizeof (char *) * nfields);
  b=nfields-1;
  for (a = 0; a < nfields; a++)
    {
      fields[b--] = charpop ();
    }

/*
  for (a = 0; a < nfields; a++)
  {
		printf("%d %s\n",a,fields[a]);
  }
*/
  context = POPint ();

  if (context>=0)
    {
      if (contexts[context].type == UIINPUT)
	{
	  int a;
	  int b;
	  char **flist;
	  int nflist;
	  flist = contexts[context].ui.input.field_data;
	  nflist = contexts[context].ui.input.num_field_data;
	  for (b = 0; b < nfields; b++)
	    {
	      int pushed = 0;
	      for (a = 0; a < nflist; a++)
		{
		  if (field_match (flist[a], fields[b]))
		    {
		      PUSHquote (contexts[context].ui.input.variable_data[a]);
		      pushed++;
		      break;
		    }
		}
	      if (!pushed)
		{
		  PUSHquote ("<notfound>");
		}
	    }
	  return nfields;
	}


      if (contexts[context].type == UIINPUTARRAY)
	{
	  int a;
	  int b;
	  char **flist;
	  int nflist;
	  int currline;
	  flist = contexts[context].ui.inputarray.field_data;
	  nflist = contexts[context].ui.inputarray.num_field_data;
	  currline = contexts[context].ui.inputarray.arr_line;
	  for (b = 0; b < nfields; b++)
	    {
	      int pushed = 0;
	      for (a = 0; a < nflist; a++)
		{
		  if (field_match (flist[a], fields[b]))
		    {
			if (currline>0 && currline<=contexts[context].ui.inputarray.count) {
		      		PUSHquote (contexts[context].ui.inputarray.variable_data[currline-1][a]);
		      		pushed++;
			}
		      break;

		    }
		}
	      if (!pushed)
		{
		  PUSHquote ("<notfound>");
		}
	    }
	  return nfields;
	}



      if (contexts[context].type == UICONSTRUCT)
	{
	  int a;
	  int b;
	  char **flist;
	  int nflist;
	  flist = contexts[context].ui.construct.field_data;
	  nflist = contexts[context].ui.construct.num_field_data;
	  for (b = 0; b < nfields; b++)
	    {
	      int pushed = 0;
	      for (a = 0; a < nflist; a++)
		{
		  if (field_match (flist[a], fields[b]))
		    {
		      PUSHquote (contexts[context].ui.construct.field_content_data[a]);
		      pushed++;
		      break;
		    }
		}
	      if (!pushed)
		{
		  PUSHquote ("<notfound>");
		}
	    }
	  return nfields;
	}
    }

  fprintf (stderr, "******** UNSUPPORTED GETFLDBUF OPERATION **********\n");

  for (a = 0; a < nfields; a++)
    {
      PUSHquote ("<notset>");
    }
  return nfields;
}



int
uilib_infield (int n)
{
  int context;
  char *fld;
  char *f = 0;
  fld = charpop ();
  context = POPint ();
  if (context>=0)
    {
      f = 0;
      if (contexts[context].type == UIINPUT)
	{
	  f = contexts[context].ui.input.infield;
	
	}

      if (contexts[context].type == UIINPUTARRAY)
	{
	  f = contexts[context].ui.inputarray.infield;
	}

      if (contexts[context].type == UICONSTRUCT)
	{
	  f = contexts[context].ui.construct.infield;
	}

    } else {
	f=lastInfield;
    }

  if (f)
    {
      if (field_match (fld, f) )
	{
	  pushint (1);
	}
      else
	{
	  pushint (0);
	}
    }
  else
    {
      pushint (0);
    }
  return 1;
}



int
uilib_fgl_drawbox (int n)
{
  int x1, x2, x3, x4, x5;
  if (n == 4)
    {
      x1 = POPint ();
      x2 = POPint ();
      x3 = POPint ();
      x4 = POPint ();
    }
  if (n == 5)
    {
      x1 = POPint ();
      x2 = POPint ();
      x3 = POPint ();
      x4 = POPint ();
      x5 = POPint ();
    }
  return 0;
}


#ifdef A4GL_assertion
#undef A4GL_assertion
#endif



int
A4GL_assertion (int n, char *s)
{
  if (n)
    {
      printf ("%s\n", s);
      exit (2);
    }
  return 0;
}

int
A4GL_assertion_full (int n, char *s, char *mod, int ln)
{
  A4GL_assertion (n, s);
  return 0;
}


static void
local_trim (char *p)
{
  int a;
  for (a = strlen (p) - 1; a >= 0; a--)
    {
      if (p[a] != ' ' && p[a] != '\t' && p[a] != '\n' && p[a] != '\r')
	break;
      p[a] = 0;
    }
}


int
uilib_trace (int n)
{
  FILE *f;
  static char *p = 0;
  char *a;

  a = charpop ();
  if (p == 0)
    {
      p = getenv ("TRACEFILE");
    }
  if (p == 0)
    {
      free (a);
      return 0;
    }
  f = fopen (p, "a");
  if (f == 0)
    {
      free (a);
      return 0;
    }
  fprintf (f, "%s\n", a);
  free (a);
  fclose (f);
  return 0;
}

void
set_construct_clause (int context, char *ptr)
{
  if (strcmp (ptr, "") == 0 || strcmp (ptr, "1") == 0)
    {
      ptr = " 1=1";
    }
  contexts[context].ui.construct.constr_clause = ptr;
}



static int
field_match (char *a, char *b)
{
char *ptr_a;
char *ptr_b;
  if (a == 0)
    return 0;
  if (b == 0)
    return 0;
  UIdebug (5, "Field  name match : '%s' '%s' : ", a, b);

  if (strcmp (a, b) == 0) {
	UIdebug(5,"Match\n");
    	return 1;
  }
  ptr_a=strchr(a,'.'); if (ptr_a) ptr_a++; 
  ptr_b=strchr(b,'.'); if (ptr_b) ptr_b++; 
  if (ptr_a && ptr_b==0) {
	// Assume they match - one is missing a table name...
	if (strcmp(ptr_a,b)==0) {
	UIdebug(5,"Match\n");
		return 1;
	}
  }
  if (ptr_a==0 && ptr_b) {
	// Assume they match - one is missing a table name...
	if (strcmp(a,ptr_b)==0) {
	UIdebug(5,"Match\n");
		return 1;
	}
  }

UIdebug(5,"Not matched\n");
  return 0;
}



int
uilib_touched (int nargs)
{
  int context;
  //char *fld;
  int nfields;
  char **fields;
  int a;

  nfields = nargs - 1;
  fields = malloc (sizeof (char *) * nfields);
  for (a = 0; a < nfields; a++)
    {
      fields[a] = charpop ();
    }
  context = POPint ();

  if (context>=0)
    {
      if (contexts[context].type == UIINPUT)
	{
	  int a;
	  int b;
	  char **flist;
	  int nflist;
	  flist = contexts[context].ui.input.field_data;
	  nflist = contexts[context].ui.input.num_field_data;
	  for (b = 0; b < nfields; b++)
	    {
	      //int pushed = 0;
	      for (a = 0; a < nflist; a++)
		{
		  if (field_match (flist[a], fields[b]))
		    {
			if (contexts[context].ui.input.touched[a]) return 1;
		    }
		}
	    }
	  return 0;
	}


      if (contexts[context].type == UIINPUTARRAY)
	{
	  int a;
	  int b;
	  char **flist;
	  int nflist;
	  int currline;
	  flist = contexts[context].ui.inputarray.field_data;
	  nflist = contexts[context].ui.inputarray.num_field_data;
	  currline = contexts[context].ui.inputarray.arr_line;
	  for (b = 0; b < nfields; b++)
	    {
	      int pushed = 0;
	      for (a = 0; a < nflist; a++)
		{
		  if (field_match (flist[a], fields[b]))
		    {

		      if (contexts[context].ui.inputarray.touched[currline][a]) return 1;
		      pushed++;
		      break;
		    }
		}
	    }
	  return 0;
	}



      if (contexts[context].type == UICONSTRUCT)
	{
	  int a;
	  int b;
	  char **flist;
	  int nflist;
	  flist = contexts[context].ui.construct.field_data;
	  nflist = contexts[context].ui.construct.num_field_data;
	  for (b = 0; b < nfields; b++)
	    {
	      //int pushed = 0;
	      for (a = 0; a < nflist; a++)
		{
		  if (field_match (flist[a], fields[b]))
		    {
		      if (contexts[context].ui.construct.touched[a]) return 1;
		    }
		}
		return 0;
	    }
	  return nfields;
	}
    }

  fprintf (stderr, "******** UNSUPPORTED GETFLDBUF OPERATION **********\n");

  return 0;
}



int uilib_do_frontcall(char *s,int no) {
  int a;
  send_to_ui(s);


  flush_ui(); /// <---- JUST FOR DEBUGGING ...



if (no) {
	// We only need to wait if we are expecting some result
  send_to_ui ("<WAITFOREVENT/>");
  flush_ui ();
  a=get_event_from_ui (NULL);
	if (a!=ID_FRONTCALLRETURN) {
		printf("Internal error - expecting a ID_FRONTCALLRETURN\n");
		return 0;
	}

  if (last_attr->sync.nvalues==no) {

  	for (a = 0; a < last_attr->sync.nvalues; a++) {
		PUSHquote(char_decode(last_attr->sync.vals[a].value));
  	}
	return 1;
  } else {
	return 0;
	}
}  else {
return 0;
}
}



void clrPendingTriggers(int ContextID) {
struct ui_context *context;
        context=&contexts[ContextID];
        if (context->nPendingTriggereds>0) {
                int a;
                for (a=0;a<context->nPendingTriggereds;a++) {
                                if (context->pendingTriggereds[a]) {
                                        free(context->pendingTriggereds[a]);
                                        context->pendingTriggereds[a]=0;
                                }
                }
        }
        context->nPendingTriggereds=0;
}


#define DISPLAY_TYPE_DISPLAY_TO 3
char *get_data_from_stack(int *d1,int *s1) {
int d;
int s;
void *ptr1;
char *ptr;
if (d1==NULL) d1=&d;
if (s1==NULL) s1=&s;

                A4GL_get_top_of_stack (1, d1, s1, (void **) &ptr1);


                ptr=A4GL_pull_off_data_for_display(1, DISPLAY_TYPE_DISPLAY_TO);
                        //args[a] = A4GL_char_pop ();
                        switch ((*d1)&DTYPE_MASK) {
                                case DTYPE_INT:
                                case DTYPE_SMINT:
                                case DTYPE_FLOAT:
                                case DTYPE_SMFLOAT:
                                case DTYPE_MONEY:
                                case DTYPE_SERIAL:
                                        A4GL_lrtrim(ptr);
                                        break;

                                case DTYPE_DECIMAL:
                                        A4GL_lrtrim(ptr);
                                        if (ptr[0]=='.' || ptr[0]==',') {
                                                char buff[2000];
                                                sprintf(buff,"0%s",ptr);
                                                free(ptr);
                                                ptr=strdup(buff);
                                        }

                        }
return ptr;
}
