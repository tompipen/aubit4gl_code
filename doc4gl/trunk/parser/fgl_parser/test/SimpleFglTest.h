#ifndef SIMPLEFGLTEST_H
#define SIMPLEFGLTEST_H

//#include <cppunit/extensions/HelperMacros.h>

#include <cppunit/extensions/HelperMacros.h>

class SimpleFglTest : public CppUnit::TestFixture
{
  //CPPUNIT_TEST_SUITE( SimpleFglTest );
  //CPPUNIT_TEST( testSimpleFgl );
  //CPPUNIT_TEST_EXCEPTION( testAddThrow, IncompatibleMoneyError );
  //CPPUNIT_TEST_SUITE_END();

public:
  static CppUnit::Test *suite()
  {
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite(
			"SimpleFglTest" 
		);
    suiteOfTests->addTest( new CppUnit::TestCaller<SimpleFglTest>(
                                   "testEmpty",
                                   &SimpleFglTest::testEmpty ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<SimpleFglTest>(
                                   "testHello",
                                   &SimpleFglTest::testHello ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<SimpleFglTest>(
                                   "testReservedHello",
                                   &SimpleFglTest::testReservedHello ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<SimpleFglTest>(
                                   "testOnlyModular",
                                   &SimpleFglTest::testOnlyModular ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<SimpleFglTest>(
                                   "testOnlyGlobalVar",
                                   &SimpleFglTest::testOnlyGlobalVar ) );

		// 16/1/2003
    suiteOfTests->addTest( new CppUnit::TestCaller<SimpleFglTest>(
                                   "testOnlyFunction",
                                   &SimpleFglTest::testOnlyFunction ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<SimpleFglTest>(
                                   "testOnlyMain",
                                   &SimpleFglTest::testOnlyMain ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<SimpleFglTest>(
                                   "testOnlyGlobalInclude",
                                   &SimpleFglTest::testOnlyGlobalInclude ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<SimpleFglTest>(
                                   "testModularGlobalFunction",
                                   &SimpleFglTest::testModularGlobalFunction ));
    suiteOfTests->addTest( new CppUnit::TestCaller<SimpleFglTest>(
                                   "testThreeGlobalInclude",
                                   &SimpleFglTest::testThreeGlobalInclude ) );
    suiteOfTests->addTest( new CppUnit::TestCaller<SimpleFglTest>(
                                  "testGlobalIncludeGlobalVar",
                                  &SimpleFglTest::testGlobalIncludeGlobalVar) );
    suiteOfTests->addTest( new CppUnit::TestCaller<SimpleFglTest>(
                                  "testOnlyDatabase",
                                  &SimpleFglTest::testOnlyDatabase) );
    suiteOfTests->addTest( new CppUnit::TestCaller<SimpleFglTest>(
                                  "testDatabaseModular",
                                  &SimpleFglTest::testDatabaseModular) );
    suiteOfTests->addTest( new CppUnit::TestCaller<SimpleFglTest>(
                                  "testDatabaseGlobals",
                                  &SimpleFglTest::testDatabaseGlobals) );
    suiteOfTests->addTest( new CppUnit::TestCaller<SimpleFglTest>(
                                  "testDbGlobModFunc",
                                  &SimpleFglTest::testDbGlobModFunc) );
    suiteOfTests->addTest( new CppUnit::TestCaller<SimpleFglTest>(
                                  "testEmptyFunction",
                                  &SimpleFglTest::testEmptyFunction) );
    return suiteOfTests;
	}
  void setUp();
  void tearDown();
  void testEmpty();
  void testHello();
  void testReservedHello();
  void testOnlyModular();
  void testOnlyGlobalVar();
  void testOnlyFunction();
  void testOnlyMain();
  void testOnlyGlobalInclude();
  void testModularGlobalFunction();
  void testModularFunction();
  void testThreeGlobalInclude();
  void testGlobalIncludeGlobalVar();
  void testOnlyDatabase();
  void testDatabaseModular();
  void testDatabaseGlobals();
  void testDbGlobModFunc();
  void testEmptyFunction();
};

#endif
