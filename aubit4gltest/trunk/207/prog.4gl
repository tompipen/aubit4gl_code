database test1

main
	define	xvar		char(25)
	define	xdttm		datetime year to second
	define	basedttm	datetime year to second
	define	xdate		date
	define	basedate	date

	display "=============================================================="
	display "0273: In SQL, if extend(year to day) and date() has different"
	display "      output format, they won't match. "
	display "--------------------------------------------------------------"

	let basedttm = '2003-05-31 12:00:00'
	let basedate = mdy(8,26,2003)

	display "Using base values:"
	display "-> Datetime: ", basedttm
	display "-> Date    : ", basedate

	create temp table m0273 (
		create_dttm 	datetime year to second,
		mydate		date )

	insert into m0273 values ( basedttm, basedate )

	display "Performing extend(year to day) on ", basedttm
	select	extend(create_dttm, year to day)
	into	xvar
	from	m0273
	where	extend(create_dttm,year to day) = '2003-05-31'

	call expect("2003-05-31",xvar)
	#display "Expect: 2003-05-31"
	#display "Actual: ", xvar

	display "We expect extend() working in the following cases:"
	display "1. comparison with a variable of type date"
	display "	extend() rel_op :a_var"
	select	count(*)
	into	xvar
	from	m0273
	where	extend(create_dttm, year to day) < basedate

	display basedttm, " < ", basedate
	call expect(1,xvar)
	#display "Expect: 1"
	#display "Actual: ", xvar

	select	count(*)
	into	xvar
	from	m0273
	where	extend(create_dttm, year to day) > basedate

	display basedttm, " > ", basedate
	call expect(0,xvar)
	#display "Expect: 0"
	#display "Actual: ", xvar

	let xdate = "05/31/2003"
	select	count(*)
	into	xvar
	from	m0273
	where	extend(create_dttm, year to day) = xdate

	display basedttm, " = ", xdate
	call expect(1,xvar)
	#display "Expect: 1"
	#display "Actual: ", xvar

	display "2. comparison with a table field of type date"
	display "	extend() rel_op a_field"
	select	count(*)
	into	xvar
	from	m0273
	where	extend(create_dttm, year to day) < mydate

	display basedttm, " < ", basedate
	call expect(1,xvar)
	#display "Expect: 1"
	#display "Actual: ", xvar

	select	count(*)
	into	xvar
	from	m0273
	where	extend(create_dttm, year to day) > mydate

	display basedttm, " > ", basedate
	call expect(0,xvar)
	# display "Expect: 0"
	#display "Actual: ", xvar

	update	m0273
	set	mydate = xdate
	#set	mydate = date( extend(create_dttm, year to day) )

	select	count(*)
	into	xvar
	from	m0273
	where	extend(create_dttm, year to day) = mydate

	display basedttm, " = ", xdate
	call expect(1,xvar)

	#display "Expect: 1"
	#display "Actual: ", xvar

	display "3. comparison with a date literal"
	display "	extend() rel_op '2003-08-26'"
	update	m0273
	set	mydate = basedate

	select	count(*)
	into	xvar
	from	m0273
	where	extend(create_dttm, year to day) < '2003-08-26'

	display	basedttm, " < '2003-08-26'"
	call expect(1,xvar)
	#display "Expect: 1"
	#display "Actual: ", xvar

	select	count(*)
	into	xvar
	from	m0273
	where	extend(create_dttm, year to day) > '2003-08-26'

	display	basedttm, " > '2003-08-26'"

	call expect(0,xvar)
	#display "Expect: 0"
	#display "Actual: ", xvar

	update	m0273
	#set	mydate = date( extend(create_dttm, year to day) )
	set	mydate = '05/31/2003'

	select	count(*)
	into	xvar
	from	m0273
	where	extend(create_dttm, year to day) = '2003-05-31'

	display	basedttm, " = '2003-05-31'"
	call expect(1,xvar)
	#display "Expect: 1"
	#display "Actual: ", xvar

	display "4. comparison with a SQL date function"
	display "	extend() rel_op today + 1"
	select	count(*)
	into	xvar
	from	m0273
	where	extend(create_dttm, year to day) < today + 1

	display	basedttm, " < today + 1"
	call expect(1,xvar)
	#display "Expect: 1"
	#display "Actual: ", xvar

	select	count(*)
	into	xvar
	from	m0273
	where	extend(create_dttm, year to day) > today + 1

	display	basedttm, " > today + 1"
	call expect(0,xvar)
	#display "Expect: 0"
	#display "Actual: ", xvar

	let xdttm = current + 1 units day
	update	m0273
	set	create_dttm = xdttm

	select	count(*)
	into	xvar
	from	m0273
	where	extend(create_dttm, year to day) = today + 1

	display	xdttm, " = today + 1"
	call expect(1,xvar)
	#display "Expect: 1"
	#display "Actual: ", xvar
	exit program 0
end main


function expect(e,a) 
define e,a char(25)
	display "Expected:",e," Actual ",a
	if e!=a then
		display "EXPECTED!=ACTUAL"
		exit program 1
	end if
end function
