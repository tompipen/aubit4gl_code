{**
 * @file
 * MID 942
 *
 * Gabrbage if a VARCHAR variable is read beyond cuurent size
 * @process TEST_GENERAL
 *}
 
main
define w_v1 varchar(10), i smallint, w_a char(1)
let w_v1 = "aaaaaaaaaa"
let w_v1 = "xxx"
for i = 1 to 10
   let w_a = w_v1[i,i]
   display w_a
end for
end main
