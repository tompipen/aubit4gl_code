#start of source
main
 define p_cutoff_hhmm char(5)
 
 if (current hour to minute) <= "00:00" then
 	display "something wrong 1"
       exit program 1
 else
 	display "ok"
 end if
 
 let p_cutoff_hhmm = current hour to minute
 if p_cutoff_hhmm <= "00:00" then
 	display "something wrong 2"
       exit program 2
 else
 	display "ok"
 end if

 if "00:00" >=(current hour to minute)  then
 	display "something wrong 1"
       exit program 1
 else
 	display "ok"
 end if
 
 let p_cutoff_hhmm = current hour to minute
 if "00:00">= p_cutoff_hhmm  then
 	display "something wrong 2"
       exit program 2
 else
 	display "ok"
 end if



end main
