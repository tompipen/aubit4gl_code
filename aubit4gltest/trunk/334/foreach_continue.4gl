database test1

MAIN
	DEFINE tab_id INTEGER
	DEFINE tab_name CHAR(18)
	DEFINE str char(128)

	LET str = "select tabid, tabname from systables"
	PREPARE st FROM str
	DECLARE cr CURSOR FOR st
  FOREACH cr into tab_id, tab_name
		if tab_id = 100 then
		  continue foreach
		end if
	  display "Tabname ", tab_name, " - ", tab_id
	END FOREACH
END MAIN
