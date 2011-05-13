

#ifdef __GNUC__
void __attribute__ ((format(printf, 1, 2) )) printc(char *fmt, ...);
void __attribute__ ((format(printf, 1, 2) )) printh(char *fmt, ...);
#else
void printc(char *fmt, ...);
void printh(char *fmt, ...);
#endif


void dump_comments (int n) ;

