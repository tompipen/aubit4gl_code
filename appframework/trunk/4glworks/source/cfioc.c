/*
	CFIOC.c  -  File IO routines

	The 4glWorks application framework
	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)

	Initial release: Oct 92
	Current release: Jun 02

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

#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <locator.h>
#include <sqltypes.h>
#include "ccmnc.h"
#include "cfioc.h"

static fgw_listtype fd_list = 
{
   NULL, NULL, 0, 0, EBADF
};

extern int status;

/*
** finds an fd
*/
fgw_fdesc *fgw_findfd(fd)
int fd;
{
    return (fgw_fdesc *) fgw_listsearch(fd, &fd_list);
}

/*
**  create new fd descriptor
*/
static fgw_fdesc *fgw_newdesc()
{
    fgw_fdesc *fd_n;

    if ((fd_n=(struct fgw_iodesc *) malloc(sizeof(struct fgw_iodesc)))!=NULL);
    {
	fd_n->fd=-1;		/* avoid erroneously closing fd 0! */
	fd_n->fd_isfile=0;
	fd_n->fd_pid=0;
	fd_n->fd_eolstatus=1;
	fd_n->fd_eof=0;
	fd_n->fd_offset=0;
	fd_n->fd_buflen=0;
	strcpy(fd_n->fd_buf, "");
	fd_n->fd_linelen=78;
	fd_n->fd_crnl=0;
	strcpy(fd_n->fd_wdsplit, "");
	fd_n->fd_eolidx=0;
	strcpy(fd_n->fd_lninit1, "");
	strcpy(fd_n->fd_lninit2, "");
	fgw_newentry(fd_n, &fd_list);
    }
    return fd_n;
}

/*
**  opens a file
*/
file_open(nargs)
int nargs;
{
    char f[90];
    char m[3];
    fgw_fdesc *fd_p;

    popquote(m, sizeof(m));
    popquote(f, sizeof(f));
    fgw_clip(f);
    if (fd_p=fgw_fileopen(f, m))
	retint(fd_p->fd_id);
    else
	retquote("");
    return(1);
}

/*
**  opens a file (internal)
*/
fgw_fdesc *fgw_fileopen(f, m)
char *f, *m;
{
    fgw_fdesc *fd_p;
    int flags;
    int mode;

    status=0;
    switch (m[0])
    {
      case 'r':
	mode=O_RDONLY;
	flags=0;
	break;
      case 'w':
	mode=O_WRONLY;
	flags=O_CREAT|O_TRUNC;
	break;
      case 'a':
	mode=O_WRONLY;
	flags=O_CREAT|O_APPEND;
	break;
      default:
	status=EINVAL;
	return NULL;
    }
    switch (m[1])
    {
      case '+':
	mode=O_RDWR;
	break;
      case ' ':
      case 0:
	break;
      default:
	status=EINVAL;
	return NULL;
    }
    if ((fd_p=fgw_newdesc())==NULL)
    {
	status=ENFILE;
	return NULL;
    }
    if ((fd_p->fd=open(f, mode|flags, 0600))==-1)
    {
	status=errno;
	fgw_dropentry(fd_p, &fd_list);
	return NULL;
    }
    else
    {
	fd_p->fd_isfile=1;
	fd_p->fd_read=read;
	fd_p->fd_write=write;
	fd_p->fd_close=close;
	return fd_p;
    }
}

/*
**  opens a pipe & spawns a child
*/
pipe_open(nargs)
int nargs;
{
    char *c;
    char m[2];
    fgw_fdesc *fd_p;

    popquote(m, sizeof(m));
    if (!(c=fgw_popquote()))
    {
	status=-1319;
	retquote("");
	return(1);
    }
    if (fd_p=fgw_pipeopen(c, m))
	retint(fd_p->fd_id);
    else
	retquote("");
    free(c);
    return(1);
}

