
database test1
main
define lv_a record
	a char(20),
	b integer
end record
define c integer



create temp table xaa (
	a char(20),
	b integer
)


prepare p1 from "insert into xaa values(?,?)"
declare c1 cursor for p1
open c1
let lv_a.a="HELLO"
let lv_a.b=1
put c1 from lv_a.*
close c1
display "Insert 1"

declare c2 cursor for insert into xaa values(lv_a.a,lv_a.b)
open c2
let lv_a.a="World"
let lv_a.b=2
put c2 #from lv_a.*
close c2
display "Insert 2"

let c=0
declare c3 cursor for select * from xaa where b>c order by b
foreach c3 into lv_a.*
	display lv_a.a," ",lv_a.b
end foreach


end main
