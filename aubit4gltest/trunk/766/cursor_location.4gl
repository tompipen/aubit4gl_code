
{**
 * @file 
 * @test
 * Tests to exemplify the behaviour of cursor location with aubit and standard
 * 4gl.
 *}

MAIN
  DEFINE ans SMALLINT

  DISPLAY "Hello " AT 4, 5
	LET ans = fgl_getkey()
	DISPLAY "FGL KEY ", ans
END MAIN
