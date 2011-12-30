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
# $Id: conv.c,v 1.190 2011-10-20 19:00:12 mikeaubury Exp $
#
*/

/**
 * @file
 * Data type convertion functions.
 *
 * Its used to the assignment of diferent data type values and the implicit
 * convertions that 4gl use.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

 /*
    =====================================================================
    Includes
    =====================================================================
  */


#define EXTERN_CONVFMTS
#include "a4gl_libaubit4gl_int.h"
#include <ctype.h>

//int A4GL_conversion_ok(int);

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

/**
 * definitions for dates (seems a pretty odd conversion though...
 */
#define A4GL_itomdec 	A4GL_itodec
#define A4GL_dtodec 	A4GL_ltodec
#define A4GL_dtomdec 	A4GL_ltodec
#define A4GL_ltomdec 	A4GL_ltodec
#define A4GL_stomdec 	A4GL_stodec

#define A4GL_ftomdec 	A4GL_ftodec
#define A4GL_sftomdec 	A4GL_sftodec
#define A4GL_mdectomdec A4GL_dectodec
#define A4GL_mdectodec 	A4GL_dectodec
#define A4GL_dectomdec 	A4GL_dectodec

#define OK (void *)1




#define print_res(x) 	print_res_l(__LINE__,x)
#define dt_encode(s,e) 	((s*16)+e)
#define DT_YEAR 		1
#define DT_MONTH 		2
#define DT_DAY 			3
#define DT_HOUR 		4
#define DT_MINUTE 		5
#define DT_SECOND 		6
#define DT_FRACTION 		7


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/** @todo Change all this function proptotypes to an header */
int A4GL_conv_invdatatoc (int *data, int v1, int v2, int v3, struct ival *d);
int A4GL_bname2 (char *str, char *s1, char *s2, char *s3);
char *A4GL_inv (char *s);
double A4GL_dec_to_double (fgldecimal * buf);
//char *A4GL_dec_to_str (fgldecimal *s, int size);
char *A4GL_add_dec (fgldecimal * a, fgldecimal * b);
fgldecimal *A4GL_minus_dec (fgldecimal * a, fgldecimal * b);
//char *A4GL_str_to_dec (char *s, fgldecimal *w);
//char *A4GL_init_dec (fgldecimal *s, int len, int d);
fgldecimal *A4GL_mult_dec (fgldecimal * s, fgldecimal * v);
fgldecimal *A4GL_divide_dec (fgldecimal * s, fgldecimal * w);

void A4GL_dec_to_dec (fgldecimal * f, fgldecimal * t);
void A4GL_dump (char *s);

int A4GL_op_ival (struct ival *a, struct ival *b, double double_val, char op, char param);


void A4GL_trim_dec (fgldecimal * s);
void A4GL_negate (fgldecimal * s);
void A4GL_pr (char *wrkbf);
void A4GL_double_to_dec (double arg, char *buf, size_t length, size_t digits);
//void A4GL_assertion                        (int a, char *s);


//int A4GL_valid_dt (char *s, int *data,int size);


int A4GL_itoint (void *a_short, void *b_int, int size_b);

int A4GL_ltoint (void *a_long, void *b_int, int size_b);

int A4GL_ftoint (void *a_f, void *b_int, int size_b);

int A4GL_sftoint (void *a_sf, void *b_int, int size_b);

int A4GL_dectoint (void *a_dec, void *b_int, int size_b);

int A4GL_ctoc (void *a, void *b, int size);
//int A4GL_ctodt             (void *a, void *b, int size);
//int A4GL_ctoint            (void *a, void *b, int size);

//int A4GL_valid_int (char *s, int *data, int size);

void A4GL_setc (void *p);
void A4GL_seti (void *p);
void A4GL_setl (void *p);
void A4GL_setf (void *p);
void A4GL_setno (void *p);
void A4GL_setsf (void *p);

int A4GL_inttoint (void *a, void *b, int size);


int A4GL_inttoc (void *a1, void *b, int size);
int A4GL_mdectol (void *zz, void *aa, int sz_ignore);
int A4GL_mdectof (void *zz, void *aa, int sz_ignore);
int A4GL_mdectos (void *z, void *w, int size);

int A4GL_ltodec (void *a, void *z, int size);

int A4GL_btob (void *a, void *b, int size);

int A4GL_dtos (void *aa, void *zz, int size);
//int A4GL_dttoc (void *a, void *b, int size);
int A4GL_dtof (void *aa, void *zz, int sz_ignore);
int A4GL_dtovc (void *aa, void *zz, int sz_ignore);
int A4GL_dtosf (void *aa, void *zz, int sz_ignore);
int A4GL_dtol (void *aa, void *zz, int sz_ignore);
int A4GL_dtoi (void *aa, void *zz, int sz_ignore);
int A4GL_dttodt (void *a, void *b, int size);

int A4GL_mdectoi (void *zz, void *aa, int sz_ignore);
int A4GL_mdectosf (void *zz, void *aa, int sz_ignore);

int A4GL_dectodec (void *a, void *z, int size);
int A4GL_dectos (void *z, void *w, int size);
int A4GL_dectosf (void *zz, void *aa, int sz_ignore);
int A4GL_dectol (void *zz, void *aa, int sz_ignore);
int A4GL_dectof (void *zz, void *aa, int sz_ignore);
int A4GL_dectoi (void *zz, void *aa, int sz_ignore);

int A4GL_ltoi (void *aa, void *zz, int sz_ignore);
int A4GL_ltod (void *aa, void *zz, int sz_ignore);
int A4GL_ltof (void *aa, void *zz, int sz_ignore);
int A4GL_ltoc (void *aa, void *zz, int size);
int A4GL_ltol (void *aa, void *bb, int sz_ignore);
int A4GL_ltovc (void *aa, void *zz, int c);
int A4GL_ltosf (void *aa, void *zz, int sz_ignore);

int A4GL_ftoi (void *aa, void *zz, int c);
int A4GL_ftol (void *aa, void *zz, int c);
int A4GL_ftof (void *aa, void *bb, int c);
int A4GL_ftosf (void *aa, void *zz, int c);
int A4GL_ftodec (void *a, void *z, int size);
int A4GL_ftod (void *aa, void *zz, int sz_ignore);
int A4GL_ftoc (void *aa, void *zz, int c);
int A4GL_ftovc (void *aa, void *zz, int c);


int A4GL_itof (void *aa, void *zz, int sz_ignore);
int A4GL_itosf (void *aa, void *zz, int sz_ignore);
int A4GL_itodec (void *a, void *z, int size);
int A4GL_itol (void *aa, void *zz, int sz_ignore);
int A4GL_itod (void *aa, void *zz, int sz_ignore);
int A4GL_itovc (void *aa, void *zz, int c);
int A4GL_itoi (void *aa, void *bb, int sz_ignore);
int A4GL_itoc (void *aa, void *zz, int size);

//int A4GL_stof (void *aa, void *zz, int sz_ignore);
int A4GL_sftovc (void *aa, void *zz, int c);
int A4GL_sftod (void *aa, void *zz, int sz_ignore);
int A4GL_sftol (void *aa, void *zz, int c);
int A4GL_sftoi (void *aa, void *zz, int c);
int A4GL_sftoc (void *aa, void *zz, int c);
int A4GL_sftof (void *aa, void *zz, int c);
int A4GL_sftosf (void *aa, void *bb, int c);
int A4GL_sftodec (void *a, void *z, int size);
//int A4GL_stol (void *aa, void *zi, int sz_ignore);
//int A4GL_stodec (void *a, void *z, int size);
//int A4GL_stomdec (void *a, void *z, int size);
int A4GL_stosf (void *aa, void *zz, int sz_ignore);
int A4GL_stoi (void *aa, void *zi, int sz_ignore);
//void A4GL_decode_datetime (struct A4GLSQL_dtime *d, int *data);

int A4GL_mdectod (void *zz, void *aa, int sz_ignore);

//static fgldecimal *dec_math (fgldecimal *s, fgldecimal *w, fgldecimal *r, char op);
//static void match_dec (fgldecimal *f, fgldecimal *t, int *a, int *b);
//void A4GL_set_setdtype (int dtype, void *ptr);
int A4GL_dectod (void *zz, void *aa, int sz_ignore);
int A4GL_d_to_dt (void *a, void *b, int size);
int A4GL_dt_to_d (void *a, void *b, int size);
int A4GL_dttovc (void *a, void *b, int size);


/* Varchar handling */
int A4GL_vctoc (void *a, void *b, int size);
int A4GL_vctovc (void *a, void *b, int size);
int A4GL_ctovc (void *a, void *b, int size);
int A4GL_vctoint (void *a, void *b, int size);
int A4GL_vctoi (void *a, void *b, int size);
int A4GL_vctol (void *a, void *b, int size);
int A4GL_vctod (void *a, void *b, int size);
int A4GL_vctosf (void *a, void *b, int size);
int A4GL_dectovc (void *a, void *b, int size);
int A4GL_mdectovc (void *a, void *b, int size);
int A4GL_vctof (void *a, void *b, int size);
int A4GL_vctodec (void *a, void *b, int size);
int A4GL_vctomdec (void *a, void *b, int size);
int A4GL_vctodt (void *a, void *b, int size);




#ifdef TEST
static void exercise (void);
static void print_res_l (int ln, char *s);
#endif

#include <errno.h>
/* extern int 		errno; */

static int size_of_operand = 0;

static int getdt_as_dbl(struct A4GLSQL_dtime *d,double *val) ;
static int A4GL_dttoi (void *a, void *b, int size) ;
static int A4GL_dttol (void *a, void *b, int size) ;
static int A4GL_dttosf (void *a, void *b, int size) ;
static int A4GL_dttof (void *a, void *b, int size) ;
/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/**
 * @deprecated
 */
/*
typedef struct
{
  double value, expect;
  int length, digits;
} TEST_T;
*/

void (*setdtype[MAX_DTYPE]) (void *ptr1) =
{
A4GL_setc, A4GL_seti, A4GL_setl, A4GL_setf,
    A4GL_setsf, A4GL_setf, A4GL_setl, A4GL_setno, A4GL_setf, A4GL_setno, A4GL_setno, A4GL_setno, A4GL_setno, A4GL_setno,
    A4GL_setno,
    A4GL_setno,
    A4GL_setno,
    A4GL_setno,
    A4GL_setno,
    A4GL_setno, A4GL_setno, A4GL_setno, A4GL_setno, A4GL_setno, A4GL_setno, A4GL_setno, A4GL_setno, A4GL_setno, A4GL_setno};


/**
 * Convertion table.
 */
int (*convmatrix[MAX_DTYPE][MAX_DTYPE]) (void *ptr1, void *ptr2, int size) =
{
  {
  A4GL_ctoc, A4GL_stoi, A4GL_stol, A4GL_stof, A4GL_stosf, A4GL_stodec, A4GL_stol, A4GL_stod, A4GL_stomdec, NO, A4GL_ctodt, NO, NO, A4GL_ctovc, A4GL_ctoint},
  {
  A4GL_itoc, A4GL_itoi, A4GL_itol, A4GL_itof, A4GL_itosf, A4GL_itodec, A4GL_itol, A4GL_itod, A4GL_itomdec, NO, NO, NO, NO,
      A4GL_itovc, A4GL_itoint},
  {
  A4GL_ltoc, A4GL_ltoi, A4GL_ltol, A4GL_ltof, A4GL_ltosf, A4GL_ltodec, A4GL_ltol, A4GL_ltod, A4GL_ltomdec, NO, NO, NO, NO,
      A4GL_ltovc, A4GL_ltoint},
  {
  A4GL_ftoc, A4GL_ftoi, A4GL_ftol, A4GL_ftof, A4GL_ftosf, A4GL_ftodec, A4GL_ftol, A4GL_ftod, A4GL_ftomdec, NO, NO, NO, NO,
      A4GL_ftovc, A4GL_ftoint},
  {
  A4GL_sftoc, A4GL_sftoi, A4GL_sftol, A4GL_sftof, A4GL_sftosf, A4GL_sftodec, A4GL_sftol, A4GL_sftod, A4GL_sftomdec, NO, NO, NO,
      NO, A4GL_sftovc, A4GL_sftoint},
  {
  A4GL_dectos, A4GL_dectoi, A4GL_dectol, A4GL_dectof, A4GL_dectosf, A4GL_dectodec, A4GL_dectol, NO, A4GL_dectomdec, NO, NO, NO,
      NO, A4GL_dectovc, A4GL_dectoint},
  {
  A4GL_ltoc, A4GL_ltoi, A4GL_ltol, A4GL_ltof, A4GL_ltosf, A4GL_ltodec, A4GL_ltol, A4GL_ltod, A4GL_ltomdec, NO, NO, NO, NO,
      A4GL_ltovc, A4GL_ltoint},
  {
  A4GL_dtos, A4GL_dtoi, A4GL_dtol, A4GL_dtof, A4GL_dtosf, A4GL_dtodec, A4GL_dtof, A4GL_ltol, A4GL_dtomdec, NO, A4GL_d_to_dt, NO,
      NO, A4GL_dtovc, NO},
  {
  A4GL_mdectos, A4GL_mdectoi, A4GL_mdectol, A4GL_mdectof, A4GL_mdectosf, A4GL_mdectodec, A4GL_mdectol, NO, A4GL_mdectomdec, NO,
      NO, NO, NO, A4GL_mdectovc, NO},
  {
  NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO},
  {
  A4GL_dttoc, A4GL_dttoi, A4GL_dttol, A4GL_dttof, A4GL_dttosf, NO, NO, A4GL_dt_to_d, NO, NO, A4GL_dttodt, NO, NO, A4GL_dttovc, NO, NO},
  {
  NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, A4GL_btob, NO, NO, NO},
  {
  NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, A4GL_btob, NO, NO},
  {
  A4GL_vctoc, A4GL_vctoi, A4GL_vctol, A4GL_vctof, A4GL_vctosf, A4GL_vctodec, A4GL_vctol, A4GL_vctod, A4GL_vctomdec, NO,
      A4GL_vctodt, NO, NO, A4GL_vctovc, A4GL_vctoint},
  {
  A4GL_inttoc, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, A4GL_inttoint},
};



/*
=====================================================================
                    Functions definitions
=====================================================================
*/



/**
 * Copy a int value.
 *
 * @param a The interval to be copied.
 * @param b A pointer to the place where to put the value copied.
 * @param size
 * @return Allways 1
 */
int
A4GL_inttoint (void *a, void *b, int size)
/* A4GL_inttoint (struct ival *a, void *b, int size) */
{
  //int data[20];
  //int val1, val2, val3;
  struct ival *d;
  struct ival *e;
  char buff[256];
  int ival_data[10];
  int isneg;
  int ok;

#ifdef DEBUG
  A4GL_debug ("inttoint size=%d\n", size);
#endif
  d = b;
  e = a;
#ifdef DEBUG
  A4GL_debug ("e->stime=0x%x e->ltime=0x%x", e->stime, e->ltime);
#endif
  memset (buff, 0, 256);

  d->i_years=0;
  d->i_months=0;
  d->i_days=0;
  d->i_hours=0;
  d->i_minutes=0;
  d->i_seconds=0;
  d->i_fractions=0;
  d->is_neg=0;

  A4GL_inttoc (a, buff, 60);
  if ((e->stime & 0xf) == e->ltime)
    {

      // We've got a single timespan..
      if (e->ltime == 2 || e->ltime == 1)
	{			// MONTH TO MONTH or YEAR TO YEAR
	  A4GL_decode_interval (e, &ival_data[0], &isneg);
	  /* while (ival_data[1]>12 && 0) { ival_data[0]++; ival_data[1]-=12; } */
	  SPRINTF2 (buff, "%d-%d", ival_data[0], ival_data[1]);	// @FIXME - negative interval
	}
    }
  A4GL_trim (buff);
  //memset(d->data,0,sizeof(d->data));
#ifdef DEBUG
  A4GL_debug ("Got Interval as : '%s'\n", A4GL_null_as_null (buff));
#endif
  ok = A4GL_ctoint (buff, b, size);
  if (ok)
    {
      if (e->is_neg)
	d->is_neg = 1;
      else
	d->is_neg = 0;
    } else {
	printf("not ok\n");
#ifdef DEBUG
	A4GL_debug("Not ok\n");
#endif
    }


  return (ok);

/*
#ifdef DEBUG
  inttoc(a,buff,40);
	A4GL_debug(" Buff=%s\n",A4GL_null_as_null(buff));
#endif


if (size==e->stime*16+e->ltime) {
	
	memcpy(b,a,sizeof(struct ival));
	return 1;
}
  d->ltime = size & 15;
  d->stime = size >> 4;

  val1 = size & 15;
  val2 = (size >> 4) & 15;
  val3 = (size >> 8) & 15;

  A4GL_decode_interval (e,&data[0]);

  A4GL_debug("Converting to %d %d %d\n",val1,val2,val3);
  A4GL_conv_invdatatoc(data,val1,val2,val3,d->data);
  A4GL_debug("Set b..");
*/
  return 1;
}


