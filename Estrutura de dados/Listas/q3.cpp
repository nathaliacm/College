/*
Considerando o registro da questão anterior, elabore um programa para armazenar o
nome e nota de 35 alunos da disciplina Estruturas de Dados. O programa deverá
mostrar os registros dos 35 alunos e notas.
*/

/*
Elabore um registro que contenha os seguintes campos: nome e nota. O campo nota
deverá ser um vetor com 03 notas para registrar as notas AP1, AP2 e FINAL.
*/

#include<stdio.h>
#include<stdlib.h>

struct registro{
    char nome[30];
    float nota[3];

}reg;

void registrar(struct registro *ptr){
    printf("Qual o nome: "); gets(ptr->nome);
    printf("AP1: "); scanf("%f",&ptr->nota[0]);
    printf("AP2: "); scanf("%f",&ptr->nota[1]);
    printf("Final: "); scanf("%f",&ptr->nota[2]);
}

void exibirRegistro(struct registro r){
    printf("Nome: %s\n",r.nome);
    printf("AP1: %.2f\n",r.nota[0]);
    printf("AP2: %.2f\n",r.nota[1]);
    printf("Final: %.2f\n",r.nota[2]);
}

int main(){
    int n_registros = 35;
    int i;

    struct registro r[n_registros];

    for(i = 0;i<n_registros;i++){
        registrar(&r[i]);
        puts("\n");
        exibirRegistro(r[i]);
        puts("\n");
        setbuf(stdin,NULL);
    }

return 0;
}
