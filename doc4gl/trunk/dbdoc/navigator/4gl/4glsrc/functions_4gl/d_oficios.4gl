# ==============================================================================
# Notas sucintas sobre a utilizacaoo deste modulo:
#  - Sequencia de chamada de funcoes
#   *- of_get_oficio(tipo)
#   *- of_open_w_inter()
#    - of_start_rep()
#    - of_output_rep(var_a_substituir,valor)
#    - of_finish_rep()
#    - of_gera_oficio(true)
#   *- of_imprime_oficios()
#    - of_insere_oficio(numero_of,tipo_oficio)
#    - of_numero_oficio(tipo_de_call,tipo_oficio,tipo_ficheiro)
#
#   * -> Estas funcoes so sao chamadas uma vez, isto e, no caso de termos um
#       ciclo associado a geracao dos oficios, escolhemos o oficio, abrimos uma
#       janela com mensagem, geramos dentro dum ciclo os varios ficheiros a
#       imprimir(com as restantes 6 funcoes) e finalmente imprime-se o grupo de
#       impressao.
#   Falta meter com os drivers para office automation
#   Falta ver bem o funcionamento em multi-posto.
#   Falta compatibilizar com a versao do IAPMEI
#   Falta meter uma versao com trace para debug.
# ==============================================================================
#database despodata
database sysmaster

globals "4glsrc/functions_4gl/d_libglob.4gl"

define 
	pr_d_of_tipo record like d_of_tipo.*,
   pr_par_d_of record        # Record de cpontrole dos oficios
      debug char(1)
   end record,
   dgetpi    integer,
   condicao  char(80),
   str_d_run char(80),
   dummy     integer,
   corrente  integer,
   grp_imp   integer,
   fichM4,fichM4Filtrado,fichBaseFiltrado,intermedio,fl_nmfinal char(40)

# ==============================================================================
#  Funcao que vai pedir o cargo e o nome, se o campo da tabela de tipos de
# oficios ( d_of_tipo ) esta preenchido com "S". 
#  Esta abre uma janela sendo feito antes do input um select para ver se na 
# tabela de tipo de oficios ( d_of_tipo ) estado preenchidos os campos "cargo"
# e "nome". Se estiverem preenchidos faz o display dos mesmos, senao vai buscar
# a tabela de controle de oficios ( d_of_controle ) e faz o display.
# ==============================================================================
function of_pergunta_cargo(pr_tipo_oficios)
{}
   define
      pr_tipo_oficios record like d_of_tipo.*,
      cargo char(60),
      nome  char(40)

   if pr_tipo_oficios.pergunta_nome = "S" then
      open window w_cargo at 6,3
      with form "perg_cargo"
      attribute(border,form line 1)

      input by name cargo,nome 

         before input
            if pr_tipo_oficios.cargo is null then
               select d_of_controle.cargo into cargo
               from d_of_controle
               where tipo_oficios = pr_tipo_oficios.tipo_fich
            else
               let cargo = pr_tipo_oficios.cargo 
            end if
  
            if pr_tipo_oficios.nome  is null then
               select d_of_controle.nome into nome
               from d_of_controle
               where tipo_oficios = pr_tipo_oficios.tipo_fich
            else
               let nome = pr_tipo_oficios.nome  
            end if

            display cargo to cargo
            display nome  to nome
  

      end input
        
      close window w_cargo

      let pr_tipo_oficios.cargo = cargo
      let pr_tipo_oficios.nome  = nome

      return pr_tipo_oficios.*

	else

      return pr_tipo_oficios.*

   end if

end function


