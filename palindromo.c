#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Questão 2 – verificação se é palindromo -- estrutura de dados -- 15/05/2026
*/

typedef struct {
    int vet[100];
    int frente;
    int tras;
} Fila;

void criarFila(Fila *f) {
    f->frente = 0;
    f->tras = 0;
}

void inserir(Fila *f, int valor) {
    f->vet[f->tras] = valor;
    f->tras++;
}

int ePalindromo(Fila *f) {

    int i = f->frente;
    int j = f->tras - 1;

    while (i < j) {

        if (f->vet[i] != f->vet[j]) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

int main() {

    Fila fila;
    criarFila(&fila);

    int opcao;
    int valor;

    while (1) {

        printf("\n========= MENU ==========\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Verificar palindromo\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0) {
            printf("Encerrando..\n");
            break;
        }

        switch (opcao) {

            case 1:
                printf("Digite um valor: ");
                scanf("%d", &valor);

                inserir(&fila, valor);

                break;

            case 2:
                if (ePalindromo(&fila)) {
                    printf("forma um palindromo\n");
                } else {
                    printf("nao forma um palindromo\n");
                }

                break;

            default:
                printf("Opcao invalida\n");
        }
    }

    return 0;
}