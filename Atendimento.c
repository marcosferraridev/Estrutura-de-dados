#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Questão 1 – Simulação de fila de atendimento -- estrutura de dados -- 15/05/2026
*/

typedef struct Cliente {
    char nome[50];
    int id; 
    struct Cliente *prox;
} Cliente;

typedef struct {
    Cliente *inicio;
    Cliente *fim;
} Fila;


void adicionar(Fila *f, char nome[], int id) {
    Cliente *novo = (Cliente*) malloc(sizeof(Cliente)); 

    strcpy(novo->nome, nome);
    novo->id = id;
    novo->prox = NULL;

    if(f->fim != NULL) {
        f->fim->prox = novo;
    }

    f->fim = novo;

    if(f->inicio == NULL) {
        f->inicio = novo;
    }
    printf("Cliente %s inserido \n", nome);
}

void atender(Fila *f) {
    if(f->inicio == NULL) {
        printf("\nFila vazia!\n");
        return;
    }

    Cliente *temp = f->inicio;

    printf("\nAtendendo: %s - ID: %d\n", temp->nome, temp->id);

    f->inicio = temp->prox;

    if(f->inicio == NULL) {
        f->fim = NULL;
    }

    free(temp);
}

void mostrarProximo(Fila *f) {
    if(f->inicio == NULL) {
        printf("\nFila vazia!\n");
    } else {
        printf("\nProximo cliente a ser atendido: %s (ID: %d)\n", f->inicio->nome, f->inicio->id);
    }
}

void mostrarTamanho(Fila *f) {
    int cont = 0;
    Cliente *atual = f->inicio;
    
    while(atual != NULL) {
        cont++;
        atual = atual->prox;
    }
    printf("\nTamanho atual da fila: %d \n", cont);
}

void mostrar(Fila *f) {
    Cliente *a = f->inicio;

    if(a == NULL) {
        printf("\nA fila esta vazia.\n");
        return;
    }

    printf("\nCLIENTES NA FILA\n");
    while(a != NULL) {
        printf("ID: %d - Nome: %s\n", a->id, a->nome);
        a = a->prox;
    }
    printf("------------------------------------------\n");
}

int main() {
    Fila f;
    f.inicio = NULL;
    f.fim = NULL;

    int opcao;
    char nome[50];
    int id;

    do {
        printf("\n===== MENU DE ATENDIMENTO =====\n");
        printf("1- Inserir cliente na fila\n");
        printf("2- Atender cliente ou remover\n");
        printf("3- Mostrar proximo cliente\n");
        printf("4- Mostrar tamanho da fila\n");
        printf("5- Mostrar todos os clientes da fila\n");
        printf("0- Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); 

        switch(opcao) {
            case 1:
                printf("Digite o nome do cliente: ");
                fgets(nome, 50, stdin);
                
                printf("Digite o ID do cliente: ");
                scanf("%d", &id);
                
                adicionar(&f, nome, id);

                break;
                
            case 2:
                atender(&f);

                break;
                
            case 3:
                mostrarProximo(&f);

                break;
                
            case 4:
                mostrarTamanho(&f);

                break;
                
            case 5:
                mostrar(&f);

                break;
                
            case 0:
                printf("Encerrando o sistema");

                break;
                
            default:
                printf("Opcao invalida!");
        }
    } while(opcao != 0);

    return 0;
}