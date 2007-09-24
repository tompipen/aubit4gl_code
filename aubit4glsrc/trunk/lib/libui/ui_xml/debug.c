#include <stdarg.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <sys/time.h>

#include "debug.h"

static char *get_timestamp(void) {
  int mja_day;
  struct tm *local_time;
  int month, year;              /* ch, yflag; */
  static char buff[50];
  struct timeval tv1;


  gettimeofday (&tv1, 0);

  local_time = localtime (&tv1.tv_sec);
  year = local_time->tm_year + 1900;
  month = local_time->tm_mon + 1;
  mja_day = local_time->tm_mday;

/*
       0000000000111111111122222
       0123456789012345678901234
       YYYY-MM-DD hh:mm:ss.fffff
*/
  sprintf (buff, "%04d-%02d-%02d %02d:%02d:%02d.%06ld",
           year, month, mja_day, local_time->tm_hour,
           local_time->tm_min, local_time->tm_sec, tv1.tv_usec
    );

	return buff;
}



void UIdebug(int lvl, char *s,...) {
static va_list args;
FILE *dbgfile;
char buff[20000];
int a;

if (lvl>9) return;
  va_start (args, s);
  vsprintf (buff, s, args);
  for (a=0;a<strlen(buff)-2;a++)  {
	if (buff[a]=='\n') buff[a]=' ';
  }

  if (buff[strlen(buff)-1]!='\n') {
		strcat(buff,"\n");
  }
	dbgfile=fopen("proxy.log","a");
	if (dbgfile) {
  		fprintf(dbgfile, "[%s %d] %s",get_timestamp(),getpid(),buff); fflush(stdout);
		fclose(dbgfile);
	}
  /* printf( "[%s %d] %s",get_timestamp(),getpid(),buff); fflush(stdout); */
}




