/**
 * Fun��es para gest�o dos par�metros de fun��es
 *
 * Author : $Author: afalout $
 * Revision : $Revision: 1.1.1.1 $
 *
 * @todo - Terminar a implementa��o dos m�todos
 *
 */

#include <stdio.h>
#include "Parameters.h"

#define PARAM_BUFFER 640

/**
 * Inicializa e devolve um estrutura de parametros
 *
 * @return Apontador para o objecto inicializado
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
 * Insere os dados de um novo parametro no final do array
 *
 * @param parameters Pointer para o objecto de parametros
 * @param name Nome da vari�vel usada como par�metro
 * @param comment Coment�rios ao parametro
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
 *  Insere um novo parametro apenas com o nome da vari�vel
 *
 *  @param parameters Pointer para o objecto que gere os parametros
 *  @param name Nome do parametro
 */
void setParameterName(Parameters *parameters, char *name)
{
  addParameter(parameters,name,NULL);
}

/**
 * Modifica o coment�rios do parametro corrente
 *
 * @param parameters Pointer para o objecto de parametros
 * @param comment Coment�rios a associar
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
 * Altera os dados de um parametro numa posi��o especifica
 *
 * @todo Gest�o do erro caso ocorra
 * @todo Gest�o de elementos vazios pelo meio
 * @todo Free(s) se elemento j� preenchido
 *
 * @param name Nome da vari�vel usada como par�metro
 * @param comment Coment�rios ao parametro
 * @param idx Indice do par�metro que se pretende alterar
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
 * @param parameters Pointer para objecto de parametros
 * @param idx Indice do parametro pretendido
 *
 * @return o nome do parametro numa dada posi��o, null se indice inv�lido
 */
char *getParameterName(Parameters *parameters,int idx)
{
  if (idx > parameters->idxParameters)
	  return NULL;
	return parameters->name[idx];
}

/**
 * @param parameters Pointer para objecto de parametros
 * @param idx Indice do parametro pretendido
 *
 * @return o coment�rio do parametro numa dada posi��o, null se indice inv�lido
 */
char *getParameterComment(Parameters *parameters,int idx)
{
  if (idx > parameters->idxParameters)
	  return NULL;
	return parameters->comment[idx];
}
