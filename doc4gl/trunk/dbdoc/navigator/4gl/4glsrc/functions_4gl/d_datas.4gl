
#  ===================================================================
#  PROGRAMA: livraria
#  -------------------------------------------------------------------
#  DESCRICAO: Modulo com funcoes relativas a tratamento de datas e 
#             Datetimes .
#  -------------------------------------------------------------------
#  FUNCOES: d_get_mes (mes)         # Devolve o nome do mes em Portugues
#           d_mes (mes)             # O mesmo que a anterior com acentos
#           d_data_ok (dia,mes,ano) # Valida se data e valida
#           d_get_dia_semana (data) # Devolve o dia da semana por extenso
#           d_AMDToStr (ano,mes,dia)# Converte data em String ???
#           d_data_extenso()        # Devolve uma data por extenso em Po.
#           get_dias_mes(mes,ano)   # Diz o numero de dias de um mes
#           d_date_cmp(data1,data2) # Compara duas datas
#           d_lov_mes()
#           d_lov_dia_semana()
#           d_cal()                 # Apresenta um calendario interactivo
#           interval2float(intervalo)      # Converte intervalo em float
#  -------------------------------------------------------------------
#  FORMS: NAO TEM
#  -------------------------------------------------------------------
#  REPORTS: NAO TEM.
#  -------------------------------------------------------------------
#  NOTAS:
#  ===================================================================



GLOBALS
     DEFINE
      
       arr_data ARRAY[6] OF RECORD 
            seg,ter,qua,qui,sex,sab,dom INTEGER END RECORD
END GLOBALS

DEFINE
	arr ARRAY[20] OF RECORD
		descr CHAR(40)
	END RECORD,
	selLetra CHAR(20), 
   pos  SMALLINT,
	len,lenAux SMALLINT,
   i INTEGER

#  ================================================================
#  Funcao para devolver um mes por extenso e em portugues.
#  ----------------------------------------------------------------
#  entradas:
#    mes -> mes a devolver.
#           Esta variavel pode assumir valores de 1 a 12.
#  ----------------------------------------------------------------
#  saidas:
#    mes_str -> string com o mes por extenso.
#  ================================================================
FUNCTION d_get_mes (mes)
{}
DEFINE mes SMALLINT

DEFINE mes_str CHAR (20)

  whenever error call d_erro
  CASE mes
    WHEN 1
      LET mes_str = "Janeiro"
    WHEN 2
      LET mes_str = "Fevereiro"
    WHEN 3
      LET mes_str = "Março"
    WHEN 4
      LET mes_str = "Abril"
    WHEN 5
      LET mes_str = "Maio"
    WHEN 6
      LET mes_str = "Junho"
    WHEN 7
      LET mes_str = "Julho"
    WHEN 8
      LET mes_str = "Agosto"
    WHEN 9
      LET mes_str = "Setembro"
    WHEN 10
      LET mes_str = "Outubro"
    WHEN 11
      LET mes_str = "Novembro"
    WHEN 12
      LET mes_str = "Dezembro"
    OTHERWISE
      LET mes_str = "Mês Inválido"
  END CASE

  RETURN mes_str

END FUNCTION

FUNCTION d_mes (mes)
{}
DEFINE mes SMALLINT

DEFINE mes_str CHAR (20)

  whenever error call d_erro
  CASE mes
    WHEN 1
      LET mes_str = "Janeiro"
    WHEN 2
      LET mes_str = "Fevereiro"
    WHEN 3
      LET mes_str = "Março"
    WHEN 4
      LET mes_str = "Abril"
    WHEN 5
      LET mes_str = "Maio"
    WHEN 6
      LET mes_str = "Junho"
    WHEN 7
      LET mes_str = "Julho"
    WHEN 8
      LET mes_str = "Agosto"
    WHEN 9
      LET mes_str = "Setembro"
    WHEN 10
      LET mes_str = "Outubro"
    WHEN 11
      LET mes_str = "Novembro"
    WHEN 12
      LET mes_str = "Dezembro"
    OTHERWISE
      LET mes_str = "Mês inválido"
  END CASE

  RETURN mes_str

