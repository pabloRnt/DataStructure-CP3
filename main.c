#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char operacao[80];          // string da operação atual
char extrato[100][80];      // até 100 linhas de extrato
int qtd_extrato = 0;        // contador

void exibirMenu(){
    printf("\n========================\n");
    printf(" CAIXA ELETRONICO \n");
    printf("========================\n");
    printf("1 - Consultar Saldo\n");
    printf("2 - Realizar Saque\n");
    printf("3 - Realizar Deposito\n");
    printf("4 - Consultar Extrato\n");
    printf("0 - Sair\n");
    printf("========================\n");
    printf("Escolha uma opcao: ");
}

void gerarMensagemOperacao(char* texto_operacao, const char* tipo, float valor, float saldo_antigo, float saldo) {
    snprintf(texto_operacao, 80,
        "\nOperacao realizada: %s\n"
        "Valor %s: %.2f\n"
        "Saldo antigo: R$ %.2f\n"
        "Saldo final: R$ %.2f\n",
        tipo, tipo, valor, saldo_antigo, saldo);
}

void pausarSistema() {
    printf("\nPressione Enter para continuar...");
    getchar();
}

void consultarSaldo(float saldo) {
    float copia_saldo = saldo;

    system("cls");
    printf("\n--- SALDO ATUAL ---\n");
    printf("R$ %.2f\n", copia_saldo);
    printf("-------------------\n");

    pausarSistema();
}

float realizarDeposito(float saldo) {

    float valor;
    float saldo_antigo = saldo;

    system("cls");

    printf("\n--- DEPOSITO ---\n");
    printf("Digite o valor do deposito: R$ ");

    if (scanf("%f", &valor) != 1) {

        printf("Entrada invalida!\n");

        while(getchar() != '\n');

        pausarSistema();

        return saldo;
    }

    while(getchar() != '\n');

    if (valor <= 0 ){
        printf("Valor invalido!\n");
    } else {
        saldo += valor;
        printf("Deposito realizado com sucesso!\n");
        printf("Saldo atual: R$ %.2f", saldo);

        gerarMensagemOperacao(operacao, "Deposito", valor, saldo_antigo, saldo);

        if (qtd_extrato < 100) {
            strcpy(extrato[qtd_extrato], operacao);
            qtd_extrato++;
        } else{
            printf("Limite máximo de registros do extrato atingido!");
        }
    }

    pausarSistema();

    return saldo;
}

float realizarSaque(float saldo) {
 
    float valor;
    float saldo_antigo = saldo;

    system("cls");

    printf("\n--- SAQUE ---\n");
    printf("Digite o valor do saque: R$ ");

    if (scanf("%f", &valor) != 1) {

        printf("Entrada invalida!\n");

        while(getchar() != '\n');

        pausarSistema();

        return saldo;
    }

    while(getchar() != '\n');

    if (valor <= saldo && valor > 0) {
        saldo -= valor;

        printf("Saque realizado!\n");
        printf("Saldo atual: R$ %.2f\n", saldo);

        gerarMensagemOperacao(operacao, "Saque", valor, saldo_antigo, saldo);

        if (qtd_extrato < 100) {
            strcpy(extrato[qtd_extrato], operacao);
            qtd_extrato++;
        } else {
            printf("Limite máximo de registros do extrato atingido!");
        }
    } else {
        printf("Saldo insuficiente ou valor invalido!\n");
    }
    
    pausarSistema();

    return saldo;
}

void consultarExtratosRecentes() {
    printf("\n--- EXTRATO (3 mais recentes) ---\n");

    int total = qtd_extrato;
    int inicio = (total > 3) ? total - 3 : 0;

    for (int i = total - 1; i >= inicio; i--) {
        printf("%s\n", extrato[i]);
    }

    pausarSistema();
}

int main() { 
    
    int opcao = -1;
    float saldo = 0.0;

    do {
        system("cls");
        exibirMenu();

        if (scanf("%d", &opcao) != 1) {

            printf("Entrada invalida!\n");

            while(getchar() != '\n');

            pausarSistema();

            continue;
        }

        while (getchar()!= '\n');

        switch(opcao) {

            case 1:
                consultarSaldo(saldo);
                break;
            case 2:
                saldo = realizarSaque(saldo);
                break;
            case 3:
                saldo = realizarDeposito(saldo);
                break;
            case 4:
                consultarExtratosRecentes();
                break;
            case 0: 
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    printf("Obrigado por usar nosso ATM!");

    return 0; 
}