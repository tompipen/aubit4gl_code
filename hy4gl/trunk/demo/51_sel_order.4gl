database hy4gl_test

define r record like prueba.*

main
define i integer
define tecla char

   begin transaction
	declare c cursor for select * from prueba order by num
    let i=0
    foreach c into r.num
		display r.num
        if i>100 then
           prompt "Pulse 'n' para terminar" for char tecla
           if tecla="n" or tecla="N" then
              exit foreach
           else
              display "Has pulsado ",tecla
           end if
        end if
        let i=i+1
    end foreach
    commit transaction
end main
