/* XML application for triggers.dtd.
 * Includes actions from triggers_act.act.
 * Generated 2008/09/15 12:50:19.
 *
 * This program was generated with the FleXML XML processor generator.
 * FleXML is Copyright (C) 1999-2005 Kristoffer Rose.  All rights reserved.
 * FleXML is Copyright (C) 2003-2006 Martin Quinson.  All rights reserved.
 * (Id: flexml.pl,v 1.61 2006/09/13 16:34:33 wdowling Exp).
 * 
 * There are two, intertwined parts to this program, part A and part B.
 *
 * Part A
 * ------
 * 
 * Some parts, here collectively called "Part A", are found in the 
 * FleXML package.  They are Copyright (C) 1999-2005 Kristoffer Rose
 * and Copyright (C) 2003-2006 Martin Quinson. All rights reserved.
 *
 * You can redistribute, use, perform, display and/or modify "Part A"
 * provided the following two conditions hold:
 *
 * 1. The program is distributed WITHOUT ANY WARRANTY from the author of
 *    FleXML; without even the implied warranty of MERCHANTABILITY or
 *    FITNESS FOR A PARTICULAR PURPOSE.
 *
 * 2. The program distribution conditions do not in any way affect the
 *    distribution conditions of the FleXML system used to generate this
 *    file or any version of FleXML derived from that system.
 *
 * Notice that these are explicit rights granted to you for files
 * generated by the FleXML system.  For your rights in connection with
 * the FleXML system itself please consult the GNU General Public License.
 * 
 * Part B
 * ------
 * 
 * The other parts, here collectively called "Part B", and which came 
 * from the DTD used by FleXML to generate this program, can be 
 * distributed (or not, as the case may be) under the terms of whoever
 * wrote them, provided these terms respect and obey the two conditions 
 * above under the heading "Part A".
 *
 * The author of and contributors to FleXML specifically disclaim
 * any copyright interest in "Part B", unless "Part B" was written 
 * by the author of or contributors to FleXML.
 * 
 */

#include "triggers.h"


#line 3 "triggers_act.act"



#include <stdio.h>                  
#include <stdlib.h>                  
#include <string.h>
#include "attr.h"
static char *inbuff=0;
char *myinputptr;
int myinputlim;

static struct s_attr lexed_attr;
static struct s_syncvalues sync;

struct s_attr *xml_parse(char *s) {
	int rval;
        inbuff=s;
        myinputlim=strlen(s);
        myinputptr=inbuff;
        memset(&lexed_attr,0, sizeof(struct s_attr));

	if (strlen(s)< 1000) {
        	UIdebug(3,"INPUT = %s\n",s);
	}

        rval=xml_yylex(); 
	if (rval==0) {
                return &lexed_attr;
        } else {
                printf("X2 - yylex failed (%s) rval=%d\n",s,rval);
                return &lexed_attr;
        }
}

int my_yyinput(char *buf,int maxsize) {
int n=attr_min(maxsize,myinputlim);
if (n>0) {
        memcpy(buf,myinputptr,n);
        myinputptr+=n;
        myinputlim-=n;
        }
return n;
}




void STag_TRIGGERED(void)
{
#line 51 "triggers_act.act"

	 
	{
		sync.vals=0;
		sync.nvalues=0;
		lexed_attr.id=0;
		lexed_attr.data=0;
		lexed_attr.type=0;
		lexed_attr.scrline=0;
		lexed_attr.arrline=0;
		lexed_attr.arrcount=0;
		lexed_attr.lastkey=0;
		lexed_attr.lastcursor=0;
		lexed_attr.infield=0;
                lexed_attr.filelen=-1;
                lexed_attr.fileid=0;
                lexed_attr.programname=0;

		if (A_TRIGGERED_ID) lexed_attr.id=strdup(A_TRIGGERED_ID); 
		if (A_TRIGGERED_TYPE) lexed_attr.type=strdup(A_TRIGGERED_TYPE); 
		if (A_TRIGGERED_DATA) lexed_attr.data=strdup(A_TRIGGERED_DATA); 
		if (A_TRIGGERED_SCRLINE) lexed_attr.scrline=atoi(A_TRIGGERED_SCRLINE); 
		if (A_TRIGGERED_ARRLINE) lexed_attr.arrline=atoi(A_TRIGGERED_ARRLINE); 
		if (A_TRIGGERED_ARRCOUNT) lexed_attr.arrcount=atoi(A_TRIGGERED_ARRCOUNT); 
		if (A_TRIGGERED_LASTKEY) lexed_attr.lastkey=strdup(A_TRIGGERED_LASTKEY); 
		if (A_TRIGGERED_LASTCURSOR) lexed_attr.lastcursor=atol(A_TRIGGERED_LASTCURSOR); 
		if (A_TRIGGERED_INFIELD) lexed_attr.infield=strdup(A_TRIGGERED_INFIELD); 
		if (A_TRIGGERED_FILEID) lexed_attr.fileid=strdup(A_TRIGGERED_FILEID);
		if (A_TRIGGERED_PROGRAMNAME) lexed_attr.programname=strdup(A_TRIGGERED_PROGRAMNAME);
                if (A_TRIGGERED_FILELEN) lexed_attr.filelen=atoi(A_TRIGGERED_FILELEN);

		
	}
	

} /* STag_TRIGGERED */

