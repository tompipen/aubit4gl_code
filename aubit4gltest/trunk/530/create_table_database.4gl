DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE

#FIXME - should not DROP also have owner prefix?
	DROP TABLE a_table
	WHENEVER ERROR STOP
  CREATE TABLE test1:'informix'.a_table (
	  anInt INTEGER
	)
#FIXME - should not DROP also have owner prefix?
	DROP TABLE a_table
	
{ target platform specific - therefore invalid as general test
  CREATE TABLE test1@unstable:'informix'.a_table (
	  anInt INTEGER
	)
	DROP TABLE a_table
	
}
END MAIN
