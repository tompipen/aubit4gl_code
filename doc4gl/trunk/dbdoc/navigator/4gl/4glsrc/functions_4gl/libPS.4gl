#  ============================================================================ 
#
#  Copyright 1997 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#                                                        
#  Autor: Carlos Patrao
#                                                        
#  Data de criacao: Tue Sep 10 12:07:07 LISBOA 1997
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : Funcoes genericas para desenvolvimento de relatorios
#                  em postscript.
#  ---------------------------------------------------------------------------
#  DESCRICAO: 
#
#  ---------------------------------------------------------------------------
#  FUNCOES: 
#           InitPostScript() 
#           ShowStr(str_p)
#           DeclareShowStr() 
#           ShowStringXY(str_p,x,y)
#           DeclareShowStringXY() 
#           SetFont(nome_fonte,dim_fonte) 
#           BeginPag()
#           EndPag()
#           DrawLine(x,y,dim,tip)
#           DeclareCm() 
#           DeclareMm() 
#           GrayRectangle(AB,AD,Ay,Ax,gr) 
#           Rectangle(AB,AD,Ay,Ax,w) 
#           DeclareNewLine(des) 
#           NewLine() 
#           MoveXY(x,y) 
#           moveOrig(x,y)
# 
#  ---------------------------------------------------------------------------
#  FORMS: 
#
#  REPORTS: 
#
#  NOTAS:
#
#  ============================================================================ 

define OrigX    decimal(4,1)
define OrigY    decimal(4,1)
define opticalX decimal(4,1)
define opticalY decimal(4,1)



# -----------------------------------------------------------------------------
# Gera o codigo em PS que permite mover o cursor para a posicao (x,y)
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#   x - Coordenada no eixo do X (em mm)
#   y - Coordenada no eixo do Y (em mm)
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS que permite mover o cursor para a 
#             posicao (x,y) 
#
# -----------------------------------------------------------------------------
# Nota: Todas as invocacoes desta funcao tem que ter em conta que a origem e'
#       o vertice superior esquerdo
#
# -----------------------------------------------------------------------------
FUNCTION MoveXY(x,y) 
  DEFINE x,y SMALLINT

  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
  IF x=0 THEN 
    LET str_aux="0"
  ELSE
    LET str_aux=x USING "<<<"," mm"
  END IF

  IF y=0 THEN 
    LET str_aux=str_aux CLIPPED," 0 moveto" 
  ELSE
    LET str_aux=str_aux CLIPPED," ",y USING "<<<"," mm moveto"
  END IF

  RETURN str_aux
END FUNCTION

# -----------------------------------------------------------------------------
# Gera o codigo em PS que permite mover a origem para determinada posicao
# Guarda a diferenca para a origem inicial canto inferior esquerdo da 
# pagina
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#   x - Coordenada no eixo do X (em mm)
#   y - Coordenada no eixo do Y (em mm)
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS que permite mover o cursor para a 
#             posicao (x,y) 
#
# -----------------------------------------------------------------------------
#
# -----------------------------------------------------------------------------
FUNCTION moveOrig(x,y)
	define x smallint
	define y smallint
	define strAux char(256)
	define xOrig, yOrig smallint

	if origX is not null and origY is not null then
	  let xOrig = origX * -1
	  let yOrig = origY * -1
  
	  # Mover para origem inicial 
	  let strAux = getval(xOrig) , " cm ", getval(yOrig),
	               " cm translate ", ascii 10
  end if

  # Salvar valores
	let origX = x
	let origY = y

	# Mover para origem nova
	let strAux = strAux clipped, getVal(x), " cm ", getVal(y),
	             " cm translate ", ascii 10
  return strAux clipped
END FUNCTION

FUNCTION resetOrig()
  initialize origX, origY to null
END FUNCTION

# -----------------------------------------------------------------------------
# Esta funcao provavelmente nao seria necessaria
# -----------------------------------------------------------------------------
FUNCTION getVal(val)
  define val smallint
	define retStr char(25)

	if val = 0 then
	  return "0"
	end if
	let retStr = val 
	return retStr
