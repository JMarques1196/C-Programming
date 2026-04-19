#include <stdio.h> 
#include <stdlib.h> 
#include "../include/types.h" // Acesso a definições de tipos
#include "../include/dados.h" // Acesso a funções de carregar e guardar dados
#include "../include/plantas.h" // Acesso a funções relacionadas a plantas
#include "../include/regas.h" // Acesso a funções relacionadas a regas
#include "../include/tarefas.h" // Acesso a funções relacionadas a tarefas


/* MAIN */
// Erro 14, scanf sem limites de tamanho (em todos)

int main(void) {

    carregar_dados(); // Carregar os dados existentes ao iniciar o programa

    
    int opcao;
    printf("Bem-vindo ao sistema de gestão de plantas!\n");
    
    // Correção do Erro 16: Sintaxe, do while (Do em falta)
    do{
        
        /* MENU */
        printf("1. Listar plantas\n");
        printf("2. Adicionar planta\n");
        printf("3. Listar regas\n");
        printf("4. Adicionar rega\n");
        printf("5. Listar tarefas\n");
        printf("6. Adicionar tarefa\n");
        printf("7. Concluir tarefa\n");
        printf("8. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) { // Correção = adicionar do antes do switch e fechar o bloco do while no final do main

        // Listar Plantas
        case 1:{
            printf("\n=== LISTA DE PLANTAS ===\n");
            listar_plantas();
            printf("Prima Enter para voltar ao Menu principal... ");
            getchar(); // Limpar o buffer do teclado
            getchar(); // Esperar pela entrada do utilizador
            break; // Voltar ao menu    
        }

        // Adicionar Planta
        case 2: {
            printf("\n=== ADICIONAR PLANTAS ===\n");
            getchar(); 
            
            char nome[50], especie[50], data_plantio[11];
            int intervalo_rega; /* em dias */

            printf("Introduza o Nome: "); 
            //Correção do Erro 14: Substituir scanf por fgets para ler strings com espaços e evitar buffer overflow.
            // Esta correção repete-te para todo o main onde existia scanf para ler strings.
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0'; 

            printf("Introduza a Especie: ");
            fgets(especie, sizeof(especie), stdin);
            especie[strcspn(especie, "\n")] = '\0';

            printf("Introduza a Data de Plantio (DD/MM/AAAA): ");
            fgets(data_plantio, sizeof(data_plantio), stdin);
            data_plantio[strcspn(data_plantio, "\n")] = '\0';

            printf("Introduza o Intervalo de Rega (em dias): ");
            scanf("%d", &intervalo_rega);

            adicionar_planta(nome, especie, data_plantio, intervalo_rega);
            printf("Planta adicionada com sucesso!\n");
            guardar_dados();
            break;
        }

        case 3:{
            // Verificar Regas
            printf("\n=== VERIFICAR NECESSIDADE DE REGA ===\n");
            int data_atual;
            printf("Data atual (dias desde 01/01/2026): ");
            scanf("%d", &data_atual);
            printf("Prima Enter para voltar ao Menu principal... ");
            getchar(); 
            getchar(); 
            break;    
        }   

        case  4: {
            // Adicionar Rega
            printf("\n=== ADICIONAR REGA ===\n");
            int id_planta, data, quantidade;

            printf("ID da planta: ");
            scanf("%d", &id_planta);
            printf("Data da rega (dias desde 01/01/2026): ");
            scanf("%d", &data);
            printf("Quantidade de agua (em ml): ");
            scanf("%d", &quantidade);
            registar_rega(id_planta, data, quantidade);
            guardar_dados(); 
            break;
        }

        case 5: {
            // Listar Tarefas
            listar_tarefas_pendentes();
            printf("Prima Enter para voltar ao Menu principal... ");
            getchar(); 
            getchar(); 
            break;
        }
        
        case 6: {
            // Adicionar Tarefa
            printf("\n=== ADICIONAR TAREFA ===\n");
            getchar(); 

            char descricao[100]; 
            int data_prevista;

            printf("Descricao da tarefa: ");
            fgets(descricao, sizeof(descricao), stdin);
            descricao[strcspn(descricao, "\n")] = '\0';

            printf("Data prevista (dias desde 01/01/2026): ");
            scanf("%d", &data_prevista);

            criar_tarefa(descricao, data_prevista); 
            guardar_dados(); 

            break;
        }

        case 7: {
            // Concluir Tarefa
            printf("\n=== CONCLUIR TAREFA ===\n");
            int id;
            printf("ID da tarefa a concluir: ");
            scanf("%d", &id);

            concluir_tarefa(id); 
            guardar_dados();
            break;
        }

        case 8: {
            printf("A sair do sistema. Até logo!\n");
            return 0; // sai do programa
        }

        default: {
            printf("Opcao invalida. Tente novamente.\n");
        }
    }} while (opcao != 8);

    return 0;
}