/**
 *
 * @param a1 A pointer to theinteger value.
 * @param b A pointer to the place where to return the converted value.
 * @param size
 * return Allways 1
 */
int
A4GL_inttoc (void *a1, void *b, int size)
{
  struct ival *a;
  int s1;
  int s2;
  int e;
  int isneg;
  //int c;
  int cnt;
  //int cpc;
  //int c2;
  int data[10];
  int nfrac = 0;
  char buff[256];
  char buff2[256];
  //             0   1   2   3   4   5   6
  char *pre[] = { " ", "-", "-", " ", ":", ":", "." };


  //int spc[] = { 0, 4, 2, 2, 2, 2, 2, 5 };
  a = a1;

  data[0] = 0;
  data[1] = 0;
  data[2] = 0;
  data[3] = 0;
  data[4] = 0;
  data[5] = 0;
  data[6] = 0;
  data[7] = 0;
  data[8] = 0;
  data[9] = 0;

  A4GL_decode_interval (a, data, &isneg);
//@FIXME isneg interval

#ifdef DEBUG
  A4GL_debug ("Y: %d", data[0]);	// -
  A4GL_debug ("M: %d", data[1]);	// -
  A4GL_debug ("D: %d", data[2]);	// ' '
  A4GL_debug ("H: %d", data[3]);	// :
  A4GL_debug ("M: %d", data[4]);	// :
  A4GL_debug ("S: %d", data[5]);	// .
  A4GL_debug ("F: %d", data[6]);	// 
#endif

  s2 = a->stime % 16;
  s1 = a->stime / 16;
  e = a->ltime;

  if (e >= 7)
    {
      nfrac = e - 6;
      e = 7;
    }


  // s2 = start..
  // s1 = number of digits in start..
  strcpy (buff, "");
  for (cnt = s2; cnt <= e; cnt++)
    {

      if (strlen (buff))
	strcat (buff, pre[cnt - 1]);

#ifdef DEBUG
      A4GL_debug ("cnt =%d data=%d\n", cnt, data[cnt - 1]);
#endif

      if (cnt == 7)
	{
	  SPRINTF1 (buff2, "%05d", data[cnt - 1]);
	  buff2[nfrac] = 0;
	}
      else
	{
	  if (cnt == s2)
	    {
	      SPRINTF2 (buff2, "%*d", s1 + 1, data[cnt - 1]);
	    }
	  else
	    {
	      SPRINTF1 (buff2, "%02d", data[cnt - 1]);
	    }
	}


      strcat (buff, buff2);

    }
  if (s2 >= 8)
    {
      SPRINTF1 (buff, ".%05d", data[7]);
    }
  if (a->is_neg)
    {
      char buffcp[2000];
      if (buff[0] == ' ')
	{
	  for (cnt = 0; cnt < strlen (buff); cnt++)
	    {
	      if (buff[cnt] == ' ' && buff[cnt + 1] != ' ')
		{
		  buff[cnt] = '-';
		  break;
		}
	    }
	}
      else
	{
	  SPRINTF1 (buffcp, "-%s", buff);
	  strcpy (buff, buffcp);
	}
    }
#ifdef DEBUG
  A4GL_debug ("-->'%s'\n", A4GL_null_as_null (buff));
#endif
  A4GL_ctoc (buff, b, size);
  return 1;
}


int
A4GL_itoint (void *a_short, void *b_int, int size_b)
{
  char buff[256];
  SPRINTF1 (buff, "%d", *(short *) a_short);
  return A4GL_ctoint (buff, b_int, size_b);
}

int
A4GL_ltoint (void *a_long, void *b_int, int size_b)
{
  char buff[256];
  SPRINTF1 (buff, "%d", *(short *) a_long);
  return A4GL_ctoint (buff, b_int, size_b);
}

int
A4GL_ftoint (void *a_f, void *b_int, int size_b)
{
  char buff[256];
  SPRINTF1 (buff, "%lf", *(double *) a_f);
  return A4GL_ctoint (buff, b_int, size_b);
}

int
A4GL_sftoint (void *a_sf, void *b_int, int size_b)
{
  char buff[256];
  SPRINTF1 (buff, "%f", *(float *) a_sf);
  return A4GL_ctoint (buff, b_int, size_b);
}

int
A4GL_dectoint (void *a_dec, void *b_int, int size_b)
{
  char buff[256];
  A4GL_dectos (a_dec, buff, 64);
  return A4GL_ctoint (buff, b_int, size_b);
}

static void
A4GL_trim_trailing_0 (char *s)
{
  int a;
  int last_zero = -1;
  int has_dot = 0;
  A4GL_lrtrim (s);
  for (a = 0; a < strlen (s); a++)
    {
      if (s[a] == '.')
	has_dot = 1;
      if (has_dot && s[a] == '0')
	{
	  if (last_zero == -1)
	    {
	      last_zero = a;
	    }
	}
      if (s[a] != '0')
	{
	  last_zero = -1;
	}
    }
  if (last_zero != -1)
    {
      s[last_zero] = 0;
    }
}

/**
 *
 * @param a
 * @param b A pointer to the place where to return the value.
 * @return The result of the convertion:
 *   - 0 : The integer its not valid.
 *   - 1 : Convertion made.
 */
int
A4GL_ctoint (void *a_char, void *b_int, int size_b)
{
  int data[256];
  struct ival *d;
  int v1, v2, v3;
  char localchar[65];
  int is_neg = 0;
  int buff_size;
  int a;

  memset (localchar, 0, 65);
  memset (data, 0, 255);

  strcpy (localchar, a_char);
  A4GL_trim_trailing_0 (localchar);
  if (localchar[0] == '.')
    {
      char b[2000];
      strcpy (b, "0");
      strcat (b, localchar);
      strcpy (localchar, b);
    }
  buff_size = strlen (localchar);
  for (a = 0; a < buff_size; a++)
    {
      if (localchar[a] == '-')
	{
	  is_neg++;
	  localchar[a] = ' ';
	  break;
	}
      if (localchar[a] != ' ')
	break;
    }

  d = (struct ival *) b_int;

#ifdef DEBUG
  A4GL_debug ("ctoint - %s size_b=%x\n", A4GL_null_as_null (a_char), size_b);
#endif
  d->ltime = size_b & 15;
  d->stime = size_b >> 4;
  d->is_neg = is_neg;
#ifdef DEBUG
  A4GL_debug ("Set d->stime=%d d->ltime=%d %p", d->stime, d->ltime, d);
  A4GL_debug ("Set d->stime=%d d->ltime=%d %p", d->stime, d->ltime, d);
  A4GL_debug ("CHECK0.01 :  d->stime=%d d->ltime=%d %p", d->stime, d->ltime, d);
#endif


  v1 = size_b & 15;
#ifdef DEBUG
  A4GL_debug ("CHECK0.1 :  d->stime=%d d->ltime=%d", d->stime, d->ltime);
#endif
  v2 = (size_b >> 4) & 15;
#ifdef DEBUG
  A4GL_debug ("CHECK0.2 :  d->stime=%d d->ltime=%d", d->stime, d->ltime);
#endif
  v3 = (size_b >> 8) & 15;

#ifdef DEBUG
  A4GL_debug ("CHECK0 :  d->stime=%d d->ltime=%d", d->stime, d->ltime);
  A4GL_debug ("v1=%d v2=%d v3=%d\n", v1, v2, v3);
#endif

  if (A4GL_valid_int (localchar, data, size_b))
    {
#ifdef DEBUG
      A4GL_debug ("CHECK1 :  d->stime=%d d->ltime=%d", d->stime, d->ltime);
#endif
      A4GL_conv_invdatatoc (data, v1, v2, v3, d);
#ifdef DEBUG
//printf("---->Y %d M %d D %d H %d M %d S %d\n", data[0],data[1],data[2],data[3],data[4],data[5]);
      A4GL_debug ("CHECK2 :  d->stime=%d d->ltime=%d", d->stime, d->ltime);
#endif
      return 1;
    }
  else
    {
      return 0;
    }

  return 1;

#ifdef DEBUG
  A4GL_debug ("ctoint\n");
#endif
  return 0;
}



int
A4GL_d_to_dt (void *a, void *b, int size)
{
  int d_y, d_m, d_d;
  static char buff[20];
  A4GL_get_date (*(long *) a, &d_d, &d_m, &d_y);
  SPRINTF3 (buff, "%04d-%02d-%02d", d_y, d_m, d_d);
  return A4GL_ctodt (&buff[0], b, size);

}

int
A4GL_dt_to_d (void *a, void *b, int size)
{
  struct A4GLSQL_dtime d;
  long rval;
  char buff[20];
  int d_y, d_m, d_d;

  // Copy our datetime in..
  if (A4GL_dttodt (a, &d, 0x13) == 0)
    return 0;
  A4GL_dttoc (&d, buff, 14);

  sscanf (buff, "%d-%d-%d", &d_y, &d_m, &d_d);
  rval = A4GL_gen_dateno (d_d, d_m, d_y);
  *(long *) b = rval;

  return 1;

}

/**
 * Copy a date value.
 *
 * @param a The pointer to the date value to be copied.
 * @param b A pointer to the place where to return the value converted.
 * @return 
 *   - 0 : 
 *   - Otherwise
 */
int
A4GL_dttodt (void *a, void *b, int size)
{
  char buff[256];
  struct A4GLSQL_dtime *d;
  d = a;
/*
  if (d->stime >= 1 && d->stime <= 19);
  else
    { 
	A4GL_debug("d->stime=%d\n",d->stime);
      A4GL_assertion (1, "Start Time invalid on datetime (dttodt)");
    }
*/

  if (!(d->ltime >= 1 && d->ltime <= 11))
    {
      A4GL_assertion (1, "End Time invalid on datetime (dttodt)");
    }

#ifdef DEBUG
  A4GL_debug ("dttodt %p %p %d a->stime=%d a->ltime=%d\n", a, b, size, d->stime, d->ltime);
#endif

  if (size == -1)
    {
#ifdef DEBUG
      A4GL_debug ("Mallocing new A4GLSQL_dtime");
#endif
      memcpy (b, a, sizeof (struct A4GLSQL_dtime));
      return 0;
    }



#ifdef DEBUG
  A4GL_debug ("In A4GL_dttodt - calling A4GL_dttoc size=%x ", size);
#endif
  if (A4GL_dttoc (a, buff, 255))
    {
      int rval;
      d = b;
#ifdef DEBUG
      A4GL_debug ("Got buff as : %s - size=%x\n", A4GL_null_as_null (buff), size);
#endif
      d->stime = size / 16;
      d->ltime = size % 16;
      rval = A4GL_ctodt (buff, b, d->stime * 16 + d->ltime);
      return rval;
    }
  return 0;
}

/**
 *
 * @param a A pointer to the value to be converted.
 * @param b A pointer to the buffer where top return the value converted.
 * @param size
 * @return
 *   - 0 : The value passed is an invalid date or datetime.
 *   - 1 : Convertion done.
 */
int
A4GL_ctodt (void *av, void *b, int size)
{
  int data[256];
  struct A4GLSQL_dtime *d;
  int valid;
  char *a;

  a = (char *) av;

#ifdef DEBUG
  A4GL_debug ("ctodt : %s %p %d\n", a, b, size);
  A4GL_debug ("a-->%s\n", A4GL_null_as_null (a));
#endif
  d = (struct A4GLSQL_dtime *) b;

  d->ltime = size % 16;
  d->stime = size >> 4;
#ifdef DEBUG
  A4GL_debug ("d->ltime=%d d->stime=%d\n", d->ltime, d->stime);
#endif
  data[0] = 0;
  data[1] = 0;
  data[2] = 0;
  data[3] = 0;
  data[4] = 0;
  data[5] = 0;
  data[6] = 0;



  valid = A4GL_valid_dt (a, data, size);
#ifdef DEBUG
  A4GL_debug ("valid=%d\n", valid);
#endif

  if (valid == 2 && (d->ltime != d->stime))
    valid = 0;

  if (valid)
    {
#ifdef DEBUG
      A4GL_debug ("Y %d\n", data[0]);
      A4GL_debug ("M %d\n", data[1]);
      A4GL_debug ("D %d\n", data[2]);
      A4GL_debug ("H %d\n", data[3]);
      A4GL_debug ("m %d\n", data[4]);
      A4GL_debug ("S %d\n", data[5]);
      A4GL_debug ("F %d\n", data[6]);
#endif

      SPRINTF7 (d->data, "%04d%02d%02d%02d%02d%02d%05d00000", data[0], data[1], data[2], data[3], data[4], data[5], data[6]);

      return 1;
    }
  else
    {
      //A4GL_assertion(1,"Bibble");
      A4GL_setnull (DTYPE_DTIME, d, size);
      return 1;
    }

  return 1;

}

static int getdt_as_dbl(struct A4GLSQL_dtime *d,double *val) {
	/* SECOND -> anything, or YEAR ->YEAR, MONTH ->MONTH  etc */
	if (d->stime>=6 || d->stime==d->ltime) {
		char buff[200];	
		A4GL_dttoc(d,buff,40);
		return (sscanf(buff,"%lf",val)==1);
	}
	return 0;
}


static int A4GL_dttoi (void *a, void *b, int size) {
  	struct A4GLSQL_dtime *d;
	double val;
	int ok=0;
  	d = a;
	ok=getdt_as_dbl(d,&val);
	if (ok) {
		*(int *)b=(int)val;
		return 1;
	}
	return 0;
}

static int A4GL_dttol (void *a, void *b, int size) {
  	struct A4GLSQL_dtime *d;
	double val;
	int ok=0;
  	d = a;
	ok=getdt_as_dbl(d,&val);
	if (ok) {
		*(long *)b=(long)val;
		return 1;
	}
	return 0;
}

static int A4GL_dttosf (void *a, void *b, int size) {
  	struct A4GLSQL_dtime *d;
	double val;
	int ok=0;
  	d = a;
	ok=getdt_as_dbl(d,&val);
	if (ok) {
		*(float *)b=(float)val;
		return 1;
	}
	return 0;
}

static int A4GL_dttof (void *a, void *b, int size) {
  	struct A4GLSQL_dtime *d;
	double val;
	int ok=0;
  	d = a;
	ok=getdt_as_dbl(d,&val);
	if (ok) {
		*(double *)b=(double)val;
		return 1;
	}
	return 0;
}

/**
 * Convert a date value to ????
 *
 * @param a The value to convert.
 * @param b A pointer to the buffer where to return the value converted.
 * @param size
 * @return
 *   - 0 : The value does not fit in the size.
 *   - 1 : Convertion made.
 */
