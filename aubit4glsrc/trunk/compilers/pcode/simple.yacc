%{
#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif

#include "npcode.h"
#include "npcode_defs.h"

int while_cnt=0;
int if_cnt=0;

int while_stack[256];
int while_stack_cnt=0;

int if_stack[256];
int if_stack_cnt=0;

char buff[20];


%}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token AND_OP 
%token OR_OP
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME FUNCTION FGLDATE   FGLDECIMAL FGLMONEY
%type <param> variable
%type <define_var>   param dtype

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%token ON_KEY BEF_ROW AFT_ROW AFTER_INP
%token KW_A_PUSH_LONG 
%token KW_A_PUSH_INT
%token KW_A_PUSH_CHAR
%token KW_A_PUSH_OP
%token KW_A_CHK_ERR
%token KW_A_CLR_ERR
%token KW_A_ERRCHK

%start translation_unit

%union {
	char str[256];
	struct cmd *cmd;
	void *ptr;
	struct param *e;
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


op_define_entry_op_set_group : 
	| define_entry_op_set_group
;

define_entry_op_set_group : 
	define_entry_op_set
	| define_entry_op_set_group define_entry_op_set
;


function_definition :
	 FUNCTION IDENTIFIER '(' fparm  ')' '{'			{ 
		add_function($<str>2,$<define_variables>4,0); } 	func_block 
				{ end_function(); }
	| FUNCTION STATIC IDENTIFIER '(' fparm  ')' '{'		{ add_function($<str>3,$<define_variables>5,1); } 	func_block { end_function(); }
	| FUNCTION STATIC dtype IDENTIFIER '(' fparm  ')' '{'	{ add_function($<str>4,$<define_variables>6,1); } 	func_block { end_function(); }
	| FUNCTION dtype IDENTIFIER '(' fparm  ')' '{'		{ add_function($<str>3,$<define_variables>5,0); } 	func_block { end_function(); }

	| FUNCTION dtype IDENTIFIER '(' VOID  ')' '{'		{ add_function($<str>3,0,0); } 				func_block { end_function(); }
	| FUNCTION STATIC dtype IDENTIFIER '(' VOID  ')' '{'	{ add_function($<str>4,0,1); } 				func_block { end_function(); }
	| FUNCTION STATIC IDENTIFIER '(' VOID  ')' '{'		{ add_function($<str>3,0,1); } 				func_block { end_function(); }

	| FUNCTION dtype IDENTIFIER '('  ')' '{'		{ add_function($<str>3,0,0); } 				func_block { end_function(); }
	| FUNCTION STATIC dtype IDENTIFIER '('  ')' '{'		{ add_function($<str>4,0,1); } 				func_block { end_function(); }
	| FUNCTION STATIC IDENTIFIER '('  ')' '{'		{ add_function($<str>3,0,1); } 				func_block { end_function(); }
;



op_cmds:
	| cmds
;


cmds : cmd
	| cmd cmds
;

cmd :
	/* Nothing... */
	';'
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



fgl_funcs :
	KW_A_PUSH_LONG '(' int_val ')' {
			add_push_long($<e>3->param_u.n);
	}
	| KW_A_PUSH_INT '(' int_val ')' {
			add_push_int($<e>3->param_u.n);
	}
	| KW_A_PUSH_CHAR '(' STRING_LITERAL ')' {
			add_push_char($<str>3);
	}
	| KW_A_PUSH_CHAR '(' variable ')' {
			add_push_charv($<e>3);
	}
	| KW_A_PUSH_CHAR '(' op_expr_list ')' {
		add_call($<str>1,$<e>3);
	}
	| KW_A_CHK_ERR '(' int_val ',' IDENTIFIER ')' {
			add_chk_err($<e>3->param_u.n);
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
			ptr=malloc(sizeof(struct cmd_errchk));
			ptr->line=$<e>3->param_u.n;
			ptr->module_name=add_string($<str>5);
			ptr->modes[0]=$<e>7->param_u.n;
			ptr->modes[1]=$<e>11->param_u.n;
			ptr->modes[2]=$<e>15->param_u.n;
			ptr->modes[3]=$<e>19->param_u.n;
			ptr->modes[4]=$<e>23->param_u.n;
			ptr->actions[0]=add_string($<str>9);
			ptr->actions[1]=add_string($<str>13);
			ptr->actions[2]=add_string($<str>17);
			ptr->actions[3]=add_string($<str>21);
			ptr->actions[4]=add_string($<str>25);
			add_errchk(ptr);
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
					$<define_variables>$=malloc(sizeof(struct define_variables));
					$<define_variables>$->var_len=1;
					$<define_variables>$->var_val=malloc(sizeof(struct variable_element));
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
					v=malloc(sizeof(struct define_variables));
					v->var_len=1;
					v->var_val=malloc(sizeof(struct variable_element));
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
				int x;
				$<define_var>$=$<define_var>1; 
				$<define_var>$->name_id=add_id($<str>2); 
				evaluate_param($<e>4,&x);
				$<define_var>$->i_arr_size[0]=x;
				$<define_var>$->i_arr_size[1]=0;
				$<define_var>$->i_arr_size[2]=0;
	}
	| dtype id_list '[' dtype_int_val ']' '[' dtype_int_val ']' 	{
				int x;
				$<define_var>$=$<define_var>1;
				$<define_var>$->name_id=add_id($<str>2); 
				evaluate_param($<e>4,&x);
				$<define_var>$->i_arr_size[0]=x;
				evaluate_param($<e>4,&x);
				$<define_var>$->i_arr_size[1]=x;
				$<define_var>$->i_arr_size[2]=0;

	}
	| dtype id_list '[' dtype_int_val ']' '[' dtype_int_val ']' '[' dtype_int_val ']'	{
				int x;
				$<define_var>$=$<define_var>1;
				$<define_var>$->name_id=add_id($<str>2); 
				evaluate_param($<e>4,&x);
				$<define_var>$->i_arr_size[0]=x;
				evaluate_param($<e>4,&x);
				$<define_var>$->i_arr_size[1]=x;
				evaluate_param($<e>4,&x);
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

/*
	IDENTIFIER  {
		$<clist>$.char_len=1;
		$<clist>$.ptr=malloc(sizeof(char *)*($<clist>$.char_len));
		$<clist>$.ptr[$<clist>$.char_len-1]=strdup($<str>1);
	}
	| id_list ',' IDENTIFIER {
	        $<clist>$.char_len++;
                $<clist>$.ptr=realloc($<clist>$.ptr,sizeof(char *)*($<clist>$.char_len));
                $<clist>$.ptr[$<clist>$.char_len-1]=strdup($<str>3);

	}
;
*/

define: {end_define();}
	| has_define {end_define();}
;

has_define:
	define_entry_op_set 
	| has_define define_entry_op_set 
;


define_entry_op_set:
		define_entry  ';'
;


op_set : | set {set_master_set($<e>1);} 
;


return: 
	RETURN  {add_return(0);}
	| RETURN expr {add_return($<e>2);}
	;


set: '=' set_internal {
	$<e>$=$<e>2;
}
;


set_internal: 
	  expr {$<e>$=$<e>1;}
	| '{' s_expr_list '}' { $<e>$=$<e>2; }
	| '{' '}' { $<e>$=malloc(sizeof(struct param)); $<e>$->param_type=PARAM_TYPE_EMPTY; }
	;

s_expr_list : set_internal {$<e>$=new_param_list($<e>1);}
	| s_expr_list ',' set_internal {$<e>$=append_param_list($<e>1,$<e>3);}
;



op_define_qualifier :  
	/* */	 {$<i>$=CAT_NORMAL;set_type(0);}
	| STATIC {$<i>$=CAT_STATIC;set_type(1);}
	| EXTERN {$<i>$=CAT_EXTERN;set_type(2);}
;

	


define_entry: op_define_qualifier opd_define_entry  op_set { set_master_type($<i>1); }
	| FUNCTION op_define_qualifier func_def_entry
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
			int x;
				evaluate_param($<e>4,&x);
				as[0]=x;
				as[1]=0;
				as[2]=0;
				add_variable_array(0,$<define_var>1,$<str>2,as,0);
	}
	| dtype IDENTIFIER '[' dtype_int_val ']' '[' dtype_int_val ']'  		{
			long as[3];
			int x;
			evaluate_param($<e>4,&x);
			as[0]=x;
			evaluate_param($<e>7,&x);
			as[1]=x;
			as[2]=0;

			add_variable_array(0,$<define_var>1,$<str>2,as,0);
	}
	| dtype IDENTIFIER '[' dtype_int_val ']' '[' dtype_int_val ']' '[' dtype_int_val ']' 		{
			long as[3];
			int x;
			evaluate_param($<e>4,&x);
			as[0]=x;
			evaluate_param($<e>7,&x);
			as[1]=x;
			evaluate_param($<e>10,&x);
			as[2]=x;
			add_variable_array(0,$<define_var>1,$<str>2,as,0);

	}
;



func_def_entry:
/* Function prototypes - we'll just ignore all of these.... */
	 IDENTIFIER '(' fparm  ')' ';' {strcpy($<str>$,"");}
	| IDENTIFIER '(' VOID  ')' ';' {strcpy($<str>$,"");}
	| dtype IDENTIFIER '('  fparm  ')' ';' {strcpy($<str>$,"");}
	| dtype IDENTIFIER '(' VOID  ')' ';' {strcpy($<str>$,"");}
;


dtype_int_val :
		int_val  {$<e>$=$<e>1;}
		| int_val '+' int_val {
	int n;
	n=$<e>1->param_u.n+ $<e>3->param_u.n;
		A4GL_debug("n=%d\n",n);
		$<e>1->param_u.n=n;
	$<e>$=$<e>1;
	}
;

dtype :
	CHAR  				{$<define_var>$=new_variable_element_string("CHAR");}
	| SHORT 			{$<define_var>$=new_variable_element_string("SHORT");}
	| INT 				{$<define_var>$=new_variable_element_string("LONG");}
	| FGLDATE			{$<define_var>$=new_variable_element_string("FGLDATE");}
	| FGLDECIMAL			{$<define_var>$=new_variable_element_string("FGLDECIMAL");}
	| FGLMONEY			{$<define_var>$=new_variable_element_string("FGLMONEY");}
	| LONG 				{$<define_var>$=new_variable_element_string("LONG");}
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
	| STRUCT struct_has_define  	{ $<define_var>$=new_variable_struct($<define_variables>2); }
;

struct_has_define: 
		IDENTIFIER {$<define_variables>$=(struct define_variables *)add_named_struct($<str>1);}
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
			add_if($<e>3,0,strdup(buff));
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
                        add_if($<e>6,0,strdup(buff));
	}
	assign_common ')' cmd 
	{
			add_set_var($<assignment>9.v,$<assignment>9.p,0);


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
			add_if($<e>4,0,strdup(buff));
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

expr :   or_expr  {$<e>$=$<e>1;}
;


or_expr: and_expr  {$<e>$=$<e>1;}
	| or_expr OR_OP and_expr   { $<e>$=new_param_op($<e>1,$<str>2,$<e>3); }
;

and_expr : other_expr_1  {$<e>$=$<e>1;}
	| and_expr AND_OP other_expr_1  { $<e>$=new_param_op($<e>1,$<str>2,$<e>3); }
;


other_expr_1: expr_1
;

expr_1:
	 op 			{$<e>$=$<e>1; }  
	| int_val 		{$<e>$=$<e>1;}
	| STRING_LITERAL 	{
			char *buff;
			char *buff2;
			buff=strdup($<str>1);
			buff2=&buff[1];
			buff2[strlen(buff2)-1]=0;
			$<e>$=new_param('s',buff2); 
			free(buff);
			}
	| fcall_expr 	 	{$<e>$=$<e>1; }
	| variable 		{$<e>$=$<e>1; }  
	/* | '&' variable 		{$<e>$=$<e>2; } */  /* @fixme - should reference the address not the variable */
	/* | '*' variable 		{$<e>$=$<e>2; } */   /* @fixme - should reference the address not the variable */
	| '(' expr ')'   	{$<e>$=$<e>2; }
	| cast expr     	{$<e>$=$<e>2; }
	| '!' expr 		{$<e>$=new_param_op($<e>2,"NOT",0);}
	| BEF_ROW { $<e>$=new_param('S',"BEF_ROW");}
	| AFT_ROW { $<e>$=new_param('S',"AFT_ROW");}
	| AFTER_INP { $<e>$=new_param('S',"AFTER_INP");}
	| ON_KEY '(' STRING_LITERAL ')' { $<e>$=new_param('K',$<str>3);}


;

cast:
	'(' dtype ')'
	;

op_expr_list : {$<e>$=0; }
	| expr_list  {$<e>$=$<e>1;}

;

expr_list:
	expr {$<e>$=new_param_list($<e>1);
		}
	| expr_list ',' expr {
			$<e>$=append_param_list($<e>1,$<e>3);
	}
;


fcall :
	IDENTIFIER '('  op_expr_list ')' {
		add_call($<str>1,$<e>3);
	}
;

fcall_expr :
	IDENTIFIER '('  op_expr_list ')' {
				$<e>$=new_param_fcall($<str>1,$<e>3);
	}
	| SIZEOF '(' op_expr_list ')' {
				$<e>$=new_param_fcall($<str>1,$<e>3);
	}
;



op: 
	 expr_1 double_operator expr_1 {
		$<e>$=new_param_op($<e>1,$<str>2,$<e>3);
		}
;



/*
and_or_op : expr AND_OP expr { $<e>$=new_param_op($<e>1,$<str>2,$<e>3); }
| expr OR_OP expr { $<e>$=new_param_op($<e>1,$<str>2,$<e>3); }
;

*/


double_operator:
 	 LE_OP 
 	| GE_OP 
 	| EQ_OP 
 	| NE_OP
 	| '+'
 	| '-'
 	| '*'
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
			$<e>$=malloc(sizeof(struct param));
			$<e>$->param_type=PARAM_TYPE_LITERAL_INT;
			sprintf(buff,$<str>1);
			if (buff[0]=='0') {
				if (buff[1]=='x'||buff[1]=='X') {
					$<e>$->param_u.n=strtol(buff,0,16);
				} else {
					$<e>$->param_u.n=strtol(buff,0,8);
				}
			} else {
				$<e>$->param_u.n=atoi($<str>1);
			}
}
;




