{**
 *
 * x4gl API framework to build unit tests.
 *
 * The functions are based in the JUnit implementation without object
 * orientation.
 *
 * The bigest problem in 4gl is that there are no features to execute
 * dynamicaly functions.
 *
 * Thus, this is realy an API or function library not a real framework.
 *
 * This module should be linked to the specificaly build test module.
 *
 * @todo : Interface com forms que mostre o resultado e permita execução
 *         de testes especificos.
 *
 * @Author: Sérgio Ferreira
 *
 }

# =====================================================================
#                   Module - level variables definitions
# =====================================================================

{**
 * Array of test suites
 *}
define paSuites array[50] of record
  suiteDescription char(60)
end record
define idxSuite smallint
define maxSuites smallint  ## Maximum number of suites in variable store

{**
 * Array of test cases
 *}
define paTestCases array[50] of record
  testCaseDescription char(60)
end record
define idxTestCase smallint
define maxtestCases smallint  ## Maximum number of suites in variable store

{**
 * Array of executed tests
 *}
define paTests array[1000] of record
	suiteDescription char(60),    ## Suite where the test belongs to
  testName         char(60),
	result           smallint,
	testComment      char(256)
end record
define idxTest smallint
define maxTests smallint  ## Maximum number of tests in variable store

## Time when the tests was started
define startTests datetime minute to fraction(3)

## Time when tests ended
define endTests datetime minute to fraction(3)

## The duration of the tests
define testDuration interval minute to fraction(3)

## The number of tests that have failed
define failures smallint

## The current suite
define currentSuite integer

## The current test case
define currentTestCase integer

## The current test
define currentTest integer

{**
 * 4gl unit execution options.
 *}
define options record
  printResult smallint,   ## The test result should be showed
	resultLocation char(1), ## Where the results are stored (Table or Variables)
	showResultIn char(1)    ## How to show a test result (Text or Form)
end record

# =====================================================================
#                           Functions definitions
# =====================================================================

  { --------------------------- TEST CONTROL ---------------------- }

{** 
 * Unit test initializations.
 *
 * This function should be allways called by the specific tests.
 *}
function fglUnitConstruct()
	let idxSuite 		= 0
	let idxTest 		= 0
	let currentTestCase = 0
	let currentSuite 	= 0
	let currentTest 	= 0
	let maxSuites 		= 50
	let maxTests 		= 1000
	let maxTestCases 	= 50

	let options.printResult 	= true
	let options.resultLocation 	= "V"
	let options.showResultIn 	= "T"
end function

{**
 * Initialization of the fgl unit API after the construction and configuration.
 *}
function fglUnitInit()
	let startTests = current
	if options.resultLocation = "D" then 
		call fglUnitCreateTempTable()
	end if
	if options.showResultIn = "T" then
		start report testResultReport
	end if
end function

{**
 * Unit test destruction function.
 *}
function fglUnitDestroy()
	let idxSuite = 0
	let idxTest = 0
	let currentTestCase = 0
	let currentSuite = 0
	let currentTest = 0
	if options.resultLocation = "D" then
		call fglUnitDropTempTable()
	end if
end function

{**
 * Set the possible result location of the test
 *
 * @param _resultLocation The place where the test results it will be stored:
 *   - T : In a temporary database table.
 *   - V : In modular variables.
 *}
function fglUnitSetResultLocation(_resultLocation)
  define _resultLocation char(1)

	if _resultLocation != "T" or _resultLocation != "V" then
		display "Assignment of invalid result location (T-Tables,V-Variables) : ",
		  _resultLocation
		exit program
	end if
	let options.resultLocation = _resultLocation
end function

{**
 * Set the possible way to show the results
 *
 * @param _showResultIn The mode how to show the test result.
 *   - T : In text mode
 *   - F : In form mode
 *}
function fglUnitSetShowResultIn(_showResultIn)
  define _showResultIn char(1)

	if _showResultIn != "T" or _showResultIn != "F" then
		display "Assignment of invalid type of result display (T-Text,F-Form) : ",
		  _showResultIn
		exit program
	end if
	let options.showResultIn = _showResultIn
end function

{**
 * Insert a new test in the result structure.
 *
 * @param testName Name of the test to be executed.
 *}
function fglUnitSetCurrentTest(testName)
  define testName char(30)

	if idxTest >= 100 then
		error "Can't execute more then 100 tests"
		return
	end if
	let idxTest = idxTest + 1
	let paTests[idxTest].testName = testName
end function

{**
 * Start a new tset suite.
 *
 * @param suiteName The name of the suite
 *}
