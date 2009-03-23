#ifndef A4GL_MEMHANDLING
#define A4GL_MEMHANDLING

void acl_free_full (void *ptr, char *f, long line);
void *acl_malloc_full(long a,char *r,char *f,long l);
void *acl_realloc_full(void *a,long b,char *r,char *f,int l);
char *acl_strdup_full(void *a,char *r,char *f,int l);

#define acl_free(s) 		acl_free_full(s,__FILE__,__LINE__)
#define acl_malloc(a,b) 	acl_malloc_full((long)a,b,__FILE__,__LINE__)
#define acl_malloc2(a) 		acl_malloc_full((long)a,"",__FILE__,__LINE__)
#define acl_realloc(a,b) 	acl_realloc_full(a,b,"",__FILE__,__LINE__)
#define acl_strdup(s) 		acl_strdup_full(s,"",__FILE__,__LINE__)

#endif
