#  ============================================================================ 
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#                                                        
#  Autor: Paulo Santos.
#         Sergio Ferreira.
#                                                        
#  Data de criacao: Tue Nov 03 13:51:27 LISBOA 1992
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
#         Tem de se meter mais um campo adicional que indique tabelas 
#         adicionais, para irem apenas na clausula where.
#         Tem de se testar se a tabela principal tambem esta nos campos
#         adicionais e tabelas adicionais.
#
#  ============================================================================ 



define
	is_upshift smallint

DEFINE
  pa_lov1 ARRAY[8] OF RECORD    # Array das 8 opcoes que estao no ecran
    descr CHAR(80)
  END RECORD,
  pos,oldpos,oldPontPag SMALLINT,
  contas_dec DECIMAL(5,1),
  comp_d, 
  comp_campoC, comp_campoD,     # Tamanho dos campo no ecran em caracteres
  pontPag, corrente, tamPag,
  nova_pag,cont,j SMALLINT,
	conta integer,
  ans          smallint,
  flag,numRegs,numEls,col,colAux,lin SMALLINT,
  pa_lov ARRAY[8] OF RECORD
	 marca CHAR(1),
    id_rowid INTEGER,
    cod CHAR(20),
    descr CHAR(80),
	 camposExtra ARRAY[10] OF CHAR(80)
  END RECORD,
  auxComp,comp_campos,myStatus INTEGER,

   pr_fields    array[10] of record       # Record com cenas dos campos.
    tabname     char(18),                  # Nome da tabela.
    colname     char(18),                  # Nome da coluna.
    tempcolname char(18),              # Nome da coluna na tabela temporaria.
    comprimento smallint
  end record,
  idxcampos                smallint,    # Indice de numero de campos.
   str_sel,qbuf1,buf_ins       char(400),   # String onde vai ficar o select.
   tabelasUtilizadas        char(64),    # String com as tabelas utilizadas.
   camposParaSelect         char(128),   # String com campos para fazer select.
   camposParaAmor           char(128),   # String com campos para fazer select.
   tamanhoTotal             smallint,    # Tamanho total de cada linha da lov.
	marca                    SMALLINT,     # Flag de marcacao
   up			    smallint     # flag que poe os dados em upper



