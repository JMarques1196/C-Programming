#include "../include/pontuacao.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

void testar_bonus(void)
{
    // funcao deve devolver um incremento percentual consoante o bonus aplicado
    // pontuacao = 100, bonus = 10%, return  100 + (100 * 10/100)
    int result;
    // Bonus = 0, Resultado = Pontos
    result = aplicar_bonus(100, 0);
    assert(result == 100);
    // Pontos = 0, Resultado tem que ser sempre 0 independentemente dos bonus
    result = aplicar_bonus(0, 67);
    assert(result == 0);
    // Pontos e Bonus Validos, calcula valor esperado
    result = aplicar_bonus(100, 10);
    assert(result == 110);
}

void testar_penalizacao(void)
{
    // Se a penalizacao for maior que os pontos, devolve 0, caso contrario devolve os pontos - penalizacao
    int result;

    // Penalizacao = 0 , Devolve o score inicial
    result = aplicar_penalizacao(100, 0);
    assert(result == 100);

    // Penalizacao e Pontuacao sao um numero valido, testa a logica interna
    result = aplicar_penalizacao(100, 50);
    assert(result == 50);

    // Penalizacao > Pontuacao, deve retornar 0
    result = aplicar_penalizacao(100, 101);
    assert(result == 0);

    // Penalizacao = Pontuacao - Boundary case
    result = aplicar_penalizacao(100, 100);
    assert(result == 0);

    // Edge cases: Pontuacao negativa ou Bonus negativo
}

int main(int)
{
    testar_bonus();
    testar_penalizacao();
    return 1;
}