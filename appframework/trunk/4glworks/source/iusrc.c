/*
	IUSRC.c  -  Consolle IO routines

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
#include <stdio.h>
#include <signal.h>

extern int efcode;
extern int status;
extern short eflastkey;
extern short _acckey;
extern short _inskey;
extern short _delkey;
extern short _nxtkey;
extern short _prvkey;
extern short _hlpkey;

static int fgw_alarmon = 0;
static int fgw_inalarm = 0;

/*
**  tests for "missing help message" error
*/
usr_testhelp(nargs)
int nargs;
{
    int r;

    r=(efcode==0);
    efcode=0;
    retint(r);
    return(1);
}

/*
**  gets next key hit from keyboard
*/
readkey(nargs)
int nargs;
{
    char c[2];

    eflastkey=rgetkey();
    c[0]=0;
    c[1]=0;
    if (eflastkey==_acckey) 
	eflastkey=2016;
    else if (eflastkey==_inskey) 
	eflastkey=2014;
    else if (eflastkey==_delkey) 
	eflastkey=2015;
    else if (eflastkey==_nxtkey) 
	eflastkey=2005;
    else if (eflastkey==_prvkey) 
	eflastkey=2006;
    else if (eflastkey==_hlpkey) 
	eflastkey=2008;
    else if (eflastkey<128)
	c[0]=eflastkey;
    if (fgw_inalarm)
    {
	alarm(0);
	fgw_inalarm=0;
    }
    if (!fgw_alarmon) clrmsg();
    retquote(c);
    return(1);
}

/*
**  gets next char from kbd (needed because prompt starts from
**  screen top)
*/
readchar(nargs)
int nargs;
{
    char c[2];
 
    c[0]=rgetkey();
    if (c[0]&128)
	c[0]=0;
    c[1]=0;
    retquote(c);
    return(1);
}

/*
** SIGALRM handler
*/
fgw_timeout()
{
    fgw_alarmon=1;
    kill(getpid(), SIGINT);
}

/*
** Initiates SIGNAL ALARM For Interval Seconds
*/
tim_setalarm(nargs)
int nargs;
{
    int s;

    popint(&s);
    s=s-time(NULL);
    if (s<0) return(0);
    else if (s==0)
    {
	fgw_inalarm=0;
	alarm(0);
	return(0);
    }
    if (status=(((int) signal(SIGALRM, (void(*)(int)) fgw_timeout))==-1))
	return(0);
    alarm(s);
    fgw_inalarm=1;
    return(0);
}

/*
**  returns and resets alarm state
*/
tim_alarmstate(nargs)
int nargs;
{
    retint(fgw_alarmon);
    fgw_alarmon=0;
    return(1);
}

get_time(nargs)
int nargs;
{
    retint(time(NULL));
    return(1);
}
