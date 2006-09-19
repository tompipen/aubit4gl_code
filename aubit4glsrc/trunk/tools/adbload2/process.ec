#include <stdio.h>
#include <stdlib.h>
#include <sqlda.h>
#include <sqlca.h>
#include <sqltypes.h>
#include <varchar.h>
#include <fcntl.h>

#include "a4gl_dbload_int.h"
extern int lv_testmode;
extern int lv_errs;
extern int lv_commit;
extern int lv_lockit;
extern int lv_skip;
extern int yylineno;

int load_ok = 0;
int currline = 0;


#define FREE(x) {free(x);x=0;}


int curr_tx_count = 0;
char *buffer_sqlda = 0;
char *currfname = "<none>";
static int cols_in_table (char *tabname);

char errbuff[2048] = "";
enum BlobLocn
{
  BLOB_DEFAULT, BLOB_IN_MEMORY, BLOB_IN_ANONFILE, BLOB_IN_NAMEFILE
};
static char *blob_dir = 0;
#define loc_mode        lc_union.lc_file.lc_mode
#define SQL_TABNAMELEN  (3 * SQL_NAMELEN + SQL_USERLEN + sizeof("@:''."))
#define SQL_COLNAMELEN  (SQL_NAMELEN + 1)

typedef enum BlobLocn BlobLocn;
struct RecLoc
{
  size_t rownum;		/* Record number */
  size_t line_1;		/* First line number */
  size_t line_2;		/* Last  line number */
};

typedef struct RecLoc RecLoc;
typedef unsigned char Uchar;

#ifndef DEFINED_BSSP
typedef enum BSSP
{ BSSP_PRESENT = 0x4321, BSSP_MISSING, BSSP_UNKNOWN } BSSP;
#define DEFINED_BSSP
#endif


struct Memory
{
  size_t mem_size;		/* Number of bytes allocated */
  Uchar *mem_base;		/* Start of buffer */
  Uchar *mem_endp;		/* Pointer one beyond last allocated byte */
  Uchar *mem_next;		/* Next location to write to */
  Uchar *mem_read;		/* Next location to read from */
};

typedef loc_t Blob;
typedef struct decimal Decimal;
typedef struct dtime Datetime;
typedef struct intrvl Interval;
#define FILENAMESIZE    128

static Blob zero_blob = { 0 };
typedef struct Memory Memory;
#define NIL(x)         ((x)0)
size_t mem_len (Memory * m);
void mem_add (Memory * m, Uchar c);
int mem_char (Memory * m);
int mem_pop (Memory * m);
void mem_new (Memory * m);
void mem_del (Memory * m);
void mem_zap (Memory * m);
void mem_rst (Memory * m);


void mem_addstr (Memory * m, const Uchar * s, size_t len);
char **ptrs_to_data = 0;
long *msz_to_data = 0;
short *isnulls = 0;
int nptrs_to_data = 0;
int *fld = 0;
int nfld = 0;


#define Sqlda struct sqlda
#define Sqlva struct sqlvar_struct

static BlobLocn def_blob_locn = BLOB_IN_MEMORY;
static size_t sql_descsize (Sqlda * desc);
void *sql_describe (Sqlda * desc);
Sqlda *idesc = 0;
static int convertdata (Memory * mem, Sqlva * col, BSSP bssp);
void
ensure_colexpr (struct s_dbloadline *dbload);


/********************************************************************************/
int
process_entry (struct s_dbloadline *dbload)
{
  FILE *f_in;
  long l;
  static char *buff;
  static long lbuff = 20000;
  static long nbuff = 0;
  int errcount = 0;

  if (lv_testmode)
    return 1;

  A4GL_debug ("process file : >%s< %d fields\n", dbload->f->fname,
	      dbload->f->nfields);

  currfname = dbload->f->fname;
  f_in = fopen (dbload->f->fname, "r");

  if (!f_in)
    {
      sprintf (errbuff, "Unable to open %s\n", dbload->f->fname);
      load_err (0, errbuff);
      return 0;
    }

  if (!prepare_it (dbload))
    {
      return 0;
    }


  buff = malloc (lbuff + 1);

  while (1)
    {
      l = ftell (f_in);
      if (!fgets (buff, lbuff, f_in))
	break;

      if (strlen (buff) >= lbuff - 1)
	{
	  // Our buffer is too small...
	  lbuff *= 2;
	  buff = realloc (buff, lbuff);
	  fseek (f_in, l, SEEK_SET);
	}
      else
	{
	  // Good line ? 
	  if (!process_line (buff, dbload))
	    {
	      errcount++;
	      if (errcount > lv_errs)
		{
		  // error count exceeded
		  printf ("Error count exceeded - load failed\n");
		  do_rollback_work();
		  fclose (f_in);
		  f_in = 0;
		  cleanup (dbload);
		  return 0;
		}
	    }
	}
    }
  cleanup (dbload);
  fclose (f_in);
  f_in = 0;
  return 1;
}



