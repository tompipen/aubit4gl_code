
MAIN
	DEFINE form_name CHAR(64)

  OPEN FORM f_ FROM "xpto"
	LET form_name = "xpto"
  OPEN FORM f_ FROM form_name
END MAIN
