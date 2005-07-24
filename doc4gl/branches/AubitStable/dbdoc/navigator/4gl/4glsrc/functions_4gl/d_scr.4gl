#  ============================================================================
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#
#  Divisao de desenvolvimento e producao de software.
#
#  Autor:  Sergio Alexandre Ferreira
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
#  DESCRICAO: Funcoes genericas para utilizacao em entradas de
#             dados standard.
#             Gestao com tabelas temporarias de rowid's.
#
#  ----------------------------------------------------------------
#  FUNCOES:
#
#           d_scr_init() - Escreve a janela de inicio e faz whenever error.
#           d_scd_pes() - Faz a gestao principal duma pesquisa.
#           d_scr_InserRowid() - Insere na temporaria de rowids
#           d_scr_pesAbortada() - Verifica se o utilizador abortou a pesquisa.
#           d_scr_createTemp()  - Cria a tabela temporaria.
#           d_scr_CountReg()    - Conta os eegistos encontrados na busca.
#           d_scr_ant_rowid()   - Posiciona no rowid anterior.
#           d_scr_seg_rowid()   - Posiciona no rowid seguinte.
#           d_scr_p_rowid()     - Posiciona no primeiro rowid.
#           d_scr_u_rowid()     - Posiciona no ultimo rowid.
#
#  ----------------------------------------------------------------
#  FORMS:
#  REPORTS:
#
#  NOTAS:
#
#  ============================================================================
#database despodata
database sysmaster


GLOBALS "4glsrc/functions_4gl/d_libglob.4gl"

define
	usa_tabelas smallint    # Se a true pode-se utilizar as tabelas do pr_scr_ctl

#  ============================================================================ 
#  Inicialicao de ecrans.
#      Incrementa o pointer de entradas de dados 
#      (para entradas de dados encadeadas).
#  ENTRADAS:
#            Titulo.
#  ============================================================================ 
function d_scr_init(titulo)
{}
  define 
	 titulo char(64)

  WHENEVER ERROR CALL d_erro
  let scr_pointer = scr_pointer + 1
  let pr_scr_ctl[scr_pointer].registos = 0 
	call d_scr_titulo(titulo)
	call d_init_user()
end function

#  ============================================================================ 
#  Mostra o titulo da janela
#  ============================================================================ 
function d_scr_titulo(titulo)
{}
  define 
	 titulo char(64),
	 tam    smallint,
	 col    smallint,
	 anostr char(4)

   WHENEVER ERROR CALL d_erro

   display titulo at 1,2
	if pr_empresa.nome is null then
      whenever error continue
      declare cr_prop cursor for
	     select nome, morada, localidade from d_proprietario
	   open cr_prop
	   case
		   when status = 0
	         fetch cr_prop into pr_empresa.nome, pr_empresa.morada, 
							          pr_empresa.localidade
	         close cr_prop
		   when status = -206
			   let anostr = year(today)
            let pr_empresa.nome = "(c) Despodata ",anostr using "<<<<"
		   otherwise 
			   call d_erro()
	   end case
	   whenever error call d_erro
	end if
	let tam = length(pr_empresa.nome)
	let col = 78 - tam
	
   display pr_empresa.nome clipped at 1,col 
   call fgl_drawbox(1,77,2,1)
   display "  " at 2,1
   display " " at 2,77
end function



function 	 d_init_scr()
{}
	# Utiliza sempre transacoes
   let d_ut_tr = true

	# Para controle de d_erro
   let d_accao = "INA"

	# Pointer de encadeamento de entradas de dados
   let scr_pointer = 0
end function




#  ============================================================================ 
#  Declaracao do cursor que recebe os rowids.
#      Cursor de rowids    : cr_rowid
#      Statement utilizado : stat_ins_rowid
#  ============================================================================ 
function d_scr_OpCrRowid()
{}
  define
	 str_stat_rowid char(100)
  
  let str_stat_rowid = "select linhaid, ordenacao from ",
								pr_scr_ctl[scr_pointer].nome_tab_rowid clipped,
								" order by 2"
  prepare stat_rowid from str_stat_rowid
  DECLARE cr_rowid SCROLL CURSOR FOR stat_rowid
  open cr_rowid
end function

#  ============================================================================ 
#  Isto agora testa se da erro a fazer fetch (cursor aberto) 
#  pois houve um brincalhao a retirar a reabertura do cursor
#  e se xse mete ha uma data de programas que deixam de funcionar
#  ============================================================================ 
function d_scr_mete_bem()
	whenever error continue
  fetch absolute pr_scr_ctl[scr_pointer].reg_corrente
                 cr_rowid into pr_scr_ctl[scr_pointer].rowid_curr
	case
    when sqlca.sqlcode = 0
			whenever error call d_erro
    when sqlca.sqlcode = -400 
			whenever error call d_erro
      call d_scr_OpCrRowid()
      fetch absolute pr_scr_ctl[scr_pointer].reg_corrente
                   cr_rowid into pr_scr_ctl[scr_pointer].rowid_curr
		otherwise
			call d_erro()
	end case
