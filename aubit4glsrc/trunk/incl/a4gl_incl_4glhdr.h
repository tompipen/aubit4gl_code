/**
 * @file
 * Header file used to include in the generated c files with origin
 * in the 4gl source files.
 */

#ifndef FGLHDR_INCL
#define FGLHDR_INCL
	#include <stdio.h>
	#define fglerror(a,b) fgl_error(__LINE__,__FILE__,a,b)
	#define AFT_FIELD_CHK(zzz,xxx) (_fld_dr==-98&&strcmp(fldname,zzz)==0)
	#define BEF_FIELD_CHK(zzz,xxx) (_fld_dr==-97&&strcmp(fldname,zzz)==0)
	#define BEF_DELETE  (_fld_dr==-12)
	#define AFT_DELETE  (_fld_dr==-13)
	#define BEF_INSERT  (_fld_dr==-14)
	#define AFT_INSERT  (_fld_dr==-15)
	#define BEF_ROW (_fld_dr==-10)
	#define AFT_ROW  (_fld_dr==-11)
	#define BEFORE_INP  (_fld_dr==-99)
	#define AFTER_INP  (_fld_dr==-95)
	#define ON_KEY(zzz) if (_fld_dr==-90&&chk_iskey(zzz))


#ifdef OLD_INCL

	/* not strictly voids - but saves getting into the details */
	void *prepare_glob_sql (char *s,int ni,void *b);
#endif
	#define set_status(a) set_status(a,0)

	#include "a4gl_incl_4gldef.h"

#ifndef OLD_INCL
	#include "a4gl_libaubit4gl.h"
#endif

    #ifndef _DEFINE_STATUSVARS_  /* set from lib/libaubit4gl/Makefile */
    /* for everything except libaubit4gl */


		/** Sqlca variable */
		#ifndef _SQLCA_DEFINED_
		    #define _SQLCA_DEFINED_
			extern sqlca_struct sqlca;
	    #endif

		/** 4gl global status variable */
		#ifndef DEFINE_STATUS
		#define DEFINE_STATUS
			/* FIXME: is this OK? see lib/fglwrap.c */
			#ifdef __CYGWIN__
				extern int status;
			#else
				extern long status;
			#endif
		#endif

		/** 4gl interrupt ocurred global flag */
		#ifndef DEFINE_INTFLAG
		#define DEFINE_INTFLAG
			#ifdef __CYGWIN__
		    	extern int int_flag;
		    #else
				extern long int_flag;
		    #endif
		#endif


		/** 4gl quit ocurred global flag */
		#ifndef DEFINE_QUITFLAG
		#define DEFINE_QUITFLAG
		    #ifdef __CYGWIN__
				extern long quit_flag;
		    #else
				extern int quit_flag;
		    #endif
		#endif
    #else
	/* only in libaubit4gl */

		/** Sqlca variable */
		#ifndef _SQLCA_DEFINED_
		    #define _SQLCA_DEFINED_
			sqlca_struct sqlca;
	    #endif

		/** 4gl global status variable */
		#ifndef DEFINE_STATUS
		#define DEFINE_STATUS
			/* FIXME: is this OK? see lib/fglwrap.c */
			#ifdef __CYGWIN__
				int status;
			#else
				long status;
			#endif
		#endif

		/** 4gl interrupt ocurred global flag */
		#ifndef DEFINE_INTFLAG
		#define DEFINE_INTFLAG
			#ifdef __CYGWIN__
		    	int int_flag;
		    #else
				long int_flag;
		    #endif
		#endif


		/** 4gl quit ocurred global flag */
		#ifndef DEFINE_QUITFLAG
		#define DEFINE_QUITFLAG
		    #ifdef __CYGWIN__
				long quit_flag;
		    #else
				int quit_flag;
		    #endif
		#endif
	#endif

	#define DEF_ASS(uass,d) char * uass[d]={(char *)-1}

	#define OP_MASK 512|1024
	#define OP_MASK_BASE 512


	#define NUMERIC_OP_2  1*OP_MASK_BASE
	#define STRING_OP_S1 2*OP_MASK_BASE
	#define STRING_OP_S2 4*OP_MASK_BASE
	#define STRING_OP_N1 8*OP_MASK_BASE
	#define STRING_OP_N2 16*OP_MASK_BASE
	#define FUNCTION_OP 32*OP_MASK_BASE
	#define BOOLEAN_OP 64*OP_MASK_BASE
	#define OTHER_OP 128*OP_MASK_BASE


	/* add no more than 15 items to any of the following groups */
	#define OP_ADD 1|NUMERIC_OP_2
	#define OP_SUB 2|NUMERIC_OP_2
	#define OP_MULT 3|NUMERIC_OP_2
	#define OP_DIV 4|NUMERIC_OP_2
	#define OP_POWER 5|NUMERIC_OP_2
	#define OP_MOD 6|NUMERIC_OP_2

	#define OP_CLIP 1|STRING_OP_S1
	#define OP_CONCAT 1|STRING_OP_S2
	#define OP_COPY 2|STRING_OP_S2
	#define OP_USING 3|STRING_OP_S2
	#define OP_MATCHES 4|STRING_OP_S2
	#define OP_LIKE 5|STRING_OP_S2

	#define OP_YEAR 1|STRING_OP_N1
	#define OP_MONTH 2|STRING_OP_N1
	#define OP_DAY 3|STRING_OP_N1
	#define OP_HOUR 4|STRING_OP_N1
	#define OP_MINUTE 5|STRING_OP_N1
	#define OP_SECOND 6|STRING_OP_N1

	#define OP_SUBSTR1 1|STRING_OP_N2
	#define OP_SUBSTR2 1|STRING_OP_N3

	#define OP_EQUAL (1|BOOLEAN_OP)
	#define OP_LESS_THAN (2|BOOLEAN_OP)
	#define OP_GREATER_THAN (3|BOOLEAN_OP)
	#define OP_NOT_EQUAL (4|BOOLEAN_OP)
	#define OP_LESS_THAN_EQ (5|BOOLEAN_OP)
	#define OP_GREATER_THAN_EQ (6|BOOLEAN_OP)
	#define OP_AND (7|BOOLEAN_OP)
	#define OP_OR (8|BOOLEAN_OP)
	#define OP_NOT (9|BOOLEAN_OP)
	#define OP_ISNULL (10|BOOLEAN_OP)
	#define OP_ISNOTNULL (11|BOOLEAN_OP)
	/* 12|BOOLEAN reserved for OP_MATH which is used internally */

	#define OP_IN (1|OTHER_OP)
	#define OP_NOTIN (2|OTHER_OP)
	#define OP_IN_SELECT (3|OTHER_OP)
	#define OP_NOTIN_SELECT (4|OTHER_OP)
	#define OP_EXISTS (5|OTHER_OP)
	#define OP_NOTEXISTS (6|OTHER_OP)

	#define ENCODE_SIZE(x) (x<<16)
	#define DECODE_SIZE(x) (x>>16)

	/* Prototpes for functions that should be seen */
