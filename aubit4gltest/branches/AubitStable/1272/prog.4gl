main

   define l_out char(500)
   define l_time char(5)

   let l_out = "Hello World\n"
   let l_out = l_out clipped, "NewLine\n"
   let l_out = l_out clipped, "NewLine2\n"

   display l_out

   let l_time = time

   if l_time matches "[0-9][0-9]:[0-9][0-9]" then
	display "xx:xx"
   else
	display l_time
   end if

end main
