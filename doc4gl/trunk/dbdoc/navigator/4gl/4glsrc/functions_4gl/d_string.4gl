

###############################################################################
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#
#  Divisao de desenvolvimento e producao de software.
#
#  Autor:   Sergio Ferreira
#           Joao Costa
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
#  FUNCOES: d_isnum (str)
#           d_ischar (str)
#           d_fmt_dec (valor,comp)
#           d_center_str (str,comp)
#           d_sstrip (str)
#           d_strstr (num_cars,car)
#
#  ----------------------------------------------------------------
#  FORMS:
#
#  REPORTS:
#
#  NOTAS:
#
###############################################################################


# Ficheiro de variaveis globais da Livraria @p
GLOBALS "4glsrc/functions_4gl/d_libglob.4gl"


#  ===================================================================
#  Funcao para testar se uma string apenas contem numeros.
#  -------------------------------------------------------------------
#  entradas:
#    str -> string a verificar.
#  -------------------------------------------------------------------
#  saidas:
#    TRUE  -> Se a string (str) apenas contiver numeros.
#    FALSE -> Se a string (str) contiver caracteres nao numericos.
#  ===================================================================
FUNCTION d_isnum(str)
{}
DEFINE str CHAR(30)

DEFINE i INTEGER

  FOR i=1 TO LENGTH(str)
    IF UPSHIFT (str[i]) >= "A" AND UPSHIFT (str[i]) <= "Z" THEN
      RETURN FALSE
    END IF
  END FOR

  RETURN TRUE

END FUNCTION


#  ===================================================================
#  Funcao para testar se uma string apenas contem letras.
#  -------------------------------------------------------------------
#  entradas:
#    str -> string com a informacao a ser testada.
#  -------------------------------------------------------------------
#  saidas:
#    TRUE  -> Se a string (str) apenas contiver letras.
#    FALSE -> Se a string (str) contiver caracteres numericos.
#  ===================================================================
FUNCTION d_ischar (str)
{}
DEFINE str CHAR(30)

DEFINE i INTEGER

  FOR i=1 TO LENGTH(str)
    IF str[i] >= "0" AND str[i] <= "9" THEN
      RETURN FALSE
    END IF
  END FOR

  RETURN TRUE 

END FUNCTION


#  =============================================================
#  Funcao para formatar um decimal consoante a parametrizacao
#  escolhida para o utilizador.
#  -------------------------------------------------------------
#  entradas:
#    valor             -> valor para ser formatado.
#                         Caso esta variavel entre com o valor
#                         NULL sera' devolvida a seguinte string:
#                         '            -- --'.
#    comp              -> comprimento da string formatada.
#    formato           -> formato pretendido
#  -------------------------------------------------------------
#  saidas:
#    val_str -> string com o valor formatado.
#  -------------------------------------------------------------
#  observacoes:
#    Os tipos de escolha do CASE encontram-se definidos na ficha
#    do utilizador.
#  =============================================================
FUNCTION d_fmt_dec (valor,comp,formato)
{}
DEFINE valor DECIMAL (17,2),
       comp  SMALLINT,
		 formato SMALLINT

DEFINE val_str CHAR (21)

  IF valor IS NULL THEN
    LET val_str =  "                -- --"
  ELSE
    CASE
      WHEN formato = 1
        LET val_str = valor USING "-----------------&.##"
      WHEN formato = 2
        LET val_str = valor USING "--,---,---,---,--&.##"
      WHEN formato = 3
        LET val_str = valor USING "-- --- --- --- --&.##"
      WHEN formato = 4
        LET val_str = valor USING "&&,&&&,&&&,&&&,&&&.##"
      WHEN formato = 5
        LET val_str = valor USING "&& &&& &&& &&& &&&.##"
      WHEN 6
        LET val_str = valor USING "-- --- --- --- --&.##"
        LET val_str [19] = "$"
      WHEN formato = 7
        LET val_str = valor USING "--,---,---,---,--&.##"
        LET val_str [19] = "$"
      OTHERWISE
        LET val_str = "*FORMATO INDEFINIDO**"
    END CASE
  END IF

  IF comp < 21 THEN
    LET val_str = val_str [22-comp,21]
  END IF

  RETURN val_str clipped