function fglUnitStartSuite(suiteName)
  define suiteName char(50)

	if options.resultLocation = "T" then
	  call fglUnitInsertSuite(suiteName)
	else
	  call fglUnitAddSuite(suiteName)
	end if
end function

{**
 * Start a new test case.
 * Called explicitly in the begining of each test.
 *
 * @param testCaseName A text description of the test case
 *}
function fglUnitStartTestCase(testCaseName)
  define testCaseName char(50)

	if options.resultLocation = "T" then
	  call fglUnitInsertTestCase(testCaseName)
	else
	  call fglUnitAddTestCase(testCaseName)
	end if
end function

{**
 * Start a new test of the current suite and test case.
 *
 * @param testName The name of the test
 *}
function fglUnitStartTest(testName)
  define testName char(50)

	if options.resultLocation = "T" then
	  call fglUnitInsertTest(testName)
	else
	  call fglUnitAddTest(testName)
	end if
end function

{**
 * Create the temporary tables used to store the tests.
 * For database located results only.
 *
 * This is Informix dependent due to the use of serial(s).
 *}
function fglUnitCreateTempTable()
  create temp table fglUnitSuite (
		suite_id serial not null,
		description char(60) not null,
		parent_suite integer            ## references fglUnitSuite (suite_id)
	)
	create temp table fglUnitTestCase (
		test_case_id serial not null,
		description char(60) not null,
		suite_id integer not null       ## references fglUnitSuite (suite_id)
	)
	create temp table fglUnitTest (
		test_id serial not null,
		testName char(60) not null,
		result smallint,
		testComment char(60),
		test_case_id integer not null   ## references fglUnitTestCase (test_case_id)
	)
end function

{**
 * Drop the temporary tables created to store the test results
 *}
function fglUnitDropTempTable()
	drop table fglUnitSuite
	drop table fglUnitTestCase
	drop table fglUnitTest
end function

{**
 * Mark the time when the tests was started.
 *}
function fglUnitMarkTestStart()
  let startTests = current
end function

{**
 * Mark the time when the tests was ended.
 *}
function fglUnitMarkTestEnd()
  let endTests = current
end function

{** 
 * Calculate the tests duration
 *}
function fglUnitComputeTestsTime()
	let endTests = current
  let testDuration = endTests - startTests
end function

{**
 * Calculate the number of test failures.
 *}
function fglUnitComputeFailures()
  if options.resultLocation = "V" then
	  call fglUnitComputeFailuresInVariables()
	else
	  select count(*) into failures from fglUnitTest where result = false
	end if
end function

{**
 * Compute the failures when the test result is stored in variables
 *}
function fglUnitComputeFailuresInVariables()
  define i smallint

	let failures = 0
	for i = 1 to idxTest
	  if paTests[i].result = false then
		  let failures = failures + 1
		end if
	end for
end function

{ ---------------------------- ASSERTIONS -------------------------------}

{**
 * Store the assertion of the current test.
 *
 * @param result The test result
 * @return The result asserted
 *}
function fglUnitAssert(result,message)
  define result smallint
	define message char(60)

	call fglUnitUpdateTestResult(result,message)
	if ( options.printResult )
	then
	  call fglUnitShowAssertionResult(result)
	end if
	return result
end function

{**
 * Assert doing the comparison with two 256 char(s).
 * 
 * @param str1 The first string to be tested.
 * @param str2 The second string to be tested.
 * @param message The message to be showed if not asserted.
 * @return The result asserted
 *}
function fglUnitAssertEqualsChar(str1,str2,message)
  define str1 char(256)
	define str2 char(256)
	define message char(60)

	return fglUnitAssert(str1=str2,message)
end function

{**
 * Assert doing the comparison with two ints.
 * 
 * @param firstInt The first integer to be tested.
 * @param secondInt The second integer to be tested.
 * @param message The message to be showed if not asserted.
 * @return The result asserted
 *}
function fglUnitAssertEqualsInt(firstInt,secondInt,message)
  define firstInt integer
	define secondInt integer
	define message char(60)

	return fglUnitAssert(firstInt=secondInt,message)
end function

{**
 * Assert doing the comparison with two decimals.
 * 
 * @param firstDec The first decimal to be tested.
 * @param secondDec The second decimal to be tested.
 * @param message The message to be showed if not asserted.
 * @return The result asserted
 *}
function fglUnitAssertEqualsDec(firstDecimal,secondDecimal,message)
  define firstDecimal decimal(16,3)
	define secondDecimal decimal(16,3)
	define message char(60)

	return fglUnitAssert(firstDecimal=secondDecimal,message)
end function

