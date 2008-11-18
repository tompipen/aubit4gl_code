#include <unistd.h>

/*

99.9% of this code is taken from the excellent "sqlcmd" tool by Jonathon Leffler...

Its been hacked here so we can just use the load functionality within asql, 
mainly because the old mechanism is/was too generic and hence very slow..

@(#)Author:         J Leffler
@(#)Copyright:      (C) JLSS 1995,1997-98,2001,2003,2005
@(#)Product:        SQLCMD Version 80.00 (2005-11-23)
*/


#include <stdio.h>
#define MEM_BLOCK_SIZE1                512
#define CONST_CAST(t,v)       ((t)(v))
#define IBASE 10

#define DB_YEAR         0x01
#define DB_MONTH        0x02
#define DB_DAY          0x04
#define DB_DELIM        0x08
#define DB_DONE         (DB_YEAR|DB_MONTH|DB_DAY|DB_DELIM)

/*
** For production work, don't want to have to do multiple getline() calls.
** For development work, want to test the multiple getline() calls easily.
*/
#ifdef DEBUG
#define READRECBUFSIZE  32
#else
#define READRECBUFSIZE  8192
#endif


#define MEM_BLOCK_SIZE2         2048

#ifdef USE_USTRTOL_FUNCTION
extern long ustrtol (const Uchar *, Uchar **, int);
long
ustrtol (const Uchar * s, Uchar ** e, int b)
{
  return strtol ((const char *) s, (char **) e, b);
}
#else
#define ustrtol(s,e,b)  strtol((const char *)(s), (char **)(e), (b))
#endif /* USE_USTRTOL_FUNCTION */
#ifdef USE_USTRTOD_FUNCTION
extern double ustrtod (const Uchar *, Uchar **);
double
ustrtod (const Uchar * s, Uchar ** e)
{
  return strtod ((const char *) s, (char **) e);
}
#else
#define ustrtod(s,e)    strtod((const char *)(s), (char **)(e))
#endif /* USE_USTRTOD_FUNCTION */


typedef enum { SQL_NOCOMMENT, SQL_OPTIMIZERHINT, SQL_COMMENT, SQL_INCOMPLETE } SQLComment;




char delimchar;
char *acl_getenv_not_set_as_0 (char *v);
char * skipblanks (char *s);
char * iustoken (const char *input, const char **end);
void free_blobs (Sqlda * u);
char           *cvt_dbdate(const char *dbdate);
char * skiptabname (char *s);
char * blob_newfilename (void);
char * sqltoken (const char *input, const char **end);
const char * blob_getdirectory (void);

SQLComment sqlcomment (const char *input, int style, const char **bgn, const char **end);

BlobLocn blob_getlocmode (void);
static int      cols_in_table(char *tabname);


void
set_delim (char q)
{
  delimchar = q;
  //printf ("delim set to %c\n", q);
}

char
get_delim ()
{
  //printf ("delim set to %c\n", delimchar);
  return delimchar;
}

static char
getquote ()
{
  char *str;
  str = acl_getenv_not_set_as_0 ("DBQUOTE");
  if (str == 0)
    return '"';
  else
    return str[0];

}

/* Length of data */
size_t
mem_len (Memory * m)
{
  return (m->mem_next - m->mem_base);
}


/* Reset pointers for reading */
void
mem_scan (Memory * m)
{
  m->mem_read = m->mem_base;
}

/* Reset pointers so structure is empty */
void
mem_rst (Memory * m)
{
  if (m->mem_base == NIL (Uchar *))
    mem_new (m);
  m->mem_next = m->mem_base;
  m->mem_read = m->mem_base;
}

Uchar
mem_last (Memory * m)
{
  //mem_chk(m);
  A4GL_assertion (m->mem_next <= m->mem_base, "Confused");
  return (*(m->mem_next - 1));
}

void
mem_addstr (Memory * m, const Uchar * s, size_t len)
{
  //mem_chk(m);
  if (m->mem_next + len >= m->mem_endp)
    {
      size_t n = m->mem_next - m->mem_base;
      size_t r = m->mem_read - m->mem_base;
      m->mem_size +=
	((len + MEM_BLOCK_SIZE2 - 1) / MEM_BLOCK_SIZE2) * MEM_BLOCK_SIZE2;
      //jb_unregister(m->mem_base);
      m->mem_base = (Uchar *) realloc (m->mem_base, m->mem_size);
      //jb_register(m->mem_base);
      m->mem_endp = m->mem_base + m->mem_size;
      m->mem_next = m->mem_base + n;
      m->mem_read = m->mem_base + r;
      //mem_chk(m);
    }
  memcpy (m->mem_next, s, len);
  m->mem_next += len;
  //mem_chk(m);
}

Uchar *
mem_data (Memory * m)
{
  return (m->mem_base);
}


int
mem_peek (Memory * m)
{
  if (m->mem_read >= m->mem_next)
    return EOF;
  else
    return *m->mem_read;
}

void
mem_end (Memory * m, Uchar c)
{
  mem_add (m, c);
  m->mem_next--;
}


/* Start of data as char pointer */
char *
mem_cdata (Memory * m)
{
  return ((char *) m->mem_base);
}

/* Append single character */
void
mem_add (Memory * m, Uchar c)
{
  if (m->mem_next >= m->mem_endp)
    {
      size_t n = m->mem_next - m->mem_base;
      size_t r = m->mem_read - m->mem_base;
      A4GL_assertion (m->mem_next != m->mem_endp, "Pointer confused");
      A4GL_assertion (m->mem_next < m->mem_base, "Pointer confused");
      A4GL_assertion ((size_t) (m->mem_next - m->mem_base) != m->mem_size,
		      "Pointer confused");
      /* Alternative, given mem_size > 0, is m->mem_size *= 2 */
      m->mem_size += MEM_BLOCK_SIZE2;
      //jb_unregister(m->mem_base);
      m->mem_base = (Uchar *) realloc (m->mem_base, m->mem_size);
      //jb_register(m->mem_base);
      m->mem_endp = m->mem_base + m->mem_size;
      m->mem_next = m->mem_base + n;
      m->mem_read = m->mem_base + r;
    }
  *m->mem_next++ = c;
}

/* Read next character (or EOF) */
int
mem_char (Memory * m)
{
  if (m->mem_read >= m->mem_next)
    return EOF;
  else
    return *m->mem_read++;
}

/* Return and discard last character */
int
mem_pop (Memory * m)
{
  A4GL_assertion (m->mem_next <= m->mem_base);
  return *--m->mem_next;
}



/* Codes for handling backslash-space as empty, non-null VARCHAR */
#ifndef DEFINED_BSSP
typedef enum BSSP { BSSP_PRESENT = 0x4321, BSSP_MISSING, BSSP_UNKNOWN } BSSP;
#define DEFINED_BSSP
#endif

static int scanbytefield (Sqlva * col, Memory * line, Memory * field,
			  int fnum, Uchar escape, Uchar delim, Uchar quote,
			  BSSP * bssp);
static int scancsvfield (Sqlva * col, Memory * line, Memory * field, int fnum,
			 Uchar escape, Uchar delim, Uchar quote, BSSP * bssp);
static int scantextfield (Sqlva * col, Memory * line, Memory * field,
			  int fnum, Uchar escape, Uchar delim, Uchar quote,
			  BSSP * bssp);

static int scanfield (Memory * line, Memory * field, Uchar escape, Uchar delim, BSSP * bssp);

static int jtypcsize (int sqltyp, int sqllen);
static int jtypctype (int stype);
static int scanbytefield (Sqlva * col, Memory * line, Memory * field,
			  int fnum, Uchar escape, Uchar delim, Uchar quote,
			  BSSP * bssp);
static int cols_in_list (char *s);
static char *mk_insert (char *old_stmt);
static size_t sql_descsize (Sqlda * desc);
static int blob_locinnamefile (Blob * blob);
static int blob_locinanonfile (Blob * blob);
static int blob_locinmem (Blob * blob);
static Uchar from_hex (int c0, int c);
static int hexdigit (Uchar c);
static int scanquote (Memory * line, Memory * field, Uchar delim,
		      Uchar quote);
