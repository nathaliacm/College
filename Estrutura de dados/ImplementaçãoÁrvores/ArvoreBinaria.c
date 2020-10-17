#include <stdio.h>
#include <stdlib.h>
#include "ArvoreBinaria.h"

struct NO {
    char info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin() {
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin)); //cria e aloca espaço para o ponteiro
    if(raiz != NULL) //se deu certo a alocaçâo
        *raiz = NULL; //coloca nulo no conteudo do ponteiro
    return raiz; //retorna o ponteiro
}
//pos-ordem
void libera_NO(struct NO* no) {
    if(no == NULL) //nó já livre
        return;
    //só libera o nó quando liberar todos os nós que estâo à direita e à esquerda
    libera_NO(no->esq);//percorre recursivamente o nó da esquerda
    libera_NO(no->dir);//percorre recursivamente o nó da direita
    free(no);
    no = NULL;
}
//pos-ordem
void libera_ArvBin(ArvBin* raiz) {
    if(raiz == NULL) //raiz ja livre
        return;
    libera_NO(*raiz); //libera cada um dos nós
    free(raiz);// libera a raiz
}

int estaVazia_ArvBin(ArvBin* raiz) {
    if(raiz == NULL) //raiz igual a null
        return 1;
    if(*raiz == NULL) //conteudo da raiz igual null
        return 1;
    return 0;
}
//pos-ordem
int altura_ArvBin(ArvBin *raiz) {
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    //subindo a arvore
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if(alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}
//pos-ordem
int totalNO_ArvBin(ArvBin *raiz) {
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

//percorrendo a arvore

//pré-ordem : visita a raiz, o filho da esquerda e o filho da direita
//em-ordem : visita o filho da esquerda, a raiz e o filho da direita
//pos-ordem : visita o filho da esquerda, o filho da direita e a raiz

//pre-ordem
void preOrdem_ArvBin(ArvBin *raiz) {
    if(raiz == NULL)
        return;
    if(*raiz != NULL) {
        printf("%c ",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

//em-ordem
void emOrdem_ArvBin(ArvBin *raiz) {
    if(raiz == NULL)
        return;
    if(*raiz != NULL) {
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%c ",(*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}
//pos-ordem
void posOrdem_Arv(ArvBin *raiz) {
    if(raiz == NULL)
        return;
    if(*raiz != NULL) {
        posOrdem_Arv(&((*raiz)->esq));
        posOrdem_Arv(&((*raiz)->dir));
        printf("%c ",(*raiz)->info);
    }
}

int insere_ArvBin(ArvBin *raiz, char valor) {
    if(raiz == NULL)//verifico se a raiz esta alocada
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));//aloca espaço pro novo no
    if(novo == NULL)
        return 0;
    //novo nó folha
    novo->info = valor;//seto o valor
    novo->dir = NULL;
    novo->esq = NULL;
    //procura onde vai inserir
    if(*raiz == NULL)
        *raiz = novo; //se for uma arvore vazia raiz aponta pro novo nó
    else {
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        //navega nos nos da arvore ate chegar a um no folha
        while(atual != NULL) {
            ant = atual;
            if(valor == atual->info) {
                free(novo); //libera o espaço alocado
                return 0; //elemento ja existe
            }
            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    //trata no folha e no com 1 filho
    if(atual->esq == NULL) { // sem filho a esquerda
        no2 = atual->dir; //aponta pro filho da direita
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL) {// procura filho mais a esquerda na subarvore da esquerda
        no1 = no2;
        no2 = no2->dir;
    }
    //copia o filho mais a direita na subarvore da esquerda para o lugar do no removido
    if(no1 != atual) {
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int remove_ArvBin(ArvBin *raiz, char valor) {
    if(raiz == NULL) // verifica se a arvore é valida
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL) { // verificar se eu realmente tenho um no atual
        // se eu achei o no
        if(valor == atual->info) { // busca pelo valor que eu quero
            if(atual == *raiz) // se for estou removendo a raiz
                *raiz = remove_atual(atual);
            else { // se nao eu verifico se é o da direita ou o da esquerda
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        // se nao continua procurando
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;// atual recebe filho da direita
        else
            atual = atual->esq;// atual recebe filho da esquerda
    }
}

int consulta_ArvBin(ArvBin *raiz, char valor) {
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL) {
        if(valor == atual->info) {
            return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}


