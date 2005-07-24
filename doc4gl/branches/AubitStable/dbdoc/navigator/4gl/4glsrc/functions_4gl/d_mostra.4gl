
#  ============================================================================
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#
#  Divisao de desenvolvimento e producao de software.
#
#  Autor: Sergio Alexandre Ferreira
#
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : dmostra, versao informix 4GL.
#  ---------------------------------------------------------------------------
#  DESCRICAO: Dmostra versao 4gl. Vai-se tentar por as novas caracteristicas,
#             como as opcoes de posicionamento, scroll horizontal, etc.
#             Desiste-se da ideia de tornar o dmostra multi-listagem, pois essa
#             e a funcao de um spooler.
#             Pode-se no entanto optimizar, por forma a deixar a informacao
#             de inicializacao nas temporarias, ou em memoria.
#
#  ---------------------------------------------------------------------------
#  FUNCOES:
#   dmostra() -
#
#  ---------------------------------------------------------------------------
#  FORMS:
#
#  REPORTS:
#
#  NOTAS:
#         Falta mudar erros para dialog(s)
#         Falta meter impressoes com d_sp(s)
#    Porting para versoes anteriores: Tirar free(s).
#
#  ============================================================================

#  ============ Variaveis globais ao modulo ===============================  #
globals "4glsrc/functions_4gl/d_libglob.4gl"

define
	left_count      smallint,        # Coordenada do sitio onde esta o primeiro
												# caracter a visualizar.
	total_ecrans   smallint,        # Numero de ecrans existentes.
	pag_curr        smallint,        # Pagina de texto corrente.
	texto           array[17] of char(256),# Array onde esta o texto.
	disp_line       char(78),
	num_str         char(3),
	idx_num_str     smallint,
	linha_texto     char(256),
		mylinha char(256),
	sp_line char(78),
	pa_ecrans array[2000] of integer  # Seek da ecrans

#  ============ Funcoes operacionais =======================================  # 


#  ============================================================================ 
#   Main para testes
#  ============================================================================ 
{
main
	 call d_mostra("/etc/group")
end main
}




#  ============================================================================ 
#  Executa o dmostra com ficheiro enviado como argumento.
#  ============================================================================ 
function d_mostra(nm_fl)
{}
    define
		 nm_fl char(64),
		 dumm  char(10),
		 ja_imp char(1),
		 grp_impressao integer,
       stat smallint,
       comm_editar smallint
   
   whenever error call d_erro
	let ja_imp = "N"
	let comm_editar = false
	#call d_scr_init("Visualizacao de listagens")
	if not init_dmostra(nm_fl) then
		sleep(2)
		return
	end if
	open window w_dmst_menu at 1, 1 with 2 rows, 78 columns
	call show_current_page()
	menu "OPCOES"
		command "Posicionar" "Da acesso ao menu de posicionamento de ecrans"
			call menu_posicionamento()
		command key(CONTROL-U)           # Up scroll     - vi like
			call pag_ant()
		command key(CONTROL-Y)           # One line down - vi like
		command key(">")                 # Next page     - ged like
			call pag_seg()
		command key("<")                 # Previous page - ged like
			call pag_ant()
		                                 # First page    - ged like
		                                 # Last page     - ged like
		command key("0")
			call gotch_number(0)
		command key("1")
			call gotch_number(1)
		command key("2")
			call gotch_number(2)
		command key("3")
			call gotch_number(3)
		command key("4")
			call gotch_number(4)
		command key("5")
			call gotch_number(5)
		command key("6")
			call gotch_number(6)
		command key("7")
			call gotch_number(7)
		command key("8")
			call gotch_number(8)
		command key("9")
			call gotch_number(9)
		command "Imprimir" "Imprime o relatorio"
			# O ultimo e' a remocao e nao o deve fazer.
			LET grp_impressao=d_sp_set_novo_grupo("","Listagem",today,d_user,
																"","N","N")
         call d_sp_nova_listagem(grp_impressao,nm_fl,"Listagem")
         call d_sp_print_grupo(grp_impressao)
			let ja_imp = "S"
												   # Scroll horizontal para a esquerda.
		command "Esquerda" "Move a listagem para a esquerda, no ecran"
			call shift_left()
													# Scroll horizontal para a direita.
		command "Direita" "Move a listagem para a direita, no ecran"
			call shift_right()
		command "Copiar"
			call d_copia(nm_fl)
		command "Editar"
			call d_edit_file(nm_fl)
			let comm_editar = true
			exit menu
		#command key(CONTROL-D)           # Down scroll   - vi like
			#call pag_seg()
		command "Fim" "Sai do utilitario de visualizacao"
			if ja_imp = "S" then
            call d_sp_rm_grupo(grp_impressao,"N")
			end if
			exit menu
	end menu

