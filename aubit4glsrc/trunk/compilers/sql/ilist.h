struct ilist {
	int i0;
	int i1;
	int i2;
	int i3;
	int i4;
	int i5;
} ;


#ifdef YYLEX_PARAM
	//YYLEX yylex (YYLEX_PARAM);
	int yylex (YYLEX_PARAM);
#else
	//YYLEX yylex ();
	int yylex (void);
#endif
