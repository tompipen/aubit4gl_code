main

open window win1 at 2,3 with 24 rows, 80 columns
   attribute (border, red)
open form test62 from "test62"
display form test62

call do_input()

end main

function do_input()
define
   i_rec   record
      col1   date,
      col2   date
   end record,
   scrline   smallint

initialize i_rec.* to null

input by name i_rec without defaults

display i_rec.col1
display i_rec.col2

if i_rec.col1 != i_rec.col2 then
   exit program 1
end if

exit program 0

end function
