/*
  Title	      : infmx_tidy.c
  Author      : Paul Redman
  Date        : 12th Sept 1995
  Description : Informix code beautifier

  Copyright (c) 1995 - Paul Redman - 75052.1341@compuserve.com

===========================================================================
 This program is freely given away to be used and modified as required. It
 is not perfect so if you find bugs or enhance it why not send me a copy at
 the above email address. The only restriction on modification is that you
 leave the copyright line above and this comment in the source code.

 No warranties implied. It does not break or remove source code, contains no
 deliberate bugs and hopefully will prove useful....BUT on no account can you
 sue me if it doesn't work or causes you problems.

 You should be able to compile it with : cc -o infmx_tidy infmx_tidy.c
 You can run it with                   : infmx_tidy <origfile> <newfile>
===========================================================================


Indents code, does not do upshift.
Pathch 2 NOT applied!

*/

#include <stdio.h>
#include <fcntl.h>

#define     ERR_FATAL      0x01
#define     ERR_NONFATAL   0x02
#define     BUFSIZE        256

void process();
void errfunc();
void doline();
void copy_line();


static char errbuf[255];


/*-----------------------------------------------------------------------
  main - entry function
  RETURNS: Nothing
-----------------------------------------------------------------------*/
int main(argc, argv)
int argc;
char *argv[];
{
	
    if (argc != 3)
    {
        sprintf(errbuf, "Usage:   infmx_tidy <infile> <outfile>");
        errfunc(ERR_FATAL, errbuf);
    }

    /* call main routine */
    process(argv[1], argv[2]);

    #ifdef DEBUG
		/* say goodbye */
	    printf("\n\n\n\n (c) Copyright 1995 - Paul Redman ");
	    printf("\n Thankyou for using infmx_tidy\n\n");
	    fflush(stdout);
    #endif


    return(0);
}

/*-----------------------------------------------------------------------
  errfunc - error routine
  RETURNS: Nothing
-----------------------------------------------------------------------*/
void errfunc(errtype, buf)
int errtype;
char *buf;
{
    fprintf(stderr, "\n\n%s\n\n", buf);
    fflush(stderr);
    if (errtype == ERR_FATAL)
        exit(1);
}

/*-----------------------------------------------------------------------
  process - main routine
  RETURNS: Nothing
-----------------------------------------------------------------------*/
void process(infile, outfile)
char *infile;
char *outfile;
{
    FILE            *ifp, 
                    *ofp, 
                    *fopen();
    char            *ibuf, 
                    *obuf; 
    int             cnt;


    ifp = fopen(infile, "r");
    if (ifp == (FILE *) NULL)
    {
        sprintf(errbuf,"Input file %s could not be opened for reading", infile);
        errfunc(ERR_FATAL, errbuf);
    }

    ofp = fopen(outfile, "w");
    if (ofp == (FILE *) NULL)
    {
        sprintf(errbuf, "Output file %s could not be opened for writing", outfile);
        errfunc(ERR_FATAL, errbuf);
    }

    ibuf = (char *) malloc(BUFSIZE * sizeof(char));
    if (ibuf == (char *) NULL)
    {
        fclose(ofp);
        fclose(ifp);
        errfunc(ERR_FATAL, "Out of memory allcating inbuf variable");
    }
    memset(ibuf, 0x00, BUFSIZE);

    obuf = (char *) malloc(BUFSIZE * sizeof(char));
    if (obuf == (char *) NULL)
    {
        fclose(ofp);
        fclose(ifp);
        errfunc(ERR_FATAL, "Out of memory allcating outbuf variable");
    }
    memset(obuf, 0x00, BUFSIZE);


    for (cnt = 0; feof(ifp) == 0; cnt++)
    {
	    fgets(ibuf, (BUFSIZE - 1), ifp);
        if (feof(ifp))
            break;

        doline(ibuf, obuf);
        fprintf(ofp, "%s", obuf);
        fflush(ofp);
    }

    fflush(ofp);
    fclose(ofp);
    fclose(ifp);

    free(obuf);
    free(ibuf);
}
        

