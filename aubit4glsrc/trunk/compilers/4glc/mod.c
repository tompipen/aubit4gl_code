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
# $Id: mod.c,v 1.91 2003-01-14 09:25:46 mikeaubury Exp $
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

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define USE_PRINTCOMMENT
#define GEN_STACKS 		10
#define MAXVARS 		2000
#define EMPTY 			"----"
#define MAXMENU 		10
#define MAXMENUOPTS 	10

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

extern int 	menu_cnt; 		/** The count of menus found */
extern int 	yylineno; 		/** The source file line number */
extern char *infilename;    /** The input (4gl file name */
extern int 	in_define;

static int 	db_used = 0;     /** Flag that indicate that a database is being used */
static int 	inc = 0;
static char pklist[2048] = "";
static char upd_using_notpk[5000] = "";
static int 	upd_using_notpk_cnt = 0;
static int 	const_cnt = 0;

int 		rep_type = 0; /** The report type */
int 		last_var_found = -1;
int 		var_hdr_finished;
int isin_command (char *cmd_type);


struct s_constants 			/** Array of constants defined in some scope */
{
  char type;     /**< The constant type */
  void *ptr;     /**< A pointer to the value of the constant */
  char name[32]; /**< The constant name */
  char scope;    /**< The scope  g : Global; m : Modular; f : Function*/
}
const_arr[MAXCONSTANTS];


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

