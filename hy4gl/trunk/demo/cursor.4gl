{/* Programilla para hacer pruebas con cursores */}

database idamar

main
define r record like arti.*
define e integer

   begin transaction

   declare c cursor for "select * from arti"
   /* Abro el cursor y muestro el primer registro */

   open cursor c

   fetch c into r.*
   create form articulos
   display form articulos
   display by name r.codigo,r.nombre,r.pvp1
   
   menu horizontal 
      command "Anterior", "Retrocede un registro"
         fetch previous c into r.*
            display by name r.codigo,r.nombre,r.pvp1

      command "Siguiente", "Avanza un registro"
         display "1"
         fetch next c into r.*
         display "2"
         display by name r.codigo,r.nombre,r.pvp1

   end menu

   close cursor c
   commit transaction
end main

form articulos
   input codigo from 11,1 to 11,10
   input nombre from 13,1 to 13,50
   input pvp1 from 14,1 to 14,20
end form