int
A4GL_dttoc (void *a, void *b, int size)
{
  struct A4GLSQL_dtime *d;
  int cnt;
  char buff[256];
  int x;
  int pos[] = { 0, 4, 6, 8, 10, 12, 14, 15, 16, 17, 18, 19 };
  int sizes[] = { 4, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1 };
  char delim[] = "-- ::.*****";

#ifdef DEBUG
  A4GL_debug ("dttoc : %p %p %x\n", a, b, size);
#endif
  d = a;
  x = 0;

#ifdef DEBUG
  A4GL_debug ("d->stime=%d d->ltime=%d\n", d->stime, d->ltime);
#endif

  if (d->stime >= 1 && d->stime <= 15);
  else
    {
      A4GL_assertion (1, "Start Time invalid on datetime(dttoc)");
    }

  if (d->ltime >= 1 && d->ltime <= 15);
  else
    {
      A4GL_assertion (1, "End Time invalid on datetime");
    }

  for (cnt = d->stime - 1; cnt <= d->ltime - 1; cnt++)
    {
      //debug ("cnt=%d", cnt);
      //debug ("   pos=%d sizes=%d", pos[cnt], sizes[cnt]);
      strncpy (&buff[x], &d->data[pos[cnt]], (size_t) sizes[cnt]);
      x += sizes[cnt];
      if (cnt < d->ltime - 1)
	{
	  if (delim[cnt] != '*')
	    {
	      buff[x++] = delim[cnt];
	    }
	}
      else
	buff[x++] = 0;
    }

  if ((int) strlen (buff) > size)
    {
	int allowtrim=1; /* Trim the precision of the datetime to fit into a smaller character string */
      // Its too small to fit into our string
      char *ptr;
#ifdef DEBUG
      A4GL_debug ("does not fit '%s' %d", A4GL_null_as_null (buff), size);
#endif

	if (allowtrim && d->stime!=1) {
		// We only want to autotrim YEAR TO .... datetimes...
		allowtrim=0;
	}
	
	if (allowtrim && buff[size]>='0' && buff[size]<='9')  {
			char buff2[2000];
			// Still allowed if we're talking about a '.'
			strcpy(buff2,buff);
			buff2[size]=0;
			if (strchr(buff2,'.')) {
				// If we are after the decimal place - allow the trim
				// otherwise its not allowed..
				allowtrim=1;
			} else {
				allowtrim=0;
			}
	}

	if ( allowtrim && size<=1) {
		allowtrim=0;
	}
	if (allowtrim && A4GL_isno(acl_getenv("ALLOWDTIMETRIM"))) {
		allowtrim=0;
	}


	if (allowtrim) {
			// It would be safe to trim at this point - we'd just lose precision...
			buff[size]=0;
			
			if (buff[strlen(buff)-1]=='.') {
				// We're ending with a trailing '.' - 
				// as theres nothing after it - we might as well 
				// get rid of it...
				buff[strlen(buff)-1]=' ';
			}
	}  else {
      		memset (b, '*', size);
      		ptr = b;
      		ptr[size] = 0;
      		return 0;
	}
    }

#ifdef DEBUG
  A4GL_debug ("dttoc sets to '%s'", A4GL_null_as_null (buff));
#endif

  strcpy (b, buff);
  return 1;
}


int
A4GL_dttovc (void *a, void *b, int size)
{
  char buff[256];
  int z;
  memset (buff, ' ', sizeof (buff));
  z = A4GL_dttoc (a, b, size);
  if (z)
    {
      A4GL_trim (b);
      return 1;
    }
  return 0;
}

/* 
 * Copy a blob 
 *
 * @param a A pointer to the blob to be copied.
 * @param b A pointer to the destination blob.
 * @param size
 * @return Allways 1
 */
int
A4GL_btob (void *a, void *b, int size)
{
  struct fgl_int_loc *la;
  struct fgl_int_loc *lb;
  la = (struct fgl_int_loc *) a;
  lb = (struct fgl_int_loc *) b;
  lb->isnull=la->isnull;
  lb->where = la->where;
  lb->f = la->f;
  lb->memsize = la->memsize;
  lb->loc_user_env=la->loc_user_env;
  lb->loc_user_bufsize=la->loc_user_bufsize;
  strcpy (lb->filename, la->filename);
  lb->ptr = la->ptr;
  return 1;
}

/**
 *
 * @param aa
 * @param zi
 * @param sz_ignore
 * @return
 *   - 0 : An error as ocurred.
 *   - 1 : Value copied and converted.
 */
int
A4GL_stoi (void *aa, void *zi, int sz_ignore)
{
  short *z;
  char *a;
  char *eptr;
  int zz;
	long long_val;
  z = (short *) zi;
  a = (char *) aa;
  A4GL_trim (a);
  zz = strlen (a);
  errno = 0;

  long_val =  strtol (a, &eptr, 10);

/*
  if (long_val < SHRT_MIN || long_val > SHRT_MAX)
    {
      A4GL_exitwith ("Value exceeds limit of SMALLINT ");
      return 0;
    }
*/

  *z = (short) long_val;

  if (eptr - a < zz)
    {
#ifdef DEBUG
      A4GL_debug ("Fail check 1 a=%p eptr=%p zz=%d", a, eptr, zz);
#endif
      (void) strtod (a, &eptr);	// We'll ignore any return value...
      if (eptr - a < zz)
	{
	  return 0;
	}
#ifdef DEBUG
      A4GL_debug ("Close shave - its a float..");
#endif
    }


  if (errno != 0 || *eptr != 0 || eptr == a)
    {
      return 0;
    }
  return 1;
}

/**
 *
 * @param aa
 * @param zi
 * @param sz_ignore
 * @return
 *   - 0 : An error as ocurred.
 *   - 1 : Copy and convertion made.
 */
int
A4GL_stol (void *aa, void *zi, int sz_ignore)
{
  char *eptr;
  size_t zz;
  char *a;
  long *z;
  a = (char *) aa;
  z = (long *) zi;
  errno = 0;
  A4GL_trim (a);

#ifdef DEBUG
  A4GL_debug ("Processing %s", A4GL_null_as_null (a));
#endif
  zz = strlen (a);
  *z = strtol (a, &eptr, 10);

  if (eptr - a < zz)
    {
#ifdef DEBUG
      A4GL_debug ("Fail check 1 a=%p eptr=%p zz=%d", a, eptr, zz);
#endif
      strtod (a, &eptr);
      if (eptr - a < zz)
	{
#ifdef DEBUG
	  A4GL_debug ("OK");
#endif
	  return 0;
	}
#ifdef DEBUG
      A4GL_debug ("Close shave - its a float..");
#endif
    }


  if (errno != 0 || eptr[0] != 0 || eptr == a)
    {
#ifdef DEBUG
      A4GL_debug ("Fail check 2 %d %d (%d %d)", errno, eptr[0], eptr, a);
#endif
      return 0;
    }
#ifdef DEBUG
  A4GL_debug ("OK");
#endif
  return 1;
}

/**
 * Copy and convert an integer value to a decimal value.
 *
 * @param a The integer value.
 * @param z A pointer to the place where to put the decimal value.
 * @param size
 * @return
 *   - 0 : The value was invalid.
 *   - 1 : Value converted and copied.
 */
int
A4GL_itodec (void *a, void *z, int size)
{
  fgldecimal *eptr;
  int h;
  int t;
  char buff[256];
  h = size;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;
#ifdef DEBUG
  A4GL_debug ("converting %d to a decimal (%x) %d,%d", A4GL_null_as_null (a), size, h, t);
#endif
  (void) A4GL_init_dec (z, h, t);
  SPRINTF1 (buff, "%016d", *(short *) a);

  eptr = A4GL_str_to_dec (buff, z);

  if (eptr)
    return 1;
  else
    return 0;
}

/**
 * Copy and convert a long value to a decimal value.
 *
 * @param a The long value.
 * @param z A pointer to the p�ace where to put the converted decimal value.
 * @param size
 * @return
 *   - 0 : An error as ocurred.
 *   - 1 : Convertion made.
 */
int
A4GL_ltodec (void *a, void *z, int size)
{
  fgldecimal *eptr;
  int h;
  int t;
  char buff[256];
  h = size;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;

#ifdef DEBUG
  A4GL_debug ("Size=%d - 0x%x\n", size, size);
  A4GL_debug ("a=%p %d", a, *(long *) a);
  A4GL_debug ("converting %d to a decimal (%x) %d,%d", *(long *) a, size, h, t);
#endif

  (void) A4GL_init_dec (z, h, t);
  SPRINTF1 (buff, "%ld", *(long *) a);
#ifdef DEBUG
  A4GL_debug ("Buff=%s\n", A4GL_null_as_null (buff));
#endif
  eptr = A4GL_str_to_dec (buff, z);
  //A4GL_debug ("eptr=%p\n", eptr);

  if (eptr)
    return 1;
  else
    return 0;
}

/**
 * Convert a C-double value to decimal.
 *
 * @param a The double value.
 * @param z A pointer to the place where to put the decimal value.
 * @param size
 * @return
 *   - 0 : Invalid value or error ocurred.
 *   - 1 : Value converted.
 */
int
A4GL_ftodec (void *a, void *z, int size)
{
  fgldecimal *eptr;
  int h;
  int t;
  double da;
  char buff[650];
  char fmt[200];
  char *ptr;
  h = size & 0xffff;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;
  da = *(double *) a;
#ifdef DEBUG
  A4GL_debug ("converting %18.18lf to a decimal (%x) %d,%d", da, size, h, t);
#endif
  (void) A4GL_init_dec (z, h, t);
#ifdef DEBUG
  A4GL_debug ("ftodec... %lf", *(double *) a);
#endif
  if (t >= 0)
    {



      if (A4GL_isyes (acl_getenv ("DBL2DEC_USING")))
	{
	  ptr = A4GL_make_using_tostring ("", h, t);
	  strcpy (fmt, ptr);
	  ptr = acl_malloc2 (strlen (fmt) + 10);
	  a4gl_using (ptr, strlen (fmt), fmt, da);
	  strcpy (buff, ptr);
	  A4GL_decstr_convert (buff, a4gl_convfmts.using_decfmt, a4gl_convfmts.posix_decfmt, 0, 0, -1);
	  free (ptr);
	}
      else
	{
	  //set format to the number of digits needed, to force round-off
	  if (A4GL_isyes (acl_getenv ("INFORMIX_ROUNDING")))
	    {
	      SPRINTF1 (fmt, "%%-32.%df", t);
	    }
	  else
	    {
	      SPRINTF1 (fmt, "%%-32.%df", t + 1);
	    }
#ifdef DEBUG
	  A4GL_debug ("Format=%s", A4GL_null_as_null (fmt));
#endif
	  SPRINTF1 (buff, fmt, *(double *) a);
	  A4GL_decstr_convert (buff, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 0, -1);
	}
    }
  else
    {
      strcpy (fmt, "%-32.1f");
      SPRINTF1 (buff, fmt, *(double *) a);
      A4GL_decstr_convert (buff, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 0, -1);
    }
#ifdef DEBUG
  A4GL_debug ("buff=%s", A4GL_null_as_null (buff));
#endif

  eptr = A4GL_str_to_dec (buff, z);

  ptr = A4GL_dec_to_str (z, 0);
#ifdef DEBUG
  A4GL_debug ("---> %s\n", ptr);
#endif
  if (eptr)
    return 1;
  else
    return 0;
}


/**
 * Convert a smallfloat to dec.
 *
 * @param a The smallfloat value.
 * @param z A pointer to the place where to put the decimal value.
 * @param size
 * @return
 *   - 0 : An error as ocurred.
 *   - 1 : Convertion made.
 */
int
A4GL_sftodec (void *a, void *z, int size)
{
  fgldecimal *eptr;
  int h;
  int t;
  char buff[256];
  h = size;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;
#ifdef DEBUG
  A4GL_debug ("converting %s to a decimal (%x) %d,%d", A4GL_null_as_null (a), size, h, t);
#endif
  (void) A4GL_init_dec (z, h, t);
  SPRINTF1 (buff, "%32.16f", *(float *) a);
  A4GL_decstr_convert (buff, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 0, 32);
  eptr = A4GL_str_to_dec (buff, z);

  if (eptr)
    return 1;
  else
    return 0;

}

/**
 * Copy a decimal value.
 *
 * @param a
 * @param z
 * @param size
 * @return
 *   - 0 : The value is not valid.
 *   - 1 : _Convertion made.
 */
int
A4GL_dectodec (void *a, void *z, int size)
{
  fgldecimal *eptr;
  int h;
  int t;
  char *buff;
  h = size;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;
  //A4GL_debug ("converting %s to a decimal (%x) %d,%d", A4GL_null_as_null(a), size, h, t);
  (void) A4GL_init_dec (z, h, t);
  buff = A4GL_dec_to_str (a, 0);
  eptr = A4GL_str_to_dec (buff, z);

  if (eptr)
    return 1;
  else
    return 0;
}

/**
 * Convert a string value to decimal
 *
 * @param a The string to be converted.
 * @param z A pointer where to return the decimal value.
 * @param size
 * @return
 *   - 0 : Invalid value or error ocurred.
 *   - 1 : Convertion made.
 */
int
A4GL_stodec (void *a, void *z, int size)
{
  char buff[1024];
  fgldecimal *eptr;
  int h;
  int t;
  h = size;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;


if (!A4GL_isno(acl_getenv("NEWDECSTRCONV"))) {
	if (a && strlen(a)) {
		A4GL_decstr_convert(a,a4gl_convfmts.ui_decfmt,a4gl_convfmts.posix_decfmt,0,1, -1);
		if (strlen(a)==0) { return 0; }
  		(void) A4GL_init_dec (z, h, t);
  		eptr = A4GL_str_to_dec (a, z);
		return 1;
	}
} else {

  if (a)
    {
      char *ptr;
      int dot = -1;
      int comma = -1;
      int cnt;
      ptr = a;
      for (cnt = 0; cnt < strlen (ptr); cnt++)
	{
	  if (ptr[cnt] == ',' && comma == -1)
	    comma = cnt;
	  if (ptr[cnt] == '.' && dot == -1)
	    dot = cnt;
	}

#ifdef DEBUG
      A4GL_debug ("Starting with : %s", a);
#endif
      if ((a4gl_convfmts.ui_decfmt.thsep == ',' || a4gl_convfmts.ui_decfmt.thsep == 0) && comma >= 0)
	{
	  if (dot == -1 || dot > comma)
	    {
	      int c = 0;
	      // remove comma separators...
	      for (cnt = 0; cnt < strlen (ptr); cnt++)
		{
		  if (ptr[cnt] == ',')
		    continue;
		  buff[c++] = ptr[cnt];
		}
	      buff[c] = 0;
	      a = buff;
	    }
	}
      if (a4gl_convfmts.ui_decfmt.thsep == '.' && dot >= 0)
	{
	  if (comma == -1 || comma > dot)
	    {
	      int c = 0;
	      // remove dot thousand separators...
	      for (cnt = 0; cnt < strlen (ptr); cnt++)
		{
		  if (ptr[cnt] == '.')
		    continue;
		  buff[c++] = ptr[cnt];
		}
	      buff[c] = 0;
	      a = buff;
	    }
	}

    }
}



#ifdef DEBUG
  A4GL_debug ("converting '%s' to a decimal (%x) %d,%d", A4GL_null_as_null (a), size, h, t);
#endif
  (void) A4GL_init_dec (z, h, t);

#ifdef DEBUG
  A4GL_debug ("After init\n");
#endif
  eptr = A4GL_str_to_dec (a, z);
#ifdef DEBUG
  A4GL_debug ("z111");
#endif


  if (A4GL_isno (acl_getenv ("TRYDECSTRINGTWICE")))
    {
      if (eptr)
	{
#ifdef DEBUG
	  A4GL_debug ("eptr...");
#endif
	  return 1;
	}
    }
  else
    {

      if (!A4GL_conversion_ok (-1))
	{
	  eptr = 0;
	}
      else
	{
	  if (eptr)
	    {
#ifdef DEBUG
	      A4GL_debug ("eptr...");
#endif
	      return 1;
	    }
	}
#ifdef DEBUG
      A4GL_debug ("Didn't work... '%c' '%c'\n", a4gl_convfmts.printf_decfmt.decsep, a4gl_convfmts.posix_decfmt.decsep);
#endif
      if (a4gl_convfmts.printf_decfmt.decsep != a4gl_convfmts.posix_decfmt.decsep)
	{
	  char buff[2000];
	  strcpy (buff, a);
	  A4GL_decstr_convert (buff, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 0, 32);
	  eptr = A4GL_str_to_dec (buff, z);
	  if (eptr)
	    {
	      return 1;
	    }
	}


    }
  return 0;
}




