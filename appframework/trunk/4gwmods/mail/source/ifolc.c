/*

	IFOLC.c  -  4gwmail folder io routines

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

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

extern int status;

/*
**  create a folder lock
*/
mil_createlock(nargs)
int nargs;
{
    char lockname[80];
    char tempname[80];
    int desc;

    popquote(lockname, 75);
    fgw_clip(lockname);
    strcpy(tempname, lockname);
    strcat(lockname, ".lock");
    strcat(tempname, "XXXXXX");
    mktemp(tempname);
    unlink(tempname);
    status=(desc=open(tempname, O_WRONLY | O_CREAT | O_EXCL, 0666))<0;
    close(desc);
    if (!status)
    {
	status=link(tempname, lockname);
	unlink(tempname);
    }
    retint(status);
    return(1);
}
/*
**  drops a folder lock
*/
mil_droplock(nargs)
int nargs;
{
    char lockname[80];

    popquote(lockname, 75);
    fgw_clip(lockname);
    strcat(lockname, ".lock");
    status=unlink(lockname);
    return(0);
}
/*
**  drops a folder
*/
mil_dropfile(nargs)
int nargs;
{
    char filename[80];

    popquote(filename, 80);
    fgw_clip(filename);
    if (unlink(filename)==-1)
	status=errno;
    return(0);
}
/*
**  renames a folder
*/
mil_renamefile(nargs)
int nargs;
{
    char oldname[80];
    char newname[80];

    popquote(newname, 80);
    popquote(oldname, 80);
    fgw_clip(oldname);
    fgw_clip(newname);
    if (rename(oldname, newname)==-1)
	status=errno;
    return(0);
}
/*
**  returns folder modification time
*/
mil_getstat(nargs)
int nargs;
{
    char filename[80];
    struct stat finfo;

    popquote(filename, 80);
    fgw_clip(filename);
    if (stat(filename, &finfo))
    {
	finfo.st_mtime=time(NULL);
	finfo.st_size=0;
    }
    retint(finfo.st_mtime);
    retint(finfo.st_size);
    return(2);
}
