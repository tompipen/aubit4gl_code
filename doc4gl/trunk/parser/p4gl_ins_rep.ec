/**
 * @file
 * Inserting information into repository (inslib version).
 * Note : This repository format is no longer used
 * But folowong functions are still used:
 *
 * RegisterErrorInDb
 * RegisterWarningInDb
 * InsertInslib
 * SqlErrors
 *
 */

/* Prototypes: */


/*===========================================================================
 *
 *   Module       : %M%
 *   Object       : 
 *   SCCS Id      : %W%
 *   Full Path    : %P%
 *   Author       : 
 *   Release date : %D%
 *
 * p4gl - 4gl Parser and repository (inslib format) loading
 *
 * ESQL/C API for inserting the symbol table in the repository
 *
 * Author : Sergio Ferreira
 *
 * Modifications wanted: 
 *     - Do not use absolute pathname of the but Relative to SRC_BASE_DIR
 *     - SRC_BASE_DIR must come as parameter or environment variable
 *
 ========================================================================== */

#include <stdio.h>
#include <unistd.h>
#include <varargs.h>
#include <string.h>
#include "p4gl_symtab.h"
#include "p4gl.h"

exec sql include datetime;
exec sql include sqltypes;


char *StatDesc;        /* SQL Statement description text for error handling */
char DbName[19];


exec sql begin declare section;
   int  ID_Modulo;
	int ID_Modulo_Desconhecido;
	int ID_Modulo_Include;
	int ID_Contentor;
	int ID_ContentorDir;
	datetime Tempo;
	datetime TempoAnterior;
exec sql end declare section;

/*
 * Entry Point of Insunix repository fill in
 */
void
InsertInslib(void)
{
	exec sql whenever sqlerror call SqlErrors;

	if (!InsertInDatabase)
		return;
	P4glVerbose("Repository insertion\n");
	SetTempo();
	ConnectDb();
	if ( dbug )
	   exec sql set explain on;

	ID_Modulo              = InsUnixGetModule(P4glCb.NmFicheiroInput);
	ID_Modulo_Desconhecido = InsUnixGetUnknownModule(P4glCb.NmFicheiroInput);
	ID_Modulo_Include      = InsUnixGetIncludeModule();
	InsUnixDelErro();
   InsUnixInsertFunctions();
	exec sql update modulo set erros = "N", carregamento=current 
		where id_modulo=:ID_Modulo;
   exec sql close database;
}
 

/*
 * Remover erros de scans anteriores a este modulo 
 */
InsUnixDelErro()
{
   exec sql delete from erro where id_modulo = :ID_Modulo;
}

/*
 * Preparacao das instrucoes SQL para tratamento do repositorio 
 */