/********************************************************************************/
/*
        Convert our colexpr - replace the \t#\n with  '?' in our string 
      	and generate the field mappings (fld->?)  in our fld array.
*/
void
generate_field_mappings (struct s_dbloadline *dbload)
{
  int a;
  int columns = 0;


  if (fld)
    {
      A4GL_debug ("free fld");
      FREE (fld);
    }

  // So now - we should have our string regardless of whether the
  // user gave it.
  for (a = 0; a < strlen (dbload->i->colexpr); a++)
    {
      if (dbload->i->colexpr[a] == '\t')
	{
	  char buff[200];
	  int c = 0;
	  int b;
	  dbload->i->colexpr[a] = '?';
	  for (b = a + 1; b < strlen (dbload->i->colexpr); b++)
	    {
	      if (dbload->i->colexpr[b] == '\n')
		{
		  buff[c] = 0;
		  dbload->i->colexpr[b] = ' ';
		  fld = realloc (fld, sizeof (int) * (columns + 1));
		  fld[columns++] = atoi (buff);
		  break;
		}
	      buff[c++] = dbload->i->colexpr[b];
	      dbload->i->colexpr[b] = ' ';
	    }
	  a = b;
	}
    }
  nfld = columns;


  // Now - we should have '?' in our string instead of our field numbers
  // and we've now got a fld->? link in our fld array.

  /* Eg. 
     fld[0] -> 1
     fld[1] -> 4
     fld[2] -> 2

     would mean the first ? should be field 1
     the second ? should be the forth field
     and the final ? should be the second field
   */
}

/********************************************************************************/


// Allocate memory for the character position specific files...
char *
alloc_memory_for_field (struct s_dbloadline *dbload, int a, long *ptr_for_len)
{
  struct s_field_pos_list *s;
  struct s_field_pos *f;

// Quick sanity check...
  A4GL_assertion (dbload->f->delim,
		  "Shouldn't use this function for a delimited file");


  s = dbload->f->field_pos_list;
  A4GL_assertion (a > s->npos, "field too high");
  f = s->pos[a];

  if (ptr_for_len)
    {
      *ptr_for_len = f->pos_list->memsz + 1;
    }

  return malloc (f->pos_list->memsz + 1);
}

/********************************************************************************/
char *
clr_memory_for_field (struct s_dbloadline *dbload, char *ptr, int a)
{
  struct s_field_pos_list *s;
  struct s_field_pos *f;
// Quick sanity check...
  A4GL_assertion (dbload->f->delim,
		  "Shouldn't use this function for a delimited file");

  s = dbload->f->field_pos_list;

  A4GL_assertion (a > s->npos, "field too high");
  f = s->pos[a];

  memset (ptr, 0, f->pos_list->memsz + 1);

}

/********************************************************************************/

int
cp_memory_for_field (char *linein, struct s_dbloadline *dbload, char *ptr,
		     int a)
{
  struct s_field_pos_list *s;
  struct s_field_pos *f;
  int cnt = 0;
  int inlen;
  int x;

// Quick sanity check...
  A4GL_assertion (dbload->f->delim,
		  "Shouldn't use this function for a delimited file");

  inlen = strlen (linein);

  s = dbload->f->field_pos_list;
  A4GL_assertion (a > s->npos, "field too high");
  f = s->pos[a];

  A4GL_debug ("Processing %s\n", f->name);

  for (x = 0; x < f->pos_list->npos; x++)
    {
      struct s_pos_list *c;
      int end;
      int b;
      c = f->pos_list->list_of_character_positions[x];
      if (c->end == 0)
	{
	  end = c->start;
	}
      else
	{
	  end = c->end;
	}

      for (b = c->start; b <= end; b++)
	{
	  if (b >= inlen)
	    {			// Its over the end of the line
	      load_err (-1, "Line too short");
	      return 0;
	    }
	  ptr[cnt++] = linein[b - 1];
	}
    }

  A4GL_assertion (cnt > f->pos_list->memsz,
		  "Got confused - and probably overwrote some memory");
  ptr[cnt] = 0;
  A4GL_debug ("Got data as : %s\n", ptr);
  return 1;
}

