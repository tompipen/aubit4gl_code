
#ifndef GENFGLTEST_H
#define GENFGLTEST_H

//#include <cppunit/extensions/HelperMacros.h>

#include <cppunit/extensions/HelperMacros.h>
#include "FglParse.h"

class GenFglTest : public CppUnit::TestFixture
{
public:
  static CppUnit::Test *suite()
  {
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite(
      "GenFglTest" 
    );

    suiteOfTests->addTest( new CppUnit::TestCaller<GenFglTest>(
      "fgl_with_errors_syntax_wrong_define",
      &GenFglTest::fgl_with_errors_syntax_wrong_define ) 
		);
    return suiteOfTests;
	}

  void fgl_with_errors_syntax_wrong_define ();

  void setUp();
  void tearDown();
};

#endif
