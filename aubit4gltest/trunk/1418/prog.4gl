database test1

define reg1 record
          a1    char(12),
          a2 char(40),
          dt  datetime year to second
        end record
main

create temp table subsi02 (a1 char(12), a2 char(40), dt datetime year to 
second)
insert into subsi02 values ("AA", "AAAAAAAAAAA", "2006-01-01 01:01:01")
insert into subsi02 values ("BB", "BBBBBBBBBBB", "2006-02-02 02:02:02")
insert into subsi02 values ("CC", "CCCCCCCCCCC", "2006-03-03 03:03:03")
start report rep1 to file "out"
declare c1 cursor for
   select a1,a2,dt from subsi02
foreach c1 into reg1.*
   output to report rep1(reg1.a1,reg1.a2,reg1.dt)
end foreach
finish report rep1
end main

report rep1(a1,a2,dt)
define a1 char(12),
       a2 char(40),
       dt datetime year to second

output top margin 0 left margin 0 bottom margin 0 page length 1

order by a1

format
 on every row
    print column 01,a1,
          column 15,a2,
          column 50,dt
end report
