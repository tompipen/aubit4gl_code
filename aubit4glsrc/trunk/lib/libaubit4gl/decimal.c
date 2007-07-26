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

s_convfmts * A4GL_get_convfmts(void)
{
    return &a4gl_convfmts;
}




static void A4GL_str_dot_to_dec(char *s,fgldecimal *d) {
char buff[2000];
char *ptr;
strcpy(buff,s);
ptr=strchr(buff,',');
while (ptr) {
	*ptr='.';
	ptr=strchr(ptr,',');
	
}
A4GL_str_to_dec(buff,d);

}


/**
 * Initialize default/configured decimal formats
 */
void A4GL_init_default_formats()
{
    char *tmp;
    char buf[32];
    float f;

    // generic format
    a4gl_convfmts.posix_decfmt.decsep = '.';
    a4gl_convfmts.posix_decfmt.thsep = 0;

    // a4gl default numeric format
    a4gl_convfmts.ui_decfmt.decsep = '.';
    a4gl_convfmts.ui_decfmt.thsep = 0;
    tmp = acl_getenv("A4GL_NUMERIC");
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
    tmp = acl_getenv("A4GL_DB_NUMERIC");
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
    sprintf(buf, "%f", 1.1);
    a4gl_convfmts.printf_decfmt.decsep = buf[1];
    sprintf(buf, "%f", 1111.1);
    a4gl_convfmts.printf_decfmt.thsep =
            (buf[1] >= '0' && buf[1] <= '9') ? 0 : buf[1];

    // detected 'scanf' numeric format
    // set scanf_decfmt to printf_decfmt (I suspect it should always be overwritten, but who knows...)
    a4gl_convfmts.scanf_decfmt.decsep = a4gl_convfmts.printf_decfmt.decsep;
    a4gl_convfmts.scanf_decfmt.thsep  = a4gl_convfmts.printf_decfmt.thsep;
    f = 0;
    if (sscanf("1.2", "%f", &f) == 1 && f > 1.1 && f < 1.3)
        a4gl_convfmts.printf_decfmt.decsep =  '.';
    else if (sscanf("1,2", "%f", &f) == 1 && f > 1.1 && f < 1.3)
        a4gl_convfmts.printf_decfmt.decsep =  ',';
    f = 0;
    if (sscanf("1.111", "%f", &f) == 1 && f > 1000)
        a4gl_convfmts.printf_decfmt.thsep =  '.';
    else if (sscanf("1,111", "%f", &f) == 1 && f > 1000)
        a4gl_convfmts.printf_decfmt.thsep =  ',';


    // forced 'scanf' numeric format for broken scanf
    // normally it should be the same as printf
    // and for '.' and ',' it should be succesfully autodetected
    tmp = acl_getenv("A4GL_SCANF_NUMERIC");
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

    A4GL_debug("Default numeric formats: a4gl=<%c%c> db=<%c%c> printf=<%c%c> scanf=<%c%c> using=<%c%c>\n", 
            a4gl_convfmts.ui_decfmt.decsep,   a4gl_convfmts.ui_decfmt.thsep,
            a4gl_convfmts.db_decfmt.decsep,     a4gl_convfmts.db_decfmt.thsep,
            a4gl_convfmts.printf_decfmt.decsep, a4gl_convfmts.printf_decfmt.thsep,
            a4gl_convfmts.scanf_decfmt.decsep,  a4gl_convfmts.scanf_decfmt.thsep,
            a4gl_convfmts.using_decfmt.decsep,  a4gl_convfmts.using_decfmt.thsep);
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
char *A4GL_decstr_convert(char *buf, s_decfmt from, s_decfmt to,
                          int newbuf, int trim, int maxlen)
{
#define MAX_DECSTR_SIZE 512 // should be sufficient for any weird string, even
                         // padded with lot of whitespace
    enum e_state {
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
    char b[MAX_DECSTR_SIZE+2];
    int dpos;
    int i, c, o;
    char * optr;
    char sign = 0;
    // find a decimal separator
    A4GL_debug("Converting \"%s\"", buf);
    for (dpos = 0; buf[dpos]; ++dpos)
    {
        if (buf[dpos] == from.decsep)
            break;
    }

    for (i = o = 0; st != DEC_STATE_S_ERR && st != DEC_STATE_S_OK && i < MAX_DECSTR_SIZE-1 && o < MAX_DECSTR_SIZE-1; ++i)
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
                if (! trim)
                    b[o++] = c;
                st = DEC_STATE_S_0;
            }
            else if (c == 0)
            {
                st = DEC_STATE_S_OK;
            }
            else
            {
                A4GL_debug("parse error, state %i\n", st);
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
                if (! trim)
                    b[o++] = c;
                st = DEC_STATE_S_SGN;
            }
            else
            {
                A4GL_debug("parse error, state %i\n", st);
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
                if (! trim)
                    b[o++] = c;
                st = DEC_STATE_S_AN;
            }
            else if (c == 0)
            {
                st = DEC_STATE_S_OK;
            }
            else
            {
                A4GL_debug("parse error, state %i\n", st);
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
                A4GL_debug("parse error, state %i\n", st);
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
                if (! trim)
                    b[o++] = c;
                st = DEC_STATE_S_AN;
            }
            else if (c == 0)
            {
                st = DEC_STATE_S_OK;
            }
            else
            {
                A4GL_debug("parse error, state %i\n", st);
                st = DEC_STATE_S_ERR;
            }
            break;
          case DEC_STATE_S_AN:
            if (c == '\t' || c == ' ')
            {
                if (! trim)
                    b[o++] = c;
                st = DEC_STATE_S_AN;
            }
            else if (c == 0)
            {
                st = DEC_STATE_S_OK;
            }
            else
            {
                A4GL_debug("parse error, state %i\n", st);
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
    if (maxlen != -1)
    {
	if (o > maxlen)
	{
	    if (trim)
	    {
		A4GL_debug("maxlen exceeded, filling with '*'s");
		memset(optr, '*', maxlen);
		optr[maxlen] = 0;
	    }
	    else
	    {
		A4GL_debug("maxlen exceeded, trying to grab the whitespace, if possible");
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
			    optr[i-1] = sign;
			    break;
			}
		    }
		}
		bl = strlen(optr);
		for (i = 0; optr[i] == ' ' || optr[i] == '\t'; ++i, --bl, ++optr)
		{
		    if (bl <= maxlen)
			break;
		}
		if (bl > maxlen)
		{
		    A4GL_debug("maxlen exceeded, filling with '*'s");
		    memset(optr, '*', maxlen);
		    optr[maxlen] = 0;
		}
	    }
	}
    }

    A4GL_debug("Conversion result\"%s\"", optr);
    if (newbuf)
        return strdup(optr);
    strcpy(buf, optr);
    return buf;
}

