/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
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
# $Id: conv.c,v 1.59 2003-09-05 15:26:58 mikeaubury Exp $
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
 * @todo Doxygen A4GL_comments to add to functions
 */

 /*
    =====================================================================
    Includes
    =====================================================================
  */


#include "a4gl_libaubit4gl_int.h"
#include <ctype.h>

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

/**
 * definitions for dates (seems a pretty odd conversion though...
 */
#define A4GL_itomdec 	A4GL_itodec
#define A4GL_dtodec 		A4GL_ltodec
#define A4GL_dtomdec 	A4GL_ltodec
#define A4GL_ltomdec 	A4GL_ltodec
#define A4GL_stomdec 	A4GL_stodec

#define A4GL_ftomdec 	A4GL_ftodec
#define A4GL_sftomdec 	A4GL_sftodec
#define A4GL_mdectomdec 	A4GL_dectodec
#define A4GL_mdectodec 	A4GL_dectodec
#define A4GL_dectomdec 	A4GL_dectodec

#define OK (void *)1


#define DEC_VAL(x) 		( ((x)&0xf)+ (((x)&0xf0)*10 /16) )
#define HEX_VAL(x) 		(((x)%10) + ((((x)-((x)%10)) / 10)*16))
#define SIGNED(x) 		(x[0]&128)
#define SET_SIGNED(x) 	(x[0]|=128)
#define SET_UNSIGNED(x) (x[0]=(x[0]>=128)?x[0]:x[0]-128)
#define NUM_DIG(x) 		((x[0])&127 )
#define NUM_DEC(x) 		((x[1]))
#define SET_DIG(x,y) 	(x[0]=y)
#define SET_DEC(x,y) 	(x[1]=y)
#define OFFSET_DEC(x) 	(2)
#define NUM_BYTES(x) 	(NUM_DIG(x)+OFFSET_DEC(x))
#define print_res(x) 	print_res_l(__LINE__,x)
#define dt_encode(s,e) 	((s*16)+e)
//#define dt_encode(s,e)        ((s*16)+e)

#define DBL_DIG1 		512
#define DT_YEAR 		1
#define DT_MONTH 		2
#define DT_DAY 			3
#define DT_HOUR 		4
#define DT_MINUTE 		5
#define DT_SECOND 		6
#define DT_FRACTION 		7
/*
#define DT_YEAR 		1
#define DT_MONTH 		2
#define DT_DAY 			3
#define DT_HOUR 		4
#define DT_MINUTE 		5
#define DT_SECOND 		6
#define DT_FRACTION 	7
*/


/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

/** @todo Change all this function proptotypes to an header */
int A4GL_conv_invdatatoc (int *data, int v1, int v2, int v3, struct ival *d);
int A4GL_bname2 (char *str, char *s1, char *s2, char *s3);
char *A4GL_inv (char *s);
double A4GL_dec_to_double (void *buf);
char *A4GL_dec_to_str (char *s, int size);
char *A4GL_add_dec (char *a, char *b);
char *A4GL_minus_dec (char *a, char *b);
char *A4GL_str_to_dec (char *s, char *w);
//char *A4GL_init_dec (char *s, int len, int d);
char *A4GL_mult_dec (char *s, char *v);
char *A4GL_divide_dec (char *s, char *w);
int A4GL_dec_roundoff (char *s, int n);
void A4GL_dec_to_dec (char *f, char *t);
void A4GL_dump (char *s);

int A4GL_op_ival (struct ival *a, struct ival *b, double double_val, char op,
	     char param);


void A4GL_trim_dec (char *s);
void A4GL_negate (char *s);
void A4GL_pr (char *wrkbf);
void A4GL_double_to_dec (double arg, char *buf, size_t length, size_t digits);
//void A4GL_assertion                        (int a, char *s);


int A4GL_valid_dt (char *s, int *data);

int A4GL_ctoc (void *a, void *b, int size);
//int A4GL_ctodt             (void *a, void *b, int size);
//int A4GL_ctoint            (void *a, void *b, int size);

int A4GL_valid_int (char *s, int *data, int size);

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
int A4GL_dttoc (void *a, void *b, int size);
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

int A4GL_stof (void *aa, void *zz, int sz_ignore);
int A4GL_sftovc (void *aa, void *zz, int c);
int A4GL_sftod (void *aa, void *zz, int sz_ignore);
int A4GL_sftol (void *aa, void *zz, int c);
int A4GL_sftoi (void *aa, void *zz, int c);
int A4GL_sftoc (void *aa, void *zz, int c);
int A4GL_sftof (void *aa, void *zz, int c);
int A4GL_sftosf (void *aa, void *bb, int c);
int A4GL_sftodec (void *a, void *z, int size);
int A4GL_stol (void *aa, void *zi, int sz_ignore);
int A4GL_stodec (void *a, void *z, int size);
//int A4GL_stomdec (void *a, void *z, int size);
int A4GL_stosf (void *aa, void *zz, int sz_ignore);
int A4GL_stoi (void *aa, void *zi, int sz_ignore);
void A4GL_decode_datetime (struct A4GLSQL_dtime *d, int *data);

int A4GL_mdectod (void *zz, void *aa, int sz_ignore);

static char *dec_math (char *s, char *w, char *r, char op);
static void match_dec (char *f, char *t, int *a, int *b);
void A4GL_trim_decimals (char *s, int d);
void A4GL_set_setdtype (int dtype, void *ptr);
int A4GL_dectod (void *zz, void *aa, int sz_ignore);
int A4GL_d_to_dt(void *a,void *b,int size) ;
int A4GL_dt_to_d(void *a,void *b,int size) ;

#ifdef TEST
static void exercise (void);
static void print_res_l (int ln, char *s);
#endif

#include <errno.h>
/* extern int 		errno; */
int lastsize;

int size_of_operand=0;

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
    A4GL_setsf, A4GL_setf, A4GL_setl, A4GL_setno, A4GL_setf, A4GL_setno, A4GL_setno, A4GL_setno, A4GL_setno, A4GL_setno, A4GL_setno};


/**
 * Convertion table.
 */
int (*convmatrix[MAX_DTYPE][MAX_DTYPE]) (void *ptr1, void *ptr2, int size) =
{
  { A4GL_ctoc, A4GL_stoi, A4GL_stol, A4GL_stof, A4GL_stosf, A4GL_stodec, A4GL_stol, A4GL_stod, A4GL_stomdec, NO, A4GL_ctodt, NO, NO, OK, A4GL_ctoint} ,
  { A4GL_itoc, A4GL_itoi, A4GL_itol, A4GL_itof, A4GL_itosf, A4GL_itodec, A4GL_itol, A4GL_itod, A4GL_itomdec, NO, NO, NO, NO, A4GL_itovc, NO} ,
  { A4GL_ltoc, A4GL_ltoi, A4GL_ltol, A4GL_ltof, A4GL_ltosf, A4GL_ltodec, A4GL_ltol, A4GL_ltod, A4GL_ltomdec, NO, NO, NO, NO, A4GL_ltovc, NO} ,
  { A4GL_ftoc, A4GL_ftoi, A4GL_ftol, A4GL_ftof, A4GL_ftosf, A4GL_ftodec, A4GL_ftol, A4GL_ftod, A4GL_ftomdec, NO, NO, NO, NO, A4GL_ftovc, NO} ,
  { A4GL_sftoc, A4GL_sftoi, A4GL_sftol, A4GL_sftof, A4GL_sftosf, A4GL_sftodec, A4GL_sftol, A4GL_sftod, A4GL_sftomdec, NO, NO, NO, NO, A4GL_sftovc, NO} ,
  { A4GL_dectos, A4GL_dectoi, A4GL_dectol, A4GL_dectof, A4GL_dectosf, A4GL_dectodec, A4GL_dectol, NO, A4GL_dectomdec, NO, NO, NO, NO, A4GL_dectos, NO} ,
  { A4GL_ltoc, A4GL_ltoi, A4GL_ltol, A4GL_ltof, A4GL_ltosf, A4GL_ltodec, A4GL_ltol, A4GL_ltod, A4GL_ltomdec, NO, NO, NO, NO, A4GL_ltovc, NO} , 
  { A4GL_dtos, A4GL_dtoi, A4GL_dtol, A4GL_dtof, A4GL_dtosf, A4GL_dtodec, A4GL_dtof, A4GL_ltol, A4GL_dtomdec, NO, A4GL_d_to_dt, NO, NO, A4GL_dtovc, NO} ,
  { A4GL_mdectos, A4GL_mdectoi, A4GL_mdectol, A4GL_mdectof, A4GL_mdectosf, A4GL_mdectodec, A4GL_mdectol, NO, A4GL_mdectomdec, NO, NO, NO, NO, A4GL_mdectos, NO} ,
  { NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO} ,
  { A4GL_dttoc, NO, NO, NO, NO, NO, NO, A4GL_dt_to_d, NO,NO,A4GL_dttodt, NO, NO, NO, NO,NO} ,
  { NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, A4GL_btob, NO, NO, NO} ,
  { NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, A4GL_btob, NO, NO} ,
  { NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO} ,
  { A4GL_inttoc, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, A4GL_inttoint}
};



/*
=====================================================================
                    Functions definitions
=====================================================================
*/

#ifdef TEST

/**
 * Main function for convertion values testing.
 */