/********************************************************************************/

int
lock_table (struct s_dbloadline *dbload)
{
  // Do we need to lock our table ? 
  A4GL_push_char( dbload->i->tabname);
  aclfgl_lock_table( 1);
  return A4GL_pop_int();
}


/********************************************************************************/

int
unlock_table (struct s_dbloadline *dbload)
{
  // Do we need to lock our table ? 

  A4GL_push_char( dbload->i->tabname);
  aclfgl_unlock_table( 1);
  return 0;
}



/********************************************************************************/
int
prepare_it (struct s_dbloadline *dbload)
{
  $char *ptr_insert;
  int a;
  int nblobs;
// Initialize some stuff...


  ensure_colexpr (dbload);
  generate_field_mappings (dbload);

  ptr_insert = malloc (strlen (dbload->i->colexpr) + 200);
  sprintf (ptr_insert, "INSERT INTO %s ", dbload->i->tabname);
  strcat (ptr_insert, dbload->i->colexpr);

  //
  // Now we've got our insert - create the cursor...
  //
  EXEC SQL PREPARE p_ins FROM $ptr_insert;

  if (sqlca.sqlcode < 0)
    {
      // Couldn't prepare it
      sprintf (errbuff, "Unable to process (prepare), Error %d\n   %s \n\n",
	       sqlca.sqlcode, ptr_insert);
      load_err (0, errbuff);
      return 0;
    }


  EXEC SQL DESCRIBE p_ins INTO idesc;

  if (sqlca.sqlcode < 0)
    {
      // Couldn't describe it
      sprintf (errbuff, "Unable to process (describe), Error %d\n   %s \n\n",
	       sqlca.sqlcode, ptr_insert);
      load_err (0, errbuff);
      return 0;
    }

  nblobs = count_blobs (idesc);

  if (nblobs)
    {
      A4GL_assertion (nblobs, "Can't load blobs yet");
      // Should have bombed out already - but just in case....
      return 0;
    }

  buffer_sqlda = (char *) sql_describe (idesc);

  A4GL_debug ("--->%s\n", ptr_insert);
  A4GL_debug ("2->%s\n", dbload->i->colexpr);

  if (ptrs_to_data)
    {
      A4GL_debug ("free ptrs_to_data");
      FREE (ptrs_to_data);
      A4GL_debug ("free msz_to_data");
      FREE (msz_to_data);
      ptrs_to_data = 0;
      msz_to_data = 0;
      nptrs_to_data = 0;
    }
  if (isnulls)
    {
      FREE (isnulls);
    }

  A4GL_debug ("alloc ptrs_to_data : %d",
	      sizeof (char *) * dbload->f->nfields);
  ptrs_to_data = malloc (sizeof (char *) * (dbload->f->nfields + 1));
  msz_to_data = malloc (sizeof (long) * (dbload->f->nfields + 1));
  isnulls = malloc (sizeof (short) * (dbload->f->nfields + 1));
  nptrs_to_data = dbload->f->nfields;

  for (a = 0; a < dbload->f->nfields; a++)
    {
      ptrs_to_data[a] = 0;
      isnulls[a] = 0;


      if (dbload->f->delim == 0)
	{
	  // if its a character specified file -
	  // we can create the memory to hold the data now
	  // as we know how big it needs to be...
	  ptrs_to_data[a] =
	    alloc_memory_for_field (dbload, a, &msz_to_data[a]);
	}

    }

  do_begin_work ();

  if (!lock_table (dbload))
    {
      return 0;
    }

  EXEC SQL DECLARE c_insert CURSOR WITH HOLD FOR p_ins;

  if (sqlca.sqlcode < 0)
    {
      // Couldn't describe it
      sprintf (errbuff, "Unable to process (declare), Error %d\n   %s \n\n",
	       sqlca.sqlcode, ptr_insert);
      load_err (0, errbuff);
      return 0;
    }


  EXEC SQL OPEN c_insert;
  currline = 0;

  return 1;

}

/********************************************************************************/

int
do_commit_work ()
{
  EXEC SQL COMMIT WORK;
}


/********************************************************************************/

int
do_rollback_work ()
{
  EXEC SQL ROLLBACK WORK;
}


/********************************************************************************/

