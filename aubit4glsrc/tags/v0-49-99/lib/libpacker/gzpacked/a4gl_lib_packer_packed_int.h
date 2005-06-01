


#define _NO_FORM_X_H_
#include "a4gl_lib_packer_int.h"
#include <zlib.h>
#define fopen gzopen
#define fwrite(a,b,c,d) gzwrite(d,a,b*c)
#define fread(a,b,c,d) gzread(d,a,b*c)
#define ftell(a) gztell(a)
#define fseek(a,b,c) gzseek(a,b,c)
#define rewind(a) gzrewind(a)
#define fclose(a) gzclose(a)
