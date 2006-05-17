%{
#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif
#ifdef RPCGEN_HEADERS
	#include "npcode.h"
#else
	#include "npcode.xs.h"
#endif
#include <stdlib.h>
#include <string.h>
#include "npcode_defs.h"
#include "a4gl_memhandling.h"

int while_cnt=0;
int if_cnt=0;

int while_stack[256];
int while_stack_cnt=0;

int if_stack[256];
int if_stack_cnt=0;

static char buff[20];
extern module *this_module_ptr;

void make_named_struct (char *name, struct define_variables *v);

%}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token AND_OP 
%token OR_OP
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME  FGLDATE   FGLDECIMAL FGLMONEY
%type <param> variable
%type <define_var>   param dtype

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS FUNCTION

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%token ON_KEY BEF_ROW AFT_ROW AFTER_INP
%token KW_A_PUSH_LONG 
%token KW_A_PUSH_INT
%token KW_A_PUSH_CHAR
%token KW_A_PUSH_OP
%token KW_A_CHK_ERR
%token KW_A_CLR_ERR
%token KW_A_ERRCHK
%token KW_A_ECALL
%token KW_A_SET_STAT
%token KW_A_SETLINE
%token KW_A_POP_VAR2
%token KW_A_POP_FUNCTION
%token KW_A_PUSH_FUNCTION
%token KW_A_POP_ARGS
%token KW_A_POP_PARAMS
%token KW_A_PUSH_VARIABLE
%token KW_A_SUBSTR



%start translation_unit

%union {
	char str[10000];
	struct cmd *cmd;
	void *ptr;
	long e_id;
	int i;
	struct variable_element *define_var;
	struct use_variable 	*use_var;
	struct define_variables *define_variables;
	struct s_assign assignment;
	struct char_list clist;
}

%%


translation_unit : tu
	| translation_unit tu
;


tu : function_definition
	|  define_entry_op_set
;

op_function: | FUNCTION 
;


function_definition :
	 op_function IDENTIFIER '(' fparm  ')' '{'			{ 
		add_function($<str>2,$<define_variables>4,0); } 	func_block 
				{ end_function(); }
	| op_function STATIC IDENTIFIER '(' fparm  ')' '{'		{ add_function($<str>3,$<define_variables>5,1); } 	func_block { end_function(); }
	| op_function STATIC dtype IDENTIFIER '(' fparm  ')' '{'	{ add_function($<str>4,$<define_variables>6,1); } 	func_block { end_function(); }
	| op_function dtype IDENTIFIER '(' fparm  ')' '{'		{ add_function($<str>3,$<define_variables>5,0); } 	func_block { end_function(); }

	| op_function dtype IDENTIFIER '(' VOID  ')' '{'		{ add_function($<str>3,0,0); } 				func_block { end_function(); }
	| op_function STATIC dtype IDENTIFIER '(' VOID  ')' '{'	{ add_function($<str>4,0,1); } 				func_block { end_function(); }
	| op_function STATIC IDENTIFIER '(' VOID  ')' '{'		{ add_function($<str>3,0,1); } 				func_block { end_function(); }

	| op_function dtype IDENTIFIER '('  ')' '{'		{ add_function($<str>3,0,0); } 				func_block { end_function(); }
	| op_function STATIC dtype IDENTIFIER '('  ')' '{'		{ add_function($<str>4,0,1); } 				func_block { end_function(); }
	| op_function STATIC IDENTIFIER '('  ')' '{'		{ add_function($<str>3,0,1); } 				func_block { end_function(); }
;



op_cmds:
	| cmds
;


cmds : cmd
	| cmd cmds
;

cmd :
	
	';' /* Nothing... */
	| block
	| if
        | for
	| while
	| goto ';'
	| label 
	| assign ';'
	| fcall ';'
	| break ';'
	| continue ';'
	| return ';'
	| expr ';'
/* 4GL specific shortcuts */
	| fgl_funcs
;



