main
define a integer

start report r1 to "out"
for a=1 to 100
output to report r1 (a)
end for
finish report r1

end main


report r1 (a)
define a integer
output
	top of page "^L"
	bottom margin 0
format
page header
print "PAGE HEADER"
skip 1 line
on every row
print "a=",a
end report
