{
	@(#)$Id: fileextn.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Sphinx Informix Tools: General Library
	@(#)Return file name extension
	@(#)Author: JL
}

{
	Find extension of filename.
	Extension only counts if it is less than half the length of
	the filename.  This stops "s.frederick" being given the extension
	".frederick".  It also means "a.out" has not got an extension.
}

FUNCTION fileextn(filename)

	DEFINE
		sccs		CHAR(1),
		filename	CHAR(14),
		extn		CHAR(14),
		flen		SMALLINT,
		dotidx		SMALLINT,
		i			SMALLINT

	LET flen = LENGTH(filename)
	LET dotidx = 0
	FOR i = 1 TO flen
		IF filename[i] = '.' THEN
			LET dotidx = i
		END IF
	END FOR

	IF flen < 2 * dotidx THEN
		LET extn = filename[dotidx, flen]
	ELSE
		LET sccs = "@(#)$Id: fileextn.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
		LET extn = NULL
	END IF
	RETURN extn

END FUNCTION {fileextn}
