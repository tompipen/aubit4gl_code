database hy4gl_test
main
define num integer
   select max(num) into num from prueba
      where 5000<prueba.num
   if status=notfound then
      display "error"
   else
      display num
   end if
   prompt "" for num
end main

