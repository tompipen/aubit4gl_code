
DATABASE test1

MAIN
	WHENEVER ERROR CONTINUE
	DROP TABLE xpto
	DROP TABLE xpta
	DROP TABLE xpti
	WHENEVER ERROR STOP
  CREATE TABLE xpto (
	  aColumn CHAR(5),
		secondColumn INTEGER,
	  third_column SMALLINT,
	  forth_column DECIMAL(16,2) NOT NULL
	)
	ALTER TABLE xpto ADD CONSTRAINT PRIMARY KEY (aColumn,secondColumn)
	ALTER TABLE xpto ADD CONSTRAINT UNIQUE (aColumn)
	ALTER TABLE xpto ADD CONSTRAINT DISTINCT (third_Column,forth_column)
	ALTER TABLE xpto ADD CONSTRAINT CHECK (third_column > 10)

  CREATE TABLE xpta (
	  aColumn CHAR(5),
		secondColumn INTEGER,
	  third_column SMALLINT,
	  forth_column DECIMAL(16,2) NOT NULL
	)
	ALTER TABLE xpta ADD CONSTRAINT PRIMARY KEY (aColumn,secondColumn)
	  CONSTRAINT pk_xpta
	ALTER TABLE xpta ADD CONSTRAINT UNIQUE (aColumn)
	  CONSTRAINT unique_xpta
	ALTER TABLE xpta ADD CONSTRAINT DISTINCT (third_column,forth_column)
	  CONSTRAINT distinct_xpta
	ALTER TABLE xpto ADD CONSTRAINT CHECK (third_column > 10)
	  CONSTRAINT check_xpta

  CREATE TABLE xpti (
	  aColumn CHAR(5),
		secondColumn INTEGER,
	  third_column SMALLINT,
	  forth_column DECIMAL(16,2) NOT NULL
	)
	ALTER TABLE xpti ADD CONSTRAINT (
	  PRIMARY KEY (aColumn,secondColumn),
	  UNIQUE (aColumn) CONSTRAINT unique_xpti,
	  DISTINCT (third_column,forth_column) CONSTRAINT distinct_xpti,
	  CHECK (third_column > 10) CONSTRAINT check_xpti
	)
	DROP TABLE xpto
	DROP TABLE xpta
	DROP TABLE xpti
END MAIN
