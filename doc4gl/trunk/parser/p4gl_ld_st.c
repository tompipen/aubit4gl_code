/**
 * @file
 * Loading of the abstract tree.
 *
 * Most of the functions included in this module are called by the parser.
 *
 * The abstract tree does not have all information of 4gl file. Its only
 * a sub-set documentation oriented.
 *
 * @todo : Break this module in severall, for each type of function
 */

/*
 *
 * Moredata - Lisboa, PORTUGAL
 *                                                       
 * $Author: saferreira $
 * $Revision: 1.4 $
 * $Date: 2003-02-05 12:45:13 $
 *                                                       
 * Programa      : Carregamento de informação sobre os módulos numa arvore
 *                 abstracta em memoria
 *
 * ---------------------------------------------------------------------------
 * @todo : Tem de se dar uma volta no processamento da tabela de simbolos
 *   para simplificar a insercao
 *
 */


#define GLOBAIS   /* As variaveis globais pertencem a este modulo */

#include <stdio.h>
#include <ctype.h>
#include <varargs.h>

/* Inseridos para funcionar com gcc */
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "p4gl_symtab.h"
#include "p4gl.h"

/** 4GL Source current line */
extern int lineno;            


/**
 * PreProcess the 4gl source file making a copy of the files included in the
 * 4gl to a temporary one.
 *
 * @todo : Send a name of a file where the values should be writed so the 
 *         memory allocation be obtained in the first pass.
 */
void P4glPreProcessing(void) 
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

/**
 * Initialize the control structure and abstract information tree.
 *
 * @todo : A proxima versao vai passar a trabalhar com alocacao dinamica de 
 * valores obtidos na primeira passagem.
 */
void initSymtab(void)
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

	P4glCb.functions = calloc(P4glCb.NumFunc, sizeof(FUNCTION));
}

/**
 * Insert a modular variable declaration.
 *
 * @param NomeVariavel The string containing the variable name
 * @param linha The line in source code where the declaration was found
 */
