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
    int ni;                                 /**< Number of elements in the input bind array*/
    int no;                                 /**< Number of elements in the output bind array*/
    char *inputDescriptorName;              /**< Name of input descriptor (ESQL) */
    char *outputDescriptorName;             /**< Name of output descriptor (ESQL) */
    char *select;                           /**< The SQL statement content */
    void *hstmt;                            /**< A pointer to the statement handle */
    char statementName[256];                    /**< The name of the SQL statement */
    void *extra_info;                       /**< A space for sql driver specific info */
  };

        /** A better name to the statement descriptor structure */
  typedef struct s_sid A4glStatememnt;


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
  };

        /** A better name to the cursor descriptor */
  typedef struct s_cid A4glCursor;


  void A4GLSQL_xset_status (int a);

  //int A4GLSQL_init_connection (char *dbName);
  int A4GLSQL_get_status (void);
  int A4GLSQL_init_session (char *sessname, char *dsn, char *usr, char *pwd);
  int A4GLSQL_set_conn (char *sessname);
  void A4GLSQL_set_dialect (char *dialect);
  int A4GLSQL_close_session (char *sessname);
  void A4GLSQL_unload_data (char *fname, char *delims, char *sql1,int nbind,struct BINDING *ibind,int converted);
  int A4GLSQL_set_status (int a, int sql);
  void A4GLSQL_set_sqlerrd(int a0,int a1,int a2,int a3,int a4,int a5);
  int A4GLSQL_execute_sql_from_ptr (char *pname, int ni, char **ibind);
  /*struct s_sid *A4GLSQL_prepare_glob_sql (char *s, int ni,struct BINDING *binding); */
  struct s_sid *A4GLSQL_prepare_sql (char *s);
  /*struct s_sid *A4GLSQL_prepare_select (struct BINDING *ibind, int ni, struct BINDING *obind, int no, char *s, int singleton); */
#define A4GL_convert_sql #error out of date
char *A4GL_convert_sql_new (char *source_dialect, char *target_dialect, char *sql,int converted);
  int A4GLSQL_swap_bind_stmt(char *stmt, char t, char **sb,int *sc,void *bind, int cnt);
struct s_sid *
A4GLSQL_prepare_select (struct BINDING *ibind, int ni, struct BINDING *obind,
                        int no, char *s,char *mod, int line,int converted, int singleton);


#ifdef __cplusplus
}
#endif
#endif
