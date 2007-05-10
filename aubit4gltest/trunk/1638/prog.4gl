{**
 * @file
 * report sum() take last value (posible modified), not the original value
 * sent to the output to report
 * @process TEST_GENERAL
 *}
 
database test1

main
define i int
start report repos_list TO "out"
for i = 1 to 3
    output to report repos_list(i)
end for
finish report repos_list
end main

report repos_list(r)
define r int
output
left margin 0 top margin 0 bottom margin 0 page length 4
order by r
format
   on every row
      if r = 1 then let r = 10 end if
      print column 10, r using "####"
      if r = 3 then let r = 300 end if
   on last row
      print "sum", column 10, sum(r) USING "####"
end report
