

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
	DISPLAY ARRAY arr TO sa.* 
		ON KEY (CONTROL-E)
		  SCROLL sa.num, sa.str DOWN
		  
		#I think this 2 whare introduced by 4Js:
		ON KEY ("home")
			display "On key home"
		ON KEY ("end")
			display "On key end"
		  
	END DISPLAY
END MAIN
