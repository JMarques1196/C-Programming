/* main.c - Programa de teste completo para pilha */

#include <stdio.h>
#include "../include/stack.h"  // Inclui interface do módulo

/* Função auxiliar para imprimir estado da pilha (SEM aceder a campos internos!) */
void mostrar_estado(StackPtr p) {
    if (stack_vazia(p)) {
        printf("Pilha está VAZIA\n");
    } else {
        printf("Pilha NÃO está vazia\n");
    }
}

int main() {
    printf("=== TESTE 1: Operações básicas ===\n");
    StackPtr pilha = stack_criar(3);  // Cria pilha com capacidade 3
    
    // Teste de pilha vazia
    printf("Estado inicial: ");
    mostrar_estado(pilha);
    
    // Adiciona elementos
    printf("\nAdicionando elementos...\n");
    stack_push(pilha, 10);
    stack_push(pilha, 20);
    stack_push(pilha, 30);
    
    // Tenta adicionar além da capacidade
    printf("Tentando adicionar 4º elemento (deve falhar): ");
    stack_push(pilha, 40);  // ERRO: pilha cheia
    
    // Remove elementos (LIFO)
    printf("\nRemovendo elementos (LIFO):\n");
    printf("Topo: %d\n", stack_pop(pilha));  // 30
    printf("Topo: %d\n", stack_pop(pilha));  // 20
    
    printf("\nEstado após remoções: ");
    mostrar_estado(pilha);
    
    // Remove mais um
    printf("Último elemento: %d\n", stack_pop(pilha));  // 10
    
    // Tenta remover de pilha vazia
    printf("Tentando remover de pilha vazia: ");
    int resultado = stack_pop(pilha);  // ERRO: pilha vazia
    printf("Resultado: %d\n", resultado);
    
    printf("\nEstado final: ");
    mostrar_estado(pilha);
    
    // Destruir pilha
    printf("\nDestruindo pilha...\n");
    stack_destruir(&pilha);
    
    /* === TESTE 2: Criação inválida === */
    printf("\n\n=== TESTE 2: Criação inválida ===\n");
    StackPtr pilha_invalida = stack_criar(-1);  // Capacidade negativa
    if (pilha_invalida == NULL) {
        printf("OK: Criação com capacidade inválida recusada\n");
    }
    
    /* === TESTE 3: Uso após destruição === */
    printf("\n=== TESTE 3: Uso após destruição ===\n");
    StackPtr pilha2 = stack_criar(2);
    stack_push(pilha2, 100);
    stack_destruir(&pilha2);
    
    // Tentar usar pilha destruída
    printf("Tentando usar pilha destruída: ");
    stack_push(pilha2, 200);  // ERRO: ponteiro é NULL
    
    printf("\n=== TODOS OS TESTES CONCLUÍDOS ===\n");
    return 0;
}