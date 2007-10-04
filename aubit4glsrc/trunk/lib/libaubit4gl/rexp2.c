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
# $Id: rexp2.c,v 1.43 2007-10-04 19:26:13 mikeaubury Exp $
#
*/

/**
 * @file
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */


/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define  EQ 	1
#define  LEQ 	2
#define  NEQ 	3
#define  GEQ 	4
#define  LTHN 	5
#define  GTHN 	6
#define  BIGG 	7
#define  LST 	8
#define  OR 	8
#define  RANGE 	10
#define  RANGE_DOT_DOT 	11
/*
#define CONSTR_SEP '\t'
#define like(s1,s2) mja_match(s1,s2,'L');
#define matches(s1,s2) mja_match(s1,s2,'M');
*/

#define is_match_decimal "[\\+\\-]{0,1}[0-9]{0,}\\.[0-9]{0,}"
#define is_match_integer "[\\+\\-]{0,1}[0-9]{1,}"

#define MATCH_LITERAL  5	/* A4GL_match failure on literal A4GL_match */
#define MATCH_RANGE    4	/* A4GL_match failure on [..] A4GL_construct */
#define MATCH_ABORT    3	/* premature end of text string */
#define MATCH_END      2	/* premature end of pattern string */
#define MATCH_VALID    1	/* valid A4GL_match */

/* pattern defines */
#define PATTERN_VALID  0	/* valid pattern */
#define PATTERN_ESC   -1	/* literal escape at end of pattern */
#define PATTERN_RANGE -2	/* malformed range in [..] A4GL_construct */
#define PATTERN_CLOSE -3	/* no end bracket in [..] A4GL_construct */
#define PATTERN_EMPTY -4	/* [..] A4GL_construct is empty */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

static int constr_size;
static char *constr_bits[256];

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


//void A4GL_doconstruct (char *s, char *whereclause);
int mja_matchcmp (char *a, char *s_match);
static int A4GL_is_construct_op (char *str, int i);
static void convert_constr_buffer (char *str);


// The 'range' character is the ':' - but this is valid for 
// a datetime (hour/minute minute/second separator)
// So - this flag is set when we're in a DATETIME field which has hours->minutes or minutes->seconds
int allow_range_character=1; 

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 *
 * @return
 */
static void
appendchr (char *s, char c)
{
  int a;

  a = strlen (s);
  if (c == '\'')
    appendchr (s, '\\');
  s[a] = c;
  s[a + 1] = 0;

}


/**
 *
 *
 * @return
 */
int
A4GL_mja_match (char *str1, char *str2, int likeormatch)
{
  char MULTICHAR, SINGLECHAR, BRACECHAR;
  int error;

  A4GL_trim (str1);
  A4GL_trim (str2);
#ifdef DEBUG
  {
    A4GL_debug ("Match '%s' '%s' %c", str1, str2, likeormatch);
  }
#endif

  if (likeormatch == 'L')
    {
      MULTICHAR = '%';
      SINGLECHAR = '.';
      BRACECHAR = ' ';
    }
  else
    {
      MULTICHAR = '*';
      SINGLECHAR = '?';
      BRACECHAR = '[';
    }

  A4GL_debug ("Calling matche...");
  error = A4GL_matche (str2, str1, MULTICHAR, SINGLECHAR, BRACECHAR);
  A4GL_debug ("A4GL_matche=%d (VALID=%d)\n", error, MATCH_VALID);
  if (error == MATCH_VALID)
    return 1;
  else
    return 0;
}

static char *
A4GL_escape_single (char *s)
{
  int a;
  int b;
  char *ptr;

  A4GL_assertion (s == 0, "Passed in a null pointer for A4GL_escape_single");
  if (!strchr (s, '\''))
    return acl_strdup (s);
  ptr = acl_malloc2 (strlen (s) * 2 + 1);
  memset (ptr, 0, strlen (s) * 2 + 1);
  b = 0;
  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == '\'')
	{
	  ptr[b++] = '\'';
	  ptr[b++] = '\'';
	}
      else
	{
	  ptr[b++] = s[a];
	}
    }

  return ptr;

}

/**
 *
 *
 * @return
 */
