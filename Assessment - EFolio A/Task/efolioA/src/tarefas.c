#include "../include/tarefas.h"
#include "../include/types.h" 
#include <stdio.h>

static int total_tarefas = 0;
static Tarefa tarefas[MAX_TAREFAS];

static int gerar_id_tarefa(void) {
    return total_tarefas + 1;
}

int criar_tarefa(char* descricao, int data_prevista) {

    // Correção do Erro 6: Verificar se o limite de tarefas não foi ultrapassado
    if(total_tarefas >= MAX_TAREFAS) {
        printf("Erro: Limite de tarefas atingido.\n");
        return 0;
    }

    tarefas[total_tarefas].id_tarefa = gerar_id_tarefa();
    // Correção do Erro 7: strcpy sem limite
    strncpy(tarefas[total_tarefas].descricao, descricao, sizeof(tarefas[total_tarefas].descricao) - 1);
    tarefas[total_tarefas].descricao[sizeof(tarefas[total_tarefas].descricao) - 1] = '\0'; // Garantir terminação nula
    tarefas[total_tarefas].data_prevista = data_prevista;
    tarefas[total_tarefas].concluida = 0;
    total_tarefas++;    

    printf("Tarefa criada com sucesso!\n"); 
    return 1;

}

/* LISTAR TAREFAS */

void listar_tarefas_pendentes() {
    
    if(total_tarefas == 0) {
        printf("Nao existem tarefas registadas.\n");
        return;
    }
    for (int i = 0; i < total_tarefas; i++) {
        // Correção do Erro 8: O operador de comparação deve ser ==, mas foi usado =, o que causa uma atribuição em vez de uma comparação, resultando em um comportamento incorreto (sempre entrando no if e marcando a tarefa como concluida)
    if (tarefas[i].concluida == 0) {
        printf("Tarefa %d: %s (prevista: %d)\n",
        tarefas[i].id_tarefa, tarefas[i].descricao,
        tarefas[i].data_prevista);
}
}
}

/* CONCLUIR TAREFA */

void concluir_tarefa(int id) {
    for (int i = 0; i < total_tarefas; i++) {
        // Correção do Erro 9: O operador de comparação deve ser ==, mas foi usado =, o que causa uma atribuição em vez de uma comparação, resultando em um comportamento incorreto (sempre marcando a tarefa como concluida independentemente do id)
        if (tarefas[i].id_tarefa == id) {
            tarefas[i].concluida = 1;
            printf("Tarefa concluida com sucesso!\n");
            return;
        }
    }
    printf("Tarefa nao encontrada.\n");
}

/* GUARDAR TAREFAS */

int guardar_tarefas(void) {
    // Correção do Erro 10: Guardar tarefas em um arquivo CSV, garantindo que os dados sejam persistidos corretamente
    FILE *f_tarefas = fopen("tarefas.csv", "w");
    if (f_tarefas == NULL) {
        return 0;
    }
    // Corrige Erro 11
    for (int i = 0; i < total_tarefas; i++) {
        fprintf(f_tarefas, "%d,%s,%d,%d\n",
                tarefas[i].id_tarefa,
                tarefas[i].descricao,
                tarefas[i].data_prevista,
                tarefas[i].concluida);
    }
    fclose(f_tarefas);
    return 1;
}

/* CARREGAR TAREFAS */


int carregar_tarefas(void) {

    FILE *f_tarefas = fopen("tarefas.csv", "r");
    if (f_tarefas == NULL) {
        return 0;
    }

    total_tarefas = 0;
    // Erro1 ciclo while corrigido do enunciado. Corrige while (!feof(f_tarefas))
    while (fscanf(f_tarefas, "%d,%99[^,],%d,%d\n",
                  &tarefas[total_tarefas].id_tarefa,
                  tarefas[total_tarefas].descricao,
                  &tarefas[total_tarefas].data_prevista,
                  &tarefas[total_tarefas].concluida) == 4) {

        total_tarefas++;
        
        if (total_tarefas >= MAX_TAREFAS) {
            printf("Aviso: Limite de tarefas atingido ao carregar dados.\n");
            break;
        }
        if(total_tarefas == 0) {
            printf("Nao existem tarefas registadas.\n");
            break;
        }
    }
    fclose(f_tarefas);
    return 1;
}