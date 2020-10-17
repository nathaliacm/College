#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

typedef struct box Box;

struct box{
    char conteudo;
    struct box *proximo;
}*inicio, *novo, *temp1, *temp2;

void alocar(){
    novo = (Box*)malloc(sizeof(Box)); //aloca espaço pro box
}

void inserirNoInicio(char caractere){
    alocar(); //aloca  o espaço pro box
    novo->conteudo=caractere; //define o conteudo do novo box

    if(inicio == NULL){ //se a lista estiver vazia.
        inicio = novo;
        novo->proximo=NULL;

    } else{
        novo->proximo=inicio;
        inicio = novo;
    }
    //novo box agora aponta praquilo que era o inicio e o inicio aponta pro novo box.
}

void inserirNoFinal(char caractere){
    alocar(); //aloca  o espaço pro box
    novo->conteudo = caractere; // /define o conteudo do novo box

    if(inicio == NULL){
        novo->proximo=NULL;
        inicio = novo;

    } else{
        Box* aux = inicio;
        while(aux->proximo!=NULL){
            aux = aux->proximo; // move o ponteiro que apontava pro inicio ate o final.
        }
        novo->proximo=NULL;
        aux->proximo=novo;
        //o proximo do novo box aponta pra NULL e o ultimo box agora aponta pro novo box.
    }

}

void inserirEntreElementos(char caractere, char caractere1, char caractere2){
    alocar(); //aloca  o espaço pro box
    novo->conteudo = caractere; //define o conteudo do novo box

    Box* aux = inicio;
    while(aux->proximo!=NULL){
        if(aux->conteudo==caractere1){ //encontrou o box do caractere
            temp1 = aux->proximo; // guarda o proximo box em uma var temporaria
            aux->proximo = novo; // o box agora vai apontar pro box criado
            novo->proximo = temp1; // o novo box vai apontar pro antigo box
            break;
        }
        aux = aux->proximo;
    }

}

void imprimirLista(){
    Box *aux = inicio;

    while(aux!=NULL){
        printf("%c ",aux->conteudo);
        aux = aux->proximo;
    }
}

void removeDoInicio(){
  Box *aux = inicio;
  if (inicio==NULL){
    printf("Lista Vazia!");
  }else{
    aux = inicio;
    inicio = inicio->proximo;
    free(aux);//libera o box
  }
}

void removeDoFim(){
  Box *aux = inicio;
  if (inicio->proximo==NULL){//se só tem um item na lista
    aux = inicio;
    inicio = inicio->proximo;
    free(aux);//libera o box
  }
  else{
    while(true){
        if(aux->proximo->proximo==NULL){//se o proximo do proximo box aponta pra NULL
            break;
        }
        aux = aux->proximo;
    }
    temp2 = aux->proximo; //aponta pro ultimo box
    aux->proximo = NULL; //penultimo box agora aponta pra NULL
    free(temp2); //tchau ultimo box
  }
}

void removeElemento(char caractere){

    if (inicio==NULL){
        printf("Lista Vazia!");
    }else{
        temp1 = inicio;
        temp2 = inicio;
        while(temp1!=NULL){
            if(temp1->conteudo == caractere){ //achou o caractere
                if(temp1==inicio){ //se estiver no inicio o inicio agora aponta pro proximo box
                    inicio = inicio->proximo;
                    free(temp1);
                    break;
                }
                else{ // o proximo do box anterior agora aponta pro proximo do box atual
                    temp2->proximo = temp1->proximo;
                    free(temp1);
                    break;
                }
            }
            else{
                temp2 = temp1;
                temp1 = temp1->proximo;
                //temp1 é o atual e temp2 é o anterior a ele.
            }
        }

    }
}


int main(){

    inicio = NULL;

    printf("Inserir A no final.\n"); system("pause"); inserirNoFinal('A'); imprimirLista();
    printf("\n\nInserir B no inicio.\n"); system("pause");inserirNoInicio('B');imprimirLista();
    printf("\n\nInserir C no final.\n"); system("pause");inserirNoFinal('C');imprimirLista();
    printf("\n\nInserir D no final.\n"); system("pause");inserirNoFinal('D');imprimirLista();
    printf("\n\nInserir E entre A e C.\n"); system("pause");inserirEntreElementos('E','A','C');imprimirLista();
    printf("\n\nInserir F no final.\n"); system("pause");inserirNoFinal('F');imprimirLista();
    printf("\n\nInserir G no inicio.\n"); system("pause");inserirNoInicio('G');imprimirLista();
    printf("\n\nRemover ultimo elemento.\n"); system("pause");removeDoFim();imprimirLista();
    printf("\n\nRemover primeiro elemento.\n"); system("pause");removeDoInicio();imprimirLista();
    printf("\n\nInserir H entre A e E.\n"); system("pause");inserirEntreElementos('H','A','E');imprimirLista();
    printf("\n\nRemover A.\n"); system("pause");removeElemento('A');imprimirLista();
    printf("\n\nInserir I entre E e C.\n"); system("pause");inserirEntreElementos('I','E','C');imprimirLista();//a questão diz E e D mas....
    printf("\n\nInserir J no final.\n"); system("pause");inserirNoFinal('J');imprimirLista();
    printf("\n\nInserir K entre B e H.\n"); system("pause");inserirEntreElementos('K','B','H');imprimirLista();
    printf("\n\nRemover D,K e I.\n"); system("pause");removeElemento('D');removeElemento('K');removeElemento('I');imprimirLista();
    printf("\n\nRemover B.\n"); system("pause");removeElemento('B');imprimirLista();
    printf("\n\nInserir L no final.\n"); system("pause");inserirNoFinal('L');imprimirLista();


    return 0;
}
