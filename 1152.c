#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma aresta
typedef struct {
    int origem, destino, peso;
} Aresta;

// Função de comparação para ordenar as arestas pelo peso
int comparar(const void* a, const void* b) {
    Aresta* arestaA = (Aresta*)a;
    Aresta* arestaB = (Aresta*)b;
    return arestaA->peso - arestaB->peso;
}

// Funções para o algoritmo de união e busca (Union-Find)
int encontrar(int* pai, int vertice) {
    if (pai[vertice] != vertice) {
        pai[vertice] = encontrar(pai, pai[vertice]); // Compressão de caminho
    }
    return pai[vertice];
}

void unir(int* pai, int* rank, int vertice1, int vertice2) {
    int raiz1 = encontrar(pai, vertice1);
    int raiz2 = encontrar(pai, vertice2);

    if (raiz1 != raiz2) {
        if (rank[raiz1] > rank[raiz2]) {
            pai[raiz2] = raiz1;
        } else if (rank[raiz1] < rank[raiz2]) {
            pai[raiz1] = raiz2;
        } else {
            pai[raiz2] = raiz1;
            rank[raiz1]++;
        }
    }
}

int main() {
    while (1) {
        int m, n;
        scanf("%d %d", &m, &n);

        if (m == 0 && n == 0) {
            break;
        }

        Aresta* arestas = (Aresta*)malloc(n * sizeof(Aresta));
        int custoTotal = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].origem, &arestas[i].destino, &arestas[i].peso);
            custoTotal += arestas[i].peso;
        }

        // Ordena as arestas pelo peso
        qsort(arestas, n, sizeof(Aresta), comparar);

        // Algoritmo de Kruskal
        int* pai = (int*)malloc(m * sizeof(int));
        int* rank = (int*)calloc(m, sizeof(int));
        for (int i = 0; i < m; i++) {
            pai[i] = i;
        }

        int custoMST = 0;
        for (int i = 0; i < n; i++) {
            int origem = arestas[i].origem;
            int destino = arestas[i].destino;

            if (encontrar(pai, origem) != encontrar(pai, destino)) {
                unir(pai, rank, origem, destino);
                custoMST += arestas[i].peso;
            }
        }

        printf("%d\n", custoTotal - custoMST);

        free(arestas);
        free(pai);
        free(rank);
    }

    return 0;
}
