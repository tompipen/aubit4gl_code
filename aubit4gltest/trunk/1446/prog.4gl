database test1

main
define
   cnt_p       smallint,
   tabname_p   char(30)
define p integer
let cnt_p = 0

start report rpt1 to "test9.out"

for p=1 to 1000
	let tabname_p="table_",p using "<<<<"
   let cnt_p = cnt_p + 1
   output to report rpt1(tabname_p)

   if cnt_p = 54 then
      exit for
   end if
end for

finish report rpt1

end main

report rpt1(tabname_p)
define
   tabname_p   char(30)

  output
      top margin     2
      bottom margin  2
      left margin    0
      right margin   80
      page length    66


format
   page header
      print column   1, "Header 1"
      print column   1, "Header 2"

      skip 1 line

      print column   1, "Header 3"

on every row
   print column   1, tabname_p

on last row
   need 4 lines
   skip 2 line
   print column   1, "trailer 1"
   print column   1, "trailer 2"

end report