char 		when_to_tmp[64];
char 		when_to[64][8];
int 		menu_nos[100];
int 		cmenu = 0;
int 		use_group = 0;
char 		curr_rep_name[256];
int 		curr_rep_block;
int 		max_menu_no = 0;
struct 		s_report sreports[1024];
int 		sreports_cnt = 0;
char 		mmtitle[132][132];         	/** Menu titles */
extern char *outputfilename;    		/** Variables dump output file name */
int 		read_glob_var = 0;
int 		counters[256];
int 		count_counters = 0;
struct 		s_report_stack report_stack[REPORTSTACKSIZE];
int 		report_stack_cnt = 0;
int 		report_cnt = 1;
int 		nblock_no = 1;
char 		gen_stack[GEN_STACKS][100][80];
int 		gen_stack_cnt[GEN_STACKS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
struct 		s_constr_buff constr_buff[256];
int 		constr_cnt = 0;

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
struct binding_comp ordbind[NUMBINDINGS];

int 		ordbindcnt = 0;
int 		ibindcnt = 0;           /** Number of elements in ibind array */
int 		nullbindcnt = 0;
int 		obindcnt = 0;
int 		fbindcnt = 0;

/** Array of variables found. The level gives us the scope variable */
struct variables
{
  char var_name[65];     /**< The name of the variable */
  char var_type[20];     /**< The data type of the variable */
  char var_size[20];     /**< The size in bytes of the variables */
  char var_arrsize[20];  /**< The number of elements if the variable is array */
  int alev1;
  int alev2;
  int alev3;
  int level;             /**< _The level. I think the record */
  char *tabname;         /**< The name of the name if like */
  char *pklist;
  char globflg;
} vars[MAXVARS];

/**
 * Module current scope level for variable declaration.
 *
 * It contains:
 *   - -1  : Global variables
 *   - 0   : Modular variables
 *   - > 0 : Function local variables
 */
int 		modlevel = -1;

/** Command stack array */
struct cmds
{
  char cmd_type[20];
  int block_no;

} command_stack[200];

/** Command stack counter / index (number of elements in command_stack) */
/*
#ifdef LEXER
int ccnt = 0;
#else
*/
extern int 	ccnt;  /* in lexer.c */
/* #endif */


/** Array index to the last variable filled in the variables array  */
int 		varcnt = 0;
int 		in_record = 0;
struct 		s_menu_stack menu_stack[MAXMENU][MAXMENUOPTS]; /** The menu stack array */


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

static int 			is_pk 				(char *s);
int 				yywrap 				(void);
struct sreports * 	get_sreports		(int z);
void 				a4gl_add_variable 	(char *name, char *type, char *n);


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

  debug ("strip_bracket\n");
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
  debug ("with_strip_bracket\n");
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
//?static
void
a4gl_add_variable (char *name, char *type, char *n)
{

  debug ("a4gl_add_variable");

  //We core dump on Solaris here, if DEBUG is set:

  debug ("a4gl_add_variable (name = %s type = %s n = %d varcnt = %d)\n",
	 name, type, n, varcnt);

  vars[varcnt].level = in_record;


  if (name != 0)
    strcpy (vars[varcnt].var_name, name);

  else
    strcpy (vars[varcnt].var_name, EMPTY);

  if (type != 0)

    strcpy (vars[varcnt].var_type, type);

  else
    strcpy (vars[varcnt].var_type, EMPTY);

  if (n != 0)
    {

		/* debug (" global variables: n = %d \n", n); */
		/* global variables: n = 2563 */
		/* we core dump here on CygWin: */

      debug ("assigning vars[varcnt].var_size ...\n");
      strcpy (vars[varcnt].var_size, n);
      debug ("/* global variables: vars[varcnt].var_size = %d */\n",
	     vars[varcnt].var_size);

    }
  else
    {
      strcpy (vars[varcnt].var_size, EMPTY);
    }

  strcpy (vars[varcnt].var_arrsize, EMPTY);

  debug ("added var\n");
  vars[varcnt].tabname = EMPTY;
  vars[varcnt].pklist = EMPTY;
  if (varcnt >= MAXVARS)
    {
      exitwith ("Too many variables");
      yyerror ("Too many variables");
    }
  varcnt++;

}

/**
 * Clear the variable stack by setting the counter to zero.
 */
void 
clr_variable (void)
{
  varcnt = modlevel;
}

/**
 *
 */
void 
inmod (void)
{
  modlevel = varcnt;
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
int isin_command (char *cmd_type)
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
	    debug ("OK\n");
	    return z+1;
	  }
  }
  return 0;
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
static int
print_record(int z, char ff,char *vname)
{
  int a;
  /*  It should be declared here because the two function are tighly coupled */
  static void print_variable(int z, char ff);


  debug("Print record %s\n",vname);

  if (isin_command ("REPORT")||
			isin_command("FORMHANDLER")||
			isin_command("MENUHANDLER"))
  {
    if (ff != '-')
	  {
	    print_start_record (1,vname);
	  }
    else
	  {
	    print_start_record (0,vname);
	  }
  }
  else
  {
    if (ff != 'G')
	    print_start_record (0,vname);
		else
	    print_start_record (2,vname);
  }

  for (a = z + 1; a < varcnt; a++)
  {

    if (strcmp (vars[a].var_type, "_RECORD") == 0)
	  {
	    if (vars[a].level > vars[z].level)
	      a = print_record (a, '-',vars[a].var_name);

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
	debug("print_end_record %s %s",vars[z].var_name, vars[z].var_arrsize);

    print_end_record (vars[z].var_name, vars[z].var_arrsize);
  }
  return a;
}

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
 * Print the variable in variables array by is index.
 *
 * The result is composed in a temporary buffer and the called the function
 * that generates the variable declaration in the target language to the
 * target generated file.
 *
 * @param z The variable index in the array.
 * @param ff The scope of the variable.
 *   - L : The variable is local to function
 *   - G : The variable have global scope
 *   - n
 *   - M : The variable is with modular scope
 */
static void 
print_variable (int z, char ff)
{
  char tmpbuff[80];

  debug ("Printing variable %c %s", ff, vars[z].var_name);

  if (strcmp (vars[z].var_name, "time") == 0)
    return;

  if (strcmp (vars[z].var_type, "_ENDREC") == 0)
  {
      return;
  }

  if (strcmp (vars[z].var_type, "_ASSOCIATE") == 0)
  {
    print_declare_associate_2 (
		  vars[z].var_name, 
			vars[z].var_size,
		  vars[z].var_arrsize
		);
    return;
  }

  if (strcmp (vars[z].var_type, "_RECORD") == 0)
  {
    setinc (1);
    print_record (z, ff,vars[z].var_name);
    setinc (-1);
    return;
  }

  if (strcmp (vars[z].var_arrsize, EMPTY) == 0)
    {
      sprintf (tmpbuff, "%s %s", vars[z].var_type, vars[z].var_name);
    }
  else
    {
      sprintf (tmpbuff, "%s %s[%s]", vars[z].var_type,
	       vars[z].var_name,  (vars[z].var_arrsize));
    }

  if (isin_command ("REPORT")||isin_command("FORMHANDLER")||isin_command("MENUHANDLER"))
    {
      if (strcmp (vars[z].var_type, "char") == 0)
	{
	  if (ff != '-')
	    {
	      print_define_char (tmpbuff, atoi (vars[z].var_size), 1);
	    }
	  else
	    {
	      print_define_char (tmpbuff, atoi (vars[z].var_size), 0);
	    }
	}
      else
	{
	  if (ff != '-')
	    {
	      print_define (tmpbuff, 1);
	    }
	  else
	    {
	      print_define (tmpbuff, 0);
	    }
	}
    }
  else
    {
      if (strcmp (vars[z].var_type, "char") == 0)
	{
	  if (ff != 'G')
	    {
	      print_define_char (tmpbuff, atoi (vars[z].var_size), 0);
	    }
	  if (ff == 'G')
	    {
	      print_define_char (tmpbuff, atoi (vars[z].var_size), 2);
	    }
	}
      else
	{
	  if (ff != 'G')
	    {
	      print_define (tmpbuff, 0);
	    }
	  if (ff == 'G')
	    {
	      print_define (tmpbuff, 2);
	    }
	}
    }

}

/**
 * Dumps the global variables to a file named <target_file>.glb
 */
static void 
dump_gvars(void)
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

		trim (vars[a].var_name);
		if (strcmp (vars[a].var_name, "***CONSTANTS***") == 0)
        {
			debug ("Found ***CONSTANTS*** (2) \n");
        }
        else
        {
			fprintf (f, "%s %s %s %s %s %s %d\n",
		       vars[a].var_name,
		       vars[a].var_type,
		       vars[a].var_size,
		       vars[a].var_arrsize,
		       vars[a].tabname, vars[a].pklist, vars[a].level);
        }

    }
  
	fprintf (f, "***CONSTANTS***\n");

	for (a = 0; a < const_cnt; a++)
    {
		if (const_arr[a].scope == 'g')
			fprintf (f, "%c %s %p\n", const_arr[a].type, const_arr[a].name,
				const_arr[a].ptr);
    }

	fclose (f);
}

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

/**
 * Dumps the contents of all of the array variable to a file named dumpvars.out.
 *
 * It only does this action if environment variable DUMPVARS is assigned.
 *
 * It is mainly used to debug the code generation
 *
 */
void 
dump_vars (void)
{

  FILE *f;

  int a;
  if (acl_getenv ("DUMPVARS") == 0)
    return;

  f = (FILE *) mja_fopen ("dumpvars.out", "w");

  for (a = 0; a < varcnt; a++)
    {

      fprintf (f, " %d - %s;%s;%s;%s;%d;%s;%s\n", a,
	       ignull (vars[a].var_name),
	       ignull (vars[a].var_type),
	       ignull (vars[a].var_size),
	       ignull (vars[a].var_arrsize),
	       vars[a].level,
	       ignull (vars[a].tabname), ignull (vars[a].pklist));

    }

  fclose (f);

}

/**
 * Print variable declaration for the scope wanted.
 *
 * The scope level is defined by the global modlevel
 *
 */
