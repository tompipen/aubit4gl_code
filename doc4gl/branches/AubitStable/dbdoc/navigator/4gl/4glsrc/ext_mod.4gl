#  ======================================================================
#  DESCRICAO: Este ficheiro tem um conjunto de funcoes que irao permitir
#             validacoes de after e before fields, assim como a configuracao
#             do menu "Opcoes" e "Lista" e ainda input's update's e outros.
#  ======================================================================

#  ======================================================================
#  Base de dados e ficheiro de globals generico da despodata.
#  ======================================================================
#DATABASE despodata

GLOBALS "4glsrc/gl_mod.4gl"


#  ======================================================================
#  Before fields do input de campos.
#  ======================================================================
function   ok_bf_mod_codigo(Alteracao_ou_Insercao) 
{}
   Define
      Alteracao_ou_Insercao char(1)

   return true
end function

function   ok_bf_mod_nome(Alteracao_ou_Insercao) 
{}
   Define
      Alteracao_ou_Insercao char(1)

   return true
end function




#  ======================================================================
#  After fields do input de campos
#  ======================================================================
function   ok_af_mod_codigo(Alteracao_ou_Insercao) 
{}
   Define
      Alteracao_ou_Insercao char(1)

   return true
end function

function   ok_af_mod_nome(Alteracao_ou_Insercao) 
{}
   Define
      Alteracao_ou_Insercao char(1)

   return true
end function



#  ======================================================================
#  Funcao a executar em before input.
#  OK Before input.
#  Ja esta.
#  ======================================================================
function 	 ok_bi_mod(Alteracao_ou_Insercao)
{}
   Define
		Alteracao_ou_Insercao char(1)

   return true
end function

#  ======================================================================
#  Funcao a executar em after input.
#  OK After input.
#  Ja esta
#  ======================================================================
function 	 ok_ai_mod(Alteracao_ou_Insercao)
{}
   Define
		Alteracao_ou_Insercao char(1)

   return true
end function


#  ======================================================================
#  Funcoes de validacao antes de efectuar accoes. Nomeadamente:
#      Adicao - ok_add_<sufixo>()
#      Alteracao - ok_update_<sufixo>()
#      Remocao - ok_delete_<sufixo>()
#      Busca - ok_busca_<sufixo>()
#      Seguinte - ok_seguinte_<sufixo>()
#      Anterior - ok_anterior_<sufixo>()
#      Opcoes - ok_opcoes_<sufixo>()
#      Fim - ok_fim_<sufixo>()
#      Lista - ok_lista_<sufixo>()
#  ----------------------------------------------------------------------
#  Se os programadores pretenderem que as alteracoes sejam efectuadas 
#  deverao retornar TRUE, caso contrario deverao retornar FALSE.
#  NOTAS:
#  ======================================================================
function 	 ok_add_mod()
{}
   return true
end function

#  ======================================================================
#  Executada assim que se escolhe a opcao "Altera"
#  ======================================================================
function 	 ok_bef_update_mod()
{}
   return true
end function

#  ======================================================================
#  Executada imediatamente antes do update
#  ======================================================================
function 	 ok_update_mod()
{}
   return true
end function

#  ======================================================================
#  Executada quando se executa a opcao "Remove"
#  ======================================================================
function 	 ok_delete_mod()
{}
   return true
end function

#  ======================================================================
#  Executada apos remocao
#  ======================================================================
function 	 scr_mod_removido()
{}
   return
end function

function 	 ok_busca_mod()
{}
   return true
end function

function 	 ok_seguinte_mod()
{}
   return true
end function

function 	 ok_anterior_mod()
{}
   return true
end function

function 	 ok_opcoes_mod()
{}
   return true
end function

function 	 ok_fim_mod()
{}
   return true
end function

function 	 ok_lista_mod()
{}
   return true
end function

#  ======================================================================
#  Remocoes na tabela de detalhe, de acordo com a condicao necessaria
#  ======================================================================
function 	 rm_details_mod() 
{}
   return true
end function

#  ======================================================================
#  Funcoes que permitem a configuracao do menu opcoes e listar.
#  ---------------------------------------------------------------
#  Executar outras opcoes. Geralmente as tabelas de detalhe
#  ===============================================================
function 	 scr_op_mod()
{}
   DEFINE 
		detail_1,
		detail_2,
		detail_3,
		detail_4,
		detail_5,
		detail_6 char(28),
                mesg1, mesg2, mesg3 char(48),
		ans smallint,
		cond char(200)
	
  if pr_scr_ctl[scr_pointer].registos <= 0 then
	 if pr_scr_ctl[scr_pointer].nomeRegs is null then
		let mesg2="Nao ha registos seleccionados"
	   let mesg3="Tem de executar uma busca"
	 else
	   let mesg1="Nao ha"
	   let mesg2=pr_scr_ctl[scr_pointer].nomeRegs clipped
	   let mesg3="seleccionadas(os)"
	 end if
	 call d_dialogOk(9,15,"",mesg1,mesg2,mesg3,"","")
	 return 
  end if
   RETURN

	while ( 1=1 )
      let ans = menuVert(5,44,+1,
									     detail_1,
									     detail_2,
									     detail_3,
									     detail_4,
									     detail_5,
									     detail_6,
				                    "","","")

      initialize pr_chaves.* to null          # Ver se isto e LIXO.
   end while
   call d_scr_close_cr_rowid()
	call d_scr_mete_bem()
end function


#  ===============================================================
#  Listagens a executar.
#  ===============================================================
function 	 scr_lista_mod()
{}
   DEFINE
		claus_where  char(64),
		nome_listagem char(64),
		fmt char(64),
		ans smallint,
		tp smallint

   if d_scr_Select() = false then
      return 
   end if

	initialize tp to null
   call d_start_drep()

   CALL d_campo_drep("codigo","codigo","d_modulos",fmt,tp)
   CALL d_campo_drep("nome","nome","d_modulos",fmt,tp)

   if not d_rep_campos(5,39) then
      call d_end_drep()
      return 
   end if
   let claus_where = " rowid in (select linhaid from ", 
                     pr_scr_ctl[scr_pointer].nome_tab_rowid," )"

   let ans = d_rep("Listagem de Modulos","d_modulos",claus_where,pr_scr_ctl[scr_pointer].order_by)
   call d_end_drep()
   call d_scr_open_cr_rowid()
end function




