{**
 * @file
 * select with arithmetics syntax error at C compile
 * @process TEST_GENERAL
 *}
 
database test1
DEFINE mr_fact RECORD
           impa MONEY(12,2),
           imp2 MONEY(12,2),
           pode DECIMAL(4,2),
           decl MONEY(12,2)
       END RECORD,
       m_nufa CHAR(10)
main
define w_tipc, a_1, a_2 decimal(10,4)

create temp table abc(d1 decimal(10,4), d2 decimal(10,4))
insert into abc values (1012,2024)

let w_tipc = 10
select d1 / 10, d2 / w_tipc INTO a_1, a_2 from abc

if a_1 <> 101.2 then display "bad1 ", a_1 exit program 1 end if
if a_2 <> 202.4 then display "bad2 ", a_2 exit program 2 end if

# Another test (compile only)

create temp table clfactur (
           factnufa CHAR(10), 
           factimpa MONEY(12,2),
           factimp2 MONEY(12,2),
           factpode DECIMAL(4,2),
           factdecl MONEY(12,2)
           )
SELECT factimpa / w_tipc, factimp2 / w_tipc, factpode,
       factdecl / w_tipc
  INTO mr_fact.*
  FROM clfactur
 WHERE factnufa = m_nufa
end main
