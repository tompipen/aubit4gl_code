#include "a4gl_4glc_int.h"
#include "a4gl_expr.h"
#include "a4gl_API_parse_lib.h"
#include "parsehelp.h"
#include "var_handling.h"
#include "trim_spaces.h"

//void sort_variables(void *ptr, int n) ;
extern struct cmds command_stack[CMD_STACK_SIZE];
extern int nblock_no;
extern struct s_report_stack report_stack[REPORTSTACKSIZE];

extern int report_stack_cnt;

extern int lines_printed;
extern int use_group;
extern struct s_report sreports[SREPORTS_SIZE];
extern int sreports_cnt;

struct expr_str_list list_of_aggregates;

struct lint_warning *extra_warnings=0;
int nextra_warnings=0;

extern char when_to_tmp[64];
extern char when_to[8][128];
extern int when_code[8];

extern char *whentostore_p;
extern int whenever_store_c;
extern char *whenever_store_p;
//extern int ibindcnt;
//extern struct binding_comp *ibind;
//extern int nullbindcnt;
//extern struct binding_comp *nullbind;

#ifdef NOPE
extern struct variable **list_local;
extern int list_local_cnt;
extern int list_local_alloc;

/* Lists for our variables in each scope...*/
extern struct variable **list_global ;      /* Our List*/
extern int list_global_cnt ;        /* Number used in our list*/
extern int list_global_alloc ;      /* Space allocated for our list*/


extern struct variable **list_imported_global ;     /* Our List*/
extern int list_imported_global_cnt ;       /* Number used in our list*/
extern int list_imported_global_alloc ;     /* Space allocated for our list*/


extern struct variable **list_class ;
extern int list_class_cnt ;
extern int list_class_alloc ;


extern struct variable **list_module;
extern int list_module_cnt ;
extern int list_module_alloc ;
#endif
extern char                clobber[64];

extern struct variable_list *local_variables;

extern char *allbuff;
extern int allbuffsize ;

extern char variable_scope ;

//static int print_agg_defines(char t,int a);


struct report_orderby_section *current_orderby=0;

struct call_list *this_functions_call_list=0;

//static void write_variable_header (struct variable *v);
//static void write_variable_simple (struct variable *v);
//static void write_variable_linked (struct variable *v);
//static void write_variable_record (struct variable *v);
//static void write_variable_object (struct variable *v);
//static void write_variable_assoc (struct variable *v);
//static void write_variable_constant (struct variable *v);
//static void write_class_string (char *name, char *val);
//static void write_class_int (char *name, int val);
//static void read_class_int (char *name, int *val);
//static void write_variable_function (struct variable *v);
//static void do_append (void);
//static void escape (char *buff) ;
//static char get_current_variable_scope (void);
//static void print_module_variables (void);
//static void print_global_variables (void);
//static void print_local_variables (void);
static int set_var_dtype(char *errbuff, struct expr_str *ptr,int err_if_whole_array) ;
//struct variable *find_variable_vu_ptr(char *errbuff, struct variable_usage *v, char *scope) ;

struct expr_str_list *get_variable_usage_for_record(struct variable_usage *vu, int err_if_whole_array) ;

struct module_definition this_module;

//expr_str_list *expand_parameters(struct variable_list *var_list, expr_str_list *parameters) ;
//char * rettype_integer (int n);
//char tmpbuff[1024] = "";


void reset_report_aggregates() {
	list_of_aggregates.list.list_len=0;
	list_of_aggregates.list.list_val=0;
}

int scan_orderby(struct report_orderby_section *c_orderby, expr_str *v) {
struct variable_usage *u;
int a;

A4GL_assertion(v->expr_type!=ET_EXPR_VARIABLE_USAGE,"Expecting a variable usage");
u=v->expr_str_u.expr_variable_usage;


if (c_orderby->variables==0) {
	c_orderby->variables=A4GL_new_ptr_list(0);
}
for (a=0;a<c_orderby->variables->list.list_len;a++) {
	struct expr_str *ov;
	struct variable_usage *ord_var;
	ov=c_orderby->variables->list.list_val[a];
	A4GL_assertion(ov->expr_type!=ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC,"Expected a ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC");
	ord_var=ov->expr_str_u.expr_variable_usage_with_asc_desc->var_usage;
	if (match_variable_usage(ord_var, u)) {
			return a;
	}
}

// if we get to here - if we're implicit - we need to add it to our orderby section...
//
if (c_orderby->rord_type == REPORT_ORDERBY_IMPLICIT) {
	struct expr_str *e;
	struct expr_str *e2;
	//struct variable_usage *u2;
	e2=A4GL_new_expr_push_variable(u,current_is_report());
	e=A4GL_new_variable_usage_with_asc_desc(e2,"A");
	A4GL_new_append_ptr_list(c_orderby->variables,e);
	
	return c_orderby->variables->list.list_len-1;
}



return -1;
}

static int strsplit(char *orig,char *srch, ...) {
char **p;
char *buff;
int a;
static va_list args;
char *ptr;


buff=strdup(orig);
p=malloc(strlen(srch)+1);
p[0]=buff;
for (a=0;a<strlen(srch);a++) {
        p[a+1]=strchr(p[a],srch[a]);
        if (p[a+1]) {
                *p[a+1]=0;
                p[a+1]++;
        } else {
                free(p);
                free(buff);
                return 0;
        }
}
va_start (args, srch);



ptr=va_arg(args, char*);
a=0;
while (ptr && a<=strlen(srch)) {
        strcpy(ptr, p[a]);
        a++;
        ptr=va_arg(args, char*);
}
va_end(args);
return strlen(srch)+1;
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
  ccnt = A4GL_get_ccnt ();
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
      /* print_start_block (nblock_no); */

      command_stack[ccnt].block_no = nblock_no++;
    }
  A4GL_debug (" Added new block");
  ccnt++;
  file_out_indent (ccnt);
  A4GL_set_ccnt (ccnt);
  return command_stack[ccnt].block_no;
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
  ccnt = A4GL_get_ccnt ();
  /* more checks here ! */

  ccnt--;
  A4GL_set_ccnt (ccnt);
  file_out_indent (ccnt);
  if (command_stack[ccnt].block_no > 0)
    {

	/*
      if (iscontinuecmd (cmd_type))
	{
	  print_continue_block (command_stack[ccnt].block_no, 0, cmd_type);
	}
      print_end_block (command_stack[ccnt].block_no);
	*/
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
  ccnt = A4GL_get_ccnt ();


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
      A4GL_debug ("/* wanted to continue a %s but wasnt in one! */", cmd_type);
      return;
    }
  /* print_continue_loop (command_stack[a].block_no, cmd_type); */
}



#ifdef OLD
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

#endif


/*
 * The parser found a new report block
 *
 * @todo Comment the parameters
 *
 * @param why
 * @param whytype
 */
