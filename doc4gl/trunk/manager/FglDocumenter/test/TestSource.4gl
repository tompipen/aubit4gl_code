{**
 * This is a 4gl to test a 4gl import.

    It is not intended to test general 4gl parsing - only commnet parsing.

   Also see 4gl code in parser/test, that tests Doc4GL parsing
 *}


{**
 * Function comment
 *
 * @todo Testing the todo tag
 * @param a ParameterA
 * @param b ParameterA
 * @return Return a value
 *}
function OneFunctionToTest(a,b)
  define a smallint
	define b char(20)

  return 1
end function

