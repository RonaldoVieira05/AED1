// utilizar o insertionsort para colocar as palavras na posição correta

#include <stdio.h>
#include <string.h>
#define T 101

void ordem_alfabetica(char nomes [][T], int N, int K){
    int i, j;
    char aux[T];

    for(i = 1; i < N; i++){
        strcpy(aux, nomes[i]);
        for(j = i; j > 0 && strcmp(aux, nomes[j-1]) < 0; j--)
            strcpy(nomes[j], nomes[j-1]);
        strcpy(nomes[j], aux);
    }
    printf("%s\n", nomes[K-1]);
}

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    char nomes[N][T];

    for(int i = 0; i < N; i++)
        scanf("%s", nomes[i]);

    ordem_alfabetica(nomes, N, K);
    return 0;
}   

// o insertion analisa cada termo e os seus termos antecedentes
