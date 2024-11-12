#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"

int main(void) {
    FILE *logfile = abrir_log(); // Abrir o arquivo de log
    int x, y;
    int flag = 1;
    int contador = 0;
    int conf = seleciona_dificuldade();
    int bombas = numero_de_Bombas(conf);
    int n = seleciona_Matriz_Back(conf);
    int** mat = constroi_Matriz_Back(n, bombas);
    char** mat_front = matriz_front(n);

    // Registrar a seleção de dificuldade no log
    char log_msg[100];
    snprintf(log_msg, sizeof(log_msg), "Dificuldade selecionada: %d", conf);
   
    while (flag) {
        printf("Agora digite as coordenadas \"x,y\" de 1 a %d para escolher uma posicao: \n", (n - 2));

        if (scanf("%d,%d", &x, &y) != 2) {
            printf("Entrada inválida. Tente novamente com o formato \"x,y\".\n");
            return 1; 
        }

        while (x < 1 || y < 1 || x > (n - 2) || y > (n - 2)) {
            printf("A entrada tem que ser um numero dentro do escopo!\n");
            printf("Digite novamente as coordenadas x,y de 1 a %d para escolher uma posicao: \n", (n - 2));
            if (scanf("%d,%d", &x, &y) != 2) {
                printf("Entrada inválida. Tente novamente.\n");
                return 1; 
            }
        }

        // Registrar as coordenadas no log e a matriz
        escrever_log(logfile, mat_front, n, x, y);

        if (mat[x][y] == -1) {
            printf("Game over\n");
            imprime_gameOver(n, mat);
            snprintf(log_msg, sizeof(log_msg), ", que pena, o jogador antingiu uma bomba!");
            escrever_log(logfile, mat_front, n, x, y); // Registrar a jogada final (Game Over)
           
            flag = 0;
        } else if (mat[x][y] == 0) {
            revelarZeros(x, y, n, mat_front, mat);
            imprime_front(n, mat_front);
            contador++;
        } else {
            mat_front[x][y] = mat[x][y] + '0';
            imprime_front(n, mat_front);
            contador++;

            if (contador == ((n - 2) * (n - 2)) - bombas) {
                printf("Parabens, voce eh fera!\n");
                snprintf(log_msg, sizeof(log_msg), "O jogador venceu!");
                imprime_gameOver(n, mat);
                escrever_log(logfile, mat_front, n, x, y); // Registrar a jogada final (Vitória)
                flag = 0;
            }
        }
    }

    // Fechar o arquivo de log
    fclose(logfile);

    libera_matriz_back(n, mat);
    libera_matriz_front(n, mat_front);
    return 0;
}
