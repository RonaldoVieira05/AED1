#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        int i, command, x;
        int stack[MAX], queue[MAX], priorityQueue[MAX];
        int topStack = 0, frontQueue = 0, rearQueue = 0, sizePQ = 0;
        int isStack = 1, isQueue = 1, isPriorityQueue = 1;

        for (i = 0; i < n; i++) {
            scanf("%d", &command);
            
            if (command == 1) {
                // Operação 1 x: Inserir o elemento x
                scanf("%d", &x);
                if (isStack) stack[topStack++] = x;         // Pilha
                if (isQueue) queue[rearQueue++] = x;        // Fila
                if (isPriorityQueue) {                      // Fila de prioridade
                    priorityQueue[sizePQ++] = x;
                    // Ordenar a fila de prioridade manualmente
                    for (int j = sizePQ - 1; j > 0; j--) {
                        if (priorityQueue[j] > priorityQueue[j-1]) {
                            int temp = priorityQueue[j];
                            priorityQueue[j] = priorityQueue[j-1];
                            priorityQueue[j-1] = temp;
                        }
                    }
                }
            } else if (command == 2) {
                // Operação 2 x: Remover o elemento e verificar se é x
                scanf("%d", &x);
                
                if (isStack) {
                    if (topStack == 0 || stack[topStack - 1] != x) {
                        isStack = 0;
                    } else {
                        topStack--;  // Remover da pilha
                    }
                }

                if (isQueue) {
                    if (frontQueue == rearQueue || queue[frontQueue] != x) {
                        isQueue = 0;
                    } else {
                        frontQueue++;  // Remover da fila
                    }
                }

                if (isPriorityQueue) {
                    if (sizePQ == 0 || priorityQueue[0] != x) {
                        isPriorityQueue = 0;
                    } else {
                        // Remover o maior da fila de prioridade (primeiro elemento)
                        for (int j = 0; j < sizePQ - 1; j++) {
                            priorityQueue[j] = priorityQueue[j+1];
                        }
                        sizePQ--;
                    }
                }
            }
        }

        // Verificar qual estrutura de dados pode ser responsável
        if (isStack && !isQueue && !isPriorityQueue) {
            printf("stack\n");
        } else if (!isStack && isQueue && !isPriorityQueue) {
            printf("queue\n");
        } else if (!isStack && !isQueue && isPriorityQueue) {
            printf("priority queue\n");
        } else if (!isStack && !isQueue && !isPriorityQueue) {
            printf("impossible\n");
        } else {
            printf("not sure\n");
        }
    }

    return 0;
}
