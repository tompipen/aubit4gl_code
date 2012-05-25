/**
 * @file 
 * Functions to handle decimal data type.
 */

#define DEFINES_CONVFMTS

#include "a4gl_libaubit4gl_int.h"

//fgldecimal * A4GL_str_to_dec (char *str, fgldecimal *dec) ;
//int A4GL_conversion_ok(int);
//char *A4GL_dec_to_str (fgldecimal *dec, int size) ;
//******************************************************************************
int A4GL_dectos (void *z, void *w, int size);
int A4GL_stoi (void *aa, void *zi, int sz_ignore);

s_convfmts a4gl_convfmts;

s_convfmts *
A4GL_get_convfmts (void)
{
  return &a4gl_convfmts;
}




void
A4GL_str_dot_to_dec (char *s, fgldecimal * d)
{
  char buff[2000];
  char *ptr;
  strcpy (buff, s);
  ptr = strchr (buff, ',');
  while (ptr)
    {
      *ptr = '.';
      ptr = strchr (ptr, ',');

    }
  if (d->dec_data[0]==0 && d->dec_data[1]==0) { // Auto size..
		int ndec;
		int ndig;
		A4GL_size_decimal_string(buff, &ndig,&ndec);
		A4GL_init_dec(d,ndig,ndec);
  }
  A4GL_str_to_dec (buff, d);

}






/**
 * Initialize default/configured decimal formats
 */
void
A4GL_init_default_formats ()
{
  char *tmp;
  char buf[32];
  float f;

  // generic format
  a4gl_convfmts.posix_decfmt.decsep = '.';
  a4gl_convfmts.posix_decfmt.thsep = 0;

  // a4gl default numeric format
  a4gl_convfmts.report_print_decfmt.decsep = '.';
  a4gl_convfmts.report_print_decfmt.thsep = 0;

  a4gl_convfmts.ui_decfmt.decsep = '.';
  a4gl_convfmts.ui_decfmt.thsep = 0;

  if (acl_getenv_not_set_as_0("A4GL_REPORT_NUMERIC")) {
  	tmp = acl_getenv ("A4GL_REPORT_NUMERIC");
  } else {
  	tmp = acl_getenv ("A4GL_NUMERIC");
  }

  if (tmp)
    {
      if (tmp[0])
	{
	  a4gl_convfmts.report_print_decfmt.decsep = tmp[0];
	  if (tmp[1])
	    a4gl_convfmts.report_print_decfmt.thsep = tmp[1];
	}
    }


  tmp = acl_getenv ("A4GL_NUMERIC");
  if (tmp)
    {
      if (tmp[0])
	{
	  a4gl_convfmts.ui_decfmt.decsep = tmp[0];
	  if (tmp[1])
	    a4gl_convfmts.ui_decfmt.thsep = tmp[1];
	}
    }

  // db client library default numeric format
  a4gl_convfmts.db_decfmt.decsep = '.';
  a4gl_convfmts.db_decfmt.thsep = 0;
  tmp = acl_getenv ("A4GL_DB_NUMERIC");
  if (tmp)
    {
      if (tmp[0])
	{
	  a4gl_convfmts.db_decfmt.decsep = tmp[0];
	  if (tmp[1])
	    a4gl_convfmts.db_decfmt.thsep = tmp[1];
	}
    }

  // detected 'printf' numeric format
  SPRINTF1 (buf, "%f", 1.1);
  a4gl_convfmts.printf_decfmt.decsep = buf[1];
  SPRINTF1 (buf, "%f", 1111.1);
  a4gl_convfmts.printf_decfmt.thsep = (buf[1] >= '0' && buf[1] <= '9') ? 0 : buf[1];

  // detected 'scanf' numeric format
  // set scanf_decfmt to printf_decfmt (I suspect it should always be overwritten, but who knows...)
  a4gl_convfmts.scanf_decfmt.decsep = a4gl_convfmts.printf_decfmt.decsep;
  a4gl_convfmts.scanf_decfmt.thsep = a4gl_convfmts.printf_decfmt.thsep;
  f = 0;
  if (sscanf ("1.2", "%f", &f) == 1 && f > 1.1 && f < 1.3)
    a4gl_convfmts.printf_decfmt.decsep = '.';
  else if (sscanf ("1,2", "%f", &f) == 1 && f > 1.1 && f < 1.3)
    a4gl_convfmts.printf_decfmt.decsep = ',';
  f = 0;
  if (sscanf ("1.111", "%f", &f) == 1 && f > 1000)
    a4gl_convfmts.printf_decfmt.thsep = '.';
  else if (sscanf ("1,111", "%f", &f) == 1 && f > 1000)
    a4gl_convfmts.printf_decfmt.thsep = ',';


  // forced 'scanf' numeric format for broken scanf
  // normally it should be the same as printf
  // and for '.' and ',' it should be succesfully autodetected
  tmp = acl_getenv ("A4GL_SCANF_NUMERIC");
  if (tmp)
    {
      if (tmp[0])
	{
	  a4gl_convfmts.scanf_decfmt.decsep = tmp[0];
	  if (tmp[1])
	    a4gl_convfmts.scanf_decfmt.thsep = tmp[1];
	}
    }

  a4gl_convfmts.using_decfmt = a4gl_convfmts.ui_decfmt;
  a4gl_convfmts.using_decfmt.thsep = 0;

#ifdef DEBUG
  A4GL_debug ("Default numeric formats: a4gl=<%c%c> db=<%c%c> printf=<%c%c> scanf=<%c%c> using=<%c%c>\n",
	      a4gl_convfmts.ui_decfmt.decsep ? a4gl_convfmts.ui_decfmt.decsep : 'N',
	      a4gl_convfmts.ui_decfmt.thsep ? a4gl_convfmts.ui_decfmt.thsep : 'N',
	      a4gl_convfmts.db_decfmt.decsep ? a4gl_convfmts.db_decfmt.decsep : 'N',
	      a4gl_convfmts.db_decfmt.thsep ? a4gl_convfmts.db_decfmt.thsep : 'N',
	      a4gl_convfmts.printf_decfmt.decsep ? a4gl_convfmts.printf_decfmt.decsep : 'N',
	      a4gl_convfmts.printf_decfmt.thsep ? a4gl_convfmts.printf_decfmt.thsep : 'N',
	      a4gl_convfmts.scanf_decfmt.decsep ? a4gl_convfmts.scanf_decfmt.decsep : 'N',
	      a4gl_convfmts.scanf_decfmt.thsep ? a4gl_convfmts.scanf_decfmt.thsep : 'N',
	      a4gl_convfmts.using_decfmt.decsep ? a4gl_convfmts.using_decfmt.decsep : 'N',
	      a4gl_convfmts.using_decfmt.thsep ? a4gl_convfmts.using_decfmt.thsep : 'N');

#endif
}

