#include <stdio.h>
#include <string.h>

#include "attr.h"

extern struct s_attr lexed_attr;
int xml_yylex (void);

//static char *inbuff=0;
//char *myinputptr_xxx;
//int myinputlim;
//#define attr_min(X,Y) (((X) < (Y)) ? (X) : (Y))

void dump_attr(struct s_attr *a) {
	int c;
	printf("ID=%s Data=%s Type=%s EnvelopeId=%s\n",a->id,a->data,a->type, a->envelopeId);
	printf("%d values\n",a->sync.nvalues);
	for (c=0;c<a->sync.nvalues;c++) {
		printf("%s\n",a->sync.vals[c].value);
	}

}