# ==============================================================================
# Escolhe o oficio por intermedio de uma lov, por tipo de oficio passado como
# parametro.
#
# SELECIONA OFICIO:
#               entra   -> tipo de oficio a escolher
#               retorna -> registo de oficio escolhido 
# ==============================================================================
function of_get_oficio(tipo)
  define tipo like d_of_tipo.tipo

  whenever error call d_erro
  initialize pr_d_of_tipo.* to null
  let corrente=0

  if tipo is not null then
    let condicao="tipo=\"",tipo clipped,"\""
  else
    let condicao="1=1"
  end if

  ### Escolha do oficio a gerar

  call d_amor(6,10,2,1,"","","TIPOS DE OFICIOS","d_of_tipo",
              "codigo","descricao","",condicao,"codigo")
    returning pr_d_of_tipo.codigo

  if pr_d_of_tipo.codigo is null then
    return pr_d_of_tipo.*
  end if

  ### Buscar os dados do tipo de oficio e teste a existencia do ficheiro base

  select * into pr_d_of_tipo.*
  from d_of_tipo 
  where pr_d_of_tipo.codigo=codigo

  if not d_posso_ler_file(pr_d_of_tipo.ficheiro) then
    initialize pr_d_of_tipo.* to null
  end if
  return pr_d_of_tipo.*
end function

# ==============================================================================
# Vai a base de dados buscar os dados necessarios sobre os oficios 
# que se pretende gerar
# ==============================================================================
function     of_set_oficio(d_tipo,d_codigo)
{}
   define
      pr_of_tipo record like d_of_tipo.*,
      d_tipo     like d_of_tipo.tipo,
      d_codigo   like d_of_tipo.codigo,
      mens       char(60),
      mens2      char(60),
      retval     smallint
   
   let dgetpi = d_getpid()
   let retval = true
   declare cr_oficios cursor for
      select * from d_of_tipo 
      where d_of_tipo.tipo   = d_tipo and
            d_of_tipo.codigo = d_codigo
   open cr_oficios
   fetch cr_oficios into pr_of_tipo.*
   if status = notfound then
      let mens = "Oficio <", d_codigo clipped, "> do tipo <",d_tipo clipped, ">"
      call d_dialogOk(9,15,"",mens,"nao existe na tabela",
                    "de tipos de oficios","!","")
      let retval = false
   end if
   fetch cr_oficios into pr_of_tipo.*
   if status = 0 then
      let mens = "Existe mais de um oficio "
      let mens2 = "<", d_codigo clipped,
                  "> do tipo <", d_tipo clipped, ">"
      call d_dialogOk(9,15,"",mens,mens2,"nao existe na tabela",
                    "de tipos de oficios","!")
      let retval = false
   end if
   close cr_oficios
   return retval
end function

# ==============================================================================
# Abre janela com tanga 
# ==============================================================================
function of_open_w_inter()
  open window w_inter at 9,21 with 6 rows, 35 columns attribute(border)
  display "Geracao do ficheiro intermedio!" at 3,3
  display "    Aguarde um momento...     " at 4,3 attribute(reverse)
end function

# ==============================================================================
# Cancela oficio 
# ==============================================================================
function of_cancel_oficio()
  whenever error continue
  close window w_inter
   if status = 1147 and status != 0 then 
        call d_erro()
   end if
   whenever error call d_erro
  call d_dialogOk(9,15,"","Programa nao previsto","para este oficio","!","","")
end function

# ==============================================================================
# Gere a geracao do oficio 
#          - entra: tipo que indica se quer ter a hipotese de alterar ficheiro
# ==============================================================================
function of_gera_oficio(tipo) 
  define tipo integer

  whenever error call d_erro
  if not of_filtragem_acentos() then      # Filtra acentos
     call d_dialogOk(9,15,"","Geracao de oficio","abortada","!","","")
     call of_del_files_aux()               # Remove ficheiros auxiliares
     return
   end if
  call of_ger_fich_intermedio()         # Gera fich intermedio
  if tipo then
    call of_alter_fich_intermedio()     # Permite aceder fich intermedio
  end if
  call of_ger_fich_final()              # Gera fich final
  call of_impressao_oficio()            # Imprime oficio
  call of_del_files_aux()               # Remove ficheiros auxiliares
end function

