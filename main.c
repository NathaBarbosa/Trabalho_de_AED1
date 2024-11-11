#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"  // Incluir o cabeçalho onde as funções estão declaradas

int main(void) {
    char *dificuldade = malloc(sizeof *dificuldade * (string_MAX));
    if (dificuldade == NULL) {
        printf("Memoria Insuficiente(01)\n");
        exit(1); 
    }

    printf("Por favor, escolha uma dificuldade escrevendo: facil, medio ou dificil \n");
    scanf("%s", dificuldade);
    int x, y;
    int flag = 1;
    int contador = 0;
    int conf = seleciona_dificuldade(dificuldade);
    
    if (conf == 0) {
        do {
            printf("Por favor, escreva uma dificuldade valida: \"facil\", \"medio\" ou \"dificil\"\n");
            scanf("%s", dificuldade);
            conf = seleciona_dificuldade(dificuldade);
        } while (conf == 0);
    }

    int bombas = numero_de_Bombas(conf);
    int n = seleciona_Matriz_Back(conf);
    int** mat = constroi_Matriz_Back(n, bombas);
    char** mat_front = matriz_front(n);

    while (flag) {
        printf("Agora digite as coordenadas \"x,y\" de 1 a %d para escolher uma posicao: \n", (n - 2));
        scanf("%d,%d", &x, &y);

        // Verifica se as coordenadas estão fora do escopo
        while (((x < 1) || (y < 1)) || ((x > (n - 2)) || (y > (n - 2)))) {
            printf("A entrada tem que ser um numero dentro do escopo!\n");
            printf("Digite novamente as coordenadas x,y de 1 a %d para escolher uma posicao: \n", (n - 2));
            scanf("%d,%d", &x, &y);
        }

        // Verifica se a coordenada já foi escolhida antes
        if (mat_front[x][y] != 'x') {
            printf("Boa tentativa, informe uma entrada ainda nao usada\n");
        } 
        else {
            if (mat[x][y] == -1) {
                printf("game over\n");
                imprime_gameOver(n, mat);
                flag = 0;
            } else {
                mat_front[x][y] = mat[x][y] + '0';
                imprime_front(n, mat_front);
                contador++;
                if (contador == ((n - 2) * (n - 2)) - bombas) {
                    printf("parabens, vc eh fera\n");
                    imprime_gameOver(n, mat);
                    flag = 0;
                }
            }
        }
    }

    free(dificuldade);
    libera_matriz_back(n, mat);
    libera_matriz_front(n, mat_front);
    return 0;
}