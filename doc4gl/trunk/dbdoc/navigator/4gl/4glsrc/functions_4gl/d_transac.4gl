

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
#  DESCRICAO : Gestao de transacoes. Nao da bota se nao existir
#              ficheiro de transacoes.
#  ----------------------------------------------------------------
#  FUNCOES:   d_commit_work()
#             d_begin_work()
#             d_rollback_work()
#             d_tem_tr() - Verifica a existencia de
#                 ficheiro de transacoes na base de dados corrente.
#             d_get_nm_tr() - Devolve o nome do ficheiro de
#                             transacoes.
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
#  Comeca uma transacao. Se existirem ficheiros de transacoes
#  definidos na base de dados.

function d_begin_work()
{}
	#if d_ut_tr = TRUE or d_ut_tr is NULL then
		let d_ex_tr = TRUE
		begin work
	#end if
end function


#  ===========================================================
#  Faz commit. Se existirem ficheiros de transacoes
#  definidos na base de dados.

function d_commit_work()
{}
	#if d_ut_tr = TRUE or d_ut_tr is NULL then
		let d_ex_tr = FALSE
		commit work
	#end if
end function


#  ===========================================================
#  Faz rollback. Se existirem ficheiros de transacoes
#  definidos na base de dados.

function d_rollback_work()
{}
	#if d_ut_tr = TRUE or d_ut_tr is NULL then
		let d_ex_tr = FALSE
		rollback work
	#end if
end function


#  ===========================================================
#  Vai a' base de dados (systables) ver se esta definida com 
#  ficheiro de transacoes.
#  E' executada pela funcao de inicializacao de funcoes 
#  e utilitarios  genericos.

function d_init_tr()
{}
  let d_ut_tr = d_tem_tr() = true 
end function

#  ===========================================================



#  =====================================================================
#  Devolve true se a base de dados tiver transacoes, false se nao tiver.
#  =====================================================================
function d_tem_tr()
  define
	 tabelaid integer

  declare cr_tr cursor for 
	 select tabid  
	   from systables 
		where tabtype="L"

  open cr_tr
  fetch cr_tr into tabelaid
  if  status = NOTFOUND then
	 return false
  else
	 return true
  end if
end function


#  =====================================================================
#  Funcao que devolve o nome do ficheiro de transacoes.
#  =====================================================================
function d_get_nm_tr()
  define
	 nome_ficheiro char(64)

  declare cr_tra cursor for 
	 select dirpath  
	   from systables 
		where tabtype="L"

  open cr_tra
  fetch cr_tra into nome_ficheiro
  if  status = NOTFOUND then
	 return ""
  else
	 return nome_ficheiro
  end if
end function

