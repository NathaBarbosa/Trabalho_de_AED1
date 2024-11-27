#include "fila.h"

// Inicializa a fila
void inicializaFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

// Insere um elemento no final da fila
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

// Remove um elemento do início da fila
int desenfileira(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia.\n");
        return -1;
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

// Ordena a fila com Bubble Sort (decrescente)
void ordenaFila(Fila* fila) {
    if (fila->tamanho < 2) return;

    int trocou;
    do {
        trocou = 0;
        No* atual = fila->inicio;
        while (atual && atual->prox) {
            if (atual->idade < atual->prox->idade) {
                int temp = atual->idade;
                atual->idade = atual->prox->idade;
                atual->prox->idade = temp;
                trocou = 1;
            }
            atual = atual->prox;
        }
    } while (trocou);
}

// Verifica se a fila está vazia
int filaVazia(Fila* fila) {
    return fila->tamanho == 0;
}

// Libera a memória da fila
void liberaFila(Fila* fila) {
    while (!filaVazia(fila)) {
        desenfileira(fila);
    }
}

// Imprime os elementos da fila
void imprimeFila(Fila* fila) {
    No* atual = fila->inicio;
    while (atual) {
        printf("%d ", atual->idade);
        atual = atual->prox;
    }
    printf("\n");
}