END FUNCTION


# -----------------------------------------------------------------------------
# Gera o codigo em PS que permite mover o cursor n mm para a direita da margem
# Mantendo-se no mesmo sitio (em altura)
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#   x - Coordenada no eixo do X (em mm)
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS que permite mover o cursor para a 
#             posicao (x,y) 
#
# -----------------------------------------------------------------------------
# Nota: Todas as invocacoes desta funcao tem que ter em conta que a origem e'
#       o vertice superior esquerdo
#
# -----------------------------------------------------------------------------
FUNCTION MoveX(x) 
  DEFINE x SMALLINT

  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #

  LET str_aux= " currentpoint exch pop ", x using "<<<<", " mm exch moveto "

  RETURN str_aux clipped
END FUNCTION


# -----------------------------------------------------------------------------
# Gera o codigo que permite mudar de linha em PS
# -----------------------------------------------------------------------------
# Parametros de entrada:
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS para mudar de linha
#
# -----------------------------------------------------------------------------
# Nota:
#
# -----------------------------------------------------------------------------
FUNCTION NewLine() 
  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
  LET str_aux="nl"

  RETURN str_aux
END FUNCTION

# -----------------------------------------------------------------------------
# Gera o codigo que permite mudar de linha em PS voltando à margem esquerda
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS para mudar de linha
#
# -----------------------------------------------------------------------------
# Nota:
#
# -----------------------------------------------------------------------------
FUNCTION CrLf() 
  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
  LET str_aux="crlf"

  RETURN str_aux clipped
END FUNCTION


# -----------------------------------------------------------------------------
# Gera o codigo da declaracao da funcao(em PS) NewLine
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#   des - Parametriza o espaco entre linhas
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS da funcao "NewLine"
#
# -----------------------------------------------------------------------------
# Nota:
#
# -----------------------------------------------------------------------------
FUNCTION DeclareNewLine(des) 
  DEFINE des SMALLINT 

  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
  LET str_aux="/nl { 0 -",des USING "<<<"," mm rmoveto } def"

  RETURN str_aux
END FUNCTION

# -----------------------------------------------------------------------------
# Gera o codigo da declaracao da funcao(em PS) CrLf 
#  (Carriage Return + Line Feed)
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#   lm - Left margin em mm
#   des - Parametriza o espaco entre linhas em mm
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS da funcao "NewLine"
#
# -----------------------------------------------------------------------------
# Nota:
#
# -----------------------------------------------------------------------------
FUNCTION DeclareCrLf(lm,des) 
	define lm  smallint
  DEFINE des SMALLINT 

  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
	#

  let str_aux =  "/crlf { currentpoint exch pop ", 
								 lm using "<<<<", " mm ",
								 " exch ",
								 des using "<<<<", 
								 " mm sub moveto } def "


  RETURN str_aux clipped
END FUNCTION


# -----------------------------------------------------------------------------
# Gera o codigo em PS para imprimir um rectangulo
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#   AB - Distancia entre os vertices A e B (em mm)
#   AD - Distancia entre os vertices A e D (em mm)
#   Ay - Coordenada vertical do vertice A (em mm)
#   Ax - Coordenada horizontal do vertice A (em mm)
#   w  - Largura do border
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS da funcao que permite imprimir um 
#             rectangulo
#
# -----------------------------------------------------------------------------
# Nota: A                    B
#        -------------------- 
#        |                  |
#        |                  |
#        |                  |
#        -------------------- 
#       D                    C
# -----------------------------------------------------------------------------
FUNCTION Rectangle(AB,AD,Ay,Ax,w) 
  DEFINE AB SMALLINT     # Largura
  DEFINE AD SMALLINT     # Altura
  DEFINE Ay SMALLINT
  DEFINE Ax SMALLINT
  DEFINE w  SMALLINT

  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
  LET str_aux=".",w USING "<<<"," setlinewidth"," ",
          AB USING "<<<"," ",AD USING "<<<"," ",
				  Ay USING "<<<"," ",Ax USING "<<<"," ",
          "rectangle"

  RETURN str_aux
