
# include	"cfun4gl.h"


static FILE *fgl_files[_NFILE] =
{
    stdin, stdout, stderr,
};


/* Callable from C. Converts a 4GL file handle to a real FILE * */
/* allows C functions to accept 4GL file handles */
FILE *cfgl_getfd(int fileno)
{
    if (fileno < 0 || fileno >= _NFILE)
	return NULL;

    return fgl_files[fileno];
}   /* cfgl_getfd */


/* Callable from C. Converts a real FILE * to a 4GL file handle */
/* registers the real FILE * for use by 4GL functions */
int cfgl_setfd(FILE *fp)
{
    int fileno;

    if(fp == NULL)
	return -1;

    for(fileno = 0; fileno < _NFILE; ++fileno)
	if (fgl_files[fileno] == NULL)
	{
	    fgl_files[fileno] = fp;
	    return fileno;
	}

    return -2;
}   /* cfgl_setfd */


/* Callable from C. Removes a real FILE * from the 4GL file handle list */
void cfgl_unsetfd(FILE *fp)
{
    int fileno;

    if(fp)
	for(fileno = 0; fileno < _NFILE; ++fileno)
	    if(fgl_files[fileno] == fp)
	    {
		fgl_files[fileno] = NULL;
		return;
	    }

}   /* cfgl_unsetfd */


/* cf. popint() et.al. - one-stop 4GL file handle getting */
void cfgl_popfd(FILE **fp)
{
    int fd;

    popint(&fd);
    if(risnull(CINTTYPE, (char *) &fd))
	*fp = NULL;
    else
	*fp = cfgl_getfd(fd);

    if(! *fp)
	cfgl_errno = EBADF;

}   /* cfgl_popfd */


/* cf. retint() et.al. - one-stop storage and return of 4GL file handles */
void cfgl_retfd(FILE *fp)
{
    if(fp)
	retint(cfgl_setfd(fp));
    else
	retquote("");	/* NULL in 4GL */

}   /* cfgl_retfd */


function(c_fopen,2,2,1,1)
{
    cfgl_Path path;
    char mode[21];
    FILE *fd;

    popstring(mode, sizeof(mode));
    popstring(path, sizeof(path));

    if((fd = fopen(path, mode)))
	cfgl_retfd(fd);
    else
    {
	cfgl_errno = errno;
	retquote("");
    }

    return 1;

}   /* c_fopen */
/*JFACE*/ int c_fopen_2(int nargs) { return c_fopen(nargs); }


function(c_freopen,3,3,1,1)
{
    cfgl_Path path;
    char mode[21];
    FILE *fd;

    cfgl_popfd(&fd);
    popstring(mode, sizeof(mode));
    popstring(path, sizeof(path));

    if(! fd)
	retquote("");
    else if((fd = freopen(path, mode, fd)))
	cfgl_retfd(fd);
    else
    {
	cfgl_errno = errno;
	retquote("");
    }

    return 1;

}   /* c_freopen */
/*JFACE*/ int c_freopen_3(int nargs) { return c_freopen(nargs); }


function(c_fdopen,2,2,1,1)
{
    int f;
    char mode[21];
    FILE *fd;

    popstring(mode, sizeof(mode));
    popint(&f);

    if((fd = fdopen(f, mode)))
	cfgl_retfd(fd);
    else
    {
	cfgl_errno = errno;
	retquote("");
    }

    return 1;

}   /* c_fdopen */
/*JFACE*/ int c_fdopen_2(int nargs) { return c_fdopen(nargs); }


function(c_popen,2,2,1,1)
{
    cfgl_Path path;
    char mode[21];
    FILE *fd;

    popstring(mode, sizeof(mode));
    popstring(path, sizeof(path));

    if((fd = popen(path, mode)))
	cfgl_retfd(fd);
    else
    {
	retquote("");
	cfgl_errno = errno;
    }

    return 1;

}   /* c_popen */
/*JFACE*/ int c_popen_2(int nargs) { return c_popen(nargs); }


function(c_fclose,1,1,1,1)
{
    FILE *fd;
    int status;

    cfgl_popfd(&fd);
    if(! fd)
	status = EOF;
    else
    {
	status = fclose(fd);
	if(status == EOF)
	    cfgl_errno = errno;
	cfgl_unsetfd(fd);
    }

    retint(status);
    return 1;

}   /* c_fclose */
/*JFACE*/ int c_fclose_1(int nargs) { return c_fclose(nargs); }