static void StInsertModGlobVariableDeclaration(char *NomeVariavel,int linha)
{
	defineOrGlobalsOcurred();
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

/**
 * Insert a new global variable declaration
 *
 * @param NomeVariavel The string containing the variable name
 * @param DataType The String containing the data type of the variable
 * @param linha The line in source code where the declaration was found
 */
static void StInsertGlobalVariableDeclaration(
  char *NomeVariavel,char *DataType,int linha)
{
	defineOrGlobalsOcurred();
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

/**
 * Insert a variable inside an dynamic array.
 * If the array is not initialized do it e alocate the space for each name.
 *
 * Aqui ainda nao tem o tipo
 * Numa primeira fase so me interessa o nome de variaveis 
 *     (Sub-variaveis de records nao servem para nada 
 * Quando chega ao fim da descoberta da funcao tem de afectar o array da funcao
 * com as variaveis locais disponiveis
 *
 * @param NomeVariavel The string containing the variable name
 * @param DataType The string containing the data type 
 * @param linha The line where found in source code
 */
static void StInsVarDeclaration(char *NomeVariavel,char *DataType,int linha)
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

/**
 * Clean the dynamic memory allocated for name list
 *
 * @param List The list to be cleaned
 */
void CleanNameList(NAME_LIST *List)
{
   register int i;

   for ( i = 0 ; i < List->idx ; i++ )
		free(List->nome[i]);
   free(List);
}

/**
 * Insert all variable(s) usage in the list at the symbol table
 *
 * @param List The name list pointer
 * @param DataType The string identifiing the data type
 */
void StInsVarListDeclaration(NAME_LIST *List,char *DataType)
{
   register int i;

	if ( InRecord )       /* Sub-variables are not inserted!...yet */
		return;

	for (i = 0 ; i < List->idx ; i++ )
    StInsVarDeclaration(List->nome[i],DataType,List->line[i]);
  CleanNameList(List);
}

/**
 * Checks if a variable is local 
 *
 * @param nome The name of the variable to be checked
 * @return 1 : Is a local variable
 *         0 : Its not a local variable
 */
static int IsLocalVariable(char *nome)
{
  register int i;

  for ( i = 0 ; i < IdxVariaveis ; i++ )
    if (strcasecmp(nome,Variaveis[i].nome)==0)
      return 1;
  return 0;
}

/*
 * Checks if a variable is modular
 *
 * @param The name of the variable to be checked
 * @return 1 : The variable is modular
 *         0 : The variable its not modular
 */
static int IsModuleVariable(char *nome)
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

/**
 * Checks if a variable is global
 *
 * @param The variable name
 * @return 1 : The variable is global
 *         0 : The variable its not global
 */
static int IsGlobalVariable(char *nome)
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
 * Found a variable usage.
 *
 * It filter(s) local and modular variable and identifiers nor defined
 * in GLOBAL(s) statement
 *
 * @param nome The variable name found
 * @param linha The line where the usage was found
 * @param utilizacao The type of the usage made
 */
void StInsertVariableUsage(char *nome,int linha,int utilizacao)
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
 *
 * @param List The list to append with variable usage
 * @param The Type of usage made
 */
void StInsertVariableListUsage(NAME_LIST *List,int utilizacao)
{
   register int i;

	for (i = 0 ; i < List->idx ; i++ )
    StInsertVariableUsage(List->nome[i],List->line[i],utilizacao);
  CleanNameList(List);
}


/**
 * Found a new cursor declaration by the parser
 *
 * @param NomeCursor The cursor name found
 * @param Tipo The type of the cursor
 * @param Prepared A flag that identifies if its or not prepared
 */
void StInsertCursorDeclaration(char *NomeCursor,int Tipo,short Prepared)
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

/**
 * Insert the usage of a cursor in the abstract tree.
 * The parser found  acursor usage.
 *
 * @param nome The cursor name
 * @param linha The line where the cursor was found
 * @param utilizacao The type of the usage made
 *
 */
void StInsertCursorUsage(char *nome,int linha,int utilizacao)
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
 * The parser have found a complete define for variable declarations.
 *
 * We have the information of variables in an array made for this purpose.
 *
 * For now just dont do anything.
 *
 */
void defineFound(void)
{
   register int i;

   for ( i = 0 ; i < IdxVariaveis ; i++ );
	/*printf("Variavel %s do tipo %d\n",Variaveis[i].nome,Variaveis[i].tipo);*/
 
	 /* Copiar para arrays da tabela de simbolos e reinicializar pointers */
}

/**
 * Verifies if exist and write one parameter in the corresponding comment.
 *
 * @param docParameter Pointer to the parameter document
 * @param nome The name found to the parameter
 */
static void writeParameterToDoc(
	Parameters *docParameter,char  *nome, int idxFunction)
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
 * Write the declared parameters in fgldoc comments with \@param
 *
 * @param idxFunction The index of the function for where we want to write the
 *                    comments
 */
static void writeParameterComments(int idxFunction)
{
  Comment    *parsedDoc;
	NAME_LIST  *parametros;
  Parameters *docParameter;
	register int j;

	parsedDoc  = P4glCb.functions[idxFunction].parsedDoc;
	parametros = P4glCb.functions[idxFunction].parametros;

	if ( parametros == (NAME_LIST *)0 )
	  return;

	if ( parsedDoc == (Comment *)0 )
	  return;

	docParameter = parsedDoc->parameterList;
	
	for ( j = 0 ; j < parametros->idx ; j++ )
		writeParameterToDoc(docParameter,parametros->nome[j],idxFunction);
}

/**
 * Fill the table usage for the current function based on the information on the
 * SQL array and (or) comment table tag.
 *
 * @param function Pointer to the function identification structure.
 */
static void fillTableUsage(FUNCTION *function)
{
  Comment    *parsedDoc;
	register int j;

	if ( function->parsedDoc == (Comment *)0 )
	  return;

	for ( j = 0 ; j <= getCommentTableUsageIdx(parsedDoc) ; j++ )
	  addFunctionTableUsage(function,getCommentTableUsage(parsedDoc,j));

	for ( j = 0 ; j <= getFunctionSqlIdx(function) ; j++ )
	{
		TableUsage *tableUsage;
		SQL *sql;
		register int k;

		sql = getFunctionSql(function,j);

		for ( k = 0 ; k < getSqlTableIdx(sql); k++ )
		{
			char *tableName;

			tableName = getSqlTable(sql,k);
		  tableUsage = newTableUsage();
		  setTableUsageTableName(tableName,tableUsage);
      setTableUsageFoundAs(TU_SQL,tableUsage);
      setTableUsageOperation(sql->operacao,tableUsage);
      setTableUsageLineNumber(TU_UNDEFINED,tableUsage);
	    addFunctionTableUsage(function,tableUsage);
		}
	}
}

/**
 * Found a complete function implementation.
 *
 * Executed after found the END FUNCTION.
 *
 * @param FunctionName A string containing the name of the function.
 * @param ultima_linha The last line of the function.
 * @param arguments The arguments of the function.
 *
 */
void StInsertFunction(char *FunctionName,int ultima_linha,NAME_LIST *arguments)
{
  char *GetListConcat();

	//fprintf(stderr,"Found %s\n",FunctionName);
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
	fillTableUsage(&(FUNCAO_CURR));
	/* @todo : Fix this crossed validation
	if ( P4glCb.idx_funcoes >= P4glCb.NumFunc )
		P4glError(ERROR_EXIT,
				"Function number diferent then in first pass %d (found %d)\n",
				P4glCb.idx_funcoes,
				P4glCb.NumFunc
		);
		*/
	P4glCb.idx_funcoes++;
}

/**
 * Found the begining of a new function.
 *
 * Inserts the line number in the source where the declaration found.
 * @todo - Os comentários deviam ser copiados e memória limpa
 *
 * @param linha The line where declaration found
 * @param functionType The type of the function (FUNCTION,MAIN or REPORT).
 */
void StInsertLineFunction(int linha,int functionType)
{
	P4glCb.functions[P4glCb.idx_funcoes].linha = linha;
	P4glCb.functions[P4glCb.idx_funcoes].functionType = functionType;
	Variaveis = (VARS *)0;
	IdxVariaveis=0;
	FunctionStatementCount = 0;
	/* Triger the documentation state machine event */
	defineFunctionOcurred();
}

/**
 * Insert an argument in parameter list.
 *
 * Not used.
 *
 * @param NmArg Parameter name in the function
 */
static void StInsertArgument(NmArg)
char *NmArg;
{
  /** @todo : Atencao a dimensoes - Deviam ser testadas */
  strcpy(FUNCAO_CURR.parametros->nome[IDX_ARG_CURR],NmArg);
  IDX_ARG_CURR++;
}


/**
 * Insert an function call in the array of calls.
 *
 * Executed when the parser found one of the function call(s) type.
 *
 * @param FunctionName The name of the function
 * @param linha The line number in the 4gl source where the function call was
 *        found
 */
void StInsertFunctionCall(char *FunctionName,int linha)
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

/**
 *
 * Update the type of usage made (Expression, call, etc)
 *
 * Executed when the parser terminates the statement where the function
 * call was made.
 *
 * @param usage A string representing the usage type wich could be:
 *   - FINISH REPORT
 *   - OUTPUT TO REPORT
 *   - CALL RETURNING
 *   - CALL
 *   - START TO REPORT
 *   - EXPRESSION
 *   - WHENEVER
 *
 */
void StUpdFCUsage(char *usage)
{
   FUNCAO_CURR.FunctionCall[IDX_FC_CURR-1].Usage = strdup(usage);
}


/**
 * Insert a table usage in the corresponding array.
 * 
 * The parser found the usage of the table in the array.
 * The parser only found the embeded SQL. 
 * If dynamic SQL used the programer should document it in the function comment.
 *
 * @param NmTable A string with the table name
 */
void StInsertTable(char *NmTable)
{
   strcpy(SQL_STMT_CURR.tabelas[IDX_TAB_CURR],NmTable);
}

/**
 * Increment the table counter.
 * 
 * @todo : Validate if this increment could be made in StInsertTable
 */
void StIncrementTable(void)
{
   IDX_TAB_CURR++;
}

/**
 *  Found an SQL statement by the parser
 *
 *  @param operacao The type of the operation
 *  @param linha The line in the source code where the end of SQL statement 
 *  found
 */
void StInsertSQL(int operacao,int linha)
{
	SQL_STMT_CURR.operacao = operacao;
	SQL_STMT_CURR.cursor   = -1;
	FUNCAO_CURR.idx_sql++;
}

/**
 * Executed by the parser when it founds a complete SQL statement
 *
 * Insert in the abstract tree the String with all the SQL statement.
 *
 * @param SqlTxt The string containing the sql text
 */
void StInsertSQLTxt(char *SqlTxt)
{
	SQL_STMT_CURR.texto = SqlTxt;
}


/**
 * Order function to let qsort organize the functions in alphabetic order.
 *
 * @param f1 The function pointer to the first function
 * @param f2 The function pointer to the second function
 */
static int FuncCmp(const void *f1,const void *f2)
{
   return(strcmp(((FUNCTION *)f1)->name,((FUNCTION *)f2)->name));
}

/**
 * Order function so quick sort can order the functions call
 *
 * @param f1 The first function call
 * @param f2 The second function call
 */
static int FunctionCallCmp(const void *f1,const void *f2)
{
   return(strcmp(((FUNC_CALL *)f1)->name,((FUNC_CALL *)f2)->name));
}

/**
 * Order the arrays of the abstract tree by name in order to acelerate
 * the access.
 *
 * This action is normaly made after all the parsing being made.
 */
void OrderSymtab(void)
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



/*  ========== Functions to parser stack (Union) */

/**
 * Insert a new name in the list. If the original is null
 * it allocates space for it.
 *
 * Used by the parser to pass things during the parse.
 *
 * @param Destino The destination list
 * @param Origem The origin list
 * @param Nome The name to be inserted in the list
 * @param Linha The line in the source code where this was asked
 */
void InsertNameList(NAME_LIST **Destino,NAME_LIST *Origem,char *Nome,int Linha)
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

/**
 * Concatenate a string into the name element with other passed as parameter
 * 
 * @param List A pointer to the list to be appended
 * @param ch The string to concatenate
 */
char *GetListConcat(NAME_LIST *List, char *ch)
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

/**
 * For debugging purpose only.
 * Not used
 *
 * Print all the content of a name list
 *
 * @param List The list to be printed to stdout
 */
static void PrintNameList(NAME_LIST *List)
{
   register int i;

	for (i = 0 ; i < List->idx ; i++ )
		printf("--Nome %s\n",List->nome[i]);
}


/**
 * Remove the temporary files used during the parsing process.
 *
 * If executed in debug mode does nor remove-it and send a message to 
 * standard output.
 */
void CleanP4gl(void)
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
 * Load in the abstract tree the existene of a GLOBALS instruction with
 * file (not for globals explicit declaration).
 *
 * @param NmFicheiro The name of the file defined as GLOBALS file
 */
void GlobalsInclude(char *NmFicheiro)
{
	if ( P4glCb.idx_globais >= MAXGLOB )
		P4glError(ERROR_EXIT,"Include stack overflow\n");
	tiraAspas(NmFicheiro);
   strcpy(P4glCb.globais[P4glCb.idx_globais].nome_ficheiro,NmFicheiro);
	P4glCb.idx_globais++;
}

/**
 * Gets the current source line number
 *
 * @return The current line in the source file
 */
int getLineno(void)
{
  return lineno;
}

/**
 * Assigns a new value to the current linenumber
 *
 * @param _lineno The new value to source line number
 */
void setLineno(int _lineno)
{
  lineno = _lineno;
}

/**
 * Increment the current line number by one.
 */
void incrementLineno(void)
{
  lineno++;
}

/**
 * Gets the flag that indicates if we are working with standard comments
 *
 * @return 0 : We do not want to load the standard comments
 *         1 : We want to load the standard comments
 */
int isLoadStdComments()
{
  return standardComments;
}

/**
 * Assigns the module global comment.
 *
 * @param comment The comment to the module.
 */
void setModuleComment(Comment *comment)
{
	P4glCb.parsedComment = comment;
}

/**
 * Store the comment as the current function comment
 *
 * @oaram comment The comment for the current function
 */
void setFunctionComment(Comment *comment)
{
	FUNCAO_CURR.parsedDoc = comment;
}

/**
 * Increment the counter of fgldoc(s) found in the source code
 */
void incrementNumFgldoc(void)
{
	P4glCb.numFglDoc++;
}

/**
 * Checks if we are outside functions in source code
 *
 * @return 0 : The parser is reading inside a function
 *         1 : We are between functions 
 */
int isInLimbo()
{
  return InLimbo;
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