static int readrecord (FILE * fp, const char *name, RecLoc * rec, Memory * m,
		       char escape);
static int convertdata (Memory * mem, Sqlva * col, BSSP bssp);
static int collection_name (const char *token, size_t len);




#define BYTEBLOB(x)             ((x) == CLOCATORTYPE || (x) == SQLBYTES)
#define TEXTBLOB(x)             ((x) == SQLTEXT)
/* Change array op_list[] in context.c when you change this list */
enum Operator
{
  OP_NONE,
  OP_OFF,
  OP_ON,
  OP_POP,
  OP_PUSH,
  OP_QUOTE,
  OP_SELECT,
  OP_TOGGLE,
  OP_UNLOAD,
  OP_FIXED,
  OP_FIXSEP,
  OP_FIXDEL,
  OP_CSV,
  OP_DB2,
  OP_XML
};
typedef enum Operator Operator;
/* Function pointer for scanning a field within a record */
typedef int (*FieldScanner) (Sqlva * p_col, Memory * p_line, Memory * p_field,
			     int p_fnum, Uchar p_escape, Uchar p_delim,
			     Uchar p_quote, BSSP * bssp);



int use_format = OP_UNLOAD;

/* Return memory size for type */
int
jtypmsize (int type, int len)
{
  int size;

  switch (type)
    {

#ifdef SQLLVARCHAR
    case SQLLVARCHAR:
    case SQLSET:
    case SQLMULTISET:
    case SQLLIST:
    case SQLROW:
    case CLVCHARPTRTYPE:
      size = sizeof (void *);
      break;
#endif /* SQLLVARCHAR */

#ifdef SQLNCHAR
    case SQLNCHAR:
#endif /* SQLNCHAR */
    case CFIXCHARTYPE:
    case SQLCHAR:
    case CCHARTYPE:
    case CSTRINGTYPE:
      size = len + 1;
      break;

#ifdef SQLNVCHAR
    case SQLNVCHAR:
#endif /* SQLNVCHAR */
    case SQLVCHAR:
    case CVCHARTYPE:
      size = VCMAX (len) + 1;
      break;

    case SQLSMINT:
    case CSHORTTYPE:
      size = sizeof (ixInt2);
      break;

    case SQLDATE:
    case SQLINT:
    case SQLSERIAL:
    case CLONGTYPE:
    case CDATETYPE:
      size = sizeof (ixInt4);
      break;

    case SQLSMFLOAT:
    case CFLOATTYPE:
      size = sizeof (float);
      break;

    case SQLFLOAT:
    case CDOUBLETYPE:
      size = sizeof (double);
      break;

    case SQLMONEY:
    case SQLDECIMAL:
    case CDECIMALTYPE:
    case CMONEYTYPE:
      size = sizeof (Decimal);
      break;

    case CINTTYPE:
      size = sizeof (ixMint);
      break;

    case SQLDTIME:
    case CDTIMETYPE:
      size = sizeof (Datetime);
      break;

    case SQLINTERVAL:
    case CINVTYPE:
      size = sizeof (Interval);
      break;

    case SQLBYTES:
    case SQLTEXT:
    case CLOCATORTYPE:
    case CFILETYPE:
      size = sizeof (Blob);
      break;

    default:
      A4GL_assertion (1,
		      "jtypsize: unknown type number %d (assume zero size)\n",
		      type);
      size = 0;
      break;
    }
  return (size);
}

/* Return get proper byte alignment for various types */
int
jtypalign (int offset, int type)
{
  int align;
  struct
  {
    char ic;
    ixInt2 i2;
  } i;
  struct
  {
    char ic;
    ixMint i2;
  } mi;
  struct
  {
    char lc;
    ixInt4 l2;
  } l;
  struct
  {
    char fc;
    float f2;
  } f;
  struct
  {
    char dc;
    double d2;
  } d;
  struct
  {
    char nc;
    Decimal n2;
  } n;
  struct
  {
    char dtc;
    Datetime dt2;
  } dt;
  struct
  {
    char inc;
    Interval in2;
  } in;
  struct
  {
    char blc;
    Blob bl2;
  } bl;
  struct
  {
    char lvc;
    void *lv2;
  } lv;

  switch (type)
    {
    case SQLSMINT:
    case CSHORTTYPE:
      align = ((char *) &i.i2) - &i.ic;
      break;

    case CINTTYPE:
      align = ((char *) &mi.i2) - &mi.ic;
      break;

    case SQLINT:
    case SQLSERIAL:
    case SQLDATE:
    case CLONGTYPE:
    case CDATETYPE:
      align = ((char *) &l.l2) - &l.lc;
      break;

    case SQLSMFLOAT:
    case CFLOATTYPE:
      align = ((char *) &f.f2) - &f.fc;
      break;

    case SQLFLOAT:
    case CDOUBLETYPE:
      align = ((char *) &d.d2) - &d.dc;
      break;

    case SQLDTIME:
    case CDTIMETYPE:
      align = ((char *) &dt.dt2) - &dt.dtc;
      break;

    case SQLINTERVAL:
    case CINVTYPE:
      align = ((char *) &in.in2) - &in.inc;
      break;

    case SQLMONEY:
    case SQLDECIMAL:
    case CDECIMALTYPE:
    case CMONEYTYPE:
      align = ((char *) &n.n2) - &n.nc;
      break;

    case CLOCATORTYPE:
    case SQLBYTES:
    case SQLTEXT:
    case CFILETYPE:
      align = ((char *) &bl.bl2) - &bl.blc;
      break;

#ifdef SQLLVARCHAR
    case SQLLVARCHAR:
    case SQLSET:
    case SQLMULTISET:
    case SQLLIST:
    case SQLROW:
    case CLVCHARPTRTYPE:
      align = ((char *) &lv.lv2) - &lv.lvc;
      break;
#endif /* SQLLVARCHAR */

    case CCHARTYPE:
    case CFIXCHARTYPE:
    case CSTRINGTYPE:
    case SQLCHAR:
    case CVCHARTYPE:
    case SQLVCHAR:
#ifdef SQLNCHAR
    case SQLNCHAR:
#endif /* SQLNCHAR */
#ifdef SQLNVCHAR
    case SQLNVCHAR:
#endif /* SQLNVCHAR */
      align = 1;
      break;

    default:
      A4GL_assertion (1,
		      "jtypalign: unknown type number %d (assume 'double' alignment)\n",
		      type);
      align = ((char *) &d.d2) - &d.dc;
      break;
    }

  --align;
  return ((offset + align) & ~align);
}

static int
jtypcsize (int sqltyp, int sqllen)
{
  int rlen;

  switch (sqltyp)
    {
    case SQLCHAR:
#ifdef SQLNCHAR
    case SQLNCHAR:
#endif /* SQLNCHAR */
      rlen = sqllen + 1;
      break;

    case SQLVCHAR:
#ifdef SQLNVCHAR
    case SQLNVCHAR:
#endif /* SQLNCHAR */
      rlen = VCMAX (sqllen) + 1;
      /* SELECT '' ... returns VARCHAR(0) (even in SE) */
      /* Need at least 2 bytes allocated to avoid error -1235 */
      if (rlen == 1)
	rlen = 2;
      break;

    default:
      rlen = sqllen;
      break;
    }
  return (rlen);
}



/*
** Where necessary, convert an SQL* type to a C*TYPE type.
*/
static int
jtypctype (int stype)
{
  int rtype;

  switch (stype)
    {
    case SQLCHAR:
#ifdef SQLNCHAR
    case SQLNCHAR:
#endif /* SQLNCHAR */
      rtype = CCHARTYPE;
      //ESQLC_VERSION_CHECKER();
      break;

    case SQLVCHAR:
#ifdef SQLNVCHAR
    case SQLNVCHAR:
#endif /* SQLNCHAR */
      rtype = CVCHARTYPE;
      break;

#ifdef ESQLC_IUSTYPES
    case SQLSET:
    case SQLMULTISET:
    case SQLLIST:
    case SQLLVARCHAR:
      rtype = CLVCHARPTRTYPE;
      break;
#endif /* ESQLC_IUSTYPES */

    default:
      rtype = stype;
      break;
    }
  return (rtype);
}


