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
#  Programa      : Report Postscript para testar funcoes genericas de 
#                  desenvolvimento de relatorios em PS 
#  ---------------------------------------------------------------------------
#  DESCRICAO: 
#
#  ---------------------------------------------------------------------------
#  FUNCOES: 
#           ShowString(str_p,x,y)
#           DeclareShowStr() 
#           SetFont(nome_fonte,dim_fonte) 
#           BeginPag()
#           EndPag()
#           DrawLine(x,y,dim,tip)
#           DeclareCm() 
#           DeclareMm() 
#           GrayRectangle(AB,AD,Ay,Ax,gr) 
#           Rectangle(AB,AD,Ay,Ax,w) 
# 
#  ---------------------------------------------------------------------------
#  FORMS: 
#
#  REPORTS: 
#
#  NOTAS:
#
#  ============================================================================ 


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
  DEFINE AB SMALLINT
  DEFINE AD SMALLINT
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

  RETURN str_aux
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
  LET str_aux="save  changeFont"

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
FUNCTION DeclareShowStr() 
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
FUNCTION ShowString(str_p,x,y)
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
