#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula{
    struct celula *proximo;
    char valor;
}Cel;


Cel* empilhar(char valor, Cel **topo){
    Cel *novo = malloc(sizeof(Cel));
    if(novo){
        novo->valor = valor;
        novo->proximo = *topo;
        *topo = novo;
        return *topo;
    }
    else
        return 0;
}


Cel* desempilhar(Cel **topo){
    Cel *remove = NULL;
    if(*topo != NULL){
        remove = *topo;
        *topo = (*topo)->proximo;
        free(remove);
    }
    return *topo;
}   


int main(){
    int i, N, j = 0, cont = 0; 
    char expressao[1000];
    Cel *topo = NULL;

    scanf("%d", &N);
    getchar();    

    while(j < N){
        fgets(expressao, sizeof(expressao), stdin);

        // Remove o '\n' do final da string
        size_t len = strlen(expressao);
        if (len > 0 && expressao[len - 1] == '\n') {
            expressao[len - 1] = '\0';
        }

        cont = 0; // reinicia para cada expressão

        for(i= 0; expressao[i] != '\0'; i++){ // iterando pela expressão
            if(expressao[i] == '<')
                empilhar('<', &topo);
            else if(expressao[i] == '>'){
                if(topo != NULL){
                desempilhar(&topo);
                cont++;
                }
            }
        }

        // Limpa a pilha após processar a expressão
        while (topo != NULL) {
            desempilhar(&topo);
        }

        printf("%d\n", cont);
        j++;
    }

    return 0;
}

/*acho que a melhor saída é utilizar pilhas para pegar os <, colocar em uma lista e cada vez que > 
aparecer tirar < da lista. 
Obs: se aparecer uma entrada com > antes que < o diamante não pode ser formado, ou seja, < tem que 
ir para a lista principal COMTABILIZAR QNTOS < FORAM REMOVIDOS PARA SABER A DE "DIAMANTES" FORMADOS*/