void
push_report_block (char *why, char whytype,char *var)
{
  set_curr_block (0);
  strcpy (report_stack[report_stack_cnt].why, why);
  report_stack[report_stack_cnt].whytype = whytype;
  strcpy(report_stack[report_stack_cnt].var , var);
  /* print_repctrl_block (); */
  report_stack_cnt++;
  lines_printed = 0;
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
struct expr_str *
add_report_agg (char t, struct expr_str *s1, struct expr_str *s2, int a, long *n)
{
  //int rval=0;
  struct expr_str *x;
  //printf ("In add_report_agg a=%d\n", a);
  if (use_group)
    {
      sreports[sreports_cnt].in_b = get_curr_block ();
	//printf("in_b=%d\n",sreports[sreports_cnt].in_b);
    }
  else
    {
      sreports[sreports_cnt].in_b = 0;
    }

  if (s2 == 0)
    {

      A4GL_debug ("Adding default where on report aggregate of 1");
      sreports[sreports_cnt].rep_where_expr = A4GL_new_literal_long_str ("1");
    }
  else
    {
      A4GL_debug ("Adding non-default where on report aggregate");
      sreports[sreports_cnt].rep_where_expr = s2;
    }


  sreports[sreports_cnt].rep_cond_expr = s1;
  sreports[sreports_cnt].a = a;
  sreports[sreports_cnt].t = t;

  //rval = print_agg_defines (t, a);
  *n = 1;
  x = A4GL_new_expr_agg (t, a, s1,s2, use_group, sreports[sreports_cnt].in_b );
  use_group = 0;
  A4GL_new_append_ptr_list(&list_of_aggregates, x);
  sreports_cnt++;

  return x;
}


#ifdef OLD

int print_agg_defines(char t,int a) {
char buff[127];

  if (t == 'C')
    {
		sprintf(buff,"_g%d",a);
		push_name(buff,0);
		push_type("long",0,0);

          		// A4GL_lex_printh ("static long _g%d=0;\n", a);
      return 1;
    }

  if (t == 'P')
    {
		sprintf(buff,"_g%d",a);
		push_name(buff,0);
		push_type("long",0,0);

		sprintf(buff,"_g%d",a+1);
		push_name(buff,0);
		push_type("long",0,0);

          //A4GL_lex_printh ("static long _g%d=0,_g%d=0;\n", a, a + 1);
        //sprintf(usage,"A4GL_push_double((double)_g%d/(double)_g%d);\n",a,a+1);
      return 2;
    }

  if (t == 'S')
    {
		sprintf(buff,"_g%dused",a);
		push_name(buff,0);
		push_type("long",0,0);
		sprintf(buff,"_g%d",a);
		push_name(buff,0);
		push_type("double",0,0);

          	//A4GL_lex_printh ("static int _g%dused=0;\n", a);
          	//A4GL_lex_printh ("static double _g%d=0;\n", a);

      return 1;
    }
  if (t == 'N' || t == 'X')
    {
		sprintf(buff,"_g%dused",a);
		push_name(buff,0);
		push_type("long",0,0);
		sprintf(buff,"_g%d",a);
		push_name(buff,0);
		push_type("double",0,0);

          //A4GL_lex_printh ("static double _g%d=0;\n", a);
          //A4GL_lex_printh ("static int _g%dused=0;\n", a);

        //sprintf(usage,"A4GL_push_double(_g%d);\n",a);
      return 1;
    }

  if (t == 'A')
    {
		sprintf(buff,"_g%dused",a);
		push_name(buff,0);
		push_type("double",0,0);

		sprintf(buff,"_g%d",a+1);
		push_name(buff,0);
		push_type("double",0,0);

          //A4GL_lex_printh ("static double _g%d=0;\n", a);
          //A4GL_lex_printh ("static long   _g%d=0;\n", a + 1);
        //sprintf(usage,"A4GL_push_double(_g%d/(double)_g%d);\n",a,a+1);

      return 2;
    }
return 0;
}


#endif


struct command *set_whenever_from_store_cmd(void) {
	return new_whenever_cmd(whenever_store_c,whentostore_p);
}



void add_external_datatypes(char *s) {
int a;

if (this_module.external_datatypes.external_datatypes_val) {
	for (a=0;a<this_module.external_datatypes.external_datatypes_len;a++) {
		if (strcmp(this_module.external_datatypes.external_datatypes_val[a], s)==0) {
			return; /* its already there */
		}
	}
}
this_module.external_datatypes.external_datatypes_len++;
this_module.external_datatypes.external_datatypes_val=realloc(this_module.external_datatypes.external_datatypes_val, this_module.external_datatypes.external_datatypes_len*sizeof(str *));
this_module.external_datatypes.external_datatypes_val[this_module.external_datatypes.external_datatypes_len-1]=strdup(s);


}


/**
 *  *
 *   *
 *    * @param
 *     */
void
add_ex_dtype (char *sx)
{
  char s[256];
  char ss[256];
  strcpy (s, sx);
  A4GL_trim (s);
  strcpy (s, downshift (s));
  A4GL_debug ("Initializing datatype : %s\n", s);

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

      add_external_datatypes(ss);

      /* print_include (ss); */
    }
}




void
do_print_menu_1 (void)
{
  /* 
 * 	print_menu_1 (get_blk_no ());
  	print_menu_1b (get_blk_no ());
	*/
}

void
do_print_menu_block_end (int mn)
{
  /* print_menu_block_end (mn, get_blk_no ()); */
}








struct command * cmd_display_by_name (expr_str_list *l, attrib *attr)
{
  void *ptr;
  int a;
  struct fh_field_list *fl;
  struct fh_field_entry *fe=0;
  struct variable_usage *vu;
  dt_display *dt;

  dt=malloc(sizeof(dt_display));

                fl=new_field_list();
                for (a=0;a<l->list.list_len;a++) {
                        char *colname;
                        //struct expr_str *f;
                        A4GL_assertion(l->list.list_val[a]->expr_type!=ET_EXPR_VARIABLE_USAGE,"Expecting a variable");
                        vu=l->list.list_val[a]->expr_str_u.expr_variable_usage;
                        while (vu->next) vu=vu->next;
                        colname=vu->variable_name;
                        fe= new_field_entry(A4GL_new_expr_simple_string(colname,ET_EXPR_IDENTIFIER), NULL,1);
                        append_field_to_list(fl,fe);
                }

  dt->dt_display_u.field_list = fl;

  dt->dttype = DT_DISPLAY_TYPE_FIELD_LIST;

  ptr=new_display_cmd (make_fgl_expr_list(l), dt, attr,EB_TRUE);

  //start_bind ('i', 0);
return ptr;
}


void set_variables (variable_list *v,char why) {
	if (why=='L') {
			if (local_variables==NULL) {
				v->variables.variables_val=NULL;
				v->variables.variables_len=0;
			} else {
		        	v->variables.variables_len=local_variables->variables.variables_len;
                        	v->variables.variables_val=malloc(local_variables->variables.variables_len*sizeof(struct variable *));
				sort_variables(local_variables->variables.variables_val, local_variables->variables.variables_len);
                        	memcpy(v->variables.variables_val,local_variables->variables.variables_val, local_variables->variables.variables_len*sizeof(struct variable *));
				sort_variables(v->variables.variables_val, v->variables.variables_len);
			}
			return ;
 	}

	if (why=='g') {
		        v->variables.variables_len=this_module.exported_global_variables.variables.variables_len;

			if ( v->variables.variables_len) {
                        	v->variables.variables_val=malloc(this_module.exported_global_variables.variables.variables_len*sizeof(struct variable *));
				sort_variables(this_module.exported_global_variables.variables.variables_val, this_module.exported_global_variables.variables.variables_len);
                        	memcpy(v->variables.variables_val,this_module.exported_global_variables.variables.variables_val, this_module.exported_global_variables.variables.variables_len*sizeof(struct variable *));
				sort_variables(v->variables.variables_val, v->variables.variables_len);
			} else {
			 	v->variables.variables_val=NULL;
			}
		return ;
 	}


	if (why=='G') {
			sort_variables(this_module.imported_global_variables.variables.variables_val, this_module.imported_global_variables.variables.variables_len);
		       v->variables.variables_len=this_module.imported_global_variables.variables.variables_len;
                       v->variables.variables_val=malloc(this_module.imported_global_variables.variables.variables_len*sizeof(struct variable *));
                       memcpy(v->variables.variables_val,this_module.imported_global_variables.variables.variables_val, this_module.imported_global_variables.variables.variables_len*sizeof(struct variable *));
			sort_variables(v->variables.variables_val, v->variables.variables_len);
		return ;
 	}

	if (why=='m') {
	//printf("Set variables %d %p\n",list_module_cnt, list_module);
			sort_variables(this_module.module_variables.variables.variables_val, this_module.module_variables.variables.variables_len);
		       v->variables.variables_len=this_module.module_variables.variables.variables_len;
                       v->variables.variables_val=malloc(this_module.module_variables.variables.variables_len*sizeof(struct variable *));
                       memcpy(v->variables.variables_val,this_module.module_variables.variables.variables_val, this_module.module_variables.variables.variables_len*sizeof(struct variable *));
			sort_variables(v->variables.variables_val, v->variables.variables_len);
		return ;
 	}

}




int A4GL_open_class_dll(char *s) {
	char buff[512];
	FILE *f;
	strcpy(buff,s);
	strcat(buff,acl_getenv("A4GL_DLL_EXT"));
	A4GL_debug("Looking for : %s\n",buff);
	f=A4GL_open_file_classpath(buff);

	if (f) { // We've found our dll...
	        fclose(f);
	        //
	        read_class(s,0);
	} else {
	        return 0;
	}


	return 1;
}


/**
 *  * Gets the C data type corresponding to 4gl data type
 *   *
 *    * @param s A string with the numeric 4gl data type (@see find_type())
 *     * @return The string (static) with the C declaration
 *      */
char * rettype_integer (int n)
{
	  char s[200];

	    /*static char rs[20] = "long";*/
	    /*int a;*/

	    A4GL_debug ("rettype_integer : %d\n", n);

	      SPRINTF1 (s, "%d", n);
	        return rettype (s);
}




void
FGLPARSE_A4GL_lexer_import_package (char *s)
{
  FILE *f;
  f = A4GL_open_file_classpath (s);
  if (f == 0)
    {
      int ok = 0;
      if (strcmp (s, "default") == 0)
	{
	  // We don't care if this one isn't there...
	  return;
	}

      ok = A4GL_open_class_dll (s);

      if (!ok)
	{
	  a4gl_yyerror ("Unable to open package description");
	}
      return;
    }
  read_package_contents (f);

}


