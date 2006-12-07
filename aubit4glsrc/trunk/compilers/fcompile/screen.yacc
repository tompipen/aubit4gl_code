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
int A4GL_get_attr_from_string (char *s);
/* extern FILE *yyin; */
int in_screen_section=0;
int dtype_size=0;
char *rm_dup_quotes(char *s) ;
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
%token GRAPH_CH
%token KW_COMPOSITES 
%token INSTRUCTIONS ATTRIBUTES DATABASE BY KW_SCREEN_TITLE KW_SCREEN KW_SIZE OPEN_SQUARE KW_END CLOSE_SQUARE NUMBER_VALUE NAMED  OPEN_BRACE CLOSE_BRACE TITLE
FORMONLY COMMENT
%token DYNAMIC COLON ATSIGN DOT WITHOUT KW_NULL INPUT TABLES PIPE EQUAL CHAR_VALUE
%token SEMICOLON LOOKUP JOINING
%token OPEN_BRACKET CLOSE_BRACKET STAR DIVIDE PLUS MINUS RECORD COMMA THROUGH TYPE DELIMITERS
%token KW_CHAR KW_INT KW_DATE KW_FLOAT SMALLFLOAT SMALLINT KW_DECIMAL MONEY DATETIME INTERVAL LIKE
%token BLACK BLUE GREEN CYAN RED MAGENTA WHITE YELLOW NORMAL REVERSE LEFT BOLD BLINK UNDERLINE DIM
%token   AUTONEXT COLOR COMMENTS DEFAULT VALIDATE DISPLAY DOWNSHIFT UPSHIFT FORMAT INCLUDE INVISIBLE NOUPDATE NOENTRY PICTURE PROGRAM REQUIRED  QUERYCLEAR VERIFY WORDWRAP COMPRESS NONCOMPRESS TO  AS
%token SERIAL KW_BYTE KW_TEXT VARCHAR SQL_VAR KW_NONSPACE
%token SQLONLY  WIDGET CONFIG KW_NL
%token COMPARISON LESSTHAN GREATERTHAN KWOR KWAND KWAND1 KWWHERE KWNOT KWBETWEEN KWIN XVAL KWNULLCHK KWNOTNULLCHK
%token YEAR MONTH DAY HOUR MINUTE SECOND FRACTION
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


%%

/* rules */
form_def : 
database_section screen_section op_table_section attribute_section op_instruction_section {A4GL_write_form();}
;
database_section :
DATABASE FORMONLY {the_form.dbname=acl_strdup("formonly");}
| DATABASE dbname WITHOUT KW_NULL INPUT {the_form.dbname=($<str>2);
if (A4GLF_open_db($<str>2)) {
		yyerror("Unable to connect to database\n");
}
}
| DATABASE FORMONLY WITHOUT KW_NULL INPUT {the_form.dbname=("formonly");}
| DATABASE dbname {the_form.dbname=acl_strdup($<str>2);
if (A4GLF_open_db($<str>2)) {
		yyerror("Unable to connect to database\n");
}
}
;


named_or_kw_st :
	NAMED   
	| st_kword 
;

named_or_kw_any :
	NAMED   
	| any_kword 
;

dbname : 
	SPECIAL_DBNAME {sprintf($<str>$,acl_getenv("DBNAME"));} 
	| SPECIAL_DBNAME ATSIGN named_or_kw_any  {sprintf($<str>$,acl_getenv("DBNAME"));} 
	| named_or_kw_st
	| named_or_kw_st ATSIGN named_or_kw_any {SPRINTF2($<str>$,"%s@%s",$<str>1,$<str>3);}
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

