/*
#  ============================================================================ 
#
#  DESPODATA - Lisboa, PORTUGAL
#                                                        
#  $Revision: 1.2 $
#  $Date: 2003-01-02 10:15:54 $
#
#  Programa      : Parser de 4gl para carregamento de informação sobre os
#   módulos num repositório relacional
#  ---------------------------------------------------------------------------
#  DESCRICAO: Carregam a informação dentro de uma estrutura em memória
#
#  ---------------------------------------------------------------------------
#  NOTAS: 
#    Tem de se dar uma volta no processamento da tabela de simbolos
#    para simplificar a insercao
#
#  ============================================================================ 
*/


#define GLOBAIS   /* As variaveis globais pertencem a este modulo */

#include <stdio.h>
#include <ctype.h>
#include <varargs.h>

/* Gnu getopt */
#include <getopt.h>

/* Inseridos para funcionar com gcc */
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "p4gl_symtab.h"

/*
 * Variable and symbol table initialization and parameters (with getopt)
 */

InitP4gl(argc,argv)
int argc;
char *argv[];
{
	int c;
	extern char *optarg;
	extern int ID_Modulo;
	char existe_ficheiro;

	/* Para utilização do gnu getopt */
	int this_option_optind = optind ? optind : 1;
  int option_index = 0;
	/* Estrutura para getopt_long */
	static struct option long_options[] =
  {
    {"file", 1, 0, 'f'},
    {"database", 1, 0, 'b'},
    {"debug", 0, 0, 'd'},
    {"verbose", 0, 0, 'v'},
    {"insert", 0, 0, 'i'},
    {"warning_level", 1, 0, 'w'},
    {"help", 0, 0, 'h'},
    {"document", 0, 0, 'c'},
    {"std_comment", 0, 0, 's'},
    {"document_directory", 1, 0, 'l'},
    {"package", 1, 0, 'p'},
    {"repository_options", 1, 0, 'o'},
    {0, 0, 0, 0},
	};

	ID_Modulo                = 0;
	P4glCb.idx_funcoes       = 0;
	P4glCb.idx_globais       = 0;
	P4glCb.ha_erros          = 0;
	existe_ficheiro          = 0;
	verbose                  = 0;
	InsertInDatabase         = 0;
	InLimbo                  = 1;
	InGlobals                = 0;
	InInclude                = 0;
	InRecord                 = 0;
	WarningLevel             = 0;
	DBConnected              = 0;
	IdxTabLikeStack          = 0;
	TabLikeStack             = (char **)0;
	DimTabLikeStack          = 0;
	repositoryFormat         = P4GL;
	generateFglDoc           = 0;
	standardComments         = 0;
	P4glCb.docFileDir        = ".";
	P4glCb.numFglDoc         = 0;
	P4glCb.errorToDb         = 0;
	P4glCb.currFglDoc = (StringBuffer *)constructStringBuffer();
	strcpy(P4glCb.package,".");
	initStringBuffer(P4glCb.currFglDoc);
	initDatabase();

	/* Variaveis temporarias para passagem de valores entre regras */
	/* Lixo para remover quando se implementar o $$ na maioria das regras */
	Variaveis = (VARS *)0;


	/* while ( (c=getopt(argc,argv,"f:dviw:h?csl:p:b:")) != -1) */
	while ( ( c = getopt_long (argc, argv, "f:dviw:h?csl:p:b:",
                        long_options, &option_index) ) != -1)
	{
		switch(c)
		{
			case 'f':                                       /* File */
				strcpy(FicheiroInput,optarg);
				existe_ficheiro = 1;
				break;

			case 'd':                                       /* Debug mode */
				dbug = 1;
				break;

			case 'v':                                       /* Verbose mode */
				verbose = 1;
				break;

			case 'i':                                       /* Repository Insert */
				InsertInDatabase = 1;
				break;

			case 'w':                                  /* Warning level */
				WarningLevel = atoi(optarg);
				break;

			case 'b':                                  /* Database Name */
				strcpy(P4glCb.database,optarg);
				break;

			case 'c':                                  /* Documentation generation*/
				generateFglDoc = 1;
				break;

			case 's':                                  /* Use standard comments */
				printf("Standard comments\n");
				standardComments = 1;
				break;

			case 'l':                            /* Documentation dir (location)*/
				P4glCb.docFileDir = (char *)malloc(strlen(optarg+1));
				strcpy(P4glCb.docFileDir,optarg);
				break;


			case 'p':                                       /* Package */
				strcpy(P4glCb.package,optarg);
				break;

			case 'o':                                       /* Package */
				insertRepositoryOptions(optarg);
				break;

			case 'h':                                  /* Warning level */
			case '?':
				/* Isto não está actualizado */
		    printf(
					 "Usage: p4gl [-h] [-d] [-i] [-v] [-w level] -f filename.4gl\n");
				printf("   -h : Display this help message\n");
				printf("   -d : Debug mode\n");
				printf("   -i : Insert in the repository\n");
				printf("   -v : Verbose mode\n");
				printf("   -w : Warning level (1..10)\n");
				printf("   -c : Generate documentation\n");
				printf("   -s : Use standard comments for documentation\n");
				printf("   -p package : Name of the package\n");
		        exit(0);
		  /* Help */
		  /* case 'E'  :  Only pre-processing */
		  /* case  L   :  Do NOT load symbol table */
		  /* Load only some objects */
		  /* case '?':     Option not valid */
		  /* case ':':     Missing option   */

		}
	}

	if ( ! existe_ficheiro ) {
		printf ("p4gl: nothing to do - try 'p4gl -h' for help\n");
		exit(0);
	}

	P4glVerbose("4gl Pre-Processing\n");
	GetDirectoryFromFile(); 
	P4glVerbose("Directory %s\n",FileDirectory);
	P4glPreProcessing();
	OpenInputFile();              /* Abrir o source 4gl (parametro)      */
	yyin = fin_ptr;
	OpenLogFile();

	InitSymtab();                 /* Inicializacao da tabela de simbolos */
}


