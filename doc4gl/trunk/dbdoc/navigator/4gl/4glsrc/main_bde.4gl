
#  ============================================================================ 
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#                                                        
#  Autor:  sergio Alexandre Ferreira
#                                                        
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : Main do programa para fazer esquemas.
#  ----------------------------------------------------------------
#  DESCRICAO: 
#
#  ----------------------------------------------------------------
#
#  ============================================================================ 

GLOBALS "/usr/desenvolv/include/d_libglob.4gl"

MAIN
   DEFINE 
		 base_de_dados CHAR(18),
		 restricao        char(20),
		 formato       char(11),
		 accao         char(8),
		 strCond CHAR(100)

	whenever error call d_erro


   DEFER INTERRUPT
   IF num_args() < 3 THEN
     DISPLAY "Utilizacao: fglgo bdesquema base_de_dados accao parametro"
     EXIT PROGRAM 
   END IF

   LET strCond="DATABASE ",arg_val(1) CLIPPED
   PREPARE Ps1 FROM strCond 
   EXECUTE Ps1

   LET base_de_dados = arg_val(1) CLIPPED

   LET d_nm_log="/tmp/bdesquema.log"
   CALL startlog(d_nm_log)

	# Temporariamente vai-se passar argumentos para preparar caminho para 
	# versao CGI.

	let accao  = Arg_Val(2)
	let restricao = Arg_Val(3)

   call bdesquema(base_de_dados,accao,restricao)

END MAIN
