head	1.3;
access;
symbols;
locks; strict;
comment	@# @;


1.3
date	92.10.25.12.07.25;	author jl;	state Exp;
branches;
next	1.2;

1.2
date	91.05.09.18.12.16;	author johnl;	state Exp;
branches;
next	1.1;

1.1
date	90.08.06.16.03.39;	author john;	state Exp;
branches;
next	;


desc
@@


1.3
log
@Replace getenviron by fgl_getenv
@
text
@-- @@(#)$Id: basedir.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
-- @@(#)JLSS Informix Tools: General Library
-- @@(#)Define base directory for application
-- @@(#)Author: JL

DEFINE
	baseenv		CHAR(32),	{ Name of environment variable }
	basedir		CHAR(64)	{ Value of environment variable }

{ Return base directory for application }
FUNCTION get_base()

	{ Edit the next line for each project }
	CALL set_base("BASEDIRECTORY")

	RETURN basedir

END FUNCTION {get_base}

{ Set base directory for application }
FUNCTION set_base(basevar)

	DEFINE
		basevar	CHAR(32),
		sccs	CHAR(1)

	IF baseenv IS NULL OR basevar != baseenv THEN
		LET baseenv = basevar
		LET basedir = fgl_getenv(basevar)
		IF basedir IS NULL THEN
			LET basedir = "."
		END IF
		LET sccs = "@@(#)$Id: basedir.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $"
	END IF

END FUNCTION {set_base}
@


1.2
log
@Upgrade
@
text
@d29 1
a29 1
		LET basedir = getenviron(basevar)
@


1.1
log
@Initial revision
@
text
@d1 4
a4 6
{
	@@(#)$Id: basedir.4gl,v 1.1 2002-06-14 05:03:46 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
	@@(#)Define base directory for application
	@@(#)Author: JL
}
d24 2
a25 1
		basevar	CHAR(32)
d33 1
@
