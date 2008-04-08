{**
 * @file
 * Compile only: with huge arrays takes an long time to compile and takes
 *               all the CPU power
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
{ 
The  following lines is the problem, with this lines the compile 
goes eternal.

But if you comment this lines you get a compilation error in the EC code

est.ec: In function `main':
est.ec:228: error: request for member `nubo' in something not a structure or uni
on
est.ec:234: error: request for member `peso' in something not a structure or uni
on
est.ec:240: error: request for member `porc' in something not a structure or uni
on

}
FOR i_mes = 1 TO 13
        FOR i_line = 1 TO 10
            FOR i_nubo = 1 TO 25
	        FOR a_nubo = i_nubo + 1 TO 26
	            IF ma_mes[i_mes, i_nubo, i_line].peso <
		       ma_mes[i_mes, a_nubo, i_line].peso THEN
		        LET ma_mes[i_mes, 31,i_line].* = ma_mes[i_mes, a_nubo,i_line].*
		        LET ma_mes[i_mes, a_nubo,i_line].* = ma_mes[i_mes, i_nubo,i_line].*
		        LET ma_mes[i_mes, i_nubo,i_line].* = ma_mes[i_mes, 31,i_line].*
	            END IF
	        END FOR
            END FOR
        END FOR
END FOR
END MAIN
