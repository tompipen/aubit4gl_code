#  ============================================================================
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#
#  Divisao de desenvolvimento e producao de software.
#
#  Autor: Sergio Ferreira
#
#  Data de criacao: 20/12/1999
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : Livraria generica de 4gl
#  ---------------------------------------------------------------------------
#  DESCRICAO:  Impressao de postscript
#              Utilitarios de alto nivel para postscript
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
#database desp
database sysmaster

#  Variaveis a que contem nomes dos ficheiros temporarios
define fileChangeFont           char(64)
define fileHelveticaPortuguese  char(64)
define fileHelveticaBPortuguese char(64)
define fileCourierPortuguese    char(64)
define fileRectangle            char(64)
define fileRectangleMm          char(64)
define fileUtils                char(128)
define fileBodyPs               char(128)
define outputNm                 char(64)

define xTitle     smallint
define yTitle     smallint
define shading    smallint
define lineLength smallint


#  ============================================================================ 
#  Recebendo como parametros o nome do ficheiro que deve ser impresso e o nome
#  do ficheiro onde devce ser colocado o resultado final efectua todas as 
#  accoes necessarias para a correcta geracao do mesmo
#  ============================================================================ 
function genReportPs(flBodyPs,_outputNm)
  define flBodyps char(64)
	define _outputNm char(64)

  call psFormFieldsetOutputNm(_outputNm)
	call psFormFieldsetBodyPs(flBodyPs)
	call endReportPs()
end function

#  ============================================================================ 
#  Afecta a propriedade que contem o nome do ficheiro de postscript
#  onde a o ficheiro final sera gerado (com concatenacao de todos os .ps)
#  ============================================================================ 
function psFormFieldsetOutputNm(_outputNm)
	define _outputNm char(64)

  let outputNm = _outputNm
end function

#  ============================================================================ 
#  ============================================================================ 
function psFormFieldsetBodyPs(flBodyPs)
	define flBodyPs char(64)

  let fileBodyPs = flBodyPs
end function

#  ============================================================================ 
#  Terminou a emissao da factura. Esta funcao trata de imprimir (ou visualizar)
#  e remover o lixo
#  ============================================================================ 
function endReportPs()
	call psFormFieldConcatPsFiles()
	#call viewReportPs()
  #call cleanFacturaPs()
end function


#  ============================================================================ 
#  Interface para impressao da factura
#  ============================================================================ 
function psFormFieldprintReportPs()
  define comm     char(256)
	define ans      smallint
	define n_copias smallint

	#let n_copias = getNCopias()
	call d_printFile_n(outputNm,"Relatorio",n_copias)
end function

#  ============================================================================ 
#  Permite visualizar o ficheiro postscript no gv
#  ============================================================================ 
function viewReportPs()
  define comm char(64)
	define ans  smallint

	let comm = "gv ", outputNm
	let ans = d_run(comm)
end function

#  ============================================================================ 
#  Inicializacoes diversas do postscript, entre as quais o código de funções
#  postscript (def) utilizados depois no report em si
#  ============================================================================ 
function initReportPs()
  define pidNum integer

	let pidNum = d_getpid()
  let fileChangeFont            = "/tmp/cha_", pidNum using "<<<<<<<<", ".ps"
  let fileHelveticaPortuguese   = "/tmp/heP_", pidNum using "<<<<<<<<", ".ps"
  let fileHelveticaBPortuguese  = "/tmp/heBP_", pidNum using "<<<<<<<<", ".ps"
  let fileCourierPortuguese     = "/tmp/courBP_", pidNum using "<<<<<<<<", ".ps"

  let fileRectangle            = "/tmp/rtg_", pidNum using "<<<<<<<<", ".ps"
  let fileRectangleMm          = "/tmp/rtgmm_", pidNum using "<<<<<<<<", ".ps"
  let fileUtils                = "/tmp/utils_", pidNum using "<<<<<<<<", ".ps"

  call changeFont(fileChangeFont)
  CALL FontPortug("Helvetica",fileHelveticaPortuguese)
  CALL FontPortug("Helvetica-Bold",fileHelveticaBPortuguese)
  CALL FontPortug("Courier",fileCourierPortuguese)

  CALL RectangulosMm(fileRectangleMm)
  call rectangles(fileRectangle)
  call psFormFieldGenUtilsPs(fileUtils)
end function

#  ============================================================================ 
#  Limpa os postscripts gerados para emissao da factura
#  ============================================================================ 
function psFormFieldcleanReportPs()
  define ans smallint

  let ans = d_unlink(fileChangeFont)
  let ans = d_unlink(fileHelveticaPortuguese)
  let ans = d_unlink(fileHelveticaBPortuguese)
  let ans = d_unlink(fileCourierPortuguese)
  let ans = d_unlink(fileRectangle)
  let ans = d_unlink(fileRectangleMm)
  let ans = d_unlink(fileUtils)
  let ans = d_unlink(fileBodyPs)
  let ans = d_unlink(outputNm)
