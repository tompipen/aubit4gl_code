{**
 * @file
 * Test if C can call a 4gl function.
 *}

FUNCTION called_function(int_value)
	DEFINE int_value INTEGER

  RETURN int_value / 2

END FUNCTION
