database hy4gl_test

define numero like prueba.num
define pedir integer
define tecla char(1)
define r record
   i integer
end record

main
   
   open window w1 at 0,0 with 10 rows, 70 columns
      attribute(cyan over blue, bright)
      title "Demo de select...where"
	prompt "Introduce un nº" for pedir
        let r.i=pedir
	select * into numero from prueba where num > r.i
	display numero
	prompt "pulse una tecla..." for char tecla
   close window w1
end main
