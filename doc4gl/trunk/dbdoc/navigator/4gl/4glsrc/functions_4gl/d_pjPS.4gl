#  ============================================================================
#
#                    FUNCOES GENERICAS DE POSTSCRIPT
#
#  Autor : Paulo Jorge Santos
#          Carlos Patrao
#          Sergio Ferreira
#  ============================================================================

#  ============================================================================
#  Gera o codigo postscript necessario à mudança de font
#  Esta é gerado no ficheiro enviado como parâmetro
#  ============================================================================
function changeFont(ficheiro)
  define ficheiro char(40)
  start report r_changeFont to ficheiro
	 output to report r_changeFont()
  finish report r_changeFont
end function

report r_changeFont()
  output
	 left margin 0
	 right margin 0
	 top margin 0
	 bottom margin 0
	 page length 1 

  format
   on last row 
      print("/changeFont{")
      print("  /reencsmalldict 12 dict def")
      print("  /ReEncodeSmall {")
      print("    reencsmalldict begin")
      print("    /newcodesandnames exch def")
      print("    /newfontname exch def")
      print("    /basefontname exch def")
      print("    /basefontdict basefontname findfont def")
      print("    /newfont basefontdict maxlength dict def")
      print
      print("    basefontdict {")
      print("      exch dup /FID ne {")
      print("        dup /Encoding eq {")
      print("          exch dup length array copy")
      print("          newfont 3 1 roll put }")
	   print("     { exch newfont 3 1 roll put")
	   print("     } ifelse")
      print("        }")
      print("        {pop pop}")
      print("        ifelse")
      print("    }forall")
      print
      print("    newfont /FontName newfontname put")
      print("    newcodesandnames aload pop")
      print("    newcodesandnames length 2 idiv {")
      print("      newfont /Encoding get 3 1 roll put")
      print("    }repeat")
      print("    newfontname newfont definefont pop ")
      print("    end")
      print("  }def")
      print
   print("/PortVec[")
   print(" 16#E0/agrave   16#E1/aacute   16#E3/atilde       16#EE/ordfeminine")
   print(" 16#C0/Agrave   16#C1/Aacute   16#C3/Atilde")
   print(" 16#E8/egrave   16#E9/eacute   16#EA/ecircumflex  16#E2/acircumflex")
   print(" 16#C8/Egrave   16#C9/Eacute   16#CA/Ecircumflex  16#B6/Acircumflex")
   print(" 16#EC/igrave     16#ED/iacute   16#CC/Igrave       16#CD/Iacute")
   print(" 16#F2/ograve     16#F3/oacute   16#F4/ocircumflex  16#F5/otilde")
   print(" 16#D2/Ograve     16#D3/Oacute   16#D4/Ocircumflex  16#D5/Otilde")
   print(" 16#F9/ugrave     16#FA/uacute   16#D9/Ugrave       16#DA/Uacute")
   print(" 16#E7/ccedilla   16#C7/Ccedilla 16#A9/copyright    16#AE/registered")
   print(" 16#AA/femordinal 16#BA/mascordinal")
      print("] def")
      print("}def")
	  print
end report


# ------------------------------------------------------------------------------
# DATA.: 09/09/1997
# AUTOR: Carlos Patrao
# ------------------------------------------------------------------------------
# Gera o PS para acrescentar a uma fonte os caracteres Portugueses
#
# ------------------------------------------------------------------------------
# Parametros de entrada:
#   nome_fonte -> Nome da fonte que vai ser transformada
#   nome_fich  -> Nome do ficheiro para onde o PS vai ser gerado
#
# ------------------------------------------------------------------------------
# Parametros de saida:
#
# ------------------------------------------------------------------------------
# Notas:
#
# ------------------------------------------------------------------------------
FUNCTION FontPortug(nome_fonte,nome_fich)
  DEFINE nome_fonte CHAR(40)
  DEFINE nome_fich CHAR(40)

  #
  # Corpo da funcao
  #
  START REPORT RepFontPortug to nome_fich
	 OUTPUT TO REPORT RepFontPortug(nome_fonte)
  FINISH REPORT RepFontPortug 
