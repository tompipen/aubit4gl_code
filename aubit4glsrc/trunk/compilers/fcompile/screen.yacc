%{
#define YYDEBUG 1
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

extern struct struct_scr_field *fld;
int graphics_mode=0;
extern int ignorekw;
extern int lineno;
extern int colno;
extern int scr;
int in_comment;
long fileseek=0;

dll_import struct_form the_form;

extern int newscreen;
extern int fldno;
extern int fstart;
extern int openwith;
extern char currftag[256];
extern char *outputfilename;
extern char *tablist[];
/* extern FILE *yyin; */
int in_screen_section=0;
int dtype_size=0;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *chk_alias(char *s);
/* extern char *char_val(char*s); */

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


%}
%start form_def

%name-prefix="a4gl_form_yy"

%union	  {
	char	str[1024];
	u_expression *expr;
}
%token <str> 
%token CH
%token INSTRUCTIONS ATTRIBUTES DATABASE BY KW_SCREEN_TITLE KW_SCREEN KW_SIZE OPEN_SQUARE KW_END CLOSE_SQUARE NUMBER_VALUE NAMED OPEN_BRACE CLOSE_BRACE TITLE
FORMONLY COMMENT
%token DYNAMIC COLON ATSIGN DOT WITHOUT KW_NULL INPUT TABLES PIPE EQUAL CHAR_VALUE
%token SEMICOLON
%token OPEN_BRACKET CLOSE_BRACKET STAR PLUS MINUS RECORD COMMA THROUGH LIKE TYPE DELIMITERS
%token KW_CHAR KW_INT KW_DATE KW_FLOAT SMALLFLOAT SMALLINT KW_DECIMAL MONEY DATETIME INTERVAL
%token BLACK BLUE GREEN CYAN RED MAGENTA WHITE YELLOW REVERSE LEFT BLINK UNDERLINE
%token   AUTONEXT COLOR COMMENTS DEFAULT DISPLAY DISPLAY DOWNSHIFT UPSHIFT FORMAT INCLUDE INVISIBLE NOENTRY PICTURE PROGRAM
REQUIRED REVERSE VERIFY WORDWRAP COMPRESS NONCOMPRESS TO  AS
%token SERIAL KW_BYTE KW_TEXT VARCHAR SQL_VAR
%token SQLONLY  WIDGET CONFIG
%token COMPARISON KWOR KWAND KWWHERE KWNOT KWBETWEEN KWIN XVAL KWNULLCHK KWNOTNULLCHK
%token YEAR MONTH DAY HOUR MINUTE SECOND FRACTION
/* extensions */
%token LISTBOX BUTTON KW_PANEL

%%

/* rules */
form_def : 
database_section screen_section op_table_section attribute_section op_instruction_section {A4GL_write_form();}
;
database_section :
DATABASE FORMONLY {the_form.dbname=strdup("formonly");}
| DATABASE dbname WITHOUT KW_NULL INPUT {the_form.dbname=($<str>2);
if (A4GLF_open_db($<str>2)) {
		yyerror("Unable to connect to database\n");
}
}
| DATABASE FORMONLY WITHOUT KW_NULL INPUT {the_form.dbname=("formonly");}
| DATABASE dbname {the_form.dbname=strdup($<str>2);
if (A4GLF_open_db($<str>2)) {
		yyerror("Unable to connect to database\n");
}
}
;

named_or_kw :
	NAMED 
	| any_kword
;

dbname : 
named_or_kw | named_or_kw ATSIGN named_or_kw {sprintf($<str>$,"%s@%s",$<str>1,$<str>3);}
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
				strdup(buff);

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
			the_form.snames.snames_len-1].name =strdup(ptr);

	in_screen_section=1; 
	}  screens_rest
;

screens_rest: op_size 
		{ ignorekw=1; 
		lineno=0; scr++; if (scr>1) newscreen=1; } 
	OPEN_BRACE { lineno=0; } 
	screen_layout 
	CLOSE_BRACE 
		{ ignorekw=0; if (lineno>the_form.maxline) the_form.maxline=lineno;in_screen_section=0;} 
	op_end 
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
		/* printf("Set to %d %d\n",the_form.maxcol,the_form.maxline); */
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

some_text: named_or_kw {
	int a;
	static char buff[256];
	strcpy(buff,$<str>1);

	for (a=0;a<strlen(buff);a++) {
		if (buff[a]=='_') buff[a]=' ';
	}
	strcpy($<str>$,buff);
}
;