/**
 * Inicializa o nome da base de dados a partir do conteudo da
 * variável de ambiente DATABASE
 */
initDatabase()
{
  if ( getenv("DATABASE") == NULL )
    strcpy(P4glCb.database,"p4gl_repository");
	else
    strcpy(P4glCb.database,getenv("DATABASE"));
	if ( P4glCb.database[0] == '\0' || strlen(P4glCb.database) == 0 )
    strcpy(P4glCb.database,"p4gl_repository");
}


/*
 * PreProcessa o source de 4gl efectuando a copia dos ficheiros incluidos
 * para um temporario.
 *
 * Falta enviar mais um nome de ficheiro onde serao esritos alguns valores para
 * alocacao de memoria obtidos na primeira passagem.
 */
P4glPreProcessing() 
{
   char comand[512];

	// Tenho de retirar isto
	FicheiroTemp  = tmpnam((char *)0);
	FicheiroParam = (char *)malloc(strlen(FicheiroTemp)+4);
	/* Devia existir uma inicializacao do dbug para html
	if ( dbug ) printf("Ficheiro pre-processado %s\n", FicheiroTemp);
	*/
	sprintf(FicheiroParam,"%s.par",FicheiroTemp);
	sprintf(comand,"p4glpp %s %s %s", FicheiroInput,FicheiroTemp,FicheiroParam);
	/* Tem de se testar o exit status e um novo argumento para verificar se nao
		conseguiu resolver o include */
   if ( system(comand) )
		P4glError(ERROR_EXIT,"Unable to Pre-process source (%s)\n",FicheiroInput);
}

/*
 *  Get the directory name and path of the file being parsed
 */
GetDirectoryFromFile()
{
   register short i;
	short len;
	char *substr();
	char *PathDirectory;

	len = strlen(FicheiroInput);
	/* 1 - Ver se o nome do ficheiro ja traz a directoria ou apenas file name */
	for (i = len ; i >= 0 ; i--)
	{
      if ( FicheiroInput[i] == '/' )
		{
			if ( FicheiroInput[0] == '/' )
			{
            PathDirectory = substr(FicheiroInput,0,i-1);
	         GetDirName(PathDirectory);
				free(PathDirectory);
				return;
			}
		   /* Concatenar o pwd com o resto */
			PathDirectory = strcat(getcwd((char *)0,256),
							           substr(FicheiroInput,0,i-1));
			GetDirName(PathDirectory);
			free(PathDirectory);
		   return;
		}
	}
	/* Nao descobriu /, portanto a directoria eh o pwd */
	PathDirectory = getcwd((char *)0,256);
	GetDirName(PathDirectory);
	free(PathDirectory);
}

