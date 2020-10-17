#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.c"

/*Julia tem uma filha chamada Mary, Mary tem 4 anos e está começando a aprender
a escrever as letras do alfabeto. Julia decidiu deixar registrado as letras que Mary
for aprendendo a escrever. Por isso resolvi ajudá-la implementando um algoritmo que
facilite os planos de Júlia.*/
int main() {

    ArvBin* raiz = cria_ArvBin(); //criando o nó raiz que vai apontar inicialmente pra NULL

    char letra;
    printf("Bem Vindo(a)!\n");
    int rodar = 1;

    while(rodar) {
        printf("\nO que deseja fazer?\n\n");
        printf("1-Listar letras aprendidas.\n");
        printf("2-Remover letra.\n");
        printf("3-Buscar letra.\n");
        printf("4-Adicionar letra.\n");
        printf("5-Total de letras aprendidas.\n");
        printf("0-Sair\n\n");

        int op;
        scanf("%d",&op);setbuf(stdin,NULL);

        switch(op) {
        case 1:
            if(estaVazia_ArvBin(raiz)) {
                printf("Nenhuma letra aprendida!");
            }
            else {
                printf("\nPre-ordem: ");
                preOrdem_ArvBin(raiz);

                printf("\nEm-ordem: ");
                emOrdem_ArvBin(raiz);

                printf("\nPos-ordem: ");
                posOrdem_Arv(raiz);
            }
            break;
        case 2:
            if(estaVazia_ArvBin(raiz)) {
                printf("Nenhuma letra aprendida!");
            }
            else {
                printf("Qual letra deseja remover?\n");
                scanf("%c",&letra);setbuf(stdin,NULL);

                if(consulta_ArvBin(raiz,letra))
                    if(remove_ArvBin(raiz,letra))
                        printf("Removida com sucesso!\n");
                    else
                        printf("Erro ao remover!\n");
                else
                    printf("Letra nao aprendida!\n");
            }
            break;
        case 3:
            printf("Qual letra deseja buscar?\n");
            scanf("%c",&letra);setbuf(stdin,NULL);

            if(consulta_ArvBin(raiz,letra))
                printf("Letra %c consta como aprendida!\n");
            else
                printf("Letra %c nao consta nas letras aprendidas!\n");
            break;
        case 4:
            printf("Qual letra deseja adicionar?\n");
            scanf("%c",&letra);setbuf(stdin,NULL);

            if(consulta_ArvBin(raiz,letra))
                printf("Letra já adicionada!\n");
            else {
                int deuBom = insere_ArvBin(raiz,letra);
                if(deuBom)
                    printf("Letra adicionada com sucesso!\n");
                else
                    printf("Erro ao adicionar a letra!\n");
            }
            break;
        case 5:
            printf("Total de letras aprendidas: %d",totalNO_ArvBin(raiz));
            break;
        default:
            rodar = 0;
            break;
        }
    }



}
