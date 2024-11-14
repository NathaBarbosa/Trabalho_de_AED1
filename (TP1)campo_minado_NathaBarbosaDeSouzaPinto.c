#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define string_MAX 10

int seleciona_dificuldade(char *dificuldade) {
    int config = 0;
    int i = 0;
    char facil[5] = {'f', 'a', 'c', 'i', 'l'};
    char medio[5] = {'m', 'e', 'd', 'i', 'o'};
    char dificil[7] = {'d', 'i', 'f', 'i', 'c', 'i', 'l'};
    
    while (dificuldade[i] != '\0') {
        if (dificuldade[i] == facil[i]) {
            config = 1;
        } else if (dificuldade[i] == medio[i]) {
            config = 2;
        } else if (dificuldade[i] == dificil[i]) {
            config = 3;
        } else {
            config = 0;
        }
        i++; 
    }
    return config; // Retorna um número correspondente à escolha do usuário ou zero {0} se não for uma entrada válida
} 

int seleciona_Matriz_Back(int config) {
    int n = 0;
    if (config == 1) {
        n = 10; // Dificuldade fácil
    } else if (config == 2) {
        n = 20; // Dificuldade média
    } else if (config == 3) {
        n = 30; // Dificuldade difícil
    } else {
        n = 0; // Entrada inválida
    }
    return n + 2; // Retorna a quantidade de linhas/colunas (adicionando 2 para evitar bordas)
}

int numero_de_Bombas(int config) {
    int bombas = 0;
    if (config == 1) {
        bombas = 3;
    } else if (config == 2) {
        bombas = 6;
    } else if (config == 3) {
        bombas = 9;
    }
    return bombas; // essa função atribui o numero de bombas de acordo com a dificuldade
}

int **constroi_Matriz_Back(int n, int bombas) {

    srand(time(NULL)); //gerando numero aleatorios com a seed fornecida pela biblioteca <time.h>
    int **matriz_back = (int **)malloc(n * sizeof(int*));
    
    for (int i = 0; i < n; i++) {
        matriz_back[i] = (int *)malloc(n * sizeof(int));
    }
    if (matriz_back == NULL) {
        printf("Memoria insuficiente(02)\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz_back[i][j] = 0; // inicializa com zeros a matriz
        }
    }
    for (int i = 0; i < bombas; i++) {
        int x = 1 + rand() % (n - 2); // Sorteia de 1 até n-2 (evita as bordas)
        int y = 1 + rand() % (n - 2); // Sorteia de 1 até n-2 (evita as bordas)
        
        if (matriz_back[x][y] == -1) {
            i--; // Se já tem uma bomba nessa posição, sorteia outra.
        } else {
            matriz_back[x][y] = -1; // Coloca a bomba.
        }
    }
    // adicionando +1 em todos os elementos perto do -1, caso não estejam nas bordas da matriz
    for (int i = 1; i < n - 1; i++) {
    for (int j = 1; j < n - 1; j++) {
        if (matriz_back[i][j] == -1) {  // Verifica se a coordenada atual é uam bomba (-1)
            // Verifica e incrementa as coordenadas ao redor, se não forem bombas (-1)
            if (matriz_back[i-1][j] != -1) {  // coordenadas acima
                matriz_back[i-1][j] += 1;
            }
            if (matriz_back[i+1][j] != -1) {  // coordenadas abaixo
                matriz_back[i+1][j] += 1;
            }
            if (matriz_back[i][j-1] != -1) {  // coordenadas à esquerda
                matriz_back[i][j-1] += 1;
            }
            if (matriz_back[i][j+1] != -1) {  // coordenadas à direita
                matriz_back[i][j+1] += 1;
            }
            if (matriz_back[i-1][j-1] != -1) {  // Diagonal superior esquerda
                matriz_back[i-1][j-1] += 1;
            }
            if (matriz_back[i-1][j+1] != -1) {  // Diagonal superior direita
                matriz_back[i-1][j+1] += 1;
            }
            if (matriz_back[i+1][j-1] != -1) {  // Diagonal inferior esquerda
                matriz_back[i+1][j-1] += 1;
            }
            if (matriz_back[i+1][j+1] != -1) {  // Diagonal inferior direita
                matriz_back[i+1][j+1] += 1;
            }
        }
    } 
}
    return matriz_back; // O motivo para evitar as bordas é para facilitar a lógica de verificaçao
}

