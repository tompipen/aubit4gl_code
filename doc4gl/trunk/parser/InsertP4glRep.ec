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
#include <stdarg.h>

#ifndef WIN32
	#include <string.h>
#endif

#include "p4gl_symtab.h"
#include "p4gl.h"
#include <stdlib.h>			/* free() exit()*/


/** The statement description */
extern char *StatDesc;
static void insertGlobalsFiles(char *package,char *module);

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
  P4glDebug("Deleting %s module related information form db...\n",moduleName);

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

  StatDesc = "Delete p4gl_mod_todo";
  exec sql delete from p4gl_mod_todo
    where id_package = :idPackage and module_name = :moduleName;

  StatDesc = "Delete p4gl_call_parameter";
  exec sql delete from p4gl_call_parameter
    where function_call_id in
	(select function_call_id
        from p4gl_function_call
        where p4gl_function_call.id_package = :idPackage
		and p4gl_function_call.module_name = :moduleName);

  StatDesc = "Delete p4gl_func_calls";  //this table is populated from loadform.4gl and will be invalidated is this is deleted
  exec sql delete from p4gl_func_calls
    where function_call_id in
    (select function_call_id
        from p4gl_function_call
        where p4gl_function_call.id_package = :idPackage
		and p4gl_function_call.module_name = :moduleName);

  StatDesc = "Delete p4gl_function_call";
  exec sql delete from p4gl_function_call
    where id_package = :idPackage and module_name = :moduleName;

  StatDesc = "Delete p4gl_globals_usage";
  exec sql delete from p4gl_globals_usage
    where id_package = :idPackage and module_name = :moduleName;

  StatDesc = "Delete p4gl_function";
  exec sql delete from p4gl_function
    where id_package = :idPackage and module_name = :moduleName;

  StatDesc = "Delete p4gl_module_prog"; // this is populated from mkf and will be invalidate if this is deleted
  exec sql delete from p4gl_module_prog
    where id_package = :idPackage and module_name = :moduleName;

  StatDesc = "Delete p4gl_glob_module"; // this is populated from loadform and will be invalidate if this is deleted
  exec sql delete from p4gl_glob_module
    where glob_incl_id in
	(select glob_incl_id
        from p4gl_glob_incl
        where p4gl_glob_incl.id_package = :idPackage
		and p4gl_glob_incl.module_including = :moduleName);

