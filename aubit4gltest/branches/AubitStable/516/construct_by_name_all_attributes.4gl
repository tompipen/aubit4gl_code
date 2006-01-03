
DATABASE test1

MAIN
  DEFINE tabname LIKE systables.tabname
  DEFINE owner LIKE systables.owner
  DEFINE tabid LIKE systables.tabid
  DEFINE rowsize LIKE systables.rowsize
  DEFINE ncols LIKE systables.ncols
  DEFINE nindexes LIKE systables.nindexes
	DEFINE strWhere CHAR(128)

	OPEN WINDOW w_ AT 2,2 WITH FORM "syst" ATTRIBUTE(BORDER)
	CONSTRUCT BY NAME strWhere ON tabname,owner,tabid,rowsize,ncols,nindexes
	  ATTRIBUTE (
		  WHITE,YELLOW,MAGENTA,CYAN,GREEN,BLUE,BLACK,NORMAL,BOLD,DIM,
      REVERSE
		)
	CLOSE WINDOW w_
	DISPLAY "Where ", strWhere clipped
END MAIN
