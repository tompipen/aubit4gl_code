{**
 * @file
 * agregate in reports where parameters = variable
 * @process TEST_GENERAL
 *}
 
database test1
main
define i,j,a int
start report rep1
for i = 1 to 5
    for j = 1 to i
        output to report rep1(i, j)
    end for
end for
finish report rep1
end main

report rep1(i,j)
define i,j,a int

output page length 1 top margin  0 bottom margin 0
order external by i
format
on last row
   print "i=1, count=",count(*) where i = 1
   print "i=2, count=",count(*) where i = 2
   print "i=3, count=",count(*) where i = 3
   print "i=4, count=",count(*) where i = 4
   print "i=5, count=",count(*) where i = 5
   for a = 1 to 5
       print "a=",a using "<<", ", count=", count(*) where i = a
   end for
end report
