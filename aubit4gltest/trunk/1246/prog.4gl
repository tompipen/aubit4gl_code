database test1

main
	define n smallint, txt char(3)

	whenever error continue
	drop table a_1246
	whenever error stop 

	create table a_1246(f1 char(3))

	begin work
	insert into a_1246 values('abc')
	select count(*) into n from a_1246
	display n
	rollback work

	if n!=1 then
		drop table a_1246
		exit program 1
	end if

	
	select count(*) into n from a_1246
	display n

	if n!=0 then
		drop table a_1246
		exit program 2
	end if

	drop table a_1246
end main
