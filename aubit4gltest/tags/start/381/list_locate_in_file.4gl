
MAIN
   DEFINE a TEXT
	 DEFINE b BYTE
   DEFINE c TEXT
	 DEFINE d BYTE
	 DEFINE file_name CHAR(64)

	 LOCATE a, b IN FILE "xpto.loc"
	 LET file_name = "xpta.loc"
	 LOCATE c, d IN FILE file_name
END MAIN
