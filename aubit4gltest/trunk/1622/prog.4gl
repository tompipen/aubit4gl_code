{**
 * @file
 * MID 941
 *
 * SQL update a money with an arithmetic operation, not all decimals
 * taked.
 * @process TEST_GENERAL
 *}
 
database test1
main
define w_tica decimal(12,6),
       w_fa, w_fb, w_a money
create temp table tablemoney (fa money, fb money)
insert into tablemoney values (13012.41, 0)
let w_tica = 10.8510
update tablemoney set fb = fa * w_tica
select * into w_fa, w_fb from tablemoney
let w_a = w_fa * w_tica
# w_fb and w_a should be the same
display w_fa, w_fb, w_a
end main
