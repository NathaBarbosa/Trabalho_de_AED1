#include "fila.h"

// Inicializa a fila
void inicializaFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}


void enfileira(Fila* fila, int idade) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Erro de memória.\n");
        exit(1);
    }
    novo->idade = idade;
    novo->prox = NULL;
    novo->ant = fila->fim;

    if (fila->fim) fila->fim->prox = novo;
    fila->fim = novo;

    if (!fila->inicio) fila->inicio = novo;
    fila->tamanho++;
}


int desenfileira(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia.\n");
        return 1;
    }

    No* removido = fila->inicio;
    int idade = removido->idade;

    fila->inicio = removido->prox;
    if (fila->inicio) fila->inicio->ant = NULL;
    else fila->fim = NULL;

    free(removido);
    fila->tamanho--;
    return idade;
}


int filaVazia(Fila* fila) {
    return fila->tamanho == 0;
}


void liberaFila(Fila* fila) {
    while (!filaVazia(fila)) {
        desenfileira(fila);
    }
}


void imprimeFila(Fila* fila) {
    No* atual = fila->inicio;
    while (atual) {
        printf("%d ", atual->idade);
        atual = atual->prox;
    }
    printf("\n");
}

void libera_lista(Fila* fila){
    
}
