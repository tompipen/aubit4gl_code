database test1
main
define lv_r integer

create temp table xx (x integer)
declare c1 cursor for
select * from xx

open c1
fetch c1 into lv_r
display sqlca.sqlerrd[3]

insert into xx values(1)

open c1
fetch c1 into lv_r
display sqlca.sqlerrd[3]

end main
