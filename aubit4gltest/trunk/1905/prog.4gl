{**
 * @file
 * Describe the test here
 * @process TEST_GENERAL
 *}
 
#if you need to use a database, use "test1"

#database test1
MAIN
CALL channel::open_file("data", "out", "w")
CALL channel::write("data", "CONTENT"||test())

END MAIN

FUNCTION test()
RETURN "BLA"
END FUNCTION

