#include <stdlib.h>
#include <string.h>
#include "a4gl_4glc_int.h"

extern int yylineno;

struct s_labels {
	char *label;
	int usage;
	int defined;
};

struct s_labels *labels=0;
int labels_cnt=0;


static int find_label(char *s) {
	int a;
	if (labels==0) return -1;
	for (a=0;a<labels_cnt;a++) {
		if (strcmp(s,labels[a].label)==0) return a;
	}
	return -1;
}


static int add_label(char *s,int u,int d) {
	int lb;
	labels_cnt++;
	labels=realloc(labels,sizeof (struct s_labels)* labels_cnt);
	lb=labels_cnt-1;
	labels[lb].label=strdup(s);
	labels[lb].usage=u;
	labels[lb].defined=d;
	return lb;
}


void A4GL_label_used(char *s) {
	int a;
	a=find_label(s);
	if (a>=0) {
		labels[a].usage++;
		return;
	}
	add_label(s,1,0);
}

void A4GL_chk_and_clr_labels() {
	int a;
	for (a=0;a<labels_cnt;a++) {
	if (labels[a].usage && labels[a].defined==0) {
	 	adderr (" - label '%s' has used but has not been defined", labels[a].label,"");
		a4gl_yyerror("Label not defined");
	}
	if (labels[a].usage==0 && labels[a].defined) {
	 	printf ("Warning: label '%s' has defined but is not used @ line %d\n", labels[a].label,yylineno);
	}
	}
	
	for (a=0;a<labels_cnt;a++) {
		free(labels[a].label);
	}
	free(labels);
	labels=0;
	labels_cnt=0;
}

void A4GL_label_defined(char *s) {
	int a;
	a=find_label(s);
	if (a>=0) {
		labels[a].defined++;
		return;
	}
	add_label(s,0,1);
}

