#include "./senha.h"
#include <string.h>

int classificar_senha(int comprimento, char *classe)
{
    if (comprimento < 0 || classe == NULL)
        return 0;
    if (comprimento <= 3)
        strcpy(classe, "Fraca");
    else if (comprimento <= 7)
        strcpy(classe, "Media");
    else if (comprimento <= 15)
        strcpy(classe, "Forte");
    else if (comprimento >= 16 && comprimento <= 30) /* BUG 1: lengths > 30 are not captured */
        strcpy(classe, "Muito Forte");
    return 1; /* BUG 2: returns 1 even when comprimento < 0 */
}