
define
       msgresp char(40)
main
   while true
     clear form
     let msgresp=maxmsg("U",1001,"")
   end while
end main

function maxmsg(dummy1,dummy2,dummy3)
  define
         dummy1 char(1),
         dummy2 smallint,
         dummy3 char(10)

      return dummy3
end function