END FUNCTION


#  =================================================================
#  Funcao para devolver uma string com o texto centrado.
#  -----------------------------------------------------------------
#  entradas:
#    str  -> string com o texto a ser centrado.
#    comp -> comprimento de referencia para a centragem.
#  -----------------------------------------------------------------
#  saidas:
#    str -> string com o texto centrado no comprimento comp.
#  =================================================================
FUNCTION d_center_str (str,comp)
{}
DEFINE str  CHAR (160),
       comp SMALLINT

DEFINE str1   CHAR (160),
       pos,
       compstr,
       offset SMALLINT

  if str is null then
	  return str clipped
  end if
  LET str1 = str
  LET compstr = LENGTH (str)
  LET offset = (comp - compstr) / 2
  FOR pos = 1 TO offset
    LET str [pos] = " "
  END FOR
  FOR pos = 1 TO compstr
    LET str [offset+pos] = str1 [pos]
  END FOR

  RETURN str clipped
 
END FUNCTION


#  =================================================================
#  Funcao para devolver uma string sem espacos no inicio
#  -----------------------------------------------------------------
#  entradas:
#    str -> string com o texto.
#  -----------------------------------------------------------------
#  saidas:
#    str -> string com o texto sem espacos no inicio.
#  =================================================================
FUNCTION d_sstrip (sst_str)
{}
DEFINE sst_str CHAR (160)

DEFINE sst_str1    CHAR (200),
       posicao,
       compstr SMALLINT

  IF sst_str IS NULL THEN 
	  RETURN sst_str clipped
  END IF

  LET sst_str1 = sst_str
  LET compstr = LENGTH (sst_str)
  FOR posicao = 1 TO compstr
    IF sst_str1 [posicao] <> " " THEN
      EXIT FOR
    END IF
  END FOR

  IF posicao < compstr THEN
     LET sst_str = sst_str1 [posicao,compstr]
  END IF
     
  RETURN sst_str CLIPPED
   

END FUNCTION


#  ===========================================================
#  Funcao para retornar n vezes uma string.
#  -----------------------------------------------------------
#  entradas:
#    num_vezes -> numero de vezes que a string sera' repetida.
#    padrao    -> string a repetir.
#  -----------------------------------------------------------
#  saidas:
#    str_car -> string com a string padrao repetida num_vezes vezes.
#  ===========================================================
FUNCTION d_strstr (num_vezes,padrao)
{}
DEFINE num_vezes SMALLINT,
       padrao    CHAR (30)

DEFINE str_car CHAR (300),
       comp,
       pos     SMALLINT

  LET comp = LENGTH (padrao)
  IF (num_vezes * comp) > 300 THEN
    LET num_vezes = 300 / comp
  END IF

  LET str_car = NULL
  FOR pos = 1 TO num_vezes
    LET str_car = str_car CLIPPED,padrao CLIPPED
  END FOR

  RETURN str_car clipped

END FUNCTION





###############################################################################
# Funcao para testar se todos os caracteres de uma string sao em maiusculas   #
#.............................................................................#
# ENTRADAS : u_str                                                            #
#              string a ser testada                                           #
#.............................................................................#
# SAIDAS : Devolve TRUE se todos os caracteres forem em maiusculas            #
#          Devolve FALSE se houver um que nao seja em maiusculas              #
###############################################################################
FUNCTION d_isupper(u_str)
{}


DEFINE u_str CHAR(500),
       u_str1 CHAR(500) 

   LET u_str1 = upshift(u_str)


   IF u_str IS NOT NULL THEN
      IF u_str = u_str1 THEN
         RETURN(1)  
      ELSE 
         RETURN(0) 
      END IF
   ELSE 
      RETURN(0)
   END IF

