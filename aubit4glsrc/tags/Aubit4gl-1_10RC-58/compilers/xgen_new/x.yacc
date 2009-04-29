%{

#define _BISON_SIMPLE_INCL_

#define _NO_FORM_X_H_
#define _NO_WINDOWS_H_

/* FIXME: this should be a4gl_xgen_int.h */
#define NOSTRCPYMAP

// We dont want (or need) the a4gl_expr header - as this is used (indirectly) to generate it !!
#define IGNORE_XGEN_EXPR_HEADERS

#include "a4gl_libaubit4gl.h"
void set_current_parent(char *s) ;
void clr_current_parent(void) ;
char *get_current_parent(void) ;

#define YYDEBUG 1
int lineno=0;
int colno=0;
int enumv=0;
int last_enum=0;
int dbg=1;

#include "elements.h"


#ifdef MOVED
struct s_vname {
	int is_ptr;
	int is_array;
	int is_vararray;
	char *name;
};

struct s_dtype {
	int isvoid;
	int isunion;
	int isstruct;
	int isenum;
	int isunknown;

	char *type;
};




struct s_element {
	struct s_dtype datatype;
	struct s_vname vname;
	char *switch_on;
};

struct s_elements {
	char *union_or_struct_name;
	int nelements;
	struct s_element *elements;
	char *union_switch_on_enum_type;
	char *union_switch_on_enum_name;
};
#endif



static int new_element(struct s_element *element,char *nm,int isunion,int isstruct,int isenum,int isunknown,struct s_vname *vname) {
	memcpy(&element->vname, vname,sizeof(element->vname));
	element->switch_on="";
	element->datatype.isvoid=0;
	element->datatype.isunion=isunion;
	element->datatype.isstruct=isstruct;
	element->datatype.isenum=isenum;
	element->datatype.isunknown=isunknown;
	element->datatype.type=strdup(nm);
}

struct s_elements *all_elements=0;
int nall_elements=0;

struct s_enum  *all_enums=0;
int nall_enums=0;


static void add_struct(char *name, struct s_elements *elements ) {
	nall_elements++;
	all_elements=realloc(all_elements, sizeof(struct s_elements)*nall_elements);
	elements->union_or_struct_name=strdup(name);
	memcpy(&all_elements[nall_elements-1], elements, sizeof(struct s_elements));
}



static int new_void_element(struct s_element *element) {
	memset(&element->vname, 0,sizeof(element->vname));
	element->switch_on="";
	element->datatype.isvoid=1;
	element->datatype.isunion=0;
	element->datatype.isstruct=0;
	element->datatype.isenum=0;
	element->datatype.isunknown=0;
	element->datatype.type="";
}



static void *memdup(void *x, int l) {
void *p;
	p=malloc(l);
	memcpy(p,x,l);
	return p;
}

%}
%start x



%union    {
        char    str[10240];
	/*struct mode mode; */
	struct s_vname vname;
	struct s_dtype dtype;
	struct s_element element;
	struct s_elements elements;
	struct s_enum enums;
	struct s_enum_element enum_element;

}

%token OPEN_BRACE
%token CLOSE_BRACE
%token CONST
%token ENUM
%token COMMA
%token SEMICOLON
%token STRUCT
%token STAR
%token VOID
%token NAMED
%token UNION
%token SWITCH
%token TYPEDEF
%token OPEN_BRACKET
%token CLOSE_BRACKET
%token CASE
%token COLON
%token LESS_THAN
%token GREATER_THAN
%token STRING
%token INT
%token LONG
%token SHORT
%token DOUBLE
%token OPAQUE
%token BOOL
%token CHAR
%token OPEN_SQUARE
%token CLOSE_SQUARE
%token INT_VAL
%token STRING_VAL
%token NUMBER_VAL
%token EQUAL
%token CH
%token HEX_INT_VAL
%token PROGRAM
%token VERSION
%%

x: xset | x xset
;