int
main (void)
{
  double rv, value;
  double rv2;
  char wrkbf[50];
  char wrkbf2[50];
  char wrkbf3[50];
  int a, b;
  int rc, x_sub, y_sub, size, len, digits;
  char *zzz;
  A4GL_init_dec (wrkbf, 30, 20);
  A4GL_init_dec (wrkbf2, 20, 6);
  A4GL_init_dec (wrkbf3, 20, 6);
  A4GL_str_to_dec ("1.0", wrkbf2);
  A4GL_str_to_dec ("0.01", wrkbf3);
  /*
     print_res(wrkbf2);
     print_res(wrkbf3);
     printf("Calculating\n");
   */
  dec_math (wrkbf2, wrkbf3, wrkbf, '*');
  /* printf("-9x-0.9 =%s\n",dec_to_str(wrkbf)); */

#ifdef EXERCISE
  exercise ();
  print_res_l (0, '0');
#endif


  A4GL_debug ("0.00003 %s\n", A4GL_dec_to_str (A4GL_inv (A4GL_str_to_dec ("0.00003", 0))));
  A4GL_debug ("0.0003 %s\n", A4GL_dec_to_str (A4GL_inv (A4GL_str_to_dec ("0.0003", 0))));
  A4GL_debug ("0.003 %s\n", A4GL_dec_to_str (A4GL_inv (A4GL_str_to_dec ("0.003", 0))));
  A4GL_debug ("0.03 %s\n", A4GL_dec_to_str (A4GL_inv (A4GL_str_to_dec (".03", 0))));
  A4GL_debug ("0.3 %s\n", A4GL_dec_to_str (A4GL_inv (A4GL_str_to_dec (".30", 0))));
  A4GL_debug ("3 %s\n", A4GL_dec_to_str (A4GL_inv (A4GL_str_to_dec ("3.0", 0))));
  A4GL_debug ("30 %s\n", A4GL_dec_to_str (A4GL_inv (A4GL_str_to_dec ("30.0", 0))));
  A4GL_debug ("300 %s\n", A4GL_dec_to_str (A4GL_inv (A4GL_str_to_dec ("300.0", 0))));
  A4GL_debug ("3000 %s\n", A4GL_dec_to_str (A4GL_inv (A4GL_str_to_dec ("3000.0", 0))));
  A4GL_debug ("30000 %s\n", A4GL_dec_to_str (A4GL_inv (A4GL_str_to_dec ("30000.0", 0))));
  A4GL_debug ("300000 %s\n", A4GL_dec_to_str (A4GL_inv (A4GL_str_to_dec ("300000.0", 0))));
  exit (0);
  A4GL_inv (A4GL_str_to_dec ("1.0", 0));
  A4GL_inv (A4GL_str_to_dec ("2.0", 0));
  A4GL_inv (A4GL_str_to_dec ("3.0", 0));
  A4GL_inv (A4GL_str_to_dec ("4.0", 0));
  A4GL_inv (A4GL_str_to_dec ("5.0", 0));
  A4GL_inv (A4GL_str_to_dec ("6.0", 0));
  A4GL_inv (A4GL_str_to_dec ("7.0", 0));
  A4GL_inv (A4GL_str_to_dec ("8.0", 0));
  A4GL_inv (A4GL_str_to_dec ("9.0", 0));
  A4GL_inv (A4GL_str_to_dec ("10.0", 0));
  A4GL_inv (A4GL_str_to_dec ("11.0", 0));
  A4GL_inv (A4GL_str_to_dec ("12.0", 0));
  A4GL_inv (A4GL_str_to_dec ("13.0", 0));
  A4GL_inv (A4GL_str_to_dec ("14.0", 0));
  A4GL_inv (A4GL_str_to_dec ("15.0", 0));
  A4GL_inv (A4GL_str_to_dec ("16.0", 0));
  A4GL_inv (A4GL_str_to_dec ("32.0", 0));
  A4GL_inv (A4GL_str_to_dec ("64.0", 0));
}

#endif

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

  A4GL_debug ("inttoint\n");
  d = b;
  e = a;
  A4GL_debug ("e->stime=0x%x e->ltime=0x%x", e->stime, e->ltime);
  A4GL_inttoc (a, buff, 60);
  A4GL_trim (buff);
  A4GL_debug ("Got Interval as : '%s'\n", buff);
  return A4GL_ctoint (buff, b, size);

/*
#ifdef DEBUG
  inttoc(a,buff,40);
	A4GL_debug(" Buff=%s\n",buff);
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
  //int c;
  int cnt;
  //int cpc;
  //int c2;
  int data[10];
  int nfrac=0;
  char buff[256];
  char buff2[256];
  //             0   1   2   3   4   5   6
  char *pre[] = { " ", "-", "-", " ", ":", ":", "." };


  //int spc[] = { 0, 4, 2, 2, 2, 2, 2, 5 };
  a = a1;


  A4GL_decode_interval (a, data);

  A4GL_debug ("Y: %d", data[0]);	// -
  A4GL_debug ("M: %d", data[1]);	// -
  A4GL_debug ("D: %d", data[2]);	// ' '
  A4GL_debug ("H: %d", data[3]);	// :
  A4GL_debug ("M: %d", data[4]);	// :
  A4GL_debug ("S: %d", data[5]);	// .
  A4GL_debug ("F: %d", data[6]);	// 

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
      if (cnt == 7)
	{
	  sprintf (buff2, "%05d", data[cnt - 1]);
	  buff2[nfrac] = 0;
	}
      else
	{
	  sprintf (buff2, "%02d", data[cnt - 1]);
	}

      strcat (buff, buff2);

    }
  A4GL_debug ("-->%s\n", buff);
  A4GL_ctoc (buff, b, size);
  return 1;
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
  char localchar[56];

  strcpy (localchar, a_char);
  d = (struct ival *) b_int;

  A4GL_debug ("ctoint - %s size_b=%x\n", a_char, size_b);
  d->ltime = size_b & 15;
  d->stime = size_b >> 4;

  A4GL_debug ("Set d->stime=%d d->ltime=%d %p", d->stime, d->ltime, d);
  A4GL_debug ("Set d->stime=%d d->ltime=%d %p", d->stime, d->ltime, d);

  A4GL_debug ("CHECK0.01 :  d->stime=%d d->ltime=%d %p", d->stime, d->ltime, d);


  v1 = size_b & 15;
  A4GL_debug ("CHECK0.1 :  d->stime=%d d->ltime=%d", d->stime, d->ltime);
  v2 = (size_b >> 4) & 15;
  A4GL_debug ("CHECK0.2 :  d->stime=%d d->ltime=%d", d->stime, d->ltime);
  v3 = (size_b >> 8) & 15;

  A4GL_debug ("CHECK0 :  d->stime=%d d->ltime=%d", d->stime, d->ltime);

  A4GL_debug ("v1=%d v2=%d v3=%d\n", v1, v2, v3);

  if (A4GL_valid_int (localchar, data, size_b))
    {
      A4GL_debug ("CHECK1 :  d->stime=%d d->ltime=%d", d->stime, d->ltime);
      A4GL_conv_invdatatoc (data, v1, v2, v3, d);
      A4GL_debug ("CHECK2 :  d->stime=%d d->ltime=%d", d->stime, d->ltime);

      return 1;
    }
  else
    {
      return 0;
    }

  return 1;

  A4GL_debug ("ctoint\n");
  return 0;
}



int A4GL_d_to_dt(void *a,void *b,int size) {
	int d_y,d_m,d_d;
	char buff[20];
	A4GL_get_date (*(long *)a, &d_d, &d_m, &d_y );
	sprintf(buff,"%04d-%02d-%02d",d_y,d_m,d_d);
	return A4GL_ctodt(buff,b,size);

}

int 
A4GL_dt_to_d(void *a,void *b,int size) {
	struct A4GLSQL_dtime d;
	long rval;
	char buff[20];
	int d_y,d_m,d_d;

	// Copy our datetime in..
	if (A4GL_dttodt(a,&d,0x13)==0) return 0;
	A4GL_dttoc(&d,buff,14);
	
	sscanf(buff,"%d-%d-%d",&d_y,&d_m,&d_d);
	rval= A4GL_gen_dateno (d_d, d_m, d_y);
	*(long *)b=rval;

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

  if (d->stime >= 1 && d->stime <= 11);
  else
    {
      A4GL_assertion (1, "Start Time invalid on datetime (dttodt)");
    }

  if (d->ltime >= 1 && d->ltime <= 11);
  else
    {
      A4GL_assertion (1, "End Time invalid on datetime (dttodt)");
    }

  A4GL_debug ("dttodt %p %p %d a->stime=%d a->ltime=%d\n", a, b, size, d->stime,
	 d->ltime);

  if (size == -1)
    {
      A4GL_debug ("Mallocing new A4GLSQL_dtime");
      memcpy (b, a, sizeof (struct A4GLSQL_dtime));
      return 0;
    }



  A4GL_debug ("In A4GL_dttodt - calling A4GL_dttoc size=%x ", size);
  if (A4GL_dttoc (a, buff, 255))
    {
      d = b;
      A4GL_debug ("Got buff as : %s - size=%x\n", buff, size);
      d->stime = size / 16;
      d->ltime = size % 16;
      return A4GL_ctodt (buff, b, d->stime * 16 + d->ltime);
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
A4GL_ctodt (void *a, void *b, int size)
{
  int data[256];
  struct A4GLSQL_dtime *d;
  A4GL_debug ("ctodt : %p %p %d\n", a, b, size);
  A4GL_debug ("a-->%s\n", a);
  d = (struct A4GLSQL_dtime *) b;

  d->ltime = size % 16;
  d->stime = size >> 4;
  A4GL_debug ("d->ltime=%d d->stime=%d\n", d->ltime, d->stime);

  if (A4GL_valid_dt (a, data))
    {
      A4GL_debug ("Y %d\n", data[0]);
      A4GL_debug ("M %d\n", data[1]);
      A4GL_debug ("D %d\n", data[2]);
      A4GL_debug ("H %d\n", data[3]);
      A4GL_debug ("m %d\n", data[4]);
      A4GL_debug ("S %d\n", data[5]);
      A4GL_debug ("F %d\n", data[6]);

      sprintf (d->data, "%04d%02d%02d%02d%02d%02d%05d00000",
	       data[0], data[1], data[2], data[3], data[4], data[5], data[6]);

      return 1;
    }
  else
    {
      return 0;
    }

  return 1;

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

  A4GL_debug ("dttoc : %p %p %x\n", a, b, size);
  d = a;
  x = 0;

  //A4GL_debug ("d->stime=%d d->ltime=%d\n", d->stime, d->ltime, d->data);

  if (d->stime >= 1 && d->stime <= 11);
  else
    {
      A4GL_assertion (1, "Start Time invalid on datetime");
    }

  if (d->ltime >= 1 && d->ltime <= 11);
  else
    {
      A4GL_assertion (1, "End Time invalid on datetime");
    }

  for (cnt = d->stime - 1; cnt <= d->ltime - 1; cnt++)
    {
      //debug ("cnt=%d", cnt);
      //debug ("   pos=%d sizes=%d", pos[cnt], sizes[cnt]);
      strncpy (&buff[x], &d->data[pos[cnt]], sizes[cnt]);
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

  if (strlen (buff) > size)
    {
      A4GL_debug ("does not fit '%s' %d", buff, size);
      A4GL_exitwith ("does not fit\n");
      return 0;
    }

  A4GL_debug ("dttoc sets to '%s'", buff);

  strcpy (b, buff);
  return 1;
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
  lb->where = la->where;
  lb->f = la->f;
  lb->memsize = la->memsize;
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
  z = (short *) zi;
  a = (char *) aa;
  A4GL_trim (a);
  zz = strlen (a);
  errno = 0;
  *z = (short) strtol (a, &eptr, 10);


    if (eptr - a < zz) {
            A4GL_debug("Fail check 1 a=%p eptr=%p zz=%d",a,eptr,zz);
            strtod (a, &eptr);
            if (eptr - a < zz) {
                    return 0;
            }
            A4GL_debug("Close shave - its a float..");
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
  int zz;
  char *a;
  long *z;
  a = (char *) aa;
  z = (long *) zi;
  errno = 0;
  A4GL_trim (a);

  A4GL_debug("Processing %s",a);
  zz = strlen (a);
  *z = strtol (a, &eptr, 10);

  if (eptr - a < zz) {
	A4GL_debug("Fail check 1 a=%p eptr=%p zz=%d",a,eptr,zz);
  	strtod (a, &eptr);
  	if (eptr - a < zz) {
		A4GL_debug("OK");
    		return 0;
	}
	A4GL_debug("Close shave - its a float..");
  }


  if (errno != 0 || eptr[0] != 0 || eptr == a)
    {
	A4GL_debug("Fail check 2");
      return 0;
    }
		A4GL_debug("OK");
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
  char *eptr;
  int h;
  int t;
  char buff[256];
  h = size;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;
  A4GL_debug ("converting %s to a decimal (%x) %d,%d", a, size, h, t);
  A4GL_init_dec (z, h, t);
  sprintf (buff, "%016d", *(short *) a);

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
 * @param z A pointer to the pçace where to put the converted decimal value.
 * @param size
 * @return
 *   - 0 : An error as ocurred.
 *   - 1 : Convertion made.
 */
