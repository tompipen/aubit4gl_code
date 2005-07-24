Code to handle CONNECT, DISCONNECT and SET CONNECTION statements in I4GL
========================================================================

The code accompanying this is designed for use with ANSI C compilers --
it uses prototypes -- and will work with version 6.00, 6.01 or 6.02 I4GL.
There is no reason to suppose it will not work with other, later versions
of I4GL.

If you are compiling with 6.00, you will need the popstring() routine
from popstr.c; if you are using 6.01 or later, the routine is in the I4GL
library and popstr.o should not be linked -- it will cause the link to
fail.  If you are using 6.02 or later, you can use the header 'fglsys.h'
to pick up the prototypes for the routines popstring(), retint() and
fgl_fatal().

The I4GL programmer must invent one or more distinct connection names,
and these will be used to specify the connection names.  Establishing the
user ID and the authorisation string (password) are also problems for the
programmer.

The routines available are:

    DEFINE
        dbase   CHAR(80),
        uconn   CHAR(18),
        uname   CHAR(18),
        uauth   CHAR(18)
    DEFINE
        retval  INTEGER

    LET dbase = "..."
    LET uconn = "..."
    LET uname = "..."
    LET uauth = "..."

    LET retval = connect_default()
    LET retval = connect_dbase_by_name(dbase, uconn)
    LET retval = connect_dbase_by_name_user(dbase, uconn, uname, uauth)

    LET retval = connect_default_wct()
    LET retval = connect_dbase_by_name_wct(dbase, uconn)
    LET retval = connect_dbase_by_name_user_wct(dbase, uconn, uname, uauth)

    LET retval = disconnect_current()
    LET retval = disconnect_default()
    LET retval = disconnect_by_name(uconn)

    LET retval = set_connect_default()
    LET retval = set_connect_by_name(uconn)
    LET retval = set_connect_db_env(dbase)

In all cases, the returned value is the same as SQLCA.SQLCODE.  Looking
at a 6.0x or later 'Informix Guide to SQL: Syntax' reference manual will
quickly reveal what this code does.  There is precious little difference
between the set_connect_by_name() and set_connect_db_env() routines,
except that the latter has more space for the variable string.  Note that
if you exceed the variable sizes specified above, the names will be
truncated without warning, probably but not necessarily leading to
failure.

Jonathan Leffler
Informix Software Inc
7th July 1995

NB: This software is not supported by Informix Software Inc and is supplied
"as is".  You use it at your own risk.

