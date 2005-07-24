/*
@(#)File:            $RCSfile: decimal.h,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-20 04:05:07 $
@(#)Purpose:         Substitute decimal.h
@(#)Author:          J Leffler
*/

#ifndef DECIMAL_H
#define DECIMAL_H

/*
**  If a client has not got ESQL/C, this file gives sufficient information
**  for the code which uses decimals to compile correctly.  It is, however,
**  subject to change if Informix ever change their version of the file.
*/

/*
In file included from include/decsci.h:22,
                 from decsci.c:12:
include/decimal.h:19: redefinition of `struct decimal'
*/

#ifndef HAS_ESQLC

	typedef struct decimal
	{
		short	s[3];
		char	c[16];
	};

	typedef struct decimal dec_t;
#endif

#endif	/* DECIMAL_H */





