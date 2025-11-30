/* 
 Projeto: REGISTER
 Autor: Lucas Gabriel e Gusthavo H. S. Rodrigues
 Data de criação: 14/10/2025
 Descrição: Estrutura inicial do projeto integrador.
*/

#include <stdio.h>
#include <string.h>
#include "tipos.h"
#include "entrada.h"
#include "processamento.h"
#include "saida.h"

int main(void) {
    Cliente clientes[MAX_CLIENTES];
    int cliente_atual = 0;
    char linha[16];
    char deseja_continuar = 's';

    do {
        if (cliente_atual >= MAX_CLIENTES) {
            printf("Limite de clientes (%d) atingido.\n", MAX_CLIENTES);
            break;
        }

        ler_cliente(&clientes[cliente_atual]);
        calcula_total_desconto(&clientes[cliente_atual]);

        printf("Valor final a pagar: R$ %.2f\n", clientes[cliente_atual].total);

        cliente_atual++;

        // Pergunta se deseja continuar
        while (1) {
            printf("Deseja cadastrar outro cliente? (s/n): ");
            if (!fgets(linha, sizeof(linha), stdin)) {
                clearerr(stdin);
                continue;
            }
            // pega primeiro char significativo
            char ch = linha[0];
            if (ch == '\n' || ch == '\0') continue;
            if (ch == 's' || ch == 'n') {
                deseja_continuar = ch;
                break;
            } else {
                printf("Opcao invalida. Digite 's' para sim ou 'n' para nao.\n");
            }
        }

    } while (deseja_continuar == 's');

    // Exibe todos os clientes cadastrados
    exibir_clientes(clientes, cliente_atual);

    return 0;
}