some_text: named_or_kw_any {
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
	wchar_t wstr[256];			/* utf8 */
	size_t retc, mlen, wlen, width;		/* utf8 */
	mlen = strlen($<str>1);			/* utf8 */
	retc = mbstowcs(wstr, $<str>1, mlen+1);	/* utf8 */
	wlen = wcslen(wstr);			/* utf8 */
	width = wcswidth(wstr, wlen);		/* utf8 */
/* utf8 
        A4GL_add_field("_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	colno+=strlen($<str>1);
*/
        A4GL_add_field("_label",colno+1,lineno,wlen,scr,0,$<str>1); /* utf8 */
	colno+=width;						/* utf8 */
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
	wchar_t wstr[256];			/* utf8 */
	size_t retc, mlen, wlen, width;		/* utf8 */
	mlen = strlen($<str>1);			/* utf8 */
	retc = mbstowcs(wstr, $<str>1, mlen+1);	/* utf8 */
	wlen = wcslen(wstr);			/* utf8 */
	width = wcswidth(wstr, wlen);		/* utf8 */
/* utf8
	A4GL_add_field("_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	colno+=strlen($<str>1);
*/
	A4GL_add_field("_label",colno+1,lineno,width,scr,0,$<str>1); /* utf8 */
	colno+=width; 				/* utf8 */
	if (colno>the_form.maxcol) the_form.maxcol=colno; 
	if (lineno>the_form.maxline) the_form.maxline=lineno;
	ltab=0;
	}
} 

