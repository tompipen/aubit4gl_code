/********************************************************
 *
 * Program to act as a decompiler
 *	for Informix  .iem files
 * 2003-3-26 John O'Gorman john.ogorman@zombie.co.nz
 *
 * Reads a .iem file of the form:
 *
 * FE68 			;Informix .iem file magic no
 * 0002 			;Count No of messages
 * 0001 000A 0000 0014		;Index rec 1: msgno=1, len=10, offset (4 bytes)
 * 0002 000A 0000 0020
 * ...
 * message 1\0
 * message 2\0
 * ...
 *
 * and produces the original .msg file:
 * .1
 * message 1
 * .2
 * message 2


 *Comments
 *
 *TODO
 *	1. Check arithmetic for offset calculation     *Done
 *	2. I have no idea if this works on MS systems
 ********************************************************/  
  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>                   /* strcpy() */

#define HELPMAXLEN 78
  
/*******  Function Prototypes ********************/ 

void mychkerr (FILE * f, char *s);


/**************************************************/ 

static char progname[128];	//use this to pass argv[0] to functions

int 
main (int argc, char *argv[]) 
{
  
FILE * infile, *infile2, *outfile;
  
char *s;
  
char line[HELPMAXLEN];
  
char header[4];		//2 bytes magic FE68, 2 bytes msgcount
  char indexrec[8];		//2 bytes msgno, 2 bytes len, 4 bytes offset
  int offset;			//offset to message (perhaps s.b size_t )
  int charcount;
  

int msgno = 0;
  
int len = 0;			//count of (possibly multiline) message chars
  int count = 0;		//full count of messages found
  
int i;			// loop counter of course!
  
if (argc < 2)
    
    {
      
fprintf (stderr, "Usage: %s iemfile > msgfile\n", argv[0]);
      
fprintf (stderr, "\t or: %s iemfile msgfile\n", argv[0]);
      
exit (1);
    
}
  
strcpy (progname, argv[0]);
  
infile = fopen (argv[1], "rb");
  mychkerr (infile, argv[1]);
  
infile2 = fopen (argv[1], "rb");
  mychkerr (infile, argv[1]);
  
if (argc >= 3)
    
    {
      
outfile = fopen (argv[2], "w+");
      mychkerr (outfile, argv[2]);
    
}
  
  else
    
    {
      
outfile = stdout;
    
}
  

if (fread (header, 1, 4, infile) < 4)
    
    {
      
mychkerr (infile, argv[1]);
    
}
  

if (header[0] != '\xFE' || header[1] != '\x68')
    
    {
      
fprintf (stderr, "%s:%s:Bad magic. Should be 0xFE68\n", 
progname,
		argv[1]);
      
exit (1);
    
}
  

count = header[2] * 256 + header[3];
  
    //fprintf(stderr, "msgcount = %d\n", count);
    
for (i = 0; i < count; i++)
    
    {
      
if (fread (indexrec, 1, 8, infile) < 8)
	
	{
	  
mychkerr (infile, argv[1]);
	
}
      
msgno = indexrec[0] * 256 + indexrec[1];
      
len = indexrec[2] * 256 + indexrec[3];
      
offset = indexrec[4] * 16777216	// 256 ^ 3
	+ indexrec[5] * 65536	// 256 ^ 2
	+ indexrec[6] * 256 
 +indexrec[7];
      
	/*
	   fprintf(stderr, "Message No %d len=%d offset = %08X\n", 
	   msgno, len, offset);
	 */ 
	fseek (infile2, offset, SEEK_SET);
      
mychkerr (infile2, argv[1]);
      

fprintf (outfile, ".%d\n", msgno);
      
mychkerr (outfile, argv[2]);
      
charcount = 0;
      
while (charcount < len)
	
	{
	  
s = fgets (line, HELPMAXLEN, infile2);
	  
mychkerr (infile2, argv[1]);
	  
charcount += strlen (s);
	  
fprintf (outfile, line);
	
}
    
}
  

fclose (outfile);
  
fclose (infile);
  
return (0);

}



/******************************************************
 *
 *	checks file stream for error and bombs with message s
 *	if necessary
 *	This saves us obscuring every file i/o with error handling
 */ 
void 
mychkerr (FILE * f, char *s) 
{
  
int e;
  
char errmsg[HELPMAXLEN];
  

sprintf (errmsg, "%s:%5s\n", progname, s);
  
if (f <= 0)
    
    {
      
perror (errmsg);
      
exit (3);
    
}
  
if ((e = ferror (f)) < 0)
    
    {
      
perror (errmsg);
      
exit (3);
    
}

}


