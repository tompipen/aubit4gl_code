database test1
main
         define n1, n2, n3 integer
         let n1 = 100
         let n2 = 123
         let n3 = null
         start report rpt to 'out'
         output to report rpt ("GROUP 1",n1)
         output to report rpt ("GROUP 2",n2)
         output to report rpt ("GROUP 2",n3)
         finish report rpt
 end main
 
 report rpt(group_id, n)
         define group_id char(10),
                 n integer
define b integer
 
         order external by group_id
         format
         page header
                 print "TEST GROUP SUM"
 
         on every row
                 print "Line: ", group_id, " ",n
         after group of group_id
                 print "Group Sum: ", group sum(n)  using "####&"
                 print "Group count: ", group count(*) using "####&"
                 print "Group min: ", group min(n) using "####&"
                 print "Group avg: ", group avg(n) using "####&.&&"
                 print "Group max: ", group max(n) using "####&"
 
         on last row
                 print "Grand total: ", sum(n) using "####&"
 
                 print "grand count: ", count(*) using "####&"
                 print "grand min: ", min(n) using "####&"
                 print "grand avg: ", avg(n) using "####&.&&"
                 print "grand max: ", max(n) using "####&"
 end report
