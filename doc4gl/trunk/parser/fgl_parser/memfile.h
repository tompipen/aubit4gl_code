
#include <stdio.h>
#include <stdlib.h>

FILE *A4GL_memfile_fopen (char *f, char *mode);
int A4GL_memfile_fseek (FILE * f, long offset, int whence);
int A4GL_memfile_getc (FILE * f);
void A4GL_memfile_fclose (FILE * f);
void A4GL_memfile_rewind (FILE * f);
long A4GL_memfile_ftell (FILE * f);
int A4GL_memfile_ungetc (int c, FILE * F);
int A4GL_memfile_feof (FILE * f);
int A4GL_memfile_fread (char *ptr, int s, int n, FILE * f);
