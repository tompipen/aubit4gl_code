/*
	CFIOC.h  -  File IO routines defines

	The 4glWorks application framework
	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)

	Initial release: Oct 92
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

#ifndef CFIOC_H
#define FGW_BUFSIZE 513
#include <sys/types.h>

typedef struct fgw_iodesc
{
    int fd_id;			/* fgw file descriptor id */
    struct fgw_iodesc *fd_next;	/* next open fd */
    int fd;			/* file descriptor */
    int fd_isfile;		/* seek, tell, lock ops valid? */
    pid_t fd_pid;		/* child pid */
    int fd_eolstatus;		/* last read terminated with a NL? */
    int fd_eof;			/* EOF marker */
    off_t fd_offset;		/* offset within file */
    int fd_buflen;		/* buffer contents */
    char fd_buf[FGW_BUFSIZE];	/* the actual buffer */
    int fd_crnl;		/* send a CR together with the NL? */
    int fd_linelen;		/* return buffer lenght */
    char fd_wdsplit[9];		/* word separator characters */
    int fd_eolidx;		/* index of word separators to be saved at the
				   end of the current line. chars below this
				   are returned at the beginning of the next */
    char fd_lninit1[5];		/* 'paragraph' line header */
    char fd_lninit2[5];		/* 'continuation' line header */
    int	(*fd_read)();		/* pointer to read function */
    int (*fd_write)();		/* pointer to write function */
    int (*fd_close)();		/* pointer to close function */
} fgw_fdesc;

extern fgw_fdesc *fgw_findfd();

#define CFIOC_H
#endif
