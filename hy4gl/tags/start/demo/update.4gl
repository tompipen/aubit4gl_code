/* Demo de UPDATE TABLE */
database hy4gl_test

function numero()
   return 10
end function

main
define maximo integer
   /* Busco el numero más grande de la tabla prueba */
   begin transaction
      declare c cursor for select max(num) from prueba
      open cursor c
      fetch c into maximo
      close cursor c
   commit transaction
   display "El numero más grande es: ",maximo using "###,###,###,##&"
   update prueba set num=-999 
{   where num=maximo}
end main
