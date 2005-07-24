

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
#  FUNCOES:  d_descodifica() - Descodifica codigo 
# 
#  ----------------------------------------------------------------
#  FORMS: 
#
#  REPORTS: 
#
#  NOTAS:
#
###############################################################################


#  =============================================================
#  Funcao para descodificar codigo
#  -------------------------------------------------------------
#   parametros
#    tabela      -> tabela a pesquisar.
#    campo_descr -> campo da descricao.
#    condicao    -> condicao de pesquisa.
#                   Caso a condicao devolva mais do que um registo
#                   apenas sera' retornado o primeiro.
#
#  Alteracoes:
#     Podera ou nao enviar erros para o ecran por intermedio da 
#     funcao generica de erros.
#  -------------------------------------------------------------
#  valores de retorno:
#    descricao -> descricao pretendida.
#                 Caso nao exista nenhum registo que preencha a
#                 condicao introduzida, sera' devolvido o valor
#                 NULL.
#
#    A descricao nao devera ter mais de 100 caracteres, caso em 
#    que sera truncada.
#    Poderia fazer mais algumas validacoes. Nomeadamente verificar se o 
#    campo existe.
##############################################################################

FUNCTION d_descodifica (tabela,campo_descr,condicao)
{}
DEFINE tabela,
       campo_descr CHAR (64),
       condicao    CHAR (500)

DEFINE sel       CHAR (700),
       descricao CHAR (78)

  #whenever error call d_erro
  IF condicao IS NULL THEN
    LET condicao = "1=1"
  END IF

  LET sel = "SELECT ",campo_descr CLIPPED," ",
              "FROM ",tabela CLIPPED," ",
              "WHERE ",condicao CLIPPED

  PREPARE PSysGetDescr FROM sel
  DECLARE cr_descodifica CURSOR FOR PSysGetDescr 

  OPEN cr_descodifica
  FETCH cr_descodifica INTO descricao
  IF status = NOTFOUND THEN
    LET descricao = NULL
  END IF
  CLOSE cr_descodifica

  RETURN descricao CLIPPED

END FUNCTION
