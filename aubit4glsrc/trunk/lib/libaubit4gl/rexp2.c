/*
# +----------------------------------------------------------------------+
# | Aubit 4gl Language Compiler Version $.0                              |
# +----------------------------------------------------------------------+
# | Copyright (c) 2000-1 Aubit Development Team (See Credits file)       |
# +----------------------------------------------------------------------+
# | This program is free software; you can redistribute it and/or modify |
# | it under the terms of one of the following licenses:                 |
# |                                                                      |
# |  A) the GNU General Public License as published by the Free Software |
# |     Foundation; either version 2 of the License, or (at your option) |
# |     any later version.                                               |
# |                                                                      |
# |  B) the Aubit License as published by the Aubit Development Team and |
# |     included in the distribution in the file: LICENSE                |
# |                                                                      |
# | This program is distributed in the hope that it will be useful,      |
# | but WITHOUT ANY WARRANTY; without even the implied warranty of       |
# | MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the        |
# | GNU General Public License for more details.                         |
# |                                                                      |
# | You should have received a copy of both licenses referred to here.   |
# | If you did not, or have any questions about Aubit licensing, please  |
# | contact afalout@ihug.co.nz                                           |
# +----------------------------------------------------------------------+
#
# $Id: rexp2.c,v 1.5 2002-05-20 11:41:12 afalout Exp $
#
*/

/**
 * @file
 *
 * @todo Add Doxygen comments to file
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 * @todo Doxygen comments to add to functions
 */


/*
=====================================================================
                    Constants definitions
=====================================================================
*/

//#define size_t long
#define  EQ 1
#define  LEQ 2
#define  NEQ 3
#define  GEQ 4
#define  LTHN 5
#define  GTHN 6
#define  BIGG 7
#define  LST 8
#define  OR 8
#define  RANGE 10
/*
#define CONSTR_SEP '\t'
#define like(s1,s2) mja_match(s1,s2,'L');
#define matches(s1,s2) mja_match(s1,s2,'M');
*/

#define is_match_decimal "[\\+\\-]{0,1}[0-9]{0,}\\.[0-9]{0,}"
#define is_match_integer  "[\\+\\-]{0,1}[0-9]{1,}"

#define MATCH_LITERAL  5    /* match failure on literal match */
#define MATCH_RANGE    4    /* match failure on [..] construct */
#define MATCH_ABORT    3    /* premature end of text string */
#define MATCH_END      2    /* premature end of pattern string */
#define MATCH_VALID    1    /* valid match */

/* pattern defines */
#define PATTERN_VALID  0    /* valid pattern */
#define PATTERN_ESC   -1    /* literal escape at end of pattern */
#define PATTERN_RANGE -2    /* malformed range in [..] construct */
#define PATTERN_CLOSE -3    /* no end bracket in [..] construct */
#define PATTERN_EMPTY -4    /* [..] construct is empty */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#include <stdlib.h> //atoi()
#include <string.h> //strlen()

//#ifdef WIN32
#ifdef __CYGWIN__
	#include "regex2.h"
#else
	#include "regex.h"
#endif

#include "a4gl_match.h"
#include "a4gl_debug.h"
#include "a4gl_aubit_lib.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

char    *constr_bits[256];
int     constr_size;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/


char *construct(char *colname, char *val, int inc_quotes);
void doconstruct(char *s,char *whereclause);
int mja_matchcmp(char *a,char *s_match);
static int isop(char *str, int i);
static void convert_constr_buffer(char *str);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/


/**
 *
 *
 * @return
 */
static void
appendchr(char *s, char c)
{
        int     a;
        a = strlen(s);
        if (c=='\'') appendchr(s,'\\');
        s[a] = c;
        s[a+1] = 0;

}


/**
 *
 *
 * @return
 */
int
mja_match(char *str1, char*str2, int likeormatch)
{
//char    tmp_str[80];
//regex_t *a;
//int 	newcursor;
//int     b;
//int     z;
char    MULTICHAR, SINGLECHAR;

		int error;
		trim(str1);
		trim(str2);
		#ifdef DEBUG
		/* {DEBUG} */ {        debug("Match '%s' '%s' %c",str1,str2,likeormatch);
		}
		#endif

        if (likeormatch == 'L') {
                MULTICHAR = '%';
                SINGLECHAR = '.';
        } else
        {
                MULTICHAR = '*';
                SINGLECHAR = '?';
        }

		error = matche(str2,str1);
		if (error==MATCH_VALID) return 1;
		else return 0;
}