char *rettype (char *s) {
  static char rs[20] = "long";
  int a;

  strcpy(rs,"unknown");

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
    strcpy (rs, "CHAR");
  if (strcmp (s, "1") == 0)
    strcpy (rs, "SMALLINT");
  if (strcmp (s, "2") == 0)
    strcpy (rs, "INTEGER");
  if (strcmp (s, "3") == 0)
    strcpy (rs, "FLOAT");
  if (strcmp (s, "4") == 0)
    strcpy (rs, "SMALLFLOAT");
  if (strcmp (s, "5") == 0)
    strcpy (rs, "DECIMAL");
  if (strcmp (s, "6") == 0)
    strcpy (rs, "INTEGER");
  if (strcmp (s, "7") == 0)
    strcpy (rs, "DATE");
  if (strcmp (s, "8") == 0)
    strcpy (rs, "MONEY");
  if (strcmp (s, "10") == 0)
    strcpy (rs, "DATETIME");
  if (strcmp (s, "11") == 0)
    strcpy (rs, "BYTE");
  if (strcmp (s, "12") == 0)
    strcpy (rs, "TEXT");
  if (strcmp (s, "13") == 0)
    strcpy (rs, "VARCHAR");
  if (strcmp (s, "14") == 0)
    strcpy (rs, "INTERVAL");
  return strdup (rs);
}

/******************************************************************************/
/**
 * Identifies the data type from a string and convert it to numeric with
 * the goal of being more easyli used.
 *
 * @todo organize some defines to the data types.
 *
 * @param s The string where the data type will be scanned
 * @return The data type in numeric code
 */


int
FGLPARSE_A4GL_lexer_find_type (char *s)
{
  char errbuff[80];
  static char types[20][80];
  //char buff[20];
  int a;
  //int b;
  static int set_types=0;
  if (set_types==0) {
          for (a=0;a<15;a++) { strcpy(types[a],rettype_integer(a)); }
          set_types=1;
  }

  for (a=0;a<15;a++) {
          if (strcmp(types[a],s)==0) { return a; }
  }

  A4GL_debug ("Looking for type '%s'", s);

  if (A4GL_find_datatype_out (s) != -1)
    {
      A4GL_debug ("Found it...");
      return A4GL_find_datatype_out (s);
    }

  A4GL_debug ("Not found - keep looking");
  A4GL_debug ("find_type %s\n", s);
  if (strcmp ("char", s) == 0) return DTYPE_CHAR;
  if (strcmp ("long", s) == 0) return DTYPE_INT;
  if (strcmp ("int8", s) == 0) return DTYPE_INT8;
  if (strcmp ("serial8", s) == 0) return DTYPE_SERIAL8;
  if (strcmp ("integer", s) == 0) return DTYPE_SMINT;
  if (strcmp ("int", s) == 0) return DTYPE_SMINT;
  if (strcmp ("short", s) == 0) return DTYPE_SMINT;
  if (strcmp ("double", s) == 0) return DTYPE_FLOAT;
  if (strcmp ("float", s) == 0) return DTYPE_SMFLOAT;
  if (strcmp ("fgldecimal", s) == 0) return DTYPE_DECIMAL;
  if (strcmp ("serial", s) == 0) return DTYPE_SERIAL;
  if (strcmp ("fgldate", s) == 0) return DTYPE_DATE;
  if (strcmp ("fglmoney", s) == 0) return 8;
  if (strcmp ("struct_dtime", s) == 0) return 10;
  if (strcmp ("fglbyte", s) == 0) return 11;
  if (strcmp ("fgltext", s) == 0) return 12;
  if (strcmp ("varchar", s) == 0) return 13;
  if (strcmp ("struct_ival", s) == 0) return 14;
  if (strcmp ("_RECORD", s) == 0) return -2;
  if (strcmp ("form", s) == 0) return 9;
  if (strcmp ("uiwindow", s) == 0) return 9;
  if (strcmp ("omdomnode", s) == 0) return 9;
  if (strcmp ("omnodelist", s) == 0) return 9;
  if (strcmp ("basechannel", s) == 0) return 9;
  if (strcmp ("string", s) == 0) return 9;
  if (strncmp ("struct _class_struct_", s,21) == 0) { return -3; }
  A4GL_debug ("Invalid type : '%s'\n", s);
  SPRINTF1 (errbuff, "Internal Error (Invalid type : '%s')\n", s);
  a4gl_yyerror (errbuff);
  return 0;
}



void
A4GL_set_clobber (char *c)
{
  char *ptr;
  //char *ptr2;
  ptr = strrchr (c, '/');
  if (ptr)
    {
      strcpy (clobber, ptr + 1);
      return;
    }

  /* Do dos mode ? */
  ptr = strrchr (c, '\\');
  if (ptr)
    {
      strcpy (clobber, ptr + 1);
      return;
    }

  strcpy (clobber, c);
}

int A4GL_is_class_static(char *s) {
	if (strncmp(s,"base.",5)==0) return 1;
	return 0;
}






void FGLPARSE_A4GL_lexer_parsed_fgl(void) {
	A4GL_debug("A4GL_lexer_parsed_fgl");
	//A4GL_lex_parsed_fgl ();
}



/**
 * Print the C code implementation for sql USING 4gl statements.
 *
 * This statement are not informix 4gl original statements.
 *
 * @param type : The sql statement type.
 *   - S : Select
 *   - D : Delete
 *   - U : Update
 * @param var The 4gl variable name to be used.
 */
struct command *print_linked_cmd (int type, expr_str *var)
{
  //char tabname[640];
  //char pklist[256];
  //int ni;
   struct command *cmd;

#ifdef FIXME
  if (last_var_is_linked (tabname, pklist))
    {
      char buff[80];
      char buff2[80];
      //int no = 0;
      int no_keys;
      int azcnt;

      if (type == 'S')
	{
	  start_bind ('o', 0);
	  sprintf (buff, "%s.*", var);
	  add_bind ('o', buff);
	}

      no_keys = linked_split (pklist, 0, 0);
      start_bind ('i', 0);

      if (type == 'U')
	{
	  char buffer[256];
	  set_pklist (pklist);
	  sprintf (buffer, "%s.*", var);
	  push_bind_rec (buffer, 'u');
	}

      for (azcnt = 1; azcnt <= no_keys; azcnt++)
	{
	  A4GL_debug ("Getting key no %d", azcnt);
	  linked_split (pklist, azcnt, buff2);
	  sprintf (buff, "%s.%s", var, buff2);
	  A4GL_debug ("Adding linked %s", buff);
	  add_bind ('i', buff);
	  A4GL_debug (" key count %d %d\n", azcnt, no_keys);
	}
	
      if (type == 'S') sprintf (buff, "SELECT * FROM %s WHERE ", tabname);
      if (type == 'D') sprintf (buff, "DELETE FROM %s WHERE ", tabname);
      if (type == 'U') sprintf (buff, "UPDATE %s SET (%s)=(%s) WHERE ", tabname, get_upd_using_notpk (), get_upd_using_queries ());

      for (azcnt = 1; azcnt <= no_keys; azcnt++)
	{
	  if (azcnt > 1)
	    strcat (buff, "AND");
	  linked_split (pklist, azcnt, buff2);
	  strcat (buff, " ");
	  strcat (buff, buff2);
	  strcat (buff, "=? ");
	}


        if (type == 'S')  {
		cmd=new_execute_cmd(copy_togenbind('i'), copy_togenbind('o'), buff);
		/* print_execute_g(buff,3,copy_togenbind('i'),copy_togenbind('o')); */
      	} else {
		cmd=new_execute_cmd(copy_togenbind('i'), copy_togenbind('o'), buff);
		/* print_execute_g(buff,3,copy_togenbind('i'),empty_genbind('o')); */
	}
	start_bind('o',0);
	start_bind('i',0);

    }
  else
    {
      return NULL;
    }
#endif
  return cmd;
}


void debug_func(struct module_entry *e) {
	A4GL_pause_execution(); // SAFE TO LEAVE IN 
 
}



char *get_module_dbname(void) {
	return this_module.mod_dbname;
}

e_boolean get_module_isschema(void) {
	return this_module.schema_only;
}


void set_module_dbname(char *db,e_boolean isschema) {
	this_module.mod_dbname=strdup(db);
	this_module.schema_only=isschema;

}



void add_globals_file_to_this_module(char *s) {
	this_module.global_files->str_list_entry.str_list_entry_len++;
	this_module.global_files->str_list_entry.str_list_entry_val=realloc(this_module.global_files->str_list_entry.str_list_entry_val, this_module.global_files->str_list_entry.str_list_entry_len*sizeof(char *));
	this_module.global_files->str_list_entry.str_list_entry_val[this_module.global_files->str_list_entry.str_list_entry_len-1]=strdup(s);
}



void add_module_entry(module_entry *m) {

                                if (m) {
                                        this_module.module_entries.module_entries_len++;
                                        this_module.module_entries.module_entries_val=realloc(this_module.module_entries.module_entries_val, sizeof(module_entry *)*this_module.module_entries.module_entries_len);
                                        this_module.module_entries.module_entries_val[this_module.module_entries.module_entries_len-1]=m;
	}
}


