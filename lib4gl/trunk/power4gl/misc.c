/******************************************************************************\
 Miscelaneous general purpose functions.
 
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

#include <unistd.h>
#include <sys/times.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <pwd.h>

#define FGL_BUFSIZE 2064
#define MAXARGSIZE 512

/******************************************************************************\
 Return the processor time value.
\******************************************************************************/

aclfgl_putime(nargs)
  int nargs;
{
struct tms t;
long i;

i = times(&t);
i = sysconf(_SC_CLK_TCK);
i = ((t.tms_utime+t.tms_stime+t.tms_cutime+t.tms_cstime) * 100) / i;
retlong(i);
return(1);
}

/******************************************************************************\
 Return the process id number.
\******************************************************************************/

aclfgl_processid(nargs)
  int nargs;
{
retlong(getpid());
return(1);
}

/******************************************************************************\
 Return the effective user id.
\******************************************************************************/

aclfgl_serid(nargs)
  int nargs;
{
retquote(getpwuid(geteuid())->pw_name);
return(1);
}

/******************************************************************************\
 Random password generator function
\******************************************************************************/
#define PASSLEN 8
 
char *alpha[] = {
 "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","x","y","z"
,"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","X","Y","Z" 
};
 
char *num[] = {"0","1","2","3","4","5","6","7","8","9"};


#define ARR_CH  ((sizeof alpha)/sizeof(char *))
#define ARR_NM  ((sizeof num)/sizeof(char *))

long sday, smin, ssec;
char npasswd[PASSLEN+2];


rnd_pass()
{
        int i, rnd_ch, rnd_nm, stime;
        long sys_time;

        sys_time=time(0);
        ssec=(localtime(&sys_time)->tm_sec);
        smin=(localtime(&sys_time)->tm_min);
        sday=(localtime(&sys_time)->tm_mday);
	stime=(unsigned)(getpid()+(sday*(smin*(1+(2/3)))*(ssec*(1+(2/3))))*10);
        srandom(stime);

        strcpy(npasswd, (char *)NULL);

        for(i=0; i<PASSLEN; ++i)
        {
                rnd_ch=rnd(ARR_CH);
                rnd_nm=rnd(ARR_NM);

                if (rnd_ch > rnd_nm)
                {
                        strcat(npasswd, alpha[rnd_ch]);
                } else {
                        strcat(npasswd, num[rnd_nm]);
                }
        }
retquote(npasswd);
return 1;
}

int rnd(n)
int n;
{
        return((random() & 0x7FFF) % n);
}

/******************************************************************************\
 Clear messages.
\******************************************************************************/

aclfgl_fgl_clrmsg(nargs)
int nargs;
{
/* clrmsg();  TODO : How to implement?   */
return(0);
}

/******************************************************************************\
 Return an integer code for a keyboard key.
\******************************************************************************/

/*extern short eflastkey;

aclfgl_getkey(nargs)
int nargs;
{
extern short _acckey;
short keyhit;

eflastkey = ((keyhit = rgetkey()) == _acckey) ? 2016 : keyhit;
clrmsg();
retlong((long) eflastkey);
return(1);
}*/

/******************************************************************************\
 Print whatever is on the screen (including windows).
\******************************************************************************/

#define bool char
#define CHAR long
#define _ATTRIBUTE (0x007f0000)
#define _CHARACTER (0x000000ff)
#define _GRAPHMODE (0x00800000)

typedef struct window {
  short _cury, _curx;
  short _maxy, _maxx;
  short _begy, _begx;
  short _flags;
  bool _clear;
  bool _leave;
  bool _scroll;
  CHAR **_y;
  short *_firstch;
  short *_lastch;
  short _attr;
} WINDOW;

typedef struct _efwindow {
  struct _efwindow *upper, *lower;
  int *win;
  int *swin;
  char *formname;
  int *winfrm;
  short rows, columns;
  short promptline;
  short msgline;
  short formline;
  short cmtline;
  short flag;
  short forecolor;
  unsigned long ucount;
} _EFwindow;

