
DATABASE test1

MAIN
	DEFINE strWhere CHAR(128)

	OPEN WINDOW w_ AT 2,2 WITH FORM "sysu" ATTRIBUTE(BORDER)
	CONSTRUCT BY NAME strWhere ON sysusers.*
		BEFORE FIELD  username, usertype
	    ERROR "In before field list"
	END CONSTRUCT
	CLOSE WINDOW w_
	DISPLAY "Where ", strWhere clipped
END MAIN
