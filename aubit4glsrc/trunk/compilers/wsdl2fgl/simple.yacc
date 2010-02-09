%{
#include <stdlib.h>
#include <string.h>
#include "wsdl2fgl.h"

int enum_cnt=0;
%}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token AND_OP 
%token OR_OP
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME  FGLDATE   FGLDECIMAL FGLMONEY FGLSDTIME
%type <define_var>   dtype struct_entry function_call_param struct_def_type_and_name struct_has_define

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID TIME_T
%token STRUCT UNION ENUM ELLIPSIS FUNCTION

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
%type <i> dtype_int_val int_val is_optional

%type <enum_elements> enum_elements
%type <enum_element> enum_element
%type <define_variables> has_struct_entry has_fparam fparam

%start translation_unit
%name-prefix="wsdl2fgl_yy"
%union {
	char str[10000];
	//struct cmd *cmd;
	void *ptr;
	long e_id;
	int i;
	struct variable_element *define_var;
	struct define_variables *define_variables;
	struct enum_element *enum_element;
	struct enum_elements *enum_elements;
}

%%


translation_unit : tu
	| translation_unit tu
;


tu : 
	opd_define_entry  ';' 
	| typedef_decl ';' 
;



typedef_decl:
	TYPEDEF dtype id_element {

                                $2->i_arr_size[0]=0;
                                $2->i_arr_size[1]=0;
                                $2->i_arr_size[2]=0;
                                $2->name="";

				strdup($<str>2);

			make_named_struct ($<str>3, add_variables(NULL, $2),1);
			//printf("Added '%s'\n",$<str>3);
	}
	| STRUCT IDENTIFIER  '{' has_struct_entry '}' {
		//printf("Adding struct %s\n",$<str>2);
		make_named_struct ($<str>2, $4,0);
	}
	| STRUCT TYPE_NAME  '{' has_struct_entry '}' {
		//printf("Adding struct %s\n",$<str>2);
		replace_named_struct ($<str>2, $4);
	}
	| ENUM IDENTIFIER '{' enum_elements '}' {
		make_named_enum ($<str>2, $4);
		enum_cnt=0;
	}
	| TYPEDEF ENUM IDENTIFIER '{' enum_elements '}' {
		make_named_enum ($<str>3, $5);
		enum_cnt=0;
	}
;


enum_elements:
	enum_element {
		$$=append_enum_element(NULL,$1);
	}
	| enum_elements ',' enum_element {
		$$=append_enum_element($1,$3);
	}
;


enum_element : 
	IDENTIFIER {
		$$=new_enum_element($<str>1,enum_cnt++);
	}
	| IDENTIFIER '=' int_val {
		enum_cnt=$3;
		$$=new_enum_element($<str>1,enum_cnt++);
	}
;


fparam: 
		{$$=0;}
	| has_fparam {$$=$1;}
;
	
has_fparam:
	function_call_param  		{
		$$=add_variables(NULL,$1);
	}
	| has_fparam ',' function_call_param 	{ 
		$$=add_variables($1, $3);
	}
		
;

has_struct_entry:
	struct_entry  {
					$$=add_variables(NULL, $<define_var>1);
	}
	| has_struct_entry  struct_entry 	{ 
					$$=add_variables($<define_variables>1, $<define_var>2);
	}
		
;


struct_entry  : struct_def_type_and_name is_optional ';' {
			$<define_var>$=$<define_var>1;
			$$->isOptional=$2;
	}
;

is_optional: 
	 {$$=0;}
	| int_val {$$=$1;}
;


