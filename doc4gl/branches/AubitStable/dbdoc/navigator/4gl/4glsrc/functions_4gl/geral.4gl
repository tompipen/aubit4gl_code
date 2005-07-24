
################################################################################
# Modulo com funcoes gerais:
# void erro(mensagem) com apito
# void mesg(mensagem) 
# void beep() - apito
# boolean interrupt()
# string replicate(char,num)
# string clippedNum(strNum)
# integer searchC(str,car)
#
# void setArray(num,c1,c2,c3)
# boolean,integer,integer edArray(pos,fpos,numRegs)
#
# boolean ehEmpty(tabela)
# void entrada(strTabela)
# string getLogin()
# boolean getSimNao(mymsg)
# boolean pausa(tipo)
# boolean existem(tabela,busca,mesgs)
# integer getNregs()
# boolean,integer auxMyFetch(fPos,currReg,numRegs)
#   0=corrente;-1=primeiro;-2=ultimo;-3=anterior;-4=seguinte;>0=numero "num"
# boolean ehEqual(var1,var2)
################################################################################

GLOBALS
  DEFINE arr ARRAY[8] OF RECORD
            c1 CHAR(80),
            c2 CHAR(80),
            c3 CHAR(80)
          END RECORD,
			 numCols INTEGER,
			 numRegs INTEGER		# Numero de registos seleccionados pela pesquisa
END GLOBALS


###########################################################################
# Escreve a mensagem de erro passada como argumento, na linha 24 do ecran #
# Apita                                                                   #
###########################################################################
FUNCTION erro(mymsg)
{}
DEFINE 
	mymsg CHAR(78),
	dim INTEGER

	OPEN WINDOW w_erro AT 24, 2 WITH 1 ROWS, 78 COLUMNS
		ERROR ""
		LET dim=(78-LENGTH(mymsg CLIPPED))/2
		DISPLAY " ", mymsg CLIPPED, " " AT 1, dim ATTRIBUTE(REVERSE)
		SLEEP 2
	CLOSE WINDOW w_erro
		
END FUNCTION


###########################################################################
# Escreve a mensagem passada como argumento, na linha 24 do ecran         #
###########################################################################
FUNCTION mesg(mymsg)
{}
DEFINE 
	mymsg CHAR(78),
	dim INTEGER

	OPEN WINDOW win_mesg AT 24, 2 WITH 1 ROWS, 78 COLUMNS
		LET dim=(78-LENGTH(mymsg CLIPPED))/2
		DISPLAY " ", mymsg CLIPPED, " " AT 1, dim ATTRIBUTE(REVERSE)
		SLEEP 2
	CLOSE WINDOW win_mesg
		
END FUNCTION

FUNCTION keep_mesg(mymsg)
{}
DEFINE 
	mymsg CHAR(78),
	dim INTEGER

	OPEN WINDOW win_mesg AT 24, 2 WITH 1 ROWS, 78 COLUMNS
	LET dim=(78-LENGTH(mymsg CLIPPED))/2
	DISPLAY " ", mymsg CLIPPED, " " AT 1, dim ATTRIBUTE(REVERSE)
		
END FUNCTION

function 	 take_mesg()
{}
	CLOSE WINDOW win_mesg
end function


###########################################################################
# Apito                                                                   #
###########################################################################
FUNCTION beep()
{}
	ERROR ""
END FUNCTION


###########################################################################
# Testa a variavel int_flag, se tiver o valor logico TRUE quer dizer que  #
# a operacao foi interrompida pelo utilizador, da' a mensagem e devolve   #
# TRUE                                                                    #
###########################################################################
FUNCTION interrupt()
{}
DEFINE
	mymsg CHAR(78),
	dim SMALLINT

	IF int_flag THEN
		LET int_flag=FALSE
		LET mymsg="OPERACAO ABORTADA PELO UTILIZADOR"
		OPEN WINDOW w_erro AT 24, 2 WITH 1 ROWS, 78 COLUMNS
			ERROR ""
			LET dim=(78-LENGTH(mymsg CLIPPED))/2
			DISPLAY " ", mymsg CLIPPED, " " AT 1, dim ATTRIBUTE(REVERSE)
			SLEEP 2
		CLOSE WINDOW w_erro
		RETURN TRUE
	END IF
	RETURN FALSE
