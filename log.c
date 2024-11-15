#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "log.h"

FILE* abrir_log() {
    FILE *logfile = fopen("log.txt", "w");
    if (logfile == NULL) {
        printf("Erro ao abrir o arquivo de log.\n");
        exit(1);
    }

    time_t agora;
    struct tm *dataHora;
    time(&agora);
    dataHora = localtime(&agora);

    fprintf(logfile, "Início do jogo: %02d/%02d/%04d %02d:%02d:%02d\n", 
            dataHora->tm_mday, dataHora->tm_mon + 1, dataHora->tm_year + 1900,
            dataHora->tm_hour, dataHora->tm_min, dataHora->tm_sec);

    return logfile;
}

void escrever_log(FILE *logfile, char **mat_front, int n, int x, int y) {
    fprintf(logfile, "Matriz atual:\n");
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            fprintf(logfile, "%c  ", mat_front[i][j]);
        }
        fprintf(logfile, "\n");
    }

        fprintf(logfile, "Jogador escolheu a coordenada (%d, %d)\n", x, y);
    
}

void registrar_fim_jogo(FILE *logfile, int ganhou, int **mat_back, int n) {
    time_t agora;
    struct tm *dataHora;
    time(&agora);
    dataHora = localtime(&agora);

    fprintf(logfile, "Fim do jogo: %02d/%02d/%04d %02d:%02d:%02d\n", 
            dataHora->tm_mday, dataHora->tm_mon + 1, dataHora->tm_year + 1900,
            dataHora->tm_hour, dataHora->tm_min, dataHora->tm_sec);

    fprintf(logfile, "Matriz Final:\n");
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            if(mat_back[i][j] == -1){
              fprintf(logfile,"%d  ", mat_back[i][j]);  
            }else{
              fprintf(logfile," %d  ", mat_back[i][j]);
            }
        }
        fprintf(logfile, "\n");
    }

    fprintf(logfile, "%s\n", ganhou ? "O jogador ganhou o jogo!" : "O jogador perdeu o jogo!");
    fprintf(logfile, "\n");
}

void jogadaFora(FILE *logfile,int x, int y){

    fprintf(logfile, "Jogador escolheu uma coordenada fora do escopo: (%d, %d)\n", x, y);
}

void posicaoRevelada(FILE *logfile,int x, int y){

    fprintf(logfile, "Jogador escolheu uma coordenada ja revelada: (%d, %d)\n", x, y);
}

void config(FILE *logfile, int conf){
    if(conf == 0) {
       fprintf(logfile, "O jogador informou uma dificuldade invalida\n"); 

    }else {
       if(conf == 1){
        fprintf(logfile, "O jogador escolheu: Facil\n");
       }else if(conf == 2){
        fprintf(logfile, "O jogador escolheu: Medio\n");
       }else {
        fprintf(logfile, "O jogador escolheu: Dificil\n");
       }
    }
}
