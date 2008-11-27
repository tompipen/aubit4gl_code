{**
 * @file
 * Multiple declare cursor in trasaction fails
 * @process TEST_GENERAL
 *}
 
DATABASE test1
MAIN 
define w_chof int
create temp table clchofer (chofcami int, chofstat int, chofchof int)
begin work # without trasaction works ok
LET w_chof = getoper(1) 
LET w_chof = getoper(2) 
LET w_chof = getoper(2) 
commit work
END MAIN

FUNCTION getoper(p_cami)
DEFINE p_cami INT,
       w_chof INT
LET w_chof = NULL
DECLARE c_chof CURSOR FOR
    SELECT chofchof
	FROM clchofer 
       WHERE chofcami = p_cami AND chofstat <> 9
OPEN c_chof
FETCH c_chof INTO w_chof
FREE c_chof
RETURN w_chof
END FUNCTION
