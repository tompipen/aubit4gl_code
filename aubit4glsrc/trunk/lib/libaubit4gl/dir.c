
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "a4gl_libaubit4gl_int.h" 

//char **A4GL_read_directory(char *dir,char *spec) ;
//void A4GL_free_directory(void) ;



static int compare_str(const void *vs1,const void *vs2);
char **m_names=0;

static int compare_str(const void *vs1,const void *vs2) {
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
	for (a=0;m_names[a];a++) PRINTF("%s\n",m_names[a]);
	free_directory();
}
#endif




char **
A4GL_read_directory(char *dir,char *spec) {
DIR *dirp;
char **names=0;
char *name;
int cnt=0;
char buff[255];
struct dirent *direntp;
dirp = opendir( dir);
	if (dirp==0) {m_names=0; return 0;}

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
   names=realloc(names,sizeof(char *)*(cnt+1));
   names[cnt-1]=0;
   m_names=names;
   return names;
}




void A4GL_free_directory(void) {
int a;
if (m_names==0) return;
for (a=0;m_names[a];a++) free(m_names[a]);
free(m_names);
}

void A4GL_free_list(char **list) {
int a;
if (list==0) return;
for (a=0;list[a];a++) {
	free(list[a]);
	list[a]=0;
}
free(list);

}


static int isinlist(char **list,char *fname) {
int a;
if (list==0) return 0;
	for (a=0;list[a];a++) {
		if (strcmp(list[a],fname)==0) return 1;
	}
return 0;
}


       static int
       cmpstringp(const void *p1, const void *p2)
       {
           /* The arguments to this function are "pointers to
              pointers to char", but strcmp() arguments are "pointers
              to char", hence the following cast plus dereference */

           return strcmp(* (char **) p1, * (char **) p2);
       }


static char **merge_list (char **list,char **newlist) {
int a;
int nlist=0;

if (newlist==0) return list;

if (list!=0) {
	for (a=0;list[a];a++) ;
	nlist=a;
}

for (a=0;newlist[a];a++) {
	if (isinlist(list,newlist[a])) continue;
	nlist++;
A4GL_debug("Adding : %s\n",newlist[a]);
	list=realloc(list,sizeof(char *)*(nlist+1));
	list[nlist-1]=strdup(newlist[a]);
        list[nlist]=0;
}
if (list) {
	qsort(list, nlist-1, sizeof(char *), cmpstringp);
}
A4GL_free_directory();
return list;
}



/**
 * Find a full path to file in DBPATH, or current directory
 *
 * @param fname The pointer to the name of the file to searched for.
 * @return The pointer to the full path including the file name and extension
 *         to file found in DBPATH. 0 otherwise.
 */
char **
A4GL_gen_list_dbpath (char *spec, char *path)
{
  static char str_path[2048], str_path2[2048];
  int cnt, cnt2;
  char *ptr = 0;
  //char *ptr2 = 0;
  int str_len;			//, curr_str_len;
  char **list=0;

  	memset (str_path, 0, 2048);
  	memset (str_path2, 0, 2048);
        strcpy(str_path,path);
	str_len = strlen (str_path);
	ptr = str_path;

	for (cnt = 0; cnt < str_len; cnt++)  {
		#ifdef __MINGW32__
			if (str_path[cnt] == ';') {
		#else
			if (str_path[cnt] == ':') {
		#endif
		A4GL_debug ("Found separator at %d", cnt);
		str_path[cnt] = 0;
		if (strlen (ptr)) {
			//A4GL_debug ("strlen (ptr) > 0, ptr=%s",ptr);
			strcpy (str_path2, ptr);
			//A4GL_debug ("str_path2=%s",str_path2);
			// Let's assume no-one will stuff DBPATH with more then 5
			// consecutive separators... :-)
			for (cnt2 = 0; cnt2 < 5; cnt2++) {
				#ifdef __MINGW32__
					if (str_path2[cnt2] == ';') {
				#else
					if (str_path2[cnt2] == ':') {
				#endif
						A4GL_debug ("Skipping one more separator");
						ptr = &str_path2[cnt2 + 1];
					} else {
						break;
					}
				}


				list=merge_list(list,A4GL_read_directory(ptr,spec));

				cnt++;
				ptr = &str_path[cnt];

			} else {
				cnt++;
				ptr = &str_path[cnt];
			}
		}
    }

    //catch cases when DBPATH contained only one path and no separator:
    if (strlen (ptr)) {
		list=merge_list(list,A4GL_read_directory(ptr,spec));
    }

A4GL_debug("Returning %p\n",list);
    return list;
}

/* ============================= EOF =============================== */
