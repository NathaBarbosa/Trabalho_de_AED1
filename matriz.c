#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

int seleciona_dificuldade() {
    int config;
    printf("Escolha o nivel de dificuldade:\n1 - Facil (10x10, 15 minas)\n2 - Medio (20x20, 60 minas)\n3 - Dificil (30x30, 135 minas)\n");
    scanf("%d", &config);

    if(config != 1 && config != 2 && config != 3){
        config = 0;
    }

    // Verifica entrada inválida
   
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
        bombas = 15;
    } else if (config == 2) {
        bombas = 60;
    } else if (config == 3) {
        bombas = 135;
    }
    return bombas;
}

int **constroi_Matriz_Back(int n, int bombas) {
    srand(time(NULL)); 
    int **matriz_back = (int **)malloc(n * sizeof(int*));
    if (matriz_back == NULL) {
        printf("Erro ao alocar memoria para a matriz de fundo\n");
        exit(1); // Sai do programa se a alocação falhar
    }

    for (int i = 0; i < n; i++) {
        matriz_back[i] = (int *)malloc(n * sizeof(int));
        if (matriz_back[i] == NULL) {
            printf("Erro ao alocar memoria para a linha %d da matriz de fundo\n", i);
            exit(1); // Sai do programa se a alocação falhar
        }
    }

    // Inicializa a matriz com 0s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz_back[i][j] = 0;
        }
    }

    // Coloca as bombas na matriz
    for (int i = 0; i < bombas; i++) {
        int x = 1 + rand() % (n - 2); 
        int y = 1 + rand() % (n - 2); 
        
        if (matriz_back[x][y] == -1) {
            i--; 
        } else {
            matriz_back[x][y] = -1;
        }
    }

    // Preenche os números ao redor das bombas
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
        printf("Erro ao alocar memoria para a matriz da frente\n");
        exit(1); // Sai do programa se a alocação falhar
    }

    for (int i = 0; i < n; i++) {
        mat_front[i] = (char *)malloc(n * sizeof(char));
        if (mat_front[i] == NULL) {
            printf("Erro ao alocar memoria para a linha %d da matriz da frente\n", i);
            exit(1); // Sai do programa se a alocação falhar
        }
    }
    
    // Inicializa a matriz da frente com 'x'
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
            printf("%c  ", mat_front[i][j]);
        }
        printf("\n");
    }
}

void imprime_gameOver(int n, int** mat_back) {
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if(mat_back[i][j] == -1){
              printf("%d  ", mat_back[i][j]);  
            }else{
              printf(" %d  ", mat_back[i][j]);
            }
            
        }
        printf("\n");
    }
}

void libera_matriz_back(int n, int** mat_back) {
    for (int i = 0; i < n; i++) {
        free(mat_back[i]);
    }
    free(mat_back);
}

void libera_matriz_front(int n, char** mat_front) {
    for (int i = 0; i < n; i++) {
        free(mat_front[i]);
    }
    free(mat_front);
}

void revelarZeros(int x, int y, int n, char** mat_front, int** mat) {
    // Verifica se a posição está dentro dos limites da matriz
    if (x < 1 || x >= n - 1 || y < 1 || y >= n - 1) return;
    // Verifica se a célula já foi revelada
    if (mat_front[x][y] != 'x') return;

    // Revela a célula atual com o valor de bombas adjacentes
    if (mat[x][y] == 0) {
        mat_front[x][y] = '0';
    } else {
        mat_front[x][y] = mat[x][y] + '0';
        return;
    }

    // Recursão para revelar as células adjacentes se o valor for zero
    revelarZeros(x - 1, y, n, mat_front, mat); // Cima
    revelarZeros(x + 1, y, n, mat_front, mat); // Baixo
    revelarZeros(x, y - 1, n, mat_front, mat); // Esquerda
    revelarZeros(x, y + 1, n, mat_front, mat); // Direita
    revelarZeros(x - 1, y - 1, n, mat_front, mat); // Diagonal superior esquerda
    revelarZeros(x - 1, y + 1, n, mat_front, mat); // Diagonal superior direita
    revelarZeros(x + 1, y - 1, n, mat_front, mat); // Diagonal fprintf(logfile, "Início do jogo: %02d/%02d/%04d %02d:%02d:%02d\n", inferior esquerda
    revelarZeros(x + 1, y + 1, n, mat_front, mat); // Diagonal inferior direita
}

int ganhouOuPerdeu(char **mat_front, int bombas, int n){
    int contador = 0;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if(mat_front[i][j] == 'x'){
                contador++;
            }       
        }

    }
    if(contador == bombas){
        return 1;

    }else{

        return 0;
    }
        
}
