#ifndef TAREFAS_H
#define TAREFAS_H
#include "../include/types.h"

int criar_tarefa(char* descricao, int data_prevista);
void listar_tarefas_pendentes(void);
void concluir_tarefa(int id);

#endif