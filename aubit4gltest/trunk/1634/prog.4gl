{**
 * @file
 * select of Varchar(x) with a value of length x, last char is removed
 * @process TEST_GENERAL
 *}
 
database test1

main
define w_a varchar(10)
create temp table pruvch (a varchar(10))
insert into pruvch values ('1234567890')
select a into w_a from pruvch 
display ">", w_a, "<"
end main
