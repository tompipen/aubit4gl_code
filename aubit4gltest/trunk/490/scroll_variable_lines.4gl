

MAIN
  DEFINE arr ARRAY[10] OF RECORD
	  num SMALLINT,
		str CHAR(20)
	END RECORD
	DEFINE i SMALLINT
	DEFINE num_lines SMALLINT
	DEFINE pos SMALLINT

	OPTIONS DELETE KEY CONTROL-E

	FOR i = 1 TO 10
	  LET arr[i].num = i
	  LET arr[i].str = "Num : ", i
	END FOR
	OPEN WINDOW w_ AT 2, 2 WITH FORM "xpto" ATTRIBUTE(BORDER)
	CALL set_count(i)
	DISPLAY ARRAY arr TO sa.* 
		ON KEY (CONTROL-N)
		  LET num_lines = num_lines + 1
			DISPLAY "Num lines ", num_lines AT 18, 2 ATTRIBUTE(REVERSE)
		ON KEY (CONTROL-P)
		  LET num_lines = num_lines - 1
			DISPLAY "Num lines ", num_lines AT 18, 2 ATTRIBUTE(REVERSE)
		ON KEY (CONTROL-E)
		  SCROLL sa.num,sa.str DOWN BY num_lines
		ON KEY (CONTROL-U)
		  SCROLL sa.num,sa.str UP BY num_lines
	END DISPLAY
END MAIN
