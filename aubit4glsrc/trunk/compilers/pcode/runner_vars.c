#if (defined(__CYGWIN__)) || defined(__MINGW32__)
	/* missing from rpcgen generated .h on CygWin: */
	#define bool_t int
	#define u_int unsigned int
#endif


#include "npcode.h"
#include "npcode_defs.h"

void
allocate_variable (int module_level, int offset, struct npvariable *n)
{
/* .. */
}
