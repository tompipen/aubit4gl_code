/*******************************************************************************
 SCCS ID : @(#) Mod: key_press.c Ver: 1.2 Date: 08/13/99 17:01:14
*******************************************************************************/
#include <stdio.h>
#include <fcntl.h>
//#include <curses.h>
//#include <term.h>

int current_flags;

aclfgl_init_term(noargs)
{
	current_flags = fcntl(0, F_GETFL, 0);
	fcntl(0, F_SETFL, current_flags | O_NDELAY);
	//cursor_invisible=1;
	return 0;
}

aclfgl_key_press(noargs)
{
char c;

	if (read(0, &c, 1) > 0)  pushint(c);
	else			 pushint(0);
	return(1);
}

aclfgl_end_term(noargs)
{
	fcntl(0, F_SETFL, current_flags);
	return(0);
}
