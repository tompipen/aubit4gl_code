head	1.1;
access;
symbols;
locks; strict;
comment	@# @;


1.1
date	88.09.23.16.39.31;	author john;	state Exp;
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
@@(#)	File:			$RCSfile: nextfld.ec,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:46 $
@@(#)	Purpose:		Set variable NEXT FIELD
@@(#)	Author:			J Leffler
*/

#define EF_V_NEXT_FIELD
#include <sqlfm.h>

#ifndef lint
static	char	sccs[] = "@@(#)$Id: nextfld.ec,v 1.1 2002-06-14 05:03:46 afalout Exp $";
#endif

/*
	Purpose:	Set next field

	Note: this has an unorthodox interface because there is a 
	#define which tacks the icb variable onto the standard I4GL/C 
	calling convention.
*/

next_v_field(i, icb)
int	i;
_EFICB	*icb;
{
	static	char	s[20];
	if (i == 1)
	{
		popstring(&s[1], sizeof(s)-1);
		s[0] = '.';
		if (strcmp(s, ".") != 0)
			icb->_EFnext = s;
	}
	return(0);
}
@
