{**
 * @file
 * REPORT: Page trailer with last IF THEN ELSE with print, misplaced output
 * @process TEST_GENERAL
 *}
 
main
define i int
start report pageno_repo to "out"
for i = 1 to 50
    output to report pageno_repo(i)
end for
finish report pageno_repo
end main

report pageno_repo(i)
define i int

output top margin 0 bottom margin 0 left margin 0 page length 30

format
    page header
        print "header"
        print "___________"

    on every row
        NEED 5 lines
        print "every", i

    page trailer
        print "___________"
        print "<test 1676>"
        if i mod 2 = 0 then
            print "<<<<"
        else
            print ">>>>"
        end if
end report
