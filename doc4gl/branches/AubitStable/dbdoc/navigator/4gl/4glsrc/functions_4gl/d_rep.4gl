


#  ============================================================================
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#
#  Divisao de desenvolvimento e producao de software.
#
#  Autor: sergio
#
#  Data de criacao: Mon Jan 18 10:40:20 LISBOA 1993
#
#   This Module contains Proprietary and Confidential
#   Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      :  Funcao geradora e gestora automatica de reports.
#  ---------------------------------------------------------------------------
#  DESCRICAO:  Trata de fazer as contas das colunas (do report) onde vao
#              cair as colunas (da tabela).
#
#  ---------------------------------------------------------------------------
#  FUNCOES:
#
#  ---------------------------------------------------------------------------
#  FORMS:
#
#  REPORTS:
#
#  NOTAS: Falta ver bem valores a null. e tamanho de strings
#         Falta gestao dos erros de sintaxe devidos a burrice de utilizadores.
#         Podera ser necessario arranjar uma funcao de arredondamentos
#       com strings
#         Falta poder abortar a meio do query.
#         Falta poder trablahr com sinonimos indo ver os tamanhos
#         Falta ir ao upscol ver o formato deste
#         Faltam meter os intervalos e ver se os date-times funcionam.
#         Falta optimizar e emagrecer o codigo.
#         Campo nao existente da estouranco.
#         Falta postscript.
#         Falta output to folha de calculo.
#         Tem de validar a ordem de chamada das funcoes.
#         No caso dos geds sei o total do contador, posso recebe-lo
#  Porting para versoes antigas: Tirar free(s).
#
#  ============================================================================

#database despodata
database sysmaster

globals "4glsrc/functions_4gl/d_libglob.4gl"

define
   y array[20] of char(80),      # Array para onde vao ser lidos os dados.
   drep_def array[20] of record  # Array de descritores de campos
      tipo        smallint,      # Tipo, de acordo com Informix.
      tamanho     smallint,      # Tamanho que ele vai ocupar em caracteres.
      formato     char(25),      # String com formato (sobretudo p/numericos)
      coluna      smallint,      # Coluna relativa em que vai ficar.
		totalizacao char(1),       # Este campo tem ou nao totalizacao (S/N).
		total_de   decimal(32,16),          # Campo utilizado para totalizacoes.
      nome       char(80),       # Nome a aparecer no header
		col        char(30),       # Nome da coluna. A null se nao for coluna.
		marcado    char(1),        # Este campo foi marcado.
      tabela     char(19)        # Tabela a que ele pertence
   end record,
   rep_str        char(250),     # String onde vai ficar cada linha a escrever.
   titulo         char(250),     # String para titulo (?)
   drep_head array[10] of char(250),
	d_header array[5] of record
		texto        char(250),   # Texto a aparecer no header.
		risco        char(250),   # Risco que aparece.
		linha_depois char(1),     # Flag que indica se tem risco a linha seguinte.
		bold         char(1),     # Indica se e para ficar em bold.
		font         char(1),     # Indica o font utilizado.
		comprometido char(1),     # Indica se esta comprometido com os campos.
		agrupamento  char(20)     # String com os agrupamentos.
	end record,
	idx_head       smallint,     # Numero de header(s)
   drep_tail      char(250),    # String onde fica o page trailer
   fld_pointer    smallint,     # Numero de campos existente
   col_curr       smallint,     # Coluna corrente.
   n_linhas       integer,     # Numero de linhas da tabela. Para d_count
   rep_fl_nm   char(64),        # String onde fica o nome do ficheiro de escrita
   str_fields char(512),        # Campos a ler, para select.
	#tam         smallint,
	str_report  char(100),
   ncolunas    smallint,     # Numero de campos existentes
	max_len     smallint,     # Tamanho maximo das linhas.
	tipo_papel  char(3),      # Tipo de papel: 8IN-8,5 in ; LAR-14,5 in
	tipo_font   smallint,     # Tipo de font: 10 cpi;12 cpi;17 cpi
	tam_risco   smallint,     # Tamanho do risco que fica em cima e em baixo.
	coluna_curr smallint,
	drep_formato smallint,    # Formato da listagem 1- normal 2-F.Calculo 3-EPS
	d_separador  char(1),
	skip_to_top_of_page smallint, # Indica que vai mudar para pagina seguinte.
	tipo_tail    smallint,    # 1 - pagina do lado esquerdo
	pid          char(5),
	temp_traco   char(80),    # Traco de um campo.
	risco_horiz  char(230),    # String onde sera escrito um traco separador.
	existe_total smallint,    # Indica se existe algum campo totalizador.
	tipo_pag     char(1),     # Tipo de pagina "-" <-> "-1-" else "Pagina 1"
	ask_format   char(1),     # Indica se deve ou nao pedir o formato. P def Nao
	pag_str      char(250),
	str_merda    char(100),
   str_sel      char(1024)   # String onde vai ficar o select preparado.

  define fontAutomatica smallint



#  ============================================================================ 
#  Faz as inicializacoes necessarias a utilizacao de drep.
#  ============================================================================ 
function     d_start_drep()
{}

	let d_separador="	"
	let ask_format   = "N"
	let ncolunas     = 0
	let pid          = d_getpid()
   let drep_head[1] = null
   let drep_head[2] = null
   let drep_head[3] = null
   let drep_head[4] = null
   let drep_head[5] = null
   let drep_head[6] = null
   let drep_head[7] = null
   let drep_head[8] = null
   let drep_head[9] = null
   let drep_head[10] = null
	let tipo_tail = 1
	let tipo_pag  = "-"
end function


#  ============================================================================ 
#  Activa a flag que faz com que obrigue  aperguntar o formato.
#  ============================================================================ 
function 	 d_rep_must_ask()
{}
   let ask_format = "S"
end function

#  ============================================================================ 
#  Indaga os utilizadores sobre que formato de output deve gerar.
#  Meter em funcao a parte que possa ser utilizada noutra altura.
#  So devera perguntar se necessario. Preencher tabelas de controlo.
#  ============================================================================ 
function 	 drep_ask_formato()
{}
	define ans smallint
	let ans = d_dialog(9,15,"Normal","F.Calculo","","","Qual o formato da","",
												  "listagem a gerar","?","")
   case
		when ans = 1
			let drep_formato = 1
		when ans = 2
			let drep_formato = 2
		otherwise
			let drep_formato = 1
	end case
end function


