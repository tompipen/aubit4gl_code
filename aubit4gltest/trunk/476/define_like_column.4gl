
DATABASE test1

MAIN
  DEFINE myTabid LIKE systables.tabid

{ All stmts below are system specific

  DEFINE mySecondTabid LIKE "informix".systables.tabid
  DEFINE mySecondATabid LIKE informix.systables.tabid
  DEFINE myThirdTabid LIKE test:"informix".systables.tabid
  DEFINE myForthTabid LIKE test:informix.systables.tabid
  DEFINE myFiftTabid LIKE test@unstable:"informix".systables.tabid
  DEFINE mySixTabid LIKE test@unstable:informix.systables.tabid
  
  
}
END MAIN
