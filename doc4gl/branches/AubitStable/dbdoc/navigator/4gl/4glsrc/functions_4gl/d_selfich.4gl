#database despodata
database sysmaster
#  ============================================================================
#
#  Copyright 1993 DESPODATA - Lisboa, PORTUGAL
#
#  Divisao de desenvolvimento e produção de software.
#
#  Autor:  Joao Alexandre Costa
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
#  NOTAS: Insere os ficheiros seleccionados numa tabela, da qual passa o
#         nome.
#
#
#  ----------------------------------------------------------------
#
#  ============================================================================

globals "4glsrc/functions_4gl/d_libglob.4gl"


define 
    lin_fich,col_fich,ncol_fich,nlin_fich integer,     # Para o filtro
    lin_ficheiros,col_ficheiros,nlin_ficheiros,ncol_ficheiros integer,
    lin_dir,col_dir,nlin_dir,ncol_dir integer,
    lin_directoria,col_directoria,nlin_directoria,ncol_directoria integer,
    posicao integer,
    fich_corrente,directoria_corrente char(64),
    directorias,ficheiros record
      dimlinha smallint,
      nlinhas smallint,
      scr_idx,arr_idx smallint,
      linhas array[300] of record
        marca char(1),
        texto char(60)
      end record
    end record,
    MAXLINES smallint

function d_selfich(filtro,dir)
{}
  define filtro,dir char(64)
  define tecla integer,
	 tabtemp char(14),
	 ctemp char(100),
	 existe smallint,
	 pidstr integer,
	 pr_temp record 
	   nomedir char(64),
	   ficheiro  char(14)
	 end record 


  let existe = FALSE
  let fich_corrente = filtro
  let directoria_corrente = dir
  let status = d_chdir(directoria_corrente)
  if status = -1 then
    call d_dialogOk(9,15,"","","Directoria nao existente",
            "ou não pode ser acedida","!","")
  else
    let directoria_corrente = d_pwd()
  end if
  let directorias.dimlinha = 40
  let ficheiros.dimlinha = 50
  let MAXLINES = 300
  call init_ecran()
  let posicao = 1   # Janela do ficheiro (filtro)
		    #  2 Janela da directoria corrente
		    #  3 Janela dos ficheiros
		    #  4 Janela das directorias
  
  let tecla =  d_opdir(directoria_corrente)
  if tecla <= 0 then
	 call d_dialogOk(9,15,"","","Directoria nao existente",
			      "ou não pode ser acedida","!","")
	 # Nao esquecer do que devolve
    return ""
  end if
  call carrega_dir()
  call carrega_fich()
  let directorias.scr_idx = 1
  let directorias.arr_idx = 1
  let ficheiros.scr_idx = 1
  let ficheiros.arr_idx = 1
  call mostraArray(1)   # directoria 
  call mostraArray(2)   # ficheiro
  while true
    case
      when  posicao = 1
	call pos_filtro()
      when  posicao = 2
	call pos_dir()
      when  posicao = 3
	call pos_ficheiro()
      when  posicao = 4
	call pos_directoria()
      otherwise
	exit while
    end case
  end while
  call d_cldir()

  call end_ecran()
  LET pidstr  = d_getpid()
  let tabtemp = "dirf", pidstr USING "<<<<&"

  let ctemp="create temp table ",tabtemp clipped ,
	    " ( nomedir char(64),ficheiro char(14) ) "
  prepare pctemp from ctemp
  execute pctemp

  for posicao = 1 to MAXLINES
    if ficheiros.linhas[posicao].texto is null then
      exit for
    end if
    if ficheiros.linhas[posicao].marca is null then
      continue for
    end if
    let pr_temp.nomedir = directoria_corrente clipped
    let pr_temp.ficheiro = ficheiros.linhas[posicao].texto[37,50] clipped

	 let existe = TRUE
    let ctemp="insert into ",tabtemp clipped," values ( ? , ?) "
    prepare pf from ctemp
    execute pf using pr_temp.*
  end for
  if existe then
    return tabtemp
  else
	 return ""
  end if
end function

