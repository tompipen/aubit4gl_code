define f1 date
define f2 date
define numero integer
main
	prompt "Introduzca una fecha:" for f1
	prompt "Introduzca una fecha posterior a "+f1+":" for f2
	if f1>=f2 
		display "He dicho una fecha 'posterior'.\n"
	end if
	display "Entre "+f1+" y "+f2+" hay "+(f2-f1)+" dias.\n"
   prompt "Introduce un numero: " for numero
   display f1+" + "+numero+" = "+(f1+numero)
end main