END FUNCTION

###########################################################################
# Recebe como argumento um caracter que se quer repetir e o numero de     #
# vezes que se pretende repetir. Por exemplo quando se quer fazer tracos  #
# num listagem: replicate("-",40)
###########################################################################
FUNCTION replicate(caracter,numero)
{}
  DEFINE caracter CHAR(1),
         numero smallint,
         x   smallint,
         mystr CHAR(256)

  FOR x=1 TO numero
	 if x > 255 then
		 exit for
 	 end if
	 if x = 1 then
      LET mystr=caracter
	 else
      LET mystr=mystr[1,x-1], caracter
	end if
  END FOR
  RETURN mystr CLIPPED
END FUNCTION



###########################################################################
# Para tirar os espacos de um string, tem grande utilidade quando de passa#
# como argumento uma variavel do tipo numerico trunca-se os espacos a     #
# esquerda e a direita e nao e' necessario usar USING                     #
###########################################################################
FUNCTION clippedNum(strNum)
{}
  DEFINE strNum CHAR(20)
  RETURN strNum CLIPPED
END FUNCTION


###########################################################################
# Procura um caracter numa string, se o encontrar devolve a posicao em que#
# ele se encontra, senao devolve 0                                        #
###########################################################################
FUNCTION searchC(str,car)
{}
  DEFINE str CHAR(80),car CHAR(1)
  DEFINE i INTEGER

  FOR i=1 TO length(str)
    IF str[i]=car THEN
      RETURN i
    END IF
  END FOR
  RETURN 0
END FUNCTION


###########################################################################
# Existe um array arr[8] com tres elementos c1, c2, c3                    #
# Esta funcao recebe como argumentos a posicao (i), e os elementos, que   #
# sao no maximo 3, mas podem ser menos.                                   #
# Para preencher o array na posicao [i], e os elementos                   #
# Exemplo: CALL setArray(i,pr_pai.codigo,pr_pai.descricao,"")             #
###########################################################################
FUNCTION setArray(num,c1,c2,c3)
{}
   DEFINE num INTEGER,c1 CHAR(80),c2 CHAR(80), c3 CHAR(80)
	DEFINE nCols SMALLINT

   LET arr[num].c1=c1
	LET nCols=1
	IF c2 IS NULL THEN
		GOTO fim
	END IF
	LET nCols=2
   LET arr[num].c2=c2
	IF c3 IS NULL THEN
		GOTO fim
	END IF
	LET nCols=3
   LET arr[num].c3=c3

	LABEL fim:
	IF num=1 THEN
		LET numCols=nCols
	ELSE
		IF nCols>numCols THEN
			LET numCols=nCols
		END IF
	END IF
END FUNCTION

###########################################################################
# Faz o display de uma linha do array para um screen array                #
# Recebe como argumentos a posicao do array e se quer fazer o display     #
# em reverse.                                                             #
###########################################################################
FUNCTION dispArr(n,ehReverse)
{}
  DEFINE n INTEGER,ehReverse INTEGER

  IF ehReverse THEN
    IF numCols=2 THEN
      DISPLAY arr[n].c1,arr[n].c2 TO sc_arr[n].* ATTRIBUTE(REVERSE)
    ELSE
      DISPLAY arr[n].c1,arr[n].c2,arr[n].c3 TO sc_arr[n].* ATTRIBUTE(REVERSE)
    END IF
  ELSE
    IF numCols=2 THEN
      DISPLAY arr[n].c1,arr[n].c2 TO sc_arr[n].*
    ELSE
      DISPLAY arr[n].c1,arr[n].c2,arr[n].c3 TO sc_arr[n].*
    END IF
  END IF
END FUNCTION

