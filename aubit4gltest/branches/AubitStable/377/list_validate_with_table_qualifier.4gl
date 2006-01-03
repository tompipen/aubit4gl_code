
DATABASE TEST1

MAIN
  DEFINE owner char(8)

 { Test is invalid - it assumes user "informix" created the database }
  
  
  
	VALIDATE owner LIKE "informix".systables.owner
END MAIN