void 
print_variables (void)
{

  int a;

  /* dump_vars (); */

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

      for (a = 0; a < varcnt; a++)
	{
	  if (vars[a].level == 0)
	    {
	      if (vars[a].globflg == 'G')
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
  debug ("push_name  a = %s n = %d \n", a, n);
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
	      print_declare_associate_1 (vars[z].var_name, as, n);
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
	  /* strcpy (vars[z].var_arrsize, EMPTY); */
	}

    }

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
 * Does nothing
 */
void 
pop_associate (char *a)
{
  /*a4gl_add_variable (0,"_ENDASSOC", 0); */
}

/**
 *
 * @param tab
 * @param pkey
 */
void 
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

/**
 *
 */
void 
pop_record (void)
{

  /* in_record--; */
  debug ("In mod.c : pop_record\n");

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

/**
 * Obtain the value of the inc variable.
 *
 * @return The content of the inc variable.
 */
int
getinc(void)
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
static int 
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

/**
 * Identifies the data type from a string and convert it to numeric with
 * the goal of being more easyli used.
 *
 * @todo organize some defines to the data types.
 *
 * @param s The string where the data type will be scanned
 * @return The data type in numeric code
 */
static int 
find_type (char *s)
{
  char errbuff[80];

  debug("Looking for type '%s'",s);
  if (find_datatype_out(s)!=-1) {
		debug("Found it...");
		return find_datatype_out(s);
  }

  debug("Not found - keep looking");
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

  if (strcmp ("form", s) == 0)
    return 9;

  debug ("Invalid type : %s\n", s);
  sprintf (errbuff, "Internal Error (Invalid type : %s)\n", s);
  yyerror (errbuff);
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

  if (s[0] == '.' && s[1] == '\0')
    return -1;

  if (s[0] == 0)
    return -1;

  if (strchr (s, '\n'))
    return -2;			/* This is a variable thru variable.. */

  strcpy (buff, s);
  if (s[0] == ' ')
    {
      if (strncmp (buff, " ASSOCIATE_", 11) == 0)
	{
	  strcpy (buff, &s[11]);
	  strcpy (buff2, &s[findex (s, ')') + 1]);
	  buff[findex (buff, '(')] = 0;
	  strcat (buff, buff2);
	  convlower (buff);
	}
      else
	return -1;
    }

  strip_bracket (buff);
  /* debug ("Stripped\n"); */

  strcat (buff, ".");
  ptr = strtok (buff, ".");
  /* debug ("Looking for %s", buff); */
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

      /* debug ("Check %d > %d...", lvl, vars[a].level); */

      if (lvl > vars[a].level)
	break;
      /*
      debug ("Checking %s %s  %d %d", ptr, vars[a].var_name, vars[a].level, lvl);
      */

      if ((strcmp (ptr, "*") == 0 || strcmp (vars[a].var_name, ptr) == 0)
	  && vars[a].level == lvl)
	{
	  ptr = strtok (0, ".");
	  if (ptr == 0)
	    {
	      /* debug ("Got no more to check"); */
	    }
	  else
	    {
	      /*
		  debug ("Got more to check '%s'", ptr);
	      debug ("vn=%s %s %s %s", vars[a].var_name, vars[a].var_type,
	      vars[a].var_arrsize, vars[a].var_size);
          */
	      if (strcmp (vars[a].var_type, "_RECORD") == 0)
		{
		  /* debug ("_RECORD...."); */
		  while (a < varcnt)
		    {
		      /* debug ("Looking for more record declarations...."); */
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

	  /* debug ("flg=%d", flg); */

	  if (flg)
	    {
	      /* debug ("Types : %s %s", vars[a].var_type, vars[a].var_size); */
	      z =
		find_type (vars[a].var_type) +
		(atoi (vars[a].var_size) << 16);
	      /* debug ("Setting last_var_found to %d\n", a); */
	      last_var_found = a;
	      /* debug ("Find type returned %x", z); */
	      return z;
	    }
	  /* debug ("More levels..."); */

	  lvl++;

	}

    }
  debug ("Variable not there : %s", s);

  return -1;

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
  a = isvartype (s, 1);
  debug ("Checking if %s is an array %d", s, a);
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
  return isvartype (s, 2);
}

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
		      print_range_check (s, vars[a].var_arrsize);
		    }
	      return find_type (vars[a].var_type);
	    }
	    lvl++;
	  }
  }

  debug ("// Warning    Couldnt find %s \n", s);

  return -1;

}
*/


/**
 * Adds a new variable to the variable array.
 *
 * Fills the structure whit received parameters.
 * Increment the index that indicates the number of elements in the array
 *
 * @param name The variable name
 * @param type The variable data type
 * @param n The size of the variable (wich one ?)
 * @param as The size of the array if the variable is of that type
 * @param lvl Scope level (Global, Modular or Local)
 */
static void
set_variable (char *name, char *type, char *n, char *as, int lvl)
{

  vars[varcnt].level = lvl;
  strcpy (vars[varcnt].var_name, name);
  strcpy (vars[varcnt].var_type, type);
  strcpy (vars[varcnt].var_size, n);
  strcpy (vars[varcnt].var_arrsize, as);

  if (varcnt >= MAXVARS)
    {
      exitwith ("Too many variables");
      yyerror ("Too many variables");
    }
  varcnt++;

}

/**
 * 
 * @param t
 * @param ptr
 * @param name
 */
void
add_constant (char t, char *ptr, char *name)
{
  char scope = 'm';
  int x;
  char buff[256];
  x = 0;
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

  if (isin_command ("FUNC") || isin_command ("REPORT")
      || isin_command ("FORMHANDLER") || isin_command ("MENUHANDLER"))
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
}

/**
 * Set the internal 4gl variables in the array.
 */
