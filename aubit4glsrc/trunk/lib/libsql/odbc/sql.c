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
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: sql.c,v 1.186 2007-03-16 16:35:59 gyver309 Exp $
#
*/

/**
 * @file
 * ODBC Sql execution implementation
 *
 * @todo Doxygen comments to add to functions
 */


/*
=====================================================================
                            Includes
=====================================================================
*/

#if (defined(WIN32) && ! defined(__CYWIN__)) /* && defined DLL_EXPORT */
#include <windows.h>
#endif

#include "a4gl_lib_sql_odbc_int.h"
#include <errno.h>
/*
=====================================================================
                            Macros
=====================================================================
*/

#define chk_rc(rc,stmt,call) A4GL_chk_rc_full(rc,(void *)stmt,call,__LINE__,__FILE__)

/**
 * Define max length of char string representation of
 * number as: = max(precision) + leading sign + E +
 * exp sign + max exp length
 * =  15 + 1 + 1 + 1 + 2
 * =  15 + 5
 */

#define strlen(a) (strlen((char *)a))
#define fgl_size(a,b) (fgl_sizes[a]==-1?b+1:fgl_sizes[a])

#ifdef _WIN32
#define ODBC_INI "ODBC.INI"
#ifndef strncasecmp
#define strncasecmp(start, attr, len) _strnicmp(start, attr, len)
#endif
#else
#define ODBC_INI ".odbc.ini"
#endif

#undef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#undef max
#define max(a, b) ((a) < (b) ? (b) : (a))

#ifndef SQL_NO_DATA_FOUND
#define SQL_NO_DATA_FOUND SQL_NO_DATA
#endif

#define retfail(s) { A4GL_trc("%s, returning False", s); return False; }
#define return_chk_rc(rc, stmt, call) { if (!chk_rc(rc, stmt, call)) { A4GL_wrn("%s failed, returning False", call); return False;} else return True;}
#define chk_rc_retonfail(rc, stmt, call) { if (!chk_rc(rc, stmt, call)) { A4GL_wrn("%s failed, returning False", call); return False;}}

#define ALWAYS_GETENV_CACHESCHEMA

/*
=====================================================================
                       Type definitions
=====================================================================
*/

//typedef int SQLRETURN;

typedef enum {
    False = 0,
    True = 1
} Bool;

struct cursors
{
    struct s_cid *cid;
    char *cname;
};

struct stmts
{
    struct s_sid *sid;
    char *pname;
};

/**
 * Definition of a date
 */
typedef struct
{
    union
    {
        char date_c[44];
        DATE_STRUCT date_ds;
    } uDate;
    long *ptr;
} ACLDATE;

typedef struct
{
    union
    {
        char dtime_c[65];
        TIMESTAMP_STRUCT dtime_t;
    } dtime_u;
    struct A4GLSQL_dtime *ptr;
} ACLDTIME;

typedef struct
{
    union
    {
        char ival_c[65];
    } ival_u;
    struct ival *ptr;
} ACLIVAL;

enum {
    FLAG_SINGLETON = 1,
    FLAG_PREPARED = 2,
    FLAG_OWNS_BINDINGS = 3,
    FLAG_OPEN = 4,
    FLAG_OWNS_SQLSTR = 5
};

// catalog query structures
/**
* structure holding bind buffers for SQLColumns
*/
struct sql_col_bind_data
{
    // SQLBindCol variables
    SQLCHAR tq[256];     // 1 TABLE_CAT
    SQLCHAR to[256];     // 2 TABLE_SCHEM
    SQLCHAR tn[256];     // 3 TABLE_NAME
    SQLCHAR cn[256];     // 4 COLUMN_NAME
    SQLSMALLINT dt;      // 5 DATA_TYPE
    SQLCHAR dtname[256]; // 6 TYPE_NAME
    SQLUINTEGER prec;    // 7 PRECISION / COLUMN_SIZE
    SQLUINTEGER buflen;  // 8 BUFFER_LENGTH
    SQLSMALLINT scale;   // 9 SCALE / DECIMAL_DIGITS
    SQLSMALLINT radix;   // 10 RADIX / NUM_PREC_RADIX
    SQLSMALLINT nullable;// 11 NULLABLE (whether col can accept NULLs)
    SQLCHAR remarks[256];// 12 REMARKS

    //ODBC >= 3.0
    SQLCHAR dftval[256]; // 13 COLUMN_DEF (default value)
    SQLSMALLINT sqltype; // 14 SQL_DATA_TYPE (
    SQLSMALLINT sqldtsub;// 15 SQL_DATETIME_SUB (datetime/interval subtype)
    SQLUINTEGER octetlen;// 16 CHAR_OCTET_LENGTH (max length of char
                         //    or length of a binary column
    SQLUINTEGER ordinal; // 17 ORDINAL_POSITION
    SQLCHAR isnullable[4];//18 IS_NULLABLE (whether col can NOT accept nulls)

    SQLLEN len_tq;
    SQLLEN len_to;
    SQLLEN len_tn;
    SQLLEN len_cn;
    SQLLEN len_dtname;
    SQLLEN len_dt;
    SQLLEN len_prec;
    SQLLEN len_buflen;
    SQLLEN len_scale;
    SQLLEN len_radix;
    SQLLEN len_nullable;
    SQLLEN len_remarks;
    //ODBC >= 3.0
    SQLLEN len_dftval;
    SQLLEN len_sqltype;
    SQLLEN len_sqldtsub;
    SQLLEN len_octetlen;
    SQLLEN len_isnullable;
};

/**
* structure holding an entire context of the SQLColumns logic
*/
struct sql_col_info_data
{
    // misc variables
    int size;
    int colsize;
    int colidx;
    int dtype;
    int prec;
    char colname[256];
    char tabname[256];
    SQLHSTMT hstmt;
    int foundInCache;
    short nColumns;
    struct sql_col_bind_data bd;
};


/**
 * Conversion table between 4gl and C data types.
 */
int conv_4gl_to_c[] = {
    SQL_C_CHAR,
    SQL_C_SHORT,
    SQL_C_LONG,
    SQL_C_DOUBLE,
    SQL_C_FLOAT,
    SQL_C_DOUBLE,    /* decimal != double  need to change this */
    SQL_C_LONG,
    -1,
    SQL_C_DOUBLE,    /* as for decimal,  money != double */
    9999,
    -1,
    SQL_C_BINARY,
    SQL_C_BINARY,
    SQL_C_CHAR,      /* Varchar */
    SQL_C_CHAR       /* Interval */
};


/*
=====================================================================
                           Constants
=====================================================================
*/

#define FETCH_ABSOLUTE      1
#define FETCH_RELATIVE      2
#define DTYPE_DATE          7
#define MAX_NUM_PRECISION   15
#define MAX_NUM_STRING_SIZE (MAX_NUM_PRECISION + 5)
#define SE_NULLPTR 1

/*
=====================================================================
                        Global variables
=====================================================================
*/
#ifdef PGODBC
int date_as_char = 1;
#else
int date_as_char = 0;
#endif

int dtime_as_char = 1;

char scratch[255][255];
HENV henv = 0;
HDBC hdbc = 0;         /** The database connection handle */
static SQLINTEGER outlen[512];

SQLINTEGER nullval = SQL_NULL_DATA;

static struct sql_col_info_data cidata;

dll_import sqlca_struct a4gl_sqlca;

/**
 * Table of 4gl sizes.
 */
int fgl_sizes[] = {
    -1,
    sizeof (short),
    sizeof (long),
    sizeof (double),
    sizeof (float),
    sizeof (double),
    sizeof (long),
    0,
    sizeof (double),
    0,
    -1,
    0,
    0,
    -1,
    20
};

/**
 *
 */
int convpos_sql_to_4gl[15] = {
    9999,       /** 0 */
    0,          /** SQL_CHAR */
    3,          /** SQL_NUMERIC */
    5,          /** SQL_DECIMAL */
    2,          /** SQL_INTEGER */
    1,          /** SQL_SMINT */
    3,          /** SQL_FLOAT  */
    4,          /** SQL_REAL */
    3,          /** SQL_DOUBLE  8 */
    7,          /** SQL_DATE 9  */
    10,         /** SQL_TIME 10 */
    10,         /** SQL_TIMESTAMP 11 */
    0           /** SQL_VARCHAR  12 */
};


/**
 *
 */
int convneg_sql_to_4gl[15] = {
    9999,       /** 0 */
    12,         /** SQL_LONGVARCHAR */
    11,         /** SQL_BINARY */
    11,         /** SQL_VARBINARY */
    11,         /** SQL_LONGVARBINARY */
    2,          /** SQL_BIGINT */
    1,          /** SQL_TINYINT */
    1           /** SQL_BIT */
};


/*
=====================================================================
                     Global variables - static
=====================================================================
*/

static int odbc_autocommit = 0;
static char sess_name[32] = "default";
//OldDBname must be long enough to hold full path for SQLlite database file
static char OldDBname[2048] = "";
static char dbms_name[1065] = "";
static char dbms_dialect[64] = "";
static int in_transaction = 0;
static int ignore_next_sql_error = 0;

/*
=====================================================================
                  Function prototypes - static
=====================================================================
*/

// error handling
static void set_global_status(int code, char *odbc_sqlstate, char *msg);
static void exitwith_sql_odbc_errm(char *errmsg, char *arg);
static void exitwith_sql_odbc(char *errmsg);
static Bool sql_ok(SQLRETURN rc);
static Bool sql_failed(SQLRETURN rc);

// statement-specific
static Bool sql_free_stmt(SQLHSTMT *phstmt);
static SQLRETURN sql_free_sid(struct s_sid **sid);
static unsigned int set_flag(unsigned int flags, int bit, Bool value);
static Bool get_flag(unsigned int flags, int bit);
static void sid_set_singleton(struct s_sid *sid, Bool flg);
static Bool sid_get_singleton(struct s_sid *sid);
static void sid_set_prepared(struct s_sid *sid, Bool flg);
static Bool sid_get_prepared(struct s_sid *sid);
static void sid_set_owns_bindings(struct s_sid *sid, Bool flg);
static Bool sid_get_owns_bindings(struct s_sid *sid);
static void cid_set_open(struct s_cid *cid, Bool flg);
static Bool cid_get_open(struct s_cid *cid);
static void sid_set_owns_sqlstr(struct s_sid *sid, Bool flg);
static Bool sid_get_owns_sqlstr(struct s_sid *sid);
static Bool prepare_statement_internal(struct s_sid *sid, char *s);

// metadata functions
static Bool sql_use_describe(void);
static Bool sql_cacheschema(void);
static Bool cache_make_key(char *tabname, char *colname, int colidx, struct sql_col_info_data *ci, char *dstbuf);
static void cache_try_add_coldata(char *colname, int colidx, struct sql_col_info_data *ci);
static Bool cache_try_get_coldata(char *tabname, char *colname, int colNo, struct sql_col_info_data *ci);
static Bool sql_columns(SQLHDBC hdbc, char *tabname, char *colname, struct sql_col_info_data *ci);
static void sql_clear_column_info(struct sql_col_info_data *ci, Bool clearTableData);
static int conv_sqlprec (int ndtype, int sdim, int scale);
static unsigned long conv_sqldtype (int sqldtype, int sdim);

// other
static void initenv (void);
static void ListDSN (void);
static char *strncpyz(char *dest, const char *src, size_t n);
static int do_fake_transactions (void);

/*
=====================================================================
                      Function prototypes
=====================================================================
*/
void *A4GL_bind_decimal (void *ptr_to_decimal);
int A4GL_dttoc (void *a, void *b, int size);
int A4GLSQL_make_connection (char *server, char *uid_p, char *pwd_p);
void *A4GL_bind_datetime (void *ptr_to_dtime_var);
void *A4GL_bind_interval (void *ptr_to_ival);
void A4GL_decode_datetime (struct A4GLSQL_dtime *d, int *data);
int A4GL_inttoc (void *a1, void *b, int size);
int A4GL_has_cache_column (char *buff);
char * A4GL_find_cache_column(char *buff);
void A4GL_add_cache_column(char*buff,char*def);


struct expr_str_list *A4GL_add_validation_elements_to_expr (
        struct expr_str_list *ptr, char *val);

char *A4GL_conv_date (char *s);
int A4GL_proc_bind (struct BINDING *b, int n, char t, HSTMT hstmt);
void A4GL_ibind_column_arr (int pos, char *s, HSTMT hstmt);
void *A4GL_bind_date (long *ptr_to_date_var);
int A4GL_ibind_column (int pos, struct BINDING *bind, HSTMT hstmt);
int A4GL_obind_column (int pos, struct BINDING *bind, HSTMT hstmt);
void A4GL_post_fetch_proc_bind (struct BINDING *use_binding, int use_nbind,
                                HSTMT hstmt);
void A4GL_add_cursor (struct s_cid *cid, char *cname);
Bool ODBC_exec_stmt (SQLHSTMT *hstmt);
Bool ODBC_exec_select (SQLHSTMT hstmt);
Bool ODBC_exec_sql (SQLCHAR * sqlstr);
int ODBC_disconnect (void);
void ODBC_set_dbms_info (void);
int A4GL_chk_need_blob (SQLRETURN rc, HSTMT hstmt);
int A4GL_chk_getenv (char *s, int a);
char *A4GL_decode_rc (int a);
void A4GL_clear_sqlca(void);
int SQL_API A4GL_newSQLSetParam (SQLHSTMT hstmt, SQLUSMALLINT ipar, SQLSMALLINT fCType,
                                 SQLSMALLINT fSqlType, SQLUINTEGER cbColDef,
                                 SQLSMALLINT ibScale, PTR rgbValue,
                                 SQLINTEGER FAR * pcbValue);
long A4GL_describecolumn (SQLHSTMT hstmt, int colno, int type);
struct s_cid *A4GLSQL_find_cursor (char *cname);

#ifdef INCLUDEDATASOURCES
RETCODE SQL_API SQLDataSources (HENV henv, SQLUSMALLINT fDirection,
                                SQLCHAR FAR * szDSN, SQLSMALLINT cbDSNMax,
                                SQLSMALLINT FAR * pcbDSN, SQLCHAR FAR * szDescription,
                                SQLSMALLINT cbDescriptionMax,
                                SQLSMALLINT FAR * pcbDescription);
#endif

/* in sqlex.c */
extern int A4GL_set_blob_data (SQLHSTMT hstmt);
extern int A4GL_get_blob_data (struct fgl_int_loc *blob, HSTMT hstmt,
                               int colno);


/*
=====================================================================
                    Platform specific code
=====================================================================
*/

#if (defined(WIN32) && ! defined(__CYWIN__)) /* && defined DLL_EXPORT */

dll_export sqlca_struct a4gl_sqlca;
dll_export int status;
int WINAPI libSQL_odbc32_init (HANDLE h, DWORD reason, void *foo)
{
    return 1;
}

char libSQL_odbc32_is_dll (void)
{
    return 1;
}
#endif /* WIN32 && DLL_EXPORT */

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

void
A4GLSQLLIB_A4GLSQL_map_tname(char *code, char *db)
{
    void *ptr = NULL;
    char *codeu;
    A4GL_dbg ("In A4GLSQLLIB_A4GLSQL_map_tname: code=\"%s\" db=\"%s\"", code, db);
    codeu = acl_strdup(code);
    A4GL_convupper(codeu);
    ptr = A4GL_find_pointer(codeu, RUNTIME_MAPPED_TNAME);
    if (ptr != NULL)
    {
        A4GL_del_pointer(codeu, RUNTIME_MAPPED_TNAME);
        acl_free(ptr);
    }
    A4GL_add_pointer(codeu, RUNTIME_MAPPED_TNAME, acl_strdup(db));
    A4GL_dbg("table name mapping added: \"%s\"(code) \"%s\"(db)\n", codeu, db);
    acl_free(codeu);
}

void
A4GLSQLLIB_A4GLSQL_unmap_tname(char *code)
{
    void *ptr = NULL;
    char *codeu;
    A4GL_dbg ("In A4GLSQLLIB_A4GLSQL_unmap_tname: code=\"%s\"", code);
    codeu = acl_strdup(code);
    A4GL_convupper(codeu);
    ptr = A4GL_find_pointer(codeu, RUNTIME_MAPPED_TNAME);
    if (ptr != NULL)
    {
        A4GL_del_pointer(codeu, RUNTIME_MAPPED_TNAME);
        acl_free(ptr);
        A4GL_dbg("table name mapping removed: \"%s\"\n", codeu);
    }
    else
    {
        A4GL_wrn("trying to remove table name mapping \"%s\", while not mapped (ignored)\n", codeu);
    }
    acl_free(codeu);
}

int
A4GLSQLLIB_A4GLSQL_is_tname_mapped(char *code)
{
    char *codeu;
    int retval;
    A4GL_dbg ("In A4GLSQLLIB_A4GLSQL_is_tname_mapped: code=\"%s\"", code);
    codeu = acl_strdup(code);
    A4GL_convupper(codeu);
    retval = A4GL_has_pointer(codeu, RUNTIME_MAPPED_TNAME);
    acl_free(codeu);
    return retval;
}

static char *lower(char *s)
{
    static char *last=0;
    if (last) acl_free(last);
    last=acl_strdup(s);
    A4GL_convlower(last);
    return last;
}


int
A4GL_has_cache_column (char *buff)
{
    int r;
    A4GL_trc ("In A4GL_has_cache_column buff=\"%s\"", buff);
    r=(int)A4GL_has_pointer (lower(buff), CACHE_COLUMN);
    A4GL_trc ("Returning %i", r);
    return r;
}


char *
A4GL_find_cache_column(char *buff)
{
    //char *buffx;
    char *ptr;
    A4GL_trc ("In A4GL_find_cache_column buff=\"%s\"", buff);
    ptr=A4GL_find_pointer (lower(buff), CACHE_COLUMN);
    A4GL_trc ("Returning %p", ptr);
    return  ptr;
}

void
A4GL_add_cache_column(char*buff,char*def)
{
    A4GL_trc ("In A4GL_find_cache_column buff=\"%s\" def=\"%s\"", buff, def);
    A4GL_add_pointer (lower(buff), CACHE_COLUMN, acl_strdup (def));
}


static void
prettyprint_sql (char *sql, struct BINDING *ibind, int nibind, char *fromwhere)
{
    int c;
    FILE *f;
    int a;
    char buff[20000];
    char sbuff[20000];
    int b;
    static int log_sql = -1;
    static char * log_sql_file = "/tmp/log.sql";
    static int first_open = 1;

    if (log_sql == -1)
        log_sql = A4GL_isyes (acl_getenv ("LOGODBCSQL"));

    if (!log_sql)
        return;

    c = 0;
    b = 0;

    if (first_open)
    {
        first_open = 0;
        f = fopen (log_sql_file, "w");
    }
    else
    {
        f = fopen (log_sql_file, "a");
    }

    if (f == NULL)
    {
        A4GL_wrn("Error opening SQL log file: '%s': %s",
                  log_sql_file, strerror(errno));
        log_sql = 0;
    }

    if (ibind == 0)
    {
        if (!strchr (sql, '?'))
        {
            FPRINTF (f, "%s;\n", sql);
        }
        fclose (f);
        return;
    }


    for (a = 0; a < strlen (sql); a++)
    {
        if (sql[a] != '?')
        {
            buff[b++] = sql[a];
            continue;
        }

        SPRINTF1 (sbuff, "'?%d'", ibind[c].dtype);

        if (ibind[c].dtype == DTYPE_CHAR)
        {
            static char *buff = 0;
            char *ptr;
            int a = 0;
            int b = 0;
            ptr = ibind[c].ptr;

            if (strchr (ptr, '\''))
            {
                buff = acl_realloc (buff, (strlen (ibind[c].ptr) * 2) + 1);
                for (a = 0; a < strlen (ptr); a++)
                {
                    if (ptr[a] != '\'')
                    {
                        buff[b++] = ptr[a];
                    }
                    else
                    {
                        buff[b++] = '\'';
                        buff[b++] = '\'';
                    }
                }
                buff[b] = 0;

                SPRINTF1 (sbuff, "'%s'", buff);
            }
            else
            {
                SPRINTF1 (sbuff, "'%s'", ptr);
            }
        }


        if (ibind[c].dtype == DTYPE_SMINT)
        {
            SPRINTF1 (sbuff, "%d", *(short *) ibind[c].ptr);
        }

        if (ibind[c].dtype == DTYPE_INT)
        {
            SPRINTF1 (sbuff, "%ld", *(long *) ibind[c].ptr);
        }


        if (ibind[c].dtype == DTYPE_FLOAT)
        {
            SPRINTF1 (sbuff, "%lf", *(double *) ibind[c].ptr);
        }

        if (ibind[c].dtype == DTYPE_SMFLOAT)
        {
            SPRINTF1 (sbuff, "%f", *(float *) ibind[c].ptr);
        }

        if (ibind[c].dtype == DTYPE_DECIMAL)
        {
            char *ptr;
            int dtype;
            dtype = ibind[c].dtype + ENCODE_SIZE (ibind[c].size);
            A4GL_push_variable (ibind[c].ptr, dtype);
            ptr = A4GL_char_pop ();
            SPRINTF1 (sbuff, "%s", ptr);
            acl_free (ptr);
        }

        if (ibind[c].dtype == DTYPE_DATE)
        {
            char *ptr;
            A4GL_push_date (*(long *) ibind[c].ptr);
            ptr = A4GL_char_pop ();
            SPRINTF1 (sbuff, "'%s'", ptr);
            acl_free (ptr);
        }
        buff[b] = 0;
        strcat (buff, sbuff);
        b = strlen (buff);
        c++;
    }
    buff[b] = 0;
    FPRINTF (f, "%s;\n", buff);
    fclose (f);
}