/*-----------------------------------------------------------------------
  doline - process 1 line between in and out buffers
  RETURNS: Nothing
-----------------------------------------------------------------------*/
void doline(ibuf, obuf)
char *ibuf;                         /* main input buffer */
char *obuf;                         /* main output buffer */
{
    char       *ip, *op;            /* ptrs to main buffers */
    int        n;                   /* temp variable (loops) */
    char       c;                   /* temp variable */
    char       *p;                  /* temp ptr variable */
    char       *token;              /* buffer to hold first token in the line */
    char       *tok;                /* ptr to token buffer */
    static int curly_set = 0;       /* set after a {, reset on a } */
    static int spaces = 0;          /* no. of spaces to indent output buffer */
    static int line_no = 0;         /* Count of lines processed */

    ip = ibuf;
    op = obuf;

    line_no++;

    /* copy blank lines as is */
    for (; *ip == ' ' || *ip == '\t' || *ip == '\n' ; ip++);
    if (*ip == '\0')
    {
        ip = ibuf;
        copy_line(ip,op);
        return;
    }


    /* Check for end of a multi line comment - note we reject the whole line
       when we find a } so we cannot process chars after the } */
    if (curly_set)
    {
        if (close_curly(ip))
            curly_set = 0;

        /* copy whole line if part of a comment OR end of a comment */
        copy_line(ip, op); 
        return;
    }

    /* Check for a single line comment - if found kick out the identical line */
    if (is_a_hash(ip))
    {
        ip = ibuf;
        copy_line(ip, op);
        return;
    }


    /* Check for a multi line comment - if found kick out all lines between
       curly brackets 'as is' by setting curly flag  */
    if (is_a_curly(ip))
    {
        curly_set = 1;

        /* Check if comment is closed on same line */
        if (close_curly(ip))
            curly_set = 0;
        ip = ibuf;
        copy_line(ip, op);
        return;
    }


    /* Not a comment - must be a real line */


    /* strip leading spaces */
    if (*ip == ' ' || *ip == '\t')
        for (; *ip == ' ' || *ip == '\t'; ip++);

    /* store this address for use further down */
    p = ip;

    /* build first token in the inbuf */
    token = (char *) malloc(BUFSIZE * sizeof(char));
    memset(token, 0x00, BUFSIZE);
    tok = token;
    for(; *ip != ' ' && *ip != '\t' && *ip != '\n' && *ip != '\0'; ip++)
        *tok++ = toupper(*ip);
    *tok = '\0';


    /* No. of spaces are adjusted before outptting the current line if it 
       contains statements like END IF, ELSE, END WHILE etc. */
    spaces = calc_before_spaces(spaces, token, ibuf);

	#ifdef DEBUG
	    printf("\nLine No. %05d, Token=|%s|, spaces=%d", line_no, token, spaces);
    	fflush(stdout);
    #endif


    /* if token is "LABEL xx" ignore spaces (labels always go on 1st char) else
       output no. of spaces to outbuf (decided by previous token) */

    //if (strcmp(token, "LABEL", 5) != 0)
    if (strcmp(token, "LABEL") != 0)
        for (n=0; n < spaces; n++)
            *op++ = ' ';

    /* default routine to copy whole line as is */
    ip = p;
    while ((c = *ip++) != '\0')
        *op++ = c;
    *op='\0';

    /* calculate number of spaces for next line using this token. This affects
       IF, WHEN, MAIN, FUNCTION, DEFINE etc. keywords that push the next line
       forward 4 chars */
    spaces = calc_after_spaces(spaces, token, ibuf);
    free(token);
}
    
/*-----------------------------------------------------------------------
  copy_line - copy an entire line 'as is'
  RETURNS: Nothing
-----------------------------------------------------------------------*/
void copy_line(ip, op)
char *ip, *op;
{
    while (*ip != '\0')
        *op++ = *ip++;
    *op='\0';
}

/*-----------------------------------------------------------------------
  is_a_hash - looks for a single line comment 
  RETURNS: 0 if not a comment, 1 if is a comment
-----------------------------------------------------------------------*/
int is_a_hash(ip)
char *ip;
{
    if (*ip == '#' )
        return(1);
 
    for (; *ip == ' ' || *ip == '\t'; ip++);

    if (*ip == '#' )
        return(1);
    else
        return(0);
}

/*-----------------------------------------------------------------------
  is_a_curly - looks for a multi line comment 
  RETURNS: 0 if not a comment, 1 if is a comment
-----------------------------------------------------------------------*/
int is_a_curly(ip)
char *ip;
{
    if (*ip == '{')
        return(1);
 
    for (; *ip == ' ' || *ip == '\t'; ip++);

    if (*ip == '{')
        return(1);
    else
        return(0);
}

