/**
 * Lista de parametros e sua definição
 */

typedef struct {
  char **name;
	char **comment;
	char **dataType;     // Tipo de dados do parametro
	int idxParameters;   // Indice que aponta para parametro corrente
	int maxParameters;   // Nº máximo de parametros permitidos
} Parameters;
