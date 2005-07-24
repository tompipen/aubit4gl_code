/*
@(#)File:            $RCSfile: getkey.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:16 $
@(#)Purpose:         Provide the missing I4GL function: FGL_GETKEY()
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1991-92,1998
*/

/*TABSTOP=4*/

#ifndef NO_FGLSYS_H
#include "fglsys.h"
#endif /* NO_FGLSYS_H */

#ifndef lint
static const char rcs[] = "@(#)$Id: getkey.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
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