/**
 * Convert decimal string from one format to another,
 *   also strips all unneeded whitespace,
 *   if conversion fails then conversion result is ""
 *
 * @param buf    source buffer (if newbuf == 0 also a destination)
 * @param from   source format
 * @param to     destination format
 * @param newbuf    0: place result in buf
 *               != 0: allocate a new buffer and place the result in it
 * @param trim   0: do not trim the string
 *               != 0: trim the string
 * @param maxlen maximum length of the string, not including terminating \000,
 *               -1: don't care; if the string after conversion is longer than
 *               a given maximum it is filled with '*'s.
 *               if the string does not fit in the buffer, but it is left
 *               padded with sufficient number of whitespace to fit, it is
 *               shifted to the left.
 * @return       buf or a newly allocated buffer
 */
char *
A4GL_decstr_convert (char *buf, s_decfmt from, s_decfmt to, int newbuf, int trim, int maxlen)
{
#define MAX_DECSTR_SIZE 512	// should be sufficient for any weird string, even
  // padded with lot of whitespace
  enum e_state
  {
    DEC_STATE_S_0 = 0,
    DEC_STATE_S_SGN = 1,
    DEC_STATE_S_BD = 2,
    DEC_STATE_S_AD1 = 3,
    DEC_STATE_S_AD2 = 4,
    DEC_STATE_S_AN = 5,
    DEC_STATE_S_OK = 6,
    DEC_STATE_S_ERR = 7
  };
  enum e_state st = DEC_STATE_S_0;
  char b[MAX_DECSTR_SIZE + 2];
  int dpos;
  int i, c, o;
  char *optr;
  char sign = 0;
  // find a decimal separator
#ifdef DEBUG
  A4GL_debug ("Converting \"%s\" %c%c->%c%c", buf,
	      from.decsep, from.thsep ? from.thsep : 'N', to.decsep, to.thsep ? to.thsep : 'N');
#endif
  for (dpos = 0; buf[dpos]; ++dpos)
    {
      if (buf[dpos] == from.decsep)
	break;
    }

  for (i = o = 0; st != DEC_STATE_S_ERR && st != DEC_STATE_S_OK && i < MAX_DECSTR_SIZE - 1 && o < MAX_DECSTR_SIZE - 1; ++i)
    {
      c = buf[i];
      switch (st)
	{
	case DEC_STATE_S_0:
	  if (c >= '0' && c <= '9')
	    {
	      b[o++] = c;
	      st = DEC_STATE_S_BD;
	    }
	  else if (c == from.decsep)
	    {
	      b[o++] = to.decsep;
	      st = DEC_STATE_S_AD1;
	    }
	  else if (c == '-' || c == '+')
	    {
	      b[o++] = c;
	      sign = c;
	      st = DEC_STATE_S_SGN;
	    }
	  else if (c == '\t' || c == ' ')
	    {
	      if (!trim)
		b[o++] = c;
	      st = DEC_STATE_S_0;
	    }
	  else if (c == 0)
	    {
	      st = DEC_STATE_S_OK;
	    }
	  else
	    {
#ifdef DEBUG
	      A4GL_debug ("parse error, state %i\n", st);
#endif
	      st = DEC_STATE_S_ERR;
	    }
	  break;
	case DEC_STATE_S_SGN:
	  if (c >= '0' && c <= '9')
	    {
	      b[o++] = c;
	      st = DEC_STATE_S_BD;
	    }
	  else if (c == from.decsep)
	    {
	      b[o++] = to.decsep;
	      st = DEC_STATE_S_AD1;
	    }
	  else if (c == '\t' || c == ' ')
	    {
	      if (!trim)
		b[o++] = c;
	      st = DEC_STATE_S_SGN;
	    }
	  else
	    {
#ifdef DEBUG
	      A4GL_debug ("parse error, state %i\n", st);
#endif
	      st = DEC_STATE_S_ERR;
	    }
	  break;
	case DEC_STATE_S_BD:
	  if (dpos - i && (dpos - i) % (from.thsep ? 4 : 3) == 0 && to.thsep)
	    b[o++] = to.thsep;
	  if (c >= '0' && c <= '9')
	    {
	      b[o++] = c;
	      st = DEC_STATE_S_BD;
	    }
	  else if (c == from.decsep)
	    {
	      b[o++] = to.decsep;
	      st = DEC_STATE_S_AD1;
	    }
	  else if (from.thsep && c == from.thsep)
	    {
	      st = DEC_STATE_S_BD;
	    }
	  else if (c == '\t' || c == ' ')
	    {
	      if (!trim)
		b[o++] = c;
	      st = DEC_STATE_S_AN;
	    }
	  else if (c == 0)
	    {
	      st = DEC_STATE_S_OK;
	    }
	  else
	    {
#ifdef DEBUG
	      A4GL_debug ("parse error, state %i\n", st);
#endif
	      st = DEC_STATE_S_ERR;
	    }
	  break;
	case DEC_STATE_S_AD1:
	  if (c >= '0' && c <= '9')
	    {
	      b[o++] = c;
	      st = DEC_STATE_S_AD2;
	    }
	  else
	    {
#ifdef DEBUG
	      A4GL_debug ("parse error, state %i\n", st);
#endif
	      st = DEC_STATE_S_ERR;
	    }
	  break;
	case DEC_STATE_S_AD2:
	  if (c >= '0' && c <= '9')
	    {
	      b[o++] = c;
	      st = DEC_STATE_S_AD2;
	    }
	  else if (from.thsep && c == from.thsep && i - dpos && (i - dpos) % (from.thsep ? 4 : 3) == 0)
	    {
	      if (to.thsep)
		b[o++] = to.thsep;
	      st = DEC_STATE_S_AD2;
	    }
	  else if (c == '\t' || c == ' ')
	    {
	      if (!trim)
		b[o++] = c;
	      st = DEC_STATE_S_AN;
	    }
	  else if (c == 0)
	    {
	      st = DEC_STATE_S_OK;
	    }
	  else
	    {
#ifdef DEBUG
	      A4GL_debug ("parse error, state %i\n", st);
#endif
	      st = DEC_STATE_S_ERR;
	    }
	  break;
	case DEC_STATE_S_AN:
	  if (c == '\t' || c == ' ')
	    {
	      if (!trim)
		b[o++] = c;
	      st = DEC_STATE_S_AN;
	    }
	  else if (c == 0)
	    {
	      st = DEC_STATE_S_OK;
	    }
	  else
	    {
#ifdef DEBUG
	      A4GL_debug ("parse error, state %i\n", st);
#endif
	      st = DEC_STATE_S_ERR;
	    }
	  break;
	default:
	  st = DEC_STATE_S_ERR;
	  break;
	}
    }
  b[o] = 0;
  if (st != DEC_STATE_S_OK)
    b[0] = 0;

  optr = b;
  //if (maxlen != -1 && st != DEC_STATE_S_OK)  /* Breaks 1643 1653 */
  if (maxlen != -1)
    {
      if (o > maxlen)
	{
	  if (trim)
	    {
#ifdef DEBUG
	      A4GL_debug ("maxlen exceeded, filling with '*'s");
#endif
	      memset (optr, '*', maxlen);
	      optr[maxlen] = 0;
	    }
	  else
	    {
#ifdef DEBUG
	      A4GL_debug ("maxlen exceeded, trying to grab the whitespace, if possible");
#endif
	      int bl = 0;
	      if (sign)
		{
		  for (i = 0; optr[i]; ++i)
		    {
		      if (optr[i] == '+' || optr[i] == '-')
			optr[i] = ' ';
		    }
		  for (i = 0; optr[i]; ++i)
		    {
		      if ((optr[i] >= '0' && optr[i] <= '9') || optr[i] == to.decsep)
			{
			  optr[i - 1] = sign;
			  break;
			}
		    }
		}
	      bl = strlen (optr);
	      for (i = 0; optr[i] == ' ' || optr[i] == '\t'; ++i, --bl, ++optr)
		{
		  if (bl <= maxlen)
		    break;
		}
	      if (bl > maxlen && to.thsep)
		{
#ifdef DEBUG
		  A4GL_debug ("maxlen exceeded, trying to grab thousand separators");
#endif
		  s_decfmt tmpfrom = to;
		  s_decfmt tmpto = to;
		  from.thsep = to.thsep;
		  tmpto.thsep = (int) NULL;
		  A4GL_decstr_convert (optr, tmpfrom, tmpto, 0, 1, maxlen);
		  bl = strlen (optr);
		}
	      if (bl > maxlen)
		{
#ifdef DEBUG
		  A4GL_debug ("maxlen exceeded, filling with '*'s");
#endif
		  memset (optr, '*', maxlen);
		  optr[maxlen] = 0;
		}
	    }
	}
    }

#ifdef DEBUG
  A4GL_debug ("Conversion result\"%s\"", optr);
#endif
  if (newbuf)
    return strdup (optr);
  strcpy (buf, optr);
  return buf;
}


