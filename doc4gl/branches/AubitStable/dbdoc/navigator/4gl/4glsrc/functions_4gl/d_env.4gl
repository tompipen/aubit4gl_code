


#  ============================================================================ 
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#                                                        
#  Autor: sergio
#                                                        
#  Data de criacao: Thu Mar 04 14:40:26 LISBOA 1993
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : Generico.
#  ---------------------------------------------------------------------------
#  DESCRICAO:  Funcoes de acesso a tabela de valores de default.
#
#  ---------------------------------------------------------------------------
#  FUNCOES: 
# 
#  ---------------------------------------------------------------------------
#  NOTAS:
#
#  ============================================================================ 

#  ============================================================================ 
#  Obtem um valor registado com a chave enviada como parametro na d_env 
#  para o utilizador corrente
#  ============================================================================ 
function getEnvVar(varName)
	define varName    char(25)
	define valor      char(128)
	define utilizador char(20)

	let utilizador = d_get_logname()
  let valor = d_get_valor(varName,utilizador)
	return valor
end function

#  ============================================================================ 
#  ============================================================================ 
function 	 d_get_valor(chave,utilizador)
{}
   define
		chave char(25),
		utilizador char(12),
		valor char(128)
   
	if utilizador is null then
		select user 
		  into utilizador 
		  from systables 
		  where tabid=1
	end if
  whenever error call d_erro
	if chave is null or utilizador is null then
		return ""
	end if
	declare cr_env cursor for
		select d_env.valor 
		  from d_env 
		  where d_env.chave=chave and d_env.utilizador=utilizador
   open cr_env 
	fetch cr_env into valor
	if status = 0 and valor is null then
		delete from d_env where d_env.chave=chave and d_env.utilizador=utilizador
	end if
	close cr_env
	return valor clipped
end function

#  ===========================================================================
#  
#  ===========================================================================
function setEnvVar(varName, valor)
  define varName char(25)
	define valor   char(128)
	define utilizador char(20)

	let utilizador = d_get_logname()
	if d_update_valor(varName,utilizador,valor) then   end if
end function

#  ===========================================================================
#  Altera o valor da keyord do utilizador.
#  Devolve true se tudo OK, false se houve algum erro de SQL.
#  ===========================================================================
function 	 d_update_valor(chave,utilizador,valor)
{}
   define
		chave char(25),
		utilizador char(12),
		valor char(128)
   
	if utilizador is null then
		select user into utilizador from systables where tabid=1
	end if

	if valor is null then
		delete from d_env 
			where d_env.chave=chave and d_env.utilizador = utilizador
		return false
	end if
   if d_get_valor(chave,utilizador) is null then
		insert into d_env ( chave, utilizador, valor ) values 
								( chave, utilizador, valor)
		if status != 0 then
			return false
		end if
	else
		update d_env set valor = valor 
			where d_env.chave=chave and d_env.utilizador=utilizador
		if status != 0 then
			return false
		end if
	end if
	return true
end function
