/*
@(#)File:            $RCSfile: decimal.h,v $
@(#)Version:         $Revision: 1.1 $
@(#)Last changed:    $Date: 2002-06-16 07:36:15 $
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

typedef struct decimal
{
	short	s[3];
	char	c[16];
};

typedef struct decimal dec_t;

#endif	/* DECIMAL_H */
