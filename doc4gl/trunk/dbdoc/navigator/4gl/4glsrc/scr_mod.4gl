#  ======================================================================
#  Base de dados e ficheiro de globals generico da despodata.
#  ======================================================================
DATABASE despodata

GLOBALS "gl_mod.4gl"

#  ============================================================================ 
#  Acede ah informacao do registo pelo "rowid" registado na tabela temporaria
#  e apresenta-a na form do ecran corrente.
#
#  E executada pela funcao de busca apos o contruct e pelas funcoes de
#  posicionamento
#  ============================================================================ 
function scr_find_mod()
{}
   if pr_scr_ctl[scr_pointer].str_get_reg is null then
      let pr_scr_ctl[scr_pointer].str_get_reg = "select ",
          pr_scr_ctl[scr_pointer].campos clipped,
          " from ",pr_scr_ctl[scr_pointer].tabela clipped,
          " where rowid=?"

      prepare stat_informacao from pr_scr_ctl[scr_pointer].str_get_reg
      declare cr_informacao cursor for stat_informacao
   end if

   open cr_informacao using pr_scr_ctl[scr_pointer].rowid_curr
   fetch cr_informacao into pr_d_modulos.*
   close cr_informacao
   let pr_back_d_modulos.* = pr_d_modulos.*
   call scr_desc_mod()
   call scr_disp_mod()

end function


#  ===========================================================================
#  Efectua os acessos a tabelas relativos a descodificacoes dos lookup(s)
#  ===========================================================================
function 	 scr_desc_mod()
{}
   DEFINE
      claus_where char(128)



end function



#  ===========================================================================
#  Apresenta o menu principal de gestao da entrada de dados (Busca;Novo;etc)
#  nome_tabela`.'
#  ----------------------------------------------------------------
#  Parametros e seu significado:
#    lin,col -> posicao do canto suprior esquerdo da janela.
#    tipo : 1 - Entrada de dados normal com todas as opcoes.
#           2 - Entrada de dados sem busca, efectuando a busca 
#               quando se entra.
#           3 - Entrada de dados sem posicionamentos. Mono-registo.
#    condicao : Condicao para efectuar uma busca quando entra na 
#               entrada de dados. Optimo para detail's, As buscas,
#               se existirem sao feitas sempre limitadas pela 
#               condicao introduzida.
#    chaves : Array de identificacao das chaves de acesso e seus valores para
#             a limitacao da busca a partida
#  ==========================================================================
FUNCTION scr_menu_mod(lin,col,tipo,condicao,chaves)
{}
   DEFINE 
      lin,col, tipo  SMALLINT,
      condicao       CHAR(64),
      chaves RECORD
         nm_chave1   CHAR(28),
         val_chave1  CHAR(28),
         nm_chave2   CHAR(28),
         val_chave2  CHAR(28),
         nm_chave3   CHAR(28),
         val_chave3  CHAR(28),
         nm_chave4   CHAR(28),
         val_chave4  CHAR(28),
         nm_chave5   CHAR(28),
         val_chave5  CHAR(28)
      END RECORD

   LET pr_chaves.* = chaves.*

   WHENEVER ERROR CALL d_erro
   LET d_nm_log="log/scr_mod.log"
   CALL startlog(d_nm_log)
   OPEN WINDOW w_titulo_mod AT 1,1 WITH 2 ROWS, 78 COLUMNS
   CALL d_scr_init("Registo de ")

   OPEN WINDOW w_mod AT lin, col
        WITH FORM "ged_mod" ATTRIBUTE(BORDER,form line 1)

   OPEN WINDOW w_menu_mod at 3,2 with 2 rows, 78 columns
   CURRENT WINDOW IS w_menu_mod

   CALL scr_init_mod()

   IF tipo = 2 THEN
      call scr_busca_mod(tipo,condicao)
      current window is w_menu_mod
   END IF

   CALL scr_tot_menu_mod()
   CALL d_scr_end()
   CLOSE WINDOW w_mod
   CLOSE WINDOW w_menu_mod
   CLOSE WINDOW w_titulo_mod 
