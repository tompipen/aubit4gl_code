/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: form_x.x,v 1.14 2007-10-24 13:35:02 mikeaubury Exp $
#*/

/**
 * @file
 * this file is processed by:
 *    SUN rpcgen to create form_x_xdr.c and form_x.h
 *  or
 *    xgen to create
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 * @todo Find a way to get rid of "register int32_t *buf;" in created code
 * that results in compiler warnings for unused variable
 */

const FCOMILE_XDR_VERSION = 108;
const FCOMILE_XDR_MAGIC = 0xa4fc1234;

struct struct_metrics
  {
	int x;
	int  y;
	int  w;
	int  h;
	int  scr;
	int  delim_code;
	string label<>;
	int pos_code;
	long dlm1;
	long dlm2;
	long field;
  };


struct struct_form_field
  {
    string tag<>;
    int metric<>;
  };


enum FIELD_ATTRIBUTES_BOOL {
	FA_B_AUTONEXT,
	FA_B_REVERSE,
	FA_B_INVISIBLE,
	FA_B_NOENTRY,
	FA_B_VERIFY,
	FA_B_WORDWRAP,
	FA_B_COMPRESS,
	FA_B_UPSHIFT,
	FA_B_DOWNSHIFT,
	FA_B_REQUIRED,
	FA_B_NOUPDATE,
	FA_B_QUERYCLEAR,
	FA_B_ZEROFILL,
	FA_B_RIGHT
	
};

enum FA_COLOUR {
	FA_C_BLACK,
	FA_C_RED,
	FA_C_GREEN,
	FA_C_YELLOW,
	FA_C_BLUE,
	FA_C_MAGENTA,
	FA_C_CYAN,
	FA_C_WHITE
};


enum FA_ATTRIBUTES_STRING {
	FA_S_INCLUDE,
	FA_S_PICTURE,
	FA_S_FORMAT,
	FA_S_DEFAULT,
	FA_S_PROGRAM,
	FA_S_WIDGET,
	FA_S_CONFIG,
	FA_S_COMMENTS,
	FA_S_CLASS,
	FA_S_ACTION
};

struct struct_field_attr_string {
 	enum FA_ATTRIBUTES_STRING type;
	string value<>;
};

struct colours {
	long colour;
	struct u_expression *whereexpr;
};


struct struct_scr_field
  {
    int field_no;
    string colname<>;
    string tabname<>;
    int subscripts[3];
    int datatype;
    int not_null;
    int dtype_size;
    int dynamic;
    int do_reverse;
    struct struct_field_attr_string str_attribs<>;
    enum FIELD_ATTRIBUTES_BOOL bool_attribs<>;
    /* enum FA_COLOUR colour; */
    struct colours colours<>;
    int general_ptr;
    int flags;
};

struct s_column {
	string tabname<>;
	string colname<>;
};

struct s_column_list {
	struct s_column columns<>;
};
	
struct s_composites {
	struct s_column_list *col_left;
	struct s_column_list *col_right;
	int has_star;
};


enum e_bef_aft_act {
	 E_BA_EDITADD,
         E_BA_REMOVE,
         E_BA_ADD,
         E_BA_UPDATE,
         E_BA_QUERY,
         E_BA_DISPLAY,
         E_BA_EDITUPDATE
};

enum e_control_block {
	E_CB_BEFORE,
	E_CB_AFTER,
	E_CB_ONBEGINNING,
	E_CB_ONENDING
};


enum ACTION_TYPES {
	 ACTION_TYPE_ABORT,
	 ACTION_TYPE_NOP,
         ACTION_TYPE_COMMENTS,
         ACTION_TYPE_IF,
         ACTION_TYPE_LET,
         ACTION_TYPE_NEXTFIELD,
         ACTION_TYPE_FUNC_CALL,
         ACTION_TYPE_BLOCK

};

