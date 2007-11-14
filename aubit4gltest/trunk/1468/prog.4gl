
main

define  i       integer

        let i =0

        display "Assigning 0 to i"
        if not i then
            display "i=0"
        else
            display "i!=0"
        end if

        display "Assigning 1 to i"
        let i= 1
        if not i then
            display "i=0"
        else
            display "i!=0"
        end if

        display "Assigning 123456 to i"
        let i= 123456
        if not i then
            display "i=0"
        else
            display "i!=0"
        end if

end main
