/* Prueba de coma flotante */

define tecla char(1)
extern rand() integer

main
define i decimal
define n integer
	open window w at 5,5 with 10 rows, 50 columns
		attribute white over blue, border
	let n=1
	let i=0
	while n<2000
		let i=i+(rand()/1000000)
		display i
		let n=n+1
	end while
	prompt "hecho" for char tecla
	close window w
end main