end function


#  ============================================================================ 
#  Quando se sai de uma entrada de dados deve-se executar esta opcao.
#  ============================================================================ 
function d_scr_end()
  if scr_pointer > 1 then
     close  cr_rowid
     let scr_pointer = scr_pointer - 1
     call d_scr_OpCrRowid()
     # Atencao a optimizacao - a funcao OpCrRowid ja faz fetch
     fetch absolute pr_scr_ctl[scr_pointer].reg_corrente
                 cr_rowid into pr_scr_ctl[scr_pointer].rowid_curr
  end if
end function

#  ============================================================================ 
#  Funcao de gestao da pesquisa.
#    ENTRADAS : Registo de controle de entrada de dados.
#  ============================================================================ 

function d_scr_pes()
{}

  call d_scr_espere()
  # Criar a tabela temporaria.
  call d_scr_createTemp()

  # Inserir na temporaria de rowids.
  call d_scrInsertRowid()

  call d_scr_nao_espere()

  # Contar os registos. 
  call d_scr_CountReg()
  # Tirar daqui este teste, e' testado atras
  if pr_scr_ctl[scr_pointer].registos = 0 then
	 return false
  end if

  call d_scr_OpCrRowid()

  # Posicionar no primeiro elemento.
  fetch first cr_rowid into pr_scr_ctl[scr_pointer].rowid_curr
  LET pr_scr_ctl[scr_pointer].reg_corrente = 1
  return true

end function


#  ============================================================================ 
#  Seleciona o posicionamento correcto do rowid.
#  ============================================================================ 
function d_scr_pos_rowid(tipo)
{}
  define
	 tipo char(1),
	 ans smallint

  case 
	 when tipo="M"
      let ans = d_scr_menu_posicionamento()

	 when tipo="A"
      let ans = d_scr_ant_rowid()

	 when tipo="S"
      let ans = d_scr_seg_rowid()

	 when tipo="P"
      let ans = d_scr_p_rowid()

	 when tipo="U"
      let ans = d_scr_u_rowid()

	 when tipo="D"
      let ans =  d_scr_posDirecto()

	 otherwise
		let ans = false
  end case

  return ans
end function


#  ============================================================================ 
#  Posicionamento no elemento corrente.
#  ============================================================================ 
function 	 d_scr_ele_curr()
{}
   fetch absolute pr_scr_ctl[scr_pointer].reg_corrente cr_rowid into 
					  pr_scr_ctl[scr_pointer].rowid_curr
end function

#  ============================================================================ 
#  Posicionamento directo por menu vertical
#  ============================================================================ 
function 	 d_scr_menu_posicionamento()
{}
  define
	  ans smallint

  # Menu vertical 
  let ans = menuVertCasc(5,20,6,"","","","Anterior (<)",
										             "Seguinte (>)",
										             "Primeiro (F4)",
										             "Ultimo   (F3)",
										             "Directo  (F2)",
				                               "Fim",
										             "","","","","","","",
														 "","","","","","")
    case
	   when ans = 1
        let ans = d_scr_ant_rowid()

	   when ans = 2
        let ans = d_scr_seg_rowid()

	   when ans = 3
        let ans = d_scr_p_rowid()

	   when ans = 4
        let ans = d_scr_u_rowid()

	   when ans = 5
        let ans =  d_scr_posDirecto()

	   otherwise
		  let ans = false
    end case
   return ans
end function


#  ============================================================================ 
#  Posiciona elemento seguinte do cursor dos rowid's.
#  ============================================================================ 
function d_scr_seg_rowid()
{}
  define
	 mensagem char(200)

  if d_scr_Select() = false then
	 return false
  end if

  fetch next cr_rowid into pr_scr_ctl[scr_pointer].rowid_curr
  if status = notfound then
	 let mensagem = pr_scr_ctl[scr_pointer].nomeRegs clipped
	 call d_dialogOk(9,15,"","Nao ha mais",mensagem,"seguintes","","")
	 return false
  else
    LET pr_scr_ctl[scr_pointer].reg_corrente = 
						 pr_scr_ctl[scr_pointer].reg_corrente + 1
	 return true
  end if
end function 


function d_scr_nxt_rowid()
{}
  fetch next cr_rowid into pr_scr_ctl[scr_pointer].rowid_curr
end function 


#  ============================================================================ 
#  Posiciona elemento anterior do cursor dos rowid's.
#  ============================================================================ 
function d_scr_ant_rowid()
{}
  DEFINE
	 mensagem char(200)

  if d_scr_Select() = false then
	 return false
  end if

  fetch previous cr_rowid into pr_scr_ctl[scr_pointer].rowid_curr
  if status = notfound then
	 let mensagem = pr_scr_ctl[scr_pointer].nomeRegs clipped
	 call d_dialogOk(9,15,"","Ja nao ha mais",mensagem,"anteriores","","")
	 return false
  else
    LET pr_scr_ctl[scr_pointer].reg_corrente = pr_scr_ctl[scr_pointer].reg_corrente - 1
	 return true
  end if
