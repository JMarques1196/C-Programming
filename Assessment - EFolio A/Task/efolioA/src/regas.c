#include <stdio.h>
#include "../include/regas.h" // Acesso a funções de carregar e guardar dados
#include "../include/plantas.h" // Acesso a funções relacionadas a plantas
#include "../include/types.h" // Acesso a definições de tipos e constantes

static Rega regas[MAX_REGAS];
static int total_regas = 0;

/* REGISTAR REGAS */
int registar_rega(int id_planta, int data, int quantidade){
    // Verificar se a planta existe
    if(!planta_existe(id_planta)){
        printf("Erro: Planta com ID %d nao existe.\n", id_planta);
        return 0;
    }

    // Correção do erro 4:Verificar o limite de regas
    if(total_regas >= MAX_REGAS){
        printf("Erro: Limite de regas atingido. Nao e possivel registrar mais regas.\n");
        return 0;
    };

    regas[total_regas].id_rega = total_regas + 1;
    regas[total_regas].id_planta = id_planta;
    regas[total_regas].data_rega = data;
    regas[total_regas].quantidade_agua = quantidade;
    total_regas++;

    // Correção do Erro 5: Atualiza a ultima rega da planta após registrar a rega, garantindo que a função verificar_rega() funcione corretamente.
    atualizar_ultima_rega(id_planta, data);
    return 1;

}

/* GUARDAR REGAS */
int guardar_regas(void) {
    FILE *f_regas = fopen("regas.csv", "w");
    if (f_regas == NULL) {
        return 0;
    }

    for (int i = 0; i < total_regas; i++) {
        fprintf(f_regas, "%d,%d,%d,%d\n",
                regas[i].id_rega,
                regas[i].id_planta,
                regas[i].data_rega,
                regas[i].quantidade_agua);
    }
    fclose(f_regas);
    return 1;
}

/*  CARREGAR REGAS */
int carregar_regas(void) {
    FILE *f_regas = fopen("regas.csv", "r");
    if (f_regas == NULL) {
        return 0;
    }

    total_regas = 0;
    // ciclo while corrigido do enunciado. Corrige while (!feof(f_regas))
    while (fscanf(f_regas, "%d,%d,%d,%d\n",
                  &regas[total_regas].id_rega,
                  &regas[total_regas].id_planta,
                  &regas[total_regas].data_rega,
                  &regas[total_regas].quantidade_agua) == 4 && total_regas < MAX_REGAS) {
                    
        total_regas++;
    }

    fclose(f_regas);
    return 1;
}