#ifdef NOTUSED
char *
get_money_as_string (fgldecimal * fgldec)
{
  int has_neg = 0;
  static char buff[200];
  int a;
  char *offbuff;
  int size;

  //A4GL_debug ("Calling make_using.. ");
  //strcpy (buff_14, "-");

  if (fgldec->dec_data[0] & 128)
    {
      has_neg = 1;
      size = (fgldec->dec_data[0] - 128) * 256 + fgldec->dec_data[1];
      offbuff = A4GL_make_using_tostring (fgldec, (size >> 8) + 1, size & 255);
    }
  else
    {
      size = fgldec->dec_data[0] * 256 + fgldec->dec_data[1];
      offbuff = A4GL_make_using_tostring (fgldec, size >> 8, size & 255);
    }
  strcpy (buff, offbuff);

  for (a = 0; a < strlen (buff); a++)
    {
      if (buff[a] == '-')
	{
	  buff[a] = '$';
	}
    }

  if (has_neg)
    {
      for (a = strlen (buff) - 1; a >= 0; a--)
	{
	  if (buff[a] == '$')
	    {
	      buff[a] = '-';
	    }
	}
    }
  return buff;
}
#endif

/**
 * Convert a decimal to string.
 *
 * @param z The decimal value to be copied and converted.
 * @param w A pointer to the place where to put the sting converted.
 * @param size
 * @return Allways 1
 */
int
A4GL_mdectos (void *z, void *w, int size)
{
  char *buff;
  char buff2[200];
  char buff3[200];

  buff = A4GL_dec_to_str (z, size);

#ifdef DEBUG
  A4GL_debug ("mdec_to_str -> '%s'\n", A4GL_null_as_null (buff));
#endif

  strcpy (buff2, buff);
  A4GL_ltrim (buff2);
  if (strlen (buff2) < size)
    {
      SPRINTF1 (buff3, "$%s", buff2);
      strcpy (buff2, buff3);
    }

  A4GL_string_set (w, buff2, size);
#ifdef DEBUG
  A4GL_debug ("w = %s\n", A4GL_null_as_null (w));
#endif


  return 1;
}

static void
prepend_0_if_required (char *ptr)
{
  static char buff[200];
  //static char ptr[256];
  strcpy (buff, ptr);
  if (ptr[0] == '.')
    {
      strcpy (buff, "0");
      strcat (buff, ptr);
    }
  if (ptr[0] == '-' && ptr[1] == '.')
    {
      strcpy (buff, "-0");
      strcat (buff, &ptr[1]);
    }
  A4GL_trim(buff);
  strcpy (ptr, buff);
}


/**
 * Convert a decimal value to long.
 *
 * @param zz The decimal value.
 * @param aa The long value.
 * @param sz_ignore Not used.
 * @return 
 *   - 0 : Value invalid or error.
 *   - 1 : Value converted.
 */
int
A4GL_mdectol (void *zz, void *aa, int sz_ignore)
{
  char buff[65];
  long *a;
  fgldecimal *z;
#ifdef DEBUG
  A4GL_debug ("mdectol");
#endif
  a = (long *) aa;
  z = (fgldecimal *) zz;
  strcpy (buff, A4GL_dec_to_str (z, 0));
  if (A4GL_apm_str_detect_overflow (buff, 0, 0, DTYPE_INT))
    {
      A4GL_setnull (DTYPE_INT, a, 0);
      return 1;
    }
  else
    {
      char *ptr;
      prepend_0_if_required (buff);
      ptr = strchr (buff, a4gl_convfmts.scanf_decfmt.decsep);
      if (ptr)
	*ptr = 0;
      ptr = strchr (buff, a4gl_convfmts.posix_decfmt.decsep);
      if (ptr)
	*ptr = 0;
      return A4GL_stol (buff, a, 0);
    }
}

/**
 * Convert a decimal value to integer.
 *
 * @param zz The decimal value.
 * @param aa A pointer where to return the integer value.
 * @param sz_ignore Not used.
 * @return 
 *   - 0 : Value invalid or error.
 *   - 1 : Value converted.
 */
int
A4GL_mdectoi (void *zz, void *aa, int sz_ignore)
{
  char buff[65];
  short *a;
  fgldecimal *z;
#ifdef DEBUG
  A4GL_debug ("mdectoi");
#endif
  a = (short *) aa;
  z = (fgldecimal *) zz;
  strcpy (buff, A4GL_dec_to_str (z, 0));
  return A4GL_stoi (buff, a, 0);
}

/**
 * Convert a decimal value to date
 *
 * @param zz The decimal value.
 * @param aa A pointer where to return the date value.
 * @param sz_ignore Not used.
 * @return 
 *   - 0 : Value invalid or error.
 *   - 1 : Value converted.
 */
int
A4GL_mdectod (void *zz, void *aa, int sz_ignore)
{
  char buff[65];
  long *a;
  fgldecimal *z;
  a = (long *) aa;
  z = (fgldecimal *) zz;
  strcpy (buff, A4GL_dec_to_str (z, 0));
  return A4GL_stol (buff, a, 0);
}

/**
 * Convert a decimal value to float.
 *
 * @param zz The decimal value.
 * @param aa A pointer where to return the decimal value.
 * @param sz_ignore Not used.
 * @return
 *   - 0 : Value invalid or error.
 *   - 1 : Value converted.
 */
int
A4GL_mdectof (void *zz, void *aa, int sz_ignore)
{
  char buff[65];
  fgldecimal *z;
  double *a;
  a = (double *) aa;
  z = (fgldecimal *) zz;

  strcpy (buff, A4GL_dec_to_str (z, 0));
  return A4GL_stof (buff, a, 0);
}

/**
 * Convert a decimal value to small float.
 *
 * @param zz The decimal value.
 * @param aa A pointer where to return the small float value.
 * @param sz_ignore Not used.
 * @return
 *   - 0 : Value invalid or error.
 *   - 1 : Value converted.
 */
int
A4GL_mdectosf (void *zz, void *aa, int sz_ignore)
{
  char buff[65];
  fgldecimal *z;
  float *a;
  z = (fgldecimal *) zz;
  a = (float *) aa;
  strcpy (buff, A4GL_dec_to_str (z, 0));
  return A4GL_stosf (buff, a, 0);
}


/**
 * Convert a decimal value to string.
 *
 * @param z The decimal value.
 * @param w A pointer where to return the string value.
 * @param size
 * @return
 *   - 0 : Value invalid or error.
 *   - 1 : Value converted.
 */
int
A4GL_dectos (void *z, void *w, int size)
{
  char *buff;
  char buff2[200];
  buff = A4GL_dec_to_str (z, size);
#ifdef DEBUG
  A4GL_debug ("dec_to_str -> '%s'\n", A4GL_null_as_null (buff));
#endif
  strcpy (buff2, buff);
  A4GL_ltrim (buff2);
  A4GL_string_set (w, buff2, size);
#ifdef DEBUG
  A4GL_debug ("w = %s\n", A4GL_null_as_null (w));
#endif
  return 1;

}

/**
 * Convert a string value to float.
 *
 * @param zz The double value.
 * @param aa A pointer where to the string value.
 * @param sz_ignore Not used.
 * @return
 *   - 0 : Value invalid or error.
 *   - 1 : Value converted.
 */
int
A4GL_stof (void *aa, void *zz, int sz_ignore)
{
  char *a;
  int ok;
  double b;
  char *eptr;

  a = A4GL_decstr_convert ((char *) aa, a4gl_convfmts.ui_decfmt, a4gl_convfmts.scanf_decfmt, 1, 1, -1);
  ok = (sscanf (a, "%lf", (double *) zz) == 1);
#ifdef DEBUG
  A4GL_debug ("stof: %s->%16.16lf; OK=%d", A4GL_null_as_null (a), *(double *) zz, ok);
#endif

  if (!ok && !A4GL_isno (acl_getenv ("ALLOWDBLCRUD")))
    {
      b = strtod ((char *) aa, &eptr);
      if (eptr != aa)
	{
	  *(double *) zz = b;
	  ok = 1;
	}
      else
	{
	  ok = 1;
	  *(double *) zz = 0;
	}
    }


  free (a);
  return ok;
}

/**
 * Convert a string value to small float.
 *
 * @param zz The decimal value.
 * @param aa A pointer where to return the small float value.
 * @param sz_ignore Not used.
 * @return 
 *   - 0 : Value invalid or error.
 *   - 1 : Value converted.
 */
int
A4GL_stosf (void *aa, void *zz, int sz_ignore)
{
  char *a;
  int ok;

  a = A4GL_decstr_convert ((char *) aa, a4gl_convfmts.ui_decfmt, a4gl_convfmts.scanf_decfmt, 1, 1, -1);
  ok = (sscanf (a, "%f", (float *) zz) == 1);
#ifdef DEBUG
  A4GL_debug ("stosf: %s->%f; OK=%d", A4GL_null_as_null (a), *(float *) zz, ok);
#endif
  if (ok == 0)
    {
      ok = 1;
      *(float *) zz = 0;
    }
  free (a);
  return ok;
}

/**
 * Convert a decimal value to long.
 *
 * @param zz The decimal value.
 * @param aa A pointer where to return the long value.
 * @param sz_ignore Not used.
 * @return
 *   - 0 : Value invalid or error.
 *   - 1 : Value converted.
 */
int
A4GL_dectol (void *zz, void *aa, int sz_ignore)
{
  static char buff_dectol[65];
  long *a;
  char *z;
  int rval;
#ifdef DEBUG
  A4GL_debug ("dectol");
#endif
  a = (long *) aa;
  z = (char *) zz;
#ifdef DEBUG
  A4GL_debug ("dectol");
#endif
  A4GL_dectos (z, buff_dectol, 64);
  if (A4GL_apm_str_detect_overflow (buff_dectol, 0, 0, DTYPE_INT))
    {
      A4GL_setnull (DTYPE_INT, a, 0);
      rval = 1;
    }
  else
    {
      char *ptr;
      prepend_0_if_required (buff_dectol);
      ptr = strchr (buff_dectol, a4gl_convfmts.scanf_decfmt.decsep);
      if (ptr)
	*ptr = 0;
      ptr = strchr (buff_dectol, a4gl_convfmts.posix_decfmt.decsep);
      if (ptr)
	*ptr = 0;
      rval = A4GL_stol (buff_dectol, a, 0);
    }
#ifdef DEBUG
  A4GL_debug ("rval=%d", rval);
#endif
  return rval;
}

/**
 * Convert a decimal value to integer.
 *
 * @param zz The decimal value.
 * @param aa A pointer where to return the integer value.
 * @param sz_ignore Not used.
 * @return
 *   - 0 : Value invalid or error.
 *   - 1 : Value converted.
 */
int
A4GL_dectoi (void *zz, void *aa, int sz_ignore)
{
  static char buff_dectoi[65];
  short *a;
  char *z;
  int rval;
#ifdef DEBUG
  A4GL_debug ("dectoi");
#endif
  a = (short *) aa;
  z = (char *) zz;
  A4GL_dectos (z, buff_dectoi, 64);
#ifdef DEBUG
  A4GL_debug ("--> %s\n", A4GL_null_as_null (buff_dectoi));
#endif

  if (A4GL_apm_str_detect_overflow (buff_dectoi, 0, 0, DTYPE_SMINT))
    {
#ifdef DEBUG
      A4GL_debug ("Overflow");
#endif
      A4GL_setnull (DTYPE_SMINT, a, 0);
      rval = 1;
    }
  else
    {
      char *ptr;
      prepend_0_if_required (buff_dectoi);
      ptr = strchr (buff_dectoi, a4gl_convfmts.scanf_decfmt.decsep);
      if (ptr)
	*ptr = 0;
      ptr = strchr (buff_dectoi, a4gl_convfmts.posix_decfmt.decsep);
      if (ptr)
	*ptr = 0;
      rval = A4GL_stoi (buff_dectoi, a, 0);
    }

  return rval;
}

/**
 * Convert a decimal value to long.
 *
 * @param zz The decimal value.
 * @param aa A pointer where to return the long value.
 * @param sz_ignore Not used.
 * @return
 *   - 0 : Value invalid or error.
 *   - 1 : Value converted.
 */
int
A4GL_dectod (void *zz, void *aa, int sz_ignore)
{
  char buff_dectod[65];
  long *a;
  char *z;
  a = (long *) aa;
  z = (char *) zz;
  A4GL_dectos (z, buff_dectod, 64);
  return A4GL_stol (buff_dectod, a, 0);
}

/**
 * Convert a decimal value to float.
 *
 * @param zz The decimal value.
 * @param aa A pointer where to return the float value.
 * @param sz_ignore Not used.
 * @return
 *   - 0 : Value invalid or error.
 *   - 1 : Value converted.
 */
int
A4GL_dectof (void *zz, void *aa, int sz_ignore)
{
  char buff[128];
  char *z;
  double *a;
  a = (double *) aa;
  z = (char *) zz;

  A4GL_dectos (z, buff, 64);
  return A4GL_stof (buff, a, 0);
}

/**
 * Convert a decimal value to small float.
 *
 * @param zz The decimal value.
 * @param aa A pointer where to return the small float value.
 * @param sz_ignore Not used.
 * @return 
 *   - 0 : Value invalid or error.
 *   - 1 : Value converted.
 */
int
A4GL_dectosf (void *zz, void *aa, int sz_ignore)
{
  char buff[65];
  char *z;
  float *a;
  z = (char *) zz;
  a = (float *) aa;
  A4GL_dectos (z, buff, 64);
  return A4GL_stosf (buff, a, 0);
}

/**
 * Convert a date to smallfloat.
 *
 * @param zz The decimal value.
 * @param aa A pointer where to return the smallfloat value.
 * @param sz_ignore Not used.
 * @return Allways 1
 */
int
A4GL_dtosf (void *aa, void *zz, int sz_ignore)
{
  int *a;
  float *z;
  a = (int *) aa;
  z = (float *) zz;
  *z = *a;
  return 1;
}

/**
 * Convert a date value to float.
 *
 * @param zz The date value.
 * @param aa A pointer where to return the float value.
 * @param sz_ignore Not used.
 * @return  Allways 1
 */
int
A4GL_dtof (void *aa, void *zz, int sz_ignore)
{
  int *a;
  double *z;
  a = (int *) aa;
  z = (double *) zz;
#ifdef DEBUG
  A4GL_debug ("dtof");
#endif
  *z = *a;
  return 1;
}

/**
 * Convert a date value to long.
 *
 * @param zz The date value.
 * @param aa A pointer where to return the float value.
 * @param sz_ignore Not used.
 * @return  Allways 1
 */
int
A4GL_dtol (void *aa, void *zz, int sz_ignore)
{
  int *a;
  long *z;
  a = (int *) aa;
  z = (long *) zz;
  *z = *a;
  return 1;
}

/**
 * Convert a date value to int.
 *
 * @param zz The date value.
 * @param aa A pointer where to return the int value.
 * @param sz_ignore Not used.
 * @return  Allways 1
 */
