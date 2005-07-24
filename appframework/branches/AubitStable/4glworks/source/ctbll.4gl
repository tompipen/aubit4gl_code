#	CTBLL.4gl  -  DB & table oriented functions
#
#	The 4glWorks application framework
#	Copyright (C) 1992-2002 Marco Greco (marco@4glworks.com)
#
#	Initial release: Oct 92
#	Current release: Jan 02
#
#	This library is free software; you can redistribute it and/or
#	modify it under the terms of the GNU Lesser General Public
#	License as published by the Free Software Foundation; either
#	version 2.1 of the License, or (at your option) any later version.
#
#	This library is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#	Lesser General Public License for more details.
#
#	You should have received a copy of the GNU Lesser General Public
#	License along with this library; if not, write to the Free Software
#	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

define	db_locked	smallint,
	tbl_locked,
	tbl_old		char(20),
	db_seengine,
	db_modeansi,
	db_withlog	smallint

#
#  module initialization
#
function tbl_init()
    whenever error call trap_err
    let db_locked=""
    let tbl_locked=""
    let tbl_old=""
    let db_seengine=""
    let db_modeansi=""
    let db_withlog=""
end function
#
#  remote table test
#
function tbl_remote(s)
    define s	char(50),
	   db	char(64),
	   rm	integer

    let db=""
    select syssyntable.dbname into db from syssyntable, systables
      where systables.tabname=s
	and systables.tabid=syssyntable.tabid
    let rm=(status=0) and (db is not null)
    return rm
end function
#
#  (Re)open database in selected mode
#
function db_open(db, ex)
    define db	char(64),
	   ex	integer,
	   s	integer

#
#  sqlca.sqlcode *must* be intact in case the db cannot be opened
#
    if db_locked is not null
    then
	close database
    end if
    let db_locked=ex
    if ex
    then
	whenever error continue
	database db exclusive
	let s=status
	if s!=0
	then
	    database db
	    let s=status
	    let db_locked=false
	end if
    else
	database db
	let s=status
    end if
    whenever error call trap_err
    let db_seengine=SQLCA.SQLAWARN[4]!="W"
    let db_modeansi=SQLCA.SQLAWARN[3]="W"
    let db_withlog=SQLCA.SQLAWARN[2]="W"
    case
      when s!=0
	let db_locked=""
	return ""
      when tbl_locked is null
      when tbl_lock(tbl_locked)
    end case
    call frm_testblobs()
    let db_locked=ex
    return db_locked
end function
#
#  close database
#
function db_close()
    if db_locked is not null
    then
	close database
    end if
    let db_locked=""
    let db_seengine=""
    let db_withlog=""
    let db_modeansi=""
end function
#
#  return database status
#
function db_islocked()
    return db_locked
end function
#
#  return logging status
#
function db_uselogs()
    return db_withlog
end function
#
#  return database engine
#
function db_isse()
    return db_seengine
end function
#
#  true if mode ansi db
#
function db_isansi()
    return db_modeansi
end function
#
#  issue a begin work if necessary
#
function wrk_begin()
    if db_withlog
    then
	begin work
    end if
end function
#
#  returns cursor open status, optionally rolling back work
#
function wrk_check()
    call check_lock()
    case
      when (SQLCA.SQLCODE=0)
	return false
      when db_withlog
	rollback work
    end case
    return true
end function
#
#  commits/rolls back work according to int_flag, true if cursor needs closing
#
function wrk_end()
    case
      when not db_withlog
	return true
      when int_flag
        rollback work
      otherwise
	commit work
    end case
    return false
end function
#
#  issue a commit work if necessary, true if cursor needs closing
#
function wrk_commit()
    if db_withlog
    then
	commit work
    end if
    return (not db_withlog)
end function
#
#  issue a rollback work if necessary, true if cursor needs closing
#
function wrk_rollback()
    if db_withlog
    then
	rollback work
    end if
    return (not db_withlog)
end function
#
#  table lock
#
function tbl_lock(t)
    define t	char(20),
	   s	char(50),
	   sr	integer

    let sr=0
    if not (db_locked) or tbl_remote(t)
    then
	let s="lock table ", t clipped
