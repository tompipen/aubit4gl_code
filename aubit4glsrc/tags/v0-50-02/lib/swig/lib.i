// ========================================================================
// this is SWIG warper specification file
// it will be processed by SWIG executale, to create Aubit 4gl library warper
// for use with Aubit 4gl compiler Perl code output compiler runner -
// "aubit4gl_pl.pm". Note that this Perl Module (.pm) needs to be installed
// to global Perl moduled locations, or Perl @INC path has to be modified,
// for it to be accessible to Perl interpreter
//
// ========================================================================


%module aubit4gl_pl

%{
//everything between this curly braces will appear literaly in 
//generated code


typedef struct {
	int sqlcode;
	char sqlerrm[73];
	char sqlerrp[9];
	int sqlerrd[6];
	char sqlawarn[9];
	char sqlstate[10];
} sqlca_struct;

struct BINDING {
        void *ptr;
        int dtype;
        long size;
};

%}

typedef struct {
	int sqlcode;
	char sqlerrm[73];
	char sqlerrp[9];
	int sqlerrd[6];
	char sqlawarn[9];
	char sqlstate[10];
} sqlca_struct;

struct BINDING {
        void *ptr;
        int dtype;
        long size;
};

extern sqlca_struct a4gl_sqlca;
extern int a4gl_status;

int A4GLSQL_init_connection (char *dbName);
void A4GLSTK_initFunctionCallStack (void);
void A4GLSTK_pushFunction (const char *functionName, char *params[], int n);
void A4GLSTK_setCurrentLine (const char *moduleName, int lineNumber);
void A4GL_chk_err (int lineno, char *fname);
void A4GL_display_at (int n, int a);
void A4GL_fgl_end (void);
void A4GL_fgl_end_4gl_0 (void);
void A4GL_fgl_start (int nargs, char *argv[]);
int A4GL_pop_bool (void);
long A4GL_pop_long (void);
void A4GL_push_char (char *p);
void A4GL_push_int (short p);
void A4GL_push_long (long p);
void A4GL_push_variable (void *ptr, int dtype);
void A4GL_pushop (int a);
void A4GL_setnull (int type, void *buff, int size);
void aclfgli_clr_err_flg (void);
int aclfgli_get_err_flg (void);

