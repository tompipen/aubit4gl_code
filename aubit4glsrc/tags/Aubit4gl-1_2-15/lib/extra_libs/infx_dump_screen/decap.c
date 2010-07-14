/*
 * 
 * Strips away the termcap escape sequences.
 * 
 *	Code donated by ICANON Associates Incorporated http://www.icanon.com 
 *  by Joe Lewinski <lewinski@icanon.com>
 */

#include <stdio.h>

#define SET_CHAR(y, x, c)		{ buf[(y)][(x)] = (c); (x)++; if ((x) > 79) { (x)=0; (y)++; } } 
#define ATOI(ar)	((ar != (char *) 0 ? atoi(ar) : 0))

int decap(fp1, fp2)
FILE *fp1, *fp2;
{
	static char buf[25][85];
	extern char *strtok();
	int i, j;
	int ch;
	char token[2000];
	int in_token, token_type, token_curs, graphics;
	
	for (i = 0; i < 25; i++)
	{
		for (j = 0; j < 85; j++)
			buf[i][j] = ' ';
		buf[i][81] = '\0';
	}
	/*
	 * look for escape sequences for vt220
	 *
	 * Typically the Escape Sequence is <ESC> followed by a [ or a (
	 * then an optional string of numbers with embedded semi-colon ";"
	 * then a letter
	 */
	in_token = token_curs = i = j = graphics = 0;
	while ((ch = fgetc(fp1)) != EOF)
	{
		switch(ch)
		{
			case '\033':			/* escape char */
				in_token = 1;
				token_curs = 0;
				token[token_curs++] = ch;
				token[token_curs] = '\0';
				break;
			case '[':
			case '(':
				if (in_token)
				{
					if (token_curs == 1 )
						token_type = '[';
					else
						token_type = '(';
					token[token_curs++] = ch;
					token[token_curs] = '\0';
				}
				else if (!graphics)
				{
					SET_CHAR(i, j, ch);
				}
				/* else eat it */
				break;
			case '0': case '1': case '2': case '3':
			case '4': case '5': case '6': case '7':
			case '8': case '9':
			case ';':
				if (in_token)
				{
					token[token_curs++] = ch;
					token[token_curs] = '\0';
					if (STRCMP(token, "(0") == 0)
					{
						graphics = 1;
						/* fprintf(stderr, "In Graphics\n"); */
						in_token = 0;
					}
				}
				else if (!graphics)
				{
					SET_CHAR(i, j, ch);
				}
				/* else eat it */
				break;
			default:
				if (in_token)
				{
					token[token_curs++] = ch;
					token[token_curs] = '\0';
					if (isalpha(ch))
					{
						in_token = 0;
						if (STRCMP(token, "(B") == 0)
						{
							/* fprintf(stderr, "Out Graphics\n"); */
							graphics = 0;
						}
						if (ch == 'H')
						{
							char *ptr;
							/* fprintf(stderr, "Token(%s)\n", token); */
							ptr = strtok(token + 2, ";");
							i = ATOI(ptr);
							if (i) i--;
							ptr = strtok((char *) NULL, "H");
							j = ATOI(ptr);
							if (j) j--;
							/* fprintf(stderr, "Position i = %d, j = %d \n", i, j); */
						}
					}
	/*
	 * <ESC>[XX;YYH =  positioning sequence to X, Y,
	 *		 (XX or YY can be single or no digits
	 * <ESC>(0   =  graphics start (ignore data until graphics end)
	 * <ESC>(B   =  graphics end
	 * <ESC>[7m   =  standout mode
	 * <ESC>[0m   =  normal mode
	 */
				}
				else if (!graphics)
				{
					if (ch == '\r')
					{
						j = 0;
					}
					if (ch == '\n')
					{
						i++;
					}
					if (ch == '\t')
					{
						int n, n_spaces;

						SET_CHAR(i, j, ' ');
						n_spaces = TAB_STOP(j);
						for (n = 0; n < n_spaces; n++)
						{
							SET_CHAR(i, j, ' ');
						}
					}
					else
					{
						SET_CHAR(i, j, ch);
					}
				}
				else if (graphics)		/* translate graphics */
				{
					/* continue; */
					switch(ch)
					{
						case 'q':
							{
								SET_CHAR(i, j, '-');
							}
							break;
						case 'x':
							{
								SET_CHAR(i, j, '|');
							}
							break;
						case 'j':
						case 'k':
						case 'l':
						case 'm':
							{
								SET_CHAR(i, j, '+');
							}
							break;
					}
				}
				/* else eat it */
				break;
		}
	}
	for (i = 0; i < 24; i++)
	{
		for (j = 0; j < 80; j++)
		{
			fputc(buf[i][j], fp2);
		}
		fputc('\n', fp2);
	}
}
TAB_STOP(pos)
int pos;
{
	if (pos < 9)
		return (8 - pos);
	if (pos < 17)
		return (16 - pos);
	if (pos < 25)
		return (24 - pos);
	if (pos < 33)
		return (32 - pos);
	if (pos < 41)
		return (40 - pos);
	if (pos < 49)
		return (48 - pos);
	if (pos < 57)
		return (56 - pos);
	if (pos < 65)
		return (64 - pos);
	if (pos < 73)
		return (72 - pos);
	if (pos < 80)
		return (79 - pos);
	return(0);
}
main(argc, argv)
int argc;
char *argv[];
{
	decap(stdin, stdout);
}

