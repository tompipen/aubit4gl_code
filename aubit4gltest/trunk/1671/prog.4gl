{**
 * @file
 * Locate TEXT in record structure doesn't compile
 * @process TEST_GENERAL
 *}
 
database test1
main

define a_x text,
       m record
            x text 
       end record

locate a_x in memory
locate m.x in memory

end main
