head	1.3;
access;
symbols;
locks; strict;
comment	@ * @;


1.3
date	98.04.16.18.32.47;	author jleffler;	state Exp;
branches;
next	1.2;

1.2
date	92.10.13.05.15.33;	author jl;	state Exp;
branches;
next	1.1;

1.1
date	91.10.17.17.11.05;	author johnl;	state Exp;
branches;
next	;


desc
@@


1.3
log
@Convert to ANSI C
@
text
@/*
@@(#)File:            $RCSfile: getkey.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:         Provide the missing I4GL function: FGL_GETKEY()
@@(#)Author:          J Leffler
@@(#)Copyright:       (C) JLSS 1991-92,1998
*/

/*TABSTOP=4*/

#ifndef NO_FGLSYS_H
#include "fglsys.h"
#endif /* NO_FGLSYS_H */

#ifndef lint
static const char rcs[] = "@@(#)$Id: getkey.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
#endif

int fgl_getkey(int nargs)
{
	extern short eflastkey;

	if (nargs != 0)
		_fgl_fatal("fgl_getkey", 1, -1318);

	eflastkey = _efrgetkey();
	retint(eflastkey);
	return(1);
}
@


1.2
log
@Fix called function
@
text
@d2 4
a5 4
@@(#)File:            $RCSfile: getkey.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:         Provide the missing function: FGL_GETKEY()
d7 1
d12 3
a14 1
#define I4GL_C
d17 1
a17 1
static	char	sccs[] = "@@(#)$Id: getkey.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
d20 1
a20 2
I4GL_C fgl_getkey(i)
int		i;
d23 3
@


1.1
log
@Initial revision
@
text
@d22 1
a22 1
	eflastkey = _rfgetkey();
@
