/**
 * @file
 * The main test file for the new 4gl parser of fgldocumenter.
 */

//#include <cppunit/CompilerOutputter.h>
//#include <cppunit/extensions/TestFactoryRegistry.h>
//#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/ui/text/TestRunner.h>
#include "SimpleFglTest.h"


int main( int argc, char **argv)
{
	int parse_4gl(const char *str);

  parse_4gl("fgl/simple/hello.4gl");
  parse_4gl("fgl/simple/reserved_hello.4gl");
  CppUnit::TextUi::TestRunner runner;
  //runner.addTest( ExampleTestCase::suite() );
  runner.addTest( SimpleFglTest::suite() );
  runner.run();
  return 0;
}