###########################################################################
# pos - posicao no screen record                                          #
# fpos - posicao do primeiro elemento do screen record dentro do cursor   #
# numRegs - numero de registos do cursor                                  #
#                                                                         #
# retVal - TRUE para terminar (se carregar em <RETURN> ou <BREAK>         #
#        - FALSE se o utilizador sair da janela                           #
#                                                                         #
# Exemplo: CALL edArray(pos,fPos,nRegs) RETURNING retVal,pos,fPos         #
###########################################################################
FUNCTION edArray(pos,fpos,numRegs)
{}
  DEFINE pos INTEGER,
         fPos INTEGER,
         numRegs INTEGER
  DEFINE numEls INTEGER,
         oldFpos INTEGER,
         oldPos INTEGER,
			i INTEGER

  LET numEls=8
  IF numEls>numRegs THEN
    LET numEls=numRegs
  END IF
  FOR i=1 TO numEls
     CALL dispArr(i,FALSE)
  END FOR
  LET oldFpos=fPos
  LET oldPos=pos

  WHILE oldFpos=fPos
    IF oldPos!=pos THEN
      CALL dispArr(oldPos,FALSE)
      LET oldPos=pos
    END IF
    CALL dispArr(pos,TRUE)
    CASE 
      WHEN getKey() = 2000  # KEY UP
        IF pos>1 THEN
          LET pos=pos-1
        ELSE
          IF fPos>1 THEN
            LET fPos=fPos-1
			 ELSE
				 LET fPos=numRegs-numEls+1
				 LET pos=numEls
          END IF
        END IF
      WHEN getkey() = 2001  # KEY DOWN
        IF pos<numEls THEN
          LET pos=pos+1
        ELSE
          IF fPos+numEls-1<numRegs THEN
            LET fPos=fPos+1
			 ELSE
				IF fPos>1 THEN
				  LET fPos=1
				ELSE
				  LET pos=1
				END IF
          END IF
        END IF
      WHEN getkey() = 2005  # KEY PGUP
        IF pos>1 THEN
          LET pos=1
        ELSE
          IF fPos>1 THEN
            LET fPos=fPos-numEls+1
            IF fPos<1 THEN
              LET fPos=1
            END IF
          END IF
        END IF
      WHEN getkey() = 2006  # KEY PGDN
        IF pos<numEls THEN
          LET pos=numEls
        ELSE
          IF fPos+2*(numEls-1)<numRegs THEN
            LET fPos=fPos+(numEls-1)
          ELSE
            LET fPos=numRegs-(numEls-1)
          END IF
        END IF
      WHEN getkey() = 32   
	IF pos<numEls THEN
          LET pos=pos+1
        ELSE
          IF fPos+numEls-1<numRegs THEN
            LET fPos=fPos+1
			 ELSE
				IF fPos>1 THEN
				  LET fPos=1
				ELSE
				  LET pos=1
				END IF
          END IF
        END IF
      WHEN getkey() = 13  # KEY "FAZER"
        RETURN TRUE,pos,fPos
      WHEN getkey() = 3   # PESQUISAR
		  RETURN TRUE, 1000, 1000
      OTHERWISE
        IF int_flag THEN
          RETURN TRUE,pos,fPos
        END IF
    END CASE
    IF oldFpos=fPos THEN
      IF pos=oldPos THEN
        CALL beep()
      END IF
    ELSE
      EXIT WHILE
    END IF
  END WHILE
  RETURN FALSE,pos,fPos
END FUNCTION


###########################################################################
# Recebe como argumento o nome de uma tabela e vai ver se tem dados       #
# Se a tabela nao tem dados devolve TRUE, se tiver dados devolve FALSE    #
###########################################################################
FUNCTION ehEmpty(tabela)
{}
  DEFINE tabela CHAR(15)
  DEFINE cnt CHAR(200),
			numRegs INTEGER

  LET cnt="SELECT COUNT(*) FROM ",tabela CLIPPED
  PREPARE pCnt FROM cnt
  DECLARE cr_cnt CURSOR FOR pCnt
  OPEN cr_cnt
  FETCH cr_cnt INTO numRegs
  CLOSE cr_cnt
  RETURN (numRegs=0)
END FUNCTION


