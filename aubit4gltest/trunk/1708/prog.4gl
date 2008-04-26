database cassens

globals 
  
   define  t_dttm1  datetime year to fraction(4),
           t_dttm2  datetime year to fraction(4) 
end globals 


main 

  #### This one works.

  let t_dttm1=current

  if t_dttm1 is not null and t_dttm1 != " " then 
     display "***t_dttm1 is not null***"
  else 
     display "***t_dttm1 is null***"
  end if 

  #### This one doesn't  ????

  initialize t_dttm2 to null

  if t_dttm2 is not null and t_dttm2 != " " then 
     display "***t_dttm2 is not null***"
  else 
     display "***t_dttm2 is null***"
  end if 
    
end main
