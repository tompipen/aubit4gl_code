#  ============================================================================ 
#
#  Copyright 1995 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#  Rua da Prata 166 4.o Dto
#  1100 LISBOA
#                                                        
#  Autor: Sergio Ferreira
#                                                        
#  Data de criacao: Sun Apr 05 22:05:34 LIS 1998
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : Form CGI que apresenta os utilitarios para
#                  seleccao e analise de problemas
#  ---------------------------------------------------------------------------
#  DESCRICAO: 
#
#  ---------------------------------------------------------------------------
#  FUNCOES: 
# 
#  ---------------------------------------------------------------------------
#  FORMS: 
#
#  REPORTS: 
#
#  NOTAS:
#
#  ============================================================================ 


main
   call f_bde_util()
end main




function f_bde_util()
{}
   define
		starterr smallint,
		NomeBd   char(20)

	let NomeBd = arg_val(1)
   call	icgi_mimetype("text/html")
   let	starterr	=	icgi_start()
   display "<html>"
   display "<head>"
   display "<title>BD Esquema - Utilitários</title>"
   display "</head>"

	display "<BODY BGCOLOR='#F38C00' TEXT='#000000'",
			  "LINK='#880000' VLINK='#660000' ALINK='#F38000'>"

   display "<CENTER><BR>"
   
	display "<TABLE BORDER=0 WIDTH='100%' CELLSPACING=0 CELLPADDING=6 ",
			  "BGCOLOR='#000000'>",
			  "<TR> <TD>" 
	
   display "<TABLE BORDER=0 CELLPADDING=0 CELLSPACING=0 ",
			  "BGCOLOR='#CC3300' WIDTH='100%'>",
			 "<TR><TD ALIGN=CENTER>"


   display "<table border='0' width='100%'>"
   display "<tr>"
   display "<td><p align='left'>BD Esquema</p>"
   display "</td>"
   display "<td><p align='right'>Utilitários</p>"
   display "</td>"
   display " </tr>"
   display "</table>"
   
   display "<form method='POST'>"
   display "<table border='0' width='100%'>"
   display    "<tr>"
   display       "<td>Base de dados</td>"
   display       "<td><input type='text' size='20' name='base_de_dados'",
					  "value='", NomeBd clipped, "'></td>"
   display       "<td>&nbsp;</td>"
   display    "</tr>"
   display    "<tr>"
   display       "<td>Descrição da tabela</td>"
   display       "<td><select name='TabTipoBusca' size='1'>"
   display          "<option selected value='comeca'>Começa por</option>"
   display          "<option value='contem'>Contem</option>"
   display          "<option value='acaba'>Acaba com</option>"
   display          "<option value='nulo'>Não está preenchido</option>"
   display       "</select></td>"
   display       "<td><input type='text' size='20' name='T1'></td>"
   display    "</tr>"
   
   display    "<tr>"
   display       "<td>Descrição da coluna</td>"
   display       "<td><select name='TabTipoBusca' size='1'>"
   display             "<option selected value='comeca'>Começa por</option>"
   display             "<option value='contem'>Contem</option>"
   display             "<option>acaba</option>"
   display             "<option value='nulo'>Não está preenchido</option>"
   display       "</select></td>"
   display       "<td><input type='text' size='20' name='T1'></td>"
   display    "</tr>"

   display    "<tr>"
   display       "<td>Chave Primária</td>"
   display       "<td>Tem <input type='radio' checked"
   display       "name='R1' value='V1'>Não tem<input type='radio'"
   display       "name='R1' value='V2'>"
   display       "</td>"
   display       "<td>&nbsp;</td>"
   display    "</tr>"
   
   display    "<tr>"
   display       "<td>&nbsp;</td>"
   display       "<td>&nbsp;</td>"
   display       "<td>&nbsp;</td>"
   display    "</tr>"

   display    "<tr>"
   display       "<td>&nbsp;</td>"
   display       "<td><p align='center'><input type='reset' name='Reset'"
   display       "value='Reset'></p>"
   display       "</td>"
   display       "<td><p align='center'><input type='submit'"
   display       "name='consulta' value='Consulta'></p>"
   display       "</td>"
   display    "</tr>"

   display "</table>"
   display "</form>"

	display "</TD></TR>"
	display "</TABLE>"
	display "</TD></TR>"
	display "</TABLE>"

   display "</body>"
   display "</html>"
end function
