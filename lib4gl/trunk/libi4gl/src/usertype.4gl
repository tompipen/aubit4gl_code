head	1.4;
access;
symbols;
locks; strict;
comment	@# @;


1.4
date	90.04.05.11.02.12;	author john;	state Exp;
branches;
next	1.3;

1.3
date	89.08.03.09.55.20;	author john;	state Exp;
branches;
next	1.2;

1.2
date	88.02.22.13.08.43;	author john;	state Exp;
branches;
next	1.1;

1.1
date	88.02.15.19.22.18;	author john;	state Exp;
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
	@@(#)$Id: usertype.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Sphinx Informix Tools: General Library
	@@(#)Return category of user
	@@(#)Author: JL
}

{ Return type of user: D = DBA, R = Resource, C = Connect }
FUNCTION usertype()

	DEFINE
		sccs		CHAR(1),
		user_type	CHAR(1)

	{ Check authorisation }
	SELECT Sysusers.Usertype
		INTO user_type
		FROM Sysusers
		WHERE Sysusers.Username = USER

	{ If user_type is null, the KPI security system has broken down }
	IF user_type IS NULL THEN
		SELECT Sysusers.Usertype
			INTO user_type
			FROM Sysusers
			WHERE Sysusers.Username = "public"
	END IF

	{ If user_type is still null, the I4GL security system is broken }
	IF user_type IS NULL THEN
		LET user_type = 'C'
		LET sccs = "@@(#)$Id: usertype.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"
	END IF

	RETURN user_type

END FUNCTION {usertype}
@


1.3
log
@Remove KPI-isms
@
text
@d12 1
d32 1
@


1.2
log
@Rename usertype variable; add return statement
@
text
@d3 1
a3 1
	@@(#)KPI Database Project: General Library
@


1.1
log
@Initial revision
@
text
@d12 1
a12 1
		usertype	CHAR(1)
d16 1
a16 1
		INTO usertype
d20 2
a21 2
	{ If usertype is null, the KPI security system has broken down }
	IF usertype IS NULL THEN
d23 1
a23 1
			INTO usertype
d28 3
a30 3
	{ If usertype is still null, the I4GL security system is broken }
	IF usertype IS NULL THEN
		LET usertype = 'C'
d32 2
@
