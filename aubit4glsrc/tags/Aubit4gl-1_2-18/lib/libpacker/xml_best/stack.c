#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


void *x_malloc(int n) ;
void move_lru(int n) ;
int dbg=0;

struct stack_entry {
	char *sname;
	int sz;
	void *ptr;
	int nmembers;
	int currmember;
	void *userptr;
	char *parent_elem;
};

struct stack_entry  *stack=0;
int stack_cnt=0;

static void print_stack() {
int a;
int b;
printf("Stack :\n");
for (a=0;a<stack_cnt;a++) {
	for (b=0;b<a;b++) {
		printf("   ");
	}
	printf("%s\n", stack[a].sname);
}
}


int SetParent_fgl(char *type, char *element, void *parent,  void *val);

//
// Sname    - name of structure (just used for debugging)
// sz       - size of each element in the array
// nmembers - number of elements to allocate (normally 1)
// userptr  - user pointer - not used internally at all..
void XMLPushOntoStack(char *sname, int sz,int nmembers,void *userptr,int from_where,char *parent_elem) {
	stack_cnt++;
	stack=realloc(stack,stack_cnt*sizeof(struct stack_entry));
	stack[stack_cnt-1].sname=sname;
	stack[stack_cnt-1].sz=sz;
	stack[stack_cnt-1].nmembers=nmembers;
	stack[stack_cnt-1].currmember=0;
//printf("Push %s %s\n",sname, parent_elem);
	stack[stack_cnt-1].parent_elem=strdup(parent_elem);

	if (nmembers) {
		switch (from_where) {
			// These are identical - its just to help valgrind find our leaks...
			case 1: stack[stack_cnt-1].ptr=x_malloc(sz*nmembers); break;
			case 2: stack[stack_cnt-1].ptr=x_malloc(sz*nmembers); break;
			case 3: stack[stack_cnt-1].ptr=x_malloc(sz*nmembers); break;
			default: stack[stack_cnt-1].ptr=x_malloc(sz*nmembers); break;
		}
	if (stack[stack_cnt-1].ptr==0) {
			printf("\n\nUnable to allocate memory\n");
			perror("");
			exit(2);
	}
		memset( stack[stack_cnt-1].ptr, 0xaa, sz*nmembers);
	} else {
		//printf("NO SIZE!\n");
		stack[stack_cnt-1].ptr=0;
	}
	stack[stack_cnt-1].userptr=userptr; 
	//print_stack();
}


int ChkTopOfStack(char *s) {
   if (strcmp(s, XMLGetTopOfStackSname())!=0) {
        fprintf(stderr,"%s is not at the top of the stack\n",s);
		print_stack();
        exit(2);
   }
return 1;
}

/* Interface function */
char *XMLGetTopOfStackSname (void) {
	if (dbg) printf("Top of stack contains a %s\n", stack[stack_cnt-1].sname);
	if (stack_cnt-1>=0) {
		return stack[stack_cnt-1].sname;
	}
	return "";
}


/* Interface function */
void *XMLGetTopOfStack (void) {
	if (stack_cnt==0) return 0;
	if (stack[stack_cnt-1].userptr) return 0;

	return stack[stack_cnt-1].ptr;
}

/* Interface function */
void *XMLGetTopOfStackUserptr (void) {
	return stack[stack_cnt-1].userptr;
}


/* Interface function */
char *XMLGetTopOfStackParentElem (void) {
	if (stack_cnt-1>=0) {
		return stack[stack_cnt-1].parent_elem;
	}
	return "";
}

/* Interface function */
int XMLGetTopOfStackNmembers (void) {
	if (dbg) printf("nmembers=%d\n", stack[stack_cnt-1].nmembers);
	return stack[stack_cnt-1].nmembers;
}

int XMLGetTopOfStackcurrent_subscript(char *sname) {
        return stack[stack_cnt-1].currmember;
}

int XMLSetTopOfStackcurrent_subscript(char *sname, int n) {
	if (stack[stack_cnt-1].nmembers<n) {
		XMLReallocateStack(sname, n);
	}
	stack[stack_cnt-1].currmember=n;
	return stack[stack_cnt-1].currmember;
}

// Resizes the pointer on our stack for more members
// (so for more elements in an array for example)
int XMLReallocateStack(char *sname, int nmembers) {
	printf("Reallocate from %d to %d members\n", stack[stack_cnt-1].nmembers,nmembers);
	stack[stack_cnt-1].nmembers=nmembers;
	stack[stack_cnt-1].ptr=realloc( stack[stack_cnt-1].ptr, stack[stack_cnt-1].sz*nmembers);
	return 1;
}

