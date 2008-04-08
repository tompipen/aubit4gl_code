database test1

main
define
   cnt      smallint,
   chr      char(01),
   smint    smallint

create temp table taba
( col1   char(01),
  col2   integer
) with no log

insert into taba values ("A",100000)
insert into taba values ("B",200000)

let cnt = 0

whenever error continue

declare curs cursor for
 select * from taba

foreach curs into chr, smint
   let cnt = cnt + 1
end foreach
if sqlca.sqlcode=0 then
	display "Bad - it should have errored.."
	exit program 1
else
	display "Found an error - which is good for a change!"
	exit program 0
end if
display cnt

end main