function init_ecran()
{}
# Desenha o ecran
  define coltmp integer

    # FILTRO
    let lin_fich       = 1
    let col_fich       = 2
    let nlin_fich      = 3
    let ncol_fich      = 30

    #FICHEIROS
    let lin_ficheiros  = 13
    let col_ficheiros  = 2
    let nlin_ficheiros = 11
    let ncol_ficheiros = 76

    #DIRECTORIA CORRENTE
    let lin_dir        = 5
    let col_dir        = 2
    let nlin_dir       = 4
    let ncol_dir       = 30

    #DIRECTORIAS
    let lin_directoria  = 1
    let col_directoria  = 36
    let nlin_directoria = 12
    let ncol_directoria = 42

  open window w_ecran at 1,1 with 23 rows,79 columns 


  call fgl_drawbox(nlin_fich,ncol_fich,lin_fich,col_fich)   # Caixa do filtro
  call fgl_drawbox(nlin_dir,ncol_dir,lin_dir,col_dir)   # Caixa da directoria

  # Caixa dos ficheiros
  call fgl_drawbox(nlin_ficheiros,ncol_ficheiros,lin_ficheiros,col_ficheiros)

  # Caixa das directorias
 call fgl_drawbox(nlin_directoria,ncol_directoria,lin_directoria,col_directoria) 
  
 let coltmp = col_fich + 2
 display "FILTRO" at lin_fich,coltmp attribute(reverse)
 let coltmp = col_dir + 2
 display "DIRECTORIA CORRENTE" at lin_dir,coltmp attribute(reverse)
 let coltmp = col_ficheiros + 2
 display "FICHEIROS" at lin_ficheiros,coltmp attribute (reverse)
 let coltmp = col_directoria + 2
 display "DIRECTORIAS" at lin_directoria,coltmp attribute (reverse)


 call mostra_dir(FALSE)
 call mostra_filtro(FALSE)
end function

function end_ecran()
{}
  close window w_ecran
end function



function pos_filtro()
{}
  define coltmp,tecla,ncol integer

    call mostra_filtro(TRUE)
    while true
    let tecla = getkey()
    case
      when tecla = 13 
        let coltmp  = col_fich + 1
	let tecla = lin_fich + 1
	let ncol = ncol_fich - 2
	open window w_fi at tecla,coltmp with 1 rows ,ncol columns
	prompt "" for  fich_corrente
	close window w_fi
        call mostra_filtro(TRUE)
        call carrega_fich()
        call mostraArray(2)   # ficheiro
      when tecla = 27 # ESCAPE
	let posicao = 99
	exit while
      when tecla = 9  # TAB
	let posicao = 2
	exit while
      otherwise
	 let tecla = tecla
    end case
    end while
    call mostra_filtro(FALSE)
end function


function pos_dir()
{}
  define ncol,coltmp,tecla integer,
	  nova_directoria char(64)

    call mostra_dir(TRUE)
    while true
    let tecla = getkey()
    case
      when tecla = 13 
        let coltmp = col_dir + 1
	let tecla = lin_dir + 1
	let ncol = ncol_dir - 2
	open window w_di at tecla,coltmp with 1 rows ,ncol columns
	prompt "" for  nova_directoria
	close window w_di
        let status = d_chdir(nova_directoria)
	if status = -1 then
           call d_dialogOk(9,15,"","","Directoria nao existente",
				  "ou não pode ser acedida","!","")
	else
	  let directoria_corrente = ""
          let directoria_corrente = d_pwd()
          call mostra_dir(TRUE)
	  call d_newdir(directoria_corrente) returning tecla
	  call carrega_dir()
	  call carrega_fich()
	  call mostraArray(1)
          call mostraArray(2)   # ficheiro
	end if
      when tecla = 27 # ESCAPE
	let posicao = 99
	exit while
      when tecla = 9  # TAB
	let posicao = 3
	exit while
      otherwise
	 let tecla = tecla
    end case
    end while
    call mostra_dir(FALSE)
end function

