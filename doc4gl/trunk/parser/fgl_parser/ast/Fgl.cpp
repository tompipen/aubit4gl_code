/* Fgl.cpp.  Generated automatically by treecc */
#line 40 "Fgl.tc"

#include <iostream.h>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "Fgl.h"

#line 11 "Fgl.cpp"

#define YYNODESTATE_REENTRANT 1
#define YYNODESTATE_TRACK_LINES 1
#define YYNODESTATE_USE_ALLOCATOR 1
#line 1 "cpp_skel.cc"
/*
 * treecc node allocation routines for C++.
 *
 * Copyright (C) 2001  Southern Storm Software, Pty Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * As a special exception, when this file is copied by treecc into
 * a treecc output file, you may use that output file without restriction.
 */

#ifndef YYNODESTATE_BLKSIZ
#define	YYNODESTATE_BLKSIZ	2048
#endif

/*
 * Types used by the allocation routines.
 */
struct YYNODESTATE_block
{
	char data__[YYNODESTATE_BLKSIZ];
	struct YYNODESTATE_block *next__;

};
struct YYNODESTATE_push
{
	struct YYNODESTATE_push *next__;
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
};

/*
 * Initialize the singleton instance.
 */
#ifndef YYNODESTATE_REENTRANT
YYNODESTATE *YYNODESTATE::state__ = 0;
#endif

/*
 * Some macro magic to determine the default alignment
 * on this machine.  This will compile down to a constant.
 */
#define	YYNODESTATE_ALIGN_CHECK_TYPE(type,name)	\
	struct _YYNODESTATE_align_##name { \
		char pad; \
		type field; \
	}
