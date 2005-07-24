#  ============================================================================ 
#
#  Copyright 1995 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#  Rua da Prata 166 4.o Dto
#  1100 LISBOA
#                                                        
#  Autor: Paulo Santos
#         Sergio Ferreira
#                                                        
#  Data de criacao: Thu Nov 09 14:29:34 LISBOA 1995
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : Livraria de funcoes genericas
#  ---------------------------------------------------------------------------
#  DESCRICAO: Menus verticais
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
#    Foi Alterado Por Pedro Higgs Menezes o Tamanho do campo descr do Array
#  pa_opcoes de 80 para 39
#    Feita uma primeira passagem para resolver o problema de Alocacao de 
#  memoria.
#    Tirar tudo o que e error
#
#  ============================================================================ 

DEFINE
	pa_opcoes ARRAY[19] OF RECORD      # Array de opcoes
		selLetra char(1),
		descr CHAR(39)                  # Descricao
	END RECORD,
   pos           SMALLINT,
   com_titulo    INTEGER,
	lenAux SMALLINT,
   CascWinStat   CHAR(9),
	displayOpcoes INTEGER

#  ============================================================================ 
#    FUNCAO QUE CONSTROI MENU VERTICAL COM POSSIBILIDADE DE CASCATA      #
#                                                                        #
#  - Parametros de entrada:                                              #
#                - linha,coluna (para posicionar o menu)                 #    
#                - numero de opcoes
#                - nivel de cascata(opcional)                            #
#                - titulo para menu(opcional)                            #
#                - opcao para posicionamento inicial(opcional)           #
#                - diversas strings consoante o numero de opcoes         # 
#  - Retorna opcao seleccionada                                          #
#  ============================================================================ 
FUNCTION menuVertCasc(lin,col,num_opcoes,nivel_cascata,titulo,opcao,
							 str0,str1,str2,str3,str4,
                      str5,str6,str7,str8,str9,
							 str10,str11,str12,str13,
							 str14,str15,str16,str17,str18)
{}
   DEFINE
      lin,col,num_opcoes,nivel_cascata SMALLINT,
      titulo                           char(80),
      opcao                            SMALLINT,
      str0,str1,str2,str3,str4,
		str5,str6,str7,str8,str9,
      str10,str11,str12,str13,str14,
		str15,str16,str17,str18         CHAR(39),
      larg_menu                       smallint   # Largura do menu

	whenever error call d_erro
   IF num_opcoes>19 OR num_opcoes<2 THEN
	  error "Numero de opcoes: 2 a 19"
	  RETURN 0
	END IF

	# Colunas de dafaul se errado
   IF col < 2 THEN LET col = 2 END IF
   IF lin < 2 THEN LET lin = 2 END IF

	# Conversao das strings para Array
	LET pa_opcoes[1].selLetra=str0[1] 
	LET pa_opcoes[1].descr=str0 clipped
	LET pa_opcoes[2].selLetra=str1[1]
	LET pa_opcoes[2].descr=str1 clipped
	LET pa_opcoes[3].selLetra=str2[1]
	LET pa_opcoes[3].descr=str2 clipped
	LET pa_opcoes[4].selLetra=str3[1]
	LET pa_opcoes[4].descr=str3 clipped
	LET pa_opcoes[5].selLetra=str4[1] 
	LET pa_opcoes[5].descr=str4 clipped
	LET pa_opcoes[6].selLetra=str5[1]
	LET pa_opcoes[6].descr=str5 clipped
	LET pa_opcoes[7].selLetra=str6[1]
	LET pa_opcoes[7].descr=str6 clipped
	LET pa_opcoes[8].selLetra=str7[1]
	LET pa_opcoes[8].descr=str7 clipped
	LET pa_opcoes[9].selLetra=str8[1]
	LET pa_opcoes[9].descr=str8 clipped
	LET pa_opcoes[10].selLetra=str9[1]
	LET pa_opcoes[10].descr=str9 clipped
	LET pa_opcoes[11].selLetra=str10[1]
	LET pa_opcoes[11].descr=str10 clipped
	LET pa_opcoes[12].selLetra=str11[1]
	LET pa_opcoes[12].descr=str11 clipped
	LET pa_opcoes[13].selLetra=str12[1]
	LET pa_opcoes[13].descr=str12 clipped
	LET pa_opcoes[14].selLetra=str13[1]
	LET pa_opcoes[14].descr=str13 clipped
	LET pa_opcoes[15].selLetra=str14[1]
	LET pa_opcoes[15].descr=str14 clipped
	LET pa_opcoes[16].selLetra=str15[1]
	LET pa_opcoes[16].descr=str15 clipped
	LET pa_opcoes[17].selLetra=str16[1]
	LET pa_opcoes[17].descr=str16 clipped
	LET pa_opcoes[18].selLetra=str17[1]
	LET pa_opcoes[18].descr=str17 clipped
	LET pa_opcoes[19].selLetra=str18[1]
	LET pa_opcoes[19].descr=str18 clipped
 
   LET larg_menu = maxLengthCas(titulo)
	IF larg_menu = 0 THEN
	  error "Valores validos de dimensao de strings: 1-70"
	END IF

   CALL AbreWindCas(num_opcoes,larg_menu,lin,col,nivel_cascata,titulo)

	# Opcao inicial e inicializacao de flag de Interrupt
   LET int_flag=FALSE
   IF opcao IS NULL THEN LET opcao=1 END IF
   CALL edArayCas(num_opcoes,opcao) RETURNING pos
   IF int_flag THEN
	   LET int_flag = FALSE
	   error "ESCOLHA ABORTADA"
   END IF

   IF nivel_cascata IS NULL THEN
      CLOSE WINDOW WmenuVert
   ELSE
	   #IF pos=0 THEN
        call closeWindMenu(nivel_cascata)
	   #END IF
   END IF 
   RETURN pos
