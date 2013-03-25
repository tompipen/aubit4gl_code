#ifndef gzfopen
#if HAVE_ZLIB

#include <zlib.h>
#define A4GL_gzfopen gzopen
#define A4GL_gzfwrite(a,b,c,d) gzwrite(d,a,b*c)
#define A4GL_gzfprintf gzprintf
#define gzfprintf gzprintf
#define A4GL_gzfread(a,b,c,d) gzread(d,a,b*c)
#define A4GL_gzfeof(f) gzeof(f)
#define A4GL_gzfclose(a) gzclose(a)
#define A4GL_gzfgetc(a) gzgetc(a)
#define A4GL_gzfputc(a,b) gzputc(b,a)
#define A4GL_gz_ferror(a) mja_gzerror(a)
#define A4GL_gz_clearerr(a) gzclearerr(a)
#else
#define A4GL_gzfopen fopen
#define A4GL_gzfwrite(a,b,c,d) fwrite(a,b,c,d)
#define A4GL_gzfread(a,b,c,d) fread(a,b,c,d)
#define A4GL_gzfprintf fprintf
#define A4GL_gzftell(a) ftell(a)
#define A4GL_gzfseek(a,b,c) fseek(a,b,c)
#define A4GL_gzrewind(a) rewind(a)
#define A4GL_gzfclose(a) fclose(a)
#define A4GL_gzfeof(f) feof(f)
#define A4GL_gzfgetc(a) fgetc(a)
#define A4GL_gzfputc(a,b) fputc(a,b)
#endif

#endif
