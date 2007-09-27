database sysmaster

main
define
   tab_p      char(10),
   q_txt      char(200)

let tab_p = "TEST"

open window win1 at 2, 2 with form "test39" attribute (border)

construct q_txt on systables.tabname, systables.version
   from formonly.tabname, formonly.version

before construct
   display tab_p to formonly.tabname


after field tabname
   if field_touched(tabname) then
	display "Unexpected..."
      	exit program 1
   else
	display "Expected..."
      	exit program 0
   end if

end construct
 
close window win1

display q_txt

end main
