
/***************************************************************************
 *                                                                         *
 * This table is for user-defined C functions.                             *
 *                                                                         *
 * Each initializer has the form:                                          *
 *                                                                         *
 *	{"name", name, nargs},                                             *
 *                                                                         *
 * Variable # of arguments:                                                *
 *                                                                         *
 *	set nargs to -(maximum # args)                                     *
 *                                                                         *
 * Be sure to declare name before the table and to leave the               *
 * line of 0's at the end of the table.                                    *
 *                                                                         *
 ***************************************************************************/

#include "fgicfunc.h"

int fgl_mqstatus();
int fgl_mqreason();
int fgl_mqerrmsg();
int fgl_mqconnect();
int fgl_mqdisconnect();
int fgl_mqopen();
int fgl_mqopen4write();
int fgl_mqopen4read();
int fgl_mqclose();
int fgl_mqwrite();
int fgl_mqread();
int fgl_mqrecieve();

int fgl_mqwriteonce();

cfunc_t usrcfuncs[] = 
{
	{"fgl_mqstatus",     fgl_mqstatus, 0},
	{"fgl_mqreason",     fgl_mqreason, 0},
	{"fgl_mqerrmsg",     fgl_mqerrmsg, -1},
	{"fgl_mqconnect",    fgl_mqconnect, -1},
	{"fgl_mqdisconnect", fgl_mqdisconnect, 1},
	{"fgl_mqopen",       fgl_mqopen, 3},
	{"fgl_mqopen4write", fgl_mqopen4write, 2},
	{"fgl_mqopen4read",  fgl_mqopen4read, 2},
	{"fgl_mqclose",      fgl_mqclose, 2},
	{"fgl_mqwrite",      fgl_mqwrite, 4},
	{"fgl_mqread",       fgl_mqread, -4},
	{"fgl_mqrecieve",    fgl_mqrecieve, 3},
	{"fgl_mqwriteonce",  fgl_mqwriteonce, -3},
    	{0, 0, 0}
};