end function 







#  ============================================================================ 
#  Posiciona primeiro elemento do cursor dos rowid's.
#  ============================================================================ 
function d_scr_p_rowid()
{}
  if d_scr_Select() = false then
	 return false
  end if
  fetch first cr_rowid into pr_scr_ctl[scr_pointer].rowid_curr
  let pr_scr_ctl[scr_pointer].reg_corrente = 1
  return true
end function 







#  ============================================================================ 
#  Posiciona ultimo elemento do cursor dos rowid's.
#  ============================================================================ 
function d_scr_u_rowid()
{}
  if d_scr_Select() = false then
	 return false
  end if
  fetch last cr_rowid into pr_scr_ctl[scr_pointer].rowid_curr
  let pr_scr_ctl[scr_pointer].reg_corrente = 
		pr_scr_ctl[scr_pointer].registos
  return true
end function 






#  ============================================================================ 
#  Inserir na tabela temporaria de acordo com a ordenacao pedida.
#  Optimizar. Se ja tiver sido preparado nao preparar outra vez.
#
#  Preparar o statement de insercao dos rowids.
#  Entradas :
#      str_stat - String onde vem definido o statement
#  Statement preparado :
#      stat_rowid
#  Atencao as transacoes.
#  ============================================================================ 
function 	 d_scrInsertRowid()
{}
  define
	 str_stat   char(128),
	 str_select char(5000),
	 linhaid    integer,
	 tabs       char(256),
	 dummy      char(128)
	
   options
		sql interrupt on

   if usa_tabelas = false then
	  let tabs = pr_scr_ctl[scr_pointer].tabela
   else
		if pr_scr_ctl[scr_pointer].tabelas is null then
	      let tabs = pr_scr_ctl[scr_pointer].tabela
		else
	      let tabs = pr_scr_ctl[scr_pointer].tabela clipped, ",",
					     pr_scr_ctl[scr_pointer].tabelas
		end if
   end if


   if pr_scr_ctl[scr_pointer].order_by is not null then
     let str_select= " select ", pr_scr_ctl[scr_pointer].tabela clipped, 
							".rowid, ",pr_scr_ctl[scr_pointer].order_by clipped,
						   " from ", tabs clipped,
					      " where ",pr_scr_ctl[scr_pointer].str_where clipped,
					      " order by ",pr_scr_ctl[scr_pointer].order_by clipped
     prepare stat_select from str_select

     let str_stat = "insert into ",
						  pr_scr_ctl[scr_pointer].nome_tab_rowid clipped, 
					      " (linhaid) values (?)" 
     prepare stat_ins_rowid from str_stat
     declare cr_sel_ord cursor for stat_select
     let pr_scr_ctl[scr_pointer].registos =  0
	  let int_flag = false
	  whenever error continue
     foreach cr_sel_ord into linhaid, dummy
		  if status != 0 and status != -213 then
			  call d_erro()
		  end if
		  if int_flag then
	        call d_dialogOk(9,15,"","PESQUISA ABORTADA","","","","")
			  exit foreach
		  end if
        let pr_scr_ctl[scr_pointer].registos =  1 +
            pr_scr_ctl[scr_pointer].registos
	     execute stat_ins_rowid using linhaid
     end foreach
     close cr_sel_ord
	else
	  # Optimizado para sem ordenacao.
     let str_select = "insert into ",
						    pr_scr_ctl[scr_pointer].nome_tab_rowid clipped, 
					       " (linhaid) select ",
                      pr_scr_ctl[scr_pointer].tabela clipped, 
							 ".rowid ",
							 " from ", tabs clipped,
					       " where ",pr_scr_ctl[scr_pointer].str_where clipped
     prepare stat_ins_rowid2 from str_select
	  execute stat_ins_rowid2
	  if status != 0 and status != -213 then
        call d_erro()
	  end if
     if int_flag then
	     call d_dialogOk(9,15,"","PESQUISA ABORTADA","","","","")
	  end if
     let pr_scr_ctl[scr_pointer].registos = sqlca.sqlerrd[3]
	end if
end function




#  ============================================================================ 
#  Verifica se o utilizador abortou a insercao
#  ============================================================================ 
function d_scr_inpAbortada()
{}
  IF int_flag = true THEN
    LET int_flag = FALSE
	 call d_dialogOk(9,15,"",
			"INSERCAO ABORTADA","","","","")
    RETURN(true)
  END IF
  return(false)
end function

#  ============================================================================ 
#  Pergunta ao utilizador se quer mesmo abortar a insercao
#  ============================================================================ 
function d_scrAbortaInsercao()
{}
		define ans smallint

		if d_dialog(9,15,"NAO","SIM","","","Quer mesmo cancelar","",
												  "","?","") = 1 then
			 return false
		else
			 return true
		end if
end function

#  ============================================================================ 
#  Verifica se o utilizador abortou uma pesquisa.
#  ============================================================================ 
function pesquisa_abortada()
{}
  IF int_flag = true THEN
    LET int_flag = FALSE
	 call d_dialogOk(9,15,"",
			"PESQUISA ABORTADA","!","","","")
    RETURN(true)
  END IF
  return(false)