/*
 * Get Dir Name from dir Path
 * It saves complete path name of the file being parsed
 */
GetDirName(DirPath)
char *DirPath;
{
   register short i;
	short len;

	RClipp(DirPath);
	FilePath = (char *)malloc(strlen(DirPath)+strlen(FicheiroInput)+2);
	sprintf(FilePath,"%s/%s",DirPath,FicheiroInput);
	len = strlen(DirPath);
	for ( i = len ; i > 0 ; i-- )
	{
		if ( DirPath[i] == '/' )
		{
			strcpy(FileDirectory,DirPath+i+1);
			return;
		}
	}
	strcpy(FileDirectory,DirPath);
}


/*
 * Inicializacao de toda a estrutura de controlo 
 * Esta funcao e muito lenta.
 *
 * Se a tabela de simbolos for mudada para listas ordenadas fica muito mais
 * rapido.
 *
 * A proxima versao vai passar a trabalhar com alocacao dinamica de valores
 * obtidos na primeira passagem.
 */

InitSymtab()
{
   register int  i,j;
	FILE          *FlPtrParam;
	char          str[128];

	P4glVerbose("Initializing\n");

	P4glCb.variaveis_mod = (VARS *)0;
	P4glCb.var_globais   = (VARS *)0;
	P4glCb.UtilGlob      = 0;
	P4glCb.idx_var_glob  = 0;


	FlPtrParam = fopen(FicheiroParam,"r");
	if (FlPtrParam == (FILE *)0)
	  P4glError(ERROR_EXIT,"Unable to read parameter file (%s)\n",FicheiroParam);
	if (fgets (str, 80,  FlPtrParam) == NULL) 
	  P4glError(ERROR_EXIT,"Format error in parameter file\n");
	for ( i = 1 ; str[i] != '\0' && str[i] != '=' ; i++);
	P4glCb.NumFunc = atoi(str+i+1);
	fclose(FlPtrParam);

	P4glCb.functions     = calloc(P4glCb.NumFunc, sizeof(FUNCTION));

	/* Em principio o calloc mete tudo a zeros 
	for ( i = 0 ; i < MAXFUNC ; i++ )
		FUNCAO(i).idx_parametros = 0; 
	for ( j = 0 ; j < MAXFUNC ; j++ )
	{
		FUNCAO(j).var_usage = (VAR_USAGE *)0;
      FUNCAO(j).idx_function_call = 0;
	   FUNCAO(j).idx_sql           = 0;
	   for ( i = 0 ; i < MAXSQL ; i++ )
	   {
         IDX_TAB(j,i)           = 0;
         SQL_STMT(j,i).operacao = 0;
         SQL_STMT(j,i).cursor   = -1;
	   }
   }
	*/
}

/* ========================= ABRIR E FECHAR FICHEIROS  
 */

/* 
 * Abre o source de 4gl
 */
OpenInputFile()
{
  fin_ptr = fopen(FicheiroTemp,"r");
  if ( fin_ptr == ((FILE *)0 ))
  {
	 fprintf(stderr,"Erro a abrir ficheiro do source (.4gl) : <%s>\n",
				FicheiroTemp);
	 perror("ERRO");
	 exit(1);
  }
}

/*
 * Abre o ficheiro onde os erros de sintaxe vao ficar acumulados 
 */
OpenLogFile()
{
  char logfile[64];
  char logdir[35];

  if ( getenv("LOGDIR") != NULL )
    strcpy(logdir,getenv("LOGDIR"));
  else
    strcpy(logdir,"/tmp");

  if (logdir[0] == '\0' )
  {
		P4glWarning(DISPENSAVEL,
	     "Variavel de ambiente <LOGDIR> nao esta preenchida (default /tmp)\n");
	 strcpy(logdir,"/tmp");
  }

  sprintf(logfile,"%s/p4gl.log",logdir);

  Log = fopen(logfile,"a");
  if ( Log == ((FILE *)0 ))
  {
	 fprintf(stderr,"Erro a abrir ficheiro log <%s>\n",logfile);
	 exit(1);
  }
}


/*
 * Insert all variable(s) usage in the list at the symbol table
 */
StInsVarListDeclaration(List,DataType)
NAME_LIST *List;
char      *DataType;
{
   register int i;

	if ( InRecord )       /* Sub-variables are not inserted!...yet */
		return;

	for (i = 0 ; i < List->idx ; i++ )
    StInsVarDeclaration(List->nome[i],DataType,List->line[i]);
  CleanNameList(List);
}

