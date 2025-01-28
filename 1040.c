#include <stdio.h>

int main() {
    float N1, N2, N3, N4, exam_score, average, final_average;

    // Leitura das quatro notas
    scanf("%f %f %f %f", &N1, &N2, &N3, &N4);

    // Calcula a média ponderada
    average = (N1 * 2 + N2 * 3 + N3 * 4 + N4 * 1) / 10;
    printf("Media: %.1f\n", average);

    // Verifica o status do aluno com base na média
    if (average >= 7.0) {
        printf("Aluno aprovado.\n");
    } else if (average < 5.0) {
        printf("Aluno reprovado.\n");
    } else {
        printf("Aluno em exame.\n");

        // Leitura da nota do exame
        scanf("%f", &exam_score);
        printf("Nota do exame: %.1f\n", exam_score);

        // Calcula a média final
        final_average = (average + exam_score) / 2;

        if (final_average >= 5.0) {
            printf("Aluno aprovado.\n");
        } else {
            printf("Aluno reprovado.\n");
        }

        printf("Media final: %.1f\n", final_average);
    }

    return 0;
}
