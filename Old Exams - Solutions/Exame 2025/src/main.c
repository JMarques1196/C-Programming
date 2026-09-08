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
        printf("[Error] Could not allocate memory for the list.\n");
        return 1;
    }

    // 2. Carregar os dados do CSV para a lista
    printf("Loading posts from '%s'...\n", POSTS_FILE);
    if (file_load_posts(POSTS_FILE, list) != SUCCESS)
    {
        printf("[Error] Failed to read the file %s.\n", POSTS_FILE);
        // Não esquecer de libertar a memória antes de sair em caso de erro
        post_list_destroy(list);
        return 1;
    }

    // 3. Exibir os posts carregados
    menu_run(list);
    // 4. Libertar a memória alocada
    post_list_destroy(list);
    printf("\nMemory freed. Program terminated successfully.\n");

    return 0;
}