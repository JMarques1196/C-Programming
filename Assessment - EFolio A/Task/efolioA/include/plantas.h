#ifndef PLANTAS_H
#define PLANTAS_H
#include "../include/types.h"

void listar_plantas(void);
int adicionar_planta(char* nome, char* especie, char* data_plantio, int intervalo);
int guardar_plantas(void);
int carregar_plantas(void);
int atualizar_ultima_rega(int id_planta, int data);
int planta_existe(int id_planta);
void verificar_rega(int data_atual);

#endif 
