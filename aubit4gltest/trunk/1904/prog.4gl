{**
 * @file
 * Describe the test here
 * @process TEST_GENERAL
 *}
 
#if you need to use a database, use "test1"
#database test1
MAIN


DEFINE buffer CHAR(1024),
       ch_obj base.Channel
LET ch_obj = base.Channel.Create()
CALL ch_obj.openfile("test", "r")
WHILE ch_obj.read(buffer)
DISPLAY "Test"
END WHILE


#CALL aclfgl_dump_screen("out")

END MAIN
