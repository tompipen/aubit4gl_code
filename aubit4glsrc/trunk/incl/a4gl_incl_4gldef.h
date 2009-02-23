/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-2005 Aubit Development Team (See Credits file)    |
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
# | contact licensing@aubit.com                                           |
# +----------------------------------------------------------------------+
#
# $Id: a4gl_incl_4gldef.h,v 1.127 2009-02-23 17:31:49 mikeaubury Exp $
*/

/**
 * @file
 *
 * Definition of structures and typedefs necessary in both lib and generated
 * C code.
 *
 * Header file used to include in the generated c files with origin
 * in the 4gl source files.
 *
 * This file is included from:
 * a4gl_incl_4glhdr.h (included by 4glc compiled 4gl code)
 * and
 * a4gl_libaubit4gl.h (included from the most of Aubit compiler and libraries code)
 *
 */

#ifndef FGLDEF_INCL
#define FGLDEF_INCL

#ifndef _NO_SYSINCL_

	#ifndef __NO_STDARG__
	/* int stdargSTART______________________; */
		#include <stdarg.h>
	/*int stdargEND______________________; */
	#endif
#endif /* _NO_SYSINCL_ */

#ifdef __cplusplus

extern "C"
{
#endif

#ifndef _NO_SYSINCL_
	/*int stdioSTART________________; */
	#include <stdio.h>
	/*int stdioEND________________; */
#endif

#define AFT_FIELD_CHK(zzz,xxx) (_fld_dr==-98&&A4GL_field_name_str_match(fldname,zzz))
#define BEF_FIELD_CHK(zzz,xxx) (_fld_dr==-97&&A4GL_field_name_str_match(fldname,zzz))

#define fglbyte struct fgl_int_loc
#define fgltext struct fgl_int_loc

	/** Date time defined without typedef. To be deprecated */
#define struct_dtime struct A4GLSQL_dtime
#define struct_ival struct ival

	/**
	 * Binding information structure definition.
	 * Used to bind values to and from SQL.
	 * Need to be here because a4gl_API_sql.h needs it
	 */
  struct BINDING
  {
    void *ptr;		   /**< A pointer to the variable bounded */
    int dtype;		   /**< The data type of the variable bounded */
    long size;		   /**< The size in bytes of the variable bounded */

    long start_char_subscript;
    long end_char_subscript;
    void *libptr;
  };


	/** SQLCA structure definition */
  typedef struct
  {
    long sqlcode;
    char sqlerrm[73];
    char sqlerrp[9];
    long sqlerrd[6];
    char sqlawarn[9];
    char sqlstate[10];
  }
  sqlca_struct;

#define fglvarchar char


  typedef struct {
	char objectName[32];
	void *objectData;
  } fglobject;


	/**
	 * Decimal 4gl data type variable definition
	 */
  typedef struct
  {
    unsigned char dec_data[128];	       /**< The value stored in decimal variable */
  }
  fgldecimal;




	/** This type name is just to have some pattern in type names */
  typedef fgldecimal FglDecimal;

  typedef fgldecimal FglMoney;

	/**
	 * Money 4gl data type variable definition
	 */
  typedef struct
  {
    unsigned char dec_data[64];	       /**< The value stored in money variable */
  }
  fglmoney;

  struct fgl_int_loc
  {
    char isnull;
    char where;
    FILE *f;
    long memsize;	/**< Memory size */
    char filename[256];
    void *ptr;

    char *loc_user_env; 
/* For user use - not used internally */
    long loc_user_bufsize;   
/* For user use - not used internally */
  };


	/** 4gl Byte data type */
  typedef struct fgl_int_loc FglByte;

	/** 4gl Text data type */
  typedef struct fgl_int_loc FglText;

	/** Date data type */
  typedef long FglDate;

	/**
	 * Datetime value variable type.
	 *
	 * The name was chaged due to imcompatibility with esql/c
	 * 
	 * The values in qualifiers are :
	 *   - 1 : YEAR
	 *   - 2 : MONTH
	 *   - 3 : DAY
	 *   - 4 : HOUR
	 *   - 5 : MINUTE
	 *   - 6 : SECOND
	 *   - > 6 FRACTION + precision of fraction (2 by default)
	 */
  struct A4GLSQL_dtime
  {
    int stime;		   /**< The start qualifier */
    int ltime;		   /**< The end qualifier */
    char data[32];	   /**< The information in the var */
  };


	/** 4gl Interval data type definition */
  typedef struct A4GLSQL_dtime FglDatetime;

	/**
	 * Interval variable data type.
	 */

  struct ival
  {
    int stime;		   /**< The start qualifier */
    int ltime;		   /**< The end qualifier */
    int i_years;
    int i_months;
    int i_days;
    int i_hours;
    int i_minutes;
    int i_seconds;
    long i_fractions;
	int is_neg;
  };

#ifndef S_CONSTR_LIST
#define S_CONSTR_LIST
struct s_constr_list {char *tabname;char *colname;char *value;char*fldbuf;};
#endif

	/** 4gl Datetime data type definition */
  typedef struct ival FglInterval;

  typedef struct ACL_Menu_Opts
  {
    char opt_title[80];
    char optkey[80];
    int optlength;
    int opt_no;
    int help_no;
    int optpos;
    int attributes;
    char shorthelp[80];
    struct ACL_Menu_Opts *next_option;
    struct ACL_Menu_Opts *prev_option;
    int page;
  }
  ACL_Menu_Opts;

  struct aclfgl_event_list {
        int event_type;
        int block;
        int keycode;
        char *field;
  };

  typedef struct
  {
    char menu_title[80];
    int menu_type;
    char parent_window_name[20];
    ACL_Menu_Opts *curr_option;
    int menu_offset;
    int mn_offset;
    int x;
    int y;
    int help_no;
    int num_opts;
    int abort_pressed;
    ACL_Menu_Opts *first;
    ACL_Menu_Opts *last;	/* used for wrapping round */
    int curr_page;
    int max_page;
    int w;
    int menu_line;
    int attrib;
    int gw_y;
    int gw_x;
    int gw_b;
    struct aclfgl_event_list *evt;
    int nevt;
    char *mnstyle;
    char *mncomment;
    char *mnimage;
  }
  ACL_Menu;


struct sDependantTable {
	char *tabname;
	char *checksuminfo;
};





struct s_field_name {
        char *fname;
        int fpos;
};
typedef struct s_field_name ts_field_name;

struct s_field_name_list {
        int nfields;
        struct s_field_name *field_name_list;
};




#define CHECK_RETURN_AND_POP(x) if (_retvars!= x) {if (_retvars!=-1||1) {if (a4gl_status==0) A4GL_set_status(-3001,0);A4GL_pop_args(_retvars);}} else { aclfgli_clr_err_flg(); A4GL_pop_params(ibind,x);}
#define CHECK_NO_RETURN if (_retvars!= 0) {if (_retvars!=-1||1) {if (a4gl_status==0) A4GL_set_status(-3001,0);A4GL_pop_args(_retvars);}} else { aclfgli_clr_err_flg();  }
#define CHECK_ONE_OR_NO_RETURN if (_retvars>0) { if (_retvars>1) { if (a4gl_status==0) { A4GL_set_status(-3001,0); } A4GL_pop_args(_retvars); } else { A4GL_pop_args(1);  aclfgli_clr_err_flg(); } } else { aclfgli_clr_err_flg(); }
#define CHECK_ONE_OR_NO_RETURN_POP if (_retvars>0) { if (_retvars>1) { if (a4gl_status==0) { A4GL_set_status(-3001,0); } A4GL_pop_args(_retvars); } else { A4GL_pop_params(ibind,1);  aclfgli_clr_err_flg(); } } else { aclfgli_clr_err_flg(); }

#define CHK_FOR_ERR (aclfgli_get_err_flg()&&(a4gl_sqlca.sqlcode !=0 || a4gl_status !=0))
#define ERR_CHK_WHEN_NOT_FOUND if ( CHK_FOR_ERR && (a4gl_sqlca.sqlcode==100))
#define ERR_CHK_SQLERROR if (CHK_FOR_ERR && (a4gl_sqlca.sqlcode<0&&a4gl_status==a4gl_sqlca.sqlcode))
#define ERR_CHK_ERROR if (CHK_FOR_ERR && (a4gl_status<0 && a4gl_sqlca.sqlcode>=0))
#define ERR_CHK_SQLWARNING if (CHK_FOR_ERR && (a4gl_sqlca.sqlcode==0&&a4gl_sqlca.sqlawarn[0]=='W'))
#define ERR_CHK_WARNING    if (CHK_FOR_ERR &&  (aclfgli_get_err_flg()&&a4gl_sqlca.sqlcode==0&&(a4gl_sqlca.sqlawarn[0]=='w'||a4gl_sqlca.sqlawarn[0]=='W')))


  /* ===================== from builtin.c =================== */

  /*
     Note : all functions with aclfgl_ prefix are callable from
     compiled 4gl code, since all references to functions get aclfgl_ prefix
     appended to them by 4gl compiler. Therefore, compiled 4gl code CANNOT
     call any function in Aubit libraries without aclfgl prefix.
   */

void A4GL_setnull (int type, void *buff, int size);
void A4GL_trim (char *p);
//void A4GL_trim_nl (char *p);
void A4GL_trim_not_nl (char *p);
char *A4GL_strncpyz(char *dest, const char *src, size_t n);

  int aclfgl_set_count (int nargs);
int a_isprint(int a);
  int aclfgl_arr_count (int nargs);
  int aclfgl_scr_line (int nargs);
  int aclfgl_arr_curr (int nargs);
  int aclfgl_length (int nargs);
  int acli_scroll (void *s, int n,int m);
  void aclfgl_key_callback(void *p, int Keycode);
  void acli_datetime (char *s, int n);


  int aclfgl_err_get (int statusnumber);	/* CHECK */
  int aclfgl_err_print (int statusnumber);	/* THESE SHOULD BE PASSED */
  int aclfgl_err_quit (int statusnumber);	/* A NUMBER OF PARAMETERS */
  int aclfgl_startlog (char *filename);		/* NOT THE PARAMETERS THEMSELVES */

#define aclfgl_errorlog(n)  A4GL_errorlog(__FILE__,__LINE__,n);
#define aclfgl_startlog(n)  A4GL_startlog(__FILE__,__LINE__,n);

int A4GL_fgl_error (int a, char *s, int err, int stat);


int A4GL_init_connection (char *dbName);



  /* int     aclfgl_errorlog       (int n); */
  int A4GL_errorlog (char *s, int l, int n);
  int A4GL_startlog (char *s, int l, int n);
  /*char *A4GLSQLCV_convert_sql(char *dialect,char *sql); */

  int aclfgl_showhelp (int helpnumber);
  int aclfgl_fgl_getenv (int nargs);
  int aclfgl_mdy (int nargs);
  char *A4GL_char_pop (void);

  int a4gl_decadd( fgldecimal *d1, fgldecimal *d2, fgldecimal *sum)  ;
  int a4gl_deccmp(fgldecimal *d1, fgldecimal *d2)  ;
  void a4gl_deccopy(fgldecimal *target, fgldecimal *src)  ;
  int a4gl_deccvasc(char *s, int n, fgldecimal *d)   ;
  int a4gl_deccvdbl(double d, fgldecimal *d1)   ;
  int a4gl_deccvflt(float d, fgldecimal *d1)   ;
  int a4gl_deccvint(int i, fgldecimal *d)   ;
  int a4gl_deccvlong(long l, fgldecimal *d)  ;
  int a4gl_decdiv( fgldecimal *d1, fgldecimal *d2, fgldecimal *res)  ;
  int a4gl_decmul(fgldecimal *d1, fgldecimal *d2, fgldecimal *res)   ;
  void a4gl_decround(fgldecimal *d1, int n)  ;
  int a4gl_decsub(fgldecimal *d1, fgldecimal *d2, fgldecimal *res)  ;
  int a4gl_dectoasc(fgldecimal *d, char *s, int l, int right)   ;
  int a4gl_dectodbl(fgldecimal *d1, double *d)  ;
  int a4gl_dectoint(fgldecimal *d1, int *ival)   ;
  int a4gl_dectolong(fgldecimal *d1, long *lval)  ;
  void a4gl_dectrunc(fgldecimal *d1,int n)  ;

  /* ======================= From buildtin_d.c ==================== */

  int aclfgl_date (int nargs);
  int aclfgl_day (int nargs);
  int aclfgl_month (int nargs);
  int aclfgl_year (int nargs);
  int aclfgl_weekday (int nargs);

  int A4GL_get_count (void);

  int aclfgl_hex (int nargs);
  int aclfgl_abs (int nargs);
  int aclfgl_root (int nargs);
  int aclfgl_sqrt (int nargs);
void A4GL_ensure_current_window_is(char *s) ;

  int A4GL_gen_field_chars (void ***field_list, void *formdets, ...);
  /* int A4GL_set_fields (void *sio); */
  void aclfgli_clr_err_flg (void);

char *A4GL_get_err_txt(void ) ;
void A4GL_set_err_txt(char *s);

  void A4GL_set_option_value (char type, long keyval);
  int aclfgli_get_err_flg (void);
  void A4GLSTK_setCurrentLine (const char *moduleName, int lineNumber);
  void A4GLSTK_getCurrentLine( char **moduleName, int *lineNumber);
	char *A4GLSTK_lastSeenLine(void);
  void A4GL_clr_fields (int to_defaults,  ...);
  int A4GL_field_name_str_match(char *f1,char *f2);
  int A4GL_chk_iskey (char *base,char *iot, char *keys);
  void A4GL_disp_fields (int n, int attr, ...);
  char *A4GL_var_for_inp_array(char *s);
  char *A4GL_add_dot_star(char *s);

  int A4GL_fgl_getfldbuf (void *inp,char itype, struct s_field_name *orig_fldlist, ...);
  void A4GL_make_field_slist_from_ap_with_field_list (struct s_field_name_list *list, va_list * ap, int replace_0, struct s_field_name *fldlist);

  int A4GL_fgl_infield (void *inp,char itype,...);
  void A4GL_set_init (struct BINDING *b, int n);
  int A4GL_req_field (void *s, char itype,char type,...);
  void aclfgli_pr_message (int attr, int wait,int nexpr);
  void A4GL_push_disp_bind (void *b, int n);
  int A4GL_fgl_start (int nargs, char *argv[]);
  void A4GLSTK_initFunctionCallStack (void);
  void A4GL_fgl_end (void);
  void A4GL_system_run (int a);
  void A4GL_push_time (void);
  int A4GL_esql_db_open(int a,char *src,char *target,char *dbname);
void *A4GL_find_prepare (char *pname);
int A4GL_call_4gl_dll (char *filename, char *function, int args);

  /*double A4GL_pop_double(void); */
  /* ======================= API_ui.c ===================== */

  /*int aclfgl_set_page (int nargs); */
  /*int aclfgl_get_page (int nargs); */

  /* ======================= builtin.c  ================== */
  void aclfgli_current (int a, int b);
  void A4GL_push_current (int a, int b);	/* stack.c */
  char *aclfgli_str_to_id (char *name);
  int aclfgl_ascii (int n);
  void A4GL_push_ascii (void);	/* stack.c */
  void acli_interval (char *s, int n);
  int A4GL_ctodt (void *a, void *b, int size);
  int A4GL_ctoint (void *a, void *b, int size);
int A4GL_check_version(char *module, char *version, int build );


  /* ====================== extfile.c ===================== */

  int aclfgl_fgl_show_help (int a);

  /* ====================== fglwrap.c ====================== */

  int aclfgl_get_ui_mode (int n);
  int aclfgl_num_args (int n);
  int aclfgl_arg_val (int n);

  /* ======================= helper.c ======================= */

  int aclfgl_fgl_prtscr (int n);
  int aclfgl_get_info (int np);

  /* ====================== others.c ======================= */

  int aclfgl_fgl_lastkey (int _np);
  int aclfgl_fgl_keyval (int _np);
  int aclfgl_upshift (int _np);
  int aclfgl_downshift (int _np);
  void A4GL_upshift_stk (void);
  void A4GL_downshift_stk (void);

  /* ======================== datatypes.c ================ */

  int aclfgl_load_datatype (int nargs);
void A4GL_set_report_dim(int with_page_length,int with_left_margin,int with_right_margin,int with_top_margin,int with_bottom_margin,char *with_top_of_page);

int A4GL_set_report_dim_int(char *type,int value);

struct BINDING *A4GL_duplicate_binding (struct BINDING *b, int n);
#ifndef BIND_RECOPY
#define BIND_RECOPY
struct BINDING * bind_recopy (struct BINDING *b, int n, struct BINDING *c);
#endif
void A4GL_check_dependant_tables(char *module_name, const char *CompileTimeSQLType,  const struct sDependantTable *dependantTables) ;





#include "a4gl_rep_structure.h"

int A4GL_set_agg(char type, long *agg_type, void **aggptr, long *aggused) ;
int A4GL_push_agg(char type, long agg_type, void *agg, long aggcnt);
int A4GL_init_agg(void **aggptr, int type);


int A4GL_push_substr (char *ca, int dtype, int a, int b, ...) ;
int A4GL_report_lineno(struct rep_structure *rep);
void A4GL_convert_report (struct rep_structure *rep, char *ofile, char *otype, char *layout, int to_pipe);

int A4GL_pdf_pdffunc(void* p,char* fname,int n) ;

void A4GL_free_report (struct rep_structure *rep);
int A4GL_push_report_section (struct rep_structure *rep, char *mod, char *repname, int lineno, char where, char *why, int rb);
void A4GL_pop_report_section (struct rep_structure *rep, int rb);
void A4GL_pdf_pop_report_section (struct pdf_rep_structure *rep, int rb) ;
int A4GL_always_output_report(struct rep_structure *rep) ;

void *A4GL_alloc_dynarr(void *var_ptr, void *old_ptr,int dim1,int dim2,int dim3,int dim4,int dim5,int total_bytes,int isRealloc)  ;
void A4GL_dynarr_free(void *var_ptr,void *old_ptr);
void A4GL_isdynarr_allocated(void *var_ptr);
void A4GL_dynarr_extent(void *var_ptr,int dim) ;
void A4GL_push_dynamic_array(void *p, int sz);

char *A4GL_get_target_dialect(char *lex_default,char *lex_compile_time_target);

int A4GL_pdf_push_report_section (struct pdf_rep_structure *rep, char *mod, char *repname, int lineno, char where, char *why, int rb) ;
#  if __WORDSIZE == 64
#define int8 long 
#define serial8 long 
#else
#define int8 long long
#define serial8 long long
#endif


/*
to fix the _nm_status error (if status is an int) change

extern int a4gl_status;

to
__attribute__((dllimport))extern int a4gl_status;

That's the ugly, short-hand way.  For some reason, auto-import
doesn't always work.  Search the mailing lists for more correct
ways of handling this (if you use the same include file to build
your library and in your applications - above should only
be used in applications which link to the library).
*/

  /*
     DLL building support on win32 hosts;  mostly to workaround their
     ridiculous implementation of data symbol exporting. See exaple in libltdl/
   */


#if ( defined(__CYGWIN__) || defined(__MINGW32__) )
	#define __NEED_DLL_IMPORT__
#endif

#ifdef __NEED_DLL_IMPORT__
#ifndef STATIC_LIBAUBIT4GL

	#define dll_export __declspec(dllexport)
	#define dll_import extern __declspec(dllimport)	/* for complex vars that can't be auto imported */
#else
	#define dll_export
	#define dll_import extern
#endif
#else
	#define dll_export
	#define dll_import extern
#endif

#ifdef __cplusplus
}
#endif

#endif				/* #ifndef FGLDEF_INCL */