/*
**  opens a pipe & spawns a child (internal)
*/
fgw_fdesc *fgw_pipeopen(c, m)
char *c, *m;
{
    fgw_fdesc *fd_p, *fd_f;
    int new_fds[2];
    int p_pipe, c_pipe;

    status=0;
    switch (m[0])
    {
      case 'r':
	p_pipe=0;
	c_pipe=1;
	break;
      case 'w':
	p_pipe=1;
	c_pipe=0;
	break;
      default:
	status=EINVAL;
	return NULL;
    }
    if ((fd_p=fgw_newdesc())==NULL)
    {
	status=ENFILE;
	return NULL;
    }
    if (pipe(new_fds)<0)
    {
	fgw_dropentry(fd_p, &fd_list);
	status=errno;
	return NULL;
    }
    fd_p->fd_pid=fork();
    if (fd_p->fd_pid==0)
    {
/*
**  child branch
*/
	close(new_fds[p_pipe]);
	if (new_fds[c_pipe]!=c_pipe)
	{
	    dup2(new_fds[c_pipe], c_pipe);
	    close(new_fds[c_pipe]);
	}
	fgw_dropentry(fd_p, &fd_list);
/*
**  Here, we should have also closed all the file streams currently open.
**  Since this is 4gl, we infer there aren't any. :-)
*/
	fd_p=(fgw_fdesc *) fd_list.head;
	while (fd_p!=NULL)
	{
	    if (fd_p->fd!=0 && fd_p->fd!=1)
		(*fd_p->fd_close) (fd_p->fd);
	    fd_f=fd_p;
	    fd_p=fd_p->fd_next;
	    free(fd_f);
	}
	sqldetach();
	execl("/bin/sh", "sh", "-c", c, NULL);
/*
**  in case anything goes wrong
*/
	_exit(127);
    }
/*
**  our branch
*/
    close(new_fds[c_pipe]);
    if (fd_p->fd_pid<0)
    {
	close(new_fds[p_pipe]);
	status=fd_p->fd_pid;
	fgw_dropentry(fd_p, &fd_list);
	return NULL;
    }
    else
    {
	fd_p->fd=new_fds[p_pipe];
	fd_p->fd_read=read;
	fd_p->fd_write=write;
	fd_p->fd_close=close;
	return fd_p;
    }
}

/*
**  add a desc to the fd list
*/
fgw_addfd(fd, r, w, c)
int fd;
int (*r)(), (*w)(), (*c)();
{
    fgw_fdesc *fd_p;

    if ((fd_p=fgw_newdesc())!=NULL)
    {
	fd_p->fd=fd;
	fd_p->fd_read=r;
	fd_p->fd_write=w;
	fd_p->fd_close=c;
	return fd_p->fd_id;
    }
    else
	return ENFILE;
}

/*
**  open stdin, stdout, stderr
*/
stdfd_open(nargs)
int nargs;
{
    int stdfd;
    int fd_id;

    popint(&stdfd);
    rsetnull(CINTTYPE, (char *) &fd_id);
    if (stdfd<0 || stdfd>2)
	status=-717;
    else if ((fd_id=fgw_addfd(stdfd, read, write, close))==-1)
    {
	status=-1;
	rsetnull(CINTTYPE, (char *) &fd_id);
    }
    retint(fd_id);
    return(1);
}

/*
** Lock an opened file
*/
file_lock(nargs)
int nargs;
{
    struct flock lck;
    fgw_fdesc *fd_p;
    int mandatory;
    int fd_id;

    popint(&mandatory);
    popint(&fd_id);
    status=0;
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))!=NULL)
    {
	if (fd_p->fd_isfile)
	{
	    if (mandatory)
		lck.l_type=F_WRLCK;
	    else
		lck.l_type=F_RDLCK;
	    lck.l_whence=0;
	    lck.l_start=0;
	    lck.l_len=0;
	    if (fcntl(fd_p->fd, F_SETLK, &lck)==-1)
		status=errno;
	}
	else
	    status=EINVAL;
    }
    return(0);
}

/*
** Terminate lock
*/
file_unlock(nargs)
int nargs;
{
    struct flock lck;
    fgw_fdesc *fd_p;
    int fd_id;

    popint(&fd_id);
    status=0;
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))!=NULL)
    {
	if (fd_p->fd_isfile)
	{
	    lck.l_type=F_UNLCK;
	    lck.l_whence=0;
	    lck.l_start=0;
	    lck.l_len=0;
	    if (fcntl(fd_p->fd, F_SETLK, &lck)==-1)
		status=errno;
	}
	else
	    status=EINVAL;
    }
    return(0);
}