display "FIXME: missing function close_file"
exit program (7)

	#let stat = close_file()
        if stat != 0 then
           error "Impossivel fechar ficheiro, status: ", stat
        end if
	close window w_border
	close window w_text
	close window w_dmst_menu
	close window w_pag

	# Quando acaba a edicao, tem que mostrar o ficheiro alterado ,PVP
	if comm_editar then
		call d_mostra(nm_fl)
	end if	
end function


#  ============= Funcoes de inicializacao ===================================  # 

#  ============================================================================ 
#  Faz as iniializacoes necessarias ao funcionamento do dmostra e da listagem
#  corrente. Devera estar optimizado por forma a so as efectuar se necessario.
#  ============================================================================ 
function 	 init_dmostra(nm_fl)
{}
    define
		 nm_fl     char(64),
		 i , stat smallint,
		 pos_no_fl integer                          # Posicao no ficheiro.
   
	call space_line()
	let left_count  = 1
	let pag_curr    = 1
	let i = 2
	let total_ecrans=1   # So para debug
	let idx_num_str = 1
	let num_str = "   "

	let pa_ecrans[1]=0

display "FIXME: missing function open_file"
exit program (7)

#   let stat=open_file(nm_fl)
	if stat != 0 then
		error "Impossivel abrir o ficheiro ", nm_fl, ", erro N.o ", stat
		return false
	end if

	while (1=1)                            # Ler ftell para o array

display "FIXME: missing function d_page_tell"
exit program (7)
#		let pa_ecrans[i] = d_page_tell(17)
		if pa_ecrans[i] = -1 then
			initialize pa_ecrans[i] to null
			exit while
		else
		   let total_ecrans = total_ecrans+1
		end if
		if i >= 2000 then
			error "So se admitem 2000 ecrans"
			exit while
		end if
		let i = i + 1
	end while

	open window w_border at 4,2 with 19 rows, 78 columns attribute(border)
   call fgl_drawbox(1,78,2,1)
	display " " at 2,1
	display " " at 2,78
	display "Ecran" at 1, 58
	display "de" at 1, 70
	display total_ecrans using "####" at 1, 74 attribute(reverse,blue)
   OPEN WINDOW w_pag AT 4, 66 WITH 1 ROWS,4 COLUMNS 
	display pag_curr using "####" at 1, 1 attribute(reverse,blue)
	open window w_text at 6,2 with 17 rows, 78 columns

	return true
end function


#  ======================================================================
#  Mostra a pagina corrente.
#  ======================================================================
function 	 show_current_page()
{}
	define 
		i,auxLeftCount smallint,
		auxPag integer

	current window is w_pag
	display pag_curr using "####" at 1, 1 attribute(reverse,blue)
	current window is w_text
	let auxPag=pa_ecrans[pag_curr]
	
	
display "FIXME: missing function d_fseek"
exit program (7)
#	call d_fseek(auxPag)
	# Experimentar com dois for(s)
	{
   for i = 1 to 17 
	   call get_text()
		let texto[i] = linha_texto clipped
		if texto[i] is not null then
		   let auxLeftCount=left_count+78 
		   let disp_line=texto[i][left_count,auxLeftCount]
		else
			let disp_line=sp_line
		end if
		display disp_line at i, 1
	end for
	}
	call put_linha(1)
	call put_linha(2)
	call put_linha(3)
	call put_linha(4)
	call put_linha(5)
	call put_linha(6)
	call put_linha(7)
	call put_linha(8)
	call put_linha(9)
	call put_linha(10)
	call put_linha(11)
	call put_linha(12)
	call put_linha(13)
	call put_linha(14)
	call put_linha(15)
	call put_linha(16)
	call put_linha(17)
	current window is w_dmst_menu
end function

function 	 put_linha(i)
{}
   define
		i,auxLeftCount smallint
	   call get_text()
		let texto[i] = linha_texto clipped
		if texto[i] is not null then
		   let auxLeftCount=left_count+78 
		   let disp_line=texto[i][left_count,auxLeftCount]
		else
			let disp_line=sp_line
		end if
		display disp_line at i, 1
end function

function 	 space_line()
{}
   define 
		i smallint
	
	for i = 1 to 78
		let sp_line[i] = " "
	end for
end function


#  ======================================================================
#  Vai ao ficheiro buscar o texto para a ecrans corrente.
#  A bronca pode ser do return do lerlinha.
#  ======================================================================
function 	 get_text()
{}
	define
		stat smallint

display "FIXME: missing function lerlinha"
exit program (7)
#	call lerlinha(256)
#	returning linha_texto,stat

	let linha_texto = linha_texto clipped

	case
	   when stat = -3 
		   initialize linha_texto to null
	end case

end function


#  ======================================================================
#  Actualiza o contador de ecrans que esta no cimo do ecran.
#  ======================================================================
{
function 	 actualiza_ecran()
	current window is w_border
   display "Pag ",pag_curr using "<<<" , 
			  " de ", total_ecrans using "<<<" at 2, 50
end function
}