/* 
 * Insere uma variavel dentro de um array dinamico que se nao estiver 
 * inicializado e-o.
 * Aloca o espaco para cada nome dinamicamente
 * Aqui ainda nao tem o tipo
 * Numa primeira fase so me interessa o nome de variaveis 
 *     (Sub-variaveis de records nao servem para nada 
 * Quando chega ao fim da descoberta da funcao tem de afectar o array da funcao
 * com as variaveis locais disponiveis
 */
StInsVarDeclaration(NomeVariavel,DataType,linha)
char *NomeVariavel;
char *DataType;
int  linha;
{

	if ( InGlobals )                        /* Variavel global */
	{
		StInsertGlobalVariableDeclaration(NomeVariavel,DataType,linha);
		return;
	}

	if ( InLimbo )                          /* Variavel modular */
	{
		StInsertModGlobVariableDeclaration(NomeVariavel,linha);
		return;
	}

   if ( Variaveis == (VARS *)0 )           /* Local variable */
	{
		 Variaveis    = (VARS *)calloc(MAXVARS,sizeof(VARS));
		 IdxVariaveis = 0;
	}
	Variaveis[IdxVariaveis].nome        = strdup(NomeVariavel);
	Variaveis[IdxVariaveis].linha       = linha;
	Variaveis[IdxVariaveis].tipo        = strdup(DataType);
	IdxVariaveis++;
	if ( IdxVariaveis >= MAXVARS )
		P4glError(ERROR_EXIT,"Local variable array overflow\n");
}

/*
 * Insercao de variaveis globais ao modulo
 */
StInsertModGlobVariableDeclaration(NomeVariavel,linha)
char *NomeVariavel;
int  linha;
{
  if ( P4glCb.variaveis_mod == (VARS *)0 )
	{
		 P4glCb.variaveis_mod = (VARS *)calloc(MAXGLBVARS,sizeof(VARS));
		 P4glCb.idx_var_mod   = 0;
	}
	P4glCb.variaveis_mod[P4glCb.idx_var_mod].nome= (char *)malloc(
    strlen(NomeVariavel)+1
  );
	strcpy(P4glCb.variaveis_mod[P4glCb.idx_var_mod].nome  , NomeVariavel);
	P4glCb.variaveis_mod[P4glCb.idx_var_mod].linha      = linha;
	P4glCb.variaveis_mod[P4glCb.idx_var_mod].tipo = (char *)0; 
	P4glCb.idx_var_mod++;
	if ( P4glCb.idx_var_mod >= MAXGLBVARS )
		P4glError(ERROR_EXIT,"Modular variable array overflow - Line %d\n",linha);
}

/*
 * Insercao de variaveis globais declaradas 
 */
StInsertGlobalVariableDeclaration(NomeVariavel,DataType,linha)
char *NomeVariavel;
char *DataType;
int  linha;
{
  if ( P4glCb.var_globais == (VARS *)0 )
	{
		 P4glCb.var_globais = (VARS *)calloc(MAXGLBVARS,sizeof(VARS));
		 P4glCb.idx_var_glob   = 0;
	}
	P4glCb.var_globais[P4glCb.idx_var_glob].nome     = (char *)strdup(
    NomeVariavel
  );
	P4glCb.var_globais[P4glCb.idx_var_glob].linha    = linha;
	P4glCb.var_globais[P4glCb.idx_var_glob].tipo     = strdup(DataType);
	if ( InInclude )
	   P4glCb.var_globais[P4glCb.idx_var_glob].tipo_dec = IN_INCLUDE;
	else
	   P4glCb.var_globais[P4glCb.idx_var_glob].tipo_dec = IN_MODULE;
	P4glCb.idx_var_glob++;
	if ( P4glCb.idx_var_glob >= MAXGLBVARS )
		P4glError(ERROR_EXIT,"Global variable array overflow - Line %d\n",linha);
}


/*
 * Found a variable usage.
 *
 * It filter(s) local and modular variable and identifiers nor defined
 * in GLOBAL(s) statement
 */
