/******************************************************************************
* (c) 1997-1998 Aubit Computing Ltd.
*
* $Id: mod.c,v 1.20 2001-10-29 14:42:00 mikeaubury Exp $
*
* Project : Part Of Aubit 4GL Library Functions
*
* Change History :
*	$Log: not supported by cvs2svn $
*	Revision 1.19  2001/10/28 17:10:36  mikeaubury
*	Added IN and EXISTS, (and NOT IN and NOT EXISTS) tests for 4gl, so
*		if exists (select * from systables where tabid=1) then
*		...
*		end if
*	
*	and
*	
*		define a integer
*		let a=1
*		if a in (1,2,3,4) then
*			display "OK"
*		end if
*	
*	and
*	
*		if a in (select tabid from systables) then
*		...
*		end if
*	
*	and
*	
*		if a not in (select tabid from systables) then
*		...
*		end if
*	
*	should all now work ..
*	
*	Revision 1.18  2001/10/28 14:46:38  mikeaubury
*	Major major expression handling updates
*	
*	Minor changes for messages and errors (doesn't prompt on errors anymore)
*	
*	Revision 1.17  2001/10/18 01:31:01  afalout
*	*** empty log message ***
*	
*	Revision 1.16  2001/10/18 00:01:30  afalout
*	NoODBC build on CygWin
*	
*	Revision 1.15  2001/10/05 18:16:40  mikeaubury
*	Fixes
*	
*	Revision 1.14  2001/09/22 20:09:59  mikeaubury
*	Fixes
*	
*	Revision 1.13  2001/09/18 08:32:23  mikeaubury
*	More fixes..
*	
*	Revision 1.12  2001/09/17 21:12:37  mikeaubury
*	new and improved...
*	But still working in it..
*	
*	Revision 1.11  2001/09/16 16:19:21  mikeaubury
*	more updates
*	
*	Revision 1.10  2001/09/10 17:47:39  mikeaubury
*	Bugfix - overflow in bindings (manifesting as a 'FUNC' was not the last block...)
*	
*	Revision 1.9  2001/09/08 09:57:41  mikeaubury
*	Does anyone know another phrase for 'yet more changes' ?
*	They are too numerous and small to mention individually....
*	
*	Revision 1.8  2001/09/07 23:15:46  afalout
*	Exit codes
*	
*	Revision 1.7  2001/09/07 21:35:38  mikeaubury
*	yet more fixes
*	
*	Revision 1.6  2001/09/06 20:02:21  mikeaubury
*	More fixes (incl. major one on passing records to functions/reports)
*	
*	Revision 1.5  2001/09/05 21:49:22  mikeaubury
*	Small changes.
*	
*	Revision 1.4  2001/09/04 21:51:02  mikeaubury
*	bug fixes.
*	Added thru syntax for some commands (eg. Input)
*	
*	Revision 1.3  2001/09/01 19:57:31  mikeaubury
*	major bug fixes...
*	Be care with records - new print_push_record ...
*	
*	Revision 1.2  2001/08/31 18:22:31  mikeaubury
*	minor fixes,
*	incl requirement for a : on a label
*	
*	major fixes:
*	automatically compiles a globals 4gl (ie. you don't need to precompile to obtain a glb to compile a module that uses that glb file...)
*	
*	Revision 1.1.1.1  2001/08/20 02:35:38  afalout
*	Initial import to SF
*	
*	Revision 1.12  2001/08/17 10:20:42  maubury
*	loop updates
*	
*	Revision 1.11  2001/08/16 07:01:41  maubury
*	updates
*	
*	Revision 1.10  2001/08/10 17:22:22  maubury
*	Updates for bug fixes (regression-fails)
*	
*	Revision 1.9  2001/07/18 17:51:33  maubury
*	Interval Changes
*	
*	Revision 1.8  2001/06/17 07:48:44  maubury
*	Bug fixes
*	
*	Revision 1.7  2001/06/16 10:33:22  maubury
*	Many bug fixes
*	
*	Revision 1.6  2001/06/15 17:32:59  maubury
*	*** empty log message ***
*	
*	Revision 1.5  2001/06/12 03:37:15  afalout
*	make install, make clean
*	
*	Revision 1.4  2001/05/26 12:40:56  maubury
*	Lib GUI Stuff.....
*	
*	Revision 1.3  2001/04/30 17:31:04  maubury
*	*** empty log message ***
*	
*	Revision 1.2  2000/09/28 02:08:58  afalout
*	*** empty log message ***
*	
*	Revision 1.1.1.1  2000/01/29 03:11:43  cvs
*	Initial import of compiler sources using jCVS client
*	
*	Revision 1.3  1998/08/11 20:23:54  fglcomp
*	Added header
*
*
*******************************************************************************/
int inc = 0;
//#include "../libincl/compiler.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


struct expr_str {
        char *expr;
        struct expr_str *next;
};

void *new_expr(char *value) ;
void *append_expr(struct expr_str *orig_ptr,char *value) ;
#include "rules/generated/y.tab.h"
#include "../../lib/libincl/report.h"
#include "rules/generated/kw.h"
#include "../../lib/libincl/oform.h"
#include "../../lib/libincl/tunable.h"
#include "../../lib/libincl/debug.h"
#include "../../lib/libincl/errors.h"
char *ignull (char *s);
char pklist[2048] = "";
char upd_using_notpk[5000] = "";
int upd_using_notpk_cnt = 0;
int rep_type = 0;

//#define CHAR_VALUE 3
//#define NAMED 2
long scan_variables (char *s, int mode);
long isvartype (char *s, int mode);
int add_constant (char t, char *ptr, char *name);
char *acl_getenv (char *);
FILE *mja_fopen (char *, char *);
#ifdef LEXER
char xwords[256][256];
int word_cnt = 0;
#endif

#include <curses.h>
#define USE_PRINTCOMMENT
extern int menu_cnt;
extern int yylineno;
extern char *infilename;
int db_used = 0;
int last_var_found = -1;
int var_hdr_finished;
#ifdef LEXER
int xccode = 0;
long fpos;
#endif

char *get_curr_rep_name ();
struct s_constants
{
  char type;
  void *ptr;
  char name[32];
  char scope;
}
const_arr[MAXCONSTANTS];
int const_cnt = 0;
int when_code[8] = { WHEN_STOP,
  WHEN_NOTSET,
  WHEN_STOP,
  WHEN_CONTINUE,
  WHEN_CONTINUE,
  WHEN_CONTINUE,
  WHEN_NOTSET,
  WHEN_NOTSET
};
char when_to_tmp[64];

char when_to[64][8];

int menu_nos[100];
int cmenu = 0;

int use_group = 0;
char curr_rep_name[256];
int curr_rep_block;
char *upshift (char *a);
char *downshift (char *a);
int findex (char *str, char c);

int max_menu_no = 0;

struct s_report
{
  char rep_cond[2000];
  char rep_expr[2000];
  int a;
  int t;
  int in_b;
};

struct s_report sreports[1024];
int sreports_cnt = 0;

static int print_variable (int z, char ff);
int print_record (int z, char ff);
int printcomment (char *fmt, ...);
int printh (char *fmt, ...);
int printc (char *fmt, ...);
int add_arr_bind (char i, char *nvar);
static bname (char *str, char *str1, char *str2);

char mmtitle[132][132];
extern char *outputfilename;
int push_bind_rec (char *s, char bindtype);
int read_glob_var = 0;
int counters[256];
int count_counters = 0;

struct
{
  char why[20];
  char whytype;
}
report_stack[256];

int report_stack_cnt = 0;
int report_cnt = 1;

int add_bind (char i, char *var);
int nblock_no = 1;