assign: assign_common {
	add_set_var($<assignment>1.v,$<assignment>1.p,0);
	}
;


assign_common: variable '=' expr {
	struct param *e;
	struct use_variable *v;
	e=$<e>1;
	v=e->param_u.uv;
	$<assignment>$.p=$<e>3;
	$<assignment>$.v=v;

}
| variable INC_OP {
        struct param *e;
        struct use_variable *v;
	struct param *e2;
	struct param *e_1;
        e_1=malloc(sizeof(struct param)); e_1->param_type=PARAM_TYPE_LITERAL_INT; e_1->param_u.n=1;
        e=$<e>1;
        v=e->param_u.uv;
	e2=new_param_op($<e>1,"+",e_1);
	$<assignment>$.p=e2;
	$<assignment>$.v=v;
}
| variable DEC_OP {
        struct param *e;
        struct use_variable *v;
	struct param *e2;
	struct param *e_1;
        e_1=malloc(sizeof(struct param)); e_1->param_type=PARAM_TYPE_LITERAL_INT; e_1->param_u.n=1;
        e=$<e>1;
        v=e->param_u.uv;
	e2=new_param_op($<e>1,"-",e_1);
	$<assignment>$.p=e2;
	$<assignment>$.v=v;
}
| variable ADD_ASSIGN expr {
        struct param *e;
        struct use_variable *v;
	struct param *e2;
        e=$<e>1;
        v=e->param_u.uv;
	e2=new_param_op($<e>1,"+",$<e>3);
	$<assignment>$.p=e2;
	$<assignment>$.v=v;
}
| variable SUB_ASSIGN expr {
        struct param *e;
        struct use_variable *v;
	struct param *e2;
        e=$<e>1;
        v=e->param_u.uv;
	e2=new_param_op($<e>1,"+",$<e>3);
	$<assignment>$.p=e2;
	$<assignment>$.v=v;
}




