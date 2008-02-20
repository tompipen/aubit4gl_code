main
        define i smallint

        let i = NULL

        display "i = NULL"
        IF i THEN
                display "IF i -> TRUE"
        ELSE
                display "IF i -> FALSE"
        END IF
        IF NOT i THEN
                display "IF NOT i -> TRUE"
        ELSE
                display "IF NOT i -> FALSE"
        END IF
end main
