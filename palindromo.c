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

    inserir(&fila, 1);
    inserir(&fila, 2);
    inserir(&fila, 3);
    inserir(&fila, 2);
    inserir(&fila, 1);

    if (ePalindromo(&fila)) {
        printf("forma um palindromo\n");
    } else {
        printf("nao forma um palindromo");
    }

    return 0;
}