# ==============================================================================
# Filtagem de acentos - Tem de se arranjar uma forma generica.
# ==============================================================================
function of_filtragem_acentos()
  whenever error call d_erro
  let fichM4Filtrado="/tmp/ofi",dgetpi using "<<<<<",".m"
  call dbug_p_filtrar()
  let str_d_run="cat ",fichM4 clipped,"|iso2mm>",fichM4Filtrado
  let dummy=d_run(str_d_run)

  call dbug_filtrado()
  if not d_posso_ler_file(pr_d_of_tipo.ficheiro) then
     return false
  end if
  call dbug_base()
  let fichBaseFiltrado="/tmp/baseFilt",dgetpi using "<<<<<"
  let str_d_run="cat ",pr_d_of_tipo.ficheiro clipped,
                "|asc2mm>",fichBaseFiltrado
  let dummy=d_run(str_d_run)
  return(true)
end function

# ==============================================================================
# Gera ficheiro intermedio 
# ==============================================================================
function of_ger_fich_intermedio()

  whenever error call d_erro
  let intermedio="/tmp/int.",dgetpi using "<<<<<"
  let str_d_run="m4 ",fichM4Filtrado clipped," ",fichBaseFiltrado clipped,
                ">",intermedio
  let dummy=d_run(str_d_run)
  call dbug_depois_m4()
  whenever error continue
  close window w_inter
   if status = 1147 and status != 0 then 
        call d_erro()
   end if
   whenever error call d_erro
end function

# ==============================================================================
# Permite alterar ficheiro intermedio 
# ==============================================================================
function of_alter_fich_intermedio()

  ## Colocar a hipotese de alteraco do ficheiro depois do M4 e antes do nroff  
  
  let dummy=d_dialog(9,15,"NAO","SIM","","","Deseja ver/alterar o ficheiro,",
                     "antes de ser formatado","?","","")
  if dummy=2 then
    let str_d_run="vi ",intermedio clipped
    run str_d_run 
  end if
end function
  
# ==============================================================================
# Gera ficheiro final 
# ==============================================================================
function of_ger_fich_final()
  open window w_final at 9,21 with 6 rows, 31 columns attribute(border)
  display "Geracao do ficheiro final!!" at 3,3
  display "    Aguarde um momento... " at 4,3 attribute(reverse)

  let fl_nmfinal="/tmp/ofi_",dgetpi using "<<<<<",corrente using"<<<<<<"
  #Tirei o -mm do nroff para funcionar com os requerimentos da TAP, PVP
  #Este ficheiro d_oficio so esta a ser compilado devido aos requerimentos TAP
  let str_d_run="cat ",intermedio clipped,"|tira_lb|nroff >", # -mm
                fl_nmfinal clipped
  let dummy=d_run(str_d_run)
  call dbug_depois_nroff()
end function

# ==============================================================================
# Cria ou acrescenta grupo de impressao
# ==============================================================================
function of_impressao_oficio()
  if not corrente then
    call d_init_user()
    let grp_imp=d_sp_set_novo_grupo(0,"Oficios",today,d_user,"","N","S")
  end if
  let corrente=corrente+1
  call d_sp_nova_listagem(grp_imp,fl_nmfinal,"Oficios") 
end function

# ==============================================================================
# Imprime grupo de impressao
# ==============================================================================
function of_imprime_oficios() 
  call d_sp_print_grupo(grp_imp) 
end function

# ==============================================================================
# Remove ficheiros auxiliares 
# ==============================================================================
function of_del_files_aux()
   let dummy=d_unlink(intermedio)
   let dummy=d_unlink(fichM4)
   let dummy=d_unlink(fichM4Filtrado)
   let dummy=d_unlink(fichBaseFiltrado)
   whenever error continue
   close window w_final
   if status = 1147 and status != 0 then 
        call d_erro()
   end if
   whenever error call d_erro
end function