FUNCTION d_amor(linha,     coluna,     # Coordenadas da janela
           tipo_disp, tipo_ret,   # Tipo de display, tipo de return
           marcacao,  pesquisa,   # Flag de marcacao, flag de pesquisa
           titulo,                # Titulo
           tabela,    campoC,     # Tabela principal, campo de codigo
           campoD,    camposExtra,# Campo descodificacao e extra
           condicao,  order_by)   # Clausula where e order by
{}
   DEFINE
      linha,     coluna, 
      tipo_disp,          # Se 2 mostra codigo + descricao. 
								          # Se 1 mostra descricao.
		  tipo_ret,           # 1 Codigo - 2 descricao 3 codi+descricao
      marcacao,  pesquisa        smallint, # True ou false
      titulo                     char(60),
      tabela                     char(64),
      campoC,    campoD          char(18),
      camposExtra                char(90),
      condicao                   char(256),
      order_by                   char(90),
		pos_mesg                   smallint,
		flg_help                   smallint,
		c,d smallint, s array[10] of char(80)

  define indiceNaJanela smallint


  options
	  help key CONTROL-V

  # Inicializacoes
  let idxcampos                = 0 
  let ans                      = true
  initialize camposParaselect  to null
  initialize tabelasUtilizadas to null
   FOR cont=1 TO 8
      INITIALIZE pa_lov1[cont].* TO NULL
   END FOR

   LET marca=marcacao
   let col    = coluna                  # Contas para a janela.
   let lin    = linha
   let colAux = col                     # Esta varivel nao tem razao de existir
	if col is null or col<2 then LET col = 2 END IF
   IF lin is null or lin = 0 THEN LET lin = 2 END IF
 
   IF condicao IS NULL THEN             # Todos os elementos.
      LET condicao = "1=1"
   END IF

   if tipo_disp = 2 then                # Com codigo e descricao
     let camposParaSelect = campoC clipped, ",", campoD clipped
  else
     let camposParaSelect = campoD clipped
  end if
  let tabelasUtilizadas=tabela clipped
                                         # Calculo do tamanho dos campos
	if camposExtra is not null then
      let tamanhoTotal = get_size_for_lov(camposExtra)
   else
		let tamanhoTotal=0
	end if
	LET tamanhoTotal = tamanhoTotal+idxcampos     # Acrescenta numero separadores
   if tipo_disp = 2 then                         # Com codigo e descricao
      let comp_campoC  = get_size(tabela,campoC)
		if comp_campoC > 80 then
		  let comp_campoC=80
      else
		  if comp_campoC=0 then
		    let comp_campoC=5
		  end if
		end if
      let tamanhoTotal = tamanhoTotal + comp_campoC + 1
   end if
   let comp_campoD  = get_size(tabela,campoD)
	if comp_campoD>80 or comp_campoD=0 then
	  let comp_campoD=80
	end if

   let tamanhoTotal = tamanhoTotal + comp_campoD

   # Isto talvez sirva para truncar! Nao ?...
   let comp_d = tamanhoTotal + 1  # Nao sao precisas tantas variaveis.

	# Alterado por Pedro Higgs Menezes
   IF pesquisa  AND comp_d < 40 THEN
		let comp_d = 40
	END IF

   IF comp_d > 77 THEN           # +1 e' para a marca
      LET comp_d = 77
   END IF

	if (col+comp_d)>78 then
	  let col=79-comp_d
	end if
                                          # Validacao das linhas.
   IF lin > 11 THEN LET lin = 11 END IF   # Sao precisas pelo menos 12 linhas.

                                       # Numero de linhas de cada pagina da LOV.
   LET tamPag = 8

  # Talvez tentar utilizar a janela corrente, seleccionado por flag.
   OPEN WINDOW WSysLov AT lin,col 
    WITH 11 ROWS, comp_d COLUMNS ATTRIBUTE(BORDER)

   # O titulo apresentado se couber na LOV. Dava jeito centrar.
   IF comp_d >= LENGTH(titulo) THEN
     let titulo = d_center_str(titulo,comp_d)
     DISPLAY titulo CLIPPED AT 1, 2
   END IF
	let pos_mesg = comp_d - 16
	if pos_mesg = 0 then
		let pos_mesg = 2
	end if
	DISPLAY "CONTROL-W = Help" AT 2, pos_mesg

   # Passar para uma funcao.
   IF pesquisa THEN
      DISPLAY "CRITERIO DE CONSULTA:" AT 3,2
      OPTIONS
         ACCEPT KEY F1,
         PROMPT LINE 4
      let flg_help = true
		while flg_help
			let flg_help = false
         PROMPT "" FOR pa_lov1[1].descr
            ON KEY(ESC)
            LET cont=1
         ON KEY(CONTROL-W)
            let flg_help = true
            call d_amor_help("PROMPT")
         END PROMPT
      end while

     OPTIONS
        ACCEPT KEY ESC
  
     IF int_flag THEN
		  let ans = false
        LET int_flag = FALSE
        call d_dialogOk(9,15,"","Escolha abortada","","","","")
        LET pos = 1 
        INITIALIZE pa_lov[1].* TO NULL
        GOTO fimFunc 
     END IF
	  let pa_lov1[1].descr = pa_lov1[1].descr clipped, "*"
	  if is_upshift then
		  let pa_lov1[1].descr = upshift(pa_lov1[1].descr)
		  display pa_lov1[1].descr at 4, 1
	  end if
   END IF

   let cont=comp_d-13
	if cont>0 then
     call fgl_drawbox(1,cont,3,1)
	  DISPLAY " " AT 3,1
	  DISPLAY " " AT 3,cont
	  LET cont=cont+1
     DISPLAY "Pag    de" AT 3,cont
	end if
   
   # Calculo do numero de paginas
   LET str_sel = "SELECT COUNT(*)",
                 " FROM ", tabelasUtilizadas CLIPPED, 
					  " WHERE ", condicao CLIPPED
   IF pa_lov1[1].descr IS NOT NULL and pa_lov1[1].descr != "*" THEN
      LET str_sel = str_sel CLIPPED," AND (",campoD clipped,
		              " MATCHES '",pa_lov1[1].descr clipped,"' OR ",
		              campoD clipped," IS NULL) "
   END IF


   PREPARE PLovCnt FROM str_sel
   DECLARE CLovCnt SCROLL CURSOR FOR PLovCnt
   OPEN CLovCnt
   FETCH CLovCnt INTO conta
   LET numRegs=conta
   LET contas_dec = conta / tamPag
   LET conta = conta / tamPag 
   LET conta = conta + (conta < contas_dec)
   CLOSE CLovCnt
  
   # Select propriamente dito.

if up = 0 THEN

   LET str_sel = "SELECT ",tabela clipped,".ROWID,", 
				     camposParaSelect clipped,
                 " FROM ", tabelasUtilizadas CLIPPED, 
                 " WHERE ", condicao CLIPPED
   IF pa_lov1[1].descr IS NOT NULL and pa_lov1[1].descr != "*" THEN
      LET str_sel = str_sel CLIPPED," AND (",campoD clipped,
		              " MATCHES '",pa_lov1[1].descr clipped,"' OR ",
		              campoD clipped," IS NULL) "
   END IF
   let buf_ins=str_sel

else

   LET str_sel = "SELECT ",tabela clipped,".ROWID,", 
				     camposParaSelect clipped,
                 " FROM ", tabelasUtilizadas CLIPPED, 
                 " WHERE ", condicao CLIPPED
   IF pa_lov1[1].descr IS NOT NULL and pa_lov1[1].descr != "*" THEN
      LET str_sel = str_sel CLIPPED," AND (UPPER(",campoD clipped,") MATCHES UPPER('",pa_lov1[1].descr clipped,"') OR ",
		              campoD clipped," IS NULL) "
   END IF
   let buf_ins=str_sel