END FUNCTION


# ------------------------------------------------------------------------------
# DATA.: 09/09/1997
# AUTOR: Carlos Patrao
# ------------------------------------------------------------------------------
# Gera o PS para acrescentar a uma fonte os caracteres Portugueses e' invocado 
# pela funcao "FontPortug"
#
# ------------------------------------------------------------------------------
# Parametros de entrada:
#   nome_fonte -> Nome da fonte que vai ser transformada
#
# ------------------------------------------------------------------------------
# Parametros de saida:
#
# ------------------------------------------------------------------------------
# Notas:
#
# ------------------------------------------------------------------------------
REPORT RepFontPortug(nome_fonte)
  DEFINE nome_fonte CHAR(40)

  OUTPUT
	 LEFT MARGIN 0
	 RIGHT MARGIN 0
	 TOP MARGIN 0
	 BOTTOM MARGIN 0
	 PAGE LENGTH 1

  FORMAT
    ON LAST ROW 
      PRINT "/",nome_fonte CLIPPED,"Portuguese{"
      PRINT " /",nome_fonte CLIPPED,
				" /",nome_fonte CLIPPED,"-Portuguese PortVec ReEncodeSmall"
      PRINT " /",nome_fonte CLIPPED,"Port",
				" /",nome_fonte CLIPPED,"-Portuguese findfont def"
      PRINT "}def"
      PRINT
END REPORT


#  ============================================================================
#  Font para Helvetica portuguese
#  ============================================================================
function helvPortug(ficheiro)
  define ficheiro char(40)

  start report r_helvPortug to ficheiro 
	 output to report r_helvPortug()
  finish report r_helvPortug
end function

report r_helvPortug()
  output
	 left margin 0
	 right margin 0
	 top margin 0
	 bottom margin 0
	 page length 1

  format
   on last row 
     print("/helvPortuguese{")
     print("  /Helvetica /Helvetica-Portuguese PortVec ReEncodeSmall")
     print("  /helvPort /Helvetica-Portuguese findfont def")
     print("}def")
     print
end report

#  ============================================================================
#  Logotipo da despodata
#  ============================================================================
function logotipo(ficheiro)
  define ficheiro char(40)

  start report r_logotipo to ficheiro 
	 output to report r_logotipo()
  finish report r_logotipo
end function

report r_logotipo()
  output
	 left margin 0
	 right margin 0
	 top margin 0
	 bottom margin 0
	 page length 1 

  format
   on last row 
     print("/logotipo{")
     print("  10 mul")
     print("  /topopag exch def")
     print("  10 mul")
     print("  /LM exch def")
     print("  /cont 1 def")
     print("  gsave")
     print("  .1 .1 scale")
     print("  %-----------RECTANGULOS A GRANEL--------------")
     print("  5 {")
     print("    2.8 11.4 topopag cont 3.2 mul LM add rectangle")
     print("    /cont cont 1 add def")
     print("  } repeat")
     print("  4 { ")
     print("    2.8 11.4 topopag 6.3 sub cont 3.2 mul LM add 0 grayRectangle")
     print("    /cont cont 1 add def")
     print("  } repeat")
     print("  %-----------SHOW DE STRINGS--------------")
     print("  LM 3.7 add cm topopag 9.5 sub cm moveto")
     print("  1.5 cm 0 (despo) ashow")
     print
     print("  1 setgray")
     print("  LM 19.8 add cm topopag 9.5 sub cm moveto")
     print("  -.5 cm 0 16#64 1.9 cm 0 (data) awidthshow     % d em hexa(64) ")
     print("  grestore")
     print("}def")
     print
end report


