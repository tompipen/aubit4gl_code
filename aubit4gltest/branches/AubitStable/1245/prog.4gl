database test1
main
define xdate date
	create temp table testtbl (zdate date);
	
	initialize  xdate to null
	
	insert into testtbl (zdate) values (xdate)
	display "SQLCA.SQLCODE=",sqlca.sqlcode
	
	let xdate=mdy(1,1,2005) # Give it something to wipe...
	
	display "Doing unload"
	unload to "unl1.unl" select * from testtbl
	
	display "Doing select"
	select * into xdate from testtbl where zdate is null
	
	if xdate is not null then
		display "Date isn't null:",xdate
		exit program 1
	end if

	let xdate=mdy(1,1,2005)
	
	display "Doing update"
	update testtbl set zdate=xdate where zdate is null
	display "Doing unload"
	unload to "unl2.unl" select * from testtbl
	
	initialize xdate to null
	
	display "Doing select"
	
	select * into xdate from testtbl where zdate is not null
	
	if xdate is null then
		display "Date is null after I updated it : ",xdate
		exit program 2
	end if
	
	display "xdate=",xdate

end main
