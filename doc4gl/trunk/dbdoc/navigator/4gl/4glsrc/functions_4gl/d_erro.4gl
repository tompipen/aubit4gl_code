# ================================================================
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#
#  Divisao de desenvolvimento e producao de software.
#
#  Autor:  Sergio Alexandre Ferreira
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
#  DESCRICAO: Modulo para o controlo dos erros na base de dados.
#  ----------------------------------------------------------------
#  FUNCOES:  d_erro() - Funcao para usar com
#                                    WHENEVER ERROR CALL d_erro()
#
#  ----------------------------------------------------------------
#  FORMS: Nao tem
#
#  REPORTS: Permite o acesso a ficheiro de log(s).
#
#  NOTAS:
#
#  ===================================================================


GLOBALS "4glsrc/functions_4gl/d_libglob.4gl"

define nomeFicheiroLog char(64)
define msg_err         CHAR (256)

#  ===========================================================
#  Funcao para terminar o programa sempre que haja um erro
#  grave no acesso `a base de dados (status < 0).
#  Esta funcao devera' ser utilizada num WHENEVER ERROR CALL d_erro().
#  Numa fase de testes ou desenvolvimento, nao se devera 
#  incluir esta instrucao uma vez que os erros enviados pelo
#  informix sao bastante legiveis.
#  -----------------------------------------------------------
#  entradas:
#    & d_ex_tr           -> Variavel boleana com indicacao de
#                           transaccao a decorrer. 
#                           Caso esteja uma transaccao a correr
#                           aquando do erro, sera' efectuado um
#                           ROOLBACK.
#  -----------------------------------------------------------
#  nota importante:
#    Apos a apresentacao da mensagem de erro. a rotina terminara'
#    o programa retornando o exit code = 1
#  ===========================================================

FUNCTION d_erro ()
	DEFINE 
		my_stat integer

  # --------------------------------------------------------------------
  # Salvar o status
  # --------------------------------------------------------------------
  let my_stat = status
  if my_stat = 0 then
  	let my_stat=sqlca.sqlcode
  end if

  # ---------------------------------
  # Escrever a mensagem no errorlog
  # ---------------------------------
  let msg_err = err_get(my_stat)
  {
  if d_ut_log = TRUE then
  	call d_writelog(msg_err)
  end if
  }

  # ------------------------------------------------
  # Enviar erro e accao para a janela 
  # ------------------------------------------------
  call d_escreveErro(my_stat)

END FUNCTION

#  ===========================================================
#  Inicia o log guardando numa variavel propria o nome do
#  ficheiro
#  ===========================================================
function d_start_log(nomeLog)
  define nomeLog char(64)

  let nomeFicheiroLog = nomeLog
	let d_nm_log = nomeLog
	call startlog(nomeFicheiroLog)
end function


#  ===========================================================

#  ===========================================================
#  Filtra o tipo de erro que aconteceu e mostra-o com a funcao
#  d_dialogOk().

