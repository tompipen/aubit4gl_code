/*
@(#)File:            $RCSfile: exec.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:16 $
@(#)Purpose:         Implement exec() for I4GL
@(#)Author:          J Leffler
*/

#define SHELL "/bin/sh"
#define I4GL_C	int

#ifndef lint
static	char	sccs[] = "@(#)$Id: exec.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
#endif

I4GL_C	exec(n)
int	n;
{
	int		 i;
	char	 cmd[512]; /* Largest string passable in I4GL */
	char	*argv[4];

	/* Reset terminal characteristics and close log file */
	_efemode();
	fgl_clog();

	/* If called wrongly, exit immediately */
	if (n != 1)
		exit(1);

	/* Find what is to be executed */
	popstring(cmd, sizeof(cmd));

	/* Close unwanted files (all except stdin, stdout, stderr) */
	for (i = 3; i < 20; i++)
		(void) close(i);

	argv[0] = SHELL;
	argv[1] = "-c";
	argv[2] = cmd;
	argv[3] = (char *)0;

	execv(SHELL, argv);
	exit(1);
}
