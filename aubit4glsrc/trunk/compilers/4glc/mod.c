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
# $Id: mod.c,v 1.106 2003-02-23 08:04:37 afalout Exp $
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

#define UPDCOL 0
#define UPDVAL 1
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
extern char current_upd_table[64];
//static int 	const_cnt = 0;

int 		rep_type = 0; /** The report type */

//int 		last_var_found = -1;

//int 		var_hdr_finished;
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

#define GEN_STACK_SIZE 200
char 		gen_stack[GEN_STACKS][GEN_STACK_SIZE][80];
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
// MJA - NEWVARIABLE
  debug ("a4gl_add_variable");
  variable_action(-1,name,type,n,"a4gl_add_variable");
}

/**
 * Clear the variable stack by setting the counter to zero.
 */
void 
clr_variable (void)
{
	// Does nothing
}

/**
 *
 */
void 
inmod (void)
{
	// Does nothing
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
#ifdef OLD_STUFF
static int
print_record(int z, char ff,char *vname)
{
  int a;
  /*  It should be declared here because the two function are tighly coupled */
  static void print_variable(int z, char ff);

	// MJA - NEWVARIABLE

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
  debug ("push_type : %s %s %s", a, n, as);

  variable_action(-1,a,n,as,"push_type");

	// MJA - NEWVARIABLE


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
  a4gl_add_variable (0,"_ENDASSOC", 0); 
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

  variable_action(-1,tab,pkey,"","add_link_to");


	// MJA - NEWVARIABLE

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
  long z_new;
  char buff[256];
  char buff2[256];
  char *ptr;
  int dir;
  int flg;
  int lvl = 0;
int dtype;
int size;
int vval;

  //last_var_found = -1;

	// MJA - NEWVARIABLE
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




vval=find_variable(buff,&dtype,&size,0,0);

if (vval==1) {
	z_new= dtype+ (size << 16);
	//printf("OK - %x (%d %d)\n",z_new,dtype,size);
	return z_new;
}

if (vval==0) {
	return -1;
} 


	//printf("Find_variable returns %d for %s\n",vval,buff);
	return vval;




#ifdef OLD_STUFF

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
		if (z_new!=z) {
			printf("Discrepency between z's for %s\n",s);
			exit(0);
		}
	      return z;
	    }
	  /* debug ("More levels..."); */

	  lvl++;

	}

    }
  debug ("Variable not there : %s", s);

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
  
	// MJA - NEWVARIABLE
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
 buff[1]=0;
 buff[0]=t;
  variable_action(-1,name,ptr,buff,"add_constant");

#ifdef OLD_STUFF
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

  if (isin_command ("FUNC") || isin_command ("REPORT") || isin_command("MAIN")
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
#endif
}

/**
 * Set the internal 4gl variables in the array.
 */
