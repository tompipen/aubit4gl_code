/**
 * Lista de parametros e sua defini��o
 */

#ifndef __PARAMETERS_H__
#define __PARAMETERS_H__

typedef struct {
  char **name;
	char **comment;
	char **dataType;     // Tipo de dados do parametro
	int idxParameters;   // Indice que aponta para parametro corrente
	int maxParameters;   // N� m�ximo de parametros permitidos
} Parameters;


#endif
