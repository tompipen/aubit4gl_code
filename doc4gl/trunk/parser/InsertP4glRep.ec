
/**
 * @file
 * Insert the information in a repository with format called p4gl_repository.
 *
 * The base information is stored in the abstract tree loaded by the parser.
 * Reads that information and store it in the relational repository.
 *
 * @todo : Implement the repsoitory with all possible information.
 *
 */

#include <stdio.h>
#include <unistd.h>
#include <varargs.h>
#include "p4gl_symtab.h"
#include "p4gl.h"


/** The statement description */
extern char *StatDesc;

exec sql whenever sqlerror call SqlErrors;


/**
 * Insert the package (in p4gl_package) if does not exist.
 *
 * @param idPackage The identifier of the package
 */
static void updatePackage(idPackage)
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
 * Delete everithing related to a 4gl module.
 *
 * @todo - Método que verifique apenas se já existe o módulo.
 *
 * @param idPackage The package primary key.
 * @param moduleName The 4gl module name.
 */
static void deleteModule(idPackage,moduleName)
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

  StatDesc = "Delete p4gl_form_usage";
  exec sql delete from p4gl_form_usage 
    where id_package = :idPackage and module_name = :moduleName;

  StatDesc = "Delete p4gl_fun_process";
  exec sql delete from p4gl_fun_process 
    where id_package = :idPackage and module_name = :moduleName;

  StatDesc = "Delete p4gl_table_usage";
  exec sql delete from p4gl_table_usage 
    where id_package = :idPackage and module_name = :moduleName;

  StatDesc = "Delete p4gl_function";
  exec sql delete from p4gl_function
    where id_package = :idPackage and module_name = :moduleName;

  StatDesc = "Delete p4gl_mod_todo";
  exec sql delete from p4gl_mod_todo 
    where id_package = :idPackage and module_name = :moduleName;

  StatDesc = "Delete p4gl_module";
  exec sql delete from p4gl_module 
    where id_package = :idPackage and module_name = :moduleName;

}

/**
 * Insert a new module.
 *
 * @todo - Ver como se comporta quando módulo indefinido (NULL)
 * @param idPackage The package primary key.
 * @param moduleName The 4gl module name.
 * @param comments The comments of the module.
 */
static void insertModule(package,module,comments)
    char *package;
    char *module;
	  Comment *comments;
{
  exec sql begin declare section;
    char *idPackage;
    char *moduleName;
		char *author;
		char *revision;
		char *deprecated;
    char *commentsText;
  exec sql end declare section;
  StatDesc = "insert p4gl_module";

	idPackage = package;
	moduleName = module;
  author = comments->author;
  if ( author == NULL )
	  author = " ";

  revision = comments->revision;
  if ( revision == NULL )
	  revision = " ";

  if ( comments->deprecated == 1 )
	  deprecated = "Y";
	else
	  deprecated = "N";

  commentsText = getCommentBuffer(comments);
  if ( commentsText == NULL )
    commentsText=" ";
  /* printf("Comments <%s>\n",comments); */
  exec sql insert into p4gl_module (id_package,module_name,author,revision,deprecated,comments) 
	  values
      (:idPackage,:moduleName,:author,:revision,:deprecated,:commentsText);
}

/**
 * Validate if the process is valid (exists in p4gl_process).
 *
 * @param idProcess The primary key of the process to be validated.
 * @return 0 - There is a process with that key, !=0 Otherwise
 */
static int isValidProcess(idProcess)
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

/**
 * Insert a process in the p4gl_process table. This is used to 
 * let the docuemnter work even if the process does not exist
 * letting the users to fix the processes later.
 *
 * @todo : Fix the errors.
 *
 * @param idProcess The primary key of the process to be validated.
 */
static int insertProcess(idProcess)
  exec sql begin declare section;
    PARAMETER char *idProcess;
  exec sql end declare section;
{
  exec sql begin declare section;
    int numProcesses;
		char strProcess[20];
  exec sql end declare section;

	sprintf(strProcess,"unknown <%s>",idProcess);
  numProcesses = 0;
  exec sql insert into p4gl_process (id_process,disp_process,den_process)
	  values (:idProcess,:idProcess,:strProcess);
}


/**
 * Insert the assignment of functions to database process.
 *
 * @param idxFunction Index of the function in the array
 */
static void insertFunctionProcess(int idxFunction)
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
    if ( isValidProcess(idProcess) != 0 )
		{
			if ( !P4glCb.insertProcess )
			{
        /* @todo - Devia usar rotina de erros do p4gl */
        printf("Error : The process <%s> does not exist\n",idProcess);
				continue;
			}
			insertProcess(idProcess);
	  }

    exec sql insert into p4gl_fun_process (
      id_process,
      id_package,module_name,
      function_name
    )
     values (:idProcess,:idPackage,:moduleName,:functionName);
  }
}

/**
 * Checks the local variables declared in the function to find the data type of
 * the parameter.
 * 
 * @param idxFunction Index of the function.
 * @param varName Parameter variable name.
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
		{
      dataType = FUNCAO(idxFunction).variaveis[i].tipo;
			break;
	  }
  }
  /** @fixme : Possiblem memory leak */
  return strdup(dataType);
}