end if


   {PREPARE PLov FROM str_sel
   DECLARE CLov SCROLL CURSOR FOR PLov
   OPEN CLov}
 
   # Tabela para possibilitar marcar linhas
 
	IF tipo_disp=2 THEN
	  LET camposParaAmor=campoC CLIPPED,",",campoD CLIPPED
	  LET qbuf1="CREATE TEMP TABLE amor (marca CHAR(1),id_rowid INTEGER,",
					 campoC CLIPPED," CHAR(20),",campoD CLIPPED," CHAR(80)"
	ELSE
	  LET camposParaAmor=campoD CLIPPED
	  LET qbuf1="CREATE TEMP TABLE amor (marca CHAR(1),id_rowid INTEGER,",
					campoD CLIPPED," CHAR(80)"
	END IF
	FOR j=1 TO idxcampos
	   LET qbuf1=qbuf1 CLIPPED,",",pr_fields[j].tempcolname CLIPPED," CHAR(80)"
	   LET camposParaAmor=camposParaAmor CLIPPED,",",
		    pr_fields[j].tempcolname clipped
	END FOR
	LET qbuf1=qbuf1 CLIPPED,")","WITH NO LOG"
	PREPARE PAmor FROM qbuf1
	EXECUTE PAmor

	LET qbuf1="INSERT INTO amor (id_rowid,",camposParaAmor CLIPPED,") ",
				 buf_ins CLIPPED 
	PREPARE PAmor1 FROM qbuf1
	EXECUTE PAmor1

	let str_sel  = "SELECT * FROM amor "
   if order_by is not null then
       LET str_sel = str_sel CLIPPED, " ORDER BY ", order_by clipped
   end if
	prepare stat_sel_amor from str_sel
	DECLARE cr_AMOR SCROLL CURSOR FOR stat_sel_amor


   #  Ajustamentos esquisitos
   LET corrente = 1
   LET col      = comp_d-2
   DISPLAY conta AT 3,col ATTRIBUTE(REVERSE)
   LET  pontPag = 1
   LET pos      = 1
   LET col      = comp_d-8
  
	# Atencao a esta variavel.
	{  LIXO.
	if camposExtra is null then
		let idxcampos = 0
	end if
	}

   WHILE TRUE

      LET numEls=tamPag
      LET flag=TRUE
	   OPEN cr_AMOR
      FOR cont = pontPag TO pontPag + tamPag - 1
         cASE 
            WHEN tipo_disp = "1"                 # Mostra apenas o codigo
               CASE
					  WHEN idxcampos = 0
                   FETCH ABSOLUTE cont cr_AMOR 
					      INTO pa_lov[cont-pontPag+1].marca,
								  pa_lov[cont-pontPag+1].id_rowid,
								  pa_lov[cont-pontPag+1].descr
					  WHEN idxcampos = 1
                   FETCH ABSOLUTE cont cr_AMOR 
					     INTO pa_lov[c].marca,pa_lov[c].id_rowid,pa_lov[c].descr,
								 s[1]
					  WHEN idxcampos = 2
                   FETCH ABSOLUTE cont cr_AMOR 
					     INTO pa_lov[cont-pontPag+1].marca,
						       pa_lov[cont-pontPag+1].id_rowid,
								 pa_lov[cont-pontPag+1].descr,
								 s[1], s[2]
					  WHEN idxcampos = 3
                   FETCH ABSOLUTE cont cr_AMOR 
					     INTO pa_lov[cont-pontPag+1].marca,
						       pa_lov[cont-pontPag+1].id_rowid,
								 pa_lov[cont-pontPag+1].descr,
								 s[1], s[2], s[3]
					  WHEN idxcampos = 4
                   FETCH ABSOLUTE cont cr_AMOR 
					     INTO pa_lov[cont-pontPag+1].marca,
						       pa_lov[cont-pontPag+1].id_rowid,
								 pa_lov[cont-pontPag+1].descr,
								 s[1], s[2], s[3], s[4]
					  WHEN idxcampos = 5
                   FETCH ABSOLUTE cont cr_AMOR 
					     INTO pa_lov[cont-pontPag+1].marca,
						       pa_lov[cont-pontPag+1].id_rowid,
								 pa_lov[cont-pontPag+1].descr,
								 s[1], s[2], s[3], s[4], s[5]
					  WHEN idxcampos = 6
                   FETCH ABSOLUTE cont cr_AMOR 
					     INTO pa_lov[cont-pontPag+1].marca,
						       pa_lov[cont-pontPag+1].id_rowid,
								 pa_lov[cont-pontPag+1].descr,
								 s[1], s[2], s[3], s[4], s[5], 
								 s[6]
					  WHEN idxcampos = 7
                   FETCH ABSOLUTE cont cr_AMOR 
					     INTO pa_lov[cont-pontPag+1].marca,
						       pa_lov[cont-pontPag+1].id_rowid,
								 pa_lov[cont-pontPag+1].descr,
								 s[1], s[2], s[3], s[4], s[5], 
								 s[6], s[7]
					  WHEN idxcampos = 8
                   FETCH ABSOLUTE cont cr_AMOR 
					     INTO pa_lov[cont-pontPag+1].marca,
						       pa_lov[cont-pontPag+1].id_rowid,
								 pa_lov[cont-pontPag+1].descr,
								 s[1], s[2], s[3], s[4], s[5], 
								 s[6], s[7], s[8]
					  WHEN idxcampos = 9
                   FETCH ABSOLUTE cont cr_AMOR 
					     INTO pa_lov[cont-pontPag+1].marca,
						       pa_lov[cont-pontPag+1].id_rowid,
								 pa_lov[cont-pontPag+1].descr,
								 s[1], s[2], s[3], s[4], s[5], 
								 s[6], s[7], s[8], s[9]
					  WHEN idxcampos = 10
                   FETCH ABSOLUTE cont cr_AMOR 
					     INTO pa_lov[cont-pontPag+1].marca,
						       pa_lov[cont-pontPag+1].id_rowid,
								 pa_lov[cont-pontPag+1].descr,
								 s[1], s[2], s[3], s[4], s[5], 
								 s[6], s[7], s[8], s[9], s[10]
					END CASE
					let c = cont-pontPag+1
					for d = 1 to idxcampos
					   let pa_lov[c].camposExtra[d] = s[d]
					end for
					LET myStatus=STATUS
               LET pa_lov1[cont-pontPag+1].descr=
						  	  pa_lov[cont-pontPag+1].marca,
							  pa_lov[cont-pontPag+1].descr[1,comp_campoD]
					     let comp_campos = getMaxComprimento(comp_campos)
	            if camposExtra is not null then
					  FOR j=1 TO idxcampos
                   LET auxComp=pr_fields[j].comprimento
                   LET pa_lov1[cont-pontPag+1].descr=
							  pa_lov1[cont-pontPag+1].descr[1,comp_campos],"-",
							  pa_lov[cont-pontPag+1].camposExtra[j][1,auxComp]
                 LET comp_campos=comp_campos+auxComp+1
					  END FOR
					end if
							 let comp_campos = getMaxComprimento(comp_campos)

            WHEN tipo_disp = "2"                  # Mostra o Codigo e descricao 
               CASE 
					  WHEN idxcampos = 0
                   FETCH ABSOLUTE cont cr_AMOR 
					      INTO pa_lov[cont-pontPag+1].marca,
								  pa_lov[cont-pontPag+1].id_rowid,
							     pa_lov[cont-pontPag+1].cod,
								  pa_lov[cont-pontPag+1].descr
					  WHEN idxcampos = 1
                   FETCH ABSOLUTE cont cr_AMOR 
					      INTO pa_lov[cont-pontPag+1].marca,
								  pa_lov[cont-pontPag+1].id_rowid,
							     pa_lov[cont-pontPag+1].cod,
								  pa_lov[cont-pontPag+1].descr,
								  s[1]
					  WHEN idxcampos = 2
                   FETCH ABSOLUTE cont cr_AMOR 
					      INTO pa_lov[cont-pontPag+1].marca,
								  pa_lov[cont-pontPag+1].id_rowid,
							     pa_lov[cont-pontPag+1].cod,
								  pa_lov[cont-pontPag+1].descr,
								  s[1], s[2]
					  WHEN idxcampos = 3
                   FETCH ABSOLUTE cont cr_AMOR 
					      INTO pa_lov[cont-pontPag+1].marca,
								  pa_lov[cont-pontPag+1].id_rowid,
							     pa_lov[cont-pontPag+1].cod,
								  pa_lov[cont-pontPag+1].descr,
								  s[1], s[2], s[3]
					  WHEN idxcampos = 4
                   FETCH ABSOLUTE cont cr_AMOR 
					      INTO pa_lov[cont-pontPag+1].marca,
								  pa_lov[cont-pontPag+1].id_rowid,
							     pa_lov[cont-pontPag+1].cod,
								  pa_lov[cont-pontPag+1].descr,
								  s[1], s[2], s[3], s[4]
					  WHEN idxcampos = 5
                   FETCH ABSOLUTE cont cr_AMOR 
					      INTO pa_lov[cont-pontPag+1].marca,
								  pa_lov[cont-pontPag+1].id_rowid,
							     pa_lov[cont-pontPag+1].cod,
								  pa_lov[cont-pontPag+1].descr,
								  s[1], s[2], s[3], s[4], s[5]
					  WHEN idxcampos = 6
                   FETCH ABSOLUTE cont cr_AMOR 
					      INTO pa_lov[cont-pontPag+1].marca,
								  pa_lov[cont-pontPag+1].id_rowid,
							     pa_lov[cont-pontPag+1].cod,
								  pa_lov[cont-pontPag+1].descr,
								  s[1], s[2], s[3], s[4], s[5], 
								  s[6]
					  WHEN idxcampos = 7
                   FETCH ABSOLUTE cont cr_AMOR 
					      INTO pa_lov[cont-pontPag+1].marca,
								  pa_lov[cont-pontPag+1].id_rowid,
							     pa_lov[cont-pontPag+1].cod,
								  pa_lov[cont-pontPag+1].descr,
								  s[1], s[2], s[3], s[4], s[5], 
								  s[6], s[7]
					  WHEN idxcampos = 8
                   FETCH ABSOLUTE cont cr_AMOR 
					      INTO pa_lov[cont-pontPag+1].marca,
								  pa_lov[cont-pontPag+1].id_rowid,
							     pa_lov[cont-pontPag+1].cod,
								  pa_lov[cont-pontPag+1].descr,
								  s[1], s[2], s[3], s[4], s[5], 
								  s[6], s[7], s[8]
					  WHEN idxcampos = 9
                   FETCH ABSOLUTE cont cr_AMOR 
					      INTO pa_lov[cont-pontPag+1].marca,
								  pa_lov[cont-pontPag+1].id_rowid,
							     pa_lov[cont-pontPag+1].cod,
								  pa_lov[cont-pontPag+1].descr,
								  s[1], s[2], s[3], s[4], s[5], 
								  s[6], s[7], s[8], s[9]
					  WHEN idxcampos = 10
                   FETCH ABSOLUTE cont cr_AMOR 
					      INTO pa_lov[cont-pontPag+1].marca,
								  pa_lov[cont-pontPag+1].id_rowid,
							     pa_lov[cont-pontPag+1].cod,
								  pa_lov[cont-pontPag+1].descr,
								  s[1], s[2], s[3], s[4], s[5], 
								  s[6], s[7], s[8], s[9], s[10]
					END CASE

					let c = cont-pontPag+1
					for d = 1 to idxcampos
					   let pa_lov[c].camposExtra[d] = s[d]
					end for
					LET myStatus=STATUS

					# ??? Quem meteu isto assim e comentou as outras tres linhas ???
               #LET pa_lov1[cont-pontPag+1].descr=pa_lov[cont-pontPag+1].marca,
               #    pa_lov[cont-pontPag+1].cod,"-",
               #    pa_lov[cont-pontPag+1].descr
          LET pa_lov1[cont-pontPag+1].descr=pa_lov[cont-pontPag+1].marca,
                   pa_lov[cont-pontPag+1].cod[1,comp_campoC],"-",
                   pa_lov[cont-pontPag+1].descr[1,comp_campoD]
          LET comp_campos=comp_campoC+comp_campoD+2
					let comp_campos = getMaxComprimento(comp_campos)
					FOR j=1 TO idxcampos
            LET auxComp=pr_fields[j].comprimento
					  let indiceNaJanela = cont-pontPag + 1
            LET pa_lov1[indiceNaJanela].descr= 
					  		pa_lov1[cont-pontPag+1].descr[1,comp_campos],"-",
					  		pa_lov[cont-pontPag+1].camposExtra[j][1,auxComp]
            LET comp_campos=comp_campos+auxComp+1
					  let comp_campos = getMaxComprimento(comp_campos)
					END FOR
					let comp_campos = getMaxComprimento(comp_campos)
         END CASE
         IF myStatus = NOTFOUND THEN
            IF flag THEN
               LET numEls=cont-pontPag
               LET flag=FALSE
            END IF

            INITIALIZE pa_lov[cont-pontPag+1].cod TO NULL
            LET pa_lov[cont-pontPag+1].descr=" "
            LET pa_lov1[cont-pontPag+1].descr=" "
          END IF
        END FOR

        IF numEls = 0 THEN
           call d_dialogOk(9,15,"",
					 "Nao existem entradas nesta tabela","","","","")
		     let ans = false
           LET pos = 1
           INITIALIZE pa_lov[1].* TO NULL
           EXIT WHILE
         END IF


    IF handlerTecla()  THEN
       IF int_flag THEN
		    let ans = false
          LET int_flag=FALSE
          call d_dialogOk(9,15,"","Escolha abortada","","","","")
          LET pos=1
          INITIALIZE pa_lov[1].* TO NULL
       END IF
       EXIT WHILE
    END IF
  END WHILE

   CLOSE cr_AMOR