#  ============================================================================ 
#  Versao 2 da funcao que permite adicionar um novo campo.
#  Ja trabalha com mais uns atributos, nomeadamente com indicacao de ser ter 
#  totalizacao e frase a meter na linha de totalizacao.
#  Tem de poder nao estar associado a nenhuma coluna e tabela.
#  Tirar tabela temporaria.
#  ============================================================================ 
function 	 d_rep_novo_campo(nome,coluna,tabela,formato,tipo,tamanho_campo,
										totalizacao,frase_totalizacao)
{}
   define
      nome    char(80),
      coluna  char(25),
      tabela  char(19),
      formato char(25),
      tipo    smallint,
		tamanho_campo smallint,
		totalizacao char(1),
		frase_totalizacao char(20),
      tamanho smallint

  whenever error call d_erro

  if totalizacao is null then
	  let totalizacao = "N"
	end if
  if tipo is null then
     declare cr_type cursor for
        select coltype, collength
           into tipo, tamanho
           from syscolumns, systables
           where syscolumns.tabid = systables.tabid and
              systables.tabname = tabela and
              syscolumns.colname = coluna
     open cr_type
     fetch cr_type into tipo, tamanho
     close cr_type 
	  
	  # Ajustamento do tamanho
	  case
	     when tipo = 266 or tipo = 10 
		     let tamanho = 22
		  when tipo != 0 and tipo != 256
			  let tamanho = null
	  end case
	  { Isto aqui esta graneloso. Limpar!
  else
     declare cr_type2 cursor for
        select collength
           into tamanho
           from syscolumns, systables
           where syscolumns.tabid = systables.tabid and
              systables.tabname = tabela and
              syscolumns.colname = coluna
     open  cr_type2
     fetch cr_type2 into tamanho
     close cr_type2 
	  
	  if tipo = 266 or tipo = 10 then
		  let tamanho = 22
	  end if
	  }
  else
	  # Tem de se tentar ir ver tamanho se este estiver a null.
	  let tamanho = tamanho_campo
  end if

	{** @todo : Tratar de calcular o tamanho como deve de ser *}
	if tamanho is null or tamanho = 0 then
	  let tamanho = 6
  end if

   let ncolunas                       = ncolunas + 1
   let drep_def[ncolunas].tipo        = tipo
   let drep_def[ncolunas].tamanho     = tamanho
   let drep_def[ncolunas].formato     = formato
   #let drep_def[ncolunas].coluna      = coluna
   let drep_def[ncolunas].totalizacao = totalizacao
	let drep_def[ncolunas].total_de    = 0
	let drep_def[ncolunas].nome        = nome
	let drep_def[ncolunas].col         = coluna
	let drep_def[ncolunas].tabela      = tabela
	let drep_def[ncolunas].marcado     = "S"
end function

#  ============================================================================ 
#  Permite adicicionar um novo campo a drep.
#  Se tipo vier a null vai tentar ver ao syscolumns.
#  Se formato vier a null vai tenter ver a upscol, ou tentar pelo tipo.
#  ============================================================================ 
function     d_campo_drep(nome,coluna,tabela,formato,tipo)
{}
   define
      nome    char(80),
      coluna  char(25),
      tabela  char(19),
      formato char(25),
      tipo    smallint

   call d_rep_novo_campo(nome,coluna,tabela,formato,tipo,"","N","")
end function

#  ============================================================================ 
#  Faz um report, recebendo como parametros as clausulas de um select.
#  Declara um cursor, prepara a instrucao, abre o cursor, chama o report,
#  chama o dmostra, remove o ficheiro.
#  Devolve false, se nao existirem linhas.
#  ============================================================================ 
function     d_rep(tit,str_tabelas,str_where,str_order)
{}
	define
      tit         char(250),
      str_tabelas char(64),
      str_where   char(512),
      str_order   char(64),
      linhas_lidas smallint,
      ans,idx     smallint
   
   whenever error call d_erro

	if ask_format = "S" then
	   call drep_ask_formato()
	end if
	# Titulos. Ver isto com headers.
   call drep_init_tipos(3)
   call drep_novo_header(1,tit,"N","N","","N","")
   call drep_formata_header(1)
   call drep_novo_header(2,"","N","N","","N","")
   call drep_formata_header(2)
   call drep_novo_header(3,"","S","N","","S","")
   call drep_formata_header(3)
   call drep_format_headers(4)

   let str_sel = "select count(*) from ", 
                 str_tabelas clipped, " where ", 
                 str_where clipped

	prepare stat_count from str_sel
   declare cr_count cursor for stat_count
   open  cr_count 
   fetch cr_count into n_linhas
   close cr_count
	
   if n_linhas <= 0 or n_linhas is null or status = notfound then
      call d_dialogOk(9,15,"","Listagem pedida",
                              "nao tem dados","para parametros escolhidos",
                              "!","")
      return false
   end if
   # Verificar se a coluna pela qual vai ordenar nao foi selecionada
   for idx=1 to ncolunas
	  if drep_def[idx].col = str_order then
		  exit for
	  end if
	end for


   let str_sel = "select ", str_fields clipped, " from ", 
                 str_tabelas clipped, " where ", 
                 str_where clipped
  if drep_def[idx].marcado = "S" then
	  let str_sel = str_sel clipped, " order by ", str_order clipped
  end if
   prepare stat_drep from str_sel
   declare cr_drep cursor for stat_drep


   let rep_fl_nm = "/tmp/r_", pid clipped
   start report r_drep4 to rep_fl_nm

   call start_count("CONSTRUCAO DA LISTAGEM",9,15,50)
   open cr_drep

   let linhas_lidas = 1
   while (1=1)
      let ans = fetch_cr_drep()
      if not ans then    # Atencao aos resultados
         exit while
      end if
      call st_count("",linhas_lidas,n_linhas,50)
		case
			when  drep_formato = 1
            call drep_put_on_string()
			when  drep_formato = 2
            call drep_put_on_string_fc()
			otherwise
            call drep_put_on_string()
		end case
      output to report r_drep4(1)
      let linhas_lidas = linhas_lidas + 1
   end while

	# Escrever os totais
	call drep_total()

	call d_close_drep(4)
   call stop_count()
	call d_visualiza_drep()

   # whenever error continue  mas porque
   return true
end function


#  ============================================================================ 
#   Escreve os totais deixando uma linha em branco antes.
#  ============================================================================ 
function 	 drep_total()
{}
		if not existe_total then
			return
		end if
		let rep_str = ""
      output to report r_drep4(1)
      call drep_put_tot_on_string()
      output to report r_drep4(1)
end function


#  ============================================================================ 
#  Visualizacao do report em causa.
#  ============================================================================ 
function 	 d_visualiza_drep()
{}
	define
		ans smallint

   call d_mostra(rep_fl_nm)
   let ans = d_unlink(rep_fl_nm)
end function

#  ============================================================================ 
#  Fecha o report.
#  ============================================================================ 
function 	 d_close_drep(report_number)
{}
   define
		report_number smallint

	case
		when  report_number = 3
         finish report r_drep3
		when  report_number = 4
         finish report r_drep4
		when  report_number = 6
         finish report r_drep6
		when  report_number = 8
         finish report r_drep8
		otherwise
         finish report r_drep3
	end case
end function

