database test1
main

whenever error continue
drop table scv
whenever error stop

create table scv (
    tabname char(18),
    colname char(18),
    attrname char(10),
    attrval char(64)
)
whenever error continue
drop table dummy
create table dummy (
	tabname char(20)
)
whenever error stop
insert into scv values("dummy","tabname","INCLUDE","AAA,BBB")
end main