#  ======================================================================
#  Posiciona na ecrans seguinte.
#  ======================================================================
function 	 pag_seg()
{}

	if pag_curr < total_ecrans then
      let pag_curr = pag_curr + 1
		call show_current_page()
	else
		error "Ja esta no ultimo ecran"
	end if
end function



#  ======================================================================
#  Posiciona na oagina anterior.
#  ======================================================================
function 	 pag_ant()
{}

	if pag_curr > 1 then
      let pag_curr = pag_curr - 1
		call show_current_page()
	else
		error "Ja esta no primeiro ecran"
	end if
end function

#  ======================================================================
# Funcao que faz o input da ecran por posicionamento directo
#
#  Entradas:
#   corrente -> Variavel com a ecran corrente
#   conta -> Numero de ecran existentes na listagem
#
#  Saidas
#   corrente -> variavel com a nova ecran
#  ======================================================================
FUNCTION PosicionamentoDirecto()
{}
   DEFINE
		str_pag char(4),
		curr_pag smallint

   LET int_flag = FALSE

	current window is w_pag
   OPTIONS
     ACCEPT KEY F1

	# Se se meter letras da erro.
   PROMPT " " FOR str_pag
      ON KEY(ESC)
         LET curr_pag=1
   END PROMPT
	let curr_pag = str_pag
   OPTIONS
      ACCEPT KEY ESC

   IF int_flag THEN
      LET int_flag = FALSE
		return
   END IF
   IF curr_pag IS NOT NULL AND curr_pag >= 1 AND curr_pag <= total_ecrans THEN
     LET pag_curr=curr_pag
   END IF

END FUNCTION 


#  ======================================================================
#  Shifta o ficheiro n caracteres a esquerda.
#  ======================================================================
function 	 shift_left()
{}
	define 
		i smallint,
		quant smallint

	let quant = num_str
	if quant <= 0 OR quant is null then let quant=1 end if
	current window is w_text
	case 
		when left_count-quant > 0 
	      #if left_count > 1 then
	      let left_count = left_count - quant
         for i = 1 to 17 
			   #let linha_texto=texto[i]
		      let disp_line=texto[i][left_count,left_count+78]
		      display disp_line at i, 1
	      end for

		when left_count = 1
		   error "Esta tudo a esquerda"

		otherwise
	      let left_count = 1
         for i = 1 to 17 
			   #let linha_texto=texto[i]
		      let disp_line=texto[i][left_count,left_count+78]
		      display disp_line at i, 1
	      end for
	end case
	#let num_str = "   "
	let idx_num_str = 1
	current window is w_dmst_menu
end function


#  ======================================================================
#  Shifta o ficheiro n caracteres a direita.
#  ======================================================================
function 	 shift_right()
{}
	define 
		i smallint,
		quant smallint

	current window is w_text
	let quant = num_str
	if quant <= 0 OR quant is null then let quant=1 end if
	if quant+left_count+78 < 256 then
	#if left_count+78 < 256 then
	   let left_count = left_count + quant
      for i = 1 to 17 
			#let linha_texto=texto[i]
		   let disp_line=texto[i][left_count,left_count+78]
		   display disp_line at i, 1
	   end for
	else
		error "Esta tudo a direita"
	end if
	#let num_str = "   "
	let idx_num_str = 1
	current window is w_dmst_menu
end function



#  ======================================================================
#  Armazena o numero que se recebeu na variavel num_str
#  ======================================================================
function 	 gotch_number(num)
{}
   define 
		num smallint

   if idx_num_str >= 3 then
		let idx_num_str = 1
	else
		let num_str[idx_num_str,idx_num_str] = num
		let idx_num_str = 1 + idx_num_str 
	end if
end function



#  ======================================================================
#  Menu vertical de posicionamento no ecran.
#  ======================================================================
function   menu_posicionamento()
{}
  define
	  ans smallint

  # Menu vertical 
  while 1=1
    let ans = menuVertCasc(3,12,6,"","","","Anterior (<)",
										            "Seguinte (>)",
										            "Primeiro (F4)",
										            "Ultimo   (F3)",
										            "Directo  (F2)",
				                              "Fim",
										             "","","","","","","",
														 "","","","","","")
    case
	   when ans = 1
		  call pag_ant()
		  exit while
	   when ans = 2
		  call pag_seg()
		  exit while
	   when ans = 3    # Primeiro ecran
	     let pag_curr = 1
		  call show_current_page()
		  exit while
	   when ans = 4    # Ultimo ecran.
	     let pag_curr = total_ecrans
		  call show_current_page()
		  exit while
	   when ans = 5    # Posicionamento directo.
		  call PosicionamentoDirecto()
	     call show_current_page()
		  exit while
	   when ans = 6    # Fim.
		  exit while
		when ans = 0
		  exit while
    end case

  end while
end function



