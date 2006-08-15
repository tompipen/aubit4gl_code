main


start report r1 to convertible
output to report r1 (1,2)
finish report r1

start report r1 to convertible
output to report r1 (1,2)
finish report r1  converting to "myfile1.pdf" AS "PDF" using "layout1"


start report r1 to convertible
output to report r1 (1,2)
finish report r1  converting to "myfile2.pdf" AS "PDF"  # uses default layout

start report r1 to convertible
output to report r1 (1,2)

finish report r1  converting to many
        convert report r1 to "orig.output" AS "SAVE"  # Special - for use with layout_engine
        convert report r1 to "myfile3.pdf" AS "PDF"  # uses default layout
        convert report r1 to "myfile4.txt" AS "TXT"  # uses default layout
free report r1

end main


report r1(a,b)
define a,b integer
format
on every row
print a," ",b
end report

