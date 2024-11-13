#ifndef LOG_H
#define LOG_H

#include <stdio.h>

// Abre o arquivo de log "log.txt" para escrita e registra o início do jogo com data e hora.
// Se ocorrer erro ao abrir o arquivo, exibe uma mensagem de erro e encerra o programa.
FILE* abrir_log();

// Escreve no arquivo de log a matriz frontal (`mat_front`) atual do jogo e a última coordenada jogada `(x, y)`.
void escrever_log(FILE *logfile, char **mat_front, int n, int x, int y);

// Registra no arquivo de log o final do jogo com data e hora e indica se o jogador venceu ou perdeu.
void registrar_fim_jogo(FILE *logfile, int ganhou);

#endif
