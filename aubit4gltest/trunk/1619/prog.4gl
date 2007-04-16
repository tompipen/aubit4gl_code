{**
 * @file
 * MID 938
 *
 * construct range of integers is no longer working
 * @process TEST_GENERAL
 *}
 
main
DEFINE w_prep CHAR(70)
OPTIONS ACCEPT KEY CONTROL-M
OPEN WINDOW v_cons AT 1,1 WITH FORM "cons" ATTRIBUTE(DIM)
CONSTRUCT BY NAME w_prep ON f1
CLOSE WINDOW v_cons
if w_prep = "f1 between 1 and 3" then  exit program 0
else    display w_prep                               exit program 1
end  if
end main