union u_action switch (enum ACTION_TYPES type) {
	 case ACTION_TYPE_NOP:  	/* No operation - used for ELSE if there isn't one */
	 case ACTION_TYPE_ABORT: 	void;
         case ACTION_TYPE_COMMENTS: 	struct s_at_comments *cmd_comment;
         case ACTION_TYPE_IF:		struct s_at_if *cmd_if;
         case ACTION_TYPE_LET:		struct s_at_let *cmd_let;
         case ACTION_TYPE_NEXTFIELD:	struct s_at_nextfield *cmd_nextfield;
         case ACTION_TYPE_FUNC_CALL:	struct s_at_call *cmd_call;
         case ACTION_TYPE_BLOCK: 	struct s_at_block *cmd_block;
	
};



struct s_bef_aft {
	enum  e_bef_aft_act befaftlist<>;
	struct s_column_list *column_list;
	struct s_at_block *cmds;
};

typedef struct u_expression *listitem;

struct s_at_call {
	string fname<>;
	listitem list_parameters<>;
};



union s_control_block switch (enum e_control_block cbtype) {
	case E_CB_BEFORE:
        case E_CB_AFTER: 	struct s_bef_aft *befaft;
        case E_CB_ONBEGINNING:
        case E_CB_ONENDING:	struct s_at_call *onbegend;
};

struct struct_tables
  {
    string tabname<>;
    string alias<>;
  };

struct screen_name {
	string name<>;
};

struct struct_master_of {
	string tab_master<>;
	string tab_detail<>;
};
	

struct struct_screen_record
  {
    string name<>;
    int dim;
    int attribs<>;
  };

struct struct_labels
  {
	string label_content<>;
	int x;
	int  y;
	int  w;
	int  scr;
  };

struct struct_form
	{
	long magic;
	string magic1<>;
	long fcompile_version;
 	long compiled_time;
	string dbname<>;
	string delim<>;
	int maxcol;
	int maxline;
	struct screen_name snames<>;
	struct struct_scr_field attributes<>;
	struct struct_metrics metrics<>;
	struct struct_form_field fields<>;
	struct struct_screen_record records<>;
	struct struct_tables tables<>;
	struct s_control_block control_blocks<>;
	struct struct_master_of  master_of<>;
	struct s_composites composites<>;
	string magic2<>;
};


enum ITEMTYPES {
	ITEMTYPE_NULL=0,
	ITEMTYPE_INT=1,
	ITEMTYPE_CHAR=2,
	ITEMTYPE_FIELD=3,
	ITEMTYPE_COMPLEX=4,

	ITEMTYPE_SPECIAL=5,
	ITEMTYPE_LIST=6,
	ITEMTYPE_NOT=7,
	ITEMTYPE_EXITNOW=8
};

enum EXPRESSIONTYPES {
	EXPRTYPE_COMPLEX,
	EXPRTYPE_ITEM
};


struct s_complex_expr {
	struct u_expression *item1;
	string comparitor<>;
	struct u_expression *item2;
};



union u_expression switch (int itemtype) {
	case ITEMTYPE_INT     : int intval;
	case ITEMTYPE_CHAR    : string charval<>;
	case ITEMTYPE_FIELD   : string field<>;
	case ITEMTYPE_COMPLEX : struct s_complex_expr *complex_expr;
	case ITEMTYPE_SPECIAL : string special<>;
	case ITEMTYPE_LIST    : listitem list<>;
	case ITEMTYPE_NOT     : struct u_expression *notexpr;
};

typedef struct s_complex_expr t_complex_expr; 
typedef union u_expression t_expression; 

struct s_at_comments {
	string comment<>;
	int hasbell;
	int isreverse;
};

struct s_at_if {
	struct u_expression *test_condition;
	struct u_action *if_true;
	struct u_action *if_false;
};

struct s_at_let {
	struct u_expression *field_tag;
	struct u_expression *value;
};

struct s_at_nextfield {
	struct u_expression *field_tag;
	int isexitnow;
};

typedef union u_action *t_ptraction;

struct s_at_block {
	t_ptraction actions<>;
};
/* =============================== EOF =============================== */
