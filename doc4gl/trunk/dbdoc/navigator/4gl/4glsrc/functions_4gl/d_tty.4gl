

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
#  Programa      :
#  ----------------------------------------------------------------
#  DESCRICAO : Funcoes de gestao dos ttys
#  ----------------------------------------------------------------
#  FUNCOES:
#
#  ----------------------------------------------------------------
#  FORMS:  NAO TEM.
#
#  REPORTS:  NAO TEM.
#
#  NOTAS:
#
# ====================================================================



GLOBALS "4glsrc/functions_4gl/d_libglob.4gl"


# --------------------------------------------------------------------- #
# Inicializa a variavel global d_tty com o nome do tty de trabalho

function d_init_tty()
	let d_tty = d_get_tty()
end function

# --------------------------------------------------------------------- #

