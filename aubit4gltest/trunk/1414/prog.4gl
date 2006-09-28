database test1
main
define a char(4)
define sa smallint

create temp table testsmall (f01 smallint)
create temp table testint (f01 int)
insert into testsmall values (7004)
select f01 into a from testsmall
display "a=", a

select f01 into sa from testsmall
display "a=", sa



select f01 into a from testint
display "a=", a

delete from testint

insert into testint values (7004)
select f01 into a from testint
display "a=", a

end main