int
A4GL_is_meaningful_in_decfmt (s_decfmt fmt, char c)
{
  if (c == fmt.decsep)
    return 1;
  if (c == fmt.thsep || c == ' ' || c == ',' || c == '.' || c == '$' || c == '�')
    return 0;
  return 1;
}

//******************************************************************************

/**
 * Initialize a decimal type variable
 *
 * @param dec A pointer to the decimal being initialized.
 * @param length The total length of the decimal.
 * @param digits The number of decimal digits of the decimal.
 *
 * @return The pointer to the decimal initialized.
 */
fgldecimal *
A4GL_init_dec (fgldecimal * dec, int length, int digits)
{
  dec->dec_data[0] = length;
  dec->dec_data[1] = digits;
  return dec;
}


// Initialize a decimal type variable - based on the encoded size...
void A4GL_init_dec_size(fgldecimal *dec, int size) {

dec->dec_data[0]=size>>8;
dec->dec_data[1]=size&0xff;
}

/**
 * Convert a string to a decimal value.
 *
 * @param str The string to be converted.
 * @param dec A pointer to the decimal where the value will be inserted.
 * The string should be in posix format - ie with a '.' as the decimal separator
 * using the A4GL_decstr_convert prior ro calling this function if you want to pass 
 * something different..
 */
