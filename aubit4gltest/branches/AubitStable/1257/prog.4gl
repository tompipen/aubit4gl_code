database test1
main

        unload to "hld.out" select 1 from systables where tabid=0

       prepare hghclm_stmt from "select * from systables"
       declare hghclm_curs cursor for hghclm_stmt

        open hghclm_curs
        fetch hghclm_curs
        display sqlca.sqlcode
end main
