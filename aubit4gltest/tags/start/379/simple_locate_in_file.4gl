
MAIN
   DEFINE a TEXT
	 DEFINE b BYTE
	 DEFINE file_name CHAR(64)

	 LOCATE a IN FILE "/tmp/xpto.loc"
	 LET file_name = "/tmp/xpta.loc"
	 LOCATE b IN FILE file_name
END MAIN
