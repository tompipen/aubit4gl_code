
#include <stdio.h>
#include <stdlib.h>

int A4GL_memfile_fopen (const char *f);
int A4GL_memfile_fseek (long offset, int whence);
int A4GL_memfile_getc (void);
void A4GL_memfile_fclose (void);
void A4GL_memfile_rewind (void);
long A4GL_memfile_ftell (void);
int A4GL_memfile_ungetc (int c);
int A4GL_memfile_feof ();
