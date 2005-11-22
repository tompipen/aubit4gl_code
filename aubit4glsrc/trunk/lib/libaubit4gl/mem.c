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
  p = malloc (size);
  A4GL_assertion(p==0,"Unable to allocate memory");
  A4GL_debug ("alloc %d bytes : %p %s %s %d", size,p,why,f,line);
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
  A4GL_debug ("Free %p %s %d", ptr,f,line);
  free (ptr);
}

