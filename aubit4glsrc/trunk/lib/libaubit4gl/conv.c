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

#include <stdio.h>

#include "../libincl/dbform.h"
#include "../libincl/dates.h"
#include "../libincl/constats.h"
#include "../libincl/stack.h"
#include "../libincl/dtypes.h"
#include "../libincl/debug.h"


#include <sys/types.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#ifdef __CYGWIN__
#include <errno.h>
#endif

extern int errno;
//#include <unistd.h>
//#include <pwd.h>
#include <locale.h>
/* #define DIGIT_ALIGN_LEFT */
#include <time.h>
#include <math.h>
int lastsize;

/** @todo Change all this function proptotypes to an header */
int bname2 (char *str, char *s1, char *s2, char *s3);
char *inv (char *s);
double dec_to_double (void *buf);
int double_to_dec (double arg, char *buf, size_t length, size_t digits);
char *dec_to_str (char *s, int size);
char *add_dec (char *a, char *b);
char *minus_dec (char *a, char *b);
char *str_to_dec (char *s, char *w);
char *init_dec (char *s, int len, int d);
char *mult_dec (char *s, char *v);
char *divide_dec (char *s, char *w);
void dec_to_dec (char *f, char *t);
void dump (char *s);

int op_ival (struct ival *a, struct ival *b, double double_val, char op,
 char param);

int conv_invdatatoc(int *data,int v1,int v2,int v3,char *buff);
/* === END PROPTOTYPES === */

/**
 * Copy a int value.
 *
 * @param a The integer to be copied.
 * @param b A pointer to the place where to put the value copied.
 * @param size
 * @return Allways 1
 */
inttoint (void *a, void *b, int size)
{
  char buff[256];
  int data[10];
  int val1,val2,val3;
struct ival *d;

  debug ("inttoint\n");
  d=b;
  d->ltime = size & 15;
  d->stime = size >> 4;

  val1 = size & 15;
  val2 = (size >> 4) & 15;
  val3 = (size >> 8) & 15;

  decode_interval ((struct ival *)a, &data);
  debug("Converting to %d %d %d\n",val1,val2,val3);

  conv_invdatatoc(data,val1,val2,val3,d->data);
  debug("Set b..");
  return 1;
}

/**
 *
 * @param a1 A pointer to theinteger value.
 * @param b A pointer to the place where to return the converted value.
 * @param size
 * return Allways 1
 */
