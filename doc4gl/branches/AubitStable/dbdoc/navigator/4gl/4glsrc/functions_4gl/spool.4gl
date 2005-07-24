#  ============================================================================
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#
#  Divisao de desenvolvimento e producao de software.
#
#  Autor: sergio
#
#  Data de criacao: Tue Oct 20 10:38:59 LISBOA 1992
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : Spooler interactivo.
#  ---------------------------------------------------------------------------
#  DESCRICAO:  Faz a gestao interactiva de uma lista de espera de impressoes.
#              Ou trata apenas do interface de impressao de relatorios.
#
#  ---------------------------------------------------------------------------
#  FUNCOES: d_sp_get_novo_grupo()
#           d_sp_print_grupo()
#           d_sp_print()
#           d_sp_rm_grupo() - Remove o grupo e respectivas listagens.
#           d_existe_routing()
#
#  ---------------------------------------------------------------------------
#  FORMS:
#
#  REPORTS:
#
#  NOTAS: Todas as funcoes tem o sufixo _sp_.
#  .......Falta implementar Visualizar e configurar.
#         Retirar records like * em passagem de paramentros.
#  .......Falta tirar mensagens de impressao e ficheiros com nomes nao
#         existentes.
#
#  ============================================================================

#database despodata
database sysmaster

globals "4glsrc/functions_4gl/d_libglob.4gl"

define
	mete_mesg smallint,
   localizacao smallint,
	impressora_fixa char(14)  # Se esta variavel preenchida so permite
									  # uma impressora

#  ============================================================================ 
#  Inicializacao do sistema de impressoes
#  ============================================================================ 
function 	 d_sp_init()
{}
  let impressora_fixa = null
end function

#  ============================================================================ 
#  Adiciona um novo grupo de impressoes.
#  Devolve um novo numero para grupo.
#  ============================================================================ 
function 	 d_sp_get_novo_grupo()
{}
   define
		grupo    integer
#		pr_grupo record like lpgroup.*
#| The symbol "table-name" is not the name of a table in the
#| specified database.
#| See error number -4320.

display "FIXME: missing database"
exit program (4)

{

	#whenever error call d_erro

	# Este insert tem de ser de outra forma
   insert into lpgroup values (pr_grupo.*)

	if status = -206 then
		error "Criacao das tabelas de impressoes"
		call d_sp_create()
      insert into grupo values (pr_grupo.*)
	end if
}

	return(sqlca.sqlerrd[2])
end function



#  ============================================================================ 
#  Escreve a inicializacao do grupo.
#  ============================================================================ 
function d_sp_set_novo_grupo(pr_grupo)
{}
   define
   pr_grupo record
        x char(10),
		descricao char (10),
		d_today date,
		d_user char (20),
		y char (20),
		z char(20),
        w char (20)
   end record


#		pr_grupo   record like lpgroup.*
#| The symbol "table-name" is not the name of a table in the
#| specified database.
#| See error number -4320.

display "FIXME: missing database"
exit program (4)

{
	#whenever error call d_erro
	if pr_grupo.grupo is not null and pr_grupo.grupo != 0 then
      update lpgroup set (descricao,data_impr,owner,tipo_papel,pausa,remove) = 
						     (pr_grupo.descricao,    pr_grupo.data_impr,
							   pr_grupo.owner,        pr_grupo.tipo_papel,
							   pr_grupo.pausa,        pr_grupo.remove)
		   where lpgroup.grupo = pr_grupo.grupo
	end if

   if status != 0 or sqlca.sqlerrd[3] <= 0 or pr_grupo.grupo is null then
		whenever error continue
      insert into lpgroup (descricao,data_impr,owner,tipo_papel,pausa,remove) 
			values (pr_grupo.descricao,    pr_grupo.data_impr,
					  pr_grupo.owner,        pr_grupo.tipo_papel,
					  pr_grupo.pausa,        pr_grupo.remove)
		let pr_grupo.grupo = sqlca.sqlerrd[2]
	   if status = -206 then
		   error "Criacao das tabelas de impressoes"
		   call d_sp_create()
         insert into lpgroup (descricao,data_impr,owner,tipo_papel,pausa,remove) 
			   values (pr_grupo.descricao,    pr_grupo.data_impr,
						  pr_grupo.owner,        pr_grupo.tipo_papel,
						  pr_grupo.pausa,        pr_grupo.remove)
		   let pr_grupo.grupo = sqlca.sqlerrd[2]
		else
			if status != 0 then
			   call d_erro()
			end if
	   end if
		whenever error stop
      let mete_mesg = false
	end if

	return pr_grupo.grupo
}

    return 0

