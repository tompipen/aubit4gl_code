database hy4gl_test

main
define comando char(255)
define numero,resultado integer
   open window w1 at 1,1 with 10 rows, 70 columns
      attribute(cyan over blue,border)
     prompt "Introduce un comando SQL: " for comando
     exec_sql comando into resultado
     display "El primer campo devuelto es: ",resultado
     prompt "" for char comando
   close window w1
end main
