head	2.6;
access;
symbols;
locks; strict;
comment	@# @;


2.6
date	91.05.09.18.12.19;	author johnl;	state Exp;
branches;
next	2.5;

2.5
date	91.05.09.14.42.47;	author johnl;	state Exp;
branches;
next	2.4;

2.4
date	90.07.19.11.02.41;	author john;	state Exp;
branches;
next	2.3;

2.3
date	90.06.21.17.15.30;	author john;	state Exp;
branches;
next	2.2;

2.2
date	90.04.06.17.56.46;	author john;	state Exp;
branches;
next	2.1;

2.1
date	90.02.08.11.23.18;	author john;	state Exp;
branches;
next	;


desc
@@


2.6
log
@Upgrade
@
text
@-- @@(#)$Id: security.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
-- @@(#)JLSS Informix Tools: General Library
-- @@(#)See whether user is entitled to perform an action
-- @@(#)Author: JL

DEFINE
	name_set	INTEGER,	{ Has user name been set? }
	user_name	CHAR(8)		{ Name of user }

FUNCTION allowed_to_do(action)

	DEFINE
		action	CHAR(12),	{ Action code }
		sccs	CHAR(1),	{ SCCS ID only }
		stmt	CHAR(110),	{ Statement to prepare }
		ostatus	INTEGER,	{ Status of OPEN }
		number	INTEGER

	IF name_set = 0 THEN
		LET user_name = "@@(#)$Id: security.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $"	{ SCCS ID only }
		LET user_name = username()
		LET name_set = 1
		LET stmt =	" SELECT COUNT(*)",
					" FROM  Sec_actuser",
					" WHERE Sec_actuser.Sau_username = ?",
					" AND Sec_actuser.Sau_action   = ?"
		WHENEVER ERROR CONTINUE
		PREPARE s_security FROM stmt
		LET ostatus = STATUS
		IF ostatus = -349 THEN	{ -349: database not selected yet }
			LET name_set = 2
			LET STATUS = 0
		ELSE
			DECLARE c_security CURSOR FOR s_security
		END IF
		WHENEVER ERROR STOP
	END IF

	IF action = "NONE" OR name_set = 2 THEN
		LET number  = 1
		LET ostatus = 0
	ELSE
		WHENEVER ERROR CONTINUE
		OPEN c_security USING user_name, action
		LET ostatus = STATUS
		IF ostatus = 0 THEN
			FETCH c_security INTO number
			CLOSE c_security
		END IF
		WHENEVER ERROR STOP
		IF ostatus != 0 THEN
			{ No security system present }
			LET name_set = 2
			LET number   = 1
			LET ostatus  = 0
		END IF
	END IF

	LET STATUS = 0			-- Crucial
	LET SQLCA.SQLCODE = 0	-- Crucial

	RETURN (number > 0 AND ostatus = 0)

END FUNCTION {allowed_to_do}
@


2.5
log
@Use BP table nomenclature
@
text
@@


2.4
log
@Upgrade for 4.0
@
text
@d1 4
a4 6
{
	@@(#)$Id: security.4gl,v 1.1 2002-06-14 05:03:47 afalout Exp $
	@@(#)Sphinx Informix Tools: Security
	@@(#)See whether user is entitled to perform an action
	@@(#)Author: JL
}
d10 1
a10 1
FUNCTION security(action)
d13 4
a16 1
		action	CHAR(12),
d23 14
a36 5
		DECLARE c_security CURSOR FOR
			SELECT COUNT(*)
				FROM Security
				WHERE @@Security.User_id = user_name
				  AND @@Security.Action  = action
d40 2
a41 1
		LET number = 1
d44 6
a49 3
		FOREACH c_security INTO number
			EXIT FOREACH
		END FOREACH
d51 1
a51 1
		IF STATUS != 0 THEN
d54 2
a55 1
			LET STATUS   = 0
d59 4
a62 1
	RETURN (number > 0 AND STATUS = 0)
d64 1
a64 1
END FUNCTION {security}
@


2.3
log
@Fix heading to remove KPGB
@
text
@d25 2
a26 2
				WHERE Security.User_id = user_name
				  AND Security.Action  = action
@


2.2
log
@You can declare cursors on non-existent tables.
It is the fetch which fails!
@
text
@d3 1
a3 1
	@@(#)KPGB Sales Analysis System: Security
@


2.1
log
@Initial revision
@
text
@a21 1
		WHENEVER ERROR CONTINUE
a26 6
		WHENEVER ERROR STOP
		IF STATUS != 0 THEN
			{ No security system present }
			LET name_set = 2
			LET STATUS   = 0
		END IF
d32 1
d36 6
@
