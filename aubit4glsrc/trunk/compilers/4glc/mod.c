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
# $Id: mod.c,v 1.191 2004-12-06 10:34:45 mikeaubury Exp $
#
*/

/**
 * @file
 * It looks like functions to help the parsing of a module (a x4gl one).
 * For that the name mod.c
 *
 * @todo Doxygen A4GL_comments in all functions
 * @todo static in modular variables
 * @todo const in read only strings
 * @todo -Wmissig-prototypes
 * @todo -Wstrict-prototypes
 * @todo -Wall
 * @todo -pedantic
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_4glc_int.h"
#include "variables.h"
#include <ctype.h>
/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define USE_PRINTCOMMENT
#define GEN_STACKS 		10
#define MAXVARS 		2000
#define EMPTY 			"----"
//#define MAXMENU 		50
//#define MAXMENUOPTS 	50

#define UPDCOL 0
#define UPDVAL 1
#define UPDVAL2 4
#define a0_width         (float) 2380.0
#define a0_height        (float) 3368.0
#define a1_width         (float) 1684.0
#define a1_height        (float) 2380.0
#define a2_width         (float) 1190.0
#define a2_height        (float) 1684.0
#define a3_width         (float) 842.0
#define a3_height        (float) 1190.0
#define a4_width         (float) 595.0
#define a4_height        (float) 842.0
#define a5_width         (float) 421.0
#define a5_height        (float) 595.0
#define a6_width         (float) 297.0
#define a6_height        (float) 421.0
#define b5_width         (float) 501.0
#define b5_height        (float) 709.0
#define letter_width     (float) 612.0
#define letter_height    (float) 792.0
#define legal_width      (float) 612.0
#define legal_height     (float) 1008.0
#define ledger_width     (float) 1224.0
#define ledger_height    (float) 792.0
#define p11x17_width     (float) 792.0
#define p11x17_height    (float) 1224.0




int A4GL_get_nevents(void) ;
void A4GL_get_event(int n,int *i,char **s) ;
//static void set_whento (char *p);
//void set_whento_store(char *p);
//void set_whenever_store (int c, char *p) ;
//void set_whenever_from_store(void) ;
//void A4GL_lex_printh(char* fmt,... );

int A4GL_findex (char *str, char c);
/*void push_validate (char *t2);*/
int A4GL_get_attr_from_string (char *s);
//char get_curr_report_stack_whytype_1 (void);
char *get_curr_report_stack_why (void);
char find_variable_scope (char *s_in);
char *A4GL_get_important_from_clobber(char *s) ;
char *A4GL_get_clobber_from_orig(char *s);
//char *A4GLSQLCV_check_sql(char *s) ;
int get_rep_no_orderby(void) ;
int get_validate_list_cnt(void) ;
//char *A4GL_decode_packtype(char *s) ;

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/*
#ifdef LEXER
char xwords[256][256];
int word_cnt = 0;
int xccode = 0;
long fpos;
#endif
*/

void dump_updvals (void);
char *pop_gen (int a);
/*int gen_cnt (int a);*/
void copy_gen (int a, int b);
extern int menu_cnt;			/** The count of menus found */
extern int yylineno;			/** The source file line number */
extern char *infilename;    /** The input (4gl file name */
extern int in_define;

static int db_used = 0;		 /** Flag that indicate that a database is being used */
static int inc = 0;
static char pklist[2048] = "";
static char upd_using_notpk[5000] = "";
static int upd_using_notpk_cnt = 0;
extern char current_upd_table[64];
/*static int    const_cnt = 0;*/

int rep_type = 0;	      /** The report type */

/*int           last_var_found = -1;*/

/*int           var_hdr_finished;*/
int isin_command (char *cmd_type);


/**
 * Array where all the WHENEVER conditions are stored.
 */
int when_code[8] = { WHEN_STOP,
  WHEN_NOTSET,
  WHEN_STOP,
  WHEN_CONTINUE,
  WHEN_CONTINUE,
  WHEN_CONTINUE,
  WHEN_NOTSET,
  WHEN_NOTSET
};

int lines_printed=0;

int lines_printed_true=0;
int lines_printed_false=0;

static int push_construct_table (char *tableName);

char when_to_tmp[64];
char when_to[64][8];
int menu_nos[100];
int cmenu = 0;
int use_group = 0;
char curr_rep_name[256];
int curr_rep_block;
int max_menu_no = 0;
struct s_report sreports[1024];
int sreports_cnt = 0;
char mmtitle[132][132];				/** Menu titles */
extern char *outputfilename;			/** Variables A4GL_dump output file name */
int read_glob_var = 0;
int counters[256];
int count_counters = 0;
struct s_report_stack report_stack[REPORTSTACKSIZE];
int report_stack_cnt = 0;
int report_cnt = 1;
int nblock_no = 1;

/*#define GEN_STACK_SIZE 5000*/
#define GEN_STACK_SIZE 10000