static void
ensure_as_char (void)
{
    static int ensured = 0;
    if (ensured)
        return;
    ensured++;

    if (A4GLSQLCV_check_requirement ("DATE_AS_CHAR"))
        date_as_char = 1;
    if (A4GLSQLCV_check_requirement ("DTIME_AS_CHAR"))
        dtime_as_char = 1;

    if (A4GL_isno (acl_getenv ("DATE_AS_CHAR")))
        date_as_char = 0;
    if (A4GL_isno (acl_getenv ("DTIME_AS_CHAR")))
        dtime_as_char = 0;
}


static void
set_conv_4gl_to_c (void)
{
    ensure_as_char ();
    A4GL_trc ("In set_conv_4gl_to_c");
    if (date_as_char)
    {
        conv_4gl_to_c[7] = SQL_C_CHAR;
        fgl_sizes[7] = 20;
    }
    else
    {
        conv_4gl_to_c[7] = SQL_C_DATE;
        fgl_sizes[7] = sizeof (long);
    }

    if (dtime_as_char)
    {
        conv_4gl_to_c[10] = SQL_C_CHAR;
        fgl_sizes[10] = 30;
    }
    else
    {

#ifdef SQL_C_DATETIME
        conv_4gl_to_c[10] = SQL_C_DATETIME;     // Was timestamp
        fgl_sizes[10] = 20;
#else
        conv_4gl_to_c[10] = SQL_C_TIMESTAMP;    // Was timestamp
        fgl_sizes[10] = 20;
#endif
    }
}


static unsigned int set_flag(unsigned int flags, int bit, Bool value)
{
    unsigned int mask;
    A4GL_assertion (bit < 0 || bit > 31, "Bit flag specification not in range 0..31");
    mask = 1 << bit;
    if (value)
    {
	if (!(flags & mask))
	    flags += mask;
    }
    else
    {
	if (flags & mask)
	    flags -= mask;
    }
    return flags;
}
static Bool get_flag(unsigned int flags, int bit)
{
    unsigned int mask;
    A4GL_assertion (bit < 0 || bit > 31, "Bit flag specification not in range 0..31");
    mask = 1 << bit;
    return flags & mask ? True : False;
}

static void sid_set_singleton(struct s_sid *sid, Bool flg)
{
    sid->extra_info = (void*)set_flag((unsigned int)(sid->extra_info), FLAG_SINGLETON, flg);
}
 
static Bool sid_get_singleton(struct s_sid *sid)
{
    return get_flag((unsigned int)(sid->extra_info), FLAG_SINGLETON);
}
 
static void sid_set_prepared(struct s_sid *sid, Bool flg)
{
    sid->extra_info = (void*)set_flag((unsigned int)(sid->extra_info), FLAG_PREPARED, flg);
}
 
static Bool sid_get_prepared(struct s_sid *sid)
{
    return get_flag((unsigned int)(sid->extra_info), FLAG_PREPARED);
}
 
static void sid_set_owns_bindings(struct s_sid *sid, Bool flg)
{
    sid->extra_info = (void*)set_flag((unsigned int)(sid->extra_info), FLAG_OWNS_BINDINGS, flg);
}

static Bool sid_get_owns_bindings(struct s_sid *sid)
{
    return get_flag((unsigned int)(sid->extra_info), FLAG_OWNS_BINDINGS);
}

static void cid_set_open(struct s_cid *cid, Bool flg)
{
    cid->extra_info = (void*)set_flag((unsigned int)(cid->extra_info), FLAG_OPEN, flg);
//    cid->hstmt = (void*)flg;
}

static Bool cid_get_open(struct s_cid *cid)
{
    return get_flag((unsigned int)(cid->extra_info), FLAG_OPEN);
//    return cid->hstmt == 0 ? False : True;
}
    
static void sid_set_owns_sqlstr(struct s_sid *sid, Bool flg)
{
    sid->extra_info = (void*)set_flag((unsigned int)(sid->extra_info), FLAG_OWNS_SQLSTR, flg);
}

static Bool sid_get_owns_sqlstr(struct s_sid *sid)
{
    return get_flag((unsigned int)(sid->extra_info), FLAG_OWNS_SQLSTR);
}

/**
 * Sets the parameters of an SQL statement.
 *
    a4gl_sqlca.sqlcode = -1;
 * This is where the ODBC call to SQLBindParameter() is made.
 *
 * @param hstmt Statement information handle.
 * @param ipar Position of the parameter.
 * @paramfCType Data type
 * @param fSqlType Data type
 * @param cbColDef
 * @param ibScale
 * @param rgbValue Pointer to the place wher the informationshould be used.
 * @param pcbValue
 * @return
 *   - 0 : An error ocurred.
 *   - 1 : Done.
 */
int SQL_API
A4GL_newSQLSetParam (SQLHSTMT hstmt, SQLUSMALLINT ipar, SQLSMALLINT fCType, SQLSMALLINT fSqlType,
        SQLUINTEGER cbColDef, SQLSMALLINT ibScale, PTR rgbValue,
        SQLINTEGER FAR * pcbValue)
{
    SQLRETURN rc;

    A4GL_trc ("In A4GL_newSQLSetParam");

    A4GL_dbg ("Setting parameter %d to type %d (%d) %d (%d)", ipar, fSqlType,
                SQL_C_BINARY, fCType, SQL_PARAM_INPUT);

    if (fCType == SQL_C_BINARY)
    {
        static SQLINTEGER cbval;
        A4GL_dbg ("Setting blob data");
        cbval = 0;
        rc = SQLBindParameter (hstmt, ipar, SQL_PARAM_INPUT, SQL_C_BINARY,
                               SQL_LONGVARBINARY, 0, 0, rgbValue, 0, &cbval);
        cbval = SQL_LEN_DATA_AT_EXEC (64000);
        A4GL_trc ("cbval=%d", cbval);
        return_chk_rc (rc, hstmt, "SQLBindParameter");
    }

    A4GL_trc ("SQLBindParam %p %d %d %d %d %d %d %d", hstmt, ipar, fCType,
            fSqlType, cbColDef, ibScale, rgbValue, pcbValue);

    rc = SQLBindParameter (hstmt, ipar, SQL_PARAM_INPUT,
            fCType, fSqlType, cbColDef, ibScale, rgbValue, 256, pcbValue);      // 3200
    return_chk_rc (rc, hstmt, "SQLBindParameter");
}


/**
 * Process the binding of the variables to the statement.
 *
 * After this, the SQL statemen knows where to put or get values.
 *
 * @param b A pointer to the varaiable binding structure.
 * @param n The number of elements in the binding array.
 * @param t The bind type
 *   - i :  Input binding.
 *   - o :  Output binding.
 * @param hstmt Statement handle.
 * @return
 *   - 0 : An error ocurred.
 *   - 1 : Done.
 */
int
A4GL_proc_bind (struct BINDING *b, int n, char t, HSTMT hstmt)
{
    int a;
    SQLRETURN rc;

    SQLSMALLINT nin = 0;
    SQLSMALLINT nout = 0;

    A4GL_dbg ("In proc_bind: binding %p n=%d t=%c, stmt=%p", b, n, t, hstmt);

    if (b == 0)
	return True;
//        retfail("null binding");

#ifdef DEBUG
    for (a = 0; a < n; a++)
        A4GL_trc ("%d=   dtype=%d ptr=%p size=%d",
                a, b[a].dtype, b[a].ptr, b[a].size);
#endif


    if (t == 'i')
    {
        rc = SQLNumParams (hstmt, &nin);
        chk_rc_retonfail(rc, hstmt, "SQLNumParams");

        A4GL_trc ("Found %d parameters are required...", nin);

        if (n != nin)
        {
            A4GL_err ("Number of host variables does not A4GL_match %d (given) !=%d (in sql)",
                     n, nin);
//            A4GLSQL_set_status(-1, 0);
	    exitwith_sql_odbc ("Number of host variables does not match the sql string");
	    return False;
        }
        A4GL_trc ("Looks like we have the right number..");
    }

    nout = -1;

    if (!A4GL_isyes (acl_getenv ("NOSCRATCHOBIND")))
    {
        if (t == 'o')
        {
            A4GL_trc ("Getting num result cols");
            rc = SQLNumResultCols (hstmt, &nout);
            if (!chk_rc (rc, hstmt, "SQLNumResultCols"))
            {
                nout = -1;
		return False;
            }
            else
                A4GL_dbg ("num result cols = %d", nout);
        }
    }

    for (a = 1; a <= n; a++)
    {
        A4GL_trc ("Binding parameter %d ", a);
        if (t == 'o')
        {
            if (!A4GL_obind_column (a, &b[a - 1], hstmt))
	        return False;
        }
        else
        {
            if (!A4GL_ibind_column (a, &b[a - 1], hstmt))
	        return False;
        }
        A4GL_trc ("Binding done...");
    }

    if (t == 'o')
    {
        if (!A4GL_isyes (acl_getenv ("NOSCRATCHOBIND")))
        {
            if (nout != -1 && n < nout)
            {
                int b = 0;
                struct BINDING bind;
                A4GL_dbg ("Binding scratch !!");
                bind.ptr = scratch[b];
                bind.dtype = 0;
                bind.size = 254;
                // We've got too few!
                for (a = n + 1; a <= nout; a++)
                {
                    A4GL_dbg ("Binding scratch @ %d", a);
                    if (!A4GL_obind_column (a, &bind, hstmt))
			return False;
                }
            }
        }
    }
    A4GL_dbg ("OK");
    return True;
}

/**
 * Find a cursor in the pointer tree.
 *
 * @param cname The name of the cursor to be found.
 * @return A pointer to the cursor information.
 */
struct s_cid *
A4GLSQL_find_cursor (char *cname)
{
    struct s_cid *ptr;

    ptr = (struct s_cid *) A4GL_find_pointer_val (cname, CURCODE);
    if (ptr)
        return ptr;

    exitwith_sql_odbc_errm ("Cursor (%s) not found", cname);
    return NULL;
}

static Bool prepare_statement_internal(struct s_sid *sid, char *s)
{
    SQLRETURN rc;
    sid->select = acl_strdup(s);
    sid->hstmt = NULL;

    A4GL_dbg("In prepare_statement_internal: sid=%p, sid->select=\"%s\", s=\"%s\"", sid, sid->select, s);

    if (A4GL_new_hstmt((SQLHSTMT*) &sid->hstmt))
    {
        A4GL_assertion (sid->hstmt == 0, "No statement");
        A4GL_trc ("A4GL_new_hstmt() allocated sid->hstmt=%p", sid->hstmt);
        rc = SQLPrepare (sid->hstmt, (SQLCHAR*)sid->select, SQL_NTS);
        if (!chk_rc(rc, sid->hstmt, "SQLPrepare"))
	{
	    exitwith_sql_odbc_errm ("Preparing statement failed: %s", sid->select);
	    return False;
	}
    }
    else
    {
	return False;
    }
    return True;
}

/**
 * Prepare a select statement.
 *
 * @todo : Check if the binds passes are arrays and if so put one more *
 *
 * @param ibind The input bind array (??).
 * @param ni The number of elements binded.
 * @param obind The output bind array (???).
 * @param no The number of output elements binded.
 * @param s The text of the select statement.
 */
void *
A4GLSQLLIB_A4GLSQL_prepare_select_internal (void *vibind, int ni,
                                            void *vobind, int no,
                                            char *s, char *uniqid, int singleton)  /* mja */
{
    struct s_sid *sid;
    struct BINDING *ibind;
    struct BINDING *obind;
    ibind = vibind;
    obind = vobind;

    A4GL_dbg ("In A4GLSQLLIB_A4GLSQL_prepare_select_internal: vibind=%p ni=%i vobind=%p no=%i s=\"%s\"",
	    vibind, ni, vobind, no, s);
    A4GL_clear_sqlca();

    sid = acl_malloc2 (sizeof (struct s_sid));
    sid->extra_info = 0;
    sid_set_singleton(sid, singleton);

    sid->select = acl_strdup (s);
    sid_set_owns_sqlstr(sid, True);

    // I'm going to copy the bindings....
    sid->ibind = acl_malloc2 (sizeof (struct BINDING) * ni);
    memcpy (sid->ibind, ibind, sizeof (struct BINDING) * ni);
    sid->obind = acl_malloc2 (sizeof (struct BINDING) * no);
    memcpy (sid->obind, obind, sizeof (struct BINDING) * no);
    sid_set_owns_bindings(sid, True);

    sid->ni = ni;
    sid->no = no;
    sid->hstmt = NULL;

    A4GL_trc("Before prepare_statement_internal");
    if (prepare_statement_internal(sid, s))
    {
	A4GL_trc("Prepare OK");
	return sid;
    }
    else
    {
	exitwith_sql_odbc_errm ("Preparing statement failed: %s", s);
	acl_free(sid);
	return NULL;
    }
}


/**
 * Declare a cursor.
 *
 * @param upd_hold Indicate if the cursor is for update or with hold.
 * @param sid Select statement to use with the cursor.
 * @param scroll Indicate if is a scrolling cursor:
 *   - 0 :
 *   - 1 :
 * @param cursname The cursor name.
 * @return A pointer to the cursor informationstrucutre.
 */
void *
A4GLSQLLIB_A4GLSQL_declare_cursor (int upd_hold, void *vsid,
                                                int scroll, char *cursname)
{
#if (ODBCVER >= 0x0300)
    //static SQLUINTEGER is_scrollable=SQL_SCROLLABLE;
    //static SQLUINTEGER isnot_scrollable=SQL_NONSCROLLABLE;
#endif
    struct s_sid *nsid = NULL;
    struct s_sid *sid;
    struct s_cid *cid;
    SQLRETURN rc;

    sid = vsid;

    cid = (struct s_cid *) A4GL_find_pointer_val (cursname, CURCODE);
    if (cid)
    {
	if (cid_get_open(cid))
	{
	    rc = SQLFreeStmt ((SQLHSTMT) cid->statement->hstmt, SQL_CLOSE);
	    if (!chk_rc (rc, cid->statement->hstmt, "SQLFreeStmt(SQL_CLOSE)"))
	    {
		exitwith_sql_odbc_errm ("Closing cursor (%s) failed", cursname);
		return NULL;
	    }
	    cid_set_open(cid, False);
	}
	if (sid_get_singleton(cid->statement))
	    sql_free_sid(&cid->statement);
	else
	    sql_free_stmt(&cid->statement->hstmt);
	A4GL_del_pointer (cursname, CURCODE);
    }

    A4GL_clear_sqlca();

    A4GL_dbg("Declaring cursor cursname='%s' sid=%p upd_hold=%d scroll=%d",
             cursname, sid, upd_hold, scroll);
    if (sid == 0)
    {
	exitwith_sql_odbc_errm ( "declare_cursor (%s): Statement could not be found (sid == 0)", cursname);
	return NULL;
    }

    if (sid_get_singleton(sid) && !scroll)
    {
	A4GL_trc ("Singleton and not scrollable - can safely use original sid");
	nsid = sid;
    }
    else
    {
	A4GL_trc ("Need to use a new statement");
	if (sid_get_singleton(sid))
	{
	    A4GL_trc ("Singleton and scrollable - can safely use original sid, but must use new hstmt");
	    nsid = sid;
	    A4GL_trc ("Old hstmt useless - freeing orig hstmt=%p", sid->hstmt);
	    sql_free_stmt(&sid->hstmt);
	}
	else
	{
	    A4GL_trc ("Not singleton - must use a new sid");

	    // prepare new sid
	    nsid = acl_malloc2 (sizeof (struct s_sid));
	    A4GL_trc("Malloced nsid=%p", nsid);
	    nsid->extra_info = 0;
	    sid_set_owns_bindings(nsid, False);
	    sid_set_singleton(nsid, True);

	    nsid->hstmt = 0;
	    nsid->ibind = sid->ibind;
	    nsid->ni = sid->ni;
	    nsid->obind = sid->obind;
	    nsid->no = sid->no;
	    sid_set_prepared(nsid, False);
	    A4GL_dbg ("nsid->hstmt=%p", sid->hstmt);
	    A4GL_trc ("nsid->ibind=%p nsid->ni=%d nsid->no=%s", nsid->ibind, nsid->ni, nsid->no);

	    nsid->select = sid->select;
	    sid_set_owns_sqlstr(nsid, False);
	}

	if (!A4GL_new_hstmt ((SQLHSTMT*) &nsid->hstmt))
	{
	    if (nsid)
		acl_free(&nsid);
	    return NULL;
	}

	A4GL_trc ("Got statement");

	if (scroll)
	{
	    A4GL_dbg ("Setting dynamic cursor");

#if (ODBCVER >= 0x0300) && !PGODBC
	    if (!A4GL_isyes (acl_getenv ("NO_ATTR_CURSOR")))
	    {
		A4GL_dbg ("Setting cursor type to scrollable");
		rc = SQLSetStmtAttr ((SQLHSTMT) nsid->hstmt, SQL_ATTR_CURSOR_TYPE,
				     (SQLPOINTER) SQL_CURSOR_STATIC, 0);
		ignore_next_sql_error = 1;
		chk_rc (rc, nsid->hstmt, "SQLSetStmtAttr - CURSOR TYPE");

		rc = SQLSetStmtAttr ((SQLHSTMT) nsid->hstmt,
				     SQL_ATTR_CURSOR_SCROLLABLE,
				     (SQLPOINTER) SQL_SCROLLABLE, 0);
		ignore_next_sql_error = 1;
		chk_rc (rc, nsid->hstmt, "SQLSetStmtAttr - CURSOR SCROLLABLE");

		if (rc == -1)
		{           // Well - we tried...
		    rc = 0;
		}

		if (rc != SQL_SUCCESS)
		{
		    //SQLINTEGER bl;
		    SQLINTEGER sl;
		    SQLUINTEGER r = 99;
		    SQLUINTEGER r2 = 99;
		    SQLGetStmtAttr (nsid->hstmt, SQL_ATTR_CURSOR_SCROLLABLE, &r,
			    sizeof (r), &sl);
		    SQLGetStmtAttr (nsid->hstmt, SQL_ATTR_CURSOR_TYPE, &r2,
			    sizeof (r2), &sl);
		    // It didn't like that ?
		    A4GL_wrn ("Asked for %x (SQL_SCROLLABLE) - got %x %x", SQL_SCROLLABLE, r, r2);
		}
	    }
	    else
	    {
		rc = SQLSetStmtOption ((SQLHSTMT) nsid->hstmt, SQL_CURSOR_TYPE,
				       SQL_CURSOR_STATIC);
	    }
#else
	    rc = SQLSetStmtOption ((SQLHSTMT) nsid->hstmt, SQL_CURSOR_TYPE,
				   SQL_CURSOR_STATIC);
#endif
//	    if (rc == 1)
//		rc = 0;
	    ignore_next_sql_error = 1;
	    chk_rc (rc, nsid->hstmt, "SQLSetStmtOption SCROLL_STATIC");

	}
    }

    // prepare new cid
    cid = acl_malloc2 (sizeof (struct s_cid));
    cid->extra_info = 0;
    nsid->extra_info = 0;
    A4GL_trc("Malloced cid=%p", cid);
    cid->statement = nsid;
    A4GL_trc ("cid->statement=%p (same as nsid)", cid->statement);
    cid->mode = upd_hold + scroll * 256;
    cid_set_open(cid, False);

    A4GL_trc ("Adding cursor %s", cursname);
    A4GL_add_cursor (cid, cursname);

    rc = SQLSetCursorName (nsid->hstmt, (SQLCHAR*)cursname, SQL_NTS);
    if (!chk_rc(rc, nsid->hstmt, "SQLSetCursorName"))
    {
	exitwith_sql_odbc_errm ("declare_cursor: Cannot set cursor name (%s)", cursname);
	cid = 0;
	if (sid_get_singleton(nsid))
	    sql_free_sid(&nsid);
	else
	    sql_free_stmt(&nsid->hstmt);
        acl_free(cid);
	return 0;
    }
    A4GL_trc ("Returning %p", cid);
    return cid;
}

/**
 * Execute an sql statement where its execution is implicit in 4gl.
 *
 * There are several places where this can occur such as a INPUT or
 * UPDATE, etc.
 *
 * @param sid The statement informnation handle.
 */
int
A4GLSQLLIB_A4GLSQL_execute_implicit_sql (void *vsid, int singleton, int ni, void *binding)
{
    struct s_sid *sid;

    int retval = 0;
    sid = vsid;

    A4GL_dbg ("In A4GLSQLLIB_A4GLSQL_execute_implicit_sql: vsid=%p singleton=%i",
	      vsid, singleton);
    A4GL_clear_sqlca();

    if (sid == 0)
    {
	exitwith_sql_odbc_errm ("Statement (%s) could not be found", "<sid == 0>");
	return False;
    }

    if (ni)
    {
	if (sid_get_owns_bindings(sid))
	{
	    if (sid->ibind)
		acl_free (sid->ibind);
	    sid_set_owns_bindings(sid, False);
	}
	sid->ibind=binding;
	sid->ni=ni;
    }
    
    A4GL_dbg ("no=%d ni=%d sql=%s",
                sid->no, sid->ni, sid->select);
    A4GL_trc ("Calling proc_bind()");
    

    if (!A4GL_proc_bind (sid->obind, sid->no, 'o', (SQLHSTMT) sid->hstmt))
        return 0;
    if (!A4GL_proc_bind (sid->ibind, sid->ni, 'i', (SQLHSTMT) sid->hstmt))
        return 0;
    A4GL_trc ("Bound data ... ni=%d no=%d", sid->ni, sid->no);

    prettyprint_sql (sid->select, sid->ibind, sid->ni, "2");

    A4GL_trc ("Calling ODBC_exec_stmt()");
    retval = ODBC_exec_stmt (&sid->hstmt) ? 1 : 0;

    //  if (retval && singleton) // why not to free sid if failed?
    if (singleton)
        sql_free_sid(&sid);
//    else
//        sql_free_stmt(&sid->hstmt);

    return retval;
}