typedef_decl:
	TYPEDEF dtype  IDENTIFIER {
		printf("Adding : %s\n",$<str>3);
		make_named_struct ($<str>3, $<define_variables>2);
		printf("Added %s\n",$<str>3);
	}
;

a4gl_sub: 
KW_A_SUBSTR	 '(' op_expr_list ')'  { $<e_id>$=new_param_fcall_returns_long($<str>1,$<e_id>3); }
;

fgl_funcs :
	a4gl_sub {
			add_push_substr($<e_id>1);
	}
	|KW_A_PUSH_LONG '(' int_constant_val ')' {
			add_push_long(atoi($<str>3));
	}
	| KW_A_POP_ARGS '(' variable ')' {
			add_pop_args($<e_id>3);
	}
	| KW_A_POP_FUNCTION '(' ')'  {
		add_pop_function();
	}
	| KW_A_POP_VAR2 '('  variable ',' int_constant_val ',' int_constant_val ')'
	| KW_A_PUSH_FUNCTION '(' IDENTIFIER ',' IDENTIFIER ',' IDENTIFIER ')' 
	| KW_A_POP_PARAMS '(' variable ',' int_constant_val ')'
	| KW_A_PUSH_VARIABLE '(' variable ',' int_constant_val ')'


	| KW_A_PUSH_INT '(' int_constant_val ')' {
			add_push_int(atoi($<str>3));
	}
	| KW_A_PUSH_CHAR '(' STRING_LITERAL ')' {
			add_push_char($<str>3);
	}
	| KW_A_PUSH_OP '(' CONSTANT ')' {
			add_push_op($<str>3);
	}
	| KW_A_SET_STAT '(' int_constant_val ',' int_val ')' {
			add_set_stat(atoi($<str>3));
	}
	| KW_A_SETLINE '(' int_val ',' int_val ')' {
			add_set_line("",atoi($<str>5));
	}
	| KW_A_SETLINE '(' IDENTIFIER ',' int_val ')' {
			add_set_line($<str>3,atoi($<str>5));
	}
	| KW_A_SETLINE '(' STRING_LITERAL ',' int_val ')' {
			add_set_line($<str>3,atoi($<str>5));
	}
	| KW_A_ECALL '(' STRING_LITERAL ',' int_val ',' int_val ')' {
			//printf("ECALL....\n"); 
			add_ecall($<str>3, get_expr_n($<e_id>5),get_expr_n($<e_id>7));
	}

	| KW_A_PUSH_CHAR '(' variable ')' {
		add_push_charv($<e_id>3);
	}
	| KW_A_PUSH_CHAR '(' a4gl_sub ')' {
		add_push_charv($<e_id>3);
	}
	| KW_A_CHK_ERR '(' int_val ',' IDENTIFIER ')' {
			add_chk_err(get_expr_n($<e_id>3));
	}
	| KW_A_CHK_ERR '(' int_val ',' STRING_LITERAL ')' {
			add_chk_err(get_expr_n($<e_id>3));
	}
	| KW_A_CLR_ERR '(' ')' {
			add_clr_err();
	}
	| KW_A_ERRCHK '(' int_val ',' STRING_LITERAL ','  
		int_val ',' STRING_LITERAL ','
		int_val ',' STRING_LITERAL ','
		int_val ',' STRING_LITERAL ','
		int_val ',' STRING_LITERAL ','
		int_val ',' STRING_LITERAL 
			')' {
			struct cmd_errchk *ptr;
			struct cmd_errchk_40110 *ptr_40110;
			struct cmd_errchk_40010 *ptr_40010;
			struct cmd_errchk_40000 *ptr_40000;
			int added=0;

			ptr=acl_malloc2(sizeof(struct cmd_errchk));
			ptr_40110=acl_malloc2(sizeof(struct cmd_errchk_40110));
			ptr_40010=acl_malloc2(sizeof(struct cmd_errchk_40010));
			ptr_40000=acl_malloc2(sizeof(struct cmd_errchk_40000));

			memset(ptr,0,sizeof(struct cmd_errchk));
			memset(ptr_40110,0,sizeof(struct cmd_errchk_40110));
			memset(ptr_40010,0,sizeof(struct cmd_errchk_40010));
			memset(ptr_40000,0,sizeof(struct cmd_errchk_40000));

			ptr->line=get_expr_n($<e_id>3);
			ptr->module_name=add_string($<str>5);

			ptr_40110->line=get_expr_n($<e_id>3);
			ptr_40110->module_name=add_string($<str>5);

			ptr_40010->line=get_expr_n($<e_id>3);
			ptr_40010->module_name=add_string($<str>5);
			ptr_40000->line=get_expr_n($<e_id>3);
			ptr_40000->module_name=add_string($<str>5);

			ptr->modes[0]=get_expr_n($<e_id>7);
			ptr->modes[1]=get_expr_n($<e_id>11);
			ptr->modes[2]=get_expr_n($<e_id>15);
			ptr->modes[3]=get_expr_n($<e_id>19);
			ptr->modes[4]=get_expr_n($<e_id>23);
	
			ptr->actions[0]=add_string($<str>9);
			ptr->actions[1]=add_string($<str>13);
			ptr->actions[2]=add_string($<str>17);
			ptr->actions[3]=add_string($<str>21);
			ptr->actions[4]=add_string($<str>25);

	if (ptr->modes[0]==4 && ptr->modes[1]==0 && ptr->modes[2]==1 && ptr->modes[3]==1 && ptr->modes[4]==0 ) {
		add_errchk_40110(ptr_40110);
		added=1;
	} 
	if (ptr->modes[0]==4 && ptr->modes[1]==0 && ptr->modes[2]==0 && ptr->modes[3]==1 && ptr->modes[4]==0 ) {
		add_errchk_40010(ptr_40010);
		added=1;
	} 
	if (ptr->modes[0]==4 && ptr->modes[1]==0 && ptr->modes[2]==0 && ptr->modes[3]==0 && ptr->modes[4]==0 ) {
		add_errchk_40000(ptr_40000);
		added=1;
	} 
	if (!added) {
		add_errchk(ptr);
	}
}
;