char *
A4GL_construct (char *tabname, char *colname_s, char *val, int inc_quotes,int dtype, int dtype_size)
{
  char *ptr2;
  int a;
  char quote[2] = "";
  static char buffer[512];
  static char buff2[512];
  static char buff3[512];
  char using_dates[100][20];
  int z;
  int z2;
	int zz;
  int cnt;
  int k, k2 = 0;
  char lastchar;
  int ismatch;
  char colname[256];
  char *ptr;

  if (inc_quotes==3 || inc_quotes==4) {
		if (dtype==DTYPE_DTIME) { 
			char *p;
			int a;
			// DATETIME RANGE KLUDGE
			// one problem we have is if we have a datetime - and a range
			//
			// Lets figure out how long out datetime should be
			// Quick and dirty way is to measure the length of
			// a 'CURRENT' with the same dimensions...
			A4GL_push_current(dtype_size>>4, dtype_size&0xf);
			p=A4GL_char_pop(); 
	
			if (strchr(p,':')) {	
				// Darn - it contains a ':' - so we cant use this as a range character
				allow_range_character=0;
			} else {
				allow_range_character=1;
			}
			a=strlen(p);
			free(p);
			if (strlen(val)>a && !A4GL_is_construct_op (val, 0)) {
				if (val[a]==':') {
					static char buffx[2000]; // Static so we can keep a reference to it..
					// Those fools have specified a range..
					// Lets convert it from a 'VAL1:VAL2' style range
					// to a 'VAL1..VAL2' style range
					strcpy(buffx,val);
					buffx[a]=0;
					strcat(buffx,"..");
					strcat(buffx,&val[a+1]);
					val=buffx;
				}
			}
		}
  } else {
		allow_range_character=1;
  }

  for (a=0;a<100;a++) {strcpy(using_dates[a],"");}

  if (tabname == 0)
    {
      tabname = "";
    }
  A4GL_debug ("A4GL_construct : '%s' '%s' '%s'", tabname, colname_s, val);
  if (strlen (tabname))
    {
      SPRINTF2 (colname, "%s.%s", tabname, colname_s);
    }
  else
    {
      strcpy (colname, colname_s);
    }

  A4GL_trim (val);
  ptr2 = val;
  strcpy (buff3, "");
#ifdef DEBUG
  {
    A4GL_debug ("Colname = %s , val = %s incq=%d\n", colname, val,
		inc_quotes);
  }
#endif
  if (strcmp (val, "") == 0) {
	A4GL_debug("Returning %s", buff3);
    return buff3;
  }

  constr_size = 0;
  constr_bits[constr_size++] = buffer;
  A4GL_debug ("constr_size++ now %d", constr_size);

  if (inc_quotes)
    strcpy (quote, "'");

  /* Clear buffer */
  strcpy (buffer, "");
  lastchar = -1;
  z = -1;
  ismatch = 0;
  A4GL_debug ("ptr2=%s", ptr2);
  for (a = 0; a < strlen (ptr2); a++)
    {

      if (ptr2[a] == '[' || ptr2[a] == '*' || ptr2[a] == '?')
	{
	  if (!A4GL_isyes (acl_getenv ("CONSTRUCT_NO_MATCHES")))
	    {
	      ismatch = 1;
	    }
	}

      if (ptr2[a] == '%' || ptr2[a] == '_')
	{
	  if (A4GL_isyes (acl_getenv ("CONSTRUCT_LIKE")))
	    {
	      if (ismatch != 1)
		ismatch = 2;
	    }
	}

      lastchar = z;
      z = A4GL_is_construct_op (ptr2, a);
      A4GL_debug ("z=%d", z);



      if (z > 0 && lastchar == 0)
	{			/* last character was not a control */
		if (z==RANGE_DOT_DOT) {
	  		appendchr (buffer, '\n');
	  		constr_bits[constr_size++] = &buffer[strlen (buffer)];
	  		appendchr (buffer, ptr2[a]);
	  		appendchr (buffer, ptr2[a]);
			lastchar=0;
			a++;
		} else {
	  		appendchr (buffer, '\n');
	  		constr_bits[constr_size++] = &buffer[strlen (buffer)];
	  		appendchr (buffer, ptr2[a]);
		}
	  A4GL_debug ("constr_size++ now %d", constr_size);
	  /*constr_bits[constr_size++]=&ptr2[a]; */
	  /*constr_bits[constr_size++]=&buffer[strlen(buffer)-1]; */
	}
      else if (z == 0 && lastchar > 0)
	{			/* last character was a control
				   but this one isnt */
	  appendchr (buffer, '\n');
	  constr_bits[constr_size++] = &buffer[strlen (buffer)];
	  appendchr (buffer, ptr2[a]);
	  A4GL_debug ("constr_size++ now %d", constr_size);
	  /*constr_bits[constr_size++]=&buffer[strlen(buffer)-1]; */
	}
      else
	{
	  if (z > 0 && lastchar > 0)
	    {
	      if (lastchar < OR && z == EQ )
		{
		  appendchr (buffer, ptr2[a]);
		}
	      else
		{
		  appendchr (buffer, '\n');
		  constr_bits[constr_size++] = &buffer[strlen (buffer)];
		  appendchr (buffer, ptr2[a]);

		  A4GL_debug ("constr_size++ now %d", constr_size);
		}
	    }
	  else
	    {
	      appendchr (buffer, ptr2[a]);
	    }
	}

      lastchar = z;
    }






  convert_constr_buffer (buffer);


  if (inc_quotes == 0)
    {
      A4GL_debug ("constr_size = %d\n", constr_size);
      for (zz = 0; zz < constr_size; zz++)
	{
	  if (A4GL_is_construct_op (constr_bits[zz], 0) == 0
	      || (zz > 1 && A4GL_is_construct_op (constr_bits[zz], 0) != OR))
	    {

	      char *eptr;
	      k = 1;
	      strtod (constr_bits[zz], &eptr);
	      //strtol(constr_bits[zz], &eptr,10);
	      A4GL_debug ("eptr=%p *eptr=%p\n", eptr, *eptr);
	      if (eptr == 0)
		k = 0;
	      if (eptr)
		{
		  if (*eptr != 0)
		    {
		      k = 0;
		    }
		}

	      if (k || k2);
	      else
		{
		  /* error in numeric */
		  A4GL_debug ("error in numeric");
		  return 0;
		}
	    }
	}
    }


  if (inc_quotes == 2)		/* Its a date */
    {
	//A4GL_pause_execution();
      A4GL_debug ("constr_size = %d\n", constr_size);
      for (zz = 0; zz < constr_size; zz++)
	{
	  if (A4GL_is_construct_op (constr_bits[zz], 0) == 0 || (zz > 1 && A4GL_is_construct_op (constr_bits[zz], 0) != OR))
	    {
	      int n;
	      if (A4GL_stod (constr_bits[zz], &n, 0) && !A4GL_isnull (DTYPE_DATE, (void *) &n))
		{
		char *p;
			int b;
		  A4GL_debug ("CDATE Returns true for %s n=%d", constr_bits[zz], n);
			for (b=0;b<100;b++) {
				if (strlen(using_dates[b])==0)  break;
			}
			A4GL_push_date(n);
			p=A4GL_char_pop();
			A4GL_debug("Date really looks like : %s",p);
			strcpy(using_dates[b], p);
			free(p);
			constr_bits[zz]=using_dates[b];
			
		}
	      else
		{
		  A4GL_debug ("CDATE Returns false for %s or its null",
			      constr_bits[zz]);
		  return 0;
		}

	    }
	}
    }

  if (inc_quotes == 3)		/* Its a datetime */
    {
		
      A4GL_debug ("constr_size = %d\n", constr_size);
      for (zz = 0; zz < constr_size; zz++)
	{
	  if (A4GL_is_construct_op (constr_bits[zz], 0) == 0 || (zz > 1 && A4GL_is_construct_op (constr_bits[zz], 0) != OR))
	    {
	      int n;
		int parts[10];
		char buff[2000];
		struct A4GLSQL_dtime d;
		if (!A4GL_valid_dt(constr_bits[zz], parts,dtype_size)) {
			
		  		A4GL_debug ("CDATETIME Returns false for %s or its null", constr_bits[zz]);
		  return 0;
		}
		n=A4GL_ctodt(constr_bits[zz],&d,dtype_size);
		if (n==0) {
			return 0;
		}
		A4GL_dttoc(&d,buff,40);
		if (strlen(buff)!=strlen(constr_bits[zz])) {
			// Too long or too short
			return 0;
		}

	    }
	}
    }

  if (inc_quotes == 4)		/* Its an interval */
    {
      A4GL_debug ("constr_size = %d\n", constr_size);
      for (zz = 0; zz < constr_size; zz++)
	{
	  if (A4GL_is_construct_op (constr_bits[zz], 0) == 0 || (zz > 1 && A4GL_is_construct_op (constr_bits[zz], 0) != OR))
	    {
	      int n;
		int parts[10];
		char buff[2000];
		if (!A4GL_valid_int(constr_bits[zz], parts,0)) {
		  	A4GL_debug ("CINTERVAL Returns false for %s or its null",
			      constr_bits[zz]);
		  return 0;
		}

	    }
	}
	
    }

  strcpy (buff2, "");
  z = A4GL_is_construct_op (constr_bits[0], 0);
  if (constr_size > 1)
    z2 = A4GL_is_construct_op (constr_bits[1], 0);
  else
    z2 = 0;
  if (ismatch && !inc_quotes)
    {
#ifdef DEBUG
      {
	A4GL_debug ("Expression error");
      }
#endif
      A4GL_debug ("error in expression");
      return 0;
    }

  if (z == 0 && z2 == 0)
    {
      if (ismatch)
	{
	  if (ismatch == 1)
	    {
	      strcat (buff2, " matches ");
	      if (A4GL_isyes (acl_getenv ("CONSTRUCT_MATCH_FIX")))
		{
		  char *ptr;
		  static char ptr2[2000];
		  static char ptr3[2000];
		  ptr = A4GL_escape_single (constr_bits[0]);
		  SPRINTF3 (ptr2, "%s%s%s", quote, ptr, quote);
		  sprintf(ptr3, "%s %s", colname, A4GLSQLCV_matches_string ("", ptr2, "\"\\\""));
			A4GL_debug("Returning %s", ptr3);
		  return ptr3;
		}
	    }

	  if (ismatch == 2)
	    {
	      strcat (buff2, " like ");
	    }

	}
      else
	{
	  strcat (buff2, "=");
	}
      strcat (buff2, quote);
      A4GL_debug ("constr_size = %d\n", constr_size);

      for (cnt = 0; cnt < constr_size; cnt++)
	{
	  char *ptr;
	  A4GL_debug ("cat : %s %s", buff2, constr_bits[cnt]);
	  ptr = A4GL_escape_single (constr_bits[cnt]);
	  strcat (buff2, ptr);
	  free (ptr);
	}
      SPRINTF3 (buff3, "%s%s%s", colname, buff2, quote);
    }

  A4GL_debug ("z=%d", z);
  if (z > 0 && z < OR)
    {
      ptr = A4GL_escape_single (constr_bits[0]);
      strcat (buff2, ptr);
      free (ptr);


      strcat (buff2, quote);
      for (zz = 1; zz < constr_size; zz++)
	{
	  ptr = A4GL_escape_single (constr_bits[zz]);
	  strcat (buff2, ptr);
	  free (ptr);
	}
      strcat (buff2, quote);

      if (strcmp (buff2, "=") == 0)
	{
	  strcpy (buff2, " is null");
	}
      if (strcmp (buff2, "!=") == 0)
	{
	  strcpy (buff2, " is not null");
	}
      if (strcmp (buff2, "=''") == 0)
	{
	  strcpy (buff2, " is null");
	}
      if (strcmp (buff2, "!=''") == 0)
	{
	  strcpy (buff2, " is not null");
	}


      SPRINTF2 (buff3, "%s%s", colname, buff2);
    }
  if (z == OR || (z2 == OR && z == 0))
    {
      if (z == OR)
	{
	  SPRINTF1 (buff3, "%s in ('',", colname);
	  for (zz = 1; zz < constr_size; zz++)
	    {
	      if (A4GL_is_construct_op (constr_bits[zz], 0) == OR)
		continue;
	      strcat (buff3, quote);
	      ptr = A4GL_escape_single (constr_bits[zz]);
	      strcat (buff3, ptr);
	      free (ptr);
	      strcat (buff3, quote);
	      if (zz < constr_size - 1)
		strcat (buff3, ",");
	    }
	  if (buff3[strlen (buff3) - 1] == ',')
	    strcat (buff3, "''");
	  /*buff3[strlen(buff3)-1]=0; */
	  strcat (buff3, ")");
	}
      else
	{
	  SPRINTF1 (buff3, "%s in (", colname);
	  for (zz = 0; zz < constr_size; zz++)
	    {
	      if (A4GL_is_construct_op (constr_bits[zz], 0) == OR)
		continue;
	      strcat (buff3, quote);
	      ptr = A4GL_escape_single (constr_bits[zz]);
	      strcat (buff3, ptr);
	      free (ptr);
	      strcat (buff3, quote);
	      if (zz < constr_size - 1)
		strcat (buff3, ",");
	    }
	  if (buff3[strlen (buff3) - 1] == ',')
	    strcat (buff3, "''");
	  strcat (buff3, ")");
	}
    }


  if (z == RANGE || z2 == RANGE)
    {
      if (z == RANGE)
	{
	  SPRINTF2 (buff3, "(%s between '' and %s", colname, quote);
	  for (zz = 1; zz < constr_size; zz++)
	    {
	      ptr = A4GL_escape_single (constr_bits[zz]);
	      strcat (buff3, ptr);
	      free (ptr);
	    }
	  strcat (buff3, quote);
	}
      else
	{
	  SPRINTF4 (buff3, "%s between %s%s%s and ", colname, quote,
		    constr_bits[0], quote);
	  if (constr_size >= 2)
	    {
	      strcat (buff3, quote);
	      for (zz = 2; zz < constr_size; zz++)
		{
		  ptr = A4GL_escape_single (constr_bits[zz]);
		  A4GL_assertion (ptr == 0, "No returned pointer");
		  strcat (buff3, ptr);
		  free (ptr);
		}
	      strcat (buff3, quote);
	    }
	  else
	    strcat (buff3, "''");
	}
      strcat (buff3, "");
    }


  if (z == RANGE_DOT_DOT || z2 == RANGE_DOT_DOT)
    {
      if (z == RANGE)
	{
	  SPRINTF2 (buff3, "(%s between '' and %s", colname, quote);
	  for (zz = 1; zz < constr_size; zz++)
	    {
	      ptr = A4GL_escape_single (constr_bits[zz]);
	      strcat (buff3, ptr);
	      free (ptr);
	    }
	  strcat (buff3, quote);
	}
      else
	{
	  SPRINTF4 (buff3, "%s between %s%s%s and ", colname, quote,
		    constr_bits[0], quote);
	  if (constr_size >= 2)
	    {
	      strcat (buff3, quote);
	      for (zz = 2; zz < constr_size; zz++)
		{
		  ptr = A4GL_escape_single (constr_bits[zz]);
		  A4GL_assertion (ptr == 0, "No returned pointer");
		  strcat (buff3, ptr);
		  free (ptr);
		}
	      strcat (buff3, quote);
	    }
	  else
	    strcat (buff3, "''");
	}
      strcat (buff3, "");
    }
#ifdef DEBUG
  {
    A4GL_debug ("buff3= [ %s ]\n", buff3);
  }
#endif
  return buff3;
}


