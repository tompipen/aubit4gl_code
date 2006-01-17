main
start report r1 to "r1.out" with page length=1
output to report r1 ("ABC")
finish report r1
end main


report r1(a)
define a integer
format every row
end report

