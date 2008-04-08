database test1

main
        define lvar1,lvar2 dec(8,2)
        #define n smallint

        let lvar1=99
        let lvar2=0.01

        create temp table t1 (a char(1),b dec(8,2))
        #insert into t1 values('a',3)
        insert into t1 values('a',lvar1-lvar2)
        #select count(*) into n from t1
        #display n
end main