/**** Use Internal Aubit function

extern _EFwindow *topwin, *botwin, *_Wscreen;
extern WINDOW *_efbigwin;
extern char *GB;

aclfgl_fgl_prtscr(nargs)
int nargs;
{
register FILE  *fp;
register _EFwindow *scr;
register WINDOW *win;
register CHAR **line, *data;
register int y, x;
register char c;
int len;
char *getenv(), *dbprint;
char setupstr[65];

dbprint = NULL;
setupstr[0] = '\0';
if (nargs >= 2) {
  popint(&len);
  if (len > 0) {
    dbprint = malloc(len+1);
    popquote(dbprint,len+1);
  }
  if (nargs >= 3) {
    popquote(setupstr,sizeof(setupstr)-1);
  }
}
if (dbprint == NULL)
  if ((dbprint = getenv("DBPRINT")) == NULL) dbprint = "lp -s";
if (topwin == _Wscreen)
  # the user is looking at the "screen" 
  win = (WINDOW * ) _Wscreen->win;
else {
  #  the user is looking at the one or more "windows" 
  win = _efbigwin;
  for (scr = botwin; scr != (_EFwindow * )0; 
  scr = (_EFwindow * )scr->upper) {
    overwrite((WINDOW * ) scr->win, win);
  }
}
if ((fp = popen(dbprint, "w")) != (FILE * )0) {
  for (y=0; y<strlen(setupstr); y++) {
    c = (char) setupstr[y];
    (void)fputc(c, fp);
  }
  (void)fputc('\n', fp);
  for (y = 0, line = win->_y; y < win->_maxy; y++, line++) {
    for (x = 0, data = *line; x < win->_maxx; x++, data++) {
      c = (char) *data & _CHARACTER;
      if ((*data & _GRAPHMODE) && *GB) {
        if (c == GB[0]) c = '·';
        else if (c == GB[1]) c = '·';
        else if (c == GB[2]) c = '·';
        else if (c == GB[3]) c = '·';
        else if (c == GB[4]) c = '-';
        else if (c == GB[5]) c = '|';
      }
      (void)fputc(c, fp);
    }
    (void)fputc('\n', fp);
  }
  (void)pclose(fp);
}
return 0;
}

*/

aclfgl_fgl_prtscr(nargs)
int nargs;
{
aclfgl_aclfgl_dump_screen(nargs);
return 0;
}
/******************************************************************************\
 Open a text file.
\******************************************************************************/

aclfgl_fgl_fopen(nargs)
int nargs;
{
char filename[80];
char mode[10];
FILE *ascfile;
if (nargs != 2)  {
  fprintf (stderr,"fgl_fopen: wrong number of arguments\n");
  exit(1);
}
popquote(mode,sizeof(mode)-1);
popquote(filename,sizeof(filename)-1);
clipped(mode);
clipped(filename);
ascfile = fopen(filename,mode);
retlong((long)ascfile);   
return 1;  
}

/******************************************************************************\
 Read a line from a text file.
\******************************************************************************/

aclfgl_fgl_fgets(nargs)
int nargs;
{
long filehandle;
char buffer[FGL_BUFSIZE];
short err_code = 0;
int len;
if (nargs != 1)  {
  fprintf(stderr,"fgl_fgets: wrong number of arguments\n");
  exit(1);
}
poplong(&filehandle);
memset(buffer,0,sizeof(buffer));
if (fgets(buffer,sizeof(buffer)-1,(FILE *)filehandle) != NULL)  {
  len = strlen(buffer);
  buffer[len-1] = '\0';
}
else {
  err_code = -1;
}
retshort(err_code);
retquote(buffer);
return 2;
}

/******************************************************************************\
 Write a fixed length string to a text file.
\******************************************************************************/

aclfgl_fgl_fputs(nargs)
int nargs;
{
long filehandle;
char buffer[FGL_BUFSIZE];
short err_code=0;
short len;
if (nargs != 3)  {
  fprintf (stderr,"fgl_fputs: wrong number of arguments\n");
  exit(1);
}
poplong(&filehandle);
popshort(&len);
popquote(buffer,len+1);
err_code = fputs(buffer,(FILE *)filehandle);
retshort(err_code);
return 1;
}

/******************************************************************************\
 Write a line to a text file (with cr and clipped).
\******************************************************************************/

aclfgl_fgl_fputl(nargs)
int nargs;
{
long filehandle;
char buffer[FGL_BUFSIZE];
short err_code=0;
if (nargs != 2)  {
  fprintf (stderr,"fgl_fputl: wrong number of arguments\n");
  exit(1);
}
poplong(&filehandle);
popquote(buffer,sizeof(buffer)-1);
clipped(buffer,(char)' ');     
err_code = fputs(buffer,(FILE *)filehandle);
fputc('\n',(FILE *)filehandle);
retshort(err_code);
return 1;
}

/******************************************************************************\
 Close a text file.
\******************************************************************************/

