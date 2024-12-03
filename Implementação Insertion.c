void insertion_sort(int vetor[], int tamanho) {
    int i, j, aux;
    for (i = 1; i < tamanho; i++) {
        aux = vetor[i];
        for (j = i; j > 0 && vetor[j - 1] > aux; j--) {
            vetor[j] = vetor[j - 1];
        }
        vetor[j] = aux;
    }
}