FILE *curr_db = 0;
FILE *outfile = 0;
FILE *hfile = 0;
FILE *ferr = 0;
#define GEN_STACKS 10
char gen_stack[GEN_STACKS][100][80];
int gen_stack_cnt[GEN_STACKS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
struct binding
{
  char varname[132];
  int dtype;
};
struct s_constr_buff
{
  char tab[64];
  char col[64];
}
constr_buff[256];

int constr_cnt = 0;

#define NUMBINDINGS 2048

struct binding ibind[NUMBINDINGS];
struct binding nullbind[NUMBINDINGS];
struct binding obind[NUMBINDINGS];
struct binding fbind[NUMBINDINGS];
struct binding ordbind[NUMBINDINGS];

int ordbindcnt = 0;

int ibindcnt = 0;
int nullbindcnt = 0;
int obindcnt = 0;

int fbindcnt = 0;

int printc (char *fmt, ...);

char *rettype (char *s);

#define MAXVARS 2000


struct variables
{

  char var_name[65];
  char var_type[20];
  char var_size[20];
  char var_arrsize[20];
  int alev1;
  int alev2;
  int alev3;
  int level;
  char *tabname;
  char *pklist;
  char globflg;
}
vars[MAXVARS];

int modlevel = -1;

struct cmds
{

  char cmd_type[20];
  int block_no;

}
command_stack[200];

#ifdef LEXER
int ccnt = 0;
#else
extern int ccnt;
#endif

#define EMPTY "----"

int varcnt = 0;

int in_record = 0;

#define MAXMENU 10
#define MAXMENUOPTS 10
struct s_menu_stack
{

  char menu_title[132];

  char menu_help[132];

  char menu_key[30];
  int menu_helpno;
}
menu_stack[MAXMENU][MAXMENUOPTS];

static char *
print (char *z)
{

  static char c[10] = "(null)";

  if (z == 0)
    {
      return c;
    }

  return z;

}

char *
with_strip_bracket (char *buff)
{
  static char bff[256];
  debug ("In with_strip_bracket\n");
  strcpy (bff, buff);
  strip_bracket (bff);
  return bff;
}

add_variable (char *name, char *type, char *n)
{

	debug ("In mod.c : add_variable (name = %s type = %s n = %d varcnt = %d)\n", name,type,n,varcnt);

  vars[varcnt].level = in_record;


  if (name != 0)
    strcpy (vars[varcnt].var_name, name);

  else
    strcpy (vars[varcnt].var_name, EMPTY);

  if (type != 0)

    strcpy (vars[varcnt].var_type, type);

  else
    strcpy (vars[varcnt].var_type, EMPTY);

//  debug ("In mod.c : add_variable (3)\n");

  if (n != 0) {
	//debug ("In mod.c : add_variable (3a)\n");
    //debug ("/* global variables: name = %d */\n", name);     	/* global variables: name = 50439268 */
	//debug ("/* global variables: varcnt = %d */\n", varcnt);  	/* global variables: varcnt = 18 */
    //debug ("/* global variables: n = %d */\n", n); 				/* global variables: n = 2563 */
    // we core dump here on CygWin:

    debug ("assigning vars[varcnt].var_size ...\n");
	strcpy (vars[varcnt].var_size, n);
    debug ("/* global variables: vars[varcnt].var_size = %d */\n", vars[varcnt].var_size);

  }
  else
  {
//	debug ("In mod.c : add_variable (3b)\n");
	strcpy (vars[varcnt].var_size, EMPTY);
  }

//  debug ("In mod.c : add_variable (4)\n");

  strcpy (vars[varcnt].var_arrsize, EMPTY);

  debug ("added var\n");
  vars[varcnt].tabname = EMPTY;
  vars[varcnt].pklist = EMPTY;
  if (varcnt>=MAXVARS) { exitwith("Too many variables"); yyerror("Too many variables"); }
  varcnt++;

}

clr_variable ()
{

  varcnt = modlevel;

}

inmod ()
{

  modlevel = varcnt;

}

print_variables (int z)
{

  int a;
  int flg = 0;
  int oz;

  int record;

  dump_vars ();

  debug ("/**********************************************************/\n");

  debug ("/******************* Variable definitions *****************/\n");

  debug ("/**********************************************************/\n");

  if (modlevel > 0)
    {
      debug ("/* local variables */\n");
      for (a = modlevel; a < varcnt; a++)
	{

	  if (vars[a].level == 0)
	    print_variable (a, 'L');

	}

    }

  if (modlevel == -1)
    {
      debug ("/* global variables %d */\n", varcnt);
      printcomment ("/* global variables %d */\n", varcnt);

      for (a = 0; a < varcnt; a++)
	{
	  if (vars[a].level == 0)
	    {
	      if (vars[a].globflg=='G')
		print_variable (a, 'G');
	      else
		print_variable (a, 'n');
	    }
	}
      dump_gvars ();
      if (only_doing_globals ())
	exit (0);
      /*varcnt=0; */
    }

  if (modlevel == 0)
    {
      debug ("/* module variables %d */\n", varcnt);

      for (a = 0; a < varcnt; a++)
	{
	  if (vars[a].level == 0 && a >= var_hdr_finished)
	    print_variable (a, 'M');
	}

    }

  debug ("/**********************************************************/\n");

}

push_name (char *a, char *n)
{

  debug ("In mod.c : push_name  a = %s n = %d \n", a, n);

  add_variable (a, 0, n);

}

push_type (char *a, char *n, char *as)
{

  int z;

  debug ("push_type : %s %s %s", a, n, as);
  for (z = varcnt - 1; z >= 0; z--)
    {
      if (strcmp (vars[z].var_type, EMPTY) != 0)
	break;
      if (a != 0)
	{
	  if (strcmp (a, "_ASSOCIATE") == 0)
	    {
	      printc ("DEF_ASS (_usg%s,%s+1);\n",
		      downshift (vars[z].var_name), as);
	      printc
		("#define ASSOCIATE_%s(w,rw) %s[ass_hash(_usg%s,%s+1,%s,w,sizeof(_usg%s),rw)]\n",
		 upshift (vars[z].var_name), downshift (vars[z].var_name),
		 downshift (vars[z].var_name), n, as,
		 downshift (vars[z].var_name));
	      continue;
	    }
	}

      if (strcmp (vars[z].var_type, EMPTY) != 0)
	break;

      if (a != 0)
	strcpy (vars[z].var_type, a);
      else
	strcpy (vars[z].var_type, EMPTY);

      if (n != 0)
	{
	  strcpy (vars[z].var_size, n);

	}
      else
	strcpy (vars[z].var_size, EMPTY);

      if (as != 0)
	{
	  debug ("Setting array size in vars...%s on %s", as,
		 vars[z].var_name);
	  strcpy (vars[z].var_arrsize, as);
	}

      else
	{
	  debug ("unSetting array size in vars...%s on %s", as,
		 vars[z].var_name);
	  //strcpy (vars[z].var_arrsize, EMPTY);
	}

    }

}

push_record ()
{
  //in_record++;
  push_type ("_RECORD", 0, 0);
}

push_associate (char *a, char *b)
{
  push_type ("_ASSOCIATE", a, b);
}

pop_associate (char *a)
{
  /*add_variable (0,"_ENDASSOC", 0); */
}

add_link_to (char *tab, char *pkey)
{
  char *pt;
  char *pk;
  int z;
  debug ("Adding link to %s %s\n", tab, pkey);
  pt = strdup (tab);
  pk = strdup (pkey);
  for (z = varcnt; z >= 0; z--)
    {
      if (strcmp (vars[z].var_type, "_RECORD") == 0)
	{
	  debug ("vars[%d] is _RECORD\n", z);
	  vars[z].tabname = pt;
	  vars[z].pklist = pk;
	  break;
	}
    }
}

pop_record ()
{

  //in_record--;
  debug ("In mod.c : pop_record\n");

  add_variable (0, "_ENDREC", 0);

}

print_variable (int z, char ff)
{
  char tmpbuff[80];

  debug ("Printing variable %d %s", ff, vars[z].var_name);

  if (strcmp (vars[z].var_name, "time") == 0)
    return;

  if (strcmp (vars[z].var_type, "_ENDREC") == 0)
    {

      return;

    }

  if (strcmp (vars[z].var_type, "_ASSOCIATE") == 0)
    {
      printc
	("#define ASSOCIATE_%s(w) %s[ass_hash(_usg%s,%s,%s+1,w,sizeof(_usg%s))]\n",
	 upshift (vars[z].var_name), downshift (vars[z].var_name),
	 downshift (vars[z].var_name), vars[z].var_arrsize, vars[z].var_size,
	 downshift (vars[z].var_name));

      return;
    }

  if (strcmp (vars[z].var_type, "_RECORD") == 0)
    {
      setinc (1);
      print_record (z, ff);
      setinc (-1);

      return;

    }

  if (strcmp (vars[z].var_arrsize, EMPTY) == 0)
    {
      sprintf (tmpbuff, "%s %s", vars[z].var_type, vars[z].var_name);
    }
  else
    {
      sprintf (tmpbuff, "%s %s[%d]", vars[z].var_type,
	       vars[z].var_name, atoi(vars[z].var_arrsize));
    }

  if (isin_command ("REPORT"))
    {
      if (strcmp (vars[z].var_type, "char") == 0)
	{
	  if (ff != '-')
	    printc ("static %s [%d+1]; /* ?5 */\n", tmpbuff,
		    atoi(vars[z].var_size));
	  else
	    printc ("%s [%d+1]; /* ?4 */\n", tmpbuff, atoi(vars[z].var_size));
	}
      else
	{
	  if (ff != '-')
	    printc ("static %s;\n", tmpbuff);
	  else
	    printc ("%s;\n", tmpbuff);
	}
    }
  else
    {
      if (strcmp (vars[z].var_type, "char") == 0)
	{
	  if (ff != 'G')
	    printc ("%s [%d+1];\n", tmpbuff, atoi(vars[z].var_size));
	  if (ff == 'G')
	    printc ("extern %s [%d+1];\n", tmpbuff, atoi(vars[z].var_size));
	}
      else
	{
	  if (ff != 'G')
	    printc ("%s;\n", tmpbuff);
	  if (ff == 'G')
	    printc ("extern %s;\n", tmpbuff);
	}
    }

}

print_record (int z, char ff)
{

  int a;

  int lvl = 1;

  if (isin_command ("REPORT"))
    {
      if (ff != '-')
	printc ("static struct { /* ?0 */\n");
      else
	printc ("struct { /* ?1 */\n");

    }
  else
    {
      if (ff != 'G')
	printc ("struct { /* ?2 */\n");
      if (ff == 'G')
	printc ("extern struct { /* ?3 */\n");
    }

  for (a = z + 1; a < varcnt; a++)
    {

      if (strcmp (vars[a].var_type, "_RECORD") == 0)
	{

	  if (vars[a].level > vars[z].level)
	    a = print_record (a, '-');

	  continue;

	}

      if (strcmp (vars[a].var_type, "_ENDREC") == 0)
	{

	  break;

	}
      print_variable (a, '-');

    }

  if (strcmp (vars[z].var_arrsize, EMPTY) == 0)
    {
      printc ("} %s;\n", vars[z].var_name);
    }

  else
    {
      printc ("} %s[%d];\n", vars[z].var_name, atoi(vars[z].var_arrsize));
    }

  return a;

}

push_command (int mn, int mnopt, char *a, char *b, char *c, char *hlp)
{
  strcpy (menu_stack[mn][mnopt - 1].menu_title, b);
  strcpy (menu_stack[mn][mnopt - 1].menu_help, c);
  strcpy (menu_stack[mn][mnopt - 1].menu_key, a);
  if (hlp)
    menu_stack[mn][mnopt - 1].menu_helpno = atoi (hlp);
  else
    menu_stack[mn][mnopt - 1].menu_helpno = 0;
  menu_stack[mn][mnopt].menu_title[0] = 0;
  menu_stack[mn][mnopt].menu_help[0] = 0;
  menu_stack[mn][mnopt].menu_key[0] = 0;
  debug ("Menu %d Option %d '%s'", mn, mnopt, b);
}

print_menu (mn)
{

  int a;
  int c;
  c = 0;

  for (a = 0; menu_stack[mn][a].menu_title[0] != 0 ||
       menu_stack[mn][a].menu_key[0] != 0 ||
       menu_stack[mn][a].menu_help[0] != 0; a++)
    c = a;

  printc ("m=(void *)new_menu(%s,1,1,%d,0,%d,\n", mmtitle[mn], 2, c + 1);

  for (a = 0; menu_stack[mn][a].menu_title[0] != 0 ||
       menu_stack[mn][a].menu_key[0] != 0 ||
       menu_stack[mn][a].menu_help[0] != 0; a++)
    {

      if (a > 0)
	printc (",\n");

      printc ("         %s,%s,%s,%d,0",
	      menu_stack[mn][a].menu_title,
	      menu_stack[mn][a].menu_key,
	      menu_stack[mn][a].menu_help, menu_stack[mn][a].menu_helpno);

    }

  printc (");\ndisp_h_menu(m);cmd_no=-2;continue;\n");

}

incprint ()
{

  int a;

  for (a = 0; a <= inc; a++)
    {

      printc ("   ");

    }

}

setinc (a)
{
  inc += a;
}

long
scan_variable (char *s)
{
  char buff[256];
  int a;
  a=scan_variables (s, 1);

  if (a==-1) {
	strcpy(buff,s);
	strcat(buff,".*");
	a=scan_variables(buff,1);
  }
  return a;
}

long
scan_variables (char *s, int mode)
{
  int a;
  long z;
  char buff[256];
  char buff2[256];
  char *ptr;
  int dir;
  int flg;
  int lvl = 0;
  last_var_found = -1;

  if (s[0] == '.' && s[1] == 0)
    return -1;

  if (s[0] == 0)
    return -1;

  if (strchr(s,'\n')) return -2; // This is a variable thru variable..
 
  strcpy (buff, s);
  if (s[0] == ' ')
    {
      if (strncmp (buff, " ASSOCIATE_", 11) == 0)
	{
	  strcpy (buff, &s[11]);
	  strcpy (buff2, &s[findex (s, ')') + 1]);
	  //debug ("/*Extra bit = %s*/\n", buff2);
	  buff[findex (buff, '(')] = 0;
	  strcat (buff, buff2);
	  convlower (buff);
	  //debug ("/*whole = %s*/\n", buff);
	}
      else
	return -1;
    }

  strip_bracket (buff);
  //debug ("Stripped\n");

  strcat (buff, ".");
  ptr = strtok (buff, ".");
  //debug ("Looking for %s", buff);
  a = varcnt;
  dir = -1;

  while (1)
    {
      a += dir;
      if (lvl > 0 && dir == -1)
	{
	  dir = 1;
	  a += 2;
	}

      if (a >= varcnt && dir == 1)
	break;

      if (a < 0 && dir == -1)
	break;

      //debug ("Check %d > %d...", lvl, vars[a].level);

      if (lvl > vars[a].level)
	break;

      ////debug ("Checking %s %s  %d %d", ptr, vars[a].var_name, vars[a].level,
	     //lvl);

      if ((strcmp (ptr, "*") == 0 || strcmp (vars[a].var_name, ptr) == 0)
	  && vars[a].level == lvl)
	{
	  ptr = strtok (0, ".");
	  if (ptr == 0)
	    {
	      //debug ("Got no more to check");
	    }
	  else
	    {
	      //debug ("Got more to check '%s'", ptr);
	      //debug ("vn=%s %s %s %s", vars[a].var_name, vars[a].var_type,
		     //vars[a].var_arrsize, vars[a].var_size);
	      if (strcmp (vars[a].var_type, "_RECORD") == 0)
		{
		  //debug ("_RECORD....");
		  while (a < varcnt)
		    {
		      //debug ("Looking for more record declarations....");
		      if (strcmp (vars[a + 1].var_type, "_RECORD") == 0 &&
			  vars[a].level == vars[a + 1].level)
			{
			  a++;
			  continue;
			}
		      debug (" ---> vn=%s %s %s %s", vars[a].var_name,
			     vars[a].var_type, vars[a].var_arrsize,
			     vars[a].var_size);
		      break;
		    }

		}
	    }
	  flg = 0;
	  if (ptr == 0)
	    flg = 1;
	  else if (strcmp (ptr, "*") == 0)
	    {
	      flg = 1;
	    }

	  //debug ("flg=%d", flg);

	  if (flg)
	    {
	      //debug ("Types : %s %s", vars[a].var_type, vars[a].var_size);
	      z =
		find_type (vars[a].var_type) +
		(atoi (vars[a].var_size) << 16);
	      //debug ("Setting last_var_found to %d\n", a);
	      last_var_found = a;
	      //debug ("Find type returned %x", z);
	      return z;
	    }
	  //debug ("More levels...");

	  lvl++;

	}

    }
  debug ("Variable not there : %s",s);

  return -1;

}

long
isarrvariable (char *s)
{
  long a;
  a = isvartype (s, 1);
  debug ("Checking if %s is an array %d", s, a);
  return a;
}

long
isrecvariable (char *s)
{
  return isvartype (s, 2);
}

long
isvartype (char *s, int mode)
{
  int a;
  long z;
  char buff[256];
  char *ptr;
  int flg;
  int dir;
  int lvl = 0;
  if (s[0] == '.' && s[1] == 0)
    return -1;
  if (s[0] == 0)
    return -1;
  strcpy (buff, s);
  strip_bracket (buff);
  debug ("Striped2\n");
  strcat (buff, ".");
  ptr = strtok (buff, ".");
  a = varcnt;
  dir = -1;
  while (1)
    {
      a += dir;
      if (lvl > 0 && dir == -1)
	{
	  dir = 1;
	  a += 2;
	}
      if (a >= varcnt && dir == 1)
	break;
      if (a < 0 && dir == -1)
	break;
      if (lvl > vars[a].level)
	break;
      if ((strcmp (ptr, "*") == 0 || strcmp (vars[a].var_name, ptr) == 0)
	  && vars[a].level == lvl)
	{
	  ptr = strtok (0, ".");
	  flg = 0;
	  if (ptr == 0)
	    flg = 1;
	  else if (strcmp (ptr, "*") == 0)
	    flg = 1;

	  if (flg && mode == 1)
	    {
	      debug ("Seems to match %s %d", vars[a].var_name,
		     vars[a].var_arrsize);
	      return atoi (vars[a].var_arrsize);
	    }

	  if (flg && mode == 2)
	    {
	      return (strcmp (vars[a].var_type, "_RECORD") == 0);
	    }

	  lvl++;
	}
    }
  return 0;
}

scan_arr_variable (char *s)
{

  int a;
  char buff[256];
  char *ptr;
  int lvl = 0;
  if (s[0] == '.' && s[1] == 0)
    return -1;
  if (s[0] == 0)
    return -1;
  strcpy (buff, s);
  strip_bracket (buff);
  debug ("striped3");
  strcat (buff, ".");
  ptr = strtok (buff, ".");
  for (a = 0; a < varcnt; a++)
    {

      debug ("chk: %d %s %s %d %d\n", a, vars[a].var_name, ptr, vars[a].level,
	     lvl);

      if (strcmp (vars[a].var_name, ptr) == 0 && vars[a].level == lvl)
	{

	  ptr = strtok (0, ".");

	  if (ptr == 0)
	    {

	      if (atoi (vars[a].var_arrsize) > 0)
		{
		  printc ("range_chk(%s,%d);\n", s,
			  atoi (vars[a].var_arrsize));
		}

	      return find_type (vars[a].var_type);

	    }

	  lvl++;

	}

    }

  debug ("/* Warning    Couldnt find %s */\n", s);

  return -1;

}

find_type (char *s)
{
  char errbuff[80];
  debug ("find_type %s\n", s);
  if (strcmp ("char", s) == 0)
    return 0;

  if (strcmp ("long", s) == 0)
    return 2;

  if (strcmp ("integer", s) == 0)
    return 1;

  if (strcmp ("int", s) == 0)
    return 1;
  if (strcmp ("short", s) == 0)
    return 1;

  if (strcmp ("double", s) == 0)
    return 3;

  if (strcmp ("float", s) == 0)
    return 4;

  if (strcmp ("fgldecimal", s) == 0)
    return 5;

  if (strcmp ("serial", s) == 0)
    return 6;

  if (strcmp ("fgldate", s) == 0)
    return 7;

  if (strcmp ("fglmoney", s) == 0)
    return 8;

  if (strcmp ("struct_dtime ", s) == 0)
    return 10;

  if (strcmp ("struct_dtime ", s) == 0)
    return 10;

  if (strcmp ("fglbyte", s) == 0)
    return 11;

  if (strcmp ("fgltext", s) == 0)
    return 12;

  if (strcmp ("varchar", s) == 0)
    return 13;

  if (strcmp ("struct_ival ", s) == 0)
    return 14;

  if (strcmp ("_RECORD", s) == 0)
    return -2;

  debug ("Invalid type : %s\n", s);
  sprintf (errbuff, "Internal Error (Invalid type : %s)\n", s);
  yyerror (errbuff);
  return 0;

}

set_variable (char *name, char *type, char *n, char *as, int lvl)
{

  vars[varcnt].level = lvl;

  strcpy (vars[varcnt].var_name, name);

  strcpy (vars[varcnt].var_type, type);

  strcpy (vars[varcnt].var_size, n);

  strcpy (vars[varcnt].var_arrsize, as);

  if (varcnt>=MAXVARS) { exitwith("Too many variables"); yyerror("Too many variables"); }
  varcnt++;

}

set_4gl_vars ()
{

  set_variable ("int_flag", "long", "0", "----", 0);
  set_variable ("quit_flag", "long", "0", "----", 0);
  set_variable ("status", "long", "----", "----", 0);
  set_variable ("sqlca", "_RECORD", "----", "----", 0);
  set_variable ("sqlcode", "long", "----", "----", 1);
  set_variable ("sqlerrm", "char", "71", "----", 1);
  set_variable ("sqlerrp", "char", "8", "----", 1);
  set_variable ("sqlerrd", "long", "----", "6", 1);
  set_variable ("sqlawarn", "char", "8", "----", 1);
  set_variable ("sqlstate", "char", "9", "----", 1);
  set_variable ("----", "_ENDREC", "----", "----", 0);

  set_variable ("today", "fgldate", "----", "----", 0);
  set_variable ("user", "char", "8", "----", 0);
  set_variable ("notfound", "long", "----", "----", 0);
  set_variable ("pageno", "long", "----", "----", 0);
  set_variable ("lineno", "long", "----", "----", 0);
  set_variable ("usrtime", "long", "----", "----", 0);
  set_variable ("time", "char", "8", "----", 0);
  add_constant ('i', "100", strdup ("notfound"));
  var_hdr_finished = varcnt;
}

open_db (char *s)
{

  char db[132];
  char buff[256];
  strcpy (db, s);
  set_status (0, 1);
  init_connection (db);
  if (get_status () != 0)
    {
      sprintf (buff, "Could not connect to database %s (%s)", s,
	       get_sqlerrm ());
      yyerror (buff);
    }
  if (db_used == 0)
    db_used = 1;
}

push_like (char *t)
{

  debug (">>>>>> %s\n", t);
  push_like2 (t);
  debug ("<<<<<<\n");
}

push_like2 (char *t2)
{
  char buff[300];
  char buffer[300];
  char *a;
  char *b;
  char *c;
  char t[256];
  char col[256];
  int isize;
  int idtype;
  char csize[20];
  char cdtype[20];
  int rval;
  char non[] = "0";
  debug ("In push_like2");

  if (db_used == 0)
    {
      sprintf (buff, "You cannot use LIKE without specifying a database");
      yyerror (buff);
      return;
    }

  strcpy (t, t2);
  strcpy (buff, t);
  strcat (buff, ".");

  a = strtok (buff, ".");	/* table name */
  b = strtok (0, ".");		/* column name */
  debug ("a='%s' b='%s'", a, b);
  if (b)
    {
      rval = read_columns (a, b, &idtype, &isize);
      if (rval == 0)
	{
	  sprintf (buff, "%s.%s does not exist in the database", a, b);
	  yyerror (buff);
	  return;
	}
      sprintf (cdtype, "%d", idtype & 15);
      sprintf (csize, "%d", isize);
      debug ("---> %s %s", cdtype, csize);
      trim_spaces (b);
      //push_name (b, 0);
      push_type (rettype (cdtype), csize, 0);
      return 1;
    }

  while (1)
    {
      col[0] = 0;
      debug ("Looking for table '%s' col '%s'", a, col);

      rval = read_columns (a, col, &idtype, &isize);

      if (rval == 0 && a)
	{
	  sprintf (buff, "%s does not exist in the database", a);
	  yyerror (buff);
	  return;
	}
      if (rval == 0 && a == 0)
	break;

      a = 0;

      sprintf (cdtype, "%d", idtype & 15);
      sprintf (csize, "%d", isize);
      debug ("%d %d", idtype, isize);
      debug ("---> %s %s", cdtype, csize);
      debug ("read_columns: Pushing %s %s %s", col, cdtype, csize);
      trim_spaces (col);
      push_name (col, 0);
      push_type (rettype (cdtype), csize, 0);
    }

  return 0;

}

push_rectab (char *t)
{

  push_like (t);

}

dump_vars ()
{

  FILE *f;

  int a;
  if (getenv ("DUMPVARS") == 0)
    return;

  f = (FILE *) mja_fopen ("dumpvars.out", "w");

  for (a = 0; a < varcnt; a++)
    {

      fprintf (f, " %d - %s,%s,%s,%s,%d,%s,%s\n", a,
	       ignull (vars[a].var_name),
	       ignull (vars[a].var_type),
	       ignull (vars[a].var_size),
	       ignull (vars[a].var_arrsize),
	       vars[a].level,
	       ignull (vars[a].tabname), ignull (vars[a].pklist));

    }

  fclose (f);

}

push_menu_title (char *s)
{

  strcpy (mmtitle[menu_cnt], s);

}

push_blockcommand (char *cmd_type)
{

  debug("START BLOCK %s",cmd_type);
  debug ("\n\n--------->%s\n\n", cmd_type);
  debug (" /* new block %s %d */\n", cmd_type, ccnt);
  strcpy (command_stack[ccnt].cmd_type, cmd_type);
  if (strcmp (cmd_type, "MAIN") == 0
      || strcmp (cmd_type, "FUNC") == 0 ||
      strcmp (cmd_type, "REPORT") == 0 || strcmp (cmd_type, "GLOBALS") == 0)
    {
      command_stack[ccnt].block_no = -1;
    }
  else
    {
      printc ("\n");
      printc ("START_BLOCK_%d:\n", nblock_no);
      command_stack[ccnt].block_no = nblock_no++;
    }
  debug (" Added new block");
  ccnt++;
}

add_continue_blockcommand (char *cmd_type)
{
  int z;
  int a;

  char err[80];
/* more checks here ! */

  for (a = ccnt - 1; a > 0; a--)
    {
      if (strcmp (command_stack[a].cmd_type, cmd_type) == 0)
	{
	  printc ("\n");
	  printc ("CONTINUE_BLOCK_%d: /*add_continue - %s */ ",
		  command_stack[a].block_no, cmd_type);
	  return;
	}
    }

}

pop_blockcommand (char *cmd_type)
{
  int z;
  int a;

  char err[80];
  debug("END BLOCK %s",cmd_type);
/* more checks here ! */
  ccnt--;
  if (command_stack[ccnt].block_no > 0)
    {
      printc ("\n");

      if (iscontinuecmd (cmd_type))
	{
	  //printc ("goto END_BLOCK_%d;\n", command_stack[ccnt].block_no);
	  printc ("CONTINUE_BLOCK_%d: continue; /* %s */\n",
		  command_stack[ccnt].block_no, cmd_type);
	  printc ("}\n");
	}
      printc ("END_BLOCK_%d: /* %s */;\n\n", command_stack[ccnt].block_no,
	      cmd_type);
    }

  debug ("\n\n--------->%s\n\n", cmd_type);

  if (strcmp (command_stack[ccnt].cmd_type, cmd_type) == 0)
    {

      command_stack[ccnt].cmd_type[0] = 0;

      return;

    }

  sprintf (err, "%s was not last block command (I've got a %s @ %d)\n", cmd_type,command_stack[ccnt].cmd_type,ccnt); 
  debug(err);
  debug ("------------------\n");
  for (a = 0; a <= ccnt; a++)
    {
      debug ("   %s\n", command_stack[a].cmd_type);
    }
  debug ("------------------\n");
  yyerror (err);
  exit (0);
}

in_command (char *cmd_type)
{

  int z;

  debug ("Check for %s %d \n", cmd_type, ccnt);

  if (ccnt == 0)
    {

      debug ("Stack is empty\n");
      return 0;
    }

  for (z = ccnt - 1; z >= 0; z--)
    {

      if (command_stack[z].cmd_type == 0 || command_stack[z].cmd_type[0] == 0)
	continue;

      if (strcmp (command_stack[z].cmd_type, cmd_type) == 0)
	{

	  debug ("OK\n");

	  return 1;

	}

    }

  printf ("Not in a %s command\n", cmd_type);
  yyerror ("Can't exit command");

  return 0;
}

isin_command (char *cmd_type)
{

  int z;
  //printf ("Check for %s %d \n", cmd_type, ccnt);
  if (ccnt == 0)
    {
      //printf ("Stack is empty\n");
      return 0;
    }

  for (z = ccnt - 1; z >= 0; z--)
    {

      if (command_stack[z].cmd_type == 0 || command_stack[z].cmd_type[0] == 0)
	continue;

      if (strcmp (command_stack[z].cmd_type, cmd_type) == 0)
	{
	  debug ("OK\n");
	  return 1;
	}

    }
  return 0;
}

char *
rettype (char *s)
{
  static char rs[20] = "long";
  debug ("In rettype : %s", s);

  if (strcmp (s, "0") == 0)
    strcpy (rs, "char");

  if (strcmp (s, "1") == 0)
    strcpy (rs, "short");

  if (strcmp (s, "2") == 0)
    strcpy (rs, "long");

  if (strcmp (s, "3") == 0)
    strcpy (rs, "double");

  if (strcmp (s, "4") == 0)
    strcpy (rs, "float");

  if (strcmp (s, "5") == 0)
    strcpy (rs, "fgldecimal");

  if (strcmp (s, "6") == 0)
    strcpy (rs, "long");

  if (strcmp (s, "7") == 0)
    strcpy (rs, "fgldate");

  if (strcmp (s, "8") == 0)
    strcpy (rs, "fglmoney");

  if (strcmp (s, "11") == 0)
    strcpy (rs, "fglbyte");
  if (strcmp (s, "12") == 0)
    strcpy (rs, "fgltext");
  if (strcmp (s, "13") == 0)
    strcpy (rs, "char");

  return rs;
}

static
trim (char *s)
{
  if (s[strlen (s) - 1] == '\n')
    s[strlen (s) - 1] = 0;
}

push_gen (int a, char *s)
{
  debug ("Push %d %s\n", a, s);
  if (gen_stack_cnt[a] >= 90)
    {
      printf ("Out of stack!\n");

      exit (0);
    }
  strcpy (gen_stack[a][gen_stack_cnt[a]++], s);
}

char *
pop_gen (int a)
{
  gen_stack_cnt[a]--;
  gen_stack[a][gen_stack_cnt[a]];
}

pop_all_gen (int a, char *s)
{
  int z;
  for (z = 0; z < gen_stack_cnt[a]; z++)
    {
      if (z > 0)
	debug ("%s ", s);
      debug ("%s", gen_stack[a][z]);
    }
}

print_space ()
{
  char buff[256];
  memset (buff, ' ', 255);
  buff[ccnt * 3] = 0;
  fprintf (outfile, "%s", buff);
}

printc (char *fmt, ...)
{
  va_list args;
  char buff[40960];
  char *ptr;
  int a;

  if (outfile == 0)
    {
      open_outfile ();
    }

  if (outfile == 0)
    return;
  va_start (args, fmt);
  if (getenv ("INCLINES"))
    {
      vsprintf (buff, fmt, args);

      for (a = 0; a < strlen (buff); a++)
	{
	  if (buff[a] == '\n')
	    {
	      if (infilename != 0)
		{
		  fprintf (outfile, "\n#line %d \"%s.4gl\"\n", yylineno,
			   outputfilename);
		}
	      else
		{
		  fprintf (outfile, "\n#line %d \"null\"\n", yylineno,
			   outputfilename);
		}
	    }
	  else
	    {
	      fprintf (outfile, "%c", buff[a]);

	      fflush (outfile);
	    }
	}
    }
  else
    {
      //print_space();

      vsprintf (buff, fmt, args);
      ptr = strtok (buff, "\n");

      while (ptr)
	{
	  print_space ();
	  fprintf (outfile, "%s\n", ptr);
	  ptr = strtok (0, "\n");
	}

    }
}

yyerrorf (char *fmt, ...)
{
  char buff[256];
  va_list args;
  va_start (args, fmt);
  vsprintf (buff, fmt, args);
  yyerror (buff);
}

#ifdef USE_PRINTCOMMENT
printcomment (char *fmt, ...)
{
  va_list args;
  if (outfile == 0)
    {
      open_outfile ();
    }

  if (outfile == 0)
    return;

  if (getenv ("COMMENTS"))
    {
      va_start (args, fmt);
      vfprintf (outfile, fmt, args);
    }
}
#endif

printh (char *fmt, ...)
{
  va_list args;
  if (outfile == 0)
    {
      open_outfile ();
    }
  if (outfile == 0)
    return;

  va_start (args, fmt);
  vfprintf (hfile, fmt, args);
}

open_outfile ()
{
  char h[132];
  char c[132];
  char err[132];
  char *ptr;
  //printf ("OPen outputs\n");
  if (outputfilename == 0)
    {
      debug ("NO output file name");
    }

  //printf ("OPen outputs: %s\n", outputfilename);
  strcpy (c, outputfilename);
  strcpy (h, outputfilename);
  strcpy (err, outputfilename);

  if (strcmp (acl_getenv ("NOCLOBBER"), "N") == 0)
    {
      debug ("Clobbering...");
      set_clobber (outputfilename);
    }

  debug ("Opening output map");
  openmap (outputfilename);
  //printf ("catting");
  ptr = acl_getenv ("NOCFILE");
  if (strlen (ptr))
    {
      if (ptr[0] == 'Y' || ptr[0] == 'y')
	{
	  debug (">>> NO C FILES... %s", ptr);
	  return;
	}
    }

  strcat (c, ".c");
  strcat (h, ".h");
  strcat (err, ".err");
  //printf ("Opening files :\n %s\n %s\n", c, h);
  outfile = mja_fopen (c, "w");
  //ferr = mja_fopen (err, "w");

  fprintf (outfile, "#define fgldate long\n");
  //fprintf (outfile, "#include \"dbform.h\"\n");
  fprintf (outfile, "#include \"4glhdr.h\"\n");
  fprintf (outfile, "#include \"%s\"\n", h);
  if (getenv ("GTKGUI"))
    fprintf (outfile, "#include <acl4glgui.h>\n");
  fprintf (outfile, "static char _compiler_ser[]=\"%s\";\n", get_serno ());
  fprintf (outfile, "static char _module_name[]=\"%s.4gl\";\n",
	   outputfilename);

  hfile = mja_fopen (h, "w");
}

add_string (char *s)
{
  static int cnt = 1;
  return 0;
  fprintf (hfile, ",\n%s", s);
  return cnt++;
}

strip_bracket (char *s)
{
  char buff[256];
  int a;
  int c = 0;
  int f = 0;
  //debug ("Stripping brackets from %s ", s);
  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] == '[')
	f++;
      if (f == 0)
	buff[c++] = s[a];
      if (s[a] == ']')
	f--;
    }
  strcpy (s, buff);
  //debug ("-->%s ", s);
}

