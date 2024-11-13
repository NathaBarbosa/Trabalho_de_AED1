#ifndef MATRIZ_H
#define MATRIZ_H

// Solicita ao usuário a seleção do nível de dificuldade (1 - Fácil, 2 - Médio, 3 - Difícil) e retorna o valor correspondente.
// Retorna 0 se uma dificuldade inválida for selecionada.
int seleciona_dificuldade();

// Define o tamanho da matriz de acordo com a dificuldade selecionada.
// Retorna 12 para fácil, 22 para médio, e 32 para difícil.
int seleciona_Matriz_Back(int config);

// Define o número de bombas na matriz com base na dificuldade.
// Retorna 15 para fácil, 60 para médio e 135 para difícil.
int numero_de_Bombas(int config);

// Cria e inicializa a matriz do campo minado com o tamanho `n` e o número de bombas fornecido.
// As bombas são representadas por -1, e as células com números representam a contagem de bombas adjacentes.
int** constroi_Matriz_Back(int n, int bombas);

// Cria e inicializa a matriz frontal, representando o campo visível para o jogador, preenchida inicialmente com 'x'.
char** matriz_front(int n);

// Exibe o campo minado que o jogador vê, mostrando a matriz `mat_front` com os valores já revelados.
void imprime_front(int n, char** mat_front);

// Exibe o campo completo, incluindo todas as bombas e números adjacentes, usado ao final do jogo (Game Over).
void imprime_gameOver(int n, int** mat_back);

// Libera a memória alocada para a matriz do campo minado (`mat_back`).
void libera_matriz_back(int n, int** mat_back);

// Libera a memória alocada para a matriz frontal (`mat_front`).
void libera_matriz_front(int n, char** mat_front);

// Função recursiva que revela células vazias adjacentes (contendo zero) a partir de uma coordenada (x, y).
// Atualiza a matriz `mat_front` para mostrar áreas reveladas.
void revelarZeros(int x, int y, int tamanho, char** statusCampo, int** mat);

// Verifica se o jogador venceu ao comparar a quantidade de células não reveladas com o número de bombas.
// Retorna 1 (verdadeiro) se a quantidade de células não reveladas for igual ao número de bombas, indicando vitória; caso contrário, retorna 0.
int ganhouOuPerdeu(char **matriz_front, int bombas, int n);

#endif
