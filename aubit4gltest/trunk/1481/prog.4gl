{**
 * @file
 * Describe the test here
 * @process TEST_GENERAL
 *}
 
#if you need to use a database, use "test1"
#database test1
main
define a char(30)
define b record
	c char(20)
end record
let a[1][2]="He"
let b.c[1][1]="He"


end main
