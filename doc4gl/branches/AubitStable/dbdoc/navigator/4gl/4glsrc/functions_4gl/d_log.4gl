# ====================================================================
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#
#  Divisao de desenvolvimento e producao de software.
#
#  Autor:
#
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  ----------------------------------------------------------------
#  PROGRAMA      :  Livraria.
#  ----------------------------------------------------------------
#  DESCRICAO : Funcoes de gestao dos log(s).
#  ----------------------------------------------------------------
#  FUNCOES:  d_writelog()
#            d_get_log_nm()
#  ----------------------------------------------------------------
#  FORMS:  NAO USA.
#
#  REPORTS:  NAO TEM.
#
#  NOTAS:
#
# ====================================================================

GLOBALS "4glsrc/functions_4gl/d_libglob.4gl"


#  ===========================================================
#  Escreve no log a mensagem que se passa.
#  Se o log nao tiver sido iniciado inicia-o.
#  ===========================================================
function d_writelog(mesg)
{}
	define 
		mesg char(256)
	
	if d_ex_log = FALSE then
		let d_nm_log = d_get_log_nm()
		let d_ex_log = TRUE
		call startlog("d_nm_log")
	end if
	call errorlog(mesg)
end function



#  ===========================================================
#  Arraja um nome de jeito para o ficheiro de log
#  Tenta ir buscar a um ficheiro da base de dados ou
#  faz a partir do nome do programa em execucao

function d_get_log_nm()
{}
	return "/tmp/log"
end function

#  ===========================================================
