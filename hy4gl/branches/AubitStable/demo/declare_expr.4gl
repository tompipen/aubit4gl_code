/* Programa de prueba del declare con expresiones generadas
    en tiempo de ejecucion */

database hy4gl_test

main
define i integer
define seleccion char(512)
define r record like prueba.*
   let seleccion="select * from prueba"
   begin transaction
   declare c cursor for seleccion
   foreach c into r.* 
      display r.num
   end foreach
   commit transaction
end main