/* STRLEN() - on Linux, STRLEN(NULL) causes a core dump. Wrap function to
 * to check for this case before doing real STRLEN()
 */
int STRLEN(char *buf)
{     
	if (buf == NULL)       
		return(0);         
	else                   
		return(strlen(buf));
}                          

/* STRCPY() - on Linux, STRCPY(NULL) causes a core dump. Wrap function to
 * to check for this case before doing real STRLEN()
 */
extern char *STRCPY(), *STRNCPY();

char *STRCPY(char *dest, char *src)
{     
	extern char *strcpy();
	if (dest == NULL)       
		return( (char *) "");         
	else                   
	{
		if (src == NULL)
		{
			*dest = '\0';
			return( (char *) "");         
		}
		return(strcpy(dest, src));
	}
}                          
/* STRNCPY() - on Linux, STRNCPY(NULL) causes a core dump. Wrap function to
 * to check for this case before doing real STRLEN()
 */
char *STRNCPY(char *dest, char *src, int n)
{     
	extern char* strncpy();
	if (dest == NULL)       
		return( (char *) "");         
	else                   
	{
		if (src == NULL)
		{
			*dest = '\0';
			return( (char *) "");         
		}
		return(strncpy(dest, src, n));
	}
}                          
/* STRNCMP() - on Linux, STRNCMP(NULL) causes a core dump. Wrap function to
 * to check for this case before doing real STRLEN()
 */
int STRNCMP(char *str1, char *str2, int n)
{     
	if (str1 == NULL)       
		return(-1);
	else                   
	{
		if (str2 == NULL)
		{
			return(1);
		}
		return(strncmp(str1, str2, n));
	}
}                          
/* STRCMP() - on Linux, STRCMP(NULL) causes a core dump. Wrap function to
 * to check for this case before doing real STRLEN()
 */
int STRCMP(char *str1, char *str2)
{     
	if (str1 == NULL)       
		return(-1);
	else                   
	{
		if (str2 == NULL)
		{
			return(1);
		}
		return(strcmp(str1, str2));
	}
}                          
/* MEMCPY() - on Linux, MEMCPY(NULL) causes a core dump. Wrap function to
 * to check for this case before doing real STRLEN()
 */
char *MEMCPY(char *dest, char *src, int n)
{     
	extern char *memcpy();
	if (dest == NULL)       
		return( (char *) "");         
	else                   
	{
		if (src == NULL)
		{
			*dest = '\0';
			return( (char *) "");         
		}
		return(memcpy(dest, src, n));
	}
}                          
