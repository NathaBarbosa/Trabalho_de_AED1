
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matriz.h"
#include "log.h"

int main(void) {
    int x, y, ganhou = 0;
    int flag = 1;
    int conf = seleciona_dificuldade();

    if (conf == 0) { 
        do {
            printf("Por favor, digite uma dificuldade valida\n");
            conf = seleciona_dificuldade();
        } while (conf == 0);
    }

    int bombas = numero_de_Bombas(conf);
    int n = seleciona_Matriz_Back(conf);
    int** mat = constroi_Matriz_Back(n, bombas);
    char** mat_front = matriz_front(n);
    FILE *logfile = abrir_log();

    while (flag) {
        printf("Digite as coordenadas x,y (1 a %d): \n", (n - 2));
        scanf("%d,%d", &x, &y);

        while (((x < 1) || (y < 1)) || ((x > (n - 2)) || (y > (n - 2)))) {
            printf("Coordenada fora do escopo! Digite novamente (1 a %d): \n", (n - 2));
            scanf("%d,%d", &x, &y);
        }

        if (mat_front[x][y] != 'x') {
            printf("Posicao ja revelada. Tente outra.\n");
            
        }else {

        if (mat[x][y] == -1) {
            printf("Game over\n");
            imprime_gameOver(n, mat);
            escrever_log(logfile, mat_front, n, x, y);
            flag = 0;
            ganhou = 0;
        } else if (mat[x][y] == 0) {
            revelarZeros(x, y, n, mat_front, mat);
            escrever_log(logfile, mat_front, n, x, y);
            imprime_front(n, mat_front);
        } else {
            mat_front[x][y] = mat[x][y] + '0';
            imprime_front(n, mat_front);
            escrever_log(logfile, mat_front, n, x, y);

            if (ganhouOuPerdeu(mat_front, bombas, n)) {
                printf("Parabens, voce eh fera!\n");
                imprime_gameOver(n, mat);
                escrever_log(logfile, mat_front, n, x, y);
                flag = 0;
                ganhou = 1;
            }
        }
      }
    }

    registrar_fim_jogo(logfile, ganhou, mat, n);
    libera_matriz_back(n, mat);
    libera_matriz_front(n, mat_front);
    fclose(logfile);

    return 0;
}
