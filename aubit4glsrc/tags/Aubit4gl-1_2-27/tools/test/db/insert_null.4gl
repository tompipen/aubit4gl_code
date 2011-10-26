database test

{*
 * This is a test for a BUG founded by Mike Aubury in 29/1/2003
 *
 * col_1=HELLO
 * col_2=
 * col_38????@?j#@??
 * 
 * 
 * Now - this could be in libaubit or esqlc.ec  ?
 *}

main
define lv_record
        record
                col_1 char(20),
                col_2 char(20),
                col_3 char(20)
        end record

        whenever error continue

        drop table test_xxx

        whenever error stop
        create table test_xxx (
                col_1 char(20),
                col_2 char(20),
                col_3 char(20)
        )

        insert into test_xxx values ("HELLO",NULL,"WORLD")

        select * into lv_record.* from test_xxx

        display "col_1=",lv_record.col_1
        display "col_2=",lv_record.col_2
        display "col_3=",lv_record.col_3
end main




