/**
 * @file sqlite3odbc.c
 * SQLite3 ODBC Driver main module.
 *
 * $Id: sqlite3odbc.c,v 1.2 2005-03-29 11:24:14 mikeaubury Exp $
 *
 * Copyright (c) 2004 Christian Werner <chw@ch-werner.de>
 *
 * See the file "license.terms" for information on usage
 * and redistribution of this file and for a
 * DISCLAIMER OF ALL WARRANTIES.
 */

/* Added for Aubit */
#undef  HAVE_CONFIG_H

#ifndef NODEBUG
	#define A4GL_debug A4GL_set_line(__FILE__,__LINE__);A4GL_debug_full
#else
	#define A4GL_debug null_func
#endif

  int A4GL_set_line (char *s, long l);
  void A4GL_debug_full (char *fmt, ...);

  #define AUBIT 1
  
/* Added for Aubit - END */

#include "sqlite3odbc.h"

#if ((defined (_WIN32)) && (! defined (AUBIT)))
//this looks like MS VC only stuff
	#include "resource.h"
	#define ODBC_INI "ODBC.INI"
#else
	#define ODBC_INI ".odbc.ini"
#endif

#ifndef DRIVER_VER_INFO
#define DRIVER_VER_INFO "0.0"
#endif

#undef min
#define min(a, b) ((a) < (b) ? (a) : (b))
#undef max
#define max(a, b) ((a) < (b) ? (b) : (a))

#define array_size(x) (sizeof (x) / sizeof (x[0]))

#define stringify1(s) #s
#define stringify(s) stringify1(s)

#define verinfo(maj, min, lev) ((maj) << 16 | (min) << 8 | (lev))

/* Column types for static string column descriptions (SQLTables etc.) */

#define SCOL_VARCHAR SQL_VARCHAR
#define SCOL_CHAR SQL_CHAR

#define ENV_MAGIC  0x53544145
#define DBC_MAGIC  0x53544144
#define DEAD_MAGIC 0xdeadbeef

#ifdef MEMORY_DEBUG

static void *
xmalloc_(int n, char *file, int line)
{
    int nn = n + 4 * sizeof (long);
    long *p;

    p = malloc(nn);
    if (!p) {
#if (MEMORY_DEBUG > 1)
	fprintf(stderr, "malloc\t%d\tNULL\t%s:%d\n", n, file, line);
#endif
	return NULL;
    }
    p[0] = 0xdead1234;
    nn = nn / sizeof (long) - 1;
    p[1] = n;
    p[nn] = 0xdead5678;
#if (MEMORY_DEBUG > 1)
    fprintf(stderr, "malloc\t%d\t%p\t%s:%d\n", n, &p[2], file, line);
#endif
    return (void *) &p[2];
}

static void *
xrealloc_(void *old, int n, char *file, int line)
{
    int nn = n + 4 * sizeof (long), nnn;
    long *p, *pp;

    if (n == 0) {
	return xmalloc_(n, file, line);
    }
    p = &((long *) old)[-2];
    if (p[0] != 0xdead1234) {
	fprintf(stderr, "*** low end corruption @ %p\n", old);
	abort();
    }
    nnn = p[1] + 4 * sizeof (long);
    nnn = nnn / sizeof (long) - 1;
    if (p[nnn] != 0xdead5678) {
	fprintf(stderr, "*** high end corruption @ %p\n", old);
	abort();
    }
    pp = realloc(p, nn);
    if (!pp) {
#if (MEMORY_DEBUG > 1)
	fprintf(stderr, "realloc\t%p,%d\tNULL\t%s:%d\n", old, n, file, line);
#endif
	return NULL;
    }
#if (MEMORY_DEBUG > 1)
    fprintf(stderr, "realloc\t%p,%d\t%p\t%s:%d\n", old, n, &pp[2], file, line);
#endif
    p = pp;
    if (n > p[1]) {
	memset(p + p[1], 0, 3 * sizeof (long));
    }
    p[1] = n;
    nn = nn / sizeof (long) - 1;
    p[nn] = 0xdead5678;
    return (void *) &p[2];
}

static void
xfree_(void *x, char *file, int line)
{
    long *p;
    int n;

    p = &((long *) x)[-2];
    if (p[0] != 0xdead1234) {
	fprintf(stderr, "*** low end corruption @ %p\n", x);
	abort();
    }
    n = p[1] + 4 * sizeof (long);
    n = n / sizeof (long) - 1;
    if (p[n] != 0xdead5678) {
	fprintf(stderr, "*** high end corruption @ %p\n", x);
	abort();
    }
#if (MEMORY_DEBUG > 1)
    fprintf(stderr, "free\t%p\t\t%s:%d\n", x, file, line);
#endif
    free(p);
}

static void
xfree__(void *x)
{
    xfree_(x, "unknown location", 0);
}

static char *
xstrdup_(char *str, char *file, int line)
{
    char *p;

    if (!str) {
#if (MEMORY_DEBUG > 1)
	fprintf(stderr, "strdup\tNULL\tNULL\t%s:%d\n", file, line);
#endif
	return NULL;
    }
    p = xmalloc_(strlen(str) + 1, file, line);
    if (p) {
	strcpy(p, str);
    }
#if (MEMORY_DEBUG > 1)
    fprintf(stderr, "strdup\t%p\t%p\t%s:%d\n", str, p, file, line);
#endif
    return p;
}

#define xmalloc(x)    xmalloc_(x, __FILE__, __LINE__)
#define xrealloc(x,y) xrealloc_(x, y, __FILE__, __LINE__)
#define xfree(x)      xfree_(x, __FILE__, __LINE__)
#define xstrdup(x)    xstrdup_(x, __FILE__, __LINE__)

#else

#define xmalloc(x)    malloc(x)
#define xrealloc(x,y) realloc(x, y)
#define xfree(x)      free(x)
#define xstrdup(x)    strdup_(x)

#endif

#ifdef _WIN32
#define vsnprintf   _vsnprintf
#define snprintf    _snprintf
#define strncasecmp _strnicmp
#endif

/*
 * tolower() replacement w/o locale
 */

static const char upper_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static const char lower_chars[] = "abcdefghijklmnopqrstuvwxyz";

static int
TOLOWER(int c)
{
    if (c) {
	char *p = strchr(upper_chars, c);

	if (p) {
	    c = lower_chars[p - upper_chars];
	}
    }
    return c;
}

/*
 * isdigit() replacement w/o ctype.h
 */

static const char digit_chars[] = "0123456789";

#define ISDIGIT(c) \
    ((c) && strchr(digit_chars, (c)) != NULL)

/*
 * isspace() replacement w/o ctype.h
 */

static const char space_chars[] = " \f\n\r\t\v";

#define ISSPACE(c) \
    ((c) && strchr(space_chars, (c)) != NULL)

/*
 * Characters in named parameters
 */

static const char id_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			       "abcdefghijklmnopqrstuvwxyz"
			       "_0123456789";

#define ISIDCHAR(c) \
    ((c) && strchr(id_chars, (c)) != NULL)

/**
 * Reset bound columns to unbound state.
 * @param s statement pointer
 */

static void unbindcols(STMT *s);

/**
 * Reallocate space for bound columns.
 * @param s statement pointer
 * @param ncols number of columns
 * @result ODBC error code
 */

static SQLRETURN mkbindcols(STMT *s, int ncols);

/**
 * Free statement's result.
 * @param s statement pointer
 * @param clrcols flag to clear column information
 *
 * The result rows are free'd using the rowfree function pointer.
 * If clrcols is greater than zero, then column bindings and dynamic column
 * descriptions are free'd.
 * If clrcols is less than zero, then dynamic column descriptions are free'd.
 */

static void freeresult(STMT *s, int clrcols);

/**
 * Internal free function for HSTMT.
 * @param stmt statement handle
 * @result ODBC error code
 */

static SQLRETURN freestmt(HSTMT stmt);

/**
 * Substitute parameter for statement.
 * @param s statement pointer
 * @param pnum parameter number
 * @param out output buffer or NULL
 * @param size size indicator or NULL
 * @result ODBC error code
 *
 * If no output buffer is given, the function computes and
 * reports the space needed for the parameter. Otherwise
 * the parameter is converted to its string representation
 * in order to be presented to sqlite3_exec_vprintf() et.al.
 */

static SQLRETURN substparam(STMT *s, int pnum, char **out, int *size);

/**
 * Free dynamically allocated column descriptions of STMT.
 * @param s statement pointer
 */

static void freedyncols(STMT *s);

/**
 * Internal query execution used by SQLExecute() and SQLExecDirect().
 * @param stmt statement handle
 * @result ODBC error code
 */

static SQLRETURN drvexecute(SQLHSTMT stmt);

#if (MEMORY_DEBUG < 1)
/**
 * Duplicate string using xmalloc().
 * @param str string to be duplicated
 * @result pointer to new string or NULL
 */

static char *
strdup_(const char *str)
{
    char *p = NULL;

    if (str) {
	p = xmalloc(strlen(str) + 1);
	if (p) {
	    strcpy(p, str);
	}
    }
    return p;
}
#endif

#ifdef USE_DLOPEN_FOR_GPPS

#include <dlfcn.h>

#define SQLGetPrivateProfileString(A,B,C,D,E,F) drvgpps(d,A,B,C,D,E,F)

/*
 * EXPERIMENTAL: SQLGetPrivateProfileString infrastructure using
 * dlopen(), in theory this makes the driver independent from the
 * driver manager, i.e. the same driver binary can run with iODBC
 * and unixODBC.
 */

static void
drvgetgpps(DBC *d)
{
    void *lib;
    int (*gpps)();

    lib = dlopen("libodbcinst.so", RTLD_LAZY);
    if (!lib) {
	lib = dlopen("libiodbcinst.so", RTLD_LAZY);
    }
    if (lib) {
	gpps = (int (*)()) dlsym(lib, "SQLGetPrivateProfileString");
	if (!gpps) {
	    dlclose(lib);
	    return;
	}
	d->instlib = lib;
	d->gpps = gpps;
    }
}

static void
drvrelgpps(DBC *d)
{
    if (d->instlib) {
	dlclose(d->instlib);
	d->instlib = 0;
    }
}

static int
drvgpps(DBC *d, char *sect, char *ent, char *def, char *buf,
	int bufsiz, char *fname)
{
    if (d->gpps) {
	return d->gpps(sect, ent, def, buf, bufsiz, fname);
    }
    strncpy(buf, def, bufsiz);
    buf[bufsiz - 1] = '\0';
    return 1;
}
#else
#define drvgetgpps(d)
#define drvrelgpps(d)
#endif

/**
 * Set error message and SQL state on DBC
 * @param d database connection pointer
 * @param naterr native error code
 * @param msg error message
 * @param st SQL state
 */

#if defined(__GNUC__) && (__GNUC__ >= 2)
static void setstatd(DBC *, int, char *, char *, ...)
    __attribute__((format (printf, 3, 5)));
#endif

static void
setstatd(DBC *d, int naterr, char *msg, char *st, ...)
{
    va_list ap;

    if (!d) {
	return;
    }
    d->naterr = naterr;
    d->logmsg[0] = '\0';
    if (msg) {
	int count;

	va_start(ap, st);
	count = vsnprintf(d->logmsg, sizeof (d->logmsg), msg, ap);
	va_end(ap);
	if (count < 0) {
	    d->logmsg[sizeof (d->logmsg) - 1] = '\0';
	}
    }
    if (!st) {
	st = "?????";
    }
    strncpy(d->sqlstate, st, 5);
    d->sqlstate[5] = '\0';
}

/**
 * Set error message and SQL state on statement
 * @param s statement pointer
 * @param naterr native error code
 * @param msg error message
 * @param st SQL state
 */

#if defined(__GNUC__) && (__GNUC__ >= 2)
static void setstat(STMT *, int, char *, char *, ...)
    __attribute__((format (printf, 3, 5)));
#endif

static void
setstat(STMT *s, int naterr, char *msg, char *st, ...)
{
    va_list ap;

    if (!s) {
	return;
    }
    s->naterr = naterr;
    s->logmsg[0] = '\0';
    if (msg) {
	int count;

	va_start(ap, st);
	count = vsnprintf(s->logmsg, sizeof (s->logmsg), msg, ap);
	va_end(ap);
	if (count < 0) {
	    s->logmsg[sizeof (s->logmsg) - 1] = '\0';
	}
    }
    if (!st) {
	st = "?????";
    }
    strncpy(s->sqlstate, st, 5);
    s->sqlstate[5] = '\0';
}

/**
 * Report IM001 (not implemented) SQL error code for HDBC.
 * @param dbc database connection handle
 * @result ODBC error code
 */

static SQLRETURN
drvunimpldbc(HDBC dbc)
{
    DBC *d;

    if (dbc == SQL_NULL_HDBC) {
	return SQL_INVALID_HANDLE;
    }
    d = (DBC *) dbc;
    setstatd(d, -1, "not supported", "IM001");
    return SQL_ERROR;
}

/**
 * Report IM001 (not implemented) SQL error code for HSTMT.
 * @param stmt statement handle
 * @result ODBC error code
 */

static SQLRETURN
drvunimplstmt(HSTMT stmt)
{
    STMT *s;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    setstat(s, -1, "not supported", "IM001");
    return SQL_ERROR;
}

/**
 * Free memory given pointer to memory pointer.
 * @param x pointer to pointer to memory to be free'd
 */

static void
freep(void *x)
{
    if (x && ((char **) x)[0]) {
	xfree(((char **) x)[0]);
	((char **) x)[0] = NULL;
    }
}

/**
 * Report S1000 (out of memory) SQL error given STMT.
 * @param s statement pointer
 * @result ODBC error code
 */

static SQLRETURN
nomem(STMT *s)
{
    setstat(s, -1, "out of memory", (*s->ov3) ? "HY000" : "S1000");
    return SQL_ERROR;
}

/**
 * Report S1000 (not connected) SQL error given STMT.
 * @param s statement pointer
 * @result ODBC error code
 */

static SQLRETURN
noconn(STMT *s)
{
    setstat(s, -1, "not connected", (*s->ov3) ? "HY000" : "S1000");
    return SQL_ERROR;
}

/**
 * Internal locale neutral strtod function.
 * @param data pointer to string
 * @param endp pointer for ending character
 * @result double value
 */

#if defined(HAVE_SQLITE3ATOF) && HAVE_SQLITE3ATOF

extern double sqlite3AtoF(char *data, char **endp);

#define ln_strtod sqlite3AtoF

#else

static double
ln_strtod(const char *data, char **endp)
{
#if defined(HAVE_LOCALECONV) || defined(_WIN32)
    struct lconv *lc;
    char buf[128], *p, *end;
    double value;

    lc = localeconv();
    if (lc && lc->decimal_point && lc->decimal_point[0] &&
	lc->decimal_point[0] != '.') {
	strncpy(buf, data, sizeof (buf) - 1);
	buf[sizeof (buf) - 1] = '\0';
	p = strchr(buf, '.');
	if (p) {
	    *p = lc->decimal_point[0];
	}
	p = buf;
    } else {
	p = (char *) data;
    }
    value = strtod(p, &end);
    end = (char *) data + (end - p);
    if (endp) {
	*endp = end;
    }
    return value;
#else
    return strtod(data, endp);
#endif
}

#endif

/**
 * Busy callback for SQLite.
 * @param udata user data, pointer to DBC
 * @param count count of subsequenct calls
 * @result true or false
 */

static int
busy_handler(void *udata, int count)
{
    DBC *d = (DBC *) udata;
    long t1;
    int ret = 0;
#ifndef _WIN32
    struct timeval tv;
#endif

    if (d->timeout <= 0) {
	return ret;
    }
    if (count <= 1) {
#ifdef _WIN32
	d->t0 = GetTickCount();
#else
	gettimeofday(&tv, NULL);
	d->t0 = tv.tv_sec * 1000 + tv.tv_usec / 1000;
#endif
    }
#ifdef _WIN32
    t1 = GetTickCount();
#else
    gettimeofday(&tv, NULL);
    t1 = tv.tv_sec * 1000 + tv.tv_usec / 1000;
#endif
    if (t1 - d->t0 > d->timeout) {
	goto done;
	return 0;
    }
#ifdef _WIN32
    Sleep(10);
#else
#ifdef HAVE_USLEEP
    usleep(10000);
#else
    tv.tv_sec = 0;
    tv.tv_usec = 10000;
    select(0, NULL, NULL, NULL, &tv);
#endif
#endif
    ret = 1;
done:
    return ret;
}

/**
 * Set SQLite options (PRAGMAs) given SQLite handle.
 * @param x SQLite database handle
 * @param d DBC pointer
 * @result SQLite error code
 *
 * "full_column_names" is always turned on to get the table
 * names in column labels. "count_changes" is always turned
 * on to get the number of affected rows for INSERTs et.al.
 */

static int
setsqliteopts(sqlite3 *x, DBC *d)
{
    int count = 0, step = 0, rc;

    while (step < 2) {
	if (step < 1) {
	    rc = sqlite3_exec(x, "PRAGMA full_column_names = on;",
			      NULL, NULL, NULL);
	} else if (step < 2) {
	    rc = sqlite3_exec(x, "PRAGMA empty_result_callbacks = on;",
			      NULL, NULL, NULL);
	}
	if (rc != SQLITE_OK) {
	    if (rc != SQLITE_BUSY ||
		!busy_handler((void *) d, ++count)) {
		return rc;
	    }
	    continue;
	}
	count = 0;
	++step;
    }
    sqlite3_busy_handler(x, busy_handler, (void *) d);
    return SQLITE_OK;
}

/**
 * Free counted array of char pointers.
 * @param rowp pointer to char pointer array
 *
 * The -1-th element of the array holds the array size.
 * All non-NULL pointers of the array and then the array
 * itself are free'd.
 */

static void
freerows(char **rowp)
{
    int size, i;

    if (!rowp) {
	return;
    }
    --rowp;
    size = (int) rowp[0];
    for (i = 1; i <= size; i++) {
	freep(&rowp[i]);
    }
    freep(&rowp);
}

/**
 * Map SQL field type from string to ODBC integer type code.
 * @param typename field type string
 * @param nosign pointer to indicator for unsigned field or NULL
 * @param ov3 boolean, true for SQL_OV_ODBC3
 * @result SQL data type
 */

static int
mapsqltype(const char *typename, int *nosign, int ov3)
{
    char *p, *q;
    int testsign = 0, result;

    result = SQL_VARCHAR;
    if (!typename) {
	return result;
    }
    q = p = xmalloc(strlen(typename) + 1);
    if (!p) {
	return result;
    }
    strcpy(p, typename);
    while (*q) {
	*q = TOLOWER(*q);
	++q;
    }
    if (strncmp(p, "inter", 5) == 0) {
    } else if (strncmp(p, "int", 3) == 0 ||
	strncmp(p, "mediumint", 9) == 0) {
	testsign = 1;
	result = SQL_INTEGER;
    } else if (strncmp(p, "numeric", 7) == 0) {
	result = SQL_DOUBLE;
    } else if (strncmp(p, "tinyint", 7) == 0) {
	testsign = 1;
	result = SQL_TINYINT;
    } else if (strncmp(p, "smallint", 8) == 0) {
	testsign = 1;
	result = SQL_SMALLINT;
    } else if (strncmp(p, "float", 5) == 0) {
	result = SQL_DOUBLE;
    } else if (strncmp(p, "double", 6) == 0 ||
	strncmp(p, "real", 4) == 0) {
	result = SQL_DOUBLE;
    } else if (strncmp(p, "timestamp", 9) == 0) {
#ifdef SQL_TYPE_TIMESTAMP
	result = ov3 ? SQL_TYPE_TIMESTAMP : SQL_TIMESTAMP;
#else
	result = SQL_TIMESTAMP;
#endif
    } else if (strncmp(p, "datetime", 8) == 0) {
#ifdef SQL_TYPE_TIMESTAMP
	result = ov3 ? SQL_TYPE_TIMESTAMP : SQL_TIMESTAMP;
#else
	result = SQL_TIMESTAMP;
#endif
    } else if (strncmp(p, "time", 4) == 0) {
#ifdef SQL_TYPE_TIME
	result = ov3 ? SQL_TYPE_TIME : SQL_TIME;
#else
	result = SQL_TIME;
#endif
    } else if (strncmp(p, "date", 4) == 0) {
#ifdef SQL_TYPE_DATE
	result = ov3 ? SQL_TYPE_DATE : SQL_DATE;
#else
	result = SQL_DATE;
#endif
#ifdef SQL_LONGVARCHAR
    } else if (strncmp(p, "text", 4) == 0) {
	result = SQL_LONGVARCHAR;
#endif
    }
    if (nosign) {
	if (testsign) {
	    *nosign = strstr(p, "unsigned") != NULL;
	} else {
	    *nosign = 1;
	}
    }
    xfree(p);
    return result;
}

/**
 * Get maximum display size and number of decimal points
 * from field type specification.
 * @param typename field type specification
 * @param sqltype target SQL data type
 * @param mp pointer to maximum display size or NULL
 * @param dp pointer to number of decimal points or NULL
 */

static void
getmd(const char *typename, int sqltype, int *mp, int *dp)
{
    int m = 0, d = 0;

    switch (sqltype) {
    case SQL_INTEGER:      m = 10; d = 9; break;
    case SQL_TINYINT:      m = 4; d = 3; break;
    case SQL_SMALLINT:     m = 6; d = 5; break;
    case SQL_FLOAT:        m = 25; d = 24; break;
    case SQL_DOUBLE:       m = 54; d = 53; break;
    case SQL_VARCHAR:      m = 255; d = 0; break;
#ifdef SQL_TYPE_DATE
    case SQL_TYPE_DATE:
#endif
    case SQL_DATE:         m = 10; d = 0; break;
#ifdef SQL_TYPE_TIME
    case SQL_TYPE_TIME:
#endif
    case SQL_TIME:         m = 8; d = 0; break;
#ifdef SQL_TYPE_TIMESTAMP
    case SQL_TYPE_TIMESTAMP:
#endif
    case SQL_TIMESTAMP:    m = 32; d = 0; break;
#ifdef SQL_LONGVARCHAR
    case SQL_LONGVARCHAR : m = 65536; d = 0; break;
#endif
    case SQL_VARBINARY: m = 255; d = 0; break;
    case SQL_LONGVARBINARY: m = 65536; d = 0; break;
    }
    if (m && typename) {
	int mm, dd;

	if (sscanf(typename, "%*[^(](%d)", &mm) == 1) {
	    m = d = mm;
	} else if (sscanf(typename, "%*[^(](%d,%d)", &mm, &dd) == 2) {
	    m = mm;
	    d = dd;
	}
    }
    if (mp) {
	*mp = m;
    }
    if (dp) {
	*dp = d;
    }
}

/**
 * Map SQL_C_DEFAULT to proper C type.
 * @param type input C type
 * @param stype input SQL type
 * @param nosign 0=signed, 0>unsigned, 0<undefined
 * @result C type
 */

static int
mapdeftype(int type, int stype, int nosign)
{
    if (type == SQL_C_DEFAULT) {
	switch (stype) {
	case SQL_INTEGER:
	    type = nosign > 0 ? SQL_C_ULONG : SQL_C_LONG;
	    break;
	case SQL_TINYINT:
	    type = nosign > 0 ? SQL_C_UTINYINT : SQL_C_TINYINT;
	    break;
	case SQL_SMALLINT:
	    type = nosign > 0 ? SQL_C_USHORT : SQL_C_SHORT;
	    break;
	case SQL_FLOAT:
	    type = SQL_C_FLOAT;
	    break;
	case SQL_DOUBLE:
	    type = SQL_C_DOUBLE;
	    break;
	case SQL_TIMESTAMP:
	    type = SQL_C_TIMESTAMP;
	    break;
	case SQL_TIME:
	    type = SQL_C_TIME;
	    break;
	case SQL_DATE:
	    type = SQL_C_DATE;
	    break;
#ifdef SQL_C_TYPE_TIMESTAMP
	case SQL_TYPE_TIMESTAMP:
	    type = SQL_C_TYPE_TIMESTAMP;
	    break;
#endif
#ifdef SQL_C_TYPE_TIME
	case SQL_TYPE_TIME:
	    type = SQL_C_TYPE_TIME;
	    break;
#endif
#ifdef SQL_C_TYPE_DATE
	case SQL_TYPE_DATE:
	    type = SQL_C_TYPE_DATE;
	    break;
#endif
	case SQL_BINARY:
	case SQL_VARBINARY:
	case SQL_LONGVARBINARY:
	    type = SQL_C_BINARY;
	    break;
	default:
	    type = SQL_C_CHAR;
	}
    }
    return type;
}

/**
 * Fixup query string with optional parameter markers.
 * @param sql original query string
 * @param sqlLen length of query string or SQL_NTS
 * @param nparam output number of parameters
 * @param isselect output indicator for SELECT statement
 * @param errmsg output error message
 * @result newly allocated string containing query string for SQLite or NULL
 */

static char *
fixupsql(char *sql, int sqlLen, int *nparam, int *isselect, char **errmsg)
{
    char *q = sql, *qz = NULL, *p, *inq = NULL, *out;
    int np = 0, size;

    *errmsg = NULL;
    if (sqlLen != SQL_NTS) {
	qz = q = xmalloc(sqlLen + 1);
	if (!qz) {
	    return NULL;
	}
	memcpy(q, sql, sqlLen);
	q[sqlLen] = '\0';
	size = sqlLen * 4;
    } else {
	size = strlen(sql) * 4;
    }
    size += sizeof (char *) - 1;
    size &= ~(sizeof (char *) - 1);
    p = xmalloc(size);
    if (!p) {
errout:
	freep(&qz);
	return NULL;
    }
    out = p;
    while (*q) {
	switch (*q) {
	case '\'':
	case '\"':
	    if (q == inq) {
		inq = NULL;
	    } else if (!inq) {
		inq = q + 1;

		while (*inq) {
		    if (*inq == *q) {
			if (inq[1] == *q) {
			    inq++;
			} else {
			    break;
			}
		    }
		    inq++;
		}
	    }
	    *p++ = *q;
	    break;
	case '?':
	    if (inq) {
		*p++ = *q;
	    } else {
		*p++ = '%';
		*p++ = 'Q';
		np++;
	    }
	    break;
	case ';':
	    if (inq) {
		*p++ = *q;
	    } else {
		do {
		    ++q;
		} while (*q && ISSPACE(*q));
		if (*q) {		
		    freep(&out);
		    *errmsg = "only one SQL statement allowed";
		    goto errout;
		}
		--q;
	    }
	    break;
	case '%':
	    *p++ = '%';
	    *p++ = '%';
	    break;
	case '{':
	    /* deal with {d 'YYYY-MM-DD'}, {t ...}, and {ts ...} */
	    if (!inq) {
		char *end = q + 1;

		while (*end && *end != '}') {
		    ++end;
		}
		if (*end == '}') {
		    char *start = q + 1;
		    char *end2 = end - 1;

		    while (start < end2 && *start != '\'') {
			++start;
		    }
		    while (end2 > start && *end2 != '\'') {
			--end2;
		    }
		    if (*start == '\'' && *end2 == '\'') {
			while (start <= end2) {
			    *p++ = *start;
			    ++start;
			}
			q = end;
			break;
		    }
		}
	    }
	    /* FALL THROUGH */
	default:
	    *p++ = *q;
	}
	++q;
    }
    freep(&qz);
    *p = '\0';
    if (nparam) {
	*nparam = np;
    }
    if (isselect) {
	p = out;
	while (*p && ISSPACE(*q)) {
	    ++p;
	}
	*isselect = strncasecmp(p, "select", 6) == 0;
    }
    return out;
}

/**
 * Find column given name in string array.
 * @param cols string array
 * @param ncols number of strings
 * @param name column name
 * @result >= 0 on success, -1 on error
 */

static int
findcol(char **cols, int ncols, char *name)
{
    int i;

    if (cols) {
	for (i = 0; i < ncols; i++) {
	    if (strcmp(cols[i], name) == 0) {
		return i;
	    }
	}
    }
    return -1;
}

/**
 * Fixup column information for a running statement.
 * @param s statement to get fresh column information
 * @param sqlite SQLite database handle
 *
 * The column labels get the table names stripped
 * when there's more than one column and all table
 * names are identical.
 *
 * The "dyncols" field of STMT is filled with column
 * information obtained by SQLite "PRAGMA table_info"
 * for each column whose table name is known. If the
 * types are already present as with SQLite 2.5.7
 * this information is used instead.
 */

static void
fixupdyncols(STMT *s, sqlite3 *sqlite)
{
    int i, k, pk, t, r, nrows, ncols, doautoinc = 0;
    char **rowp, *flagp, flags[128];

    if (!s->dyncols) {
	return;
    }
    /* fixup labels */
    if (s->dcols > 1) {
	char *table = s->dyncols[0].table;

	for (i = 1; table[0] && i < s->dcols; i++) {
	    if (strcmp(s->dyncols[i].table, table)) {
		break;
	    }
	}
	if (i >= s->dcols) {
	    for (i = 0; i < s->dcols; i++) {
		s->dyncols[i].label = s->dyncols[i].column;
	    }
	}
    } else if (s->dcols == 1) {
	s->dyncols[0].label = s->dyncols[0].column;
    }
    for (i = 0; i < s->dcols; i++) {
	s->dyncols[i].type =
	    mapsqltype(s->dyncols[i].typename, &s->dyncols[i].nosign, *s->ov3);
	getmd(s->dyncols[i].typename, s->dyncols[i].type,
	      &s->dyncols[i].size, NULL);
#ifdef SQL_LONGVARCHAR
	if (s->dyncols[i].type == SQL_VARCHAR &&
	    s->dyncols[i].size > 255) {
	    s->dyncols[i].type = SQL_LONGVARCHAR;
	}
#endif
	if (s->dyncols[i].type == SQL_VARBINARY &&
	    s->dyncols[i].size > 255) {
	    s->dyncols[i].type = SQL_LONGVARBINARY;
	}
	if (s->dyncols[i].typename && strlen(s->dyncols[i].typename) == 7 &&
	    strncasecmp(s->dyncols[i].typename, "integer", 7) == 0) {
	    doautoinc++;
	    s->dyncols[i].autoinc = -1;
	} else {
	    s->dyncols[i].autoinc = 0;
	}
    }
    if (!doautoinc) {
	return;
    }
    if (s->dcols > array_size(flags)) {
	flagp = xmalloc(sizeof (flags[0]) * s->dcols);
	if (flagp == NULL) {
	    return;
	}
    } else {
	flagp = flags;
    }
    memset(flagp, 0, sizeof (flags[0]) * s->dcols);
    for (i = 0; i < s->dcols; i++) {
	s->dyncols[i].autoinc = 0;
    }
    for (i = 0; i < s->dcols; i++) {
	int ret, lastpk = -1, autoinccount = 0;
	char *sql;

	if (!s->dyncols[i].table[0]) {
	    continue;
	}
	if (flagp[i]) {
	    continue;
	}
	sql = sqlite3_mprintf("PRAGMA table_info('%q')", s->dyncols[i].table);
	if (!sql) {
	    continue;
	}
	ret = sqlite3_get_table(sqlite, sql, &rowp, &nrows, &ncols, NULL);
	sqlite3_free(sql);
	if (ret != SQLITE_OK) {
	    continue;
	}
	k = findcol(rowp, ncols, "name");
	t = findcol(rowp, ncols, "type");
	pk = findcol(rowp, ncols, "pk");
	if (k < 0 || t < 0) {
	    goto freet;
	}
	for (r = 1; r <= nrows; r++) {
	    int m;

	    for (m = i; m < s->dcols; m++) {
		if (!flagp[m] &&
		    strcmp(s->dyncols[m].column, rowp[r * ncols + k]) == 0 &&
		    strcmp(s->dyncols[m].table, s->dyncols[i].table) == 0) {
		    char *typename = rowp[r * ncols + t];

		    flagp[m] = 1;
		    freep(&s->dyncols[m].typename);
		    s->dyncols[m].typename = xstrdup(typename);
		    s->dyncols[m].type =
			mapsqltype(typename, &s->dyncols[m].nosign, *s->ov3);
		    getmd(typename, s->dyncols[m].type, &s->dyncols[m].size,
			  NULL);
#ifdef SQL_LONGVARCHAR
		    if (s->dyncols[m].type == SQL_VARCHAR &&
			s->dyncols[m].size > 255) {
			s->dyncols[m].type = SQL_LONGVARCHAR;
		    }
#endif
		    if (s->dyncols[i].type == SQL_VARBINARY &&
			s->dyncols[i].size > 255) {
			s->dyncols[i].type = SQL_LONGVARBINARY;
		    }
		    if (pk >= 0	&& strcmp(rowp[r * ncols + pk], "1") == 0) {
			if (++autoinccount > 1) {
			    if (lastpk >= 0) {
				s->dyncols[lastpk].autoinc = 0;
				lastpk = -1;
			    }
			} else {
			    lastpk = m;
			    if (strlen(typename) == 7 &&
				strncasecmp(typename, "integer", 7) == 0) {
				s->dyncols[m].autoinc = 1;
			    }
			}
		    }
		}
	    }
	}
freet:
	sqlite3_free_table(rowp);
    }
    if (flagp != flags) {
	freep(&flagp);
    }
}

/**
 * Return number of month days.
 * @param year
 * @param month 1..12
 * @result number of month days or 0
 */

static int
getmdays(int year, int month)
{
    static const int mdays[] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    int mday;

    if (month < 1) {
	return 0;
    }
    mday = mdays[(month - 1) % 12];
    if (mday == 28 && year % 4 == 0 &&
	(!(year % 100 == 0) || year % 400 == 0)) {
	mday++;
    }
    return mday;
}

/**
 * Convert string to ODBC DATE_STRUCT.
 * @param str string to be converted
 * @param ds output DATE_STRUCT
 * @result 0 on success, -1 on error
 *
 * Strings of the format 'YYYYMMDD' or 'YYYY-MM-DD' or
 * 'YYYY/MM/DD' are converted to a DATE_STRUCT.
 */

static int
str2date(char *str, DATE_STRUCT *ds)
{
    int i, err = 0;
    char *p, *q;

    ds->year = ds->month = ds->day = 0;
    p = str;
    while (*p && !ISDIGIT(*p)) {
	++p;
    }
    q = p;
    i = 0;
    while (*q && !ISDIGIT(*q)) {
	++i;
	++q;
    }
    if (i >= 8) {
	char buf[8];

	strncpy(buf, p + 0, 4); buf[4] = '\0';
	ds->year = strtol(buf, NULL, 10);
	strncpy(buf, p + 4, 2); buf[2] = '\0';
	ds->month = strtol(buf, NULL, 10);
	strncpy(buf, p + 6, 2); buf[2] = '\0';
	ds->day = strtol(buf, NULL, 10);
	goto done;
    }
    i = 0;
    while (i < 3) {
	int n;

	q = NULL; 
	n = strtol(p, &q, 10);
	if (!q || q == p) {
	    if (*q == '\0') {
		if (i == 0) {
		    err = 1;
		}
		goto done;
	    }
	}
	if (*q == '-' || *q == '/' || *q == '\0' || i == 2) {
	    switch (i) {
	    case 0: ds->year = n; break;
	    case 1: ds->month = n; break;
	    case 2: ds->day = n; break;
	    }
	    ++i;
	    if (*q) {
		++q;
	    }
	} else {
	    i = 0;
	    while (*q && !ISDIGIT(*q)) {
		++q;
	    }
	}
	p = q;
    }
done:
    /* final check for overflow */
    if (err ||
	ds->month < 1 || ds->month > 12 ||
	ds->day < 1 || ds->day > getmdays(ds->year, ds->month)) {
	return -1;
    }
    return 0;
}

/**
 * Convert string to ODBC TIME_STRUCT.
 * @param str string to be converted
 * @param ts output TIME_STRUCT
 * @result 0 on success, -1 on error
 *
 * Strings of the format 'HHMMSS' or 'HH:MM:SS'
 * are converted to a TIME_STRUCT.
 */

static int
str2time(char *str, TIME_STRUCT *ts)
{
    int i, err = 0;
    char *p, *q;

    ts->hour = ts->minute = ts->second = 0;
    p = str;
    while (*p && !ISDIGIT(*p)) {
	++p;
    }
    q = p;
    i = 0;
    while (*q && ISDIGIT(*q)) {
	++i;
	++q;
    }
    if (i >= 6) {
	char buf[4];

	strncpy(buf, p + 0, 2); buf[2] = '\0';
	ts->hour = strtol(buf, NULL, 10);
	strncpy(buf, p + 2, 2); buf[2] = '\0';
	ts->minute = strtol(buf, NULL, 10);
	strncpy(buf, p + 4, 2); buf[2] = '\0';
	ts->second = strtol(buf, NULL, 10);
	goto done;
    }
    i = 0;
    while (i < 3) {
	int n;

	q = NULL; 
	n = strtol(p, &q, 10);
	if (!q || q == p) {
	    if (*q == '\0') {
		if (i == 0) {
		    err = 1;
		}
		goto done;
	    }
	}
	if (*q == ':' || *q == '\0' || i == 2) {
	    switch (i) {
	    case 0: ts->hour = n; break;
	    case 1: ts->minute = n; break;
	    case 2: ts->second = n; break;
	    }
	    ++i;
	    if (*q) {
		++q;
	    }
	} else {
	    i = 0;
	    while (*q && !ISDIGIT(*q)) {
		++q;
	    }
	}
	p = q;
    }
done:
    /* final check for overflow */
    if (err || ts->hour > 23 || ts->minute > 59 || ts->second > 59) {
	return -1;
    }
    return 0;
}

/**
 * Convert string to ODBC TIMESTAMP_STRUCT.
 * @param str string to be converted
 * @param tss output TIMESTAMP_STRUCT
 * @result 0 on success, -1 on error
 *
 * Strings of the format 'YYYYMMDDhhmmssff' or 'YYYY-MM-DD hh:mm:ss ff'
 * or 'YYYY/MM/DD hh:mm:ss ff' or 'hh:mm:ss ff YYYY-MM-DD' are
 * converted to a TIMESTAMP_STRUCT. The ISO8601 formats
 *    YYYY-MM-DDThh:mm:ss[.f]Z
 *    YYYY-MM-DDThh:mm:ss[.f]shh:mm
 * are also supported. In case a time zone field is present,
 * the resulting TIMESTAMP_STRUCT is expressed in UTC.
 */

static int
str2timestamp(char *str, TIMESTAMP_STRUCT *tss)
{
    int i, m, n, err = 0;
    char *p, *q, in = '\0';

    tss->year = tss->month = tss->day = 0;
    tss->hour = tss->minute = tss->second = 0;
    tss->fraction = 0;
    p = str;
    while (*p && !ISDIGIT(*p)) {
	++p;
    }
    q = p;
    i = 0;
    while (*q && ISDIGIT(*q)) {
	++i;
	++q;
    }
    if (i >= 14) {
	char buf[16];

	strncpy(buf, p + 0, 4); buf[4] = '\0';
	tss->year = strtol(buf, NULL, 10);
	strncpy(buf, p + 4, 2); buf[2] = '\0';
	tss->month = strtol(buf, NULL, 10);
	strncpy(buf, p + 6, 2); buf[2] = '\0';
	tss->day = strtol(buf, NULL, 10);
	strncpy(buf, p + 8, 2); buf[2] = '\0';
	tss->hour = strtol(buf, NULL, 10);
	strncpy(buf, p + 10, 2); buf[2] = '\0';
	tss->minute = strtol(buf, NULL, 10);
	strncpy(buf, p + 12, 2); buf[2] = '\0';
	tss->second = strtol(buf, NULL, 10);
	if (i > 14) {
	    m = i - 14;
	    strncpy(buf, p + 14, m);
	    while (m < 9) {
		buf[m] = '0';
		++m;
	    }
	    buf[m] = '\0';
	    tss->fraction = strtol(buf, NULL, 0);
	}
	m = 7;
	goto done;
    }
    m = i = 0;
    while ((m & 7) != 7) {
	q = NULL; 
	n = strtol(p, &q, 10);
	if (!q || q == p) {
	    if (*q == '\0') {
		if (m < 1) {
		    err = 1;
		}
		goto done;
	    }
	}
	if (in == '\0') {
	    switch (*q) {
	    case '-':
	    case '/':
		if ((m & 1) == 0) {
		    in = *q;
		    i = 0;
		}
		break;
	    case ':':
		if ((m & 2) == 0) {
		    in = *q;
		    i = 0;
		}
		break;
	    case ' ':
	    case '.':
		break;
	    default:
		in = '\0';
		i = 0;
		break;
	    }
	}
	switch (in) {
	case '-':
	case '/':
	    switch (i) {
	    case 0: tss->year = n; break;
	    case 1: tss->month = n; break;
	    case 2: tss->day = n; break;
	    }
	    if (++i >= 3) {
		i = 0;
		m |= 1;
		if (!(m & 2)) {
		    m |= 8;
		}
		goto skip;
	    } else {
		++q;
	    }
	    break;
	case ':':
	    switch (i) {
	    case 0: tss->hour = n; break;
	    case 1: tss->minute = n; break;
	    case 2: tss->second = n; break;
	    }
	    if (++i >= 3) {
		i = 0;
		m |= 2;
		if (*q == '.') {
		    in = '.';
		    goto skip2;
		}
		if (*q == ' ') {
		    if ((m & 1) == 0) {
			char *e = NULL;

			strtol(q + 1, &e, 10);
			if (e && *e == '-') {
			    goto skip;
			}
		    }
		    in = '.';
		    goto skip2;
		}
		goto skip;
	    } else {
		++q;
	    }
	    break;
	case '.':
	    if (++i >= 1) {
		int ndig = q - p;

		if (p[0] == '+' || p[0] == '-') {
		    ndig--;
		}
		while (ndig < 9) {
		    n = n * 10;
		    ++ndig;
		}
		tss->fraction = n;
		m |= 4;
		i = 0;
	    }
	default:
	skip:
	    in = '\0';
	skip2:
	    while (*q && !ISDIGIT(*q)) {
		++q;
	    }
	}
	p = q;
    }
    if ((m & 7) > 1 && (m & 8)) {
	/* ISO8601 timezone */
	if (p > str && ISDIGIT(*p)) {
	    int nn, sign;

	    q = p - 1;
	    if (*q != '+' && *q != '-') {
		goto done;
	    }
	    sign = *q == '+' ? -1 : 1;
	    q = NULL;
	    n = strtol(p, &q, 10);
	    if (!q || *q++ != ':' || !ISDIGIT(*q)) {
		goto done;
	    }
	    p = q;
	    q = NULL;
	    nn = strtol(p, &q, 0);
	    tss->minute += nn * sign;
	    if ((SQLSMALLINT) tss->minute < 0) {
		tss->hour -= 1;
		tss->minute += 60;
	    } else if (tss->minute >= 60) {
		tss->hour += 1;
		tss->minute -= 60;
	    }
	    tss->hour += n * sign;
	    if ((SQLSMALLINT) tss->hour < 0) {
		tss->day -= 1;
		tss->hour += 24;
	    } else if (tss->hour >= 24) {
		tss->day += 1;
		tss->hour -= 24;
	    }
	    if ((short) tss->day < 1 || tss->day >= 28) {
		int mday, pday, pmon;

		mday = getmdays(tss->year, tss->month);
		pmon = tss->month - 1;
		if (pmon < 1) {
		    pmon = 12;
		}
		pday = getmdays(tss->year, pmon);
		if ((SQLSMALLINT) tss->day < 1) {
		    tss->month -= 1;
		    tss->day = pday;
		} else if (tss->day > mday) {
		    tss->month += 1;
		    tss->day = 1;
		}
		if ((SQLSMALLINT) tss->month < 1) {
		    tss->year -= 1;
		    tss->month = 12;
		} else if (tss->month > 12) {
		    tss->year += 1;
		    tss->month = 1;
		}
	    }
	}
    }
done:
    /* final check for overflow */
    if (err ||
	tss->month < 1 || tss->month > 12 ||
	tss->day < 1 || tss->day > getmdays(tss->year, tss->month) ||
	tss->hour > 23 || tss->minute > 60 || tss->second > 60) {
	return -1;
    }
    return (m & 7) < 1 ? -1 : 0;
}

/**
 * Get boolean flag from string.
 * @param string string to be inspected
 * @result true or false
 */

static int
getbool(char *string)
{
    if (string) {
	return string[0] && strchr("Yy123456789Tt", string[0]) != NULL;
    }
    return 0;
}

/**
 * SQLite trace callback
 * @param arg DBC pointer
 */

static void
dbtrace(void *arg, const char *msg)
{
    DBC *d = (DBC *) arg;

    if (msg && d->trace) {
	int len = strlen(msg);

	if (len > 0) {
	    char *end = "\n";

	    if (msg[len - 1] != ';') {
		end = ";\n";
	    }
	    fprintf(d->trace, "%s%s", msg, end);
	    fflush(d->trace);
	}
    }
}

/**
 * Trace function for SQLite return codes
 * @param rc SQLite return code
 * @param err error string or NULL
 */

static void
dbtracerc(DBC *d, int rc, char *err)
{
    if (rc != SQLITE_OK && d->trace) {
	fprintf(d->trace, "-- SQLITE ERROR CODE %d", rc);
	fprintf(d->trace, err ? ": %s\n" : "\n", err);
	fflush(d->trace);
    }
}

/**
 * Open SQLite database file given file name and flags.
 * @param d DBC pointer
 * @param name file name
 * @param dsn data source name
 * @param sflag STEPAPI flag
 * @param busy busy/lock timeout
 * @result ODBC error code
 */

static SQLRETURN
dbopen(DBC *d, char *name, char *dsn, char *sflag, char *busy)
{
    char *endp = NULL;
    int rc, tmp, busyto = 1000;

    if (d->sqlite) {
	sqlite3_close(d->sqlite);
	d->sqlite = NULL;
    }
    rc = sqlite3_open(name, &d->sqlite);
    if (rc != SQLITE_OK) {
connfail:
	setstatd(d, rc, "connect failed", (*d->ov3) ? "HY000" : "S1000");
	return SQL_ERROR;
    }
    if (d->trace) {
	sqlite3_trace(d->sqlite, dbtrace, d);
    }
    d->step_enable = getbool(sflag);
    d->curtype = d->step_enable ?
	SQL_CURSOR_FORWARD_ONLY : SQL_CURSOR_STATIC;
    tmp = strtol(busy, &endp, 0);
    if (endp && *endp == '\0' && endp != busy) {
	busyto = tmp;
    }
    if (busyto < 1 || busyto > 1000000) {
	busyto = 1000000;
    }
    d->timeout = busyto;
    if (setsqliteopts(d->sqlite, d) != SQLITE_OK) {
	sqlite3_close(d->sqlite);
	d->sqlite = NULL;
	goto connfail;
    }
    freep(&d->dbname);
    d->dbname = xstrdup(name);
    freep(&d->dsn);
    d->dsn = xstrdup(dsn);
    return SQL_SUCCESS;
}

/**
 * Find out column type
 * @s3stmt SQLite statement pointer
 * @col column number
 * @result type name as string
 */

static char *
s3stmt_coltype(sqlite3_stmt *s3stmt, int col)
{
   char *typename = (char *) sqlite3_column_decltype(s3stmt, col);

   if (!typename) {
       switch (sqlite3_column_type(s3stmt, col)) {
       case SQLITE_INTEGER: typename = "integer"; break;
       case SQLITE_FLOAT:   typename = "double";  break;
       default:
       case SQLITE_TEXT:    typename = "varchar"; break;
#if 0
       case SQLITE_BLOB:    typename = "blob";    break;
       case SQLITE_NULL:    typename = "null";    break;
#endif
       }
   }
   return typename;
}

/**
 * Do one sqlite statement step gathering one result row
 * @param s statement pointer
 * @result ODBC error code
 */

static int
s3stmt_step(STMT *s)
{
    DBC *d = (DBC *) s->dbc;
    char **rowd = NULL;
    const char *errp = NULL;
    int i, ncols, rc;

    if (s != d->cur_s3stmt || !s->s3stmt) {
	setstat(s, -1, "stale statement", (*s->ov3) ? "HY000" : "S1000");
	return SQL_ERROR;
    }
    rc = sqlite3_step(s->s3stmt);
    if (rc == SQLITE_ROW || rc == SQLITE_DONE) {
	++d->s3stmt_rownum;
	ncols = sqlite3_column_count(s->s3stmt);
	if (d->s3stmt_rownum == 0 && ncols > 0) {
	    int size;
	    char *p;
	    COL *dyncols;
	    const char *colname, *typename;

	    for (i = size = 0; i < ncols; i++) {
		colname = sqlite3_column_name(s->s3stmt, i);
		size += 3 + 3 * strlen(colname);
	    }
	    dyncols = xmalloc(ncols * sizeof (COL) + size);
	    if (!dyncols) {
		freedyncols(s);
		s->ncols = 0;
		sqlite3_finalize(s->s3stmt);
		s->s3stmt = NULL;
		d->cur_s3stmt = NULL;
		return nomem(s);
	    }
	    p = (char *) (dyncols + ncols);
	    for (i = 0; i < ncols; i++) {
		char *q;

		colname = sqlite3_column_name(s->s3stmt, i);
		typename = s3stmt_coltype(s->s3stmt, i);
		dyncols[i].db = ((DBC *) (s->dbc))->dbname;
		strcpy(p, colname);
		dyncols[i].label = p;
		p += strlen(p) + 1;
		q = strchr(colname, '.');
		if (q) {
		    dyncols[i].table = p;
		    strncpy(p, colname, q - colname);
		    p[q - colname] = '\0';
		    p += strlen(p) + 1;
		    strcpy(p, q + 1);
		    dyncols[i].column = p;
		    p += strlen(p) + 1;
		} else {
		    dyncols[i].table = "";
		    strcpy(p, colname);
		    dyncols[i].column = p;
		    p += strlen(p) + 1;
		}
#ifdef SQL_LONGVARCHAR
		dyncols[i].type = SQL_LONGVARCHAR;
		dyncols[i].size = 65536;
#else
		dyncols[i].type = SQL_VARCHAR;
		dyncols[i].size = 255;
#endif
		dyncols[i].index = i;
		dyncols[i].scale = 0;
		dyncols[i].prec = 0;
		dyncols[i].nosign = 1;
		dyncols[i].autoinc = -1;
		dyncols[i].typename = xstrdup(typename);
	    }
	    freedyncols(s);
	    s->ncols = s->dcols = ncols;
	    s->dyncols = s->cols = dyncols;
	    fixupdyncols(s, d->sqlite);
	    mkbindcols(s, s->ncols);
	}
	if (ncols <= 0) {
	    goto killstmt;
	}
	if (rc == SQLITE_DONE) {
	    freeresult(s, 0);
	    s->nrows = 0;
	    sqlite3_finalize(s->s3stmt);
	    s->s3stmt = NULL;
	    d->cur_s3stmt = NULL;
	    return SQL_SUCCESS;
	}
	rowd = xmalloc((1 + 2 * ncols) * sizeof (char *));
	if (rowd) {
	    const unsigned char *value;

	    rowd[0] = (char *) (ncols * 2);
	    ++rowd;
	    for (i = 0; i < ncols; i++) {
		value = sqlite3_column_text(s->s3stmt, i);
		rowd[i] = NULL;
		rowd[i + ncols] = xstrdup(value);
	    }
	    for (i = 0; i < ncols; i++) {
		value = sqlite3_column_text(s->s3stmt, i);
		if (value && !rowd[i + ncols]) {
		    freerows(rowd);
		    rowd = 0;
		    break;
		}
	    }
	}
	if (rowd) {
	    freeresult(s, 0);
	    s->nrows = 1;
	    s->rows = rowd;
	    if (rc == SQLITE_DONE) {
		sqlite3_finalize(s->s3stmt);
		s->s3stmt = NULL;
		d->cur_s3stmt = NULL;
	    }
	    return SQL_SUCCESS;
	}
    }
killstmt:
    rc = sqlite3_finalize(s->s3stmt);
    errp = sqlite3_errmsg(d->sqlite);
    s->s3stmt = NULL;
    d->cur_s3stmt = NULL;
    setstat(s, rc, "%s (%d)", (*s->ov3) ? "HY000" : "S1000",
	    errp ? errp : "unknown error", rc);
    return SQL_ERROR;	
}

/**
 * Stop running sqlite statement
 * @param s statement pointer
 */

static void
s3stmt_end(STMT *s)
{
    DBC *d;

    if (!s || !s->s3stmt) {
	return;
    }
    d = (DBC *) s->dbc;
    sqlite3_finalize(s->s3stmt);
    s->s3stmt = NULL;
    d->cur_s3stmt = NULL;
}

/**
 * Conditionally stop running sqlite statement
 * @param s statement pointer
 */

static void
s3stmt_end_if(STMT *s)
{
    DBC *d = (DBC *) s->dbc;

    if (d && d->cur_s3stmt == s) {
	s3stmt_end(s);
    }
}

/**
 * Start sqlite statement for execution of SELECT statement.
 * @param s statement pointer
 * @param params string array of statement parameters
 * @result ODBC error code
 */

static SQLRETURN
s3stmt_start(STMT *s, char **params)
{
    DBC *d = (DBC *) s->dbc;
    char *sql = NULL;
    const char *endp;
    sqlite3_stmt *s3stmt = NULL;
    int rc;

    sql = sqlite3_vmprintf(s->query, (char *) params);
    if (!sql) {
	return nomem(s);
    }
    rc = sqlite3_prepare(d->sqlite, sql, -1, &s3stmt, &endp);
    sqlite3_free(sql);
    if (rc != SQLITE_OK) {
	if (s3stmt) {
	    sqlite3_finalize(s3stmt);
	}
	setstat(s, rc, "%s (%d)", (*s->ov3) ? "HY000" : "S1000",
		sqlite3_errmsg(d->sqlite), rc);
	return SQL_ERROR;
    }
    s->s3stmt = s3stmt;
    d->cur_s3stmt = s;
    d->s3stmt_rownum = -1;
    return SQL_SUCCESS;
}

/**
 * Function not implemented.
 */

SQLRETURN SQL_API
SQLBulkOperations(SQLHSTMT stmt, SQLSMALLINT oper)
{
    return drvunimplstmt(stmt);
}

/**
 * Function not implemented.
 */

SQLRETURN SQL_API
SQLDataSources(SQLHENV env, SQLUSMALLINT dir, SQLCHAR *srvname,
	       SQLSMALLINT buflen1, SQLSMALLINT *lenp1,
	       SQLCHAR *desc, SQLSMALLINT buflen2, SQLSMALLINT *lenp2)
{
    if (env == SQL_NULL_HENV) {
	return SQL_INVALID_HANDLE;
    }
    return SQL_ERROR;
}

/**
 * Function not implemented.
 */

SQLRETURN SQL_API
SQLDrivers(SQLHENV env, SQLUSMALLINT dir, SQLCHAR *drvdesc,
	   SQLSMALLINT descmax, SQLSMALLINT *desclenp,
	   SQLCHAR *drvattr, SQLSMALLINT attrmax, SQLSMALLINT *attrlenp)
{
    if (env == SQL_NULL_HENV) {
	return SQL_INVALID_HANDLE;
    }
    return SQL_ERROR;
}

/**
 * Function not implemented.
 */

SQLRETURN SQL_API
SQLBrowseConnect(SQLHDBC dbc, SQLCHAR *connin, SQLSMALLINT conninLen,
		 SQLCHAR *connout, SQLSMALLINT connoutMax,
		 SQLSMALLINT *connoutLen)
{
    return drvunimpldbc(dbc);
}

/**
 * Put (partial) parameter data into executing statement.
 * @param stmt statement handle
 * @param data pointer to data
 * @param len length of data
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLPutData(SQLHSTMT stmt, SQLPOINTER data, SQLINTEGER len)
{
    STMT *s;
    int i, dlen, done = 0;
    BINDPARM *p;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    if (!s->query || s->nparams <= 0) {
seqerr:
	setstat(s, -1, "sequence error", "HY010");
	return SQL_ERROR;
    }
    for (i = 0; i < s->nparams; i++) {
	p = &s->bindparms[i];
	if (p->need) {
	    int type = mapdeftype(p->type, p->stype, -1);

	    if (len == SQL_NULL_DATA) {
		freep(&p->param);
		p->ind = &p->len;
		p->len = SQL_NULL_DATA;
		p->need = 0;
	    } else
	    if (type == SQL_C_BINARY) {
		if (len <= 0) {
		    setstat(s, -1, "invalid length", "HY090");
		    return SQL_ERROR;
		}
		goto putd;
	    } else
	    if (type != SQL_C_CHAR) {
		int size = 0;

		switch (type) {
		case SQL_C_TINYINT:
		case SQL_C_UTINYINT:
		case SQL_C_STINYINT:
		    size = sizeof (char);
		    break;
		case SQL_C_SHORT:
		case SQL_C_USHORT:
		case SQL_C_SSHORT:
		    size = sizeof (short);
		    break;
		case SQL_C_LONG:
		case SQL_C_ULONG:
		case SQL_C_SLONG:
		    size = sizeof (long);
		    break;
		case SQL_C_FLOAT:
		    size = sizeof (float);
		    break;
		case SQL_C_DOUBLE:
		    size = sizeof (double);
		    break;
#ifdef SQL_C_TYPE_DATE
		case SQL_C_TYPE_DATE:
#endif
		case SQL_C_DATE:
		    size = sizeof (DATE_STRUCT);
		    break;
#ifdef SQL_C_TYPE_DATE
		case SQL_C_TYPE_TIME:
#endif
		case SQL_C_TIME:
		    size = sizeof (TIME_STRUCT);
		    break;
#ifdef SQL_C_TYPE_DATE
		case SQL_C_TYPE_TIMESTAMP:
#endif
		case SQL_C_TIMESTAMP:
		    size = sizeof (TIMESTAMP_STRUCT);
		    break;
		}
		freep(&p->param);
		p->param = xmalloc(size);
		if (!p->param) {
		    return nomem(s);
		}
		memcpy(p->param, data, size);
		p->len = size;
		p->need = 0;
	    } else if (len == SQL_NTS) {
		char *dp = data;

		dlen = strlen(dp);
		freep(&p->param);
		p->param = xmalloc(dlen + 1);
		if (!p->param) {
		    return nomem(s);
		}
		strcpy(p->param, dp);
		p->len = dlen;
		p->need = 0;
	    } else if (len <= 0) {
		setstat(s, -1, "invalid length", "HY090");
		return SQL_ERROR;
	    } else {
putd:
		dlen = min(p->len - p->offs, len);
		if (!p->param) {
		    setstat(s, -1, "no memory for parameter", "HY013");
		    return SQL_ERROR;
		}
		memcpy((char *) p->param + p->offs, data, dlen);
		p->offs += dlen;
		if (p->offs >= p->len) {
		    *((char *) p->param + p->len) = '\0';
		    p->need = 0;
		}
	    }
	    done = 1;
	    break;
	}
    }
    if (!done) {
	goto seqerr;
    }
    for (i = 0; i < s->nparams; i++) {
	p = &s->bindparms[i];
	if (p->need) {
	    return SQL_NEED_DATA;
	}
    }
    return drvexecute(stmt);
}

/**
 * Clear out parameter bindings, if any.
 * @param s statement pointer
 */

static SQLRETURN
freeparams(STMT *s)
{
    if (s->bindparms) {
	int n;

	for (n = 0; n < s->nbindparms; n++) {
	    if (s->bindparms[n].ind && s->bindparms[n].param) {
		freep(&s->bindparms[n].param);
	    }
	    memset(&s->bindparms[n], 0, sizeof (BINDPARM));
	}
    }
    return SQL_SUCCESS;
}

/* see doc on top */

static SQLRETURN
substparam(STMT *s, int pnum, char **out, int *size)
{
    char buf[256];
    int type, len = 0;
    BINDPARM *p;
    double dval;

    if (!s->bindparms || pnum < 0 || pnum >= s->nbindparms) {
	goto error;
    }
    p = &s->bindparms[pnum];
    type = mapdeftype(p->type, p->stype, -1);
    if (p->need) {
	if (!p->param) {
	    p->len = SQL_LEN_DATA_AT_EXEC(*p->lenp);
	    if (p->len <= 0 && p->len != SQL_NTS && p->len != SQL_NULL_DATA) {
		setstat(s, -1, "invalid length", "HY009");
		return SQL_ERROR;
	    }
	    if (p->len > 0) {
		p->param = xmalloc(p->len + 1);
		if (!p->param) {
		    return nomem(s);
		}
	    }
	}
	return SQL_NEED_DATA;
    }
    if (!p->param || (p->lenp && *p->lenp == SQL_NULL_DATA)) {
	strcpy(buf, "NULL");
	goto bind;
    }
    switch (type) {
    case SQL_C_CHAR:
    case SQL_C_BINARY:
	break;
    case SQL_C_UTINYINT:
	sprintf(buf, "%d", *((unsigned char *) p->param));
	goto bind;
    case SQL_C_TINYINT:
    case SQL_C_STINYINT:
	sprintf(buf, "%d", *((char *) p->param));
	goto bind;
    case SQL_C_USHORT:
	sprintf(buf, "%d", *((unsigned short *) p->param));
	goto bind;
    case SQL_C_SHORT:
    case SQL_C_SSHORT:
	sprintf(buf, "%d", *((short *) p->param));
	goto bind;
    case SQL_C_ULONG:
    case SQL_C_LONG:
    case SQL_C_SLONG:
	sprintf(buf, "%ld", *((long *) p->param));
	goto bind;
    case SQL_C_FLOAT:
	dval = *((float *) p->param);
	goto dodouble;
    case SQL_C_DOUBLE:
	dval = *((double *) p->param);
    dodouble: {
	char *buf2 = sqlite3_mprintf("%.16g", dval);

	if (buf2) {
	    strcpy(buf, buf2);
	    sqlite3_free(buf2);
	} else {
	    strcpy(buf, "NULL");
	}
	goto bind;
    }
#ifdef SQL_C_TYPE_DATE
    case SQL_C_TYPE_DATE:
#endif
    case SQL_C_DATE:
	sprintf(buf, "%04d-%02d-%02d",
		((DATE_STRUCT *) p->param)->year,
		((DATE_STRUCT *) p->param)->month,
		((DATE_STRUCT *) p->param)->day);
	goto bind;
#ifdef SQL_C_TYPE_TIME
    case SQL_C_TYPE_TIME:
#endif
    case SQL_C_TIME:
	sprintf(buf, "%02d:%02d:%02d",
		((TIME_STRUCT *) p->param)->hour,
		((TIME_STRUCT *) p->param)->minute,
		((TIME_STRUCT *) p->param)->second);
	goto bind;
#ifdef SQL_C_TYPE_TIMESTAMP
    case SQL_C_TYPE_TIMESTAMP:
#endif
    case SQL_C_TIMESTAMP:
	sprintf(buf, "%04d-%02d-%02d %02d:%02d:%02d.%d",
		((TIMESTAMP_STRUCT *) p->param)->year,
		((TIMESTAMP_STRUCT *) p->param)->month,
		((TIMESTAMP_STRUCT *) p->param)->day,
		((TIMESTAMP_STRUCT *) p->param)->hour,
		((TIMESTAMP_STRUCT *) p->param)->minute,
		((TIMESTAMP_STRUCT *) p->param)->second,
		(int) ((TIMESTAMP_STRUCT *) p->param)->fraction);
    bind:
	if (out) {
	    strcpy(*out, buf);
	    *out += strlen(buf) + 1;
	}
	if (size) {
	    *size += strlen(buf) + 1;
	}
	return SQL_SUCCESS;
    default:
	goto error;
    }
    if (p->ind) {
	len = p->len;
    } else if (!p->lenp) {
	if (!(p->max != SQL_NTS || p->max == SQL_SETPARAM_VALUE_MAX)) {
error:
	    setstat(s, -1, "invalid parameter", (*s->ov3) ? "07009" : "S1093");
	    return SQL_ERROR;
	}
    } else {
	len = *p->lenp == SQL_NTS ? strlen(p->param) : *p->lenp;
    }
    if (out) {
	if (p->max == SQL_NTS || p->max == SQL_SETPARAM_VALUE_MAX) {
	    strcpy(*out, p->param);
	    *out += strlen(p->param) + 1;
	} else {
	    if (len > 0) {
		memcpy(*out, p->param, len);
		*out += len;
	    }
	    **out = '\0';
	    *out += 1;
	}
    }
    if (size) {
	if (p->max == SQL_NTS || p->max == SQL_SETPARAM_VALUE_MAX) {
	    *size += strlen(p->param) + 1;
	} else {
	    *size += len > 0 ? len + 1 : 1;
	}
    }
    return SQL_SUCCESS;
}

/**
 * Internal bind parameter on HSTMT.
 * @param stmt statement handle
 * @param pnum parameter number, starting at 1
 * @param iotype input/output type of parameter
 * @param buftype type of host variable
 * @param ptype
 * @param coldef
 * @param scale
 * @param data pointer to host variable
 * @param buflen length of host variable
 * @param len output length pointer
 * @result ODBC error code
 */

static SQLRETURN
drvbindparam(SQLHSTMT stmt, SQLUSMALLINT pnum, SQLSMALLINT iotype,
	     SQLSMALLINT buftype, SQLSMALLINT ptype, SQLUINTEGER coldef,
	     SQLSMALLINT scale,
	     SQLPOINTER data, SQLINTEGER buflen, SQLINTEGER *len)
{
    STMT *s;
    BINDPARM *p;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    if (pnum == 0) {
	setstat(s, -1, "invalid parameter", (*s->ov3) ? "07009" : "S1093");
	return SQL_ERROR;
    }
    if (!data && (!len || (*len != SQL_NULL_DATA &&
			   *len > SQL_LEN_DATA_AT_EXEC_OFFSET))) {
	setstat(s, -1, "invalid buffer", "HY003");
	return SQL_ERROR;
    }
    if (len && *len < 0 && *len > SQL_LEN_DATA_AT_EXEC_OFFSET &&
	*len != SQL_NTS && *len != SQL_NULL_DATA) {
	setstat(s, -1, "invalid length reference", "HY009");
	return SQL_ERROR;
    }
#if 0
    if (iotype != SQL_PARAM_INPUT)
	return SQL_ERROR;
#endif
    --pnum;
    if (s->bindparms) {
	if (pnum >= s->nbindparms) {
	    BINDPARM *newparms;
	    
	    newparms = xrealloc(s->bindparms,
				(pnum + 1) * sizeof (BINDPARM));
	    if (!newparms) {
outofmem:
		return nomem(s);
	    }
	    s->bindparms = newparms;
	    memset(&s->bindparms[s->nbindparms], 0,
		   (pnum - s->nbindparms) * sizeof (BINDPARM));
	    s->nbindparms = pnum + 1;
	}
    } else {
	int npar = max(10, pnum + 1);

	s->bindparms = xmalloc(npar * sizeof (BINDPARM));
	if (!s->bindparms) {
	    goto outofmem;
	}
	memset(s->bindparms, 0, npar * sizeof (BINDPARM));
	s->nbindparms = npar;
    }
    p = &s->bindparms[pnum];
    p->type = buftype; 
    p->stype = ptype; 
    p->max = buflen;
    p->inc = buflen;
    p->lenp = (int *) len;
    p->offs = 0;
    p->len = 0;
    if (p->lenp) {
	if (buftype == SQL_C_CHAR) {
	    if (*p->lenp == SQL_NTS) {
		p->len = p->max = buflen = strlen(data);
	    } else if (*p->lenp >= 0) {
		p->len = p->max = buflen = *p->lenp;
	    }
	}
    }
    if (p->lenp && *p->lenp <= SQL_LEN_DATA_AT_EXEC_OFFSET) {
	p->param = NULL;
	p->ind = data;
	p->need = 1;
    } else if (p->lenp && *p->lenp == SQL_NULL_DATA) {
	p->param = NULL;
	p->ind = NULL;
	p->need = 0;
    } else {
	if (buftype == SQL_C_CHAR) {
	    p->param = data;
	    p->ind = NULL;
	} else {
	    p->param = data;
	    p->ind = NULL;
	}
	p->need = 0;
    }
    p->param0 = p->param;
    return SQL_SUCCESS;
}

/**
 * Bind parameter on HSTMT.
 * @param stmt statement handle
 * @param pnum parameter number, starting at 1
 * @param iotype input/output type of parameter
 * @param buftype type of host variable
 * @param ptype
 * @param coldef
 * @param scale
 * @param data pointer to host variable
 * @param buflen length of host variable
 * @param len output length pointer
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLBindParameter(SQLHSTMT stmt, SQLUSMALLINT pnum, SQLSMALLINT iotype,
		 SQLSMALLINT buftype, SQLSMALLINT ptype, SQLUINTEGER coldef,
		 SQLSMALLINT scale,
		 SQLPOINTER data, SQLINTEGER buflen, SQLINTEGER *len)
{
    return drvbindparam(stmt, pnum, iotype, buftype, ptype, coldef,
			scale, data, buflen, len);
}

/**
 * Bind parameter on HSTMT.
 * @param stmt statement handle
 * @param pnum parameter number, starting at 1
 * @param vtype input/output type of parameter
 * @param ptype
 * @param lenprec
 * @param scale
 * @param val pointer to host variable
 * @param lenp output length pointer
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLBindParam(SQLHSTMT stmt, SQLUSMALLINT pnum, SQLSMALLINT vtype,
	     SQLSMALLINT ptype, SQLUINTEGER lenprec,
	     SQLSMALLINT scale, SQLPOINTER val,
	     SQLINTEGER *lenp)
{
    return drvbindparam(stmt, pnum, SQL_PARAM_INPUT, vtype, ptype,
			lenprec, scale, val, 0, lenp);
}

/**
 * Return number of parameters.
 * @param stmt statement handle
 * @param nparam output parameter count
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLNumParams(SQLHSTMT stmt, SQLSMALLINT *nparam)
{
    STMT *s;
    SQLSMALLINT dummy;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    if (!nparam) {
	nparam = &dummy;
    }
    *nparam = s->nparams;
    return SQL_SUCCESS;
}

/**
 * Retrieve next parameter for sending data to executing query.
 * @param stmt statement handle
 * @param p pointer to output parameter indicator
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLParamData(SQLHSTMT stmt, SQLPOINTER *p)
{
    STMT *s;
    int i;
    SQLPOINTER dummy;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    if (!p) {
	p = &dummy;
    }
    for (i = 0; i < s->nparams; i++) {
	if (s->bindparms[i].need) {
	    *p = (SQLPOINTER) s->bindparms[i].ind;
	    return SQL_NEED_DATA;
	}
    }
    return SQL_SUCCESS;
}    

/**
 * Return information about parameter.
 * @param stmt statement handle
 * @param pnum parameter number, starting at 1
 * @param dtype output type indicator
 * @param size output size indicator
 * @param decdigits output number of digits
 * @param nullable output NULL allowed indicator
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLDescribeParam(SQLHSTMT stmt, UWORD pnum, SWORD *dtype, UDWORD *size,
		 SWORD *decdigits, SWORD *nullable)
{
    STMT *s;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    --pnum;
    if (pnum >= s->nparams) {
	setstat(s, -1, "invalid parameter index",
		(*s->ov3) ? "HY000" : "S1000");
	return SQL_ERROR;
    }
    if (dtype) {
#ifdef SQL_LONGVARCHAR
	*dtype = SQL_LONGVARCHAR;
#else
	*dtype = SQL_VARCHAR;
#endif
    }
    if (size) {
#ifdef SQL_LONGVARCHAR
	*size = 65536;
#else
	*size = 255;
#endif
    }
    if (decdigits) {
	*decdigits = 0;
    }
    if (nullable) {
	*nullable = SQL_NULLABLE;
    }
    return SQL_SUCCESS;
}

/**
 * Set information on parameter.
 * @param stmt statement handle
 * @param par parameter number, starting at 1
 * @param type type of host variable
 * @param sqltype
 * @param coldef
 * @param scale
 * @param val pointer to host variable
 * @param len output length pointer
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLSetParam(SQLHSTMT stmt, SQLUSMALLINT par, SQLSMALLINT type,
	    SQLSMALLINT sqltype, SQLUINTEGER coldef,
	    SQLSMALLINT scale, SQLPOINTER val, SQLINTEGER *nval)
{
    return drvbindparam(stmt, par, SQL_PARAM_INPUT,
			type, sqltype, coldef, scale, val,
			SQL_SETPARAM_VALUE_MAX, nval);
}

/**
 * Function not implemented.
 */

SQLRETURN SQL_API
SQLParamOptions(SQLHSTMT stmt, UDWORD rows, UDWORD *rowp)
{
    return drvunimplstmt(stmt);
}

/**
 * Function not implemented.
 */

SQLRETURN SQL_API
SQLGetDescField(SQLHDESC handle, SQLSMALLINT recno,
		SQLSMALLINT fieldid, SQLPOINTER value,
		SQLINTEGER buflen, SQLINTEGER *strlen)
{
    return SQL_ERROR;
}

/**
 * Function not implemented.
 */

SQLRETURN SQL_API
SQLSetDescField(SQLHDESC handle, SQLSMALLINT recno,
		SQLSMALLINT fieldid, SQLPOINTER value,
		SQLINTEGER buflen)
{
    return SQL_ERROR;
}

/**
 * Function not implemented.
 */

SQLRETURN SQL_API
SQLGetDescRec(SQLHDESC handle, SQLSMALLINT recno,
	      SQLCHAR *name, SQLSMALLINT buflen,
	      SQLSMALLINT *strlen, SQLSMALLINT *type,
	      SQLSMALLINT *subtype, SQLINTEGER *len,
	      SQLSMALLINT *prec, SQLSMALLINT *scale,
	      SQLSMALLINT *nullable)
{
    return SQL_ERROR;
}

/**
 * Function not implemented.
 */

SQLRETURN SQL_API
SQLSetDescRec(SQLHDESC handle, SQLSMALLINT recno,
	      SQLSMALLINT type, SQLSMALLINT subtype,
	      SQLINTEGER len, SQLSMALLINT prec,
	      SQLSMALLINT scale, SQLPOINTER data,
	      SQLINTEGER *strlen, SQLINTEGER *indicator)
{
    return SQL_ERROR;
}

/**
 * Setup empty result set from constant column specification.
 * @param stmt statement handle
 * @param colspec column specification array
 * @param ncols number of columns
 * @result ODBC error code
 */

static SQLRETURN
mkresultset(HSTMT stmt, COL *colspec, int ncols)
{
    STMT *s;
    DBC *d;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    if (s->dbc == SQL_NULL_HDBC) {
noconn:
	return noconn(s);
    }
    d = (DBC *) s->dbc;
    if (!d->sqlite) {
	goto noconn;
    }
    s3stmt_end_if(s);
    freeresult(s, 0);
    s->ncols = ncols;
    s->cols = colspec;
    mkbindcols(s, s->ncols);
    s->nrows = 0;
    s->rowp = -1;
    return SQL_SUCCESS;
}

/**
 * Columns for result set of SQLTablePrivileges().
 */

static COL tablePrivSpec[] = {
    { "SYSTEM", "TABLEPRIV", "TABLE_QUALIFIER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "TABLEPRIV", "TABLE_OWNER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "TABLEPRIV", "TABLE_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "TABLEPRIV", "GRANTOR", SCOL_VARCHAR, 50 },
    { "SYSTEM", "TABLEPRIV", "GRANTEE", SCOL_VARCHAR, 50 },
    { "SYSTEM", "TABLEPRIV", "PRIVILEGE", SCOL_VARCHAR, 50 },
    { "SYSTEM", "TABLEPRIV", "IS_GRANTABLE", SCOL_VARCHAR, 50 }
};

/**
 * Retrieve privileges on tables and/or views.
 * @param stmt statement handle
 * @param catalog catalog name/pattern or NULL
 * @param catalogLen length of catalog name/pattern or SQL_NTS
 * @param schema schema name/pattern or NULL
 * @param schemaLen length of schema name/pattern or SQL_NTS
 * @param table table name/pattern or NULL
 * @param tableLen length of table name/pattern or SQL_NTS
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLTablePrivileges(SQLHSTMT stmt,
		   SQLCHAR *catalog, SQLSMALLINT catalogLen,
		   SQLCHAR *schema, SQLSMALLINT schemaLen,
		   SQLCHAR *table, SQLSMALLINT tableLen)
{
    return mkresultset(stmt, tablePrivSpec, array_size(tablePrivSpec));
}

/**
 * Columns for result set of SQLColumnPrivileges().
 */

static COL colPrivSpec[] = {
    { "SYSTEM", "COLPRIV", "TABLE_QUALIFIER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "COLPRIV", "TABLE_OWNER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "COLPRIV", "TABLE_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "COLPRIV", "GRANTOR", SCOL_VARCHAR, 50 },
    { "SYSTEM", "COLPRIV", "GRANTEE", SCOL_VARCHAR, 50 },
    { "SYSTEM", "COLPRIV", "PRIVILEGE", SCOL_VARCHAR, 50 },
    { "SYSTEM", "COLPRIV", "IS_GRANTABLE", SCOL_VARCHAR, 50 }
};

/**
 * Retrieve privileges on columns.
 * @param stmt statement handle
 * @param catalog catalog name/pattern or NULL
 * @param catalogLen length of catalog name/pattern or SQL_NTS
 * @param schema schema name/pattern or NULL
 * @param schemaLen length of schema name/pattern or SQL_NTS
 * @param table table name/pattern or NULL
 * @param tableLen length of table name/pattern or SQL_NTS
 * @param column column name or NULL
 * @param columnLen length of column name or SQL_NTS
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLColumnPrivileges(SQLHSTMT stmt,
		    SQLCHAR *catalog, SQLSMALLINT catalogLen,
		    SQLCHAR *schema, SQLSMALLINT schemaLen,
		    SQLCHAR *table, SQLSMALLINT tableLen,
		    SQLCHAR *column, SQLSMALLINT columnLen)
{
    return mkresultset(stmt, colPrivSpec, array_size(colPrivSpec));
}

/**
 * Columns for result set of SQLPrimaryKeys().
 */

static COL pkeySpec[] = {
    { "SYSTEM", "PRIMARYKEY", "TABLE_QUALIFIER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "PRIMARYKEY", "TABLE_OWNER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "PRIMARYKEY", "TABLE_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "PRIMARYKEY", "COLUMN_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "PRIMARYKEY", "KEY_SEQ", SQL_SMALLINT, 50 },
    { "SYSTEM", "PRIMARYKEY", "PK_NAME", SCOL_VARCHAR, 50 }
};

/**
 * Internal retrieve information about indexed columns.
 * @param stmt statement handle
 * @param cat catalog name/pattern or NULL
 * @param catLen length of catalog name/pattern or SQL_NTS
 * @param schema schema name/pattern or NULL
 * @param schemaLen length of schema name/pattern or SQL_NTS
 * @param table table name/pattern or NULL
 * @param tableLen length of table name/pattern or SQL_NTS
 * @result ODBC error code
 */

static SQLRETURN
drvprimarykeys(SQLHSTMT stmt,
	       SQLCHAR *cat, SQLSMALLINT catLen,
	       SQLCHAR *schema, SQLSMALLINT schemaLen,
	       SQLCHAR *table, SQLSMALLINT tableLen)
{
    STMT *s;
    DBC *d;
    SQLRETURN sret;
    int i, size, ret, nrows, ncols, offs, namec, uniquec;
    char **rowp, *errp = NULL, *sql, tname[512];

    sret = mkresultset(stmt, pkeySpec, array_size(pkeySpec));
    if (sret != SQL_SUCCESS) {
	return sret;
    }
    s = (STMT *) stmt;
    d = (DBC *) s->dbc;
    if (!table || table[0] == '\0' || table[0] == '%') {
	setstat(s, -1, "need table name", (*s->ov3) ? "HY000" : "S1000");
	return SQL_ERROR;
    }
    if (tableLen == SQL_NTS) {
	size = sizeof (tname) - 1;
    } else {
	size = min(sizeof (tname) - 1, tableLen);
    }
    strncpy(tname, table, size);
    tname[size] = '\0';
    sql = sqlite3_mprintf("PRAGMA index_list('%q')", tname);
    if (!sql) {
	return nomem(s);
    }
    ret = sqlite3_get_table(d->sqlite, sql, &rowp, &nrows, &ncols, &errp);
    sqlite3_free(sql);
    if (ret != SQLITE_OK) {
	setstat(s, ret, "%s (%d)", (*s->ov3) ? "HY000" : "S1000",
		errp ? errp : "unknown error", ret);
	if (errp) {
	    sqlite3_free(errp);
	    errp = NULL;
	}
	return SQL_ERROR;
    }
    if (errp) {
	sqlite3_free(errp);
	errp = NULL;
    }
    if (ncols * nrows <= 0) {
nodata:
	sqlite3_free_table(rowp);
	/* try table_info for integer primary keys */
	ret = SQLITE_ERROR;
	sql = sqlite3_mprintf("PRAGMA table_info('%q')", tname);
	if (sql) {
	    ret = sqlite3_get_table(d->sqlite, sql, &rowp,
				    &nrows, &ncols, NULL);
	    sqlite3_free(sql);
	}
	if (ret == SQLITE_OK) {
	    int typec, roffs;

	    namec = findcol(rowp, ncols, "name");
	    uniquec = findcol(rowp, ncols, "pk");
	    typec = findcol(rowp, ncols, "type");
	    if (namec < 0 || uniquec < 0 || typec < 0) {
		goto nodata2;
	    }
	    for (i = 1; i <= nrows; i++) {
		if (*rowp[i * ncols + uniquec] != '0' &&
		    strlen(rowp[i * ncols + typec]) == 7 &&
		    strncasecmp(rowp[i * ncols + typec], "integer", 7) == 0) {
		    break;
		}
	    }
	    if (i > nrows) {
		goto nodata2;
	    }
	    size = (1 + 1) * array_size(pkeySpec);
	    s->rows = xmalloc((size + 1) * sizeof (char *));
	    if (!s->rows) {
		s->nrows = 0;
		return nomem(s);
	    }
	    s->rows[0] = (char *) size;
	    s->rows += 1;
	    memset(s->rows, 0, sizeof (char *) * size);
	    s->rowfree = freerows;
	    s->nrows = 1;
	    roffs = s->ncols;
	    s->rows[roffs + 0] = xstrdup("");
	    s->rows[roffs + 1] = xstrdup("");
	    s->rows[roffs + 2] = xstrdup(tname);
	    s->rows[roffs + 3] = xstrdup(rowp[i * ncols + namec]);
	    s->rows[roffs + 4] = xstrdup("1");
nodata2:
	    sqlite3_free_table(rowp);
	}
	return SQL_SUCCESS;
    }
    size = 0;
    namec = findcol(rowp, ncols, "name");
    uniquec = findcol(rowp, ncols, "unique");
    if (namec < 0 || uniquec < 0) {
	goto nodata;
    }
    for (i = 1; i <= nrows; i++) {
	int nnrows, nncols;
	char **rowpp;

	if (*rowp[i * ncols + uniquec] != '0') {
	    ret = SQLITE_ERROR;
	    sql = sqlite3_mprintf("PRAGMA index_info('%q')",
				  rowp[i * ncols + namec]);
	    if (sql) {
		ret = sqlite3_get_table(d->sqlite, sql, &rowpp,
					&nnrows, &nncols, NULL);
		sqlite3_free(sql);
	    }
	    if (ret == SQLITE_OK) {
		size += nnrows;
		sqlite3_free_table(rowpp);
	    }
	}
    }
    if (size == 0) {
	goto nodata;
    }
    s->nrows = size;
    size = (size + 1) * array_size(pkeySpec);
    s->rows = xmalloc((size + 1) * sizeof (char *));
    if (!s->rows) {
	s->nrows = 0;
	return nomem(s);
    }
    s->rows[0] = (char *) size;
    s->rows += 1;
    memset(s->rows, 0, sizeof (char *) * size);
    s->rowfree = freerows;
    offs = 0;
    for (i = 1; i <= nrows; i++) {
	int nnrows, nncols;
	char **rowpp;

	if (*rowp[i * ncols + uniquec] != '0') {
	    int k;

	    ret = SQLITE_ERROR;
	    sql = sqlite3_mprintf("PRAGMA index_info('%q')",
				  rowp[i * ncols + namec]);
	    if (sql) {
		ret = sqlite3_get_table(d->sqlite, sql, &rowpp,
					&nnrows, &nncols, NULL);
		sqlite3_free(sql);
	    }
	    if (ret != SQLITE_OK) {
		continue;
	    }
	    for (k = 0; nnrows && k < nncols; k++) {
		if (strcmp(rowpp[k], "name") == 0) {
		    int m;

		    for (m = 1; m <= nnrows; m++) {
			int roffs = (offs + m) * s->ncols;

			s->rows[roffs + 0] = xstrdup("");
			s->rows[roffs + 1] = xstrdup("");
			s->rows[roffs + 2] = xstrdup(tname);
			s->rows[roffs + 3] = xstrdup(rowpp[m * nncols + k]);
			s->rows[roffs + 5] = xstrdup(rowp[i * ncols + namec]);
		    }
		} else if (strcmp(rowpp[k], "seqno") == 0) {
		    int m;

		    for (m = 1; m <= nnrows; m++) {
			int roffs = (offs + m) * s->ncols;
			int pos = m - 1;
			char buf[32];

			sscanf(rowpp[m * nncols + k], "%d", &pos);
			sprintf(buf, "%d", pos + 1);
			s->rows[roffs + 4] = xstrdup(buf);
		    }
		}
	    }
	    offs += nnrows;
	    sqlite3_free_table(rowpp);
	}
    }
    sqlite3_free_table(rowp);
    return SQL_SUCCESS;
}

/**
 * Retrieve information about indexed columns.
 * @param stmt statement handle
 * @param cat catalog name/pattern or NULL
 * @param catLen length of catalog name/pattern or SQL_NTS
 * @param schema schema name/pattern or NULL
 * @param schemaLen length of schema name/pattern or SQL_NTS
 * @param table table name/pattern or NULL
 * @param tableLen length of table name/pattern or SQL_NTS
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLPrimaryKeys(SQLHSTMT stmt,
	       SQLCHAR *cat, SQLSMALLINT catLen,
	       SQLCHAR *schema, SQLSMALLINT schemaLen,
	       SQLCHAR *table, SQLSMALLINT tableLen)
{
    return drvprimarykeys(stmt, cat, catLen, schema, schemaLen,
			  table, tableLen);
}

/**
 * Columns for result set of SQLSpecialColumns().
 */

static COL scolSpec[] = {
    { "SYSTEM", "COLUMN", "SCOPE", SQL_SMALLINT, 1 },
    { "SYSTEM", "COLUMN", "COLUMN_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "COLUMN", "DATA_TYPE", SQL_SMALLINT, 50 },
    { "SYSTEM", "COLUMN", "TYPE_NAME", SCOL_VARCHAR, 50 },
    { "SYSTEM", "COLUMN", "PRECISION", SQL_INTEGER, 50 },
    { "SYSTEM", "COLUMN", "LENGTH", SQL_INTEGER, 50 },
    { "SYSTEM", "COLUMN", "DECIMAL_DIGITS", SQL_INTEGER, 50 },
    { "SYSTEM", "COLUMN", "PSEUDO_COLUMN", SQL_SMALLINT, 1 },
    { "SYSTEM", "COLUMN", "NULLABLE", SQL_SMALLINT, 1 }
};

/**
 * Internal retrieve information about indexed columns.
 * @param stmt statement handle
 * @param id type of information, e.g. best row id
 * @param cat catalog name/pattern or NULL
 * @param catLen length of catalog name/pattern or SQL_NTS
 * @param schema schema name/pattern or NULL
 * @param schemaLen length of schema name/pattern or SQL_NTS
 * @param table table name/pattern or NULL
 * @param tableLen length of table name/pattern or SQL_NTS
 * @param scope
 * @param nullable
 * @result ODBC error code
 */

static SQLRETURN
drvspecialcolumns(SQLHSTMT stmt, SQLUSMALLINT id,
		  SQLCHAR *cat, SQLSMALLINT catLen,
		  SQLCHAR *schema, SQLSMALLINT schemaLen,
		  SQLCHAR *table, SQLSMALLINT tableLen,
		  SQLUSMALLINT scope, SQLUSMALLINT nullable)
{
    STMT *s;
    DBC *d;
    SQLRETURN sret;
    int i, size, ret, nrows, ncols, nnnrows, nnncols, offs;
    int namec = -1, uniquec = -1, namecc = -1, typecc = -1;
    int notnullcc = -1, mkrowid = 0;
    char *errp = NULL, *sql, tname[512];
    char **rowp = NULL, **rowppp = NULL;

    sret = mkresultset(stmt, scolSpec, array_size(scolSpec));
    if (sret != SQL_SUCCESS) {
	return sret;
    }
    s = (STMT *) stmt;
    d = (DBC *) s->dbc;
    if (!table || table[0] == '\0' || table[0] == '%') {
	setstat(s, -1, "need table name", (*s->ov3) ? "HY000" : "S1000");
	return SQL_ERROR;
    }
    if (tableLen == SQL_NTS) {
	size = sizeof (tname) - 1;
    } else {
	size = min(sizeof (tname) - 1, tableLen);
    }
    strncpy(tname, table, size);
    tname[size] = '\0';
    if (id != SQL_BEST_ROWID) {
	return SQL_SUCCESS;
    }
    sql = sqlite3_mprintf("PRAGMA index_list('%q')", tname);
    if (!sql) {
	return nomem(s);
    }
    ret = sqlite3_get_table(d->sqlite, sql, &rowp, &nrows, &ncols, &errp);
    sqlite3_free(sql);
    if (ret != SQLITE_OK) {
doerr:
	setstat(s, ret, "%s (%d)", (*s->ov3) ? "HY000" : "S1000",
		errp ? errp : "unknown error", ret);
	if (errp) {
	    sqlite3_free(errp);
	    errp = NULL;
	}
	return SQL_ERROR;	
    }
    if (errp) {
	sqlite3_free(errp);
	errp = NULL;
    }
    size = 0; /* number result rows */
    if (ncols * nrows <= 0) {
	goto nodata_but_rowid;
    }
    sql = sqlite3_mprintf("PRAGMA table_info('%q')", tname);
    if (!sql) {
	return nomem(s);
    }
    ret = sqlite3_get_table(d->sqlite, sql, &rowppp, &nnnrows, &nnncols,
			    &errp);
    sqlite3_free(sql);
    if (ret != SQLITE_OK) {
	sqlite3_free_table(rowp);
	goto doerr;
    }
    if (errp) {
	sqlite3_free(errp);
	errp = NULL;
    }
    namec = findcol(rowp, ncols, "name");
    uniquec = findcol(rowp, ncols, "unique");
    if (namec < 0 || uniquec < 0) {
	goto nodata_but_rowid;
    }
    namecc = findcol(rowppp, nnncols, "name");
    typecc = findcol(rowppp, nnncols, "type");
    notnullcc = findcol(rowppp, nnncols, "notnull");
    for (i = 1; i <= nrows; i++) {
	int nnrows, nncols;
	char **rowpp = NULL;

	if (*rowp[i * ncols + uniquec] != '0') {
	    ret = SQLITE_ERROR;
	    sql = sqlite3_mprintf("PRAGMA index_info('%q')",
				  rowp[i * ncols + namec]);
	    if (sql) {
		ret = sqlite3_get_table(d->sqlite, sql, &rowpp,
					&nnrows, &nncols, NULL);
		sqlite3_free(sql);
	    }
	    if (ret == SQLITE_OK) {
		size += nnrows;
		sqlite3_free_table(rowpp);
	    }
	}
    }
nodata_but_rowid:
    if (size == 0) {
	size = 1;
	mkrowid = 1;
    }
    s->nrows = size;
    size = (size + 1) * array_size(scolSpec);
    s->rows = xmalloc((size + 1) * sizeof (char *));
    if (!s->rows) {
	s->nrows = 0;
	sqlite3_free_table(rowp);
	sqlite3_free_table(rowppp);
	return nomem(s);
    }
    s->rows[0] = (char *) size;
    s->rows += 1;
    memset(s->rows, 0, sizeof (char *) * size);
    s->rowfree = freerows;
    if (mkrowid) {
	s->nrows = 0;
	goto mkrowid;
    }
    offs = 0;
    for (i = 1; i <= nrows; i++) {
	int nnrows, nncols;
	char **rowpp = NULL;

	if (*rowp[i * ncols + uniquec] != '0') {
	    int k;

	    ret = SQLITE_ERROR;
	    sql = sqlite3_mprintf("PRAGMA index_info('%q')",
				  rowp[i * ncols + namec]);
	    if (sql) {
		ret = sqlite3_get_table(d->sqlite, sql, &rowpp,
					&nnrows, &nncols, NULL);
		sqlite3_free(sql);
	    }
	    if (ret != SQLITE_OK) {
		continue;
	    }
	    for (k = 0; nnrows && k < nncols; k++) {
		if (strcmp(rowpp[k], "name") == 0) {
		    int m;

		    for (m = 1; m <= nnrows; m++) {
			int roffs = (offs + m) * s->ncols;

			s->rows[roffs + 0] =
			    xstrdup(stringify(SQL_SCOPE_SESSION));
			s->rows[roffs + 1] = xstrdup(rowpp[m * nncols + k]);
			s->rows[roffs + 4] = xstrdup("0");
			s->rows[roffs + 7] =
			    xstrdup(stringify(SQL_PC_NOT_PSEUDO));
			if (namecc >= 0 && typecc >= 0) {
			    int ii;

			    for (ii = 1; ii <= nnnrows; ii++) {
				if (strcmp(rowppp[ii * nnncols + namecc],
					   rowpp[m * nncols + k]) == 0) {
				    char *typen = rowppp[ii * nnncols + typecc];
				    int sqltype, mm, dd, isnullable = 0;
				    char buf[32];
					
				    s->rows[roffs + 3] = xstrdup(typen);
				    sqltype = mapsqltype(typen, NULL, *s->ov3);
				    getmd(typen, sqltype, &mm, &dd);
#ifdef SQL_LONGVARCHAR
				    if (sqltype == SQL_VARCHAR && mm > 255) {
					sqltype = SQL_LONGVARCHAR;
				    }
#endif
				    if (sqltype == SQL_VARBINARY && mm > 255) {
					sqltype = SQL_LONGVARBINARY;
				    }
				    sprintf(buf, "%d", sqltype);
				    s->rows[roffs + 2] = xstrdup(buf);
				    sprintf(buf, "%d", mm);
				    s->rows[roffs + 5] = xstrdup(buf);
				    sprintf(buf, "%d", dd);
				    s->rows[roffs + 6] = xstrdup(buf);
				    if (notnullcc >= 0) {
					char *inp =
					   rowppp[ii * nnncols + notnullcc];

					isnullable = inp[0] != '0';
				    }
				    sprintf(buf, "%d", isnullable);
				    s->rows[roffs + 8] = xstrdup(buf);
				}
			    }
			}
		    }
		}
	    }
	    offs += nnrows;
	    sqlite3_free_table(rowpp);
	}
    }
    if (nullable == SQL_NO_NULLS) {
	for (i = 1; i < s->nrows; i++) {
	    if (s->rows[i * s->ncols + 8][0] == '0') {
		int m, i1 = i + 1;

		for (m = 0; m < s->ncols; m++) {
		    freep(&s->rows[i * s->ncols + m]);
		}
		size = s->ncols * sizeof (char *) * (s->nrows - i1);
		if (size > 0) {
		    memmove(s->rows + i * s->ncols,
			    s->rows + i1 * s->ncols,
			    size);
		    memset(s->rows + s->nrows * s->ncols, 0,
			   s->ncols * sizeof (char *));
		}
		s->nrows--;
		--i;
	    }
	}
    }
mkrowid:
    sqlite3_free_table(rowp);
    sqlite3_free_table(rowppp);
    if (s->nrows == 0) {
	s->rows[s->ncols + 0] = xstrdup(stringify(SQL_SCOPE_SESSION));
	s->rows[s->ncols + 1] = xstrdup("_ROWID_");
	s->rows[s->ncols + 2] = xstrdup(stringify(SQL_INTEGER));
	s->rows[s->ncols + 3] = xstrdup("integer");
	s->rows[s->ncols + 4] = xstrdup("0");
	s->rows[s->ncols + 5] = xstrdup("10");
	s->rows[s->ncols + 6] = xstrdup("9");
	s->rows[s->ncols + 7] = xstrdup(stringify(SQL_PC_PSEUDO));
	s->rows[s->ncols + 8] = xstrdup(stringify(SQL_FALSE));
	s->nrows = 1;
    }
    return SQL_SUCCESS;
}

/**
 * Retrieve information about indexed columns.
 * @param stmt statement handle
 * @param id type of information, e.g. best row id
 * @param cat catalog name/pattern or NULL
 * @param catLen length of catalog name/pattern or SQL_NTS
 * @param schema schema name/pattern or NULL
 * @param schemaLen length of schema name/pattern or SQL_NTS
 * @param table table name/pattern or NULL
 * @param tableLen length of table name/pattern or SQL_NTS
 * @param scope
 * @param nullable
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLSpecialColumns(SQLHSTMT stmt, SQLUSMALLINT id,
		  SQLCHAR *cat, SQLSMALLINT catLen,
		  SQLCHAR *schema, SQLSMALLINT schemaLen,
		  SQLCHAR *table, SQLSMALLINT tableLen,
		  SQLUSMALLINT scope, SQLUSMALLINT nullable)
{
    return drvspecialcolumns(stmt, id, cat, catLen, schema, schemaLen,
			     table, tableLen, scope, nullable);
}

/**
 * Columns for result set of SQLForeignKeys().
 */

static COL fkeySpec[] = {
    { "SYSTEM", "FOREIGNKEY", "PKTABLE_QUALIFIER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "FOREIGNKEY", "PKTABLE_OWNER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "FOREIGNKEY", "PKTABLE_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "FOREIGNKEY", "PKCOLUMN_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "FOREIGNKEY", "FKTABLE_QUALIFIER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "FOREIGNKEY", "FKTABLE_OWNER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "FOREIGNKEY", "FKTABLE_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "FOREIGNKEY", "FKCOLUMN_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "FOREIGNKEY", "KEY_SEQ", SQL_SMALLINT, 5 },
    { "SYSTEM", "FOREIGNKEY", "UPDATE_RULE", SQL_SMALLINT, 5 },
    { "SYSTEM", "FOREIGNKEY", "DELETE_RULE", SQL_SMALLINT, 5 },
    { "SYSTEM", "FOREIGNKEY", "FK_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "FOREIGNKEY", "PK_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "FOREIGNKEY", "DEFERRABILITY", SQL_SMALLINT, 5 }
};

/**
 * Internal retrieve information about primary/foreign keys.
 * @param stmt statement handle
 * @param PKcatalog primary key catalog name/pattern or NULL
 * @param PKcatalogLen length of PKcatalog or SQL_NTS
 * @param PKschema primary key schema name/pattern or NULL
 * @param PKschemaLen length of PKschema or SQL_NTS
 * @param PKtable primary key table name/pattern or NULL
 * @param PKtableLen length of PKtable or SQL_NTS
 * @param FKcatalog foreign key catalog name/pattern or NULL
 * @param FKcatalogLen length of FKcatalog or SQL_NTS
 * @param FKschema foreign key schema name/pattern or NULL
 * @param FKschemaLen length of FKschema or SQL_NTS
 * @param FKtable foreign key table name/pattern or NULL
 * @param FKtableLen length of FKtable or SQL_NTS
 * @result ODBC error code
 */

static SQLRETURN SQL_API
drvforeignkeys(SQLHSTMT stmt,
	       SQLCHAR *PKcatalog, SQLSMALLINT PKcatalogLen,
	       SQLCHAR *PKschema, SQLSMALLINT PKschemaLen,
	       SQLCHAR *PKtable, SQLSMALLINT PKtableLen,
	       SQLCHAR *FKcatalog, SQLSMALLINT FKcatalogLen,
	       SQLCHAR *FKschema, SQLSMALLINT FKschemaLen,
	       SQLCHAR *FKtable, SQLSMALLINT FKtableLen)
{
    STMT *s;
    DBC *d;
    SQLRETURN sret;
    int i, size, ret, nrows, ncols, offs, namec, seqc, fromc, toc;
    char **rowp, *errp = NULL, *sql, pname[512], fname[512];

    sret = mkresultset(stmt, fkeySpec, array_size(fkeySpec));
    if (sret != SQL_SUCCESS) {
	return sret;
    }
    s = (STMT *) stmt;
    d = (DBC *) s->dbc;
    if ((!PKtable || PKtable[0] == '\0' || PKtable[0] == '%') &&
	(!FKtable || FKtable[0] == '\0' || FKtable[0] == '%')) {
	setstat(s, -1, "need table name", (*s->ov3) ? "HY000" : "S1000");
	return SQL_ERROR;
    }
    size = 0;
    if (PKtable) {
	if (PKtableLen == SQL_NTS) {
	    size = sizeof (pname) - 1;
	} else {
	    size = min(sizeof (pname) - 1, PKtableLen);
	}
	strncpy(pname, PKtable, size);
    }
    pname[size] = '\0';
    size = 0;
    if (FKtable) {

	if (FKtableLen == SQL_NTS) {
	    size = sizeof (fname) - 1;
	} else {
	    size = min(sizeof (fname) - 1, FKtableLen);
	}
	strncpy(fname, FKtable, size);
    }
    fname[size] = '\0';
    if (fname[0] != '\0') {
	int plen;

	ret = SQLITE_ERROR;
	sql = sqlite3_mprintf("PRAGMA foreign_key_list('%q')", fname);
	if (sql) {
	    ret = sqlite3_get_table(d->sqlite, sql, &rowp,
				    &nrows, &ncols, &errp);
	    sqlite3_free(sql);
	}
	if (ret != SQLITE_OK) {
	    setstat(s, ret, "%s (%d)", (*s->ov3) ? "HY000" : "S1000",
		    errp ? errp : "unknown error", ret);
	    if (errp) {
		sqlite3_free(errp);
		errp = NULL;
	    }
	    return SQL_ERROR;
	}
	if (errp) {
	    sqlite3_free(errp);
	    errp = NULL;
	}
	if (ncols * nrows <= 0) {
nodata:
	    sqlite3_free_table(rowp);
	    return SQL_SUCCESS;
	}
	size = 0;
	namec = findcol(rowp, ncols, "table");
	seqc = findcol(rowp, ncols, "seq");
	fromc = findcol(rowp, ncols, "from");
	toc = findcol(rowp, ncols, "to");
	if (namec < 0 || seqc < 0 || fromc < 0 || toc < 0) {
	    goto nodata;
	}
	plen = strlen(pname);
	for (i = 1; i <= nrows; i++) {
	    char *ptab = rowp[i * ncols + namec];

	    if (plen && ptab) {
		int len = strlen(ptab);

		if (plen != len || strncasecmp(pname, ptab, plen) != 0) {
		    continue;
		}
	    }
	    size++;
	}
	if (size == 0) {
	    goto nodata;
	}
	s->nrows = size;
	size = (size + 1) * array_size(fkeySpec);
	s->rows = xmalloc((size + 1) * sizeof (char *));
	if (!s->rows) {
	    s->nrows = 0;
	    return nomem(s);
	}
	s->rows[0] = (char *) size;
	s->rows += 1;
	memset(s->rows, 0, sizeof (char *) * size);
	s->rowfree = freerows;
	offs = 0;
	for (i = 1; i <= nrows; i++) {
	    int pos = 0, roffs = (offs + 1) * s->ncols;
	    char *ptab = rowp[i * ncols + namec];
	    char buf[32];

	    if (plen && ptab) {
		int len = strlen(ptab);

		if (plen != len || strncasecmp(pname, ptab, plen) != 0) {
		    continue;
		}
	    }
	    s->rows[roffs + 0] = xstrdup("");
	    s->rows[roffs + 1] = xstrdup("");
	    s->rows[roffs + 2] = xstrdup(ptab);
	    s->rows[roffs + 3] = xstrdup(rowp[i * ncols + toc]);
	    s->rows[roffs + 4] = xstrdup("");
	    s->rows[roffs + 5] = xstrdup("");
	    s->rows[roffs + 6] = xstrdup(fname);
	    s->rows[roffs + 7] = xstrdup(rowp[i * ncols + fromc]);
	    sscanf(rowp[i * ncols + seqc], "%d", &pos);
	    sprintf(buf, "%d", pos + 1);
	    s->rows[roffs + 8] = xstrdup(buf);
	    s->rows[roffs + 9] = xstrdup(stringify(SQL_NO_ACTION));
	    s->rows[roffs + 10] = xstrdup(stringify(SQL_NO_ACTION));
	    s->rows[roffs + 11] = NULL;
	    s->rows[roffs + 12] = NULL;
	    s->rows[roffs + 13] = xstrdup(stringify(SQL_NOT_DEFERRABLE));
	    offs++;
	}
	sqlite3_free_table(rowp);
    } else {
	int nnrows, nncols, plen = strlen(pname);
	char **rowpp;

	ret = sqlite3_get_table(d->sqlite, "select name from sqlite_master "
				"where type='table'", &rowp,
				&nrows, &ncols, &errp);
	if (ret != SQLITE_OK) {
	    setstat(s, ret, "%s (%d)", (*s->ov3) ? "HY000" : "S1000",
		    errp ? errp : "unknown error", ret);
	    if (errp) {
		sqlite3_free(errp);
		errp = NULL;
	    }
	    return SQL_ERROR;
	}
	if (errp) {
	    sqlite3_free(errp);
	    errp = NULL;
	}
	if (ncols * nrows <= 0) {
	    goto nodata;
	}
	size = 0;
	for (i = 1; i <= nrows; i++) {
	    int k, len;

	    if (!rowp[i]) {
		continue;
	    }
	    len = strlen(rowp[i]);
	    if (len == plen && strncasecmp(pname, rowp[i], plen) == 0) {
		continue;
	    }
	    rowpp = NULL;
	    ret = SQLITE_ERROR;
	    sql = sqlite3_mprintf("PRAGMA foreign_key_list('%q')", rowp[i]);
	    if (sql) {
		ret = sqlite3_get_table(d->sqlite, sql, &rowpp,
				      &nnrows, &nncols, NULL);
		sqlite3_free(sql);
	    }
	    if (ret != SQLITE_OK || nncols * nnrows <= 0) {
		sqlite3_free_table(rowpp);
		continue;
	    }
	    namec = findcol(rowpp, nncols, "table");
	    seqc = findcol(rowpp, nncols, "seq");
	    fromc = findcol(rowpp, nncols, "from");
	    toc = findcol(rowpp, nncols, "to");
	    if (namec < 0 || seqc < 0 || fromc < 0 || toc < 0) {
		sqlite3_free_table(rowpp);
		continue;
	    }
	    for (k = 1; k <= nnrows; k++) {
		char *ptab = rowpp[k * nncols + namec];

		if (plen && ptab) {
		    len = strlen(ptab);
		    if (len != plen || strncasecmp(pname, ptab, plen) != 0) {
			continue;
		    }
		}
		size++;
	    }
	    sqlite3_free_table(rowpp);
	}
	if (size == 0) {
	    goto nodata;
	}
	s->nrows = size;
	size = (size + 1) * array_size(fkeySpec);
	s->rows = xmalloc((size + 1) * sizeof (char *));
	if (!s->rows) {
	    s->nrows = 0;
	    return nomem(s);
	}
	s->rows[0] = (char *) size;
	s->rows += 1;
	memset(s->rows, 0, sizeof (char *) * size);
	s->rowfree = freerows;
	offs = 0;
	for (i = 1; i <= nrows; i++) {
	    int k, len;

	    if (!rowp[i]) {
		continue;
	    }
	    len = strlen(rowp[i]);
	    if (len == plen && strncasecmp(pname, rowp[i], plen) == 0) {
		continue;
	    }
	    rowpp = NULL;
	    ret = SQLITE_ERROR;
	    sql = sqlite3_mprintf("PRAGMA foreign_key_list('%q')", rowp[i]);
	    if (sql) {
		ret = sqlite3_get_table(d->sqlite, sql, &rowpp,
					&nnrows, &nncols, NULL);
		sqlite3_free(sql);
	    }
	    if (ret != SQLITE_OK || nncols * nnrows <= 0) {
		sqlite3_free_table(rowpp);
		continue;
	    }
	    namec = findcol(rowpp, nncols, "table");
	    seqc = findcol(rowpp, nncols, "seq");
	    fromc = findcol(rowpp, nncols, "from");
	    toc = findcol(rowpp, nncols, "to");
	    if (namec < 0 || seqc < 0 || fromc < 0 || toc < 0) {
		sqlite3_free_table(rowpp);
		continue;
	    }
	    for (k = 1; k <= nnrows; k++) {
		int pos = 0, roffs = (offs + 1) * s->ncols;
		char *ptab = rowpp[k * nncols + namec];
		char buf[32];

		if (plen && ptab) {
		    len = strlen(ptab);
		    if (len != plen || strncasecmp(pname, ptab, plen) != 0) {
			continue;
		    }
		}
		s->rows[roffs + 0] = xstrdup("");
		s->rows[roffs + 1] = xstrdup("");
		s->rows[roffs + 2] = xstrdup(ptab);
		s->rows[roffs + 3] = xstrdup(rowpp[k * nncols + toc]);
		s->rows[roffs + 4] = xstrdup("");
		s->rows[roffs + 5] = xstrdup("");
		s->rows[roffs + 6] = xstrdup(rowp[i]);
		s->rows[roffs + 7] = xstrdup(rowpp[k * nncols + fromc]);
		sscanf(rowpp[k * nncols + seqc], "%d", &pos);
		sprintf(buf, "%d", pos + 1);
		s->rows[roffs + 8] = xstrdup(buf);
		s->rows[roffs + 9] = xstrdup(stringify(SQL_NO_ACTION));
		s->rows[roffs + 10] = xstrdup(stringify(SQL_NO_ACTION));
		s->rows[roffs + 11] = NULL;
		s->rows[roffs + 12] = NULL;
		s->rows[roffs + 13] = xstrdup(stringify(SQL_NOT_DEFERRABLE));
		offs++;
	    }
	    sqlite3_free_table(rowpp);
	}
	sqlite3_free_table(rowp);
    }
    return SQL_SUCCESS;
}

/**
 * Retrieve information about primary/foreign keys.
 * @param stmt statement handle
 * @param PKcatalog primary key catalog name/pattern or NULL
 * @param PKcatalogLen length of PKcatalog or SQL_NTS
 * @param PKschema primary key schema name/pattern or NULL
 * @param PKschemaLen length of PKschema or SQL_NTS
 * @param PKtable primary key table name/pattern or NULL
 * @param PKtableLen length of PKtable or SQL_NTS
 * @param FKcatalog foreign key catalog name/pattern or NULL
 * @param FKcatalogLen length of FKcatalog or SQL_NTS
 * @param FKschema foreign key schema name/pattern or NULL
 * @param FKschemaLen length of FKschema or SQL_NTS
 * @param FKtable foreign key table name/pattern or NULL
 * @param FKtableLen length of FKtable or SQL_NTS
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLForeignKeys(SQLHSTMT stmt,
	       SQLCHAR *PKcatalog, SQLSMALLINT PKcatalogLen,
	       SQLCHAR *PKschema, SQLSMALLINT PKschemaLen,
	       SQLCHAR *PKtable, SQLSMALLINT PKtableLen,
	       SQLCHAR *FKcatalog, SQLSMALLINT FKcatalogLen,
	       SQLCHAR *FKschema, SQLSMALLINT FKschemaLen,
	       SQLCHAR *FKtable, SQLSMALLINT FKtableLen)
{
    return drvforeignkeys(stmt,
			  PKcatalog, PKcatalogLen,
			  PKschema, PKschemaLen, PKtable, PKtableLen,
			  FKcatalog, FKcatalogLen,
			  FKschema, FKschemaLen,
			  FKtable, FKtableLen);
}

/**
 * Internal commit or rollback transaction.
 * @param d database connection pointer
 * @param comptype type of transaction's end, SQL_COMMIT or SQL_ROLLBACK
 * @result ODBC error code
 */

static SQLRETURN
endtran(DBC *d, SQLSMALLINT comptype)
{
    int fail = 0, ret, busy_count = 0;
    char *sql, *errp = NULL;

    if (!d->sqlite) {
	setstatd(d, -1, "not connected", (*d->ov3) ? "HY000" : "S1000");
	return SQL_ERROR;
    }
    if (d->autocommit || !d->intrans) {
	return SQL_SUCCESS;
    }
    switch (comptype) {
    case SQL_COMMIT:
	sql = "COMMIT TRANSACTION";
	goto doit;
    case SQL_ROLLBACK:
    rollback:
	sql = "ROLLBACK TRANSACTION";
    doit:
	ret = sqlite3_exec(d->sqlite, sql, NULL, NULL, &errp);
	if (ret == SQLITE_BUSY && !fail && comptype == SQL_COMMIT) {
	    if (busy_handler((void *) d, ++busy_count)) {
		if (errp) {
		    sqlite3_free(errp);
		    errp = NULL;
		}
		goto doit;
	    }
	}
	d->intrans = 0;
	if (ret != SQLITE_OK) {
	    if (!fail) {
		setstatd(d, ret, "%s", (*d->ov3) ? "HY000" : "S1000",
			 errp ? errp : "transaction failed");
		if (errp) {
		    sqlite3_free(errp);
		    errp = NULL;
		}
		fail = 1;
		goto rollback;
	    }
	    if (errp) {
		sqlite3_free(errp);
		errp = NULL;
	    }
	    return SQL_ERROR;
	}
	if (errp) {
	    sqlite3_free(errp);
	    errp = NULL;
	}
	return SQL_SUCCESS;
    }
    setstatd(d, -1, "invalid completion type", (*d->ov3) ? "HY000" : "S1000");
    return SQL_ERROR;
}

/**
 * Internal commit or rollback transaction.
 * @param type type of handle
 * @param handle HDBC, HENV, or HSTMT handle
 * @param comptype SQL_COMMIT or SQL_ROLLBACK
 * @result ODBC error code
 */

static SQLRETURN
drvendtran(SQLSMALLINT type, SQLHANDLE handle, SQLSMALLINT comptype)
{
    DBC *d;
    int fail = 0;

    switch (type) {
    case SQL_HANDLE_DBC:
	if (handle == SQL_NULL_HDBC) {
	    return SQL_INVALID_HANDLE;
	}
	d = (DBC *) handle;
	return endtran(d, comptype);
    case SQL_HANDLE_ENV:
	if (handle == SQL_NULL_HENV) {
	    return SQL_INVALID_HANDLE;
	}
	d = ((ENV *) handle)->dbcs;
	while (d) {
	    SQLRETURN ret;

	    ret = endtran(d, comptype);
	    if (ret != SQL_SUCCESS) {
		fail++;
		comptype = SQL_ROLLBACK;
	    }
	    d = d->next;
	}
	return fail ? SQL_ERROR : SQL_SUCCESS;
    }
    return SQL_INVALID_HANDLE;
}

/**
 * Commit or rollback transaction.
 * @param type type of handle
 * @param handle HDBC, HENV, or HSTMT handle
 * @param comptype SQL_COMMIT or SQL_ROLLBACK
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLEndTran(SQLSMALLINT type, SQLHANDLE handle, SQLSMALLINT comptype)
{
    return drvendtran(type, handle, comptype);
}

/**
 * Commit or rollback transaction.
 * @param env environment handle or NULL
 * @param dbc database connection handle or NULL
 * @param type SQL_COMMIT or SQL_ROLLBACK
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLTransact(SQLHENV env, SQLHDBC dbc, UWORD type)
{
    if (env != SQL_NULL_HENV) {
	return drvendtran(SQL_HANDLE_ENV, (SQLHANDLE) env, type);
    }
    return drvendtran(SQL_HANDLE_DBC, (SQLHANDLE) dbc, type);
}

/**
 * Function not implemented.
 */

SQLRETURN SQL_API
SQLCopyDesc(SQLHDESC source, SQLHDESC target)
{
    return SQL_ERROR;
}

/**
 * Translate SQL string.
 * @param stmt statement handle
 * @param sqlin input string
 * @param sqlinLen length of input string
 * @param sql output string
 * @param sqlMax max space in output string
 * @param sqlLen value return for length of output string
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLNativeSql(SQLHSTMT stmt, SQLCHAR *sqlin, SQLINTEGER sqlinLen,
	     SQLCHAR *sql, SQLINTEGER sqlMax, SQLINTEGER *sqlLen)
{
    int outLen = 0;

    if (sqlinLen == SQL_NTS) {
	sqlinLen = strlen(sqlin);
    }
    if (sql) {
	if (sqlMax > 0) {
	    strncpy(sql, sqlin, sqlMax - 1);
	    sqlin[sqlMax - 1] = '\0';
	    outLen = min(sqlMax - 1, sqlinLen);
	}
    } else {
	outLen = sqlinLen;
    }
    if (sqlLen) {
	*sqlLen = outLen;
    }
    if (sql && outLen < sqlinLen) {
	setstat((STMT *) stmt, -1, "data right truncated", "01004");
	return SQL_SUCCESS_WITH_INFO;
    }
    return SQL_SUCCESS;
}

/**
 * Columns for result set of SQLProcedures().
 */

static COL procSpec[] = {
    { "SYSTEM", "PROCEDURE", "PROCEDURE_QUALIFIER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "PROCEDURE", "PROCEDURE_OWNER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "PROCEDURE", "PROCEDURE_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "PROCEDURE", "NUM_INPUT_PARAMS", SQL_SMALLINT, 5 },
    { "SYSTEM", "PROCEDURE", "NUM_OUTPUT_PARAMS", SQL_SMALLINT, 5 },
    { "SYSTEM", "PROCEDURE", "NUM_RESULT_SETS", SQL_SMALLINT, 5 },
    { "SYSTEM", "PROCEDURE", "REMARKS", SCOL_VARCHAR, 255 },
    { "SYSTEM", "PROCEDURE", "PROCEDURE_TYPE", SQL_SMALLINT, 5 }
};

/**
 * Retrieve information about stored procedures.
 * @param stmt statement handle
 * @param catalog catalog name/pattern or NULL
 * @param catalogLen length of catalog or SQL_NTS
 * @param schema schema name/pattern or NULL
 * @param schemaLen length of schema or SQL_NTS
 * @param proc procedure name/pattern or NULL
 * @param procLen length of proc or SQL_NTS
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLProcedures(SQLHSTMT stmt,
	      SQLCHAR *catalog, SQLSMALLINT catalogLen,
	      SQLCHAR *schema, SQLSMALLINT schemaLen,
	      SQLCHAR *proc, SQLSMALLINT procLen)
{
    return mkresultset(stmt, procSpec, array_size(procSpec));
}

/**
 * Columns for result set of SQLProcedureColumns().
 */

static COL procColSpec[] = {
    { "SYSTEM", "PROCCOL", "PROCEDURE_QUALIFIER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "PROCCOL", "PROCEDURE_OWNER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "PROCCOL", "PROCEDURE_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "PROCCOL", "COLUMN_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "PROCCOL", "COLUMN_TYPE", SQL_SMALLINT, 5 },
    { "SYSTEM", "PROCCOL", "DATA_TYPE", SQL_SMALLINT, 5 },
    { "SYSTEM", "PROCCOL", "TYPE_NAME", SCOL_VARCHAR, 50 },
    { "SYSTEM", "PROCCOL", "PRECISION", SQL_INTEGER, 10 },
    { "SYSTEM", "PROCCOL", "LENGTH", SQL_INTEGER, 10 },
    { "SYSTEM", "PROCCOL", "RADIX", SQL_SMALLINT, 5 },
    { "SYSTEM", "PROCCOL", "SCALE", SQL_SMALLINT, 5 },
    { "SYSTEM", "PROCCOL", "NULLABLE", SQL_SMALLINT, 5 },
    { "SYSTEM", "PROCCOL", "REMARKS", SCOL_VARCHAR, 50 },
    { "SYSTEM", "PROCCOL", "COLUMN_DEF", SCOL_VARCHAR, 50 },
    { "SYSTEM", "PROCCOL", "SQL_DATA_TYPE", SQL_SMALLINT, 5 },
    { "SYSTEM", "PROCCOL", "SQL_DATETIME_SUB", SQL_SMALLINT, 5 },
    { "SYSTEM", "PROCCOL", "CHAR_OCTET_LENGTH", SQL_SMALLINT, 5 },
    { "SYSTEM", "PROCCOL", "ORDINAL_POSITION", SQL_SMALLINT, 5 },
    { "SYSTEM", "PROCCOL", "IS_NULLABLE", SCOL_VARCHAR, 50 }
};

/**
 * Retrieve information about columns in result set of stored procedures.
 * @param stmt statement handle
 * @param catalog catalog name/pattern or NULL
 * @param catalogLen length of catalog or SQL_NTS
 * @param schema schema name/pattern or NULL
 * @param schemaLen length of schema or SQL_NTS
 * @param proc procedure name/pattern or NULL
 * @param procLen length of proc or SQL_NTS
 * @param column column name/pattern or NULL
 * @param columnLen length of column or SQL_NTS
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLProcedureColumns(SQLHSTMT stmt,
		    SQLCHAR *catalog, SQLSMALLINT catalogLen,
		    SQLCHAR *schema, SQLSMALLINT schemaLen,
		    SQLCHAR *proc, SQLSMALLINT procLen,
		    SQLCHAR *column, SQLSMALLINT columnLen)
{
    return mkresultset(stmt, procColSpec, array_size(procColSpec));

}

/**
 * Get information of HENV.
 * @param env environment handle
 * @param attr attribute to be retrieved
 * @param val output buffer
 * @param len length of output buffer
 * @param lenp output length
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLGetEnvAttr(SQLHENV env, SQLINTEGER attr, SQLPOINTER val,
	      SQLINTEGER len, SQLINTEGER *lenp)
{
    ENV *e;

    if (env == SQL_NULL_HENV) {
	return SQL_INVALID_HANDLE;
    }
    e = (ENV *) env;
    if (!e || e->magic != ENV_MAGIC) {
	return SQL_INVALID_HANDLE;
    }
    switch (attr) {
    case SQL_ATTR_CONNECTION_POOLING:
	return SQL_ERROR;
    case SQL_ATTR_CP_MATCH:
	return SQL_NO_DATA;
    case SQL_ATTR_OUTPUT_NTS:
	if (val) {
	    *((SQLINTEGER *) val) = SQL_TRUE;
	}
	if (lenp) {
	    *lenp = sizeof (SQLINTEGER);
	}
	return SQL_SUCCESS;
    case SQL_ATTR_ODBC_VERSION:
	if (val) {
	    *((SQLINTEGER *) val) = e->ov3 ? SQL_OV_ODBC3 : SQL_OV_ODBC2;
	}
	if (lenp) {
	    *lenp = sizeof (SQLINTEGER);
	}
	return SQL_SUCCESS;
    }
    return SQL_ERROR;
}

/**
 * Set information in HENV.
 * @param env environment handle
 * @param attr attribute to be retrieved
 * @param val parameter buffer
 * @param len length of parameter
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLSetEnvAttr(SQLHENV env, SQLINTEGER attr, SQLPOINTER val, SQLINTEGER len)
{
    ENV *e;

    if (env == SQL_NULL_HENV) {
	return SQL_INVALID_HANDLE;
    }
    e = (ENV *) env;
    if (!e || e->magic != ENV_MAGIC) {
	return SQL_INVALID_HANDLE;
    }
    switch (attr) {
    case SQL_ATTR_CONNECTION_POOLING:
	return SQL_SUCCESS;
    case SQL_ATTR_CP_MATCH:
	return SQL_NO_DATA;
    case SQL_ATTR_OUTPUT_NTS:
	if ((SQLINTEGER) val == SQL_TRUE) {
	    return SQL_SUCCESS;
	}
	return SQL_ERROR;
    case SQL_ATTR_ODBC_VERSION:
	if (!val) {
	    return SQL_ERROR;
	}
	if ((SQLINTEGER) val == SQL_OV_ODBC2) {
	    e->ov3 = 0;
	    return SQL_SUCCESS;
	}
	if ((SQLINTEGER) val == SQL_OV_ODBC3) {
	    e->ov3 = 1;
	    return SQL_SUCCESS;
	}
	return SQL_ERROR;
    }
    return SQL_ERROR;
}

/**
 * Internal get error message given handle (HENV, HDBC, or HSTMT).
 * @param htype handle type
 * @param handle HENV, HDBC, or HSTMT
 * @param recno
 * @param sqlstate output buffer for SQL state
 * @param nativeerr output buffer of native error code
 * @param msg output buffer for error message
 * @param buflen length of output buffer
 * @param msglen output length
 * @result ODBC error code
 */

static SQLRETURN
drvgetdiagrec(SQLSMALLINT htype, SQLHANDLE handle, SQLSMALLINT recno,
	      SQLCHAR *sqlstate, SQLINTEGER *nativeerr, SQLCHAR *msg,
	      SQLSMALLINT buflen, SQLSMALLINT *msglen)
{
    DBC *d = NULL;
    STMT *s = NULL;
    int len, naterr;
    char *logmsg, *sqlst;

    if (handle == SQL_NULL_HANDLE) {
	return SQL_INVALID_HANDLE;
    }
    if (sqlstate) {
	sqlstate[0] = '\0';
    }
    if (msg && buflen > 0) {
	msg[0] = '\0';
    }
    if (msglen) {
	*msglen = 0;
    }
    if (nativeerr) {
	*nativeerr = 0;
    }
    switch (htype) {
    case SQL_HANDLE_ENV:
    case SQL_HANDLE_DESC:
	return SQL_NO_DATA;
    case SQL_HANDLE_DBC:
	d = (DBC *) handle;
	logmsg = d->logmsg;
	sqlst = d->sqlstate;
	naterr = d->naterr;
	break;
    case SQL_HANDLE_STMT:
	s = (STMT *) handle;
	logmsg = s->logmsg;
	sqlst = s->sqlstate;
	naterr = s->naterr;
	break;
    default:
	return SQL_INVALID_HANDLE;
    }
    if (buflen < 0) {
	return SQL_ERROR;
    }
    if (recno > 1) {
	return SQL_NO_DATA;
    }
    len = strlen(logmsg);
    if (len == 0) {
	return SQL_NO_DATA;
    }
    if (nativeerr) {
	*nativeerr = naterr;
    }
    if (sqlstate) {
	strcpy(sqlstate, sqlst);
    }
    if (msglen) {
	*msglen = len;
    }
    if (len >= buflen) {
	if (msg && buflen > 0) {
	    strncpy(msg, logmsg, buflen);
	    msg[buflen - 1] = '\0';
	    logmsg[0] = '\0';
	}
    } else if (msg) {
	strcpy(msg, logmsg);
	logmsg[0] = '\0';
    }
    return SQL_SUCCESS;
}

/**
 * Get error message given handle (HENV, HDBC, or HSTMT).
 * @param htype handle type
 * @param handle HENV, HDBC, or HSTMT
 * @param recno
 * @param sqlstate output buffer for SQL state
 * @param nativeerr output buffer of native error code
 * @param msg output buffer for error message
 * @param buflen length of output buffer
 * @param msglen output length
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLGetDiagRec(SQLSMALLINT htype, SQLHANDLE handle, SQLSMALLINT recno,
	      SQLCHAR *sqlstate, SQLINTEGER *nativeerr, SQLCHAR *msg,
	      SQLSMALLINT buflen, SQLSMALLINT *msglen)
{
    return drvgetdiagrec(htype, handle, recno, sqlstate,
			 nativeerr, msg, buflen, msglen);
}

/**
 * Function not implemented.
 */

SQLRETURN SQL_API
SQLGetDiagField(SQLSMALLINT htype, SQLHANDLE handle, SQLSMALLINT recno,
		SQLSMALLINT id, SQLPOINTER info, 
		SQLSMALLINT buflen, SQLSMALLINT *strlen)
{
    return SQL_ERROR;
}

/**
 * Internal get option of HSTMT.
 * @param stmt statement handle
 * @param attr attribute to be retrieved
 * @param val output buffer
 * @param bufmax length of output buffer
 * @param buflen output length
 * @result ODBC error code
 */

static SQLRETURN
drvgetstmtattr(SQLHSTMT stmt, SQLINTEGER attr, SQLPOINTER val,
	       SQLINTEGER bufmax, SQLINTEGER *buflen)
{
    STMT *s = (STMT *) stmt;
    SQLUINTEGER *uval = (SQLUINTEGER *) val;

    switch (attr) {
    case SQL_QUERY_TIMEOUT:
	*uval = 0;
	return SQL_SUCCESS;
    case SQL_ATTR_CURSOR_TYPE:
	*uval = s->curtype;
	return SQL_SUCCESS;
    case SQL_ATTR_CURSOR_SCROLLABLE:
	*uval = s->curtype != SQL_CURSOR_FORWARD_ONLY ?
	    SQL_SCROLLABLE : SQL_NONSCROLLABLE;
	return SQL_SUCCESS;
#ifdef SQL_ATTR_CURSOR_SENSITIVITY
    case SQL_ATTR_CURSOR_SENSITIVITY:
	*uval = SQL_UNSPECIFIED;
	return SQL_SUCCESS;
#endif
    case SQL_ATTR_ROW_NUMBER:
	{
	    STMT *s = (STMT *) stmt;
	    DBC *d = (DBC *) s->dbc;

	    if (s == d->cur_s3stmt) {
		*uval = d->s3stmt_rownum < 0 ?
		    SQL_ROW_NUMBER_UNKNOWN : d->s3stmt_rownum;
	    }
	}
	*uval = s->rowp < 0 ? SQL_ROW_NUMBER_UNKNOWN : s->rowp;
	return SQL_SUCCESS;
    case SQL_ATTR_ASYNC_ENABLE:
	*uval = SQL_ASYNC_ENABLE_OFF;
	return SQL_SUCCESS;
    case SQL_CONCURRENCY:
	*uval = SQL_CONCUR_LOCK;
	return SQL_SUCCESS;
    case SQL_ATTR_RETRIEVE_DATA:
	*uval = s->retr_data;
	return SQL_SUCCESS;
    case SQL_ROWSET_SIZE:
    case SQL_ATTR_ROW_ARRAY_SIZE:
	*uval = s->rowset_size;
	return SQL_SUCCESS;
    /* Needed for some driver managers, but dummies for now */
    case SQL_ATTR_IMP_ROW_DESC:
    case SQL_ATTR_APP_ROW_DESC:
    case SQL_ATTR_IMP_PARAM_DESC:
    case SQL_ATTR_APP_PARAM_DESC:
	*((SQLHDESC *) val) = (SQLHDESC) DEAD_MAGIC;
	return SQL_SUCCESS;
    case SQL_ATTR_ROW_STATUS_PTR:
	*((SQLUSMALLINT **) val) = s->row_status;
	return SQL_SUCCESS;
    case SQL_ATTR_ROWS_FETCHED_PTR:
	*((SQLUINTEGER **) val) = s->row_count;
	return SQL_SUCCESS;
    case SQL_ATTR_USE_BOOKMARKS: {
	STMT *s = (STMT *) stmt;

	*(SQLUINTEGER *) val = s->bkmrk ? SQL_UB_ON : SQL_UB_OFF;
	return SQL_SUCCESS;
    }
    case SQL_ATTR_PARAM_BIND_OFFSET_PTR:
	*((SQLUINTEGER **) val) = s->parm_bind_offs;
	return SQL_SUCCESS;
    case SQL_ATTR_PARAM_BIND_TYPE:
	*((SQLUINTEGER *) val) = SQL_PARAM_BIND_BY_COLUMN;
	return SQL_SUCCESS;
    case SQL_ATTR_PARAM_OPERATION_PTR:
	*((SQLUSMALLINT **) val) = s->parm_oper;
	return SQL_SUCCESS;
    case SQL_ATTR_PARAM_STATUS_PTR:
	*((SQLUSMALLINT **) val) = s->parm_status;
	return SQL_SUCCESS;
    case SQL_ATTR_PARAMS_PROCESSED_PTR:
	*((SQLUINTEGER **) val) = s->parm_proc;
	return SQL_SUCCESS;
    case SQL_ATTR_PARAMSET_SIZE:
	*((SQLUINTEGER *) val) = s->paramset_size;
	return SQL_SUCCESS;
    case SQL_ATTR_ROW_BIND_TYPE:
	*(SQLUINTEGER *) val = s->bind_type;
	return SQL_SUCCESS;
    case SQL_ATTR_ROW_BIND_OFFSET_PTR:
	*((SQLUINTEGER **) val) = s->bind_offs;
	return SQL_SUCCESS;
    }
    return drvunimplstmt(stmt);
}

/**
 * Get option of HSTMT.
 * @param stmt statement handle
 * @param attr attribute to be retrieved
 * @param val output buffer
 * @param bufmax length of output buffer
 * @param buflen output length
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLGetStmtAttr(SQLHSTMT stmt, SQLINTEGER attr, SQLPOINTER val,
	       SQLINTEGER bufmax, SQLINTEGER *buflen)
{
    return drvgetstmtattr(stmt, attr, val, bufmax, buflen);
}

/**
 * Internal set option on HSTMT.
 * @param stmt statement handle
 * @param attr attribute to be set
 * @param val input buffer (attribute value)
 * @param buflen length of input buffer
 * @result ODBC error code
 */

static SQLRETURN
drvsetstmtattr(SQLHSTMT stmt, SQLINTEGER attr, SQLPOINTER val,
	       SQLINTEGER buflen)
{
    STMT *s = (STMT *) stmt;

    switch (attr) {
    case SQL_ATTR_CURSOR_TYPE:
	if ((SQLUINTEGER) val == SQL_CURSOR_FORWARD_ONLY) {
	    s->curtype = SQL_CURSOR_FORWARD_ONLY;
	} else {
	    s->curtype = SQL_CURSOR_STATIC;
	}
	if ((SQLUINTEGER) val != SQL_CURSOR_FORWARD_ONLY &&
	    (SQLUINTEGER) val != SQL_CURSOR_STATIC) {
	    goto e01s02;
	}
	return SQL_SUCCESS;
    case SQL_ATTR_CURSOR_SCROLLABLE:
	if ((SQLUINTEGER) val == SQL_NONSCROLLABLE) {
	    s->curtype = SQL_CURSOR_FORWARD_ONLY;
	} else {
	    s->curtype = SQL_CURSOR_STATIC;
	}
	return SQL_SUCCESS;
    case SQL_ATTR_ASYNC_ENABLE:
	if ((SQLUINTEGER) val != SQL_ASYNC_ENABLE_OFF) {
    e01s02:
	    setstat(s, -1, "option value changed", "01S02");
	    return SQL_SUCCESS_WITH_INFO;
	}
	return SQL_SUCCESS;
    case SQL_CONCURRENCY:
	if ((SQLUINTEGER) val != SQL_CONCUR_LOCK) {
	    goto e01s02;
	}
	return SQL_SUCCESS;
    case SQL_ATTR_QUERY_TIMEOUT:
	return SQL_SUCCESS;
    case SQL_ATTR_RETRIEVE_DATA:
	if ((SQLUINTEGER) val != SQL_RD_ON &&
	    (SQLUINTEGER) val != SQL_RD_OFF) {
	    goto e01s02;
	}
	s->retr_data = (int) val;
	return SQL_SUCCESS;
    case SQL_ROWSET_SIZE:
    case SQL_ATTR_ROW_ARRAY_SIZE:
	if ((SQLUINTEGER) val < 1) {
	    setstat(s, -1, "invalid rowset size", "HY000");
	    return SQL_ERROR;
	} else {
	    SQLUSMALLINT *rst = &s->row_status1;

	    if ((SQLUINTEGER) val > 1) {
		rst = xmalloc(sizeof (SQLUSMALLINT) * (SQLUINTEGER) val);
		if (!rst) {
		    return nomem(s);
		}
	    }
	    if (s->row_status0 != &s->row_status1) {
		freep(&s->row_status0);
	    }
	    s->row_status0 = rst;
	    s->rowset_size = (SQLUINTEGER) val;
	}
	return SQL_SUCCESS;
    case SQL_ATTR_ROW_STATUS_PTR:
	s->row_status = (SQLUSMALLINT *) val;
	return SQL_SUCCESS;
    case SQL_ATTR_ROWS_FETCHED_PTR:
	s->row_count = (SQLUINTEGER *) val;
	return SQL_SUCCESS;
    case SQL_ATTR_PARAM_BIND_OFFSET_PTR:
	s->parm_bind_offs = (SQLUINTEGER *) val;
	return SQL_SUCCESS;
    case SQL_ATTR_PARAM_BIND_TYPE:
	if ((SQLUINTEGER) val != SQL_PARAM_BIND_BY_COLUMN) {
	    goto e01s02;
	}
	return SQL_SUCCESS;
    case SQL_ATTR_PARAM_OPERATION_PTR:
	s->parm_oper = (SQLUSMALLINT *) val;
	return SQL_SUCCESS;
    case SQL_ATTR_PARAM_STATUS_PTR:
	s->parm_status = (SQLUSMALLINT *) val;
	return SQL_SUCCESS;
    case SQL_ATTR_PARAMS_PROCESSED_PTR:
	s->parm_proc = (SQLUINTEGER *) val;
	return SQL_SUCCESS;
    case SQL_ATTR_PARAMSET_SIZE:
	if ((SQLUINTEGER) val < 1) {
	    goto e01s02;
	}
	s->paramset_size = (SQLUINTEGER) val;
	s->paramset_count = 0;
	return SQL_SUCCESS;
    case SQL_ATTR_ROW_BIND_TYPE:
	s->bind_type = (SQLUINTEGER) val;
	return SQL_SUCCESS;
    case SQL_ATTR_ROW_BIND_OFFSET_PTR:
	s->bind_offs = (SQLUINTEGER *) val;
	return SQL_SUCCESS;
    case SQL_ATTR_USE_BOOKMARKS:
	if ((SQLUINTEGER) val != SQL_UB_OFF &&
	    (SQLUINTEGER) val != SQL_UB_ON) {
	    goto e01s02;
	}
	s->bkmrk = (SQLUINTEGER) val == SQL_UB_ON;
	return SQL_SUCCESS;
    }
    return drvunimplstmt(stmt);
}

/**
 * Set option on HSTMT.
 * @param stmt statement handle
 * @param attr attribute to be set
 * @param val input buffer (attribute value)
 * @param buflen length of input buffer
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLSetStmtAttr(SQLHSTMT stmt, SQLINTEGER attr, SQLPOINTER val,
	       SQLINTEGER buflen)
{
    return drvsetstmtattr(stmt, attr, val, buflen);
}

/**
 * Internal get option of HSTMT.
 * @param stmt statement handle
 * @param opt option to be retrieved
 * @param param output buffer
 * @result ODBC error code
 */

static SQLRETURN
drvgetstmtoption(SQLHSTMT stmt, SQLUSMALLINT opt, SQLPOINTER param)
{
    STMT *s = (STMT *) stmt;
    SQLUINTEGER *ret = (SQLUINTEGER *) param;

    switch (opt) {
    case SQL_QUERY_TIMEOUT:
	*ret = 0;
	return SQL_SUCCESS;
    case SQL_CURSOR_TYPE:
	*ret = s->curtype;
	return SQL_SUCCESS;
    case SQL_ROW_NUMBER:
	{
	    DBC *d = (DBC *) s->dbc;

	    if (s == d->cur_s3stmt) {
		*ret = d->s3stmt_rownum < 0 ?
		    SQL_ROW_NUMBER_UNKNOWN : d->s3stmt_rownum;
	    }
	}
	*ret = s->rowp < 0 ? SQL_ROW_NUMBER_UNKNOWN : s->rowp;
	return SQL_SUCCESS;
    case SQL_ASYNC_ENABLE:
	*ret = SQL_ASYNC_ENABLE_OFF;
	return SQL_SUCCESS;
    case SQL_CONCURRENCY:
	*ret = SQL_CONCUR_LOCK;
	return SQL_SUCCESS;
    case SQL_ATTR_RETRIEVE_DATA:
	*ret = s->retr_data;
	return SQL_SUCCESS;
    case SQL_ROWSET_SIZE:
    case SQL_ATTR_ROW_ARRAY_SIZE:
	*ret = s->rowset_size;
	return SQL_SUCCESS;
    }
    return drvunimplstmt(stmt);
}

/**
 * Get option of HSTMT.
 * @param stmt statement handle
 * @param opt option to be retrieved
 * @param param output buffer
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLGetStmtOption(SQLHSTMT stmt, SQLUSMALLINT opt, SQLPOINTER param)
{
    return drvgetstmtoption(stmt, opt, param);
}

/**
 * Internal set option on HSTMT.
 * @param stmt statement handle
 * @param opt option to be set
 * @param param input buffer (option value)
 * @result ODBC error code
 */

static SQLRETURN
drvsetstmtoption(SQLHSTMT stmt, SQLUSMALLINT opt, SQLUINTEGER param)
{
    STMT *s = (STMT *) stmt;

    switch (opt) {
    case SQL_CURSOR_TYPE:
	if (param == SQL_CURSOR_FORWARD_ONLY) {
	    s->curtype = param;
	} else {
	    s->curtype = SQL_CURSOR_STATIC;
	}
	if (param != SQL_CURSOR_FORWARD_ONLY &&
	    param != SQL_CURSOR_STATIC) {
	    goto e01s02;
	}
	return SQL_SUCCESS;
    case SQL_ASYNC_ENABLE:
	if (param != SQL_ASYNC_ENABLE_OFF) {
	    goto e01s02;
	}
	return SQL_SUCCESS;
    case SQL_CONCURRENCY:
	if (param != SQL_CONCUR_LOCK) {
	    goto e01s02;
	}
	return SQL_SUCCESS;
    case SQL_QUERY_TIMEOUT:
	return SQL_SUCCESS;
    case SQL_RETRIEVE_DATA:
	if (param != SQL_RD_ON && param != SQL_RD_OFF) {
    e01s02:
	    setstat(s, -1, "option value changed", "01S02");
	    return SQL_SUCCESS_WITH_INFO;
	}
	s->retr_data = (int) param;
	return SQL_SUCCESS;
    case SQL_ROWSET_SIZE:
    case SQL_ATTR_ROW_ARRAY_SIZE:
	if (param < 1) {
	    setstat(s, -1, "invalid rowset size", "HY000");
	    return SQL_ERROR;
	} else {
	    SQLUSMALLINT *rst = &s->row_status1;

	    if (param > 1) {
		rst = xmalloc(sizeof (SQLUSMALLINT) * param);
		if (!rst) {
		    return nomem(s);
		}
	    }
	    if (s->row_status0 != &s->row_status1) {
		freep(&s->row_status0);
	    }
	    s->row_status0 = rst;
	    s->rowset_size = param;
	}
	return SQL_SUCCESS;
    }
    return drvunimplstmt(stmt);
}

/**
 * Set option on HSTMT.
 * @param stmt statement handle
 * @param opt option to be set
 * @param param input buffer (option value)
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLSetStmtOption(SQLHSTMT stmt, SQLUSMALLINT opt, SQLUINTEGER param)
{
    return drvsetstmtoption(stmt, opt, param);
}

/**
 * Function not implemented.
 */

SQLRETURN SQL_API
SQLSetPos(SQLHSTMT stmt, SQLUSMALLINT row, SQLUSMALLINT op, SQLUSMALLINT lock)
{
    return drvunimplstmt(stmt);
}

/**
 * Function not implemented.
 */

SQLRETURN SQL_API
SQLSetScrollOptions(SQLHSTMT stmt, SQLUSMALLINT concur, SQLINTEGER rowkeyset,
		    SQLUSMALLINT rowset)
{
    return drvunimplstmt(stmt);
}

#define strmak(dst, src, max, lenp) { \
    int len = strlen(src); \
    int cnt = min(len + 1, max); \
    strncpy(dst, src, cnt); \
    *lenp = (cnt > len) ? len : cnt; \
}

/**
 * Internal return information about what this ODBC driver supports.
 * @param dbc database connection handle
 * @param type type of information to be retrieved
 * @param val output buffer
 * @param valMax length of output buffer
 * @param valLen output length
 * @result ODBC error code
 */

static SQLRETURN
drvgetinfo(SQLHDBC dbc, SQLUSMALLINT type, SQLPOINTER val, SQLSMALLINT valMax,
	   SQLSMALLINT *valLen)
{
    DBC *d;
    char dummyc[16];
    SQLSMALLINT dummy;
    static char drvname[] =
#ifdef _WIN32
	"sqliteodbc.dll";
#else
	"sqliteodbc.so";
#endif

    if (dbc == SQL_NULL_HDBC) {
	return SQL_INVALID_HANDLE;
    }
    d = (DBC *) dbc;
    if (valMax) {
	valMax--;
    }
    if (!valLen) {
	valLen = &dummy;
    }
    if (!val) {
	val = dummyc;
	valMax = sizeof (dummyc) - 1;
    }
    switch (type) {
    case SQL_MAX_USER_NAME_LEN:
	*((SQLSMALLINT *) val) = 16;
	*valLen = sizeof (SQLSMALLINT);
	break;
    case SQL_USER_NAME:
	strmak(val, "", valMax, valLen);
	break;
    case SQL_DRIVER_ODBC_VER:
#if 0
	strmak(val, (*d->ov3) ? "03.00" : "02.50", valMax, valLen);
#else
	strmak(val, "03.00", valMax, valLen);
#endif
	break;
    case SQL_ACTIVE_CONNECTIONS:
    case SQL_ACTIVE_STATEMENTS:
	*((SQLSMALLINT *) val) = 0;
	*valLen = sizeof (SQLSMALLINT);
	break;
#ifdef SQL_ASYNC_MODE
    case SQL_ASYNC_MODE:
	*((SQLUINTEGER *) val) = SQL_AM_NONE;
	*valLen = sizeof (SQLUINTEGER);
	break;
#endif
#ifdef SQL_CREATE_TABLE
    case SQL_CREATE_TABLE:
	*((SQLUINTEGER *) val) = SQL_CT_CREATE_TABLE |
				 SQL_CT_COLUMN_DEFAULT |
				 SQL_CT_COLUMN_CONSTRAINT |
				 SQL_CT_CONSTRAINT_NON_DEFERRABLE;
	*valLen = sizeof (SQLUINTEGER);
	break;
#endif
#ifdef SQL_CREATE_VIEW
    case SQL_CREATE_VIEW:
	*((SQLUINTEGER *) val) = SQL_CV_CREATE_VIEW;
	*valLen = sizeof (SQLUINTEGER);
	break;
#endif
#ifdef SQL_DDL_INDEX
    case SQL_DDL_INDEX:
	*((SQLUINTEGER *) val) = SQL_DI_CREATE_INDEX | SQL_DI_DROP_INDEX;
	*valLen = sizeof (SQLUINTEGER);
	break;
#endif
#ifdef SQL_DROP_TABLE
    case SQL_DROP_TABLE:
	*((SQLUINTEGER *) val) = SQL_DT_DROP_TABLE;
	*valLen = sizeof (SQLUINTEGER);
	break;
#endif
#ifdef SQL_DROP_VIEW
    case SQL_DROP_VIEW:
	*((SQLUINTEGER *) val) = SQL_DV_DROP_VIEW;
	*valLen = sizeof (SQLUINTEGER);
	break;
#endif
#ifdef SQL_INDEX_KEYWORDS
    case SQL_INDEX_KEYWORDS:
	*((SQLUINTEGER *) val) = SQL_IK_ALL;
	*valLen = sizeof (SQLUINTEGER);
	break;
#endif
    case SQL_DATA_SOURCE_NAME:
	strmak(val, (d->dsn ? d->dsn : ""), valMax, valLen);
	break;
    case SQL_DRIVER_NAME:
	strmak(val, drvname, valMax, valLen);
	break;
    case SQL_DRIVER_VER:
	strmak(val, DRIVER_VER_INFO, valMax, valLen);
	break;
    case SQL_FETCH_DIRECTION:
	*((SQLUINTEGER *) val) = SQL_FD_FETCH_NEXT | SQL_FD_FETCH_FIRST |
	    SQL_FD_FETCH_LAST | SQL_FD_FETCH_PRIOR | SQL_FD_FETCH_ABSOLUTE;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_ODBC_VER:
	strmak(val, (*d->ov3) ? "03.00" : "02.50", valMax, valLen);
	break;
    case SQL_ODBC_SAG_CLI_CONFORMANCE:
	*((SQLSMALLINT *) val) = SQL_OSCC_NOT_COMPLIANT;
	*valLen = sizeof (SQLSMALLINT);
	break;
    case SQL_STANDARD_CLI_CONFORMANCE:
	*((SQLUINTEGER *) val) = SQL_SCC_XOPEN_CLI_VERSION1;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_SERVER_NAME:
    case SQL_DATABASE_NAME:
	strmak(val, (d->dbname ? d->dbname : ""), valMax, valLen);
	break;
    case SQL_SEARCH_PATTERN_ESCAPE:
	strmak(val, "", valMax, valLen);
	break;
    case SQL_ODBC_SQL_CONFORMANCE:
	*((SQLSMALLINT *) val) = SQL_OSC_MINIMUM;
	*valLen = sizeof (SQLSMALLINT);
	break;
    case SQL_ODBC_API_CONFORMANCE:
	*((SQLSMALLINT *) val) = SQL_OAC_LEVEL1;
	*valLen = sizeof (SQLSMALLINT);
	break;
    case SQL_DBMS_NAME:
	strmak(val, "SQLite", valMax, valLen);
	break;
    case SQL_DBMS_VER:
	strmak(val, SQLITE_VERSION, valMax, valLen);
	break;
    case SQL_COLUMN_ALIAS:
    case SQL_NEED_LONG_DATA_LEN:
	strmak(val, "Y", valMax, valLen);
	break;
    case SQL_ROW_UPDATES:
    case SQL_ACCESSIBLE_PROCEDURES:
    case SQL_PROCEDURES:
    case SQL_EXPRESSIONS_IN_ORDERBY:
    case SQL_ODBC_SQL_OPT_IEF:
    case SQL_LIKE_ESCAPE_CLAUSE:
    case SQL_ORDER_BY_COLUMNS_IN_SELECT:
    case SQL_OUTER_JOINS:
    case SQL_ACCESSIBLE_TABLES:
    case SQL_MULT_RESULT_SETS:
    case SQL_MULTIPLE_ACTIVE_TXN:
    case SQL_MAX_ROW_SIZE_INCLUDES_LONG:
	strmak(val, "N", valMax, valLen);
	break;
    case SQL_DATA_SOURCE_READ_ONLY:
	strmak(val, "N", valMax, valLen);
	break;
#ifdef SQL_OJ_CAPABILITIES
    case SQL_OJ_CAPABILITIES:
	*((SQLUINTEGER *) val) = 0;
	*valLen = sizeof (SQLUINTEGER);
	break;
#endif
#ifdef SQL_MAX_IDENTIFIER_LEN
    case SQL_MAX_IDENTIFIER_LEN:
	*((SQLUSMALLINT *) val) = 255;
	*valLen = sizeof (SQLUSMALLINT);
	break;
#endif
    case SQL_CONCAT_NULL_BEHAVIOR:
	*((SQLSMALLINT *) val) = SQL_CB_NULL;
	*valLen = sizeof (SQLSMALLINT);
	break;
    case SQL_CURSOR_COMMIT_BEHAVIOR:
    case SQL_CURSOR_ROLLBACK_BEHAVIOR:
	*((SQLSMALLINT *) val) = SQL_CB_DELETE;
	*valLen = sizeof (SQLSMALLINT);
	break;
#ifdef SQL_CURSOR_SENSITIVITY
    case SQL_CURSOR_SENSITIVITY:
	*((SQLUINTEGER *) val) = SQL_UNSPECIFIED;
	*valLen = sizeof (SQLUINTEGER);
	break;
#endif
    case SQL_DEFAULT_TXN_ISOLATION:
	*((SQLUINTEGER *) val) = SQL_TXN_READ_UNCOMMITTED;
	*valLen = sizeof (SQLUINTEGER);
	break;
#ifdef SQL_DESCRIBE_PARAMETER
    case SQL_DESCRIBE_PARAMETER:
	strmak(val, "Y", valMax, valLen);
	break;
#endif
    case SQL_TXN_ISOLATION_OPTION:
	*((SQLUINTEGER *) val) = SQL_TXN_READ_UNCOMMITTED;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_IDENTIFIER_CASE:
	*((SQLSMALLINT *) val) = SQL_IC_SENSITIVE;
	*valLen = sizeof (SQLSMALLINT);
	break;
    case SQL_IDENTIFIER_QUOTE_CHAR:
	strmak(val, "\"", valMax, valLen);
	break;
    case SQL_MAX_TABLE_NAME_LEN:
    case SQL_MAX_COLUMN_NAME_LEN:
	*((SQLSMALLINT *) val) = 255;
	*valLen = sizeof (SQLSMALLINT);
	break;
    case SQL_MAX_CURSOR_NAME_LEN:
	*((SWORD *) val) = 255;
	*valLen = sizeof (SWORD);
	break;
    case SQL_MAX_PROCEDURE_NAME_LEN:
	*((SQLSMALLINT *) val) = 0;
	break;
    case SQL_MAX_QUALIFIER_NAME_LEN:
    case SQL_MAX_OWNER_NAME_LEN:
	*((SQLSMALLINT *) val) = 255;
	break;
    case SQL_OWNER_TERM:
	strmak(val, "owner", valMax, valLen);
	break;
    case SQL_PROCEDURE_TERM:
	strmak(val, "procedure", valMax, valLen);
	break;
    case SQL_QUALIFIER_NAME_SEPARATOR:
	strmak(val, ".", valMax, valLen);
	break;
    case SQL_QUALIFIER_TERM:
	strmak(val, "database", valMax, valLen);
	break;
    case SQL_QUALIFIER_USAGE:
	*((SQLUINTEGER *) val) = 0;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_SCROLL_CONCURRENCY:
	*((SQLUINTEGER *) val) = SQL_SCCO_LOCK;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_SCROLL_OPTIONS:
	*((SQLUINTEGER *) val) = SQL_SO_STATIC | SQL_SO_FORWARD_ONLY;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_TABLE_TERM:
	strmak(val, "table", valMax, valLen);
	break;
    case SQL_TXN_CAPABLE:
	*((SQLSMALLINT *) val) = SQL_TC_ALL;
	*valLen = sizeof (SQLSMALLINT);
	break;
    case SQL_CONVERT_FUNCTIONS:
	*((SQLUINTEGER *) val) = 0;
	*valLen = sizeof (SQLUINTEGER);
       break;
    case SQL_SYSTEM_FUNCTIONS:
    case SQL_NUMERIC_FUNCTIONS:
    case SQL_STRING_FUNCTIONS:
    case SQL_TIMEDATE_FUNCTIONS:
	*((SQLUINTEGER *) val) = 0;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_CONVERT_BIGINT:
    case SQL_CONVERT_BIT:
    case SQL_CONVERT_CHAR:
    case SQL_CONVERT_DATE:
    case SQL_CONVERT_DECIMAL:
    case SQL_CONVERT_DOUBLE:
    case SQL_CONVERT_FLOAT:
    case SQL_CONVERT_INTEGER:
    case SQL_CONVERT_LONGVARCHAR:
    case SQL_CONVERT_NUMERIC:
    case SQL_CONVERT_REAL:
    case SQL_CONVERT_SMALLINT:
    case SQL_CONVERT_TIME:
    case SQL_CONVERT_TIMESTAMP:
    case SQL_CONVERT_TINYINT:
    case SQL_CONVERT_VARCHAR:
	*((SQLUINTEGER *) val) = 
	    SQL_CVT_CHAR | SQL_CVT_NUMERIC | SQL_CVT_DECIMAL |
	    SQL_CVT_INTEGER | SQL_CVT_SMALLINT | SQL_CVT_FLOAT | SQL_CVT_REAL |
	    SQL_CVT_DOUBLE | SQL_CVT_VARCHAR | SQL_CVT_LONGVARCHAR |
	    SQL_CVT_BIT | SQL_CVT_TINYINT | SQL_CVT_BIGINT |
	    SQL_CVT_DATE | SQL_CVT_TIME | SQL_CVT_TIMESTAMP;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_CONVERT_BINARY:
    case SQL_CONVERT_VARBINARY:
    case SQL_CONVERT_LONGVARBINARY:
	*((SQLUINTEGER *) val) = 0;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_POSITIONED_STATEMENTS:
    case SQL_LOCK_TYPES:
	*((SQLUINTEGER *) val) = 0;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_BOOKMARK_PERSISTENCE:
	*((SQLUINTEGER *) val) = SQL_BP_SCROLL;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_UNION:
	*((SQLUINTEGER *) val) = SQL_U_UNION;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_OWNER_USAGE:
    case SQL_SUBQUERIES:
    case SQL_TIMEDATE_ADD_INTERVALS:
    case SQL_TIMEDATE_DIFF_INTERVALS:
	*((SQLUINTEGER *) val) = 0;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_QUOTED_IDENTIFIER_CASE:
	*((SQLUSMALLINT *) val) = SQL_IC_SENSITIVE;
	*valLen = sizeof (SQLUSMALLINT);
	break;
    case SQL_POS_OPERATIONS:
	*((SQLUINTEGER *) val) = 0;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_ALTER_TABLE:
	*((SQLUINTEGER *) val) = 0;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_CORRELATION_NAME:
	*((SQLSMALLINT *) val) = SQL_CN_DIFFERENT;
	*valLen = sizeof (SQLSMALLINT);
	break;
    case SQL_NON_NULLABLE_COLUMNS:
	*((SQLSMALLINT *) val) = SQL_NNC_NON_NULL;
	*valLen = sizeof (SQLSMALLINT);
	break;
    case SQL_NULL_COLLATION:
	*((SQLSMALLINT *) val) = SQL_NC_START;
	*valLen = sizeof(SQLSMALLINT);
	break;
    case SQL_MAX_COLUMNS_IN_GROUP_BY:
    case SQL_MAX_COLUMNS_IN_ORDER_BY:
    case SQL_MAX_COLUMNS_IN_SELECT:
    case SQL_MAX_COLUMNS_IN_TABLE:
    case SQL_MAX_ROW_SIZE:
    case SQL_MAX_TABLES_IN_SELECT:
	*((SQLSMALLINT *) val) = 0;
	*valLen = sizeof (SQLSMALLINT);
	break;
    case SQL_MAX_BINARY_LITERAL_LEN:
    case SQL_MAX_CHAR_LITERAL_LEN:
	*((SQLUINTEGER *) val) = 0;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_MAX_COLUMNS_IN_INDEX:
	*((SQLSMALLINT *) val) = 0;
	*valLen = sizeof (SQLSMALLINT);
	break;
    case SQL_MAX_INDEX_SIZE:
	*((SQLUINTEGER *) val) = 0;
	*valLen = sizeof(SQLUINTEGER);
	break;
#ifdef SQL_MAX_IDENTIFIER_LENGTH
    case SQL_MAX_IDENTIFIER_LENGTH:
	*((SQLUINTEGER *) val) = 255;
	*valLen = sizeof (SQLUINTEGER);
	break;
#endif
    case SQL_MAX_STATEMENT_LEN:
	*((SQLUINTEGER *) val) = 16384;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_QUALIFIER_LOCATION:
	*((SQLSMALLINT *) val) = SQL_QL_START;
	*valLen = sizeof (SQLSMALLINT);
	break;
    case SQL_GETDATA_EXTENSIONS:
	*((SQLUINTEGER *) val) =
	    SQL_GD_ANY_COLUMN | SQL_GD_ANY_ORDER | SQL_GD_BOUND;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_STATIC_SENSITIVITY:
	*((SQLUINTEGER *) val) = 0;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_FILE_USAGE:
	*((SQLSMALLINT *) val) = SQL_FILE_CATALOG;
	*valLen = sizeof (SQLSMALLINT);
	break;
    case SQL_GROUP_BY:
	*((SQLSMALLINT *) val) = 0;
	*valLen = sizeof (SQLSMALLINT);
	break;
    case SQL_KEYWORDS:
	strmak(val, "CREATE,SELECT,DROP,DELETE,UPDATE,INSERT,"
	       "INTO,VALUES,TABLE,INDEX,FROM,SET,WHERE,AND,CURRENT,OF",
	       valMax, valLen);
	break;
    case SQL_SPECIAL_CHARACTERS:
	strmak(val, "", valMax, valLen);
	break;
    case SQL_BATCH_SUPPORT:
    case SQL_BATCH_ROW_COUNT:
    case SQL_PARAM_ARRAY_ROW_COUNTS:
	*((SQLUINTEGER *) val) = 0;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES1:
	*((SQLUINTEGER *) val) = SQL_CA1_NEXT | SQL_CA1_BOOKMARK;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_STATIC_CURSOR_ATTRIBUTES1:
	*((SQLUINTEGER *) val) = SQL_CA1_NEXT | SQL_CA1_ABSOLUTE |
	    SQL_CA1_RELATIVE | SQL_CA1_BOOKMARK;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_FORWARD_ONLY_CURSOR_ATTRIBUTES2:
    case SQL_STATIC_CURSOR_ATTRIBUTES2:
	*((SQLUINTEGER *) val) = SQL_CA2_READ_ONLY_CONCURRENCY |
	    SQL_CA2_LOCK_CONCURRENCY;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_KEYSET_CURSOR_ATTRIBUTES1:
    case SQL_KEYSET_CURSOR_ATTRIBUTES2:
    case SQL_DYNAMIC_CURSOR_ATTRIBUTES1:
    case SQL_DYNAMIC_CURSOR_ATTRIBUTES2:
	*((SQLUINTEGER *) val) = 0;
	*valLen = sizeof (SQLUINTEGER);
	break;
    case SQL_ODBC_INTERFACE_CONFORMANCE:
	*((SQLUINTEGER *) val) = SQL_OIC_CORE;
	*valLen = sizeof (SQLUINTEGER);
	break;
    default:
	setstatd(d, -1, "unsupported info option %d",
		 (*d->ov3) ? "HYC00" : "S1C00", type);
	return SQL_ERROR;
    }
    return SQL_SUCCESS;
}

/**
 * Return information about what this ODBC driver supports.
 * @param dbc database connection handle
 * @param type type of information to be retrieved
 * @param val output buffer
 * @param valMax length of output buffer
 * @param valLen output length
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLGetInfo(SQLHDBC dbc, SQLUSMALLINT type, SQLPOINTER val, SQLSMALLINT valMax,
	   SQLSMALLINT *valLen)
{
    return drvgetinfo(dbc, type, val, valMax, valLen);
}

/**
 * Return information about supported ODBC API functions.
 * @param dbc database connection handle
 * @param func function code to be retrieved
 * @param flags output indicator
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLGetFunctions(SQLHDBC dbc, SQLUSMALLINT func,
		SQLUSMALLINT *flags)
{
    DBC *d;
    int i;
    SQLUSMALLINT exists[100];

    if (dbc == SQL_NULL_HDBC) {
	return SQL_INVALID_HANDLE;
    }
    d = (DBC *) dbc;
    for (i = 0; i < array_size(exists); i++) {
	exists[i] = SQL_FALSE;
    }
    exists[SQL_API_SQLALLOCCONNECT] = SQL_TRUE;
    exists[SQL_API_SQLFETCH] = SQL_TRUE;
    exists[SQL_API_SQLALLOCENV] = SQL_TRUE;
    exists[SQL_API_SQLFREECONNECT] = SQL_TRUE;
    exists[SQL_API_SQLALLOCSTMT] = SQL_TRUE;
    exists[SQL_API_SQLFREEENV] = SQL_TRUE;
    exists[SQL_API_SQLBINDCOL] = SQL_TRUE;
    exists[SQL_API_SQLFREESTMT] = SQL_TRUE;
    exists[SQL_API_SQLCANCEL] = SQL_TRUE;
    exists[SQL_API_SQLGETCURSORNAME] = SQL_TRUE;
    exists[SQL_API_SQLCOLATTRIBUTES] = SQL_TRUE;
    exists[SQL_API_SQLNUMRESULTCOLS] = SQL_TRUE;
    exists[SQL_API_SQLCONNECT] = SQL_TRUE;
    exists[SQL_API_SQLPREPARE] = SQL_TRUE;
    exists[SQL_API_SQLDESCRIBECOL] = SQL_TRUE;
    exists[SQL_API_SQLROWCOUNT] = SQL_TRUE;
    exists[SQL_API_SQLDISCONNECT] = SQL_TRUE;
    exists[SQL_API_SQLSETCURSORNAME] = SQL_FALSE;
    exists[SQL_API_SQLERROR] = SQL_TRUE;
    exists[SQL_API_SQLSETPARAM] = SQL_TRUE;
    exists[SQL_API_SQLEXECDIRECT] = SQL_TRUE;
    exists[SQL_API_SQLTRANSACT] = SQL_TRUE;
    exists[SQL_API_SQLEXECUTE] = SQL_TRUE;
    exists[SQL_API_SQLBINDPARAMETER] = SQL_TRUE;
    exists[SQL_API_SQLGETTYPEINFO] = SQL_TRUE;
    exists[SQL_API_SQLCOLUMNS] = SQL_TRUE;
    exists[SQL_API_SQLPARAMDATA] = SQL_TRUE;
    exists[SQL_API_SQLDRIVERCONNECT] = SQL_TRUE;
    exists[SQL_API_SQLPUTDATA] = SQL_TRUE;
    exists[SQL_API_SQLGETCONNECTOPTION] = SQL_TRUE;
    exists[SQL_API_SQLSETCONNECTOPTION] = SQL_TRUE;
    exists[SQL_API_SQLGETDATA] = SQL_TRUE;
    exists[SQL_API_SQLSETSTMTOPTION] = SQL_TRUE;
    exists[SQL_API_SQLGETFUNCTIONS] = SQL_TRUE;
    exists[SQL_API_SQLSPECIALCOLUMNS] = SQL_TRUE;
    exists[SQL_API_SQLGETINFO] = SQL_TRUE;
    exists[SQL_API_SQLSTATISTICS] = SQL_TRUE;
    exists[SQL_API_SQLGETSTMTOPTION] = SQL_TRUE;
    exists[SQL_API_SQLTABLES] = SQL_TRUE;
    exists[SQL_API_SQLBROWSECONNECT] = SQL_FALSE;
    exists[SQL_API_SQLNUMPARAMS] = SQL_TRUE;
    exists[SQL_API_SQLCOLUMNPRIVILEGES] = SQL_FALSE;
    exists[SQL_API_SQLPARAMOPTIONS] = SQL_FALSE;
    exists[SQL_API_SQLDATASOURCES] = SQL_TRUE;
    exists[SQL_API_SQLPRIMARYKEYS] = SQL_TRUE;
    exists[SQL_API_SQLDESCRIBEPARAM] = SQL_TRUE;
    exists[SQL_API_SQLPROCEDURECOLUMNS] = SQL_TRUE;
    exists[SQL_API_SQLDRIVERS] = SQL_FALSE;
    exists[SQL_API_SQLPROCEDURES] = SQL_TRUE;
    exists[SQL_API_SQLEXTENDEDFETCH] = SQL_TRUE;
    exists[SQL_API_SQLSETPOS] = SQL_FALSE;
    exists[SQL_API_SQLFOREIGNKEYS] = SQL_TRUE;
    exists[SQL_API_SQLSETSCROLLOPTIONS] = SQL_TRUE;
    exists[SQL_API_SQLMORERESULTS] = SQL_TRUE;
    exists[SQL_API_SQLTABLEPRIVILEGES] = SQL_FALSE;
    exists[SQL_API_SQLNATIVESQL] = SQL_TRUE;
    if (func == SQL_API_ALL_FUNCTIONS) {
	memcpy(flags, exists, sizeof (exists));
    } else if (func == SQL_API_ODBC3_ALL_FUNCTIONS) {
	int i;
#define SET_EXISTS(x) \
	flags[(x) >> 4] |= (1 << ((x) & 0xF))
#define CLR_EXISTS(x) \
	flags[(x) >> 4] &= ~(1 << ((x) & 0xF))

	memset(flags, 0,
	       sizeof (SQLUSMALLINT) * SQL_API_ODBC3_ALL_FUNCTIONS_SIZE);
	for (i = 0; i < array_size(exists); i++) {
	    if (exists[i]) {
		flags[i >> 4] |= (1 << (i & 0xF));
	    }
	}
	SET_EXISTS(SQL_API_SQLALLOCHANDLE);
	SET_EXISTS(SQL_API_SQLFREEHANDLE);
	SET_EXISTS(SQL_API_SQLGETSTMTATTR);
	SET_EXISTS(SQL_API_SQLSETSTMTATTR);
	SET_EXISTS(SQL_API_SQLGETCONNECTATTR);
	SET_EXISTS(SQL_API_SQLSETCONNECTATTR);
	SET_EXISTS(SQL_API_SQLGETENVATTR);
	SET_EXISTS(SQL_API_SQLSETENVATTR);
	SET_EXISTS(SQL_API_SQLCLOSECURSOR);
	SET_EXISTS(SQL_API_SQLBINDPARAM);
#if !defined(HAVE_UNIXODBC) || !HAVE_UNIXODBC
	/*
	 * Some unixODBC versions have problems with
	 * SQLError() vs. SQLGetDiagRec() with loss
	 * of error/warning messages.
	 */
	SET_EXISTS(SQL_API_SQLGETDIAGREC);
#endif
	SET_EXISTS(SQL_API_SQLFETCHSCROLL);
	SET_EXISTS(SQL_API_SQLENDTRAN);
    } else {
	if (func < array_size(exists)) {
	    *flags = exists[func];
	} else {
	    switch (func) {
	    case SQL_API_SQLALLOCHANDLE:
	    case SQL_API_SQLFREEHANDLE:
	    case SQL_API_SQLGETSTMTATTR:
	    case SQL_API_SQLSETSTMTATTR:
	    case SQL_API_SQLGETCONNECTATTR:
	    case SQL_API_SQLSETCONNECTATTR:
	    case SQL_API_SQLGETENVATTR:
	    case SQL_API_SQLSETENVATTR:
	    case SQL_API_SQLCLOSECURSOR:
	    case SQL_API_SQLBINDPARAM:
#if !defined(HAVE_UNIXODBC) || !HAVE_UNIXODBC
	    /*
	     * Some unixODBC versions have problems with
	     * SQLError() vs. SQLGetDiagRec() with loss
	     * of error/warning messages.
	     */
	    case SQL_API_SQLGETDIAGREC:
#endif
	    case SQL_API_SQLFETCHSCROLL:
	    case SQL_API_SQLENDTRAN:
		*flags = SQL_TRUE;
		break;
	    default:
		*flags = SQL_FALSE;
	    }
	}
    }
    return SQL_SUCCESS;
}

/**
 * Internal allocate HENV.
 * @param env pointer to environment handle
 * @result ODBC error code
 */

static SQLRETURN
drvallocenv(SQLHENV *env)
{
    ENV *e;

    if (env == NULL) {
	return SQL_INVALID_HANDLE;
    }
    e = (ENV *) xmalloc(sizeof (ENV));
    if (e == NULL) {
	*env = SQL_NULL_HENV;
	return SQL_ERROR;
    }
    e->magic = ENV_MAGIC;
    e->ov3 = 0;
    e->dbcs = NULL;
    *env = (SQLHENV) e;
    return SQL_SUCCESS;
}

/**
 * Allocate HENV.
 * @param env pointer to environment handle
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLAllocEnv(SQLHENV *env)
{
    return drvallocenv(env);
}

/**
 * Internal free HENV.
 * @param env environment handle
 * @result ODBC error code
 */

static SQLRETURN
drvfreeenv(SQLHENV env)
{
    ENV *e;

    if (env == SQL_NULL_HENV) {
	return SQL_INVALID_HANDLE;
    }
    e = (ENV *) env;
    if (e->magic != ENV_MAGIC) {
	return SQL_SUCCESS;
    }
    if (e->dbcs) {
	return SQL_ERROR;
    }
    e->magic = DEAD_MAGIC;
    xfree(e);
    return SQL_SUCCESS;
}

/**
 * Free HENV.
 * @param env environment handle
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLFreeEnv(SQLHENV env)
{
    return drvfreeenv(env);
}

/**
 * Internal allocate HDBC.
 * @param env environment handle
 * @param dbc pointer to database connection handle
 * @result ODBC error code
 */

static SQLRETURN
drvallocconnect(SQLHENV env, SQLHDBC *dbc)
{
    DBC *d;
    ENV *e;
    const char *verstr;
    int maj = 0, min = 0, lev = 0;

    if (dbc == NULL) {
	return SQL_ERROR;
    }
    d = (DBC *) xmalloc(sizeof (DBC));
    if (d == NULL) {
	*dbc = SQL_NULL_HDBC;
	return SQL_ERROR;
    }
    memset(d, 0, sizeof (DBC));
    d->curtype = SQL_CURSOR_STATIC;
    d->ov3 = &d->ov3val;
    e = (ENV *) env;
    if (e->magic == ENV_MAGIC) {
	DBC *n, *p;

	d->env = e;
	d->ov3 = &e->ov3;
	p = NULL;
	n = e->dbcs;
	while (n) {
	    p = n;
	    n = n->next;
	}
	if (p) {
	    p->next = d;
	} else {
	    e->dbcs = d;
	}
    }
    d->autocommit = 1;
    d->magic = DBC_MAGIC;
    *dbc = (SQLHDBC) d;
    drvgetgpps(d);
    return SQL_SUCCESS;
}

/**
 * Allocate HDBC.
 * @param env environment handle
 * @param dbc pointer to database connection handle
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLAllocConnect(SQLHENV env, SQLHDBC *dbc)
{
    return drvallocconnect(env, dbc);
}

/**
 * Internal free connection (HDBC).
 * @param dbc database connection handle
 * @result ODBC error code
 */

static SQLRETURN
drvfreeconnect(SQLHDBC dbc)
{
    DBC *d;
    ENV *e;

    if (dbc == SQL_NULL_HDBC) {
	return SQL_INVALID_HANDLE;
    }
    d = (DBC *) dbc;
    if (d->magic != DBC_MAGIC) {
	return SQL_INVALID_HANDLE;
    }
    if (d->sqlite) {
	setstatd(d, -1, "not disconnected", (*d->ov3) ? "HY000" : "S1000");
	return SQL_ERROR;
    }
    while (d->stmt) {
	freestmt((HSTMT) d->stmt);
    }
    e = d->env;
    if (e && e->magic == ENV_MAGIC) {
	DBC *n, *p;

	p = NULL;
	n = e->dbcs;
	while (n) {
	    if (n == d) {
		break;
	    }
	    p = n;
	    n = n->next;
	}
	if (n) {
	    if (p) {
		p->next = d->next;
	    } else {
		e->dbcs = d->next;
	    }
	}
    }
    drvrelgpps(d);
    d->magic = DEAD_MAGIC;
    if (d->trace) {
	fclose(d->trace);
    }
    xfree(d);
    return SQL_SUCCESS;
}

/**
 * Free connection (HDBC).
 * @param dbc database connection handle
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLFreeConnect(SQLHDBC dbc)
{
    return drvfreeconnect(dbc);
}

/**
 * Internal get connect attribute of HDBC.
 * @param dbc database connection handle
 * @param attr option to be retrieved
 * @param val output buffer
 * @param bufmax size of output buffer
 * @param buflen output length
 * @result ODBC error code
 */

static SQLRETURN
drvgetconnectattr(SQLHDBC dbc, SQLINTEGER attr, SQLPOINTER val,
		  SQLINTEGER bufmax, SQLINTEGER *buflen)
{
    DBC *d;
    SQLINTEGER dummy;

    if (dbc == SQL_NULL_HDBC) {
	return SQL_INVALID_HANDLE;
    }
    d = (DBC *) dbc;
    if (!val) {
	val = (SQLPOINTER) &dummy;
    }
    if (!buflen) {
	buflen = &dummy;
    }
    switch (attr) {
    case SQL_ATTR_CONNECTION_DEAD:
	*((SQLINTEGER *) val) = d->sqlite ? SQL_CD_FALSE : SQL_CD_TRUE;
	*buflen = sizeof (SQLINTEGER);
	break;
    case SQL_ATTR_ACCESS_MODE:
	*((SQLINTEGER *) val) = SQL_MODE_READ_WRITE;
	*buflen = sizeof (SQLINTEGER);
	break;
    case SQL_ATTR_AUTOCOMMIT:
	*((SQLINTEGER *) val) =
	    d->autocommit ? SQL_AUTOCOMMIT_ON : SQL_AUTOCOMMIT_OFF;
	*buflen = sizeof (SQLINTEGER);
	break;
    case SQL_ATTR_LOGIN_TIMEOUT:
	*((SQLINTEGER *) val) = 100;
	*buflen = sizeof (SQLINTEGER);
	break;
    case SQL_ATTR_ODBC_CURSORS:
	*((SQLINTEGER *) val) = SQL_CUR_USE_DRIVER;
	*buflen = sizeof (SQLINTEGER);
	break;
    case SQL_ATTR_PACKET_SIZE:
	*((SQLINTEGER *) val) = 16384;
	*buflen = sizeof (SQLINTEGER);
	break;
    case SQL_ATTR_TXN_ISOLATION:
	*((SQLINTEGER *) val) = SQL_TXN_READ_UNCOMMITTED;
	*buflen = sizeof (SQLINTEGER);
	break;
    case SQL_ATTR_TRACE:
    case SQL_ATTR_TRACEFILE:
    case SQL_ATTR_QUIET_MODE:
    case SQL_ATTR_TRANSLATE_OPTION:
    case SQL_ATTR_KEYSET_SIZE:
    case SQL_ATTR_QUERY_TIMEOUT:
    case SQL_ATTR_PARAM_BIND_TYPE:
    case SQL_ATTR_CURRENT_CATALOG:
	*((SQLINTEGER *) val) = 0;
	*buflen = sizeof (SQLINTEGER);
	break;
    case SQL_ATTR_ROW_BIND_TYPE:
	*((SQLUINTEGER *) val) = SQL_BIND_BY_COLUMN;
	*buflen = sizeof (SQLUINTEGER);
	break;
    case SQL_ATTR_USE_BOOKMARKS:
	*((SQLINTEGER *) val) = SQL_UB_OFF;
	*buflen = sizeof (SQLINTEGER);
	break;
    case SQL_ATTR_ASYNC_ENABLE:
	*((SQLINTEGER *) val) = SQL_ASYNC_ENABLE_OFF;
	*buflen = sizeof (SQLINTEGER);
	break;
    case SQL_ATTR_NOSCAN:
	*((SQLINTEGER *) val) = SQL_NOSCAN_ON;
	*buflen = sizeof (SQLINTEGER);
	break;
    case SQL_ATTR_CONCURRENCY:
	*((SQLINTEGER *) val) = SQL_CONCUR_LOCK;
	*buflen = sizeof (SQLINTEGER);
	break;
    case SQL_ATTR_SIMULATE_CURSOR:
	*((SQLINTEGER *) val) = SQL_SC_NON_UNIQUE;
	*buflen = sizeof (SQLINTEGER);
	break;
    case SQL_ATTR_MAX_ROWS:
    case SQL_ATTR_MAX_LENGTH:
	*((SQLINTEGER *) val) = 1000000000;
	*buflen = sizeof (SQLINTEGER);
	break;
    case SQL_ATTR_CURSOR_TYPE:
	*((SQLINTEGER *) val) = d->curtype;
	*buflen = sizeof (SQLINTEGER);
	break;
    case SQL_ATTR_RETRIEVE_DATA:
	*((SQLINTEGER *) val) = SQL_RD_ON;
	*buflen = sizeof (SQLINTEGER);
	break;
    default:
	*((SQLINTEGER *) val) = 0;
	*buflen = sizeof (SQLINTEGER);
	setstatd(d, -1, "unsupported connect attribute %d",
		 (*d->ov3) ? "HYC00" : "S1C00", (int) attr);
	return SQL_ERROR;
    }
    return SQL_SUCCESS;
}

/**
 * Get connect attribute of HDBC.
 * @param dbc database connection handle
 * @param attr option to be retrieved
 * @param val output buffer
 * @param bufmax size of output buffer
 * @param buflen output length
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLGetConnectAttr(SQLHDBC dbc, SQLINTEGER attr, SQLPOINTER val,
		  SQLINTEGER bufmax, SQLINTEGER *buflen)
{
    return drvgetconnectattr(dbc, attr, val, bufmax, buflen);
}

/**
 * Internal set connect attribute of HDBC.
 * @param dbc database connection handle
 * @param attr option to be set
 * @param val option value
 * @param len size of option
 * @result ODBC error code
 */

static SQLRETURN
drvsetconnectattr(SQLHDBC dbc, SQLINTEGER attr, SQLPOINTER val,
		  SQLINTEGER len)
{
    DBC *d;

    if (dbc == SQL_NULL_HDBC) {
	return SQL_INVALID_HANDLE;
    }
    d = (DBC *) dbc;
    switch (attr) {
    case SQL_AUTOCOMMIT:
	if (len == SQL_IS_INTEGER) {
	    d->autocommit = (SQLINTEGER) val == SQL_AUTOCOMMIT_ON;
	    goto doit;
	}
	if (val && len >= sizeof (SQLINTEGER)) {
	    d->autocommit = *((SQLINTEGER *) val) == SQL_AUTOCOMMIT_ON;
doit:
	    if (d->autocommit && d->intrans) {
		return endtran(d, SQL_COMMIT);
	    } else if (!d->autocommit) {
		s3stmt_end(d->cur_s3stmt);
	    }
	}
	break;
    default:
	setstatd(d, -1, "option value changed", "01S02");
	return SQL_SUCCESS_WITH_INFO;
    }
    return SQL_SUCCESS;
}

/**
 * Set connect attribute of HDBC.
 * @param dbc database connection handle
 * @param attr option to be set
 * @param val option value
 * @param len size of option
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLSetConnectAttr(SQLHDBC dbc, SQLINTEGER attr, SQLPOINTER val,
		  SQLINTEGER len)
{
    return drvsetconnectattr(dbc, attr, val, len);
}

/**
 * Internal get connect option of HDBC.
 * @param dbc database connection handle
 * @param opt option to be retrieved
 * @param param output buffer
 * @result ODBC error code
 */

static SQLRETURN
drvgetconnectoption(SQLHDBC dbc, SQLUSMALLINT opt, SQLPOINTER param)
{
    DBC *d;
    SQLINTEGER dummy;

    if (dbc == SQL_NULL_HDBC) {
	return SQL_INVALID_HANDLE;
    }
    d = (DBC *) dbc;
    if (!param) {
	param = (SQLPOINTER) &dummy;
    }
    switch (opt) {
    case SQL_ACCESS_MODE:
	*((SQLINTEGER *) param) = SQL_MODE_READ_WRITE;
	break;
    case SQL_AUTOCOMMIT:
	*((SQLINTEGER *) param) =
	    d->autocommit ? SQL_AUTOCOMMIT_ON : SQL_AUTOCOMMIT_OFF;
	break;
    case SQL_LOGIN_TIMEOUT:
	*((SQLINTEGER *) param) = 100;
	break;
    case SQL_ODBC_CURSORS:
	*((SQLINTEGER *) param) = SQL_CUR_USE_DRIVER;
	break;
    case SQL_PACKET_SIZE:
	*((SQLINTEGER *) param) = 16384;
	break;
    case SQL_TXN_ISOLATION:
	*((SQLINTEGER *) param) = SQL_TXN_READ_UNCOMMITTED;
	break;
    case SQL_OPT_TRACE:
    case SQL_OPT_TRACEFILE:
    case SQL_QUIET_MODE:
    case SQL_TRANSLATE_DLL:
    case SQL_TRANSLATE_OPTION:
    case SQL_KEYSET_SIZE:
    case SQL_QUERY_TIMEOUT:
    case SQL_BIND_TYPE:
    case SQL_CURRENT_QUALIFIER:
	*((SQLINTEGER *) param) = 0;
	break;
    case SQL_USE_BOOKMARKS:
	*((SQLINTEGER *) param) = SQL_UB_OFF;
	break;
    case SQL_ASYNC_ENABLE:
	*((SQLINTEGER *) param) = SQL_ASYNC_ENABLE_OFF;
	break;
    case SQL_NOSCAN:
	*((SQLINTEGER *) param) = SQL_NOSCAN_ON;
	break;
    case SQL_CONCURRENCY:
	*((SQLINTEGER *) param) = SQL_CONCUR_LOCK;
	break;
    case SQL_SIMULATE_CURSOR:
	*((SQLINTEGER *) param) = SQL_SC_NON_UNIQUE;
	break;
    case SQL_ROWSET_SIZE:
    case SQL_MAX_ROWS:
    case SQL_MAX_LENGTH:
	*((SQLINTEGER *) param) = 1000000000;
	break;
    case SQL_CURSOR_TYPE:
	*((SQLINTEGER *) param) = d->curtype;
	break;
    case SQL_RETRIEVE_DATA:
	*((SQLINTEGER *) param) = SQL_RD_ON;
	break;
    default:
	*((SQLINTEGER *) param) = 0;
	setstatd(d, -1, "unsupported connect option %d",
		 (*d->ov3) ? "HYC00" : "S1C00", opt);
	return SQL_ERROR;
    }
    return SQL_SUCCESS;
}

/**
 * Get connect option of HDBC.
 * @param dbc database connection handle
 * @param opt option to be retrieved
 * @param param output buffer
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLGetConnectOption(SQLHDBC dbc, SQLUSMALLINT opt, SQLPOINTER param)
{
    return drvgetconnectoption(dbc, opt, param);
}

/**
 * Internal set option on HDBC.
 * @param dbc database connection handle
 * @param opt option to be set
 * @param param option value
 * @result ODBC error code
 */

static SQLRETURN
drvsetconnectoption(SQLHDBC dbc, SQLUSMALLINT opt, SQLUINTEGER param)
{
    DBC *d;

    if (dbc == SQL_NULL_HDBC) {
	return SQL_INVALID_HANDLE;
    }
    d = (DBC *) dbc;
    switch (opt) {
    case SQL_AUTOCOMMIT:
	d->autocommit = param == SQL_AUTOCOMMIT_ON;
	if (d->autocommit && d->intrans) {
	    return endtran(d, SQL_COMMIT);
	} else if (!d->autocommit) {
	    s3stmt_end(d->cur_s3stmt);
	}
	break;
    default:
	setstatd(d, -1, "option value changed", "01S02");
	return SQL_SUCCESS_WITH_INFO;
    }
    return SQL_SUCCESS;
}

/**
 * Set option on HDBC.
 * @param dbc database connection handle
 * @param opt option to be set
 * @param param option value
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLSetConnectOption(SQLHDBC dbc, SQLUSMALLINT opt, SQLUINTEGER param)
{
    return drvsetconnectoption(dbc, opt, param);
}

#if defined(WITHOUT_DRIVERMGR) || !defined(_WIN32)

/**
 * Handling of SQLConnect() connection attributes
 * for standalone operation without driver manager.
 * @param dsn DSN/driver connection string
 * @param attr attribute string to be retrieved
 * @param out output buffer
 * @param outLen length of output buffer
 * @result true or false
 */

static int
getdsnattr(char *dsn, char *attr, char *out, int outLen)
{
    char *str = dsn, *start;
    int len = strlen(attr);

    while (*str) {
	while (*str && *str == ';') {
	    ++str;
	}
	start = str;
	if ((str = strchr(str, '=')) == NULL) {
	    return 0;
	}
	if (str - start == len &&
#ifdef _WIN32
	    _strnicmp(start, attr, len) == 0
#else
	    strncasecmp(start, attr, len) == 0
#endif
	   ) {
	    start = ++str;
	    while (*str && *str != ';') {
		++str;
	    }
	    len = min(outLen - 1, str - start);
	    strncpy(out, start, len);
	    out[len] = '\0';
	    return 1;
	}
	while (*str && *str != ';') {
	    ++str;
	}
    }
    return 0;
}
#endif

/**
 * Internal connect to SQLite database.
 * @param dbc database connection handle
 * @param dsn DSN string
 * @param dsnLen length of DSN string or SQL_NTS
 * @result ODBC error code
 */

static SQLRETURN
drvconnect(SQLHDBC dbc, SQLCHAR *dsn, SQLSMALLINT dsnLen)
{
    DBC *d;
    int len;
    char buf[SQL_MAX_MESSAGE_LENGTH], dbname[SQL_MAX_MESSAGE_LENGTH / 4];
    char busy[SQL_MAX_MESSAGE_LENGTH / 4], tracef[SQL_MAX_MESSAGE_LENGTH];
    char sflag[32];

    if (dbc == SQL_NULL_HDBC) {
	return SQL_INVALID_HANDLE;
    }
    d = (DBC *) dbc;
    if (d->magic != DBC_MAGIC) {
	return SQL_INVALID_HANDLE;
    }
    if (d->sqlite != NULL) {
	setstatd(d, -1, "connection already established", "08002");
	return SQL_ERROR;
    }
    buf[0] = '\0';
    if (dsnLen == SQL_NTS) {
	len = sizeof (buf) - 1;
    } else {
	len = min(sizeof (buf) - 1, dsnLen);
    }
    if (dsn != NULL) {
	strncpy(buf, dsn, len);
    }
    buf[len] = '\0';
    if (buf[0] == '\0') {
	setstatd(d, -1, "invalid DSN", (*d->ov3) ? "HY090" : "S1090");
	return SQL_ERROR;
    }
    busy[0] = '\0';
    dbname[0] = '\0';
#ifdef WITHOUT_DRIVERMGR
    getdsnattr(buf, "database", dbname, sizeof (dbname));
    if (dbname[0] == '\0') {
	strncpy(dbname, buf, sizeof (dbname));
	dbname[sizeof (dbname) - 1] = '\0';
    }
    getdsnattr(buf, "timeout", busy, sizeof (busy));
    sflag[0] = '\0';
    // Aubit: looks unused - nwflag[0] = '\0';
    getdsnattr(buf, "stepapi", sflag, sizeof (sflag));
#else
    SQLGetPrivateProfileString(buf, "timeout", "1000",
			       busy, sizeof (busy), ODBC_INI);
    SQLGetPrivateProfileString(buf, "database", "",
			       dbname, sizeof (dbname), ODBC_INI);
    SQLGetPrivateProfileString(buf, "stepapi", "",
			       sflag, sizeof (sflag), ODBC_INI);
#endif
    tracef[0] = '\0';
#ifdef WITHOUT_DRIVERMGR
    getdsnattr(buf, "tracefile", tracef, sizeof (tracef));
#else
    SQLGetPrivateProfileString(buf, "tracefile", "",
			       tracef, sizeof (tracef), ODBC_INI);
#endif
    if (tracef[0] != '\0') {
	d->trace = fopen(tracef, "a");
    }
    return dbopen(d, dbname, dsn, sflag, busy);
}

/**
 * Connect to SQLite database.
 * @param dbc database connection handle
 * @param dsn DSN string
 * @param dsnLen length of DSN string or SQL_NTS
 * @param uid user id string or NULL
 * @param uidLen length of user id string or SQL_NTS
 * @param pass password string or NULL
 * @param passLen length of password string or SQL_NTS
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLConnect(SQLHDBC dbc, SQLCHAR *dsn, SQLSMALLINT dsnLen,
	   SQLCHAR *uid, SQLSMALLINT uidLen,
	   SQLCHAR *pass, SQLSMALLINT passLen)
{
    return drvconnect(dbc, dsn, dsnLen);
}

/**
 * Disconnect given HDBC.
 * @param dbc database connection handle
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLDisconnect(SQLHDBC dbc)
{
    DBC *d;

    if (dbc == SQL_NULL_HDBC) {
	return SQL_INVALID_HANDLE;
    }
    d = (DBC *) dbc;
    if (d->magic != DBC_MAGIC) {
	return SQL_INVALID_HANDLE;
    }
    if (d->intrans) {
	setstatd(d, -1, "incomplete transaction", "25000");
	return SQL_ERROR;
    }
    if (d->cur_s3stmt) {
	s3stmt_end(d->cur_s3stmt);
    }
    if (d->sqlite) {
	sqlite3_close(d->sqlite);
	d->sqlite = NULL;
    }
    freep(&d->dbname);
    freep(&d->dsn);
    return SQL_SUCCESS;
}

#if defined(WITHOUT_DRIVERMGR) || !defined(_WIN32)

/**
 * Internal standalone (w/o driver manager) database connect.
 * @param dbc database connection handle
 * @param hwnd dummy window handle or NULL
 * @param connIn driver connect input string
 * @param connInLen length of driver connect input string or SQL_NTS
 * @param connOut driver connect output string
 * @param connOutMax length of driver connect output string
 * @param connOutLen output length of driver connect output string
 * @param drvcompl completion type
 * @result ODBC error code
 */

static SQLRETURN
drvdriverconnect(SQLHDBC dbc, SQLHWND hwnd,
		 SQLCHAR *connIn, SQLSMALLINT connInLen,
		 SQLCHAR *connOut, SQLSMALLINT connOutMax,
		 SQLSMALLINT *connOutLen, SQLUSMALLINT drvcompl)
{
    DBC *d;
    int len;
    char buf[SQL_MAX_MESSAGE_LENGTH], dbname[SQL_MAX_MESSAGE_LENGTH / 4];
    char dsn[SQL_MAX_MESSAGE_LENGTH / 4], busy[SQL_MAX_MESSAGE_LENGTH / 4];
    char tracef[SQL_MAX_MESSAGE_LENGTH];
    char sflag[32];

    if (dbc == SQL_NULL_HDBC || hwnd != NULL) {
	return SQL_INVALID_HANDLE;
    }
    if (drvcompl != SQL_DRIVER_COMPLETE &&
	drvcompl != SQL_DRIVER_COMPLETE_REQUIRED &&
	drvcompl != SQL_DRIVER_PROMPT &&
	drvcompl != SQL_DRIVER_NOPROMPT) {
	return SQL_NO_DATA;
    }
    d = (DBC *) dbc;
    if (d->sqlite) {
	setstatd(d, -1, "connection already established", "08002");
	return SQL_ERROR;
    }
    buf[0] = '\0';
    if (connInLen == SQL_NTS) {
	len = sizeof (buf) - 1;
    } else {
	len = min(connInLen, sizeof (buf) - 1);
    }
    if (connIn != NULL) {
	strncpy(buf, connIn, len);
    }
    buf[len] = '\0';
    if (!buf[0]) {
	setstatd(d, -1, "invalid connect attributes",
		 (*d->ov3) ? "HY090" : "S1090");
	return SQL_ERROR;
    }
    dsn[0] = '\0';
    getdsnattr(buf, "DSN", dsn, sizeof (dsn));

    /* special case: connIn is sole DSN value without keywords */
    if (!dsn[0] && !strchr(buf, ';') && !strchr(buf, '=')) {
	strncpy(dsn, buf, sizeof (dsn) - 1);
	dsn[sizeof (dsn) - 1] = '\0';
    }

    busy[0] = '\0';
    getdsnattr(buf, "timeout", busy, sizeof (busy));
#ifndef WITHOUT_DRIVERMGR
    if (dsn[0] && !busy[0]) {
	SQLGetPrivateProfileString(dsn, "timeout", "1000",
				   busy, sizeof (busy), ODBC_INI);
    }
#endif
    dbname[0] = '\0';
    getdsnattr(buf, "database", dbname, sizeof (dbname));
#ifndef WITHOUT_DRIVERMGR
    if (dsn[0] && !dbname[0]) {
	SQLGetPrivateProfileString(dsn, "database", "",
				   dbname, sizeof (dbname), ODBC_INI);
    }
#endif
    sflag[0] = '\0';
    getdsnattr(buf, "stepapi", sflag, sizeof (sflag));
#ifndef WITHOUT_DRIVERMGR
    if (dsn[0] && !sflag[0]) {
	SQLGetPrivateProfileString(dsn, "stepapi", "",
				   sflag, sizeof (sflag), ODBC_INI);
    }
#endif
    if (!dbname[0] && !dsn[0]) {
	strcpy(dsn, "SQLite");
	strncpy(dbname, buf, sizeof (dbname));
	dbname[sizeof (dbname) - 1] = '\0';
    }
    tracef[0] = '\0';
    getdsnattr(buf, "tracefile", tracef, sizeof (tracef));
#ifndef WITHOUT_DRIVERMGR
    if (dsn[0] && !tracef[0]) {
	SQLGetPrivateProfileString(dsn, "tracefile", "",
				   tracef, sizeof (tracef), ODBC_INI);
    }
#endif
    if (connOut || connOutLen) {
	int count;

	buf[0] = '\0';
	count = snprintf(buf, sizeof (buf),
			 "DSN=%s;Database=%s;StepAPI=%s;Timeout=%s;"
			 "Tracefile=%s",
			 dsn, dbname, sflag, busy, tracef);
	if (count < 0) {
	    buf[sizeof (buf) - 1] = '\0';
	}
	len = min(connOutMax - 1, strlen(buf));
	if (connOut) {
	    strncpy(connOut, buf, len);
	    connOut[len] = '\0';
	}
	if (connOutLen) {
	    *connOutLen = len;
	}
    }
    if (tracef[0] != '\0') {
	d->trace = fopen(tracef, "a");
    }
    return dbopen(d, dbname, dsn, sflag, busy);
}
#endif

/* see doc on top */

static SQLRETURN
freestmt(SQLHSTMT stmt)
{
    STMT *s;
    DBC *d;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    freeresult(s, 1);
    freep(&s->query);
    d = (DBC *) s->dbc;
    if (d && d->magic == DBC_MAGIC) {
	STMT *p, *n;

	p = NULL;
	n = d->stmt;
	while (n) {
	    if (n == s) {
		break;
	    }
	    p = n;
	    n = n->next;
	}
	if (n) {
	    if (p) {
		p->next = s->next;
	    } else {
		d->stmt = s->next;
	    }
	}
    }
    freeparams(s);
    freep(&s->bindparms);
    if (s->row_status0 != &s->row_status1) {
	freep(&s->row_status0);
	s->rowset_size = 1;
	s->row_status0 = &s->row_status1;
    }
    xfree(s);
    return SQL_SUCCESS;
}

/**
 * Allocate HSTMT given HDBC (driver internal version).
 * @param dbc database connection handle
 * @param stmt pointer to statement handle
 * @result ODBC error code
 */

static SQLRETURN
drvallocstmt(SQLHDBC dbc, SQLHSTMT *stmt)
{
    DBC *d;
    STMT *s, *sl, *pl;

    if (dbc == SQL_NULL_HDBC) {
	return SQL_INVALID_HANDLE;
    }
    d = (DBC *) dbc;
    if (d->magic != DBC_MAGIC || stmt == NULL) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) xmalloc(sizeof (STMT));
    if (s == NULL) {
	*stmt = SQL_NULL_HSTMT;
	return SQL_ERROR;
    }
    *stmt = (SQLHSTMT) s;
    memset(s, 0, sizeof (STMT));
    s->dbc = dbc;
    s->ov3 = d->ov3;
    s->curtype = d->curtype;
    s->row_status0 = &s->row_status1;
    s->rowset_size = 1;
    s->retr_data = SQL_RD_ON;
    s->bind_type = SQL_BIND_BY_COLUMN;
    s->bind_offs = NULL;
    s->paramset_size = 1;
    sprintf(s->cursorname, "CUR_%08lX", (long) *stmt);
    sl = d->stmt;
    pl = NULL;
    while (sl) {
	pl = sl;
	sl = sl->next;
    }
    if (pl) {
	pl->next = s;
    } else {
	d->stmt = s;
    }
    return SQL_SUCCESS;
}

/**
 * Allocate HSTMT given HDBC.
 * @param dbc database connection handle
 * @param stmt pointer to statement handle
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLAllocStmt(SQLHDBC dbc, SQLHSTMT *stmt)
{
    return drvallocstmt(dbc, stmt);
}

/**
 * Internal function to perform certain kinds of free/close on STMT.
 * @param stmt statement handle
 * @param opt SQL_RESET_PARAMS, SQL_UNBIND, SQL_CLOSE, or SQL_DROP
 * @result ODBC error code
 */

static SQLRETURN
drvfreestmt(SQLHSTMT stmt, SQLUSMALLINT opt)
{
    STMT *s;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    switch (opt) {
    case SQL_RESET_PARAMS:
	freeparams(s);
	break;
    case SQL_UNBIND:
	unbindcols(s);
	break;
    case SQL_CLOSE:
	s3stmt_end_if(s);
	freeresult(s, 0);
	break;
    case SQL_DROP:
	s3stmt_end_if(s);
	return freestmt(stmt);
    default:
	setstat(s, -1, "unsupported option", (*s->ov3) ? "HYC00" : "S1C00");
	return SQL_ERROR;
    }
    return SQL_SUCCESS;
}

/**
 * Free HSTMT.
 * @param stmt statement handle
 * @param opt SQL_RESET_PARAMS, SQL_UNBIND, SQL_CLOSE, or SQL_DROP
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLFreeStmt(SQLHSTMT stmt, SQLUSMALLINT opt)
{
    return drvfreestmt(stmt, opt);
}

/**
 * Cancel HSTMT closing cursor.
 * @param stmt statement handle
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLCancel(SQLHSTMT stmt)
{
    return drvfreestmt(stmt, SQL_CLOSE);
}

/**
 * Internal function to get cursor name of STMT.
 * @param stmt statement handle
 * @param cursor output buffer
 * @param buflen length of output buffer
 * @param lenp output length
 * @result ODBC error code
 */

static SQLRETURN
drvgetcursorname(SQLHSTMT stmt, SQLCHAR *cursor, SQLSMALLINT buflen,
		 SQLSMALLINT *lenp)
{
    STMT *s;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    if (lenp && !cursor) {
	*lenp = strlen(s->cursorname);
	return SQL_SUCCESS;
    }
    if (cursor) {
	if (buflen > 0) {
	    strncpy(cursor, s->cursorname, buflen - 1);
	    cursor[buflen - 1] = '\0';
	}
	if (lenp) {
	    *lenp = min(strlen(s->cursorname), buflen - 1);
	}
    }
    return SQL_SUCCESS;
}

/**
 * Get cursor name of STMT.
 * @param stmt statement handle
 * @param cursor output buffer
 * @param buflen length of output buffer
 * @param lenp output length
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLGetCursorName(SQLHSTMT stmt, SQLCHAR *cursor, SQLSMALLINT buflen,
		 SQLSMALLINT *lenp)
{
    return drvgetcursorname(stmt, cursor, buflen, lenp);
}

/**
 * Internal function to set cursor name on STMT.
 * @param stmt statement handle
 * @param cursor new cursor name
 * @param len length of cursor name or SQL_NTS
 * @result ODBC error code
 */

static SQLRETURN
drvsetcursorname(SQLHSTMT stmt, SQLCHAR *cursor, SQLSMALLINT len)
{
    STMT *s;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    if (!cursor ||
	!((cursor[0] >= 'A' && cursor[0] <= 'Z') ||
	  (cursor[0] >= 'a' && cursor[0] <= 'z'))) {
	setstat(s, -1, "invalid cursor name", (*s->ov3) ? "HYC00" : "S1C00");
	return SQL_ERROR;
    }
    if (len == SQL_NTS) {
	len = sizeof (s->cursorname) - 1;
    } else {
	len = min(sizeof (s->cursorname) - 1, len);
    }
    strncpy(s->cursorname, cursor, len);
    s->cursorname[len] = '\0';
    return SQL_SUCCESS;
}

/**
 * Set cursor name on STMT.
 * @param stmt statement handle
 * @param cursor new cursor name
 * @param len length of cursor name or SQL_NTS
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLSetCursorName(SQLHSTMT stmt, SQLCHAR *cursor, SQLSMALLINT len)
{
    return drvsetcursorname(stmt, cursor, len);
}

/**
 * Close open cursor.
 * @param stmt statement handle
 * @return ODBC error code
 */

SQLRETURN SQL_API
SQLCloseCursor(SQLHSTMT stmt)
{
    return drvfreestmt(stmt, SQL_CLOSE);
}

#if defined(WITHOUT_DRIVERMGR) || !defined(HAVE_IODBC) || defined(_WIN32)

/**
 * Allocate a HENV, HDBC, or HSTMT handle.
 * @param type handle type
 * @param input input handle (HENV, HDBC)
 * @param output pointer to output handle (HENV, HDBC, HSTMT)
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLAllocHandle(SQLSMALLINT type, SQLHANDLE input, SQLHANDLE *output)
{
    SQLRETURN ret;

    switch (type) {
    case SQL_HANDLE_ENV:
	ret = drvallocenv((SQLHENV *) output);
	if (ret == SQL_SUCCESS) {
	    ENV *e = (ENV *) *output;

	    if (e && e->magic == ENV_MAGIC) {
		e->ov3 = 1;
	    }
	}
	return ret;
    case SQL_HANDLE_DBC:
	return drvallocconnect((SQLHENV) input, (SQLHDBC *) output);
    case SQL_HANDLE_STMT:
	return drvallocstmt((SQLHDBC) input, (SQLHSTMT *) output);
    }
    return SQL_ERROR;
}
#endif

#if defined(WITHOUT_DRIVERMGR) || !defined(HAVE_IODBC) || defined(_WIN32)

/**
 * Free a HENV, HDBC, or HSTMT handle.
 * @param type handle type
 * @param h handle (HENV, HDBC, or HSTMT)
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLFreeHandle(SQLSMALLINT type, SQLHANDLE h)
{
    switch (type) {
    case SQL_HANDLE_ENV:
	return drvfreeenv((SQLHENV) h);
    case SQL_HANDLE_DBC:
	return drvfreeconnect((SQLHDBC) h);
    case SQL_HANDLE_STMT:
	return drvfreestmt((SQLHSTMT) h, SQL_DROP);
    }
    return SQL_ERROR;
}
#endif

/**
 * Free dynamically allocated column information in STMT.
 * @param s statement pointer
 */

static void
freedyncols(STMT *s)
{
    if (s->dyncols) {
	int i;

	for (i = 0; i < s->dcols; i++) {
	    freep(&s->dyncols[i].typename);
	}
	if (s->cols == s->dyncols) {
	    s->cols = NULL;
	    s->ncols = 0;
	}
	freep(&s->dyncols);
    }
    s->dcols = 0;
}

/* see doc on top */

static void
freeresult(STMT *s, int clrcols)
{
    if (s->rows) {
	if (s->rowfree) {
	    s->rowfree(s->rows);
	    s->rowfree = NULL;
	}
	s->rows = NULL;
    }
    s->nrows = -1;
    if (clrcols > 0) {
	freep(&s->bindcols);
	s->nbindcols = 0;
    }
    if (clrcols) {
	freedyncols(s);
	s->cols = NULL;
	s->ncols = 0;
    }
}

/* see doc on top */

static void
unbindcols(STMT *s)
{
    int i;

    s->bkmrkcol.type = -1;
    s->bkmrkcol.max = 0;
    s->bkmrkcol.lenp = NULL;
    s->bkmrkcol.valp = NULL;
    s->bkmrkcol.index = 0;
    s->bkmrkcol.offs = 0;
    for (i = 0; s->bindcols && i < s->nbindcols; i++) {
	s->bindcols[i].type = -1;
	s->bindcols[i].max = 0;
	s->bindcols[i].lenp = NULL;
	s->bindcols[i].valp = NULL;
	s->bindcols[i].index = i;
	s->bindcols[i].offs = 0;
    }
}

/* see doc on top */

static SQLRETURN
mkbindcols(STMT *s, int ncols)
{
    if (s->bindcols) {
	if (s->nbindcols < ncols) {
	    int i;
	    BINDCOL *bindcols =
		xrealloc(s->bindcols, ncols * sizeof (BINDCOL));

	    if (!bindcols) {
		return nomem(s);
	    }
	    for (i = s->nbindcols; i < ncols; i++) {
		bindcols[i].type = -1;
		bindcols[i].max = 0;
		bindcols[i].lenp = NULL;
		bindcols[i].valp = NULL;
		bindcols[i].index = i;
		bindcols[i].offs = 0;
	    }
	    s->bindcols = bindcols;
	    s->nbindcols = ncols;
	}
    } else if (ncols > 0) {
	s->bindcols = (BINDCOL *) xmalloc(ncols * sizeof (BINDCOL));
	if (!s->bindcols) {
	    return nomem(s);
	}
	s->nbindcols = ncols;
	unbindcols(s);
    }
    return SQL_SUCCESS;
}

/**
 * Internal function to retrieve row data, used by SQLFetch() and
 * friends and SQLGetData().
 * @param s statement pointer
 * @param col column number, 0 based
 * @param otype output data type
 * @param val output buffer
 * @param len length of output buffer
 * @param lenp output length
 * @param partial flag for partial data retrieval
 * @result ODBC error code
 */

static SQLRETURN
getrowdata(STMT *s, SQLUSMALLINT col, SQLSMALLINT otype,
	   SQLPOINTER val, SQLINTEGER len, SQLINTEGER *lenp, int partial)
{
    char **data, valdummy[16];
    SQLINTEGER dummy;
    int valnull = 0;
    int type = otype;

    if (!s->rows) {
	return SQL_NO_DATA;
    }
    if (col >= s->ncols) {
	setstat(s, -1, "invalid column", (*s->ov3) ? "07009" : "S1002");
	return SQL_ERROR;
    }
    if (s->rowp < 0 || s->rowp >= s->nrows) {
	return SQL_NO_DATA;
    }
    if (s->retr_data != SQL_RD_ON) {
	return SQL_SUCCESS;
    }
    type = mapdeftype(type, s->cols[col].type, s->cols[col].nosign ? 1 : 0);
    if (otype == SQL_C_CHAR) {
	switch (s->cols[col].type) {
	case SQL_BINARY:
	case SQL_VARBINARY:
	case SQL_LONGVARBINARY:
	    type = SQL_C_BINARY;
	    break;
	}
    }
    data = s->rows + s->ncols + (s->rowp * s->ncols) + col;
    if (!lenp) {
	lenp = &dummy;
    }
    if (!val) {
	valnull = 1;
	val = (SQLPOINTER) valdummy;
    }
    if (*data == NULL) {
	*lenp = SQL_NULL_DATA;
	switch (type) {
	case SQL_C_UTINYINT:
	case SQL_C_TINYINT:
	case SQL_C_STINYINT:
	    *((char *) val) = 0;
	    break;
	case SQL_C_USHORT:
	case SQL_C_SHORT:
	case SQL_C_SSHORT:
	    *((short *) val) = 0;
	    break;
	case SQL_C_ULONG:
	case SQL_C_LONG:
	case SQL_C_SLONG:
	    *((long *) val) = 0;
	    break;
	case SQL_C_FLOAT:
	    *((float *) val) = 0;
	    break;
	case SQL_C_DOUBLE:
	    *((double *) val) = 0;
	    break;
	case SQL_C_BINARY:
	case SQL_C_CHAR:
	    *((char *) val) = '\0';
	    break;
#ifdef SQL_C_TYPE_DATE
	case SQL_C_TYPE_DATE:
#endif
	case SQL_C_DATE:
	    memset((DATE_STRUCT *) val, 0, sizeof (DATE_STRUCT));
	    break;
#ifdef SQL_C_TYPE_TIME
	case SQL_C_TYPE_TIME:
#endif
	case SQL_C_TIME:
	    memset((TIME_STRUCT *) val, 0, sizeof (TIME_STRUCT));
	    break;
#ifdef SQL_C_TYPE_TIMESTAMP
	case SQL_C_TYPE_TIMESTAMP:
#endif
	case SQL_C_TIMESTAMP:
	    memset((TIMESTAMP_STRUCT *) val, 0, sizeof (TIMESTAMP_STRUCT));
	    break;
	default:
	    return SQL_ERROR;
	}
    } else {
	char *endp = NULL;

	switch (type) {
	case SQL_C_UTINYINT:
	case SQL_C_TINYINT:
	case SQL_C_STINYINT:
	    *((char *) val) = strtol(*data, &endp, 0);
	    if (endp && endp == *data) {
		*lenp = SQL_NULL_DATA;
	    } else {
		*lenp = sizeof (char);
	    }
	    break;
	case SQL_C_USHORT:
	case SQL_C_SHORT:
	case SQL_C_SSHORT:
	    *((short *) val) = strtol(*data, &endp, 0);
	    if (endp && endp == *data) {
		*lenp = SQL_NULL_DATA;
	    } else {
		*lenp = sizeof (short);
	    }
	    break;
	case SQL_C_ULONG:
	case SQL_C_LONG:
	case SQL_C_SLONG:
	    *((int *) val) = strtol(*data, &endp, 0);
	    if (endp && endp == *data) {
		*lenp = SQL_NULL_DATA;
	    } else {
		*lenp = sizeof (int);
	    }
	    break;
	case SQL_C_FLOAT:
	    *((float *) val) = ln_strtod(*data, &endp);
	    if (endp && endp == *data) {
		*lenp = SQL_NULL_DATA;
	    } else {
		*lenp = sizeof (float);
	    }
	    break;
	case SQL_C_DOUBLE:
	    *((double *) val) = ln_strtod(*data, &endp);
	    if (endp && endp == *data) {
		*lenp = SQL_NULL_DATA;
	    } else {
		*lenp = sizeof (double);
	    }
	    break;
	case SQL_C_BINARY:
	case SQL_C_CHAR: {
	    int doz;
	    int dlen = strlen(*data);
	    int offs = 0;

	    doz = type == SQL_C_CHAR ? 1 : 0;
	    if (partial && len && s->bindcols) {
		if (dlen && s->bindcols[col].offs >= dlen) {
		    s->bindcols[col].offs = 0;
		    return SQL_NO_DATA;
		}
		offs = s->bindcols[col].offs;
		dlen -= offs;
	    }
	    if (val && !valnull && len) {
		strncpy(val, *data + offs, len - doz);
	    }
	    if (valnull || len < 1) {
		*lenp = dlen;
	    } else {
		*lenp = min(len - doz, dlen);
		if (*lenp == len - doz && *lenp != dlen) {
		    *lenp = SQL_NO_TOTAL;
		}
	    }
	    if (len && !valnull && doz) {
		((char *) val)[len - 1] = '\0';
	    }
	    if (partial && len && s->bindcols) {
		if (*lenp == SQL_NO_TOTAL) {
		    s->bindcols[col].offs += len - doz;
		    setstat(s, -1, "data right truncated", "01004");
		    if (s->bindcols[col].lenp) {
			*s->bindcols[col].lenp = dlen;
		    }
		    return SQL_SUCCESS_WITH_INFO;
		}
		s->bindcols[col].offs += *lenp;
	    }
	    break;
	}
#ifdef SQL_C_TYPE_DATE
	case SQL_C_TYPE_DATE:
#endif
	case SQL_C_DATE:
	    if (str2date(*data, (DATE_STRUCT *) val) < 0) {
		*lenp = SQL_NULL_DATA;
	    } else {
		*lenp = sizeof (DATE_STRUCT);
	    }
	    break;
#ifdef SQL_C_TYPE_TIME
	case SQL_C_TYPE_TIME:
#endif
	case SQL_C_TIME:
	    if (str2time(*data, (TIME_STRUCT *) val) < 0) {
		*lenp = SQL_NULL_DATA;
	    } else {
		*lenp = sizeof (TIME_STRUCT);
	    }
	    break;
#ifdef SQL_C_TYPE_TIMESTAMP
	case SQL_C_TYPE_TIMESTAMP:
#endif
	case SQL_C_TIMESTAMP:
	    if (str2timestamp(*data, (TIMESTAMP_STRUCT *) val) < 0) {
		*lenp = SQL_NULL_DATA;
	    } else {
		*lenp = sizeof (TIMESTAMP_STRUCT);
	    }
	    break;
	default:
	    return SQL_ERROR;
	}
    }
    return SQL_SUCCESS;
}

/**
 * Bind C variable to column of result set.
 * @param stmt statement handle
 * @param col column number, starting at 1
 * @param type output type
 * @param val output buffer
 * @param max length of output buffer
 * @param lenp output length pointer
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLBindCol(SQLHSTMT stmt, SQLUSMALLINT col, SQLSMALLINT type,
	   SQLPOINTER val, SQLINTEGER max, SQLINTEGER *lenp)
{
    STMT *s;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    if (col < 1) {
	if (col == 0 && s->bkmrk && type == SQL_C_BOOKMARK) {
	    s->bkmrkcol.type = type;
	    s->bkmrkcol.max = max;
	    s->bkmrkcol.lenp = lenp;
	    s->bkmrkcol.valp = val;
	    s->bkmrkcol.offs = 0;
	    if (lenp) {
		*lenp = 0;
	    }
	    return SQL_SUCCESS;
	}
	setstat(s, -1, "invalid column", (*s->ov3) ? "07009" : "S1002");
	return SQL_ERROR;
    }
    if (mkbindcols(s, col) != SQL_SUCCESS) {
	return SQL_ERROR;
    }
    --col;
    if (type == SQL_C_DEFAULT) {
	type = mapdeftype(type, s->cols[col].type, 0);
    } else {
	switch (type) {
	case SQL_C_LONG:
	case SQL_C_ULONG:
	case SQL_C_SLONG:
	case SQL_C_TINYINT:
	case SQL_C_UTINYINT:
	case SQL_C_STINYINT:
	case SQL_C_SHORT:
	case SQL_C_USHORT:
	case SQL_C_SSHORT:
	case SQL_C_FLOAT:
	case SQL_C_DOUBLE:
	case SQL_C_TIMESTAMP:
	case SQL_C_TIME:
	case SQL_C_DATE:
	case SQL_C_CHAR:
#ifdef SQL_C_TYPE_DATE
	case SQL_C_TYPE_DATE:
#endif
#ifdef SQL_C_TYPE_TIME
	case SQL_C_TYPE_TIME:
#endif
#ifdef SQL_C_TYPE_TIMESTAMP
	case SQL_C_TYPE_TIMESTAMP:
#endif
	    break;
	case SQL_C_BINARY:
	    break;
	default:
	    setstat(s, -1, "invalid type %d", "HY003", type);
	    return SQL_ERROR;
	}
    }
    if (max < 0) {
	setstat(s, -1, "invalid length", "HY090");
	return SQL_ERROR;
    }
    s->bindcols[col].type = type;
    s->bindcols[col].max = max;
    s->bindcols[col].lenp = lenp;
    s->bindcols[col].valp = val;
    s->bindcols[col].offs = 0;
    if (lenp) {
	*lenp = 0;
    }
    return SQL_SUCCESS; 
}

/**
 * Columns for result set of SQLTables().
 */

static COL tableSpec[] = {
    { "SYSTEM", "COLUMN", "TABLE_QUALIFIER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "COLUMN", "TABLE_OWNER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "COLUMN", "TABLE_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "COLUMN", "TABLE_TYPE", SCOL_VARCHAR, 50 },
    { "SYSTEM", "COLUMN", "REMARKS", SCOL_VARCHAR, 50 }
};

/**
 * Retrieve information on tables and/or views.
 * @param stmt statement handle
 * @param cat catalog name/pattern or NULL
 * @param catLen length of catalog name/pattern or SQL_NTS
 * @param schema schema name/pattern or NULL
 * @param schemaLen length of schema name/pattern or SQL_NTS
 * @param table table name/pattern or NULL
 * @param tableLen length of table name/pattern or SQL_NTS
 * @param type types of tables string or NULL
 * @param typeLen length of types of tables string or SQL_NTS
 * @result ODBC error code
 */

static SQLRETURN
drvtables(SQLHSTMT stmt,
	  SQLCHAR *cat, SQLSMALLINT catLen,
	  SQLCHAR *schema, SQLSMALLINT schemaLen,
	  SQLCHAR *table, SQLSMALLINT tableLen,
	  SQLCHAR *type, SQLSMALLINT typeLen)
{
    SQLRETURN ret;
    STMT *s;
    DBC *d;
    int ncols, rc;
    char *errp = NULL, *sql, tname[512];
    char *where = "(type = 'table' or type = 'view')";

    ret = mkresultset(stmt, tableSpec, array_size(tableSpec));
    if (ret != SQL_SUCCESS) {
	return ret;
    }
    s = (STMT *) stmt;
    d = (DBC *) s->dbc;
    if (type && (typeLen > 0 || typeLen == SQL_NTS) && type[0] == '%') {
	int size = 3 * array_size(tableSpec);

	s->rows = xmalloc(size * sizeof (char *));
	if (!s->rows) {
	    s->nrows = 0;
	    return nomem(s);
	}
	memset(s->rows, 0, sizeof (char *) * size);
	s->ncols = array_size(tableSpec);
	s->rows[s->ncols + 0] = "";
	s->rows[s->ncols + 1] = "";
	s->rows[s->ncols + 2] = "";
	s->rows[s->ncols + 3] = "TABLE";
	s->rows[s->ncols + 5] = "";
	s->rows[s->ncols + 6] = "";
	s->rows[s->ncols + 7] = "";
	s->rows[s->ncols + 8] = "VIEW";
#ifdef MEMORY_DEBUG
	s->rowfree = xfree__;
#else
	s->rowfree = free;
#endif
	s->nrows = 2;
	s->rowp = -1;
	return SQL_SUCCESS;
    }
    if (cat && (catLen > 0 || catLen == SQL_NTS) && cat[0] == '%') {
	int size = 2 * array_size(tableSpec);

	s->rows = xmalloc(size * sizeof (char *));
	if (!s->rows) {
	    s->nrows = 0;
	    return nomem(s);
	}
	memset(s->rows, 0, sizeof (char *) * size);
	s->ncols = array_size(tableSpec);
	s->rows[s->ncols + 0] = "";
	s->rows[s->ncols + 1] = "";
	s->rows[s->ncols + 2] = d->dbname;
	s->rows[s->ncols + 3] = "CATALOG";
#ifdef MEMORY_DEBUG
	s->rowfree = xfree__;
#else
	s->rowfree = free;
#endif
	s->nrows = 1;
	s->rowp = -1;
	return SQL_SUCCESS;
    }
    if (schema && (schemaLen > 0 || schemaLen == SQL_NTS) &&
	schema[0] == '%') {
	if ((!cat || catLen == 0 || !cat[0]) &&
	    (!table || tableLen == 0 || !table[0])) {
	    int size = 2 * array_size(tableSpec);

	    s->rows = xmalloc(size * sizeof (char *));
	    if (!s->rows) {
		s->nrows = 0;
		return nomem(s);
	    }
	    memset(s->rows, 0, sizeof (char *) * size);
	    s->ncols = array_size(tableSpec);
	    s->rows[s->ncols + 1] = "";
#ifdef MEMORY_DEBUG
	    s->rowfree = xfree__;
#else
	    s->rowfree = free;
#endif
	    s->nrows = 1;
	    s->rowp = -1;
	    return SQL_SUCCESS;
	}
    }
    if (type) {
	char tmp[256], *t;
	int with_view = 0, with_table = 0;

	if (typeLen == SQL_NTS) {
	    strncpy(tmp, type, sizeof (tmp));
	    tmp[sizeof (tmp) - 1] = '\0';
	} else {
	    int len = min(sizeof (tmp) - 1, typeLen);

	    strncpy(tmp, type, len);
	    tmp[len] = '\0';
	}
	t = tmp;
	while (*t) {
	    *t = TOLOWER(*t);
	    t++;
	}
	t = tmp;
	while (t) {
	    if (t[0] == '\'') {
		++t;
	    }
	    if (strncmp(t, "table", 5) == 0) {
		with_table++;
	    } else if (strncmp(t, "view", 4) == 0) {
		with_view++;
	    }
	    t = strchr(t, ',');
	    if (t) {
		++t;
	    }
	}
	if (with_view && with_table) {
	    /* where is already preset */
	} else if (with_view && !with_table) {
	    where = "type = 'view'";
	} else if (!with_view && with_table) {
	    where = "type = 'table'";
	} else {
	    s->rowp = -1;
	    return SQL_SUCCESS;
	}
    }
    strcpy(tname, "%");
    if (table && (tableLen > 0 || tableLen == SQL_NTS) && table[0] != '%') {
	int size;

	if (tableLen == SQL_NTS) {
	    size = sizeof (tname) - 1;
	} else {
	    size = min(sizeof (tname) - 1, tableLen);
	}
	strncpy(tname, table, size);
	tname[size] = '\0';
    }
    sql = sqlite3_mprintf("select '' as 'TABLE_QUALIFIER', "
			  "'' as 'TABLE_OWNER', "
			  "tbl_name as 'TABLE_NAME', "
			  "upper(type) as 'TABLE_TYPE', "
			  "NULL as 'REMARKS' "
			  "from sqlite_master where %s "
			  "and tbl_name like '%q'", where, tname);
    if (!sql) {
	return nomem(s);
    }
    rc = sqlite3_get_table(d->sqlite, sql, &s->rows, &s->nrows, &ncols, &errp);
    sqlite3_free(sql);
    if (rc == SQLITE_OK) {
	if (ncols != s->ncols) {
	    freeresult(s, 0);
	    s->nrows = 0;
	} else {
	    s->rowfree = sqlite3_free_table;
	}
    } else {
	s->nrows = 0;
	s->rows = NULL;
	s->rowfree = NULL;
    }
    if (errp) {
	sqlite3_free(errp);
	errp = NULL;
    }
    s->rowp = -1;
    return SQL_SUCCESS;
}

/**
 * Retrieve information on tables and/or views.
 * @param stmt statement handle
 * @param cat catalog name/pattern or NULL
 * @param catLen length of catalog name/pattern or SQL_NTS
 * @param schema schema name/pattern or NULL
 * @param schemaLen length of schema name/pattern or SQL_NTS
 * @param table table name/pattern or NULL
 * @param tableLen length of table name/pattern or SQL_NTS
 * @param type types of tables string or NULL
 * @param typeLen length of types of tables string or SQL_NTS
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLTables(SQLHSTMT stmt,
	  SQLCHAR *cat, SQLSMALLINT catLen,
	  SQLCHAR *schema, SQLSMALLINT schemaLen,
	  SQLCHAR *table, SQLSMALLINT tableLen,
	  SQLCHAR *type, SQLSMALLINT typeLen)
{
    return drvtables(stmt, cat, catLen, schema, schemaLen,
		     table, tableLen, type, typeLen);
}

/**
 * Columns for result set of SQLColumns().
 */

static COL colSpec[] = {
    { "SYSTEM", "COLUMN", "TABLE_QUALIFIER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "COLUMN", "TABLE_OWNER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "COLUMN", "TABLE_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "COLUMN", "COLUMN_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "COLUMN", "DATA_TYPE", SQL_SMALLINT, 50 },
    { "SYSTEM", "COLUMN", "TYPE_NAME", SCOL_VARCHAR, 50 },
    { "SYSTEM", "COLUMN", "PRECISION", SQL_INTEGER, 50 },
    { "SYSTEM", "COLUMN", "LENGTH", SQL_INTEGER, 50 },
    { "SYSTEM", "COLUMN", "RADIX", SQL_SMALLINT, 50 },
    { "SYSTEM", "COLUMN", "SCALE", SQL_SMALLINT, 50 },
    { "SYSTEM", "COLUMN", "NULLABLE", SQL_SMALLINT, 50 },
    { "SYSTEM", "COLUMN", "REMARKS", SCOL_VARCHAR, 50 },
    { "SYSTEM", "COLUMN", "COLUMN_DEF", SCOL_VARCHAR, 50 },
    { "SYSTEM", "COLUMN", "SQL_DATA_TYPE", SQL_SMALLINT, 50 },
    { "SYSTEM", "COLUMN", "SQL_DATETIME_SUB", SQL_SMALLINT, 50 },
    { "SYSTEM", "COLUMN", "CHAR_OCTET_LENGTH", SQL_SMALLINT, 50 },
    { "SYSTEM", "COLUMN", "ORDINAL_POSITION", SQL_SMALLINT, 50 },
    { "SYSTEM", "COLUMN", "IS_NULLABLE", SCOL_VARCHAR, 50 }
};

/**
 * Internal retrieve column information on table.
 * @param stmt statement handle
 * @param cat catalog name/pattern or NULL
 * @param catLen length of catalog name/pattern or SQL_NTS
 * @param schema schema name/pattern or NULL
 * @param schemaLen length of schema name/pattern or SQL_NTS
 * @param table table name/pattern or NULL
 * @param tableLen length of table name/pattern or SQL_NTS
 * @param col column name/pattern or NULL
 * @param colLen length of column name/pattern or SQL_NTS
 * @result ODBC error code
 */

static SQLRETURN
drvcolumns(SQLHSTMT stmt,
	   SQLCHAR *cat, SQLSMALLINT catLen,
	   SQLCHAR *schema, SQLSMALLINT schemaLen,
	   SQLCHAR *table, SQLSMALLINT tableLen,
	   SQLCHAR *col, SQLSMALLINT colLen)
{
    SQLRETURN sret;
    STMT *s;
    DBC *d;
    int ret, nrows, ncols, size, i, k;
    char *errp = NULL, *sql, tname[512], **rowp;

    sret = mkresultset(stmt, colSpec, array_size(colSpec));
    if (sret != SQL_SUCCESS) {
	return sret;
    }
    s = (STMT *) stmt;
    d = (DBC *) s->dbc;
    if (!table || table[0] == '\0' || table[0] == '%') {
	setstat(s, -1, "need table name", (*s->ov3) ? "HY000" : "S1000");
	return SQL_ERROR;
    }
    if (tableLen == SQL_NTS) {
	size = sizeof (tname) - 1;
    } else {
	size = min(sizeof (tname) - 1, tableLen);
    }
    strncpy(tname, table, size);
    tname[size] = '\0';
    sql = sqlite3_mprintf("PRAGMA table_info('%q')", tname);
    if (!sql) {
	return nomem(s);
    }
    ret = sqlite3_get_table(d->sqlite, sql, &rowp, &nrows, &ncols, &errp);
    sqlite3_free(sql);
    if (ret != SQLITE_OK) {
	setstat(s, ret, "%s (%d)", (*s->ov3) ? "HY000" : "S1000",
		errp ? errp : "unknown error", ret);
	if (errp) {
	    sqlite3_free(errp);
	    errp = NULL;
	}
	return SQL_ERROR;	
    }
    if (errp) {
	sqlite3_free(errp);
	errp = NULL;
    }
    if (ncols * nrows <= 0) {
	sqlite3_free_table(rowp);
	return SQL_NO_DATA;
    }
    size = array_size(colSpec) * (nrows + 1);
    s->rows = xmalloc((size + 1) * sizeof (char *));
    if (!s->rows) {
	return nomem(s);
    }
    s->rows[0] = (char *) size;
    s->rows += 1;
    memset(s->rows, 0, sizeof (char *) * size);
    s->rowfree = freerows;
    s->nrows = nrows;
    for (i = 1; i <= s->nrows; i++) {
	s->rows[array_size(colSpec) * i + 0] = xstrdup("");
	s->rows[array_size(colSpec) * i + 1] = xstrdup("");
	s->rows[array_size(colSpec) * i + 2] = xstrdup(tname);
	s->rows[array_size(colSpec) * i + 8] = xstrdup("10");
	s->rows[array_size(colSpec) * i + 9] = xstrdup("0");
	s->rows[array_size(colSpec) * i + 15] = xstrdup("16384");
    }
    for (k = 0; k < ncols; k++) {
	if (strcmp(rowp[k], "cid") == 0) {
	    for (i = 1; i <= s->nrows; i++) {
		char buf[256];
		int coln = i;

		sscanf(rowp[i * ncols + k], "%d", &coln);
		sprintf(buf, "%d", coln + 1);
		s->rows[array_size(colSpec) * i + 16] = xstrdup(buf);
	    }
	} else if (strcmp(rowp[k], "name") == 0) {
	    for (i = 1; i <= s->nrows; i++) {
		s->rows[array_size(colSpec) * i + 3] =
		    xstrdup(rowp[i * ncols + k]);
	    }
	} else if (strcmp(rowp[k], "notnull") == 0) {
	    for (i = 1; i <= s->nrows; i++) {
		if (*rowp[i * ncols + k] != '0') {
		    s->rows[array_size(colSpec) * i + 10] =
			xstrdup(stringify(SQL_FALSE));
		} else {
		    s->rows[array_size(colSpec) * i + 10] =
			xstrdup(stringify(SQL_TRUE));
		}
		s->rows[array_size(colSpec) * i + 17] =
		    xstrdup(*rowp[i * ncols + k] != '0' ? "NO" : "YES");
	    }
	} else if (strcmp(rowp[k], "dflt_value") == 0) {
	    for (i = 1; i <= s->nrows; i++) {
		char *dflt = rowp[i * ncols + k];

		s->rows[array_size(colSpec) * i + 12] =
		    xstrdup(dflt ? dflt : "NULL");
	    }
	} else if (strcmp(rowp[k], "type") == 0) {
	    for (i = 1; i <= s->nrows; i++) {
		char *typename = rowp[i * ncols + k];
		int sqltype, m, d;
		char buf[256];

		s->rows[array_size(colSpec) * i + 5] = xstrdup(typename);
		sqltype = mapsqltype(typename, NULL, *s->ov3);
		getmd(typename, sqltype, &m, &d);
#ifdef SQL_LONGVARCHAR
		if (sqltype == SQL_VARCHAR && m > 255) {
		    sqltype = SQL_LONGVARCHAR;
		}
#endif
		if (sqltype == SQL_VARBINARY && m > 255) {
		    sqltype = SQL_LONGVARBINARY;
		}
		sprintf(buf, "%d", sqltype);
		s->rows[array_size(colSpec) * i + 4] = xstrdup(buf);
		s->rows[array_size(colSpec) * i + 13] = xstrdup(buf);
		sprintf(buf, "%d", m);
		s->rows[array_size(colSpec) * i + 7] = xstrdup(buf);
		sprintf(buf, "%d", d);
		s->rows[array_size(colSpec) * i + 6] = xstrdup(buf);
	    }
	}
    }
    sqlite3_free_table(rowp);
    return SQL_SUCCESS;
}

/**
 * Retrieve column information on table.
 * @param stmt statement handle
 * @param cat catalog name/pattern or NULL
 * @param catLen length of catalog name/pattern or SQL_NTS
 * @param schema schema name/pattern or NULL
 * @param schemaLen length of schema name/pattern or SQL_NTS
 * @param table table name/pattern or NULL
 * @param tableLen length of table name/pattern or SQL_NTS
 * @param col column name/pattern or NULL
 * @param colLen length of column name/pattern or SQL_NTS
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLColumns(SQLHSTMT stmt,
	   SQLCHAR *cat, SQLSMALLINT catLen,
	   SQLCHAR *schema, SQLSMALLINT schemaLen,
	   SQLCHAR *table, SQLSMALLINT tableLen,
	   SQLCHAR *col, SQLSMALLINT colLen)
{
    return drvcolumns(stmt, cat, catLen, schema, schemaLen,
		      table, tableLen, col, colLen);
}

/**
 * Columns for result set of SQLGetTypeInfo().
 */

static COL typeSpec[] = {
    { "SYSTEM", "TYPE", "TYPE_NAME", SCOL_VARCHAR, 50 },
    { "SYSTEM", "TYPE", "DATA_TYPE", SQL_SMALLINT, 2 },
    { "SYSTEM", "TYPE", "PRECISION", SQL_INTEGER, 4 },
    { "SYSTEM", "TYPE", "LITERAL_PREFIX", SCOL_VARCHAR, 50 },
    { "SYSTEM", "TYPE", "LITERAL_SUFFIX", SCOL_VARCHAR, 50 },
    { "SYSTEM", "TYPE", "CREATE_PARAMS", SCOL_VARCHAR, 50 },
    { "SYSTEM", "TYPE", "NULLABLE", SQL_SMALLINT, 2 },
    { "SYSTEM", "TYPE", "CASE_SENSITIVE", SQL_SMALLINT, 2 },
    { "SYSTEM", "TYPE", "SEARCHABLE", SQL_SMALLINT, 2 },
    { "SYSTEM", "TYPE", "UNSIGNED_ATTRIBUTE", SQL_SMALLINT, 2 },
    { "SYSTEM", "TYPE", "MONEY", SQL_SMALLINT, 2 },
    { "SYSTEM", "TYPE", "AUTO_INCREMENT", SQL_SMALLINT, 2 },
    { "SYSTEM", "TYPE", "LOCAL_TYPE_NAME", SCOL_VARCHAR, 50 },
    { "SYSTEM", "TYPE", "MINIMUM_SCALE", SQL_SMALLINT, 2 },
    { "SYSTEM", "TYPE", "MAXIMUM_SCALE", SQL_SMALLINT, 2 }
};

/**
 * Internal function to build up data type information as row in result set.
 * @param s statement pointer
 * @param row row number
 * @param typename name of type
 * @param type integer SQL type
 * @param tind type index
 */

static void
mktypeinfo(STMT *s, int row, char *typename, int type, int tind)
{
    int offs = row * array_size(typeSpec);
    char *tcode, *crpar = NULL, *quote = NULL, *sign = stringify(SQL_FALSE);
    static char tcodes[32 * 32];

    if (tind <= 0) {
	tind = row;
    }
    tcode = tcodes + tind * 32;
    sprintf(tcode, "%d", type);
    s->rows[offs + 0] = typename;
    s->rows[offs + 1] = tcode;
    switch (type) {
    default:
#ifdef SQL_LONGVARCHAR
    case SQL_LONGVARCHAR:
	crpar = "length";
	quote = "'";
	sign = NULL;
	s->rows[offs + 2] = "65536";
	break;
#endif
    case SQL_CHAR:
    case SQL_VARCHAR:
	s->rows[offs + 2] = "255";
	crpar = "length";
	quote = "'";
	sign = NULL;
	break;
    case SQL_TINYINT:
	s->rows[offs + 2] = "3";
	break;
    case SQL_SMALLINT:
	s->rows[offs + 2] = "5";
	break;
    case SQL_INTEGER:
	s->rows[offs + 2] = "7";
	break;
    case SQL_FLOAT:
	s->rows[offs + 2] = "7";
	break;
    case SQL_DOUBLE:
	s->rows[offs + 2] = "15";
	break;
#ifdef SQL_TYPE_DATE
    case SQL_TYPE_DATE:
#endif
    case SQL_DATE:
	s->rows[offs + 2] = "10";
	quote = "'";
	sign = NULL;
	break;
#ifdef SQL_TYPE_TIME
    case SQL_TYPE_TIME:
#endif
    case SQL_TIME:
	s->rows[offs + 2] = "8";
	quote = "'";
	sign = NULL;
	break;
#ifdef SQL_TYPE_TIMESTAMP
    case SQL_TYPE_TIMESTAMP:
#endif
    case SQL_TIMESTAMP:
	s->rows[offs + 2] = "32";
	quote = "'";
	sign = NULL;
	break;
    case SQL_VARBINARY:
	sign = NULL;
	s->rows[offs + 2] = "255";
	break;
    case SQL_LONGVARBINARY:
	sign = NULL;
	s->rows[offs + 2] = "65536";
	break;
    }
    s->rows[offs + 3] = s->rows[offs + 4] = quote;
    s->rows[offs + 5] = crpar;
    s->rows[offs + 6] = stringify(SQL_NULLABLE);
    s->rows[offs + 7] = stringify(SQL_FALSE);
    s->rows[offs + 8] = stringify(SQL_SEARCHABLE);
    s->rows[offs + 9] = sign;
    s->rows[offs + 10] = stringify(SQL_FALSE);
    s->rows[offs + 11] = stringify(SQL_FALSE);
    s->rows[offs + 12] = typename;
    s->rows[offs + 13] = NULL;
    s->rows[offs + 14] = NULL;
}

/**
 * Helper function to sort type information.
 * Callback for qsort().
 * @param a first item to compare
 * @param b second item to compare
 * @result ==0, <0, >0 according to data type number
 */

static int
typeinfosort(const void *a, const void *b)
{
    char **pa = (char **) a;
    char **pb = (char **) b;
    int na, nb;

    na = strtol(pa[1], NULL, 0);
    nb = strtol(pb[1], NULL, 0);
    return na - nb;
}

/**
 * Internal return data type information.
 * @param stmt statement handle
 * @param sqltype which type to retrieve
 * @result ODBC error code
 */

static SQLRETURN
drvgettypeinfo(SQLHSTMT stmt, SQLSMALLINT sqltype)
{
    SQLRETURN ret;
    STMT *s;
    DBC *d;

    ret = mkresultset(stmt, typeSpec, array_size(typeSpec));
    if (ret != SQL_SUCCESS) {
	return ret;
    }
    s = (STMT *) stmt;
    d = (DBC *) s->dbc;
#ifdef SQL_LONGVARCHAR
    s->nrows = sqltype == SQL_ALL_TYPES ? 13 : 1;
#else
    s->nrows = sqltype == SQL_ALL_TYPES ? 12 : 1;
#endif
    if (sqltype == SQL_ALL_TYPES) {
	s->nrows += 2;
    }
    s->rows = (char **) xmalloc(sizeof (char *) * (s->nrows + 1)
				* array_size(typeSpec));
    if (!s->rows) {
	s->nrows = 0;
	return nomem(s);
    }
#ifdef MEMORY_DEBUG
    s->rowfree = xfree__;
#else
    s->rowfree = free;
#endif
    memset(s->rows, 0,
	   sizeof (char *) * (s->nrows + 1) * array_size(typeSpec));
    if (sqltype == SQL_ALL_TYPES) {
	int cc = 1;

	mktypeinfo(s, cc++, "varchar", SQL_VARCHAR, 0);
	mktypeinfo(s, cc++, "tinyint", SQL_TINYINT, 0);
	mktypeinfo(s, cc++, "smallint", SQL_SMALLINT, 0);
	mktypeinfo(s, cc++, "integer", SQL_INTEGER, 0);
	mktypeinfo(s, cc++, "float", SQL_FLOAT, 0);
	mktypeinfo(s, cc++, "double", SQL_DOUBLE, 0);
#ifdef SQL_TYPE_DATE
	mktypeinfo(s, cc++, "date", (*s->ov3) ? SQL_TYPE_DATE : SQL_DATE, 0);
#else
	mktypeinfo(s, cc++, "date", SQL_DATE, 0);
#endif
#ifdef SQL_TYPE_TIME
	mktypeinfo(s, cc++, "time", (*s->ov3) ? SQL_TYPE_TIME : SQL_TIME, 0);
#else
	mktypeinfo(s, cc++, "time", SQL_TIME, 0);
#endif
#ifdef SQL_TYPE_TIMESTAMP
	mktypeinfo(s, cc++, "timestamp",
		   (*s->ov3) ? SQL_TYPE_TIMESTAMP : SQL_TIMESTAMP, 0);
#else
	mktypeinfo(s, cc++, "timestamp", SQL_TIMESTAMP, 0);
#endif
	mktypeinfo(s, cc++, "char", SQL_CHAR, 0);
	mktypeinfo(s, cc++, "numeric", SQL_DOUBLE, 0);
#ifdef SQL_LONGVARCHAR
	mktypeinfo(s, cc++, "text", SQL_LONGVARCHAR, 0);
	mktypeinfo(s, cc++, "longvarchar", SQL_LONGVARCHAR, 0);
#else
	mktypeinfo(s, cc++, "text", SQL_VARCHAR, 0);
#endif
	mktypeinfo(s, cc++, "varbinary", SQL_VARBINARY, 0);
	mktypeinfo(s, cc++, "longvarbinary", SQL_LONGVARBINARY, 0);
	qsort(s->rows + array_size(typeSpec), s->nrows,
	      sizeof (char *) * array_size(typeSpec), typeinfosort);
    } else {
	switch (sqltype) {
	case SQL_CHAR:
	    mktypeinfo(s, 1, "char", SQL_CHAR, 10);
	    break;
	case SQL_VARCHAR:
	    mktypeinfo(s, 1, "varchar", SQL_VARCHAR, 1);
	    break;
	case SQL_TINYINT:
	    mktypeinfo(s, 1, "tinyint", SQL_TINYINT, 2);
	    break;
	case SQL_SMALLINT:
	    mktypeinfo(s, 1, "smallint", SQL_SMALLINT, 3);
	    break;
	case SQL_INTEGER:
	    mktypeinfo(s, 1, "integer", SQL_INTEGER, 4);
	    break;
	case SQL_FLOAT:
	    mktypeinfo(s, 1, "float", SQL_FLOAT, 5);
	    break;
	case SQL_DOUBLE:
	    mktypeinfo(s, 1, "double", SQL_DOUBLE, 6);
	    break;
#ifdef SQL_TYPE_DATE
	case SQL_TYPE_DATE:
	    mktypeinfo(s, 1, "date", SQL_TYPE_DATE, 25);
	    break;
#endif
	case SQL_DATE:
	    mktypeinfo(s, 1, "date", SQL_DATE, 7);
	    break;
#ifdef SQL_TYPE_TIME
	case SQL_TYPE_TIME:
	    mktypeinfo(s, 1, "date", SQL_TYPE_TIME, 26);
	    break;
#endif
	case SQL_TIME:
	    mktypeinfo(s, 1, "time", SQL_TIME, 8);
	    break;
#ifdef SQL_TYPE_TIMESTAMP
	case SQL_TYPE_TIMESTAMP:
	    mktypeinfo(s, 1, "date", SQL_TYPE_TIMESTAMP, 27);
	    break;
#endif
	case SQL_TIMESTAMP:
	    mktypeinfo(s, 1, "timestamp", SQL_TIMESTAMP, 9);
	    break;
#ifdef SQL_LONGVARCHAR
	case SQL_LONGVARCHAR:
	    mktypeinfo(s, 1, "longvarchar", SQL_LONGVARCHAR, 12);
	    break;
#endif
	case SQL_VARBINARY:
	    mktypeinfo(s, 1, "varbinary", SQL_VARBINARY, 30);
	    break;
	case SQL_LONGVARBINARY:
	    mktypeinfo(s, 1, "longvarbinary", SQL_LONGVARBINARY, 31);
	    break;
	default:
	    s->nrows = 0;
	    return SQL_NO_DATA;
	}
    }
    return SQL_SUCCESS;
}

/**
 * Return data type information.
 * @param stmt statement handle
 * @param sqltype which type to retrieve
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLGetTypeInfo(SQLHSTMT stmt, SQLSMALLINT sqltype)
{
    return drvgettypeinfo(stmt, sqltype);
}

/**
 * Columns for result set of SQLStatistics().
 */

static COL statSpec[] = {
    { "SYSTEM", "STATISTICS", "TABLE_QUALIFIER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "STATISTICS", "TABLE_OWNER", SCOL_VARCHAR, 50 },
    { "SYSTEM", "STATISTICS", "TABLE_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "STATISTICS", "NON_UNIQUE", SQL_SMALLINT, 50 },
    { "SYSTEM", "STATISTICS", "INDEX_QUALIFIER", SCOL_VARCHAR, 255 },
    { "SYSTEM", "STATISTICS", "INDEX_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "STATISTICS", "TYPE", SQL_SMALLINT, 50 },
    { "SYSTEM", "STATISTICS", "ORDINAL_POSITION", SQL_SMALLINT, 50 },
    { "SYSTEM", "STATISTICS", "COLUMN_NAME", SCOL_VARCHAR, 255 },
    { "SYSTEM", "STATISTICS", "ASC_OR_DESC", SCOL_CHAR, 1 },
    { "SYSTEM", "STATISTICS", "CARDINALITY", SQL_INTEGER, 50 },
    { "SYSTEM", "STATISTICS", "PAGES", SQL_INTEGER, 50 },
    { "SYSTEM", "STATISTICS", "FILTER_CONDITION", SCOL_VARCHAR, 255 }
};

/**
 * Internal return statistic information on table indices.
 * @param stmt statement handle
 * @param cat catalog name/pattern or NULL
 * @param catLen length of catalog name/pattern or SQL_NTS
 * @param schema schema name/pattern or NULL
 * @param schemaLen length of schema name/pattern or SQL_NTS
 * @param table table name/pattern or NULL
 * @param tableLen length of table name/pattern or SQL_NTS
 * @param itype type of index information
 * @param resv reserved
 * @result ODBC error code
 */

static SQLRETURN
drvstatistics(SQLHSTMT stmt, SQLCHAR *cat, SQLSMALLINT catLen,
	      SQLCHAR *schema, SQLSMALLINT schemaLen,
	      SQLCHAR *table, SQLSMALLINT tableLen,
	      SQLUSMALLINT itype, SQLUSMALLINT resv)
{
    SQLRETURN sret;
    STMT *s;
    DBC *d;
    int i, size, ret, nrows, ncols, offs, namec, uniquec;
    char **rowp, *errp = NULL, *sql, tname[512];

    sret = mkresultset(stmt, statSpec, array_size(statSpec));
    if (sret != SQL_SUCCESS) {
	return sret;
    }
    s = (STMT *) stmt;
    d = (DBC *) s->dbc;
    if (!table || table[0] == '\0' || table[0] == '%') {
	setstat(s, -1, "need table name", (*s->ov3) ? "HY000" : "S1000");
	return SQL_ERROR;
    }
    if (tableLen == SQL_NTS) {
	size = sizeof (tname) - 1;
    } else {
	size = min(sizeof (tname) - 1, tableLen);
    }
    strncpy(tname, table, size);
    tname[size] = '\0';
    sql = sqlite3_mprintf("PRAGMA index_list('%q')", tname);
    if (!sql) {
	return nomem(s);
    }
    ret = sqlite3_get_table(d->sqlite, sql, &rowp, &nrows, &ncols, &errp);
    sqlite3_free(sql);
    if (ret != SQLITE_OK) {
	setstat(s, ret, "%s (%d)", (*s->ov3) ? "HY000" : "S1000",
		errp ? errp : "unknown error", ret);
	if (errp) {
	    sqlite3_free(errp);
	    errp = NULL;
	}
	return SQL_ERROR;
    }
    if (errp) {
	sqlite3_free(errp);
	errp = NULL;
    }
    if (ncols * nrows <= 0) {
nodata:
	sqlite3_free_table(rowp);
	/* try table_info for integer primary keys */
	if (itype == SQL_INDEX_UNIQUE) {
	    ret = SQLITE_ERROR;

	    sql = sqlite3_mprintf("PRAGMA table_info('%q')", tname);
	    if (sql) {
		ret = sqlite3_get_table(d->sqlite, sql, &rowp,
					&nrows, &ncols, NULL);
		sqlite3_free(sql);
	    }
	    if (ret == SQLITE_OK) {
		int colid, typec, roffs;

		namec = findcol(rowp, ncols, "name");
		uniquec = findcol(rowp, ncols, "pk");
		typec = findcol(rowp, ncols, "type");
		colid = findcol(rowp, ncols, "cid");
		if (namec < 0 || uniquec < 0 || typec < 0 || colid < 0) {
		    goto nodata2;
		}
		for (i = 1; i <= nrows; i++) {
		    if (*rowp[i * ncols + uniquec] != '0' &&
			strlen(rowp[i * ncols + typec]) == 7 &&
			strncasecmp(rowp[i * ncols + typec], "integer", 7)
			== 0) {
			break;
		    }
		}
		if (i > nrows) {
		    goto nodata2;
		}
		size = (1 + 1) * array_size(statSpec);
		s->rows = xmalloc((size + 1) * sizeof (char *));
		if (!s->rows) {
		    s->nrows = 0;
		    return nomem(s);
		}
		s->rows[0] = (char *) size;
		s->rows += 1;
		memset(s->rows, 0, sizeof (char *) * size);
		s->rowfree = freerows;
		s->nrows = 1;
		roffs = s->ncols;
		s->rows[roffs + 0] = xstrdup("");
		s->rows[roffs + 1] = xstrdup("");
		s->rows[roffs + 2] = xstrdup(tname);
		s->rows[roffs + 3] = xstrdup(stringify(SQL_FALSE));
		s->rows[roffs + 4] = xstrdup("");
		s->rows[roffs + 5] = xstrdup("");
		s->rows[roffs + 6] = xstrdup(stringify(SQL_INDEX_OTHER));
		s->rows[roffs + 7] = xstrdup("1");
		s->rows[roffs + 8] = xstrdup(rowp[i * ncols + namec]);
		s->rows[roffs + 9] = xstrdup("A");
nodata2:
		sqlite3_free_table(rowp);
	    }
	}
	return SQL_SUCCESS;
    }
    size = 0;
    namec = findcol(rowp, ncols, "name");
    uniquec = findcol(rowp, ncols, "unique");
    if (namec < 0 || uniquec < 0) {
	goto nodata;
    }
    for (i = 1; i <= nrows; i++) {
	int nnrows, nncols;
	char **rowpp;
	int isuniq;

	isuniq = *rowp[i * ncols + uniquec] != '0';
	if (isuniq || itype == SQL_INDEX_ALL) {
	    ret = SQLITE_ERROR;
	    sql = sqlite3_mprintf("PRAGMA index_info('%q')", 
				  rowp[i * ncols + namec]);
	    if (sql) {
		ret = sqlite3_get_table(d->sqlite, sql, &rowpp,
					&nnrows, &nncols, NULL);
		sqlite3_free(sql);
	    }
	    if (ret == SQLITE_OK) {
		size += nnrows;
		sqlite3_free_table(rowpp);
	    }
	}
    }
    if (size == 0) {
	goto nodata;
    }
    s->nrows = size;
    size = (size + 1) * array_size(statSpec);
    s->rows = xmalloc((size + 1) * sizeof (char *));
    if (!s->rows) {
	s->nrows = 0;
	return nomem(s);
    }
    s->rows[0] = (char *) size;
    s->rows += 1;
    memset(s->rows, 0, sizeof (char *) * size);
    s->rowfree = freerows;
    offs = 0;
    for (i = 1; i <= nrows; i++) {
	int nnrows, nncols;
	char **rowpp;

	if (*rowp[i * ncols + uniquec] != '0' || itype == SQL_INDEX_ALL) {
	    int k;

	    ret = SQLITE_ERROR;
	    sql = sqlite3_mprintf("PRAGMA index_info('%q')", 
				  rowp[i * ncols + namec]);
	    if (sql) {
		ret = sqlite3_get_table(d->sqlite, sql, &rowpp,
					&nnrows, &nncols, NULL);
		sqlite3_free(sql);
	    }
	    if (ret != SQLITE_OK) {
		continue;
	    }
	    for (k = 0; nnrows && k < nncols; k++) {
		if (strcmp(rowpp[k], "name") == 0) {
		    int m;

		    for (m = 1; m <= nnrows; m++) {
			int roffs = (offs + m) * s->ncols;
			int isuniq;

			isuniq = *rowp[i * ncols + uniquec] != '0';
			s->rows[roffs + 0] = xstrdup("");
			s->rows[roffs + 1] = xstrdup("");
			s->rows[roffs + 2] = xstrdup(tname);
			if (isuniq) {
			    s->rows[roffs + 3] = xstrdup(stringify(SQL_FALSE));
			} else {
			    s->rows[roffs + 3] = xstrdup(stringify(SQL_TRUE));
			}
			s->rows[roffs + 4] = xstrdup("");
			s->rows[roffs + 5] = xstrdup(rowp[i * ncols + namec]);
			s->rows[roffs + 6] =
			    xstrdup(stringify(SQL_INDEX_OTHER));
			s->rows[roffs + 8] = xstrdup(rowpp[m * nncols + k]);
			s->rows[roffs + 9] = xstrdup("A");
		    }
		} else if (strcmp(rowpp[k], "seqno") == 0) {
		    int m;

		    for (m = 1; m <= nnrows; m++) {
			int roffs = (offs + m) * s->ncols;
			int pos = m - 1;
			char buf[32];

			sscanf(rowpp[m * nncols + k], "%d", &pos);
			sprintf(buf, "%d", pos + 1);
			s->rows[roffs + 7] = xstrdup(buf);
		    }
		}
	    }
	    offs += nnrows;
	    sqlite3_free_table(rowpp);
	}
    }
    sqlite3_free_table(rowp);
    return SQL_SUCCESS;
}

/**
 * Return statistic information on table indices.
 * @param stmt statement handle
 * @param cat catalog name/pattern or NULL
 * @param catLen length of catalog name/pattern or SQL_NTS
 * @param schema schema name/pattern or NULL
 * @param schemaLen length of schema name/pattern or SQL_NTS
 * @param table table name/pattern or NULL
 * @param tableLen length of table name/pattern or SQL_NTS
 * @param itype type of index information
 * @param resv reserved
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLStatistics(SQLHSTMT stmt, SQLCHAR *cat, SQLSMALLINT catLen,
	      SQLCHAR *schema, SQLSMALLINT schemaLen,
	      SQLCHAR *table, SQLSMALLINT tableLen,
	      SQLUSMALLINT itype, SQLUSMALLINT resv)
{
    return drvstatistics(stmt, cat, catLen, schema, schemaLen,
			 table, tableLen, itype, resv);
}

/**
 * Retrieve row data after fetch.
 * @param stmt statement handle
 * @param col column number, starting at 1
 * @param type output type
 * @param val output buffer
 * @param len length of output buffer
 * @param lenp output length
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLGetData(SQLHSTMT stmt, SQLUSMALLINT col, SQLSMALLINT type,
	   SQLPOINTER val, SQLINTEGER len, SQLINTEGER *lenp)
{
    STMT *s;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    if (col == 0 && s->bkmrk && type == SQL_C_BOOKMARK) {
	*((long *) val) = s->rowp;
	if (lenp) {
	    *lenp = sizeof (long);
	}
	return SQL_SUCCESS;
    }
    if (col < 1 || col > s->ncols) {
	setstat(s, -1, "invalid column", (*s->ov3) ? "07009" : "S1002");
	return SQL_ERROR;
    }
    --col;
    return getrowdata(s, col, type, val, len, lenp, 1);
}

/**
 * Internal: fetch and bind from statement's current row
 * @param s statement pointer
 * @param rsi rowset index
 * @result ODBC error code
 */

static SQLRETURN
dofetchbind(STMT *s, int rsi)
{
    int ret, i, withinfo = 0;

    s->row_status0[rsi] = SQL_ROW_SUCCESS;
    if (s->bkmrk && s->bkmrkcol.valp) {
	long *val;

	if (s->bind_type != SQL_BIND_BY_COLUMN) {
	    val = (long *) ((char *) s->bkmrkcol.valp + s->bind_type * rsi);
	} else {
	    val = (long *) s->bkmrkcol.valp + rsi;
	}
	if (s->bind_offs) {
	    val = (long *) ((char *) val + *s->bind_offs);
	}
	*val = s->rowp;
	if (s->bkmrkcol.lenp) {
	    SQLINTEGER *ival;

	    if (s->bind_type != SQL_BIND_BY_COLUMN) {
		ival = (SQLINTEGER *)
		    ((char *) s->bkmrkcol.lenp + s->bind_type * rsi);
	    } else {
		ival = &s->bkmrkcol.lenp[rsi];
	    }
	    if (s->bind_offs) {
		ival = (SQLINTEGER *) ((char *) ival + *s->bind_offs);
	    }
	    *ival = sizeof (long);
	}
    }
    ret = SQL_SUCCESS;
    for (i = 0; s->bindcols && i < s->ncols; i++) {
	BINDCOL *b = &s->bindcols[i];
	SQLPOINTER dp = 0;
	SQLINTEGER *lp = 0;

	b->offs = 0;
	if (b->valp) {
	    if (s->bind_type != SQL_BIND_BY_COLUMN) {
		dp = (SQLPOINTER) ((char *) b->valp + s->bind_type * rsi);
	    } else {
		dp = (SQLPOINTER) ((char *) b->valp + b->max * rsi);
	    }
	    if (s->bind_offs) {
		dp = (SQLPOINTER) ((char *) dp + *s->bind_offs);
	    }
	}
	if (b->lenp) {
	    if (s->bind_type != SQL_BIND_BY_COLUMN) {
		lp = (SQLINTEGER *) ((char *) b->lenp + s->bind_type * rsi);
	    } else {
		lp = b->lenp + rsi;
	    }
	    if (s->bind_offs) {
		lp = (SQLINTEGER *) ((char *) lp + *s->bind_offs);
	    }
	}
	if (dp || lp) {
	    ret = getrowdata(s, (SQLUSMALLINT) i, b->type, dp, b->max, lp, 0);
	    if (!SQL_SUCCEEDED(ret)) {
		s->row_status0[rsi] = SQL_ROW_ERROR;
		break;
	    }
	    if (ret != SQL_SUCCESS) {
		withinfo = 1;
#ifdef SQL_ROW_SUCCESS_WITH_INFO
		s->row_status0[rsi] = SQL_ROW_SUCCESS_WITH_INFO;
#endif
	    }
	}
    }
    if (SQL_SUCCEEDED(ret)) {
	ret = withinfo ? SQL_SUCCESS_WITH_INFO : SQL_SUCCESS;
    }
    return ret;
}

/**
 * Internal fetch function for SQLFetchScroll() and SQLExtendedFetch().
 * @param stmt statement handle
 * @param orient fetch direction
 * @param offset offset for fetch direction
 * @result ODBC error code
 */

static SQLRETURN
drvfetchscroll(SQLHSTMT stmt, SQLSMALLINT orient, SQLINTEGER offset)
{
    STMT *s;
    int i, withinfo = 0;
    SQLRETURN ret;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    for (i = 0; i < s->rowset_size; i++) {
	s->row_status0[i] = SQL_ROW_NOROW;
    }
    if (s->row_status) {
	memcpy(s->row_status, s->row_status0,
	       sizeof (SQLUSMALLINT) * s->rowset_size);
    }
    s->row_count0 = 0;
    if (s->row_count) {
	*s->row_count = s->row_count0;
    }
    if (!s->bindcols) {
	for (i = 0; i < s->rowset_size; i++) {
	    s->row_status0[i] = SQL_ROW_ERROR;
	}
	ret = SQL_ERROR;
	i = 0;
	goto done2;
    }
    if (s->curtype == SQL_CURSOR_FORWARD_ONLY && orient != SQL_FETCH_NEXT) {
	setstat(s, -1, "wrong fetch direction", "01000");
	ret = SQL_ERROR;
	i = 0;
	goto done2;
    }
    ret = SQL_SUCCESS;
    i = 0;
    if (((DBC *) (s->dbc))->cur_s3stmt == s && s->s3stmt) {
	s->rowp = 0;
	for (; i < s->rowset_size; i++) {
	    ret = s3stmt_step(s);
	    if (ret != SQL_SUCCESS) {
		s->row_status0[i] = SQL_ROW_ERROR;
		break;
	    }
	    if (s->nrows < 1) {
		break;
	    }
	    ret = dofetchbind(s, i);
	    if (!SQL_SUCCEEDED(ret)) {
		break;
	    } else if (ret == SQL_SUCCESS_WITH_INFO) {
		withinfo = 1;
	    }
	}
    } else if (s->rows) {
	switch (orient) {
	case SQL_FETCH_NEXT:
	    if (s->nrows < 1) {
		return SQL_NO_DATA;
	    }
	    if (s->rowp < 0) {
		s->rowp = -1;
	    }
	    if (s->rowp >= s->nrows) {
		s->rowp = s->nrows;
		return SQL_NO_DATA;
	    }
	    break;
	case SQL_FETCH_PRIOR:
	    if (s->nrows < 1) {
		s->rowp = -1;
		return SQL_NO_DATA;
	    }
	    s->rowp -= s->rowset_size + 1;
	    if (s->rowp < -1) {
		s->rowp = -1;
		return SQL_NO_DATA;
	    }
	    break;
	case SQL_FETCH_FIRST:
	    if (s->nrows < 1) {
		return SQL_NO_DATA;
	    }
	    s->rowp = -1;
	    break;
	case SQL_FETCH_LAST:
	    if (s->nrows < 1) {
		return SQL_NO_DATA;
	    }
	    s->rowp = s->nrows - s->rowset_size;
	    if (--s->rowp < -1) {
		s->rowp = -1;
	    }
	    break;
	case SQL_FETCH_ABSOLUTE:
	    if (offset == 0) {
		s->rowp = -1;
		return SQL_NO_DATA;
	    } else if (offset < 0) {
		if (0 - offset <= s->nrows) {
		    s->rowp = s->nrows + offset - 1;
		    break;
		}
		s->rowp = -1;
		return SQL_NO_DATA;
	    } else if (offset > s->nrows) {
		s->rowp = s->nrows;
		return SQL_NO_DATA;
	    }
	    s->rowp = offset - 1 - 1;
	    break;
	case SQL_FETCH_RELATIVE:
	    if (offset >= 0) {
		s->rowp += offset * s->rowset_size - 1;
		if (s->rowp >= s->nrows) {
		    s->rowp = s->nrows;
		    return SQL_NO_DATA;
		}
	    } else {
		s->rowp += offset * s->rowset_size - 1;
		if (s->rowp < -1) {
		    s->rowp = -1;
		    return SQL_NO_DATA;
		}
	    }
	    break;
	case SQL_FETCH_BOOKMARK:
	    if (s->bkmrk) {
		if (offset < 0 || offset >= s->nrows) {
		    return SQL_NO_DATA;
		}
		s->rowp = offset - 1;
		break;
	    }
	    /* fall through */
	default:
	    s->row_status0[0] = SQL_ROW_ERROR;
	    ret = SQL_ERROR;
	    goto done;
	}
	for (; i < s->rowset_size; i++) {
	    ++s->rowp;
	    if (s->rowp < 0 || s->rowp >= s->nrows) {
		break;
	    }
	    ret = dofetchbind(s, i);
	    if (!SQL_SUCCEEDED(ret)) {
		break;
	    } else if (ret == SQL_SUCCESS_WITH_INFO) {
		withinfo = 1;
	    }
	}
    }
done:
    if (i == 0) {
	if (SQL_SUCCEEDED(ret)) {
	    return SQL_NO_DATA;
	}
	return ret;
    }
    if (SQL_SUCCEEDED(ret)) {
	ret = withinfo ? SQL_SUCCESS_WITH_INFO : SQL_SUCCESS;
    }
done2:
    if (s->row_status) {
	memcpy(s->row_status, s->row_status0,
	       sizeof (SQLUSMALLINT) * s->rowset_size);
    }
    s->row_count0 = i;
    if (s->row_count) {
	*s->row_count = s->row_count0;
    }
    return ret;
}

/**
 * Fetch next result row.
 * @param stmt statement handle
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLFetch(SQLHSTMT stmt)
{
    return drvfetchscroll(stmt, SQL_FETCH_NEXT, 0);
}

/**
 * Fetch result row with scrolling.
 * @param stmt statement handle
 * @param orient fetch direction
 * @param offset offset for fetch direction
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLFetchScroll(SQLHSTMT stmt, SQLSMALLINT orient, SQLINTEGER offset)
{
    return drvfetchscroll(stmt, orient, offset);
}

/**
 * Fetch result row with scrolling and row status.
 * @param stmt statement handle
 * @param orient fetch direction
 * @param offset offset for fetch direction
 * @param rowcount output number of fetched rows
 * @param rowstatus array for row stati
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLExtendedFetch(SQLHSTMT stmt, SQLUSMALLINT orient, SQLINTEGER offset,
		 SQLUINTEGER *rowcount, SQLUSMALLINT *rowstatus)
{
    STMT *s;
    SQLRETURN ret;
    SQLUSMALLINT *rst;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    /* temporarily turn off SQL_ATTR_ROW_STATUS_PTR */
    rst = s->row_status;
    s->row_status = 0;
    ret = drvfetchscroll(stmt, orient, offset);
    s->row_status = rst;
    if (rowstatus) {
	memcpy(rowstatus, s->row_status0,
	       sizeof (SQLUSMALLINT) * s->rowset_size);
    }
    if (rowcount) {
	*rowcount = s->row_count0;
    }
    return ret;
}

/**
 * Return number of affected rows of HSTMT.
 * @param stmt statement handle
 * @param nrows output number of rows
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLRowCount(SQLHSTMT stmt, SQLINTEGER *nrows)
{
    STMT *s;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    if (nrows) {
	*nrows = s->nrows;
    }
    return SQL_SUCCESS;
}

/**
 * Return number of columns of result set given HSTMT.
 * @param stmt statement handle
 * @param ncols output number of columns
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLNumResultCols(SQLHSTMT stmt, SQLSMALLINT *ncols)
{
    STMT *s;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    if (ncols) {
	*ncols = s->ncols;
    }
    return SQL_SUCCESS;
}

/**
 * Internal describe column information.
 * @param stmt statement handle
 * @param col column number, starting at 1
 * @param name buffer for column name
 * @param nameMax length of name buffer
 * @param nameLen output length of column name
 * @param type output SQL type
 * @param size output column size
 * @param digits output number of digits
 * @param nullable output NULL allowed indicator
 * @result ODBC error code
 */

static SQLRETURN
drvdescribecol(SQLHSTMT stmt, SQLUSMALLINT col, SQLCHAR *name,
	       SQLSMALLINT nameMax, SQLSMALLINT *nameLen,
	       SQLSMALLINT *type, SQLUINTEGER *size,
	       SQLSMALLINT *digits, SQLSMALLINT *nullable)
{
    STMT *s;
    COL *c;
    int didname = 0;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    if (!s->cols) {
	setstat(s, -1, "no columns", (*s->ov3) ? "07009" : "S1002");
	return SQL_ERROR;
    }
    if (col < 1 || col > s->ncols) {
	setstat(s, -1, "invalid column", (*s->ov3) ? "07009" : "S1002");
	return SQL_ERROR;
    }
    c = s->cols + col - 1;
    if (name && nameMax > 0) {
	strncpy(name, c->column, nameMax);
	name[nameMax - 1] = '\0';
	didname = 1;
    }
    if (nameLen) {
	if (didname) {
	    *nameLen = strlen(name);
	} else {
	    *nameLen = strlen(c->column);
	}
    }
    if (type) {
	*type = c->type;
    }
    if (size) {
	*size = c->size;
    }
    if (digits) {
	*digits = 0;
    }
    if (nullable) {
	*nullable = 1;
    }
    return SQL_SUCCESS;
}

/**
 * Describe column information.
 * @param stmt statement handle
 * @param col column number, starting at 1
 * @param name buffer for column name
 * @param nameMax length of name buffer
 * @param nameLen output length of column name
 * @param type output SQL type
 * @param size output column size
 * @param digits output number of digits
 * @param nullable output NULL allowed indicator
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLDescribeCol(SQLHSTMT stmt, SQLUSMALLINT col, SQLCHAR *name,
	       SQLSMALLINT nameMax, SQLSMALLINT *nameLen,
	       SQLSMALLINT *type, SQLUINTEGER *size,
	       SQLSMALLINT *digits, SQLSMALLINT *nullable)
{
    return drvdescribecol(stmt, col, name, nameMax, nameLen,
			  type, size, digits, nullable);
}

/**
 * Internal retrieve column attributes.
 * @param stmt statement handle
 * @param col column number, starting at 1
 * @param id attribute id
 * @param val output buffer
 * @param valMax length of output buffer
 * @param valLen output length
 * @param val2 integer output buffer
 * @result ODBC error code
 */

static SQLRETURN
drvcolattributes(SQLHSTMT stmt, SQLUSMALLINT col, SQLUSMALLINT id,
		 SQLPOINTER val, SQLSMALLINT valMax, SQLSMALLINT *valLen,
		 SQLINTEGER *val2)
{
    STMT *s;
    COL *c;
    SQLSMALLINT dummy;
    char *valc = (char *) val;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    if (!s->cols) {
	return SQL_ERROR;
    }
    if (!valLen) {
	valLen = &dummy;
    }
    if (id == SQL_COLUMN_COUNT) {
	if (val2) {
	    *val2 = s->ncols;
	}
	*valLen = sizeof (int);
	return SQL_SUCCESS;
    }
    if (id == SQL_COLUMN_TYPE && col == 0) {
	if (val2) {
	    *val2 = SQL_INTEGER;
	}
	*valLen = sizeof (int);
	return SQL_SUCCESS;
    }
#ifdef SQL_DESC_OCTET_LENGTH
    if (id == SQL_DESC_OCTET_LENGTH && col == 0) {
	if (val2) {
	    *val2 = 4;
	}
	*valLen = sizeof (int);
	return SQL_SUCCESS;
    }
#endif
    if (col < 1 || col > s->ncols) {
	setstat(s, -1, "invalid column", (*s->ov3) ? "07009": "S1002");
	return SQL_ERROR;
    }
    c = s->cols + col - 1;

    switch (id) {
    case SQL_COLUMN_LABEL:
	if (c->label) {
	    if (valc && valMax > 0) {
		strncpy(valc, c->label, valMax);
		valc[valMax - 1] = '\0';
	    }
	    *valLen = strlen(c->label);
	    goto checkLen;
	}
	/* fall through */
    case SQL_COLUMN_NAME:
    case SQL_DESC_NAME:
	if (valc && valMax > 0) {
	    strncpy(valc, c->column, valMax);
	    valc[valMax - 1] = '\0';
	}
	*valLen = strlen(c->column);
checkLen:
	if (*valLen >= valMax) {
	    setstat(s, -1, "data right truncated", "01004");
	    return SQL_SUCCESS_WITH_INFO;
	}
	return SQL_SUCCESS;
    case SQL_COLUMN_TYPE:
    case SQL_DESC_TYPE:
	if (val2) {
	    *val2 = c->type;
	}
	*valLen = sizeof (int);
	return SQL_SUCCESS;
    case SQL_COLUMN_DISPLAY_SIZE:
	if (val2) {
	    *val2 = c->size;
	}
	*valLen = sizeof (int);
	return SQL_SUCCESS;
    case SQL_COLUMN_UNSIGNED:
	if (val2) {
	    *val2 = c->nosign ? SQL_TRUE : SQL_FALSE;
	}
	*valLen = sizeof (int);
	return SQL_SUCCESS;
    case SQL_COLUMN_SCALE:
    case SQL_DESC_SCALE:
	if (val2) {
	    *val2 = c->scale;
	}
	*valLen = sizeof (int);
	return SQL_SUCCESS;
    case SQL_COLUMN_PRECISION:
    case SQL_DESC_PRECISION:
	if (val2) {
	    *val2 = c->prec;
	}
	*valLen = sizeof (int);
	return SQL_SUCCESS;
    case SQL_COLUMN_MONEY:
	if (val2) {
	    *val2 = SQL_FALSE;
	}
	*valLen = sizeof (int);
	return SQL_SUCCESS;
    case SQL_COLUMN_AUTO_INCREMENT:
	if (val2) {
	    *val2 = c->autoinc > 0 ? SQL_TRUE : SQL_FALSE;
	}
	*valLen = sizeof (int);
	return SQL_SUCCESS;
    case SQL_COLUMN_LENGTH:
    case SQL_DESC_LENGTH:
	if (val2) {
	    *val2 = c->size;
	}
	*valLen = sizeof (int);
	return SQL_SUCCESS;
    case SQL_COLUMN_NULLABLE:
    case SQL_DESC_NULLABLE:
	if (val2) {
	    *val2 = SQL_NULLABLE;
	}
	*valLen = sizeof (int);
	return SQL_SUCCESS;
    case SQL_COLUMN_SEARCHABLE:
	if (val2) {
	    *val2 = SQL_SEARCHABLE;
	}
	*valLen = sizeof (int);
	return SQL_SUCCESS;
    case SQL_COLUMN_CASE_SENSITIVE:
	if (val2) {
	    *val2 = SQL_TRUE;
	}
	*valLen = sizeof (int);
	return SQL_SUCCESS;
    case SQL_COLUMN_UPDATABLE:
	if (val2) {
	    *val2 = SQL_TRUE;
	}
	*valLen = sizeof (int);
	return SQL_SUCCESS;
    case SQL_COLUMN_TYPE_NAME: {
	char *tn = c->typename ? c->typename : "varchar";

	if (valc && valMax > 0) {
	    strncpy(valc, tn, valMax);
	    valc[valMax - 1] = '\0';
	}
	*valLen = strlen(tn);
	goto checkLen;
    }
    case SQL_COLUMN_OWNER_NAME:
    case SQL_COLUMN_QUALIFIER_NAME: {
	char *z = "";

	if (valc && valMax > 0) {
	    strncpy(valc, z, valMax);
	    valc[valMax - 1] = '\0';
	}
	*valLen = strlen(z);
	goto checkLen;
    }
    case SQL_COLUMN_TABLE_NAME:
#if (SQL_COLUMN_TABLE_NAME != SQL_DESC_TABLE_NAME)
    case SQL_DESC_TABLE_NAME:
#endif
	if (valc && valMax > 0) {
	    strncpy(valc, c->table, valMax);
	    valc[valMax - 1] = '\0';
	}
	*valLen = strlen(c->table);
	goto checkLen;
    }
    setstat(s, -1, "unsupported column attributes %d", "HY091", id);
    return SQL_ERROR;
}

/**
 * Retrieve column attributes.
 * @param stmt statement handle
 * @param col column number, starting at 1
 * @param id attribute id
 * @param val output buffer
 * @param valMax length of output buffer
 * @param valLen output length
 * @param val2 integer output buffer
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLColAttributes(SQLHSTMT stmt, SQLUSMALLINT col, SQLUSMALLINT id,
		 SQLPOINTER val, SQLSMALLINT valMax, SQLSMALLINT *valLen,
		 SQLINTEGER *val2)
{
    return drvcolattributes(stmt, col, id, val, valMax, valLen, val2);
}

/**
 * Internal retrieve column attributes.
 * @param stmt statement handle
 * @param col column number, starting at 1
 * @param id attribute id
 * @param val output buffer
 * @param valMax length of output buffer
 * @param valLen output length
 * @param val2 integer output buffer
 * @result ODBC error code
 */

static SQLRETURN
drvcolattribute(SQLHSTMT stmt, SQLUSMALLINT col, SQLUSMALLINT id,
		SQLPOINTER val, SQLSMALLINT valMax, SQLSMALLINT *valLen,
		SQLPOINTER val2)
{
    STMT *s;
    COL *c;
    int v = 0;
    char *valc = (char *) val;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    if (!s->cols) {
	return SQL_ERROR;
    }
    if (col < 1 || col > s->ncols) {
	setstat(s, -1, "invalid column", (*s->ov3) ? "07009" : "S1002");
	return SQL_ERROR;
    }
    c = s->cols + col - 1;
    switch (id) {
    case SQL_DESC_CATALOG_NAME:
	if (valc && valMax > 0) {
	    strncpy(valc, c->db, valMax);
	    valc[valMax - 1] = '\0';
	}
	if (valLen) {
	    *valLen = strlen(c->db);
	}
checkLen:
	if (valLen && *valLen >= valMax) {
	    setstat(s, -1, "data right truncated", "01004");
	    return SQL_SUCCESS_WITH_INFO;
	}
	break;
    case SQL_COLUMN_LENGTH:
    case SQL_DESC_LENGTH:
	v = c->size;
	break;
    case SQL_COLUMN_LABEL:
	if (c->label) {
	    if (valc && valMax > 0) {
		strncpy(valc, c->label, valMax);
		valc[valMax - 1] = '\0';
	    }
	    if (valLen) {
		*valLen = strlen(c->label);
	    }
	    goto checkLen;
	}
	/* fall through */
    case SQL_COLUMN_NAME:
    case SQL_DESC_NAME:
	if (valc && valMax > 0) {
	    strncpy(valc, c->column, valMax);
	    valc[valMax - 1] = '\0';
	}
	if (valLen) {
	    *valLen = strlen(c->column);
	    goto checkLen;
	}
	break;
    case SQL_DESC_TYPE_NAME: {
	char *tn = c->typename ? c->typename : "varchar";

	if (valc && valMax > 0) {
	    strncpy(valc, tn, valMax);
	    valc[valMax - 1] = '\0';
	}
	if (valLen) {
	    *valLen = strlen(tn);
	    goto checkLen;
	}
	break;
    }
    case SQL_DESC_OCTET_LENGTH:
	v = c->size;
	break;
#if (SQL_COLUMN_TABLE_NAME != SQL_DESC_TABLE_NAME)
    case SQL_COLUMN_TABLE_NAME:
#endif
    case SQL_DESC_TABLE_NAME:
	if (valc && valMax > 0) {
	    strncpy(valc, c->table, valMax);
	    valc[valMax - 1] = '\0';
	}
	if (valLen) {
	    *valLen = strlen(c->table);
	    goto checkLen;
	}
	break;
    case SQL_DESC_TYPE:
	v = c->type;
	break;
    case SQL_DESC_CONCISE_TYPE:
	switch (c->type) {
	case SQL_INTEGER:
	    v = SQL_C_LONG;
	    break;
	case SQL_TINYINT:
	    v = SQL_C_TINYINT;
	    break;
	case SQL_SMALLINT:
	    v = SQL_C_SHORT;
	    break;
	case SQL_FLOAT:
	    v = SQL_C_FLOAT;
	    break;
	case SQL_DOUBLE:
	    v = SQL_C_DOUBLE;
	    break;
	case SQL_TIMESTAMP:
	    v = SQL_C_TIMESTAMP;
	    break;
	case SQL_TIME:
	    v = SQL_C_TIME;
	    break;
	case SQL_DATE:
	    v = SQL_C_DATE;
	    break;
#ifdef SQL_C_TYPE_TIMESTAMP
	case SQL_TYPE_TIMESTAMP:
	    v = SQL_C_TYPE_TIMESTAMP;
	    break;
#endif
#ifdef SQL_C_TYPE_TIME
	case SQL_TYPE_TIME:
	    v = SQL_C_TYPE_TIME;
	    break;
#endif
#ifdef SQL_C_TYPE_DATE
	case SQL_TYPE_DATE:
	    v = SQL_C_TYPE_DATE;
	    break;
#endif
	default:
	    v = SQL_C_CHAR;
	    break;
	}
	break;
    case SQL_DESC_UPDATABLE:
	v = SQL_TRUE;
	break;
    case SQL_COLUMN_DISPLAY_SIZE:
	v = c->size;
	break;
    case SQL_COLUMN_UNSIGNED:
	v = c->nosign ? SQL_TRUE : SQL_FALSE;
	break;
    case SQL_COLUMN_SEARCHABLE:
	v = SQL_SEARCHABLE;
	break;
    case SQL_COLUMN_SCALE:
    case SQL_DESC_SCALE:
	v = c->scale;
	break;
    case SQL_COLUMN_PRECISION:
    case SQL_DESC_PRECISION:
	v = c->prec;
	break;
    case SQL_COLUMN_MONEY:
	v = SQL_FALSE;
	break;
    case SQL_COLUMN_AUTO_INCREMENT:
	v = c->autoinc > 0 ? SQL_TRUE : SQL_FALSE;
	break;
    case SQL_DESC_NULLABLE:
	v = SQL_NULLABLE;
	break;
    default:
	setstat(s, -1, "unsupported column attribute %d", "HY091", id);
	return SQL_ERROR;
    }
    if (val2) {
	*(int *) val2 = v;
    }
    return SQL_SUCCESS;
}

/**
 * Retrieve column attributes.
 * @param stmt statement handle
 * @param col column number, starting at 1
 * @param id attribute id
 * @param val output buffer
 * @param valMax length of output buffer
 * @param valLen output length
 * @param val2 integer output buffer
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLColAttribute(SQLHSTMT stmt, SQLUSMALLINT col, SQLUSMALLINT id,
		SQLPOINTER val, SQLSMALLINT valMax, SQLSMALLINT *valLen,
		SQLPOINTER val2)
{
    return drvcolattribute(stmt, col, id, val, valMax, valLen, val2);
}

/**
 * Internal return last HDBC or HSTMT error message.
 * @param env environment handle or NULL
 * @param dbc database connection handle or NULL
 * @param stmt statement handle or NULL
 * @param sqlState output buffer for SQL state
 * @param nativeErr output buffer for native error code
 * @param errmsg output buffer for error message
 * @param errmax length of output buffer for error message
 * @param errlen output length of error message
 * @result ODBC error code
 */

static SQLRETURN
drverror(SQLHENV env, SQLHDBC dbc, SQLHSTMT stmt,
	 SQLCHAR *sqlState, SQLINTEGER *nativeErr,
	 SQLCHAR *errmsg, SQLSMALLINT errmax, SQLSMALLINT *errlen)
{
    SQLCHAR dummy0[6];
    SQLINTEGER dummy1;
    SQLSMALLINT dummy2;

    if (env == SQL_NULL_HENV &&
	dbc == SQL_NULL_HDBC &&
	stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    if (sqlState) {
	sqlState[0] = '\0';
    } else {
	sqlState = dummy0;
    }
    if (!nativeErr) {
	nativeErr = &dummy1;
    }
    *nativeErr = 0;
    if (!errlen) {
	errlen = &dummy2;
    }
    *errlen = 0;
    if (errmsg) {
	if (errmax > 0) {
	    errmsg[0] = '\0';
	}
    } else {
	errmsg = dummy0;
	errmax = 0;
    }
    if (stmt) {
	STMT *s = (STMT *) stmt;

	if (s->logmsg[0] == '\0') {
	    goto noerr;
	}
	*nativeErr = s->naterr;
	strcpy(sqlState, s->sqlstate);
	if (errmax == SQL_NTS) {
	    strcpy(errmsg, "[SQLite]");
	    strcat(errmsg, s->logmsg);
	    *errlen = strlen(errmsg);
	} else {
	    strncpy(errmsg, "[SQLite]", errmax);
	    if (errmax - 8 > 0) {
		strncpy(errmsg + 8, s->logmsg, errmax - 8);
	    }
	    *errlen = min(strlen(s->logmsg) + 8, errmax);
	}
	s->logmsg[0] = '\0';
	return SQL_SUCCESS;
    }
    if (dbc) {
	DBC *d = (DBC *) dbc;

	if (d->magic != DBC_MAGIC || d->logmsg[0] == '\0') {
	    goto noerr;
	}
	*nativeErr = d->naterr;
	strcpy(sqlState, d->sqlstate);
	if (errmax == SQL_NTS) {
	    strcpy(errmsg, "[SQLite]");
	    strcat(errmsg, d->logmsg);
	    *errlen = strlen(errmsg);
	} else {
	    strncpy(errmsg, "[SQLite]", errmax);
	    if (errmax - 8 > 0) {
		strncpy(errmsg + 8, d->logmsg, errmax - 8);
	    }
	    *errlen = min(strlen(d->logmsg) + 8, errmax);
	}
	d->logmsg[0] = '\0';
	return SQL_SUCCESS;
    }
noerr:
    sqlState[0] = '\0';
    errmsg[0] = '\0';
    *nativeErr = 0;
    *errlen = 0;
    return SQL_NO_DATA_FOUND;
}

/**
 * Return last HDBC or HSTMT error message.
 * @param env environment handle or NULL
 * @param dbc database connection handle or NULL
 * @param stmt statement handle or NULL
 * @param sqlState output buffer for SQL state
 * @param nativeErr output buffer for native error code
 * @param errmsg output buffer for error message
 * @param errmax length of output buffer for error message
 * @param errlen output length of error message
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLError(SQLHENV env, SQLHDBC dbc, SQLHSTMT stmt,
	 SQLCHAR *sqlState, SQLINTEGER *nativeErr,
	 SQLCHAR *errmsg, SQLSMALLINT errmax, SQLSMALLINT *errlen)
{
    return drverror(env, dbc, stmt, sqlState, nativeErr,
		    errmsg, errmax, errlen);
}

/**
 * Return information for more result sets.
 * @param stmt statement handle
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLMoreResults(SQLHSTMT stmt)
{
    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    return SQL_NO_DATA;
}

/**
 * Internal query preparation used by SQLPrepare() and SQLExecDirect().
 * @param stmt statement handle
 * @param query query string
 * @param queryLen length of query string or SQL_NTS
 * @result ODBC error code
 */

static SQLRETURN
drvprepare(SQLHSTMT stmt, SQLCHAR *query, SQLINTEGER queryLen)
{
    STMT *s;
    DBC *d;
    char *errp = NULL;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    if (s->dbc == SQL_NULL_HDBC) {
noconn:
	return noconn(s);
    }
    d = s->dbc;
    if (!d->sqlite) {
	goto noconn;
    }
    s3stmt_end(s);
    freep(&s->query);
    s->query = fixupsql(query, queryLen, &s->nparams, &s->isselect, &errp);
    if (!s->query) {
	if (errp) {
	    setstat(s, -1, errp, (*s->ov3) ? "HY000" : "S1000");
	    return SQL_ERROR;
	}
	return nomem(s);
    }
    errp = NULL;
    freeresult(s, -1);
    if (s->isselect) {
	int ret, ncols;
	const char *rest;
	char *sql, **params = NULL;
	sqlite3_stmt *s3stmt = NULL;

	if (s->nparams) {
	    int i;

	    params = xmalloc(s->nparams * sizeof (char *));
	    if (!params) {
		return nomem(s);
	    }
	    for (i = 0; i < s->nparams; i++) {
		params[i] = NULL;
	    }
	}
	sql = sqlite3_vmprintf(s->query, (char *) params);
	freep(&params);
	if (!sql) {
	    return nomem(s);
	}
	ret = sqlite3_prepare(d->sqlite, sql, -1, &s3stmt, &rest);
	sqlite3_free(sql);
	if (ret != SQLITE_OK) {
	    if (s3stmt) {
		sqlite3_finalize(s3stmt);
	    }
	    setstat(s, ret, "%s (%d)", (*s->ov3) ? "HY000" : "S1000",
		    sqlite3_errmsg(d->sqlite), ret);
	    return SQL_ERROR;
	}
	ncols = sqlite3_column_count(s3stmt);
	if (ncols > 0) {
	    int i, size;
	    char *p;
	    COL *dyncols;
	    DBC *d = (DBC *) s->dbc;
	    const char *colname, *typename;

	    for (i = size = 0; i < ncols; i++) {
		colname = sqlite3_column_name(s3stmt, i);
		size += 3 + 3 * strlen(colname);
	    }
	    dyncols = xmalloc(ncols * sizeof (COL) + size);
	    if (!dyncols) {
		freedyncols(s);
		ncols = 0;
	    } else {
		p = (char *) (dyncols + ncols);
		for (i = 0; i < ncols; i++) {
		    char *q;

		    colname = sqlite3_column_name(s3stmt, i);
		    typename = s3stmt_coltype(s3stmt, i);
		    dyncols[i].db = ((DBC *) (s->dbc))->dbname;
		    strcpy(p, colname);
		    dyncols[i].label = p;
		    p += strlen(p) + 1;
		    q = strchr(colname, '.');
		    if (q) {
			dyncols[i].table = p;
			strncpy(p, colname, q - colname);
			p[q - colname] = '\0';
			p += strlen(p) + 1;
			strcpy(p, q + 1);
			dyncols[i].column = p;
			p += strlen(p) + 1;
		    } else {
			dyncols[i].table = "";
			strcpy(p, colname);
			dyncols[i].column = p;
			p += strlen(p) + 1;
		    }
#ifdef SQL_LONGVARCHAR
		    dyncols[i].type = SQL_LONGVARCHAR;
		    dyncols[i].size = 65536;
#else
		    dyncols[i].type = SQL_VARCHAR;
		    dyncols[i].size = 256;
#endif
		    dyncols[i].index = i;
		    dyncols[i].scale = 0;
		    dyncols[i].prec = 0;
		    dyncols[i].nosign = 1;
		    dyncols[i].autoinc = -1;
		    dyncols[i].typename = xstrdup(typename);
		}
		freedyncols(s);
		s->dyncols = s->cols = dyncols;
		s->dcols = ncols;
		fixupdyncols(s, d->sqlite);
	    }
	}
	s->ncols = ncols;
	sqlite3_finalize(s3stmt);
    }
    mkbindcols(s, s->ncols);
    if (s->nparams) {
	s->paramset_count = 0;
    }
    return SQL_SUCCESS;
}

/* see doc on top */

static SQLRETURN
drvexecute(SQLHSTMT stmt)
{
    STMT *s;
    DBC *d;
    char *errp = NULL, **params = NULL, *sql;
    int rc, i, size, ncols, busy_count, start_trans;
    SQLRETURN ret;

    if (stmt == SQL_NULL_HSTMT) {
	return SQL_INVALID_HANDLE;
    }
    s = (STMT *) stmt;
    if (s->dbc == SQL_NULL_HDBC) {
noconn:
	return noconn(s);
    }
    d = (DBC *) s->dbc;
    if (!d->sqlite) {
	goto noconn;
    }
    if (!s->query) {
	setstat(s, -1, "no query prepared", (*s->ov3) ? "HY000" : "S1000");
	return SQL_ERROR;
    }
    if (s->nbindparms < s->nparams) {
	setstat(s, -1, "unbound parameters in query",
		(*s->ov3) ? "HY000" : "S1000");
	return SQL_ERROR;
    }
    busy_count = 0;
    start_trans = !d->autocommit && !d->intrans;
again:
    s3stmt_end(s);
    for (i = size = 0; i < s->nparams; i++) {
	ret = substparam(s, i, NULL, &size);
	if (ret != SQL_SUCCESS) {
	    goto cleanup;
	}
    }
    if (s->nparams) {
	char *p;

	params = xmalloc(s->nparams * sizeof (char *) + size);
	if (!params) {
	    ret = nomem(s);
	    goto cleanup;
	}
	p = (char *) (params + s->nparams);
	for (i = 0; i < s->nparams; i++) {
	    int len = 0;

	    params[i] = p;
	    substparam(s, i, &p, NULL);
	    if (s->bindparms[i].ind) {
		len = s->bindparms[i].len;
	    } else if (s->bindparms[i].lenp) {
		len = *s->bindparms[i].lenp;
	    }
	    if (len == SQL_NULL_DATA) {
		params[i] = NULL;
	    }
	}
    }
    freeresult(s, 0);
    if (!d->autocommit && !d->intrans) {
begin_again:
	rc = sqlite3_exec(d->sqlite, "BEGIN TRANSACTION", NULL, NULL, &errp);
	if (rc == SQLITE_BUSY) {
	    if (busy_handler((void *) d, ++busy_count)) {
		if (errp) {
		    sqlite3_free(errp);
		    errp = NULL;
		}
		goto begin_again;
	    }
	}
	if (rc != SQLITE_OK) {
	    freep(&params);
	    setstat(s, rc, "%s (%d)", (*s->ov3) ? "HY000" : "S1000",
		    errp ? errp : "unknown error", rc);
	    if (errp) {
		sqlite3_free(errp);
		errp = NULL;
	    }
	    ret = SQL_ERROR;
	    goto cleanup;
	}
	d->intrans = 1;
	if (errp) {
	    sqlite3_free(errp);
	    errp = NULL;
	}
    }
    if (s->isselect && !d->intrans &&
	s->curtype == SQL_CURSOR_FORWARD_ONLY &&
	d->step_enable && s->nparams == 0 && d->cur_s3stmt == NULL) {
	s->nrows = -1;
	ret = s3stmt_start(s, params);
	if (ret == SQL_SUCCESS) {
	    freep(&params);
	    goto done2;
	}
    }
    sql = sqlite3_vmprintf(s->query, (char *) params);
    if (!sql) {
	freep(&params);
	ret = nomem(s);
	goto cleanup;
    }
    rc = sqlite3_get_table(d->sqlite, sql, &s->rows, &s->nrows, &ncols, &errp);
    sqlite3_free(sql);
    if (rc == SQLITE_BUSY) {
	if (busy_handler((void *) d, ++busy_count)) {
	    freep(&params);
	    if (errp) {
		sqlite3_free(errp);
		errp = NULL;
	    }
	    if (start_trans) {
		sqlite3_exec(d->sqlite, "ROLLBACK TRANSACTION;",
			     NULL, NULL, NULL);
		d->intrans = 0;
	    }
	    if (s->nparams) {
		for (i = 0; i < s->nparams; i++) {
		    BINDPARM *p = &s->bindparms[i];

		    p->param = p->param0;
		}
		s->paramset_count = 0;
		s->paramset_nrows = 0;
	    }
	    s->nrows = 0;
	    goto again;
	}
    }
    if (rc != SQLITE_OK) {
	freep(&params);
	setstat(s, rc, "%s (%d)", (*s->ov3) ? "HY000" : "S1000",
		errp ? errp : "unknown error", rc);
	if (errp) {
	    sqlite3_free(errp);
	    errp = NULL;
	}
	ret = SQL_ERROR;
	goto cleanup;
    }
    freep(&params);
    if (errp) {
	sqlite3_free(errp);
	errp = NULL;
    }
    s->rowfree = sqlite3_free_table;
    if (!s->isselect) {
	/*
	 * INSERT/UPDATE/DELETE results are immediately released.
	 */
	//set_last_serial(sqlite_last_insert_rowid());
	freeresult(s, -1);
	s->nrows = sqlite3_changes(d->sqlite);
	goto done;
    }
    if (s->ncols != ncols) {
	/*
	 * Weird result.
	 */
	setstat(s, -1, "broken result set %d/%d",
		(*s->ov3) ? "HY000" : "S1000", s->ncols, ncols);
	ret = SQL_ERROR;
	goto cleanup;
    }
done:
    mkbindcols(s, s->ncols);
done2:
    ret = SQL_SUCCESS;
    s->rowp = -1;
    if (s->nparams) {
	s->paramset_count++;
	s->paramset_nrows += s->nrows;
	if (s->paramset_count < s->paramset_size) {
	    for (i = 0; i < s->nparams; i++) {
		BINDPARM *p = &s->bindparms[i];

		if (p->param && p->inc > 0) {
		    p->param = (char *) p->param + p->inc;
		}
	    }
	    goto again;
	}
    }
cleanup:
    if (s->nparams) {
	for (i = 0; i < s->nparams; i++) {
	    BINDPARM *p = &s->bindparms[i];

	    p->param = p->param0;
	}
	s->nrows = s->paramset_nrows;
	s->paramset_count = 0;
	s->paramset_nrows = 0;
    }
    return ret;
}

/**
 * Prepare HSTMT.
 * @param stmt statement handle
 * @param query query string
 * @param queryLen length of query string or SQL_NTS
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLPrepare(SQLHSTMT stmt, SQLCHAR *query, SQLINTEGER queryLen)
{
    return drvprepare(stmt, query, queryLen);
}

/**
 * Execute query.
 * @param stmt statement handle
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLExecute(SQLHSTMT stmt)
{
    return drvexecute(stmt);
}

/**
 * Execute query directly.
 * @param stmt statement handle
 * @param query query string
 * @param queryLen length of query string or SQL_NTS
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLExecDirect(SQLHSTMT stmt, SQLCHAR *query, SQLINTEGER queryLen)
{
    if (drvprepare(stmt, query, queryLen) != SQL_SUCCESS) {
	return SQL_ERROR;
    }
    return drvexecute(stmt);
}

#ifdef _WIN32
#ifndef WITHOUT_DRIVERMGR

/*
 * Windows configuration dialog stuff.
 */

#include <windowsx.h>
#include <winuser.h>

#define stricmp _stricmp

static HINSTANCE NEAR hModule;	/* Saved module handle for resources */

#define MAXPATHLEN      (255+1)           /* Max path length */
#define MAXKEYLEN       (15+1)            /* Max keyword length */
#define MAXDESC         (255+1)           /* Max description length */
#define MAXDSNAME       (32+1)            /* Max data source name length */
#define MAXTONAME       (32+1)            /* Max timeout length */
#define MAXDBNAME	(255+1)

/* Attribute key indexes into an array of Attr structs, see below */

#define KEY_DSN 		0
#define KEY_DESC		1
#define KEY_DBNAME		2
#define KEY_BUSY		3
#define KEY_DRIVER		4
#define KEY_STEPAPI		5
#define NUMOFKEYS		6

typedef struct {
    BOOL supplied;
    char attr[MAXPATHLEN];
} ATTR;

typedef struct {
    SQLHWND parent;
    LPCSTR  driver;
    ATTR    attr[NUMOFKEYS];
    char    DSN[MAXDSNAME];
    BOOL    newDSN;
    BOOL    defDSN;
} SETUPDLG;

static struct {
    char *key;
    int ikey;
} attrLookup[] = {
    { "DSN", KEY_DSN },
    { "DESC", KEY_DESC },
    { "Description", KEY_DESC},
    { "Database", KEY_DBNAME },
    { "Timeout", KEY_BUSY },
    { "Driver", KEY_DRIVER },
    { "StepAPI", KEY_STEPAPI },
    { NULL, 0 }
};

/**
 * Setup dialog data from datasource attributes.
 * @param attribs attribute string
 * @param setupdlg pointer to dialog data
 */

static void
ParseAttributes(LPCSTR attribs, SETUPDLG *setupdlg)
{
    char *str = (char *) attribs, *start, key[MAXKEYLEN];
    int elem, nkey;

    while (*str) {
	start = str;
	if ((str = strchr(str, '=')) == NULL) {
	    return;
	}
	elem = -1;
	nkey = str - start;
	if (nkey < sizeof (key)) {
	    int i;

	    memcpy(key, start, nkey);
	    key[nkey] = '\0';
	    for (i = 0; attrLookup[i].key; i++) {
		if (stricmp(attrLookup[i].key, key) == 0) {
		    elem = attrLookup[i].ikey;
		    break;
		}
	    }
	}
	start = ++str;
	while (*str && *str != ';') {
	    ++str;
	}
	if (elem >= 0) {
	    int end = min(str - start, sizeof (setupdlg->attr[elem].attr) - 1);

	    setupdlg->attr[elem].supplied = TRUE;
	    memcpy(setupdlg->attr[elem].attr, start, end);
	    setupdlg->attr[elem].attr[end] = '\0';
	}
	++str;
    }
}

/**
 * Set datasource attributes in registry.
 * @param parent handle of parent window
 * @param setupdlg pointer to dialog data
 * @result true or false
 */

static BOOL
SetDSNAttributes(HWND parent, SETUPDLG *setupdlg)
{
    char *dsn = setupdlg->attr[KEY_DSN].attr;

    if (setupdlg->newDSN && strlen(dsn) == 0) {
	return FALSE;
    }
    if (!SQLWriteDSNToIni(dsn, setupdlg->driver)) {
	if (parent) {
	    char buf[MAXPATHLEN], msg[MAXPATHLEN];

	    LoadString(hModule, IDS_BADDSN, buf, sizeof (buf));
	    wsprintf(msg, buf, dsn);
	    LoadString(hModule, IDS_MSGTITLE, buf, sizeof (buf));
	    MessageBox(parent, msg, buf,
		       MB_ICONEXCLAMATION | MB_OK | MB_TASKMODAL |
		       MB_SETFOREGROUND);
	}
	return FALSE;
    }
    if (parent || setupdlg->attr[KEY_DESC].supplied) {
	SQLWritePrivateProfileString(dsn, "Description",
				     setupdlg->attr[KEY_DESC].attr,
				     ODBC_INI);
    }
    if (parent || setupdlg->attr[KEY_DBNAME].supplied) {
	SQLWritePrivateProfileString(dsn, "Database",
				     setupdlg->attr[KEY_DBNAME].attr,
				     ODBC_INI);
    }
    if (parent || setupdlg->attr[KEY_BUSY].supplied) {
	SQLWritePrivateProfileString(dsn, "Timeout",
				     setupdlg->attr[KEY_BUSY].attr,
				     ODBC_INI);
    }
    if (parent || setupdlg->attr[KEY_STEPAPI].supplied) {
	SQLWritePrivateProfileString(dsn, "StepAPI",
				     setupdlg->attr[KEY_STEPAPI].attr,
				     ODBC_INI);
    }
    if (setupdlg->attr[KEY_DSN].supplied &&
	stricmp(setupdlg->DSN, setupdlg->attr[KEY_DSN].attr)) {
	SQLRemoveDSNFromIni(setupdlg->DSN);
    }
    return TRUE;
}

/**
 * Get datasource attributes from registry.
 * @param setupdlg pointer to dialog data
 */

static void
GetAttributes(SETUPDLG *setupdlg)
{
    char *dsn = setupdlg->attr[KEY_DSN].attr;

    if (!setupdlg->attr[KEY_DESC].supplied) {
	SQLGetPrivateProfileString(dsn, "Description", "",
				   setupdlg->attr[KEY_DESC].attr,
				   sizeof (setupdlg->attr[KEY_DESC].attr),
				   ODBC_INI);
    }
    if (!setupdlg->attr[KEY_DBNAME].supplied) {
	SQLGetPrivateProfileString(dsn, "Database", "",
				   setupdlg->attr[KEY_DBNAME].attr,
				   sizeof (setupdlg->attr[KEY_DBNAME].attr),
				   ODBC_INI);
    }
    if (!setupdlg->attr[KEY_BUSY].supplied) {
	SQLGetPrivateProfileString(dsn, "Timeout", "1000",
				   setupdlg->attr[KEY_BUSY].attr,
				   sizeof (setupdlg->attr[KEY_BUSY].attr),
				   ODBC_INI);
    }
    if (!setupdlg->attr[KEY_STEPAPI].supplied) {
	SQLGetPrivateProfileString(dsn, "StepAPI", "0",
				   setupdlg->attr[KEY_STEPAPI].attr,
				   sizeof (setupdlg->attr[KEY_STEPAPI].attr),
				   ODBC_INI);
    }
}

/**
 * Open file dialog for selection of SQLite database file.
 * @param hdlg handle of originating dialog window
 */

static void
GetDBFile(HWND hdlg)
{
    SETUPDLG *setupdlg = (SETUPDLG *) GetWindowLong(hdlg, DWL_USER);
    OPENFILENAME ofn;

    memset(&ofn, 0, sizeof (ofn));
    ofn.lStructSize = sizeof (ofn);
    ofn.hwndOwner = hdlg;
    ofn.hInstance = (HINSTANCE) GetWindowLong(hdlg, GWL_HINSTANCE);
    ofn.lpstrFile = (LPTSTR) setupdlg->attr[KEY_DBNAME].attr;
    ofn.nMaxFile = MAXPATHLEN;
    ofn.Flags = OFN_HIDEREADONLY | OFN_PATHMUSTEXIST |
		OFN_NOCHANGEDIR | OFN_EXPLORER | OFN_FILEMUSTEXIST;
    if (GetOpenFileName(&ofn)) {
	SetDlgItemText(hdlg, IDC_DBNAME, setupdlg->attr[KEY_DBNAME].attr);
	setupdlg->attr[KEY_DBNAME].supplied = TRUE;
    }
}

/**
 * Dialog procedure for ConfigDSN().
 * @param hdlg handle of dialog window
 * @param wmsg type of message
 * @param wparam wparam of message
 * @param lparam lparam of message
 * @result true or false
 */

static BOOL CALLBACK
ConfigDlgProc(HWND hdlg, WORD wmsg, WPARAM wparam, LPARAM lparam)
{
    SETUPDLG *setupdlg = NULL;

    switch (wmsg) {
    case WM_INITDIALOG:
	SetWindowLong(hdlg, DWL_USER, lparam);
	setupdlg = (SETUPDLG *) lparam;
	GetAttributes(setupdlg);
	SetDlgItemText(hdlg, IDC_DSNAME, setupdlg->attr[KEY_DSN].attr);
	SetDlgItemText(hdlg, IDC_DESC, setupdlg->attr[KEY_DESC].attr);
	SetDlgItemText(hdlg, IDC_DBNAME, setupdlg->attr[KEY_DBNAME].attr);
	SetDlgItemText(hdlg, IDC_TONAME, setupdlg->attr[KEY_BUSY].attr);
	CheckDlgButton(hdlg, IDC_STEPAPI,
		       getbool(setupdlg->attr[KEY_STEPAPI].attr) ?
		       BST_CHECKED : BST_UNCHECKED);
	if (setupdlg->defDSN) {
	    EnableWindow(GetDlgItem(hdlg, IDC_DSNAME), FALSE);
	    EnableWindow(GetDlgItem(hdlg, IDC_DSNAMETEXT), FALSE);
	} else {
	    SendDlgItemMessage(hdlg, IDC_DSNAME,
			       EM_LIMITTEXT, (WPARAM) (MAXDSNAME - 1), 0L);
	    SendDlgItemMessage(hdlg, IDC_DESC,
			       EM_LIMITTEXT, (WPARAM) (MAXDESC - 1), 0L);
	    SendDlgItemMessage(hdlg, IDC_DBNAME,
			       EM_LIMITTEXT, (WPARAM) (MAXDBNAME - 1), 0L);
	    SendDlgItemMessage(hdlg, IDC_TONAME,
			       EM_LIMITTEXT, (WPARAM) (MAXTONAME - 1), 0L);
	}
	return TRUE;
    case WM_COMMAND:
	switch (GET_WM_COMMAND_ID(wparam, lparam)) {
	case IDC_DSNAME:
	    if (GET_WM_COMMAND_CMD(wparam, lparam) == EN_CHANGE) {
		char item[MAXDSNAME];

		EnableWindow(GetDlgItem(hdlg, IDOK),
			     GetDlgItemText(hdlg, IDC_DSNAME,
					    item, sizeof (item)));
		return TRUE;
	    }
	    break;
	case IDC_BROWSE:
	    GetDBFile(hdlg);
	    break;
	case IDOK:
	    setupdlg = (SETUPDLG *) GetWindowLong(hdlg, DWL_USER);
	    if (!setupdlg->defDSN) {
		GetDlgItemText(hdlg, IDC_DSNAME,
			       setupdlg->attr[KEY_DSN].attr,
			       sizeof (setupdlg->attr[KEY_DSN].attr));
	    }
	    GetDlgItemText(hdlg, IDC_DESC,
			   setupdlg->attr[KEY_DESC].attr,
			   sizeof (setupdlg->attr[KEY_DESC].attr));
	    GetDlgItemText(hdlg, IDC_DBNAME,
			   setupdlg->attr[KEY_DBNAME].attr,
			   sizeof (setupdlg->attr[KEY_DBNAME].attr));
	    GetDlgItemText(hdlg, IDC_TONAME,
			   setupdlg->attr[KEY_BUSY].attr,
			   sizeof (setupdlg->attr[KEY_BUSY].attr));
	    strcpy(setupdlg->attr[KEY_STEPAPI].attr,
		   IsDlgButtonChecked(hdlg, IDC_STEPAPI) == BST_CHECKED ?
		   "1" : "0");
	    SetDSNAttributes(hdlg, setupdlg);
	    /* FALL THROUGH */
	case IDCANCEL:
	    EndDialog(hdlg, wparam);
	    return TRUE;
	}
	break;
    }
    return FALSE;
}

/**
 * ODBC INSTAPI procedure for DSN configuration.
 * @param hwnd parent window handle
 * @param request type of request
 * @param driver driver name
 * @param attribs attribute string of DSN
 * @result true or false
 */
//AUBIT change - several variables used here are defined inside #ifndef WITHOUT_DRIVERMGR
#ifndef WITHOUT_DRIVERMGR
BOOL INSTAPI
ConfigDSN(HWND hwnd, WORD request, LPCSTR driver, LPCSTR attribs)
{
    BOOL success;
    SETUPDLG *setupdlg;

    setupdlg = (SETUPDLG *) xmalloc(sizeof (SETUPDLG));
    if (setupdlg == NULL) {
	return FALSE;
    }
    memset(setupdlg, 0, sizeof (SETUPDLG));
    if (attribs) {
	ParseAttributes(attribs, setupdlg);
    }
    if (setupdlg->attr[KEY_DSN].supplied) {
	strcpy(setupdlg->DSN, setupdlg->attr[KEY_DSN].attr);
    } else {
	setupdlg->DSN[0] = '\0';
    }
    if (request == ODBC_REMOVE_DSN) {
	if (!setupdlg->attr[KEY_DSN].supplied) {
	    success = FALSE;
	} else {
	    success = SQLRemoveDSNFromIni(setupdlg->attr[KEY_DSN].attr);
	}
    } else {
	setupdlg->parent = hwnd;
	setupdlg->driver = driver;
	setupdlg->newDSN = request == ODBC_ADD_DSN;
	setupdlg->defDSN = stricmp(setupdlg->attr[KEY_DSN].attr,
				   "Default") == 0;
	if (hwnd) {
	    success = DialogBoxParam(hModule, MAKEINTRESOURCE(CONFIGDSN),
				     hwnd, (DLGPROC) ConfigDlgProc,
				     (LONG) setupdlg) == IDOK;
	} else if (setupdlg->attr[KEY_DSN].supplied) {
	    success = SetDSNAttributes(hwnd, setupdlg);
	} else {
	    success = FALSE;
	}
    }
    xfree(setupdlg);
    return success;
}
#endif //AUBIT change
/**
 * Dialog procedure for SQLDriverConnect().
 * @param hdlg handle of dialog window
 * @param wmsg type of message
 * @param wparam wparam of message
 * @param lparam lparam of message
 * @result true or false
 */

static BOOL CALLBACK
DriverConnectProc(HWND hdlg, WORD wmsg, WPARAM wparam, LPARAM lparam)
{
    SETUPDLG *setupdlg;

    switch (wmsg) {
    case WM_INITDIALOG:
	SetWindowLong(hdlg, DWL_USER, lparam);
	setupdlg = (SETUPDLG *) lparam;
	SetDlgItemText(hdlg, IDC_DSNAME, setupdlg->attr[KEY_DSN].attr);
	SetDlgItemText(hdlg, IDC_DESC, setupdlg->attr[KEY_DESC].attr);
	SetDlgItemText(hdlg, IDC_DBNAME, setupdlg->attr[KEY_DBNAME].attr);
	SetDlgItemText(hdlg, IDC_TONAME, setupdlg->attr[KEY_BUSY].attr);
	SendDlgItemMessage(hdlg, IDC_DSNAME,
			   EM_LIMITTEXT, (WPARAM) (MAXDSNAME - 1), 0L);
	SendDlgItemMessage(hdlg, IDC_DESC,
			   EM_LIMITTEXT, (WPARAM) (MAXDESC - 1), 0L);
	SendDlgItemMessage(hdlg, IDC_DBNAME,
			   EM_LIMITTEXT, (WORD)(MAXDBNAME - 1), 0L);
	SendDlgItemMessage(hdlg, IDC_TONAME,
			   EM_LIMITTEXT, (WORD)(MAXTONAME - 1), 0L);
	CheckDlgButton(hdlg, IDC_STEPAPI,
		       getbool(setupdlg->attr[KEY_STEPAPI].attr) ?
		       BST_CHECKED : BST_UNCHECKED);
	return TRUE;
    case WM_COMMAND:
	switch (GET_WM_COMMAND_ID(wparam, lparam)) {
	case IDC_BROWSE:
	    GetDBFile(hdlg);
	    break;
	case IDOK:
	    setupdlg = (SETUPDLG *) GetWindowLong(hdlg, DWL_USER);
	    GetDlgItemText(hdlg, IDC_DSNAME,
			   setupdlg->attr[KEY_DSN].attr,
			   sizeof (setupdlg->attr[KEY_DSN].attr));
	    GetDlgItemText(hdlg, IDC_DBNAME,
			   setupdlg->attr[KEY_DBNAME].attr,
			   sizeof (setupdlg->attr[KEY_DBNAME].attr));
	    GetDlgItemText(hdlg, IDC_TONAME,
			   setupdlg->attr[KEY_BUSY].attr,
			   sizeof (setupdlg->attr[KEY_BUSY].attr));
	    strcpy(setupdlg->attr[KEY_STEPAPI].attr,
		   IsDlgButtonChecked(hdlg, IDC_STEPAPI) == BST_CHECKED ?
		   "1" : "0");
	    /* FALL THROUGH */
	case IDCANCEL:
	    EndDialog(hdlg, GET_WM_COMMAND_ID(wparam, lparam) == IDOK);
	    return TRUE;
	}
    }
    return FALSE;
}

/**
 * Internal connect using a driver connection string.
 * @param dbc database connection handle
 * @param hwnd parent window handle
 * @param connIn driver connect input string
 * @param connInLen length of driver connect input string or SQL_NTS
 * @param connOut driver connect output string
 * @param connOutMax length of driver connect output string
 * @param connOutLen output length of driver connect output string
 * @param drvcompl completion type
 * @result ODBC error code
 */

static SQLRETURN
drvdriverconnect(SQLHDBC dbc, SQLHWND hwnd,
		 SQLCHAR *connIn, SQLSMALLINT connInLen,
		 SQLCHAR *connOut, SQLSMALLINT connOutMax,
		 SQLSMALLINT *connOutLen, SQLUSMALLINT drvcompl)
{
    BOOL maybeprompt, prompt = FALSE;
    DBC *d;
    SETUPDLG *setupdlg;
    short ret;
    SQLRETURN rc;

    if (dbc == SQL_NULL_HDBC) {
	return SQL_INVALID_HANDLE;
    }
    d = (DBC *) dbc;
    if (d->sqlite) {
	setstatd(d, -1, "connection already established", "08002");
	return SQL_ERROR;
    }
    setupdlg = (SETUPDLG *) xmalloc(sizeof (SETUPDLG));
    if (setupdlg == NULL) {
	return SQL_ERROR;
    }
    memset(setupdlg, 0, sizeof (SETUPDLG));
    maybeprompt = drvcompl == SQL_DRIVER_COMPLETE ||
	drvcompl == SQL_DRIVER_COMPLETE_REQUIRED;
    if (connIn == NULL || !connInLen ||
	(connInLen == SQL_NTS && !connIn[0])) {
	prompt = TRUE;
    } else {
	ParseAttributes(connIn, setupdlg);
	if (!setupdlg->attr[KEY_DSN].attr[0] &&
	    drvcompl == SQL_DRIVER_COMPLETE_REQUIRED) {
	    strcpy(setupdlg->attr[KEY_DSN].attr, "DEFAULT");
	}
	GetAttributes(setupdlg);
	if (drvcompl == SQL_DRIVER_PROMPT ||
	    (maybeprompt &&
	     !setupdlg->attr[KEY_DSN].attr[0] ||
	     !setupdlg->attr[KEY_DBNAME].attr[0])) {
	    prompt = TRUE;
	}
    }
retry:
    if (prompt) {
	ret = DialogBoxParam(hModule, MAKEINTRESOURCE(DRIVERCONNECT),
			     hwnd, (DLGPROC) DriverConnectProc,
			     (LONG) setupdlg);
	if (!ret || ret == -1) {
	    xfree(setupdlg);
	    return SQL_NO_DATA_FOUND;
	}
    }
    if (connOut || connOutLen) {
	char buf[1024];
	int len, count;
	char dsn_0 = setupdlg->attr[KEY_DSN].attr[0];
	char drv_0 = setupdlg->attr[KEY_DRIVER].attr[0];

	buf[0] = '\0';
	count = snprintf(buf, sizeof (buf),
			 "%s%s%s%s%s%sDatabase=%s;StepAPI=%s;"
			 "Timeout=%s",
			 dsn_0 ? "DSN=" : "",
			 dsn_0 ? setupdlg->attr[KEY_DSN].attr : "",
			 dsn_0 ? ";" : "",
			 drv_0 ? "Driver=" : "",
			 drv_0 ? setupdlg->attr[KEY_DRIVER].attr : "",
			 drv_0 ? ";" : "",
			 setupdlg->attr[KEY_DBNAME].attr,
			 setupdlg->attr[KEY_STEPAPI].attr,
			 setupdlg->attr[KEY_BUSY].attr);
	if (count < 0) {
	    buf[sizeof (buf) - 1] = '\0';
	}
	len = min(connOutMax - 1, strlen(buf));
	if (connOut) {
	    strncpy(connOut, buf, len);
	    connOut[len] = '\0';
	}
	if (connOutLen) {
	    *connOutLen = len;
	}
    }
    rc = dbopen(d, setupdlg->attr[KEY_DBNAME].attr,
		setupdlg->attr[KEY_DSN].attr,
		setupdlg->attr[KEY_STEPAPI].attr,
		setupdlg->attr[KEY_BUSY].attr);
    if (rc != SQL_SUCCESS) {
	if (maybeprompt && !prompt) {
	    prompt = TRUE;
	    goto retry;
	}
	xfree(setupdlg);
	return rc;
    }
    xfree(setupdlg);
    return SQL_SUCCESS;
}

#endif /* WITHOUT_DRIVERMGR */
#endif /* _WIN32 */

#ifndef WITHOUT_DRIVERMGR

/**
 * Connect using a driver connection string.
 * @param dbc database connection handle
 * @param hwnd parent window handle
 * @param connIn driver connect input string
 * @param connInLen length of driver connect input string or SQL_NTS
 * @param connOut driver connect output string
 * @param connOutMax length of driver connect output string
 * @param connOutLen output length of driver connect output string
 * @param drvcompl completion type
 * @result ODBC error code
 */

SQLRETURN SQL_API
SQLDriverConnect(SQLHDBC dbc, SQLHWND hwnd,
		 SQLCHAR *connIn, SQLSMALLINT connInLen,
		 SQLCHAR *connOut, SQLSMALLINT connOutMax,
		 SQLSMALLINT *connOutLen, SQLUSMALLINT drvcompl)
{
    return drvdriverconnect(dbc, hwnd, connIn, connInLen,
			    connOut, connOutMax, connOutLen, drvcompl);
}

#endif /* WITHOUT_DRIVERMGR */

#ifdef _WIN32

/**
 * DLL initializer for WIN32.
 * @param hinst instance handle
 * @param reason reason code for entry point
 * @param reserved
 * @result always true
 */
//AUBIT change - several variables used here are earlied defined inside #ifndef WITHOUT_DRIVERMGR
#ifndef WITHOUT_DRIVERMGR
BOOL APIENTRY
LibMain(HANDLE hinst, DWORD reason, LPVOID reserved)
{
    static int initialized = 0;

    switch (reason) {
    case DLL_PROCESS_ATTACH:
	if (!initialized++) {
	    hModule = hinst;
	}
	break;
    case DLL_THREAD_ATTACH:
	break;
    case DLL_PROCESS_DETACH:
	--initialized;
	break;
    case DLL_THREAD_DETACH:
	break;
    default:
	break;
    }
    return TRUE;
}
#endif //AUBIT
/**
 * DLL entry point for WIN32.
 * @param hinst instance handle
 * @param reason reason code for entry point
 * @param reserved
 * @result always true
 */
#ifndef __MINGW32__
int __stdcall
DllMain(HANDLE hinst, DWORD reason, LPVOID reserved)
{
    return LibMain(hinst, reason, reserved);
}
#endif

#endif /* _WIN32 */

#if defined(HAVE_ODBCINSTEXT_H) && HAVE_ODBCINSTEXT_H

/*
 * unixODBC property page for this driver,
 * may or may not work depending on unixODBC version.
 */

#include <odbcinstext.h>

int
ODBCINSTGetProperties(HODBCINSTPROPERTY prop)
{
    static const char *instYN[] = { "No", "Yes", NULL };

    prop->pNext = (HODBCINSTPROPERTY) malloc(sizeof (ODBCINSTPROPERTY));
    prop = prop->pNext;
    memset(prop, 0, sizeof (ODBCINSTPROPERTY));
    prop->nPromptType = ODBCINST_PROMPTTYPE_FILENAME;
    strncpy(prop->szName, "Database", INI_MAX_PROPERTY_NAME);
    strncpy(prop->szValue, "", INI_MAX_PROPERTY_VALUE);
    prop->pNext = (HODBCINSTPROPERTY) malloc(sizeof (ODBCINSTPROPERTY));
    prop = prop->pNext;
    memset(prop, 0, sizeof (ODBCINSTPROPERTY));
    prop->nPromptType = ODBCINST_PROMPTTYPE_TEXTEDIT;
    strncpy(prop->szName, "Timeout", INI_MAX_PROPERTY_NAME);
    strncpy(prop->szValue, "1000", INI_MAX_PROPERTY_VALUE);
    prop->pNext = (HODBCINSTPROPERTY) malloc(sizeof (ODBCINSTPROPERTY));
    prop = prop->pNext;
    memset(prop, 0, sizeof (ODBCINSTPROPERTY));
    prop->nPromptType = ODBCINST_PROMPTTYPE_COMBOBOX;
    prop->aPromptData = malloc (sizeof (instYN));
    memcpy(prop->aPromptData, instYN, sizeof (instYN));
    strncpy(prop->szName, "StepAPI", INI_MAX_PROPERTY_NAME);
    strncpy(prop->szValue, "No", INI_MAX_PROPERTY_VALUE);
    return 1;
}

#endif /* HAVE_ODBCINSTEXT_H */
