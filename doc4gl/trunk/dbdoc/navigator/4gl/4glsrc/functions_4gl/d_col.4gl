#  ============================================================================ 
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#                                                        
#  Autor: sergio
#                                                        
#  Data de criacao: Fri Aug 14 12:13:24 LISBOA 1992
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : 
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


function d_col_ischar(tabela,coluna)
{}
   define
		tabela char(18),
		coluna char(18),
		tipo smallint
	
	whenever error call d_erro

	select coltype 
		into tipo
		from systables, syscolumns
		where systables.tabid=syscolumns.tabid and
				systables.tabname=tabela and
				syscolumns.colname=coluna

   if tipo=0 OR tipo=256 then
		return true
	else
		return false
	end if
end function

