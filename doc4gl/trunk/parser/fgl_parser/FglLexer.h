
#ifndef FGL_LEXER_H
#define  FGL_LEXER_H

class FglLexer {
	private:
    int sql_mode;
    int idents_cnt;
    /**
     * Current 4gl source file line number 
     */
    int yylineno;		
    int lastlex;
    /** Flag to help inside c ans SQL code parsing */
    int xccode; 
    int word_cnt;
    /** 
     * Current line read so far, incl. CR/LF 
     */
    char yyline[2000];	
    /**
     * Length of current line
     */
    int yyline_len;		  
    /**
     * FIle position of start of current line 
     */
    long yyline_fpos;		
    #define MAX_XWORDS 1024
    char xwords[MAX_XWORDS][256];
    char idents[256][256];
    struct s_kw *kwords;
    /** 
     * Current state to help in the identifier problem 
     * @todo : This is just assigned. No other usage.
     */
    int current_yylex_state;
    /**
     * Flag that indicate that we want to trace the returned tokens
     * from the lexer to the syntax parser.
     */
    char traceTokens;
    
    /** A reference to the memfile object used */
		// @todo : Make a setter to this
    MemFile *memFile;
    void lexer_ungetc (int a);
    int isident (char *p);
    void ccat (char *s, char a, int instr);
    int isnum (char *s);
    char *read_word2 (int *tokenType);
    char *read_word (int *tokenType);
    int words (int cnt, int pos,char *p);
    char *mk_word (int c);
    int get_hash_val (char *s);
    int chk_word_more (char *buff, char *p, char *str, int tokenType);
    int chk_word (char *str);
    void to_lower_str (char *s);
    void fix_bad_strings (char *s);
    void turn_state_all (int kw, int v, int arr);
    int lexer_fgetc (void);
    char *A4GL_translate (char *s);

  public :
		~FglLexer();
		FglLexer();
    void set_namespace (char *s);
    void setMemFile(MemFile *_memFile);
    int yyLex (void *pyylval, int yystate, short *yys1, short *yys2);
    void turn_state (int kw, int v);
    void setTraceTokens(char _traceTokens);
};

#endif