#ifdef OLD_INCL
	char *	new_string(int a);
	int 	pop_bool(void);
	int 	pop_int(void);
	long 	pop_long(void);
	long 	pop_date(void);
	float 	pop_float(void);
	double 	pop_double(void);
	int 	pop_var(void *p,int d) ;
	int 	pop_var2(void *p,int d,int s) ;
	double 	ret_var(void *p,int d) ;
	int 	pop_char(char *z,int size);
	char *	char_pop(void);
	int 	pop_param(void *p,int d,int size);

	void 	pop_params		(struct BINDING *b,int n);
	void 	push_param		(void *p,int d);
	void 	push_params 	(struct BINDING *b, int n);

	void 	push_user(void);
	void 	push_today(void);
	int 	opboolean(void);
	void 	pop_args(int a) ;
	void 	debug_print_stack(void) ;
	void 	print_stack(void) ;


	void 	locate_var(struct fgl_int_loc *p,char where,char *filename);
#endif

	#if (defined(WIN32) && ! defined(__CYGWIN__))
		#define dll_export __declspec(dllexport)
		#define dll_import __declspec(dllimport)
	#else
		#define dll_export
		#define dll_import
	#endif

	#define acl_free(s) acl_free_full(s,__FILE__,__LINE__)
	#define acl_malloc(a,b) acl_malloc_full(a,b,__FILE__,__LINE__)

	#define GETSETNEW -1
	#define GETSETRM -2
	#define GETSETGET 1
	#define GETSETSET 2
	#define GETSETGETPTR 3
	#define GETPTR(struct,ptr,element) get_set(struct,ptr,GETSETGETPTR,element,0)
	#define GET(struct,ptr,element) get_set(struct,ptr,GETSETGET,element,0)
	#define SET(struct,ptr,element,value) get_set(struct,ptr,GETSETSET,element,(long)value)
	#define NEW(struct) get_set(struct,0,GETSETNEW,0,0)
	#define RM(struct,ptr) get_set(struct,ptr,GETSETRM,0,0)

#ifdef OLD_INCL

	/* report stuff */
	struct rep_structure {
	    int top_margin,bottom_margin,left_margin,right_margin;
	    int page_length;
	    int has_first_page;
	    char *next_page;
	    char *rep_table; /* database table for aggregate values */
	    struct BINDING *group_data;
	    char output_mode;
	    char output_loc[256];
	    char top_of_page[256];
	    FILE *output;
	    int page_no;
	    int printed_page_no;
	    int line_no;
	    int col_no;
		/* was 	    int (*report)(); */
		/* int (*report)(void); */ /* report.c:180: too many arguments to function */
        int (*report)(int a, int b);
	};
	struct pdf_rep_structure {
	    double top_margin,bottom_margin,left_margin,right_margin;
	    double page_length;
	    double page_width;
	    int has_first_page;
	    char *next_page;
	    char *rep_table; /* database table for aggregate values */
	    struct BINDING *group_data;
	    char output_mode;
	    char output_loc[256];
	    FILE *output;
	    int page_no;
	    int printed_page_no;
	    double line_no;
	    double col_no;
		/* was 	    int (*report)(); */
		/* int (*report)(void); */ /* report.c:180: too many arguments to function */
        int (*report)(int a, int b);
		char font_name[256];
	    double font_size;
	    int paper_size;
	    void *pdf_ptr;
	   int font;
	};

	double pdf_size(double f, char c,struct pdf_rep_structure *p);
#endif
	#define REPORT_START -1
	#define REPORT_FINISH -2
	#define REPORT_DATA -3
	#define REPORT_OPS_COMPLETE -4
	#define REPORT_AFTERDATA -5
	#define REPORT_SENDDATA -6
	#define REPORT_BEFOREDATA -7
	#define REPORT_BEFOREGROUP -8
	#define REPORT_AFTERGROUP -9
	#define REPORT_LASTROW -10
	#define REPORT_PAGEHEADER -11
	#define REPORT_FIRSTPAGEHEADER -12
	#define REPORT_LASTDATA -13
	#define REPORT_PAGETRAILER -14


	#define ERR_BADNOARGS 1000
	#define ABORT 1
	#define WARN 2

	#ifndef NODEBUG
#ifdef OLD_INCL
		int set_line(char *s,long l);
#endif
		#define debug set_line(__FILE__,__LINE__);debug_full
	#else
		#define debug null_func
	#endif


	#define MENU_ALL "_AlL_"

#endif /* #ifndef FGLHDR_INCL */

