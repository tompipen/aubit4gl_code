#include <stdio.h>
#include <stdlib.h>

FILE *memfile_fopen(char *f,char *mode) ;
int memfile_fseek(FILE *f, long offset,int whence) ;
int memfile_getc(FILE *f) ;
void memfile_fclose(FILE *f) ;
void memfile_rewind(FILE *f);
long memfile_ftell(FILE *f);
int memfile_ungetc(int c,FILE *F);
int memfile_feof(FILE *f);
int memfile_fread(char *ptr,int s,int n,FILE *f) ;
