{/* DEMO del 'whenever error' */}
database hy4gl_test
define tecla char

function ver_error(numero)
define numero integer
   display "ERROR: ",numero
   prompt "" for char tecla
end function

main
define r record like prueba.*
   let r.num=0
   whenever error continue
   display "Hago el primer insert con  whenever error continue..."
   insert into prueba values (1)
   if status!=ok then
      prompt "ATENCION! El insert ha fallado y lo he capturado en el programa" for char tecla
   end if
   whenever error call ver_error(status)
   display "Hago el siguiente insert con whenever error call ver_error(status)"
   insert into prueba values (1)
   if status!=ok then
      prompt "ATENCION! El insert ha fallado y lo he capturado en el programa" for char tecla
   end if
   whenever error stop
   display "Hago el siguiente insert con whenever error stop"
   insert into prueba values (1)
   if status!=ok then
      prompt "ATENCION! El insert ha fallado y lo he capturado en el programa" for char tecla
   end if
   prompt "" for char tecla
end main