fgldecimal *
A4GL_str_to_dec (char *str_orig, fgldecimal * dec)
{
  char head[256];
  char head2[256];
  char tail[256];
  char tmp[3];
  int a;
  int isneg = 0;
  int sec = 'f';
  int digits;
  int decimals;
  int head_len;
  int tail_len;
  long head_i;
  char buff[256];
  char str[1024];
  int round_cnt;
  int carry;
  int l2;
  char tmpbuf[2];
  A4GL_strncpyz (str, str_orig, sizeof (str));
//A4GL_remove_trailing_zeros_and_leading_spaces(str);
  A4GL_trim (str);
#ifdef DEBUG
  A4GL_debug ("XYXY str to dec : '%s'", str);
#endif

#ifdef NUMCHECK
  if (strchr(str,',')) {
		// Check we have a posix style decimal...
		char *pcomma=strchr(str,',');
		char *pdot=strchr(str,'.');
		if (pdot==0) { A4GL_assertion(1,"A4GL_str_to_dec called with a non posix decimal string"); }
		else {
			if (pdot<pcomma) { 
				A4GL_assertion(1,"A4GL_str_to_dec called with a non posix decimal string"); 
			}
		}
  }
#endif

  digits = dec->dec_data[0] & 127;
  decimals = dec->dec_data[1];

  memset (head, 0, 256);
  memset (tail, 0, 256);

  l2 = strlen (str);
  /* Parse our string. */
  for (a = 0; a < l2; a++)
    {
      if (str[a] == ' ' && (sec == 't' || sec == 'h'))
	{
	  sec = 'e';
	  continue;
	}
      if (str[a] == ' ' && (sec == 'f' || sec == 'e'))
	continue;
      if (str[a] == '-' && sec == 'f')
	{
	  sec = 'h';
	  isneg = 1;
	  continue;
	}
      if (str[a] == '+' && sec == 'f')
	{
	  sec = 'h';
	  isneg = 0;
	  continue;
	}

      if (str[a] >= '0' && str[a] <= '9' && (sec == 'f' || sec == 'h' || sec == 't'))
	{
	  if (sec == 'f')
	    sec = 'h';
	  if (sec == 'h' && str[a] == '0' && strlen (head) == 0)
	    continue;
	  tmp[0] = str[a];
	  tmp[1] = 0;

	  if (sec == 'h')
	    strcat (head, tmp);
	  else
	    strcat (tail, tmp);

	  continue;
	}

      if (str[a] == '.' && (sec == 'h' || sec == 'f'))
	{
	  sec = 't';
	  continue;
	}
      if (str[a] == '$')
	{
	  continue;
	}

      // Dodgey character ?
      // Informix seems to set the value to 0 not null...
      // which seems inconsistant with the handling of bad dates..
      //
      // Ho hum  - make it switchable, but use the Informix action as
      // the default..
      //
      A4GL_conversion_ok (0);
      if (A4GL_isyes (acl_getenv ("A4GL_NULL_DECIMAL_IF_BAD")))
	{
#ifdef DEBUG
	  A4GL_debug ("Bad...");
#endif
	  A4GL_setnull (DTYPE_DECIMAL, dec, dec->dec_data[0] * 256 + dec->dec_data[1]);
	}
      else
	{
#ifdef DEBUG
	  A4GL_debug ("Bad...");
#endif
	  return A4GL_str_to_dec ("0", dec);
	}
      return dec;
    }

  /* We should now have two strings - head and tail */

  head_i = atoi (head);
#ifdef DEBUG
  A4GL_debug ("digits=%d decimals=%d\n", digits, decimals);
#endif

  head_len = digits - decimals;
  if (head_len < 0)
    {
      A4GL_assertion (1, "Head_len <0 - do we have a decimal(1) [== decimal(1,2)] ?");
    }
  tail_len = decimals;

  if (strlen (head) > digits - decimals)
    {
      // Its too big..
#ifdef DEBUG
      A4GL_debug ("Bad %s %d - %d %d ", head, strlen (head), digits, decimals);
#endif
      A4GL_setnull (DTYPE_DECIMAL, dec, dec->dec_data[0] * 256 + dec->dec_data[1]);
      return dec;
    }
  strcat (tail, "00000000000000000000000000000");
  tail[decimals + 1] = 0;


  // now round the tail..
  carry = 0;
  round_cnt = decimals;
  if (tail[round_cnt] >= '5')
    {
      carry = 1;
    }

  while (carry)
    {
#ifdef DEBUG
      A4GL_debug ("Doing Carry... %s", tail);
#endif
      round_cnt--;
      if (round_cnt < 0)
	break;
      tail[round_cnt]++;
      if (tail[round_cnt] <= '9')
	{
	  carry = 0;
	  break;
	}
      if (tail[round_cnt] > '9')
	tail[round_cnt] = '0';
    }

  if (carry)
    {

      head_i++;
    }

  tail[decimals] = 0;
#ifdef DEBUG
  A4GL_debug ("head_len=%d", head_len);
  A4GL_debug ("head_i=%d head='%s'", head_i, head);
#endif
  SPRINTF2 (buff, "%0*ld", head_len, head_i);
  memset (head2, '0', 255);

  head2[head_len] = 0;
  strcpy (&head2[head_len - strlen (head)], head);
  if (carry)
    {
      for (a = strlen (head2) - 1; a >= 0; a--)
	{
	  head2[a]++;
	  if (head2[a] <= '9')
	    break;
	  head2[a] = '0';
	}
    }
  strcpy (buff, head2);
#ifdef DEBUG
  A4GL_debug ("head2=%s\n", head2);
#endif


  strcpy ((char *)&dec->dec_data[2], buff);
  tmpbuf[0] = a4gl_convfmts.posix_decfmt.decsep;
  tmpbuf[1] = 0;
  strcat ((char *)&dec->dec_data[2], tmpbuf);
  strcat ((char *)&dec->dec_data[2], tail);

  //while  (strlen(&dec->dec_data[2])!=digits+1) { strcat(&dec->dec_data[2],"0"); }

  dec->dec_data[0] = dec->dec_data[0] & 127;
  if (isneg)
    {

      dec->dec_data[0] += 128;
    }

#ifdef DEBUG
  A4GL_debug ("----> %s\n", &dec->dec_data[2]);
#endif
  return dec;
}