StInsertVariableUsage(nome,linha,utilizacao)
char *nome;
int  linha;
int  utilizacao;
{
  VAR_USAGE *Next;
  VAR_USAGE *Previous;
	char      Nome[64];

	strcpy(Nome,nome);
	BaseName(Nome);
	/* ??? Isto nao foi testado */
	if ( IsFglInternalVariable(Nome) )
		return;

	/* Podia aproveitar para ver se ha conflito de locais e globais */
  if ( IsLocalVariable(Nome) || IsModuleVariable(Nome))
	{
		/* printf("Utilizacao de variavel local %s\n",Nome); */
		return;
	}
	else
	{
		if (IsGlobalVariable(Nome))
		   P4glCb.UtilGlob++;
		else
			return;
	} 
   /* printf("Utilizacao de variavel global %s\n",Nome);  */

	Next = FUNCAO_CURR.var_usage;
	Previous = Next;
   while (Next != (VAR_USAGE *)0)
	{
		/*printf("Posicionar\n");*/
	   Previous = Next;
		Next = Next->next;
	}
	/*printf("Alocar\n"); */
   Next = (VAR_USAGE *)malloc(sizeof(VAR_USAGE));
	if ( FUNCAO_CURR.var_usage == (VAR_USAGE *)0)
		FUNCAO_CURR.var_usage = Next;
	else
	   Previous->next = Next;
	Next->nome = (char *)malloc(strlen(Nome)+1);
	strcpy(Next->nome,Nome);
	Next->linha      = linha;
	Next->utilizacao = utilizacao;
	Next->next       = (VAR_USAGE *)0;
	/* printf("Utilizacao de global %s\n",Nome); */
}


/*
 * Insert all variable(s) usage in the list at the symbol table
 */
StInsertVariableListUsage(List,utilizacao)
NAME_LIST *List;
int  utilizacao;
{
   register int i;

	for (i = 0 ; i < List->idx ; i++ )
    StInsertVariableUsage(List->nome[i],List->line[i],utilizacao);
  CleanNameList(List);
}

/*
 * Verifica se eh uma variavel local ou nao
 */
IsLocalVariable(nome)
char *nome;
{
  register int i;

  for ( i = 0 ; i < IdxVariaveis ; i++ )
    if (strcasecmp(nome,Variaveis[i].nome)==0)
      return 1;
  return 0;
}

/*
 * Verifica se eh uma variavel global ao modulo ou nao
 */
IsModuleVariable(nome)
char *nome;
{
   register int i;

	/*printf("Vai ve se e global ao modulo \n"); */
   for ( i = 0 ; i < P4glCb.idx_var_mod ; i++ )
	{
	/*printf("Vai comparar %s com %s\n", nome, P4glCb.variaveis_mod[i].nome);*/
		if (strcasecmp(nome,P4glCb.variaveis_mod[i].nome)==0)
			return 1;
	}
	return 0;
}

/*
 * Verifica se eh ou nao uma variavel global 
 */
IsGlobalVariable(nome)
char *nome;
{
   register int i;

   for ( i = 0 ; i < P4glCb.idx_var_glob ; i++ )
	{
		if (strcasecmp(nome,P4glCb.var_globais[i].nome)==0)
			return 1;
	}
	return 0;
}


/*
 * New Cursor declaration
 */
StInsertCursorDeclaration(NomeCursor,Tipo,Prepared)
char *NomeCursor;
int Tipo;
short Prepared;
{
  P4glCb.cursores[P4glCb.idx_cursores].nome = (char *)malloc(
    strlen(NomeCursor)+1
  );
	strcpy(P4glCb.cursores[P4glCb.idx_cursores].nome,NomeCursor);
  P4glCb.cursores[P4glCb.idx_cursores].tipo        = Tipo;
  P4glCb.cursores[P4glCb.idx_cursores].FuncNum     = P4glCb.idx_funcoes;
  P4glCb.cursores[P4glCb.idx_cursores].prepared    = Prepared;

	/* Referencing the cursor at the select statement */
	FUNCAO_CURR.idx_sql--;
	SQL_STMT_CURR.cursor = P4glCb.idx_cursores;
	FUNCAO_CURR.idx_sql++;

   P4glCb.idx_cursores++;
}

/*
 * Insere a utilizacao de um cursor
 */
