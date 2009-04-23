#ifndef A4GL_EXDATA_H
#define A4GL_EXDATA_H
#ifdef __cplusplus
extern "C"
{
#endif

  /* ============================ from datatypes.c ============================ */
  void A4GL_init_datatypes (void);
  void *A4GL_get_datatype_function_n (char *name, char *funcname);
  int A4GL_has_datatype_function_n (char *name, char *funcname);
  int A4GLEXDATA_initlib (char *f);
  int A4GL_find_datatype_out (char *name);
  int A4GL_find_datatype (char *name);
  void *A4GL_get_datatype_function_i (int a, char *funcname);
  int A4GL_has_datatype_function_i (int a, char *funcname);
  int A4GL_add_datatype (char *name, int rq, int precision);
  int A4GL_add_datatype_function_n (char *name, char *funcname, void *func);
  void A4GL_add_conversion (char *from, char *to, void *func);
  /* ============================ end from datatypes.c ============================ */


#ifdef __cplusplus
}
#endif
#endif
