
# include	"cfun4gl.h"
# include	<sys/stat.h>


function(c_mkdir,1,2,1,1)
{
    int i;
    int mode = 0;
    cfgl_Path buf;
    cfgl_FMode fmode;

    if(nargs != 1 && nargs != 2)
	cfgl_fatal("usage: c_mkdir(path [, mode] char(*))"
			 " returning integer\n");

    if(nargs == 1)
	mode = 0777;
    else
    {
	/* get create mode argument */
	popstring(fmode, sizeof(fmode));
	mode = cfgl_interpMode(fmode);

    }

    /* get path argument */
    popstring(buf, sizeof(buf));

    if(! *buf)
    {
	i = -1;
	cfgl_errno = ENOENT;
    }
    else
    {
	i = mkdir(buf, mode);
	if(i < 0)
	    cfgl_errno = errno;
    }

    retint(i);
    return 1;

}   /* c_mkdir */
/*JFACE*/ int c_mkdir_1(int nargs) { return c_mkdir(nargs); }
/*JFACE*/ int c_mkdir_2(int nargs) { return c_mkdir(nargs); }


function(c_chdir,1,1,1,1)
{
    cfgl_Path path;
    int i;

    if(nargs != 1)
	cfgl_fatal("usage: c_chdir(path char(*)) returning integer\n");

    popstring(path, sizeof(path));
    if(! *path)
    {
	i = -1;
	cfgl_errno = ENOENT;
    }
    else
    {
	i = chdir(path);
	if(i < 0)
	    cfgl_errno = errno;
    }

    retint(i);
    return 1;

}   /* c_chdir */
/*JFACE*/ int c_chdir_1(int nargs) { return c_chdir(nargs); }


function(c_unlink,1,1,1,1)
{
    cfgl_Path path;
    int i;

    if(nargs != 1)
	cfgl_fatal("usage: c_unlink(path char(*)) returning integer\n");

    popstring(path, sizeof(path));
    if(! *path)
    {
	i = -1;
	cfgl_errno = ENOENT;
    }
    else
    {
	i = unlink(path);
	if(i < 0)
	    cfgl_errno = errno;
    }

    retint(i);
    return 1;

}   /* c_unlink */
/*JFACE*/ int c_unlink_1(int nargs) { return c_unlink(nargs); }


function(c_rmdir,1,1,1,1)
{
    cfgl_Path path;
    int i;

    if(nargs != 1)
	cfgl_fatal("usage: c_rmdir(path char(*)) returning integer\n");

    popstring(path, sizeof(path));
    if(! *path)
    {
	i = -1;
	cfgl_errno = ENOENT;
    }
    else
    {
	i = rmdir(path);
	if(i < 0)
	    cfgl_errno = errno;
    }

    retint(i);
    return 1;

}   /* c_rmdir */
/*JFACE*/ int c_rmdir_1(int nargs) { return c_rmdir(nargs); }


