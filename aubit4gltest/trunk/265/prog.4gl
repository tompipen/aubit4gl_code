main 
 define dt1, dt2 datetime year to second 
 
 let dt1 = current 
 let dt2 = current + 1 units day 

 if dt2 > dt1 then 
 	display "true" 
 else 
 	display "false" 
 end if 
 if dt2 = dt1 then 
 	display "true" 
 else 
 	display "false" 
 end if 
 if dt2 < dt1 then 
 	display "true" 
 else 
 	display "false" 
 end if 



 let dt1 = current 
 let dt2 = current - 1 units day 

 if dt2 > dt1 then 
 	display "true" 
 else 
 	display "false" 
 end if 
 if dt2 = dt1 then 
 	display "true" 
 else 
 	display "false" 
 end if 
 if dt2 < dt1 then 
 	display "true" 
 else 
 	display "false" 
 end if 

end main 
