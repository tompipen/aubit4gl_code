 main 
 define dt1, dt2,dt3 date 

--!call aclfgl_setenv("DBDATE","mdy4/")
 let dt1 = "01/01/2005" 
 let dt2 = dt1 - 1 units day 
 let dt3=mdy(12,31,2004)

 if dt3=dt2 then display dt1," ",dt2, " This is ok" else display dt1," ",dt2, " This is wrong" end if

 let dt1 = "03/01/2005" 
 let dt2 = dt1 - 1 units day 
 let dt3=mdy(2,28,2005)

 if dt3=dt2 then display dt1," ",dt2, " This is ok" else display dt1," ",dt2, " This is wrong" end if

 let dt1 = "01/02/2005" 
 let dt2 = dt1 - 1 units day 
 let dt3=mdy(1,1,2005)
 if dt3=dt2 then display dt1," ",dt2, " This is ok" else display dt1," ",dt2, " This is wrong" end if

 let dt1 = "12/10/2004" 
 let dt2 = dt1 - 9 units day 
 let dt3=mdy(12,1,2004)


 if dt3=dt2 then display dt1," ",dt2, " This is ok" else display dt1," ",dt2, " This is wrong" end if


 let dt1 = "12/03/2004" 
 let dt2 = dt1 - 2 units day + 1 units day 
 let dt3=mdy(12,2,2004)
 if dt3=dt2 then display dt1," ",dt2, " This is ok" else display dt1," ",dt2, " This is wrong" end if
 end main 
