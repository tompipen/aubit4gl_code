%{
#define YYDEBUG 1
#ifdef YYPURE
#undef YYPURE
#endif
#define YYPURE 1
/*#define YYLEX_PARAM yystate */
#define YY_DECL int yylex(int yystate)
int tagCaseInsensitive=1;
int ign_kw(int yystate,int kw);
/*
	y.tab.c was generated from screen.yacc using yacc
*/


/*
=====================================================================
		                    Includes
=====================================================================
*/

/* prevent warning for redundant declaration of yyparse / fgl_comp_parse: */
#define _BISON_SIMPLE_INCL_
#define _NO_WINDOWS_H_
#include "a4gl_fcompile_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

int graphics_mode=0;
extern int ignorekw;
extern int lineno;
extern int colno;
extern int scr;
int in_comment;
long fileseek=0;
int ltab=0;
int replicate_bug=0;
int extended_graphics=0;

dll_import struct_form the_form;

extern int newscreen;
extern int fldno;
extern int fstart;
extern int openwith;
extern char currftag[256];
extern char *outputfilename;
extern char *tablist[];
int A4GL_get_dtype_size(void) ;
//int A4GL_get_attr_from_string (char *s);

//struct local_expr_list { listitem *expr_list; int nlist; };


int in_screen_section=0;
int dtype_size=0;
char *rm_dup_quotes(char *s) ;
/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *chk_alias(char *s);
//int A4GL_wcswidth(char *mbs);	/* utf8 */

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

%}
%start form_def

%name-prefix "a4gl_form_yy"
%lex-param {yystate}

%union	  {
	char	str[1024];
	u_expression *expr;
	int intval;
	struct s_column_list *col_list;
	struct s_column column;
	struct local_expr_list *el;
	struct s_at_comments *at_comments;
	struct s_at_if *at_if;
	struct s_at_let *at_let;
	struct s_at_nextfield *at_nextfield;
	struct s_at_call *fcall;
	struct s_at_block *at_block;
	struct u_action *at_action;
	struct s_bef_aft *befact;
	struct s_control_block *control_block;
	struct s_lookups *lookups;
	struct s_lookup *lookup;
	struct  s_layout_attributes  *layout_attrib;
	struct s_layout *layout;
}
%left KW_OR
%left KW_AND
%left KW_NOT
%left IS_NULL IS_NOT_NULL 
%left  GREATERTHAN  LESSTHAN 
%left KW_MINUS KW_PLUS
%left KW_DIVIDE KW_MULTIPLY
%left KW_POWER KW_MOD

%token <str> 
%token CH
%token GRAPH_CH
%token KW_COMPOSITES 
%token INSTRUCTIONS ATTRIBUTES DATABASE BY KW_SCREEN_TITLE KW_SCREEN KW_SIZE OPEN_SQUARE KW_END CLOSE_SQUARE NUMBER_VALUE NAMED  OPEN_BRACE CLOSE_BRACE TITLE NAMED_CASE_SPECIFIC
FORMONLY COMMENT
%token DYNAMIC COLON ATSIGN DOT WITHOUT KW_NULL INPUT TABLES PIPE EQUAL CHAR_VALUE CHARACTER_ENCODING
%token SEMICOLON LOOKUP JOINING LOOKUP_FROM
%token OPEN_BRACKET CLOSE_BRACKET STAR DIVIDE PLUS MINUS RECORD COMMA THROUGH TYPE DELIMITERS
%token KW_CHAR KW_INT KW_DATE KW_FLOAT SMALLFLOAT SMALLINT KW_DECIMAL MONEY DATETIME INTERVAL LIKE
%token BLACK BLUE GREEN CYAN RED MAGENTA WHITE YELLOW NORMAL REVERSE LEFT BOLD BLINK UNDERLINE DIM
%token   AUTONEXT COLOR COMMENTS DEFAULT VALIDATE DISPLAY DOWNSHIFT UPSHIFT FORMAT INCLUDE INVISIBLE NOUPDATE NOENTRY PICTURE PROGRAM REQUIRED  QUERYCLEAR VERIFY WORDWRAP COMPRESS NONCOMPRESS TO  AS UNHIDABLE
%token SERIAL KW_BYTE KW_TEXT VARCHAR SQL_VAR KW_NONSPACE KW_HEADER
%token SQLONLY  WIDGET CONFIG KW_NL
%token COMPARISON LESSTHAN GREATERTHAN KWOR KWAND KWAND1 KWWHERE KWNOT KWBETWEEN KWIN XVAL KWNULLCHK KWNOTNULLCHK
%token YEAR MONTH DAY HOUR MINUTE SECOND FRACTION KW_JUSTIFY KW_CENTER KW_TABINDEX KW_NOT_NULL
/* extensions */
%token LISTBOX BUTTON KW_PANEL DISPLAYONLY ALLOWING  

%token KW_WS KW_TAB
%token KW_MASTER_OF
%token KW_BEFORE KW_AFTER KW_EDITADD KW_EDITUPDATE KW_REMOVE KW_OF
%token KW_ADD KW_UPDATE KW_QUERY KW_ON_ENDING KW_ON_BEGINNING 
%token KW_CALL
%token KW_BELL KW_ABORT KW_LET KW_EXITNOW KW_NEXTFIELD
%token KW_IF KW_THEN KW_ELSE  KW_BEGIN KW_TOTAL KW_RIGHT KW_ZEROFILL
%token KW_USES_EXTENDED SPECIAL_DBNAME
%token KW_ACTION
%token KW_PAGE KW_HBOX KW_VBOX KW_GRID KW_GROUP  KW_TABLE KW_FOLDER KW_STYLE KW_LAYOUT KW_HIDDEN KW_AUTOSIZE KW_NOSHOW KW_NOHIDEMENU
%token KW_TEXTEDIT KW_BUTTONEDIT KW_LABEL KW_EDIT KW_DATEEDIT  KW_SCROLL  KW_IMAGE
%token KW_FONTPITCH KW_FIXED KW_VARIABLE KW_WANTRETURNS KW_WANTNORETURNS KW_WANTTABS
%token KW_AUTOSCALE KW_PIXELWIDTH KW_PIXELHEIGHT KW_BORDER

%token KW_SCROLLBARS_BOTH KW_SCROLLBARS_V KW_SCROLLBARS_H KW_STRETCH_Y KW_STRETCH_BOTH KW_ITEMS KW_VALUEMAX KW_VALUEMIN
%token KW_PROGRESSBAR KW_COMBOBOX OPTIONS KW_BROWSER KW_VALUECHECKED KW_VALUEUNCHECKED KW_CHECKBOX
%token KW_LINEISODD KW_LINEISEVEN

%%

