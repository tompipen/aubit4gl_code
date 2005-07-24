{
	@(#)chcolumn.4gl	6.1 89/08/17
	@(#)FGLBLD: Choose column name/type
	@(#)Author: JL
}

DEFINE
	sccs		CHAR(32),
	sv_tabid	INTEGER,
	sv_tabname	CHAR(18),
	ncolumns	INTEGER,
	collist		ARRAY[100] OF RECORD
				colname		CHAR(18),
				coltype		CHAR(18)
				END RECORD

{ Use DISPLAY ARRAY to select a choice from the column list }
FUNCTION ch_syscolumns(tabname)

	DEFINE
		tabname	CHAR(18),
		tabid	INTEGER,
		n		INTEGER,
		retname	CHAR(18),
		rettype	CHAR(18)

	LET sccs = "@(#)chcolumn.4gl	6.1 89/08/17"
	OPEN WINDOW w_syscolumns AT 10, 17
		WITH FORM "syscol"
		ATTRIBUTE(BORDER, MESSAGE LINE FIRST)

	IF tabname != sv_tabname OR sv_tabname IS NULL THEN
		LET tabid = get_tabid(tabname)
		CALL fetch_columns(tabid)
	END IF

	LET n = NULL
	IF INT_FLAG = FALSE THEN
		MESSAGE "Use cursor keys to choose column"
		DISPLAY "Use ESC to select" AT 2, 1
		CALL SET_COUNT(ncolumns)
		DISPLAY BY NAME tabname
		DISPLAY ARRAY collist TO s_syscolumns.*
		IF INT_FLAG = FALSE THEN
			LET n = ARR_CURR()
		END IF
		MESSAGE ""
	END IF

	LET INT_FLAG = FALSE

	IF n IS NULL THEN
		LET retname = NULL
		LET rettype = NULL
	ELSE
		LET retname = collist[n].colname
		LET rettype = collist[n].coltype
	END IF

	CLOSE WINDOW w_syscolumns
	DISPLAY rettype TO FORMONLY.pktype
	RETURN retname, rettype

END FUNCTION {ch_syscolumns}

{ Store the column names and type data for a table }
FUNCTION fetch_columns(tabid)

	DEFINE
		i		INTEGER,
		colid	INTEGER,
		tabid	INTEGER,
		coltyp	INTEGER,
		collen	INTEGER

	IF tabid != sv_tabid THEN
		MESSAGE "Fetching column names"
		DECLARE c_columns CURSOR FOR
			SELECT Colname, Coltype, Collength, Colno
				FROM Syscolumns
				WHERE Syscolumns.Tabid = tabid
				ORDER BY Colno

		LET collist[1].colname = "ROWID"
		LET collist[1].coltype = "INTEGER"
		LET i = 1
		FOREACH c_columns
			INTO collist[i+1].colname, coltyp, collen, colid
			LET i = i + 1
			LET collist[i].coltype = sqltype(coltyp, collen)
			IF i >= 100 THEN	{ 100: dimension of array columns }
				ERROR "More than 100 columns in table -- extra ignored"
				EXIT FOREACH
			END IF
		END FOREACH
		LET ncolumns = i
		LET sv_tabid = tabid
		MESSAGE ""
	END IF

END FUNCTION {fetch_columns}

{ Tell how many columns there are }
FUNCTION num_columns()

	RETURN ncolumns

END FUNCTION {num_columns}

{ Give name of ith column }
FUNCTION get_colname(i)

	DEFINE
		i		INTEGER,
		retval	CHAR(18)

	IF i > 0 AND i <= ncolumns THEN
		LET retval = collist[i].colname
		IF i = 1 THEN
			LET retval = downshift(retval)
		END IF
	ELSE
		LET retval = NULL
	END IF
	RETURN retval

END FUNCTION {get_colname}

{ Validate column name and return type of column }
FUNCTION chk_column(colname)

	DEFINE
		colname	CHAR(18),
		i		INTEGER,
		retval	CHAR(18)

	LET retval = NULL
	FOR i = 1 TO ncolumns
		IF collist[i].colname = colname THEN
			LET retval = collist[i].coltype
			EXIT FOR
		END IF
	END FOR

	RETURN retval

END FUNCTION {chk_column}

{ Find tabid for given table name }
FUNCTION get_tabid(tabname)

	DEFINE
		tabname	CHAR(18),
		retval	INTEGER

	IF tabname = sv_tabname THEN
		LET retval = sv_tabid
	ELSE
		LET retval = NULL
		SELECT Systables.Tabid
			INTO retval
			FROM Systables
			WHERE Systables.Tabname = tabname
			  AND (Systables.Tabtype = 'T' OR Systables.Tabtype = 'V')
		{ NB: do not save tabname/tabid without first fetching columns }
	END IF

	RETURN retval

END FUNCTION {get_tabid}
