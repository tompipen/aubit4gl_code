#DATABASE geral        # Nome da base de dados pretendida
database sysmaster


GLOBALS

DEFINE
          etiquetas_ja_preenchidas ARRAY[10] of record
              linha1 CHAR(68),
              atrib1 CHAR(3),
              linha2 CHAR(68),
              linha3 CHAR(68),
              linha4 CHAR(68),
              linha5 CHAR(68),
              linha6 CHAR(68),
              linha7 CHAR(68),
              linha8 CHAR(68),
              linha9 CHAR(68),
              linha10 CHAR(68),
              linha11 CHAR(68)
           end record
END GLOBALS
 


###############################################################################
# Programa exemplo que prepara os dados e chama as funcoes respectivas        #
###############################################################################
# VARIAVEIS :                                                                 #
#       pr_etiqueta     : Record que vai conter nos campos 'linha' os dados   #
#                         que se pretende imprimir e nos campos 'atrib', os   #
#                         atributos dessa 'linha'.                            #
#                                                                             #
#       pr_cliente      : Record que vai conter a informacao que se pretende  #
#                         imprimir e passar para pr_etiqueta.                 #
#                                                                             #
#       contador_copias : Vai contar o numero de copias ja imprimidas.        #
#                                                                             #
#       num_copias      : Numero de copias que se pretende para cada etiqueta #
#                                                                             #
#       tipo_etiq       : Tipo de etiqueta pretendida.                        #
#                                                                             #
#       i               : Variavel que verifica se e' a primeira impressao    #
#                         para o caso de se comecar a imprimir na segunda     #
#                         etiqueta da primeira linha.                         #
#                                                                             #
#       j               : Index do array.                                     #
#                                                                             #
#       pos_1_etiq      : Posicao da primeira etiqueta.                       #
#                                                                             #
#       etiq_numa_linha : O tipo de etiqueta vai implicar o numero de         #
#                         etiquetas numa linha que esta variavel vai conter.  #
###############################################################################


FUNCTION etiquetas(tipo_etiq,pos_1_etiq,num_copias,atrib)


	 DEFINE 
          pr_etiqueta RECORD
          linha1 CHAR(68),
          atrib1 CHAR(3),
          linha2 CHAR(68),
          linha3 CHAR(68),
          linha4 CHAR(68),
          linha5 CHAR(68),
          linha6 CHAR(68),
          linha7 CHAR(68),
          linha8 CHAR(68),
			 linha9 CHAR(68),
			 linha10 CHAR(68),
			 linha11 CHAR(68)
          END RECORD
#          pr_cliente RECORD LIKE armazens.*,     # NOME DA TABELA PRETENDIDA
#| The symbol "table-name" is not the name of a table in the
#| specified database.
#| See error number -4320.


    display "FIXME: no database"
    exit program (4)

{
          contador_copias,num_copias SMALLINT,  
          atrib CHAR(3),
          tipo_etiq,i,j,pos_1_etiq,etiq_numa_linha,fim_etiq SMALLINT






	  # ***** VALIDACAO DOS DADOS INSERIDOS ***** #

     LET etiq_numa_linha = d_ini_etiq(tipo_etiq)  
	  IF etiq_numa_linha = 0 THEN
		  CALL mesg(" TIPO DE ETIQUETA NAO EXISTENTE")
        EXIT PROGRAM
	  END IF
	  IF pos_1_etiq > etiq_numa_linha THEN
		  CALL mesg(" POSICAO INVALIDA")
		  EXIT PROGRAM
     END IF
	 

     LET i = 1                                  
     LET j = 1

     DECLARE cr_lista CURSOR FOR
             SELECT * FROM armazens
	#			 WHERE nome = "CARLOTA" 


     FOREACH cr_lista INTO pr_cliente.*
             FOR contador_copias =1 TO num_copias 
                 LET pr_etiqueta.linha1 = pr_cliente.nome CLIPPED

					  # ***** ATRIBUTOS DA IMPRESSORA PRETENDIDOS PELO PROGRAMADOR
                 LET pr_etiqueta.atrib1 = atrib 

					  LET pr_etiqueta.linha2 = pr_cliente.localizacao CLIPPED
                 LET pr_etiqueta.linha3 = pr_cliente.cod_arm CLIPPED
                 LET pr_etiqueta.linha4 = pr_cliente.tamanho CLIPPED
					  LET pr_etiqueta.linha5 = "ola"
					  LET pr_etiqueta.linha6 = "inte"
					  LET pr_etiqueta.linha7 = "hello"
                 LET pr_etiqueta.linha8 = pr_cliente.responsavel CLIPPED

                 CALL d_impr_etiq(pr_etiqueta.*,pos_1_etiq,i,etiq_numa_linha,
											 j,tipo_etiq)
					       RETURNING i,j
              END FOR 
     END FOREACH



		# *****  VERIFICACAO DO NUMERO DE COPIAS NO FIM DO FOREACH ***** # 

    IF num_copias < contador_copias AND j != 1 THEN  
		 LET fim_etiq = j-1
       OUTPUT TO REPORT r_etiquetas(tipo_etiq,i,0,fim_etiq)
    END IF

    CALL d_end_etiq()
}
END FUNCTION  



###############################################################################
#     Conjunto de funcoes que vao permitir a impressao de varios tipos de     #
#     etiquetas com n copias                                                  #
###############################################################################
  


###############################################################################
# Funcao que inicializa o report e determina dependendo do tipo de etiqueta   #
# o numero de etiquetas numa linha(etiq_numa_linha).                          #
#.............................................................................#
# ENTRADAS : tipo_etiq                                                        #
#                   O tipo de etiqueta.                                       #
#.............................................................................#
# SAIDAS   : etiq_numa_linha                                                  #
#                   Numero de etiquetas por linha que o tipo de etiqueta      #
#                   permite.                                                  #
###############################################################################



{}
       # *****    INICIALIZACAO DAS ETIQUETAS ***** # 