/**
 * Convert a decimal to a string.
 *
 * @param dec a pointer to the decimal that will be converted.
 * @param size The total size of the decimal
 * @return A pointer to a static buffer that contains the decimal.
 */
char *
A4GL_dec_to_str (fgldecimal * dec, int size)
{
  static char buff[256];
  //char buff2[256];
  int a;
  char *ptr;
  int has_neg = 0;
  int l;
  strcpy (buff, " ");
  if (dec->dec_data[0] & 128)
    {
      has_neg = 1;
    }
#ifdef DEBUG
  A4GL_debug("Decimal %d %d\n", dec->dec_data[0] &127, dec->dec_data[1]);
  A4GL_debug ("XYXY dec to str : %s", &dec->dec_data[2]);
#endif
  ptr = (char *)&dec->dec_data[2];
  strcat (buff, ptr);
#ifdef DEBUG
A4GL_debug("ptr=%s\n",ptr);
#endif
  l = strlen (buff);
  for (a = has_neg; a < l; a++)
    {
      if (buff[a] == a4gl_convfmts.posix_decfmt.decsep)
	break;
      if (buff[a] == ' ')
	continue;
      if (buff[a] == '0' && a == strlen (buff) - 2 && buff[a + 1] == a4gl_convfmts.posix_decfmt.decsep)
	break;
      if (buff[a] == '0')
	{
	  buff[a] = ' ';
	  continue;
	}
      //if (buff[a]=='-') continue;
      break;
    }
  A4GL_trim (buff);
  if (buff[strlen (buff) - 1] == a4gl_convfmts.posix_decfmt.decsep)
    buff[strlen (buff) - 1] = 0;

#ifdef DEBUG
  A4GL_debug ("--->XYXY '%s'", buff);
#endif

  if (has_neg)
    {
      l = strlen (buff);
      for (a = 0; a < l; a++)
	{
	  if (buff[a] != ' ')
	    {
	      buff[a - 1] = '-';
	      break;
	    }
	}
    }
  if (strncmp (buff, "-.", 2) == 0)
    {
      char buff2[2000];
      strcpy (buff2, "-0.");
      strcat (buff2, &buff[2]);
      strcpy (buff, buff2);
    }
  if (strncmp (buff, ".", 1) == 0)
    {
      char buff2[2000];
      strcpy (buff2, "0.");
      strcat (buff2, &buff[1]);
      strcpy (buff, buff2);
    }


  return buff;
}


static void trim_trailing_zero(char *s) {
int a;
int l;
a=strlen(s)-1;
for (l=a;l>0;l--) {
	if (s[l]!='0') break;
	s[l]=0;
}
}

// Try to get the best formatting for a double
// regardless of the size of any fields etc
// we will take the most significant 8 digits or so...
char *formatDouble(double d,int useExponent) {
static char buff[3000];
char buff2[2000];
char *eptr;
int npow;
int ndec;
SPRINTF1(buff,"%+1.8e",d);
eptr=strchr(buff,'e');
A4GL_assertion(eptr==0,"internal error - 'e' not found in proper place");
*eptr=0;
eptr++;
strcpy(buff2,buff);
trim_trailing_zero(buff2);
if (atol(eptr)<=-31 && useExponent) {
	sprintf(buff,"%.6e",d);
	return buff;
}
npow=atol(eptr)-strlen(buff2)+3;
ndec=0;
if (npow<0) {
	ndec=0-npow;
} else {
	npow=npow;
	if (npow<0) {
		ndec=0-npow;
	} 
}
	
sprintf(buff,"%.*f",ndec,d);
	// +1.00100000e+00
	//1.00100000e+00

A4GL_debug(">>%s<< %f (ndec=%d)\n", buff, d,ndec);
return buff;
}

#ifdef USE_MAPM