break: BREAK {
		add_break(while_stack[while_stack_cnt-1]);
	}
;

continue: CONTINUE {
		add_continue(while_stack[while_stack_cnt-1]);
	}
;

fparm: 
		{$<define_variables>$=0;}
	| has_fparam {$<define_variables>$=$<define_variables>1;}
;
	
has_fparam:
	param  			{
					$<define_variables>$=acl_malloc2(sizeof(struct define_variables));
					$<define_variables>$->var_len=1;
					$<define_variables>$->var_val=acl_malloc2(sizeof(struct variable_element));
					memcpy(&$<define_variables>$->var_val[0],$<define_var>1,sizeof(struct variable_element));
				}
	| has_fparam ',' param 	{ 
				struct define_variables *v;
				v=$<define_variables>1;
				v->var_len++;
				v->var_val=realloc(v->var_val, sizeof(struct variable_element)*v->var_len);
					memcpy(&v->var_val[v->var_len-1],$<define_var>3,sizeof(struct variable_element));
	}
		
;

has_structparam:
	param_semi  			{
					struct define_variables *v;
					v=acl_malloc2(sizeof(struct define_variables));
					v->var_len=1;
					v->var_val=acl_malloc2(sizeof(struct variable_element));
					memcpy(&v->var_val[0],$<define_var>1,sizeof(struct variable_element));
					$<define_variables>$=v;
				}
	| has_structparam  param_semi 	{ 
				struct define_variables *v;
				//char buff[80];
				v=$<define_variables>1;
				v->var_len++;
				v->var_val=realloc(v->var_val, sizeof(struct variable_element)*v->var_len);
				A4GL_debug("Name = %d\n",$<define_var>2->name_id);
				memcpy(&v->var_val[v->var_len-1],$<define_var>2,sizeof(struct variable_element));
				$<define_variables>$=v;
	}
		
;


param_semi : param ';' {$<define_var>$=$<define_var>1;}

