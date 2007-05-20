{**
 * @file
 *
 * -esqli
 *   Select byte field  after selecting 'null' byte value -> Illegal ESQL locator, 
 *   or uninitialized blob variable in 4GL..
 *
 * -eci
 *   Error:Could not find function in shared library (ESQLAPI_A4GL_init_out_byte)- STOP
 * @process TEST_GENERAL
 *}
 
DATABASE test1

MAIN
DEFINE lv_id INTEGER
DEFINE lv_photo BYTE
DEFINE lv_file CHAR(20)
LET lv_file = "fom.jpg"
LOCATE lv_photo IN FILE lv_file

CREATE TEMP TABLE tmpphotos(id INT, photo BYTE)
INSERT INTO tmpphotos VALUES (1, NULL)
INSERT INTO tmpphotos VALUES (2, lv_photo)
FOR lv_id = 1 TO 2
    SELECT photo INTO lv_photo FROM tmpphotos WHERE id = lv_id
END FOR
END MAIN
