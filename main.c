#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char operacao[80];          // Armazena a string formatada da última operação
char extrato[100][80];      // Matriz para armazenar o histórico de até 100 operações
int qtd_extrato = 0;        // Contador global de operações realizadas

void exibirMenu(){
    // Exibe as opções disponíveis para o usuário no console
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
    // Formata uma string detalhada sobre a transação para ser salva no extrato
    snprintf(texto_operacao, 80,
        "\nOperacao realizada: %s\n"
        "Valor %s: %.2f\n"
        "Saldo antigo: R$ %.2f\n"
        "Saldo final: R$ %.2f\n",
        tipo, tipo, valor, saldo_antigo, saldo);
}

void pausarSistema() {
    // Interrompe a execução até que o usuário pressione Enter, evitando que mensagens sumam da tela
    printf("\nPressione Enter para continuar...");
    getchar();
}

void consultarSaldo(float saldo) {
    // Apenas exibe o valor atual da variável saldo
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
    
    // Validação para garantir que a entrada seja um número
    if (scanf("%f", &valor) != 1) {

        printf("Entrada invalida!\n");

        // Limpa o buffer do teclado para evitar loops infinitos
        while(getchar() != '\n');

        pausarSistema();

        return saldo;
    }

    while(getchar() != '\n');

    // Verifica se o valor é positivo antes de alterar o saldo
    if (valor <= 0 ){
        printf("Valor invalido!\n");
    } else {
        saldo += valor;
        printf("Deposito realizado com sucesso!\n");
        printf("Saldo atual: R$ %.2f", saldo);
        
        // Registra a operação no histórico global
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

    // Verifica se há saldo suficiente para a retirada
    if (valor <= saldo && valor > 0) {
        saldo -= valor;

        printf("Saque realizado!\n");
        printf("Saldo atual: R$ %.2f\n", saldo);
        
        // Registra a operação no histórico global
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
    // Percorre a matriz de extrato de trás para frente para mostrar os últimos registros
    printf("\n--- EXTRATO (3 mais recentes) ---\n");

    int total = qtd_extrato;
    int inicio = (total > 3) ? total - 3 : 0;

    // Loop que exibe as últimas 3 transações ou todas se houver menos de 3
    for (int i = total - 1; i >= inicio; i--) {
        printf("%s\n", extrato[i]);
    }

    pausarSistema();
}

int main() { 
    
    int opcao = -1;
    float saldo = 0.0;

    // Loop principal do programa
    do {
        system("cls");
        exibirMenu();
        
        // Validação da entrada do menu
        if (scanf("%d", &opcao) != 1) {

            printf("Entrada invalida!\n");

            while(getchar() != '\n');

            pausarSistema();

            continue;
        }

        while (getchar()!= '\n');

        // Direciona para a função correspondente à escolha do usuário
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