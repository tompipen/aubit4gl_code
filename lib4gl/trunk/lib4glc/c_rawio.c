
# include	"cfun4gl.h"
# include	<sys/stat.h>


function(c_open,2,3,1,1)
{
    cfgl_Path path;
    cfgl_FMode fmode;
    char flagstr[21];
    int rflag = 0, wflag = 0;
    int oflag = 0, mode = 0666;
    int fd, i;

    if(nargs != 2 && nargs != 3)
	cfgl_fatal("usage: c_open(path, oflag [, mode] char(*))"
			 " returning integer\n");

    if(nargs == 3)
    {
	/* get create mode argument */
	popstring(fmode, sizeof(fmode));
	mode = cfgl_interpMode(fmode);
    }

    /* get open flag argument */
    popstring(flagstr, sizeof(flagstr));

    for(i = 0; flagstr[i]; ++i)
    {
	switch(flagstr[i])
	{
	case 'r':  rflag = 1;		break;
	case 'w':  wflag = 1;		break;
	case 'd':  oflag |= O_NDELAY;	break;
	case 'b':  oflag |= O_NONBLOCK;	break;
	case 'a':  oflag |= O_APPEND;	break;
	case 's':  oflag |= O_SYNC;	break;
	case 'c':  oflag |= O_CREAT;	break;
	case 't':  oflag |= O_TRUNC;	break;
	case 'e':  oflag |= O_EXCL;	break;
	case 'y':  oflag |= O_NOCTTY;	break;
	}
    }

    /* make sense of the read and write flags */
    if(rflag && wflag)	oflag |= O_RDWR;
    else if(wflag)	oflag |= O_WRONLY;
    else /* assume */	oflag |= O_RDONLY;

    /* get file name argument */
    popstring(path, sizeof(path));

    fd = open(path, oflag, mode);
    if(fd < 0)
	cfgl_errno = errno;

    retint(fd);
    return 1;
}   /* c_open */
/*JFACE*/ int c_open_2(int nargs) { return c_open(nargs); }
/*JFACE*/ int c_open_3(int nargs) { return c_open(nargs); }


function(c_pipe,0,0,1,2)
{
    int pipefd[2];

    if(nargs != 0)
	cfgl_fatal("usage: c_pipe() returning (rfd, wfd) integer\n");

    if(pipe(pipefd) == -1)
    {
	cfgl_errno = errno;
	pipefd[0] = -1;
	pipefd[1] = -1;
    }

    retint(pipefd[0]);
    retint(pipefd[1]);

    return 2;

}   /* c_pipe */
/*JFACE*/ int c_pipe_0(int nargs) { return c_pipe(nargs); }


function(c_dup,1,1,1,1)
{
    int i, fd;

    if(nargs != 1)
	cfgl_fatal("usage: c_dup(fd integer) returning (nfd) integer\n");

    popint(&fd);
    i = dup(fd);
    if(i < 0)
	cfgl_errno = errno;

    retint(i);
    return 1;
}   /* c_dup */
/*JFACE*/ int c_dup_1(int nargs) { return c_dup(nargs); }


function(c_dup2,2,2,1,1)
{
    int i, fd1, fd2;

    if(nargs != 2)
	cfgl_fatal("usage: c_dup2(fd1, fd2 integer) returning (fd) integer\n");

    popint(&fd2);
    popint(&fd1);
    i = dup2(fd1, fd2);
    if(i < 0)
	cfgl_errno = errno;

    retint(i);
    return 1;
}   /* c_dup */
/*JFACE*/ int c_dup2_2(int nargs) { return c_dup2(nargs); }


function(c_close,1,1,1,1)
{
    int i, fd;

    if(nargs != 1)
	cfgl_fatal("usage: c_close(fd integer) returning (status) integer\n");

    popint(&fd);
    i = close(fd);
    if(i < 0)
	cfgl_errno = errno;

    retint(i);
    return 1;
}   /* c_close */
/*JFACE*/ int c_close_1(int nargs) { return c_close(nargs); }


function(c_read,2,2,1,2)
{
    cfgl_IOBuf buf;
    int i, n, fd;

    if(nargs != 2)
	cfgl_fatal("usage: c_read(fd, n integer)"
		         " returning (nbytes) integer, (str) char(*)\n");

    /* get byte count argument */
    popint(&n);

    /* make sure count is sensible */
    if(n > CFGL_IOBUF) n = CFGL_IOBUF;
    if(n < 1)          n = 1;

    /* get file descriptor argument */
    popint(&fd);

    i = read(fd, buf, n);
    if(i < 0)
    {
	cfgl_errno = errno;
	buf[0] = 0;
    }
    else
	buf[i] = 0;
   
    retint(i);
    retquote(buf);

    return 2;
}   /* c_read */
/*JFACE*/ int c_read_2(int nargs) { return c_read(nargs); }


