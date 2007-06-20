{**
 * @file
 * construct, long input string should go to bottom line
 *
 * TUI=OK, Only fails with HL_TUI
 *   work fine if the 'before construct' is commented
 * @process TEST_GENERAL
 *}
MAIN
DEFINE w_prep CHAR(70)
OPEN WINDOW v_1 AT 1,1 WITH FORM "cons" # ATTRIBUTE(DIM, FORM LINE 3)
CONSTRUCT BY NAME w_prep ON f1, f2
    # The following line is the problem
    BEFORE CONSTRUCT display "", "" TO f1, f2
    ON KEY(ESC) EXIT CONSTRUCT
END CONSTRUCT
CLOSE WINDOW v_1
if w_prep = "f1 between 123456789 and 987654321" then  exit program 0
else    display w_prep                               exit program 1
end  if
end main