# ==============================================================================
# Inicia REPORT para criar ficheiro de M4 
# ==============================================================================
function of_start_rep()
  let fichM4="/tmp/oficio",dgetpi using "<<<<<",".m"
  start report r_M4_of to fichM4
  call d_of_reset_debug()
end function

# ==============================================================================
# Finaliza REPORT para criar ficheiro de M4 
# ==============================================================================
function of_finish_rep()
  finish report r_M4_of
end function

# ==============================================================================
# Output para REPORT de M4 
# ==============================================================================
function of_output_rep(var_a_substituir,valor)
  define var_a_substituir char(80),
         valor char(256)

  output to report r_M4_of(var_a_substituir,valor)
end function

#  ============================================================================ 
#  Report para ficheiro de M4
#  ============================================================================ 
report r_M4_of(var_a_sub,valor)
  define var_a_sub char(80),
         valor char(256)
  define aux_str char(256)

  output
    left margin 0
    right margin 0
    top margin 0
    bottom margin 0
    page length 2

  format
    first page header
      let aux_str="changequote(@,@)"
      print(aux_str clipped)
    on every row
      let aux_str="define(",var_a_sub clipped,",@",valor clipped,"@)"
      print(aux_str clipped)

end report

#  ============================================================================ 
#  Valida se se pode ler o ficheiro do qual se passa o nome.
#  Da mensagens sobre o ficheiro, utlizando as dialog(s).
#  ============================================================================ 
function     d_posso_ler_file(nm_fl)
{}
   define
      nm_fl   char(64),
      pmesg   char(40),
      ans smallint,
      retval smallint
   
   let pmesg = "Ficheiro base ", nm_fl clipped
   let ans = d_fstat(nm_fl)
   case
      when ans = 0
         call d_dialogOk(9,15,"",pmesg,"nao existe",
                         "Consulte o admnistrador da BD","!","")
         let retval = false
      when ans = 1
         let retval = true
      when ans = 2
         call d_dialogOk(9,15,"",pmesg,"nao tem permissao de leitura",
                         "Consulte o admnistrador da BD","!","")
         let retval = false
      when ans = 3
         let retval = true
      otherwise
         let retval = true
   end case
   return retval
end function


# ==============================================================================
#  Passa a modo debug
# ==============================================================================
function     d_of_set_debug()
{}
   let pr_par_d_of.debug = "S"
end function

# ==============================================================================
#  Desliga o modo de debug
# ==============================================================================
function     d_of_reset_debug()
{}
   let pr_par_d_of.debug = "N"
end function

function     dbug_p_filtrar()
{}
   define
      ans smallint,
      comm char(128)

   if pr_par_d_of.debug != "S" then
      return
   end if
   let ans = d_dialog(9,15,"SIM","NAO","","OFICIOS - Modo DEBUG",
                     "Deseja ver/alterar o ficheiro,",
                     "de m4 base","?","","")

   if ans = 1 then
      let comm = "vi ", fichM4
      run comm
   end if
end function

function     dbug_filtrado()
{}
   define
      ans smallint,
      comm char(128)

   if pr_par_d_of.debug != "S" then
      return
   end if
   let ans = d_dialog(9,15,"SIM","NAO","","OFICIOS - Modo DEBUG",
                     "Deseja ver/alterar o ficheiro,",
                     "depois da 1.a filtragem","?","","")

   if ans = 1 then
      let comm = "vi ", fichM4Filtrado
      run comm
   end if
end function

function     dbug_depois_m4()
{}
   define
      ans smallint,
      comm char(128)

   if pr_par_d_of.debug != "S" then
      return
   end if
   let ans = d_dialog(9,15,"SIM","NAO","","OFICIOS - Modo DEBUG",
                     "Deseja ver/alterar o ficheiro,",
                     "depois de passar pelo m4","?","","")

   if ans = 1 then
      let comm = "vi ", intermedio
      run comm
   end if
end function

