// (c) 2010 Aubit Computing Ltd
//
//   wsdl2fgl
//
//
// Process :
//
//
// We can process a .h or a wsdl
// If input file is a wsdl - then process that using wsdl2h to get a header file
// 
// Processing the header file reads in the datatypes and functions and creates the 4gl stubs associated
// with the code generated from soapcpp2
//
// Both wsdl2h and soapcpp2 are from "gsoap" and licensing restrictions may apply
//
//
#include <string.h>
#define _XOPEN_SOURCE  1
#include <stdio.h>
#include <stdlib.h>

#ifndef  WEXITSTATUS
#define WEXITSTATUS(x) wexitstatus(x)
#endif



// variables
extern int yylineno;
extern FILE *yyin;
extern int wsdl2fgl_yydebug;

FILE *fOut=NULL;

// Function prototypes
static int wexitstatus(int x) ;




int main(int argc,char *argv[]) {
int wsdlMode=0;
char *fileName=0;
char *yydebug_flag;
int a;
char stub[2000];
		char buff[2000];
		int exitStatus;
FILE *soap_in;


yydebug_flag=getenv("YYDEBUG");
if (yydebug_flag) {
	if (strcmp(yydebug_flag,"Y")==0) {
		wsdl2fgl_yydebug=1;
	}
}
for (a=1;a<argc;a++) {
	if (strcmp(argv[a],"-w")==0) {
		wsdlMode=1;
		continue;
	}

	if (strcmp(argv[a],"-h")==0) {
		wsdlMode=0;
		continue;
	}
	
	

	// Filename detection
	// if anything is left - it should be the filename...
	if (fileName!=NULL) {
		fprintf(stderr,"A filename has already been set...\n");
		exit(2);
	}

	if (strstr(argv[a],".wsdl")) {
		char *ptr;
		wsdlMode=1;
		fileName=argv[a];

		sprintf(buff,"wsdl2h  -x -c %s", fileName);
		exitStatus=system(buff);
		exitStatus=WEXITSTATUS(exitStatus);
		if (exitStatus!=0) {
			fprintf(stderr,"Error running %s\n",buff);
			exit(2);
		}
		fileName=strdup(fileName);
		ptr=strstr(fileName,".wsdl");
		*ptr=0;
		strcpy(stub,fileName);
		strcat(fileName,".h"); // Its shorted - so we should be ok - we dont need to allocate any more memory
		continue;
	}

	if (strstr(argv[a],".h")) {
		wsdlMode=0;
		fileName=argv[a];
		strcpy(stub,fileName);
		stub[strlen(stub)-2]=0;
		continue;
	}

	fprintf(stderr,"Unknown file type - expecting a .h or a .wsdl\n");
	exit(2);
	
}

if (fileName==NULL) {
	fprintf(stderr,"No filename specified\n");
	exit(1);
}

if (wsdlMode) {
	printf("Processing %s generated from WSDL file\n",fileName);
} else {
	printf("Processing %s\n",fileName);
}


sprintf(buff,"soapcpp2 -n -w -x -c -C %s", fileName);
printf("Running %s\n",buff);
exitStatus=system(buff);
exitStatus=WEXITSTATUS(exitStatus);
if (exitStatus!=0) {
		fprintf(stderr,"Error running %s\n",buff);
		exit(2);
}



yyin=fopen(fileName,"r");

if (yyin==NULL) {
	fprintf(stderr,"Could not open input file : %s\n",fileName);
	exit(2);
}

fOut=fopen("Client_4gl.c","w");
if (fOut==NULL) {
	fprintf(stderr,"Could not open output file\n");	
	exit(2);
}

//fprintf(fOut,"#include \"soapH.h\"\n");
fprintf(fOut,"#include \"a4gl_incl_4glhdr.h\"\n");
//fprintf(fOut,"#define soap_namespaces namespaces\n");

soap_in=fopen("soap.nsmap","r");
if (soap_in==NULL) {
	fprintf(stderr,"Unable to open soap.nsmap - should have been generated by soapcpp2\n");
	exit(2);
}
while (1) {
	char buff[2000];
	char *ptr;
	if (fgets(buff,sizeof(buff),soap_in)==0) break;
	ptr=strstr(buff,"soap_namespaces");
	if (ptr) {
		*ptr=' '; ptr++;
		*ptr=' '; ptr++;
		*ptr=' '; ptr++;
		*ptr=' '; ptr++;
		*ptr=' '; ptr++;
	}
	fprintf(fOut,"%s",buff);
}
fclose(soap_in);

wsdl2fgl_yyparse();
fclose(fOut);
return 0;
}


FILE *getOuputFile(void ) {
	return fOut;
}


static int wexitstatus(int x) {
	return x;
}


void wsdl2fgl_yyerror(char *s) {
	fprintf(stderr,"%s - Line %d\n",s,yylineno);
	exit(2);

}

void *acl_malloc2(int n) {
	return malloc(n);
}

