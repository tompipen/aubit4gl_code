

#include <stdio.h>
#include <unistd.h>
#include <varargs.h>
#include "p4gl_symtab.h"

/**
 * Inserção no repositório denominado p4glRepository
 *
 * Efectua a leitura com origem na tabela de simbolos carregada pelo p4gl
 * e grava a respectiva informação no repositório relacional
 *
 * O repositório ainda não está completo. Esta a ser desenvolvido à medida que
 * é necessário
 *
 */

extern char *StatDesc;


/**
 * Trata da inserção de toda a informação no repositório
 */
insertP4glRep()
{
	/*I get a core dump here

	(gdb) run
	Starting program: /usr/local/bin/p4gl --file=PZU.4gl --database=p4gl_repository  --insert  em /opt/aubit/apps/erp/src/ap

	Program received signal SIGSEGV, Segmentation fault.
	0x0805a125 in insertP4glRep () at InsertP4glRep.ec:30
	30		updatePackage(P4glCb.package);
	(gdb) bt
	#0  0x0805a125 in insertP4glRep () at InsertP4glRep.ec:30
	#1  0x08058d21 in executeActions () at actions.c:21
	#2  0x08051dfd in main (argc=6, argv=0xbffff5e4) at m_p4gl.c:23
	#3  0x4004c306 in __libc_start_main (main=0x8051dbc <main>, argc=6,
	    ubp_av=0xbffff5e4, init=0x8049dec <_init>, fini=0x812fc90 <_fini>,
	    rtld_fini=0x4000d2dc <_dl_fini>, stack_end=0xbffff5dc)
	    at ../sysdeps/generic/libc-start.c:129
	(gdb)


    */
	exec sql whenever sqlerror call SqlErrors;
	ConnectDb();
	deleteModule(P4glCb.package,P4glCb.module);
	updatePackage(P4glCb.package);
	insertModule(P4glCb.package,P4glCb.module,P4glCb.parsedComment->buffer);
	insertFunctions();
}

/**
 * Verifica se existe e se afirmativo altera o package 
 */
updatePackage(idPackage)
  exec sql begin declare section;
		PARAMETER char *idPackage;
	exec sql end declare section;
{
	StatDesc = "Update p4gl_package";
  exec sql update p4gl_package set id_package = :idPackage
	  where id_package = :idPackage;

	/* Falta saber qual o sqlca.sqlerrd (ver manual esqlc) */
  if ( sqlca.sqlerrd[2] <= 0)
	{
	  exec sql insert into p4gl_package (id_package) values (:idPackage);
	}
}


/*
 * Apaga tudo o que diga respeito a um módulo de 4gl
 *
 * @todo - Método que verifique apenas se já existe o módulo
 *
 * @param idPackage Chave primária do package
 * @param moduleName Nome do módulo de 4gl
 */
deleteModule(idPackage,moduleName)
  exec sql begin declare section;
		PARAMETER char *idPackage;
		PARAMETER char *moduleName;
	exec sql end declare section;
{
	StatDesc = "Delete p4gl_fun_parameter";
  exec sql delete from p4gl_fun_parameter
	  where id_package = :idPackage and module_name = :moduleName;

	StatDesc = "Delete p4gl_fun_return";
  exec sql delete from p4gl_fun_return
	  where id_package = :idPackage and module_name = :moduleName;

	StatDesc = "Delete p4gl_fun_todo";
  exec sql delete from p4gl_fun_todo
	  where id_package = :idPackage and module_name = :moduleName;

	StatDesc = "Delete p4gl_fun_process";
  exec sql delete from p4gl_fun_process 
	  where id_package = :idPackage and module_name = :moduleName;

	StatDesc = "Delete p4gl_function";
  exec sql delete from p4gl_function
	  where id_package = :idPackage and module_name = :moduleName;

	StatDesc = "Delete p4gl_module";
  exec sql delete from p4gl_module 
	  where id_package = :idPackage and module_name = :moduleName;

	StatDesc = "Delete p4gl_table_usage";
  exec sql delete from p4gl_table_usage 
	  where id_package = :idPackage and module_name = :moduleName;
}

/**
 * Insere um novo módulo
 * @todo - Ver como se comporta quando módulo indefinido (NULL)
 */
insertModule(idPackage,moduleName,comments)
  exec sql begin declare section;
		PARAMETER char *idPackage;
		PARAMETER char *moduleName;
		PARAMETER char *comments;
	exec sql end declare section;
{
	StatDesc = "insert p4gl_module";
	if ( comments == NULL )
	  comments=" ";
	/* printf("Comments <%s>\n",comments); */
  exec sql insert into p4gl_module (id_package,module_name,comments) values
	  (:idPackage,:moduleName,:comments);
}

/**
 * Insere todas as funções relativas a este módulo
 */ 
