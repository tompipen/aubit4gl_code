#  ============================================================================ 
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#                                                        
#  Autor:   Sergio Alexandre Ferreira
#                                                        
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      :  bdesquema
#  ----------------------------------------------------------------
#  DESCRICAO:  Faz esquemas das tabelas da base de dados mais a 
#              maneira.
#
#  ----------------------------------------------------------------
#  FUNCOES: 
# 
#  ----------------------------------------------------------------
#  FORMS: 
#
#  REPORTS: 
#
#  NOTAS:
#    Falta o keep together no formato word.
#    Falta meter a label do systableext no heading 1 das tabelas
#
#  ============================================================================ 

DATABASE despodata

GLOBALS "/usr/desenvolv/include/d_libglob.4gl"

define
	imprime_header   smallint,    # Flag de impressao ou nao do cabecalho
	bdados        char(19),
	pr_parametros record
		tabelas    char(30),       # Tabelas a mostrar-Todas,Sistema,Especifica
		mod        char(1),        # Todos;Sem modulo;Modulo especifico
		modulo     char(20),       # Todas, Especifico
		ordenacao  char(10),       # Tabid, Tabname
		cabecalho  char(1),        # Gerar header efooter (S/N)
		resultado  char(12),       # Output-stdout,visualizador
		ficheiro   char(50),       # RNome do ficheiro
		remover    char(1),        # Remove ficheiro (Sim/Nao)
		accao      char(20),       # Accao a efectuar (L-Lista Tabelas ; 
											# C-Colunas ; T-Todas)
		diagrama   char(1)         # Mostrar ou nao a ligacao a outras tabelas
	end record,
	modname   char(40),
	pr_esquema record             # 
		nome_tab char(19),         # Nome da tabela
		tabid    integer,          # Tabid da tabela
		nome_col char(19),
		colno    smallint,
		desc_col char(254),
		tipo_col char(19),
		nulos    char(3),
		chave    char(1),          # Indica se a coluna e chave primaria
		den_col  char(50),         # Denominacao da coluna
		def_col  char(30),         # Valor  de default
		inc_col  char(512)
	end record,
	# Este record define uma chave estrangeira
	pr_chave_estrangeira array[50] of record   
		col_que_ref1  char(19),    # Colunas que referenciam
		col_que_ref2  char(19),
		col_que_ref3  char(19),
		col_que_ref4  char(19),
		col_que_ref5  char(19),
		col_que_ref6  char(19),
		col_que_ref7  char(19),
		tab_ref       char(19),    # Tabela que e referenciada
		col_ref1      char(19),    # Colunas que sao referenciadas
		col_ref2      char(19),
		col_ref3      char(19),
		col_ref4      char(19),
		col_ref5      char(19),
		col_ref6      char(19),
		col_ref7      char(19)
	end record,
	chv_curr      smallint,       # Chave estrangeira corrente
	num_campos    smallint,
	num_tabelas   smallint,
	tipo          integer,
	tamanho       integer,
	fl_nm_bde     char(64),
	str_where     char(256),
	fl_nm_tabelas char(64),
	fl_nm_header  char(64),
	fl_nm_out     char(64),
	chave_primaria       char(120),
	tipo_primaria        smallint,  # 1-Explicita,2-Const Unico,3-Ind. Un.
	idx_chv_sec          smallint,
	chaves_secundarias   array[10] of char(120),
	idx_chv_est          smallint,
	chaves_estrangeiras  array[50] of char(256),
	idx_validacoes       smallint,
	ExistemValidacoes    smallint,
	TextoValidacoes      char(640),
	TextoValidacao       char(32),
	PrValidacoes           array[10] of record
		texto char(512)
	end record,
	TemChavesUnicas smallint,
	existe_body          smallint,
	com_header           smallint


#  ============================================================================ 
#  Esquemas de bases de dados.
#  ============================================================================ 
FUNCTION 	 bdesquema(base_de_dados,accao,restricao)
{}
   DEFINE
		base_de_dados char(20),
		restricao     char(20),
		accao         char(8)   # L-Lista de Tabelas ; T-Informacao total

			create temp table tmp_checks (
				checktext char(512)
			)
   let d_nm_log = "/tmp/bdesquema.log"
   let bdados = base_de_dados
   let existe_body=false
	let TemChavesUnicas = false
   let pr_parametros.diagrama = "S"
	let pr_parametros.accao = accao
	let pr_parametros.tabelas    = "Aplicacao"
	case 
		when accao = "MOD"    # Lista de Modulos - Html
			call BdEsquemaCGIMod()
		when accao = "TABMOD" # Tabelas de modulos - Html
			let pr_parametros.modulo = restricao
			call BdEsquemaCGITab()
		when accao = "TABLE" # Tabela - Html
			let pr_parametros.modulo = NULL
	      let pr_parametros.tabelas = restricao
			call BdEsquemaCGITab()
		otherwise
			error "Tipo de execucao invalida"
	end case
end function


#  ============================================================================ 
#  Mostra todas as tabela s de um dado modulo
#  ============================================================================ 
function BdEsquemaCGITab()
	let pr_parametros.ficheiro   = "/tmp/bdes.",d_getpid() using "<<<<<"
	let fl_nm_bde = pr_parametros.ficheiro
	let pr_parametros.resultado = "stdout"
   call get_esquema()
