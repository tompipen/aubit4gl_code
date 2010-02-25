
main
if aclfgl_file_exists("r1.pdf") then
code
	unlink("r1.pdf");
endcode
end if
start report r1 to "r1.pdf"
output to report r1 ("Hello World iii")
#output to report r1 ("World Hello iii")
finish report r1
if aclfgl_file_exists("r1.pdf") then
	exit program 0
else
	exit program 1
end if
end main

pdfreport r1(lv_str)
define lv_str char(20)
define lv_b byte
define lv_c char(20)
format

on every row 

 	locate lv_b in file "mylogo.jpg"
	let lv_c="mylogo.jpg"


	print  "A1";
	PRINT IMAGE "mylogo.jpg" AS JPEG SCALED BY 0.1
	skip to 2 inches
	print  "A2";
	PRINT IMAGE lv_c  AS JPEG SCALED BY 0.2
	skip to 4 inches
	print  "A3";
	PRINT IMAGE lv_b  AS JPEG SCALED BY 0.4

end report