FUNCTION d_ini_etiq(tipo_etiq)                 
	
   DEFINE 
      tipo_etiq,
		etiq_numa_linha SMALLINT,
      nome_fich CHAR(20),
		proc      integer

	LET proc      = d_getpid() 
	LET nome_fich = "etiq",proc USING "<<<<<"  

   START REPORT r_etiquetas TO nome_fich

   CASE  
        WHEN tipo_etiq >= 4300 AND tipo_etiq<=4306 
             LET etiq_numa_linha = 1 
             EXIT CASE
        WHEN tipo_etiq >=4311 AND tipo_etiq<=4316 OR tipo_etiq = 4000 
             LET etiq_numa_linha =2 
             EXIT CASE
        WHEN tipo_etiq >= 4321 AND tipo_etiq <=4329
             LET etiq_numa_linha = 3
             EXIT CASE
        WHEN tipo_etiq >= 4332 AND tipo_etiq <= 4335
             LET etiq_numa_linha = 4
             EXIT CASE
        OTHERWISE
				 LET etiq_numa_linha = 0
				 EXIT CASE
   END CASE

   RETURN etiq_numa_linha

END FUNCTION




##############################################################################
# Funcao que recebe a informacao a ser impressa , controlo da impressao do   #
# numero de etiquetas possivel por linha e controlo da posicao da primeira   #
# etiqueta.                                                                  #
#............................................................................#
# ENTRADAS :                                                                 #
#           pr_etiqueta                                                      #
#                - Record que contem informacao para ser imprimida e  vai    #
#                  ser transportada para o array.                            #
#                                                                            #
#           pos_1_etiq                                                       #
#                -  Posicao da primeira etiqueta.                            #
#                                                                            #
#           i                                                                #
#                - Variavel que vai controlar se e' a primeira linha da      #
#                  impressao. Se for vai verificar a pos_1_etiq para ver     #
#                  em que etiqueta vai comecar.                              #
#                                                                            #
#           etiq_numa_linha                                                  #
#                - O numero de etiquetas numa linha. Quando o indice do      #
#                  array atinjir este valor, faz_se o output do report.      #
#                                                                            #
#           j                                                                #
#                - Indice do array.                                          #
#............................................................................#
# VARIAVEIS :                                                                #
#            aux_etiq                                                        #
#                    - Vai servir para guardar o valor da variavel           #
#                      etiq_numa_linha se pos_1_etiq for diferente de 1.     #
##############################################################################



{}

FUNCTION d_impr_etiq(pr_etiqueta,pos_1_etiq,i,etiq_numa_linha,j,tipo_etiq)

   DEFINE pr_etiqueta RECORD
       linha1 CHAR(68),
       atrib1 CHAR(3),
       linha2 CHAR(68),
       linha3 CHAR(68),
       linha4 CHAR(68),
       linha5 CHAR(68),
       linha6 CHAR(68),
       linha7 CHAR(68),
       linha8 CHAR(68),
       linha9 CHAR(68),
       linha10 CHAR(68),
       linha11 CHAR(68)
       END RECORD,

       ret,pos_1_etiq,j,i,etiq_numa_linha,aux_etiq,
		 tipo_etiq,num_etiq SMALLINT       

   LET aux_etiq = etiq_numa_linha       # para saber em que etiqueta vai
   LET num_etiq = etiq_numa_linha
   IF i = 1 THEN                        # Controlo da primeira impressao#
      IF pos_1_etiq != 1 THEN           # Posicao da primeira etiqueta#       
         CASE 
              WHEN pos_1_etiq = 2 
                   CASE
                        WHEN etiq_numa_linha = 2
                             LET etiq_numa_linha = 1
                        WHEN etiq_numa_linha = 3
                             LET etiq_numa_linha = 2
                        WHEN etiq_numa_linha = 4
                             LET etiq_numa_linha = 3
                   END CASE
              WHEN pos_1_etiq = 3
                   CASE
                        WHEN etiq_numa_linha = 3
                             LET etiq_numa_linha = 1 
                        WHEN etiq_numa_linha = 4
                             LET etiq_numa_linha = 2
                   END CASE
              WHEN pos_1_etiq = 4
                   LET etiq_numa_linha = 1 
         END CASE
      END IF
   END IF

   FOR j =j TO etiq_numa_linha  
       LET etiquetas_ja_preenchidas[j].linha1 = pr_etiqueta.linha1
       LET etiquetas_ja_preenchidas[j].atrib1 = pr_etiqueta.atrib1
       LET etiquetas_ja_preenchidas[j].linha2 = pr_etiqueta.linha2
       LET etiquetas_ja_preenchidas[j].linha3 = pr_etiqueta.linha3
       LET etiquetas_ja_preenchidas[j].linha4 = pr_etiqueta.linha4
       LET etiquetas_ja_preenchidas[j].linha5 = pr_etiqueta.linha5
       LET ret = linhas5(tipo_etiq)
       IF ret = 0 THEN
          LET etiquetas_ja_preenchidas[j].linha6 = pr_etiqueta.linha6
          LET etiquetas_ja_preenchidas[j].linha7 = pr_etiqueta.linha7
          LET etiquetas_ja_preenchidas[j].linha8 = pr_etiqueta.linha8
          LET ret = linhas8(tipo_etiq)
          IF ret = 0 THEN
             LET etiquetas_ja_preenchidas[j].linha9 = pr_etiqueta.linha9
             LET etiquetas_ja_preenchidas[j].linha10 = pr_etiqueta.linha10
             LET etiquetas_ja_preenchidas[j].linha11 = pr_etiqueta.linha11
          END IF 
        END IF

       IF j < etiq_numa_linha THEN
          EXIT FOR
       END IF

   END FOR

   IF j >= etiq_numa_linha THEN
      OUTPUT TO REPORT r_etiquetas(tipo_etiq,i,pos_1_etiq,num_etiq)
      LET etiq_numa_linha = aux_etiq
      LET j=1
      LET i =0
   ELSE
      LET j=j+1
   END IF

   RETURN i,j

END FUNCTION




###############################################################################
# Report das etiquetas                                                        #
###############################################################################