InsUnixPrepareStatements()
{
	exec sql begin declare section;
		char StrSql[256];
	exec sql end declare section;

  StatDesc = "Preparacao de seleccao de funcao declarada";
	strcpy(StrSql,        "select id_funcao  ");
	strcpy(StrSql,strcat(StrSql, "from tags "));
	strcpy(StrSql,strcat(StrSql, "where nm_funcao=? and nm_modulo=?"));
	exec sql prepare StSelFuncDec from :StrSql;

  StatDesc = "Preparacao de inserção de declaração de função";
	strcpy(StrSql,        "insert into ");
	strcpy(StrSql,strcat(StrSql, "funcao "));
	/** Isto devia receber tambem o módulo */
	strcpy(StrSql,strcat(StrSql, "(funcao,id_modulo) values (?,2)"));
	exec sql prepare StInsFuncDec from :StrSql;

  StatDesc = "Preparacao de inserção de tag de função";
	strcpy(StrSql,        "insert into ");
	strcpy(StrSql,strcat(StrSql, "tags "));
	/** Isto devia receber tambem o módulo */
	strcpy(StrSql,strcat(StrSql, "(nm_funcao,id_funcao) values (?,?)"));
	exec sql prepare StInsTags from :StrSql;

   StatDesc = "Preparacao de seleccao de funcao chamada ";
	strcpy(StrSql, "select id_funcao, nm_modulo, nm_directoria ");
	strcpy(StrSql,strcat(StrSql, "from tags "));
	strcpy(StrSql,strcat(StrSql, "where nm_funcao=? "));
	exec sql prepare StGetFunctions from :StrSql;
	exec sql declare c_GetFunctions cursor for StGetFunctions;

   StatDesc = "Preparacao de insercao de utilizacao de funcao";
	strcpy(StrSql, "insert into utilFuncao ");
   strcpy(StrSql, strcat(StrSql," (chamada,chamador,linha,numsequencia,"));
   strcpy(StrSql, strcat(StrSql," caminho,utilizacao) values "));
	strcpy(StrSql, strcat(StrSql,"(?,?,?,?,?,?)"));
	exec sql prepare StInsUtilFuncao from :StrSql;
	exec sql declare c_StInsUtilFuncao CURSOR for StInsUtilFuncao;

   StatDesc = "Preparacao de insercao de utilizacao de tabela";
   strcpy(StrSql,        "insert into utilizacaotabela ");
   strcpy(StrSql,strcat(StrSql,"(n_sequencia,id_tabela,id_funcao,operacao)"));
	strcpy(StrSql,strcat(StrSql,      " values "));
	strcpy(StrSql,strcat(StrSql," (0,?,?,?)"));
	exec sql prepare StInsUtilTab from :StrSql;
	exec sql declare c_StInsUtilTab cursor for StInsUtilTab;
  
   StatDesc = "Preparacao de seleccao de tabela";
   strcpy(StrSql,        "select id_tabela ");
	strcpy(StrSql,strcat(StrSql,    "from tabela "));
	strcpy(StrSql,strcat(StrSql,    "where nome=?"));
	exec sql prepare StGetTabela from :StrSql;

   StatDesc = "Preparacao de insercao de tabela";
	strcpy(StrSql, "insert into tabela (id_tabela,nome) values (0,?)");
	exec sql prepare StInsTabela from :StrSql;

   StatDesc = "Preparacao de alteracao de funcao";
	strcpy(StrSql,"update funcao set ninstrucoes=?,linha=?");
	strcpy(StrSql,strcat(StrSql," where id_funcao=? "));
	exec sql prepare StUpdFunction from :StrSql;

   StatDesc = "Preparacao de insercao de parametros de funcao";
	strcpy(StrSql,"insert into parametrofuncao ");
	strcpy(StrSql,strcat(StrSql," (numsequencia,nome,id_funcao) values "));
	strcpy(StrSql,strcat(StrSql," (?,?,?) "));
	exec sql prepare StInsFuncParam from :StrSql;
	exec sql declare c_StInsFuncParam cursor for StInsFuncParam;

   StatDesc = "Preparacao de insercao de declaracao de global ";
	strcpy(StrSql,"insert into global (id_global,id_modulo,global,datatype)");
	strcpy(StrSql,strcat(StrSql," values (0,?,?,?)"));
	exec sql prepare StInsGlobal from :StrSql;

   StatDesc = "Preparacao de seleccao de declaracao de global ";
	strcpy(StrSql,"select id_global from global where global=? and id_modulo=?");
	exec sql prepare StGetGlobal from :StrSql;

   StatDesc = "Preparacao de insercao de utilizacao de global ";
	strcpy(StrSql,
		"insert into utilglobal (n_sequencia,id_global,id_funcao,linha,accao)"); 
	strcpy(StrSql,strcat(StrSql," values (0,?,?,?,?)"));
	exec sql prepare StInsGlobUsage from :StrSql;
	exec sql declare c_StInsGlobUsage cursor for StInsGlobUsage;

   StatDesc = "Preparacao de insercao de utilizacao de cursor ";
	strcpy(StrSql,
		"insert into utilcursor (id_cursor,id_funcao,linha,n_sequencia,accao)"); 
	strcpy(StrSql,strcat(StrSql," values (?,?,?,?,?)"));
	exec sql prepare StInsCurUsage from :StrSql;
	exec sql declare c_StInsCurUsage cursor for StInsCurUsage;

   StatDesc = "Remocao de utilizacao de tabela";
   strcpy(StrSql,"delete from utilizacaotabela where id_funcao=?");
	exec sql prepare StDelUtilTabela from :StrSql;

   StatDesc = "Preparacao de insercao de funcao";
   strcpy(StrSql,"insert into funcao (id_funcao,id_modulo,funcao,ninstrucoes)");
	strcpy(StrSql,strcat(StrSql," values (0,?,?,?)"));
	exec sql prepare StInsFuncao from :StrSql;

   StatDesc = "Preparacao de insercao de cursor";
   strcpy(StrSql,"insert into cursor ");
	strcpy(StrSql,strcat(StrSql,"(id_cursor,id_funcao,nome,tipo,prepared) "));
	strcpy(StrSql,strcat(StrSql," values (0,?,?,?,?)"));
	exec sql prepare StInsCursor from :StrSql;

   StatDesc = "Preparacao de insercao de SQL";
   strcpy(StrSql,"insert into sql (numstatement,numbloco,id_funcao,statement,");
	strcpy(StrSql,strcat(StrSql," id_cursor)"));
	strcpy(StrSql,strcat(StrSql," values (?,?,?,?,?)"));
	exec sql prepare StInsertSql from :StrSql;
}

/*
 * Insere a informacao que esta directamente associada a funcoes, nomeadamente
 * declaracao de funcoes, utilizacao de funcoes, utilizacao de tabelas
 */