;

param : dtype   id_list 			{$<define_var>$=$<define_var>1; $<define_var>$->name_id=add_id($<str>2); }
	| dtype id_list '[' dtype_int_val ']' 	{
				long x;
				$<define_var>$=$<define_var>1; 
				$<define_var>$->name_id=add_id($<str>2); 
				evaluate_param_i_into_integer($<e_id>4,&x);
				$<define_var>$->i_arr_size[0]=x;
				$<define_var>$->i_arr_size[1]=0;
				$<define_var>$->i_arr_size[2]=0;
	}
	| dtype id_list '[' dtype_int_val ']' '[' dtype_int_val ']' 	{
				long x;
				$<define_var>$=$<define_var>1;
				$<define_var>$->name_id=add_id($<str>2); 
				evaluate_param_i_into_integer($<e_id>4,&x);
				$<define_var>$->i_arr_size[0]=x;
				evaluate_param_i_into_integer($<e_id>4,&x);
				$<define_var>$->i_arr_size[1]=x;
				$<define_var>$->i_arr_size[2]=0;

	}
	| dtype id_list '[' dtype_int_val ']' '[' dtype_int_val ']' '[' dtype_int_val ']'	{
				long x;
				$<define_var>$=$<define_var>1;
				$<define_var>$->name_id=add_id($<str>2); 
				evaluate_param_i_into_integer($<e_id>4,&x);
				$<define_var>$->i_arr_size[0]=x;
				evaluate_param_i_into_integer($<e_id>4,&x);
				$<define_var>$->i_arr_size[1]=x;
				evaluate_param_i_into_integer($<e_id>4,&x);
				$<define_var>$->i_arr_size[2]=x;

	}
	| dtype id_list '['  ']' 		{	//struct param *sz;
								$<define_var>$=$<define_var>1; 
								$<define_var>$->name_id=add_id($<str>2);
								$<define_var>$->i_arr_size[0]=-1;
						}
;


id_list : IDENTIFIER 
;


define: {end_define();}
	| has_define {end_define();}
;

has_define:
	define_entry_op_set 
	| has_define define_entry_op_set 
;


define_entry_op_set:
		define_entry  ';' {set_type(0);}
	| typedef_decl ';' {set_type(0);}
;


op_set : | set {set_master_set($<e_id>1);} 
;


return: 
	RETURN  {add_return(0);}
	| RETURN expr {add_return($<e_id>2);}
	;


set: '=' set_internal {
	$<e_id>$=$<e_id>2;
}
;


set_internal: 
	  expr {$<e_id>$=$<e_id>1;}
	| '{' s_expr_list '}' { $<e_id>$=$<e_id>2; }
	| '{' '}' { $<e_id>$=0; }
	;

s_expr_list : set_internal 		{$<e_id>$=new_param_list_returns_long($<e_id>1);}
	| s_expr_list ',' set_internal  {append_param_list($<e_id>1,$<e_id>3);$<e_id>$=$<e_id>1;}
;



define_qualifier :  
	STATIC {$<i>$=CAT_STATIC;set_type(1);}
	| EXTERN {$<i>$=CAT_EXTERN;set_type(2);}
;

	


define_entry: 
	opd_define_entry op_set { set_master_type(CAT_NORMAL); }
	| qualified opd_define_entry  op_set { set_master_type($<i>1); }
;

qualified : define_qualifier {$<i>$=$<i>1;}
	| qualified define_qualifier  {$<i>$=$<i>1|$<i>2;}
;

