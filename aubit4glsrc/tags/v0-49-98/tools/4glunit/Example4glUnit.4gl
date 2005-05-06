{**
 * Example of 4gl unit usage
 *}

{**
 * Test example entry point
 *}
main
  call testExample()
end main

{**
 * This is a test example
 *}
function testExample()
	call fglUnitConstruct()
	call fglUnitInit()
	call fglUnitStartSuite("Example suite")
	call fglUnitStartTestCase("Example test case")
	call executeTests()
	call fglUnitPrintResult()
	call fglUnitDestroy()
end function

{**
 *  The first test to be executed
 *}
function testOne()
	call fglUnitStartTest("TEST ONE")
	call testOneSetup()
	if not fglUnitAssert(false,"First test allways returns false") then
	  return
	end if
	call testOneTearDown()
end function

function testOneSetup()
end function

function testOneTearDown()
end function

{**
 * The second test to be executed
 *}
function testTwo()
	call testTwoSetup()
	call fglUnitStartTest("TEST TWO")
	if not fglUnitAssert(true,"Second test allways returns true") then
	  return
	end if
	call testTwoTearDown()
end function

function testTwoSetup()
end function

function testTwoTearDown()
end function

{**
 * Real execution of the tests
 *}
function executeTests()
	call testOne()
	call testTwo()
end function

