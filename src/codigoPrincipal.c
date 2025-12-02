// Programa para cadastrar clientes de uma empresa de impermeabilizacao de moveis

#include <stdio.h>
#include <string.h>

// definicao de constante para o numero maximo de clientes
// pra nao ultrapassar o limite do array

#define MAX_CLIENTES 100

int main()
{

    // Declaracao de variaveis (nome do cliente, endereco, telefone, valor do movel, valor da impermeabilizacao, total a pagar, desconto)
    // + variavel [MAX_CLIENTES] para controle de repeticao

    char nome[MAX_CLIENTES][100];
    char endereco[MAX_CLIENTES][100];
    char telefone[MAX_CLIENTES][20];
    float valor_movel[MAX_CLIENTES], valor_impermeabilizacao[MAX_CLIENTES], total[MAX_CLIENTES], desconto[MAX_CLIENTES];
    char deseja_continuar;

    // variavel para controlar o cliente atual
    int cliente_atual = 0;

    // estrutura de repeticao para para cadastrar varios clientes
    do
    {
        printf("Digite o nome do cliente: ");
        scanf("%s", nome[cliente_atual]);

        printf("Digite o endereco do cliente: ");
        scanf("%s", endereco[cliente_atual]);

        // estrutura de repeticao para validar o telefone
        //  se o telefone tiver menos de 8 digitos ou mais de 13 digitos, pedir para digitar novamente
        // se digitar uma letra, pede pra digitar denovo
        do
        {
            printf("digite o telefone do cliente (somente numeros): ");
            scanf("%s", telefone[cliente_atual]);

            if (strlen(telefone[cliente_atual]) < 8 || strlen(telefone[cliente_atual]) > 13)
            {
                printf("insira um valor maior que zero.\n");
            }
        } while (strlen(telefone[cliente_atual]) < 10 || strlen(telefone[cliente_atual]) > 13);

        // estrutura de repeticao para validar o valor do movel e da impermeabilizacao
        // valor do movel deve ser maior que zero

        do
        {
            printf("digite o valor do movel: R$ ");
            scanf("%f", &valor_movel[cliente_atual]);

            if (valor_movel[cliente_atual] <= 0)
            {
                printf("insira um valor maior que zero.\n");
            }

        } while (valor_movel[cliente_atual] <= 0);

        // estrutura de repeticao para validar o valor da impermeabilizacao
        //  valor da impermeabilizacao deve ser maior que zero

        do
        {
            printf("Digite o valor da impermeabilizacao: R$ ");
            scanf("%f", &valor_impermeabilizacao[cliente_atual]);

            if (valor_impermeabilizacao[cliente_atual] <= 0)
            {
                printf("Valor invalido. O valor da impermeabilizacao nao pode ser negativo.\n");
            }
        } while (valor_impermeabilizacao[cliente_atual] <= 0);

        // Calculo do valor do movel + valor da ipermeabilização = TOTAL.
        // para aplicar desconto se necessario

        total[cliente_atual] = valor_movel[cliente_atual] + valor_impermeabilizacao[cliente_atual];

        // condicional de desconto: se TOTAL for maior que R$300,00, aplicar desconto de 15%
        // senao, sem desconto

        if (total[cliente_atual] > 300)
        {
            desconto[cliente_atual] = total[cliente_atual] * 0.15;
            total[cliente_atual] = total[cliente_atual] - desconto[cliente_atual];
            printf("Desconto de 15%% aplicado.\n");
        }
        else
        {
            desconto[cliente_atual] = 0;
            printf("Sem desconto.\n");
        }

        // Exibir o valor final a pagar
        printf("Valor final a pagar: R$ %.2f\n", total[cliente_atual]);

        // Incrementa o cliente atual para o proximo cadastro
        cliente_atual++;

        // estrutura de repeticao para validar a resposta da continuacao do cadastro de mais algum cliente
        // se a resposta for diferente de 's' ou 'n', pedir para digitar novamente
        do
        {
            // Pergunta se deseja continuar
            printf("Deseja cadastrar outro cliente? (s/n): ");
            scanf(" %c", &deseja_continuar); // espaço antes do %c limpa o buffer

            if (deseja_continuar != 's' && deseja_continuar != 'n')
            {
                printf("Opcao invalida. Digite 's' para sim ou 'n' para nao.\n");
            }

        } while (deseja_continuar != 's' && deseja_continuar != 'n');

    } while (deseja_continuar == 's');

    // tabela pra organizar os dados cadastrados dos clientes
    //titulo da tabela
    printf("\n----- Clientes Cadastrados -----\n");

    // titulos das colunas
    printf("Nome\t\tEndereco\tTelefone\t\tValor Movel\t\tValor Impermeabilizacao\t\tDesconto\t\tTotal a Pagar\n");

    //estrutura de repeticao pra mostrar os dados de cada cliente cadastrado
    for (int i = 0; i < cliente_atual; i++)
    {
        printf("%s\t\t%s\t\t%s\t\tR$ %.2f\t\tR$ %.2f\t\t\tR$ %.2f\t\tR$ %.2f\n",
               nome[i],
               endereco[i],
               telefone[i],
               valor_movel[i],
               valor_impermeabilizacao[i],
               desconto[i],
               total[i]);
    }
    return 0;
}