/* rules */
form_def : 
database_section encoding_section screen_or_layout_section op_table_section attribute_section op_instruction_section {
A4GL_check_compiled_form();
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
A4GL_write_form();
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
;

encoding_section :
	{the_form.encoding="";}
	|  CHARACTER_ENCODING  CHAR_VALUE {
		the_form.encoding=strdup(A4GL_strip_quotes($<str>2));
	}
;

database_section :
DATABASE FORMONLY {the_form.dbname=acl_strdup("formonly");
the_form.allowNullInput=1;
}
| DATABASE dbname WITHOUT KW_NULL INPUT {the_form.dbname=acl_strdup($<str>2);
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
the_form.allowNullInput=0;
}
| DATABASE FORMONLY WITHOUT KW_NULL INPUT {the_form.dbname=("formonly");
the_form.allowNullInput=0;
}
| DATABASE dbname {the_form.dbname=acl_strdup($<str>2);
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
the_form.allowNullInput=1;
}
;



named_or_kw_st_pc : 
	NAMED {strcpy($<str>$,$<str>1);A4GL_make_downshift($<str>$); }
	| NAMED_CASE_SPECIFIC {strcpy($<str>$,$<str>1); }
;


named_or_kw_any_pc : 
	NAMED {strcpy($<str>$,$<str>1);A4GL_make_downshift($<str>$); }
	| NAMED_CASE_SPECIFIC {strcpy($<str>$,$<str>1); }
;

named_or_kw_any_tag : 
	NAMED {strcpy($<str>$,$<str>1);
 		if (tagCaseInsensitive) {
                		A4GL_make_downshift($<str>$);
        		}
	}
	| NAMED_CASE_SPECIFIC {strcpy($<str>$,$<str>1); }
;


dbname : 
	SPECIAL_DBNAME {strcpy($<str>$,acl_getenv("DBNAME"));} 
	| SPECIAL_DBNAME ATSIGN named_or_kw_any_pc  {strcpy($<str>$,acl_getenv("DBNAME"));} 
	| named_or_kw_st_pc 
	| named_or_kw_st_pc ATSIGN named_or_kw_any_pc {SPRINTF2($<str>$,"%s@%s",$<str>1,$<str>3);}
;


screen_or_layout_section : 
	screen_section  {
			the_form.layout=NULL;
			the_form.layout_attrib=NULL;
	}
	| layout_section {
			the_form.layout=$<layout>1;
	}
;


vbox_section:
	KW_VBOX opt_layout_ident layout_attributes op_layout_items KW_END {
			$<layout>$=$<layout>4;
			$<layout>$->id=strdup($<str>2);
			$<layout>$->attrib=$<layout_attrib>3;
			$<layout>$->layout_type=LAYOUT_VBOX;
	}
;


hbox_section:
	KW_HBOX opt_layout_ident layout_attributes op_layout_items KW_END {
			$<layout>$=$<layout>4;
			$<layout>$->id=strdup($<str>2);
			$<layout>$->attrib=$<layout_attrib>3;
			$<layout>$->layout_type=LAYOUT_HBOX;
	}
;

group_section:
	KW_GROUP opt_layout_ident layout_attributes op_layout_items KW_END {
			$<layout>$=$<layout>4;
			$<layout>$->id=strdup($<str>2);
			$<layout>$->attrib=$<layout_attrib>3;
			$<layout>$->layout_type=LAYOUT_GROUP;
			/* only one item in a group */
			if ( $<layout>$->children.children_len!=1) {
				yyerror("A GROUP must contain 1 and only 1 child item");
			}
	}
;

folder_section:
	KW_FOLDER opt_layout_ident layout_attributes pages KW_END {
		 $<layout>$=$<layout>4;
		 $<layout>$->id=strdup($<str>2);
		 $<layout>$->attrib=$<layout_attrib>3;
	}
;


pages: 	page {
		$<layout>$=malloc(sizeof(struct s_layout));
		$<layout>$->layout_type=LAYOUT_FOLDER;
		$<layout>$->id="NOTSET";
		$<layout>$->attrib=0;
		$<layout>$->screen_no=-1;
		$<layout>$->children.children_val=0;
		$<layout>$->children.children_len=0;
		add_child($<layout>$, $<layout>1);
	}
	| pages page {
		add_child($<layout>1, $<layout>2);
		$<layout>$=$<layout>1;
	}
;


page: 
	KW_PAGE opt_layout_ident layout_attributes op_layout_items KW_END  {
			$<layout>$=$<layout>4;
			$<layout>$->id=strdup($<str>2);
			$<layout>$->attrib=$<layout_attrib>3;
			$<layout>$->layout_type=LAYOUT_PAGE;
			if ( $<layout>$->children.children_len!=1) {
				yyerror("A PAGE must contain 1 and only 1 child item");
			}
	}

;

opt_layout_ident: 
	{strcpy($<str>$,"");}
	 |  named_or_kw_any_pc {
		{strcpy($<str>$,$<str>1);}
	}
;

grid_section:
	KW_GRID 
		{ in_screen_section=1; colno=0;   lineno=0; scr++; if (scr>1) newscreen=1; sprintf($<str>$,"%d", scr); }
	opt_layout_ident   layout_attributes
        OPEN_BRACE 
		{ ignorekw=1; lineno=0; }
        screen_layout
        CLOSE_BRACE
		{ignorekw=0; in_screen_section=0;}
	KW_END {
		$<layout>$=malloc(sizeof(struct s_layout));
		$<layout>$->layout_type=LAYOUT_GRID;
		$<layout>$->id=strdup($<str>3);
		$<layout>$->attrib=$<layout_attrib>4;
		$<layout>$->screen_no=atol($<str>2);
		$<layout>$->children.children_val=0;
		$<layout>$->children.children_len=0;
	}
;



table_section:
	KW_TABLE
		{ in_screen_section=1; colno=0; lineno=0; scr++; if (scr>1) newscreen=1;  sprintf($<str>$,"%d", scr);}
 	opt_layout_ident   layout_attributes
        OPEN_BRACE 
		{ ignorekw=1; lineno=0; }
        screen_layout
        CLOSE_BRACE
		{ignorekw=0; in_screen_section=0;}
	KW_END {
		//strcpy($<str>$,$<str>2);
		$<layout>$=malloc(sizeof(struct s_layout));
		$<layout>$->layout_type=LAYOUT_TABLE;
		$<layout>$->id=strdup($<str>3);
		$<layout>$->attrib=$<layout_attrib>4;
		$<layout>$->screen_no=atol($<str>2);
		$<layout>$->children.children_val=0;
		$<layout>$->children.children_len=0;
	}
;


layout_attributes:  {
		$<layout_attrib>$=0;
		}
	| OPEN_BRACKET { new_layout_attribs(); } layout_attribute_list CLOSE_BRACKET {
		$<layout_attrib>$=get_layout_attrib();
	}
;

layout_attribute: 
	KW_STYLE EQUAL CHAR_VALUE {
		add_str_layout_attrib(FA_S_STYLE, $<str>3);
	}
	| KW_HIDDEN {
		add_bool_layout_attrib(FA_B_HIDDEN);
	}
	| KW_NOSHOW {
		add_bool_layout_attrib(FA_B_NOSHOW);
	}
	| KW_NOHIDEMENU {
		add_bool_layout_attrib(FA_B_NOHIDEMENU);
	}
	| KW_AUTOSIZE {
		add_bool_layout_attrib(FA_B_AUTOSIZE);
	}
	| KW_TEXT EQUAL CHAR_VALUE {
		add_str_layout_attrib(FA_S_TEXT, $<str>3); 
	}
	| KW_ACTION EQUAL NAMED {
		add_str_layout_attrib(FA_S_ACTION, $<str>3); 
	}
	| KW_BORDER {
		add_bool_layout_attrib(FA_B_BORDER);
	}
	| KW_PIXELHEIGHT EQUAL NUMBER_VALUE { add_str_layout_attrib(FA_S_PIXELHEIGHT,$<str>3); }
	| KW_PIXELWIDTH EQUAL NUMBER_VALUE { add_str_layout_attrib(FA_S_PIXELWIDTH,$<str>3); }
;

layout_attribute_list:
	layout_attribute 
	| layout_attribute_list layout_attribute
	| layout_attribute_list COMMA layout_attribute
;


op_layout_items: {
		$<layout>$=malloc(sizeof(struct s_layout));
		                $<layout>$->layout_type=LAYOUT_NOTSET;
                		$<layout>$->id="NOTSET";
                		$<layout>$->attrib=0;
                		$<layout>$->screen_no=-1;
                		$<layout>$->children.children_val=0;
                		$<layout>$->children.children_len=0;
		}
	| layout_items {$<layout>$=$<layout>1;}

;


layout_items:
	layout_container {
		$<layout>$=malloc(sizeof(struct s_layout));
		$<layout>$->layout_type=LAYOUT_NOTSET;
		$<layout>$->id="NOTSET";
		$<layout>$->attrib=0;
		$<layout>$->screen_no=-1;
		$<layout>$->children.children_val=0;
		$<layout>$->children.children_len=0;
		add_child($<layout>$, $<layout>1);
	}
	| layout_items layout_container {
		add_child($<layout>1, $<layout>2);
		$<layout>$=$<layout>1;
	}
;

layout_container:
	vbox_section
		{ $<layout>$=$<layout>1; }
	| hbox_section
		{ $<layout>$=$<layout>1;}
	| group_section
		{ $<layout>$=$<layout>1;}
	| folder_section
		{ $<layout>$=$<layout>1;}
	| grid_section
		{ $<layout>$=$<layout>1;}
	| table_section
		{ $<layout>$=$<layout>1;}
;

layout_section:
	KW_LAYOUT layout_attributes { 
		the_form.layout_attrib=$<layout_attrib>2;
	} layout_container op_end {
		$<layout>$=$<layout>4;
	}
;




screen_section : screens_section | screen_section screens_section ;

screens_section :
	KW_SCREEN {
	char buff[256];
	sprintf(buff,"Screen %d", the_form.snames.snames_len);
		the_form.snames.snames_len++;the_form.snames.snames_val=
			realloc(the_form.snames.snames_val,
				(the_form.snames.snames_len)*
					sizeof(struct screen_name));

		the_form.snames.snames_val[the_form.snames.snames_len-1].name=
				acl_strdup(buff);

		in_screen_section=1; 
	}  screens_rest
| KW_SCREEN_TITLE CHAR_VALUE {
	char buff[256];
	char *ptr;
	the_form.snames.snames_len++;the_form.snames.snames_val=
		realloc(the_form.snames.snames_val, 
			(the_form.snames.snames_len)*
				sizeof(struct screen_name));
		sprintf(buff,"%s", $<str>2);
		ptr=buff;
		ptr++;
		ptr[strlen(ptr)-1]=0;

		the_form.snames.snames_val[
			the_form.snames.snames_len-1].name =acl_strdup(ptr);

	in_screen_section=1; 
	}  screens_rest
;

screens_rest: op_size { lineno=0; scr++; if (scr>1) newscreen=1; } 
	op_extended
	OPEN_BRACE { ignorekw=1; lineno=0; } 
	screen_layout 
	CLOSE_BRACE 
	{ ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;} 
	op_end 
;


op_extended :  | KW_USES_EXTENDED { extended_graphics=1; }
;
	


op_size :  
| KW_SIZE NUMBER_VALUE 
| KW_SIZE NUMBER_VALUE BY NUMBER_VALUE {
	int c;
	int l;
	if (A4GL_isyes(acl_getenv("USE_FORM_SIZE"))) {
		c=atoi($<str>4);
		l=atoi($<str>2);
        	if (c>the_form.maxcol) the_form.maxcol=c;
        	if (l>the_form.maxline) the_form.maxline=l;
	}
}
;

op_end : 
| KW_END
;


screen_layout : 
screen_element 
| screen_layout screen_element
;

some_text: NAMED {
	int a;
	static char buff[256];
	strcpy(buff,$<str>1);
	if (A4GL_isyes(acl_getenv("SPACESCORE"))) {
		for (a=0;a<strlen(buff);a++) {
			if (buff[a]=='_') buff[a]=' ';
		}
	}
	strcpy($<str>$,buff);
} 
	
;

screen_element : 
some_text {
        //printf("%s %d %d %d %d %d %s\n","_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	if (lineno) {
        //A4GL_add_field("_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	//colno+=strlen($<str>1);
        A4GL_add_field("_label",colno+1,lineno,A4GL_wcswidth($<str>1),scr,0,$<str>1); /* utf8 */
	colno+=A4GL_wcswidth($<str>1);		/* utf8 */
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}
| field  { ltab=0; }
| KW_TAB {
	if (colno==0&&replicate_bug) {colno=4; ltab=1;}
	else {
		if (colno==4&&replicate_bug) {colno=16;}
		else {
			colno++;
			while ((colno%8)!=0) {colno++;}
		}
		ltab=0;
	}
}
| GRAPH_CH {
	char buff[256];
	if (lineno) {
	sprintf(buff,"\n%s",$<str>1);
	A4GL_add_field("_label",colno+1,lineno,1,scr,0,$<str>1);
	colno++;
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
} 
| PIPE {
	char buff[256];
	if (lineno) {
	strcpy(buff,$<str>1);
	A4GL_add_field("_label",colno+1,lineno,1,scr,0,$<str>1);
	colno+=strlen($<str>1);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}


| CHAR_VALUE {
	if (lineno) {
	//A4GL_add_field("_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	//colno+=strlen($<str>1);
	A4GL_add_field("_label",colno+1,lineno,A4GL_wcswidth($<str>1),scr,0,$<str>1);	/* utf8 */
	colno+=A4GL_wcswidth($<str>1);	/* utf8 */
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
} 

| ch_list {
	if (lineno) {
	//A4GL_add_field("_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	//colno+=strlen($<str>1);
	A4GL_add_field("_label",colno+1,lineno,A4GL_wcswidth($<str>1),scr,0,$<str>1);	/* utf8 */
	colno+=A4GL_wcswidth($<str>1);	/* utf8 */
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
}  
| KW_WS {
	if (ltab==1) colno=8;
	ltab=0;
	colno++;
}
| KW_NL {colno=0;lineno++;
	ltab=0;
}
| KW_NONSPACE  {
	ltab=0;
}



;

ch_list: CH {strcpy($<str>$,$<str>1);}
	| ch_list CH {sprintf($<str>$,"%s%s",$<str>1,$<str>2);}
;


field : 
OPEN_SQUARE 
{
	colno++;
	fstart=colno;
	openwith='[';
}
field_element 
CLOSE_SQUARE
{
	colno++;
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (openwith=='[')
		A4GL_add_field($<str>3,fstart+1,lineno,colno-fstart-1,scr,3,"");
	else
		A4GL_add_field($<str>3,fstart+1,lineno,colno-fstart-1,scr,2,"");

       fstart=-1;

}


;


field_element : field_tag_name_scr {
			strcpy($<str>$,$<str>1);
			} 
		| field_element PIPE  {
				/* field elements = name x y width screen_no endswith'|' */
				colno++;
				if (colno>the_form.maxcol) the_form.maxcol=colno; 
				if (lineno>the_form.maxline) the_form.maxline=lineno;
				if (openwith=='[')
					A4GL_add_field($<str>1,fstart+1,lineno,colno-fstart-1,scr,1,"");
				else
					A4GL_add_field($<str>1,fstart+1,lineno,colno-fstart-1,scr,0,"");
				fstart=colno;
				openwith='|';
			} field_tag_name_scr {
				strcpy($<str>$,$<str>4);
			}
;



op_table_section : 
| TABLES table_def_list  op_end;

table_def_list : 
table_def 
| table_def_list table_def
| table_def_list COMMA table_def
;

table_def : named_or_kw_any_pc opequal { 
clr_status();
A4GL_add_table($<str>2,$<str>1); 
err_on_status();
} 
;

opequal :  {strcpy($<str>$,"");}
| EQUAL table_qualifier  {strcpy($<str>$,$<str>2); }
;

table_qualifier : named_or_kw_any_pc {sprintf($<str>$,"%s", $<str>1);}
| named_or_kw_any_pc COLON named_or_kw_any_pc {sprintf($<str>$,"%s%s%s", $<str>1, $<str>2, $<str>3);}
| named_or_kw_any_pc ATSIGN named_or_kw_any_pc
        {sprintf($<str>$,"%s%s%s", $<str>1, $<str>2, $<str>3);}
| named_or_kw_any_pc ATSIGN named_or_kw_any_pc COLON named_or_kw_any_pc {sprintf($<str>$,"%s%s%s%s%s", $<str>1, $<str>2, $<str>3,$<str>4,$<str>5);}
| named_or_kw_any_pc DOT named_or_kw_any_pc {sprintf($<str>$,"%s%s%s", $<str>1, $<str>2, $<str>3);}
| CHAR_VALUE DOT named_or_kw_any_pc
;



attribute_section :  
	ATTRIBUTES field_tag_list op_end
;

field_tag_list : 
field_tag | field_tag_list field_tag
;


op_field_tag_type:
	{strcpy($<str>$,"Edit");}
	| KW_EDIT {strcpy($<str>$,"Edit");}
	| KW_TEXTEDIT {strcpy($<str>$,"TextEdit");}
	| KW_LABEL {strcpy($<str>$,"Label");}
	| KW_DATEEDIT {strcpy($<str>$,"DateEdit");}
	| KW_BUTTONEDIT {strcpy($<str>$,"ButtonEdit");}
	| BUTTON {strcpy($<str>$,"Button");}
	| KW_IMAGE {strcpy($<str>$,"Image");}
	| KW_PROGRESSBAR {strcpy($<str>$,"ProgressBar");} 
	| KW_COMBOBOX {strcpy($<str>$,"ComboBox");} 
	| KW_CHECKBOX {strcpy($<str>$,"CheckBox");} 
	| KW_BROWSER {strcpy($<str>$,"Browser");} 
;


field_tag :  op_field_tag_type
		field_tag_name {
			if (tagCaseInsensitive) {
				A4GL_make_downshift($<str>2);
			}
			strcpy(currftag,$<str>2);
			fldno=A4GL_find_field($<str>2);
		} 
		fpart_list 
		SEMICOLON {
			if (strcmp($<str>1,"Edit")!=0) {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();

				if (A4GL_has_str_attribute(fld,FA_S_WIDGET)) {
					yyerror("Field already has a widget");
				} else {
					A4GL_add_str_attr(fld,FA_S_WIDGETTYPE,$<str>1);
				}
			}
			if (the_form.allowNullInput==0) {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
				if (!A4GL_has_bool_attribute(fld,FA_B_NOTNULL)) {
					A4GL_add_bool_attr(fld,FA_B_NOTNULL);
				}
			}
		}
;

fpart_list : 
fpart 
| fpart_list fpart 
| fpart_list SEMICOLON fpart
;

eq_or_colon: EQUAL | COLON 
;
fpart : 
eq_or_colon { 
	A4GL_init_fld();
}
field_type op_att 
{
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	//if (fld->tabname) {
		//A4GL_make_downshift(fld->tabname);
	//}
	//A4GL_make_downshift(fld->colname);
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
#ifdef DEBUG
	A4GL_debug("add color %d\n",FA_C_WHITE);
#endif
}
op_field_desc
{
	int cnt;
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	if (A4GL_has_str_attribute(fld,FA_S_FORMAT)) {
		int dtype;
		dtype=fld->datatype & DTYPE_MASK;

		if (dtype!=DTYPE_INT  &&
		    dtype!=DTYPE_SMINT  &&
		    dtype!=DTYPE_SERIAL  &&
		    dtype!=DTYPE_FLOAT  &&
		    dtype!=DTYPE_SMFLOAT  &&
		    dtype!=DTYPE_DATE  &&
		    dtype!=DTYPE_DECIMAL  &&
		    dtype!=DTYPE_MONEY) {
		printf("dtype=%d col=%s\n",dtype,fld->colname);
	        		yyerror("A FORMAT cannot be applied to this fields because of the datatype");
	        		YYERROR;
		}
	} else {
		char *format;
		cnt=0;
		while (1) {
			if (strcmp(the_form.dbname,"formonly")==0) {
				format=0;
			} else {
				format=A4GL_get_syscolatt(fld->tabname, fld->colname,cnt++,"def_format");
			}
			if (format==0) break;
			if (format && strlen(format)) {
				// Looks like we've found one in syscolatt instead...
				A4GL_trim(format);
				if (strlen(format)) {
					A4GL_add_str_attr(fld,FA_S_FORMAT,format);
				}
				break;
			} else {
				break;
			}
		}
	}
	
	cnt=0;
	if (strcmp(the_form.dbname,"formonly")!=0) {
	while (1) {
		char *att_color;
		char *att_inverse;
		char *att_underline;
		char *att_blink;
		char *att_left;
		char *att_condition;
		int attr=0;
		int used=0;

		// format has already been handled...
		att_color=A4GL_get_syscolatt(fld->tabname, fld->colname,cnt,"color");

		if (att_color) {
			used++;
			att_color=strdup(att_color);
			A4GL_trim(att_color);
			if (strlen(att_color)>0) {

		switch (att_color[0]) {
			/*
			0: WHITE/ NORMAL
			1: YELLOW/BOLD
			2: MAGENTA/BOLD
			3: RED/BOLD
			4: CYAN/DIM
			5: GREEN/DIM
			6: BLUE/DIM
			7: BLACK/DIM
			*/
			case '0': attr+=7; break;
			case '1': attr+=3; break;
			case '2': attr+=5; break;
			case '3': attr+=1; break;
			case '4': attr+=6; break;
			case '5': attr+=2; break;
			case '6': attr+=4; break;
			case '7': attr+=0; break;
		}
				
			}
			free(att_color);
		}

		att_inverse=A4GL_get_syscolatt(fld->tabname, fld->colname,cnt,"inverse");
		if (att_inverse) {
			used++;
			att_inverse=strdup(att_inverse);
			A4GL_trim(att_inverse);
			if (strlen(att_inverse)) {
				if (strcmp(att_inverse,"y")==0) {
					attr+=A4GL_get_attr_from_string("REVERSE");
				}
			}
		}

		att_underline=A4GL_get_syscolatt(fld->tabname, fld->colname,cnt,"underline");
		if (att_underline) {
			used++;
			att_underline=strdup(att_underline);
			A4GL_trim(att_underline);
			if (strlen(att_underline)) {
				if (strcmp(att_underline,"y")==0) {
					attr+=A4GL_get_attr_from_string("UNDERLINE");
				}
			}
		}

		att_blink=A4GL_get_syscolatt(fld->tabname, fld->colname,cnt,"blink");
		if (att_blink) {
			used++;
			att_blink=strdup(att_blink);
			if (strlen(att_blink)) {
				if (strcmp(att_blink,"y")==0) {
					attr+=A4GL_get_attr_from_string("BLINK");
				}
			}
		}

		att_left=A4GL_get_syscolatt(fld->tabname, fld->colname,cnt,"left");
		if (att_left) {
			used++;
			att_left=strdup(att_left);
			A4GL_trim(att_left);
			if (strlen(att_left)) {
				if (strcmp(att_left,"y")==0) {
					attr+=A4GL_get_attr_from_string("LEFT");
				}
			}

		}

		att_condition=A4GL_get_syscolatt(fld->tabname, fld->colname,cnt,"condition");
		if (att_condition) {
			used++;
			att_condition=strdup(att_condition);
			A4GL_trim(att_condition);
			if (strlen(att_condition)) {
				//printf("%s\n", att_condition);
				fprintf(stderr, "Conditions in upscol are not handled yet (%s)\n",att_condition);
			}
		}
		if (!used) {
				break;
		}

		if (attr) {
		        int a;
                        struct  u_expression *e_true;
                        e_true=create_int_expr(1);
                        fld->colours.colours_len++;
                        a=fld->colours.colours_len;
                        fld->colours.colours_val=realloc(fld->colours.colours_val,a*sizeof(struct colours ) );
                        fld->colours.colours_val[a-1].colour=attr;
                        fld->colours.colours_val[a-1].whereexpr=e_true;

		}

		cnt++;
	}
	}
	



	if (fld->datatype==90&&!(A4GL_has_str_attribute(fld,FA_S_DEFAULT)))
	{
	        extern FILE *a4gl_form_yyin;

#ifdef DEBUG
			A4GL_debug("Currpos = %ld\n",ftell(a4gl_form_yyin));
#endif
	        yyerror("A button must have a default value for its caption");
	        YYERROR;
	}


	if (!(A4GL_has_str_attribute(fld,FA_S_PICTURE)) && strcmp(the_form.dbname,"formonly")!=0 ) {
		char *p;
		p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"PICTURE");
		if (p) {
			// Theres a picture in syscolval - but nothing in the form - use the syscolval one...
			A4GL_add_str_attr(fld,FA_S_PICTURE,p);
		}
	}

		// COMMENTS
		// DEFAULT
		// PICTURE

		// INCLUDE

		// AUTONEXT
		// SHIFT
		// VERIFY


	if (strcmp(the_form.dbname,"formonly")!=0 ) {
		// String ...
		if (!(A4GL_has_str_attribute(fld,FA_S_PICTURE))) {
			char *p;
			p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"PICTURE");
			if (p) {
				// Theres a picture in syscolval - but nothing in the form - use the syscolval one...
				A4GL_add_str_attr(fld,FA_S_PICTURE,p);
			}
		}

		if (!(A4GL_has_str_attribute(fld,FA_S_COMMENTS))) {
			char *p;
			p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"COMMENTS");
			if (p) {
				A4GL_add_str_attr(fld,FA_S_COMMENTS,p);
			}
		}

		if (!(A4GL_has_str_attribute(fld,FA_S_DEFAULT))) {
			char *p;
			p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"DEFAULT");
			if (p) {
				A4GL_add_str_attr(fld,FA_S_DEFAULT,p);
			}
		}

		if (!(A4GL_has_str_attribute(fld,FA_S_INCLUDE))) {
			char *p;
			p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"INCLUDE");
			if (p) {
				p=process_include(p);
				A4GL_add_str_attr(fld,FA_S_INCLUDE,p);
			}
		}

	

		// Booleans...
		if (!(A4GL_has_bool_attribute(fld,FA_B_AUTONEXT))) {
			char *p;
			p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"AUTONEXT");
			if (p) {
				// Theres a picture in syscolval - but nothing in the form - use the syscolval one...
				A4GL_add_bool_attr(fld,FA_B_AUTONEXT);
			}
		}

		if (!(A4GL_has_bool_attribute(fld,FA_B_VERIFY))) {
			char *p;
			p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"VERIFY");
			if (p) {
				// Theres a picture in syscolval - but nothing in the form - use the syscolval one...
				A4GL_add_bool_attr(fld,FA_B_VERIFY);
			}
		}

		if (!A4GL_has_bool_attribute(fld,FA_B_UPSHIFT)  &&! A4GL_has_bool_attribute(fld,FA_B_DOWNSHIFT)) {
			char *p;
			p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"SHIFT");
			if (p) {
				if (strcmp(p,"UP")==0) {
					A4GL_add_bool_attr(fld,FA_B_UPSHIFT);
				}
				if (strcmp(p,"DOWN")==0) {
					A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT);
				}
			}
		}

	}






	a4gl_status=0;
	A4GL_set_field(currftag,fld);
	if (a4gl_status!=0) {
		yyerror(A4GL_get_fcompile_err());
	}


	if ((fld->datatype&256)==256) {
			fld->datatype-=256;
			if (!A4GL_has_bool_attribute(fld,FA_B_NOTNULL)) {
					A4GL_add_bool_attr(fld,FA_B_NOTNULL);
				}
			
			if (!A4GL_has_bool_attribute(fld,FA_B_REQUIRED)) {
				switch (fld->datatype&DTYPE_MASK) {
					case DTYPE_CHAR:
					case DTYPE_NCHAR:
					case DTYPE_VCHAR:
					case DTYPE_NVCHAR:
						// Characters can be spaces - everything else would have to be null
						// but nulls are not allowed - so it must be 'required' as well
						if (A4GL_isyes(acl_getenv("SPCNOTNULLCHAR"))) {
							break;
						}
						// drop through...
					default : 
						if (!A4GL_has_bool_attribute(fld,FA_B_NOENTRY)) {
							// Forcing 'REQUIRED' on a 'NOENTRY' is just dumb...
							A4GL_add_bool_attr(fld,FA_B_REQUIRED);
						}
						break;
				}
			}
	}
}
;