END FUNCTION



# -----------------------------------------------------------------------------
# Gera o codigo em PS para imprimir um rectangulo com sombreado
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#   AB - Distancia entre os vertices A e B (em mm)
#   AD - Distancia entre os vertices A e D (em mm)
#   Ay - Coordenada vertical do vertice A (em mm)
#   Ax - Coordenada horizontal do vertice A (em mm)
#   gr - Grau de cinzento
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS da funcao que permite imprimir um 
#             rectangulo com sombreado 
#
# -----------------------------------------------------------------------------
# Nota: A                    B
#        -------------------- 
#        |                  |
#        |                  |
#        |                  |
#        -------------------- 
#       D                    C
# -----------------------------------------------------------------------------
FUNCTION GrayRectangle(AB,AD,Ay,Ax,gr) 
  DEFINE AB SMALLINT
  DEFINE AD SMALLINT
  DEFINE Ay SMALLINT
  DEFINE Ax SMALLINT
  DEFINE gr SMALLINT

  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
  LET str_aux=AB USING "<<<"," ",AD USING "<<<"," ",
				  Ay USING "<<<"," ",Ax USING "<<<"," ",".",gr USING "<<<"," ",
				  "grayRectangle"

  RETURN str_aux clipped
END FUNCTION



# -----------------------------------------------------------------------------
# Gera o codigo da declaracao da funcao(em PS) "mm"
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS da funcao "showStr"
#
# -----------------------------------------------------------------------------
# Nota: Esta funcao permite que se usem nos parametros das funcoes de PS 
#       valores em milimetros
# -----------------------------------------------------------------------------
FUNCTION DeclareMm() 
  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
  LET str_aux="/mm { 2.834646 mul } def"

  RETURN str_aux
END FUNCTION


# -----------------------------------------------------------------------------
# Gera o codigo da declaracao da funcao(em PS) "cm"
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS da funcao "showStr"
#
# -----------------------------------------------------------------------------
# Nota: Esta funcao permite que se usem nos parametros das funcoes de PS 
#       valores em centimetros
# -----------------------------------------------------------------------------
FUNCTION DeclareCm() 
  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
  LET str_aux="/cm { 28.346456 mul } def"

  RETURN str_aux
END FUNCTION


# -----------------------------------------------------------------------------
# Gera o codigo em PS que permite desenhar uma linha
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#   x   - Cordenada horizontal da origem do segmento de recta (em mm)
#   y   - Cordenada vertical da origem do segmento de recta (em mm)
#   dim - Tamanho do segmento de recta (em mm)
#   tip - Tipo do segmento de recta: (H)orizontal
#                                    (V)ertical
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS para desenhar uma linha
#
# -----------------------------------------------------------------------------
# Nota: O parametro "dim" pode conter valores negativos, tal significa que o
#       sentido do vector que se esta a desenhar e' na direccao da origem 
#       (canto inferior esquerdo)
#
# -----------------------------------------------------------------------------
FUNCTION DrawLine(x,y,dim,tip)
  DEFINE x,y SMALLINT
  DEFINE dim SMALLINT
  DEFINE tip CHAR(1)

  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
  LET str_aux=x USING "<<<"," mm ",y USING "<<<"," mm moveto"

  IF Upshift(tip)="V" THEN
    LET str_aux=str_aux CLIPPED," 0 ",dim," mm rlineto"
  ELSE
	 IF Upshift(tip)="H" THEN
      LET str_aux=str_aux CLIPPED," ",dim," mm 0 rlineto"
	 ELSE
      LET str_aux=str_aux CLIPPED," 0 0 rlineto"
	 END IF
  END IF

  LET str_aux=str_aux CLIPPED," stroke"

  RETURN str_aux
END FUNCTION


