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
# $Id: pointers.c,v 1.18 2003-05-12 14:24:17 mikeaubury Exp $
#
*/

/**
 * @file
 *
 * Functions that deal with pointers to memory for the global statements such as
 * windows, cursors, etc.
 *
 * It have an internal binary tree where store the information.
 *
 * @todo Take the prototypes here declared. See if the functions are static
 * or to be externally seen
 */

/*
=====================================================================
                    Constants definitions
=====================================================================
*/

#define TXT_LEN 128

#define  FIND(a) (tfind(a,(void *)&root,strcmpare))
#define  ADD(a) (tsearch(a,(void *)&root,strcmpare))
#define  DELETE(a) (tdelete(a,(void *)&root,strcmpare))

/*
=====================================================================
		                    Includes
=====================================================================
*/

#include "a4gl_libaubit4gl_int.h"

/*
#ifndef WIN32
#include <search.h>
//#else
//#define VISIT int
#endif
*/

/*
=====================================================================
                    Variables definitions
=====================================================================
*/

/** Root of the tree */
void *root = 0;


/**
 * Tree node
 */
struct s_node
{
  char name[TXT_LEN + 1];
  void *ptr;
};

/*
=====================================================================
                   Platform specific definitions
=====================================================================
*/

#if defined(__DARWIN__) || defined (WIN32) || defined(__CYGWIN__) || defined(__MINGW32__)
//actually, should use  #if HAVE_SEARCH_H

	/* search internal node for windows and platforms without this library function */

typedef struct entry
{
  char *key, *data;
}
ENTRY;
typedef enum
{ FIND, ENTER }
ACTION;

	/* TSEARCH(3C) */
	/** The type of the visit made to an element of the tree */
	//why are this two lines commented out:
	//typedef enum { preorder, postorder, endorder, leaf } VISIT;
	//void action (const void *nodep, const VISIT which, const int depth);

	/** A node tree information */
typedef struct node_t
{
  char *key;
  struct node_t *left, *right;
}
node;

node *tsearch (char *key, node ** rootp, int (*compar) ());
node *tdelete (char *key, node ** rootp, int (*compar) ());
void twalk (node * root, void *act);
	// void twalk(node *root, VISIT action);
node *tfind (char *key, node ** rootp, int (*compar) ());
#endif

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

int strcmpare (const void *a, const void *b);
void action (const void *nodep, const VISIT which, const int depth);
void print_ptr_stack (void);

/*
=====================================================================
                    Functions definitions
=====================================================================
*/

/**
 * Comparison function to use with bsearch.
 *
 * @param a Pointer to the first element to compare.
 * @param b Pointer to the second element to compare.
 * @return:
 *   - less than zero if a less than b
 *   - zero if a equals b
 *   - greater than zero if a greater b
 */
int
strcmpare (const void *a, const void *b)
{
  return strcmp (a, b);
}

/**
 * Function to be executed when iterating in one node.
 *
 * Used for debuging purposes.
 *
 * @param nodep
 * @param wich The position of the element in the tree:
 *  - preorder
 *  - postorder
 *  - endorder
 *  - leaf
 * @param depth
 */
void
action (const void *nodep, const VISIT which, const int depth)
{
  struct s_node *datap;
  char buff[800];

  memset (buff, ' ', 800);
  buff[depth * 4] = 0;
  switch (which)
    {
    case preorder:
      break;
    case postorder:
      datap = *(struct s_node **) nodep;
      debug ("%s%s %p :", buff, datap->name, datap->ptr);
      break;
    case endorder:
      break;
    case leaf:
      datap = *(struct s_node **) nodep;
      debug ("%s%s %p :", buff, datap->name, datap->ptr);
      break;
    }
  return;
}

/**
 * Add a pointer to the tree.
 *
 * @param orig_name The name or key to be access key.
 * @param type The type of the information stored.
 * @param ptr A pointer to the information to store.
 */
void
add_pointer (char *orig_name, char type, void *ptr)
{
  void *a;
  struct s_node *buff;
  struct s_node *buff_add;
  struct s_node buff2;
  struct s_node *node;
  char ptrchar[800];
  trim (orig_name);
  debug ("Adding pointer to %s %c (%p)", orig_name, type, ptr);
  buff = (struct s_node *) malloc (sizeof (struct s_node));
  buff->name[0] = type;
  buff->name[1] = 0;
  strcat (buff->name, orig_name);
  buff->ptr = ptr;
  debug ("Buff=%p\n", buff);
  a = FIND (buff);

  if (a)
    {
      debug ("Found an existing one %p\n", a);
      node = *(struct s_node **) a;
      debug ("Node = %p\n", node);
      debug ("Node=%p name=%s\n", node, node->name);
      sprintf (ptrchar, ">%p", buff->ptr);
      debug ("Copied ptr\n");
      node->ptr = ptr;
      debug ("Copy buffer %s\n", ptrchar);
      strcpy (buff2.name, ptrchar);
      debug ("And find its pointer\n");
      a = FIND (&buff2);
      if (a)
	{
	  debug ("Found ptr... \n");
	  node = *(struct s_node **) a;
#if ! defined(__MINGW32__)
	  DELETE (&buff2);
#endif

	  debug ("Try to free %p\n", node);
	  strcpy (node->name, "======");
	  free (node);
	}
      else
	{
	  debug ("No pointer\n");
	}
    }
  else
    {
      debug ("tfind ... a=%p\n", a);
      a = ADD (buff);
      debug ("tsearch ... a=%p %p\n", a, buff);
    }
  buff_add = (struct s_node *) malloc (sizeof (struct s_node));
  sprintf (buff_add->name, ">%p", ptr);
  buff_add->ptr = buff;
  debug ("Adding extra for %s %p\n", buff_add->name, buff_add->ptr);
  a = ADD (buff_add);
  debug ("Added...");
}



