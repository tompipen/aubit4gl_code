#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memfile.h"

int opened=0;
char *buff;
long  buff_len;
FILE *in;
long pos=0;
FILE *mja_fopen(char *name,char *mode);


FILE *memfile_fopen(char *f,char *mode) {

	if (opened>1) {
		printf("Too many opened!!");
		exit(1);
	}

	if (strchr(mode,'w')) {
		printf("Can't use memfile for Writing...");
		exit(1);
	
	}

	opened++;

	in=mja_fopen(f,mode);

	if (in==0) return 0;
	else {
		fseek(in,0,SEEK_END);
		buff_len=ftell(in);
		buff=(char *)malloc(buff_len+1);
		rewind(in);

		if (fread(buff,buff_len,1,in)!=1) {
			printf("Unable to read file into buffer\n");
		}
	}

        pos=0;
	return in;
}



int memfile_fseek(FILE *f, long offset,int whence) {
	if (f!=in) {
		return fseek(f,offset,whence);
	} else {
		if (whence==SEEK_SET) { pos=offset;return 0;}
		if (whence==SEEK_END) { pos=buff_len-offset;return 0;}
		if (whence==SEEK_CUR) { pos+=offset;return 0;}
	}
	return 1;
}


int memfile_getc(FILE *f) {
int a;
	if (f!=in) {
		return getc(f);
	} else {
		a=buff[pos];
		pos++;
		return a;
	}
}


void memfile_fclose(FILE *f) {
	if (f!=in) {
		fclose(f);
	} else {
		opened--;
		free(buff);
	}
}

void memfile_rewind(FILE *f) {
	if (f!=in) {
		rewind(f);
	} else {
		pos=0;
	}
}

long memfile_ftell(FILE *f) {
	if (f!=in) {
		return ftell(f);
	} else {
		return pos;
	}
}

int memfile_ungetc(int c,FILE *f) {
	if (f!=in) {
		return ungetc(c,f);
	} else {
		pos--;
	}
	return 0;
}

int memfile_feof(FILE *f) {
	if (f!=in) {
		return feof(f);
	} else {
		return pos>buff_len;
	}
}

int memfile_fread(char *ptr,int s,int n,FILE *f) {
	if (f!=in) {
		return fread(ptr,s,n,f);
	} else {
		memcpy(ptr,&buff[pos],s*n);
		pos+=s*n;
		return 0;
	}
}