const char *
sql_dbtemp (void)
{
  static char *db_temp = 0;

  if (db_temp == (char *) 0)
    {
      if (((db_temp = getenv ("DBTEMP")) == (char *) 0) &&
	  ((db_temp = getenv ("TMPDIR")) == (char *) 0))
	db_temp = DEFAULT_TMPDIR;
    }
  return (db_temp);
}


/*
** scanrecord() - read data line from file according to sqlda structure
**
** fp       - file to read
** idesc    - controlling format
** rec      - in/out: record location (rownum, line_1, line_2)
** name     - input file name
** line     - where line should be returned
**
** Returns:
** 0   - data read
**     - sqlca.sqlcode == 0 => all OK
**     - sqlca.sqlcode != 0 => some data format error
** EOF - no data to read
**
** NB: It would be nice to avoid copying the data from line into field.
** However, any field can contain escape characters, especially if the escape
** is weird (such as a digit).  So, in general, we have to copy the data.
** Adding code to determine whether we might be able to avoid copying the data
** (such as by looking at the values in rec to see whether the record spreads
** over several lines) might help.  If might be faster to use strchr() to
** identify whether any escape characters occur, and use non-copying processing
** if they don't, but you'd have to do some benchmarking to prove your point.
** Note that version 2.6 went a long way down the non-copying road, but ran
** foul of the escape characters, and hence version 2.7 reverted to the same
** processing as in version 2.5 and earlier.
*/
int
scanrecord (FILE * fp, Sqlda * idesc, RecLoc * rec, const char *name,
	    Memory * line)
{
  int i;
  int c;
  Uchar delim;
  Uchar escape;
  Uchar quote;
  Memory field;
  BSSP bssp;

  char *str_escape;

  str_escape = acl_getenv_not_set_as_0 ("DBESCAPE");
  if (str_escape == 0)
    {
      escape = '\\';
    }
  else
    {
      escape = str_escape[0];
    }

  /* Attempt to read a record into line */
  if (readrecord (fp, name, rec, line, escape) == EOF)
    {
      return (EOF);
    }

  delim = get_delim ();
  if (use_format == OP_QUOTE)
    quote = getquote ();
  else
    quote = escape;

  mem_new (&field);
  sqlca.sqlcode = 0;

  mem_scan (line);		/* Set structure for scanning */
  for (i = 0; i < idesc->sqld; i++)
    {
      Sqlva *col = &idesc->sqlvar[i];
      FieldScanner scanner;

      mem_rst (&field);
      if (BYTEBLOB (col->sqltype))
	scanner = scanbytefield;
      else if (use_format == OP_QUOTE)
	scanner = scancsvfield;
      else
	scanner = scantextfield;
      c = (*scanner) (col, line, &field, i, escape, delim, quote, &bssp);

      //printf("%c %d\n",c,sqlca.sqlcode);

      if (sqlca.sqlcode != 0)
	{
	  load_err (rec->rownum, 0);
	  return 0;
	  break;
	}

      else
	{
	  if (c == delim || ((c == '\n' || c == EOF) && i == idesc->sqld - 1))
	    {
	      if (convertdata (&field, col, bssp) != 0)
		{
		  if (rec->rownum == rec->line_2)
		    {
		      load_err (rec->rownum, "Error in line");
		    }
		  else
		    {
		      load_err (rec->rownum, "Error in line");
		    }
		}
	    }

	  else
	    {
	      /* Number of values in file != number of columns */

	      //printf ("X1\n");
	      load_err (rec->rownum,
			"Number of values is not the same as the number of columns (1)");
	      sqlca.sqlcode = -846;
	      return 0;
	    }
	}
    }

  if ((c = mem_char (line)) != EOF && c != '\n')
    {
      //printf ("X2 c=%x\n", c);
      load_err (rec->rownum,
		"Number of values is not the same as the number of columns (2)");
      sqlca.sqlcode = -846;	/* No. values in file != columns */
      return 0;
    }
  mem_del (&field);
  return (0);
}


static int
scanbytefield (Sqlva * col, Memory * line, Memory * field, int fnum,
	       Uchar escape, Uchar delim, Uchar quote, BSSP * bssp)
{
  int parity = 0;
  int c;

  A4GL_assertion (!BYTEBLOB (col->sqltype), "Not a blob column");

  /* BYTE blobs do not support the backslash-space convention */
  *bssp = BSSP_MISSING;

  while ((c = mem_char (line)) != EOF)
    {
      if (c == delim)
	{
	  /* Field delimiter */
	  break;
	}
      else if (c == escape)
	{
	  /* Escape character -- use next character */
	  if ((c = mem_char (line)) == EOF)
	    break;
	}
      else if (c == quote)
	{
	  /* Un-escaped quote -- ignore */
	  A4GL_assertion (use_format != OP_QUOTE, "Unescaped quote ?");
	  continue;
	}
      else if (c == '\n')
	{
	  /* Final field delimiter is optional */
	  break;
	}
      if ((++parity & 0x1) == 0)
	{
	  int c0 = mem_pop (field);
	  if (!isxdigit (c0) || !isxdigit (c))
	    {
	      load_err (0, "bad hex value");
	      sqlca.sqlcode = -32405;	/* Incorrectly formed hexadecimal value */
	      break;
	    }
	  mem_add (field, from_hex (c0, c));
	}
      else
	mem_add (field, (Uchar) c);
    }

  if ((parity & 0x01) != 0)
    {
      load_err (0, "bad hex value");
      sqlca.sqlcode = -32405;	/* Incorrectly formed hexadecimal value */
    }

  return c;
}

static int
scancsvfield (Sqlva * col, Memory * line, Memory * field, int fnum,
	      Uchar escape, Uchar delim, Uchar quote, BSSP * bssp)
{
  int c;

  A4GL_assertion (BYTEBLOB (col->sqltype), "Its a blob");

  *bssp = BSSP_UNKNOWN;
  if ((c = mem_peek (line)) != EOF)
    {
      if (c == quote)
	{
	  *bssp = BSSP_MISSING;
	  c = mem_char (line);
	  c = scanquote (line, field, delim, quote);
	}
      else
	c = scanfield (line, field, escape, delim, bssp);
    }

  if (*bssp == BSSP_UNKNOWN || mem_len (field) > 1)
    *bssp = BSSP_MISSING;

  if (TEXTBLOB (col->sqltype))
    mem_end (field, '\0');
  else
    mem_add (field, '\0');

  return c;
}



/*
** Scan a field for text (non-BYTE) data.
*/
static int
scantextfield (Sqlva * col, Memory * line, Memory * field, int fnum,
	       Uchar escape, Uchar delim, Uchar quote, BSSP * bssp)
{
  int c;

  A4GL_assertion (BYTEBLOB (col->sqltype), "Its a blob");

  *bssp = BSSP_UNKNOWN;
  c = scanfield (line, field, escape, delim, bssp);

  if (*bssp == BSSP_UNKNOWN || mem_len (field) > 1)
    *bssp = BSSP_MISSING;

  if (TEXTBLOB (col->sqltype))
    mem_end (field, '\0');
  else
    mem_add (field, '\0');

  return c;
}

/*
** Scan a regular field delimited by delim.
** Special characters (newline, escape, delim) escaped by escape.
*/
static int
scanfield (Memory * line, Memory * field, Uchar escape, Uchar delim,
	   BSSP * bssp)
{
  int c;

  while ((c = mem_char (line)) != EOF && c != delim)
    {
      if (c == escape)
	{
	  /* Escape character -- use next character */
	  if ((c = mem_char (line)) == EOF)
	    break;
	  if (*bssp == BSSP_UNKNOWN && c == ' ')
	    *bssp = BSSP_PRESENT;
	}
      else if (c == '\n')	/* Bug: should be EOR? */
	{
	  /* Final field delimiter is optional */
	  break;
	}
      mem_add (field, (Uchar) c);
    }
  return (c);
}