char gen_stack[GEN_STACKS][GEN_STACK_SIZE][800];
int gen_stack_cnt[GEN_STACKS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
struct s_constr_buff constr_buff[256];
int constr_cnt = 0;

/**
 * Input bind array.
 *
 * Used for instructions like execute using or open using wher we have a list 
 * of variables that act as input for the statement.
 */
struct binding_comp ibind[NUMBINDINGS];
struct binding_comp nullbind[NUMBINDINGS];

/**
 * Output bind array.
 */
struct binding_comp obind[NUMBINDINGS];
struct binding_comp fbind[NUMBINDINGS];
struct binding_comp ebind[NUMBINDINGS];
struct binding_comp ordbind[NUMBINDINGS];

int ordbindcnt = 0;
int ibindcnt = 0;			/** Number of elements in ibind array */
int nullbindcnt = 0;
int obindcnt = 0;
int fbindcnt = 0;
int ebindcnt = 0;


/**
 * Module current scope level for variable declaration.
 *
 * It contains:
 *   - -1  : Global variables
 *   - 0   : Modular variables
 *   - > 0 : Function local variables
 */
int modlevel = -1;

/** Command stack array */
struct cmds
{
  char cmd_type[20];
  int block_no;

}
command_stack[200];

/** Command stack counter / index (number of elements in command_stack) */
/*
#ifdef LEXER
int ccnt = 0;
#else
*/
extern int ccnt;		/* in lexer.c */
/* #endif */


/** Array index to the last variable filled in the variables array  */




int in_record = 0;
struct s_menu_stack menu_stack[MAXMENU][MAXMENUOPTS];	       /** The menu stack array */

int has_default_database (void);
char *get_default_database (void);

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/
char *rettype (char *s);
/*static int                    is_pk                           (char *s);*/
int yywrap (void);
struct sreports *get_sreports (int z);
void a4gl_add_variable (char *name, char *type, char *n);
static void push_validate_column(char *tabname,char *colname) ;

char *get_namespace (char *s);
char *make_sql_string_and_free (char *first, ...);
/*void do_print_menu_1(void) ;*/
/*void do_print_menu_block_end(void) ;*/
/*int get_blk_no(void) ;*/
char *do_clobbering(char *f,char *s) ;

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Not Used
 *
 * @todo If not used remove it
 *
 * @param z
 * @return
 */
/*
static char *print (char *z)
{
  static char c[10] = "(null)";

  if (z == 0)
  {
    return c;
  }

  return z;
}
*/


#ifdef OLD_STUFF
/**
 * Strip square brackets "[]" from a string.
 * 
 * @param s The string to be stripped
 */
static void
strip_bracket (char *s)
{
  char buff[256];
  int a;
  int c = 0;
  int f = 0;

  A4GL_debug ("strip_bracket\n");
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
}
#endif

/**
 * Strips square brackets "[]" from a string at leaves it just as it was.
 * 
 * @param buff The original string to be stripped
 * @return static buffer with string stripped
 */
/*
static char *
with_strip_bracket (const char *buff)
{
  static char bff[256];
  A4GL_debug ("with_strip_bracket\n");
  strcpy (bff, buff);
  strip_bracket (bff);
  return bff;
}
*/

/**
 * Adds a new variable found by the parser to the variable array
 * Note: Function with same name in ace renamed
 *
 * @param name The variable name
 * @param type The data type of the variable
 * @paran n
 */
/*?static*/
void
a4gl_add_variable (char *name, char *type, char *n)
{
/* MJA - NEWVARIABLE*/
  A4GL_debug ("a4gl_add_variable");
  variable_action (-1, name, type, n, "a4gl_add_variable");
}

/**
 * Clear the variable stack by setting the counter to zero.
 */
void
clr_variable (void)
{
  /* Does nothing*/
}

/**
 *
 */
void
inmod (void)
{
  /* Does nothing*/
}

/**
 * Check if the current state of the compiler is inside a command.
 *
 * Used to see what should be the scope of declarations and usages.
 *
 * Compare the parameter with the string with command type stored in
 * the command stack.
 *
 * @param cmd_type The command type
 * @return
 *   - 0 : We are NOT in command type
 *   - 1 : We are in command type
 */
int
isin_command (char *cmd_type)
{
  int z;
  if (ccnt == 0)
    {
      return 0;
    }

  for (z = ccnt - 1; z >= 0; z--)
    {
      if (command_stack[z].cmd_type == 0 || command_stack[z].cmd_type[0] == 0)
	continue;

      if (strcmp (command_stack[z].cmd_type, cmd_type) == 0)
	{
	  A4GL_debug ("OK\n");
	  return z + 1;
	}
    }
  return 0;
}


char *command_type_for_stack_pos(int n) {
	return command_stack[n].cmd_type;
}
/**
 * This function gets the last command of type s
 * and returns the an ID for it - this is just the stack position - but
 * later maybe made into something unique for a module
 * This ensures that we can have lots of concurrent _sio's running...
 * (prompts within inputs etc)
 * @param cmt_type - Command type to look for ("ALL" for any sio based command, "ALLINPUT" to exclude display array)
 * @return stack ID
**/

int get_sio_id(char *cmd_type) {
int stack_ids[10];
int a;
int max_id=0;
int anymode=0;
for (a=0;a<10;a++) stack_ids[a]=0;
//printf("Looking for cmd_type = %s\n",cmd_type);
/* Are we looking for anything ? */
if (strcmp(cmd_type,"ALL")==0) { anymode=1; }
if (strcmp(cmd_type,"ALLINPUT")==0) { anymode=2; }
if (anymode) { /* used for getfldbuf etc */
	stack_ids[0]=isin_command("INPUT");
	stack_ids[1]=isin_command("CONSTRUCT");
	if (anymode!=2) stack_ids[2]=isin_command("DISPLAY");

	for (a=0;a<3;a++) {
		if (stack_ids[a]>max_id) max_id=stack_ids[a];
	}
	return max_id;
}

a=isin_command(cmd_type);
if (a==0) {
	int z;
	printf("Looking for cmd_type = %s - not found\n",cmd_type);
  	for (z = ccnt - 1; z >= 0; z--)
    	{
      	if (command_stack[z].cmd_type == 0 || command_stack[z].cmd_type[0] == 0)
		continue;
	printf("%d %s\n",z,command_stack[z].cmd_type);
	}
	a4gl_yyerror("Internal error - unable to find sio_id for command");
	return 0;
}
return a;

}
/**
 * Print the declaration of a record.
 *
 * @param z The variable index in the array.
 * @param ff The scope of the record variable:
 *   - -
 *   - G
 * @param vname The record variable name
 */
#ifdef OLD_STUFF
static int
print_record (int z, char ff, char *vname)
{
  int a;
  /*  It should be declared here because the two function are tighly coupled */
  static void print_variable (int z, char ff);

  /* MJA - NEWVARIABLE*/

  A4GL_debug ("Print record %s\n", A4GL_null_as_null(vname));

  if (isin_command ("REPORT") ||
      isin_command ("FORMHANDLER") || isin_command ("MENUHANDLER"))
    {
      if (ff != '-')
	{
	  print_start_record (1, vname);
	}
      else
	{
	  print_start_record (0, vname);
	}
    }
  else
    {
      if (ff != 'G')
	print_start_record (0, vname);
      else
	print_start_record (2, vname);
    }

  for (a = z + 1; a < varcnt; a++)
    {

      if (strcmp (vars[a].var_type, "_RECORD") == 0)
	{
	  if (vars[a].level > vars[z].level)
	    a = print_record (a, '-', vars[a].var_name);

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
      print_end_record (vars[z].var_name, "-1");
    }
  else
    {
      A4GL_debug ("print_end_record %s %s", A4GL_null_as_null(vars[z].var_name), A4GL_null_as_null(vars[z].var_arrsize));

      print_end_record (vars[z].var_name, vars[z].var_arrsize);
    }
  return a;
}
#endif

/**
 * Increment the variable inc by a value.
 *
 * @param a The increment.
 */
void
setinc (int a)
{
  inc += a;
}



#ifdef NOLONGERRREQD
/**
 * Tests if a char pointer is null (char *)0
 *
 * @param ptr The variable to be checked
 * @return
 *   - The parameter pointer if not null
 *   - An empty string otherwise (with just one NULL caracter)
 */
static char *
ignull (char *ptr)
{
  static char *empty = "";
  if (ptr)
    return ptr;
  else
    return empty;
}
#endif

/**
 * The parser found a new variable name and inserts it in the variable array.
 *
 * @todo Document what is the parameter n
 *
 * @param a The variable name
 * @param n
 */
void
push_name (char *a, char *n)
{
  A4GL_debug ("push_name  a = %s n = %d \n", A4GL_null_as_null(a), n);
  a4gl_add_variable (a, 0, n);
}


/**
 * Add a new type into the variables array.
 *
 * Executed directly by the parser.
 *
 * The variables names are allready filled in the array.
 * All of them that have no typr yet associated are defined with this
 * data type.
 *
 * @param a The data type name hardcoded inside the program
 * @param n  The size of elements if the variable is char, decimal, associate
 * @param as If it is recognizing an array or associate is the number of 
 *           elements
 */
void
push_type (char *a, char *n, char *as)
{
  A4GL_debug ("push_type : %s %s %s", A4GL_null_as_null(a), A4GL_null_as_null(n), A4GL_null_as_null(as));

  variable_action (-1, a, n, as, "push_type");

  /* MJA - NEWVARIABLE*/


/* DELETE THIS WHEN DONE .........FIXME FIXME FIXME...........
      if (a != 0)
	{
	  if (strcmp (a, "_ASSOCIATE") == 0)
	    {
	      print_declare_associate_1 (vars[z].var_name, as, n);
	      continue;
	    }
	}
*/


}

/**
 * The parser found the starting of a new record.
 */
void
push_record (void)
{
  /* in_record++; */
  push_type ("_RECORD", 0, 0);
}

/**
 * The parser found the starting of a new object instance
 */
void
push_object (char *objtype)
{
  /* in_record++; */
  push_type ("_OBJECT", objtype, 0);
}

/**
 * The parser found a new associative array.
 *
 * @param a The size of the string used in the key.
 * @param b Number of elements of the hash (array).
 */
void
push_associate (char *a, char *b)
{
  push_type ("_ASSOCIATE", a, b);
}

/**
 * pop the associate array description...
 */
void
pop_associate (char *a)
{
  a4gl_add_variable (0, "_ENDASSOC", 0);
}

/**
 *
 * @param tab
 * @param pkey
 */
void
add_link_to (char *tab, char *pkey)
{

  /*char *pt;*/
  /*char *pk;*/
  /*int z;*/
  A4GL_debug ("Adding link to %s %s\n", A4GL_null_as_null(tab), A4GL_null_as_null(pkey));

  variable_action (-1, tab, pkey, "", "add_link_to");


  /* MJA - NEWVARIABLE*/

}

/**
 *
 */
void
pop_record (void)
{

  /* in_record--; */
  A4GL_debug ("In mod.c : pop_record\n");

  a4gl_add_variable (0, "_ENDREC", 0);

}

/**
 *
 * @param mn
 * @param mnopt
 * @param a
 * @param b
 * @param c
 * @param hlp
 */
void
push_command (int mn, int mnopt, char *a, char *b, char *c, char *hlp)
{

  A4GL_debug ("Menu %d Option %d '%s'", mn, mnopt, A4GL_null_as_null(b));
A4GL_assertion(mn>=MAXMENU,"Ran out of menu spaces");
A4GL_assertion(mnopt>=MAXMENUOPTS,"Ran out of option slots");
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
}

/**
 * Obtain the value of the inc variable.
 *
 * @return The content of the inc variable.
 */
int
getinc (void)
{
  return inc;
}

/**
 * Find a character in a string.
 *
 * @param str The string where to find the caracter
 * @param c The character to be found in a string
 * @return
 *   - The index of the character if found in the string
 *   - 0 if not found
 */
int
A4GL_findex (char *str, char c)
{
  int a;
  for (a = 0; a < strlen (str); a++)
    {
      if (str[a] == c)
	return a;
    }
  return 0;
}


/**
 * Scan a string to find what kind of variable is declared or used inside 
 * it.
 *
 * @todo Complete the folowing comment
 *
 * Transform the sting making the folowing actions:
 *   - Strip eventual square brackets []
 *   - 
 *
 * @param s The string containing the variable declaration
 * @param mode Not used
 * @return A code with one the folowing meanings:
 *   - -1 No variable detected
 *   - -2 Is a variable thru variable
 *   - A numeric code number identifiing the data type (@see find_type())
 */
static long
scan_variables (char *s_n, int mode)
{
  /*int a;*/

  /*long z;*/
  long z_new;
  char s[1024];
  char buff[1024];
  char buff2[1024];
  /*char *ptr;*/
  /*int dir;*/

  /*int flg;*/
  /*int lvl = 0;*/
  int dtype;
  int size;
  int vval;

  if (strlen(s_n)>1023) {
	A4GL_assertion(1,"scan_variables buffers too small");
  }
  memset(s,0,1024);
  strcpy(s,s_n);


A4GL_debug("s=%s",A4GL_null_as_null(s));

  /*last_var_found = -1;*/

  /* MJA - NEWVARIABLE*/
  if (s[0] == '.' && s[1] == '\0')
    return -1;

  if (s[0] == 0)
    return -1;

  if (strchr (s, '\n'))
    return -2;			/* This is a variable thru variable.. */

  if (strlen(s)>=sizeof(buff)) {
		A4GL_assertion(1,"scan_variables buffer is too small..");
  }
  strcpy (buff, s);




  if (s[0] == ' ')
    {
      if (strncmp (buff, " ASSOCIATE_", 11) == 0)
	{
	  strcpy (buff, &s[11]);
	  strcpy (buff2, &s[A4GL_findex (s, ')') + 1]);
	  buff[A4GL_findex (buff, '(')] = 0;
	  strcat (buff, buff2);
	/*printf("DOWNSHIFT : %s\n",buff);*/
	  A4GL_convlower (buff);
	}
      else
	return -1;
    }

/*
 {
	char xxx[1024];
	strcpy(xxx,rm_class_copy(s));
	strcpy(s,xxx);
 }
*/


    if(strncmp(s,"CLASS_COPY->",12)==0) { strcpy(buff,&s[12]); strcpy(s,buff); }  


A4GL_debug("find_variable : %s",A4GL_null_as_null(buff));
  vval = find_variable (buff, &dtype, &size, 0, 0);

  if (vval == 1)
    {
      z_new = dtype + (size << 16);
      /*printf("OK - %x (%d %d)\n",z_new,dtype,size);*/
      return z_new;
    }

  if (vval == 0)
    {
      return -1;
    }


  /*printf("Find_variable returns %d for %s\n",vval,buff);*/
  return vval;




#ifdef OLD_STUFF

  strcat (buff, ".");
  ptr = strtok (buff, ".");
  /* A4GL_debug ("Looking for %s", buff); */
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

      /* A4GL_debug ("Check %d > %d...", lvl, vars[a].level); */

      if (lvl > vars[a].level)
	break;
      /*
         A4GL_debug ("Checking %s %s  %d %d", ptr, vars[a].var_name, vars[a].level, lvl);
       */

      if ((strcmp (ptr, "*") == 0 || strcmp (vars[a].var_name, ptr) == 0)
	  && vars[a].level == lvl)
	{
	  ptr = strtok (0, ".");
	  if (ptr == 0)
	    {
	      /* A4GL_debug ("Got no more to check"); */
	    }
	  else
	    {
	      /*
	         A4GL_debug ("Got more to check '%s'", ptr);
	         A4GL_debug ("vn=%s %s %s %s", vars[a].var_name, vars[a].var_type,
	         vars[a].var_arrsize, vars[a].var_size);
	       */
	      if (strcmp (vars[a].var_type, "_RECORD") == 0)
		{
		  /* A4GL_debug ("_RECORD...."); */
		  while (a < varcnt)
		    {
		      /* A4GL_debug ("Looking for more record declarations...."); */
		      if (strcmp (vars[a + 1].var_type, "_RECORD") == 0 &&
			  vars[a].level == vars[a + 1].level)
			{
			  a++;
			  continue;
			}
		      A4GL_debug (" ---> vn=%s %s %s %s", A4GL_null_as_null(vars[a].var_name),
			     A4GL_null_as_null(vars[a].var_type), A4GL_null_as_null(vars[a].var_arrsize),
			     A4GL_null_as_null(vars[a].var_size));
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

	  /* A4GL_debug ("flg=%d", flg); */

	  if (flg)
	    {
	      /* A4GL_debug ("Types : %s %s", vars[a].var_type, vars[a].var_size); */
	      z =
		find_type (vars[a].var_type) +
		(atoi (vars[a].var_size) << 16);
	      /* A4GL_debug ("Setting last_var_found to %d\n", a); */
	      last_var_found = a;
	      /* A4GL_debug ("Find type returned %x", z); */
	      if (z_new != z)
		{
		  printf ("Discrepency between z's for %s\n", s);
		  exit (0);
		}
	      return z;
	    }
	  /* A4GL_debug ("More levels..."); */

	  lvl++;

	}

    }
  A4GL_debug ("Variable not there : %s", A4GL_null_as_null(s));

  return -1;
#endif

}

/**
 * Scan a string to see if its a variable declaration, and if so
 * gets the data type.
 *
 * @param s The string eventualy containing the variable
 * @return The data type in numeric code
 */
long
scan_variable (char *s)
{
  char buff[256];
  int a;
  a = scan_variables (s, 1);

  if (a == -1)
    {
      strcpy (buff, s);
      strcat (buff, ".*");
      a = scan_variables (buff, 1);
    }
  return a;
}



#ifdef OLD_STUFF
/**
 *
 * @todo Document the possible return values
 *
 * @param s
 * @param mode
 * @return
 *   - 0
 *   - -1
 *   - 1
 *   - 
 */
static long
isvartype (char *s, int mode)
{
  int a;
  char buff[256];
  char *ptr;
  int flg;
  int dir;
  int lvl = 0;

  /* MJA - NEWVARIABLE*/
  if (s[0] == '.' && s[1] == 0)
    return -1;
  if (s[0] == 0)
    return -1;
  strcpy (buff, s);







  strip_bracket (buff);
  A4GL_debug ("Striped2\n");
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
	      A4GL_debug ("Seems to A4GL_match %s %d", A4GL_null_as_null(vars[a].var_name), vars[a].var_arrsize);
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

/**
 * Check if the variable is array type.
 *
 * @todo Document the possible return values
 *
 * @param s The variable name
 * @return
 *   - -1 
 *   - 0 
 *   - 1
 */
long
isarrvariable (char *s)
{
  long a;
A4GL_debug("isarrvariable\n");
  a = isvartype (s, 1);
  A4GL_debug ("Checking if %s is an array %d", A4GL_null_as_null(s), a);
  return a;
}

/**
 * Check if a variable is a record.
 *
 * @todo Document the possible return values
 *
 * @param s The variable name
 * @return
 *   - -1
 *   - 0
 *   - 1
 */
static long
isrecvariable (char *s)
{
A4GL_debug("isrecvariable\n");
  return isvartype (s, 2);
}
#endif

/**
 * This function is not used.
 *
 * @todo : Undertstand if this function is old code and if so remove-it
 */
/*
static int
scan_arr_variable (char *s)
{

  int a;
  char buff[256];
  char *ptr;
  int lvl = 0;
	// MJA - NEWVARIABLE
  if (s[0] == '.' && s[1] == 0)
    return -1;
  if (s[0] == 0)
    return -1;
  strcpy (buff, s);
  strip_bracket (buff);
  A4GL_debug ("striped3");
  strcat (buff, ".");
  ptr = strtok (buff, ".");
  for (a = 0; a < varcnt; a++)
  {
    A4GL_debug ("chk: %d %s %s %d %d\n", a, A4GL_null_as_null(vars[a].var_name), A4GL_null_as_null(ptr), vars[a].level, lvl);

    if (strcmp (vars[a].var_name, ptr) == 0 && vars[a].level == lvl)
	  {
	    ptr = strtok (0, ".");

	    if (ptr == 0)
	    {
	      if (atoi (vars[a].var_arrsize) > 0)
		    {
		      print_range_check (s, vars[a].var_arrsize);
		    }
	      return find_type (vars[a].var_type);
	    }
	    lvl++;
	  }
  }

  A4GL_debug ("// Warning    Couldnt find %s \n", A4GL_null_as_null(s));

  return -1;

}
*/



/**
 * 
 * @param t
 * @param ptr
 * @param name
 */
void
add_constant (char t, char *ptr, char *name)
{
  /*char scope = 'm';*/
  int x;
  char buff[256];
  x = 0;
  buff[1] = 0;
  buff[0] = t;
  variable_action (-1, name, ptr, buff, "add_constant");

#ifdef OLD_STUFF
  if (x != 0)
    {
      adderr ("'%s' is a reserved word and cannot be used as a constant\n",
	      name, "");
      a4gl_yyerror ("Constant Declaration Error");
    }
  A4GL_debug ("Add constant\n");
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
      a4gl_yyerror ("Duplicate Constant");
    }

  if (isin_command ("FUNC") || isin_command ("REPORT")
      || isin_command ("MAIN") || isin_command ("FORMHANDLER")
      || isin_command ("MENUHANDLER"))
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
  const_arr[const_cnt].scope = scope;
  const_arr[const_cnt].ptr = strdup (ptr);
  const_cnt++;
#endif
}

/**
 * Set the internal 4gl variables in the array.
 */
void
set_4gl_vars (void)
{
  set_current_variable_scope ('G');
  variable_action (-1, "int_flag", "", "", "a4gl_add_variable");
  variable_action (-1, "long", "", "", "push_type");
  variable_action (-1, "quit_flag", "", "", "a4gl_add_variable");
  variable_action (-1, "long", "", "", "push_type");
  variable_action (-1, "a4gl_status", "", "", "a4gl_add_variable");
  variable_action (-1, "long", "", "", "push_type");
  variable_action (-1, "time", "", "", "a4gl_add_variable");
  variable_action (-1, "char", "8", "", "push_type");
  variable_action (-1, "a4gl_sqlca", "", "", "a4gl_add_variable");
  variable_action (-1, "_RECORD", "", "", "push_type");
  variable_action (-1, "sqlcode", "", "", "a4gl_add_variable");
  variable_action (-1, "long", "", "", "push_type");
  variable_action (-1, "sqlerrm", "", "", "a4gl_add_variable");
  variable_action (-1, "char", "72", "", "push_type");
  variable_action (-1, "sqlerrp", "", "", "a4gl_add_variable");
  variable_action (-1, "char", "8", "", "push_type");
  variable_action (-1, "sqlerrd", "", "", "a4gl_add_variable");
  variable_action (-1, "", "", "6", "push_type");
  variable_action (-1, "long", "", "", "push_type");
  variable_action (-1, "sqlawarn", "", "", "a4gl_add_variable");
  variable_action (-1, "char", "8", "", "push_type");
  variable_action (-1, "sqlstate", "", "", "a4gl_add_variable");
  variable_action (-1, "char", "9", "", "push_type");
  variable_action (-1, "", "_ENDREC", "", "a4gl_add_variable");

  variable_action (-1, "notfound", "100", "i", "add_constant");

/* @todo - QUICK HACK*/
/*variable_action(-1,"sqlca","a4gl_sqlca","C","add_constant");*/
/*variable_action(-1,"status","a4gl_status","C","add_constant");*/

  variable_action (-1, "false", "0", "i", "add_constant");
  variable_action (-1, "true", "1", "i", "add_constant");
  variable_action (-1, "today", "", "", "a4gl_add_variable");
  variable_action (-1, "fgldate", "", "", "push_type");
  variable_action (-1, "user", "", "", "a4gl_add_variable");	/* Did someone change this  to 'usr' */
  variable_action (-1, "char", "8", "", "push_type");
  variable_action (-1, "pageno", "", "", "a4gl_add_variable");
  variable_action (-1, "long", "", "", "push_type");
  variable_action (-1, "lineno", "", "", "a4gl_add_variable");
  variable_action (-1, "long", "", "", "push_type");
  variable_action (-1, "usrtime", "", "", "a4gl_add_variable");
  variable_action (-1, "long", "", "", "push_type");
  variable_action (-1, "curr_hwnd", "", "", "a4gl_add_variable");
  variable_action (-1, "long", "", "", "push_type");
  variable_action (-1, "curr_form", "", "", "a4gl_add_variable");
  variable_action (-1, "long", "", "", "push_type");
  variable_action (-1, "err_file_name", "", "", "a4gl_add_variable");
  variable_action (-1, "char", "32", "", "push_type");
  variable_action (-1, "err_file_no", "", "", "a4gl_add_variable");
  variable_action (-1, "long", "", "", "push_type");
  variable_action (-1, "curr_file_name", "", "", "a4gl_add_variable");
  variable_action (-1, "char", "32", "", "push_type");
  variable_action (-1, "curr_line_no", "", "", "a4gl_add_variable");
  variable_action (-1, "long", "", "", "push_type");
  variable_action (-1, "err_status", "", "", "a4gl_add_variable");
  variable_action (-1, "long", "", "", "push_type");
  variable_action (-1, "aiplib_status", "", "", "a4gl_add_variable");
  variable_action (-1, "long", "", "", "push_type");

//printf("--> M\n");
  set_current_variable_scope ('m');
}

/**
 * Open a database.
 *
 * Called by the parser when found the 4gl DATABASE statement.
 *
 * @param s The database name
 */
void
open_db (char *s)
{
  char db[2048];
  char buff[256];

  A4GL_debug ("open_db %s", A4GL_null_as_null(s));
  strcpy (db, s);

  if (has_default_database ())
    {
      strcpy (db, get_default_database ());
      A4GL_debug ("Overriding default database with %s", A4GL_null_as_null(db));
      A4GL_trim (db);
    }

  A4GLSQL_set_status (0, 1);
  A4GLSQL_init_connection (db);
  if (A4GLSQL_get_status () != 0)
    {
      sprintf (buff, "Could not connect to database %s (%s)", A4GL_null_as_null(db),
	       A4GL_null_as_null(A4GLSQL_get_sqlerrm ()));
      a4gl_yyerror (buff);
    }
  if (db_used == 0)
    db_used = 1;
}

/**
 * Gets the C data type corresponding to 4gl data type
 *
 * @param s A string with the numeric 4gl data type (@see find_type()) 
 * @return The string (static) with the C declaration
 */
char *
rettype (char *s)
{
  static char rs[20] = "long";
  int a;
  A4GL_debug ("In rettype : %s", A4GL_null_as_null(s));

  a = atoi (s);

  A4GL_debug ("In rettype");
  if (A4GL_has_datatype_function_i (a, "OUTPUT"))
    {
      /* char *(*function) (); */
      char *(*function) (void);
      A4GL_debug ("In datatype");
      function = A4GL_get_datatype_function_i (a, "OUTPUT");
      A4GL_debug ("Copy");
      strcpy (rs, function ());
      A4GL_debug ("Returning %s\n", A4GL_null_as_null(rs));
      return rs;
    }

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

  if (strcmp (s, "10") == 0)
    strcpy (rs, "struct_dtime");

  if (strcmp (s, "11") == 0)
    strcpy (rs, "fglbyte");

  if (strcmp (s, "12") == 0)
    strcpy (rs, "fgltext");

  if (strcmp (s, "13") == 0)
    strcpy (rs, "char");
  if (strcmp (s, "14") == 0)
    strcpy (rs, "struct_ival");

  return rs;
}

/**
 * Trim the spaces at the right part of a string.
 *
 * @param s The string to be trimmed
 */
static void
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

/**
 * Acces to the database and push a variable declaration for a simple
 * like variable (the ones that are not like table.*)
 *
 * @param tableName The name of the table
 * @param columnName The name of the column
 *
 * @return
 *   - 0 : Column does not exist or an error ocurred.
 *   - 1 : Type readed.
 */
static int
pushLikeTableColumn (char *tableName, char *columnName)
{
  int rval;
  int idtype;
  int isize;
  char csize[20];
  char cdtype[20];
  char buff[300];

  A4GL_debug ("pushLikeTableColumn()");
  rval = A4GLSQL_read_columns (tableName, columnName, &idtype, &isize);
  if (rval == 0)
    {
      sprintf (buff, "%s.%s does not exist in the database", tableName,
	       columnName);
      a4gl_yyerror (buff);
      return 0;
    }
  sprintf (cdtype, "%d", idtype & 15);
  sprintf (csize, "%d", isize);
  trim_spaces (columnName);
  push_type (rettype (cdtype), csize, (char *) 0);
  return 1;
}


static int
pushValidateTableColumn (char *tableName, char *columnName)
{
  int rval;
  int idtype;
  int isize;
  /*char csize[20];*/
  /*char cdtype[20];*/
  char buff[300];

  A4GL_debug ("pushValidateTableColumn()");
/*printf("Table name = %s column name=%s\n",tableName,columnName);*/
  rval = A4GLSQL_read_columns (tableName, columnName, &idtype, &isize);
  if (rval == 0)
    {
      sprintf (buff, "%s.%s does not exist in the database", tableName,
	       columnName);
      a4gl_yyerror (buff);
      return 0;
    }
  /*sprintf (cdtype, "%d", idtype & 15);*/
  /*sprintf (csize, "%d", isize);*/
  trim_spaces (columnName);
  push_validate_column (tableName,columnName);
  return 1;
}

static int
pushValidateAllTableColumns (char *tableName)
{
  int rval;
  int isize = 0;
  int idtype = 0;
  char colname[256] = "";
  /*char csize[20];*/
  /*char cdtype[20];*/
  char buff[300];
  char *ccol;

  A4GL_debug ("pushValidateAllTableColumns()");
  /* A4GLSQL_get_columns (char *tabname, char *colname, int *dtype, int *size) */
  A4GL_debug ("Calling get_columns : %s\n", A4GL_null_as_null(tableName));
  rval = A4GLSQL_get_columns (tableName, colname, &idtype, &isize);
  A4GL_debug ("rval = %d", rval);
  if (rval == 0 && tableName)
    {
      sprintf (buff, "%s does not exist in the database", tableName);
      a4gl_yyerror (buff);
      return 1;
    }

  A4GL_debug ("Rval !=0");

  while (1)
    {
      colname[0] = 0;

      /* int A4GLSQL_next_column(char **colname, int *dtype,int *size); */
      rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
      A4GL_debug ("next column for table '%p' is '%p'", tableName, ccol);
      A4GL_debug ("next column for table '%s' is '%s'", A4GL_null_as_null(tableName), A4GL_null_as_null(ccol));

      strcpy (colname, ccol);

      /*
         warning: passing arg 1 of `A4GLSQL_next_column' from incompatible pointer type
         we are sending char ARRAY to function expecting char POINTER !!!!
       */

      if (rval == 0)
	break;

      /*sprintf (cdtype, "%d", idtype & 15);*/
      /*sprintf (csize, "%d", isize);*/
      /*A4GL_debug ("%d %d", idtype, isize);*/
      /*A4GL_debug ("---> %s %s", cdtype, csize);*/
      /*A4GL_debug ("A4GLSQL_read_columns: Pushing %s %s %s", colname, cdtype,*/
	     /*csize);*/
      trim_spaces (colname);
      push_validate_column (tableName,colname);

      /*push_name (colname, 0);*/
      /*push_type (rettype (cdtype), csize, 0);*/
    }
  A4GLSQL_end_get_columns ();
  return 0;
}


/**
 * Find all columns of a table from the database to declare a record like
 * table.*
 *
 * @param tableName The name of the table
 */
static int
pushLikeAllTableColumns (char *tableName)
{
  int rval;
  int isize = 0;
  int idtype = 0;
  char colname[256] = "";
  char csize[20];
  char cdtype[20];
  char buff[300];
  char *ccol;

  A4GL_debug ("pushLikeAllTableColumns()");
  /* A4GLSQL_get_columns (char *tabname, char *colname, int *dtype, int *size) */
  A4GL_debug ("Calling get_columns : %s\n", A4GL_null_as_null(tableName));
  rval = A4GLSQL_get_columns (tableName, colname, &idtype, &isize);
  A4GL_debug ("rval = %d", rval);
  if (rval == 0 && tableName)
    {
      sprintf (buff, "%s does not exist in the database", tableName);
      a4gl_yyerror (buff);
      return 1;
    }

  A4GL_debug ("Rval !=0");

  while (1)
    {
      colname[0] = 0;

      /* int A4GLSQL_next_column(char **colname, int *dtype,int *size); */
      rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
      A4GL_debug ("next column for table '%p' is '%p'", tableName, ccol);
      A4GL_debug ("next column for table '%s' is '%s'", A4GL_null_as_null(tableName),A4GL_null_as_null(ccol));

      strcpy (colname, ccol);

      /*
         warning: passing arg 1 of `A4GLSQL_next_column' from incompatible pointer type
         we are sending char ARRAY to function expecting char POINTER !!!!
       */

      if (rval == 0)
	break;

      sprintf (cdtype, "%d", idtype & 15);
      sprintf (csize, "%d", isize);
      A4GL_debug ("%d %d", idtype, isize);
      A4GL_debug ("---> %s %s", A4GL_null_as_null(cdtype), A4GL_null_as_null(csize));
      A4GL_debug ("A4GLSQL_read_columns: Pushing %s %s %s", A4GL_null_as_null(colname), A4GL_null_as_null(cdtype),
	     A4GL_null_as_null(csize));
      trim_spaces (colname);
      push_name (colname, 0);
      push_type (rettype (cdtype), csize, 0);
    }
  A4GLSQL_end_get_columns ();
  return 0;
}

/**
 * The parser found a variable declared like table.column
 * It needs to go to the database to find the data type in order to do the
 * proper declaration, binds and convertions.
 *
 * @param t2 The table and column (table.column format)
 */
static void
push_like2 (char *t2)
{
  char buff[300];
  char *tableName;
  char *columnName;
  char t[256];
  A4GL_debug ("In push_like2");

  if (db_used == 0)
    {
      sprintf (buff, "You cannot use LIKE without specifying a database");
      a4gl_yyerror (buff);
      return;
    }

  strcpy (t, t2);
  strcpy (buff, t);
  strcat (buff, ".");

  tableName = strtok (buff, ".");	/* table name */
  columnName = strtok (0, ".");	/* column name */
  A4GL_debug ("a='%s' b='%s'", A4GL_null_as_null(tableName), A4GL_null_as_null(columnName));

  if (columnName)
    {
      pushLikeTableColumn (tableName, columnName);
      return;
    }

  pushLikeAllTableColumns (tableName);
  return;
}


void
push_validate (char *t2)
{
  char buff[300];
  char *tableName;
  char *columnName;
  char t[256];
  A4GL_debug ("In push_validate");
  /*printf("t2=%s\n",t2);*/


/* Skip any owner bit...*/
  if (t2[0]=='\\' && t2[1]=='"') {
	char *x;
	x=strchr(t2,'.');
	if (x) {
		t2=x+1;
	}
  }



  if (db_used == 0)
    {
      sprintf (buff, "You cannot use VALIDATE without specifying a database");
      a4gl_yyerror (buff);
      return;
    }

  strcpy (t, t2);
  strcpy (buff, t);
  strcat (buff, ".");

  tableName = strtok (buff, ".");	/* table name */
  columnName = strtok (0, ".");	/* column name */
  A4GL_debug ("a='%s' b='%s'", A4GL_null_as_null(tableName), A4GL_null_as_null(columnName));

  if (columnName && strcmp(columnName,"*")!=0)
    {
      pushValidateTableColumn (tableName, columnName);
      return;
    }

  pushValidateAllTableColumns (tableName);
  return;
}





/**
 * The parser found a new variable like table.column.
 *
 * Its gonna be inserted in the variables array.
 *
 * @param t The table and column (table.column format)
 */
void
push_like (char *t)
{

  A4GL_debug (">>>>>> %s\n", A4GL_null_as_null(t));
  push_like2 (t);
  A4GL_debug ("<<<<<<\n");
}

/**
 * The parse found a new record like table.*
 *
 * @param t The table name
 */
void
push_rectab (char *t)
{
  push_like (t);
}

/**
 * Insert a new menu title in the menu titles array.
 *
 * The parser have found a new menu.
 *
 * @param s The title of the menu
 */
void
push_menu_title (char *s)
{
  strcpy (mmtitle[menu_cnt], s);
}

/**
 * The parser found the begining of a new block command
 *
 * Some of the commands are marked in the generated code as a C label.
 * Others (Main, func, report, globals, etc) are just added to the command 
 * stack.
 *
 * @param cmd_type The type of the command found:
 */
void
push_blockcommand (char *cmd_type)
{
  /*printf("push_blockcommand %s\n",cmd_type);*/
  A4GL_debug ("START BLOCK %s", cmd_type);
  A4GL_debug ("\n\n--------->%s\n\n", cmd_type);
  A4GL_debug (" /* new block %s %d */\n", cmd_type, ccnt);
  strcpy (command_stack[ccnt].cmd_type, cmd_type);
  if (strcmp (cmd_type, "MAIN") == 0
      || strcmp (cmd_type, "FUNC") == 0 ||
      strcmp (cmd_type, "REPORT") == 0 || strcmp (cmd_type, "GLOBALS") == 0 ||
      strcmp (cmd_type, "FORMHANDLER") == 0
      || strcmp (cmd_type, "MENUHANDLER") == 0)
    {
      command_stack[ccnt].block_no = -1;
    }
  else
    {
      print_start_block (nblock_no);

      command_stack[ccnt].block_no = nblock_no++;
    }
  A4GL_debug (" Added new block");
  ccnt++;
  file_out_indent(ccnt);
}

/**
 * The parser found a CONTINUE statement.
 *
 * @param cmd_type The type of continue found (the keyword found after
 * the CONTINUE token).
 */
void
add_continue_blockcommand (char *cmd_type)
{
  int a;

  /* more checks here ! */

  for (a = ccnt - 1; a > 0; a--)
    {
      if (strcmp (command_stack[a].cmd_type, cmd_type) == 0)
	{
	  print_continue_block (command_stack[a].block_no, 0);
	  return;
	}
    }

}

/**
 * Check if is a continue of a command.
 *
 * @param s The keyword / token for it could be a continue.
 *
 * @return 
 *   - 1 : Is a continue command.
 *   - 0 : Otherwise.
 */
static int
iscontinuecmd (char *s)
{

  if (strcmp (s, "FOR") == 0)
    return 1;
  /* if (strcmp(s,"FOREACH")==0) return 1; */
  if (strcmp (s, "WHILE") == 0)
    return 1;
  if (strcmp (s, "CASE") == 0)
    return 1;
  /*
     if (strcmp(s,"CONSTRUCT")==0) return 1;
     if (strcmp(s,"DISPLAY")==0) return 1;
     if (strcmp(s,"PROMPT")==0) return 1;
   */

  return 0;
}

/**
 * An end of a block command was ocurred.
 *
 *   - End the block with the necessary command.
 *   - Decrement the increment count.
 *
 * @param cmd_type The type of the block that was ended.
 */
void
pop_blockcommand (char *cmd_type)
{
  int a;

  char err[80];
  A4GL_debug ("END BLOCK %s", cmd_type);

  /* more checks here ! */

  ccnt--;
  file_out_indent(ccnt);
  if (command_stack[ccnt].block_no > 0)
    {

      if (iscontinuecmd (cmd_type))
	{
	  print_continue_block (command_stack[ccnt].block_no, 1);
	}
      print_end_block (command_stack[ccnt].block_no);
    }

  A4GL_debug ("\n\n--------->%s\n\n", cmd_type);

  if (strcmp (command_stack[ccnt].cmd_type, cmd_type) == 0)
    {

      command_stack[ccnt].cmd_type[0] = 0;

      return;

    }

  sprintf (err, "%s was not last block command (I've got a %s @ %d)\n",
	   cmd_type, command_stack[ccnt].cmd_type, ccnt);
  A4GL_debug (err);
  A4GL_debug ("------------------\n");
  for (a = 0; a <= ccnt; a++)
    {
      A4GL_debug ("   %s\n", command_stack[a].cmd_type);
    }
  A4GL_debug ("------------------\n");
  a4gl_yyerror (err);
  exit (0);
}

/**
 *
 * @param cmd_type
 */
int
in_command (char *cmd_type)
{

  int z;

  A4GL_debug ("Check for %s %d \n", cmd_type, ccnt);

  if (ccnt == 0)
    {
      A4GL_debug ("Stack is empty\n");
      return 0;
    }

  for (z = ccnt - 1; z >= 0; z--)
    {

      if (command_stack[z].cmd_type == 0 || command_stack[z].cmd_type[0] == 0)
	continue;

      if (strcmp (command_stack[z].cmd_type, cmd_type) == 0)
	{
	  A4GL_debug ("OK\n");
	  return 1;
	}
    }

  printf ("Not in a %s command\n", cmd_type);
  a4gl_yyerror ("Can't exit command");

  return 0;
}


/**
 * Trim the New Line at the end of a string.
 * 
 * @param s The string to be trimmed
 */
/* in funcs_d.c :

void 	trim				(char *p);

static void
trim(char *s)
{
  if (s[strlen (s) - 1] == '\n')
    s[strlen (s) - 1] = 0;
}

*/

/**
 *
 * @param a 
 * @param s
 */
void
push_gen (int a, char *s)
{
  A4GL_debug ("Push %d %s - %d\n", a, A4GL_null_as_null(s), gen_stack_cnt[a]);
  /*printf ("Push %d %s - %d\n", a, s,gen_stack_cnt[a]);*/
  if (gen_stack_cnt[a] >= GEN_STACK_SIZE)
    {
      printf ("Out of stack!\n");
      exit (77);
    }
  strcpy (gen_stack[a][gen_stack_cnt[a]++], s);
}


int
gen_cnt (int a)
{
  return gen_stack_cnt[a];
}



void
copy_gen (int a, int b)
{
  int c;


  if (gen_stack_cnt[a] && gen_stack[a][gen_stack_cnt[a] - 1][0] == '(')
    {
      /*printf ("POP\n");*/
      pop_gen (a);
    }


  for (c = 0; c < gen_stack_cnt[b]; c++)
    {
      push_gen (a, gen_stack[b][c]);
    }
  gen_stack_cnt[b] = 0;
}

char *
pop_gen (int a)
{
  /*printf ("Popgen called\n");*/
  /*printf ("UPDVAL2 cnt = %d\n", gen_stack_cnt[UPDVAL2]);*/
  /*dump_updvals();*/
  gen_stack_cnt[a]--;
  return gen_stack[a][gen_stack_cnt[a]];

}


/**
 *
 * @param a
 * @param s
 */
void
pop_all_gen (int a, char *s)
{
  int z;
  for (z = 0; z < gen_stack_cnt[a]; z++)
    {
      if (z > 0)
 A4GL_debug ("%s ", A4GL_null_as_null(s));

      A4GL_debug ("%s", A4GL_null_as_null(gen_stack[a][z]));
    }
  gen_stack_cnt[a] = 0;
}


/**
 * Not used
 */
/*
static a4gl_yyerrorf (char *fmt, ...)
{
  char buff[256];
  va_list args;
  va_start (args, fmt);
  vsprintf (buff, fmt, args);
  a4gl_yyerror (buff);
}
*/

#ifdef NOLONGERREQD

/**
 * Checks if a column is part of primary key
 *
 * @param s The string containing the primary key column name
 * @return
 *   - 1 : The column is part of PK 
 *   - 0 : The column is not part of PK 
 */
static int
is_pk (char *s)
{
  int a;
  int cnt;
  char buff[256];
  A4GL_debug ("Checking if %s is a pk in %s", A4GL_null_as_null(s),A4GL_null_as_null( pklist));
  a = linked_split (pklist, 0, 0);
  for (cnt = 1; cnt <= a; cnt++)
    {
      linked_split (pklist, cnt, buff);
      if (A4GL_aubit_strcasecmp (s, buff) == 0)
	{
	  A4GL_debug ("Yes");
	  return 1;
	}
    }
  if (strlen (upd_using_notpk) > 0)
    strcat (upd_using_notpk, ",");
  strcat (upd_using_notpk, s);
  upd_using_notpk_cnt++;
  A4GL_debug ("No");
  return 0;
}
#endif


/**
 * Add a new bind to the specific aray (acording to the type).
 *
 * @param i The bind type.
 *   - i : Input bind.
 *   - O :
 *   - N : Null bind.
 *   - o : Output bind.
 *   - F :
 * @param var The variable name to be binded.
 */
int
add_bind (char i, char *var_i)
{
  long dtype;
/*char c;*/
char var[2048]="";
A4GL_debug("add_bind: %c %s\n",i,A4GL_null_as_null(var_i));
strcpy(var,var_i);

  if (var_i[0] == '"')
    {
      dtype = (strlen (var) - 2) << 16;
	strcpy(var,var_i);
    }
  else
    {
	A4GL_debug("Scanning...");
      dtype = scan_variable (var_i);


	switch (i) {
	case 'f': strcpy(var,fgl_add_scope(var_i,'L'));break; /* Function parameters*/
	case 'O': strcpy(var,fgl_add_scope(var_i,'L'));break; /* Report order by*/
	default: strcpy(var,fgl_add_scope(var_i,0));
	}

    }


  A4GL_debug ("add_bind - dtype=%x (%s) i=%c\n", dtype, A4GL_null_as_null(var), i);

  if (i == 'i')
    {
      if (dtype == -2 || strstr (var, ".*"))
	{
	  A4GL_debug ("push_bind_rec...");
	  push_bind_rec (var, i);
	}
      else
	{
	if (ibindcnt>=NUMBINDINGS) {
		a4gl_yyerror("Internal error - ran out of bindings...");
		return 0;
	}
	  ibind[ibindcnt].start_char_subscript = 0;
	  ibind[ibindcnt].end_char_subscript = 0;

/*printf("var= '%s'\n",var);*/
	  if (strncmp (var, " a4gl_substr(", 8) != 0)
	    {
	      strcpy (ibind[ibindcnt].varname, var);
	      ibind[ibindcnt].dtype = dtype;
	    }
	  else
	    {
	      char buff[256];
	      char buff2[256];
	      int s_dtype;
	      int s_sstart;
	      int s_send;
	      int a;
	      strcpy (buff2, &var[strlen("a4gl_substr ")+1]);
		printf("%s\n",buff2);
	      a =
		sscanf (buff2, "%s , %d , %d , %d) /*1*/", buff, &s_dtype,
			&s_sstart, &s_send);
	      if (a != 4)
		{
		A4GL_debug("Error processing : %s\n",A4GL_null_as_null(buff2));
		  a4gl_yyerror ("Internal error - (split substr)");
		}
	      if (s_send == 0)
		s_send = s_sstart;
	      strcpy (ibind[ibindcnt].varname, buff);
	      ibind[ibindcnt].dtype = s_dtype;
	      ibind[ibindcnt].start_char_subscript = s_sstart;
	      ibind[ibindcnt].end_char_subscript = s_send;
	      /*printf("%s %d %d %d\n",ibind[ibindcnt].varname,ibind[ibindcnt].dtype,ibind[ibindcnt].start_char_subscript,ibind[ibindcnt].end_char_subscript);*/
	    }
	  ibindcnt++;
	}
      return ibindcnt;
    }

  if (i == 'N')
    {
      if (dtype == -2 || strstr (var, ".*"))
	{
	  A4GL_debug ("push_bind_rec...");
	  push_bind_rec (var, i);
	}
      else
	{
	  strcpy (nullbind[nullbindcnt].varname, var);
	  nullbind[nullbindcnt].dtype = dtype;
	  nullbindcnt++;

	  if (nullbindcnt>=NUMBINDINGS) {
		a4gl_yyerror("Internal error - ran out of bindings...");
		return 0;
	  }
	}
      return nullbindcnt;
    }



  if (i == 'o')
    {
      if (dtype == -2 || strstr (var, ".*"))
	{
	  push_bind_rec (var, i);
	}
      else
	{
	if (obindcnt>=NUMBINDINGS) {
		a4gl_yyerror("Internal error - ran out of bindings...");
		return 0;
	}
	  strcpy (obind[obindcnt].varname, var);
	  obind[obindcnt].dtype = dtype;
	  obindcnt++;
	}
      return obindcnt;
    }

  if (i == 'e')
    {
      if (dtype == -2 || strstr (var, ".*"))
	{
	  push_bind_rec (var, i);
	}
      else
	{
	if (ebindcnt>=NUMBINDINGS) {
		a4gl_yyerror("Internal error - ran out of bindings...");
		return 0;
	}
	  strcpy (ebind[ebindcnt].varname, var);
	  ebind[ebindcnt].dtype = dtype;
	  ebindcnt++;
	}
      return ebindcnt;
    }

  if (i == 'O')
    {
      if (dtype == -2 || strstr (var, ".*"))
	push_bind_rec (var, i);
      else
	{
	if (ordbindcnt>=NUMBINDINGS) {
		a4gl_yyerror("Internal error - ran out of bindings...");
		return 0;
	}
	  strcpy (ordbind[ordbindcnt].varname, var);
	  ordbind[ordbindcnt].dtype = dtype;
	  ordbindcnt++;
	}
      return ordbindcnt;
    }




  if (i == 'f' || i == 'F')
    {
      if (i == 'f')
	dtype = -1;

      if (dtype == -2 || strstr (var, ".*"))
	push_bind_rec (var, i);
      else
	{
	if (fbindcnt>=NUMBINDINGS) {
		a4gl_yyerror("Internal error - ran out of bindings...");
		return 0;
	}
	  strcpy (fbind[fbindcnt].varname, var);
	  fbind[fbindcnt].dtype = 0;
	  fbindcnt++;
	  return fbindcnt;
	}
    }

  return 0;
}

/**
 * Initilize the bind arrays and add a variable to it.
 *
 * @param i The bind type:
 *   - i : Input bind.
 *   - N : Null bind.
 *   - o : Output bind.
 *   - O 
 *   - f or F :
 * @param var The variable name to be binded.
 * @return
 */
int
start_bind (char i, char *var)
{
  A4GL_debug ("start_bind %c -  %s", i, A4GL_null_as_null(var));

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

  if (i == 'f' || i == 'F')
    {
      fbindcnt = 0;
    }
  if (i == 'e')
    {
      ebindcnt = 0;
    }

  if (var != 0)
    return add_bind (i, var);

  return 0;
}

/**
 * Gets the bind array index of a specific type of bind.
 *
 * @param i The bind array type:
 *   - i : Input bind.
 *   - N : Null bind
 *   - o : Output bind
 *   - f or F
 * @return The counter in the bind array, 0 if invalid type.
 */
int
get_bind_cnt (char i)
{
  if (i == 'i')
    return ibindcnt;
  if (i == 'N')
    return nullbindcnt;
  if (i == 'o') return obindcnt;
  if (i == 'e') return ebindcnt;
  if (i=='O') return ordbindcnt;
  if (i == 'f' || i == 'F')
    return fbindcnt;
  return 0;
}


char *get_bind_varname(char i,int n) {
	if (i=='o') {
		return obind[n].varname;
	}
	if (i=='i') {
		return ibind[n].varname;
	}
	return "";
}
/**
 * Gets the number of elements filled in a bind array.
 *
 * @param i The bind array type:
 *   - i : The bind type.
 *   - N : Null bind.
 *   - o : Output bind.
 *   - f or F
 * @return The number of elements in the bind array, 0 if invalid type.
 */
int
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

  return 0;
}

/**
 * The parser found a CONTINUE instruction for a specific loop command.
 *
 * One example could be CONTINUE WHILE.
 *
 * The loop commands could be:
 *   - WHILE
 *   - INPUT
 *   - FOREACH
 *   - FOR
 *   - CONSTRUCT
 *   - DISPLAY
 *   - MENU
 *
 *   Finds backwards the opened corresponding command. 
 *   This means that if we have a CONTINUE WHILE then it belongs to the
 *   last founded (and not yet closed) WHILE.
 *
 * @param cmd_type The string containing the type name of the loop used
 */
void
continue_loop (char *cmd_type)
{
  int a;
  int g = 0;
  char *internal_cmd_type;



/* We have to do some messing around here...*/
/* If we want to 'continue input' - we call continue_input("INPUT")*/
/* if we want a next field ... that does the next field bit - then calls continue_input("INPUTREQ")*/
/* Here - we will always be looking for "INPUT" - but pass on the INPUT/INPUTREQ to the print stage...*/
/* Same goes for construct*/


  internal_cmd_type=strdup(cmd_type);

  if (strcmp(cmd_type,"INPUTREQ")==0) strcpy(internal_cmd_type,"INPUT");
  if (strcmp(cmd_type,"CONSTRUCTREQ")==0) strcpy(internal_cmd_type,"CONSTRUCT");

  for (a = ccnt - 1; a >= 0; a--)
    {
      A4GL_debug ("continue_loop:%s %s %s\n", command_stack[a].cmd_type, cmd_type,internal_cmd_type);

      if (strcmp (command_stack[a].cmd_type, internal_cmd_type) == 0)
	{
	  g = 1;
	  break;
	}
    }
  if (g == 0)
    {
      A4GL_debug ("/* wanted to continue a %s but wasnt in one! */", cmd_type);
      return;
    }
  print_continue_loop (command_stack[a].block_no, cmd_type);
}

/**
 * The parser found a EXIT instruction for a specific loop command.
 *
 * One example could be EXIT WHILE.
 *
 * The loop commands could be:
 *   - WHILE
 *   - INPUT
 *   - FOREACH
 *   - FOR
 *   - CONSTRUCT
 *   - DISPLAY
 *   - MENU
 *
 *   Finds backwards the opened corresponding command.
 *   This means that if we have a EXIT WHILE then it belongs to the
 *   last founded (and not yet closed) WHILE.
 *
 * @param cmd_type The string containing the type name of the loop used
 */
void
exit_loop (char *cmd_type)
{
  int a;
  int g = 0;
  int printed = 0;

  for (a = ccnt - 1; a >= 0; a--)
    {
      A4GL_debug ("exit_loop:%s %s\n", command_stack[a].cmd_type, cmd_type);

      if (strcmp (command_stack[a].cmd_type, cmd_type) == 0)
	{
	  g = 1;
	  break;
	}
    }
  if (g == 0)
    {
      A4GL_debug ("/* wanted to exit a %s but wasnt in one! */", cmd_type);
      return;
    }

  if (strcmp (cmd_type, "MENU") == 0)
    {
      print_exit_loop ('M', command_stack[a].block_no);
      printed = 1;
    }

  if (strcmp (cmd_type, "PROMPT") == 0)
    {
      print_exit_loop ('P', 0);
      printed = 1;
    }


  if (printed == 0)
    {
      print_exit_loop (0, command_stack[a].block_no);
    }
}

/**
 *
 *
 * @param
 */
void
set_curr_block (int a)
{
  curr_rep_block = a;
}

/**
 * The parser found a new report block
 *
 * @todo Comment the parameters
 *
 * @param why
 * @param whytype
 */
void
push_report_block (char *why, char whytype)
{
  set_curr_block (0);
  strcpy (report_stack[report_stack_cnt].why, why);
  report_stack[report_stack_cnt].whytype = whytype;
  print_repctrl_block ();
  report_stack_cnt++;
  lines_printed=0;
}


/**
 *
 *
 * @param
 */
/*
static
get_curr_rep ()
{
  return report_cnt;
}
*/

/**
 * Initializes a new report structurem where some information about it
 * is stored.
 *
 * @param rep The report structure pointer
 */
void
init_report_structure (struct rep_structure *rep)
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
  rep->lines_in_header=0;
  rep->lines_in_first_header=0;
  rep->lines_in_trailer=0;
  strcpy (rep->output_loc, "\"stdout\"");
}


void
pdf_init_report_structure (struct pdf_rep_structure *rep)
{
  A4GL_debug ("ZZ1 init structure...");
  rep->top_margin = -36.0;
  rep->bottom_margin = -36.0;
  rep->left_margin = -36.0;

  rep->page_length = -842.0;	/* A4 */
  rep->page_width = -595.0;	/* A4 */

  rep->right_margin = rep->page_width - (2 * rep->left_margin);

  rep->page_no = 0;
  rep->printed_page_no = 0;
  rep->line_no = 0.0;
  rep->col_no = 0.0;
  rep->output_mode = 'F';
  rep->font_size = 10;
  rep->paper_size = 0;
  rep->lines_in_header=0;
  rep->lines_in_first_header=0;
  rep->lines_in_trailer=0;
  strcpy (rep->font_name, "\"Helvetica\"");
  strcpy (rep->output_loc, "\"stdout\"");
}

/**
 *
 *
 * @param
 */
void
resize_paper (struct pdf_rep_structure *pdf_rep_struct)
{
  int portrait = 1;
  float a;

  A4GL_debug ("ZZ1 Fixing paper size.....");

  if (pdf_rep_struct->paper_size != 0)
    {

      if (pdf_rep_struct->paper_size < 0)
	{
	  portrait = 0;
	  pdf_rep_struct->paper_size = 0 - pdf_rep_struct->paper_size;
	}

      switch (pdf_rep_struct->paper_size)
	{
	case 1:
	  pdf_rep_struct->page_length = 0 - a4_height;
	  pdf_rep_struct->page_width = 0 - a4_width;
	  break;
	case 2:
	  pdf_rep_struct->page_length = 0 - letter_height;
	  pdf_rep_struct->page_width = 0 - letter_width;
	  break;
	case 3:
	  pdf_rep_struct->page_length = 0 - legal_height;
	  pdf_rep_struct->page_width = 0 - legal_width;
	  break;

	case 4:		/* Not used.... */
	  pdf_rep_struct->page_length = 0 - a4_height;
	  pdf_rep_struct->page_width = 0 - a4_width;
	  break;

	case 5:
	  pdf_rep_struct->page_length = 0 - a5_height;
	  pdf_rep_struct->page_width = 0 - a5_width;
	  break;

	}
    }


  if (portrait == 0)		/* Its landscape - swap it around.... */
    {
      a = pdf_rep_struct->page_length;
      pdf_rep_struct->page_length = pdf_rep_struct->page_width;
      pdf_rep_struct->page_width = a;
    }

}

/**
 *
 *
 * @param
 */
int
scan_orderby (char *varname, int cnt)
{
  int a;
char b1[256];
char b2[256];
  A4GL_debug ("Scanning order by for %s %d", varname, ordbindcnt);
  for (a = 0; a <= cnt; a++)
    {
	strcpy(b1,varname);
	if (b1[0]>='A'&&b1[0]<='Z'&&b1[1]=='_') { strcpy(b1,&varname[2]); }
	strcpy(b2,ordbind[a].varname);
	if (b2[0]>='A'&&b2[0]<='Z'&&b2[1]=='_') { strcpy(b2,&ordbind[a].varname[2]); }
      A4GL_debug ("/* chk %s against %s */\n", varname, ordbind[a].varname);
      if (A4GL_aubit_strcasecmp (b1, b2) == 0)
	return a;
    }
  return -1;
}

/**
 *
 *
 * @param
 */
void
reset_attrib (struct form_attr *form_attrib)
{
  A4GL_debug ("Reseting attributes\n");
  form_attrib->iswindow = 0;

  form_attrib->attrib = 0xffff;

  form_attrib->form_line = 0xff;
  form_attrib->error_line = 0xff;
  form_attrib->comment_line = 0xff;
  form_attrib->message_line = 0xff;
  form_attrib->prompt_line = 0xff;
  form_attrib->menu_line = 0xff;

  form_attrib->border = 0;
}


/**
 *
 *
 * @param
 */
int
attr_code (char *s)
{

  A4GL_debug ("Decoding colour %s\n", s);

  return A4GL_get_attr_from_string (s);

}

/**
 * Breaks the file name to take the file name without extension and dir name
 *
 * Its used to separate column names from tablename too.
 *
 * This function is repeated in severall places.
 *
 * @param str The file name
 * @param str1 A pointer to the place where to return the left part.
 * @param str2 A pointer to the place where to return the right part.
 */
/*
static
A4GL_bname (char *str, char *str1, char *str2)
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
*/

/**
 * Not Used
 */
/*
static
get_single_key (char *s)
{
  char buff[2];
  s[0] = s[1];
  s[1] = 0;
}
*/

/**
 *
 *
 * @param
 */
void
set_mod_level (int a)
{
  modlevel = a;
}

#ifdef NOLONGERREQD
/**
 *
 *
 * @param
 */
static int
matoi (char *s)
{
  int a;
  if (s == 0)
    return 0;
  a = atoi (s);
  return a;
}
#endif

/**
 *
 *
 * @param
 */
void
drop_counter (void)
{
  count_counters--;
}

/**
 *
 *
 * @param
 */
void
new_counter (void)
{
  count_counters++;
  counters[count_counters] = 0;
}

/**
 *
 *
 * @param
 */
int
get_counter_val (void)
{
  A4GL_debug ("/* get_counter_val =  %d counter number %d*/\n",
	 counters[count_counters], count_counters);
  return counters[count_counters];
}

/**
 *
 *
 * @param
 */
int
inc_counter (void)
{
  return ++counters[count_counters];
}

/**
 *
 *
 * @param
 */
int
dec_counter (void)
{
  return --counters[count_counters];
}

/**
 *
 *
 * @param
 */
void
reset_counter (void)
{
  counters[count_counters] = 0;
}

/**
 *
 *
 * @param
 */
void
set_counter (int a)
{
  counters[count_counters] = a;
}

/**
 *
 *
 * @param
 */
void
inc_counter_by (int a)
{
  counters[count_counters] += a;
  A4GL_debug ("/* inc_by =  %d counter number %d*/\n",
	 counters[count_counters], count_counters);
}

/**
 *
 *
 * @param
 */
/*
static void
dec_counter_by (int a)
{
  counters[count_counters] -= a;
}
*/

/**
 *
 *
 * @param
 */
static int
add_arr_bind (char i, char *nvar)
{
  long dtype;
  char var[256];


  if (isrecvariable (nvar))
    {
      strcat (nvar, "[0].*");
    }
  else
    {
      strcat (nvar, "[0]");
    }

        if (i=='f') strcpy(var,fgl_add_scope(nvar,'L'));
        else        strcpy(var,fgl_add_scope(nvar,0));
  dtype = scan_variable (var);

  A4GL_debug ("/* add_arr_bind %c %s %x */\n", i, var, dtype);

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
      if (dtype == -2) push_bind_rec (var, i);
      else
	{
	  strcpy (obind[obindcnt].varname, var);
	  obind[obindcnt].dtype = dtype;
	  obindcnt++;
	}
      return obindcnt;
    }
  if (i == 'e')
    {
      if (dtype == -2) push_bind_rec (var, i);
      else
	{
	  strcpy (ebind[ebindcnt].varname, var);
	  ebind[ebindcnt].dtype = dtype;
	  ebindcnt++;
	}
      return ebindcnt;
    }


  if (i == 'f' || i == 'F')
    {
      strcpy (fbind[fbindcnt].varname, var);
      fbind[fbindcnt].dtype = dtype;
      fbindcnt++;
      return fbindcnt;
    }

  return 0;
}


/**
 *
 *
 * @param
 */
void
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
  if (i == 'o') { obindcnt = 0; }
  if (i == 'e') { ebindcnt = 0; }
  if (i == 'f' || i == 'F')
    {
      fbindcnt = 0;
    }
  if (var != 0)
    add_arr_bind (i, var);
}



