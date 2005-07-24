
#  ============================================================================
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#
#
#  Autor:  Sergio Alexandre Ferreira, Nuno Coelho
#
#
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : Funcao de extenso em informix 4GL.
#  ----------------------------------------------------------------
#  DESCRICAO:  Traducao da funcao em C do Fernando Fernandez.
#
#  ----------------------------------------------------------------
#  FUNCOES:  extenso()
#
#  ============================================================================


#database despodata
database sysmaster

	define strExtenso char(512)

function 	 extenso(num,tamanho_maximo,moeda_std)
{}
   define
#		num            float,
		num						 decimal(32,16),
		tamanho_maximo smallint,    # Tamanho maximo da primeira linha
		flag           smallint,    # true -> Utilizar acentos.
																# false -> Nao utilizar acentos.
		i,j						 smallint,
		moeda_std			 char(10),
		moedinha_std	 char(10),
		FezMilMilhoes, FezMilhoes, FezMilhares,
		FezUnidades 	 char(1), #controlar por onde ele passou, e que partes 
													 #do numero ja foram tratadas.
# Ver esta cena
#		nome           array[4][2] of char(20),
		nome           array[6] of char(30),
#		extenso        char(60),
		n decimal(32,16),
   
	   mil_milhoes, milhoes, milhares, unidades, centavos integer,
		 mil_milhoes_aux, milhoes_aux, milhares_aux decimal(32,16),
		frac           float
#		frac					 decimal(1,16)

#   whenever error call d_erro
{
	let nome[1][1] = "um mi-lhar de mi-lhoes"
	let nome[2][2] = "um mi-lhar de mi-lh~oes"
	let nome[3][1] = " mi-lha-res de mi-lhoes"
	let nome[4][2] = " mi-lha-res de mi-lh~oes"
	let nome[5][1] = "um mi-lhao"
	let nome[6][2] = "um mi-lh~ao"
	let nome[7][1] = " mi-lhoes"
	let nome[8][2] = " mi-lh~oes"
}

# para ja vou fazer isto sem acentos
	let nome[1] = "um milhar de milhoes"
	let nome[2] = " milhares de milhoes"
	let nome[3] = "um milhao"
	let nome[4] = " milhoes"
	let nome[5] = " mil"



	let strExtenso=NULL
	
  if num=0 then
		let strExtenso="zero"
#		return "zero", 0
#		return " "
	end if

# depois acertar isto de acordo com os parametros que forem
# passados, provavelmente o melhor e chamar a d_lov() para
# a tabela moeda

	IF moeda_std="escudos" then
		let moedinha_std=" centavos"
	END IF

	IF moeda_std="euros" then
		let moedinha_std=" centimos"
	END IF
	
		
	let n=num 

# Mil milhoes
	let mil_milhoes_aux = n /1000000000
	let mil_milhoes = mil_milhoes_aux

		if mil_milhoes is null then
				let mil_milhoes = 0
		end if

	let n = n - mil_milhoes*1000000000

# milhoes

	let milhoes_aux = (n - n MOD 1000000)/1000000
	let milhoes=milhoes_aux
	let n = n - milhoes * 1000000

		if milhoes is null then 
				let milhoes = 0
		end if
		
	let milhares_aux = (n - n MOD 1000)/1000
	let milhares=milhares_aux
	
	let n = n-milhares*1000
	let unidades = n
