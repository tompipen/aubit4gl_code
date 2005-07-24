-- @(#)$Id: translog.4gl,v 1.1 2002-06-20 09:10:42 afalout Exp $
-- @(#)JLSS Informix Tools: General Library
-- @(#)Handle transactions whether database has log or not
-- @(#)Author: JL

DEFINE
	logstatus	INTEGER
	{ 0 => State of log unknown, 1 => Log absent, 2 => Log present }

{ Determine whether there is a transaction log }
FUNCTION	translog()

	DEFINE
		sccs	CHAR(1),
		logs	INTEGER

	IF logstatus = 0 THEN
		LET sccs = "@(#)$Id: translog.4gl,v 1.1 2002-06-20 09:10:42 afalout Exp $"
		LET logs = get_databaselogs()
		IF logs = FALSE THEN
			LET logstatus = 1 { Log absent }
		ELSE
			LET logstatus = 2 { Log present }
		END IF
	END IF

	RETURN (logstatus = 2)

END FUNCTION {translog}

{ Begin a transaction if there is a log }
FUNCTION begin_work()

	IF translog() THEN
		WHENEVER ERROR CONTINUE
		BEGIN WORK
		WHENEVER ERROR STOP
	END IF

END FUNCTION {begin_work}

{ Commit a transaction if there is a log }
FUNCTION commit_work()

	IF translog() THEN
		WHENEVER ERROR CONTINUE
		COMMIT WORK
		WHENEVER ERROR STOP
	END IF

END FUNCTION {commit_work}

{ Rollback transaction if there is a log }
FUNCTION rollback_work()

	IF translog() THEN
		WHENEVER ERROR CONTINUE
		ROLLBACK WORK
		WHENEVER ERROR STOP
	END IF

END FUNCTION {rollback_work}

{ Terminate a transaction }
FUNCTION end_work(state)

	DEFINE
		state	INTEGER

	IF state != 0 THEN
		CALL rollback_work()
	ELSE
		CALL commit_work()
	END IF

END FUNCTION {end_work}