# -----------------------------------------------------------------------------
# Gera o codigo em PS que permite Fechar uma pagina
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS para fechar uma pagina
#
# -----------------------------------------------------------------------------
# Nota:
# -----------------------------------------------------------------------------
FUNCTION EndPag()
  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
  LET str_aux="showpage restore"

  RETURN str_aux 
END FUNCTION


# -----------------------------------------------------------------------------
# Gera o codigo em PS que permite Abrir uma pagina
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS para abrir uma pagina
#
# -----------------------------------------------------------------------------
# Nota:
# -----------------------------------------------------------------------------
FUNCTION BeginPag()
  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
  LET str_aux="save changeFont 0 297 mm moveto"

  RETURN str_aux 
END FUNCTION


# -----------------------------------------------------------------------------
# Gera o codigo em PS que permite modificar a fonte em que se esta a imprimir
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#   nome_fonte -> Nome da fonte que se pretende activar
#   dim_fonte  -> Dimensao da fonte que se pretende activar
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS para modificar o font do que se esta' a
#             imprimir
#
# -----------------------------------------------------------------------------
# Nota:
# -----------------------------------------------------------------------------
FUNCTION SetFont(nome_fonte,dim_fonte) 
  DEFINE nome_fonte CHAR(40)
  DEFINE dim_fonte SMALLINT

  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
  LET str_aux=nome_fonte CLIPPED,"Portuguese ",
				  nome_fonte CLIPPED,"Port ",
				  "[",dim_fonte USING "<<"," 0 0 ",
						dim_fonte USING "<<"," 0 0] makefont setfont"

  RETURN str_aux
END FUNCTION


# -----------------------------------------------------------------------------
# Gera o codigo da declaracao da funcao(em PS) "showStr"
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS da funcao "showStr"
#
# -----------------------------------------------------------------------------
# Nota:
# -----------------------------------------------------------------------------
FUNCTION DeclareShowStringXY() 
  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
  LET str_aux="/showStr { gsave moveto show grestore } def"

  RETURN str_aux
END FUNCTION


# -----------------------------------------------------------------------------
# Gera o codigo em PS que permite imprimir uma string na posicao (x,y)
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#   str_p - Texto que se pertende imprimir
#   x     - Deslocamento horizontal desde a origem em milimetros
#   y     - Deslocamento vertical desde a origem em milimetros
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS que permite imprimir texto em (x,y)
#
# -----------------------------------------------------------------------------
# Nota: Nao esquecer que a origem em PS (0,0) e' o canto inferior esquerdo de
#       uma pagina
# -----------------------------------------------------------------------------
FUNCTION ShowStringXY(str_p,x,y)
  DEFINE str_p CHAR(128)
  DEFINE y     SMALLINT
  DEFINE x     SMALLINT

  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
  LET str_aux=
	 "(",str_p CLIPPED,") ",x USING "<<<"," mm ",y USING "<<<"," mm showStr"

  RETURN str_aux
END FUNCTION