StInsertCursorUsage(nome,linha,utilizacao)
char *nome;
int  linha;
int  utilizacao;
{
   CUR_USAGE *Next;
   CUR_USAGE *Previous;

	         /* Podia aproveitar para ver se ha conflito de locais e globais */

	Next = FUNCAO_CURR.cur_usage;
	Previous = Next;
   while (Next != (CUR_USAGE *)0)
	{
	   Previous = Next;
		Next = Next->next;
	}
   Next = (CUR_USAGE *)malloc(sizeof(CUR_USAGE));
	if ( FUNCAO_CURR.cur_usage == (CUR_USAGE *)0)
		FUNCAO_CURR.cur_usage = Next;
	else
	   Previous->next = Next;
	Next->nome       = (char *)malloc(strlen(nome)+1);
	strcpy(Next->nome,nome);
	Next->linha      = linha;
	Next->utilizacao = utilizacao;
	Next->next       = (CUR_USAGE *)0;
}




/* 
 * Foi encontrado um define. Deve haver variaveis no array temporario
 * Eh fundamental receber o contexto do define, i.e: 
 *     GLOBALS - Declaracao de variaveis globais
 *     MODULE  - Declaracao de variaveis globais ao modulo
 *     LOCAL   - Declaracao de variaveis locais
 *
 */
Define()
{
   register int i;

   for ( i = 0 ; i < IdxVariaveis ; i++ );
	/*printf("Variavel %s do tipo %d\n",Variaveis[i].nome,Variaveis[i].tipo);*/
 
	 /* Copiar para arrays da tabela de simbolos e reinicializar pointers */
}


/*
 * Insere a declaracao de uma nova funcao na tabela de simbolos
 */
StInsertFunction(FunctionName,ultima_linha,arguments)
char      *FunctionName;
int       ultima_linha;
NAME_LIST *arguments;
{
  char *GetListConcat();

	// ??? Provavelmente não deveria ser assim
	Downshift(FunctionName);

	if (strcmp(FunctionName,"paradarsorte") == 0)
		return;

	if (IsFglFunction(FunctionName))  /* Nao insere funcoes internas */
		return;

	strcpy(P4glCb.functions[P4glCb.idx_funcoes].name,FunctionName);
	P4glCb.functions[P4glCb.idx_funcoes].n_linhas = 
	   P4glCb.functions[P4glCb.idx_funcoes].linha - ultima_linha;
	/* Podem existir funções sem parametros */
	if ( arguments != (NAME_LIST *)0 )
	  FUNCAO_CURR.ParamTxt      = GetListConcat(arguments,",");
	else
	  FUNCAO_CURR.ParamTxt      = (char *)0;
	FUNCAO_CURR.parametros    = arguments;
	FUNCAO_CURR.variaveis     = Variaveis;
	FUNCAO_CURR.idx_var       = IdxVariaveis;
	writeParameterComments(P4glCb.idx_funcoes);
	FUNCAO_CURR.Include       = InInclude;
	FUNCAO_CURR.NInstrucoes   = FunctionStatementCount;
	if ( P4glCb.idx_funcoes >= P4glCb.NumFunc )
		P4glError(ERROR_EXIT,"Function stack overflow %d\n",P4glCb.idx_funcoes);
	P4glCb.idx_funcoes++;
}

/*
 * Insere a linha de declaracao de uma nova funcao na tabela de simbolos
 * Poderia chamar-se StInsertBeginFunction()
 * @todo - Os comentários deviam ser copiados e memória limpa
 */
StInsertLineFunction(linha,functionType)
int linha;
int functionType;
{
	P4glCb.functions[P4glCb.idx_funcoes].linha = linha;
	P4glCb.functions[P4glCb.idx_funcoes].functionType = functionType;
	Variaveis = (VARS *)0;
	IdxVariaveis=0;
	FunctionStatementCount = 0;
	FUNCAO_CURR.fglDoc     = strdup(P4glCb.currFglDoc->buffer);
	/*FUNCAO_CURR.parsedDoc  = (Comment *)0; */
	if ( FUNCAO_CURR.fglDoc != (char *) 0 )
	  FUNCAO_CURR.parsedDoc  = (Comment *)parseComment(FUNCAO_CURR.fglDoc);
	destroyStringBuffer(P4glCb.currFglDoc);
}


/**
 * Escreve os parametros declarados nos comentários associados a cada 
 * parametro.
 * Se o parametro não existir documentado é inserido vazio
 *
 * @param idxFunction Indice da função de que se quer escrever comentários
 */
