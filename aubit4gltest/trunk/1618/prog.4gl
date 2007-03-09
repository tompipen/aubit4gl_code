{**
 * @file
 * Trying to control page numbers odd/even, used for duplex printing
 * pageno is not updated in the before group
 *
 * Mantis bug 934
 * @process TEST_GENERAL
 *}

main
define w_i, w_j int,
       w_file char(30)

let w_file = "out.expected"
{! let w_file = "out" }
start report repolin_repo to w_file
for w_i = 0 to 29
    let w_j = w_i / 10
    output to report repolin_repo(w_i, w_j)
end for
finish report repolin_repo
end main

report repolin_repo(s_i, s_j)
define s_i, s_j int
output left margin 0 bottom margin 0 top margin 0 page length 12
order external by s_j
format   
   page header 
       print column  1, "j=", s_j using "#&",
             column 30, "page:", pageno using "##"
       print

   before group of s_j
       skip to top of page
       if (pageno mod 2) = 0 then
           print "page left blank"
           skip to top of page
       end if
       
   on every row 
      print "j=", s_j using "#&", ", i=", s_i using "#&"
end report
