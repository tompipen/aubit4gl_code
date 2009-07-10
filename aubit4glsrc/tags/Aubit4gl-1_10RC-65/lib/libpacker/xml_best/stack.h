void XMLPushOntoStack(char *sname, int sz,int nmembers,void *userptr,int from_where,char *parent_element) ;
char *XMLGetTopOfStackSname (void) ;
void *XMLGetTopOfStack (void) ;
void *XMLGetTopOfStackUserptr (void) ;
int XMLGetTopOfStackNmembers (void) ;
int XMLReallocateStack(char *sname, int nmembers) ;
void *XMLPopOffStack(char *sname, int retain) ;
int XMLGetTopOfStackcurrent_subscript(char *sname) ;
int XMLSetTopOfStackcurrent_subscript(char *sname, int n) ; 
char *XMLGetTopOfStackParentElem(void);

int ChkTopOfStack(char *s) ;

int SetParent_overload(char *type, char *element, void *parent,  void *val);
int SetParent_cmds(char *type, char *element, void *parent,  void *val);
int SetParent_expr(char *type, char *element, void *parent,  void *val);
char *x_strdup(char *p);
#define strdup x_strdup
