/* Fgl.h.  Generated automatically by treecc */
#ifndef __yy_Fgl_h
#define __yy_Fgl_h
#line 31 "Fgl.tc"


#define FunctionVector vector <Function> 

#line 10 "Fgl.h"

#include <new>

const int FglNode_kind = 1;
const int FglStatement_kind = 2;
const int FglIdentifier_kind = 3;
const int Variable_kind = 4;
const int FglExpression_kind = 5;
const int AbstractFunction_kind = 7;
const int AbstractInitVariable_kind = 11;
const int fglStatement_kind = 15;
const int FormRest_kind = 17;
const int FormName_kind = 18;
const int Initialize_kind = 14;
const int BinaryExpression_kind = 6;
const int FunctionList_kind = 9;
const int InitializeVariableList_kind = 10;
const int Function_kind = 8;
const int InitializeSingleVariable_kind = 12;
const int InitializeThruVariable_kind = 13;
const int OpenForm_kind = 16;
const int OpenFormFrom_kind = 19;

class FglNode;
class FglStatement;
class FglIdentifier;
class Variable;
class FglExpression;
class AbstractFunction;
class AbstractInitVariable;
class fglStatement;
class FormRest;
class FormName;
class Initialize;
class BinaryExpression;
class FunctionList;
class InitializeVariableList;
class Function;
class InitializeSingleVariable;
class InitializeThruVariable;
class OpenForm;
class OpenFormFrom;

class YYNODESTATE
{
public:

	YYNODESTATE();
	virtual ~YYNODESTATE();

#line 1 "cpp_skel.h"
private:

	struct YYNODESTATE_block *blocks__;
	struct YYNODESTATE_push *push_stack__;
	int used__;
#line 67 "Fgl.h"
public:

	FglIdentifier *FglIdentifierCreate(char * name);
	Variable *VariableCreate(char * name);
	FormName *FormNameCreate(char * name);
	Initialize *InitializeCreate(InitializeVariableList * init_val_list, FglNode * form_rest);
	FunctionList *FunctionListCreate(FglNode * expr1, FglNode * expr2);
	InitializeVariableList *InitializeVariableListCreate(FglNode * expr1, FglNode * expr2);
	Function *FunctionCreate(FglNode * functionName);
	InitializeSingleVariable *InitializeSingleVariableCreate(FglNode * variable);
	InitializeThruVariable *InitializeThruVariableCreate(FglNode * first_variable, FglNode * second_variable);
	OpenForm *OpenFormCreate(FglNode * form_name, FglNode * form_rest);
	OpenFormFrom *OpenFormFromCreate(char * open_form_from_place);

public:

	void *alloc(size_t);
	void dealloc(void *, size_t);
	int push();
	void pop();
	void clear();
	virtual void failed();
	virtual char *currFilename();
	virtual long currLinenum();

};

class FglNode
{
protected:

	int kind__;
	char *filename__;
	long linenum__;

public:

	int getKind() const { return kind__; }
	const char *getFilename() const { return filename__; }
	long getLinenum() const { return linenum__; }
	void setFilename(char *filename) { filename__ = filename; }
	void setLinenum(long linenum) { linenum__ = linenum; }

protected:

	friend class YYNODESTATE;

	FglNode(YYNODESTATE *state__);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FglNode();

};

class FglStatement : public FglNode
{
protected:

	friend class YYNODESTATE;

	FglStatement(YYNODESTATE *state__);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FglStatement();

};

class FglIdentifier : public FglNode
{
protected:

	friend class YYNODESTATE;

	FglIdentifier(YYNODESTATE *state__, char * name);

public:

	char * name;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FglIdentifier();

};

class Variable : public FglNode
{
protected:

	friend class YYNODESTATE;

	Variable(YYNODESTATE *state__, char * name);

public:

	char * name;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Variable();

};

class FglExpression : public FglNode
{
protected:

	friend class YYNODESTATE;

	FglExpression(YYNODESTATE *state__);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FglExpression();

};

