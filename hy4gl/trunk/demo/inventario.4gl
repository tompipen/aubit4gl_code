/*  Programa de inventario. */
database hy4gl_test

define tecla char
define raya char(80)

function proveedores()
	display ""
end function

function mensaje(cadena)
define cadena char(80)
define longitud integer
define tecla char
   let longitud=length(cadena)
   if longitud>78 then
      let longitud=78
   end if
   open window w_msg at 10,(40-longitud/2) with 3 rows, longitud+2 columns
      attribute (white over red, bright, border)
      title "Atención"
      prompt cadena for char tecla
   close window w_msg
end function

function listados()
	define r record like arti.*
   define i integer
	declare c1 local cursor for select * from arti order by ws_desc
	let raya="========================================================================================"
   start report r1
   let i=0
   open window w_rep at  4,0 with 20 rows, 80 columns
		attribute(cyan over blue, border)
      title "Listado de articulos"
      
   display "Generando listado de articulos agrupado por modelo..."
	foreach c1 into r.*
      let i=i+1
		output to report r1(r.*)
      display "Leyendo..."+i at 10,10
		attribute(cyan over blue, border)
	end foreach
	finish report r1
   call mensaje("Se ha generado el archivo 'inventario.out' con el listado.")
   close window w_rep
end function

report r1(ra)
define ra record like arti.*
define i integer
define contador integer

/* Se puede enviar la salida a impresora directamente con:
   output report to pipe "lpr -Plp"

   O por correo con:
   output report to pipe "mail usuario"
   
   De momento, genero un fichero con la salida.
*/
output report to "inventario.out"
   page width 80
   page heigth 64
   
format

first page header
   print "Primera pagina del listado"
   print ""
   print "Listado de pruebas...    "+today()+" Pag:"+pageno
	let i=0

page header
	print raya
    print "Listado de pruebas...    "+today()+" Pag:"+pageno
	print raya

before group of ra.ws_desc
    print ""
	print "Nuevo grupo: "+ra.ws_desc
    print "------------------------------------------------"
    let contador=0
        
on every row
   print i+".-"+ra.ws_desc[1,40]+" "+ra.ws_marca[1,20]+" "+
      ra.ws_usuario[1,20]
	let i=i+1
   let contador=contador+1


on last row
   display "Total de lineas: "+lineno

end report


function sub_inventario(situacion)
define situacion like arti.ws_situacion
define r record like arti.*
	open window w at 10,10 with 10 rows, 50 columns
		attribute white over blue, border, bright
		title "Los de la zona "+situacion
	declare c2 local cursor for select * from arti where ws_situacion=situacion
   declare c3 local cursor for select * from arti where ws_usuario=r.ws_usuario
	browse c2 into r.*
     from 2,2 to 7,40
     display r.ws_desc[1,20]+" "+r.ws_usuario[1,20]
	on key("a")
      open window w3 at 5,5 with 10 rows, 40 columns
         attribute(border, white over blue)
      browse c3 into r.*
         display r.ws_usuario+r.ws_desc
      on key ("a")
         display ""
      end browse
      close window w3
	end browse
	close window w
end function

function articulos()
define r record like arti.*
define salir integer
define query char(8192)

   let salir=0

	declare c local cursor for select * from arti order by ws_situacion,ws_desc
	open window w_br at 4,0 with 20 rows, 80 columns
		attribute(cyan over blue, border)
   display "[Intro] Consulta articulo        [a] Consulta zona" at 17,10

	browse c into r.*
      from 0,0 to 15,79
      title "Sit.        Descripcion"
	display r.ws_situacion+" "+r.ws_desc

	 on key ("a")
		sub_inventario(r.ws_situacion)

	 on key (13)
		open window w1 at 10,10 with 10 rows, 55 columns
			attribute white over red, border
      create form f_arti
      display form f_arti
      
      display ""
		display "Nombre: "
		display "Usuario: "
      display "Fecha de compra "
      display "Valor adquisicion: "

      display "[F1] Aceptar  [F8] Cancelar"
      let salir=0
      input by name r.ws_desc,r.ws_usuario,r.ws_compra,r.ws_valor
         on key (F1)
            /* La sentencia 'update' no está todavia implementada 
            let query="update arti set ws_desc='"+r.ws_desc+
               "', ws_usuario='"+r.ws_usuario clipped+
               "',ws_compra='"+r.ws_compra+
               "',ws_valor="+r.ws_valor+" where ws_familia='"+
                  r.ws_familia clipped+
               "' and ws_codigo="+r.ws_codigo
            exec_sql query */ /* Ya si: 07-03-1999 */
            update arti set ws_desc=r.ws_desc,
               ws_usuario=r.ws_usuario,
               ws_compra=r.ws_compra,
               ws_valor=r.ws_valor
            where ws_familia=r.ws_familia
               and ws_codigo=r.ws_codigo
            let salir=1
            exit input
         on key(F8)
            exit input
      end input

		close window w1
      if salir=1 then
         exit browse
      end if
      
   on key (F8)
      exit browse

	end browse
	close window w_br
end function

form f_arti
   input ws_desc from 2,10 to 2,40
   input ws_usuario from 3,10 to 3,30
   input ws_compra from 4,20 to 4,30
   input ws_valor from 5,20 to 5,40
end form


main
	open window w_menu at 0,0 with 4 rows, 80 columns
		attribute (yellow over black, bright, border)

	menu 
		attribute black over white ; white over black
		command "Articulos", "Mantenimiento de articulos"
			articulos()
		command "Proveedores","Mantenimiento de proveedores (no implementado)"
			proveedores()
		command "Listados", "Lanza listados de inventario"
			listados()
		command "Salir","Salir"
			exit menu
	end menu
	close window w_menu
end main


