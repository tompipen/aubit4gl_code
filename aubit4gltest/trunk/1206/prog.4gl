
database test1

main
	define b char(4)

	create temp table pgt1(a char(5))
	insert into pgt1 values ('crap')

	select a into b from pgt1 where ord(a)<111

	display b

	update pgt1 set a='good' where ord(a)<111
	select a into b from pgt1 where ord(a)<111
	display b
	drop table pgt1
end main