#define BYTEBLOB(x)		((x) == CLOCATORTYPE || (x) == SQLBYTES)
#define MIN(a, b)		(((a) < (b)) ? (a) : (b))


/*
**	Count the number of columns in the column list of an INSERT statement.
**	Do it by finding the open parenthesis, then counting the number of
**	commas and add one, and find the closing parenthesis.  An error has
**	occurred if the first non-blank character is not an open parenthesis, or
**	if a non-blank character occurs after the close parenthesis, or if a
**	non-alphanumeric, non-space, non-comma character occurs within the
**	parentheses.  Ignore DELIMIDENT issues.
*/
static int
cols_in_list (char *s)
{
  int c;
  int n = 0;
  int t = 0;

  s = skipblanks (s);
  while ((c = *s++) != '\0')
    {
      if (c == '(')
	{
	  if (t != 0)
	    return (-1);
	  t = 1;
	}
      else if (c == ')')
	{
	  if (t != 1)
	    return (-1);
	  t = 2;
	}
      else if (c == ',')
	{
	  if (t != 1)
	    return (-1);
	  n++;
	}
      else if (t != 1)
	{
	  if (!isspace (c))
	    return (-1);
	}
      else if (!isalnum (c) && c != '_' && !isspace (c))
	return (-1);
      /* ELSE it's OK */
    }

  if (t == 2)
    n++;
  return (n);
}


/*
**	Convert a SQ_LDINSERT statement (an INSERT statement which may
**	or may not have a VALUES clause) into an SQ_INSERT statement with
**	an appropriate VALUES clause.  Error handling in mk_insert is a
**	bit crude.
**	NB: the statement has a semi-colon at the end, which is stripped off.
*/
static char *
mk_insert (char *old_stmt)
{
  const char *src;
  char *s;
  char c;
  char *pad;
  char *new_stmt;
  char *tab;
  int i;
  int ncols;

  i = strlen (old_stmt);
  if (old_stmt[i - 1] == ';')
    old_stmt[i - 1] = '\0';
  src = old_stmt;
  s = iustoken (src, &src);	/* Confused by hints! */
  if (tokencmp (s, src - s, "insert", sizeof ("insert") - 1) != 0)
    {
      load_err (0, "Syntax error");
      return (NIL (char *));
    }
  s = iustoken (src, &src);	/* Confused by hints! */
  if (tokencmp (s, src - s, "into", sizeof ("into") - 1) != 0)
    {
      load_err (0, "Syntax error");
      return (NIL (char *));
    }
  tab = iustoken (src, &src);	/* Start of table name */
  /* Confused, still, by comments embedded in table name */
  s = skiptabname (tab);	/* After table name */

  if ((ncols = cols_in_list (s)) == 0)
    {
      c = *s;
      *s = '\0';
      ncols = cols_in_table (tab);
      *s = c;
    }
  if (ncols <= 0)
    {
      if (ncols < 0)
	{
	  load_err (0, "Syntax error");
	}
      return (NIL (char *));
    }

  /* Watch the constant string -- the spaces are ALL needed */
  new_stmt = (char *) malloc (sizeof ("insert into values () ") + strlen (tab) + 2 * ncols);	/*=C++=*/

  s = (char*)sprintf (new_stmt, "insert into %s values(", tab);
  pad = "";
  for (i = 0; i < ncols; i++)
    {
      if (i)
	strcat (new_stmt, ",?");
      else
	strcat (new_stmt, "?");
    }
  strcat (new_stmt, ")");

  return (new_stmt);
}

/*
** Count the number of blobs in the data to be loaded.
*/
int
count_blobs (Sqlda * u)
{
  Sqlva *c;
  Sqlva *e;
  int count = 0;

  for (c = u->sqlvar, e = c + u->sqld; c < e; c++)
    {
      if (c->sqltype == SQLBYTES ||
	  c->sqltype == SQLTEXT || c->sqltype == CLOCATORTYPE)
	count++;
    }
  return (count);
}

/*
**	Release the memory associated with the blobs.
*/
void free_blobs (Sqlda * u)
{
  Sqlva *c;
  Sqlva *e;
  Blob *blob;

  for (c = u->sqlvar, e = c + u->sqld; c < e; c++)
    {
      if (c->sqltype == SQLBYTES ||
	  c->sqltype == SQLTEXT || c->sqltype == CLOCATORTYPE)
	{
	  blob = (Blob *) c->sqldata;
	  if (blob->loc_buffer != NIL (char *))
	    {
	      //jb_unregister(blob->loc_buffer);
	      free (blob->loc_buffer);
	      blob->loc_buffer = NIL (char *);
	    }
	  blob->loc_bufsize = -1;
	}
    }
}


void
mem_new (Memory * m)
{
  m->mem_size = MEM_BLOCK_SIZE1;
  m->mem_base = (Uchar *) malloc (m->mem_size);
  m->mem_next = m->mem_base;
  m->mem_read = m->mem_base;
  //jb_register(m->mem_base);
  m->mem_endp = m->mem_base + m->mem_size;
}


/* Free all resources */
void
mem_del (Memory * m)
{
  if (m->mem_base != NIL (Uchar *))
    {
      //jb_unregister(m->mem_base);
      free (m->mem_base);
    }
  mem_zap (m);
}

void
mem_zap (Memory * m)
{
  m->mem_base = m->mem_endp = m->mem_next = m->mem_read = NIL (Uchar *);
  m->mem_size = 0;
}

#define LCURLY '{'
#define RCURLY '}'
#define STAR   '*'
#define SLASH  '/'
#define PLUS   '+'
#define DASH   '-'


enum
{
  JLSS_CSTYLE_COMMENT = 0x01,
  JLSS_ISOSQL_COMMENT = 0x02,
  JLSS_INFORMIX_COMMENT = 0x04,
  JLSS_ALLSQL_COMMENTS =
    (JLSS_CSTYLE_COMMENT | JLSS_ISOSQL_COMMENT | JLSS_INFORMIX_COMMENT)
};

int
tokencmp (const char *str, size_t len, const char *token, size_t toklen)
{
  char cs;
  char ct;
  size_t ncmp = len;

  if (toklen < len)
    ncmp = toklen;

  A4GL_assertion (ncmp <= 0, "ncmp not positive");
  while (ncmp > 0)
    {
      cs = tolower ((Uchar) * str++);
      ct = tolower ((Uchar) * token++);
      if (cs != ct)
	return (cs - ct);
      ncmp--;
    }

  A4GL_assertion (ncmp != 0, "ncmp not zero");

  if (len == toklen)
    {
      return 0;
    }
  else
    {
      /* One string is a prefix of the other */
      /* Conceptually, append NUL to end of shorter string */
      if (toklen < len)
	return (1);
      else
	return (-1);
    }
}

int
sql_error (char *s1, char *s2)
{
  ec_check_and_report_error ();
}

/* Skip over table name of form [database[@server]:]["owner".]tablename */
char * skiptabname (char *s)
{
  register unsigned char c;

  while ((c = *s++) != '\0')
    {
      if (!isalnum (c) && c != '_' && c != '@' && c != ':' && c != '.' &&
	  c != '"' && c != '\'')
	break;
    }
  return (s - 1);
}


/* Skip over blanks */
char * skipblanks (char *s)
{
  while (isspace ((unsigned char) *s))
    s++;
  return (s);
}


static size_t
sql_descsize (Sqlda * desc)
{
  Sqlva *col;
  size_t offset;
  int i;
  size_t size;

  offset = 0;
  for (col = desc->sqlvar, i = 0; i < desc->sqld; col++, i++)
    {
/*fprintf(stderr, "B%d: type = %d, len = %d\n", i, col->sqltype, col->sqllen);*/
      size = jtypmsize (col->sqltype, col->sqllen);
      offset = jtypalign (offset, col->sqltype);
      col->sqldata = (char *) offset;
      col->sqllen = jtypcsize (col->sqltype, col->sqllen);
      col->sqltype = jtypctype (col->sqltype);
      offset += size;
/*fprintf(stderr, "A%d: type = %d, len = %d, size = %d\n", i, col->sqltype, col->sqllen, size);*/
    }
  /* Make overall size compatible with a C short so that an  */
  /* array of indicator variables can be allocated after it. */
  offset = jtypalign (offset, SQLSMINT);
  return (offset);
}



