
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

char **read_directory(char *dir,char *spec) ;
void free_directory() ;


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
	read_directory(".",".sql");
	for (a=0;m_names[a];a++) printf("%s\n",m_names[a]);
	free_directory();
}
#endif




char **read_directory(char *dir,char *spec) {
DIR *dirp;
char **names=0;
char *name;
int cnt=0;
char buff[255];
struct dirent *direntp;
dirp = opendir( dir);
	if (dirp==0) {m_names=0; return;}

   /***************************************************************************
   * readdir() returns either a pointer to a structure containing directory
   * entry, or it returns a NULL to indicate that all the entries for the
   * corresponding opendir() directory have already been seen.
   ***************************************************************************/
   while ( (direntp = readdir( dirp )) != 0 )
   {
        name=direntp->d_name;
	if (!strstr(name,spec)) continue;
	strcpy(buff,&name[strlen(name)-strlen(spec)]);
	if (strcmp(buff,spec)!=0) continue;
	strcpy(buff,name);
	buff[strlen(name)-strlen(spec)]=0;
	
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