/**
 *
 *
 * @return
 */
static int
A4GL_is_construct_op (char *str, int i)
{
  if (i >= 2)
    {
      if (str[i - 2] != '\\' && str[i - 1] == '\\')
	return 0;
    }
  if (i >= 1)
    {
      if (str[i - 1] == '\\')
	return 0;
    }
  if (str[i] == '=')
    return EQ;
  if (str[i] == '=')
    return EQ;
  if (str[i] == '<' && str[i + 1] == '=')
    return LEQ;
  if (str[i] == '!' && str[i + 1] == '=')
    return NEQ;
  if (str[i] == '>' && str[i + 1] == '=')
    return GEQ;
  if (str[i] == '<')
    return LTHN;
  if (str[i] == '>')
    return GTHN;
  if (str[i] == '|')
    return OR;
  if (str[i] == ':' && allow_range_character)
    return RANGE;
  if (str[i] == '.' && str[i + 1] == '.')
    return RANGE_DOT_DOT;
  return 0;
}


/**
 *
 *
 * @return
 */
static void
convert_constr_buffer (char *str)
{
  int a;
  int b;

  b = strlen (str);
  for (a = 0; a < b; a++)
    {
      if (str[a] == '\n')
	str[a] = 0;
    }
}




/* ============================ EOF ================================== */
