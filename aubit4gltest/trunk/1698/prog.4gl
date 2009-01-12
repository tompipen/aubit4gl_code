{**
 * @file
 * Pause without parameters
 * @process TEST_GENERAL
 *}
 
main
start report repo1 to "out"
output to report repo1(1)
finish report repo1
end main
report repo1(i)
define i int
format
    on every row
        print "i=", i
    page trailer
        pause 
end report