###########################################################################
# Funcao para abrir o ecran no inicio dos programas, recebe como argumento#
# a tabela a que se refere o programa                                     #
###########################################################################
FUNCTION entrada(strTabela)
{}
	DEFINE strTabela CHAR(32)
	DEFINE auxStr CHAR(80)

	OPEN WINDOW w_tit AT 2, 2 WITH 1 ROWS, 77 COLUMNS   # Window com o titulo
		ATTRIBUTE(BORDER)
	LET auxStr="TABELA DE ",strTabela CLIPPED," - Versao 1.00"
	DISPLAY auxStr AT 1, 3 ATTRIBUTE(BOLD)
	DISPLAY " (c) SAM 1991" AT 1, 58 ATTRIBUTE(BOLD)
	OPEN WINDOW w_form AT 5, 2 WITH 13 ROWS, 77 COLUMNS   # Window com a form
		ATTRIBUTE(BORDER)
	OPEN WINDOW w_menu_geral AT 20, 2 WITH 2 ROWS, 77 COLUMNS
		ATTRIBUTE(BORDER)
END FUNCTION

FUNCTION saida()
	CLOSE WINDOW w_tit
	CLOSE WINDOW w_form
	CLOSE WINDOW w_menu_geral
END FUNCTION


###########################################################################
# Devolve o nome do utilizador                                            #
###########################################################################
FUNCTION getLogin()
{}
   DEFINE logName CHAR(12)

   CREATE TEMP TABLE logTmp ( login CHAR(12) )
   INSERT INTO logTmp VALUES (USER)
   SELECT * INTO logName FROM logTmp
	DROP TABLE logTmp
	RETURN logName CLIPPED
END FUNCTION


###########################################################################
# Recebe como argumento uma mensagem, e pergunta Sim/Nao                  #
# Devolve TRUE se SIM, False se NAO                                       #
###########################################################################
FUNCTION getSimNao(mymsg)
{}
  DEFINE mymsg CHAR(50),
         simNao CHAR(1),
         dimMsg INTEGER,
         dim INTEGER

  LET dimMsg=LENGTH(mymsg CLIPPED)+13+2
  LET dim=(80-dimMsg)/2+1
  OPEN WINDOW w_simNao AT 24,dim WITH 1 ROWS, dimMsg COLUMNS
  WHILE TRUE
    LET simNao=" "
    PROMPT mymsg CLIPPED ," (SIM/NAO) ? " FOR CHAR simNao
    LET simNao=UPSHIFT(simNao)
    IF (simNao="S") OR (simNao="N") THEN
      EXIT WHILE
    END IF
  END WHILE

  CLOSE WINDOW w_simNao
  RETURN (simNao="S")
END FUNCTION


###########################################################################
# Recebe como argumento tipo i-imprimir, c-imprimir ou fim, e-ecran(cont.)#
# Apresenta um menu com as operacoes definidas pelo tipo, devolve sempre  #
# TRUE excepto quando no caso do tipo=c nao se quiser imprimir            #
###########################################################################
FUNCTION pausa(tipo)
{}

DEFINE
	tipo CHAR(1),
	lixo CHAR(1),
	retVal SMALLINT

LET retVal=TRUE

CASE 
	WHEN tipo = "i"
		MENU " IMPRESSAO"
		COMMAND "CARREGUE EM RETURN PARA IMPRIMIR" ""
			EXIT MENU
		END MENU
		EXIT CASE
	WHEN tipo = "c"
		MENU " IMPRESSAO"
		COMMAND "IMPRIMIR " " Para confirmar a impressao"
			EXIT MENU
		COMMAND "FIM " " Para voltar ao menu anterior"
			LET retVal=FALSE
			EXIT MENU
		END MENU
		EXIT CASE
	WHEN tipo = "e"
		PROMPT "CARREGUE EM RETURN PARA CONTINUAR " FOR lixo
		EXIT CASE
END CASE

RETURN retVal

END FUNCTION


