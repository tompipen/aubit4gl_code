head	1.3;
access;
symbols;
locks; strict;
comment	@# @;


1.3
date	91.05.09.17.42.25;	author johnl;	state Exp;
branches;
next	1.2;

1.2
date	90.11.22.11.10.17;	author johnl;	state Exp;
branches;
next	1.1;

1.1
date	90.11.19.12.47.44;	author johnl;	state Exp;
branches;
next	;


desc
@@


1.3
log
@Upgrade heading
@
text
@-- @@(#)$Id: dispcntr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
-- @@(#)JLSS Informix Tools: General Library
-- @@(#)Display n out of m counter
-- @@(#)Author: J Leffler

FUNCTION display_counter(row_num, num_rows)

	DEFINE
		row_num		INTEGER,
		num_rows	INTEGER,
		dis_str		CHAR(13),
		sccs		CHAR(1)

	IF num_rows > 0 THEN
		LET dis_str = "--", row_num USING "&&&&", "/",
							num_rows USING "&&&&", "--"
	ELSE
		LET dis_str = " "
		LET sccs = "@@(#)$Id: dispcntr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
	END IF

	DISPLAY dis_str AT 1, 64

END FUNCTION {display_counter}
@


1.2
log
@Invert actions
@
text
@d1 4
a4 4
{
	@@(#)$Id: dispcntr.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)Display n out of m counter
}
d11 2
a12 1
		dis_str		CHAR(13)
d19 1
d22 1
a22 1
	DISPLAY dis_str AT 1, 65
@


1.1
log
@Initial revision
@
text
@a13 2
		LET dis_str = " "
	ELSE
d16 2
@
