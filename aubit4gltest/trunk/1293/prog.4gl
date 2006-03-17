DATABASE test1
 MAIN
         DEFINE
                 d1 DATE,
                 d2 DATE,
                 d3 DATE
         LET d1 = mdy(12,31,1999)
         LET d2 = mdy(1,1,2000)
         LET d3 = mdy(1,2,2000)
         DISPLAY d1 USING " #######", d2 USING " #######", d3 USING " #######"
         DISPLAY d1 USING " mm/dd/yyyy", d2 USING " mm/dd/yyyy", d3 USING " mm/dd/yyyy"

	whenever error continue
	drop table testdate
	whenever error stop
         CREATE TABLE TESTDATE (
             date1 DATE,
             date2 DATE,
             date3 DATE
         )
         INSERT INTO TESTDATE VALUES (d1, d2, d3)

         SELECT date1, date2, date3 INTO d1, d2, d3 FROM TESTDATE

         DISPLAY d1 USING " mm/dd/yyyy", d2 USING " mm/dd/yyyy", d3 USING " mm/dd/yyyy"

         --DROP TABLE TESTDATE

	if d1 is null or d2 is null or d3 is null then
		exit program 2
	end if
	if d1!=mdy(12,31,1999) or d2!=mdy(1,1,2000) or d3!=mdy(1,2,2000) then
		exit program 1
	else
		exit program 0
	end if
  
 END MAIN
