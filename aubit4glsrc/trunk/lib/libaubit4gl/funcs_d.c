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
# $Id: funcs_d.c,v 1.12 2002-10-22 06:43:36 afalout Exp $
#
*/

/**
 * @file
 * Some functions, like using.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/


#include "a4gl_libaubit4gl_int.h"

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

//extern int errno;

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/

int 			bname2	(char *str,char *str1,char *str2,char *str3);
void 			trim_nl	(char *p);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Another implementation of basename.
 *
 * @param str
 * @param str1
 * @param str2
 * @param str3
 */
int
bname2(char *str,char *str1,char *str2,char *str3)
{
char ss[256];
char b1[10];
char b2[10];
char b3[10];

	if (!strchr(str,'/')) {
	return 0;
	}

#ifdef DEBUG
	 {debug("%p %p %p %p",str,str1,str2,str3);}
#endif
#ifdef DEBUG
	 {debug("(1)%s %s %s",str1,str2,str3);}
#endif
	strcpy(ss,str);
#ifdef DEBUG
	 {debug("(1.1)%s %s %s",str1,str2,str3);}
#endif
#ifdef DEBUG
	 {debug("In bname2 %s");}
#endif
	trim(ss);
#ifdef DEBUG
	 {debug("(2)%s %s %s",str1,str2,str3);}
#endif
	bnamexxx(ss,b2,b3);
#ifdef DEBUG
	 {debug("(1) Splits to %s %s",b2,b3);}
#endif
#ifdef DEBUG
	 {debug("(3)%s %s %s",str1,str2,str3);}
#endif
	strcpy(ss,b2);
	bnamexxx(ss,b1,b2);
#ifdef DEBUG
	 {debug("(2) Splits to '%s' '%s'",b1,b2);}
#endif
#ifdef DEBUG
	 {debug("(4)%s %s %s",str1,str2,str3);}
#endif
#ifdef DEBUG
	 {debug("'%s' '%s' '%s'",b1,b2,b3);}
#endif
#ifdef DEBUG
	 {debug("%s %s %s",str1,str2,str3);}
#endif
	strcpy(str1,b1);
#ifdef DEBUG
	 {debug("1");}
#endif
	strcpy(str2,b2);
#ifdef DEBUG
	 {debug("1");}
#endif
	strcpy(str3,b3);
#ifdef DEBUG
	 {debug("Copied...");}
#endif
	return 1;
}


/**
 * Aubit compiler malloc.
 *
 * It was used to make some debug about memory allocations.
 * Right now just encapsulate standard C malloc.
 *
 * @param size The size in bytes to be allocated
 * @param why The reason for memory allocation
 * @param f The source file name where the memory is being alocated
 * @pram line The source file line number where memory being alocated
 * @return A pointer for the memory alocated
 */
void*
acl_malloc_full(int size,char *why,char *f,long line)
{
  void *p;
  p=malloc(size);
  return p;
}

/**
 *
 *
 * @param
 */
void
acl_free_full(void *ptr,char *f,long line)
{
  free(ptr);
}

/**
 * Trim the spaces at the rigth side of a string
 *
 * @param p The string to be trimmed.
 */
void
trim(char *p)
{
  int a;
  for (a=strlen(p)-1;a>=0;a--)
  {
    if (p[a]!=' ')  break;
    p[a]=0;
  }
}

/**
 * Trim the spaces and new lines at the rigth side of a string.
 *
 * @param p The string to be trimmed.
 */
void
trim_nl(char *p)
{
  int a;
  for (a=strlen(p)-1;a>=0;a--)
  {
    if (p[a]!=' '&&p[a]!='\n'&&p[a]!='\r')  break;
    p[a]=0;
  }
}


/**
 * Yet another implementation of basename.
 *
 * @param str
 * @param str1
 * @param str2
 */
void
bnamexxx(char *str,char *str1,char *str2)
{
static char fn[132];
	int a;
	char *ptr;

	strcpy(fn,str);
#ifdef DEBUG
	 {debug("In bnamexxx - splitting %s",str);}
#endif
	for (a=strlen(fn);a>=0;a--) {
		if (date_sep(fn[a])) {
#ifdef DEBUG
	 {debug("separator found at %d",a);}
#endif
			fn[a]=0;
			break;
		}
	}
#ifdef DEBUG
	 {debug("a=%d",a);}
#endif
	ptr=&fn[a];
#ifdef DEBUG
	 {debug("ptr=%p",ptr);}
#endif
	strcpy(str1,fn);
#ifdef DEBUG
	 {debug("Str1 now = '%s'",str1);}
#endif
	if (a>=0) strcpy(str2,ptr+1);
	else str2[0]=0;
#ifdef DEBUG
	 {debug("Str2='%s'",str2);}
#endif
}

/**
 * Pad a string with spaces until the string reaches a size.
 *
 * @param ptr A pointer to the string being padded.
 * @param The size of the string.
 */
void 
pad_string(char *ptr,int size) 
{
	int a;
	for (a=strlen(ptr);a<size;a++) {
		ptr[a]=' ';
	}
	ptr[size]=0;
}


/**
 * Convert a digit to 
 *
 * @param a
 * @param z
 * @param fmt
 * @param dtype
 * @param size
 * @param buff
 * @return Allways 1.
 */