function     dbug_depois_nroff()
{}
   define
      ans smallint,
      comm char(128)

   if pr_par_d_of.debug != "S" then
      return
   end if
   let ans = d_dialog(9,15,"SIM","NAO","","OFICIOS - Modo DEBUG",
                     "Deseja ver/alterar o ficheiro,",
                     "depois da formatacao","?","","")

   if ans = 1 then
      let comm = "vi ", fl_nmfinal
      run comm
   end if
end function

function     dbug_base()
{}
   define
      ans smallint,
      comm char(128)

   if pr_par_d_of.debug != "S" then
      return
   end if
   let ans = d_dialog(9,15,"SIM","NAO","","OFICIOS - Modo DEBUG",
                     "Deseja ver/alterar o ficheiro,",
                     "base","?","","")

   if ans = 1 then
      let comm = "vi ", pr_d_of_tipo.ficheiro
      run comm
   end if
end function


# ==============================================================================
#  Funcao para inserir registo na tabela de oficios emitidos ( d_of_emitidos) e
# mover o ficheiro de depois de gerado para o directorio
# $DB/oficios/bin/MMAAAA ( dois digitos para o mes e quatro digitos para
# o ano ) tendo o nome of_TTTT.NN ( T - tipo de oficio, N - numero de oficio ).
#  Parametros:
#      - numero_of   ( numero do oficio )
#      - tipo_oficio ( tipo de oficio )
# ==============================================================================
function of_insere_oficio(numero_of,tipo_oficio,numero_pedido)
{}
   define
      numero_of         integer,      # Numero de oficio
      tipo_oficio       char(8),      # Tipo de oficio
		numero_pedido     integer,      # Numero de pedido
      ficheiro_oficio   char(64),     # Nome do ficheiro final do oficio
      d_hora            smallint,     # Hora de insercao do oficio
      d_minuto          smallint,     # Minuto de insercao do oficio
      numero_seq        integer,      # Numero sequencial de oficios emitidos
      mes               char(2),      # Mes corrente
      ano               smallint,     # Ano corrente
      directorio        char(200),    # Directorio correspondentes aos oficios
                                      # mes e ano corrente
      string_a_executar char(200),    # String para mover ficheiro
      ans               smallint      # Codigo para execucao da funcao d_run()

   # Busca de hora e minuto corrente.
   call d_current()
   returning d_hora,d_minuto

   # busca de utilizador corrente.
   call d_init_user()

   #  Busca do ultimo numero de oficio emitido a tabela de oficios emitidos
   # ( d_of_emitidos ).
   select max(numero_sequencial) into numero_seq
   from d_of_emitidos

   # If para validar numero de oficio emitido
   if numero_seq != 0 then
      if numero_seq is null then
         let numero_seq = 1
      else
         let numero_seq = numero_seq + 1
      end if
   else
      let numero_seq = 1
   end if

   # Busca de mes e ano corrente e formatacao do mes.
   let mes = month(today)
   let ano = year(today)
   if length(mes) < 10 then
      let mes = "0",mes clipped
   end if

   #  Afectacao do nome do directorio para onde vai mover o oficio gerado e
   # afectacao da string para executar o mover do oficio para o nome acima
   # afectado.
   let directorio = "oficios/",mes clipped,ano using "####"
   let string_a_executar = "mkdir ", directorio clipped, " 2> /dev/null "
   let ans = d_run(string_a_executar)
   let string_a_executar = "cp ", fl_nmfinal clipped,
                           " ", directorio clipped,"/of",tipo_oficio clipped,
                           ".",numero_of using "<<<<"
   #  Execucao da string.
   let ans = d_run(string_a_executar)

   #  Afectacao do nome final do oficio.
   let ficheiro_oficio = directorio clipped,"/of",tipo_oficio clipped,
                           ".",numero_of using "<<<<"
   
   #  Insercao dos seguintes dados na tabela de oficios emitidos
   # ( d_of_emitidos ):
   #     - numero_seq      ( numero sequencial do oficio emitido )
   #     - tipo_oficio     ( tipo de oficio )
   #     - numero_of       ( numero do oficio )
   #     - today           ( data corrente )
   #     - d_hora          ( hora da impressao )
   #     - d_minuto        ( minuto da impressao )
   #     - d_user          ( utilizador corrente )
   #     - ficheiro_oficio ( nome final do oficio )
   #     - numero_pedido   ( numero do pedido )
   insert into d_of_emitidos (numero_sequencial,tipo_oficio,numero,data,hora,
                              minuto,responsavel,nome_ficheiro,pedido)
   values (numero_seq,tipo_oficio,numero_of,today,d_hora,d_minuto,
           d_user,ficheiro_oficio,numero_pedido)