end function


#  ============================================================================
#  Desliga a mensagem que aparece para cada listagem a imprimir.
#  ============================================================================ 
function 	 d_sp_sem_mesg()
{}
   let mete_mesg = false
end function

#  ============================================================================ 
#  Imprime um grupo de impressao, da forma como definido.
#  ============================================================================ 
function 	 d_sp_print_grupo(num_grupo)
   define
   num_grupo integer
#		num_grupo   like lpgroup.grupo
#| The symbol "grupo" is not the name of a column in the
#| specified database.
#| See error number -4322.

display "FIXME: missing database"
exit program (4)


	call d_sp_print_grupo_n(num_grupo,1)
end function

function 	 d_sp_print_grupo_n(num_grupo,ncopias)
{}
   define
        num_grupo integer,
#		num_grupo   like lpgroup.grupo,
#| The symbol "grupo" is not the name of a column in the
#| specified database.
#| See error number -4322.
		ncopias     smallint,
		contador    smallint,
		lpcomm      char(128),
#		pr_lpgroup  record like lpgroup.*,
#| The symbol "table-name" is not the name of a table in the
#| specified database.
#| See error number -4320.
#		pr_lplist   record like lplist.*,
		ans         smallint,
		str1        char(60),
		str2        char(60),
		str3        char(60),
		str4        char(60),
		str5        char(60),
		str6        char(60),
		tudo_igual  smallint       # Indicador de tipo de papel igual para todas
											# as listagens.

display "FIXME: missing database"
exit program (4)

{
	initialize str1, str2, str3, str4, str5, str6 to null

	select grupo, descricao, data_impr, owner, tipo_papel, pausa, remove
		into  pr_lpgroup.*
		from  lpgroup
		where lpgroup.grupo = num_grupo

	if status = notfound then
		error "Grupo de impressao inexistente"
		sleep 2
		return
	end if


	#let d_impressora = "lp"
	let d_impr_nome = d_get_printer_name(impressora_fixa,pr_lpgroup.tipo_papel)
	if impressora_fixa is not null then
	  let d_impressora = impressora_fixa
	end if
	if d_impressora is null then
	   call d_dialogOk(9,15,str1,
			  "Impossivel determinar impressora",str3,"!",str5,"")
		return
	end if
   if  not d_sp_mesg_printer(2,pr_lpgroup.descricao,
									pr_lpgroup.owner,
									pr_lpgroup.data_impr)
	then
	   #call d_dialogOk(9,15,"","","Impressao enviada",
		                           #"para spooler interactivo","","")
	   call d_dialogOk(9,15,"","","Impressao cancelada","","","")
		return
	end if
   declare cr_group cursor for
		select listid, grupo, directoria, ficheiro, descricao 
			from  lplist
			where lplist.grupo = num_grupo
   open cr_group
	let lpcomm = ""
	if not mete_mesg then
      call d_wait(9,15,"","","A listagem vai a caminho","","!","")
	end if
	foreach cr_group into pr_lplist.*
		#if pr_lpgroup.pausa = "S" then
		   let lpcomm  = pr_lplist.ficheiro clipped
		#else
		   #let lpcomm  = lpcomm  clipped," ", pr_lplist.ficheiro clipped
		#end if
		for contador=1 to ncopias
			call d_sp_print(pr_lpgroup.*,lpcomm,mete_mesg)
		end for
		if mete_mesg = true then
			let mete_mesg = false
		end if
	end foreach
	if not mete_mesg then
      call d_no_wait()
	end if

	if lpcomm="" then
		error "Grupo de impressao sem listagens para imprimir"
		sleep 2
		return
	end if

}

end function


