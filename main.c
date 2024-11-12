#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
#include <time.h>

int main(void) {
    int x, y;
    int flag = 1;
    int contador = 0;
    int conf = seleciona_dificuldade();
    if (conf == 0) { //se o usuario digitar qualquer string que nâo seja "facil", "medio" ou "dificil", pede para digitar novamente
        do {
            printf("Por favor, digite uma dificuldade valida\n");
            conf = seleciona_dificuldade();
            
        } while (conf == 0); // nâo sai do loop ate que o usuario digite uma entrada valida
    }
    int bombas = numero_de_Bombas(conf);
    int n = seleciona_Matriz_Back(conf);
    int ganhou = 0;  // Flag para armazenar se o jogador ganhou ou perdeu
    int** mat = constroi_Matriz_Back(n, bombas);
    char** mat_front = matriz_front(n);
    FILE *logfile = abrir_log();  // Abre o arquivo de log para registrar as informações
    

    while (flag) {
        printf("Agora digite as coordenadas ""x,y"" de 1 a %d para escolher uma posicao: \n", (n - 2));
        scanf("%d,%d", &x, &y); // lê as coordenadas

        // Verifica se as coordenadas estão fora do escopo
        while (((x < 1) || (y < 1)) || ((x > (n - 2)) || (y > (n - 2)))) {
            printf("A entrada tem que ser um numero dentro do escopo!\n");
            printf("Digite novamente as coordenadas x,y de 1 a %d para escolher uma posicao: \n", (n - 2));
            scanf("%d,%d", &x, &y);
        }

        // Verifica se a coordenada já foi escolhida antes
        if (mat_front[x][y] != 'x') {
            printf("Boa tentativa, informe uma entrada ainda nao usada ou ainda nao revelada\n");

        } else{
        
        
        // Verifica se a coordenada já foi escolhida antes
        if (mat[x][y] == -1) {
            printf("Game over\n");
            imprime_gameOver(n, mat);
            escrever_log(logfile,mat_front, n, x, y);
            flag = 0;
            ganhou = 0;  // Jogador perdeu
        } else if (mat[x][y] == 0) {
            revelarZeros(x, y, n, mat_front, mat); // Passa a matriz da frente e de fundo
            escrever_log(logfile,mat_front, n, x, y);
            imprime_front(n, mat_front);
            contador++;
        } else {
            mat_front[x][y] = mat[x][y] + '0'; // Marca com o número de bombas adjacentes
            imprime_front(n, mat_front);
            escrever_log(logfile,mat_front, n, x, y);
            contador++;

            if (ganhouOuPerdeu(mat_front, bombas,n)) {
                printf("Parabéns, você é fera!\n");
                imprime_gameOver(n, mat);
                escrever_log(logfile,mat_front, n, x, y);
                flag = 0;
                ganhou = 1;  // Jogador ganhou
            }
        }
    }
        fprintf(logfile, "Jogador escolheu a coordenada (%d, %d)\n", x, y);
}

    // Registra o término do jogo
    registrar_fim_jogo(logfile, ganhou);

    // Libera a memória e fecha o arquivo de log
    libera_matriz_back(n, mat);
    libera_matriz_front(n, mat_front);
    fclose(logfile);  // Fecha o arquivo de log ao finalizar o jogo

    return 0;
}
