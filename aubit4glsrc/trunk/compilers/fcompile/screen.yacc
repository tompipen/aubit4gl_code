%{
#include "form_x.h"
#include "../../lib/libincl/compiler.h"
#include <stdio.h>
#include <string.h>
#include "../../lib/libincl/dbform.h"
#include "../../lib/libincl/debug.h"
extern struct struct_scr_field *fld;
int graphics_mode=0;
extern int ignorekw;
extern int lineno;
extern int colno;
extern int scr;
int in_comment;
long fileseek=0;
extern struct_form the_form;
//extern int maxcol;
//extern int maxline;
extern int newscreen;
extern int fldno;
extern int fstart;
extern int openwith;
extern char currftag[256];
extern char *outputfilename;
char *chk_alias(char *s);
char *char_val(char*s);
extern char *tablist[];
extern FILE *yyin;
int in_screen_section=0;

int add_field (char *s, int x, int y, int wid, int scr, int delim,char *label);
%}
%start form_def
%union	  {
	char	str[1024];
}
%token <str> 
%token CH
%token INSTRUCTIONS ATTRIBUTES DATABASE BY KW_SCREEN_TITLE KW_SCREEN KW_SIZE OPEN_SQUARE KW_END CLOSE_SQUARE NUMBER_VALUE NAMED OPEN_BRACE CLOSE_BRACE TITLE
FORMONLY COMMENT
%token DYNAMIC COLON ATSIGN DOT WITHOUT KW_NULL INPUT TABLES PIPE EQUAL CHAR_VALUE
%token SEMICOLON
%token OPEN_BRACKET CLOSE_BRACKET STAR PLUS MINUS RECORD COMMA THROUGH LIKE TYPE NOT DELIMITERS
%token KW_CHAR KW_INT KW_DATE KW_FLOAT SMALLFLOAT SMALLINT KW_DECIMAL MONEY DATETIME INTERVAL
%token BLACK BLUE GREEN CYAN RED MAGENTA WHITE YELLOW REVERSE LEFT BLINK UNDERLINE
%token   AUTONEXT COLOR COMMENTS DEFAULT DISPLAY DISPLAY DOWNSHIFT UPSHIFT FORMAT INCLUDE INVISIBLE NOENTRY PICTURE PROGRAM
REQUIRED REVERSE VERIFY WORDWRAP COMPRESS NONCOMPRESS TO  AS
%token SERIAL KW_BYTE KW_TEXT VARCHAR SQL_VAR
%token SQLONLY  WIDGET CONFIG

/* extensions */
%token LISTBOX BUTTON KW_PANEL

%%

/* rules */
form_def : 
database_section screen_section op_table_section attribute_section op_instruction_section {write_form();}
;
database_section :
DATABASE FORMONLY {the_form.dbname=strdup("formonly");}
| DATABASE dbname WITHOUT KW_NULL INPUT {the_form.dbname=($<str>2);}
| DATABASE FORMONLY WITHOUT KW_NULL INPUT {the_form.dbname=("formonly");}
| DATABASE dbname {the_form.dbname=strdup($<str>2);}
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
	}  screens_rest;
