
#ifdef __cplusplus
extern "C" {
#endif
void popquote(char *s,int size);
void retquote(char *s);
void retint(int a);
void retflo(float *a);
//void rsetnull(int d,void *ptr);

void retshort(short x);
void poplong(long* x);
void retlong(long x);
void pushquote(char* x, int y);
void popint(int* x);
void popshort(short* x);
void retstring(char* str);

#ifdef __cplusplus
}
#endif
