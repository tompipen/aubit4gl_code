



#  ============================================================================
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#
#  Divisao de desenvolvimento e producao de software.
#
#  Autor: Joao Alexandre Costa
#
#  Data de criacao: Tue Jan 12 11:56:32 LISBOA 1993
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      :
#  ---------------------------------------------------------------------------
#  DESCRICAO:
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
#         Esta muito rebuscado. Tem de ser optimizado e repensado, deixando
#         compatibilidade.
#         Tem de se meter impressora de default, deste sistema de impressoes.
#         Falta meter os parametros de record like * em record like campos.
#
#  ============================================================================

globals "4glsrc/functions_4gl/d_libglob.4gl"

#  ============================================================================ 
#  Recebe o nome do ficheiro a imprimir e o seu tipo
#  ============================================================================ 
FUNCTION d_print(nome,tipo)
{}
  DEFINE nome CHAR(64),
			tipo CHAR(3)

	DEFINE 
		pr_d_routing RECORD 
			terminal char(50),
			impressora char(14)
		END RECORD,
		pr_d_printer RECORD
		  impressora char(14),
        nome char(64),
        tipo char(30),
        postscript char(1),
        remota char(1),
        nomesys char(14),
		  comando char(64)
      END RECORD,
		pr_d_routimpr RECORD 
         impresso char(3),
         impressora char(14)
		END RECORD,
		comando CHAR(256),
		ans SMALLINT,
		aux CHAR(128)
	
  whenever error call d_erro
	IF d_impressora IS NULL THEN
	  whenever error continue
	  SELECT terminal, impressora INTO pr_d_routing.*  FROM d_routing
	  WHERE  terminal=d_tty

	  if status = -206 then
		  call create_drouting()
	  end if

	  IF STATUS = 0 THEN
		 LET d_impressora=pr_d_routing.impressora
	  END IF
	  whenever error call d_erro
	  
	END IF

	IF tipo != "N" THEN
	  SELECT impressora INTO d_impressora FROM d_routimpr
	  WHERE impresso=tipo
	  IF STATUS = 0 THEN
		 LET d_impressora=pr_d_routimpr.impressora
	  END IF
	END IF

	whenever error continue
	SELECT impressora, nome, tipo, postscript, remota, nomesys, comando
		INTO pr_d_printer.* FROM d_printer
	WHERE d_printer.nome = d_impressora
	case 
		when status=100 
			declare cr_printer cursor for 
				select impressora, nome, tipo, postscript, remota, nomesys
			   from d_printer
			open cr_printer
			fetch cr_printer into pr_d_printer.*
			close cr_printer
			
		when status=-206
		   call create_dprinter()
	end case
	whenever error call d_erro

	if pr_d_printer.comando is null then
      LET aux = fgl_getenv("DBPRINT")
	   IF aux IS NULL THEN
	     LET aux="lpr "
	     #LET aux="lp -c -s "
	   END IF
	   if d_impressora is null then
		   let aux = aux clipped, " -P", d_impressora
		   #let aux = aux clipped, " -d", d_impressora
	   end if
	else
		let aux = pr_d_printer.comando
	end if


	# Se a impressora nao e postscript, procurar uma que seja
	#if tipo = "EPS" then
		#let aux = aux clipped, " -o raw "
	#end if

	IF pr_d_printer.nomesys IS NULL THEN
	  LET comando=aux CLIPPED," ",nome clipped
	ELSE
	  LET comando = "cat ",nome clipped," | rcmd ",
						      pr_d_printer.nomesys clipped," \"",
						      aux CLIPPED ," \""
	END IF
  LET comando = comando CLIPPED, " 2> /dev/null"

	#display "Comando impressao" , comando 
	#sleep 4
	LET ans=d_run(comando)

END FUNCTION


