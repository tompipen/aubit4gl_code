{ Demostracion de los bucles 'for' }

main
define i date
   /* La variable que avanza puede ser de tipo numerica o fecha */
   for i = today() to today()+20
      if i=today()+2
         display "me salto el dia de pasado mañana, ",i
         continue for
      end if
      if i=today()+15
         exit for
      end if
      display "El dia ",i," será ",dow(i)
   end for
end main
