/* Programa para probar el tipo de datos 'interval' */


main
define inter interval
define d date
define t time
define dt datetime
define tecla char
   prompt "Introduce tu fecha de nacimiento: " for d
   prompt "Introduce tu hora de nacimiento: " for t
   let dt=d+t
   if dt>datetime() then
      display "Venga, hombre... ¿como vas a nacer despues de hoy?"
      prompt "" for char tecla
   else
      display "Naciste en el instante: ",dt,"\n"
      let inter=datetime()-dt
      display "Tienes ",inter," horas"
   end if
end main