END FUNCTION  
###############################################################################
# Funcao para testar se uma string so contem caracteres em minusculas         #
#.............................................................................#
# ENTRADAS : str                                                              #
#             string a ser testada                                            #
#.............................................................................#
# SAIDAS : Devolve TRUE se todos os caracteres estiverem em minusculas        #
#          Devolve FALSE se houver um caracter que nao esteja em minusculas   #
###############################################################################
FUNCTION d_islower(str)
{}

DEFINE str CHAR(500),
       str1 CHAR(500)

   IF str IS NOT NULL THEN
      LET str1 = downshift(str)
      IF str = str1 THEN 
         RETURN(1)
      ELSE
         RETURN(0)
      END IF 
   ELSE
      RETURN(0)
   END IF

END FUNCTION



###############################################################################
# Funcao para testar se todos os caracteres de uma string sao digitos         #
#.............................................................................#
# ENTRADAS : str                                                              #
#              string a ser testada                                           #
#.............................................................................#
# SAIDAS : Devolve TRUE se todos os caracteres da string forem digitos        #
#          Devolve FALSE se um dos caracteres nao for digito                  #
###############################################################################
FUNCTION d_isdigit(str)
{}

DEFINE str CHAR(500),
       len INTEGER,
       i INTEGER

   IF str IS NOT NULL THEN
      LET len = length(str)
      FOR i = 1 TO len  
          IF str[i] >="0" AND str[i] <="9" THEN
             LET i=i
          ELSE
             EXIT FOR 
          END IF   
      END FOR
      IF i = len+1 THEN
         RETURN(TRUE)
      ELSE 
         RETURN(FALSE)
      END IF
   ELSE
      RETURN(FALSE)
   END IF

END FUNCTION  




################################################################################
# Funcao para testar se todos os caracteres de uma string sao hexadecimais     #
#..............................................................................#
# ENTRADAS : str                                                               #
#             string a ser testada                                             ##..............................................................................## SAIDAS : Devolve TRUE se todos os caracteres da string forem hexadecimais    ##          Devolve FALSE se houver um caracter que nao seja hexadecimal        #################################################################################
FUNCTION d_isxdigit(str)
{}
DEFINE str CHAR(500),
       len INTEGER,
       i INTEGER
 
   IF str IS NOT NULL THEN
      LET len = length(str)
      FOR i = 1 TO len
          IF str[i] >="0"
			   AND str[i] <="9"
			   OR str[i] >="A"
			   AND str[i] <="F"
			   OR str[i] >="a"
			   AND str[i]<="z" THEN
                LET i=i 
          ELSE
             EXIT FOR
          END IF
       END FOR
       IF i = len+1 THEN
          RETURN(TRUE)
       ELSE
          RETURN(FALSE)
       END IF
    ELSE
       RETURN(FALSE)
    END IF

END FUNCTION  


###############################################################################
# Funcao para testar se todos os caracteres de uma string sao alfanumericos   #
#.............................................................................#
# ENTRADAS : str                                                              #
#             string a ser testada                                            #
#.............................................................................#
# SAIDAS : Devolve TRUE se todos os caracteres forem alfanumericos            #
#          Devolve FALSE se houver um caracter que nao seja alfanumerico      #
###############################################################################
FUNCTION d_isalnum(str)
{}

DEFINE str CHAR(500),
       len INTEGER,
       i INTEGER

   IF str IS NULL THEN
		return(false)
	end if

   LET len = length(str)
   FOR i = 1 TO len
      IF ( str[i] >="0" AND str[i]<="9") OR
		   ( str[i] >="A" AND str[i]<="Z") OR
			( str[i]>="a" AND str[i]<="z" )
		THEN
         LET i=i
      ELSE 
         EXIT FOR
      END IF
   END FOR
   IF i = len+1 THEN
      RETURN(TRUE)
   ELSE
      RETURN(FALSE)
   END IF

