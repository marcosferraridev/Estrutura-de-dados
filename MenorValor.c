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

// push (antes insere)
void push(Pilha *p, int valor) {

    if (pilhaCheia(p)) {
        printf("\nA pilha esta cheia\n");
        return;
    }

    p->topo++;

    p->elementos[p->topo] = valor;

    printf("\nValor %d inserido\n", valor);
}


// pop (antes remove)
void pop(Pilha *p) {

    if (pilhaVazia(p)) {
        printf("\nA pilha esta vazia\n");
        return;
    }

    printf("\nElemento removido: %d\n",
           p->elementos[p->topo]);

    p->topo--;
}


// mostra os elementos da pilha
void mostrarPilha(Pilha *p) {

	int i;
	
    if (pilhaVazia(p)) {
        printf("\nNenhum elemento na pilha\n");
        return;
    }

    printf("\nPilha atual:\n");

    for ( i = p->topo; i >= 0; i--) {
        printf("%d\n", p->elementos[i]);
    }
}


// pega o menor valor caso não esteja vazia
void getMin(Pilha *p) {
	
	int i;
	
    if (pilhaVazia(p)) {
        printf("\nPilha vazia");
        return;
    }

    int menor = p->elementos[0];

    for ( i = 1; i <= p->topo; i++) {

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

        printf("\n========= MENU ==========\n");
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

                push(&p, numero);

                break;

            case 2:
                pop(&p);

                break;

            case 3:
                mostrarPilha(&p);

                break;

            case 4:
                getMin(&p);

                break;

            case 0:
                printf("\nPrograma finalizado");

                break;

            default:

                printf("\nOpcao invalida");
        }
    }

    return 0;
}