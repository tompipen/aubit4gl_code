/*
	@@(#)$Id: dlist.h,v 1.1 2002-06-14 05:03:45 afalout Exp $
	@@(#)Header file for D-list handling
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
