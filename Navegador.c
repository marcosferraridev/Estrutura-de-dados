#include <stdio.h>
#include <string.h>

/*
Questão 5 – histórico de navegação -- estrutura de dados -- 15/05/2026
*/

typedef struct {
    char site[30][40];
    int topo;
} Pilha;

void iniciar(Pilha *p) {
    p->topo = -1;
}

int semDados(Pilha *p) {
    return p->topo == -1;
}

void volta(Pilha *p, char nome[]) {

    if (p->topo < 29) {
        p->topo++;

        strcpy(p->site[p->topo], nome);
    }
}

char* avanca(Pilha *p) {

    static char aux[40];

    if (semDados(p)) {
        return NULL;
    }

    strcpy(aux, p->site[p->topo]);

    p->topo--;

    return aux;
}

void limparHistorico(Pilha *p) {
    p->topo = -1;
}

int main() {

    Pilha voltar;
    Pilha avancarPilha;

    iniciar(&voltar);
    iniciar(&avancarPilha);

    char paginaAtual[40] = "Inicio";
    char novaPagina[40];

    int escolha = -1;

    while (escolha != 0) {

        printf("\n========== NAVEGADOR ==========\n");
        printf("Pagina atual: %s\n", paginaAtual);

        printf("\n1 - Abrir pagina\n");
        printf("2 - Voltar pagina\n");
        printf("3 - Avancar pagina\n");
        printf("0 - Sair\n");

        printf("\nOpcao: ");
        scanf("%d", &escolha);

        switch(escolha) {

            case 1:

                printf("Nome da pagina: ");
                scanf("%39s", novaPagina);

                volta(&voltar, paginaAtual);

                strcpy(paginaAtual, novaPagina);

                limparHistorico(&avancarPilha);

                break;

            case 2:

                if (semDados(&voltar)) {

                    printf("\nNao ha paginas anteriores\n");

                } else {

                    volta(&avancarPilha, paginaAtual);

                    strcpy(paginaAtual, avanca(&voltar));

                    printf("\nVoce voltou!\n");
                }

                break;

            case 3:

                if (semDados(&avancarPilha)) {

                    printf("\nNao existe pagina para avancar\n");

                } else {

                    volta(&voltar, paginaAtual);

                    strcpy(paginaAtual, avanca(&avancarPilha));

                    printf("\nAvancando pagina\n");
                }

                break;

            case 0:

                printf("\nFim do programa\n");

                break;

            default:

                printf("\nOpcao invalida\n");
        }
    }

    return 0;
}