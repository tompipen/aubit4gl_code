/**
 * Funções para gestão dos parâmetros de funções
 *
 * Author : $Author: afalout $
 * Revision : $Revision: 1.1.1.1 $
 *
 * @todo - Terminar a implementação dos métodos
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
 * @param name Nome da variável usada como parâmetro
 * @param comment Comentários ao parametro
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
 *  Insere um novo parametro apenas com o nome da variável
 *
 *  @param parameters Pointer para o objecto que gere os parametros
 *  @param name Nome do parametro
 */
void setParameterName(Parameters *parameters, char *name)
{
  addParameter(parameters,name,NULL);
}

/**
 * Modifica o comentários do parametro corrente
 *
 * @param parameters Pointer para o objecto de parametros
 * @param comment Comentários a associar
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
 * Altera os dados de um parametro numa posição especifica
 *
 * @todo Gestão do erro caso ocorra
 * @todo Gestão de elementos vazios pelo meio
 * @todo Free(s) se elemento já preenchido
 *
 * @param name Nome da variável usada como parâmetro
 * @param comment Comentários ao parametro
 * @param idx Indice do parâmetro que se pretende alterar
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
 * @return o nome do parametro numa dada posição, null se indice inválido
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
 * @return o comentário do parametro numa dada posição, null se indice inválido
 */
char *getParameterComment(Parameters *parameters,int idx)
{
  if (idx > parameters->idxParameters)
	  return NULL;
	return parameters->comment[idx];
}
