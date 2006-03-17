/**
 * @file 
 * Functions to handle decimal data type.
 */

#include "a4gl_libaubit4gl_int.h"

//fgldecimal * A4GL_str_to_dec (char *str, fgldecimal *dec) ;
//int A4GL_conversion_ok(int);
//char *A4GL_dec_to_str (fgldecimal *dec, int size) ;
char decimal_char=0;


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
  //char *ptr;
  char buff[256];
char str[1024];
  int round_cnt;
  int carry;
  if (decimal_char==0) {
	  SPRINTF1(buff,"%f",1.2);
	  if (strchr(buff,'.')) decimal_char='.';
	  if (strchr(buff,',')) decimal_char=',';
  }
  if (decimal_char==0) {
	  decimal_char='.';
  }

strcpy(str,str_orig);


if (decimal_char!=',') {
       int b=0;
       for (a=0;a<strlen(str_orig);a++) {
               if (str_orig[a]==',') continue;
               str[b++]=str_orig[a];
       }
       str[b]=0;
}


A4GL_trim(str);

#ifdef DEBUG
	A4GL_debug("XYXY str to dec : '%s'",str);
#endif

	digits  =dec->dec_data[0]&127;
	decimals=dec->dec_data[1];

	memset(head,0,256);
	memset(tail,0,256);

  /* Parse our string. */
  for (a=0;a<strlen(str);a++) 
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

	  if (str[a]==decimal_char&&(sec=='h'||sec=='f')) {
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
  strcat(&dec->dec_data[2],".");
  strcat(&dec->dec_data[2],tail);
  
  //while  (strlen(&dec->dec_data[2])!=digits+1) { strcat(&dec->dec_data[2],"0"); }
  

  if (isneg) dec->dec_data[0]+=128;

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
  strcpy(buff," ");
  if (dec->dec_data[0]&128) { has_neg=1; }
  
#ifdef DEBUG
  A4GL_debug("XYXY dec to str : %s",&dec->dec_data[2]);
#endif
  ptr=&dec->dec_data[2];
  strcat(buff,ptr);
	for (a=has_neg;a<strlen(buff);a++) {
		if (buff[a]=='.') break;
		if (buff[a]==' ') continue;
		if (buff[a]=='0' && a==strlen(buff)-2&&buff[a+1]=='.') break;
		if (buff[a]=='0') {buff[a]=' ';continue;}
		//if (buff[a]=='-') continue;
		break;
	}
  A4GL_trim(buff);
  if (buff[strlen(buff)-1]=='.') buff[strlen(buff)-1]=0;

#ifdef DEBUG
  A4GL_debug("--->XYXY '%s'",buff);
#endif

  if (has_neg) {
    for (a=0;a<strlen(buff);a++) {
	    if (buff[a]!=' ') {buff[a-1]='-'; break;}
    }
  }
  return buff;
}