/*
** tell current fd position
*/
file_tell(nargs)
int nargs;
{
    fgw_fdesc *fd_p;
    int fd_id;
    int offset;

    popint(&fd_id);
    status=0;
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))!=NULL)
	if (fd_p->fd_isfile)
	    retint(fd_p->fd_offset-fd_p->fd_buflen);
	else
	    status=ESPIPE;
    if (status)
	retquote("");
    return(1);
}

/*
** position fd current offset
*/
file_seek(nargs)
int nargs;
{
    fgw_fdesc *fd_p;
    int offset;
    int fd_id;

    popint(&offset);
    popint(&fd_id);
    status=0;
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))!=NULL)
    {
	if (!fd_p->fd_isfile)
	    status=ESPIPE;
	else if (lseek(fd_p->fd, offset, SEEK_SET)==-1)
	    status=errno;
	else
	{
	    *fd_p->fd_buf=0;
	    fd_p->fd_buflen=0;
	    fd_p->fd_offset=offset;
	}
    }
    return(0);
}

/*
** Read operation
*/
fd_read(nargs)
int nargs;
{
    char bf[FGW_BUFSIZE];
    int fd_id;
    fgw_fdesc *fd_p;
    char *p, *q, *s;
    int	r, ml, cl, tl;

    popint(&fd_id);
    status=0;
/*
** see what fd we're talking about
*/
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))==NULL)
    {
	retquote("");
	return(1);
    }
/*
**  the maximum length we can return depends on whether this is the
**  first line after a <NL> (a paragraph header) or not
*/
    if (fd_p->fd_eolstatus)
	tl=strlen(fd_p->fd_lninit1);
    else
	tl=strlen(fd_p->fd_lninit2);
    ml=fd_p->fd_linelen-tl;
/*
**  try to mimic fgets functionality
*/
    for (;;)
    {
	if (fd_p->fd_buflen)
	{
/*
**  identify [<CR>]<NL> position, if any
*/
	    cl=1;
	    r=0;
	    p=strchr(fd_p->fd_buf, '\n');
	    if (p!=NULL)
	    {
		if (p>fd_p->fd_buf)
		{
		    q=p;
		    if (*--q=='\r')
		    {
			p=q;
			cl++;
		    }
		}
		r=p-fd_p->fd_buf;
	    }
/*
** line break within client buffer limits
*/
	    if (p!=NULL && r<=ml)
	    {
/*
**  put the correct line header, and then the buffer contents
*/
		if (fd_p->fd_eolstatus)
		    strcpy(bf, fd_p->fd_lninit1);
		else
		    strcpy(bf, fd_p->fd_lninit2);
		strncat(bf, fd_p->fd_buf, r);
		bf[tl+r]=0;
		fgw_clip(bf);
/*
**  remove line from buffer
*/
		p=p+cl;
		fd_p->fd_buflen=fd_p->fd_buflen-r-cl;
		fgw_move(fd_p->fd_buf, p, fd_p->fd_buflen+1);
		fd_p->fd_eolstatus=1;
		retquote(bf);
		return(1);
	    }
/*
** buffer holds more than client is willing to accept, and no [<CR>]<LF>
*/
	    else if (r>ml || fd_p->fd_buflen>=ml)
	    {
/*
** this is what we're going to return if no word splitting requested, or no
** valid word separator found
*/
		s=fd_p->fd_buf+ml;
		fd_p->fd_buflen=fd_p->fd_buflen-ml;
		r=ml;
/*
** search for a word separator
*/
		if (strlen(fd_p->fd_wdsplit))
		    for (p=fd_p->fd_buf+ml-1; p>=fd_p->fd_buf; p--)
			for (q=fd_p->fd_wdsplit; *q; q++)
			    if (*p==*q)
			    {
				if (q-fd_p->fd_wdsplit>=fd_p->fd_eolidx)
				    p++;
				s=p;
				r=p-fd_p->fd_buf;
				fd_p->fd_buflen=fd_p->fd_buflen+ml-r;
				goto ws_label;
			    }
ws_label:
/*
**  put the correct line header, and then the buffer contents
*/
		if (fd_p->fd_eolstatus)
		    strcpy(bf, fd_p->fd_lninit1);
		else
		    strcpy(bf, fd_p->fd_lninit2);
		strncat(bf, fd_p->fd_buf, r);
		bf[tl+r]=0;
		fgw_clip(bf);
/*
**  remove line from buffer
*/
		fgw_move(fd_p->fd_buf, s, fd_p->fd_buflen+1);
		fd_p->fd_eolstatus=0;
		retquote(bf);
		return(1);
	    }
/*
**  last string in buffer and (hugh!) no [<CR>]<NL>
*/
	    else if (fd_p->fd_eof)
	    {
		if (fd_p->fd_eolstatus)
		    strcpy(bf, fd_p->fd_lninit1);
		else
		    strcpy(bf, fd_p->fd_lninit2);
		strcat(bf, fd_p->fd_buf);
		fgw_clip(bf);
		*fd_p->fd_buf=0;
		fd_p->fd_buflen=0;
		retquote(bf);
		return(1);
	    }
	}
/*
**  nothing in buffer and eof
*/
	else if (fd_p->fd_eof)
	{
	    retquote("");
	    return(1);
	}
/*
** not there yet, just keep on reading
*/
	if ((r=(*fd_p->fd_read) (fd_p->fd, bf, sizeof(bf)-fd_p->fd_buflen-1))>0)
	{
	    bf[r]=0;
/*
**	change tabs into spaces or the screen screws up
*/
	    p=strchr(bf, '\t');
	    while (p!=NULL)
	    {
		*p=' ';
		p=strchr(p, '\t');
	    }
	    strcat(fd_p->fd_buf, bf);
	    fd_p->fd_buflen+=r;
	    fd_p->fd_offset+=r;
	}
	else if (!r || errno==EINVAL)
	    fd_p->fd_eof=1;
	else
	{
	    retquote("");
	    status=errno;
	    return(1);
	}
    }
}