/**
 * Find the pointer to a global statement of 4gl (cursor, window, etc).
 *
 * @param pname The key to access in the tree.
 * @param t The type of the pointer. The pointer type codes are defined in
 * pointers.h and(or) dbforms.h.
 * @return The pointer to the memory location information.
 */
void *
find_pointer (const char *pname, char t)
{
  struct s_node buff;
  struct s_node *node;
  void *a;

  debug ("Finding pointer to %s %c", pname, t);
  buff.name[0] = t;
  buff.name[1] = 0;
  strcat (buff.name, pname);
  buff.ptr = 0;
  debug ("Finding %s", buff.name);
  a = FIND (&buff);
  debug ("A=%p", a);
  if (a != NULL)
    {
      node = *(struct s_node **) a;
      debug ("Returning %s %c %p", &node->name[1], node->name[0], node->ptr);
      return node->ptr;
    }
  else
    {
      debug ("Opps - not found pname=%s t=%c a=%p", pname, t, a);
      return 0;
    }
}


/**
 * Debug the tree.
 *
 * Iterate in the tree and execute the action() function to show what it is
 * doing.
 */
void
print_ptr_stack (void)
{
  twalk (root, action);
}

/**
 * Delete a pointer from the tree.
 *
 * @param pname The key to access to the tree.
 * @param t The type of the information stired in the tree.
 */
void
del_pointer (char *pname, char t)
{
  void *a;
  struct s_node *buff;
  struct s_node buff2;
  struct s_node *node;
  char ptrchar[800];
  buff = (struct s_node *) malloc (sizeof (struct s_node));
  buff->name[0] = t;
  buff->name[1] = 0;
  strcat (buff->name, pname);
  debug ("Buff=%p\n", buff);
  a = FIND (buff);
  if (a)
    {
      node = *(struct s_node **) a;
      sprintf (ptrchar, ">%p", buff->ptr);
      strcpy (buff2.name, ptrchar);
      a = FIND (&buff2);
      if (a)
	{
	  node = *(struct s_node **) a;
#if ! defined(__MINGW32__)
	  DELETE (&buff2);
#endif
	  strcpy (node->name, "======");
	  free (node);
	}
#if ! defined(__MINGW32__)
      DELETE (buff);
#endif
      free (buff);
    }
}


/**
 * Gets a pointer stored in the tree acess in by key and type.
 *
 * @param pname The key to access.
 * @param t The type of the information stored.
 *
 * @return The pointer to the values found.
 */
void *
find_pointer_val (char *pname, char t)
{
  return find_pointer (pname, t);
}

/**
 * Find a member of the tree using the pointer address instead the key.
 *
 * @param name
 * @param type
 * @param ptr
 * @return
 *   - 0 :
 *   - 1 :
 */
int
find_pointer_ptr (char *name, char *type, void *ptr)
{
  struct s_node buff;
  struct s_node *node;
  void *a;
  debug ("Finding pointer to pointer %p", ptr);
  sprintf (buff.name, ">%p", ptr);
  debug ("Finding %s", buff.name);
  buff.ptr = 0;

  a = FIND (&buff);
  debug ("Find returns %p", a);
  if (a)
    {
      node = *(struct s_node **) a;
      node = (struct s_node *) node->ptr;

      debug ("Copying.. %s", node->name);
      *type = node->name[0];
      strcpy (name, &node->name[1]);
      return 1;
    }
  else
    {
      debug ("Not found");
      return 0;
    }
}

/**
 * Check if a name have a pointer stored in the tree.
 *
 * @param pname The key to access to the tree.
 * @param t The type of the information stored.
 * @return If the key exists in the tree:
 *   - 0 : Do not exist in the tree
 *   - 1 : Exist in the tree
 */
int
has_pointer (char *pname, char t)
{
  void *a;
  a = find_pointer (pname, t);
  if (a)
    return 1;
  else
    return 0;
}

/**
 * Tree search generalized from Knuth (6.2.2) Algorithm T just like
 * the AT&T man page says.
 *
 * The node_t structure is for internal use only, lint doesn't grok it.
 *
 * Written by reading the System V Interface Definition, not the code.
 *
 * Totally public domain.
 */
 /*LINTLIBRARY*/