int
A4GL_dtoi (void *aa, void *zz, int sz_ignore)
{
  int *a;
  short *z;
  a = (int *) aa;
  z = (short *) zz;
  *z = *a;
  return 1;
}

/**
 * Convert a long value to date.
 *
 * @param zz The long value.
 * @param aa A pointer where to return the date value.
 * @param sz_ignore Not used.
 * @return  Allways 1
 */
int
A4GL_ltod (void *aa, void *zz, int sz_ignore)
{
  long *a;
  int *z;
  a = (long *) aa;
  z = (int *) zz;
  *z = *a;
  return 1;
}

/**
 * Convert a integer value to date.
 *
 * @param zz The integer value.
 * @param aa A pointer where to return the date value.
 * @param sz_ignore Not used.
 * @return  Allways 1
 */
int
A4GL_itod (void *aa, void *zz, int sz_ignore)
{
  short *a;
  int *z;
  a = (short *) aa;
  z = (int *) zz;
  *z = *a;
  return 1;
}

/**
 * Convert a small float value to date.
 *
 * @param zz The small float value.
 * @param aa A pointer where to return the date value.
 * @param sz_ignore Not used.
 * @return  Allways 1
 */
int
A4GL_sftod (void *aa, void *zz, int sz_ignore)
{
  float *a;
  int *z;
  a = (float *) aa;
  z = (int *) zz;
  *z = *a;
  return 1;
}


/**
 * Convert a float value to date.
 *
 * @param zz The float value.
 * @param aa A pointer where to return the date value.
 * @param sz_ignore Not used.
 * @return  Allways 1
 */
int
A4GL_ftod (void *aa, void *zz, int sz_ignore)
{
  double *a;
  int *z;
  a = (double *) aa;
  z = (int *) zz;
#ifdef DEBUG
  A4GL_debug ("ftod");
#endif
  *z = *a;
  return 1;
}


/**
 * stod() - converts a string to an internal date type.
 *
 * Uses DBDATE format info but does not assume the string is well
 * formed, making it suitable for conversion of user data input.
 *
 * @ param str The string value
 * @ param str A pointer where to return the date value
 * @ param sz_ignore Not used
 * @return
 *   - 0 :  There was a conversion error
 *   - 1 :  Conversion done.
 */
int
A4GL_stod (void *str_v, void *date_v, int sz_ignore)
{
  static char dbdate[40] = "";	// holds current DBDATE value
  static int d_pos, m_pos, y_pos;	// relative positions of day/month/year
  char num[3][10];		// date numbers extracted from string
  char *p;
  int n;
  char *str;
  int *date;
  char c[5];
  int d;
  int y;
  str = (char *) str_v;
  date = (int *) date_v;
  n = sscanf (str, "%c%c%c. %d,%d", &c[0], &c[1], &c[2], &d, &y);
  if (n == 5)
    {				// Oddball date format..
      int a;
      c[3] = 0;
      for (a = 1; a <= 12; a++)
	{
	  int m;
	  if (A4GL_aubit_strcasecmp (c, (char *) A4GL_find_str_resource_int ("_MON", a)) == 0)
	    {
	      m = a;
	      y = A4GL_modify_year (y);

	      *date = A4GL_gen_dateno (d, m, y);

	      if (*date == DATE_INVALID)
		{
		  return 0;
		}
	      else
		{
		  return 1;
		}
	    }
	}
    }

//A4GL_debug("STOD : %s %d",str_v,*date);
  // set date format from (A4GL_)DBDATE, or use Informix default "mdy4".
  // we only need to do this once, the first time stod() is called.
  // note - for this conversion we need only the three letters DMY
  // in their correct sequence, which we put into variables d/m/y_pos
  if (dbdate[0] == '\0')
    {
      char dmy[4] = "";
      strncpy (dbdate, A4GL_get_dbdate (), 10);
      for (p = dbdate; (*p > '\0') && (strlen (dmy) < 3); p++)
	{
	  if (a4gl_isalpha (*p))
	    {
	      *p = toupper (*p);
	      strncat (dmy, p, 1);
	    }
	}
      // store the positions (0-2) in dmy string of characters D,M,Y
      d_pos = strcspn (dmy, "D");
      m_pos = strcspn (dmy, "M");
      y_pos = strcspn (dmy, "Y");
      // each of these must be different and in the range 0-2
      if ((d_pos + m_pos + y_pos) != 3 || d_pos == m_pos || d_pos == y_pos || m_pos == y_pos)
	{
	  // we have an invalid dbdate format - die ...
	  A4GL_set_errm (dbdate);
	  A4GL_exitwith ("conv.c - Invalid DBDATE format: %s");
	  return 0;
	}
    }				// end of dbdate initialization

  // first scan the string and extract contiguous sequences
  // of digits, up to three of them ( for day/month/year )
  num[0][0] = '\0';
  num[1][0] = '\0';
  num[2][0] = '\0';
  n = 0;
  for (p = str; (*p > '\0') && (n < 3); p++)
    {
      if (isdigit (*p))
	{
	  strncat (num[n], p, 1);
	  if (strlen (num[n]) > 8)
	    {
	      n++;
	    }
	}
      else
	{
	  if (num[n][0] > '\0')
	    {
	      n++;
	    }
	}
    }

  // a single sequence of 6 digits is treated as three 2-digit numbers
  if (strlen (num[0]) == 6)
    {
      strncpy (num[1], &num[0][2], 2);
      strncpy (num[2], &num[0][4], 2);
      num[0][2] = '\0';
      num[1][2] = '\0';
      num[2][2] = '\0';
    }
  else
    {
      if (strlen (num[0]) == 8)
	{
	  // a single sequence of 8 digits is treated as two 2-digit numbers
	  // and one 4-digit year (which four depends on DBDATE)
	  switch (y_pos)
	    {
	    case 0:		// year is the first number
	      strncpy (num[1], &num[0][4], 2);
	      num[1][2] = '\0';
	      strncpy (num[2], &num[0][6], 2);
	      num[2][2] = '\0';
	      num[0][4] = '\0';
	      break;
	    case 1:		// year is in the middle (v. unlikely)
	      strncpy (num[1], &num[0][2], 4);
	      num[1][4] = '\0';
	      strncpy (num[2], &num[0][6], 2);
	      num[2][2] = '\0';
	      num[0][2] = '\0';
	      break;
	    default:		// year is at the end, the usual case
	      strncpy (num[1], &num[0][2], 2);
	      num[1][2] = '\0';
	      strncpy (num[2], &num[0][4], 4);
	      num[2][4] = '\0';
	      num[0][2] = '\0';
	      break;
	    }
	}
      else
	{
	  // otherwise, we expect exactly three separate numbers
	  if (!isdigit (num[2][0]))
	    {
	      *date = DATE_INVALID;
	      return 0;
	    }
	}
    }

  // convert d/m/y strings to integer, and then convert to informix-style
  // internal date number  - but first check year for y2k conversion

  if (strlen (num[y_pos]) < 4)
    {
      n = A4GL_modify_year (atoi (num[y_pos]));
    }
  else
    {
      n = atoi (num[y_pos]);
    }

  *date = A4GL_gen_dateno (atoi (num[d_pos]), atoi (num[m_pos]), n);

  if (*date == DATE_INVALID)
    {
      return 0;
    }

  return 1;
  //return ((*date = A4GL_gen_dateno (atoi (num[d_pos]), atoi (num[m_pos]), n)) != DATE_INVALID);
}


/**
 * Convert a date to ???
 *
 * @param zz The date value value.
 * @param aa A pointer where to return the value.
 * @param sz_ignore Not used.
 * @return
 *   - 0 : There was a convertion error
 *   - 1 : Convertion made.
 */
int
A4GL_dtovc (void *aa, void *zz, int sz_ignore)
{
  int *a;
  char *z;
  a = (int *) aa;
  z = (char *) zz;
  if (A4GL_dtos (a, z, 6))
    {
      A4GL_trim (z);
      return 1;
    }
  return 0;
}


/**
 * Convert a date to  string, using the current DBDATE format setting.
 *
 * @param aa The date value value.
 * @param zz A pointer where to return the value.
 * @param size The size of the string buffer where to put the converted value.
 * @return
 *   - 0 : There was a conversion error
 *   - 1 : Conversion made.
 */
int
A4GL_dtos (void *aa, void *zz, int size)
{
  long *a;
  char *z;
  char *p;

  z = (char *) zz;
  a = (long *) aa;
  A4GL_assertion (a == 0, "No date pointer");
  A4GL_assertion (z == 0, "No string pointer");
  //memset(z,0,size-1);
  //z[size-1]=0;
#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("dtos date=%d %x", *a, *a);
  }
#endif


  /* without a format string, using_date() will refer to DBDATE */
  p = A4GL_using_date (*a, "");

  if (size < strlen (p))
    {
#ifdef DEBUG
      /* {DEBUG} */
      {
	A4GL_debug ("Size too small, %d", size);
      }
#endif
      memset (z, '*', size);
      z[size] = 0;
      return 0;
    }
  strncpy (z, p, size);
  z[size] = 0;
  A4GL_pad_string (z, size);

#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Date = %s\n", A4GL_null_as_null (z));
  }
#endif
  return 1;
}

/**
 * Convert an integer to ???
 *
 * @param aa The integer value.
 * @param zz A pointer to the place where to return the value.
 * @param size
 * @return
 *   - 0 : There was a convertion error
 *   - 1 : Convertion made.
 */
int
A4GL_itoc (void *aa, void *zz, int size)
{
  char fmt[10] = "d";
  short local_a;
  int local_a_int;
  char *z;
  char *buff;
  local_a = *(short *) aa;
  local_a_int = local_a;
  z = (char *) zz;

  if (size > 10)
    {
      SPRINTF1 (z, "%d", local_a_int);
      A4GL_pad_string (z, size);
      return 1;
    }

  buff = malloc (size + 20);
  if (A4GL_digittoc (&local_a_int, z, fmt, DTYPE_SMINT, size))
    {
#ifdef DEBUG
      {
	A4GL_debug ("itoc return from A4GL_digittoc using %s", A4GL_null_as_null (fmt));
      }
#endif
      SPRINTF1 (buff, fmt, local_a_int);
    }
  if (strlen (buff) > size)
    {
      memset (z, '*', size);
      z[size] = 0;
    }
  else
    {
      strcpy (z, buff);
    }
  free (buff);

  return 1;
}

/**
 * Convert an integer to long
 *
 * @param aa The integer value.
 * @param zz A pointer to the place where to return the value.
 * @param sz_ignore Not used.
 * @return
 *   - 0 : There was a convertion error
 *   - 1 : Convertion made.
 */
int
A4GL_itol (void *aa, void *zz, int sz_ignore)
{
  short *a;
  long *z;
  z = (long *) zz;
  a = (short *) aa;
  *z = (long) *a;

  return 1;
}

/**
 * Convert an integer to float
 *
 * @param aa The integer value.
 * @param zz A pointer to the place where to return the value.
 * @param sz_ignore Not used.
 * @return Allways 1
 */
int
A4GL_itof (void *aa, void *zz, int sz_ignore)
{
  short *a;
  double *z;
  z = (double *) zz;
  a = (short *) aa;
  *z = (double) *a;
  return 1;
}

/**
 * Convert an integer to small float
 *
 * @param aa The integer value.
 * @param zz A pointer to the place where to return the value.
 * @param sz_ignore Not used.
 * @return Allways 1
 */
int
A4GL_itosf (void *aa, void *zz, int sz_ignore)
{
  short *a;
  float *z;
  z = (float *) zz;
  a = (short *) aa;
  *z = (float) *a;
  return 1;
}

/**
 * Convert an integer to ???
 *
 * @param aa The integer value.
 * @param zz A pointer to the place where to return the value.
 * @param c The size
 * @return Allways 1
 */
int
A4GL_itovc (void *aa, void *zz, int c)
{
  short *a;
  char *z;
  z = (char *) zz;
  a = (short *) aa;

  if (A4GL_itoc (a, z, c))
    {
      A4GL_trim (z);
      return 1;
    }
  else
    {
      return 0;
    }
}


/**
 * Convert a long value to
 *
 * @param aa The integer value.
 * @param zz A pointer to the place where to return the value.
 * @param size
 * @return Allways 1
 */
int
A4GL_ltoc (void *aa, void *zz, int size)
{
  long *a;
  char *z;
  char fmt[10] = "ld";
  char *buff;
  z = (char *) zz;
  a = (long *) aa;

  buff = malloc (size + 10);

#ifdef DEBUG
  {
    A4GL_debug ("Size=%d", size);
  }
#endif
  if (A4GL_digittoc ((int *) a, z, fmt, DTYPE_INT, size))
    {
#ifdef DEBUG
      {
	A4GL_debug ("ltoc return from A4GL_digittoc using %s", A4GL_null_as_null (fmt));
      }
#endif
      SPRINTF1 (buff, fmt, *(long *) a);
      if (strlen (buff) > size)
	{
	  memset (buff, '*', size);
	  buff[size] = 0;
	}
      strcpy (z, buff);
      A4GL_pad_string (z, size);
    }
  free (buff);
  return 1;
}

/**
 * Convert a long value to integer.
 *
 * @param aa The long value.
 * @param zz A pointer to the place where to return the value.
 * @param sz_ignore Not used.
 * @return Allways 1
 */
int
A4GL_ltoi (void *aa, void *zz, int sz_ignore)
{
  long *a;
  short *z;
  a = (long *) aa;
  z = (short *) zz;
#ifdef DEBUG
  {
    A4GL_debug ("Ltoi");
  }
#endif
#ifndef SHRT_MIN
#define SHRT_MIN -32000
#define SHRT_MAX 32000
#endif
  if (*a < SHRT_MIN || *a > SHRT_MAX)
    {
      A4GL_exitwith ("Value exceeds limit of SMALLINT ");
      return 0;
    }
  *z = (short) *a;
  return 1;
}

/**
 * Convert a long value to float.
 *
 * @param aa The long value.
 * @param zz A pointer to the place where to return the value.
 * @param sz_ignore Not used.
 * @return Allways 1
 */
int
A4GL_ltof (void *aa, void *zz, int sz_ignore)
{
  long *a;
  double *z;
  a = (long *) aa;
  z = (double *) zz;

#ifdef DEBUG
  A4GL_debug ("ltof");
#endif
  *z = (double) *a;
  return 1;
}

/**
 * Convert a long value to small float.
 *
 * @param aa The long value.
 * @param zz A pointer to the place where to return the value.
 * @param sz_ignore Not used.
 * @return Allways 1
 */
int
A4GL_ltosf (void *aa, void *zz, int sz_ignore)
{
  long *a;
  float *z;
  a = (long *) aa;
  z = (float *) zz;
  *z = (float) *a;
  return 1;
}

/**
 * Convert a long value to
 *
 * @param aa The long value.
 * @param zz A pointer to the place where to return the value.
 * @param c
 * @return Allways 1
 */
int
A4GL_ltovc (void *aa, void *zz, int c)
{
  long *a;
  char *z;
  a = (long *) aa;
  z = (char *) zz;
  if (A4GL_ltoc (a, z, c))
    {
      A4GL_trim (z);
      return 1;
    }
  return 0;
}

/**
 * Convert a float value to
 *
 * @param aa The float value.
 * @param zz A pointer to the place where to return the value.
 * @param c
 * @return Allways 1
 */