start_bind (char i, char *var)
{
  debug ("start_bind %c -  %s", i, var);

  if (i == 'i')
    {
      ibindcnt = 0;
    }
  if (i == 'N')
    {
      nullbindcnt = 0;
    }

  if (i == 'o')
    {
      obindcnt = 0;
    }

  if (i == 'O')
    {
      ordbindcnt = 0;
    }

  if (i == 'f'||i=='F')
    {
      fbindcnt = 0;
    }

  if (var != 0)
    return add_bind (i, var);

  return 0;
}
get_bind_cnt (char i)
{
  if (i == 'i')
    return ibindcnt;
  if (i == 'N')
    return nullbindcnt;
  if (i == 'o')
    return obindcnt;
  if (i == 'f'||i=='F')
    return fbindcnt;
}

add_bind (char i, char *var)
{
  long dtype;

  if (var[0]=='"') {
		dtype=(strlen(var)-2)<<16;
  } else {
      dtype = scan_variable (var);
  }

/*printc(" add_bind %c %s %d %ld\n",i,var,dtype); */
  debug ("add_bind - dtype=%d (%s)\n", dtype,var);

  if (i == 'i')
    {
      if (dtype == -2)
	{
	  debug ("push_bind_rec...");
	  push_bind_rec (var, i);
	}
      else
	{
	  strcpy (ibind[ibindcnt].varname, var);
	  ibind[ibindcnt].dtype = dtype;
	  ibindcnt++;
	}
      return ibindcnt;
    }

  if (i == 'N')
    {
      if (dtype == -2)
	{
	  debug ("push_bind_rec...");
	  push_bind_rec (var, i);
	}
      else
	{
	  strcpy (nullbind[nullbindcnt].varname, var);
	  nullbind[nullbindcnt].dtype = dtype;
	  nullbindcnt++;
	}
      return nullbindcnt;
    }



  if (i == 'o')
    {
      if (dtype == -2)
	{
	  printcomment ("/* add_bind   obind... %s */\n", var);
	  push_bind_rec (var, i);
	}
      else
	{
	  strcpy (obind[obindcnt].varname, var);
	  obind[obindcnt].dtype = dtype;
	  obindcnt++;
	}
      return obindcnt;
    }

  if (i == 'O')
    {
      if (dtype == -2)
	push_bind_rec (var, i);
      else
	{
	  strcpy (ordbind[ordbindcnt].varname, var);
	  ordbind[ordbindcnt].dtype = dtype;
	  ordbindcnt++;
	}
      return ordbindcnt;
    }




  if (i == 'f'||i=='F')
    {
      if (i=='f') dtype=-1;

      if (dtype == -2)
	push_bind_rec (var, i);
      else
	{
      	strcpy (fbind[fbindcnt].varname, var);
      	fbind[fbindcnt].dtype = 0;
      	fbindcnt++;
      	return fbindcnt;
       }
    }

}