void *
sql_describe (Sqlda * desc)
{
  Sqlva *col;
  void *space;
  char *buffer;
  short *indarray;
  size_t size;
  size_t offset;
  size_t i;
  size_t n;

  /* Step 1 -- calculate memory required */
  size = sql_descsize (desc);

  /* Step 2 -- allocate memory */
  space = malloc (size + desc->sqld * sizeof (ixInt2));
  if (space != 0)
    {
      buffer = (char *) space;		/*=C++=*/
      indarray = (short *) (buffer + size);

      /* Step 3 -- fix up pointers and indicators and initialize */
      offset = (long) buffer;
      col = desc->sqlvar;
      n = desc->sqld;
      for (i = 0; i < n; i++, col++)
	{
	  col->sqldata += offset;
	  if (col->sqltype == CLOCATORTYPE ||
	      col->sqltype == SQLTEXT || col->sqltype == SQLBYTES)
	    blob_locate ((Blob *) col->sqldata, BLOB_DEFAULT);
#ifdef ESQLC_IUSTYPES
	  else if (col->sqltype == CLVCHARPTRTYPE)
	    {
	      void *data = 0;
	      ifx_var_flag (&data, 1);
	      col->sqldata = (char *) data;			/*=C++=*/
	    }
#endif /* ESQLC_IUSTYPES */
	  col->sqlind = indarray++;
	  *col->sqlind = 0;
	}
    }

  return (space);
}


/*
** Initialise a Blob data structure ready for use.
** Returns: 0 => OK, non-zero => fail
*/
int
blob_locate (Blob * blob, BlobLocn locn)
{
  int rc;

  *blob = zero_blob;
  blob->loc_status = 0;
  blob->loc_type = SQLTEXT;
  blob->loc_xfercount = 0;
  if (locn == BLOB_DEFAULT)
    locn = blob_getlocmode ();
  switch (locn)
    {
    case BLOB_IN_NAMEFILE:
      rc = blob_locinnamefile (blob);
      break;
    case BLOB_IN_ANONFILE:
      rc = blob_locinanonfile (blob);
      break;
    case BLOB_IN_MEMORY:
      rc = blob_locinmem (blob);
      break;
    case BLOB_DEFAULT:
    default:
      A4GL_assertion (1, "Unknown blob type");
      rc = -1;
      break;
    }
  return (rc);
}

static int
blob_locinnamefile (Blob * blob)
{
  blob->loc_fname = blob_newfilename ();
  if (blob->loc_fname == (char *) 0)
    return (-1);
  blob->loc_loctype = LOCFNAME;
  blob->loc_mode = 0666;
  blob->loc_oflags = LOC_WONLY | LOC_RONLY;
  blob->loc_size = -1;
  blob->loc_indicator = 0;
  blob->loc_fd = -1;
#ifdef DEBUG
  dump_blob (stderr, "blob_locinnamefile()", blob);
#endif /* DEBUG */
  return (0);
}
static int
blob_locinanonfile (Blob * blob)
{
  char tmp[FILENAMESIZE];

  /* Open a file and then delete it, but keep it open. */
  /* The system cleans it up regardless of how we exit */
  strcpy (tmp, sql_dbtemp ());
  strcat (tmp, "/blob.XXXXXX");
  blob->loc_loctype = LOCFILE;
  blob->loc_fname = (char *) 0;
  blob->loc_mode = 0666;
  blob->loc_oflags = LOC_WONLY | LOC_RONLY;
  blob->loc_size = -1;
  blob->loc_indicator = 0;
  mktemp (tmp);
  blob->loc_fd = open (tmp, 0666, O_RDWR);
  if (blob->loc_fd < 0)
    {
      return (-1);
    }
  unlink (tmp);
#ifdef DEBUG
  dump_blob (stderr, "blob_locinanonfile()", blob);
#endif /* DEBUG */
  return (0);
}
static int
blob_locinmem (Blob * blob)
{
  /* Use memory only */
  blob->loc_loctype = LOCMEMORY;
  blob->loc_size = 0;
  blob->loc_bufsize = -1;
  blob->loc_buffer = (char *) 0;
  blob->loc_indicator = 0;
  blob->loc_oflags = 0;
#ifdef DEBUG
  dump_blob (stderr, "blob_locinmem()", blob);
#endif /* DEBUG */
  return (0);
}

char * blob_newfilename (void)
{
  char tmp[FILENAMESIZE];
  char *rv;
  static int counter = 0;

  do
    {
      sprintf (tmp, "%s/blob.%05d.%06d", blob_getdirectory (),
	       (int) getpid (), ++counter);
    }
  while (access (tmp, F_OK) == 0);

  /* Cast result of malloc() to placate C++ compilers (eg MSVC) */
  rv = (char *) malloc (strlen (tmp) + 1);
  if (rv != (char *) 0)
    strcpy (rv, tmp);
  return (rv);
}

const char *
blob_getdirectory (void)
{
  const char *rv = blob_dir;
  if (rv == 0)
    rv = sql_dbtemp ();
  return rv;
}

BlobLocn blob_getlocmode (void)
{
  return (def_blob_locn);
}

static Uchar
from_hex (int c0, int c)
{
  return (Uchar) ((hexdigit ((Uchar) c0) << 4) | hexdigit ((Uchar) c));
}

/* hexdigit() - convert character to corresponding hexadecimal value */
static int
hexdigit (Uchar c)
{
  int n;

  A4GL_assertion (!isxdigit (c), "Not hex");
  if (isdigit (c))
    n = c - '0';
  else if (c >= 'a' && c <= 'f')
    n = c - 'a' + 10;
  else if (c >= 'A' && c <= 'F')
    n = c - 'A' + 10;
  else
    A4GL_assertion (1, "Invalid hex digit");
  return (n);
}



/*
 * ** Scan a CSV quote-enclosed field after opening quote read.
 * ** An embedded quote quote sequence means a single quote.
 * */
static int
scanquote (Memory * line, Memory * field, Uchar delim, Uchar quote)
{
  int c;
  int eor = '\n';

  while ((c = mem_char (line)) != EOF)
    {
      if (c == quote)
	{
	  /* Check for doubled quote, etc. */
	  if ((c = mem_peek (line)) == quote)
	    {
	      c = mem_char (line);
	      mem_add (field, (Uchar) c);
	    }
	  else
	    {
	      /* Found a 'closing quote'; ignore it and scan to field delimiter */
	      /* NB: also completes record at EOR (newline).  Kludgy... */
	      while ((c = mem_char (line)) != EOF && c != delim && c != eor)
		{
		  mem_add (field, (Uchar) c);
		}
	      break;
	    }
	}
      else
	mem_add (field, (Uchar) c);
    }
  return c;
}



