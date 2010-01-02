/*
 * fgldoc, an Informix-4GL program documenter
 * Copyright (c) 1995-1999 Ivan Nejgebauer <ian@uns.ns.ac.yu>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

EXEC SQL include sqlca;
EXEC SQL include sqltypes;

read_progdbs(pname, mod_reg_func)
    char *pname;
    int (*mod_reg_func)();
{
    char *pdbs;

    EXEC SQL BEGIN DECLARE SECTION;
	char dbname[19];
	char progname[11];
	string modname[11];
	string modpath[41];
    EXEC SQL END DECLARE SECTION;

    dbname[sizeof dbname - 1] = '\0';
    if ((pdbs = getenv("PROGRAM_DESIGN_DBS")) != NULL)
	strncpy(dbname, pdbs, sizeof dbname - 1);
    else
	strcpy(dbname, "syspgm4gl");
    progname[sizeof progname - 1] = '\0';
    strncpy(progname, pname, sizeof progname - 1);

    EXEC SQL whenever sqlerror call bail_out;

    EXEC SQL database :dbname;

    EXEC SQL declare c_source cursor for
	select fglsourcename, spath into :modname, :modpath from source4gl
	    where progname = :progname and fglsourcename is not null;
    EXEC SQL open c_source;
    while (1) {
	EXEC SQL fetch c_source;
	if (SQLCODE != 0)
	    break;
	mod_reg_func(modname, risnull(SQLCHAR, modpath) ? "." : modpath);
    }
    EXEC SQL close c_source;
    EXEC SQL free c_source;

    EXEC SQL whenever sqlerror goto no_consequence;

    EXEC SQL declare c_global cursor for
	select globname, gpath into :modname, :modpath from global
	    where progname = :progname and globname is not null;
    EXEC SQL open c_global;
    while (1) {
	EXEC SQL fetch c_global;
	if (SQLCODE != 0)
	    break;
	mod_reg_func(modname, risnull(SQLCHAR, modpath) ? "." : modpath);
    }
    EXEC SQL close c_global;
    EXEC SQL free c_global;

no_consequence:
    EXEC SQL close database;
}

#define MBUFSIZE	1024	/* error message buffer size */

#define FATAL(msg) \
    fprintf(stderr, "Fatal error trying to report SQL error %d:\n%s.\n", \
	    SQLCODE, msg)

#ifdef HAVE_RGETLMSG
#define MSGFUNC rgetlmsg
#define GETMSG(code) MSGFUNC(code, mbuf, MBUFSIZE, &msglen)
#else
#define MSGFUNC rgetmsg
#define GETMSG(code) MSGFUNC(code, mbuf, (short) MBUFSIZE)
#endif

bail_out()
{
    char mbuf[MBUFSIZE];
    int msglen;
    int gmerr;

    switch (gmerr = GETMSG(SQLCODE)) {
    case 0:
	break;
    case -1227:
	FATAL("Error number -1227:\nMessage file not found.");
	break;
    case -1228:
	FATAL("Error number -1228:\nMessage number not found in message file.");
	break;
    case -1231:
	FATAL("Error number -1231:\nCannot seek within message file.");
	break;
    case -1232:
	FATAL("Error number -1232:\nMessage buffer too small.");
	break;
    default:
	sprintf(mbuf, "Unknown error %d from %s()", gmerr, MSGFUNC);
	FATAL(mbuf);
	break;
    }

    if (gmerr == 0) {
	fprintf(stderr, "SQL statement error number %d.\n", SQLCODE);
	fprintf(stderr, mbuf, sqlca.sqlerrm);
    }
    exit(1);
}
