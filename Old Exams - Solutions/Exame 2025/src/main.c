#include <stdio.h>
#include <stdlib.h>

#include "../include/types.h"
#include "../include/posts.h"
#include "../include/files.h"
#include "../include/menu.h"

#define POSTS_FILE "../posts.csv"

int main(void)
{

    // 1. Criar e inicializar a estrutura opaca da lista
    PostList *list = post_list_create();
    if (list == NULL)
    {
        printf("[Erro] Nao foi possivel alocar memoria para a lista.\n");
        return 1;
    }

    // 2. Carregar os dados do CSV para a lista
    printf("A carregar posts do ficheiro '%s'...\n", POSTS_FILE);
    if (file_load_posts(POSTS_FILE, list) != SUCCESS)
    {
        printf("[Erro] Falha ao ler o ficheiro %s.\n", POSTS_FILE);
        // Não esquecer de libertar a memória antes de sair em caso de erro
        post_list_destroy(list);
        return 1;
    }

    // 3. Exibir os posts carregados
    menu_run(list);
    // 4. Libertar a memória alocada
    post_list_destroy(list);
    printf("\nMemoria libertada. Programa terminado com sucesso.\n");

    return 0;
}