/*
** readrecord - read single record into memory.
** See unload.format document for description of record layout.
** On entry, the RecLoc structure contains the description of the
** last record read -- the row number and the range of lines it occupied.
** If this is the first record, then all the RecLoc elements are zero.
** If we read any data, then the row number is increased and the range of
** lines is initially set to one more than the last line of the last record.
** As more lines of data are added, the last line number is incremented.
** Note, however, that getline() can return successfully either because it
** read a whole line, or because it ran out of space to store the data.
*/
static int
readrecord (FILE * fp, const char *name, RecLoc * rec, Memory * m,
	    char escape)
{
  Uchar buffer[READRECBUFSIZE];
  size_t line_1 = rec->line_2 + 1;
  int nbytes;

  mem_rst (m);
  while ((nbytes = getaline (fp, (char *) buffer, sizeof (buffer))) != EOF)
    {
      mem_addstr (m, buffer, nbytes);
      if (mem_last (m) == '\n')
	{
	  const Uchar *m_end;
	  const Uchar *m_src;
	  size_t len = mem_len (m);
	  size_t e_cnt = 0;	/* escape count - number of trailing backslashes */
	  rec->line_2++;
	  A4GL_assertion (len == 0, "No length");
	  if (len == 1)
	    {
	      A4GL_assertion (buffer[0] != '\n', "Invalid empty line");
	      break;		/* Empty line (newline only); EOR */
	    }
	  m_src = mem_data (m);
	  m_end = m_src + len - 2;
	  A4GL_assertion (m_end[1] != '\n', "Invalid empty line");
	  if (m_end[0] == escape)
	    {
	      /*
	       ** NB: non-escape, escape, newline marks continuation,
	       ** but non-escape, escape, escape, newline marks EOL,
	       ** and non-escape, escape, escape, escape, newline marks continuation,
	       ** and so on...worry about it!
	       */
	      e_cnt = 1;
	      while (m_end > m_src && *--m_end == escape)
		e_cnt++;
	    }
	  if (e_cnt % 2 == 0)
	    break;
	}
    }
  if (feof (fp) && mem_len (m) == 0)
    return (EOF);		/* No data read */
  rec->rownum++;
  rec->line_1 = line_1;
  if (feof (fp) && mem_last (m) != '\n')
    {
      /* EOF with data but without trailing newline, perhaps */
      /* because second last character is escape (backslash) */
      mem_add (m, '\n');
      rec->line_2++;
      load_err (0, "EOF without terminating newline");
      sqlca.sqlcode = -746;
      return 0;
    }
  mem_end (m, '\0');
  A4GL_assertion (rec->line_1 > rec->line_2, "Confused (1)");
  A4GL_assertion (rec->rownum > rec->line_1, "Confused (2)");
  A4GL_assertion (rec->rownum == 0, "Confused (3)");
  A4GL_assertion (rec->line_1 == 0, "Confused (4)");
  A4GL_assertion (rec->line_2 == 0, "Confused (5)");
  return (0);			/* Data was read so not EOF yet */
}



/*
**      Convert the data in a memory block into the correct type.
*/
static int
convertdata (Memory * mem, Sqlva * col, BSSP bssp)
{
  enum
  { null = -1, notnull = 0 };
  size_t len;
  ixInt4 lval = 0;
  double dval = 0.0;
  int retval;
  ixInt2 type = 0;
  static char *datefmt=0;
  char *function = "<undefined>";
  Uchar *end;
  ixInt4 *date;
  Decimal *dcp;
  Datetime *dtp;
  Interval *inp;
  Blob *blob;

  retval = sqlca.sqlcode = 0;
  len = mem_len (mem);
  if (len == 0)
    {
      *col->sqlind = null;
    }
  else if (len == 1 && *mem_data (mem) == '\0' && !BYTEBLOB (col->sqltype))
    {
      *col->sqlind = null;
    }
  else
    {
      *col->sqlind = notnull;
      switch (type = col->sqltype)
	{
	case CCHARTYPE:
	case CSTRINGTYPE:
	case CFIXCHARTYPE:
	case SQLCHAR:
#ifdef SQLNCHAR
	case SQLNCHAR:
#endif /* SQLNCHAR */
	  /* Should we warn if string is truncated?? */
	  len = MIN (mem_len (mem), (size_t) col->sqllen);
	  strncpy (col->sqldata, (const char *) mem_data (mem), len);			/*=C++=*/
	  break;
	case CVCHARTYPE:
	case SQLVCHAR:
#ifdef SQLNVCHAR
	case SQLNVCHAR:
#endif /* SQLNVCHAR */
	  /* Should we warn if string is truncated?? */
	  if (bssp == BSSP_PRESENT)
	    len = 0;
	  else
	    len = MIN (mem_len (mem), (size_t) col->sqllen);
	  strncpy (col->sqldata, (const char *) mem_data (mem), len);			/*=C++=*/
	  col->sqldata[len] = '\0';
	  break;

#ifdef ESQLC_IUSTYPES
	case CLVCHARPTRTYPE:
	case SQLLVARCHAR:
	  {
	    /* NB: ifx_var_setdata() sets sqlca.sqlcode on error! */
	    /* Workaround for B169213 - ifx_var_setdata() won't accept zero length data */
	    void *data = col->sqldata;
	    char *memd = (char *) mem_data (mem);		/*=C++=*/
	    len = MIN (mem_len (mem), (size_t) col->sqllen);
	    /* Don't include the trailing ASCII NUL in the LVARCHAR value. */
	    if (len > 0 && memd[len - 1] == '\0')
	      len--;
	    if (ifx_var_setdata (&data, memd, len) == 0
		&& bssp == BSSP_PRESENT)
	      ifx_var_setlen (&data, 0);
	    /* Ensure safety if col->sqldata was initially unallocated */
	    col->sqldata = (char *) data;		/*=C++=*/
	  }
	  break;

	case CBOOLTYPE:
	case SQLBOOL:
	  {
	    char data = *mem_data (mem);
	    if (mem_len (mem) > 2)
	      error_746 ("string is too long to convert to BOOLEAN");
	    else
	      {
		switch (data)
		  {
		  case 't':
		  case 'T':
		    *col->sqldata = 1;
		    break;
		  case 'f':
		  case 'F':
		    *col->sqldata = 0;
		    break;
		  default:
		    error_746 ("string value cannot be converted to BOOLEAN");
		    break;
		  }
	      }
	  }
	  break;
#endif /* ESQLC_IUSTYPES */

	case CSHORTTYPE:
	case SQLSMINT:
	  lval = ustrtol (mem_data (mem), &end, IBASE);
	  function = "ustrtol";
	  type = SQLSMINT;
	  if (end == mem_data (mem) || *end != '\0')
	    {
	      /* Character to numeric conversion error */
	      sqlca.sqlcode = -1213;
	    }
	  else if (lval < -32767 || lval > 32767)
	    {
	      /* Value too large to fit in a SMALLINT */
	      sqlca.sqlcode = -1214;
	    }
	  else
	    *((ixInt2 *) col->sqldata) = (ixInt2) lval;
	  break;
	case CINTTYPE:
	case CLONGTYPE:
	case SQLINT:
	case SQLSERIAL:
	  lval = ustrtol (mem_data (mem), &end, IBASE);
	  if (end == mem_data (mem) || *end != '\0')
	    {
	      /* Character to numeric conversion error */
	      sqlca.sqlcode = -1213;
	      function = "ustrtol";
	      type = SQLINT;
	    }
	  else
	    *((ixInt4 *) col->sqldata) = lval;
	  break;

	case CFLOATTYPE:
	case SQLSMFLOAT:
	  dval = ustrtod (mem_data (mem), &end);
	  if (end == mem_data (mem) || *end != '\0')
	    {
	      /* Character to numeric conversion error */
	      sqlca.sqlcode = -1213;
	      function = "strtod";
	      type = SQLSMFLOAT;
	    }
	  else
	    *(float *) col->sqldata = (float) dval;
	  break;

	case CDOUBLETYPE:
	case SQLFLOAT:
	  dval = ustrtod (mem_data (mem), &end);
	  if (end == mem_data (mem) || *end != '\0')
	    {
	      /* Character to numeric conversion error */
	      sqlca.sqlcode = -1213;
	      function = "strtod";
	      type = SQLFLOAT;
	    }
	  else
	    *(double *) col->sqldata = dval;
	  break;

	case CMONEYTYPE:
	case SQLMONEY:
	case CDECIMALTYPE:
	case SQLDECIMAL:
	  /* Is the scale & precision set correctly? */
	  dcp = (Decimal *) col->sqldata;
	  sqlca.sqlcode = deccvasc (mem_cdata (mem), len, dcp);
	  if (sqlca.sqlcode != 0)
	    {
	      function = "deccvasc";
	      type = (type == CMONEYTYPE || type == SQLMONEY)
		? SQLMONEY : SQLDECIMAL;
	    }
	  break;

	case CDATETYPE:
	case SQLDATE:
	  date = (ixInt4 *) col->sqldata;
	  if (datefmt==0) {
		  	datefmt=(char *)cvt_dbdate(acl_getenv ("DBDATE"));
	  }
	  sqlca.sqlcode =
	    rdefmtdate (date, datefmt, mem_cdata (mem));
	  if (sqlca.sqlcode != 0)
	    {
	      function = "rdefmtdate";
	      type = SQLDATE;
	    }
	  break;

	case CDTIMETYPE:
	case SQLDTIME:
	  dtp = (Datetime *) col->sqldata;
	  dtp->dt_qual = (ixInt2) col->sqllen;
	  sqlca.sqlcode = dtcvasc (mem_cdata (mem), dtp);
	  if (sqlca.sqlcode != 0)
	    {
	      function = "dtcvasc";
	      type = SQLDTIME;
	    }
	  break;

	case CINVTYPE:
	case SQLINTERVAL:
	  inp = (Interval *) col->sqldata;
	  inp->in_qual = (ixInt2) col->sqllen;
	  sqlca.sqlcode = incvasc (mem_cdata (mem), inp);
	  if (sqlca.sqlcode != 0)
	    {
	      function = "incvasc";
	      type = SQLINTERVAL;
	    }
	  break;

	case CLOCATORTYPE:
	case SQLTEXT:
	case SQLBYTES:
	  blob = (Blob *) col->sqldata;
	  blob->loc_loctype = LOCMEMORY;
	  blob->loc_bufsize = mem_len (mem);
	  blob->loc_buffer = mem_cdata (mem);
	  blob->loc_size = len;
	  blob->loc_indicator = (len == 0) ? -1 : 0;
	  /* Invalidate memory block 'cos blob is using it! */
	  mem_zap (mem);
	  mem_rst (mem);
	  break;

#ifdef ESQLC_IUSTYPES
	case CINT8TYPE:
	case SQLINT8:
	case SQLSERIAL8:
	  sqlca.sqlcode =
	    ifx_int8cvasc (mem_cdata (mem), mem_len (mem) - 1,
			   (ifx_int8_t *) col->sqldata);
	  break;
#endif /* ESQLC_IUSTYPES */

	default:
	  A4GL_assertion (1, "Unknown type");
	  break;
	}
    }

  if (sqlca.sqlcode < 0)
    {
      load_err (0, "Bad column data - couldn't convert");
      retval = -1;
    }
  return (retval);
}