InsUnixInsertFunctions()
{
   register int i;
	exec sql begin declare section;
	   int  ID_Funcao;
		char NomeModulo[256];
		char *NomeFuncao;
		char StrSql[256];
		int NInstrucoes;
		int NLinha;
	exec sql end declare section;
	int comparacao;


	InsUnixPrepareStatements();

	/* Remover todos os SQL(s) do modulo corrente */
   StatDesc = "Remocao de Query de funcoes";
	exec sql delete from sql where id_funcao in 
		(select id_funcao from funcao where id_modulo = :ID_Modulo);

	/* Remover todos os parametros de funcoes */
   StatDesc = "Remocao de parametros de funcoes";
	exec sql delete from parametrofuncao where id_funcao in 
		(select id_funcao from funcao where id_modulo = :ID_Modulo);

	/* Remover todas as utilizacoes de funcao do modulo corrente */
   StatDesc = "Remocao de utilizacao de funcoes";
	exec sql delete from utilfuncao where chamador in 
		(select id_funcao from funcao where id_modulo = :ID_Modulo);

	P4glVerbose("Global usage variable deletion\n");
   StatDesc = "Remocao de globais utilizadas no modulo corrente";
	exec sql delete from utilglobal where id_funcao in 
		(select id_funcao from funcao where id_modulo = :ID_Modulo);
	  
	P4glVerbose("Global declared variable deletion\n");
   StatDesc = "Remocao de globais declaradas ";
	exec sql delete from global where id_modulo = :ID_Modulo;

	P4glVerbose("Getting Function(s) ID\n");
	for ( i = 0 ; i < P4glCb.idx_funcoes ; i++ )
	{
		if ( FUNCAO(i).Include )
		{
			FUNCAO(i).ID_Function = -1;
			continue;
		}

		NomeFuncao  = FUNCAO(i).name;
      strcpy(NomeModulo,FilePath);
      StatDesc   = "Seleccao de funcoes declaradas";
	   exec sql execute StSelFuncDec
		   into  :ID_Funcao
		   using :NomeFuncao, :NomeModulo;
		if (sqlca.sqlcode == 100)
		{
			/* In debug is possible to use the source in wd */
		  if ( dbug )
			{
        StatDesc = "Preparacao de seleccao de funcao declarada (DEBUG)";
				sprintf(NomeModulo,"%%%s",P4glCb.NmFicheiroInput);
				exec sql select id_funcao into :ID_Funcao from tags
					where nm_funcao=:NomeFuncao and nm_modulo like :NomeModulo;
			}
			else
			{
			   P4glError(ERROR_NO_EXIT,
			     "Funcao %s nao definida nos tags como declarada no modulo %s\n",
			     NomeFuncao, NomeModulo);
				 /** TODO Isto devia ser opcional */
				 ID_Funcao = insertFunctionDeclaration(NomeFuncao,NomeModulo);
			}
		}
		FUNCAO(i).ID_Function = ID_Funcao;
		NLinha      = FUNCAO(i).linha;
		NInstrucoes = FUNCAO(i).NInstrucoes;
      StatDesc   = "Actualizacao da informacao da funcao";
	   exec sql execute StUpdFunction using :NInstrucoes, 
														 :NLinha,
														 :ID_Funcao;
	}

	P4glVerbose("Global variable declaration insertion\n");
	InsUnixInsertGlobalDeclaration(ID_Modulo);

	P4glVerbose("Cursor declaration and usage deletion\n");
   StatDesc = "Remocao de cursores";
	exec sql delete from cursor where id_funcao in
		(select id_funcao from funcao where id_modulo = :ID_Modulo);
   StatDesc = "Remocao de utilizacao de cursores";
	exec sql delete from utilcursor where id_funcao in
		(select id_funcao from funcao where id_modulo = :ID_Modulo);
	InsUnixInsertCursorDeclaration();

	/* Se necessario tem de se meter tudo num array */
	P4glVerbose("Tables and function Usage Insertion\n");
   StatDesc = "Abertura de cursor de utilizacao de funcao";
	exec sql OPEN c_StInsUtilFuncao ;
   StatDesc = "Abertura de cursor de utilizacao de tabela";
	exec sql OPEN c_StInsUtilTab ;
   StatDesc = "Abertura de cursor de insercao de global";
	exec sql OPEN c_StInsGlobUsage ;
   StatDesc = "Abertura de cursor de insercao de cursor";
	exec sql OPEN c_StInsCurUsage ;
   StatDesc = "Abertura de cursor de parametros de funcoes";
	exec sql OPEN c_StInsFuncParam ;
	for ( i = 0 ; i < P4glCb.idx_funcoes ; i++ )
	{
		if ( FUNCAO(i).ID_Function != -1 )
		{
		   InsUnixInsertFunctionsUsage(ID_Modulo, FUNCAO(i).ID_Function, i);
		   InsUnixInsertTablesUsage(i);
		   InsUnixInsertGlobalUsage(i, ID_Modulo); 
         InsUnixInsertCursorUsage(i);
         InsUnixInsertFuncParam(i);
		}
	}
	exec sql FLUSH c_StInsUtilFuncao ;
	exec sql CLOSE c_StInsUtilFuncao ;
   exec sql FLUSH c_StInsUtilTab ;
   exec sql CLOSE c_StInsUtilTab ;
	exec sql FLUSH c_StInsGlobUsage ;
	exec sql CLOSE c_StInsGlobUsage ;
	exec sql FLUSH c_StInsCurUsage ;
	exec sql CLOSE c_StInsCurUsage ;
	exec sql FLUSH c_StInsFuncParam ;
	exec sql CLOSE c_StInsFuncParam ;
}

/**
 * Insere uma nova função na tabela de funções declaradas
 */
int insertFunctionDeclaration(functionName,moduleName)
   exec sql begin declare section;
		PARAMETER char *functionName;
		PARAMETER char *moduleName;
	exec sql end declare section;
{
	exec sql begin declare section;
    int  ID_Funcao;
	exec sql end declare section;

  StatDesc = "Function declaration insert execution";
	exec sql execute StInsFuncDec
		using :functionName;

	ID_Funcao = sqlca.sqlerrd[1];
  StatDesc = "Tag declaration insert execution";
	exec sql execute StInsTags 
		using :functionName, :ID_Funcao;
  return ID_Funcao;
}

/* 
 * Obtem o ID do modulo corrente (para chaves primarias)
 */
InsUnixGetModule(NomeFicheiro)
   exec sql begin declare section;
		PARAMETER char *NomeFicheiro;
	exec sql end declare section;
{
   exec sql begin declare section;
		int IDModulo;
	   char Fich[640];
	   char *NmDir;
   exec sql end declare section;

	/* Isto ate que poderia ter sido feito logo nas inicializacoes */
   NmDir = getcwd((char *)0,256);
	strcpy(Fich,NmDir);
	strcpy(Fich,strcat(Fich,"/"));
	strcpy(Fich,strcat(Fich,NomeFicheiro));
	StatDesc = "Seleccao em modulo";
   exec sql select id_modulo into :IDModulo
		from  modulo
		where ficheiro = :Fich;
	if (sqlca.sqlcode == 100) 
	{
		P4glWarning(DISPENSAVEL,
						"Modulo <%s> nao foi inserido pelo carregamento de %s\n",
						Fich,"tags. Inserido pelo p4gl");
		/*
		ID_Modulo = -1;
		*/
		StatDesc = "Insercao em modulo";
		exec sql insert into modulo (id_modulo, modulo,ficheiro)
			values (0, :NomeFicheiro, :Fich);
		IDModulo = sqlca.sqlerrd[1];
	}
	free(NmDir);

	StatDesc = "Seleccao de contentor EXE";
	exec sql select ID_Contentor into :ID_Contentor
		from contentor where localizacao=:NmDir and tipo='EXE';
	StatDesc = "Seleccao de contentor DIR";
	exec sql select ID_Contentor into :ID_ContentorDir
		from contentor where localizacao=:NmDir and tipo='DIR';
	return (IDModulo);
}

/* 
 * Obtem o ID do modulo indefinido (onde sao ligadas as funcoes das
 * quais nao se sabe a quem pertencem)
 */
