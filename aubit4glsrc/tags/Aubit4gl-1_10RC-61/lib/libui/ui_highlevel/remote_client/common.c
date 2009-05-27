char *A4GL_strcat  (char *d,char *s,char *fname,int l,int sdest) {
	return strcat(d,s);
}

void *acl_malloc_full(long a,char *r,char *f,long l) {
	printf("MALLOC : %s %d\n",f,l);
	return malloc(a);
}



#define _DEFINE_STATUSVARS_
#include "a4gl_libaubit4gl.h"

int abort_pressed;
//int int_flag;
//int a4gl_status;


int status1=0;
int status2=0;


/**
 * Checks if the string have some sort of yes (y,Y,1,true).
 *
 * @param s The string to be checked
 * @return - 1 : Is yes
 *         - 0 : Otherwise
 */
int
A4GL_isyes (char *s)
{
  if (s == 0)
    {
      //debug("isyes = false");
      return 0;
    }
  //debug("isyes called with %s\n",s);
  if (s[0] == 0)
    {
      //debug("isyes = false");
      return 0;
    }
  if (s[0] == 'y' || s[0] == 'Y' || s[0] == '1'
      || A4GL_aubit_strcasecmp (s, "true") == 0)
    {
      //debug("isyes = true");
      return 1;
    }
  //debug("isyes = false");
  return 0;
}


/**
 * Checks if the string have some sort of yes (y,Y,1,true).
 *
 * @param s The string to be checked
 * @return - 1 : Is yes
 *         - 0 : Otherwise
 */
int
A4GL_isno (char *s)
{
  if (s == 0)
    {
      return 0;
    }
  if (s[0] == 0)
    {
      return 0;
    }
  if (s[0] == 'n' || s[0] == 'N' || s[0] == '0'
      || A4GL_aubit_strcasecmp (s, "false") == 0)
    {
      return 1;
    }
  return 0;
}



int
A4GL_aubit_strcasecmp (char *a, char *b)
{
  int c;
  int l1;
  int l2;
  int m;

  l1=strlen(a);
  l2=strlen(b);

  if (l1>l2) m=l2;
        else m=l1;

  for (c = 0; c <= m; c++)
    {
      if (toupper (a[c]) > toupper (b[c]))
        return 1;
      if (toupper (a[c]) < toupper (b[c]))
        return -1;
    }

  if (l1 == l2) return 0;
  if (l1 > l2 ) return 1;

  return -1;
}



void A4GL_add_pointer (char *orig_name, char type, void *ptr) {
	
}

int A4GL_has_pointer (char *pname, char t) {
	return 0;
}

void *
A4GL_find_pointer (const char *pname, char t) {
	return 0;
}




char *A4GL_strcpy(char *dest,char *src,char *f,int l,int sd) {
        int lsrc;
        char buff[256];

        if (src==0) {
                sprintf(buff,"No source for strcpy @ %s line %d",f,l);
                A4GL_assertion(1,buff);
        }

        lsrc=strlen(src);
        if (sd!=sizeof(char *)) {
                if (lsrc>=sd) {
                        //A4GL_debug("String overflow detected : %s %d (%d>=%d)",f,l,strlen(src),sd);
                        sprintf(buff,"String overflow detected @ %s line %d",f,l);
                        A4GL_assertion(1,buff);
                }
        }
#ifdef strcpy
#undef strcpy
        strcpy(dest,src);
#endif


#ifdef DEBUG
{
// This just adds some debugging stuff - but this
// isn't applicable when called from the routines in dmy.c
// as they put some funny characters in the string as placeholders
//
        if (strcmp(f,"dmy.c")==0) return dest;


// Quick - is it big ?
        if (lsrc>255) {
                char buff[3000];
                strncpy(buff,src,2999);
                buff[2999]=0;
                //A4GL_debug("Long string : %s\n",buff);
        }

// Does it look Good ?
{
        int a;
        for (a=0;a<lsrc;a++) {
                if (!isprint(src[a])&&src[a]!='\n'&&!ispunct(src[a])) {
                        //A4GL_debug("Possible bad char @%d for string '%s' (%d)\n",a,src,strlen(src));
                }
        }
}
}
#endif

        return dest;
}