#  ============================================================================ 
#  Faz as inicializacoes do report.
#  ============================================================================ 
function 	 d_init_drep(report_number)
{}
   define
		report_number smallint

	let fontAutomatica = true
  let col_curr = 1
  let rep_fl_nm = "/tmp/r_", pid clipped 
	case
		when  report_number = 4
         start report r_drep4 to rep_fl_nm
		when  report_number = 6
         start report r_drep6 to rep_fl_nm
		when  report_number = 8
         start report r_drep8 to rep_fl_nm
		otherwise
         start report r_drep3 to rep_fl_nm
	end case
   let skip_to_top_of_page = false
end function

#  ============================================================================ 
#  Insere um novo header na estrutura global de headers.
#  O header id e a ordem do header. Entre 1 e 10.
#  ============================================================================ 
function 	 drep_novo_header(header_id, texto,        c_risco,    bold,
									   font,      comprometido, agrupamento)
{}
   define
		header_id     smallint,
		texto         char(250),
		c_risco       char(1),
		bold          char(1),
		font          char(1),
		comprometido  char(1),
		agrupamento   char(20)

   if header_id > 10 then
		return false
	end if
	if header_id is null or header_id > idx_head then
		let idx_head = header_id
	end if
	let d_header[header_id].texto         = texto
	let d_header[header_id].linha_depois = c_risco
	let d_header[header_id].bold         = bold
	let d_header[header_id].font         = font
	let d_header[header_id].comprometido = comprometido
	let d_header[header_id].agrupamento  = agrupamento
end function


#  ============================================================================ 
#  Adiciona uma nova frase a uma componente do header.
#  ============================================================================ 
function 	 drep_frase_header(header_id,ordem,frase)
{}
   define  
		header_id    smallint,
		ordem        smallint,
		frase        char(160)
   
	if d_header[header_id].comprometido != "S" then
		return false    # Nao e comprometido, ja veio o texto
	end if
	let y[ordem] = frase
end function

#  ============================================================================ 
#  Formata o header do qual se passa o seu identificador.
#  Nao esquecer que strings encosta header a esquerda e numeros a direita.
#  ============================================================================ 
function 	 drep_formata_header(hid)
{}
	define
		hid          smallint,
		fim          smallint,
		str_temp     char(250),
		mtam         smallint,
		i,j          smallint

   if d_header[hid].comprometido != "S" then
		if d_header[hid].linha_depois = "S" then
	      let d_header[hid].risco = replicate ("-",tam_risco)
		end if
		# Meter aqui as sequencias de bolds e fonts.
		return
	end if
	initialize d_header[hid].texto to null
   for i = 1 to ncolunas
		if drep_def[i].marcado!="S" then
		  continue for
		end if
		if d_header[hid].agrupamento is null then
			let fim                 = drep_def[i].coluna
			let mtam                = drep_def[i].tamanho
			if length(y[i]) != 0 then
		      let d_header[hid].texto  = d_header[hid].texto[1,fim], y[i][1,mtam]
				initialize y[i] to null
			else
				let str_temp = get_head(drep_def[i].tipo,drep_def[i].nome,mtam)
		      let d_header[hid].texto  = d_header[hid].texto[1,fim], 
												  str_temp[1,mtam]
												  #drep_def[i].nome[1,mtam]
			end if
			# Isto pode dar erro de allocation de string
         let d_header[hid].risco = d_header[hid].risco[1,fim],
											  replicate("-",drep_def[i].tamanho)
		else
			if i > 1 then
			   if d_header[hid].agrupamento[i] = d_header[hid].agrupamento[i-1]
				then
					let y[i] = null
					continue for
				end if
			end if
			let fim                 = drep_def[i].coluna
			let mtam                = drep_def[i].tamanho
			if d_header[hid].agrupamento[i] != " " and 
				d_header[hid].agrupamento is not null then
				let j = i+1
				while (1=1)
					if d_header[hid].agrupamento[i] != d_header[hid].agrupamento[j] 
						or d_header[hid].agrupamento is null or i > 20
					then
						exit while
					else
			         let mtam = mtam + drep_def[j].tamanho+1
					end if
					let j = j+1
				end while
			end if
			#let y[i] = y[i] clipped 
			if length(y[i]) != 0 then
		      let d_header[hid].texto  = d_header[hid].texto[1,fim], y[i][1,mtam]
            let d_header[hid].risco = d_header[hid].risco[1,fim],
											  replicate("-",mtam)
			end if
		end if
		initialize y[i] to null
	end for
end function



function 	 get_head(tipo,texto,tamanho)
{}
   define
		tipo smallint,
		texto char(80),
		tamanho smallint,
		sitio smallint,
		str_ret char(200)
   
	initialize str_ret to null
	if tamanho is null then
		return  str_ret clipped
	end if

	let texto = texto clipped
	if tipo >= 1 and tipo <= 6 and tipo is not null then
		let sitio = tamanho - length(texto)
		if sitio < 1 then
			let str_ret = texto clipped
		else
		   let str_ret = str_ret[1,sitio], texto clipped
		end if
	else
		let str_ret = texto clipped
	end if
	return str_ret clipped
end function

#  ============================================================================ 
#  Formata as strings de header, de acordo com o definido na estrutura.
#  ============================================================================ 
function 	 drep_format_headers(report_number)
{}
     define
		 report_number smallint,
		 i, j          smallint

		let j = 1
		for i = 1 to idx_head 
			let drep_head[j] = d_header[i].texto
			let j = j+1
			if d_header[i].linha_depois = "S" then
				let drep_head[j] = d_header[i].risco
			   let j = j+1
			end if
		end for
end function


#  ============================================================================ 
#  Nanda com o caracas os recursos utlizados por drep
#  ============================================================================ 
function     d_end_drep()
{}
	define 
		i smallint

   for i = 1 to 20
    initialize drep_def[i].* to null
	 initialize y[i] to null
    let drep_def[i].total_de = 0
	end for
end function



#  ============================================================================ 
#  Da proxima vez que passar pelo report faz skip to top of page.
#  ============================================================================ 
function 	 drep_skip_top()
{}
   let skip_to_top_of_page = true
end function

#  ============================================================================ 
#  Report driver para o report definido
#  ============================================================================ 
function 	 d_rd_drep(str_linha,report_number)
{}
   define
		str_linha char(250),
		report_number smallint

	case
		when  report_number = 4
         output to report r_drep4(str_linha)
		when  report_number = 6
         output to report r_drep6(str_linha)
		when  report_number = 8
         output to report r_drep8(str_linha)
		otherwise
			let rep_str = str_linha
         output to report r_drep3(1)
	end case

end function


