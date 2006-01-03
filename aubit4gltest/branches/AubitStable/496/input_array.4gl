
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
	OPEN WINDOW w_ AT 3, 3 WITH FORM "xpto" ATTRIBUTE(BORDER)
	CALL set_count(i)
	INPUT ARRAY arr WITHOUT DEFAULTS FROM sa.* 
	  AFTER INPUT 
		  LET num_lines = arr_count()
		BEFORE ROW 
		  IF fgl_lastkey() = fgl_keyval("DELETE") THEN
				LET pos = scr_line()
			  LET arr[pos].str ="JJJJ"
			END IF
		AFTER ROW 
	END INPUT
	FOR i = 1 TO num_lines
	  DISPLAY "Linha : ", arr[i].num, " / ", arr[i].str
	END FOR

END MAIN
