/*
Considerando o registro definido na questão anterior, crie uma agenda com 5 pessoas.
O programa deverá usar um menu de opções (sub-rotinas), com as seguintes opções:
 Inserir os 5 registros.
 Pesquisar um dos 5 registros de cada vez pelo campo nome.
 Alterar campos de um registro.
 Sair do programa de cadastro.
*/

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct contato{
    char nome[30];
    char endereco[50];
    long int telefone;
    char situacao[1]; //L – Livre; X – Ocupado e * - Apagado)

};

void criarContato(struct contato *ptr){
    printf("Qual o nome: "); gets(ptr->nome);
    printf("endereco: "); gets(ptr->endereco);
    printf("telefone: "); scanf("%ld",&ptr->telefone); setbuf(stdin,NULL);
    printf("situacao: "); gets(ptr->situacao);
}

void exibirContato(struct contato c){
    printf("Nome: %s\n",c.nome);
    printf("Endereco: %s\n",c.endereco);
    printf("Telefone: %ld\n",c.telefone);
    printf("Situacao: %s\n",c.situacao);
}

int main(){
    int op, i;
    int numRegistros = 5;

    struct contato c[numRegistros];
    while(op!=0){
        printf("------MENU------\n");
        printf("1- Inserir os 5 registros.\n");
        printf("2- Pesquisar um dos 5 registros de cada vez pelo campo nome.\n");
        printf("3- Alterar campos de um registro.\n");
        printf("0- Sair do programa de cadastro.\n\n");

        scanf("%d",&op);

        setbuf(stdin,NULL);

        switch(op){
            case 1:
                for(i=0;i<numRegistros;i++){
                    criarContato(&c[i]);
                    puts("\n");
                    setbuf(stdin,NULL);
                }
                break;
            case 2:
                char nome[30];
                printf("Digite o nome: ");
                gets(nome);
                setbuf(stdin,NULL);
                for(i=0;i<numRegistros;i++){
                    if ( strcmp(nome,c[i].nome) == 0){
                        exibirContato(c[i]);
                        puts("\n");
                    }
                }
                break;
            case 3:
                char name[30];
                int aux;
                printf("Digite o nome do registro que deseja alterar: ");
                gets(name); setbuf(stdin,NULL);
                printf("O que deseja alterar? 1-nome 2-telefone 3-endereco 4-situacao ");
                scanf("%d",&aux); setbuf(stdin,NULL);

                for(i=0;i<numRegistros;i++){
                    if ( strcmp(name,c[i].nome) == 0){
                        switch(aux){
                            case 1:
                                printf("novo nome: ");
                                gets(c[i].nome); setbuf(stdin,NULL);
                                break;
                            case 2:
                                printf("novo telefone: ");
                                scanf("%ld",&c[i].telefone); setbuf(stdin,NULL);
                                break;
                            case 3:
                                printf("novo endereco: ");
                                gets(c[i].endereco); setbuf(stdin,NULL);
                                break;
                            case 4:
                                char s[1];
                                printf("nova situacao: ");
                                gets(c[i].situacao); setbuf(stdin,NULL);

                                break;

                        }
                        exibirContato(c[i]);
                    }
                }
                break;
            case 0:
                break;

        }
    }
}
