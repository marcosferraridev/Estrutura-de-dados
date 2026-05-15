#include <stdio.h>
#include <string.h>

/*
Questão 4 – letras repetidas -- estrutura de dados -- 15/05/2026
*/

typedef struct {
    char letras[100];
    int topo;
} Pilha;

void criar(Pilha *p) {
    p->topo = -1;
}

void guardar(Pilha *p, char c) {

    p->topo++;
    p->letras[p->topo] = c;
}

char ultimo(Pilha *p) {

    if (p->topo == -1) {
        return '\0';
    }

    return p->letras[p->topo];
}

int main() {

    Pilha p;
    criar(&p);
    char texto[100];

    printf("Digite a palavra desejada: ");
    scanf("%s", texto);

    for (int i = 0; i < strlen(texto); i++) {

        if (texto[i] != ultimo(&p)) {
            guardar(&p, texto[i]);
        }
    }

    printf("\nResultado final: ");

    for (int i = 0; i <= p.topo; i++) {
        printf("%c", p.letras[i]);
    }

    return 0;
}