database test1

main
define
   knt      smallint,
   col2_p   char(04)

whenever error continue
drop table foofoo
whenever error stop 

create table foofoo
( col1   integer,
  col2   char(4) )

insert into foofoo values (3,'art')

declare curs cursor for
 select col1 from foofoo
  where col1 = 3

open curs
fetch curs into col2_p

let knt = SQLCA.sqlerrd[3]

display knt
if knt !=1 then
	exit program 1
end if

whenever error continue
drop table foofoo
whenever error stop 

exit program 0
end main
