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

#endif	/*  */
void *
bsearch (const void *item, /* Pointer to item sought        */ 
	 const void *table, /* Pointer to start of table     */ 
	 size_t tablesize, /* Number of items in table      */ 
	 size_t entrysize, /* Size of one entry in table    */ 
	 int (*compare) (const void *,
			 const void *)) /* Comparison function           */  
{
  int top;
  int middle;
  int bottom;
  int result;
  const void *entry;
  const char *base = table;
  bottom = 0;
  top = tablesize - 1;
  while (top >= bottom)
    
    {
      middle = (top + bottom) / 2;
      entry = base + middle * entrysize;
      result = (*compare) (item, entry);
      if (result == 0)
	return ((void *) entry);	/* Found */
      
      else if (result < 0)
	top = middle - 1;
      
      else
	bottom = middle + 1;
    }
  return (0);			/* Not found */
}


#ifdef TEST
  
#include <stdio.h>
#include <assert.h>
#include <string.h>
static char *array[] = { "abcd", "abce", "bc", "def" 
};
static char *lookup[] = 
  { "a", "abce", "bc", "def", "abcd", "e", "abcdef", "ba", "caliph" 
};

#define DIM(x) (sizeof(x)/sizeof(*(x)))
  static int
qs_compare (const void *p1, const void *p2) 
{
  const char *const *s1 = (const char *const *) p1;
  const char *const *s2 = (const char *const *) p2;
  return (strcmp (*s1, *s2));
}
int
main (void) 
{
  size_t i;
  char **s;
  printf ("Data:\n");
  for (i = 0; i < DIM (array); i++)
    
    {
      
	/* Ensure data is sorted */ 
	if (i > 0)
	assert (qs_compare (&array[i - 1], &array[i]) < 0);
      printf ("%lu: %s\n", (unsigned long) i, array[i]);
    }
  printf ("Searching:\n");
  for (i = 0; i < DIM (lookup); i++)
    
    {
      s =
	bsearch (&lookup[i], array, DIM (array), sizeof (char *), qs_compare);
      if (s == 0)
	printf ("<<%s>> not found.\n", lookup[i]);
      
      else
	printf ("<<%s>> found at index %d (<<%s>>)\n", lookup[i], s - array,
		 *s);
    }
  s = bsearch (&lookup[0], array, 0, sizeof (char *), qs_compare);
  assert (s == 0);
  printf ("OK\n");
  return 0;
}


#endif	/* TEST */