// Free the memory associated with a XML structure read
// sname - name of structure (just used for debugging)
// retain is whether we want to free the memory associated with that section we've
//        just used and are now freeing. This is retained when we have a pointer to a structure
//        rather than a structure in our source .x file (so we're using that data rather than
//        memcpy'ing it).
void *XMLPopOffStack(char *sname, int retain) {
char *ptr;
void *userptr;
// Ok - here we might want to reallocate the array
// but theres little point...
	userptr=stack[stack_cnt-1].userptr;
//printf("POP %s\n",sname);

	if (strcmp(stack[stack_cnt-1].sname,sname)!=0) {
		printf("Can't pop %s off the stack - its not at the top\n", sname);
		exit(2);
	}
	if (stack_cnt<=0) {
		printf("Nothing on the stack!\n");
		exit(2);
	}
	if (strcmp(stack[stack_cnt-1].sname, sname)!=0) {
		printf("XMLStack got confused\n");
		exit(1);
	}
	stack_cnt--;
	if (!retain) {
		if (dbg) printf("Popping %s\n",sname);
		free(stack[stack_cnt-1].ptr);
		return 0;
	}
	if (dbg) printf("Popping  & retaining %s\n",sname);
	//print_stack();

	ptr=stack[stack_cnt].ptr;

	stack[stack_cnt].sname=0;
	stack[stack_cnt].sz=0;
	stack[stack_cnt].nmembers=0;
	stack[stack_cnt].currmember=0;

	stack[stack_cnt].ptr=0;
	if (userptr) {
		return 0;
	}
	return ptr;
}



void SetParent(char *type, void *parent,  void *val) {
	char *ptype;
	extern int yylineno;
	ptype=XMLGetTopOfStackSname();

	if (strlen(type)==0){ return; }
	if (parent) {
		if (SetParent_overload(ptype,type, parent,  val)) return;
		if (SetParent_fgl(ptype,type, parent,  val)) return;
		//if (SetParent_expr(ptype,type, parent,  val)) return;
		
		printf("Set %s in %p (beleived to be type %s) =%p failed (%d)\n",type,parent,XMLGetTopOfStackSname(), val,yylineno);
		print_stack();
		exit(2);
	} else {
			printf("No parent...\n");
	}
}


void *x_malloc(int n) {
static long cnt=0;
char *ptr;
cnt+=n;
ptr=malloc(n);
if (ptr) return ptr;
printf("Failed to allocate %d more bytes (%ld total)\n", n, cnt);
return 0;
}

#define MAXLRU 100
char *lrulist[MAXLRU];
int init_lru=0;
int last_lru=0;

void do_init_lru() {
	int a;
	for (a=0;a<MAXLRU;a++) lrulist[a]=0;
	init_lru=1;
}

int in_lru(char *p) {
	int a;
	//printf("in lry : '%s'\n",p);
	if (init_lru==0) do_init_lru();
	for (a=0;a<MAXLRU;a++) {
		if (lrulist[a]==0) continue;
		if (strcmp(p,lrulist[a])==0) {
				last_lru=a;
				return 1;
		}
	}
	last_lru=0;
	return 0;
}

char *lru(char *p) {
	int a;
	//printf("lru %s\n",p);
	if (init_lru==0) do_init_lru();
	if (strcmp(p,lrulist[last_lru])==0) { move_lru(last_lru); return lrulist[0]; }
	for (a=0;a<MAXLRU;a++) {
		if (lrulist[a]==0) continue;
		if (strcmp(p,lrulist[a])==0) {
				last_lru=a;
				move_lru(last_lru);
				return lrulist[0];
		}
	}
	A4GL_assertion(1,"SHouldn't happen");
	return 0;
}

void move_lru(int n) {
int a;
char *newone;
	//printf("move_lru %d\n",n);
	//for(a=0;a<MAXLRU;a++) { if (lrulist[a]) printf("B%d. '%s'\n",a,lrulist[a]); }
	if (n==0) return; /* its already there... */
	newone=lrulist[n];
		
	for(a=n;a>0;a--) {
			lrulist[a]=lrulist[a-1];
	}
	lrulist[0]=newone;
	//for(a=0;a<MAXLRU;a++) { if (lrulist[a]) printf("A%d. '%s'\n",a,lrulist[a]); }

}

void add_lru(char *p) {
	int a;
	for (a=0;a<MAXLRU;a++) {
			if (lrulist[a]==0) {
				lrulist[a]=p;
				return;
			}
		}
	lrulist[MAXLRU-1]=p;
	move_lru(MAXLRU-1);
}

#undef strdup
char *x_strdup(char *p) {
	char *ptr;

	//return strdup(p);
	if (p==0) return 0;

	if (in_lru(p)) {
			//printf("Reuse %s\n", lru(p));
			return lru(p);
	}
	ptr=strdup(p); /* x_malloc(strlen(p)+1); */
	if (ptr==0) {
			printf("\n\nUnable to allocate memory\n");
			perror("");
			exit(2);
	}
	//printf("Dont reuse %s\n",p);
	add_lru(ptr);
	return ptr;
}

