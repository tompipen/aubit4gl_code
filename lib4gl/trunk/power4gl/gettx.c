/******************************************************************************\ 
 General text retrieval by file name and key text.

 Text tables are loaded into memory upon first access by means of linked lists.
 One list contains header information for each table that has been accessed.
 For each of these tables a separate list exists containing the key and data
 text pairs. During retrieval the proper table is found in the header list. If
 it is not present it is loaded in from the corresponding text file. The text
 is then found in the data list by matching the key text.
 
 Copyright (C) 2001 John H. Frantz, Pétur K. Hilmarsson.
 
 This file is part of Power-4gl.
 
 Power-4gl is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or   
 (at your option) any later version.
 
 Power-4gl is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with Power-4gl; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
\******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAXLEN 500
#define TABLEN 24
#define DIRLEN 100
#define KEYLEN 24

typedef struct linklist
  {
  char *key;
  char *data;
  struct linklist *next;
  } ITEM;
typedef ITEM *LINK;
typedef struct linkhead
  {
  char *table;
  int count;
  LINK first;
  struct linkhead *next;
  } HEAD;
typedef HEAD *HLINK;

/******************************************************************************\
 Fatal error handling. Message displayed and program terminated.
 Parameters: Error message.
\******************************************************************************/

static void ferr(msg)

char *msg;
{
fprintf(stderr,"%s",msg);
exit(1);
}

/******************************************************************************\
 Table initialization. Text file copied to new working list.
 Parameters: Name of text file, key field length.
 Return: Pointer to list header.
\******************************************************************************/

static HLINK loadtable(table,keylen)

char *table;
register int keylen;
{
FILE *fp, *fopen();
char s[MAXLEN + 1];
register int i;
register HLINK hlink;
register LINK link;

hlink = NULL;
if ((fp = fopen(table,"r")) != NULL)
  {
  if (keylen < 0) keylen = 0;
  if (keylen > MAXLEN) keylen = MAXLEN;
  while ((fgets(s,MAXLEN,fp)) != NULL)
    {
    if ((i = strlen(s)) > keylen)
      {
      if (s[i - 1] == '\n') s[i - 1] = '\0';
      if (hlink == NULL)
        {
        hlink = (HLINK) malloc (sizeof(HEAD));
        hlink->table = malloc(strlen(table) + 1);
        strcpy(hlink->table,table);
        hlink->count = 0;
        hlink->first = NULL;
        hlink->next = NULL;
        }
      link = hlink->first;
      hlink->first = (LINK) malloc(sizeof(ITEM));
      hlink->first->key = malloc(keylen + 1);
      strncpy(hlink->first->key,s,keylen);
      hlink->first->key[keylen] = '\0';
      hlink->first->data = malloc(strlen(s) - keylen + 1);
      strcpy(hlink->first->data,&(s[keylen]));
      hlink->first->next = link;
      hlink->count++;
      }
    }
  fclose(fp);
  }
return(hlink);
}

/******************************************************************************\
 Text retrieval with 4gl parameter interface (entry point).
 Parameters: Table name and key text.
 Return: data text ("\0" if not found).
\******************************************************************************/

char *gettxt(tab,key)

char *tab,*key;
{
char *e,*data = "\0";
static HLINK firsthlink = NULL;
static char dir[DIRLEN + 1] = "\0";
static int firstaccess = FALSE;
char table[DIRLEN + TABLEN + 1];
register HLINK hlink = NULL;
register LINK link;

if (!firstaccess)
  {
  if ((e = getenv("SYSTEMDIR")) != NULL)
    {
    strncat(dir,e,DIRLEN - 1);
    if (dir[strlen(dir) - 1] != '/') strcat(dir,"/");
    }
  firstaccess = TRUE;
  }
strcpy(table,dir);
strcat(table,tab);
if (firsthlink == NULL) firsthlink = loadtable(table,strlen(key));
if (firsthlink != NULL)
  {
  hlink = firsthlink;
  while (strcmp(hlink->table,table) != 0)
    {
    if (hlink->next == NULL)
      {
      if ((hlink->next = loadtable(table,strlen(key))) == NULL)
        {
        hlink = NULL;
        break;
        }
      }
    hlink = hlink->next;
    }
  }
if (hlink != NULL)
  {
  link = hlink->first;
  while (link != NULL)
    {
    if (strcmp(link->key,key) == 0)
      {
      data = link->data;
      break;
      }
    link = link->next;
    }
  }
return(data);
}

/******************************************************************************\
 4gl interface for text retrieval (4gl entry point).
 4gl Parameters: Table name and key text.
 4gl Return: Data text ("\0" if not found).
\******************************************************************************/

int gettx(nargs)

int nargs;
{
char table[TABLEN + 1], key[KEYLEN + 1];
register int i;

if (nargs != 2) ferr("gettx: wrong number of arguments.");
popquote(key,KEYLEN + 1);
popquote(table,TABLEN + 1);
for (i = KEYLEN - 1;i >= 0; i--)
  {
  if (key[i] == ' ') key[i] = '\0';
  else break;
  }
for (i = TABLEN - 1;i >= 0; i--)
  {
  if (table[i] == ' ') table[i] = '\0';
  else break;
  }
retquote (gettxt(table,key));
return (1);
}
/*
main() {printf("%s",gettxt("zstx.4gl","menu      |"));}
*/