/**
 *
 *
 * @param
 */
void
push_construct (char *a, char *b)
{
  if (strcmp(b,"*")==0) {
	push_construct_table(a);
  } else {
  	strcpy (constr_buff[constr_cnt].tab, a);
  	strcpy (constr_buff[constr_cnt].col, b);
  	constr_cnt++;
  }
}




static int
push_construct_table (char *tableName)
{
  int rval;
  int isize = 0;
  int idtype = 0;
  char colname[256] = "";
  /*char csize[20];*/
  /*char cdtype[20];*/
  char buff[300];
  char *ccol;

  A4GL_debug ("push_construct_table()");
  A4GL_debug ("Calling get_columns : %s\n", tableName);
  rval = A4GLSQL_get_columns (tableName, colname, &idtype, &isize);
  A4GL_debug ("rval = %d", rval);
  if (rval == 0 && tableName)
    {
      sprintf (buff, "%s does not exist in the database", tableName);
      a4gl_yyerror (buff);
      return 1;
    }

  A4GL_debug ("Rval !=0");

  while (1)
    {
      colname[0] = 0;

      rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
      A4GL_debug ("next column for table '%p' is '%p'", tableName, ccol);
      A4GL_debug ("next column for table '%s' is '%s'", tableName, ccol);

      strcpy (colname, ccol);
      A4GL_trim(colname);
      /*
         warning: passing arg 1 of `A4GLSQL_next_column' from incompatible pointer type
         we are sending char ARRAY to function expecting char POINTER !!!!
       */

      if (rval == 0)
        break;

	push_construct(tableName,colname);
    }
  A4GLSQL_end_get_columns ();
  return 0;
}


