/**
 * @file
 * Implements stack functions for helping in the parsing.
 */

#include <strings.h>
#include <string.h>
#include "a4gl_debug.h"

#define PUSH_NAME  1
#define PUSH_LIKE 2
#define PUSH_RECORD 3
#define PUSH_RECTAB 4
#define PUSH_TYPE 5
#define PUSH_ASSOCIATE 6
#define POP_RECORD 7
#define POP_ASSOCIATE 8
#define SETNAME 0

/** Item of stack entry */
struct s_dimitem
{
  int type;
  char *a;
  char *b;
  char *c;
  struct s_dimitem *next;
};

/** Stack entry */
struct s_dimentry
{
  char *dimname;
  struct s_dimitem *item;
};

/** Pointer to the global stack */
struct s_dimentry **dims = 0;

/** Dimension used in number of elements */
int dimcnt = -1;

/** Dimension in number of elements allocated */
int dimalloc = 0;

/**
 * Adds a new item to the list pointed by global variable dims
 *
 * @param a The type of the information stored in a stack (there are defines 
 *          to code it.
 * @param s1
 * @param s2
 * @param s3
 */
static void dim_add (int a, char *s1, char *s2, char *s3)
{
  char *ptr1;
  char *ptr2;
  char *ptr3;
  struct s_dimentry *ent;
  struct s_dimitem *itm;
  struct s_dimitem *itm2;
  
  debug ("dim_add %d %p %p %p\n", a, s1, s2, s3);

  if (a == SETNAME)
  {
    if (dimalloc <= dimcnt || dimcnt < 0)
    {
      long size_space;
      dimalloc += 10;
      size_space = sizeof (struct s_dimentry *) * dimalloc;
      debug ("Allocating space for %d dims of %d bytes\n", dimalloc,
        size_space);
      dims = (struct s_dimentry **) realloc (dims, size_space);
      debug ("dims=%p\n", dims);
    }
    debug ("Allocating entry\n");
    ent = (struct s_dimentry *) malloc (sizeof (struct s_dimentry));
    debug ("ent=%p\n", ent);

    ent->dimname = (char *) strdup (s1);
    ent->item = 0;
    dimcnt += 1;
    debug ("Adding to array at %d\n", dimcnt);
    dims[dimcnt] = ent;
    debug ("Ok\n");
    return;
  }
  if (dimcnt < 0 || dimalloc <= 0)
  {
    yyerror ("Internal error allocating dim space\n");
  }
  debug ("Adding item dimcnt=%d dimalloc=%d dims=%p\n", dimcnt, dimalloc,
    dims);
  itm = (struct s_dimitem *) malloc (sizeof (struct s_dimitem));
  debug ("itm=%p\n", itm);
  itm->type = a;

  if (s1)
    itm->a = strdup (s1);
  else
    itm->a = 0;

  if (s2)
    itm->b = strdup (s2);
  else
    itm->b = 0;

  if (s3)
    itm->c = strdup (s3);
  else
    itm->c = 0;
  debug ("set strings\n");

  itm->next = 0;
  itm2 = dims[dimcnt]->item;
  debug ("Setting link\n");
  if (itm2 == 0)
  {
    debug ("First item\n");
    dims[dimcnt]->item = itm;
    debug ("Done\n");
  }
  else
  {
    debug (">First item\n");
    itm2 = dims[dimcnt]->item;
    debug ("itm2=%p\n");
    while (itm2->next != 0)
    {
      debug ("Keep going %p %p\n", itm2, itm2->next);
      itm2 = itm2->next;
    }
    debug ("itm2=%p\n", itm2);
    itm2->next = itm;
  }
  debug ("all done\n");
}

/**
 * Pushes a name to the stack.
 *
 * Executed when the parser found the declaration of variables in define.
 *
 * @todo : Understand why this function is called with only one argument
 *
 * @param a The name to be pushed
 * @param b
 */
void dim_push_name (char *a, char *b)
{
  dim_add (PUSH_NAME, a, b, 0);
}

/**
 * Pushes the table and(or) column to the stack.
 *
 * Executed when the parser found a declaration like table.column
 *
 * @param a The pair table.column 
 */
void dim_push_like (char *a)
{
  dim_add (PUSH_LIKE, a, 0, 0);
}

/**
 * Push the declaration of a record to the stack.
 *
 * Dont store any information. Just allocate the memory needed and waits
 * until the parser found the rest of the information.
 */
void dim_push_record (void)
{
  dim_add (PUSH_RECORD, 0, 0, 0);
}

/**
 * Push the declaration of a record like table.* to the stack.
 *
 * Alocate the memory needed, store the table name and waits
 * until the parser found the rest of the information.
 *
 * @param a The table name
 */
void dim_push_rectab (char *a)
{
  dim_add (PUSH_RECTAB, a, 0, 0);
}

/**
 * Push a fgl data type to the stack.
 *
 * @param type The data type name (char, integer, etc). For the arrays is 
 *             filled.
 * @param sz The size of the data type if a sizeable one (decimal, etc).
 * @param arrsz The size of the type if its an array
 */
void dim_push_type (char *type, char *sz, char *arrsz)
{
  dim_add (PUSH_TYPE, type, sz, arrsz);
}

/**
 * Pop a record from the stack.
 *
 * Executed when the parser finishes the parsing of the record (found end record
 * or like tablename.*
 */
void dim_pop_record (void)
{
  dim_add (POP_RECORD, 0, 0, 0);
}

/**
 * Pushes an associative variable into the stack.
 *
 * An associative array is an kind of hash and is an aubit extension to 
 * 4gl.
 *
 * @param a 
 * @param b
 */
void dim_push_associate (char *a, char *b)
{
  dim_add (PUSH_ASSOCIATE, a, b, 0);
}


/**
 * Adds an associative array to the stack.
 *
 * @param a 
 */
void dim_pop_associate (char *a)
{
  dim_add (POP_ASSOCIATE, a, 0, 0);
}

void dim_set_name (char *a)
{
  dim_add (SETNAME, a, 0, 0);
}

static void push_dim_records (int cnt)
{
  int a;
  struct s_dimitem *ptr;
  a = 0;
  ptr = dims[cnt]->item;
  while (ptr)
  {
    switch (ptr->type)
	  {
	    case PUSH_NAME:
	      push_name (ptr->a, ptr->b);
	      break;
	    case PUSH_LIKE:
	      push_like (ptr->a);
	      break;
	    case PUSH_RECORD:
	      push_record ();
	      break;
	    case PUSH_RECTAB:
	      push_rectab (ptr->a);
	      break;
	    case PUSH_TYPE:
	      push_type (ptr->a, ptr->b, ptr->c);
	      break;
	    case PUSH_ASSOCIATE:
	      push_associate (ptr->a, ptr->b);
	      break;
	    case POP_RECORD:
	      pop_record ();
	      break;
	    case POP_ASSOCIATE:
	      pop_associate (ptr->a);
	      break;
	  }
    ptr = ptr->next;
  }
}

push_dim (char *a)
{
  int cnt;
  for (cnt = 0; cnt <= dimcnt; cnt++)
  {
    if (strcmp (dims[cnt]->dimname, a) == 0)
	  {
	    push_dim_records (cnt);
	    return;
	  }
  }

  yyerror ("Unknown type");
  return;
}
