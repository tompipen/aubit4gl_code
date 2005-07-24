{
	@(#)$Id: fglbld.sql,v 1.1.1.1 2002-06-15 05:07:13 afalout Exp $
	@(#)Schema for FGLBLD database
}

CREATE TABLE cpopup            
(
    tabname            CHAR(18),
    pkcol              CHAR(18),
    menuname           CHAR(18),
    basename           CHAR(7),
    selected           CHAR(18)
);

CREATE TABLE fetch_it          
(
    tabname            CHAR(18),
    pkcol              CHAR(18),
    basename           CHAR(7)
);

CREATE TABLE spi               
(
    tabname            CHAR(18),
    pkcol              CHAR(18),
    menuname           CHAR(18),
    basename           CHAR(7),
    opt_ins            CHAR(1),
    afterfield         CHAR(1),
    beforefield        CHAR(1),
    controlb           CHAR(1),
    controlp           CHAR(1),
    opt_del            CHAR(1),
    opt_upd            CHAR(1),
    opt_rep            CHAR(1),
    opt_sh             CHAR(1)
);

CREATE TABLE upopup            
(
    tabname            CHAR(18),
    pkcol              CHAR(18),
    basename           CHAR(7),
    selected           CHAR(18)
);

CREATE TABLE master_detail     
(
    master             CHAR(18),
    pkcol              CHAR(18),
    menuname           CHAR(18),
    basename           CHAR(7),
    opt_ins            CHAR(1),
    afterfield         CHAR(1),
    beforefield        CHAR(1),
    controlb           CHAR(1),
    controlp           CHAR(1),
    opt_del            CHAR(1),
    opt_upd            CHAR(1),
    opt_rep            CHAR(1),
    opt_sh             CHAR(1),
    detail             CHAR(18)
);

CREATE TABLE md_join           
(
    master             CHAR(18),
    detail             CHAR(18)
);