#  ============================================================================ 
#  Mete a mensagem de impressao e permite trocar a impressora.
#  Se tipo = 1 nao da opcao de mandar para spooler.
#  ============================================================================ 
function d_sp_mesg_printer(tipo,mesg,dono,data_impr)
{}
   define
		tipo smallint,
		mesg char(50),
		dono char(20),
		data_impr date,
		str1        char(60),
		str2        char(60),
		str3        char(60),
		str4        char(60),
		str5        char(60),
		str6        char(60),
		op1         char(10),
		op2         char(10),
		op3         char(10),
		ans smallint

	initialize str1, str2, str3, str4, str5, str6, op1, op2, op3 to null
	while ( 1=1 )
		#let str1 = "Impressao de:"
		let str2 = mesg
		if dono is not null then
		   let str4 = " Processado por ", dono clipped, " em ",
				data_impr
		else
		   let str4 = ""
		end if
		let str5 = ""
		let str6 = "Impressora: ", d_impr_nome  clipped
 
		let op1 = "Imprimir"
		let op2 = "Alterar"    # ??? Tem de se meter a chamar o gv ou o d_mostra
		let op3 = "Cancelar"
		{ Para ja e para agradar ao pessoal fica com o cancelar
		if tipo = 1 then
		   let op3 = ""
		else
		   let op3 = "Spooler"
		end if
		}
	   let ans = d_dialog(9,15,op1,op2,op3,str1,str2,str3,str4,str5,str6)
		case
			when ans = 1
		      exit while
			when ans = 3
				return false
			when ans = 2
		      call d_sp_choose_printer("")
			otherwise
		      exit while
		end case
   end while
	return true
end function


#  ============================================================================ 
#  Remove um grupo de impressao, removendo as respectivas listagens que dele
#  fazem parte.
#  A segundo argumento indica se deve remover ou nao os respectivos ficheiros.
#  ============================================================================ 
function 	 d_sp_rm_grupo(num_grupo,remove)
{}
   define
        num_grupo integer,
#		num_grupo   like lpgroup.grupo,
#| The symbol "grupo" is not the name of a column in the
#| specified database.
#| See error number -4322.
		remove char(1)
#		pr_lplist   record like lplist.*
  define retval smallint

display "FIXME: missing database"
exit program (4)

{
	if remove = "S" then
      declare cr_mylist cursor for
		   select listid, grupo, directoria, ficheiro, descricao
			   from  lplist
			   where lplist.grupo = num_grupo
      open cr_mylist
	   foreach cr_mylist into pr_lplist.*
			let retval = d_unlink(pr_lplist.ficheiro)
		end foreach
	end if
   delete from lpgroup where lpgroup.grupo = num_grupo
	delete from lplist where lplist.grupo = num_grupo

}

end function



#  ============================================================================ 
#  Imprime a lista de ficheiros que tem para imprimir.
#  ============================================================================ 
function 	 d_sp_print(pr_lpgroup,lplist,mete_mesg)
{}
   define
        pr_lpgroup record
            dummy char(1)
        end record,

#		pr_lpgroup  record like lpgroup.*,
#| The symbol "table-name" is not the name of a table in the
#| specified database.
#| See error number -4320.
		lplist      char(128),
		mete_mesg   smallint              # Flag que indica se deve meter mensagem

display "FIXME: missing database"
exit program (4)
{

   call d_sp_imprime(lplist,pr_lpgroup.tipo_papel,pr_lpgroup.remove,mete_mesg)

}
end function


#  ============================================================================ 
#  Imprime um ficheiro do qual se passa o nome e tipo de papel, metendo ou nao
#  uma mensagem e removendo-o ou nao
#  ============================================================================ 
function 	 d_sp_imprime(fich,tipo_pap,remove,mete_mesg)
{}
   define
		fich char(64),
		tipo_pap char(3),
		remove char(1),
		mete_mesg smallint,
#		desc_papel  like tipos_papel.descr,
#| The symbol "descr" is not the name of a column in the
#| specified database.
#| See error number -4322.
		comm        char(256),
		cond        char(64),
		str5        char(60),
		str4        char(60),
		str3        char(60),
		str2        char(60),
		ans         smallint,
		str1        char(60)

display "FIXME: missing database"
exit program (4)
{

	initialize str5, str4, str3, str2, str1 to null
	if mete_mesg then
	   let cond       = "tipos_papel.tipo=\"",tipo_pap clipped, "\""
	   let desc_papel = d_descodifica("tipos_papel","descr",cond)
	   if desc_papel is null then
		   case  
			   when tipo_pap = "EPS"
	            let str2 = " Coloque papel branco"
	            let str3 = " na impressora laser!..."
				otherwise
	            let str2 = " Coloque papel "
	            let str3 = " na impressora !..."
		   end case
	   else
	      let str2 = " Coloque ", desc_papel clipped
	      let str3 = " na impressora !..."
	   end if

	   call d_dialogOk(9,15,str1,str2,str3,str4,str5,"")
	end if
	call d_imprime(fich,tipo_pap)

	if remove="S" then
		let ans = d_unlink(fich)
	end if
}

