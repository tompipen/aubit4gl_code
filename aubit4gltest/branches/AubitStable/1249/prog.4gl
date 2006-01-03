database test1


main
	define x smallint, d,d2 date, dc char(10), a char(1)
	whenever error continue
	drop table dt
	whenever error stop
	--execute immediate "set datestyle to 'SQL,European'"

	create temp table dt (dt date)
	delete from dt			# in case it already existed

	display 'Inserted' at 2,10
	display 'Got back' at 2,20
	# date values
	let d=mdy(8,1,2004)
	display d,'  ', d using "dd mmm yy" at 5,1
	insert into dt values (d)
	select dt into d2 from dt

	display 'date1:  ',d,'   ',d2 using "dd/mm/yy" at 6,1
	delete from dt
	

	# character values
	let dc=mdy(8,1,2004)
	insert into dt values (dc)
	select dt into d2 from dt
	display 'char:  ',d,'   ',d2 at 7,1
	if d2=d then display "ok" at 7,35 else display "ERROR" at 7,35 exit program 1 end if


	delete from dt
	#drop table dt


	# date values
	let d=mdy(8,13,2004)
	let d2=mdy(12,31,1899)
	display d,'  ', d using "dd mmm yy" at 10,1
	insert into dt values (d)
	select dt into d2 from dt
	display 'date2:  ',d,'   ',d2 at 11,1
	delete from dt

	# character values
	let dc=mdy(8,13,2004)
	insert into dt values (dc)
	select dt into d2 from dt
	display 'char:  ',d,'   ',d2 at 12,1
	if d2=d then display "ok" at 12,35 else display "ERROR" at 12,35  exit program 1 end if

	drop table dt
end main