screen_element : 
some_text {
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	     A4GL_add_field("_label",1+colno-strlen($<str>1),lineno,strlen($<str>1),scr,0,$<str>1);
}
| field  
| CH {
	char buff[256];
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	strcpy(buff,$<str>1);
	if (buff[0]=='\n') A4GL_add_field("_label",1+colno-1,lineno,1,scr,0,$<str>1);
	else A4GL_add_field("_label",1+colno-strlen($<str>1),lineno,1,scr,0,$<str>1);
}
| PIPE {
	char buff[256];
	strcpy(buff,$<str>1);
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (buff[0]=='\n') A4GL_add_field("_label",1+colno-1,lineno,1,scr,0,$<str>1);
	else A4GL_add_field("_label",1+colno-strlen($<str>1),lineno,1,scr,0,$<str>1);
}


| CHAR_VALUE {
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	     A4GL_add_field("_label",1+colno-strlen($<str>1),lineno,strlen($<str>1),scr,0,$<str>1);
} 

;


field : 
OPEN_SQUARE 
{
	fstart=colno;
	openwith='[';
}
field_element 
CLOSE_SQUARE
{
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (openwith=='[')
		A4GL_add_field($<str>3,fstart+1,lineno,colno-fstart-1,scr,3,"");
	else
		A4GL_add_field($<str>3,fstart+1,lineno,colno-fstart-1,scr,2,"");
};


field_element : 
field_tag_name {
	strcpy($<str>$,$<str>1);
} 
| 
field_element PIPE  
{
	/* 
field elements = name x y width screen_no endswith'|' 
*/
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	if (openwith=='[')
		A4GL_add_field($<str>1,fstart+1,lineno,colno-fstart-1,scr,1,"");
	else
		A4GL_add_field($<str>1,fstart+1,lineno,colno-fstart-1,scr,0,"");
	fstart=colno;
	openwith='|';
}
field_tag_name 
{
	strcpy($<str>$,$<str>4);
};



op_table_section : 
| TABLES table_def_list  op_end;

table_def_list : 
table_def 
| table_def_list table_def
| table_def_list COMMA table_def
;

table_def : named_or_kw opequal { 
A4GL_make_downshift($<str>1);
A4GL_make_downshift($<str>2);
A4GL_add_table($<str>2,$<str>1); 
} 
;

opequal :  {strcpy($<str>$,"");}
| EQUAL table_qualifier  {sprintf($<str>$,"%s",$<str>2);}
;

table_qualifier : named_or_kw {sprintf($<str>$,"%s", $<str>1);}
| named_or_kw COLON named_or_kw {sprintf($<str>$,"%s%s%s", $<str>1, $<str>2, $<str>3);}
| named_or_kw ATSIGN named_or_kw 
        {sprintf($<str>$,"%s%s%s", $<str>1, $<str>2, $<str>3);}
| named_or_kw ATSIGN named_or_kw COLON named_or_kw {sprintf($<str>$,"%s%s%s%s%s", $<str>1, $<str>2, $<str>3,$<str>4,$<str>5);}
| named_or_kw DOT named_or_kw {sprintf($<str>$,"%s%s%s", $<str>1, $<str>2, $<str>3);}
;



attribute_section :  
	ATTRIBUTES field_tag_list op_end
;

field_tag_list : 
field_tag | field_tag_list field_tag
;

field_tag : 
field_tag_name {
	A4GL_make_downshift($<str>1);
	strcpy(currftag,$<str>1);
	fldno=A4GL_find_field($<str>1);
} 
fpart_list SEMICOLON
;

fpart_list : 
fpart | fpart_list fpart;

fpart : 
EQUAL { 
A4GL_init_fld();
}
field_type op_att 
{
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);

	fld->colour=FA_C_WHITE;
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
op_field_desc
{
	if (fld->datatype==90&&!(A4GL_has_str_attribute(fld,FA_S_DEFAULT)))
	{
	        extern FILE *yyin;

			A4GL_debug("Currpos = %ld\n",ftell(yyin));
	        yyerror("A button must have a default value for its caption");
	        YYERROR;
	}
	A4GL_set_field(currftag,fld);
};



op_att : 
| OPEN_SQUARE NUMBER_VALUE CLOSE_SQUARE {
	fld->subscripts[0]=atoi($<str>2);
} 
| 
OPEN_SQUARE NUMBER_VALUE COMMA NUMBER_VALUE CLOSE_SQUARE {
	fld->subscripts[0]=atoi($<str>2);
	fld->subscripts[1]=atoi($<str>4);
};