/**
 * Execute an implicit select instruction.
 *
 * Used when the SELECT is a direct SELECT INTO in 4gl code.
 *
 * @param sid The statement information.
 */
int
A4GLSQLLIB_A4GLSQL_execute_implicit_select (void *vsid, int singleton)
{
    int retval;
    struct s_sid *sid;
    SQLSMALLINT nresultcols;
    sid = vsid;

    A4GL_dbg ("In A4GLSQLLIB_A4GLSQL_execute_implicit_select: vsid=%p singleton=%i",
	      vsid, singleton);
    A4GL_clear_sqlca();

    if (sid == 0)
    {
	exitwith_sql_odbc_errm ("Statement (%s) could not be found", "<sid == 0>");
	return -1;
    }
    A4GL_dbg ("Executing immediate: %s", sid->select);
    if (!A4GL_proc_bind (sid->obind, sid->no, 'o', (SQLHSTMT) sid->hstmt))
        return -1;
    if (!A4GL_proc_bind (sid->ibind, sid->ni, 'i', (SQLHSTMT) sid->hstmt))
        return -1;
    A4GL_trc ("Bound data ... ni=%d no=%d", sid->ni, sid->no);

    prettyprint_sql (sid->select, sid->ibind, sid->ni, "3");

    retval = ODBC_exec_select ((SQLHSTMT) sid->hstmt);

    if (sql_ok(retval) && a4gl_status!=100 )
    {
	SQLRETURN rc;
	nresultcols = 0;
	rc = SQLNumResultCols ((SQLHSTMT) sid->hstmt, &nresultcols);
	chk_rc (rc, sid->hstmt, "SQLNumResultCols");
	if (sql_failed(rc))
	{
	    if (singleton)
		sql_free_sid(&sid);
	    else
		sql_free_stmt(&sid->hstmt);
	}
    }




    if (retval && a4gl_status != 100)
    {
        A4GL_trc ("Calling post_fetch_proc_bind");
        A4GL_post_fetch_proc_bind (sid->obind, sid->no,
                (SQLHSTMT) & sid->hstmt);
        if (nresultcols && nresultcols != sid->no)
        {
            strcpy (a4gl_sqlca.sqlawarn, "       ");
            a4gl_sqlca.sqlawarn[0] = 'W';
            a4gl_sqlca.sqlawarn[3] = 'W';
        }
    }

    /*  if (retval)
        sql_free_stmt(&sid->hstmt);
        else
        A4GL_trc ("retval not set");*/
 
    if (singleton)
        sql_free_sid(&sid);
    else
        sql_free_stmt(&sid->hstmt);

    if (retval == False)
	return -1;
    return  0;
}


/**
 * Open a cursor already declared.
 *
 * @param ni
 * @param s The cursor name.
 * @return
 */
int A4GLSQLLIB_A4GLSQL_open_cursor (char *s, int ni, void *ibind)
{
    struct s_cid *cid;
    char *curs;
    SQLINTEGER rowcount;
    int save_ni = -1;
    SQLRETURN rc;
    struct BINDING *save_ibind = 0;
    SQLRETURN rc2;
    int insertCursor;

    A4GL_clear_sqlca();

    A4GL_dbg ("In A4GLSQLLIB_A4GLSQL_open_cursor s=\"%s\" ni=%d ibind=%p", s, ni, ibind);
    cid = A4GLSQL_find_cursor (s);

    if (cid == 0)
    {
        exitwith_sql_odbc_errm("Cursor (%s) not found", s);
	return 0;
    }

    if (cid_get_open(cid))
    {
	rc = SQLFreeStmt ((SQLHSTMT) cid->statement->hstmt, SQL_CLOSE);
	if (!chk_rc (rc, cid->statement->hstmt, "SQLFreeStmt(SQL_CLOSE)"))
	{
	    exitwith_sql_odbc_errm ("Closing cursor (%s) failed", s);
	    return 0;
	}
    }

    A4GL_trc ("cid=%p cid->statement=%p cid->statement->select='%s'",
	      cid, cid->statement, cid->statement->select);

    insertCursor = strncasecmp (cid->statement->select, "INSERT", 6) == 0
	        || strncasecmp (cid->statement->select, " INSERT", 7) == 0;

    if (ni && ! insertCursor)
    {
        // They've used a value on the OPEN
        save_ni = cid->statement->ni;
        save_ibind = cid->statement->ibind;
        cid->statement->ni = ni;
        cid->statement->ibind = (struct BINDING *) ibind;
    }


    if ( ! sid_get_prepared(cid->statement))
    {
	A4GL_dbg ("calling SQLPrepare s='%s' cid=%p cid->statement=%p cid->statement->select='%s'",
		  s, cid, cid->statement, cid->statement->select);
	A4GL_assertion (cid->statement->hstmt == 0, "No statement");
	rc = SQLPrepare ((SQLHSTMT) cid->statement->hstmt,
		(SQLCHAR*)cid->statement->select, SQL_NTS);

	if (!chk_rc(rc, cid->statement->hstmt, "SQLPrepare"))
	{
	    if (save_ni != -1 && ! insertCursor)
	    {
		cid->statement->ni = save_ni;
		cid->statement->ibind = save_ibind;
	    }
	    exitwith_sql_odbc_errm("Preparing cursor (%s) failed", s);
	    return 0;
	}
	A4GL_trc ("cid->statement->ibind=%p cid->statement->ni=%p",
		cid->statement->ibind, cid->statement->ni);
	sid_set_prepared(cid->statement, True);
    }
    else
    {
	A4GL_dbg ("Using already prepared cursor s='%s' cid=%p cid->statement=%p cid->statement->select='%s'",
		s, cid, cid->statement, cid->statement->select);
    }

    if (insertCursor)
	return 1;

    if (((cid->statement->ni) != ni) && ni > 0)
    {
        A4GL_err ("Too many or too few host variables ni=%d no expected=%d",
                ni, cid->statement->ni);
        if (save_ni != -1)
        {
            cid->statement->ni = save_ni;
            cid->statement->ibind = save_ibind;
        }

	exitwith_sql_odbc_errm("Too many or too few host variables for \"USING\" (cursor (%s))", s);
	return 0;
    }

    A4GL_trc ("Host variables OK");

    curs = cid->statement->select;

    A4GL_trc ("s=%s ni=%d ibind=%p", s, ni, ibind);


    if (!aclfgli_get_err_flg())
    {
        if (ni == 0) /* No USING on the open.. */
        {
            prettyprint_sql (cid->statement->select, cid->statement->ibind,
                             cid->statement->ni, "4");
            if (!A4GL_proc_bind (cid->statement->ibind, cid->statement->ni, 'i',
                                 (SQLHSTMT) cid->statement->hstmt))
	    {
		if (save_ni != -1)
		{
		    cid->statement->ni = save_ni;
		    cid->statement->ibind = save_ibind;
		}
		exitwith_sql_odbc_errm("Binding input failed; cursor (%s)", s);
		return 0;
	    }
        }
        else
        {
#ifdef ndef
            struct BINDING *b;
            int a;
            A4GL_trc ("We dont have a binding - but I'll make one");
            b = acl_malloc2 (sizeof (struct BINDING) * ni);

            for (a = ni - 1; a >= 0; a--)
            {
                b[a].ptr = A4GL_char_pop ();
                A4GL_trc ("Got string as '%s' a=%d\n", b[a].ptr, a);
                b[a].dtype = 0;
                b[a].size = strlen (b[a].ptr);
                A4GL_trc ("Got size as '%d' a=%d\n", b[a].size, a);
            }

            for (a = 0; a < ni; a++)
            {
                A4GL_trc ("%d %d %s", b[a].dtype, b[a].size, b[a].ptr);
            }
#endif

            if (!A4GL_proc_bind (ibind, ni, 'i', (SQLHSTMT) cid->statement->hstmt))
	    {
		if (save_ni != -1)
		{
		    cid->statement->ni = save_ni;
		    cid->statement->ibind = save_ibind;
		}
		exitwith_sql_odbc_errm("Binding input failed; cursor (%s)", s);
		return 0;
	    }
            prettyprint_sql (cid->statement->select, ibind, ni, "5");

        }
    }

    A4GL_dbg ("Executing statement (opening cursor) \"%s\" cid=%p cid->statement->hstmt=%p\n",
	      curs, cid, cid->statement->hstmt);
    /* Execute the SQL statement. */
    rc = SQLExecute ((SQLHSTMT) cid->statement->hstmt); //Reformatted
    if (!chk_rc (rc, cid->statement->hstmt, "SQLExecute"))
    {
	if (save_ni != -1)
	{
	    cid->statement->ni = save_ni;
	    cid->statement->ibind = save_ibind;
	}
	exitwith_sql_odbc_errm("Opening cursor (%s) failed", s);
	return 0;
    }
    cid_set_open(cid, True);
    rc2 = A4GL_chk_need_blob (rc, (SQLHSTMT) & cid->statement->hstmt);

    A4GL_trc ("OBind...");
    if (!A4GL_proc_bind (cid->statement->obind, cid->statement->no, 'o',
		(SQLHSTMT) cid->statement->hstmt))
    {
	if (save_ni != -1)
	{
	    cid->statement->ni = save_ni;
	    cid->statement->ibind = save_ibind;
	}
	exitwith_sql_odbc_errm("Binding output failed; cursor (%s)", s);
	return 0;
    }

    rc = SQLRowCount (cid->statement->hstmt, &rowcount);

    /* chk_rc (rc, cid->statement->hstmt, "SQLRowCount"); */
    a4gl_sqlca.sqlerrd[1] = rowcount;
    if (save_ni != -1)
    {
        cid->statement->ni = save_ni;
        cid->statement->ibind = save_ibind;
    }

    return 1;
}

/**
 * Fetch a cursor into variables.
 *
 * @param cursor_name The cursor name
 * @param fetch_mode The direction of the fetch:
 *  - FETCH_ABSOLUTE
 *  - FETCH_RELATIVE
 * @param fetch_when The number of elements to advance or go back.
 *   - 1
 *   - -1
 *   - Otherwise
 * @param nibind
 * @param ibind
 */
int
A4GLSQLLIB_A4GLSQL_fetch_cursor (char *cursor_name,
                                     int fetch_mode, int fetch_when,
                                     int nibind, void *vibind)
{
    struct s_cid *cid;
    SQLRETURN rc;
    SQLINTEGER nr;
    int use_nbind;
    struct BINDING *use_binding;
    int mode = 0;
    struct BINDING *ibind;
    int use_extended_fetch = -1;


    A4GL_dbg ("In A4GLSQLLIB_A4GLSQL_fetch_cursor cursor_name='%s', fetch_mode=%d, fetch_when=%d, nibind=%d, vibind=%p)",
            cursor_name, fetch_mode, fetch_when, nibind, vibind);

    A4GL_clear_sqlca();

    ibind = vibind;
    a4gl_sqlca.sqlerrd[2] = 0;

    A4GL_trc ("before find cursor");

    cid = A4GLSQL_find_cursor (cursor_name);
    if (cid == 0)
    {
        exitwith_sql_odbc_errm ("Cursor (%s) not found", cursor_name);
        return 0;
    }
    A4GL_trc ("cid=%p", cid);
    if (!cid_get_open(cid))
    {
        exitwith_sql_odbc_errm ("Fetch attempted on unopened cursor (%s)", cursor_name);
        return 0;
    }
    if (nibind == 0)
    {
        A4GL_trc ("   Use cursors bindings..");
        use_binding = cid->statement->obind;
        use_nbind = cid->statement->no;
    }
    else
    {
        A4GL_trc ("   Use fetches bindings..");
        use_binding = ibind;
        use_nbind = nibind;
        A4GL_proc_bind (ibind, nibind, 'o', (SQLHSTMT) cid->statement->hstmt);
    }

    switch (fetch_mode)
    {
      case FETCH_ABSOLUTE:
        A4GL_trc ("Absolute : %d", fetch_when);
        mode = SQL_FETCH_ABSOLUTE;
        break;
      case FETCH_RELATIVE:
        A4GL_trc ("relative : %d", fetch_when);
        mode = SQL_FETCH_RELATIVE;
        break;
    }

    if (mode == SQL_FETCH_RELATIVE)
    {
        if (fetch_when == 1)
        {
            A4GL_trc ("fetch next");
            mode = SQL_FETCH_NEXT;
        }
        if (fetch_when == -1)
        {
            A4GL_trc ("fetch previous");
            mode = SQL_FETCH_PRIOR;
        }
    }

    if (mode == SQL_FETCH_ABSOLUTE)
    {
        if (fetch_when == 1)
        {
            A4GL_trc ("fetch first");
            mode = SQL_FETCH_FIRST;
        }
        if (fetch_when == -1)
        {
            A4GL_trc ("fetch last");
            mode = SQL_FETCH_LAST;
        }
    }

    A4GL_trc ("Before Extended fetch...");


    if (use_extended_fetch == -1)
    {
        use_extended_fetch = 0;
        if (A4GL_chk_getenv ("EXTENDED_FETCH", TRUE))
            use_extended_fetch = 1;
        if (strcmp ("INGRES", A4GLSQL_dbms_dialect ()) == 0)
            use_extended_fetch = 0;
    }

    A4GL_dbg ("use_Extended_fetch=%d\n", use_extended_fetch);

    if (use_extended_fetch == 1 && mode != SQL_FETCH_NEXT)
    {
        A4GL_dbg ("Calling SQLextended/SQLFetchScroll fetch(%p %d %d)",
                cid->statement->hstmt, mode, fetch_when);
        nr = 1;

#if (ODBCVER >= 0x0300) && !PGODBC
        A4GL_dbg ("Calling SQLFetchScroll(%p,%d,%d)",
                    cid->statement->hstmt, mode, fetch_when);
        rc = SQLFetchScroll((SQLHSTMT) cid->statement->hstmt, mode, fetch_when);
        if (!chk_rc(rc, cid->statement->hstmt, "SQLFetchScroll"))
	{
	    exitwith_sql_odbc_errm ("Fetching cursor (%s) failed", cursor_name);
	    return 0;
	}
#else
        A4GL_dbg ("Calling SQLExtendenFetch(%p,%d,%d,&,&)",
                    cid->statement->hstmt, mode, fetch_when);
        {
            SQLUSMALLINT nrs[1000];
            rc = SQLExtendedFetch ((SQLHSTMT) cid->statement->hstmt, mode,
                                   fetch_when, &nr, &nrs[0]);
        }
        if (!chk_rc(rc, cid->statement->hstmt, "SQLExtendedFetch"))
	{
	    exitwith_sql_odbc_errm ("Fetching cursor (%s) failed", cursor_name);
	    return 0;
	}
#endif
    }
    else
    {
        A4GL_dbg ("Calling SQLFetch(%p", cid->statement->hstmt);
        if (mode != SQL_FETCH_NEXT)
            A4GL_wrn("Fetching next and not supposed to..\n");
        rc = SQLFetch ((SQLHSTMT) cid->statement->hstmt);
        if (!chk_rc(rc, cid->statement->hstmt, "SQLFetch"))
	{
	    exitwith_sql_odbc_errm ("Fetching cursor (%s) failed", cursor_name);
	    return 0;
	}
    }
    A4GL_trc ("After fetch rc=%d", rc);
    if (rc == SQL_NO_DATA_FOUND)
    {
        A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode(100);
        return 1;
    }
    a4gl_sqlca.sqlerrd[2] = 1;

    /*
       if (rc != SQL_SUCCESS && rc != SQL_NO_DATA_FOUND)
       {
       A4GL_set_sqlca (cid->statement->hstmt, "ODBC_exec_select : After SQLFetch", 0);
       }
     */

    /*  res = PQexec (conn, cmd); exec */

    A4GL_trc ("use_binding, Calling post_fetch_proc_bind, nibind=%d", use_nbind);
    A4GL_post_fetch_proc_bind (use_binding, use_nbind,
                               (SQLHSTMT) & cid->statement->hstmt);
    return 1;
}

/**
 * Initialize a connection, given an ODBC database/datasource name.
 *
 * If a connection was already opened free the resources used.
 *
 * Gets the username and password from the environment
 * and call A4GLSQL_make_connection().
 *
 * @todo : Substitute the deprecated function SQLFreeConnect.
 * @param       ODBC datasource name (DSN)
 * @return      0 if success (program terminates otherwise)
 */
int
A4GLSQLLIB_A4GLSQL_init_connection_internal (char *dbName_f)
{
    char empty[10] = "None";
    char dbName[2048];
    char *u, *p;
    HDBC *hh = 0;
    SQLRETURN rc = 0;
    char uname_acl[256];
    char passwd_acl[256];


    A4GL_clear_sqlca();

    strcpy (dbName, dbName_f);
    A4GL_trim (dbName);

    /* This section does not apply to "real" SQLite odbc driver since it will use odbc.ini
       settings to look for SQLite database file
#ifdef SQLITEODBC
     */
#ifdef SQLITE_DIRECT
    {
        char a[128], b[128], tmp[2048];
        char *FullPathDBname;
        char DATABASE[128];
        A4GL_dbg ("SQLITE special...");

        /* NOTE:

           When using SQLite, user can use the following DATABASE statement parameters:

           DATABASE example    - will use DBPATH to find SQLite db file, adding .db extension first
           DATABASE "example"  - same
           DATABASE "example.db" - will use DBPATH to find SQLite db file
           DATABASE "/full/path/to/dbfile/example" - will add .db extension, and check for file in specified path
           DATABASE "/full/path/to/dbfile/example.db" - will check for file in specified path
         */


        //See if user specified extension in his DATABASE statement:
        A4GL_bname (dbName, a, b);
        if (a[0] == 0)
        {
            SPRINTF1 (tmp, "%s.db", dbName);
            A4GL_dbg ("Added .db file name extension, dbName=%s", tmp);
        }
        else
        {
            strcpy (tmp, dbName);
        }
        //store DB file name as per DATABASE statement
        SPRINTF1 (DATABASE, "%s", tmp);
        //Find full path to the SQLite database file, use DBPATH
        FullPathDBname = A4GL_fullpath_dbpath ((char *) tmp);

        if (FullPathDBname)
        {
            strcpy (tmp, FullPathDBname);
            //strcpy (dbName,tmp);

            //add db file name as per DATABASE statement to discovered path
            SPRINTF1 (dbName, "%s", tmp);
            A4GL_dbg ("Found SQLite db in '%s'", dbName);
        }
        else
        {
            /*
NOTE: SQLite by default will automatically create a new empty
database file when an attempt to access non-existing database is
made. This will in most casesI though result in complete confusion, since
DATABASE statement will never fail, but then all SQL statements
expecting tables and/or data will fail. But user will think he is
successfully conncted to the database...

So even if automatic creation of new database on first access
sounds like a cool feature, I beleive we better exit here if we
cannot find a specified SQLite database file in DBPATH.

             */
            exitwith_sql_odbc_errm ("SQLite database file not found in DBPATH=%s", acl_getenv ("DBPATH"));
        }
    }
#endif

    A4GL_trc ("A4GLSQL_init_connection(dbName='%s')", dbName);

    if (strcmp (dbName, OldDBname) == 0)
    {
        A4GL_trc ("Already connected - ignored.");
        return 0;
    }

    /* free up the current default connection, if there is one */
    if (A4GL_has_pointer ("default", SESSCODE))
    {
        hh = A4GL_find_pointer_val ("default", SESSCODE);
        rc = SQLFreeConnect ((SQLHSTMT) * hh);
        chk_rc (rc, 0, "SQLFreeConnect");
    }


    if (A4GL_sqlid_from_aclfile (dbName, uname_acl, passwd_acl))
    {
        A4GL_dbg ("Found in ACL File...");
        u = 0;
        p = 0;
        u = acl_getenv_only ("SQLUID");
        p = acl_getenv_only ("SQLPWD");
        if (u && strlen (u) == 0)
            u = 0;
        if (p && strlen (p) == 0)
            p = 0;
        if (!u || !p)
        {
            u = uname_acl;
            p = passwd_acl;
        }
    }
    else
    {

        A4GL_dbg ("**not** found in ACL File...");
        /* get the user name and password from SQLUID, SQLPWD.
         *  if SQLUID not set, then try getlogin() or $LOGNAME
         *  if SQLPWD not set, then prompt user if we can
         */
        u = acl_getenv ("SQLUID");
#if ( ! defined(__MINGW32__))
        /*
FIXME:
can we find out if there is user name/password specified in odbc.ini
before we just override it ?
         */

        if (u == 0 || *u == '\0')
            u = getlogin ();
        /*
           FIXME
           we have something simmilar somewhere in libaubit4gl for WIN32 - find it 
           and use it instead getlogin()
         */
#else
        A4GL_trc ("avoided getlogin() call");
#endif

        /* FIXME: what is LOGNAME ? */
        if (u == 0 || *u == '\0')
            u = acl_getenv ("LOGNAME");
        if (u == 0)
            u = empty;

        p = acl_getenv ("SQLPWD");
        if ((p == 0 || *p == '\0') && *u > '\0')
        {
            /*  prompt user for password - if not specified in odbc.ini -not yet implemented  */
        }
        if (p == 0)
            p = empty;
    }

    A4GL_trc ("user=%s pass=%s", u, p);


    if (A4GLSQL_make_connection (dbName, u, p))
    {
        /* do we have an existing pointer to default */
        hh = A4GL_find_pointer_val ("default", SESSCODE);
        if (hh == 0)
        {
            hh = acl_malloc2 (sizeof (HDBC));
        }
        *hh = hdbc;
        A4GL_add_pointer ("default", SESSCODE, hh);


        A4GL_trc ("AUTOCOM rc=%d", rc);
    }
    else
    {
        exitwith_sql_odbc_errm ("Could not connect to database (%s)", dbName);
    }
    A4GL_trc ("hh=%p for %s", hh, dbName);
    strcpy (OldDBname, dbName);
    return 0;
}