end function

#  ============================================================================ 
#  Geracao de um ficheiro com funcoes utilitarias para postsript
#  ============================================================================ 
function psFormFieldgenUtilsPs(fileUtl)
	define fileUtl char(64)

  start report     psFormFieldRepGenUtilsPs to fileUtl
  output to report psFormFieldRepGenUtilsPs()
  finish report    psFormFieldRepGenUtilsPs
end function

#  ============================================================================ 
#  Report para geracao de funcoes utilitarias em postscript
#  ============================================================================ 
report psFormFieldrepGenUtilsPs()

  format 
		on every row
      PRINT DeclareCm() 
      PRINT DeclareMm() 

	    # Mudanca de linha sem calculos
      PRINT DeclareCrLf(12,5)

      PRINT DeclareShowStringXY() 
      PRINT DeclareShowStr() 
end report

#  ============================================================================ 
#  Concatena todos os ficheiros que contituem a factura num unico cujo
#  nome é enviado como parâmetro
#  ============================================================================ 
function psFormFieldconcatPsFiles()
	start report     psFormFieldRepConcatPsFiles to outputNm
	output to report psFormFieldRepConcatPsFiles()
	finish report    psFormFieldRepConcatPsFiles
end function

#  ============================================================================ 
#  Report usado apenas para fazer a concatenacao de todos os ficheiros ps que
#  constituem a factura
#  ============================================================================ 
report psFormFieldrepConcatPsFiles()
	output
		left margin 0
		top margin 0
		bottom margin 0
		page length 2
  format 
		on every row
      print initPostscript()
      print file (fileChangeFont)
      print file (fileHelveticaPortuguese)
      print file (fileHelveticaBPortuguese)
      print file (fileCourierPortuguese)
      print file (fileRectangle)
      print file (fileRectangleMm)
      print file (fileUtils)
      print file (fileBodyPs)
end report


#  ??? Estes deviam ir para um modulo so de funcoes para geracao de 
#      funcoes para formularios

#  ============================================================================ 
#  ============================================================================ 
function psFieldInitDefaults()
  let lineLength = 60
	let xTitle     = 1
	let yTitle     = 3
	let shading    = 0
end function

#  ============================================================================ 
#  Afecta a variavel modular de largura do border com o valor definido
#  ============================================================================ 
function psFieldSetBorderLength(_length)
  define _length smallint

  let lineLength = _length
end function

#  ============================================================================ 
#  Afecta a posicao do titulo do campo relativamente ao inicio do campo
#  (de cima pra baixo)
#  ============================================================================ 
function psFieldSetTitlePosition(x,y)
  define x smallint
	define y smallint

  let xTitle = x
	let yTitle = y
end function

#  ============================================================================ 
#  Afecta o shading usado no campo a preencher (funcoes para formularios)
#  ============================================================================ 
function psFieldSetShading(_shading)
  define _shading smallint

	let shading = _shading
end function

#  ============================================================================ 
#  Gera um campo com o titulo no canto superior esquerdo da pagina
#  A altura e largura definida
#  ============================================================================ 
function psFormField(x,y,largura,altura,titulo)
  define x           smallint
  define y           smallint
  define largura     smallint
  define altura      smallint
	define titulo      char(256)
	define strPs       char(512)

	define titleX      smallint
	define titleY      smallint

	let strPs = ""

	# Shading (caso exista)
	if shading > 0 and shading is not null then
    let strPs = GrayRectangle(largura,altura,y,x,shading), ascii 10
	end if

	# Quadrado preto
	let strPs = strPs clipped,
							Rectangle(largura,altura,y, x,lineLength), 
							ascii 10

  # Titulo
	if titulo is not null then
		let titleX = x + xTitle
		let titleY = y - yTitle
		let strPs  = strPs clipped,
								 ShowStringXY(titulo,titleX,titleY), ascii 10
  end if
  return strPs clipped
end function

#  ============================================================================ 
#  Gera um data field vertical (titulo em cima e dados em baixo)
#  Assume que se parte a meio o campo em altura
#  ============================================================================ 
function psFormVerticalField(x,y,largura,altura,titulo,dados)
  define x           smallint
  define y           smallint
  define largura     smallint
  define altura      smallint
	define titulo      char(60)
	define dados       char(60)
	define strPs       char(512)

  let strPs = GrayRectangle(largura,altura/2,y, x,90), " ",
			        Rectangle    (largura,altura,y, x,60), " ",
			        DrawLine     (x,y-altura/2,largura,"H"), " ",
              #SetFont("Courier",11), " ",
							ShowStringXY (titulo,x+1,y-altura/2+1),
							ShowStringXY(dados,x+1,y-altura+1)

  return strPs clipped
end function

