head	1.4;
access;
symbols;
locks; strict;
comment	@# @;


1.4
date	90.04.05.11.02.00;	author john;	state Exp;
branches;
next	1.3;

1.3
date	89.12.12.11.56.54;	author john;	state Exp;
branches;
next	1.2;

1.2
date	89.08.03.09.31.07;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.11.24.17.43.48;	author john;	state Exp;
branches;
next	;


desc
@@


1.4
log
@Add sccs string
@
text
@{
	@@(#)$Id: centre.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
	@@(#)Centre string in field
	@@(#)Author: JL
}

FUNCTION centre(title, ncols)

    DEFINE
		sccs	CHAR(1),
		title	CHAR(512),
		ncols	INTEGER    { width of field }

    DEFINE
		col     SMALLINT,
		centr	CHAR(512)

    LET col = (ncols - LENGTH(title)) / 2
    IF col > 0 THEN
		LET centr = col SPACES, title CLIPPED
	ELSE
		LET sccs  = "@@(#)$Id: centre.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
		LET centr = title
		LET ncols = LENGTH(title)
	END IF

	RETURN centr[1,ncols] CLIPPED

END FUNCTION {centre}
@


1.3
log
@Clip returned string
@
text
@d11 3
a13 2
		title CHAR(512),
		ncols INTEGER    { width of field }
d23 1
@


1.2
log
@Return string which is truncated/clipped to correct length
@
text
@d26 1
a26 1
	RETURN centr[1,ncols]
@


1.1
log
@Initial revision
@
text
@d11 1
a11 1
		title CHAR(80),
d16 1
a16 1
		centr	CHAR(80)
d23 1
d26 1
a26 1
	RETURN centr
@