aclfgl_fgl_fclose(nargs)
int nargs;
{
long filehandle;
if (nargs != 1)  {
  fprintf(stderr,"fgl_fclose: wrong number of arguments\n");
  exit(1);
}
poplong(&filehandle);               
fclose((FILE *)filehandle);
return 0;
}

/******************************************************************************\
 Clip a string (internal routine used in fgl i/o functions).
\******************************************************************************/

clipped(str)
char *str;
{
char *blank;
blank = str + strlen(str) - 1;
while (*blank == ' ')  {
  *blank-- = '\0';
}
}

/******************************************************************************\
 Find the maximum value of a set of integers.
\******************************************************************************/

aclfgl_fgl_maxints(nargs)
int nargs;
{
int i;
long test_val;
long max_val = -2147483647;
for (i=0;i<nargs; i++)  {
  poplong(&test_val);
  if (test_val > max_val) max_val = test_val;
}
retlong(max_val);
return 1;
}

/******************************************************************************\
 Compare two 4gl records for any differences.
 Returns the number of the field that differs or 0 if the records are the same.
 Nulls compare equal and trailing spaces are not significant.
 Aliases of the function exist for multiple use within a 4gl module
 using different numbers of record fields.
\******************************************************************************/

aclfgl_fgl_recdiff1(nargs) int nargs; {return (aclfgl_fgl_recdiff(nargs));}
aclfgl_fgl_recdiff2(nargs) int nargs; {return (aclfgl_fgl_recdiff(nargs));}
aclfgl_fgl_recdiff3(nargs) int nargs; {return (aclfgl_fgl_recdiff(nargs));}
aclfgl_fgl_recdiff4(nargs) int nargs; {return (aclfgl_fgl_recdiff(nargs));}
aclfgl_fgl_recdiff5(nargs) int nargs; {return (aclfgl_fgl_recdiff(nargs));}
aclfgl_fgl_recdiff6(nargs) int nargs; {return (aclfgl_fgl_recdiff(nargs));}
aclfgl_fgl_recdiff7(nargs) int nargs; {return (aclfgl_fgl_recdiff(nargs));}
aclfgl_fgl_recdiff8(nargs) int nargs; {return (aclfgl_fgl_recdiff(nargs));}
aclfgl_fgl_recdiff9(nargs) int nargs; {return (aclfgl_fgl_recdiff(nargs));}
aclfgl_fgl_recdiff(nargs)
int nargs;
{
char* *argvec;
int i;
if ((nargs <= 0) || ((nargs % 2) != 0)) {
  fprintf (stderr,"fgl_recdiff: wrong number of arguments\n");
  exit(1);
}
if ((argvec = (char**) malloc(nargs * sizeof(char**))) == 0) {
  fprintf (stderr,"fgl_recdiff: not enough initial memory\n");
  exit(1);
}
for (i = nargs-1; i >= 0; --i) {
  char buff[MAXARGSIZE+1];
  char *p;
  popquote(buff, sizeof(buff));
  if (*buff == 0) {
    argvec[i] = "";
    continue;
  }
  /* trim trailing spaces */
  for (p = buff + (sizeof(buff)-2); p >= buff && *p == ' '; --p);
  *(p+1) = 0;
  if ((argvec[i] = strdup(buff)) == 0) {
    fprintf (stderr,"fgl_recdiff: not enough memory\n");
    exit(1);
  }
}
for (nargs /= 2, i = 0; i < nargs; ++i) {
  if (strcmp(argvec[i], argvec[i+nargs]) != 0)
  break;
}
retint((i == nargs) ? 0 : ++i);		/* adjust from origin 0 to origin 1 */
for (nargs *= 2, i = 0; i < nargs; ++i) {
  if (*argvec[i] != 0)
  free(argvec[i]);
}
free((char*)argvec);
return(1);
}

/******************************************************************************\
 Swap the contents of two 4gl records.
 Aliases of the function exist for multiple use within a 4gl module
 using different numbers of record fields.
\******************************************************************************/