#  ============================================================================ 
#  Inicializa os tipos das colunas que se utilizam no report
#  Mete as colunas onde vai cair o campo. As contas sao feitas aqui.
#  ============================================================================ 
function     drep_init_tipos(report_number)
{}
   define 
		report_number smallint,
      coluna        smallint,
		i,aux         smallint

	initialize str_fields to null  # se calhar meter na funcao de inicializacao
	for i = 1 to ncolunas
		if drep_def[i].marcado != "S" then
			continue for
		end if

      if drep_def[i].tipo >= 256 then
         LET drep_def[i].tipo=drep_def[i].tipo-256
      end if

      case
         WHEN  drep_def[i].tipo = 0
            if drep_def[i].tamanho < length(drep_def[i].nome) then
               let drep_def[i].tamanho = length(drep_def[i].nome)
            end if
         WHEN  drep_def[i].tipo = 1  # Smallint
				if drep_def[i].tamanho is null then
               let drep_def[i].tamanho = 5
				end if
            if drep_def[i].tamanho < length(drep_def[i].nome) then
               let drep_def[i].tamanho = length(drep_def[i].nome)
            end if
				# Ver isto bem
				if drep_def[i].formato is null then
               let drep_def[i].formato = "#####"
				end if
            if drep_def[i].tamanho > 5 then
               let drep_def[i].formato = replicate("#",drep_def[i].tamanho)
            end if
         WHEN  drep_def[i].tipo = 2  # Integer
				if drep_def[i].tamanho is null then
               let drep_def[i].tamanho = 7
				end if
            if drep_def[i].tamanho < length(drep_def[i].nome) then
               let drep_def[i].tamanho = length(drep_def[i].nome)
            end if
				if drep_def[i].formato is null then
               let drep_def[i].formato = "#######"
				end if
            if drep_def[i].tamanho > 7 then
               let drep_def[i].formato = replicate("#",drep_def[i].tamanho)
            end if
         WHEN  drep_def[i].tipo = 3  # Float. Meter a ir buscar formatos default, etc.
				if drep_def[i].tamanho is null then
               let drep_def[i].tamanho = 12
				end if
            if drep_def[i].tamanho < length(drep_def[i].nome) then
               let drep_def[i].tamanho = length(drep_def[i].nome)
            end if
				if drep_def[i].formato is null then
               let drep_def[i].formato = "#,###,###.###"
				end if
            if drep_def[i].tamanho < length(drep_def[i].formato) then
               let drep_def[i].tamanho = length(drep_def[i].formato)
            end if
         WHEN  drep_def[i].tipo = 4  # Smallfloat.
				if drep_def[i].tamanho is null then
               let drep_def[i].tamanho = 12
				end if
            if drep_def[i].tamanho < length(drep_def[i].nome) then
               let drep_def[i].tamanho = length(drep_def[i].nome)
            end if
				if drep_def[i].formato is null then
               let drep_def[i].formato = "#,###,###.###"
				end if
            if drep_def[i].tamanho < length(drep_def[i].formato) then
               let drep_def[i].tamanho = length(drep_def[i].formato)
            end if
         WHEN  drep_def[i].tipo = 5  # Decimal.
				if drep_def[i].tamanho is null then
               let drep_def[i].tamanho = 12
				end if
				if drep_def[i].formato is null then
               let drep_def[i].formato = "#,###,###.###"
				end if
         WHEN  drep_def[i].tipo = 6 # Serial
				if drep_def[i].tamanho is null then
               let drep_def[i].tamanho = 7
				end if
            if drep_def[i].tamanho < length(drep_def[i].nome) then
               let drep_def[i].tamanho = length(drep_def[i].nome)
            end if
            #if drep_def[i].tamanho > 7 then
				    if drep_def[i].formato is null then
               #let drep_def[i].formato = replicate("#",drep_def[i].tamanho)
               let drep_def[i].formato = replicate("#",7)
            end if
         WHEN  drep_def[i].tipo = 7  # Date
				if drep_def[i].tamanho is null then
               let drep_def[i].tamanho = 10
				end if
            if drep_def[i].tamanho < length(drep_def[i].nome) then
               let drep_def[i].tamanho = length(drep_def[i].nome)
            end if
            if drep_def[i].tamanho < 8 then
               let drep_def[i].tamanho = 10
            end if
         #WHEN  drep_def[i].tipo = 8 # Money 
            #PRINT "money     ";
         #WHEN  drep_def[i].tipo = 9
            #PRINT "Invalido  ";
         WHEN  drep_def[i].tipo = 10
            let drep_def[i].tamanho = 22
            #let drep_def[i].tamanho = cnvrt_dt()
         #WHEN  drep_def[i].tipo = 11 #Byte
            #PRINT "invalido  ";
         #WHEN  drep_def[i].tipo = 12 #Text
            #PRINT "invalido  ";
         ##WHEN  drep_def[i].tipo = 13 # varchar
            #PRINT "invalido  ";
         #WHEN  drep_def[i].tipo = 14   # Interval
            #PRINT "interval  ";
            #let drep_def[i].tamanho = cnvrt_intvl()
      END CASE
		if drep_def[i].totalizacao = "S" then
			let existe_total = true
		end if
      if i > 1 then
			# Ver as marcacoes
			let aux = i-1
			while (aux != 0 ) 
			  if drep_def[aux].marcado  = "S" then
				 exit while
			  end if
			  let aux = aux - 1
			end while
         #let drep_def[i].coluna = drep_def[i-1].coluna+drep_def[i-1].tamanho+1
			if aux = 0 then
           let drep_def[i].coluna  = 1
			else
           let drep_def[i].coluna = drep_def[aux].coluna+drep_def[aux].tamanho+1
			end if
      else
         let drep_def[i].coluna  = 1
      end if

		# BUG QUANDO NAO HA MARCACAO
		if i > 1 then
			if str_fields is not null then
           let str_fields = str_fields clipped, ", "
			end if
		end if
		if drep_def[i].tabela is null then
         let str_fields = str_fields clipped,
								drep_def[i].col clipped
		else
         let str_fields = str_fields clipped,
                          drep_def[i].tabela clipped, ".", 
								  drep_def[i].col clipped
		end if
   end for
	let aux = i -1
	while (aux != 0 )
	   if drep_def[aux].marcado  = "S" then
		  exit while
		end if
		let aux = aux - 1
   end while
   if aux = 0 then
	  let max_len = 0
   else
     let max_len = drep_def[aux].coluna+drep_def[aux].tamanho
	end if
     #let max_len = drep_def[i-1].coluna+drep_def[i-1].tamanho


	call escolhe_papel()
	let risco_horiz = replicate ("-",tam_risco)   # So para trailer(s).
end function


