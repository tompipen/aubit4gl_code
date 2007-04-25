{**
 * @file
 * INTO clause in declare cursor and NOT in FETCH -> segfault
 * @process TEST_GENERAL
 *}
 
database test1
main
define w_b char(2)
create temp table pru (b char(2))
insert into pru values ("ok")
declare c_cur cursor for select b into w_b from pru 
open c_cur
fetch c_cur 
free c_cur
display w_b
end main
