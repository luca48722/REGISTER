#include <stdio.h>
#include <string.h>
#include "../include/entrada.h"

void lerNome(Cliente *c){
    printf("Digite o nome do cliente: ");
    scanf("%s", c->nome);
}

void lerEndereco(Cliente *c){
    printf("Digite o endereco do cliente: ");
    scanf("%s", c->endereco);
}

void lerTelefone(Cliente *c){
    do {
        printf("Digite o telefone do cliente (somente numeros): ");
        scanf("%s", c->telefone);

        if (strlen(c->telefone) < 8 || strlen(c->telefone) > 13) {
            printf("Telefone invalido! Digite entre 8 e 13 digitos.\n");
        }
    } while (strlen(c->telefone) < 8 || strlen(c->telefone) > 13);
}

void lerValorMovel(Cliente *c){
    do {
        printf("Digite o valor do movel: R$ ");
        scanf("%f", &c->valor_movel);

        if (c->valor_movel <= 0){
            printf("Valor invalido! Deve ser maior que zero.\n");
        }
    } while (c->valor_movel <= 0);
}

void lerValorImpermeabilizacao(Cliente *c){
    do {
        printf("Digite o valor da impermeabilizacao: R$ ");
        scanf("%f", &c->valor_impermeabilizacao);

        if (c->valor_impermeabilizacao <= 0){
            printf("Valor invalido! Deve ser maior que zero.\n");
        }
    } while (c->valor_impermeabilizacao <= 0);
}

char perguntarContinuar(){
    char opc;
    do {
        printf("Deseja cadastrar outro cliente? (s/n): ");
        scanf(" %c", &opc);
    } while (opc != 's' && opc != 'n');
    return opc;
}