/**
 *
 *
 * @param
 */
void
reset_constr (void)
{
  constr_cnt = 0;
}


/**
 *
 *
 * @param
 */
char *
convstrsql (char *s)
{
  static char buff[1024];
  int a;
  int b = 0;
  A4GL_debug ("Convstrsql ... %s", s);
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
  A4GL_debug ("Convstrsql ... %s => %s", s, buff);
  return buff;
}

/**
 * Upshift a string.
 *
 * @param a The string to be upshifted.
 * @return A static buffer with a copy of the string upshifted.
 */
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

/**
 * Downshift a string.
 *
 * @param a The string to be downshifted.
 * @return A pointer to a staic buffer where the string downshifted is putted.
 */
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

/**
 * Obtain the current report block.
 *
 * @return The current block.
 */
static int
get_curr_block (void)
{
  return curr_rep_block;
}

/**
 * Add a report ???
 *
 * @param t
 * @param s1
 * @param s2
 * @param a
 *
 * @return
 */
int
add_report_agg (char t, struct expr_str *s1, struct expr_str *s2, int a)
{

  A4GL_debug ("In add_report_agg a=%d\n", a);
  if (use_group)
    {
      sreports[sreports_cnt].in_b = get_curr_block ();
    }
  else
    {
      sreports[sreports_cnt].in_b = 0;
    }

  if (s2 == 0)
    {

      A4GL_debug ("Adding default where on report aggregate of 1");
      sreports[sreports_cnt].rep_where_expr = A4GL_new_expr ("A4GL_push_int(1);");
    }
  else
    {
      A4GL_debug ("Adding non-default where on report aggregate");
      sreports[sreports_cnt].rep_where_expr = s2;
    }


  sreports[sreports_cnt].rep_cond_expr = s1;

  sreports[sreports_cnt].a = a;

  sreports[sreports_cnt].t = t;

  sreports_cnt++;

  if (t == 'C')
    {
      A4GL_lex_printh ("static long _g%d=0;\n", a);
      return 1;
    }

  if (t == 'P')
    {
      A4GL_lex_printh ("static long _g%d=0,_g%d=0;\n", a, a + 1);
      return 2;
    }

  if (t == 'S')
    {
      A4GL_lex_printh ("static double _g%d=0;\n", a);
      return 1;
    }

  if (t == 'N' || t == 'X')
    {
      A4GL_lex_printh ("static double _g%d=0;\n", a);
      A4GL_lex_printh ("static int _g%dused=0;\n", a);
      return 1;
    }

  if (t == 'A')
    {
      A4GL_lex_printh ("static double _g%d=0;\n", a);
      A4GL_lex_printh ("static long   _g%d=0;\n", a + 1);
      return 2;
    }
  use_group = 0;
  return -1;
}

