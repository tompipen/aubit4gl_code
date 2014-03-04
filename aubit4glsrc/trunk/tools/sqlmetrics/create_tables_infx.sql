
create table sql_log (
   application varchar(30), -- is the program name of the program generating the output
   pid int,    --     is the process ID
   type varchar(10), -- is PREPARE/EXECUTE/OPEN/FETCH/DECLARE/PUT
   cursorname varchar(30), -- is the name of the cursor for a OPEN/FETCH/DECLARE /PUT
   sql varchar(255), --  is the SQL being processed.
   module varchar(30), --  is the modulename of the 4gl where this SQL is located
   lineno int,     --  is the line number in the 4gl where this SQL is located
   elatime float,  --  is the execution of this statement in seconds
   sql_code int,   --  sqlca.sqlcode
   curtime datetime year to fraction(3), --  timestamp
   params varchar(255)
  )
