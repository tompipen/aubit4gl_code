main
start report r1 to "r1.out"
output to report r1(1)
output to report r1(2)
output to report r1(3)
finish report r1
end main

report r1 (a)
define a smallint
format

on last row
	print "Sum = ", sum(a)
	print "AVG = ", avg(a)
	print "MIN = ", min(a)
	print "MAX = ", max(a)
	print "count=", count(*)
	print "% > 1 = ", percent(*) where a>1
end report