op_att : 
| OPEN_SQUARE NUMBER_VALUE CLOSE_SQUARE {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi($<str>2);
} 
| 
OPEN_SQUARE NUMBER_VALUE COMMA NUMBER_VALUE CLOSE_SQUARE {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->subscripts[0]=atoi($<str>2);
	fld->subscripts[1]=atoi($<str>4);
};



field_datatype_null : 
		field_datatype KWNOT KW_NULL 	{ sprintf($<str>$,"%d",atoi($<str>1)+256); }
		| field_datatype  		{ strcpy($<str>$,$<str>1); }
;

field_datatype : {strcpy($<str>$,"0"); dtype_size=0;}
	| 	TYPE LIKE named_or_kw_any_pc DOT named_or_kw_any_pc {
			sprintf($<str>$,"%d",A4GLF_getdatatype_fcompile($<str>5,$<str>3,1));
        		dtype_size=A4GL_get_dtype_size();
		}
	| 	TYPE LIKE named_or_kw_any_pc {
			sprintf($<str>$,"%d",A4GLF_getdatatype_fcompile($<str>3,"",1));
        		dtype_size=A4GL_get_dtype_size();
		}
	| 	TYPE datatype {
			strcpy($<str>$,$<str>2);
			
		}
;

field_type : FORMONLY DOT field_name field_datatype_null {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->tabname=acl_strdup("formonly");
	fld->colname=acl_strdup($<str>3);
        fld->datatype=atoi($<str>4)&0xff;
	if (atoi($<str>4)&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi($<str>4)&0xff;
        fld->dtype_size=dtype_size;
}
| DISPLAYONLY field_datatype_null {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	static int xdo=0;
	char buff[256];
	sprintf(buff,"_do_%d",xdo++);
	fld->tabname=acl_strdup("formonly");
	fld->colname=acl_strdup(buff);
        fld->datatype=atoi($<str>2)&0xff;
	if (atoi($<str>2)&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi($<str>2)&0xff;
        fld->dtype_size=dtype_size;
}
| DISPLAYONLY ALLOWING INPUT field_datatype_null {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	static int di=0;
	char buff[256];
	sprintf(buff,"_di_%d",di++);
	fld->tabname=acl_strdup("formonly");
	fld->colname=acl_strdup(buff);
        fld->datatype=atoi($<str>4)&0xff;
	if (atoi($<str>4)&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi($<str>4)&0xff;
        fld->dtype_size=dtype_size;
}
| named_or_kw_any_pc DOT named_or_kw_any_pc {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->tabname=acl_strdup($<str>1); 
	fld->colname=acl_strdup($<str>3);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname,0);
        fld->dtype_size=A4GL_get_dtype_size();
}
| named_or_kw_any_pc {
	struct struct_scr_field *fld;
	char *tab;
	fld=A4GL_get_fld();
	tab=fcompile_find_table($<str>1);
	if (tab) {
		fld->tabname=strdup(fcompile_find_table($<str>1));
	} else {
		fld->tabname=0;
	}
	fld->colname=acl_strdup($<str>1);
	if (fld->tabname!=0) {
		fld->not_null=0;
        	fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname,0);
        	fld->dtype_size=A4GL_get_dtype_size();
	} else {
		fld->tabname=acl_strdup("-");
        	fld->dtype_size=1;
		fld->datatype=DTYPE_CHAR;
	}
}

| STAR named_or_kw_any_pc DOT named_or_kw_any_pc {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->tabname=acl_strdup($<str>2); 
	fld->colname=acl_strdup($<str>4);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname,0);
        fld->dtype_size=A4GL_get_dtype_size();
}
| STAR named_or_kw_any_pc {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	fld->colname=acl_strdup($<str>2);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"",0);
	fld->tabname=A4GL_get_found_in_tab();
        fld->dtype_size=A4GL_get_dtype_size();
}
;


