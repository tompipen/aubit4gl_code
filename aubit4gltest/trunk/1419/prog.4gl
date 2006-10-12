database test1

main
define i int
for i = 1 to 3
     call repos_call(i)
end for
end main

function repos_call(p)
define p int
start report repos_list to "a"
    output to report repos_list(p)
finish report repos_list
end function

report repos_list(r)
define r int
output
top margin 0 bottom margin 0 page length 1
order by r
format
on every row
   print r
end report
