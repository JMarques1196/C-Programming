# Task: Identify at least 4 issues with the following code:

'''
/* modulo_suspeito.h */
#define MAX 100
// Error 1: No include guards
int buffer[MAX];  // Error 2. We should not be defining or allocating storage in a header file.

void processar();

/* modulo_suspeito.c */
#include <stdio.h>

// Error 3: Header not included (include "modulo_suspeito.h")

static int privada;
// Error 4: publica should be static
int publica;

static void helper() {
    printf("Ajudante\n");
}

void processar() {
    helper();
}

/* Notes

    How to expose publica in a controled way:

    // Função pública para obter o valor
   int obter_publica(void) {
       return publica;
   }
   // Função pública para alterar o valor
   void definir_publica(int valor) {
      publica = valor;
   }

   By using a setter and a getter we have controlled exposure of the variable
*/
'''