END FUNCTION


#  ===========================================================================
#  Execucao da busca no inicio do processamento
#  ===========================================================================
FUNCTION scr_busca_mod(tipo,condicao)
   DEFINE 
      tipo     SMALLINT,
      condicao CHAR(64)

   CURRENT WINDOW IS w_mod
   LET pr_scr_ctl[scr_pointer].str_where = condicao

   IF tipo != 2 then
      IF NOT get_mod_order_by() THEN
         return
      END IF
   ELSE
      LET pr_scr_ctl[scr_pointer].order_by = ""
   END IF

   IF d_scr_pes() = false THEN
      return                           # Nao ha registos seleccionados
   END IF

   CALL scr_find_mod()          # Aceder a informacao atraves do rowid\
end function



#  =========================================================================
#  Menu principal com todas as opcoes (Novo;Busca;Insere:Altera:Posiciona).
#  =========================================================================
FUNCTION scr_tot_menu_mod()
{}

   MENU "OPCOES"
      COMMAND "Busca" "Efectua busca"
         CURRENT WINDOW IS w_mod
         CALL scr_pes_mod()

      COMMAND "Posiciona" "Menu de posicionamento nos elementos"
         CURRENT WINDOW IS w_mod
         IF d_scr_Select() = true THEN
            CALL scr_pos_mod("M")
         END IF

      COMMAND "Insere" "Adiciona novo elemento"
         CALL scr_novo_mod()

      COMMAND "Remove" "Remove o elemento corrente"
         CURRENT WINDOW IS w_mod
         IF NOT d_auth("d_modulos","delete") THEN
            CALL d_dialogOk(9,15,"","Voce nao tem permissoes",
                                    "de remocao na tabela pretendida","!",
                                    "Consulte o seu admnistrador de BD","")
            NEXT OPTION "Posiciona"
         ELSE
            IF ok_delete_mod() THEN
               IF rm_details_mod() THEN
                  CALL d_scr_rm() 
                  CALL scr_mod_removido()
                  CALL scr_find_mod()
               END IF
            END IF
         END IF

      COMMAND "Altera" "Modifica o elemento corrente"
         CURRENT WINDOW IS w_mod
         CALL scr_mod_mod()

      COMMAND "Lista" "Lista os dados selecionados"
         IF ok_fim_mod() THEN
            CALL scr_lista_mod()
         END IF



      COMMAND "Fim" "Volta ao menu anterior"
         IF ok_fim_mod() THEN
            EXIT MENU
         END If

      COMMAND key(">")
         CURRENT WINDOW IS w_mod
         CALL scr_pos_mod("S")
      COMMAND key("<")
         CURRENT WINDOW IS w_mod
         CALL scr_pos_mod("A")
      # Para  alterar para key home
      COMMAND key(F4)
         CURRENT WINDOW IS w_mod
         CALL scr_pos_mod("P")
      # Para alterar para key_ent , como tecla de funcao.
      COMMAND key(F3)
         CURRENT WINDOW IS w_mod
         CALL scr_pos_mod("U")
      # Acesso absoluto ao registo (ordem na seleccao)
      COMMAND key(F2)
         CURRENT WINDOW IS w_mod
         CALL scr_pos_mod("D")
      COMMAND key("!")
         CALL d_runsh()
      COMMAND key(CONTROL-G)
         CALL d_scr_win_id()
   END MENU

END FUNCTION

#  ========================================================================
#  Remove os elementos cuja chave de acesso e' passado por pr_chaves.
#  ========================================================================
function  scr_rm_mod()
{}
end function

#  ========================================================================
#  Inicializa a estrutura de controle.
#  ========================================================================
function scr_init_mod()
{}
   let pr_scr_ctl[scr_pointer].campos  = 
