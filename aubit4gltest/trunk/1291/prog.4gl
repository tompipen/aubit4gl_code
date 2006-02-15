{**
 * @file
 * Decribe the test here
 * @process TEST_GENERAL
 *}
 
database test1
main
define lv_a char(1)

select 'y' into lv_a from tab1 
having count(*) >= 1

end main
