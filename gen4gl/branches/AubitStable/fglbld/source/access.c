/*
@(#)File:           $RCSfile: access.c,v $
@(#)Version:        $Revision: 1.1 $
@(#)Last changed:   $Date: 2002-06-20 09:10:42 $
@(#)Purpose:        I4GL/D4GL interface to access(2)
@(#)Author:         J Leffler
@(#)Copyright:      (C) JLSS 1988,1998
*/

#include <unistd.h>

#ifdef FOURJS
	#include "f2c/r_c.h"
#else
	/* fglsys.h is distributed with c-code I4GL. */
	#ifdef I4GL_C4GL
		#include "fglsys.h"
    #endif
#endif /* FOURJS */

#ifndef lint
	static const char rcs[] = "@(#)$Id: access.c,v 1.1 2002-06-20 09:10:42 afalout Exp $";
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
