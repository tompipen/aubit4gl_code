
DATABASE TEST1

MAIN
  DEFINE prSystables RECORD LIKE systables.*

	VALIDATE prSystables.* LIKE systables.*

	#Using "informix" here depends on test database
	#being created by user informix (systables)
	#This will fail on a lot of test machinec and I'll disable it.
	#If you want to test for owner.tablename - please edit testdb.sql
	#script to add a consistant user name and table ownership
	#andrej	
	
	#VALIDATE prSystables.* LIKE "informix".systables.*
	
END MAIN