END FUNCTION


#  ============================================================================ 
#  Abertura da janela correspondente ao menu, e ao nivel pretendido
#  ============================================================================ 
FUNCTION AbreWindCas(num_opc,larg_w,lin,col,nivel_cascata,titulo)
{}
   DEFINE 
      num_opc,                       # Numero de opcoes
		larg_w,                        # Largura da Janela
		lin,col,nivel_cascata     SMALLINT,
		titulo                    char(80),
      colTitulo,dimTitulo       INTEGER

  LET larg_w = larg_w + 2            # Para o Border
  LET com_titulo = FALSE
  IF titulo IS NOT NULL THEN
	 LET dimTitulo=length(titulo)
	 LET com_titulo=TRUE
	 LET num_opc=num_opc+2    # reserva linhas para escrever titulo
  END IF
  IF lin>23-num_opc THEN 
	 LET lin=23-num_opc 
  END IF 
  if (col+larg_w)>78 then 
	 let col=79-larg_w 
  end if
  let displayOpcoes=TRUE 
  if nivel_cascata is not null then
	 if CascWinStat[nivel_cascata]="O" THEN
	   let displayOpcoes=FALSE 
    end if
  end if

   CASE
      when nivel_cascata = 1
         IF CascWinStat[1]="O" THEN
            call curr_win(1)
         else
            call open_win(lin,col,num_opc,larg_w,1)
            LET CascWinStat[1]="O"
         END IF
      WHEN nivel_cascata = 2
         IF CascWinStat[2]="O" THEN
            call curr_win(2)
         ELSE
            LET CascWinStat[2]="O"
            call open_win(lin,col,num_opc,larg_w,2)
         END IF
      WHEN nivel_cascata = 3
         IF CascWinStat[3]="O" THEN
            call curr_win(3)
         ELSE
            LET CascWinStat[3]="O"
            call open_win(lin,col,num_opc,larg_w,3)
         END IF
      WHEN nivel_cascata = 4
         IF CascWinStat[4]="O" THEN
            call curr_win(4)
         ELSE
            LET CascWinStat[4]="O"
            call open_win(lin,col,num_opc,larg_w,4)
         END IF
      WHEN nivel_cascata = 5
         IF CascWinStat[5]="O" THEN
            call curr_win(5)
         ELSE
            LET CascWinStat[5]="O"
            call open_win(lin,col,num_opc,larg_w,5)
         END IF
      WHEN nivel_cascata = 6
         IF CascWinStat[6]="O" THEN
            call curr_win(6)
         ELSE
            LET CascWinStat[6]="O"
            call open_win(lin,col,num_opc,larg_w,6)
         END IF
      WHEN nivel_cascata = 7
         IF CascWinStat[7]="O" THEN
            call curr_win(7)
         ELSE
            LET CascWinStat[7]="O"
            call open_win(lin,col,num_opc,larg_w,7)
         END IF
      WHEN nivel_cascata = 8
         IF CascWinStat[8]="O" THEN
            call curr_win(8)
         ELSE
            LET CascWinStat[8]="O"
            call open_win(lin,col,num_opc,larg_w,8)
         END IF
      WHEN nivel_cascata = 9
         IF CascWinStat[9]="O" THEN
            call curr_win(9)
         ELSE
            LET CascWinStat[9]="O"
            call open_win(lin,col,num_opc,larg_w,9)
         END IF

      OTHERWISE
         OPEN WINDOW WmenuVert AT lin,col WITH num_opc ROWS, larg_w COLUMNS 
            ATTRIBUTE (BORDER)
   END CASE


   if com_titulo then
	   LET colTitulo=(larg_w-dimTitulo)/2+1
	   DISPLAY titulo AT 1,colTitulo
      CALL fgl_drawbox(1,larg_w,2,1)
	   DISPLAY " " AT 2,1
	   DISPLAY " " AT 2,larg_w
   end if

