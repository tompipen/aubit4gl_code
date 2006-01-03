main
	start report r1 to "r1.out"
	output to report r1 ("Mike Aubury")
	finish report r1

	start report r2 to "r2.out"
	output to report r2 ("Mike Aubury")
	finish report r2

	start report r3 to "r3.out"
	output to report r3 ("Mike Aubury")
	finish report r3

end main

report r1(lv_name)
define lv_name char(20)
format
on every row
print "Hello ",lv_name
print file "letter.txt"
end report

report r2(lv_name)
define lv_name char(20)

output 
	right margin 80
format
on every row
print "Hello ",lv_name
print file "letter.txt"
end report

report r3(lv_name)
define lv_name char(20)

output 
	right margin 80
format
on every row
print "Hello ",lv_name
print file "letter.txt";
end report


