
DATABASE test1

MAIN
call chk_user()
	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	WHENEVER ERROR STOP
	CREATE TABLE xpto (
	  firstColumn SMALLINT,
		secondColumn CHAR(10)
	)

  GRANT UPDATE ON xpto TO PUBLIC
  GRANT UPDATE (secondColumn) ON xpto TO PUBLIC
  GRANT UPDATE (secondColumn,firstColumn) ON xpto TO PUBLIC
  GRANT UPDATE ON xpto TO informix
  GRANT UPDATE (firstColumn) ON xpto TO informix
  GRANT UPDATE (firstColumn,secondColumn) ON xpto TO informix
  GRANT UPDATE ON xpto TO informix, root
  GRANT UPDATE (secondColumn) ON xpto TO informix, root
  GRANT UPDATE (secondColumn,firstColumn) ON xpto TO informix, root
	DROP TABLE xpto
END MAIN

FUNCTIOn chk_user()
DEFINE lv char (600)
display dbms_dialect()
	IF dbms_dialect()='POSTGRESQL' OR dbms_dialect()='POSTGRES8' THEN
		{
		see http://www.postgresql.org/docs/7.4/static/sql-createuser.html
		}
	
		let lv = "CREATE USER informix WITH CREATEDB CREATEUSER;"
		whenever error continue
			PREPARE cur1 FROM lv
			if status <> 0 then
				display "PREPARE of ", lv clipped, " failed."
			end if
			EXECUTE cur1 #INTO lv
			if status <> 0 then
				display "EXECUTE of prepared statment ", lv clipped, " failed."
			end if
		whenever error stop
		#DISPLAY lv CLIPPED
	end if

end function


