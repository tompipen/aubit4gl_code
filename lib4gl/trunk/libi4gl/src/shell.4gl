head	2.4;
access;
symbols;
locks; strict;
comment	@# @;


2.4
date	98.08.20.20.19.20;	author jleffler;	state Exp;
branches;
next	2.3;

2.3
date	98.08.20.20.17.48;	author jleffler;	state Exp;
branches;
next	2.2;

2.2
date	98.07.09.00.27.06;	author jleffler;	state Exp;
branches;
next	2.1;

2.1
date	98.07.08.18.56.30;	author jleffler;	state Exp;
branches;
next	1.6;

1.6
date	90.08.19.12.45.20;	author john;	state Exp;
branches;
next	1.5;

1.5
date	90.04.05.11.02.09;	author john;	state Exp;
branches;
next	1.4;

1.4
date	89.08.03.09.55.16;	author john;	state Exp;
branches;
next	1.3;

1.3
date	88.11.14.11.17.09;	author john;	state Exp;
branches;
next	1.2;

1.2
date	88.10.06.10.08.23;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.04.19.12.35.00;	author john;	state Exp;
branches;
next	;


desc
@@


2.4
log
@Detab new headers
@
text
@-- @@(#)$Id: shell.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
-- @@(#)Purpose:     Provide shell escape -- allow user to run commands
-- @@(#)Author:      Jonathan Leffler
-- @@(#)Product:     :PRODUCT:

FUNCTION shell_escape()

	DEFINE
		rcs		CHAR(1),
		cmd		CHAR(80),
		ans		CHAR(1)

	LET INT_FLAG = FALSE
	LET ans = '!'
	WHILE ans = '!'
		PROMPT "! " FOR cmd
		IF INT_FLAG THEN
			LET INT_FLAG = FALSE
			EXIT WHILE
		END IF
--#		IF fgl_fglgui() THEN
--#			CALL fgl_system(cmd)
--#		ELSE
			RUN cmd
--#		END IF
		PROMPT "Hit any key to continue" FOR CHAR ans
		IF INT_FLAG THEN
			LET rcs = "@@(#)$Id: shell.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
			LET INT_FLAG = FALSE
			EXIT WHILE
		END IF
	END WHILE

END FUNCTION {shell_escape}
@


2.3
log
@Revamp headers with :PRODUCT: information.
@
text
@d1 4
a4 4
-- @@(#)$Id: shell.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
-- @@(#)Purpose:		Provide shell escape -- allow user to run commands
-- @@(#)Author:		Jonathan Leffler
-- @@(#)Product:		:PRODUCT:
d28 1
a28 1
			LET rcs = "@@(#)$Id: shell.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
@


2.2
log
@Add minimal D4GL support
@
text
@d1 4
a4 6
{
	@@(#)$Id: shell.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)JLSS Informix Tools: General Library
	@@(#)Provide shell escape -- allow user to run commands
	@@(#)Author: JL
}
d28 1
a28 1
			LET rcs = "@@(#)$Id: shell.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
@


2.1
log
@Change sccs to rcs and Sphinx to JLSS
@
text
@d2 1
a2 1
	@@(#)$Id: shell.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
d23 5
a27 1
		RUN cmd
d30 1
a30 1
			LET rcs = "@@(#)$Id: shell.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
@


1.6
log
@Remove echo. NB: PROMPT LINE must be 24 for sanity to prevail
@
text
@d2 2
a3 2
	@@(#)$Id: shell.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
d11 1
a11 1
		sccs	CHAR(1),
d26 1
a26 1
			LET sccs = "@@(#)$Id: shell.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
@


1.5
log
@Add sccs string
@
text
@a23 1
		RUN "echo"
@


1.4
log
@Remove KPI-isms
@
text
@d11 1
d27 1
@


1.3
log
@Add interrupt handling
@
text
@d3 1
a3 1
	@@(#)KPI Database Project: General Library
@


1.2
log
@Allow repeat command on repeat of !
@
text
@d14 1
d18 4
d25 4
@


1.1
log
@Initial revision
@
text
@d14 7
a20 4
	PROMPT "! " FOR cmd
	RUN cmd
	RUN "echo"
	PROMPT "Hit any key to continue" FOR CHAR ans
@