opd_define_entry:  
/* Variable definitions */
	  dtype IDENTIFIER   					{add_variable(0,$<define_var>1,$<str>2,0);}
	| dtype IDENTIFIER '['  ']'   				{
			long as[3];
			as[0]=-1;
			as[1]=0;
			as[2]=0;
			add_variable_array(0,$<define_var>1,$<str>2,as,0);
	}
	| dtype IDENTIFIER '[' dtype_int_val ']'   		{
			long as[3];
			long x;
				evaluate_param_i_into_integer($<e_id>4,&x);
				as[0]=x;
				as[1]=0;
				as[2]=0;
				add_variable_array(0,$<define_var>1,$<str>2,as,0);
	}
	| dtype IDENTIFIER '[' dtype_int_val ']' '[' dtype_int_val ']'  		{
			long as[3];
			long x;
			evaluate_param_i_into_integer($<e_id>4,&x);
			as[0]=x;
			evaluate_param_i_into_integer($<e_id>7,&x);
			as[1]=x;
			as[2]=0;

			add_variable_array(0,$<define_var>1,$<str>2,as,0);
	}
	| dtype IDENTIFIER '[' dtype_int_val ']' '[' dtype_int_val ']' '[' dtype_int_val ']' 		{
			long as[3];
			long x;
			evaluate_param_i_into_integer($<e_id>4,&x);
			as[0]=x;
			evaluate_param_i_into_integer($<e_id>7,&x);
			as[1]=x;
			evaluate_param_i_into_integer($<e_id>10,&x);
			as[2]=x;
			add_variable_array(0,$<define_var>1,$<str>2,as,0);

	}
;



dtype_int_val :
		int_val  {$<e_id>$=$<e_id>1;}
		| int_val '+' int_val {
	int n;
		n=get_expr_n($<e_id>1) +  get_expr_n($<e_id>3);
		$<e_id>$=new_param_returns_long('I',(void *)n);
	}
;

dtype :
	CHAR  				{$<define_var>$=new_variable_element_string("CHAR");}
	| SIGNED CHAR  			{$<define_var>$=new_variable_element_string("CHAR");}
	| UNSIGNED CHAR 		{$<define_var>$=new_variable_element_string("UCHAR");}
	| SHORT 			{$<define_var>$=new_variable_element_string("SHORT");}
	| SHORT INT			{$<define_var>$=new_variable_element_string("SHORT");}
	| INT 				{$<define_var>$=new_variable_element_string("LONG");}
	| UNSIGNED SHORT 		{$<define_var>$=new_variable_element_string("USHORT");}
	| SIGNED SHORT 			{$<define_var>$=new_variable_element_string("SHORT");}
	| UNSIGNED INT 			{$<define_var>$=new_variable_element_string("ULONG");}
	| SIGNED INT 			{$<define_var>$=new_variable_element_string("LONG");}
	| UNSIGNED SHORT INT 		{$<define_var>$=new_variable_element_string("USHORT");}
	| SIGNED SHORT INT 		{$<define_var>$=new_variable_element_string("SHORT");}
	| FGLDATE			{$<define_var>$=new_variable_element_string("FGLDATE");}
	| FGLDECIMAL			{$<define_var>$=new_variable_element_string("FGLDECIMAL");}
	| FGLMONEY			{$<define_var>$=new_variable_element_string("FGLMONEY");}
	| LONG 				{$<define_var>$=new_variable_element_string("LONG");}
	| LONG INT 				{$<define_var>$=new_variable_element_string("LONG");}

	| UNSIGNED LONG 		{$<define_var>$=new_variable_element_string("ULONG");}
	| UNSIGNED LONG INT		{$<define_var>$=new_variable_element_string("ULONG");}

	| LONG LONG			{$<define_var>$=new_variable_element_string("LONGLONG");}
	| SIGNED LONG LONG		{$<define_var>$=new_variable_element_string("LONGLONG");}
	| UNSIGNED LONG LONG		{$<define_var>$=new_variable_element_string("ULONGLONG");}

	| LONG LONG INT			{$<define_var>$=new_variable_element_string("LONGLONG");}
	| SIGNED LONG LONG INT		{$<define_var>$=new_variable_element_string("LONGLONG");}
	| UNSIGNED LONG LONG INT		{$<define_var>$=new_variable_element_string("ULONGLONG");}
	| FLOAT 			{$<define_var>$=new_variable_element_string("FLOAT");}
	| DOUBLE			{$<define_var>$=new_variable_element_string("DOUBLE");}
	| VOID				{$<define_var>$=new_variable_element_string("Void");}
	| CHAR '*' 			{$<define_var>$=new_variable_element_string("String");}
	| INT '*' 			{$<define_var>$=new_variable_element_string("LongPtr");}
	| LONG '*' 			{$<define_var>$=new_variable_element_string("LongPtr");}
	| SHORT '*' 			{$<define_var>$=new_variable_element_string("ShortPtr");}
	| VOID '*' 			{$<define_var>$=new_variable_element_string("VoidPointer");}
	| VOID '*' '*' 			{$<define_var>$=new_variable_element_string("VoidPointer");}
	| VOID '*' '*' '*' 		{$<define_var>$=new_variable_element_string("VoidPointer");}
	| STRUCT struct_has_define  	{$<define_var>$=new_variable_struct($<define_variables>2); }
	| TYPE_NAME 			{
						struct define_variables *v;
						struct variable_element *e;
						v=add_named_struct($<str>1);
						printf("v=%p\n",v);
						e=new_variable_struct(v);
						printf("e=%p\n",e);
						$<define_var>$=e;
						printf("Get : %p\n",$<define_var>$);
					}
