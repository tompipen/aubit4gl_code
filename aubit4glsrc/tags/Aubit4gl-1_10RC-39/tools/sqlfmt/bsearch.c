/*
@(#)File:            $RCSfile: bsearch.c,v $
@(#)Version:         $Revision: 1.2 $
@(#)Last changed:    $Date: 2003-05-12 14:24:42 $
@(#)Purpose:         General Binary Search Algorithm
@(#)Author:          J Leffler
@(#)Copyright:       (C) JLSS 1987,1990,1997-98
@(#)Product:         SQLFMT Version 14 (1998-11-04)
*/  
  
/*TABSTOP=4*/ 
  
#include <stdlib.h>
  
#ifndef lint
static const char rcs[] =
  "@(#)$Id: bsearch.c,v 1.2 2003-05-12 14:24:42 mikeaubury Exp $";

#endif	/* 

bsearch (
	 const void *table, /* Pointer to start of table     */ 
	 size_t tablesize, /* Number of items in table      */ 
	 size_t entrysize, /* Size of one entry in table    */ 
	 int (*compare) (const void *,
			 const void *)) /* Comparison function           */  
{
  
  
  
  
  
  
  
  
  
    
    {
      
      
      
      
	
      
      else if (result < 0)
	
      
      else
	
    
  



#ifdef TEST
  
#include <stdio.h>
#include <assert.h>
#include <string.h>

};

  { 
};

#define DIM(x) (sizeof(x)/sizeof(*(x)))
  
qs_compare (const void *p1, const void *p2) 
{
  
  
  


main (void) 
{
  
  
  
  
    
    {
      
	/* Ensure data is sorted */ 
	if (i > 0)
	
      
    
  
  
    
    {
      
	bsearch (&lookup[i], array, DIM (array), sizeof (char *), qs_compare);
      
	
      
      else
	
		 *s);
    
  
  
  
  



#endif	/* TEST */