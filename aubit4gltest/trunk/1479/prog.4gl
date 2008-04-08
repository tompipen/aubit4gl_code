database sysmaster

main


start report report1 to "out"

call do_report()

finish report report1

end main

function do_report()
define
   mny_p   decimal(4,2)

let mny_p = 50.0
output to report report1(1,mny_p)
let mny_p = 51.0
output to report report1(1,mny_p)
let mny_p = 52.0
output to report report1(2,mny_p)

end function

{------------------------------------------------------------------------}
{ REPORT: REPORT1                                                        }
{------------------------------------------------------------------------}
report report1(typ, mny_r)
define
   typ     smallint,
   mny_r   decimal(4,2)

output
   left margin 0
   right margin 158
   top margin 1
   bottom margin 2
   page length 66

order by typ

format

on every row
   print mny_r using "#&.&"

after group of typ
   print "group ", typ using "<<", " sum ", group sum(mny_r) using "##&.&&"

on last row
   print "report sum ", sum(mny_r) using "##&.&&"

end report