function pos_ficheiro()
{}
  define coltmp,tecla,idx integer

    let ficheiros.arr_idx = 1
    let ficheiros.scr_idx = 1
    call mlinhaArray(2,TRUE)    # mostra a linha corrente em reverse
    let coltmp = col_ficheiros + 2
    while true
    let tecla = getkey()
    case 
      when tecla = 2000  # tecla cima
	     if ficheiros.arr_idx = 1 then
	       error ""
	       continue while
	     end if
             call mlinhaArray(2,FALSE)
	     let ficheiros.arr_idx = ficheiros.arr_idx - 1
	     if ficheiros.scr_idx = 1 then
	       call scrollArray(2,"UP")
	     else
	       let ficheiros.scr_idx = ficheiros.scr_idx - 1
	     end if
             call mlinhaArray(2,TRUE)

      when tecla = 2001 OR tecla = 32 # tecla baixo
	     let idx=ficheiros.arr_idx
	     if ficheiros.arr_idx = MAXLINES or 
		 ficheiros.linhas[idx+1].texto is null then
	         error ""
	         continue while
	     end if
             call mlinhaArray(2,FALSE)
	     let ficheiros.arr_idx = ficheiros.arr_idx + 1
	     if ficheiros.scr_idx < nlin_ficheiros-2 then
	       let ficheiros.scr_idx = ficheiros.scr_idx + 1
	     else
	       call scrollArray(2,"DOWN")
	     end if
             call mlinhaArray(2,TRUE)
      when tecla = 13    # enter
	    let idx = ficheiros.arr_idx
            if  ficheiros.linhas[idx].marca is null then
              let ficheiros.linhas[idx].marca = '*'
	    else
              initialize ficheiros.linhas[idx].marca  to null
	    end if
             call mlinhaArray(2,TRUE)
      when tecla = 27 # ESCAPE
	     let posicao = 99
	     exit while
      when tecla = 47
	for idx=1 to MAXLINES
	  if ficheiros.linhas[idx].texto is null then
	    exit for
	  else
            if  ficheiros.linhas[idx].marca is null then
              let ficheiros.linhas[idx].marca = '*'
	    else
              initialize ficheiros.linhas[idx].marca  to null
	    end if
	  end if
	end for
	call mostraArray(2)
        call mlinhaArray(2,TRUE)

      when tecla = 9  # TAB
	let posicao = 4
	exit while
      otherwise
	call trata_teclaF(tecla)
    end case
    end while
    call mlinhaArray(2,FALSE)
end function

function pos_directoria()
{}
  define coltmp,tecla,idx integer,
	 nova_directoria char(64)

    let coltmp = col_directoria + 2
    let directorias.arr_idx = 1
    let directorias.scr_idx = 1
    call mlinhaArray(1,TRUE)    # mostra a linha corrente em reverse
    while true
    let tecla = getkey()
    case 
      when tecla = 2000  # tecla cima
	     if directorias.arr_idx = 1 then
	       error ""
	       continue while
	     end if
             call mlinhaArray(1,FALSE)
	     let directorias.arr_idx = directorias.arr_idx - 1
	     if directorias.scr_idx = 1 then
	       call scrollArray(1,"UP")
	     else
	       let directorias.scr_idx = directorias.scr_idx - 1
	     end if
             call mlinhaArray(1,TRUE)

      when tecla = 2001  OR tecla = 32 # tecla baixo
	     let idx=directorias.arr_idx
	     if directorias.arr_idx = MAXLINES or 
		 directorias.linhas[idx+1].texto is null then
	         error ""
	         continue while
	     end if
             call mlinhaArray(1,FALSE)
	     let directorias.arr_idx = directorias.arr_idx + 1
	     if directorias.scr_idx < nlin_directoria-2 then
	       let directorias.scr_idx = directorias.scr_idx + 1
	     else
	       call scrollArray(1,"DOWN")
	     end if
             call mlinhaArray(1,TRUE)
      when tecla = 13    # enter
	      # mudar de directoria
	      let idx = directorias.arr_idx
	      let nova_directoria = directoria_corrente clipped,"/",
		  directorias.linhas[idx].texto[27,40] clipped
             let status = d_chdir(nova_directoria)
	     if status = -1 then
	         call d_dialogOk(9,15,"",nova_directoria clipped,
		  "Directoria nao existente","ou não pode ser acedida","!","")
	     else
	       initialize directoria_corrente to null
	       let directoria_corrente = d_pwd()
               call mlinhaArray(1,FALSE)
               call mostra_dir(FALSE)
	       call d_newdir(directoria_corrente) returning tecla
               let directorias.arr_idx = 1
               let directorias.scr_idx = 1
               call carrega_dir()
               call carrega_fich()
               call mostraArray(1)   # directoria 
               call mostraArray(2)   # ficheiro
	       call carrega_dir()
               call mlinhaArray(1,TRUE)
	    end if
      when tecla = 27 # ESCAPE
	     let posicao = 99
	     exit while
      when tecla = 9  # TAB
	let posicao = 1
	exit while
      otherwise
	call trata_teclaD(tecla)
    end case
    end while
    call mlinhaArray(1,FALSE)
end function

