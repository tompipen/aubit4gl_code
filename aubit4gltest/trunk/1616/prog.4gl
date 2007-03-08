{**
 * @file
 * MID 927
 *
 * Segmentation violation, construct numeric field with alpha input
 * and exiting with 'exit construct'
 * @process TEST_GENERAL
 *}
 
main
DEFINE w_prep CHAR(70)
OPTIONS ACCEPT KEY CONTROL-M
OPEN WINDOW v_cons AT 1,1 WITH FORM "cons"
CONSTRUCT BY NAME w_prep ON f1
    ON KEY(ESC) EXIT CONSTRUCT
END CONSTRUCT
CLOSE WINDOW v_cons
EXIT PROGRAM 0
end main