op_lu_ft_eq_c: {
		$<lookups>$=malloc(sizeof(s_lookups));
		$<lookups>$->lookups.lookups_len=0;
		$<lookups>$->lookups.lookups_val=0;
	}
	| lu_ft_eq_c {
		$<lookups>$=$<lookups>1;
		}
;

lu_ft_eq_c:
	lu_ft_eq_c_i {
		$<lookups>$=malloc(sizeof(s_lookups));
		$<lookups>$->lookups.lookups_len=0;
		$<lookups>$->lookups.lookups_val=0;

		$<lookups>$->lookups.lookups_len++;
		$<lookups>$->lookups.lookups_val=realloc($<lookups>$->lookups.lookups_val, sizeof($<lookups>$->lookups.lookups_val[0])*$<lookups>$->lookups.lookups_len);
		$<lookups>$->lookups.lookups_val[$<lookups>$->lookups.lookups_len-1]=$<lookup>1;
	}
	| lu_ft_eq_c COMMA lu_ft_eq_c_i {
		$<lookups>$=$<lookups>1;
		$<lookups>$->lookups.lookups_len++;
		$<lookups>$->lookups.lookups_val=realloc($<lookups>$->lookups.lookups_val, sizeof($<lookups>$->lookups.lookups_val[0])*$<lookups>$->lookups.lookups_len);
		$<lookups>$->lookups.lookups_val[$<lookups>$->lookups.lookups_len-1]=$<lookup>3;
	}
;

lu_ft_eq_c_i:
	lu_ft EQUAL lu_fc  {
		$<lookup>$=malloc(sizeof(struct s_lookup));
		$<lookup>$->fieldtag=strdup($<str>1);
		$<lookup>$->tabcol=strdup($<str>3);
}
;

lu_ft: field_tag_name ;

lu_fc: 	named_or_kw_any_pc DOT named_or_kw_any_pc {
			sprintf($<str>$,"%s.%s", $<str>1,$<str>3);
		}
	| named_or_kw_any_pc {
			sprintf($<str>$,"%s", $<str>1);
	}
;

lu_joincol:
 	named_or_kw_any_pc DOT named_or_kw_any_pc {sprintf($<str>$,"%s.%s", $<str>1,$<str>3);}
	| named_or_kw_any_pc {sprintf($<str>$,"%s",$<str>1);}
 	| STAR named_or_kw_any_pc DOT named_or_kw_any_pc {sprintf($<str>$,"*%s.%s", $<str>2,$<str>4);}
	| STAR named_or_kw_any_pc {sprintf($<str>$,"*%s",$<str>2);}
;

lu_join: JOINING 
	| COMMA JOINING
;


op_field_desc : 
| COMMA op_desc_list
;

op_desc_list : 
desc | op_desc_list COMMA desc;

