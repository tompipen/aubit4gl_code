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
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: mod.c,v 1.276 2006-07-04 14:22:32 mikeaubury Exp $
#
*/

/**
 * @file
 * It looks like functions to help the parsing of a module (a x4gl one).
 * For that the name mod.c
 *
 * @todo Doxygen comments in all functions
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
#include "field_handling.h"
#include <errno.h>
#define GEN_STACK_HERE
#include "a4gl_gen_stack.h"
#define FEATURE_USED            'X'

extern char force_ui[];
/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define USE_PRINTCOMMENT
#define GEN_STACKS 		10
#define MAXVARS 		2000
#define EMPTY 			"----"
//#define MAXMENU               50
//#define MAXMENUOPTS   50

#define UPDCOL 0
#define UPDVAL 1
#define UPDVAL2 4
#define INSCOL 5
#define INSVAL 6
#define TCOL 7

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

int ui_elements = 0;
int arr_ui_elements[2000];
struct s_replacements
{
  char *find;
  char *replace;
};
struct s_replacements *replacements = 0;
int nreplacements = 0;

static void A4GL_set_sql_features (void);

int A4GL_get_nevents (void);
void A4GL_get_event (int n, int *i, char **s);
//static void set_whento (char *p);
//void set_whento_store(char *p);
//void set_whenever_store (int c, char *p) ;
//void set_whenever_from_store(void) ;
//void A4GL_lex_printh(char* fmt,... );

int nreturn_values = -1;

int A4GL_findex (char *str, char c);
/*void push_validate (char *t2);*/
int A4GL_get_attr_from_string (char *s);
//char get_curr_report_stack_whytype_1 (void);
char *get_curr_report_stack_why (void);
char find_variable_scope (char *s_in);
char *A4GL_get_important_from_clobber (char *s);
char *A4GL_get_clobber_from_orig (char *s);
//char *A4GLSQLCV_check_sql(char *s) ;
int get_rep_no_orderby (void);
int get_validate_list_cnt (void);
char *sql_features = 0;
//int get_ccnt(void);
//void set_ccnt(int a);
int get_block_no (int n);
//struct fh_field_list *new_field_list(void);
//char *A4GL_decode_packtype(char *s) ;

/*
=====================================================================
                    Variables definitions
=====================================================================
*/


//
//void dump_updvals (void);
//void dump_insvals (void);
//char *pop_gen (int a);
/*int gen_cnt (int a);*/
//void copy_gen (int a, int b);
extern int menu_cnt;			/** The count of menus found */
extern int yylineno;			/** The source file line number */
extern char *infilename;    /** The input (4gl file name */
extern int in_define;
extern int doing_a_print;

static int db_used = 0;		 /** Flag that indicate that a database is being used */
static int inc = 0;
static char pklist[2048] = "";
static char upd_using_notpk[5000] = "";
static int upd_using_notpk_cnt = 0;
extern char current_upd_table[64];
extern char current_ins_table[256];
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

int lines_printed = 0;

int lines_printed_true = 0;
int lines_printed_false = 0;

static int push_construct_table (char *tableName);

char when_to_tmp[64] = "";
char when_to[8][128] = { "", "", "", "", "", "", "", "" };
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




struct s_constr_buff constr_buff[256];
int constr_cnt = 0;

/**
 * Input bind array.
 *
 * Used for instructions like execute using or open using wher we have a list 
 * of variables that act as input for the statement.
 */
struct binding_comp *ibind = 0;	//[NUMBINDINGS];
long a_ibind = 0;
struct binding_comp *nullbind = 0;	//[NUMBINDINGS];
long a_nullbind = 0;

/**
 * Output bind array.
 */
struct binding_comp *obind = 0;	//[NUMBINDINGS];
long a_obind = 0;
struct binding_comp *fbind = 0;	//[NUMBINDINGS];
long a_fbind = 0;
struct binding_comp *ebind = 0;	//[NUMBINDINGS];
long a_ebind = 0;
struct binding_comp *ordbind = 0;	//[NUMBINDINGS];
long a_ordbind = 0;

int ordbindcnt = 0;
int ibindcnt = 0;			/** Number of elements in ibind array */
int nullbindcnt = 0;
int obindcnt = 0;
int fbindcnt = 0;
int ebindcnt = 0;

struct binding_comp *ensure_bind (long *a_bindp, long need,
				  struct binding_comp *b);
struct binding_list *new_bind_list (char *s);
struct binding_list *append_bind_list (struct binding_list *l, char *s);

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

//extern int ccnt;		/* in lexer.c */


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
//char *rettype (char *s);
int yywrap (void);
struct sreports *get_sreports (int z);
void a4gl_add_variable (char *name, char *type, char *n);
static void push_validate_column (char *tabname, char *colname);

char *get_namespace (char *s);
char *make_sql_string_and_free (char *first, ...);
char *do_clobbering (char *f, char *s);
char *pg_make_sql_string_and_free (char *first, ...);

int A4GL_db_used (void);
/*
=====================================================================
                    Functions definitions
=====================================================================
*/






int
A4GL_db_used (void)
{
  return db_used;
}


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
  /* Does nothing */
}

/**
 *
 */
