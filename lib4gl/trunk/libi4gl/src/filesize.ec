head	1.1;
access;
symbols;
locks; strict;
comment	@# @;


1.1
date	2001.07.27.16.24.09;	author jleffler;	state Exp;
branches;
next	;


desc
@Find the size of a file
@


1.1
log
@Initial revision
@
text
@/*
@@(#)File:            $RCSfile: filesize.ec,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:         Find the size of a file.
@@(#)Author:          J Leffler
@@(#)Copyright:       (C) JLSS 2001
@@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fglsys.h>
#include <sqltypes.h>
#include <sqlhdr.h>

#ifndef lint
static const char rcs[] = "@@(#)$Id: filesize.ec,v 1.1 2002-06-14 05:03:46 afalout Exp $";
#endif

int i4gl_filesize(int nargs)
{
    struct stat sb;
    char filename[1024];        /* PATH_MAX? */
    if (nargs != 1)
        fgl_fatal(__LINE__, __FILE__, -1316);   /* Wrong number of arguments */
	popstring(filename, sizeof(filename));
    if (stat(filename, &sb) != 0)
    {
        int null;
        rsetnull(SQLINT, (void *)&null);
        retint(null);
    }
    else
        retint(sb.st_size);
    return(1);
}

@
