{**
 * @file
 * pg8 : report ordered : variable corruption
 * @process TEST_GENERAL
 *}
 
DATABASE test1

MAIN

DEFINE w RECORD
          agen INTEGER ,
          zove INTEGER ,
          pobl CHAR (30),
          nucl INTEGER ,
          coes INTEGER ,
          muni INTEGER ,
          pueb INTEGER ,
          unid INTEGER ,
          kilo INTEGER ,
          impo DECIMAL (32,16),
          comi DECIMAL (32,16)
       END RECORD,
	w_nuca INT,
	w_coes INT,
	w_colo CHAR(50),
	w_prod INT,
	w_bode INT,
	w_tice INT

START REPORT estrpobl_zona TO "est.out"
create temp table bug3 (
          agen INTEGER ,
          zove INTEGER ,
          pobl CHAR (30),
          nucl INTEGER ,
          coes INTEGER ,
          muni INTEGER ,
          pueb INTEGER ,
          unid INTEGER ,
          kilo INTEGER ,
          impo DECIMAL (32,16),
          comi DECIMAL (32,16),
          nuca INT,
          prod INT,
          tice SMALLINT,
          coes2 INT,
          colo char(50)
           )
load from "t1697.unl" insert into bug3
DECLARE c_unid CURSOR FOR 
     SELECT * from bug3
FOREACH c_unid INTO w.*, w_nuca, w_prod, w_tice, w_coes, w_colo
        display " impo = ", w.impo
        OUTPUT TO REPORT estrpobl_zona(w.*)
END FOREACH
FREE c_unid
FINISH REPORT estrpobl_zona
END MAIN

REPORT estrpobl_zona(r)
DEFINE r RECORD
          agen INTEGER ,
          zove INTEGER ,
          pobl CHAR (30),
          nucl INTEGER ,
          coes INTEGER ,
          muni INTEGER ,
          pueb INTEGER ,
          unid INTEGER ,
          kilo INTEGER ,
          impo DECIMAL (32,16),
          comi DECIMAL (32,16)
	END RECORD 

ORDER BY r.agen, r.zove, r.pobl, r.nucl

FORMAT
    ON EVERY ROW
        display "impo=", r.impo
END REPORT
