{**
 * @file
 * SQL block, fails with -eci and -pg8, ok with -esqli
 * @process TEST_GENERAL
 *}
 
database test1
main

define p_prod, w_tipf, p_nubo, p_nuca int,
       p_fech, a_fini, a_ffin date

create temp table clconfac (
     conftipf int,
     confprod int,
     confnubo int,
     confnuca int,
     conffini date,
     confffin date
     )

let p_prod = 111
let p_nubo = 0
let p_nuca = 39
let p_fech = today
let a_fini = p_fech - 30
let a_ffin = p_fech + 30
insert into clconfac values (3, p_prod, p_nubo, p_nuca, a_fini, a_ffin)

let w_tipf = 9
SQL 
SELECT FIRST 1 conftipf INTO $w_tipf FROM clconfac
        WHERE confprod = $p_prod AND confnubo = $p_nubo AND
              confnuca = $p_nuca AND $p_fech BETWEEN conffini AND confffin
END SQL
if w_tipf = 3 then display "ok" exit program 0 end if
display "bad ", w_tipf, " status=", status
exit program 1
end main