{**
 * Assert doing the comparison with two dates.
 * 
 * @param firstDate The first date to be tested.
 * @param secondDate The second date to be tested.
 * @param message The message to be showed if not asserted.
 * @return The result asserted
 *}
function fglUnitAssertEqualsDate(firstDate,secondDate,message)
  define firstDate date
	define secondDate date
	define message char(60)

	return fglUnitAssert(firstDate=secondDate,message)
end function

{**
 * Assert doing the comparison with null for strings
 * 
 * @param strValue The value to be tested 
 * @param message The message to be showed if not asserted.
 * @return The result asserted
 *}
function fglUnitAssertNull(strValue,message)
define strValue char(256)
define message char(60)
define dummy smallint


	if strValue is null then
	  call fglUnitAssert(true,message) returning dummy
		return true
	else
	  call fglUnitAssert(false,message) returning dummy
		return false
  end if
end function

{**
 * Make an assertion based on an expected row count to be expected in a table
 *
 * @param rowCount The number of rows to be found in the table
 * @param tableName The name of the table to be inspected
 * @return The result asserted
 *}
function fglUnitAssertCountTable(rowCount,tableName,message)
define rowCount integer
define tableName char(19)
define message char(80)
define strSql char(128)
define tblCount integer
define dummy smallint

	let strSql = "select count(*) from ", tableName clipped
	prepare statCount from strSql
	declare crCount cursor for statCount
	open crCount
	fetch crCount into tblCount
	call fglUnitAssert(tblCount = rowCount,message) returning dummy
	close crCount
	return tblCount = rowCount
end function

{**
 * Fail the current test
 *
 * @param message The text message to be displayed
 *}
function fglUnitFail(message)
define message char(80)
define dummy smallint

	call fglUnitAssert(false,message) returning dummy
end function

{**
 * Insert a new test suite in the suite table.
 * For database located results only.
 *}
function fglUnitInsertSuite(suiteDescription)
  define suiteDescription char(60)

  insert into fglUnitSuite (suite_id,description) values (0,suiteDescription)
	let currentSuite = sqlca.sqlerrd[2]
end function

{**
 * Insert a new test case in the test case table.
 * For database located results only.
 *}
function fglUnitInsertTestCase(testCaseDescription)
  define testCaseDescription char(60)

  insert into fglUnitTestCase (test_case_id,description,suite_id)
	  values(0,testCaseDescription,currentSuite)
	let currentTestCase = sqlca.sqlerrd[2]
end function

{**
 * Insert a new test case in the test case array.
 * For variable located results only.
 *}
function fglUnitAddTestCase(testCaseDescription)
  define testCaseDescription char(60)
  let idxTestCase = idxTestCase + 1

  if idxTestCase > maxTestCases then
	  display "Reached the maximum of test cases ", maxSuites
		exit program
	end if

	let paTestCases[idxTestCase].testCaseDescription = testCaseDescription
end function
{**
 * Insert a new test suite in the test table.
 * For database located results only.
 *}
function fglUnitInsertTest(testDescription)
  define testDescription char(60)

	if currentTestCase <= 0 then
	  display "No current test case"
		exit program
	end if

  insert into fglUnitTest (test_id,description,test_case_id)
	  values (0,testDescription,currentTestCase)
  let currentTest = sqlca.sqlerrd[2]
end function


{** 
 * Insert a new test suite.
 * For variable located results only
 *
 * @param suiteDescription Text suite description
 *}
function fglUnitAddSuite(suiteDescription)
	define suiteDescription char(60)
  let idxSuite = idxSuite + 1

  if idxSuite > maxSuites then
	  display "Reached the maximum of suites ", maxSuites
		exit program
	end if

	let paSuites[idxSuite].suiteDescription = suiteDescription
end function

{**
 * Add a new test of the current suite
 * For variable located results only
 *}
function fglUnitAddTest(testDescription)
  define testDescription char(60)
	let idxTest = idxTest + 1

  if idxTest > maxTests then
	  display "Reached the maximum of tests ", maxTests
		exit program
	end if

	let paTests[idxTest].suiteDescription = paSuites[idxSuite].suiteDescription
	let paTests[idxTest].testName = testDescription
	# ... @todo
end function 

{**
 * Update the test result of the current test
 *}
function fglUnitUpdateTestResult(result,comment)
  define result smallint
	define comment char(60)

  if options.resultLocation = "V" then 
	  let paTests[idxTest].result = result
		let paTests[idxTest].testComment = comment
	else
	  update fglUnitTest 
		  set fglUnitTest.result = result, fglUnitTest.testComment = comment
			where test_id = currentTest
	end if