#  ============================================================================ 
#  Recebe o nome do ficheiro a imprimir e o seu tipo.
#  Imprime na impressora corrente.
#  ============================================================================ 
FUNCTION d_imprime(nome,tipo)
{}
  DEFINE nome CHAR(64),
			tipo CHAR(3),
			cap1, cap2  CHAR(30)    # Capabilities do termcap

	DEFINE 
		pr_d_printer RECORD
		  impressora char(14),
        nome char(64),
        tipo char(30),
        postscript char(1),
        remota char(1),
        nomesys char(14),
		  comando char(64)
      END RECORD,
		comando CHAR(256),
		ans SMALLINT,
		myprinter char(128),
		aux CHAR(128)
	
	initialize aux to null
   #LET aux = fgl_getenv("DBPRINT")
	#IF aux IS NULL THEN
	#LET myprinter="lp -c -s "
	#END IF


	#display "DIMPRIME"
	#sleep 4
	#select impressora, nome, tipo, postscript, remota, nomesys
	select *
		into pr_d_printer.*
		from d_printer
		where d_printer.impressora=d_impressora


	if status = notfound then 
		let d_impressora = "Def"
		initialize pr_d_printer.* to null
	end if

	# Se a impressora nao e postscript, procurar uma que seja
	if pr_d_printer.postscript = "S" then
		if tipo = "EPS" then
		   let aux = aux clipped, " -o raw "
		end if
	end if

	if pr_d_printer.comando is null then
	   #LET myprinter="lp -c -s "
	   LET myprinter="lpr  "
	   if d_impressora != "Def" then
		   #let myprinter = myprinter clipped, " -d", d_impressora clipped
		   let myprinter = myprinter clipped, " -P", d_impressora clipped
	   end if
	   if aux is not null then
		   let myprinter = myprinter clipped, aux clipped
	   end if
	else
		let myprinter = pr_d_printer.comando
	end if

	# Se definida como remota  e nao existir sistema vair para default.
	IF pr_d_printer.nomesys IS NULL and pr_d_printer.remota = "S" THEN
		let pr_d_printer.remota = "N"
	end if

	case
		when pr_d_printer.remota="N"
			let comando =  myprinter clipped, " ", nome
			{
	      IF d_impressora = "Def" THEN
	         LET comando=aux CLIPPED," ",nome
	      ELSE
	         LET comando=myprinter clipped,aux CLIPPED,
								" -d ",d_impressora," ",nome
			end if
			}
         LET comando = comando CLIPPED, " 2> /dev/null"
			#display "Comando impressao 1", comando
			#sleep 5
	      LET ans=d_run(comando)
			sleep 1
		when pr_d_printer.remota="S"
	      LET comando="cat ",nome," | rcmd ",pr_d_printer.nomesys," \"",
						 myprinter clipped," \""
			{
	      IF  d_impressora = "Def" THEN
	         LET comando="cat ",nome," | rcmd ",pr_d_printer.nomesys," \"",
						 myprinter clipped," \""
	      ELSE
	         LET comando="cat ",nome," | rcmd ",
								pr_d_printer.nomesys clipped," \"", 
						      myprinter clipped,aux CLIPPED ,
								" -d",d_impressora clipped," \""
	      END IF
			}
         LET comando = comando CLIPPED, " 2> /dev/null"
			#display "Comando impressao 2", comando
			#sleep 5
	      LET ans=d_run(comando)
			sleep 1
		when pr_d_printer.remota="E"
			{ ISTO FOI SUBSTITUIDO PELO SCRIPT LPE...
			let cap1 = printer_on()
			let cap2 = printer_off()
	      LET comando="echo \"", cap1 clipped, "\\c\"",
							";cat ",nome clipped,
							"; echo \"", cap1 clipped, "\\c\""
			}
	      LET comando="lpe ",nome clipped
			let ans=d_run(comando)
		otherwise
			# let ans = printer_on()
	      LET comando="more ",nome
			run comando
			#display "Comando impressao ", comando
			#sleep 5
			# let ans = printer_off()
	end case
	#error "Imprimiu" sleep 4
END FUNCTION


#  ============================================================================ 
#  Cria a tabela de routing.
#  ============================================================================ 
function 	 create_drouting()
{}
	create table d_routing (
		terminal char(50),
		impressora char(14)
   )
end function

#  ============================================================================ 
#  Cria a tabela de impressoras.
#  ============================================================================ 
function 	 create_dprinter()
{}
	create table d_printer (
		 impressora char(14),
       nome char(64),
       tipo char(30),
       postscript char(1),
       remota char(1),
       nomesys char(14)
	)
end function