/*
FIXME: if error occurs here, we will see something like:
 SQL Error encountered at Delete p4gl_glob_module: -217
make: *** [doc4gl.test] Error 1

BUT fgldoc WILL NOT NOTICE THE ERROR and say:
	[LOG] : AS6.4gl Parsed
 AND CONTINUE!!!!
*/



  StatDesc = "Delete p4gl_glob_incl";
  exec sql delete from p4gl_glob_incl
    where id_package = :idPackage and module_including = :moduleName;

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
    char *since;
    char *see;
    char *commentsText;
  exec sql end declare section;
  StatDesc = "insert p4gl_module";

  idPackage = package;
  moduleName = module;
  if ( comments != (Comment *)0 )
  {
    author = comments->author;
    if ( author == NULL )
      author = " ";

    revision = comments->revision;
    if ( revision == NULL )
      revision = " ";

    since = comments->since;
    if ( since == NULL )
      since = " ";

    see = comments->see;
    if ( see == NULL )
      see = " ";

    if ( comments->deprecated == 1 )
      deprecated = "Y";
    else
      deprecated = "N";
  }
  else
  {
    author = " ";
    since = " ";
    see = " ";
    revision = " ";
    deprecated = "N";
  }

  commentsText = getCommentBuffer(comments);
  if ( commentsText == NULL )
    commentsText=" ";

  exec sql insert into p4gl_module
    (id_package,module_name,author,revision,deprecated,since,see,comments)
    values
      (:idPackage,:moduleName,:author,:revision,:deprecated,:since,:see,:commentsText);

	P4glDebug("Added module -%s-\n",moduleName);

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
static void 
insertProcess(idProcess)
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
  P4glDebug("%s\n",StatDesc);

  idPackage    = P4glCb.package;
  moduleName   = P4glCb.module;
  functionName = FUNCAO(idxFunction).name;
  for ( i = 0 ; i < FUNCAO(idxFunction).parsedDoc->processIdx ; i++ )
  {
	P4glDebug("i=-%d-\n",i);
	idProcess = FUNCAO(idxFunction).parsedDoc->processCode[i];
    RClipp(idProcess);
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

	P4glDebug("Inserting idProcess -%s- for function _%s_\n",idProcess,functionName);

	exec sql insert into p4gl_fun_process
	( id_process,
      id_package,module_name,
      function_name
    ) values (
	 :idProcess,:idPackage,:moduleName,:functionName
	);
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
 * Insert the table usage (from comments ONLY) loaded in abstract table to the repository.
 *
 * @param idxFunction Index of the function in the symbol table
 */
/* NOT NEEDED - they are already added to table usage obtained by parsing 
source code - not shure where this happened ?

static void insertFunctionTablesUsageComments(int idxFunction)
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
  for (i = 0 ; i <= FUNCAO(idxFunction).parsedDoc->tableIdx ; i++ )
  {
	comments = FUNCAO(idxFunction).parsedDoc->tableList[i]->tableName;
	P4glDebug("Storing table comment %s\n",comments);
  }
}
*/
static void
insertFunctionGlobalsUsage(int idxFunction)
{
exec sql begin declare section;
    char *idPackage;
    char *moduleName;
    char *functionName;
    char *variableName;
    int onLine;
    int type;
exec sql end declare section;
VAR_USAGE *Next;

  if ( FUNCAO(idxFunction).parsedDoc == (Comment *)0)
    return;

  StatDesc = "insert p4gl_globals_usage";
  idPackage    = P4glCb.package;
  moduleName   = P4glCb.module;
  functionName = FUNCAO(idxFunction).name;

	Next = FUNCAO(idxFunction).var_usage;

	if ( Next == (VAR_USAGE *)0) {
	    P4glDebug("No GLOBALS\n");
		return;
	}

	P4glDebug("--------- GLOBALS referenced in function %s:\n",functionName);

	while (Next != (VAR_USAGE *)0) {

		//strcpy(p_id_process,id_process);   <<<<<< valgrind !!!!
		variableName=strdup(Next->nome);
        onLine=Next->linha;
        type=Next->utilizacao;

	    switch (type)
	    {
	      case READ_VAR:
	         P4glDebug("Usage: %s %d\n", variableName,onLine);
	        break;
	      case ASSIGNMENT:
	         P4glDebug("Assignment: %s %d \n",variableName,onLine);
	        break;
		  case GLOB_FILE:
/*
FIXME: this is NOT be related to function, but MODULE!
*/
			 P4glDebug("ERROR? GLOBALS file: %s %d \n",variableName,onLine);
            break;
	      default:
	         P4glDebug("ERROR-unknown: %s %d \n",variableName,onLine);
             exit (8);
	    }

	   //Insert it
       exec sql
       insert into p4gl_globals_usage
        (id_package,module_name,function_name,variable_name,line,type)
	   values
        (:idPackage,:moduleName,:functionName,:variableName,:onLine,:type);

	   Next = Next->next;
	}
}

/*
static void
DumpFunctions(void)
{
register int i,j;
VAR_USAGE *Next;

	for (i=0 ; i < P4glCb.idx_funcoes ; i++)
	{
		fprintf(f_dump,"NAME=Func  %s\n", P4glCb.functions[i].name);
		fprintf(f_dump,"Name : %s Line : %d Instructions : %d\n",
									 P4glCb.functions[i].name,
		                            P4glCb.functions[i].linha,
		                            P4glCb.functions[i].NInstrucoes);

		// Parameters / Arguments
		for (j = 0 ; j< IDX_ARG(i) ; j++) {
			printf("PARAMETER : %s\n", FUNCAO(i).parametros[j]);
		}

		// Functions called
		for (j = 0 ; j< IDX_FC(i) ; j++) {
			printf("%s %d\n",
				FUNC_CALL(i,j).name,
				FUNC_CALL(i,j).linha);
		}

		// GLOBALS usage
		Next = FUNCAO(i).var_usage;
		while (Next != (VAR_USAGE *)0) {
			if ( Next->utilizacao == READ_VAR )
	         printf("%s %d\n", Next->nome,Next->linha);
		  else //Assignment
	         printf("%s %d \n",Next->nome,Next->linha);
		   Next = Next->next;
		}
	}
}
*/

/**
 * Insert all table usage (database tables referenced in this function).
 * The table(s) usage in a function could be extracted by the parser (in
 * explicit/static SQL statement) or by \@table tag (when using dynamic/prepred SQL).
 *
 * @param idxFunction Index of the function for which we want to get table(s)
 * usage.
 */
static void insertTablesUsage(int idxFunction)
{
  exec sql begin declare section;
    char *idPackage;
    char *moduleName;
    char *functionName;
    char operation;
    char *tableName;
	char *p_id_process;
	char owner[129];
	char tabtype[1];
    char id_process[129];
    int numTables;
    int NumRows;
    int NumRows2;
  exec sql end declare section;
  FUNCTION *function;
  register int i;

  idPackage    = P4glCb.package;
  moduleName   = P4glCb.module;
  function = getFunction(idxFunction);
  functionName = function->name;

	StatDesc = "Inserting ussage of the database table";
	P4glVerbose("%s for function -%s-%d-\n",StatDesc,functionName,getFunctionTableUsageIdx(function));

  for ( i = 0 ; i < getFunctionTableUsageIdx(function) ; i++)
  {
	TableUsage *tableUsage;

//P4glDebug("loop -%d-\n",i);
	tableUsage = getFunctionTableUsage(function,i);
//P4glDebug("A\n");
	tableName = tableUsage->tableName;
//P4glDebug("1table -%s-\n",tableName);
    RClipp(tableName);
//P4glDebug("2table -%s-\n",tableName);
	LClipp(tableName);
//P4glDebug("table -%s-\n",tableName);

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
//P4glDebug("T=-%d-\n",IsTerminated(tableName));
//P4glDebug("NumRows=-%d-\n",NumRows);
//P4glDebug("table -%s-\n",tableName);

	exec sql select count(*) into :NumRows
        from systables
            where tabname = :tableName;

	if ( NumRows == 0 )
    {
		//P4glDebug("NOTFOUND\n");
		//P4glError(ERROR_EXIT,"Table -%s- does not exist in this database\n",tableName);
        /* This is not nececeraly an error; maybe it's a temp table, or maybe
        it's a DDL (create table) statement.
		*/
        strcpy(tabtype,"U"); //Doc4GL table types are T=table V=view U=undefined E=tEmporary
        strcpy(owner,"unknown");

    } else {
		exec sql select owner, tabtype into :owner, :tabtype
        from systables
            where tabname = :tableName;
			//Informix tabtyeps are Table or View

	    RClipp(owner);
		P4glDebug("Owner of table %s is %s\n",tableName,owner);
    }
	// check if we have this table
	numTables = 0;
	exec sql select count(*)
	    into :numTables
			from systableext
			    where tabname = :tableName
				and owner = :owner;
	if ( numTables == 0 )
    {
		//add table
		P4glDebug("New table %s\n",tableName);
		exec sql
	      insert into systableext (owner,tabname,tabtype)
	          values (:owner, :tableName, :tabtype );
    }

	/* FIXME: remove field tablename form p4gl_table_usage - use only tabname (FK to systableext)
      need to remove it from Doc4GL browser
    */

	P4glDebug("New table usage -%s-%s-%s-%s-%s-%s-%c-\n",idPackage,moduleName,functionName,tableName,owner,tableName,operation);

	exec sql
      insert into p4gl_table_usage (
            id_table_usage, id_package, module_name,
            function_name, table_name, operation,
			owner,tabname )
          values (0, :idPackage,:moduleName,
            :functionName, :tableName, :operation,
			:owner, :tableName );

	/* check if we have this function in the context of this process
	We are doing this to get the process for this function, so that
    we can apply same process to tables used in this function

	WARNING - check - is it already stored in database from comment? 
		- YES, in function insertFunctionProcess

	WARNING - function can have multiple processes associated with it -
        we should open a cursor and associate all processes, not as we
        currently do ("first 1")

	*/
	exec sql
		select  first 1 id_process into :id_process
			from p4gl_fun_process
			where function_name = :functionName
            and id_package = :idPackage
            and module_name = :moduleName;

	if (strcmp (SQLSTATE, "02000") == 0)
    {
		P4glDebug("NOTFOUND\n");
		strcpy(id_process,"");
    } else {
		//strcpy(p_id_process,id_process);   <<<<<< valgrind !!!!
		p_id_process=strdup(id_process);
		RClipp(p_id_process);
		sprintf(id_process,"%s",p_id_process);
		P4glDebug("Got process for function -%s- as -%s-\n",functionName,id_process);
    }

	if (IsEmpty (id_process))
    {
		/* we don't know process for this function */

		P4glDebug("New function/process for function %s\n",functionName);
		/* assume process by directory location */
        /*
		currpath = getcwd((char *)0,256);
        RClipp(currpath);
		Upshift(currpath);
		// src/ap
		P4glDebug("path:%s\n",currpath);
		p_id_process=substr(currpath, RightPos(currpath,1,"/")+1,strlen(currpath));
        */

        p_id_process=strdup(FileDirectory);
		Upshift(p_id_process);
		sprintf(id_process,"%s",p_id_process);
		//P4glDebug("process from path:%s\n",p_id_process);

	    /* insertFunctionProcess finction will do this checking:
		if ( isValidProcess(p_id_process) != 0 )
        {
			sprintf(id_process,"%s",p_id_process);
			P4glError(ERROR_EXIT,"Process -%s- does not exist\n",id_process);
        }
        */
        //insert function/process relationship

		//assign it to global array

		P4glDebug("curr index =-%d-\n",FUNCAO(idxFunction).parsedDoc->processIdx);

		FUNCAO(idxFunction).parsedDoc->processCode[FUNCAO(idxFunction).parsedDoc->processIdx]=strdup(p_id_process);
		FUNCAO(idxFunction).parsedDoc->processIdx=FUNCAO(idxFunction).parsedDoc->processIdx++;
		insertFunctionProcess(idxFunction);
    }

    /* now that we know process for this function, we can apply same process to
    this table */
//P4glDebug("Checking for table/process relationship -%s-%s-%s-\n",id_process,owner,tableName);
    /* check if we already have this table in the context of this process */

	exec sql select count(*) into :NumRows2
        from p4gl_table_process
        where owner = :owner
        and tabname = :tableName
        and id_process = :id_process
		;

//P4glDebug("GOT %d\n",NumRows2);
	if (NumRows2 == 0)
    {
		P4glDebug("New table/process relationship -%s-%s-%s-\n",id_process,owner,tableName);
		// Insert table/process relationship
		exec sql
		insert into p4gl_table_process
            (id_process, owner, tabname)
        values
            (:id_process,:owner, :tableName);
    }
//P4glDebug("end for\n");

  } // end for loop

//P4glDebug("Exit function\n");

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

	P4glDebug("Inserting function: pkg=%s module=%s func=%s type=%s\n",
    	idPackage,moduleName,functionName,functionType);

  exec sql insert into p4gl_function (
      id_package,module_name,
      function_name,function_type,deprecated,comments,author,since
    )
    values (:idPackage,:moduleName,:functionName,:functionType,:deprecated,
            :comments,:author,:since);

    /* TODO: add instructions_num, sql_num 
	- what is "locals" in HTML output? is that Local Variables count? */

  insertFunctionParameters(idxFunction);
  insertFunctionReturns(idxFunction);
  insertFunctionProcess(idxFunction);
  insertFunctionTodos(idxFunction);
  insertTablesUsage(idxFunction);
  //not needed insertFunctionTablesUsageComments(idxFunction);
  insertFunctionGlobalsUsage(idxFunction);

/*
  TODO:
  insertFormsUsage(idxFunction);

  comment.h:
  ...
  char       *formList[100];    / List of forms defined in the comment or found
  int        formIdx;           / Number of elements in the form list
  int         tableStarted;     / Internal state
} Comment;

    I DON'T THIS IS EXTRACTED BY THE PARSER AT THE MOMENT ?



*/

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

/**
 * Insert all the function calls loaded in the abstract tree.
 * Function calls relationships can only be resolved after all the
 * module/function and program/module information is in the database.
 * TODO: create program to establish this relationships.
 */
static void insertFunctionCalls()
{
   register int i,j;
  exec sql begin declare section;
    char *idPackage;
    char *moduleName;
    int NumRows;
    int Line;
	char FunctionCalling[129];
 	char FunctionCalled[129];
  exec sql end declare section;

    StatDesc = "insert p4gl_function_call";

  idPackage    = P4glCb.package;
  moduleName   = P4glCb.module;


	for (i=0 ; i < P4glCb.idx_funcoes ; i++) 	/* foreach function in this module */
	{
		for (j = 0 ; j< IDX_FC(i) ; j++) /* foreach function call in this function */
		{
            //FunctionCalling=strdup(P4glCb.functions[i].name);
            //FunctionCalled=strdup(FUNC_CALL(i,j).name);
            
            sprintf(FunctionCalling,"%s",P4glCb.functions[i].name);
            sprintf(FunctionCalled,"%s",FUNC_CALL(i,j).name);

			Line = FUNC_CALL(i,j).linha;

			P4glDebug("Function %s calls %s on line %d\n",
				P4glCb.functions[i].name,
				FUNC_CALL(i,j).name,
				FUNC_CALL(i,j).linha);

			/* check if we already have this function call. Since we deleted
            all this before strting processing this module, it should allways
            return ), unless if same function was called multiple times on the
			same line - in which case we will ignore folowing calls on the same
			line */
			exec sql
				select count (*) into :NumRows
		        from p4gl_function_call
			        where id_package = :idPackage
			        and module_name = :moduleName
			        and function_name = :FunctionCalling
            	    and calls_func_name = :FunctionCalled
                    and line = :Line;


			if (NumRows == 0)
		    {
				exec sql
				insert into p4gl_function_call
                (function_call_id,id_package,module_name,function_name,calls_func_name,line,call_type)
				values
				(0,:idPackage,:moduleName,:FunctionCalling,:FunctionCalled,:Line,"F");

                /* todo: extract & insert call_type: F-function R-report W-whenever error/warning call xxx */

                /* todo: extract & insert into p4gl_call_parameter */


            }   		// end if - relationsip between calling/called functions already exists
		}   			// end for - each call in function
	}  					// end for - each function in module
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
/*
$int nrows;
$char tabname[18];
int a;
*/


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
  insertFunctionCalls();

  //insertGlobalsFiles();
  insertGlobalsFiles(P4glCb.package,P4glCb.module);

  P4glDebug("Done inserting\n");

//exit (4);

}


/**
 * Insert information about GLOBALS files referenced in this module to the
 * the repository.
 */
static void insertGlobalsFiles(char *package,char *module)
{
int i;
  exec sql begin declare section;
    char *idPackage;
    char *moduleName;
    char *globFilename;
  exec sql end declare section;


  idPackage = package;
  moduleName = module;

//  idPackage    = P4glCb.package;
//  moduleName   = P4glCb.module;

  P4glDebug("GLOBALS files in module >%s< package >%s<:\n",moduleName,idPackage);

	for (i=0 ; i < P4glCb.idx_globais ; i++) 	/* foreach file referenced as GLOBALS in this module */
    {
        globFilename=strdup(P4glCb.globais[i].nome_ficheiro);
		P4glDebug("  %d=>%s<\n",i,globFilename);

		exec sql
			insert into p4gl_glob_incl
	        (glob_incl_id,module_including,glob_filename,id_package)
    	    values
        	(0,:moduleName,:globFilename,:idPackage);


    }

}

/*     This tables are NOT in Case Studio model - add them !

--table containing each occurrence of GLOBALS filename statement
--populated by p4gl

create table p4gl_glob_incl (
	glob_incl_id serial,                    -- primary key
	module_including char(64) not null,     -- name of the module INCLUDING file via GLOBALS stmt.
    glob_filename char(254) not null,       -- filename specified in GLOBALS stmt.
	id_package char(64) not null,
        primary key (glob_incl_id),
		foreign key (id_package,module_including)
		  references p4gl_module (id_package,module_name)

);


--table relating each occurance of GLOBALS stmt with a module that is included with it
--populated by endrun (loadforms.4gl) after all modules are known/loaded

--drop table p4gl_glob_module;

create table p4gl_glob_module (
	glob_incl_id integer,            		-- id of the GLOBALS statement
	module_included char(64) not null,  	-- name of the module INCLUDED in GLOBALS stmt.
	id_package char(64) not null,
		primary key (glob_incl_id),
		foreign key (glob_incl_id)
		  references p4gl_glob_incl (glob_incl_id),
		foreign key (id_package,module_included)
		  references p4gl_module (id_package,module_name)
);



*/


/* ================================ EOF ================================== */

