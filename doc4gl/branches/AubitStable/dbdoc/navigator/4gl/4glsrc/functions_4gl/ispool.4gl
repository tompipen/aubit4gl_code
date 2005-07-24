#  ============================================================================ 
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#                                                        
#  Autor: sergio
#                                                        
#  Data de criacao: Tue Jan 12 12:48:47 LISBOA 1993
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : Spooler interactivo.
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


#  ============================================================================ 
#  ============================================================================ 
function 	 spool_interactivo()
{}
   menu ""
		command "Grupos"
			call sp_sel_group()
		command "Listagens"
			call sp_sel_list()
		command "Imprimir"
		command "Fim"
			exit menu
	end menu
end function


#  ============================================================================ 
#  Seleccao do grupo de impressao.
#  ============================================================================ 
function 	 sp_sel_group()
{}
end function



#  ============================================================================ 
#  Seleccao da listagem.
#  ============================================================================ 
function 	 sp_sel_list()
{}
end function