end function


#  ============================================================================ 
#  Vai buscar a informacao relativa a descricao de tabelas e colunas 
#  e executa a lista de tabelas
#  ============================================================================ 
function     get_esquema()
{}
   define
		str_sel   char(640),
		str_sel_coldesc   char(128),
		ans       smallint,
		comm      char(128),
		existe_extensao smallint,
		desc_tabela     char(254),
		dumm smallint
	
	whenever error stop
	let str_sel = "select  systables.tabname, systables.tabid, colname, ",
					  " syscolumns.colno, ",
					  " coltype,collength,",
					  " colno,remarks ",
					  " from systables, syscolumns,outer systableext where ",
					  " systables.tabid=syscolumns.tabid ",
					  " and systables.tabname=systableext.tabname "
   case
		when pr_parametros.tabelas = "Aplicacao"
			let str_where = str_where clipped, 
								 " and systables.tabname not matches 'sys*' ",
								 "and systables.tabname not matches ' VER*'"
		when pr_parametros.tabelas = "Sistema"
			let str_where = str_where clipped, 
								 " and systables.tabname matches 'sys*' "
		when pr_parametros.tabelas = "Todas"
		when pr_parametros.tabelas IS NULL
		otherwise
			let str_where = str_where clipped, 
								 " and systables.tabname matches '", 
				             pr_parametros.tabelas, "'"
	end case

	case
		when  pr_parametros.modulo is null 
		when  pr_parametros.modulo = "SEM_MODULO"          # Sem Modulo
			let str_where = str_where clipped, 
			" and systables.tabname not in ",
			"(select d_mod_tab.tabname from d_mod_tab where ",
			"systables.tabname=d_mod_tab.tabname)"
		otherwise                # Modulo especifico
			let str_where = str_where clipped, 
			" and systables.tabname in ",
			"(select d_mod_tab.tabname from d_mod_tab where codmod='",
			pr_parametros.modulo,"')"
	end case

	whenever error continue
   let str_sel_coldesc = "select syscolumnext.remarks from syscolumnext ",
								 "where tabname=?",
								 " and colname=?"
	prepare stat_sel_coldesc from str_sel_coldesc
	case status
		when 0
	      declare cr_coldesc cursor for  stat_sel_coldesc 
	      let existe_extensao = true
		when -206
			let existe_extensao = false
		otherwise 
			call d_erro()
	end case
	whenever error stop

	# Ordenacao
#	case
#		when pr_parametros.ordenacao = "Tabid"
#			let str_sel = str_sel clipped, str_where clipped, 
#							  " order by tabid,syscolumns.colno"
#		otherwise
#			let str_sel = str_sel clipped, str_where clipped, 
#							  " order by systables.tabname, syscolumns.colno"
#	end case

	let str_sel = str_sel clipped, str_where clipped, 
					  " order by systables.tabname, syscolumns.colno"

	# ??? Falta a possibilidade de gerar uma pagina apemas com as tabelas
	call bde_lista_tab()

	start report r_html_bdesquema 

	prepare stat_bdesq from str_sel
	declare cr_bdesq cursor for stat_bdesq
	foreach cr_bdesq into pr_esquema.nome_tab, pr_esquema.tabid,
								 pr_esquema.nome_col, pr_esquema.colno,
								 tipo, tamanho, dumm, desc_tabela
		call GetOmissao(pr_esquema.tabid,pr_esquema.colno)
		let pr_esquema.tipo_col = DGetTipo(tipo,tamanho)
		let pr_esquema.nulos    = d_aceita_nulos(tipo)
		initialize pr_esquema.desc_col to null # ??? Devia ser tudo
		if existe_extensao then
		   open  cr_coldesc using pr_esquema.nome_tab, pr_esquema.nome_col
		   fetch cr_coldesc into pr_esquema.desc_col 
		   open  cr_coldesc
		end if
		output to report r_html_bdesquema(pr_esquema.nome_tab,desc_tabela)
	end foreach
								  
	finish report r_html_bdesquema

	let ans = d_unlink(fl_nm_bde)
	let ans = d_unlink(fl_nm_tabelas)
	let ans = d_unlink(fl_nm_header)
end function

#  ============================================================================ 
#  Vai preencher os arrays de chaves.
#  Para permitir compatibilidade com versoes antigas de bases de dados
#  nao liga a nao existencia de tabelas de "constraints" e tenta ir buscar os
#  inidices unicos para chave primaria (se varios assume que o primeiro eh
#  chave primaria).
#  Atencao ao funcionamento em OnLine pois so da para 7 campos num indice
#  ============================================================================ 
function 	 get_chaves(tabela,idtabela)
{}
   define
		tabela   char(19),
		idtabela integer
   
	initialize chave_primaria to null
	if not get_primaria_explicita(tabela,idtabela) then
		if not get_primaria_unique(tabela,idtabela) then
			call get_primaria_indice_unico(tabela,idtabela)
		end if
	end if
	call get_secundarias(tabela)
	call get_estrangeiras(tabela,idtabela)
end function