#  ============================================================================ 
#  Toma decisoes relativamente ao tipo de papel e fonts utilizados.
#  ============================================================================ 
function 	 escolhe_papel()
{}
	case 
		when max_len <= 85
			let tipo_papel = "8IN"
			let tipo_font  = 10
			let tam_risco  = 84
		when max_len > 85 and max_len <= 105
			let tipo_papel = "8IN"
			let tipo_font  = 12
			let tam_risco  = 105
		when max_len > 105 and max_len <= 144
			let tipo_papel = "8IN"
		let tipo_font  = 17
			let tam_risco  = 144
		when max_len > 144 and max_len <= 145
			let tipo_papel = "LAR"
			let tipo_font  = 10
			let tam_risco  = 145
		when max_len > 145 and max_len <= 162
			let tipo_papel = "LAR"
			let tipo_font  = 12
			let tam_risco  = 162
		when max_len > 162 and max_len <= 276
			let tipo_papel = "LAR"
			let tipo_font  = 17
			let tam_risco  = 233
		otherwise
			let tipo_papel = "LAR"
			let tipo_font  = 17
			let tam_risco  = 233
	end case
end function

#  ============================================================================ 
#  Converte o tamanho da coluna de uma campo interval em keywords 
#  qualificadoras (year, month, etc).
#  ============================================================================ 
function     cnvrt_intvl(clngth)
{}
   define
      clngth smallint,
      large_fld char(11),
      small_fld char(11),
      dt_size char(35),  # Por isso e que nao funciona. Mete a string e nao o 
								 # o tamanho
      hex_length char(4),
      null_size smallint
   
   let hex_length = to_hex(clngth, 4)

   CALL qual_fld("l", hex_length[3])
      returning large_fld,null_size

   CALL qual_fld("s", hex_length[4])
       returning small_fld, null_size

   LET dt_size = large_fld CLIPPED, " to ", small_fld CLIPPED
       RETURN (dt_size CLIPPED)
end function

#  ============================================================================ 
#  Converte o tamanho da coluna de uma campo datetima em keywords em ascii
#  year, month, etc
#  ============================================================================ 
function     cnvrt_dt(clngth)
{}
   define
      clngth smallint,
      large_fld char(11),
      small_fld char(11),
      dt_size char(35),
      hex_length char(4),
      null_size smallint
   
   let hex_length = to_hex(clngth, 4)

   CALL qual_fld("l", hex_length[3])
      returning large_fld,null_size

   CALL qual_fld("s", hex_length[4])
       returning small_fld, null_size

   LET dt_size = large_fld CLIPPED, " to ", small_fld CLIPPED
       RETURN (dt_size CLIPPED)

end function


#  ============================================================================ 
#  Converte um numero em decimal numa string com representacao em Hexa do
#  numero.
#  ============================================================================ 
function to_hex(dec_number, mypower)
{}
DEFINE  dec_number    INTEGER,
        mypower         SMALLINT,
        the_num       INTEGER,
        i,j           SMALLINT,
        hex_power     INTEGER,
        hex_number    CHAR(4)

LET the_num = dec_number
IF the_num < 0 THEN
   LET the_num = 65536 + the_num
END IF

LET hex_power = 16 ** mypower
LET  hex_number = "0000"

FOR i = 1 TO mypower
   IF the_num = 0 THEN
       EXIT FOR
   END IF

   LET hex_power = hex_power / 16
   IF the_num >= hex_power THEN
      LET hex_number[i] = hex_digit(the_num / hex_power)
      LET the_num = the_num MOD hex_power
   END IF
END FOR
RETURN (hex_number[1,mypower])
end function


#  ============================================================================ 
#  Converte um digito Hexa na keyowrd qualificadora (year,month, etc)
#  ============================================================================ 
function    qual_fld(ftype, fvalue)
{}
DEFINE
      ftype, fvalue       CHAR(1),
      fld_name            CHAR(11),
      fld_size            SMALLINT


CASE
   WHEN (fvalue = "0")
     LET fld_name = "YEAR"
     LET fld_size = 4

   WHEN (fvalue = "2")
     LET fld_name = "MONTH"
     LET fld_size = 2

   WHEN (fvalue = "4")
     LET fld_name = "DAY"
     LET fld_size = 2

   WHEN (fvalue = "6")
     LET fld_name = "HOUR"
     LET fld_size = 2

   WHEN (fvalue = "8")
     LET fld_name = "MINUTE"
     LET fld_size = 2

   WHEN (fvalue MATCHES "[Aa]")
     LET fld_name = "SECOND"
     LET fld_size = 2

   WHEN (fvalue MATCHES "[Bb]")
     LET fld_name = "FRACTION(1)"
     LET fld_size = 1

   WHEN (fvalue MATCHES "[Cc]")
     LET fld_size = 2
     IF ftype = "l" then
       LET fld_name = "FRACTION"
     ELSE
       LET fld_name = "FRACTION(2)"
     END IF

   WHEN (fvalue MATCHES "[Dd]")
     LET fld_name = "FRACTION"
     LET fld_size = 3

   WHEN (fvalue MATCHES "[Ee]")
     LET fld_name = "FRACTION(4)"
     LET fld_size = 4

   WHEN (fvalue MATCHES "[Ff]")
     LET fld_name = "FRACTION(5)"
     LET fld_size = 5

   OTHERWISE
     LET fld_name = "uh oh:", fvalue
     LET fld_size = 0

END CASE

RETURN fld_name clipped, fld_size clipped

end function

#  ============================================================================ 
#  Converte um digito em decimal no correspobdente em Hexa.
#  ============================================================================ 
function     hex_digit(dec_num)

DEFINE  dec_num   SMALLINT,
        hex_char  CHAR(1)



CASE
   WHEN  dec_num = 10
       LET hex_char = "A"
   WHEN dec_num = 11
       LET hex_char = "B"
   WHEN dec_num = 12
       LET hex_char = "C"
   WHEN dec_num = 13
       LET hex_char = "D"
   WHEN dec_num = 14
       LET hex_char = "E"
   WHEN dec_num = 15
       LET hex_char = "F"
   OTHERWISE
       LET hex_char = dec_num
END CASE

RETURN hex_char
end function