int
do_begin_work ()
{
  $BEGIN WORK;
  curr_tx_count = 0;
}




/********************************************************************************/
int
cleanup (struct s_dbloadline *dbload)
{
  int a;
  A4GL_debug ("In cleanup");

  if (ptrs_to_data)
    {
      if (dbload->f->delim == 0)
	{
	  // We allocated some memory for character position specified
	  // files...
	  for (a = 0; a < nptrs_to_data; a++)
	    {
	      A4GL_debug ("free pointers %d %s", a, ptrs_to_data[a]);
	      FREE (ptrs_to_data[a]);
	    }
	}
      A4GL_debug ("free ptrs_to_data");
      FREE (ptrs_to_data);
      A4GL_debug ("freed");
    }

  A4GL_debug ("Done cleanup of ptrs_to_data");

  if (isnulls)
    {
      A4GL_debug ("free isnulls");
      FREE (isnulls);
    }

  EXEC SQL CLOSE c_insert;
  unlock_table (dbload);
  do_commit_work();
}




/********************************************************************************/
int
process_line (char *s, struct s_dbloadline *dbload)
{
  load_ok = 1;
  Memory field;
  int a;
  int len;
  currline++;


  if (currline < lv_skip)
    return 1;			// Its good - because we dont care...




  if (dbload->f->delim)
    {				// Its a delimited file...
      char *ptr;
      int fldcnt = 1;
      int a;
      ptrs_to_data[0] = s;
      len = strlen (s);
      ptr = s;
      A4GL_debug ("Processing line %d %s\n", currline, s);
      while (1)
	{
	  ptr = strchr (ptr, dbload->f->delim[0]);
	  if (!ptr)
	    break;
	  if (fldcnt > nptrs_to_data)
	    {			// Too many fields on line..
	      load_err (0, "Too many fields on line");
	      return 0;
	    }
	  *ptr = 0;
	  ptrs_to_data[fldcnt] = ptr + 1;
	  ptr++;
	  fldcnt++;
	}
      fldcnt--;
      if (fldcnt != nptrs_to_data)
	{
	  load_err (0, "Too few fields on line");
	  return 0;
	}
      A4GL_debug ("Got %d fields\n", fldcnt);
      for (a = 0; a < fldcnt; a++)
	{
	  msz_to_data[a] = strlen (ptrs_to_data[a]) + 1;
	  A4GL_debug ("   %d. %s\n", a, ptrs_to_data[a]);
	}
    }
  else
    {				// Its a columnar file..
      int a;
      for (a = 0; a < nptrs_to_data; a++)
	{


	  // Lets clear down the memory first...
	  clr_memory_for_field (dbload, ptrs_to_data[a], a);

	  if (!cp_memory_for_field (s, dbload, ptrs_to_data[a], a))
	    {
	      return 0;
	    }
	}
    }


  mem_new (&field);
  for (a = 0; a < nfld; a++)
    {
      int field_no;
      enum
      { null = -1, notnull = 0 };
      Sqlva *col;
      field_no = fld[a] - 1;
      A4GL_debug ("Data : %s field %d fieldno %d\n", ptrs_to_data[field_no],
		  a, field_no);
      mem_rst (&field);
      mem_addstr (&field, ptrs_to_data[field_no], msz_to_data[field_no]);
      col = &idesc->sqlvar[a];

      if (convertdata (&field, col, BSSP_UNKNOWN) != 0)
	{
	  mem_del (&field);
	  A4GL_debug ("  Data BAD\n");
	  //load_err (-1, "Can't convert field to proper datatype");
	  return 0;
	}
      else
	{
	  A4GL_debug ("  Data OK\n");
	}

      if (dbload->f->delim == 0)
	{
	  // check to see if it matches out 
	  if (dbload->f->field_pos_list->pos[field_no]->null)
	    {
	      if (strcmp
		  (dbload->f->field_pos_list->pos[field_no]->null,
		   ptrs_to_data[field_no]) == 0)
		{
		  A4GL_debug ("Field is actually null - not %s\n",
			      ptrs_to_data[field_no]);
		  *col->sqlind = null;
		}
	    }
	}
    }

  mem_del (&field);

  EXEC SQL PUT c_insert USING DESCRIPTOR idesc;

  // All our data should be setup - now we need to check for nulls...

  curr_tx_count++;

  if (curr_tx_count > lv_commit)
    {
	do_commit_work();
      do_begin_work ();
    }

  A4GL_debug ("processed line\n");
  return 1;
}