end function

#  ============================================================================ 
#  Verifica se o utilizador abortou a modificacao
#  ============================================================================ 
function d_scr_updAbortada()
{}
  IF int_flag = true THEN
    LET int_flag = FALSE
	 call d_dialogOk(9,15,"",
			"MODIFICACAO ABORTADA","","","","")
    RETURN(true)
  END IF
  return(false)
end function




#  ============================================================================ 
#  Verifica se o utilizador abortou a pesquisa
#  ============================================================================ 
function d_scr_pesAbortada()
{}
  IF int_flag THEN
    LET int_flag = FALSE
	 call d_dialogOk(9,15,"",
			"PESQUISA ABORTADA","","","","")
    RETURN(true)
  END IF
  return(false)
end function



#  ============================================================================ 
#  Verifica se o utilizador abortou o posicionamento directo
#  ============================================================================ 
function d_scr_dirPosAbortada()
{}
  IF int_flag THEN
    LET int_flag = FALSE
	 call d_dialogOk(9,15,"",
			"POSICIONAMENTO DIRECTO ABORTADO","","","","")
    RETURN(true)
  END IF
  return(false)
end function



#  ============================================================================ 
#  Cria a tabela temporaria que vai ter os rowid's
#  ============================================================================ 
function d_scr_createTemp()
{}
  define 
	 str_create char(200),
	 ptrstr     char(2)

  if pr_scr_ctl[scr_pointer].nome_tab_rowid is null then
	 let ptrstr = scr_pointer using "<<"
    let pr_scr_ctl[scr_pointer].nome_tab_rowid = "tabrowid_", ptrstr
    let str_create = " create temp table ",pr_scr_ctl[scr_pointer].nome_tab_rowid, 
							" ( linhaid integer, ordenacao serial)"
    prepare stat_create from str_create
    execute stat_create
    let str_create = " create unique index idx_linhaid_", ptrstr,
						   " on ",
							pr_scr_ctl[scr_pointer].nome_tab_rowid clipped,
							" ( linhaid )"
    prepare stat_index from str_create
    execute stat_index
    let str_create = " drop index idx_linhaid "
	 prepare stat_idrop from str_create
  else
	 #execute stat_idrop
    #let str_create = " drop table ",pr_scr_ctl[scr_pointer].nome_tab_rowid
    #prepare stat_drop from str_create
    #execute stat_drop
    let str_create = " delete from ",pr_scr_ctl[scr_pointer].nome_tab_rowid
    prepare stat_delete from str_create
    execute stat_delete
    #execute stat_create
    #execute stat_index
  end if

	
end function




#  ============================================================================ 
#  Conta o numero de registos que estao na tabela de rowid's. 
#  Tentar que a versao 4.1 ja va a estrutura sqlca.
#  ============================================================================ 
function d_scr_CountReg()
{}
  define
	 nome_registos char(60),
	 mesg1 char(60),
	 mesg2 char(60),
	 mesg3 char(60)

  {
  let pr_scr_ctl[scr_pointer].registos = 
					  d_count(pr_scr_ctl[scr_pointer].nome_tab_rowid,"1 = 1")
					  }

  if pr_scr_ctl[scr_pointer].nomeRegs is null then
	 let nome_registos="registos"
  else
	 let nome_registos=pr_scr_ctl[scr_pointer].nomeRegs clipped
  end if

  case 
	 when pr_scr_ctl[scr_pointer].registos = 0
	   let mesg1	= "Nao ha"
	   let mesg2	= nome_registos clipped
	   let mesg3 = " que cumpram os parametros"
      call d_dialogOk(9,15,"",mesg1,mesg2,mesg3,"","")

	 {
	 when pr_scr_ctl[scr_pointer].registos = 1
	   let mesg1 = "Foi selecionado "
		let mesg2 = "1 ", nome_registos

	 otherwise
	   let mesg1 = "Foram selecionados "
		let mesg2 = pr_scr_ctl[scr_pointer].registos using "<<<"
		let mesg3 = nome_registos
		}
  end case


end function