print_param (char i)
{
  int a;
  char buff[256];
  //dump_vars ();
  printc ("\n");

  debug("Expanding binding.. - was %d entries",fbindcnt);
  expand_bind(&fbind,'F',fbindcnt);
  debug("Expanded - now %d entries",fbindcnt);

  if (i == 'r')
    {
      printc ("static ");
    }

  printc ("struct BINDING %cbind[]={ /* print_param */\n", i);
  for (a = 0; a < fbindcnt; a++)
    {

      fbind[a].dtype = scan_variable (fbind[a].varname);

      if (a > 0) printc (",\n");

      printc ("{&%s,%d,%d}", fbind[a].varname, (int) fbind[a].dtype & 0xffff,
	      (int) fbind[a].dtype >> 16);
    }
  printc ("\n}; /* end of binding */\n");
  return a;
}

how_many_in_bind (char i)
{
  if (i == 'i')
    return ibindcnt - 1;
  if (i == 'N')
    return nullbindcnt - 1;
  if (i == 'o')
    return obindcnt - 1;
  if (i == 'O')
    return ordbindcnt - 1;
}

print_bind (char i)
{
  int a;
  int dtype;
  debug ("/* %c */\n", i);
  //dump_vars ();
  if (i == 'i')
    {
      printc ("\n");
      printc ("struct BINDING ibind[]={\n /* ibind %d*/", ibindcnt);
      if (ibindcnt == 0)
	{
	  printc ("{0,0,0}");
	}
      for (a = 0; a < ibindcnt; a++)
	{
	  if (a > 0)
	    printc (",\n");
	  printc ("{&%s,%d,%d}", ibind[a].varname,
		  (int) ibind[a].dtype & 0xffff, (int) ibind[a].dtype >> 16);
	}
      printc ("\n}; /* end of binding */\n");
      start_bind (i, 0);
      return a;
    }

  if (i == 'N')
    {
      expand_bind(&nullbind,'N',nullbindcnt) ;
      printc ("\n");
      printc ("struct BINDING nullbind[]={\n /* nullbind %d*/", nullbindcnt);
      if (nullbindcnt == 0)
	{
	  printc ("{0,0,0}");
	}
      for (a = 0; a < nullbindcnt; a++)
	{
	  if (a > 0)
	    printc (",\n");

	  chk_init_var(nullbind[a].varname);

	  printc ("{&%s,%d,%d}", nullbind[a].varname,
		  (int) nullbind[a].dtype & 0xffff, (int) nullbind[a].dtype >> 16);
	}
      printc ("\n}; /* end of binding */\n");
      start_bind (i, 0);
      return a;
    }

  if (i == 'o')
    {
      
      printc ("\n");
      printc ("struct BINDING obind[]={\n");
      if (obindcnt == 0)
	{
	  printc ("{0,0,0}");
	}

      for (a = 0; a < obindcnt; a++)
	{
	  if (a > 0)
	    printc (",\n");
	  printc ("{&%s,%d,%d}", obind[a].varname,
		  (int) obind[a].dtype & 0xffff, (int) obind[a].dtype >> 16);
	}
      printc ("\n}; /* end of binding */\n");
      start_bind (i, 0);
      return a;
    }

  if (i == 'O')
    {
      printc ("\n");
      expand_bind(&ordbind,'O',ordbindcnt);
      printc ("static struct BINDING _ordbind[]={\n");
      if (ordbindcnt == 0)
	{
	  printc ("{0,0,0}");
	}

      for (a = 0; a < ordbindcnt; a++)
	{
	  if (a > 0)
	    printc (",\n");
	  printc ("{&%s,%d,%d}", ordbind[a].varname,
		  (int) ordbind[a].dtype & 0xffff,
		  (int) ordbind[a].dtype >> 16);
	}
      printc ("\n}; /* end of binding */\n");

      start_bind (i, 0);

      return a;
    }

}


print_bind_expr(void *ptr,char i) {
int a;
char buff[256];
  if (i == 'i')
    {
      append_expr(ptr,"struct BINDING ibind[]={");

      if (ibindcnt == 0)
	{
	  append_expr(ptr,"{0,0,0}");
	}
      for (a = 0; a < ibindcnt; a++)
	{
	  if (a > 0) append_expr(ptr,",");
	  sprintf (buff,"{&%s,%d,%d}", ibind[a].varname,
		  (int) ibind[a].dtype & 0xffff, (int) ibind[a].dtype >> 16);
	  append_expr(ptr,buff);
	}
      append_expr(ptr,"};");
      start_bind (i, 0);
      return a;
    }
}


continue_loop (char *cmd_type)
{
  int a;
  int g = 0;
  for (a = ccnt - 1; a >= 0; a--)
    {

      debug ("continue_loop:%s %s\n", command_stack[a].cmd_type, cmd_type);

      if (strcmp (command_stack[a].cmd_type, cmd_type) == 0)
	{
	  g = 1;
	  break;
	}
    }
  if (g == 0)
    {
      debug ("/* wanted to continue a %s but wasnt in one! */", cmd_type);
      return;
    }

  printc ("goto CONTINUE_BLOCK_%d;", command_stack[a].block_no);
}

exit_loop (char *cmd_type)
{
  int a;
  int g = 0;
  for (a = ccnt - 1; a >= 0; a--)
    {

      debug ("exit_loop:%s %s\n", command_stack[a].cmd_type, cmd_type);

      if (strcmp (command_stack[a].cmd_type, cmd_type) == 0)
	{
	  g = 1;
	  break;
	}
    }
  if (g == 0)
    {
      debug ("/* wanted to exit a %s but wasnt in one! */", cmd_type);
      return;
    }

  printc ("goto END_BLOCK_%d;", command_stack[a].block_no);
}

push_report_block (char *why, char whytype)
{
  set_curr_block (0);
  strcpy (report_stack[report_stack_cnt].why, why);
  report_stack[report_stack_cnt].whytype = whytype;
  debug ("/* report block %s %c */ \n", why, whytype);
  printc ("rep_ctrl%d_%d:\n", report_cnt, report_stack_cnt);
  report_stack_cnt++;
}