#if defined(__DARWIN__) || defined (WIN32) || defined (__CYGWIN__)
//actually, should use  #if HAVE_SEARCH_H
/**
 * find or insert datum into search tree
 *
 * @param key key to be located
 * @param rootp address of tree root
 * @param compar ordering function
 * @todo Describe function
 */
  node * tsearch (key, rootp, compar)
     char *
       key;
     register node **
       rootp;
     int (*compar) ();
{
  register node *q;

  if (rootp == (struct node_t **) 0)
    return ((struct node_t *) 0);
  while (*rootp != (struct node_t *) 0)	/* Knuth's T1: */
    {
      int r;

      if ((r = (*compar) (key, (*rootp)->key)) == 0)	/* T2: */
	return (*rootp);	/* we found it! */

      rootp = (r < 0) ? &(*rootp)->left :	/* T3: follow left branch */
	&(*rootp)->right;	/* T4: follow right branch */
    }
  q = (node *) malloc (sizeof (node));	/* T5: key not found */
  if (q != (struct node_t *) 0)	/* make new node */
    {
      *rootp = q;		/* link new node to old */
      q->key = key;		/* initialize new node */
      q->left = q->right = (struct node_t *) 0;
    }
  return (q);
}

/**
 * delete node with given key
 *
 * @param
 * @param
 * @param
 *
 * @todo Describe function
 */
node *
tdelete (key, rootp, compar)
     char *key;			/* key to be deleted */
     register node **rootp;	/* address of the root of tree */
     int (*compar) ();		/* comparison function */
{
  node *p;
  register node *q;
  register node *r;
  int cmp;


  if (rootp == (struct node_t **) 0 || (p = *rootp) == (struct node_t *) 0)
    return ((struct node_t *) 0);

  while ((cmp = (*compar) (key, (*rootp)->key)) != 0)
    {
      p = *rootp;
      rootp = (cmp < 0) ? &(*rootp)->left :	/* follow left branch */
	&(*rootp)->right;	/* follow right branch */
      if (*rootp == (struct node_t *) 0)
	return ((struct node_t *) 0);	/* key not found */
    }

  r = (*rootp)->right;		/* D1: */
  if ((q = (*rootp)->left) == (struct node_t *) 0)	/* Left (struct node_t *)0? */
    q = r;
  else if (r != (struct node_t *) 0)	/* Right link is null? */
    {
      if (r->left == (struct node_t *) 0)	/* D2: Find successor */
	{
	  r->left = q;
	  q = r;
	}
      else
	{			/* D3: Find (struct node_t *)0 link */
	  for (q = r->left; q->left != (struct node_t *) 0; q = r->left)
	    r = q;
	  r->left = q->right;
	  q->left = (*rootp)->left;
	  q->right = (*rootp)->right;
	}
    }
  free ((struct node_t *) *rootp);	/* D4: Free node */
  *rootp = q;			/* link parent to new node */
  return (p);
}

/**
 * Walk the nodes of a tree
 *
 * @param
 * @param
 * @param
 *
 * @todo Describe function
 */
static void
trecurse (root, action, level)
     register node *root;	/* Root of the tree to be walked */
     register void (*action) ();	/* Function to be called at each node */
     register int level;
{
  if (root->left == (struct node_t *) 0 && root->right == (struct node_t *) 0)
    (*action) (root, leaf, level);
  else
    {
      (*action) (root, preorder, level);
      if (root->left != (struct node_t *) 0)
	trecurse (root->left, action, level + 1);
      (*action) (root, postorder, level);
      if (root->right != (struct node_t *) 0)
	trecurse (root->right, action, level + 1);
      (*action) (root, endorder, level);
    }
}

/**
 * Walk the nodes of a tree .
 *
 * @param root Root of the tree to be walked
 * @paramaction Function to be called at each node
 */
void
twalk (node * root, void *act)
{
  if (root != (node *) 0 && act != (void (*)()) 0)
    trecurse (root, act, 0);
}

/* tsearch.c ends here */
/*
 * Tree search generalized from Knuth (6.2.2) Algorithm T just like
 * the AT&T man page says.
 *
 * The node_t structure is for internal use only, lint doesn't grok it.
 *
 * Written by reading the System V Interface Definition, not the code.
 *
 * Totally public domain.
 */
 /*LINTLIBRARY*/
/**
 * Find a node
 *
 * @param key Key to be found
 * @param rootp Address of the tree root
 * @param compar Ordering function
 * @return
 *   - 0 : Key not found in the tree.
 *   - 1 : Key found in the tree.
 */
node * tfind (char *key, register node ** rootp, int (*compar) ())
{
  if (rootp == (struct node_t **) 0)
    return ((struct node_t *) 0);
  while (*rootp != (struct node_t *) 0)	/* T1: */
    {
      int r;
      if ((r = (*compar) (key, (*rootp)->key)) == 0)	/* T2: */
	return (*rootp);	/* key found */
      rootp = (r < 0) ? &(*rootp)->left :	/* T3: follow left branch */
	&(*rootp)->right;	/* T4: follow right branch */
    }
  return (node *) 0;
}


#endif /* # defined (WIN32)  || defined (__CYGWIN__) || defined (__DARWIN__) */

/* ============================== EOF ============================ */
