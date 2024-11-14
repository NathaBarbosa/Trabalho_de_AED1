#ifndef LOG_H
#define LOG_H

#include <stdio.h>


FILE* abrir_log();
// Abre o arquivo de log "log.txt" para registro do jogo e escreve a data e hora de início.
// Se ocorrer um erro ao abrir o arquivo, exibe uma mensagem de erro e encerra o programa.
// Entrada: Nenhuma.
// Saída: Ponteiro para o arquivo de log.

void escrever_log(FILE *logfile, char **mat_front, int n, int x, int y);
// Registra o estado atual da matriz frontal (`mat_front`) e a última coordenada jogada `(x, y)` no log.
// Permite o acompanhamento do progresso do jogador no arquivo de log.
// Entrada: logfile - ponteiro para o arquivo de log; mat_front - matriz visível ao jogador. 
// n - tamanho da matriz; x, y - coordenadas da jogada.
// Saída: Nenhuma (escreve diretamente no arquivo).

void registrar_fim_jogo(FILE *logfile, int ganhou, int** mat_back, int n);
// Registra o final do jogo no arquivo de log com data e hora, além de indicar vitória ou derrota do jogador.
// Também exibe a matriz completa (com todas as bombas e números adjacentes).
// Entrada: logfile - ponteiro para o arquivo de log; ganhou - 1 se o jogador venceu, 0 se perdeu.
// mat_back - matriz de fundo; n - tamanho da matriz.
// Saída: Nenhuma (escreve diretamente no arquivo).

void jogadaFora(FILE *logfile,int x, int y);
//Registra no log.txt quando o jogador faz uma jogada fora dos limites da função
//Entrada: logfile - ponteiro para o arquivo de log; coordenadas x e y.
//Saída: Nenhuma.

void posicaoRevelada(FILE *logfile,int x, int y);
//Registra no log.txt quando o jogador insere uma coordenada ja revelada.
//Entrada: logfile - ponteiro para o arquivo de log; coordenadas x e y.
//Saída: Nenhuma.

void config(FILE *logfile, int conf);
//Registra no log.txt a dificuldade selecionada pelo jogador ou informa que a configuração escolhida não é valida.
//Entrada: logfile - ponteiro para o arquivo de log; coordenadas x e y.
//Saída: Nenhuma.

#endif