/*
** Read a blob from disk;
*/
fd_blobread(nargs)
int nargs;
{
    loc_t *textvar;
    int fd_id;
    fgw_fdesc *fd_p;
    char *newbuf;
    int r, bufsize;
    struct stat fileinfo;

    poplocator(&textvar);
    popint(&fd_id);
    status=0;
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))==NULL)
	return(0);
    if (fd_p->fd_buflen || fd_p->fd_offset)
    {
	status=-999;
	return(0);
    }
/*
**  try to avoid memory leaks & segv's :-)
*/
    if (textvar->loc_loctype==LOCMEMORY &&
	textvar->loc_bufsize>0 &&
	textvar->loc_buffer)
	free(textvar->loc_buffer);
/*
** WARNING we do not deal with loc_user_env. Mem leaks will result from
** text vars used with the text manipulation package, and not properly
** freed prior to calling fd_blobread
*/
    textvar->loc_buffer=NULL;
    textvar->loc_bufsize=0;
    textvar->loc_size=0;
    textvar->loc_indicator=-1;
    textvar->loc_loctype=LOCMEMORY;
/*
** work out how much we have to read - might not be possible if it is a pipe
*/
    if (fstat(fd_p->fd, &fileinfo))
    {
	bufsize=8096;
	fileinfo.st_size=0;
    }
    else
        bufsize=fileinfo.st_size;
/*
** keep on reading until we hit the end (single read for files)
*/
    for (;;)
    {
	textvar->loc_bufsize+=bufsize;
	if ((newbuf=(char *) realloc(textvar->loc_buffer, textvar->loc_bufsize)))
	{
	    textvar->loc_buffer=newbuf;
	    if ((r=(*fd_p->fd_read) (fd_p->fd,
				     textvar->loc_buffer+textvar->loc_size,
				     bufsize))>0)
	    {
		textvar->loc_size+=r;
		fd_p->fd_offset+=r;
		textvar->loc_indicator=0;
		if (r==fileinfo.st_size)
		    fd_p->fd_eof=1;
		else
		    continue;
	    }
	    else if (!r || errno==EINVAL)
		fd_p->fd_eof=1;
	    else
		status=errno;
	}
	else
	{
	    free(textvar->loc_buffer);
	    textvar->loc_buffer=NULL;
	    textvar->loc_bufsize=0;
	    textvar->loc_size=0;
	    status=-1319;
	}
	return(0);
    }
}

