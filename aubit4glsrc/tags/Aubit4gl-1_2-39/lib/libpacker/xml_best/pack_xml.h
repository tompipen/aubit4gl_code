#ifdef HAVE_ZLIB
#include "zlib.h"
#include "a4gl_gzip.h"
#define YY_INPUT(buf,result,max_size) \
if ( ((result = gzread(yyin, buf, max_size)) < 0)) \
YY_FATAL_ERROR( "input in flex scanner failed" );
#endif

/*
    int c = gzgetc(yyin); \
    result = (c == EOF) ? YY_NULL : (buf[0] = c, 1); \
*/
