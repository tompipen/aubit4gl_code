
/*
 * This file contains the C function c_statfile() which is designed
 * to be called from an Informix 4GL program. It accepts a path name
 * as its only argument and returns the size of the file, the
 * last modification time as an integer and the file permissions
 * as a 3 character string in symbolic format. These permissions
 * are based on what permissions set for the given pathname/file in
 * relation to the user (userid) that is calling the function.
 *
 * symbolic file permissions example: rwx
 *
 * usage: call c_statfile(path_name) 
 *             returning file_size, mod_time, perm_str
 *
 *
 *
 * The C function c_filemode() is also included in this file. It
 * is called with a path name as its only argument, and returns
 * the owner, group, and octal permissions string for the file.
 *
 * usage: call c_filemode(path_name)
 *             returning file_owner, file_group, file_perms
 *
 * An example of return values: "seanb" "informix" "0444"
 */


# include	"cfun4gl.h"
# include	<sys/types.h>
# include	<sys/stat.h>

/* password and group structure definitions */
# include	<pwd.h>
# include	<grp.h>


function(c_statfile,1,1,1,3)
{
    struct stat st;
    cfgl_Path filename;
    char prm_str[4];

    /* get file name argument */
    popstring(filename, sizeof(filename));

    /* set the initial permission string */
    strcpy(prm_str, "---");

    /* call stat() to get file statistics */
    if (stat(filename, &st) == -1)
    {
        st.st_size = 0;
        st.st_mtime = 0;
    }
    else
    {
	/* call access() to get the "rwx" permission string */
        if (access(filename, 04) == 0) prm_str[0] = 'r';
        if (access(filename, 02) == 0) prm_str[1] = 'w';
        if (access(filename, 01) == 0) prm_str[2] = 'x';
    }

    /* return size, mtime, and permissions */
    retint((int) st.st_size);
    retint((int) st.st_mtime);
    retquote(prm_str);
    return 3;

}   /* c_statfile */
/*JFACE*/ int c_statfile_1(int nargs) { return c_statfile(nargs); }


function(c_filemode,1,1,1,3)
{
    struct stat st;
    struct passwd *pwent;
    struct group *grent;
    cfgl_Path filename;
    char file_perms[4];
    char file_group[15];
    char file_owner[15];

    popstring(filename, sizeof(filename));

    if (stat(filename,&st) == -1)	/* get file statistics */
    {
        *file_owner = 0;
        *file_group = 0;
        *file_perms = 0;
    }
    else
    {
        sprintf(file_perms, "%o", (st.st_mode & 0x01FF));
        if((pwent = getpwuid(st.st_uid)))
            strcpy(file_owner, pwent->pw_name);
        else
            *file_owner = 0;

        if((grent = getgrgid(st.st_gid)))
            strcpy(file_group, grent->gr_name);
        else
            *file_group = 0;
    }        

    retquote(file_owner);
    retquote(file_group);
    retquote(file_perms);

    return 3;

}   /* c_filemode */
/*JFACE*/ int c_filemode_1(int nargs) { return c_filemode(nargs); }