"codigo,",
"nome"
   let pr_scr_ctl[scr_pointer].str_get_reg = null
   let pr_scr_ctl[scr_pointer].tabela  = "d_modulos"
   let pr_scr_ctl[scr_pointer].nomeRegs = ""
   let pr_scr_ctl[scr_pointer].tabelas = ""
   let flag_insert = true
end function


#  ============================================================================
#  Pesquisa da informacao fazendo um "qiery by example" (construct)
#  e acedendao a informacao. Pergunta ao utilizador qual a ordenacao pretendida
#  ============================================================================
FUNCTION scr_pes_mod()
{}
   # Validar permissoes de acesso a tabela
   IF NOT d_auth("d_modulos","select") THEN
      CALL d_dialogOk(9,15,"","Voce nao tem permissoes",
                              "de acesso a tabela pretendida","!",
                             "Consulte o seu admnistrador de BD","")
      RETURN
   END IF

   IF NOT ok_busca_mod() THEN
      RETURN
   END IF

   CALL d_scr_find_inst()
   CURRENT WINDOW IS w_mod

   let int_flag = false
   CLEAR FORM

   CONSTRUCT BY NAME 
         pr_scr_ctl[scr_pointer].str_where 
      ON 
         d_modulos.codigo,
         d_modulos.nome

   if d_scr_pesAbortada() = true then
      call scr_disp_mod()

      call d_scr_end_find_inst()
      return
   end if

   # Ordenacao
   IF NOT get_mod_order_by() THEN
      CALL d_scr_end_find_inst()
      RETURN
   END IF

   IF d_scr_pes() = false THEN
      CALL d_scr_end_find_inst()
      RETURN
   END If

   # Procurar na tabela por rowid.
   CALL scr_find_mod()
   CALL d_scr_end_find_inst()
END FUNCTION


#  ==========================================================================
#  Posicionamento do registo corrente nos seleccionados
#  ==========================================================================
FUNCTION scr_pos_mod(tipo)
{}
   DEFINE 
      tipo char(1)

   CASE 
      WHEN tipo="S"
         IF NOT ok_seguinte_mod() THEN
            RETURN
         END If
      WHEN tipo="A"
         IF NOT ok_anterior_mod() THEN
            RETURN
         END IF
   END CASE
   IF d_scr_pos_rowid(tipo) = false THEN
      RETURN
   END IF
   CALL scr_find_mod()
end function


#  ===============================================================
#  Mete o menu de escolha da ordenacao.
#  ===============================================================
function 	 get_mod_order_by()
{}
   DEFINE 
      campo array[19] of record 
         nome_campo  char(39),
         colname     char(19)
      end record,
      numero_de_campos smallint,
      ans smallint
	

   LET campo[1].colname = ""
   LET campo[1].nome_campo = "Nao ordenado"
   LET campo[2].colname = "codigo"
   LET campo[2].nome_campo = "codigo"
   LET campo[3].colname = "nome"
   LET campo[3].nome_campo = "nome"
   LET numero_de_campos=2


   let ans = menuVertCasc(6,40,numero_de_campos+1,"","ORDENACAO POR",1,
									     campo[1].nome_campo,
									     campo[2].nome_campo,
									     campo[3].nome_campo,
									     campo[4].nome_campo,
									     campo[5].nome_campo,
									     campo[6].nome_campo,
									     campo[7].nome_campo,
									     campo[8].nome_campo,
									     campo[9].nome_campo,
									     campo[10].nome_campo,
									     campo[11].nome_campo,
									     campo[12].nome_campo,
									     campo[13].nome_campo,
									     campo[14].nome_campo,
									     campo[15].nome_campo,
									     campo[16].nome_campo,
									     campo[17].nome_campo,
									     campo[18].nome_campo,
									     campo[19].nome_campo)
   if ans <= 0 then
		let pr_scr_ctl[scr_pointer].order_by = campo[1].colname
		return false
	else
		let pr_scr_ctl[scr_pointer].order_by = campo[ans].colname
	end if
	return true
