
DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
  DROP TABLE tbl_ol_in_db 
  DROP TABLE tbl_ol_ext 
  DROP TABLE tbl_ol_ns 
  DROP TABLE tbl_ol_ext_ns 
  DROP TABLE tbl_ol_lmp 
  DROP TABLE tbl_ol_lmr 
	DROP TABLE tbl_ol_complex 
	WHENEVER ERROR STOP
  CREATE TABLE tbl_ol_in_db (
	  just_a_field INTEGER
	) IN rootdbs

  CREATE TABLE tbl_ol_ext (
	  just_a_field INTEGER
	) EXTENT SIZE 10

  CREATE TABLE tbl_ol_ns (
	  just_a_field INTEGER
	) NEXT SIZE 10

  CREATE TABLE tbl_ol_ext_ns (
	  just_a_field INTEGER
	) EXTENT SIZE 10 NEXT SIZE 20

  CREATE TABLE tbl_ol_lmp (
	  just_a_field INTEGER
	) LOCK MODE PAGE

  CREATE TABLE tbl_ol_lmr (
	  just_a_field INTEGER
	) LOCK MODE ROW

	CREATE TABLE tbl_ol_complex (
	  just_a_field INTEGER
	) IN rootdbs EXTENT SIZE 10 NEXT SIZE 20 LOCK MODE ROW
  DROP TABLE tbl_ol_in_db 
  DROP TABLE tbl_ol_ext 
  DROP TABLE tbl_ol_ns 
  DROP TABLE tbl_ol_ext_ns 
  DROP TABLE tbl_ol_lmp 
  DROP TABLE tbl_ol_lmr 
	DROP TABLE tbl_ol_complex 

END MAIN
