/*
@(#)File:            $RCSfile: filter.c,v $
@(#)Version:         $Revision: 1.3 $
@(#)Last changed:    $Date: 2003-09-29 15:10:38 $
@(#)Purpose:         Standard File Filter
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1987-89,1991,1993,1996-98
@(#)Product:         SQLFMT Version 14 (1998-11-04)
*/  
  
/*TABSTOP=4*/ 
   /*LINTLIBRARY*/ 
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "stderr.h"
#include "filter.h"


#ifndef lint
static const char rcs[] =
  "@(#)$Id: filter.c,v 1.3 2003-09-29 15:10:38 mikeaubury Exp $";

#endif	/* 
  
/* Set program to continue with next file after a file-open error */ 
  void
filter_setcontinue (void) 
{
  



/*
    Purpose:    Standard File Filter

    Maintenance Log
    ---------------
    09/03/87  JL    Original version stabilised
    18/04/88  JL    Now pass fp and file name to function
    15/12/91  JL    Upgrade for ANSI C
    29/06/93  JL    Rename to filter and accept optind argument
    15/10/96  JL    Remove non-ANSI support and ffilter(); rename file
	31/03/98  JL    Add support for continuing on error opening a file

    Arguments
    ---------
    argc            In: Number of arguments
    argv            In: Argument list of program
    optind          In: Offset in list to start at
    function        In: Function to process file

    Comments
    --------
    1.  For every non-flag option in the argument list, or standard input
        if there are no non-flag arguments, run 'function' on file.
    2.  If a file name is '-', use standard input.
    3.  The optnum argument should normally be the value of optind as
        supplied by getopt(3).  But it should be the index of the first
        non-flag argument.

*/ 
  
filter (int argc, char **argv, int optnum, Filter function) 
{
  
  
  
  
    
    {
      
	/* Assumes argv[argc] == NIL(char *) and can be assigned to */ 
	argv[argc] = "-";
      
    
  
    
    {
      
	
	{
	  
	  
	
      
      else if ((fp = fopen (argv[i], "r")) != NULL)
	
	{
	  
	  
	  
	
      
      else if (continue_mode)
	
		     strerror (errno));
      
      else
	
    



#ifdef TEST
  
/*
** Test program -- equivalent to: cat [-v] [file ...]
*/ 
  
#include <ctype.h>
#define GETOPT gnu_getopt
#include "getopt.h"
  
fcopy (FILE * f1, FILE * f2) 
{
  
  
  
    
    {
      
	
    


vis (FILE * fp, char *fn) 
{
  
  
  
    
    {
      
	
      
      else if (c > 127 || !isprint (c))
	
      
      else
	
    


cat (FILE * fp, char *fn) 
{
  
  


main (int argc, char **argv) 
{
  
  
  
  
  
    
    {
      
	
      
      else if (opt == 'v')
	
      
      else
	
    
  
  



#endif	/* TEST */