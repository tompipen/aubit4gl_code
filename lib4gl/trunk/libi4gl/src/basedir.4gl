-- @(#)$Id: basedir.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
-- @(#)JLSS Informix Tools: General Library
-- @(#)Define base directory for application
-- @(#)Author: JL

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
		LET sccs = "@(#)$Id: basedir.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
	END IF

END FUNCTION {set_base}