#
#  AFAIK there's no way that SE can have synonyms pointing to
#  tables residing in a remote ONLINE server (and viceversa).
#  If there is, then this code is too simplicistic!
#
	if db_seengine
	then
	    let s=s clipped, " in share mode"
	else
	    let s=s clipped, " in exclusive mode"
	end if
	prepare lock_stat from s
	whenever error continue
	execute lock_stat
	whenever error call trap_err
	let sr=status
	call check_lock()
	free lock_stat
    end if
    return (sr=0)
end function
#
#  table lock, with a simulated SET LOCK WAIT TO secs
#
function tbl_lockwait(t, c)
    define t	char(20),
	   c	smallint,
	   s	char(50),
	   sr	integer

    let sr=0
    if not (db_locked) or tbl_remote(t)
    then
	let s="lock table ", t clipped
#
#  AFAIK there's no way that SE can have synonyms pointing to
#  tables residing in a remote ONLINE server (and viceversa).
#  If there is, then this code is too simplicistic!
#
	if db_seengine
	then
	    let s=s clipped, " in share mode"
	else
	    let s=s clipped, " in exclusive mode"
	end if
	prepare lock_waitstat from s
	while (true)
	    whenever error continue
	    execute lock_waitstat
	    whenever error call trap_err
	    let sr=status
	    if (sr=0) or (c<=1)
	    then
		exit while
	    end if
	    sleep 1
	    let c=c-1
	end while
	call check_lock()
	free lock_waitstat
    end if
    return (sr=0)
end function
#
#  table unlock
#
function tbl_unlock(t)
    define t	char(20),
	   s	char(50)

    if (not db_locked) or tbl_remote(t)
    then
	let s="unlock table ", t clipped
	prepare unlock_stat from s
	execute unlock_stat
	free unlock_stat
    end if
end function
#
#  locks table during viewer execution
#
function tbl_holdlock(t)
    define t	char(20)

    if db_withlog
    then
#
#  This is a very scary situation - using a table lock for a table
#  maintenance viewer in a database with logs. Don't do it.
#  That's why I'm generating an error here (even though the code is not
#  really relevant)
#
	let status=-255
	call trap_err()
	return false
    end if
    if tbl_lock(t)
    then
	if tbl_locked is not null
	then
	    let tbl_old=tbl_locked
	end if
	let tbl_locked=t
	return true
    end if
    return false
end function
#
#  releases table after viewer execution
#
function tbl_lockdone()
    define s	char(50),
	   t	char(20)

    case
      when tbl_old is not null
	let t=tbl_old
	let tbl_old=""
      when tbl_locked is not null
	let t=tbl_locked
	let tbl_locked=""
      otherwise
	return
    end case
    call tbl_unlock(t)
end function
#
#  checks result of tentative lock & issues error msg
#
function check_lock()
    case sqlca.sqlcode
      when 0
      when notfound
	call usr_warn("ctbl.na")
      when -244
	call usr_warn("ctbl.rm")
      when -246
	call usr_warn("ctbl.rm")
      when -250
	call usr_warn("ctbl.rm")
      when -289
	call usr_warn("ctbl.tm")
      when -291
	call usr_warn("ctbl.tm")
      otherwise
	call usr_warn(sqlca.sqlcode)
    end case
end function
#
#  checks result of a tentative insert/update and issues error message
#
function check_writeop()
    case sqlca.sqlcode
      when 0
      when -239
	call usr_warn("ctbl.rt")
      when -452
	call usr_warn("ctbl.nb")
      otherwise
	call check_lock()
    end case
end function
#
#  checks result of database stmt
#
function check_dbopen()
    case sqlca.sqlcode
      when 0
      when -354
	call usr_warn("ctbl.bn")
      when -1
	call usr_warn("ctbl.ed")
      when -459
	call usr_warn("ctbl.ed")
      when -329
	call usr_warn("ctbl.ndb")
      when -425
	call usr_warn("ctbl.dbl")
      when -387
	call usr_warn("ctbl.uu")
      otherwise
	call usr_warn(sqlca.sqlcode)
    end case
end function