print_report_ctrl ()
{
  int a;
  debug
    ("/* ********************************************************** */\n");
  debug
    ("/*                 Report Control Block                       */\n");
  debug
    ("/* ********************************************************** */\n");
  printc ("report%d_ctrl:\n", report_cnt);
  printc ("debug(\"ctrl=%%d nargs=%%d\",acl_ctrl,nargs);\n");
/*
   printc("    if (acl_ctrl==REPORT_START) goto start_%d;\n",report_cnt);
   printc("    if (acl_ctrl==REPORT_FINISH) goto finish_%d;\n",report_cnt);
 */
  printc ("    if (acl_ctrl==REPORT_OPS_COMPLETE) return;\n\n");
  printc ("    if (acl_ctrl==REPORT_SENDDATA) {\n");
  printc ("   /* check for after group of */\n");
  printc ("       %s(0,REPORT_DATA);\n", get_curr_rep_name ());
  printc ("   /* check for before group of */\n");
  printc ("    }\n\n");

  /*if (report_stack[a].whytype=='F') printc("if (acl_ctrl==REPORT_FINISH) call %s(0,REPORT_LASTROW)\n", report_cnt,a); */

  printc ("if (acl_ctrl==REPORT_FINISH) {%s(0,REPORT_LASTDATA);return;}\n",
	  get_curr_rep_name ());
  if (rep_type == REP_TYPE_NORMAL)
    {
      printc
	("if (acl_ctrl==REPORT_LASTDATA) {%s(0,REPORT_LASTROW);_started=0;fclose(rep.output);return;}\n",
	 get_curr_rep_name ());
    }
  else
    {
      printc
	("if (acl_ctrl==REPORT_LASTDATA) {%s(0,REPORT_LASTROW);_started=0;pdf_rep_close(&rep);return;}\n",
	 get_curr_rep_name ());

    }
  printc ("    if (acl_ctrl==REPORT_AFTERDATA ) {\n");
  pr_report_agg ();
  printc ("    }\n");

  for (a = 0; a < report_stack_cnt; a++)
    {
/* on last row */
      if (report_stack[a].whytype == 'L')
	printc
	  ("if (acl_ctrl==REPORT_LASTROW) { acl_ctrl=0;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);

/* on every row */
      if (report_stack[a].whytype == 'E')
	printc
	  ("if (acl_ctrl==REPORT_DATA) {acl_ctrl=REPORT_AFTERDATA;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);

/* before group of */
      if (report_stack[a].whytype == 'B')
	printc
	  ("if (acl_ctrl==REPORT_BEFOREGROUP&&nargs==%s) {nargs=-1*nargs;goto rep_ctrl%d_%d;}\n",
	   report_stack[a].why, report_cnt, a);

/* after group of */
      if (report_stack[a].whytype == 'A')
	printc
	  ("if (acl_ctrl==REPORT_AFTERGROUP&&nargs==%s) {nargs=-1*nargs;goto rep_ctrl%d_%d;}\n",
	   report_stack[a].why, report_cnt, a);

      if (report_stack[a].whytype == 'T')
	printc
	  ("if (acl_ctrl==REPORT_PAGETRAILER) {acl_ctrl=REPORT_PAGEHEADER;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);

      if (report_stack[a].whytype == 'P')
	printc
	  ("if (acl_ctrl==REPORT_PAGEHEADER&&rep.page_no==1) {acl_ctrl=0;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);

      if (report_stack[a].whytype == 'p')
	printc
	  ("if (acl_ctrl==REPORT_PAGEHEADER&&(rep.page_no!=1||(rep.page_no==1&&rep.has_first_page==0))) {acl_ctrl=0;goto rep_ctrl%d_%d;}\n",
	   report_cnt, a);

    }
  pr_report_agg_clr ();
}

get_curr_rep ()
{
  return report_cnt;
}

print_rep_ret ()
{
  printc ("goto report%d_ctrl;\n\n", report_cnt);
}

init_report_structure (struct rep_structure * rep)
{
  rep->top_margin = 3;
  rep->bottom_margin = 3;
  rep->left_margin = 5;
  rep->right_margin = 132;
  rep->page_length = 66;
  rep->page_no = 0;
  rep->printed_page_no = 0;
  rep->line_no = 0;
  rep->col_no = 0;
  rep->output_mode = 'F';
  strcpy (rep->output_loc, "\"stdout\"");
}

pdf_init_report_structure (struct pdf_rep_structure *rep)
{
  rep->top_margin = -36.0;
  rep->bottom_margin = -36.0;
  rep->left_margin = -36.0;

  rep->page_length = -842.0;	// A4
  rep->page_width = -595.0;	// A4

  rep->right_margin = rep->page_width - (2 * rep->left_margin);

  rep->page_no = 0;
  rep->printed_page_no = 0;
  rep->line_no = 0.0;
  rep->col_no = 0.0;
  rep->output_mode = 'F';
  rep->font_size = 10;
  rep->paper_size = 1;
  strcpy (rep->font_name, "\"Helvetica\"");
  strcpy (rep->output_loc, "\"stdout\"");
}

print_call_out ()
{
  printc ("goto output_%d;\n", report_cnt);
}

print_output_rep (struct rep_structure *rep)
{
  printc ("output_%d:\n", report_cnt);
  printc ("rep.top_margin=%d;\n", rep->top_margin);
  printc ("rep.bottom_margin=%d;\n", rep->bottom_margin);
  printc ("rep.left_margin=%d;\n", rep->left_margin);
  printc ("rep.right_margin=%d;\n", rep->right_margin);
  printc ("rep.page_length=%d;\n", rep->page_length);
  printc ("rep.page_no=%d;\n", rep->page_no);
  printc ("rep.printed_page_no=%d;\n", rep->printed_page_no);
  printc ("rep.line_no=%d;\n", rep->line_no);
  printc ("rep.col_no=%d;\n", rep->col_no);
  printc ("if (strlen(_rout2)==0)\n");
  printc ("strcpy(rep.output_loc,%s);\n", rep->output_loc);
  printc ("else strcpy(rep.output_loc,_rout2);\n");
  printc ("if (strlen(_rout1)==0)\n");
  printc ("rep.output_mode='%c';\n", rep->output_mode);
  printc ("else rep.output_mode=_rout1[0];\n");
  printc ("rep.report=&%s;\n", get_curr_rep_name ());
  printc ("trim(rep.output_loc);");
  print_rep_ret ();
}

pdf_print_output_rep (struct pdf_rep_structure *rep)
{
  printc ("output_%d:\n", report_cnt);
  printc ("strcpy(rep.font_name,%s);\n", rep->font_name);
  printc ("rep.font_size=%f;\n", rep->font_size);
  printc ("rep.paper_size=%d;\n", rep->paper_size);

  printc ("rep.top_margin=pdf_size(%f,'l',&rep);\n", rep->top_margin);
  printc ("rep.bottom_margin=pdf_size(%f,'l',&rep);\n", rep->bottom_margin);
  printc ("rep.page_length=pdf_size(%f,'l',&rep);\n", rep->page_length);
  printc ("rep.left_margin=pdf_size(%f,'c',&rep);\n", rep->left_margin);
  printc ("rep.right_margin=pdf_size(%f,'c',&rep);\n", rep->right_margin);
  printc ("rep.page_width=pdf_size(%f,'c',&rep);\n", rep->page_width);

  printc ("rep.page_no=%d;\n", rep->page_no);
  printc ("rep.printed_page_no=%d;\n", rep->printed_page_no);

  printc ("rep.line_no=%f;\n", rep->line_no);
  printc ("rep.col_no=%f;\n", rep->col_no);

  printc ("if (strlen(_rout2)==0)\n");
  printc ("strcpy(rep.output_loc,%s);\n", rep->output_loc);
  printc ("else strcpy(rep.output_loc,_rout2);\n");
  printc ("if (strlen(_rout1)==0)\n");
  printc ("rep.output_mode='%c';\n", rep->output_mode);
  printc ("else rep.output_mode=_rout1[0];\n");
  printc ("rep.report=&%s;\n", get_curr_rep_name ());
  printc ("trim(rep.output_loc);");
  print_rep_ret ();
}

scan_orderby (char *varname, int cnt)
{
  int a;
  debug ("Scanning order by for %s %d", varname, ordbindcnt);
  for (a = 0; a <= cnt; a++)
    {
      debug ("/* chk %s against %s */\n", varname, ordbind[a].varname);
      if (aubit_strcasecmp (ordbind[a].varname, varname) == 0)
	return a;
    }
  return -1;
}

print_form_attrib (struct form_attr * form_attrib)
{
  printc ("%d,%d,%d,%d,%d,%d,%d,%d,(0x%x)",
	  form_attrib->iswindow,
	  form_attrib->form_line,
	  form_attrib->error_line,
	  form_attrib->prompt_line,
	  form_attrib->menu_line,
	  form_attrib->border,
	  form_attrib->comment_line,
	  form_attrib->message_line, form_attrib->attrib);
  debug ("Printing attributes\n");
  debug ("%d,%d,%d,%d,%d,%d,%d,%d,(0x%x)", form_attrib->iswindow,
	 form_attrib->form_line, form_attrib->error_line,
	 form_attrib->prompt_line, form_attrib->menu_line,
	 form_attrib->border, form_attrib->comment_line,
	 form_attrib->message_line, form_attrib->attrib);
}

reset_attrib (struct form_attr *form_attrib)
{
  debug ("Reseting attributes\n");
  form_attrib->iswindow = 0;
  form_attrib->form_line = 3;
  form_attrib->error_line = -1;
  form_attrib->comment_line = -2;
  form_attrib->message_line = 1;
  form_attrib->prompt_line = -2;
  form_attrib->menu_line = 1;
  form_attrib->border = 0;
  form_attrib->attrib = 0;
}

attr_code (char *s)
{
  debug ("Decoding colour %s\n", s);
  if (strcmp (s, "BLACK") == 0)
    return colour_code (COLOR_BLACK);
  if (strcmp (s, "YELLOW") == 0)
    return colour_code (COLOR_YELLOW);
  if (strcmp (s, "BLUE") == 0)
    return colour_code (COLOR_BLUE);
  if (strcmp (s, "CYAN") == 0)
    return colour_code (COLOR_CYAN);
  if (strcmp (s, "MAGENTA") == 0)
    return colour_code (COLOR_MAGENTA);
  if (strcmp (s, "GREEN") == 0)
    return colour_code (COLOR_GREEN);
  if (strcmp (s, "RED") == 0)
    return colour_code (COLOR_RED);
  if (strcmp (s, "WHITE") == 0)
    return colour_code (COLOR_WHITE);
  if (strcmp (s, "REVERSE") == 0)
    return A_REVERSE;
  if (strcmp (s, "BLINK") == 0)
    return A_BLINK;
  if (strcmp (s, "UNDERLINE") == 0)
    return A_UNDERLINE;
  if (strcmp (s, "BOLD") == 0)
    return A_BOLD;
  if (strcmp (s, "NORMAL") == 0)
    return A_NORMAL;
  if (strcmp (s, "INVISIBLE") == 0)
    return colour_code (COLOR_BLACK);
  if (strcmp (s, "DIM") == 0)
    return A_DIM;
  return 0;
}

colour_code (int a)
{
  int z, b;
  z = 1;
#ifdef WIN32
  return COLOR_PAIR (a + 1);
#else
  return COLOR_PAIR (a + 1);
#endif
}

print_field_bind (int ccc)
{
  char tabname[40];
  char colname[40];
  int a;
  debug ("%d\n", ibindcnt);
  printcomment ("/* ibindcnt=%d */\n", ibindcnt);

  for (a = 0; a < ccc; a++)
    {
      printcomment ("/* a=%d */\n", a);
      bname (ibind[a].varname, tabname, colname);
      if (a > 0)
	printc (",");
      if (colname[0] != 0)
	printc ("\"%s\",1", colname);
      else
	printc ("\"%s\",1", tabname);
    }
  return a;
}

static
bname (char *str, char *str1, char *str2)
{
  char fn[132];
  int a;
  char *ptr;
  strcpy (fn, str);
  for (a = strlen (fn); a >= 0; a--)
    {
      if (fn[a] == '.')
	{
	  fn[a] = 0;
	  break;
	}
    }
  ptr = &fn[a];
  strcpy (str1, fn);
  if (a >= 0)
    strcpy (str2, ptr + 1);
  else
    str2[0] = 0;
}

get_single_key (char *s)
{
  char buff[2];
  s[0] = s[1];
  s[1] = 0;
}

set_mod_level (int a)
{
  modlevel = a;
}

long
get_variable_dets (char *s, int *type, int *arrsize, int *size, int *level,
		   char *arr)
{
  int a;
  long z;
  char buff[256];
  char *ptr;
  int lvl = 0;
  if (s[0] == '.' && s[1] == 0)
    return -1;
  if (s[0] == 0)
    return -1;
  strcpy (buff, s);
  strip_bracket (buff);
  strcat (buff, ".");
  ptr = strtok (buff, ".");

  for (a = 0; a < varcnt; a++)
    {
      if (strcmp (vars[a].var_name, ptr) == 0 && vars[a].level == lvl)
	{
	  ptr = strtok (0, ".");

	  if (ptr == 0)
	    {
	      z =
		find_type (vars[a].var_type) +
		(atoi (vars[a].var_size) << 16);
	      *level = vars[a].level;
	      *type = z;
	      *arrsize = matoi (vars[a].var_arrsize);
	      if (arr)
		strcpy (arr, vars[a].var_arrsize);
	      *size = matoi (vars[a].var_size);
	      debug ("\n/* %s %s %s %s %d */\n",
		     vars[a].var_name,
		     vars[a].var_type,
		     vars[a].var_size, vars[a].var_arrsize, vars[a].level);
	      return z;
	    }

	  lvl++;

	}

    }
  return -1;
}

matoi (char *s)
{
  int a;
  if (s == 0)
    return 0;
  a = atoi (s);
  return a;
}

//char *

int
push_bind_rec (char *s, char bindtype)
{
  int a;
  long z;
  char buff[256];
  char bb[256];
  char bbb[256];
  char endoflist[256];
char save[256];
  char *ptr;
  int lvl = 0;

  debug ("In push_bind_rec : %s\n", s);

  strcpy(endoflist,"");
  if (strchr(s,'\n')) {
	int v1;
	int v2;
	char *ptr1;
	char *ptr2;

	char r1[256];
	char r2[256];
	char buff[256];

	
	strcpy(save,s);
	s=save;

  	ptr=strchr(save,'\n');

	*ptr=0;
	ptr++;
	strcpy(endoflist,ptr);
	debug("Thru splits to %s and %s",s,ptr);

	strcpy(r1,s);
	ptr1=strrchr(r1,'.');
	*ptr1=0;
	ptr1++;

	strcpy(r2,s);
	ptr2=strrchr(r2,'.');
	*ptr2=0;

	if (strcmp(r1,r2)!=0) {
		yyerror("Records for thru look different...");
	}

	v1=scan_variable(s);
	if (v2==-1) {
		yyerror("Variable not found (first entry in thru)");
	}
	v1=last_var_found;
	debug("v1=%d",v1);

	v2=scan_variable(ptr);
	if (v2==-1) {
		yyerror("Variable not found (second entry in thru)");
	}
	v2=last_var_found;
	debug("v2=%d",v2);
	
	for (a=v1;a<=v2;a++) {
		sprintf(buff,"%s.%s",r1,vars[a].var_name);
		      add_bind (bindtype, buff);
	}
	return;
  }

  if (s[0] == '.' && s[1] == 0)
    return -1;
  if (s[0] == 0)
    return -1;

  strcpy (buff, s);

  if (strchr(s,'.')==0) {
	strcat(buff,".*");
  }

  strcat (buff, ".");
  /*strip_bracket(buff); */
  strcpy (bb, "");
  scan_variable (s);
  if (last_var_found == -1)
    {
      yyerror ("Record or structure not defined");
    }


  ptr = strtok (buff, ".");

  for (a = last_var_found; a < varcnt; a++)
    {
      debug ("Check2 ptr=%p", ptr);
      if (ptr == 0)
	{
	  debug
	    ("Error processing record - missing item variable ?\nAssuming *");
	  ptr = "*";
	}
      if (
	  (strcmp (ptr, "*") == 0 || 1)
	   //|| strcmp (vars[a].var_name, with_strip_bracket (ptr)) == 0)
	  && vars[a].level == lvl)
	{
	  debug ("CHeck2.2");
	  if (ptr[0] != '*')
	    {
	      strcat (bb, ptr);
	      strcat (bb, ".");
	      ptr = strtok (0, ".");
	    }
	  else
	    {
	      while (strcmp (vars[a].var_type, "_ENDREC") != 0)
		{
		  z =
		    find_type (vars[a].var_type) +
		    (atoi (vars[a].var_size) << 16);
		  strcpy (bbb, bb);
		  strcat (bbb, vars[a].var_name);
		  if (bindtype != 'u')
		    {
		      add_bind (bindtype, bbb);
		    }
		  else
		    {
		      debug ("UPDATE USING .... check %s", vars[a].var_name);
		      if (!(is_pk (vars[a].var_name)))
			add_bind ('i', bbb);
		    }
		  a++;
		}
	      return 1;
	    }

	  debug ("CHeck3");
	  lvl++;

	}
      debug ("CHeck4");

    }
  return -1;
}

drop_counter ()
{
  count_counters--;
}

new_counter ()
{
  count_counters++;
  counters[count_counters] = 0;
}

get_counter_val ()
{
  debug ("/* get_counter_val =  %d counter number %d*/\n",
	 counters[count_counters], count_counters);
  return counters[count_counters];
}

inc_counter ()
{
  return ++counters[count_counters];
}

dec_counter ()
{
  return --counters[count_counters];
}

reset_counter ()
{
  counters[count_counters] = 0;
}

set_counter (int a)
{
  counters[count_counters] = a;
}
inc_counter_by (int a)
{
  counters[count_counters] += a;
  debug ("/* inc_by =  %d counter number %d*/\n",
	 counters[count_counters], count_counters);
}
dec_counter_by (int a)
{
  counters[count_counters] -= a;
}

print_bind_pop1 (char i)
{
  int a;
  a = 0;
  if (i == 'i')
    {
      if (scan_variable (obind[a].varname) != -1)
	printc ("pop_var2(&%s,%d,%d);\n", ibind[a].varname,
		(int) ibind[a].dtype & 0xffff, (int) ibind[a].dtype >> 16);
      else
	printc ("%s;\n", ibind[a].varname);
    }

  if (i == 'o')
    {
      if (scan_variable (obind[a].varname) != -1)
	printc ("pop_var2(&%s,%d,%d);\n", obind[a].varname,
		(int) obind[a].dtype & 0xffff, (int) obind[a].dtype >> 16);
      else
	printc ("%s;\n", obind[a].varname);
    }

}

start_arr_bind (char i, char *var)
{
  if (i == 'i')
    {
      ibindcnt = 0;
    }
  if (i == 'N')
    {
      nullbindcnt = 0;
    }
  if (i == 'o')
    {
      obindcnt = 0;
    }
  if (i == 'f'||i=='F')
    {
      fbindcnt = 0;
    }
  if (var != 0)
    add_arr_bind (i, var);
}

add_arr_bind (char i, char *nvar)
{
  long dtype;
  char var[256];
  strcpy (var, nvar);

  if (isrecvariable (var))
    {
      strcat (var, "[0].*");
    }
  else
    {
      strcat (var, "[0]");
    }

  dtype = scan_variable (var);

  debug ("/* add_arr_bind %c %s %x */\n", i, var, dtype);

  if (i == 'i')
    {
      if (dtype == -2)
	push_bind_rec (var, i);
      else
	{
	  strcpy (ibind[ibindcnt].varname, var);
	  ibind[ibindcnt].dtype = dtype;
	  ibindcnt++;
	}
      return ibindcnt;
    }

  if (i == 'N')
    {
      if (dtype == -2)
	push_bind_rec (var, i);
      else
	{
	  strcpy (nullbind[nullbindcnt].varname, var);
	  nullbind[nullbindcnt].dtype = dtype;
	  nullbindcnt++;
	}
      return nullbindcnt;
    }

  if (i == 'o')
    {
      if (dtype == -2)
	push_bind_rec (var, i);
      else
	{
	  strcpy (obind[obindcnt].varname, var);
	  obind[obindcnt].dtype = dtype;
	  obindcnt++;
	}
      return obindcnt;
    }
  if (i == 'f'||i=='F')
    {
      strcpy (fbind[fbindcnt].varname, var);
      fbind[fbindcnt].dtype = dtype;
      fbindcnt++;
      return fbindcnt;
    }

}

print_arr_bind (char i)
{
  int a;
  int dtype;
  debug ("/* %c */\n", i);
  //dump_vars ();
  if (i == 'i')
    {
      printc ("\n");
      printc ("struct BINDING ibind[]={\n");
      for (a = 0; a < ibindcnt; a++)
	{
	  if (a > 0)
	    printc (",\n");
	  printc ("{&%s,%d,%d}", ibind[a].varname,
		  (int) ibind[a].dtype & 0xffff, (int) ibind[a].dtype >> 16);
	}
      printc ("\n}; /* end of binding */\n");
      return a;
    }

  if (i == 'o')
    {
      printc ("\n");
      printc ("struct BINDING obind[]={\n");
      for (a = 0; a < obindcnt; a++)
	{
	  if (a > 0)
	    printc (",\n");
	  printc ("{&%s,%d,%d}", obind[a].varname,
		  (int) obind[a].dtype & 0xffff, (int) obind[a].dtype >> 16);
	}
      printc ("\n}; /* end of binding */\n");
      return a;
    }
}

push_construct (char *a, char *b)
{
  strcpy (constr_buff[constr_cnt].tab, a);
  strcpy (constr_buff[constr_cnt].col, b);
  constr_cnt++;
}

print_constr ()
{
  int a;
  printc
    ("struct s_constr_list {char *tabname;char *colname;} constr_flds[]={\n");
  for (a = 0; a < constr_cnt; a++)
    {
      if (a > 0)
	printc (",\n");
      printc ("{\"%s\",\"%s\"}", constr_buff[a].tab, constr_buff[a].col);
    }
  printc ("\n};");
  return a;
}

reset_constr ()
{
  constr_cnt = 0;
}

print_field_bind_constr ()
{
  char tabname[40];
  char colname[40];
  int a;
  for (a = 0; a < constr_cnt; a++)
    {
      if (a > 0)
	printc (",");
      if (constr_buff[a].tab[0] != 0)
	printc ("\"%s.%s\",1", constr_buff[a].tab, constr_buff[a].col);
      else
	printc ("\"%s\",1", constr_buff[a].col);
    }
  return a;
}

char *
convstrsql (char *s)
{
  static char buff[1024];
  int a;
  int b = 0;
  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] == '"')
	{
	  if (a == 0)
	    buff[b++] = '\'';
	  else
	    {
	      if (s[a - 1] != '\\')
		{
		  buff[b++] = '\'';
		}
	    }
	  continue;
	}
      if (s[a] == '\'')
	{
	  buff[b++] = '\\';
	  buff[b++] = '\'';
	  continue;
	}
      buff[b++] = s[a];

    }
  return buff;
}

#ifdef n0
int
convlower (char *s)
{
  int a;
  debug ("/* %s to ", s);
  for (a = 0; a < strlen (s); a++)
    {
      s[a] = tolower (s[a]);
    }
  debug ("%s */", s);
}
#endif

dump_gvars ()
{

  FILE *f;
  int a;
  char ii[64];
  strcpy (ii, outputfilename);
  strcat (ii, ".glb");
  f = mja_fopen (ii, "w");

  if (f == 0)
    {
      fprintf (stderr, "Couldnt open output file %s\n", ii);
      exit (0);
    }

  fprintf (f, "DATABASE=%s\n", get_hdrdbname ());

  for (a = 0; a < varcnt; a++)
    {
      fprintf (f, "%s %s %s %s %s %s %d\n",
	       vars[a].var_name,
	       vars[a].var_type,
	       vars[a].var_size,
	       vars[a].var_arrsize,
	       vars[a].tabname, vars[a].pklist, vars[a].level);

    }
  fclose (f);
}

read_glob (char *s)
{

  FILE *f;
  int a;
  char line[256];
  char ii[64];
  char dbname[64];
  char tname[128];
  char pklist[1024];
  strcpy (ii, s);
  strcat (ii, ".glb");
  f = mja_fopen (ii, "r");

  if (f == 0)
    {
      debug ("Trying to compile globals file");
      generate_globals_for (ii);
      f = mja_fopen (ii, "r");
    }

  if (f == 0)
    {
      fprintf (stderr, "Couldnt open globals file %s\n", ii);
      exit (7);
    }

  debug ("OPening %s\n", ii);

  fgets (line, 255, f);
  strcpy (dbname, "");
  sscanf (line, "DATABASE=%s", dbname);

  if (strlen (dbname) > 0)
    {
      set_hdrdbname (dbname);
      open_db (dbname);
    }

  debug ("DBNAME=%s from globals", dbname);
  while ( !feof (f))
    {

      fscanf (f, "%s %s %s %s %s %s %d\n",
	      vars[varcnt].var_name,
	      vars[varcnt].var_type,
	      vars[varcnt].var_size,
	      vars[varcnt].var_arrsize, tname, pklist, &vars[varcnt].level);


      vars[varcnt].tabname = strdup (tname);
      vars[varcnt].pklist = strdup (pklist);

      debug ("Read %s %s from globals file (%s %s)\n",
	     vars[varcnt].var_name,
	     vars[varcnt].var_type,
	     vars[varcnt].tabname, vars[varcnt].pklist);
      debug ("In full : %s %s %s %s %s %s %d\n",
	     vars[varcnt].var_name,
	     vars[varcnt].var_type,
	     vars[varcnt].var_size,
	     vars[varcnt].var_arrsize,
	     vars[varcnt].tabname, vars[varcnt].pklist, vars[varcnt].level);
      vars[varcnt].globflg='G';

  if (varcnt>=MAXVARS) { exitwith("Too many variables"); yyerror("Too many variables"); }
      varcnt++;
    }
  fclose (f);


#ifdef NOLONGERUSED
  read_glob_var = 1;
  print_variables (1);
  read_glob_var = 0;
#endif


  //set_mod_level (varcnt);
}

char *
upshift (char *a)
{
  int i;
  static char buff[256];
  strcpy (buff, a);
  for (i = 0; i < strlen (buff); i++)
    {
      buff[i] = toupper (buff[i]);
    }
  return buff;
}

char *
downshift (char *a)
{
  int i;
  static char buff[256];
  strcpy (buff, a);
  for (i = 0; i < strlen (buff); i++)
    {
      buff[i] = tolower (buff[i]);
    }
  return buff;
}

findex (char *str, char c)
{
  int a;
  for (a = 0; a < strlen (str); a++)
    {
      if (str[a] == c)
	return a;
    }
  return 0;
}

add_report_agg (char t, char *s1, char *s2, int a)
{
  if (use_group)
    {
      sreports[sreports_cnt].in_b = get_curr_block ();
      printc ("/*Set curr block to %d for expr %d*/\n", get_curr_block (), a);
    }
  else
    {
      sreports[sreports_cnt].in_b = 0;
    }
  if (strlen (s2) == 0)
    {
      strcpy (sreports[sreports_cnt].rep_cond, "push_int(1);");
    }
  else
    {
      strcpy (sreports[sreports_cnt].rep_cond, s2);
    }
  strcpy (sreports[sreports_cnt].rep_expr, s1);
  sreports[sreports_cnt].a = a;
  sreports[sreports_cnt].t = t;
  sreports_cnt++;

  if (t == 'C')
    {
      printh ("static long _g%d=0;\n", a);
      return 1;
    }

  if (t == 'P')
    {
      printh ("static long _g%d=0,_g%d=0;\n", a, a + 1);
      return 2;
    }

  if (t == 'S')
    {
	printh ("static double _g%d=0;\n",
						 a);
      return 1;
    }

  if (t == 'N' || t == 'X')
    {
      printh ("static double _g%d=0;\n", a);
      printh ("static int _g%dused=0;\n", a);
      return 1;
    }

  if (t == 'A')
    {
      printh ("static double _g%d=0;\n", a);
      printh ("static long   _g%d=0;\n", a + 1);
      return 2;
    }
  use_group = 0;
}

pr_report_agg ()
{
  int z;
  int a;
  int t;
  char s1[5024];
  char s2[5024];
  for (z = 0; z < sreports_cnt; z++)
    {
      strcpy (s2, sreports[z].rep_cond);
      strcpy (s1, sreports[z].rep_expr);
      a = sreports[z].a;
      t = sreports[z].t;

      if (t == 'C')
	{
	  printc ("%s if (pop_bool()) _g%d++;\n", s2, a);
	}

      if (t == 'P')
	{
	  printc ("_g%d++; %s if (pop_bool()) _g%d++; \n", a + 1, s2, a);
	}

      if (t == 'S')
	{
	  printc
	    ("%s if (pop_bool()) {double _res;%s _res=pop_double(); _g%d+=_res;}\n ",
	     s2, s1, a);
	}

      if (t == 'A')
	{
	  printc
	    ("%s if (pop_bool()) {double _res;%s _res=pop_double(); _g%d+=_res;_g%d++;}\n ",
	     s2, s1, a, a + 1);
	}

      if (t == 'N')
	{
	  printc
	    ("%s if (pop_bool()) {double _res;%s _res=pop_double(); if (_res<_g%d||_g%dused==0) {_g%d=_res;_g%dused=1;}}\n",
	     s2, s1, a, a, a, a);
	}
      if (t == 'X')
	{
	  printc
	    ("%s if (pop_bool()) {double _res;%s _res=pop_double(); if (_res>_g%d||_g%dused==0) {_g%d=_res;_g%dused=1;}}\n",
	     s2, s1, a, a, a, a);
	}

    }
}

set_curr_rep_name (char *s)
{
  strcpy (curr_rep_name, "acl_fglr_");
  strcat (curr_rep_name, s);
}

char *
get_curr_rep_name ()
{
  return curr_rep_name;
}

set_curr_block (int a)
{
  curr_rep_block = a;
}

get_curr_block ()
{
  return curr_rep_block;
}

set_ingroup ()
{
  use_group = 1;
}

pr_report_agg_clr ()
{
  int z;
  int a;
  int t;
  int in_b;
  char s1[1024];
  char s2[1024];
  for (z = 0; z < sreports_cnt; z++)
    {
      strcpy (s2, sreports[z].rep_cond);
      strcpy (s1, sreports[z].rep_expr);
      a = sreports[z].a;
      t = sreports[z].t;
      in_b = sreports[z].in_b;
      if (in_b > 0)
	{
	  printc ("if (nargs==-%d&&acl_ctrl==REPORT_AFTERGROUP) {\n", in_b);
	  printc ("/* t=%c */\n", t);
	  if (t == 'C' || t == 'N' || t == 'X'||t=='S')
	    {
	      printc ("_g%d=0;\n", a);
	    }

	  if (t == 'N' || t == 'X')
	    {
	      printc ("_g%dused=0;\n", a);
	    }

	  if (t == 'P' ||  t == 'A')
	    {
	      printc ("_g%d=0;_g%d=0;\n", a + 1, a);
	    }
	  printc ("}\n");
	}
    }
}

set_whento (char *p)
{
  debug ("whento = %p", p);
  strcpy (when_to_tmp, p);
}

set_whenever (int c, char *p)
{
  int code;
  int oldcode;
  oldcode = c & 15;
  debug("MJA Set_whenever : %d %s",c,p);
  c = c >> 4;
  c = c << 4;
  code = -1;
  switch (c)
    {
    case WHEN_ERROR:
      code = A_WHEN_ERROR;
      break;

    case WHEN_ANYERROR:
      code = A_WHEN_ERROR;
      break;

// Can someone explain the difference...
    //case WHEN_ANYERROR:
      //code = A_WHEN_ANYERROR;
      //break;

    case WHEN_SQLERROR:
      code = A_WHEN_SQLERROR;
      break;
    case WHEN_WARNING:
      code = A_WHEN_WARNING;
      break;
    case WHEN_SQLWARNING:
      code = A_WHEN_SQLWARNING;
      break;
    case WHEN_NOTFOUND:
      code = A_WHEN_NOTFOUND;
      break;
    case WHEN_SUCCESS:
      code = A_WHEN_SUCCESS;
      break;
    case WHEN_SQLSUCCESS:
      code = A_WHEN_SQLSUCCESS;
      break;
    }

  if (code == -1)
    {
      printf ("Code=%d (%x) to %p\n", c, c, p);
      yyerror ("Internal error setting whenever error...");
      exit (0);
    }

  if (p)
    {
      strcpy (when_to[code], p);
    }
  else
    {
      strcpy (when_to[code], when_to_tmp);
    }
  when_code[code] = oldcode;
  printc ("set_status(0);\n");
}

prchkerr (int l, char *f)
{
  int a;
/* 0 = continue */
/* 1 = stop */
/* 2 = call */
/* 3 = goto */

debug("MJA prchkerr %d %s",l,f);

  printc ("if (sqlca.sqlcode !=0 || status !=0 || %d) {\n",
	  when_code[A_WHEN_SUCCESS] == WHEN_CALL
	  || when_code[A_WHEN_SQLSUCCESS] == WHEN_CALL);

  /*printc("debug(\"status=%%d sqlca.sqlcode=%%d\",status,sqlca.sqlcode);\n"); */

  printcomment ("/* NOTFOUND */");
  a =
    pr_when_do ("   if (sqlca.sqlcode==100)", when_code[A_WHEN_NOTFOUND], l,
		f, when_to[A_WHEN_NOTFOUND]);

  printcomment ("/* SQLERROR */");
  a =
    pr_when_do ("   if (sqlca.sqlcode<0&&status==sqlca.sqlcode)",
		when_code[A_WHEN_SQLERROR], l, f, when_to[A_WHEN_SQLERROR]);

  printcomment ("/* ANYERROR */");
  a =
    pr_when_do ("   if (status<0||sqlca.sqlcode<0)",
		when_code[A_WHEN_ANYERROR], l, f, when_to[A_WHEN_ANYERROR]);

  printcomment ("/* ERROR */");
  a =
    pr_when_do ("   if (status<0)", when_code[A_WHEN_ERROR], l, f,
		when_to[A_WHEN_ERROR]);
  printcomment ("/* SQLWARNING */");
  a =
    pr_when_do ("   if (sqlca.sqlcode==0&&sqlca.sqlawarn[0]=='W')",
		when_code[A_WHEN_SQLWARNING], l, f,
		when_to[A_WHEN_SQLWARNING]);

  printcomment ("/* WARNING */");
  a =
    pr_when_do
    ("   if (sqlca.sqlcode==0&&(sqlca.sqlawarn[0]=='w'||sqlca.sqlawarn[0]=='W'))",
     when_code[A_WHEN_WARNING], l, f, when_to[A_WHEN_WARNING]);

  printcomment ("/* SQLSUCCESS */");
  a =
    pr_when_do ("   if (sqlca.sqlcode==0&&status==0)",
		when_code[A_WHEN_SQLSUCCESS], l, f,
		when_to[A_WHEN_SQLSUCCESS]);

  printcomment ("/* SUCCESS */");
  a =
    pr_when_do ("   if (sqlca.sqlcode==0&&status==0)",
		when_code[A_WHEN_SUCCESS], l, f, when_to[A_WHEN_SUCCESS]);

  printc ("}\n");
}

pcopy (char *s)
{
  if (ferr)
    fprintf (ferr, "%s\n", s);
}

int
add_constant (char t, char *ptr, char *name)
{
  char scope = 'm';
  int x;
  char buff[256];
  x = 0;
  //x = rwlookup (name);
  if (x != 0)
    {
      adderr ("'%s' is a reserved word and cannot be used as a constant\n",
	      name, "");
      yyerror ("Constant Declaration Error");
    }
  debug ("Add constant\n");
  x = check_for_constant (name, buff);
  if (x)
    {
/* Note : this shouldnt actually happen! 
   all constants should be replaced by this point anyway
   eg
   define constant a="Bibble"
   define constant a="Wibble"
   will parse as
   define constant a="Bibble"
   define constant "Bibble"="Wibble"
 */
      adderr ("Constant %s has already been defined (as '%s')", name, buff);
      yyerror ("Duplicate Constant");
    }

  if (isin_command ("FUNC") || isin_command ("REPORT"))
    {
      scope = 'f';
    }
  if (isin_command ("GLOBALS"))
    {
      scope = 'g';
    }
  const_arr[const_cnt].type = t;
  strcpy (const_arr[const_cnt].name, name);
  const_arr[const_cnt].type = t;
  const_arr[const_cnt].ptr = strdup (ptr);
  const_cnt++;
}

clr_function_constants ()
{
  int a;
  int lcnt = 0;
  debug ("Clr constants\n");
  for (a = 0; a <= const_cnt; a++)
    {
      if (const_arr[const_cnt].scope == 'f')
	{
	  const_arr[const_cnt].name[0] = 0;
	}
      else
	lcnt = a;

    }
  const_cnt = lcnt + 1;

}

check_for_constant (char *name, char *buff)
{
  int x;

  for (x = 0; x < const_cnt; x++)
    {
      if (aubit_strcasecmp (name, const_arr[x].name) == 0)
	{
	  strcpy (buff, const_arr[x].ptr);
	  switch (const_arr[x].type)
	    {
	    case 'c':
	      return 1;
	    case 'f':
	      return 2;
	    case 'i':
	      return 3;
	    }

	}
    }
  return 0;
}

pr_when_do (char *when_str, int when_code, int l, char *f, char *when_to)
{

  if (when_code & 15 == WHEN_CONTINUE)
    return 0;

  if (when_code & 15 == WHEN_NOTSET)
    return 0;

  if (when_code == WHEN_STOP)
    {
      printc ("%s chk_err(%d,_module_name);\n", when_str, l, f);
      printcomment ("/* WHENSTOP */");
    }
  if (when_code == WHEN_CALL)
    {
      printc ("%s aclfgl_%s(0);\n", when_str, when_to);
      printcomment ("/* WHENCALL */");
    }

  if (when_code == WHEN_GOTO)
    {
      printc ("%s goto %s;\n", when_str, when_to);
      printcomment ("/* WHENGOTO */");
    }
  return 1;
}

npush_menu ()
{
  max_menu_no++;
  cmenu++;
  menu_nos[cmenu] = max_menu_no;
  debug ("Menu no %d", max_menu_no);
  return max_menu_no;
}

pop_menu ()
{
  cmenu--;
  if (cmenu >= 0)
    {
      menu_cnt = menu_nos[cmenu];
      debug ("Reset Menu no %d", menu_cnt);
    }
  else
    {
      debug ("Nothing to reset to...");
    }
}

setrecord (char *s, char *t, char *c)
{
  return 0;
}

swapstring (char *d, char *s)
{
  int b = 0;
  int a;
  int flg;
  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] == '\'')
	{
	  flg = 1;
	  if (a > 0)
	    {
	      if (s[a - 1] == '\\')
		{
		  flg = 0;
		}
	    }
	  if (flg)
	    d[b++] = '"';
	  else
	    d[b++] = s[a];
	}
      else if (s[a] == '"')
	{
	  d[b++] = '\\';
	  d[b++] = '"';
	}
      else
	d[b++] = s[a];
    }
  debug ("Converted : %s to %s", s, d);
}

