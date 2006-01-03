main 
 define xdttm datetime year to second 
 
 display "Test 1:" 
 let xdttm = "2004-08-01 11:15:00" 
 call abc(xdttm) 
 display "Test 2:" 
 let xdttm = "2004-09-01 11:15:00" 
 call abc(xdttm) 
 
 display "Test 3:" 
 let xdttm = "2004-08-30 11:15:00" 
 call abc(xdttm) 
 
 let xdttm = "2004-09-01 00:01:00" 
 display "Test 4:" 
 call abc(xdttm) 
 
 display "Test 5:" 
 let xdttm = "2004-08-30 23:59:00" 
 call abc(xdttm) 
 
 end main 
 
 function abc(xdttm) 
 
 define xdttm datetime year to second, 
 xcvt_dttm datetime year to second 
 
 display "Input Time: ", xdttm 
 let xcvt_dttm = xdttm + 1 units hour  + 1 units minute 
 display "Adding time:", xcvt_dttm 
 if xcvt_dttm is null then 
 display "This is null." 
 end if 
 
 let xcvt_dttm = xdttm - 1 units hour - 1 units minute 
 display "Subtracting time:", xcvt_dttm 
 if xcvt_dttm is null then 
 display "This is null." 
 end if 
 
 end function 
