/*
@(#)File:            $RCSfile: filesize.ec,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:16 $
@(#)Purpose:         Find the size of a file.
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 2001
@(#)Product:         :PRODUCT:
*/

/*TABSTOP=4*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fglsys.h>
#include <sqltypes.h>
#include <sqlhdr.h>

#ifndef lint
static const char rcs[] = "@(#)$Id: filesize.ec,v 1.2 2002-06-14 09:23:16 afalout Exp $";
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

