/**
 * @file
 * Header of creation test suite for informix direct aubit 4gl access.
 */

#ifndef INFORMIX_TEST_H
#define INFORMIX_TEST_H
	Suite *makeInformixConnectionSuite	(void);
	Suite *makeDdlSuite					(void);
	Suite *makeDmlSuite					(void);


    /* ----------------- prototypes ----------------------- */

    /* test_informix_util.ec */
	int cleanTestTable				(void);
	int countTestRows				(void);
	int insertTestRows				(void);
	int countTestRowsWithWhere		(char *str);
    int createTestTable				(void);
    int dropTestTable				(void);
    int connectToTestInstance		(void);
    int createDatabase				(char *dbName);
    int disconnectFromTestInstance	(void);
    int tableExist					(char *tableName);
	int validateTestRow	(int an_int_var,char *a_char_var,float a_decimal_var);


#endif