END FUNCTION


#  ================================================================
#  Funcao para transformar uma data numa string com o formato
#  "yyyy.mm.dd".
#  ----------------------------------------------------------------
#  entradas:
#    ano,mes,dia -> sem comentarios.
#                   Caso alguma das variaveis entrar com NULL, a 
#                   mesma sera' substituida por ??.
#  ----------------------------------------------------------------
#  saidas:
#    data_str -> string com a data no formato referido.
#  ================================================================
FUNCTION d_AMDToStr (ano,mes,dia)
{}
DEFINE ano,mes,dia SMALLINT

DEFINE data_str CHAR (10)

  whenever error call d_erro
  IF ano IS NULL THEN
    LET data_str = "????"
  ELSE
    LET data_str = ano USING "&&&&"
  END IF
  IF mes IS NULL THEN
    LET data_str = data_str CLIPPED,".","??"
  ELSE
    LET data_str = data_str CLIPPED,".",mes USING "&&"
  END IF
  IF dia IS NULL THEN
    LET data_str = data_str CLIPPED,".","??"
  ELSE
    LET data_str = data_str CLIPPED,".",dia USING "&&"
  END IF

  RETURN data_str

END FUNCTION


#  ================================================================
#  Funcao para devolver o dia da semana por extenso.
#  ----------------------------------------------------------------
#  entradas:
#    data -> sem comentarios.
#  ----------------------------------------------------------------
#  saidas:
#    dia_sem_str -> string com o dia da semana por extenso.
#  ================================================================
FUNCTION d_get_dia_semana(data)
{}
   DEFINE
		data        date,
      dia_sem_str char(7),
		dia_semana  smallint

  let dia_semana = weekday(data)

  whenever error call d_erro
  CASE
    WHEN dia_semana = 0
      LET dia_sem_str = "DOMINGO"
    WHEN dia_semana = 1
      LET dia_sem_str = "SEGUNDA"
    WHEN dia_semana = 2
      LET dia_sem_str = "TERCA"
    WHEN dia_semana = 3
      LET dia_sem_str = "QUARTA"
    WHEN dia_semana = 4
      LET dia_sem_str = "QUINTA"
    WHEN dia_semana = 5
      LET dia_sem_str = "SEXTA"
    WHEN dia_semana = 6
      LET dia_sem_str = "SABADO"
  END CASE

  RETURN dia_sem_str

END FUNCTION


#  ================================================================
#  Funcao para testar uma data.
#  ----------------------------------------------------------------
#  entradas:
#    dia,mes,ano -> data a testar.
#  ----------------------------------------------------------------
#  saidas:
#    TRUE  se a data estiver correcta, ou se todos os campos estiverem
#          a NULL.
#    FALSE se a data estiver incorrecta.
#  ================================================================
FUNCTION d_data_ok (dia,mes,ano)
{}
DEFINE dia,mes,ano SMALLINT

DEFINE num_dias SMALLINT

  # --------------------------------------------------------------------
  # Se todos os elementos da data estiverem a NULL a data e' considerada
  # correcta.
  # --------------------------------------------------------------------
  whenever error call d_erro
  IF dia IS NULL AND mes IS NULL AND ano IS NULL THEN
    RETURN TRUE
  END IF

  # ----------------------------------------------------------------
  # Se o teste anterior falhou entao pelo menos um deles encontra-se
  # preenchido.
  # ----------------------------------------------------------------
  CASE
    WHEN dia IS NULL
      RETURN FALSE
    WHEN mes IS NULL
      RETURN FALSE
    WHEN ano IS NULL
      RETURN FALSE
  END CASE

  CASE
    # --------------------------
    # Teste dos meses especiais.
    # --------------------------
    WHEN mes=0 OR mes=13 OR mes=14 OR mes=15
      LET num_dias = 31
    WHEN mes=1 OR mes=3 OR mes=5 OR mes=7 OR mes=8 OR mes=10 OR mes=12
      LET num_dias = 31
    WHEN mes=4 OR mes=6 OR mes=9 OR mes=11
      LET num_dias = 30
    WHEN mes=2
      LET num_dias = 28 + ((ano MOD 4)=0)
    OTHERWISE 
      RETURN FALSE
  END CASE
  IF dia > num_dias OR dia < 1 THEN
    RETURN FALSE
  END IF

  RETURN TRUE

