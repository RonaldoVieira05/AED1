#include <stdio.h>
#include <stdlib.h>

#define MAX_ID 100001  // Limite máximo para os identificadores

int main() {
    int N, M, i, id;

    // Lê o número de pessoas na fila
    scanf("%d", &N);
    
    int fila[N];  // Array para armazenar os identificadores da fila
    
    // Lê os identificadores das pessoas na fila
    for (i = 0; i < N; i++) {
        scanf("%d", &fila[i]);
    }

    // Lê o número de pessoas que saíram da fila
    scanf("%d", &M);
    
    // Array de marcação para verificar quem saiu da fila
    int saiu[MAX_ID] = {0};  // Inicializado com 0, onde 1 indicará que a pessoa saiu
    
    // Lê os identificadores de quem saiu e marca no array 'saiu'
    for (i = 0; i < M; i++) {
        scanf("%d", &id);
        saiu[id] = 1;  // Marca o identificador como removido
    }

    // Imprime os identificadores das pessoas que ainda estão na fila
    int primeiro = 1;  // Flag para controlar a impressão do primeiro elemento
    for (i = 0; i < N; i++) {
        if (saiu[fila[i]] == 0) {  // Se a pessoa não saiu
            if (!primeiro) {
                printf(" ");  // Imprime espaço antes dos próximos elementos
            }
            printf("%d", fila[i]);
            primeiro = 0;  // Depois do primeiro elemento, não imprime mais antes
        }
    }
    
    printf("\n");  // Adiciona uma nova linha ao final da saída

    return 0;
}
