{**
 * @file
 * Can't print ASCII 0 (NULL) in a report
 *
 * used por some printers escape sequences
 *
 * @process TEST_GENERAL
 *}
 
main
define w_file char(30)
let w_file = "out.expected"
{! let w_file = "out" }
start report reponull to w_file
output to report reponull()
finish report reponull
end main

report reponull()
output
left margin 0 top margin 0 bottom margin 0 page length 1
format
    on every row
        print "text file"
        print "here comes ", ascii 0, " a null"
end report
