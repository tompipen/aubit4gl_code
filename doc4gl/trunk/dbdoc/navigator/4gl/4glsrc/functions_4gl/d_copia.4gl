
#  ============================================================================ 
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#                                                        
#  Autor: sergio
#                                                        
#  Data de criacao: Thu May 13 17:28:24 LISBOA 1993
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : Livraria generica de funcoes.
#  ---------------------------------------------------------------------------
#  DESCRICAO: Estas funcoes servem para copiar ficheiros para diversos sitios,
#             Tem uma parte interactiva, e uma que executa os devidos comandos.
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


#  ============================================================================ 
#  Copia um ficheiro para um destino 
#  ============================================================================ 
function 	 d_copia(ficheiro)
{}
   define
		ficheiro char(64),
		destino  char(40)
	
	let destino = d_get_destino()
	{
	if destino is null then
		return
	end if
	}
	call d_cp(destino,ficheiro)
end function

#  ============================================================================ 
#  Executa o comando que efectua a copia.
#  ============================================================================ 
function 	 d_cp(destino,ficheiro)
{}
   define
		destino          char(40),
		ficheiro         char(64),
		dest_comm_antes  char(25),
		dest_comm_depois char(25),
		ans              smallint,
		comm             char(80),
		nome_fl          char(50),
		perg_nome        char(1),
		mens, mens1      char(60)
   
	if destino is not null then
      whenever error call d_erro
	   declare cr_dest cursor for
		   select d_file_dest.comm_antes, 
				    d_file_dest.com_depois, d_file_dest.perg_nome
			   from d_file_dest
			   where d_file_dest.dest_name = destino
      open cr_dest
	   fetch cr_dest into dest_comm_antes, dest_comm_depois, perg_nome
	   close cr_dest
	else
		let dest_comm_antes = "cp "
      let perg_nome = "S"
	end if
	if perg_nome = "S" then
		open window w_dialogo at 9, 12 with 6 rows, 60 columns
			attribute(border)
		display "Introduza nome de ficheiro de destino" at 2, 10
		open window w_prompt  at 12, 17 with 1 rows, 50 columns
			attribute(reverse)
		prompt "" for nome_fl 
		close window w_prompt
		close window w_dialogo
	   let comm = dest_comm_antes  clipped, " ",
				     ficheiro         clipped, " ",
				     nome_fl clipped
	else
	   let comm = dest_comm_antes  clipped, " ",
				     ficheiro         clipped, " ",
				     dest_comm_depois clipped
	end if
	      #let ans = d_dialog(9,15,op1,op2,op3,str1,str2,str3,str4,str5,str6)
	call keep_mesg("Comando em execucao !...")
   let ans = d_run(comm)
	call take_mesg()
	let mens = "Ficheiro <",ficheiro clipped, "> copiado para"
	if perg_nome = "S" then
	   let mens1 = "<",dest_comm_depois clipped, "/", nome_fl clipped, ">"
	else
	   let mens1 = "<", dest_comm_depois, ">"
	end if
	call d_dialogOk(9,15,"",mens,mens1,"","!","")
end function


#  ============================================================================ 
#  Pede interactivamente o destino a dar ao ficheiro, perguntando o nome 
#  do ficheiro de destino.
#  ============================================================================ 
function 	 d_get_destino()
{}
   define
		n_destinos  smallint,
		destino     char(40)

	whenever error continue
   select count(*) 
		into n_destinos
		from d_file_dest
	whenever error call d_erro
	if status = -206 then 
		let n_destinos = 0
	end if
   if n_destinos <= 0 then
	   #call d_dialogOk(9,15,"","Nao ha destinos para ficheiros","","!","","")
		return ""
	end if
	call d_amor(9,15,1,2,false,false,"Destinos para ficheiros","d_file_dest",
					"comm_antes",
					"dest_name",
					"",
					"1=1",
					"")
	returning destino
	return destino
end function



