head	1.1;
access;
symbols;
locks; strict;
comment	@ * @;


1.1
date	96.10.09.06.04.24;	author johnl;	state Exp;
branches;
next	;


desc
@@


1.1
log
@Initial revision
@
text
@/*
@@(#)File:            $RCSfile: i4glsqrt.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:         I4GL-callable SQRT routine i4gl_sqrt()
@@(#)Author:          J Leffler
@@(#)Copyright:       (C) JLSS 1996
@@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/

#include <decimal.h>
#include <fglsys.h>

#ifndef lint
static const char sccs[] = "@@(#)$Id: i4glsqrt.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
#endif

int i4gl_sqrt(int n)
{
	dec_t	d;
	dec_t	r;
	int     s;

	if (n != 1)
		fgl_fatal("i4gl_sqrt", 1, -1318);

	popdec(&d);
	s = decsqrt(&d, &r);
	if (s != 0)
		fgl_fatal("i4gl_sqrt", 2, s);

	retdec(&r);
	return(1);
}


@
