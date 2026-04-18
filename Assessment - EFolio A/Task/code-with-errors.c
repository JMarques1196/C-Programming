/* TYPES AND VARIABLES */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ── Tipos de dados ────────────────────────────────────────── */
#define MAX_PLANTAS 100
#define MAX_REGAS 500
#define MAX_TAREFAS 200

typedef struct {
int id;
char nome[50];
char especie[50];
char data_plantio[11]; /* DD/MM/AAAA */
int intervalo_rega; /* em dias */
int ultima_rega; /* timestamp: dias desde 01/01/2026 */
} Planta;

typedef struct {
int id_rega;
int id_planta;
int data_rega; /* timestamp: dias desde 01/01/2026 */
int quantidade_agua; /* em ml */
} Rega;

typedef struct {
int id_tarefa;
char descricao[100];
int data_prevista; /* timestamp: dias desde 01/01/2026 */
int concluida; /* 0 = pendente | 1 = concluida */
} Tarefa;

Planta plantas[MAX_PLANTAS];
Rega regas[MAX_REGAS];
Tarefa tarefas[MAX_TAREFAS];
int total_plantas = 0;
int total_regas = 0;
int total_tarefas = 0;

/* SNIPPET 1 - LOAD DATA*/
// Dois Erros
void carregar_dados() {
   
FILE *f_plantas = fopen("plantas.csv", "r");
if (f_plantas == NULL) { printf("Erro\n"); return; }

while (!feof(f_plantas)) { // Erro numero 1: feof() só retorna true após uma leitura falhar por ter atingido o fim do ficheiro, logo vai executar uma leitura a mais onde nao le nada
    // Coreerção: while (fscanf(...) == 6) { ... } - Tipo de Erro: Logico
    fscanf(f_plantas, "%d,%[^,],%[^,],%[^,],%d,%d\n",
    &plantas[total_plantas].id, 
    plantas[total_plantas].nome,
    plantas[total_plantas].especie,
    plantas[total_plantas].data_plantio,
    &plantas[total_plantas].intervalo_rega,
    &plantas[total_plantas].ultima_rega);
    total_plantas++;
}
// Erro numero 2: Não verificar se total_plantas ultrapassou MAX_PLANTAS, o que pode causar um buffer overflow
fclose(f_plantas);
// Erro 3, nao existe verificaçao se fopen falhou, como para f_plantas. o que pode causar um crash se o ficheiro nao existir ou tiver problemas de leitura
// Tipo de erro: robusteza / segurança
FILE *f_regas = fopen("regas.csv", "r");
while (!feof(f_regas)) {

}

/* SNIPPET 2 - LIST PLANTS*/

void listar_plantas() {
printf("=== PLANTAS ===\n");
for (int i = 0; i <= total_plantas; i++) { // Erro 4: O loop deve ser i < total_plantas, pois os indices vao de 0 a total_plantas-1. Com o <= vai tentar acessar plantas[total_plantas] que é fora do array, causando um comportamento indefinido
printf("ID: %d | Nome: %s | [...]\n", plantas[i].id, plantas[i].nome,
[...]);
}
}


/* REGISTER IRRIGATION */
// Função que receve os dados de uma rega e armazena no array de regas. Retorna 1 se a rega foi registrada com sucesso, ou 0 se houve um erro (ex: array cheio).
int registar_rega(int id_planta, int data, int quantidade) {
    // Erro 5 Ausencia de verificação se total_regas ultrapassou MAX_REGAS, o que pode causar um buffer overflow
    // outro erro seria nao verificar se a planta existe, mas isso pode ser opcional dependendo do design do programa
regas[total_regas].id_rega = total_regas + 1;
regas[total_regas].id_planta = id_planta;
regas[total_regas].data_rega = data;
regas[total_regas].quantidade_agua = quantidade;
total_regas++;
[...]
return 1;
}


/* CHECK IRRIGATION */
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


/* CREATE TASK */

void criar_tarefa(char* descricao, int data_prevista) {
    // Erro 7, Ausencia de verificação se total_tarefas ultrapassou MAX_TAREFAS, o que pode causar um buffer overflow
tarefas[total_tarefas].id_tarefa = total_tarefas + 1;
// Erro 8: Possivel Buffer overflow em strcpy se descricao for maior que 99 caracteres (o array tem espaço para 100, mas o ultimo é para o terminador nulo)
strcpy(tarefas[total_tarefas].descricao, descricao);
tarefas[total_tarefas].data_prevista = data_prevista;
tarefas[total_tarefas].concluida = 0;
total_tarefas++;
}

/* LIST TASKS */

void listar_tarefas_pendentes() {
[...]
for (int i = 0; i < total_tarefas; i++) {
    // Erro 9: O operador de comparação deve ser ==, mas foi usado =, o que causa uma atribuição em vez de uma comparação, resultando em um comportamento incorreto (sempre entrando no if e marcando a tarefa como concluida)
if (tarefas[i].concluida = 0) {
printf("Tarefa %d: %s (prevista: %d)\n",
tarefas[i].id_tarefa, tarefas[i].descricao,
tarefas[i].data_prevista);
}
}

/* CONCLUDE TASKS */

void concluir_tarefa(int id) {
for (int i = 0; i < total_tarefas; i++) {
    // Erro 10: O operador de comparação deve ser ==, mas foi usado =, o que causa uma atribuição em vez de uma comparação, resultando em um comportamento incorreto (sempre marcando a tarefa como concluida independentemente do id)
if (tarefas[i].id_tarefa = id) {
tarefas[i].concluida = 1;
[...]
return;
}
}

/* SAVE DATA */

void guardar_dados() {
FILE *f_plantas = fopen("plantas.csv", "w");
if (f_plantas == NULL) { printf("Erro\n"); return; }
for (int i = 0; i < total_plantas; i++) {
    // Erro 11: O formato do printf deve corresponder aos tipos dos dados. Se plantas[i].nome, plantas[i].especie ou plantas[i].data_plantio contiverem vírgulas, isso pode corromper o formato CSV. Uma solução seria usar aspas para envolver os campos de texto ou substituir as vírgulas por outro caractere.
fprintf(f_plantas, "%d,%s,%s,%s,%d,%d\n", plantas[i].id, [...]);
}
fclose(f_plantas);
}

/* ADD PLANTS */

void adicionar_planta(int id, char* nome, char* especie,
char* data_plantio, int intervalo) {
[...]
plantas[total_plantas].intervalo_rega = intervalo;
// Erro 12: falta o = para atribuir o valor de ultima_rega, o que pode resultar em um valor indefinido e causar problemas nas funções que dependem desse campo, como verificar_rega()
// Tambem falta consultar se total_plantas ultrapassou MAX_PLANTAS, o que pode causar um buffer overflow
plantas[total_plantas].ultima_rega total_plantas++;
}

/* MAIN */
// Erro 13, scanf sem limites de tamanho (em todos)
int main() {
[...]
// Erro 14: Sintaxe, do while (Do em falta)
switch (opcao) {
[...]
case 2: {
int id, intervalo;
char nome[50], especie[50], data[11];
printf("Nome: "); scanf("%s", nome);
printf("Especie: "); scanf("%s", especie);
[...]
break;
}
[...]
case 6: {
char descricao[100]; int data_prevista;
printf("Descricao: "); scanf("%s", descricao);
[...]
break;
}
[...]
} while (opcao != 8);
return 0;
}