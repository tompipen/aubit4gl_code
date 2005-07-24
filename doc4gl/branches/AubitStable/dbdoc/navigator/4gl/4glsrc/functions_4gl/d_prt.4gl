#  ============================================================================
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#
#  Divisao de desenvolvimento e producao de software.
#
#  Autor: sergio
#
#  Data de criacao: Wed May 18 16:54:16 LISBOA 1994
#
#   This Module contains Proprietary and Confidential
#   Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : Funcoes para gestao de impressoes. Versao 2
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
#       Estas funcoes deverao funcionar com a base de dados da despodata e
#       do IAPMEI, entre outras.
#
#  ============================================================================


#database geral
database sysmaster

define
   d_prt_impressora char(14),
   d_prt_fl_nm      char(30),
   d_prt_nm_lst     char(30),
   d_prt_formato    char(1),
   d_prt_copias     smallint

#  ============================================================================ 
#  Impressao interactiva, imediata de ficheiro.
#  ============================================================================ 
function d_prt_int_im_fl(fl_nm,nm_lst,frmt,impressora,copias)
{}
   define
      fl_nm    char(64),     # Nome do ficheiro.
      nm_lst   char(30),     # Nome da listagem.
      frmt     char(1),      # Formato do ficheiro (Ascii, Postscript,
                             # Iapmei metafile, IBM propRinter).
      impressora char(14),   # Nome da impressora (a null se impressora do
                             # utilizador.
      copias    smallint     # Numero de copias a imprimir.

   let impressora = d_prt_def_printer(impressora)
   if not d_prt_mesg() then
      return false
   end if
   call d_prt_filtra(impressora,frmt)
   call d_prt_fl()
end function

#  ============================================================================ 
#  Mete a mensagem de impressao, permite trocar a impressora, cancelar ou
#  enviar para spooler interactivo.
#  Se tipo = 1 nao da opcao de mandar para spooler.
#  ============================================================================ 
function d_prt_mesg()
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
   if d_prt_nm_lst is not null then
      let str1 = "Relatorio:", d_prt_nm_lst clipped
   else
      let str1 = null
   end if
   while ( 1=1 )
      let str2 = mesg
      if dono is not null then
         let str4 = " Processado por ", dono clipped, " em ",
            data_impr
      else
         let str4 = ""
      end if
      let str5 = ""
      let str6 = "Impressora: ", d_impr_nome  clipped
 
      let op1 = "OK"
      let op2 = "Cancelar"
      let op3 = "Impressora"

      if tipo = 1 then
         let op3 = ""
      else
         let op3 = "Spooler"
      end if
      let ans = d_dialog2(9,14,op1,op2,op3,op4,"GESTAO DE IMPRESSOES",
                          str1,str2,str3,str4,str5,str6)
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
#  Trata de filtrar uma listagem de acordo com o seu formato, com
#  a impressora. Devolve o nome do ficheiro.
#  ============================================================================ 
function     d_prt_filtra(ficheiro,impressora,formato)
{}
   define
      ficheiro   char(64),
      impressora char(14),
      formato    char(1)
end function

#  ============================================================================ 
#  Recebe impressora como parametro e trata de validar e achar uma impressora
#  default de jeito.
#  ============================================================================ 
function     d_prt_def_printer(impressora)
{}
   define
      impressora char(14)

   if impressora is null then
      if d_printer is null then
         let d_printer  = d_prt_get_user_impr() 
         let impressora = d_printer
      end if
   end if
end function


#  ============================================================================ 
#  Imprime efectivamente um ficheiro.
#  ============================================================================ 
function     d_prt_fl()
{}
end function


