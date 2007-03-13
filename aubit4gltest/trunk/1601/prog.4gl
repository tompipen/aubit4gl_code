{**
 * @file
 * MID 901. Format error using "((&)"
 * @process TEST_GENERAL
 *}
 
main
define a money
let a = -10234.56
display a using "(((,((&)", " ", a using "---,--&"
display a using "(((,((&.)", " ", a using "---,--&."
display a using "(((,((&.&)", " ", a using "---,--&.&"
end main