| ch_list {
	if (lineno) {
	wchar_t wstr[256];			/* utf8 */
	size_t retc, mlen, wlen, width;		/* utf8 */
	mlen = strlen($<str>1);			/* utf8 */
	retc = mbstowcs(wstr, $<str>1, mlen+1);	/* utf8 */
	wlen = wcslen(wstr);			/* utf8 */
	width = wcswidth(wstr, wlen);		/* utf8 */
/* utf8
	A4GL_add_field("_label",colno+1,lineno,strlen($<str>1),scr,0,$<str>1);
	colno+=strlen($<str>1);
*/
	A4GL_add_field("_label",colno+1,lineno,width,scr,0,$<str>1); /* utf8 */
	colno+=width; /* utf8 */
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

table_def : named_or_kw_any opequal { 
A4GL_make_downshift($<str>1);
A4GL_make_downshift($<str>2);
clr_status();
A4GL_add_table($<str>2,$<str>1); 
err_on_status();
} 
;

opequal :  {strcpy($<str>$,"");}
| EQUAL table_qualifier  {strcpy($<str>$,$<str>2); }
;

table_qualifier : named_or_kw_any {sprintf($<str>$,"%s", $<str>1);}
| named_or_kw_any COLON named_or_kw_any {sprintf($<str>$,"%s%s%s", $<str>1, $<str>2, $<str>3);}
| named_or_kw_any ATSIGN named_or_kw_any 
        {sprintf($<str>$,"%s%s%s", $<str>1, $<str>2, $<str>3);}
| named_or_kw_any ATSIGN named_or_kw_any COLON named_or_kw_any {sprintf($<str>$,"%s%s%s%s%s", $<str>1, $<str>2, $<str>3,$<str>4,$<str>5);}
| named_or_kw_any DOT named_or_kw_any {sprintf($<str>$,"%s%s%s", $<str>1, $<str>2, $<str>3);}
| CHAR_VALUE DOT named_or_kw_any
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
fpart_list 
SEMICOLON
;

fpart_list : 
fpart 
| fpart_list fpart
| fpart_list SEMICOLON fpart
;

fpart : 
EQUAL { 
A4GL_init_fld();
}
field_type op_att 
{
	A4GL_make_downshift(fld->tabname);
	A4GL_make_downshift(fld->colname);

	//fld->colour=FA_C_WHITE;
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
	if (!(A4GL_has_str_attribute(fld,FA_S_PICTURE)) && strcmp(the_form.dbname,"formonly")!=0 ) {
		char *p;
	
		p=A4GLSQL_syscolval_expr(fld->tabname,fld->colname,"PICTURE");
		if (p) {
			// Theres a picture in syscolval - but nothing in the form -
			// Use the syscolval one...
			A4GL_add_str_attr(fld,FA_S_PICTURE,p);
			//printf("Setting field picture from syscolval (%s)\n",p);
		}
	}

	A4GL_set_field(currftag,fld);
}
;



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
	| 	TYPE LIKE named_or_kw_any DOT named_or_kw_any {
			sprintf($<str>$,"%d",A4GLF_getdatatype_fcompile($<str>5,$<str>3));
		}
	| 	TYPE LIKE named_or_kw_any {
			sprintf($<str>$,"%d",A4GLF_getdatatype_fcompile($<str>3,""));
		}
	| 	TYPE datatype {
			strcpy($<str>$,$<str>2);
		}
;

field_type : FORMONLY DOT field_name field_datatype_null {
	fld->tabname=acl_strdup("formonly");
	fld->colname=acl_strdup($<str>3);
        fld->datatype=atoi($<str>4)&0xff;
	if (atoi($<str>4)&256) fld->not_null=1;
	else fld->not_null=0;
        fld->datatype=atoi($<str>4)&0xff;
        fld->dtype_size=dtype_size;
}
| DISPLAYONLY field_datatype_null {
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
| named_or_kw_any DOT named_or_kw_any {
	//printf("%s %s\n",$<str>1,$<str>3);
	fld->tabname=acl_strdup($<str>1); 
	fld->colname=acl_strdup($<str>3);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
| named_or_kw_any {
	fld->colname=acl_strdup($<str>1);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}

| STAR named_or_kw_any DOT named_or_kw_any {
	fld->tabname=acl_strdup($<str>2); 
	fld->colname=acl_strdup($<str>4);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
        //if (fld->datatype==DTYPE_SERIAL) { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
}
| STAR named_or_kw_any {
	fld->colname=acl_strdup($<str>2);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
}
;



lu_ft: field_tag_name 
;

lu_ft_eq_c:
	lu_ft_eq_c_i
	| lu_ft_eq_c COMMA lu_ft_eq_c_i
;
lu_ft_eq_c_i:
	lu_ft EQUAL lu_fc 
;

lu_fc: 	named_or_kw_any DOT named_or_kw_any
	| named_or_kw_any
;

lu_joincol:
 	named_or_kw_any DOT named_or_kw_any
	| named_or_kw_any
 	| STAR named_or_kw_any DOT named_or_kw_any
	| STAR named_or_kw_any
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
AUTONEXT { A4GL_add_bool_attr(fld,FA_B_AUTONEXT); }
| COLOR EQUAL colors  op_where {
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
| LOOKUP  lu_ft_eq_c lu_join lu_joincol 
| COMMENTS EQUAL CHAR_VALUE { A4GL_add_str_attr(fld,FA_S_COMMENTS,$<str>3); }
| DEFAULT EQUAL def_val { A4GL_add_str_attr(fld,FA_S_DEFAULT,$<str>3); }
| DISPLAY LIKE named_or_kw_any {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
| DISPLAY LIKE named_or_kw_any DOT named_or_kw_any {	A4GL_debug("WARNING : DISPLAY LIKE not really implemented");}
| VALIDATE LIKE named_or_kw_any {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
| VALIDATE LIKE named_or_kw_any DOT named_or_kw_any {	A4GL_debug("WARNING : VALIDATE LIKE not really implemented");}
| DOWNSHIFT { A4GL_add_bool_attr(fld,FA_B_DOWNSHIFT); }
| UPSHIFT { A4GL_add_bool_attr(fld,FA_B_UPSHIFT); }
| FORMAT EQUAL CHAR_VALUE { A4GL_add_str_attr(fld,FA_S_FORMAT,$<str>3); }
| INCLUDE EQUAL OPEN_BRACKET incl_list CLOSE_BRACKET { sprintf($<str>$,"\n%s",$<str>4); A4GL_add_str_attr(fld,FA_S_INCLUDE,$<str>$); }
| WIDGET EQUAL CHAR_VALUE { A4GL_add_str_attr(fld,FA_S_WIDGET,$<str>3); }
| CONFIG EQUAL CHAR_VALUE { A4GL_add_str_attr(fld,FA_S_CONFIG,$<str>3); }
| KW_ACTION EQUAL named_or_kw_any { A4GL_add_str_attr(fld,FA_S_ACTION,$<str>3); }
| INVISIBLE { A4GL_add_bool_attr(fld,FA_B_INVISIBLE); }
| DYNAMIC KW_SIZE EQUAL NUMBER_VALUE { fld->dynamic=atoi($<str>4);
A4GL_debug("fld->dynamic=%d",fld->dynamic); }
| DYNAMIC  { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
| SQLONLY  { printf("Warning %s is not implemented for 4GL\n",$<str>1); }
| NOENTRY { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
| NOUPDATE { A4GL_add_bool_attr(fld,FA_B_NOUPDATE); }
| PICTURE EQUAL CHAR_VALUE { A4GL_add_str_attr(fld,FA_S_PICTURE,$<str>3); }
| PROGRAM EQUAL CHAR_VALUE { A4GL_add_str_attr(fld,FA_S_PROGRAM,$<str>3); }
| REQUIRED {
	A4GL_add_bool_attr(fld,FA_B_REQUIRED);
}
| REVERSE {
	A4GL_add_bool_attr(fld,FA_B_REVERSE);
}
| VERIFY { A4GL_add_bool_attr(fld,FA_B_VERIFY); }
| QUERYCLEAR   /* ADD */
| KW_ZEROFILL   /* ADD */
| KW_RIGHT   /* ADD */
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
CHAR_VALUE {strcpy($<str>$,$<str>1);}
| NUMBER_VALUE  {strcpy($<str>$,$<str>1);}
| SQL_VAR {sprintf($<str>$,"\n%s",$<str>1);}
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
		strcpy($<str>$,$<str>1);
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
	the_form.delim=acl_strdup(buff);
}
| KW_SCREEN RECORD {
A4GL_add_srec();
} srec_dim OPEN_BRACKET srec_field_list CLOSE_BRACKET op_ltype op_semi
| KW_PANEL OPEN_BRACKET NUMBER_VALUE COMMA NUMBER_VALUE CLOSE_BRACKET TO OPEN_BRACKET NUMBER_VALUE COMMA NUMBER_VALUE CLOSE_BRACKET 
| composites
| master_of
| control_block 
;


op_ltype : | AS LISTBOX;
 
op_star: | STAR;

op_semi: | SEMICOLON;

srec_dim : named_or_kw_any  {
   A4GL_set_dim_srec($<str>1,1);
}
| named_or_kw_any OPEN_SQUARE NUMBER_VALUE CLOSE_SQUARE {
   A4GL_set_dim_srec($<str>1,atoi($<str>3));
};

/*
field_list : 
field_list_element {
	sprintf($<str>$,"%s",$<str>1);
} 
| field_list COMMA field_list_element {
	sprintf($<str>$,"%s,%s",$<str>1,$<str>3);
};
*/


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
named_or_kw_any	
{A4GL_add_srec_attribute("",$<str>1,""); }
| named_or_kw_any DOT named_or_kw_any
{A4GL_add_srec_attribute($<str>1,$<str>3,""); }
| FORMONLY DOT named_or_kw_any
{A4GL_add_srec_attribute("formonly",$<str>3,""); }
| named_or_kw_any DOT STAR 
{A4GL_add_srec_attribute($<str>1,"*",""); }
| FORMONLY DOT STAR 
{A4GL_add_srec_attribute("formonly","*",""); }
;

field_list_element :
field_list_item  | field_list_item THROUGH field_list_item {A4GL_add_srec_attribute("","","THROUGH");} 
;


field_name : named_or_kw_any {
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
named_or_kw_any  {
	strcpy($<str>$,$<str>1);
	A4GL_make_downshift($<str>$);
	colno+=strlen($<str>1);
	}
;

field_tag_name_scr : 
op_ws named_or_kw_any {
	colno+=strlen($<str>2);
} op_ws {
	strcpy($<str>$,$<str>2);
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
CHAR_VALUE   { 
	if (strlen($<str>1)==2) {/* "" */
		sprintf($<str>$,"NULL");
	} else {
		strcpy($<str>$,A4GL_char_val($<str>1)); 
	}
}
| NAMED   {strcpy($<str>$,$<str>1); }
| NAMED TO NAMED  {sprintf($<str>$,"%s\t%s",$<str>1,$<str>3); }
| NAMED COLON NAMED  {sprintf($<str>$,"%s\t%s",$<str>1,$<str>3); }
| CH   {strcpy($<str>$,$<str>1);}
| number_value 
| number_value TO number_value { sprintf($<str>$,"%s\t%s",$<str>1,$<str>3); }
| number_value COLON number_value { sprintf($<str>$,"%s\t%s",$<str>1,$<str>3); }
| CHAR_VALUE TO CHAR_VALUE {
	sprintf($<str>$,"%s\t",A4GL_char_val($<str>1));
	sprintf($<str>$,"%s%s",$<str>$,A4GL_char_val($<str>3));
}
| CHAR_VALUE COLON CHAR_VALUE {
	sprintf($<str>$,"%s\t",A4GL_char_val($<str>1));
	sprintf($<str>$,"%s%s",$<str>$,A4GL_char_val($<str>3));
}
| KW_NULL {
	sprintf($<str>$,"NULL");
}

;

opt_dec_ext : {sprintf($<str>$,"%d",(16<<8) + 2);}
	| OPEN_BRACKET NUMBER_VALUE CLOSE_BRACKET {sprintf($<str>$,"%d",((atoi($<str>2)+2)<<8)+2);}
	| OPEN_BRACKET NUMBER_VALUE COMMA NUMBER_VALUE CLOSE_BRACKET {sprintf($<str>$,"%d",(atoi($<str>2)<<8)+atoi($<str>4));}
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
	value COMPARISON value { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,$<str>2); }
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
	KW_COMPOSITES LESSTHAN comp_list GREATERTHAN op_star LESSTHAN comp_list GREATERTHAN
;

comp_list: comp_item
	| comp_list COMMA comp_item
;

comp_item : table_name DOT column_name 
;

table_name : named_or_kw_any
;

column_name : named_or_kw_any
;

control_block :
	KW_BEFORE bef_act_list KW_OF column_list actions
	| KW_AFTER aft_act_list KW_OF column_list actions
	| KW_ON_BEGINNING func_call
	| KW_ON_ENDING func_call
	
;

action:
	abort
	| comments
	| if
	| let
	| nextfield
	| func_call
	| block
;


if: KW_IF expression KW_THEN action op_else
;


op_else: | KW_ELSE action
;

abort : KW_ABORT 
;

let   : KW_LET field_tag_name EQUAL expression 
;

nextfield : KW_NEXTFIELD field_tag_name
	  | KW_NEXTFIELD EQUAL field_tag_name
	  | KW_NEXTFIELD KW_EXITNOW
	  | KW_NEXTFIELD EQUAL KW_EXITNOW
;

block: 
	KW_BEGIN actions KW_END
;

actions: action 
	| actions action
;


comments :
	COMMENTS CHAR_VALUE
	| COMMENTS KW_BELL CHAR_VALUE
	| COMMENTS REVERSE CHAR_VALUE
;


bef_act_list: 
	bef_act | bef_act_list bef_act
;

aft_act_list: 
	aft_act | aft_act_list aft_act
;

bef_act :
	KW_EDITADD
	| KW_EDITUPDATE
	| KW_REMOVE
;

aft_act:
	KW_EDITADD
	| KW_ADD
	| KW_UPDATE
	| KW_QUERY
	| KW_REMOVE
	| DISPLAY
	| KW_EDITUPDATE
;

column_list: column_entry
	| column_list COMMA column_entry
;

column_entry : 
	table_name DOT column_name
	| column_name
;

master_of:
	table_name KW_MASTER_OF table_name op_semi
;

func_call: KW_CALL named_or_kw_any OPEN_BRACKET op_func_call_args CLOSE_BRACKET
;

op_func_call_args: | func_call_args;


func_call_args: 
	func_call_arg | func_call_args COMMA func_call_arg
;

func_call_arg : expression
;


expression : 
	single_expression
	| expression KWAND expression { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,"AND");  }
	| expression KWOR expression { $<expr>$=create_expr_comp_expr($<expr>1,$<expr>3,"OR");  }


;

op_expression_list : 
	| expression_list
;

expression_list : expression
	| expression_list COMMA expression
;

single_expression: 
	MINUS expression { void *x; x=create_int_expr(0); $<expr>$=create_expr_comp_expr(x,$<expr>2,"-"); }

	|PLUS expression  { void *x; x=create_int_expr(0); $<expr>$=create_expr_comp_expr(x,$<expr>2,"+"); }
	| evalue  { $<expr>$=$<expr>1; }
	| KWNOT expression { $<expr>$=create_not_expr($<expr>2); }
	| OPEN_BRACKET expression CLOSE_BRACKET { $<expr>$=$<expr>2; }
	| fcall_name OPEN_BRACKET op_expression_list CLOSE_BRACKET { $<expr>$=$<expr>3; }
	| KW_TOTAL KW_OF field_tag_name { $<expr>$=$<expr>3; }
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
;

fcall_name: named_or_kw_any
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




st_kword : 
      KW_COMPOSITES 

     | INSTRUCTIONS 
     | ATTRIBUTES 
     | DATABASE 
     | BY 
     | KW_SIZE 

     | KW_END 
     | TITLE 
     | COMMENT 
     | DYNAMIC 
     | KW_NULL 
     | INPUT 
     | TABLES 
     | LOOKUP 
     | JOINING 
     | RECORD 
     | THROUGH 
     | TYPE 
     | DELIMITERS 
     | KW_CHAR 
     | KW_INT 
     | KW_DATE 
     | KW_FLOAT 
     | SMALLFLOAT 
     | SMALLINT 
     | KW_DECIMAL 
     | MONEY 
     | DATETIME 
     | INTERVAL 
     | LIKE 
     | BLACK 
     | BLUE 
     | GREEN 
     | CYAN 
     | RED 
     | MAGENTA 
     | WHITE 
     | YELLOW 
     | NORMAL 
     | REVERSE 
     | LEFT 
     | BOLD 
     | BLINK 
     | UNDERLINE 
     | DIM 
     | AUTONEXT 
     | COLOR 
     | COMMENTS 
     | DEFAULT 
     | VALIDATE 
     | DISPLAY 
     | DOWNSHIFT 
     | UPSHIFT 
     | FORMAT 
     | INCLUDE 
     | INVISIBLE 
     | NOUPDATE 
     | NOENTRY 
     | PICTURE 
     | PROGRAM 
     | REQUIRED 
     | QUERYCLEAR 
     | VERIFY 
     | WORDWRAP 
     | COMPRESS 
     | NONCOMPRESS 
     | TO 
     | AS 
     | SERIAL 
     | KW_BYTE 
     | KW_TEXT 
     | VARCHAR 
     | SQL_VAR 
     | KW_NONSPACE 
     | SQLONLY 
     | WIDGET 
     | CONFIG 
     | COMPARISON 
     | LESSTHAN 
     | GREATERTHAN 
     | KWOR 
     | KWAND 
     | KWWHERE 
     | KWNOT 
     | KWBETWEEN 
     | KWIN 
     | XVAL 
     | KWNULLCHK 
     | KWNOTNULLCHK 
     | YEAR 
     | MONTH 
     | DAY 
     | HOUR 
     | MINUTE 
     | SECOND 
     | FRACTION 
     | LISTBOX 
     | BUTTON 
     | KW_PANEL 
     | DISPLAYONLY 
     | ALLOWING 
     | KW_MASTER_OF 
     | KW_BEFORE 
     | KW_AFTER 
     | KW_EDITADD 
     | KW_EDITUPDATE 
     | KW_REMOVE 
     | KW_OF 
     | KW_ADD 
     | KW_UPDATE 
     | KW_QUERY 
     | KW_ON_ENDING 
     | KW_ON_BEGINNING 
     | KW_CALL 
     | KW_BELL 
     | KW_ABORT 
     | KW_LET 
     | KW_EXITNOW 
     | KW_NEXTFIELD 
     | KW_IF 
     | KW_THEN 
     | KW_ELSE 
     | KW_BEGIN 
     | KW_TOTAL 
     | KW_RIGHT 
     | KW_ZEROFILL 
     | KW_USES_EXTENDED 
     | KW_ACTION 



;

any_kword : 
      KW_COMPOSITES 
     /* | INSTRUCTIONS  */
     /* | ATTRIBUTES  */
     | DATABASE 
     | BY 
     | KW_SCREEN_TITLE 
     | KW_SCREEN 
     | KW_SIZE 
     | TITLE 
     | FORMONLY 
     | COMMENT 
     | DYNAMIC 
     | WITHOUT 
     /* | KW_NULL  */
     | INPUT 
     | TABLES 
     | LOOKUP 
     | JOINING 
     | RECORD 
     | THROUGH 
     | TYPE 
     | DELIMITERS  
     | KW_CHAR 
     | KW_INT 
     | KW_DATE 
     | KW_FLOAT 
     | SMALLFLOAT 
     | SMALLINT 
     | KW_DECIMAL 
     | MONEY 
     | DATETIME 
     | INTERVAL 
     | LIKE 
     | BLACK 
     | BLUE 
     | GREEN 
     | CYAN 
     | RED 
     | MAGENTA 
     | WHITE 
     | YELLOW 
     | NORMAL 
     | REVERSE 
     | LEFT 
     | BOLD 
     | BLINK 
     | UNDERLINE 
     | DIM 
     | AUTONEXT 
     | COLOR  
     | COMMENTS 
     | DEFAULT 
     | VALIDATE 
     | DISPLAY 
     | DOWNSHIFT 
     | UPSHIFT 
     | FORMAT 
     | INCLUDE 
     | INVISIBLE 
     | NOUPDATE 
     | NOENTRY 
     | PICTURE 
     | PROGRAM 
     | REQUIRED 
     | QUERYCLEAR 
     | VERIFY 
     | WORDWRAP 
     | COMPRESS 
     | NONCOMPRESS 
     | TO 
     | AS 
     | SERIAL 
     | KW_BYTE 
     | KW_TEXT 
     | VARCHAR 
     | SQL_VAR 
     | SQLONLY 
     | WIDGET 
     | CONFIG 
     | COMPARISON 
     | LESSTHAN 
     | GREATERTHAN 
     | KWOR 
     | KWAND 
     | KWWHERE 
     | KWNOT 
     | KWBETWEEN 
     | KWIN 
     /* | XVAL  */
     | KWNULLCHK 
     | KWNOTNULLCHK 
     | YEAR 
     | MONTH 
     | DAY 
     | HOUR 
     | MINUTE 
     | SECOND 
     | FRACTION 
     | LISTBOX 
     | BUTTON 
     | KW_PANEL 
     /* | DISPLAYONLY  */
     | ALLOWING 
     | KW_MASTER_OF 
     | KW_BEFORE 
     | KW_AFTER 
     | KW_EDITADD 
     | KW_EDITUPDATE 
     | KW_REMOVE 
     | KW_OF 
     | KW_ADD 
     | KW_UPDATE 
     | KW_QUERY 
     | KW_ON_ENDING 
     | KW_ON_BEGINNING 
     | KW_CALL 
     | KW_BELL 
     | KW_ABORT 
     | KW_LET 
     /* | KW_EXITNOW  */
     | KW_NEXTFIELD 
     | KW_IF 
     | KW_THEN 
     | KW_ELSE 
     | KW_BEGIN 
     | KW_TOTAL 
     | KW_RIGHT 
     | KW_ZEROFILL 
     | KW_USES_EXTENDED 
     | KW_ACTION 
;



%%


#include "lex.yy.c"



/* =========================== EOF ============================ */



