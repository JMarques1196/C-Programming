#include "log.h"
#include <stdio.h>

int main() {

    /* Demonstração completa das funcionalidades */
    
    // Teste 1: Log ativo por padrão
    printf("=== Teste 1: Log ativo (padrão) ===\n");
    Log_msg("Sistema iniciado");
    Log_erro("Ficheiro não encontrado");
    Log_msg("Operação concluída");
    
    // Teste 2: Desativar o log
    printf("\n=== Teste 2: Desativar log ===\n");
    Log_ativar(0);  // Desativa
    
    // Estas mensagens NÃO devem aparecer
    Log_msg("Esta mensagem não deve aparecer");
    Log_erro("Este erro também não deve aparecer");
    
    // Teste 3: Reativar o log
    printf("\n=== Teste 3: Reativar log ===\n");
    Log_ativar(1);  // Reativa
    
    // Estas mensagens DEVEM aparecer novamente
    Log_msg("Log reativado com sucesso");
    Log_erro("Teste final de erro");
    
    // Teste 4: Estado inválido (robustez)
    printf("\n=== Teste 4: Estado inválido ===\n");
    Log_ativar(42);  // Valor inválido, mas tratado como "ativo"
    Log_msg("Teste com estado inválido");
    
    return 0;
}