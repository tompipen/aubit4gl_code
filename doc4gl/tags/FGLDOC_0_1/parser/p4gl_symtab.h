/**
 * @file
 *
 * Moradat - Lisboa, PORTUGAL
 *                                                       
 * Author: Sergio Ferreira
 *                                                       
 * P4gl - Contains Header of all declarations:
 *                           - Symbol table structures
 *                           - DEFINES
 *                           - Global and external variable declaration
 * ---------------------------------------------------------------------------
 * $Id: p4gl_symtab.h,v 1.3 2003-02-04 13:13:13 saferreira Exp $
 */


/* General usage DEFINE(S) */

   /* Maximos */

#define MAXFUNC       512            /* Max functions by module             */
#define MAXCALL       768            /* Max function call in a function     */
#define MAXTAB         64            /* Maximo de tabelas por SQL           */
#define MAXRET         64            /* Maximo de valores de return         */
#define MAXVARS       128            /* Maximo de variaveis locais          */
#define MAXGLBVARS  20000            /* Maximo de variaveis globais modulo  */
#define MAXGLOB         1            /* Maximo de GLOBALS                   */
#define MAXCURS       640            /* Maximo de cursores                  */
#define MAXSQL         50            /* Maximo de instrucoes SQL por funcao */

#define NAO             0
#define SIM             1

#define ERROR_EXIT      0            /* Exit after show the error         */
#define ERROR_NO_EXIT   1            /* Wont exit after showing the error */

                                     /* Is the cursor prepared ?          */
#define  NOT_PREPARED  0
#define  PREPARED      1


/*  ===== Name list general usage structure - it should be in a compiler
 *        general purpose library
 */

#define MAX_NAMES_IN_LIST 128
typedef struct                     /* Stack for Name Lists (parser usage) */
{
   char *nome[MAX_NAMES_IN_LIST];  /* Name discovered                     */
	int  line [MAX_NAMES_IN_LIST];  /* Source line where found             */
	int  type;                      /* Type of name: String, etc           */
	int  idx;
}NAME_LIST;

 
/*  ===== SQL description 
 *     ??? Nao suporta inserts de selects e nested queryes 
 *     ??? Falta associacao de SQL a cursores 
 */
                                     /* SQL statement type                */
#define  SQL_EMBEBIDO  0
#define  SQL_PREPARADO 1
#define  SQL_SELECT    0
#define  SQL_INSERT    1
#define  SQL_UPDATE    2
#define  SQL_DELETE    3

typedef struct {
	 int  tipo;                /* SQL type as defined earlier             */
   char tabelas[MAXTAB][18]; /* Used tables                             */
	 int  idx_tabelas;         /* Number of used tables                   */
	 int  operacao;            /* Operacao efectuada */
	 char *texto;              /* SQL text                                */
	 int  cursor;              /* Linking with the cursor, if so          */
}SQL;

#include "TableUsage.h"

/*  ==== Cursor definition 
 */
                                /* Cursor type */
#define  CURS_SCROLL        0
#define  CURS_NORMAL        1
#define  WITH_HOLD          2
#define  SCROLL_WITH_HOLD   3

typedef struct {
	 int tipo;                 /* Cursor type                             */
	 int transaction;          /* With ou sem hold                        */
    char *nome;               /* Nome do cursor                          */
	 int  FuncNum;             /* Funcao em que e declarado               */
	 int  ID_Cursor;           /* Id do cursor declarado                  */
    short prepared;           /* O cursor e preparado o explicito        */
} CURSORES;                   /* Estrutura de definicao de cada cursor   */

#define IN_MODULE   0         /* Global declared at the module           */
#define IN_INCLUDE  1         /* Global declared in the include file     */
                              /* Definicao (declaracao) de VARIAVEIS     */
typedef struct {
   char *nome;                /* Nome da variavel                        */
	char *tipo;                /* Tipo de variavel, texto                 */
	int linha;                 /* Linha em que e declarada                */
	int id_global;             /* Id (serial) da declaracao das variaveis */
	int tipo_dec;              /* Declaracao explicita ou implicita       */
	/* composta ??? (record ou array ) Logo se ve */
} VARS;
                              /* DEFINICAO DE GLOBALS */
/* Devia ser uma union */
typedef struct {
   char nome_ficheiro[64];    /* Nome do ficheiro de GLOBALS */
	VARS variaveis[128];       /* Numero de variaveis */
} GLOBALS;

                              /* EXECUCAO DE FUNCAO */
typedef struct {
	/* ??? Passar a char * para ser dinamico */
   char name[50];             /* Nome da funcao executada */
	char *Usage;               /* Type of call made        */
	int  linha;                /* Linha em que e executada */
}FUNC_CALL;

#define ASSIGNMENT 1
#define READ_VAR   2 

                              /* Lista de Utilizacao de variaveis em funcao */