/**
 * Free the resources allocated for a cursor.
 * FIXME: in free.rule, we still print just FIXME comment...
 * The cursor is found in the pointer tree.
 * WARNING: If cursor is not found, the stuff tries to find and
 *          free a statement with the same name
 *
 * @param cname The cursor name.
 * @return Allways zero
 */
void
A4GLSQLLIB_A4GLSQL_free_cursor (char *cname)
{
    struct s_cid *ptr;

    A4GL_dbg ("In A4GLSQLLIB_A4GLSQL_free_cursor: cname=\"%s\"", cname);

    A4GL_clear_sqlca();

    ptr = A4GL_find_pointer_val (cname, CURCODE);
    if (ptr == 0)
    {
        struct s_sid *sid;
        sid = A4GLSQL_find_prepare (cname);
        if (sid != 0)
        {
	    sql_free_sid(&sid);
            A4GL_del_pointer (cname, PRECODE);
            return;
        }
	exitwith_sql_odbc_errm ("Can't free cursor (%s) that hasn't been defined", cname);
    }
    else
    {
	if (sid_get_singleton(ptr->statement))
	    sql_free_sid(&ptr->statement);
	else
	    sql_free_stmt(&ptr->statement->hstmt);
	A4GL_del_pointer (cname, CURCODE);
    }
}

/**
 * Close a cursor.
 *
 * The cursor is found in the pointer tree.
 *
 * @param The cursor name.
 * @return
 *   - -1 A cursor with that name was not found
 *   - 1 Cursor closed
 */
int
A4GLSQLLIB_A4GLSQL_close_cursor (char *cname)
{
    struct s_cid *ptr;
    SQLRETURN rc;

    A4GL_clear_sqlca();

    A4GL_dbg ("In close cursor: cname=\"%s\"", cname);
    ptr = A4GL_find_pointer_val (cname, CURCODE);
    if (ptr == 0)
    {
	exitwith_sql_odbc_errm ("Can't close cursor (%s) that hasn't been defined", cname);
	return -1;
    }

    A4GL_trc ("Freeing cursor cname='%s' ptr=%p", cname, ptr);

    if (cid_get_open(ptr))
    {
	rc = SQLFreeStmt ((SQLHSTMT) ptr->statement->hstmt, SQL_CLOSE);
	if (!chk_rc (rc, ptr->statement->hstmt, "SQLFreeStmt(SQL_CLOSE)"))
	{
	    exitwith_sql_odbc_errm ("Closing cursor (%s) failed", cname);
	    return -1;
	}
	cid_set_open(ptr, False);
    }
    return 1;
}

/**
 * Add a cursor to the pointer tree.
 *
 * @param cid A pointer to the identifing cursor structure.
 * @param cname The cursor name.
 */
void
A4GL_add_cursor (struct s_cid *cid, char *cname)
{
  A4GL_add_pointer (cname, CURCODE, cid);
}

/**
 * Gets the size of the datatype of a table column.
 *
 * @param coltype The data type.
 * @param collen The length of the column.
 * @param colname The name of the column.
 * @return The size calculated.
 */
SQLUINTEGER
A4GL_display_size (SQLSMALLINT coltype, SQLUINTEGER collen, SQLCHAR* colname)
{
    A4GL_trc ("in A4GL_display_size: Coltype=%d %d %s\n", coltype, collen, colname);
    switch (coltype)
    {
      case 0:
      case SQL_CHAR:
      case SQL_VARCHAR:
        A4GL_dbg ("Character string");
        return (max (collen, strlen (colname)));
      case SQL_SMALLINT:
        return (max (6, strlen (colname)));
      case SQL_INTEGER:
        return (max (11, strlen (colname)));
      case SQL_DECIMAL:
      case SQL_NUMERIC:
      case SQL_REAL:
      case SQL_FLOAT:
      case SQL_DOUBLE:
        return (max (MAX_NUM_STRING_SIZE, strlen (colname)));

        /* Note that this function only supports the core data types. */
      case SQL_LONGVARBINARY:
      case SQL_LONGVARCHAR:
      case SQL_VARBINARY:
        return 6;
      case 9:			/* date */

        return 12;
      case 11:			/* datetime */

        return 26;		/* yyyy-mm-dd hh:mm:ss.ffffff */

      case 91:			/* date */
        return 10;
      case 92:			/* time */
        return 8;
      case 93:			/* datetime/timestamp */
        return collen;

      case 10:
        return 8;

      default:
        PRINTF ("Unknown datatype, %d\n", coltype);
        return (0);
    }
}

/**
 * Connects to a database.
 *
 * @param server The database server name. 
 * @param uid_p The user identification.
 * @param pwd_p The password.
 * @return 
 *   - 1 : Connection estabilished.
 *   - 0 : there was an error connecting to database.
 */
int
A4GLSQL_make_connection (char *server, char *uid_p, char *pwd_p)
{
    RETCODE rc;
    char uid[256] = "";
    char pwd[256] = "";
    //RETCODE xrc;

#ifdef DEBUG
    A4GL_dbg ("A4GLSQL_make_connection .. server=%s uid_p=%s pwd_p=%s",
            server, uid_p, pwd_p);
#else
    A4GL_dbg ("A4GLSQL_make_connection .. server=%s uid_p=%s",
	    server, uid_p);
#endif

    /* do nothing if no server, which can happen if fgl_start
     * has no default compile-time database  */
    if ((server == 0) || (strlen (server) == 0))
    {
        A4GL_trc (" no server - no connection.");
        return 1;
    }

    /* copy user name and password, and remove trailing spaces
     */

    A4GL_trim (uid_p);
    A4GL_trim (pwd_p);
    if (uid_p)
        strcpy (uid, uid_p);
    if (pwd_p)
        strcpy (pwd, pwd_p);
    A4GL_trim (uid);
    A4GL_trim (pwd);
    A4GL_trim (server);
    /*
FIXME: we really need more then trim() here - I once had a TAB after
uid by mistake...
     */

    initenv ();
    rc = SQLAllocConnect (henv, &hdbc);
    chk_rc (rc, 0, "SQLAllocConnect");
    A4GL_trc ("Connecting to >%s< as >%s</>%s<", server, uid, pwd);

    // Do we actually need this ?
    // YES, WE ACTUALLY DO!!!
    if (A4GL_isyes (acl_getenv ("AUTOCOMMIT")))
    {
        rc = SQLSetConnectOption (hdbc, SQL_AUTOCOMMIT, 1);
	chk_rc(rc, 0, "SQLSetConnectOption(SQL_AUTOCOMMIT=1)");
        odbc_autocommit = 1;
    }
    if (A4GL_isno (acl_getenv ("AUTOCOMMIT")))
    {
        rc = SQLSetConnectOption (hdbc, SQL_AUTOCOMMIT, 0);
	chk_rc(rc, 0, "SQLSetConnectOption(SQL_AUTOCOMMIT=0)");
        odbc_autocommit = 0;
    }

    rc=0;
#if (ODBCVER >= 0x0300)
#ifdef SQL_CUR_USE_IF_NEEDED
    A4GL_trc ("Cursor use if needed");

    if (!A4GL_isno(acl_getenv("SETODBCCURSORS")))
    {
        if (A4GL_isyes (acl_getenv ("ALWAYS_ODBC_CURSOR")))
        {
	    A4GL_dbg("Setting SQL_CUR_USE_ODBC");
            rc = SQLSetConnectAttr (hdbc, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER) SQL_CUR_USE_ODBC, (SQLINTEGER) 0);
	    chk_rc(rc, 0, "SQLSetConnectAttr(SQL_CUR_USE_ODBC)");
        }
        else
        {
	    A4GL_dbg("Setting SQL_CUR_USE_IF_NEEDED");
            rc = SQLSetConnectAttr (hdbc, SQL_ATTR_ODBC_CURSORS, (SQLPOINTER) SQL_CUR_USE_IF_NEEDED, (SQLINTEGER) 0);
	    chk_rc(rc, 0, "SQLSetConnectAttr(SQL_CUR_USE_IF_NEEDED)");
        }
    }
#else
    if (!A4GL_isno(acl_getenv("NOSETODBCCURSORS")))
    {
        //rc = SQLSetConnectOption(hdbc, SQL_ODBC_CURSORS,SQL_CUR_USE_ODBC );
	A4GL_dbg("Setting SQL_CUR_USE_ODBC");
        rc = SQLSetConnectAttr (hdbc, SQL_ATTR_ODBC_CURSORS,
                        (SQLPOINTER) SQL_CUR_USE_ODBC, (SQLINTEGER) 0);
	chk_rc(rc, 0, "SQLSetConnectAttr(SQL_CUR_USE_ODBC)");
    }
#endif
#else
    A4GL_trc ("ConnectOption - not ConnectAttr");
    rc = SQLSetConnectOption (hdbc, SQL_ODBC_CURSORS, SQL_CUR_USE_IF_NEEDED);
    chk_rc(rc, 0, "SQLSetConnectOption(SQL_CUR_USE_IF_NEEDED)");
#endif

    rc = SQLConnect (hdbc, (SQLCHAR*)server, SQL_NTS, (SQLCHAR*)uid, SQL_NTS, (SQLCHAR*)pwd, SQL_NTS);
    chk_rc (rc, 0, "SQLConnect");

    if (sql_failed(rc))
    {
        return 0;
    }

    A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode(0);
    ODBC_set_dbms_info ();

    rc = SQLSetConnectOption (hdbc, SQL_ASYNC_ENABLE, 0);
    chk_rc(rc, 0, "SQLSetConnectOption(SQL_ASYNC_ENABLE)");
    A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode(0);

    A4GLSQLCV_load_convert ("INFORMIX", dbms_dialect);

    return 1;
}

/**
 * Returns the name of the SQL dialect used
 * by the current connected database
 * eg. "INFORMIX", "SAPDB", "POSTGRESQL"
 *
 * @return  dialect as char string
 */
char *
A4GLSQLLIB_A4GLSQL_dbms_dialect (void)
{
  /* this is set in make_connection */
  return dbms_dialect;
}

/**
 * Returns the name of the currently connected DBMS.
 * eg. "Informix", "SAP DB", "PostgreSQL"
 *
 * @return  pointer to name
 */
char *
A4GLSQLLIB_A4GLSQL_dbms_name (void)
{
  /* this is set in make_connection */
  return dbms_name;
}

/**
 * Sets the dbms_name / dbms_dialect variables, for current session.
 * Should always be called by make_connection() and set_conn().
 *
 * @return Always 0.
 */
void
ODBC_set_dbms_info (void)
{
  SQLRETURN rc;
  short len = 0;
  memset (dbms_name, 0, 64);
  rc = SQLGetInfo (hdbc, SQL_DBMS_NAME, dbms_name, (short) 64, &len);


  A4GL_dbg ("DIALECT : %s\n", dbms_name);
  strcpy (dbms_dialect, "");

  if (strncasecmp (dbms_name, "informix", 8) == 0)
    {
      strcpy (dbms_dialect, "INFORMIX");
      return;
    }

  if (strncasecmp (dbms_name, "sapdb", 5) == 0)
    {
      strcpy (dbms_dialect, "SAPDB");
      return;
    }

  if (strncasecmp (dbms_name, "postgr", 6) == 0)
    {
      strcpy (dbms_dialect, "POSTGRESQL");
      return;
    }
  if (strncasecmp (dbms_name, "POSTGRESQL", 6) == 0)
    {
      strcpy (dbms_dialect, "POSTGRESQL");
      return;
    }

  if (strncasecmp (dbms_name, "oracl", 5) == 0)
    {
      strcpy (dbms_dialect, "ORACLE");
      return;
    }

  if (strncasecmp (dbms_name, "mysql", 5) == 0)
    {
      strcpy (dbms_dialect, "MYSQL");
      return;
    }

  if (strncasecmp (dbms_name, "SQLite", 6) == 0)
    {
      strcpy (dbms_dialect, "SQLITE");
      return;
    }
  if (strncasecmp (dbms_name, "INGRES", 6) == 0)
    {
      strcpy (dbms_dialect, "INGRES");
      return;
    }
  if (strncasecmp (dbms_name, "DB2", 3) == 0)
    {
      strcpy (dbms_dialect, "DB2");
      return;
    }
  if (strncasecmp (dbms_name, "SQLDS/VM", 8) == 0)
    {
      strcpy (dbms_dialect, "DB2VM");
      return;
    }
  if (strncasecmp (dbms_name, "Microsoft SQL Server",20) == 0)
    {
      strcpy (dbms_dialect, "SQLSERVER");
      return;
    }



  strcpy (dbms_dialect, dbms_name);
  /* ( later, this will be set from user-editable config files ) */
}

/**
 * Disconnect the current connection from a datasource.
 *
 * @return Always 0.
 */
int
ODBC_disconnect (void)
{
    SQLRETURN rc;
    A4GL_dbg ("ODBC_disconnect: hdbc=%p", hdbc);
    if (hdbc)
    {
        rc = SQLDisconnect (hdbc);
        chk_rc (rc, 0, "SQLDisconnect");
    }
    /* Free the connection handle.      */
    if (hdbc)
    {
        rc = SQLFreeConnect ((HDBC) hdbc);
        chk_rc (rc, 0, "SQLFreeConnect");
    }
    /* Free the environment handle.     */
    if (henv)
    {
        rc = SQLFreeEnv (henv);
        chk_rc (rc, 0, "SQLFreeEnv");
    }
    return 0;
}

/**
 * Execute an SQL statement trough ODBC.
 *
 * @param sqlstr The sql text to be executed.
 * @return
 *   - 1 : The statement was correctly executed.
 *   - 0 : There was an error.
 */
Bool ODBC_exec_sql (SQLCHAR * sqlstr)
{
  HSTMT hstmt;
  SQLRETURN rc;

  A4GL_dbg ("In ODBC_exec_sql: sqlstr=\"%s\"", sqlstr);

  if (!A4GL_new_hstmt ((SQLHSTMT *) & hstmt))
      return False;

  prettyprint_sql ((char*)sqlstr, 0, 0, "6");

  rc = SQLExecDirect ((SQLHSTMT) hstmt, sqlstr, SQL_NTS);
  chk_rc (rc, 0, "SQLExecDirect");
  if (rc != SQL_SUCCESS)
  {
      sql_free_stmt(&hstmt);
      return False;
  }
  sql_free_stmt(&hstmt);
  return True;
}

/**
 * Execute a prepared sql statement through ODBC.
 * Called from A4GLSQL_execute_implicit_sql()
 *
 * @param hstmt The statement handle.
 * @return
 *   - 1 : The statement was correctly executed.
 *   - 0 : There was an error.
 */
Bool ODBC_exec_stmt (SQLHSTMT *ptr_hstmt)
{
    SQLRETURN rc1;
    SQLRETURN rc2;
    int fake_tr = 0;

    SQLINTEGER rowcount;

    A4GL_trc ("In ODBC_exec_stmt %p", *ptr_hstmt);

    if (ptr_hstmt == 0)
    {
        A4GL_dbg ("Null ptr_hstmt. Returnirng False");
        return False;
    }

    if (*ptr_hstmt == 0)
    {
        A4GL_dbg ("Null *ptr_hstmt. Returnirng 0");
        return False;
    }

    if (do_fake_transactions ())
    {
        // if we're not already in a transaction - start one
        if (!in_transaction)
        {
            fake_tr = 1;
            A4GLSQLLIB_A4GLSQL_commit_rollback (-1);
        }
    }

    rc1 = SQLExecute ((SQLHSTMT) *ptr_hstmt);	// Reformatted in caller
    chk_rc (rc1, *ptr_hstmt, "SQLExecute");

    if (sql_ok(rc1))
    {
        if (fake_tr)
            A4GLSQLLIB_A4GLSQL_commit_rollback (1);
        rc2 = A4GL_chk_need_blob (rc1, *ptr_hstmt);
        chk_rc (rc2, *ptr_hstmt, "SQLExecute/chk_need_blob");
    }
    else
    {
        if (fake_tr)
            A4GLSQLLIB_A4GLSQL_commit_rollback (0);
        A4GL_dbg("SQLExecute failed - returning False");
        return False;
    }

    if (sql_ok(SQLRowCount ((SQLHSTMT) *ptr_hstmt, &rowcount)))
    {
        a4gl_sqlca.sqlerrd[2] = rowcount;
    }
    else
    {
        A4GL_err("SQLRowCount failed - returning False");
        return False;
    }

    A4GL_trc("OK");
//    A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode(0);
    return True;
}

/**
 * Do a output bind of variable to the statement.
 *
 * @param pos Position / sequence in the bind array.
 * @param bind Pointer to the bind array.
 * @param hstmt Statement handle.
 * @return
 *   - 1 : Statement executed.
 *   - 0 : An error ocurred.
 */
int
A4GL_obind_column (int pos, struct BINDING *bind, HSTMT hstmt)
{
  static SQLRETURN rc;
  void *ptr_to_use;
  A4GL_debug ("In A4GL_obind_column, pos=%i, bind=%p hstmt=%p)", pos, bind, hstmt);
  A4GL_trc   ("dtype=%d size=%d ptr=%p", bind->dtype, bind->size, bind->ptr);
  ptr_to_use = bind->ptr;

  set_conv_4gl_to_c ();

  if (bind->dtype == DTYPE_DATE)
    {
      bind->libptr = A4GL_bind_date ((long *) bind->ptr);
      ptr_to_use = bind->libptr;
    }

  if (bind->dtype == DTYPE_DTIME)
    {
      bind->libptr = A4GL_bind_datetime ((void *) bind->ptr);
      ptr_to_use = bind->libptr;
    }

  if (bind->dtype == DTYPE_INTERVAL)
    {
      bind->libptr = A4GL_bind_interval ((void *) bind->ptr);
      ptr_to_use = bind->libptr;
    }

  if (bind->dtype == DTYPE_DECIMAL || bind->dtype == DTYPE_MONEY)
    {
      bind->libptr = A4GL_bind_decimal ((void *) bind->ptr);
      ptr_to_use = bind->libptr;
    }

  if (bind->dtype == DTYPE_BYTE || bind->dtype == DTYPE_TEXT)
    {
      return True;
    }
  outlen[pos] = 0;

  A4GL_trc ("before SQLBindCol (%p,%d,%d,%p,%d,%p)", (SQLHSTMT) hstmt, pos,
	      conv_4gl_to_c[bind->dtype], ptr_to_use,
              fgl_size (bind->dtype, bind->size), &outlen[pos]);

  A4GL_assertion (conv_4gl_to_c[bind->dtype] < 0,
		  "Invalid 4GL<->ODBC conversion of datatype..");

  rc = SQLBindCol ((SQLHSTMT) hstmt, pos, conv_4gl_to_c[bind->dtype],
                   ptr_to_use, fgl_size (bind->dtype, bind->size), &outlen[pos]);

  if (!chk_rc(rc, hstmt, "SQLBindCol"))
      return False;
  /* A4GL_set_sqlca (hstmt, "obind_column : After SQLBindCol", 0); */
  return True;
}

/**
 * Do a input bind of variable to the statement.
 *
 * @param pos Position/sequence of the parameter.
 * @param bin  Pointer to the element in the bin array that decribes the
 * bin to be done.
 * @param hstmt A pointer to the statement information.
 */
