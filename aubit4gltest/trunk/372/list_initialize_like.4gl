
DATABASE TEST1

MAIN
  DEFINE tabid integer
  DEFINE owner char(8)
  DEFINE tabname CHAR(18)

	INITIALIZE tabid, owner, tabname 
	  LIKE systables.tabid, "informix".systables.owner, systables.tabname
END MAIN
