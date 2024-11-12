#ifndef MATRIZ_H
#define MATRIZ_H

// Função que seleciona o nível de dificuldade
int seleciona_dificuldade();

// Função que seleciona o tamanho da matriz com base na dificuldade
int seleciona_Matriz_Back(int config);

// Função que calcula o número de bombas com base na dificuldade
int numero_de_Bombas(int config);

// Função que constrói a matriz de fundo (onde as bombas são colocadas)
int** constroi_Matriz_Back(int n, int bombas);

// Função que cria a matriz da frente (a que será mostrada ao jogador)
char** matriz_front(int n);

// Função que imprime a matriz da frente
void imprime_front(int n, char** mat_front);

// Função que imprime a matriz de fundo (mostra as bombas e números ao redor)
void imprime_gameOver(int n, int** mat_back);

// Função que libera a memória da matriz de fundo
void libera_matriz_back(int n, int** mat_back);

// Função que libera a memória da matriz da frente
void libera_matriz_front(int n, char** mat_front);

// Função recursiva para revelar células adjacentes quando o valor é zero
void revelarZeros(int x, int y, int tamanho, char** statusCampo, int** mat);

FILE* abrir_log(); // abre o arquivo log

void escrever_log(FILE *logfile, char **mat_front, int n, int x, int y); //escreve as jogadas no arquivo log.txt

#endif
