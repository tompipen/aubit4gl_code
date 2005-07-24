/*
	@(#)$Id: adjinarr.ec,v 1.2 2002-06-14 09:23:03 afalout Exp $
	@(#)Alternative interface for INPUT ARRAY
	@(#)Allows programmer specified array dimensions
	@(#)Requires modification to $INFORMIXDIR/incl/sqlfm.h
	@(#)This is an ESQL/C file to ensure that the include files are found
*/
#define FAR_V_INPUT

/* This pair of definitions should be included in $INFORMIXDIR/incl/sqlfm.h */
#ifndef FAR_V_INPUT
#define _farinput(a, b, c, d, e, f, g, h)	_far_v_input(a, b, c, d, e, f, g, h)
#define _efipclean	_ef_v_ipclean
#endif

#ifndef lint
static	char	sccs[] = "@(#)$Id: adjinarr.ec,v 1.2 2002-06-14 09:23:03 afalout Exp $";
#endif

#include <sqlhdr.h>
#include <sqlfm.h>

typedef	struct	sqlvar_struct	Sqlva;

#define I4GL_C	/* I4GL Interface Routine */

static	int	max_dimension = 0;

/* Set usable dimension for INPUT ARRAY */
I4GL_C	set_max_dimension(n)
int		n;
{
	if (n == 1)
	{
		popint(&max_dimension);
	}
	return(0);
}

/* Substitute INPUT ARRAY */
_far_v_input(a, b, c, d, e, f, g, h)
int			 a;	/* Dimension of program array */
int			 b;	/* Size of row in program array (strictly size_t) */
int			 c;	/* Number of items in porgram array */
Sqlva		*d;	/* Description of data in array (element 0) */
_EFFIELD	*e;	/* Form field list */
int			 f;	/* Purpose unknown */
_EFICB		*g;	/* Input Control Block */
_EFBAF		*h;	/* Purpose unknown */
{
	int		dimension;

	if (max_dimension > 0 && max_dimension < a)
		dimension = max_dimension;
	else
		dimension = a;

	/* Invoke the real INPUT ARRAY routine */
	_farinput(dimension, b, c, d, e, f, g, h);

}

/* Substitute input cleanup routine */
_ef_v_ipclean()
{
	max_dimension = 0;
	_efipclean();
}