LABEL fimFunc:

	options
		help key CONTROL-W

   CLOSE WINDOW WSysLov

   CASE 
		when tipo_ret = 0
			return ans

      WHEN tipo_ret = 1
			whenever error continue
			DROP TABLE amor
			if status != -206 and status != 0 then
				call d_erro()
			end if
			whenever error stop
         RETURN pa_lov[pos].cod
      WHEN tipo_ret = 2
			whenever error continue
			DROP TABLE amor
			whenever error stop
         RETURN pa_lov[pos].descr    
      WHEN tipo_ret = 3
			whenever error continue
			DROP TABLE amor
			whenever error stop
         RETURN pa_lov[pos].cod, pa_lov[pos].descr
   END CASE

END FUNCTION


#  ======================================================================
# Funcao que faz o input da nova pagina
#
#  Entradas:
#   corrente -> Variavel com a pagina corrente
#   conta -> Numero de paginas existentes na LOV
#
#  Saidas
#   corrente -> variavel com a nova pagina
#  ======================================================================
FUNCTION NovaPag ()
{}
DEFINE
     linha SMALLINT,
     coluna SMALLINT,
     novoCorrente SMALLINT 

LET linha=lin+2
LET coluna=colAux+comp_d-10
OPEN WINDOW NovaPag AT linha,coluna WITH 1 ROWS,3 COLUMNS 
LET int_flag = FALSE

