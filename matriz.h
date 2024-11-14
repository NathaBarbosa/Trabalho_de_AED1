#ifndef MATRIZ_H
#define MATRIZ_H


int seleciona_dificuldade();
// Função que solicita ao usuário para selecionar o nível de dificuldade do jogo.
// Retorna 1 para fácil, 2 para médio e 3 para difícil. Se uma dificuldade inválida for selecionada, retorna 0.
// Entrada: Nenhuma.
// Saída: Valor inteiro representando o nível de dificuldade.


int seleciona_Matriz_Back(int config);
// Define o tamanho da matriz do campo minado com base na dificuldade escolhida.
// Para garantir uma borda de segurança, adiciona 2 ao valor retornado (para facilitar a lógica do jogo).
// Entrada: config - nível de dificuldade selecionado (1, 2 ou 3).
// Saída: Inteiro que indica o tamanho da matriz (12 para fácil, 22 para médio, 32 para difícil).


int numero_de_Bombas(int config);
// Retorna o número de bombas a serem inseridas na matriz de acordo com a dificuldade escolhida.
// Entrada: config - nível de dificuldade selecionado (1, 2 ou 3).
// Saída: Inteiro representando a quantidade de bombas (15 para fácil, 60 para médio, 135 para difícil).


int** constroi_Matriz_Back(int n, int bombas);
// Cria e inicializa a matriz de fundo (back) do campo minado com o tamanho especificado e a quantidade de bombas.
// As bombas são inseridas aleatoriamente na matriz e são representadas por -1.
// As células ao redor das bombas recebem números indicando a contagem de bombas adjacentes.
// Entrada: n - tamanho da matriz; bombas - número de bombas a serem posicionadas.
// Saída: Ponteiro para matriz de inteiros representando o campo minado.


char** matriz_front(int n);
// Cria e inicializa a matriz frontal (visível ao jogador), preenchida inicialmente com 'x'.
// Esta matriz representa a visão do jogador durante o jogo.
// Entrada: n - tamanho da matriz.
// Saída: Ponteiro para matriz de caracteres representando o campo visível.


void imprime_front(int n, char** mat_front);
// Exibe a matriz frontal atual para o jogador, mostrando as células já reveladas.
// Entrada: n - tamanho da matriz; mat_front - ponteiro para a matriz frontal.
// Saída: Nenhuma (impressão no console).


void imprime_gameOver(int n, int** mat_back);
// Exibe a matriz de fundo completa, incluindo todas as bombas e números adjacentes, ao final do jogo (Game Over).
// Entrada: n - tamanho da matriz; mat_back - ponteiro para a matriz de fundo.
// Saída: Nenhuma (impressão no console).


void libera_matriz_back(int n, int** mat_back);
// Libera a memória alocada para a matriz de fundo (mat_back).
// Entrada: n - tamanho da matriz; mat_back - ponteiro para a matriz de fundo.
// Saída: Nenhuma.


void libera_matriz_front(int n, char** mat_front);
// Libera a memória alocada para a matriz frontal (mat_front).
// Entrada: n - tamanho da matriz; mat_front - ponteiro para a matriz frontal.
// Saída: Nenhuma.


void revelarZeros(int x, int y, int tamanho, char** statusCampo, int** mat);
// Função recursiva que revela células adjacentes contendo zero a partir de uma coordenada especificada.
// As células com valor zero são expandidas para mostrar as áreas vazias na matriz frontal.
// Entrada: x, y - coordenadas iniciais; tamanho - tamanho da matriz; statusCampo - matriz frontal; mat - matriz de fundo.
// Saída: Nenhuma (modifica diretamente a matriz frontal).


int ganhouOuPerdeu(char **matriz_front, int bombas, int n);
// Verifica se o jogador venceu comparando a quantidade de células não reveladas com o número de bombas.
// Retorna 1 se a quantidade de células não reveladas é igual ao número de bombas (indicando vitória), caso contrário, retorna 0.
// Entrada: matriz_front - matriz visível ao jogador; bombas - quantidade de bombas; n - tamanho da matriz.
// Saída: Inteiro (1 para vitória, 0 para continuação do jogo).

#endif
