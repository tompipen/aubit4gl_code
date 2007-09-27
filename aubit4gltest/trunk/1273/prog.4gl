database test1
main
define lv_a char(20)
whenever error continue
drop table a
whenever error stop
create temp table a (a char(20))
insert into a values ("Hello")

let lv_a=" "
select * into lv_a from a 
where a="Hello"
union all
select * from a 
where a="World"

display lv_a
let lv_a=" "
select * into lv_a from a 
where a="World"
union all
select * from a 
where a="Hello"

display lv_a

end main