;

struct_has_define: 
		IDENTIFIER {
			$<define_variables>$=(struct define_variables *)add_named_struct($<str>1);
		}
		| TYPE_NAME {$<define_variables>$=(struct define_variables *)add_named_struct($<str>1);}
		|  '{' has_structparam '}' {
			A4GL_debug("Structure : %p\n",$<define_variables>2);
			$<define_variables>$=$<define_variables>2;
		A4GL_debug("BBB : %p from %p\n",$<define_variables>$,$<define_variables>2);
		}  
;


func_block : 
	define 
	op_cmds 
'}'

;


block : '{' { add_block(0); set_pc_vstack_curr(); }
	define op_cmds '}' {end_block();}
	| '{' '}'  {add_block(0); set_pc_vstack_curr(); end_block(); }

;


if: IF '(' expr ')' {
			if_cnt++;
			if_stack[if_stack_cnt++]=if_cnt;
			$<i>$=if_cnt;
			sprintf(buff,"_if_c_%d",if_cnt);
			A4GL_debug("i = %d\n",$<i>$);
			add_label(buff);
			sprintf(buff,"_if_else_%d",if_cnt);
			add_if($<e_id>3,0,acl_strdup(buff));
			}
		cmd  {
			A4GL_debug("using i = %d\n",$<i>5);
			sprintf(buff,"_if_end_%d",$<i>5);
			add_goto(buff);
			sprintf(buff,"_if_else_%d",$<i>5);
			add_label(buff);
			} 
		op_else {
			sprintf(buff,"_if_end_%d",$<i>5);
			add_label(buff);
			if_stack_cnt--;
			}
;


op_else:  
	| ELSE cmd 
;


for : 
	FOR '(' assign ';' {
		        while_cnt++;
                        while_stack[while_stack_cnt++]=while_cnt;
                        $<i>$=while_cnt;
                        sprintf(buff,"_while_c_%d",while_cnt);
                        add_label(buff);
	} expr ';' {
                        sprintf(buff,"_while_e_%d",$<i>5);
                        add_if($<e_id>6,0,acl_strdup(buff));
	}
	assign_common ')' cmd 
	{
			add_set_var($<assignment>9.v,$<assignment>9.p,0,0,0);


                        sprintf(buff,"_while_c_%d",$<i>5);
                        add_goto(buff);
                        sprintf(buff,"_while_e_%d",$<i>5);
                        add_label(buff);
                        while_stack_cnt--;
	}
;


while : WHILE {
			while_cnt++;
			while_stack[while_stack_cnt++]=while_cnt;
			$<i>$=while_cnt;
			sprintf(buff,"_while_c_%d",while_cnt);
			add_label(buff);

		} '(' expr ')'  {
			sprintf(buff,"_while_e_%d",$<i>2);
			add_if($<e_id>4,0,acl_strdup(buff));
		} cmd {
			sprintf(buff,"_while_c_%d",$<i>2);
			add_goto(buff);
			sprintf(buff,"_while_e_%d",$<i>2);
			add_label(buff);
			while_stack_cnt--;
		}
