{**
 * @file
 * Test if the pushint function works ok
 *}

DATABASE test1

FUNCTION fgl_push_int(int_value)
	DEFINE int_value INTEGER

  RETURN int_value

END FUNCTION
