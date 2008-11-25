{**
 * @file
 * pg8 : Segmentation violation, open cursor after a select
 *   with not matches 
 * @process TEST_GENERAL
 *}
 
DATABASE test1

MAIN
DEFINE t_fpol int,
       a_inpc MONEY,
      m_ncta INT

LET m_ncta = 1023
create temp table a_conhsald (saldncta int, saldimpc money)
SELECT saldimpc INTO a_inpc
            FROM a_conhsald
           WHERE (saldncta = m_ncta) 
create temp table a_conmpoli (polcfpol int,
                              polcncta int,
                              polcrefe char(20))
insert into a_conmpoli values (1,1023,"NADA")
DECLARE c_cpol CURSOR FOR
    SELECT polcfpol
              FROM a_conmpoli
             WHERE polcncta = m_ncta  and
                        (polcrefe is null or polcrefe not matches "ASIENTO*")
FOREACH c_cpol INTO t_fpol
   display t_fpol
END FOREACH
END MAIN