desc :  
AUTONEXT { 
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();

A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
| COLOR EQUAL colors  op_where {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
		if ($<expr>4==0)  {
			int a;
			struct  u_expression *e_true;
  			e_true=create_int_expr(1);
			fld->colours.colours_len++;
			a=fld->colours.colours_len;
			fld->colours.colours_val=realloc(fld->colours.colours_val,a*sizeof(struct colours ) );
			fld->colours.colours_val[a-1].colour=atoi($<str>3);
			fld->colours.colours_val[a-1].whereexpr=e_true;
		} else  {
			int a;
			fld->colours.colours_len++;
			a=fld->colours.colours_len;
			fld->colours.colours_val=realloc(fld->colours.colours_val,a*sizeof(struct colours ) );
			fld->colours.colours_val[a-1].colour=atoi($<str>3);
			fld->colours.colours_val[a-1].whereexpr=$<expr>4;

		}
} 
| LOOKUP_FROM  lu_joincol  {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	   struct s_lookup  *l;
	   struct s_lookups *ls;
           l=malloc(sizeof(struct s_lookup));
           l->fieldtag=strdup("<<FROM>>");
           l->tabcol=strdup($<str>2);

	   ls=malloc(sizeof(s_lookups));
	   ls->lookups.lookups_len=0;
	   ls->lookups.lookups_val=0;

	   ls->lookups.lookups_len++;
	   ls->lookups.lookups_val=realloc(ls->lookups.lookups_val, sizeof(ls->lookups.lookups_val[0])*ls->lookups.lookups_len);
  	   ls->lookups.lookups_val[ls->lookups.lookups_len-1]=l;
	   ls->joincol="<<FROM>>";

	   fld->lookup.lookups.lookups_len++;
	   fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	   fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=ls;


}
| LOOKUP  op_lu_ft_eq_c lu_join lu_joincol  {
				struct struct_scr_field *fld;
				fld=A4GL_get_fld();
	$<lookups>2->joincol=strdup($<str>4);
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=$<lookups>2;
}
| COMMENTS EQUAL CHAR_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_COMMENTS,$<str>3); }
| DEFAULT EQUAL def_val { A4GL_add_str_attr(A4GL_get_fld(),FA_S_DEFAULT,$<str>3); }
| OPTIONS EQUAL def_val { A4GL_add_str_attr(A4GL_get_fld(),FA_S_OPTIONS,$<str>3); }
| DISPLAY LIKE named_or_kw_any_pc {	
#ifdef DEBUG
A4GL_debug("WARNING : DISPLAY LIKE not really implemented");
#endif
}
| DISPLAY LIKE named_or_kw_any_pc DOT named_or_kw_any_pc {	
#ifdef DEBUG
A4GL_debug("WARNING : DISPLAY LIKE not really implemented");
#endif
}
| VALIDATE LIKE named_or_kw_any_pc {	
#ifdef DEBUG
A4GL_debug("WARNING : VALIDATE LIKE not really implemented");
#endif
}
| VALIDATE LIKE named_or_kw_any_pc DOT named_or_kw_any_pc {	
#ifdef DEBUG
A4GL_debug("WARNING : VALIDATE LIKE not really implemented");
#endif
}
| DOWNSHIFT { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_DOWNSHIFT); }
| UPSHIFT { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UPSHIFT); }
| FORMAT EQUAL CHAR_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_FORMAT,$<str>3); }
| INCLUDE EQUAL OPEN_BRACKET incl_list CLOSE_BRACKET { sprintf($<str>$,"\n%s",$<str>4); A4GL_add_str_attr(A4GL_get_fld(),FA_S_INCLUDE,$<str>$); }
| WIDGET EQUAL CHAR_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_WIDGET,$<str>3); }
| CONFIG EQUAL CHAR_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_CONFIG,$<str>3); }
| KW_ACTION EQUAL named_or_kw_any_pc { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ACTION,$<str>3); }
| INVISIBLE { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_INVISIBLE); }
| DYNAMIC KW_SIZE EQUAL NUMBER_VALUE { A4GL_get_fld()->dynamic=atoi($<str>4); 
#ifdef DEBUG
A4GL_debug("fld->dynamic=%d",A4GL_get_fld()->dynamic); 
#endif
}
| DYNAMIC  { A4GL_get_fld()->dynamic=-1; 
#ifdef DEBUG
A4GL_debug("dynamic=-1"); 
#endif
}
| SQLONLY  { printf("Warning %s is not implemented for 4GL\n",$<str>1); }

| NOENTRY { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOENTRY); }

| NOUPDATE { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOUPDATE); }
| PICTURE EQUAL CHAR_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PICTURE,$<str>3); }
| PROGRAM EQUAL CHAR_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PROGRAM,$<str>3); }
| REQUIRED 	{ A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REQUIRED); }
| UNHIDABLE 	{ A4GL_add_bool_attr(A4GL_get_fld(),FA_B_UNHIDABLE); }
| REVERSE 	{ A4GL_add_bool_attr(A4GL_get_fld(),FA_B_REVERSE); }
| VERIFY 	{ A4GL_add_bool_attr(A4GL_get_fld(),FA_B_VERIFY); }
| QUERYCLEAR   	{ A4GL_add_bool_attr(A4GL_get_fld(),FA_B_QUERYCLEAR); }
| KW_ZEROFILL   { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_ZEROFILL); }
| KW_RIGHT   	{ A4GL_add_bool_attr(A4GL_get_fld(),FA_B_RIGHT); }
| WORDWRAP  	{ A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP); }
| WORDWRAP  COMPRESS {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_COMPRESS);
}
| WORDWRAP NONCOMPRESS {
	A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WORDWRAP);
}



/* Extended attributes */
| KW_HIDDEN { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_HIDDEN); }
| KW_NOSHOW { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOSHOW); }
| KW_NOHIDEMENU { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_NOHIDEMENU); }
| KW_AUTOSCALE { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_AUTOSCALE); }
| KW_WANTNORETURNS { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTNORETURNS); }
| KW_WANTRETURNS { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTRETURNS); }
| KW_WANTTABS { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_WANTTABS); }
| KW_FONTPITCH EQUAL KW_FIXED { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHFIXED); }
| KW_FONTPITCH EQUAL KW_VARIABLE { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_FONTPITCHVARIABLE); }
| KW_SCROLL { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLL); }
| KW_IMAGE EQUAL CHAR_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_IMAGE,$<str>3); }
| KW_JUSTIFY EQUAL LEFT { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"left"); }
| KW_JUSTIFY EQUAL KW_RIGHT { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"right"); }
| KW_JUSTIFY EQUAL KW_CENTER { A4GL_add_str_attr(A4GL_get_fld(),FA_S_JUSTIFY,"center"); }
| KW_PIXELHEIGHT EQUAL NUMBER_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELHEIGHT,$<str>3); }
| KW_PIXELWIDTH EQUAL NUMBER_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_PIXELWIDTH,$<str>3); }
| KW_SCROLLBARS_BOTH  { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_BOTH); } 
| KW_SCROLLBARS_V  { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_VERTICAL); } 
| KW_SCROLLBARS_H  { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_SCROLLBARS_HORIZONAL); } 
| KW_STRETCH_Y  { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_Y); } 
| KW_STRETCH_BOTH  { A4GL_add_bool_attr(A4GL_get_fld(),FA_B_STRETCH_BOTH); } 
| KW_ITEMS  EQUAL OPEN_BRACKET items_list CLOSE_BRACKET { A4GL_add_str_attr(A4GL_get_fld(),FA_S_ITEMS,$<str>4); } 
| KW_TABINDEX EQUAL NUMBER_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TABINDEX,$<str>3); } 
| KW_VALUEMAX EQUAL NUMBER_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMAX,$<str>3); } 
| KW_VALUEMIN EQUAL NUMBER_VALUE{ A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEMIN,$<str>3); } 
| KW_NOT_NULL { A4GL_get_fld()->not_null=1;}

| KW_VALUECHECKED EQUAL CHAR_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,$<str>3); } 
| KW_VALUEUNCHECKED EQUAL CHAR_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,$<str>3); } 
| KW_VALUECHECKED EQUAL NUMBER_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUECHECKED,$<str>3); } 
| KW_VALUEUNCHECKED EQUAL NUMBER_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_VALUEUNCHECKED,$<str>3); } 
| KW_TEXT EQUAL CHAR_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_TEXT,$<str>3); } 
| KW_HEADER EQUAL CHAR_VALUE { A4GL_add_str_attr(A4GL_get_fld(),FA_S_HEADER,$<str>3); } 
| KW_STYLE EQUAL CHAR_VALUE { A4GL_add_str_attr(A4GL_get_fld(), FA_S_STYLE, $<str>3); } 
;



def_val : 
CHAR_VALUE {strcpy($<str>$,$<str>1);}
| NUMBER_VALUE  {strcpy($<str>$,$<str>1);}
| NAMED  {sprintf($<str>$,"\"%s\"",$<str>1);}
| SQL_VAR {sprintf($<str>$,"\n%s",$<str>1);
	if (strcasecmp($<str>1,"current")==0) {
		int a;
		if (((A4GL_get_fld()->datatype)&DTYPE_MASK)==DTYPE_DTIME) {
			a=A4GL_get_fld()->dtype_size;
			sprintf($<str>$,"\n%s%x",$<str>1, a);
		}
	}
}
;


colors : 	color 
	| 	colors color { sprintf($<str>$,"%d",atoi($<str>1)+atoi($<str>2)); }
;

color : 
	BLACK { strcpy($<str>$,"0"); }
| 	BLUE { strcpy($<str>$,"4"); }
| 	GREEN { strcpy($<str>$,"2"); }
| 	CYAN { strcpy($<str>$,"6"); }
| 	RED { strcpy($<str>$,"1"); }
| 	MAGENTA { strcpy($<str>$,"5"); }
| 	WHITE { strcpy($<str>$,"7"); }
| 	YELLOW { strcpy($<str>$,"3"); }

|	NUMBER_VALUE { 
			char *ptr;
			
			ptr=$<str>1;
			if (strlen(ptr) > 1) {
	        		yyerror("Colour number out of range 0-7");
			}
			if (*ptr>='0'||*ptr<='7') ;
			else {
	        		yyerror("Colour number out of range 0-7");
			}

		/* Translate from Informix colour codes to Aubit ones...*/
		switch (*ptr) {
			/*
			0: WHITE/ NORMAL
			1: YELLOW/BOLD
			2: MAGENTA/BOLD
			3: RED/BOLD
			4: CYAN/DIM
			5: GREEN/DIM
			6: BLUE/DIM
			7: BLACK/DIM
			*/
			case '0': strcpy($<str>$,"7"); break;
			case '1': strcpy($<str>$,"3"); break;
			case '2': strcpy($<str>$,"5"); break;
			case '3': strcpy($<str>$,"1"); break;
			case '4': strcpy($<str>$,"6"); break;
			case '5': strcpy($<str>$,"2"); break;
			case '6': strcpy($<str>$,"4"); break;
			case '7': strcpy($<str>$,"0"); break;
		}
		}

| 	REVERSE { sprintf($<str>$,"%d",A4GL_get_attr_from_string("REVERSE")); }
| 	DIM  { sprintf($<str>$,"%d",A4GL_get_attr_from_string("DIM")); }
| 	NORMAL  { sprintf($<str>$,"%d",A4GL_get_attr_from_string("NORMAL")); }
| 	LEFT { sprintf($<str>$,"%d",A4GL_get_attr_from_string("LEFT")); }
| 	BOLD { sprintf($<str>$,"%d",A4GL_get_attr_from_string("BOLD")); }
| 	BLINK { sprintf($<str>$,"%d",A4GL_get_attr_from_string("BLINK")); }
| 	UNDERLINE { sprintf($<str>$,"%d",A4GL_get_attr_from_string("UNDERLINE")); }

;

op_instruction_section : 
	| INSTRUCTIONS instruct_opts op_end;

instruct_opts :  
	instruct_op_1 | instruct_opts  instruct_op_1 ;