REPORT r_etiquetas(tipo_etiq,i,pos_1_etiq,num_etiq)
{}

   DEFINE 
      j,i,tipo_etiq,pos_1_etiq,num_etiq,col,col1,teste,ret SMALLINT,
      comp,car DECIMAL(3,1),
      x CHAR(1)

   OUTPUT

   LEFT MARGIN 0
   RIGHT MARGIN 0 
   TOP MARGIN 0
   BOTTOM MARGIN 0
   PAGE LENGTH 64 

   FORMAT
   FIRST PAGE HEADER
         LET j = 1
         CASE 
              WHEN etiquetas_ja_preenchidas[j].atrib1[1] = "1"
                   PRINT pica();
                   LET car = 10
              WHEN etiquetas_ja_preenchidas[j].atrib1[1] = "2"
                   PRINT elite();
                   LET car = 12
              WHEN etiquetas_ja_preenchidas[j].atrib1[1] = "3" 
                   PRINT cond();
                   LET car = (17.1)
              WHEN etiquetas_ja_preenchidas[j].atrib1[1] = "4" 
                   PRINT enlarged();
                   LET car = 5

        END CASE
        CASE
             WHEN  etiquetas_ja_preenchidas[j].atrib1[2] = "T" 
        END CASE
        CASE
             WHEN  etiquetas_ja_preenchidas[j].atrib1[3] = "T"
				       PRINT nlq();
				 WHEN  etiquetas_ja_preenchidas[j].atrib1[3] = "F"
						 PRINT draft();
        END CASE


   ON EVERY ROW    #Calculo da primeira impressao#
        PRINT ASCII 27, "A", ASCII 13, ASCII 27, "2";
        LET comp = comp_etiq(tipo_etiq)
        LET col = comp*car+0.5
        LET teste = 1


   WHILE teste = 1


        # VERIFICACAO DOS ATRIBUTOS E IMPRESSAO DA LINHA1 #
        LET j = 1
        IF tipo_etiq >= 4300 AND tipo_etiq <= 4306 THEN
           PRINT COLUMN 1,etiquetas_ja_preenchidas[j].linha1 CLIPPED
        ELSE
           IF i = 1 AND pos_1_etiq != 1 THEN
              CASE
                   WHEN  pos_1_etiq = 2
								LET col = col+9
                        PRINT COLUMN col,
                        etiquetas_ja_preenchidas[j].linha1 CLIPPED;
                        IF num_etiq = 3 OR num_etiq = 4 THEN
									LET col=col-9
                           LET col1=col*2
									LET col1 = col1+8
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha1 CLIPPED;
                           IF num_etiq = 4 THEN
										LET col1=col*3
										LET col1=col1+7
                              PRINT COLUMN col1,
                              etiquetas_ja_preenchidas[j+1].linha1 CLIPPED;
										PRINT
                           ELSE
                              PRINT
                           END IF
                        ELSE 
									LET col=col-9
                           PRINT
                        END IF
                   WHEN pos_1_etiq = 3
                        LET col1= col*2
								LET col1=col1+8
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha1 CLIPPED;
                        IF num_etiq = 4 THEN
                           LET col1=col*3
									LET col1=col1+7
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha1 CLIPPED;
									PRINT
                        ELSE 
                           PRINT
                        END IF
                   WHEN pos_1_etiq = 4
                        LET col1 = col*3
								LET col1 = col1+7
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha1 CLIPPED;
								PRINT
                END CASE
         ELSE 
				 IF i = 1 THEN
					 LET col = col+9
             ELSE
					 LET col = col+10
             END IF
                PRINT COLUMN 1,
                etiquetas_ja_preenchidas[j].linha1 CLIPPED;
                IF num_etiq =2 OR num_etiq = 3 OR num_etiq = 4 CLIPPED THEN
                PRINT COLUMN col,
                etiquetas_ja_preenchidas[j+1].linha1 CLIPPED;
                IF num_etiq = 3 OR num_etiq = 4 THEN
				       IF i = 1 THEN
				   	    LET col = col-9
                   ELSE
				   	    LET col = col-10
                   END IF
                   LET col1=col*2
						 IF i = 1 THEN 
						    LET col1 = col1+9
                   ELSE
							 LET col1 = col1+10
                   END IF
  			        	LET col1 = col1-1
						PRINT COLUMN col1,
						etiquetas_ja_preenchidas[j+2].linha1 CLIPPED;
						LET col1 = col1+1
						IF i = 1 THEN
							LET col = col+9
							LET col1 = col1-9
                  ELSE
							LET col = col+10
							LET col1 = col1-10
                  END IF
                  IF num_etiq = 4 THEN
				         IF i = 1 THEN
				            LET col = col-9
                     ELSE
				            LET col = col-10
                     END IF
                     LET col1=col*3
					      IF i = 1 THEN 
					         LET col1 = col1+9
                     ELSE
					         LET col1 = col1+10
                     END IF
							LET col1 = col1-2
							PRINT COLUMN col1,
                     etiquetas_ja_preenchidas[j+3].linha1 CLIPPED;
							LET col1 = col1+2
						   IF i = 1 THEN
						    	LET col = col+9
							   LET col1 = col1-9
                     ELSE
						   	LET col = col+10
						   	LET col1 = col1-10
                     END IF
							PRINT
                 ELSE
                     PRINT
                 END IF
             ELSE
					  PRINT
           END IF
        ELSE
           PRINT
        END IF
     END IF
  END IF




        # VERIFICACAO DOS ATRIBUTOS E IMPRESSAO DA LINHA2 #
		  IF i = 1 THEN 
		     LET col = col-9
        ELSE 
		     LET col = col-10
        END IF
        LET j = 1
        IF tipo_etiq >= 4300 AND tipo_etiq <= 4306 THEN
           PRINT COLUMN 1,etiquetas_ja_preenchidas[j].linha2 CLIPPED
        ELSE
           IF i = 1 AND pos_1_etiq != 1 THEN
              CASE
                   WHEN pos_1_etiq = 2
								LET col = col+9
                        PRINT COLUMN col,
                        etiquetas_ja_preenchidas[j].linha2 CLIPPED;
                        IF num_etiq = 3 OR num_etiq = 4 THEN
                           LET col1=col*2
									LET col1=col1-1
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha2 CLIPPED;
                           IF num_etiq = 4 THEN
                              LET col1=col*3
										LET col1=col1-2
                              PRINT COLUMN col1,
                              etiquetas_ja_preenchidas[j+1].linha2 CLIPPED;
										PRINT
                           ELSE
                              PRINT
                           END IF
                        ELSE 
                              PRINT
                        END IF
                   WHEN pos_1_etiq = 3
								LET col = col+9
                        LET col1= col*2
								LET col1=col1-1
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha2 CLIPPED;
                        IF num_etiq = 4 THEN
                           LET col1=col*3
									LET col1=col1-2
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha2 CLIPPED;
									PRINT
                        ELSE 
                           PRINT
                        END IF
                   WHEN pos_1_etiq = 4
								LET col = col+9
                        LET col1 = col*3
								LET col1 = col1-2
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha2 CLIPPED;
								PRINT
                END CASE
         ELSE 
             PRINT COLUMN 1,
             etiquetas_ja_preenchidas[j].linha2 CLIPPED;
             IF num_etiq =2 OR num_etiq = 3 OR num_etiq = 4 CLIPPED THEN
                PRINT COLUMN col,
                etiquetas_ja_preenchidas[j+1].linha2 CLIPPED;
                IF num_etiq = 3 OR num_etiq = 4 THEN
                   LET col1=col*2
		  				LET col1=col1-1
		     		  PRINT COLUMN col1, etiquetas_ja_preenchidas[j+2].linha2
					  CLIPPED;
					  LET col1=col1+1
                 IF num_etiq = 4 THEN
                    LET col1=col*3
					     LET col1=col1-2
						  PRINT COLUMN col1,
                    etiquetas_ja_preenchidas[j+3].linha2 CLIPPED;
						  LET col1=col1+2
					   	PRINT
                 ELSE
                    PRINT
                 END IF
              ELSE 
                  PRINT
           END IF
        ELSE
			  PRINT
        END IF
     END IF
  END IF







        # VERIFICACAO DOS ATRIBUTOS E IMPRESSAO DA LINHA3 #

        LET j = 1
        IF tipo_etiq >= 4300 AND tipo_etiq <= 4306 THEN
           PRINT COLUMN 1,etiquetas_ja_preenchidas[j].linha3 CLIPPED
        ELSE
           IF i = 1 AND pos_1_etiq != 1 THEN
              LET comp = comp_etiq(tipo_etiq) 
              CASE
                   WHEN pos_1_etiq = 2
                        PRINT COLUMN col,
                        etiquetas_ja_preenchidas[j].linha3 CLIPPED;
                        IF num_etiq = 3 OR num_etiq = 4 THEN
                           LET col1=col*2
									LET col1=col1-1
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha3 CLIPPED;
                           IF num_etiq = 4 THEN
                              LET col1=col*3
										LET col1=col1-2
                              PRINT COLUMN col1,
                              etiquetas_ja_preenchidas[j+1].linha3 CLIPPED;
										PRINT
                           ELSE
                              PRINT
                           END IF
                        ELSE 
                              PRINT
                        END IF
                   WHEN pos_1_etiq = 3
                        LET col1= col*2
								LET col1=col1-1
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha3 CLIPPED;
                        IF num_etiq = 4 THEN
                           LET col1=col*3
									LET col1=col1-2
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha3 CLIPPED;
									PRINT
                        ELSE 
                           PRINT
                        END IF
                   WHEN pos_1_etiq = 4
                        LET col1 = col*3
								LET col1=col1-2
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha3 CLIPPED;
								PRINT
                END CASE
         ELSE
				 PRINT COLUMN 1,
             etiquetas_ja_preenchidas[j].linha3 CLIPPED;
             IF num_etiq =2 OR num_etiq = 3 OR num_etiq = 4 CLIPPED THEN
					 PRINT COLUMN col,
                etiquetas_ja_preenchidas[j+1].linha3 CLIPPED;
                IF num_etiq = 3 OR num_etiq = 4 THEN
                   LET col1=col*2
			   	    LET col1=col1-1
                   PRINT COLUMN col1,
                   etiquetas_ja_preenchidas[j+2].linha3 CLIPPED;
					    LET col1=col1+1
                   IF num_etiq = 4 THEN
                      LET col1=col*3
						    LET col1=col1-2
                      PRINT COLUMN col1,
                      etiquetas_ja_preenchidas[j+3].linha3 CLIPPED;
						  	 LET col1=col1+2
							 PRINT
                   ELSE
                      PRINT
                   END IF
                ELSE 
                   PRINT
               END IF
            ELSE
					PRINT
            END IF
         END IF
      END IF



        # VERIFICACAO DOS ATRIBUTOS E IMPRESSAO DA LINHA4 #

        LET j = 1
        IF tipo_etiq >= 4300 AND tipo_etiq <= 4306 THEN
           PRINT COLUMN 1,etiquetas_ja_preenchidas[j].linha4 CLIPPED
        ELSE
           IF i = 1 AND pos_1_etiq != 1 THEN
              LET comp = comp_etiq(tipo_etiq) 
              CASE
                   WHEN pos_1_etiq = 2
                        PRINT COLUMN col,
                        etiquetas_ja_preenchidas[j].linha4 CLIPPED;
                        IF num_etiq = 3 OR num_etiq = 4 THEN
                           LET col1=col*2
									LET col1=col1-1
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha4 CLIPPED;
                           IF num_etiq = 4 THEN
                              LET col1=col*3
										LET col1=col1-2
                              PRINT COLUMN col1,
                              etiquetas_ja_preenchidas[j+1].linha4 CLIPPED;
										PRINT
                           ELSE
                              PRINT
                           END IF
                        ELSE 
                              PRINT
                        END IF
                   WHEN pos_1_etiq = 3
                        LET col1= col*2
								LET col1=col1-1
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha4 CLIPPED;
                        IF num_etiq = 4 THEN
                           LET col1=col*3
									LET col1=col1-2
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha4 CLIPPED;
									PRINT
                        ELSE 
                           PRINT
                        END IF
                   WHEN pos_1_etiq = 4
                        LET col1 = col*3
								LET col1=col1-2
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha4 CLIPPED;
								PRINT
                END CASE
         ELSE
				 PRINT COLUMN 1, etiquetas_ja_preenchidas[j].linha4 CLIPPED;
             IF num_etiq =2 OR num_etiq = 3 OR num_etiq = 4 CLIPPED THEN
                PRINT COLUMN col,
                etiquetas_ja_preenchidas[j+1].linha4 CLIPPED;
               IF num_etiq = 3 OR num_etiq = 4 THEN
                  LET col1=col*2
						LET col1=col1-1
                  PRINT COLUMN col1,
                  etiquetas_ja_preenchidas[j+2].linha4 CLIPPED;
					   LET col1=col1+1
                  IF num_etiq = 4 THEN
                     LET col1=col*3
							LET col1=col1-2
                     PRINT COLUMN col1,
                     etiquetas_ja_preenchidas[j+3].linha4 CLIPPED;
							LET col1=col1+2
							PRINT
                  ELSE
                     PRINT
                  END IF
               ELSE 
                  PRINT
               END IF
            ELSE
					PRINT
            END IF
         END IF
      END IF



        # VERIFICACAO DOS ATRIBUTOS E IMPRESSAO DA LINHA5 #

        LET j = 1
        IF tipo_etiq >= 4300 AND tipo_etiq <= 4306 THEN
           PRINT COLUMN 1,etiquetas_ja_preenchidas[j].linha5 CLIPPED
        ELSE
           IF i = 1 AND pos_1_etiq != 1 THEN
              CASE
                   WHEN pos_1_etiq = 2
                        PRINT COLUMN col,
                        etiquetas_ja_preenchidas[j].linha5 CLIPPED;
                        IF num_etiq = 3 OR num_etiq = 4 THEN
                           LET col1=col*2
									LET col1=col1-1
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha5 CLIPPED;
                           IF num_etiq = 4 THEN
                              LET col1=col*3
										LET col1=col1-2
                              PRINT COLUMN col1,
                              etiquetas_ja_preenchidas[j+1].linha5 CLIPPED;
                           ELSE
                              LET ret = linhas5(tipo_etiq)
                              IF ret = 1 THEN
											EXIT CASE
                              END IF
                           END IF
                        ELSE 
                              LET ret = linhas5(tipo_etiq)
                              IF ret = 1 THEN
											EXIT CASE
                              END IF
                        END IF
                              LET ret = linhas5(tipo_etiq)
                              IF ret = 1 THEN
											EXIT CASE
                              END IF
                   WHEN pos_1_etiq = 3
                        LET col1= col*2
								LET col1=col1-1
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha5 CLIPPED;
                        IF num_etiq = 4 THEN
                           LET col1=col*3
									LET col1=col1-2
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha5 CLIPPED;
                        ELSE 
                              LET ret = linhas5(tipo_etiq)
                              IF ret = 1 THEN
											EXIT CASE
                              END IF
                        END IF
                   WHEN pos_1_etiq = 4
                        LET col1 = col*3
								LET col1 = col1-2
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha5 CLIPPED;
                END CASE
                LET ret = linhas5(tipo_etiq)
                IF ret = 1 THEN
                   PRINT ASCII 27, "A", ASCII 17, ASCII 27, "2";
                   PRINT
                   EXIT WHILE
                ELSE
						 PRINT
                END IF

         ELSE 
             PRINT COLUMN 1,
             etiquetas_ja_preenchidas[j].linha5 CLIPPED;
             IF num_etiq =2 OR num_etiq = 3 OR num_etiq = 4 CLIPPED THEN
                PRINT COLUMN col,
                etiquetas_ja_preenchidas[j+1].linha5 CLIPPED;
                IF num_etiq = 3 OR num_etiq = 4 THEN
                   LET col1=col*2
				   	 LET col1=col1-1
                   PRINT COLUMN col1,
                   etiquetas_ja_preenchidas[j+2].linha5 CLIPPED;
						 LET col1=col1+1
                   IF num_etiq = 4 THEN
                      LET col1=col*3
							 LET col1=col1-2
                      PRINT COLUMN col1,
                      etiquetas_ja_preenchidas[j+3].linha5 CLIPPED;
							 LET col1=col1+2
                      LET ret = linhas5(tipo_etiq)
                      IF ret = 1 THEN
                         PRINT ASCII 27, "A", ASCII 17, ASCII 27, "2";
                         PRINT
                         EXIT WHILE
                      ELSE
								 PRINT
                      END IF
                   ELSE
                      LET ret = linhas5(tipo_etiq)
                      IF ret = 1 THEN
                         PRINT ASCII 27, "A", ASCII 17, ASCII 27, "2";
                         PRINT
                         EXIT WHILE
                      ELSE
						    	 PRINT
                      END IF
                   END IF
               ELSE
                  LET ret = linhas5(tipo_etiq)
                  IF ret = 1 THEN
                     PRINT ASCII 27, "A", ASCII 17, ASCII 27, "2";
                     PRINT
                     EXIT WHILE
                  ELSE
						 	PRINT
                  END IF
               END IF
           ELSE
              LET ret = linhas5(tipo_etiq)
              IF ret = 1 THEN
                 PRINT ASCII 27, "A", ASCII 17, ASCII 27, "2";
                 PRINT
                 EXIT WHILE
              ELSE
		   	     PRINT
              END IF
           END IF
         END IF
      END IF



        # VERIFICACAO DOS ATRIBUTOS E IMPRESSAO DA LINHA6 #

        LET j = 1
        IF tipo_etiq >= 4300 AND tipo_etiq <= 4306 THEN
           PRINT COLUMN 1,etiquetas_ja_preenchidas[j].linha6 CLIPPED
        ELSE
           IF i = 1 AND pos_1_etiq != 1 THEN
              LET comp = comp_etiq(tipo_etiq) 
              CASE pos_1_etiq
                   WHEN 2
                        PRINT COLUMN col,
                        etiquetas_ja_preenchidas[j].linha6 CLIPPED;
                        IF num_etiq = 3 OR num_etiq = 4 THEN
                           LET col1=col*2
									LET col1=col1-1
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha6 CLIPPED;
                           IF num_etiq = 4 THEN
                              LET col1=col*3
										LET col1=col1-2
                              PRINT COLUMN col1,
                              etiquetas_ja_preenchidas[j+1].linha6 CLIPPED;
										PRINT
                           ELSE
                              PRINT
                           END IF
                        ELSE 
                              PRINT
                        END IF
                   WHEN 3
                        LET col1= col*2
								LET col1=col1-1
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha6 CLIPPED;
                        IF num_etiq = 4 THEN
                           LET col1=col*3
									LET col1=col1-2
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha6 CLIPPED;
									PRINT
                        ELSE 
                           PRINT
                        END IF
                   WHEN 4
                        LET col1 = col*3
								LET col1=col1-2
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha6 CLIPPED;
								PRINT
                END CASE
         ELSE 
             PRINT COLUMN 1,
             etiquetas_ja_preenchidas[j].linha6 CLIPPED;
             IF num_etiq =2 OR num_etiq = 3 OR num_etiq = 4 CLIPPED THEN
                PRINT COLUMN col,
                etiquetas_ja_preenchidas[j+1].linha6 CLIPPED;
                IF num_etiq = 3 OR num_etiq = 4 THEN
                   LET col1=col*2
					  	 LET col1=col1-1
                   PRINT COLUMN col1,
                   etiquetas_ja_preenchidas[j+2].linha6 CLIPPED;
						 LET col1=col1+1
                   IF num_etiq = 4 THEN
                      LET col1=col*3
							 LET col1=col1-2
                      PRINT COLUMN col1,
                      etiquetas_ja_preenchidas[j+3].linha6 CLIPPED;
							 LET col1=col1+2
							 PRINT
                   ELSE
                      PRINT
                   END IF
                ELSE 
                   PRINT
                END IF
				 ELSE
					 PRINT
             END IF
         END IF
      END IF




        # VERIFICACAO DOS ATRIBUTOS E IMPRESSAO DA LINHA7 #

        LET j = 1
        IF tipo_etiq >= 4300 AND tipo_etiq <= 4306 THEN
           PRINT COLUMN 1,etiquetas_ja_preenchidas[j].linha7 CLIPPED
        ELSE
           IF i = 1 AND pos_1_etiq != 1 THEN
              LET comp = comp_etiq(tipo_etiq) 
              CASE pos_1_etiq
                   WHEN 2
                        PRINT COLUMN col,
                        etiquetas_ja_preenchidas[j].linha7 CLIPPED;
                        IF num_etiq = 3 OR num_etiq = 4 THEN
                           LET col1=col*2
									LET col1=col1-1
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha7 CLIPPED;
                           IF num_etiq = 4 THEN
                              LET col1=col*3
										LET col1=col1-2
                              PRINT COLUMN col1,
                              etiquetas_ja_preenchidas[j+1].linha7 CLIPPED;
										PRINT
                           ELSE
                              PRINT
                           END IF
                        ELSE 
                              PRINT
                        END IF
                   WHEN 3
                        LET col1= col*2
								LET col1=col1-1
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha7 CLIPPED;
                        IF num_etiq = 4 THEN
                           LET col1=col*3
									LET col1=col1-2
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha7 CLIPPED;
									PRINT
                        ELSE 
                           PRINT
                        END IF
                   WHEN 4
                        LET col1 = col*3
								LET col1=col1-2
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha7 CLIPPED;
								PRINT
                END CASE
         ELSE 
             PRINT COLUMN 1,
             etiquetas_ja_preenchidas[j].linha7 CLIPPED;
             IF num_etiq =2 OR num_etiq = 3 OR num_etiq = 4 CLIPPED THEN
                PRINT COLUMN col,
                etiquetas_ja_preenchidas[j+1].linha7 CLIPPED;
                IF num_etiq = 3 OR num_etiq = 4 THEN
                   LET col1=col*2
					  	 LET col1=col1-1
						 PRINT COLUMN col1,
                   etiquetas_ja_preenchidas[j+2].linha7 CLIPPED;
						 LET col1=col1+1
                   IF num_etiq = 4 THEN
                      LET col1=col*3
							 LET col1=col1-2
                      PRINT COLUMN col1,
                      etiquetas_ja_preenchidas[j+3].linha7 CLIPPED;
							 LET col1=col1+2
							 PRINT
                   ELSE
                      PRINT
                   END IF
                ELSE 
                   PRINT
                END IF
			  ELSE
				  PRINT
           END IF
        END IF
    END IF




        # VERIFICACAO DOS ATRIBUTOS E IMPRESSAO DA LINHA8 #

        LET j = 1
        IF tipo_etiq >= 4300 AND tipo_etiq <= 4306 THEN
           PRINT COLUMN 1,etiquetas_ja_preenchidas[j].linha8 CLIPPED
        ELSE
           IF i = 1 AND pos_1_etiq != 1 THEN
              LET comp = comp_etiq(tipo_etiq) 
              CASE pos_1_etiq
                   WHEN 2
                        PRINT COLUMN col,
                        etiquetas_ja_preenchidas[j].linha8 CLIPPED;
                        IF num_etiq = 3 OR num_etiq = 4 THEN
                           LET col1=col*2
									LET col1=col1-1
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha8 CLIPPED;
                           IF num_etiq = 4 THEN
                              LET col1=col*3
										LET col1=col1-2
                              PRINT COLUMN col1,
                              etiquetas_ja_preenchidas[j+1].linha8 CLIPPED;
                           ELSE
                              LET ret = linhas8(tipo_etiq)
                              IF ret = 1 THEN
											EXIT CASE
                              END IF
                           END IF
                        ELSE 
                              LET ret = linhas8(tipo_etiq)
                              IF ret = 1 THEN
											EXIT CASE
                              END IF
                        END IF
                   WHEN 3
                        LET col1= col*2
								LET col1=col1-1
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha8 CLIPPED;
                        IF num_etiq = 4 THEN
                           LET col1=col*3
									LET col1=col1-2
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha8 CLIPPED;
                        ELSE 
                              LET ret = linhas8(tipo_etiq)
                              IF ret = 1 THEN
											EXIT CASE
                              END IF
                        END IF
                   WHEN 4
                        LET col1 = col*3
								LET col1=col1-2
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha8 CLIPPED;
                END CASE
                  LET ret = linhas8(tipo_etiq)
                  IF ret = 1 THEN
                     PRINT ASCII 27, "A", ASCII 17, ASCII 27, "2";
                     PRINT
                     EXIT WHILE
                  ELSE
							PRINT
                  END IF
         ELSE 
             PRINT COLUMN 1,
             etiquetas_ja_preenchidas[j].linha8 CLIPPED;
             IF num_etiq =2 OR num_etiq = 3 OR num_etiq = 4 CLIPPED THEN
                PRINT COLUMN col,
                etiquetas_ja_preenchidas[j+1].linha8 CLIPPED;
                IF num_etiq = 3 OR num_etiq = 4 THEN
                   LET col1=col*2
				  		 LET col1=col1-1
                   PRINT COLUMN col1,
                   etiquetas_ja_preenchidas[j+2].linha8 CLIPPED;
						 LET col1=col1+1
                   IF num_etiq = 4 THEN
                      LET col1=col*3
							 LET col1=col1-2
                      PRINT COLUMN col1,
                      etiquetas_ja_preenchidas[j+3].linha8 CLIPPED;
							 LET col1=col1+2
                      LET ret = linhas8(tipo_etiq)
                      IF ret = 1 THEN
                         PRINT ASCII 27, "A", ASCII 17, ASCII 27, "2";
                         PRINT
                         EXIT WHILE
                      ELSE
				           	 PRINT
                      END IF
                   ELSE
                      LET ret = linhas8(tipo_etiq)
                      IF ret = 1 THEN
                         PRINT ASCII 27, "A", ASCII 17, ASCII 27, "2";
                         PRINT
                         EXIT WHILE
                      ELSE
				           	 PRINT
                      END IF
                   END IF
               ELSE 
                  LET ret = linhas8(tipo_etiq)
                  IF ret = 1 THEN
                     PRINT ASCII 27, "A", ASCII 17, ASCII 27, "2";
                     PRINT
                     EXIT WHILE
                  ELSE
							PRINT
                  END IF
               END IF
            ELSE
                  LET ret = linhas8(tipo_etiq)
                  IF ret = 1 THEN
                     PRINT ASCII 27, "A", ASCII 17, ASCII 27, "2";
                     PRINT
                     EXIT WHILE
                  ELSE
							PRINT
                  END IF
           END IF
         END IF
       END IF




        # VERIFICACAO DOS ATRIBUTOS E IMPRESSAO DA LINHA9 #

        LET j = 1
        IF tipo_etiq >= 4300 AND tipo_etiq <= 4306 THEN
           PRINT COLUMN 1,etiquetas_ja_preenchidas[j].linha9 CLIPPED
        ELSE
           IF i = 1 AND pos_1_etiq != 1 THEN
              LET comp = comp_etiq(tipo_etiq) 
              CASE pos_1_etiq
                   WHEN 2
                        PRINT COLUMN col,
                        etiquetas_ja_preenchidas[j].linha9 CLIPPED;
                        IF num_etiq = 3 OR num_etiq = 4 THEN
                           LET col1=col*2
									LET col1=col1-1
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha9 CLIPPED;
                           IF num_etiq = 4 THEN
                              LET col1=col*3
										LET col1=col1-2
                              PRINT COLUMN col1,
                              etiquetas_ja_preenchidas[j+1].linha9 CLIPPED;
                           ELSE
                              PRINT
                           END IF
                        ELSE 
                              PRINT
                        END IF
                   WHEN 3
                        LET col1= col*2
								LET col1=col1-1
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha9 CLIPPED;
                        IF num_etiq = 4 THEN
                           LET col1=col*3
									LET col1=col1-2
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha9 CLIPPED;
									PRINT
                        ELSE 
                           PRINT
                        END IF
                   WHEN 4
                        LET col1 = col*3
								LET col1=col1-2
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha9 CLIPPED;
								PRINT
                END CASE
         ELSE 
             PRINT COLUMN 1,
             etiquetas_ja_preenchidas[j].linha9 CLIPPED;
             IF num_etiq =2 OR num_etiq = 3 OR num_etiq = 4 THEN
                PRINT COLUMN col,
                etiquetas_ja_preenchidas[j+1].linha9 CLIPPED;
                IF num_etiq = 3 OR num_etiq = 4 THEN
                   LET col1=col*2
					  	 LET col1=col1-1
                   PRINT COLUMN col1,
                   etiquetas_ja_preenchidas[j+2].linha9 CLIPPED;
						 LET col1=col1+1
                   IF num_etiq = 4 THEN
                      LET col1=col*3
							 LET col1=col1-2
                      PRINT COLUMN col1,
                      etiquetas_ja_preenchidas[j+3].linha9 CLIPPED;
						    LET col1=col1+2
							 PRINT
                   ELSE
                      PRINT
                   END IF
               ELSE 
                  PRINT
               END IF
			  ELSE
				  PRINT
           END IF
         END IF
      END IF





        # VERIFICACAO DOS ATRIBUTOS E IMPRESSAO DA LINHA10 #

        LET j = 1
        IF tipo_etiq >= 4300 AND tipo_etiq <= 4306 THEN
           PRINT COLUMN 1,etiquetas_ja_preenchidas[j].linha10 CLIPPED
        ELSE
           IF i = 1 AND pos_1_etiq != 1 THEN
              LET comp = comp_etiq(tipo_etiq) 
              CASE pos_1_etiq
                   WHEN 2
                        PRINT COLUMN col,
                        etiquetas_ja_preenchidas[j].linha10 CLIPPED;
                        IF num_etiq = 3 OR num_etiq = 4 THEN
                           LET col1=col*2
									LET col1=col1-1
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha10 CLIPPED;
                           IF num_etiq = 4 THEN
                              LET col1=col*3
										LET col1=col1-2
                              PRINT COLUMN col1,
                              etiquetas_ja_preenchidas[j+1].linha10 CLIPPED;
										PRINT
                           ELSE
                              PRINT
                           END IF
                        ELSE 
                              PRINT
                        END IF
                   WHEN 3
                        LET col1= col*2
								LET col1=col1-1
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha10 CLIPPED;
                        IF num_etiq = 4 THEN
                           LET col1=col*3
									LET col1=col1-2
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha10 CLIPPED;
									PRINT
                        ELSE 
                           PRINT
                        END IF
                   WHEN 4
                        LET col1 = col*3
								LET col1=col1-2
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha10 CLIPPED;
								PRINT
                END CASE
         ELSE 
             PRINT COLUMN 1,
             etiquetas_ja_preenchidas[j].linha10 CLIPPED;
             IF num_etiq =2 OR num_etiq = 3 OR num_etiq = 4 CLIPPED THEN
                PRINT COLUMN col,
                etiquetas_ja_preenchidas[j+1].linha10 CLIPPED;
                IF num_etiq = 3 OR num_etiq = 4 THEN
                   LET col1=col*2
					  	 LET col1=col1-1
                   PRINT COLUMN col1,
                   etiquetas_ja_preenchidas[j+2].linha10 CLIPPED;
						 LET col1=col1+1
                   IF num_etiq = 4 THEN
                      LET col1=col*3
							 LET col1=col1-2
                      PRINT COLUMN col1,
                      etiquetas_ja_preenchidas[j+3].linha10 CLIPPED;
							 LET col1=col1+2
							 PRINT
                   ELSE
                      PRINT
                   END IF
                ELSE 
                   PRINT
                END IF
			  ELSE
				  PRINT
           END IF
        END IF
     END IF







        # VERIFICACAO DOS ATRIBUTOS E IMPRESSAO DA LINHA11 #

        LET j = 1
        IF tipo_etiq >= 4300 AND tipo_etiq <= 4306 THEN
           PRINT COLUMN 1,etiquetas_ja_preenchidas[j].linha11 CLIPPED
        ELSE
           IF i = 1 AND pos_1_etiq != 1 THEN
              LET comp = comp_etiq(tipo_etiq) 
              CASE pos_1_etiq
                   WHEN 2
                        PRINT COLUMN col,
                        etiquetas_ja_preenchidas[j].linha11 CLIPPED;
                        IF num_etiq = 3 OR num_etiq = 4 THEN
                           LET col1=col*2
									LET col1=col1-1
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha11 CLIPPED;
                           IF num_etiq = 4 THEN
                              LET col1=col*3
										LET col1=col1-2
                              PRINT COLUMN col1,
                              etiquetas_ja_preenchidas[j+1].linha11 CLIPPED;
										PRINT
                           ELSE
                              PRINT
                           END IF
                        ELSE 
                              PRINT
                        END IF
                   WHEN 3
                        LET col1= col*2
								LET col1=col1-1
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha11 CLIPPED;
                        IF num_etiq = 4 THEN
                           LET col1=col*3
									LET col1=col1-2
                           PRINT COLUMN col1,
                           etiquetas_ja_preenchidas[j+1].linha11 CLIPPED;
									PRINT
                        ELSE 
                           PRINT
                        END IF
                   WHEN 4
                        LET col1 = col*3
								LET col1=col1-2
                        PRINT COLUMN col1,
                        etiquetas_ja_preenchidas[j].linha11 CLIPPED
								PRINT
                END CASE
         ELSE 
             PRINT COLUMN 1,
             etiquetas_ja_preenchidas[j].linha11 CLIPPED;
             IF num_etiq =2 OR num_etiq = 3 OR num_etiq = 4 CLIPPED THEN
                PRINT COLUMN col,
                etiquetas_ja_preenchidas[j+1].linha11 CLIPPED;
                IF num_etiq = 3 OR num_etiq = 4 THEN
                   LET col1=col*2
					  	 LET col1=col1-1
                   PRINT COLUMN col1,
                   etiquetas_ja_preenchidas[j+2].linha11 CLIPPED;
						 LET col1=col1+1
                   IF num_etiq = 4 THEN
                      LET col1=col*3
							 LET col1=col1-2
                      PRINT COLUMN col1,
                      etiquetas_ja_preenchidas[j+3].linha11 CLIPPED;
							 LET col1=col1+2
							 PRINT
                   ELSE
                      PRINT ASCII 27, "A", ASCII 17, ASCII 27, "2";
                      PRINT
                   END IF
                ELSE 
                   PRINT ASCII 27, "A", ASCII 17, ASCII 27, "2";
                   PRINT
                END IF
				ELSE
					PRINT
            END IF
         END IF
       END IF
		 EXIT WHILE