function(c_write,3,3,1,1)
{
    cfgl_IOBuf buf;
    int i, n, fd;

    if(nargs != 3)
	cfgl_fatal("usage: c_write(fd integer, str char(*), n integer)"
	                 " returning (nbytes) integer\n");

    /* get byte count argument */
    popint(&n);

    /* get string */
    popquote(buf, sizeof(buf));

    /* get file descriptor argument */
    popint(&fd);

    /* make sure count is sensible */
    if(n > CFGL_IOBUF) n = CFGL_IOBUF;
    if(n < 0)          n = 0;
    if(n == 0)         n = cfgl_trim(buf);

    i = write(fd, buf, n);
    if(i < 0)
	cfgl_errno = errno;
   
    retint(i);

    return 1;
}   /* c_write */
/*JFACE*/ int c_write_3(int nargs) { return c_write(nargs); }


function(c_mread,4,4,1,1)
{
    int i, ofs, n, fd;
    cfgl_MemPtr mp;

    if(nargs != 4)
	cfgl_fatal("usage: c_mread(fd, bufptr, ofs, n integer)"
		         " returning (nbytes) integer\n");

    popint(&n);
    popint(&ofs);
    mp = cfgl_getptr();
    popint(&fd);

    cfgl_checkmem("c_mread", mp, ofs, n);

    i = read(fd, mp->m + ofs, n);
    if(i < 0)
	cfgl_errno = errno;
   
    retint(i);
    return 1;

}   /* c_mread */
/*JFACE*/ int c_mread_4(int nargs) { return c_mread(nargs); }
 

function(c_mwrite,4,4,1,1)
{
    int i, ofs, n, fd;
    cfgl_MemPtr mp;

    if(nargs != 4)
	cfgl_fatal("usage: c_mwrite(fd, bufptr, ofs, n integer)"
	                 " returning (nbytes) integer\n");

    popint(&n);
    popint(&ofs);
    mp = cfgl_getptr();
    popint(&fd);

    cfgl_checkmem("c_mwrite", mp, ofs, n);

    i = write(fd, mp->m + ofs, n);
    if(i < 0)
	cfgl_errno = errno;
   
    retint(i);

    return 1;
}   /* c_mwrite */
/*JFACE*/ int c_mwrite_4(int nargs) { return c_mwrite(nargs); }


function(c_lseek,3,3,1,1)
{
    int fd, whence;
    long ofs;
    int i;

    if(nargs != 3)
	cfgl_fatal("usage: c_lseek(fd, ofs, whence integer)"
			 " returning integer\n");

    popint(&whence);
    poplong(&ofs);
    popint(&fd);

    i = lseek(fd, ofs, whence);
    if(i < 0)
	cfgl_errno = errno;

    retlong(i);
    return 1;

}   /* c_lseek */
/*JFACE*/ int c_lseek_3(int nargs) { return c_lseek(nargs); }


function(c_chmod,2,2,1,1)
{
    cfgl_Path path;
    cfgl_FMode fmode;

    int i, mode = 0;

    if(nargs != 2)
	cfgl_fatal("usage: c_chmod(path, mode char(*))"
			 " returning integer\n");

    /* get create mode argument */
    popstring(fmode, sizeof(fmode));
    mode = cfgl_interpMode(fmode);		/* in direct.c */

    /* get file name argument */
    popstring(path, sizeof(path));

    i = chmod(path, mode);
    if(i < 0)
	cfgl_errno = errno;

    retint(i);
    return 1;

}   /* c_chmod */
/*JFACE*/ int c_chmod_2(int nargs) { return c_chmod(nargs); }


function(c_fsync,1,1,1,1)
{
    int status, fd;

    if(nargs != 1)
	cfgl_fatal("usage: c_fsync(fd smallint) returning integer\n");

    popint(&fd);
    status = fsync(fd);
    if(status < 0)
	cfgl_errno = errno;
    retint(status);
    return 1;

}   /* c_fsync */
/*JFACE*/ int c_fsync_1(int nargs) { return c_fsync(nargs); }


