# Sistema de Caixa Eletrônico em C

Este é um sistema interativo de caixa eletrônico (ATM) desenvolvido em linguagem C para o projeto **DataStructure-CP3**. O programa funciona via console e gerencia operações bancárias básicas, além de manter um histórico em memória das transações efetuadas durante a execução.

## ⚙️ Funcionalidades

O sistema exibe um menu com as seguintes opções:

1. **Consultar Saldo:** Exibe o valor do saldo atual em conta.
2. **Realizar Saque:** Permite retirar um valor da conta (valida se o valor é positivo e se há saldo suficiente).
3. **Realizar Depósito:** Permite adicionar valores à conta (valida se a entrada é um valor positivo).
4. **Consultar Extrato:** Exibe o histórico das 3 operações mais recentes. O sistema em si é capaz de registrar as últimas 100 movimentações em memória.
0. **Sair:** Finaliza o atendimento e encerra o programa.

## 🚀 Como Executar

### Pré-requisitos
- Compilador C (como o GCC ou MinGW).
- **Aviso de SO:** O código utiliza o comando `system("cls")` para limpar a tela, nativo de ambientes Windows. Caso vá rodar em Linux ou macOS, substitua os `system("cls")` por `system("clear")` no arquivo `main.c`.

### Compilação e Execução
Pelo terminal, navegue até a pasta do projeto e utilize os comandos:

```bash
# Compilar o código fonte
gcc main.c -o atm

# Executar o programa gerado (no Windows)
atm.exe
```

## 👥 Autores

Projeto desenvolvido por:

* **Lucas Barreto Santana** - RM: 573149
* **Pablo Renato dos Santos Sobral de Carvalho** - RM: 569894