#  ============================================================================ 
#  Dialog box com titulo, 6 strings e 4 opcoes.
#  ============================================================================ 
function     d_dialog2(lin,col,op1,op2,op3,op4,titulo,
                      str1,str2,str3,str4,str5,str6)
{}
  define
    lin, col smallint,
    op1 char(14),
    op2 char(14),
    op3 char(14),
    op4 char(14),
    titulo char(48),
    str1 char(48),
    str2 char(48),
    str3 char(48),
    str4 char(48),
    str5 char(48),
    str6 char(48),
    strtmp char(48),
    op array[4] of char(10),
    opkey array[4] of char(1),
    colu array[4] of smallint,
    len array[4] of smallint,
    curop smallint,
    nops smallint,
    charans char(1),
    i smallint,
    ans integer

  open window w_dialog2 at lin,col with 12 rows, 50 columns attribute(border)


  let strtmp=d_sstrip(titulo)
  let titulo=d_center_str(strtmp,48)

  let strtmp=d_sstrip(str1)
  let str1=d_center_str(strtmp,48)
  let strtmp=d_sstrip(str2)
  let str2=d_center_str(strtmp,48)
  let strtmp=d_sstrip(str3)
  let str3=d_center_str(strtmp,48)
  let strtmp=d_sstrip(str4)
  let str4=d_center_str(strtmp,48)
  let strtmp=d_sstrip(str5)
  let str5=d_center_str(strtmp,48)
  let strtmp=d_sstrip(str6)
  let str6=d_center_str(strtmp,48)


  if str1 is not null then
    display str1 at 1, 2 attribute(reverse)
  end if

  if str1 is not null then
    display str1 at 3, 2
  end if
  if str2 is not null then
    display str2 at 4, 2
  end if
  if str3 is not null then
    display str3 at 5, 2
  end if
  if str4 is not null then
    display str4 at 6, 2
  end if
  if str5 is not null then
    display str5 at 7, 2
  end if
  if str6 is not null then
    display str6 at 8, 2
  end if

  let curop = 1
  let nops  = 1

  if op1 is null then 
    display "Funcao chamada com argumentos a menos" at 4, 5
    let op1 = "OK"
  end if

  if op2 is not null then
    let nops = nops+1
  end if

  if op3 is not null then
    let nops = nops+1
  end if

  if op4 is not null then
    let nops = nops+1
  end if


  let op[1]=op1
  let op[2]=op2
  let op[3]=op3
  let op[4]=op4
  let opkey[1]=upshift(op1[1])
  let opkey[2]=upshift(op2[1])
  let opkey[3]=upshift(op3[1])
  let opkey[4]=upshift(op4[1])

  # Falta calcular o sitio das opcoes.
  for i = nops to 1 step -1
    let len[i] = length(op[i] clipped)
    let colu[i]=((i-1)*(50/nops) + (50/nops)/2) - len[i]/2
    call fgl_drawbox(3,len[i]+2,8,colu[i]-1)
    if i = 1 then
      display op[curop] clipped at 9, colu[1] attribute(reverse)
    else
      display op[i] clipped at 9, colu[i] attribute(normal)
    end if
  end for

  while 1=1
    LET ans=getKey()
    case
      when ans=9 or ans=32 or ans=54 or ans=2003 # Espaco ou tab
        display op[curop] clipped at 9, colu[curop] attribute(normal)
        if curop >= nops then
          let curop = 1
        else
          let curop = curop + 1
        end if
        display op[curop] clipped at 9, colu[curop] attribute(reverse)

      when ans = 52 or ans=2002
        display op[curop] clipped at 9, colu[curop] attribute(normal)
        if curop <= 1 then
          let curop = nops
        else
          let curop = curop - 1
        end if
        display op[curop] clipped at 9, colu[curop] attribute(reverse)

      when ans=13                                   # Return
        exit while

      otherwise
         for i = curop to nops
            if upshift(ascii ans) = opkey[i] then
               display op[curop] clipped at 9, colu[curop] attribute(normal)
               let curop = i
               display op[curop] clipped at 9, colu[curop] attribute(reverse)
               exit while
            end if
         end for
         for i = 1 to curop
            if upshift(ascii ans) = opkey[i] then
               display op[curop] clipped at 9, colu[curop] attribute(normal)
               let curop = i
               display op[curop] clipped at 9, colu[curop] attribute(reverse)
               exit while
            end if
         end for
    end case
  end while
  display op[curop] clipped at 9, colu[curop] attribute(invisible)
  sleep(1)
  close window w_dialog2
  return(curop)
end function