end function


# ==============================================================================
#  Funcao para buscar o numero a dar ao oficio, dependendo do tipo de numeracao
# que foi pedido. Para isso vai-se buscar o registo a tabela de controle a onde
# tipo de ficheiro for igual ao passado como parametro.
#  Pode haver tres tipos numeracao:
#     - "C" Vai pela numeracao existente na tabela de tipos de oficios
#      ( d_of_tipo ), ao correspondente tipo de oficio
#     - "G" Vai pela numeracao existente na tabela de controle ( d_of_controle )
#     - "N" Nao numera
#  Parametros:
#      - tipo_de_call  ( S - Sim N - Nao )
#      - tipo_oficio   ( tipo de oficio )
#      - tipo_ficheiro ( tipo de ficheiro N - nroff, L - Latex, etc. )
# ==============================================================================
function of_numero_oficio(tipo_de_call,tipo_oficio,tipo_ficheiro)
{}
   define
      pr_of_controle    record like d_of_controle.*,
		tipo_de_call      char(1),
      tipo_oficio       char(8),
      ultimo_numero     integer,
      tipo_ficheiro     char(1)

   #  Busca dos dados a tabela de controle ( d_of_controle ), referemte ao
   # tipo de ficheiro passado como parametro.
   select * into pr_of_controle.*
   from d_of_controle
   where tipo_oficios = tipo_ficheiro

   #  Case para saber qual o tipo de numeracao a executar
   case
      #  Se o tipo de numeracao from "C", entao ira buscar o ultimo numero
      # a tabela de tipos de oficios ( d_of_tipo ) referente ao tipo de oficio
      # passado como parametro, incrementado um valor ao ja existente se
      # existir, se nao existir afecta-o com um valor.
      #  Sendo feito um update a tabela de tipos de oficios ( d_of_tipo )
      # com o novo numero de oficio.
      when pr_of_controle.tipo_numeracao = "C"
         select ultimo_num into ultimo_numero
         from d_of_tipo
         where codigo = tipo_oficio
   
         if ultimo_numero is null then
            let ultimo_numero = 1
         else
            if ultimo_numero = 0 then
               let ultimo_numero = 1
            else
               let ultimo_numero = ultimo_numero + 1
            end if
         end if
   
			if tipo_de_call = "S" then
            update d_of_tipo set d_of_tipo.ultimo_num = ultimo_numero
            where codigo = tipo_oficio
			end if

      #  Se o tipo de numeracao from "N", nao numero efectando o numero de
      # oficio a null.
      when pr_of_controle.tipo_numeracao = "N"
         let ultimo_numero = null

      #  Se o tipo de numeracao from "G", entao ira buscar o ultimo numero
      # a tabela de controle de oficios ( d_of_tipo ) referente ao tipo de
      # ficheiro passado como parametro, incrementado um valor ao ja
      # existente se existir, se nao existir afecta-o com um valor.
      #  Sendo feito um update a tabela de controle de oficios ( d_of_controle )
      # com o novo numero de oficio.
      when pr_of_controle.tipo_numeracao = "G"
         let ultimo_numero = pr_of_controle.ultimo_numero

         if ultimo_numero is null then
            let ultimo_numero = 1
         else
            if ultimo_numero = 0 then
               let ultimo_numero = 1
            else
               let ultimo_numero = ultimo_numero + 1
            end if
         end if

			if tipo_de_call = "S" then
            update d_of_controle set d_of_controle.ultimo_numero = ultimo_numero
            where tipo_oficios = tipo_ficheiro
			end if

   end case

   # Retorna o numero de oficio a afectar.
   return ultimo_numero

