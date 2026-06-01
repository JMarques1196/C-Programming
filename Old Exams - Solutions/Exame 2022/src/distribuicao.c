// Distribuir o maximo de pessoas respeitando a ordem de chegada.

// Recebe a lista de mesas e grupos em espera e devolve o print da distribuição de mesas.
#include "../include/types.h"

// Logica
/*
 * Se a mesa recebida no csv tiver lotação > 0, sai do arranjo
 * Se a lotação for 0, verificamos se algum grupo cabe na mesa, por ordem de chegada
 * Se o grupo couber, alocamos o grupo à mesa e saímos do arranjo
 * Se o grupo não couber, passamos para o próximo grupo, até encontrar um que caiba ou chegar ao fim do arranjo de grupos
 * Devolve o resultado ordenado
 */

int distribuicao(Mesa *mesas, int total_mesas, Cliente *clientes, int total_grupos, Ordenacao *ordenacao)
{
    int total_ordenados = 0; // Controla quantas linhas de relatório criámos

    // 1. Corremos cada grupo por ordem de chegada
    for (int x = 0; x < total_grupos; x++)
    {
        int conseguiu_mesa = 0; // Flag para saber se o grupo foi sentado

        // 2. Procuramos uma mesa para este grupo
        for (int i = 0; i < total_mesas; i++)
        {
            // Se a mesa já tiver ocupação, saltamos para a próxima mesa
            if (mesas[i].ocupacao > 0)
            {
                continue;
            }

            // Se a mesa estiver livre, verificamos se o grupo cabe
            if (mesas[i].lugares >= clientes[x].tamanho_grupo)
            {
                // O Grupo senta-se!
                ordenacao[total_ordenados].grupo_cliente = clientes[x].ordem;
                ordenacao[total_ordenados].numero_mesa = mesas[i].numero;

                // Atualizamos a ocupação da mesa para que mais ninguém se sente lá
                mesas[i].ocupacao = clientes[x].tamanho_grupo;

                conseguiu_mesa = 1; // Ativamos a flag
                total_ordenados++;
                break; // Grupo já tem mesa, paramos de procurar mesas para ele
            }
        }

        // 3. Se corremos as mesas todas e a flag continuar a 0, o grupo vai para "wait"
        if (conseguiu_mesa == 0)
        {
            ordenacao[total_ordenados].grupo_cliente = clientes[x].ordem;
            ordenacao[total_ordenados].numero_mesa = -1; // O nosso marcador "wait"
            total_ordenados++;
        }
    }

    return total_ordenados; // Devolvemos quantos registos foram criados
}


/* 

A Lógica do Algoritmo (Best-Fit) => Para alocar o maior numero de lugares possiveis
ara cada grupo de clientes: 
Olhas para todas as mesas.
Ignoras as mesas que não têm espaço suficiente.
Para as mesas que têm espaço, calculas o desperdício: $\text{Lugares Livres} - \text{Tamanho do Grupo}$.
Guardas a mesa que der o menor desperdício.
No final do loop das mesas, se encontraste uma mesa ideal, sentas lá o grupo (atualizas a ocupação da mesa). 
Se não encontraste nenhuma, o grupo fica em "wait".

*/