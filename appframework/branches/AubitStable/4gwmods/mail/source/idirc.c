/*

	IDIRC.c  -  4gwmail directory routines

	4gwMail, a news and mail client 4glWorks module
	Copyright (C) 1997-2002 Marco Greco (marco@4glworks.com)

	Initial release: Oct 97
	Current release: Jan 02

	This library is free software; you can redistribute it and/or
	modify it under the terms of the GNU Lesser General Public
	License as published by the Free Software Foundation; either
	version 2.1 of the License, or (at your option) any later version.

	This library is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public
	License along with this library; if not, write to the Free Software
	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#ifndef popquote
#define popquote popvchar	/* since this is what we actually need */
#endif

#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include "id-osdep.h"

#ifdef HAVE_DIRENT_H
#include <dirent.h>
#else
#define dirent direct
#if HAVE_SYS_NDIR_H
#include <sys/ndir.h>
#endif
#if HAVE_SYS_DIR_H
#include <sys/dir.h>
#endif
#if HAVE_NDIR_H
#include <ndir.h>
#endif
#endif		/* HAVE_DIRENT_H */

extern int status;

DIR *dstream;
int dtype=0;

/*
**  open directory for scanning
*/
diropen(nargs)
int nargs;
{
    char dirname[80];

    popquote(dirname, sizeof(dirname));
    fgw_clip(dirname);
    if (status=(dtype!=0))
	return(0);
    dstream=opendir(dirname);
    if (dstream!=NULL)
	dtype=1;
    else
	status=errno;
    return(0);
}
/*
**  reads next directory entry
*/
dirin(nargs)
int nargs;
{
    char bf[70];
    char *p;
    struct dirent *d;

    bf[0]=0;
    if (status=(dtype==0))
	{}
    else if ((d=readdir(dstream))==NULL)
    {
	closedir(dstream);
	dtype=0;
    }
    else
    {
	strcpy(bf, d->d_name);
	p=strpbrk(bf, "\t\n\r");
	while (p != NULL)
	{
	    *p=' ';
	    p=strpbrk(p, "\t\n\r");
	}
    }
    retquote(bf);
    return(1);
}
/*
**  closes directory stream
*/
dirclose(nargs)
int nargs;
{
    if (status=(dtype!=0))
    {
	closedir(dstream);
	dtype=0;
    }
    return(0);
}
/*
**  creates a directory
*/
dirmake(nargs)
int nargs;
{
    char dirname[80];

    popquote(dirname, sizeof(dirname));
    fgw_clip(dirname);
    if (mkdir(dirname, 0700)==-1)
	status=errno;
    return(0);
}
