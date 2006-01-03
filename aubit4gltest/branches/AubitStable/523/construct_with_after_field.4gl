
DATABASE test1

MAIN
	DEFINE strWhere CHAR(128)

	OPEN WINDOW w_ AT 2,2 WITH FORM "sysu" ATTRIBUTE(BORDER)
	CONSTRUCT BY NAME strWhere ON sysusers.*
		AFTER FIELD  priority
	    ERROR "In after field"
	END CONSTRUCT
	CLOSE WINDOW w_
	DISPLAY "Where ", strWhere clipped
END MAIN