struct var_usage{
   char      *nome;           /* Nome da variavel */
	int       linha;           /* Linha em que e utilizada */
	int       utilizacao;      /* Tipo de utilizacao */
	struct var_usage *next;           /* Apontador para proximo elemento */
};
typedef struct var_usage VAR_USAGE;             

#define CURSOR_OPEN    1
#define CURSOR_FETCH   2
#define CURSOR_CLOSE   3
#define CURSOR_PUT     4
#define CURSOR_UPDATE  5
#define CURSOR_FLUSH   6

struct cur_usage{
   char      *nome;           /* Nome do cursor */
	int       linha;           /* Linha em que e utilizada */
	int       utilizacao;      /* Tipo de utilizacao */
	struct cur_usage *next;           /* Apontador para proximo elemento */
};
typedef struct cur_usage CUR_USAGE;             

#include "Comment.h"
                              /* DEFINICAO DE UMA FUNCAO */
typedef struct {
	/* ??? Passar a char * para ser dinamico */
  int       functionType;          /* Tipo de função */
  char      name[50];            /* Nome da funcao */
	int       linha;               /* N.o da linha em que a funcao e declarada */
	NAME_LIST *parametros;           /* Parametros da funcao em lista */
	char      *ParamTxt;             /* Parametros da funcao em texto */
	int       idx_parametros;        /* Indice dos parametros */
	/* ??? E retornos diferentes ??? */
	char      retorno[MAXRET][18];   /* Parametros da funcao */
	int       idx_retorno;
	FUNC_CALL FunctionCall[MAXCALL]; /* Execucao de funcoes */
	int       idx_function_call;     
	VARS      *variaveis;            /* Declaracao de Variaveis locais */
	int       idx_var;               /* Indice de variavel corrente */
	VAR_USAGE *var_usage;            /* lista de utilizacao de variaveis */
	CUR_USAGE *cur_usage;            /* lista de utilizacao de cursores */
	int       n_linhas;              /* N.o total de linhas */
	SQL       sql[MAXSQL];           /* Array de instrucoes de SQL */
	int       idx_sql;               /* Indice de SQL corrente     */
	TableUsage *tableUsage[MAXSQL];   /* Table usage information */
	int       idxTableUsage;         /* Index of table usage */
	int       ID_Function;           /* Serial da funcao na tabela funcao */
	short     Include;               /* Function is included from other file */
	int       NInstrucoes;           /* N.o de instrucoes                    */
	Comment   *parsedDoc;            /* Comentário de documentação */
} FUNCTION;                        /* Definicao de uma Funcao */

/** Opções configuráveis para inserção no repositório (p4gl format)*/
typedef struct {
  short insertTableUsage;          /* Se a 1, inserir utilização de tabelas */
  short insertLocalvariables;      /* Se a 1, inserir variáveis locais */
  short insertStrings;             /* Se a 1, inserir conteudo das strings */
} REP_OPTIONS;
                                /* Estrutura geral de controle de uma source */
typedef struct {
	char     directoria[64];         /* Directoria corrente */
	char     *package;            /* Nome do package */
	char     modulo[64];             /* Nome do source de 4gl */
	char     *module;                /* Nome do source de 4gl */
	char     *database;              /* The repository database name */
	int      numFglDoc;              /* Quantidade já lida de fgldocs */
	Comment  *parsedComment;         /* Comentário de documentação do módulo */
	GLOBALS  globais[MAXGLOB];       /* Globals files and variables           */ 
	int      idx_globais;            /* Indice de variavel global corrente    */
	int      UtilGlob;               /* N.o de utilizacao de globais          */
  VARS     *var_globais;           /* Variaveis globais ao modulo           */
	short    idx_var_glob;           /* Indice de variaveis do modulo         */
  VARS     *variaveis_mod;         /* Variaveis globais ao modulo           */
	short    idx_var_mod;            /* Indice de variaveis do modulo         */
	FUNCTION *functions;            /* Funcoes                               */
  int      idx_funcoes;            /* Indice de funcao corrente             */ 
	int      NumFunc;                /* Funcoes descobertas na 1.a passagem   */
	CURSORES cursores[MAXCURS];      /* Array de cursores                     */ 
	int      idx_cursores;           /* Indice de cursor corrente             */
	char     *NmFicheiroInput;       /* Nome do source 4gl                    */
  char     Directory[64];          /* Directory where the scanned file is */
	char     *NmFicheiroTemp;        /* Temporario depois de Pre-Processado   */
	char     *NmFicheiroTemp2;       /* Temporario de valores obtidos no PP   */
	FILE     *fl_ptr_cod;            /* File Pointer to Code file             */

	char     fl_erros_nm[28];        /* Nome de ficheiro de erros             */
	FILE     *fl_erros_ptr;          /* Pointer para ficheiro de erros        */
	char     *docFileName;            /* Nome de ficheiro de documentação */
	char     *docFileDir;            /* Nome da directoria de documentação */
	FILE     *docFilePtr;            /* Pointer para ficheiro de documentação */
	short    ha_erros;               /* Indica a existencia de erros          */
	short    errorToDb;
	short    insertProcess;          /* Indicate if it should insert the process */
	REP_OPTIONS repositoryOptions;   /* Opções de inserção no repositório */
}P4GLCB;                       /* P4gl Control Block */


