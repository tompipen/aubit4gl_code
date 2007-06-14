{**
 * @file
 * skip of page trailer, on filled page
 * @process TEST_GENERAL
 *}
 
main
define i int
start report pageno_repo to "out"
for i = 1 to 10
    output to report pageno_repo(i)
end for
finish report pageno_repo
end main

report pageno_repo(i)
define i int

output top margin 0 bottom margin 0 left margin 0 page length 10

format
    page header
        print "header"
    on every row
        print "a", i
    page trailer
        skip 2 lines
        print "<test 1646>"
end report