int
A4GL_ftoc (void *aa, void *zz, int c)
{
  double *a;
  char *z;
  char fmt[10] = ".2lf";
  char *buff = 0;
  a = (double *) aa;
  z = (char *) zz;

  buff = malloc (c + 200);
  memset (buff, 0, c + 200);	// allow plenty of extra space...


  memset (buff, '*', c + 199);
  if (A4GL_digittoc ((int *) a, z, fmt, DTYPE_FLOAT, c))
    {
      SPRINTF1 (buff, fmt, *a);
      if (strlen (buff) > c + 200)
	{
	  A4GL_assertion (1, "Buffer overrun...");
	}
    }

  if (strlen (buff) > c)
    {
      // Its too long...
      strcpy (fmt, ".1f");
      if (A4GL_digittoc ((int *) a, z, fmt, DTYPE_FLOAT, c))
	{
	  SPRINTF1 (buff, fmt, *a);
	}
      if (strlen (buff) > c)
	{
	  strcpy (fmt, ".0f");
	  if (A4GL_digittoc ((int *) a, z, fmt, DTYPE_FLOAT, c))
	    {
	      SPRINTF1 (buff, fmt, *a);
	    }
	}
    }

  if (strlen (buff) > c)
    {
      memset (z, '*', c);
      z[c] = 0;
    }
  else
    {
      strcpy (z, A4GL_decstr_convert (buff, a4gl_convfmts.printf_decfmt, a4gl_convfmts.using_decfmt, 0, 0, -1));
    }


  free (buff);
  return 1;
}

/**
 * Convert a float value to int.
 *
 * @param aa The float value.
 * @param zz A pointer to the place where to return the value.
 * @param c
 * @return Allways 1
 */
int
A4GL_ftoi (void *aa, void *zz, int c)
{
  char buff[200];
  double *a;
  short *z;
  z = (short *) zz;
  a = (double *) aa;
  SPRINTF1 (buff, "%lf", *a);
  A4GL_decstr_convert (buff, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 0, -1);
  if (A4GL_apm_str_detect_overflow (buff, 0, 0, DTYPE_SMINT))
    {
      A4GL_setnull (DTYPE_SMINT, z, 0);
    }
  else
    {
      *z = (short) *a;
    }
  return 1;
}

/**
 * Convert a float value to long.
 *
 * @param aa The float value.
 * @param zz A pointer to the place where to return the value.
 * @param c
 * @return Allways 1
 */
int
A4GL_ftol (void *aa, void *zz, int c)
{
  double *a;
  long *z;
  char buff[256];
  a = (double *) aa;
  z = (long *) zz;
#ifdef DEBUG
  A4GL_debug ("ftol");
#endif

  SPRINTF1 (buff, "%lf", *a);
  A4GL_decstr_convert (buff, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 0, -1);

  if (A4GL_apm_str_detect_overflow (buff, 0, 0, DTYPE_INT))
    {
      A4GL_setnull (DTYPE_INT, z, 0);
    }
  else
    {
      *z = (long) *a;
    }
#ifdef DEBUG
  {
    A4GL_debug ("a=%lf z=%d\n", *a, *z);
  }
#endif
  return 1;
}

/**
 * Convert a float value to small float.
 *
 * @param aa The float value.
 * @param zz A pointer to the place where to return the value.
 * @param c
 * @return Allways 1
 */
int
A4GL_ftosf (void *aa, void *zz, int c)
{
  double *a;
  float *z;
  a = (double *) aa;
  z = (float *) zz;
  *z = (float) *a;
  return 1;
}

/**
 * Convert a float value to ???
 *
 * @param aa The float value.
 * @param zz A pointer to the place where to return the value.
 * @param c
 * @return Allways 1
 */
int
A4GL_ftovc (void *aa, void *zz, int c)
{
  double *a;
  char *z;
  a = (double *) aa;
  z = (char *) zz;
  if (A4GL_ftoc (a, z, c))
    {
      A4GL_trim (z);
      return 1;
    }

  return 0;
}

/**
 * Convert a small float value to ???
 *
 * @param aa The float value.
 * @param zz A pointer to the place where to return the value.
 * @param c
 * @return Allways 1
 */
int
A4GL_sftoc (void *aa, void *zz, int c)
{
  float *a;
  char *z;
  char fmt[10] = ".2f";
  char *buff;
  a = (float *) aa;
  z = (char *) zz;
  buff = malloc (c + 40);
  strcpy (buff, "******************************************");
  if (A4GL_digittoc ((int *) a, z, fmt, DTYPE_FLOAT, c))
    {
      SPRINTF1 (buff, fmt, *a);
    }

  if (strlen (buff) > c)
    {
      // Its too long...
      strcpy (fmt, ".1f");
      if (A4GL_digittoc ((int *) a, z, fmt, DTYPE_FLOAT, c))
	{
	  SPRINTF1 (buff, fmt, *a);
	}
      if (strlen (buff) > c)
	{
	  strcpy (fmt, ".0f");
	  if (A4GL_digittoc ((int *) a, z, fmt, DTYPE_FLOAT, c))
	    {
	      SPRINTF1 (buff, fmt, *a);
	    }
	}
    }
  if (strlen (buff) > c)
    {
      memset (z, '*', c);
      z[c] = 0;
    }
  else
    {
      //strcpy (z, buff);
      strcpy (z, A4GL_decstr_convert (buff, a4gl_convfmts.printf_decfmt, a4gl_convfmts.using_decfmt, 0, 0, -1));
    }


  return 1;
}

/**
 * Convert a small float value to integer
 *
 * @param aa The small float value.
 * @param zz A pointer to the place where to return the value.
 * @param c
 * @return Allways 1
 */
int
A4GL_sftoi (void *aa, void *zz, int c)
{
  float *a;
  short *z;
  char buff[256];
  z = (short *) zz;
  a = (float *) aa;
  SPRINTF1 (buff, "%f", *a);
  A4GL_decstr_convert (buff, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 0, -1);
  if (A4GL_apm_str_detect_overflow (buff, 0, 0, DTYPE_SMINT))
    {
      A4GL_setnull (DTYPE_SMINT, z, 0);
    }
  else
    {
      *z = (short) *a;
    }
  return 1;
}

/**
 * Convert a small float value to long
 *
 * @param aa The small float value.
 * @param zz A pointer to the place where to return the value.
 * @param c
 * @return Allways 1
 */
int
A4GL_sftol (void *aa, void *zz, int c)
{
  float *a;
  long *z;
  char buff[200];
  z = (long *) zz;
  a = (float *) aa;
  SPRINTF1 (buff, "%f", *a);
  A4GL_decstr_convert (buff, a4gl_convfmts.printf_decfmt, a4gl_convfmts.posix_decfmt, 0, 0, -1);
  if (A4GL_apm_str_detect_overflow (buff, 0, 0, DTYPE_INT))
    {
      A4GL_setnull (DTYPE_INT, z, 0);
    }
  else
    {
      *z = (long) *a;
    }
  return 1;
}

/**
 * Convert a small float value to float
 *
 * @param aa The small float value.
 * @param zz A pointer to the place where to return the value.
 * @param c
 * @return Allways 1
 */
int
A4GL_sftof (void *aa, void *zz, int c)
{
  float *a;
  double *z;
  a = (float *) aa;
  z = (double *) zz;
  *z = (double) *a;
  return 1;
}

/**
 * Convert a small float value to  ???
 *
 * @param aa The small float value.
 * @param zz A pointer to the place where to return the value.
 * @param c
 * @return Allways 1
 */
int
A4GL_sftovc (void *aa, void *zz, int c)
{
  float *a;
  char *z;
  a = (float *) aa;
  z = (char *) zz;
  if (A4GL_sftoc (a, z, c))
    {
      A4GL_trim (z);
      return 1;
    }
  return 0;
}

/**
 * Copy a small float value.
 *
 * @param aa The small float value.
 * @param zz A pointer to the place where to return the value.
 * @param c
 * @return Allways 1
 */
int
A4GL_sftosf (void *aa, void *bb, int c)
{
  float *a, *b;
  a = (float *) aa;
  b = (float *) bb;
  *b = *a;
  return 1;
}

/**
 * Copy a float value.
 *
 * @param aa The float value.
 * @param zz A pointer to the place where to return the value.
 * @param c
 * @return Allways 1
 */
int
A4GL_ftof (void *aa, void *bb, int c)
{
  double *a;
  double *b;
  a = (double *) aa;
  b = (double *) bb;
  *b = *a;
  return 1;
}

int
A4GL_vctoc (void *a, void *b, int size)
{
  return A4GL_ctoc (a, b, size);
}

int
A4GL_vctovc (void *a, void *b, int size)
{
  char *x;
  x = b;
  memset (b, 0, size + 1);
  strncpy (b, a, size);
  x[size] = 0;
  return 1;
}

int
A4GL_ctovc (void *a, void *b, int size)
{
  char *x;
  x = b;
  memset (b, 0, size + 1);
  strncpy (b, a, size);
  x[size] = 0;
  return 1;
}

int
A4GL_vctoint (void *a, void *b, int size)
{
  return A4GL_ctoint (a, b, size);
}

int
A4GL_vctoi (void *a, void *b, int size)
{
  return A4GL_stoi (a, b, size);
}

int
A4GL_vctol (void *a, void *b, int size)
{
  return A4GL_stol (a, b, size);
}

int
A4GL_vctod (void *a, void *b, int size)
{
  return A4GL_stod (a, b, size);
}

int
A4GL_vctosf (void *a, void *b, int size)
{
  return A4GL_stosf (a, b, size);
}

int
A4GL_dectovc (void *a, void *b, int size)
{
  if (A4GL_dectos (a, b, size))
    {
      A4GL_trim (b);
      return 1;
    }
  return 0;

}

int
A4GL_mdectovc (void *a, void *b, int size)
{
  if (A4GL_dectos (a, b, size))
    {
      A4GL_trim (b);
      return 1;
    }
  return 0;
}

int
A4GL_vctof (void *a, void *b, int size)
{
  return A4GL_stof (a, b, size);
}

int
A4GL_vctodec (void *a, void *b, int size)
{
  return A4GL_stodec (a, b, size);
}

int
A4GL_vctomdec (void *a, void *b, int size)
{
  return A4GL_stomdec (a, b, size);
}

int
A4GL_vctodt (void *a, void *b, int size)
{
  return A4GL_ctodt (a, b, size);
}

/**
 * Copy a ??? value.
 *
 * @param aa The ??? value.
 * @param zz A pointer to the place where to return the value.
 * @param c
 * @return Allways 1
 */
int
A4GL_ctoc (void *a, void *b, int size)
{
#ifdef DEBUG
  {
    /*A4GL_debug ("--->Got size as %d", size); */
  }
#endif


  //A4GL_debug ("String_set....");

  A4GL_string_set (b, a, size);

#ifdef DEBUG
  {
    //A4GL_debug ("Set string");
  }
#endif
  //A4GL_debug ("returning");
  return 1;
}

/**
 * Copy a long value.
 *
 * @param aa The long value.
 * @param zz A pointer to the place where to return the value.
 * @param c
 * @return Allways 1
 */
int
A4GL_ltol (void *aa, void *bb, int sz_ignore)
{
  long *a;
  long *b;

  a = (long *) aa;
  b = (long *) bb;

  *b = *a;
#ifdef DEBUG
  {
    /* A4GL_debug ("ltol %ld", *a);
       A4GL_debug ("ltol %ld", *b); */
  }
#endif
  return 1;
}

/**
 * Copy an integer value.
 *
 * @param aa The long value.
 * @param zz A pointer to the place where to return the value.
 * @param c
 * @return Allways 1
 */
int
A4GL_itoi (void *aa, void *bb, int sz_ignore)
{
  short *a;
  short *b;
  a = (short *) aa;
  b = (short *) bb;
  *b = *a;
  return 1;
}

/**
 * Assign a character value to an empty string
 *
 * @param p The pointer to the string to be cleaned.
 */
void
A4GL_setc (void *p)
{
  char *p1;
  p1 = (char *) p;
  p1[0] = 0;
}

/**
 * Set an integer to zero.
 *
 * @param p The pointer to the integer.
 */
void
A4GL_seti (void *p)
{
  int *p1;
  p1 = (int *) p;
  *p1 = 0;
}

/**
 * Set a long to zero.
 *
 * @param p The pointer to the long.
 */
void
A4GL_setl (void *p)
{
  long *p1;
  p1 = (long *) p;
  *p1 = 0;
}

/**
 * Set a float to zero.
 *
 * @param p The pointer to the float.
 */
void
A4GL_setf (void *p)
{
  double *p1;
  p1 = (double *) p;
  *p1 = 0;
}

/**
 * Set a small float to zero.
 *
 * @param p The pointer to the float.
 */
void
A4GL_setsf (void *p)
{
  float *p1;
  p1 = (float *) p;
  *p1 = 0;
}

/**
 * Does nothing.
 */
void
A4GL_setno (void *p)
{
  return;
}


/**
 * Convert a value from one data type to other data type.
 *
 * @param dtype1 Data type of the original value.
 * @param p1 Pointer to the value to be converted.
 * @param dtype2  Data type of the original value.
 * @param p2 Pointer to the place where to put the converted value.
 * @param size
 */
