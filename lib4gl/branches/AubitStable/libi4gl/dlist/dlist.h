/*
	@(#)$Id: dlist.h,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Header file for D-list handling
*/
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
extern	int		 rm_key(/* index */);
extern	int		 ins_key(/* int, int, int */);
extern	int		 upd_key(/* int, int, int */);
extern	int		 del_key(/* index */);
extern	char	*get_key(/* int, int, int */);
extern	int		 zap_key(/* index */);
extern	int		 cnt_key(/* index */);
extern	int		 num_key(/* index */);

extern	int		 sc_error;
