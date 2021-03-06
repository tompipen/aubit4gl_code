
#ifdef __cplusplus
extern "C"
{
#endif
  void popquote (char *s, int size);
  void popstring (char *s, int size);
  void retquote (char *s);
  void retint (int a);
  void retflo (float *a);
  void pushint (int a);
  void A4GL_strip (char *s);

  void retshort (short x);
  void poplong (long *x);
  void retlong (long x);
  void pushquote (char *x, int y);
  void popint (int *x);
  void popshort (short *x);
  void retstring (char *str);


  void pushshort (short x);
  void pushlong (long x);
  void popvchar (char *x, int y);
  void retdub (double *x);

  void popdec(void *x);
  void retdec(void *x);
  void popdtime(void *x);
  void retdtime(void *x);



#ifdef __cplusplus
}
#endif