// from funcs_d.c
/**
 * Trim the spaces and new lines at the rigth side of a string.
 *
 * @param p The string to be trimmed.
 */
void
A4GL_trim_nl (char *p)
{
  int a;
  for (a = strlen (p) - 1; a >= 0; a--)
    {
      if (p[a] != ' ' && p[a] != '\n' && p[a] != '\r' && p[a] != '\t')
        break;
      p[a] = 0;
    }
}

/**
 * Trim the spaces at the rigth side of a string
 *
 * @param p The string to be trimmed.
 */
void
A4GL_trim (char *p)
{
  int a;
  for (a = strlen (p) - 1; a >= 0; a--)
    {
      if (p[a] != ' ' && p[a] != '\t' && p[a] != '\n' && p[a] != '\r')
        break;
      p[a] = 0;
    }
}




int A4GL_set_line(char *fname, long lineno) {  return 0; }
int A4GL_set_line_extended (char *fname, long lineno, const char *level, const char *func) {
	return 0;
}


void A4GL_assertion(int a, char *s) {
	if (a) {
		printf("%s\n",s);
		A4GL_exitwith(s);
	}
}

void A4GL_debug_full_extended(char *fmt,...) {
}



void A4GL_exitwith(char *s) {
	printf("%s\n");
	exit(1);
	
}


int A4GLSQL_set_status(int a,int b) {
	status1=a;
	status2=b;
	return a;
}


void A4GL_pause_execution(void) {
	//
}



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
}


/*
A4GL_LL_field_opts(f) {
	A4GL_assertion(1,"A4GL_LL_field_opts Invalid for pipeclient");
}
*/

A4GL_ll_set_field_opts(void *f,long o) {
	A4GL_LL_set_field_opts(f,o);

}


/*
A4GL_LL_out_linemode(char *s) {
	if (A4GL_isyes(acl_getenv("LOCALLINEOUTPUT"))) {
		printf("%s\n",s);
	} else {
		A4GL_LL_out_linemode_internal(s);
	}
}
*/


A4GL_set_intr() {
}


int A4GL_isscrmode() {
return 0;
}

char *A4GL_internal_version() {
	return "1";
}
void A4GL_set_scrmode (char a) {
}


A4GL_internal_build() {
	return "2";
}
int A4GL_sprintf (char *f,int l, char *dest,size_t sdest,char *fmt, ...) {
char buff[256];
int x;
char *c;
va_list args;
//sk:char xbuff[20000];
char xbuff[50000];


// DO NOT CALL A4GL_debug from this function!!!!
// (put that in a few times - just top make sure :-)
/* 

We can end up with problems with overlapping - eg
      sprintf(bibble,"'%s'",bibble);

   so we'll sprintf into a temporary space first, then strcpy across after

*/
        if (fmt==0) {
                sprintf(buff,"No format for sprintf @ %s line %d",f,l);
                A4GL_assertion(1,buff);
        }

// DO NOT CALL A4GL_debug from this function!!!!
        if (sdest>sizeof(char *)) { // We do this one...
              va_start (args, fmt);
              c=acl_malloc2(sdest);
              x=VSNPRINTF(c,sdest,fmt,args);
              if (x>=sdest) {
                        sprintf(buff,"sprintf trying to exceed allocated space @ %s (line %d)",f,l);
                        PRINTF("-->%s (%d>=%d)",fmt,x,sdest);
                        A4GL_assertion(1,buff);
              }
              strcpy(dest,c);
              free(c);
// DO NOT CALL A4GL_debug from this function!!!!
        } else {
              va_start (args, fmt);
              x=VSPRINTF(xbuff,fmt,args);
                if (x>sizeof(xbuff)) {
                        A4GL_assertion(1,"sprintf > 20,000 characters when using a pointer...");
                }
              strcpy(dest,xbuff);
        }
        return x;
// DO NOT CALL A4GL_debug from this function!!!!
}


//A4GL_LL_out_linemode_internal() {
//}