function 	 d_escreveErro(mstat)
{}
  define mstat integer,
  msg1 char(48),
  msg2 char(48),
  msg3 char(48),
  msg4 char(48),
  msg5 char(48),
  op1  char(10),
  op2  char(10),
  op3  char(10),
  ans  smallint,
  erro_sql smallint,
  pode_recuperar smallint,
  recupera_mesmo smallint,
  #
  # Carlos patrao, 19-06-1998
  #
  # Variaveis de ambiente para os CGI's 
  #
  V_REQUEST_METHOD CHAR(50),
  V_QUERY_STRING CHAR(50)

  let recupera_mesmo = false

  initialize msg1, msg2, msg3, msg4, msg5, op1, op2, op3 to null
  if d_errmsg is null then
    case
	   when d_accao = "Ins"
		  let msg1="        E impossivel escrever na tabela"
	   when d_accao = "Del"
		  let msg1="    E impossivel remover elemento da tabela"
	   when d_accao = "Dev"
		  let msg1="     E impossivel remover elemento da lista"
    end case
  else
	 let msg1=d_errmsg
	 initialize d_errmsg to null
  end if

  case
	 when mstat = -206
		let msg3 = "Falta uma tabela na estrutura"
		let msg4 = "da base de dados"
		let msg5 = "    Consulte o admnistrador da base de dados"
		let pode_recuperar = false

	 when mstat = -239
		let msg3 = "Nao pode inserir registos"
		let msg4 = "com a chave duplicada"
		let pode_recuperar = true

	 when mstat = -250
		let msg2 = "   O registo corrente esta bloqueado "
		let msg3 = "          por outro utilizador"
	   let op1 = "OK "
	   let op2 = NULL
	   let op3 = NULL
		#
		# Carlos Patrao, 17-06-1998
		#
		# Inibir a chamada de funcoes que facam prompt quando a "d_erro"
		# e' invocada por um CGI
		#
		LET V_REQUEST_METHOD=fgl_getenv("REQUEST_METHOD") CLIPPED
		LET V_QUERY_STRING=fgl_getenv("QUERY_STRING") CLIPPED
		IF V_REQUEST_METHOD IS NOT NULL OR V_QUERY_STRING IS NOT NULL THEN
		  DISPLAY msg_err 
		ELSE
	     let ans = d_dialog(9,15,op1,op2,op3,msg1,msg2,msg3,msg4,msg5,"")
		END IF
		let int_flag = true
		return

	 when mstat = -213
		let msg2="  Operacao interrompida por sua ordem."
		let pode_recuperar = true

	 when mstat = -273
		let msg2="    Nao tem permissoes para alterar registos."
		let msg3="  Consulte o seu admnistrador da base de dados"
		let pode_recuperar = true

	 when mstat = -274
		let msg2="    Nao tem permissoes para remover registos."
		let msg3="  Consulte o seu admnistrador da base de dados"
		let pode_recuperar = true

	 when mstat = -263
		let msg2="       Provavelmente alguem o bloqueou "
		let msg3="  Consulte o seu admnistrador da base de dados"
		let pode_recuperar = true

	 when mstat = -242
		let msg2 ="       Provavelmente alguem a bloqueou "
		let msg3="  Consulte o seu admnistrador da base de dados"
		let pode_recuperar = true

    when mstat = -329 
	    let msg2 = "      Voce nao tem permissoes de ligacao "
		 let msg3 = "              a\' base de dados ",d_db clipped
		 let msg5 = "    Consulte o admnistrador da base de dados"
		 let pode_recuperar = false

    when mstat = -387 
	    let msg2 = "      Voce nao tem permissoes de ligacao "
		 let msg3 = "              a\' base de dados"
		 let msg5 = "    Consulte o admnistrador da base de dados"
		 let pode_recuperar = false

    when mstat = -1110 
	    let msg2 = "Nao existe um ficheiro"
		 let msg3 = "essencial ao funcionamento do programa"
		 let msg5 = "Consulte o admnistrador da base de dados"
		 let pode_recuperar = false

   when mstat = -1136
		let msg2 ="Janela demasiado grande para caber no ecran"
		let msg3="Consulte o seu fornecedor de software"
		let msg5="!"

   when mstat = -1138
		let msg2 ="Moldura demasiado grande para caber no ecran"
		let msg3="Consulte o seu fornecedor de software"
		let msg5="!"

   when mstat = -1322
		let msg2 ="Impossivel abrir ficheiro para relatorio"
		let msg3="Provavelmente devera verificar permissoes"
		let msg5="!"
		let pode_recuperar = false

   when mstat = -10000
		 let msg5 = "    Consulte o admnistrador da base de dados"
		 let recupera_mesmo = true

	 otherwise
		let erro_sql = true
		let pode_recuperar = false
		let msg2="Erro impossivel de resolver"
		let msg3="Consulte o seu fornecedor de software"
		let msg5="Status :",mstat
  end case

	let op1 = "OK "
	let op2 = "INF.ADICIONAIS"
	let op3 = "REGISTO"
	#
	# Carlos Patrao, 17-06-1998
	#
	# Inibir a chamada de funcoes que facam prompt quando a "d_erro"
	# e' invocada por um CGI
	#
	LET V_REQUEST_METHOD=fgl_getenv("REQUEST_METHOD") CLIPPED
	LET V_QUERY_STRING=fgl_getenv("QUERY_STRING") CLIPPED
	IF V_REQUEST_METHOD IS NOT NULL OR V_QUERY_STRING IS NOT NULL THEN
	  DISPLAY msg_err 
	ELSE
	  let ans = d_dialog(9,15,op1,op2,op3,msg1,msg2,msg3,msg4,msg5,"")
   END IF

	if not recupera_mesmo then
      # ------------------------------------------------
      # Se o erro foi detectado dentro de uma transacao,
      # e' feito um ROLLBACK
      # ------------------------------------------------
      IF d_ex_tr THEN
		   call d_rollback_work()
	   END IF	
   
	   case
		   when ans = 1
			   exit case
		   when ans = 2
	         #
	         # Carlos Patrao, 17-06-1998
	         #
	         # Inibir a chamada de funcoes que facam prompt quando a "d_erro"
	         # e' invocada por um CGI
	         #
	         LET V_REQUEST_METHOD=fgl_getenv("REQUEST_METHOD") CLIPPED
	         LET V_QUERY_STRING=fgl_getenv("QUERY_STRING") CLIPPED
	         IF V_REQUEST_METHOD IS NOT NULL OR V_QUERY_STRING IS NOT NULL THEN
	           DISPLAY msg_err 
	         ELSE
			     call inf_adicional()
				END IF
			when ans = 3
	         #
	         # Carlos Patrao, 17-06-1998
	         #
	         # Inibir a chamada de funcoes que facam prompt quando a "d_erro"
	         # e' invocada por um CGI
	         #
	         LET V_REQUEST_METHOD=fgl_getenv("REQUEST_METHOD") CLIPPED
	         LET V_QUERY_STRING=fgl_getenv("QUERY_STRING") CLIPPED
	         IF V_REQUEST_METHOD IS NOT NULL OR V_QUERY_STRING IS NOT NULL THEN
	           DISPLAY msg_err 
	         ELSE
				  call d_mostra(d_nm_log)
				END IF
	   end case
   
	   if pode_recuperar = true then
		   let msg1=NULL
		   let msg2="Pode tentar continuar a execucao do programa"
		   let msg3=NULL
		   let msg4="!"
		   let msg5=NULL
	      let op1 = "CONTINUAR"
	      let op2 = "ABANDONAR"
	      let op3 = NULL
	      #
	      # Carlos Patrao, 17-06-1998
	      #
	      # Inibir a chamada de funcoes que facam prompt quando a "d_erro"
	      # e' invocada por um CGI
	      #
	      LET V_REQUEST_METHOD=fgl_getenv("REQUEST_METHOD") CLIPPED
	      LET V_QUERY_STRING=fgl_getenv("QUERY_STRING") CLIPPED
	      IF V_REQUEST_METHOD IS NOT NULL OR V_QUERY_STRING IS NOT NULL THEN
	        DISPLAY msg_err 
      	ELSE
	        let ans = d_dialog(9,15,op1,op2,op3,msg1,msg2,msg3,msg4,msg5,"")
			END IF
		   case
			   when ans = 1
				   EXIT CASE
			   when ans = 2
	            EXIT PROGRAM
		   end case
	   else
		   EXIT PROGRAM
	   end if
	end if

  # Inactivo.
  let d_accao = "INA"
  let d_status = mstat
  let status = mstat
end function



#  ======================================================================
#  Mostra a informacao adicional.
#  ======================================================================
function 	 inf_adicional()
{}
  define
	 str1 char(256),
	 ans smallint,
	 op1,op2,op3 char(10)


	let op1 = "OK "
	let op2 = "REGISTO"
	let op3 = null
	let ans = d_dialog(9,15,op1,op2,op3,"",msg_err,"","!","","")
	if ans = 2 then
		if d_nm_log is not null then
		  call d_mostra(d_nm_log)
		else
			if nomeFicheiroLog is not null then
				call d_mostra(nomeFicheiroLog)
			else
	      call d_dialogOk(9,15,"","Nome do ficheiro de log",
																 "nao registado","","","")
			end if
		end if
  end if
end function