num_arr_elem (char *s)
{
  int a;
  int c = 0;
  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == '[')
	c++;
    }
  return c;
}

char *
change_arr_elem (char *s)
{
  static char buff[1024];
  int a;
  char buff2[2];
  buff2[1] = 0;
  buff[0] = 0;
  strcpy (buff, "(");
  debug ("change_arr_elem: %s", s);
  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == ',')
	{
	  strcat (buff, ")-1][(");
	}
      else
	{
	  buff2[0] = s[a];
	  strcat (buff, buff2);
	}
    }
  strcat (buff, ")-1");
  debug ("Generated... %s", buff);
  return buff;
}

trim_spaces (char *s)
{
  int l;
  for (l = strlen (s) - 1; l >= 0; l--)
    {
      if (s[l] == ' ')
	s[l] = 0;
      else
	break;
    }
}

yywrap ()
{
  return 1;
}

system_var (char *s)
{
  if (aubit_strcasecmp (s, "today") == 0)
    return 1;
  if (aubit_strcasecmp (s, "time") == 0)
    return 1;
  if (aubit_strcasecmp (s, "user") == 0)
    return 1;
  if (aubit_strcasecmp (s, "date") == 0)
    return 1;
  return 0;
}

inc_report_cnt ()
{
  sreports_cnt = 0;
  report_cnt++;
  report_stack_cnt = 0;
}

