
/**
 * @file
 * Contains the prototype declaration for external functions 
 *
 * $Id: p4gl.h,v 1.2 2003-01-06 20:16:38 saferreira Exp $
 */

/* From ParseComment.c */
// #include "ParseComment.h"

/* From p4gl_ld_st.c */
void InitP4gl(int argc,char *argv[]);
void StInsVarListDeclaration(NAME_LIST *List,char *DataType);
void StInsertVariableUsage(char *nome,int linha,int utilizacao);
void StInsertVariableListUsage(NAME_LIST *List,int utilizacao);
void StInsertCursorDeclaration(char *NomeCursor,int Tipo,short Prepared);
void StInsertCursorUsage(char *nome,int linha,int utilizacao);
void defineFound(void);
void StInsertFunction(char *FunctionName,int ultima_linha,NAME_LIST *arguments);
void StInsertLineFunction(int linha,int functionType);
void StInsertFunctionCall(char *FunctionName,int linha);
void StUpdFCUsage(char *usage);
void StInsertTable(char *NmTable);
void StIncrementTable(void);;
void StInsertSQL(int operacao,int linha);
void StInsertSQLTxt(char *SqlTxt);
void OrderSymtab(void);
void InsertNameList(NAME_LIST **Destino,NAME_LIST *Origem,char *Nome,int Linha);
char *GetListConcat(NAME_LIST *List, char *ch);
void CleanNameList(NAME_LIST *List);
void CleanP4gl(void);
void GlobalsInclude(char *NmFicheiro);
void insertRepositoryOptions(char *options);

/* From p4gl_util.c */
void P4glError(int errorType,char *fmt,...);
void P4glWarning(int errorLevel,char *fmt,...);
void P4glVerbose(char *fmt,...);
void P4glDebug(char *fmt,...);
void RClipp(char *str);
void Upshift(char *str);
void Downshift(char *str);
void copystr(char *StrDest,char *StrOrig);
void tiraAspas(char *str);
char *CpStr(char *fmt,...);
void BaseName(char *str);
char *fileWithoutExtension(char *str);
char *substr(char *str, short start, short finish);
int IsEmpty(char *Str);

/* From m_p4gl.c */
void CopyToken(char *YYText,int TokenType);
void executeActions(void);

/* From GenParameters.c */
Parameters *initParameters(int maxParameters);
void addParameter(Parameters *parameters,char *name,char *comment);
void setParameterName(Parameters *parameters, char *name);
void setParameterComments(Parameters *parameters, char *comment);
void setParameter(Parameters *parameters,char *name,char *comment,int idx);
char *getParameterName(Parameters *parameters,int idx);
char *getParameterComment(Parameters *parameters,int idx);

/* From p4gl_parse.c */
int GetReserved(char *YYText);
int IsFglFunction(char *NmFunction);
int IsFglKey(char *StrKey);
int IsFglInternalVariable(char *InternalVariable);
int IsFglColor(char *Color);

/* From InsertP4glRep.c */
void insertP4glRep(void);

/* p4gl_dump.c */

/* From P4glLexFuncs.c */
void CopyToken(char *YYText,int TokenType);

/* From actions.c */
int parseFgl(void);

/* From P4glInit.c */
void setFglSourceFile(char *_fglSourceFile);
void setDebug(int _debug);
void setVerbose(int _verbose);
void setRepositoryInsert(int _repositoryInsert);
void setWarningLevel(int _warningLevel);
void setDatabaseName(char *_databaseName);
void setFgldocGen(int _fgldocGen);
void setStandardComments(int _standardComments);
void setDocFileDir(char *_docFileDir);
void initArguments(int argc, char *argv[]);
void setPackage(char *_package);
void initP4glPhaseOne(void);
int initP4glPhaseTwo(void);

/** From P4glAbstractTree.c */
int getFunctionsIdx(void);
FUNCTION *getFunction(int sequence);
int getTableFunctionUsageIdx(FUNCTION *function);
TableUsage *getFunctionTableUsage(FUNCTION *function,int sequence);
void setFunctionTableUsageIdx(FUNCTION *function,int idxTableUsage);
void addFunctionTableUsage(FUNCTION *function, TableUsage *tableUsage);
int getFunctionSqlIdx(FUNCTION *function);
SQL *getFunctionSql(FUNCTION *function,int sequence);
int getSqlTableIdx(SQL *sql);
char *getSqlTable(SQL *sql,int sequence);