function mostra_dir(rev)
{}
  define rev smallint   # TRUE REVERSE
  define lintmp,coltmp smallint,
	 texto char(64)

  let lintmp = lin_dir + 1
  let coltmp = col_dir + 1
  for coltmp=col_dir+1 to col_dir + ncol_dir -2
    display " " at lintmp,coltmp
  end for
  let lintmp = lintmp + 1
  for coltmp=col_dir+1 to col_dir + ncol_dir -2
    display " " at lintmp,coltmp
  end for
  let lintmp = lin_dir + 1
  let coltmp = col_dir + 1
  if rev then
    let texto = directoria_corrente[1,ncol_dir -2 ]
    display texto clipped at lintmp,coltmp  attribute(reverse)
    let lintmp = lintmp + 1
    let texto = directoria_corrente[ncol_dir -2 + 1 ,(ncol_dir-2) * 2]
    display texto clipped at lintmp,coltmp  attribute(reverse)
  else
    let texto = directoria_corrente[1,ncol_dir -2 ]
    display texto clipped at lintmp,coltmp  
    let lintmp = lintmp + 1
    let texto = directoria_corrente[ncol_dir -2 + 1 ,(ncol_dir-2) * 2]
    display texto clipped at lintmp,coltmp 
  end if
end function

function mostra_filtro(rev)
{}
  define rev smallint   # TRUE REVERSE
  define lintmp,coltmp smallint

  let lintmp = lin_fich + 1
  let coltmp = col_fich + 1
  for coltmp=col_fich+1 to col_fich + ncol_fich -2
    display " " at lintmp,coltmp
  end for
  let coltmp = col_fich + 1
  if rev then
    display fich_corrente clipped at lintmp,coltmp  attribute(reverse)
  else
    display fich_corrente clipped at lintmp,coltmp 
  end if
end function

function actual_ndir()
{}
  define n,coltmp smallint

  let n = directorias.nlinhas
  let coltmp = col_directoria + 2 + 13
  display n USING "##&" at lin_directoria,coltmp attribute (reverse)
end function

function actual_nfich()
{}
  define n,coltmp smallint

  let n = ficheiros.nlinhas
  let coltmp = col_ficheiros + 2 + 11
  display n USING "##&" at lin_ficheiros,coltmp attribute (reverse)
end function

function carrega_dir()
{}
  define i integer

  declare cr_dir cursor for
  select  * from d_tmpdir
  where modo[1] = 'd'
  order by 1

  let directorias.scr_idx = 1
  let directorias.arr_idx = 1
  for i=1 to 300
    initialize directorias.linhas[i].texto to null
  end for
  let i = 1
  foreach cr_dir into d_pr_dir.*
    let directorias.linhas[i].marca = 'D'
    let directorias.linhas[i].texto = d_pr_dir.modo," ",
				d_pr_dir.nome_uid," ",
				d_pr_dir.nome[1,14]
    let  i = i + 1
  end foreach
  initialize directorias.linhas[i].marca to null
  let directorias.nlinhas = i-1
  call actual_ndir()
end function

function carrega_fich()
{}
  define i integer,
	 find char(100)

  let find = "select  * from d_tmpdir where modo[1] != 'd'",
	     "and nome matches \"",fich_corrente clipped,"\"",
	     " order by 1"
  prepare pfind from find
  declare cr_fich cursor for pfind

  let ficheiros.scr_idx = 1
  let ficheiros.arr_idx = 1
  for i=1 to 300
    initialize ficheiros.linhas[i].texto to null
  end for
  let i = 1
  foreach cr_fich into d_pr_dir.*
    initialize ficheiros.linhas[i].marca to null
    let ficheiros.linhas[i].texto = d_pr_dir.modo," ",
				d_pr_dir.nome_uid," ",
				d_pr_dir.st_size using "########&"," ",
				d_pr_dir.nome[1,14]
    let  i = i + 1
  end foreach
  let ficheiros.nlinhas = i-1
  call actual_nfich()

end function

function mlinhaArray(modo,rev)
{}
  define modo,rev,i,coltmp smallint,
	 lintmp smallint,
	 dummy,idx smallint,
	 linhad char(40),
	 linhaf char(50)
