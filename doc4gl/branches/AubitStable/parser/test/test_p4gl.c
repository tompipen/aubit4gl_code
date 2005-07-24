/**
 * @file
 * Test suite for p4gl unit testing.
 *
 * The purpose is to test everithing that could possible break in p4gl.
 *
 * We need some code modifications in p4gl to suport good tests
 */


#include <stdio.h>
#include <check.h>
#include "p4gl_symtab.h"
#include "p4gl.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

/**
 * Tests the load of tables information in p4gl.
 * This test do not insert in the database and checks if the table was loaded 
 * to the abstract tree.
 *
 * @todo : Terminate the table usage work.
 */
START_TEST(test_table_abstract_tree)
{
	FUNCTION *function;
	TableUsage *tableUsage;

	initP4glPhaseOne();
	setFglSourceFile("TestTable.4gl");
	setRepositoryInsert(0);
	fail_unless(initP4glPhaseTwo(),"Error initializing");
	fail_unless(parseFgl(),"Error parsing the source file");
	OrderSymtab();
	function = getFunction(0);
	tableUsage = getFunctionTableUsage(function,0);
	fail_unless(tableUsage != (TableUsage *)0,"Table usage 0 is null");
	fail_unless(!strcmp(tableUsage->tableName," xpto "),"Table name is not xpto");
	tableUsage = getFunctionTableUsage(function,1);
	fail_unless(tableUsage != (TableUsage *)0,"Table usage 1 is null");
	fail_unless(!strcmp(tableUsage->tableName,"abc"),"Table name is not abc");
}
END_TEST

/**
 * Create the p4gl suite for testing the p4gl documentation parser.
 */
Suite *p4gl_suite(void)
{
  Suite *s = suite_create("P4gl");
	TCase *tc_core = tcase_create("Core");

	suite_add_tcase(s,tc_core);

	tcase_add_test(tc_core,test_table_abstract_tree);
	return s;
}

/**
 * Main entry point of p4gl unit test(s).
 */
int main(void)
{
  int nf;

	Suite *s = p4gl_suite();
	SRunner *sr = srunner_create(s);
	srunner_set_fork_status(sr,CK_NOFORK);
	srunner_run_all(sr,CK_NORMAL);
	nf = srunner_ntests_failed(sr);
	srunner_free(sr);
	suite_free(s);
	return (nf == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

