
MAIN
	DEFINE form_name CHAR(18)

  OPEN WINDOW w_name AT 3,3 WITH FORM "xpto"
	CLOSE WINDOW w_name

	LET form_name = "xpto"
  OPEN WINDOW w_name AT 3,3 WITH FORM form_name
	CLOSE WINDOW w_name
END MAIN