END WHILE

PRINT ASCII 27, "A", ASCII 12, ASCII 27, "2";
ON LAST ROW

PRINT ASCII 27, "A", ASCII 12, ASCII 27, "2";
CASE car
     WHEN 17.1
          PRINT nocond();
     WHEN 5
          PRINT noenlarged();
END CASE
PRINT draft();
          

END REPORT





################################################################################
# Funcao que termina o report                                                  #
################################################################################

FUNCTION d_end_etiq()
{}
   FINISH REPORT r_etiquetas

END FUNCTION 



#################################################################################  Funcao que verifica se o tipo de etiqueta tem cinco linhas                  #################################################################################
#                                                                              #
#   ENTRADAS:                                                                  #
#       tipo_etiq - Tipo de etiqueta                                           #
#..............................................................................##                                                                              #
#   SAIDAS:                                                                    #
#       1 - Retorna 1 se for verdade                                           #
#                                                                              #
#       0 - Retorna 0 se for falso                                             #
#                                                                              #
################################################################################


{}
FUNCTION linhas5(tipo_etiq)

DEFINE 
     tipo_etiq SMALLINT

IF tipo_etiq = 4300 OR
   tipo_etiq = 4302 OR
   tipo_etiq = 4305 OR
   tipo_etiq = 4311 OR
   tipo_etiq = 4313 OR
   tipo_etiq = 4315 OR
   tipo_etiq = 4321 OR
   tipo_etiq = 4323 OR
   tipo_etiq = 4325 OR
   tipo_etiq = 4328 OR
   tipo_etiq = 4332 OR
   tipo_etiq = 4334 THEN
      RETURN 1
