{**
 * @file
 * bigint precision with doubles
 * @process TEST_GENERAL
 *}
 
main
define w_bi1, w_bi2 bigint,
       w_db double precision

let w_bi1 = -9223372036854775807 

let w_bi2 =  9223372036854775807
let w_db = w_bi1 * w_bi2
display w_bi1, " * ", w_bi2, " = ", w_db
let w_db = w_bi2 * 10
display w_bi2, " * 10 = ", w_db
let w_db =  w_bi2 + 1
display w_bi2, " + 1 = ", w_db
let w_db =  w_bi2 + 10
display w_bi2, " + 10 = ", w_db
let w_db =  w_bi1 - 1
display w_bi1, " - 1 = ", w_db

display w_bi1, " - 10 = ", w_db
end main
