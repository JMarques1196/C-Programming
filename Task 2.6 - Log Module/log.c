#include "log.h"
#include <stdio.h> 


static int log_ativo = 1; // Variável para controlar o estado do log

// Getter and Setter functions for log_ativo

// Function to log messages
void Log_msg(const char *mensagem){ // message is a pointer to char
// In C, a string is a array of characters terminated by \0 (null character)
// By writing * mensagem, we are dereferencing the pointer to get the value it points to, which is the first character of the string.
if(log_ativo==1) { // Check if logging is active
    printf("LOG: %s\n", mensagem); // Print the log message
}
}

void Log_erro(const char *erro){
    if(log_ativo==1) {
        printf("ERRO: %s\n", erro);
    }

}

void Log_ativar(int estado){
    log_ativo = estado; // Set the log_ativo variable to the provided state
}

