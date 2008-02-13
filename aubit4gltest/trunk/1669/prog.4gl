{**
 * @file
 * RETURN in nested INPUT generate bad EC code
 * @process TEST_GENERAL
 *}
 
main
CALL inpf1()
end main

FUNCTION inpf1()
DEFINE w_cnom, w_conf CHAR(1)
OPEN WINDOW v_prem AT 5,5 WITH FORM "vprem" ATTRIBUTE(BORDER)
INPUT w_cnom WITHOUT DEFAULTS FROM cnom ATTRIBUTE(UNDERLINE,BOLD)
    ON KEY(ESC)
        EXIT INPUT
    AFTER INPUT
        IF NOT int_flag THEN
            INPUT BY NAME w_conf WITHOUT DEFAULTS ATTRIBUTE(UNDERLINE,BOLD)
                ON KEY(ESC)
                    EXIT INPUT
                AFTER INPUT
                    IF w_conf = "Y" THEN
                        RETURN
                    END IF
            END INPUT
        END IF
END INPUT
CLOSE WINDOW v_prem
END FUNCTION