char *
trans_quote (char *s)
{
  static char buff[1024];
  int c;
  int a;
  c = 0;
  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == '"')
	{
	  buff[c++] = '\\';
	}
      buff[c++] = s[a];
      buff[c] = 0;
    }
  return buff;
}

#ifdef NODEF
extern struct s_kw kwords[];

extern struct s_kw kwords[];
FILE *yyin = 0;
char *read_word (FILE * f, int *t);
char *read_word2 (FILE * f, int *t);
int ccat (char *s, char a);
char *mk_word (int c);
#define stricmp strcasecmp

#define TYPE_EOF  -1
#define TYPE_USTRING  -2	/* unterminated string */
#define TYPE_NUM 3

#define DBG			//

yylex ()
{
  int a;
  char buff[1024];
  word_cnt = 0;
  printf ("-----");
  debug ("YYLEX called");
  if (yyin == 0)
    {
      printf ("No input...\n");
      exit (0);
    }

  a = chk_word (yyin, buff);
  debug ("chk_word returns %d\n", a);
  if (a == 2)
    {
      to_lower_str (buff);
    }

  set_str (buff);

  debug ("%04d %d (%4d) %s\n", yylineno, ccnt, a, buff);
  return a;
}

char *
read_word (FILE * f, int *t)
{
  char *ptr;
  ptr = read_word2 (f, t);
  strcpy (xwords[word_cnt], ptr);
  word_cnt++;
  return ptr;
}

char *
read_word2 (FILE * f, int *t)
{
  static char word[1024] = "";
  int escp = 0;
  int instrs = 0;
  int instrd = 0;
  int a;
  strcpy (word, "");
  *t = NAMED;
  while (1)
    {
      a = fgetc (f);

      if (feof (f))
	{
	  *t = TYPE_EOF;
	  return word;
	}

      if (xccode)
	{
	  while (1)
	    {
	      if (feof (f))
		break;
	      if (a == '\n' || a == '\r')
		break;
	      ccat (word, a);
	      a = fgetc (f);
	    }
	  printf ("CCODE > %s\n", word);
	  inc_yylineno (f);
	  *t = CLINE;
	  return word;
	}
      //DBG printf("Read %c\n",a);

      if (a == '-' && instrs == 0 && instrd == 0 && xccode == 0)
	{
	  int z;
	  z = fgetc (f);
	  ungetc (z, f);
	  if (z == '-')
	    {
	      while (1)
		{
		  a = fgetc (f);
		  if (feof (f))
		    break;
		  if (a == '\n' || a == '\r')
		    break;
		  ccat (word, a);
		}
	      inc_yylineno (f);
	      *t = COMMENT;
	      return word;
	    }
	}

      if (a == '#' && instrs == 0 && instrd == 0 && xccode == 0)
	{
	  while (1)
	    {
	      a = fgetc (f);
	      if (feof (f))
		break;
	      if (a == '\n' || a == '\r')
		break;
	      ccat (word, a);
	    }
	  inc_yylineno (f);
	  *t = COMMENT;
	  return word;

	}

      if (a == '{' && instrs == 0 && instrd == 0 && xccode == 0)
	{
	  while (1)
	    {
	      a = fgetc (f);
	      if (feof (f))
		break;
	      if (a == '}')
		break;
	      ccat (word, a);
	    }
	  *t = COMMENT;
	  return word;
	}

      if (a == '\n' || a == '\r')
	{
	  inc_yylineno (f);
	  if (instrs || instrd)
	    {
	      *t = TYPE_USTRING;
	    }
	  if (strlen (word) > 0)
	    return word;
	  else
	    continue;
	}

    if (instrs == 0 && instrd == 0
	  && (a == ' ' || a == '	'))
	{
	  if (strlen (word) > 0)
	    return word;
	  else
	    continue;
	}

      if (instrs == 0 && instrd == 0 && (ispunct (a)) && a != '"' && a != '\''
	  && a != '_')
	{
	  if (strlen (word) > 0)
	    {
	      if (isnum (word) && a == '.');
	      else
		{
		  ungetc (a, f);
		  return word;
		}
	    }
	  else
	    {
	      ccat (word, a);
	      return word;
	    }
	}

      if (a == '\\' && !escp)
	{
	  ccat (word, a);
	  if (escp == 0)
	    {
	      escp = 1;
	      continue;
	    }
	  else
	    {
	      escp == 0;
	    }
	}

      if (a == '"' && !escp && instrs == 0)
	{
	  if (instrd == 1)
	    {
	      ccat (word, '"');
	      *t = CHAR_VALUE;
	      return word;
	    }
	  ccat (word, '"');
	  instrd = 1;
	  continue;
	}

      if (a == '\'' && !escp && instrd == 0)
	{
	  if (instrs == 1)
	    {
	      ccat (word, '"');
	      *t = CHAR_VALUE;
	      return word;
	    }
	  ccat (word, '"');
	  instrs = 1;
	  continue;
	}
      ccat (word, a);
      escp = 0;
    }

}

ccat (char *s, char a)
{
  char buff[2];
  buff[0] = a;
  buff[1] = 0;
  strcat (s, buff);
}

chk_word (FILE * f, char *str)
{
  long a;
  int cnt;
  char *p;
  int t;
  int w;
  int rt;
  char buff[256];
  cnt = 0;
  rt = yylineno;
  p = read_word (f, &t);
  w = word_cnt;

  if (strcmp (p, "code") == 0 && xccode == 0)
    {
      xccode = 1;
      return CSTART;
    }

  if (strcmp (p, "endcode") == 0 && xccode)
    {
      xccode = 0;
      return CEND;
    }

  if (xccode)
    {
      strcpy (str, p);
      return CLINE;
    }

  if (t == COMMENT)
    {
      strcpy (str, p);
      return chk_word (f, str);
      /* dont return comments */
    }
  a = ftell (f);
  strcpy (buff, p);

  if (t == TYPE_EOF)
    {
      strcpy (str, "");
      return -1;
    }

  debug ("Got %s\n", p);
//printf("Read word %s\n",p);

  while (kwords[cnt].id > 0)
    {
      strcpy (p, buff);
      debug ("%s %s\n", p, kwords[cnt].vals[0]);
      if (kwords[cnt].mode >= 1)
	{
	  if (words (cnt, 0, f, p))
	    {
	      strcpy (str, mk_word (cnt));
	      print_words ();
	      return kwords[cnt].id;
	    }
	}
      word_cnt = w;
      yylineno = rt;
      fseek (f, a, SEEK_SET);
      cnt++;
    }
  strcpy (str, p);
  a = isnum (str);
  if (a == 1)
    t = INT_VALUE;
  if (a == 2)
    t = NUMBER_VALUE;
  print_words ();
  return t;
}

words (int cnt, int pos, FILE * f, char *p)
{
  int f_pos;
  int z;
  int t;
  char buff[132];
  int states = -1;
  strcpy (buff, kwords[cnt].vals[pos]);
  if (buff[0] == '*' && strlen (buff) > 1)
    {
      strcpy (buff, &kwords[cnt].vals[pos][1]);
      states = 1;
    }

  if (stricmp (buff, "<ident>") == 0)
    {
      //printf ("check %s\n", p);
      if (isident (p) == 0)
	return 0;
    }
  else
    {
      if (stricmp (p, buff) != 0)
	{
	  return 0;
	}
    }
  if (states != -1)
    start_state (buff, states);

  if (kwords[cnt].vals[pos + 1] == 0)
    {
      return 1;
    }
  p = read_word (f, &t);

  z = words (cnt, pos + 1, f, p);

  if (z == 0)
    {
      //fseek(f,f_pos,SEEK_SET);
      return 0;
    }
}

isident (char *p)
{
  int a;
  for (a = 0; a < strlen (p); a++)
    {
      if (isalnum (p[a]) || p[a] == '_')
	continue;
      return 0;
    }
  return 1;
}

char *
mk_word (int c)
{
  static char buff[256];
  int a;
  strcpy (buff, "");
  for (a = 0; kwords[c].vals[a]; a++)
    {
      if (a > 0)
	strcat (buff, " ");

      if (strcmp (kwords[c].vals[a], "<ident>") != 0)
	{
	  strcat (buff, kwords[c].vals[a]);
	}
      else
	{
	  strcat (buff, xwords[a]);
	}
    }
  return buff;
}

