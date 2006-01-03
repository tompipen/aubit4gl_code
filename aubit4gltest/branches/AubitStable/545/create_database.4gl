
MAIN

	WHENEVER ERROR CONTINUE
	DROP database xpto 
#|________________^
#| Error at line 5, character 18
#| You cannot drop a database from within Aubit4gl - if the target database 
#| allows - prepare and execute it manually (xpto)

   CREATE DATABASE xpto
   
	WHENEVER ERROR CONTINUE
	DROP database xpto 
	WHENEVER ERROR STOP
   
END MAIN