InsUnixGetUnknownModule()
{
   exec sql begin declare section;
		int ID_Modulo;
   exec sql end declare section;

	StatDesc = "Seleccao em modulo";
   exec sql select id_modulo into :ID_Modulo
		from  modulo
		where modulo = "DESCONHECIDO";
	if (sqlca.sqlcode == 100) 
	{
		StatDesc = "Insercao em modulo";
		exec sql insert into modulo
			(id_modulo, modulo,ficheiro)
			values
			(0, "DESCONHECIDO", "DESCONHECIDO");
		return (sqlca.sqlerrd[1]);
	}
	return (ID_Modulo);
}

/* 
 * Obtem o ID do modulo de include (onde sao declaradas as globais 
 * usadas.
 *
 * Se o nome do modulo for *GLB.4gl usa o ficheiro globais.4gl que tem de estar
 * scannado
 */
InsUnixGetIncludeModule()
{
   exec sql begin declare section;
		int ID_Modulo;
		char *NomeInclude;
   exec sql end declare section;

	if ( P4glCb.idx_globais <= 0 )
		return;

	NomeInclude = P4glCb.globais[0].nome_ficheiro;

	/* Na versao 0.3 os ficheiros de globals sao gerados dinamicamente */
	if ( strcmp(NomeInclude+strlen(NomeInclude)-7,"GLB.4gl") == 0 )
		NomeInclude = "globais.4gl";

	StatDesc = "Seleccao do modulo de include (GLOBALS)";
   exec sql declare CrInclude cursor for 
		select id_modulo into :ID_Modulo
		   from  modulo
		   where modulo = :NomeInclude;
	exec sql open CrInclude;
	exec sql fetch CrInclude into :ID_Modulo;
	if (sqlca.sqlcode == 100) 
	{
		StatDesc = "Insercao em modulo de include";
		exec sql insert into modulo
			(id_modulo, modulo,ficheiro)
			values
			(0, :NomeInclude, "DESCONHECIDO");
		return (sqlca.sqlerrd[1]);
	}
	return (ID_Modulo);
}


/* 
 * Insere uma nova funcao declarada 
 */
InsUnixInsereFuncao(ID_Modulo, NumFuncao)
   exec sql begin declare section;
      PARAMETER int ID_Modulo;
   exec sql end declare section;
	int NumFuncao;
{
   exec sql begin declare section;
		char FunctionName[64];
   exec sql end declare section;

   
	 strcpy(FunctionName,FUNCAO(NumFuncao).name);
    StatDesc = "Insercao em funcao";
	 exec sql execute StInsFuncao using :ID_Modulo, :FunctionName;
	 return (sqlca.sqlerrd[1]);
}


/*
 * Insere utilizacao de funcoes dentro de uma delas
 * Ainda falta meter a remocao a trabalhar
 * ??? Isto agora passa a inserir todas as possibilidades  com grau
 *     de probabilidade.
 * Tabela UtilFuncao
 */
InsUnixInsertFunctionsUsage(ID_Modulo,ID_Function,FN)
	exec sql begin declare section;
      PARAMETER int ID_Modulo;
      PARAMETER int ID_Function;
	exec sql end declare section;
	int FN;                            /* Function Number */
{
   register int i;
	int c;
	exec sql begin declare section;
	   int  ID_Function_Chamada;
		int  Linha;
		int  NSeq;
		char *Usage;    /* Type of function call (call, expression) */
	exec sql end declare section;
	char FuncaoAnterior[50];

	FuncaoAnterior[0]='\0';
	NSeq = 0;
	for ( i = 0 ; i < IDX_FC(FN) ; i++)
	{
		NSeq = InsertFunctionCall(FUNC_CALL(FN,i).name,
								        FUNC_CALL(FN,i).linha,
								        FUNC_CALL(FN,i).Usage,
								        ID_Function,
										  NSeq);

		                         /* Optimizacao - devia passar para a funcao */
										 /* A seguir vem da versao anterior */
		/*
		printf("Funcao %s\n", FUNC_CALL(FN,i).name);
		if ( FuncaoAnterior[0]=='\0' ||   
			  strcmp(FuncaoAnterior,FUNC_CALL(FN,i).name)!=0 )
			  Optimizacao para implementar 
		strcpy(FuncaoAnterior,FUNC_CALL(FN,i).name);
		*/
	}
}

struct called_functions
{
   int ID;
	short caminho;
	char  NmModulo[129];
	char  NmDirectoria[129];
};


/*
 * Insere a execucao de funcao.
 * Se existirem varias funcoes com o mesmo nome tenta descobrir qual a mais 
 * provavel, no entanto insere-as todas .
 */
InsertFunctionCall(Name, Line, UsageType, IDFunction, NSeq)
   exec sql begin declare section;
      PARAMETER char *Name;
      PARAMETER int  Line;
      PARAMETER char *UsageType;
      PARAMETER int  IDFunction;
      PARAMETER int  NSeq;
   exec sql end declare section;
{
   exec sql begin declare section;
		int Caminho;
      int ID_Function_Chamada;
   exec sql end declare section;
   register int i;
	int idx_caminho = 0;
	/* This should be more dynamic - In other aplications could be a problem */
	struct called_functions IDCalledFunctions[50];

   /* IMPORTANTE : ??? Tem de ter optimizacao de funcoes com o mesmo nome */
	idx_caminho = GetCalledFunctions(Name,IDCalledFunctions); 
	if (idx_caminho == 0)
	{
      P4glWarning(IMPORTANT,"Funcao %s nao declarada\n", Name);
		return NSeq;
	}
	
	for ( i = 0 ; i < idx_caminho ; i++ )
	{
      StatDesc = "Insert of Function Call";
		ID_Function_Chamada = IDCalledFunctions[i].ID;
		Caminho             = IDCalledFunctions[i].caminho;
      exec sql put c_StInsUtilFuncao 
         from :ID_Function_Chamada, :IDFunction, :Line,
				  :NSeq, :Caminho, :UsageType;
		/* Porque este flush ??? */
      exec sql FLUSH c_StInsUtilFuncao;
		NSeq++;
	}
	return NSeq;
}


/* 
 * Preenche o array de funcoes chamadas
 */