field_datatype_null : 
		field_datatype KWNOT KW_NULL 	{ sprintf($<str>$,"%d",atoi($<str>1)+256); }
		| field_datatype  		{ strcpy($<str>$,$<str>1); }
;

field_datatype : {strcpy($<str>$,"0");}
	| 	TYPE LIKE named_or_kw DOT named_or_kw {
			sprintf($<str>$,"%d",A4GLF_getdatatype_fcompile($<str>5,$<str>3));
		}
	| 	TYPE LIKE named_or_kw {
			sprintf($<str>$,"%d",A4GLF_getdatatype_fcompile($<str>3,""));
		}
	| 	TYPE datatype {
			strcpy($<str>$,$<str>2);
		}
;

field_type : FORMONLY DOT field_name field_datatype_null {
	fld->tabname=strdup("formonly");
	fld->colname=strdup($<str>3);
        fld->datatype=atoi($<str>4);
        fld->dtype_size=dtype_size;
}
| named_or_kw DOT named_or_kw {
	fld->tabname=strdup($<str>1); 
	fld->colname=strdup($<str>3);
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
}
| named_or_kw {
	fld->colname=strdup($<str>1);
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
};


op_field_desc : 
| COMMA op_desc_list
;

op_desc_list : 
desc | op_desc_list COMMA desc;

