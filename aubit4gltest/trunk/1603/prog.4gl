{**
 * @file
 * Printing extendiend ascii characters -> column position failing
 * @process TEST_GENERAL
 *}
 
#if you need to use database, use "test1"
#database test1
main

#It is recomended that you use temp tables
#	create temp table abc(x char(10), y char(10))

#Use 	
#	call aclfgl_dump_screen("out")
# To generate screen dump to be compared against expected screen representation
# Default diff expect file names "out" and  "out.expected"

define w_file, w_a CHAR(40)

let w_file = "out.expected"
{! let w_file = "out" }
start report repoascii_repo to w_file
let w_a = "This is a normal line"
output to report repoascii_repo(w_a)
let w_a = "This is not, feliz a", ascii 165, "o nuevo!"
output to report repoascii_repo(w_a)
let w_a = "This is again normal"
output to report repoascii_repo(w_a)
finish report repoascii_repo
end main

report repoascii_repo(r_a)
define r_a char(40)

output
left margin 0 bottom margin 0 top margin 0 page length 1

format
   on every row
       print COLUMN  5, "col5",
             COLUMN 10, r_a,
             COLUMN 60, "col60"
end report
