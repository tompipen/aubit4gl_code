
###############################################################################
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#                                                        
#  Autor:  Sergio Ferreira
#                                                        
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : 
#  ----------------------------------------------------------------
#  FUNCOES: d_exist (tabela,condicao)
#           d_count(tabela,condicao)
# 
#  ----------------------------------------------------------------
#  FORMS:  NAO TEM
#
#  REPORTS:  NAO TEM
#
#  NOTAS:
#
###############################################################################



#  == d_exist ========================================================
#  Funcao para verificar a existencia de pelo menos um elemento numa
#  determinada tabela que cumpram uma condicao.
#  -------------------------------------------------------------------
#  entradas:
#    tabela   -> tabela a pesquisar.
#    condicao -> condicao de pesquisa.
#  -------------------------------------------------------------------
#  saidas:
#    TRUE  -> se existir pelo menos um elemento.
#    FALSE -> se nao existirem nenhuns elementos.
#  ===================================================================
FUNCTION d_exist (tabela,condicao)
{}
DEFINE tabela   CHAR(18),
       condicao CHAR(350)

DEFINE qbuf    CHAR(400),
       min_row INTEGER

  IF condicao IS NULL THEN
    LET condicao="1=1" 
  END IF

  LET qbuf="SELECT MIN(ROWID) ",
             "FROM ",tabela CLIPPED," ",
             "WHERE ",condicao CLIPPED

  PREPARE PExiste FROM qbuf
  DECLARE CExiste CURSOR FOR PExiste
  OPEN CExiste
  FETCH CExiste INTO min_row
  CLOSE CExiste

  IF min_row IS NULL THEN
    RETURN FALSE
  END IF

  RETURN TRUE

END FUNCTION


# Funcao que devolve o numero de registos que um determinado select a
# uma tabela devolve.
# -------------------------------------------------------------------
# Entradas:
#   tabela   -> Nome da tabela onde vai ser efectuado o select
#   condicao -> Condicao do select
# 
# Saidas:
#   conta    -> Numero de registos devolvidos pelo select 
# ===================================================================
FUNCTION d_count(tabela,condicao)
{}
  DEFINE
    tabela CHAR(150),
    condicao CHAR(350)

  # Variaveis locais da funcao
  DEFINE 
    str_sel CHAR(500),
    conta SMALLINT

  # Corpo da funcao
  LET str_sel="SELECT COUNT(*) ",
                "FROM ",tabela CLIPPED," ",
                "WHERE ",condicao CLIPPED

  PREPARE P_conta FROM str_sel
  DECLARE cr_conta CURSOR FOR P_conta

  OPEN cr_conta

  case status
	when 100
		exit case
	when 0
		exit case
	# A gestao dos erros e feita pela funcao generica.
	otherwise  # meter aqui a funcao generica
  end case

  FETCH cr_conta INTO conta
  CLOSE cr_conta
  

  RETURN conta
END FUNCTION