#include "m_apm.h"

void A4GL_push_dec_from_apm (M_APM tmp);




// Work out the correct precision for a fgldecimal 
// based on the mpam 'm1' value (by converting it to a string)
static void set_fgl_decimal_precision_from_apm_decimal(fgldecimal *d, M_APM m1) {
char s1[200];

// Check to see if we actually need to do anything...
  if (d->dec_data[0]==0 && d->dec_data[1]==0) { // Auto size..
	int ndig;
	int ndec;
	int len;
	int len2;
	char *ptr;
		len=m_apm_significant_digits(m1);
		len2=m_apm_exponent(m1);
		m_apm_to_fixpt_string(s1,len-len2,m1);
		ptr=strchr(s1,'.');
		if (ptr) {
			int a;
			for (a=strlen(ptr)-1;a>0;a--) {
				if (ptr[a]!='0') {
					break;
				}
				ptr[a]=0;
			}
		}
		A4GL_size_decimal_string(s1,&ndig,&ndec);

		// If we're too large - try trimming off any trailing decimal places..
		while (ndig>64 && ndec>0) {
			ndig--;
			ndec--;
		}
		if (ndig>64) {
			// Its still too big..
			ndig=64;
			ndec=0;
		}


		A4GL_init_dec(d,ndig,ndec);
  }


}

void acl_apm_set_string (M_APM m1, char *s, int convert)
{
  char buff[2000];
  strcpy (buff, s);
  if (strchr (s, '.') == 0 && strchr (s, ',') != 0 && convert && a4gl_convfmts.printf_decfmt.decsep == ',')
    {
      A4GL_assertion (1, "set string from real decimal");
    }
  A4GL_trim (buff);
  m_apm_set_string (m1, buff);
}


int
a4gl_decadd (fgldecimal * d1, fgldecimal * d2, fgldecimal * sum)
{
  M_APM m1;
  M_APM m2;
  M_APM mres;
  char buff[2000];
  m1 = m_apm_init ();
  m2 = m_apm_init ();
  mres = m_apm_init ();

  acl_apm_set_string (m1, A4GL_dec_to_str (d1, 0), 1);
  acl_apm_set_string (m2, A4GL_dec_to_str (d2, 0), 1);

  m_apm_add (mres, m1, m2);

  set_fgl_decimal_precision_from_apm_decimal(sum,mres);


  m_apm_to_fixpt_string (buff, sum->dec_data[1], mres);
  A4GL_str_dot_to_dec (buff, sum);

  m_apm_free (m1);
  m_apm_free (m2);
  m_apm_free (mres);

  return 0;
}

int
a4gl_deccmp (fgldecimal * d1, fgldecimal * d2)
{
  int a;
  M_APM m1;
  M_APM m2;
  char p1[1000];
  char p2[1000];
  //char buff[200];
  m1 = m_apm_init ();
  m2 = m_apm_init ();
  strcpy (p1, A4GL_dec_to_str (d1, 0));
  strcpy (p2, A4GL_dec_to_str (d2, 0));
  acl_apm_set_string (m1, p1, 1);
  acl_apm_set_string (m2, p2, 1);
  a = m_apm_compare (m1, m2);
  m_apm_free (m1);
  m_apm_free (m2);

  return a;
}



int
a4gl_deccvdbl (double d, fgldecimal * d1)
{
  char buff[200];
  SPRINTF1 (buff, "%32.16lf", d);
  A4GL_str_dot_to_dec (buff, d1);
  return 0;
}

int
a4gl_deccvflt (float d, fgldecimal * d1)
{
  char buff[200];
  SPRINTF1 (buff, "%32.16f", d);
  A4GL_str_dot_to_dec (buff, d1);
  return 0;
}

int
a4gl_deccvint (int i, fgldecimal * d)
{
  char buff[200];
  SPRINTF1 (buff, "%d", i);
  A4GL_str_dot_to_dec (buff, d);
  return 0;
}

int
a4gl_deccvlong (long l, fgldecimal * d)
{
  char buff[200];
  SPRINTF1 (buff, "%ld", l);
  A4GL_str_dot_to_dec (buff, d);

  return 0;
}

int
a4gl_decdiv (fgldecimal * d1, fgldecimal * d2, fgldecimal * res)
{
  M_APM m1;
  M_APM m2;
  M_APM mres;
  char buff[2000];
  m1 = m_apm_init ();
  m2 = m_apm_init ();
  mres = m_apm_init ();

  acl_apm_set_string (m2, A4GL_dec_to_str (d2, 0), 1);
  acl_apm_set_string (m1, "0", 1);
  if (m_apm_compare (m1, m2) == 0)
    {				//
      // Divide by zero!
      A4GL_setnull (DTYPE_DECIMAL, res, res->dec_data[0] * 256 + res->dec_data[1]);

      return 0;

    }


  acl_apm_set_string (m1, A4GL_dec_to_str (d1, 0), 1);


  m_apm_divide (mres, res->dec_data[1] + 1, m1, m2);

  set_fgl_decimal_precision_from_apm_decimal(res,mres);
  m_apm_to_fixpt_string (buff, res->dec_data[1], mres);

  A4GL_str_dot_to_dec (buff, res);

  m_apm_free (m1);
  m_apm_free (m2);
  m_apm_free (mres);

  return 0;
}