xset: 	  struct
	| union
	| enum
	| typedef
;


typedef: TYPEDEF STRING NAMED LESS_THAN GREATER_THAN SEMICOLON
	| TYPEDEF STRUCT NAMED STAR NAMED SEMICOLON 
		

;

enum: 	ENUM NAMED {
		last_enum=0;
		} 
	OPEN_BRACE enum_list CLOSE_BRACE SEMICOLON  {
		nall_enums++;
		all_enums=realloc(all_enums, sizeof(struct s_enum)*nall_enums);
		memcpy(&all_enums[nall_enums-1], &$<enums>5, sizeof(struct s_enum));
		all_enums[nall_enums-1].enum_name=strdup($<str>2);
	}
;

enum_list: enum_element  {
			$<enums>$.nelements=1;
			$<enums>$.elements=memdup(&$<enum_element>1,sizeof($<enum_element>1));
	}
	| enum_list COMMA enum_element  {
			int sz;
			memcpy(&$<enums>$,&$<enums>1,sizeof($<enums>$));
			$<enums>$.nelements++;
			sz=$<enums>$.nelements*sizeof($<enum_element>3);
			$<enums>$.elements=realloc($<enums>$.elements,sz);
			memcpy(&$<enums>$.elements[ $<enums>$.nelements-1], &$<enum_element>3, sizeof($<enum_element>3));
	}

;

enum_element: NAMED  {
			$<enum_element>$.element_name=strdup($<str>1);
			$<enum_element>$.val=last_enum;
			last_enum++;
		}
		| NAMED EQUAL INT_VAL  {
			last_enum=atoi($<str>3);
			$<enum_element>$.element_name=strdup($<str>1);
			$<enum_element>$.val=last_enum;
			last_enum++;
		}
;



value: INT_VAL | NAMED | string | NUMBER_VAL | HEX_INT_VAL
;

struct: STRUCT NAMED OPEN_BRACE struct_list CLOSE_BRACE SEMICOLON  {
		memcpy(&$<elements>$, &$<elements>4, sizeof($<elements>$));
		$<elements>$.union_switch_on_enum_type="";
		$<elements>$.union_switch_on_enum_name="";
		add_struct($<str>2, &$<elements>$);
	}
; 


struct_list: 
	element_s SEMICOLON {
			$<elements>$.nelements=1;
			$<elements>$.elements=memdup(&$<element>1,sizeof($<element>1));
	
	}
	| struct_list element_s SEMICOLON {
			$<elements>$.nelements++;
			$<elements>$.elements=realloc($<elements>$.elements,sizeof($<element>2)*$<elements>$.nelements);
			memcpy(&$<elements>$.elements[ $<elements>$.nelements-1],&$<element>2, sizeof($<element>2));
	}
;




vname:    NAMED  					{$<vname>$.is_ptr=0; $<vname>$.is_array=0;  		$<vname>$.is_vararray=0; $<vname>$.name=strdup($<str>1);}
	| NAMED LESS_THAN GREATER_THAN 			{$<vname>$.is_ptr=0; $<vname>$.is_array=0;  		$<vname>$.is_vararray=1; $<vname>$.name=strdup($<str>1);}
	| NAMED OPEN_SQUARE INT_VAL CLOSE_SQUARE 	{$<vname>$.is_ptr=0; $<vname>$.is_array=atoi($<str>3);  $<vname>$.is_vararray=0; $<vname>$.name=strdup($<str>1);}
	| STAR NAMED  					{$<vname>$.is_ptr=1; $<vname>$.is_array=0;  		$<vname>$.is_vararray=0; $<vname>$.name=strdup($<str>2);}
	| STAR NAMED LESS_THAN GREATER_THAN 		{$<vname>$.is_ptr=1; $<vname>$.is_array=0;  		$<vname>$.is_vararray=1; $<vname>$.name=strdup($<str>2);}
	| STAR NAMED OPEN_SQUARE INT_VAL CLOSE_SQUARE 	{$<vname>$.is_ptr=1; $<vname>$.is_array=atoi($<str>4);	$<vname>$.is_vararray=0; $<vname>$.name=strdup($<str>2);}
