#include "fila.h"

#define ARQUIVO "clientes.txt"

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

    // Ordenando a fila
    printf("Fila antes da ordenação:\n");
    imprimeFila(&fila);

    ordenaFila(&fila);

    printf("Fila após a ordenação:\n");
    imprimeFila(&fila);

    // Atendendo os clientes (desenfileirando)
    printf("Atendendo os clientes:\n");
    while (!filaVazia(&fila)) {
        int atendido = desenfileira(&fila);
        printf("Atendendo cliente com idade: %d\n", atendido);
    }

    // Liberando a memória
    liberaFila(&fila);

    return 0;
}