END FUNCTION





#  ================================================================
#  Devolve a data por extenso, e em portugues
#  ----------------------------------------------------------------

FUNCTION d_data_extenso(data)
{}
   DEFINE 
	   data DATE,
		mes      smallint,
      ret_date CHAR(40),
		temp_str CHAR(64),
		dia      smallint,
		ano      smallint

  WHENEVER ERROR CALL d_erro

  LET dia      = DAY(data)
  LET ret_date = dia USING "##"
  LET mes      = month(data)
  LET temp_str = d_get_mes(mes)
  LET ret_date = ret_date CLIPPED," de ", temp_str clipped
  LET ano      = year(data)
  LET temp_str = ano USING  "<<<<"
  LET ret_date = ret_date CLIPPED," de ", temp_str clipped

  RETURN ret_date CLIPPED

END FUNCTION

#  ----------------------------------------------------------------


#  ----------------------------------------------------------------
#  Devolve o numero de dias do mes que se passa como parametro
#  ----------------------------------------------------------------

FUNCTION d_get_dias_mes(mes,ano)
{}
   define
      mes               smallint,
      ano               smallint,
      data              date,
		dia smallint

   let dia = 1

   if ano < 1000 then
      let ano = ano + 1900
   end if

   if mes = 12 then
      let mes = 1
      let ano = ano + 1
   else
      let mes = mes + 1
   end if

   let data = mdy(mes,dia,ano) - 1
   return day(data)
end function


FUNCTION get_dias_mes(mes,ano)
{}
DEFINE mes,ano SMALLINT
  
  CASE mes
	 WHEN 1
		RETURN 31
	 WHEN 3
		RETURN 31
	 WHEN 5
		RETURN 31
	 WHEN 7
		RETURN 31
	 WHEN 8
		RETURN 31
	 WHEN 10
		RETURN 31
	 WHEN 12
		RETURN 31
	 WHEN 2
		IF ((((ano MOD 400)=0) OR ((ano MOD 4)=0)) AND ((ano MOD 100) <> 0)) THEN
		  RETURN 29
		ELSE
		  RETURN 28
		END IF
	 OTHERWISE
		RETURN 30
  END CASE
END FUNCTION

#  ----------------------------------------------------------------



#  ----------------------------------------------------------------
#  Funcao de comparacao de datas. Evita os barretes devidos aos 
#  nulls.
#  ----------------------------------------------------------------

FUNCTION d_date_cmp(d1,d2)
{}
  DEFINE d1,d2 DATE

  IF (d1 IS NULL) AND (d2 IS NULL) THEN
	 RETURN TRUE
  END IF
  IF (d1 IS NULL) OR (d2 IS NULL) THEN
	 RETURN FALSE
  END IF
  RETURN (d1=d2)
END FUNCTION


################################################################################# Funcao que permite visualizar uma lov com os meses e escolher um            #
# ............................................................................#
# ENTRADAS : Coordenadas da lov                                               #
#.............................................................................#
# SAIDAS : O numero do mes escolhido                                          #
###############################################################################
FUNCTION d_lov_mes(linha,coluna)
{}

DEFINE linha,coluna INTEGER,
       ret SMALLINT