#  ============================================================================ 
#  Vai buscar uma chave primaria definida explicitamente no "create table"
#  com "primary key"
#  ??? Falta nao ligar a nao existencia de sysconstraints.
#  ============================================================================ 
function 	 get_primaria_explicita(tabela,idtabela)
{}
   define
		tabela  char(19),
		idtabela integer,
		nomeidx char(18),
		col1, col2,col3,col4,col5,col6,col7 char(19)
   
	declare cr_primaria_const cursor for 
		select sysindexes.idxname, 
				 scol1.colname, scol2.colname, scol3.colname,
				 scol4.colname, scol5.colname, scol6.colname, scol7.colname
			from sysconstraints, sysindexes, 
				  syscolumns scol1, outer syscolumns scol2, outer syscolumns scol3,
				  outer syscolumns scol4, outer syscolumns scol5, 
				  outer syscolumns scol6, outer syscolumns scol7
			where sysconstraints.tabid = idtabela and
					sysconstraints.constrtype = "P" and
					sysconstraints.idxname    = sysindexes.idxname and
					sysindexes.part1 = scol1.colno and idtabela = scol1.tabid and
					sysindexes.part2 = scol2.colno and idtabela = scol2.tabid and
					sysindexes.part3 = scol3.colno and idtabela = scol3.tabid and
					sysindexes.part4 = scol4.colno and idtabela = scol4.tabid and
					sysindexes.part5 = scol5.colno and idtabela = scol5.tabid and
					sysindexes.part6 = scol6.colno and idtabela = scol6.tabid and
					sysindexes.part7 = scol7.colno and idtabela = scol7.tabid 
	initialize col1,col2,col3,col4,col5,col6,col7 to null
	open cr_primaria_const
	fetch cr_primaria_const into nomeidx, col1,col2,col3,col4,col5,col6,col7
	if status = notfound then
		return false
	end if
	close cr_primaria_const
	let chave_primaria = col1
	if col2 is not null then
		let chave_primaria = chave_primaria clipped, ", ", col2
	end if
	if col3 is not null then
		let chave_primaria = chave_primaria clipped, ", ", col3
	end if
	if col4 is not null then
		let chave_primaria = chave_primaria clipped, ", ", col4
	end if
	if col5 is not null then
		let chave_primaria = chave_primaria clipped, ", ", col5
	end if
	if col6 is not null then
		let chave_primaria = chave_primaria clipped, ", ", col6
	end if
	if col7 is not null then
		let chave_primaria = chave_primaria clipped, ", ", col7
	end if
	let tipo_primaria = 1
	return true

end function

#  ============================================================================ 
#  Procura uma chave primaria a partir da existeciad de um constraint unique
#  ============================================================================ 
function 	 get_primaria_unique(tabela,idtabela)
{}
   define
		tabela  char(19),
		idtabela integer,
		nomeidx char(18),
		col1, col2,col3,col4,col5,col6,col7 char(19)
   
	return false
end function

#  ============================================================================ 
#  Vai a procura de chave primaria com inidiDdice unico
#  ============================================================================ 
function 	 get_primaria_indice_unico(tabela,idtabela)
{}
   define
		tabela   char(19),
		idtabela integer,
		nomeidx  char(18),
		col1, col2,col3,col4,col5,col6,col7 char(19)
   
	declare cr_primaria_idx cursor for 
		select sysindexes.idxname, 
				 scol1.colname, scol2.colname, scol3.colname,
				 scol4.colname, scol5.colname, scol6.colname, scol7.colname
			from sysindexes, 
				  syscolumns scol1, outer syscolumns scol2, outer syscolumns scol3,
				  outer syscolumns scol4, outer syscolumns scol5, 
				  outer syscolumns scol6, outer syscolumns scol7
			where sysindexes.tabid = idtabela       and
					sysindexes.idxtype = "U"          and
					sysindexes.part1 = scol1.colno and idtabela = scol1.tabid and
					sysindexes.part2 = scol2.colno and idtabela = scol2.tabid and
					sysindexes.part3 = scol3.colno and idtabela = scol3.tabid and
					sysindexes.part4 = scol4.colno and idtabela = scol4.tabid and
					sysindexes.part5 = scol5.colno and idtabela = scol5.tabid and
					sysindexes.part6 = scol6.colno and idtabela = scol6.tabid and
					sysindexes.part7 = scol7.colno and idtabela = scol7.tabid 
	initialize col1,col2,col3,col4,col5,col6,col7 to null
	open cr_primaria_idx
	fetch cr_primaria_idx into nomeidx, col1,col2,col3,col4,col5,col6,col7
	if status = notfound then
		return 
	end if
	close cr_primaria_idx 
	let chave_primaria = col1
	if col2 is not null then
		let chave_primaria = chave_primaria clipped, ", ", col2
	end if
	if col3 is not null then
		let chave_primaria = chave_primaria clipped, ", ", col3
	end if
	if col4 is not null then
		let chave_primaria = chave_primaria clipped, ", ", col4
	end if
	if col5 is not null then
		let chave_primaria = chave_primaria clipped, ", ", col5
	end if
	if col6 is not null then
		let chave_primaria = chave_primaria clipped, ", ", col6
	end if
	if col7 is not null then
		let chave_primaria = chave_primaria clipped, ", ", col7
	end if
	let tipo_primaria = 2
	return 
end function


