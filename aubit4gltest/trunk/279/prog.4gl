main 
 define 
 sdate date, 
 edate date, 
 edatec char(10), 
 mnth smallint, 
 yr smallint 
 
 
 let sdate = mdy(05,15,2004)
 
 let mnth = month(sdate) 
 let yr = year(sdate) 
 let edatec = mnth using "&&", "/01/", yr using "&&&&" 
 let edate = edatec 
 display "edate=",edate using "dd/mm/yyyy"
 let edate = extend(edate)
 display "edate=",edate using "dd/mm/yyyy"
 let edate=edate + 1 units month 
 display "edate=",edate using "dd/mm/yyyy"
 let edate = edate - 1 units day 
 display "edate=",edate using "dd/mm/yyyy"

 let edate = edatec 
 let edate = extend(edate) + 1 units month - 1 units day 
 display "edate=",edate using "dd/mm/yyyy"

end main 