desc :  
AUTONEXT { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
| COLOR EQUAL colors  op_where {
		if ($<expr>4==0) 
			fld->colour=atoi($<str>3); 
		else  {
			int a;
			fld->colours.colours_len++;
			a=fld->colours.colours_len;
			fld->colours.colours_val=realloc(fld->colours.colours_val,a);
			fld->colours.colours_val[a-1].colour=atoi($<str>3);
			fld->colours.colours_val[a-1].whereexpr=$<expr>4;
		}
} 
| COMMENTS EQUAL CHAR_VALUE { A4GL_add_str_attr(fld,FA_S_COMMENTS,$<str>3); }
| DEFAULT EQUAL def_val { A4GL_add_str_attr(fld,FA_S_DEFAULT,$<str>3); }
| DISPLAY LIKE named_or_kw {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
| DISPLAY LIKE named_or_kw DOT named_or_kw {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
| DOWNSHIFT { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
| UPSHIFT { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
| FORMAT EQUAL CHAR_VALUE { A4GL_add_str_attr(fld,FA_S_FORMAT,$<str>3); }
| INCLUDE EQUAL OPEN_BRACKET incl_list CLOSE_BRACKET { sprintf($<str>$,"\n%s",$<str>4); A4GL_add_str_attr(fld,FA_S_INCLUDE,$<str>$); }
| WIDGET EQUAL CHAR_VALUE { A4GL_add_str_attr(fld,FA_S_WIDGET,$<str>3); }
| CONFIG EQUAL CHAR_VALUE { A4GL_add_str_attr(fld,FA_S_CONFIG,$<str>3); }
| INVISIBLE { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
| DYNAMIC KW_SIZE EQUAL NUMBER_VALUE { fld->dynamic=atoi($<str>4);
A4GL_debug("fld->dynamic=%d",fld->dynamic); }
| DYNAMIC  { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
| SQLONLY  { printf("Warining %s is not implemented for 4GL\n",$<str>1); }
| NOENTRY { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
| PICTURE EQUAL CHAR_VALUE { A4GL_add_str_attr(fld,FA_S_PICTURE,$<str>3); }
| PROGRAM EQUAL CHAR_VALUE { A4GL_add_str_attr(fld,FA_S_PROGRAM,$<str>3); }
| REQUIRED {
	A4GL_add_bool_attr(fld,FA_B_REQUIRED);
}
| REVERSE {
	A4GL_add_bool_attr(fld,FA_B_REVERSE);
}
| VERIFY {
	A4GL_add_bool_attr(fld,FA_B_VERIFY);
}
| WORDWRAP  {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
}
| WORDWRAP  COMPRESS {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
	A4GL_add_bool_attr(fld,FA_B_COMPRESS);
}
| WORDWRAP NONCOMPRESS {
	A4GL_add_bool_attr(fld,FA_B_WORDWRAP);
};


def_val : 
CHAR_VALUE
| NUMBER_VALUE 
| SQL_VAR {sprintf($<str>$,"\n%s",$<str>1);}
;
colors : color | colors color {
sprintf($<str>$,"%d",atoi($<str>1)+atoi($<str>2));
}
;

color : 
BLACK {
	strcpy($<str>$,"0");
}
| BLUE {
	strcpy($<str>$,"4");
}
| GREEN {
	strcpy($<str>$,"2");
}
| CYAN {
	strcpy($<str>$,"6"); 
}
| RED {
	strcpy($<str>$,"1");
}
| MAGENTA {
	strcpy($<str>$,"5"); 
}
| WHITE {
	strcpy($<str>$,"7");
}
| YELLOW {
	strcpy($<str>$,"3");
}
| REVERSE {
	sprintf($<str>$,"%d",A4GL_get_attr_from_string("REVERSE"));
}
| LEFT {
	sprintf($<str>$,"%d",A4GL_get_attr_from_string("LEFT"));
}
| BLINK {
	sprintf($<str>$,"%d",A4GL_get_attr_from_string("BLINK"));
}
| UNDERLINE {
	sprintf($<str>$,"%d",A4GL_get_attr_from_string("UNDERLINE"));
};

op_instruction_section : 
| INSTRUCTIONS {
} 
instruct_opts op_end;

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
	the_form.delim=strdup(buff);
}
| KW_SCREEN RECORD {
A4GL_add_srec();
} srec_dim OPEN_BRACKET field_list CLOSE_BRACKET op_ltype op_semi
| KW_PANEL OPEN_BRACKET NUMBER_VALUE COMMA NUMBER_VALUE CLOSE_BRACKET TO OPEN_BRACKET NUMBER_VALUE COMMA NUMBER_VALUE CLOSE_BRACKET 
;

op_ltype : | AS LISTBOX;
 
op_semi: | SEMICOLON;

srec_dim : 
named_or_kw  {
   A4GL_set_dim_srec($<str>1,1);
}
| named_or_kw OPEN_SQUARE NUMBER_VALUE CLOSE_SQUARE {
   A4GL_set_dim_srec($<str>1,atoi($<str>3));
};


field_list : 
field_list_element {
	sprintf($<str>$,"%s",$<str>1);
} 
| field_list COMMA field_list_element {
	sprintf($<str>$,"%s,%s",$<str>1,$<str>3);
};

field_list_item :
named_or_kw	
{A4GL_add_srec_attribute("",$<str>1,""); }
| named_or_kw DOT named_or_kw	 
{A4GL_add_srec_attribute($<str>1,$<str>3,""); }
| FORMONLY DOT named_or_kw	 
{A4GL_add_srec_attribute("formonly",$<str>3,""); }
| named_or_kw DOT STAR 
{A4GL_add_srec_attribute($<str>1,"*",""); }
| FORMONLY DOT STAR 
{A4GL_add_srec_attribute("formonly","*",""); }
;

field_list_element :
field_list_item  | field_list_item THROUGH field_list_item {A4GL_add_srec_attribute("","","THROUGH");} 
;


field_name : named_or_kw {
	strcpy($<str>$,$<str>1);
}
;

field_tag_name : 
named_or_kw {
	strcpy($<str>$,$<str>1);
	A4GL_make_downshift($<str>$);
	}
	;

datatype : 
KW_CHAR {
	strcpy($<str>$,"0");
	dtype_size=0;
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
	strcpy($<str>$,"5");
	dtype_size=atoi($<str>2);
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


number_value : NUMBER_VALUE | PLUS NUMBER_VALUE | MINUS NUMBER_VALUE {sprintf($<str>$,"-%s",$<str>2);}
;


incl_entry : 
CHAR_VALUE   { strcpy($<str>$,A4GL_char_val($<str>1)); }
| NAMED   {strcpy($<str>$,$<str>1); }
| NAMED TO NAMED  {sprintf($<str>$,"%s\t%s",$<str>1,$<str>3); }
| CH   {strcpy($<str>$,$<str>1);}
| number_value 
| number_value TO number_value {
	sprintf($<str>$,"%s\t%s",$<str>1,$<str>3);
}
| CHAR_VALUE TO CHAR_VALUE {
	sprintf($<str>$,"%s\t",A4GL_char_val($<str>1));
	sprintf($<str>$,"%s%s",$<str>$,A4GL_char_val($<str>3));
}
| KW_NULL {
	sprintf($<str>$,"NULL");
}

;

opt_dec_ext : {strcpy($<str>$,"");}
	| OPEN_BRACKET NUMBER_VALUE CLOSE_BRACKET {sprintf($<str>$,"16.%d",atoi($<str>2));}
	| OPEN_BRACKET NUMBER_VALUE COMMA NUMBER_VALUE CLOSE_BRACKET {sprintf($<str>$,"%d.%d",atoi($<str>2),atoi($<str>4));}
;

opt_int_ext : {strcpy($<str>$,"");}
	| int_start TO int_end
	{
	sprintf($<str>$,"%d",(atoi($<str>1)*16)+atoi($<str>3));
	}
;


opt_unit_size: {
A4GL_debug("Nothing in fraction - assume 2");
strcpy($<str>$,"2");} |  OPEN_BRACKET NUMBER_VALUE CLOSE_BRACKET {
A4GL_debug("    %s",$<str>2);
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
  A4GL_debug("opt_frac returns %s",$<str>2);
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
A4GL_debug("opt_frac returns %s",$<str>2);
sprintf($<str>$,"%d",atoi($<str>2)+6); }
;

opt_frac: {
A4GL_debug("Nothing in fraction - assume 2");
strcpy($<str>$,"2");} |  OPEN_BRACKET dtfrac CLOSE_BRACKET {
A4GL_debug("Read fraction .. ");
A4GL_debug("    %s",$<str>2);
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
	value COMPARISON value {
		$<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2);
		}
	| value EQUAL value {
		$<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2);
	}
	| value KWNULLCHK {
		void *p;
		p=create_char_expr("ISNULL");
		$<expr>$=create_expr_comp_expr($<expr>1,p,"ISNULL");
	}
	| value KWNOTNULLCHK {
		void *p;
		p=create_char_expr("ISNOTNULL");
		$<expr>$=create_expr_comp_expr($<expr>1,p,"ISNOTNULL");
	}
	| value  {
		$<expr>$=$<expr>1;
			//create_expr_comp_expr($<expr>1,$<expr>3,$<str>2);
	}
	| value KWBETWEEN value KWAND value {
		$<expr>$=create_list_expr();
		add_list_expr($<expr>$,$<expr>3);
		add_list_expr($<expr>$,$<expr>5);
		$<expr>$=create_expr_comp_expr($<expr>1,$<expr>$,"BETWEEN");
	}
	| value KWIN OPEN_BRACKET value_list CLOSE_BRACKET {
		$<expr>$=create_expr_comp_expr($<expr>1,$<expr>4,"IN");
	}
	| KWNOT clause {
		$<expr>$=create_not_expr($<expr>2);
	}
	| OPEN_BRACKET clause CLOSE_BRACKET {
		$<expr>$=$<expr>2;
	}
;

value : fieldidentifier  {$<expr>$=create_field_expr($<str>1);}
| NUMBER_VALUE  {$<expr>$=create_int_expr(atoi($<str>1));}
| CHAR_VALUE    {$<expr>$=create_char_expr($<str>1);}
| XVAL          {$<expr>$=create_special_expr($<str>1);}
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

any_kword : 
 AS
| AUTONEXT
| BLACK
| BLINK
| BLUE
| KWOR
| KWAND
| COMPARISON
| BUTTON
| BY
| COLOR
| COMMENT
| COMMENTS
| COMPRESS
| CONFIG
| CYAN
| DATABASE
| DATETIME
| DEFAULT
| DELIMITERS
| DOWNSHIFT
| DYNAMIC 
| FORMAT
| GREEN
| INCLUDE
| INPUT
| INTERVAL
| INVISIBLE
| KW_BYTE 
| KW_CHAR
| KW_DATE
| KW_DECIMAL
| KW_FLOAT
| KW_INT
| KW_NULL
| KW_PANEL
| KW_SCREEN
| KW_SCREEN_TITLE
| KW_SIZE 
| KW_TEXT 
| LEFT
| LISTBOX
| MAGENTA
| MONEY
| NOENTRY
| NONCOMPRESS 
| KWNOT 
| PICTURE
| PROGRAM
| RECORD 
| RED
| REQUIRED
| REVERSE
| SERIAL 
| SMALLFLOAT
| SMALLINT
| SQLONLY  
| SQL_VAR
| TABLES 
| THROUGH 
| TITLE
| TO  
| UNDERLINE
| UPSHIFT
| VARCHAR
| VERIFY 
| WHITE
| WIDGET 
| WITHOUT
| WORDWRAP 
| YELLOW
| TYPE
| LIKE
|YEAR 
|MONTH 
|DAY 
|HOUR 
|MINUTE 
|SECOND 
|FRACTION

;
%%


#include "lex.yy.c"



/* =========================== EOF ============================ */


