{**
 * @file
 * wordwrap in a multiline screen field fills with SPACES after moving word
 * to the next line
 * @process TEST_GENERAL
 *}
 
MAIN
DEFINE a char(17)
OPEN WINDOW v1 AT 1,1 WITH FORM "word" ATTRIBUTE(DIM)
INPUT BY NAME a WITHOUT DEFAULTS ATTRIBUTE(UNDERLINE,BOLD)
CLOSE WINDOW v1
IF a <> "aaaaa bbbbb ccccc" THEN display a exit program 1 END IF
display a
END MAIN