#define	YYNODESTATE_ALIGN_FOR_TYPE(type)	\
	((unsigned)(&(((struct _YYNODESTATE_align_##type *)0)->field)))
#define	YYNODESTATE_ALIGN_MAX(a,b)	\
	((a) > (b) ? (a) : (b))
#define	YYNODESTATE_ALIGN_MAX3(a,b,c) \
	(YYNODESTATE_ALIGN_MAX((a), YYNODESTATE_ALIGN_MAX((b), (c))))
YYNODESTATE_ALIGN_CHECK_TYPE(int, int);
YYNODESTATE_ALIGN_CHECK_TYPE(long, long);
#if defined(WIN32) && !defined(__CYGWIN__)
YYNODESTATE_ALIGN_CHECK_TYPE(__int64, long_long);
#else
YYNODESTATE_ALIGN_CHECK_TYPE(long long, long_long);
#endif
YYNODESTATE_ALIGN_CHECK_TYPE(void *, void_p);
YYNODESTATE_ALIGN_CHECK_TYPE(float, float);
YYNODESTATE_ALIGN_CHECK_TYPE(double, double);
#define	YYNODESTATE_ALIGNMENT	\
	YYNODESTATE_ALIGN_MAX( \
			YYNODESTATE_ALIGN_MAX3	\
			(YYNODESTATE_ALIGN_FOR_TYPE(int), \
		     YYNODESTATE_ALIGN_FOR_TYPE(long), \
			 YYNODESTATE_ALIGN_FOR_TYPE(long_long)), \
  	     YYNODESTATE_ALIGN_MAX3 \
		 	(YYNODESTATE_ALIGN_FOR_TYPE(void_p), \
			 YYNODESTATE_ALIGN_FOR_TYPE(float), \
			 YYNODESTATE_ALIGN_FOR_TYPE(double)))

/*
 * Constructor for YYNODESTATE.
 */
YYNODESTATE::YYNODESTATE()
{
	/* Initialize the allocation state */
	blocks__ = 0;
	push_stack__ = 0;
	used__ = 0;

#ifndef YYNODESTATE_REENTRANT
	/* Register this object as the singleton instance */
	if(!state__)
	{
		state__ = this;
	}
#endif
}

/*
 * Destructor for YYNODESTATE.
 */
YYNODESTATE::~YYNODESTATE()
{
	/* Free all node memory */
	clear();

#ifndef YYNODESTATE_REENTRANT
	/* We are no longer the singleton instance */
	if(state__ == this)
	{
		state__ = 0;
	}
#endif
}

#ifdef YYNODESTATE_USE_ALLOCATOR

/*
 * Allocate a block of memory.
 */
void *YYNODESTATE::alloc(size_t size__)
{
	struct YYNODESTATE_block *block__;
	void *result__;

	/* Round the size to the next alignment boundary */
	size__ = (size__ + YYNODESTATE_ALIGNMENT - 1) &
				~(YYNODESTATE_ALIGNMENT - 1);

	/* Do we need to allocate a new block? */
	block__ = blocks__;
	if(!block__ || (used__ + size__) > YYNODESTATE_BLKSIZ)
	{
		if(size__ > YYNODESTATE_BLKSIZ)
		{
			/* The allocation is too big for the node pool */
			return (void *)0;
		}
		block__ = new YYNODESTATE_block;
		if(!block__)
		{
			/* The system is out of memory.  The programmer can
			   inherit the "failed" method to report the
			   out of memory state and/or abort the program */
			failed();
			return (void *)0;
		}
		block__->next__ = blocks__;
		blocks__ = block__;
		used__ = 0;
	}

	/* Allocate the memory and return it */
	result__ = (void *)(block__->data__ + used__);
	used__ += size__;
	return result__;
}

/*
 * Deallocate a block of memory.
 */
void YYNODESTATE::dealloc(void *ptr__, size_t size__)
{
	/* Nothing to do for this type of node allocator */
}

/*
 * Push the node allocation state.
 */
int YYNODESTATE::push()
{
	struct YYNODESTATE_block *saved_block__;
	int saved_used__;
	struct YYNODESTATE_push *push_item__;

	/* Save the current state of the node allocation pool */
	saved_block__ = blocks__;
	saved_used__ = used__;

	/* Allocate space for a push item */
	push_item__ = (struct YYNODESTATE_push *)
			alloc(sizeof(struct YYNODESTATE_push));
	if(!push_item__)
	{
		return 0;
	}

	/* Copy the saved information to the push item */
	push_item__->saved_block__ = saved_block__;
	push_item__->saved_used__ = saved_used__;

	/* Add the push item to the push stack */
	push_item__->next__ = push_stack__;
	push_stack__ = push_item__;
	return 1;
}

/*
 * Pop the node allocation state.
 */
void YYNODESTATE::pop()
{
	struct YYNODESTATE_push *push_item__;
	struct YYNODESTATE_block *saved_block__;
	struct YYNODESTATE_block *temp_block__;

	/* Pop the top of the push stack */
	push_item__ = push_stack__;
	if(push_item__ == 0)
	{
		saved_block__ = 0;
		used__ = 0;
	}
	else
	{
		saved_block__ = push_item__->saved_block__;
		used__ = push_item__->saved_used__;
		push_stack__ = push_item__->next__;
	}

	/* Free unnecessary blocks */
	while(blocks__ != saved_block__)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
}

/*
 * Clear the node allocation pool completely.
 */
void YYNODESTATE::clear()
{
	struct YYNODESTATE_block *temp_block__;
	while(blocks__ != 0)
	{
		temp_block__ = blocks__;
		blocks__ = temp_block__->next__;
		delete temp_block__;
	}
	push_stack__ = 0;
	used__ = 0;
}

#endif /* YYNODESTATE_USE_ALLOCATOR */

/*
 * Default implementation of functions which may be overridden.
 */
void YYNODESTATE::failed()
{
}

#ifdef YYNODESTATE_TRACK_LINES

char *YYNODESTATE::currFilename()
{
	return (char *)0;
}

long YYNODESTATE::currLinenum()
{
	return 0;
}

#endif
#line 291 "Fgl.cpp"
FglIdentifier *YYNODESTATE::FglIdentifierCreate(char * name)
{
	void *buf__ = this->alloc(sizeof(FglIdentifier));
	if(buf__ == 0) return 0;
	return new (buf__) FglIdentifier(this, name);
}

Variable *YYNODESTATE::VariableCreate(char * name)
{
	void *buf__ = this->alloc(sizeof(Variable));
	if(buf__ == 0) return 0;
	return new (buf__) Variable(this, name);
}

FormName *YYNODESTATE::FormNameCreate(char * name)
{
	void *buf__ = this->alloc(sizeof(FormName));
	if(buf__ == 0) return 0;
	return new (buf__) FormName(this, name);
}

Initialize *YYNODESTATE::InitializeCreate(InitializeVariableList * init_val_list, FglNode * form_rest)
{
	void *buf__ = this->alloc(sizeof(Initialize));
	if(buf__ == 0) return 0;
	return new (buf__) Initialize(this, init_val_list, form_rest);
}

FunctionList *YYNODESTATE::FunctionListCreate(FglNode * expr1, FglNode * expr2)
{
	void *buf__ = this->alloc(sizeof(FunctionList));
	if(buf__ == 0) return 0;
	return new (buf__) FunctionList(this, expr1, expr2);
}

InitializeVariableList *YYNODESTATE::InitializeVariableListCreate(FglNode * expr1, FglNode * expr2)
{
	void *buf__ = this->alloc(sizeof(InitializeVariableList));
	if(buf__ == 0) return 0;
	return new (buf__) InitializeVariableList(this, expr1, expr2);
}

Function *YYNODESTATE::FunctionCreate(FglNode * functionName)
{
	void *buf__ = this->alloc(sizeof(Function));
	if(buf__ == 0) return 0;
	return new (buf__) Function(this, functionName);
}

InitializeSingleVariable *YYNODESTATE::InitializeSingleVariableCreate(FglNode * variable)
{
	void *buf__ = this->alloc(sizeof(InitializeSingleVariable));
	if(buf__ == 0) return 0;
	return new (buf__) InitializeSingleVariable(this, variable);
}

InitializeThruVariable *YYNODESTATE::InitializeThruVariableCreate(FglNode * first_variable, FglNode * second_variable)
{
	void *buf__ = this->alloc(sizeof(InitializeThruVariable));
	if(buf__ == 0) return 0;
	return new (buf__) InitializeThruVariable(this, first_variable, second_variable);
}

OpenForm *YYNODESTATE::OpenFormCreate(FglNode * form_name, FglNode * form_rest)
{
	void *buf__ = this->alloc(sizeof(OpenForm));
	if(buf__ == 0) return 0;
	return new (buf__) OpenForm(this, form_name, form_rest);
}

OpenFormFrom *YYNODESTATE::OpenFormFromCreate(char * open_form_from_place)
{
	void *buf__ = this->alloc(sizeof(OpenFormFrom));
	if(buf__ == 0) return 0;
	return new (buf__) OpenFormFrom(this, open_form_from_place);
}

FglNode::FglNode(YYNODESTATE *state__)
{
	this->kind__ = FglNode_kind;
	this->filename__ = state__->currFilename();
	this->linenum__ = state__->currLinenum();
}

FglNode::~FglNode()
{
	// not used
}

int FglNode::isA(int kind) const
{
	if(kind == FglNode_kind)
		return 1;
	else
		return 0;
}

const char *FglNode::getKindName() const
{
	return "FglNode";
}

FglStatement::FglStatement(YYNODESTATE *state__)
	: FglNode(state__)
{
	this->kind__ = FglStatement_kind;
}

FglStatement::~FglStatement()
{
	// not used
}

int FglStatement::isA(int kind) const
{
	if(kind == FglStatement_kind)
		return 1;
	else
		return FglNode::isA(kind);
}

const char *FglStatement::getKindName() const
{
	return "FglStatement";
}

FglIdentifier::FglIdentifier(YYNODESTATE *state__, char * name)
	: FglNode(state__)
{
	this->kind__ = FglIdentifier_kind;
	this->name = name;
}

FglIdentifier::~FglIdentifier()
{
	// not used
}

int FglIdentifier::isA(int kind) const
{
	if(kind == FglIdentifier_kind)
		return 1;
	else
		return FglNode::isA(kind);
}

const char *FglIdentifier::getKindName() const
{
	return "FglIdentifier";
}

Variable::Variable(YYNODESTATE *state__, char * name)
	: FglNode(state__)
{
	this->kind__ = Variable_kind;
	this->name = name;
}

Variable::~Variable()
{
	// not used
}

int Variable::isA(int kind) const
{
	if(kind == Variable_kind)
		return 1;
	else
		return FglNode::isA(kind);
}

const char *Variable::getKindName() const
{
	return "Variable";
}

FglExpression::FglExpression(YYNODESTATE *state__)
	: FglNode(state__)
{
	this->kind__ = FglExpression_kind;
}

FglExpression::~FglExpression()
{
	// not used
}

int FglExpression::isA(int kind) const
{
	if(kind == FglExpression_kind)
		return 1;
	else
		return FglNode::isA(kind);
}

const char *FglExpression::getKindName() const
{
	return "FglExpression";
}

AbstractFunction::AbstractFunction(YYNODESTATE *state__, FglNode * functionName)
	: FglNode(state__)
{
	this->kind__ = AbstractFunction_kind;
	this->functionName = functionName;
}

AbstractFunction::~AbstractFunction()
{
	// not used
}

int AbstractFunction::isA(int kind) const
{
	if(kind == AbstractFunction_kind)
		return 1;
	else
		return FglNode::isA(kind);
}

const char *AbstractFunction::getKindName() const
{
	return "AbstractFunction";
}

AbstractInitVariable::AbstractInitVariable(YYNODESTATE *state__)
	: FglNode(state__)
{
	this->kind__ = AbstractInitVariable_kind;
}

AbstractInitVariable::~AbstractInitVariable()
{
	// not used
}

int AbstractInitVariable::isA(int kind) const
{
	if(kind == AbstractInitVariable_kind)
		return 1;
	else
		return FglNode::isA(kind);
}

const char *AbstractInitVariable::getKindName() const
{
	return "AbstractInitVariable";
}

fglStatement::fglStatement(YYNODESTATE *state__)
	: FglNode(state__)
{
	this->kind__ = fglStatement_kind;
}

fglStatement::~fglStatement()
{
	// not used
}

int fglStatement::isA(int kind) const
{
	if(kind == fglStatement_kind)
		return 1;
	else
		return FglNode::isA(kind);
}

const char *fglStatement::getKindName() const
{
	return "fglStatement";
}

FormRest::FormRest(YYNODESTATE *state__)
	: FglNode(state__)
{
	this->kind__ = FormRest_kind;
}

FormRest::~FormRest()
{
	// not used
}

int FormRest::isA(int kind) const
{
	if(kind == FormRest_kind)
		return 1;
	else
		return FglNode::isA(kind);
}

const char *FormRest::getKindName() const
{
	return "FormRest";
}

FormName::FormName(YYNODESTATE *state__, char * name)
	: FglNode(state__)
{
	this->kind__ = FormName_kind;
	this->name = name;
}

FormName::~FormName()
{
	// not used
}

int FormName::isA(int kind) const
{
	if(kind == FormName_kind)
		return 1;
	else
		return FglNode::isA(kind);
}

const char *FormName::getKindName() const
{
	return "FormName";
}

Initialize::Initialize(YYNODESTATE *state__, InitializeVariableList * init_val_list, FglNode * form_rest)
	: FglStatement(state__)
{
	this->kind__ = Initialize_kind;
	this->init_val_list = init_val_list;
	this->form_rest = form_rest;
}

Initialize::~Initialize()
{
	// not used
}

int Initialize::isA(int kind) const
{
	if(kind == Initialize_kind)
		return 1;
	else
		return FglStatement::isA(kind);
}

const char *Initialize::getKindName() const
{
	return "Initialize";
}

BinaryExpression::BinaryExpression(YYNODESTATE *state__, FglNode * expr1, FglNode * expr2)
	: FglExpression(state__)
{
	this->kind__ = BinaryExpression_kind;
	this->expr1 = expr1;
	this->expr2 = expr2;
}

BinaryExpression::~BinaryExpression()
{
	// not used
}

int BinaryExpression::isA(int kind) const
{
	if(kind == BinaryExpression_kind)
		return 1;
	else
		return FglExpression::isA(kind);
}

const char *BinaryExpression::getKindName() const
{
	return "BinaryExpression";
}

FunctionList::FunctionList(YYNODESTATE *state__, FglNode * expr1, FglNode * expr2)
	: BinaryExpression(state__, expr1, expr2)
{
	this->kind__ = FunctionList_kind;
}

FunctionList::~FunctionList()
{
	// not used
}

int FunctionList::isA(int kind) const
{
	if(kind == FunctionList_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *FunctionList::getKindName() const
{
	return "FunctionList";
}

InitializeVariableList::InitializeVariableList(YYNODESTATE *state__, FglNode * expr1, FglNode * expr2)
	: BinaryExpression(state__, expr1, expr2)
{
	this->kind__ = InitializeVariableList_kind;
}

InitializeVariableList::~InitializeVariableList()
{
	// not used
}

int InitializeVariableList::isA(int kind) const
{
	if(kind == InitializeVariableList_kind)
		return 1;
	else
		return BinaryExpression::isA(kind);
}

const char *InitializeVariableList::getKindName() const
{
	return "InitializeVariableList";
}

Function::Function(YYNODESTATE *state__, FglNode * functionName)
	: AbstractFunction(state__, functionName)
{
	this->kind__ = Function_kind;
}

Function::~Function()
{
	// not used
}

int Function::isA(int kind) const
{
	if(kind == Function_kind)
		return 1;
	else
		return AbstractFunction::isA(kind);
}

const char *Function::getKindName() const
{
	return "Function";
}

InitializeSingleVariable::InitializeSingleVariable(YYNODESTATE *state__, FglNode * variable)
	: AbstractInitVariable(state__)
{
	this->kind__ = InitializeSingleVariable_kind;
	this->variable = variable;
}

InitializeSingleVariable::~InitializeSingleVariable()
{
	// not used
}

int InitializeSingleVariable::isA(int kind) const
{
	if(kind == InitializeSingleVariable_kind)
		return 1;
	else
		return AbstractInitVariable::isA(kind);
}

const char *InitializeSingleVariable::getKindName() const
{
	return "InitializeSingleVariable";
}

InitializeThruVariable::InitializeThruVariable(YYNODESTATE *state__, FglNode * first_variable, FglNode * second_variable)
	: AbstractInitVariable(state__)
{
	this->kind__ = InitializeThruVariable_kind;
	this->first_variable = first_variable;
	this->second_variable = second_variable;
}

InitializeThruVariable::~InitializeThruVariable()
{
	// not used
}

int InitializeThruVariable::isA(int kind) const
{
	if(kind == InitializeThruVariable_kind)
		return 1;
	else
		return AbstractInitVariable::isA(kind);
}

const char *InitializeThruVariable::getKindName() const
{
	return "InitializeThruVariable";
}

OpenForm::OpenForm(YYNODESTATE *state__, FglNode * form_name, FglNode * form_rest)
	: fglStatement(state__)
{
	this->kind__ = OpenForm_kind;
	this->form_name = form_name;
	this->form_rest = form_rest;
}

OpenForm::~OpenForm()
{
	// not used
}

int OpenForm::isA(int kind) const
{
	if(kind == OpenForm_kind)
		return 1;
	else
		return fglStatement::isA(kind);
}

const char *OpenForm::getKindName() const
{
	return "OpenForm";
}

OpenFormFrom::OpenFormFrom(YYNODESTATE *state__, char * open_form_from_place)
	: FormRest(state__)
{
	this->kind__ = OpenFormFrom_kind;
	this->open_form_from_place = open_form_from_place;
}

OpenFormFrom::~OpenFormFrom()
{
	// not used
}

int OpenFormFrom::isA(int kind) const
{
	if(kind == OpenFormFrom_kind)
		return 1;
	else
		return FormRest::isA(kind);
}

const char *OpenFormFrom::getKindName() const
{
	return "OpenFormFrom";
}

static void FglNavigate_1__(FglNode *node)
#line 11 "FglNavigate.tc"
{
	//fprintf(stderr,"%s:%d <%s>\n",__FILE__,__LINE__,node->getKindName());
	Function *func;
	FglIdentifier *ident;
	switch ( node->getKind() )
	{
	  case FunctionList_kind:
	    FglNavigate(((FunctionList *)node)->expr1);
			func = (Function *)((FunctionList *)node)->expr2;
			ident = (FglIdentifier *)func->functionName;
	    fprintf(stderr, "Func is : %s \n", ident->name);
			break;
		case Function_kind:
	    //fprintf(stderr,"%s:%d <%s>\n",__FILE__,__LINE__,node->getKindName());
			func = (Function *)((FunctionList *)node);
			ident = (FglIdentifier *)func->functionName;
	    fprintf(stderr, " Func is : %s \n", ident->name);
			break;
	}

}
#line 863 "Fgl.cpp"

void FglNavigate(FglNode * node__)
{
	switch(node__->getKind())
	{
		case FglNode_kind:
		case FglStatement_kind:
		case Initialize_kind:
		case FglIdentifier_kind:
		case Variable_kind:
		case FglExpression_kind:
		case BinaryExpression_kind:
		case FunctionList_kind:
		case InitializeVariableList_kind:
		case AbstractFunction_kind:
		case Function_kind:
		case AbstractInitVariable_kind:
		case InitializeSingleVariable_kind:
		case InitializeThruVariable_kind:
		case fglStatement_kind:
		case OpenForm_kind:
		case FormRest_kind:
		case OpenFormFrom_kind:
		case FormName_kind:
		{
			FglNavigate_1__((FglNode *)node__);
		}
		break;

		default: break;
	}
}

#line 108 "Fgl.tc"


/*
 * Entry points that are imported from the yacc parser.
 */
extern void yyrestart(FILE *file);
extern int yyparse(void *);

/*
 * Destructor for NodeState.
 */
NodeState::~NodeState()
{
	/* Nothing needs to be done here */
}

/*
 * Get the name of the current input file in use by the parser.
 */
char *NodeState::currFilename()
{
	return filename;
}

/*
 * Get the line number for the current input line in use by the parser.
 */
long NodeState::currLinenum()
{
	return linenum;
}

/*
 * Report memory failure and exit.
 */
void NodeState::failed()
{
	cerr << progname << ": virtual memory exhausted" << endl;
	exit(1);
}

#line 939 "Fgl.cpp"
