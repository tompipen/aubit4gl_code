

# ===================================================================
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
#  PROGRAMA : variaveis globais da livraria.
#  ----------------------------------------------------------------
#  DESCRICAO :
#  ----------------------------------------------------------------
#  FUNCOES: 
# 
#  ----------------------------------------------------------------
#  FORMS: 
#
#  REPORTS: 
#
#  NOTAS: Estas variaveis globais passarao a ser utilizadas em todos os 
#         programas que utilizem funcoes e utilitarios genericos.
# ===================================================================


GLOBALS

DEFINE

  #
  # Variavel que contem mensagem de erro personalizada
  #

  d_errmsg char(48),

  #  Record com a instituicao que esta a correr a aplicacao

  pr_empresa RECORD                   # Record com a informacao da
				 codigo     smallint,
             nome       CHAR (60),    # empresa corrente
             morada     CHAR (60),    # Morada
             localidade CHAR (40),    # Localidade
             cod_postal CHAR (40),    # Codigo postal
             telefones  CHAR (30),    # String com telefones, sep por virgula
             fax        CHAR (15),    
             cap_social float,
             numci      CHAR (40)     # Numero de contriuinte
  END RECORD,

  d_user       char(12),             # Nome do utilizador
  d_impressora CHAR (14),            # string com o nome logico (UNIX) 
												 # da impressora
  d_db         char(19),             # String com o nome da base de dados 
												 # que esta a ser utilizada.
  d_impr_nome  CHAR (64),            # string com o nome da impressora corrente
  d_tty        CHAR (50),            # string com o path do device
                              # de input (ex.: /dev/tty01).
  d_status       SMALLINT,  # Status em que o d_erro escreve para 
									 # Saber que houve erro.
  d_ut_tr        SMALLINT,  # Flag da utilizacao de transacoes
									 # na base de dados.
  d_ex_tr        SMALLINT,  # Flag de indicacao de existencia de
									 # transaccao a decorrer.
  d_ut_log       SMALLINT,  # Flag que indica a utilizacao
									 # de ficheiro de log(s).
  d_ex_log       SMALLINT,  # Flag que indica a existencia de um 
									 # ficheiro de log ja aberto (c/startlog)
  d_nm_log       CHAR(64),  # Pathname do ficheiro de log
									 # utilizado neste programa.
   
	 # Estrutura de controlo de entradas de dados para template tipo ent. 
	 pr_scr_ctl array[3] of record
		linha           smallint,
		coluna          smallint,
		tabela         char(100),# Tabela master da entrada de dados.
		tabelas        char(100),# Tabelas utilizadas.
		campos         char(1000), # Campos selecionados.
		reg_corrente    smallint,# Numero do registo corrente.
      registos        smallint,# Numero de registos selecionados
		nomeRegs        char(48),# Nome dos registos para as mensagens de erro.
		str_get_reg    char(2000),# registos a ir buscar da tabela master.
		str_where      char(5000),# Clausula where a utilizar no select.
      str_select     char(5000),# String com o select a preparar para a busca.
		nome_tab_rowid char(16), # Nome da tabela de rowid's.
		rowid_curr     integer,  # Rowid corrente.
		nome_tab_apoio char(16), # Nome da tabela temporaria de apoio a edicao.
		comDetail      smallint, # Diz se a tabela tem ou nao detalhe(true, false)
		order_by       char(200)  # Campo pelo qual se vai fazer o order by.
	 end record,
	 scr_pointer      integer,  # Nivel de entrada de dados corrente.
	 d_accao          char(3),  # Accao efectuada quando deu o erro.


   # Variaveis parao uso das rotinas de directorias

      d_dir_nome       char(64),  # Nome da ultima directoria pesquisada
      d_pr_dir  record            # Record com a mesma estrutura da tab. temp.
	   nome char(20),           # Nome da entrada
	   modo char(10),           # Permissoes ( -r-xrwx--t )
	   st_ino integer,         # Inode
	   st_dev integer,         # 
	   st_rdev integer,        #
	   st_nlink integer,       # N. de links
	   st_uid integer,         # uid
		nome_uid char(14),      # Nome do user
	   st_gid integer,         # gid
	   st_size integer,         # dimensao
	   st_atime integer,        # tempos
	   st_mtime integer,        #
	   st_ctime integer         #
	end  record



END GLOBALS




#########################################################################
#########################################################################
#           DUMMY FUNCTIONS
#########################################################################
#########################################################################

#Could not find this functions anywhere - they are probably C code functions.

function icgi_start()
	display "FIXME: call to dummy finction"
	exit program (5)
	return 0
end function



function d_unlink(something)
define something char(100)
	display "FIXME: call to dummy finction"
	exit program (5)
	return 0
end function


#	let pr_parametros.ficheiro   = "/tmp/bdes.",d_getpid() using "<<<<<"
function d_getpid()
	display "FIXME: call to dummy finction"
	exit program (5)
	return 0
end function


#"text/html"
function icgi_mimetype(type)
define type char (100)
	display "FIXME: call to dummy finction"
	exit program (5)
end function

function d_run(comm)
  define comm char(64)
	display "FIXME: call to dummy finction"
	exit program (5)
	return 0
end function