#  ============================================================================ 
#  Insere um rowid na tabela temporaria
#  Ver a optimizacao da insercao.
#  ============================================================================ 
function d_scr_ins_rowid(linhaid)
{}
  define
	 linhaid integer,
	 str_insert char(1000)

  if pr_scr_ctl[scr_pointer].nome_tab_rowid is null then
    call d_scr_createTemp()
  end if

  let str_insert = " insert into ",
						 pr_scr_ctl[scr_pointer].nome_tab_rowid clipped,
						 " ( linhaid ) values (?)"
  prepare stat_ins from str_insert
  execute stat_ins using linhaid
   let d_status = status
   if status != 0 then
	  return
   end if
	
  # Actualizar cursor de rowid's
  if pr_scr_ctl[scr_pointer].registos != 0 and 
	  pr_scr_ctl[scr_pointer].registos is not null then
    close  cr_rowid
    open   cr_rowid
  else
	 { Atencao a remocao de todos os elementos
	 whenever error continue
	 close cr_rowid
	 whenever error call d_erro
	 }
    call d_scr_OpCrRowid()
  end if

  # Posicionar no rowid inserido
  fetch first cr_rowid into pr_scr_ctl[scr_pointer].rowid_curr
  let pr_scr_ctl[scr_pointer].reg_corrente = 1
  while status = 0
	  if pr_scr_ctl[scr_pointer].rowid_curr = linhaid then
		  exit while
	  end if
     fetch next cr_rowid into pr_scr_ctl[scr_pointer].rowid_curr
     let pr_scr_ctl[scr_pointer].reg_corrente = 
			pr_scr_ctl[scr_pointer].reg_corrente + 1
  end while
  # Actualizar contadores.
  let pr_scr_ctl[scr_pointer].registos = pr_scr_ctl[scr_pointer].registos+1
  #fetch first cr_rowid into pr_scr_ctl[scr_pointer].rowid_curr #LIXO ???
  call d_scr_disp_count()
   let status = d_status
end function





#  ===============================================================
#  Remocao de elementos
#  ===============================================================
function d_scr_rm()
{}
  define
	 ans smallint

  if d_scr_Select() = false then
	 return 
  end if

  # Menu vertical 
  while 1=1
    let ans = menuVertCasc(5,34,3,"","","","Corrente","Seleccionados","Fim",
				  "","","","","","","","","","","","","","","","")
    case
	   when ans = 1
		  call d_scr_rm_curr()
	   when ans = 2
		  call d_scr_rm_sel()
	   when ans = 3
		  exit while
		when ans = 0
		  exit while
	   otherwise
		  call d_dialogOk(9,15,"","","       Unrecoverable Application Error","","","")
    end case
  end while

end function


function d_scr_rm1()
{}
  define
	 ans smallint

  if d_scr_Select() = false then
	 return 
  end if

  # Menu vertical 
  while 1=1
    let ans = menuVertCasc(5,34,2,"","","","Corrente","Fim","",
				  "","","","","","","","","","","","","","","","")
    case
	   when ans = 1
		  call d_scr_rm_curr()
	  # when ans = 2
	#	  call d_scr_rm_sel()
	   when ans = 2
		  exit while
		when ans = 0
		  exit while
	   otherwise
		  call d_dialogOk(9,15,"","","       Unrecoverable Application Error","","","")
    end case
  end while

end function

#
#  Fecha o cursor de rowids
#

function   d_scr_close_cr_rowid()
{}
   close cr_rowid
end function


#
# Abre o cursor de rowids
#

function 	 d_scr_open_cr_rowid()
{}
   open cr_rowid
   fetch absolute pr_scr_ctl[scr_pointer].reg_corrente cr_rowid into 
					  pr_scr_ctl[scr_pointer].rowid_curr
end function



#  ===============================================================
#  Remove o elemento corrente
#  ===============================================================
function d_scr_rm_curr()
{}
  define
	 str_rm char(100)

  if d_scr_conf_rm(1) = false then
	 call d_dialogOk(9,15,"",
			"REMOCAO ABORTADA","","","","")
	 return
  end if

  # Remover elemento
  let str_rm = "delete from ",pr_scr_ctl[scr_pointer].tabela clipped,
					" where rowid=?"
  prepare stat_rm from str_rm
  call d_begin_work() 
  execute stat_rm using pr_scr_ctl[scr_pointer].rowid_curr
  # Testar esta historia do status
  if status != 0 then
	 call d_rollback_work()
	 return
  end if

  # Remover da tabela de rowid's
  let str_rm = "delete from ",pr_scr_ctl[scr_pointer].nome_tab_rowid clipped,
					" where linhaid=?"
  prepare stat_rmrowid from str_rm
  execute stat_rmrowid using pr_scr_ctl[scr_pointer].rowid_curr
  if status != 0 then
	 call d_rollback_work()
	 return
  else
    call d_commit_work()
  end if

  clear form

  # Fechar e abrir o cursor
  close cr_rowid
  open cr_rowid

  # Actualizar contadores
  if pr_scr_ctl[scr_pointer].registos = pr_scr_ctl[scr_pointer].registos > 0 then
     let pr_scr_ctl[scr_pointer].registos = pr_scr_ctl[scr_pointer].registos - 1
  end if

  if pr_scr_ctl[scr_pointer].reg_corrente >= 1 then
    let pr_scr_ctl[scr_pointer].reg_corrente = 
							  pr_scr_ctl[scr_pointer].reg_corrente - 1
  end if

  fetch absolute pr_scr_ctl[scr_pointer].reg_corrente cr_rowid into 
					  pr_scr_ctl[scr_pointer].rowid_curr

  call d_scr_disp_count()

end function