LET ret = menuVertCasc(linha,coluna,12,"","","","JANEIRO","FEVEREIRO","MARCO",
                          "ABRIL","MAIO","JUNHO","JULHO","AGOSTO","SETEMBRO",
								  "OUTUBRO","NOVEMBRO","DEZEMBRO","","","","","","","")

RETURN ret

END FUNCTION


################################################################################# Funcao que permite visualizar uma lov com os dias da semana e escolher um    ################################################################################## ENTRADAS: Coordenadas da lov                                                 ################################################################################## SAIDAS: Retorna o numero correspondente ao dia da semana escolhido           ################################################################################# 
{}
FUNCTION d_lov_dia_semana(linha,coluna)

  DEFINE linha,coluna INTEGER,
         ret SMALLINT

  LET ret = menuVertCasc(linha,coluna,7,"","","","DOMINGO","SEGUNDA","TERCA",
	 "QUARTA","QUINTA","SEXTA","SABADO","","","","","","","","","","","","")

  IF ret <> 0 THEN
     RETURN ret-1
  ELSE
     RETURN(7) 
  END IF 

END FUNCTION



###############################################################################
# Conjunto de funcoes que permitem visualizar uma lov com o ano e mes         #
# pretendido e escolher um dia do mes                                         #
#.............................................................................#
# FUNCOES : d_dia()                                                           #
#           d_cal()                                                           #
#           inicia()                                                          #
#           inicia1()                                                         #
#           inicia2()                                                         #
#.............................................................................#
# ENTRADAS : Coordenadas da lov (d_dia(linha,coluna))                         #
#.............................................................................#
#SAIDAS : Uma variavel do tipo DATE com a data escolhida                      #
###############################################################################
{}
FUNCTION d_cal(mes,ano,lin,col)

  DEFINE dia,mes,ano,lin,col INTEGER               # Depois de o mes e o ano
                                                   # terem sido escolhidos
  OPEN WINDOW W_data AT lin,col                    # e aberta a janela W_data
  WITH FORM "f_cal"                                # com o form f_cal e e'
       ATTRIBUTE (BORDER, FORM LINE FIRST)         # chamada a funcao inicia()
                                                   # a qual vai tratar do 
  LET dia = inicia(mes,ano)                        # preenchimento do array
  CLOSE WINDOW W_data 
  RETURN dia

END FUNCTION
{}



###############################################################################
# Funcao que devolve os dias do mes e se o ano e' bissexto, alem disso devolve#
# o mes em extenso                                                            #
###############################################################################
{}
FUNCTION inicia(mes,ano)

   DEFINE 
         fim_mes,i,dia,mes,ano INTEGER,
			nomemes CHAR(15)

   FOR i=1 TO 6
       INITIALIZE arr_data[i].* TO NULL      # Inicializa o array a null
   END FOR 

   CASE mes 
     
        WHEN 1
             LET fim_mes = 31
             LET nomemes="JANEIRO"
             EXIT CASE
        WHEN 2
             LET nomemes="FEVEREIRO"
             IF ((((ano MOD 400)=0)
				    OR ((ano MOD 4)=0))
				    AND ((ano MOD 100) <> 0)) THEN 

                  LET fim_mes = 29
             ELSE
                  LET fim_mes = 28
             END IF 
             EXIT CASE
        WHEN 3
             LET fim_mes = 31
             LET nomemes = "MARCO"
             EXIT CASE
        WHEN 4
             LET fim_mes = 30
             LET nomemes = "ABRIL"
             EXIT CASE
        WHEN 5
             LET fim_mes = 31
             LET nomemes = "MAIO"
             EXIT CASE
        WHEN 6
             LET fim_mes = 30
             LET nomemes = "JUNHO"
             EXIT CASE
        WHEN 7
             LET fim_mes = 31
             LET nomemes = "JULHO"
             EXIT CASE
        WHEN 8
             LET fim_mes = 31
             LET nomemes = "AGOSTO"
             EXIT CASE
        WHEN 9
             LET fim_mes = 30
             LET nomemes = "SETEMBRO" 
             EXIT CASE
        WHEN 10
             LET fim_mes = 31
             LET nomemes = "OUTUBRO"
             EXIT CASE
        WHEN 11
             LET fim_mes = 30
             LET nomemes = "NOVEMBRO"
             EXIT CASE
        WHEN 12
             LET fim_mes = 31
             LET nomemes = "DEZEMBRO"
             EXIT CASE
   END CASE

   LET dia = inicia1(mes,ano,fim_mes,nomemes)   # Vai permitir preencher o array 
   RETURN dia

