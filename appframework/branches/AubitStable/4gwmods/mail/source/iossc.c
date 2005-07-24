/*
	IOSSC.c  -  gather various mail related strings from the OS

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

#include <netdb.h>
#include <pwd.h>
#include <string.h>
#include <time.h>

struct passwd *getpwuid();

/*
**  returns the current user mail address
*/
mil_senderid(nargs)
int nargs;
{
    struct passwd *pwrec;
    struct hostent *hostrec;
    char hostname[80];
    char fulluserid[80];

    pwrec=getpwuid(getuid());
    gethostname(hostname, sizeof(hostname)-1);
    hostrec=gethostbyname(hostname);
    fulluserid[0]=0;
/*
** I should probably use strncat and keep track of the space left
** in fulluserid...
*/
    if (pwrec!=NULL && (hostrec!=NULL || strlen(hostname)))
    {
	if (strlen(pwrec->pw_gecos))
	{
	    strcpy(fulluserid, "\"");
	    strcat(fulluserid, pwrec->pw_gecos);
	    strcat(fulluserid, "\" <");
	}
	strcat(fulluserid, pwrec->pw_name);
	strcat(fulluserid, "@");
	if (hostrec!=NULL)
	   strcat(fulluserid, hostrec->h_name);
	else
	   strcat(fulluserid, hostname);
	if (strlen(pwrec->pw_gecos))
	    strcat(fulluserid, ">");
    }
    retquote(fulluserid);
    return(1);
}
/*
** returns a string containg the current time, unix format
*/
mil_unixtime(nargs)
int nargs;
{
    char s[80];
    time_t t;

    popint(&t);
    strcpy(s, ctime(&t));
    s[strlen(s)-1]=0;
    retquote(s);
    return(1);
}
/*
** returns a string containg the current time, RFC 822 (well, almost) format
*/
mil_rfctime(nargs)
int nargs;
{
    char s[80];
    time_t t;

    popint(&t);
    strftime(s, sizeof(s)-1, "%a, %d %b %Y %H:%M:%S %Z", localtime(&t));
/*  cftime(s, "%a, %d %b %Y %H:%M:%S %Z", &t);
*/  retquote(s);
    return(1);
}