int
A4GL_ibind_column (int pos, struct BINDING *bind, HSTMT hstmt)
{
    int size_c = 0;
    int size = 0;
    int isnull;
    /* DATE_STRUCT *tmp; */
    /*review */
    int k = 0;
    void *ptr_to_use = 0;
    SQLRETURN rc;

    isnull = A4GL_isnull (bind->dtype, bind->ptr);

    A4GL_debug ("In A4GL_ibind_column, pos=%i, bind=%p hstmt=%p)", pos, bind, hstmt);
    A4GL_trc   ("dtype=%d size=%d ptr=%p isnull=%i", bind->dtype, bind->size, bind->ptr, isnull);

    ptr_to_use = bind->ptr;

    if (bind->dtype == DTYPE_DATE && A4GL_isyes (acl_getenv ("BINDDATEASINT")))
    {
        rc = A4GL_newSQLSetParam ((SQLHSTMT) hstmt, pos, SQL_INTEGER, SQL_INTEGER,
                                  0, 0, bind->ptr, isnull ? &nullval : NULL);
        return True;
    }

    if (bind->dtype != DTYPE_CHAR && bind->dtype != DTYPE_VCHAR)
    {
        size_c = 0;
    }
    else
    {
        if (bind->start_char_subscript == 0)
        {
            size_c = bind->size;
        }
        else
        {
            if (bind->start_char_subscript > 100000)
            {
                size_c = 0;
                A4GL_assertion (1,
                        "Dubious start substring character  - a test exists if its more that 100,000");
            }
            else
            {
                size_c =
                    bind->end_char_subscript - bind->start_char_subscript + 1;
            }
        }
    }

#ifdef DEBUG
    A4GL_trc ("Binding %d=(dtype=%d size=%d ptr=%p)",
                pos, bind->dtype, bind->size, bind->ptr);
    if (bind->dtype == DTYPE_CHAR || bind->dtype == DTYPE_VCHAR)
    {
        A4GL_trc ("dtype=%d size=%d isnull=%d",
                    bind->dtype, bind->size, isnull);
        A4GL_trc (" is a string : %s size=%d start=%d end=%d  size_c= %d",
                    bind->ptr, bind->size, bind->start_char_subscript,
                    bind->end_char_subscript, size_c);
    }

    if (bind->dtype == DTYPE_CHAR)
    {
        A4GL_trc (" Binding : %s ", bind->ptr);
    }
    set_conv_4gl_to_c ();
    A4GL_trc ("Call SQLSetParam h=%p p=%d dt=%d dt=%d size=%d k=%d ptr=%p",
            hstmt, pos, conv_4gl_to_c[bind->dtype],
            conv_4gl_to_c[bind->dtype], size_c, k, bind->ptr);
#endif

    if (bind->dtype == DTYPE_DATE)
    {
        ACLDATE *p;		//@todo FIXME - THIS WILL CREATE A MEMORY LEAK - 
        // NEED TO CLEAN THIS AFTER ITS FINISHED BEING USED...
        void *ptr;
        int d, m, y;
        A4GL_dbg ("Binding Date original pointer=%p", bind->ptr);
        ptr = bind->ptr;
        p = (ACLDATE *) A4GL_bind_date ((long *) ptr);
        A4GL_get_date (*(int *) ptr, &d, &m, &y);

        ensure_as_char ();

        if (date_as_char)
        {
            A4GL_trc ("date_as_char");
            if (A4GL_isyes (acl_getenv ("BINDDBDATE")))
            {
                char *x;
                A4GL_push_date (*(long *) ptr);
                x = A4GL_char_pop ();
                SPRINTF1 (p->uDate.date_c, "%s", x);
                acl_free (x);
            }
            else
            {
                SPRINTF3 (p->uDate.date_c, "%04d-%02d-%02d", y, m, d);
            }
            size_c = strlen (p->uDate.date_c);
            ptr_to_use = &p->uDate.date_c;
            A4GL_trc ("Binding : %s\n", p->uDate.date_c);
        }
        else
        {
            p->uDate.date_ds.year = y;
            p->uDate.date_ds.month = m;
            p->uDate.date_ds.day = d;
            ptr_to_use = &p->uDate.date_ds;
        }


        bind->libptr = p;
    }

    if (bind->dtype == DTYPE_DTIME)
    {
        ACLDTIME *p;		//@todo FIXME - THIS WILL CREATE A MEMORY LEAK - NEED TO CLEAN THIS AFTER ITS FINISHED BEING USED...
        void *ptr;
        //int d,m,y;
        A4GL_dbg ("Binding Datetime original pointer=%p", bind->ptr);

        ptr = bind->ptr;
        ensure_as_char ();

        p = (ACLDTIME *) A4GL_bind_datetime (ptr);
        if (dtime_as_char)
        {
            char buff[50];
            A4GL_dttoc (ptr, buff, bind->size);
            A4GL_trim (buff);
            strcpy (p->dtime_u.dtime_c, buff);
            size_c = strlen (buff);
            ptr_to_use = &p->dtime_u.dtime_c;
        }
        else
        {
            int arr[10];
            A4GL_decode_datetime ((struct A4GLSQL_dtime *) ptr, &arr[0]);
            p->dtime_u.dtime_t.year = arr[0];
            p->dtime_u.dtime_t.month = arr[1];
            p->dtime_u.dtime_t.day = arr[2];
            p->dtime_u.dtime_t.hour = arr[3];
            p->dtime_u.dtime_t.minute = arr[4];
            p->dtime_u.dtime_t.second = arr[5];
            p->dtime_u.dtime_t.fraction = arr[6];
            ptr_to_use = &p->dtime_u.dtime_t;

        }
        bind->libptr = p;
    }

    if (bind->dtype == DTYPE_INTERVAL)
    {
        ACLIVAL *p;		//@todo FIXME - THIS WILL CREATE A MEMORY LEAK - NEED TO CLEAN THIS AFTER ITS FINISHED BEING USED...
        char buff[50];
        void *ptr;
        //int d,m,y;
        A4GL_dbg ("Binding Datetime original pointer=%p", bind->ptr);

        ptr = bind->ptr;
        p = (ACLIVAL *) A4GL_bind_interval (ptr);
        ensure_as_char ();
        A4GL_inttoc (ptr, buff, bind->size);
        A4GL_trim (buff);
        strcpy (p->ival_u.ival_c, buff);
        size_c = strlen (buff);
        bind->libptr = p;
        ptr_to_use = p;
    }



    if (bind->dtype == DTYPE_DECIMAL || bind->dtype == DTYPE_MONEY)
    {
        double *p;		//@todo FIXME - THIS WILL CREATE A MEMORY LEAK - NEED TO CLEAN THIS AFTER ITS FINISHED BEING USED...
        void *ptr;
        int dtype;
        double d;
        A4GL_dbg ("Allocate for decimal");
        ptr = bind->ptr;
        p = acl_malloc2 (sizeof (double));
        dtype = bind->dtype + ENCODE_SIZE (bind->size);
        A4GL_push_variable (bind->ptr, dtype);
        d = A4GL_pop_double ();
        *p = d;
        bind->libptr = p;
        ptr_to_use = p;

        A4GL_trc ("Bound decimal...\n");
    }

    set_conv_4gl_to_c ();

    A4GL_dbg ("DTYPE %d DTYPE %d SIZE %d", conv_4gl_to_c[bind->dtype],
            conv_4gl_to_c[bind->dtype], size_c);


    if (size_c)
    {
        size = size_c;
        if (isnull)
        {
            A4GL_trc ("Calling setparam1");
            rc = A4GL_newSQLSetParam ((SQLHSTMT) hstmt, pos,
                    conv_4gl_to_c[bind->dtype], conv_4gl_to_c[bind->dtype],
                    size, k, bind->ptr, &nullval);
        }
        else
        {
            SQLINTEGER *sz;
            sz = acl_malloc2 (sizeof (SQLINTEGER));
            *sz = size_c;
            A4GL_trc ("Calling setparam2");
            rc = A4GL_newSQLSetParam ((SQLHSTMT) hstmt, pos,
                    conv_4gl_to_c[bind->dtype], conv_4gl_to_c[bind->dtype],
                    size, k, ptr_to_use, sz);
        }
    }
    else
    {
        A4GL_trc ("Calling setparam3");
        rc = A4GL_newSQLSetParam ((SQLHSTMT) hstmt, pos,
                conv_4gl_to_c[bind->dtype], conv_4gl_to_c[bind->dtype],
                size, k, ptr_to_use, isnull ? &nullval : NULL);
    }

    A4GL_trc ("Called newSQLSetParam = %d", rc);
    /* chk_rc (rc, hstmt, "SQLSetParam"); */
    return True;
}

/**
 * Ask odbc to execute a select statement allready prepared.
 *
 * @param hstmt The statement handle.
 * @return
 *   - 1 : Statement executed.
 *   - 0 : An error ocurred.
 */
Bool ODBC_exec_select (SQLHSTMT hstmt)
{
    SQLRETURN rc;
    SQLSMALLINT nresultcols;

    a4gl_sqlca.sqlerrd[0] = 0;
    A4GL_dbg ("In ODBC_exec_select: hstmt=%p", hstmt);

    rc = SQLExecute (hstmt);	// Reformatted in caller
    chk_rc_retonfail(rc, hstmt, "SQLExecute");

    A4GL_assertion (rc == SQL_NO_DATA_FOUND,
        "SQLExecute returned SQL_NO_DATA - not a select statement?");

    rc = A4GL_chk_need_blob (rc, hstmt);
    if (rc != 0)
    {
        A4GL_wrn ("chk_need_blob returned nonzero status - returning False");
        return False;
    }

    rc = SQLNumResultCols (hstmt, &nresultcols);
    chk_rc_retonfail(rc, hstmt, "ODBC_exec_select: SQLNumResultCols");
    A4GL_trc ("SQLNumResultCols returned nColumns=%d", nresultcols);
    if (nresultcols == 0)
    {
        A4GL_wrn ("SQLNumResultCols returned nColumns=0 - returning False");
        a4gl_sqlca.sqlerrd[0] = 0;
        return False;
    }

    A4GL_trc ("Before Fetch");
    rc = SQLFetch ((SQLHSTMT) hstmt);
    chk_rc_retonfail (rc, hstmt, "SQLFetch");

    if (rc == SQL_NO_DATA_FOUND)
    {
        a4gl_sqlca.sqlerrd[0] = 1;
	A4GLSQL_set_status(100,1);
	a4gl_sqlca.sqlcode=100;
	a4gl_status=100;
        return True;
    }

    rc = SQLFetch ((SQLHSTMT) hstmt);
    if (sql_failed(rc))
	chk_rc_retonfail (rc, hstmt, "SQLFetch");
    if (rc != SQL_NO_DATA_FOUND)
    {
	if (A4GLSQL_set_status (-284, 1))
            set_global_status(-284, "HY000", "A subquery has returned not exactly one row");
        a4gl_sqlca.sqlerrd[0] = 0;
	return False;
    }

    a4gl_sqlca.sqlerrd[0] = 1;
    A4GL_dbg ("Done OK, returning True");
    return True;
}


/**
 * Create a statement handle.
 *
 * Ask to odbc to give a statement handler.
 *
 * @param A pointer to the statement handle structure to be created.
 * @return
 *   - 1 : Statement executed.
 *   - 0 : An error ocurred.
 */
int
A4GL_new_hstmt (SQLHSTMT * phstmt)
{
    SQLRETURN rc;
    Bool status = False;
    A4GL_trc ("Getting new statement, phstmt=%p, database='%s'", phstmt, OldDBname);
    if (hdbc == 0)
    {
        exitwith_sql_odbc_errm ("Not connected to database (%s)", OldDBname);
	return False;
    }
#if (ODBCVER >= 0x300)
    rc = SQLAllocHandle(SQL_HANDLE_STMT, hdbc, phstmt);
    A4GL_dbg ("after SQLAllocHandle: rc=%d, phstmt=%p *phstmt=%p", rc, phstmt, *phstmt);
    status = chk_rc(rc, 0, "SQLAllocHandle");
#else
    rc = SQLAllocStmt(hdbc, phstmt);
    A4GL_dbg ("after SQLAllocStmt: rc=%d, phstmt=%p *phstmt=%p", rc, phstmt, *phstmt);
    status = chk_rc(rc, 0, "SQLAllocStmt");
#endif
//    if (!status)
//        exitwith_sql_odbc ("Allocating a statement failed");
    return status;
}

int conv_sqlprec (int ndtype, int sdim, int scale)
{
    if (ndtype == DTYPE_DECIMAL)
    {
        if (strcmp (dbms_dialect, "ORACLE") == 0)
        {
            //size=((sdim+2)<<8)+2;
            return ((sdim + scale) << 8) + scale;
        }
        if (strcmp (dbms_dialect, "INFORMIX") == 0)
        {
            return (sdim << 8) + scale;
        }
        if (strcmp (dbms_dialect, "DB2") == 0 || strcmp(dbms_dialect, "DB2VM") == 0)
        {
            A4GL_dbg ("ndtype=%i sdim=%i scale=%i ret=%i(0x%x)",
                    ndtype, sdim, scale, (sdim << 8) + scale,
                    (sdim << 8) + scale);
            return (sdim << 8) + scale;
        }
    }
    return sdim;
}

static Bool sql_free_stmt(SQLHSTMT *phstmt)
{
    SQLRETURN rc;
    A4GL_trc("In sql_free_stmt hstmt=%p &hstmt=%p", *phstmt, phstmt);
#if (ODBCVER >= 0x300)
    rc = SQLFreeHandle(SQL_HANDLE_STMT, *phstmt);
    if (!sql_ok(rc))
	chk_rc(rc, *phstmt, "SQLFreeHandle");
#else
    rc = SQLFreeStmt (*phstmt, SQL_DROP);
    if (!sql_ok(rc))
	chk_rc(rc, *phstmt, "SQLFreeStmt");
#endif
    if (sql_ok(rc))
    {
        *phstmt = NULL;
    }
    return sql_ok(rc);
}

static SQLRETURN sql_free_sid(struct s_sid **sid)
{
    SQLRETURN rc;
    A4GL_trc("In sql_free_sid sid=%p &sid=%p", *sid, sid);

    ignore_next_sql_error = 1;
    rc = sql_free_stmt(&((*sid)->hstmt));

    if (sid_get_owns_sqlstr(*sid))
    {
	acl_free((*sid)->select);
	(*sid)->select = NULL;
    }
    if (sid_get_owns_bindings(*sid))
    {
	if ((*sid)->ibind)
	    acl_free ((*sid)->ibind);
	if ((*sid)->obind)
	    acl_free ((*sid)->obind);
    }
    acl_free (*sid);
    return rc;
}
/**
 * Convert the SQL data type to the 4gl data type.
 *
 * Use the table convneg_sql_to_4gl.
 *
 * @param sqldtype The sql datatype returned by ODBC.
 * @param sdim
 * @return The 4gl data type.
 */
static unsigned long conv_sqldtype (int sqldtype, int sdim)
{
    int ndtype;
    A4GL_dbg ("In conv_sqldtype: encoding sqldtype=%d, sdim=%d", sqldtype, sdim);

    //#if (ODBCVER >= 0x0300)
#ifdef SQL_TYPE_DATE
    if (sqldtype == SQL_TYPE_DATE)
    {
        A4GL_dbg ("returning (sqldtype=SQL_TYPE_DATE)->DTYPE_DATE");
        return DTYPE_DATE;
    }
#endif

    if (sqldtype == SQL_TIME)
    {
        A4GL_dbg ("returning (sqldtype=SQL_TIME)->DTYPE_DTIME");
        return DTYPE_DTIME;
    }

    if (sqldtype >= 0)
        ndtype = convpos_sql_to_4gl[sqldtype];
    else
        ndtype = convneg_sql_to_4gl[sqldtype * -1];


    if (ndtype == 0)
    {
        A4GL_dbg ("Encoding string size : %d", sdim);
        ndtype = ENCODE_SIZE (sdim);
    }


    if (A4GL_isyes (acl_getenv ("NODATETIMES")))
    {
        if (ndtype == DTYPE_DTIME)
        {
            ndtype = DTYPE_DATE;
        }
    }


    A4GL_dbg ("returning (sqldtype=%d, sdim=%d)->0x%x ", sqldtype, sdim, ndtype);
    return ndtype;
}

/**
 * Gets the current database name.
 *
 * @return The current database name.
 */
char *
A4GLSQLLIB_A4GLSQL_get_currdbname (void)
{
    return OldDBname;
}

/**
 * Describe a column for an existing statement 
 *
 * @param hstmt The statement handler.
 * @param colno
 * @param type The type of the decribing information to return.
 *   - 0: The column type.
 *   - 1: The column name.
 *   - 2: The scale.
 *   - 3: The column length.
 *   - 4: Nullable or not
 *  @return The description wanted  or zero if there was an error.
 */
long
A4GL_describecolumn (SQLHSTMT hstmt, int colno, int type)
{
    static char colname[256];
    SQLSMALLINT coltype;
    SQLSMALLINT colnamelen;
    SQLSMALLINT nullable;
    SQLUINTEGER collen;
    SQLSMALLINT scale;
    SQLSMALLINT nresultcols;
    SQLINTEGER rowcount;
    SQLRETURN rc;

    if (type == 6)
    {
        A4GL_pause_execution ();
    }
    if (hstmt == 0)
    {
        A4GL_wrn ("Statement %p has not been prepared", hstmt);
        exitwith_sql_odbc ("Statement has not been prepared");
        return 0;
    }

    A4GL_dbg ("hstmt=%p", hstmt);
    if (type == 5)
    {
        nresultcols = 0;
        A4GL_dbg ("SQLNumResultCols");
        chk_rc_retonfail(SQLNumResultCols(hstmt, &nresultcols), hstmt, "SQLNumResultCols");
        A4GL_dbg ("Returning nresultcols=%d\n", nresultcols);
        return nresultcols;
    }

    if (type == 6)
    {
        rowcount = 0;
        A4GL_dbg ("SQLRowCount");
        chk_rc_retonfail(SQLRowCount(hstmt, &rowcount), hstmt, "SQLRowCount");
        return rowcount;
    }


    A4GL_trc ("Describing...");
    rc = SQLDescribeCol (hstmt, colno, (SQLCHAR*)colname, (SQLSMALLINT)sizeof (colname),
                         &colnamelen, &coltype, &collen, &scale, &nullable);
    chk_rc_retonfail(rc, hstmt, "SQLDescribeCol");

    A4GL_dbg ("SQL DATATYPE : Got colname='%s' coltype=%d collen=%d", colname, coltype, collen);
    A4GL_dbg ("Returning description field: field code=%d", type);
    switch (type)
    {
      case 0:
        coltype = conv_sqldtype (coltype, collen);
        return coltype;
      case 1:
        return (long) colname;
      case 2:
        return scale;
      case 3:
        return collen;
      case 4:
        return nullable;
    }

    A4GL_err("Internal Error (describecolumn)");
    exitwith_sql_odbc ("Internal Error (describecolumn)");
    return 0;
}

/**
 * Describe an sql statement.
 *
 * @param stmt The text with the statement to be described.
 * @param colno
 * @param type The type of the information wanted.
 * @return
 */
long
A4GLSQLLIB_A4GLSQL_describe_stmt (char *stmt, int colno, int type)
{
    struct s_sid *sid;
    HSTMT *hstmt = 0;
    struct s_cid *cid;
    long z;

    A4GL_clear_sqlca();

    A4GL_dbg ("In A4GLSQLLIB_A4GLSQL_describe_stmt (stmt=\"%s\", colno=%d, type=%d)",
	      stmt, colno, type);

    sid = A4GLSQL_find_prepare (stmt);

    A4GL_trc ("sid=%p\n", sid);
    cid = 0;

    if (sid == 0)
    {
        A4GL_dbg ("sid == 0 - try as a cursor");
        cid = A4GLSQL_find_cursor (stmt);
        A4GL_trc ("cid == %p", cid);
	if (cid == 0)
	{
	    A4GL_wrn("Statement (%s) neither cursor could not be found (sid == 0 && cid == 0)", stmt);
	    exitwith_sql_odbc_errm ("Statement (%s) could not be found", stmt);
	    return 0;
	}
        hstmt = cid->statement->hstmt;
    }
    else
    {
        hstmt = (SQLHSTMT *) sid->hstmt;
    }

    A4GL_trc ("describecolumn");
    z = A4GL_describecolumn ((SQLHSTMT) hstmt, colno, type);
    A4GL_trc ("Returning %d\n", z);
    return z;
}


// clearTableData - clear also table-specific data (not only column-specific)
static void sql_clear_column_info(struct sql_col_info_data *ci, Bool clearTableData)
{
    // misc variables
    memset(&ci->bd, 0, sizeof(ci->bd));
    memset(ci->colname, 0, sizeof(ci->colname));
    ci->dtype = 0;
    ci->size = 0;
    ci->colsize = 0;
    ci->foundInCache = 0;

    if (clearTableData)
    {
        memset(ci->tabname, 0, sizeof(ci->tabname));
        ci->colidx = 0;
        ci->nColumns = 0;
        ci->hstmt = NULL;

        /*if (ci->hstmt != NULL)
              SQLFreeHandle(SQL_HANDLE_STMT, c->hstmt);
              ci->hstmt = NULL;*/
    }
}

static Bool sql_use_describe(void)
{
    static int useDescribe = -1;
    if (useDescribe == -1)
        useDescribe = A4GLSQLCV_check_requirement("USE_DESCRIBE_NOT_SQLCOLUMNS");
    return useDescribe ? True : False;
}

static Bool sql_cacheschema(void)
{
#ifdef ALWAYS_GETENV_CACHESCHEMA
    return A4GL_isyes(acl_getenv("CACHESCHEMA")) ? True : False;
#else
    static int cacheSchema = -1;
    if (cacheSchema == -1)
        cacheSchema = A4GL_isyes(acl_getenv("CACHESCHEMA"));
    return cacheSchema ? True : False;
#endif
}

char *strncpyz(char *dest, const char *src, size_t n)
{
    if (n == 0)
        return dest;
    if (src == NULL)
        dest[0] = 0;
    else
    {
        strncpy(dest, src, n-1);
        dest[n-1] = 0;
    }
    return dest;
}

// returns false also if CACHESCHEMA disabled
static Bool cache_make_key(char *tabname, char *colname, int colidx, struct sql_col_info_data *ci, char *dstbuf)
{
    if (tabname == NULL)
        return False;
    if (colname == NULL && colidx <= 0)
        return False;
    if (!sql_cacheschema())
        return False;

    if (colname == NULL) //search by colidx
        SPRINTF2 (dstbuf, "%s_%d", tabname, colidx);
    else
        SPRINTF2 (dstbuf, ":%s %s", tabname, colname);

    return True;
}

// internal function, so no extra tabname/colname preprocessing is done
// colname == NULL -> get column by colNo
static void cache_try_add_coldata(char *colname, int colidx, struct sql_col_info_data *ci)
{
    char keybuf[sizeof(ci->colname)+sizeof(ci->tabname)+16];
    char valbuf[sizeof(ci->colname)+64];

    A4GL_dbg("In cache_try_add_coldata: tabname=\"%s\", colname=\"%s\", colidx=%i",
             ci->tabname, colname, colidx);

    if (!cache_make_key(ci->tabname, colname, colidx, ci, keybuf))
    {
        A4GL_dbg("CatalogCache: Not caching column");
        return;
    }

    if (A4GL_has_cache_column(keybuf))
    {
        A4GL_dbg("Catalog cache: Not adding - column already cached");
        return;
    }

    SPRINTF4(valbuf, "%s %d %d %d", ci->colname, ci->dtype, ci->size, ci->prec);
    A4GL_dbg("Catalog cache: Adding to cache key=<%s> val=<%s>\n", keybuf, valbuf);
    A4GL_add_cache_column (keybuf, valbuf);
}

static Bool cache_try_get_coldata(char *tabname, char *colname, int colidx, struct sql_col_info_data *ci)
{
    char keybuf[sizeof(ci->colname)+sizeof(ci->tabname)+16];
    char *ptr;

    if (!cache_make_key(tabname, colname, colidx, ci, keybuf))
        return False;

    sql_clear_column_info(ci, 0);
    A4GL_dbg("Catalog cache: Looking in cache for key <%s>", keybuf);
    ptr = A4GL_find_cache_column(keybuf);
    if (ptr == NULL)
    {
        A4GL_dbg("Catalog cache: Not found in cache");
        return False;
    }

    if (sscanf(ptr, "%s %d %d %d", ci->colname, &ci->dtype, &ci->size, &ci->prec) == 4)
    {
        A4GL_dbg("Catalog cache: found cached column (\"%s\",%d,%d,%d)", ci->colname, ci->dtype, ci->size, ci->prec);
        ci->foundInCache = 1;
        return True;
    }
    else
        A4GL_assertion(1, "Catalog cache: Cache data error. Shouldn't happen, this is a BUG!");
    return False;
}