void
inmod (void)
{
  /* Does nothing */
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
  int ccnt;
  ccnt=A4GL_get_ccnt();
  if (ccnt== 0)
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


char *
command_type_for_stack_pos (int n)
{
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

int
get_sio_id (char *cmd_type)
{
  int stack_ids[10];
  int a;
  int max_id = 0;
  int anymode = 0;
  int ccnt;
  ccnt=A4GL_get_ccnt();
  for (a = 0; a < 10; a++)
    stack_ids[a] = 0;
/* Are we looking for anything ? */
  if (strcmp (cmd_type, "ALL") == 0)
    {
      anymode = 1;
    }
  if (strcmp (cmd_type, "ALLINPUT") == 0)
    {
      anymode = 2;
    }
  if (anymode)
    {				/* used for getfldbuf etc */
      stack_ids[0] = isin_command ("INPUT");
      stack_ids[1] = isin_command ("CONSTRUCT");
      if (anymode != 2)
	stack_ids[2] = isin_command ("DISPLAY");

      for (a = 0; a < 3; a++)
	{
	  if (stack_ids[a] > max_id)
	    max_id = stack_ids[a];
	}
      return max_id;
    }

  a = isin_command (cmd_type);
  if (a == 0)
    {
      int z;
      PRINTF ("Looking for cmd_type = %s - not found\n", cmd_type);
      for (z = ccnt - 1; z >= 0; z--)
	{
	  if (command_stack[z].cmd_type == 0
	      || command_stack[z].cmd_type[0] == 0)
	    continue;
	  PRINTF ("%d %s\n", z, command_stack[z].cmd_type);
	}
      a4gl_yyerror ("Internal error - unable to find sio_id for command");
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
  A4GL_debug ("push_name  a = %s n = %d \n", A4GL_null_as_null (a), n);
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
  A4GL_debug ("push_type : %s %s %s", A4GL_null_as_null (a),
	      A4GL_null_as_null (n), A4GL_null_as_null (as));

  variable_action (-1, a, n, as, "push_type");

  /* MJA - NEWVARIABLE */


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

  /*char *pt; */
  /*char *pk; */
  /*int z; */
  A4GL_debug ("Adding link to %s %s\n", A4GL_null_as_null (tab),
	      A4GL_null_as_null (pkey));

  variable_action (-1, tab, pkey, "", "add_link_to");


  /* MJA - NEWVARIABLE */

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

  A4GL_debug ("Menu %d Option %d '%s'", mn, mnopt, A4GL_null_as_null (b));
  A4GL_assertion (mn >= MAXMENU, "Ran out of menu spaces");
  A4GL_assertion (mnopt >= MAXMENUOPTS, "Ran out of option slots");
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
  menu_stack[mn][mnopt].idle_interval = 0;
  menu_stack[mn][mnopt].timeout_val = 0;
  menu_stack[mn][mnopt].action[0] = 0;
}


void
push_menu_action (int mn, int mnopt, char *s)
{
  strcpy (menu_stack[mn][mnopt - 1].menu_title, "\"\"");
  strcpy (menu_stack[mn][mnopt - 1].menu_help, "\"\"");
  strcpy (menu_stack[mn][mnopt - 1].menu_key, "");
  menu_stack[mn][mnopt - 1].menu_helpno = 0;
  menu_stack[mn][mnopt - 1].idle_interval = 'A';
  strcpy (menu_stack[mn][mnopt - 1].action, s);


  menu_stack[mn][mnopt].menu_title[0] = 0;
  menu_stack[mn][mnopt].menu_help[0] = 0;
  menu_stack[mn][mnopt].menu_key[0] = 0;
  menu_stack[mn][mnopt].idle_interval = 0;
  menu_stack[mn][mnopt].timeout_val = 0;
  menu_stack[mn][mnopt].action[0] = 0;
}

void
push_menu_timeout (int mn, int mnopt, char *s)
{
  strcpy (menu_stack[mn][mnopt - 1].menu_title, "\"\"");
  strcpy (menu_stack[mn][mnopt - 1].menu_help, "\"\"");
  strcpy (menu_stack[mn][mnopt - 1].menu_key, "\"\"");
  menu_stack[mn][mnopt - 1].menu_helpno = 0;
  menu_stack[mn][mnopt - 1].idle_interval = s[0];
  menu_stack[mn][mnopt - 1].timeout_val = atol (&s[2]);

  menu_stack[mn][mnopt].menu_title[0] = 0;
  menu_stack[mn][mnopt].menu_help[0] = 0;
  menu_stack[mn][mnopt].menu_key[0] = 0;
  menu_stack[mn][mnopt].idle_interval = 0;
  menu_stack[mn][mnopt].timeout_val = 0;
  menu_stack[mn][mnopt].action[0] = 0;
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
  /*int a; */

  /*long z; */
  long z_new;
  char s[1024];
  char buff[1024];
  char buff2[1024];
  /*char *ptr; */
  /*int dir; */

  /*int flg; */
  /*int lvl = 0; */
  int dtype;
  int size;
  int vval;


  if (strlen (s_n) > 1023)
    {
      A4GL_assertion (1, "scan_variables buffers too small");
    }
  memset (s, 0, 1024);
  strcpy (s, s_n);


  A4GL_debug ("s=%s", A4GL_null_as_null (s));

  /*last_var_found = -1; */

  /* MJA - NEWVARIABLE */
  if (s[0] == '.' && s[1] == '\0')
    return -1;

  if (s[0] == 0)
    return -1;

  if (strchr (s, '\n'))
    return -2;			/* This is a variable thru variable.. */

  if (strlen (s) >= sizeof (buff))
    {
      A4GL_assertion (1, "scan_variables buffer is too small..");
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


  if (strncmp (s, "CLASS_COPY->", 12) == 0)
    {
      strcpy (buff, &s[12]);
      strcpy (s, buff);
    }


  A4GL_debug ("find_variable : %s", A4GL_null_as_null (buff));

  if (strcmp (buff, "a4gl_status") == 0)
    add_feature ("STATUS");
  if (strcmp (buff, "a4gl_sqlca.sqlawarn") == 0)
    add_feature ("SQLCA_SQLAWARN");
  if (strcmp (buff, "a4gl_sqlca.sqlcode") == 0)
    add_feature ("SQLCA_SQLCODE");
  if (strcmp (buff, "a4gl_sqlca.sqlerrm") == 0)
    add_feature ("SQLCA_SQLERRM");
  if (strcmp (buff, "a4gl_sqlca.sqlerrd[(1)-1]") == 0)
    add_feature ("SQLCA_SQLERRD1");
  if (strcmp (buff, "a4gl_sqlca.sqlerrd[(2)-1]") == 0)
    add_feature ("SQLCA_SQLERRD2");
  if (strcmp (buff, "a4gl_sqlca.sqlerrd[(3)-1]") == 0)
    add_feature ("SQLCA_SQLERRD3");
  if (strcmp (buff, "a4gl_sqlca.sqlerrd[(4)-1]") == 0)
    add_feature ("SQLCA_SQLERRD4");
  if (strcmp (buff, "a4gl_sqlca.sqlerrd[(5)-1]") == 0)
    add_feature ("SQLCA_SQLERRD5");
  if (strcmp (buff, "a4gl_sqlca.sqlerrd[(6)-1]") == 0)
    add_feature ("SQLCA_SQLERRD6");


  vval = find_variable (buff, &dtype, &size, 0, 0);

  if (vval == 1)
    {
      z_new = dtype + (size << 16);
      return z_new;
    }

  if (vval == 0)
    {
      return -1;
    }


  return vval;





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

  /* MJA - NEWVARIABLE */
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
	      A4GL_debug ("Seems to A4GL_match %s %d",
			  A4GL_null_as_null (vars[a].var_name),
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
  A4GL_debug ("isarrvariable\n");
  a = isvartype (s, 1);
  A4GL_debug ("Checking if %s is an array %d", A4GL_null_as_null (s), a);
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
  A4GL_debug ("isrecvariable\n");
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
  /*char scope = 'm'; */
  int x;
  char buff[256];
  x = 0;
  buff[1] = 0;
  buff[0] = t;
  variable_action (-1, name, ptr, buff, "add_constant");

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

  A4GL_debug ("open_db %s", A4GL_null_as_null (s));
  strcpy (db, s);

  if (has_default_database ())
    {
      strcpy (db, get_default_database ());
      A4GL_debug ("Overriding default database with %s",
		  A4GL_null_as_null (db));
      A4GL_trim (db);
    }

  A4GLSQL_set_status (0, 1);
  A4GLSQL_init_connection (db);
  if (A4GLSQL_get_status () != 0)
    {
      SPRINTF2 (buff, "Could not connect to database %s (%s)",
	       A4GL_null_as_null (db),
	       A4GL_null_as_null (A4GLSQL_get_sqlerrm ()));
      a4gl_yyerror (buff);
    }
  if (db_used == 0)
    db_used = 1;
}



#ifdef MOVED
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
  A4GL_debug ("In rettype : %s", A4GL_null_as_null (s));

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
      A4GL_debug ("Returning %s\n", A4GL_null_as_null (rs));
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
#endif


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
  char *cname;

  A4GL_debug ("pushLikeTableColumn()");

  rval = A4GLSQL_read_columns (tableName, columnName, &idtype, &isize);
  cname = A4GL_confirm_colname (tableName, columnName);

  if (rval == 0)
    {
      SPRINTF2 (buff, "%s.%s does not exist in the database", tableName,
	       columnName);
      a4gl_yyerror (buff);
      return 0;
    }
  SPRINTF1 (cdtype, "%d", idtype & 15);
  SPRINTF1 (csize, "%d", isize);

  trim_spaces (cname);
  push_type (rettype (cdtype), csize, (char *) 0);
  return 1;
}


static int
pushValidateTableColumn (char *tableName, char *columnName)
{
  int rval;
  int idtype;
  int isize;
  /*char csize[20]; */
  /*char cdtype[20]; */
  char buff[300];

  A4GL_debug ("pushValidateTableColumn()");
  rval = A4GLSQL_read_columns (tableName, columnName, &idtype, &isize);
  if (rval == 0)
    {
      SPRINTF2 (buff, "%s.%s does not exist in the database", tableName,
	       columnName);
      a4gl_yyerror (buff);
      return 0;
    }
  trim_spaces (columnName);
  push_validate_column (tableName, columnName);
  return 1;
}

static int
pushValidateAllTableColumns (char *tableName)
{
  int rval;
  int isize = 0;
  int idtype = 0;
  char colname[256] = "";
  /*char csize[20]; */
  /*char cdtype[20]; */
  char buff[300];
  char *ccol;

  A4GL_debug ("pushValidateAllTableColumns()");


  A4GL_debug ("Calling get_columns : %s\n", A4GL_null_as_null (tableName));

  rval = A4GLSQL_get_columns (tableName, colname, &idtype, &isize);

  A4GL_debug ("rval = %d", rval);
  if (rval == 0 && tableName)
    {
      SPRINTF1 (buff, "%s does not exist in the database", tableName);
      a4gl_yyerror (buff);
      return 1;
    }

  A4GL_debug ("Rval !=0");

  while (1)
    {
      colname[0] = 0;

      rval = A4GLSQL_next_column (&ccol, &idtype, &isize);

      /*
         warning: passing arg 1 of `A4GLSQL_next_column' from incompatible pointer type
         we are sending char ARRAY to function expecting char POINTER !!!!
       */

      if (rval == 0)
	break;

      strcpy (colname, ccol);

      A4GL_debug ("next column for table '%p' is '%p'", tableName, ccol);
      A4GL_debug ("next column for table '%s' is '%s'",
		  A4GL_null_as_null (tableName), A4GL_null_as_null (ccol));

      trim_spaces (colname);
      push_validate_column (tableName, colname);

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
  char *ccol = 0;
  int ncol = 0;
  char *cname;


  A4GL_debug ("pushLikeAllTableColumns()");
  /* A4GLSQL_get_columns (char *tabname, char *colname, int *dtype, int *size) */
  A4GL_debug ("Calling get_columns : '%s'\n", A4GL_null_as_null (tableName));
  rval = A4GLSQL_get_columns (tableName, colname, &idtype, &isize);
  A4GL_debug ("rval = %d", rval);
  if (rval == 0 && tableName)
    {
      SPRINTF1 (buff, "%s does not exist in the database", tableName);
      a4gl_yyerror (buff);
      return 1;
    }

  A4GL_debug ("Rval (%d) !=0", rval);

  while (1)
    {
      colname[0] = 0;

      /* int A4GLSQL_next_column(char **colname, int *dtype,int *size); */
      ccol = 0;
      rval = A4GLSQL_next_column (&ccol, &idtype, &isize);
      if (rval == 0)
	{
	  A4GL_debug ("Got rval back from next_column as 0");
	  break;
	}

      ncol++;

      A4GL_assertion (ccol == 0, "No column name set");

      A4GL_debug ("next column for table '%p' is '%p'", tableName, ccol);
      A4GL_debug ("next column for table '%s' is '%s'",
		  A4GL_null_as_null (tableName), A4GL_null_as_null (ccol));
      strcpy (colname, ccol);


      /*
         warning: passing arg 1 of `A4GLSQL_next_column' from incompatible pointer type
         we are sending char ARRAY to function expecting char POINTER !!!!
       */


      SPRINTF1 (cdtype, "%d", idtype & 15);
      SPRINTF1 (csize, "%d", isize);
      A4GL_debug ("%d %d", idtype, isize);
      A4GL_debug ("---> %s %s", A4GL_null_as_null (cdtype),
		  A4GL_null_as_null (csize));
      A4GL_debug ("A4GLSQL_read_columns: Pushing %s %s %s",
		  A4GL_null_as_null (colname), A4GL_null_as_null (cdtype),
		  A4GL_null_as_null (csize));


      //cname=A4GL_confirm_colname(tableName,colname);
      cname = strdup (colname);


      trim_spaces (cname);
      push_name (cname, 0);
      push_type (rettype (cdtype), csize, 0);
    }
  A4GL_debug ("ncol=%d\n", ncol);
  if (ncol == 0)
    {

      SPRINTF1 (buff, "%s does not exist in the database", tableName);
      a4gl_yyerror (buff);
      return 1;
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
      SPRINTF0 (buff, "You cannot use LIKE without specifying a database");
      a4gl_yyerror (buff);
      return;
    }

  strcpy (t, t2);
  strcpy (buff, t);
  strcat (buff, ".");

  tableName = strtok (buff, ".");	/* table name */
  columnName = strtok (0, ".");	/* column name */
  A4GL_debug ("a='%s' b='%s'", A4GL_null_as_null (tableName),
	      A4GL_null_as_null (columnName));

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


/* Skip any owner bit...*/
  if (t2[0] == '\\' && t2[1] == '"')
    {
      char *x;
      x = strchr (t2, '.');
      if (x)
	{
	  t2 = x + 1;
	}
    }



  if (db_used == 0)
    {
      SPRINTF0 (buff, "You cannot use VALIDATE without specifying a database");
      a4gl_yyerror (buff);
      return;
    }

  strcpy (t, t2);
  strcpy (buff, t);
  strcat (buff, ".");

  tableName = strtok (buff, ".");	/* table name */
  columnName = strtok (0, ".");	/* column name */
  A4GL_debug ("a='%s' b='%s'", A4GL_null_as_null (tableName),
	      A4GL_null_as_null (columnName));

  if (columnName && strcmp (columnName, "*") != 0)
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

  A4GL_debug (">>>>>> %s\n", A4GL_null_as_null (t));
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
int
push_blockcommand (char *cmd_type)
{
int ccnt;
ccnt=A4GL_get_ccnt();
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
  file_out_indent (ccnt);
  A4GL_set_ccnt(ccnt);
  return command_stack[ccnt].block_no;
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
  int ccnt;
  ccnt=A4GL_get_ccnt();

  /* more checks here ! */

  for (a = ccnt - 1; a > 0; a--)
    {
      if (strcmp (command_stack[a].cmd_type, cmd_type) == 0)
	{
	  print_continue_block (command_stack[a].block_no, 0, 0);
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

  //if (strcmp (s, "FOR") == 0) return 1;
  /* if (strcmp(s,"FOREACH")==0) return 1; */
  //if (strcmp (s, "WHILE") == 0) return 1;
  //if (strcmp (s, "CASE") == 0) return 1;
  /*
     if (strcmp(s,"CONSTRUCT")==0) return 1;
     if (strcmp(s,"DISPLAY")==0) return 1;
     if (strcmp(s,"PROMPT")==0) return 1;
   */

  return 0;
}



void
continue_blockcommand (char *cmd_type)
{
	int ccnt;
	ccnt=A4GL_get_ccnt();
  //int a;

  //char err[80];
  print_continue_block (command_stack[ccnt - 1].block_no, 0, cmd_type);
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
  int ccnt;
  char err[80];
  A4GL_debug ("END BLOCK %s", cmd_type);
  ccnt=A4GL_get_ccnt();
  /* more checks here ! */

  ccnt--;
  A4GL_set_ccnt(ccnt);
  file_out_indent (ccnt);
  if (command_stack[ccnt].block_no > 0)
    {

      if (iscontinuecmd (cmd_type))
	{
	  print_continue_block (command_stack[ccnt].block_no, 0, cmd_type);
	}
      print_end_block (command_stack[ccnt].block_no);
    }

  A4GL_debug ("\n\n--------->%s\n\n", cmd_type);

  if (strcmp (command_stack[ccnt].cmd_type, cmd_type) == 0)
    {

      command_stack[ccnt].cmd_type[0] = 0;

      return;

    }

  SPRINTF3 (err, "%s was not last block command (I've got a %s @ %d)\n",
	   cmd_type, command_stack[ccnt].cmd_type, ccnt);
  A4GL_debug (err);
  A4GL_debug ("------------------\n");
  for (a = 0; a <= ccnt; a++)
    {
      A4GL_debug ("   %s\n", command_stack[a].cmd_type);
    }
  A4GL_debug ("------------------\n");
  a4gl_yyerror (err);
  //exit (0);
}

/**
 *
 * @param cmd_type
 */
int
in_command (char *cmd_type)
{

	int ccnt;
  int z;
  char buff[255];
ccnt=A4GL_get_ccnt();
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

  //PRINTF ("Not in a %s command\n", cmd_type);
  SPRINTF1 (buff,
	   "Can't exit/continue '%s' command (because you're not in one)",
	   cmd_type);
  a4gl_yyerror (buff);

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
  char var[2048] = "";
  A4GL_debug ("add_bind: %c %s\n", i, A4GL_null_as_null (var_i));
  strcpy (var, var_i);

  if (var_i[0] == '"')
    {
      dtype = (strlen (var) - 2) << 16;
      strcpy (var, var_i);
    }
  else
    {
      A4GL_debug ("Scanning...");
      dtype = scan_variable (var_i);


      switch (i)
	{
	case 'f':
	  strcpy (var, fgl_add_scope (var_i, 'L'));
	  break;		/* Function parameters */
	case 'O':
	  strcpy (var, fgl_add_scope (var_i, 'L'));
	  break;		/* Report order by */
	default:
	  strcpy (var, fgl_add_scope (var_i, 0));
	}

    }


  A4GL_debug ("add_bind - dtype=%x (%s) i=%c\n", dtype, A4GL_null_as_null (var), i);

  if (i == 'i')
    {
      if (dtype == -2 || strstr (var, ".*"))
	{
	  char buff[2000];
	  if (strstr (var, ".*") == 0 && strchr(var,'\n')==0)
	    {
	      strcpy (buff, var);
	      strcat (buff, ".*");
	    }
	  A4GL_debug ("push_bind_rec...");
	  push_bind_rec (var, i);
	}
      else
	{
	  ibind = ensure_bind (&a_ibind, ibindcnt, ibind);
	  ibind[ibindcnt].start_char_subscript = 0;
	  ibind[ibindcnt].end_char_subscript = 0;

	  if (strncmp (var, " a4gl_substr(", 8) != 0)
	    {
	      strcpy (ibind[ibindcnt].varname, var);
	      ibind[ibindcnt].dtype = dtype;
	    }
	  else
	    {
	      char buff[256];
	      char buff2[256];
	      int s_dtype=-1;
	      int s_sstart=-1;
	      int s_send=-1;
	      //int a;
	      char *ptrs[5] = { 0, 0, 0, 0, 0 };
	      strcpy (buff2, &var[strlen ("a4gl_substr ") + 1]);
	      ptrs[0] = buff2;
	      ptrs[1] = strstr (ptrs[0] + 3, " , ");
	      if (ptrs[1])
		{
		  *ptrs[1] = 0; ptrs[1]++;
		  strcpy (buff, ptrs[0]);
		  ptrs[2] = strstr (ptrs[1] + 3, " , ");
		  if (ptrs[2])
		    {
		      *ptrs[2] = 0; ptrs[2]++;
		      s_dtype = atol (ptrs[1]);
		      ptrs[3] = strstr (ptrs[2] + 3, " , ");
		      if (ptrs[3])
			{
			  *ptrs[3] = 0; ptrs[3]++;
			  s_sstart = atol (ptrs[2]);
			  s_send = atol (ptrs[3]);
			}
		    }
		}




	      //a = sscanf (buff2, "%s , %d , %d , %d) /*1*/", buff, &s_dtype, &s_sstart, &s_send);
	      if (ptrs[3] == 0 || s_sstart<0 || s_send<0 || s_dtype<0)
		{
		  A4GL_debug ("Error processing : %s\n",
			      A4GL_null_as_null (buff2));
		  set_yytext (buff2);
		  a4gl_yyerror ("Internal error - (split substr)");
		}
	      if (s_send == 0)
		s_send = s_sstart;
	      strcpy (ibind[ibindcnt].varname, buff);
	      ibind[ibindcnt].dtype = s_dtype;
	      ibind[ibindcnt].start_char_subscript = s_sstart;
	      ibind[ibindcnt].end_char_subscript = s_send;
	    }
	  ibindcnt++;
	}
      return ibindcnt;
    }

  if (i == 'N')
    {
      if (dtype == -2 || strstr (var, ".*"))
	{
	  char buff[2000];
	  A4GL_debug ("push_bind_rec...");
	  strcpy (buff, var);
	  if (strstr (var, ".*") == 0 && strchr(var,'\n')==0)
	    {
	      strcpy (buff, var);
	      strcat (buff, ".*");
	    }
	  push_bind_rec (buff, i);
	}
      else
	{
	  nullbind = ensure_bind (&a_nullbind, nullbindcnt, nullbind);
	  strcpy (nullbind[nullbindcnt].varname, var);
	  nullbind[nullbindcnt].dtype = dtype;
	  nullbindcnt++;

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
	  obind = ensure_bind (&a_obind, obindcnt, obind);
	  obind[obindcnt].start_char_subscript = 0;
	  obind[obindcnt].end_char_subscript = 0;
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
	  ebind = ensure_bind (&a_ebind, ebindcnt, ebind);
	  ebind[ebindcnt].start_char_subscript = 0;
	  ebind[ebindcnt].end_char_subscript = 0;
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
	  ordbind = ensure_bind (&a_ordbind, ordbindcnt, ordbind);
	  memset (&ordbind[ordbindcnt], 0, sizeof (ordbind[ordbindcnt]));
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
	  fbind = ensure_bind (&a_fbind, fbindcnt, fbind);
	  fbind[fbindcnt].start_char_subscript = 0;
	  fbind[fbindcnt].end_char_subscript = 0;
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
  A4GL_debug ("start_bind %c -  %s", i, A4GL_null_as_null (var));

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
  if (i == 'o')
    return obindcnt;
  if (i == 'e')
    return ebindcnt;
  if (i == 'O')
    return ordbindcnt;
  if (i == 'f' || i == 'F')
    return fbindcnt;
  return 0;
}


char *
get_bind_varname (char i, int n)
{
  if (i == 'o')
    {
      return obind[n].varname;
    }
  if (i == 'i')
    {
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
int ccnt;
ccnt=A4GL_get_ccnt();


/* We have to do some messing around here...*/
/* If we want to 'continue input' - we call continue_input("INPUT")*/
/* if we want a next field ... that does the next field bit - then calls continue_input("INPUTREQ")*/
/* Here - we will always be looking for "INPUT" - but pass on the INPUT/INPUTREQ to the print stage...*/
/* Same goes for construct*/


  internal_cmd_type = acl_strdup (cmd_type);

  if (strcmp (cmd_type, "INPUTREQ") == 0)
    strcpy (internal_cmd_type, "INPUT");
  if (strcmp (cmd_type, "CONSTRUCTREQ") == 0)
    strcpy (internal_cmd_type, "CONSTRUCT");

  for (a = ccnt - 1; a >= 0; a--)
    {
      A4GL_debug ("continue_loop:%s %s %s\n", command_stack[a].cmd_type,
		  cmd_type, internal_cmd_type);

      if (strcmp (command_stack[a].cmd_type, internal_cmd_type) == 0)
	{
	  g = 1;
	  break;
	}
    }
  if (g == 0)
    {
      A4GL_debug ("/* wanted to continue a %s but wasnt in one! */",
		  cmd_type);
      return;
    }
  print_continue_loop (command_stack[a].block_no, cmd_type);
}


int
get_block_no (int n)
{
  return command_stack[n].block_no;
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
  int ccnt;
  int g = 0;
  int printed = 0;
  ccnt=A4GL_get_ccnt();

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

    printf("wanted to exit a %s but wasnt in one!\n",cmd_type);
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
  lines_printed = 0;
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
  rep->lines_in_header = 0;
  rep->lines_in_first_header = 0;
  rep->lines_in_trailer = 0;
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
  rep->lines_in_header = 0;
  rep->lines_in_first_header = 0;
  rep->lines_in_trailer = 0;
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
      strcpy (b1, A4GL_unscope (varname));
      //if (b1[0]>='A'&&b1[0]<='Z'&&b1[1]=='_') { strcpy(b1,&varname[2]); }
      strcpy (b2, A4GL_unscope (ordbind[a].varname));
      //if (b2[0]>='A'&&b2[0]<='Z'&&b2[1]=='_') { strcpy(b2,&ordbind[a].varname[2]); }
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

  if (i == 'f')
    strcpy (var, fgl_add_scope (nvar, 'L'));
  else
    strcpy (var, fgl_add_scope (nvar, 0));
  dtype = scan_variable (var);

  A4GL_debug ("/* add_arr_bind %c %s %x */\n", i, var, dtype);

  if (i == 'i')
    {
      if (dtype == -2)
	push_bind_rec (var, i);
      else
	{
	  ibind = ensure_bind (&a_ibind, ibindcnt, ibind);
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
	  nullbind = ensure_bind (&a_nullbind, nullbindcnt, nullbind);
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
	  obind = ensure_bind (&a_obind, obindcnt, obind);
	  strcpy (obind[obindcnt].varname, var);
	  obind[obindcnt].dtype = dtype;
	  obindcnt++;
	}
      return obindcnt;
    }
  if (i == 'e')
    {
      if (dtype == -2)
	push_bind_rec (var, i);
      else
	{
	  ebind = ensure_bind (&a_ebind, ebindcnt, ebind);
	  strcpy (ebind[ebindcnt].varname, var);
	  ebind[ebindcnt].dtype = dtype;
	  ebindcnt++;
	}
      return ebindcnt;
    }


  if (i == 'f' || i == 'F')
    {
      fbind = ensure_bind (&a_fbind, fbindcnt, fbind);
      fbind[fbindcnt].start_char_subscript = 0;
      fbind[fbindcnt].end_char_subscript = 0;
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
  if (i == 'o')
    {
      obindcnt = 0;
    }
  if (i == 'e')
    {
      ebindcnt = 0;
    }
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
  if (strcmp (b, "*") == 0)
    {
      push_construct_table (a);
    }
  else
    {
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
  /*char csize[20]; */
  /*char cdtype[20]; */
  char buff[300];
  char *ccol;

  A4GL_debug ("push_construct_table()");
  A4GL_debug ("Calling get_columns : %s\n", tableName);
  rval = A4GLSQL_get_columns (tableName, colname, &idtype, &isize);
  A4GL_debug ("rval = %d", rval);
  if (rval == 0 && tableName)
    {
      SPRINTF1 (buff, "%s does not exist in the database", tableName);
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
      A4GL_trim (colname);
      /*
         warning: passing arg 1 of `A4GLSQL_next_column' from incompatible pointer type
         we are sending char ARRAY to function expecting char POINTER !!!!
       */

      if (rval == 0)
	break;

      push_construct (tableName, colname);
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
	  if (a == 0 || (s[0]=='"' && a==strlen(s)-1)) {
	    buff[b++] = '\'';
	  }
	  else
	    {
	      if (s[a - 1] != '\\')
		{
		  buff[b++] = '\'';
		} else {
	  	  buff[b++] = '"';
		}
	    }
	  continue;
	}
      if (s[a] == '\'')
	{
	  buff[b++] = '\'';
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
struct expr_str *add_report_agg (char t, struct expr_str *s1, struct expr_str *s2, int a,long *n)
{
int rval;
struct expr_str *x;
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
      sreports[sreports_cnt].rep_where_expr =A4GL_new_literal_long_str("1");
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
  
   rval=print_agg_defines(t,a);
   *n=rval;
   x=A4GL_new_expr_agg(t,a);
   use_group = 0;

   return x;
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


char *whentostore_p = 0;
int whenever_store_c = 0;
char *whenever_store_p = 0;



void
set_whento_store (char *p)
{
  if (p)
    whentostore_p = acl_strdup (p);
  else
    whentostore_p = 0;
}



/**
 *
 */
void
set_whento (char *p)
{
  A4GL_debug ("whento = %p", p);
  strcpy (when_to_tmp, p);
}

void
set_whenever_store (int c, char *p)
{
  whenever_store_c = c;
  if (p)
    whenever_store_p = acl_strdup (p);
  else
    whenever_store_p = 0;
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
void
set_whenever (int c, char *p)
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
      PRINTF ("Code=%d (%x) to %p\n", c, c, p);
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


void
set_whenever_from_store (void)
{
  set_whento (whentostore_p);
  set_whenever (whenever_store_c, whenever_store_p);
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
      if (A4GL_isyes (acl_getenv ("DOING_CM")))
	{
	  strcat (buff, "?@@PARAM@@?");
	}
      else
	{
	  strcat (buff, "?");
	}
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
void
expand_bind (struct binding_comp *bind, int btype, int cnt, int must_be_local)
{
  char buff[256];
  /*int b1; */
  int dim;
  int xxxa;
  static struct binding_comp *save_bind = 0;
  char variable_scope;

  xxxa = 0;

  if (cnt == 0)
    return;			/* theres nothing there to expand */

  save_bind = acl_realloc (save_bind, sizeof (struct binding_comp) * cnt);
  for (xxxa = 0; xxxa < cnt; xxxa++)
    {
      strcpy (save_bind[xxxa].varname, bind[xxxa].varname);
      save_bind[xxxa].dtype = bind[xxxa].dtype;
    }

  start_bind (btype, 0);

  for (xxxa = 0; xxxa < cnt; xxxa++)
    {
      strcpy (buff, save_bind[xxxa].varname);
      if (must_be_local)
	{
	  variable_scope = find_variable_scope (buff);
	  if (A4GL_isyes (acl_getenv ("REPORT_VARS_AT_MODULE"))) {
		  if (variable_scope=='R') variable_scope='L';
	  }
	  if (variable_scope != 'L' && variable_scope!='R')
	    {
		   A4GL_debug("scope = %c - variable not defined locally",variable_scope);
	      set_yytext (buff);
	      a4gl_yyerror ("Variable has not been defined locally");
	      return;
	    }
	}




      dim = 1;
      if (A4GL_isyes (acl_getenv ("NO_ARRAY_EXPAND")))
	dim = 0;
      if (strncmp (buff, " a4gl_let_substr", 16) == 0)
	dim = 0;
      if (strncmp (buff, " ASSOCIATE", 10) == 0)
	dim = 0;


      if (dim)
	{
	  if (isarrvariable (buff) && buff[strlen (buff) - 1] != ']'
	      && buff[strlen (buff) - 2] != ']' && dim == 1)
	    {
	      int type, arrsize1, arrsize2, arrsize3, size, level;
	      int c1;
	      int c2;
	      int c3;
	      char buff2[256];
	      //char arrbuff[256];


	      get_variable_dets_arr3 (buff, &type, &arrsize1, &arrsize2,
				      &arrsize3, &size, &level, 0);

	      if (arrsize3)
		{
		  for (c1 = 0; c1 < arrsize1; c1++)
		    {
		      for (c2 = 0; c2 < arrsize2; c2++)
			{
			  for (c3 = 0; c3 < arrsize3; c3++)
			    {
			      SPRINTF4 (buff2, "%s[%d][%d][%d]", buff, c1, c2,
				       c3);
			      if (scan_variable (buff2) == -2)
				{
				  strcat (buff2, ".*");
				}
			      add_bind (btype, buff2);
			    }
			}
		    }
		}
	      else
		{

		  if (arrsize2)
		    {
		      for (c1 = 0; c1 < arrsize1; c1++)
			{
			  for (c2 = 0; c2 < arrsize2; c2++)
			    {
			      SPRINTF3 (buff2, "%s[%d][%d]", buff, c1, c2);
			      if (scan_variable (buff2) == -2)
				{
				  strcat (buff2, ".*");
				}
			      add_bind (btype, buff2);
			    }
			}
		    }
		  else
		    {
		      for (c1 = 0; c1 < arrsize1; c1++)
			{
			  SPRINTF2 (buff2, "%s[%d]", buff, c1);
			  if (scan_variable (buff2) == -2)
			    {
			      strcat (buff2, ".*");
			    }
			  add_bind (btype, buff2);
			}

		    }
		}









	      continue;
	    }
	}

      if (scan_variable (buff) == -2)
	{
	  strcat (buff, ".*");
	}
      add_bind (btype, buff);
    }

}

/**
 * Expandthe output bind
 */
void
expand_obind (void)
{
  expand_bind (obind, 'o', obindcnt, 0);
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
	  FPRINTF (stderr,
		   "Warning: Only initializing first element in array %s\n",
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
      FPRINTF (stderr,
	       "Warning: Only initializing first element in array %s\n", s);
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
      int printed = 0;
      if (orig_ptr->expr_type == ET_EXPR_STRING)
	{
	  A4GL_debug ("     %d - %s", orig_ptr->expr_type,
		      orig_ptr->u_data.expr_char);
	  printed = 1;
	}
      if (!printed)
	{
	  A4GL_debug ("exprtype : %d", orig_ptr->expr_type);
	}
      orig_ptr = orig_ptr->next;
    }
  A4GL_debug ("---------------------------------------------------");
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
      if (A4GL_isyes (acl_getenv ("LOWER_CASE_GLOB_NAME")))
	{
	  s[a] = tolower (s[a]);
	}
    }
}

char
get_curr_report_stack_whytype_1 (void)
{
  return report_stack[report_stack_cnt - 1].whytype;
}

char
get_curr_report_stack_whytype (void)
{
  return report_stack[report_stack_cnt].whytype;
}


char *
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
  char buff[1000];
  char *ccol;
  char *notab;
  strcpy (big_buff, "SET ");

  if (mode == 1)
    {
      /* It will only be a '*' anyway.... */
      if (db_used == 0)
	{
	  SPRINTF0 (buff,
		   "You cannot use update * =  without specifying a database");
	  a4gl_yyerror (buff);
	  return 0;
	}

      A4GL_4glc_clr_gen (UPDCOL);

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
	  A4GL_4glc_push_gen (UPDCOL, colname);
	}
      A4GLSQL_end_get_columns ();
    }

  if (A4GL_4glc_gen_cnt (UPDCOL) != A4GL_4glc_gen_cnt (UPDVAL))
    {
      A4GL_4glc_dump_updvals ();
      a4gl_yyerror
	("Number of columns in update not the same as number of values");
    }

  for (a = 0; a < A4GL_4glc_gen_cnt (UPDCOL); a++)
    {
      if (a)
	strcat (big_buff, ",");
      if (A4GL_isyes (acl_getenv ("DOING_CM")))
	{
	  if (strcmp (A4GL_4glc_get_gen (UPDVAL, a), "?") == 0)
	    {
	      A4GL_assertion (1, "How ?");
	    }
	}

      notab=A4GLSQLCV_check_colname (current_upd_table, A4GL_4glc_get_gen (UPDCOL, a));

      while (strchr(notab,'.')) {
	      notab=strchr(notab,'.')+1;
      }

      SPRINTF2 (buff, "%s=%s ", notab, A4GL_4glc_get_gen (UPDVAL, a));

      strcat (big_buff, buff);
    }

  return big_buff;
}



#ifdef MOVED_TO_LIBAUBIT4GL


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
  ptr = acl_strdup (first);


  if (first != kw_comma && first != kw_space && first != kw_ob
      && first != kw_cb)
    {
      A4GL_debug ("FREE %p (%s)\n", first, first);
      if (A4GL_isyes (acl_getenv ("FREE_SQL_MEM")))
	{
	  free (first);
	}
      first = 0;
    }
  l = strlen (ptr);

  while (1)
    {
      n++;
      next = va_arg (ap, char *);
      if (next == 0)
	break;
      l += strlen (next);
      l++;			/* Extra space... */
      ptr = acl_realloc (ptr, l);
      strcat (ptr, next);
      if (next != kw_comma && next != kw_space && next != kw_ob
	  && next != kw_cb)
	{
	  A4GL_debug ("FREE %p (%s)\n", next, next);
	  if (A4GL_isyes (acl_getenv ("FREE_SQL_MEM")))
	    {
	      free (next);
	    }
	}
    }
  A4GL_debug ("Generated : %s\n", ptr);
  return ptr;
}
#endif

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
  ptr = acl_strdup (first);


  if (A4GL_isyes (acl_getenv ("FREE_SQL_MEM")))
    {
      free (first);
    }
  first = 0;
  l = strlen (ptr);

  while (1)
    {
      n++;
      next = va_arg (ap, char *);
      if (next == 0)
	break;
      l += strlen (next);
      l += 3;			/* Extra space... */
      ptr = acl_realloc (ptr, l);
      if (strlen (ptr))
	{
	  if (!ispunct (ptr[strlen (ptr) - 1]))
	    {
	      strcat (ptr, " ");
	    }
	}

      strcat (ptr, next);
      if (A4GL_isyes (acl_getenv ("FREE_SQL_MEM")))
	{
	  free (next);
	}
    }
  A4GL_debug ("Generated : %s\n", ptr);
  return ptr;
}






void
do_print_menu_1 (void)
{
  print_menu_1 (get_blk_no ());
  print_menu_1b (get_blk_no ());
}

void
do_print_menu_block_end (int mn)
{
  print_menu_block_end (mn, get_blk_no ());
}

int
get_blk_no (void)
{
	int ccnt;
	ccnt=A4GL_get_ccnt();
  return command_stack[ccnt - 1].block_no;
}

int
get_blk_no_1 (void)
{
	int ccnt;
	ccnt=A4GL_get_ccnt();
  return command_stack[ccnt - 2].block_no;
}


struct s_exchange_clobber
{
  char *orig;
  char *new;
  char *important;
};

struct s_exchange_clobber *clob_arr = 0;
int clob_arr_cnt = 0;

static int
has_clobber (char *s)
{
  int a;
  if (clob_arr_cnt == 0)
    return 0;
  for (a = 0; a < clob_arr_cnt; a++)
    {
      if (strcmp (clob_arr[a].orig, s) == 0)
	{
	  return 1;
	}
    }
  return 0;
}


static char *
get_clobber (char *s)
{
  int a;
  if (clob_arr_cnt == 0)
    return s;
  for (a = 0; a < clob_arr_cnt; a++)
    {
      if (strcmp (clob_arr[a].orig, s) == 0)
	{
	  return clob_arr[a].new;
	}
    }
  return s;
}

char *
A4GL_get_important_from_clobber (char *s)
{
  int a;
  if (clob_arr_cnt == 0)
    return s;
  for (a = 0; a < clob_arr_cnt; a++)
    {
      if (strcmp (clob_arr[a].orig, s) == 0)
	{
	  return clob_arr[a].important;
	}
    }
  return s;
}



char *
A4GL_get_clobber_from_orig (char *s)
{
  int a;
  if (clob_arr_cnt == 0)
    return s;
  for (a = 0; a < clob_arr_cnt; a++)
    {
      if (strcmp (clob_arr[a].new, s) == 0)
	{
	  return clob_arr[a].orig;
	}
    }
  return s;
}


static char *
add_clobber (char *buff_orig, char *important)
{
  static char buff_new[256];
  static int p = 0;
  char b1[256];

  strcpy (buff_new, buff_orig);

  if (has_clobber (buff_orig))
    return get_clobber (buff_orig);

  clob_arr_cnt++;
  clob_arr =
    acl_realloc (clob_arr, sizeof (struct s_exchange_clobber) * clob_arr_cnt);
  if (clob_arr == 0)
    {
      a4gl_yyerror ("Unable to allocate buffer...");
      return 0;
    }



  if (strlen (buff_orig) <= 20)
    {				/* Extra 2 for the quotes... */
      clob_arr[clob_arr_cnt - 1].orig = acl_strdup (buff_orig);
      clob_arr[clob_arr_cnt - 1].new = acl_strdup (buff_new);
      clob_arr[clob_arr_cnt - 1].important = acl_strdup (important);
      return buff_orig;
    }

  strcpy (b1, important);
  b1[9] = 0;
  SPRINTF2 (buff_new, "\"a4gl_%03d_%s\"", p++, b1);
  clob_arr[clob_arr_cnt - 1].orig = acl_strdup (buff_orig);
  clob_arr[clob_arr_cnt - 1].new = acl_strdup (buff_new);
  clob_arr[clob_arr_cnt - 1].important = acl_strdup (important);
  return buff_new;
}

char *
do_clobbering (char *f, char *s)
{
  static char buff[256];

  if (A4GL_isyes (acl_getenv ("NOCLOBBER")))
    {
      SPRINTF1 (buff, "\"%s\"", s);
      if (!has_clobber (buff))
	{
	  add_clobber (buff, s);
	}
      return buff;
    }

  SPRINTF2 (buff, "\"%s_%s\"", f, s);

  if (A4GL_isyes (acl_getenv ("ALWAYSCLOBBER")))
    {
      if (!has_clobber (buff))
	{
	  add_clobber (buff, s);
	}
      return buff;
    }

  if (has_clobber (buff))
    {
      return get_clobber (buff);
    }
  return add_clobber (buff, s);
}


char *
fgl_add_scope (char *s, int n)
{
  char c;
  static char buffer[2560];
  char buffer2[1024];
  //static char if1[2000]="";
  //static char if2[2000]="";

  if (strncmp (s, "CLASS_COPY->", 12) == 0)
    return s;

  strcpy (buffer2, s);
  c = find_variable_scope (buffer2);

  if (c == 'C' || c == 'P');
  else
    {
      if (A4GL_isyes (acl_getenv ("MARK_SCOPE"))
	  || A4GL_isyes (acl_getenv ("MARK_SCOPE_MODULE")));
      else
	{
	  return s;
	}
    }


  if (buffer2[0] >= 'A' && buffer2[0] <= 'Z' && buffer2[1] == '_')
    {
      strcpy (buffer2, A4GL_unscope (buffer2));
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


  if (c != 'S')
    {
      if (c == 'C' || c == 'P')
	{
	  if (c == 'C')
	    {
	      SPRINTF1 (buffer, "CLASS_COPY->%s", buffer2);
	    }
	  else
	    {
	      find_variable_ptr (buffer2);
	      SPRINTF1 (buffer, "CLASS_COPY->%s", get_last_class_var ());
	    }
	}
      else
	{
	  if (A4GL_isyes (acl_getenv ("REPORT_VARS_AT_MODULE")) && c=='L') { if (isin_command ("REPORT")) { c='R'; } }
	  if (A4GL_isyes (acl_getenv ("MARK_SCOPE_MODULE")) && (c == 'M' || c=='R'))
	    {
		    if (c=='R') {
			    extern char curr_func[];
	      			SPRINTF4 (buffer, "%c_%s_%s_%s", c, A4GL_compiling_module_basename (), curr_func,buffer2);
		    } else {
	      		SPRINTF3 (buffer, "%c_%s_%s", c, A4GL_compiling_module_basename (), buffer2);
		    }
	      buffer[0] = toupper (buffer[0]);
	    }
	  else
	    {
		
	      SPRINTF2 (buffer, "%c_%s", c, buffer2);
	      buffer[0] = toupper (buffer[0]);
	    }
	}
    }
  else
    {
      SPRINTF1 (buffer, "%s", buffer2);
    }

  return buffer;
}

int rep_no_orderby = 0;

void
set_rep_no_orderby (int n)
{
  rep_no_orderby = n;
}

int
get_rep_no_orderby (void)
{
  return rep_no_orderby;
}

struct s_validate
{
  char tabname[65];
  char colname[65];
  struct expr_str *expr;
};

struct s_validate *validate_list = 0;
int validate_list_cnt = 0;

int
get_validate_list_cnt (void)
{
  return validate_list_cnt;
}

void
clr_validate_list (void)
{
  if (validate_list)
    free (validate_list);
  validate_list_cnt = 0;
  validate_list = 0;
}

static void
push_validate_column (char *tabname, char *colname)
{
  validate_list_cnt++;
  validate_list =
    acl_realloc (validate_list,
		 sizeof (struct s_validate) * validate_list_cnt);
  /*A4GL_trim(tabname); */
  /*A4GL_trim(colname); */
  strcpy (validate_list[validate_list_cnt - 1].tabname, tabname);
  strcpy (validate_list[validate_list_cnt - 1].colname, colname);

  validate_list[validate_list_cnt - 1].expr =(void*) A4GLSQL_get_validation_expr (tabname, colname);
  if (validate_list[validate_list_cnt - 1].expr == (void *) -1)
    {
      a4gl_yyerror
	("Unable to get validation information - does A4GL_SYSCOL_VAL exist ?");
    }


}

struct expr_str *
A4GL_get_validate_expr (int n)
{
  return validate_list[n].expr;
}


struct s_event
{
  int n;
  char *s;
};

struct s_event_list
{
  int nevents;
  struct s_event *events;
};

struct s_event_list event_queue[255];
int nevent_queue = -1;

void
A4GL_new_events (void)
{
  nevent_queue++;
  event_queue[nevent_queue].nevents = 0;
  event_queue[nevent_queue].events = 0;
}

void
A4GL_drop_events ()
{
  int a;
  if (event_queue[nevent_queue].events)
    {
      if (event_queue[nevent_queue].nevents)
	{
	  for (a = 0; a < event_queue[nevent_queue].nevents; a++)
	    {
	      free (event_queue[nevent_queue].events[a].s);
	    }
	}
      free (event_queue[nevent_queue].events);
    }
  event_queue[nevent_queue].nevents = 0;
  event_queue[nevent_queue].events = 0;
  nevent_queue--;
}

void
A4GL_add_onkey_key (char *s)
{
  A4GL_add_event (A4GL_EVENT_KEY_PRESS, s);
}

void
A4GL_add_onaction (char *s)
{
  A4GL_add_event (A4GL_EVENT_ON_ACTION, s);
}

void
A4GL_add_ontimer (char *s)
{
  if (s[0] == 'D')
    {
      A4GL_add_event (A4GL_EVENT_ON_IDLE, &s[2]);
      return;
    }
  if (s[0] == 'V')
    {
      A4GL_add_event (A4GL_EVENT_ON_INTERVAL, &s[2]);
      return;
    }
  if (s[0] == 'T')
    {
      A4GL_add_event (A4GL_EVENT_ON_TIME, &s[2]);
      return;
    }
}

void
A4GL_add_event (int n, char *s)
{
  event_queue[nevent_queue].nevents++;
  event_queue[nevent_queue].events =
    acl_realloc (event_queue[nevent_queue].events,
		 sizeof (struct s_event) * event_queue[nevent_queue].nevents);
  event_queue[nevent_queue].events[event_queue[nevent_queue].nevents - 1].n =
    n;
  event_queue[nevent_queue].events[event_queue[nevent_queue].nevents - 1].s =
    acl_strdup (s);
}

int
A4GL_get_nevents (void)
{
  return event_queue[nevent_queue].nevents;
}

void
A4GL_get_event (int n, int *i, char **s)
{
  *i = event_queue[nevent_queue].events[n].n;
  *s = event_queue[nevent_queue].events[n].s;
}


void
A4GL_copy_fbind_to_Obind (void)
{
  ordbind = ensure_bind (&a_ordbind, ordbindcnt, ordbind);
  memcpy (ordbind, fbind, sizeof (struct binding_comp) * fbindcnt);
  ordbindcnt = fbindcnt;
}



/* 
   Translate from the directory name for the SQLPACK to the
   logical name used for translating...
*/
char *
A4GL_decode_packtype (char *s)
{
  if (strcmp (s, "infx") == 0)
    return "INFORMIX";
  if (strcmp (s, "postgres") == 0)
    return "POSTGRES";

  return s;
}


void
A4GL_load_features ()
{
  int dump_features;
  FILE *f;
  char *ptr;
  char buff[300];
  dump_features = A4GL_isyes (acl_getenv ("DUMP_FEATURES"));
  if (dump_features == 0)
    return;
  A4GL_set_sql_features ();
  f = fopen (sql_features, "r");
  if (f == 0)
    {
      return;
    }
  while (1)
    {
      strcpy (buff, "");
      fgets (buff, 256, f);
      if (feof (f))
	break;
      ptr = strchr (buff, ' ');
      if (ptr)
	*ptr = 0;
      ptr = strchr (buff, '\n');
      if (ptr)
	*ptr = 0;
      ptr = strchr (buff, '\r');
      if (ptr)
	*ptr = 0;
      ptr = strchr (buff, '\t');
      if (ptr)
	*ptr = 0;
      A4GL_trim (buff);
      if (buff[0] == '#')
	continue;
      if (strlen (buff) == 0)
	continue;
      A4GL_add_pointer (buff, FEATURE_USED, (void *) 1);
    }
  fclose (f);


}

void
A4GL_add_feature (char *feature)
{
  static int dump_features = -1;
  static int failed = 0;
  FILE *f;

  if (dump_features == -1)
    {
      dump_features = A4GL_isyes (acl_getenv ("DUMP_FEATURES"));
    }

  if (dump_features == 0)
    return;
  if (!A4GL_has_pointer (feature, FEATURE_USED))
    {
      A4GL_set_sql_features ();
      f = fopen (sql_features, "a");
      if (f == 0)
	{
	  if (failed == 0)
	    PRINTF ("Unable to open features file (%s) - %d\n", sql_features,
		    errno);
	  failed++;
	  return;
	}
      A4GL_add_pointer (feature, FEATURE_USED, (void *) 1);
      FPRINTF (f, "%s\n", feature);
      fclose (f);
    }
}



void
A4GL_CV_print_exec_sql (char *s)
{
  char *ptr;
  int converted=0;
  if (A4GL_compile_time_convert()) {
  	ptr = A4GLSQLCV_check_sql (s,&converted);
  } else {
	  ptr=s;
  }
  print_exec_sql (ptr,converted);
}


void
A4GL_CV_print_exec_sql_bound (char *s)
{
  char *ptr;
  int converted=0;
  if (A4GL_compile_time_convert()) {
  	ptr = A4GLSQLCV_check_sql (s,&converted);
  } else {
	  ptr=s;
  }
  print_exec_sql_bound (ptr,converted);
}

void
A4GL_CV_print_do_select (char *s)
{
  print_do_select (s,0);

}


char *
A4GL_CV_print_select_all (char *s)
{
  char *ptr;
  int converted=0;
  if (A4GL_compile_time_convert()) {
  		ptr = A4GLSQLCV_check_sql (s,&converted);
  } else {
	  	ptr=s;
  }
  return print_select_all (ptr,converted);
}


int
A4GL_escape_quote_owner (void)
{
  if (A4GLSQLCV_check_requirement ("QUOTE_OWNER"))
    {
      return 1;
    }
  if (A4GLSQLCV_check_requirement ("NO_OWNER_QUOTE"))
    {
      return 0;
    }
  if (strcmp (acl_getenv ("A4GL_LEXTYPE"), "EC") == 0)
    {
      return 0;
    }
  return 1;
}



char *
A4GLSQLCV_generate_ins_string (char *current_ins_table, char *s)
{
  char buff[40000];
  if (A4GLSQLCV_check_requirement ("FULL_INSERT"))
    {
      char *p;
      if (strstr (s, " VALUES "))
	{
	  p = fix_insert_expr (1);
	  if (p)
	    {
	      SPRINTF2 (buff, "INSERT INTO %s %s", current_ins_table, p);
	      free (s);
	      return acl_strdup (buff);
	    }
	}
    }


  return s;

}





static void
A4GL_set_sql_features (void)
{
  if (sql_features == 0)
    {
      sql_features = acl_getenv ("A4GL_SQL_FEATURE_FILE");
      if (sql_features == 0)
	sql_features = "sql_features";
      if (strlen (sql_features) == 0)
	{
	  sql_features = "sql_features";
	}
    }
}

void
emulate_insert (char *s)
{
  char buff[256];
  SPRINTF1 (buff, "\"%s\"", s);
  A4GL_cursor_defined (buff, 'I');
}


void
add_serial_column (char *t, char *c)
{
  // Doesn't do anything just yet....
}


void
do_yyerror (char *s)
{
  a4gl_yyerror (s);
}

#ifdef NDEF
char *
A4GL_print_start_to_is_expr (struct expr_str *ptr)
{
  A4GL_append_expr (ptr, "A4GL_set_rep_start_from_stack();");
  print_expr (ptr);
  return "A4GL_get_rep_start()";
}
#endif





struct expr_str *
A4GL_generate_variable_expr (char *s)
{
  int a;
  int flg = 0;
  void *p1 = 0;

  if (strchr (s, '\n') == 0)
    {
      a = scan_variable (s);
    }
  else
    {
      a = -2;
    }

  if (a >= 0)
    {
      if (A4GL_aubit_strcasecmp (s, "today") == 0)
	{
	  flg = 1;
	  p1 = A4GL_new_expr_simple (ET_EXPR_TODAY);
	}

      if (A4GL_aubit_strcasecmp (s, "time") == 0)
	{
	  flg = 1;
	  p1 = A4GL_new_expr_simple (ET_EXPR_TIME);
	}

      if (A4GL_aubit_strcasecmp (s, "pageno") == 0)
	{
	  flg = 1;
	  p1 = A4GL_new_expr_simple (ET_EXPR_PAGENO);
	}

      if (A4GL_aubit_strcasecmp (s, "lineno") == 0)
	{
	  flg = 1;
	  p1 = A4GL_new_expr_simple (ET_EXPR_LINENO);
	}

      if (flg == 0)
	{
	  p1 = A4GL_new_expr_push_variable (s, (int) scan_variable (s));
	}


      if (p1 == 0)
	{
	  PRINTF ("Thought I'd got all of these :%s\n", s);
	  A4GL_assertion (1, "Thought I'd got all of these");
	  //p1 = A4GL_new_expr (s);
	}
    }



  if (a == -1)
    {
      char buff[25600];		// Typically a substr-check for that first...
      if (strstr (s, "a4gl_substr"))
	{
	  char *ptr_str;
	  char *ptr_len;
	  char *ptr_s;
	  char *ptr_e;
	  char *ptr;
	  int type = -1;

	  ptr_str = &s[13];
	  ptr_len = strchr (ptr_str, ',');
	  *ptr_len = 0;
	  ptr_len++;
	  ptr_s = strchr (ptr_len, ',');
	  *ptr_s = 0;
	  ptr_s++;
	  ptr_e = strchr (ptr_s, ',');
	  *ptr_e = 0;
	  ptr_e++;

	  ptr = strchr (ptr_e, ',');

	  if (ptr)
	    {
	      *ptr = 0;
	      type = 0;
	      ptr++;
	      if (ptr[0] == ' ' && ptr[1] == '0' && ptr[2] == ' ')
		{
		  *ptr = 0;
		  type = 1;
		}
	    }
	  else
	    {
	      if (ptr_e[0] == ' ' && ptr_e[1] == '0' && ptr_e[2] == ' ')
		{
		  *ptr_e = 0;
		  ptr_e = "0";
		  type = 0;
		}
	    }

	  p1 =
	    A4GL_new_substring_expr (ptr_str, atol (ptr_len), ptr_s, ptr_e,
				     type);
	  return p1;
	}
      else
	{
	  A4GL_assertion (1, "Is this used for anything else ?");
	}

	  A4GL_assertion (1, "Is this used for anything else too ?");
     SPRINTF1 (buff, "A4GL_push_char(%s); /* NOT SUBSTR EXPR */", s);;
      p1 = A4GL_new_expr_obsol (buff);
    }

  if (a == -2)
    {
      p1 = print_push_rec (s, 0, 0);
    }
  return p1;

}

/*
int A4GL_am_doing_a_print(void) {
	return doing_a_print;
}
*/



struct binding_comp *
ensure_bind (long *a_bindp, long need, struct binding_comp *b)
{
  long a_bind;
  a_bind = *a_bindp;
  A4GL_debug ("ensure bind %d %d\n", a_bind, need);

  if (a_bind > need)
    return b;

  while (a_bind <= need)
    {
      if (a_bind == 0)
	a_bind = 2000;		// Start off small :-)
      else
	{
	  a_bind = a_bind * 2;	// just double it ?
	}
    }
  b = realloc (b, sizeof (struct binding_comp) * a_bind);
  A4GL_debug ("ensure bind Allocted %d\n", a_bind);
  A4GL_assertion (b == 0, "Unable to allocation memory for binding");
  *a_bindp = a_bind;
  return b;
}



struct binding_list *
new_bind_list (char *s)
{
  struct binding_list *l;
  l = malloc (sizeof (struct binding_list));
  l->bindings = 0;
  l->nbindings = 0;
  if (s)
    {
      append_bind_list (l, s);
    }
  return l;
}

struct binding_list *
append_bind_list (struct binding_list *l, char *s)
{
  l->nbindings++;
  l->bindings = realloc (l->bindings, l->nbindings * sizeof (char *));
  l->bindings[l->nbindings - 1] = strdup (s);
  return l;
}


void
print_display_by_name (char *attr)
{
  int a;
  char tabname[40];
  char colname[40];

  t_dt_display dt;
  struct expr_str *e;
  struct expr_str_list *l;
  l = A4GL_new_ptr_list (0);
  dt.u_data.field_list = new_field_list ();

  for (a = 0; a < ibindcnt; a++)
    {
      e = A4GL_new_expr_push_variable (ibind[a].varname, ibind[a].dtype);
      l = A4GL_new_append_ptr_list (l, e);

      A4GL_bname (ibind[a].varname, tabname, colname);
      append_field_to_list (dt.u_data.field_list,
			    new_field_entry (colname, "1", 1));
    }

  dt.type = DT_DISPLAY_TYPE_FIELD_LIST;

  print_display_new (l, &dt, attr);
  start_bind ('i', 0);

}



int
A4GL_4glc_push_gen_expand (int n, char *v)
{
  int a;
  struct record_list *list;

  if (strncmp (v, "?,", 2) == 0 || strncmp (v, "?@@PARAM@@?,", 2) == 0)
    {
      int x;
      if (strncmp (v, "?,", 2) == 0)
	{
	  x = ((strlen (v) + 1) / 2);
	}
      else
	{
	  x = ((strlen (v) + 1) / 12);
	}
      for (a = 0; a < x; a++)
	{
	  if (A4GL_isyes (acl_getenv ("DOING_CM")))
	    {
	      A4GL_4glc_push_gen (n, "?@@PARAM@@?");
	    }
	  else
	    {
	      A4GL_4glc_push_gen (n, "?");
	    }
	}
      return 1;
    }

  if (strstr (v, ".*") == 0)
    {
      A4GL_4glc_push_gen (n, v);
      return 1;
    }

  list = split_record_list (v, "", 0);
  A4GL_debug ("Got list : %p", list);

  if (list == 0)
    {
      a4gl_yyerror ("OOps\n");
      return -1;
    }


  for (a = 0; a < list->records_cnt; a++)
    {
      A4GL_4glc_push_gen (n, list->list[a]->name);
    }

  return 1;
}







void
add_sql_function (char *s)
{
  FILE *f = 0;
  if (A4GL_isyes(acl_getenv("LOGSQLFUNCTIONS"))) {
  f = fopen ("/tmp/sqlcall.log", "a");
  if (!f)
    return;
  FPRINTF (f, "%s %s %d\n", s, A4GL_compiling_module (), yylineno);
  fclose (f);
  }
}



int
get_sio_ids (char *s)
{
  return get_block_no (get_sio_id (s) - 1);
}


void
add_replace (char *a, char *b)
{
  nreplacements++;
  replacements =
    realloc (replacements, sizeof (struct s_replacements) * nreplacements);
  replacements[nreplacements - 1].find = strdup (a);
  replacements[nreplacements - 1].replace = strdup (b);
}


void
drop_replace (char *a)
{
  int z;
  for (z = 0; z < nreplacements; z++)
    {
      if (replacements[z].find == 0)
	continue;
      if (strcmp (replacements[z].find, a) == 0)
	replacements[z].find = 0;
    }
}



struct expr_str *
get_for_default_step (void)
{
  struct expr_str *ptr;
  ptr = A4GL_new_literal_long_str ("1");
  return ptr;
}






char *get_force_ui() {
	return force_ui;
}





int A4GL_is_internal_class_function(char *class,char *name) {
	return 1;
}




/* ================================= EOF ============================= */