OPTIONS
  ACCEPT KEY F1
PROMPT " " FOR novoCorrente
  ON KEY(ESC)
   LET cont=1
      ON KEY(CONTROL-W)
		   call d_amor_help("MENU")
END PROMPT
OPTIONS
  ACCEPT KEY ESC

IF int_flag THEN
	 let ans = false
    LET int_flag = FALSE
      CLOSE WINDOW NovaPag
      DISPLAY corrente USING "##" AT 3,col ATTRIBUTE(REVERSE)
END IF
IF novoCorrente IS NOT NULL AND novoCorrente >= 1 AND novoCorrente <= conta THEN
  LET corrente=novoCorrente
END IF

CLOSE WINDOW NovaPag
DISPLAY corrente USING "##" AT 3,col ATTRIBUTE(REVERSE)

END FUNCTION 





FUNCTION displayArr(n,reverse)
{}
 
 DEFINE n,reverse INTEGER
 DEFINE e INTEGER

 LET pa_lov1[n].descr=pa_lov1[n].descr CLIPPED
 LET e=n+3
 IF reverse THEN
  DISPLAY pa_lov1[n].descr AT e,1 ATTRIBUTE(REVERSE) 
 ELSE
  DISPLAY pa_lov1[n].descr AT e,1
 END IF

