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
# $Id: amkmessage.c,v 1.10 2004-05-17 15:48:08 mikeaubury Exp $
#*/  
  
/**
 * @file
 * message help file compiler, Informix 4gl style formated.
 *
 * Compile a message file (.msg), and generates a help compiled file
 * for use in Aubit 4gl programs
 *
 * Program to act as a drop in replacement
 *	for Informix  mkmessage
 * 2003-3-25 John O'Gorman john.ogorman@zombie.co.nz
 *
 * Reads a file of the form:
 * .1
 * message 1
 * .2
 * message 2
 *
 * Produces a file of the form 	(shown here in hex)
 * FE68 			;Informix MAGIC no
 * 0002 			;Count No of messages
 * 0001 000A 0000 000A		;Index record 1: msgno len offset
 * 0002 000A 0000 0014
 * message 1\0
 * message 2\0
 *
 *Comments
 * I wrote this to run in 3 passes of the input file to avoid the need
 * to have any arbitrary program storage limits.
 * The Informix format imposes implicit limits:
 * 1. Max no of message : 32767
 * 2. Max len of any message: 32767
 * 3. Max file size: 2^31 (2GB)
 *
 * @todo 1. Check null terminating logic for 1 message only
 * @todo 2. Add errno arg to chckerr()
 * @todo 3. investigate whether strtol() is preferable to atoi
 *
 */

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_mkmess_int.h"
//#include <stdio.h>
//#include <stdlib.h>


/*
-----------------------------------------------------------------------------
 PORTABLE
   Set if we are going to use network style integers
   Not set if we are going to use native integers
 (On some platforms these may be the same, on others they won't be)
-----------------------------------------------------------------------------
*/

#if defined (PORTABLE) && ! defined (__MINGW32__)
	#include <netinet/in.h>
#else
	#ifndef htonl
		#define htonl(x) (x)
		#define htons(x) (x)
		#define ntohl(x) (x)
		#define ntohs(x) (x)
	#endif
#endif



/*
=====================================================================
                    Variables definitions
=====================================================================
*/ 
  
#define HELPMAXLEN 78
static char progname[128];	//use this to pass argv[0] to functions

/*
=====================================================================
                    Functions prototypes
=====================================================================
*/ 
void mychkerr (FILE * f, char *s);
int outindex (int msgno, int len, int offset, FILE * f);
int out4 (int n, FILE * f);
int out2 (int n, FILE * f);
int fwrite2 (char *s, FILE * f);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/ 
  
/**
 * The main entry function to amkmessage compiler
 *
 * @param argc The arg count
 * @param argv The arguments values
 */ 
