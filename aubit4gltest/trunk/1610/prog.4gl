{**
 * @file
 * Selecting varchar return the string pdaded with spaces up to the 
 * maximun length, mantis bug 915
 * @process TEST_GENERAL
 *}
 
#if you need to use database, use "test1"
database test1
main

define w_f1 varchar(60)
create temp table tempvar(f1 varchar(60))
insert into tempvar values ("this with no spaces")
insert into tempvar values ("this with 1 space ")
insert into tempvar values ("this with 2 spaces ")
declare c_v cursor for select * from tempvar
foreach c_v into w_f1
    display ">", w_f1, " <"
end foreach
end main
