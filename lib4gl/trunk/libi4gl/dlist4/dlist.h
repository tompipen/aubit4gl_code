head	4.1;
access;
symbols;
locks; strict;
comment	@ * @;


4.1
date	91.11.17.22.15.31;	author jl;	state Exp;
branches;
next	3.3;

3.3
date	89.06.28.18.51.00;	author john;	state Exp;
branches;
next	3.2;

3.2
date	89.06.28.18.50.52;	author john;	state Exp;
branches;
next	3.1;

3.1
date	88.10.13.16.17.54;	author john;	state Exp;
branches;
next	2.4;

2.4
date	88.09.25.20.09.02;	author john;	state Exp;
branches;
next	2.1;

2.1
date	88.06.22.09.21.10;	author john;	state Exp;
branches;
next	1.3;

1.3
date	88.06.16.17.16.17;	author john;	state Exp;
branches;
next	1.2;

1.2
date	88.06.16.15.49.19;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.06.16.12.10.15;	author john;	state Exp;
branches;
next	;


desc
@@


4.1
log
@Un-generalise: now D-Lists store integers (long) only
@
text
@/*
@@(#)	File:			$RCSfile: dlist.h,v $
@@(#)	Version:		$Revision: 1.1 $
@@(#)	Last changed:	$Date: 2002-06-14 05:03:45 $
@@(#)	Purpose:		Header file for D-list handling
@@(#)	Author:			J Leffler
*/

/*TABSTOP=4*/

#ifndef DLIST_H
#define DLIST_H

#define SC_CURRENT	'C'
#define SC_NEXT		'N'
#define SC_PREVIOUS	'P'
#define SC_FIRST	'F'
#define SC_LAST		'L'
#define	SC_RELATIVE	'R'
#define SC_ABSOLUTE	'A'

#define ENOERROR	0
#define ENOLIST		-1
#define EINVARG		-2
#define ENOMEM		-3

#define NIL(x)	((x)0)

extern	int		 mk_key(/* void */);
extern	int		 rm_key(/* int */);
extern	int		 ins_key(/* int, int */);
extern	int		 upd_key(/* int, int */);
extern	int		 del_key(/* int */);
extern	int		 get_key(/* int, int, int */);
extern	int		 zap_key(/* int */);
extern	int		 cnt_key(/* int */);
extern	int		 num_key(/* int */);

extern	int		 sc_error;

#endif	/* DLIST_H */
@


3.3
log
@No change -- just making release numbers uniform
@
text
@d2 5
a6 2
	@@(#)$Id: dlist.h,v 1.1 2002-06-14 05:03:45 afalout Exp $
	@@(#)Header file for D-list handling
d8 6
d30 8
a37 8
extern	int		 rm_key(/* index */);
extern	int		 ins_key(/* int, int, int */);
extern	int		 upd_key(/* int, int, int */);
extern	int		 del_key(/* index */);
extern	char	*get_key(/* int, int, int */);
extern	int		 zap_key(/* index */);
extern	int		 cnt_key(/* index */);
extern	int		 num_key(/* index */);
d40 2
@


3.2
log
@No change -- just making release numbers uniform
@
text
@@


3.1
log
@Revise headers; unify discrepant versions
@
text
@@


2.4
log
@Convert to uniform release 2.4
@
text
@@


2.1
log
@Add interface spec.
@
text
@d3 1
a3 1
	@@(#)Header file for double-linked list handling
@


1.3
log
@Spare weight removed
@
text
@d19 12
@


1.2
log
@Amended to define type
@
text
@d3 1
a3 1
	@@(#)Header file for Dlist handling
a18 18

#define CHARTYPE
typedef	char	keytype[2];
typedef	char	*keyret;

extern	void	del_key(/* void */);
extern	void	ins_key(/* int */);
extern	void	upd_key(/* int */);
extern	void	del_all(/* void */);
extern	keyret	get_key(/* int, int */);
extern	int		cnt_key(/* void */);
extern	int		key_num(/* void */);

extern	int		sc_error;

#if defined(DECTYPE)
#include <decimal.h>
#endif
@


1.1
log
@Initial revision
@
text
@d20 4
d28 1
a28 1
extern	int		get_key(/* int, int */);
d33 4
@
