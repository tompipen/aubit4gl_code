
DATABASE test1

MAIN
  DEFINE r RECORD
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	END RECORD

	WHENEVER ERROR CONTINUE
	DROP TABLE xpto_tmp
	WHENEVER ERROR STOP
	CREATE temp TABLE xpto_tmp (
	  firstColumn SMALLINT,
	  secondColumn CHAR(10)
	)
	INSERT INTO xpto_tmp VALUES (1,"Xpto")
	UNLOAD TO "unlfile.unl" SELECT * FROM xpto_tmp
	DELETE FROM xpto_tmp
	LOAD FROM "unlfile.unl" INSERT INTO xpto_tmp
	SELECT * INTO r.* FROM xpto_tmp
	DISPLAY r.*
	DROP TABLE xpto_tmp
END MAIN
