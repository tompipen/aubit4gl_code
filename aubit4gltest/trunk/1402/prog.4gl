database test1

main
define
   q_txt    char(200),
   n_vinmove   record
      vin10  Char(10),
      vin    char(10)
   end record

open window win1 at 2,3 with 10 rows, 40 columns
   attribute (border, red)
open form test1 from "test1"
display form test1

defer interrupt

construct by name q_txt on vinmove.vin, vinmove.vin10

after construct
   if int_flag != 0 then
      exit construct
   end if
   if not field_touched(vin, vin10) then
	exit program 0
      continue construct
   end if
end construct

exit program 1

if int_flag != 0 then
   let int_flag = 0
   display by name n_vinmove.vin10, n_vinmove.vin
   message "should see this message"
   return
   message "should NOT see this message"
end if

end main