end function

#  ============================================================================ 
#  Insere listagem no grupo enviado como argumento.
#  ============================================================================ 
function 	 d_sp_nova_listagem(num_grupo,ficheiro,desc)
{}
   define
		num_grupo   integer,
		ficheiro    char(64),
		desc        char(50)
   
	if num_grupo is null then
		error "Tentativa de inserir listagem em grupo invalido"
		sleep 2
		return
	end if
	insert into lplist (grupo,ficheiro,descricao)
		values
			(num_grupo, ficheiro, desc)

   # Nao esquecer de testar status, etc.
end function


#  ============================================================================ 
#  Imprime directamente um ficheiro sem o passar pelo  spooler.
#  ============================================================================ 
function 	 d_sp_imp_ja()
{}
end function



#  ============================================================================ 
#  Valida a existencia de tabelas de routing e se estao preenchidas para este
#  terminal.
#  ============================================================================ 
function 	 d_existe_routing()
{}
   return false
end function



#  ============================================================================ 
#  Cria as tabelas essenciais ao funcionamento das rotinas de spooling.
#  ============================================================================ 
function 	 d_sp_create()
{}
   create table lpgroup
	(
		grupo        serial,
		descricao    char(50),
		data_impr    date,
		owner        char(20),
		tipo_papel   char(3),
		pausa        char(1),
		remove       char(1)
	)

	create table lplist(
		listid      serial,
		grupo       integer,
		directoria  char(64),
		ficheiro    char(64),
		descricao   char(50)
	)

	create table tipos_papel(
		tipo    char(3),
		descr    char(30)
   )
end function


#  ============================================================================ 
#  Escolher impressora interactivamente.
#  Fazer lov a d_impressora, com uma eventual clausula de where.
#  ============================================================================ 
function 	 d_sp_choose_printer(tipo_papel)
{}
   define
        tipo_papel char(20),
#		tipo_papel like lpgroup.tipo_papel,
#| The symbol "tipo_papel" is not the name of a column in the
#| specified database.
#| See error number -4322.
#		where_ad   char(64),
                where_ad   char(200),
		dummy      char(20)

display "FIXME: missing database"
exit program (4)

{
	if tipo_papel = "EPS" then
		let where_ad = "d_printer.postscript=\"S\""
	else
		let where_ad = "1=1"
	end if

  if localizacao then
     let where_ad = where_ad clipped,
               "and impressora IN (select impressora from d_user_printer ",
               " where login = '", d_user, "')"
  end if


	call d_amor(8,12,2,3,false,false,"Impressoras de sistema","d_printer",
					"impressora",
					"nome",
					"",
					where_ad,
					"")
	returning d_impressora, d_impr_nome
  LET dummy = d_update_valor("IMPRESSORA_CURR",d_user,d_impressora)
}


end function

function set_localizacao()
{}
  let localizacao = TRUE
end function

#  ============================================================================ 
#  Fixa uma impressora para garantir que o utilizador nao escolhe outra
#  ============================================================================ 
function d_sp_fixa_impressora(nome_impressora)
{}
  define
	 nome_impressora char(14)
  let impressora_fixa = nome_impressora
end function


#  ============================================================================ 
#  Imprime um ficheiro
#  ============================================================================ 
function d_printFile(fileName,descricao)
	define fileName char(128)
	define descricao char(128)
	define grp_impressao smallint

	if d_user is null then
		call d_init_user()
	end if

  LET grp_impressao=d_sp_set_novo_grupo("",descricao,today,d_user,
																"","N","N")
  call d_sp_nova_listagem(grp_impressao,fileName,"Listagem")
  call d_sp_print_grupo(grp_impressao)
end function

#  ============================================================================ 
#  Imprime um ficheiro N vezes
#  ============================================================================ 
function d_printFile_n(fileName,descricao,ncopias)
	define fileName char(128)
	define descricao char(128)
	define ncopias smallint
	define grp_impressao smallint

	if d_user is null then
		call d_init_user()
	end if

  LET grp_impressao=d_sp_set_novo_grupo("",descricao,today,d_user,
																"","N","N")
  call d_sp_nova_listagem(grp_impressao,fileName,"Listagem")
  call d_sp_print_grupo_n(grp_impressao,ncopias)
end function