inttoc (void *a1, void *b, int size)
{
  struct ival *a;
  int s1;
  int s2;
  int c;
  int cnt;
  int cpc;
  int c2;
  char buff[256];
  char buff2[256];
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

  a = a1;
  s1 = a->stime % 16;
  s2 = a->stime / 16;
  sprintf (buff, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
	   a->data[0], a->data[1], a->data[2], a->data[3],
	   a->data[4], a->data[5],
	   a->data[6], a->data[7],
	   a->data[8], a->data[9],
	   a->data[10], a->data[11],
	   a->data[12], a->data[13],
	   a->data[14], a->data[15], a->data[16], a->data[17], a->data[18]);
  cnt = 0;
  for (c = 1; c < s1; c++)
    {
      debug ("c=%d cnt=%d\n", c, cnt);
      cnt += spc[c];
    }
  debug ("Cnt=%d\n", cnt);
  debug ("buff=%s\n", buff);

  for (c = 0; c < s2; c++)
    {
      debug("buff2[%d]=buff[%d] = %c",c,cnt+c,buff[cnt+c]);
      buff2[c] = buff[cnt + c];
    }

  c2 = c;

  for (cpc = s1; cpc < a->ltime; cpc++)
    {
      if (cpc == 1)
	buff2[c++] = '-';
      if (cpc == 2)
	buff2[c++] = '-';
      if (cpc == 3)
	buff2[c++] = ' ';
      if (cpc == 4)
	buff2[c++] = ':';
      if (cpc == 5)
	buff2[c++] = ':';
      if (cpc == 6)
	buff2[c++] = '.';

      buff2[c] = buff[cnt + c2];
      c++;
      c2++;
      buff2[c] = buff[cnt + c2];
      c++;
      c2++;
    }
  buff2[c] = 0;
  debug("buff2=%s",buff2);
  strcpy (b, buff2);

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
ctoint (void *a, void *b, int size)
{
  int data[256];
  struct ival *d;
  int v1, v2, v3;
  char fractions[6];
  debug ("ctoint : %p %p %d\n", a, b, size);
  debug ("a-->%s\n", a);
  d = (struct ival *) b;

  d->ltime = size & 15;
  d->stime = size >> 4;

  v1 = size & 15;
  v2 = (size >> 4) & 15;
  v3 = (size >> 8) & 15;

  debug ("v1=%d v2=%d v3=%d\n", v1, v2, v3);

  if (valid_int (a, data,size))
    {
	conv_invdatatoc(data,v1,v2,v3,d->data);

      	return 1;
    }
  else
    {
      return 0;
    }

  return 1;

  debug ("ctoint\n");
  return 0;
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
dttodt (void *a, void *b, int size)
{
  char buff[256];
  debug ("dttodt %p %p %d\n", a, b, size);
  if (dttoc (a, buff, 255))
    {
      return ctodt (buff, b, size);
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
ctodt (void *a, void *b, int size)
{
  int data[256];
  struct a4gl_dtime *d;
  debug ("ctodt : %p %p %d\n", a, b, size);
  debug ("a-->%s\n", a);
  d = (struct a4gl_dtime *) b;

  d->ltime = size & 15;
  d->stime = size >> 4;

  if (valid_dt (a, data))
    {
      debug ("Y %d\n", data[0]);
      debug ("M %d\n", data[1]);
      debug ("D %d\n", data[2]);
      debug ("H %d\n", data[3]);
      debug ("m %d\n", data[4]);
      debug ("S %d\n", data[5]);
      debug ("F %d\n", data[6]);

      sprintf (d->data, "%04d%02d%02d%02d%02d%02d%d00000",
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
dttoc (void *a, void *b, int size)
{
  struct a4gl_dtime *d;
  int cnt;
  char buff[256];
  int x;
  int pos[] = { 0, 4, 6, 8, 10, 12, 14, 15, 16, 17, 18, 19 };
  int sizes[] = { 4, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1 };
  char delim[] = "-- ::.*****";

  debug ("dttoc : %p %p %d\n", a, b, size);
  d = a;
  x = 0;
  for (cnt = d->stime - 1; cnt <= d->ltime - 1; cnt++)
    {
      debug ("cnt=%d", cnt);
      debug ("   pos=%d sizes=%d", pos[cnt], sizes[cnt]);
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
      debug ("does not fit '%s' %d", buff, size);
      exitwith ("does not fit\n", buff, size);
      return 0;
    }

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
btob (void *a, void *b, int size)
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
stoi (void *aa, void *zi, int sz_ignore)
{
  int *z;
  char *a;
  char *eptr;
  int zz;
  z = (int *) zi;
  a = (char *) aa;
  trim (a);
  zz = strlen (a);
  errno = 0;
  *z = strtol (a, &eptr, 10);
  if (eptr - a < zz)
    return 0;
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
stol (void *aa, void *zi, int sz_ignore)
{
  char *eptr;
  int zz;
  char *a;
  long *z;
  a = (char *) aa;
  z = (long *) zi;
  errno = 0;
  trim (a);
  zz = strlen (a);
  *z = strtol (a, &eptr, 10);
  if (eptr - a < zz)
    return 0;
  if (errno != 0 || eptr[0] != 0 || eptr == a)
    {
      return 0;
    }
  return 1;
}

#define itomdec itodec
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
itodec (void *a, void *z, int size)
{
  char *eptr;
  int zz;
  int h;
  int t;
  char buff[256];
  h = size;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;
  debug ("converting %s to a decimal (%x) %d,%d", a, size, h, t);
  init_dec (z, h, t);
  sprintf (buff, "%016d", *(int *) a);

  eptr = str_to_dec (buff, z);

  if (eptr)
    return 1;
  else
    return 0;
}

/**
 * definitions for dates (seems a pretty odd conversion though... 
 */
#define dtodec ltodec
#define dtomdec ltodec

#define ltomdec ltodec
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
ltodec (void *a, void *z, int size)
{
  char *eptr;
  int zz;
  int h;
  int t;
  char buff[256];
  h = size;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;
  debug ("converting %s to a decimal (%x) %d,%d", a, size, h, t);
  init_dec (z, h, t);
  sprintf (buff, "%032ld", *(long *) a);
  eptr = str_to_dec (buff, z);

  if (eptr)
    return 1;
  else
    return 0;
}


#define ftomdec ftodec
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
ftodec (void *a, void *z, int size)
{
  char *eptr;
  int zz;
  int h;
  int t;
  char buff[256];
  h = size;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;
  debug ("converting %s to a decimal (%x) %d,%d", a, size, h, t);
  init_dec (z, h, t);
  sprintf (buff, "%32.16lf", *(double *) a);
  eptr = str_to_dec (buff, z);

  if (eptr)
    return 1;
  else
    return 0;
}



#define sftomdec sftodec

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
sftodec (void *a, void *z, int size)
{
  char *eptr;
  int zz;
  int h;
  int t;
  char buff[256];
  h = size;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;
  debug ("converting %s to a decimal (%x) %d,%d", a, size, h, t);
  init_dec (z, h, t);
  sprintf (buff, "%32.16f", *(float *) a);
  eptr = str_to_dec (buff, z);

  if (eptr)
    return 1;
  else
    return 0;

}

#define mdectomdec dectodec
#define mdectodec dectodec
#define dectomdec dectodec

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
dectodec (void *a, void *z, int size)
{
  char *eptr;
  int zz;
  int h;
  int t;
  char *buff;
  h = size;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;
  debug ("converting %s to a decimal (%x) %d,%d", a, size, h, t);
  init_dec (z, h, t);
  buff = dec_to_str (a, 0);
  eptr = str_to_dec (buff, z);
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
stodec (void *a, void *z, int size)
{
  char *eptr;
  int zz;
  int h;
  int t;
  h = size;
  t = h;
  h = h / 256;
  t = t - h * 256;
  errno = 0;
  debug ("converting %s to a decimal (%x) %d,%d", a, size, h, t);
  init_dec (z, h, t);

  debug ("After init\n");
  dump (z);
  eptr = str_to_dec (a, z);
  dump (z);

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
mdectos (void *z, void *w, int size)
{
  char *eptr;
  int zz;
  char *buff;
  buff = dec_to_str (z, size);
  debug ("In dectos gets '%s'", buff);
  dump (z);
  ctoc (buff, w, size);
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
mdectol (void *zz, void *aa, int sz_ignore)
{
  char buff[64];
  long *a;
  char *z;
  debug ("mdectol");
  a = (long *) aa;
  z = (char *) zz;
  strcpy (buff, dec_to_str (z, 0));
  return stol (buff, a, 0);
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
mdectoi (void *zz, void *aa, int sz_ignore)
{
  char buff[64];
  int *a;
  char *z;
  debug ("mdectoi");
  a = (int *) aa;
  z = (char *) zz;
  strcpy (buff, dec_to_str (z, 0));
  return stoi (buff, a, 0);
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
mdectod (void *zz, void *aa, int sz_ignore)
{
  char buff[64];
  long *a;
  char *z;
  a = (long *) aa;
  z = (char *) zz;
  strcpy (buff, dec_to_str (z, 0));
  return stol (buff, a, 0);
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
mdectof (void *zz, void *aa, int sz_ignore)
{
  char buff[64];
  char *z;
  double *a;
  a = (double *) aa;
  z = (char *) zz;

  strcpy (buff, dec_to_str (z, 0));
  return stof (buff, a, 0);
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
mdectosf (void *zz, void *aa, int sz_ignore)
{
  char buff[64];
  char *z;
  float *a;
  z = (char *) zz;
  a = (float *) aa;
  strcpy (buff, dec_to_str (z, 0));
  return stof (buff, a, 0);
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
dectos (void *z, void *w, int size)
{
  char *eptr;
  int zz;
  char *buff;
  int r;
  debug ("dectos");

  buff = dec_to_str (z, size);
  debug ("In dectos gets '%s'", buff);
  dump (z);
  r = ctoc (buff, w, size);
  debug ("r=%d\n", r);
  return r;
}

/**
 * Convert a string value to float.
 *
 * @param zz The decimal value.
 * @param aa A pointer where to return the string value.
 * @param sz_ignore Not used.
 * @return 
 *   - 0 : Value invalid or error.
 *   - 1 : Value converted.
 */
stof (void *aa, void *zz, int sz_ignore)
{
  char *a;
  double *z;
  a = (char *) aa;
  z = (double *) zz;
  sscanf (a, "%lf", z);
  return 1;
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
stosf (void *aa, void *zz, int sz_ignore)
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
dectol (void *zz, void *aa, int sz_ignore)
{
  char buff[64];
  long *a;
  char *z;
  debug ("dectol");
  a = (long *) aa;
  z = (char *) zz;
  dectos (z, buff, 64);
  return stol (buff, a, 0);
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
dectoi (void *zz, void *aa, int sz_ignore)
{
  char buff[64];
  int *a;
  char *z;
  debug ("dectoi");
  a = (int *) aa;
  z = (char *) zz;
  dectos (z, buff, 64);
  return stoi (buff, a, 0);
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
dectod (void *zz, void *aa, int sz_ignore)
{
  char buff[64];
  long *a;
  char *z;
  a = (long *) aa;
  z = (char *) zz;
  dectos (z, buff, 64);
  return stol (buff, a, 0);
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
dectof (void *zz, void *aa, int sz_ignore)
{
  char buff[64];
  char *z;
  double *a;
  a = (double *) aa;
  z = (char *) zz;

  dectos (z, buff, 64);
  return stof (buff, a, 0);
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
dectosf (void *zz, void *aa, int sz_ignore)
{
  char buff[64];
  char *z;
  float *a;
  z = (char *) zz;
  a = (float *) aa;
  dectos (z, buff, 64);
  return stosf (buff, a, 0);
}

/**
 * Convert a date to smallfloat.
 *
 * @param zz The decimal value.
 * @param aa A pointer where to return the smallfloat value.
 * @param sz_ignore Not used.
 * @return Allways 1
 */
dtosf (void *aa, void *zz, int sz_ignore)
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
dtof (void *aa, void *zz, int sz_ignore)
{
  int *a;
  double *z;
  a = (int *) aa;
  z = (double *) zz;
  debug ("dtof");
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
dtol (void *aa, void *zz, int sz_ignore)
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
dtoi (void *aa, void *zz, int sz_ignore)
{
  int *a;
  int *z;
  a = (int *) aa;
  z = (int *) zz;
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
ltod (void *aa, void *zz, int sz_ignore)
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
itod (void *aa, void *zz, int sz_ignore)
{
  int *a;
  int *z;
  a = (int *) aa;
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
sftod (void *aa, void *zz, int sz_ignore)
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
ftod (void *aa, void *zz, int sz_ignore)
{
  double *a;
  int *z;
  a = (double *) aa;
  z = (int *) zz;
  debug ("ftod");
  *z = *a;
  return 1;
}

/**
 * Convert a string value to date.
 *
 * @param zz The string value.
 * @param aa A pointer where to return the date value.
 * @param sz_ignore Not used.
 * @return
 *   - 0 : There was a convertion error
 *   - 1 : Convertion made.
 */
stod (void *zz, void *aa, int sz_ignore)
{
  int d[4];
  char p1[10] = "ptr1";
  char p2[10] = "ptr2";
  char p3[10] = "ptr3";
  char dbdate_y[10] = "";
  char dbdate_m[10] = "";
  char dbdate_d[10] = "";
  int cnt = 0;
  int ptr1;
  int a;
  char buff[5];
  char buff2[15];
  char dbdate[20];
  int *c;
  char *z;
  c = (int *) aa;
  z = (char *) zz;
  ptr1 = 0;
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("stod %s", z);
  }
#endif
  if (bname2 (z, p1, p2, p3)==0) return 0;
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("done bname2 '%s' '%s' '%s'", p1, p2, p3);
  }
#endif
  strcpy (dbdate, acl_getenv ("DBDATE"));
  debug ("DBDATE set to %s\n", dbdate);

  if (dbdate[0] == 'Y')
    strcpy (dbdate_y, p1);
  if (dbdate[0] == 'M')
    strcpy (dbdate_m, p1);
  if (dbdate[0] == 'D')
    strcpy (dbdate_d, p1);

  if (dbdate[1] == 'Y')
    strcpy (dbdate_y, p2);
  if (dbdate[1] == 'M')
    strcpy (dbdate_m, p2);
  if (dbdate[1] == 'D')
    strcpy (dbdate_d, p2);

  if (dbdate[2] == 'Y')
    strcpy (dbdate_y, p3);
  if (dbdate[2] == 'M')
    strcpy (dbdate_m, p3);
  if (dbdate[2] == 'D')
    strcpy (dbdate_d, p3);

  strcpy (p1, dbdate_d);
  strcpy (p2, dbdate_m);
  strcpy (p3, dbdate_y);

  d[0] = atoi (p1);
  d[1] = atoi (p2);
  d[2] = atoi (p3);
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("Split to numbers : %d %d %d", d[0], d[1], d[2]);
  }
#endif
  if (strlen (p1) > 0 && strlen (p2) > 0 && strlen (p3) > 0)
    {
      cnt = 3;
    }
  trim (p3);
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("trimmed");
  }
#endif
  if (strlen (p3) <= 2)
    {
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("Modify year");
      }
#endif
      d[2] = modify_year (d[2]);
    }
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("Modified year");
  }
#endif
  if (cnt != 3)
    {
      /* could be all numbers */
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("Check numbers %s", z);
      }
#endif
      if (strlen (z) == 6)
	{
#ifdef DEBUG
/* {DEBUG} */
	  {
	    debug ("6 chars long");
	  }
#endif
	  buff[0] = z[0];
	  buff[1] = z[1];
	  buff[2] = 0;
	  d[0] = atoi (buff);
	  buff[0] = z[2];
	  buff[1] = z[3];
	  buff[2] = 0;
	  d[1] = atoi (buff);
	  buff[0] = z[4];
	  buff[1] = z[5];
	  buff[2] = 0;
	  d[2] = atoi (buff);
	  d[2] = modify_year (d[2]);
	  cnt = 3;
	}
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("Checked 6");
      }
#endif
      if (strlen (z) == 8)
	{
#ifdef DEBUG
/* {DEBUG} */
	  {
	    debug ("8 chars long");
	  }
#endif
	  buff[0] = z[0];
	  buff[1] = z[1];
	  buff[2] = 0;
	  d[0] = atoi (buff);
	  buff[0] = z[2];
	  buff[1] = z[3];
	  buff[2] = 0;
	  d[1] = atoi (buff);
	  buff[0] = z[4];
	  buff[1] = z[5];
	  buff[2] = z[6];
	  buff[3] = z[7];
	  buff[5] = 0;
	  d[2] = atoi (buff);
	  cnt = 3;
	}
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("Checked 8");
      }
#endif
    }
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("  (cnt=%d)", cnt);
  }
#endif
  if (cnt == 3)
    {
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("cnt=3 %d %d %d", d[0], d[1], d[2]);
      }
#endif
      *c = gen_dateno (d[0], d[1], d[2]);
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("Generated date");
      }
#endif
      if (*c != DATE_INVALID)
	{
#ifdef DEBUG
/* {DEBUG} */
	  {
	    debug ("Made %d", *c);
	  }
#endif
	  return 1;
	}
      else
	return 0;
    }
  else
    return 0;


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
dtovc (void *aa, void *zz, int sz_ignore)
{
  int *a;
  char *z;
  a = (int *) aa;
  z = (char *) zz;
  return dtos (a, z);
}

/**
 * Convert a date to  string.
 *
 * @param aa The date value value.
 * @param zz A pointer where to return the value.
 * @param size The size of the string buffer where to put the converted value.
 * @return
 *   - 0 : There was a convertion error
 *   - 1 : Convertion made.
 */
dtos (void *aa, void *zz, int size)
{
  int *a;
  char *z;
  int d, m, y;
  z = (char *) zz;
  a = (int *) aa;
  d = 0;
  m = 0;
  y = 0;
#ifdef DEBUG
/* {DEBUG} */ { debug ("dtos"); }
#endif
#ifdef DEBUG
/* {DEBUG} */ { debug ("Size=%d\n", size); }
#endif

  if (size < 6)
  {
    #ifdef DEBUG
    /* {DEBUG} */ { debug ("Size too small"); }
    #endif
    memset (z, '*', size);
    z[size] = 0;
    return 0;
  }

  if (get_date (*a, &d, &m, &y))	// Need DBDATE Fix....
  {
    if (strncasecmp (acl_getenv ("DBDATE"), "DMY", 3) == 0)
    {
  
      if (size >= 10)
      {
        sprintf (z, "%02d/%02d/%04d", d, m, y);
      }
      if (size < 10 && size >= 8)
      {
        sprintf (z, "%02d/%02d/%02d", d, m, y % 100);
      }
      if (size < 8 && size >= 6)
      {
        sprintf (z, "%02d%02d%02d", d, m, y % 100);
      }
    
    }
    else
    {
      if (size >= 10)
      {
        sprintf (z, "%02d/%02d/%04d", m, d, y);
      }
      if (size < 10 && size >= 8)
      {
        sprintf (z, "%02d/%02d/%02d", m, d, y % 100);
      }
      if (size < 8 && size >= 6)
      {
        sprintf (z, "%02d%02d%02d", m, d, y % 100);
      }
    }
    pad_string (z, size);
  
    #ifdef DEBUG
    /* {DEBUG} */ { debug ("Date = %s\n", z); }
    #endif
    return 1;
  }
  else
    return 0;
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
itoc (void *aa, void *zz, int size)
{
  char fmt[10] = "d";
  int *a;
  char *z;
  a = (int *) aa;
  *a = ((*a) & 0xffff);
  z = (char *) zz;
  if (digittoc (a, z, fmt, DTYPE_SMINT, size))
    {
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("itoc return from digittoc using %s", fmt);
      }
#endif
      sprintf (z, fmt, *(int *) a);
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
itol (void *aa, void *zz, int sz_ignore)
{
  int *a;
  long *z;
  z = (long *) zz;
  a = (int *) aa;
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("itol");
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
itof (void *aa, void *zz, int sz_ignore)
{
  int *a;
  double *z;
  z = (double *) zz;
  a = (int *) aa;
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
itosf (void *aa, void *zz, int sz_ignore)
{
  int *a;
  float *z;
  z = (float *) zz;
  a = (int *) aa;
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
itovc (void *aa, void *zz, int c)
{
  int *a;
  char *z;
  z = (char *) zz;
  a = (int *) aa;
  itoc (a, z, c);
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
ltoc (void *aa, void *zz, int size)
{
  long *a;
  char *z;
  char fmt[10] = "ld";
  z = (char *) zz;
  a = (long *) aa;
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("Size=%d", size);
  }
#endif
  if (digittoc (a, z, fmt, DTYPE_INT, size))
    {
#ifdef DEBUG
/* {DEBUG} */
      {
	debug ("ltoc return from digittoc using %s", fmt);
      }
#endif
      sprintf (z, fmt, *(long *) a);
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
ltoi (void *aa, void *zz, int sz_ignore)
{
  long *a;
  int *z;
  a = (long *) aa;
  z = (int *) zz;

#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("Ltoi");
  }
#endif
  *z = (int) *a;
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
ltof (void *aa, void *zz, int sz_ignore)
{
  long *a;
  double *z;
  a = (long *) aa;
  z = (double *) zz;

  debug ("ltof");
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
ltosf (void *aa, void *zz, int sz_ignore)
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
ltovc (void *aa, void *zz, int c)
{
  long *a;
  char *z;
  a = (long *) aa;
  z = (char *) zz;
  ltoc (a, z, c);
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
ftoc (void *aa, void *zz, int c)
{
  double *a;
  char *z;
  char fmt[10] = ".2lf";
  a = (double *) aa;
  z = (char *) zz;
  if (digittoc (a, z, fmt, DTYPE_FLOAT, c))
    {
      sprintf (z, fmt, *a);
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
ftoi (void *aa, void *zz, int c)
{
  double *a;
  int *z;
  z = (int *) zz;
  a = (double *) aa;
  *z = (int) *a;
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
ftol (void *aa, void *zz, int c)
{
  double *a;
  long *z;
  a = (double *) aa;
  z = (long *) zz;
  debug ("ftol");
  *z = (long) *a;
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("a=%lf z=%d\n", *a, *z);
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
ftosf (void *aa, void *zz, int c)
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
ftovc (void *aa, void *zz, int c)
{
  double *a;
  char *z;
  a = (double *) aa;
  z = (char *) zz;
  ftoc (a, z, c);

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
sftoc (void *aa, void *zz, int c)
{
  float *a;
  char *z;
  char fmt[10] = ".2f";
  a = (float *) aa;
  z = (char *) zz;
  if (digittoc (a, z, fmt, DTYPE_FLOAT, c))
    {
      sprintf (z, fmt, *a);
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
sftoi (void *aa, void *zz, int c)
{
  float *a;
  int *z;
  z = (int *) zz;
  a = (float *) aa;
  *z = (int) *a;
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
sftol (void *aa, void *zz, int c)
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
sftof (void *aa, void *zz, int c)
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
sftovc (void *aa, void *zz, int c)
{
  float *a;
  char *z;
  a = (float *) aa;
  z = (char *) zz;
  sftoc (a, z, c);
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
sftosf (void *aa, void *bb, int c)
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
ftof (void *aa, void *bb, int c)
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
ctoc (void *a, void *b, int size)
{
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("--->Got size as %d", size);
  }
#endif
  string_set (b, a, size);
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("Set string");
  }
#endif
  debug ("returning");
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
ltol (void *aa, void *bb, int sz_ignore)
{
  long *a;
  long *b;
  a = (long *) aa;
  b = (long *) bb;

  *b = *a;
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("ltol %ld %ld", *a, *b);
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
itoi (void *aa, void *bb, int sz_ignore)
{
  int *a;
  int *b;
  a = (int *) aa;
  b = (int *) bb;
  *b = *a;
  return 1;
}

/**
 * Assign a character value to an empty string
 *
 * @param p The pointer to the string to be cleaned.
 */
void
setc (void *p)
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
seti (void *p)
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
setl (void *p)
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
setf (void *p)
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
setsf (void *p)
{
  float *p1;
  p1 = (float *) p;
  *p1 = 0;
}

/**
 * Does nothing.
 */
void
setno (void *p)
{
  return;
}


void (*setdtype[15]) (void *ptr1) =
{
  setc, seti, setl, setf,
    setsf, setf, setl, setno, setf, setno, setno, setno, setno, setno, setno
};

#define OK (void *)1

/**
 * Convertion table.
 */
int (*convmatrix[15][15]) (void *ptr1, void *ptr2, int size) =
{
  {
    ctoc, stoi, stol, stof, stosf, stodec, stol, stod, stof, NO, ctodt, NO,
      NO, OK, ctoint}
  ,
  {
    itoc, itoi, itol, itof, itosf, itodec, itol, itod, itomdec, NO, NO, NO,
      NO, itovc, NO}
  ,
  {
    ltoc, ltoi, ltol, ltof, ltosf, ltodec, ltol, ltod, ltomdec, NO, NO, NO,
      NO, ltovc, NO}
  ,
  {
    ftoc, ftoi, ftol, ftof, ftosf, ftodec, ftol, ftod, ftomdec, NO, NO, NO,
      NO, ftovc, NO}
  ,
  {
    sftoc, sftoi, sftol, sftof, sftosf, sftodec, sftol, sftod, sftomdec, NO,
      NO, NO, NO, sftovc, NO}
  ,
  {
    dectos, dectoi, dectol, dectof, dectosf, dectodec, dectol, NO, dectomdec,
      NO, NO, NO, NO, dectos, NO}
  ,
  {
    ltoc, ltoi, ltol, ltof, ltosf, ltodec, ltol, ltod, ltomdec, NO, NO, NO,
      NO, ltovc, NO}
  ,
  {
    dtos, dtoi, dtol, dtof, dtosf, dtodec, dtof, ltol, dtomdec, NO, NO, NO,
      NO, dtovc, NO}
  ,
  {
    mdectos, mdectoi, mdectol, mdectof, mdectosf, mdectodec, mdectol, NO,
      mdectomdec, NO, NO, NO, NO, mdectos, NO}
  ,
  {
  NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO}
  ,
  {
  dttoc, NO, NO, NO, NO, NO, NO, NO, NO, NO, dttodt, NO, NO, NO, NO}
  ,
  {
  NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, btob, NO, NO, NO}
  ,
  {
  NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, btob, NO, NO}
  ,
  {
  NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO}
  ,
  {
  inttoc, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO,inttoint}
};


/**
 * Convert a value from one data type to other data type.
 *
 * @param dtype1 Data type of the original value.
 * @param p1 Pointer to the value to be converted.
 * @param dtype2  Data type of the original value.
 * @param p2 Pointer to the place where to put the converted value.
 * @param size
 */
conv (int dtype1, void *p1, int dtype2, void *p2, int size)
{
  int (*ptr) (void *ptr1, void *ptr2, int size);
  void *ptrf;
  int rval;
  debug ("In conv.. d1=%d d2=%d size=%d", dtype1, dtype2, size);

  assertion (p1 == 0, "Pointer 1 is zero");
  assertion (p2 == 0, "Pointer 2 is zero");

  /* debug ("Dtype1=%d p1=%p (%ld) ", dtype1, p1, *(int *) p1); */
  if (isnull (dtype1, p1))
    {
      debug ("First is null");
      setnull (dtype2, p2, size);
      return 1;
    }

  if (dtype1 == 0 && dtype2 != 0)
    {
      trim (p1);
      if (strlen (p1) == 0)
	{
	  setnull (dtype2, p2, size);
	  return 1;
	}
    }


#ifdef DEBUG
/* {DEBUG} */
  {
    /* debug ("convert %d %p %d %p\n", dtype1, p1, dtype2, p2); */
  }
#endif

  ptr = convmatrix[dtype1 & DTYPE_MASK][dtype2 & DTYPE_MASK];

  if (ptr == NO)
    {
      debug ("No! - %d %d", dtype1, dtype2);
      setdtype[dtype2 & DTYPE_MASK] (p2);
      return -1;
    }
#ifdef DEBUG
/* {DEBUG} */
  {
    debug ("conv (%ld %ld)", *(long *) p1, *(long *) p2);
  }
#endif
  rval = convmatrix[dtype1 & DTYPE_MASK][dtype2 & DTYPE_MASK] (p1, p2, size);
  debug ("rval=%d\n", rval);
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
assertion (int a, char *s)
{

  if (a)
    {
      set_errm (s);
      debug ("%s", s);
      exitwith ("Assertion failed %s");
      chk_err (0, "Unknown");
      exit (0);
    }
}


#define DEC_VAL(x) ( ((x)&0xf)+ (((x)&0xf0)*10 /16) )
#define HEX_VAL(x) (((x)%10) + ((((x)-((x)%10)) / 10)*16))
#define SIGNED(x) (x[0]&128)
#define SET_SIGNED(x) (x[0]|=128)
#define SET_UNSIGNED(x) (x[0]=(x[0]>=128)?x[0]:x[0]-128)
#define NUM_DIG(x) ((x[0])&127 )
#define NUM_DEC(x) ((x[1]))
#define SET_DIG(x,y) (x[0]=y)
#define SET_DEC(x,y) (x[1]=y)
#define OFFSET_DEC(x) (2)
#define NUM_BYTES(x) (NUM_DIG(x)+OFFSET_DEC(x))
#define DBL_DIG1 512
#define print_res(x) print_res_l(__LINE__,x)


/**
 * Convert a decimal value to double.
 *
 * @param The pointer to the decimal value.
 * @return The decimal value converted to double.
 */
double
dec_to_double (void *buf)
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

  trim_dec (s);
  trim_dec (w);

  if (sn == wn)
    {

      if (op == '*')
	{
	  if (sn == 1)
	    {
	      negate (s);
	      negate (w);
	    }
	  dec_to_dec (mult_dec (s, w), r);
	  return r;
	}

      if (op == '/')
	{
	  if (sn == 1)
	    {
	      negate (s);
	      negate (w);
	    }
	  dec_to_dec (divide_dec (s, w), r);
	  return r;

	}

      if (op == '+')
	{

	  z = add_dec (s, w);
	  dec_to_dec (z, r);
	}

      if (op == '-')
	{
	  if (sn)
	    {
	      /* -n1 - -n2 = -n1 + n2 = n2 - n1  */
	      negate (w);
	      negate (s);
	      z = minus_dec (w, s);
	      dec_to_dec (z, r);
	      return r;
	    }
	  else
	    {
	      z = minus_dec (s, w);
	      dec_to_dec (z, r);
	      return r;
	    }
	}

      if (sn == 1)
	{

	  negate (r);

	}
      return r;
    }


  if (sn)
    {
      if (op == '*')
	{

	  negate (s);

	  dec_to_dec (mult_dec (s, w), r);

	  negate (r);

	}

      if (op == '+')
	{

	  dec_to_dec (minus_dec (w, s), r);

	}
      if (op == '-')
	{

	  dec_to_dec (add_dec (s, w), r);

	  negate (r);

	}
      return r;
    }
  if (wn)
    {
      if (op == '*')
	{

	  negate (w);

	  dec_to_dec (mult_dec (s, w), r);

	  negate (r);

	}
      if (op == '+')
	{

	  dec_to_dec (minus_dec (s, w), r);

	}
      if (op == '-')
	{

	  dec_to_dec (add_dec (s, w), r);

	}
      return r;
    }
  return 0;
}

/**
 * Convert a value from double to decimal.
 *
 * @param arg
 * @param buf
 * @param length
 * @param digits
 * @return Nothing important.
 */
int
double_to_dec (double arg, char *buf, size_t length, size_t digits)
{
  char wrkbuf[DBL_DIG1], format[DBL_DIG1];
  init_dec (buf, length, digits);
  sprintf (format, "%%-%d.%dlf", length, digits);
  sprintf (wrkbuf, format, arg);
  str_to_dec (wrkbuf, buf);
}

/**
 * @deprecated
 */
typedef struct
{
  double value, expect;
  int length, digits;
} TEST_T;


/**
 * Copy a decimal value.
 *
 * @param f The value to be copied.
 * @param t A pointer to the place where to copy the decimal value.
 */
void dec_to_dec (char *f, char *t)
{
  int l, lt;
  int d, ld;
  int x, y, c;
  trim_dec (f);
  l = NUM_DIG (f);
  d = NUM_DEC (f);
  if (t[0] & 128)
    t[0] = t[0] - 128;
  lt = NUM_DIG (t);
  ld = NUM_DEC (t);
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
      debug ("Too small\n");
      pr (f);
      pr (t);
      exit (0);
      return;
    }

  memset (&t[OFFSET_DEC (t)], 0, lt);
  memcpy (&t[y + OFFSET_DEC (t)], &f[x + OFFSET_DEC (f)], c);
  if (f[0] & 128)
    negate (t);
}

/**
 * Convert a string to decimal.
 *
 * @param s The string value to be copied.
 * @param w A pointer to the place where to put the decimal value.
 */
char *
str_to_dec (char *s, char *w)
{
  int cnt;
  char hd[DBL_DIG1];
  int hdcnt = 0;
  char tl[DBL_DIG1];
  int tlcnt = 0;
  int dp = 0;
  int neg = 0;
  char buff[DBL_DIG1];
  int l, d, a;
  memset (hd, 0, DBL_DIG1 - 1);
  memset (tl, 0, DBL_DIG1 - 1);
  for (cnt = 0; cnt < strlen (s); cnt++)
    {
      if (s[cnt] == '.')
	{

	  dp++;
	  if (dp > 1)
	    return 0;
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

	}
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



  init_dec (buff, (hdcnt + tlcnt), tlcnt);
  cnt = OFFSET_DEC (buff);
  for (a = 0; a < hdcnt; a += 2)
    {
      buff[cnt++] = HEX_VAL ((hd[a] - '0') * 10 + (hd[a + 1] - '0'));
    }

  for (a = 0; a < tlcnt; a += 2)
    {
      buff[cnt++] = HEX_VAL ((tl[a] - '0') * 10 + (tl[a + 1] - '0'));
    }



  if (w == 0)
    {
      w = init_dec (w, (hdcnt + tlcnt), tlcnt);
    }

  dec_to_dec (buff, w);
  if (neg)
    {
      negate (w);
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
pr (char *wrkbf)
{
  int rc;
  int y_sub;
  rc = NUM_DIG (wrkbf);
  for (y_sub = 0; y_sub <= rc + 1; y_sub++)
    debug ("%02X ", wrkbf[y_sub] & 0xff);
  debug ("\n");
}

/**
 * 
 * @param f
 * @param t
 * @param a
 * @param b
 */
void match_dec (char *f, char *t, int *a, int *b)
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
add_dec (char *a, char *b)
{
  static char wrkbuf[3][DBL_DIG1];
  int xlen, xdig;
  int cnt;
  int lb1, hb1, lb2, hb2;
  int n1, n2;
  int carry = 0;
  int acc;
  match_dec (a, b, &xlen, &xdig);
  memset (wrkbuf[0], 0, DBL_DIG1 - 1);
  memset (wrkbuf[1], 0, DBL_DIG1 - 1);
  memset (wrkbuf[2], 0, DBL_DIG1 - 1);
  double_to_dec (0, wrkbuf[0], xlen + 2, xdig);
  double_to_dec (0, wrkbuf[1], xlen + 2, xdig);
  double_to_dec (0, wrkbuf[2], xlen + 2, xdig);
  dec_to_dec (a, wrkbuf[0]);
  dec_to_dec (b, wrkbuf[1]);
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
negate (char *s)
{
  if (s[0] & 128 == 1)
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
dec_to_str (char *s, int size)
{
  int l;
  int d;
  int c;
  int x;
  int a;
  int k;
  static char buff[DBL_DIG1];
  int has_zero = 1;
  l = NUM_DIG (s);
  d = NUM_DEC (s);

  debug ("l=%d d=%d\n", l, d);
  if (l == 0 && d == 0)
    {
      l = size & 256;
      d = size % 256;
      debug ("l=%d d=%d\n", l, d);
    }
  c = 0;
  x = l * 2 - d;

  memset (buff, 0, DBL_DIG1 - 1);

  if (s[0] & 128)
    {
      buff[0] = '-';
      c++;
      x++;
    }

  if (c == x)
    {
      buff[c++] = '.';
      has_zero = 0;
    }

  for (a = OFFSET_DEC (s); a <= l + 1; a++)
    {
      k = DEC_VAL (s[a]);
      buff[c++] = ((int) k / 10) + '0';
      if (buff[c - 1] != '0' && has_zero == 1)
	has_zero = 0;
      if (buff[c - 1] == '0' && has_zero == 1)
	buff[c - 1] = ' ';

      if (c == x)
	{

	  buff[c++] = '.';

	  has_zero = 0;

	}

      buff[c++] = (int) k % 10 + '0';

      if (buff[c - 1] != '0' && has_zero == 1)
	has_zero = 0;
      if (buff[c - 1] == '0' && has_zero == 1)
	buff[c - 1] = ' ';

      if (c == x)
	{

	  buff[c++] = '.';

	  has_zero = 0;

	}
    }

  if (d == 0)
    {
      buff[x] = 0;
      if (buff[x - 1] == ' ')
	buff[x - 1] = '0';
    }

  debug ("has_zero=%d c=%d x=%d", has_zero, c, x);
  return buff;
}

/**
 * Make a subtraction between two decimal values.
 * 
 * @param a The left value.
 * @param b The rigth value.
 * @return The result of the subtraction
 */
char *
minus_dec (char *a, char *b)
{
  static char wrkbuf[3][DBL_DIG1];
  static char cbuff[DBL_DIG1];
  int xlen, xdig;
  int cnt;
  int lb1, hb1, lb2, hb2;
  int n1, n2;
  int carry = 0;
  int acc;
  int neg = 0;
  match_dec (a, b, &xlen, &xdig);
  memset (wrkbuf[0], 0, DBL_DIG1 - 1);
  memset (wrkbuf[1], 0, DBL_DIG1 - 1);
  memset (wrkbuf[2], 0, DBL_DIG1 - 1);
  double_to_dec (0, wrkbuf[0], xlen + 1, xdig);
  double_to_dec (0, wrkbuf[1], xlen + 1, xdig);
  double_to_dec (0, wrkbuf[2], xlen + 1, xdig);
  dec_to_dec (a, wrkbuf[0]);
  dec_to_dec (b, wrkbuf[1]);
  cnt =
    memcmp (&wrkbuf[0][OFFSET_DEC (wrkbuf[0])],
	    &wrkbuf[1][OFFSET_DEC (wrkbuf[1])], NUM_DIG (wrkbuf[0]));
  if (cnt < 0)
    {
      dec_to_dec (wrkbuf[0], wrkbuf[2]);
      dec_to_dec (wrkbuf[1], wrkbuf[0]);
      dec_to_dec (wrkbuf[2], wrkbuf[1]);
      neg = 1;
    }
  memset (wrkbuf[2], 0, DBL_DIG1 - 1);
  double_to_dec (0, wrkbuf[2], xlen + 1, xdig);
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
    negate (wrkbuf[2]);
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
init_dec (char *s, int len, int d)
{
  if (s == 0)
    {
      s = malloc (len + OFFSET_DEC (s));
    }
  memset (s, 0, len + OFFSET_DEC (s));
  SET_DIG (s, len / 2);
  SET_DEC (s, d);
  return s;
}

/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/
/*************************************************************************/

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
  init_dec (wrkbf, 30, 20);
  init_dec (wrkbf2, 20, 6);
  init_dec (wrkbf3, 20, 6);
  str_to_dec ("1.0", wrkbf2);
  str_to_dec ("0.01", wrkbf3);
//print_res(wrkbf2);
  //print_res(wrkbf3);
  //printf("Calculating\n");
  dec_math (wrkbf2, wrkbf3, wrkbf, '*');
  //printf("-9x-0.9 =%s\n",dec_to_str(wrkbf));
  //exercise();


  debug ("0.00003 %s\n", dec_to_str (inv (str_to_dec ("0.00003", 0))));
  debug ("0.0003 %s\n", dec_to_str (inv (str_to_dec ("0.0003", 0))));
  debug ("0.003 %s\n", dec_to_str (inv (str_to_dec ("0.003", 0))));
  debug ("0.03 %s\n", dec_to_str (inv (str_to_dec (".03", 0))));
  debug ("0.3 %s\n", dec_to_str (inv (str_to_dec (".30", 0))));
  debug ("3 %s\n", dec_to_str (inv (str_to_dec ("3.0", 0))));
  debug ("30 %s\n", dec_to_str (inv (str_to_dec ("30.0", 0))));
  debug ("300 %s\n", dec_to_str (inv (str_to_dec ("300.0", 0))));
  debug ("3000 %s\n", dec_to_str (inv (str_to_dec ("3000.0", 0))));
  debug ("30000 %s\n", dec_to_str (inv (str_to_dec ("30000.0", 0))));
  debug ("300000 %s\n", dec_to_str (inv (str_to_dec ("300000.0", 0))));
  exit (0);
  inv (str_to_dec ("1.0", 0));
  inv (str_to_dec ("2.0", 0));
  inv (str_to_dec ("3.0", 0));
  inv (str_to_dec ("4.0", 0));
  inv (str_to_dec ("5.0", 0));
  inv (str_to_dec ("6.0", 0));
  inv (str_to_dec ("7.0", 0));
  inv (str_to_dec ("8.0", 0));
  inv (str_to_dec ("9.0", 0));
  inv (str_to_dec ("10.0", 0));
  inv (str_to_dec ("11.0", 0));
  inv (str_to_dec ("12.0", 0));
  inv (str_to_dec ("13.0", 0));
  inv (str_to_dec ("14.0", 0));
  inv (str_to_dec ("15.0", 0));
  inv (str_to_dec ("16.0", 0));
  inv (str_to_dec ("32.0", 0));
  inv (str_to_dec ("64.0", 0));
}

#endif


/**
 * Make a multiplication between two decimal values.
 *
 * @param s The left factor.
 * @param s The rigth factor.
 * @return The result of the multiplication.
 */
char *
mult_dec (char *s, char *v)
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
  init_dec (buff2, ml * 2, 0);
  init_dec (sumation, ml * 2, 0);
  str_to_dec ("0", buff2);
  str_to_dec ("0", sumation);
  SET_DEC (buff2, 0);
  for (c1 = NUM_DIG (s) - 1; c1 >= 0; c1--)
    {
      memset (buff, 0, sizeof (buff));
      cnt = DBL_DIG1;
      //cnt = 0;
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

      init_dec (sumation, ml * 2, 0);
      dec_math (buff3, buff2, sumation, '+');
      memcpy (buff2, sumation, NUM_BYTES (sumation));
    }

  SET_DEC (buff2, md);
  return buff2;
}

/**
 * For testing purpose.
 *
 * Make some examples of decimal expressions.
 */
exercise ()
{
  char buffx[DBL_DIG1];
  char buffy[DBL_DIG1];
  char buffz[DBL_DIG1];
  double x;
  int xi, yi;
  double y;
  double z;
  double z2;
  char tb1[20];
  char tb2[20];
  init_dec (buffx, 20, 6);
  init_dec (buffy, 20, 6);
  init_dec (buffz, 30, 20);

  for (z = 2; z <= 2; z++)
    {
      for (xi = -99; xi <= 100; xi += 1)
	{

	  for (yi = -100; yi <= 100; yi += 1)
	    {

	      x = (double) xi / (double) 10;

	      y = (double) yi / (double) 10;

	      double_to_dec (x, buffx, 20, 8);
	      double_to_dec (y, buffy, 20, 8);

//printf("x=%lf ",x);debug("%s ",dec_to_str(buffx));debug("y=%lf ",y);debug("%s\n",dec_to_str(buffy));
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

	      sprintf (tb1, "%10.2lf", dec_to_double (buffz));

	      sprintf (tb2, "%10.2lf", z2);

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

		  debug ("**********************\n x=%lf", x);

		  debug (" y=%lf ", y);

		  if (z == 0)
		    {

		      debug ("(+)");

		    }

		  if (z == 1)
		    {

		      debug ("(-)");

		    }

		  if (z == 2)
		    {
		      debug ("(*)");
		    }
		  if (z == 3)
		    {
		      debug ("(/)");
		    }

		  debug (" fix='%s' float='%s'\n", tb1, tb2);

		}

	      //pr(buffz);
	    }

	}
    }
}

/**
 * 
 * @param a The decimal value.
 */
trim_dec (char *s)
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
    negate (s);
}


char *
inv (char *s)
{
  char buff[DBL_DIG1];
  static char buffers[8][DBL_DIG1];
  char mult_by[512];
  char mpoint01[512];
  static char tmpbuff[512];
  char *res;
  int counter = 0;
  int d;
  int a;
  int flg;
  double p;
  memcpy (buff, s, NUM_BYTES (s));
  init_dec (mult_by, 64, 32);
  init_dec (tmpbuff, 64, 32);
  str_to_dec ("1.00", mult_by);
  init_dec (mpoint01, 4, 2);
  str_to_dec ("0.01", mpoint01);

  d = NUM_DEC (buff);

  init_dec (tmpbuff, 64, 32);
  if (NUM_DIG (buff) > NUM_DEC (buff))
    {
      SET_DEC (buff, NUM_DIG (buff) * 2 - 2);

      for (a = d; a < NUM_DIG (buff); a++)
	{
	  init_dec (mpoint01, 4, 2);
	  str_to_dec ("0.01", mpoint01);
	  init_dec (tmpbuff, 64, 32);
	  dec_math (mult_by, mpoint01, tmpbuff, '*');
	  init_dec (mult_by, 64, 32);
	  dec_to_dec (tmpbuff, mult_by);
	}
    }

  init_dec (buffers[0], 2, 0);
  init_dec (buffers[1], 64, 32);
  init_dec (buffers[2], 64, 32);
  init_dec (buffers[3], 64, 32);
  init_dec (buffers[4], 64, 32);
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
      debug ("Divide by zero\n");
      exit (0);
    }
  double_to_dec (p, buffers[1], 32, 16);
  str_to_dec ("2.0", buffers[0]);
  str_to_dec ("0", buffers[3]);

  for (a = 1; a <= 400; a++)
    {
      counter++;
      init_dec (buffers[4], 64, 32);

      dec_math (buffers[1], buff, buffers[4], '*');
      init_dec (buffers[2], 64, 32);
      init_dec (buffers[0], 4, 0);
      str_to_dec ("2.0", buffers[0]);
      dec_math (buffers[0], buffers[4], buffers[2], '-');

      init_dec (buffers[4], 64, 32);
      dec_math (buffers[2], buffers[1], buffers[4], '*');
      if (memcmp (buffers[4], buffers[3], NUM_BYTES (buffers[4])) == 0)
	break;
      memcpy (buffers[3], buffers[4], NUM_BYTES (buffers[4]));
      memcpy (buffers[1], buffers[4], NUM_BYTES (buffers[4]));
    }
  init_dec (buffers[4], 126, 62);
  str_to_dec ("0.00000000000000000000000000000005", buffers[4]);
  init_dec (buffers[1], 126, 62);
  dec_math (buffers[3], buffers[4], buffers[1], '+');
  init_dec (tmpbuff, 64, 32);
  dec_math (mult_by, buffers[1], tmpbuff, '*');

  /* debug ("Done: %s %d interations\n", dec_to_str (tmpbuff), counter); */
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
divide_dec (char *s, char *w)
{
  return mult_dec (s, inv (w));
}

/**
 *
 * @param s
 * @param d
 */
trim_decimals (char *s, int d)
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
	negate (s);
    }
}


/**
 * Dump a value teling the line in the source where was found.
 *
 * Used for debugging purpose only.
 *
 * @param ln The line in the source code
 * @param s The value to be printed to the debug.
 */
print_res_l (int ln, char *s)
{
  static int c = 0;
  //debug ("%4d->%s\n", ln, dec_to_str (s));
  debug ("      ");
  pr (s);
}

/**
 * Dump the information in a string in hexadecimal format.
 *
 * Used just for debugging purpose only.
 *
 * @param s The string to be dumped.
 */
void dump (char *s)
{
  int a;
  char buff[256] = "";
  char buff2[256] = "";
  sprintf (buff, "Dump : %p\n", s);
  for (a = 0; a <= 31; a++)
    {
      sprintf (buff2, "%02x ", s[a] & 0xff);
      strcat (buff, buff2);
    }
  debug (buff);
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
valid_dt (char *s, int *data)
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

  debug ("In valid_dt\n");
  if (strlen (s) > 24)
    {
      debug ("Too long\n");
      return 0;
    }

  strcpy (buff, s);
  ptr[0] = &buff[0];
  debug ("Splitting '%s'\n");
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
      // not something we we're expecting
      debug ("Dodgey character %c\n", buff[a]);
      return 0;
    }

#define DT_YEAR 1
#define DT_MONTH 2
#define DT_DAY 3
#define DT_HOUR 4
#define DT_MINUTE 5
#define DT_SECOND 6
#define DT_FRACTION 7
#define dt_encode(s,e) ((s*16)+e)
  type[cnt] = 0;
  dt_type = -1;
  debug ("cnt=%d\n", cnt);
  debug ("type=%s\n", type);
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
    }				//***

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
    }				//***

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
    return 1;			// single number..
  if (dt_type == 0 && strlen (ptr[0]) == 0)
    return 0;			//nothing...

  b = dt_type & 15;
  a = dt_type >> 4;
  debug ("a=%d b=%d dt_type=%d cnt=%d\n", a, b, dt_type, cnt);

  if (b - a != cnt)
    {
      debug ("mismatch in brackets\n");
      return 0;
    }

  for (i = 0; i < 10; i++)
    {
      data[i] = 0;
    }

  for (i = a; i <= b; i++)
    {
      debug ("i=%d i-a=%d\n", i, i - a);
      if (i == 1 && strlen (ptr[i - a]) != 4)
	{
	  debug ("Year no 4 digits\n");
	  return 0;
	}

      if (i != 1 && strlen (ptr[i - a]) != 2 && i != 7)
	{
	  debug ("expecting 2 digits\n");
	  return 0;
	}

      data[i - 1] = atoi (ptr[i - a]);

      debug ("%s -> '%s'\n", codes[i], ptr[i - a]);
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
valid_int (char *s, int *data,int size)
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

  for (i=0;i<10;i++) {
	data[i]=0;
  }

  size_type=(size>>4)&15;
  debug ("In valid_dt\n");
  if (strlen (s) > 24)
    {
      debug ("Too long\n");
      return 0;
    }

  strcpy (buff, s);
  ptr[0] = &buff[0];
  debug ("Splitting '%s'\n",buff);
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
      // not something we we're expecting
      debug ("Dodgey character %c\n", buff[a]);
      return 0;
    }

#define DT_YEAR 1
#define DT_MONTH 2
#define DT_DAY 3
#define DT_HOUR 4
#define DT_MINUTE 5
#define DT_SECOND 6
#define DT_FRACTION 7
#define dt_encode(s,e) ((s*16)+e)
  type[cnt] = 0;
  dt_type = -1;
  debug ("cnt=%d\n", cnt);
  debug ("type=%s\n", type);

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
    }				//***

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
    }				//***

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

  debug("dt_type= %d\n",dt_type);

  if (dt_type==0) { // Lets assume the programmer knows what he's doing..
	debug("Probably type= %d\n",size_type); 
	dt_type=dt_encode(size_type,size_type);
  }

  if (dt_type == -1)
    return 0;

  if (dt_type == 0 && strlen (ptr[0]))
    return 1;			// single number..

  if (dt_type == 0 && strlen (ptr[0]) == 0)
    return 0;			//nothing...

  b = dt_type & 15;
  a = dt_type >> 4;
  debug ("a=%d b=%d dt_type=%d cnt=%d\n", a, b, dt_type, cnt);

  if (b - a != cnt)
    {
      debug ("mismatch in brackets\n");
      return 0;
    }

  for (i = 0; i < 10; i++)
    {
      data[i] = 0;
    }

  for (i = a; i <= b; i++)
    {
      debug ("i=%d i-a=%d\n", i, i - a);

	if (i==7) {
		char buff[256];
		strcpy(buff,ptr[i-a]);
		strcat(buff,"000000");
		buff[5]=0;
		debug("Setting fraction to %d\n",atoi(buff));
      		data[i - 1] = atoi (buff);
	} else {
      		data[i - 1] = atoi (ptr[i - a]);
	}

      debug ("%s -> '%s'\n", codes[i], ptr[i - a]);
    }
  has_yr_month = 0;
  has_rest = 0;
  if (data[0] || data[1])
    has_yr_month = 1;
  if (data[2] || data[3] || data[4] || data[5] || data[6])
    has_rest = 1;
  if (has_yr_month && has_rest)
    {
      debug ("Can't have month/year and day/hour/second/fraction..\n");
      return 0;
    }
  return 1;
}

/**
 * @param ival
 * @param data
 */
decode_interval (struct ival *ival, int *data)
{
  int a;
  char buff[256];
  int b;
  int i;
  int cnt = 0;
  int has_yr_month = 0;
  char buff2[64];
  int has_rest = 0;
  int buff_size;
  int size_type;
  int s1;
  int s2;
  int c;
  int cpc;
  int c2;

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

  debug("Decoding interval into component parts");

  for (i=0;i<10;i++) {
	data[i]=0;
  }

  s1 = ival->stime % 16;
  s2 = ival->stime / 16;
debug("s1=%d s2=%d",s1,s2);

  sprintf (buff, "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
	   ival->data[0], ival->data[1], ival->data[2], ival->data[3],
	   ival->data[4], ival->data[5],
	   ival->data[6], ival->data[7],
	   ival->data[8], ival->data[9],
	   ival->data[10], ival->data[11],
	   ival->data[12], ival->data[13],
	   ival->data[14], ival->data[15], 
   	   ival->data[16], ival->data[17], ival->data[18]);

debug("buff=%s\n",buff);

  cnt = 0;
  for (c = 1; c < s1; c++)
    {
      debug ("c=%d cnt=%d\n", c, cnt);
      cnt += spc[c];
    }

  debug ("Cnt=%d\n", cnt);
  debug("Taking first part (size=%d) from %d",s2,cnt);

  c=s2;
  strncpy(buff2,&buff[cnt],s2);
  buff2[s2]=0;
  debug("buff2 = '%s'\n",buff2);

  c2 = c;
  for (cpc = s1; cpc < ival->ltime; cpc++)
    {
      debug("cpc=%d buff2=%s c2=%d cnt=%d cnt+c2=%d ",cpc,buff2,c2,cnt,cnt+c2);
      data[cpc-1]=atoi(buff2);

      buff2[0] = buff[cnt + c2];
      c2++;
      if (ival->ltime<7) {
		buff2[1] = buff[cnt + c2]; c2++; buff2[2]=0;
	} else {
		buff2[1] = buff[cnt + c2]; c2++; 
		buff2[2] = buff[cnt + c2]; c2++;
		buff2[3] = buff[cnt + c2]; c2++;
		buff2[4] = buff[cnt + c2]; c2++; buff2[4]=0;
	}
    } 

  debug("cpc=%d buff2=%s",cpc,buff2);
  data[cpc-1]=atoi(buff2);
  for (c=0;c<7;c++) {
	debug("Data : %s %d\n",codes[c],data[c]);
  }
}

