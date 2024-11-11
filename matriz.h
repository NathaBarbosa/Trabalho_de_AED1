// matriz.h
#ifndef MATRIZ_H
#define MATRIZ_H

#define string_MAX 10

// Funções
int seleciona_dificuldade(char *dificuldade);
int seleciona_Matriz_Back(int config);
int numero_de_Bombas(int config);
int **constroi_Matriz_Back(int n, int bombas);
char **matriz_front(int n);
void imprime_front(int n, char** mat_front);
void imprime_gameOver(int n, int** mat_back);
void libera_matriz_back(int n, int** mat_back);
void libera_matriz_front(int n, char** mat_front);

#endif // MATRIZ_H