int
A4GL_ltodec (void *a, void *z, int size)
{
  char *eptr;
  int h;
  int t;
  char buff[256];
  h = size;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;

  A4GL_debug ("Size=%d - 0x%x\n", size, size);
  A4GL_debug ("a=%p %d", a, *(long *) a);
  A4GL_debug ("converting %d to a decimal (%x) %d,%d", *(long *) a, size, h, t);

  A4GL_init_dec (z, h, t);
  sprintf (buff, "%ld", *(long *) a);
  A4GL_debug ("Buff=%s\n", buff);
  eptr = A4GL_str_to_dec (buff, z);
  A4GL_debug ("eptr=%p\n", eptr);

  if (eptr)
    return 1;
  else
    return 0;
}

/**
 * Convert a float value to decimal.
 *
 * @param a The float value.
 * @param z A pointer to the place where to put the decimal value.
 * @param size
 * @return
 *   - 0 : Invalid value or error ocurred.
 *   - 1 : Value converted.
 */
int
A4GL_ftodec (void *a, void *z, int size)
{
  char *eptr;
  int ndig;
  int ndec;
  char buff[64];
  char fmt[16];

  ndig = size >> 8;
  ndec = size & 0xff;
  errno = 0;
  A4GL_init_dec (z, ndig, ndec);

  if (ndec >= 0)
    {
      // set format to the number of digits needed, to force round-off
      sprintf (fmt, "%%-32.%df", ndec);
    }
  else
    {
      strcpy (fmt, "%-32.16f");
    }
  sprintf (buff, fmt, *(double *) a);

  eptr = A4GL_str_to_dec (buff, z);

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
  char *eptr;
  int h;
  int t;
  char buff[256];
  h = size;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;
  A4GL_debug ("converting %s to a decimal (%x) %d,%d", a, size, h, t);
  A4GL_init_dec (z, h, t);
  sprintf (buff, "%32.16f", *(float *) a);
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
  char *eptr;
  int h;
  int t;
  char *buff;
  h = size;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;
  A4GL_debug ("converting %s to a decimal (%x) %d,%d", a, size, h, t);
  A4GL_init_dec (z, h, t);
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
  char *eptr;
  int h;
  int t;
  h = size;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;
  A4GL_debug ("converting %s to a decimal (%x) %d,%d", a, size, h, t);
  A4GL_init_dec (z, h, t);

  A4GL_debug ("After init\n");
  //A4GL_dump (z);
  eptr = A4GL_str_to_dec (a, z);
  //A4GL_dump (z);

  if (eptr)
    {
      return 1;
    }
  return 0;
}



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

  buff = A4GL_dec_to_str (z, size);

  A4GL_debug ("mdec_to_str -> '%s'\n", buff);

  strcpy(buff2,buff);
  A4GL_ltrim(buff2);

  A4GL_string_set (w, buff2, size);

  A4GL_debug ("w = %s\n", w);
  return 1;
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
  char buff[64];
  long *a;
  char *z;
  A4GL_debug ("mdectol");
  a = (long *) aa;
  z = (char *) zz;
  strcpy (buff, A4GL_dec_to_str (z, 0));
  return A4GL_stol (buff, a, 0);
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
  char buff[64];
  short *a;
  char *z;
  A4GL_debug ("mdectoi");
  a = (short *) aa;
  z = (char *) zz;
  strcpy (buff, A4GL_dec_to_str (z, 0));
  return A4GL_stoi (buff, a, 0);
}

/**
 * Convert a decimal value to double.
 *
 * @param zz The decimal value.
 * @param aa A pointer where to return the double value.
 * @param sz_ignore Not used.
 * @return 
 *   - 0 : Value invalid or error.
 *   - 1 : Value converted.
 */