/**
 * Insert the parameters of a function
 *
 * @param idxFunction Index of the function in the symbol table
 */
static void insertFunctionParameters(idxFunction)
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
  if ( FUNCAO(idxFunction).parsedDoc == (Comment *)0 )
    return;
  parameters = FUNCAO(idxFunction).parsedDoc->parameterList;
  for (i = 0 ; i < parameters->idxParameters ; i++ )
  {
    comments = parameters->comment[i];
    if ( comments == NULL )
      comments = "";
    var_name = parameters->name[i];
    dataType = parameters->dataType[i];
    if ( dataType == NULL )
      dataType = getParameterDataType(idxFunction,var_name);
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
static void insertFunctionReturns(int idxFunction)
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
 * Insert the Todo task list loaded in abstract table to the repository.
 *
 * @param idxFunction Index of the function in the symbol table
 */
static void insertFunctionTodos(int idxFunction)
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
 * Insert all table usage.
 * The table(s) usage in a function could be extracted by the parser (in 
 * explicit SQL or by \@table tag.
 *
 * @param idxFunction Index of the function for where we want to get table(s)
 * usage.
 */
static void insertTablesUsage(int idxFunction)
{
  register int i,j;
  exec sql begin declare section;
    char *idPackage;
    char *moduleName;
    char *functionName;
    char operation; 
    char *tableName;
  exec sql end declare section;
  FUNCTION *function;

  idPackage    = P4glCb.package;
  moduleName   = P4glCb.module;
  function = getFunction(idxFunction);
  functionName = function->name;
  for ( i = 0 ; i < getFunctionTableUsageIdx(function) ; i++)
  {
    TableUsage *tableUsage;
    tableUsage = getFunctionTableUsage(function,i);
    tableName = tableUsage->tableName;
    switch (tableUsage->operation)
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
}

/**
 * Insert a new function declaration in p4gl_function.
 *
 * @todo - Ver se não dá erro quando não tem comentários (NULL)
 *
 * @param idxFunction Index of function in array of abstract tree.
 */
static void insertFunction(int idxFunction)
{
  exec sql begin declare section;
    char *idPackage;
    char *moduleName;
    char *functionName;
    char *functionType;
    char *comments;
    char *deprecated;
    char *author;
    char *since;
  exec sql end declare section;

  StatDesc = "insert p4gl_function";
  idPackage    = P4glCb.package;
  moduleName   = P4glCb.module;
  functionName = FUNCAO(idxFunction).name;
  comments     = getCommentBuffer(FUNCAO(idxFunction).parsedDoc);
  if ( FUNCAO(idxFunction).functionType == FUNCTION_TYPE )
    functionType = "F";
  else
    functionType = "R";

  if ( FUNCAO(idxFunction).parsedDoc != (Comment *)0 ) {
    if ( getCommentDeprecated(FUNCAO(idxFunction).parsedDoc))
      deprecated = "Y";
    else
      deprecated = "N";
  
    author = FUNCAO(idxFunction).parsedDoc->author;
	  if ( author == NULL )
	    author = " ";
  
    since = FUNCAO(idxFunction).parsedDoc->since;
	  if ( since == NULL )
	    since = " ";
	}
	else {
	  deprecated = "N";
		author = " ";
		since = " ";
	}
  
  if ( comments == (char *)0 )
    comments=" ";
  exec sql insert into p4gl_function (
      id_package,module_name,
      function_name,function_type,deprecated,comments,author,since
    )
    values (:idPackage,:moduleName,:functionName,:functionType,:deprecated,
            :comments,:author,:since);
  insertFunctionParameters(idxFunction);
  insertFunctionReturns(idxFunction);
  insertFunctionProcess(idxFunction);
  insertFunctionTodos(idxFunction);
  insertTablesUsage(idxFunction);
}


/**
 * Insert all the functions loaded in the abstract tree.
 */ 
static void insertFunctions(void)
{
  register int i;

  for ( i = 0 ; i < P4glCb.idx_funcoes ; i++ )
    insertFunction(i);
}

/*
 * Start the connection to the database
 * 
 * @return - 1 : Connection established
 *         - 0 : Otherwise
 */
static int connectDb(void)
{
exec sql begin declare section;
   char StrStat[512];
exec sql end declare section;

  if ( DBConnected )
    return 1;
  sprintf(StrStat,"database %s",P4glCb.database);
  StatDesc = "Preparacao de instrucao de abertura da BD";
  exec sql prepare opndb from :StrStat;
  StatDesc = "Abertura da BD";
  exec sql execute opndb ;
  if ( sqlca.sqlcode != 0 )
  {
    P4glError(ERROR_EXIT," %d open the database %s\n",
      sqlca.sqlcode,P4glCb.database
    );
    return 0;
  }
  DBConnected = 1;
  return 1;
}



/**
 * Entry function to the insertion of the information in the abstract tree to 
 * the repository.
 */
void insertP4glRep(void)
{
  exec sql whenever sqlerror call SqlErrors;
  if ( ! connectDb() )
    return;
  deleteModule(P4glCb.package,P4glCb.module);
  updatePackage(P4glCb.package);

  insertModule(
    P4glCb.package,
    P4glCb.module,
    P4glCb.parsedComment
  );
  insertFunctions();
}

