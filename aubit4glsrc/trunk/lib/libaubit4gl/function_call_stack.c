
/**
 * @file 
 * Functions to imlement the mechanism of registering the function call
 * stack during a 4gl program execution and to suport the ability of doing
 * a printStackTrace like Java
 *
 * This facility is very good at java to store in log(s) or see imediatly
 * without need a debugger, wich functions have been called.
 *
 * @todo : Modify the compiler and the error function to call this facility
 */

#include <stdio.h>

#define MAX_FUNCTION_CALL_STACK 1000

/**
 * The type definition of a function call 
 */
typedef struct FunctionCall {
  const char *moduleName;   /**< Module where function was called */
  int  lineNumber;          /**< Line in the 4gl where function was called */
  const char *functionName; /**< The name of the function called */
} FunctionCall;

/** The current function call stack */
static FunctionCall *functionCallStack;

/** The function pointer index */
static int functionCallPointer;

/** The current module where the program is flowing */
static const char *currentModuleName;

/** The current 4gl line number in the source where the program is working */
static int currentFglLineNumber;

/** Flag that indicate that the stack info is used */
static int stackInfoInitialized = 0;

/**
 * Initialize the function call stack
 *
 * @return 
 *   - 0 : No memory for initializing the stack
 *   - 1 : Stack initialized
 */
int A4GLSTK_initFunctionCallStack(void)
{
  functionCallStack = (FunctionCall *)calloc(
    sizeof(FunctionCall),
    MAX_FUNCTION_CALL_STACK
  );
  functionCallPointer = 0;
  stackInfoInitialized = 1;
}

/**
 * Set the current 4gl line and module where the program flows.
 *
 * @param moduleName The name of the module where the program is.
 * @param lineNumber The line at 4gl source where the program is.
 */
void A4GLSTK_setCurrentLine(const char *moduleName,int lineNumber)
{
  currentModuleName = moduleName;
  currentFglLineNumber = lineNumber;
}

/**
 * Push a function called to the function stack.
 *
 * @param functionName The name of the function called.
 */
void A4GLSTK_pushFunction(const char *functionName)
{
  fprintf(stderr,"=====&&&&&&============PUSH %s\n",functionName);
  functionCallStack[functionCallPointer].functionName = functionName;
  functionCallPointer++;
}

/**
 * Pop the last function from the stack.
 */
void A4GLSTK_popFunction()
{
  functionCallPointer--;
  if ( functionCallPointer < 0 )
    functionCallPointer = 0;
}

/**
 * Generate a string with the current 4gl stack trace.
 *
 * @return A pointer to a static char buffer where the stack trace was printed.
 */
char *A4GLSTK_getStackTrace(void)
{
  static char stackTrace[640];
  register int i;

  strcpy(stackTrace,"4gl function call stack :\n");
  for ( i = functionCallPointer ; i >= 0 ; i-- )
  {
    strcat(stackTrace,"    ");
    if ( functionCallStack[i].moduleName == '\0' )
      strcat(stackTrace,functionCallStack[i].functionName);
    else
      sprintf(stackTrace,
       "  %s\n%s (%s) Line %d\n",
        stackTrace,
        functionCallStack[i].moduleName,
        functionCallStack[i].functionName,
        functionCallStack[i].lineNumber
      );
    strcat(stackTrace,"()\n");
  }
  return stackTrace;
}

/**
 * To verify that the stack info is allready initialized.
 * 
 * @return 
 *   - 0 : Stack info not initialized.
 *   - 1 : Stack info initialized.
 */
int A4GLSTK_isStackInfo(void)
{
  return stackInfoInitialized;
}
