
database test1
main

create temp table a (a1 integer);   -- all ints 0 .. 9
create temp table o (o1 integer);   -- odds 1,3,..9
create temp table e (e1 integer);   -- evens 2,4 .. 8
insert into a values(0);
insert into a values(1);
insert into a values(2);
insert into a values(3);
insert into a values(4);
insert into a values(5);
insert into a values(6);
insert into a values(7);
insert into a values(8);
insert into a values(9);
insert into o values(1);
insert into o values(3);
insert into o values(5);
insert into o values(7);
insert into o values(9);
insert into e values(2);
insert into e values(4);
insert into e values(6);
insert into e values(8);


unload to "unl1"
 	select * FROM a, OUTER o WHERE a.a1 = o.o1;

-- ANSI SQL for the above LEFT Join a to o AND a to e
unload to "unl2"
	select * FROM a, OUTER o, OUTER e WHERE a.a1 = o.o1 AND a.a1 = e.e1;

-- ANSI SQL for the above LEFT JOIN a to (LEFT JOIN of e and e (no rows))
unload to "unl3"
 	select * FROM a, OUTER (o, OUTER e) WHERE a.a1 = o.o1 AND o.o1 = e.e1;
end main
