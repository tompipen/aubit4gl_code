database test1
main
# MID : 513

create temp table bibble (a char(10))

insert into bibble values("Hello")
insert into bibble values("World")

select * from bibble
order by a
into temp a1;

end main
