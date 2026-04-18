/* Este Ficheiro vai conter apenas funções para manipular dados de plantas 
    Vai incluir listar e carregar plantas.
*/

#ifndef PLANTAS_H
#define PLANTAS_H
#include "../include/types.h"

void listar_plantas();
int adicionar_planta(char* nome, char* especie, char* data_plantio, int intervalo);
int guardar_plantas(void);
int carregar_plantas(void);
// Funcao para atualizar a ultima rega de uma planta
int atualizar_ultima_rega(int id_planta, int data);
// Funcao para verificar se uma planta existe
int planta_existe(int id_planta);
void verificar_rega(int data_atual);

#endif