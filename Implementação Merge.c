void merge(int vetor[], int esq, int meio, int dir) {
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    int L[n1], R[n2];
   
    for (i = 0; i < n1; i++)
        L[i] = vetor[esq + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor[meio + 1 + j];
   
    i = 0;
    j = 0;
    k = esq;
   
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            vetor[k++] = L[i++];
        else
            vetor[k++] = R[j++];
    }
   
    while (i < n1)
        vetor[k++] = L[i++];
   
    while (j < n2)
        vetor[k++] = R[j++];
}

void merge_sort(int vetor[], int esq, int dir) {
    if (esq < dir) {
        int meio = esq + (dir - esq) / 2;
        merge_sort(vetor, esq, meio);
        merge_sort(vetor, meio + 1, dir);
        merge(vetor, esq, meio, dir);
    }
}
