#include <stdio.h>
#include <string.h>

char operacao[80];          // string da operação atual
char extrato[100][80];      // até 100 linhas de extrato
int qtd_extrato = 0;        // contador

void consultarSaldo(float saldo) {
    float copia_saldo = saldo;

    printf("\n--- SALDO ATUAL ---\n");
    printf("R$ %.2f\n", copia_saldo);
    getchar(); 
}

float realizarDeposito(float saldo) {
    float valor;
    printf("\n--- DEPÓSITO ---\n");
    printf("Digite o valor do deposito: ");
    scanf("%f", &valor);
    
    if (valor <= 0 ){
        printf("Valor invalido \n");
    } else {
        saldo += valor;
        float saldo_antigo = saldo - valor;
        printf("Deposito realizado com sucesso!\n");
        getchar(); 
    }

        sprintf(operacao,
            "\nOperacao realizada: Deposito\n"
            "Valor depositado: %.2f\n"
            "Saldo antigo: %.2f\n"
            "Saldo final: %.2f\n",
            valor, saldo_antigo, saldo);

    if (qtd_extrato < 100) {
        strcpy(extrato[qtd_extrato], operacao);
        qtd_extrato++;
    }
    
    return saldo;
}
float realizarSaque(float saldo) {
    float valor;

    printf("\n--- SAQUE ---\n");
    printf("Digite o valor do saque: ");
    scanf("%f", &valor);

    if (valor <= saldo && valor > 0) {
        saldo -= valor;
        float saldo_antigo = saldo + valor;
        printf("Saque realizado!\n");
        printf("Saque atual: %f\n", saldo);
        getchar(); 
    } else {
        printf("Saldo insuficiente ou valor invalido!\n");
    }

        sprintf(operacao,
            "\nOperacao realizada: Saque\n"
            "Valor sacado: %.2f\n"
            "Saldo antigo: %.2f\n"
            "Saldo final: %.2f\n",
            valor, saldo_antigo, saldo);

    if (qtd_extrato < 100) {
        strcpy(extrato[qtd_extrato], operacao);
        qtd_extrato++;
    }
    
    return saldo;
}

void consultarExtratosRecentes() {
    printf("\n--- EXTRATO (3 mais recentes) ---\n");

    int total = qtd_extrato;
    int inicio = (total > 3) ? total - 3 : 0;

    for (int i = total - 1; i >= inicio; i--) {
        printf("%s\n", extrato[i]);
    }
}
int main() { 
    
    int opcao = -1;
    float saldo = 0.0;

    while(opcao != 0) {
        printf("\n========================\n");
        printf(" CAIXA ELETRONICO \n");
        printf("========================\n");
        printf("1 - Consultar Saldo\n");
        printf("2 - Realizar Saque\n");
        printf("3 - Realizar Deposito\n");
        printf("4 - Consultar Extrato Recentemente\n");
        printf("0 - Sair\n");
        printf("========================\n");
        printf("Escolha uma opcao: ");
        
        
        scanf("%d", &opcao);

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
    }

    return 0; 
}