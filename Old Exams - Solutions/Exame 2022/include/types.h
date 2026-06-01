#ifndef TYPES_H
#define TYPES_H

#define MAX_MESAS 20
#define MAX_GRUPOS 30

typedef struct
{
    int numero;
    int lugares;
    int ocupacao;
} Mesa;

typedef struct
{
    char ordem;
    int tamanho_grupo;
} Cliente;

typedef struct
{
    int numero_mesa;
    char grupo_cliente;
} Ordenacao;

#endif