#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "a4gl_incl_4glhdr.h"

void free_directory(void) ;
int compare_str(const void *vs1,const void *vs2) ;
char **scan_directory(char *spec) ;


char **m_names=0;

int compare_str(const void *vs1,const void *vs2) {
char *s1;
char *s2;
	s1=*(char **)vs1;
	s2=*(char **)vs2;
	return strcmp(s1,s2);
}



#ifdef TEST

/* to compile standalone.. */
main() {
int a;
	scan_directory(".","$AUBITDIR/?.sql");
	for (a=0;m_names[a];a++) printf("%s\n",m_names[a]);
	free_directory();
}
#endif




char **scan_directory(char *spec) {
DIR *dirp;
char **names=0;
char *name;
int cnt=0;
char buff[255];
char *left;
char *right="";
char *dir;
char spec2[255];
//char buff2[255];
struct dirent *direntp;
A4GL_trim(spec);
if (strncmp(spec,"$AUBITDIR",9)==0) {
	strcpy(spec2,acl_getenv("AUBITDIR"));
	strcat(spec2,&spec[9]);
} else {
	strcpy(spec2,spec);
}

dir=spec2;
left=strrchr(spec2,'/');
if (left) {
	*left=0;
	left++;
right=strrchr(left,'?');
if (right) {
	*right=0;
	right++;
}
}

A4GL_debug("DIR: Loading directory %s",dir);
	dirp = opendir(dir);


	if (dirp==0) {m_names=0; return 0;}

   /***************************************************************************
   * readdir() returns either a pointer to a structure containing directory
   * entry, or it returns a NULL to indicate that all the entries for the
   * corresponding opendir() directory have already been seen.
   ***************************************************************************/
   while ( (direntp = readdir( dirp )) != 0 )
   {
        name=direntp->d_name;

A4GL_debug("DIR: checking %s for left",name);
	if (strncmp(name,left,strlen(left))!=0)  continue;
A4GL_debug("DIR: checking %s for right (%s=%s)",name,&name[strlen(name)-strlen(right)],right);
	if (strncmp(&name[strlen(name)-strlen(right)],right,strlen(right))!=0)  continue;
	strcpy(buff,&name[strlen(left)]);
	buff[strlen(buff)-strlen(right)]=0;
A4GL_debug("DIR: Looks good... %s",buff);
	cnt++;
	names=realloc(names,sizeof(char *)*(cnt+1));
	A4GL_debug("DIR : %s",buff);
	names[cnt-1]=strdup(buff);
      /************************************************************************
      * Here we are examining one of the components of the directory entry's
      * structure.  I put {brackets} around the file name to show exactly
      * what portion of the output is the file name from the structure.
      ************************************************************************/
   }
   
   closedir( dirp );
   qsort(names, cnt, sizeof(char *),compare_str);
   cnt++;
   names=realloc(names,sizeof(char *)*cnt);
   names[cnt-1]=0;
   m_names=names;

   return names;
}


void free_directory() {
int a;
if (m_names==0) return;
for (a=0;m_names[a];a++) free(m_names[a]);
free(m_names);
}
