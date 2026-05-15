#include <stdio.h>

float saldo;

void consultarSaldo(float saldo) {
    float copia_saldo = saldo;

    printf("\n--- SALDO ATUAL ---\n");
    printf("R$ %.2f\n", copia_saldo);
    printf("-------------------\n");
    system("pause"); // Aguarda o usuario
}

float realizarDeposito(saldo) {
    float valor;
    printf("Digite o valor do deposito: ");
    scanf("%f", &valor);

        if (valor <= 0 ){
            printf("Valor invalido \n");
        } else {
            saldo += valor;
            printf("Deposito realizado com sucesso!");
        }
        
    return saldo;
}

int main() {
    int opcao = 0;

    
    while(opcao != 5) {
        printf("\n========================\n");
        printf(" CAIXA ELETRONICO \n");
        printf("========================\n");
        printf("1 - Consultar Saldo\n");
        printf("2 - Realizar Saque\n");
        printf("3 - Realizar Deposito\n");
        printf("0 - Sair\n");
        printf("========================\n");
        printf("Escolha uma opcao: ");
        
        // Lê a escolha do usuário
        scanf("%d", &opcao);

        // Estrutura de decisão baseada na variável 'opcao'
        switch(opcao) {

            case 1:
               
                printf("Saldo: R$ 1000,00\n");
                    break;

            case 2:
                printf("Digite o valor do saque: ");
                float saque;
                scanf("%f", &saque);
                if (saque > 1000) {
                    printf("Saldo insuficiente!\n");
                } else {
                    printf("Saque realizado com sucesso! Novo saldo: R$ %.2f\n", 1000 - saque);
                }
                break;
            case 3:
                printf("Digite o valor do deposito: ");
                float deposito;
                scanf("%f", &deposito);
                printf("Deposito realizado com sucesso! Novo saldo: R$ %.2f\n", 1000 + deposito);
                break;
                
            case 0: { 
                 // Finaliza o loop while 
                printf("Saindo...\n");
                break;
                
            }

            default:
                // Executado caso o usuário digite um número que não esteja no menu
                printf("Opcao invalida!\n");
        }
    }

    return 0; // Encerra o programa com sucesso
}