#  ============================================================================ 
#  Vai buscar as colunas de um dado indice
#  ============================================================================ 
function get_cols_de_indice(nome_indice,idtab) 
{}
   define
		nome_indice char(19),
		idtab       integer,
		col1, col2, col3, col4, col5, col6, col7 char(19)
 
	initialize col1, col2, col3, col4, col5, col6, col7 to null
	select scol1.colname, scol2.colname, scol3.colname,
				 scol4.colname, scol5.colname, scol6.colname, scol7.colname
			into col1, col2, col3, col4, col5, col6, col7
			from sysindexes, 
				  syscolumns scol1, outer syscolumns scol2, outer syscolumns scol3,
				  outer syscolumns scol4, outer syscolumns scol5, 
				  outer syscolumns scol6, outer syscolumns scol7
			where sysindexes.idxname = nome_indice and
					sysindexes.part1 = scol1.colno and idtab = scol1.tabid and
					sysindexes.part2 = scol2.colno and idtab = scol2.tabid and
					sysindexes.part3 = scol3.colno and idtab = scol3.tabid and
					sysindexes.part4 = scol4.colno and idtab = scol4.tabid and
					sysindexes.part5 = scol5.colno and idtab = scol5.tabid and
					sysindexes.part6 = scol6.colno and idtab = scol6.tabid and
					sysindexes.part7 = scol7.colno and idtab = scol7.tabid 
   
   return col1, col2, col3, col4, col5, col6, col7 
end function


#  ============================================================================ 
#  Vai buscar as chaves secundarias
#  ============================================================================ 
function 	 get_secundarias(tabela)
{}
   define
		tabela  char(19)
end function

#  ============================================================================ 
#  Vai buscar as chaves estrangeiras todas (de acordo com a seleccao a efectuar)
#  e guarda-as no array de chaves estrangeiras
#  ============================================================================ 
function 	 get_estrangeiras(tabela,idtabela)
{}
   define
		tabela             char(19),
		idtabela           integer,
		ind_que_referencia char(19),
		const_id           integer,
		tab_ref            char(19), 
		tabid_ref          integer,
		i smallint,
		idx_ref            char(19)


	for i = 1 to 50 
	   initialize pr_chave_estrangeira[i].* to null
	end for
	let chv_curr = 0
	let i = 1

	#
	# Tem de ler o indice da tabela referenciada (sysreferences.primary)
	# e o indice da tabela que referencia (sysconstraints.idxname) para
	# retirar as respectivas colunas
	# Se calhar mais valia fazer um foreach para cada constraint e um foreach 
	# para as colunas desse constraint.
	#
	declare cr_est_const cursor for 
		select sysconstraints.idxname, sysconstraints.constrid, 
				 systables.tabname, systables.tabid,
				 const_ref.idxname
			from sysconstraints, sysconstraints const_ref, sysreferences, systables
			where sysconstraints.tabid      = idtabela and
			      sysconstraints.constrid    = sysreferences.constrid and
			      const_ref.constrid         = sysreferences.primary and
			      sysreferences.ptabid      = systables.tabid and
					sysconstraints.constrtype = "R" 
	foreach cr_est_const into ind_que_referencia, const_id,
									  pr_chave_estrangeira[i].tab_ref, tabid_ref,
									  idx_ref
		call get_cols_de_indice(ind_que_referencia,idtabela) 
			  returning pr_chave_estrangeira[i].col_que_ref1, 
							pr_chave_estrangeira[i].col_que_ref2, 
							pr_chave_estrangeira[i].col_que_ref3, 
							pr_chave_estrangeira[i].col_que_ref4, 
							pr_chave_estrangeira[i].col_que_ref5, 
							pr_chave_estrangeira[i].col_que_ref6, 
							pr_chave_estrangeira[i].col_que_ref7
		call get_cols_de_indice(idx_ref,tabid_ref) 
			  returning pr_chave_estrangeira[i].col_ref1, 
							pr_chave_estrangeira[i].col_ref2, 
							pr_chave_estrangeira[i].col_ref3, 
							pr_chave_estrangeira[i].col_ref4, 
							pr_chave_estrangeira[i].col_ref5, 
							pr_chave_estrangeira[i].col_ref6, 
							pr_chave_estrangeira[i].col_ref7
		call nova_estrangeira()
		let i = 1 + i
	end foreach
	close cr_est_const
end function


