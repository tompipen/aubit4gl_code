// SimpleFglTest.cpp

#include <stdio.h>
#include "SimpleFglTest.h"

// @todo : Declare this in a .h
int parse_4gl(const char *fileName);

#define PARSE_OK 0

// Registers the fixture into the 'registry'
//CPPUNIT_TEST_SUITE_REGISTRATION( SimpleFglTest );


void 
SimpleFglTest::setUp()
{
}


void 
SimpleFglTest::tearDown()
{
}

void SimpleFglTest::testEmpty()
{
  CPPUNIT_ASSERT_EQUAL( PARSE_OK, parse_4gl("fgl/fgl_structure/empty.4gl") );
}


void 
SimpleFglTest::testHello()
{
  // Set up

  // Process

  // Check
  CPPUNIT_ASSERT_EQUAL( PARSE_OK, parse_4gl("fgl/simple/hello.4gl") );
}

void SimpleFglTest::testReservedHello()
{
  CPPUNIT_ASSERT_EQUAL( PARSE_OK, parse_4gl("fgl/simple/reserved_hello.4gl") );
}

void SimpleFglTest::testOnlyModular()
{
  CPPUNIT_ASSERT_EQUAL( PARSE_OK, parse_4gl("fgl/fgl_structure/only_modular_var.4gl"));
}

void SimpleFglTest::testOnlyGlobalVar()
{
  CPPUNIT_ASSERT_EQUAL(
		PARSE_OK,parse_4gl("fgl/fgl_structure/only_global_var.4gl") 
	);
}

void SimpleFglTest::testOnlyFunction()
{
  CPPUNIT_ASSERT_EQUAL(
		PARSE_OK,parse_4gl("fgl/fgl_structure/only_function.4gl") 
	);
}

void SimpleFglTest::testOnlyMain()
{
  CPPUNIT_ASSERT_EQUAL(
		PARSE_OK,parse_4gl("fgl/fgl_structure/only_main.4gl") 
	);
}

void SimpleFglTest::testOnlyGlobalInclude()
{
  CPPUNIT_ASSERT_EQUAL(
		PARSE_OK,parse_4gl("fgl/fgl_structure/only_global_include.4gl") 
	);
}

void SimpleFglTest::testModularGlobalFunction()
{
  CPPUNIT_ASSERT_EQUAL(
		PARSE_OK,parse_4gl("fgl/fgl_structure/global_modular_function.4gl") 
	);
}

void SimpleFglTest::testModularFunction()
{
  CPPUNIT_ASSERT_EQUAL(
		PARSE_OK,parse_4gl("fgl/fgl_structure/modular_function.4gl") 
	);
}

void SimpleFglTest::testThreeGlobalInclude()
{
  CPPUNIT_ASSERT_EQUAL(
		PARSE_OK,parse_4gl("fgl/fgl_structure/three_global_include.4gl") 
	);
}

void SimpleFglTest::testGlobalIncludeGlobalVar()
{
  CPPUNIT_ASSERT_EQUAL(
		PARSE_OK,parse_4gl("fgl/fgl_structure/global_include_global_var.4gl") 
	);
}

void SimpleFglTest::testOnlyDatabase()
{
  CPPUNIT_ASSERT_EQUAL(
		PARSE_OK,parse_4gl("fgl/fgl_structure/only_database.4gl") 
	);
}

void SimpleFglTest::testDatabaseModular()
{
  CPPUNIT_ASSERT_EQUAL(
		PARSE_OK,parse_4gl("fgl/fgl_structure/database_modular.4gl") 
	);
}

void SimpleFglTest::testDatabaseGlobals()
{
  CPPUNIT_ASSERT_EQUAL(
		PARSE_OK,parse_4gl("fgl/fgl_structure/database_globals.4gl") 
	);
}

void SimpleFglTest::testDbGlobModFunc()
{
  CPPUNIT_ASSERT_EQUAL(
		PARSE_OK,parse_4gl("fgl/fgl_structure/db_glob_mod_func.4gl") 
	);
}

void SimpleFglTest::testEmptyFunction()
{
  CPPUNIT_ASSERT_EQUAL(
		PARSE_OK,parse_4gl("fgl/fgl_structure/empty_function.4gl") 
	);
}
