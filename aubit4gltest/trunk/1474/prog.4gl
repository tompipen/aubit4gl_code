main
define a integer
start report r1 to "r1.out"
for a=1 to 300000
	output to report r1 (a)
end for
finish report r1
end main

report r1 (a)
define a integer
format
on last row
	print count(*)  using "#######&"
end report