# ------------------------------------------------------------------------------
# DATA.: 10/09/1997
# AUTOR: Carlos Patrao
# ------------------------------------------------------------------------------
# Gera o PS para desenhar rectangulos que aceitam medidas em milimetros
#
# ------------------------------------------------------------------------------
# Parametros de entrada:
#   nome_fich  -> Nome do ficheiro para onde o PS vai ser gerado
#
# ------------------------------------------------------------------------------
# Parametros de saida:
#
# ------------------------------------------------------------------------------
# Notas:
#
# ------------------------------------------------------------------------------
FUNCTION RectangulosMm(nome_fich)
  DEFINE nome_fich CHAR(40)

  START REPORT RepRectangulosMm TO nome_fich 
	 OUTPUT TO REPORT RepRectangulosMm()
  FINISH REPORT RepRectangulosMm
END FUNCTION


# ------------------------------------------------------------------------------
# DATA.: 10/09/1997
# AUTOR: Carlos Patrao
# ------------------------------------------------------------------------------
# Gera o PS para desenhar rectangulos que aceitam medidas em milimetros
#
# ------------------------------------------------------------------------------
# Parametros de entrada:
#
# ------------------------------------------------------------------------------
# Parametros de saida:
#
# ------------------------------------------------------------------------------
# Notas:
#
# ------------------------------------------------------------------------------
REPORT RepRectangulosMm()
  OUTPUT
	 LEFT MARGIN 0
	 RIGHT MARGIN 0
	 TOP MARGIN 0
	 BOTTOM MARGIN 0
	 PAGE LENGTH 1 

  FORMAT
    ON LAST ROW 
      PRINT("/prepareStack {       % controi stack de modo a alimentar rlineto")
      PRINT("  -1 mul          ")
      PRINT("  mm")
      PRINT("  exch")
      PRINT("  mm")
      PRINT("  dup")
      PRINT("  -1 mul")
      PRINT("  0 4 2 roll  ")
      PRINT("}def")
      PRINT
      PRINT("/baseRectangle {")
      PRINT("  mm                   %   converte em mm")
      PRINT("  exch                 %   as coodenadas")
      PRINT("  mm                   %   do rectangulo")
      PRINT("  newpath")
      PRINT("  moveto ")
      PRINT("  prepareStack")
      PRINT("  0 rlineto            %    -------->|")
      PRINT("  rlineto              %             |")
      PRINT("  0 rlineto            %    <--------V")
      PRINT("  closepath")
      PRINT("}def")
      PRINT
      PRINT("/rectangle {           % largura altura y x ")
      PRINT("  baseRectangle")
      PRINT("  stroke")
      PRINT("}def")
      PRINT
      PRINT("/grayRectangle {       % largura altura y x grauCinzento")
      PRINT("  gsave")
      PRINT("    setgray")
      PRINT("    baseRectangle")
      PRINT("    fill")
      PRINT("  grestore")
      PRINT("}def")
      PRINT
END REPORT


function rectangles(ficheiro)
  define ficheiro char(40)

  start report r_rectangles to ficheiro 
	 output to report r_rectangles()
  finish report r_rectangles
end function

report r_rectangles()
  output
	 left margin 0
	 right margin 0
	 top margin 0
	 bottom margin 0
	 page length 1 

  format
   on last row 
     print("/prepareStack {        % controi stack de modo a alimentar rlineto")
     print("  -1 mul          ")
     print("  cm")
     print("  exch")
     print("  cm")
     print("  dup")
     print("  -1 mul")
     print("  0 4 2 roll  ")
     print("}def")
     print
     print("/baseRectangle {")
     print("  cm                   %   converte em cm")
     print("  exch                 %   as coodenadas")
     print("  cm                   %   do rectangulo")
     print("  newpath")
     print("  moveto ")
     print("  prepareStack")
     print("  0 rlineto            %    -------->|")
     print("  rlineto              %             |")
     print("  0 rlineto            %    <--------V")
     print("  closepath")
     print("}def")
     print
     print("/rectangle {           % largura altura y x ")
     print("  baseRectangle")
     print("  stroke")
     print("}def")
     print
     print("/grayRectangle {       % largura altura y x grauCinzento")
     print("  gsave")
     print("    setgray")
     print("    baseRectangle")
     print("    fill")
     print("  grestore")
     print("}def")
     print
end report