end function


# ==============================================================================
#  Funcao que gera variaveis por defeito para macro (m4), sendo descriminadas de
# seguida:
#    - var_data_dia_corrente      ( Data corrente )
#    - var_dia_corrente           ( Dia corrente )
#    - var_mes_corrente           ( Mes corrente )
#    - var_descr_mes_corrente     ( Descricao mes corrente )
#    - var_ano_corrente           ( Ano corrente )
#    - var_utilizador_corrente    ( Utilizador corrente )
#    - var_hora_corrente          ( Hora corrente )
#    - var_minuto_corrente        ( Minuto corrente )
#    - var_nome_ficheiro_oficio   ( Nome ficheiro oficio )
# ==============================================================================
function of_gera_variaveis_std()
{}
   define
      str_form  char(256),   # String para afectacao de variavel para macro (m4)
      data_dia  date,        # Data corrente
      dia_dia   smallint,    # Dia corrente
      mes_dia   smallint,    # Mes corrente
      descr_mes char(10),    # String de descricao de mes
      ano_dia   smallint,    # Ano corrente
      d_hora    smallint,    # Hora corrente
      d_minuto  smallint     # Minuto corrente

	# Data corrente
   let data_dia  = today
   let  str_form = data_dia
   call of_output_rep("var_data_dia_corrente",str_form)

	# Dia corrente
   let dia_dia   = day(today)
   let  str_form = dia_dia
   call of_output_rep("var_dia_corrente",str_form)

	# Mes Corrente
   let mes_dia   = month(today)
   let  str_form = mes_dia
   call of_output_rep("var_mes_corrente",str_form)

	# Busca descricao mes corrente
   call d_busca_descricao_mes(mes_dia)
   returning descr_mes

	# Descricao mes corrente
   let  str_form =  descr_mes clipped
   call of_output_rep("var_descr_mes_corrente",str_form)

	# Ano corrente
   let ano_dia   = year(today)
   let  str_form = ano_dia
   call of_output_rep("var_ano_corrente",str_form)

	# Busca utilizador corrente
   call d_init_user()

	# Utilizador corrente
   let  str_form =  d_user clipped
   call of_output_rep("var_utilizador_corrente",str_form)

	# Busca hora e minuto correntes
   call d_current()
   returning d_hora,d_minuto

	# Hora corrente
   let  str_form =  d_hora
   call of_output_rep("var_hora_corrente",str_form)

	# Minuto corrente
   let  str_form =  d_minuto
   call of_output_rep("var_minuto_corrente",str_form)

	# Nome ficheiro oficio
   let  str_form =  fl_nmfinal clipped
   call of_output_rep("var_nome_ficheiro_oficio",str_form)

end function


function d_busca_descricao_mes(mes)
{}
    define
       mes      smallint,
       desc_mes char(10)

    case
       when mes = 1
          let desc_mes = "JANEIRO"
       when mes = 2
          let desc_mes = "FEVEREIRO"
       when mes = 3
          let desc_mes = "MARCO"
       when mes = 4
          let desc_mes = "ABRIL"
       when mes = 5
          let desc_mes = "MAIO"
       when mes = 6
          let desc_mes = "JUNHO"
       when mes = 7
          let desc_mes = "JULHO"
       when mes = 8
          let desc_mes = "AGOSTO"
       when mes = 9
          let desc_mes = "SETEMBRO"
       when mes = 10
          let desc_mes = "OUTUBRO"
       when mes = 11
          let desc_mes = "NOVEMBRO"
       when mes = 12
          let desc_mes = "DEZEMBRO"
    end case

    return desc_mes

end function
