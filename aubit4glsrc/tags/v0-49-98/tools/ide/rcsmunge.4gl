{
	@(#)$Id: rcsmunge.4gl,v 1.1.1.1 2001-08-20 02:37:08 afalout Exp $
	@(#)JLSS I4GL Library: Version Control Information
	@(#)Remove RCS ID string control information from strings
	@(#)Author: JL
}

{
-- Test code
MAIN
	DEFINE s VARCHAR(80)
	LET s = "Version $Revision: 1.1.1.1 $ ($Date: 2001-08-20 02:37:08 $)"
	DISPLAY "<<", s, ">>"
	LET s = rcs_munge(s)
	DISPLAY "<<", s, ">>"
END MAIN
}

FUNCTION rcs_munge(in_str)

	DEFINE in_str	VARCHAR(80)
	DEFINE out_str	VARCHAR(80)
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
		IF (in_str[i] = '$') THEN
			LET i = i + 1
		END IF
		WHILE (i <= len AND  in_str[i] != ':' AND in_str[i] != '$')
			LET i = i + 1
		END WHILE
		IF (i > len) THEN
			EXIT WHILE
		END IF
		IF (in_str[i] = '$') THEN
			-- Unexpanded keyword '$Keyword$' notation (skip it)
			LET i = i + 1
			CONTINUE WHILE
		END IF
		IF (in_str[i] = ':') THEN
			LET i = i + 1
		END IF
		IF (in_str[i] = ' ') THEN
			LET i = i + 1
		END IF
		WHILE (i <= len AND in_str[i] != '$')
			LET out_str[j] = in_str[i]
			LET i = i + 1
			LET j = j + 1
		END WHILE
		IF (in_str[i] = '$') THEN
			IF (out_str[j-1] = ' ') THEN
				LET j = j - 1
			END IF
			LET i = i + 1
		END IF
	END WHILE

	RETURN out_str

END FUNCTION {rcs_munge}