#  ============================================================================ 
#  Faz o fetch next consoante o numero de colunas.
#  Esta funcao esta porreira. Limpinha.
#  Podia ser utilizada a meias entra a lov e o d_rep.
#  No maximo 20 colunas.
#  ============================================================================ 
function     fetch_cr_drep()
{}

   case
      when ncolunas = 1
         fetch next cr_drep into y[1]
      when ncolunas = 2
         fetch next cr_drep into y[1], y[2]
      when ncolunas = 3
         fetch next cr_drep into y[1], y[2], y[3]
      when ncolunas = 4
         fetch next cr_drep into y[1], y[2], y[3], y[4]
      when ncolunas = 5
         fetch next cr_drep into y[1], y[2], y[3], y[4], y[5]
      when ncolunas = 6
         fetch next cr_drep into y[1], y[2], y[3], y[4], y[5],
                                 y[6]
      when ncolunas = 7
         fetch next cr_drep into y[1], y[2], y[3], y[4], y[5],
                                 y[6], y[7]
      when ncolunas = 8
         fetch next cr_drep into y[1], y[2], y[3], y[4], y[5],
                                 y[6], y[7], y[8]
      when ncolunas = 9
         fetch next cr_drep into y[1], y[2], y[3], y[4], y[5],
                                 y[6], y[7], y[8], y[9]
      when ncolunas = 10
         fetch next cr_drep into y[1], y[2], y[3], y[4], y[5],
                                 y[6], y[7], y[8], y[9], y[10]
      when ncolunas = 11
         fetch next cr_drep into y[1], y[2], y[3], y[4], y[5],
                                 y[6], y[7], y[8], y[9], y[10], 
                                 y[11]
      when ncolunas = 12
         fetch next cr_drep into y[1], y[2], y[3], y[4], y[5],
                                 y[6], y[7], y[8], y[9], y[10], 
                                 y[11], y[12]
      when ncolunas = 13
         fetch next cr_drep into y[1], y[2], y[3], y[4], y[5],
                                 y[6], y[7], y[8], y[9], y[10], 
                                 y[11], y[12], y[13]
      when ncolunas = 14
         fetch next cr_drep into y[1], y[2], y[3], y[4], y[5],
                                 y[6], y[7], y[8], y[9], y[10], 
                                 y[11], y[12], y[13], y[14]
      when ncolunas = 15
         fetch next cr_drep into y[1], y[2], y[3], y[4], y[5],
                                 y[6], y[7], y[8], y[9], y[10], 
                                 y[11], y[12], y[13], y[14], y[15]
      when ncolunas = 16
         fetch next cr_drep into y[1], y[2], y[3], y[4], y[5],
                                 y[6], y[7], y[8], y[9], y[10], 
                                 y[11], y[12], y[13], y[14], y[15], 
                                 y[16]
      when ncolunas = 17
         fetch next cr_drep into y[1], y[2], y[3], y[4], y[5],
                                 y[6], y[7], y[8], y[9], y[10], 
                                 y[11], y[12], y[13], y[14], y[15], 
                                 y[16], y[17]
      when ncolunas = 18
         fetch next cr_drep into y[1], y[2], y[3], y[4], y[5],
                                 y[6], y[7], y[8], y[9], y[10], 
                                 y[11], y[12], y[13], y[14], y[15], 
                                 y[16], y[17], y[18]
      when ncolunas = 19
         fetch next cr_drep into y[1], y[2], y[3], y[4], y[5],
                                 y[6], y[7], y[8], y[9], y[10], 
                                 y[11], y[12], y[13], y[14], y[15], 
                                 y[16], y[17], y[18], y[19]
      when ncolunas = 20
         fetch next cr_drep into y[1], y[2], y[3], y[4], y[5],
                                 y[6], y[7], y[8], y[9], y[10], 
                                 y[11], y[12], y[13], y[14], y[15], 
                                 y[16], y[17], y[18], y[19], y[20]
      otherwise
         error "Atingido numero maximo de colunas"
   end case
   if status = 0 then
      return true
   else
      return false
   end if
end function



#  ============================================================================ 
#  Mete os campos todos numa string de acordo com o formato de folhas de 
#  calculo.
#  Faz as contas de totalizacao, se necessario.
#  ============================================================================ 
function     drep_put_on_string_fc()
{}
   define
		temp_str     char(80),
      i,aux        smallint,
		tottemp      decimal(32,16)
   
   initialize rep_str to null

	let aux = 1
   let col_curr = 1
   for i = 1 to ncolunas
		if drep_def[i].marcado = 'N' then
		  continue for
		end if
		let temp_str = d_sstrip(y[aux])
		let rep_str = rep_str clipped, d_separador, temp_str clipped

		if drep_def[i].totalizacao = "S" then
			#let y[aux] = y[aux] clipped 
			if length(y[aux]) != 0 then
			   let tottemp = y[aux]
			   let drep_def[i].total_de = drep_def[i].total_de + tottemp
			end if
		end if
		let aux = aux + 1
   end for 
end function


#  ============================================================================ 
#  Mete os campos todos numa string fazendo arranjando determinado formato para
#  o fazer.
#  Faz as contas de totalizacao, se necessario.
#  ============================================================================ 
function     drep_put_on_string()
{}
   define
		col          smallint,
		mtam         smallint,
      i,aux        smallint
   
   initialize rep_str to null

	let aux = 1
   let col_curr = 1
   for i = 1 to ncolunas
		if drep_def[i].marcado = "N" then
		  continue for
		end if
		let coluna_curr = aux
      call drep_formata_coluna(drep_def[i].tipo,
										 drep_def[i].formato,
                               drep_def[i].tamanho)
      if i > 1 then
			let col = drep_def[i].coluna
			let mtam    = drep_def[i].tamanho
         let rep_str = rep_str[1,col], 
							  str_report[1,mtam]
      else
		   let mtam = drep_def[i].tamanho	
         let rep_str = " ", str_report[1,mtam]
      end if

      let col_curr = col_curr + drep_def[i].tamanho + 1 # Para que

		if drep_def[i].totalizacao = "S" then
			#let y[aux] = y[aux] clipped 
			if length(y[i]) != 0 then
			   let drep_def[i].total_de = drep_def[i].total_de + y[aux]
			end if
		end if
		let aux = aux+1
   end for 
end function

#  ============================================================================ 
#  Escreve um campo na string. recebe a sua ordem no array e o valor em string.
#  Ver se da para fazer merge da funcao em cima com esta.
#  ============================================================================ 
function 	 drep_write_campo(valor,ordem)
{}
   define
		valor char(100),
		ordem smallint

   case
		when  drep_formato = 1
         call drep_write_camponorm(valor,ordem)
		when  drep_formato = 2
         call drep_write_campo_fc(valor,ordem)
		otherwise
         call drep_write_camponorm(valor,ordem)
	end case
end function

function 	 drep_write_camponorm(valor,ordem)
{}
   define
		valor char(100),
		ordem smallint,
		mtam  smallint

	let coluna_curr = ordem
	let y[ordem]    = valor
   call drep_formata_coluna(drep_def[ordem].tipo,
									 drep_def[ordem].formato,
                            drep_def[ordem].tamanho)
	let mtam = drep_def[coluna_curr].tamanho
   if col_curr > 1 then
      let rep_str = rep_str[1,col_curr], str_report[1,mtam]
   else
      let rep_str = " ", str_report[1,mtam]
   end if

	# Sera so para gastar tempo e recursos.
   let col_curr = col_curr + drep_def[ordem].tamanho + 1

	if drep_def[ordem].totalizacao = "S" then
		if y[ordem] is not null then
		   let drep_def[ordem].total_de=drep_def[ordem].total_de + y[ordem]
		end if
	end if
end function


function 	 drep_write_campo_fc(valor,ordem)
{}
   define
		valor    char(100),
		ordem    smallint,
		mtam     smallint,
		str_temp char(80)

	let str_temp = d_sstrip(valor)
	if ordem > 1 then
	   let rep_str = rep_str clipped, d_separador, str_temp clipped
	else
	   let rep_str = str_temp clipped
	end if