int
a4gl_decmul (fgldecimal * d1, fgldecimal * d2, fgldecimal * res)
{
  M_APM m1;
  M_APM m2;
  M_APM mres;
  char buff[2000];
  char s1[2000];
  char s2[2000];
  m1 = m_apm_init ();
  m2 = m_apm_init ();
  mres = m_apm_init ();

  strcpy(s1,A4GL_dec_to_str (d1, 0));
  strcpy(s2,A4GL_dec_to_str (d2, 0));
  acl_apm_set_string (m1, s1, 1);
  acl_apm_set_string (m2, s2, 1);

  m_apm_multiply (mres, m1, m2);

  set_fgl_decimal_precision_from_apm_decimal(res,mres);

  m_apm_to_fixpt_string (buff, res->dec_data[1], mres);
  A4GL_str_dot_to_dec (buff, res);

  m_apm_free (m1);
  m_apm_free (m2);
  m_apm_free (mres);

  return 0;
}

void
a4gl_decround (fgldecimal * d1, int n)
{
  M_APM m1;
  char buff[200];
  m1 = m_apm_init ();
  acl_apm_set_string (m1, A4GL_dec_to_str (d1, 0), 1);

  set_fgl_decimal_precision_from_apm_decimal(d1,m1);
  m_apm_to_fixpt_string (buff, n, m1);
  A4GL_str_dot_to_dec (buff, d1);
  m_apm_free (m1);
}


int
a4gl_decsub (fgldecimal * d1, fgldecimal * d2, fgldecimal * res)
{
  M_APM m1;
  M_APM m2;
  M_APM mres;
  char buff[2000];
  m1 = m_apm_init ();
  m2 = m_apm_init ();
  mres = m_apm_init ();

  acl_apm_set_string (m1, A4GL_dec_to_str (d1, 0), 1);
  acl_apm_set_string (m2, A4GL_dec_to_str (d2, 0), 1);

  m_apm_subtract (mres, m1, m2);

  set_fgl_decimal_precision_from_apm_decimal(res,mres);
  m_apm_to_fixpt_string (buff, res->dec_data[1], mres);
  A4GL_str_dot_to_dec (buff, res);

  m_apm_free (m1);
  m_apm_free (m2);
  m_apm_free (mres);

  return 0;
}

int
a4gl_dectoasc (fgldecimal * d, char *s, int l, int right)
{
  M_APM m1;
  char buff[2000];
  m1 = m_apm_init ();
  acl_apm_set_string (m1, A4GL_dec_to_str (d, 0), 1);
  m_apm_to_fixpt_string (buff, right, m1);
  if (strlen (buff) > l)
    {
      return -1;
    }
  else
    {
      strcpy (s, buff);
    }
  return 0;
}

int
a4gl_dectodbl (fgldecimal * d1, double *d)
{
//char buff[256];
  A4GL_stof (A4GL_dec_to_str (d1, 0), d, 0);
  return 0;
}

int
a4gl_dectoint (fgldecimal * d1, int *ival)
{
  A4GL_stoi (A4GL_dec_to_str (d1, 0), ival, 0);
  return 0;
}

int
a4gl_dectolong (fgldecimal * d1, long *lval)
{
  A4GL_stol (A4GL_dec_to_str (d1, 0), lval, 0);
  return 0;
}

void
a4gl_dectrunc (fgldecimal * d1, int n)
{
  M_APM m1;
  M_APM m_mult;
  M_APM m10;
  M_APM mres;
  char buff[200];
  int norig;
  norig = n;

  m1 = m_apm_init ();
  m_mult = m_apm_init ();
  m10 = m_apm_init ();
  mres = m_apm_init ();

  acl_apm_set_string (m1, A4GL_dec_to_str (d1, 0), 1);

  m_apm_set_long (m_mult, 1);
  m_apm_set_long (m10, 10);

// We'll need to multiply up our value to floor it..
// this trims it back to an integer
// by multiplying up by factors of 10 - we get the number of decimal
// places when we convert it back later
//
  if (n)
    {
      while (n)
	{
	  m_apm_multiply (mres, m_mult, m10);
	  m_apm_copy (m_mult, mres);
	  n--;
	}

      // multiply our number by our factor..
      m_apm_multiply (mres, m1, m_mult);
      m_apm_copy (m1, mres);
    }


  if (m_apm_sign (m1) < 0)
    {
      m_apm_ceil (mres, m1);
    }
  else
    {
      m_apm_floor (mres, m1);
    }

  m_apm_divide (m1, norig, mres, m_mult);

  set_fgl_decimal_precision_from_apm_decimal(d1,m1);
// m1 should now be truncated to n decimal places..
  m_apm_to_fixpt_string (buff, d1->dec_data[1] + 1, m1);
  A4GL_str_dot_to_dec (buff, d1);
}


void
A4GL_push_dec_from_apm (M_APM tmp)
{
  fgldecimal d;
  char buff[300];
  A4GL_init_dec (&d, 0, 0);
  set_fgl_decimal_precision_from_apm_decimal(&d,tmp);
  m_apm_to_fixpt_string (buff, d.dec_data[1], tmp);
  A4GL_str_dot_to_dec (buff, &d);
  A4GL_push_dec_dec (&d, 0, 16);
}

static M_APM
A4GL_str_dot_to_m_apm (char *s)
{
  M_APM ret;
  char buff[2000];
  char *ptr;
  strcpy (buff, s);
  ptr = strchr (buff, ',');
  while (ptr)
    {
      *ptr = '.';
      ptr = strchr (ptr, ',');

    }

  ret = m_apm_init ();

  acl_apm_set_string (ret, s, 0);

  return ret;

}



