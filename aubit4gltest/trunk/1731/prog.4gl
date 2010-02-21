main
define mes char(2)

let mes = "3 "    # NOT OK
if mes matches "[0123456789 ][0123456789 ]" then 
   display "matchesTest: mes = \"", mes, "\" test OK" 
else 
   display "matchesTest: mes = \"", mes, "\" test not OK, but in I4GL OK" 
end if

let mes = ""      # NOT OK
if mes matches "[0123456789 ][0123456789 ]" then 
   display "matchesTest: mes = \"\" test not OK, but in I4GL OK" 
else 
   display "matchesTest: mes = \"\" test OK" 
end if

let mes = "  "      # NOT OK
if mes matches "[0123456789 ][0123456789 ]" then 
   display "matchesTest: mes = \"", mes, "\" test OK" 
else 
   display "matchesTest: mes = \"", mes, "\" test not OK, but in I4GL OK" 
end if

let mes = " 2"    # OK
if mes matches "[0123456789 ][0123456789 ]" then 
   display "matchesTest: mes = \"", mes, "\" test OK" 
else 
   display "matchesTest: mes = \"", mes, "\" test not OK, but in I4GL OK" 
end if

let mes = "33"    # OK
if mes matches "[0123456789 ][0123456789 ]" then 
   display "matchesTest: mes = \"", mes, "\" test OK" 
else 
   display "matchesTest: mes = \"", mes, "\" test not OK, but in I4GL OK" 
end if




end main