/**
 *
 *
 * @return
 */
char *
construct(char *colname, char *val, int inc_quotes)
{
char    *ptr2;
int     a;
char    quote[2] = "";
static char     buffer[512];
static char     buff2[512];
static char     buff3[512];
int     z;
int     z2;
int     cnt;
int     k, k2=0;
char    lastchar;
int ismatch;

		trim(val);
        ptr2 = val;
        strcpy(buff3,"");
		#ifdef DEBUG
			{debug("Colname = %s , val = %s incq=%d\n",colname,val,inc_quotes);}
		#endif
        if (strcmp(val, "") == 0) return buff3;

        constr_size = 0;
        constr_bits[constr_size++] = buffer;

        if (inc_quotes) strcpy(quote, "'");

        /* Clear buffer */
        strcpy(buffer, "");
        lastchar = -1;
        z = -1;
        ismatch=0;
        for (a = 0; a < strlen(ptr2); a++) {
                if (ptr2[a]=='['||ptr2[a]=='*'||ptr2[a]=='?') ismatch=1;
                lastchar = z;
                z = isop(ptr2, a);
                if (z > 0 && lastchar == 0) { /* last character was not a control */
                        appendchr(buffer, '\n');
                        constr_bits[constr_size++] = &buffer[strlen(buffer)];
                        appendchr(buffer, ptr2[a]);
                        /*constr_bits[constr_size++]=&ptr2[a];*/
                        /*constr_bits[constr_size++]=&buffer[strlen(buffer)-1];*/
                } else if (z == 0 && lastchar > 0) { /* last character was a control  
                                                                                                                                                                                                          but this one isnt */
                        appendchr(buffer, '\n');
                        constr_bits[constr_size++] = &buffer[strlen(buffer)];
                        appendchr(buffer, ptr2[a]);
                        /*constr_bits[constr_size++]=&buffer[strlen(buffer)-1];*/
                } else if (z > 0 && lastchar > 0) {
                        if (lastchar<OR&&z==EQ) {
                                appendchr(buffer, ptr2[a]);
                        } else 
                        {
                                appendchr(buffer, '\n');
                                constr_bits[constr_size++] = &buffer[strlen(buffer)];
                                appendchr(buffer, ptr2[a]);
                        }
                } else
                        appendchr(buffer, ptr2[a]);
                lastchar = z;
        }
        convert_constr_buffer(buffer);
        if (!inc_quotes) {
                for (z = 0; z < constr_size; z++) {
                        if (isop(constr_bits[z], 0) == 0 || (z > 1 && isop(constr_bits[z], 0) != OR))
                        {

               k = atoi(constr_bits[z]);
               if (k || k2)  ;
               else {
					/* error in numeric */
                    return 0;
                    }
                        }
                }
        }
        strcpy(buff2, "");
        z = isop(constr_bits[0], 0);
        if (constr_size > 1)
                z2 = isop(constr_bits[1], 0);
        else
                z2 = 0;
        if (ismatch&&!inc_quotes) {
			#ifdef DEBUG
				{debug("Expression error");}
			#endif
                return 0;
        }
        if (z == 0 && z2 == 0) {
                if (ismatch) strcat(buff2, " matches ");
                else strcat(buff2,"=");
                strcat(buff2, quote);
                for (cnt = 0; cnt < constr_size; cnt++) {
                        strcat(buff2, constr_bits[cnt]);
                }
                sprintf(buff3, "%s%s%s", colname, buff2, quote);
        }
        if (z > 0 && z < OR) {
                strcat(buff2, constr_bits[0]);
                strcat(buff2, quote);
                for (z = 1; z < constr_size; z++) {
                        strcat(buff2, constr_bits[z]);
                }
                strcat(buff2, quote);
                if (strcmp(buff2, "=") == 0) {
                        strcpy(buff2, "is null");
                }
                if (strcmp(buff2, "!=") == 0) {
                        strcpy(buff2, "is not null");
                }
                sprintf(buff3, "%s%s", colname, buff2);
        }
        if (z == OR || (z2 == OR && z == 0)) {
                if (z == OR)  {
                        sprintf(buff3, "%s in ('',", colname);
                        for (z = 1; z < constr_size; z++) {
                                if (isop(constr_bits[z], 0) == OR)
                                        continue;
                                strcat(buff3, quote);
                                strcat(buff3, constr_bits[z]);
                                strcat(buff3, quote);
                                if (z < constr_size - 1)
                                        strcat(buff3, ",");
                        }
                        if (buff3[strlen(buff3)-1] == ',')
                                strcat(buff3, "''");
                        /*buff3[strlen(buff3)-1]=0;*/
                        strcat(buff3, ")");
                } else {
                        sprintf(buff3, "%s in (", colname);
                        for (z = 0; z < constr_size; z++) {
                                if (isop(constr_bits[z], 0) == OR)
                                        continue;
                                strcat(buff3, quote);
                                strcat(buff3, constr_bits[z]);
                                strcat(buff3, quote);
                                if (z < constr_size - 1)
                                        strcat(buff3, ",");
                        }
                        if (buff3[strlen(buff3)-1] == ',')
                                strcat(buff3, "''");
                        strcat(buff3, ")");
                }
        }
        if (z == RANGE || z2 == RANGE) {
                if (z == RANGE) {
                        sprintf(buff3, "(%s  between '' and %s", colname, quote);
                        for (z = 1; z < constr_size; z++) {
                                strcat(buff3, constr_bits[z]);
                        }
                        strcat(buff3, quote);
                } else  {
                        sprintf(buff3, "%s  between %s%s%s and ", colname, quote, constr_bits[0], quote);
                        if (constr_size >= 2) {
                                strcat(buff3, quote);
                                for (z = 2; z < constr_size; z++) {
                                        strcat(buff3, constr_bits[z]);
                                }
                                strcat(buff3, quote);
                        } else
                                strcat(buff3, "''");
                }
                strcat(buff3, "");
        }
        /*
        	for (z=0;z<constr_size;z++) 
			{
            	printf("(%s)\n",constr_bits[z]);
            }
		*/
		#ifdef DEBUG
			{debug("buff3= [ %s ]\n", buff3);}
		#endif
        return buff3;
}


