#include <stdio.h>

int main() {
    int codigo1, codigo2, unidades1, unidades2;
    float preco1, preco2, valor_total;

    // Lendo as informações do primeiro produto
    scanf("%d %d %f", &codigo1, &unidades1, &preco1);

    // Lendo as informações do segundo produto
    scanf("%d %d %f", &codigo2, &unidades2, &preco2);

    // Calculando o valor total a pagar
    valor_total = (unidades1 * preco1) + (unidades2 * preco2);

    // Exibindo o resultado com duas casas decimais
    printf("VALOR A PAGAR: R$ %.2f\n", valor_total);

    return 0;
}
