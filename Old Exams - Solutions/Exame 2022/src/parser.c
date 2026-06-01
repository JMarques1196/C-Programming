// Modulo para parsing dos ficheiros csv

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/types.h"
#include "../include/parser.h"

/* Funções auxiliares para parsing dos ficheiros csv */

int parser_mesa(char *file_name, Mesa *lista_mesas)
{
    FILE *fp = fopen(file_name, "r");
    // guard clauses
    if (!fp)
    {
        return 0;
    }

    int total_mesas = 0;

    while (total_mesas < MAX_MESAS &&
           // fscanf da como retorno o nº de ints preenchidos. Se encontrar um numero,
           // Vai ler o ficheiro fp e preencher as variaveis pretendidas uma por uma.
           // lugar e lotação numa linha, devolve 3. Se develolver um nº diferente de 3 existe um problema no ficheiro
           fscanf(fp, "%d,%d,%d", &lista_mesas[total_mesas].numero, &lista_mesas[total_mesas].lugares, &lista_mesas[total_mesas].ocupacao) == 3)
    {
        total_mesas++;
    }

    fclose(fp);
    return total_mesas;
}

int parser_cliente(char *file_name, Cliente *lista_clientes)
{
    FILE *fp = fopen(file_name, "r");
    if (!fp)
    {
        return 0;
    }

    int total_grupos = 0;

    while (total_grupos < MAX_GRUPOS &&
           fscanf(fp, " %c,%d", &lista_clientes[total_grupos].ordem, &lista_clientes[total_grupos].tamanho_grupo) == 2)
    {
        total_grupos++;
    }

    fclose(fp);
    return total_grupos;
}
// csv parsing.
// Read 1 line using fgets (stops at eol)
// split the string by a delimiter using strtok (",")
// atoi or sscanf to convert string to int
