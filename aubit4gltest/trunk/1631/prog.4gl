{**
 * @file
 * return for PAUSE not working when a MENU is active 
 * @process TEST_GENERAL
 *}
 
main
menu "Test"
    command "report"
        call reposcr()
    command "end"
        exit menu
end menu
end main

function reposcr()
define i int
start report repos_list 
for i = 1 to 3
    output to report repos_list(i)
end for
finish report repos_list
end function

report repos_list(r)
define r int
output left margin 0 top margin 0 bottom margin 0 page length 5
format
    on every row
       print r
    page trailer
        pause "enter to continue"
end report
