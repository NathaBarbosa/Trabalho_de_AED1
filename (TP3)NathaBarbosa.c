#include "fila.h"

#define ARQUIVO "clientes.txt"

void bubbleSort(Fila* fila){
     int trocou;
    do {
        trocou = 0;
        No* atual = fila->inicio;
        while (atual && atual->prox) {
            if (atual->idade < atual->prox->idade) {
                int temp = atual->idade;
                atual->idade = atual->prox->idade;
                atual->prox->idade = temp;
                trocou = 1;
            }
            atual = atual->prox;
        }
    } while (trocou);
}



int main() {
    Fila fila;
    inicializaFila(&fila);

    // Abrindo o arquivo para leitura
    FILE* arquivo = fopen(ARQUIVO, "r");
    if (!arquivo) {
        printf("Erro ao abrir o arquivo %s.\n", ARQUIVO);
        return 1;
    }

    // Lendo idades do arquivo e enfileirando
    int idade;
    while (fscanf(arquivo, "%d", &idade) != EOF) {
        enfileira(&fila, idade);
    }
    fclose(arquivo);

    printf("Fila nao ordenada:\n");
    imprimeFila(&fila);

    // Ordenando a fila
    bubbleSort(&fila);
    
    

    // Atendendo os clientes (desenfileirando e liberando memória)
    printf("Atendendo os clientes:\n");
    while (!filaVazia(&fila)) {
        int atendido = desenfileira(&fila);
        printf("Atendido: %d\n", atendido);
    }

    // Liberando memória da fila (garantia final)
    liberaFila(&fila);

    return 0;
}
