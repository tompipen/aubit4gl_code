-- @(#)$Id: security.4gl,v 1.1 2002-06-20 09:10:42 afalout Exp $
-- @(#)JLSS Informix Tools: General Library
-- @(#)See whether user is entitled to perform an action
-- @(#)Author: JL

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
		LET user_name = "@(#)$Id: security.4gl,v 1.1 2002-06-20 09:10:42 afalout Exp $"	{ SCCS ID only }
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