char * iustoken (const char *input, const char **end)
{
  const char *token;
  size_t len;

  token = sqltoken (input, end);
  len = *end - token;
  if (collection_name (token, len))
    {
		/**
                ** Token is SET, MULTISET or LIST.
                ** Now check whether next non-blank character not in a comment
                ** is open brace.  If so, the construct is the start of an IDS
                ** collection literal.
                ** NB: Does handle double-dash comments between collection name
                ** and open brace.  Note that brace comments are not allowed!
                ** NB: Do not want to look for { ... } with sqlcomment() since
                ** that will track the entire collection LIST{v1, v2, ..., vN},
                ** (unless it contains nested {} comments, of course).
                */
      const char *src = *end;
      const char *c_bgn;
      const char *c_end;
      int style = JLSS_CSTYLE_COMMENT | JLSS_ISOSQL_COMMENT;
      SQLComment cmt;
      while ((cmt = sqlcomment (src, style, &c_bgn, &c_end)) == SQL_COMMENT)
	{
	  src = c_end;
	}
      if (*c_bgn == LCURLY)
	*end = c_bgn + 1;
    }
  return CONST_CAST (char *, token);
}




/*
** sqlcomment() -- Isolate SQL Comments
**
** Skip over white space (per isspace()) in string, and identify a
** comment or hint, if there is one.  Three comment styles are
** recognized:
**  * C-style comments -- slash star to star slash.
**  * ISO double dash comments -- from dash dash to newline.
**  * Informix brace comments -- left curly brace to right curly brace.
** For each comment style, if the first character is a plus sign, the
** comment is an optimizer hint.
**
** Returns appropriate value from SQLComment enumeration.
** Sets *begin to point to the start of the comment.
** Sets *end to point to the first character after the comment.
** If there is no comment, then *begin and *end both point to the first
** non-comment, non-white space character.  If *begin != *end and *end
** points to ASCII NUL '\0', the comment is incomplete.
**
** This is primarily an internal function used by sqltoken() and
** iustoken(), but has to be exposed and may be of general use.
**
** Usage pattern:
**     const char *src;
**     const char *end;
**     const char *bgn;
**     int   style = JLSS_ALLSQL_COMMENTS;
**     SQLComment cmt;
**     ...initialize src...
**     while ((cmt = sqlcomment(src, style, &bgn, &end)) == SQL_COMMENT)
**         src = end;
**     ...after the loop, bgn points to either the end of the string, or
**     ...the start of the next non-comment token.  If comments are of
**     ...interest, they can be picked up in the body of the loop.
*/

SQLComment sqlcomment (const char *input, int style, const char **bgn, const char **end)
{
  const char *token = input;
  unsigned char c = *input;
#ifdef DEBUG
  const char s_hint[] = "+ hint";
  const char s_cmmt[] = " comment";
#endif

  while (isspace (c = *input))
    input++;
  *bgn = input;
  if (c != LCURLY && c != DASH && c != SLASH)
    {
      /* It isn't a comment - whatever else it is */
      *end = input;
      return (SQL_NOCOMMENT);
    }
  else if ((style & JLSS_INFORMIX_COMMENT) != 0 && c == LCURLY)
    {
      /* Optimizer hint (to first RCURLY); treat as symbol */
#ifdef DEBUG
      const char *comment_type = (input[1] == PLUS) ? s_hint : s_cmmt;
#endif /* DEBUG */
      if ((token = strchr (input + 1, RCURLY)) == 0)
	{
	  *end = input + strlen (input);
	  return SQL_INCOMPLETE;
	}
      *end = token + 1;
      return (input[1] == PLUS) ? SQL_OPTIMIZERHINT : SQL_COMMENT;
    }
  else if ((style & JLSS_ISOSQL_COMMENT) != 0 && c == DASH
	   && input[1] == DASH)
    {
      /* Optimizer hint (to end of line); treat as symbol */
#ifdef DEBUG
      const char *comment_type = (input[2] == PLUS) ? s_hint : s_cmmt;
#endif /* DEBUG */
      if ((token = strchr (input + 2, '\n')) == 0)
	{
	  *end = input + strlen (input);
	  return SQL_INCOMPLETE;
	}
      *end = token + 1;
      return (input[2] == PLUS) ? SQL_OPTIMIZERHINT : SQL_COMMENT;
    }
  else if ((style & JLSS_CSTYLE_COMMENT) != 0 && c == SLASH
	   && input[1] == STAR)
    {
      /* Optimizer hint to star-slash combo; treat as symbol */
      /* Mercifully, we don't have to deal with backslash-newline splicing */
#ifdef DEBUG
      const char *comment_type = (input[2] == PLUS) ? s_hint : s_cmmt;
#endif /* DEBUG */
      int plus = (input[2] == PLUS);
      input += 2;
      while ((token = strchr (input, STAR)) != 0)
	{
	  if (*(token + 1) != SLASH)
	    input = token + 1;
	  else
	    break;
	}
      if (token == 0)
	{
	  *end = input + strlen (input);
	  return SQL_INCOMPLETE;
	}
      else
	{
	  *end = token + 2;
	  return plus ? SQL_OPTIMIZERHINT : SQL_COMMENT;
	}
    }
  *end = input;
  /* Found, for example, the slash in SELECT a / b AS c ... */
  return SQL_NOCOMMENT;
}

