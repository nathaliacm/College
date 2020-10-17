/*
Considerando a necessidade de desenvolver uma agenda que contenha os campos:
nome, endereço, telefone e um campo situação (L – Livre; X – Ocupado e * -
Apagado); defina a estrutura de registro apropriado em C.
*/

#include<stdio.h>
#include<stdlib.h>

struct contato{
    char nome[30];
    char endereco[50];
    long int telefone;
    char situacao; //L – Livre; X – Ocupado e * - Apagado)

};

void criarContato(struct contato *ptr){
    printf("Qual o nome: "); gets(ptr->nome);
    printf("endereco: "); gets(ptr->endereco);
    printf("telefone: "); scanf("%ld",&ptr->telefone); setbuf(stdin,NULL);
    printf("situacao: "); scanf("%c",&ptr->situacao);
}

void exibirContato(struct contato c){
    printf("Nome: %s\n",c.nome);
    printf("Endereco: %s\n",c.endereco);
    printf("Telefone: %ld\n",c.telefone);
    printf("Situacao: %c\n",c.situacao);
}

int main(){
    struct contato c;
    criarContato(&c);
    puts("\n");
    exibirContato(c);
}