GetCalledFunctions(Name,ArrayIDs)
   exec sql begin declare section;
      PARAMETER char *Name;
   exec sql end declare section;
   struct called_functions *ArrayIDs;
{
   exec sql begin declare section;
		int  IDFunction;
		char NmModulo[129];
		char NmDirectoria[129];
   exec sql end declare section;
   register int idx=0, i;

	exec sql open c_GetFunctions using :Name;
	while (sqlca.sqlcode == 0)
	{
		exec sql fetch c_GetFunctions 
			into :IDFunction, :NmModulo, :NmDirectoria;
		if ( sqlca.sqlcode != 0 ) break;
		ArrayIDs[idx].ID                 = IDFunction;
		strcpy(ArrayIDs[idx].NmModulo,     NmModulo);
		strcpy(ArrayIDs[idx].NmDirectoria, NmDirectoria);
		ArrayIDs[idx].caminho = 99;
		idx++;
	}
	exec sql close c_GetFunctions;

	switch (idx)
	{
		case 0:
			return(0);
		case 1:                        /* Eh esta funcao de certeza */
		   ArrayIDs[0].caminho = 0;
			return 1;
	}

	                                /* Funcao no mesmo source              */
	for ( i = 0 ; i < idx ; i++ )
	{
		if ( strcmp(ArrayIDs[i].NmModulo,FilePath) == 0 )
		{
			if ( ArrayIDs[idx].caminho != 99 )
				printf("Estranho !... Ja existem ID(s) != 99\n");
			ArrayIDs[i].caminho = GetMaiorCaminho(ArrayIDs,idx);
		}
	}

	for ( i = 0 ; i < idx ; i++ )
		if ( strcmp(ArrayIDs[i].NmDirectoria,FileDirectory) == 0 )
			ArrayIDs[i].caminho = GetMaiorCaminho(ArrayIDs,idx);

	for ( i = 0 ; i < idx ; i++ )
	{
		if ( strstr(ArrayIDs[i].NmModulo,"_LIB_O")  != NULL ||
		     strstr(ArrayIDs[i].NmModulo,"_LIB_OO") != NULL ||
		     strstr(ArrayIDs[i].NmModulo,"_LIBGEN") != NULL )
			ArrayIDs[i].caminho = GetMaiorCaminho(ArrayIDs,idx);
	}

	for ( i = 0 ; i < idx ; i++ )
	{
		if ( ArrayIDs[i].caminho == 99 )
			ArrayIDs[i].caminho = GetMaiorCaminho(ArrayIDs,idx);
	}
	return idx;
}


/* 
 * Obtem o maior caminho do array diferente de 99
 * Se tudo a 99 devolve 1 
 */
GetMaiorCaminho(ArrayIDs,idx)
struct called_functions *ArrayIDs;
int idx;
{
   register int i;
	int maior = -1;

	for ( i = 0 ; i < idx ; i++ )
	{
		if ( ArrayIDs[i].caminho != 99 )
			if ( ArrayIDs[i].caminho > maior )
				maior = ArrayIDs[i].caminho;
	}
	return maior+1;
}

/*
 * Insere utilizacao de tabela
 * Tabela UtilFuncao
 */
InsUnixInsertTablesUsage(FunctionNum)
	exec sql begin declare section;
	exec sql end declare section;
	int FunctionNum;
{
   register int i,j;
	exec sql begin declare section;
		int ID_Function;
		int ID_Table; 
		char Operacao; 
		int NSeq; 
		short IndNSeq;
	exec sql end declare section;

	for ( i = 0 ; i < FUNCAO(FunctionNum).idx_sql; i++)
	{
	   ID_Function = FUNCAO(FunctionNum).ID_Function;
		/* ??? Isto podia ser global ao modulo */
	   StatDesc = "Remocao em Utilizacao de tabela";
	   exec sql execute StDelUtilTabela  using :ID_Function;
		InsUnixInsertSql(SQL_STMT(FunctionNum,i).texto,
							  ID_Function,i,
							  SQL_STMT(FunctionNum,i).cursor);
		for ( j = 0 ; j < SQL_STMT(FunctionNum,i).idx_tabelas ; j++ )
		{
		   ID_Table = InsUnixInsertTable(SQL_STMT(FunctionNum,i).tabelas[j]);
			if ( ID_Table == -1 )   return;
			switch (SQL_STMT(FunctionNum,i).operacao )
			{
				 case SQL_SELECT:
					  Operacao = 'S';
					  break;
				 case SQL_INSERT:
					  Operacao = 'I';
					  break;
				 case SQL_UPDATE:
					  Operacao = 'U';
					  break;
				 case SQL_DELETE:
					  Operacao = 'D';
					  break;
				 default:
					  Operacao = 'S';
			}
         StatDesc = "Insercao em Utilizacao de Tabela";
			exec sql put c_StInsUtilTab
				from :ID_Table, :ID_Function, :Operacao;
		} 
		                    /* Inserir LIKE(s) */
		/*
		for ( j = 0 ; j < idx_tabelas ; j++ )
		{
		   ID_Table = InsUnixInsertTable(SQL_STMT(FunctionNum,i).tabelas[j]);
			switch (SQL_STMT(FunctionNum,i).operacao )
			{
				 case SQL_SELECT:
					  Operacao = 'S';
					  break;
				 case SQL_INSERT:
					  Operacao = 'I';
					  break;
				 case SQL_UPDATE:
					  Operacao = 'U';
					  break;
				 case SQL_DELETE:
					  Operacao = 'D';
					  break;
				 default:
					  Operacao = "S";
			}
         StatDesc = "Insercao em Utilizacao de Tabela";
			exec sql put c_StInsUtilTab 
				from :ID_Table, :ID_Function, :Operacao;
		}
		*/
	}
}

/*
 * Insert of text from Sql stament
 */
InsUnixInsertSql(SqlTxt,ID_Function,NumStatement,IdxCursor)
exec sql begin declare section;
   PARAMETER char *SqlTxt;
   PARAMETER int ID_Function;
   PARAMETER int NumStatement;
