/**
 * @file
 * File error writing
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */

#include <stdio.h>
#include "../libincl/debug.h"
#ifdef WIN32
#ifndef __CYGWIN__
#include <share.h>
#endif
#endif
char buff[2048];
FILE *fout=0;
long le;
int errline;
FILE *mja_fopen(char *name, char *mode);

/**
 * Write to error file.
 *
 * The error file is a copy of the source file with an error on it.
 * Used by the compiler.
 *
 * @param f A pointer to the source file name.
 * @param fname The error file name.
 * @param as Position in the file
 * @param lineno Line number on the source file.
 */
FILE *write_errfile(FILE *f,char *fname,long as,int lineno) {
  int a;
  int b;
  long s2,e;
  long s;
  int errorno;
  fout=mja_fopen(fname,"w");
  errorno=ferror(f);
  /* find the nearest NL */
  find_nl(f,as,&s2,&e);
  if ((as-s2)<=0)  {
       as-=2;
    find_nl(f,as,&s2,&e);
  }
  debug("s2=%d e=%d",s2,e);
  s=e+1;
  errline=lineno;
  rewind(f);
  a=2048;
  while (s>0) {
   if (a>s) a=s;
   fread(buff,a,1,f);
   fwrite(buff,a,1,fout);
   s-=a;
  }
  le=as-s2;
  prerrmark(fout,(int)(as-s2));
  return fout;
}

/**
 * Copy the rest of the bytes in the input file to the output file.
 *
 * @param f A pointer to the input source file.
 */
void write_cont(FILE *f) {
  int a,s=1;
  a=2048;
  fprintf(fout,"\n");
  while (s>0) {
   //if (feof(f)) break;
   s=fread(buff,1,a,f);
   fwrite(buff,s,1,fout);
  }
  fclose(fout);
}


/**
 * Find the new lines nearest to a position in a file.
 *
 * @param f The pointer to the opened file.
 * @param fp The file position where to find the new line.
 * @param s A pointer to the place where to return the position of the new line
 *   before.
 * @param e A pointer to the place where to return the position of the new line
 *   after.
 */
void find_nl(FILE *f,long fp,long *s,long *e) 
{
  int a;
  char buff[10];

  while (fp>0) {
    fseek(f,fp,SEEK_SET);
    fread(buff,1,1,f);
    if (buff[0]=='\n') break;
    fp--;
  }
  *s=fp+1;
  buff[0]=0;
  for (fp=*s+1;buff[0]!='\n';fp++) {
    fseek(f,fp,SEEK_SET);
    fread(buff,1,1,f);
    if (feof(f)) break;
  }
  *e=fp-1;
}

prerrmark(FILE *f,int a) {
int b;
fprintf(f,"|"); for (b=1;b<a-1;b++) { fprintf(f,"_"); } fprintf(f,"^\n");
fprintf(f,"| Error at line %d, character %d\n",errline,le);
}

/*
main() {
FILE *f;
f=mja_fopen("test","r");
write_errfile(f,"test.out",10);
write_cont(f);
}
*/


/**
 * Open a file
 *
 * @param name The file name.
 * @param mode The mode for passing directy to mode.
 * @return The pointer to the opened file.
 */
FILE *mja_fopen(char *name, char *mode) {
	return fopen(name,mode);
}



