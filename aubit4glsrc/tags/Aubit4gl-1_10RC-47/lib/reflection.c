/**
 * @file
 * Contains the functions that suport the implementaton of reflection in 
 * aubit 4gl.
 *
 * Reflection is the ability to inspect the functions and variables available
 * and provide a way to execute them dinamicaly.
 *
 * The ideas are taken from Java.
 *
 * This mechanism can help a lot in the reuse of 4gl code.
 *
 * It is very important to the creation of a good unit testing api.
 *
 * With reflection we can execute the functions using is name inside a string.
 *
 * It works maintaining a central table that contains the function name,
 * and a pointer to the function and a description of the parameters that
 * she is waiting for.
 *
 * @todo : Implement it preferable with some sort of C collections.
 *
 */

#include <glib.h>

#define MAX_PARAMETERS 10

/** The information about a variable */
typedef struct Variable
{
  char *name;	 /**< The name of the variable */
  int dataType;	 /**< The type of data that the variable contains */
  void *pointer; /**< A pointer to the memory of the variable */
}
Variable;

/** Typedef for parameter */
typedef Variable Parameter;

/** A function definition structure */
typedef struct Function
{
  char *name;	 /**< The name of the function */
  const void *pointer; /**< A pointer to the defined function */
  GHashTable parameters; /**< The function parameters */
}
Function;

/** The function table */
static GHashTable functionTable;

/**
 * Initialize the memory for the table of functions.
 *
 * @param numberOfFunctions The amount of functions to allocate space for
 */
void
initFunctionTable (int numberofFunctions)
{
  functionTable = g_hash_table_new (g_str_hash, g_str_equal);
}

/**
 * Add a function to the  function registry.
 *
 * @param functionName The name of the function.
 * @param parameters The parameters definition array.
 * @param numberOfParameters The amount of parameters used.
 */
int
addFunction (const char *functionName, const void *functioPointer)
{
  Function function = malloc (sizeof (Function));
  function.functionName = strdup (functionName);
  function.pointer = functionPointer;
  g_hash_table_insert (functionTable, function.functionName, function);
}

/**
 * Add a parameter to the function.
 *
 * @param The function where to add the parameter.
 * @param variableName The name of the parameter.
 */
int
addParameter (const char *functionName, const char *variableName)
{
}

/**
 * Execute the function by name.
 *
 * @param functionName The name of the function.
 * @param parameters An array of parameters pointer.
 */
int
executeFunction (char *functionName, int numParameters)
{
}

/**
 * Assign a value to a global variable.
 *
 * @param variableName The name of the variable.
 * @param value A pointer to the variable vaue.
 */
int
setVariable (char *variableName, void *value)
{
}

/**
 * Get a value of a variable.
 *
 * @param variableName The name of the variable where to get a value.
 * @return A pointer to the variable name.
 */
void *
getVariable (char *variableName)
{
}
