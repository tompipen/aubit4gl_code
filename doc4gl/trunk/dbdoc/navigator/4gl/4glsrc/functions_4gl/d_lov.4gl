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
#  PROGRAMA      :  Livraria
#
#  ----------------------------------------------------------------
#  DESCRICAO :
#
#  ----------------------------------------------------------------
#  FUNCOES:  d_lov() - List of values. Para descodificacao de tabelas.
# 
#  ----------------------------------------------------------------
#  FORMS:  Nao usa.
#
#  REPORTS:  Nao tem
#
#  NOTAS:  Por questoes de compatibilidade mantem-se esta com os 
#          argumentos necessarios e chama-se a d_amor.
#
# ====================================================================

FUNCTION d_lov(lin, col, tipo_disp, tipo_ret, campo_order, unicos, titulo, 
					 tabela, campoC, campoD, condicao)

DEFINE
	lin, col, tipo_disp, tipo_ret, campo_order, unicos SMALLINT,
	titulo CHAR(30),
	tabela CHAR(60),
	campoC, campoD CHAR(18),
	condicao CHAR(300),
	order_by  char(64),
	cod char(64),
	descricao char(64)

  whenever error call d_erro
	if campo_order = 1 then
		let order_by = campoC
	else
		let order_by = campoD
	end if

	if tipo_ret = 1 OR tipo_ret = 2 then # 1-codigo ; 2-descricao
      call d_amor(lin,     col,     # Coordenadas da janela
           tipo_disp, tipo_ret,     # Tipo de display, tipo de return
           false,  true,            # Flag de marcacao, flag de pesquisa
           titulo,                  # Titulo
           tabela,    campoC,       # Tabela principal, campo de codigo
           campoD,    "",           # Campo descodificacao e extra
           condicao,  order_by)     # Clausula where e order by
		returning cod
		return cod
	else                              # 3-codigo + descricao
      call d_amor(lin,     col,     # Coordenadas da janela
           tipo_disp, tipo_ret,     # Tipo de display, tipo de return
           false,  true,            # Flag de marcacao, flag de pesquisa
           titulo,                  # Titulo
           tabela,    campoC,       # Tabela principal, campo de codigo
           campoD,    "",           # Campo descodificacao e extra
           condicao,  order_by)     # Clausula where e order by
		returning cod, descricao
		return cod, descricao
	end if
end function
