/******************************************************************************
* (c) 1997-1998 Aubit Computing Ltd.
*
* $Id: map.c,v 1.1.1.1 2001-08-20 02:35:33 afalout Exp $
*
* Project : Part Of Aubit 4GL Library Functions
*
* Change History :
*	$Log: not supported by cvs2svn $
*	Revision 1.3  2001/06/12 03:37:15  afalout
*	make install, make clean
*	
*	Revision 1.2  2000/09/28 02:08:44  afalout
*	*** empty log message ***
*	
*	Revision 1.1.1.1  2000/01/29 03:11:43  cvs
*	Initial import of compiler sources using jCVS client
*	
*	Revision 1.2  1998/08/11 20:23:54  fglcomp
*	Added header
*
*
*******************************************************************************/
#include <stdio.h>
#include "../../lib/libincl/debug.h"
static FILE *mapfile=0;

openmap(char *s) {
char buff[256];
debug("openmap...");
if (strcmp(acl_getenv("MAP4GL"),"Y")==0) {
debug("Opening map file..%s \n",acl_getenv("MAP4GL"));
debug("Yep...\n");
sprintf(buff,"%s.map",s);
mapfile=fopen(buff,"w");

if (mapfile==0) {
	debug("Unable to open map file");
	printf("Unable to open map file\n");
	exit(1);
	}
debug("Mapfile=%p",mapfile);
}
}

addmap(char t,char *s,char *w,int l,char *m) {
  debug("Adding to map... %p",mapfile);
  if (mapfile) fprintf(mapfile,"%c|%s|%s|%d|%s|\n", t,s,w,l,m);
}

closemap()
{
if (mapfile) fclose(mapfile);
} 


