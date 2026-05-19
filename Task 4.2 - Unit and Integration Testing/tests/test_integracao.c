#include "../include/pontuacao.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

void testar_calculo_pontuacao(void)
{
    // recebe os pontos e o bonus / penalizacao
    // Calcula o resultado final com bonus e devolve o resultado considerando as penalizacoes

    int result;
    // penalizacao = 0, resultado vai ser igual aos pontos com bonus
    result = calcular_pontuacao_nivel(100, 50, 0);
    assert(result == 150);
    // penalizacao = 50 com valores para para bonus e pontuacao
    result = calcular_pontuacao_nivel(100, 50, 20);
    assert(result == 130);
}

int main(void)
{
    testar_calculo_pontuacao();
    return 0;
}