end function

#  ============================================================================ 
#  Escreve a linha tal como esta no ficheiro e espera outra.
#  ============================================================================ 
function 	 drep_despeja_linha(report_number)
{}
   define
		report_number smallint

   call d_rd_drep(rep_str,report_number)
   let col_curr = 1
end function

#  ============================================================================ 
#  Mete os totais todos numa string fazendo arranjando determinado formato para
#  o fazer.
#  Faz as contas de totalizacao, se necessario.
#  ============================================================================ 
function     drep_put_tot_on_string()
{}
   define
		col          smallint,
		mtam         smallint,
      i            smallint
   
   initialize rep_str to null

   for i = 1 to ncolunas
		let  coluna_curr = i
      call drep_formata_tot_coluna(drep_def[i].tipo,
											  drep_def[i].formato,
                                   drep_def[i].tamanho)
      if i > 1 then
         let col     = drep_def[i].coluna
         let mtam    = drep_def[i].tamanho
         let rep_str = rep_str[1,col], 
							  str_report[1,mtam]
      else
         let mtam    = drep_def[i].tamanho
         let rep_str = " ", str_report[1,mtam]
      end if
		if drep_def[i].totalizacao = "S" then
			#let y[i] = y[i] clipped 
			if length(y[i]) != 0 then
			   let drep_def[i].total_de = drep_def[i].total_de+y[i]
			end if
		end if
   end for 
end function



#  ============================================================================ 
#  Formata a coluna corrente, recebendo o tipo. Se tipo a null mete 
#  directamente.
#  ============================================================================ 
function     drep_format_column(valor,tipo,formato,tamanho)
{}
   define
      valor      char(80),
		tipo       smallint,
      formato    char(25),
		tamanho    smallint

	let coluna_curr    = 1
	let y[coluna_curr] = valor
   call drep_formata_coluna(tipo,formato,tamanho)
   return drep_def[coluna_curr].coluna clipped, str_report clipped
end function


#  ============================================================================ 
#  Formata a coluna corrente, recebendo o tipo. Se tipo a null mete 
#  directamente.
#  ============================================================================ 
function     drep_formata_coluna(tipo,formato,tamanho)
{}
   define
      tipo       smallint,
      formato    char(25),
      tamanho    smallint,
      um_small   smallint,
      um_int     integer,
      um_float   float,
      um_date    date,
      um_smfloat smallfloat,
		
      um_decimal decimal(32,16)

   case # Meter a entrar em linha de conta com o tamanho.
      WHEN tipo = 0  # Char
         let str_report = y[coluna_curr]
      WHEN tipo = 1  # Smallint
         let um_int = y[coluna_curr]
         let str_report = um_int using formato clipped
      WHEN tipo = 2  # Integer
         let um_int = y[coluna_curr]
         let str_report = um_int using formato clipped
      WHEN tipo = 3  # Float. Meter a ir buscar formatos default, etc.
         let um_float = y[coluna_curr]
         let str_report = um_float using formato clipped
      WHEN tipo = 4  # Smallfloat.
         let um_float = y[coluna_curr]
         let str_report = um_float using formato clipped
      WHEN tipo = 5  # Decimal.
         let um_decimal = y[coluna_curr]
         let str_report = um_decimal using formato clipped 
         #Retirei esta formatacao ->"##,###,###.###", devido aos cambios que
         #tem 6 casas decimais. A formatacao que estava nao e necessaria
         #porque ja esta afectado na funcao drep_init_tipos(x).
         #É na funcao d_campo_drep(.....) que entra a formatacao desejada e o
         #tipo de campo
      WHEN tipo = 6  # Serial
         let um_int = y[coluna_curr]
         let str_report = um_int using formato clipped
      WHEN tipo = 7  # Date
         let um_date = y[coluna_curr]
         let str_report = um_date
      #WHEN tipo = 8 # Money
         #PRINT "money     ";
      #WHEN tipo = 9
         #PRINT "Invalido  ";
      WHEN tipo = 10
		   
      #WHEN tipo = 11
         #PRINT "invalido  ";
      #WHEN tipo = 12
         #PRINT "invalido  ";
      ##WHEN tipo = 13
         #PRINT "invalido  ";
      #WHEN tipo = 14
         #PRINT "interval  ";
      OTHERWISE
         error "Tipo invalido"
   END CASE
end function

#  ============================================================================ 
#  Formata a coluna corrente de totais , 
#  recebendo o tipo. Se tipo a null mete 
#  directamente.
#  ============================================================================ 
function     drep_formata_tot_coluna(tipo,formato,tamanho)
{}
   define
      tipo       smallint,
      formato    char(25),
      tamanho    smallint,
      um_small   smallint,
      um_int     integer,
      um_float   float,
      um_date    date,
      um_smfloat smallfloat,
		
      um_decimal decimal

	 let um_date = null
	 let um_decimal = null
	 let str_report = ""
   case # Meter a entrar em linha de conta com o tamanho.
      WHEN tipo = 0  # Char
			# Meter o total no primeiro char em que caiba.
			if coluna_curr <= 1 then
            let str_report = "TOTAL"
			else
				let str_report = ""
			end if
      WHEN tipo = 1  # Smallint
         #let um_int = y[coluna_curr]
         let str_report = um_int using formato clipped
      WHEN tipo = 2  # Integer
         #let um_int = y[coluna_curr]
         let str_report = um_int using formato clipped
      WHEN tipo = 3  # Float. Meter a ir buscar formatos default, etc.
			if drep_def[coluna_curr].totalizacao = "S" then
            let str_report = drep_def[coluna_curr].total_de using formato clipped
			end if
      WHEN tipo = 4  # Smallfloat.
			if drep_def[coluna_curr].totalizacao = "S" then
            let str_report = drep_def[coluna_curr].total_de using formato clipped
			end if
      WHEN tipo = 5  # Decimal.
         #let um_decimal = y[coluna_curr]
         let str_report = um_decimal using "#,###,###.###"
      WHEN tipo = 6  # Serial
         #let um_int = y[coluna_curr]
         let str_report = um_int using formato clipped
      WHEN tipo = 7  # Date
         #let um_date = y[coluna_curr]
         let str_report = um_date
      #WHEN tipo = 8
         #PRINT "money     ";
      #WHEN tipo = 9
         #PRINT "Invalido  ";
      WHEN 10
		   
      #WHEN tipo = 11
         #PRINT "invalido  ";
      #WHEN tipo = 12
         #PRINT "invalido  ";
      ##WHEN tipo = 13
         #PRINT "invalido  ";
      #WHEN tipo = 14
         #PRINT "interval  ";
      OTHERWISE
         error "Tipo invalido"
   END CASE
end function