void clr_call_list() {
	if (this_functions_call_list==0) {
		this_functions_call_list=malloc(sizeof(struct call_list));
		this_functions_call_list->calls_by_call.calls_by_call_len=0;
		this_functions_call_list->calls_by_call.calls_by_call_val=0;
		this_functions_call_list->calls_by_expr.calls_by_expr_len=0;
		this_functions_call_list->calls_by_expr.calls_by_expr_val=0;
	}

	if ( this_functions_call_list->calls_by_call.calls_by_call_val) {
		// We dont free this - because we're going to use this data in the function header info...
		this_functions_call_list->calls_by_call.calls_by_call_val=0;
	}
	this_functions_call_list->calls_by_call.calls_by_call_len=0;


	if ( this_functions_call_list->calls_by_expr.calls_by_expr_val) {
		// We dont free this - because we're going to use this data in the function header info...
		this_functions_call_list->calls_by_expr.calls_by_expr_val=0;
	}
	this_functions_call_list->calls_by_expr.calls_by_expr_len=0;
}

void add_to_call_list_by_call(struct command *c) {
	if (this_functions_call_list==0) {
		clr_call_list();
	}
	this_functions_call_list->calls_by_call.calls_by_call_len++;
	this_functions_call_list->calls_by_call.calls_by_call_val=realloc(this_functions_call_list->calls_by_call.calls_by_call_val,sizeof(struct command *)*this_functions_call_list->calls_by_call.calls_by_call_len);
	this_functions_call_list->calls_by_call.calls_by_call_val[this_functions_call_list->calls_by_call.calls_by_call_len-1]=c;
	//printf("add_to_call_list_by_call - %d \n", this_functions_call_list->calls_by_call.calls_by_call_len);
}

void add_to_call_list_by_expr(expr_str *c) {
	if (this_functions_call_list==0) {
		clr_call_list();
	}
	this_functions_call_list->calls_by_expr.calls_by_expr_len++;
	this_functions_call_list->calls_by_expr.calls_by_expr_val=realloc(this_functions_call_list->calls_by_expr.calls_by_expr_val,sizeof(expr_str *)*this_functions_call_list->calls_by_expr.calls_by_expr_len);
	this_functions_call_list->calls_by_expr.calls_by_expr_val[this_functions_call_list->calls_by_expr.calls_by_expr_len-1]=c;
}



void *get_def_mn_file (void) {
        struct expr_str *ptr;
        ptr=A4GL_new_literal_string("menu");

                return ptr;
 }
        

void dopush_commands() {
	// do nothing - for debugging..
}

void dopop_commands() {
	// do nothing - for debugging..
}


int ignore_indicators=0;
int using_indicators=-1;

int set_ignore_indicators() {
	if (using_indicators==-1) { using_indicators=A4GLSQLCV_check_requirement ("USE_INDICATOR"); }
	if (using_indicators) {
		if (ignore_indicators==0) {
			A4GL_setenv("USE_INDICATOR","N",1);
		}
		ignore_indicators++;
	}
	return ignore_indicators;
}


int clr_ignore_indicators() {
	if (using_indicators==-1) { using_indicators=A4GLSQLCV_check_requirement ("USE_INDICATOR"); }

	if (using_indicators) {
		ignore_indicators--;
		if (ignore_indicators==0) {
			A4GL_setenv("USE_INDICATOR","Y",1);
		}
	}
	return ignore_indicators;
}


void A4GL_clr_extra_warnings() {
nextra_warnings=0;
extra_warnings=0; // We're still using the original ones - so we can't free it...
}

void A4GL_add_extra_warning(int yylineno,char* msg) {
nextra_warnings++;
extra_warnings=realloc(extra_warnings, nextra_warnings*sizeof(struct lint_warning));
extra_warnings[nextra_warnings-1].lineno=yylineno;
extra_warnings[nextra_warnings-1].warning=strdup(msg);

}


void A4GL_set_extra_warnings(unsigned int *n, struct lint_warning **l) {
	*n=nextra_warnings;
	*l=extra_warnings;
}


struct on_events *new_event_list(on_event *evt)
{
        struct on_events *e;
            e=malloc(sizeof(on_events));
               e->event.event_len=1;
                e->event.event_val=malloc(sizeof(e->event.event_val[0]) * e->event.event_len);
                e->event.event_val[e->event.event_len-1]=evt;
	return e;

}


struct on_events *append_event_list(struct on_events * evtlist, struct on_event *evt) {
                evtlist->event.event_len=evtlist->event.event_len+1;
                evtlist->event.event_val=realloc(evtlist->event.event_val, sizeof(evtlist->event.event_val[0]) * evtlist->event.event_len);
                evtlist->event.event_val[evtlist->event.event_len-1]=evt;
                return evtlist;
}


struct s_select_list_item_list *make_select_list_item_list_from_variable_record(char *s) {
	struct variable_usage *vu;
	struct variable_usage *vu_item;
	struct variable_usage *vu_top;
	char buff[256];
	char errbuff[256];
	struct s_select_list_item_list *l;
	enum e_scope scope;
	char *ptr;
	struct variable *v;
	int a;
	vu=malloc(sizeof(struct variable_usage));
	strcpy(buff,s);
	ptr=strstr(buff,".*");
	if (!ptr) {
		A4GL_assertion(1,"Expecting record.*");
		return NULL;
	}
	*ptr=0;

	vu=new_variable_usage(0,buff,0);

	v=find_variable_vu_ptr(errbuff, vu,&scope, 1);
	if (!v) {a4gl_yyerror(errbuff); return NULL;}
	if (v->var_data.variable_type!=VARIABLE_TYPE_RECORD) {
		a4gl_yyerror("Not a record variable");
		return NULL;
	}
	if (v->arr_subscripts.arr_subscripts_len) {
		a4gl_yyerror("You cant use an array here");
		return NULL;
	}
	
	l=new_select_list_item_list(0);
	for (a=0;a<v->var_data.variable_data_u.v_record.variables.variables_len;a++) {
		
		struct variable *v2;
		struct s_select_list_item *rval;
		struct expr_str *e;

		v2=v->var_data.variable_data_u.v_record.variables.variables_val[a];
		vu_top=A4GL_memdup(vu, sizeof(struct variable_usage));
		vu_item=new_variable_usage(0,v2->names.names.names_val[0].name,0);
		append_variable_usage(vu_top,vu_item);
		e=A4GL_new_expr_push_variable(vu_top,current_is_report());
		ensure_variable(errbuff, e,1);
		free(e);

		rval=new_select_list_item_variable_usage(vu_top);
		l=local_add_select_list_item_list(l,rval);

		
	}


	return l;
}


struct variable_usage *usage_bottom_level( variable_usage *u) {
        while (u->next) u=u->next;
        return u;

}


static struct s_select_list_item *flatten_slist(struct s_select_list_item *s) {
	/* There is a small change we might be passed in a variable
 	* 	thats not been expanded - so expand it - and if its just a single
 	*    	value - use that..
 	*/
	if (s->data.type==E_SLI_VARIABLE_USAGE_LIST) {
		struct s_select_list_item_list *slist;
		slist=s->data.s_select_list_item_data_u.var_usage_list;
		slist=rationalize_select_list_item_list(slist);
		if (slist->list.list_len==1) {
			return slist->list.list_val[0]; // its not really a list - if it just contains one thing..
		}
	}

	return s;
}

struct s_select_list_item *convert_fgl_expr_to_sql_expr(expr_str *e) {
struct s_select_list_item *rval=NULL;

	if (e->expr_type== ET_EXPR_SELECT_LIST_ITEM) {
		rval=e->expr_str_u.sl_item;
	}

	if (e->expr_type==ET_EXPR_IDENTIFIER) {
		rval=new_select_list_item_column_from_transform(e->expr_str_u.expr_string);
	}

	if (e->expr_type==ET_EXPR_THROUGH) {
		struct s_select_list_item_list *slist;
		char errbuff[256];
		int a;
		expr_str_list *elist;
		elist=malloc(sizeof(expr_str_list));
		elist->list.list_len=1;
		elist->list.list_val=malloc(sizeof(expr_str *));
		elist->list.list_val[0]=e;
	
		elist=expand_variables_in_expr_str_list(elist,1,1);
		if (elist==0) return 0;
				slist=new_select_list_item_list(0);

		for (a=0;a<elist->list.list_len;a++) {
					e=elist->list.list_val[a];
					ensure_variable(errbuff, e,1);
					local_add_select_list_item_list(slist, new_select_list_item_variable_usage(e->expr_str_u.expr_variable_usage));
					inc_var_usage(e);
		}
		rval=flatten_slist(new_select_list_item_variable_usage_list(slist));
		return rval;
	}