/**
 *
 *
 * @return
 */
static int
isop(char *str, int i)
{
        if (i >= 2) {
                if (str[i-2] != '\\' && str[i-1] == '\\')
                        return 0;
        }
        if (i >= 1) {
                if (str[i-1] == '\\')
                        return 0;
        }
        if (str[i] == '=')
                return EQ;
        if (str[i] == '=')
                return EQ;
        if (str[i] == '<' && str[i+1] == '=')
                return LEQ;
        if (str[i] == '!' && str[i+1] == '=')
                return NEQ;
        if (str[i] == '>' && str[i+1] == '=')
                return GEQ;
        if (str[i] == '<')
                return LTHN;
        if (str[i] == '>')
                return GTHN;
        if (str[i] == '|')
                return OR;
        if (str[i] == ':')
                return RANGE;
        return 0;
}


/**
 *
 *
 * @return
 */
static void
convert_constr_buffer(char *str)
{
int     a;
int     b;
        
		b = strlen(str);
        for (a = 0; a < b; a++) 
		{
                if (str[a] == '\n')
                        str[a] = 0;
        }
}


/**
 *
 *
 * @return
 */
void
doconstruct(char *s,char *whereclause)
{
        int a;
        int t;
        char buffer[2][80];
        printf("Here 1\n");
        strcpy(whereclause,"");
        strcpy(buffer[0],"");
        strcpy(buffer[1],"");
        printf("s=%s\n",s);
        t=0;

        for (a=0;a<=strlen(s);a++) {
                if (s[a]==CONSTR_SEP||s[a]==0)  {

                        if (t==1) {
                                if (strlen(whereclause) > 0) strcat(whereclause," AND ");
                                if (buffer[0][0]=='*')
                                        strcat(whereclause,construct(&buffer[0][1],buffer[1],1));
                                else
                                        strcat(whereclause,construct(buffer[0],buffer[1],0));
                                strcpy(buffer[0],"");
                                strcpy(buffer[1],"");
                        }
                        t=!t;
                }
                else
                        appendchr(buffer[t],s[a]);
        }
        if (strlen(whereclause)==0) strcpy(whereclause,"1=1");
}


// ============================ EOF ==================================