// s1 = String for first parameter
// s2 = string for second parameter (or 0 is its just a range check)
// op = Operation being performed
// overflow_dtype = datatype to check range for..
int
A4GL_apm_str_detect_overflow (char *s1, char *s2, int op, int overflow_dtype)
{
  char buff[256];
  M_APM m1;
  M_APM m2;
  M_APM mres;
  int o;
  fgldecimal *sum;
  if (s2)
    {
      mres = m_apm_init ();
      m1 = A4GL_str_dot_to_m_apm (s1);
      m2 = A4GL_str_dot_to_m_apm (s2);

      switch (op)
	{
	case OP_ADD:
	  m_apm_add (mres, m1, m2);
	  break;

	case OP_SUB:
	  m_apm_subtract (mres, m1, m2);
	  break;

	case OP_MULT:
	  m_apm_multiply (mres, m1, m2);
	  break;

	case OP_DIV:
	  m_apm_divide (mres, 0, m1, m2);
	  break;

	case OP_POWER:
	case OP_MOD:
	  m_apm_free (m1);
	  m_apm_free (m2);
	  m_apm_free (mres);
	  return 0;
	}
      m_apm_free (m1);
      m_apm_free (m2);
    }
  else
    {
      mres = A4GL_str_dot_to_m_apm (s1);
    }

  switch (overflow_dtype)
    {
    case DTYPE_INT8:
      m1 = A4GL_str_dot_to_m_apm ("9223372036854775807");
      o = m_apm_compare (mres, m1);
      m_apm_free (m1);
      if (o > 0)
	{
	  if (s2)
	    {
	      sum = malloc (sizeof (*sum));
	      A4GL_init_dec (sum, 64, 0);
	      m_apm_to_fixpt_string (buff, 0, mres); // dont need set_fgl_decimal_precision_from_apm_decimal
	      A4GL_str_dot_to_dec (buff, sum);
	      A4GL_push_dec_dec (sum, 0, 0);
	    }
	  m_apm_free (mres);
	  return 1;
	}

      m1 = A4GL_str_dot_to_m_apm ("-9223372036854775807");
      m_apm_compare (mres, m1);
      m_apm_free (m1);
      if (o < 0)
	{
	  if (s2)
	    {
	      sum = malloc (sizeof (*sum));
	      A4GL_init_dec (sum, 64, 0); // dont need set_fgl_decimal_precision_from_apm_decimal
	      m_apm_to_fixpt_string (buff, 0, mres);
	      A4GL_str_dot_to_dec (buff, sum);
	      A4GL_push_dec_dec (sum, 0, 0);
	    }
	  m_apm_free (mres);
	  return 1;
	}
      break;

    case DTYPE_INT:
      m1 = A4GL_str_dot_to_m_apm ("2147483647");
      o = m_apm_compare (mres, m1);
      m_apm_free (m1);
      if (o > 0)
	{
	  if (s2)
	    {
	      sum = malloc (sizeof (*sum));
	      A4GL_init_dec (sum, 64, 0); // dont need set_fgl_decimal_precision_from_apm_decimal
	      m_apm_to_fixpt_string (buff, 0, mres);
	      A4GL_str_dot_to_dec (buff, sum);
	      A4GL_push_dec_dec (sum, 0, 0);
	    }
	  m_apm_free (mres);
	  return 1;
	}

      m1 = A4GL_str_dot_to_m_apm ("-2147483648");
      o = m_apm_compare (mres, m1);
      m_apm_free (m1);
      if (o < 0)
	{
	  if (s2)
	    {
	      sum = malloc (sizeof (*sum));
	      A4GL_init_dec (sum, 64, 0);
	      m_apm_to_fixpt_string (buff, 0, mres); // dont need set_fgl_decimal_precision_from_apm_decimal
	      A4GL_str_dot_to_dec (buff, sum);
	      A4GL_push_dec_dec (sum, 0, 0);
	    }
	  m_apm_free (mres);
	  return 1;
	}
      break;
    case DTYPE_SMINT:
      m1 = A4GL_str_dot_to_m_apm ("32767");
      o = m_apm_compare (mres, m1);
      m_apm_free (m1);
      if (o > 0)
	{
	  if (s2)
	    {
	      sum = malloc (sizeof (*sum));
	      A4GL_init_dec (sum, 64, 0);
	      m_apm_to_fixpt_string (buff, 0, mres); // dont need set_fgl_decimal_precision_from_apm_decimal
	      A4GL_str_dot_to_dec (buff, sum);
	      A4GL_push_dec_dec (sum, 0, 0);
	    }
	  m_apm_free (mres);
	  return 1;
	}

      m1 = A4GL_str_dot_to_m_apm ("-32768");
      o = m_apm_compare (mres, m1);
      m_apm_free (m1);
      if (o < 0)
	{
	  if (s2)
	    {
	      sum = malloc (sizeof (*sum));
	      A4GL_init_dec (sum, 64, 0);
	      m_apm_to_fixpt_string (buff, 0, mres); // dont need set_fgl_decimal_precision_from_apm_decimal
	      A4GL_str_dot_to_dec (buff, sum);
	      A4GL_push_dec_dec (sum, 0, 0);
	    }
	  m_apm_free (mres);
	  return 1;
	}
      break;
    }

  m_apm_free (mres);
  return 0;

}





#endif
//a4gl_dececvt()
//a4gl_decfcvt() 