# -----------------------------------------------------------------------------
# Gera o codigo em PS que permite imprimir uma string para linha optica
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#   str_p - Texto que se pertende imprimir
#   n     - Numero de caracteres do campo optico
#   x     - Deslocamento horizontal desde a origem em milimetros
#   y     - Deslocamento vertical desde a origem em milimetros
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS que permite imprimir texto em (x,y)
#
# -----------------------------------------------------------------------------
# Nota: Nao esquecer que a origem em PS (0,0) e' o canto inferior esquerdo de
#       uma pagina
# -----------------------------------------------------------------------------
FUNCTION ShowOpticalStringXY(str_p,n,x,y)
  DEFINE str_p CHAR(128)
  DEFINE n     SMALLINT
  DEFINE y     SMALLINT
  DEFINE x     SMALLINT
	define initX decimal(5,2)
	define initY decimal(5,2)
	define i     smallint
	define len   smallint
  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(2048)

	let str_aux = "% Optical line", ascii 10
	let len = length(str_p)

	if opticalX is null or opticalX =0 then   
	  let opticalX = 4.8   
  end if
	if opticalY is null or opticalY =0 then   
	  let opticalY = 4   
  end if

	LET initX = x
	LET initY = y
	FOR i = 1 to n
		if i <= len then
			let initX = initX + 1
			let initY = initY - 2
      LET str_aux = str_aux clipped,
		                initX USING "<<<.<<"," mm ",
		                initY USING "<<<.<<"," mm moveto", ascii 10
      LET str_aux = str_aux clipped , "(", str_p[i], ") ShowS", ascii 10
			let initX = initX - 1
			let initY = initY + 2
		end if
    LET str_aux = str_aux clipped,
		              initX USING "<<<.<<"," mm ",
		              initY USING "<<<.<<"," mm moveto", ascii 10
    LET str_aux = str_aux CLIPPED," 0 -", opticalY using "<<",
		              " mm rlineto", ascii 10
    LET str_aux = str_aux CLIPPED, opticalX using "<<.<<"," mm 0 rlineto", 
		              ascii 10
    LET str_aux = str_aux CLIPPED," 0 ", opticalY using "<<.<<"," mm rlineto"
    LET str_aux=str_aux CLIPPED," stroke", ascii 10
		LET initX   = initX + opticalX
	END FOR
	let str_aux = substituiVirgula(str_aux)

  RETURN str_aux
END FUNCTION

# Substitui virgula por ponto (por causa dos locales)
function substituiVirgula(str)
  define str char(2048)
	define i smallint
	define len smallint

	let len = length(str)
	for i = 1 to len
	  if str[i] = ',' then
		  let str[i] = '.'
    end if
	end for
	return str
end function

# -----------------------------------------------------------------------------
# Define os tamanhos do campo optico
# -----------------------------------------------------------------------------
FUNCTION setOpticalCharSize(x,y)
	define x smallint
	define y smallint

  let opticalX = x
  let opticalY = y
END FUNCTION


# -----------------------------------------------------------------------------
# Gera o codigo em PS que permite imprimir uma string na posicao currente
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#   str_p - Texto que se pertende imprimir
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS que permite imprimir texto
#
# -----------------------------------------------------------------------------
# Nota: 
#
# -----------------------------------------------------------------------------
FUNCTION ShowStr(str_p)
  DEFINE str_p CHAR(128)

  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)
	define len     smallint
	define i       smallint
	define j       smallint

  #
  # Corpo da funcao
  #

	# Filtrar (
	let str_aux = "("
	let j = 1
	let len = length(str_p)
	for i = 1 to len
		case
	    when str_p[i] = "("
			  let str_aux = str_aux[1,j], "\\("
				let j = j + 2
	    when str_p[i] = ")"
			  let str_aux = str_aux[1,j], "\\)"
				let j = j + 2
	    otherwise
			  let str_aux = str_aux[1,j], str_p[i]
				let j = j + 1
	  end case
	end for
  LET str_aux = str_aux[1,j], ") ShowS"

  RETURN str_aux
END FUNCTION


# -----------------------------------------------------------------------------
# Gera o codigo da declaracao da funcao(em PS) "ShowS"
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem o codigo em PS da funcao "ShowS"
#
# -----------------------------------------------------------------------------
# Nota:
# -----------------------------------------------------------------------------
FUNCTION DeclareShowStr() 
  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
  LET str_aux="/ShowS /show load def"

  RETURN str_aux
END FUNCTION


# -----------------------------------------------------------------------------
# Gera o codigo que permite identificar o ficheiro como sendo de PS
#
# -----------------------------------------------------------------------------
# Parametros de entrada:
#
# -----------------------------------------------------------------------------
# Parametros de saida:
#   str_aux - Contem  a marca identifictiva do PS
#
# -----------------------------------------------------------------------------
# Nota:
# -----------------------------------------------------------------------------
FUNCTION InitPostScript() 
  #
  # Parametros de saida
  #
  DEFINE str_aux CHAR(128)

  #
  # Corpo da funcao
  #
  LET str_aux="%!PS-Adobe-1.0"

  RETURN str_aux
END FUNCTION

