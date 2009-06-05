{**
 * @file
 * Partial assigment in a varchar, segfault at insert
 * @process TEST_GENERAL
 *}
 
database test1
main
define a_c1, a_c2 char(40),
       a_v1, a_v2 varchar(255)

create temp table errtbl (v varchar(255))
let a_c1 = "a"
let a_c2 = "b"
let a_v1[1,40] = a_c1
let a_v1[41,80] = a_c2
display a_v1
insert into errtbl (v) values (a_v1)
select v into a_v2 from errtbl
if a_v1 <> a_v2 then exit program 1 end if
end main