end function

      { ---------------- TEST RESULT DISPLAY FUNCTIONS ------------------ }

{**
 * Show the result of the assertion made.
 *
 * @param result The result of the assertion.
 *}
function fglUnitShowAssertionResult(result)
	define result smallint

  if options.showResultIn = "T" then
    call fglUnitShowTextAssertionResult(result)
	else
		# @todo : Implement this function
	  #call fglUnitShowFormAssertionResult(result)
	end if
end function

{**
 * Show the result of an assertion.
 *
 * This function display in text mode.
 *
 * @param result
 *}
function fglUnitShowTextAssertionResult(result)
	define result smallint

  if result then
	  output to report testResultReport("ASSERT",".")
	else
	  output to report testResultReport("ASSERT","F")
  end if
end function

{**
 * Print a summary of the result of the tests.
 *}
function fglUnitPrintResult()
	output to report testResultReport("","")
	call fglUnitComputeTestsTime()
	call fglUnitComputeFailures()
	call fglUnitPrintFailures()
	call fglUnitPrintResultSummary()
end function

{**
 * Show the summary results of the test executed.
 *}
function fglUnitPrintResultSummary()
	if options.showResultIn = "T" then
	    call fglUnitPrintTextResultSummary()
	else
		# @todo : Implement it
    	#call fglUnitPrintTextResultSummary()
	end if
end function

{**
 * The text version that show the results of tests in text mode.
 *}
function fglUnitPrintTextResultSummary()
	output to report testResultReport("Time","")
	if failures = 0 then
	  output to report testResultReport("OK","")
		return
  end if

	output to report testResultReport("","FAILURES!!!")
	output to report testResultReport("SUMMARY","")
	finish report testResultReport
end function

{**
 * The report to show the tests result.
 * Implemented as report because display allways put a new line at the end
 * in text mode.
 *}
report testResultReport(messageType,mesg)
  define messageType char(10)
	define mesg char(128)

	output 
	  page length 66
		top margin 0
		bottom margin 0
		left margin 0
	
	format 
	  on every row
	  case messageType 
		  when "ASSERT"
			  print mesg clipped;
			when "Time"
        print "Time ", testDuration
		  when "OK"
	      print "OK (", idxTest, " tests)"
	    when "FAILURES"
				skip 1 line
	      print "There was ", failures using "<<<<" , " failure"
	    when "SUMMARY"
	      print "Test - run: ", idxTest using "<<<<", "  Failures:", 
	        failures using "<<<<"
			otherwise 
			  print mesg clipped
		end case
	#on last row
	  
end report

{**
 * Print the failures detail of the test executed.
 *}
function fglUnitPrintFailures()
	if failures < 1 then
	  return
  end if

	if options.showResultIn = "F" then
	  output to report testResultReport("FAILURES","")
	else
	  # @todo Implement this feature
	end if


  if options.resultLocation = "V" then
	  call fglUnitPrintVariableFailures()
	else
	  call fglUnitPrintDBFailures()
	end if
end function

{** 
 * Print the detail of the failures stored in variables
 *}
function fglUnitPrintVariableFailures()
  define i smallint

	for i =  1 to idxTest
	  if paTests[i].result = false then
		  call fglUnitPrintFailure(i,paTests[i].testName,paTests[i].testComment)
		end if
	end for
end function 

{**
 * Print the detail of the failures stored in temporary tables
 *}
function fglUnitPrintDBFailures()
  define testName char(60)
	define testComment char(60)
	define i smallint

	let i = 0
  declare crFailures cursor for 
	  select fglUnitTest.testName, fglUnitTest.testComment
		from fglUnitTest where result = false
  foreach crFailures into testName, testComment
		let i = i + 1
	  call fglUnitPrintFailure(i,testName,testComment)
	end foreach
	close crFailures
end function

{**
 * Print the failure
 *
 * @param i The order of the failure
 * @param testName The name of the test
 * @param testComment The comment to the faile test
 *}
function fglUnitPrintFailure(i,testName,testComment)
  define i smallint
	define testName char(60)
	define testComment char(60)
	define msg char(80)

  if options.showResultIn = "T" then
	  let msg = i using "<<<<", ")", testName
	  output to report testResultReport("",msg)
		let msg = "    ", testComment
	  output to report testResultReport("",msg)
	else
	  # @todo Implement the form test detail show
	end if
end function

{**
 * Sets the flag that tells us if the test result should be or not showed 
 * online.
 *
 * @param _printResult The value to be set to the flag
 *}
function fglUnitSetPrintResult(_printResult)
  define _printResult smallint

	let options.printResult = _printResult
end function


# =============================== EOF =====================================