/**
 * Generate the name for the current report.
 *
 * It is generated with an aubit4gl specific namespace.
 *
 * @param s The name of the report in the 4gl source
 */
void
set_curr_rep_name (char *s)
{
  strcpy (curr_rep_name, (char *) get_namespace (s));
  strcat (curr_rep_name, s);
}

/**
 * Obtain the current report name.
 *
 * @return The name of the report.
 */
char *
get_curr_rep_name (void)
{
  return curr_rep_name;
}

/**
 * Assigns the flag that tells that we are inside a group.
 */
void
set_ingroup (void)
{
  use_group = 1;
}


char *whentostore_p;
int whenever_store_c;
char * whenever_store_p;



void set_whento_store(char *p) {
	if (p) whentostore_p=strdup(p);
	else whentostore_p=0;
}



/**
 *
 */
void set_whento (char *p)
{
  A4GL_debug ("whento = %p", p);
  strcpy (when_to_tmp, p);
}

void set_whenever_store (int c, char *p) {
	whenever_store_c=c;
	if (p) whenever_store_p=strdup(p);
	else whenever_store_p=0;
}

/**
 * Define the error handling after a certain point of the program.
 *
 * @param c The event to be catched:
 *  - WHEN_ERROR:
 *  - WHEN_ANYERROR:
 *  - WHEN_SQLERROR:
 *  - WHEN_WARNING:
 *  - WHEN_SQLWARNING:
 *  - WHEN_NOTFOUND:
 *  - WHEN_SUCCESS:
 *  - WHEN_SQLSUCCESS:
 * @param p The A4GL_action to execute.
 */