END FUNCTION {}
{}





##############################################################################
# Funcao que preenche o array                                                #
##############################################################################
{}
FUNCTION inicia1(mes,ano,fim_mes,nomemes)

        DEFINE
             mes,i,dia_semana,dia,ano,fim_mes INTEGER,
				 nomemes CHAR(15)
   LET i = 1
   FOR dia=1 TO fim_mes 
       LET dia_semana = weekday(MDY(mes,dia,ano))

       CASE dia_semana 
            WHEN 0
                 LET arr_data[i].dom = dia 
                 LET i =i+1
                 EXIT CASE

            WHEN 1
                 LET arr_data[i].seg =dia 
                 EXIT CASE
            WHEN 2
                 LET arr_data[i].ter =dia 
                 EXIT CASE
            WHEN 3
                 LET arr_data[i].qua =dia 
                 EXIT CASE
            WHEN 4
                 LET arr_data[i].qui =dia 
                 EXIT CASE
            WHEN 5
                 LET arr_data[i].sex =dia 
                 EXIT CASE
            WHEN 6
                 LET arr_data[i].sab =dia 
                 EXIT CASE
        END CASE     

   END FOR

   LET dia = inicia2(ano,mes,fim_mes,nomemes,i)  # Vai fazer o display do 
   RETURN dia                                    # do array e o seu control

END FUNCTION
{}



