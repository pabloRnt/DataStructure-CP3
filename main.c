#include <stdio.h>


void consultarSaldo(float saldo) {
    float copia_saldo = saldo;

    printf("\n--- SALDO ATUAL ---\n");
    printf("R$ %.2f\n", copia_saldo);
    printf("-------------------\n");
    getchar(); 
    
}

float realizarDeposito(float saldo) {
    float valor;
    printf("Digite o valor do deposito: ");
    scanf("%f", &valor);
    
    if (valor <= 0 ){
        printf("Valor invalido \n");
    } else {
        saldo += valor;
        printf("Deposito realizado com sucesso!\n");
    }
    
    return saldo;
}
float realizarSaque(float saldo) {
    float valor;

    printf("Valor do saque: ");
    scanf("%f", &valor);
    if (valor <= saldo && valor > 0) {
        saldo -= valor;
        printf("Saque realizado!\n");
        printf("Saque atual: %f", saldo);
    } else {
        printf("Saldo insuficiente ou valor invalido!\n");
    }

    return saldo;
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
                
            case 0: 
                printf("Saindo...\n");
                break;

            default:
                
                printf("Opcao invalida!\n");
        }
    }

    return 0; 
}