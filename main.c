#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include <time.h>

int main(void) {
    int x, y;
    int flag = 1;
    int contador = 0;
    int conf = seleciona_dificuldade();
    int bombas = numero_de_Bombas(conf);
    int n = seleciona_Matriz_Back(conf);
    int ganhou = 0;  // Flag para armazenar se o jogador ganhou ou perdeu
    int** mat = constroi_Matriz_Back(n, bombas);
    char** mat_front = matriz_front(n);
    FILE *logfile = abrir_log();  // Abre o arquivo de log para registrar as informações

    // Registra o início do jogo
    time_t now;
    struct tm *info;
    time(&now);
    info = localtime(&now);
    fprintf(logfile, "Data e Hora de início: %s", asctime(info));  // Salva a hora de início no log

    while (flag) {
        printf("Agora digite as coordenadas \"x,y\" de 1 a %d para escolher uma posicao: \n", (n - 2));
        
        // Lê as coordenadas x e y no formato "x,y"
        if (scanf("%d,%d", &x, &y) != 2) {
            printf("Entrada inválida. Tente novamente com o formato \"x,y\".\n");
            return 1; // Sai do programa em caso de entrada inválida
        }

        // Verifica se as coordenadas estão fora do escopo
        while (x < 1 || y < 1 || x > (n - 2) || y > (n - 2)) {
            printf("A entrada tem que ser um numero dentro do escopo!\n");
            printf("Digite novamente as coordenadas x,y de 1 a %d para escolher uma posicao: \n", (n - 2));
            if (scanf("%d,%d", &x, &y) != 2) {
                printf("Entrada inválida. Tente novamente.\n");
                return 1; // Sai do programa em caso de entrada inválida
            }
        }

        // Registra a coordenada no log
        fprintf(logfile, "Jogador escolheu a coordenada (%d, %d)\n", x, y);
        
        // Verifica se a coordenada já foi escolhida antes
        if (mat[x][y] == -1) {
            printf("Game over\n");
            imprime_gameOver(n, mat);
            flag = 0;
            ganhou = 0;  // Jogador perdeu
        } else if (mat[x][y] == 0) {
            revelarZeros(x, y, n, mat_front, mat); // Passa a matriz da frente e de fundo
            imprime_front(n, mat_front);
            contador++;
        } else {
            mat_front[x][y] = mat[x][y] + '0'; // Marca com o número de bombas adjacentes
            imprime_front(n, mat_front);
            contador++;

            if (contador == ((n - 2) * (n - 2)) - bombas) {
                printf("Parabéns, você é fera!\n");
                imprime_gameOver(n, mat);
                flag = 0;
                ganhou = 1;  // Jogador ganhou
            }
        }
    }

    // Registra o término do jogo
    registrar_fim_jogo(logfile, ganhou);

    // Libera a memória e fecha o arquivo de log
    libera_matriz_back(n, mat);
    libera_matriz_front(n, mat_front);
    fclose(logfile);  // Fecha o arquivo de log ao finalizar o jogo

    return 0;
}#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include <time.h>

int main(void) {
    int x, y;
    int flag = 1;
    int contador = 0;
    int conf = seleciona_dificuldade();
    int bombas = numero_de_Bombas(conf);
    int n = seleciona_Matriz_Back(conf);
    int ganhou = 0;  // Flag para armazenar se o jogador ganhou ou perdeu
    int** mat = constroi_Matriz_Back(n, bombas);
    char** mat_front = matriz_front(n);
    FILE *logfile = abrir_log();  // Abre o arquivo de log para registrar as informações

    // Registra o início do jogo
    time_t now;
    struct tm *info;
    time(&now);
    info = localtime(&now);
    fprintf(logfile, "Data e Hora de início: %s", asctime(info));  // Salva a hora de início no log

    while (flag) {
        printf("Agora digite as coordenadas \"x,y\" de 1 a %d para escolher uma posicao: \n", (n - 2));
        
        // Lê as coordenadas x e y no formato "x,y"
        if (scanf("%d,%d", &x, &y) != 2) {
            printf("Entrada inválida. Tente novamente com o formato \"x,y\".\n");
            return 1; // Sai do programa em caso de entrada inválida
        }

        // Verifica se as coordenadas estão fora do escopo
        while (x < 1 || y < 1 || x > (n - 2) || y > (n - 2)) {
            printf("A entrada tem que ser um numero dentro do escopo!\n");
            printf("Digite novamente as coordenadas x,y de 1 a %d para escolher uma posicao: \n", (n - 2));
            if (scanf("%d,%d", &x, &y) != 2) {
                printf("Entrada inválida. Tente novamente.\n");
                return 1; // Sai do programa em caso de entrada inválida
            }
        }

        // Registra a coordenada no log
        fprintf(logfile, "Jogador escolheu a coordenada (%d, %d)\n", x, y);
        
        // Verifica se a coordenada já foi escolhida antes
        if (mat[x][y] == -1) {
            printf("Game over\n");
            imprime_gameOver(n, mat);
            flag = 0;
            ganhou = 0;  // Jogador perdeu
        } else if (mat[x][y] == 0) {
            revelarZeros(x, y, n, mat_front, mat); // Passa a matriz da frente e de fundo
            imprime_front(n, mat_front);
            contador++;
        } else {
            mat_front[x][y] = mat[x][y] + '0'; // Marca com o número de bombas adjacentes
            imprime_front(n, mat_front);
            contador++;

            if (contador == ((n - 2) * (n - 2)) - bombas) {
                printf("Parabéns, você é fera!\n");
                imprime_gameOver(n, mat);
                flag = 0;
                ganhou = 1;  // Jogador ganhou
            }
        }
    }

    // Registra o término do jogo
    registrar_fim_jogo(logfile, ganhou);

    // Libera a memória e fecha o arquivo de log
    libera_matriz_back(n, mat);
    libera_matriz_front(n, mat_front);
    fclose(logfile);  // Fecha o arquivo de log ao finalizar o jogo

    return 0;
}