function d_rm_tabela_rowid()
{}
   define
	   str_rm char(100)

   call d_begin_work() 

   # Remover da tabela de rowid's
   let str_rm = " delete from ",pr_scr_ctl[scr_pointer].nome_tab_rowid clipped,
					 " where linhaid = ? "
   prepare stat_taberowid from str_rm
   execute stat_taberowid using pr_scr_ctl[scr_pointer].rowid_curr
 
   if status != 0 then
	   call d_rollback_work()
	   return
   else
      call d_commit_work()
   end if
 
   clear form
 
   # Fechar e abrir o cursor
   close cr_rowid
   open cr_rowid

   # Actualizar contadores
   if pr_scr_ctl[scr_pointer].registos > 0 then
      let pr_scr_ctl[scr_pointer].registos = pr_scr_ctl[scr_pointer].registos - 1
   end if
 
   if pr_scr_ctl[scr_pointer].reg_corrente > 1 then
      let pr_scr_ctl[scr_pointer].reg_corrente = pr_scr_ctl[scr_pointer].reg_corrente - 1
   end if
 
   fetch absolute pr_scr_ctl[scr_pointer].reg_corrente cr_rowid into 
					   pr_scr_ctl[scr_pointer].rowid_curr
 
   call d_scr_disp_count()
 
end function


#  ===============================================================
#  Remove o elemento corrente sem fazer pergunta
#  ===============================================================
function d_scr_rm_corrente()
{}
  define
	 str_rm char(100)

  # Remover elemento
  let str_rm = "delete from ",pr_scr_ctl[scr_pointer].tabela clipped,
					" where rowid=?"
  prepare stat_rmcorrente from str_rm
  call d_begin_work() 
  execute stat_rmcorrente using pr_scr_ctl[scr_pointer].rowid_curr
  # Testar esta historia do status
  if status != 0 then
	 call d_rollback_work()
	 return
  end if

  # Remover da tabela de rowid's
  let str_rm = "delete from ",pr_scr_ctl[scr_pointer].nome_tab_rowid clipped,
					" where linhaid=?"
  prepare stat_rmrowidcorrente from str_rm
  execute stat_rmrowidcorrente using pr_scr_ctl[scr_pointer].rowid_curr
  if status != 0 then
	 call d_rollback_work()
	 return
  else
    call d_commit_work()
  end if

  clear form

  # Fechar e abrir o cursor
  close cr_rowid
  open cr_rowid

  # Actualizar contadores
  if pr_scr_ctl[scr_pointer].registos = pr_scr_ctl[scr_pointer].registos > 0 
  then
     let pr_scr_ctl[scr_pointer].registos = pr_scr_ctl[scr_pointer].registos - 1
  end if

  if pr_scr_ctl[scr_pointer].reg_corrente >= 1 then
    let pr_scr_ctl[scr_pointer].reg_corrente = 
							  pr_scr_ctl[scr_pointer].reg_corrente - 1
  end if

  fetch absolute pr_scr_ctl[scr_pointer].reg_corrente cr_rowid into 
					  pr_scr_ctl[scr_pointer].rowid_curr

  call d_scr_disp_count()
end function


#  ===============================================================
#  Remove todos os elementos selecionados
#  ===============================================================
function d_scr_rm_sel()
  define
	 str_rm char(100)

  if d_scr_conf_rm(2) = false then
	 call d_dialogOk(9,15,"",
			"         REMOCAO ABORTADA","","","","")
	 return
  end if

  call d_begin_work() 

  fetch first cr_rowid into pr_scr_ctl[scr_pointer].rowid_curr
  while status = 0 
    # Remover elemento
    let str_rm = "delete from ",pr_scr_ctl[scr_pointer].tabela clipped,
					  " where rowid=?"
    prepare stat_rmc from str_rm
    execute stat_rmc using pr_scr_ctl[scr_pointer].rowid_curr
  
    # Testar lock's ! Acho que o derro resolve este problema.

    if status != 0 then
	   call d_rollback_work()
	   call d_dialogOk(9,15,"",
			"REMOCAO MAL SUCEDIDA","","","","")
		return
	 end if

    fetch next cr_rowid into pr_scr_ctl[scr_pointer].rowid_curr
  end while

  call d_rm_rowids()
  if status = 0 then
     call d_commit_work()
  else
	  call d_rollback_work()
	  call d_dialogOk(9,15,"",
			"REMOCAO DE ELEMENTOS","MAL SUCEDIDA","","","")
  end if

  call d_scr_reset_contadores()

  call d_scr_disp_count()
  clear form

end function

function d_scr_reset_contadores()
  # Actualizar contadores
  let pr_scr_ctl[scr_pointer].registos = 0
  let pr_scr_ctl[scr_pointer].reg_corrente = 0
  let pr_scr_ctl[scr_pointer].rowid_curr = 0
  call d_scr_disp_count()
end function



#
# Remove os elementos selecionados da tabela de rowids
#

function d_rm_rowids()
  define
	 str_del char(100)

  let str_del = "delete from ",pr_scr_ctl[scr_pointer].nome_tab_rowid clipped
  prepare stat_delrowid from str_del
  execute stat_delrowid 
end function


