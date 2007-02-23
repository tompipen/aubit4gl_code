{**
 * @file
 * Check the use of NULL values in before/after groups
 * @process TEST_GENERAL
 *}
 
#if you need to use database, use "test1"
database test1
main

#It is recomended that you use temp tables
#	create temp table abc(x char(10), y char(10))

#Use 	
#	call aclfgl_dump_screen("out")
# To generate screen dump to be compared against expected screen representation
# Default diff expect file names "out" and  "out.expected"

define a, b, c int,
     w_file char(30)

let w_file = "out.expected"
{! let w_file = "out" }
start report groupnull_repo to w_file
let a = null
for b = 1 to 2
  for c = 1 to 2
     output to report groupnull_repo(a, b, c)
  end for
end for
finish report groupnull_repo
end main

report groupnull_repo(a, b, c)
define a, b, c int

output left margin 0 top margin 0 bottom margin 0 page length 1

order by a, b, c

format
    before group of a
        print column  1, "before a=", a
    before group of b
        print column 11, "before b=", b
    before group of c
        print column 21, "before c=", c
    on every row
        print column 31, "a=", a, ",b=", b, ",c=", c
    after group of c
        print column 21, "after c=", c
    after group of b
        print column 11, "after b=", b
    after group of a
        print column  1, "after a=", a

end report