	if (e->expr_type==ET_EXPR_VARIABLE_USAGE) {
		char errbuff[256];
		int a;
		//struct expr_str_list *l;
		int is_record=0;
		variable_usage *u;
		inc_var_usage(e);
		u=usage_bottom_level(e->expr_str_u.expr_variable_usage);
		if (u->datatype==-2) {
				is_record=1;
				u=e->expr_str_u.expr_variable_usage;
		}

		if (u->datatype==-1) {
			if (strcmp(u->variable_name,"*")==0) {
				u=e->expr_str_u.expr_variable_usage;
				while (u->next) {
					if (strcmp(u->next->variable_name,"*")==0) {
						break;
					}
					u=u->next;
				}
			}
			is_record=1;
		}

		if (is_record) { // Its a possible record..
				struct s_select_list_item_list *slist;
				enum e_scope scope;
				//int doit;
				struct variable *v;
				expr_str_list  *elist;
				
				v=find_variable_vu_ptr(errbuff, u, &scope, 1);
				A4GL_assertion(v==0,"Couldn't find variable");
				A4GL_assertion(v->var_data.variable_type!=VARIABLE_TYPE_RECORD,"Expecting a record");
				// We're going to create a select_list_item_list using this record
				// but we'll do it by creating the variable_usage's first
				// the easiest way is to use get_variable_usage_for_record...
				elist=get_variable_usage_for_record(u, 1);

				slist=new_select_list_item_list(0);

				for (a=0;a<elist->list.list_len;a++) {
					e=elist->list.list_val[a];
					ensure_variable(errbuff, e,1);
					local_add_select_list_item_list(slist, new_select_list_item_variable_usage(e->expr_str_u.expr_variable_usage));
				}
				rval=flatten_slist(new_select_list_item_variable_usage_list(slist));
  
		} else {
			ensure_variable(errbuff, e,1);
			rval=new_select_list_item_variable_usage(e->expr_str_u.expr_variable_usage);
		}
		//A4GL_assertion(1,"These should all have been filtered out by now...");
		//rval=new_select_list_item_variable_usage(e->expr_str_u.expr_variable_usage);
	}

	A4GL_assertion(rval==NULL, "convert_fgl_expr_to_sql_expr failed");

return rval;
}




char * get_id_from_variable_usage_expression(expr_str *ptr) {
	if (ptr->expr_type==ET_EXPR_VARIABLE_USAGE) {
		return expr_as_string_when_possible(ptr);
	}
	A4GL_assertion(1,"get_id_from_variable_usage_expression failed");
	return "";
}

char *get_variable_as_string_from_variable_usage_expression(expr_str *ptr) {

	return expr_as_string_when_possible(ptr);

//A4GL_assertion(1,"FIXME");
//return NULL;
}


int get_variable_dtype_from_variable_usage_expression(char *errbuff, expr_str *ptr) { 
int type=0;
struct variable_usage *p;
struct variable *v;
enum e_scope scope;

strcpy(errbuff,"");
if (ptr==0)  {
	strcpy(errbuff, "No expression");
	return -1;
}

if (ptr->expr_type==ET_EXPR_LINENO) { return DTYPE_INT; }
if (ptr->expr_type==ET_EXPR_PAGENO) { return DTYPE_INT; }
if (ptr->expr_type==ET_EXPR_TODAY) { return DTYPE_DATE; }

if (ptr->expr_type!=ET_EXPR_VARIABLE_USAGE) {
	strcpy(errbuff, "Not a variable expression");
	return -1;
}

p=ptr->expr_str_u.expr_variable_usage;
scope=E_SCOPE_NOTSET;
v=find_variable_vu_ptr(errbuff, p,&scope,1);

if (v==0) {
	if (strlen(errbuff)==0) {
		set_yytext(expr_as_string_when_possible(ptr));
		strcpy(errbuff,"Variable has not defined");
	}
	return -1;
}

while (p) {
	
	// Are we the last portion, and are we in a string 
	if (p->next==0 && type==-2&&strcmp(p->variable_name,"*")==0) {
		// They've picked the whole record...
		break;
	}
	type=p->datatype;
	p=p->next;
}
return type;
}






int check_input_or_display_array_variable(expr_str *e) {
struct  variable_usage *vu;
char errbuff[256];
struct variable *v;
struct variable_usage *vu2;
enum e_scope scope;
// Need to check its really an array

if (e->expr_type!=ET_EXPR_VARIABLE_USAGE) {
	strcpy(errbuff, "Not a simple variable expression");
	return 0; // Error condition
}

vu=e->expr_str_u.expr_variable_usage;
while  (vu->next) { vu=vu->next; }
if (vu->subscripts.subscripts_len) {
	// Cant pick an element - must be the whole array
	return 0;
}
/* lets make a copy - so we can select just a single subscript of it */
vu2=clone_variable_usage(e->expr_str_u.expr_variable_usage);

/* now - move to the bottom level */
vu=vu2;
while  (vu->next) { vu=vu->next; }

/* And select a subscript */
vu->subscripts.subscripts_len=1;
vu->subscripts.subscripts_val=malloc(sizeof(vu->subscripts.subscripts_val[0]));
vu->subscripts.subscripts_val[0]=A4GL_new_literal_long_str ("1");

/* Find the variable */
v=find_variable_vu_ptr(errbuff, vu2, &scope,1);

if (v==NULL) return 0;

ensure_variable(errbuff, e, 0);


// Is it a single dimensional array ?
if (v->arr_subscripts.arr_subscripts_len==1) return 1;

// Well - its not...
return 0;

}



void A4GL_ensure_dtype_variables(expr_str_list *s) {
//...
}

void set_report_orderby(struct variable_list *v, struct expr_str_list*params, struct report_orderby_section *orderby) {
	expr_str_list *Eslist;
	int number_of_variables_in_orderby=0;

	if (orderby) {
		if (orderby->variables) {
			number_of_variables_in_orderby=orderby->variables->list.list_len;
		}
	}

	Eslist=expand_parameters(v, params);
/*
	if (Eslist) {
		if (Eslist->list.list_len && number_of_variables_in_orderby==0) {
			int a;
			expr_str_list *nlist;
			nlist=A4GL_new_ptr_list(0);
			for (a=0;a<Eslist->list.list_len;a++) {
				struct expr_str *e;
				e=A4GL_new_variable_usage_with_asc_desc(Eslist->list.list_val[a],"A");
				A4GL_new_append_ptr_list(nlist,e);
			}
			// Need to copy across the parameters to the order by..
			orderby->variables=nlist;
		}
	}
*/
	current_orderby=orderby; /* used for scan_orderby to get the BEFORE/AFTER group numbers */
	return ;
}



/*

int input_str(char *rn,char **r,int isptr,int arr) {
        return input_string(rn,r,isptr,arr);
}



int output_str(char *n, char *r,int isptr,int arr) {
	if (r==0) r="";
 	return output_string(n,r,isptr,arr);
}
*/

int set_bind_var_dtype(char *type, char *errbuff,struct expr_str_list *bindlist) {
int a;
strcpy(errbuff,"");
for (a=0;a<bindlist->list.list_len;a++) {
	if (strcmp(type,"obind_var_let_list")==0) {
		if (!set_var_dtype(errbuff, bindlist->list.list_val[a], 1)) {
			return 0;
		}
	}
	if (strcmp(type,"init_bind_var_list")==0) {
		// We dont mind initializing the whold of an array -----v-----  hence that 0
		if (!set_var_dtype(errbuff, bindlist->list.list_val[a], 0)) {
			return 0;
		}
	}
}

return 1;
}

static int set_var_dtype(char *errbuff, struct expr_str *ptr, int err_if_whole_array) {
struct variable_usage *p;
struct variable *v;
enum e_scope scope;
strcpy(errbuff,"");
if (ptr==0)  {
	strcpy(errbuff, "No expression");
	return 0; // Error condition
}

if (ptr->expr_type==ET_EXPR_TODAY) return 1;
if (ptr->expr_type==ET_EXPR_TIME) return 1;
if (ptr->expr_type==ET_EXPR_PAGENO) return 1;
if (ptr->expr_type==ET_EXPR_LINENO) return 1;

if (ptr->expr_type==ET_EXPR_THROUGH) return 1;
if (ptr->expr_type==ET_EXPR_EXPR_LIST) {
	int a;
	for (a=0;a<ptr->expr_str_u.expr_list->list.list_len;a++) {
		if (!set_var_dtype(errbuff, ptr->expr_str_u.expr_list->list.list_val[a], err_if_whole_array)) {
			return 0;
		}
	}
	return 1;
}
if (ptr->expr_type!=ET_EXPR_VARIABLE_USAGE) {
	strcpy(errbuff, "Not a simple variable expression");
	return 0; // Error condition
}

p=ptr->expr_str_u.expr_variable_usage;
scope=E_SCOPE_NOTSET;
v=find_variable_vu_ptr(errbuff, p,&scope,err_if_whole_array);
if (v==0) {
	if (strlen(errbuff)==0) { 
		// No specific error - so put in something...
		set_yytext(expr_as_string_when_possible(ptr));
		sprintf(errbuff, "'%s' does not represent a defined variable", expr_as_string_when_possible(ptr));
	}
	return 0; // Error condition
}

A4GL_debug("Dtype set to  %d\n",p->datatype);
return 1;
}



