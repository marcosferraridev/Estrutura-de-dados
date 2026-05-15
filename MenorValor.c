#include <stdio.h>
#include <stdlib.h>

/*
Questão 3 – Menor valor pilha -- estrutura de dados -- 15/05/2026
*/

typedef struct {
    int elementos[50];
    int topo;
} Pilha;

void iniciarPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {

    if (p->topo == -1) {
        return 1;
    }

    return 0;
}

int pilhaCheia(Pilha *p) {

    if (p->topo == 50 - 1) {
        return 1;
    }

    return 0;
}
//insere o valor na pilha caso não esteja cheia também
void insere(Pilha *p, int valor) {

    if (pilhaCheia(p)) {
        printf("\nA pilha esta cheia.\n");
        return;
    }

    p->topo++;

    p->elementos[p->topo] = valor;

    printf("\nValor %d inserido.\n", valor);
}


// Remove elemento
void remove(Pilha *p) {

    if (pilhaVazia(p)) {
        printf("\nA pilha esta vazia.\n");
        return;
    }

    printf("\nElemento removido: %d\n",
           p->elementos[p->topo]);

    p->topo--;
}
//mostra os elementos da pila
void mostrarPilha(Pilha *p) {

    if (pilhaVazia(p)) {
        printf("\nNenhum elemento na pilha\n");
        return;
    }

    printf("\nPilha atual:\n");

    for (int i = p->topo; i >= 0; i--) {
        printf("%d\n", p->elementos[i]);
    }
}
//pega o menor valor caso não esteja vazia
void getMin(Pilha *p) {

    if (pilhaVazia(p)) {
        printf("\nPilha vazia");
        return;
    }

    int menor = p->elementos[0];

    for (int i = 1; i <= p->topo; i++) {

        if (p->elementos[i] < menor) {
            menor = p->elementos[i];
        }
    }

    printf("\nMenor elemento: %d\n", menor);
}


int main() {

    Pilha p;

    iniciarPilha(&p);

    int opcao = -1;
    int numero;

    while (opcao != 0) {

        printf("\n========== MENU ==========\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Mostrar pilha\n");
        printf("4 - Menor valor\n");
        printf("0 - Encerrar\n");

        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                printf("Digite um numero: ");
                scanf("%d", &numero);

                insere(&p, numero);

                break;

            case 2:
                remove(&p);

                break;

            case 3:
                mostrarPilha(&p);

                break;

            case 4:
                getMin(&p);

                break;

            case 0:
                printf("\nPrograma finalizado.");

                break;

            default:

                printf("\nOpcao invalida.");
        }
    }

    return 0;
}