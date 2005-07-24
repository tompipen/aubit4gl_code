/*** Primera prueba de menus.... */

define prn char(30)

function gestion()
	open window wgest at 10,20 with 10 rows, 60 columns
		attributes(white over red, bright,border)
		title "Tipo de papel"

	menu "formato" horizontal
		command "A4 con membrete vertical","La hoja derechita..."
			let prn=prn+"vert"
			exit menu
		command "A4 con membrete apaisado","La hoja de lado..."
			let prn=prn+"apa"
			exit menu
	end menu

	close window wgest
end function

function aviso(cadena)
define cadena char(50)
define tecla char(1)
	open window w_aviso at 10,10 with 10 rows, 40 columns
		attribute bright, white over red, border
		title "Atención"
	display cadena at 5,20
	prompt "" for char tecla
	close window w_aviso
end function

main
	open window wmenu at 5,0 with 10 rows, 40 columns
		attribute cyan over blue, border
		title "Colas de Impresión"

	menu "Impresoras" vertical
   attributes (blue over cyan);(cyan over blue)
		command "Local","Impresora conectada al ordenador"
			let prn="local"
		command "Gestion","Impresoras del dpto de Gestion"
			let prn="gest"
			gestion()
		command "Fin","Fin de seleccion de impresora"
			exit menu
		on key(F1)
			aviso("Pulsa F1")
	end menu

	close window wmenu
	display prn
end main

