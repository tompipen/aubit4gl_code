#ifndef	_SXML_H_
#define	_SXML_H_

#include <strings.h>

typedef struct _sxml_
{
	struct _sxml_ *next;
	struct _sxml_ *parent;
	struct _sxml_ *sub;
	char *value;
	char *name;
} SXML;

/*
 * Programmer Interface
 */

/* XML handling */
SXML *sxml_get_next(SXML *, const char *, int);
SXML *sxml_get_sub(SXML *, const char *, int);
char *sxml_get_value(SXML *, const char *, int);
int sxml_readfile(const char *, SXML **);
SXML *sxml_put_next(SXML **, char *);
SXML *sxml_put_sub(SXML **, char *);
char *sxml_put_value(SXML *, char *);
int sxml_writefile(const char *, const SXML *);
size_t sxml_createbuf(char **, const char *, const SXML *);
int sxml_parsebuf(const char *, SXML **);
void sxml_free_tree(SXML **);

/* error handling */
char *sxml_errstr(int);

enum
{
	SXML_ERR_SYNTAX = 1,
	SXML_ERR_SYNTAX_COMMENT,
	SXML_ERR_MEM,
	SXML_ERR_INVAL,
	SXML_ERR_FILE_ERROR,
	SXML_ERR_FILE_EMPTY,
	SXML_ERR_FILE_BADF,
	SXML_ERR_FILE_INVAL
} sxml_errcodes;

#ifdef	_REENTRANT
#warning "not working code, the library is not threadsafe yet"
/*
 * not working code, this library is not thread safe yet
 */
#	define	sxml_errno	__sxml_errno_r()
	extern	int	__sxml_errno_r();
#else
#	ifndef	_SXML_C_
		extern	int	sxml_errno;
#	endif
#endif

#endif	/* _SXML_H_ */

