{
	@(#)$Id: perfaux.4gl,v 1.1.1.1 2002-06-15 05:07:14 afalout Exp $
	@(#)Generic Simplified Perform Program
	@(#)Author: Jonathan Leffler, Sphinx Ltd.
	@(#)Miscellaneous support routines
}

{ Global to this file -- not accessible outside }
DEFINE
	logstatus	INTEGER
	{ 0 => State of log unknown, 1 => Log absent, 2 => Log present }

{ Warn about ignored interrupt if interrupt has occurred }
FUNCTION check_interrupt()

	IF int_flag != 0 THEN
		ERROR "Interrupt detected -- ignored"
		LET int_flag = 0
	END IF

END FUNCTION {check_interrupt}

{ Provide shell escape -- allow user to run commands }
FUNCTION shell_escape()

	DEFINE
		cmd		CHAR(80),
		ans		CHAR(1)

	PROMPT "! " FOR cmd
	RUN cmd
	RUN "echo" { Scroll screen up if prompt line is bottom line }
	PROMPT "Hit any key to continue" FOR CHAR ans

END FUNCTION {shell_escape}

{ Determine whether there is a transaction log }
FUNCTION	translog()

	DEFINE
		junk	INTEGER

	IF logstatus = 0 THEN
		SELECT Tabid
			INTO junk
			FROM Systables
			WHERE Systables.Tabtype = 'L'
		IF STATUS = NOTFOUND THEN
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
		BEGIN WORK
	END IF

END FUNCTION {begin_work}

{ Commit a transaction if there is a log }
FUNCTION commit_work()

	IF translog() THEN
		COMMIT WORK
	END IF

END FUNCTION {commit_work}

{ Rollback transaction if there is a log }
FUNCTION rollback_work()

	IF translog() THEN
		ROLLBACK WORK
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
