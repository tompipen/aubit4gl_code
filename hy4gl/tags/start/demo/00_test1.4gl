define a integer
define c integer
define cadena char(30)

define reg record
	a integer
   c integer
	/* Registros dentro de registros */
	fecha record
		dia integer
		mes integer
		anno integer
	end record /* El problema es que por ahora, solo los defino, luego
			no los puedo usar... O:-) */
end record

define d char(20)

/* Definiciones de funciones externas (de la librería de C) */
extern getenv() char

main
	open window w2 at 1,1 with 22 rows, 78 columns attribute border, 
		yellow over blue,bright

	open window w1 at 5,5 with 15 rows, 20 columns 
		attribute yellow over cyan,bright, border

	display "hola" attribute cyan over blue
	let reg.a=5
	let a=1
	let d=3  

	while a<100
		display a,"eee", getenv("HOME")+d,"\r\n"
		let a=a+1
	end while

	display "Eso es todo, amigos" at 10,3 attribute cyan over blue
	/* Un comentario en C
		{Dentro, un comentario de los de Pascal}
		/* Y otro comentario  de C */
		Aqui termina el comentario de C
	*/
	display "Acaba de pasar la prueba de los comentarios anidados"
	close window w2
	display "yata!"
end main
