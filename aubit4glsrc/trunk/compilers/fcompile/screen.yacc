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

struct local_expr_list {
	listitem *expr_list;
	int nlist;
};


int in_screen_section=0;
int dtype_size=0;
char *rm_dup_quotes(char *s) ;
/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

char *chk_alias(char *s);
int A4GL_wcswidth(char *mbs);	/* utf8 */

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
database_section screen_section op_table_section attribute_section op_instruction_section {
A4GL_check_compiled_form();
A4GL_write_form();}
;
database_section :
DATABASE FORMONLY {the_form.dbname=acl_strdup("formonly");}
| DATABASE dbname WITHOUT KW_NULL INPUT {the_form.dbname=acl_strdup(downshift($<str>2));
if (A4GLF_open_db(the_form.dbname)) {
		yyerror("Unable to connect to database\n");
}
}
| DATABASE FORMONLY WITHOUT KW_NULL INPUT {the_form.dbname=("formonly");}
| DATABASE dbname {the_form.dbname=acl_strdup(downshift($<str>2));
if (A4GLF_open_db(the_form.dbname)) {
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
	fld->colours.colours_len=0;
	fld->colours.colours_val=0;
	A4GL_debug("add color %d\n",FA_C_WHITE);
}
op_field_desc
{
	if (A4GL_has_str_attribute(fld,FA_S_FORMAT)) {
		int dtype;
		dtype=fld->datatype & DTYPE_MASK;

		if (dtype!=DTYPE_INT  &&
		    dtype!=DTYPE_SMINT  &&
		    dtype!=DTYPE_FLOAT  &&
		    dtype!=DTYPE_SMFLOAT  &&
		    dtype!=DTYPE_DATE  &&
		    dtype!=DTYPE_DECIMAL  &&
		    dtype!=DTYPE_MONEY) {
	        		yyerror("A FORMAT cannot be applied to this fields because of the datatype");
	        		YYERROR;
				printf("X1\n");
		}
	}

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
	a4gl_status=0;
	A4GL_set_field(currftag,fld);
	if (a4gl_status!=0) {
		yyerror(A4GL_get_fcompile_err());
	}
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
	fld->tabname=acl_strdup($<str>1); 
	fld->colname=acl_strdup($<str>3);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
}
| named_or_kw_any {
	fld->colname=acl_strdup($<str>1);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
}

| STAR named_or_kw_any DOT named_or_kw_any {
	fld->tabname=acl_strdup($<str>2); 
	fld->colname=acl_strdup($<str>4);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,fld->tabname);
        fld->dtype_size=A4GL_get_dtype_size();
}
| STAR named_or_kw_any {
	fld->colname=acl_strdup($<str>2);
	fld->not_null=0;
        fld->datatype=A4GLF_getdatatype_fcompile(fld->colname,"");
        fld->dtype_size=A4GL_get_dtype_size();
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

lu_fc: 	named_or_kw_any DOT named_or_kw_any {
			sprintf($<str>$,"%s.%s", $<str>1,$<str>3);
		}
	| named_or_kw_any {
			sprintf($<str>$,"%s", $<str>1);
	}
;

lu_joincol:
 	named_or_kw_any DOT named_or_kw_any {sprintf($<str>$,"%s.%s", $<str>1,$<str>3);}
	| named_or_kw_any {sprintf($<str>$,"%s",$<str>1);}
 	| STAR named_or_kw_any DOT named_or_kw_any {sprintf($<str>$,"*%s.%s", $<str>1,$<str>3);}
	| STAR named_or_kw_any {sprintf($<str>$,"*%s",$<str>1);}
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
| LOOKUP  lu_ft_eq_c lu_join lu_joincol  {
	$<lookups>2->joincol=strdup($<str>4);
	fld->lookup.lookups.lookups_len++;
	fld->lookup.lookups.lookups_val=realloc(fld->lookup.lookups.lookups_val, sizeof(fld->lookup.lookups.lookups_val[0])*fld->lookup.lookups.lookups_len);
	fld->lookup.lookups.lookups_val[fld->lookup.lookups.lookups_len-1]=$<lookups>2;
}
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
| DYNAMIC KW_SIZE EQUAL NUMBER_VALUE { fld->dynamic=atoi($<str>4); A4GL_debug("fld->dynamic=%d",fld->dynamic); }
| DYNAMIC  { fld->dynamic=-1; A4GL_debug("dynamic=-1"); }
| SQLONLY  { printf("Warning %s is not implemented for 4GL\n",$<str>1); }
| NOENTRY { A4GL_add_bool_attr(fld,FA_B_NOENTRY); }
| NOUPDATE { A4GL_add_bool_attr(fld,FA_B_NOUPDATE); }
| PICTURE EQUAL CHAR_VALUE { A4GL_add_str_attr(fld,FA_S_PICTURE,$<str>3); }
| PROGRAM EQUAL CHAR_VALUE { A4GL_add_str_attr(fld,FA_S_PROGRAM,$<str>3); }
| REQUIRED 	{ A4GL_add_bool_attr(fld,FA_B_REQUIRED); }
| REVERSE 	{ A4GL_add_bool_attr(fld,FA_B_REVERSE); }
| VERIFY 	{ A4GL_add_bool_attr(fld,FA_B_VERIFY); }
| QUERYCLEAR   	{ A4GL_add_bool_attr(fld,FA_B_QUERYCLEAR); }
| KW_ZEROFILL   { A4GL_add_bool_attr(fld,FA_B_ZEROFILL); }
| KW_RIGHT   	{ A4GL_add_bool_attr(fld,FA_B_RIGHT); }
| WORDWRAP  	{ A4GL_add_bool_attr(fld,FA_B_WORDWRAP); }
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

srec_dim : named_or_kw_any  {
   A4GL_set_dim_srec($<str>1,1);
}
| named_or_kw_any OPEN_SQUARE NUMBER_VALUE CLOSE_SQUARE {
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

opt_dec_ext : {
			sprintf($<str>$,"0");
		}
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
} |  column_name
{
	$<column>$.tabname=strdup("");
	$<column>$.colname=strdup($<str>1);
}

;

table_name : named_or_kw_any
;

column_name : named_or_kw_st
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
			$<at_nextfield>$->isexitnow=0;
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

func_call: KW_CALL named_or_kw_any OPEN_BRACKET {
			$<fcall>$=malloc(sizeof(struct s_at_call));
			$<fcall>$->fname=strdup($<str>2);
			$<fcall>$->list_parameters.list_parameters_len=0;
			$<fcall>$->list_parameters.list_parameters_val=0;
	} op_func_call_args CLOSE_BRACKET {
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

     | ATTRIBUTES 
     | DATABASE 
     | BY 
     | KW_SIZE 
	|INSTRUCTIONS

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



