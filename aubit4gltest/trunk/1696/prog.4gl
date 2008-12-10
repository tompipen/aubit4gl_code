{**
 * @file
 * pg8 : report parameter corruption, select with many fields
 * @process TEST_GENERAL
 *}
 
DATABASE test1

MAIN
DEFINE w RECORD
           llav INT,
           zove INT,
           moba INT,
           nucl INT,
           line INT,
           unid INT,
           fech INT
        END RECORD

create temp table clclient (clienone char(30), clienopr char(30),
      cliedire char(30), cliecoes int, cliemuni int,
               cliepueb int, cliefulc date, cliefalt date, clieticl int,
               cliecolo char(30), clietice int, cliecred money,
               cliezove int, cliestat int, cliemoba int,
               clienucl int) # , cliesact
insert into clclient values ("a", "b", "c", 1,1,1,today, today, 1,"d",1,99.99,
                     1, 1, 1,  155018)
insert into clclient values ("a", "b", "c", 1,1,1,today, today, 1,"d",1,99.99,
                     1, 1, 1,  155095)
insert into clclient values ("a", "b", "c", 1,1,1,today, today, 1,"d",1,99.99,
                     1, 1, 1,  468670)
create temp table bug1 (llav INT, zove int, moba int, nucl int,
                   line int, unid int, fech int)
insert into bug1 values (100,1511,12,155018,4,1,200701)
insert into bug1 values (100,1511,0,155095,7,2,200705)
insert into bug1 values (100,1511,0,468670,7,4,200810)
DECLARE c_unid CURSOR FOR select * from bug1
START REPORT estrline_list TO "est.out"
FOREACH c_unid INTO w.*
    display "in llav=", w.llav, " nucl=", w.nucl
    OUTPUT TO REPORT estrline_list(w.*)
END FOREACH
FREE c_unid
FINISH REPORT estrline_list
END MAIN

REPORT estrline_list(r)
DEFINE r RECORD
           llav INT,
           zove INT,
           moba INT,
           nucl INT,
           line INT,
           unid INT,
           fech INT
        END RECORD,
        w_none CHAR(35),
        w_nopr CHAR(35),
        w_dire CHAR(30),
        w_coes INT,
        w_muni INT,
        w_pueb INT,
        w_cred MONEY,
        w_colo CHAR(30),
        w_fulc DATE,
        w_falt DATE,
        w_tice INT,
        w_ticl INT,
        w_zove INT,
        w_stat INT,
        w_moba INT,
        w_sact MONEY

OUTPUT
    TOP MARGIN 0
    BOTTOM MARGIN 0
    PAGE LENGTH 66
    LEFT MARGIN 0

ORDER BY r.llav, r.zove, r.nucl, r.line

FORMAT

    ON EVERY ROW
        display "out llav=", r.llav, " nucl=", r.nucl
        if r.llav <> 100  then
            display "error found"
            select noneexistent from noneexistant
        end if

    AFTER GROUP OF r.nucl
        display "after group nucl=", r.nucl, " llav=", r.llav
        SELECT clienone, clienopr, cliedire, cliecoes, cliemuni,
               cliepueb, cliefulc, cliefalt, clieticl, cliecolo ,
               clietice, cliecred, cliezove, cliestat, cliemoba # , cliesact
             INTO w_none, w_nopr, w_dire, w_coes, w_muni ,
                  w_pueb, w_fulc, w_falt, w_ticl, w_colo ,
                  w_tice, w_cred, w_zove, w_stat, w_moba # , w_sact
             FROM clclient
             WHERE clienucl = r.nucl

END REPORT