end function



#  ===============================================================
#  Aceita a introducao de uma nova linha.
#  ===============================================================
function scr_novo_mod()
{}
   # Validar permissoes de insercao na tabela
   IF NOT d_auth("d_modulos","insert") THEN
      CALL d_dialogOk(9,15,"","Voce nao tem permissoes",
									  "de insercao na tabela pretendida","!",
									  "Consulte o seu admnistrador de BD","")
		RETURN
	END IF

	call d_scr_ins_inst()
	current window is w_mod
   initialize pr_d_modulos.* 
      like 

         d_modulos.codigo  , 
         d_modulos.nome 


 

	while ( 1=1 )
      call scr_disp_mod()
      call scr_input_mod("I")
      if d_scr_inpAbortada() = true then
         let pr_d_modulos.* = pr_back_d_modulos.*
         call scr_desc_mod()
         call scr_disp_mod()

         exit while
      end if

      # Insercao de uma linha
	   call d_begin_work()
      if scr_ins_mod() = true then


         call d_scr_ins_rowid(sqlca.sqlerrd[6])
		   if d_status != 0 then
            let pr_d_modulos.* = pr_back_d_modulos.*
            call scr_disp_mod()

            CALL d_rollback_work()
		   else
            let pr_back_d_modulos.* = pr_d_modulos.*
            
            CALL d_commit_work()
         END IF
			exit while
      ELSE
			if d_status != -239 then
            let pr_d_modulos.* = pr_back_d_modulos.*
            call scr_disp_mod()

            call d_rollback_work()
				exit while
			else
            CALL d_rollback_work()
			end if
      end if
	end while
	call d_scr_open_cr_rowid()
	call d_scr_end_ins_inst()
end function



#  ===========================================================================
#  Mostra a informacao de um ecran, da informacao seleccionada
#  ===========================================================================
function scr_disp_mod()
{}
   # display_dos campos
   clear form
   if pr_scr_ctl[scr_pointer].Registos <= 0 then
      return
   end if
   DISPLAY BY NAME pr_d_modulos.*    # Especificar aqui os campos todos

   # Display de descodificacoes de campos


   call d_scr_disp_count()
	#current window is `w_'sufixo
end function

#  ============================================================================
#  Faz input do record `pr_'sufixo na form.
#  Se for alteracao e executado com "A", se insercao "I"
#  ============================================================================
function scr_input_mod(tipo_oper)
{}
   DEFINE
		tipo_oper           char(1),
		claus_where         char(64),
		dumm                smallint,
	   veio_de_input_array smallint

   LET int_flag = false
	LET veio_de_input_array = false

	# Verificar os duplicados.
   INPUT BY NAME

      pr_d_modulos.codigo,
      pr_d_modulos.nome
		   WITHOUT DEFAULTS

      BEFORE INPUT
         IF NOT ok_bi_mod(tipo_oper) THEN
				EXIT INPUT
			END IF
			IF veio_de_input_array THEN
				NEXT FIELD d_modulos.nome
			END IF


		# Podia ter sempre aqui tudo. So se metia os CONTROL+W
		# Control-w para ir ver tabelas
      ON KEY(CONTROL-W)
         CASE            WHEN infield(xx)
               LET dumm=1
         OTHERWISE
            CALL d_dialogOk(9,15,"","",
                 "Este campo nao e um codigo","","","")
      END CASE

      # Janela de identificacao
      on key(CONTROL-G)
         call d_scr_win_id()

      # Copiar os campos!..
      on key(CONTROL-P)
         case
         WHEN infield(codigo) 
            LET pr_d_modulos.codigo = pr_back_d_modulos.codigo
            DISPLAY BY NAME pr_d_modulos.codigo
            NEXT FIELD nome
         WHEN infield(nome) 
            LET pr_d_modulos.nome = pr_back_d_modulos.nome
            DISPLAY BY NAME pr_d_modulos.nome


				otherwise
               CALL d_dialogOk(9,15,"","Este erro nao deveria",
									  "ter acontecido","!","","")
         end case
      after input
         IF NOT ok_ai_mod(tipo_oper) THEN
            CONTINUE INPUT
         END IF


      BEFORE FIELD codigo
         IF NOT ok_bf_mod_codigo(tipo_oper) THEN
            NEXT FIELD codigo
         END IF
      BEFORE FIELD nome
         IF NOT ok_bf_mod_nome(tipo_oper) THEN
            NEXT FIELD nome
         END IF


      AFTER FIELD codigo
         IF NOT ok_af_mod_codigo(tipo_oper) THEN
            NEXT FIELD codigo
         END IF
      AFTER FIELD nome
         IF NOT ok_af_mod_nome(tipo_oper) THEN
            NEXT FIELD nome
         END IF



   END INPUT
