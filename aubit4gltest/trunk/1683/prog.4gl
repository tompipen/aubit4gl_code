{**
 * @file
 * outer table bad cnversion to pg8
 * A4GL_LEXTYPE=C
 * A4GL_TARGETDIALECT=POSTGRES8
 * A4GL_SQLTYPE=pg8
 * @process TEST_GENERAL
 *}
 
database test1
main
define w_id int, w_d int, w_c char(1)
create temp table tbl1 (id int, d int)
insert into tbl1 values (1, 1)
insert into tbl1 values (3, 2)
insert into tbl1 values (5, 3)
create temp table tbl2 (d2 int, c char(1))
insert into tbl2 values (1, "A")
insert into tbl2 values (2, "B")
declare c_cur cursor for
    select id, d, c from tbl1, outer tbl2
         where tbl1.d = tbl2.d2 and tbl2.d2 < 10
foreach c_cur into w_id, w_d, w_c
    display w_id, " ", w_d , " ", w_c
end foreach
end main