END FUNCTION




#  ============================================================================ 
#  Trata do processamento das teclas
#  ============================================================================ 

FUNCTION handlerTecla()
{}
   define
		tecla smallint

  LET int_flag = FALSE
  FOR cont=1 TO tamPag 
    CALL displayArr(cont,FALSE)
  END FOR
  LET oldpos=pos
  LET oldPontPag=pontPag
  WHILE oldPontPag=pontPag
     DISPLAY corrente USING "##" AT 3,col ATTRIBUTE(REVERSE)
    if oldpos!=pos then
     call displayArr(oldpos,FALSE)
     let oldpos=pos
    end if
     CALL displayArr(pos,TRUE)
    let tecla = getKey()
    #CASE getKey()
    CASE
      WHEN tecla = 2000  # KEY UP
      if pos>1 then
       let pos=pos-1
       LET corrente=(pontPag+pos-1)/tamPag + (((pontPag+pos-1) mod tamPag)!=0)
      else
       if pontPag>1 then
          LET pontPag=pontPag-1
         LET corrente=(pontPag+pos-1)/tamPag + (((pontPag+pos-1) mod tamPag)!=0)
       else
        LET corrente = conta 
           LET  pontPag =numRegs-numEls+1
        let pos=numEls
       end if
      end if

      WHEN tecla = 2001  # KEY DOWN
        if pos<numEls then
       let pos=pos+1
       LET corrente = (pontPag+pos-1)/tamPag + (((pontPag+pos-1) mod tamPag)!=0)
      else
       if pontPag+numEls-1<numRegs then
          LET pontPag=pontPag+1
         LET corrente = (pontPag+pos-1)/tamPag + (((pontPag+pos-1) mod tamPag)!=0)
       else
        let pos=1
          LET pontPag=1
        LET corrente = 1
       end if
      end if

    WHEN tecla = 115 # s - seguinte
    call pag_seguinte()

    WHEN tecla = 62 # s - seguinte
    call pag_seguinte()

    WHEN tecla = 97 # a - anterior 
     call pag_anterior()

    WHEN tecla = 60 # a - anterior 
     call pag_anterior()


    WHEN tecla = 103 # g - posiciona na pagina
      CALL NovaPag()
      LET  pontPag = ( corrente - 1 ) * tamPag + 1
      LET pos=1

      WHEN tecla = 117 # u - posiciona na ultima pagina
        LET corrente = conta
           LET  pontPag = ( corrente - 1 ) * tamPag + 1
        LET pos=1

      WHEN tecla = 112 # p - posiciona na primeira pagina
        LET corrente = 1
           LET  pontPag = ( corrente - 1 ) * tamPag + 1
        LET pos=1

      WHEN tecla = 32  # tecla espaco
        if pos<numEls then
       let pos=pos+1
       LET corrente = (pontPag+pos-1)/tamPag + (((pontPag+pos-1) mod tamPag)!=0)
      else
       if pontPag+numEls-1<numRegs then
          LET pontPag=pontPag+1
         LET corrente = (pontPag+pos-1)/tamPag + (((pontPag+pos-1) mod tamPag)!=0)
       else
        let pos=1
          LET pontPag=1
        LET corrente = 1
       end if
      end if

    WHEN tecla = 27 # ESCAPE
		IF marca THEN 
		  RETURN TRUE
		END IF

    WHEN tecla = 13 # CONTROL-M
		IF marca THEN
		  CALL marcando()
		ELSE
        RETURN TRUE
		END IF

	 when tecla = 23 # CONTROL-W - Help
		 call d_amor_help("MENU")

    OTHERWISE
      IF int_flag THEN
	     let ans = false
        return true
      END IF
    END CASE
    if oldPontPag=pontPag then
     if pos=oldpos AND marca=FALSE then
       ERROR ""
     end if
    else
     exit while
    end if
   END WHILE
