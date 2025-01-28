#include <stdio.h>
#include <string.h>

// Função para deslocar caracteres 3 posições à direita na tabela ASCII
void shiftThreePositions(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            str[i] += 3;
        }
    }
}

// Função para inverter uma string
void reverseString(char *str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// Função para deslocar caracteres da metade em diante uma posição à esquerda na tabela ASCII
void shiftHalfLeft(char *str) {
    int len = strlen(str);
    int half = len / 2;
    for (int i = half; i < len; i++) {
        str[i] -= 1;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // Consumir o '\n' após o número de casos de teste

    for (int i = 0; i < n; i++) {
        char linha[1001];
        fgets(linha, 1001, stdin);

        // Remover o '\n' no final da linha, se houver
        linha[strcspn(linha, "\n")] = '\0';

        // Primeira parte: deslocar 3 posições à direita
        shiftThreePositions(linha);

        // Segunda parte: inverter a string
        reverseString(linha);

        // Terceira parte: deslocar a metade em diante uma posição à esquerda
        shiftHalfLeft(linha);

        // Imprimir a linha criptografada
        printf("%s\n", linha);
    }

    return 0;
}