# Acrescentei
	let frac = n - unidades 
	let centavos = frac*100
	if (frac*1000) MOD 10 > 5 then
		let centavos = centavos+1
	end if

	# Limpar a string. Nao e preciso.
	let FezMilMilhoes = "N"
	let FezMilhoes = "N"
	let FezMilhares = "N"
	
	# Mil milhoes
	if mil_milhoes > 0 then
			if mil_milhoes = 1 then
					let strExtenso = strExtenso clipped, nome[1]
			else
					let strExtenso = strExtenso clipped, TrataNumero(mil_milhoes, flag+1)
					let strExtenso = strExtenso clipped, nome[2]
			end if
			let FezMilMilhoes = "S"
					if milhoes = 0 and milhares = 0 and unidades = 0 then
						let strExtenso = strExtenso clipped, " de"
					else
						let strExtenso = strExtenso clipped, ", "
					end if
	end if
	
 # Milhoes	
			if milhoes > 0  then#and FezMilMilhoes != "S") then
					if milhoes = 1 then
					 	let strExtenso = strExtenso clipped, nome[3]
					else
						let strExtenso = strExtenso clipped, TrataNumero(milhoes,flag+1)
						let strExtenso = strExtenso clipped, nome[4]
					end if
					let FezMilhoes = "S"
							if milhares = 0 and unidades = 0 then
								let strExtenso = strExtenso clipped, " de "
							else
								let strExtenso = strExtenso clipped, ", "
							end if
			end if

 # Milhares
			if milhares > 0 then
					if milhares =1 then
						let strExtenso = strExtenso clipped, nome[5]
					else
						let strExtenso = strExtenso clipped, TrataNumero(milhares,flag+1)
						let strExtenso = strExtenso clipped, nome[5]
					end if
					let FezMilhares = "S"
								if unidades > 0 then
									IF (unidades MOD 100) > 0  and milhoes > 0 then
										let strExtenso = strExtenso clipped, ", "
									ELSE
										let strExtenso = strExtenso clipped, " e "
									END IF
							end if
			end if

	# Unidades
		if unidades > 0  then 
	# Acrescentei esta, se der bronca tirar
			if centavos > 99 then 
				let centavos=0 
				let unidades=unidades+1
			end if
				let strExtenso = strExtenso clipped, TrataNumero(unidades,flag+1)
		end if

	# Tratamento da moeda em causa
	IF unidades = 1 then
			IF moeda_std="escudos" THEN
				let moeda_std="escudo"
			END IF
			IF moeda_std="euros" THEN
				let moeda_std="euro"
			END IF
	END IF

		IF unidades > 0 then
			let strExtenso = strExtenso clipped, " ",moeda_std
		END IF

		if centavos > 0 then
				if unidades > 0 then 
					let strExtenso = strExtenso clipped, " e "
				end if
				let strExtenso = strExtenso clipped, TrataNumero(centavos,flag+1)
				let strExtenso = strExtenso clipped, moedinha_std
		end if

		return strExtenso
				
			
end function


function 	 TrataNumero(n,flag)
{}
   define
		n        integer,
		unidades array[20] of char(15),
		dezenas  array[10] of char(20),
		centenas array[10] of char(20),
		flag     smallint,
		extenso_do_numero   char(128),
		aux smallint

	let unidades[1] = ""
	let unidades[2] = " um"
	let unidades[3] = " dois"
	let unidades[4] = " tres"
	let unidades[5] = " quatro"
	let unidades[6] = " cinco"
  let unidades[7] = " seis"
	let unidades[8] = " sete"
	let unidades[9] = " oito"
	let unidades[10] = " nove"
	let unidades[11] = " dez"
	let unidades[12] = " onze"
	let unidades[13] = " doze"
	let unidades[14] = " treze"
	let unidades[15] = " catorze"
	let unidades[16] = " quinze"
	let unidades[17] = " dezasseis"
	let unidades[18] = " dezassete"
	let unidades[19] = " dezoito"
	let unidades[20] = " dezanove"

	let dezenas[1] = ""
	let dezenas[2] = ""
	let dezenas[3] = " vinte"
	let dezenas[4] = " trinta"
	let dezenas[5] = " quarenta"
	let dezenas[6] = " cinquenta"
	let dezenas[7] = " sessenta"
	let dezenas[8] = " setenta"
	let dezenas[9] = " oitenta"
	let dezenas[10] = " noventa"

	let centenas[1] = ""
	let centenas[2] = " cento"
	let centenas[3] = " duzentos"
	let centenas[4] = " trezentos"
	let centenas[5] = " quatrocentos"
	let centenas[6] = " quinhentos"
	let centenas[7] = " seiscentos"
	let centenas[8] = " setecentos"
	let centenas[9] = " oitocentos"
	let centenas[10] = " novecentos"

			
	if n < 1000 and n != 0 then
		if n=100 then
			let extenso_do_numero = extenso_do_numero clipped, " cem"
		else 
			if n > 99 then
				let extenso_do_numero= extenso_do_numero clipped, centenas[n/100+1]
				if (n MOD 100) > 0 then
					let extenso_do_numero = extenso_do_numero clipped, " e "
				end if
			end if
			if (n MOD 100) < 20 then
			# O gajo nao papa isto directamente ...
				let aux = (n MOD 100)+1
				let extenso_do_numero=extenso_do_numero clipped, unidades[aux]
			else 
				let aux = ((n MOD 100)/10)+1
				let extenso_do_numero=extenso_do_numero clipped,dezenas[aux]
				if (n MOD 10) > 0 and n>10 then
					let extenso_do_numero = extenso_do_numero clipped, " e "
					let aux = (n MOD 10)+1
					let extenso_do_numero = extenso_do_numero clipped, unidades[aux]
				end if
			end if
		end if
	else 
		if n > 999 then
		   let extenso_do_numero = extenso_do_numero clipped,
											"<<ERRO: NUMERO > 999>>"
		end if
	end if
	return extenso_do_numero
end function