end function


#  ===============================================================
#  Alteracao dos elementos.
#  ===============================================================
function scr_mod_mod()
{}
   if not ok_bef_update_mod() then
       return
   end if
   # Validar permissoes de alteracao na tabela
   IF NOT d_auth("d_modulos","update") THEN
      CALL d_dialogOk(9,15,"","Voce nao tem permissoes",
									  "de remocao na tabela pretendida","!",
									  "Consulte o seu admnistrador de BD","")
		return
	END IF
   if d_scr_Select() = false then
      return 
   end if

   call d_scr_mod_inst()
   current window is w_mod
   declare cr_update cursor for 
      select 
d_modulos.codigo,
d_modulos.nome 
      from d_modulos
      where rowid=pr_scr_ctl[scr_pointer].rowid_curr
      for update

   call d_begin_work()
   whenever error continue
   open cr_update
   fetch cr_update into pr_d_modulos.*
   case status
      when -250
         call d_rollback_work()
         CALL d_dialogOk(9,15,"","Este registo esta bloqueado",
                                 "por outro utilizador",
                                 "","Tente mais tarde","")
         whenever error call d_erro
         call d_scr_end_mod_inst()
         return 
      when 0
         whenever error call d_erro
      otherwise
         call d_erro()
         call d_rollback_work()
         whenever error call d_erro
   end case
 
   while 1=1
      call  scr_input_mod("A")
      if d_scr_updAbortada() = true then
         call d_rollback_work()
         let pr_d_modulos.* = pr_back_d_modulos.*
         call scr_desc_mod()
         call scr_disp_mod()

         call d_scr_open_cr_rowid()
         call d_scr_end_mod_inst()
         return
      end if

      if not ok_update_mod() then
         return
      end if
      whenever error continue
      update d_modulos set (
            codigo,
            nome 
            ) = ( 

                  pr_d_modulos.codigo,
                  pr_d_modulos.nome
            )
         where current of cr_update
      case sqlca.sqlcode
         when 0
				whenever error call d_erro
            exit while
         when -346
            if sqlca.sqlerrd[2] = -100 then
               CALL d_dialogOk(9,15,"","Impossivel alterar",
									           "valor que nao pode ser","!",
									           "duplicado na tabela","")
				   whenever error call d_erro
            else
               call d_erro()
				   whenever error call d_erro
               exit while
            end if
         otherwise
            call d_erro()
				whenever error call d_erro
            exit while
      end case
   end while


   if status != 0 then
      call d_rollback_work()
   else
      let pr_back_d_modulos.* = pr_d_modulos.*
      call d_commit_work()
   end if
   call d_scr_open_cr_rowid()
   call d_scr_end_mod_inst()
end function


