database cassens

globals 
 define 
   t_dt  datetime year to fraction(2),
   c_dt  char(22)
end globals


main 

  let c_dt="2007-09-21 12:00:00.00"

  display "c_dt is ",c_dt

 #sleep 5

  let t_dt=extend(c_dt, year to fraction(2))  ### This works on hpkcc, not on ca4ae.

  let t_dt=c_dt                               ### This works on ca4ae.

  display "t_dt is ",t_dt 

end main
