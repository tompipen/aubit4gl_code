
MAIN
	DEFINE form_name CHAR(64)

  OPEN FORM f_ FROM "xpto"
	CLOSE FORM f_
	LET form_name = "xpto"
  OPEN FORM f_ FROM form_name
	CLOSE FORM f_
END MAIN