to_lower_str (char *s)
{
  int a;
  for (a = 0; a < strlen (s); a++)
    {
      s[a] = tolower (s[a]);
    }
}

isnum (char *s)
{
  int a;
  int dp = 0;
  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == '.' && dp == 0)
	{
	  dp++;
	  continue;
	}
      if (s[a] >= '0' && s[a] <= '9')
	continue;
      return 0;
    }
  if (strchr (s, '.'))
    return 2;
  return 1;
}

#ifdef NOLONGERHERE
turn_state (int kw, int v)
{
  int a;
//printf("State changes %d to %d\n",kw,v);
for (a = 0; kwords[a].id > 0;
       a++)
    {
      if (kwords[a].id == kw)
	{
	  if (v)
	    kwords[a].mode++;
	  else
	    kwords[a].mode--;
	  return;
	}
    }
}
#endif

inc_yylineno (FILE * f)
{
  yylineno++;
  fpos = ftell (f);
}

print_words ()
{
  int a;
  return;
  for (a = 0; a < word_cnt; a++)
    {
      printf ("<%s>", xwords[a]);
    }
  printf ("\n");
}
#endif

char *
ignull (char *ptr)
{
  static char *empty = "";
  if (ptr)
    return ptr;
  else
    return empty;
}

last_var_is_linked (char *tabname, char *pklist)
{
  strcpy (pklist, "");
  strcpy (tabname, "");
  if (last_var_found >= 0)
    {
      debug ("last var=%d\n", last_var_found);
      debug ("....%s %s %s\n", vars[last_var_found].var_name,
	     vars[last_var_found].tabname, vars[last_var_found].pklist);

      strcpy (tabname, vars[last_var_found].tabname);
      strcpy (pklist, vars[last_var_found].pklist);
    }
  if (strcmp (tabname, "") == 0)
    return 0;
  else
    return 1;
}

/* 
split a string into peices, 
	if a=0 return the number of pieces
	if a=1 then return the first into buffetc...
*/
int
linked_split (char *s, int a, char *buff)
{
  char *p;
  int z;
  int cnt;
  char buffer[2000];
  strcpy (buffer, s);
  strcat (buffer, ",");

  cnt = 0;
  debug ("linked_split %s %d %p", s, a, buff);
  if (a == 0)
    {
      for (z = 0; z < strlen (buffer); z++)
	{
	  if (buffer[z] == ',')
	    {
	      cnt++;
	    }
	}
      return cnt;
    }
  strcpy (buff, "");
  p = buffer;
  cnt = 0;
  if (a > 0)
    {
      for (z = 0; z < strlen (buffer); z++)
	{
	  if (buffer[z] == ',')
	    {
	      cnt++;
	      if (cnt == a)
		{
		  buffer[z] = 0;
		  strcpy (buff, p);
		  debug ("Linked found:%s", p);
		  return 1;
		}
	      p = &buffer[z + 1];
	    }
	}
    }
  return 0;
}

set_pklist (char *s)
{
  debug ("pklist set to %s\n", s);
  strcpy (pklist, s);
  strcpy (upd_using_notpk, "");
  upd_using_notpk_cnt = 0;
}

is_pk (char *s)
{
  int a;
  int cnt;
  char buff[256];
  debug ("Checking if %s is a pk in %s", s, pklist);
  a = linked_split (pklist, 0, 0);
  for (cnt = 1; cnt <= a; cnt++)
    {
      linked_split (pklist, cnt, buff);
      if (strcasecmp (s, buff) == 0)
	{
	  debug ("Yes");
	  return 1;
	}
    }
  if (strlen (upd_using_notpk) > 0)
    strcat (upd_using_notpk, ",");
  strcat (upd_using_notpk, s);
  upd_using_notpk_cnt++;
  debug ("No");
  return 0;
}

char *
get_upd_using_notpk ()
{
  debug ("get_upd_using_notpk");
  debug ("Returning %s", upd_using_notpk);
  return upd_using_notpk;
}

char *
get_upd_using_queries ()
{
  static char buff[2000];
  int a;
  debug ("get_upd_using_???");
  strcpy (buff, "");

  for (a = 0; a < upd_using_notpk_cnt; a++)
    {
      if (strlen (buff) > 0)
	strcat (buff, ",");
      strcat (buff, "?");
    }
  debug ("Returning %s", buff);
  return buff;

}

char *
ispdf ()
{
  if (rep_type == REP_TYPE_NORMAL)
    return "";
  else
    return "pdf_";
}

int
iscontinuecmd (char *s)
{

  if (strcmp (s, "FOR") == 0)
    return 1;
  //if (strcmp(s,"FOREACH")==0) return 1;
  if (strcmp (s, "WHILE") == 0)
    return 1;
  if (strcmp (s, "CASE") == 0)
    return 1;
  //if (strcmp(s,"CONSTRUCT")==0) return 1;
  //if (strcmp(s,"DISPLAY")==0) return 1;
  //if (strcmp(s,"PROMPT")==0) return 1;

  return 0;
}

generate_globals_for (char *s)
{
  char buff[1024];
  char dirname[1024];
  char fname[1024];
  char *ptr;
  char nocfile[256];
  strcpy (buff, s);

  if (strchr (buff, '/'))
    {
      strcpy (dirname, buff);
      ptr = strrchr (dirname, '/');
      *ptr = 0;
      ptr++;
      strcpy (fname, ptr);
    }
  else
    {
      strcpy (dirname, ".");
      strcpy (fname, buff);
    }

  strcpy (nocfile, acl_getenv ("NOCFILE"));
  setenv ("NOCFILE", "Yes", 1);
  ptr = strchr (fname, '.');
  *ptr = 0;
  debug ("Trying to compile globals file %s\n", fname);
  sprintf (buff, "cd %s; 4glc -G %s", dirname, fname);
  system (buff);
  setenv ("NOCFILE", nocfile, 1);

}






int
print_push_rec_old_delete_me (char *s, char *b)
{
  int a;
  long z;
  char buff[256];
  int cnt=0;
  char bb[256];
  char buffer[30000] = "";
  char buffer2[30000];
  char nbuff[30000];
  char *ptr;
  int lvf;
  int lvl = 0;
  debug ("/* pushing record  '%s' '%s' */\n", s, b);
  if (s[0] == '.' && s[1] == 0)
    return -1;
  if (s[0] == 0)
    return -1;

  scan_variable (s);

  if (last_var_found == -1)
    {
      yyerror ("Record or structure not defined");
    }
  lvf = last_var_found;

  debug ("last_var_found=%d", lvf);

  strcpy (buff, s);
  strcat (buff, ".");
  strcpy (bb, "");
  ptr = strtok (buff, ".");


  for (a = lvf; a < varcnt; a++)
    {
  	debug ("a=%d ptr=%s vars[a].var_name=%s", a,ptr,vars[a].var_name);
      if (ptr == 0)
	{
	  debug ("ptr=%s buff=%s", ptr, buff);
	  yyerror ("Record structure is too complex for use here");
	}
      debug ("Check %s %s\n",vars[a].var_name,ptr);

      if (
	  (strcmp (ptr, "*") == 0
	   || strcmp (vars[a].var_name, with_strip_bracket (ptr)) == 0)
	  && vars[a].level == lvl)
	{
	  debug (".* bit");
	  if (ptr[0] != '*')
	    {
	      debug ("not .*");
	      strcat (bb, ptr);
	      strcat (bb, ".");
	      ptr = strtok (0, ".");
	    }
	  else
	    {
	      debug (".*");
	      cnt = 0;
	      while (strcmp (vars[a].var_type, "_ENDREC") != 0)
		{
  		debug("Print var at %d \n",a);
		  z =
		    find_type (vars[a].var_type) +
		    (atoi (vars[a].var_size) << 16);
		debug("z=%d\n",z);
		  if (z != -2)
		    {
		      strcpy (buffer2, buffer);
		      sprintf (buffer, "%s push_variable(&%s%s,0x%x);\n",
			       buffer2, bb, vars[a].var_name, z);
		      a++;
		      cnt++;
		    }
		  else
		    {
		      int c;
		      char nvar[256];
		      strcpy (buffer2, buffer);
		      sprintf (nvar, "%s%s.*", bb, vars[a].var_name);
		      debug("recursing with %s\n",nvar);
		      c=print_push_rec (nvar, nbuff);
		      sprintf (buffer, "%s %s\n", buffer2, nbuff);
			debug ("print_push_rec returns %d for %s\n",print_push_rec,nvar);
		      cnt += c;
		      a += c;
		      a++;
		    }
		}
	      debug ("/* Returning %d */", cnt);
	      strcpy (b, buffer);
	      return cnt;
	    }

	  lvl++;

	}

    }
  return -1;
}



int
print_push_rec (char *s, char *b)
{
  int a;
  long z;
  char buff[256];
  int cnt=0;
  char bb[256];
  char buffer[40000] = "";
  char buffer2[40000];
  char nbuff[40000];
  char *ptr;
  int lvf;
  int lvl = 0;
  char endoflist[256];
  char save[256];

debug("print_push_rec");
  strcpy(endoflist,"");

  if (strchr(s,'\n')) {
	debug("Have a thru");
		strcpy(save,s);
		s=save;
		ptr=strchr(save,'\n');
		*ptr=0;
		ptr++;
		strcpy(endoflist,ptr);
	debug("Splits to %s and %s",s,endoflist);
		
  }
  strcpy(bb,s);

  bb[strlen(bb)-1]=0;

  debug ("pushing record  '%s' '%s'\n", s, b);
  if (s[0] == '.' && s[1] == 0)
    return -1;
  if (s[0] == 0)
    return -1;

  scan_variable (s);

  if (last_var_found == -1)
    {
      yyerror ("Record or structure not defined");
    }

  lvf = last_var_found+1;

  debug ("last_var_found=%d -> %s", lvf,vars[lvf].var_name);


  for (a = lvf; a < varcnt; a++)
    {
	      if (strcmp (vars[a].var_type, "_ENDREC") == 0) {
			debug("Spotted ENDREC @ %d\n",a);
	      		strcpy (b, buffer);
			return cnt;
		}

		debug("Testing variable @%d\n",a);
	       z =
		    find_type (vars[a].var_type) +
		    (atoi (vars[a].var_size) << 16);


		  if (z != -2)
		    {
		      strcpy (buffer2, buffer);
		      sprintf (buffer, "%s   push_variable(&%s%s,0x%x);\n",
		       buffer2, bb, vars[a].var_name, z);
		      cnt++;
		    }
		  else
		    {
		      int c;
		      char nvar[256];
		      strcpy (buffer2, buffer);
		      sprintf (nvar, "%s%s.*", bb, vars[a].var_name);

		      debug("recursing with %s\n",nvar);
		      c=print_push_rec (nvar, nbuff);
		      sprintf (buffer, "%s%s\n", buffer2, nbuff);
		      cnt += c;
		      a += c;
		      a++;
		}

	      if (strcmp (vars[a].var_name, endoflist) == 0) {
		debug("Done the last one...");
		break;
		}
    }
  return -1;
}

expand_obind() {
expand_bind(&obind,'o',obindcnt) ;
}

// *************************************************************************
//
// When you've got a function definition which includes a record
// You don't know when adding to the binding the structures involved
// This copies the original binding and reapplies them.
// This should be called after the structure is known - ie. just before you 
// want to print it !
//
// *************************************************************************
expand_bind(struct binding *bind,int btype,int cnt)  {
struct binding save_bind[NUMBINDINGS];
char buff[256];
int a;
for (a=0;a<cnt;a++) {
	strcpy(save_bind[a].varname,bind[a].varname);
	save_bind[a].dtype=bind[a].dtype;
}

start_bind(btype,0);

for (a=0;a<cnt;a++) {
 	strcpy(buff,save_bind[a].varname);
	if (scan_variable(buff)==-2) {
		strcat(buff,".*");
	}
		
	add_bind(btype,buff);
}

}


char *
get_var_name(int z) {
	return vars[z].var_name;
}
	


chk_init_var(char *s) {
char buff[1024];
char *ptr;

if (strcmp(s,"")==0) return ;

strcpy(buff,s);
ptr=strchr(buff,'.');
if (strchr(buff,'[')) { /* This need fixing */
// This should check for arrays within arrays...
// but this doesn't
	return;
}

if (ptr==0) {
	if (isarrvariable(s)) {
		printf("Warning: Only initializing first element in array %s\n",s);
		strcat(s,"[0]");
		return;
	} else {
		return;
	}
} 


*ptr=0;
if (isarrvariable (buff)) {
			char buff[1024];
			char *ptr;
		printf("Warning: Only initializing first element in array %s\n",s);
			strcpy(buff,s);
			ptr=strchr(s,'.');
			*ptr=0;
			strcat(s,"[0].");

			ptr=strchr(buff,'.');
			debug("ptr=%s\n",ptr);
			ptr++;
			strcat(s,ptr);
		}

}

void *new_expr(char *value) {
	struct expr_str *ptr;
	debug("new_expr");
	ptr=malloc(sizeof(struct expr_str));
	ptr->next=0;
	ptr->expr=strdup(value);
	debug("newexpr : %s -> %p\n",value,ptr);
	return ptr;
}

void *append_expr(struct expr_str *orig_ptr,char *value) {
struct expr_str *ptr;
struct expr_str *start;
	start=orig_ptr;

	debug("MJA append_expr %p (%s)",orig_ptr,value);

	ptr=new_expr(value);
	if (orig_ptr->next!=0) {
		while (orig_ptr->next!=0) orig_ptr=orig_ptr->next;
	}
	orig_ptr->next=ptr;
	debug("Appended expr");
	return start;
}

void *append_expr_expr(struct expr_str *orig_ptr,struct expr_str *second_ptr) {
struct expr_str *ptr;
struct expr_str *start;
	debug("MJA append_expr_expr %p %p",orig_ptr,second_ptr);
	start=orig_ptr;
	if (orig_ptr->next!=0) {
		while (orig_ptr->next!=0) orig_ptr=orig_ptr->next;
	}
	orig_ptr->next=second_ptr;
	return start;
}

print_expr(struct expr_str *ptr) {
void *optr;
	debug("Print expr... %p",ptr);
	while (ptr) {
		debug("Printing %p",ptr->expr);
		printc("%s\n",ptr->expr);
		free(ptr->expr);
		optr=ptr;
		debug("going to %p",ptr->next);
		ptr=ptr->next;
		free(optr);
	}
}

length_expr(struct expr_str *ptr) {
void *optr;
int c=0;
	debug("Print expr... %p",ptr);
	while (ptr) {
		c++;
		ptr=ptr->next;
	}
return c;
}