void set_whenever (int c, char *p)
{
  int code;
  int oldcode;
  oldcode = c & 15;
  c = c >> 4;
  c = c << 4;
  code = -1;
  switch (c)
    {
    case WHEN_ERROR:
      set_whenever (WHEN_SQLERROR, p);
      code = A_WHEN_ERROR;
      break;

    case WHEN_ANYERROR:
      set_whenever (WHEN_ERROR, p);
      set_whenever (WHEN_SQLERROR, p);
      code = A_WHEN_ERROR;
      break;

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
      a4gl_yyerror ("Internal error setting whenever error...");
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

  print_clr_status ();
}


void set_whenever_from_store(void) {
	set_whento(whentostore_p);
	set_whenever(whenever_store_c,whenever_store_p);
}


/**
 *
 *
 * @param
 */
int
npush_menu (void)
{
  max_menu_no++;
  cmenu++;
  menu_nos[cmenu] = max_menu_no;
  A4GL_debug ("Menu no %d", max_menu_no);
  return max_menu_no;
}

/**
 *
 *
 * @param
 */
void
pop_menu (void)
{
  cmenu--;
  if (cmenu >= 0)
    {
      menu_cnt = menu_nos[cmenu];
      A4GL_debug ("Reset Menu no %d", menu_cnt);
    }
  else
    {
      A4GL_debug ("Nothing to reset to...");
    }
}

/**
 *
 *
 * @param
 */
int
setrecord (char *s, char *t, char *c)
{
  return 0;
}

/**
 * Escape special characters in a string copying it to another.
 *
 * Escape \,",' with a \
 *
 * @param d A pointer to he destination string
 * @param s A pointer to the origin string.
 */
/*
static void
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
  A4GL_debug ("Converted : %s to %s", s, d);
}
*/

/**
 * Check the number of dimentions in the array declaration string
 *
 * @param s A pointer to the string with array declaration.
 * @return The number of dimentions.
 */
int
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

/**
 *
 *
 * @param
 */
char *
change_arr_elem (char *s)
{
  static char buff[1024];
  int a;
  char buff2[2];
  buff2[1] = 0;
  buff[0] = 0;
  strcpy (buff, "(");
  A4GL_debug ("change_arr_elem: %s", s);
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
  A4GL_debug ("Generated... %s", buff);
  return buff;
}

/**
 * Executed at the end of the parsing process by bison.
 */
int
yywrap (void)
{
  return 1;
}

/**
 * Check if a string is one of the internal variables: today,time,user,date
 *
 * @param s The string to be checked.
 * @return 
 *   - 1 : Is an internal variable.
 *   - 0 : Otherwise
 */
int
system_var (char *s)
{
  if (A4GL_aubit_strcasecmp (s, "today") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "time") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "user") == 0)
    return 1;
  if (A4GL_aubit_strcasecmp (s, "date") == 0)
    return 1;
  return 0;
}

/**
 * Increment the number of reports declared.
 */
void
inc_report_cnt (void)
{
  sreports_cnt = 0;
  report_cnt++;
  report_stack_cnt = 0;
}

/**
 * Escape the quotes in a string with backslash.
 *
 * @param s The string to be checked.
 * @return A pointer to a static buffer with the escaped string.
 */
/*
static char *
trans_quote (char *s)
{
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
*/


/**
 * Split a string into pieces, 
 *
 * @param s The input string
 * @param a
 * @param buff A pointer to the buffer where the result is putted.
 * @return 
 *   - if a=0 return the number of pieces
 *   - if a=1 then return the first into buffetc...
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
  A4GL_debug ("linked_split %s %d %p", s, a, buff);
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
		  A4GL_debug ("Linked found:%s", p);
		  return 1;
		}
	      p = &buffer[z + 1];
	    }
	}
    }
  return 0;
}

/**
 * Copy a value to the primary key list.
 *
 * @param s The string to be copied.
 */
