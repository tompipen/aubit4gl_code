database test1
main
start report order_repo to "out"
output to report  order_repo(2.00)
output to report  order_repo(5.00)
output to report  order_repo(4.00)
output to report  order_repo(3.00)
output to report  order_repo(6.00)
output to report  order_repo(1.00)
finish report order_repo
end main

report order_repo(m)
define m money
output
   page length 1 bottom margin 0 top margin 0 left margin 0
order by m desc
format
   on every row
      print m
end report