;


variable: IDENTIFIER 				{$<e>$=new_param('V',(void *)mk_use_variable(0    ,0    ,$<str>1,0)); 
}
	| IDENTIFIER '[' expr ']'  		{$<e>$=new_param('V',(void *)mk_use_variable(0    ,$<e>3,$<str>1,0));}    
	| IDENTIFIER '[' expr ']' '[' expr ']' 		{$<e>$=new_param('V',(void *)mk_use_variable(0    ,$<e>3,$<str>1,0));}    
	| IDENTIFIER '[' expr ']' '[' expr ']'  '[' expr ']'		{$<e>$=new_param('V',(void *)mk_use_variable(0    ,$<e>3,$<str>1,0));}    
	| variable '.' IDENTIFIER 		{
		$<e>$=new_param('V',
	(void *)mk_use_variable(
	$<e>1,
	0    ,
	$<str>3,0));
	}    

	| variable '.' IDENTIFIER '[' expr ']'	{
$<e>$=new_param('V',(void *)mk_use_variable(
$<e>1,
$<e>5,
$<str>3,
0
)
);}    
	| '*' variable  	{
		struct param *p;
		p=$<e>2;
		$<e>$=$<e>2;
		p->param_u.uv->indirection++;

	}
	| '&' variable  	{
		struct param *p;
		p=$<e>2;
		$<e>$=$<e>2;
		p->param_u.uv->indirection--;
	}
;