int
A4GL_mdectod (void *zz, void *aa, int sz_ignore)
{
  char buff[64];
  long *a;
  char *z;
  a = (long *) aa;
  z = (char *) zz;
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
  char buff[64];
  char *z;
  double *a;
  a = (double *) aa;
  z = (char *) zz;

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
  char buff[64];
  char *z;
  float *a;
  z = (char *) zz;
  a = (float *) aa;
  strcpy (buff, A4GL_dec_to_str (z, 0));
  return A4GL_stof (buff, a, 0);
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
  A4GL_debug ("dec_to_str -> '%s'\n", buff);
  strcpy(buff2,buff);
  A4GL_ltrim(buff2);
  A4GL_string_set (w, buff2, size);

  A4GL_debug ("w = %s\n", w);


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
  double *z;
  char *p;
  char buff[32];
  int n;
int ok;

  //A4GL_debug ("stof aa = %s, zz = %f", aa, (double *) zz);
  a = (char *) aa;

  z = (double *) zz;
 *z=0;

  /* watch out for any "," separators in the number - remove them first */
  if (strchr (a, ','))
    {
      a = buff;
      for (n = 0, p = (char *) aa; *p > '\0' && n < 32; p++, n++)
	{
	  if (*p != ',')
	    *a++ = *p;
	}
      *a = '\0';
      a = buff;
    }

  ok=sscanf (a, "%lf", z);
  A4GL_debug ("stof: string %s ", a);
  A4GL_debug ("stof: float %lf", *z);
  A4GL_debug ("stof: OK=%d", ok);
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
  float *z;
  a = (char *) aa;
  z = (float *) zz;
  sscanf (a, "%f", z);
  return 1;
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
  static char buff[64];
  long *a;
  char *z;
int rval;
  A4GL_debug ("dectol");
  a = (long *) aa;
  z = (char *) zz;
  A4GL_debug ("dectol");
  A4GL_dectos (z, buff, 64);
  rval=A4GL_stol (buff, a, 0);
  A4GL_debug("rval=%d",rval);
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
  static char buff[64];
  short *a;
  char *z;
int rval;
  A4GL_debug ("dectoi");
  a = (short *) aa;
  z = (char *) zz;
  A4GL_dectos (z, buff, 64);
  A4GL_debug("--> %s\n",buff);

  rval=A4GL_stoi (buff, a, 0);

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
  char buff[64];
  long *a;
  char *z;
  a = (long *) aa;
  z = (char *) zz;
  A4GL_dectos (z, buff, 64);
  return A4GL_stol (buff, a, 0);
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
  char buff[64];
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
  A4GL_debug ("dtof");
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
  A4GL_debug ("ftod");
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
  static char dbdate[10] = "";	// holds current DBDATE value
  static int d_pos, m_pos, y_pos;	// relative positions of day/month/year
  char num[3][10];		// date numbers extracted from string
  char *p;
  int n;
  char *str;
  int *date;

  str = (char *) str_v;
  date = (int *) date_v;
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
	  if (isalpha (*p))
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
      if ((d_pos + m_pos + y_pos) != 3 || d_pos == m_pos ||
	  d_pos == y_pos || m_pos == y_pos)
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

  return ((*date = A4GL_gen_dateno (atoi (num[d_pos]), atoi (num[m_pos]), n))
	  != DATE_INVALID);
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
  return A4GL_dtos (a, z, 6);
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
  int *a;
  char *z;
  char *p;

  z = (char *) zz;
  a = (int *) aa;

#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("dtos date=%d %x", *a,*a);
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
  A4GL_pad_string (z, size);

#ifdef DEBUG
  /* {DEBUG} */
  {
    A4GL_debug ("Date = %s\n", z);
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
  char buff[256];
  local_a=*(short *)aa;
  local_a_int=local_a;

  z = (char *) zz;
  if (A4GL_digittoc (&local_a_int, z, fmt, DTYPE_SMINT, size))
    {
#ifdef DEBUG
      {
 A4GL_debug ("itoc return from A4GL_digittoc using %s", fmt);
      }
#endif
      sprintf (buff, fmt, local_a_int);
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
#ifdef DEBUG
  {
    A4GL_debug ("itol");
  }
#endif
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
  A4GL_itoc (a, z, c);
  return 1;
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
  char buff[256];
  z = (char *) zz;
  a = (long *) aa;
#ifdef DEBUG
  {
    A4GL_debug ("Size=%d", size);
  }
#endif
  if (A4GL_digittoc ((int *) a, z, fmt, DTYPE_INT, size))
    {
#ifdef DEBUG
      {
 A4GL_debug ("ltoc return from A4GL_digittoc using %s", fmt);
      }
#endif
      sprintf (buff, fmt, *(long *) a);
      if (strlen (buff) > size)
	{
	  memset (buff, '*', size);
	  buff[size] = 0;
	}
      strcpy (z, buff);
      A4GL_pad_string (z, size);
    }
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

  A4GL_debug ("ltof");
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
  A4GL_ltoc (a, z, c);
  return 1;
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
  char buff[256];
  a = (double *) aa;
  z = (char *) zz;

  strcpy (buff, "******************************************");
  if (A4GL_digittoc ((int *) a, z, fmt, DTYPE_FLOAT, c))
    {
      sprintf (buff, fmt, *a);
    }

  if (strlen (buff) > c)
    {
      // Its too long...
      strcpy (fmt, ".1f");
      if (A4GL_digittoc ((int *) a, z, fmt, DTYPE_FLOAT, c))
	{
	  sprintf (buff, fmt, *a);
	}
      if (strlen (buff) > c)
	{
	  strcpy (fmt, ".0f");
	  if (A4GL_digittoc ((int *) a, z, fmt, DTYPE_FLOAT, c))
	    {
	      sprintf (buff, fmt, *a);
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
      strcpy (z, buff);
    }


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
  double *a;
  short *z;
  z = (short *) zz;
  a = (double *) aa;
  *z = (short) *a;
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
  a = (double *) aa;
  z = (long *) zz;
  A4GL_debug ("ftol");
  *z = (long) *a;
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
  A4GL_ftoc (a, z, c);

  return 1;
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
  char buff[256];
  a = (float *) aa;
  z = (char *) zz;
  strcpy (buff, "******************************************");
  if (A4GL_digittoc ((int *) a, z, fmt, DTYPE_FLOAT, c))
    {
      sprintf (buff, fmt, *a);
    }

  if (strlen (buff) > c)
    {
      // Its too long...
      strcpy (fmt, ".1f");
      if (A4GL_digittoc ((int *) a, z, fmt, DTYPE_FLOAT, c))
	{
	  sprintf (buff, fmt, *a);
	}
      if (strlen (buff) > c)
	{
	  strcpy (fmt, ".0f");
	  if (A4GL_digittoc ((int *) a, z, fmt, DTYPE_FLOAT, c))
	    {
	      sprintf (buff, fmt, *a);
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
      strcpy (z, buff);
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
  z = (short *) zz;
  a = (float *) aa;
  *z = (short) *a;
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
  z = (long *) zz;
  a = (float *) aa;
  *z = (long) *a;
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
  A4GL_sftoc (a, z, c);
  return 1;
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
    //A4GL_debug ("--->Got size as %d", size);
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
    A4GL_debug ("ltol %ld %ld", *a, *b);
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
  int (*ptr) (void *ptr1, void *ptr2, int size);
  int rval;
  //A4GL_debug ("In conv.. d1=%d d2=%d size=%d", dtype1, dtype2, size);






  /* A4GL_debug ("Dtype1=%d p1=%p (%ld) ", dtype1, p1, *(int *) p1); */

  if (A4GL_isnull (dtype1&DTYPE_MASK, p1))
    {
      A4GL_debug ("First is null");
      A4GL_setnull (dtype2, p2, size);
      return 1;
    }

  if (dtype1 == 0 && dtype2 != 0)
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

  if ( ((dtype2&DTYPE_MASK) == DTYPE_DECIMAL || (dtype2&DTYPE_MASK) == DTYPE_MONEY ) && (size < 256))
    {
      //char*ptr=0;*ptr=0;
      // we don't know how many decimals are required, 4 should be ok
	A4GL_debug("DTYPE_DECIMAL fix in conv.c...");
      size += 8;
      if (size > 32)
	size = 32;
      size = size * 256 + 4;
      A4GL_debug ("conv: changing invalid decimal size to %d", size);
    }


  size_of_operand=DECODE_SIZE(dtype1);
#ifdef DEBUG
  {				/* A4GL_debug ("convert %d %p %d %p\n", dtype1, p1, dtype2, p2); */
  }
#endif

  ptr = convmatrix[dtype1 & DTYPE_MASK][dtype2 & DTYPE_MASK];

  A4GL_debug("ptr=%p",ptr);

  if (ptr == NO)
    {
      A4GL_debug ("No! - %d %d", dtype1, dtype2);



      setdtype[dtype2 & DTYPE_MASK] (p2);




      return -1;




    }

{
  A4GL_debug("dtype1=0x%x dtype2=0x%x",dtype1,dtype2);
  A4GL_debug("Masked : dtype1=%d dtype2=%d",dtype1&DTYPE_MASK,dtype2&DTYPE_MASK);
}

  rval = convmatrix[dtype1 & DTYPE_MASK][dtype2 & DTYPE_MASK] (p1, p2, size);

 {
  A4GL_debug("rval=%x\n",rval);
  }


  return rval;
}

/**
 * Assert if an expression is true.
 *
 * @param a The result of the expression:
 *   - 0 : The expression was true.
 *   - Otherwise : The expression was not true.
 * @param s The message if the expression is not true.
 */
void
A4GL_assertion (int a, char *s)
{
  if (a)
    {
      fflush (stdout);
      A4GL_set_errm (s);
      A4GL_debug ("%s", s);
      A4GL_exitwith ("Assertion failed %s");
      A4GL_chk_err (0, "Unknown");
      exit (0);
    }
}


/**
 * Convert a decimal value to double.
 *
 * @param The pointer to the decimal value.
 * @return The decimal value converted to double.
 */
double
A4GL_dec_to_double (void *buf)
{
  size_t len;
  int digits;
  double rv = 0.0;
  char *buffer = (char *) buf;
  size_t high, low, index, max;
  digits = NUM_DEC (buffer);
  len = NUM_BYTES (buffer);
  max = len - 1;
  digits = abs (digits);
  for (index = OFFSET_DEC (buffer); index < max; index++)
    {
      low = buffer[index] & 0x0f;
      high = (buffer[index] & 0xf0) >> 4;
      rv = ((rv * 10.0 + high) * 10.0 + low);
    }
  low = buffer[max] & 0x0f;
  high = (buffer[max] & 0xf0) >> 4;
  rv = rv * 10.0 + high + low;
  rv *= 10;
  if (digits > 0)
    rv /= pow ((double) 10, (double) digits);
  if (buffer[0] & 128)
    rv = -rv;
  return rv;
}

/**
 * Operations over decimal values.
 *
 * @param s 
 * @param w
 * @param r
 * @param op The operator:
 *   - * : Multiply.
 *   - / : Divide.
 *   - + : Adition.
 *   - - : Subtraction.
 * @return
 */
char *
dec_math (char *s, char *w, char *r, char op)
{
  int sn = 0;
  int wn = 0;
  char *z;
  if (s[0] & 128)
    sn = 1;
  if (w[0] & 128)
    wn = 1;

  A4GL_trim_dec (s);
  A4GL_trim_dec (w);

  if (sn == wn)
    {

      if (op == '*')
	{
	  if (sn == 1)
	    {
	      A4GL_negate (s);
	      A4GL_negate (w);
	    }
	  A4GL_dec_to_dec (A4GL_mult_dec (s, w), r);
	  return r;
	}

      if (op == '/')
	{
	  if (sn == 1)
	    {
	      A4GL_negate (s);
	      A4GL_negate (w);
	    }
	  A4GL_dec_to_dec (A4GL_divide_dec (s, w), r);
	  return r;

	}

      if (op == '+')
	{

	  z = A4GL_add_dec (s, w);
	  A4GL_dec_to_dec (z, r);
	}

      if (op == '-')
	{
	  if (sn)
	    {
	      /* -n1 - -n2 = -n1 + n2 = n2 - n1  */
	      A4GL_negate (w);
	      A4GL_negate (s);
	      z = A4GL_minus_dec (w, s);
	      A4GL_dec_to_dec (z, r);
	      return r;
	    }
	  else
	    {
	      z = A4GL_minus_dec (s, w);
	      A4GL_dec_to_dec (z, r);
	      return r;
	    }
	}

      if (sn == 1)
	{

	  A4GL_negate (r);

	}
      return r;
    }


  if (sn)
    {
      if (op == '*')
	{

	  A4GL_negate (s);

	  A4GL_dec_to_dec (A4GL_mult_dec (s, w), r);

	  A4GL_negate (r);

	}

      if (op == '+')
	{

	  A4GL_dec_to_dec (A4GL_minus_dec (w, s), r);

	}
      if (op == '-')
	{

	  A4GL_dec_to_dec (A4GL_add_dec (s, w), r);

	  A4GL_negate (r);

	}
      return r;
    }
  if (wn)
    {
      if (op == '*')
	{

	  A4GL_negate (w);

	  A4GL_dec_to_dec (A4GL_mult_dec (s, w), r);

	  A4GL_negate (r);

	}
      if (op == '+')
	{

	  A4GL_dec_to_dec (A4GL_minus_dec (s, w), r);

	}
      if (op == '-')
	{

	  A4GL_dec_to_dec (A4GL_add_dec (s, w), r);

	}
      return r;
    }
  return 0;
}

/**
 * Convert a value from double to decimal.
 *
 * @param  arg  the double value
 * @param  buf  pointer to the decimal
 * @param  length of decimal
 * @param  number of decimal digits
 * @return void
 */
void
A4GL_double_to_dec (double arg, char *buf, size_t length, size_t digits)
{
  char wrkbuf[DBL_DIG1], format[DBL_DIG1];
  A4GL_init_dec (buf, length, digits);
  sprintf (format, "%%-%d.%dlf", length, digits);
  sprintf (wrkbuf, format, arg);
  A4GL_str_to_dec (wrkbuf, buf);
}


/**
 * Copy a decimal value, converting where necessary if the source
 * and destination have different lengths and decimal places.
 *
 * @param f pointer to the value to be copied.
 * @param t pointer to the place where to copy the decimal value.
 * @return void
 */
void
A4GL_dec_to_dec (char *f, char *t)
{
  int l, lt;
  int d, ld;
  int x, y, c;
  char buff[64];

  A4GL_debug ("dec_to_dec");
  A4GL_dump (f);
  A4GL_dump (t);

  A4GL_trim_dec (f);

  A4GL_dump (f);

  l = NUM_DIG (f);
  d = NUM_DEC (f);

  if (t[0] & 128)
    t[0] = t[0] - 128;
  lt = NUM_DIG (t);
  ld = NUM_DEC (t);

  if (ld < d && d > 0)
    {
      // target has fewer decimal places - do we need to round off ?
      // we need only do this if the rounding might be upward on the
      // last decimal digit, ie. check if the next digit is 5 or more
      c = 0;
      x = l + OFFSET_DEC (f) - (d % 2 == 0 ? d / 2 : (d + 1) / 2);
      if (ld % 2 == 0)
	{
	  if ((f[x + (ld / 2)] & 0xf0) >= 0x50)
	    c = 1;
	}
      else
	{
	  if ((f[x + (ld - 1) / 2] & 0x0f) >= 0x05)
	    c = 1;
	}
      A4GL_debug ("rounding = %d", c);
      if (c)
	{
	  // use a rounded copy of the source decimal
	  A4GL_debug("copying %d bytes\n", NUM_BYTES (f));
	  memcpy (buff, f, NUM_BYTES (f));
	  A4GL_dec_roundoff (buff, ld);
	  f = buff;
	}
    }

  x = 0;
  y = 0;
  x = (l * 2 - lt * 2 - d + ld) / 2;

  if (x < 0)
    {
      y = 0 - x;
      x = 0;
    }

  c = lt - x;
  c = lt;

  if (c > l)
    c = l;

  if (c < 0)
    {
      A4GL_debug ("Too small\n");
      A4GL_pr (f);
      A4GL_pr (t);
      exit (0);
      return;
    }

  A4GL_debug ("lt=%d c=%d\n", lt, c);

  memset (&t[OFFSET_DEC (t)], 0, lt);

  memcpy (&t[y + OFFSET_DEC (t)], &f[x + OFFSET_DEC (f)], c);

  if (f[0] & 128)
    A4GL_negate (t);

  A4GL_dump (t);
}

/**
 * Convert a string to decimal.
 *
 * @param s The string value to be copied.
 * @param w A pointer to the place where to put the decimal value.
 */
char *
A4GL_str_to_dec (char *s, char *w)
{
  int cnt;
  char hd[DBL_DIG1];
  int hdcnt = 0;
  char tl[DBL_DIG1];
  int tlcnt = 0;
  int dp = 0;
  int neg = 0;
  char buff[DBL_DIG1];
  int a;

  memset (hd, 0, DBL_DIG1 - 1);
  memset (tl, 0, DBL_DIG1 - 1);
  for (cnt = 0; cnt < strlen (s); cnt++)
    {
      if (s[cnt] == '.')
	{

	  dp++;
	  if (dp > 1) return 0;
	  continue;
	}

      if (s[cnt] == '+' || s[cnt] == ',' || s[cnt] == ')')
	continue;
      if (s[cnt] == '-' || s[cnt] == '(')
	{
	  neg = 1;
	  continue;
	}
      if (s[cnt] >= '0' && s[cnt] <= '9')
	{

	  if (dp)
	    tl[tlcnt++] = s[cnt];

	  else
	    hd[hdcnt++] = s[cnt];
	 continue;

	}

	if (s[cnt]==' ') {
		int a;
		if (tlcnt==0&&hdcnt==0) continue; // leading space..
		for (a=cnt+1;a<strlen(s);a++) {
			if (s[a]!=' ') return 0; // Nope - there is something after it
		}
		break; // just trailing spaces
	}

	// If we've got to here - I've got a character I'm not expecting...
	A4GL_debug("Can a decimal have a '%c' (%d) in it ?",s[cnt],s[cnt]);
	return 0;
    }


  if (hdcnt % 2 == 1)
    {
      strcpy (buff, "0");
      strcat (buff, hd);
      strcpy (hd, buff);
      hdcnt++;
    }

  if (tlcnt % 2 == 1)
    {
      strcat (tl, "0");
      tlcnt++;
    }

  A4GL_debug ("Head : %s (%d) tail %s(%d) \n", hd, hdcnt, tl, tlcnt);

  A4GL_init_dec (buff, (hdcnt + tlcnt), tlcnt);
  cnt = OFFSET_DEC (buff);

  A4GL_debug ("Cnt = %d\n", cnt);

  for (a = 0; a < hdcnt; a += 2)
    {
      buff[cnt] = HEX_VAL ((hd[a] - '0') * 10 + (hd[a + 1] - '0'));
      cnt++;
    }

  for (a = 0; a < tlcnt; a += 2)
    {
      buff[cnt] = HEX_VAL ((tl[a] - '0') * 10 + (tl[a + 1] - '0'));
      cnt++;
    }

  if (w == 0)
    {
      w = A4GL_init_dec (w, (hdcnt + tlcnt), tlcnt);
    }

  A4GL_dec_to_dec (buff, w);
  if (neg)
    {
      A4GL_debug ("NEGATE...");
      A4GL_negate (w);
    }
  return w;
}

/**
 * For debuging purpose only.
 *
 * Print each element of a string in hexadecimal.
 * 
 * @param wrkbf The buffer with the information to be printed to debug.
 */
void
A4GL_pr (char *wrkbf)
{
  int rc;
  int y_sub;
  rc = NUM_DIG (wrkbf);
  for (y_sub = 0; y_sub <= rc + 1; y_sub++)
    A4GL_debug ("%02X ", wrkbf[y_sub] & 0xff);
  A4GL_debug ("\n");
}

/**
 * 
 * @param f
 * @param t
 * @param a
 * @param b
 */
static void
match_dec (char *f, char *t, int *a, int *b)
{
  int l, lt;
  int d, ld;
  int x, y, c;
  int c2;
  l = NUM_DIG (f);
  d = NUM_DEC (f);
  lt = NUM_DIG (t);
  ld = NUM_DEC (t);
  x = l * 2 - d;
  y = lt * 2 - ld;
  if (x > y)
    c = x;
  else
    c = y;
  if (d > ld)
    c2 = d;
  else
    c2 = ld;
  c += c2;
  *a = c;
  *b = c2;
}

/**
 * Add two decimal values.
 *
 * @param a The first part of the sum.
 * @param b The second part of the sum.
 * @return The result of the adition in string mode.
 */
char *
A4GL_add_dec (char *a, char *b)
{
  static char wrkbuf[3][DBL_DIG1];
  int xlen, xdig;
  int cnt;
  int n1, n2;
  int carry = 0;
  int acc;
  match_dec (a, b, &xlen, &xdig);
  memset (wrkbuf[0], 0, DBL_DIG1 - 1);
  memset (wrkbuf[1], 0, DBL_DIG1 - 1);
  memset (wrkbuf[2], 0, DBL_DIG1 - 1);
  A4GL_double_to_dec (0, wrkbuf[0], xlen + 2, xdig);
  A4GL_double_to_dec (0, wrkbuf[1], xlen + 2, xdig);
  A4GL_double_to_dec (0, wrkbuf[2], xlen + 2, xdig);
  A4GL_dec_to_dec (a, wrkbuf[0]);
  A4GL_dec_to_dec (b, wrkbuf[1]);
  for (cnt = xlen / 2 + 2; cnt >= OFFSET_DEC (wrkbuf[0]); cnt--)
    {
      n1 = DEC_VAL (wrkbuf[0][cnt]);
      n2 = DEC_VAL (wrkbuf[1][cnt]);
      acc = n1 + n2 + carry;

      if ((acc) >= 100)
	{
	  carry = acc;
	  acc = acc % 100;
	  carry -= acc;
	  carry = carry / 100;
	}
      else
	{
	  carry = 0;
	}
      wrkbuf[2][cnt] = HEX_VAL (acc);
    }
  return wrkbuf[2];
}

/**
 * Change the signal of a value in a string.
 *
 * The value is modified directly.
 *
 * @param s The value to be negated.
 */
void
A4GL_negate (char *s)
{
  if ((s[0] & 128) == 1)
    s[0] = s[0] - 128;
  else
    s[0] = s[0] + 128;
}

/**
 * Convert a decimal to string.
 *
 * @param s The decimal value
 * @param size
 * @return
 */
char *
A4GL_dec_to_str (char *s, int size)
{
  int l, d;
  int c, x, k;
 int a;
  static char buff[DBL_DIG1];
//int h,t;
  int dot_printed = -1;
  int blank = 0;
  char buff2[200];
  int ok;

  if (A4GL_isnull (DTYPE_DECIMAL, s)) {
	strcpy(buff,"");
	return buff;
  }
  l = NUM_DIG (s);		// length of decimal in bytes
  d = NUM_DEC (s);		// number of digits to right of decimal point
  // calculate starting position (bytes) of decimal point


/*
  h = size_of_operand;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;
  if (h!=l || d!=t) {
	A4GL_debug("Looks like an uninitialize decimal...");
  	A4GL_init_dec (s, h, t);
  	l = NUM_DIG (s);		// length of decimal in bytes
  	d = NUM_DEC (s);		// number of digits to right of decimal point
  }
*/


  if (d<0) {
	char *ptr=0;
	*ptr=0;
  }
  x = l + OFFSET_DEC (s) - (d % 2 == 0 ? d / 2 : (d + 1) / 2);


  if (size<=0) size=l+1;

  A4GL_debug ("dec_to_str l=%d d=%d\n", l, d);
  //dump(s);

  if (l == 0 && d == 0)
    {
      l = size & 256;
      d = size % 256;
      A4GL_debug ("**** CHECK THIS - IT LOOKS WRONG, l=%d d=%d\n", l, d);
    }

  memset (buff, 0, DBL_DIG1 - 1);
  c = 0;

  // a negative decimal has first bit set
  if (s[0] & 128)
    {
      buff[c++] = '-';
    }

  // skip initial 2-byte 'header' and leading zero bytes before dec. point
  a = OFFSET_DEC (s);
  while (s[a] == 0 && a < x)
    {
      blank += 2;
      a++;
    }

  // scan digits (0-9) of number, packed two per byte/char
  for (; a <= l + 1; a++)
    {
      if (a == x)
	{
	  // insert decimal point, and a leading zero if needed
	  if (c == 0 || buff[c - 1] == '-')
	    buff[c++] = '0';
	  dot_printed = c;
	  buff[c++] = '.';
	}

      // extract decimal as a 2-digit number ( 00 - 99 ) 
      k = DEC_VAL (s[a]);

      // append ascii char for left-hand digit, unless
      // it's an unecessary leading zero
      buff[c] = ((int) k / 10) + '0';
      if (buff[c] == '0' && (c == 0 || buff[c - 1] == '-'))
	{
	  blank++;
	  buff[c] = 0;
	}
      else
	c++;

      // similarly for right-hand digit
      buff[c] = (int) k % 10 + '0';
      if (buff[c] == '0' && (c == 0 || buff[c - 1] == '-'))
	{
	  blank++;
	  buff[c] = 0;
	}
      else
	c++;
    }

  if (dot_printed && d % 2 == 1)
    {
      buff[dot_printed + d + 1] = 0;
    }
  memset (buff2, ' ', 199);
  buff2[blank] = 0;
  strcat (buff2, buff);
  strcpy (buff, buff2);
  A4GL_debug("99 size=%d blank=%d",size,blank);
  //if (!dot_printed) {
	ok=0;
	for (a=0;a<strlen(buff);a++) {
		if (buff[a]!=' ') {ok=1;break;}
	}
	if (ok==0) {
		buff[strlen(buff)-1]='0';
	}
  //}

  A4GL_debug ("returning: %s - blank=%d\n", buff, blank);
  return buff;
}

/**
 * Make a subtraction between two decimal values.
 * 
 * @param a The left value.
 * @param b The right value.
 * @return The result of the subtraction
 */
char *
A4GL_minus_dec (char *a, char *b)
{
  static char wrkbuf[3][DBL_DIG1];
  static char cbuff[DBL_DIG1];
  int xlen, xdig;
  int cnt;
  int n1, n2;
  int carry = 0;
  int acc;
  int neg = 0;
  match_dec (a, b, &xlen, &xdig);
  memset (wrkbuf[0], 0, DBL_DIG1 - 1);
  memset (wrkbuf[1], 0, DBL_DIG1 - 1);
  memset (wrkbuf[2], 0, DBL_DIG1 - 1);
  A4GL_double_to_dec (0, wrkbuf[0], xlen + 1, xdig);
  A4GL_double_to_dec (0, wrkbuf[1], xlen + 1, xdig);
  A4GL_double_to_dec (0, wrkbuf[2], xlen + 1, xdig);
  A4GL_dec_to_dec (a, wrkbuf[0]);
  A4GL_dec_to_dec (b, wrkbuf[1]);
  cnt =
    memcmp (&wrkbuf[0][OFFSET_DEC (wrkbuf[0])],
	    &wrkbuf[1][OFFSET_DEC (wrkbuf[1])], NUM_DIG (wrkbuf[0]));
  if (cnt < 0)
    {
      A4GL_dec_to_dec (wrkbuf[0], wrkbuf[2]);
      A4GL_dec_to_dec (wrkbuf[1], wrkbuf[0]);
      A4GL_dec_to_dec (wrkbuf[2], wrkbuf[1]);
      neg = 1;
    }
  memset (wrkbuf[2], 0, DBL_DIG1 - 1);
  A4GL_double_to_dec (0, wrkbuf[2], xlen + 1, xdig);
  for (cnt = xlen / 2 + 1; cnt >= OFFSET_DEC (wrkbuf[2]); cnt--)
    {
      n1 = DEC_VAL (wrkbuf[0][cnt]);
      n2 = DEC_VAL (wrkbuf[1][cnt]);
      acc = n1 - n2 - carry;
      /*
       */

      if ((acc) < 0)
	{

	  acc = (100 + acc);

	  carry = 1;

	}
      else
	{

	  carry = 0;

	}
      cbuff[cnt] = carry;

      wrkbuf[2][cnt] = HEX_VAL (acc);
    }
  if (neg)
    A4GL_negate (wrkbuf[2]);
  return wrkbuf[2];
}

/**
 *
 * @param s
 * @param len
 * @param d
 * @return A pointer to the value alocated.
 */
char *
A4GL_init_dec (char *s, int len, int d)
{
  A4GL_debug ("init_dec len=%d,d=%d", len, d);
  if (len % 2 == 1)
    len++;			/* This was missing - odd number decimals wouldn't allocate the right space! */


  if (s == 0)
    {
	A4GL_debug("Alloc some space");
      s = malloc (len + OFFSET_DEC (s));
    }

  A4GL_debug("memset - %p 0 %d",s,len+OFFSET_DEC(s));

  memset (s, 0, len + OFFSET_DEC (s));
  SET_DIG (s, len / 2);
  SET_DEC (s, d);
  A4GL_dump (s);
  return s;
}



/**
 * Make a multiplication between two decimal values.
 *
 * @param s The left factor.
 * @param s The rigth factor.
 * @return The result of the multiplication.
 */
char *
A4GL_mult_dec (char *s, char *v)
{
  int c1, c2;
  static char buff[DBL_DIG1 * 2 + 1];
  static char buff2[DBL_DIG1 + 1];
  static char buff3[DBL_DIG1 + 1];
  static char sumation[DBL_DIG1 + 1];

  int acc;
  int carry;
  int cnt;
  int md, ml;
  int loopcnt = 0;
  md = NUM_DEC (s) + NUM_DEC (v);
  ml = (NUM_DIG (s) + NUM_DIG (v));
  A4GL_init_dec (buff2, ml * 2, 0);
  A4GL_init_dec (sumation, ml * 2, 0);
  A4GL_str_to_dec ("0", buff2);
  A4GL_str_to_dec ("0", sumation);
  SET_DEC (buff2, 0);
  for (c1 = NUM_DIG (s) - 1; c1 >= 0; c1--)
    {
      memset (buff, 0, sizeof (buff));
      cnt = DBL_DIG1;
      /* cnt = 0; */
      carry = 0;
      for (c2 = NUM_DIG (v) - 1; c2 >= 0; c2--)
	{
	  acc =
	    DEC_VAL (s[c1 + OFFSET_DEC (s)]) *
	    DEC_VAL (v[c2 + OFFSET_DEC (v)]) + carry;

	  if (acc >= 100)
	    {
	      carry = acc;
	      acc = carry % 100;
	      carry = (carry - acc) / 100;
	    }
	  else
	    {
	      carry = 0;
	    }
	  buff[cnt] = HEX_VAL (acc);
	  cnt--;
	}

      if (carry)
	buff[cnt--] = HEX_VAL (carry);
      memset (buff3, 0, sizeof (buff3));
      memcpy (&buff3[OFFSET_DEC (buff3)], &buff[cnt + 1], DBL_DIG1 - cnt);
      buff3[0] = (DBL_DIG1 - cnt + loopcnt);
      loopcnt++;

      SET_DEC (buff3, 0);

      A4GL_init_dec (sumation, ml * 2, 0);
      dec_math (buff3, buff2, sumation, '+');
      memcpy (buff2, sumation, NUM_BYTES (sumation));
    }

  SET_DEC (buff2, md);
  return buff2;
}

/*
 * Round a decimal number to a given number of decimal places
 *
 * @param s  pointer to the decimal to be rounded
 * @param n  number of decimal places required
 * @return   1 if rounded ok,  0 if failed (overflow)
*/
int
A4GL_dec_roundoff (char *s, int n)
{
  int l, d, i, c, k;
  char buff[DBL_DIG1];
int m;

  l = NUM_DIG (s);		// length of decimal in bytes
  d = NUM_DEC (s);		// number of decimal places

  A4GL_debug("A4GL_dec_roundoff - %d",n);
  // we can only round off to fewer decimals than we have
  if (n >= d) {
    A4GL_debug("Round off lower..");
    return 0;
  }

  // copy the decimal digits to a char buffer - ignore sign and dec. point
  memset (buff, 0, DBL_DIG1 - 1);
  c = 0;
  for (i = OFFSET_DEC (s); i <= l + 1; i++)
    {
      k = DEC_VAL (s[i]);
      buff[c++] = ((int) k / 10) + '0';
      buff[c++] = (int) k % 10 + '0';
    }

  A4GL_debug("Buff=%s\n",buff);

  // round off number in the char buffer
  m = l * 2 -d +n;
  for (k=m+1;k<l*2;k++) {
	buff[k]=0;
  }

  A4GL_debug("Total digits : %d decimals %d new decimals %d",m,d,n);
  A4GL_debug("m=%d l-d+n=%d buff[m]=%c",m,(l*2)-d+n,buff[m]);
  while (m > 0 && buff[m] >= '5')
    {
      buff[m] = '0';
	m--;
      if (buff[m] < '9')
	{
	  buff[m] += 1;
	  break;
	}
      buff[m] = '9';
    }

  A4GL_debug("Buff now=%s n=%d\n",buff,n);
  // test for an overflow - we cannot round in that case
  if (m < 1 && buff[0] == '0') {
	A4GL_debug("Overflow...");
    return 0;
  }

  // write rounded result back to decimal number
  i = OFFSET_DEC (s);
  for (c = 0; c <= strlen (buff); c += 2)
    {
      s[i++] = HEX_VAL ((buff[c] - '0') * 10 + (buff[c + 1] - '0'));
    }

  return 1;
}


#ifdef TEST

/**
 * For testing purpose.
 *
 * Make some examples of decimal expressions.
 */
static void
exercise (void)
{
  char buffx[DBL_DIG1];
  char buffy[DBL_DIG1];
  char buffz[DBL_DIG1];
  double x;
  int xi, yi;
  double y;
  double z;
  double z2 = 0;
  char tb1[20];
  char tb2[20];
  A4GL_init_dec (buffx, 20, 6);
  A4GL_init_dec (buffy, 20, 6);
  A4GL_init_dec (buffz, 30, 20);

  for (z = 2; z <= 2; z++)
    {
      for (xi = -99; xi <= 100; xi += 1)
	{

	  for (yi = -100; yi <= 100; yi += 1)
	    {

	      x = (double) xi / (double) 10;

	      y = (double) yi / (double) 10;

	      A4GL_double_to_dec (x, buffx, 20, 8);
	      A4GL_double_to_dec (y, buffy, 20, 8);

	      /* printf("x=%lf ",x);debug("%s ",dec_to_str(buffx));debug("y=%lf ",y);debug("%s\n",dec_to_str(buffy)); */
	      if (z == 0)
		dec_math (buffx, buffy, buffz, '+');

	      if (z == 1)
		dec_math (buffx, buffy, buffz, '-');

	      if (z == 2)
		dec_math (buffx, buffy, buffz, '*');

	      if (z == 3)
		{
		  if (y == 0)
		    continue;

		  dec_math (buffx, buffy, buffz, '/');
		}

	      if (z == 0)
		{

		  z2 = x + y;

		}

	      if (z == 1)
		{

		  z2 = x - y;

		}

	      if (z == 2)
		{
		  z2 = x * y;
		}

	      if (z == 3)
		{
		  z2 = x / y;
		}

	      sprintf (tb1, "%10.2f", A4GL_dec_to_double (buffz));

	      sprintf (tb2, "%10.2f", z2);

	      if (strcmp (tb1, "     -0.00") == 0)
		{

		  sprintf (tb1, "      0.00");

		}

	      if (strcmp (tb2, "     -0.00") == 0)
		{

		  sprintf (tb2, "      0.00");

		}

	      if (strcmp (tb1, tb2) != 0)
		{

		  A4GL_debug ("**********************\n x=%lf", x);

		  A4GL_debug (" y=%lf ", y);

		  if (z == 0)
		    {

		      A4GL_debug ("(+)");

		    }

		  if (z == 1)
		    {

		      A4GL_debug ("(-)");

		    }

		  if (z == 2)
		    {
		      A4GL_debug ("(*)");
		    }
		  if (z == 3)
		    {
		      A4GL_debug ("(/)");
		    }

		  A4GL_debug (" fix='%s' float='%s'\n", tb1, tb2);

		}

	      /* pr(buffz); */
	    }

	}
    }
}

#endif /* #ifdef TEST */

/**
 *
 * @param a The decimal value.
 */
void
A4GL_trim_dec (char *s)
{
  int a;
  int cnt = 0;
  int f;
  char hold[1024];
  int neg = 0;

  if (SIGNED (s))
    neg = 1;

  if (NUM_DEC (s) > 0)
    {

      for (a = 0; a <= NUM_DEC (s) / 2; a++)
	{

	  f = NUM_DIG (s);

	  f = f + OFFSET_DEC (s);

	  f = f - a - 1;

	  if (s[f] == 0)
	    {
	      cnt++;
	    }
	  else
	    {
	      break;
	    }

	}

      if (cnt)
	{
	  SET_DEC (s, NUM_DEC (s) - cnt * 2);
	  SET_DIG (s, NUM_DIG (s) - cnt);
	}

    }
  cnt = -1;
  for (a = 0; a <= NUM_DIG (s); a++)
    {
      if (s[a + OFFSET_DEC (s)] != 0)
	break;
      cnt = a;
    }
  if (cnt > 0)
    {
      if (cnt >= NUM_DIG (s))
	cnt = NUM_DIG (s) - 2;
      a = NUM_BYTES (s) - cnt;
      memcpy (hold, &s[cnt + 1 + OFFSET_DEC (s)], a);
      memcpy (&s[OFFSET_DEC (s)], hold, NUM_DIG (s) - cnt - 1);
      SET_DIG (s, NUM_DIG (s) - 1 - cnt);
    }
  if (neg)
    A4GL_negate (s);
}


/**
 *
 * @todo Describe function
 */
char *
A4GL_inv (char *s)
{
  char buff[DBL_DIG1];
  static char buffers[8][DBL_DIG1];
  char mult_by[512];
  char mpoint01[512];
  static char tmpbuff[512];
  int counter = 0;
  int d;
  int a;
  int flg;
  double p = 0;
  memcpy (buff, s, NUM_BYTES (s));
  A4GL_init_dec (mult_by, 64, 32);
  A4GL_init_dec (tmpbuff, 64, 32);
  A4GL_str_to_dec ("1.00", mult_by);
  A4GL_init_dec (mpoint01, 4, 2);
  A4GL_str_to_dec ("0.01", mpoint01);

  d = NUM_DEC (buff);

  A4GL_init_dec (tmpbuff, 64, 32);
  if (NUM_DIG (buff) > NUM_DEC (buff))
    {
      SET_DEC (buff, NUM_DIG (buff) * 2 - 2);

      for (a = d; a < NUM_DIG (buff); a++)
	{
	  A4GL_init_dec (mpoint01, 4, 2);
	  A4GL_str_to_dec ("0.01", mpoint01);
	  A4GL_init_dec (tmpbuff, 64, 32);
	  dec_math (mult_by, mpoint01, tmpbuff, '*');
	  A4GL_init_dec (mult_by, 64, 32);
	  A4GL_dec_to_dec (tmpbuff, mult_by);
	}
    }

  A4GL_init_dec (buffers[0], 2, 0);
  A4GL_init_dec (buffers[1], 64, 32);
  A4GL_init_dec (buffers[2], 64, 32);
  A4GL_init_dec (buffers[3], 64, 32);
  A4GL_init_dec (buffers[4], 64, 32);
  flg = 0;
  for (a = 0; a <= NUM_DEC (buff); a++)
    {
      p = DEC_VAL (buff[OFFSET_DEC (buff) + a]);
      if (p != 0)
	{
	  p = 1.0 / p;
	  flg = 1;
	  break;
	}
    }
  if (flg == 0)
    {
      A4GL_debug ("Divide by zero\n");
      exit (0);
    }
  A4GL_double_to_dec (p, buffers[1], 32, 16);
  A4GL_str_to_dec ("2.0", buffers[0]);
  A4GL_str_to_dec ("0", buffers[3]);

  for (a = 1; a <= 400; a++)
    {
      counter++;
      A4GL_init_dec (buffers[4], 64, 32);

      dec_math (buffers[1], buff, buffers[4], '*');
      A4GL_init_dec (buffers[2], 64, 32);
      A4GL_init_dec (buffers[0], 4, 0);
      A4GL_str_to_dec ("2.0", buffers[0]);
      dec_math (buffers[0], buffers[4], buffers[2], '-');

      A4GL_init_dec (buffers[4], 64, 32);
      dec_math (buffers[2], buffers[1], buffers[4], '*');
      if (memcmp (buffers[4], buffers[3], NUM_BYTES (buffers[4])) == 0)
	break;
      memcpy (buffers[3], buffers[4], NUM_BYTES (buffers[4]));
      memcpy (buffers[1], buffers[4], NUM_BYTES (buffers[4]));
    }
  A4GL_init_dec (buffers[4], 126, 62);
  A4GL_str_to_dec ("0.00000000000000000000000000000005", buffers[4]);
  A4GL_init_dec (buffers[1], 126, 62);
  dec_math (buffers[3], buffers[4], buffers[1], '+');
  A4GL_init_dec (tmpbuff, 64, 32);
  dec_math (mult_by, buffers[1], tmpbuff, '*');

  /* A4GL_debug ("Done: %s %d interations\n", A4GL_dec_to_str (tmpbuff), counter); */
  return tmpbuff;
}

/**
 * Divide two decimal values.
 *
 * @param s The left decimal.
 * @param w The rigth decimal.
 * @return The result of the division.
 */
char *
A4GL_divide_dec (char *s, char *w)
{
  return A4GL_mult_dec (s, A4GL_inv (w));
}

/**
 *
 * @param s
 * @param d
 */
void
A4GL_trim_decimals (char *s, int d)
{
  int diff;
  int n;
  return;
  diff = NUM_DEC (s) - d;
  if (SIGNED (s))
    n = 1;
  else
    n = 0;
  if (diff > 0)
    {
      SET_DIG (s, NUM_DIG (s) - diff / 2);
      SET_DEC (s, d);
      if (n)
 A4GL_negate (s);
    }
}


#ifdef TEST

/**
 * Dump a value teling the line in the source where was found.
 *
 * Used for debugging purpose only.
 *
 * @param ln The line in the source code
 * @param s The value to be printed to the debug.
 */
static void
print_res_l (int ln, char *s)
{
  /* A4GL_debug ("%4d->%s\n", ln, A4GL_dec_to_str (s)); */
  A4GL_debug ("      ");
  A4GL_pr (s);
}

#endif

/**
 * Dump the information in a string in hexadecimal format.
 *
 * Used just for debugging purpose only.
 *
 * @param s The string to be dumped.
 */
void
A4GL_dump (char *s)
{
  int a;
  char buff[256] = "";
  char buff2[256] = "";
return;

  sprintf (buff, "Dump : %p\n", s);
  for (a = 0; a <= 7; a++)
    {
      sprintf (buff2, "%02x ", s[a] & 0xff);
      strcat (buff, buff2);
    }
  A4GL_debug (buff);
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
A4GL_valid_dt (char *s, int *data)
{
  int a;
  char buff[256];
  char *ptr[256];
  char type[256];
  int dt_type;
  int b;
  int i;
  int cnt = 0;
  int buff_size;
  char *codes[] = { "", "YEAR", "MONTH", "DAY", "HOUR", "MINUTE",
    "SECOND", "FRACTION1", "FRACTION2", "FRACTION3", "FRACTION4", "FRACTION5",
    0
  };

  A4GL_debug ("In valid_dt\n");
  if (strlen (s) > 25)
    {
      A4GL_debug ("Too long\n");
      return 0;
    }

  strcpy (buff, s);
  ptr[0] = &buff[0];
  A4GL_debug ("Splitting '%s'\n", s);
  cnt = 0;
  buff_size = strlen (buff);
  for (a = 1; a < buff_size; a++)
    {

      if (buff[a] == '.')
	{
	  type[cnt++] = '.';
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
      A4GL_debug ("Dodgey character %c\n", buff[a]);
      return 0;
    }

  type[cnt] = 0;
  dt_type = -1;
  A4GL_debug ("cnt=%d\n", cnt);
  A4GL_debug ("type=%s\n", type);

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
    return 0;
  if (dt_type == 0 && strlen (ptr[0]))
    return 1;			/* single number.. */
  if (dt_type == 0 && strlen (ptr[0]) == 0)
    return 0;			/* nothing... */

  b = dt_type & 15;
  a = dt_type >> 4;
  A4GL_debug ("a=%d b=%d dt_type=%d cnt=%d\n", a, b, dt_type, cnt);

  if (b - a != cnt)
    {
      A4GL_debug ("mismatch in brackets\n");
      return 0;
    }

  for (i = 0; i < 10; i++)
    {
      data[i] = 0;
    }

  for (i = a; i <= b; i++)
    {
      A4GL_debug ("i=%d i-a=%d\n", i, i - a);
      if (i == 1 && strlen (ptr[i - a]) != 4)
	{
	  A4GL_debug ("Year no 4 digits\n");
	  return 0;
	}

      if (i != 1 && strlen (ptr[i - a]) != 2 && i != 7)
	{
	  A4GL_debug ("expecting 2 digits -> '%s'\n", ptr[i - a]);
	  return 0;
	}

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
	  data[i - 1] = atoi (ptr[i - a]);
	}

      A4GL_debug ("%s -> '%s'\n", codes[i], ptr[i - a]);
    }
  return 1;
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
  char buff[256];
  char *ptr[256];
  char type[256];
  int dt_type;
  int b;
  int i;
  int cnt = 0;
  int has_yr_month = 0;
  int has_rest = 0;
  int buff_size;
  int size_type;
  char *codes[] = { "", "YEAR", "MONTH", "DAY", "HOUR", "MINUTE",
    "SECOND", "FRACTION1", "FRACTION2", "FRACTION3", "FRACTION4", "FRACTION5",
    0
  };

  for (i = 0; i < 10; i++)
    {
      data[i] = 0;
    }

  size_type = (size >> 4) & 15;
  A4GL_debug ("In valid_int size=%x\n",size);
  if (strlen (s) > 30)
    {
      A4GL_debug ("Too long - '%s' (%d)\n", s, strlen (s));
      return 0;
    }

  strcpy (buff, s);
  ptr[0] = &buff[0];
  A4GL_debug ("Splitting '%s'\n", buff);
  cnt = 0;
  buff_size = strlen (buff);
  for (a = 1; a < buff_size; a++)
    {

      if (buff[a] == '.')
	{
	  type[cnt++] = '.';
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
      /* not something we we're expecting */
      A4GL_debug ("Dodgey character %c\n", buff[a]);
      return 0;
    }

  type[cnt] = 0;
  dt_type = -1;
  //debug ("cnt=%d\n", cnt);
  //debug ("type='%s' size=0x%x\n", type,size);

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

  A4GL_debug ("dt_type= %d\n", dt_type);

  if (dt_type == 0)
    {				/* Lets assume the programmer knows what he's doing.. */
      A4GL_debug ("Probably type= %d\n", size_type);
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
  A4GL_debug ("a=%d b=%d dt_type=%d cnt=%d\n", a, b, dt_type, cnt);

  if (b - a != cnt)
    {
      A4GL_debug ("mismatch in brackets\n");
      return 0;
    }

  for (i = 0; i < 10; i++)
    {
      data[i] = 0;
    }

  for (i = a; i <= b; i++)
    {
      A4GL_debug ("i=%d i-a=%d\n", i, i - a);

      if (i == 7)
	{
	  char buff[256];
	  strcpy (buff, ptr[i - a]);
	  strcat (buff, "000000");
	  buff[5] = 0;
	  A4GL_debug ("Setting fraction to %d\n", atoi (buff));
	  data[i - 1] = atoi (buff);
	}
      else
	{
	  data[i - 1] = atoi (ptr[i - a]);
	}

      A4GL_debug ("%s -> '%s'\n", codes[i], ptr[i - a]);
    }
  has_yr_month = 0;
  has_rest = 0;
  if (data[0] || data[1])
    has_yr_month = 1;
  if (data[2] || data[3] || data[4] || data[5] || data[6])
    has_rest = 1;
  if (has_yr_month && has_rest)
    {
      A4GL_debug ("Can't have month/year and day/hour/second/fraction..\n");
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
  int cnt;
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
}


#ifdef MOVED_TO_INTERVAL_C
/**
 * @param ival
 * @param data
 */
void
A4GL_decode_interval (struct ival *ival, int *data)
{
  char buff[256];
  int i;
  int cnt = 0;
  char buff2[64];
  int s1;
  int s2;
  int c;
  int cpc;
  int c2;
  int ltime;

  char *codes[] = { "YEAR", "MONTH", "DAY", "HOUR", "MINUTE",
    "SECOND", "FRACTION",
    0
  };
  int spc[] = {
    0,
    4,
    2,
    2,
    2,
    2,
    2,
    5
  };

  A4GL_debug ("Decoding interval into component parts");

  for (i = 0; i < 10; i++)
    {
      data[i] = 0;
    }

  s1 = ival->stime % 16;
  s2 = ival->stime / 16;
  A4GL_debug ("s1=%d s2=%d", s1, s2);

  sprintf (buff, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
	   ival->data[0], ival->data[1], ival->data[2], ival->data[3],
	   ival->data[4], ival->data[5],
	   ival->data[6], ival->data[7],
	   ival->data[8], ival->data[9],
	   ival->data[10], ival->data[11],
	   ival->data[12], ival->data[13],
	   ival->data[14], ival->data[15],
	   ival->data[16], ival->data[17], ival->data[18],
	   ival->data[19], ival->data[20], ival->data[21],
	   ival->data[22], ival->data[23]);

  A4GL_debug ("buff=%s\n", buff);

  cnt = 0;
  for (c = 1; c < s1; c++)
    {
      A4GL_debug ("c=%d cnt=%d\n", c, cnt);
      cnt += spc[c];
    }

  A4GL_debug ("Cnt=%d\n", cnt);
  A4GL_debug ("Taking first part (size=%d) from %d", s2, cnt);

  c = s2;
  strncpy (buff2, &buff[cnt], s2);
  buff2[s2] = 0;
  A4GL_debug ("buff2 = '%s'\n", buff2);

  c2 = c;
  ltime = ival->ltime;
  if (ltime >= 7)
    ltime = 7;

  for (cpc = s1; cpc < ltime; cpc++)
    {
      A4GL_debug ("cpc=%d buff2=%s c2=%d cnt=%d cnt+c2=%d ", cpc, buff2, c2, cnt,
	     cnt + c2);
      data[cpc - 1] = atoi (buff2);

      buff2[0] = buff[cnt + c2];
      c2++;
      if (ival->ltime < 7)
	{
	  buff2[1] = buff[cnt + c2];
	  c2++;
	  buff2[2] = 0;
	}
      else
	{
	  buff2[1] = buff[cnt + c2];
	  c2++;
	  buff2[2] = buff[cnt + c2];
	  c2++;
	  buff2[3] = buff[cnt + c2];
	  c2++;
	  buff2[4] = buff[cnt + c2];
	  c2++;
	  buff2[4] = 0;
	}
    }

  A4GL_debug ("cpc=%d buff2=%s", cpc, buff2);
  data[cpc - 1] = atoi (buff2);
  for (c = 0; c < 7; c++)
    {
      A4GL_debug ("Data : %s %d\n", codes[c], data[c]);
    }
}
#endif

/**
* This function sets up the conversion matrix
* for a new datatype
**/
void
A4GL_set_convmatrix (int dtype1, int dtype2, void *ptr)
{

  A4GL_debug ("Setting convmatrix %d %d to %p", dtype1, dtype2, ptr);

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

/* ============================= EOF ================================ */
