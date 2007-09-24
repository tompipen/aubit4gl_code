#include <stdio.h>
#include <string.h>

#include "attr.h"

extern struct s_attr lexed_attr;
int xml_yylex (void);

static char *inbuff=0;
char *myinputptr;
int myinputlim;
//#define attr_min(X,Y) (((X) < (Y)) ? (X) : (Y))

void dump_attr(struct s_attr *a) {
	int c;
	printf("ID=%s Data=%s Type=%s\n",a->id,a->data,a->type);
	printf("%d values\n",a->sync.nvalues);
	for (c=0;c<a->sync.nvalues;c++) {
		printf("%s\n",a->sync.vals[c]);
	}

}
/*
struct s_attr *xml_parse(char *s) {
	inbuff=s;
	myinputlim=strlen(s);
	myinputptr=inbuff;
	memset(&lexed_attr,0, sizeof(struct s_attr));
	UIdebug(3,"INPUT = %s\n",s);

	if (xml_yylex()) {
		printf("X1 - yylex returned true\n");
		return &lexed_attr;
	} else {
		return &lexed_attr;
		printf("X2 - yylex returned false\n");
	}
}
*/
/*
int my_yyinput(char *buf,int maxsize) {
int n=attr_min(maxsize,myinputlim);
if (n>0) {
	memcpy(buf,myinputptr,n);
	myinputptr+=n;
	myinputlim-=n;
	}
return n;
}
*/