function(c_umask,1,1,1,1)
{
    cfgl_FMode fmode;
    int mode;

    if(nargs != 1)
	cfgl_fatal("usage: c_umask(mask char(*)) returning char(*)\n");

    popstring(fmode, sizeof(fmode));
    mode = cfgl_interpMode(fmode);

    mode = umask(mode);

    strcpy(fmode, "---------");
    if(mode & S_IRUSR) fmode[0] = 'r';
    if(mode & S_IWUSR) fmode[1] = 'w';
    if(mode & S_IXUSR) fmode[2] = 'x';
    if(mode & S_IRGRP) fmode[3] = 'r';
    if(mode & S_IWGRP) fmode[4] = 'w';
    if(mode & S_IXGRP) fmode[5] = 'x';
    if(mode & S_IROTH) fmode[6] = 'r';
    if(mode & S_IWOTH) fmode[7] = 'w';
    if(mode & S_IXOTH) fmode[8] = 'x';

    retquote(fmode);
    return 1;

}   /* c_umask */
/*JFACE*/ int c_umask_1(int nargs) { return c_umask(nargs); }


function(c_lockf,3,3,1,1)
{
    int fd, ftn, size;
    char cmd[21];
    int status;

    if(nargs != 3)
        cfgl_fatal("usage: c_lockf(fd integer, ftn char(*), size integer)"
			 " returning integer\n");

    popint(&size);
    popstring(cmd, sizeof(cmd));
    popint(&fd);

	 if(!strcmp(cmd, "F_" "ULOCK")) ftn = F_ULOCK;
    else if(!strcmp(cmd, "F_" "LOCK"))  ftn = F_LOCK;
    else if(!strcmp(cmd, "F_" "TLOCK")) ftn = F_TLOCK;
    else if(!strcmp(cmd, "F_" "TEST"))  ftn = F_TEST;
    else cfgl_fatal("c_lockf(,%s,): unknown funct" "ion\n", cmd);

    status = lockf(fd, ftn, size);
    if(status == -1)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_lockf */
/*JFACE*/ int c_lockf_3(int nargs) { return c_lockf(nargs); }


function(c_fcntl,2,3,1,1)
{
    char carg[15], buf[15];
    int fd, cmd, arg;
    int status;

    if(nargs < 2 || nargs > 3)
	cfgl_fatal("usage: c_fcntl(fd, cmd char(*) [, arg])"
			 " returning integer\n");

    if(nargs == 3)
	popstring(carg, sizeof(carg));
    else
	*carg = 0;

    popstring(buf, sizeof(buf));

	 if(!strcmp(buf, "F_" "DUPFD")) cmd = F_DUPFD;
    else if(!strcmp(buf, "F_" "GETFD")) cmd = F_GETFD;
    else if(!strcmp(buf, "F_" "SETFD")) cmd = F_SETFD;
    else if(!strcmp(buf, "F_" "GETFL")) cmd = F_GETFL;
    else if(!strcmp(buf, "F_" "SETFL")) cmd = F_SETFL;
    else cfgl_fatal("c_fcntl(): unknown or unsupported command: %s\n", buf);

    popint(&fd);

    if(cmd == F_DUPFD || cmd == F_GETFD || cmd == F_SETFD)
    {
	pushquote(carg, sizeof(carg));	/* convert to int using 4GL */
	popint(&arg);
	status = fcntl(fd, cmd, arg);
	if(status == -1)
	    cfgl_errno = errno;
	retint(status);
	return 1;
    }

    if(cmd == F_GETFL)
    {
	char *cp = buf;

	status = fcntl(fd, cmd);
	if(status == -1)
	    cfgl_errno = errno;
	else
	{
	    if(status & O_NDELAY)   *cp++ = 'd';
	    if(status & O_NONBLOCK) *cp++ = 'b';
	    if(status & O_APPEND)   *cp++ = 'a';
	    if(status & O_SYNC)     *cp++ = 's';
	    *cp++ = ' ';		/* prevent it from being null */
	}

	*cp = 0;
	retquote(buf);
	return 1;
    }

    if(cmd == F_SETFL)
    {
	char *cp = carg;
	for(arg = 0; *cp; ++cp)
	    switch(*cp)
	    {
		case 'd':  arg |= O_NDELAY;	break;
		case 'b':  arg |= O_NONBLOCK;	break;
		case 'a':  arg |= O_APPEND;	break;
		case 's':  arg |= O_SYNC;	break;
	    }

	status = fcntl(fd, cmd, arg);
	if(status == -1)
	    cfgl_errno = errno;
	retint(status);
	return 1;
    }

    return 0;

}   /* c_fcntl */
/*JFACE*/ int c_fcntl_2(int nargs) { return c_fcntl(nargs); }
/*JFACE*/ int c_fcntl_3(int nargs) { return c_fcntl(nargs); }
