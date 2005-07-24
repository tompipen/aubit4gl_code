/**********************************************************************
 * Copyright (C) 1992-2002 Sanderson Wacher Pty. Limited
 * All rights reserved.
 * Use, modification, duplication, and/or distribution of this
 * software is limited by the software license agreement.
 * Sccsid: %Z% %M%%Y% %Q%%I% %E%
 **********************************************************************/

# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<ctype.h>
# include	<string.h>
# include	<fcntl.h>
# include	<errno.h>


/* Informix specific includes */

# include	<sqltypes.h>
# include	<sqlhdr.h>
# include	<sqlfm.h>
# include	<sqlca.h>
# include	<decimal.h>


/* various string limits and the strings themselves */
/* generous but arbitrary. Some functions use dynamic strings instead */

# define	CFGL_PATH	1024
# define	CFGL_IOBUF	2048
# define	CFGL_STRING	2048
# define	CFGL_FMODE	16

typedef char cfgl_Path   [CFGL_PATH   + 1];
typedef char cfgl_IOBuf  [CFGL_IOBUF  + 1];
typedef char cfgl_String [CFGL_STRING + 1];
typedef char cfgl_FMode  [CFGL_FMODE  + 1];


/* macro for C-4GL function headers */
/* also scanned for by Perl scripts for nefarious purposes */

# define   function(name,min,max,step,return)	int name(int nargs)


/* the following empty macro is purely for the sake of generating */
/* variants in the interface files (eg fglext.c and fgiusr.c).    */
/* The RUNNER macro is detected by Perl scripts. The contents is  */
/* a single arg (to keep cpp happy) and the string may name an    */
/* interface file and an optional override name for the function  */
/* eg    RUNNER(fglext c_getkey)                                  */
/* must be used one per line between the function macro and the   */
/* leading { of the function itself                               */

# define   RUNNER(contents)


/* theirs and ours */

extern int errno, cfgl_errno;


/* flags work-around for old-fashioned Four J's argument rules */
/* Should be obsolete from version 3.00+ of Four J's */

extern int cfgl_badargs;


/* used in symbol tables - associative array, ok? */

typedef struct
{
    char *name;
    long value;
} cfgl_Assoc;

/* support functions for constants */
long cfgl_const(cfgl_Assoc table[], size_t count, char *tab, char *name);


/* dynamic strings for growable buffers */

typedef struct
{
    int alloc;
    int len;
    char *str;
} cfgl_DynStr;

void cfgl_initstr(cfgl_DynStr *dyn);
void cfgl_strcat(cfgl_DynStr *dyn, char *str);
void cfgl_retstr(cfgl_DynStr *dyn);


/* All allocated blocks have a header up front so that all memory access */
/* can be checked. This is the 4GL world, not C, so we can't have cowboy */
/* library routines - our happy little programmers wouldn't have a HOPE  */
/* to catch memory overruns - no slight on them, it's just the environ.  */

# if WORD_BIT <= 32
   typedef int cfgl_MemInt;
# else
   typedef short cfgl_MemInt;
# endif

# if WORD_BIT <= 32 || SHRT_MAX < INT_MAX
#  define	CFGL_MAGIC	0x6b656b61
# else
#  define	CFGL_MAGIC	0x6861626565627465
# endif

typedef struct cfgl_MemBlock *cfgl_MemPtr;

struct cfgl_MemCtrl
{
    cfgl_MemPtr prev, next;
    cfgl_MemInt magic;	/* attempt to detect scribbling by memory library */
    cfgl_MemInt serial;	/* the serial number is printed in errors */
    cfgl_MemInt size;	/* the serial can be getted from 4GL for debugging */
};

typedef struct cfgl_MemBlock
{
    struct cfgl_MemCtrl ctrl;
    char m[1];
} cfgl_MemBlock;

# define	M_NEXT		ctrl.next
# define	M_PREV		ctrl.prev
# define	M_MAGIC		ctrl.magic
# define	M_SERIAL	ctrl.serial
# define	M_SIZE		ctrl.size

/* memory support functions */
cfgl_MemPtr cfgl_getptr(void);
int cfgl_getint(cfgl_MemPtr);
void cfgl_checkmem(char *action, cfgl_MemPtr mp, int ofs, int del);


/* special error status returned for fatal errors. If you see a    */
/* program terminate with this error status, it's almost certainly */
/* a usage error or an error in the C library itself               */

# define	CFGL_FATAL	254

/* general purpose error termination - typically for usage problems */
void cfgl_fatal(char *format, ...);


/* string support functions */
void cfgl_ucase(char *str);
void cfgl_lcase(char *str);
int  cfgl_trim(char *str);

/* signal support functions */
int   cfgl_get_sig(void);
char *cfgl_sig_name(int sig);

/* FILE type support functions */
int   cfgl_interpMode(char *str);
FILE *cfgl_getfd(int fileno);
int   cfgl_setfd(FILE *fp);
void  cfgl_unsetfd(FILE *fp);
void  cfgl_popfd(FILE **fp);
void  cfgl_retfd(FILE *fp);