/*
** sqltoken() - get SQL token
**
** Returns pointer to start of next SQL token (keyword, string,
** punctuation) in given string, or pointer to null at end of string if
** there is none.  The end of the token is in the end parameter.
**
** The current version recognizes three comment conventions:
** -- comment to end of line
** { comment enclosed in braces }
** C-style comments (slash-star to star-slash).
** When the first character after the open comment marker is a plus, it
** is recognized as an Informix-style optimizer hint and returned as a
** token: {+ hint } and --+ hint to end of line
** 2001-03-31: # to end of line is no longer regarded as a comment
** (because of SLVs).
** KLUDGE: Outer while loop should be unnecessary now...
** 2004-12-24: Permit hexadecimal constants (0xFFFFFFFF etc).
*/
char * sqltoken (const char *input, const char **end)
{
  const char *token;
  unsigned char c;
  unsigned char q;

  while (*input != '\0')
    {
      int style = JLSS_ALLSQL_COMMENTS;
      SQLComment cmt;
      const char *c_bgn;
      const char *c_end;

      while ((cmt = sqlcomment (input, style, &c_bgn, &c_end)) == SQL_COMMENT)
	input = c_end;

      input = c_bgn;
      if (cmt == SQL_OPTIMIZERHINT || cmt == SQL_INCOMPLETE)
	{
	  *end = c_end;
	  return CONST_CAST (char *, input);
	}
      if ((c = *input) == '\0')
	break;
      else if (c == '\'' || c == '"')
	{
	  /* Character string or delimited identifier */
	  const char *str = input + 1;
	  token = input;
	  q = c;
	  /* Ignores newlines in quoted strings! */
	  /* Handles adjacent doubled quotes */
	  while ((str = strchr (str, q)) != 0)
	    {
	      if (*(str + 1) != q)
		{
		  *end = str + 1;
		  return CONST_CAST (char *, token);
		}
	      str += 2;
	    }
	  break;
	}
      else if (isdigit (c)
	       || (c == '.' && isdigit ((unsigned char) input[1])))
	{
	  /* Intelligent number parsing */
	  /* Handles unsigned integers, fixed point, */
	  /* and exponental (1E+32) notation */
	  token = input;
	  if (c == '0' && (input[1] == 'x' || input[1] == 'X')
	      && isxdigit ((unsigned char) input[2]))
	    {
	      /* Hexadecimal integer */
	      input += 2;
	      while ((c = *input++) != '\0' && isxdigit (c))
		;
	    }
	  else
	    {
	      /* Octal or decimal integer, or floating point */
	      if (c == '.')
		input++;
	      while ((c = *input++) != '\0' && isdigit (c))
		;
	      if (c == '.')
		{
		  while ((c = *input++) != '\0' && isdigit (c))
		    ;
		}
	      if (c == 'e' || c == 'E')
		{
		  /* Maybe exponential notation -- in fact should be... */
		  if (isdigit ((unsigned char) *input) ||
		      ((*input == PLUS || *input == DASH)
		       && isdigit ((unsigned char) input[1])))
		    {
		      if ((c = *input++) == PLUS || c == DASH)
			input++;
		      while ((c = *input++) != '\0' && isdigit (c))
			;
		    }
		}
	    }
	  *end = input - 1;
	  return CONST_CAST (char *, token);
	}
      else if (isalpha (c) || c == '_')
	{
	  /* Word (identifier or keyword) */
	  token = input;
	  while ((c = *input++) != '\0' && (isalnum (c) || c == '_'))
	    ;
	  *end = input - 1;
	  return CONST_CAST (char *, token);
	}
      else
	{
	  /* Punctuation - symbols */
	  token = input++;
	  /* Only compound symbols known are: <> != <= >= || :: (used in IUS) */
	  /* Any other punctuation character is treated as a single token */
	  if (*input != '\0'
	      && (c == '<' || c == '!' || c == '|' || c == '>' || c == ':'))
	    {
	      switch (c)
		{
		case '<':
		  if (*input == '>' || *input == '=')
		    input++;
		  break;
		case '>':
		  if (*input == '=')
		    input++;
		  break;
		case '!':
		  if (*input == '=')
		    input++;
		  break;
		case '|':
		  if (*input == '|')
		    input++;
		  break;
		case ':':
		  if (*input == ':')
		    input++;
		  break;
		default:
		  A4GL_assertion (1, "Confused");
		  break;
		}
	    }
	  *end = input;
	  return CONST_CAST (char *, token);
	}
    }
  *end = input;
  return CONST_CAST (char *, input);
}



static int
collection_name (const char *token, size_t len)
{
  int rc = 0;
  if (isalpha ((unsigned char) *token) == 0)
    rc = 0;
  else if (len == sizeof ("SET") - 1
	   && tokencmp (token, len, "SET", len) == 0)
    rc = 1;
  else if (len == sizeof ("LIST") - 1
	   && tokencmp (token, len, "LIST", len) == 0)
    rc = 1;
  else if (len == sizeof ("MULTISET") - 1
	   && tokencmp (token, len, "MULTISET", len) == 0)
    rc = 1;
  return rc;
}





int
getaline (FILE * fp, char *buffer, size_t buflen)
{
  int c = 0;			/* Unnecessary, but keeps GCC quiet */
  size_t i;

  A4GL_assertion (buflen == 0, "No buffer");
  A4GL_assertion (buffer == 0, "No buffer");

  /* Read as much of line as possible */
  for (i = 0; --buflen > 0 && (c = getc (fp)) != EOF && c != '\n'; i++)
    buffer[i] = c;

#ifdef DISCARD_NEWLINE
#else
  /* Tack newline onto end */
  if (buflen > 0 && c == '\n')
    buffer[i++] = c;
#endif /* DISCARD_NEWLINE */

#ifdef DISCARD_RESIDUE
  /* Read and discard rest of line */
  if (buflen <= 0 && c != '\n')
    {
      while ((c = getc (fp)) != EOF && c != '\n')
	;
    }
#endif /* DISCARD_RESIDUE */

  /* Null terminate string */
  buffer[i] = '\0';

  /* Return length of string */
  return ((i == 0 && c == EOF) ? EOF : (int) i);
}



char           *cvt_dbdate(const char *dbdate)
{
        static char     retval[11];
        char           *p;
        const char     *d;
        unsigned char   c;
        int             state;
        int             i;
        int             n;

        if (strlen(dbdate) != 5)
                return(NIL(char *));
        p = retval;
        d = dbdate;
        state = 0;
        while ((c = *d++) != '\0')
        {
                switch (c)
                {
                case 'y':
                case 'Y':
                        if (state & DB_YEAR)
                                return(NIL(char *));
                        switch (*d++)
                        {
                        case '2':
                                n = 2;
                                break;
                        case '4':
                                n = 4;
                                break;
                        default:
                                return(NIL(char *));
                        }
                        for (i = 0; i < n; i++)
                                *p++ = 'y';
                        *p++ = ' ';
                        state |= DB_YEAR;
                        break;
                case 'm':
                case 'M':
                        if (state & DB_MONTH)
                                return(NIL(char *));
                        *p++ = 'm';
                        *p++ = 'm';
                        *p++ = ' ';
                        state |= DB_MONTH;
                        break;
                case 'd':
                case 'D':
                        if (state & DB_DAY)
                                return(NIL(char *));
                        *p++ = 'd';
                       *p++ = 'd';
                        *p++ = ' ';
                        state |= DB_DAY;
                        break;
                default:
                        if (state & DB_DELIM)
                                return(NIL(char *));
                        if (!ispunct(c) && c != '0')
                                return(NIL(char *));
                        state |= DB_DELIM;
                        if ((state & DB_DONE) != DB_DONE)
                                return(NIL(char *));
                        *--p = '\0';
                        if (c == '0')
                        {
                                /* No punctuation -- copy string without the blanks */
                                char *src;
                                char *dst;
                                for (src = dst = retval; *src != '\0'; src++)
                                {
                                        if (*src != ' ')
                                                *dst++ = *src;
                                }
                        }
                        else
                        {
                                /* Overwrite the blank punctuation markers */
                                for (p = retval; *p != '\0'; p++)
                                {
                                        if (*p == ' ')
                                                *p = c;
                                }
                        }
                        break;
                }
        }
        if ((state & DB_DONE) != DB_DONE)
                return(NIL(char *));
        return(retval);
}

void rec_zero(RecLoc *rec)
{
	        static RecLoc zero = { 0 };
		        *rec = zero;
}

