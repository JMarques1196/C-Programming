// Main.c apenas chama funções de outros modulos.

// Main funciona como orquestradora.
// Recebe os ficheiros csv
// Chama a funcção de parsing
// Passa as listas lidas para distribuicao
// argc - argument count - numero de argumentos passados na linha de comando
// argv - argument vector - array de strings com os argumentos passados na linha de comando
#include "../include/parser.h"
#include "../include/types.h"
#include "../include/distribuicao.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 3) // 3 porque: [0]programa, [1]mesas, [2]clientes
    {
        printf("Usage: %s <mesas.csv> <clientes.csv>\n", argv[0]);
        return 1; // Return 1 = Error
    }

    /* Inicialização de listas */
    Mesa lista_mesas[MAX_MESAS];
    Cliente lista_clientes[MAX_GRUPOS];
    Ordenacao lista_ordenacao[MAX_GRUPOS];

    /* Parsing e preenchimento de listas */
    int total_mesas = parser_mesa(argv[1], lista_mesas);
    int total_grupos = parser_cliente(argv[2], lista_clientes);
    int total_ordenandos = distribuicao(lista_mesas, total_mesas, lista_clientes, total_grupos, lista_ordenacao);

    /* Aux */
    int selection;

    int i = 0;
    // O loop continua até encontrar a mesa com ID -1 (marcador de fim)
    printf("Total_Mesas: %d\n", total_mesas);

    while (i < total_mesas)
    {
        printf("Posicao [%d] -> ID: %d | Lugares: %d | Ocupados: %d\n",
               i,
               lista_mesas[i].numero,
               lista_mesas[i].lugares,
               lista_mesas[i].ocupacao);
        i++;
    }

    printf("Total_Grupos: %d\n", total_grupos);

    int x = 0;
    while (x < total_grupos)
    {
        printf("Posicao [%d] -> Grupo %c | Tamnho do Grupo: %d\n",
               x,
               lista_clientes[x].ordem,
               lista_clientes[x].tamanho_grupo);
        x++;
    }

    int z = 0;
    while (z < total_grupos)
    {
        printf("Grupo %c -> Mesa %d\n",
               lista_ordenacao[z].grupo_cliente,
               lista_ordenacao[z].numero_mesa);
        z++;
    }

    return 0;
}