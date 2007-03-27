{**
 * @file
 * MID 953
 * Error status number -366.
 * The scale exceeds the maximum precision specified..
 * @process TEST_GENERAL
 *}
 
database test1

main
define w_d decimal(12,3), w_file char(20)
let w_file = "out.expected"
{! let w_file = "out" }
start report repodec to w_file
let w_d = 0.000
output to report repodec(w_d)
finish report repodec
end main

report repodec(s_d)
define s_d decimal(12,3)
output left margin 0 bottom margin 0 top margin 0 page length 1

# order required to use temp table
order by s_d

format on every row print "OK"
end report
