
DATABASE test1

MAIN
  whenever error continue
	drop table test_table
  whenever error stop
  CREATE TABLE test_table (
	  anIntField INTEGER
	)
	
	DROP TABLE test_table
END MAIN



