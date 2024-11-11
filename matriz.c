// matriz.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

int seleciona_dificuldade(char *dificuldade) {
    int config = 0;
    int i = 0;
    char facil[5] = {'f', 'a', 'c', 'i', 'l'};
    char medio[5] = {'m', 'e', 'd', 'i', 'o'};
    char dificil[7] = {'d', 'i', 'f', 'i', 'c', 'i', 'l'};

    while (dificuldade[i] != '\0') {
        if (dificuldade[i] == facil[i]) {
            config = 1;
        } else if (dificuldade[i] == medio[i]) {
            config = 2;
        } else if (dificuldade[i] == dificil[i]) {
            config = 3;
        } else {
            config = 0;
        }
        i++; 
    }
    return config;
} 

int seleciona_Matriz_Back(int config) {
    int n = 0;
    if (config == 1) {
        n = 10; // Dificuldade fácil
    } else if (config == 2) {
        n = 20; // Dificuldade média
    } else if (config == 3) {
        n = 30; // Dificuldade difícil
    } else {
        n = 0; // Entrada inválida
    }
    return n + 2; // Retorna a quantidade de linhas/colunas (adicionando 2 para evitar bordas)
}

int numero_de_Bombas(int config) {
    int bombas = 0;
    if (config == 1) {
        bombas = 3;
    } else if (config == 2) {
        bombas = 6;
    } else if (config == 3) {
        bombas = 9;
    }
    return bombas;
}

int **constroi_Matriz_Back(int n, int bombas) {
    srand(time(NULL)); 
    int **matriz_back = (int **)malloc(n * sizeof(int*));
    
    for (int i = 0; i < n; i++) {
        matriz_back[i] = (int *)malloc(n * sizeof(int));
    }
    if (matriz_back == NULL) {
        printf("Memoria insuficiente(02)\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz_back[i][j] = 0;
        }
    }
    for (int i = 0; i < bombas; i++) {
        int x = 1 + rand() % (n - 2); 
        int y = 1 + rand() % (n - 2); 
        
        if (matriz_back[x][y] == -1) {
            i--; 
        } else {
            matriz_back[x][y] = -1;
        }
    }
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if (matriz_back[i][j] == -1) { 
                if (matriz_back[i-1][j] != -1) matriz_back[i-1][j] += 1;
                if (matriz_back[i+1][j] != -1) matriz_back[i+1][j] += 1;
                if (matriz_back[i][j-1] != -1) matriz_back[i][j-1] += 1;
                if (matriz_back[i][j+1] != -1) matriz_back[i][j+1] += 1;
                if (matriz_back[i-1][j-1] != -1) matriz_back[i-1][j-1] += 1;
                if (matriz_back[i-1][j+1] != -1) matriz_back[i-1][j+1] += 1;
                if (matriz_back[i+1][j-1] != -1) matriz_back[i+1][j-1] += 1;
                if (matriz_back[i+1][j+1] != -1) matriz_back[i+1][j+1] += 1;
            }
        } 
    }
    return matriz_back;
}

char **matriz_front(int n) {
    char **mat_front = (char **)malloc(n * sizeof(char*));
    if (mat_front == NULL) {
        printf("Memoria insuficiente(03)\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        mat_front[i] = (char *)malloc(n * sizeof(char));
        if (mat_front[i] == NULL) {
            printf("Memoria insuficiente(03)\n");
            exit(1);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat_front[i][j] = 'x';
        }
    }
    return mat_front;
}

void imprime_front(int n, char** mat_front) {
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            printf("%c ", mat_front[i][j]);
        }
        printf("\n");
    }
}

void imprime_gameOver(int n, int** mat_back) {
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            printf("%d  ", mat_back[i][j]);
        }
        printf("\n");
    }
}

void libera_matriz_back(int n, int** mat_back) {
    for (int i = 1; i < n; i++) {
        free(mat_back[i]);
    }
    free(mat_back);
}

void libera_matriz_front(int n, char** mat_front) {
    for (int i = 1; i < n; i++) {
        free(mat_front[i]);
    }
    free(mat_front);
}