typedef struct                   /* Variable declaration information */
{
   char name[256];
	int  line;
	char data_type[256];
}VAR_DECLARATION;


/* ========================  Variable Declaration */

#ifdef GLOBAIS
#   define EXTE 
#else
#   define EXTE extern
#endif

EXTE short  verbose;            /* Verbose mode flag      */
EXTE int    exit_stat;
EXTE FILE   *fin_ptr;
EXTE FILE   *fout_ptr;
EXTE int    dbug;
EXTE VARS   *Variaveis;        /* Lista corrente de variáveis declaradas */
EXTE int    IdxVariaveis; 
EXTE FILE   *Log;               /* Ficheiro onde os erros vao ser acumulados */
EXTE P4GLCB P4glCb;             /* P4gl Symbol Table (Entry point structure) */
EXTE short  InsertInDb;         /* Repository insert mode */
EXTE int    back_lineno;      /* YYlineno backup for file inclusion        */
EXTE char   *FilePath;          /* Complete path of the file being parsed    */
/*
EXTE VARS   *var_declaradas;    
EXTE int    idx_var_dec;       
*/
EXTE int   InsertInDatabase;    /* Repository Insert Mode */

                                /* Flags de posicionamento no source    */
EXTE short  InInclude;          /* Esta dentro de GLOBALS dum include   */
EXTE short  InGlobals;          /* Esta dentro de GLOBALS...END GLOBALS */
EXTE short  InLimbo;            /* Esta fora de funcoes e globals       */
EXTE short  InRecord;           /* Dentro de um record                  */

EXTE short  DBConnected;        /* Connect to the database (True/false) */

/* Lista de tabelas usadas em like(s). Convem ser dinamico */
#define     MAX_BLOCK_STACK 100
EXTE char **TabLikeStack;
EXTE short  IdxTabLikeStack;
EXTE short  DimTabLikeStack;
EXTE long   FunctionStatementCount;

/* Definicoes para definicao de importancia de erros e avisos */
#define     IMPORTANT    0         /* Muito importantes */
#define     ERR_MEDIUM 1         /* Importancia media */
											 /* O p4gl consegiu safar-se*/
#define     DISPENSAVEL  2         /* Dispensaveis */
#define     ERR_DEFAULTS 6         /* Environment defaults set */

/* Definição de tipos de repositório */
#define INSLIB  0
#define P4GL    1

EXTE int repositoryFormat;

/** Define se deve ou não gerar os documentos */
EXTE int generateFglDoc;

/** Define se se usa os comentários standard do 4gl para documentação */
EXTE int standardComments;

EXTE short  WarningLevel;       /* Verbose and Warning detail display level */

/** Tipos de função */
#define FUNCTION_TYPE 0
#define REPORT_TYPE   1

	/* Temporarias para stack de descobertas */
/*
#ifndef GLOBAIS
	extern int TipoVariavel; 
#endif
*/

						 /* Para o lex trabalhar bem */
extern FILE *yyin; /* File pointer para o ficheiro .4gl que ja esta aberto */

/* Macros para utilizacao de tabela de simbolos */

#define FicheiroInput  P4glCb.NmFicheiroInput
#define FileDirectory  P4glCb.Directory
#define FicheiroTemp   P4glCb.NmFicheiroTemp
#define FicheiroParam  P4glCb.NmFicheiroTemp2
 
#define FUNCAO(li)    (P4glCb.functions[li])
#define FUNCAO_CURR   (P4glCb.functions[P4glCb.idx_funcoes])
#define IDX_ARG_CURR  (P4glCb.functions[P4glCb.idx_funcoes].idx_parametros)
#define IDX_ARG(li)   (P4glCb.functions[li].idx_parametros)

#define IDX_FC(fu)    (P4glCb.functions[fu].idx_function_call)
#define IDX_FC_CURR   (P4glCb.functions[P4glCb.idx_funcoes].idx_function_call)
#define FUNC_CALL(fu,fc) (P4glCb.functions[fu].FunctionCall[fc])

#define SQL_STMT(fu,idx)     (P4glCb.functions[fu].sql[idx])
#define SQL_STMT_CURR        (FUNCAO_CURR.sql[FUNCAO_CURR.idx_sql])
#define IDX_TAB(fu,idx)      (FUNCAO(fu).sql[idx].idx_tabelas)
#define IDX_TAB_CURR         (FUNCAO_CURR.sql[FUNCAO_CURR.idx_sql]).idx_tabelas