instruct_op_1 : instruct_op | instruct_op SEMICOLON;

instruct_op :
DELIMITERS CHAR_VALUE {
	char buff[4];
	strcpy(buff,A4GL_char_val($<str>2));
	if (strlen(buff)==1) {
		buff[1]=buff[0];
		buff[2]=buff[0];
		buff[3]=0;
	}
	the_form.delim=acl_strdup(buff);
}
| control_block  {
	the_form.control_blocks.control_blocks_len++;
	the_form.control_blocks.control_blocks_val= realloc( the_form.control_blocks.control_blocks_val, sizeof(the_form.control_blocks.control_blocks_val[0])*the_form.control_blocks.control_blocks_len);
	memcpy(&the_form.control_blocks.control_blocks_val[the_form.control_blocks.control_blocks_len-1], $<control_block>1,sizeof(struct s_control_block));
;
}
| KW_SCREEN RECORD {
A4GL_add_srec();
} srec_dim OPEN_BRACKET srec_field_list CLOSE_BRACKET op_ltype op_semi
| KW_PANEL OPEN_BRACKET NUMBER_VALUE COMMA NUMBER_VALUE CLOSE_BRACKET TO OPEN_BRACKET NUMBER_VALUE COMMA NUMBER_VALUE CLOSE_BRACKET 
| composites
| master_of
;


op_ltype : | AS LISTBOX;
 
op_star: {$<intval>$=0;} | STAR {$<intval>$=1;} 
;

op_semi: | SEMICOLON;

srec_dim : named_or_kw_any_pc  {
   A4GL_set_dim_srec($<str>1,1);
}
| named_or_kw_any_pc OPEN_SQUARE NUMBER_VALUE CLOSE_SQUARE {
   A4GL_set_dim_srec($<str>1,atoi($<str>3));
};


srec_field_list : 
field_list_element {
	sprintf($<str>$,"%s",$<str>1);
} 
| srec_field_list op_comma field_list_element {
	sprintf($<str>$,"%s,%s",$<str>1,$<str>3);
};

op_comma : 
	| COMMA
;

field_list_item :
named_or_kw_any_pc
{A4GL_add_srec_attribute("",$<str>1,"");
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
 }
| named_or_kw_any_pc DOT named_or_kw_any_pc
{A4GL_add_srec_attribute($<str>1,$<str>3,""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
| FORMONLY DOT named_or_kw_any_pc
{A4GL_add_srec_attribute("formonly",$<str>3,""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
| named_or_kw_any_pc DOT STAR 
{A4GL_add_srec_attribute($<str>1,"*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
| FORMONLY DOT STAR 
{A4GL_add_srec_attribute("formonly","*",""); 
if (A4GL_getFormErr()) {a4gl_form_yyerror(A4GL_get_fcompile_err());}
}
;

field_list_element :
field_list_item  | field_list_item THROUGH field_list_item {A4GL_add_srec_attribute("","","THROUGH");} 
;


field_name : named_or_kw_any_pc {
	strcpy($<str>$,$<str>1);
}
	| KW_END { strcpy($<str>$,$<str>1); }
;


op_ws : {strcpy($<str>$,"");} | ws {strcpy($<str>$,$<str>1);}
;

ws: ws_elem | ws ws_elem
;

ws_elem:
 KW_WS {colno++;}
|  KW_TAB {
	colno++;
	while ((colno%8)!=0) {colno++;}

       	//colno++;
       	//while ((colno%8)!=0) {colno++;}
	//colno--;
}
;



field_tag_name : 
named_or_kw_any_tag  {
	strcpy($<str>$,$<str>1);
/*
	if (tagCaseInsensitive) {
		A4GL_make_downshift($<str>$);
	}
*/
	colno+=strlen($<str>1);
	}
;

field_tag_name_scr : 
op_ws named_or_kw_any_tag {
	colno+=strlen($<str>2);
} op_ws {
	strcpy($<str>$,$<str>2);
	/*
	if (tagCaseInsensitive) {
		A4GL_make_downshift($<str>$);
	}
*/
}
;

datatype : 
KW_CHAR {
	strcpy($<str>$,"0");
	dtype_size=0;
} 
| KW_CHAR OPEN_BRACKET NUMBER_VALUE CLOSE_BRACKET {
	strcpy($<str>$,"0");
	dtype_size=atol($<str>3);
} 
| KW_INT {
	strcpy($<str>$,"2");
	dtype_size=0;
} 
| KW_DATE {
	strcpy($<str>$,"7");
	dtype_size=0;
} 
| KW_FLOAT {
	strcpy($<str>$,"3");
	dtype_size=0;
} 
| SMALLFLOAT {
	strcpy($<str>$,"4");
	dtype_size=0;
}
| SMALLINT {
	strcpy($<str>$,"1");
	dtype_size=0;
} 
| KW_DECIMAL opt_dec_ext {
		int i;
		i=atoi($<str>2);
		strcpy($<str>$,"5");
		dtype_size=i;
} 
| MONEY opt_dec_ext {
	strcpy($<str>$,"8");
	dtype_size=atoi($<str>2);
} 
| DATETIME opt_dt_ext {
	strcpy($<str>$,"10");
	dtype_size=atoi($<str>2);
} 
| INTERVAL opt_int_ext {
	strcpy($<str>$,"14");
	dtype_size=atoi($<str>2);
}
| SERIAL {
	strcpy($<str>$,"6");
	dtype_size=0;
}
| KW_BYTE {
	strcpy($<str>$,"11");
	dtype_size=0;
}
| KW_TEXT {
	strcpy($<str>$,"12");
	dtype_size=0;
}
| VARCHAR { strcpy($<str>$,"13");
	dtype_size=0;
	}
| BUTTON { strcpy($<str>$,"90");
	dtype_size=0;
	}

;


incl_list : incl_entry | incl_list COMMA incl_entry {
	sprintf($<str>$,"%s\n%s",$<str>1,$<str>3);
};

items_list : items_entry | items_list COMMA items_entry {
	sprintf($<str>$,"%s\n%s",$<str>1,$<str>3);
};


number_value : NUMBER_VALUE | PLUS NUMBER_VALUE | MINUS NUMBER_VALUE {sprintf($<str>$,"-%s",$<str>2);}
;

items_entry : 
	CHAR_VALUE   { 
		if (strlen($<str>1)==2) { /* "" */
			strcpy($<str>$,"");
		} else {
			strcpy($<str>$,A4GL_char_val($<str>1)); 
		}
	}
	| NAMED   {strcpy($<str>$,$<str>1); }
	| CH   {strcpy($<str>$,$<str>1);}
	| number_value 
	| KW_NULL {
		strcpy($<str>$,"");
	}
;


incl_entry:
	incl_item
	| incl_item TO incl_item {
			sprintf($<str>$,"%s\t%s",$<str>1,$<str>3); 
	}
	| incl_item COLON incl_item {
			sprintf($<str>$,"%s\t%s",$<str>1,$<str>3); 
	}
;

incl_item:
	CHAR_VALUE {
		if (strlen($<str>1)==2) {/* "" */
			sprintf($<str>$,"NULL");
		} else {
			strcpy($<str>$,A4GL_char_val($<str>1));
		}
	}
	| NAMED {strcpy($<str>$,$<str>1);}
	| CH {strcpy($<str>$,$<str>1);}
	| number_value {strcpy($<str>$,$<str>1);}
	| KW_NULL {strcpy($<str>$,"NULL");}

;



opt_dec_ext : {
			sprintf($<str>$,"0");
		}
	| OPEN_BRACKET NUMBER_VALUE CLOSE_BRACKET {
		int n;
		 n=atol(acl_getenv("A4GL_DEFDECPREC"));
		sprintf($<str>$,"%d",((atoi($<str>2))<<8)+n);
	}
	| OPEN_BRACKET NUMBER_VALUE COMMA NUMBER_VALUE CLOSE_BRACKET {sprintf($<str>$,"%d",(atoi($<str>2)<<8)+atoi($<str>4));}
;

opt_int_ext : {strcpy($<str>$,"");}
	| int_start TO int_end
	{
	sprintf($<str>$,"%d",(atoi($<str>1)*16)+atoi($<str>3));
	}
;


opt_unit_size: {
#ifdef DEBUG
A4GL_debug("Nothing in fraction - assume 2");
#endif
strcpy($<str>$,"2");} |  OPEN_BRACKET NUMBER_VALUE CLOSE_BRACKET {
#ifdef DEBUG
A4GL_debug("    %s",$<str>2);
#endif
strcpy($<str>$,$<str>2);
};

dtfrac: NUMBER_VALUE {
if (atoi($<str>1)>5) {
yyerror("Fraction values are between 0 and 5");
YYERROR;
}
}
;

int_start :  int_start_unit opt_unit_size {sprintf($<str>$,"%d",atoi($<str>2)*16+atoi($<str>1));}
;

int_start_unit : YEAR {strcpy($<str>$,"1");}
| MONTH {strcpy($<str>$,"2");}
| DAY {strcpy($<str>$,"3");}
| HOUR {strcpy($<str>$,"4");}
| MINUTE {strcpy($<str>$,"5");}
| SECOND{strcpy($<str>$,"6");}
| FRACTION opt_frac
  {
#ifdef DEBUG
  A4GL_debug("opt_frac returns %s",$<str>2);
#endif
  sprintf($<str>$,"%d",atoi($<str>2)+6); }
  ;

  int_end : int_start_unit;

opt_dt_ext : {strcpy($<str>$,"");}
	| dt_start TO dt_end {sprintf($<str>$,"%d",atoi($<str>1)*16+atoi($<str>3));}
;

dt_start: dtime_val {strcpy($<str>$,$<str>1);}
;

dt_end: dtime_val {strcpy($<str>$,$<str>1);}
;

dtime_val :
YEAR {strcpy($<str>$,"1");}
| MONTH {strcpy($<str>$,"2");}
| DAY {strcpy($<str>$,"3");}
| HOUR {strcpy($<str>$,"4");}
| MINUTE {strcpy($<str>$,"5");}
| SECOND{strcpy($<str>$,"6");}
| FRACTION opt_frac
{
#ifdef DEBUG
A4GL_debug("opt_frac returns %s",$<str>2);
#endif
sprintf($<str>$,"%d",atoi($<str>2)+6); }
;

opt_frac: {
#ifdef DEBUG
A4GL_debug("Nothing in fraction - assume 2");
#endif
strcpy($<str>$,"2");} |  OPEN_BRACKET dtfrac CLOSE_BRACKET {
#ifdef DEBUG
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",$<str>2);
#endif
strcpy($<str>$,$<str>2);
};


op_where: {$<expr>$=0;} | where_clause {
$<expr>$=$<expr>1;
}

;

where_clause : KWWHERE clauses {
		$<expr>$=$<expr>2;
	}
;

clauses : 
	clause 
	| clause KWAND clause {
		$<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,"AND");  
	}
	| clause KWOR clause {
		$<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,"OR");  
	}
;




clause: 
	KW_LINEISODD { $<expr>$=create_expr_oddline();}
	| KW_LINEISEVEN { $<expr>$=create_expr_evenline(); }
	| value COMPARISON value { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2); }
	| value LESSTHAN value { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2); }
	| value GREATERTHAN value { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2); }
	| value LIKE value { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2); }
	| value KWNOT LIKE value { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>4,"NOTLIKE"); }
	| value EQUAL value { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2); }
	| value KWNULLCHK { void *p; p=create_char_expr("ISNULL"); $<expr>$=create_expr_comp_expr($<expr>1,p,"ISNULL"); }
	| value KWNOTNULLCHK { void *p; p=create_char_expr("ISNOTNULL"); $<expr>$=create_expr_comp_expr($<expr>1,p,"ISNOTNULL"); }
	| value  { $<expr>$=$<expr>1; }
	| value KWBETWEEN value KWAND value { $<expr>$=create_list_expr(); add_list_expr($<expr>$,$<expr>3); add_list_expr($<expr>$,$<expr>5); $<expr>$=create_expr_comp_expr($<expr>1,$<expr>$,"BETWEEN"); }
	| value KWIN OPEN_BRACKET value_list CLOSE_BRACKET { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>4,"IN"); }
	| KWNOT clause { $<expr>$=create_not_expr($<expr>2); }
	| OPEN_BRACKET clause CLOSE_BRACKET { $<expr>$=$<expr>2; }
