/*
@(#)File:           $RCSfile: opendb.ec,v $
@(#)Version:        $Revision: 1.1.1.1 $
@(#)Last changed:   $Date: 2002-06-15 05:07:13 $
@(#)Purpose:        Open database reliably
@(#)Author:         J Leffler
*/

$include sqlca;
#include <stdio.h>

int opendb(dbase)
$char *dbase;
{
$	int	tabid;

$	CLOSE DATABASE;		/* Might be one open */
	sqlca.sqlcode = 0;

$	DATABASE $dbase;
	if (sqlca.sqlcode != 0)
		return(sqlca.sqlcode);

	/* There is a bug in ESQL/C which means that the database open */
	/* can fail, but sqlca.sqlcode does not report the trouble, so */
	/* this check ensures that the database really is open. JL     */
$	SELECT Tabid INTO $tabid FROM Systables WHERE Systables.Tabid = 1;
	return(sqlca.sqlcode);
}

int	closedb()
{
$	CLOSE DATABASE;
	return(sqlca.sqlcode);
}