static int sql_get_next_column_info(struct sql_col_info_data *ci)
{
    SQLRETURN rc;
    sql_clear_column_info(ci, 0);

    if (! sql_use_describe())
    {
        rc = SQLFetch(ci->hstmt);

        if (rc == SQL_NO_DATA_FOUND)
	{
	    if (ci->colidx == 1)
	    {
		exitwith_sql_odbc_errm ("Unable to retrieve column info for table (%s)\n",
			ci->tabname);
	    }
            return 0;
	}

        chk_rc(rc, ci->hstmt, "SQLFetch");
        if (rc == SQL_SUCCESS_WITH_INFO)
        {
            A4GL_dbg("Some problem with SQLFetch for SQLColumns? - SQL_SUCCESS_WITH_INFO returned\n");
            return 0;
        }

        if (rc != SQL_SUCCESS)
        {
            A4GL_wrn ("SQLFetch for SQLColumns failed");
            return 0;
        }
    }
    else //use describe
    {
        SQLSMALLINT cnamelen;
        if (ci->colidx > ci->nColumns)
            return 0;
        rc = SQLDescribeCol(ci->hstmt, ci->colidx, ci->bd.cn, sizeof(ci->bd.cn), &cnamelen,
                &ci->bd.dt, &ci->bd.prec, &ci->bd.scale, &ci->bd.nullable);
        chk_rc(rc, ci->hstmt, "SQLDescribeCol");

        if (rc == SQL_SUCCESS_WITH_INFO)
        {
            A4GL_dbg("Some problem with SQLDescribeCol - SQL_SUCCESS_WITH_INFO returned\n");
            return 0;
        }

        if (rc != SQL_SUCCESS)
        {
            A4GL_wrn ("SQLDescribeCol failed");
            return 0;
        }
    }

    // convert bind data to more useful format
    //  SPRINTF1 (szcolsize, "%d", curcol.colsize);
    ci->colsize = A4GL_display_size(ci->bd.dt, ci->bd.prec, (SQLCHAR*)"");
    ci->prec = ci->bd.prec;
    strncpyz(ci->colname, (char*)ci->bd.cn, sizeof(ci->colname));
    A4GL_convlower(ci->colname);

    ci->dtype = conv_sqldtype(ci->bd.dt, ci->prec);
    if (ci->bd.dt == SQL_TIME)
    {
        ci->dtype = DTYPE_DTIME;
        ci->prec = 0x46;
    }
    ci->size = conv_sqlprec(ci->dtype, ci->prec, ci->bd.scale);
    return 1;
}

static Bool sql_columns(SQLHDBC hdbc, char *tabname, char *colname,
                        struct sql_col_info_data *ci)
{
    char *dotptr = NULL;
    char *owner = NULL;
    char *tname = NULL;
    SQLRETURN rc = 0;

    sql_clear_column_info(ci, 1);
    // some sanity checks and general logic
    if (hdbc == 0)
    {
        A4GL_wrn ("Not connected to database");
        exitwith_sql_odbc ("Not connected to database");
        return False;
    }

    A4GL_assertion(tabname == NULL, "NULL tabname in sql_columns");

    // ok, let's do table name mangling
    strncpyz(ci->tabname, tabname, sizeof(ci->tabname));
    A4GL_trim(ci->tabname);
    A4GL_assertion(strlen(ci->tabname) == 0, "read_columns: empty tabname");

    if (A4GL_isyes (acl_getenv ("UCASETNAME"))
            || strcmp (dbms_dialect, "ORACLE") == 0
            || strcmp (dbms_dialect, "DB2") == 0
            || strcmp (dbms_dialect, "DB2VM") == 0)
        A4GL_convupper(ci->tabname);

    // trim column name if needed
    strncpyz(ci->colname, colname, sizeof(ci->colname));
    A4GL_trim(ci->colname);

    // try to get column's info from cache
    if (cache_try_get_coldata(ci->tabname, ci->colname, 0, ci))
    {
        ci->foundInCache = 1;
        return SQL_SUCCESS;
    }

    if (! sql_use_describe())
    {
        if (!A4GL_new_hstmt(&ci->hstmt))
            return False;

        char *buf = NULL;
        // split table name to owner and table, if applicable
        buf = acl_strdup(ci->tabname);
        dotptr = strchr(buf, '.');
        if (dotptr)
        {
            *dotptr = 0;
            tname = dotptr+1;
            owner = buf;
        }
        else
        {
            tname = buf;
            owner = NULL;
        }

        rc = SQLColumns(ci->hstmt,
                        NULL, 0,
                        (SQLCHAR*)owner, owner ? SQL_NTS : 0,
                        (SQLCHAR*)tname, SQL_NTS,
                        ci->colname[0] == 0 ? NULL : (SQLCHAR*)ci->colname,
                        ci->colname[0] == 0 ? 0 : SQL_NTS);
        acl_free (buf);
        chk_rc_retonfail(rc, ci->hstmt, "SQLColumns");

        {
            SQLRETURN rc1 = 0;
            rc1 = SQLNumResultCols(ci->hstmt, &ci->nColumns);
            chk_rc_retonfail(rc1, ci->hstmt, "SQLNumResultCols");
        }

        A4GL_trc ("nColumns=%d; Binding columns", ci->nColumns);
        if (ci->nColumns == 0)
            A4GL_wrn ("Colunmn count for SQLColumns/GetColumnCount is 0. Weird thing.");

        {
            Bool bindStatus = False;
            bindStatus =
                   chk_rc(SQLBindCol(ci->hstmt, 3, SQL_C_CHAR, ci->bd.tn, sizeof(ci->bd.tn)-1, &ci->bd.len_tn), ci->hstmt, "SQLBindCol(3)")
                && chk_rc(SQLBindCol(ci->hstmt, 4, SQL_C_CHAR, ci->bd.cn, sizeof(ci->bd.cn)-1, &ci->bd.len_cn), ci->hstmt, "SQLBindCol(4)")
                && chk_rc(SQLBindCol(ci->hstmt, 5, SQL_C_LONG, &ci->bd.dt, sizeof(ci->bd.dt), &ci->bd.len_dt), ci->hstmt, "SQLBindCol(5)")
                && chk_rc(SQLBindCol(ci->hstmt, 7, SQL_C_LONG, &ci->bd.prec, sizeof(ci->bd.prec), &ci->bd.len_prec), ci->hstmt, "SQLBindCol(7)")
                && chk_rc(SQLBindCol(ci->hstmt, 8, SQL_C_LONG, &ci->bd.buflen, sizeof(ci->bd.buflen), &ci->bd.len_buflen), ci->hstmt, "SQLBindCol(8)")
                && chk_rc(SQLBindCol(ci->hstmt, 9, SQL_C_LONG, &ci->bd.scale, sizeof(ci->bd.scale), &ci->bd.len_scale), ci->hstmt, "SQLBindCol(9)")
                && chk_rc(SQLBindCol(ci->hstmt, 10, SQL_C_LONG, &ci->bd.radix, sizeof(ci->bd.radix), &ci->bd.len_radix), ci->hstmt, "SQLBindCol(10)")
                && chk_rc(SQLBindCol(ci->hstmt, 11, SQL_C_LONG, &ci->bd.nullable, sizeof(ci->bd.nullable), &ci->bd.len_nullable), ci->hstmt, "SQLBindCol(11)")
                && chk_rc(SQLBindCol(ci->hstmt, 12, SQL_C_CHAR, ci->bd.remarks, sizeof(ci->bd.remarks)-1, &ci->bd.len_remarks), ci->hstmt, "SQLBindCol(12)"); 
            if (!bindStatus)
                retfail("sql_columns: binding failed");
        }
        A4GL_trc ("Bound columns\n");
    }
    else
    {
        char s[512+20];
        if (!A4GL_new_hstmt (& ci->hstmt))
            return False;

        sprintf(s, "select * from %s", ci->tabname);
        rc = SQLPrepare(ci->hstmt, (SQLCHAR*)s, SQL_NTS);
        chk_rc_retonfail(rc, ci->hstmt, "sql_columns: SQLPrepare()");

        rc = SQLNumResultCols(ci->hstmt, &ci->nColumns);
        chk_rc_retonfail(rc, ci->hstmt, "sql_columns: SQLNumResultCols()");

        if (ci->nColumns == 0)
        {
            A4GL_wrn ("Table with 0 columns? Weird thing.");
            return False;
        }
        if (ci->colname[0] != 0 && !sql_cacheschema())
        {
            char *origCname;
            origCname = acl_strdup(ci->colname);
            ci->colidx = 1;
            while (sql_get_next_column_info(ci))
            {
                if (!strcasecmp(origCname, ci->colname))
                {
                    cache_try_add_coldata(NULL, ci->colidx, ci);
                    break;
                }
                ci->colidx++;
            }
            acl_free(origCname);
        }
    }

    if (sql_cacheschema())
    {
        ci->colidx = 1;
        while (sql_get_next_column_info(ci))
        {
            cache_try_add_coldata(NULL, ci->colidx, ci);
            ci->colidx++;
        }
        ci->colidx = 0;
    }
    //fixme return valid column when colname nonempty

    return True;
}

/**
 * Gets information about columns from a table in the database engine.
 *
 * @param tabname The table that we wish to get information about it.
 * @param colname The column name to get information about it.
 * @param dtype A pointer to the variable where to put the data type.
 * @param size A pointer to the variable where to put the size of the column
 *  returned by the database.
 * @return
 *   - 1 : Information readed.
 *   - 0 : Error ocurred.
 */
int
A4GLSQLLIB_A4GLSQL_get_columns (char *tabname, char *colname, int *dtype,
                                    int *size)
{
    //    rc = sql_columns(hdbc, &hstmtGetColumns, tabname, colname, &cidata);
    A4GL_clear_sqlca();

    return sql_columns(hdbc, tabname, NULL, &cidata);
}


/**
 * Iterate in getting information about all columns from a table from the 
 * database engine.
 *
 * A4GLSQL_get_columns(char *tabname) should be called before this one.
 *
 * This is used to declare record like table.*
 *
 * @param colname The place where to put the column name
 * @param dtype A pointer to the variable where to put the data type.
 * @param size A pointer to the variable where to put the size of the column
 *  returned by the database.
 * @return 
 *   - 1 : Information readed.
 *   - 0 : Error ocurred.
 */
int
A4GLSQLLIB_A4GLSQL_next_column (char **colname, int *dtype, int *size)
{
    static char colname_buf[sizeof(cidata.colname)];

    A4GL_clear_sqlca();

    sql_clear_column_info(&cidata, 0);
    cidata.colidx++;

    if (!cache_try_get_coldata(cidata.tabname, NULL, cidata.colidx, &cidata))
    {
        if (!sql_get_next_column_info(&cidata))
            return 0; 

        cache_try_add_coldata(NULL, cidata.colidx, &cidata);
    }
    strncpyz(colname_buf, cidata.colname, sizeof(colname_buf));
    *colname = colname_buf;
    *dtype = cidata.dtype;
    *size = cidata.size;
    return 1;
}


/**
 * Free all resources allocated in getting information about columns
 * 
 * @return 
 *   - 0 : Descriptor dealocated
 *   - 1 : Error ocurred.
 */
int
A4GLSQLLIB_A4GLSQL_end_get_columns()
{
    A4GL_clear_sqlca();

    if (cidata.hstmt != NULL)
    {
        sql_free_stmt(&cidata.hstmt);
        sql_clear_column_info(&cidata, 1);
    }
    return 0;
}

/**
 *
 *
 * @param
 */
void
A4GL_ibind_column_arr (int pos, char *s, HSTMT hstmt)
{
    int size;
    /* DATE_STRUCT *tmp; */
    /*review */

    size = strlen (s);

    set_conv_4gl_to_c ();
    A4GL_newSQLSetParam (hstmt, pos, conv_4gl_to_c[0], conv_4gl_to_c[0], size,
                         0, s, NULL);
}

/**
 * Init a new connection to the database and associate with an explicit
 * session name.
 *
 * If the user identification was not set gets the values fromthe environment.
 *
 * @param sessname The name to be tied to the session.
 * @param dsn The data source name.
 * @param usr The user name to establish the connection.
 * @param pwd The password of the user to set the connection.
 */
int
A4GLSQLLIB_A4GLSQL_init_session_internal (char *sessname, char *dsn,
                                              char *usr, char *pwd)
{
    char empty[10] = "None";
    char *u, *p = 0;
    char uname_acl[256];
    char passwd_acl[256];
    HDBC *hh;

    A4GL_clear_sqlca();

    if (sessname == 0 || strlen (sessname) == 0)
    {
        return 0;
    }

    hh = A4GL_find_pointer_val (sessname, SESSCODE);

    if (hh)
    {
        exitwith_sql_odbc_errm ("Session (%s) already opened", sessname);
        return 0;
    }

    if (strcmp (sessname, sess_name) == 0)
        return 0;

    if (A4GL_sqlid_from_aclfile (dsn, uname_acl, passwd_acl))
    {
        // If we've got a match - it must be explicitly overridden by the environment
        // so we'll use getenv rather than acl_getenv....
        u = acl_getenv_only ("SQLUID");
        p = acl_getenv_only ("SQLPWD");
        if (u && strlen (u) == 0)
            u = 0;
        if (p && strlen (p) == 0)
            p = 0;
        if (!u || !p)
        {
            u = uname_acl;
            p = passwd_acl;
        }
    }
    else
    {
        if (usr == 0)
            u = acl_getenv ("SQLUID");
        else
            u = usr;

        if (pwd == 0)
            p = acl_getenv ("SQLPWD");
        else
            p = pwd;
    }

    A4GL_trc ("Got environment variables");

    if (u == 0)
        u = empty;
    if (p == 0)
        p = empty;

    A4GL_dbg ("Try to make connection: dsn='%s' u=/%s' p='%s'", dsn, u, p);

    if (A4GLSQL_make_connection (dsn, u, p))
    {
        /* do we have an existing pointer to default */
        hh = acl_malloc2 (sizeof (HDBC));
        A4GL_add_pointer (sessname, SESSCODE, hh);
        *hh = hdbc;
        A4GL_dbg ("Made connection executing SQL");
    }
    else
    {
        A4GL_wrn ("Could not connect to database dsn=\"%s\", user=\"%s\"", dsn, usr);
        exitwith_sql_odbc_errm ("Could not connect to database (%s)", dsn);
    }
    strcpy (sess_name, sessname);
    return 0;
}

/**
 * Get the current session name.
 *
 * @return The current connection name.
 */
char *
A4GLSQLLIB_A4GLSQL_get_curr_conn (void)
{
    return sess_name;
}

/**
 * Sets the connection to use in the execution of the next SQL statement.
 *
 * ODBC dynamic library.
 *
 * @param sessname The session name.
 */
int
A4GLSQLLIB_A4GLSQL_set_conn_internal (char *sessname)
{
    HDBC *hdbc_new;

    A4GL_clear_sqlca();

    if (A4GL_find_pointer_val (sessname, SESSCODE))
    {
        strcpy (sess_name, sessname);
        hdbc_new = (HDBC *) A4GL_find_pointer_val (sessname, SESSCODE);
        hdbc = *hdbc_new;
    }
    else
    {
        if (strcmp (sessname, "default") != 0)
        {
            A4GL_wrn ("Could not make session \"%s\" current as it does not exist", sessname);
            exitwith_sql_odbc_errm ("Could not make session (%s) current as it does not exist", sessname);
            return 0;
        }
        else
        {
            strcpy (sess_name, "default");
        }
    }

    ODBC_set_dbms_info ();
    return 1;
}

/**
 * Find the session and if exist close it.
 *
 * @param sessname The session name.
 * @return 
 *  - 0 : The session does not exist or could not disconnect from DB.
 *  - 1 : Session closed.
 */
int
A4GLSQLLIB_A4GLSQL_close_session_internal (char *sessname)
{
    HDBC *ptr;
    SQLRETURN rc;

    A4GL_clear_sqlca();

    ptr = (HDBC *) A4GL_find_pointer_val (sessname, SESSCODE);

    A4GL_dbg ("Trying to close session %s, pr=%p", sessname, ptr);

#if ( defined (SQLITEODBC) || defined (SQLITE_DIRECT) )
    //SQLite needs all transactions closed before connection can be ended
    //FIXME: is there a bettr way? SQL_AUTOCOMMIT ? What should we really
    //do if program wants to exit after an error or by reaching EXIT PROGARAM?
    A4GL_dbg ("commiting all transactions on SQLite...");
    A4GLSQLLIB_A4GLSQL_commit_rollback (1);
#endif

    if (A4GL_isyes (acl_getenv ("FORCE_ROLLBACK_AT_EXIT")))
    {
        A4GLSQLLIB_A4GLSQL_commit_rollback (1);
    }



    if (ptr == 0)
    {
	strcpy (OldDBname, "");
        exitwith_sql_odbc_errm ("Session Id (%s) does not exist", sessname);
        return 0;
    }

    rc = SQLDisconnect (*ptr);

    if (rc == 0)
    {
	strcpy (OldDBname, "");
        A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode(0);
        acl_free (ptr);
        if (strcmp (sessname, "default") != 0)
            A4GLSQL_set_conn ("default");
    }
    else
    {
        exitwith_sql_odbc ("Could not disconnect from the database");
        return 0;
    }
    return 1;
}


/**
 *
 *
 * @param
 */
void *
A4GL_bind_date (long *ptr_to_date_var)
{
    ACLDATE *ptr;

    A4GL_trc ("Binding date for %p", ptr_to_date_var);
    ptr = acl_malloc2 (sizeof (ACLDATE));
    ptr->ptr = ptr_to_date_var;
    ensure_as_char ();
    if (date_as_char)
    {
        strcpy (ptr->uDate.date_c, "0000-00-00");
    }
    else
    {
        ptr->uDate.date_ds.year = -1;
        ptr->uDate.date_ds.month = -1;
        ptr->uDate.date_ds.day = -1;
    }

    return (void *) ptr;
}


void *
A4GL_bind_datetime (void *ptr_to_dtime_var)
{
    ACLDTIME *ptr;

    A4GL_trc ("Binding datetime for %p", ptr_to_dtime_var);
    ptr = acl_malloc2 (sizeof (ACLDTIME));

    ensure_as_char ();
    if (dtime_as_char)
    {
        strcpy (ptr->dtime_u.dtime_c, "");
    }
    else
    {
        ptr->dtime_u.dtime_t.year = -1;
        ptr->dtime_u.dtime_t.month = -1;
        ptr->dtime_u.dtime_t.day = -1;
        ptr->dtime_u.dtime_t.hour = -1;
        ptr->dtime_u.dtime_t.minute = -1;
        ptr->dtime_u.dtime_t.second = -1;
    }


    ptr->ptr = ptr_to_dtime_var;
    return (void *) ptr;
}


void *
A4GL_bind_interval (void *ptr_to_ival)
{
    ACLIVAL *ptr;

    A4GL_trc ("Binding interval for %p", ptr_to_ival);
    ptr = acl_malloc2 (sizeof (ACLIVAL));
    strcpy (ptr->ival_u.ival_c, "");
    ptr->ptr = ptr_to_ival;
    return (void *) ptr;
}


void *
A4GL_bind_decimal (void *ptr_to_decimal)
{
    double *ptr;
    A4GL_trc ("Binding interval for %p", ptr_to_decimal);
    ptr = acl_malloc2 (sizeof (double));
    return (void *) ptr;
}


/**
 * Binding processing after fetch.
 *
 * @param use_binding A pointer to the binding structure.
 * @param use_nbind A counter of the number of elements in the binding array.
 * @param hstmt The statement handle.
 */
