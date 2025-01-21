#include <stdio.h>
#include <string.h>

#define MAX 100

// Estrutura para armazenar pares de coordenadas
typedef struct {
    int x, y;
} Par;

int main() {
    int colunas, linhas;
    char mapa[MAX][MAX];
    int visitados[MAX][MAX] = {0}; // Matriz para rastrear posições visitadas

    // Lê o número de colunas e linhas
    scanf("%d %d", &colunas, &linhas);

    // Lê o mapa linha por linha
    for (int i = 0; i < linhas; ++i) {
        scanf("%s", mapa[i]);
    }

    Par pos = {0, 0}; // Começa no canto superior esquerdo
    int encontrouTesouro = 0; // Flag para saber se encontrou o tesouro

    while (1) {
        char atual = mapa[pos.y][pos.x];
        visitados[pos.y][pos.x] = 1; // Marca a posição atual como visitada

        if (atual == '*') {
            encontrouTesouro = 1; // Encontrou o tesouro
            break;
        }

        if (atual == '.') {
            break; // Sai se encontrar um espaço vazio
        }

        // Movimenta-se de acordo com a seta
        if (atual == '<') {
            if (pos.x - 1 < 0) break;
            while (pos.x > 0 && mapa[pos.y][pos.x - 1] == '.') {
                pos.x--;
            }
            pos.x--; // Move para a posição válida
        } else if (atual == '>') {
            if (pos.x + 1 >= colunas) break;
            while (pos.x < colunas - 1 && mapa[pos.y][pos.x + 1] == '.') {
                pos.x++;
            }
            pos.x++;
        } else if (atual == '^') {
            if (pos.y - 1 < 0) break;
            while (pos.y > 0 && mapa[pos.y - 1][pos.x] == '.') {
                pos.y--;
            }
            pos.y--;
        } else if (atual == 'v') {
            if (pos.y + 1 >= linhas) break;
            while (pos.y < linhas - 1 && mapa[pos.y + 1][pos.x] == '.') {
                pos.y++;
            }
            pos.y++;
        }

        // Verifica se a nova posição já foi visitada
        if (visitados[pos.y][pos.x]) {
            break; // Sai em caso de ciclo
        }
    }

    // Imprime o resultado
    printf("%c\n", encontrouTesouro ? '*' : '!');
    return 0;
}
