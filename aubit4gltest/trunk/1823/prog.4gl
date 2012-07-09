{**
 * @file
 * Options for open session
 * @process TEST_GENERAL
 *}
 
database test1
main

define w_t1a varchar(10)
define w_t1b char(10)
let w_t1a = "test1"
let w_t1b = "test1"
open session s1 to database test1
display "ok1"
open session s2 to database "test1"
display "ok2"
open session s3 to database w_t1a
display "ok3"
open session s3 to database w_t1b
display "ok4"
end main