END FUNCTION

################################################################################

FUNCTION maxLengthCas(titulo)
{}
  define	
	  titulo   char(80),
	  i,my_len smallint

  LET my_len=length(titulo)
  FOR i=1 TO 19 
	 LET lenAux=length(pa_opcoes[i].descr)
	 IF lenAux=0        THEN EXIT FOR            END IF
	 IF lenAux > my_len THEN LET my_len = lenAux END IF
  END FOR
  IF my_len>70         THEN RETURN 0            END IF
  RETURN my_len

END FUNCTION

################################################################################

FUNCTION dispArCas(dacLinha,ehReverse)
{}
  DEFINE dacLinha smallint,
				 ehReverse INTEGER
  DEFINE col INTEGER

  IF com_titulo THEN
	 LET col = dacLinha+2
  ELSE
	 LET col = dacLinha
  END IF

  IF ehReverse THEN
      DISPLAY pa_opcoes[dacLinha].descr AT col,2 ATTRIBUTE(REVERSE)
      DISPLAY " " AT col,1 ATTRIBUTE(REVERSE)
  ELSE
      DISPLAY pa_opcoes[dacLinha].descr AT col,2
      DISPLAY " " AT col,1 
  END IF
END FUNCTION


#  ============================================================================ 
#  
#  ============================================================================ 
FUNCTION edArayCas(numRegs,numOpcao)
{}
  DEFINE numRegs,numOpcao INTEGER,
  oldPos,pos INTEGER,
         i,tecla INTEGER,
			lastKeyWasDigit INTEGER
  define nni smallint

  IF  displayOpcoes THEN
		let nni = 1
		while 1=1
      CALL dispArCas(nni,FALSE)
			let nni = nni + 1
			if nni > numRegs then
				exit while
			end if
    END while
  END If
  CALL dispArCas(numOpcao,TRUE)
  LET  oldPos = numOpcao
  LET  pos = numOpcao
  LET  lastKeyWasDigit = FALSE

  WHILE TRUE
    IF oldPos!=pos THEN
      CALL dispArCas(oldPos,FALSE)
      CALL dispArCas(pos,TRUE)
      LET  oldPos = pos
    END IF
	 LET tecla = getkey()

	 # Isto deveria de estar numa funcao de handle das teclas
    CASE
      WHEN tecla = 23  # KEY CONTROL+W =>  HELP 
        call socorroCas()
      WHEN tecla = 48  # KEY 0 
		  IF numRegs>=10 THEN
          IF lastKeyWasDigit THEN
			   LET pos=10
            LET lastKeyWasDigit=FALSE
		    END IF
		  END IF
      WHEN tecla = 49  # KEY 1 
		  IF numRegs>=11 THEN
          IF lastKeyWasDigit THEN
			   LET pos=11
            LET lastKeyWasDigit=FALSE
          ELSE
		      LET pos=1
            LET lastKeyWasDigit=TRUE
		    END IF
		  ELSE	 
		    LET pos=1
		  END IF
      WHEN tecla = 50  # KEY 2 
		  IF numRegs>=12 AND lastKeyWasDigit THEN
			 LET pos=12
          LET lastKeyWasDigit=FALSE
        ELSE
			 LET pos=2
		  END IF
      WHEN tecla = 51  # KEY 3 
		  IF numRegs>=3 THEN
          IF lastKeyWasDigit AND numRegs>=13 THEN
			   LET pos=13
            LET lastKeyWasDigit=FALSE
          ELSE
		      LET pos=3
		    END IF
		  END IF
      WHEN tecla = 52  # KEY 4 
		  IF numRegs>=4 THEN
          IF lastKeyWasDigit AND numRegs>=14 THEN
			   LET pos=14
            LET lastKeyWasDigit=FALSE
          ELSE
		      LET pos=4
		    END IF
		  END IF
      WHEN tecla = 53  # KEY 5 
		  IF numRegs>=5 THEN
          IF lastKeyWasDigit AND numRegs>=15 THEN
			   LET pos=15
            LET lastKeyWasDigit=FALSE
          ELSE
		      LET pos=5
		    END IF
		  END IF
      WHEN tecla = 54  # KEY 6 
		  IF numRegs>=6 THEN
          IF lastKeyWasDigit AND numRegs>=16 THEN
			   LET pos=16
            LET lastKeyWasDigit=FALSE
          ELSE
		      LET pos=6
		    END IF
		  END IF
      WHEN tecla = 55  # KEY 7 
		  IF numRegs>=7 THEN
          IF lastKeyWasDigit AND numRegs>=17 THEN
			   LET pos=17
            LET lastKeyWasDigit=FALSE
          ELSE
		      LET pos=7
		    END IF
		  END IF
      WHEN tecla = 56  # KEY 8 
		  IF numRegs>=8 THEN
          IF lastKeyWasDigit AND numRegs>=18 THEN
			   LET pos=18
            LET lastKeyWasDigit=FALSE
          ELSE
		      LET pos=8
		    END IF
		  END IF
      WHEN tecla = 57  # KEY 9 
		  IF numRegs>=9 THEN
          IF lastKeyWasDigit AND numRegs>=19 THEN
			   LET pos=19
            LET lastKeyWasDigit=FALSE
          ELSE
		      LET pos=9
		    END IF
		  END IF
      WHEN tecla = 2000  # KEY UP
        IF pos>1 THEN
          LET pos=pos-1
        ELSE
          LET pos=numRegs
        END IF
      WHEN tecla = 2001  # KEY DOWN
        IF pos<numRegs THEN
          LET pos=pos+1
        ELSE
          LET pos=1
        END IF
      WHEN tecla = 32
        IF pos<numRegs THEN
          LET pos=pos+1
        ELSE
          LET pos=1
        END IF
      WHEN tecla = 13  # KEY "FAZER"
        RETURN pos
      WHEN tecla = 27  # ESCAPE
        RETURN 0
      OTHERWISE
        IF int_flag THEN
          RETURN 0
        END IF
		  LET pos=testLetraCas(pos,tecla,numRegs)
		  IF pos!=0 THEN
          IF oldPos!=pos THEN
            CALL dispArCas(oldPos,FALSE)
            CALL dispArCas(pos,TRUE)
            LET oldPos=pos
          END IF
			 RETURN pos
        ELSE
            LET pos=oldPos
		  END IF
    END CASE
  END WHILE