function_call_param : 
	dtype id_element 			{$$=$1; $$->name=strdup($<str>2); }

		/* starlist can be empty - so dont need a dtype on its own */
	| dtype starlist 			{$$=$1; $$->name=strdup($<str>2); }


	/* | dtype  			{$$=$1; $$->name=strdup(""); } */
	| dtype id_element '[' dtype_int_val ']' 	{
				$$=$<define_var>1; 
				$$->i_arr_size[0]=$4;
				$$->i_arr_size[1]=0;
				$$->i_arr_size[2]=0;

				$$->name=strdup($<str>2); 
	}
	| dtype id_element '[' dtype_int_val ']' '[' dtype_int_val ']' 	{
				$$=$<define_var>1;
				$$->name=strdup($<str>2); 
				$$->i_arr_size[0]=$4;
				$$->i_arr_size[1]=$7;
				$$->i_arr_size[2]=0;

	}
	| dtype id_element '[' dtype_int_val ']' '[' dtype_int_val ']' '[' dtype_int_val ']'	{
				$$=$<define_var>1;
				$$->name=strdup($<str>2); 
				$$->i_arr_size[0]=$4;
				$$->i_arr_size[1]=$7;
				$$->i_arr_size[2]=$10;

	}
	| dtype id_element '['  ']' 		{	//struct param *sz;
								$$=$<define_var>1; 
								$$->name=strdup($<str>2);
								$$->i_arr_size[0]=-1;
						}
;


struct_def_type_and_name: /* Used to define the contents of a struct element */
	dtype starlist 			{$$=$1; $$->name=strdup($<str>2); }
	| dtype id_list 			{$<define_var>$=$<define_var>1; $<define_var>$->name=strdup($<str>2); }
	| dtype id_list '[' dtype_int_val ']' 	{
				$$=$<define_var>1; 
				$$->i_arr_size[0]=$4;
				$$->i_arr_size[1]=0;
				$$->i_arr_size[2]=0;

				$<define_var>$->name=strdup($<str>2); 
	}
	| dtype id_list '[' dtype_int_val ']' '[' dtype_int_val ']' 	{
				$$=$<define_var>1;
				$$->name=strdup($<str>2); 
				$$->i_arr_size[0]=$4;
				$$->i_arr_size[1]=$7;
				$$->i_arr_size[2]=0;

	}
	| dtype id_list '[' dtype_int_val ']' '[' dtype_int_val ']' '[' dtype_int_val ']'	{
				$$=$<define_var>1;
				$$->name=strdup($<str>2); 
				$$->i_arr_size[0]=$4;
				$$->i_arr_size[1]=$7;
				$$->i_arr_size[2]=$10;

	}
	| dtype id_list '['  ']' 		{	//struct param *sz;
								$$=$<define_var>1; 
								$$->name=strdup($<str>2);
								$$->i_arr_size[0]=-1;
						}

;


id_element: 
	starlist IDENTIFIER {
		if (strlen($<str>1)) {
		sprintf($<str>$,"%s %s",$<str>1,$<str>2);
		} else {
		strcpy($<str>$,$<str>2);
		}
	}
;

starlist :  {strcpy($<str>$,"");}
	| '*'  {strcpy($<str>$,"*");}
	| starlist '*'  {strcpy($<str>$,$<str>1); strcat($<str>$,"*");}
;


id_list : id_element 
	| id_list ',' id_element {
		sprintf($<str>$,"%s,%s",$<str>1,$<str>3);
	}
;











opd_define_entry:  
/* Variable definitions */
	dtype id_list   					{add_variable(0,$<define_var>1,$<str>2,0);}
	| dtype id_list  '(' fparam  ')' { add_function_definition($<define_var>1,$<str>2,$4); }
	| dtype id_list '['  ']'   				{
			long as[3];
			as[0]=-1;
			as[1]=0;
			as[2]=0;
			add_variable_array(0,$<define_var>1,$<str>2,as,0);
	}
	| dtype id_list '[' dtype_int_val ']'   		{
			long as[3];
				//evaluate_param_i_into_integer($<e_id>4,&x);
				as[0]=$4;
				as[1]=0;
				as[2]=0;
				add_variable_array(0,$<define_var>1,$<str>2,as,0);
	}
	| dtype id_list '[' dtype_int_val ']' '[' dtype_int_val ']'  		{
			long as[3];
			//evaluate_param_i_into_integer($<e_id>4,&x);
			as[0]=$4;
			//evaluate_param_i_into_integer($<e_id>7,&x);
			as[1]=$7;
			as[2]=0;

			add_variable_array(0,$<define_var>1,$<str>2,as,0);
	}
	| dtype id_list '[' dtype_int_val ']' '[' dtype_int_val ']' '[' dtype_int_val ']' 		{
			long as[3];
			//evaluate_param_i_into_integer($<e_id>4,&x);
			as[0]=$4;
			//evaluate_param_i_into_integer($<e_id>7,&x);
			as[1]=$7;
			//evaluate_param_i_into_integer($<e_id>10,&x);
			as[2]=$10;
			add_variable_array(0,$<define_var>1,$<str>2,as,0);

	}
