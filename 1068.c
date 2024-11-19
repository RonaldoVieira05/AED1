#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    struct celula *proximo;
    char valor;
} Cel;

Cel* empilhar(Cel *topo, char valor) {
    Cel *novo = malloc(sizeof(Cel));
    if (novo) {
        novo->valor = valor;
        novo->proximo = topo;
        return novo;
    }
    return topo;
}

Cel* desempilhar(Cel *topo) {
    if (topo != NULL) {
        Cel *remove = topo;
        topo = topo->proximo;
        free(remove);
    }
    return topo;
}

void verificar_parenteses(char expressao[]) {
    Cel *topo = NULL; // Pilha vazia para cada expressão
    int correta = 1;  // Flag para indicar se a expressão está correta

    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            topo = empilhar(topo, '(');
        } else if (expressao[i] == ')') {
            if (topo == NULL) { // Parêntese fechando sem um aberto correspondente
                correta = 0;
                break;
            } else {
                topo = desempilhar(topo);
            }
        }
    }

    // Se a pilha não estiver vazia, há parênteses abertos sem fechamento correspondente
    if (topo != NULL) correta = 0;

    // Limpa qualquer elemento que possa ter sobrado na pilha
    while (topo != NULL) {
        topo = desempilhar(topo);
    }

    if (correta)
        printf("correct\n");
    else
        printf("incorrect\n");
}

int main() {
    char expressao[1000];

    // Leitura de múltiplas expressões até o fim da entrada
    while (fgets(expressao, sizeof(expressao), stdin) != NULL) {
        // Remove o '\n' no final da expressão, caso exista
        size_t len = strlen(expressao);
        if (len > 0 && expressao[len - 1] == '\n') {
            expressao[len - 1] = '\0';
        }

        verificar_parenteses(expressao);
    }

    return 0;
}
