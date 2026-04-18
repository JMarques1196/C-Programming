
#include "../include/plantas.h"
#include "../include/types.h"
#include <stdio.h>
#include <string.h>

static Planta plantas[MAX_PLANTAS];
static int total_plantas = 0;

// Gerar ID sem input do utilizador
static int gerar_id_planta(void) {
    return total_plantas + 1;
}

/********** PLANTAS **********/ 

/* LISTAR AS PLANTAS */
void listar_plantas(void) {

    if (total_plantas == 0) {
        printf("Nao existem plantas registadas.\n");
        return;
    }

    for (int i = 0; i < total_plantas; i++) {
        printf("ID: %d\n", plantas[i].id);
        printf("  Nome: %s\n", plantas[i].nome);
        printf("  Especie: %s\n", plantas[i].especie);
        printf("  Data de plantio: %s\n", plantas[i].data_plantio);
        printf("  Intervalo de rega: %d dias\n", plantas[i].intervalo_rega);
        printf("  Ultima rega: %d\n", plantas[i].ultima_rega);
        printf("---------------------------------\n");
    }
}

/* ADICIONAR PLANTA */

int adicionar_planta(char* nome, char* especie, char* data_plantio, int intervalo) {
    
    /* Verificar se existe espaço disponível */
    if (total_plantas >= MAX_PLANTAS) {
        return 0;
    }
    plantas[total_plantas].id = gerar_id_planta();

    strncpy(plantas[total_plantas].nome, nome, sizeof(plantas[total_plantas].nome) - 1);
    plantas[total_plantas].nome[sizeof(plantas[total_plantas].nome) - 1] = '\0'; // Garantir terminação nula

    strncpy(plantas[total_plantas].especie, especie, sizeof(plantas[total_plantas].especie) - 1);
    plantas[total_plantas].especie[sizeof(plantas[total_plantas].especie) - 1] = '\0'; // Garantir terminação nula

    strncpy(plantas[total_plantas].data_plantio, data_plantio, sizeof(plantas[total_plantas].data_plantio) - 1);
    plantas[total_plantas].data_plantio[sizeof(plantas[total_plantas].data_plantio) - 1] = '\0'; // Garantir terminação nula                


    plantas[total_plantas].intervalo_rega = intervalo;
    plantas[total_plantas].ultima_rega = 0; // Inicializar ultima rega como 0 (nunca regada)

// Erro 12: falta o = para atribuir o valor de ultima_rega, o que pode resultar em um valor indefinido e causar problemas nas funções que dependem desse campo, como verificar_rega()
// Tambem falta consultar se total_plantas ultrapassou MAX_PLANTAS, o que pode causar um buffer overflow
    total_plantas++;
    return 1;
}

/* GUARDAR PLANTAS */

// Int em vez de void para poder retornar um codigo de erro.
int guardar_plantas(void) {
    FILE *f_plantas = fopen("plantas.csv", "w");
    if (f_plantas == NULL) {
        return 0;
    }
    
    for (int i = 0; i < total_plantas; i++) {
        fprintf(f_plantas, "%d,%s,%s,%s,%d,%d\n",
                plantas[i].id,
                plantas[i].nome,
                plantas[i].especie,
                plantas[i].data_plantio,
                plantas[i].intervalo_rega,
                plantas[i].ultima_rega);
    }
    fclose(f_plantas);
    return 1;
}

/*  CARREGAR PLANTAS */
/* Lógica:
    1 . Ler o ficheiro linha a linha com scanf e extrair os campos.
    2 . Para cada linha lida, criar uma nova planta no array total_plantas.
*/
int carregar_plantas(void) {
    FILE *f_plantas = fopen("plantas.csv", "r");
    if (f_plantas == NULL) {
        return 0;
    }

    total_plantas = 0;
    // ciclo while corrigido do enunciado.
    // Notas de estudo: fscanf escreve o valor numa variavel, logo usa & para saber onde ela está na memoria
    // strings nao precisam de & porque ja são ponteiros (arrays decaem para ponteiros)
    while (fscanf(f_plantas, "%d,%[^,],%[^,],%[^,],%d,%d\n",
                  &plantas[total_plantas].id,
                  plantas[total_plantas].nome,
                  plantas[total_plantas].especie,
                  plantas[total_plantas].data_plantio,
                  &plantas[total_plantas].intervalo_rega,
                  &plantas[total_plantas].ultima_rega) == 6 && total_plantas < MAX_PLANTAS) {
        total_plantas++;
    }

    fclose(f_plantas);
    return 1;
}

/* VERIFICAR NECESSIDADE DE REGA */
void verificar_rega(int data_atual) {

    printf("=== PLANTAS QUE PRECISAM DE REGA ===\n");
    for (int i = 0; i < total_plantas; i++) {
    int dias = data_atual - plantas[i].ultima_rega;
    if (dias >= plantas[i].intervalo_rega) {
        // Possivel erro no printf
    printf("Planta %s (ID: %d) precisa de rega! (ultima: %d dias atras)\n",
    plantas[i].nome, plantas[i].id, dias);
    }
}
}


/* ATUALIZAR ULTIMA REGA */

// Permite a atualizaçao da data da ultima rega sem expor a variavel diretamente.
int atualizar_ultima_rega(int id_planta, int data){
    for (int i = 0; i < total_plantas; i++) {
        if (plantas[i].id == id_planta) {
            plantas[i].ultima_rega = data;
            return 1;
        }
    }
    return 0;
}

// VERIFICAR SE PLANTA EXISTE
int planta_existe(int id_planta) {
    for (int i = 0; i < total_plantas; i++) {
        if (plantas[i].id == id_planta) {
            return 1;
        }
    }
    return 0;
}