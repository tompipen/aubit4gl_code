//
#include "a4gl_libaubit4gl_int.h"


fgldecimal *A4GL_init_dec(fgldecimal *dec, int length, int digits) {
	dec->dec_data[0]=length;
	dec->dec_data[1]=digits;
	return dec;
}


fgldecimal *
A4GL_str_to_dec (char *str, fgldecimal *dec) {
char head[256];
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
char *ptr;
char buff[256];
int round_cnt;
int carry;

	A4GL_debug("XYXY str to dec : %s",str);

	digits  =dec->dec_data[0]&127;
	decimals=dec->dec_data[1];

	memset(head,0,256);
	memset(tail,0,256);

/* Parse our string. */
for (a=0;a<strlen(str);a++) {
	if (str[a]==' '&&(sec=='t'||sec=='h')) {sec='e';continue;}
	if (str[a]==' '&&(sec=='f'||sec=='e')) continue;
	if (str[a]=='-'&&sec=='f') {sec='h';isneg=1;continue;}
	if (str[a]=='+'&&sec=='f') {sec='h';isneg=0;continue;}

	if (str[a]>='0'&&str[a]<='9'&&(sec=='f'||sec=='h'||sec=='t')) {
		if (sec=='f') sec='h';
		if (sec=='h'&&str[a]=='0'&&strlen(head)==0) continue;
		tmp[0]=str[a];
		tmp[1]=0;

		if (sec=='h') 	strcat(head,tmp);
		else 		strcat(tail,tmp);

		continue;
	}

	if (str[a]=='.'&&(sec=='h'||sec=='f')) {
		sec='t';
		continue;
	}

	// Dodgey character ?
	//printf("??? %c - %c\n",str[a],sec);
	// Informix seems to set the value to 0 not null...
	// which seems inconsistant with the handling of bad dates..
	//
	// Ho hum  - make it switchable, but use the Informix action as
	// the default..
	//
	A4GL_conversion_ok(0);
	if (A4GL_isyes(acl_getenv("A4GL_NULL_DECIMAL_IF_BAD"))) {
		A4GL_setnull(DTYPE_DECIMAL,dec,dec->dec_data[0]*256+dec->dec_data[1]);
	} else {
		return A4GL_str_to_dec("0",dec);
	}
	return dec;
}

/* We should now have two strings - head and tail */

head_i=atoi(head);

head_len=digits-decimals;
tail_len=decimals;

if (strlen(head)>digits-decimals) {
	// Its too big..
	//printf("Num too big");
	A4GL_setnull(DTYPE_DECIMAL,dec,dec->dec_data[0]*256+dec->dec_data[1]);
	return dec;
}
strcat(tail,"00000000000000000000000000000");
tail[decimals+1]=0;


// now round the tail..
carry=0;
round_cnt=decimals;
//printf("Think about rounding.. %s %d\n",tail,round_cnt);
if (tail[round_cnt]>='5') {
	//printf("Have >=5 - so carry\n");
	carry=1;
}

while (carry) {
		round_cnt--;
		if (round_cnt<0) break;
		tail[round_cnt]++;
		if (tail[round_cnt]<='9') {carry=0;break;}
}

if (carry) head_i++;

tail[decimals]=0;
sprintf(buff,"%0*d",head_len,head_i);
sprintf(&dec->dec_data[2],buff);
strcat(&dec->dec_data[2],".");
strcat(&dec->dec_data[2],tail);

//while  (strlen(&dec->dec_data[2])!=digits+1) { strcat(&dec->dec_data[2],"0"); }


if (isneg) dec->dec_data[0]+=128;

//if (strlen(&dec->dec_data[2])-1>digits) { // The tail must be too long...
	//printf("str=%s digits=%d decimal=%d\n",&dec->dec_data[2],digits,decimals);
	//printf("NEEDS ROUNDING\n");
//}
//printf("----> %s\n",&dec->dec_data[2]);
return dec;
}

char *A4GL_dec_to_str (fgldecimal *dec, int size) {
static char buff[256];
char buff2[256];
int a;
char *ptr;
int has_neg=0;
strcpy(buff," ");
if (dec->dec_data[0]&128) { has_neg=1; }

A4GL_debug("XYXY dec to str : %s",&dec->dec_data[2]);
ptr=&dec->dec_data[2];
//printf("dectostr--->%s\n",&dec->dec_data[2]);
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


//printf("--->%s\n",&dec->dec_data[2]);
A4GL_debug("--->XYXY '%s'",buff);
if (has_neg) {
for (a=0;a<strlen(buff);a++) {
	if (buff[a]!=' ') {buff[a-1]='-'; break;}
}
}
return buff;
}