##############################################################################
# Funcao que faz o display do array e o seu controle                         #
##############################################################################
{}
FUNCTION inicia2(ano,mes,fim_mes,nomemes,i)

   DEFINE ano,mes,fim_mes,i,dia,auxdia INTEGER,
          nomemes CHAR(15)

   IF i >1 THEN
      CALL set_count(i)
      DISPLAY BY NAME nomemes
      DISPLAY BY NAME ano
      INPUT ARRAY arr_data WITHOUT DEFAULTS
      FROM s_data.*

      BEFORE ROW
             LET i = arr_curr() 
             ON KEY (CONTROL-P)       # Permite visualizar o calendario do
             LET auxdia = 0           # mes anterior
             EXIT INPUT

             ON KEY(CONTROL-N)        # Permite visualizar o calendario do
                LET auxdia = -1       # mes seguinte
                EXIT INPUT

      BEFORE FIELD seg

             CASE
               WHEN i=1

                    IF arr_data[i].seg IS NULL THEN
                        NEXT FIELD ter
                    END IF 

                    EXIT CASE 
             END CASE

             LET auxdia = arr_data[i].seg
             DISPLAY  arr_data[i].seg TO s_data[i].seg 
             ATTRIBUTE (REVERSE)

      AFTER FIELD seg 

            LET arr_data[i].seg = auxdia
            DISPLAY arr_data[i].seg TO s_data[i].seg
 
      BEFORE FIELD ter

             CASE 
                WHEN i=1
                     IF arr_data[i].ter IS NULL THEN
                        NEXT FIELD qua
                     END IF
                     EXIT CASE

                WHEN i=5 OR i=6
                     IF arr_data[i].ter IS NULL THEN
                        NEXT FIELD seg 
                     END IF
                     EXIT CASE
             END CASE

             LET auxdia = arr_data[i].ter
             DISPLAY arr_data[i].ter TO s_data[i].ter
             ATTRIBUTE (REVERSE)

       AFTER FIELD ter

             LET arr_data[i].ter = auxdia
             DISPLAY arr_data[i].ter TO s_data[i].ter

       BEFORE FIELD qua

              CASE 
                 WHEN i=1
                      IF arr_data[i].qua IS NULL THEN
                         NEXT FIELD qui
                      END IF
                      EXIT CASE
                 WHEN i=5 OR i=6
                      IF arr_data[i].qua IS NULL THEN
                         NEXT FIELD ter 
                      END IF 
                      EXIT CASE
              END CASE

              LET auxdia = arr_data[i].qua
              DISPLAY arr_data[i].qua TO s_data[i].qua
              ATTRIBUTE (REVERSE)

        AFTER FIELD qua

              LET arr_data[i].qua = auxdia
              DISPLAY arr_data[i].qua TO s_data[i].qua

       BEFORE FIELD qui

              CASE 
                 WHEN i=1
                      IF arr_data[i].qui IS NULL THEN
                         NEXT FIELD sex
                      END IF
                      EXIT CASE
                 WHEN i=5 OR i=6
                      IF arr_data[i].qui IS NULL THEN
                         NEXT FIELD qua
                      END IF
                      EXIT CASE
              END CASE     

              LET auxdia = arr_data[i].qui
              DISPLAY arr_data[i].qui TO s_data[i].qui
              ATTRIBUTE (REVERSE)

        AFTER FIELD qui

              LET arr_data[i].qui = auxdia 
              DISPLAY arr_data[i].qui TO s_data[i].qui

        BEFORE FIELD sex

               CASE  
                  WHEN i=1
                       IF arr_data[i].sex IS NULL THEN
                          NEXT FIELD sab
                       END IF
                       EXIT CASE
                  WHEN i=5 OR i=6
                       IF arr_data[i].sex IS NULL THEN
                          NEXT FIELD qui
                       END IF
                       EXIT CASE
               END CASE   

               LET auxdia = arr_data[i].sex
               DISPLAY arr_data[i].sex TO s_data[i].sex
               ATTRIBUTE (REVERSE)

         AFTER FIELD sex

               LET arr_data[i].sex = auxdia
               DISPLAY arr_data[i].sex TO s_data[i].sex

         BEFORE FIELD sab

                CASE 
                   WHEN i=1
                        IF arr_data[i].sab IS NULL THEN
                           NEXT FIELD dom
                        END IF
                        EXIT CASE
                   WHEN i=5 OR i=6
                        IF arr_data[i].sab IS NULL THEN
                           NEXT FIELD sex
                        END IF
                        EXIT CASE
                END CASE   

                LET auxdia = arr_data[i].sab 
                DISPLAY arr_data[i].sab TO s_data[i].sab
                ATTRIBUTE (REVERSE)

          AFTER FIELD sab

                LET arr_data[i].sab = auxdia
                DISPLAY arr_data[i].sab TO s_data[i].sab

         BEFORE FIELD dom

                IF arr_data[i].dom IS NULL THEN
                   NEXT FIELD sab
                END IF 
   
                IF auxdia=fim_mes AND arr_data[i].dom IS NULL THEN
                   NEXT FIELD sab
                END IF

                LET auxdia = arr_data[i].dom
                DISPLAY arr_data[i].dom TO s_data[i].dom
                ATTRIBUTE(REVERSE)

          AFTER FIELD dom

                LET arr_data[i].dom = auxdia
                DISPLAY arr_data[i].dom TO s_data[i].dom
 

          END INPUT

   END IF

   LET dia = auxdia
   RETURN dia

END FUNCTION
{}