#  ============================================================================ 
#  pede a confirmacao da remocao 
#  ============================================================================ 
function d_scr_conf_rm(tipo_rm)
{}
  define 
	 tipo_rm smallint

  case
	 when  tipo_rm = 1
		if d_dialog(9,15,"NAO","SIM","","","QUER MESMO REMOVER","",
												  "O ELEMENTO CORRENTE","?",
		"") = 1 then
			 return false
		else
			 return true
		end if
	 when  tipo_rm = 2
		if d_dialog(9,15,"NAO","SIM","","",
					 "QUER MESMO REMOVER","",
					 "TODOS OS ELEMENTOS SELECCIONADOS","?","") = 2 then
		   if d_dialog(9,15,"CANCELAR","OK","","","",
					 "TODOS OS ELEMENTOS SELECCIONADOS",
					 "","SERAO REMOVIDOS","") = 1 then
			  return false
			else
			  return true
			end if
		else
			 return false
		end if
	 otherwise
	   call d_dialogOk(9,15,"","",
			"UNRECOVERABLE APPLICATION ERROR","","","")
		exit program
  end case
end function




#  ============================================================================ 
#  Posicionamento directo pelo campo da form.
#  ============================================================================ 
function d_scr_posDirecto()
  define 
	 mensagem     char(100),
	 mensagem1    char(100),
	 mensagem2    char(100),
	 RegCorrente  smallint

  if d_scr_Select() = false then
	 return false
  end if

  let RegCorrente = pr_scr_ctl[scr_pointer].reg_corrente

  whenever error continue
  input by name RegCorrente without defaults
	 on key(CONTROL-G) 
		call d_scr_win_id()

	 after field RegCorrente
		if RegCorrente > pr_scr_ctl[scr_pointer].registos or RegCorrente <= 0 then
		  let mensagem1 = column(19)
		  let mensagem2 = "entre 1 e ", 
							    pr_scr_ctl[scr_pointer].registos using "<<<"
		  let mensagem  = mensagem1 clipped, mensagem2 clipped
		  call d_dialogOk(9,15,"",
			"           Tem de introduzir um numero",mensagem,"","","")
		  next field RegCorrente
		end if
	  after input
        LET pr_scr_ctl[scr_pointer].reg_corrente = RegCorrente
  end input
   case
	  when status = 0
		  exit case
      when status = -1102
			call d_scr_other_input()
		otherwise
			call d_erro()
   end case
	whenever error call d_erro

  if d_scr_dirPosAbortada() = true then
	  let RegCorrente = pr_scr_ctl[scr_pointer].reg_corrente
	  display by name RegCorrente
	  return false
  end if

  fetch absolute RegCorrente cr_rowid into pr_scr_ctl[scr_pointer].rowid_curr
  # Falta testar os erros.
  return true
end function


#  ============================================================================ 
#  Input alternativo para o posicionamento directo.
#  ============================================================================ 
function 	 d_scr_other_input()
{}
   open window w_reg at 6, 61 with 1 rows, 5 columns attribute(reverse)
   prompt "" for
          pr_scr_ctl[scr_pointer].reg_corrente
	close window w_reg
	call d_scr_disp_count()
end function


#  ============================================================================ 
#  Verifica se ha registos seleccionados
#  ============================================================================ 
function d_scr_Select()
{}
  define
	 mesg1 char(78),
	 mesg2 char(78),
	 mesg3 char(78)

  if pr_scr_ctl[scr_pointer].registos <= 0 then
	 if pr_scr_ctl[scr_pointer].nomeRegs is null then
		let mesg2="Nao ha registos seleccionados"
	   let mesg3="Tem de executar uma busca ou uma insercao"
	 else
	   let mesg1="Nao ha"
	   let mesg2=pr_scr_ctl[scr_pointer].nomeRegs clipped
	   let mesg3="seleccionadas(os)"
	 end if
	 call d_dialogOk(9,15,"",mesg1,mesg2,mesg3,"","")
	 return false
  end if
  return true
end function




function d_scr_Erro(accao,stat)
{}
  define
	 accao char(3),
	 stat smallint,
	 msg1 char(48),
	 msg2 char(48),
	 msg3 char(48)

  case
	 when accao="Ins"
		let msg1="        E impossivel aceder a\' tabela"
	 when accao="Del"
		let msg1="    E impossivel remover elemento da tabela"
	 when accao="Dev"
		let msg1="     E impossivel remover elemento da lista"
  end case

  case
	 when stat = 0
	 when stat = -263
		let msg2="       Provavelmente alguem o bloqueou "
		let msg3="  Consulte o seu admnistrador da base de dados"

	 when stat = -242
		let msg2="       Provavelmente alguem a bloqueou "
		let msg3="  Consulte o seu admnistrador da base de dados"
	 otherwise
		let msg1="Status :",stat
  end case
  call d_dialogOk(9,15,"",msg1,msg2,"",msg3,"")
end function


function d_runsh()
  define 
	 comm     char(64)
