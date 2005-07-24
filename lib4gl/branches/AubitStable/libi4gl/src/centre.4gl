{
	@(#)$Id: centre.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $
	@(#)Sphinx Informix Tools: General Library
	@(#)Centre string in field
	@(#)Author: JL
}

FUNCTION centre(title, ncols)

    DEFINE
		sccs	CHAR(1),
		title	CHAR(512),
		ncols	INTEGER    { width of field }

    DEFINE
		col     SMALLINT,
		centr	CHAR(512)

    LET col = (ncols - LENGTH(title)) / 2
    IF col > 0 THEN
		LET centr = col SPACES, title CLIPPED
	ELSE
		LET sccs  = "@(#)$Id: centre.4gl,v 1.2 2002-06-14 09:23:16 afalout Exp $"
		LET centr = title
		LET ncols = LENGTH(title)
	END IF

	RETURN centr[1,ncols] CLIPPED

END FUNCTION {centre}
