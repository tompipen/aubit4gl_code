/*
	CSHLC.c  -  OS related routines

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

#ifndef popquote
#define popquote popvchar	/* since this is what we actually need */
#endif

#include <stdio.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>

char *fgw_popquote();

struct passwd *getpwuid();
extern int status;

/*
**  returns the current process id
*/
get_process(nargs)
int nargs;
{
    retlong(getpid());
    return(1);
}

/*
**  returns the current user id
*/
get_login(nargs)
int nargs;
{
    struct passwd *p;

    p=getpwuid(getuid());
    if (p == NULL)
	retquote("");
    else
	retquote(p->pw_name);
    return(1);
}

/*
**  executes an external program without refreshing the screen
*/
shell(nargs)
int nargs;
{
    char *c;
    int i;

    c=fgw_popquote();
    freopen("/dev/null", "a+", stderr);
    i=system(c);
    if ((i&255)==0)
	i=i>>8;
    else
	status=i;
    freopen(ctermid(NULL), "a+", stderr);
    retint(i);
    free(c);
    return(1);
}

/*
**  true if the argument is an executable file
*/
executable(nargs)
int nargs;
{
    char *f;

    f=fgw_popquote();
    retint(!access(f, X_OK));
    free(f);
    return(1);
}