;

value : fieldidentifier  {
$<expr>$=create_field_expr($<str>1);
if (strcasecmp(currftag,$<str>1)!=0) {
	yyerror("Cannot make colour conditional upon a different field tag");
	
}
}
| NUMBER_VALUE  {$<expr>$=create_int_expr(atoi($<str>1)); printf("NUMBER VALUE : %s\n",$<str>1); }
| CHAR_VALUE    {$<expr>$=create_char_expr($<str>1);}
| XVAL          {
	$<expr>$=create_special_expr($<str>1);
}
;

fieldidentifier : NAMED  
;

value_list : value {
		$<expr>$=create_list_expr();
		add_list_expr($<expr>$,$<expr>1);
	}
| value_list COMMA value {
		add_list_expr($<expr>1,$<expr>3);
		$<expr>$=$<expr>1;
	}

;





composites:
	KW_COMPOSITES composites_list
;

composites_list: composite_entry 
		| composites_list composite_entry
;

composite_entry: 
	LESSTHAN comp_list GREATERTHAN op_star LESSTHAN comp_list GREATERTHAN {
		the_form.composites.composites_len++;
		the_form.composites.composites_val= realloc(the_form.composites.composites_val, 
			sizeof(the_form.composites.composites_val[0])* the_form.composites.composites_len);
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_left=$<col_list>2;
		the_form.composites.composites_val[the_form.composites.composites_len-1].col_right=$<col_list>6;
		the_form.composites.composites_val[the_form.composites.composites_len-1].has_star=$<intval>4;
	}
;

comp_list: comp_item {
		$<col_list>$=malloc(sizeof(struct s_column_list));
		$<col_list>$->columns.columns_len=1;
		$<col_list>$->columns.columns_val=malloc(sizeof(struct s_column));
		$<col_list>$->columns.columns_val[0].tabname=$<column>1.tabname;
		$<col_list>$->columns.columns_val[0].colname=$<column>1.colname;
	}
	| comp_list COMMA comp_item  {
		$<col_list>$=$<col_list>1;
		$<col_list>$->columns.columns_len++;
		$<col_list>$->columns.columns_val=realloc($<col_list>$->columns.columns_val, sizeof(struct s_column)*$<col_list>$->columns.columns_len);
		$<col_list>$->columns.columns_val[$<col_list>$->columns.columns_len-1].tabname=$<column>3.tabname;
		$<col_list>$->columns.columns_val[$<col_list>$->columns.columns_len-1].colname=$<column>3.colname;
	}
;

comp_item : table_name DOT column_name {
	$<column>$.tabname=strdup($<str>1);
	$<column>$.colname=strdup($<str>3);
} |  column_name {
	int n;
	char *tabname;
        n=A4GLF_getdatatype_fcompile($<str>1,"",0);
        tabname=A4GL_get_found_in_tab();

	$<column>$.tabname=strdup(tabname);
	$<column>$.colname=strdup($<str>1);
}

;

table_name : named_or_kw_any_pc
;

column_name : named_or_kw_st_pc
;

control_block :
	KW_BEFORE bef_act_list KW_OF column_list actions {
		$<control_block>$=malloc(sizeof(struct s_control_block));
		$<control_block>$->cbtype=E_CB_BEFORE;
		$<control_block>$->s_control_block_u.befaft=$<befact>2;
		$<control_block>$->s_control_block_u.befaft->column_list=$<col_list>4;
		$<control_block>$->s_control_block_u.befaft->cmds=$<at_block>5;
	}
	| KW_AFTER aft_act_list KW_OF column_list actions {
		$<control_block>$=malloc(sizeof(struct s_control_block));
		$<control_block>$->cbtype=E_CB_AFTER;
		$<control_block>$->s_control_block_u.befaft=$<befact>2;
		$<control_block>$->s_control_block_u.befaft->column_list=$<col_list>4;
		$<control_block>$->s_control_block_u.befaft->cmds=$<at_block>5;

	}
	| KW_ON_BEGINNING func_call {
		$<control_block>$=malloc(sizeof(struct s_control_block));
		$<control_block>$->cbtype=E_CB_ONBEGINNING;
		$<control_block>$->s_control_block_u.onbegend=$<fcall>2;
	}
	| KW_ON_ENDING func_call {
		$<control_block>$=malloc(sizeof(struct s_control_block));
		$<control_block>$->cbtype=E_CB_ONENDING;
		$<control_block>$->s_control_block_u.onbegend=$<fcall>2;
	}
;

action:
	abort {
		$<at_action>$=malloc(sizeof(struct u_action));
		$<at_action>$->type=ACTION_TYPE_ABORT;
	}
	| comments {
		$<at_action>$=malloc(sizeof(struct u_action));
		$<at_action>$->type=ACTION_TYPE_COMMENTS;
		$<at_action>$->u_action_u.cmd_comment=$<at_comments>1;
	}
	| if {
		$<at_action>$=malloc(sizeof(struct u_action));
		$<at_action>$->type=ACTION_TYPE_IF;
		$<at_action>$->u_action_u.cmd_if=$<at_if>1;
	}
	| let {
		$<at_action>$=malloc(sizeof(struct u_action));
		$<at_action>$->type=ACTION_TYPE_LET;
		$<at_action>$->u_action_u.cmd_let=$<at_let>1;
	}
	| nextfield {
		$<at_action>$=malloc(sizeof(struct u_action));
		$<at_action>$->type=ACTION_TYPE_NEXTFIELD;
		$<at_action>$->u_action_u.cmd_nextfield=$<at_nextfield>1;
	}
	| func_call {
		$<at_action>$=malloc(sizeof(struct u_action));
		$<at_action>$->type=ACTION_TYPE_FUNC_CALL;
		$<at_action>$->u_action_u.cmd_call=$<fcall>1;
	}
	| block {
		$<at_action>$=malloc(sizeof(struct u_action));
		$<at_action>$->type=ACTION_TYPE_BLOCK;
		$<at_action>$->u_action_u.cmd_block=$<at_block>1;

	}
;


if: KW_IF expression KW_THEN action op_else {
		$<at_if>$=malloc(sizeof(struct s_at_if));
		$<at_if>$->test_condition=$<expr>2;
		$<at_if>$->if_true=$<at_action>4;
		$<at_if>$->if_false=$<at_action>5;
	}
;


op_else: {$<at_action>$=0;} 
	| KW_ELSE action {	
		$<at_action>$=$<at_action>2;
	}
;

abort : KW_ABORT  
;

let   : KW_LET field_tag_name EQUAL expression 
		{
			$<at_let>$=malloc(sizeof(struct s_at_let));
			$<at_let>$->field_tag=create_field_expr($<str>2);
			$<at_let>$->value=$<expr>4;
		}
;

nextfield : KW_NEXTFIELD field_tag_name 
		{
			$<at_nextfield>$=malloc(sizeof(struct s_at_nextfield));
			$<at_nextfield>$->field_tag=create_field_expr($<str>2);
			$<at_nextfield>$->isexitnow=0;
		}
	  | KW_NEXTFIELD EQUAL field_tag_name
		{
			$<at_nextfield>$=malloc(sizeof(struct s_at_nextfield));
			$<at_nextfield>$->field_tag=create_field_expr($<str>3);
			$<at_nextfield>$->isexitnow=0;
		}
	  | KW_NEXTFIELD KW_EXITNOW
		{
			$<at_nextfield>$=malloc(sizeof(struct s_at_nextfield));
			$<at_nextfield>$->field_tag=0;
			$<at_nextfield>$->isexitnow=1;
		}
	  | KW_NEXTFIELD EQUAL KW_EXITNOW
		{
			$<at_nextfield>$=malloc(sizeof(struct s_at_nextfield));
			$<at_nextfield>$->field_tag=0;
			$<at_nextfield>$->isexitnow=1;
		}
;

block: 
	KW_BEGIN actions KW_END {
		 $<at_block>$= $<at_block>2;
	}
;

actions: action  {
		$<at_block>$=malloc(sizeof(struct s_at_block));
		$<at_block>$->actions.actions_len=0;
		$<at_block>$->actions.actions_val=0;

		$<at_block>$->actions.actions_len++;
		$<at_block>$->actions.actions_val=realloc( $<at_block>$->actions.actions_val, sizeof($<at_block>$->actions.actions_val[0])*$<at_block>$->actions.actions_len);
		$<at_block>$->actions.actions_val[$<at_block>$->actions.actions_len-1].uaction=$<at_action>1;

	}
	| actions action {
		$<at_block>$=$<at_block>1;
		$<at_block>$->actions.actions_len++;
		$<at_block>$->actions.actions_val=realloc( $<at_block>$->actions.actions_val, sizeof($<at_block>$->actions.actions_val[0])*$<at_block>$->actions.actions_len);
		$<at_block>$->actions.actions_val[$<at_block>$->actions.actions_len-1].uaction=$<at_action>2;
		}
;


