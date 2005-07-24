#  ============================================================================ 
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#                                                        
#  Autor: sergio
#                                                        
#  Data de criacao: Thu Mar 04 16:08:11 LISBOA 1993
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      :  Generico
#  ---------------------------------------------------------------------------
#  DESCRICAO:  Mete caixas para esperar um momento e vai dizendo o que esta a
#              fazer.
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
#
#  ============================================================================ 

define
	window_opened smallint

function d_wait(lin,col,str1,str2,str3,str4,str5,str6)
{}
  define
	 lin, col smallint,
	 str1 char(48),
	 str2 char(48),
	 str3 char(48),
	 str4 char(48),
	 str5 char(48),
	 str6 char(48),
	 ans smallint


   whenever error call d_erro
   open window w_wait at lin,col with 10 rows, 50 columns attribute(border)
	 let window_opened = true
   if str1 is not null then
      let str1=d_center_str(d_sstrip(str1 clipped),48)
      display str1 clipped at 2, 2
   end if
   if str2 is not null then
      let str2=d_center_str(d_sstrip(str2 clipped),48)
      display str2 clipped at 3, 2
   end if
  if str3 is not null then
    let str3=d_center_str(d_sstrip(str3 clipped),48)
    display str3 clipped at 4, 2
  end if
  if str4 is not null then
    let str4=d_center_str(d_sstrip(str4 clipped),48)
    display str4 clipped at 5, 2
  end if
  if str5 is not null then
    let str5=d_center_str(d_sstrip(str5 clipped),48)
    display str5 clipped at 6, 2
  end if
	# Isto da erro no linux, nao sei porque
  #call fgl_drawbox(3,19,12,23)
  display "AGUARDE UM MOMENTO !..." at 9,15 attribute(reverse,blink)
end function


function 	 d_change_wait(str1,str2,str3,str4,str5,str6)
{}
  define
	 lin, col smallint,
	 str1 char(48),
	 str2 char(48),
	 str3 char(48),
	 str4 char(48),
	 str5 char(48),
	 str6 char(48),
	 ans smallint

  if str1 is not null then
    let str1=d_center_str(d_sstrip(str1 clipped),48)
    display str1 clipped at 2, 2
  end if
  if str2 is not null then
    let str2=d_center_str(d_sstrip(str2 clipped),48)
    display str2 clipped at 3, 2
  end if
  if str3 is not null then
    let str3=d_center_str(d_sstrip(str3 clipped),48)
    display str3 clipped at 4, 2
  end if
  if str4 is not null then
    let str4=d_center_str(d_sstrip(str4 clipped),48)
    display str4 clipped at 5, 2
  end if
  if str5 is not null then
    let str5=d_center_str(d_sstrip(str5 clipped),48)
    display str5 clipped at 6, 2
  end if
end function

function 	 d_no_wait()
{}
   if window_opened then
     close window w_wait
	end if
	let window_opened = false
end function

