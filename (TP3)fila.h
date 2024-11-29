#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>


typedef struct No {
    int idade;
    struct No* prox;
    struct No* ant;
} No;


typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} Fila;


void inicializaFila(Fila* fila);


void enfileira(Fila* fila, int idade);


int desenfileira(Fila* fila);


int filaVazia(Fila* fila);


void liberaFila(Fila* fila);


void imprimeFila(Fila* fila);

#endif