insertFunctions()
{
	register int i;

  for ( i = 0 ; i < P4glCb.idx_funcoes ; i++ )
	  insertFunction(i);
}

/**
 * Insere um novo método (função)
 * @todo - Ver se não dá erro quando não tem comentários (NULL)
 * @param idxFunction Indice da função na tabela de simbolos
 */
insertFunction(int idxFunction)
{
  exec sql begin declare section;
		char *idPackage;
		char *moduleName;
		char *functionName;
		char *functionType;
		char *comments;
	exec sql end declare section;

	StatDesc = "insert p4gl_function";
	idPackage    = P4glCb.package;
	moduleName   = P4glCb.module;
	functionName = FUNCAO(idxFunction).name;
	comments     = FUNCAO(idxFunction).parsedDoc->buffer;
	if ( FUNCAO(idxFunction).functionType == FUNCTION_TYPE )
	  functionType = "F";
  else
	  functionType = "R";

	if ( comments == (char *)0 )
	  comments=" ";
  exec sql insert into p4gl_function (
	    id_package,module_name,
	    function_name,function_type,comments
		)
	  values (:idPackage,:moduleName,:functionName,:functionType,:comments);
  insertFunctionParameters(idxFunction);
  insertFunctionReturns(idxFunction);
  insertFunctionProcess(idxFunction);
  insertFunctionTodos(idxFunction);
}

/**
 * Insere associações entre funções e processos na base de dados
 */
insertFunctionProcess(int idxFunction)
{
  exec sql begin declare section;
		char *idProcess;
		char *idPackage;
		char *moduleName;
		char *functionName;
	exec sql end declare section;
	register int i;

	if ( FUNCAO(idxFunction).parsedDoc == (Comment *)0 )
	  return;

	StatDesc = "insert p4gl_fun_process";
	idPackage    = P4glCb.package;
	moduleName   = P4glCb.module;
	functionName = FUNCAO(idxFunction).name;
	for ( i = 0 ; i < FUNCAO(idxFunction).parsedDoc->processIdx ; i++ )
	{
		idProcess = FUNCAO(idxFunction).parsedDoc->processCode[i];
		if ( isValidProcess(idProcess) == 0 )
		{
      exec sql insert into p4gl_fun_process (
				id_process,
	      id_package,module_name,
	      function_name
		    )
	      values (:idProcess,:idPackage,:moduleName,:functionName);
	  }
		else
			/* @todo - Devia usar rotina de erros do p4gl */
		  printf("Erro : processo inexistente\n");
  }
}

/**
 * Percorre as variáveis locais declaradas para encontrar o tipo de dados
 * do parâmetro
 * 
 * @param idxFunction Número da Função
 * @param varName Nome do parâmetro
 */
char *getParameterDataType(int idxFunction,char *paramName)
{
	char *dataType;
	char *varName;
	register int i;

	dataType = "Unknown (for now)";
	for ( i = 0 ; i < FUNCAO(idxFunction).idx_var ; i++ )
	{
		varName = FUNCAO(idxFunction).variaveis[i].nome;
		if ( strcmp(varName,paramName) == 0 )
		  dataType = FUNCAO(idxFunction).variaveis[i].tipo;
	}
	return dataType;
}

/**
 * Parameters of a function
 *
 * @param idxFunction Index of the function in the symbol table
 */
insertFunctionParameters(idxFunction)
int idxFunction;
{
  exec sql begin declare section;
		char *idPackage;
		char *moduleName;
		char *functionName;
		char *var_name;
		char *dataType;
		char *comments;
    int  i;
	exec sql end declare section;
	Parameters *parameters;

	if ( FUNCAO(idxFunction).parametros == (NAME_LIST *)0)
		return;

	StatDesc = "insert p4gl_fun_parameter";
	idPackage    = P4glCb.package;
	moduleName   = P4glCb.module;
	functionName = FUNCAO(idxFunction).name;
	// Aceder aos comentários da função caso existam
	parameters = FUNCAO(idxFunction).parsedDoc->parameterList;
	for (i = 0 ; i < parameters->idxParameters ; i++ )
	{
		comments = parameters->comment[i];
		if ( comments == NULL )
		  comments = "";
		var_name = parameters->name[i];
	  dataType = parameters->dataType[i];
		if ( dataType == NULL )
		  dataType = "--";
    exec sql insert into p4gl_fun_parameter (
	      id_package,module_name, function_name,
				item_num,var_name,data_type,comments
		  )
	    values (
			  :idPackage,:moduleName,:functionName, 
			  :i, :var_name, :dataType, :comments
     );
	}

	/* Para remover
	for (i = 0 ; i < FUNCAO(idxFunction).parametros->idx ; i++ )
	{
		var_name = FUNCAO(idxFunction).parametros->nome[i];
	  dataType = getParameterDataType(idxFunction,var_name);
 
    exec sql insert into p4gl_fun_parameter (
	      id_package,module_name, function_name,
				item_num,var_name,data_type
		  )
	    values (
			  :idPackage,:moduleName,:functionName, 
			  :i, :var_name, :dataType
     );
  }
	*/
}

