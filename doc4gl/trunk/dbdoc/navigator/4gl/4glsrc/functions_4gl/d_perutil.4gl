#  ============================================================================
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#                                                        
#  Autor: Pedro Higgs Menezes
#                                                        
#  Data de criacao: Tue Oct 18 14:58:03 LISBOA 1994
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : 
#  ---------------------------------------------------------------------------
#  DESCRICAO:  d_tem_permissao(nome_logname,permissao)
#     - Esta funcao vai servir para verificar se um utilizador tem permissao
#      para efectuar determinada tarefa
#               Parametros:
#                    logname   - Nome de login do utilizador
#                    permissao - String que identifica a permissao
#               Valores de retorno:
#                    true      - O utilizador tem permissao
#                    false     - O utilizador nao tem permissao
#
#
#              d_cargo(nome_logname,cargo)
#     - Esta funcao vai servir para verificar se um utilizador ocupa determinado
#      cargo 
#               Parametros:
#                    logname - Nome de login do utilizador
#                    cargo   - Codigo de cargo 
#               Valores de retorno:
#                    true    - O utilizador assume o cargo
#                    false   - O utilizador nao assume o cargo
#                 
#              d_ins_cargo(cod_cargo,cod_modulo,cod_descricao)
#      - Esta funcao insere um cargo na tabela "cargos". Vai verificar
#		  se o cargo existe e se nao existir vai inseri-lo
#               Parametros:
#							cod_cargo     - Codigo do cargo
#							cod_modulo    - Modulo a que pertence
#							cod_descricao - Descricao do cargo
#					 Valores de retorno:
#							true  - Inserir o cargo
#							false - Nao inseriu
#
#              d_ins_accao(cod_accao,cod_cargo)
#       - Esta funcao  insere accoes na tabela "accoes". Vai verificar
#        se existe o cargo na tabela "cargos" e na tabela "accoes" se existe
#        ja algum registo igual a aquele que e passado como parametro, se nao
#        existe insere
#               Parametros:
#                    cod_accao - Codigo accao
#                    cargo     - Codigo do cargo que vai ter esta permissao
#               Valores de retorno:
#							true  - Inserir o cargo
#							false - Nao inseriu
#
#              d_ins_acc_logname(nome_logname,des_cargo)
#        - Esta funcao insere pessoas na tabela "cargo_pessoa". Vai verificar
#         se ja existe algum registo igual a aquele que passado como paramentro,
#         e se nao existe insere
#               Parametros:
#                    nome_logname - Nome de login da pessoa
#                    cargo        - Codigo do cargo ocupado por pessoa
#               Valores de retorno:
#							true  - Inserir o cargo
#							false - Nao inseriu
#
#              d_ins_accao_ef(nome_logname,cod_accao,desc_comentario)
#        - Esta funcao  insere accoes efectuadas na tabela "d_acccoes_ef".
#         Vai verificar se existe o cargo na tabela "cargos" e na tabela
#         "d_accoes".
#               Parametros:
#                    cod_accao       - Codigo accao
#                    nome_logname    - Nome de login da pessoa
#                    desc_comentario - Comentario a accao
#
#  ---------------------------------------------------------------------------
#  FUNCOES:  d_tem_permissao()
#
#  ---------------------------------------------------------------------------
#  FORMS:
#
#  REPORTS:
#
#  NOTAS:
#
#  ============================================================================

#database despodata
database sysmaster

GLOBALS "4glsrc/functions_4gl/d_libglob.4gl"

define
	foi_a_primeira_tem  integer,
	foi_a_primeira_dca  integer,
	foi_a_primeira_dic  integer,
	foi_a_primeira_dia  integer,
	foi_a_primeira_dicl integer


#  ============================================================================ 
#     - Esta funcao vai servir para verificar se um utilizador tem permissao
#      para efectuar determinada tarefa
#               Parametros:
#                    logname - Nome de login do utilizador
#                    permissao - String que identifica a permissao
#  ============================================================================ 
function d_tem_permissao(nome_logname,permissao)
{}
   define
	   nome_logname char(19),
	   permissao    char(10),
		str_sel      char(300)

  
   let str_sel = " select * from d_cargo_pessoa,d_accoes ",
                 " where d_cargo_pessoa.nome_login = \"",nome_logname,"\" and ",
		                 " d_cargo_pessoa.cargo      =     d_accoes.cargo   and ",
							  " d_accoes.accao            = \"", permissao ,"\""

	if foi_a_primeira_tem = FALSE then
	   prepare stat_tem_permissao from str_sel
      declare cr_tem_permissao cursor for stat_tem_permissao
		let foi_a_primeira_tem = TRUE
	end if

   open cr_tem_permissao
	   fetch cr_tem_permissao

   if status = 0 then
      close cr_tem_permissao
	   return true                   # true  - O utilizador tem permissao
   else
      close cr_tem_permissao
	   return false                  # false - O utilizador nao tem permissao
   end if

end function


#  ============================================================================ 
#     - Esta funcao vai servir para verificar se um utilizador ocupa determinado
#      cargo 
#               Parametros:
#                    logname - Nome de login do utilizador
#                    cargo   - Codigo de cargo 
#  ============================================================================ 
function d_cargo(nome_logname,cod_cargo)
{}
   define
	   nome_logname     char(19),
	   cod_cargo        char(10),
		str_sel          char(300)


	if foi_a_primeira_dca = FALSE then
   let str_sel = " select * from d_cargo_pessoa ",
                 " where d_cargo_pessoa.nome_login = \"",nome_logname,"\" and ",
		                 " d_cargo_pessoa.cargo      = \"", cod_cargo  ,"\""
	   prepare stat_cargo from str_sel
      declare cr_cargo cursor for stat_cargo
		let foi_a_primeira_dca = TRUE
	end if

   open cr_cargo
	   fetch cr_cargo

   if status = 0 then
      close cr_cargo
	   return true                   # true  - O utilizador assume o cargo
   else
      close cr_cargo
	   return false                  # false - O utilizador nao assume o cargo
   end if
	
