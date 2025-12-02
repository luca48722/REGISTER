#ifndef CLIENTE_H
#define CLIENTE_H

#define MAX_CLIENTES 100

typedef struct {
    char nome[100];
    char endereco[100];
    char telefone[20];
    float valor_movel;
    float valor_impermeabilizacao;
    float desconto;
    float total;
} Cliente;

#endif
