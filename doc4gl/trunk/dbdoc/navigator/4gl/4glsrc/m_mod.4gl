#  ============================================================================ 
#
#  Copyright 1995 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#  Rua da Prata 166 4.o Dto
#  1100 LISBOA
#                                                        
#  Autor: 
#                                                        
#  Data de criacao: Thu Dec 21 17:01:33 LISBOA 1995
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
GLOBALS "/usr/desenvolv/include/d_libglob.4gl"

define
   pr_chaves record
      nm_chave1   char (28),
      val_chave1  char(28),
      nm_chave2   char (28),
      val_chave2  char(28),
      nm_chave3   char (28),
      val_chave3  char(28),
      nm_chave4   char (28),
      val_chave4  char(28),
      nm_chave5   char (28),
      val_chave5  char(28)
   end record


MAIN
      DEFINE
         nm_db char(19),

         str_prepdb char(64)

   defer interrupt

   whenever error call d_erro
   LET d_nm_log="log/scr_mod.log"
   CALL startlog(d_nm_log)
   let d_accao = "INA"
   let scr_pointer = 0
   IF num_args() < 1 THEN
      LET nm_db="despodata"
   ELSE
      LET nm_db=arg_val(1)
   END IF
   LET str_prepdb="database '",nm_db,"'"
   PREPARE stat_db FROM str_prepdb
   EXECUTE stat_db


	call create_extensao()

	menu "OPÇÕES"
		command "Módulos" "Registo de modulos da aplicacao"
         call scr_menu_mod(6,3,1,"1=1",pr_chaves.*)
		command "Tabelas" "Associacao de tabelas a modulos"
         call scr_menu_mtab(6,3,1,"1=1",pr_chaves.*)
		command "Fim" "Sai do programa"
			exit menu
	end menu
end main


