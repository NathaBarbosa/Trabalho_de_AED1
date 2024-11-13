#ifndef LOG_H
#define LOG_H

#include <stdio.h>

FILE* abrir_log();
void escrever_log(FILE *logfile, char **mat_front, int n, int x, int y);
void registrar_fim_jogo(FILE *logfile, int ganhou);

#endif