void ETag_TRIGGERED(void)
{
#line 86 "triggers_act.act"

	 
	{
		/* dump_attr(&lexed_attr); */
	}
	

} /* ETag_TRIGGERED */

void STag_SYNCVALUES(void)
{
#line 94 "triggers_act.act"

	 
	{
		/* Just to be sure these are cleared down... */
		if (sync.vals) {
			int a;
			for (a=0;a<sync.nvalues;a++) {
				if (sync.vals[a].value) 	free(sync.vals[a].value);
				if (sync.vals[a].fieldname) 	free(sync.vals[a].fieldname);
			}
			free(sync.vals);
		}
                sync.nvalues=0;
                sync.vals=0;
	}
	

} /* STag_SYNCVALUES */

void ETag_SYNCVALUES(void)
{
#line 112 "triggers_act.act"

	 
	{
		memcpy(&lexed_attr.sync,&sync,sizeof(sync));
	}
	

} /* ETag_SYNCVALUES */

void ETag_SYNCVALUE(void)
{
#line 120 "triggers_act.act"

	 
	{
		sync.nvalues++;
		sync.vals=realloc(sync.vals, sizeof(struct s_syncvalue)*sync.nvalues) ;
                //if (lexed_attr.fileid && lexed_attr.filelen)  {
                        //char *ptr;
                        //sync.vals[sync.nvalues-1].value=malloc(lexed_attr.filelen);
                        //ptr=pcdata;
//
                        //memcpy(sync.vals[sync.nvalues-1].value,ptr, lexed_attr.filelen);
                //} else {
                        sync.vals[sync.nvalues-1].value=strdup(pcdata);
                //}

                if (A_SYNCVALUE_FIELDTYPE) {
                        sync.vals[sync.nvalues-1].fieldtype=atoi(A_SYNCVALUE_FIELDTYPE);
                } else {
                        sync.vals[sync.nvalues-1].fieldtype=-1;
                }

		sync.vals[sync.nvalues-1].fieldname=strdup(A_SYNCVALUE_FIELDNAME);

	}
	

} /* ETag_SYNCVALUE */

void STag_SYNCROWS(void)
{
#line 147 "triggers_act.act"

	 
	{
	if (lexed_attr.rows.row) {
		/* free_rows(lexed_attr.rows.row); */
	}
	lexed_attr.rows.nrows=0;
	lexed_attr.rows.row=0;
	}
	

} /* STag_SYNCROWS */

void STag_ROW(void)
{
#line 158 "triggers_act.act"

	 
	{
		lexed_attr.rows.nrows++;
		lexed_attr.rows.row=realloc(lexed_attr.rows.row,sizeof(struct s_row)* lexed_attr.rows.nrows);
		lexed_attr.rows.row[lexed_attr.rows.nrows-1].rownum=atoi(A_ROW_SUBSCRIPT);
		lexed_attr.rows.row[lexed_attr.rows.nrows-1].sync.nvalues=0;
		lexed_attr.rows.row[lexed_attr.rows.nrows-1].sync.vals=0;
	}
	

} /* STag_ROW */

void ETag_ROW(void)
{
#line 170 "triggers_act.act"

	 
	{
		int a;
		lexed_attr.rows.row[lexed_attr.rows.nrows-1].sync.nvalues=sync.nvalues;
		lexed_attr.rows.row[lexed_attr.rows.nrows-1].sync.vals=malloc(sizeof(struct s_syncvalue)*sync.nvalues);
		for (a=0;a<sync.nvalues;a++) {
			lexed_attr.rows.row[lexed_attr.rows.nrows-1].sync.vals[a].value=strdup(sync.vals[a].value);
			lexed_attr.rows.row[lexed_attr.rows.nrows-1].sync.vals[a].fieldtype=sync.vals[a].fieldtype;
			lexed_attr.rows.row[lexed_attr.rows.nrows-1].sync.vals[a].fieldname=strdup(sync.vals[a].fieldname);
		}
	}
	

} /* ETag_ROW */


#line 184 "triggers_act.act"


/* XML application entry points. */
void ETag_SYNCROWS(void) {}
void STag_SYNCVALUE(void) {}
