/*
@(#)	File:			$RCSfile: dlist.h,v $
@(#)	Version:		$Revision: 1.2 $
@(#)	Last changed:	$Date: 2002-06-14 09:23:16 $
@(#)	Purpose:		Header file for D-list handling
@(#)	Author:			J Leffler
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