#  ============================================================================ 
#  Imprime a paginacao, recebendo se e header ou trailer e metendo no 
#  sitio certo.
#  ============================================================================ 
function 	 print_pagina(sitio,npag)
{}
	define
		sitio    char(1),
		npag     smallint,
		pagplace smallint,
		str_pag  char(20)

	if tipo_pag ="-" then
		let str_pag = "- ",npag using "<<<<", " -"
	else
		let str_pag = "Pagina ",npag using "####"
	end if
	let pagplace = length(str_pag)
	let pagplace = max_len - pagplace - 1
	let pag_str  = pag_str[1,pagplace], str_pag clipped
end function

report     r_drep3(da_sorte)
{}
   define
		da_sorte smallint

   output
   top margin  0 
   bottom margin  6 
   left margin 0
	page length 72
   format
   first page header
      print d_rep_font() clipped;
      print drep_head[1] clipped
      print drep_head[2] clipped
      print drep_head[3] clipped
   page header
      print d_rep_font() clipped;
      print drep_head[1] clipped
      print drep_head[2] clipped
      print drep_head[3] clipped

   on every row
      if skip_to_top_of_page then
         let skip_to_top_of_page = false
			skip to top of page
		end if
      print rep_str clipped
   
   page trailer 
		if tipo_tail = 1 then
			print risco_horiz clipped
			call print_pagina("T",pageno)
			print pag_str clipped
		else
			skip 1 line
         print drep_tail clipped
		end if
end report

report     r_drep4(da_sorte)
{}
   define
		da_sorte smallint

   output
   top margin  0 
   bottom margin  6 
   left margin 0
	page length 72
   format
   first page header
      print d_rep_font() clipped;
      print drep_head[1] clipped
      print drep_head[2] clipped
      print drep_head[3] clipped
      print drep_head[4] clipped
   page header
      print d_rep_font() clipped;
      print drep_head[1] clipped
      print drep_head[2] clipped
      print drep_head[3] clipped
      print drep_head[4] clipped

   on every row
      if skip_to_top_of_page then
         let skip_to_top_of_page = false
			skip to top of page
		end if
      print rep_str clipped
   
   page trailer 
		if tipo_tail = 1 then
			print risco_horiz clipped
			call print_pagina("T",pageno)
			print pag_str clipped
		else
			skip 1 line
         print drep_tail clipped
		end if
end report



#  ============================================================================ 
#  Report com um header de 6 linhas.
#  ============================================================================ 
report     r_drep6(str_drep)
{}
   define
      str_drep char(250),
		i smallint

   output
   top margin  0 
   bottom margin  6 
   left margin 0
	page length 72
   format
   first page header
      print d_rep_font() clipped;
      print drep_head[1] clipped
      print drep_head[2] clipped
      print drep_head[3] clipped
      print drep_head[4] clipped
      print drep_head[5] clipped
      print drep_head[6] clipped
   page header
      print d_rep_font() clipped;
      print drep_head[1] clipped
      print drep_head[2] clipped
      print drep_head[3] clipped
      print drep_head[4] clipped
      print drep_head[5] clipped
      print drep_head[6] clipped

   on every row
      if skip_to_top_of_page then
         let skip_to_top_of_page = false
			skip to top of page
		end if
      print str_drep clipped
   
   page trailer 
		if tipo_tail = 1 then
			print risco_horiz clipped
			call print_pagina("T",pageno)
			print pag_str clipped
		else
			skip 1 line
         print drep_tail clipped
		end if
end report

#  ============================================================================ 
#  Report com um header de 8 linhas.
#  ============================================================================ 
report     r_drep8(str_drep)
{}
   define
      str_drep char(250),
		i smallint

   output
   top margin  0 
   bottom margin  6 
   left margin 0
	page length 72
   format
   first page header
      print d_rep_font() clipped;
      print drep_head[1] clipped
      print drep_head[2] clipped
      print drep_head[3] clipped
      print drep_head[4] clipped
      print drep_head[5] clipped
      print drep_head[6] clipped
      print drep_head[7] clipped
      print drep_head[8] clipped
   page header
      print d_rep_font() clipped;
      print drep_head[1] clipped
      print drep_head[2] clipped
      print drep_head[3] clipped
      print drep_head[4] clipped
      print drep_head[5] clipped
      print drep_head[6] clipped
      print drep_head[7] clipped
      print drep_head[8] clipped

   on every row
      if skip_to_top_of_page then
         let skip_to_top_of_page = false
			skip to top of page
		end if
      print str_drep clipped
   
   page trailer 
		if tipo_tail = 1 then
			print risco_horiz clipped
			call print_pagina("T",pageno)
			print pag_str clipped
		else
			skip 1 line
         print drep_tail clipped
		end if
end report


#  =====================  GESTAO DA ESCOLHA DE CAMPOS ===================  #

function     d_rep_campos(linha,coluna)
{}
   define
      linha    smallint,
      coluna   smallint,
      ans      smallint,
      i        smallint,
		existem_campos smallint,
      str19    char(19)

   CALL menuMarc(linha,coluna,ncolunas,"ESCOLHA OS CAMPOS",
					  "*******************",
                 drep_def[1].nome, drep_def[2].nome, 
					  drep_def[3].nome, drep_def[4].nome, 
					  drep_def[5].nome, drep_def[6].nome, 
					  drep_def[7].nome, drep_def[8].nome, 
					  drep_def[9].nome, drep_def[10].nome,
                 drep_def[11].nome, drep_def[12].nome, 
					  drep_def[13].nome, drep_def[14].nome, 
					  drep_def[15].nome, drep_def[16].nome, 
					  drep_def[17].nome, drep_def[18].nome,
					  drep_def[19].nome)
      returning ans, str19
   if not ans then
      return false
   end if
	let existem_campos = FALSE
   for i = 1 to ncolunas
      if str19[i,i] != "*" then
         let drep_def[i].marcado = "N"
		else
         let drep_def[i].marcado = "S"
			let existem_campos = TRUE
      end if
   end for
   return existem_campos
end function



#  ============================================================================ 
#  Manda o font correcto para a impressora.
#  ============================================================================ 
function 	 d_rep_font()
{}
   define
		str_fnt char(10)

	 if not fontAutomatica then
		 return ""
   end if

   case
		when  tipo_font = 10   # Pica
			let str_fnt = d_pica()
		when  tipo_font = 12   # Elite
			let str_fnt = d_elite()
		when  tipo_font = 17   # Condensado
			let str_fnt = d_cond()
		otherwise
			let str_fnt = d_cond()
	end case
	return str_fnt clipped
end function

#  ============================================================================ 
#  Desliga a mudanca automomatica de font
#  ============================================================================ 
function disableFontChange()
  let fontAutomatica = false
end function

#  ============================================================================ 
#  Liga a mudanca automomatica de font
#  ============================================================================ 
function enableFontChange()
  let fontAutomatica = true
end function