writeParameterComments(int idxFunction)
{
  Comment    *parsedDoc;
	NAME_LIST  *parametros;
  Parameters *docParameter;
	register int j;

	parsedDoc  = P4glCb.functions[idxFunction].parsedDoc;
	parametros = P4glCb.functions[idxFunction].parametros;

	if ( parametros == (NAME_LIST *)0 )
	  return;

	docParameter = parsedDoc->parameterList;
	
	for ( j = 0 ; j < parametros->idx ; j++ )
		writeParameterToDoc(docParameter,parametros->nome[j],idxFunction);
}

/**
 * Verifica se existe e escreve um parâmetro no comentário de parâmetro 
 * correspondente.
 *
 * @param docParameter Apontador para documentação de parâmetros
 * @param nome Nome do parâmetro descoberto por parsing
 */
writeParameterToDoc(Parameters *docParameter,char  *nome, int idxFunction)
{
  int parameterDocumented;
	register int i;

	parameterDocumented = 0;
	for ( i = 0 ; i < docParameter->idxParameters ; i++ )
  {
	  if ( strcasecmp(nome,docParameter->name[i]) == 0 )
		{
      docParameter->dataType[i] = (char *)getParameterDataType(
			  idxFunction,
			  nome
			);
			parameterDocumented = 1;
		}
  }
  if ( parameterDocumented == 0 )
	{
		addParameter(docParameter,nome,"--");
    docParameter->dataType[docParameter->idxParameters]=
			(char *)getParameterDataType(
			  idxFunction,
			  nome
		);
	}
}

/**
 * Insere um argumento na lista de parametros
 * @param NmArg Nome do argumento da função
 */
StInsertArgument(NmArg)
char *NmArg;
{
  /* ??? Atencao a dimensoes - Deviam ser testadas */
  strcpy(FUNCAO_CURR.parametros->nome[IDX_ARG_CURR],NmArg);
  IDX_ARG_CURR++;
}


/*
 * Insere na tabela de simbolos a execucao de uma funcao 
 */
StInsertFunctionCall(FunctionName,linha)
char *FunctionName;
{
	Downshift(FunctionName);
	if (IsFglFunction(FunctionName))  /* Nao insere funcoes internas */
		return;

	if ( IDX_FC_CURR >= MAXCALL )
	{
		P4glError(ERROR_EXIT,"CALL(s) by function Stack Overflow (%d)\n",MAXCALL);
		return;
	}
   strcpy(FUNCAO_CURR.FunctionCall[IDX_FC_CURR].name,FunctionName);
   FUNCAO_CURR.FunctionCall[IDX_FC_CURR].linha = linha;
   IDX_FC_CURR++;
}

/*
 * Update the type of usage made (Expression, call, etc)
 */
StUpdFCUsage(usage)
char *usage;
{
   FUNCAO_CURR.FunctionCall[IDX_FC_CURR-1].Usage = strdup(usage);
}


/*
 * Insert de utilizacao de tabela no array
 * ??? De futuro serah para desaparecer
 */
StInsertTable(NmTable)
char *NmTable;
{
   strcpy(SQL_STMT_CURR.tabelas[IDX_TAB_CURR],NmTable);
}

StIncrementTable()
{
   IDX_TAB_CURR++;
}

/*
 *  Found an SQL statement
 */
StInsertSQL(operacao,linha)
int  operacao;
int  linha;
{
	SQL_STMT_CURR.operacao = operacao;
	SQL_STMT_CURR.cursor   = -1;
	FUNCAO_CURR.idx_sql++;
}

StInsertSQLTxt(SqlTxt)
char *SqlTxt;
{
	SQL_STMT_CURR.texto = SqlTxt;
}


/*
 * Funcao de comparacao para o qsort ordenar as funcoes 
 */
FuncCmp(f1,f2)
char *f1;
char *f2;
{
   return(strcmp(((FUNCTION *)f1)->name,((FUNCTION *)f2)->name));
}

FunctionCallCmp(f1,f2)
char *f1;
char *f2;
{
   return(strcmp(((FUNC_CALL *)f1)->name,((FUNC_CALL *)f2)->name));
}

/*
 * Orderna os arrays da tabela de simbolos pelo nome
 */
