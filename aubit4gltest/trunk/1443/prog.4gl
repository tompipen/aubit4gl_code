main
define
   p_sel record
      beg_date   date,
      end_date   date,
      ldgrp      char(01)
   end record


call startlog("Blah")

   open window sel_w at 2, 2 with form "examp1" attribute (border)

   input by name p_sel.beg_date, p_sel.end_date, p_sel.ldgrp
           without defaults

   after field beg_date
		call errorlog("after p_sel.beg_date")

   after field end_date
		call errorlog("after p_sel.end_date")

   after field ldgrp
		call errorlog("after p_sel.end_date")

   before field beg_date
		call errorlog("before p_sel.beg_date")

   before field end_date
		call errorlog("before p_sel.end_date")

   before field ldgrp
		call errorlog("before p_sel.end_date")

   after input 
		call errorlog("after input")
end input
if p_sel.beg_date!="1/1/1" or p_sel.end_date!="1/1/1" or p_sel.ldgrp!="A" THEN
	exit program 1
else
	exit program 0
end if

end main
