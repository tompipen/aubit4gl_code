DATABASE test1

MAIN
	DEFINE	date_time	DATETIME HOUR TO SECOND	

	CREATE TEMP TABLE temp_tbl( time_stamp	DATETIME HOUR TO SECOND)

	LET date_time = "12:03:01"
#CURRENT HOUR TO SECOND
	
	DISPLAY date_time 

	INSERT INTO temp_tbl VALUES (date_time)
	initialize date_time to null
	
	select time_stamp into date_Time from temp_tbl

	display date_time 


END MAIN


