

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
#  PROGRAMA      : 
#
#  ----------------------------------------------------------------
#  DESCRICAO :
#
#  ----------------------------------------------------------------
#  FUNCOES:  d_dec_round()
# 
#  ----------------------------------------------------------------
#  FORMS: 
#
#  REPORTS: 
#
#  NOTAS:
#
# ====================================================================


#  ====================================================================
#  Funcao para arredondar um dado valor
#  --------------------------------------------------------------------
#  entradas :
#    valor -> valor a arredondar
#  --------------------------------------------------------------------
#  saidas :
#    valor -> valor arredondado
#  ====================================================================
FUNCTION d_dec_round (valor)
{}
DEFINE valor     DECIMAL (17,2),
       valor_int INTEGER

  LET valor_int = valor

  IF valor - valor_int >= .5 THEN
    LET valor = valor_int + 1
  ELSE
    LET valor = valor_int
  END IF

  RETURN valor

END FUNCTION
