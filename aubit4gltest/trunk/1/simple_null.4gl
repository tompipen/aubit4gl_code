DATABASE test1
MAIN 
#defined but not used, can be removed? 
#define a record like systables.*

	
	CREATE TEMP TABLE xtemp ( 
	xcode CHAR(1), 
	xchar CHAR(10), 
	xsint SMALLINT, 
	xint INTEGER, 
	xflt FLOAT, 
	xdec DECIMAL(32,2), 
	xdate DATE, 
	xmon MONEY, 
	xdt DATETIME HOUR TO SECOND 
	) 
	
	
	
	INSERT INTO xtemp VALUES ("1", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL) 
	CALL show_values()
	DELETE FROM xtemp
	INSERT INTO xtemp VALUES ("1", "1", 1, 1, 1,1, "01/01/2001", 1,"12:01:02") 
	CALL show_values()
	DROP TABLE xtemp 
end main

function show_values()
DEFINE 
xcode CHAR(1), 
xchar CHAR(10), 
xsint SMALLINT, 
xint INTEGER, 
xflt FLOAT, 
xdec DECIMAL(32,2), 
xdate DATE, 
xmon MONEY(10,2), 
xdt DATETIME HOUR TO SECOND 


	
	SELECT * INTO xcode, xchar, xsint, xint, xflt, xdec, xdate, xmon, xdt FROM xtemp 
	WHERE xtemp.xcode = "1" 
	
	IF status = 0 THEN 
		IF xchar IS NULL THEN 
			display "xchar is null" 
		ELSE 
			display "xchar is ", xchar 
		END IF 
		
		IF xsint IS NULL THEN 
			display "xsint is null" 
		ELSE 
			display  "xsint is ", xsint 
		END IF 
		
		IF xint IS NULL THEN 
			display  "xint is null" 
		ELSE 
			display  "xint is ", xint 
		END IF 
		
		IF xflt IS NULL THEN 
			display  "xflt is null" 
		ELSE 
			display  "xflt is ", xflt 
		END IF 
		
		IF xdec IS NULL THEN 
			display  "xdec is null" 
		ELSE 
			display  "xdec is ", xdec 
		END IF 
		
		IF xdate IS NULL THEN 
			display  "xdate is null" 
		ELSE 
			display  "xdate is ", xdate 
		END IF 
		
		IF xmon IS NULL THEN 
			display  "xmon is null" 
		ELSE 
			display  "xmon is ", xmon 
		END IF 
		
		IF xdt IS NULL THEN 
			display  "xdt is null" 
		ELSE 
			display  "xdt is ", xdt 
		END IF 
	
	END IF
END  FUNCTION