int A4GL_is_meaningful_in_decfmt(s_decfmt fmt, char c)
{
    if (c == fmt.decsep)
        return 1;
    if (    c == fmt.thsep ||
            c == ' ' ||
            c == ',' ||
            c == '.' || 
            c == '$' ||
            c == '£')
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
fgldecimal *A4GL_init_dec(fgldecimal *dec, int length, int digits) {
	dec->dec_data[0]=length;
	dec->dec_data[1]=digits;
	return dec;
}


/**
 * Convert a string to a decimal value.
 *
 * @param str The string to be converted.
 * @param dec A pointer to the decimal where the value will be inserted.
 */
fgldecimal *A4GL_str_to_dec (char *str_orig, fgldecimal *dec) {
  char head[256];
  char head2[256];
  char tail[256];
  char tmp[3];
  int a;
  int isneg=0;
  int sec='f';
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

  A4GL_strncpyz(str, str_orig, sizeof(str));
  A4GL_trim(str);
#ifdef DEBUG
	A4GL_debug("XYXY str to dec : '%s'",str);
#endif

	digits  =dec->dec_data[0]&127;
	decimals=dec->dec_data[1];

	memset(head,0,256);
	memset(tail,0,256);

	l2=strlen(str);
  /* Parse our string. */
  for (a=0;a<l2;a++) 
	{
	  if (str[a]==' '&&(sec=='t'||sec=='h')) {sec='e';continue;}
	  if (str[a]==' '&&(sec=='f'||sec=='e')) continue;
	  if (str[a]=='-'&&sec=='f') {sec='h';isneg=1;continue;}
	  if (str[a]=='+'&&sec=='f') {sec='h';isneg=0;continue;}

	  if (str[a]>='0'&&str[a]<='9'&&(sec=='f'||sec=='h'||sec=='t')) 
		{
		  if (sec=='f') sec='h';
		  if (sec=='h'&&str[a]=='0'&&strlen(head)==0) continue;
		  tmp[0]=str[a];
		  tmp[1]=0;

		  if (sec=='h') 	strcat(head,tmp);
		  else 		strcat(tail,tmp);

		  continue;
	  }

	  if (str[a]=='.' && (sec=='h'||sec=='f')) {
		  sec='t';
		  continue;
	  }
	  if (str[a]=='$') {
		  continue;
	  }

	  // Dodgey character ?
	  // Informix seems to set the value to 0 not null...
	  // which seems inconsistant with the handling of bad dates..
	  //
	  // Ho hum  - make it switchable, but use the Informix action as
	  // the default..
	  //
	  A4GL_conversion_ok(0);
	  if (A4GL_isyes(acl_getenv("A4GL_NULL_DECIMAL_IF_BAD"))) {
		  A4GL_debug("Bad...");
		  A4GL_setnull(DTYPE_DECIMAL,dec,dec->dec_data[0]*256+dec->dec_data[1]);
	  } else {
		  A4GL_debug("Bad...");
		  return A4GL_str_to_dec("0",dec);
	  }
	  return dec;
  }

  /* We should now have two strings - head and tail */
  
  head_i=atoi(head);
#ifdef DEBUG
  A4GL_debug("digits=%d decimals=%d\n",digits,decimals);
#endif
	
  head_len=digits-decimals;
	if (head_len<0) {
		A4GL_assertion(1, "Head_len <0 - do we have a decimal(1) [== decimal(1,2)] ?");
	}
  tail_len=decimals;

  if (strlen(head)>digits-decimals) {
	  // Its too big..
	A4GL_debug("Bad %s %d - %d %d ",head,strlen(head),digits,decimals);
	  A4GL_setnull(DTYPE_DECIMAL,dec,dec->dec_data[0]*256+dec->dec_data[1]);
	  return dec;
  }
  strcat(tail,"00000000000000000000000000000");
  tail[decimals+1]=0;


  // now round the tail..
  carry=0;
  round_cnt=decimals;
  if (tail[round_cnt]>='5') {
	carry=1;
  }

  while (carry) {
		A4GL_debug("Doing Carry... %s",tail);
		round_cnt--;
		if (round_cnt<0) break;
		tail[round_cnt]++;
		if (tail[round_cnt]<='9') {carry=0;break;}
		if (tail[round_cnt]>'9') tail[round_cnt]='0';
  }

  if (carry) {
		
		head_i++;
	}

  tail[decimals]=0;
#ifdef DEBUG
  A4GL_debug("head_len=%d",head_len);
  A4GL_debug("head_i=%d head='%s'",head_i,head);
#endif
  SPRINTF2(buff,"%0*ld",head_len,head_i);
  memset(head2,'0',255);

  head2[head_len]=0;
  strcpy(&head2[head_len-strlen(head)],head);
  if (carry) {
	  for (a=strlen(head2)-1;a>=0;a--) {
		  head2[a]++;
		  if (head2[a]<='9') break;
		  head2[a]='0';
	  }
  }
  strcpy(buff,head2);
#ifdef DEBUG
  A4GL_debug("head2=%s\n",head2);
#endif
  
  
  strcpy(&dec->dec_data[2],buff);
  tmpbuf[0] = a4gl_convfmts.posix_decfmt.decsep; tmpbuf[1] = 0;
  strcat(&dec->dec_data[2],tmpbuf);
  strcat(&dec->dec_data[2],tail);
  
  //while  (strlen(&dec->dec_data[2])!=digits+1) { strcat(&dec->dec_data[2],"0"); }
  
   dec->dec_data[0]= dec->dec_data[0]&127;
  if (isneg) {
		
		dec->dec_data[0]+=128;
	}

#ifdef DEBUG
  A4GL_debug("----> %s\n",&dec->dec_data[2]);
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
char *A4GL_dec_to_str (fgldecimal *dec, int size) {
  static char buff[256];
  //char buff2[256];
  int a;
  char *ptr;
  int has_neg=0;
  int l;
  strcpy(buff," ");
  if (dec->dec_data[0]&128) { has_neg=1; }
  
#ifdef DEBUG
  A4GL_debug("XYXY dec to str : %s",&dec->dec_data[2]);
#endif
  ptr=&dec->dec_data[2];
  strcat(buff,ptr);
	l=strlen(buff);
	for (a=has_neg;a<l;a++) {
		if (buff[a]==a4gl_convfmts.posix_decfmt.decsep) break;
		if (buff[a]==' ') continue;
		if (buff[a]=='0' && a==strlen(buff)-2 && 
			buff[a+1]==a4gl_convfmts.posix_decfmt.decsep) break;
		if (buff[a]=='0') {buff[a]=' ';continue;}
		//if (buff[a]=='-') continue;
		break;
	}
  A4GL_trim(buff);
  if (buff[strlen(buff)-1]==a4gl_convfmts.posix_decfmt.decsep)
      buff[strlen(buff)-1]=0;

#ifdef DEBUG
  A4GL_debug("--->XYXY '%s'",buff);
#endif

  if (has_neg) {
	l=strlen(buff);
    for (a=0;a<l;a++) {
	    if (buff[a]!=' ') {buff[a-1]='-'; break;}
    }
  }
  return buff;
}



#ifdef USE_MAPM

#include "m_apm.h"

int
a4gl_decadd (fgldecimal * d1, fgldecimal * d2, fgldecimal * sum)
{
M_APM m1;
M_APM m2;
M_APM mres;
char buff[2000];
	m1= m_apm_init();
	m2= m_apm_init();
	mres= m_apm_init();

	m_apm_set_string(m1, A4GL_dec_to_str(d1,0));
	m_apm_set_string(m2, A4GL_dec_to_str(d2,0));

	m_apm_add(mres, m1, m2);

	m_apm_to_fixpt_string(buff, sum->dec_data[1], mres);
	A4GL_str_dot_to_dec(buff,sum);

	m_apm_free(m1);
	m_apm_free(m2);
	m_apm_free(mres);

  return 0;
}

int
a4gl_deccmp (fgldecimal * d1, fgldecimal * d2)
{
int a;
	M_APM m1;
	M_APM m2;
	char buff[200];
	m1= m_apm_init();
	m2= m_apm_init();
	m_apm_set_string(m1, A4GL_dec_to_str(d1,0));
	m_apm_set_string(m2, A4GL_dec_to_str(d2,0));
	a=m_apm_compare(m1,m2);
	m_apm_free(m1);
	m_apm_free(m2);

/*
	m_apm_to_fixpt_string(buff, 10, m1);
		printf("-->%s ",buff);
	m_apm_to_fixpt_string(buff, 10, m2);
		printf(" %s",buff);

	printf("=%d\n",a);
*/
  return a;
}

void
a4gl_deccopy (fgldecimal * src, fgldecimal * target)
{
	char buff[200];
	a4gl_deccvasc(buff,199, src);
	A4GL_str_dot_to_dec(buff,target);
}

int
a4gl_deccvasc (char *s, int n, fgldecimal * d)
{
char buff[256];
        M_APM m1;
        M_APM m2;
        m1= m_apm_init();
        m2= m_apm_init();
	m_apm_set_string(m1, s);
	m_apm_to_fixpt_string(buff, d->dec_data[1], m2);
	A4GL_str_dot_to_dec(buff,d);
	m_apm_free(m1);
	m_apm_free(m2);
	

  return 0;
}

int
a4gl_deccvdbl (double d, fgldecimal * d1)
{
char buff[200];
  	sprintf(buff,"%32.16lf",d);
	A4GL_str_dot_to_dec(buff,d1);
  return 0;
}

int
a4gl_deccvflt (float d, fgldecimal * d1)
{
char buff[200];
  	sprintf(buff,"%32.16f",d);
	A4GL_str_dot_to_dec(buff,d1);
  return 0;
}

int
a4gl_deccvint (int i, fgldecimal * d)
{
char buff[200];
  	sprintf(buff,"%d",i);
	A4GL_str_dot_to_dec(buff,d);
  return 0;
}

int
a4gl_deccvlong (long l, fgldecimal * d)
{
	char buff[200];
  	sprintf(buff,"%ld",l);
	A4GL_str_dot_to_dec(buff,d);
  
  return 0;
}

int
a4gl_decdiv (fgldecimal * d1, fgldecimal * d2, fgldecimal * res)
{
M_APM m1;
M_APM m2;
M_APM mres;
char buff[2000];
	m1= m_apm_init();
	m2= m_apm_init();
	mres= m_apm_init();

	m_apm_set_string(m1, A4GL_dec_to_str(d1,0));
	m_apm_set_string(m2, A4GL_dec_to_str(d2,0));


	m_apm_divide(mres, res->dec_data[1]+1, m1, m2);

	m_apm_to_fixpt_string(buff, res->dec_data[1], mres);

	A4GL_str_dot_to_dec(buff,res);

	m_apm_free(m1);
	m_apm_free(m2);
	m_apm_free(mres);

  return 0;
}


int
a4gl_decmul (fgldecimal * d1, fgldecimal * d2, fgldecimal * res)
{
M_APM m1;
M_APM m2;
M_APM mres;
char buff[2000];
	m1= m_apm_init();
	m2= m_apm_init();
	mres= m_apm_init();

	m_apm_set_string(m1, A4GL_dec_to_str(d1,0));
	m_apm_set_string(m2, A4GL_dec_to_str(d2,0));

	m_apm_multiply(mres, m1, m2);

	m_apm_to_fixpt_string(buff, res->dec_data[1], mres);
	A4GL_str_dot_to_dec(buff,res);
	m_apm_free(m1);
	m_apm_free(m2);
	m_apm_free(mres);

  return 0;
}

void
a4gl_decround (fgldecimal * d1, int n)
{
M_APM m1;
char buff[200];
     m1= m_apm_init();
     m_apm_set_string(m1, A4GL_dec_to_str(d1,0));
     m_apm_to_fixpt_string(buff,n,m1);
     A4GL_str_dot_to_dec(buff,d1);
	m_apm_free(m1);
}


int
a4gl_decsub (fgldecimal * d1, fgldecimal * d2, fgldecimal * res)
{
M_APM m1;
M_APM m2;
M_APM mres;
char buff[2000];
	m1= m_apm_init();
	m2= m_apm_init();
	mres= m_apm_init();

	m_apm_set_string(m1, A4GL_dec_to_str(d1,0));
	m_apm_set_string(m2, A4GL_dec_to_str(d2,0));

	m_apm_subtract(mres, m1, m2);

	m_apm_to_fixpt_string(buff, res->dec_data[1], mres);
	A4GL_str_dot_to_dec(buff,res);

	m_apm_free(m1);
	m_apm_free(m2);
	m_apm_free(mres);

  return 0;
}

int
a4gl_dectoasc (fgldecimal * d, char *s, int l, int right)
{
M_APM m1;
char buff[2000];
	m1= m_apm_init();
	m_apm_set_string(m1, A4GL_dec_to_str(d,0));
	m_apm_to_fixpt_string(buff, right, m1);
	if (strlen(buff)>l) {
		return -1;
	} else {
		strcpy(s,buff);
	}
  return 0;
}

int
a4gl_dectodbl (fgldecimal * d1, double *d)
{
char buff[256];
   A4GL_stof (A4GL_dec_to_str(d1,0), d, 0);
return 0;
}

int
a4gl_dectoint (fgldecimal * d1, int *ival)
{
   A4GL_stoi (A4GL_dec_to_str(d1,0), ival, 0);
  return 0;
}

int
a4gl_dectolong (fgldecimal * d1, long *lval)
{
   A4GL_stol (A4GL_dec_to_str(d1,0), lval, 0);
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
norig=n;

m1= m_apm_init();
m_mult= m_apm_init();
m10= m_apm_init();
mres= m_apm_init();

m_apm_set_string(m1, A4GL_dec_to_str(d1,0));

m_apm_set_long(m_mult,1);
m_apm_set_long(m10,10);

// We'll need to multiply up our value to floor it..
// this trims it back to an integer
// by multiplying up by factors of 10 - we get the number of decimal
// places when we convert it back later
//
if (n) {
	while (n) {
		m_apm_multiply(mres, m_mult,m10);
		m_apm_copy(m_mult,mres);
		n--;
	}

	// multiply our number by our factor..
	m_apm_multiply(mres,m1,m_mult);
	m_apm_copy(m1,mres);
}


if (m_apm_sign(m1)<0) {
	m_apm_ceil(mres, m1);
} else {
	m_apm_floor(mres, m1);
}

m_apm_divide(m1, norig, mres,m_mult);

// m1 should now be truncated to n decimal places..
m_apm_to_fixpt_string(buff, d1->dec_data[1]+1, m1);
A4GL_str_dot_to_dec(buff,d1);
}

#endif
//a4gl_dececvt()
//a4gl_decfcvt() 
