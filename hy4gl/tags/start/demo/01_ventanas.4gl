function di_cadena(cadena)
define cadena char(50)
	display cadena
end function

/* Funcion main */
main
define a integer
define b integer
define c char(39)
define i integer
define x integer
define y decimal
define tiempo integer
define cadena char(255)
	let y=10
	let y=11.5
	let x=1

   /* Prueba de una llamada a una funcion, con una expresion como parametro
      ademas pruebo tambien los comentarios con varias lineas... */
	di_cadena("a"+"b"+"c"+1+"d")

   /* Imprimo los parametros recibidos: */
   display "Has llamado al programa con "+arg_count+" parametros."
   for i=0 to arg_count
      display arg_val(i)
   end for

   delay 2
   /* Abrimos una ventana de color azul con el borde en amarillo brillante */
	open window w at 1,1 with 5 rows, 70 columns
		attribute(yellow over blue,border,bright)
		title "hola"

   display "linea 0" at 0,0
   display "linea 1" at 1,0

   delay 2

   /* meto codigo en C 'embebido' */
   .c /* Aqui empieza el bloque de C */
      int i; /* Puedo definir variables en el codigo en c!! */
      wprintw(curwin,"eeeeeeeeeee!!! Esto esta en C\n");
      i=8;
      wprintw(curwin,"La variable 'i' es interna del bloque de C y vale %d\n",i);
      update_panels();
      doupdate();
      refresh();
   c. /* Fin del bloque de C */

   /* Y esperamos dos segundos */
	delay 2
   
	open window w1 at 4,x with 13 rows, 40 columns 
		attribute(white over red,bright,border)

	/* Concatena cadenas facilmente */
   /* Y hace asignaciones múltiples: En una asignacion calculo el valor 
      de dos variables. (util para hacer swap: let a,b=b,a) */
   let c, b = "hola, "+"mundo "+95+2, 500
   display c
   delay 2
   display "1500 iteraciones en 4GL" at 1,1

   .c /* Esto lo hago en C por curiosidad. Podria hacerlo con variables 
      	del tipo 'datetime' de 4GL */
      tiempo=time(NULL);
   c.
   
	while (b<2000)
		display "leidos: ",(b*2) using "##,##&" at 3,5 attribute(white over red)
		display "procesados: ",b at 5,5
		display "quedan: ",(2000-b)
		let b=b+1
	end while

   .c
       mvwprintw(curwin,7,7,"Tiempo transcurrido: %d segundos",time(NULL)-tiempo);
       update_panels();
       doupdate();
       getch();

    /* Ahora hago el mismo bucle de antes, pero en C */
       wclear(curwin);
       b=500;
       mvwprintw(curwin,1,1,"1500 iteraciones en C");
       tiempo=time(NULL);
       do
       {
          mvwprintw(curwin,3,5,"leidos: %d",b*2);
          mvwprintw(curwin,5,5,"Procesados: %d",b);
          mvwprintw(curwin,6,5,"quedan: %d",2000-b);
          update_panels();
          doupdate();
          b++;
       } while (b<2000);
       mvwprintw(curwin,7,7,"Tiempo transcurrido: %d segundos",time(NULL)-tiempo);
       update_panels();
       doupdate();
       getch();
    c.
	let x=1
	open window ww at 2,20 with 5 rows,50 columns
		attribute(yellow over magenta,border)
		title "Vaya colores..."
	while x<=35
		move window w1 to 4,x
		let x=x+1
	end while
	open window w3 at 10,20 with 10 rows,30 columns
		attribute(border,cyan over blue)
		title "Ventana con titulo"
	let b=1
	while b < 3
		current window w1
		delay 1
		current window w3
		delay 1
		let b=b+1
	end while
	close window w3
	close window w1
	display "Eso es todo, amigos" at 10,40 attribute(cyan over blue)
	
	delay 3
	close window w
end main