exec sql end declare section;
	int           IdxCursor;
{
exec sql begin declare section;
   int  NumBloco = 1;
	char Bloco[256];
	int  Cursor;
exec sql end declare section;
	register int i, j,k,l;
	int Inicio;

	if ( IdxCursor >= 0 )
	   Cursor = P4glCb.cursores[IdxCursor].ID_Cursor;
	else
	   rsetnull(CINTTYPE,(char *)&Cursor);
	if (SqlTxt == (char *)0) return;
	Inicio = 0;
	while (1)
	{
	  for ( i = Inicio ; i <= Inicio+255 && SqlTxt[i]  != '\0' ; i++);
		if  ( SqlTxt[i] ==  '\0' )
		{
			strcpy(Bloco,SqlTxt+Inicio);
         StatDesc = "Insercao de Bloco de SQL";
		   exec sql execute StInsertSql 
				using :NumStatement, :NumBloco, :ID_Function, :Bloco, :Cursor;
			break;
	   }
		else
		{
			for ( j = i ; j > Inicio && j > 0  ; j-- ) /*Procura ultimo separador*/
				if (SqlTxt[j] == ' ' || SqlTxt[j]==',' || SqlTxt[j]==')') break;
			for ( k = Inicio,l=0 ; k < j ; k++,l++)
				Bloco[l] = SqlTxt[k];
			Bloco[l] = '\0';
			Inicio = j;
		}
      StatDesc = "Insercao de Bloco de SQL ( )";
		exec sql execute StInsertSql 
				using :NumStatement, :NumBloco, :ID_Function, :Bloco, :Cursor;
	   NumBloco++;
   }
}

/*
 *  Insere existencia de tabela
 *  Tabela : tabela
 */
InsUnixInsertTable(NomeTabela)
	exec sql begin declare section;
      PARAMETER char *NomeTabela;
	exec sql end declare section;
{
	exec sql begin declare section;
		int ID_Tabela;
	exec sql end declare section;

   StatDesc = "Seleccao em Utilizacao de Tabela";
	if ( IsEmpty(NomeTabela) )
	{
      P4glWarning(IMPORTANT,"Tentativa de insercao de tabela vazia %s \n", 
					              P4glCb.NmFicheiroInput);
		return(-1);
	}
	exec sql execute StGetTabela 
		into  :ID_Tabela
		using :NomeTabela;

	 if (sqlca.sqlcode == 100 )
	 {
       StatDesc = "Insercao em Tabela";
		 exec sql execute StInsTabela using :NomeTabela;
		 return sqlca.sqlerrd[1];
	 }
	 return ID_Tabela;
}

/*
 * Insere todas as variaveis que estao declaradas no modulo ou no modulo 
 * incluido.
 * A insercao do modulo incluido eh pouco eficaz pois esta a inserir tantas
 * vezes quantas as inclusoes. Devia existir um esquema de tempos de 
 * alteracao e switch que permitisse forcar a insercao 
 *  
 *  ALTERACAO : Se o nome do ficheiro incluido for *GLB.4gl utiliza o 
 *              ficheiro de globais chamado "globais.4gl"
 */
InsUnixInsertGlobalDeclaration(ID_Modulo)
	exec sql begin declare section;
		PARAMETER int  ID_Modulo;
	exec sql end declare section;
{
   register int i,j;
	exec sql begin declare section;
		int  ID_Global;
		char *NomeGlob;
		char *Datatype;
	exec sql end declare section;
	int       TamanhoGlobais;
	VAR_USAGE *VarUsage;


	for ( i = 0 ; i < P4glCb.idx_var_glob ; i++ )
	{
		Datatype = P4glCb.var_globais[i].tipo;
		NomeGlob = P4glCb.var_globais[i].nome;
		if ( P4glCb.var_globais[i].tipo_dec == IN_MODULE )
		{
         StatDesc = "Insercao de declaracao de global (declarada no modulo)";
		   exec sql execute StInsGlobal using :ID_Modulo, :NomeGlob, :Datatype;
	      ID_Global = sqlca.sqlerrd[1];
		}
		else          /* IN_INCLUDE - Declaracao em GLOBALS "GlobalFile.4gl" */
		{
         StatDesc = "Seleccao de global";
			exec sql execute StGetGlobal into :ID_Global
				using :NomeGlob, :ID_Modulo_Include;
			if (sqlca.sqlcode == 100)
			{
            StatDesc = "Insercao de declaracao de global";
				exec sql execute StInsGlobal using :ID_Modulo_Include, :NomeGlob, 
								:Datatype;
	         ID_Global = sqlca.sqlerrd[1];
		   }
	   }
		P4glCb.var_globais[i].id_global = ID_Global;
	}
}

/*
 * Verifica se o nome eh nome de uma tabela utilizada
 */
IsTable(Nome)
char *Nome;
{
   register int i,j,k;
 
	/* Percorrer utilizacao de tabelas nas funcoes */
	for ( i = 0 ; i < P4glCb.idx_funcoes ; i++ )
	{
		for ( j = 0 ; j < FUNCAO(i).idx_sql; i++)
		{
			for ( k = 0 ; k < FUNCAO(i).sql[j].idx_tabelas ; k++ )
				if (strcasecmp(Nome,FUNCAO(i).sql[j].tabelas[k])==0)
            {
               printf("Nome %s eh nome de tabela \n", Nome);
               return 1;
            }
       }
   }
   printf("Nome %s nao eh nome de tabela \n",Nome);
   return 0;
}

/*
 * Insere as utilizacoes de variaveis globais na funcao
 * O modulo de declaracao eh:
 *   - O proprio se estiver no array de globais declaradas
 *   - O modulo de globais caso contrario
 */
InsUnixInsertGlobalUsage(FuncNum,ID_Modulo)
int FuncNum;
exec sql begin declare section;
   PARAMETER int ID_Modulo;