void 
set_4gl_vars(void)
{
set_current_variable_scope('G');
variable_action(-1,"int_flag","","","a4gl_add_variable");
variable_action(-1,"long","","","push_type");
variable_action(-1,"quit_flag","","","a4gl_add_variable");
variable_action(-1,"long","","","push_type");
variable_action(-1,"status","","","a4gl_add_variable");
variable_action(-1,"long","","","push_type");

variable_action(-1,"time","","","a4gl_add_variable");
variable_action(-1,"char","8","","push_type");

variable_action(-1,"sqlca","","","a4gl_add_variable");
variable_action(-1,"_RECORD","","","push_type");
variable_action(-1,"sqlcode","","","a4gl_add_variable");
variable_action(-1,"long","","","push_type");
variable_action(-1,"sqlerrm","","","a4gl_add_variable");
variable_action(-1,"char","72","","push_type");
variable_action(-1,"sqlerrp","","","a4gl_add_variable");
variable_action(-1,"char","8","","push_type");
variable_action(-1,"sqlerrd","","","a4gl_add_variable");
variable_action(-1,"","","6","push_type");
variable_action(-1,"long","","","push_type");
variable_action(-1,"sqlawarn","","","a4gl_add_variable");
variable_action(-1,"char","8","","push_type");
variable_action(-1,"sqlstate","","","a4gl_add_variable");
variable_action(-1,"char","9","","push_type");
variable_action(-1,"","_ENDREC","","a4gl_add_variable");
variable_action(-1,"notfound","100","i","add_constant");
variable_action(-1,"false","0","i","add_constant");
variable_action(-1,"true","1","i","add_constant");
variable_action(-1,"today","","","a4gl_add_variable");
variable_action(-1,"fgldate","","","push_type");
variable_action(-1,"user","","","a4gl_add_variable"); /* Did someone change this  to 'usr' */
variable_action(-1,"char","8","","push_type");
variable_action(-1,"pageno","","","a4gl_add_variable");
variable_action(-1,"long","","","push_type");
variable_action(-1,"lineno","","","a4gl_add_variable");
variable_action(-1,"long","","","push_type");
variable_action(-1,"usrtime","","","a4gl_add_variable");
variable_action(-1,"long","","","push_type");
variable_action(-1,"curr_hwnd","","","a4gl_add_variable");
variable_action(-1,"long","","","push_type");
variable_action(-1,"curr_form","","","a4gl_add_variable");
variable_action(-1,"long","","","push_type");
variable_action(-1,"err_file_name","","","a4gl_add_variable");
variable_action(-1,"char","32","","push_type");
variable_action(-1,"err_file_no","","","a4gl_add_variable");
variable_action(-1,"long","","","push_type");
variable_action(-1,"curr_file_name","","","a4gl_add_variable");
variable_action(-1,"char","32","","push_type");
variable_action(-1,"curr_line_no","","","a4gl_add_variable");
variable_action(-1,"long","","","push_type");
variable_action(-1,"err_status","","","a4gl_add_variable");
variable_action(-1,"long","","","push_type");
variable_action(-1,"aiplib_status","","","a4gl_add_variable");
variable_action(-1,"long","","","push_type");

set_current_variable_scope('m');
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
char *
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
    debug ("next column for table '%p' is '%p'", tableName, ccol);
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
  debug ("Push %d %s - %d\n", a, s,gen_stack_cnt[a]);
  if (gen_stack_cnt[a] >= GEN_STACK_SIZE)
    {
      printf ("Out of stack!\n");
      exit (77);
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
      if (z > 0) debug ("%s ", s);

      debug ("%s", gen_stack[a][z]);
    }
    gen_stack_cnt[a]=0;
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
  debug ("add_bind - dtype=%d (%s) i=%c\n", dtype, var,i);

  if (i == 'i')
    {
      if (dtype == -2||strstr(var,".*"))
	{
	  debug ("push_bind_rec...");
	  push_bind_rec (var, i);
	}
      else
	{
	  ibind[ibindcnt].start_char_subscript=0;
	  ibind[ibindcnt].end_char_subscript=0;

	  if (strlen(current_upd_table)) {
		push_gen(UPDVAL,"?");
	  }

	  if (strncmp(var," substr(",8)!=0) {
	  	strcpy (ibind[ibindcnt].varname, var);
	  	ibind[ibindcnt].dtype = dtype;
	  } else {
		char buff[256];
		char buff2[256];
		int s_dtype;
		int s_sstart;
		int s_send;
		int a;
		strcpy(buff2,&var[8]);

		a=sscanf(buff2,"%s , %d , %d , %d) /*1*/",buff,&s_dtype,&s_sstart,&s_send);
		if (a!=4) {
			yyerror("Internal error - (split substr)");
		}
		if (s_send==0) s_send=s_sstart;
	  	strcpy (ibind[ibindcnt].varname, buff);
	  	ibind[ibindcnt].dtype = s_dtype;
		ibind[ibindcnt].start_char_subscript=s_sstart;
		ibind[ibindcnt].end_char_subscript=s_send;
		//printf("%s %d %d %d\n",ibind[ibindcnt].varname,ibind[ibindcnt].dtype,ibind[ibindcnt].start_char_subscript,ibind[ibindcnt].end_char_subscript);
	  }
	  ibindcnt++;
	}
      return ibindcnt;
    }

  if (i == 'N')
    {
      if (dtype == -2||strstr(var,".*"))
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
      if (dtype == -2||strstr(var,".*"))
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
      if (dtype == -2||strstr(var,".*"))
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

      if (dtype == -2||strstr(var,".*"))
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
  debug("Convstrsql ... %s",s);
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
  debug("Convstrsql ... %s => %s",s,buff);
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
  //dump_expr(ptr);
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
  //dump_expr(start);
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
  //dump_expr(start);
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

/**
 *
 *
 * @param
 */
char *
subtract_one(char *s)
{
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

/**
 * @param mode If mode is set to 1 - expect a '*' as column names...
*/
char *fix_update_expr(int mode) {
  char big_buff[20000];
int a;
  int rval;
  int isize = 0;
  int idtype = 0;
  char colname[256] = "";
  char csize[20];
  //char cdtype[20];
  char buff[1000];
  char *ccol;

printf("current_upd_table=%s\n",current_upd_table);

if (mode==1) {
	// It will only be a '*' anyway....
  	if (db_used == 0)
  	{
    		sprintf (buff, "You cannot use update * =  without specifying a database");
    		yyerror (buff);
    		return 0;
  	}
	
    	gen_stack_cnt[UPDCOL]=0;

	strcpy(colname,"");
  	rval = A4GLSQL_get_columns(current_upd_table,colname,&idtype, &isize);
	if (rval==0) {
		yyerror("Table is not in the database");
		return 0;
	}


  	while (1)
  	{
    		colname[0] = 0;
    		rval = A4GLSQL_next_column(&ccol,&idtype,&isize);
    		strcpy(colname,ccol);
    		if (rval == 0 ) break;
    		trim_spaces (colname);
		push_gen(UPDCOL,colname);
  	}
	A4GLSQL_end_get_columns();
}

printf("Columns =%d values=%d\n",gen_stack_cnt[UPDCOL],gen_stack_cnt[UPDVAL]) ;
if (gen_stack_cnt[UPDCOL]!=gen_stack_cnt[UPDVAL]) {
	yyerror("Number of columns in update not the same as number of values");
}

for (a=0;a<gen_stack_cnt[UPDCOL];a++) {
  if (a) strcat(big_buff,",");
  sprintf(buff,"%s=%s",gen_stack[UPDCOL][a],gen_stack[UPDVAL][a]);
  strcat(big_buff,buff);
}

//printf("---> %s\n",big_buff);
return big_buff;
}

/* ================================= EOF ============================= */