# MODO 1 Directoria
# MODO 2 Ficheiro
# rev TRUE -> mostra em reverse

  if modo = 1 then
    let dummy = directorias.dimlinha
    let coltmp = col_directoria + 1
    let lintmp =  lin_directoria + directorias.scr_idx 
    if lintmp >= nlin_directoria+lin_directoria-1 then
      return
    end if
    let idx = directorias.arr_idx
    let linhad =directorias.linhas[idx].texto[1,dummy]
    if directorias.linhas[idx].texto is null then
       return
    end if
    if rev then
        display linhad at lintmp,coltmp attribute(reverse)
    else
        display linhad at lintmp,coltmp
    end if
  else
    let dummy = ficheiros.dimlinha
    let coltmp = col_ficheiros + 1
    let lintmp =  lin_ficheiros + ficheiros.scr_idx 
    if lintmp >= nlin_ficheiros+lin_ficheiros-1 then
      return
    end if
    let idx = ficheiros.arr_idx
    let linhaf =ficheiros.linhas[idx].texto[1,dummy]
    if ficheiros.linhas[idx].texto is null then
       return
    end if
    if rev then
      if ficheiros.linhas[idx].marca is not null then
          display "*",linhaf at lintmp,coltmp attribute(reverse)
      else
          display " ",linhaf at lintmp,coltmp attribute(reverse)
      end if
    else
      if ficheiros.linhas[idx].marca is not null then
        display "*",linhaf at lintmp,coltmp
      else
        display " ",linhaf at lintmp,coltmp
      end if
    end if
  end if
end function

function mostraArray(modo)
{}
  define modo,idx,i,coltmp smallint,
	 lintmp smallint,
	 dummy smallint,
	 linhad char(40),
	 linhaf char(50)
# MODO 1 Directoria
# MODO 2 Ficheiro

  if modo = 1 then
    let dummy = directorias.dimlinha
    let coltmp = col_directoria + 1
    for i=1 to nlin_directoria - 2
      let lintmp =  lin_directoria + i
      let idx = i -1 + directorias.arr_idx
      let linhad =directorias.linhas[idx].texto[1,dummy]
      if directorias.linhas[idx].texto is null then
	call espacos(1,lintmp,coltmp)
      else
        display linhad at lintmp,coltmp
      end if
    end for
  else
    let coltmp = col_ficheiros + 1
    let dummy = ficheiros.dimlinha
    for i=1 to nlin_ficheiros - 2
      let lintmp =  lin_ficheiros + i
      let idx = i -1 + ficheiros.arr_idx
      let linhaf = ficheiros.linhas[idx].texto[1,dummy]
      if ficheiros.linhas[idx].texto is null then
	call espacos(2,lintmp,coltmp)
      else
        if ficheiros.linhas[idx].marca is null then
          display " ",linhaf at lintmp,coltmp
        else
          display "*",linhaf at lintmp,coltmp 
        end if
     end if
    end for
  end if
end function

function espacos(modo,linha,coluna)
{}
  define modo,linha,coluna,i smallint
  # Escreve dim espacos
  if modo = 1 then
    display "                                        " at linha,coluna
  else
    display "                                                  " 
    at linha,coluna
  end if
end function

function scrollArray(modo,direccao)
{}
define modo smallint,
       direccao char(4),
       i,inicio,fim,linha,coluna,idx smallint,
	 linhad char(40),
	 linhaf char(50)
# MODO 1 Directoria
# MODO 2 Ficheiro
  if modo = 1 then
    let linha = lin_directoria + 1
    let coluna = col_directoria + 1
    if direccao = "DOWN"  then
      let inicio = directorias.arr_idx - (nlin_directoria - 2) + 1
      let fim =  directorias.arr_idx
    else
      let fim = directorias.arr_idx + (nlin_directoria - 2)  - 1
      let inicio =  directorias.arr_idx 
    end if
  else
    let linha = lin_ficheiros + 1
    let coluna = col_ficheiros + 1
    if direccao = "DOWN"  then
      let inicio = ficheiros.arr_idx - (nlin_ficheiros - 2) + 1
      let fim =  ficheiros.arr_idx
    else
      let fim = ficheiros.arr_idx + (nlin_ficheiros - 2) - 1
      let inicio =  ficheiros.arr_idx
    end if
  end if
  for i=inicio to fim
    if modo = 1 then
      let linhad = directorias.linhas[i].texto[1,40]
      display linhad at linha , coluna
    else
      let linhaf =  ficheiros.linhas[i].texto[1,50]
      if ficheiros.linhas[i].marca is null then
        display " ",linhaf at linha , coluna
      else
        display "*",linhaf at linha , coluna
      end if
    end if
    let linha = linha + 1
  end for