#  ===============================================================
#  Faz insert do record com a informacao na tabela.
#  ===============================================================
function scr_ins_mod()
{}
   DEFINE
      str_insert char(640),
      str_chaves char(128),
      valores_chaves char(128)


   IF NOT ok_add_mod() THEN
      RETURN FALSE
   END IF
   IF flag_insert THEN
      # Chaves passadas por argumento a funcao principal. Para master/detail
      LET str_chaves     = get_chaves_mod()
      LET valores_chaves = get_valores_chaves_mod()
      LET str_insert = "INSERT INTO d_modulos (", str_chaves clipped,

         " d_modulos.codigo , " ,
         " d_modulos.nome ",
         " ) ",
         " VALUES (", valores_chaves CLIPPED,
         " ?,?" ,
         " )"

      PREPARE stat_insert FROM str_insert
      LET flag_insert = false
   END IF

   LET d_accao="Ins"
   WHENEVER ERROR CONTINUE
   EXECUTE stat_insert USING 

                  pr_d_modulos.codigo,
                  pr_d_modulos.nome
   # Deveriam ser testados outros erros nomedamente no que se refere a
   # integridade referencial
   CASE status 
		WHEN -239
         CALL d_dialogOk(9,15,"","Nao e possivel inserir informacao",
									     "com chave de acesso duplicada","!",
									     "Consulte o manual de instrucoes","")
	      WHENEVER ERROR CALL d_erro
			LET d_status = -239
			RETURN false
		WHEN 0
	      WHENEVER ERROR CALL d_erro
         LET d_status=0
			RETURN true
		OTHERWISE
			CALl d_erro()
			whenever error call d_erro
			return false
	end case


	# Isto eh estranho
   if d_status != 0 then
      let d_status=0
      return false
   end if
   return true
end function


function get_chaves_mod()
{}
   DEFINE
      str_chaves char(128)
	
	if pr_chaves.nm_chave1 is not null then
	   let str_chaves = pr_chaves.nm_chave1, " , "
	end if

	if pr_chaves.nm_chave2 is not null then
	   let str_chaves = pr_chaves.nm_chave2, " , "
	end if

	if pr_chaves.nm_chave3 is not null then
	   let str_chaves = pr_chaves.nm_chave3, " , "
	end if

	if pr_chaves.nm_chave4 is not null then
	   let str_chaves = pr_chaves.nm_chave4, " , "
	end if

	if pr_chaves.nm_chave5 is not null then
	   let str_chaves = pr_chaves.nm_chave5, " , "
	end if

   return str_chaves
end function



function get_valores_chaves_mod()
{}
   DEFINE
      str_valores char(128)
	
   if pr_chaves.val_chave1 is not null then
      if d_col_ischar("d_modulos",pr_chaves.nm_chave1) = true then
         let str_valores = "\"", pr_chaves.val_chave1, "\", "
      else
         let str_valores = pr_chaves.val_chave1, " , "
      end if
   end if

	if pr_chaves.val_chave2 is not null then
		if d_col_ischar("d_modulos",pr_chaves.nm_chave2) = true then
	      let str_valores = "\"", pr_chaves.val_chave2, "\", "
		else
	      let str_valores = pr_chaves.val_chave2, " , "
		end if
	end if

	if pr_chaves.val_chave3 is not null then
		if d_col_ischar("d_modulos",pr_chaves.nm_chave3) = true then
	      let str_valores = "\"", pr_chaves.val_chave3, "\", "
		else
	      let str_valores = pr_chaves.val_chave3, " , "
		end if
	end if

	if pr_chaves.val_chave4 is not null then
		if d_col_ischar("d_modulos",pr_chaves.nm_chave4) = true then
	      let str_valores = "\"", pr_chaves.val_chave4, "\", "
		else
	      let str_valores = pr_chaves.val_chave4, " , "
		end if
	end if

	if pr_chaves.val_chave5 is not null then
		if d_col_ischar("d_modulos",pr_chaves.nm_chave5) = true then
	      let str_valores = "\"", pr_chaves.val_chave5, "\", "
		else
	      let str_valores = pr_chaves.val_chave5, " , "
		end if
	end if

   return str_valores
end function









