

###############################################################################
#
#  Copyright 1992 DESPODATA - Lisboa, PORTUGAL
#                                                        
#  Divisao de desenvolvimento e producao de software.
#                                                        
#  Autor: 
#                                                        
#
#	This Module contains Proprietary and Confidential
#	Information of Despodata - Consultores internacionais Lda.
#
#  Modulo        : %M%
#  SCCSID        : %I%
#  Data do delta : %G%
#  Programa      : Livraria
#  ----------------------------------------------------------------
#  FUNCOES: 
# 
#  ----------------------------------------------------------------
#  FORMS:  NAO USA.
#
#  REPORTS: d_echeque
#
#  NOTAS:
#
###############################################################################

# enquanto nao se usa o fmt da jeito usar esta


FUNCTION flDstring(valor)
{}

  DEFINE valor float
  DEFINE escudos,centavos,resto,i,j,k integer,
			aux array[10] of char(1),
			strE char(10),
			strC char(2)
			
			LET strC="00"
			LET escudos=valor
			LET centavos=(valor-escudos)*100

			LET i=10
			WHILE escudos!=0
			  LET resto=escudos MOD 10
			  LET escudos=escudos/10
			  LET aux[i]=ASCII resto+48
			  LET i=i-1
			END WHILE
			LET j=1
			FOR k=i+1 TO 10
			 LET strE[j]=aux[k]
			 LET j=j+1
			END FOR
			LET i=2
			WHILE centavos!=0
			  LET resto=centavos mod 10
			  LET centavos=centavos/10
			  LET aux[i]=ascii resto+48
			  LET i=i-1
			END WHILE
			IF i!=2 THEN
			  LET j=1
			  FOR k=i+1 TO 2 
			   LET strC[j]=aux[k]
			   LET j=j+1
			  END FOR
         END IF 

         RETURN strE,strC
END FUNCTION

#  =============================================================
#  Report que emite um cheque
#  Atencao ao report to.
#  =============================================================

REPORT d_echeque(escudos,centavos,local,dia,mes,ano,entidade)
	 DEFINE
			 escudos CHAR(10),
			 centavos CHAR(2),
			 local CHAR(14),
			 dia,mes,ano SMALLINT,
			 entidade CHAR(60)
		DEFINE
			dim,j SMALLINT


OUTPUT
	 REPORT TO PRINTER
    LEFT MARGIN 0
    RIGHT MARGIN 0
    TOP MARGIN 0
    BOTTOM MARGIN 0
    PAGE LENGTH 20

FORMAT
	PAGE HEADER
	  SKIP 3 LINES

   ON EVERY ROW
	  {
	  LET dim = LENGTH(escudos CLIPPED)

	  PRINT COLUMN 47;
	  FOR j=1 TO dim
	    PRINT " ";
	  END FOR
	  }
	  PRINT COLUMN 46;
	  PRINT escudos USING "##########" ," ",centavos
	  PRINT
	  {
	  LET dim =( 14 - LENGTH(local CLIPPED)) / 2
	  FOR j=1 TO dim
	    PRINT ' ';
	  END FOR
	  }
	  PRINT COLUMN 46;
	  PRINT local
	  PRINT
	  PRINT COLUMN 47,dia USING "&&";
	  PRINT COLUMN 51,mes USING "&&";
	  PRINT COLUMN 55,ano USING "<<<<"
	  PRINT
	  IF 50 > LENGTH(entidade) THEN
		 PRINT d_elite();
	    PRINT COLUMN 20,entidade;
		 PRINT d_pica()
     ELSE
	    PRINT COLUMN 10,entidade
	  END IF
	  PRINT d_enlarged()
	  PRINT COLUMN 10;
	  PRINT "**",escudos CLIPPED,"$",centavos,"**"
	  PRINT d_noenlarged()
END REPORT
  



#  =============================================================
#  Funcao de emissao de cheques
#  =============================================================


FUNCTION d_emite_cheque(valor,local,data,entidade)
{}

  DEFINE valor float,
			local CHAR(14),
			data DATE,
			entidade CHAR(60)
  DEFINE
		 escudos char(10),
		 centavos char(2),
		 ano INTEGER

  IF valor<=0 THEN
	 CALL d_mesg("Valor de cheque nao e' positivo")
	 RETURN
  END IF
  LET ano=year(data)
  IF ano<2000 THEN
	 LET ano=ano-1900
  ELSE
	 LET ano=ano-2000
  END IF
  CALL flDstring(valor) RETURNING escudos,centavos

  START REPORT d_echeque
  OUTPUT TO REPORT d_echeque(escudos,centavos,local,DAY(data),MONTH(data),ano,entidade)
  FINISH REPORT d_echeque

END FUNCTION


#  =============================================================



