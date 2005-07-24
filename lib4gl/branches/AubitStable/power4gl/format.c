/******************************************************************************\ 
 String formatting.
 
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
#include <ctype.h>

#define MAX_STR_LEN 81
#define MAX_STRINGS 20

format(nargs)
short nargs;
{
    char FormStr[MAX_STR_LEN],*CleanStr,LeadingSpaces[MAX_STR_LEN];
    char Value[MAX_STRINGS][MAX_STR_LEN],Format[MAX_STRINGS][MAX_STR_LEN];
    char OutputString[256];
    size_t Len;
    unsigned long CharCount,ItemCount,ThisCount,Diff;
    unsigned long i,j;
    int StLen;

/* Following are all possible types to be formatted */
    short          ShortValue;
    long           LongValue;
    unsigned short UnsignedShortValue;
    unsigned long  UnsignedLongValue;
    double         DoubleValue;
    char           CharValue;
    char           StringValue[MAX_STR_LEN];
/* End of possible values to be formattaed */

  *OutputString = '\0';

/* Pop all possible strings from the argument stack */
  for (i=nargs; i>1; i--)
  {
    popquote(Value[i-2],MAX_STR_LEN);
    /* Remove trailing blanks */
    ThisCount = strlen(Value[i-2]);
    while ((ThisCount > 0) && (Value[i-2][ThisCount-1]==' '))
    {
      Value[i-2][ThisCount-1] = '\0';
      ThisCount--;
    }
  }
  popquote(FormStr,MAX_STR_LEN);
  /* Remove trailing blanks */
  ThisCount = strlen(FormStr);
  while ((ThisCount > 0) && (FormStr[ThisCount-1]==' '))
  {
    FormStr[ThisCount-1] = '\0';
    ThisCount--;
  }


/* Clean it until a '%' delimiter is reached */
  CleanStr = strchr(FormStr,'%');
  if (CleanStr==NULL)
  {
    printf("Error in format string, no delimiters found...\n");
    retquote(OutputString);
    return(1);
  }
  Len = strlen(CleanStr);
  Diff = strlen(FormStr) - Len;
/* printf("Diff: %d\n",Diff); */
  for (i=0; i<Diff; i++) LeadingSpaces[i] = ' ';
  LeadingSpaces[i] = '\0';
  CharCount = 0;
  ItemCount = 0;

/* Split the format string into individual format strings */
  while ((CharCount < Len) && (ItemCount < MAX_STRINGS))
  {
    ThisCount = 0;
    Format[ItemCount][ThisCount] = CleanStr[CharCount];
    CharCount++;
    ThisCount++;
    while ((CleanStr[CharCount] != '%') && (CharCount < Len))
    {
      Format[ItemCount][ThisCount] = CleanStr[CharCount];
      CharCount++;
      ThisCount++;
    }
    Format[ItemCount][ThisCount] = '\0';
    ItemCount++;
  }
/* printf("LeadingSpaces 1: |%s|\n",LeadingSpaces); */
/* printf("Format[0] 1: |%s|\n",Format[0]); */
  if (Diff > 0)
  {
    strcat(LeadingSpaces,Format[0]);
/* printf("LeadingSpaces 2: |%s|\n",LeadingSpaces); */
    strcpy(Format[0],LeadingSpaces);
  }
/* printf("Format[0] 2: |%s|\n",Format[0]); */
/* Splitting finished, goahead and interpret each format string */
  for (i=0; i<ItemCount; i++)
  {
    ThisCount = 1;
    while ((!isalpha(Format[i][ThisCount])) && (ThisCount < strlen(Format[i])))
      ThisCount++;
    switch (tolower(Format[i][ThisCount]))
    {
      case 'f':
        DoubleValue = atof(Value[i]);
        sprintf(Value[i],Format[i],DoubleValue);
        break;
      case 'e':
        DoubleValue = atof(Value[i]);
        sprintf(Value[i],Format[i],DoubleValue);
        break;
      case 'd':
        ShortValue = atoi(Value[i]);
        sprintf(Value[i],Format[i],ShortValue);
        break;
      case 'o':
        ShortValue = atoi(Value[i]);
        sprintf(Value[i],Format[i],ShortValue);
        break;
      case 'x':
        ShortValue = atoi(Value[i]);
        sprintf(Value[i],Format[i],ShortValue);
        break;
      case 'u':
        UnsignedShortValue = atoi(Value[i]);
        sprintf(Value[i],Format[i],UnsignedShortValue);
        break;
      case 's':
        strcpy(StringValue,Value[i]);
        sprintf(Value[i],Format[i],StringValue);
        break;
      case 'l':  /* Long values */
        if (ThisCount < strlen(Format[i])) ThisCount++;
        switch (tolower(Format[i][ThisCount]))
        {
          case 'd':
            LongValue = atol(Value[i]);
            sprintf(Value[i],Format[i],LongValue);
            break;
          case 'o':
            LongValue = atol(Value[i]);
            sprintf(Value[i],Format[i],LongValue);
            break;
          case 'x':
            LongValue = atol(Value[i]);
            sprintf(Value[i],Format[i],LongValue);
            break;
          case 'u':
            UnsignedLongValue = atol(Value[i]);
            sprintf(Value[i],Format[i],UnsignedLongValue);
            break;
          default:
            printf("Invalid character following a long identifier...\n");
            retquote(OutputString);
            return(1);
        }
        break;
/*
      default:
        printf("Invalid character following a delimiter...\n");
        retquote(OutputString);
        return(1);
*/
    }
    strcat(OutputString,Value[i]);
  }
  retquote(OutputString);
  return(1);
}
