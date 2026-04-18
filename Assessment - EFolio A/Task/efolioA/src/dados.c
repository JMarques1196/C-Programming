#include "../include/dados.h"
#include "../include/plantas.h"
#include "../include/regas.h"
#include "../include/tarefas.h" 

void carregar_dados(void) {
    carregar_plantas();
    carregar_regas();
    carregar_tarefas(); 
}

void guardar_dados(void) {
    guardar_plantas();
    guardar_regas();
    guardar_tarefas(); 
}