#  ============================================================================ 
#  Mete uma nova chave estrangeira no array correspondente
#  Recebendo os valores do record pr_chave_estrangeira
#  ============================================================================ 
function 	 nova_estrangeira()
{}
	let chv_curr = chv_curr + 1
	let chaves_estrangeiras[chv_curr] = "<A ",
	     "HREF=/cgi-bin/r4gl?bdesquema&bdesquema&", bdados clipped,
		  "&TABLE&",
		   pr_chave_estrangeira[chv_curr].tab_ref clipped, 
			">("

	let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,
			 pr_chave_estrangeira[chv_curr].col_que_ref1
	if pr_chave_estrangeira[chv_curr].col_que_ref2 is not null then
		let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,
			 ", ", pr_chave_estrangeira[chv_curr].col_que_ref2
	end if
	if pr_chave_estrangeira[chv_curr].col_que_ref3 is not null then
		let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,
			 ", ", pr_chave_estrangeira[chv_curr].col_que_ref3
	end if
	if pr_chave_estrangeira[chv_curr].col_que_ref4 is not null then
		let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,
		", ", pr_chave_estrangeira[chv_curr].col_que_ref4
	end if
	if pr_chave_estrangeira[chv_curr].col_que_ref5 is not null then
		let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,
		", ", pr_chave_estrangeira[chv_curr].col_que_ref5
	end if
	if pr_chave_estrangeira[chv_curr].col_que_ref6 is not null then
		let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,
		", ", pr_chave_estrangeira[chv_curr].col_que_ref6
	end if
	if pr_chave_estrangeira[chv_curr].col_que_ref7 is not null then
		let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,
		", ", pr_chave_estrangeira[chv_curr].col_que_ref7
	end if
	let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,
		 ") referencia ", pr_chave_estrangeira[chv_curr].tab_ref clipped, " ( "
	let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,
			 pr_chave_estrangeira[chv_curr].col_ref1
	if pr_chave_estrangeira[chv_curr].col_ref2 is not null then
		let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,
			 ", ", pr_chave_estrangeira[chv_curr].col_ref2
	end if
	if pr_chave_estrangeira[chv_curr].col_ref3 is not null then
		let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,
			 ", ", pr_chave_estrangeira[chv_curr].col_ref3
	end if
	if pr_chave_estrangeira[chv_curr].col_ref4 is not null then
		let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,
		", ", pr_chave_estrangeira[chv_curr].col_ref4
	end if
	if pr_chave_estrangeira[chv_curr].col_ref5 is not null then
		let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,
		", ", pr_chave_estrangeira[chv_curr].col_ref5
	end if
	if pr_chave_estrangeira[chv_curr].col_ref6 is not null then
		let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,
		", ", pr_chave_estrangeira[chv_curr].col_ref6
	end if
	if pr_chave_estrangeira[chv_curr].col_ref7 is not null then
		let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,
		", ", pr_chave_estrangeira[chv_curr].col_ref7
	end if
	let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,")"
	let chaves_estrangeiras[chv_curr] = chaves_estrangeiras[chv_curr] clipped,
		 "</A>"
end function


#  ============================================================================ 
#  Vai buscar os valores de default (??? devia ir a upscol e a contraints)
#  ============================================================================ 
function GetOmissao(idtabela,nocoluna)
{}
	define
		idtabela integer,
		nocoluna smallint,
		tipo     char(1),
		valor    char(256)

	select type, default
		into tipo, valor
		from sysdefaults
		where tabid=idtabela and colno = nocoluna
   case 
		when tipo = "U"
			let pr_esquema.def_col = "Utilizador"
		when tipo = "C"
			let pr_esquema.def_col = "Hora de sistema"
		when tipo = "N"
			let pr_esquema.def_col = "Nulo"
		when tipo = "T"
			let pr_esquema.def_col = "Data de sistema"
		when tipo = "S"
			let pr_esquema.def_col = "Nome do servidor"
		otherwise
			let pr_esquema.def_col = valor clipped
	end case
end function

#  ============================================================================ 
#  Vai buscar todos os checks de uma tabela e junta-os por constraint
#  ============================================================================ 
function GetValidacoesTabela(idTabela)
	define
		idtabela    integer,
		nocoluna    smallint,
		myconstrid integer, seq smallint
	
	declare cr_validacoes cursor for
	select sysconstraints.constrid, checktext , seqno
		from syschecks, sysconstraints
		where tabid = idtabela and 
				syschecks.constrid = sysconstraints.constrid  and type='T'
		order by sysconstraints.constrid, seqno
	let idx_validacoes = 1
	start report AgregaChecks
	let ExistemValidacoes = false
	foreach cr_validacoes into myconstrid, TextoValidacao, seq
		output to report AgregaChecks(myconstrid)
		let ExistemValidacoes = true
	end foreach
	finish report AgregaChecks
	close cr_validacoes
end function

#  Report usado para a agregacao e para inserir na tabela temporaria
report AgregaChecks(constrid)
	define
      constrid integer

   format 
		before group of constrid
			let TextoValidacoes = ""
		on every row 
			let TextoValidacoes = TextoValidacoes clipped, TextoValidacao clipped
		after group of constrid
			insert into tmp_checks (checktext) values (TextoValidacoes)
end report

#  ============================================================================ 
#  Vai buscar as validacoes aceite na coluna e tabela. Tabela syschecks e 
#  sysconstraints.
#  ============================================================================ 
function GetValidacoes(idtabela,nocoluna)
{}
	define
		idtabela    integer,
		nocoluna    smallint,
		str_matches char(64)
	
	# Tenho ideia que nao posso ir buscar directamente a coluna
	# Tenho  de analisar a expressao.
	# Para vou seleccionar o que tiver a coluna e meter directamente
	# Depois hei-de fazer um parser
	if not ExistemValidacoes then
		return
	end if

	let str_matches = "*", pr_esquema.nome_col clipped, "*"
	declare cr_validacao cursor for
	select checktext from tmp_checks
		where checktext matches str_matches
	let idx_validacoes = 1
	let pr_esquema.inc_col = ""
	foreach cr_validacao into PrValidacoes[idx_validacoes].texto
		let pr_esquema.inc_col = pr_esquema.inc_col clipped, 
			 PrValidacoes[idx_validacoes].texto clipped
	   let idx_validacoes = idx_validacoes + 1
	end foreach
	let idx_validacoes = idx_validacoes - 1
	close cr_validacao