END FUNCTION  
 
#  
#  Verifica se todos os caracteres da string enviada como parametro sao:
#   Alfanumericos
#   Espacos
#
FUNCTION d_isalnumspace(str)
{}
   DEFINE 
		str CHAR(500),
      len INTEGER,
      i   INTEGER

   IF str IS NULL THEN
		return(false)
	end if

   LET len = length(str)
   FOR i = 1 TO len
      IF ( str[i] >="0" AND str[i]<="9") OR
		   ( str[i] >="A" AND str[i]<="Z") OR
			( str[i]>="a" AND str[i]<="z" ) OR
			str[i] = " "
		THEN
      ELSE   # Descobriu outra coisa qualquer
			return false
      END IF
   END FOR
   RETURN(TRUE)
END FUNCTION  



###############################################################################
# Funcao para procurar um caracter numa string                                #
#.............................................................................#
# ENTRADAS : str                                                              #
#             string a ser testada                                            #
#            chr                                                              #
#             caracter a procurar                                             #
#.............................................................................#
# SAIDAS : Devolve FALSE se nao encontrar o caracter na string                #
#          Devolve a posicao da primeira ocorrencia do caracter na string     #
###############################################################################
FUNCTION d_strchr(str,chr)
{}

DEFINE chr CHAR(1),
       str CHAR(500),
       i INTEGER, 
       len INTEGER

   IF str IS NOT NULL THEN
      LET len = length(str)
      FOR i=1 TO len
          IF str[i] = chr THEN
             EXIT FOR
          END IF
      END FOR
      IF i = len+1 THEN
         RETURN(FALSE)
      ELSE
         RETURN i
      END IF
   ELSE 
      RETURN(FALSE)
   END IF

END FUNCTION 


###############################################################################
# Funcao para testar se todos os caracteres sao espacos                       #
#.............................................................................#
# ENTRADAS : str                                                              #
#             string a ser testada                                            #
#.............................................................................#
# SAIDAS : Devolve TRUE se todos os caracteres forem espacos                  #
#          Devolve FALSE se houver um caracter que nao seja espaco            #
###############################################################################
FUNCTION d_isspace(str)
{}

DEFINE str CHAR(500),
        len INTEGER,
        i INTEGER

   IF str IS NOT NULL THEN
      LET len = length(str)
      FOR i = 1 TO len
          IF str[i] = " " THEN
             LET i=i
          ELSE
             EXIT FOR
          END IF
      END FOR
      IF i = len+1 THEN
         RETURN(TRUE)
      ELSE
         RETURN(FALSE)
      END IF
   ELSE
      RETURN(FALSE)
   END IF

END FUNCTION
 


################################################################################
# Funcao para testar tecla de control                                          #
# .............................................................................#
# ENTRADAS : ctrl                                                              #
#              tecla de control a ser testada                                  #
#..............................................................................#
# SAIDAS : Devolve 0 se nao for tecla de control                               #
#          Devolve a letra correspondente se for tecla de control              #
################################################################################
 FUNCTION d_iscntrl(ctrl)
 {} 
 DEFINE ctrl SMALLINT,
        ret SMALLINT

   IF ctrl IS NOT NULL OR ctrl <32 THEN 
      LET ret = ctrl+64
      RETURN ret
   ELSE 
      RETURN(0)
   END IF

END FUNCTION  




###############################################################################
# Funcao para testar se todos os caracteres de uma string sao de pontuacao    #
#.............................................................................#
# ENTRADAS : str                                                              #
#             string a ser testada                                            #
#.............................................................................#
# SAIDAS : Devolve TRUE se todos os caracteres forem de pontuacao             #
#          Devolve FALSE se houver um caracter que nao seja de pontuacao      #
###############################################################################
FUNCTION d_ispunct(str)
{}
DEFINE str CHAR(500),
       ret SMALLINT,
       len INTEGER,
       i INTEGER

   IF str IS NOT NULL THEN
      LET len = length(str)
      FOR i = 1 TO len
          IF str[i] >="a"
			   AND str[i] <="z"
			   OR str[i] >="A"
			   AND str[i] <="Z"
			   OR str[i] >="0"
			   AND str[i]<="9"
			   OR str[i] = " " THEN
               EXIT FOR
          END IF
      END FOR
      IF i = len+1 THEN
         RETURN(TRUE)
      ELSE
         RETURN(FALSE)
      END IF
   END IF

