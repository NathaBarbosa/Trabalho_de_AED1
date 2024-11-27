#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

// Estrutura para o nó da fila
typedef struct No {
    int idade;
    struct No* prox;
    struct No* ant;
} No;

// Estrutura da fila
typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} Fila;

// Inicializa uma fila vazia
void inicializaFila(Fila* fila);

// Insere um elemento no final da fila
void enfileira(Fila* fila, int idade);

// Remove um elemento do início da fila
int desenfileira(Fila* fila);

// Ordena a fila de forma decrescente (maior idade primeiro)
void ordenaFila(Fila* fila);

// Verifica se a fila está vazia
int filaVazia(Fila* fila);

// Libera a memória alocada pela fila
void liberaFila(Fila* fila);

// Imprime os elementos da fila (apenas para depuração)
void imprimeFila(Fila* fila);

#endif