;

label : IDENTIFIER ':' cmd {
		add_label($<str>1);
	}
;

goto: GOTO IDENTIFIER {
		add_goto($<str>2);
	}
;

expr :   or_expr  {$<e_id>$=$<e_id>1;}
;


or_expr: and_expr  {$<e_id>$=$<e_id>1;}
	| or_expr OR_OP and_expr   { $<e_id>$=new_param_op_returns_long($<e_id>1,$<str>2,$<e_id>3); }
;

and_expr : other_expr_1  {$<e_id>$=$<e_id>1;}
	| and_expr AND_OP other_expr_1  { $<e_id>$=new_param_op_returns_long($<e_id>1,$<str>2,$<e_id>3); }
;


other_expr_1: expr_1
;

expr_1:
	 op 			{$<e_id>$=$<e_id>1; }  
	| int_val 		{$<e_id>$=$<e_id>1;}
	| STRING_LITERAL 	{
			char *buff;
			char *buff2;
			buff=acl_strdup($<str>1);
			buff2=&buff[1];
			buff2[strlen(buff2)-1]=0;
			$<e_id>$=new_param_returns_long('s',buff2); 
			free(buff);
			}
	| fcall_expr 	 	{$<e_id>$=$<e_id>1; }
	| variable 		{$<e_id>$=$<e_id>1; }  
	| '(' expr ')'   	{$<e_id>$=$<e_id>2; }
	| cast expr     	{$<e_id>$=$<e_id>2; }
	| '!' expr 		{$<e_id>$=new_param_op_returns_long($<e_id>2,"NOT",0);}
	| BEF_ROW 		{ $<e_id>$=new_param_returns_long('S',"BEF_ROW");}
	| AFT_ROW 		{ $<e_id>$=new_param_returns_long('S',"AFT_ROW");}
	| AFTER_INP 		{ $<e_id>$=new_param_returns_long('S',"AFTER_INP");}
	| ON_KEY '(' STRING_LITERAL ')' { $<e_id>$=new_param_returns_long('K',$<str>3);}


;

cast:
	'(' dtype ')'
	;

op_expr_list : {$<e_id>$=0; }
	| expr_list  {$<e_id>$=$<e_id>1;}

;

expr_list:
	expr {$<e_id>$=new_param_list_returns_long($<e_id>1);
		}
	| expr_list ',' expr {
			append_param_list($<e_id>1,$<e_id>3);
			$<e_id>$=$<e_id>1;
	}
;


fcall :
	IDENTIFIER '('  op_expr_list ')' {
		add_call($<str>1,$<e_id>3);
	}
	
;

fcall_expr :
	IDENTIFIER '('  op_expr_list ')' {
			$<e_id>$=new_param_fcall_returns_long($<str>1,$<e_id>3);
			
	}
	| SIZEOF '(' op_expr_list ')' {
				$<e_id>$=new_param_fcall_returns_long($<str>1,$<e_id>3);
	}
;



op: 
	 expr_1 double_operator expr_1 {
		$<e_id>$=new_param_op_returns_long($<e_id>1,$<str>2,$<e_id>3);
		}
;




double_operator:
 	 LE_OP 
 	| GE_OP 
 	| EQ_OP 
 	| NE_OP
 	| '+'
 	| '-'
 	| '*'
 	| '%'
 	| '/'
	| '<'
	| '>'
 ;

int_constant_val :
		CONSTANT 
			| '+' CONSTANT {sprintf($<str>$,"%s",$<str>2);}
			| '-' CONSTANT {sprintf($<str>$,"-%s",$<str>2);}
			;

	