end function

#  ============================================================================ 
#  Fim das validacoes
#  ============================================================================ 
function FimValidacoes()
	delete from tmp_checks
	let TextoValidacoes = ""
	let pr_esquema.inc_col = ""
end function



#  ============================================================================ 
#  Cria a lista das tabelas existentes
#  ============================================================================ 
function 	 bde_lista_tab()
{}
   define
		str_sel_tab     char(640),
		nome_tabela     char(19),
		desc_tabela     char(254),
		existe_extensao smallint

	let str_sel_tab = "select count(*) from systables where 1=1 ", str_where
	prepare stat_count_tab from str_sel_tab
	declare cr_count_tab cursor for stat_count_tab
	open cr_count_tab
	fetch cr_count_tab into num_tabelas
	if num_tabelas = 1 then
		return
	end if

	let str_sel_tab = "select remarks from systableext where tabname=?"
	whenever error continue
	prepare stat_sys_extended from str_sel_tab
	case status
		when 0
         declare cr_sys_extended cursor for stat_sys_extended
	      let existe_extensao = true
		when -206
			let existe_extensao = false
		otherwise 
			call d_erro()
	end case
	whenever error call d_erro

   let str_sel_tab = " select systables.tabname, remarks from systables, ",
		     " outer systableext where ",
		     " systables.tabname=systableext.tabname ", str_where ,
							" order by 1"
	# whenever error continue
	prepare stat_sel_tab from str_sel_tab
	declare cr_sel_tab cursor for stat_sel_tab
	let fl_nm_tabelas = "/tmp/tabs", d_getpid() using "<<<<<"
	start report r_html_tabelas #to fl_nm_tabelas
	FOREACH cr_sel_tab into nome_tabela
		initialize desc_tabela to null
		if existe_extensao then
		   open  cr_sys_extended using nome_tabela
		   fetch cr_sys_extended into  desc_tabela
		   close cr_sys_extended
		end if
	   output to report r_html_tabelas(nome_tabela,desc_tabela)
	END FOREACH
   finish report r_html_tabelas
end function




#  ============================================================================ 
#  Mostra a lista de tabelas orgaizada por ordem alfabetica em formato HTML
#  ============================================================================ 
report     r_html_tabelas(nome_tabela,desc_tabela)
{}
   define
		nome_tabela char(19),
		starterr smallint,
		desc_tabela char(254)

   output 
		 left margin 0
		 top margin 0
		 bottom margin 0
		 page length 30
   format
      first page header
			 if not existe_body then
				 call icgi_mimetype("text/html")
				 let starterr = icgi_start()
			    print "<HTML>"
			    print "<HEAD>"
			    print "<META NAME=\"Generator\" CONTENT=\"bdesquema\">"
			    print "<TITLE> "
			    print "Despodata - ",bdados clipped, 
						 "     Desenho do modelo de dados"
			    print "</TITLE> "
			    print "</HEAD>"
			    print "<BODY>"
			    let existe_body=true
			 else
				 skip 8 lines
			 end if
		    # Mete um novo titulo Heading 2 com autonumlgl
			 select nome into modname
			    from d_modulos 
			    where codigo = pr_parametros.modulo
		    print "<CENTER><H1>"
			 if modname is not null then
		       print "Módulo '",modname clipped, "'";
			 end if
		    print "</H1></CENTER>"
		    print "<H2>"
		    print "Indice de Tabelas"
		    print "</H2>"

			 # Se calhar dava jeito usar o num_tabelas
		    # Cria uma tabela html para mostrar as tabelas

          print "<TABLE BORDER CELLSPACING=2 CELLPADDING=7>";
          print "<TR>";
          print "<TH>";
          print "Tabela";
          print "</TH>";
          print "<TH>";
          print "Descrição" ;
          print "</TH>";
          print "</TR>";

	 on every row
          print "<TR>";
          print "<TD VALIGN=\"TOP\">";
          print "<A HREF=#", nome_tabela clipped, ">", 
					 nome_tabela clipped, "</A>";
          print "</TD>";
          print "<TD VALIGN=\"TOP\">";
	  if desc_tabela is not null then
          print desc_tabela clipped;
	  else
	     print "-";
	  end if
     print "</TD>";
     print "</TR>";

		on last row
          print "</TABLE>"

end report

