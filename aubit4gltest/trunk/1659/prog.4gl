{**
 * @file
 * PRINT FILE in a loop (more than 1,000) fails with :
 * ==18037== Warning: invalid file descriptor 1019 in syscall open()
 * Err:Program ./prinfile.exe stopped at 'prinfile.4gl', line number 22.
 * Error status number -30101.
 * Unable to open PRINT FILE file.
 * @process TEST_GENERAL
 *}
 
main
define w_file char(40)
define i int
let w_file = "out.expected"
{! let w_file = "out" !}
start report repo1 to file w_file
for i = 1 to 1100
    output to report repo1(i)
end for
finish report repo1
end main

report repo1(i)
define i int
output
  page length 10 left margin 5 top margin 3 bottom margin 3

format
  on every row
     skip to top of page
     print "i=",i
     print file "prinfile.txt"
end report
