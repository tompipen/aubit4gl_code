{**
 * @file
 * Test if the pushdec function works ok
 *}

FUNCTION fgl_push_decimal(decimal_value)
	DEFINE decimal_value DECIMAL(16,11)

  RETURN decimal_value
END FUNCTION
