head	1.1;
access;
symbols;
locks; strict;
comment	@ * @;


1.1
date	91.05.17.12.40.57;	author johnl;	state Exp;
branches;
next	;


desc
@@


1.1
log
@Initial revision
@
text
@/*
@@(#)File:            $RCSfile: clrerrln.c,v $
@@(#)Version:         $Revision: 1.1 $
@@(#)Last changed:    $Date: 2002-06-14 05:03:46 $
@@(#)Purpose:         Clear the error line
@@(#)Author:          J Leffler
*/

extern	void	clrmsg();

#ifndef lint
static	char	sccs[] = "@@(#)$Id: clrerrln.c,v 1.1 2002-06-14 05:03:46 afalout Exp $";
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
@