void
A4GL_post_fetch_proc_bind (struct BINDING *use_binding, int use_nbind,
                                HSTMT hstmt)
{
    int bind_counter;
    int zz;
    // int ncols;
    ACLDATE *date1;
    ACLDTIME *dt1;
    ACLIVAL *iv1;
    A4GL_trc ("In post_fetch_proc_bind...");

    for (bind_counter = 0; bind_counter < use_nbind; bind_counter++)
    {

        A4GL_trc ("a=%d Binding type %d ptr=%p %d", bind_counter,
                use_binding[bind_counter].dtype,
                use_binding[bind_counter].ptr, outlen[bind_counter + 1]);


        if (use_binding[bind_counter].dtype == DTYPE_CHAR)
        {
            A4GL_dbg ("Found string @ %d = '%s'",
                        bind_counter, use_binding[bind_counter].ptr);
            if (strlen (use_binding[bind_counter].ptr))
            {			// Its not null 
                A4GL_pad_string (use_binding[bind_counter].ptr,
                                 use_binding[bind_counter].size);
            }
        }



        if (outlen[bind_counter + 1] == -1)
        {
            if (use_binding[bind_counter].dtype == DTYPE_DATE)
            {
                date1 = use_binding[bind_counter].ptr;
                A4GL_setnull (DTYPE_DATE,
                              (char *) use_binding[bind_counter].ptr, 0);
                continue;
            }
            A4GL_setnull (use_binding[bind_counter].dtype,
                          (char *) use_binding[bind_counter].ptr,
                          use_binding[bind_counter].size);
            continue;
        }

        if (use_binding[bind_counter].dtype == DTYPE_BYTE
                || use_binding[bind_counter].dtype == DTYPE_BYTE)
        {
            A4GL_get_blob_data (use_binding[bind_counter].ptr, hstmt,
                                bind_counter);
            continue;
        }

        if (use_binding[bind_counter].dtype == DTYPE_DATE)
        {
            A4GL_trc ("Got a date datatype - better copy the date in properly");

            date1 = use_binding[bind_counter].libptr;

            ensure_as_char ();
            if (date_as_char)
            {
                int y, d, m;
                int nscanned;
                y = -1;
                d = -1;
                m = -1;
                A4GL_dbg ("Date as char: DATE=(%s,%d)\n",
                            date1->uDate.date_c, strlen (date1->uDate.date_c));

                if (strlen (date1->uDate.date_c))
                {
                    nscanned = sscanf (date1->uDate.date_c, "%d-%d-%d",
                                       &y, &m, &d);
                    if (nscanned == 3)
                    {
                        A4GL_dbg ("Calling gen_dateno");
                        zz = A4GL_gen_dateno (d, m, y);
                        *(long *) date1->ptr = zz;
                        continue;
                    }
                    else
                    {
                        A4GL_push_char (date1->uDate.date_c);
                        zz = A4GL_pop_date ();
                        *(long *) date1->ptr = zz;
                        continue;
                    }
                }
                else
                {
                    A4GL_dbg ("Looks null");
                    A4GL_setnull (DTYPE_DATE, date1->ptr, 0);
                    continue;
                }
            }
            else
            {

		if (date1->uDate.date_ds.year==-1)  { // Null/no rows found..
                    A4GL_setnull (DTYPE_DATE, date1->ptr, 0);
		} else {
                A4GL_dbg ("Date not as char");
                A4GL_assertion (date1->uDate.date_ds.month < 1
                                || date1->uDate.date_ds.month > 12,
                                "Invalid month retrieved from db");
                A4GL_assertion (date1->uDate.date_ds.day < 1
                                || date1->uDate.date_ds.day > 31,
                                "Invalid day retrieved from db");
                A4GL_trc ("Year=%d Month=%d Day=%d",
                            date1->uDate.date_ds.year,
                            date1->uDate.date_ds.month,
                            date1->uDate.date_ds.day);

                A4GL_dbg ("Calling gen_dateno");
                zz = A4GL_gen_dateno (date1->uDate.date_ds.day,
                                      date1->uDate.date_ds.month,
                                      date1->uDate.date_ds.year);
                *(long *) date1->ptr = zz;
		}
            }

            //*(long *) use_binding[bind_counter].ptr = zz;
            continue;
        }


        if (use_binding[bind_counter].dtype == DTYPE_INTERVAL)
        {
            char buff[256];
            iv1 = use_binding[bind_counter].libptr;
            strcpy (buff, iv1->ival_u.ival_c);
            A4GL_push_char (buff);
            A4GL_setnull (DTYPE_INTERVAL, iv1->ptr,
                          use_binding[bind_counter].size);
            A4GL_pop_param (iv1->ptr, DTYPE_INTERVAL,
                            use_binding[bind_counter].size);
            continue;
        }


        if (use_binding[bind_counter].dtype == DTYPE_DTIME)
        {
            char buff[256];
            dt1 = use_binding[bind_counter].libptr;
            ensure_as_char ();
            if (dtime_as_char)
            {
                strcpy (buff, dt1->dtime_u.dtime_c);
            }
            else
            {
                char buff2[256];
                int s;
                int e;
                strcpy (buff, "");
                s = use_binding[bind_counter].size >> 4;
                e = use_binding[bind_counter].size & 0xf;

                if (s > 1)
                    dt1->dtime_u.dtime_t.year = 0;
                if (s > 2)
                    dt1->dtime_u.dtime_t.month = 0;
                if (s > 3)
                    dt1->dtime_u.dtime_t.day = 0;
                if (s > 4)
                    dt1->dtime_u.dtime_t.hour = 0;
                if (s > 5)
                    dt1->dtime_u.dtime_t.minute = 0;
                if (s > 6)
                    dt1->dtime_u.dtime_t.second = 0;

                if (strlen (buff) || dt1->dtime_u.dtime_t.year)
                {
                    SPRINTF1 (buff2, "%04d", dt1->dtime_u.dtime_t.year);
                    strcat (buff, buff2);
                }

                if (strlen (buff) || dt1->dtime_u.dtime_t.month)
                {
                    if (e >= 2)
                    {
                        SPRINTF1 (buff2, "%02d", dt1->dtime_u.dtime_t.month);
                        if (strlen (buff))
                            strcat (buff, "-");
                        strcat (buff, buff2);
                    }
                }
                if (strlen (buff) || dt1->dtime_u.dtime_t.day)
                {
                    if (e >= 3)
                    {
                        SPRINTF1 (buff2, "%02d", dt1->dtime_u.dtime_t.day);
                        if (strlen (buff))
                            strcat (buff, "-");
                        strcat (buff, buff2);
                    }
                }
                if (strlen (buff) || dt1->dtime_u.dtime_t.hour)
                {
                    if (e >= 4)
                    {
                        SPRINTF1 (buff2, "%02d", dt1->dtime_u.dtime_t.hour);
                        if (strlen (buff))
                            strcat (buff, " ");
                        strcat (buff, buff2);
                    }
                }


                if (strlen (buff) || dt1->dtime_u.dtime_t.minute)
                {
                    if (e >= 5)
                    {
                        SPRINTF1 (buff2, "%02d", dt1->dtime_u.dtime_t.minute);
                        if (strlen (buff))
                            strcat (buff, ":");
                        strcat (buff, buff2);
                    }
                }
                if (strlen (buff) || dt1->dtime_u.dtime_t.second)
                {
                    if (e >= 6)
                    {
                        SPRINTF1 (buff2, "%02d", dt1->dtime_u.dtime_t.second);
                        if (strlen (buff))
                            strcat (buff, ":");
                        strcat (buff, buff2);
                    }
                }

            }
            A4GL_push_char (buff);
            A4GL_setnull (DTYPE_DTIME, dt1->ptr,
                          use_binding[bind_counter].size);
            A4GL_pop_param (dt1->ptr, DTYPE_DTIME,
                            use_binding[bind_counter].size);
            continue;
        }


        if (use_binding[bind_counter].dtype == DTYPE_DECIMAL
                || use_binding[bind_counter].dtype == DTYPE_MONEY)
        {
            // We've actually selected into a double...
            double d;
            A4GL_dbg ("using decimal");
            A4GL_assertion (use_binding[bind_counter].libptr == 0,
                            "No pointer to use for decimal/money");
            d = *((double *) use_binding[bind_counter].libptr);
            A4GL_dbg ("DECIMAL from double on db d=%lf", d);
            A4GL_push_double (d);
            A4GL_pop_var2 (use_binding[bind_counter].ptr,
                           use_binding[bind_counter].dtype,
                           use_binding[bind_counter].size);
            continue;
        }
        A4GL_dbg ("Bound %d\n", bind_counter);
    }


#ifdef DEBUG
    if (0)
    {
        char buffstr[30000] = "Fetch returns :\n";
        char bf[2048];
        int a;
        for (a = 0; a < use_nbind; a++)
        {
            char *cptr;
            int dtype;


            if (use_binding[a].dtype == DTYPE_CHAR
                    || use_binding[a].dtype == DTYPE_VCHAR
                    || use_binding[a].dtype == DTYPE_DECIMAL
                    || use_binding[a].dtype == DTYPE_MONEY
                    || use_binding[a].dtype == DTYPE_DTIME)
            {
                A4GL_dbg ("Need to add size to dtype");
                dtype=use_binding[a].dtype + ENCODE_SIZE (use_binding[a].size);
            }
            else
            {
                dtype = use_binding[a].dtype;
            }

            if (dtype == DTYPE_BYTE || dtype == DTYPE_TEXT)
            {
                A4GL_push_char ("<byte>");
            }
            else
            {
                if ((dtype & 15) == DTYPE_DTIME || (dtype & 15) == DTYPE_DATE)
                {
                    if ((dtype & 15) == DTYPE_DATE)
                    {
                        ACLDATE *date1;
                        ensure_as_char ();
                        date1 = use_binding[a].libptr;
                        if (date_as_char)
                        {
                            A4GL_push_char (date1->uDate.date_c);
                        }
                        else
                        {
                            int xd;
                            int xm;
                            int xy;
                            char buff[40];
                            xy = date1->uDate.date_ds.year;
                            xm = date1->uDate.date_ds.month;
                            xd = date1->uDate.date_ds.day;
                            SPRINTF3 (buff, "%d-%d-%d", xy, xm, xd);
                            A4GL_push_char (buff);
                        }
                    }
                    else
                    {
                        A4GL_push_char ("<datetime>");
                    }
                }
                else
                {
                    A4GL_push_variable (use_binding[a].ptr, dtype);
                }
            }
            cptr = A4GL_char_pop ();
            SPRINTF4 (bf, "%d) %d %d : %s", a, use_binding[a].dtype,
                      (int) use_binding[a].size, cptr);
            if (a > 0)
                strcat (buffstr, ",\n");
            strcat (buffstr, bf);
            acl_free (cptr);
        }
        strcat (buffstr, "\n");
        A4GL_dbg ("use_nbind=%d - %s", use_nbind, buffstr);
    }
#endif
}

/**
 * Implementationin ODBC of the transaction statements (BEGIN WORK,
 * COMMIT WORK, ROLLBACK WORK).
 *
 * @param mode The transaction statement to execute:
 *   - -1 : Begin work
 *   - 0 : Rollback work
 *   - 1 : Commit work
 */
void
A4GLSQLLIB_A4GLSQL_commit_rollback (int mode)
{
    HSTMT hstmt = 0;
    char *ptr;
    int tmode;
    SQLRETURN rc;

    A4GL_clear_sqlca();

    A4GL_trc ("In commit_rollback");
    ptr = acl_getenv ("TRANSMODE");

    if (strlen (ptr))
    {
        tmode = atoi (ptr);
    }
    else
    {
        tmode = 0;
    }


    if (tmode == -1)
        return;


    if (tmode == 0)
    {
        A4GL_trc ("ODBC Transaction Mode:%d ", mode);
        if (mode == 1)
        {
            if (in_transaction)
                rc = SQLSetConnectOption (hdbc,SQL_AUTOCOMMIT,odbc_autocommit);
            in_transaction = 0;
            SQLTransact (henv, hdbc, SQL_COMMIT);
        }

        if (mode == 0)
        {
            if (in_transaction)
                rc = SQLSetConnectOption (hdbc,SQL_AUTOCOMMIT,odbc_autocommit);
            in_transaction = 0;
            SQLTransact (henv, hdbc, SQL_ROLLBACK);
        }

        if (mode == -1)
        {
            rc = SQLSetConnectOption (hdbc, SQL_AUTOCOMMIT, 0);
            in_transaction = 1;
        }

        chk_rc (rc, hstmt, "Commit/Rollback1");
        //      A4GL_set_sqlca (SQL_NULL_HSTMT, "Commit/Rollback", 0);
    }
    else
    {
        A4GL_trc ("Native Transaction Mode:%d", mode);
        if (!A4GL_new_hstmt ((SQLHSTMT *) & hstmt))
	    return;
        if (mode == -1)
        {
            in_transaction = 1;
            SQLExecDirect (hstmt, (SQLCHAR*)"BEGIN WORK", SQL_NTS);
        }

        if (mode == 0)
        {
            in_transaction = 0;
            SQLExecDirect (hstmt, (SQLCHAR*)"ROLLBACK WORK", SQL_NTS);
        }

        if (mode == 1)
        {
            in_transaction = 0;
            SQLExecDirect (hstmt, (SQLCHAR*)"COMMIT WORK", SQL_NTS);
        }

        chk_rc (rc, hstmt, "Commit/Rollback2");
        //      A4GL_set_sqlca (hstmt, "Commit/Rollback", 0);

	sql_free_stmt(&hstmt);
    }
}

/**
 * ODBC implementation of the UNLOAD 4gl statement.
 *
 * @param fname File name where to unload the data.
 * @param delims column separator to use.
 * @param sql1 Sql select text to generate the unload data.
 */
void
A4GLSQLLIB_A4GLSQL_unload_data_internal (char *fname, char *delims,
                                           char *sql1, int nbind, void *vibind)
{
    HSTMT hstmt;
    char *sql2;
    struct BINDING *ibind;
    int cnt = 0;
    static char databuf[64000];
    short ncols;
    char colname[64];
    SQLSMALLINT colnamelen;
    SQLSMALLINT coltype[5000];
    SQLUSMALLINT colcnt;
    SQLINTEGER ind;
    SQLUINTEGER collen;
    SQLSMALLINT scale;
    SQLSMALLINT nullable;
    FILE *fout;
    ibind = vibind;
    fout = A4GL_mja_fopen (fname, "wt");
    SQLRETURN rc;

    A4GL_clear_sqlca();

    if (fout == 0)
    {
        A4GL_wrn ("Error opening file \"%s\" for unload", fname);
        exitwith_sql_odbc_errm ("Error opening file (%s) for unload", fname);
        return;
    }

    if (hdbc == 0)
    {
        exitwith_sql_odbc ("Not connected to database");
	fclose(fout);
        return;
    }
    if (!A4GL_new_hstmt ((SQLHSTMT *) & hstmt))
    {
	fclose(fout);
	return;
    }

    sql2 = acl_strdup (sql1);

    A4GL_assertion (hstmt == 0, "No statement");
    SQLPrepare ((SQLHSTMT) hstmt, (SQLCHAR*)sql2, SQL_NTS);
    A4GL_proc_bind (ibind, nbind, 'i', (SQLHSTMT) hstmt);

    prettyprint_sql (sql2, ibind, nbind, "7");

    rc = SQLExecute (hstmt);	// Reformatted
    chk_rc (rc, hstmt, "unload_data");
    if (a4gl_sqlca.sqlcode < 0)
        return;

    A4GL_trc ("Executed %s %d", sql2, rc);

    rc = SQLNumResultCols (hstmt, &ncols);
    A4GL_dbg ("Calling chk_Rc %d\n", rc);
    chk_rc (rc, hstmt, "unload_data");
    if (a4gl_sqlca.sqlcode < 0)
        return;
    A4GL_dbg ("Done Calling chk_Rc %d status=%d \n", rc, a4gl_sqlca.sqlcode);


    for (colcnt = 1; colcnt <= ncols; colcnt++)
    {

        rc = SQLDescribeCol (hstmt, colcnt, (SQLCHAR*)colname,
                (SQLSMALLINT) sizeof (colname),
                &colnamelen, &coltype[colcnt],
                &collen, &scale, &nullable);
        chk_rc (rc, hstmt, "SQLDescribeCol");
    }
    while (1)
    {
        rc = SQLFetch (hstmt);
        chk_rc (rc, hstmt, "SQLFetch");
        if (rc == SQL_NO_DATA_FOUND)
            break;
        cnt++;
        A4GL_trc ("Fetched row");
        for (colcnt = 1; colcnt <= ncols; colcnt++)
        {

            rc =
                    SQLGetData (hstmt, colcnt, SQL_CHAR, databuf,
                            sizeof (databuf), &ind);
            /*
warning: passing arg 6 of `SQLGetData' from incompatible pointer type
unsigned long ind;

SQLRETURN   SQLGetData(SQLHSTMT StatementHandle,
SQLUSMALLINT ColumnNumber, SQLSMALLINT TargetType,
SQLPOINTER TargetValue, SQLINTEGER BufferLength,
SQLINTEGER *StrLen_or_Ind);
             */

            chk_rc (rc, hstmt, "SQLGetData");

            A4GL_trc ("Cycling through data %d (%d) ind=%d", colcnt, rc, ind);
            if (ind == -1)
            {
                A4GL_trc ("Null...");
                FPRINTF (fout, "%c", delims[0]);
            }
            else
            {
                A4GL_trim (databuf);
                A4GL_trc ("Not null %s    datatype : %d", databuf,
                        coltype[colcnt]);

                if (strlen (databuf) == 0)
                    strcpy (databuf, " ");

                if (coltype[colcnt] == SQL_DATE)
                {
                    FPRINTF (fout, "%s%c", A4GL_conv_date (databuf), delims[0]);
                }
                else
                {
                    if (coltype[colcnt] == SQL_DOUBLE)
                    {
                        if (strchr (databuf, '.') || strchr (databuf, ',')
                                || strchr (databuf, 'e'))
                        {
                            FPRINTF (fout, "%s%c", databuf, delims[0]);
                        }
                        else
                        {
                            FPRINTF (fout, "%s.0%c", databuf, delims[0]);
                        }
                    }
                    else
                    {
                        FPRINTF (fout, "%s%c", databuf, delims[0]);
                    }
                }
            }
        }
        FPRINTF (fout, "\n");
    }

    A4GL_trc ("All done...");
    acl_free (sql2);
    rc = SQLFreeStmt (hstmt, SQL_DROP);
    fclose (fout);
    chk_rc (rc, hstmt, "SQLFreeStmt");
    a4gl_sqlca.sqlerrd[1] = cnt;
}

/**
 * Convert a date to the format setted in DBDATE.
 *
 * @param s The string with the date coming from the database.
 */
char *
A4GL_conv_date (char *s)
{
    static char buff[20];
    static char sbuff[20];
    static char dbdate[20];
    int y, m, d;
    int cnt;
    buff[0] = 0;

    sscanf (s, "%d-%d-%d", &y, &m, &d);
    strcpy (dbdate, A4GL_get_dbdate ());

    A4GL_trc ("Scanning... dbdate=%s", dbdate);

    for (cnt = 0; cnt <= 2; cnt++)
    {

        if (dbdate[cnt] == 'y' || dbdate[cnt] == 'Y')
        {
            SPRINTF1 (sbuff, "%04d", y);
            strcat (buff, sbuff);
        }

        if (dbdate[cnt] == 'm' || dbdate[cnt] == 'M')
        {
            SPRINTF1 (sbuff, "%02d", m);
            strcat (buff, sbuff);
        }

        if (dbdate[cnt] == 'd' || dbdate[cnt] == 'D')
        {
            SPRINTF1 (sbuff, "%02d", d);
            strcat (buff, sbuff);
        }

        if (cnt != 2)
        {

            if (dbdate[4] != 0)
                SPRINTF1 (sbuff, "%c", dbdate[4]);
            else
                SPRINTF0 (sbuff, "/");

            strcat (buff, sbuff);
        }

    }
    return buff;
}



#ifdef INCLUDEDATASOURCES
RETCODE SQL_API
SQLDataSources (HENV henv, SQLUSMALLINT fDirection,
		SQLCHAR FAR * szDSN, SQLSMALLINT cbDSNMax, SQLSMALLINT FAR * pcbDSN,
		SQLCHAR FAR * szDescription, SQLSMALLINT cbDescriptionMax,
		SQLSMALLINT FAR * pcbDescription)
{
  return -1;
}
#endif

/**
 *
 * @param rc 
 * @param hstmt The statement handle.
 * @return
 */
int
A4GL_chk_need_blob (SQLRETURN rc, HSTMT hstmt)
{
    A4GL_trc ("In A4GL_chk_need_blob rc=%d", rc);
    if (rc != SQL_NEED_DATA)
        return rc;
    A4GL_trc ("Need data for %p", hstmt);
    return A4GL_set_blob_data (hstmt);
}

static int do_fake_transactions (void)
{
    static int d = -1;
    if (d == -1)
    {
        d = A4GL_isyes (acl_getenv ("FAKE_TRANSACTIONS"));
    }
    return d;
}



/**
 * Check if a environment variable is set (true/false).
 *
 * @param A string containing the environment variable.
 * @param a
 * @return
 *   - TRUE : The variable is set and have YyTt
 *   - FALSE  Otherwise.
 */
int
A4GL_chk_getenv (char *s, int a)
{
    char *p;
    p = acl_getenv (s);
    if (p == 0 && a == 0)
        return TRUE;
    if (p == 0 && a != 0)
        return FALSE;

    A4GL_trc ("Checking %s (%s) for %d", s, p, a);

    if (p[0] == 'Y' || p[0] == 'y' || p[0] == 'T' || p[0] == 't')
    {
        if (a == TRUE)
            return TRUE;
    }
    if (p[0] == 'N' || p[0] == 'n' || p[0] == 'F' || p[0] == 'f')
    {
        if (a == TRUE)
            return FALSE;
        else
            return TRUE;
    }
    return FALSE;
}

/**
 * PUT statement for cursors for insert.
 * Not implemented.
 *
 * @param ibind The input bin array.
 * @param n 
 */
void
A4GLSQLLIB_A4GLSQL_put_insert (void *vibind, int n)
{
    struct BINDING *ibind;
    char *cursorName;
    struct s_cid *cid;
    struct s_sid *sid;
    int ni;

    A4GL_clear_sqlca();

    ibind = vibind;


    cursorName = A4GL_char_pop ();
    cid = A4GLSQL_find_cursor (cursorName);
    acl_free (cursorName);
    if (cid == 0)
        return;
    A4GL_dbg ("Which Bind ? %p %d, %p %d", vibind, n, cid->statement->ibind,
            cid->statement->ni);
    if (n)
    {
        ibind = vibind;
        ni = n;
    }
    else
    {
        ni = cid->statement->ni;
        ibind = cid->statement->ibind;
    }
    sid = cid->statement;
    A4GL_proc_bind (ibind, ni, 'i', (SQLHSTMT) sid->hstmt);
    prettyprint_sql (sid->select, ibind, ni, "8");
    ODBC_exec_stmt ((SQLHSTMT*)&(sid->hstmt));

}

/**
 * FLUSH CURSOR 4gl statement implementation.
 * Not implemented in ODBC.
 *
 * @param The cursor name.
 */
void
A4GLSQLLIB_A4GLSQL_flush_cursor (char *cursor)
{
    A4GL_clear_sqlca();

    A4GL_err ("Not implemented A4GLSQL_flush_cursor");
    exitwith_sql_odbc ("Not implemented A4GLSQL_flush_cursor");
}

/**
 * Initialization of the sql dynamic library.
 *
 * Used to initialise SQL library, ater loading it with dlopen,
 * called from fglwrap.c
 */