;



dtype_int_val :
		int_val  { 	$$=$1; }
		| int_val '+' int_val { $$=$1+$3; }
;

dtype :
	CHAR  				{$$=new_variable_element_string("char");}
	| SIGNED CHAR  			{$$=new_variable_element_string("char");}
	| UNSIGNED CHAR 		{$$=new_variable_element_string("uchar");}
	| SHORT 			{$$=new_variable_element_string("short");}
	| SHORT INT			{$$=new_variable_element_string("short");}
	| INT 				{$$=new_variable_element_string("long");}
	| UNSIGNED SHORT 		{$$=new_variable_element_string("ushort");}
	| SIGNED SHORT 			{$$=new_variable_element_string("short");}
	| UNSIGNED INT 			{$$=new_variable_element_string("ulong");}
	| SIGNED INT 			{$$=new_variable_element_string("long");}
	| UNSIGNED SHORT INT 		{$$=new_variable_element_string("ushort");}
	| SIGNED SHORT INT 		{$$=new_variable_element_string("short");}
	| LONG 				{$$=new_variable_element_string("long");}
	| TIME_T 			{$$=new_variable_element_string("time_t");}
	| LONG INT 				{$$=new_variable_element_string("long");}

	| UNSIGNED LONG 		{$$=new_variable_element_string("ulong");}
	| UNSIGNED LONG INT		{$$=new_variable_element_string("ulong");}

	| LONG LONG			{$$=new_variable_element_string("longlong");}
	| SIGNED LONG LONG		{$$=new_variable_element_string("longlong");}
	| UNSIGNED LONG LONG		{$$=new_variable_element_string("ulonglong");}

	| LONG LONG INT			{$$=new_variable_element_string("longlong");}
	| SIGNED LONG LONG INT		{$$=new_variable_element_string("longlong");}
	| UNSIGNED LONG LONG INT		{$$=new_variable_element_string("ulonglong");}
	| FLOAT 			{$$=new_variable_element_string("float");}
	| DOUBLE			{$$=new_variable_element_string("double");}
	| VOID				{$$=new_variable_element_string("void");}
	| ENUM TYPE_NAME  		{char buff[2000];sprintf(buff,"ENUM:%s",$<str>2); $$=new_variable_element_string(buff); }
	| STRUCT struct_has_define  	{$$=$2; }
	| TYPE_NAME 			{
						struct define_variables *v;
						struct variable_element *e;
						v=add_named_struct($<str>1);
						e=new_variable_struct(v,$<str>1);
						$<define_var>$=e;
					}
;

struct_has_define: 
		TYPE_NAME { $$=new_variable_struct(add_named_struct($<str>1),$<str>1); }
		| IDENTIFIER {$$=new_variable_struct(add_named_struct($<str>1),$<str>1);}
		|  '{' has_struct_entry '}' {
			/* An anonymous structure... */
			char anonbuff[200];
			static int anonCnt=0;
			sprintf(anonbuff,"anon_struct_%d", anonCnt);
			printf("Structure : %p\n",$<define_variables>2);
			$$==new_variable_struct($<define_variables>2,anonbuff);
			A4GL_debug("BBB : %p from %p\n",$<define_variables>$,$<define_variables>2);
		}  
;




int_constant_val :
		CONSTANT 
			| '+' CONSTANT {sprintf($<str>$,"%s",$<str>2);}
			| '-' CONSTANT {sprintf($<str>$,"-%s",$<str>2);}
			;

	
int_val: int_constant_val {
			char buff[256];
			unsigned long n=0;
			strcpy(buff,$<str>1);
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
			$$=n;
}
;







