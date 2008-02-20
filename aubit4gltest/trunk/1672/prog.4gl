{**
 * @file
 * ERror in EC code printing ORDERed TEXT variables
 * @process TEST_GENERAL
 *}
 
DATABASE test1

MAIN
DEFINE w RECORD 
               cvee INT,
	       obse TEXT
	END RECORD

START REPORT cliracti_report TO "paso"
LOCATE w.obse IN MEMORY
OUTPUT TO REPORT cliracti_report(w.*)
FINISH REPORT cliracti_report
END MAIN

REPORT cliracti_report(s)
DEFINE s RECORD
               cvee INT,
	       obse TEXT
          END RECORD

ORDER BY s.cvee

FORMAT
    ON EVERY ROW
	 PRINT s.cvee,
	       s.obse 
END REPORT