/********************************************************************************/


#ifndef DEFAULT_TMPDIR
#define DEFAULT_TMPDIR  "/tmp"
#endif

int
load_err (int n, char *s)
{
  if (A4GL_isyes (acl_getenv ("ADBLOAD_TERMTOO")))
    {
      fprintf (stderr, "Error : %s\n", s);
    }
  load_ok = 0;
  logerr (currfname, currline, yylineno, s);
}


/*
** Return number of columns in table, or zero if table name invalid.
** Allow for 'owner'.tablename, "owner".tablename and owner.tablename
** This version does (finally) allow for temporary tables!
**
** The subterfuge with a_stmt circumvents the idiotic ESQL/C
** compiler which does not recognize that even though it cannot evaluate
** the size of an array, the C compiler is able to do so -- so it complains
** with a warning:
** Warning -33208: Runtime error is possible because size of 'stmt'
** is unknown.
*/
int
cols_in_table (char *tabname)
{
  char a_stmt[sizeof ("SELECT * FROM ") + 256];
  EXEC SQL BEGIN DECLARE SECTION;
  char *stmt = a_stmt;
  EXEC SQL END DECLARE SECTION;
  int n_columns = 0;
  Sqlda *d;

  sprintf (stmt, "SELECT * FROM %s", tabname);
  EXEC SQL PREPARE p_cols FROM:stmt;
  if (sqlca.sqlcode != 0)
    {
      sqlca.sqlcode = -206;	/* Table is not in database */
      strcpy (sqlca.sqlerrm, tabname);
      sql_error ("", "");
    }
  else
    {
      EXEC SQL DESCRIBE p_cols INTO d;
      if (sqlca.sqlcode != 0 || d == 0)
	{
	  sprintf (stmt, "Unexpected error on DESCRIBE for table %s\n",
		   tabname);
	  sqlca.sqlcode = -746;
	  sqlca.sqlerrd[1] = 0;
	  strcpy (sqlca.sqlerrm, stmt);



	}
      n_columns = d->sqld;
      EXEC SQL FREE p_cols;
      if (sqlca.sqlcode != 0)
	{
	  sprintf (stmt, "Unexpected error on FREE for table %s\n", tabname);
	  sqlca.sqlcode = -746;
	  sqlca.sqlerrd[1] = 0;
	  strcpy (sqlca.sqlerrm, stmt);
	}
    }
  return (n_columns);
}

/********************************************************************************/

int
ec_check_and_report_error ()
{
  if (sqlca.sqlcode < 0)
    {
      load_err (0, "Some SQL Error");
      load_ok = 0;
    }
}


/********************************************************************************/
/* 
Generate the (col,col)=(val,val) portion of the insert statement  
if not given 
*/
void
ensure_colexpr (struct s_dbloadline *dbload)
{
  $char colname[260];
  $char tabname[260];
  char bigbuff_col[100000];
  char bigbuff_val[100000];
  char *ptr;
  char smbuff[200];
  $int colno;



  if (strlen (dbload->i->colexpr) == 0)
    {
      // looks like we're going to have to generate it...
      strcpy (tabname, dbload->i->tabname);
      EXEC SQL DECLARE c_getcols CURSOR FOR
	select colname, colno from systables, syscolumns
	where systables.tabname = $tabname
	and systables.tabid = syscolumns.tabid order by colno;
      EXEC SQL OPEN c_getcols;

      while (1)
	{
	  EXEC SQL FETCH c_getcols INTO $colname, $colno;

	  if (sqlca.sqlcode != 0)
	    break;
	  if (strlen (bigbuff_col))
	    {
	      strcat (bigbuff_col, ",");
	    }
	  trim (colname);
	  strcat (bigbuff_col, colname);
	  if (strlen (bigbuff_val))
	    {
	      strcat (bigbuff_val, ",");
	    }
	  sprintf (smbuff, "\t%d\n", colno);
	  strcat (bigbuff_val, smbuff);
	}

      EXEC SQL CLOSE c_getcols;

      ptr = malloc (strlen (bigbuff_col) + strlen (bigbuff_val) + 200);
      sprintf (ptr, "(", tabname);
      strcat (ptr, bigbuff_col);
      strcat (ptr, ") VALUES (");
      strcat (ptr, bigbuff_val);
      strcat (ptr, ")");

      dbload->i->colexpr = ptr;
    }
}

#include "esqltype.h"
#include "jtypes.c"