comments :
	COMMENTS CHAR_VALUE {
		$<at_comments>$=malloc(sizeof(struct s_at_comments));
		$<at_comments>$->comment=strdup(A4GL_strip_quotes($<str>2));
		$<at_comments>$->hasbell=0;
		$<at_comments>$->isreverse=0;
	}
	| COMMENTS KW_BELL CHAR_VALUE {
		$<at_comments>$=malloc(sizeof(struct s_at_comments));
		$<at_comments>$->comment=strdup(A4GL_strip_quotes($<str>3));
		$<at_comments>$->hasbell=1;
		$<at_comments>$->isreverse=0;
	}
	| COMMENTS REVERSE CHAR_VALUE {
		$<at_comments>$=malloc(sizeof(struct s_at_comments));
		$<at_comments>$->comment=strdup(A4GL_strip_quotes($<str>3));
		$<at_comments>$->hasbell=0;
		$<at_comments>$->isreverse=1;
	}
	| COMMENTS KW_BELL REVERSE CHAR_VALUE {
		$<at_comments>$=malloc(sizeof(struct s_at_comments));
		$<at_comments>$->comment=strdup(A4GL_strip_quotes($<str>4));
		$<at_comments>$->hasbell=1;
		$<at_comments>$->isreverse=1;
	}
;


bef_act_list: 
	bef_act {
		$<befact>$=malloc(sizeof(struct s_bef_aft));
		$<befact>$->cmds=0;
		$<befact>$->column_list=0;
		$<befact>$->befaftlist.befaftlist_len=0;
		$<befact>$->befaftlist.befaftlist_val=0;		

		$<befact>$->befaftlist.befaftlist_len++;
		$<befact>$->befaftlist.befaftlist_val=realloc($<befact>$->befaftlist.befaftlist_val, sizeof($<befact>$->befaftlist.befaftlist_val[0])*$<befact>$->befaftlist.befaftlist_len);
		$<befact>$->befaftlist.befaftlist_val[$<befact>$->befaftlist.befaftlist_len-1]=$<intval>1;

	}
	| bef_act_list bef_act {
		$<befact>$->befaftlist.befaftlist_len++;
		$<befact>$->befaftlist.befaftlist_val=realloc($<befact>$->befaftlist.befaftlist_val, sizeof($<befact>$->befaftlist.befaftlist_val[0])*$<befact>$->befaftlist.befaftlist_len);
		$<befact>$->befaftlist.befaftlist_val[$<befact>$->befaftlist.befaftlist_len-1]=$<intval>2;
	}
;

aft_act_list: 
	aft_act  {
		$<befact>$=malloc(sizeof(struct s_bef_aft));
		$<befact>$->cmds=0;
		$<befact>$->column_list=0;
		$<befact>$->befaftlist.befaftlist_len=0;
		$<befact>$->befaftlist.befaftlist_val=0;		

		$<befact>$->befaftlist.befaftlist_len++;
		$<befact>$->befaftlist.befaftlist_val=realloc($<befact>$->befaftlist.befaftlist_val, sizeof($<befact>$->befaftlist.befaftlist_val[0])*$<befact>$->befaftlist.befaftlist_len);
		$<befact>$->befaftlist.befaftlist_val[$<befact>$->befaftlist.befaftlist_len-1]=$<intval>1;

	}
	| aft_act_list aft_act {
		$<befact>$->befaftlist.befaftlist_len++;
		$<befact>$->befaftlist.befaftlist_val=realloc($<befact>$->befaftlist.befaftlist_val, sizeof($<befact>$->befaftlist.befaftlist_val[0])*$<befact>$->befaftlist.befaftlist_len);
		$<befact>$->befaftlist.befaftlist_val[$<befact>$->befaftlist.befaftlist_len-1]=$<intval>2;
	}
;

bef_act :
	KW_EDITADD 	{$<intval>$=E_BA_EDITADD;}
	| KW_EDITUPDATE {$<intval>$=E_BA_EDITUPDATE;}
	| KW_REMOVE	{$<intval>$=E_BA_REMOVE;}
;

aft_act:
	KW_EDITADD 	{$<intval>$=E_BA_EDITADD;}
	| KW_ADD	{$<intval>$=E_BA_ADD;}
	| KW_UPDATE	{$<intval>$=E_BA_UPDATE;}
	| KW_QUERY	{$<intval>$=E_BA_QUERY;}
	| KW_REMOVE	{$<intval>$=E_BA_REMOVE;}
	| DISPLAY	{$<intval>$=E_BA_DISPLAY;}
	| KW_EDITUPDATE	{$<intval>$=E_BA_EDITUPDATE;}
;

column_list: column_entry {
		$<col_list>$=malloc(sizeof(struct s_column_list));
		$<col_list>$->columns.columns_len=1;
		$<col_list>$->columns.columns_val=malloc(sizeof(struct s_column));
		$<col_list>$->columns.columns_val[0].tabname=$<column>1.tabname;
		$<col_list>$->columns.columns_val[0].colname=$<column>1.colname;
	}
	| column_list op_comma column_entry {
		$<col_list>$=$<col_list>1;
		$<col_list>$->columns.columns_len++;
		$<col_list>$->columns.columns_val=realloc($<col_list>$->columns.columns_val, sizeof(struct s_column)*$<col_list>$->columns.columns_len);
		$<col_list>$->columns.columns_val[$<col_list>$->columns.columns_len-1].tabname=$<column>3.tabname;
		$<col_list>$->columns.columns_val[$<col_list>$->columns.columns_len-1].colname=$<column>3.colname;
	}
	
;

column_entry : 
	table_name DOT column_name {
		$<column>$.tabname=strdup($<str>1);
		$<column>$.colname=strdup($<str>3);
	}
	| column_name {
		$<column>$.tabname=strdup("");
		$<column>$.colname=strdup($<str>1);
	}
;

master_of:
	table_name KW_MASTER_OF table_name op_semi {
		the_form.master_of.master_of_len++;
		the_form.master_of.master_of_val=realloc(the_form.master_of.master_of_val, sizeof(the_form.master_of.master_of_val[0])*the_form.master_of.master_of_len);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_master=strdup($<str>1);
		the_form.master_of.master_of_val[the_form.master_of.master_of_len-1].tab_detail=strdup($<str>3);
	}
;

func_call: KW_CALL named_or_kw_any_pc OPEN_BRACKET {
			$<fcall>$=malloc(sizeof(struct s_at_call));
			memset($<fcall>$,0,sizeof(struct s_at_call));
			$<fcall>$->fname=strdup($<str>2);
			$<fcall>$->list_parameters.list_parameters_len=0;
			$<fcall>$->list_parameters.list_parameters_val=0;
	} op_func_call_args CLOSE_BRACKET {
		$<fcall>$=$<fcall>4;
		if ($<el>5) {
			listitem *l;
			$<fcall>$->list_parameters.list_parameters_len=$<el>5->nlist;
			l=$<el>5->expr_list;
			$<fcall>$->list_parameters.list_parameters_val=l;
		}
	}
	
;

op_func_call_args: {$<el>$=0;} 
	| func_call_args {
		$<el>$=$<el>1;
	}
;

func_call_args: 
	func_call_arg  {
		$<el>$=malloc(sizeof(struct local_expr_list));
		$<el>$->nlist=1;
		$<el>$->expr_list=malloc(sizeof($<el>$->expr_list[0]));
		$<el>$->expr_list[0]=$<expr>1;
	}
	| func_call_args COMMA func_call_arg {
		$<el>$=$<el>1;
		$<el>$->nlist++;
		$<el>$->expr_list=realloc($<el>$->expr_list, sizeof($<el>$->expr_list[0])*$<el>$->nlist);
		$<el>$->expr_list[$<el>$->nlist-1]=$<expr>3;
	}
;

func_call_arg : expression {
		$<expr>$=$<expr>1;
	}
;


expression : 
	single_expression
	| expression and_or expression { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2);}

;

and_or: 
	KWAND {strcpy($<str>$,"AND");}
	| KWOR {strcpy($<str>$,"OR");}
;


/*
op_expression_list : 
	| expression_list
;


expression_list : expression
	| expression_list COMMA expression
;
*/

single_expression: 
	MINUS expression { void *x; x=create_int_expr(0); $<expr>$=create_expr_comp_expr(x,$<expr>2,"-"); }

	|PLUS expression  { void *x; x=create_int_expr(0); $<expr>$=create_expr_comp_expr(x,$<expr>2,"+"); }
	| evalue  { $<expr>$=$<expr>1; }
	| KWNOT expression { $<expr>$=create_not_expr($<expr>2); }
	| OPEN_BRACKET expression CLOSE_BRACKET { $<expr>$=$<expr>2; }
	| fcall_name OPEN_BRACKET op_func_call_args CLOSE_BRACKET { 
			$<expr>$=create_fcall($<str>1,$<el>3);
	}
	| KW_TOTAL KW_OF field_tag_name { $<expr>$=create_field_expr($<str>3); }
	| expression COMPARISON expression { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2); }
	| expression LESSTHAN expression { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2); }
	| expression GREATERTHAN expression { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2); }
	| expression STAR expression { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2); }
	| expression PLUS expression { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2); }
	| expression MINUS expression { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2); }
	| expression DIVIDE expression { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2); }
	| expression LIKE expression { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2); }
	| expression KWNOT LIKE expression { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>4,"NOTLIKE"); }
	| expression EQUAL expression { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2); }
	| expression KWNULLCHK { void *p; p=create_char_expr("ISNULL"); $<expr>$=create_expr_comp_expr($<expr>1,p,"ISNULL"); }
	| expression KWNOTNULLCHK { void *p; p=create_char_expr("ISNOTNULL"); $<expr>$=create_expr_comp_expr($<expr>1,p,"ISNOTNULL"); }
	| expression KWBETWEEN expression KWAND expression { $<expr>$=create_list_expr(); add_list_expr($<expr>$,$<expr>3); add_list_expr($<expr>$,$<expr>5); $<expr>$=create_expr_comp_expr($<expr>1,$<expr>$,"BETWEEN"); }
	| expression KWIN OPEN_BRACKET evalue_list CLOSE_BRACKET { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>4,"IN"); }
	| expression KWNOT KWIN OPEN_BRACKET evalue_list CLOSE_BRACKET { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>5,"NOTIN"); }
;

fcall_name: named_or_kw_any_pc
;

evalue : field_tag_name  { $<expr>$=create_field_expr($<str>1); }
| NUMBER_VALUE  {$<expr>$=create_int_expr(atoi($<str>1)); }
| CHAR_VALUE    {$<expr>$=create_char_expr($<str>1);}
| XVAL        { $<expr>$=create_special_expr($<str>1); }
| KW_NULL { $<expr>$=create_special_expr($<str>1);}
;

evalue_list : evalue {
		$<expr>$=create_list_expr();
		add_list_expr($<expr>$,$<expr>1);
	}
| evalue_list COMMA evalue {
		add_list_expr($<expr>1,$<expr>3);
		$<expr>$=$<expr>1;
	}

;






%%


#include "lex.a4gl_form_yy.c"



/* =========================== EOF ============================ */



