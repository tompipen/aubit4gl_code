database test1

main
	define n,c smallint, txt char(3)
	let txt=" "
	let c=0
		#drop table a
	while 1
		create temp table a(f1 char(3))

		begin work
			insert into a values('abc')
			select count(*) into n from a
			display "In transaction:",n
		rollback work

		select count(*) into n from a
		display "After transaction rolled back:",n

		select f1 into txt from a
		display txt
		drop table a
		let c=c+1

		if c=2 then 
			exit while 
		end if
	end while
end main