int
main (int argc, char *argv[]) 
{
  FILE * infile, *outfile;
  char *s;
  char line[HELPMAXLEN];
  int msgno = 0;
  int lwm = 0;			//low  water mark (beginning of message block)
  int hwm = 0;			//high water mark (offset to next message)
  int len = 0;			//count of (possibly multiline) message chars
  int current = 0;		//current count of messages found
  int count = 0;		//full count of messages found
  if (argc < 2)
    
    {
      fprintf (stderr, "Usage: %s sourcefile binfile\n", argv[0]);
      exit (1);
    }
  strcpy (progname, argv[0]);
  infile = fopen (argv[1], "r");
  mychkerr (infile, argv[1]);
  if (argc >= 3)
    
    {
      outfile = fopen (argv[2], "w+b");
      mychkerr (outfile, argv[2]);
    }
  
  else
    
    {
      outfile = stderr;
    }
  
/************************
	Pass 1: read the file, identify and count messages 
************************/ 
    while ((s = fgets (line, HELPMAXLEN, infile)) != NULL)
    
    {
      if (line[0] == '#')
	{
	  continue;
	}
      if (line[0] == '.')
	
	{
	  ++count;
	}
    }
  if (count < 1)
    
    {
      fprintf (stderr, "%s: %s contains no messages!\n", argv[0], argv[1]);
      exit (2);
    }
  A4GL_debug ("%d messages found\n", count);
  //printf("Writing header\n");
    //fputs("FE68\n",outfile);
    fwrite2 ("\xFE\x68", outfile);
  //printf("Wriring Count : %d\n",count);
    //fprintf(outfile,"%04X\n",count);
    out2 (count, outfile);
    //printf("Done write of count\n");
  
/****************************** 
	Pass 2
	Now reread the input file
	 build the index array
	 copy the messages (minus their .nnn headers) after the index block
*******************************/ 
    rewind (infile);
  mychkerr (infile, argv[1]);
  current = 0;			//count of message read so far
  lwm = hwm = 4 + count * 8;	//where the next message will be written
  s = fgets (line, HELPMAXLEN, infile);
  if (s == NULL)
    
    {
      fprintf (stderr, "%s:empty file\n", progname);
      exit (4);
    }
  while (1)
    
    {
      if (line[0] != '.')
	
	{
	  break;
	}
      if (feof (infile))
	
	{
	  break;
	}
      msgno = atoi (&line[1]);
      len = 0;			// reset len for next message
      // get the message (possibly multiline)
      while (1)
	
	{
	  s = fgets (line, HELPMAXLEN, infile);
	  if (line[0] == '.' || feof (infile))
	    
	    {
	      hwm += len + 1;	// add 1 for terminating '\0'
	      outindex (msgno, len, lwm, outfile);
	      lwm = hwm;
	      break;
	    }
	  
	  else
	    
	    {
	      len += strlen (line);
	      continue;
	    }
	}
    }
  
/************
	Pass 3: read the input file again 
		append the message strings (skipping the .nnn lines)

*************/ 
    current = 0;
  rewind (infile);
  mychkerr (infile, argv[1]);
  while (1)
    
    {
      s = fgets (line, HELPMAXLEN, infile);
      if (feof (infile))
	
	{
	  if (++current > 1)
	    
	    {
	      fputc (0, outfile);	//terminate prev string
	    }
	  break;
	}
      if (line[0] == '.')
	
	{
	  if (++current > 1)
	    
	    {
	      fputc (0, outfile);	//terminate prev string
	    }
	  continue;
	}
      
      else
	
	{
	  fprintf (outfile, "%s",s);
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
  char errmsg[80];
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


/********************************************************
 *
 * outindex(msgno, len, offset, f) writes out .iem index record 
 *				onto file stream
 */ 
int 
outindex (int msgno, int len, int offset, FILE * f) 
{
  out2 (msgno, f);
  out2 (len, f);
  return out4 (offset, f);
}


/*************************************************
 * out4(n,f)  writes n as 4 bytes in MSB order onto file f
 *
 */ 
int 
out4 (int n, FILE * f) 
{
  int n1, n2;
  n1 = n / 65536;
  n2 = n % 65536;
  out2 (n1, f);
  return out2 (n2, f);
}


/*****************************************************
 * out2(n,f)  writes n as 2 bytes in MSB order onto file f
 */ 
int 
out2 (int n, FILE * f) 
{
  char s[2];
  short nn;
  //printf("out2\n");
  nn=htons(n);
  memcpy(s,&nn,2);
  //s[0] = n / 256;
  //s[1] = n % 256;
//printf("Calling fwrite2 Writing %d as %d\n",n,nn);
  nn=fwrite2 (&s[0], f);
  //printf("!out2\n");
  return nn;
}


/*************************************************
 *  fwrite2: write 2 bytes onto file stream
 */ 
int 
fwrite2 (char *s, FILE * f) 
{
  size_t n;
  //printf("Writing %x %x\n",s[0]&0xff,s[1]&0xff);
  n = fwrite (s, 1, 2, f);
  return (int) n;
}


/* ============================= EOF =============================== */ 
  