ELSE
      RETURN 0
END IF

END FUNCTION




#################################################################################  Funcao que verifica se o tipo de etiqueta tem oito  linhas                  #################################################################################
#                                                                              #
#   ENTRADAS:                                                                  #
#       tipo_etiq - Tipo de etiqueta                                           #
#..............................................................................##                                                                              #
#   SAIDAS:                                                                    #
#       1 - Retorna 1 se for verdade                                           #
#                                                                              #
#       0 - Retorna 0 se for falso                                             #
#                                                                              #
################################################################################




{}
FUNCTION linhas8(tipo_etiq)

DEFINE
     tipo_etiq SMALLINT

IF tipo_etiq = 4301 OR
   tipo_etiq = 4316 OR
   tipo_etiq = 4303 OR
   tipo_etiq = 4306 OR
   tipo_etiq = 4326 OR
   tipo_etiq = 4303 OR
   tipo_etiq = 4312 OR
   tipo_etiq = 4314 OR
   tipo_etiq = 4322 OR
   tipo_etiq = 4324 OR
   tipo_etiq = 4334 OR
	tipo_etiq = 4000 OR
   tipo_etiq = 4335 THEN
      RETURN 1
ELSE
      RETURN 0
END IF

END FUNCTION




#################################################################################  Funcao que verifica o comprimento da etiqueta                               #################################################################################
#                                                                              #
#   ENTRADAS:                                                                  #
#       tipo_etiq - Tipo de etiqueta                                           #
#..............................................................................##                                                                              #
#   SAIDAS:                                                                    #
#       Comp - Retorna o comprimento (contem os respectivos espacos entre      #
#              etiquetas) do tipo de etiqueta.                                 #
#                                                                              #
################################################################################

{}

FUNCTION comp_etiq(tipo_etiq)

DEFINE 
       tipo_etiq SMALLINT,
       comp DECIMAL(3,1)

CASE 
     WHEN tipo_etiq = 4311 OR
          tipo_etiq = 4312 OR
          tipo_etiq = 4321 OR
          tipo_etiq = 4322 OR
          tipo_etiq = 4332 
            LET comp = 3.1
     WHEN tipo_etiq = 4313 OR
          tipo_etiq = 4314 OR
          tipo_etiq = 4323 OR
          tipo_etiq = 4324 
            LET comp = 3.8
     WHEN tipo_etiq = 4315 OR
          tipo_etiq = 4325
            LET comp = 4.3
     WHEN tipo_etiq = 4316
				LET comp = 4.4
     WHEN tipo_etiq = 4326 OR
          tipo_etiq = 4000
				LET comp = 4.2
     WHEN tipo_etiq = 4328 OR
          tipo_etiq = 4329
            LET comp = 4.5
     WHEN tipo_etiq = 4334 OR
          tipo_etiq = 4335 
            LET comp = 3.5
END CASE
RETURN comp

END FUNCTION
