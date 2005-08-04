#ifndef GEN_STACK_H
#define GEN_STACK_H
#define UPDCOL 0
#define UPDVAL 1
#define PUTVAL 3
#define UPDVAL2 4
#define INSCOL 5
#define INSVAL 6
#define TCOL 7
#define GEN_STACKS                10
#define GEN_STACK_SIZE 10000

#define GEN_STACK_ELEM_SIZE 20480

#ifdef GEN_STACK_HERE
char gen_stack[GEN_STACKS][GEN_STACK_SIZE][GEN_STACK_ELEM_SIZE];
int gen_stack_cnt[GEN_STACKS] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
#else
extern char gen_stack[GEN_STACKS][GEN_STACK_SIZE][GEN_STACK_ELEM_SIZE];
extern int gen_stack_cnt[GEN_STACKS] ;
#endif

void push_gen (int a, char *s);


#endif
