
DATABASE test1

MAIN

#Err:Program stopped at 'temp.4gl', line number 5.
#Error status number -5015.
#[unixODBC][SAP AG][LIBSQLOD SO][SAP DB]Syntax error or access violation;
#-5015 POS(8) Missing keyword:TYPE,TRIGGER,SEQUENCE,ROLE,PACKAGE,DBPROCEDURE,DBPROC..

	CREATE TEMP TABLE xtemp
		(
		xno	INTEGER
		)

	DECLARE mycur CURSOR FOR
		SELECT * FROM xtemp

	FOREACH mycur
		DISPLAY "ERROR: table is supposed to be empty"
		exit program (1)
	END FOREACH

	# Foreach does an implcit open and close...
	# so this isn't needed...
	# (AF) ... but we should keep it because it demonstrates incompatibility
	#between Aubit and other 4GL compilers - if it is alowed to have it
	#with Informix 4GL, it should be allowed with Aubit too.
	#To demonstrate, try running this test with -ifx-p (Hint: it will work)
	CLOSE mycur

	DROP TABLE xtemp

END MAIN
