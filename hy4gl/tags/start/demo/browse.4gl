database hy4gl_test
define r record like prueba.*
define tecla char
main
	open window w at 10,10 with 10 rows, 70 columns
		attribute (white over red, bright, border)
	declare c local cursor for select * from prueba
	browse c into r.num
      from 1,5 to 7,20
        title "titulo"
		display r.num using "##,###,###,###.##"
	on key(13)
      open window w2 at 2,30 with 5 rows,40 columns
         attribute(white over red,bright)
		display "Has elegido el numero ",r.num
      prompt "" for char tecla
      close window w2
   else
      display "no encuentro registros"
      prompt "" for r.num
	end browse
	close window w
end main
