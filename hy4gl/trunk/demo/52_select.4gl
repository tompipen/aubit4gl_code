database hy4gl_test

define r record like prueba.*

main
	declare c local cursor for select * from prueba
	foreach c into r.*
		display r.num
	end foreach
end main