char **matriz_front(int n) {
    char **mat_front = (char **)malloc(n * sizeof(char*));
    if (mat_front == NULL) {
        printf("Memoria insuficiente(03)\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        mat_front[i] = (char *)malloc(n * sizeof(char));
        if (mat_front[i] == NULL) {
            printf("Memoria insuficiente(03)\n");
            exit(1);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mat_front[i][j] = 'x';
        }
    }
    return mat_front;
}

void imprime_front(int n, char** mat_front) {
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            printf("%c ", mat_front[i][j]);
        }
        printf("\n"); // como construi uma matriz com casas a mais, imprimo somente
                        //o necessario e fujo de qualquer erro por acessar algo fora da matriz
    }
}

void imprime_gameOver(int n, int** mat_back) {
    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < n - 1; j++) {
            printf("%d  ", mat_back[i][j]);
        }
        printf("\n"); //imprime a matriz_back sem os 'x' 
    }
}

void libera_matriz_back(int n, int** mat_back) {
    for (int i = 1; i < n ; i++) {
        free(mat_back[i]);
    }       //função que libera a alocção dinâmica de memoria da matriz_back
    free(mat_back);
}

void libera_matriz_front(int n, char** mat_front) {
    for (int i = 1; i < n ; i++) {
        free(mat_front[i]);
    } //função que libera a alocção dinâmica de memoria da matriz_front
    free(mat_front);
}

int main(void) {
    char *dificuldade = malloc(sizeof *dificuldade * (string_MAX));
    if (dificuldade == NULL) {
        printf("Memoria Insuficiente(01)\n");
        exit(1); //escolhi fazer manualmente para praticar 
    }

    printf("Por favor, escolha uma dificuldade escrevendo: facil, medio ou dificil \n");
    scanf("%s", dificuldade); // lê a dificuldade que o usuario escolher para jogar
    int x, y;
    int flag = 1;
    int contador = 0;
    int conf = seleciona_dificuldade(dificuldade);
    if (conf == 0) { //se o usuario digitar qualquer string que nâo seja "facil", "medio" ou "dificil", pede para digitar novamente
        do {
            printf("Por favor, escreva uma dificuldade valida: ""facil"", ""medio"" ou ""dificil""\n");
            scanf("%s", dificuldade);
            conf = seleciona_dificuldade(dificuldade);
        } while (conf == 0); // nâo sai do loop ate que o usuario digite uma entrada valida
    }

    int bombas = numero_de_Bombas(conf);
    int n = seleciona_Matriz_Back(conf);
    int** mat = constroi_Matriz_Back(n, bombas);
    char** mat_front = matriz_front(n);

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
            printf("Boa tentativa, informe uma entrada ainda nao usada\n");
        } 
        // Caso as coordenadas sejam válidas e não usadas, processa o jogo
        else {
            if (mat[x][y] == -1) { //se a coordenada for uma bomba, imprime game over e mostra  matriz_back
                printf("game over\n"); 
                imprime_gameOver(n, mat);
                flag = 0;
            } else { // se não, coloca o elemento da matriz_back na matriz_front
                mat_front[x][y] = mat[x][y] + '0';
                imprime_front(n, mat_front);
                contador++; //adiciona +1 no contador caso essa operação seja feita
                if (contador == ((n - 2) * (n - 2)) - bombas) { //se um determinado numero de jogadas forem feitas com sucesso, encerra o game
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
