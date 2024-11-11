#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// Função de comparação para ordenar as strings
int compare(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N;
    scanf("%d\n", &N);

    for (int test = 0; test < N; test++) {
        char line[10000]; // linha de entrada
        fgets(line, sizeof(line), stdin);

        char *items[1000];
        int count = 0;

        // Dividindo a linha em palavras
        char *token = strtok(line, " \n");
        while (token != NULL) {
            int is_duplicate = 0;

            // Verificar se o item já existe na lista
            for (int i = 0; i < count; i++) {
                if (strcmp(items[i], token) == 0) {
                    is_duplicate = 1;
                    break;
                }
            }
          
            // Se não for duplicado, adicionar à lista
            if (!is_duplicate) {
                items[count] = malloc(strlen(token) + 1);
                strcpy(items[count], token);
                count++;
            }

            token = strtok(NULL, " \n");
        }

        // Ordenar os itens em ordem alfabética
        qsort(items, count, sizeof(char *), compare);

        // Imprimir a lista ordenada
        for (int i = 0; i < count; i++) {
            if (i > 0) printf(" ");
            printf("%s", items[i]);
            free(items[i]); // liberar memória alocada
        }
        printf("\n");
    }

    return 0;
}
