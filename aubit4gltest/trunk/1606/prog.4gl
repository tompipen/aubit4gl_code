{**
 * @file
 * Using a INTERVAL variable as a report parameter, when exist a ORDER BY
 * requiring a temporarytable, the generated code to create the table has 
 * a syntax error
 *
 * Mantis bug 907
 *
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

define w_int interval day to minute
start report repoint_repo to "out"
output to report repoint_repo(w_int)
finish report repoint_repo
end main

report repoint_repo(s_int)
define s_int interval day to minute
output left margin 0 bottom margin 0 top margin 0 page length 1
order by s_int
format on every row print "ok"
end report
