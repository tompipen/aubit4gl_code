database test1
main
	define	x1, y1	char(10)
	define	h1	char(100)

	create temp table abc(x char(10), y char(10))

	insert into abc values("a", "1");
	insert into abc values("c", "3");
	insert into abc values("b", "2");

	declare	acur cursor for
		select	*
		from	abc
		order by y desc
	foreach acur into x1, y1
		display x1, y1
	end foreach

end main