;


element_s:
	ENUM NAMED vname  	{ new_element(&$<element>$,$<str>2,0,0,1,0,&$<vname>3); }
	| STRUCT NAMED vname	{ new_element(&$<element>$,$<str>2,1,0,0,0,&$<vname>3); }
	| NAMED vname		{ new_element(&$<element>$,$<str>1,0,0,0,1,&$<vname>2); }
	| BOOL vname		{ new_element(&$<element>$,"bool",0,0,0,0,&$<vname>2); }
	| CHAR vname		{ new_element(&$<element>$,"char",0,0,0,0,&$<vname>2); }
	| INT vname 		{ new_element(&$<element>$,"int",0,0,0,0,&$<vname>2); }
	| LONG vname 		{ new_element(&$<element>$,"long",0,0,0,0,&$<vname>2); }
	| SHORT vname 		{ new_element(&$<element>$,"short",0,0,0,0,&$<vname>2); }
	| STRING vname 		{ new_element(&$<element>$,"string",0,0,0,0,&$<vname>2); }
	| OPAQUE vname 		{ new_element(&$<element>$,"opaque",0,0,0,0,&$<vname>2); }
	| DOUBLE vname 		{ new_element(&$<element>$,"double",0,0,0,0,&$<vname>2); }
;


/* we're creating a subset here - we'll only allow enums as switches in our union */

switch_element:
	 ENUM NAMED NAMED   {
		 struct s_vname v;
			v.is_ptr=0;
			v.is_array=0;
			v.is_vararray=0;
			v.name=strdup($<str>3);
		 	new_element(&$<element>$,$<str>2,0,0,1,0,&v); 
		}
;

union: UNION NAMED SWITCH OPEN_BRACKET switch_element CLOSE_BRACKET  OPEN_BRACE union_list CLOSE_BRACE SEMICOLON  {
		memcpy(&$<elements>$, &$<elements>8, sizeof($<elements>$));
		$<elements>$.union_switch_on_enum_type=strdup($<element>5.datatype.type);
		$<elements>$.union_switch_on_enum_name=strdup($<element>5.vname.name);
		add_struct($<str>2, &$<elements>$);
	}
;

union_list: 	union_element {	
			$<elements>$.nelements=1;
			$<elements>$.elements=memdup(&$<element>1,sizeof($<element>1));
		}
		| union_list union_element  {
			struct s_element *e;
			e=&$<element>2;

			$<elements>$.nelements++;
			$<elements>$.elements=realloc($<elements>$.elements,sizeof($<element>2)*$<elements>$.nelements);
			memcpy(&$<elements>$.elements[ $<elements>$.nelements-1],e, sizeof($<element>2));
		}
;



uelement:
	 VOID  	{new_void_element(&$<element>$); }
	| element_s 
;


/* no case's on numerics - must be an enumeration */
union_element:  CASE NAMED COLON  uelement SEMICOLON  {
		memcpy(&$<element>$,&$<element>4,sizeof($<element>$));
		$<element>$.switch_on=strdup($<str>2);
	}

;




string: STRING_VAL ;

/* 
------------------------------------------------------------------------------------------------------------------------------------------------------------
*/








program_name: NAMED;
version_name: NAMED;

hex_int_value: INT_VAL 	| HEX_INT_VAL
;




function_def_list : 
	function_def | function_def_list function_def
;

func_rval	: NAMED | VOID	;
pval 		: NAMED | VOID	;
func_name	: NAMED		;



function_def: 
	func_rval func_name OPEN_BRACKET pval CLOSE_BRACKET EQUAL INT_VAL SEMICOLON
;


;
%%



#include "lex.yy.c"
#
#
#


