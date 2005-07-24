
# include	"cfun4gl.h"
# include	<pwd.h>
# if defined(__linux)
#  define	_XOPEN_SOURCE
#  include	<unistd.h>
# endif

# define	MAX_KEY		100
# define	MAX_SALT	15
# define	MAX_NAME	8

# if defined(__linux)
char *crypt(char *, char *);
# endif

function(c_crypt,2,2,1,1)
{
    char key[MAX_KEY + 1];
    char salt[MAX_SALT + 1];

    if(nargs != 2)
	cfgl_fatal("usage: c_crypt(key, salt char(*))) returning char(*)\n");

    popstring(salt, sizeof(salt));
    popstring(key,  sizeof(key));

    retquote(crypt(key, salt));
    return 1;

}   /* c_crypt */
/*JFACE*/ int c_crypt_2(int nargs) { return c_crypt(nargs); }


static int shove_pwent(struct passwd *pw)
{
    if(! pw)
    {
	int i;

	for(i = 0; i < 9; ++i)
	    retquote("");
    }
    else
    {
	retquote(pw->pw_name);
	retquote(pw->pw_passwd);
	retint(pw->pw_uid);
	retint(pw->pw_gid);
# if defined(__alpha) || defined(__linux)
	retquote("");
# else
	retquote(pw->pw_age);
# endif
# if defined(__linux)
	retquote("");
# else
	retquote(pw->pw_comment);
# endif
	retquote(pw->pw_gecos);
	retquote(pw->pw_dir);
	retquote(pw->pw_shell);
    }

    return 9;

}   /* shove_pwent */


function(c_setpwent,0,0,1,0)
{
    if(nargs != 0)
	cfgl_fatal("usage: c_setpwent()\n");

    setpwent();
    return 0;

}   /* c_setpwent */
/*JFACE*/ int c_setpwent_0(int nargs) { return c_setpwent(nargs); }


function(c_endpwent,0,0,1,0)
{
    if(nargs != 0)
	cfgl_fatal("usage: c_endpwent()\n");

    endpwent();
    return 0;

}   /* c_endpwent */
/*JFACE*/ int c_endpwent_0(int nargs) { return c_endpwent(nargs); }


function(c_getpwent,0,0,1,9)
{
    if(nargs != 0)
	cfgl_fatal("usage: c_getpwent()"
		   " returning string, string, int, int,"
		   " string, string, string, string, string"
		   "\n");

    return shove_pwent(getpwent());

}   /* c_getpwent */
/*JFACE*/ int c_getpwent_0(int nargs) { return c_getpwent(nargs); }


function(c_getpwuid,1,1,1,9)
{
    int uid;

    if(nargs != 1)
	cfgl_fatal("usage: c_getpwuid(int)"
		   " returning string, string, int, int,"
		   " string, string, string, string, string"
		   "\n");

    popint(&uid);
    return shove_pwent(getpwuid(uid));

}   /* c_getpwuid */
/*JFACE*/ int c_getpwuid_1(int nargs) { return c_getpwuid(nargs); }


function(c_getpwnam,1,1,1,9)
{
    char name[MAX_NAME + 1];

    if(nargs != 1)
	cfgl_fatal("usage: c_getpwnam(char (8))"
		   " returning string, string, int, int,"
		   " string, string, string, string, string"
		   "\n");

    popstring(name, sizeof(name));

    return shove_pwent(getpwnam(name));

}   /* c_getpwnam */
/*JFACE*/ int c_getpwnam_1(int nargs) { return c_getpwnam(nargs); }