aclfgl_fgl_recswap1(nargs) int nargs; {return (aclfgl_fgl_recswap(nargs));}
aclfgl_fgl_recswap2(nargs) int nargs; {return (aclfgl_fgl_recswap(nargs));}
aclfgl_fgl_recswap3(nargs) int nargs; {return (aclfgl_fgl_recswap(nargs));}
aclfgl_fgl_recswap4(nargs) int nargs; {return (aclfgl_fgl_recswap(nargs));}
aclfgl_fgl_recswap5(nargs) int nargs; {return (aclfgl_fgl_recswap(nargs));}
aclfgl_fgl_recswap6(nargs) int nargs; {return (aclfgl_fgl_recswap(nargs));}
aclfgl_fgl_recswap7(nargs) int nargs; {return (aclfgl_fgl_recswap(nargs));}
aclfgl_fgl_recswap8(nargs) int nargs; {return (aclfgl_fgl_recswap(nargs));}
aclfgl_fgl_recswap9(nargs) int nargs; {return (aclfgl_fgl_recswap(nargs));}
aclfgl_fgl_recswap(nargs)
int nargs;
{
char **argvec;
char buff[MAXARGSIZE+1];
int i;
if ((nargs <= 0) || ((nargs % 2) != 0)) {
  fprintf (stderr,"fgl_recswap: wrong number of arguments\n");
  exit(1);
}
if ((argvec = (char**) malloc(nargs * sizeof(char**))) == 0) {
  fprintf (stderr,"fgl_recswap: not enough initial memory\n");
  exit(1);
}
for (i = nargs-1; i >= 0; --i) {
  popquote(buff, sizeof(buff));
  if (*buff == 0) {
    argvec[i] = "";
    continue;
  }
  if ((argvec[i] = strdup(buff)) == 0) {
    fprintf (stderr,"fgl_recswap: not enough memory\n");
    exit(1);
  }
}
for (i = nargs / 2; i < nargs; ++i) {
  retquote(argvec[i]);
  if (*argvec[i] != 0) free(argvec[i]);
}
for (i = 0; i < nargs / 2; ++i) {
  retquote(argvec[i]);
  if (*argvec[i] != 0) free(argvec[i]);
}
free((char*)argvec);
return(nargs);
}

/******************************************************************************\
 Replace occurences of a pattern in a string with another pattern.
\******************************************************************************/

aclfgl_fgl_strrep(nargs)
int nargs;
{
char s1[2000];		/* Input string. */
char p1[200];		/* Pattern which will be found and replaced. */
char p2[200];		/* Pattern which will replace the found pattern. */
char s2[2000];		/* Resulting string. */
char *c1;		/* Current position in input string. */
char *c2;		/* Current position in resulting string. */
char *x1;		/* Newest occurance of pattern in input string. */
short i;
popquote(p2,sizeof(p2)-1);
popquote(p1,sizeof(p1)-1);
popquote(s1,sizeof(s1)-1);
/* Trim trailing spaces. */
for (i = strlen(s1) - 1; i >= 0; i--) if (s1[i] != ' ') break;
s1[i + 1] = '\0';
for (i = strlen(p1) - 1; i >= 0; i--) if (p1[i] != ' ') break;
p1[i + 1] = '\0';
for (i = strlen(p2) - 1; i >= 0; i--) if (p2[i] != ' ') break;
p2[i + 1] = '\0';
s2[0] = '\0';
/* Find and replace pattern. */
c1 = s1;
c2 = s2;
if (strlen(p1) > 0) while ((x1 = strstr(c1,p1)) != NULL) {
  if ((i = x1 - c1) >= 2000 - strlen(s2)) i = 2000 - strlen(s2) - 1;
  c2 = strncpy(c2,c1,i);
  c2 = c2 + i;
  if (strlen(p2) >= 2000 - strlen(s2)) p2[2000 - strlen(s2) - 1] = '\0';
  c2 = strcpy(c2,p2);
  c1 = x1 + strlen(p1);
  c2 = c2 + strlen(p2);
  c2[0] = '\0';
}
if (strlen(c1) >= 2000 - strlen(s2)) c1[2000 - strlen(s2) - 1] = '\0';
c2 = strcpy(c2,c1);
retquote(s2);
return 1;
}

/******************************************************************************\
 Find position of first occurence of a pattern in a string.
\******************************************************************************/

aclfgl_fgl_strpos(nargs)
int nargs;
{
char s1[1000];		/* Input string. */
char p1[100];		/* Pattern which will be found. */
char *x1;		/* Occurance of pattern in input string. */
short i;		/* Relative position of found pattern */
popquote(p1,sizeof(p1)-1);
popquote(s1,sizeof(s1)-1);
/* Trim trailing spaces. */
for (i = strlen(s1) - 1; i >= 0; i--) if (s1[i] != ' ') break;
s1[i + 1] = '\0';
for (i = strlen(p1) - 1; i >= 0; i--) if (p1[i] != ' ') break;
p1[i + 1] = '\0';
/* Find pattern. */
i = 0;
if ((strlen(p1) > 0) && ((x1 = strstr(s1,p1)) != NULL)) i = x1 - s1 + 1;
retshort(i);
return 1;
}