class AbstractFunction : public FglNode
{
protected:

	friend class YYNODESTATE;

	AbstractFunction(YYNODESTATE *state__, FglNode * functionName);

public:

	FglNode * functionName;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AbstractFunction();

};

class AbstractInitVariable : public FglNode
{
protected:

	friend class YYNODESTATE;

	AbstractInitVariable(YYNODESTATE *state__);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~AbstractInitVariable();

};

class fglStatement : public FglNode
{
protected:

	friend class YYNODESTATE;

	fglStatement(YYNODESTATE *state__);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~fglStatement();

};

class FormRest : public FglNode
{
protected:

	friend class YYNODESTATE;

	FormRest(YYNODESTATE *state__);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FormRest();

};

class FormName : public FglNode
{
protected:

	friend class YYNODESTATE;

	FormName(YYNODESTATE *state__, char * name);

public:

	char * name;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FormName();

};

class Initialize : public FglStatement
{
protected:

	friend class YYNODESTATE;

	Initialize(YYNODESTATE *state__, InitializeVariableList * init_val_list, FglNode * form_rest);

public:

	InitializeVariableList * init_val_list;
	FglNode * form_rest;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Initialize();

};

class BinaryExpression : public FglExpression
{
protected:

	friend class YYNODESTATE;

	BinaryExpression(YYNODESTATE *state__, FglNode * expr1, FglNode * expr2);

public:

	FglNode * expr1;
	FglNode * expr2;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~BinaryExpression();

};

class FunctionList : public BinaryExpression
{
protected:

	friend class YYNODESTATE;

	FunctionList(YYNODESTATE *state__, FglNode * expr1, FglNode * expr2);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~FunctionList();

};

class InitializeVariableList : public BinaryExpression
{
protected:

	friend class YYNODESTATE;

	InitializeVariableList(YYNODESTATE *state__, FglNode * expr1, FglNode * expr2);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~InitializeVariableList();

};

class Function : public AbstractFunction
{
protected:

	friend class YYNODESTATE;

	Function(YYNODESTATE *state__, FglNode * functionName);

public:


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~Function();

};

class InitializeSingleVariable : public AbstractInitVariable
{
protected:

	friend class YYNODESTATE;

	InitializeSingleVariable(YYNODESTATE *state__, FglNode * variable);

public:

	FglNode * variable;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~InitializeSingleVariable();

};

class InitializeThruVariable : public AbstractInitVariable
{
protected:

	friend class YYNODESTATE;

	InitializeThruVariable(YYNODESTATE *state__, FglNode * first_variable, FglNode * second_variable);

public:

	FglNode * first_variable;
	FglNode * second_variable;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~InitializeThruVariable();

};

class OpenForm : public fglStatement
{
protected:

	friend class YYNODESTATE;

	OpenForm(YYNODESTATE *state__, FglNode * form_name, FglNode * form_rest);

public:

	FglNode * form_name;
	FglNode * form_rest;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~OpenForm();

};

class OpenFormFrom : public FormRest
{
protected:

	friend class YYNODESTATE;

	OpenFormFrom(YYNODESTATE *state__, char * open_form_from_place);

public:

	char * open_form_from_place;


	virtual int isA(int kind) const;
	virtual const char *getKindName() const;

protected:

	virtual ~OpenFormFrom();

};


void FglNavigate(FglNode * node);

#line 70 "Fgl.tc"


/*
 * Inherit YYNODESTATE to provide additional functionality.
 */
class NodeState : public YYNODESTATE
{
private:

	char *progname;
	char *filename;
	long  linenum;

public:

	NodeState(char *_progname, char *_filename)
			: YYNODESTATE()
		{
			filename = _filename;
			linenum = 1;
		}
	virtual ~NodeState();

public:

	virtual char *currFilename();
	virtual long currLinenum();
	virtual void failed();

	void incLine() { ++linenum; }

};

#line 550 "Fgl.h"
#endif
