database test1
main
define a integer

define lv_acc_to, lv_acc_from integer
define l_bal1 float
create temp table accounts(acctno integer, balance float)
insert into accounts values(1,1000)
insert into accounts values(2,1000)

let lv_acc_to=1
let lv_acc_from=2


let a=100

        todo  # or  something like :    todo while a<1

                when true
                        update accounts set balance=balance+a where acctno=lv_acc_to
                        if sqlca.sqlcode=0 then
                                DONE
                        end if

                when true
                        update accounts set balance=balance-a where acctno=lv_acc_from
                        if sqlca.sqlcode=0 then
                                DONE
                        end if
        end todo

select balance into l_bal1 from accounts where acctno=lv_acc_to
display "TO:", l_bal1
select balance into l_bal1 from accounts where acctno=lv_acc_from
display "FROM:", l_bal1

end main



