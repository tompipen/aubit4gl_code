/**
 * @file
 * Functions parameter management code.
 *
 * Author : $Author: saferreira $
 * Revision : $Revision: 1.2 $
 *
 * @todo - Terminar a implementação dos métodos
 *
 */

#include <stdio.h>
#include "Parameters.h"

#define PARAM_BUFFER 640

/**
 * Initialize and return a Parameters structure.
 *
 * @param maxParameters The maximum number of parameters for memory allocation.
 * @return Pointer to the structure allocated.
 */
Parameters *initParameters(int maxParameters)
{
	Parameters *param = (Parameters *)malloc(sizeof(Parameters));
	param->name       = (char **)calloc(maxParameters,sizeof(char *));
	param->comment    = (char **)calloc(maxParameters,sizeof(char *));
	param->dataType   = (char **)calloc(maxParameters,sizeof(char *));
	param->idxParameters = -1;
  return param;
}

/**
 * Insert the data of a new parameter at the end of the array allocated.
 *
 * @param parameters Pointer to the structure.
 * @param name Variable name used as 4gl parameter.
 * @param comment Comments to the parameter found in document comment.
 */
void addParameter(Parameters *parameters,char *name,char *comment)
{
  parameters->idxParameters++;
  parameters->name[parameters->idxParameters] = (char *)strdup(name);
  parameters->comment[parameters->idxParameters] = (char *)malloc(
		sizeof(char) * PARAM_BUFFER
  );
	if ( comment != NULL )
  {
    strcat(
		  parameters->comment[parameters->idxParameters],
			comment
    );
  }
}

/**
 *  Insert a new parameter just with is name.
 *
 *  @param parameters Pointer to the parameters structure.
 *  @param name Name of the parameter.
 */
void setParameterName(Parameters *parameters, char *name)
{
  addParameter(parameters,name,NULL);
}

/**
 * Modify the comments of the current parameter.
 *
 * @param parameters Pointer to the parameters structue.
 * @param comment Comments to add.
 */
void setParameterComments(Parameters *parameters, char *comment)
{
	if ( comment == NULL )
    return;
  strcat(
		parameters->comment[parameters->idxParameters],
		comment
  );
}

/**
 * Modify the information about a parameter at a specific position.
 *
 * @todo Gestão do erro caso ocorra
 * @todo Gestão de elementos vazios pelo meio
 * @todo Free(s) se elemento já preenchido
 *
 * @param name Name of 4gl variable used as parameter
 * @param comment Comments to parameter
 * @param idx Index of the parameter to modify
 */
void setParameter(Parameters *parameters,char *name,char *comment,int idx)
{
  if (idx > parameters->maxParameters - 1)
	  return;
  parameters->name[idx] = (char *)strdup(name);
  parameters->comment[idx] = (char *)strdup(comment);
	if ( idx > parameters->idxParameters )
    parameters->idxParameters = idx;
}


/**
 * Finds the parameter name by index.
 *
 * @param parameters Pointer to the parameters structure.
 * @param idx Index of the parameter wanted
 *
 * @return The name of the parameter, null if invalid index
 */
char *getParameterName(Parameters *parameters,int idx)
{
  if (idx > parameters->idxParameters)
	  return NULL;
	return parameters->name[idx];
}

/**
 * Finds the comment of the parameter identified by is index.
 *
 * @param parameters Pointer to the parameters structure.
 * @param idx Index of the wanted parameter.
 *
 * @return The comments of the parameter. Null if invalid index.
 */
char *getParameterComment(Parameters *parameters,int idx)
{
  if (idx > parameters->idxParameters)
	  return NULL;
	return parameters->comment[idx];
}