struct expr_str *ensure_variable(char *errbuff, struct expr_str *ptr, int err_if_whole_array) {
if (!set_var_dtype(errbuff, ptr, err_if_whole_array)) {
	ptr=0;
}

return ptr;
}








// get an expression list for an expanded record
// ie - we pass in mv_rec
// we get back VARIABLE_USAGE(mv_rec.a), VARIABLE_USAGE(mv_rec.b) etc
struct expr_str_list *get_variable_usage_for_record(struct variable_usage *vu,int err_if_whole_array) {
struct variable *v;
expr_str_list *n;
char errbuff[256];
enum e_scope scope;
//struct variable_usage *vu1;
struct variable_usage *vu_top;
struct variable_usage *vu_next;
struct expr_str *vu_as_expr;
int a;
		v=find_variable_vu_ptr(errbuff, vu, &scope,err_if_whole_array);
		if (v==0) {
			A4GL_assertion(1,"Variable not found");
		}
		if (v->var_data.variable_type!=VARIABLE_TYPE_RECORD) {
			printf("EXPECTED A RECORD...\n");
			return 0;
		}
		
	n=A4GL_new_ptr_list(0);

	for (a=0;a<v->var_data.variable_data_u.v_record.variables.variables_len;a++) {
			vu_top=clone_variable_usage(vu);
			vu_next=vu_top;
			while (vu_next->next) {
				if (strcmp(vu->next->variable_name,"*")==0) break;
				vu_next=vu_next->next;
			}

			vu_next->next=malloc(sizeof(struct variable_usage));
			vu_next->next->variable_name=v->var_data.variable_data_u.v_record.variables.variables_val[a]->names.names.names_val[0].name;
			vu_next->next->subscripts.subscripts_len=0;
			vu_next->next->subscripts.subscripts_val=0;
			vu_next->next->substrings_start=0;
			vu_next->next->substrings_end=0;
			vu_next->next->next=0;
			vu_next->next->datatype=-1;
			vu_next->next->object_type="";
			vu_next->next->escope=E_SCOPE_NOTSET;
			vu_next->next->variable_id=-1;

			if (v->var_data.variable_data_u.v_record.variables.variables_val[a]->arr_subscripts.arr_subscripts_len) {
				int l1=0;
				int l2=0;
				int l3=0;
				struct variable_usage *vu_new=0;
				struct variable_usage *vu_new2=0;
				int dim=0,dim1=0,dim2=0,dim3=0;
				dim=v->var_data.variable_data_u.v_record.variables.variables_val[a]->arr_subscripts.arr_subscripts_len;
				switch (dim) {
					case 1:
						dim1=v->var_data.variable_data_u.v_record.variables.variables_val[a]->arr_subscripts.arr_subscripts_val[0];
						
						break;
					case 2:
						dim1=v->var_data.variable_data_u.v_record.variables.variables_val[a]->arr_subscripts.arr_subscripts_val[0];
						dim2=v->var_data.variable_data_u.v_record.variables.variables_val[a]->arr_subscripts.arr_subscripts_val[1];
						break;
					case 3: 
						dim1=v->var_data.variable_data_u.v_record.variables.variables_val[a]->arr_subscripts.arr_subscripts_val[0];
						dim2=v->var_data.variable_data_u.v_record.variables.variables_val[a]->arr_subscripts.arr_subscripts_val[1];
						dim3=v->var_data.variable_data_u.v_record.variables.variables_val[a]->arr_subscripts.arr_subscripts_val[2];
						break;
					default: A4GL_assertion(1,"Shouldnt get to here"); break;
				}


				switch (dim) {
					case 1:
						for (l1=0;l1<dim1;l1++) {
							vu_new=clone_variable_usage(vu_top);
							vu_new2=vu_new; while (vu_new2->next!=0) { vu_new2=vu_new2->next; }

							vu_new2->subscripts.subscripts_val=malloc(sizeof(expr_str *)*dim);
							vu_new2->subscripts.subscripts_val[0]=A4GL_new_literal_long_long(l1+1);
							vu_new2->subscripts.subscripts_len=dim;
							vu_as_expr=A4GL_new_expr_push_variable(vu_new,current_is_report());
							A4GL_assertion(vu_as_expr==NULL,"Variable should not be null");
							ensure_variable(errbuff, vu_as_expr,err_if_whole_array);
							A4GL_assertion(vu_as_expr==NULL,"Variable should not be null");
							A4GL_new_append_ptr_list(n, vu_as_expr);
						}
						break; // single dimension..
					case 2:
						for (l1=0;l1<dim1;l1++) {
						for (l2=0;l2<dim2;l2++) {
							vu_top->subscripts.subscripts_val=malloc(sizeof(expr_str *)*dim);
							vu_new=clone_variable_usage(vu_top);
							vu_new2=vu_new; while (vu_new2->next!=0) { vu_new2=vu_new2->next; }
							vu_new2->subscripts.subscripts_len=dim;
							vu_new2->subscripts.subscripts_val[0]=A4GL_new_literal_long_long(l1+1);
							vu_new2->subscripts.subscripts_val[1]=A4GL_new_literal_long_long(l2+1);
							vu_as_expr=A4GL_new_expr_push_variable(vu_new,current_is_report());
							A4GL_assertion(vu_as_expr==NULL,"Variable should not be null");
							ensure_variable(errbuff, vu_as_expr,err_if_whole_array);
							A4GL_assertion(vu_as_expr==NULL,"Variable should not be null");
							A4GL_new_append_ptr_list(n, vu_as_expr);
						}
						}
						break; // 2 dimension..
					case 3:
						for (l1=0;l1<dim1;l1++) {
						for (l2=0;l2<dim2;l2++) {
						for (l3=0;l3<dim3;l3++) {
							vu_top->subscripts.subscripts_val=malloc(sizeof(expr_str *)*dim);
							vu_new=clone_variable_usage(vu_top);

							vu_new2=vu_new; while (vu_new2->next!=0) { vu_new2=vu_new2->next; }

							vu_new2->subscripts.subscripts_len=dim;
							vu_new2->subscripts.subscripts_val[0]=A4GL_new_literal_long_long(l1+1);
							vu_new2->subscripts.subscripts_val[1]=A4GL_new_literal_long_long(l2+1);
							vu_new2->subscripts.subscripts_val[2]=A4GL_new_literal_long_long(l3+1);
							vu_as_expr=A4GL_new_expr_push_variable(vu_new,current_is_report());
							A4GL_assertion(vu_as_expr==NULL,"Variable should not be null");
							ensure_variable(errbuff, vu_as_expr,err_if_whole_array);
							A4GL_assertion(vu_as_expr==NULL,"Variable should not be null");
							A4GL_new_append_ptr_list(n, vu_as_expr);
						}
						}
						}
						break; // 3 dimension..
				}
			} else {
				vu_as_expr=A4GL_new_expr_push_variable(vu_top,current_is_report());
				A4GL_assertion(vu_as_expr==NULL,"Variable should not be null");
				ensure_variable(errbuff, vu_as_expr,err_if_whole_array);
				A4GL_assertion(vu_as_expr==NULL,"Variable should not be null");
				A4GL_new_append_ptr_list(n, vu_as_expr);
			}

	}
return n;
}

char *get_variable_bottom_level_name(struct variable_usage *vu ) {
	while (vu->next) {
		vu=vu->next;
	}
	return vu->variable_name;
}