#  ============================================================================ 
#  Relatorio em formato HTML
#  ============================================================================ 
report     r_html_bdesquema(tab,desc_tabela) 
	define
		tab         char(19),
		desc_tabela char(254),
		starterr smallint,
		i           smallint

   output
		top margin 0
		bottom margin 0
		page length 10
		left margin 0
	
	format

		first page header
			 if not existe_body then
				 call icgi_mimetype("text/html")
				 let starterr = icgi_start()
			    print "<HTML>"
			    print "<HEAD>"
			    print "<META NAME=\"Generator\" CONTENT=\"bdesquema\">"
			    print "<TITLE> "
			    print "Despodata - ",bdados clipped, 
						 "     Desenho do modelo de dados"
			    print "</TITLE> "
			    print "</HEAD>"
			    print "<BODY>"
			    let existe_body=true
			 else
				 skip 8 lines
			 end if

		  print "<H1>Detalhes das tabelas</H1>"

		before group of tab
		  # Mete um novo titulo Heading 2 com autonumlgl
		  print "   <A NAME=", pr_esquema.nome_tab clipped, ">";
		  print "<H3>";
		  print "Tabela ", pr_esquema.nome_tab clipped, " - ";
		  print desc_tabela clipped;
		  print "</H3>";

		  call get_chaves(pr_esquema.nome_tab,pr_esquema.tabid)

		  # Cria uma tabela word com o tamanho pretendido

		  print "<TABLE BORDER CELLPADDING=3 WIDTH=100%>"

		  # Cabecalho da tabela
		  print "<TR>";

		  print "<TD  VALIGN=\"TOP\"";
		  print "<B><I>";
		  print "<P ALIGN=\"CENTER\">";
		  print "Nome";
		  print"</B></I></TD>";

		  print "<TD VALIGN=\"TOP\"";
		  print "<B><I>";
		  print "<P ALIGN=\"CENTER\">";
		  print "Tipo";
		  print"</B></I></TD>";

		  print "<TD VALIGN=\"TOP\"";
		  print "<B><I>";
		  print "<P ALIGN=\"CENTER\">";
		  print "Nulos";
		  print"</B></I></TD>";

		  print "<TD VALIGN=\"TOP\"";
		  print "<B><I>";
		  print "<P ALIGN=\"CENTER\">";
		  print "Default";
		  print"</B></I></TD>";

		  print "<TD VALIGN=\"TOP\"";
		  print "<B><I>";
		  print "<P ALIGN=\"CENTER\">";
		  print "Validação";
		  print"</B></I></TD>";

		  print "<TD VALIGN=\"TOP\"";
		  print "<B><I>";
		  print "<P ALIGN=\"CENTER\">";
		  print "Descri&ccedil;&atilde;o";
		  print"</B></I></TD>";

		  print "</TR>";
		  call GetValidacoesTabela(pr_esquema.tabid)

		on every row
		   call GetValidacoes(pr_esquema.tabid,pr_esquema.colno)
         print "<TR>";
         print    "<TD VALIGN=\"TOP\">";

			print       "<P>";
		   if pr_esquema.nome_col is null then
			   print "-";
		   else
			   print pr_esquema.nome_col clipped;
		   end if
         print " ";
         print    "</TD>";
         print    "<TD VALIGN='TOP'>";
         print " ";
			print       "<P>";
		   print        pr_esquema.tipo_col clipped;
         print " ";
         print    "</TD>";
         print    "<TD ALIGN='CENTER'>";
         print " ";
			print "<P ALIGN='CENTER'>";
		   print pr_esquema.nulos clipped;

         print "</TD>";
         print "<TD VALIGN=\"TOP\">";

			print "<P>";
		   if pr_esquema.def_col is null then
			   print "-";
		   else
			   print pr_esquema.def_col clipped;
		   end if

         print "</TD>";
         print "<TD VALIGN=\"TOP\">";
			print "<P>";
		   if pr_esquema.inc_col is null then
			   print "-";
		   else
		      print pr_esquema.inc_col clipped;
		   end if

         print "</TD>";
         print "<TD VALIGN=\"TOP\">";

			print "<P>";
		   if pr_esquema.desc_col is null then
			   print "-";
		   else
		      print pr_esquema.desc_col clipped;
		   end if

         print "</TD>";
         print "</TR>"


		after group of tab
		  call FimValidacoes()
		  print "</TABLE>"

			# Chaves primarias, secundarias e estrangeiras
         #print "<TABLE CELLSPACING=0 BORDER=0 CELLPADDING=7 >"
         print "<P><TABLE CELLSPACING=0 BORDER=0 CELLPADDING=7>";
         print "<TR>";
         print "<TD VALIGN=\"TOP\">";
         print "<B><I>";
         print "<P>";
         print "Chave prim&aacute;ria";
         print "</B></I>";
         print "</TD>";

         print "<TD  VALIGN=\"TOP\">";

         print "<P>";
         print  chave_primaria clipped;

         print "</TD>";
         print "</TR>";

			# ??? A partir daqui eh so se existirem outras chaves unicas
			if TemChavesUnicas then
            print "<TR>";
            print "<TD VALIGN=\"TOP\">";
            print "<B><I>";
            print "<P>";
            print "Outras chaves únicas";
            print "</B></I>";
            print "</TD>";
            print "<TD VALIGN=\"TOP\">";

            print "<P> ";

            print "</TD>";
            print "</TR>";
			end if
			# ??? Ate aqui eh so se existirem outras chaves unicas

         print    "<TR>";
         print    "<TD VALIGN=\"TOP\">";
         print       "<B><I>";
         print       "<P>";
         print       "Chaves estrangeiras";
         print       "</B></I>";
         print    "</TD>";
         print    "<TD VALIGN=\"TOP\">";
         print       "<P>";
			for i = 1 to chv_curr
			   print chaves_estrangeiras[i] clipped, "<P>"
			end for
         Print "</TD>";
         print "</TR>";

         print "<TR>";
         print "<TD VALIGN=\"TOP\">";
         print "&nbsp;";
         print "</TD>";
         print "<TD VALIGN=\"TOP\">";
         print "&nbsp;";
         print "</TD>";
         print "</TR>";
         print "</TABLE>";

			# Apllet que mete o diagrama
			if pr_parametros.diagrama = "S" then
				for i = 1 to chv_curr
				  if pr_chave_estrangeira[i].tab_ref is not null then
					 print "<P>"
