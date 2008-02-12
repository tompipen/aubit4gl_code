{**
 * @file
 * Compile only: generate bad EC code large arrays of record
 * @process TEST_GENERAL
 *}
 
DATABASE test1

DEFINE  ma_tota ARRAY[30,10] OF INT,
        ma_clie ARRAY[30,10] OF INT,
	ma_nubo ARRAY[30] OF RECORD
	    anual INT,
	    mes ARRAY[13] OF RECORD
		bodega INT,
		linea ARRAY[10] OF INT
	    END RECORD
	END RECORD,
	ma_mes ARRAY[13,31,10] OF RECORD
	    nubo SMALLINT,
	    peso INT,
	    porc SMALLINT
	END RECORD

MAIN
DEFINE w RECORD
	   nubo INT,
	   prod INT,
	   unid INT,
	   unic INT,
	   ano, mes SMALLINT
       END RECORD,
       a_nubo INT,
       i_nubo, i_mes, i_line SMALLINT

FOR i_nubo = 1 TO 30 
    LET ma_nubo[i_nubo].anual = 0
    FOR i_mes = 1 TO 13
        LET ma_nubo[i_nubo].mes[i_mes].bodega = 0
	FOR i_line = 1 TO 10
            LET ma_tota[i_nubo, i_line] = 0
            LET ma_clie[i_nubo, i_line] = 0
            LET ma_nubo[i_nubo].mes[i_mes].linea[i_line] = 0
            LET ma_mes[i_mes, i_nubo, i_line].nubo = NULL
            LET ma_mes[i_mes, i_nubo, i_line].peso = 0
            LET ma_mes[i_mes, i_nubo, i_line].porc = 0
	END FOR
    END FOR
END FOR
END MAIN
