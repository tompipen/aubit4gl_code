define tecla char

define r record
   codigo char(10)
   nombre char(20)
   direccion char(20)
   chequeo integer
   fecha date
end record

extern _4GLerror() integer

function ver_registro()
  open window w2 at 5,5 with 10 rows, 60 columns
     attribute (white over red, border)
     display "Nombre: ",r.nombre
     display "Código: ",r.codigo
     display "Dir: ",r.direccion
     display "Check: ",r.chequeo
     display "Fecha: ",r.fecha
     prompt "" for char tecla
  close window w2
end function

main
define a integer
define tecla char
define sw_cancelado integer
   let sw_cancelado=0
   let a=1
   let r.codigo="1010"
   let r.nombre="David Prieto"
   let r.direccion="Via Paisajista"
   let r.chequeo=0
   let r.fecha="17-08-1998"
   
   open window w1 at 10,5 with 13 rows, 70 columns
      attribute(border)
      create form f_prueba
      display form f_prueba
      input by name r.*
         on key(F1)
            call ver_registro()
         on key(F2)
            exit input
         on button aceptar
            exit input
         on button cancelar
            let sw_cancelado=1
            exit input
      end input
      if sw_cancelado=0 then
         call ver_registro()
      end if
   close window w1
end main

form f_prueba
   input codigo from 5,5 to 5,14
   input nombre from 6,5 to 6,45 attribute (white over red,bright)
   input direccion from 7,5 to 7,45 attribute (white over red)
   check chequeo at 9,20 attribute (cyan over black, bright)
   input fecha from 9,30 to 9,40 attribute (yellow,bright)
   button aceptar at 10,10 attribute (cyan over blue,bright)
   button cancelar at 10,30 attribute (cyan over blue)
end form

