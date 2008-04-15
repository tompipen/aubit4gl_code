.0
SQLITE_OK


This value is returned if everything worked and there were no errors. 
.2
SQLITE_INTERNAL


This value indicates that an internal consistency check within the SQLite library failed. This can only happen if there is a bug in the SQLite library. If you ever get an SQLITE_INTERNAL reply from an sqlite_exec call, please report the problem on the SQLite mailing list. 
.1
SQLITE_ERROR


This return value indicates that there was an error in the SQL that was passed into the sqlite_exec. 
.3
SQLITE_PERM


This return value says that the access permissions on the database file are such that the file cannot be opened. 
.4
SQLITE_ABORT


This value is returned if the callback function returns non-zero. 
.5
SQLITE_BUSY


This return code indicates that another program or thread has the database locked. SQLite allows two or more threads to read the database at the same time, but only one thread can have the database open for writing at the same time. Locking in SQLite is on the entire database.
.6
SQLITE_LOCKED


This return code is similar to SQLITE_BUSY in that it indicates that the database is locked. But the source of the lock is a recursive call to sqlite_exec. This return can only occur if you attempt to invoke sqlite_exec from within a callback routine of a query from a prior invocation of sqlite_exec. Recursive calls to sqlite_exec are allowed as long as they do not attempt to write the same table. 
.7
SQLITE_NOMEM


This value is returned if a call to malloc fails. 
.8
SQLITE_READONLY


This return code indicates that an attempt was made to write to a database file that is opened for reading only. 
.9
SQLITE_INTERRUPT


This value is returned if a call to sqlite_interrupt interrupts a database operation in progress. 
.10
SQLITE_IOERR


This value is returned if the operating system informs SQLite that it is unable to perform some disk I/O operation. This could mean that there is no more space left on the disk. 
.11
SQLITE_CORRUPT


This value is returned if SQLite detects that the database it is working on has become corrupted. Corruption might occur due to a rogue process writing to the database file or it might happen due to an perviously undetected logic error in of SQLite. This value is also returned if a disk I/O error occurs in such a way that SQLite is forced to leave the database file in a corrupted state. The latter should only happen due to a hardware or operating system malfunction. 
.13
SQLITE_FULL


This value is returned if an insertion failed because there is no space left on the disk, or the database is too big to hold any more information. The latter case should only occur for databases that are larger than 2GB in size. 
.14
SQLITE_CANTOPEN


This value is returned if the database file could not be opened for some reason. 
.15
SQLITE_PROTOCOL


This value is returned if some other process is messing with file locks and has violated the file locking protocol that SQLite uses on its rollback journal files. 
.17
SQLITE_SCHEMA


When the database first opened, SQLite reads the database schema into memory and uses that schema to parse new SQL statements. If another process changes the schema, the command currently being processed will abort because the virtual machine code generated assumed the old schema. This is the return code for such cases. Retrying the command usually will clear the problem. 
.18
SQLITE_TOOBIG


SQLite will not store more than about 1 megabyte of data in a single row of a single table. If you attempt to store more than 1 megabyte in a single row, this is the return code you get. 
.19
SQLITE_CONSTRAINT


This constant is returned if the SQL statement would have violated a database constraint. 
.20
SQLITE_MISMATCH


This error occurs when there is an attempt to insert non-integer data into a column labeled INTEGER PRIMARY KEY. For most columns, SQLite ignores the data type and allows any kind of data to be stored. But an INTEGER PRIMARY KEY column is only allowed to store integer data. 
.21
SQLITE_MISUSE


This error might occur if one or more of the SQLite API routines is used incorrectly. Examples of incorrect usage include calling sqlite_exec after the database has been closed using sqlite_close or calling sqlite_exec with the same database pointer simultaneously from two separate threads. 
.22
SQLITE_NOLFS


This error means that you have attempts to create or access a file database file that is larger that 2GB on a legacy Unix machine that lacks large file support. 
.23
SQLITE_AUTH


This error indicates that the authorizer callback has disallowed the SQL you are attempting to execute. 
.100
SQLITE_ROW


This is one of the return codes from the sqlite_step routine which is part of the non-callback API. It indicates that another row of result data is available. 
.101
SQLITE_DONE


This is one of the return codes from the sqlite_step routine which is 
part of the non-callback API. It indicates that the SQL 
statement has been completely executed and the sqlite_finalize 
routine is ready to be called. 
