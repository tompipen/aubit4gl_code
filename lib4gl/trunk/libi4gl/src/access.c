head	1.4;
access;
symbols;
locks; strict;
comment	@ * @;


1.4
date	98.07.08.16.05.52;	author jleffler;	state Exp;
branches;
next	1.3;

1.3
date	98.07.08.01.57.40;	author jleffler;	state Exp;
branches;
next	1.2;

1.2
date	98.06.16.23.13.45;	author jleffler;	state Exp;
branches;
next	1.1;

1.1
date	88.09.26.18.38.53;	author john;	state Exp;
branches;
next	;


desc
@@


1.4
log
@Add support for D4GL
@
text
@/*
@@(#)File:           $RCSfile: access.c,v $
@@(#)Version:        $Revision: 1.1 $
@@(#)Last changed:   $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:        I4GL/D4GL interface to access(2)
@@(#)Author:         J Leffler
@@(#)Copyright:      (C) JLSS 1988,1998
*/

#include <unistd.h>

#ifdef FOURJS
#include "f2c/r_c.h"
#else
#include "fglsys.h"
#endif /* FOURJS */

#ifndef lint
static const char rcs[] = "@@(#)$Id: access.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
#endif

int	file_access(int n)
{
	char	file[512];
	int		mode;

	if (n != 2)
		fgl_fatal("file_access", 1, -1318);
	popint(&mode);
	popstring(file, sizeof(file));
	retint(access(file, mode));
	return(1);
}

#ifdef FOURJS
CFACE(file_access, 2, 1)
#endif /* FOURJS */
@


1.3
log
@Remove tabs from file header
@
text
@d3 3
a5 3
@@(#)Version:        $Revision: 1.1 $
@@(#)Last changed:   $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:        I4GL interface to access(2)
d12 3
a14 8
/*
extern void popint(int *);
extern void fgl_fatal(const char *, int, int);
extern void popstring(char *, size_t);
extern void retint(int);

Or:

d16 1
a16 1
*/
d19 1
a19 1
static const char rcs[] = "@@(#)$Id: access.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
d34 4
@


1.2
log
@Update
@
text
@d2 5
a6 5
@@(#)File:			$RCSfile: access.c,v $
@@(#)Version:		$Revision: 1.1 $
@@(#)Last changed:	$Date: 2002-06-14 05:03:46 $
@@(#)Purpose:		I4GL interface to access(2)
@@(#)Author:			J Leffler
d17 4
d24 1
a24 1
static const char rcs[] = "@@(#)$Id: access.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
@


1.1
log
@Initial revision
@
text
@d2 6
a7 5
@@(#)	File:			$RCSfile: access.c,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:46 $
@@(#)	Purpose:		I4GL interface to access(2)
@@(#)	Author:			J Leffler
d10 8
a17 1
#define I4GL_C	int /* Interface to C from I4GL */
d20 1
a20 1
static char	sccs[] = "@@(#)$Id: access.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
d23 1
a23 2
I4GL_C	file_access(n)
int	n;
d29 1
a29 4
	{
		retint(-1);
		return(1);
	}
@
