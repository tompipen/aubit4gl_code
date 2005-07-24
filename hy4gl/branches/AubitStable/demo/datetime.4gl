{/******* Programa para probar los tipos DATE, TIME, DATETIME, INTERVAL **/}

main
   define fecha DATE
   define hora TIME
   define momento DATETIME
   define cadena char(100)
   define numero integer
   
   let fecha=today()
   let hora=time()

   let momento=fecha+hora
   display "Hoy es: ",fecha
   display "Son las: ",hora
   display "Ahora mismo es: ",momento
   display "--------------------------------------"

   let fecha="12-10-1492"
   let numero=today()-fecha

   prompt "Han pasado "+numero using "#,###,##&"+" dias desde el 12 de Octubre de 1472" for char cadena
end main
