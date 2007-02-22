#include "a4gl_libaubit4gl.h"

static void *last_orig=0;

struct mem_extra {
	int nmemalloc;
	void **ptr;
};




/**
 * Aubit compiler malloc.
 *
 * It was used to make some A4GL_debug about memory allocations.
 * Right now just encapsulate standard C malloc.
 *
 * @param size The size in bytes to be allocated
 * @param why The reason for memory allocation
 * @param f The source file name where the memory is being alocated
 * @pram line The source file line number where memory being alocated
 * @return A pointer for the memory alocated
 */
void *
acl_malloc_full (long size, char *why, char *f, long line)
{
  void *p;
  if (size>2000000) { A4GL_assertion(1,"Dubious amount of memory to malloc"); }
  p = malloc (size);
  A4GL_assertion(p==0,"Unable to allocate memory");
  //A4GL_debug ("alloc %d bytes : %p %s %s %d", size,p,why,f,line);
  return p;
}

char *acl_strdup_full(void *a,char *r,char *f,int l) {
        char *p;
        p=strdup(a);
        A4GL_assertion(p==0,"Unable to allocate memory");
        return p;
}

void *acl_realloc_full(void *a,long b,char *r,char *f,int l) {
        void *p;
        p=realloc(a,b);
        A4GL_assertion(p==0,"Unable to allocate memory");
        return p;
}

/**
 *
 *
 * @param
 */
void
acl_free_full (void *ptr, char *f, long line)
{
  //A4GL_debug ("Free %p %s %d", ptr,f,line);
  free (ptr);
}


/*
 *  Allocate some memory - but associate it with some other pointer
 *  that way - we can 'link' them so we can remove all the associated memory just by
 *  freeing the parent...
 */
void *A4GL_alloc_associated_mem(void *orig,int nbytes) {
	char buff[256]="";
	int nelem;
	static struct mem_extra *ptr=0;
	void *newblock=0;

	if (last_orig!=orig)  {
		SPRINTF1(buff,"%p",orig);
		if (A4GL_has_pointer(buff,MEMEXTRA)) {
			ptr=A4GL_find_pointer(buff,MEMEXTRA);
		} else {
			ptr=malloc(sizeof(struct mem_extra));
			memset(ptr,0,sizeof(struct mem_extra));
			if (ptr==0) {
				A4GL_assertion(1,"Unable to allocate memory");
			}
			A4GL_add_pointer(buff,MEMEXTRA,ptr);
			ptr->nmemalloc=0;
			ptr->ptr=0;
		}
		last_orig=orig;
	} else {
		// ptr will be set to point to the last one already...
	}
	ptr->nmemalloc++;
	nelem=ptr->nmemalloc;
	// ptr will point to our mem_extra area now..

	ptr->ptr=realloc(ptr->ptr,sizeof (void *)*nelem);
	
	if (nbytes) {
		newblock=malloc(nbytes);
	} else {
		newblock=0;
	}

	ptr->ptr[nelem-1]=newblock;
	return ptr->ptr[nelem-1];
}


void A4GL_free_associated_mem(void *orig) {
	char buff[256];
	struct mem_extra *ptr;
	int a;
	if (last_orig==orig) {
		last_orig=0;
	}
	SPRINTF1(buff,"%p",orig);

	if (A4GL_has_pointer(buff,MEMEXTRA)) {
		ptr=A4GL_find_pointer(buff,MEMEXTRA);
	} else {
		// Nothing allocated...
		return;
	}

	for (a=0;a<ptr->nmemalloc;a++) {
		A4GL_free_associated_mem(ptr->ptr[a]);	// free any children...
		if (ptr->ptr[a]) free(ptr->ptr[a]); 			// free the allocated memory..
	}
	ptr->nmemalloc=0;

	// free the array that holds our pointers..
	free(ptr->ptr);
	ptr->ptr=0;

	// free the mem_extra structure iteself..
	free(ptr);

	// Finally - get rid of the A4GL_..._pointer...
	A4GL_del_pointer(buff,MEMEXTRA);
}
