database test1

main
define
   cnt        smallint,
   scratch    char(200),
   u_rec   record
      col1   char(10),
      col2   char(10)
   end record

create temp table foo
( col1    char(10),
  col2    char(10)
) with no log

insert into foo values ('01',null)

let scratch = "update foo",
                " set col2 = ?",
              " where col1 = ?"

prepare upd_stmt from scratch

let u_rec.col1 = "01"
let u_rec.col2 = "  "

execute upd_stmt using u_rec.col2, u_rec.col1

let cnt = 0
select count(*) into cnt from foo
 where col1 = '01'
   and col2 is null

if  cnt = 1 then
   display "col2 is still null - BAD"
   exit program 1
else
   display "col2 no longer null - GOOD"
   exit program 0
end if

end main
