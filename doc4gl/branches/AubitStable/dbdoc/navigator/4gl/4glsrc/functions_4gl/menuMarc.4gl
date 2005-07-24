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
#  Data de criacao: Thu Nov 09 14:26:20 LISBOA 1995
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : Funcoes genericas da Despodata
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
#
#  ============================================================================ 

DEFINE
	arr      ARRAY[19] OF RECORD
	   descr CHAR(80)
	END RECORD,
	arrMarca       CHAR(19),
	selLetra       CHAR(19), 
   pos            SMALLINT,
   com_titulo,
	marca_todos    INTEGER,
	len,lenAux     SMALLINT


#  ============================================================================ 
#           FUNCAO QUE CONSTROI MENU VERTICAL E MARCA OPCOES             #
#                                                                        #
#  - Parametros de entrada:                                              #
#                - linha,coluna (para posicionar o menu)                 #    
#                - numero de opcoes                                      #
#                - titulo(opcional)                                      #
#                - opcoes marcadas por omissao(opcional)                 #
#                - diversas strings consoante o numero de opcoes         # 
#  - Retorna 2 campos                                                    #
#        - FALSE se <(CTRL-C)>  ou   TRUE se <(ESC)>                        #
#        - string(19) com * nos campos seleccionados 
#  ============================================================================ 

FUNCTION menuMarc(lin,col,opcoes,titulo,opcMarcadas,str0,str1,str2,str3,str4,str5,str6,
			  str7,str8,str9,str10,str11,str12,str13,str14,str15,str16,str17,str18)

DEFINE
	lin,col,opcoes SMALLINT,
	titulo         char(80),
	opcMarcadas    char(19),
   str0,str1,str2,str3,str4,str5,str6,str7,str8,str9 CHAR(50),
   str10,str11,str12,str13,str14,str15,str16,str17,str18 CHAR(50)

DEFINE
	comp_descr,i SMALLINT

   call inicTuti(opcoes,opcMarcadas)	
   IF opcoes>19 OR opcoes<2 THEN
	  error "Opcoes: 2->19"
	  RETURN 0
	END IF
	LET arrMarca=opcMarcadas
	FOR i=1 TO 19 
	  LET arr[i].descr=""
	END FOR

   IF col < 2 THEN LET col = 2 END IF
   IF lin < 2 THEN LET lin = 2 END IF

   FOR i=1 TO opcoes
	  CASE 
		 WHEN (i) = 1
			LET selLetra[i]=str0[1]
	      LET arr[i].descr=str0
		 WHEN (i) = 2
			LET selLetra[i]=str1[1]
	      LET arr[i].descr=str1
		 WHEN (i) = 3
			LET selLetra[i]=str2[1]
	      LET arr[i].descr=str2
		 WHEN (i) = 4
			LET selLetra[i]=str3[1]
	      LET arr[i].descr=str3
		 WHEN (i) = 5
			LET selLetra[i]=str4[1]
	      LET arr[i].descr=str4
		 WHEN (i) = 6
			LET selLetra[i]=str5[1]
	      LET arr[i].descr=str5
		 WHEN (i) = 7
			LET selLetra[i]=str6[1]
	      LET arr[i].descr=str6
		 WHEN (i) = 8
			LET selLetra[i]=str7[1]
	      LET arr[i].descr=str7
		 WHEN (i) = 9
			LET selLetra[i]=str8[1]
	      LET arr[i].descr=str8
		 WHEN (i) = 10
			LET selLetra[i]=str9[1]
	      LET arr[i].descr=str9
		 WHEN (i) = 11
			LET selLetra[i]=str10[1]
	      LET arr[i].descr=str10
		 WHEN (i) = 12
			LET selLetra[i]=str11[1]
	      LET arr[i].descr=str11
		 WHEN (i) = 13
			LET selLetra[i]=str12[1]
	      LET arr[i].descr=str12
		 WHEN (i) = 14
			LET selLetra[i]=str13[1]
	      LET arr[i].descr=str13
		 WHEN (i) = 15
			LET selLetra[i]=str14[1]
	      LET arr[i].descr=str14
		 WHEN (i) = 16
			LET selLetra[i]=str15[1]
	      LET arr[i].descr=str15
		 WHEN (i) = 17
			LET selLetra[i]=str16[1]
	      LET arr[i].descr=str16
		 WHEN (i) = 18
			LET selLetra[i]=str17[1]
	      LET arr[i].descr=str17
		 WHEN (i) = 19
			LET selLetra[i]=str18[1]
	      LET arr[i].descr=str18
     END CASE
	END FOR

   LET comp_descr=maxLengthMar(titulo)
	IF comp_descr=0 THEN
	  error "Valores validos de dimensao de strings: 1-70"
	END IF

   # Abertura da janela com a form da LOV
   CALL AbreWindMar(opcoes,comp_descr,lin,col,titulo)

  LET int_flag=FALSE
  CALL edArayMar(opcoes) RETURNING pos
  IF int_flag THEN
	LET int_flag = FALSE
	error "ESCOLHA ABORTADA"
  END IF

  CLOSE WINDOW w_menuVert
  RETURN pos,arrMarca clipped
