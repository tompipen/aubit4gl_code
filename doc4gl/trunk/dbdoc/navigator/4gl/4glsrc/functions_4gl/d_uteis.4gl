#  ============================================================================
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#                                                        
#  Autor: Pedro Higgs Menezes
#                                                        
#  Data de criacao: Thu Oct 27 15:32:05 LISBOA 1994
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : 
#  ---------------------------------------------------------------------------
#  DESCRICAO:  Funcao que serve para ver quantos dias uteis um mes, para isso
#       sao passados como parametros o mes e o ano, sendo depios feita uma
#       de feriados (tabela tferiados, campo frd_dia), existentes para aquele
#       mes.
#
#  ---------------------------------------------------------------------------
#  FUNCOES: d_duteis()
# 
#  ---------------------------------------------------------------------------
#  FORMS: 
#
#  REPORTS: 
#
#  NOTAS:
#
#  ============================================================================ 

#database geral
database sysmaster

GLOBALS "4glsrc/functions_4gl/d_libglob.4gl"

#  ============================================================================ 
#   Funcao que serve para ver quantos dias uteis um mes, para isso sao passados
#  como parametros o mes e o ano, sendo depios feita uma de feriados (tabela
#  tferiados, campo frd_dia), existentes para aquele mes.
#  ============================================================================ 
function d_duteis()
{}

	define
		dias   smallint,
		n_dias smallint,
		i      smallint,
		ate    smallint,
		mes    smallint,
		ano    smallint,
		data   date

	if num_args() < 1 then         # Se nao forem passados parametros
		let mes = month(today)      # Assume-se a data corrente tirando-se
		let ano = year(today)       # data mesma o mes e o ano
		#display mes
		#display ano
	else
	                               # Se foram passados parametros serao
	   let mes = arg_val(1)        # O primeiro e o mes
	   let ano = arg_val(2)        # O segundo e o ano
	end if

	# Inicializacao de variaveis
	let dias   = 0
	let n_dias = 0
	let i      = 0
	let ate    = 0

	# Para ver quantos dias tem o mes
   case 
	   when mes = 1                # Janeiro
			  let ate = 31
	   when mes = 2                # Fevereiro

           if (((ano mod 400 ) =  0)   or
				  (((ano mod 4   ) =  0)   and
				  (( ano mod 100 ) != 0))) then
				  let ate = 29
			  else
				  let ate = 28
			  end if

	   when mes = 3                # Marco
			  let ate = 31
	   when mes = 4                # Abril
			  let ate = 30
	   when mes = 5                # Maio
			  let ate = 31
	   when mes = 6                # Junho
			  let ate = 30
	   when mes = 7                # Julho
			  let ate = 31
	   when mes = 8                # Agosto
			  let ate = 31
	   when mes = 9                # Setembro
			  let ate = 30
	   when mes = 10               # Outobro
			  let ate = 31
	   when mes = 11               # Novembro
			  let ate = 30
	   when mes = 12               # Dezembro
			  let ate = 31
		otherwise                   # Outros
			  let ate = 31
	end case



	# Para ver quantos feriados existem para aquela mes e ano
	select count(*) into n_dias
	from tferiados
	where month(frd_dia) = mes and
			year(frd_dia)  = ano

	# Se tiver feriados sao subtraidos
	if n_dias > 0 then
		let n_dias = -n_dias
	end if

	# Passa para formato date os parametros passados
	let data = mdy(mes,1,ano)
	#display data

	# Agora vai finalmente ver quantos dias uteis tem
	for i = 1 to ate

		let dias = weekday(data)

		let data = data + 1

		# Se for domingo (0) ou Sabado (6) nao e somado
		if dias != 0 and
			dias != 6 then

			let n_dias = n_dias + 1

		end if

	end for

	# Aqui estao a quantidade de dias que tem este mes
	display n_dias

end function
