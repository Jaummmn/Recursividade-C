    /******************************************************************************
     Name : Sistema de banco
     Author : Joao victor de Andrade Martinho
     Date: 12/03/25
     Descrpition: programa para gerenciar saldo de banco atraves do uso de recursividade

    *******************************************************************************/

    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    void verSenha();
    void verConta();
    void verMenu();
    void depositar();
    void sacar();
    void verSaldo();
    void verLogin();
    void alterarSenha();

    char nome[10] = "joao";
    int senha = 1234;
    int tentativas = 3;
    float saldo = 100;
    int numeroConta = 237;

    int main()
    {
        printf("sistema de banco\n");
        puts("-----------------------------");
        verMenu();

        return 0;
    }

void alterarSenha() {
        verSenha();

        int novaSenha = 0;
        puts("Insira sua nova senha:");
        scanf("%d", &novaSenha);

        senha = novaSenha;
        printf("Senha alterada com sucesso!\n");
    }

    void sacar()
    {
        int valor = 0;
        puts("Qual valor para sacar?");
        scanf("%d", &valor);
        if (valor > saldo) {
            puts("Saldo insuficiente");
            sacar();
        } else {
            saldo = saldo - valor;
            printf("Saque realizado com sucesso, saldo atual: %.2f\n", saldo);
        }
    }

    void depositar()
    {
        int conta = 0;
        puts("---Qual numero da conta para depositar?---");
        scanf("%d", &conta);
        if (conta == numeroConta) {
            int valor = 0;
            puts("---Qual valor para depositar?---");
            scanf("%d", &valor);
            saldo += valor;
            printf("---Deposito realizado com sucesso, saldo atual: %.2f\n ---", saldo);
        } else {
            puts("---Numero da conta invalido---");
            depositar();
        }
    }

    void verSaldo()
    {
        printf("---Seu saldo atual: %.2f\n ---", saldo);
    }

    void verMenu()
    {
        int opcao;

        while (1) {
            printf("\n--- Menu ---\n");
            printf("1. Opcao ver saldo\n");
            printf("2. Opcao sacar\n");
            printf("3. Opcao depositar\n");
            printf("4. Opcao alterar senha\n");
            printf("5. Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &opcao);

            switch (opcao) {
                case 1:
                    printf("---Voce escolheu a opcao ver saldo---\n");
                    verLogin();
                    verSaldo();
                    break;
                case 2:
                    printf("---Voce escolheu a opcao sacar---\n");
                    verLogin();
                    sacar();
                    break;
                case 3:
                    printf("---Voce escolheu a opcao depositar---\n");
                    depositar();
                    break;
                case 4:
                    puts("---Voce escolheu a opcao alterar senha---\n");
                    alterarSenha();
                    break;
                case 5:
                    printf("Saindo\n");
                    return;
                default:
                    printf("---Opcao invalida. Tente novamente.---\n");
                break;
            }
        }
    }

    void verLogin()
    {
	    fflush(stdin);
        char user[10];
        puts("---Login:---");
        gets(user);

        if (strcmp(user, nome) == 0) {
            verSenha();
        } else {
            verLogin();
        }
    }

    void verSenha()
    {

        int pwd = 0;
        puts("---Senha:---");
        scanf("%d", &pwd);

        if (pwd == senha) {
            printf("---Login realizado com sucesso!---\n");

        } else {
            tentativas--;
            printf("---Senha incorreta, tentativas restantes: %d---\n", tentativas);

            if (tentativas > 0) {
                verSenha();
            } else {
                puts("___________________________________");
                printf("---Tentativas esgotadas, voltando para o login.---\n");
                tentativas = 3;
                verLogin();
            }
        }
    }

