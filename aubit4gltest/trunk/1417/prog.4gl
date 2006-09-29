database test1
main
start report order_repo to "order.out"
output to report  order_repo(2, 1)
output to report  order_repo(5, 4)
output to report  order_repo(2, 3)
output to report  order_repo(3, 4)
output to report  order_repo(5, 7)
output to report  order_repo(1, 4)
finish report order_repo
end main

report order_repo(m, n)
define m, n int
output
   page length 1 bottom margin 0 top margin 0 left margin 0
order by m desc, n asc
format
   on every row
      display m, n
end report
