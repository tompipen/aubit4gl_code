{
	@(#)$Id: usertype.4gl,v 1.2 2002-06-14 09:23:17 afalout Exp $
	@(#)Sphinx Informix Tools: General Library
	@(#)Return category of user
	@(#)Author: JL
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
		LET sccs = "@(#)$Id: usertype.4gl,v 1.2 2002-06-14 09:23:17 afalout Exp $"
	END IF

	RETURN user_type

END FUNCTION {usertype}