/*
** Write operation
*/
fd_write(nargs)
int nargs;
{
    char *bf;
    int fd_id;
    fgw_fdesc *fd_p;

    if (!(bf=fgw_popquote()))
    {
	status=-1319;
	return(0);
    }
    popint(&fd_id);
    status=0;
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))!=NULL)
    {
	fgw_clip(bf);
	fgw_fdwrite(fd_p, bf, strlen(bf));
    }
    free(bf);
    return(0);
}

/*
** Write operation, with [<CR>]<LN> postpended
*/
fd_writeln(nargs)
int nargs;
{
    char *bf;
    int fd_id;
    fgw_fdesc *fd_p;

    if (!(bf=fgw_popquote()))
    {
	status=-1319;
	return(0);
    }
    popint(&fd_id);
    status=0;
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))!=NULL)
    {
	fgw_clip(bf);
	if (fd_p->fd_crnl)
	   strcat(bf, "\r\n");
	else
	   strcat(bf, "\n");
	fgw_fdwrite(fd_p, bf, strlen(bf));
    }
    free(bf);
    return(0);
}

/*
** Dump a blob to disk;
*/
fd_blobwrite(nargs)
int nargs;
{
    loc_t *textvar;
    int fd_id;
    fgw_fdesc *fd_p;

    poplocator(&textvar);
    popint(&fd_id);
    if (textvar->loc_loctype!=LOCMEMORY)
    {
	status=-717;
	return(0);
    }
    status=0;
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))!=NULL &&
	textvar->loc_bufsize && !textvar->loc_indicator)
	fgw_fdwrite(fd_p, textvar->loc_buffer, textvar->loc_bufsize);
    return(0);
}

/*
**  write operation(internal)
*/
fgw_fdwrite(fd_p, bf, l)
fgw_fdesc *fd_p;
char *bf;
int l;
{
    int r;

    if (fd_p->fd_buflen && fd_p->fd_isfile)
	if (lseek(fd_p->fd, fd_p->fd_offset-fd_p->fd_buflen, SEEK_SET)==-1)
	    status=errno;
	else
	{
	    fd_p->fd_offset-=fd_p->fd_buflen;
	    fd_p->fd_buflen=0;
	    *fd_p->fd_buf=0;
	}
/*
** avoid SIGPIPEs if it's a pipe
*/
    if (fd_p->fd_pid)
	(void) signal(SIGPIPE, SIG_IGN); 
    if ((r=(*fd_p->fd_write) (fd_p->fd,bf,l))==-1)
	status=errno;
    else
    {
	if (fd_p->fd_eof)
	    fd_p->fd_eof=0;
	fd_p->fd_offset+=r;
    }
}

/*
** set output buffer size
*/
fd_linelen(nargs)
int nargs;
{
    int fd_id;
    int ln;
    fgw_fdesc *fd_p;

    popint(&ln);
    popint(&fd_id);
    status=0;
    if (ln>0 && ln<sizeof(fd_p->fd_buf))
    {
	if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))!=NULL)
	    fd_p->fd_linelen=ln;
    }
    else
	status=EINVAL;
    return(0);
}

/*
** set eol marker
*/
fd_crnl(nargs)
int nargs;
{
    int fd_id;
    int crnl;
    fgw_fdesc *fd_p;

    popint(&crnl);
    popint(&fd_id);
    status=0;
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))!=NULL)
	fd_p->fd_crnl=crnl;
    return(0);
}

/*
** set word prepend separator
*/
fd_prewordsep(nargs)
int nargs;
{
    int fd_id;
    char sep[5], post[5];
    fgw_fdesc *fd_p;

    popquote(sep, sizeof(sep));
    popint(&fd_id);
    status=0;
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))==NULL)
	return(0);
    strcpy(post, fd_p->fd_wdsplit+fd_p->fd_eolidx);
    strcpy(fd_p->fd_wdsplit, sep);
    strcat(fd_p->fd_wdsplit, post);
    fd_p->fd_eolidx=strlen(sep);    
    return(0);
}

/*
** set word postpend separator
*/
fd_postwordsep(nargs)
int nargs;
{
    int fd_id;
    char sep[5];
    fgw_fdesc *fd_p;

    popquote(sep, sizeof(sep));
    popint(&fd_id);
    status=0;
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))!=NULL)
	strcpy(fd_p->fd_wdsplit+fd_p->fd_eolidx, sep);
    return(0);
}