#                print "<applet code=\"JoinTabelas.class\" width=360 height=140>"
#                print "<param name=minleft value=\"UM\">"
#                print "<param name=maxleft value=\"UM\">"
#                print "<param name=lefttable value=\"", 
#							 pr_esquema.nome_tab clipped, "\">"
#                print "<param name=minright value=\"ZERO\">"
#                print "<param name=maxright value=\"VARIOS\">"
#                print "<param name=righttable value=\"", 
#							 pr_chave_estrangeira[i].tab_ref clipped, "\">"
#                print "</applet>"
				  end if
				end for
			end if


		on last row 
         print "<P> <A HREF=\"/cgi-bin/r4gl?bdesquema&bdesquema&", 
					 bdados clipped,
					"&MOD&XX\">"
			print "Voltar à lista de módulos...</A>"
			print "</BODY>"
			print "</HTML>"

end report

# ===========================================================================
#  Esta funcao nao esta ainda nada generica.
#  ??? Tem de passar para um modulo a parte pequeno
# ===========================================================================
function BdEsquemaCGIMod()
   call MostraModulos()
end function

# ===========================================================================
# Apresenta uma lista de moduolos definidos para esta base de dados
# Para ja so vai ser implementada a versao html
# ===========================================================================
function MostraModulos()
   define
		str_sel char(640),
		codigo  char(5),
		nome    char(40)

	let str_sel = " select codigo,nome from d_modulos order by 2"
	prepare stat_modulos from str_sel
	declare cr_modulos cursor for stat_modulos
	start report r_html_modulos 
	foreach cr_modulos into codigo, nome
		output to report r_html_modulos(codigo,nome)
	end foreach
	finish report r_html_modulos
end function

#  ============================================================================ 
#  Lista de modulos de uma base de dados
#  ============================================================================ 
report     r_html_modulos(codigo,nome) 
   define
		codigo char(5),
		starterr smallint,
		nome char(40)

   output
		top margin 0
		bottom margin 0
		page length 10000
		left margin 0
	
	format

		first page header
				 call icgi_mimetype("text/html")
				 let starterr = icgi_start()
			    print "<HTML>"
			    print "<HEAD>"
			    print "<META NAME=\"Generator\" CONTENT=\"bdesquema\">"
			    print "<TITLE> "
			    print "Módulos da base de dados : ",bdados
			    print "</TITLE> "
			    print "</HEAD>"
	          display "<BODY BGCOLOR='#F38C00' TEXT='#000000'",
			            "LINK='#880000' VLINK='#660000' ALINK='#F38000'>"
			 print "<H1>"
			 print "Módulos da base de dados : '", bdados clipped, "'"
			 print "</H1>"
			 print "<P>"

          display "<CENTER><BR>"
	       display "<TABLE BORDER=0 WIDTH='100%' CELLSPACING=0 CELLPADDING=6 ",
			         "BGCOLOR='#000000'>",
			         "<TR> <TD>" 
          display "<TABLE BORDER=0 CELLPADDING=0 CELLSPACING=0 ",
			         "BGCOLOR='#CC3300' WIDTH='100%'>",
			        "<TR><TD ALIGN=CENTER>"

			 print "<BLOCKQUOTE><TABLE>"
		on every row
		   print "<TR><TD>"
		   print nome clipped
		   print "</TD>"
		   print "<TD>"
			print    "<B><A HREF=\"/cgi-bin/r4gl?bdesquema&bdesquema&",
						bdados clipped, 
						"&TABMOD&",codigo clipped, "\"></B>"
			print    "<P>"
			print codigo clipped
			print       "</A>"
			print "</TD></TR>"
		on last row
		   print "<TR><TD>"
			print "Tabelas nao associadas a qualquer módulo"
		   print "</TD>"
		   print "<TD>"
			print       "<A HREF=\"/cgi-bin/r4gl?bdesquema&bdesquema&",
					      bdados clipped, 
					      "&TABMOD&SMOD\">SemMod</A>"
			print "</TD></TR>"
			print "</TABLE>"
	      display "</TD></TR>"
	      display "</TABLE>"
	      display "</TD></TR>"
	      display "</TABLE>"
			print "</BLOCKQUOTE>"
			print       "<A HREF='/cgi-bin/r4gl?bdesquema&BdeUtil&",
					      bdados clipped, "'>Utiltários</A>"
			print "<P><FONT SIZE=-2><I>&copy Despodata"

#			print "<FORM>"
#			print "<INPUT NAME=\"mostra_chaves\" TYPE=\"radio\" VALUE=\"frase\" ",
#			      "CHECKED>Sem Chaves estrangeiras"
#			print "<INPUT NAME=\"mostra_tipo_query\" TYPE=\"radio\" ",
#					"VALUE=\"palavra\">",
#					" Com Chaves Estrangeiras"
#		print "</FORM>"
			print "</BODY>"
end report

