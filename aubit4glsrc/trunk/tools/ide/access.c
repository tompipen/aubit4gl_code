/*
@(#)File:           $RCSfile: access.c,v $
@(#)Version:        $Revision: 1.1.1.1 $
@(#)Last changed:   $Date: 2001-08-20 02:37:05 $
@(#)Purpose:        I4GL/D4GL interface to access(2)
@(#)Author:         J Leffler
@(#)Copyright:      (C) JLSS 1988,1998
*/

#include <unistd.h>

#ifdef FOURJS
#include "f2c/r_c.h"
#else
#ifndef AUBIT4GL
#ifndef QUERIX
#include "fglsys.h"
#endif
#endif
#endif /* FOURJS */

#ifndef lint
static const char rcs[] = "@(#)$Id: access.c,v 1.1.1.1 2001-08-20 02:37:05 afalout Exp $";
#endif

#ifdef AUBIT4GL
int	aclfgl_file_access(int n)
#else
int	file_access(int n)
#endif
{
	char	file[512];
	int		mode;

#ifndef AUBIT4GL
#ifndef QUERIX
/*
access.o: In function `file_access':
access.o(.text+0x12): undefined reference to `popint'
access.o(.text+0x23): undefined reference to `popstring'
access.o(.text+0x35): undefined reference to `retint'
collect2: ld returned 1 exit status
*/

/*
/tmp/cc2QRfnO.o: In function `aclfgl_file_check':
/usr/aubit/Aubit4gl/IDE/./d4glfile.c:2353: undefined reference to `aclfgl_file_access'
/tmp/ccwOmu9q.o: In function `aclfgl_form_check':
/usr/aubit/Aubit4gl/IDE/./d4glform.c:2359: undefined reference to `aclfgl_file_access'
/tmp/ccvI32ZR.o: In function `aclfgl_is_a_file':
/usr/aubit/Aubit4gl/IDE/./d4glmain.c:1205: undefined reference to `aclfgl_file_access'
/tmp/ccvI32ZR.o: In function `aclfgl_is_file_writeable':
/usr/aubit/Aubit4gl/IDE/./d4glmain.c:1243: undefined reference to `aclfgl_file_access'
*/

/*
tmp/ccAKBFBo.o: In function `main':
/usr/aubit/Aubit4gl/IDE/./d4glmain.c:229: undefined reference to `aclfgl_file_check'
/usr/aubit/Aubit4gl/IDE/./d4glmain.c:244: undefined reference to `aclfgl_file_modify_cycle'
/tmp/ccAKBFBo.o: In function `aclfgl_main_menu':
/usr/aubit/Aubit4gl/IDE/./d4glmain.c:359: undefined reference to `aclfgl_file_compile_menu'
/usr/aubit/Aubit4gl/IDE/./d4glmain.c:382: undefined reference to `aclfgl_form_compile_menu'
*/



	if (n != 2)
		fgl_fatal("file_access", 1, -1318);
	popint(&mode);
	popstring(file, sizeof(file));
	retint(access(file, mode));
#endif
#endif

	return(1);
}

#ifdef FOURJS
CFACE(file_access, 2, 1)
#endif /* FOURJS */