END FUNCTION
 

#  ============================================================================ 
#  Faz o handle das teclas premidas pelo utilizador
#  ============================================================================ 
FUNCTION testLetraCas(pos,tecla,numRegs)
{}
   DEFINE 
      pos,tecla,
		numRegs    INTEGER, 
		i           smallint,
		letra       char(1),
		asctecla    char(1)

	let asctecla = ASCII tecla
   IF (tecla>96 AND tecla<123) OR (tecla>64 AND tecla<91) THEN
		LET tecla=(tecla<91)*32+tecla
      FOR i=pos TO numRegs
	      let letra = downshift(pa_opcoes[i].selLetra)
			IF letra = asctecla THEN
				RETURN i
			END IF
		END FOR
      IF pos>1 THEN
			FOR i=1 TO pos-1 
	         let letra = downshift(pa_opcoes[i].selLetra)
			   IF letra=asctecla THEN
				    RETURN i
				END IF
			END FOR
      END IF
   END IF
   RETURN 0

END FUNCTION

#  ============================================================================ 
#  Fecha a janela correspondente ao menu
#  ============================================================================ 
FUNCTION closeWindMenu(nivel_cascata)
{}
  DEFINE nivel_cascata SMALLINT

  call close_win(nivel_cascata)
  LET CascWinStat[nivel_cascata]=""
END FUNCTION

#  ============================================================================ 
#  Instrucoes de utilizacao
#  ============================================================================ 
function socorroCas()
{}
  define ans integer

  open window w_socorroCas at 10,23 with 9 rows,34 columns attribute(border)
  display "GUIA DE UTILIZACAO" AT 1,9 attribute (reverse)
  display "<setas,espaco> - mover" AT 3,2
  display "<alfanumerico> - acesso directo" AT 4,2
  display "<ENTER,RETURN> - escolhe opcao" AT 5,2
  display "  <CTRL-C,ESC> - abortar escolha" AT 6,2

  call fgl_drawbox(3,4,7,16)
  display "OK" at 8, 17 attribute(reverse)
  while 1=1
    LET ans=getkey()
	 case
		when ans = 32   # Espaco
		  exit while
		when ans = 13   # Return
		  exit while
	 end case
  end while
  display "OK" at 8, 17 attribute(invisible)
  sleep(1)
  close window w_socorroCas
end function