end function


#  ============================================================================ 
#     - Esta funcao vai servir para verificar se um utilizador ocupa determinado
#      cargo 
#               Parametros:
#                    logname - Nome de login do utilizador
#                    cargo   - Codigo de cargo 
#  ============================================================================ 
function d_ins_cargo(cod_cargo,cod_modulo,cod_descricao)
{}
   define
		cod_cargo     char(10),
		cod_modulo    char(10),
		cod_descricao char(50),
		str_sel       char(300)

	let str_sel = " select * from d_cargos ",
		           " where d_cargos.cargo     = \"", cod_cargo     ,"\" and ",
                       " d_cargos.modulo    = \"", cod_modulo    ,"\" and ",
				           " d_cargos.descricao = \"", cod_descricao ,"\""

	if foi_a_primeira_dic = FALSE then
	   prepare stat_cargo_mod from str_sel
      declare cr_cargo_mod cursor for stat_cargo_mod
		let foi_a_primeira_dic = TRUE
	end if

   open cr_cargo_mod
	   fetch cr_cargo_mod

   if status != 0 then
      close cr_cargo_mod
		insert into cargos values (cod_cargo,cod_modulo,cod_descricao)
		return false           # Nao existe e insere
	else 
      close cr_cargo_mod
		return true            # Existe e sai sem fazer nada
   end if
	
end function


#  ============================================================================ 
#       - Esta funcao  insere accoes na tabela "accoes". Vai verificar
#        se existe o cargo na tabela "cargos" e na tabela "accoes" se existe
#        ja algum registo igual a aquele que e passado como parametro, se nao
#        existe insere
#               Parametros:
#                    cod_accao - Codigo accao
#                    cargo     - Codigo do cargo que vai ter esta permissao
#  ============================================================================ 
function d_ins_accao(cod_accao,cod_cargo)
{}
   define
		cod_accao   char(10),
		cod_cargo   char(10),
		str_sel     char(300)

	
	let str_sel = " select * from d_accoes,d_cargos ",
	              " where d_cargos.cargo = \"", cod_cargo ,"\" and ",
			              " d_accoes.cargo =      d_cargos.cargo   and ",
			              " d_accoes.accao = \"", cod_accao ,"\""

	if foi_a_primeira_dia = FALSE then
	   prepare stat_accoes from str_sel
      declare cr_accoes cursor for stat_accoes
		let foi_a_primeira_dia = TRUE
	end if

   open cr_accoes
	   fetch cr_accoes

   if status != 0 then
      close cr_accoes
		insert into accoes values (cod_cargo,cod_accao)
		return false           # Nao existe e insere
	else 
      close cr_accoes
		return true            # Existe e sai sem fazer nada
   end if

end function


#  ============================================================================ 
#        - Esta funcao insere pessoas na tabela "cargo_pessoa". Vai verificar
#         se ja existe algum registo igual a aquele que passado como paramentro,
#         e se nao existe insere
#               Parametros:
#                    nome_logname - Nome de login da pessoa
#                    cargo        - Codigo do cargo ocupado por pessoa
#  ============================================================================ 
function d_ins_acc_logname(nome_logname,cod_cargo)
{}
   define
	   nome_logname char(19),
	   cod_cargo    char(10),
		str_sel      char(300)

	let str_sel = " select * from d_cargo_pessoa ",
					  " where d_cargo_pessoa.nome_login = \"",nome_logname,"\" and ",
							  " d_cargo_pessoa.cargo      = \"", cod_cargo  ,"\""


	if foi_a_primeira_dicl = FALSE then
	   prepare stat_logname from str_sel
      declare cr_logname cursor for stat_logname
	   let foi_a_primeira_dicl = TRUE
	end if

   open cr_logname
	   fetch cr_logname

   if status != 0 then
      close cr_logname
		insert into cargo_pessoa values (nome_logname,cod_cargo)
		return false           # Nao existe e insere
	else 
      close cr_logname
		return true            # Existe e sai sem fazer nada
   end if

end function
 

#  ============================================================================ 
#       - Esta funcao  insere accoes efectuadas na tabela "d_acccoes_ef".
#        Vai verificar se existe o cargo na tabela "cargos" e na tabela
#        "d_accoes".
#               Parametros:
#                    cod_accao       - Codigo accao
#                    nome_logname    - Nome de login da pessoa
#                    desc_comentario - Comentario a accao
#  ============================================================================ 
function d_ins_accao_ef(nome_logname,cod_accao,desc_comentario)
{}
   define
		cod_accao       char(10),
	   nome_logname    char(19),
		desc_comentario char(50),
		str_sel         char(300),
		d_hora          smallint,
		d_minuto        smallint,
		ver_accao       char(10)

	call d_current()
	returning d_hora,d_minuto

	select d_accoes.accao into ver_accao
	from d_cargo_pessoa,d_accoes
	where d_cargo_pessoa.nome_login = nome_logname   and
			d_cargo_pessoa.cargo      = d_accoes.cargo and
			d_accoes.accao            = cod_accao

	if ver_accao is null then
		call errorlog("Atencao : Ha algum problema na funcao d_ins_accao")
	end if

   insert into d_accoes_ef (nome_login,data_ex,hora,minuto,accao,comentario)
	values (nome_logname,today,d_hora,d_minuto,cod_accao,desc_comentario)
	
end function