return false
end function



function    pag_anterior()
{}
      IF corrente > 1 THEN 
        LET corrente = corrente - 1
           LET  pontPag = ( corrente - 1 ) * tamPag + 1
        LET pos=1
      ELSE
         call d_dialogOk(9,15,"","Nao existem paginas anteriores","","","","")
      END IF
end function


function    pag_seguinte()
{}
      IF corrente <> conta THEN
        LET  pontPag = corrente  * tamPag + 1
        LET  corrente = corrente + 1
        LET pos=1
      ELSE
         call d_dialogOk(9,15,"","Nao existem mais paginas","","","","")
      END IF
end function




#  ======================================================================
#  Faz um parse a string que se passa, e que e' da forma:
#    "tab.campo, tab.campo, campo, etc"
#  ======================================================================
function    get_size_for_lov(campos)
{}
  define
    campos       char(128),                # Atencao ao tamanho da string.
    tok          char(18),
    idx          smallint,
    idxtab       smallint,
    jaExiste     smallint,
    i,j          smallint,
    tcampos       smallint,
    tabelas       array[5] of char(19),
    estado        smallint                 # 0 - Estado inicial
                              # 1 - Apanhou nome tabela
                              # 2 - Apanhou ponto
                              # 3 - Apanhou tabela e campo

  let idxcampos = 1 
  let idx       = 1
  let estado    = 0

   while 1=1
    call get_names(campos,idx) returning tok, idx
    case
      when tok="$"                           # Chegou ao fim da string
        if estado = 1 OR estado=2 then
           let pr_fields[idxcampos].colname = pr_fields[idxcampos].tabname
           initialize pr_fields[idxcampos].tabname to null 
        end if
        if estado != 0 then
           let idxcampos = idxcampos + 1
        end if
        exit while

      when tok=" "                           # Separador 
        if estado = 1 OR estado = 2 then
           let pr_fields[idxcampos].colname = pr_fields[idxcampos].tabname
           initialize pr_fields[idxcampos].tabname to null 
        end if
        if estado != 0 then
           let idxcampos = idxcampos + 1
           let estado = 0
        end if

      when tok="."                           # Ponto
        let estado=2

      otherwise                          # Identificador
        case
          when estado = 0
            let pr_fields[idxcampos].tabname = tok
            let estado = 1
          when estado = 2
              let pr_fields[idxcampos].colname = tok
            let estado=3
            #let idxcampos = idxcampos+1
          otherwise
        end case
    end case
  end while
  let idxcampos = idxcampos - 1

  #  Aqui ja os campos estao nas strings.

  let tcampos  = 0

  let idxtab   = 1

  LET tabelas[1]=tabelasUtilizadas CLIPPED

  let jaExiste = true

   for i = 1 to idxcampos
    let pr_fields[i].tempcolname = pr_fields[i].tabname[1,3], 
                         pr_fields[i].colname clipped
    let pr_fields[i].comprimento = get_size(pr_fields[i].tabname,
                             pr_fields[i].colname)
    let tcampos = tcampos+pr_fields[i].comprimento
	 if pr_fields[i].tabname is not null then
       for j = 1 to idxtab
         if tabelas[j] = pr_fields[i].tabname clipped then
           let jaExiste=true
           exit for
         else
           let jaExiste=false
         end if
      end for
	 else
		 let jaExiste = true
	 end if
                   # Talvez nao fosse mau testar o valor maximo!...
    if not jaExiste then     
      let idxtab = idxtab + 1
      let tabelas[idxtab] = pr_fields[i].tabname clipped 
    end if
    let camposParaSelect = camposParaSelect CLIPPED, ",", pr_fields[i].colname CLIPPED
  end for

IF idxtab>1 THEN
  for j=2 to idxtab
    let tabelasUtilizadas = tabelasUtilizadas clipped, ",", tabelas[j]
  end for
END IF

  return tcampos
end function


