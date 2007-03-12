{**
 * @file
 * MID 940
 *
 * lineno contains last lie printed of previous page after new page.
 * I-4GL contains 0 (zero)
 * @process TEST_GENERAL
 *}
 
database test1
main
define w_i, w_j int,
       w_file char(30)

let w_file = "out.expected"
{! let w_file = "out" }
start report repolin_repo to w_file
for w_i = 1 to 2
    for w_j = 1 to 12
        output to report repolin_repo(w_i, w_j)
    end for
end for
finish report repolin_repo
end main

report repolin_repo(s_i, s_j)
define s_i, s_j, a_line int, w_how char(4)
output left margin 0 bottom margin 2 top margin 1 page length 12
order external by s_i
format   
   page header 
       print column  1, "i=", s_i using "#&",
             column 30, "page:", pageno using "##"
       print "------------"

   before group of s_i
       skip to top of page

   on every row 
      let a_line = lineno
      if (lineno mod 2) = 0 then let w_how = "even" 
      else let w_how = "odd"
      end if
      print "j=", s_j using "#&", ", line=", a_line using "#&", " ", w_how
end report
