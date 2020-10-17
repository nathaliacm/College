/*

A seção de controle de produção de uma fábrica mantém um arquivo de registros de
produção por funcionários. Cada registro contém o nome do funcionário (como uma
cadeia de 35 caracteres), o sexo do funcionário (M- masculino ou F- feminino) e o
número de peças produzidas pelo funcionário.
 Escrever um programa que calcule de escreva:
A quantidade de peças produzidas pelos funcionários do sexo masculino e
feminino;
O nome do(a) funcionário(a) com a maior produção registrada (obs. não
haverá empates).

*/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct registro{
    char nome[35];
    char sexo;
    int num_pecas;
};

void registrar(struct registro *ptr){
    printf("Qual o nome: "); gets(ptr->nome);
    printf("sexo: "); scanf("%c",&ptr->sexo);
    printf("pecas: "); scanf("%d",&ptr->num_pecas);
}

void exibirRegistro(struct registro r){
    printf("Nome: %s\n",r.nome);
    printf("Sexo: %c\n",r.sexo);
    printf("Pecas: %d\n",r.num_pecas);
}

int main(){
    int qtRegistros,i;
    int pecas_M = 0;
    int pecas_F = 0;
    char s = 'F';
    int aux,maior = 0;

    printf("Quantos registros? ");
    scanf("%d",&qtRegistros); setbuf(stdin,NULL);
    struct registro r[qtRegistros];

    for(i = 0;i<qtRegistros;i++){
        registrar(&r[i]);
        setbuf(stdin,NULL);
        if( r[i].sexo == 'F'){
            pecas_F+=r[i].num_pecas;
        } else{
            pecas_M+=r[i].num_pecas;
        }

        if(r[i].num_pecas>maior){
            maior = r[i].num_pecas;
            aux = i;
        }
        puts("\n");

    }

    printf("quantidade de pecas produzidas pelos funcionarios do sexo masculino: %d\n",pecas_M);
    printf("quantidade de pecas produzidas pelos funcionarios do sexo feminino: %d\n",pecas_F);
    printf("\nFuncionario com maior qt de pecas: \n\n");
    exibirRegistro(r[aux]);


return 0;
}
