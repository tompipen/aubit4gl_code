#  ============================================================================ 
#  Dialog box com 6 strings e 3 opcoes.
#  ============================================================================ 
function 	 d_dialog(lin,col,op1,op2,op3,str1,str2,str3,str4,str5,str6)
{}
  define
	 lin, col smallint,
	 op1 char(14),
	 op2 char(14),
	 op3 char(14),
	 str1 char(48),
	 str2 char(48),
	 str3 char(48),
	 str4 char(48),
	 str5 char(48),
	 str6 char(48),
	 strtmp char(48),
	 op array[3] of char(10),
	 opkey array[3] of char(1),
	 colu array[3] of smallint,
	 len array[3] of smallint,
	 curop smallint,
	 nops smallint,
	 charans char(1),
	 i smallint,
	 ans integer

  open window w_dialog at lin,col with 10 rows, 50 columns attribute(border)


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
    display str1 clipped at 1, 2
  end if
  if str2 is not null then
    display str2 clipped at 2, 2
  end if
  if str3 is not null then
    display str3 clipped at 3, 2
  end if
  if str4 is not null then
    display str4 clipped at 4, 2
  end if
  if str5 is not null then
    display str5 clipped at 5, 2
  end if
  if str6 is not null then
    display str6 clipped at 6, 2
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

  let op[1]=op1
  let op[2]=op2
  let op[3]=op3
  let opkey[1]=upshift(op1[1])
  let opkey[2]=upshift(op2[1])
  let opkey[3]=upshift(op3[1])

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
  close window w_dialog
  return(curop)
end function



#  ============================================================================ 
#  Cria uma dialog box , com um OK no centro.
#  ============================================================================ 
function d_dialogOk(lin,col,str1,str2,str3,str4,str5,str6)
{}
  define
	 lin, col smallint,
	 str1 char(48),
	 str2 char(48),
	 str3 char(48),
	 str4 char(48),
	 str5 char(48),
	 str6 char(48),
	 strtmp char(48),
	 ans smallint


  open window w_dialogOk at lin,col with 10 rows, 50 columns attribute(border)
  if str1 is not null then
	 let strtmp = d_sstrip(str1)
    let str1=d_center_str(strtmp,48)
    display str1 clipped at 2, 2
  end if
  if str2 is not null then
	 let strtmp = d_sstrip(str2)
    let str2=d_center_str(strtmp,48)
    display str2 clipped at 3, 2
  end if
  if str3 is not null then
	 let strtmp = d_sstrip(str3)
    let str3=d_center_str(strtmp,48)
    display str3 clipped at 4, 2
  end if
  if str4 is not null then
	 let strtmp = d_sstrip(str4)
    let str4=d_center_str(strtmp,48)
    display str4 clipped at 5, 2
  end if
  if str5 is not null then
	 let strtmp = d_sstrip(str5)
    let str5=d_center_str(strtmp,48)
    display str5 clipped at 6, 2
  end if
  if str6 is not null then
	 let strtmp = d_sstrip(str6)
    let str6=d_center_str(strtmp,48)
    display str6 clipped at 7, 2
  end if

  call fgl_drawbox(3,6,8,23)
  display "OK" at 9, 25 attribute(reverse)
  while 1=1
    LET ans=getKey()
	 case
		when ans = 32   # Espaco
		  exit while
		when ans = 13   # Return
		  exit while
	 end case
  end while
  display "OK" at 9, 25 attribute(invisible)
  sleep(1)
  close window w_dialogOk
end function

