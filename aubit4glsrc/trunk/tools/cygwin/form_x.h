/* This is manaully edited version of form_x.h
for use only on CygWin - WIN32 platform */

/*
In file included from /usr/include/netinet/in.h:14,
                 from /usr/local/include/rpc/rpc.h:41,
                 from form_x.h:10,
                 from formwrite2.c:9:
/usr/include/cygwin/in.h:150: warning: `INADDR_LOOPBACK' redefined
/usr/local/include/rpc/types.h:60: warning: this is the location of the previous
 definition

in rpc/rpc.h :

#include <rpc/types.h>
#include <netinet/in.h>


*/



//--------- new --------------

#ifndef _FORM_X_H_RPCGEN
#define _FORM_X_H_RPCGEN

#include <rpc/rpc.h>

#ifdef __cplusplus
extern "C" {
#endif

#define FCOMILE_XDR_VERSION 102
#define FCOMILE_XDR_MAGIC 0xa4fc1234


//-----------old---------------

#ifndef XDRFILE
#define XDRFILE
//#include <rpc/rpc.h>
#define bool_t int
#define u_int unsigned int

//-----------------------------

struct struct_metrics {
	int x;
	int y;
	int w;
	int scr;
	int delim_code;
	char *label;
	int pos_code;
	int dlm1;
	int dlm2;
	int field;
};
typedef struct struct_metrics struct_metrics;
bool_t xdr_struct_metrics();


struct struct_form_field {
	char *tag;
	struct {
		u_int metric_len;
		int *metric_val;
	} metric;
};
typedef struct struct_form_field struct_form_field;
bool_t xdr_struct_form_field();


enum FIELD_ATTRIBUTES_BOOL {
	FA_B_AUTONEXT = 0,
	FA_B_REVERSE = 1,
	FA_B_INVISIBLE = 2,
	FA_B_NOENTRY = 3,
	FA_B_VERIFY = 4,
	FA_B_WORDWRAP = 5,
	FA_B_COMPRESS = 6,
	FA_B_UPSHIFT = 7,
	FA_B_DOWNSHIFT = 8,
	FA_B_REQUIRED = 9,
};
typedef enum FIELD_ATTRIBUTES_BOOL FIELD_ATTRIBUTES_BOOL;
bool_t xdr_FIELD_ATTRIBUTES_BOOL();


enum FA_COLOUR {
	FA_C_BLACK = 0,
	FA_C_RED = 1,
	FA_C_GREEN = 2,
	FA_C_YELLOW = 3,
	FA_C_BLUE = 4,
	FA_C_MAGENTA = 5,
	FA_C_CYAN = 6,
	FA_C_WHITE = 7,
};
typedef enum FA_COLOUR FA_COLOUR;
bool_t xdr_FA_COLOUR();



enum FA_ATTRIBUTES_STRING {
	FA_S_INCLUDE = 0,
	FA_S_PICTURE = 1,
	FA_S_FORMAT = 2,
	FA_S_DEFAULT = 3,
	FA_S_PROGRAM = 4,
	FA_S_WIDGET = 5,
	FA_S_CONFIG = 6,
	FA_S_COMMENTS = 7,
};
typedef enum FA_ATTRIBUTES_STRING FA_ATTRIBUTES_STRING;
bool_t xdr_FA_ATTRIBUTES_STRING();


struct struct_field_attr_string {
	enum FA_ATTRIBUTES_STRING type;
	char *value;
};
typedef struct struct_field_attr_string struct_field_attr_string;
bool_t xdr_struct_field_attr_string();


struct colours {
        enum FA_COLOUR colour;
        struct u_expression *whereexpr;
};
typedef struct colours colours;


/*
struct struct_scr_field {
	int field_no;
	char *colname;
	char *tabname;
	int subscripts[3];
	int datatype;
	int dynamic;
	int do_reverse;
	struct {
		u_int str_attribs_len;
		struct struct_field_attr_string *str_attribs_val;
	} str_attribs;
	struct {
		u_int bool_attribs_len;
		enum FIELD_ATTRIBUTES_BOOL *bool_attribs_val;
	} bool_attribs;
	enum FA_COLOUR colour;
};
typedef struct struct_scr_field struct_scr_field;
bool_t xdr_struct_scr_field();
*/


//----</new>------------

struct struct_scr_field {
	int field_no;
	char *colname;
	char *tabname;
	int subscripts[3];
	int datatype;
	int dynamic;
	int do_reverse;
	struct {
		u_int str_attribs_len;
		struct struct_field_attr_string *str_attribs_val;
	} str_attribs;
	struct {
		u_int bool_attribs_len;
		enum FIELD_ATTRIBUTES_BOOL *bool_attribs_val;
	} bool_attribs;
	enum FA_COLOUR colour;
	struct {
		u_int colours_len;
		struct colours *colours_val;
	} colours;
};
typedef struct struct_scr_field struct_scr_field;
bool_t xdr_struct_scr_field();
//----</new>------------



struct struct_tables {
	char *tabname;
	char *alias;
};
typedef struct struct_tables struct_tables;
bool_t xdr_struct_tables();


struct screen_name {
	char *name;
};
typedef struct screen_name screen_name;
bool_t xdr_screen_name();


struct struct_screen_record {
	char *name;
	int dim;
	struct {
		u_int attribs_len;
		int *attribs_val;
	} attribs;
};
typedef struct struct_screen_record struct_screen_record;
bool_t xdr_struct_screen_record();


struct struct_labels {
	char *label_content;
	int x;
	int y;
	int w;
	int scr;
};
typedef struct struct_labels struct_labels;
bool_t xdr_struct_labels();

/* ---old---
struct struct_form {
	char *magic1;
	char *dbname;
	char *delim;
	int maxcol;
	int maxline;
	struct {
		u_int snames_len;
		struct screen_name *snames_val;
	} snames;
	struct {
		u_int attributes_len;
		struct struct_scr_field *attributes_val;
	} attributes;
	struct {
		u_int metrics_len;
		struct struct_metrics *metrics_val;
	} metrics;
	struct {
		u_int fields_len;
		struct struct_form_field *fields_val;
	} fields;
	struct {
		u_int records_len;
		struct struct_screen_record *records_val;
	} records;
	struct {
		u_int tables_len;
		struct struct_tables *tables_val;
	} tables;
	char *magic2;
};
typedef struct struct_form struct_form;
*/

struct struct_form {
	long magic;
	char *magic1;
	long fcompile_version;
	long compiled_time;
	char *dbname;
	char *delim;
	int maxcol;
	int maxline;
	struct {
		u_int snames_len;
		struct screen_name *snames_val;
	} snames;
	struct {
		u_int attributes_len;
		struct struct_scr_field *attributes_val;
	} attributes;
	struct {
		u_int metrics_len;
		struct struct_metrics *metrics_val;
	} metrics;
	struct {
		u_int fields_len;
		struct struct_form_field *fields_val;
	} fields;
	struct {
		u_int records_len;
		struct struct_screen_record *records_val;
	} records;
	struct {
		u_int tables_len;
		struct struct_tables *tables_val;
	} tables;
	char *magic2;
};
typedef struct struct_form struct_form;
bool_t xdr_struct_form();


//#endif //#ifndef XDRFILE


//==================================================================

/*
struct colours {
	enum FA_COLOUR colour;
	struct u_expression *whereexpr;
};
typedef struct colours colours;
*/

enum ITEMTYPES {
	ITEMTYPE_INT = 1,
	ITEMTYPE_CHAR = 2,
	ITEMTYPE_FIELD = 3,
	ITEMTYPE_COMPLEX = 4,
	ITEMTYPE_SPECIAL = 5,
	ITEMTYPE_LIST = 6,
	ITEMTYPE_NOT = 7,
};
typedef enum ITEMTYPES ITEMTYPES;

enum EXPRESSIONTYPES {
	EXPRTYPE_COMPLEX = 0,
	EXPRTYPE_ITEM = 1,
};
typedef enum EXPRESSIONTYPES EXPRESSIONTYPES;

struct s_complex_expr {
	struct u_expression *item1;
	char *comparitor;
	struct u_expression *item2;
};
typedef struct s_complex_expr s_complex_expr;

typedef struct u_expression *listitem;

struct u_expression {
	int itemtype;
	union {
		int intval;
		char *charval;
		char *field;
		struct s_complex_expr *complex_expr;
		char *special;
		struct {
			u_int list_len;
			listitem *list_val;
		} list;
		struct u_expression *notexpr;
	} u_expression_u;
};
typedef struct u_expression u_expression;

typedef s_complex_expr t_complex_expr;

typedef u_expression t_expression;

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_struct_metrics (XDR *, struct_metrics*);
extern  bool_t xdr_struct_form_field (XDR *, struct_form_field*);
extern  bool_t xdr_FIELD_ATTRIBUTES_BOOL (XDR *, FIELD_ATTRIBUTES_BOOL*);
extern  bool_t xdr_FA_COLOUR (XDR *, FA_COLOUR*);
extern  bool_t xdr_FA_ATTRIBUTES_STRING (XDR *, FA_ATTRIBUTES_STRING*);
extern  bool_t xdr_struct_field_attr_string (XDR *, struct_field_attr_string*);
extern  bool_t xdr_colours (XDR *, colours*);
extern  bool_t xdr_struct_scr_field (XDR *, struct_scr_field*);
extern  bool_t xdr_struct_tables (XDR *, struct_tables*);
extern  bool_t xdr_screen_name (XDR *, screen_name*);
extern  bool_t xdr_struct_screen_record (XDR *, struct_screen_record*);
extern  bool_t xdr_struct_labels (XDR *, struct_labels*);
extern  bool_t xdr_struct_form (XDR *, struct_form*);
extern  bool_t xdr_ITEMTYPES (XDR *, ITEMTYPES*);
extern  bool_t xdr_EXPRESSIONTYPES (XDR *, EXPRESSIONTYPES*);
extern  bool_t xdr_s_complex_expr (XDR *, s_complex_expr*);
extern  bool_t xdr_listitem (XDR *, listitem*);
extern  bool_t xdr_u_expression (XDR *, u_expression*);
extern  bool_t xdr_t_complex_expr (XDR *, t_complex_expr*);
extern  bool_t xdr_t_expression (XDR *, t_expression*);

#else /* K&R C */
extern bool_t xdr_struct_metrics ();
extern bool_t xdr_struct_form_field ();
extern bool_t xdr_FIELD_ATTRIBUTES_BOOL ();
extern bool_t xdr_FA_COLOUR ();
extern bool_t xdr_FA_ATTRIBUTES_STRING ();
extern bool_t xdr_struct_field_attr_string ();
extern bool_t xdr_colours ();
extern bool_t xdr_struct_scr_field ();
extern bool_t xdr_struct_tables ();
extern bool_t xdr_screen_name ();
extern bool_t xdr_struct_screen_record ();
extern bool_t xdr_struct_labels ();
extern bool_t xdr_struct_form ();
extern bool_t xdr_ITEMTYPES ();
extern bool_t xdr_EXPRESSIONTYPES ();
extern bool_t xdr_s_complex_expr ();
extern bool_t xdr_listitem ();
extern bool_t xdr_u_expression ();
extern bool_t xdr_t_complex_expr ();
extern bool_t xdr_t_expression ();

#endif /* K&R C */

//=================================================================

#ifdef __cplusplus
}
#endif

#endif //#ifndef XDRFILE

#endif /* !_FORM_X_H_RPCGEN */

