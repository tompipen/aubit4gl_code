Arbol Asigna_nombre(char *);
Arbol Asigna_valor(double);
Arbol Busca_Var(char *,Arbol);
Arbol Busca_Fun(char *);
Arbol Existe_Var(char *);
int tam_var(char *);

void genCodigo();
void genParams(Arbol);
void genParam(char *);
void genParamRecord(char *);
void genVariables(Arbol,char *);
void genVariable(Arbol, char *);
void genRecord(Arbol);

void genFuenteC(Arbol snt);
void genMenu(Arbol snt);
void genBrowse(Arbol snt);
void genForm(Arbol snt);
void genFormDisplay(Arbol snt);
void genFormCreate(Arbol snt);
void genFormExit(Arbol snt);
void genFormContinue(Arbol snt);
void genValidaCamposForm(Arbol snt);
void genFormValidate(Arbol snt,bool actual);
void genFormCurrent(Arbol snt);

void genDeclare(Arbol);
void genOpenCursor(Arbol snt);
void generaOpenCursor(char *c);
void genCloseCursor(Arbol snt);
void genFetchCursor(Arbol snt);
void genForeach(Arbol);
void genContinueForeach(Arbol snt);
void genExitForeach(Arbol snt);
void genSelect(Arbol);
void genExecSQL(Arbol);
void genInsert(Arbol);
void genDelete(Arbol);
void genTransacc(Arbol snt);
void genWhere(Arbol snt);
void genBinWhere(Arbol snt);
void genSelInto(Arbol vars);

void genReport(Arbol snt);
void genStartReport(Arbol snt);
void genFinishReport(Arbol snt);
void genOutputReport(Arbol snt);
void genVarBeforeGrp(Arbol lst);
void genBeforeGrp(Arbol lst);
void genAfterGrp(Arbol lst);
void genPrint(Arbol exp);

void genFunciones();
void genFuncion(Arbol);
void genSentencias(Arbol);
void genSentencia(Arbol);
void genAsignacion(Arbol snt);
void genExitProgram(Arbol snt);
void genIf(Arbol snt);
void genWhile(Arbol snt);
void genContinueWhile(Arbol snt);
void genExitWhile(Arbol snt);
void genFor(Arbol snt);
void genContinueFor(Arbol snt);
void genExitFor(Arbol snt);
void genLlamada(Arbol snt);
void genRetorno(Arbol snt);
void genDelay(Arbol snt);

void genAbVentana(Arbol snt);
struct atributos lee_atributos(Arbol snt);
void genEscribir(Arbol snt);
void genLeer(Arbol snt);
void genLeerExit(Arbol snt);

void genCieVentana(Arbol snt);
void genMovVentana(Arbol snt);
void genClearWindow(Arbol snt);
void genCurVentana(Arbol snt);

void genExpresion(Arbol);
void genConstante(Arbol);
void genCadena(Arbol snt);
void genUnaria(Arbol expr);
void genBinaria(Arbol snt);
void genNombre(Arbol snt);
void genSubcadena(Arbol expr);
void genUsing(Arbol expr);
void genClipped(Arbol expr);

void genera(int, char *fmt,...);
enum tipos tipo_exp(Arbol exp);
enum tipos tipo_var(char *);
char *chr_tipo_var(char *var);
enum tipos tipo_fun(char *);
Arbol tipo_campo_bd(char *, char*);

Arbol Campos_reg(char *);
Arbol Campos_tabla(char *);

char *charListaId(Arbol);

void error(char *,...);
void warning(char *,...);