#  ==========================================================================
#  ??? Devia ser usada uma funcao generica
#  Eu acho que ate existe.
#  Mas para ja fica esta
#  ==========================================================================
function    get_size(tabname,colname)
{}
   define
    tabname   char(18),
    colname   char(18),
    coltype   smallint,
    tamanho   smallint
   
  if tabname is not null then
      select @coltype, @collength
         into coltype, tamanho
         from systables, syscolumns
         where syscolumns.colname = colname
          and syscolumns.tabid = systables.tabid
          and systables.tabname = tabname
	   if status=NOTFOUND then        # no caso de tabelas temporarias
		  let coltype=-1
		end if
   else
    declare cr_syst cursor for
         select @coltype, @collength
            from syscolumns
            where syscolumns.colname = colname
    open cr_syst
    fetch cr_syst into coltype, tamanho
	 if status=NOTFOUND then        # no caso de tabelas temporarias
	   let coltype=-1
	 end if
    close cr_syst
   end if

	if coltype > 255 then
	   let coltype = coltype - 256
	end if
   case
    #when  coltype = 0   # Char - Tamanho fica o mesmo
    when  coltype = 1   # Smallint
      let tamanho=5
    when  coltype = 2   # Integer
      let tamanho=9
    when  coltype = 3   # Float
      let tamanho=9
    when  coltype = 4   # Smallfloat
      let tamanho=9
    when  coltype = 5   # Decimal             ??? Devia ver precisao
      let tamanho=9
    when  coltype = 6   # Serial
      let tamanho=9
    when  coltype = 7   # Date
      let tamanho=10
    when  coltype = 8   # Money
      let tamanho=9
    when  coltype = 10  # Datetime            ??? Devia calcular precisao
      let tamanho=16
    when  coltype = 14  # Interval            ??? Devia calcular precisao
      let tamanho=16
	 when coltype = -242
      let tamanho=16
    when  coltype = -1  # Temporaria
      let tamanho=0
  end case

  return tamanho

end function





#  ============================================================================ 
#  Vai buscar os nomes dos campos e tabelas que estao numa string
#  ============================================================================ 
function    get_names(campos,indice)
{}
   define
    campos     char(128),
    indice     smallint,
    token      char(20),
    idxrt      smallint,
    tamanho    smallint
   
  let idxrt   = 1
  initialize token to null
  let tamanho = length(campos)

  while ( 1 = 1 )
    if indice > tamanho then
      if token is null then
        let indice = indice + 1
         let token = "$"
      end if
      exit while
    end if

    case 
      when campos[indice,indice] = "."
        if token is null then
          let indice = indice + 1
           let token = "."
        end if
        exit while
      when campos[indice,indice]=","
        if token is null then
          let indice = indice + 1
           let token = " "
        end if
        exit while
      when campos[indice,indice]=" "
        if token is null then
          let indice = indice + 1
           let token = " "
        end if
        exit while
      when campos[indice,indice]="  "
        if token is null then
          let indice = indice + 1
           let token = " "
        end if
        exit while
      otherwise
        let token[idxrt,idxrt] = campos[indice,indice]
        let idxrt = idxrt + 1
          let indice = indice + 1
    end case
  end while

   return token, indice
end function




FUNCTION marcando()
{}

  IF pa_lov[pos].marca="*" THEN
	 LET pa_lov1[pos].descr[1,1]=" "
	 LET pa_lov[pos].marca=" "
  ELSE
	 LET pa_lov1[pos].descr[1,1]="*"
	 LET pa_lov[pos].marca="*"
  END IF
  UPDATE amor SET marca=pa_lov[pos].marca WHERE id_rowid=pa_lov[pos].id_rowid

END FUNCTION

function d_set_upshift_amor()
	let is_upshift = true
end function


function d_reset_upshift_amor()
	let is_upshift = false
end function



#  ============================================================================ 
#  Executa o help relativo a tecles de d_amor.
#  ============================================================================ 
function d_amor_help(tipo)
{}
   define
		tipo char(10)

   if tipo = "MENU" then
      call d_dialogOk(9,15,"ESC/Enter = Selecciona opcao corrente",
									"Seta cima = Anterior     Seta baixo = Seguinte",
		                     "> = Pagina Seguinte      < = Pagina Anterior",
									"CTRL-C = Aborta busca    G = Seleccao de pagina",
									"P = Primeira Pagina      U = Ultima Pagina",
									"")
	else
      call d_dialogOk(9,15,"Digite o criterio correspondente",
									"a descricao pretendida",
									"",
		                     "* - Significa qualquer conjunto de caracteres",
									"? - Significa qualquer caracter",
									"")
	end if
end function

# ============================================================================
# Poe a opcao UPPER.
# ============================================================================
function setUpper()

   let up = 1

end function



#  Devolve o maximo de comprimento de acordo com o que esta escolhido
function getMaxComprimento(comp)
  define comp smallint

  if comp >80 then
    let comp = 78
  end if
  return comp
end function
