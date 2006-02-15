 
define c1,c2,c3 integer
 
main
 defer interrupt
 options accept key control-q
 
 

 open window w1 at 06,03 with form 'eraseme'
 attribute (border, form line first,comment line last,
 prompt line last,message line last-1)
 

 let c1 = 1
 let c2 = 1
 let c3 = 1
 

 while true
  input by name c1,c2,c3 without defaults
   after field c1
    if c1 = 999 then
     error '999 IS A NOT ALLOWED VALUE'
     next field c1
    end if
 
   after field c2
    if c2 = 999 then
     error '999 IS A NOT ALLOWED VALUE'
     next field c2
    end if
 
   after field c3
    if c3 = 999 then
     error '999 IS A NOT ALLOWED VALUE'
     next field c3
    end if
 
   on key (esc, interrupt)
    exit while
  end input
 end while

  if int_flag=true then
	display "Failed"
	exit program 1
  end if

  if c1!=123 or c2!=123 or c3!=123 then
	display "Failed"
	exit program 1
  end if
  display "OK"
  exit program 0
 
 close window w1
end main
#######################################################################
 
 