/*
** set paragraph line prepend text
*/
fd_1stlineheader(nargs)
int nargs;
{
    int fd_id;
    char hea[5];
    fgw_fdesc *fd_p;

    popquote(hea, sizeof(hea));
    popint(&fd_id);
    status=0;
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))!=NULL)
	strcpy(fd_p->fd_lninit1, hea);
    return(0);
}

/*
**  set continuation line prepend text
*/
fd_2ndlineheader(nargs)
int nargs;
{
    int fd_id;
    char hea[5];
    fgw_fdesc *fd_p;

    popquote(hea, sizeof(hea));
    popint(&fd_id);
    status=0;
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))!=NULL)
	strcpy(fd_p->fd_lninit2, hea);
    return(0);
}

/*
** Flag to discard buffer contents up to the next eol
*/
fd_droptoeol(nargs)
int nargs;
{
    char bf[FGW_BUFSIZE];
    int fd_id;
    fgw_fdesc *fd_p;
    char *p;
    int	r;

    popint(&fd_id);
    status=0;
/*
** see what fd we're talking about
*/
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))==NULL)
	return(0);
    else if (fd_p->fd_eolstatus)
	return(0);
    for (;;)
    {
	if (fd_p->fd_buflen)
	{
/*
**  identify [<CR>]<NL> position, if any
*/
	    if ((p=strchr(fd_p->fd_buf, '\n'))!=NULL)
	    {
		p++;
		fd_p->fd_buflen=fd_p->fd_buflen-(p-fd_p->fd_buf);
		fgw_move(fd_p->fd_buf, p, fd_p->fd_buflen+1);
		fd_p->fd_eolstatus=1;
		return(0);
	    }
	    else
	    {
		fd_p->fd_buflen=0;
		*fd_p->fd_buf=0;
	    }
/*
** not there yet, just keep on reading
*/
	}
	else if (fd_p->fd_eof)
	    return(0);
	if ((r=(*fd_p->fd_read) (fd_p->fd, bf, sizeof(bf)-fd_p->fd_buflen-1))>0)
	{
	    bf[r]=0;
/*
**	change tabs into spaces or the screen screws up
*/
	    p=strchr(bf, '\t');
	    while (p!=NULL)
	    {
		*p=' ';
		p=strchr(p, '\t');
	    }
	    strcat(fd_p->fd_buf, bf);
	    fd_p->fd_buflen+=r;
	    fd_p->fd_offset+=r;
	}
	else if (!r || errno==EINVAL)
	    fd_p->fd_eof=1;
	else
	{
	    status=errno;
	    return(0);
	}
    }
}

/*
**  return eol status
*/
fd_eol(nargs)
int nargs;
{
    int fd_id;
    fgw_fdesc *fd_p;

    popint(&fd_id);
    status=0;
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))!=NULL)
	retint(fd_p->fd_eolstatus);
    else
	retquote("");
    return(1);
}

/*
**  return eof status
*/
fd_eof(nargs)
int nargs;
{
    int fd_id;
    fgw_fdesc *fd_p;

    popint(&fd_id);
    status=0;
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))!=NULL)
	retint(fd_p->fd_eof && !fd_p->fd_buflen);
    else
	retquote("");
    return(1);
}

/*
**  Done with IO, close fd & free mem
*/
fd_close(nargs)
int nargs;
{
    int fd_id;
    fgw_fdesc *fd_p;

    popint(&fd_id);
    status=0;
    if ((fd_p=(fgw_fdesc *) fgw_listsearch(fd_id, &fd_list))==NULL)
    {
	retquote("");
	return(1);
    }
    retint(fgw_fdclose(fd_p));
    return(1);
}

/*
**  closes a stream (internal)
*/
fgw_fdclose(fd_p)
fgw_fdesc *fd_p;
{
    int r=0;
    int rc;

    if ((*fd_p->fd_close) (fd_p->fd)==-1)
	status=errno;
    if (fd_p->fd_pid)
    {
	do
	{
	    r=waitpid(fd_p->fd_pid, &rc, WUNTRACED);
	} while (r==-1 && errno==EINTR);
	if (r==-1)
	{
	    status=errno;
	    rsetnull(CINTTYPE, (char *) &r);
	}
	else
	    r=(rc>>8);
    }
    fgw_dropentry(fd_p, &fd_list);
    return(r);
}