/*-----------------------------------------------------------------------
  close_curly - look for the } character       
  RETURNS: 0 if not found, 1 if found
-----------------------------------------------------------------------*/
int close_curly(ip)
char *ip;
{
    while (*ip != '}' && *ip != '\0')
        *ip++;

    return( (*ip) ? 1 : 0);
}

/*-----------------------------------------------------------------------
  calc_after_spaces - calculate number of spaces based on token and how
                      it affects the next line
  RETURNS: no. of spaces to indent next line 
-----------------------------------------------------------------------*/
int calc_after_spaces(spaces, tok, ibuf)
int   spaces;
char  *tok;       /* first token in input buffer */
char  *ibuf;      /* original input buffer */
{
    if (strncmp(tok, "MAIN", 4) == 0)
        spaces += 4;


    /* the problem with indenting after a DEFINE is that I don't know when to
       un-indent again. Note we have the same problem with the OPTION stmt. */
    /*    if (strncmp(tok, "DEFINE", 6) == 0)
        spaces += 4;
    */

    if (strncmp(tok, "IF", 2) == 0)
        if (no_endif(ibuf))
            spaces += 4;

    if (strncmp(tok, "ELSE", 4) == 0)
        spaces += 4;

    if (strncmp(tok, "CASE", 4) == 0)
        spaces += 4;

    /* don't let WHEN and WHENEVER get mixed up */
    if (strlen(tok) == 4 && strncmp(tok, "WHEN", 4) == 0)
        spaces += 4;

    if (strncmp(tok, "FOR", 3) == 0)
        spaces += 4;

    if (strncmp(tok, "FUNCTION", 8) == 0)
        spaces += 4;

    if (strncmp(tok, "WHILE", 5) == 0)
        spaces += 4;

    return ((spaces >= 0) ? spaces : 0);
}
/*-----------------------------------------------------------------------
  calc_before_spaces - calculate number of spaces based on token for 
                       current line
  RETURNS: no. of spaces to indent next line 
-----------------------------------------------------------------------*/
int calc_before_spaces(spaces, tok, ibuf)
int   spaces;
char  *tok;       /* first token in input buffer */
char  *ibuf;      /* original input buffer */
{
    if (strncmp(tok, "ELSE", 2) == 0)
        spaces -= 4;

    if (strncmp(tok, "END", 3) == 0)
        spaces -= 4;

    if (strncmp(tok, "MAIN", 4) == 0)
        spaces = 0;

    if (strncmp(tok, "FUNCTION", 8) == 0)
        spaces = 0;

    if (strncmp(tok, "RECORD", 6) == 0)
        spaces = 0;

    /* don't let WHEN and WHENEVER get mixed up */
    if (strlen(tok) == 4 && strncmp(tok, "WHEN", 4) == 0)
        spaces -= 4;

    return ((spaces >= 0) ? spaces : 0);
}

/*-----------------------------------------------------------------------
  no_endif - checks for presence of END IF on this line
  RETURNS: TRUE (=1) if END IF does not exist, else FALSE (=0)
-----------------------------------------------------------------------*/
int no_endif(ibuf)
char  *ibuf;      /* original input buffer */
{
    char *token, *tok, *ip;
    int rc = 1;

    ip = ibuf;

    /* build first token in the inbuf */
    token = (char *) malloc(BUFSIZE * sizeof(char));

    while (1)
    {
        memset(token, 0x00, BUFSIZE);
        tok = token;
 
        /* remove whitespace */
        for (; *ip == ' ' || *ip == '\t';)
            ip++;

        for(; *ip != ' ' && *ip != '\t' && *ip != '\n' && *ip != '\0'; ip++)
            *tok++ = toupper(*ip);
        *tok = '\0';

        /* note - tok would stop on '\n' so now value *ip = '\O' */
        if (*ip == '\n' || *ip == '\0')
            break;

        if (strncmp(token, "END", 3) == 0)
        {

            memset(token, 0x00, BUFSIZE);
            tok = token;

            /* remove whitespace */
            for (; *ip == ' ' || *ip == '\t';)
                ip++;

            for(; *ip != ' ' && *ip != '\t' && *ip != '\n' && *ip != '\0'; ip++)
                *tok++ = toupper(*ip);
            *tok = '\0';

            if (strncmp(token, "IF", 2) == 0)
            {
                rc = 0;
                break;
            }
        }

    } /* end while(1) */

    return(rc);
}
