
database test1

main
	define d date
whenever error continue
	drop table a
whenever error stop
	create temp table a(dt date)
	let d=mdy(2,10,2004)

	insert into a values(d)

	let d=d-3

	update a set dt=d

	select dt into d from a

	display d

	unload to "xx1" select * from a
	--unload to "xx2" select * from a where d>=mdy(1,1,2001) and d<=mdy(1,1,2005)
	unload to "xx3" select * from a where d>="1/1/2001" and d<="1/1/2005"
	--unload to "xx4" select * from a where d>=mdy(1,1,2005) and d<=mdy(1,1,2005)
	unload to "xx5" select * from a where d>="1/1/2005" and d<="1/1/2005"

end main
