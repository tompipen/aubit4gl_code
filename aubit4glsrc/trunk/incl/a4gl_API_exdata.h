#ifdef __cplusplus
extern "C" {
#endif

	/* ============================ from datatypes.c ============================ */
	void    init_datatypes			(void);
	void *  get_datatype_function_n	(char *name,char *funcname);
	int     has_datatype_function_n	(char *name,char *funcname);
	int     A4GLEXDATA_initlib 		(char *f);
	int     find_datatype_out		(char *name);
	int 	find_datatype			(char *name);
	void *  get_datatype_function_i	(int a,char *funcname);
	int     has_datatype_function_i	(int a,char *funcname);
	int 	add_datatype 			(char *name, int rq, int precision);
	int 	add_datatype_function_n (char *name, char *funcname, void *func);
	void 	add_conversion 			(char *from, char *to, void *func);
	/* ============================ end from datatypes.c ============================ */


#ifdef __cplusplus
}
#endif