END FUNCTION   



################################################################################
# Funcao para testar se todos os caracteres de uma string sao printaveis       #
#..............................................................................#
# ENTRADAS : str                                                               #
#              string a ser testada                                            #
#..............................................................................## SAIDAS : Devolve TRUE se todos os caracteres forem caracteres printaveis     #
#          Devolve FALSE se houver um caracter que nao seja printavel          #
################################################################################
FUNCTION d_isprint(str)
{}

DEFINE str CHAR(500),
         len INTEGER,
         i INTEGER

   IF str IS NOT NULL THEN
      LET len = length(str)
      FOR i = 1 TO len
          IF str[i] >= " " AND str[i] <= "~" THEN
             LET i=i
          ELSE
             EXIT FOR
          END IF
      END FOR
      IF i = len+1 THEN
         RETURN(TRUE)
      ELSE
         RETURN(FALSE)
      END IF
   ELSE
      RETURN(FALSE)
   END IF

END FUNCTION      



################################################################################
# Funcao para testar se todos os caracteres de uma string sao caracteres       #
#        graficos                                                              #
#..............................................................................#
# ENTRADAS : str                                                               #
#             string a ser testada                                             #
#..............................................................................#
# SAIDAS : Devolve TRUE se todos os caracteres forem graficos                  #
#          Devolve FALSE se houver um caracter que nao seja grafico            #
################################################################################
FUNCTION d_isgraph(str)
{}
DEFINE str CHAR(500),
       len INTEGER,
       i INTEGER  

   IF str IS NOT NULL THEN
      LET len = length(str)
      FOR i = 1 TO len
          IF str[i] >= "!" AND str[i] <= "~" THEN
             LET i=i
          ELSE
             EXIT FOR
          END IF
      END FOR
      IF i = len+1 THEN
         RETURN(TRUE)
      ELSE
         RETURN(FALSE)
      END IF
   ELSE
      RETURN(FALSE)    
   END IF

END FUNCTION




################################################################################
# Funcao para testar se todos os caracteres de uma string sao em ascii         #
#..............................................................................#
# ENTRADAS : str                                                               #
#              string a ser testada                                            #
#..............................................................................#
# SAIDAS : Devolve TRUE se todos os caracteres forem em ascii                  #
#          Devolve FALSE se houver um caracter que nao seja em ascii           #
################################################################################
FUNCTION d_isascii(str)
{}

DEFINE str CHAR(500),
       len INTEGER,
       i INTEGER

   IF str IS NOT NULL THEN
      LET len = length(str)
      FOR i = 1 TO len
          IF str[i] >= ASCII 0 AND str[i]<= ASCII 127 THEN
             LET i=i
          ELSE
             EXIT FOR
          END IF
      END FOR
      IF i = len+1 THEN
         RETURN(TRUE)
      ELSE
         RETURN(FALSE)
      END IF
   ELSE
      RETURN(FALSE)
   END IF

END FUNCTION
   
#  ============================================================================
#  Retira todos os espacos de uma string de 512
#  ============================================================================
function clippAllSpaces(str)
  define str char(512)
  define strOut char(512)
	define len smallint
	define i smallint
	define j smallint

	let len = length(str)
	let j = 1
  for i = 1 to len
	  if str[i] != ' ' then
		  let strOut[j] = str[i]
			let j = j+1
    end if
	end for
  return strOut clipped
end function

