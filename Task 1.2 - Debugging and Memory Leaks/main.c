#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h> // Syntax Error, library missing

// Estrutura para armazenar dados de um estudante
typedef struct {
    char nome[50];
    float nota;
} Estudante;

// Variáveis globais
/* Estudante* estudantes;
int numEstudantes; */

// FIX: Initialize globals to safe defaults to avoid use-before-init (good practice)
Estudante* estudantes = NULL;
int numEstudantes = 0;


// Protótipos das funções
void adicionarEstudante(char* nome, float nota);
/* float calcularMedia();
void listarEstudantes();
void libertarMemoria(); */

// FIX: Add explicit (void) in prototypes without params (clearer in C)
float calcularMedia(void);
void listarEstudantes(void);
void libertarMemoria(void);


// Função principal
int main(void) {
    int opcao;
    char nome[50];
    float nota;

    setlocale(LC_ALL, "C");
    /* numEstudantes = 0; => No longer needed, as it is initialized above */
    estudantes = (Estudante*)malloc(10 * sizeof(Estudante));
    // FIX: Check malloc return to avoid NULL dereference

    if (!estudantes) {
        fprintf(stderr, "Erro: sem memória.\n");
        return 1;
    }

    
    do {
        printf("\n=== MENU ===\n");
        printf("1. Adicionar estudante\n");
        printf("2. Calcular média\n");
        printf("3. Listar estudantes\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Nome: ");
                scanf("%49s", nome); // FIX: Added limit to avoid overflow
                printf("Nota: ");
                scanf("%f", &nota); // Syntax Error, "," missing
                adicionarEstudante(nome, nota);
                break;
            case 2:
                printf("Média: %.2f\n", calcularMedia());
                break;
            case 3:
                listarEstudantes();
                break;
        }
    } while(opcao != 0);
    
    libertarMemoria();
    return 0;
}

// Adiciona um estudante à lista
void adicionarEstudante(char* nome, float nota) {
    if(numEstudantes < 10) {
        strcpy(estudantes[numEstudantes].nome, nome);
        estudantes[numEstudantes].nota = nota;
        numEstudantes++;
        printf("Estudante adicionado com sucesso!\n");
    } else {
        printf("Lista cheia!\n");
    }
}

// Calcula a média das notas
float calcularMedia(void) {
    float soma =0.0f;


    // FIX: Guard against division by zero if no students
    if (numEstudantes == 0) return 0.0f;

    int i;
    
    for(i = 0; i < numEstudantes; i++) {
        soma = soma + estudantes[i].nota;
    }    
    return soma / numEstudantes;
}

// Lista todos os estudantes
void listarEstudantes() {
    int i;
    
    if(numEstudantes == 0) {
        printf("Nenhum estudante registado.\n");
        return;
    }
    
    printf("\n=== Lista de Estudantes ===\n");
    for(i = 0; i < numEstudantes; i++) {
        printf("%d. %s - %.2f\n", i+1, estudantes[i].nome, estudantes[i].nota);
    }
}

// Liberta a memória alocada
void libertarMemoria() {
    printf("A libertar memória...\n");
    // (código de libertação omitido pelo programador original)

    // FIX: Free the allocated array to avoid memory leak
    free(estudantes);
    estudantes = NULL;

}