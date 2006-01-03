
DATABASE test1

MAIN
  DEFINE myS RECORD LIKE systables.*
  
{ all stmts below are system specific
  DEFINE mySecondS RECORD LIKE "informix".systables.*
  DEFINE mySecondAS RECORD LIKE informix.systables.*
  DEFINE myThirdS RECORD LIKE test:"informix".systables.*
  DEFINE myForthS RECORD LIKE test:informix.systables.*
  DEFINE myFiftS RECORD LIKE test@unstable:"informix".systables.*
  DEFINE mySixS RECORD LIKE test@unstable:informix.systables.*
  
}
  
END MAIN
