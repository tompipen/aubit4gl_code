/*
@(#)File:            $RCSfile: clrerrln.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2002-06-14 09:23:16 $
@(#)Purpose:         Clear the error line
@(#)Author:          J Leffler
*/

extern	void	clrmsg();

#ifndef lint
static	char	sccs[] = "@(#)$Id: clrerrln.c,v 1.2 2002-06-14 09:23:16 afalout Exp $";
#endif

/* -- Routine: clear_error_line		*/
/* -- I4GL: CALL clear_error_line() */

/*ARGSUSED*/
int	clear_error_line(i)
int	i;
{
	clrmsg();
	return(0);
}
