/**
 * @file
 *
 * Program initialization functions.
 *
 * It deals with the initializations of parameters (with getopt) and the
 * possible execution by other mean (linking with other main).
 */

#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "p4gl_symtab.h"

/** Flag to set when the file name is assigned */
static existe_ficheiro = 0;

/**
 * Sets the 4gl source file name to be parsed.
 * 
 * @param sourceFileName The source file name to be parsed
 */
void setFglSourceFile(char *_fglSourceFile)
{
  FicheiroInput = strdup(_fglSourceFile);
  existe_ficheiro = 1;
}

/**
 * Sets the debug flag.
 *
 * @param _debug The debug flag to be assigned.
 */
void setDebug(int _debug)
{
  dbug = _debug;
}

/**
 * Sets the verbose flag.
 *
 * @param _verbose The verbose flag value.
 */
void setVerbose(int _verbose)
{
  verbose = _verbose;
}

/**
 * Sets the flag that indicatesd that we should insert the information at the 
 * database.
 *
 * @param _repositoryInsert The value of the flag.
 */
void setRepositoryInsert(int _repositoryInsert)
{
  InsertInDatabase = 1;
}

/**
 * Sets the warning level.
 *
 * @param _warningLevel The warning level to be used.
 */
void setWarningLevel(int _warningLevel)
{
  WarningLevel = _warningLevel;
}

/**
 * Sets the database name where the repository reside.
 *
 * @param _databaseName The name of the database.
 */
void setDatabaseName(char *_databaseName)
{
  P4glCb.database = strdup(_databaseName);
}

/**
 * Set the flag that indicates that we should generate fgldoc for the module.
 *
 * @param _fgldocGen The value to be assigned to the flag.
 */
void setFgldocGen(int _fgldocGen)
{
  generateFglDoc = _fgldocGen;
}

/**
 * Sets the standard comments flag.
 *
 * @param _standardComments The value of the flag to be seted.
 */
void setStandardComments(int _standardComments)
{
  standardComments = _standardComments;
}

/**
 * Sets the directory name where the fgldoc file should be generated.
 *
 * @param _docFileDir The directory name.
 */
void setDocFileDir(char *_docFileDir)
{
  P4glCb.docFileDir = strdup(_docFileDir);
}

/**
 * Sets the package name.
 *
 * @param _package The package name.
 */
void setPackage(char *_package)
{
  P4glCb.package = strdup(_package);
}

/**
 * Insert in the control record the options sended as program parametrers.
 *
 * The string with the options are relative to the repository options 
 * (-o switch).
 *
 * @options The string containing the repository options.
 */
static void setRepositoryOptions(char *options)
{
  if ( index(options,'t') != NULL || index(options,'T') != NULL )
    P4glCb.repositoryOptions.insertTableUsage = 1;
  /** @todo - The missing configuration options */
}


/**
 * Initialize the variable that contains the database name from the environment
 * variable DATABASE
 */
static void initDatabase(void)
{
  if ( getenv("DATABASE") == NULL )
    setDatabaseName("p4gl_repository");
  else
    setDatabaseName(getenv("DATABASE"));
  if ( P4glCb.database[0] == '\0' || strlen(P4glCb.database) == 0 )
    setDatabaseName("p4gl_repository");
}

/**
 * Parse the comand line arguments and acording to the passed values
 * set(s) the properties.
 *
 * @param argc The argument count
 * @param argv The argument values
 */
void initArguments(int argc, char *argv[])
{
  int c;
  extern char *optarg;
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
    {"insert_process", 1, 0, 'x'},
    {0, 0, 0, 0},
  };

  /* while ( (c=getopt(argc,argv,"f:dviw:h?csl:p:b:")) != -1) */
  while ( ( c = getopt_long (argc, argv, "f:dviw:h?csl:p:b:",
                        long_options, &option_index) ) != -1)
  {
    switch(c)
    {
      case 'f':                                       /* File */
        setFglSourceFile(optarg);
        break;

      case 'd':                                       /* Debug mode */
        setDebug(1);
        break;

      case 'v':                                       /* Verbose mode */
        setVerbose(1);
        break;

      case 'i':                                       /* Repository Insert */
        setRepositoryInsert(1);
        break;

      case 'w':                                  /* Warning level */
        setWarningLevel(atoi(optarg));
        break;

      case 'b':                                  /* Database Name */
        setDatabaseName(optarg);
        break;

      case 'c':                                  /* Documentation generation*/
        setFgldocGen(1);
        break;

      case 's':                                  /* Load standard comments */
        setStandardComments(1);
        break;

      case 'l':                            /* Documentation dir (location)*/
        setDocFileDir(optarg);
        break;

      case 'p':                                       /* Package */
        setPackage(optarg);
        break;

      case 'o':                                       /* Package */
        setRepositoryOptions(optarg);
        break;

      case 'h':                                  /* Warning level */
      case '?':
        /* Isto não está actualizado */
        printf(
           "Usage: p4gl [-h] [-d] [-i] [-v] [-w level] -f ficheiro.4gl\n");
        printf("   -h : Display this help message\n");
        printf("   -d : Debug mode\n");
        printf("   -i : Insert in the repository\n");
        printf("   -v : Verbose mode\n");
        printf("   -w : Warning level (1..10)\n");
        printf("   -c : Generate documentation\n");
        printf("   -s : Use standard comments for documentation\n");
        printf("   -p package : Nome do package\n");
        exit(0);

      case 'x':                            
        P4glCb.insertProcess = 1;
        break;

      /* Help */
      /* case 'E'  :  Only pre-processing */
      /* case  L   :  Do NOT load symbol table */
      /* Load only some objects */
      /* case '?':     Option not valid */
      /* case ':':     Missing option   */

    }
  }
}