void
set_pklist (char *s)
{
  A4GL_debug ("pklist set to %s\n", s);
  strcpy (pklist, s);
  strcpy (upd_using_notpk, "");
  upd_using_notpk_cnt = 0;
}

/**
 *
 *
 * @param
 */
char *
get_upd_using_notpk (void)
{
  A4GL_debug ("get_upd_using_notpk");
  A4GL_debug ("Returning %s", upd_using_notpk);
  return upd_using_notpk;
}

/**
 *
 *
 * @param
 */
char *
get_upd_using_queries (void)
{
  static char buff[2000];
  int a;
  A4GL_debug ("get_upd_using_???");
  strcpy (buff, "");

  for (a = 0; a < upd_using_notpk_cnt; a++)
    {
      if (strlen (buff) > 0)
	strcat (buff, ",");
      strcat (buff, "?");
    }
  A4GL_debug ("Returning %s", buff);
  return buff;

}

/**
 * Check if the current report is a pdf one.
 *
 * @todo : The rep type is never assigned.
 *
 * @return 
 *   - An empty string if is a normal report 
 *   - pdf_ Otherwise
 */
char *
ispdf (void)
{
  if (rep_type == REP_TYPE_NORMAL)
    return "";
  else
    return "pdf_";
}


/**
 *
 * When you've got a function definition which includes a record
 * You don't know when adding to the binding the structures involved
 * This copies the original binding and reapplies them.
 * This should be called after the structure is known - ie. just before you
 * want to print it !
 *
 * @param bind A pointer to the bind structure.
 * @param btype The type of the bind:
 *   - i : Input bind.
 *   - N : Null bind.
 *   - o : Output bind.
 *   - O
 *   - f or F :
 * @param cnt The number of elements in the bind array.
 */
void expand_bind (struct binding_comp *bind, int btype, int cnt)
{
  char buff[256];
  int b1;
  /*int b2;*/
  /*int b3;*/
  int dim;
  int xxxa;
  static struct binding_comp *save_bind=0;

  xxxa=0;

  if (cnt==0) return; /* theres nothing there to expand */

  save_bind=realloc(save_bind,sizeof(struct binding_comp)*cnt);
  for (xxxa = 0; xxxa < cnt; xxxa++)
    {
      strcpy (save_bind[xxxa].varname, bind[xxxa].varname);
      save_bind[xxxa].dtype = bind[xxxa].dtype;
    }

  start_bind (btype, 0);

  for (xxxa = 0; xxxa < cnt; xxxa++)
    {
      strcpy (buff, save_bind[xxxa].varname);



	dim=1;
        if (A4GL_isyes(acl_getenv("NO_ARRAY_EXPAND"))) dim=0; 
	if (strncmp(buff," a4gl_let_substr",16)==0) dim=0;
	if (strncmp(buff," ASSOCIATE",10)==0) dim=0;


	if (dim)   {
      		if (isarrvariable (buff)&&buff[strlen(buff)-1]!=']'&&buff[strlen(buff)-2]!=']' && dim==1) { 
         		int type,arrsize,size,level;
         		char buff2[256];
         		char arrbuff[256];
		
		
	/*printf("Warning: Using an array at this point may not be supported (%s) @ line %d\n",buff,yylineno); */
 		/*printf("GET1 : %s\n",buff);*/
        		get_variable_dets (buff,&type,&arrsize,&size,&level,arrbuff);
			for (b1=0;b1<arrsize;b1++) {
				sprintf(buff2,"%s[%d]",buff,b1);
      				if (scan_variable (buff2) == -2) { strcat (buff2, ".*"); }
      				add_bind (btype, buff2);
			}
			continue;
      		}
	}

      if (scan_variable (buff) == -2) { strcat (buff, ".*"); }
      add_bind (btype, buff);
    }

}

/**
 * Expandthe output bind
 */
void
expand_obind (void)
{
  expand_bind (obind, 'o', obindcnt);
}


/**
 *
 * @param s
 */
void
chk_init_var (char *s)
{
  char buff[1024];
  char *ptr;

  if (strcmp (s, "") == 0)
    return;

  strcpy (buff, s);
  ptr = strchr (buff, '.');
  if (strchr (buff, '['))
    {				/* This need fixing */
/* This should check for arrays within arrays...
 but this doesn't
*/
      return;
    }

  if (ptr == 0)
    {
      if (isarrvariable (s))
	{
	  printf ("Warning: Only initializing first element in array %s\n",
		  s);
	  strcat (s, "[0]");
	  return;
	}
      else
	{
	  return;
	}
    }


  *ptr = 0;
  if (isarrvariable (buff))
    {
      char buff[1024];
      char *ptr;
      printf ("Warning: Only initializing first element in array %s\n", s);
      strcpy (buff, s);
      ptr = strchr (s, '.');
      *ptr = 0;
      strcat (s, "[0].");

      ptr = strchr (buff, '.');
      A4GL_debug ("ptr=%s\n", ptr);
      ptr++;
      strcat (s, ptr);
    }

}

/**
 * Dump an expression if in A4GL_debug mode.
 *
 * @param orig_ptr A pointer to the expression list
 */
void
dump_expr (struct expr_str *orig_ptr)
{
  struct expr_str *start;
  start = orig_ptr;

  A4GL_debug ("DUMP EXPR : ");
  while (orig_ptr)
    {
      A4GL_debug ("     %s", orig_ptr->expr);
      orig_ptr = orig_ptr->next;
    }
  A4GL_debug ("---------------------------------------------------");
}


#ifdef MOVED_TO_LIBAUBIT4GL
/**
 * Allocate space and create a new expression structure.
 *
 * @param value The value to be added to the expression.
 * @return A pointer to the allocated expression.
 */
void *
A4GL_new_expr (char *value)
{
  struct expr_str *ptr;
  A4GL_debug ("new_expr - %s", value);
  ptr = malloc (sizeof (struct expr_str));
  ptr->next = 0;
  ptr->expr = strdup (value);
  A4GL_debug ("newexpr : %s -> %p\n", value, ptr);
  /*dump_expr(ptr);*/
  return ptr;
}

/**
 * Insert a new value to the expression.
 *
 * @param orig_expr
 * @param value 
 * @return 
 */
void *
A4GL_append_expr (struct expr_str *orig_ptr, char *value)
{
  struct expr_str *ptr;
  struct expr_str *start;
  start = orig_ptr;

  A4GL_debug ("MJA A4GL_append_expr %p (%s)", orig_ptr, value);

  ptr = A4GL_new_expr (value);
  if (orig_ptr->next != 0)
    {
      while (orig_ptr->next != 0)
	orig_ptr = orig_ptr->next;
    }
  orig_ptr->next = ptr;
  A4GL_debug ("Appended expr");
  /*dump_expr(start);*/
  return start;
}
#endif

/**
 * Insert a new expression at the end of anoher one.
 *
 * @param orig_ptr The expression to be appended.
 * @param second_ptr The expression to append.
 */
void *
A4GL_append_expr_expr (struct expr_str *orig_ptr, struct expr_str *second_ptr)
{
  struct expr_str *start;
  A4GL_debug ("MJA A4GL_append_expr_expr %p %p", orig_ptr, second_ptr);
  start = orig_ptr;
  if (orig_ptr->next != 0)
    {
      while (orig_ptr->next != 0)
	orig_ptr = orig_ptr->next;
    }
  orig_ptr->next = second_ptr;
  /*dump_expr(start);*/
  return start;
}

/**
 * Checks and return the length of an expression
 *
 * @param ptr
 * @return The number of operands in an expression
 */
int
length_expr (struct expr_str *ptr)
{
  int c = 0;
  A4GL_debug ("Print expr... %p", ptr);
  while (ptr)
    {
      c++;
      ptr = ptr->next;
    }
  return c;
}


/**
 * This is something internal for Mike?
 * It's called from main.rule, in function file_name, for GLOBALS file names
 * @param s
 */
void
tr_glob_fname (char *s)
{
  int a;
  for (a = 0; a <= strlen (s); a++)
    {
      if (s[a] == '\\')
	s[a] = '/';

#ifdef MIKES_WORKAROUND_FOR_FILES_COPY_FROM_WINDOWS
      s[a] = tolower (s[a]);
#endif
    }
}

char
get_curr_report_stack_whytype_1 (void)
{
  return report_stack[report_stack_cnt-1].whytype;
}

char
get_curr_report_stack_whytype (void)
{
  return report_stack[report_stack_cnt].whytype;
}


char*
get_curr_report_stack_why (void)
{
  return report_stack[report_stack_cnt].why;
}



/* folowing functions are to work around problem with exporting struct in Windows dll */

/**
 *
 *
 * @param
 */
char 
get_report_stack_whytype (int a)
{
  return report_stack[a].whytype;
}

/**
 *
 *
 * @param
 */
char *
get_report_stack_why (int a)
{
  return report_stack[a].why;
}

/**
 *
 *
 * @param
 */
struct sreports *
get_sreports (int z)
{
  return (struct sreports *) z;
}


/**
 *
 *
 * @param
 */
void
add_ex_dtype (char *sx)
{
  char s[256];
  char ss[256];
  strcpy (s, sx);
  A4GL_trim (s);
  strcpy (s, downshift (s));
  A4GL_debug ("Initializing datatype : %s\n");

  A4GLEXDATA_initlib (s);

  A4GL_debug ("Checking if we need an extra include...");

  if (A4GL_has_datatype_function_n (s, "INCLUDE"))
    {
      /* char *(*function) (); */
      char *(*function) (void);
      A4GL_debug ("yep");

      function = A4GL_get_datatype_function_n (s, "INCLUDE");

      A4GL_debug ("function=%s\n", function);

      strcpy (ss, function ());
      print_include (ss);
    }
}

/**
 *
 *
 * @param
 */
char *
subtract_one (char *s)
{
  static char buff[256];
  int a;
  int c;

  c = 0;
  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == ',')
	{
	  buff[c++] = '-';
	  buff[c++] = '1';
	}
      buff[c++] = s[a];
    }
  buff[c++] = '-';
  buff[c++] = '1';
  buff[c] = 0;
  return buff;
}

/**
 * @param mode If mode is set to 1 - expect a '*' as column names...
*/
char *
fix_update_expr (int mode)
{
  static char big_buff[20000];
  int a;
  int rval;
  int isize = 0;
  int idtype = 0;
  char colname[256] = "";
  /*char csize[20];*/
  /*char cdtype[20];*/
  char buff[1000];
  char *ccol;
  strcpy (big_buff, "SET ");


  if (mode == 1)
    {
      /* It will only be a '*' anyway....*/
      if (db_used == 0)
	{
	  sprintf (buff,
		   "You cannot use update * =  without specifying a database");
	  a4gl_yyerror (buff);
	  return 0;
	}

      gen_stack_cnt[UPDCOL] = 0;

      strcpy (colname, "");
      rval =
	A4GLSQL_get_columns (current_upd_table, colname, &idtype, &isize);
      if (rval == 0)
	{
	  a4gl_yyerror ("Table is not in the database");
	  return 0;
	}


      while (1)
	{
	  colname[0] = 0;
	  rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
	  strcpy (colname, ccol);
	  if (rval == 0)
	    break;
	  trim_spaces (colname);
	  push_gen (UPDCOL, colname);
	}
      A4GLSQL_end_get_columns ();
    }

  if (gen_stack_cnt[UPDCOL] != gen_stack_cnt[UPDVAL])
    {
dump_updvals();
      a4gl_yyerror
	("Number of columns in update not the same as number of values");
    }

  for (a = 0; a < gen_stack_cnt[UPDCOL]; a++)
    {
      if (a)
	strcat (big_buff, ",");
      sprintf (buff, "%s=%s", gen_stack[UPDCOL][a], gen_stack[UPDVAL][a]);
      strcat (big_buff, buff);
    }

  return big_buff;
}



char *
make_sql_string_and_free (char *first, ...)
{
  va_list ap;
  char *ptr = 0;
  int l;
  char *next;
  int n;

	extern char *kw_space;
	extern char *kw_comma;
	extern char *kw_ob;
	extern char *kw_cb;

  n = 0;
  va_start (ap, first);
  ptr = strdup (first);


	if (first!=kw_comma && first!=kw_space && first!=kw_ob && first!=kw_cb) {
		A4GL_debug("FREE %p (%s)\n",first,first); 
		if (A4GL_isyes(acl_getenv("FREE_SQL_MEM"))) {
			free(first);
		}
			first=0;
	}
  l = strlen (ptr);

  while (1)
    {
      n++;
      next = va_arg (ap, char *);
      if (next == 0)
	break;
      l += strlen (next);
      l++;			/* Extra space...*/
      ptr = realloc (ptr, l);
      strcat (ptr, next);
	if (next!=kw_comma && next!=kw_space && next!=kw_ob && next!=kw_cb) {
		A4GL_debug("FREE %p (%s)\n",next,next); 
		if (A4GL_isyes(acl_getenv("FREE_SQL_MEM"))) {
			free(next);
		}
	}
    }
  A4GL_debug("Generated : %s\n",ptr);
  return ptr;
}