function(c_rename,2,2,1,1)
{
    cfgl_Path source, target;
    int status;

    if(nargs != 2)
	cfgl_fatal("usage: c_rename(source, target char(*))"
			 " returning integer\n");

    popstring(target, sizeof(target));
    popstring(source, sizeof(source));

    status = rename(source, target);
    if(status == -1)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_rename */
/*JFACE*/ int c_rename_2(int nargs) { return c_rename(nargs); }


function(c_link,2,2,1,1)
{
    cfgl_Path path1, path2;
    int status;

    if(nargs != 2)
        cfgl_fatal("usage: c_link(path1, path2 char(*))"
			 " returning integer\n");

    popstring(path2, sizeof(path2));
    popstring(path1, sizeof(path1));

    status = link(path1, path2);
    if(status == -1)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_link */
/*JFACE*/ int c_link_2(int nargs) { return c_link(nargs); }


function(c_symlink,2,2,1,1)
{
    cfgl_Path path1, path2;
    int status;

    if(nargs != 2)
        cfgl_fatal("usage: c_symlink(path1, path2 char(*))"
			 " returning integer\n");

    popstring(path2, sizeof(path2));
    popstring(path1, sizeof(path1));

    status = symlink(path1, path2);
    if(status == -1)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_symlink */
/*JFACE*/ int c_symlink_2(int nargs) { return c_symlink(nargs); }


function(c_readlink,1,1,1,1)
{
    cfgl_Path path, buf;
    int status;

    if(nargs != 1)
	cfgl_fatal("usage: c_readlink(path char(*)) returning char(*))\n");

    popstring(path, sizeof(path));

    status = readlink(path, buf, sizeof(buf));
    if(status == -1)
    {
	cfgl_errno = errno;
	buf[0] = 0;
    }
    else
	buf[status] = 0;

    retquote(buf);
    return 1;

}   /* c_readlink */
/*JFACE*/ int c_readlink_1(int nargs) { return c_readlink(nargs); }


function(c_chown,3,3,1,1)
{
    cfgl_Path path;
    int uid, gid;
    int status;

    if(nargs != 3)
	cfgl_fatal("usage: c_chown(path char(*), uid, gid integer)"
			 " returning integer\n");

    popint(&gid);
    popint(&uid);
    popstring(path, sizeof(path));

    if(risnull(CINTTYPE, (char *) &uid)) uid = -1;
    if(risnull(CINTTYPE, (char *) &gid)) gid = -1;

    status = chown(path, uid, gid);
    if(status == -1)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_chown */
/*JFACE*/ int c_chown_3(int nargs) { return c_chown(nargs); }


function(c_lchown,3,3,1,1)
{
    cfgl_Path path;
    int uid, gid;
    int status;

    if(nargs != 3)
	cfgl_fatal("usage: c_lchown(path char(*), uid, gid integer)"
			 " returning integer\n");

    popint(&gid);
    popint(&uid);
    popstring(path, sizeof(path));

    if(risnull(CINTTYPE, (char *) &uid)) uid = -1;
    if(risnull(CINTTYPE, (char *) &gid)) gid = -1;

    status = lchown(path, uid, gid);
    if(status == -1)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_lchown */
/*JFACE*/ int c_lchown_3(int nargs) { return c_lchown(nargs); }


function(c_fchown,3,3,1,1)
{
    int fd, uid, gid;
    int status;

    if(nargs != 3)
	cfgl_fatal("usage: c_fchown(fd, uid, gid integer)"
			 " returning integer\n");

    popint(&gid);
    popint(&uid);
    popint(&fd);

    if(risnull(CINTTYPE, (char *) &uid)) uid = -1;
    if(risnull(CINTTYPE, (char *) &gid)) gid = -1;

    status = fchown(fd, uid, gid);
    if(status == -1)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_fchown */
/*JFACE*/ int c_fchown_3(int nargs) { return c_fchown(nargs); }


function(c_chroot,1,1,1,1)
{
    cfgl_Path path;
    int status;

    if(nargs != 1)
	cfgl_fatal("usage: c_chroot(path char(*)) returning integer\n");

    popstring(path, sizeof(path));

    status = chroot(path);
    if(status == -1)
	cfgl_errno = errno;

    retint(status);
    return 1;

}   /* c_chroot */
/*JFACE*/ int c_chroot_1(int nargs) { return c_chroot(nargs); }


# define STAT_RETURNS " returning (st_mode, st_uid, st_gid," \
				 " st_size, st_atime, st_mtime) integer"

static int stat_status;
static int stat_errno;
static struct stat stat_extra;

/* in the unlikely event you actually want this stuff */
function(c_exstat,0,0,1,4)
{
    if(nargs != 0)
	cfgl_fatal("usage: c_exstat()"
		   "returning (st_ino, st_dev, st_rdev, st_nlink) integer");

    if(stat_status == -1)
    {
	cfgl_errno = stat_errno;	/* and don't you forget it... */

	retquote("");
	retquote("");
	retquote("");
	retquote("");
    }
    else
    {
	retlong(stat_extra.st_ino);
	retlong(stat_extra.st_dev);
	retlong(stat_extra.st_rdev);
	retlong(stat_extra.st_nlink);
    }

    return 4;

}   /* c_exstat */


static int retStat(int status, struct stat *buf)
{
    stat_status = status;
    stat_errno = errno;
    stat_extra = *buf;

    if(status == -1)
    {
	cfgl_errno = errno;
	retquote("");
	retquote("");
	retquote("");
	retquote("");
	retquote("");
	retquote("");
    }
    else
    {
	retlong(buf->st_mode);
	retlong(buf->st_uid);
	retlong(buf->st_gid);
	retlong(buf->st_size);
	retlong(buf->st_atime);
	retlong(buf->st_mtime);
    }

    return 6;

}   /* retStat */


function(c_stat,1,1,1,6)
{
    struct stat buf;
    cfgl_Path path;
    int status;

    if(nargs != 1)
	cfgl_fatal("usage: c_stat(path char(*))" STAT_RETURNS);

    popquote(path, sizeof(path));
    status = stat(path, &buf);
    return retStat(status, &buf);

}   /* c_stat */


function(c_fstat,1,1,1,6)
{
    struct stat buf;
    int fd;
    int status;

    if(nargs != 1)
	cfgl_fatal("usage: c_fstat(fd smallint)" STAT_RETURNS);

    popint(&fd);
    status = fstat(fd, &buf);
    return retStat(status, &buf);

}   /* c_fstat */


function(c_lstat,1,1,1,6)
{
    struct stat buf;
    cfgl_Path path;
    int status;

    if(nargs != 1)
	cfgl_fatal("usage: c_lstat(path char(*))" STAT_RETURNS);

    popquote(path, sizeof(path));
    status = lstat(path, &buf);
    return retStat(status, &buf);

}   /* c_lstat */


function(c_isfstat,2,2,1,1)
{
    char action[10];
    char *ap = action;
    long fmode;
    long result;

    if(nargs != 2)
	cfgl_fatal("usage: c_isfstat(action char(*), fmode integer)"
			 " returning boolean\n");

    poplong(&fmode);
    popstring(action, sizeof(action));

    /* geeez I'm nice */
    if(! strncmp(ap, "S_", 2))
	ap += 2;

         if(! strcmp(action, "ISBLK"))  result = S_ISBLK(fmode);
    else if(! strcmp(action, "ISCHR"))  result = S_ISCHR(fmode);
    else if(! strcmp(action, "ISDIR"))  result = S_ISDIR(fmode);
    else if(! strcmp(action, "ISFIFO")) result = S_ISFIFO(fmode);
    else if(! strcmp(action, "ISNAM"))  result = S_ISNAM(fmode);
    else if(! strcmp(action, "ISREG"))  result = S_ISREG(fmode);
    else cfgl_fatal("c_isfstat: invalid operation %s\n", action);

    /* convert to 0,1 */
    retint(result != 0);
    return 1;

}   /* c_isfstat */


typedef int accessftn(const char *, int);

static int cfgl_access(int nargs, char *name, accessftn *ftn)
{
    cfgl_Path path;
    cfgl_FMode fmode;
    int amode = F_OK;
    char *mp = fmode;
    int result;

    if(nargs != 1 && nargs != 2)
	cfgl_fatal("usage: %s(path [, mode] char(*))"
			 " returning boolean\n", name);

    if(nargs == 2)
    {
	popquote(fmode, sizeof(fmode));
	     if(! strcmp(fmode, "R_" "OK")) amode = R_OK;
	else if(! strcmp(fmode, "W_" "OK")) amode = W_OK;
	else if(! strcmp(fmode, "X_" "OK")) amode = X_OK;
	else if(! strcmp(fmode, "F_" "OK")) amode = F_OK;
	else amode = cfgl_interpMode(fmode);
    }

    popquote(path, sizeof(path));
    result = (*ftn)(path, amode);

    if(result == -1)
	cfgl_errno = errno;
    retint(result == 0);
    return 1;

}   /* cfgl_access */


function(c_access,1,2,1,1)
{
    return cfgl_access(nargs, "c_access", access);
}   /* c_access */


function(c_eaccess,1,2,1,1)
{
    return cfgl_access(nargs, "c_eaccess", eaccess);
}   /* c_eaccess */


function(c_modestr,1,1,1,1)
{
    int mode;
    cfgl_FMode fmode;

    if(nargs != 1)
	cfgl_fatal("usage: c_modestr(fmode integer) returning char(*)\n");

    strcpy(fmode, "----------");	/* 10 dashes */

    popint(&mode);
    switch(mode & S_IFMT)
    {
    case S_IFREG: fmode[0] = '-';	break;	/* no-op */
    case S_IFLNK: fmode[0] = 'l';	break;
    case S_IFBLK: fmode[0] = 'b';	break;
    case S_IFCHR: fmode[0] = 'c';	break;
    case S_IFDIR: fmode[0] = 'd';	break;
    case S_IFIFO: fmode[0] = 'p';	break;
    case S_IFNAM: fmode[0] = 'n';	/* TODO - CONFIRM!!! SCO only? */

    default:
	cfgl_fatal("c_modestr: unknown file type %o\n", mode & S_IFMT);
    }

    if(mode & S_IRUSR) fmode[1] = 'r';
    if(mode & S_IWUSR) fmode[2] = 'w';
    if(mode & S_IXUSR) fmode[3] = 'x';

    if(mode & S_IRGRP) fmode[4] = 'r';
    if(mode & S_IWGRP) fmode[5] = 'w';
    if(mode & S_IXGRP) fmode[6] = 'x';

    if(mode & S_IROTH) fmode[7] = 'r';
    if(mode & S_IWOTH) fmode[8] = 'w';
    if(mode & S_IXOTH) fmode[9] = 'x';

    /* now the fancy combinations */
    if(mode & S_ISUID) fmode[3] = mode & S_IXUSR ? 's' : 'S';
    if(mode & S_ISGID) fmode[6] = mode & S_IXGRP ? 's' : 'S';
    if(mode & S_ISVTX) fmode[9] = mode & S_IXOTH ? 't' : 'T';

    retquote(fmode);
    return 1;

}   /* c_modestr */