##############################################################################
# Funcao que chama o calendario, os argumentos sao a linha e a coluna do     #
# canto superior esquerdo da janela e devolve uma variavel do tipo DATE      #
##############################################################################
{}
FUNCTION d_dia(lin,col)

   DEFINE
        data DATE,
        ano,mes,dia,lin,col INTEGER
{
	OPEN WINDOW w_ano AT 15,20 WITH 1 ROWS,30 COLUMNS
	ATTRIBUTE (BORDER)
   PROMPT"QUAL O ANO PRETENDIDO? "
         FOR ano
   CLOSE WINDOW w_ano
	IF ano IS NULL THEN
		RETURN "      "
   END IF
   LET mes = d_lov_mes(8,20)                      # Permite escolher um mes
	IF mes = 0 THEN
		RETURN "      "
   END IF
	}
	LET ano = year(today)
	LET mes = month(today)
   LET dia = 32

   WHILE dia >31 OR dia <1 OR dia IS NULL
         LET dia = d_cal(mes,ano,lin,col)

         CASE dia                                 # Se a variavel dia for 0
            WHEN 0                                # significa que se pretende
                 IF mes = 1 THEN                  # o mes anterior, se o mes
                    LET mes = 12                  # for 1 o ano tambem muda.
                    LET ano = ano-1
                 ELSE
                    LET mes=mes-1
                 END IF
                 EXIT CASE
            WHEN -1                               # Se a variavel for -1
                 IF mes = 12 THEN                 # significa que se pretende 
                    LET mes = 1                   # o mes seguinte, se o mes
                    LET ano = ano+1               # for 12 o ano tambem muda
                 ELSE
                    LET mes=mes+1
                 END IF
                 EXIT CASE
         END CASE 
  END WHILE  
  RETURN MDY(mes,dia,ano)
END FUNCTION


#  ============================================================================ 
# Conversao de interval para float. A incluir na livraria ???
#  ============================================================================ 
function 	 interval2float(um_intervalo)
{}
   define
		um_intervalo   interval hour(6) to minute,
		str_interval   char(10),
		horas, minutos smallint,
		retval         smallfloat
	
	let str_interval = um_intervalo 
	let horas        = str_interval[1,7]
	if horas is null
	then
		let horas=0
	end if
	let minutos      = str_interval[9,10]
	if minutos is null
	then
		let minutos=0
	end if
	let retval       = horas + minutos / 60
	return retval
end function

#  Funcoes para descodificacao resumida

#  ============================================================================
#  Transforma o dia da semana em dias em portugues.
#  devia ser stored procedure e funcao de livraria
#  Devia receber apenas o weekday como parametro
#  ============================================================================
function d_DescodificaDiaSemana(Dia)
{}
   define
      Dia        date,
      DiaSemana  smallint,
		descr_semana char(4)

	 let DiaSemana = weekday(Dia)
    case DiaSemana
                when 0
                        let descr_semana = "Dom."
                when 1
                        let descr_semana = "Seg."
                when 2
                        let descr_semana = "Ter."
                when 3
                        let descr_semana = "Qua."
                when 4
                        let descr_semana = "Qui."
                when 5
                        let descr_semana = "Sex."
                when 6
                        let descr_semana = "Sab."
        end case

        return descr_semana

end function


#  Tenho ideia que existe uma versao desta funcao na livraria.
#  Podia existir em tored Procedure
#  de qualquer forma devia apenas receber o mes como parametro
function d_DescodificaMes(mes)
 define
           mes         smallint,
			  DescrMes    char(4)

     case
              when mes= 1
                        let DescrMes = "Jan."
              when mes= 2
                        let DescrMes = "Fev."
              when mes= 3
                        let DescrMes = "Mar."
              when mes= 4
                        let DescrMes = "Abr."
              when mes= 5
                        let DescrMes = "Mai."
              when mes= 6
                        let DescrMes = "Jun."
              when mes= 7
                        let DescrMes = "Jul."
              when mes= 8
                        let DescrMes = "Ago."
              when mes= 9
                        let DescrMes = "Set."
              when mes= 10
                        let DescrMes = "Out."
              when mes= 11
                        let DescrMes = "Nov."
              when mes= 12
                        let DescrMes = "Dez."
        end case
        return DescrMes
end function