END FUNCTION

################################################################################

FUNCTION AbreWindMar(opcoes,comp_descr,lin,col,titulo)
DEFINE opcoes,comp_descr,
		 lin,col SMALLINT,
		 titulo char(80)
DEFINE colTitulo,dimTitulo INTEGER,
   mlinhas, mcolunas integer

  LET comp_descr=comp_descr+2

  LET com_titulo=FALSE
  IF titulo IS NOT NULL THEN
	 LET dimTitulo=length(titulo)
	 LET com_titulo=TRUE
	 LET opcoes=opcoes+2    # reserva linhas para escrever titulo
  END IF

  IF lin>23-opcoes THEN 
	 LET lin=23-opcoes
  END IF

  if (col+comp_descr)>78 then
	  let col=79-comp_descr
  end if

  let mlinhas = opcoes
  let mcolunas = comp_descr
  OPEN WINDOW w_menuVert AT lin,col
		WITH mlinhas ROWS, mcolunas COLUMNS
		ATTRIBUTE (BORDER)

  if com_titulo then
	 LET colTitulo=(comp_descr-dimTitulo)/2+1
	 DISPLAY titulo AT 1,colTitulo
    CALL fgl_drawbox(1,comp_descr,2,1)
	 DISPLAY " " AT 2,1
	 DISPLAY " " AT 2,comp_descr
  end if

END FUNCTION

################################################################################

FUNCTION dispArMar(n,ehReverse)
  DEFINE n INTEGER,ehReverse INTEGER
  DEFINE col INTEGER,
			str1 char(1)

  IF com_titulo THEN
	 LET col=n+2
  ELSE
	 LET col=n
  END IF
  LET str1=arrMarca[n]

  IF ehReverse THEN
      DISPLAY arr[n].descr AT col,2 ATTRIBUTE(REVERSE)
      DISPLAY str1 AT col,1 ATTRIBUTE(REVERSE)
  ELSE
      DISPLAY arr[n].descr AT col,2
      DISPLAY str1 AT col,1 
  END IF

END FUNCTION

################################################################################

FUNCTION edArayMar(numRegs)
  DEFINE numRegs INTEGER
  DEFINE oldPos,pos INTEGER,
         i,tecla INTEGER,
			lastKeyWasDigit INTEGER

  FOR i=1 TO numRegs
     CALL dispArMar(i,FALSE)
  END FOR
  LET oldPos=1
  LET pos=1
  LET lastKeyWasDigit=FALSE

  WHILE TRUE
    IF oldPos!=pos THEN
      CALL dispArMar(oldPos,FALSE)
      LET oldPos=pos
    END IF
    CALL dispArMar(pos,TRUE)
	 LET tecla=getKey()
    CASE
      WHEN tecla = 23  # KEY CONTROL+W =>  HELP 
        call socorroMar()
      WHEN tecla = 47  # KEY (/) MARCA/DESMARCA TUDO
        CALL marcaTudo(numRegs)
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
      WHEN tecla = 13  # KEY "MARCAR/DESMARCAR"
        CALL marca2(pos) 
      WHEN tecla = 27  # ESCAPE
        RETURN TRUE
      OTHERWISE
        IF int_flag THEN
          RETURN FALSE
        END IF
		  LET i=testLetraMar(pos,tecla,numRegs)
		  IF i!=0 THEN
		    IF numRegs>=i THEN
		      LET pos=i
		    END IF
		  END IF
    END CASE
  END WHILE