int_val: int_constant_val {
			char buff[256];
			unsigned long n=0;
			sprintf(buff,$<str>1);
			if (buff[0]=='0') {
				
				if (buff[1]=='x'||buff[1]=='X') {
					if (strcmp(buff,"0xffffffff")==0) {
						n=0xffffffff;
					}  else {
						n=strtol(buff,0,16);
					}
				} else {
					n=strtol(buff,0,8);
				}
			} else {
				n=atoi($<str>1);
			}
			$<e_id>$=new_param_returns_long('I',(void *)n);
}
;




assign: assign_common {
	add_set_var($<assignment>1.v,$<assignment>1.p,0,0,0);
	}
;


assign_common: variable '=' expr {
	struct param *e;
	struct use_variable *v;
	e=&PARAM_ID(this_module_ptr,$<e_id>1);
	v=get_use_variable($<e_id>1);
	$<assignment>$.p=$<e_id>3;
	$<assignment>$.v=v;

}
| variable INC_OP {
	int e_id2;
	int n;
	n=new_param_returns_long('I',(void *)1);
	e_id2=new_param_op_returns_long($<e_id>1,"+",n);
	$<assignment>$.p=e_id2;
	$<assignment>$.v=get_use_variable($<e_id>1);
}
| variable DEC_OP {
	int e_id2;
	int n;
	n=new_param_returns_long('I',(void *)1);
        e_id2=new_param_op_returns_long($<e_id>1,"-",n);
        $<assignment>$.p=e_id2;
        $<assignment>$.v=get_use_variable($<e_id>1);
}
| variable ADD_ASSIGN expr {
	long e2;
	e2=new_param_op_returns_long($<e_id>1,"+",$<e_id>3);
	$<assignment>$.p=e2;
	$<assignment>$.v=get_use_variable($<e_id>1);
}
| variable SUB_ASSIGN expr {
	long e2;
	e2=new_param_op_returns_long($<e_id>1,"-",$<e_id>3);
	$<assignment>$.p=e2;
	$<assignment>$.v=get_use_variable($<e_id>1);
}


| variable MUL_ASSIGN expr {
	long e2;
	e2=new_param_op_returns_long($<e_id>1,"*",$<e_id>3);
	$<assignment>$.p=e2;
	$<assignment>$.v=get_use_variable($<e_id>1);
}
| variable DIV_ASSIGN expr {
	long e2;
	e2=new_param_op_returns_long($<e_id>1,"/",$<e_id>3);
	$<assignment>$.p=e2;
	$<assignment>$.v=get_use_variable($<e_id>1);
}



;


variable: IDENTIFIER 					{
		$<e_id>$=new_param_returns_long('V',(void *)mk_use_variable(0    ,0, 0,0,   $<str>1,0));
	}
	| IDENTIFIER '[' expr ']'  			{
		$<e_id>$=new_param_returns_long('V',(void *)mk_use_variable(0,$<e_id>3,0,0,$<str>1,0));
	}    
	| IDENTIFIER '[' expr ']' '[' expr ']' 		{
		$<e_id>$=new_param_returns_long('V',(void *)mk_use_variable(0,$<e_id>3,$<e_id>6,0,$<str>1,0));
	}    
	| IDENTIFIER '[' expr ']' '[' expr ']'  '[' expr ']'	{
		$<e_id>$=new_param_returns_long('V',(void *)mk_use_variable(0,$<e_id>3,$<e_id>6,$<e_id>9,$<str>1,0));
	}    
	| variable '.' IDENTIFIER 		{
		$<e_id>$=new_param_returns_long('V',
			(void *)mk_use_variable(
				$<e_id>1,
				0    ,0,0,
				$<str>3,0));
				}    
	| variable '.' IDENTIFIER '[' expr ']'	{
		$<e_id>$=new_param_returns_long('V',(void *)mk_use_variable(
			$<e_id>1, $<e_id>5, 0,0, $<str>3, 0));
	}    
	| '*' variable  	{
		$<e_id>$=$<e_id>2;
		set_indirection($<e_id>2,1);

	}
	| '&' variable  	{
		set_indirection($<e_id>2,-1);
		$<e_id>$=$<e_id>2;
	}
;



