head	1.4;
access;
symbols;
locks; strict;
comment	@# @;


1.4
date	98.08.20.20.19.20;	author jleffler;	state Exp;
branches;
next	1.3;

1.3
date	98.08.20.20.17.48;	author jleffler;	state Exp;
branches;
next	1.2;

1.2
date	97.10.07.18.35.38;	author johnl;	state Exp;
branches;
next	1.1;

1.1
date	97.09.03.01.29.22;	author johnl;	state Exp;
branches;
next	;


desc
@I4GL code to remove "$Revision: 1.1 $" leaving just XYZ
@


1.4
log
@Detab new headers
@
text
@-- @@(#)$Id: rcsmunge.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
-- @@(#)Purpose:     Remove RCS ID string control information from strings
-- @@(#)Author:      Jonathan Leffler
-- @@(#)Product:     :PRODUCT:

{
-- Test code
MAIN
	DEFINE s VARCHAR(80)
	LET s = "Version $Revision: 1.1 $ ($Date: 2002-06-14 05:03:47 $)"
	DISPLAY "<<", s, ">>"
	LET s = rcs_munge(s)
	DISPLAY "<<", s, ">>"
END MAIN
}

FUNCTION rcs_munge(in_str)

	DEFINE in_str	VARCHAR(80)
	DEFINE out_str	VARCHAR(80)
	DEFINE rcs		CHAR(1)
	DEFINE i		INTEGER		-- Index into in_str
	DEFINE j		INTEGER		-- Index into out_str
	DEFINE len		INTEGER		-- Length of in_str (ignoring trailing blanks)

	LET i = 1
	LET j = 1
	LET len = LENGTH(in_str)

	WHILE i <= len
		WHILE (i <= len AND in_str[i] != '$')
			LET out_str[j] = in_str[i]
			LET i = i + 1
			LET j = j + 1
		END WHILE
		IF (in_str[i] == '$') THEN
			LET i = i + 1
		END IF
		WHILE (i <= len AND  in_str[i] != ':' AND in_str[i] != '$')
			LET i = i + 1
		END WHILE
		IF (i > len) THEN
			EXIT WHILE
		END IF
		IF (in_str[i] == '$') THEN
			-- Unexpanded keyword '$Keyword$' notation (skip it)
			LET i = i + 1
			CONTINUE WHILE
		END IF
		IF (in_str[i] == ':') THEN
			LET i = i + 1
		END IF
		IF (in_str[i] == ' ') THEN
			LET i = i + 1
		END IF
		WHILE (i <= len AND in_str[i] != '$')
			LET out_str[j] = in_str[i]
			LET i = i + 1
			LET j = j + 1
		END WHILE
		IF (in_str[i] == '$') THEN
			IF (out_str[j-1] == ' ') THEN
				LET j = j - 1
			END IF
			LET i = i + 1
		END IF
	END WHILE

	RETURN out_str

	LET rcs = "@@(#)$Id: rcsmunge.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"

END FUNCTION {rcs_munge}
@


1.3
log
@Revamp headers with :PRODUCT: information.
@
text
@d1 4
a4 4
-- @@(#)$Id: rcsmunge.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
-- @@(#)Purpose:		Remove RCS ID string control information from strings
-- @@(#)Author:		Jonathan Leffler
-- @@(#)Product:		:PRODUCT:
d10 1
a10 1
	LET s = "Version $Revision: 1.1 $ ($Date: 2002-06-14 05:03:47 $)"
d71 1
a71 1
	LET rcs = "@@(#)$Id: rcsmunge.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
@


1.2
log
@Improve heading comments and example
@
text
@d1 4
a4 6
{
	@@(#)$Id: rcsmunge.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)JLSS I4GL Library: Version Control Information
	@@(#)Remove RCS ID string control information from strings
	@@(#)Author: JL
}
d10 1
a10 1
	LET s = "Version $Revision: 1.1 $ ($Date: 2002-06-14 05:03:47 $)"
d21 1
d70 2
@


1.1
log
@Initial revision
@
text
@d2 8
d12 1
a12 1
	LET s = rcs_munge("Version $Revision: 1.1 $ ($Date: 2002-06-14 05:03:47 $)")
d14 1
a14 1
	LET s = rcs_munge("Version $Revision: 1.1 $ ($Date: 2002-06-14 05:03:47 $)")
d72 1
a72 2
END FUNCTION

@
