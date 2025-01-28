#include <stdio.h>

int main() {
    int h_inicio, m_inicio, h_fim, m_fim;
    int duracao_horas, duracao_minutos, inicio_total, fim_total, duracao_total;

    // Lendo a hora e os minutos de início e fim
    scanf("%d %d %d %d", &h_inicio, &m_inicio, &h_fim, &m_fim);

    // Convertendo o tempo de início e fim para minutos totais
    inicio_total = h_inicio * 60 + m_inicio;
    fim_total = h_fim * 60 + m_fim;

    // Se o tempo de fim é menor que o de início, significa que o jogo terminou no dia seguinte
    if (fim_total <= inicio_total) {
        fim_total += 24 * 60; // Adiciona 24 horas em minutos
    }

    // Calculando a duração total em minutos
    duracao_total = fim_total - inicio_total;

    // Convertendo a duração de minutos para horas e minutos
    duracao_horas = duracao_total / 60;
    duracao_minutos = duracao_total % 60;

    // Imprimindo a duração do jogo
    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracao_horas, duracao_minutos);

    return 0;
}