END FUNCTION
 
################################################################################

FUNCTION marca2(pos) 
  DEFINE pos SMALLINT

  IF arrMarca[pos]="*" THEN
    LET arrMarca[pos]=" "
  ELSE
    LET arrMarca[pos]="*"
  END IF

END FUNCTION

################################################################################
 
FUNCTION maxLengthMar(titulo)
  define	titulo char(80), 
	  i smallint

  LET len=length(titulo)
  FOR i=1 TO 19 
	 LET lenAux=length(arr[i].descr)
	 IF lenAux=0 THEN
		EXIT FOR
	 END IF
	 IF lenAux > len THEN
		LET len = lenAux
	 END IF
  END FOR
  IF len>70 THEN
	 RETURN 0
  END IF
  RETURN len

END FUNCTION

################################################################################

FUNCTION testLetraMar(pos,tecla,numRegs)
{}

  DEFINE pos,tecla,numRegs INTEGER,
	  i smallint

		  IF (tecla>96 AND tecla<123) OR (tecla>64 AND tecla<91) THEN
		    LET tecla=(tecla<91)*32+tecla
			 FOR i=pos TO numRegs
			   IF DOWNSHIFT(selLetra[i])=ASCII tecla THEN
				  RETURN i
				END IF
			 END FOR
          IF pos>1 THEN
			   FOR i=1 TO pos-1 
			     IF DOWNSHIFT(selLetra[i])=ASCII tecla THEN
				    RETURN i
				  END IF
			   END FOR
			 END IF
		  END IF
		  RETURN 0

END FUNCTION

################################################################################

FUNCTION marcaTudo(numRegs) 
{}
  define numRegs INTEGER
  DEFINE col INTEGER,
			str1 char(1),
			i smallint

  for i=1 to numRegs
    IF marca_todos THEN
      let arrMarca[i]="*"
    ELSE
      let arrMarca[i]=" "
	 END IF
    IF com_titulo THEN
	   LET col=i+2
    ELSE
	   LET col=i
    END IF
    let str1=arrMarca[i]
    DISPLAY str1 AT col,1
  end for
  IF marca_todos THEN
    let marca_todos=false
  ELSE
    let marca_todos=true
  END IF
END FUNCTION

function inicTuti(opcoes,opcMarcadas)	
{}
  define opcoes SMALLINT,
	      opcMarcadas char(19),
			i smallint

   let marca_todos=FALSE
   for i=1 to opcoes
	  if opcMarcadas[i]!="*" then
       let marca_todos=TRUE
		 return
	  end if
	end for

end function

function socorroMar()
{}
  define ans integer

  open window w_socorroMar at 9,19 with 11 rows,41 columns attribute(border)
  display "GUIA DE UTILIZACAO" AT 1,12 attribute (reverse)
  display " <setas,espaco> - mover" AT 3,1 
  display " <alfanumerico> - acesso directo" AT 4,1 
  display " <ENTER,RETURN> - marcar/desmarcar opcao" AT 5,1 
  display "     <\"/\">      - marcar/desmarcar tudo" AT 6,1 
  display "     <CTRL-C>   - abortar marcacao" AT 7,1 
  display "     <ESC>      - sair com marcacao" AT 8,1 

  call fgl_drawbox(3,4,9,19)
  display "OK" at 10, 20 attribute(reverse)
  while 1=1
    LET ans=getKey()
	 case
		when ans = 32   # Espaco
		  exit while
		when ans = 13   # Return
		  exit while
	 end case
  end while
  display "OK" at 10, 20 attribute(invisible)
  sleep(1)
  close window w_socorroMar
end function
