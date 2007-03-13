{**
 * @file
 * Compile error in EC, undefined function A4GL_int_out_byte().
 * @process TEST_GENERAL
 *}
 
database test1
main
DEFINE w_byte BYTE
LOCATE w_byte IN MEMORY
SELECT bytefield into w_byte from bytetable
end main