int
A4GL_conv (int dtype1, void *p1, int dtype2, void *p2, int size)
{
static int set_slots=0;
int slot;
#define MAX_CONV_SLOTS 20
static void *slots[MAX_CONV_SLOTS][MAX_CONV_SLOTS];
static int have_slots[MAX_CONV_SLOTS][MAX_CONV_SLOTS];
      int (*call_function) (int, void *, int, void *, int);
  int (*ptr) (void *ptr1, void *ptr2, int size);
  int rval;
  //A4GL_debug ("In conv.. d1=%d d2=%d size=%d", dtype1, dtype2, size);


  char buff[256];

 if (!set_slots) {
	int a;
	int b;
	set_slots=1;
	for (a=0;a<MAX_CONV_SLOTS;a++) {
	for (b=0;b<MAX_CONV_SLOTS;b++) {
		slots[a][b]=NULL;
		have_slots[a][b]=0;
	}
	}
 }

  /* A4GL_debug ("Dtype1=%d p1=%p (%ld) ", dtype1, p1, *(int *) p1); */

  if (A4GL_isnull (dtype1 & DTYPE_MASK, p1))
    {
#ifdef DEBUG
      A4GL_debug ("First is null");
#endif
      A4GL_setnull (dtype2, p2, size);
      return 1;
    }

  if (dtype1 == DTYPE_CHAR && (dtype2 != DTYPE_CHAR && dtype2 != DTYPE_VCHAR && dtype2 != DTYPE_NCHAR && dtype2 != DTYPE_NVCHAR ))
    {
      A4GL_trim (p1);
      if (strlen (p1) == 0)
	{
	  A4GL_setnull (dtype2, p2, size);
	  return 1;
	}
    }

  A4GL_assertion (p1 == 0, "Pointer 1 is zero");
  A4GL_assertion (p2 == 0, "Pointer 2 is zero");

  /* Sanity check - conv() is sometimes erroneously called with
   * just a length for decimals, instead of length + decimal places.
   * This is a temporary measure - such bugs will be located & fixed.
   */

  if (((dtype2 & DTYPE_MASK) == DTYPE_DECIMAL || (dtype2 & DTYPE_MASK) == DTYPE_MONEY) && (size < 256))
    {
      //char*ptr=0;*ptr=0;
      // we don't know how many decimals are required, 4 should be ok
      //
      if (size == 0)
	{
#ifdef DEBUG
	  A4GL_debug ("%d\n", dtype1);
#endif
	  size = 32 * 256 + 16;
	}
#ifdef DEBUG
      A4GL_debug ("DTYPE_DECIMAL fix in conv.c...");
#endif
      size += 8;
      if (size > 32)
	size = 32;
      size = size * 256 + 4;
#ifdef DEBUG
      A4GL_debug ("conv: changing invalid decimal size to %d", size);
#endif
    }


  size_of_operand = DECODE_SIZE (dtype1);
  call_function=NULL;
  A4GL_conversion_ok (1);


  switch(dtype2&DTYPE_MASK) {
	case 0:		strcpy(buff,"CONVTO_0"); slot=0; break;
	case 1:		strcpy(buff,"CONVTO_1"); slot=1; break;
	case 2:		strcpy(buff,"CONVTO_2"); slot=2; break;
	case 3:		strcpy(buff,"CONVTO_3"); slot=3; break;
	case 4:		strcpy(buff,"CONVTO_4"); slot=4; break;
	case 5:		strcpy(buff,"CONVTO_5"); slot=5; break;
	case 6:		strcpy(buff,"CONVTO_6"); slot=6; break;
	case 7:		strcpy(buff,"CONVTO_7"); slot=7; break;
	case 8:		strcpy(buff,"CONVTO_8"); slot=8; break;
	case 9:		strcpy(buff,"CONVTO_9"); slot=9; break;
	case 10:	strcpy(buff,"CONVTO_10"); slot=10; break;
	case 11:	strcpy(buff,"CONVTO_11"); slot=11; break;
	case 12:	strcpy(buff,"CONVTO_12"); slot=12; break;
	case 13:	strcpy(buff,"CONVTO_13"); slot=13; break;
	case 14:	strcpy(buff,"CONVTO_14"); slot=14; break;
	case 15:	strcpy(buff,"CONVTO_15"); slot=15; break;
	default:
		slot=-1;
  		SPRINTF1 (buff, "CONVTO_%d", dtype2 & DTYPE_MASK);
  }

  call_function=NULL;
//printf("Buff=%s\n",buff);
  if (slot>=0 && (dtype1&DTYPE_MASK)< MAX_CONV_SLOTS &&  (dtype2&DTYPE_MASK)< MAX_CONV_SLOTS) {
	// We might potentially have a cached value...
	// so - do we have a cached value ? 
	if (have_slots[dtype1&DTYPE_MASK][dtype2&DTYPE_MASK]) {
		// Yes - dont need to do anything else...
		call_function=slots[dtype1&DTYPE_MASK][dtype2&DTYPE_MASK] ;
	}  else {
     		if (A4GL_has_datatype_function_i (dtype1 & DTYPE_MASK, buff)) {
      			call_function = A4GL_get_datatype_function_i (dtype1 & DTYPE_MASK, buff);
     		}
		
		slots[dtype1&DTYPE_MASK][dtype2&DTYPE_MASK]=call_function;
		// Regardless of whether we've got a function - we have looked for one
		// so - we need to mark that...
	//printf("Marked slot : %d\n",slot);
		have_slots[dtype1&DTYPE_MASK][dtype2&DTYPE_MASK]=1;
	}
  } else {
	// No cached value possible...
     	if (A4GL_has_datatype_function_i (dtype1 & DTYPE_MASK, buff)) {
      		call_function = A4GL_get_datatype_function_i (dtype1 & DTYPE_MASK, buff);
  	}
  }


  if (call_function) {
      return call_function (dtype1 & DTYPE_MASK, p1, dtype2 & DTYPE_MASK, p2, size);
   }

  ptr = convmatrix[dtype1 & DTYPE_MASK][dtype2 & DTYPE_MASK];

  //A4GL_debug("ptr=%p",ptr);

  if (ptr == NO)
    {
#ifdef DEBUG
      A4GL_debug ("No! - %d %d", dtype1, dtype2);
#endif
      A4GL_exitwith ("Invalid conversion");

      if (A4GL_has_datatype_function_i (dtype2, "SETDTYPE"))
	{
	  void (*function) (void *);
	  function = A4GL_get_datatype_function_i (dtype2, "SETDTYPE");
	  function (p2);
	}
      else
	{
	  if ((dtype2 & DTYPE_MASK) < (sizeof (setdtype) / sizeof (void *)))
	    {
		if (setdtype[dtype2 & DTYPE_MASK]) {
	      		setdtype[dtype2 & DTYPE_MASK] (p2);
		}
	    }
	}
      return -1;
    }

#ifdef DEBUG
  A4GL_debug ("40 Conv %d %d\n", dtype1 & DTYPE_MASK, dtype2 & DTYPE_MASK);
#endif
  rval = convmatrix[dtype1 & DTYPE_MASK][dtype2 & DTYPE_MASK] (p1, p2, size);

  return rval;
}



/**
 * Validate if date or date time is valid.
 *
 * @param s The data value as string.
 * @param data A pointer to the place where to pass information about the value.
 * @return If the date is valid or not:
 *   - 0 : The date is not valid.
 *   - 1 : The date is valid.
 */
int
A4GL_valid_dt (char *s, int *data, int size)
{
  int a = 0;
  char buff[256];
  char *ptr[256];
  char type[256];
  int dt_type = 0;
  int b = 0;
  int i = 0;
  int cnt = 0;
  int buff_size = 0;
#ifdef DEBUG
  char *codes[] = { "", "YEAR", "MONTH", "DAY", "HOUR", "MINUTE", "SECOND", "FRACTION1", "FRACTION2", "FRACTION3", "FRACTION4", "FRACTION5", 0 }; // Used for DEBUGGING
#endif
  for (a = 0; a < 255; a++)
    {
      ptr[a] = 0;
    }
  memset (buff, 0, sizeof (buff));
#ifdef DEBUG
  //A4GL_debug ("In valid_dt\n");
#endif
  
  if (strlen (s) >= 255)
    {
#ifdef DEBUG
      A4GL_debug ("Too long\n");
#endif
      return 0;
    }

  strcpy (buff, s);
  

  // Check the string length...
  if (strlen (buff) > 25) {
	char *z;
	// Its too long - this might be because the decimal on the fractions
	// is too long - but we can just trim that..
	//
	// Get the position of a '.'
	z=strchr(buff,'.');
	if (z) {
		int sl;
		z++;
		sl=strlen(z);
		// Ok - is that too long ?
		if (sl>5) {
			int a;
			int bad=0;
			// yes - but are they all numbers ? 
			for (a=0;a<sl;a++) {
				if (z[a]>='0'&&z[a]<='9') continue;
				bad=1;
				break;
			}
			if (bad) {
				//printf("Too long 1\n");
			 	return 0;
			}
			// Ok - so they are all numbers - but its too long..
			// lets trim them to 5..
			z[5]=0;


			// Now recheck with our new trimmed size...
			if (strlen(buff)>25) {
				//printf("Too long 2 : %s\n",buff);
				return 0;
			}
		} else {
			return 0;
		}
	} else {
      		return 0;
	}
  }


  ptr[0] = &buff[0];
#ifdef DEBUG
  //A4GL_debug ("Splitting '%s' size=%d\n", A4GL_null_as_null (s), size);
#endif
  cnt = 0;
  buff_size = strlen (buff);
  for (a = 0; a < buff_size; a++)
    {

      if (buff[a] == '.')	// C
	{
	  type[cnt++] = '.';	// C
	  ptr[cnt] = &buff[a + 1];
	  buff[a] = 0;
	  continue;
	}

      if (buff[a] == '-')
	{
	  type[cnt++] = '-';
	  ptr[cnt] = &buff[a + 1];
	  buff[a] = 0;
	  continue;
	}

      if (buff[a] == ' ')
	{
	  type[cnt++] = ' ';
	  ptr[cnt] = &buff[a + 1];
	  buff[a] = 0;
	  continue;
	}

      if (buff[a] == ':')
	{
	  type[cnt++] = ':';
	  ptr[cnt] = &buff[a + 1];
	  buff[a] = 0;
	  continue;
	}

      if (buff[a] >= '0' && buff[a] <= '9')
	{
	  continue;
	}
      /*  not something we we're expecting */
#ifdef DEBUG
      A4GL_debug ("Dodgey character %c\n", buff[a]);
#endif
      return 0;
    }

  type[cnt] = 0;
  dt_type = -1;
#ifdef DEBUG
  //A4GL_debug ("cnt=%d\n", cnt);
  //A4GL_debug ("type=%s\n", A4GL_null_as_null (type));
#endif

  if (strcmp (type, "") == 0)
    {

      dt_type = 0;
    }

  if (strcmp (type, "-- ::.") == 0)
    {
      dt_type = dt_encode (DT_YEAR, DT_FRACTION);
    }
  if (strcmp (type, "- ::.") == 0)
    {
      dt_type = dt_encode (DT_MONTH, DT_FRACTION);
    }
  if (strcmp (type, " ::.") == 0)
    {
      dt_type = dt_encode (DT_DAY, DT_FRACTION);
    }
  if (strcmp (type, "::.") == 0)
    {
      dt_type = dt_encode (DT_HOUR, DT_FRACTION);
    }
  if (strcmp (type, ":.") == 0)
    {
      dt_type = dt_encode (DT_MINUTE, DT_FRACTION);
    }
  if (strcmp (type, ".") == 0)
    {
      dt_type = dt_encode (DT_SECOND, DT_FRACTION);
    }

  if (strcmp (type, "-- ::") == 0)
    {
      dt_type = dt_encode (DT_YEAR, DT_SECOND);
    }
  if (strcmp (type, "- ::") == 0)
    {
      dt_type = dt_encode (DT_MONTH, DT_SECOND);
    }
  if (strcmp (type, " ::") == 0)
    {
      dt_type = dt_encode (DT_DAY, DT_SECOND);
    }
  if (strcmp (type, "::") == 0)
    {
      dt_type = dt_encode (DT_HOUR, DT_SECOND);
    }

  if (strcmp (type, ":") == 0)
    {
      dt_type = dt_encode (DT_MINUTE, DT_SECOND);
    }

  if (strcmp (type, "-- :") == 0)
    {
      dt_type = dt_encode (DT_YEAR, DT_MINUTE);
    }
  if (strcmp (type, "- :") == 0)
    {
      dt_type = dt_encode (DT_MONTH, DT_MINUTE);
    }
  if (strcmp (type, " :") == 0)
    {
      dt_type = dt_encode (DT_DAY, DT_MINUTE);
    }
  if (strcmp (type, ":") == 0)
    {
      dt_type = dt_encode (DT_HOUR, DT_MINUTE);
    }

  if (strcmp (type, "-- ") == 0)
    {
      dt_type = dt_encode (DT_YEAR, DT_HOUR);
    }
  if (strcmp (type, "- ") == 0)
    {
      dt_type = dt_encode (DT_MONTH, DT_HOUR);
    }
  if (strcmp (type, " ") == 0)
    {
      dt_type = dt_encode (DT_DAY, DT_HOUR);
    }

  if (strcmp (type, "--") == 0)
    {
      dt_type = dt_encode (DT_YEAR, DT_DAY);
    }

  if (strcmp (type, "-") == 0)
    {
      if (strlen (ptr[0]) != 4)
	{
	  dt_type = dt_encode (DT_MONTH, DT_DAY);
	}
      else
	{
	  dt_type = dt_encode (DT_YEAR, DT_MONTH);
	}
    }

  if (dt_type == -1)
    {
#ifdef DEBUG
      A4GL_debug ("dt_type==-1");
#endif
      return 0;
    }
  if (dt_type == 0 && strlen (ptr[0]))
    {
      a = size >> 4;
      b = size & 15;
#ifdef DEBUG
      A4GL_debug ("DIGIT %d %d", a, b);
#endif
      if (a == b)
	{
	  if (a == 1)
	    data[0] = atoi (ptr[0]);
	  if (a == 2)
	    data[1] = atoi (ptr[0]);
	  if (a == 3)
	    data[2] = atoi (ptr[0]);
	  if (a == 4)
	    data[3] = atoi (ptr[0]);
	  if (a == 5)
	    data[4] = atoi (ptr[0]);
	  if (a == 6)
	    data[5] = atoi (ptr[0]);
	}
      return 2;			/* single number.. */
    }
  if (dt_type == 0 && strlen (ptr[0]) == 0)
    {
#ifdef DEBUG
      A4GL_debug ("Nothing");
#endif
      return 0;			/* nothing... */
    }

  b = dt_type & 15;
  a = dt_type >> 4;
#ifdef DEBUG
  A4GL_debug ("a=%d b=%d dt_type=%d cnt=%d\n", a, b, dt_type, cnt);
#endif

  if (b - a != cnt)
    {
#ifdef DEBUG
      A4GL_debug ("mismatch in brackets\n");
#endif
      return 0;
    }

  for (i = 0; i < 10; i++)
    {
      data[i] = 0;
    }

#ifdef DEBUG
  A4GL_debug ("a=%d b=%d\n", a, b);
#endif
  for (i = a; i <= b; i++)
    {
#ifdef DEBUG
      A4GL_debug ("i=%d i-a=%d\n", i, i - a);
#endif
      if (i == 1 && strlen (ptr[i - a]) != 4)
	{
#ifdef DEBUG
	  A4GL_debug ("Year not 4 digits\n");
#endif
	  return 0;
	}

      if (i != 1 && strlen (ptr[i - a]) != 2 && i != 7)
	{
#ifdef DEBUG
	  A4GL_debug ("expecting 2 digits -> '%s' i=%d\n", A4GL_null_as_null (ptr[i - a]), i);
#endif
	  if (i != 4 && i != 5 && i != 3 && i != 6)
	    {
	      return 0;
	    }
#ifdef DEBUG
	  A4GL_debug ("ZZ9 : %d", strlen (ptr[i - a]));
#endif
	  if (i == 2)
	    {
	      if (atol (ptr[i - a]) == 0)
		{
		  return 0;
		}		// can't have a 0 in the month
	    }
	  if (i == 3)
	    {
	      if (atol (ptr[i - a]) == 0)
		{
		  return 0;
		}		// cant have a 0 in the day
	    }
	  if (strlen (ptr[i - a]) != 1)
	    {
	      return 0;
	    }

	}

      if (i == 2)
	{
	  char *p;
	  p = ptr[i - a];
	  if (atol (p) == 0 && 0)
	    {
	      return 0;
	    }
	}			// can't have a 0 in the month
      if (i == 3)
	{
	  char *p;
	  p = ptr[i - a];
	  if (atol (p) == 0 && 0)
	    {
	      return 0;
	    }
	}			// cant have a 0 in the day

      if (i == 7)
	{
	  int l;
	  char buff[10];
	  strncpy (buff, ptr[i - a], 9);
	  buff[5] = 0;
	  l = strlen (ptr[i - a]);
	  if (l == 1)
	    data[i - 1] = atoi (ptr[i - a]) * 10000;
	  if (l == 2)
	    data[i - 1] = atoi (ptr[i - a]) * 1000;
	  if (l == 3)
	    data[i - 1] = atoi (ptr[i - a]) * 100;
	  if (l == 4)
	    data[i - 1] = atoi (ptr[i - a]) * 10;
	  if (l == 5)
	    data[i - 1] = atoi (ptr[i - a]) * 1;
	}
      else
	{
#ifdef DEBUG
	  A4GL_debug ("data[%d-1]=%s", i, ptr[i - a]);
#endif
	  data[i - 1] = atoi (ptr[i - a]);
	}

#ifdef DEBUG
      A4GL_debug ("%s -> '%s'\n", A4GL_null_as_null (codes[i]), A4GL_null_as_null (ptr[i - a]));
#endif
    }

  if ((size >> 4) <= 1 && (size & 0xf) >= 3)
    {				// Year to day..
      int y;
      int m = 1;
      int d = 1;
      if (a <= 1)
	{
	  if (ptr[1 - a])
	    {
	      y = atol (ptr[1 - a]);
	    }
	}
      if (a <= 2)
	{
	  if (ptr[2 - a])
	    {
	      m = atol (ptr[2 - a]);
	    }
	}
      if (a <= 3)
	{
	  if (ptr[3 - a])
	    {
	      d = atol (ptr[3 - a]);
	    }
	}

      if (m <= 0 || d <= 0)
	{
	  return 0;
	}
    }

  // Do we have a valid date ?
  if (data[0] && data[1] && data[2])
    {
      long x;
      x = A4GL_gen_dateno (data[2], data[1], data[0]);
      if (x == DATE_INVALID)
	return 0;
#ifdef DEBUG
      A4GL_debug ("%ld!=%ld", x, DATE_INVALID);
#endif
    }

  if (data[3] < 0 || data[3] > 23)
    return 0;			// Hours
  if (data[4] < 0 || data[4] > 59)
    return 0;			// Minutes
  if (data[5] < 0 || data[5] > 59)
    return 0;			// Seconds


  {
    int l1_t;
    int l2_t;
    int l1_s;
    int l2_s;
    //  Do we have compatible types ?
    l1_t = dt_type & 0xf0;
    l1_s = size & 0xf0;
    l2_t = dt_type & 0x0f;
    l2_s = size & 0x0f;
    if (l2_t >= DT_SECOND)
      l2_t = DT_FRACTION;
    if (l2_s >= DT_SECOND)
      l2_s = DT_FRACTION;

    if (l1_t != l1_s || l2_t != l2_s)
      {

#ifdef DEBUG
	A4GL_debug ("Are they really compatible ? %d %d %d %d\n", l1_t, l1_s, l2_t, l2_s);
	A4GL_debug ("Informix(tm)4GL might complain about this and set it to null instead...");
#endif
	//return 0;
      }

  }
  return 1;
}