function(c_pclose,1,1,1,1)
{
    FILE *fd;
    int status;

    cfgl_popfd(&fd);
    if(! fd)
	status = -1;
    else
    {
	status = pclose(fd);
	if(status == -1)
	    cfgl_errno = errno;
	cfgl_unsetfd(fd);
    }

    retint(status);
    return 1;

}   /* c_pclose */
/*JFACE*/ int c_pclose_1(int nargs) { return c_pclose(nargs); }


function(c_fflush,0,1,1,1)
{
    FILE *fd;
    int status;

    if(nargs > 1)
	cfgl_fatal("usage: c_fflush([FILE *fd]) returning integer\n");

    if(nargs == 1)
	cfgl_popfd(&fd);
    else
	fd = NULL;

    status = fflush(fd);
    if(status == EOF)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_fflush */
/*JFACE*/ int c_fflush_0(int nargs) { return c_fflush(nargs); }
/*JFACE*/ int c_fflush_1(int nargs) { return c_fflush(nargs); }


function(c_ferror,1,1,1,1)
{
    FILE *fd;

    cfgl_popfd(&fd);
    if(! fd)
	retquote("");
    else
	retint(ferror(fd));

    return 1;

}   /* c_ferror */
/*JFACE*/ int c_ferror_1(int nargs) { return c_ferror(nargs); }


function(c_feof,1,1,1,1)
{
    FILE *fd;

    cfgl_popfd(&fd);
    if(! fd)
	retquote("");
    else
	retint(feof(fd));

    return 1;

}   /* c_feof */
/*JFACE*/ int c_feof_1(int nargs) { return c_feof(nargs); }


function(c_clearerr,1,1,1,0)
{
    FILE *fd;

    cfgl_popfd(&fd);
    if(! fd)
	retquote("");
    else
	clearerr(fd);

    return 0;

}   /* c_clearerr */
/*JFACE*/ int c_clearerr_1(int nargs) { return c_clearerr(nargs); }


function(c_fileno,1,1,1,1)
{
    FILE *fd;

    cfgl_popfd(&fd);
    if(! fd)
	retquote("");
    else
	retint(fileno(fd));

    return 1;

}   /* fileno */
/*JFACE*/ int c_fileno_1(int nargs) { return c_fileno(nargs); }


function(c_fgetpos,1,1,1,1)
{
#if defined(__linux)
    cfgl_fatal("fsetpos has been butchered on Linux\n");
    retquote("");
#else
    FILE *fd;
    fpos_t pos;

    cfgl_popfd(&fd);
    if(! fd)
	retquote("");
    else if(fgetpos(fd, &pos) == 0)
	retlong(pos);
    else
	retquote("");
#endif

    return 1;

}   /* c_fgetpos */
/*JFACE*/ int c_fgetpos_1(int nargs) { return c_fgetpos(nargs); }


function(c_fsetpos,2,2,1,1)
{
#if defined(__linux)
    cfgl_fatal("fsetpos has been butchered on Linux\n");
    retquote("");
#else
    FILE *fd;
    fpos_t pos;

# if defined(_HPUX_SOURCE)
    long l;

    poplong(&l);
    pos = l;
# else
    popint(&pos);
# endif
    cfgl_popfd(&fd);
    if(! fd)
	retquote("");
    else
	retint(fsetpos(fd, &pos));
#endif
    return 1;

}   /* c_fsetpos */
/*JFACE*/ int c_fsetpos_2(int nargs) { return c_fsetpos(nargs); }


function(c_setvbuf,3,3,1,1)
{
    FILE *fd;
    int size, type;
    char buf[2];

    popstring(buf, sizeof(buf));
    popint(&size);
    if(risnull(CINTTYPE, (char *) &size))
	size = BUFSIZ;

    cfgl_popfd(&fd);

    type = _IONBF;
    switch(*buf)
    {
    case 'B': type = _IOFBF; break;
    case 'L': type = _IOLBF; break;
    case 'N':
    case 'U': type = _IONBF; break;
    }

    if(! fd)
	retquote("");
    else
	retint(setvbuf(fd, NULL, type, size));

    return 1;

}   /* c_setvbuf */
/*JFACE*/ int c_setvbuf_3(int nargs) { return c_setvbuf(nargs); }


function(c_putc,2,2,1,1)
{
    char c[2];
    FILE *fd;
    int status;

    cfgl_popfd(&fd);
    popquote(c, sizeof(c));

    if(! fd)
        retquote("");
    else
    {
	status = putc(*c, fd);
	if(status != EOF)
	{
	    c[0] = status;
	    c[1] = 0;
	}
	else
	{
	    c[0] = 0;
	    cfgl_errno = errno;
	}

	retquote(c);
    }

    return 1;

}   /* c_putc */
/*JFACE*/ int c_putc_2(int nargs) { return c_putc(nargs); }


function(c_getc,1,1,1,1)
{
    char c[2];
    FILE *fd;
    int status;

    cfgl_popfd(&fd);
    if(! fd)
	retquote("");
    else
    {
	status = getc(fd);

	if(status != EOF)
	{
	    c[0] = status;
	    c[1] = 0;
	}
	else
	{
	    c[0] = 0;
	    cfgl_errno = errno;
	}

	retquote(c);
    }

    return 1;

}   /* c_getc */
/*JFACE*/ int c_getc_1(int nargs) { return c_getc(nargs); }


function(c_fgetln,1,1,1,2)
{
    FILE *fd;
    int n, ch;
    cfgl_IOBuf buf;

    cfgl_popfd(&fd);
    if(! fd)
    {
	n = -1;
	buf[0] = 0;
    }
    else
    {
	n = 0;
	while((ch = getc(fd)) != EOF)
	{
	    if(ch == '\n')
		break;
	    if(n <= CFGL_IOBUF)
		buf[n++] = ch;
	}

	if(n == 0 && feof(fd))
	{
	    rsetnull(CINTTYPE, (char *) &n);
	    buf[0] = 0;
	}
	else
	{
	    buf[n] = 0;
	    if(ferror(fd))
		cfgl_errno = errno;
	}
    }

    retint(n);
    retquote(buf);
    return 2;

}   /* c_fgetln */
/*JFACE*/ int c_fgetln_1(int nargs) { return c_fgetln(nargs); }


function(c_fputln,3,3,1,1)
{
    FILE *fd;
    int len, n;
    cfgl_IOBuf buf;

    popquote(buf, sizeof(buf));
    popint(&len);
    cfgl_popfd(&fd);

    if(! fd)
    {
	retquote("");
	return 1;
    }

    if(len == 0) len = cfgl_trim(buf);
    if(len > CFGL_IOBUF) len = CFGL_IOBUF;

    n = 0;
    while(n < len && ! ferror(fd))
    {
        putc(buf[n], fd);
	if(ferror(fd)) break;
	++n;
    }

    if(! ferror(fd))
    {
	putc('\n', fd);
	if(! ferror(fd)) ++n;
    }

    if(ferror(fd))
	cfgl_errno = errno;

    retint(n);
    return 1;

}   /* c_fputln */
/*JFACE*/ int c_fputln_3(int nargs) { return c_fputln(nargs); }


function(c_fseek,3,3,1,1)
{
    FILE *fd;
    long offset;
    int whence;
    int status;

    popint(&whence);
    poplong(&offset);
    cfgl_popfd(&fd);
    if(! fd)
        retquote("");
    else
    {
	status = fseek(fd, offset, whence);
	if(status == -1)
	    cfgl_errno = errno;

	retint(status);
    }

    return 1;

}   /* c_fseek */
/*JFACE*/ int c_fseek_3(int nargs) { return c_fseek(nargs); }


function(c_rewind,1,1,1,1)
{
    FILE *fd;

    cfgl_popfd(&fd);
    if(! fd)
	retquote("");
    else
    {
	errno = 0;
	rewind(fd);
	retint(errno ? -1 : 0);
	if(errno)
	    cfgl_errno = errno;
    }

    return 1;

}   /* c_rewind */
/*JFACE*/ int c_rewind_1(int nargs) { return c_rewind(nargs); }


function(c_ftell,1,1,1,1)
{
    FILE *fd;
    long pos;

    cfgl_popfd(&fd);
    if(! fd)
	retquote("");
    else
    {
	pos = ftell(fd);
	if(pos == -1)
	    cfgl_errno = errno;

	retlong(pos);
    }

    return 1;

}   /* c_ftell */
/*JFACE*/ int c_ftell_1(int nargs) { return c_ftell(nargs); }
