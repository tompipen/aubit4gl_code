


# ====================================================================
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#
#  Divisao de desenvolvimento e producao de software.
#
#  Autor:   Sergio Alexandre Ferreira
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
#  DESCRICAO : Funcoes de gestao dos utilizadores
#  ----------------------------------------------------------------
#  FUNCOES:  d_get_logname
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
# Inicializa a variavel global d_user com o nome de login corrente.

function d_init_user()
  let d_user = d_get_logname()
end function

# --------------------------------------------------------------------- #

# --------------------------------------------------------------------- #
# Devolve o nome do utilizador - Na proxima versao ja nao tem de se
# ter uma tabela temporaria.
# Meter o free para a 4.1.
# --------------------------------------------------------------------- #

#  ===========================================================================
# Nao deveria ser preciso o PID uma vez que uma temporaria e unica
#  Basatava um query da treta em vez de insercao numa temporaria
#  ===========================================================================
FUNCTION d_get_logname()
{}
   DEFINE 
		logName CHAR(12),
		strStat char(128),
		tabname char(20),
		pidstr  integer

   whenever error call d_erro
	let pidstr = d_getpid()
	let tabname="usr_", pidstr using "<<<<<"
	let strStat = "create temp table ",tabname clipped," (utilizador char(16)) "
	prepare statCreate from strStat
	execute statCreate
	let strStat ="insert into ",tabname clipped , "( utilizador ) values (USER)"
	prepare statInsert from strStat
	execute statInsert
	let strStat ="select * from ", tabname clipped
	prepare statSelect from strStat
	declare cr_xx cursor for statSelect
	open cr_xx 
	fetch cr_xx into logName
	close cr_xx
	let strStat ="drop table ",tabname clipped 
	prepare statDrop from strStat
	execute statDrop
	RETURN logName CLIPPED
END FUNCTION

