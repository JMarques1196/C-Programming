#ifndef PARSER_H
#define PARSER_H
#include "types.h"

/* Recebe um ficheiro CSV e devolve todas as mesas e a respectiva lotação */
int parser_mesa(char *file_name, Mesa *lista_mesas);
/* Recebe um ficheiro CSV e devolve todos os grupos de clientes à espera de mesa */
int parser_cliente(char *file_name, Cliente *lista_clientes);

#endif