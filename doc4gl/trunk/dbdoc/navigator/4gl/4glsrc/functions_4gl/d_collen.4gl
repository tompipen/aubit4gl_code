

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
#  DESCRICAO: Modulo para calculo do comprimeto de um campo.
#
#  ----------------------------------------------------------------
#  FUNCOES: d_get_col_len ()
# 
#  ----------------------------------------------------------------
#  FORMS: NAO USA
#  ----------------------------------------------------------------
#  REPORTS: NAO TEM.
#  ----------------------------------------------------------------
#  NOTAS:
#
# ====================================================================


#  ===========================================================
#  Funcao para calcular o comprimento ocupado por uma determinada
#  coluna.
#  O calculo e' feito com base no tipo da coluna (ver CASE).
#  -----------------------------------------------------------
#  entradas:
#    tabela -> tabela onde a coluna pertence.
#    coluna -> columa para calcular o comprimento.
#  -----------------------------------------------------------
#  saidas:
#    comp -> comprimento ocupado pela coluna.
#  ===========================================================
FUNCTION d_get_col_len (tabela,coluna)
{}
DEFINE tabela,
       coluna CHAR (18)

DEFINE tipo,
       comp SMALLINT

  whenever error call d_erro
  SELECT coltype,collength 
    INTO tipo,comp
    FROM systables,syscolumns
    WHERE colname = coluna AND
          systables.tabid = syscolumns.tabid AND
          tabname = tabela

  CASE
    WHEN status = NOTFOUND
      LET comp = NULL

    # Se o tipo de coluna for CHAR o comprimento ja esta afectad
    WHEN tipo = 0 OR tipo = 256

    # Se o tipo de coluna for SMALLINT o comprimento e' 6.
    WHEN tipo = 1 OR tipo = 257
      LET comp = 6 

    # Se o tipo de coluna for INTEGER ou SERIAL o comprimento e' 11.
    WHEN tipo = 2 OR tipo = 258 OR tipo = 262
      LET comp = 11

    # Se o tipo de coluna for DECIMAL o comprimento e' feito com base na
    # seguinte formula:
    WHEN tipo = 5 OR tipo = 261 OR tipo = 7 OR tipo = 263
      LET comp = (comp / 256) + 1

    # Se o tipo de coluna for DATE o comprimento e' 10.
    WHEN tipo = 7 OR tipo = 263
      LET comp = 10 
  END CASE

  RETURN comp

END FUNCTION
