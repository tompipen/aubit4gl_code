{**
 * @file
 * WRong EC code initialize in a FOR index
 * @process TEST_GENERAL
 *}
 
DEFINE ma_impo ARRAY[10] OF INT
main
define x INT
FOR x = 1 TO 10
    INITIALIZE ma_impo[x] TO NULL
END FOR
end main
