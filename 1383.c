#include <stdio.h>

#define N 9

int main() {
    int matriz[N][N], n, a, i, j, valor;

    scanf("%d", &n);
    if (n < 1) {
        return 0;
    }

    for (a = 0; a < n; a++) {
        // Ler a matriz
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                scanf("%d", &matriz[i][j]); // i = linha, j = coluna
            }
        }

        valor = 0; // Reinicia a verificação para cada instância

        // Verificação de linhas e colunas
        for (i = 0; i < N; i++) {
            int linha[N] = {0}, coluna[N] = {0};
            for (j = 0; j < N; j++) {
                // Verificação da linha
                if (matriz[i][j] < 1 || matriz[i][j] > 9 || linha[matriz[i][j] - 1]) {
                    valor = 1;
                    break;
                }
                linha[matriz[i][j] - 1] = 1;

                // Verificação da coluna
                if (matriz[j][i] < 1 || matriz[j][i] > 9 || coluna[matriz[j][i] - 1]) {
                    valor = 1;
                    break;
                }
                coluna[matriz[j][i] - 1] = 1;
            }
            if (valor == 1) break; // Se já encontrou um erro, sai do loop
        }

        // Verificação das subgrades 3x3
        if (valor == 0) {
            for (int boxRow = 0; boxRow < 3; boxRow++) {
                for (int boxCol = 0; boxCol < 3; boxCol++) {
                    int subgrade[N] = {0};
                    for (i = 0; i < 3; i++) {
                        for (j = 0; j < 3; j++) {
                            int num = matriz[boxRow * 3 + i][boxCol * 3 + j];
                            if (num < 1 || num > 9 || subgrade[num - 1]) {
                                valor = 1;
                                break;
                            }
                            subgrade[num - 1] = 1;
                        }
                        if (valor == 1) break; // Se já encontrou um erro, sai do loop
                    }
                    if (valor == 1) break; // Se já encontrou um erro, sai do loop
                }
                if (valor == 1) break; // Se já encontrou um erro, sai do loop
            }
        }

        // Impressão do resultado
        printf("Instancia %d\n", a + 1); // Instância começa de 1
        if (valor == 1) {
            printf("NAO\n\n");
        } else {
            printf("SIM\n\n");
        }
    }

    return 0;
}