void A4GL_new_append_ptr_list_with_expand(expr_str_list *l,struct expr_str *e) {
//struct expr_str_list *vlist=0;
struct variable_usage *vu_top;
struct variable_usage *vu_last;
struct variable *v_top;
int nsubscripts_expected,nsubscripts_got;
char errbuff[256];
int c1,c2,c3;
enum e_scope scope;

//printf("Here length=%d\n",l->list.list_len);
//printf("-->%s\n",expr_as_string_when_possible(e));

	if (e->expr_type!=ET_EXPR_VARIABLE_USAGE) {
		A4GL_new_append_ptr_list(l,e);
		return;
	}

	vu_top=e->expr_str_u.expr_variable_usage;

	vu_last=vu_top;
	while (vu_last->next) {
		if (strcmp(vu_last->next->variable_name,"*")==0) {
			break;
		}
		vu_last=vu_last->next;
	}
	v_top=find_variable_vu_ptr(errbuff, vu_top, &scope, 0);

	// Is it an array ? 
	if (v_top->var_data.variable_type==VARIABLE_TYPE_ASSOC) {
		nsubscripts_expected=1;
	} else {
		nsubscripts_expected=v_top->arr_subscripts.arr_subscripts_len;
	}
	nsubscripts_got=vu_last->subscripts.subscripts_len;



	if (nsubscripts_got && nsubscripts_got!=nsubscripts_expected) {
		// They've specified *part* of the subscripts - but we were expecting more than one
		a4gl_yyerror("Subscripting error");
	}


	if (nsubscripts_got==0 && nsubscripts_expected>0) {
		if (v_top->arr_subscripts.arr_subscripts_val[0]==-1) { 	// Its a dynamic array..

			A4GL_new_append_ptr_list(l,e);
			return ;
		}
	}

	if (nsubscripts_got==0 && nsubscripts_expected>0) {
		struct variable_usage *vu_new;
		struct variable_usage *vu_next;
		struct expr_str *e2;
		// We need to provide the subscripts
		switch (nsubscripts_expected) {
			case 1:
				for (c1=0;c1<v_top->arr_subscripts.arr_subscripts_val[0];c1++) {
					vu_new=clone_variable_usage(vu_top);
					vu_next=vu_new;
					while (vu_next->next!=0) { vu_next=vu_next->next; }
					vu_next->subscripts.subscripts_len=1;
					vu_next->subscripts.subscripts_val=malloc(sizeof(expr_str *)*1);
					vu_next->subscripts.subscripts_val[0]=A4GL_new_literal_long_long(c1+1);
					e2=A4GL_new_expr_push_variable(vu_new,current_is_report());
					A4GL_new_append_ptr_list_with_expand(l, e2);
				}
				// We're all done - any adding would have been done in the calls...
				return;

			case 2:
				for (c1=0;c1<v_top->arr_subscripts.arr_subscripts_val[0];c1++) {
					for (c2=0;c2<v_top->arr_subscripts.arr_subscripts_val[1];c2++) {
								vu_new=clone_variable_usage(vu_top);
								vu_next=vu_new;
								while (vu_next->next!=0) { vu_next=vu_next->next; }
								vu_next->subscripts.subscripts_len=2;
								vu_next->subscripts.subscripts_val=malloc(sizeof(expr_str *)*2);
								vu_next->subscripts.subscripts_val[0]=A4GL_new_literal_long_long(c1+1);
								vu_next->subscripts.subscripts_val[1]=A4GL_new_literal_long_long(c2+1);
								e2=A4GL_new_expr_push_variable(vu_new,current_is_report());
								A4GL_new_append_ptr_list_with_expand(l, e2);

					}
				}
				// We're all done - any adding would have been done in the calls...
				return;
			case 3:
				//vu_new=clone_variable_usage(vu_top);
				for (c1=0;c1<v_top->arr_subscripts.arr_subscripts_val[0];c1++) {
					for (c2=0;c1<v_top->arr_subscripts.arr_subscripts_val[1];c2++) {
						for (c3=0;c3<v_top->arr_subscripts.arr_subscripts_val[2];c3++) {
								vu_new=clone_variable_usage(vu_top);
								vu_next=vu_new;

								while (vu_next->next!=0) { vu_next=vu_next->next; }
								vu_next->subscripts.subscripts_len=3;
								vu_next->subscripts.subscripts_val=malloc(sizeof(expr_str *)*3);
								vu_next->subscripts.subscripts_val[0]=A4GL_new_literal_long_long(c1+1);
								vu_next->subscripts.subscripts_val[1]=A4GL_new_literal_long_long(c2+1);
								vu_next->subscripts.subscripts_val[2]=A4GL_new_literal_long_long(c3+1);
								e2=A4GL_new_expr_push_variable(vu_new,current_is_report());
								A4GL_new_append_ptr_list_with_expand(l, e2);
						}
					}
				}
				// We're all done - any adding would have been done in the calls...
				return;
			default: 
				A4GL_assertion(1,"Cant handle more than 3 subscripts");
				return;
		}
		A4GL_assertion(1,"Not possible");
	}


	// By the time we get to here - we can't have any unsubscripted array..

	if (strcmp(get_variable_bottom_level_name(vu_top),"*")==0 || v_top->var_data.variable_type==VARIABLE_TYPE_RECORD)  {
		int a;
		struct variable_usage *vu_add;


		// Remove any trailing .*
		vu_add=vu_top;
		while (vu_add) {
			struct variable_usage *vu_next;
			if (!vu_add->next)  break;
			vu_next=vu_add->next;
			if (strcmp(vu_next->variable_name,"*")==0) {
				vu_add->next=0;
			}
			vu_add=vu_add->next;
		}

		
		for (a=0;a<v_top->var_data.variable_data_u.v_record.variables.variables_len;a++) {
			struct variable_usage *vu_new;
			struct expr_str *e2;
			vu_new=clone_variable_usage(vu_top);
			vu_add=new_variable_usage(0,v_top->var_data.variable_data_u.v_record.variables.variables_val[a]->names.names.names_val[0].name ,0);
			append_variable_usage(vu_new, vu_add);
			e2=A4GL_new_expr_push_variable(vu_new,current_is_report());
			A4GL_new_append_ptr_list_with_expand(l, e2);
		}
		return ;
	}

	if (nsubscripts_got==nsubscripts_expected) { A4GL_new_append_ptr_list(l,e); return; }


	A4GL_assertion(1,"Not possible");
	
}




struct expr_str_list *fully_expand_variables_in_expr_str_list(expr_str_list *l) {
expr_str_list *n;
int a;
if (l==0) return l;
if (l->list.list_len==0) return l;

n=A4GL_new_ptr_list(0);
for (a=0;a<l->list.list_len;a++) {
	A4GL_new_append_ptr_list_with_expand(n, l->list.list_val[a]);
}

n= expand_variables_in_expr_str_list(n,0,0);
return n;
}


