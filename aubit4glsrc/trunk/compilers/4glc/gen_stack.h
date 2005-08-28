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

#ifdef GEN_STACK_HERE
char **gen_stack_ptr[GEN_STACKS];
int gen_stack_cnt[GEN_STACKS];
int gen_stack_alloc[GEN_STACKS];
#else
//extern char **gen_stack_ptr[GEN_STACKS];
//extern int gen_stack_cnt[GEN_STACKS] ;
//extern int gen_stack_alloc[GEN_STACKS];
#endif

void A4GL_4glc_push_gen (int a, char *s);
int A4GL_4glc_gen_cnt(int a);
void A4GL_4glc_clr_gen(int a);
char *A4GL_4glc_get_gen(int a,int n);
void A4GL_4glc_pop_all_gen (int a, char *s);
void A4GL_4glc_copy_gen (int a, int b);
void A4GL_init_gen_stack(void);
void A4GL_4glc_dump_updvals (void);
#endif