| KW_SCREEN_TITLE CHAR_VALUE {
	char buff[256];
	char *ptr;
	the_form.snames.snames_len++;the_form.snames.snames_val=
		realloc(the_form.snames.snames_val, 
			(the_form.snames.snames_len)*
				sizeof(struct screen_name));
		sprintf(buff,"%s", $<str>3);
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
	c=atoi($<str>4);
	l=atoi($<str>2);
        if (c>the_form.maxcol) the_form.maxcol=c;
        if (l>the_form.maxline) the_form.maxline=l;
	//printf("Set to %d %d\n",the_form.maxcol,the_form.maxline);
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

screen_element : 
some_text {
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	add_field("_label",1+colno-strlen($<str>1),lineno,strlen($<str>1),scr,0,$<str>1);
} 
| field  
| CH {
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	add_field("_label",1+colno-strlen($<str>1),lineno,1,scr,0,$<str>1);
}
| PIPE {
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	add_field("_label",1+colno-strlen($<str>1),lineno,1,scr,0,$<str>1);
}


| CHAR_VALUE {
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	add_field("_label",1+colno-strlen($<str>1),lineno,strlen($<str>1),scr,0,$<str>1);
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
		add_field($<str>3,fstart+1,lineno,colno-fstart-1,scr,3,"");
	else
		add_field($<str>3,fstart+1,lineno,colno-fstart-1,scr,2,"");
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
		add_field($<str>1,fstart+1,lineno,colno-fstart-1,scr,1,"");
	else
		add_field($<str>1,fstart+1,lineno,colno-fstart-1,scr,0,"");
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
make_downshift($<str>1);
make_downshift($<str>2);
add_table($<str>2,$<str>1); 
} 
;

opequal :  {strcpy($<str>$,"");}
| EQUAL table_qualifier  {sprintf($<str>$,"%s",$<str>2);}

table_qualifier : named_or_kw {sprintf($<str>$,"%s", $<str>1);}
| named_or_kw COLON named_or_kw {sprintf($<str>$,"%s%s%s", $<str>1, $<str>2, $<str>3);}
| named_or_kw ATSIGN named_or_kw 
        {sprintf($<str>$,"%s%s%s", $<str>1, $<str>2, $<str>3);}
| named_or_kw ATSIGN named_or_kw COLON named_or_kw {sprintf($<str>$,"%s%s%s%s%s", $<str>1, $<str>2, $<str>3,$<str>4,$<str>5);}
| named_or_kw DOT named_or_kw {sprintf($<str>$,"%s%s%s", $<str>1, $<str>2, $<str>3);}
;

opowner : {strcpy($<str>$,"");}
| named_or_kw DOT {sprintf($<str>$,"%s%s",$<str>1,$<str>2);}
| CHAR_VALUE DOT {sprintf($<str>$,"%s%s",$<str>1,$<str>2);}
;


attribute_section :  
ATTRIBUTES field_tag_list op_end;

field_tag_list : 
field_tag | field_tag_list field_tag;

field_tag : 
field_tag_name {
	make_downshift($<str>1);
	strcpy(currftag,$<str>1);
	fldno=find_field($<str>1);
} 
fpart_list SEMICOLON
;

fpart_list : 
fpart | fpart_list fpart;

fpart : 
EQUAL { 
init_fld();
} 
field_type op_att {
	make_downshift(fld->tabname);
	make_downshift(fld->colname);

	fld->colour=FA_C_WHITE;
	debug("add color %d\n",FA_C_WHITE);
}
op_field_desc 
{
if (fld->datatype==90&&!(has_str_attribute(fld,FA_S_DEFAULT))) {
        debug("Currpos = %ld\n",ftell(yyin));
        yyerror("A button must have a default value for its caption");
        YYERROR;
}
	set_field(currftag,fld);
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

field_type :
FORMONLY DOT field_name {
	fld->tabname=strdup("formonly");
	fld->colname=strdup($<str>3);
}
| FORMONLY DOT field_name TYPE datatype {
	fld->tabname=strdup("formonly");
	fld->colname=strdup($<str>3);
	fld->datatype=atoi($<str>5);
}
| FORMONLY DOT field_name TYPE datatype NOT KW_NULL {
	fld->tabname=strdup("formonly");
	fld->colname=strdup($<str>3);
	fld->datatype=atoi($<str>5)+256;
}
| FORMONLY DOT field_name TYPE LIKE named_or_kw {
	fld->tabname=strdup("formonly");
	fld->colname=strdup($<str>3);
}
| FORMONLY DOT field_name TYPE LIKE named_or_kw DOT named_or_kw {
	fld->tabname=strdup("formonly");
	fld->colname=strdup($<str>3);
	exitwith("NEEDS FIXING");
}
| named_or_kw DOT named_or_kw {
	fld->tabname=strdup($<str>1); 
	fld->colname=strdup($<str>3);
        fld->datatype=getdatatype(fld->colname,fld->tabname);
}
| named_or_kw {
	fld->colname=strdup($<str>1);
        fld->datatype=getdatatype(fld->colname,fld->tabname);
};


op_field_desc : 
| COMMA op_desc_list
;

op_desc_list : 
desc | op_desc_list COMMA desc;

desc :  
AUTONEXT {
	add_bool_attr(fld,FA_B_AUTONEXT);
}
| COLOR EQUAL colors {
	fld->colour=atoi($<str>3);
}
| COMMENTS EQUAL CHAR_VALUE {
	add_str_attr(fld,FA_S_COMMENTS,$<str>3);
}
| DEFAULT EQUAL def_val {
	add_str_attr(fld,FA_S_DEFAULT,$<str>3);
}
| DISPLAY LIKE named_or_kw
| DISPLAY LIKE named_or_kw DOT named_or_kw
| DOWNSHIFT {
	add_bool_attr(fld,FA_B_DOWNSHIFT);
}
| UPSHIFT {
	add_bool_attr(fld,FA_B_UPSHIFT);
}
| FORMAT EQUAL CHAR_VALUE {
	add_str_attr(fld,FA_S_FORMAT,$<str>3);
}
| INCLUDE EQUAL OPEN_BRACKET incl_list CLOSE_BRACKET {
	sprintf($<str>$,"\n%s",$<str>4);
	add_str_attr(fld,FA_S_INCLUDE,$<str>$);
}
| WIDGET EQUAL CHAR_VALUE {
	add_str_attr(fld,FA_S_WIDGET,$<str>3);
}
| CONFIG EQUAL CHAR_VALUE {
	add_str_attr(fld,FA_S_CONFIG,$<str>3);
}
| INVISIBLE {
	add_bool_attr(fld,FA_B_INVISIBLE);
}
| DYNAMIC KW_SIZE EQUAL NUMBER_VALUE { fld->dynamic=atoi($<str>4);
debug("fld->dynamic=%d",fld->dynamic);
 }
| DYNAMIC  { fld->dynamic=-1; debug("dynamic=-1"); }
| SQLONLY  {
printf("Warining %s is not implemented for 4GL\n",$<str>1);
}
| NOENTRY {
	add_bool_attr(fld,FA_B_NOENTRY);
}
| PICTURE EQUAL CHAR_VALUE {
	add_str_attr(fld,FA_S_PICTURE,$<str>3);
}
| PROGRAM EQUAL CHAR_VALUE {
	add_str_attr(fld,FA_S_PROGRAM,$<str>3);
}
| REQUIRED {
	add_bool_attr(fld,FA_B_REQUIRED);
}
| REVERSE {
	add_bool_attr(fld,FA_B_REVERSE);
}
| VERIFY {
	add_bool_attr(fld,FA_B_VERIFY);
}
| WORDWRAP  {
	add_bool_attr(fld,FA_B_WORDWRAP);
}
| WORDWRAP  COMPRESS {
	add_bool_attr(fld,FA_B_WORDWRAP);
	add_bool_attr(fld,FA_B_COMPRESS);
}
| WORDWRAP NONCOMPRESS {
	add_bool_attr(fld,FA_B_WORDWRAP);
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
	sprintf($<str>$,"%d",A_REVERSE);
}
| LEFT {
	sprintf($<str>$,"%d",A_LEFT);
}
| BLINK {
	sprintf($<str>$,"%d",A_BLINK);
}
| UNDERLINE {
	sprintf($<str>$,"%d",A_UNDERLINE);
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
	strcpy(buff,char_val($<str>2));
	if (strlen(buff)==1) {
		buff[1]=buff[0];
		buff[2]=buff[0];
		buff[3]=0;
	}
	the_form.delim=strdup(buff);
}
| KW_SCREEN RECORD {
add_srec();
} srec_dim OPEN_BRACKET field_list CLOSE_BRACKET op_ltype op_semi
| KW_PANEL OPEN_BRACKET NUMBER_VALUE COMMA NUMBER_VALUE CLOSE_BRACKET TO OPEN_BRACKET NUMBER_VALUE COMMA NUMBER_VALUE CLOSE_BRACKET 
;

op_ltype : | AS LISTBOX;
 
op_semi: | SEMICOLON;

srec_dim : 
named_or_kw  {
   set_dim_srec($<str>1,1);
}
| named_or_kw OPEN_SQUARE NUMBER_VALUE CLOSE_SQUARE {
   set_dim_srec($<str>1,atoi($<str>3));
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
{add_srec_attribute("",$<str>1,""); }
| named_or_kw DOT named_or_kw	 
{add_srec_attribute($<str>1,$<str>3,""); }
| FORMONLY DOT named_or_kw	 
{add_srec_attribute("formonly",$<str>3,""); }
| named_or_kw DOT STAR 
{add_srec_attribute($<str>1,"*",""); }
| FORMONLY DOT STAR 
{add_srec_attribute("formonly","*",""); }
;

field_list_element :
field_list_item  | field_list_item THROUGH field_list_item {add_srec_attribute("","","THROUGH");} 
;


field_name : 
named_or_kw;

field_tag_name : 
named_or_kw {
	strcpy($<str>$,$<str>1);
	make_downshift($<str>$);
	}
	;

datatype : 
KW_CHAR {
	strcpy($<str>$,"0");
} 
| KW_INT {
	strcpy($<str>$,"2");
} 
| KW_DATE {
	strcpy($<str>$,"7");
} 
| KW_FLOAT {
	strcpy($<str>$,"3");
} 
| SMALLFLOAT {
	strcpy($<str>$,"4");
} 
| SMALLINT {
	strcpy($<str>$,"1");
} 
| KW_DECIMAL opt_dec_ext{
	strcpy($<str>$,"5");
} 
| MONEY opt_dec_ext {
	strcpy($<str>$,"8");
} 
| DATETIME {
	strcpy($<str>$,"10");
} 
| INTERVAL {
	strcpy($<str>$,"14");
}
| SERIAL {
	strcpy($<str>$,"6");
}
| KW_BYTE {
	strcpy($<str>$,"11");
}
| KW_TEXT {
	strcpy($<str>$,"12");
}
| VARCHAR { strcpy($<str>$,"13");}
| BUTTON { strcpy($<str>$,"90");}

;


incl_list : incl_entry | incl_list COMMA incl_entry {
	sprintf($<str>$,"%s\n%s",$<str>1,$<str>3);
};


number_value : NUMBER_VALUE | PLUS NUMBER_VALUE | MINUS NUMBER_VALUE {sprintf($<str>$,"-%s",$<str>2);}
;


incl_entry : 
CHAR_VALUE   { strcpy($<str>$,char_val($<str>1)); }
| NAMED   {strcpy($<str>$,$<str>1); }
| CH   {strcpy($<str>$,$<str>1);}
| number_value 
| number_value TO number_value {
	sprintf($<str>$,"%s\t%s",$<str>1,$<str>3);
}
| CHAR_VALUE TO CHAR_VALUE {
	sprintf($<str>$,"%s\t",char_val($<str>1));
	sprintf($<str>$,"%s%s",$<str>$,char_val($<str>3));
}
| KW_NULL {
	sprintf($<str>$,"NULL");
};

opt_dec_ext : {strcpy($<str>$,"");}
	| OPEN_BRACKET NUMBER_VALUE CLOSE_BRACKET {sprintf($<str>$,"16.%d",atoi($<str>2));}
	| OPEN_BRACKET NUMBER_VALUE COMMA NUMBER_VALUE CLOSE_BRACKET {sprintf($<str>$,"%d.%d",atoi($<str>2),atoi($<str>4));}
;


any_kword : 
 AS
| AUTONEXT
| BLACK
| BLINK
| BLUE
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
| DISPLAY
| DOWNSHIFT
| DYNAMIC 
| FORMAT
| FORMONLY 
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
| LIKE 
| LISTBOX
| MAGENTA
| MONEY
| NOENTRY
| NONCOMPRESS 
| NOT 
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
| TYPE 
| UNDERLINE
| UPSHIFT
| VARCHAR 
| VERIFY 
| WHITE
| WIDGET 
| WITHOUT
| WORDWRAP 
| YELLOW

;
%%
#include "lex.yy.c"