void 
set_4gl_vars(void)
{

  set_variable ("int_flag", 	"long", 	"0", 		"----", 0);
  set_variable ("quit_flag", 	"long", 	"0", 		"----", 0);
  set_variable ("status", 		"long", 	"----", 	"----", 0);
  set_variable ("sqlca", 		"_RECORD", 	"----", 	"----", 0);
  set_variable ("sqlcode", 		"long", 	"----", 	"----", 1);
  set_variable ("sqlerrm", 		"char", 	"71", 		"----", 1);
  set_variable ("sqlerrp", 		"char", 	"8", 		"----", 1);
  set_variable ("sqlerrd", 		"long", 	"----", 	"6", 1);
  set_variable ("sqlawarn", 	"char", 	"8", 		"----", 1);
  set_variable ("sqlstate", 	"char", 	"9", 		"----", 1);
  set_variable ("----", 		"_ENDREC", 	"----", 	"----", 0);

  set_variable ("today", 		"fgldate", 	"----", 	"----", 0);
  set_variable ("user", 		"char", 	"8", 		"----", 0);
  set_variable ("notfound", 	"long", 	"----", 	"----", 0);
  set_variable ("pageno", 		"long", 	"----", 	"----", 0);
  set_variable ("lineno", 		"long", 	"----", 	"----", 0);
  set_variable ("usrtime", 		"long", 	"----", 	"----", 0);

/* These are for my personal use! MJA */
  set_variable ("curr_hwnd", 	"long", 	"----", 	"----", 0);
  set_variable ("curr_form", 	"long", 	"----", 	"----", 0);

  set_variable ("err_file_name","char", 	"32", 		"----", 0);
  set_variable ("err_line_no", 	"long", 	"----", 	"----", 0);

  set_variable ("curr_file_name", "char", 	"32", 		"----", 0);
  set_variable ("curr_line_no", "long", 	"----", 	"----", 0);

  set_variable ("err_status", 	"long", 	"----", 	"----", 0);
  set_variable ("aiplib_status", "long", 	"----", 	"----", 0);

  set_variable ("time", 		"char", 	"8", 		"----", 0);
  
  add_constant ('i', "100", strdup ("notfound"));
  var_hdr_finished = varcnt;
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
char db[132];
char buff[256];

debug("open_db %s", s);

  strcpy (db, s);
  A4GLSQL_set_status (0, 1);
  A4GLSQL_init_connection (db);
  if (A4GLSQL_get_status () != 0)
    {
      sprintf (buff, "Could not connect to database %s (%s)", s,
	       A4GLSQL_get_sqlerrm ());
      yyerror (buff);
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
static char *
rettype (char *s)
{
  static char rs[20] = "long";
	int a;
  debug ("In rettype : %s", s );

  a=atoi(s);

  debug("In rettype");
  if (has_datatype_function_i(a,"OUTPUT")) 
  {
	/* char *(*function) (); */
    char *(*function) (void);
	debug("In datatype");
	function=get_datatype_function_i(a,"OUTPUT");
	debug("Copy");
	strcpy(rs,function());
	debug("Returning %s\n",rs);
	return  rs;
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

  if (strcmp (s, "11") == 0)
    strcpy (rs, "fglbyte");
  if (strcmp (s, "12") == 0)
    strcpy (rs, "fgltext");
  if (strcmp (s, "13") == 0)
    strcpy (rs, "char");

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
pushLikeTableColumn(char *tableName,char *columnName)
{
int rval;
int idtype;
int isize;
char csize[20];
char cdtype[20];
char buff[300];

  debug ("pushLikeTableColumn()");
  rval = A4GLSQL_read_columns (tableName, columnName, &idtype, &isize);
  if (rval == 0)
  {
    sprintf (buff, "%s.%s does not exist in the database",tableName,columnName);
    yyerror (buff);
    return 0;
  }
  sprintf (cdtype, "%d", idtype & 15);
  sprintf (csize, "%d", isize);
  trim_spaces (columnName);
  push_type (rettype (cdtype), csize, (char *)0);
  return 1;
}

/**
 * Find all columns of a table from the database to declare a record like
 * table.*
 *
 * @param tableName The name of the table
 */
static int 
pushLikeAllTableColumns(char *tableName)
{
  int rval;
  int isize = 0;
  int idtype = 0;
  char colname[256] = "";
  char csize[20];
  char cdtype[20];
  char buff[300];
  char *ccol;

  debug ("pushLikeAllTableColumns()");
  /* A4GLSQL_get_columns (char *tabname, char *colname, int *dtype, int *size) */
  rval = A4GLSQL_get_columns(tableName,colname,&idtype, &isize);
  if (rval == 0 && tableName)
  {
    sprintf (buff, "%s does not exist in the database", tableName);
    yyerror (buff);
    return 1;
  }

  while (1)
  {
    colname[0] = 0;

    /* int A4GLSQL_next_column(char **colname, int *dtype,int *size); */
    rval = A4GLSQL_next_column(&ccol,&idtype,&isize);
    debug ("next column for table '%s' is '%s'", tableName, ccol);

    strcpy(colname,ccol);

	/*
	warning: passing arg 1 of `A4GLSQL_next_column' from incompatible pointer type
    we are sending char ARRAY to function expecting char POINTER !!!!
    */

    if (rval == 0 )
      break;

    sprintf (cdtype, "%d", idtype & 15);
    sprintf (csize, "%d", isize);
    debug ("%d %d", idtype, isize);
    debug ("---> %s %s", cdtype, csize);
    debug ("A4GLSQL_read_columns: Pushing %s %s %s", colname, cdtype, csize);
    trim_spaces (colname);
    push_name (colname, 0);
    push_type (rettype (cdtype), csize, 0);
  }
  A4GLSQL_end_get_columns();
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

  tableName = strtok (buff, ".");	/* table name */
  columnName = strtok (0, ".");		/* column name */
  debug ("a='%s' b='%s'", tableName,columnName);

  if (columnName)
  {
    pushLikeTableColumn(tableName,columnName);
    return;
  }

  pushLikeAllTableColumns(tableName);
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

  debug (">>>>>> %s\n", t);
  push_like2(t);
  debug ("<<<<<<\n");
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

  debug ("START BLOCK %s", cmd_type);
  debug ("\n\n--------->%s\n\n", cmd_type);
  debug (" /* new block %s %d */\n", cmd_type, ccnt);
  strcpy (command_stack[ccnt].cmd_type, cmd_type);
  if (strcmp (cmd_type, "MAIN") == 0
      || strcmp (cmd_type, "FUNC") == 0 ||
      strcmp (cmd_type, "REPORT") == 0 || strcmp (cmd_type, "GLOBALS") == 0 ||
      strcmp (cmd_type, "FORMHANDLER") == 0 || strcmp (cmd_type, "MENUHANDLER") == 0)
    {
      command_stack[ccnt].block_no = -1;
    }
  else
    {

      print_start_block (nblock_no);

      command_stack[ccnt].block_no = nblock_no++;
    }
  debug (" Added new block");
  ccnt++;
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
  debug ("END BLOCK %s", cmd_type);

	/* more checks here ! */

  ccnt--;
  if (command_stack[ccnt].block_no > 0)
    {

      if (iscontinuecmd (cmd_type))
	{
	  print_continue_block (command_stack[ccnt].block_no, 1);
	}
      print_end_block (command_stack[ccnt].block_no);
    }

  debug ("\n\n--------->%s\n\n", cmd_type);

  if (strcmp (command_stack[ccnt].cmd_type, cmd_type) == 0)
    {

      command_stack[ccnt].cmd_type[0] = 0;

      return;

    }

  sprintf (err, "%s was not last block command (I've got a %s @ %d)\n",
	   cmd_type, command_stack[ccnt].cmd_type, ccnt);
  debug (err);
  debug ("------------------\n");
  for (a = 0; a <= ccnt; a++)
    {
      debug ("   %s\n", command_stack[a].cmd_type);
    }
  debug ("------------------\n");
  yyerror (err);
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
  debug ("Push %d %s\n", a, s);
  if (gen_stack_cnt[a] >= 90)
    {
      printf ("Out of stack!\n");

      exit (0);
    }
  strcpy (gen_stack[a][gen_stack_cnt[a]++], s);
}

/**
 * Not used
 *
 * @param a
 */
/*
static char *pop_gen (int a)
{
  gen_stack_cnt[a]--;
  gen_stack[a][gen_stack_cnt[a]];
}
*/

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
	debug ("%s ", s);
      debug ("%s", gen_stack[a][z]);
    }
}


/**
 * Not used
 */
/*
static yyerrorf (char *fmt, ...)
{
  char buff[256];
  va_list args;
  va_start (args, fmt);
  vsprintf (buff, fmt, args);
  yyerror (buff);
}
*/

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
  debug ("Checking if %s is a pk in %s", s, pklist);
  a = linked_split (pklist, 0, 0);
  for (cnt = 1; cnt <= a; cnt++)
  {
    linked_split (pklist, cnt, buff);
    if (aubit_strcasecmp (s, buff) == 0)
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


/**
 * @param s
 * @param bindtype
 *   - u :
 * @return 
 *   - -1 :
 *   - 0 :
 */
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

  /* The function should be declared here because they are thigly coupled
  int add_bind (char i, char *var); */
  /* BUT add_bind is already declared in a4gl+4glc_4glc.h !!! */


  debug ("In push_bind_rec : %s\n", s);

  strcpy (endoflist, "");
  if (strchr (s, '\n'))
    {
      int v1;
      int v2 = 0;
      char *ptr1;
      char *ptr2;

      char r1[256];
      char r2[256];
      char buff[256];


      strcpy (save, s);
      s = save;

      ptr = strchr (save, '\n');

      *ptr = 0;
      ptr++;
      strcpy (endoflist, ptr);
      debug ("Thru splits to %s and %s", s, ptr);

      strcpy (r1, s);
      ptr1 = strrchr (r1, '.');
      *ptr1 = 0;
      ptr1++;

      strcpy (r2, s);
      ptr2 = strrchr (r2, '.');
      *ptr2 = 0;

      if (strcmp (r1, r2) != 0)
	{
	  yyerror ("Records for thru look different...");
	}

      v1 = scan_variable (s);
      if (v2 == -1)
	{
	  yyerror ("Variable not found (first entry in thru)");
	}
      v1 = last_var_found;
      debug ("v1=%d", v1);

      v2 = scan_variable (ptr);
      if (v2 == -1)
	{
	  yyerror ("Variable not found (second entry in thru)");
	}
      v2 = last_var_found;
      debug ("v2=%d", v2);

      for (a = v1; a <= v2; a++)
	{
	  sprintf (buff, "%s.%s", r1, vars[a].var_name);
	  add_bind (bindtype, buff);
	}
      return 0;
    }

  if (s[0] == '.' && s[1] == 0)
    return -1;
  if (s[0] == 0)
    return -1;

  strcpy (buff, s);

  if (strchr (s, '.') == 0)
    {
      strcat (buff, ".*");
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
      if ((strcmp (ptr, "*") == 0 || 1)
	  /* || strcmp (vars[a].var_name, with_strip_bracket (ptr)) == 0) */
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
add_bind (char i, char *var)
{
  long dtype;

  if (var[0] == '"')
    {
      dtype = (strlen (var) - 2) << 16;
    }
  else
    {
      dtype = scan_variable (var);
    }

  debug ("add_bind - dtype=%d (%s)\n", dtype, var);

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




  if (i == 'f' || i == 'F')
    {
      if (i == 'f')
	dtype = -1;

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

  if (i == 'f' || i == 'F')
    {
      fbindcnt = 0;
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
  if (i == 'f' || i == 'F')
    return fbindcnt;
  return 0;
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
  print_continue_loop (command_stack[a].block_no,cmd_type);
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

  if (strcmp (cmd_type, "MENU") == 0)
  {
    print_exit_loop ('M', 0);
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
  strcpy (rep->output_loc, "\"stdout\"");
}


void 
pdf_init_report_structure (struct pdf_rep_structure *rep)
{
debug("ZZ1 init structure...");
  rep->top_margin = -36.0;
  rep->bottom_margin = -36.0;
  rep->left_margin = -36.0;

  rep->page_length = -842.0;		/* A4 */
  rep->page_width = -595.0;			/* A4 */

  rep->right_margin = rep->page_width - (2 * rep->left_margin);

  rep->page_no = 0;
  rep->printed_page_no = 0;
  rep->line_no = 0.0;
  rep->col_no = 0.0;
  rep->output_mode = 'F';
  rep->font_size = 10;
  rep->paper_size = 0;
  strcpy (rep->font_name, "\"Helvetica\"");
  strcpy (rep->output_loc, "\"stdout\"");
}

/**
 *
 *
 * @param
 */
void
resize_paper(struct pdf_rep_structure *pdf_rep_struct)
{
int portrait=1;
float a;

	debug("ZZ1 Fixing paper size.....");

	if (pdf_rep_struct->paper_size!=0) 
	{

		if (pdf_rep_struct->paper_size<0)
		{
				portrait=0;
				pdf_rep_struct->paper_size=0-pdf_rep_struct->paper_size;
		}

		switch (pdf_rep_struct->paper_size)
		{
		case 1:
			pdf_rep_struct->page_length=0-a4_height;
			pdf_rep_struct->page_width=0-a4_width;
			break;
		case 2:
			pdf_rep_struct->page_length=0-letter_height;
			pdf_rep_struct->page_width=0-letter_width;
			break;
		case 3:
			pdf_rep_struct->page_length=0-legal_height;
			pdf_rep_struct->page_width=0-legal_width;
			break;

		case 4:  /* Not used.... */
			pdf_rep_struct->page_length=0-a4_height;
			pdf_rep_struct->page_width=0-a4_width;
			break;

		case 5:
			pdf_rep_struct->page_length=0-a5_height;
			pdf_rep_struct->page_width=0-a5_width;
			break;

		}
	}


	if (portrait==0)  /* Its landscape - swap it around.... */
    {
		a=pdf_rep_struct->page_length;
		pdf_rep_struct->page_length=pdf_rep_struct->page_width;
		pdf_rep_struct->page_width=a;
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
  debug ("Scanning order by for %s %d", varname, ordbindcnt);
  for (a = 0; a <= cnt; a++)
    {
      debug ("/* chk %s against %s */\n", varname, ordbind[a].varname);
      if (aubit_strcasecmp (ordbind[a].varname, varname) == 0)
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
reset_attrib (struct form_attr * form_attrib)
{
  debug ("Reseting attributes\n");
  form_attrib->iswindow     = 0;

  form_attrib->attrib       = 0xffff;

  form_attrib->form_line    = 0xff;
  form_attrib->error_line   = 0xff;
  form_attrib->comment_line = 0xff;
  form_attrib->message_line = 0xff;
  form_attrib->prompt_line  = 0xff;
  form_attrib->menu_line    = 0xff;

  form_attrib->border       = 0;
}


/**
 *
 *
 * @param
 */
int
attr_code (char *s)
{

 debug ("Decoding colour %s\n", s);

  return get_attr_from_string(s);

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
static int
matoi (char *s)
{
  int a;
  if (s == 0)
    return 0;
  a = atoi (s);
  return a;
}

/**
 *
 *
 * @param
 */
long
get_variable_dets (char *s, int *type, int *arrsize,
		   int *size, int *level, char *arr)
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



/**
 *
 *
 * @param
 */
void
drop_counter(void)
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
  debug ("/* get_counter_val =  %d counter number %d*/\n",
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
  debug ("/* inc_by =  %d counter number %d*/\n",
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
  if (i == 'o')
    {
      obindcnt = 0;
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
  strcpy (constr_buff[constr_cnt].tab, a);
  strcpy (constr_buff[constr_cnt].col, b);
  constr_cnt++;
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

/**
 * Compile the 4gl source with -G option to generate the .glb file
 *
 * This file is then readed to generate the externs in C.
 *
 * @param s The 4gl file name (without extension).
 */
static void
generate_globals_for (char *s)
{
char buff[1024];
char dirname[1024];
char fname[1024];
char *ptr;
char nocfile[256];

  debug ("In generate_globals_for\n");

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

/**
 * Read the gobals file (.glb).
 *
 * @param s The file name (without .glb extension).
 */
void 
read_glob (char *s)
{
FILE *f;
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
    	#ifdef DEBUG
			debug ("Trying to compile globals file");
        #endif
		generate_globals_for (ii);
		f = mja_fopen (ii, "r");
    }

	if (f == 0)
    {
    	fprintf (stderr, "Couldnt open globals file %s\n", ii);
		exit (7);
    }

	#ifdef DEBUG
		debug ("Opening %s\n", ii);
    #endif

	fgets (line, 255, f);
	strcpy (dbname, "");
	sscanf (line, "DATABASE=%s", dbname);

	if (strlen (dbname) > 0)
    {
    	set_hdrdbname (dbname);
		open_db (dbname);
    }

	#ifdef DEBUG
		debug ("DBNAME=%s from globals", dbname);
    #endif
  
	while (!feof (f))
    {
    	fgets (line, 255, f);
		if (feof (f))
			break;
		/* did not catch it:
		trim (line);
		if (strcmp (line, "***CONSTANTS***") == 0)
        {
			debug ("Found ***CONSTANTS***\n");
			break;
        }
        */

	  	sscanf (line, "%s %s %s %s %s %s %d\n",
	      vars[varcnt].var_name,
	      vars[varcnt].var_type,
	      vars[varcnt].var_size,
	      vars[varcnt].var_arrsize, tname, pklist, &vars[varcnt].level);

        trim (vars[varcnt].var_name);
		if (strcmp (vars[varcnt].var_name, "***CONSTANTS***") == 0)
        {
			debug ("Found ***CONSTANTS*** (3)\n");
			break;
        }

		vars[varcnt].tabname = strdup (tname);
		vars[varcnt].pklist = strdup (pklist);

		#ifdef DEBUG
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
        #endif

		vars[varcnt].globflg = 'G';

		if (varcnt >= MAXVARS)
        {
			exitwith ("Too many variables");
			yyerror ("Too many variables");
		}

		varcnt++;
	}

	while (!feof (f))
    {
	char ct;
    char cn[256];
    char cv[256];
      
		fgets (line, 255, f);
		if (feof (f))
			break;
		trim (line);
		/* bug fix - possibly not neded? */
		if (strcmp (line, "***CONSTANTS***") == 0)
        {
			debug ("Found ***CONSTANTS***\n");
			break;
        }
		sscanf (line, "%c %s %s", &ct, cn, cv);
		add_constant (ct, cv, cn);
	}

	fclose (f);
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

debug("In add_report_agg a=%d\n",a);
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
	
      debug("Adding default where on report aggregate of 1");
      sreports[sreports_cnt].rep_where_expr=new_expr("push_int(1);");
    }
  else
    {
      debug("Adding non-default where on report aggregate");
      sreports[sreports_cnt].rep_where_expr=s2;
    }

	
  sreports[sreports_cnt].rep_cond_expr=s1;

  sreports[sreports_cnt].a = a;

  sreports[sreports_cnt].t = t;

  debug("sreports[%d].a=%d",sreports_cnt,a);

  sreports_cnt++;

  if (t == 'C')
    {
      lex_printh ("static long _g%d=0;\n", a);
      return 1;
    }

  if (t == 'P')
    {
      lex_printh ("static long _g%d=0,_g%d=0;\n", a, a + 1);
      return 2;
    }

  if (t == 'S')
    {
      lex_printh ("static double _g%d=0;\n", a);
      return 1;
    }

  if (t == 'N' || t == 'X')
    {
      lex_printh ("static double _g%d=0;\n", a);
      lex_printh ("static int _g%dused=0;\n", a);
      return 1;
    }

  if (t == 'A')
    {
      lex_printh ("static double _g%d=0;\n", a);
      lex_printh ("static long   _g%d=0;\n", a + 1);
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
  strcpy (curr_rep_name, "acl_fglr_");
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

/**
 *
 */
void
set_whento (char *p)
{
  debug ("whento = %p", p);
  strcpy (when_to_tmp, p);
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
 * @param p The action to execute.
 */
void
set_whenever (int c, char *p)
{
  int code;
  int oldcode;
  oldcode = c & 15;
  debug ("MJA Set_whenever : %d %s", c, p);
  c = c >> 4;
  c = c << 4;
  code = -1;
  switch (c)
    {
    case WHEN_ERROR:
	set_whenever (WHEN_SQLERROR,p);
        code = A_WHEN_ERROR;
      break;

    case WHEN_ANYERROR:
	set_whenever (WHEN_ERROR,p);
	set_whenever (WHEN_SQLERROR,p);
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

  print_clr_status ();
}

/**
 * Clear all constants.
 */
void 
clr_function_constants (void)
{
  int a;
  int lcnt = 0;
  debug ("Clr constants\n");
  for (a = 0; a <= const_cnt; a++)
    {
      if (const_arr[a].scope == 'f')
	{
	  const_arr[a].name[0] = 0;
	}
      else
	lcnt = a;

    }
  const_cnt = lcnt + 1;

}

/**
 *
 *
 * @param
 */
int
check_for_constant (char *name, char *buff)
{
  int x;

  if (in_define)
    return 0;

  for (x = 0; x < const_cnt; x++)
    {
      if (aubit_strcasecmp (name, const_arr[x].name) == 0)
	{
	  debug ("Found constant @ %d type=%c scope=%c", x, const_arr[x].type,
		 const_arr[x].scope);
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
  debug ("Menu no %d", max_menu_no);
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
      debug ("Reset Menu no %d", menu_cnt);
    }
  else
    {
      debug ("Nothing to reset to...");
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
  debug ("Converted : %s to %s", s, d);
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
 *
 * @param tabname
 * @param pklist
 * @return
 */
int
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

/**
 * Copy a value to the primary key list.
 *
 * @param s The string to be copied.
 */
void 
set_pklist (char *s)
{
  debug ("pklist set to %s\n", s);
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
  debug ("get_upd_using_notpk");
  debug ("Returning %s", upd_using_notpk);
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
 *
 * @param
 */
int
print_push_rec (char *s, char *b)
{
  int a;
  long z;
  int cnt = 0;
  char bb[256];
  char buffer[40000] = "";
  char buffer2[40000];
  char nbuff[40000];
  char *ptr;
  int lvf;
  char endoflist[256];
  char save[256];

  debug ("print_push_rec");
  strcpy (endoflist, "");

  if (strchr (s, '\n'))
    {
      debug ("Have a thru");
      strcpy (save, s);
      s = save;
      ptr = strchr (save, '\n');
      *ptr = 0;
      ptr++;
      strcpy (endoflist, ptr);
      debug ("Splits to %s and %s", s, endoflist);

    }
  strcpy (bb, s);

  bb[strlen (bb) - 1] = 0;

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

  lvf = last_var_found + 1;

  debug ("last_var_found=%d -> %s", lvf, vars[lvf].var_name);


  for (a = lvf; a < varcnt; a++)
    {
      if (strcmp (vars[a].var_type, "_ENDREC") == 0)
	{
	  debug ("Spotted ENDREC @ %d\n", a);
	  strcpy (b, buffer);
	  return cnt;
	}

      debug ("Testing variable @%d\n", a);
      z = find_type (vars[a].var_type) + (atoi (vars[a].var_size) << 16);


      if (z != -2)
	{
	  strcpy (buffer2, buffer);
	  sprintf (buffer, "%s   push_variable(&%s%s,0x%x);\n",
		   buffer2, bb, vars[a].var_name, (unsigned int)z);
	  cnt++;
	}
      else
	{
	  int c;
	  char nvar[256];
	  strcpy (buffer2, buffer);
	  sprintf (nvar, "%s%s.*", bb, vars[a].var_name);

	  debug ("recursing with %s\n", nvar);
	  c = print_push_rec (nvar, nbuff);
	  sprintf (buffer, "%s%s\n", buffer2, nbuff);
	  cnt += c;
	  a += c;
	  a++;
	}

      if (strcmp (vars[a].var_name, endoflist) == 0)
	{
	  debug ("Done the last one...");
	  break;
	}
    }
  return -1;
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
expand_bind (struct binding_comp * bind, int btype, int cnt)
{
  struct binding_comp save_bind[NUMBINDINGS];
  char buff[256];
  int a;
  for (a = 0; a < cnt; a++)
    {
      strcpy (save_bind[a].varname, bind[a].varname);
      save_bind[a].dtype = bind[a].dtype;
    }

  start_bind (btype, 0);

  for (a = 0; a < cnt; a++)
    {
      strcpy (buff, save_bind[a].varname);
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
  expand_bind (obind, 'o', obindcnt);
}

/**
 * Get a variable name at a specified position of  the variable array.
 *
 * @param z The position where to find the variable.
 * @return A pointer to the variable found.
 */
char *
get_var_name (int z)
{
  return vars[z].var_name;
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
      debug ("ptr=%s\n", ptr);
      ptr++;
      strcat (s, ptr);
    }

}

/**
 * Dump an expression if in debug mode.
 *
 * @param orig_ptr A pointer to the expression list
 */
void 
dump_expr (struct expr_str *orig_ptr)
{
  struct expr_str *start;
  start = orig_ptr;

	debug("DUMP EXPR : ");
      while (orig_ptr) {
	debug ("     %s",orig_ptr->expr);
	orig_ptr = orig_ptr->next;
    }
	debug("---------------------------------------------------");
}

/**
 * Allocate space and create a new expression structure.
 *
 * @param value The value to be added to the expression.
 * @return A pointer to the allocated expression.
 */
void *
new_expr (char *value)
{
  struct expr_str *ptr;
  debug ("new_expr - %s",value);
  ptr = malloc (sizeof (struct expr_str));
  ptr->next = 0;
  ptr->expr = strdup (value);
  debug ("newexpr : %s -> %p\n", value, ptr);
  dump_expr(ptr);
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
append_expr (struct expr_str *orig_ptr, char *value)
{
  struct expr_str *ptr;
  struct expr_str *start;
  start = orig_ptr;

  debug ("MJA append_expr %p (%s)", orig_ptr, value);

  ptr = new_expr (value);
  if (orig_ptr->next != 0)
    {
      while (orig_ptr->next != 0)
	orig_ptr = orig_ptr->next;
    }
  orig_ptr->next = ptr;
  debug ("Appended expr");
  dump_expr(start);
  return start;
}

/**
 * Insert a new expression at the end of anoher one.
 *
 * @param orig_ptr The expression to be appended.
 * @param second_ptr The expression to append.
 */
void *
append_expr_expr (struct expr_str *orig_ptr, struct expr_str *second_ptr)
{
  struct expr_str *start;
  debug ("MJA append_expr_expr %p %p", orig_ptr, second_ptr);
  start = orig_ptr;
  if (orig_ptr->next != 0)
  {
    while (orig_ptr->next != 0)
      orig_ptr = orig_ptr->next;
  }
  orig_ptr->next = second_ptr;
  dump_expr(start);
  return start;
}

/**
 * Checks and return the length of an expression
 *
 * @param ptr
 * @return The number of operands in an expression
 */
int
length_expr (struct expr_str * ptr)
{
  int c = 0;
  debug ("Print expr... %p", ptr);
  while (ptr)
  {
    c++;
    ptr = ptr->next;
  }
  return c;
}


/** 
 * This is something internal for Mike?
 *
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
      s[a] = tolower (s[a]);
    }
}


/* folowing functions are to work around problem with exporting struct in Windows dll */

/**
 *
 *
 * @param
 */
char *
get_report_stack_whytype(int a)
{
    return &report_stack[a].whytype;
}

/**
 *
 *
 * @param
 */
char *
get_report_stack_why(int a)
{
	return report_stack[a].why;
}

/**
 *
 *
 * @param
 */
struct sreports *
get_sreports(int z)
{
	return (struct sreports *) z;
}


/**
 *
 *
 * @param
 */
void
add_ex_dtype(char *sx)
{
	char s[256];
	char ss[256];
	strcpy(s,sx);
	trim(s);
	strcpy(s,downshift(s));
	debug("Initializing datatype : %s\n");

	A4GLEXDATA_initlib(s);

	debug("Checking if we need an extra include...");

	if (has_datatype_function_n(s,"INCLUDE")) 
	{
       	/* char *(*function) (); */
        char *(*function) (void);
		debug("yep");

        function=get_datatype_function_n(s,"INCLUDE");

		debug("function=%s\n",function);

		strcpy(ss,function());
		print_include(ss);
	}
}
/* ================================= EOF ============================= */

char *subtract_one(char *s) {
static char buff[256];
int a;
int c;

c=0;
for (a=0;a<strlen(s);a++) {
	if (s[a]==',') {
		buff[c++]='-';
		buff[c++]='1';
	}
	buff[c++]=s[a];
}
buff[c++]='-';
buff[c++]='1';
buff[c]=0;
return buff;
}