/**
 * Return values of a function
 *
 * @param idxFunction Index of the function in the symbol table
 */
insertFunctionReturns(idxFunction)
int idxFunction;
{
  exec sql begin declare section;
		char *idPackage;
		char *moduleName;
		char *functionName;
		char *var_name;
		char *dataType;
		char *comments;
    int  i;
	exec sql end declare section;

	if ( FUNCAO(idxFunction).parsedDoc == (Comment *)0)
		return;

	StatDesc = "insert p4gl_fun_return";
	idPackage    = P4glCb.package;
	moduleName   = P4glCb.module;
	functionName = FUNCAO(idxFunction).name;
	// Aceder aos comentários da função caso existam
	for (i = 0 ; i <= FUNCAO(idxFunction).parsedDoc->returnIdx ; i++ )
	{
		var_name = "";
	  dataType = "";
		comments = FUNCAO(idxFunction).parsedDoc->returnList[i];
 
    exec sql insert into p4gl_fun_return (
	      id_package,module_name, function_name,
				item_num,var_name,data_type, comments
		  )
	    values (
			  :idPackage,:moduleName,:functionName, 
			  :i, :var_name, :dataType, :comments
     );
  }
}

/**
 * Todo task list
 *
 * @param idxFunction Index of the function in the symbol table
 */
insertFunctionTodos(idxFunction)
int idxFunction;
{
  exec sql begin declare section;
		char *idPackage;
		char *moduleName;
		char *functionName;
		char *comments;
    int  i;
	exec sql end declare section;

	if ( FUNCAO(idxFunction).parsedDoc == (Comment *)0)
		return;

	StatDesc = "insert p4gl_fun_todo";
	idPackage    = P4glCb.package;
	moduleName   = P4glCb.module;
	functionName = FUNCAO(idxFunction).name;
	// Aceder aos comentários da função caso existam
	for (i = 0 ; i <= FUNCAO(idxFunction).parsedDoc->todoIdx ; i++ )
	{
		comments = FUNCAO(idxFunction).parsedDoc->todoList[i];
 
    exec sql insert into p4gl_fun_todo (
	      id_package,module_name, function_name,
				item_num, comments
		  )
	    values (
			  :idPackage,:moduleName,:functionName, 
			  :i, :comments
     );
  }
}


/**
 * Insere utilização de tabelas
 */
insertTablesUsage(idxFunction)
int idxFunction;
{
  register int i,j;
	exec sql begin declare section;
		char *idPackage;
		char *moduleName;
		char *functionName;
		char operation; 
		char *tableName;
	exec sql end declare section;

	idPackage    = P4glCb.package;
	moduleName   = P4glCb.module;
	functionName = FUNCAO(idxFunction).name;
	for ( i = 0 ; i < FUNCAO(idxFunction).idx_sql; i++)
	{
		/* Retirei daqui a inserção do sql (inslib) */
		for ( j = 0 ; j < SQL_STMT(idxFunction,i).idx_tabelas ; j++ )
		{
			switch (SQL_STMT(idxFunction,i).operacao )
			{
				 case SQL_SELECT:
					  operation = 'S';
					  break;
				 case SQL_INSERT:
					  operation = 'I';
					  break;
				 case SQL_UPDATE:
					  operation = 'U';
					  break;
				 case SQL_DELETE:
					  operation = 'D';
					  break;
				 default:
					  operation = 'S';
			}
      StatDesc = "Insercao em Utilizacao de Tabela";
			exec sql 
			  insert into p4gl_table_usage ( 
				    id_table_usage, id_package, module_name,
	          function_name, table_name, operation )
					values (0, :idPackage,:moduleName,
					  :functionName, :tableName, :operation );
		} 

		/* @todo Inserir LIKE(s) */
		/*
		for ( j = 0 ; j < idx_tabelas ; j++ )
		{
		   ID_Table = InsUnixInsertTable(SQL_STMT(idxFunction,i).tabelas[j]);
			switch (SQL_STMT(idxFunction,i).operacao )
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

/**
 * Valida se o processo é válido
 *
 * @param idProcess Chave única do processo a validar
 * @return 0 - Existe processo com chave, !=0 caso contrário
 */
isValidProcess(idProcess)
  exec sql begin declare section;
		PARAMETER char *idProcess;
	exec sql end declare section;
{
  exec sql begin declare section;
	  int numProcesses;
  exec sql end declare section;

  numProcesses = 0;
  exec sql select count(*)
		into :numProcesses
	  from p4gl_process
		where id_process = :idProcess;

  if ( numProcesses > 0 ) 
	  return 0;
	return 1;
}