expr_str_list *expand_variables_in_expr_str_list(expr_str_list *parameters,int err_if_not_var,int err_if_whole_array) {
expr_str_list *n;
char errbuff[256];
enum e_scope scope;
int param_to_add;
if (parameters==NULL) return parameters;


n=A4GL_new_ptr_list(0);


for (param_to_add=0;param_to_add<parameters->list.list_len;param_to_add++) {
	switch (parameters->list.list_val[param_to_add]->expr_type) {

		case ET_EXPR_LINENO:
		case ET_EXPR_PAGENO:
				A4GL_new_append_ptr_list(n,parameters->list.list_val[param_to_add]);
				break;



		case ET_EXPR_VARIABLE_USAGE_WITH_ASC_DESC:
		case ET_EXPR_VARIABLE_USAGE:
			{
				struct variable *v1;
				struct variable_usage *vu1;
				struct variable_usage *last_vu;
				struct expr_str_list *vlist;
				if (parameters->list.list_val[param_to_add]->expr_type==ET_EXPR_VARIABLE_USAGE) {
				vu1=parameters->list.list_val[param_to_add]->expr_str_u.expr_variable_usage;
				} else {
				vu1=parameters->list.list_val[param_to_add]->expr_str_u.expr_variable_usage_with_asc_desc->var_usage;
				}
				A4GL_debug("Got : %s %d \n", cmds_get_variable_usage_as_string(vu1), err_if_whole_array);
				v1=find_variable_vu_ptr(errbuff, vu1, &scope, err_if_whole_array);
				if (v1==0) {
					set_yytext(expr_as_string_when_possible(parameters->list.list_val[param_to_add]));
					if(strlen(errbuff)) {
						a4gl_yyerror(errbuff);
					} else {
						a4gl_yyerror("Variable not found");
					}
					return 0;
				}

				if (strcmp(get_variable_bottom_level_name(vu1),"*")==0 || v1->var_data.variable_type==VARIABLE_TYPE_RECORD)  {
					struct variable_usage *vu_top;
					struct variable_usage *vu_next;

						vu_top=clone_variable_usage(vu1);
						vu_next=vu_top;
						last_vu=vu_next;
						while (vu_next->next) {
							last_vu=vu_next;
							vu_next=vu_next->next;
						}
						last_vu->next=0;

						A4GL_debug("Got to here.. %d %d\n", v1->arr_subscripts.arr_subscripts_len, last_vu->subscripts.subscripts_len);
				
						if (v1->arr_subscripts.arr_subscripts_len && last_vu->subscripts.subscripts_len!=v1->arr_subscripts.arr_subscripts_len) {
							int is_dynamic_array=0;
							// Its also an array..
							if ( v1->arr_subscripts.arr_subscripts_len==1 &&  last_vu->subscripts.subscripts_len==0) {
									if ( v1->arr_subscripts.arr_subscripts_val[0]==-1) {
										is_dynamic_array=1;
									}
							}

							if (err_if_whole_array && ! is_dynamic_array) {
								a4gl_yyerror("You cant use this variable here because its an array");
								return 0;
							} else {
								// Just leave it as is...
								A4GL_new_append_ptr_list(n,parameters->list.list_val[param_to_add]);
							} 
						} else {
							int a;
							vlist=get_variable_usage_for_record(vu_top, err_if_whole_array );
							A4GL_assertion (vlist==0,"Expecting a list");
							for (a=0;a<vlist->list.list_len;a++) {
								A4GL_new_append_ptr_list(n,vlist->list.list_val[a]);
							}
						}
				} else {
					A4GL_new_append_ptr_list(n,parameters->list.list_val[param_to_add]);
				}
			}
			break;

		case ET_EXPR_PARAMETER:
			{
				struct variable_usage *vu1;
				struct variable *v;
				struct expr_str *e;
				vu1=new_variable_usage(0,parameters->list.list_val[param_to_add]->expr_str_u.expr_param.expr_string,0);
				v=find_variable_vu_ptr(errbuff, vu1, &scope, err_if_whole_array);
				if (v==0) {
					set_yytext(expr_as_string_when_possible(parameters->list.list_val[param_to_add]));
					if(strlen(errbuff)) {
						a4gl_yyerror(errbuff);
					} else {
						a4gl_yyerror("Variable not found");
					}
					return 0;
				}
				if (v->var_data.variable_type == VARIABLE_TYPE_RECORD) {
					int a;
					struct variable_usage *vu_top;
					struct variable_usage *vu_next;

					for(a=0;a<v->var_data.variable_data_u.v_record.variables.variables_len;a++) {
						vu_top=clone_variable_usage(vu1);
						vu_next=new_variable_usage(0,v->var_data.variable_data_u.v_record.variables.variables_val[a]->names.names.names_val[0].name ,0);
						append_variable_usage(vu_top,vu_next);

						e=A4GL_new_expr_push_variable(vu_top,current_is_report());
						A4GL_new_append_ptr_list(n,e);
					}
				} else {
					e=A4GL_new_expr_push_variable(vu1,current_is_report());
					A4GL_new_append_ptr_list(n,e);
				}
			}
			break;


		case ET_EXPR_THROUGH: 
			{
				//int b;
				//expr_str_list *n1;
				struct variable *v1;
				struct variable_usage *vt1;
				struct variable *v2;
				struct variable_usage *vt2;
				struct variable_usage *vu1;
				struct variable_usage *vu2;
				struct variable_usage *last_vu;
				struct variable_usage *vu_top;
				struct variable_usage *vu_next;
				struct expr_str_list *vlist;
				int start;
				int end;
				int a;
				char buff1[2000];
				char buff2[2000];
				//struct expr_str *det;
				struct expr_str_list *s;
				s=parameters->list.list_val[param_to_add]->expr_str_u.expr_list;
				A4GL_assertion(s->list.list_len!=2,"Not a through...");	
				A4GL_assertion(s->list.list_val[0]->expr_type!=ET_EXPR_VARIABLE_USAGE,"Expecting a variable usage");
				A4GL_assertion(s->list.list_val[1]->expr_type!=ET_EXPR_VARIABLE_USAGE,"Expecting a variable usage");
				vu1=s->list.list_val[0]->expr_str_u.expr_variable_usage;
				vu2=s->list.list_val[1]->expr_str_u.expr_variable_usage;
				strcpy(buff1,"");
				strcpy(buff2,"");
				v1=find_variable_vu_ptr(errbuff, vu1, &scope, err_if_whole_array);
				if (v1==0) {
					set_yytext(expr_as_string_when_possible(parameters->list.list_val[param_to_add]));
					if(strlen(errbuff)) {
						a4gl_yyerror(errbuff);
					} else {
						a4gl_yyerror("Variable not found");
					}
					return 0;
				}
				v2=find_variable_vu_ptr(errbuff, vu2, &scope, err_if_whole_array);
				if (v2==0) {
					set_yytext(expr_as_string_when_possible(parameters->list.list_val[param_to_add]));
					if(strlen(errbuff)) {
						a4gl_yyerror(errbuff);
					} else {
						a4gl_yyerror("Variable not found");
					}
					return 0;
				}

				// Lets check that they look the same...
				vt1=vu1;
				while (vt1) { if (strlen(buff1)) {strcat(buff1,".");} if (vt1->next) strcat(buff1,vt1->variable_name); vt1=vt1->next; }
				vt2=vu2;
				while (vt2) { if (strlen(buff2)) {strcat(buff2,".");} if (vt2->next) strcat(buff2,vt2->variable_name); vt2=vt2->next; }
				if (strcmp(buff1,buff2)!=0) { // Not the same prefix...
					a4gl_yyerror("Not a common record for 'through'");
					return 0;
				}
			
				vu_top=clone_variable_usage(vu1);
				vu_next=vu_top;
				last_vu=vu_top;
				while (vu_next->next) {
						last_vu=vu_next;
						vu_next=vu_next->next;
				}
				vu_next=last_vu->next;
				last_vu->next=0;
				vlist=get_variable_usage_for_record(last_vu, err_if_whole_array);
				last_vu->next=vu_next;
				start=-1;
				end=-1;

				for (a=0;a<vlist->list.list_len;a++) {
					if (strcmp(get_variable_bottom_level_name(vlist->list.list_val[a]->expr_str_u.expr_variable_usage), get_variable_bottom_level_name(vu1))==0) {
						start=a;
					}
					if (strcmp(get_variable_bottom_level_name(vlist->list.list_val[a]->expr_str_u.expr_variable_usage), get_variable_bottom_level_name(vu2))==0) {
						end=a;
					}
				}
				if (start==-1) { a4gl_yyerror("START of through not found"); return 0; }
				if (end==-1) { a4gl_yyerror("END of through not found"); return 0; }
				for (a=start;a<=end;a++) {
					A4GL_new_append_ptr_list(n,vlist->list.list_val[a]);
				}
				//  vu_next should now point to the bottom level...
				
			}
			break;


		default :
			if (err_if_not_var) {
					A4GL_assertion(1,"Unhandled..");
					break;
			} else {
				A4GL_new_append_ptr_list(n,parameters->list.list_val[param_to_add]);
				break;
			}
	}
}


for (param_to_add=0;param_to_add<n->list.list_len;param_to_add++) {
	char errbuff[256];
        switch (n->list.list_val[param_to_add]->expr_type) {
                case ET_EXPR_VARIABLE_USAGE:
			if (!ensure_variable(errbuff, n->list.list_val[param_to_add], err_if_whole_array)) {
				a4gl_yyerror(errbuff);
				return 0;
			}
			
			break;
		default:
			break;
	}
}

return n;
}



static int has_dependant_table(char *s) {
int a;
for (a=0;a<this_module.dependant_tables.dependant_tables_len;a++) {
	if (strcmp(s,this_module.dependant_tables.dependant_tables_val[a].tabname)==0) {
		return 1;
	}

}
return 0;
}

void add_dependant_table(char *s) {
	if (!has_dependant_table(s)) {
		this_module.dependant_tables.dependant_tables_len++;
		this_module.dependant_tables.dependant_tables_val=realloc(this_module.dependant_tables.dependant_tables_val , sizeof(this_module.dependant_tables.dependant_tables_val[0])*this_module.dependant_tables.dependant_tables_len);
		this_module.dependant_tables.dependant_tables_val[this_module.dependant_tables.dependant_tables_len-1].tabname=strdup(s);
		this_module.dependant_tables.dependant_tables_val[this_module.dependant_tables.dependant_tables_len-1].checksuminfo=strdup(A4GLSQL_get_table_checksum(s));
	}

}


int inc_var_usage_from_binding_list(struct expr_str_list *l) {
int a;
        if (l==0) return 1;
        for (a=0;a<l->list.list_len;a++) {
		if (l->list.list_val[a]->expr_type==ET_EXPR_VARIABLE_USAGE) {
                	inc_var_usage(l->list.list_val[a]);
		}
        }
	return 1;
}

int inc_var_assigned_from_binding_list(expr_str_list *l)  {
int a;
        if (l==0) return 1;
        for (a=0;a<l->list.list_len;a++) {
		if (l->list.list_val[a]->expr_type==ET_EXPR_VARIABLE_USAGE) {
                inc_var_assigned(l->list.list_val[a]);
		}
        }
	return 1;
}



int ignore_var_usage_for_builtin_variable(expr_str *str ) {
if (str->expr_type!=ET_EXPR_VARIABLE_USAGE) return 0;
if (A4GL_isyes(acl_getenv("A4GL_STATUSASCOL"))) {
	if (strcmp(str->expr_str_u.expr_variable_usage->variable_name,"a4gl_status")==0) return 1;

}
return 0;
}