/**
 * Opens the file where the syntax error it wil be stored.
 *
 * The log file name is in a global variable just as the file pointer after
 * opening the file.
 */
static void openLogFile(void)
{
  char logfile[64];
  char logdir[35];
  mode_t originalUmask;

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

  originalUmask = umask((mode_t)0);
  sprintf(logfile,"%s/p4gl.log",logdir);

  Log = fopen(logfile,"a");
  if ( Log == ((FILE *)0 ))
  {
   fprintf(stderr,"Erro a abrir ficheiro log <%s>\n",logfile);
   exit(1);
  }
  umask(originalUmask);
}
/**
 * Variable and symbol table initialization. 
 * This is the first phase only.
 */
void initP4glPhaseOne(void)
{
  extern int ID_Modulo;
  char existe_ficheiro;

  openLogFile();
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
  P4glCb.parsedComment     = (Comment *)0;
  P4glCb.package = strdup(".");
  P4glCb.insertProcess     = 1;
  initDatabase();
  initCommentStateMachine();

  /* Variaveis temporarias para passagem de valores entre regras */
  /* Lixo para remover quando se implementar o $$ na maioria das regras */
  Variaveis = (VARS *)0;
}

/**
 * It open(s) the 4gl source file.
 *
 * The name of the file is stored in global variable.
 *
 * The File pointer identifying the opened file is leaved in a global
 * variable to.
 *
 * @return The error code of the action:
 *   1 : The file was opened with sucess.
 *   0 : There was an error opening the file.
 */
static int openInputFile(void)
{
  fin_ptr = fopen(FicheiroTemp,"r");
  if ( fin_ptr == ((FILE *)0 ))
  {
   fprintf(stderr,"Erro a abrir ficheiro do source (.4gl) : <%s>\n",
        FicheiroTemp);
   perror("ERRO");
   return 0;
  }
  return 1;
}

/**
 * Get Dir Name from dir Path.
 *
 * It saves complete path name of the file being parsed.
 *
 * @param dirPath The complete directory path
 */
static void getDirName(char *dirPath)
{
  register short i;
  short len;

  RClipp(dirPath);
  FilePath = (char *)malloc(strlen(dirPath)+strlen(FicheiroInput)+2);
  sprintf(FilePath,"%s/%s",dirPath,FicheiroInput);
  len = strlen(dirPath);
  for ( i = len ; i > 0 ; i-- )
  {
    if ( dirPath[i] == '/' )
    {
      strcpy(FileDirectory,dirPath+i+1);
      return;
    }
  }
  strcpy(FileDirectory,dirPath);
}


/**
 * Get the directory name and path of the file being parsed.
 *
 * It uses the information in the global variables.
 */
static void getDirectoryFromFile(void)
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
           getDirName(PathDirectory);
        free(PathDirectory);
        return;
      }
       /* Concatenar o pwd com o resto */
      PathDirectory = strcat(getcwd((char *)0,256),
                         substr(FicheiroInput,0,i-1));
      getDirName(PathDirectory);
      free(PathDirectory);
       return;
    }
  }
  /* Nao descobriu /, portanto a directoria eh o pwd */
  PathDirectory = getcwd((char *)0,256);
  getDirName(PathDirectory);
  free(PathDirectory);
}



/**
 * Phase two. After setting the execution properties
 *
 * Abstract tree initialization.
 * Input (4gl source) file opening.
 *
 * @return The status returning code:
 *   0 : There was an error initializing.
 *   1 : Everithing OK.
 */
int initP4glPhaseTwo(void)
{
  /** @todo : This test should return error */
  if ( ! existe_ficheiro )
    P4glError(ERROR_EXIT,
       "Utilizacao: p4gl [-h] [-d] [-i] [-v] -f %s\n","ficheiro.4gl");

  P4glVerbose("4gl Pre-Processing\n");
  getDirectoryFromFile(); 
  P4glVerbose("Directory %s\n",FileDirectory);
  P4glPreProcessing();
  if ( !openInputFile() )
    return 0;
  yyin = fin_ptr;

  initSymtab();                 /* Inicializacao da tabela de simbolos */
  return 1;
}