#  ============================================================================ 
#  Vai buscar a impressora para onde vai determinada listagem.
#  Devolve o nome de impressora e sua descricao.
#  Prioridade ao tipo de impresso.
#  ============================================================================ 
function 	 d_get_printer_name(impressora_default,tipo)
{}
   define
		impressora_default char(14),
		tipo               char(3),
		n_ps               smallint,
		impressora char(14),
		impr_nome  char(64),
		postscript char(1),
		where_ad   char(48)

	 call d_get_impr_default()
	 return d_impressora
	 # ??? Para ja fica assim
		
	if impressora_default is not null then
	  initialize impr_nome to null
	  select d_printer.impressora, d_printer.nome , d_printer.postscript
	      into impressora, impr_nome, postscript
			from d_printer
			where d_printer.impressora = impressora_default
	  if status = notfound then
		  error "Impressora inexistente"
	  end if
	  return impr_nome
	end if

	if tipo="EPS" then
		select count(*) 
			into n_ps 
			from d_printer where d_printer.postscript="S"
		if status = notfound or n_ps <= 0 then
			return ""
		end if
		let where_ad = " and d_printer.postscript=\"S\""
	end if
 
	# Ver se existem impressoras
	select count(*) 
		into n_ps 
		from d_printer
	if status = notfound or n_ps <= 0 then
	   call d_get_impr_default()
		return d_impressora
	end if

	# Procurar impressora para tipo de impresso
	declare cr_impr cursor for 
		select d_printer.impressora, d_printer.nome , d_printer.postscript
			from d_printer, d_routimpr
			where d_routimpr.impresso = tipo
	open cr_impr
	fetch cr_impr into impressora, impr_nome, postscript
	case 
		when status=notfound  # Por encaminhamento
			# Por routing e impresso
			declare cr_routing cursor for
				select d_routing.impressora 
					from d_routing 
					where d_routing.terminal = d_tty
			open cr_routing
			fetch cr_routing into impr_nome
			if status != 0 then  # Atencao a outros status
			   if tipo = "EPS" then
					let impr_nome = d_get_first_ps()
					return impr_nome
				else
					let impr_nome = d_get_first_nao_ps()
					if impr_nome is null then
						exit case
					else
						return impr_nome
					end if
				end if
				exit case
			end if
			while (1=1)
			   if tipo = "EPS" then
					let impr_nome = d_get_first_ps()
					return impr_nome
				end if
			   fetch cr_routing into impr_nome
				if status != 0 then
					exit while
				end if
			end while
			if tipo="EPS" then
				return "" # Impossivel
			end if
		when status=0
			while (1=1)
				if tipo = "EPS" then
					if postscript = "S" then
	               close cr_impr
						call d_get_desc_impr(impr_nome)
						return impr_nome
					else 
						return ""
					end if
				else # Encaminhamento.
					# Por routing e impresso
					declare cr_rout cursor for
						  select d_routing.impressora 
							  from d_routing 
							  where d_routing.impressora = impr_nome
					open cr_rout
					fetch cr_rout into impr_nome
					if status != 0 then  # Atencao a outros status
	               close cr_impr
						close cr_rout
						call d_get_desc_impr(impr_nome)
						return impr_nome
					end if 
					close cr_rout
				end if
	         fetch cr_impr into impr_nome, postscript
				if status != 0 then
					exit while
				end if
	      end while
	      close cr_impr
			# Por impresso
			return impr_nome
		otherwise
			return ""
	end case
	close cr_impr
	call d_get_impr_default()
	return "Def" # Default

end function


#  ============================================================================ 
#  Vai a tabela de impressoras buscar a sua descricao, por nome.
#  Falta optimizar a busca com uma instarucao preparada.
#  ============================================================================ 
function 	 d_get_desc_impr(impressora)
{}
   define
		impressora char(14),
		nome       char(64)

	if impressora = "Def" then
		let d_impressora = impressora
		let d_impr_nome  = " Principal"
		return
	end if
   select d_printer.nome 
		into nome
		from  d_printer
		where d_printer.impressora=impressora
   # Actualizar variavel global
	let d_impr_nome = nome
end function


#  ============================================================================ 
#  Vai buscar primeira impressora de postscript que encontrar.
#  ============================================================================ 
function 	 d_get_first_ps()
{}
	declare cr_ps cursor for
      select d_printer.impressora, d_printer.nome 
		   from  d_printer
		   where d_printer.postscript = "S"
	open cr_ps
   fetch cr_ps into d_impressora, d_impr_nome
	close cr_ps
	return d_impressora
end function

#  ============================================================================ 
#  Vai buscar primeira impressora nao postscript que encontrar.
#  Se nao encontrar nenhuma devolve postscript, caso contrario devolve null.
#  ============================================================================ 
function 	 d_get_first_nao_ps()
{}
	define
	  post          char(1),
	  printer_ps    char(14),
	  printer_nm_ps char(64)

	declare cr_mprinter cursor for
      select d_printer.impressora, d_printer.nome , d_printer.postscript
		   from  d_printer
	open cr_mprinter
   foreach cr_mprinter into d_impressora, d_impr_nome, post
		if post = "S" then 
			let printer_ps    = d_impressora
			let printer_nm_ps = d_impr_nome
		else
			return d_impressora
		end if
	end foreach
	close cr_mprinter
	return d_impressora
end function



#  ============================================================================ 
#  Vai buscar a impressora de default do sistema.
#  ============================================================================ 
function 	 d_get_impr_default()
{}
	define impr_def char(14)

	let impr_def = d_get_valor("IMPRESSORA_CURR",d_user)

	if impr_def is null then
		let d_impressora="Def"
	else
		LET D_Impressora=impr_def
	end if
	call d_get_desc_impr(impr_def)
end function
