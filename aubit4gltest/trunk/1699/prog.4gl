{**
 * @file
 * compilte time: undefined reference to 'lineno'
 * @process TEST_GENERAL
 *}
 
DATABASE test1
DEFINE 	gr_customer 	RECORD 
            customer_num            int,
            fname                   char(15),
            lname                   char(15)
           end record

MAIN
  START REPORT three_up
  DECLARE c_cust CURSOR FOR
    SELECT * INTO gr_customer.*
       FROM customer
       ORDER BY zipcode,company
  FOREACH c_cust
    OUTPUT TO REPORT three_up()
  END FOREACH
  FINISH REPORT three_up
END MAIN

REPORT three_up() 
FORMAT
  FIRST PAGE HEADER
	LET pageno = 0

  ON EVERY ROW
    PRINT "row"

  ON LAST ROW
	PRINT "last"

  PAGE TRAILER
	LET pageno = pageno + 1
	PRINT "page",pageno USING "-----" 
END REPORT  
