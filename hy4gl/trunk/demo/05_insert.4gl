database hy4gl_test

extern random() integer /* La funcion 'random' es de C y devuelve un entero */

function ran()
	return random()
end function

main
	define reg record like prueba.*
	define i integer
	define valor integer
	let i=0
	
	open window w1 at 5,10 with 10 rows, 30 columns
		attribute (white over red, border)
		title "Prueba nº 5"

	display "Inserto 500 elementos dentro de un 'BEGIN TRANSACTION'"
		at 3,2
	begin transaction
	while i<500
		let valor = ran()
		insert into prueba values(valor)
		display "Valor nº "+i+"= "+valor at 5,5
		let i=i+1
	end while
	commit transaction

	display "Inserto 50 elementos sin 'BEGIN TRANSACTION'"
		at 3,2
	let i=0
	while i<50
		let valor = ran()
		insert into prueba values(valor)
		display "Valor nº "+i+"= "+valor at 5,5
		let i=i+1
	end while

	close window w1

end main
