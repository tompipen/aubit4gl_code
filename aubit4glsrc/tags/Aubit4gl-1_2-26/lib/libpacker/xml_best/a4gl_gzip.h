#ifndef gzfopen
#if HAVE_ZLIB

#include <zlib.h>
#define gzfopen gzopen
#define gzfwrite(a,b,c,d) gzwrite(d,a,b*c)
#define gzfprintf gzprintf
#define gzfread(a,b,c,d) gzread(d,a,b*c)
#define gzfeof(f) gzeof(f)
#define gzfclose(a) gzclose(a)
#define gzfgetc(a) gzgetc(a)
#define gzfputc(a,b) gzputc(b,a)
#define gz_ferror(a) mja_gzerror(a)
#define gz_clearerr(a) gzclearerr(a)
#else
#define gzfopen fopen
#define gzfwrite(a,b,c,d) fwrite(a,b,c,d)
#define gzfread(a,b,c,d) fread(a,b,c,d)
#define gzfprintf fprintf
#define gzftell(a) ftell(a)
#define gzfseek(a,b,c) fseek(a,b,c)
#define gzrewind(a) rewind(a)
#define gzfclose(a) fclose(a)
#define gzfeof(f) feof(f)
#define gzfgetc(a) fgetc(a)
#define gzfputc(a,b) fputc(a,b)
#endif

#endif