int 
digittoc(int *a,char *z,char *fmt,int dtype,int size)    
{
	static char buff[100];
#ifdef DEBUG
	 {debug("digittoc"); }
#endif
	sprintf(buff,fmt,*a);
#ifdef DEBUG
	 {debug("digittoc: %s",buff); }
#endif
	if (strlen(buff)>size) {
		memset(z,'*',size);
		pad_string(z,size);
		return 0;

	}
#ifdef DIGIT_ALIGN_LEFT
	sprintf(buff,"%%-%d%s",size,fmt);
#else
	sprintf(buff,"%%%d%s",size,fmt);
#endif
#ifdef DEBUG
	 {debug("digittoc: buff set to %s",buff);}
#endif
	strcpy(fmt,buff);
#ifdef DEBUG
	 {debug("digittoc: returns");}
#endif
	return 1;
}

/**
 * USING 4gl statement implementation.
 *
 * @param str The string where to return the values.
 * @param s
 * @param fmt The string that contains the format pattern.
 * @param num The number to be formated.
 */
void
using(char *str,int s,char *fmt,double num)
{
int dig[MAXDIG];
int pnt[MAXPNT];
char number[65];
char fm1[64],fm2[64];
char *ptr1,*ptr;
char *ptr2;
char *p;
char canfloat_head[]="*-+($";
char rep_digit[]="*&#<-+()$";
char buff[800];
int isneg=0;
int a,b;
int isprnt=0;
double ad;

	debug("In using...");
	for (a=0;a<MAXPNT;a++) {pnt[a]=0;}
	for (a=0;a<MAXDIG;a++) {dig[a]=0;}

	ptr1=&number[0];
	ptr2=&number[32];

	if (num<0) {
	    isneg=1;
	    num=0.0-num;
	}

#if defined (__MINGW32__)
	if (strchr(fmt,'.')) {
#else
	if (index(fmt,'.')) {
#endif
	    strcpy(fm1,fmt);
#if defined (__MINGW32__)
		p=(char *)strchr(fm1,'.');
#else
		p=(char *)index(fm1,'.');
#endif
	    p[0]=0;
#if defined (__MINGW32__)
		strcpy(fm2,strchr(fmt,'.')+1);
#else
		strcpy(fm2,index(fmt,'.')+1);
#endif
	}
	else {
	  strcpy(fm1,fmt);
	  strcpy(fm2,"");
	}
	ad=0.5;
	trim(fm2);

	for (a=1;a<=strlen(fm2);a++) {
	   ad=ad/10;
	}
	num+=ad;
	sprintf(number,"%64.32f",num);
	number[31]=0;
	debug("Number=%s",number);
	debug("Format=%s",fmt);
	strcpy(str,fmt);
	b=30;
	isprnt=1;

	for (a=strlen(fm1)-1;a>=0;a--) 
	{
    if (strchr(rep_digit,fm1[a])) {
          if (((ptr1[b]=='0'&&ptr1[b-1]==' ')||ptr1[b]==' ')&&isprnt==1) isprnt=0;
          str[a]=ptr1[b--];
          if (!isprnt) {
              if (fm1[a]=='#') {str[a]=' ';continue;}
              if (fm1[a]=='*') {str[a]='*';continue;}
              if (fm1[a]=='&') {str[a]='0';continue;}
              if (fm1[a]=='<') {str[a]='<';continue;}
              p=strchr(canfloat_head,fm1[a]);
              if (p) {
                      p[0]=1;
                      if (fm1[a]=='+'&&isneg) {str[a]='-';continue;}
                      if (fm1[a]=='+'&&!isneg) {str[a]='+';continue;}
                      if (fm1[a]=='-'&&isneg) {str[a]='-';continue;}
                      if (fm1[a]=='(') {
                            if (isneg) {str[a]='(';continue;}
                            else {str[a]=' ';continue;}
                      }
                      if (fm1[a]==')'&&isneg) {str[a]=')';continue;}
                      str[a]=fm1[a];continue;
              }
              else {str[a]=' ';continue;}
              str[a]=fm1[a]; 
          } 
    }
    else 
	{
          if (isprnt) {
              str[a]=fm1[a];
          }
          else
          {
            if (fm1[a]==',') {str[a]=' ';continue;}
            str[a]=fm1[a];

          }
         }
	}
	b=0;

	for (a=0;a<strlen(fm2);a++) 
	{
	    if (strchr(rep_digit,fm2[a])) 
		{
	    	if (fm2[a]==')')
			{
	        	if (isneg) 
				{
					str[a+strlen(fm1)+1]=')';continue;
				}
		        else
				{
					str[a+strlen(fm1)+1]=' ';continue;
				}
			}

        	str[a+strlen(fm1)+1]=ptr2[b++];
		}
    	else
		{
    		str[a+strlen(fm1)+1]=fm2[a];
		}
	}
#if defined (__MINGW32__)
	ptr=(char *)strrchr(str,'<');
#else
	ptr=(char *)rindex(str,'<');
#endif
	if (ptr) 
	{
	   b=0;
	   for (a=0;a<strlen(str);a++) 
	   {
	    if (str[a]=='<') continue;
	    buff[b++]=str[a];
	   }
	   buff[b]=0;
	   strcpy(str,buff);
	}
	debug("str=%s",str);
}

/* ============================== EOF ========================== */