exec sql end declare section;
{
	VAR_USAGE *VarUs;
	exec sql begin declare section;
		char *NomeGlob;
		int   Linha;
		char  Utilizacao[6];
		int   ID_Global;
		int   ID_Function;
	exec sql end declare section;

   VarUs       = FUNCAO(FuncNum).var_usage;
	ID_Function = FUNCAO(FuncNum).ID_Function;

   while ( VarUs != (VAR_USAGE *)0)
	{
		NomeGlob = VarUs->nome;
		Linha    = VarUs->linha;
		if (VarUs->utilizacao == READ_VAR)  strcpy(Utilizacao,"READ");
		else                                strcpy(Utilizacao,"WRITE");
		ID_Global = GetIdGlobal(NomeGlob);
      StatDesc = "Insercao de utilizacao de global (no cursor)";
		exec sql put c_StInsGlobUsage 
			from :ID_Global, :ID_Function, :Linha, :Utilizacao;
		VarUs = VarUs->next;
	}
}

/*
 * Inserr as declaracoes de cursores do modulo
 */
InsUnixInsertCursorDeclaration()
{
   register int i;
	exec sql begin declare section;
		char  *NomeCursor;
		int   ID_Function;
		char  *TipoCursor;
		char  *Prepared;
	exec sql end declare section;

	for ( i = 0 ; i < P4glCb.idx_cursores ; i++ ) 
	{
		NomeCursor  = P4glCb.cursores[i].nome;
		switch (P4glCb.cursores[i].tipo)
		{
			case CURS_SCROLL:
				TipoCursor = "SCROLL";
				break;
			case WITH_HOLD:
				TipoCursor = "WITH HOLD";
				break;
			case SCROLL_WITH_HOLD:
				TipoCursor = "SCROLL WITH HOLD";
				break;
			default:
				TipoCursor = "UNDEFINED";
				break;
		}
		if ( P4glCb.cursores[i].prepared == PREPARED )
			Prepared = "PREPARED";
		else
			Prepared = "EXPLICIT";
		ID_Function = FUNCAO(P4glCb.cursores[i].FuncNum).ID_Function;
      StatDesc = "Insercao de declaracao de cursor ";
		exec sql execute StInsCursor 
			using :ID_Function, :NomeCursor, :TipoCursor, :Prepared;
		P4glCb.cursores[i].ID_Cursor = sqlca.sqlerrd[1];
	}
}

/*
 * Cursor usage in a function
 */
InsUnixInsertCursorUsage(FuncNum)
int FuncNum;
{
	CUR_USAGE *CurUs;
	exec sql begin declare section;
		char *NomeCursor;
		int   Linha;
		char  Utilizacao[20];
		int   ID_Cursor;
		int   ID_Function;
      int i;
	exec sql end declare section;

	Utilizacao[0]='0';
   CurUs       = FUNCAO(FuncNum).cur_usage;
	ID_Function = FUNCAO(FuncNum).ID_Function;

	i = 0;
   while ( CurUs != (CUR_USAGE *)0)
	{
		NomeCursor = CurUs->nome;
		Linha      = CurUs->linha;
	   switch ( CurUs->utilizacao )
	   {
		   case CURSOR_OPEN:
				strcpy(Utilizacao,"OPEN");
			   break;
		   case CURSOR_FETCH:
				strcpy(Utilizacao,"FETCH");
			   break;
		   case CURSOR_CLOSE:
				strcpy(Utilizacao,"CLOSE");
			   break;
		   case CURSOR_PUT:
				strcpy(Utilizacao,"PUT");
			   break;
		   case CURSOR_UPDATE:
				strcpy(Utilizacao,"UPDATE");
			   break;
		   case CURSOR_FLUSH:
				strcpy(Utilizacao,"FLUSH");
			   break;
		   default:
				strcpy(Utilizacao,"UNDEF");
			   break;
	   }
		ID_Cursor = GetIdCursor(NomeCursor);
      StatDesc = "Insercao de utilizacao de cursor (usando cursor)";
		exec sql put c_StInsCurUsage 
			from :ID_Cursor, :ID_Function, :Linha, :i, :Utilizacao;
		CurUs = CurUs->next;
		i++;
	}
}

/*
 * Parameters of a function
 */
InsUnixInsertFuncParam(FuncNum)
int FuncNum;
{
	exec sql begin declare section;
		int   ID_Function;
      int  i;
		char *Nome;
		char *DataType;
	exec sql end declare section;
	register int j;

	ID_Function = FUNCAO(FuncNum).ID_Function;
	if ( FUNCAO(FuncNum).parametros == (NAME_LIST *)0)
		return;
	for (i = 0 ; i < FUNCAO(FuncNum).parametros->idx ; i++ )
	{
		Nome = FUNCAO(FuncNum).parametros->nome[i];

		/* ??? Obter tipo da variavel local */
		/* ??? Preencher tipo */
		/* ??? coluna datatype */
		/*
		for ( j = 0 ; j < FUNCAO(FuncNum).
		 */
		EXEC sql put c_StInsFuncParam from :i, :Nome, :ID_Function;
   }
}



/*
 * Obtem o ID_Global da variavel com o nome que recebe como parametro
 * Se fosse arvore binaria era muito mais rapido
 */
GetIdGlobal(NomeGlobal)
char *NomeGlobal;
{
   register int i;

	for( i = 0 ; i <= P4glCb.idx_var_glob ; i++)
      if (strcasecmp(NomeGlobal,P4glCb.var_globais[i].nome)==0)
			return(P4glCb.var_globais[i].id_global);
   return(-1);
}


/*
 * Obtem o ID_Cursor do cursor com o nome que recebe como parametro
 */
GetIdCursor(NomeCursor)
char *NomeCursor;
{
   register int i;

	for( i = 0 ; i <= P4glCb.idx_cursores ; i++)
      if (strcasecmp(NomeCursor,P4glCb.cursores[i].nome)==0)
			return(P4glCb.cursores[i].ID_Cursor);
   P4glWarning(IMPORTANT,
		"Cursor %s inexistente (provavelmente este source nao compila) \n", 
					              NomeCursor);
   return(-1);
}

 /*
  * Funcao que faz a gestao dos erros
  */