end function

function trata_teclaF(tecla)
{}
define  tecla,i smallint

    
  case
    when tecla = 3002   # F3  primeiro
      if ficheiros.arr_idx = 1 then
	# Ja esta na primeira
	error ""
      else
        let ficheiros.arr_idx = 1
        let ficheiros.scr_idx = 1
        call mostraArray(2)
        call mlinhaArray(2,TRUE)
      end if

      
    when tecla = 3003   # F4  ultimo
      if  ficheiros.arr_idx + (nlin_ficheiros - 2) > ficheiros.nlinhas then
	# Ultima pagina
	error ""
	exit case
      end if
      let ficheiros.scr_idx = 1
      let ficheiros.arr_idx = ficheiros.nlinhas - (ficheiros.nlinhas MOD (nlin_ficheiros - 2)) + 1
      call mostraArray(2)
      call mlinhaArray(2,TRUE)

    when tecla = 62     # >   pagina seguinte
      let i = ficheiros.arr_idx + (nlin_ficheiros - 2)
      if i > ficheiros.nlinhas then
	# Ultima pagina
	error ""
      else
        let ficheiros.scr_idx = 1
        let ficheiros.arr_idx =  i
        call mostraArray(2)
        call mlinhaArray(2,TRUE)
      end if

    when tecla = 60     # <   pagina anterior
      let i = ficheiros.arr_idx - (nlin_ficheiros - 2)
      if i <= 0 then
	# primeira pagina
	error ""
      else
        let ficheiros.scr_idx = 1
        let ficheiros.arr_idx =  i
        call mostraArray(2)
        call mlinhaArray(2,TRUE)
      end if

    otherwise
      error ""
  end case
end function

function trata_teclaD(tecla)
{}
  define tecla,i smallint
  case
    when tecla = 3002   # F3  primeiro
      if directorias.arr_idx = 1 then
	# Ja esta na primeira
	error ""
      else
        let directorias.arr_idx = 1
        let directorias.scr_idx = 1
        call mostraArray(1)
        call mlinhaArray(1,TRUE)
      end if

      
    when tecla = 3003   # F4  ultimo
      if  directorias.arr_idx + (nlin_directoria - 2) > directorias.nlinhas then
	# Ultima pagina
	error ""
	exit case
      end if
      let directorias.scr_idx = 1
      let directorias.arr_idx = directorias.nlinhas - (directorias.nlinhas MOD (nlin_directoria - 2)) + 1
      call mostraArray(1)
      call mlinhaArray(1,TRUE)

    when tecla = 62     # >   pagina seguinte
      let i = directorias.arr_idx + (nlin_directoria - 2)
      if i > directorias.nlinhas then
	# Ultima pagina
	error ""
      else
        let directorias.scr_idx = 1
        let directorias.arr_idx =  i
        call mostraArray(1)
        call mlinhaArray(1,TRUE)
      end if

    when tecla = 60     # <   pagina anterior
      let i = directorias.arr_idx - (nlin_directoria - 2)
      if i <= 0 then
	# primeira pagina
	error ""
      else
        let directorias.scr_idx = 1
        let directorias.arr_idx =  i
        call mostraArray(1)
        call mlinhaArray(1,TRUE)
      end if

    otherwise
      error ""
  end case
end function



function edita_char(texto,dimtexto,linha,coluna,nlinha,ncoluna)
# Devolve um texto alterado/novo
{}
define texto char(512),           # Texto a alterar/inserir
       dimtexto smallint,         # Dimensao do texto
       linha smallint,            # linha  
       coluna smallint,           # coluna
       nlinha smallint,           # nº de linhas
       ncoluna smallint           # nº de colunas
define lin,col  smallint,          # Linha e coluna corrente
       buftexto char(512),
       caracter char(1),
       idx  smallint,              # Índice no array
       i,tecla smallint

let buftexto = texto
let lin = linha
let col = coluna
let idx = 1
let caracter = texto[idx]
display caracter at lin,col

while true
    let tecla = getkey()
    case 
      when tecla >= 32 and tecla <= 255     #texto
	let  buftexto[idx] = tecla
	let idx = idx + 1
      when tecla = 27
	exit while
    end case
  end while
  for i=idx to dimtexto
    let buftexto[i] = ' '
  end for 
  return buftexto[1,dimtexto]
end function
