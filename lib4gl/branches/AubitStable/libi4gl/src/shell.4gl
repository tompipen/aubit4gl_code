-- @(#)$Id: shell.4gl,v 1.2 2002-06-14 09:23:17 afalout Exp $
-- @(#)Purpose:     Provide shell escape -- allow user to run commands
-- @(#)Author:      Jonathan Leffler
-- @(#)Product:     :PRODUCT:

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
			LET rcs = "@(#)$Id: shell.4gl,v 1.2 2002-06-14 09:23:17 afalout Exp $"
			LET INT_FLAG = FALSE
			EXIT WHILE
		END IF
	END WHILE

END FUNCTION {shell_escape}