#  ============================================================================
#  Parte uma string em linhas, de acordo com o comprimento enviado como 
#  parametro.
#  Devolve 4 linhas da string
#  ??? Esta funcao precisa de mais km
#  use /usr/desenvolv/local/source/4gl/funcoes  
#  ============================================================================
function splitStringByLines(str,len)
  define str char(500)
	define len smallint
	define i smallint
	define inicio_linha smallint
	define inicio_analise smallint
	define linha_corrente smallint
	define linhas array[5] of char(100)
	define mens char(128)

	let linha_corrente = 1
	let inicio_linha = 1

	initialize linhas[1], linhas[2], linhas[3], linhas[4] to null
	if length(str) = 0 then
	  return linhas[1], linhas[2], linhas[3], linhas[4]
  end if
	while (1=1)
	  let inicio_analise = len * linha_corrente
		if linha_corrente > 5 then
		  exit while
    end if
	  if inicio_analise > length(str) then
		  let inicio_analise = length(str)
			if inicio_analise <= 0 then     exit while     end if
			{ ??? LIXO
			let mens = "Linha corrente ", linha_corrente,
			           "Inicio linha ", inicio_linha, 
								 "Inicio Analise ", inicio_analise
			call errorlog(mens)
			 }
			let linhas[linha_corrente] = str[inicio_linha,inicio_analise]
			exit while
	  end if
    for i = inicio_analise to inicio_linha step -1
		  if str[i+1] = " " or          # Se o seguinte for espaco estamos no fim
		     str[i+1] = "+" or 
		     str[i+1] = "," or 
		     str[i+1] = ";" or 
		     str[i+1] = ":" or 
		     str[i+1] = "-" then
			  let linhas[linha_corrente] = str[inicio_linha,i]
			  let linha_corrente = linha_corrente + 1
			  let inicio_linha = i + 1
		  end if
	  end for
		if inicio_linha > length(str) then  let inicio_linha = length(str)  end if
	  if  inicio_linha <= 1 then
		   exit while
	  end if
	end while
	return linhas[1],
	       linhas[2],
	       linhas[3],
	       linhas[4]
end function


################################################################################
#
# Esta função parte uma sting em varias linhas (maximo de 6 Lin. e 80 Col.),
# não parte os numero e as datas
#   - limitador  -> Tamanho que cada linha deve de ter.
#   - separador  -> Caractere que separa conteodos da string 
#   - str_origem -> String original que vai ser partida
#
################################################################################
function BreakString( str_origem, separador, limitador)
define  limitador  smallint,
	separador  char(1),
        str_origem char(512),
        str_limite char(3),
        linha_prt  char(80),
	str_numeros char(14),
	max_linhas smallint,
	inicio_origem smallint,
	fim_origem smallint,
	inicio_linha smallint,
	fim_linha smallint,
	i,j smallint,
	linha_final array[6] of char(80)


	#Assim não parte os numeros e as datas
	let str_numeros = "1234567890/"
	let max_linhas = 6
	let separador = ";"

	let inicio_origem = 1
	let fim_origem = limitador

	# Numero maximo de linhas
	for i = 1 to max_linhas
	    let inicio_linha = 1
	    let fim_linha = limitador 

	    let linha_prt = str_origem[inicio_origem,fim_origem]
	    let str_limite = "*",linha_prt[limitador],"*"

  	    if  str_numeros matches str_limite then
		# Vai a procura do separador para traz
		for j = limitador to 1 STEP -1
			if j = 1 then
			   let fim_origem = limitador
			else 
			   let fim_origem = fim_origem - 1
			end if

			if linha_prt[j] = separador then
			   let fim_linha = j - 1 #assim não repete o separador
			   exit for
			end if
		end for
	    end if

	    let linha_final[i] = linha_prt[inicio_linha,fim_linha]

	    let inicio_origem = fim_origem + 1
	    let fim_origem = inicio_origem + limitador - 1

	end for

return linha_final[1],linha_final[2],linha_final[3],
       linha_final[4],linha_final[5],linha_final[6]
end function