int
A4GLSQLLIB_SQL_initlib (void)
{
    A4GL_clear_sqlca();

    initenv ();
    A4GLSQL_make_connection (0, 0, 0);
    return 1;
}

char *
A4GLSQLLIB_A4GLSQL_syscolval_expr (char *tabname, char *colname, char *typ)
{
    return 0;
}

struct expr_str_list *
A4GL_add_validation_elements_to_expr (struct expr_str_list *ptr, char *val)
{
    char *ptr2;
    char *ptrn;
    //char buff[256];
    A4GL_trim (val);
    ptr2 = val;
    while (1)
    {
        ptrn = strtok (ptr2, ",");
        if (ptrn == 0)
            break;
        if (ptr2)
        {
            ptr2 = 0;
        }

        //SPRINTF1 (buff, "A4GL_push_char(\"%s\");", ptrn);

        if (ptr == 0)
        {
            ptr = A4GL_new_ptr_list (A4GL_new_literal_string (ptrn));
            //ptr = A4GL_new_expr (buff);
        }
        else
        {
            ptr=A4GL_new_append_ptr_list (ptr, A4GL_new_literal_string (ptrn));
        }

    }
    return ptr;
}


t_expr_str_list *
A4GLSQLLIB_A4GLSQL_get_validation_expr (char *tabname, char *colname)
{
    char buff[300];
    char val[65];
    struct expr_str_list *ptr = 0;
    char *cptr = 0;
    struct BINDING obind[1] = { {0, 0, 64, 0, 0} };	/* end of binding */

    A4GL_clear_sqlca();

    obind[0].ptr = &val;

    cptr = acl_getenv ("A4GL_SYSCOL_VAL");
    if (cptr == 0)
        return 0;
    if (strlen (cptr) == 0)
        return 0;
    if (strcmp (cptr, "NONE") == 0)
        return 0;
    SPRINTF3 (buff,
            "select attrval from %s where attrname='INCLUDE' and tabname='%s' and colname='%s'",
            cptr, tabname, colname);
    A4GLSQL_add_prepare ("p_get_val", (void *) A4GLSQL_prepare_select_internal(
                                         0, 0, 0, 0, buff,"__internal_sql_1", 0));
    if (a4gl_sqlca.sqlcode != 0)
        return (void *) -1;
    A4GLSQLLIB_A4GLSQL_declare_cursor (0 + 0,
            A4GLSQL_find_prepare ("p_get_val"), 0, "c_get_val");
    if (a4gl_sqlca.sqlcode != 0)
        return (void *) -1;
    A4GLSQLLIB_A4GLSQL_open_cursor ("c_get_val", 0, 0);
    if (a4gl_sqlca.sqlcode != 0)
        return (void *) -1;

    while (1)
    {
        A4GLSQL_fetch_cursor ("c_get_val", 2, 1, 1, obind);
        if (a4gl_sqlca.sqlcode != 0)
            break;
        ptr = A4GL_add_validation_elements_to_expr (ptr, val);
        /* Process it... */
    }
    return ptr;
}


void static initenv (void)
{
    if (henv == 0)
    {
        SQLRETURN rc;
        A4GL_dbg ("Calling SQLAllocEnv()");
        //This call core dumps on SQLite/MinGW:
        rc = SQLAllocEnv (&henv);
        //rc = SQLAllocEnv (henv);
        chk_rc (rc, 0, "SQLAllocEnv");
        A4GL_trc ("SQLAllocEnv returned %d %p", rc, henv);
        if (rc == SQL_SUCCESS)
        {
            ListDSN ();
        }
    }
}

static void ListDSN (void)
{
    char l_dsn[100], l_desc[100];
    short int l_len1, l_len2, l_next;
    SQLRETURN rc;

    l_next = SQL_FETCH_FIRST;
    rc = SQL_SUCCESS;

    A4GL_dbg ("Listing DSNs");

    while (rc == SQL_SUCCESS)
    {
        rc = SQLDataSources (henv, l_next, (SQLCHAR*)l_dsn, sizeof (l_dsn), &l_len1,
                             (SQLCHAR*)l_desc, sizeof (l_desc), &l_len2);
        if (rc != SQL_SUCCESS)
            break;

        A4GL_dbg ("Server=(%s) Description=(%s)\n", l_dsn, l_desc);
        l_next = SQL_FETCH_NEXT;
    }
}

/* =================================================== */
/* Folowing code examples taken from sqliteodbc.c file */
/* =================================================== */

#ifdef EXAMPLE

//FIXME: we need to be able to read odbc.ini directly to get at least
// username and password

#if defined(WITHOUT_DRIVERMGR) || !defined(_WIN32)

/**
 * Handling of SQLConnect() connection attributes
 * for standalone operation without driver manager.
 * Extracts requested parameter value from connect string.
 * @param dsn DSN/driver connection string
 * @param attr attribute string to be retrieved
 * @param out output buffer
 * @param outLen length of output buffer
 * @result true or false
 */

static int
A4GL_getdsnattr (char *dsn, char *attr, char *out, int outLen)
{
    char *str = dsn, *start;
    int len = strlen (attr);

    while (*str)
    {
        while (*str && *str == ';')
        {
            ++str;
        }
        start = str;
        if ((str = strchr (str, '=')) == NULL)
        {
            return 0;
        }
        if (str - start == len && strncasecmp (start, attr, len) == 0)
        {
            start = ++str;
            while (*str && *str != ';')
            {
                ++str;
            }
            len = min (outLen - 1, str - start);
            strncpy (out, start, len);
            out[len] = '\0';
            return 1;
        }
        while (*str && *str != ';')
        {
            ++str;
        }
    }
    return 0;
}
#endif

#if defined(WITHOUT_DRIVERMGR) || defined(_WIN32)

/**
 * Get datasource attributes from registry.
 * @param setupdlg pointer to dialog data
 */

static void GetAttributes (SETUPDLG * setupdlg)
{
    char *dsn = setupdlg->attr[KEY_DSN].attr;

    if (!setupdlg->attr[KEY_DESC].supplied)
    {
        SQLGetPrivateProfileString (dsn, "Description", "",
                                    setupdlg->attr[KEY_DESC].attr,
                                    sizeof (setupdlg->attr[KEY_DESC].attr),
                                    ODBC_INI);
    }
    if (!setupdlg->attr[KEY_DBNAME].supplied)
    {
        SQLGetPrivateProfileString (dsn, "Database", "",
                                    setupdlg->attr[KEY_DBNAME].attr,
                                    sizeof (setupdlg->attr[KEY_DBNAME].attr),
                                    ODBC_INI);
    }
    if (!setupdlg->attr[KEY_BUSY].supplied)
    {
        SQLGetPrivateProfileString (dsn, "Timeout", "1000",
                                    setupdlg->attr[KEY_BUSY].attr,
                                    sizeof (setupdlg->attr[KEY_BUSY].attr),
                                    ODBC_INI);
    }
    if (!setupdlg->attr[KEY_NOWCHAR].supplied)
    {
        SQLGetPrivateProfileString (dsn, "NoWCHAR", "",
                                    setupdlg->attr[KEY_NOWCHAR].attr,
                                    sizeof (setupdlg->attr[KEY_NOWCHAR].attr),
                                    ODBC_INI);
    }
#ifdef ASYNC
    if (!setupdlg->attr[KEY_THR].supplied)
    {
        SQLGetPrivateProfileString (dsn, "Threaded", "1",
                                    setupdlg->attr[KEY_THR].attr,
                                    sizeof (setupdlg->attr[KEY_THR].attr),
                                    ODBC_INI);
    }
#endif
}

#endif

/**
 * Internal connect to database.
 * @param dbc database connection handle
 * @param dsn DSN string
 * @param dsnLen length of DSN string or SQL_NTS
 * @result ODBC error code
 */

static SQLRETURN
example_drvconnect (SQLHDBC dbc, SQLCHAR * dsn, SQLSMALLINT dsnLen)
{
    DBC *d;
    int len;
    char buf[SQL_MAX_MESSAGE_LENGTH], dbname[SQL_MAX_MESSAGE_LENGTH / 4];
    char busy[SQL_MAX_MESSAGE_LENGTH / 4];
    char tflag[32], nwflag[32];


    //Test parameters we got:
    if (dbc == SQL_NULL_HDBC)
    {
        return SQL_INVALID_HANDLE;
    }
    d = (DBC *) dbc;
    if (d->magic != DBC_MAGIC)
    {
        return SQL_INVALID_HANDLE;
    }
    if (d->sqlite != NULL)
    {
        setstatd (d, "connection already established", "08002");
        return SQL_ERROR;
    }
    buf[0] = '\0';
    if (dsnLen == SQL_NTS)
    {
        len = sizeof (buf) - 1;
    }
    else
    {
        len = min (sizeof (buf) - 1, dsnLen);
    }
    if (dsn != NULL)
    {
        strncpy (buf, dsn, len);
    }
    buf[len] = '\0';
    if (buf[0] == '\0')
    {
        setstatd (d, "invalid DSN", "S1090");
        return SQL_ERROR;
    }
    busy[0] = '\0';
    dbname[0] = '\0';
#ifdef WITHOUT_DRIVERMGR
    //get info from odbc.ini using our own read function
    A4GL_getdsnattr (buf, "database", dbname, sizeof (dbname));
    if (dbname[0] == '\0')
    {
        strncpy (dbname, buf, sizeof (dbname));
        dbname[sizeof (dbname) - 1] = '\0';
    }
    A4GL_getdsnattr (buf, "timeout", busy, sizeof (busy));
    tflag[0] = '\0';
    nwflag[0] = '\0';
#ifdef ASYNC
    A4GL_getdsnattr (buf, "threaded", tflag, sizeof (tflag));
#endif
    A4GL_getdsnattr (buf, "nowchar", nwflag, sizeof (nwflag));
#else
    //get info from odbc.ini using driver manager function calls:
    SQLGetPrivateProfileString (buf, "timeout", "1000",
                                busy, sizeof (busy), ODBC_INI);
    SQLGetPrivateProfileString (buf, "database", "",
                                dbname, sizeof (dbname), ODBC_INI);
#ifdef ASYNC
    SQLGetPrivateProfileString (buf, "threaded", "",
                                tflag, sizeof (tflag), ODBC_INI);
#endif
    SQLGetPrivateProfileString (buf, "nowchar", "",
                                nwflag, sizeof (nwflag), ODBC_INI);
#endif

    //Now we can connect:
    //d->nowchar = getbool(nwflag);
    //return dbopen(d, dbname, dsn, tflag, busy);
}


#endif //ifdef EXAMPLE

/**
 * Decode a return call from the integer defined value to a string.
 *
 * @param a The integer value to be decoded.
 * @return The value converted to string
 */
char *
A4GL_decode_rc (int a)
{
    static char buf[64];
    switch (a)
    {
      case SQL_SUCCESS:
        return "SQL_SUCCESS";
      case SQL_ERROR:
        return "SQL_ERROR";
      case SQL_INVALID_HANDLE:
        return "SQL_INVALID_HANDLE";
      case SQL_SUCCESS_WITH_INFO:
        return "SQL_SUCCESS_WITH_INFO";
      case SQL_STILL_EXECUTING:
        return "SQL_STILL_EXECUTING";
      case SQL_NEED_DATA:
        return "SQL_NEED_DATA";
      case SQL_NO_DATA_FOUND:
        return "SQL_NO_DATA_FOUND";
    }
    sprintf(buf, "Not decoded SQL retval (%i(?))", a);
    return buf;
}

static Bool sql_ok(SQLRETURN rc)
{
    return rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO || rc == SQL_NO_DATA_FOUND;
}

static Bool sql_failed(SQLRETURN rc)
{
    return ! sql_ok(rc);
}

char *
A4GLSQLLIB_A4GLSQL_get_errmsg (int a)
{
    return 0;
}

/**
 * Get the current SQL error message.
 *
 * @return The contents of sqlca.sqlerrm.
 */
char *
A4GLSQLLIB_A4GLSQL_get_sqlerrm (void)
{
    return a4gl_sqlca.sqlerrm;
}

/**
 * Clear sqlca data
 *
 */
void
A4GL_clear_sqlca(void)
{
    A4GL_trc ("In A4GL_clear_sqlca and error status");
    if (!aclfgli_get_err_flg())
    {
	A4GL_dbg ("clearing sqlca");
	memset(&a4gl_sqlca, 0, sizeof(a4gl_sqlca));
	strcpy(a4gl_sqlca.sqlerrm, "?");
	memset(a4gl_sqlca.sqlawarn, ' ', sizeof(a4gl_sqlca.sqlawarn));
	strcpy(a4gl_sqlca.sqlstate, "00000");
	A4GLSQL_set_status (0, 1);
    }
    else
    {
	A4GL_dbg ("err_flg enabled - NOT clearing sqlca");
    }
}

/**
 * Assign the sqlca.sqlcode and a4gl_status with a value
 *
 * @param a The value to be assigned.
 */
void
A4GLSQLLIB_A4GLSQL_set_sqlca_sqlcode (int a)
{
  A4GL_dbg ("In set_sqlca_sqlcode, code=%i", a);
  a4gl_status = a;
  a4gl_sqlca.sqlcode = a;
}


/**
 * Helper function. Used to set some common fields in case of SQL error.
 *
 * @param code Error code (native code or meaningful hardcoded value)
 * @param odbc_sqlstate The 5-character ODBC sqlstate
 * @param msg The error string
 */
static void set_global_status(int code, char *odbc_sqlstate, char *msg)
{
    A4GL_dbg ("In set_global_status: odbc_sqlstate=%s msg=%s code=%d", odbc_sqlstate, msg, code);

    strcpy(a4gl_sqlca.sqlstate, odbc_sqlstate);
    strcpy(a4gl_sqlca.sqlerrm, "?");
    A4GL_set_lasterrorstr(msg);
    a4gl_sqlca.sqlerrd[1] = 0;
    a4gl_sqlca.sqlcode = code;
}

static void exitwith_sql_odbc_errm(char *errmsg, char *arg)
{
    int code = -1;
    A4GL_dbg("Aubit4GL error, key string=\"%s\", arg=\"%s\", looking for matching error code", errmsg, arg);

    code = A4GL_get_errcode_for_errstr(errmsg);

    if (code == -1)
    {
	A4GL_ftl("Internal error: no error code corresponding to message \"%s\", full rebuild needed", errmsg);
	A4GL_assertion(1, "No error code corresponding to the message, full rebuild needed");
    }

    code = code * -1;
    
    if (A4GLSQL_set_status (code, 1))
    {
	set_global_status(code, "00000", errmsg);
	A4GL_set_errm(arg);
    }
    return;
}

static void exitwith_sql_odbc(char *errmsg)
{
    exitwith_sql_odbc_errm(errmsg, "");
}

/**
 * Assign the values of sqlca acording to the status of the statement.
 *
 * @param hstmt The statement handler.
 * @param s A string to identify who and wy called this.
 * @return
 *   - 0 : Global status variables (sqlca, a4glstatus) have not been altered
 *   - 1 : Global status variables have been altered
 */
int
A4GL_set_sqlca (SQLHSTMT hstmt, char *s)
{
    char odbc_sqlstate[81];
    char errmsg[500];
    SQLINTEGER nativeerr = 0;
    SQLSMALLINT msglen;
    RETCODE rc = 0;
#ifdef USE_DIAG_REC
    int i;
#endif

    A4GL_dbg ("In set_sqlca: hstmt=%p, s=\"%s\"", hstmt, s);
    A4GL_dbg ("henv=%p hdbc=%p", henv, hdbc);

    memset (odbc_sqlstate, 0, sizeof(odbc_sqlstate));
    memset (errmsg, 0, sizeof(errmsg));
    strcpy (odbc_sqlstate, "00000");


#ifdef USE_DIAG_REC
        rc = SQL_SUCCESS;
        i = 0
        do
        {
            ++i;
            rc = SQLGetDiagRec (SQL_HANDLE_STMT, hstmt, i, odbc_sqlstate,
                                 &nativeerr, errmsg, sizeof(msg), &msglen);
            if (rc == SQL_SUCCESS || rc == SQL_SUCCESS_WITH_INFO)
            {
                A4GL_dbg("After SQLGetDiagRec [%d]: rc=%d nativeerr=%d odbc_sqlstate='%s' errmsg=%s",
                    i, rc, nativeerr, odbc_sqlstate, errmsg);
            }
            A4GL_assertion (i > 100000, "Paranoic number of error records (infinite loop?)");
        } while (sql_failed(rc) || rc == SQL_NO_DATA_FOUND)
#else
    rc = SQLError (henv, hdbc, hstmt, (SQLCHAR*)odbc_sqlstate, &nativeerr,
                                (SQLCHAR*)errmsg, sizeof(errmsg), &msglen);
#endif

    // Some checks
    if (sql_failed(rc))
    {
        A4GL_wrn("SQLError failed (SHOULDN'T HAPPEN!), rc=%d\n", rc);
        strcpy (odbc_sqlstate, "HY000");
        SPRINTF1(errmsg,
		 "SQLError failed (SHOULDN'T HAPPEN!), no real error info available, assuming HY000, rc=%s",
                 A4GL_decode_rc(rc));
        nativeerr = -1;
    }
#ifdef USE_DIAG_REC
    else if (i == 1 && rc == SQL_NO_DATA_FOUND) // error occured but driver did not provide an info record
#else
    else if (rc == SQL_NO_DATA_FOUND) // error occured but driver did not provide an info record
#endif
    {                   // (this part of code is needed when using broken ODBC drivers)
        A4GL_wrn("It seems error occured, but SQLError ODBC function returned no error record, assuming HY000");
        strcpy (odbc_sqlstate, "HY000");
        strcpy (errmsg,
		"It seems error occured, but SQLError ODBC function returned no error record, assuming HY000");
        nativeerr = -1;
    }
    A4GL_dbg("after SQLError/SQLGetDiagRec: rc=%d nativeerr=%d odbc_sqlstate='%s' errmsg=%s",
               rc, nativeerr, odbc_sqlstate, errmsg);

    // Some conversions
    if (nativeerr > 0 && nativeerr != 100)
        nativeerr = 0 - nativeerr;
#ifdef DEBUG
    if (strcmp (odbc_sqlstate, "S1010") == 0) // Function sequence error
    {
        if (A4GL_isyes(acl_getenv("ASSERTONFUNCSEQERR")))
            A4GL_assertion (1, "Function sequence error ?");
    }

    if (strcmp (odbc_sqlstate, "01S02") == 0)
    {
        A4GL_wrn ("%s: Option value changed", s);
        //        strcpy (odbc_sqlstate, ""); // why to change this one?
    }
#endif
    if (strlen (odbc_sqlstate) == 0)
        strcpy (odbc_sqlstate, "00000");

    if (strcmp (odbc_sqlstate, "00000") == 0)
        nativeerr = 0;
//    else if (nativeerr == 0) // What a weird stuff? Why there is no single
//        nativeerr = -101;    //  word of comment why someone might need this?

    if (odbc_sqlstate[0] == '0' && odbc_sqlstate[1] == '1')
    {
        A4GL_wrn("Got ODBC odbc_sqlstate=%s", odbc_sqlstate);
        strcpy (a4gl_sqlca.sqlawarn, "       ");
        a4gl_sqlca.sqlawarn[0] = 'W';
	if (nativeerr < 0) // ODBC thinks this is a warning, so let's make code positive
            nativeerr = 0 - nativeerr;
    }

    if (ignore_next_sql_error)
    {
        A4GL_dbg("Error ignored (by design)");
        ignore_next_sql_error = 0;
	return False;
    }
    if (A4GLSQL_set_status (nativeerr, 0))
    {
        set_global_status(nativeerr, odbc_sqlstate, errmsg);
	return True;
    }
    else
	return False;
}

/**
 * Check if there was an error and set sqlca.
 *
 * @param rc The return call error.
 * @param hstmt The statement handle.
 * @param c  A string to identify who and wy called this
 * @param line Used just for debug
 * @param file Used just for debug
 * @return
 *   - 0 : An error ocurred.
 *   - 1 : Done.
 */
int
A4GL_chk_rc_full (SQLRETURN rc, void *hstmt, char *c, int line, char *file)
{
    A4GL_dbg ("In chk_rc_full : rc=%d(%s) hstmt=%p c=%s line=%d file=%s",
	    	rc, A4GL_decode_rc(rc), hstmt, c, line, file);

    if (rc == SQL_SUCCESS)
    {
	if (A4GLSQL_set_status (0, 0))
            set_global_status(0, "00000", "Success");
	ignore_next_sql_error = 0;
	return True;
    }
    else if (rc == SQL_NO_DATA_FOUND)
    {
	if (A4GLSQL_set_status (100, 0))
            set_global_status(100, "00000", "Success with NO_DATA");
	ignore_next_sql_error = 0;
	return True;
    }
    else if (rc == SQL_INVALID_HANDLE)
    {
	if (A4GLSQL_set_status (-2, 0))
            set_global_status(-2, "HY000", "Invalid handle - error info unavailable");
	ignore_next_sql_error = 0;
        return False;
    }
    else if (rc == SQL_SUCCESS_WITH_INFO && hstmt == 0)
    {
	if (A4GLSQL_set_status (1, 0))
	{
	    set_global_status(0, "01000", "Success with info, details unavailable because of null handle");
	    strcpy(a4gl_sqlca.sqlawarn, "       ");
	    a4gl_sqlca.sqlawarn[0] = 'W';
	}
	ignore_next_sql_error = 0;
        return True;
    }
    else if (rc == SQL_ERROR && hstmt == 0)
    {
	if (A4GLSQL_set_status (-1, 0))
            set_global_status(0, "HY000", "Error, details unavailable because of null handle");
	ignore_next_sql_error = 0;
        return False;
    }

    A4GL_set_sqlca(hstmt, c);
    ignore_next_sql_error = 0;
    return sql_ok(rc);
//    return False;
}

/* ================================ EOF ================================ */
