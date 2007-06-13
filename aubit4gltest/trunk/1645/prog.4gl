{**
 * @file
 * Use of large integer literals
 * Accept int8 as with 4GL 7.32
 * *****************************************
 * IBM Informix 4GL Reference Manual Version 7.32 March 2003 
 ******************************************
 * page 3-9
 *
 * SMALLINT
 * Integers, ranging from -32,767 to +32,767
 * 
 * INTEGER, INT
 * Integers, ranging from -2,147,483,647 to +2,147,483,647
 * (that is, -(2^31 -1) to (2^31 -1))
 * 
 * BIGINT
 * Integer, ranging from -9,223,372,036,854,775,807
 * to 9,223,372,036,854,775,807 (that is, -(2^63 -1) to (2^63 -1))
 **********************
 * page 3-10
 *
 * 4GL also supports additional IBM Informix Dynamic Server data types:
 * INT8 Stores 8-byte integer values in range -(2^63 -1) to 2^63 -1
 * SERIAL Stores large sequential integers in same range as INT
 * SERIAL8 Stores large sequential integers in same range as INT8
 ************************
 * pag 3-14
 *
 * BIGINT
 * The BIGINT data type stores whole numbers in a range from
 * -9,223,372,036,854,775,807 to 9,223,372,036,854,775,807. (The negative
 * number -9,223,372,036,854,775,808 is a reserved value that cannot be used.)
 * BIGINT can store whole numbers, counts, and quantities that normally
 * exceed the limits of INTEGER values. BIGINT can store INT8 and SERIAL8
 * values of an IBM Informix Dynamic Server 9.x database. For more information
 * about the INT8 and SERIAL8 data types, see page 3-10. BIGINT can
 * pass values to C functions, where they can be converted into a 8-byte C
 * whole-number data type.
 *
 * @process TEST_GENERAL
 *}
 
main
define a int8,
       b int
let a = 12345678901234
display a
let b = 12345678901234
display b
end main