###########################################################################
# Esta funcao faz uma contagem dos dados de uma tabela da base de dados   #
# Recebe como argumento a TABELA, a frase para efectuar a condicao na     #
# pesquisa BUSCA, que pode ser construida por uma instrucao CONSTRUCT,    #
# mesgs se for TRUE em faz o DISPLAY do total de registos encontrados     #
###########################################################################
FUNCTION existem(tabela,busca,mesgs)
{}
  DEFINE tabela    CHAR(15),busca CHAR(200),mesgs SMALLINT
  DEFINE findCnt   CHAR(500),	# COUNT(*) dos elementos seleccionados em BUSCA
			erroVar   CHAR(80),
			erroVar1  CHAR(80),
			erroVar2  CHAR(80),
			erroVar3  CHAR(80)

	#Conta o numero de registos que se encontram nas condicoes dadas
	LET findCnt="SELECT COUNT(*) FROM ",tabela CLIPPED
	IF (busca IS NOT NULL) AND (length(busca CLIPPED)!=0) THEN
	  LET findCnt=findCnt CLIPPED," WHERE ",busca CLIPPED
	END IF
	PREPARE pFindCnt FROM findCnt
	DECLARE cr_tabCnt CURSOR FOR pFindCnt
	OPEN cr_tabCnt
	FETCH cr_tabCnt INTO numRegs
	CLOSE cr_tabCnt
	IF numRegs=0 THEN
	  IF mesgs THEN
		  CALL erro("NAO FOI ENCONTRADO NENHUM ELEMENTO NAS CONDICOES DADAS.")
	  END IF
	  RETURN FALSE
	END IF

	IF mesgs THEN
		IF numRegs=1 THEN
		 LET erroVar="FOI ENCONTRADO APENAS UM REGISTO!"
		ELSE
		 LET erroVar1 = "FORAM ENCONTRADOS "
		 let erroVar2 = clippedNum(numRegs)
		 let erroVar3 = " REGISTOS!"
		 let erroVar  = erroVar1 clipped,erroVar2 clipped, erroVar3 clipped
		END IF
		CALL mesg(erroVar)
	END IF
	RETURN TRUE
END FUNCTION



#  ======================================================================
#  Funcao de comparacoes de datas.
#  ======================================================================

FUNCTION cmpData(d1,d2)
{}
  DEFINE d1,d2 DATE

  IF (d1 IS NULL) AND (d2 IS NULL) THEN
	 RETURN TRUE
  END IF
  IF (d1 IS NULL) OR (d2 IS NULL) THEN
	 RETURN FALSE
  END IF
  RETURN (DAY(d1)=DAY(d2)) AND (MONTH(d1)=MONTH(d2))
END FUNCTION

###########################################################################
# Devolve o numero total de registo para o cursor cr_tabCnt, tem de ser   #
# ja chamado antes a funcao existem()                                     #
###########################################################################
FUNCTION getNregs()
{}
  OPEN cr_tabCnt
  FETCH cr_tabCnt INTO numRegs
  CLOSE cr_tabCnt
  RETURN numRegs
END FUNCTION


###########################################################################
# fPos - movimento que se pretende fazer no cursor                        #
# currReg - posicao corrente no cursor                                    #
# numRegs - total de registos do cursor                                   #
#                                                                         #
# Devolve retVal TRUE se puder executar o movimento, caso contrario FALSE #
# se devolver TRUE, devolve a nova posicao                                #
###########################################################################
FUNCTION auxMyFetch(fPos,currReg,numRegs)
{}
  DEFINE fPos INTEGER,currReg INTEGER,numRegs INTEGER
  DEFINE oldCurr INTEGER,retVal INTEGER

  LET retVal=FALSE
  LET oldCurr=currReg
  CASE 
    WHEN fPos = 0   # CORRENTE
      IF currReg>numRegs THEN
       LET currReg=numRegs
      END IF
    WHEN fPos = -1  # FIRST
      LET currReg=1
    WHEN fPos = -2  # LAST
      LET currReg=numRegs
    WHEN fPos = -3  # PREVIOUS
      IF currReg>1 THEN
        LET currReg=currReg-1
      ELSE
        CALL erro("JA ESTA NO INICIO DOS ELEMENTOS ENCONTRADOS")
        GOTO fim
      END IF
    WHEN fPos = -4  # NEXT
      IF currReg<numRegs THEN
        LET currReg=currReg+1
      ELSE
        CALL erro("JA ESTA NO FIM DOS ELEMENTOS ENCONTRADOS")
        GOTO fim
      END IF
    OTHERWISE
      IF (fPos>=1) AND (fPos<=numRegs) THEN
        LET currReg=fPos
      ELSE
        GOTO fim
      END IF
  END CASE

  IF (oldCurr=currReg) AND (fPos<0) THEN
    CALL beep()
    GOTO fim
  END IF
  LET retVal=TRUE

  LABEL fim:
  RETURN retVal,currReg

