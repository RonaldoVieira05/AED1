#include <stdio.h>

int main() {
    int T, PA, PB, anos;
    double G1, G2;
    
    // Lendo o número de casos de teste
    scanf("%d", &T);
    
    for (int i = 0; i < T; i++) {
        // Lendo os dados de cada caso de teste
        scanf("%d %d %lf %lf", &PA, &PB, &G1, &G2);
        
        anos = 0;
        
        // Enquanto PA não for maior que PB e o número de anos não for maior que 100
        while (PA <= PB && anos <= 100) {
            // Atualizando a população de A e B com base nas taxas de crescimento
            PA += (int)(PA * (G1 / 100));
            PB += (int)(PB * (G2 / 100));
            anos++;
        }
        
        // Se o número de anos ultrapassar 100, imprime "Mais de 1 seculo"
        if (anos > 100) {
            printf("Mais de 1 seculo.\n");
        } else {
            printf("%d anos.\n", anos);
        }
    }
    
    return 0;
}