OrderSymtab()
{
   register int i;
   
	 /*
	if (!InsertInDatabase)
		return;
		*/
	P4glVerbose("Symbol table post-treatment\n");
		/* Ordenar lista de funcoes */
   qsort(P4glCb.functions, P4glCb.idx_funcoes,sizeof(FUNCTION),FuncCmp);
	for (i=0 ; i < P4glCb.idx_funcoes ; i++)
	{
		/* Funcoes executadas */
      qsort(P4glCb.functions[i].FunctionCall, 
				P4glCb.functions[i].idx_function_call,
				sizeof(FUNC_CALL),FunctionCallCmp);

		/* Falta utilizacao de tabelas */
	}

	/* Outras modificações */
	P4glCb.module = P4glCb.NmFicheiroInput;
	//strcpy(P4glCb.package,P4glCb.directoria);
	//printf("Package %s\n", P4glCb.package);
}



/*  ========== Funcoes para stack do parser (Union) */

/*
 * Insert a new name in the list. If the original is null
 * it allocates space for it
 */
InsertNameList(Destino,Origem,Nome,Linha)
NAME_LIST **Destino;
NAME_LIST *Origem;
char *Nome;
int Linha;
{
	if ( Origem == (NAME_LIST *)0 )
	{
		*Destino = (NAME_LIST *)malloc(sizeof(NAME_LIST));
		if ( *Destino == (NAME_LIST *)0 )
      fprintf(stderr,"Não há mais memória (InsertNameList)\n");
		(*Destino)->idx = 0;
	}
	else
		*Destino = Origem;
	(*Destino)->nome[(*Destino)->idx] = (char *)malloc(strlen(Nome)+1);
	strcpy((*Destino)->nome[(*Destino)->idx],Nome);
	(*Destino)->line[(*Destino)->idx] = Linha;
	(*Destino)->idx++;
	if ((*Destino)->idx > MAX_NAMES_IN_LIST )
		P4glError(ERROR_EXIT,"List of names Stack Overflow\n");
}

/*
 * Concatenation of the list with a character separator
 */
char *GetListConcat(List, ch)
NAME_LIST *List;
char *ch;
{
   register int i;
	char *Destino;
	int  len;

	len = 0;
	/* Isto se calhar ficava mais eficaz se utiliza-se o realoc */
	for (i = 0 ; i < List->idx ; i++ )
		len += strlen(List->nome[i])+1;

	Destino = (char *)malloc(len + 1);
	Destino[0] = '\0';
	for (i = 0 ; i < List->idx ; i++ )
	{
		if ( i > 0 )
			strcat(Destino,ch);
		strcat(Destino,List->nome[i]);
   }
	return Destino;
}

/*
 * For debugging purpose only 
 */
PrintNameList(List)
NAME_LIST *List;
{
   register int i;

	for (i = 0 ; i < List->idx ; i++ )
		printf("--Nome %s\n",List->nome[i]);
}

/*
 * Clean the dynamic memory allocated for name list
 */
CleanNameList(List)
NAME_LIST *List;
{
   register int i;

   for ( i = 0 ; i < List->idx ; i++ )
		free(List->nome[i]);
   free(List);
}


/*
 * Remocoes diversas
 */
CleanP4gl()
{
	if ( !dbug )
	{
      unlink(FicheiroTemp);
      unlink(FicheiroParam);
	}
	else
		printf("ATENCAO : Temporarios nao foram limpos !\n");
}


/*
 * Carrega na tabela de simbolos a existencia de um GLOBALS por include
 * ??? Isto provavelmente eh lixo
 */
GlobalsInclude(NmFicheiro)
	char *NmFicheiro;
{
	if ( P4glCb.idx_globais >= MAXGLOB )
		P4glError(ERROR_EXIT,"Include stack overflow\n");
	tiraAspas(NmFicheiro);
   strcpy(P4glCb.globais[P4glCb.idx_globais].nome_ficheiro,NmFicheiro);
	P4glCb.idx_globais++;
}


/**
 * Analisa a string relativa a opções de inserção no repositório
 * e configura a estrutura global REP_OPTIONS
 */
insertRepositoryOptions(char *options)
{
  if ( index(options,'t') != NULL || index(options,'T') != NULL )
    P4glCb.repositoryOptions.insertTableUsage = 1;
	/** @todo - Resto das opções de configuração */
}

   

/*
 * It insert(s) a table usage as like 
 */
/*
InsertTabLikeStack(NmTabela)
char *NmTabela;
{
   if 
}
*/