END FUNCTION


###########################################################################
# Compara duas variveis do mesmo tipo e devolve TRUE se forem iguais      #
# verificando se alguma delas e' null                                     #
###########################################################################
FUNCTION ehEqual(var1,var2)
{}
	DEFINE var1 CHAR(80),var2 CHAR(80)
	DEFINE auxVar SMALLINT

	LET auxVar=(var1 CLIPPED=var2 CLIPPED)
	IF auxVar IS NULL THEN
		IF var1 IS NOT NULL OR var2 IS NOT NULL THEN
			RETURN FALSE
		END IF
		RETURN TRUE
	END IF
	RETURN auxVar
END FUNCTION


###########################################################################
# Permite editar um ficheiro com um editor `a sua escolha                 #
# Guarda o editor na d_env para a proxima vez                             #
###########################################################################
FUNCTION d_edit_file(filename)
{}
	Define filename char(256),
			tfile char(256),
			comando  char(500),
			ans smallint

	let ans = menuVertCasc(6,30,2,"","ESCOLHA EDITOR",1,
									     "vi",
									     "joe",
									     "",
									     "",
									     "",
									     "",
									     "",
									     "",
									     "",
									     "",
									     "",
									     "",
									     "",
									     "",
									     "",
									     "",
									     "",
									     "",
									     "")


	case 
   when ans <= 0
		CALL d_dialogOk(9,15,"","",
									  "","EDICAO CANCELADA!",
									  "","")
	when ans=1 # VI
		let comando="vi ", filename clipped, "; clear"
		if year(today)=2000 and month(today)=1
		then
			CALL d_dialogOk(9,15,"","", "",comando, "","")
		end if
		run comando
		sleep 1

	when ans=2 # JOE
		let tfile="/tmp/d_edit.", d_getpid() using "<<<<<<<<<" clipped, ".c"
		let comando="cp ", filename clipped, " ", tfile clipped, 
					   ";joe -help -nobackups -overwrite ", tfile clipped,
						";cp ", tfile clipped," ",  filename clipped,
						";clear "
		if year(today)=2000 and month(today)=1
		then
			CALL d_dialogOk(9,15,"",
										  comando[1,30],
										  comando[31,60],
										  comando[61,90],
										  comando[91,120],
										  comando[121,150])
		end if
		run comando
		sleep 1
	end case
END FUNCTION




# D_ROUND: ARREDONDA UM VALOR SEGUNDO O METODO TRADICIONAL
function d_round(val)
	define val decimal(32,16)
	define res decimal(32,0)

	let res=val using "######################################"
	if res is null
	then
		return 0
	else
		return res
	end if
end function


# D_CEIL: ARREDONDA UM VALOR PARA O INTEIRO IMEDIATAMENTE SUPERIOR
function d_ceil(val)
	define val decimal(32,16)
	define ival decimal(32,0)
	define res decimal(32,0)
	define dec smallint

	let ival=val*1000
	let dec=ival mod 1000
	if dec!=0
	then
		let ival=ival+(1000-dec)
	end if

	let res=ival/1000
	return res

end function
{
function existeTabela(nomeTabela)

define nomeTabela varchar(30)

	select tabname
	from systables
	where tabname="nomeTabela"

		if sqlca.sqlcode = notfound then
			return false
		end if

		return true
		
end function
}

{** 
 *
 * Substitui a função C getkey() apenas para o dynamic 4gl
 * 
 *}
--#function getKey()
--#  return fgl_getkey()
--#end function