/**
 *  * Check if a value is a valid date or datetime.
 *   * @param s
 *    * @param data
 *     * @param size
 *      * @return The result of the validation:
 *       *   - 0 : The value is not a valid date or datetime.
 *        *   - 1 : The value is a valid datetime.
 *         */

static int decodePostgresqlInterval(char *s, int *i_years, int *i_months, int *i_days, int *i_hours, int *i_minutes, int *i_second, int *i_fraction) {
int l;
char buff[2000];
char *ptrs[100];
int ptrs_cnt=0;
int a;
*i_years=0;
*i_months=0;
*i_days=0;
*i_hours=0;
*i_minutes=0;
*i_second=0;
*i_fraction=0;

	// Split the string into component parts..
	strcpy(buff,s);
	ptrs[0]=&buff[0];

	l=strlen(s);
	for (a=0;a<l;a++) {
		if (buff[a]==' ') {
			buff[a]=0;
			ptrs[ptrs_cnt]=&buff[a+1];
			while (*ptrs[ptrs_cnt]==' ') ptrs[ptrs_cnt]++;
			ptrs_cnt++;
		}
	}

//printf("Here\n");
	for (a=1;a<ptrs_cnt;a++) {
		A4GL_lrtrim(ptrs[a]);
		if (strcmp(ptrs[a],"@")==0) continue;
		//printf("..%s\n",ptrs[a]);
		A4GL_make_downshift(ptrs[a]);
		if (strstr(ptrs[a],"yea") ) { *i_years=atol(ptrs[a-1]); }
		if (strstr(ptrs[a],"mon") ) { *i_months=atol(ptrs[a-1]); }
		if (strstr(ptrs[a],"day") ) { *i_days=atol(ptrs[a-1]); }
		if (strstr(ptrs[a],"hour") ) { *i_hours=atol(ptrs[a-1]); }
		if (strstr(ptrs[a],"min") ) { *i_minutes=atol(ptrs[a-1]); }
		if (strstr(ptrs[a],"sec") ) { 
			char *dot;
			dot=strchr(ptrs[a-1],'.');
			if (dot) {
				*dot=0; dot++;
				*i_second=atol(ptrs[a-1]); 
				*i_fraction=atol(dot); 
				
			} else {
				*i_second=atol(ptrs[a-1]); 
			}
		}
	}
	//printf("Y:%d M:%d D:%d H:%d M:%d S:%d F:%d\n", *i_years, *i_months, *i_days, *i_hours, *i_minutes, *i_second, *i_fraction);

return 1;
}


static int isValidPgStyleInterval(char *s, int *data, int size) {
int ivals[7];
struct ival i;
if (data==NULL) data=ivals;
if (decodePostgresqlInterval(s,&data[0],&data[1],&data[2],&data[3],&data[4],&data[5],&data[6])) {
if (A4GL_conv_invdatatoc (data,0,0,0,&i)) {
	return 1;
}
}
return 0;

}

/**
 * Check if a value is a valid date or datetime.
 * @param s
 * @param data
 * @param size
 * @return The result of the validation:
 *   - 0 : The value is not a valid date or datetime.
 *   - 1 : The value is a valid datetime.
 */
int
A4GL_valid_int (char *s, int *data, int size)
{
  int a;
  static char buff[256];
  static char *ptr[256];
  static char type[256];
  int data_z[32];
  int dt_type;
  int b;
  int i;
  int cnt = 0;
  int has_yr_month = 0;
  int has_rest = 0;
  int buff_size;
  int size_type;
#ifdef DEBUG
  char *codes[] = { "", "YEAR", "MONTH", "DAY", "HOUR", "MINUTE",
    "SECOND", "FRACTION1", "FRACTION2", "FRACTION3", "FRACTION4", "FRACTION5",
    0
  };
#endif

  //if (strcmp(s,"0-1")==0) { return 1; }

  if (strlen (s) == 0)
    return 0;


  if (s[0]=='@') { // Postgresql style integer
		return isValidPgStyleInterval(s,data,size);
  }

  if (data==NULL) {
		data=data_z;
  }
 for (i = 0; i < 32; i++) { data[i] = 0; }
  

  size_type = (size >> 4) & 15;
#ifdef DEBUG
  A4GL_debug ("In valid_int size=%x\n", size);
#endif
  if (strlen (s) > 30)
    {
#ifdef DEBUG
      A4GL_debug ("Too long - '%s' (%d)\n", A4GL_null_as_null (s), strlen (s));
#endif
      return 0;
    }

#ifdef DEBUG
  A4GL_debug ("%d %d\n", (size & 0xf), size_type);
#endif
  if ((size & 0xf) > 1 && size_type < 1)
    return 0;			// Size is wrong..
  if ((size & 0xf) < size_type && size_type != 8)
    return 0;			// Size is wrong..

  memset (buff, 0, 255);
  while (s[0] == ' ' && s[0] != 0)
    s++;
  strcpy (buff, s);
  if (strlen (buff) == 0)
    return 0;
  memset (type, 0, 255);
  // Lets strip any leading '-'
  //
  buff_size = strlen (buff);
  for (a = 0; a < buff_size; a++)
    {
      if (buff[a] == '-')
	{
	  buff[a] = ' ';
	  break;
	}
      if (buff[a] != ' ')
	break;
    }
  ptr[0] = &buff[0];
#ifdef DEBUG
  A4GL_debug ("Splitting '%s'\n", A4GL_null_as_null (buff));
#endif
  cnt = 0;


  for (a = 1; a < buff_size; a++)
    {

      if (buff[a] == '.')	// C
	{
	  type[cnt++] = '.';	// C
	  ptr[cnt] = &buff[a + 1];
	  buff[a] = 0 ;
	  continue;
	}

      if (buff[a] == '-')
	{
	  type[cnt++] = '-';
	  ptr[cnt] = &buff[a + 1];
	  buff[a] = 0;
	  continue;
	}

      if (buff[a] == ' ')
	{
	  type[cnt++] = ' ';
	  ptr[cnt] = &buff[a + 1];
	  buff[a] = 0;
	  continue;
	}

      if (buff[a] == ':')
	{
	  type[cnt++] = ':';
	  ptr[cnt] = &buff[a + 1];
	  buff[a] = 0;
	  continue;
	}

      if (buff[a] >= '0' && buff[a] <= '9')
	{
	  continue;
	}
      /* not something we we're expecting */
#ifdef DEBUG
      A4GL_debug ("Dodgey character %c\n", buff[a]);
#endif
      return 0;
    }

  type[cnt] = 0;
  dt_type = -1;
#ifdef DEBUG
  A4GL_debug ("cnt=%d\n", cnt);
#endif

  //debug ("type='%s' size=0x%x\n", type,size);
//printf("type=%s\n",type);

  if (strcmp (type, "") == 0)
    {
      dt_type = 0;
    }

  if (strcmp (type, "-- ::.") == 0)
    {
      dt_type = dt_encode (DT_YEAR, DT_FRACTION);
    }
  if (strcmp (type, "- ::.") == 0)
    {
      dt_type = dt_encode (DT_MONTH, DT_FRACTION);
    }
  if (strcmp (type, " ::.") == 0)
    {
      dt_type = dt_encode (DT_DAY, DT_FRACTION);
    }
  if (strcmp (type, "::.") == 0)
    {
      dt_type = dt_encode (DT_HOUR, DT_FRACTION);
    }
  if (strcmp (type, ":.") == 0)
    {
      dt_type = dt_encode (DT_MINUTE, DT_FRACTION);
    }
  if (strcmp (type, ".") == 0)
    {
      dt_type = dt_encode (DT_SECOND, DT_FRACTION);
    }

  if (strcmp (type, "-- ::") == 0)
    {
      dt_type = dt_encode (DT_YEAR, DT_SECOND);
    }
  if (strcmp (type, "- ::") == 0)
    {
      dt_type = dt_encode (DT_MONTH, DT_SECOND);
    }
  if (strcmp (type, " ::") == 0)
    {
      dt_type = dt_encode (DT_DAY, DT_SECOND);
    }
  if (strcmp (type, "::") == 0)
    {
      dt_type = dt_encode (DT_HOUR, DT_SECOND);
    }

  if (strcmp (type, ":") == 0)
    {
      if ((size & 0xff) % 16 == 6)
	dt_type = dt_encode (DT_MINUTE, DT_SECOND);
      else
	dt_type = dt_encode (DT_HOUR, DT_MINUTE);
    }

  if (strcmp (type, "-- :") == 0)
    {
      dt_type = dt_encode (DT_YEAR, DT_MINUTE);
    }
  if (strcmp (type, "- :") == 0)
    {
      dt_type = dt_encode (DT_MONTH, DT_MINUTE);
    }
  if (strcmp (type, " :") == 0)
    {
      dt_type = dt_encode (DT_DAY, DT_MINUTE);
    }

  if (strcmp (type, "-- ") == 0)
    {
      dt_type = dt_encode (DT_YEAR, DT_HOUR);
    }
  if (strcmp (type, "- ") == 0)
    {
      dt_type = dt_encode (DT_MONTH, DT_HOUR);
    }
  if (strcmp (type, " ") == 0)
    {
      dt_type = dt_encode (DT_DAY, DT_HOUR);
    }

  if (strcmp (type, "--") == 0)
    {
      dt_type = dt_encode (DT_YEAR, DT_DAY);
    }

  if (strcmp (type, "-") == 0)
    {
      dt_type = dt_encode (DT_YEAR, DT_MONTH);
    }

#ifdef DEBUG
  A4GL_debug ("dt_type= %d\n", dt_type);
#endif

  if (dt_type == 0)
    {				/* Lets assume the programmer knows what he's doing.. */
#ifdef DEBUG
      A4GL_debug ("Probably type= %d\n", size_type);
#endif
      dt_type = dt_encode (size_type, size_type);
    }



  if (dt_type == -1)
    return 0;

  if (dt_type == 0 && strlen (ptr[0]))
    return 1;			/* single number.. */

  if (dt_type == 0 && strlen (ptr[0]) == 0)
    return 0;			/* nothing... */


  
  b = dt_type & 15;
  a = dt_type >> 4;

#ifdef DEBUG
  A4GL_debug ("a=%d b=%d dt_type=%d cnt=%d\n", a, b, dt_type, cnt);
#endif

//printf("Check %s '%s' %d %d %d\n", s,type,size_type, a,b);
if (a==((size >>4)&0xf) && b==(size&0xf) ){
	; // printf("matches on size...\n");
} else {
	int az;
	az=((size >>4)&0xf);
	if (a==1 || a==2) {
		if (az==1 || az==2) ;
		else { return 0; }
	} else {
		if (az==1 || az==2)  return 0;
	}
	//printf("not matches on size...\n");
}
	

  if (b - a != cnt)
    {
#ifdef DEBUG
      A4GL_debug ("mismatch in brackets\n");
#endif
      return 0;
    }

  for (i = 0; i < 10; i++)
    {
      data[i] = 0;
    }

  for (i = a; i <= b; i++)
    {
#ifdef DEBUG
      A4GL_debug ("i=%d i-a=%d\n", i, i - a);
#endif

      if (i == 7)
	{
	  char buff[256];
	  strcpy (buff, ptr[i - a]);
	  strcat (buff, "000000");
	  buff[5] = 0;
#ifdef DEBUG
	  A4GL_debug ("Setting fraction to %d\n", atoi (buff));
#endif
	  data[i - 1] = atoi (buff);
	}
      else
	{
	  data[i - 1] = atoi (ptr[i - a]);
	}

#ifdef DEBUG
      A4GL_debug ("%s -> '%s'\n", A4GL_null_as_null (codes[i]), A4GL_null_as_null (ptr[i - a]));
#endif
    }
  has_yr_month = 0;
  has_rest = 0;
  if (data[0] || data[1])
    has_yr_month = 1;
  if (data[2] || data[3] || data[4] || data[5] || data[6])
    has_rest = 1;
  if (has_yr_month && has_rest)
    {
#ifdef DEBUG
      A4GL_debug ("Can't have month/year and day/hour/second/fraction..\n");
#endif
      return 0;
    }
  return 1;
}



static int
atoi_n (char *s, int n)
{
  char buff[256];
  strcpy (buff, s);
  buff[n] = 0;
  return atoi (buff);
}


void
A4GL_decode_datetime (struct A4GLSQL_dtime *d, int *data)
{
  int cnt = 0;
  char buff[256];
  int x;
  int pos[] = { 0, 4, 6, 8, 10, 12, 14, 15, 16, 17, 18, 19 };
  int sizes[] = { 4, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1 };
  //char delim[] = "-- ::.*****";
  int data_internal[20];
  if (d == 0 || data == 0)
    {
      A4GL_assertion (d == 0, "d=0 in decode_datetime");
      A4GL_assertion (data == 0, "data=0 in decode_datetime");
    }

  for (x = 0; x < 10; x++)
    {
      data[x] = 0;
    }

  for (x = 0; x < 20; x++)
    {
      data_internal[x] = 0;
    }

  x = 0;

  memset (buff, 0, 255);
  for (cnt = d->stime - 1; cnt <= d->ltime - 1; cnt++)
    {

      //debug ("cnt=%d", cnt);
      //debug ("   pos=%d sizes=%d", pos[cnt], sizes[cnt]);
      strncpy (&buff[x], &d->data[pos[cnt]], sizes[cnt]);

      data_internal[cnt] = atoi_n (&buff[x], sizes[cnt]);
      x += sizes[cnt];
    }
  // Got our split into Y,M,D,H,M,S,F,F,F,F,F
  // Need to copy these across
  data[0] = data_internal[0];	//Y
  data[1] = data_internal[1];	//M
  data[2] = data_internal[2];	//D
  data[3] = data_internal[3];	//H
  data[4] = data_internal[4];	//M
  data[5] = data_internal[5];	//S
  data[6] = data_internal[6];	//F1
  data[6] = data[6] * 10 + data_internal[7];	//F2
  data[6] = data[6] * 10 + data_internal[8];	//F3
  data[6] = data[6] * 10 + data_internal[9];	//F4
  data[6] = data[6] * 10 + data_internal[10];	//F5
#ifdef DEBUG
  A4GL_debug ("%d %d %d %d %d %d %d", data[0], data[1], data[2], data[3], data[4], data[5], data[6]);
#endif
}



/**
* This function sets up the conversion matrix
* for a new datatype
**/
void
A4GL_set_convmatrix (int dtype1, int dtype2, void *ptr)
{

#ifdef DEBUG
  A4GL_debug ("Setting convmatrix %d %d to %p", dtype1, dtype2, ptr);
#endif

  convmatrix[dtype1][dtype2] = ptr;
}


/**
*
*
**/
void
A4GL_set_setdtype (int dtype, void *ptr)
{
  setdtype[dtype] = ptr;
}



