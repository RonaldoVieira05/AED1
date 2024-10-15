#include <stdio.h>

int main() {
    int idade, resultado_ano = 0, resultado_mes = 0, restante_para_dias = 0;

    // Entrada da idade em dias
    scanf("%d", &idade);

    if (idade >= 365) {
        // Calcula os anos
        resultado_ano = idade / 365;
        // Calcula o restante para meses
        int restante_para_meses = idade - (resultado_ano * 365);
        resultado_mes = restante_para_meses / 30;
        // Calcula o restante para dias
        restante_para_dias = restante_para_meses - (resultado_mes * 30);
    } else if (idade >= 30) {
        // Calcula os meses e o restante para dias
        resultado_mes = idade / 30;
        restante_para_dias = idade - (resultado_mes * 30);
    } else {
        // Caso em que a idade é menor que 30 dias
        restante_para_dias = idade;
    }

    // Saída no formato esperado, sempre com anos, meses e dias
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", resultado_ano, resultado_mes, restante_para_dias);

    return 0;
}
