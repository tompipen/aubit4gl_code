#ifndef A4GL_SQL_H
#define A4GL_SQL_H
#ifdef __cplusplus
extern "C"
{
#endif




        /**
         * An SQL statement identification structure.
         */
  struct s_sid
  {
    struct BINDING *ibind;                  /**< The input bind array */
    struct BINDING *obind;                  /**< The output bind array */
    /* DLM added */
    struct BINDING *extobind;
    int ni;                                 /**< Number of elements in the input bind array*/
    int no;                                 /**< Number of elements in the output bind array*/
    /* DLM addes */
    int neo;                                 /**< Number of elements in the extra output bind array*/
    char *inputDescriptorName;              /**< Name of input descriptor (ESQL) */
    char *outputDescriptorName;             /**< Name of output descriptor (ESQL) */
    char *select;                           /**< The SQL statement content */
    void *hstmt;                            /**< A pointer to the statement handle */
    char statementName[256];                    /**< The name of the SQL statement */
    void *extra_info;                       /**< A space for sql driver specific info */
    char extra_space[1024];                       /**< A space for sql driver specific info */
    int refcnt; /* reference counter to check if being used by a cursor (or more than one ;-) ) */
  };

        /** A better name to the statement descriptor structure */
  typedef struct s_sid A4glStatememnt;


enum e_cursor_state
{
  E_CURSOR_DECLARED,
  E_CURSOR_OPEN,
  E_CURSOR_CLOSED,
  E_CURSOR_FREED                /* Dont know if we'll ever use this one! */
};


        /**
         * The cursor identification structure.
         */
  struct s_cid
  {
    struct s_sid *statement;        /**< The statement used to declare the cursor */
    int mode;                       /**< The cursor mode */
    void *hstmt;                    /**< A pointer to the satetement handle */

    struct BINDING *o_ibind;                  /**< The input bind array */
    struct BINDING *o_obind;                  /**< The output bind array */
    int o_ni;                                 /**< Number of elements in the input bind array*/
    int o_no;                                 /**< Number of elements in the output bind array*/
    int sql_no;
    int currpos; 			/** Current position in the resultset */
    int nrows;				/** number of rows in the dataset */
    char *DeclareSql;
    void *extra_info;			/**< A space for sql driver specific info */
    int isScroll;
    enum e_cursor_state cursorState;
    struct BINDING *o_lastopenibind;
    int o_lastopenni;
  };

        /** A better name to the cursor descriptor */
  typedef struct s_cid A4glCursor;


  void A4GL_xset_status (int a);

  //int A4GLSQL_init_connection (char *dbName);
  int A4GL_get_status (void);
  int A4GL_init_session (char *sessname, char *dsn, char *usr, char *pwd);
  int A4GL_init_session_with_sqltype (char *sessname, char *dsn, char *usr, char *pwd,char *sqltype);
  int A4GL_set_conn (char *sessname);
  void A4GL_set_dialect (char *dialect);
  int A4GL_close_session (char *sessname);
  void A4GL_unload_data2 (char *fname, char *delims,void *filterFunc, char *sql1,int nbind,struct BINDING *ibind,int converted);
  int A4GL_set_status (int a, int sql);
  void A4GL_set_sqlerrd(int a0,int a1,int a2,int a3,int a4,int a5);
  int A4GLSQL_execute_sql_from_ptr (char *pname, int ni, char **ibind);
  /*struct s_sid *A4GLSQL_prepare_glob_sql (char *s, int ni,struct BINDING *binding); */
  struct s_sid *A4GLSQL_prepare_sql (char *s);
#define A4GL_convert_sql #error out of date
  char *A4GL_convert_sql_new (char *source_dialect, char *target_dialect, char *sql,int converted);

  int A4GL_swap_bind_stmt(char *stmt, char t, char **sb,int *sc,void *bind, int cnt);
  struct s_sid * A4GL_prepare_select (struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s,char *mod, int line,int converted, int singleton);
char * A4GL_translate_sql (char *sql1);

void A4GL_set_sqlerrm (char *m, char *p);


// Cursor handling...
void A4GL_free_cursor(char* cursor_name,int partOfAnotherCommand) ;
int A4GL_fetch_cursor(char* cursor_name,int fetch_mode,int fetch_when,int nibind,void* ibind) ;
int A4GL_open_cursor(char* s,int no,void* vibind) ;
void A4GL_flush_cursor(char* cursor) ;
int A4GL_close_cursor(char* currname,int explicit_) ;
void* A4GL_declare_cursor(int upd_hold,void* sid,int scroll,char* cursname) ;
void A4GL_put_insert(void* ibind,int n) ;
void *A4GL_find_cursor (char *cname);
void A4GL_free_prepare(struct s_sid *sid);


int A4GL_execute_implicit_sql(void* sid,int singleton,int no,void* ibind) ;
int A4GL_execute_implicit_select(void* sid,int singleton) ;


#ifdef __cplusplus
}
#endif
#endif
