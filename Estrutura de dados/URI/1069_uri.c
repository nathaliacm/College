#include <stdio.h>

int main () {
    int N;
    char stringTeste[1000];
    int diamantes, i,aux,aux2;

    scanf("%d",&N);

    for (i=0;i<N; i++){
        scanf("%s",stringTeste);
        diamantes = 0;
        for(aux = 0; stringTeste[aux]!='\0'; aux++){//percorre a string
            if(stringTeste[aux] == '<'){//verifica se abriu
                for(aux2 = aux; stringTeste[aux2]!='\0'; aux2++){
                    if(stringTeste[aux2] == '>'){
                        stringTeste[aux2] = 'x'; //substitui pra nao contar novamente
                        diamantes++;
                        break; //ja achou o par
                }
            }
        }
    }
    printf("%d\n", diamantes);
    }
    return 0;
}