#	 pr_aplic record like aplic.*
#| The symbol "table-name" is not the name of a table in the
#| specified database.
#| See error number -4320.


display "FIXME: missing database"
exit program (5)


{
  select * into pr_aplic.*
  from aplic

  if pr_aplic.flag_shell matches"[Ss]*" then
     options
	    prompt line last

     prompt "!" for comm
     run comm
  end if

}

end function


# Mostra os contadores na form corrente.
function d_scr_disp_count()
{}
  whenever error continue
  display pr_scr_ctl[scr_pointer].reg_corrente , 
			 pr_scr_ctl[scr_pointer].registos 
	 to RegCorrente, totalRegs
	case
		when status = 0
			exit case
		when status = -1102
			call d_scr_disp_other_count()
		otherwise
			call d_erro()
	END CASE
   whenever error call d_erro
end function





#  ============================================================================ 
#  Funcao de display dos contadores alternativa, sem campos da form, mas
#  com janelas
#  ============================================================================ 
function 	 d_scr_disp_other_count()
{}
   display pr_scr_ctl[scr_pointer].reg_corrente using "#####" at 1,60 
		attribute(reverse)
	display "de" at 1, 67 
	display pr_scr_ctl[scr_pointer].registos  using "#####" at 1, 70 
		attribute(reverse)
end function




#
# Abre uma janela onde sera visualizada toda a identificacao do programa
# Falta dar a hora
#

function 	 d_scr_win_id()
{}
  define dia_de_hoje date,
			msg1 char(60),
			msg2 char(60),
			msg3 char(60),
			msg4 char(60),
			ans smallint

  let msg1 = "UTILIZADOR: ",d_user clipped
  let msg2 =  "TERMINAL:   ",d_tty clipped
  let msg3 =  ""
  let dia_de_hoje = today
  let msg4 =  "DATA:       ",dia_de_hoje using "DD/MM/YY" 
  let ans = d_dialog(9,15,"OK","UTILITARIOS","","",msg1,msg2,msg3,msg4,"")
  if ans = 2 then
     call d_scr_servicos()
  end if
end function



#  ============================================================================ 
#  Da ao utilizador hipotese de executar outros servicos
#  ============================================================================ 
function 	 d_scr_servicos()
{}
	 define 
		ans smallint,
		comm char(30)

    let ans = menuVertCasc(13,22,3,"","SERVIÇOS ADICIONAIS","",
														 "Spooler interactivo",
										             "Correio electrónico",
				                               "Fim",
										             "",
										             "",
										             "",
										             "","","","","","","",
														 "","","","","","")
   case
		when ans = 1
			let comm = "d_spooler"
			run comm
		when ans = 2
			run "mail"
		otherwise
	end case
end function

#
#  Mete uma pequena mensagem de espera
#

function 	 d_scr_espere()
{}
  call keep_mesg("Busca em execucao. Aguarde um momento !...")
end function



#
#  Tira mensagem de espera
#

function 	 d_scr_nao_espere()
{}
  call take_mesg()
end function



function 	 d_scr_acc_null(valor,coluna,tabela,descricao)
{}
   define
		valor     char(28),
		coluna    char(19),
		tabela    char(19),
		descricao char(64)

	if valor is null then
		if  d_accept_null(tabela,coluna) then
			CALL d_dialogOk(9,15,"",
			   "Tem de preencher o",
			   descricao,
			   "","","")
		end if
	end if
end function

#  ============================================================================ 
#  Mete as instrcoes para a insercao, apagando o menu.
#  ============================================================================ 
function 	 d_scr_ins_inst()
{}
   open window w_inst_ins at 3, 2 with 2 rows ,78 columns
	display "Insercao: ESC - Termina     CTRL-C - Aborta insercao" at 1, 1
	display "          CTRL+E - Ajuda    CTRL+W - Consulta" at 2, 1
end function

function 	 d_scr_end_ins_inst()
{}
   close window w_inst_ins
end function

#  ============================================================================ 
#  Mete as instrucoes para a modificacao, apagando o menu.
#  ============================================================================ 
function 	 d_scr_mod_inst()
{}
   open window w_inst_mod at 3, 2 with 2 rows ,78 columns
	display "Modificacao: ESC - Termina     CTRL-C - Aborta modificacao" at 1, 1
	display "             CTRL+E - Ajuda    CTRL+W - Consulta" at 2, 1
end function

function 	 d_scr_end_mod_inst()
{}
   close window w_inst_mod
end function


#  ============================================================================ 
#  Mete as instrcoes para a busca, apagando o menu.
#  ============================================================================ 
function 	 d_scr_find_inst()
{}
   open window w_inst_mod at 3, 2 with 2 rows ,78 columns
	display "Busca: ESC - Termina" at 1, 1
	display "       CTRL-C - Aborta a busca" at 2, 1
end function

function 	 d_scr_end_find_inst()
{}
   close window w_inst_mod
end function

function 	 d_scr_set_tabelas()
{}
   let usa_tabelas = true
end function

function 	 d_scr_reset_tabelas()
{}
   let usa_tabelas = false
end function