void
SqlErrors(void)
 {
    int err = 0;
    if(!strncmp(SQLSTATE, "00", 2) ||
       !strncmp(SQLSTATE,"02",2))
       return(SQLSTATE[1]);
    if(!strncmp(SQLSTATE, "01", 2))
       printf("\n SQL Warning encountered at %s: %d \n",
                   StatDesc,
                   sqlca.sqlcode);
		 /*
       P4glWarning(IMPORTANT, "\n SQL Warning encountered at %s: %d \n",
                   StatDesc,
                   sqlca.sqlcode);
						 */
    else /* SQLSTATE class > "02" */
    {
       printf("\n SQL Error encountered at %s: %d \n",
		           StatDesc,
                 sqlca.sqlcode);
		 /*
       P4glError(ERROR_EXIT, "\n SQL Error encountered at %s: %d \n",
		           StatDesc,
                 sqlca.sqlcode);
					  */
       err = 1;
    }
	 exec sql close database;
	 exit(1);
 }


/*
 * Meter cronometro a zero
 */
SetTempo()
{
   TempoAnterior.dt_qual = TU_DTENCODE(TU_YEAR,TU_F3);
	dtcurrent(&TempoAnterior);
}

/*
 * Mostra o tempo que passou e mete o cronometro a zero 
 */
MostraTempo()
{
	char strtempo[64];
	exec sql begin declare section;
		interval Intervalo;
   exec sql end declare section;

   Tempo.dt_qual = TU_DTENCODE(TU_YEAR,TU_F3);
	dtcurrent(&Tempo);
	dtsub(&TempoAnterior,&Tempo,&Intervalo);
	dtcurrent(&TempoAnterior);
	intoasc(&Intervalo,strtempo);
	printf("Tempo %s\n",strtempo);
}


/* =========================================================================
 # Insertion of error at the log table of inslib
 # =========================================================================*/
/*VARARGS0*/
P4glLog(va_alist)
va_dcl
{
	int tipoErro;              /* Se a 0 e para fazer exit */
	va_list args;
	char *fmt;
	char *NmDir;
	exec sql begin declare section;
		char *Progname;
		char ErrTxt[256];
	exec sql end declare section;

	va_start(args);
	fmt     = va_arg(args,char *);
	(void) vsprintf(ErrTxt,fmt,args);
	va_end(args);

	Progname = FicheiroInput;
	exec sql insert into erros
		          (ficheiro,  data_scan, texto)
		   values (:Progname, CURRENT,   :ErrTxt);
}


/*
 * Start the connection to the database
 * TODO - Tornar este método global
 */
ConnectDb()
{
exec sql begin declare section;
   char StrStat[512];
exec sql end declare section;

	if ( DBConnected )
		return;
  sprintf(StrStat,"database %s",P4glCb.database);
  StatDesc = "Preparacao de instrucao de abertura da BD";
	exec sql prepare opndb from :StrStat;
   StatDesc = "Abertura da BD";
	exec sql execute opndb ;
	if ( sqlca.sqlcode != 0 )
		P4glError(ERROR_EXIT," %d open the database %s\n",
		  sqlca.sqlcode,P4glCb.database
    );
	DBConnected = 1;
}

/*
 * It register(s) a error at the database and 
 * mark module not scanned.
 */
void
RegisterErrorInDb(msg)
char *msg;
{
   exec sql begin declare section;
		char *Txt;
   exec sql end declare section;

	exec sql whenever sqlerror   goto ERRO;
	/*exec sql whenever sqlwarning goto ERRO;*/
	Txt = msg;
	if (!InsertInDatabase)
		return;
	ConnectDb();
	if (!DBConnected) return;
	if (ID_Modulo == 0)
	   ID_Modulo = InsUnixGetModule(P4glCb.NmFicheiroInput);
   StatDesc = "Alteracao de modulo";
	exec sql update modulo set erros = "S", carregamento=current 
		where id_modulo=:ID_Modulo;
   StatDesc = "Insercao de erro";
	exec sql insert into erro (id_erro,id_modulo,descricao)
		      values (0,:ID_Modulo,:Txt);
	exec sql whenever sqlerror   call SqlErrors;
	/*exec sql whenever sqlwarning call SqlErrors;*/
	return;

ERRO:
   printf("\n SQL Warning or ERROR encountered at %s: %d \n",
                   StatDesc,
                   sqlca.sqlcode);
	exec sql whenever sqlerror   call SqlErrors;
	/*exec sql whenever sqlwarning call SqlErrors;*/
}

/*
 * It register(s) a warning at the database and 
 * mark module not scanned.
 */
void
RegisterWarningInDb(msg)
char *msg;
{
   exec sql begin declare section;
		char *Txt;
   exec sql end declare section;

	Txt = msg;
	if (!InsertInDatabase)
		return;
	exec sql whenever sqlerror   goto ERRO;
	/*exec sql whenever sqlwarning goto ERRO;*/
	ConnectDb();
	if (ID_Modulo == 0)
	   ID_Modulo = InsUnixGetModule(P4glCb.NmFicheiroInput);
	exec sql whenever sqlerror   goto ERRO;
	/*exec sql whenever sqlwarning goto ERRO;*/
   StatDesc = "Insercao de avisos";
	exec sql insert into erro (id_erro,id_modulo,descricao)
		      values (0,:ID_Modulo,:Txt);
	/*
	exec sql whenever sqlerror   call SqlErrors;
	exec sql whenever sqlwarning call SqlErrors;
	*/
	return;

ERRO:
   printf("\n SQL Warning or ERROR encountered at %s: %d \n",
                   StatDesc,
                   sqlca.sqlcode);
	/*
	exec sql whenever sqlerror   call SqlErrors;
	exec sql whenever sqlwarning call SqlErrors;
	*/
}