char *
pg_make_sql_string_and_free (char *first, ...)
{
  va_list ap;
  char *ptr = 0;
  int l;
  char *next;
  int n;
  n = 0;
  va_start (ap, first);
  ptr = strdup (first);


  if (A4GL_isyes(acl_getenv("FREE_SQL_MEM"))) {
	free(first);
  }
  first=0;
  l = strlen (ptr);

  while (1)
    {
      n++;
      next = va_arg (ap, char *);
      if (next == 0)
	break;
      l += strlen (next);
      l+=3;			/* Extra space...*/
      ptr = realloc (ptr, l);
	if (strlen(ptr)) {
		if (!ispunct(ptr[strlen(ptr)-1])) {
			strcat(ptr," ");
		}	
	}

      strcat (ptr, next);
      if (A4GL_isyes(acl_getenv("FREE_SQL_MEM"))) {
			free(next);
      }
    }
  A4GL_debug("Generated : %s\n",ptr);
  return ptr;
}


void
dump_updvals ()
{
  int a;
  for (a = 0; a < gen_stack_cnt[UPDCOL]; a++)
    {
      printf ("UPDCOL[%d] : %s\n", a, gen_stack[UPDCOL][a]);
    }

  for (a = 0; a < gen_stack_cnt[UPDVAL]; a++)
    {
      printf ("UPDVAL[%d] : %s\n", a,gen_stack[UPDVAL][a]);
    }
  for (a = 0; a < gen_stack_cnt[UPDVAL2]; a++)
    {
      printf ("UPDVAL2[%d]: %s\n", a,gen_stack[UPDVAL2][a]);
    }
}


void do_print_menu_1(void) {
	print_menu_1(get_blk_no());
	print_menu_1b(get_blk_no());
}

void do_print_menu_block_end(void) {
	print_menu_block_end(get_blk_no());
}

int get_blk_no() {
	return command_stack[ccnt-1].block_no;
}


struct s_exchange_clobber {
	char *orig;
	char *new;
	char *important;
};

struct s_exchange_clobber *clob_arr=0;
int clob_arr_cnt=0;

static int has_clobber(char *s) {
	int a;
	if (clob_arr_cnt==0) return 0;
	for (a=0;a<clob_arr_cnt;a++) {
		if (strcmp(clob_arr[a].orig,s)==0) {
			return 1;
		}
	}
	return 0;
}


static char *get_clobber(char *s) {
	int a;
	if (clob_arr_cnt==0) return 0;
	for (a=0;a<clob_arr_cnt;a++) {
		if (strcmp(clob_arr[a].orig,s)==0) {
			return clob_arr[a].new;
		}
	}
return "";
}

char *A4GL_get_important_from_clobber(char *s) {
	int a;
	if (clob_arr_cnt==0) return 0;
	for (a=0;a<clob_arr_cnt;a++) {
		if (strcmp(clob_arr[a].orig,s)==0) {
			return clob_arr[a].important;
		}
	}
return "";
}
char *A4GL_get_clobber_from_orig(char *s) {
	int a;
	if (clob_arr_cnt==0) return 0;
	for (a=0;a<clob_arr_cnt;a++) {
		if (strcmp(clob_arr[a].new,s)==0) {
			return clob_arr[a].orig;
		}
	}
return "";
}


static char *add_clobber(char *buff_orig,char *important) {
static char buff_new[256];
static int p=0;
char b1[256];
/*printf("add clobber : %s %s\n",buff_orig,important);*/
	strcpy(buff_new,buff_orig);

	if (has_clobber(buff_orig)) return get_clobber(buff_orig);

	clob_arr_cnt++;
	clob_arr=realloc(clob_arr,sizeof(struct s_exchange_clobber)*clob_arr_cnt);
	if (clob_arr==0) {
		a4gl_yyerror("Unable to allocate buffer...");
		return 0;
	}



	if (strlen(buff_orig)<=20) { /* Extra 2 for the quotes...*/
		clob_arr[clob_arr_cnt-1].orig=strdup(buff_orig);
		clob_arr[clob_arr_cnt-1].new=strdup(buff_new);
		clob_arr[clob_arr_cnt-1].important=strdup(important);
		return buff_orig;
	}

	strcpy(b1,important);
	b1[9]=0;
	sprintf(buff_new,"\"a4gl_%03d_%s\"",p++,b1);
	clob_arr[clob_arr_cnt-1].orig=strdup(buff_orig);
	clob_arr[clob_arr_cnt-1].new=strdup(buff_new);
	clob_arr[clob_arr_cnt-1].important=strdup(important);
	return buff_new;
}

char *do_clobbering(char *f,char *s) {
static char buff[256];
	if (A4GL_isyes(acl_getenv("NOCLOBBER"))) {
		/*printf("NOCLOBBER : %s\n",s);*/
		sprintf(buff,"\"%s\"",s);
		return buff;
	}

	sprintf(buff,"\"%s_%s\"",f,s);

	if (A4GL_isyes(acl_getenv("ALWAYSCLOBBER"))) {
		return buff;
	}

	if (has_clobber(buff)) {
		return get_clobber(buff);
	}
	return add_clobber(buff,s);
}


char *
fgl_add_scope (char *s, int n)
{
  char c;
  static char buffer[256];
  char buffer2[1024];

//printf("ADD SCOPE : %s\n",s);
  if (strncmp(s,"CLASS_COPY->",12)==0) return s;
//printf("Not class_copy\n");

  strcpy (buffer2, s);
  c = find_variable_scope (buffer2);

  if (c == 'C' || c=='P');
  else
    {
	//printf("c!='C'");
      if (!A4GL_isyes (acl_getenv ("MARK_SCOPE")))
	{
	  return s;
	}
    }


  if (buffer2[0] >= 'A' && buffer2[0] <= 'Z' && buffer2[1] == '_')
    {
      char buff[1024];
      strcpy (buff, &buffer2[2]);
      strcpy (buffer2, buff);
    }



  if (n == 0)
    {
      if (buffer2[0] == ' ')
	{
	  c = 'S';
	}
      else
	{
	  c = find_variable_scope (buffer2);
	  if (c == 0)
	    {
	      c = 'S';
	    }
	}
    }
  else
    {
      c = n;
    }


//printf("c=%c\n",c);
  if (c != 'S') {
		if (c=='C'||c=='P') {
			if (c=='C')  {
    			sprintf (buffer, "CLASS_COPY->%s",  buffer2);
			} else {
			find_variable_ptr (buffer2);
    			sprintf (buffer, "CLASS_COPY->%s",  get_last_class_var());
			}
		} else {
    			sprintf (buffer, "%c_%s", c, buffer2);
		}
	}
  else
    sprintf (buffer, "%s", buffer2);

  return buffer;
}

int rep_no_orderby=0;

void set_rep_no_orderby(int n) {
	rep_no_orderby=n;
}

int get_rep_no_orderby(void) {
	return rep_no_orderby;
}

struct s_validate {
	char tabname[65];
	char colname[65];
	struct expr_str *expr;
};

struct s_validate *validate_list=0;
int validate_list_cnt=0;

int get_validate_list_cnt(void) {
/*int a;*/
	/*printf("Return count : %d\n",validate_list_cnt);*/
/*for (a=0;a<validate_list_cnt;a++) {*/
	/*printf("   %s %s %p\n",validate_list[a].tabname,validate_list[a].colname,validate_list[a].expr);*/
/*}*/
	return validate_list_cnt;
}
	
void clr_validate_list(void) {
	/*printf("Clear list\n");*/
	if (validate_list) free(validate_list);	
	validate_list_cnt=0;
	validate_list=0;
}

static void push_validate_column(char *tabname,char *colname) {
	validate_list_cnt++;
	/*printf("Add to list %s %s\n",tabname,colname);*/
	validate_list=realloc(validate_list,sizeof(struct s_validate)*validate_list_cnt);
	/*A4GL_trim(tabname);*/
	/*A4GL_trim(colname);*/
	strcpy(validate_list[validate_list_cnt-1].tabname,tabname);
	strcpy(validate_list[validate_list_cnt-1].colname,colname);

	validate_list[validate_list_cnt-1].expr=A4GLSQL_get_validation_expr(tabname,colname);
	if (validate_list[validate_list_cnt-1].expr==(void *)-1) {
		a4gl_yyerror("Unable to get validation information - does A4GL_SYSCOL_VAL exist ?");
	}

	/*printf("-->%p (%d)\n",validate_list[validate_list_cnt-1].expr,validate_list_cnt-1);*/
	/*printf("%d elements\n",length_expr(validate_list[validate_list_cnt-1].expr));*/
	
}

struct expr_str *A4GL_get_validate_expr(int n) {
	/*printf("-->%p for %d\n",validate_list[n].expr,n);*/
	return validate_list[n].expr;
}


struct s_event {
	int n;
	char *s;
};

struct s_event_list {
	int nevents;
	struct s_event *events;
};

struct s_event_list event_queue[255];
int nevent_queue=-1;

void A4GL_new_events(void) {
	nevent_queue++;
	event_queue[nevent_queue].nevents=0;
	event_queue[nevent_queue].events=0;
}

void A4GL_drop_events() {
int a;
	if (event_queue[nevent_queue].events) {
		if (event_queue[nevent_queue].nevents) {
			for (a=0;a<event_queue[nevent_queue].nevents;a++) {
				free(event_queue[nevent_queue].events[a].s);
			}
		}
		free(event_queue[nevent_queue].events);
	}
	event_queue[nevent_queue].nevents=0;
	event_queue[nevent_queue].events=0;
	nevent_queue--;
}

void A4GL_add_onkey_key(char *s) {
	//printf("ADD EVENT 90 : %s\n",s);
	A4GL_add_event(-90,s);
}

void A4GL_add_event(int n,char *s) {
	/*printf("Add Event : %d %s\n",n,s);*/
	event_queue[nevent_queue].nevents++;
	event_queue[nevent_queue].events=realloc(event_queue[nevent_queue].events,sizeof(struct s_event)*event_queue[nevent_queue].nevents);
	event_queue[nevent_queue].events[event_queue[nevent_queue].nevents-1].n=n;
	event_queue[nevent_queue].events[event_queue[nevent_queue].nevents-1].s=strdup(s);
}

int A4GL_get_nevents(void) {
	/*printf("nevents=%d\n", event_queue[nevent_queue].nevents);*/
	return event_queue[nevent_queue].nevents;
}

void A4GL_get_event(int n,int *i,char **s) {
	/*printf("getevent : %d\n", n);*/
	*i=event_queue[nevent_queue].events[n].n;
	*s=event_queue[nevent_queue].events[n].s;
}


void A4GL_copy_fbind_to_Obind(void) {
//printf("Copying fbind %d %d\n",fbindcnt,ordbindcnt);
memcpy(ordbind,fbind,sizeof(struct binding_comp)*fbindcnt);
ordbindcnt=fbindcnt;
}



/* 
   Translate from the directory name for the SQLPACK to the
   logical name used for translating...
*/
char *A4GL_decode_packtype(char *s) {
	if (strcmp(s,"infx")==0) return "INFORMIX";
	if (strcmp(s,"postgres")==0) return "POSTGRES";

	return s;
}


void A4GL_add_feature(char *feature) {
	/* Reserved for future use */
}



void A4GL_CV_print_exec_sql(char *s) {
	char *ptr;
	ptr=A4GLSQLCV_check_sql(s);
	print_exec_sql(ptr);
}


void A4GL_CV_print_exec_sql_bound(char *s) {
	char *ptr;
	ptr=A4GLSQLCV_check_sql(s);
	print_exec_sql_bound(ptr);
}

void A4GL_CV_print_do_select(char *s) {
	print_do_select(A4GLSQLCV_check_sql(s));

}


char *A4GL_CV_print_select_all(char *s) {
	return print_select_all(A4GLSQLCV_check_sql(s));
}


int A4GL_escape_quote_owner(void) {
	if (A4GLSQLCV_check_requirement("QUOTE_OWNER")) {return 1;}
	if (A4GLSQLCV_check_requirement("NO_OWNER_QUOTE")) {return 0;}
	if (strcmp(acl_getenv("A4GL_LEXTYPE"),"EC")==0)  return 0;
	return 1;
}


#ifdef MOVED
char *A4GL_datetime_value(char *s) {
static char buff[256];
if (strncasecmp(s,"DATETIME(",9)==0) {
	if (s[9]!='"') {
		if (A4GLSQLCV_check_requirement("QUOTE_DATETIME")) {
			char *ptr;
			ptr=strdup(&s[9]);
			ptr[strlen(ptr)-1]=0;
			sprintf(buff,"DATETIME(\"%s\")",ptr);
			free(ptr);
			return buff;
		}
	}

}
return s;
}

char *A4GL_interval_value(char *s) {
static char buff[256];
if (strncasecmp(s,"INTERVAL(",9)==0) {
	if (s[9]!='"') {
		if (A4GLSQLCV_check_requirement("QUOTE_INTERVAL")) {
			char *ptr;
			ptr=strdup(&s[9]);
			ptr[strlen(ptr)-1]=0;
			sprintf(buff,"INTERVAL(\"%s\")",ptr);
			free(ptr);
			return buff;
		}
	}

}
return s;
}
#endif




/* ================================= EOF ============================= */
